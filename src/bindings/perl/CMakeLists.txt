###############################################################################
#
# Description       : CMake build script for libSEDML Perl bindings
# Original author(s): Frank Bergmann <fbergman@caltech.edu>
# Organization      : California Institute of Technology
#
# This file is part of libSEDML.  Please visit http://sbml.org for more
# information about SEDML, and the latest version of libSEDML.
#
# Copyright (C) 2009-2013 jointly by the following organizations: 
#     1. California Institute of Technology, Pasadena, CA, USA
#     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
#  
# Copyright (C) 2006-2008 by the California Institute of Technology,
#     Pasadena, CA, USA 
#  
# Copyright (C) 2002-2005 jointly by the following organizations: 
#     1. California Institute of Technology, Pasadena, CA, USA
#     2. Japan Science and Technology Agency, Japan
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
#
###############################################################################

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
#include(FindPerlLibs)
find_package(Perl REQUIRED)
find_package(PerlLibs REQUIRED)

####################################################################
#
# determine local dependencies, so as to re-swig if one of them changed
# 

file(GLOB SWIG_DEPENDENCIES 
	${CMAKE_CURRENT_SOURCE_DIR}/*.i 
	${CMAKE_CURRENT_SOURCE_DIR}/*.h 
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.i
	${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.h
	)



# need documentation file
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/LibSEDML.txt" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


#
# Remove SWIG wrappers if requested
#
if (LIBSEDML_REMOVE_WRAPPERS)
  foreach(file 
    ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML_wrap.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.pod
  )
    if (EXISTS ${file})
      FILE(REMOVE ${file})
    endif()
  endforeach()
endif(LIBSEDML_REMOVE_WRAPPERS)

set(SWIG_EXTRA_FLAGS -DSWIGEXPORT 
  -DLIBSBML_CPP_NAMESPACE_BEGIN -DLIBSBML_CPP_NAMESPACE_END -DLIBSBML_CPP_NAMESPACE_QUALIFIER -DLIBSBML_CPP_NAMESPACE_USE
  -DLIBNUML_CPP_NAMESPACE_BEGIN -DLIBNUML_CPP_NAMESPACE_END -DLIBNUML_CPP_NAMESPACE_QUALIFIER -DLIBNUML_CPP_NAMESPACE_USE
  )
if(NOT UNIX)
	set(SWIG_EXTRA_FLAGS ${SWIG_EXTRA_FLAGS} -DSWIGWIN -DSWIG_CSHARP_NO_WSTRING_HELPER )
endif()



add_custom_command(	
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML_wrap.cpp ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.pod
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS	-I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
			-I${CMAKE_CURRENT_SOURCE_DIR}/../..
			-I${CMAKE_CURRENT_BINARY_DIR}/../../
			-I${CMAKE_CURRENT_SOURCE_DIR}/../../sedml
			-I${CMAKE_CURRENT_SOURCE_DIR}
			-I${LIBNUML_INCLUDE_DIR}/
			-I${LIBSBML_INCLUDE_DIR}/
			-c++
			-perl5
			-proxy
			${SWIG_EXTRA_FLAGS}		 
			${SWIG_EXTRA_ARGS}		 
			-o ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML_wrap.cpp 
			${CMAKE_CURRENT_SOURCE_DIR}/libsedml.i
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/libsedml.i
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
	        ${SWIG_DEPENDENCIES}
    COMMENT "Swig Perl bindings source") 

add_custom_target(binding_perl_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML_wrap.cpp ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.pod)


# 
# Determine the perl installation directory
#
set(PERL_PACKAGE_INSTALL_DIR)
set(PERL_PACKAGE_INSTALL_BIN_DIR)
if (UNIX OR CYGWIN) 
  execute_process(COMMAND "${PERL_EXECUTABLE}" -V:version
    OUTPUT_VARIABLE PERL_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
  string(REPLACE "'" "" PERL_VERSION ${PERL_VERSION})
  string(REPLACE ";" "" PERL_VERSION ${PERL_VERSION})
  string(REPLACE "version=" "" PERL_VERSION ${PERL_VERSION})
  string(REPLACE " " "" PERL_VERSION ${PERL_VERSION})
  execute_process(COMMAND "${PERL_EXECUTABLE}" -V:archname
    OUTPUT_VARIABLE PERL_PLATFORM OUTPUT_STRIP_TRAILING_WHITESPACE)
  string(REPLACE " " "" PERL_PLATFORM ${PERL_PLATFORM})
  string(REPLACE "'" "" PERL_PLATFORM ${PERL_PLATFORM})
  string(REPLACE ";" "" PERL_PLATFORM ${PERL_PLATFORM})
  string(REPLACE "archname=" "" PERL_PLATFORM ${PERL_PLATFORM})
  set(PERL_PACKAGE_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/perl5/site_perl/${PERL_VERSION}/${PERL_PLATFORM})
  set(PERL_PACKAGE_INSTALL_BIN_DIR ${PERL_PACKAGE_INSTALL_DIR}/auto/libSEDML)
else()
  set(PERL_PACKAGE_INSTALL_DIR ${MISC_PREFIX}bindings/perl)
  set(PERL_PACKAGE_INSTALL_BIN_DIR ${PERL_PACKAGE_INSTALL_DIR})
endif()
	
# install(FILES "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.pod" DESTINATION ${PERL_PACKAGE_INSTALL_DIR})
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.pm" DESTINATION ${PERL_PACKAGE_INSTALL_DIR})
 
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "#ifdef WIN32\n")
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "// do not include MFC\n")
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "#define WIN32_LEAN_AND_MEAN \n")
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "// do not include GDI by default\n")
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "#define NOGDI\n")
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "#endif\n\n")
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "#include <EXTERN.h>\n")
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "#include \"LibSEDML_wrap.cpp\"\n")
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp" "\n\n")

####################################################################
#
# Build native library
#

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../swig)
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/../../)
include_directories(BEFORE ${PERL_INCLUDE_PATH})
add_definitions(-DLIBSEDML_STATIC)
if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

if (NOT UNIX)
	add_definitions(-DWIN32SCK_IS_STDSCK -DWIN32IO_IS_STDIO)
	
	
	if (MSVC)
	# these definitions are needed for activestate perl 5.14.2
	if (LIBSEDML_BUILD_TYPE STREQUAL "32bit")
	  add_definitions( -D_USE_32BIT_TIME_T -DPERL_TEXTMODE_SCRIPTS -DNO_STRICT ) 
	elseif(LIBSEDML_BUILD_TYPE STREQUAL "64bit")
		add_definitions( -DUSE_64_BIT_INT -DUSE_ITHREADS -DMULTIPLICITY ) 
	endif()
	add_definitions(
		-DUSE_LARGE_FILES		
		-DUSE_SITECUSTOMIZE
		-DPERL_IMPLICIT_CONTEXT 
		)
	endif()
endif ()

if(APPLE)
	#add_definitions(-DPERL_DARWIN)
endif()

if (MSVC)
  # the build fails when compiled with packages as the object file is too 
  # big adding the big flag makes it work!
  add_definitions(/bigobj)
endif(MSVC)


add_library(binding_perl_lib MODULE ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp)
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/LibSEDML.cpp 
      PROPERTIES OBJECT_DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/LibSEDML_wrap.cpp)
add_dependencies(binding_perl_lib binding_perl_swig)
target_link_libraries(binding_perl_lib ${LIBSEDML_LIBRARY}-static ${PERL_LIBRARY})

set_target_properties(binding_perl_lib PROPERTIES  OUTPUT_NAME LibSEDML)
set_target_properties(binding_perl_lib PROPERTIES  PREFIX "")

if(APPLE)
	set_target_properties(binding_perl_lib PROPERTIES  SUFFIX ".bundle")
endif()

install(TARGETS binding_perl_lib  DESTINATION ${PERL_PACKAGE_INSTALL_BIN_DIR} )
