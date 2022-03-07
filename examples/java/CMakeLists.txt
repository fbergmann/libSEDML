###############################################################################
#
# Description       : CMake build script for libSEDML Java examples
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

find_package(Java COMPONENTS Development REQUIRED)


if (JAVA_COMPATIBILITY)
SET(COMPAT_ARGS "-source ${JAVA_COMPATIBILITY} -target ${JAVA_COMPATIBILITY}")
endif()

foreach( example
  
  create_sedml
  echo_sedml
  print_sedml
  
)

  file(TO_NATIVE_PATH ${CMAKE_CURRENT_BINARY_DIR} CURRENT_BIN)
  file(TO_NATIVE_PATH ${CMAKE_CURRENT_BINARY_DIR}/../../src/bindings/java/libsedmlj.jar CURRENT_JAR )
  file(TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${example}.java CURRENT_FILE)

  add_custom_command(  
    OUTPUT ${example}.class
    COMMAND "${Java_JAVAC_EXECUTABLE}"
    ARGS -cp ".${FILE_SEP}\"${CURRENT_JAR}\"${FILE_SEP}${CMAKE_CURRENT_SOURCE_DIR}"
       ${CURRENT_FILE}
       ${COMPAT_ARGS}
       -d ${CMAKE_CURRENT_BINARY_DIR}
    MAIN_DEPENDENCY "${CMAKE_CURRENT_SOURCE_DIR}/../../src/bindings/java/local.i"
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${example}.java
    COMMENT "Build java example ${example}"
  ) 
  
  add_custom_target(example_java_${example} ALL 
    DEPENDS 
    ${CMAKE_CURRENT_BINARY_DIR}/${example}.class 
    SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/${example}.java 
  )
  
  add_dependencies(example_java_${example} binding_java_jar)

  
endforeach()
