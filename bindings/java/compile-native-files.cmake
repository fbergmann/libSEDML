###############################################################################
#
# Description       : CMake build script for native java files
# Original author(s): Frank Bergmann <fbergman@caltech.edu>
# Organization      : California Institute of Technology
#
# <!--------------------------------------------------------------------------
# This file is part of libSEDML.  Please visit http://sed-ml.org for more
# information about SED-ML. The latest version of libSEDML can be found on
# github: https://github.com/fbergmann/libSEDML/
#
# Copyright (c) 2013-2016, Frank T. Bergmann
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
# ------------------------------------------------------------------------ -->
#
###############################################################################

message("Creating: libsedml.jar")

# find all sources
file(GLOB_RECURSE SOURCE_FILES RELATIVE ${BIN_DIRECTORY} ${BIN_DIRECTORY}/java-files/org/sedml/libsedml/*.java)

# convert paths
set(NATIVE_FILES)
foreach(javaFile ${SOURCE_FILES})
	file(TO_NATIVE_PATH ${javaFile} temp)
	set(NATIVE_FILES ${NATIVE_FILES} ${temp})
endforeach()

# delete file if it exists
if (EXISTS ${BIN_DIRECTORY}/libsedml.jar)
	file(REMOVE ${BIN_DIRECTORY}/libsedml.jar)	
endif()

# compile files
execute_process(
	COMMAND "${Java_JAVAC_EXECUTABLE}"
		 -source 1.5
		 -target 1.5
		 -d java-files
		 ${NATIVE_FILES}	
	WORKING_DIRECTORY "${BIN_DIRECTORY}"
)

# enumerate class files
file(GLOB_RECURSE CLASS_FILES RELATIVE ${BIN_DIRECTORY}/java-files ${BIN_DIRECTORY}/java-files/org/sedml/libsedml/*.class)
set(NATIVE_CLASS_FILES)
foreach(classFile ${CLASS_FILES})
	file(TO_NATIVE_PATH ${classFile} temp)
	set(NATIVE_CLASS_FILES ${NATIVE_CLASS_FILES} ${temp})
endforeach()

# create jar
execute_process(
	COMMAND "${Java_JAR_EXECUTABLE}"
		 -cvfm ..${PATH_SEP}libsedmlj.jar
		 ../Manifest.txt
		 ${NATIVE_CLASS_FILES}	
	WORKING_DIRECTORY "${BIN_DIRECTORY}/java-files"
)

# # print variables for debug purposes 
# message("BIN_DIRECTORY         : ${BIN_DIRECTORY}")
# message("Java_JAVAC_EXECUTABLE : ${Java_JAVAC_EXECUTABLE}")
# message("Java_JAR_EXECUTABLE   : ${Java_JAR_EXECUTABLE}")

