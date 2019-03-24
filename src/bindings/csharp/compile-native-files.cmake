#################################################
 # @file compile-native-files.cmake
 # @brief Base file
 # @author DEVISER
 #
 # <!--------------------------------------------------------------------------
 # This file is part of libSEDML. Please visit http://sed-ml.org for more
 # information about SED-ML. The latest version of libSEDML can be found on
 # github: https://github.com/fbergmann/libSEDML/
 # 

 # Copyright (c) 2013-2019, Frank T. Bergmann
 # All rights reserved.
 # 

 # Redistribution and use in source and binary forms, with or without
 # modification, are permitted provided that the following conditions are met:
 # 

 # 1. Redistributions of source code must retain the above copyright notice,
 # this
 # list of conditions and the following disclaimer.
 # 2. Redistributions in binary form must reproduce the above copyright notice,
 # this list of conditions and the following disclaimer in the documentation
 # and/or other materials provided with the distribution.
 #
 # This library is free software; you can redistribute it and/or modify it
 # under the terms of the GNU Lesser General Public License as published by the
 # Free Software Foundation. A copy of the license agreement is provided in the
 # file named "LICENSE.txt" included with this software distribution and also
 # available online as http://sbml.org/software/libsbml/license.html
 # ------------------------------------------------------------------------ -->
 #


message("Creating: libsedmlcsP.dll")

# find all sources
file(GLOB_RECURSE SOURCE_FILES RELATIVE ${BIN_DIRECTORY} ${BIN_DIRECTORY}/csharp-files/*.cs)
set(SOURCE_FILES ${SOURCE_FILES} ${BIN_DIRECTORY}/AssemblyInfo.cs)


SET(PATCH_SWIG_FILES ON)

# convert paths
set(NATIVE_FILES)
foreach(csFile ${SOURCE_FILES})
  
  file(TO_NATIVE_PATH ${csFile} temp)
  set(NATIVE_FILES ${NATIVE_FILES} ${temp})

  
  if (PATCH_SWIG_FILES)
  
    # read file, prepend using statement, write again ... 
    file(READ ${csFile} content)
    file(WRITE ${csFile} "using System;\nusing System.Runtime.InteropServices;\n\n${content}")

  endif(PATCH_SWIG_FILES)

endforeach()

# delete file if it exists
if (EXISTS ${BIN_DIRECTORY}/libsedmlcsP.dll)
    file(REMOVE ${BIN_DIRECTORY}/libsedmlcsP.dll)	
endif()

# the compile run disables the following warnings
# -  105: warning CS0105: The using directive for `x' appeared previously 
#         in this namespace (needed because of swig 3.0.2)
# -  108: 'method name' hides inherited member 'base member name'. Use the 
#         new keyword if hiding was intended.
# -  114: 'method name' hides inherited member 'base member name'. To make 
#         the current member override that implementation, add the override 
#         keyword. Otherwise add the new keyword.
# - 1570: XML comment on 'class name' has badly formed XML.
# - 1572: XML comment on 'method name' has a param tag for 'parameter name'
#         but there is no parameter by that name.
# - 1573: Parameter 'parameter name' has no matching param tag in the XML 
#         comment for 'method name' (but other parameters do).
# - 1574: XML comment on 'method name' has cref attribute 'method name' 
#         that could not be resolved.
# - 1591: Missing XML comment for publicly visible type or member 'method
#         name'

# compile files
execute_process(
    COMMAND "${CSHARP_COMPILER}"
         -target:library
         -nowarn:105,108,109,1591
         #-nowarn:105,108,109,114,1570,1572,1573,1574,1591
         -out:libsedmlcsP.dll
         -doc:libsedmlcsP.xml
         ${CSHARP_EXTRA_ARGS}
         ${NATIVE_FILES}
    
    WORKING_DIRECTORY "${BIN_DIRECTORY}"
)

# # print variables for debug purposes
# message("BIN_DIRECTORY     : ${BIN_DIRECTORY}")
# message("SRC_DIRECTORY     : ${SRC_DIRECTORY}")
# message("CSHARP_COMPILER   : ${CSHARP_COMPILER}")
# message("CSHARP_EXTRA_ARGS : ${CSHARP_EXTRA_ARGS}")
# 

## delete testrunner if it exists
#if (EXISTS ${BIN_DIRECTORY}/TestRunner.exe)
#    file(REMOVE ${BIN_DIRECTORY}/TestRunner.exe)
#endif()
#
## find all test files
#file(GLOB_RECURSE TEST_FILES RELATIVE ${SRC_DIRECTORY}/test ${SRC_DIRECTORY}/test/*.cs)
#
#set(TEST_FILES ${TEST_FILES} ${SRC_DIRECTORY}/TestRunner.cs
#                             ${SRC_DIRECTORY}/Compiler.cs)
#
## convert paths
#set(NATIVE_TEST_FILES)
#foreach(csFile ${TEST_FILES})
#    file(TO_NATIVE_PATH ${csFile} temp)
#    set(NATIVE_TEST_FILES ${NATIVE_TEST_FILES} ${temp})
#endforeach()
#
#file(TO_NATIVE_PATH ${BIN_DIRECTORY}/TestRunner.exe TEST_RUNNER)
#file(TO_NATIVE_PATH ${BIN_DIRECTORY}/libsedmlcsP.dll MANAGED_LIB)
#
#message("Creating: TestRunner.exe")
#                             
## compile tests
#execute_process(
#    COMMAND "${CSHARP_COMPILER}"
#         -target:exe
#         -nowarn:108,109,114,1570,1572,1573,1574,1591
#         -r:${MANAGED_LIB}
#         -out:${TEST_RUNNER}
#         ${CSHARP_EXTRA_ARGS}
#         ${NATIVE_TEST_FILES}
#    OUTPUT_QUIET    
#    ERROR_QUIET    
#    WORKING_DIRECTORY "${SRC_DIRECTORY}/test"
#)

