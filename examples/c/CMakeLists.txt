###############################################################################
#
# Description       : CMake build script for libSEDML C examples
# Original author(s): Frank Bergmann <fbergman@caltech.edu>
# Organization      : California Institute of Technology
#
# This file is part of libSEDML.  Please visit http://sed-ml.org for more
# information about SED-ML, and the latest version of libSEDML.
#
# Copyright (c) 2013, Frank T. Bergmann  
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
###############################################################################


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/../../)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/../../src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)

foreach(example 

	create_sedml
	echo_sedml
	print_sedml
	
)
	add_executable(example_c_${example} ${example}.c)
	set_target_properties(example_c_${example} PROPERTIES  OUTPUT_NAME ${example})
	if (WIN32 AND NOT CYGWIN)
	set_target_properties(example_c_${example} PROPERTIES COMPILE_DEFINITIONS "LIBSEDML_STATIC=1")
	endif()
	target_link_libraries(example_c_${example} ${LIBSEDML_LIBRARY}-static)
	
	if (WITH_LIBXML)
		target_link_libraries(example_c_${example} ${LIBXML_LIBRARY} ${EXTRA_LIBS})
	endif()

	if (WITH_ZLIB)
		target_link_libraries(example_c_${example} ${LIBZ_LIBRARY})
	endif(WITH_ZLIB)
	if (WITH_BZIP2)
		target_link_libraries(example_c_${example} ${LIBBZ_LIBRARY})
	endif(WITH_BZIP2)

endforeach()
