###############################################################################
#
# Description       : CMake build script for libSEDML examples
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

# only compile examples if specified, but always copy samples
if(WITH_EXAMPLES)

add_subdirectory(c)
add_subdirectory(c++)

if(WITH_CSHARP)
  add_subdirectory(csharp)
endif(WITH_CSHARP)


if(WITH_JAVA)
  add_subdirectory(java)
endif(WITH_JAVA)


endif(WITH_EXAMPLES)



# the remaining language bindings do not need to be compiled in order to run. 

# Now we just have to select files for installation# 
install(FILES README.md DESTINATION ${MISC_PREFIX}examples)

## install c examples
file(GLOB c_samples "${CMAKE_CURRENT_SOURCE_DIR}/c/*.c"
					 "${CMAKE_CURRENT_SOURCE_DIR}/c/README.md"
					 "${CMAKE_CURRENT_SOURCE_DIR}/c/*.h")
install(FILES ${c_samples} DESTINATION ${MISC_PREFIX}examples/c)
#
# install c++ examples
file(GLOB cpp_samples "${CMAKE_CURRENT_SOURCE_DIR}/c++/*.c"
					 "${CMAKE_CURRENT_SOURCE_DIR}/c++/README.md"
					 "${CMAKE_CURRENT_SOURCE_DIR}/c++/*.cpp"
					 "${CMAKE_CURRENT_SOURCE_DIR}/c++/*.h")
install(FILES ${cpp_samples} DESTINATION ${MISC_PREFIX}examples/c++)

if(WITH_CSHARP)
# install c# examples
file(GLOB cs_samples "${CMAKE_CURRENT_SOURCE_DIR}/csharp/*.cs"
					 "${CMAKE_CURRENT_SOURCE_DIR}/csharp/README.md")
install(FILES ${cs_samples} DESTINATION ${MISC_PREFIX}examples/csharp)
endif()

if(WITH_JAVA)
# install java examples
file(GLOB java_samples "${CMAKE_CURRENT_SOURCE_DIR}/java/*.java"
					 "${CMAKE_CURRENT_SOURCE_DIR}/java/README.md")
install(FILES ${java_samples} DESTINATION ${MISC_PREFIX}examples/java)
endif()
#
#if(WITH_PERL)
## install perl examples
#file(GLOB perl_samples "${CMAKE_CURRENT_SOURCE_DIR}/perl/*.pl"
#					 "${CMAKE_CURRENT_SOURCE_DIR}/perl/README.md")
#install(FILES ${perl_samples} DESTINATION ${MISC_PREFIX}examples/perl)
#endif()

if (WITH_PYTHON)
# install python examples
file(GLOB python_samples "${CMAKE_CURRENT_SOURCE_DIR}/python/*.py"
					 "${CMAKE_CURRENT_SOURCE_DIR}/python/README.md")
install(FILES ${python_samples} DESTINATION ${MISC_PREFIX}examples/python)
endif()


# install sample-models

#file(GLOB _samples "${CMAKE_CURRENT_SOURCE_DIR}/sample-models/*.xml")
#install(FILES ${l3_samples} DESTINATION ${MISC_PREFIX}examples/sample-models)

