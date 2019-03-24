###############################################################################
#
# Description       : CMake build script for libSEDML C# examples
# Original author(s): Frank Bergmann <fbergman@caltech.edu>
# Organization      : California Institute of Technology
#
# This file is part of libSEDML.  Please visit http://sed-ml.org for more
# information about SEDML, and the latest version of libSEDML.
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

foreach( example
	
	create_sedml
	echo_sedml
	print_sedml
	
)

file(TO_NATIVE_PATH ${CMAKE_CURRENT_BINARY_DIR}/../../src/bindings/csharp MANAGED_LIB)
get_filename_component(MANAGED_LIB ${MANAGED_LIB} ABSOLUTE)
file(TO_NATIVE_PATH ${MANAGED_LIB} MANAGED_LIB)
file(TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}${PATH_SEP}${example}.cs SOURCE_FILE)


	add_custom_command(	
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${example}.exe
		COMMAND "${CSHARP_COMPILER}"
		ARGS -r:libsedmlcsP.dll
      -lib:${MANAGED_LIB}
			-target:exe
			-out:${example}.exe
			${CSHARP_EXTRA_ARGS}
			${SOURCE_FILE}
		MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/${example}.cs
		COMMENT "Build C# example: ${example}") 
	
	add_custom_target(exmple_cs_${example} ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${example}.exe)
	add_dependencies(exmple_cs_${example} binding_csharp_managed_lib)
	
endforeach()
