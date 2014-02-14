###############################################################################
#
# Description       : CMake build script for libSEDML Ruby bindings
# Original author(s): Frank Bergmann <fbergman@caltech.edu>
# Organization      : California Institute of Technology
#
# This file is part of libSEDML.  Please visit http://sedml.org for more
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
# and also available online as http://sedml.org/software/libsedml/license.html
#
###############################################################################

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
include(FindRuby)


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

#
# Remove SWIG wrappers if requested
#
if (LIBSEDML_REMOVE_WRAPPERS)
  foreach(file 
    ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp
  )
    if (EXISTS ${file})
      FILE(REMOVE ${file})
    endif()
  endforeach()
endif(LIBSEDML_REMOVE_WRAPPERS)


set(SWIG_EXTRA_FLAGS -DSWIGEXPORT -DLIBSBML_CPP_NAMESPACE_BEGIN -DLIBSBML_CPP_NAMESPACE_END)
if(NOT UNIX)
	set(SWIG_EXTRA_FLAGS ${SWIG_EXTRA_FLAGS} -DSWIGWIN -DSWIG_CSHARP_NO_WSTRING_HELPER )
endif()

add_custom_command(	
    OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS    -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
			-I${CMAKE_CURRENT_SOURCE_DIR}/../../
			-I${CMAKE_BINARY_DIR}/
			-I${CMAKE_CURRENT_SOURCE_DIR}/../../sedml
			-I${CMAKE_CURRENT_SOURCE_DIR}
			-I${LIBSBML_INCLUDE_DIR}/
			-c++
			-ruby		
			${SWIG_EXTRA_FLAGS}		 
			${SWIG_EXTRA_ARGS}		 
			-o ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp 
			${CMAKE_CURRENT_SOURCE_DIR}/libsedml.i
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/libsedml.i
	DEPENDS ${SWIG_DEPENDENCIES}
    COMMENT "Swig Ruby source") 

add_custom_target(binding_ruby_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp)

	
####################################################################
#
# Build native library
#

if(WIN32)
	add_definitions(-DNT=1 -DIMPORT)
endif()
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../swig)
include_directories(${LIBSBML_INCLUDE_DIR})
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
include_directories(BEFORE ${CMAKE_BINARY_DIR})
add_definitions(-DLIBSEDML_STATIC)
include_directories(${RUBY_INCLUDE_DIRS})
include_directories(${RUBY_HDR_DIR})
if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)


add_library(binding_ruby_lib SHARED ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp)
add_dependencies(binding_ruby_lib binding_ruby_swig)

# 
# Determine the ruby installation directory
#
set(RUBY_PACKAGE_INSTALL_DIR)
if (UNIX OR CYGWIN) 
  execute_process(COMMAND "${RUBY_EXECUTABLE}" -e "print RUBY_PLATFORM"
    OUTPUT_VARIABLE RUBY_PLATFORM)
  set(RUBY_PACKAGE_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/ruby/site_ruby/${RUBY_VERSION_MAJOR}.${RUBY_VERSION_MINOR}/${RUBY_PLATFORM})
else()
  set(RUBY_PACKAGE_INSTALL_DIR ${MISC_PREFIX}bindings/ruby)
endif()

set_target_properties (binding_ruby_lib PROPERTIES OUTPUT_NAME "libSEDML")
if (UNIX)
	set_target_properties (binding_ruby_lib PROPERTIES PREFIX "")
	if (APPLE)
		set_target_properties (binding_ruby_lib PROPERTIES SUFFIX ".bundle")
	endif()
endif()

target_link_libraries(binding_ruby_lib ${LIBSEDML_LIBRARY}-static ${RUBY_LIBRARY})
install(TARGETS binding_ruby_lib DESTINATION ${RUBY_PACKAGE_INSTALL_DIR} )

