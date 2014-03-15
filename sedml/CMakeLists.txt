###############################################################################
#
# Description       : CMake build script for libSEDML
# Original author(s): Frank Bergmann <fbergman@caltech.edu>
# Organization      : California Institute of Technology
#
# <!--------------------------------------------------------------------------
# 
# This file is part of libSEDML.  Please visit http://sed-ml.org for more
# information about SED-ML. The latest version of libSEDML can be found on 
# github: https://github.com/fbergmann/libSEDML/
# 
# 
# Copyright (c) 2013-2014, Frank T. Bergmann  
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met: 
# 
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer. 
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution. 
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
# ---------------------------------------------------------------------- -->
# 
###############################################################################


include(CheckLibraryExists)
check_library_exists(m sqrt "" HAVE_LIBM)

# generate configuration for this system
configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/common/libsedml-config-common.h.cmake
	"${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-config-common.h"
	)

# Replace: @PACKAGE_VERSION@ and @LIBSEDML_VERSION_NUMERIC@
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/common/libsedml-version.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-version.h"
  )

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/common/libsedml-package.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-package.h"
  )

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/common/libsedml-namespace.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-namespace.h"
  )
  

###############################################################################
#
# mark header files for installation
#
foreach(dir annotation common compress conversion extension math units util validator xml  )

	file(GLOB header_files "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.h")
	install(FILES ${header_files} DESTINATION include/sedml/${dir})

endforeach(dir)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${files} DESTINATION include/sedml)

# install generated headers
install(FILES 
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-version.h"
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-config-common.h"
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-namespace.h"
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-package.h"
        DESTINATION include/sedml/common)

###############################################################################
#
# specify include directories
#
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(BEFORE ${LIBSBML_INCLUDE_DIR})
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/..)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/..)

if (EXTRA_DEFS)
add_definitions(${EXTRA_DEFS})
endif()

###############################################################################
#
# Find all sources
#

foreach (directory common sedml )

	set(dir ${directory})

	if ("${directory}" STREQUAL "sedml")
		set(dir ".")
	endif()


	file(GLOB temp
			${dir}/*.cpp
			${dir}/*.c
			${dir}/*.h)

	# create source group for IDEs
	source_group(${directory} FILES ${temp})

	# add to libsbml sources
	set(LIBSEDML_SOURCES ${LIBSEDML_SOURCES} ${temp})

endforeach()

###############################################################################
#
# this is a directory level operation!
#
if (MSVC)
if (WITH_STATIC_RUNTIME)
	foreach(flag_var
		CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
		CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
		CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
		CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)

		if(${flag_var} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		endif(${flag_var} MATCHES "/MD")


	endforeach(flag_var)
	add_definitions( -D_MT)
endif(WITH_STATIC_RUNTIME)
endif(MSVC)

###############################################################################
#
# Build library
#

if (NOT LIBSEDML_SKIP_SHARED_LIBRARY)

add_library (${LIBSEDML_LIBRARY} SHARED ${LIBSEDML_SOURCES} )

if (LIBSEDML_SHARED_VERSION)
  set_target_properties(${LIBSEDML_LIBRARY} PROPERTIES COMPILE_DEFINITIONS "LIBSEDML_EXPORTS=1")
  set_target_properties(${LIBSEDML_LIBRARY} PROPERTIES
                      SOVERSION ${LIBSEDML_VERSION_MAJOR}
                      VERSION ${LIBSEDML_VERSION_MAJOR}.${LIBSEDML_VERSION_MINOR}.${LIBSEDML_VERSION_PATCH})
endif()

target_link_libraries(${LIBSEDML_LIBRARY} ${LIBSBML_LIBRARY} ${EXTRA_LIBS})

INSTALL(TARGETS ${LIBSEDML_LIBRARY}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

endif()

add_library (${LIBSEDML_LIBRARY}-static STATIC ${LIBSEDML_SOURCES} )
if (WIN32 AND NOT CYGWIN)
	# don't decorate static library 
	set_target_properties(${LIBSEDML_LIBRARY}-static PROPERTIES COMPILE_DEFINITIONS "LIBSEDML_STATIC=1")
endif(WIN32 AND NOT CYGWIN)

target_link_libraries(${LIBSEDML_LIBRARY}-static ${LIBSBML_LIBRARY} ${EXTRA_LIBS})

INSTALL(TARGETS ${LIBSEDML_LIBRARY}-static
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )
