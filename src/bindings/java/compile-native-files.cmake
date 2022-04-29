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

SET (COMPATIBILITY_ARGS)
if (COMPATIBILIY)
SET (COMPATIBILITY_ARGS ${COMPATIBILITY_ARGS} -source ${COMPATIBILIY} -target ${COMPATIBILIY})
endif()


# compile files
execute_process(
  COMMAND "${Java_JAVAC_EXECUTABLE}"
     ${COMPATIBILITY_ARGS}
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

