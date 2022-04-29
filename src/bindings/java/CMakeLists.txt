find_package(SWIG REQUIRED)
find_package(JNI)
find_package(Java COMPONENTS Development REQUIRED)
include(${SWIG_USE_FILE})


####################################################################
#
# create manifest file
# 
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/Manifest.txt.in"
  "${CMAKE_CURRENT_BINARY_DIR}/Manifest.txt"
  )

####################################################################
#
# ensure that javac, jar and python are available
# 

if (NOT EXISTS "${Java_JAVAC_EXECUTABLE}")
  if (NOT EXISTS "${JAVA_COMPILE}")
    message(FATAL_ERROR "The java language bindings require Java_JAVAC_EXECUTABLE to be set to the javac command.")
  else()
    SET(Java_JAVAC_EXECUTABLE "${JAVA_COMPILE}" CACHE STRING "Javac compiler" FORCE)
  endif()
endif()


if (NOT EXISTS "${Java_JAR_EXECUTABLE}")
  if (NOT EXISTS "${JAVA_ARCHIVE}")	
    message(FATAL_ERROR "The java language bindings require Java_JAR_EXECUTABLE to be set to the jar command.")
  else()
        set (Java_JAR_EXECUTABLE "${JAVA_ARCHIVE}" CACHE STRING "jar command" FORCE)
  endif()
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
# Determine the installation directory
#
set(JAVA_PACKAGE_BIN_INSTALL_DIR)
set(JAVA_PACKAGE_JAR_INSTALL_DIR)
if (UNIX OR CYGWIN) 
  set(JAVA_PACKAGE_BIN_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR})
  set(JAVA_PACKAGE_JAR_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/share/java)  
else()
  set(JAVA_PACKAGE_BIN_INSTALL_DIR ${MISC_PREFIX}bindings/java)
  set(JAVA_PACKAGE_JAR_INSTALL_DIR ${MISC_PREFIX}bindings/java)  
endif()

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


set(SWIG_EXTRA_FLAGS -DSWIGEXPORT 
   -DLIBSBML_CPP_NAMESPACE_BEGIN -DLIBSBML_CPP_NAMESPACE_END -DLIBSBML_CPP_NAMESPACE_QUALIFIER -DLIBSBML_CPP_NAMESPACE_USE
   -DLIBNUML_CPP_NAMESPACE_BEGIN -DLIBNUML_CPP_NAMESPACE_END -DLIBNUML_CPP_NAMESPACE_QUALIFIER -DLIBNUML_CPP_NAMESPACE_USE
   )
if(NOT UNIX)
  set(SWIG_EXTRA_FLAGS ${SWIG_EXTRA_FLAGS} -DSWIGWIN -DSWIG_CSHARP_NO_WSTRING_HELPER )
endif()


####################################################################
#
# Swig bindings
#
#
ADD_CUSTOM_COMMAND(	
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp 
         ${CMAKE_CURRENT_BINARY_DIR}/java-files/org/sedml/libsedml/libsedmlJNI.java
  COMMAND "${CMAKE_COMMAND}"
  ARGS    -E make_directory  ${CMAKE_CURRENT_BINARY_DIR}/java-files/org/sedml/libsedml
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
         -I${CMAKE_CURRENT_SOURCE_DIR}/../../
         -I${CMAKE_CURRENT_BINARY_DIR}/../../
         -I${CMAKE_CURRENT_SOURCE_DIR}/../../sedml
         -I${CMAKE_CURRENT_SOURCE_DIR}
         -I${LIBNUML_INCLUDE_DIR}/
         -I${LIBSBML_INCLUDE_DIR}/
     -c++
     -java
     -package org.sedml.libsedml
     ${SWIG_EXTRA_ARGS}
     ${SWIG_EXTRA_FLAGS}
     -outdir ${CMAKE_CURRENT_BINARY_DIR}/java-files/org/sedml/libsedml
         -o ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp 
         ${CMAKE_CURRENT_SOURCE_DIR}/../swig/libsedml.i
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/../swig/libsedml.i
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
          ${SWIG_DEPENDENCIES}
    COMMENT "Swig Java source") 
  
add_custom_target(binding_java_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp)

  
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../swig)
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/../../)
add_definitions(-DLIBSEDML_STATIC)
if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

# if additional directories are set be sure to include them
if (JNI_INCLUDE_DIRS)
include_directories(${JNI_INCLUDE_DIRS})
endif(JNI_INCLUDE_DIRS)
if (JAVA_INCLUDE_PATH)
include_directories(${JAVA_INCLUDE_PATH})
endif(JAVA_INCLUDE_PATH)
if (JAVA_INCLUDE_PATH2)
include_directories(${JAVA_INCLUDE_PATH2})
endif(JAVA_INCLUDE_PATH2)


add_library(binding_java_lib SHARED ${CMAKE_CURRENT_BINARY_DIR}/libsedml_wrap.cpp )
add_dependencies( binding_java_lib binding_java_swig) 
set_target_properties (binding_java_lib PROPERTIES OUTPUT_NAME "sedmlj")


if(APPLE)
  set_target_properties (binding_java_lib PROPERTIES SUFFIX ".jnilib")
endif()

install(TARGETS binding_java_lib DESTINATION ${JAVA_PACKAGE_BIN_INSTALL_DIR} )

target_link_libraries(binding_java_lib ${LIBSEDML_LIBRARY}-static )

set(JAVA_COMPATIBILITY "" CACHE STRING
  "Specify the source and target compatibility for the libsbml Java bindings (for example 1.7). Leave empty to remove the parameter altogether.")


ADD_CUSTOM_COMMAND(	
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/libsedmlj.jar
  COMMAND "${CMAKE_COMMAND}"
  ARGS    -E make_directory  ${CMAKE_CURRENT_BINARY_DIR}/test
  COMMAND "${CMAKE_COMMAND}"
  ARGS -DJava_JAVAC_EXECUTABLE=\"${Java_JAVAC_EXECUTABLE}\"
     -DJava_JAR_EXECUTABLE=\"${Java_JAR_EXECUTABLE}\"
     -DBIN_DIRECTORY=\"${CMAKE_CURRENT_BINARY_DIR}\"
     -DSRC_DIRECTORY=\"${CMAKE_CURRENT_SOURCE_DIR}\"
     -DFILE_SEP=\"${FILE_SEP}\"
     -DPATH_SEP=${PATH_SEP}
     -DCOMPATIBILIY=${JAVA_COMPATIBILITY}
     -P "${CMAKE_CURRENT_SOURCE_DIR}/compile-native-files.cmake"
  
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
    COMMENT "Building: libsedml.jar"
  ) 

add_custom_target(binding_java_jar ALL DEPENDS 
  ${CMAKE_CURRENT_BINARY_DIR}/libsedmlj.jar
  ${CMAKE_CURRENT_BINARY_DIR}/java-files/org/sedml/libsedml/libsedmlJNI.java
  )
  
add_dependencies(binding_java_jar binding_java_swig)
  
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsedmlj.jar DESTINATION ${JAVA_PACKAGE_JAR_INSTALL_DIR}) 
  

