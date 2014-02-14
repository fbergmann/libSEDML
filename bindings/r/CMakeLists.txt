###############################################################################
#
# Description       : CMake build script for libSEDML R bindings
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

SET(R_INCLUDE_DIRS)
SET(R_LIB)
SET(R_INTERPRETER)
SET(R_ADDITIONAL_PATH_ENTRIES "" CACHE STRING "Additional paths to the RTOOLS / GCC binary directories to build package")
SET(CMAKE_FIND_FRAMEWORK NEVER)
SET(CMAKE_FIND_APPBUNDLE NEVER)
# first lets search for the include/lib/interpreter if a user did not specify them
if (NOT R_INCLUDE_DIRS)
    find_path(R_INCLUDE_DIRS
        NAMES R.h
        PATHS /usr/include /usr/local/include /usr/share/R/include
              /Library/Frameworks/R.framework/Versions/Current/Resources/include
              $ENV{ProgramFiles}/R/R-2.15.3/include
              $ENV{ProgramW6432}/R/R-2.15.3/include
              $ENV{ProgramFiles}/R/R-2.15.2/include
              $ENV{ProgramW6432}/R/R-2.15.2/include
              $ENV{ProgramFiles}/R/R-2.15.1/include
              $ENV{ProgramW6432}/R/R-2.15.1/include
              ${CMAKE_CURRENT_SOURCE_DIR}/../../include
              ${LIBSEDML_DEPENDENCY_DIR}/include
        DOC "The directory containing the R include files."
        )
endif()

if (NOT R_LIB)
    SET(R_SUFFIX)
	if (WIN32)
		if (LIBSEDML_BUILD_TYPE STREQUAL "32bit")
		SET(R_SUFFIX "/i386")
		else()
		SET(R_SUFFIX "/x64")
		endif()
	endif()
	find_library(R_LIB
			NAMES Rlib.lib R
			PATHS /usr/lib /usr/local/lib /usr/lib/R/lib
            $ENV{ProgramFiles}/R/R-2.15.3/bin${R_SUFFIX}
            $ENV{ProgramW6432}/R/R-2.15.3/bin${R_SUFFIX}
            $ENV{ProgramFiles}/R/R-2.15.2/bin${R_SUFFIX}
            $ENV{ProgramW6432}/R/R-2.15.2/bin${R_SUFFIX}
            $ENV{ProgramFiles}/R/R-2.15.1/bin${R_SUFFIX}
            $ENV{ProgramW6432}/R/R-2.15.1/bin${R_SUFFIX}
            /Library/Frameworks/R.framework/Versions/Current/Resources/lib
            ${CMAKE_CURRENT_SOURCE_DIR}/../../
            ${LIBSEDML_DEPENDENCY_DIR}/lib
			DOC "The file name of the R library."
			)
endif()
if (NOT R_INTERPRETER)
	find_program(R_INTERPRETER
        NAMES R R32 R64
        PATHS 
          $ENV{ProgramFiles}/R/R-2.15.3/bin
          $ENV{ProgramW6432}/R/R-2.15.3/bin
          $ENV{ProgramFiles}/R/R-2.15.2/bin
          $ENV{ProgramW6432}/R/R-2.15.2/bin
          $ENV{ProgramFiles}/R/R-2.15.1/bin
          $ENV{ProgramW6432}/R/R-2.15.1/bin
          /Library/Frameworks/R.framework/Versions/Current/Resources/bin/
          /usr/local/bin
          /usr/bin
        DOC "The file name of the R interpreter."
        )
endif()

# message(
# "
#              R_INCLUDE_DIRS = ${R_INCLUDE_DIRS}
#                       R_LIB = ${R_LIB}
#               R_INTERPRETER = ${R_INTERPRETER}
#   R_ADDITIONAL_PATH_ENTRIES = ${R_ADDITIONAL_PATH_ENTRIES}
# 
# ")

# if we have not found something, stop here to ask for it
if (NOT R_INTERPRETER)
	message(FATAL_ERROR "Need the R interpreter in order to create an R package") 
endif()
if (NOT R_LIB)
	message(FATAL_ERROR "Need the R library, please specify R_LIB")
endif()
if (NOT R_INCLUDE_DIRS)
	message(FATAL_ERROR "Need the R include directory, please specify R_INCLUDE_DIRS")
endif()



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
    ${CMAKE_CURRENT_BINARY_DIR}/libSEDML.R
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

ADD_CUSTOM_COMMAND(	
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp
	       ${CMAKE_CURRENT_BINARY_DIR}/libSEDML.R
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS	-I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
			-I${CMAKE_CURRENT_SOURCE_DIR}/../../
			-I${CMAKE_BINARY_DIR}/
			-I${CMAKE_CURRENT_SOURCE_DIR}/../../sedml
			-I${CMAKE_CURRENT_SOURCE_DIR}
			-I${LIBSBML_INCLUDE_DIR}/
			-c++
			-r
			${SWIG_EXTRA_FLAGS}		 
			${SWIG_EXTRA_ARGS}		 
			-o ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp 
			${CMAKE_CURRENT_SOURCE_DIR}/libsedml.i
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/libsedml.i
	DEPENDS ${SWIG_DEPENDENCIES}
    COMMENT "Swig R source") 

add_custom_target(binding_r_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp)

	
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
include_directories(${R_INCLUDE_DIRS})
if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)


add_library(binding_r_lib SHARED ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp)
add_dependencies(binding_r_lib binding_r_swig)


set_target_properties (binding_r_lib PROPERTIES OUTPUT_NAME "libSEDML")
if (UNIX)
	set_target_properties (binding_r_lib PROPERTIES PREFIX "")
	if (APPLE)
		set_target_properties (binding_r_lib PROPERTIES SUFFIX ".so")
	endif()
endif()
if (R_ADDITIONAL_PATH_ENTRIES)
target_link_libraries(binding_r_lib ${LIBSEDML_LIBRARY}-static ${R_LIB} ${R_ADDITIONAL_PATH_ENTRIES})
else()
target_link_libraries(binding_r_lib ${LIBSEDML_LIBRARY}-static ${R_LIB})
endif()
install(TARGETS binding_r_lib DESTINATION lib )

####################################################################
#
# create the r package
#

MACRO (TODAY RESULT) 
    IF (WIN32) 
        EXECUTE_PROCESS(COMMAND "cmd" " /C date /T" OUTPUT_VARIABLE ${RESULT} OUTPUT_STRIP_TRAILING_WHITESPACE) 
        string(REGEX REPLACE "(..)/(..)/..(..).*" "\\1/\\2/\\3" ${RESULT} ${${RESULT}}) 
    ELSEIF(UNIX) 
        EXECUTE_PROCESS(COMMAND "date" "+%Y-%m-%d" OUTPUT_VARIABLE ${RESULT} OUTPUT_STRIP_TRAILING_WHITESPACE) 
        string(REGEX REPLACE "(..)/(..)/..(..).*" "\\1/\\2/\\3" ${RESULT} ${${RESULT}}) 
    ELSE (WIN32) 
        MESSAGE(SEND_ERROR "date not implemented") 
        SET(${RESULT} 000000) 
    ENDIF (WIN32) 
ENDMACRO (TODAY) 

TODAY(CURRENT_DATE) 

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/libSEDML")

set(R_LIBRARY_DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/libSEDML/inst/libs")

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/libSEDML/R)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/temp)
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/DESCRIPTION.in"
  "${CMAKE_CURRENT_BINARY_DIR}/libSEDML/DESCRIPTION"
  )
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/NAMESPACE"
  "${CMAKE_CURRENT_BINARY_DIR}/libSEDML/NAMESPACE"
)

get_target_property(LIBSEDML_R_NATIVELIB binding_r_lib LOCATION)

if (APPLE AND ENABLE_UNIVERSAL)

file(MAKE_DIRECTORY ${R_LIBRARY_DESTINATION})
file(MAKE_DIRECTORY ${R_LIBRARY_DESTINATION}/i386)
file(MAKE_DIRECTORY ${R_LIBRARY_DESTINATION}/x86_64)

add_custom_command(	
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/libSEDML_${LIBSEDML_VERSION_MAJOR}${LIBSEDML_VERSION_MINOR}${LIBSEDML_VERSION_PATCH}.zip
	COMMAND "${CMAKE_COMMAND}"
			-DFILENAME=\"${CMAKE_CURRENT_BINARY_DIR}/libSEDML.R\"
			-P "${CMAKE_CURRENT_SOURCE_DIR}/patch-swig-file.cmake"
	COMMAND "${CMAKE_COMMAND}"
	ARGS  -E copy_if_different 
		 ${LIBSEDML_R_NATIVELIB}
		 ${R_LIBRARY_DESTINATION}/i386
	COMMAND "${CMAKE_COMMAND}"
	ARGS  -E copy_if_different
		 ${LIBSEDML_R_NATIVELIB}
		 ${R_LIBRARY_DESTINATION}/x86_64
	COMMAND "${CMAKE_COMMAND}"
	ARGS  -E copy_if_different 
		 ${CMAKE_CURRENT_BINARY_DIR}/libSEDML.R
		 ${CMAKE_CURRENT_BINARY_DIR}/libSEDML/R
    COMMAND "${R_INTERPRETER}"
    ARGS  CMD INSTALL --build 
	      --no-libs 
		  --no-test-load 
		  --no-clean-on-error 
		  --no-multiarch 
		  libSEDML
		  -l temp		  
	MAIN_DEPENDENCY ${CMAKE_CURRENT_BINARY_DIR}/libSEDML.R
	DEPENDS ${SWIG_DEPENDENCIES}
    COMMENT "Create R Package") 

else(APPLE AND ENABLE_UNIVERSAL)

if (WIN32)
if (LIBSEDML_BUILD_TYPE STREQUAL "32bit")
set(R_LIBRARY_DESTINATION "${R_LIBRARY_DESTINATION}/i386")
else()
set(R_LIBRARY_DESTINATION "${R_LIBRARY_DESTINATION}/x64")
endif()
endif()

if (APPLE)
if (LIBSEDML_BUILD_TYPE STREQUAL "32bit")
set(R_LIBRARY_DESTINATION "${R_LIBRARY_DESTINATION}/i386")
else()
set(R_LIBRARY_DESTINATION "${R_LIBRARY_DESTINATION}/x86_64")
endif()
endif(APPLE)


file(MAKE_DIRECTORY ${R_LIBRARY_DESTINATION})

add_custom_command(	
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/libSEDML_${LIBSEDML_VERSION_MAJOR}${LIBSEDML_VERSION_MINOR}${LIBSEDML_VERSION_PATCH}.zip
	COMMAND "${CMAKE_COMMAND}"
			-DFILENAME=\"${CMAKE_CURRENT_BINARY_DIR}/libSEDML.R\"
			-P "${CMAKE_CURRENT_SOURCE_DIR}/patch-swig-file.cmake"
	COMMAND "${CMAKE_COMMAND}"
	ARGS  -E copy_if_different 
		 ${LIBSEDML_R_NATIVELIB}
		 ${R_LIBRARY_DESTINATION}
	COMMAND "${CMAKE_COMMAND}"
	ARGS  -E copy_if_different 
		 ${CMAKE_CURRENT_BINARY_DIR}/libSEDML.R
		 ${CMAKE_CURRENT_BINARY_DIR}/libSEDML/R
    COMMAND "${R_INTERPRETER}"
    ARGS  CMD INSTALL --build 
	      --no-libs 
		  --no-test-load 
		  --no-clean-on-error 
		  --no-multiarch 
		  libSEDML
		  -l temp		  
	MAIN_DEPENDENCY ${CMAKE_CURRENT_BINARY_DIR}/libSEDML.R
	DEPENDS ${SWIG_DEPENDENCIES}
    COMMENT "Create R Package (${LIBSEDML_BUILD_TYPE})") 
endif(APPLE AND ENABLE_UNIVERSAL)
add_custom_target(binding_r_package ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/libSEDML_${LIBSEDML_VERSION_MAJOR}${LIBSEDML_VERSION_MINOR}${LIBSEDML_VERSION_PATCH}.zip binding_r_lib)
