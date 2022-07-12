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

cmake_minimum_required(VERSION 2.8.12...3.19.0)

###############################################################################
#
# Parse VERSION.txt to determine the package version
#

set(LIBSEDML_VERSION_MAJOR)
set(LIBSEDML_VERSION_MINOR)
set(LIBSEDML_VERSION_PATCH)
set(LIBSEDML_VERSION_RELEASE)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION.txt")

    file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/VERSION.txt" VersionString NEWLINE_CONSUME)
    string(STRIP "${VersionString}" VersionString)
    string(REPLACE "." ";" VersionString "${VersionString}" )
    string(REPLACE "-" ";" VersionString "${VersionString}" )
    list(LENGTH VersionString versionLength)
    list(GET VersionString 0 LIBSEDML_VERSION_MAJOR )
    list(GET VersionString 1 LIBSEDML_VERSION_MINOR )
    list(GET VersionString 2 LIBSEDML_VERSION_PATCH )

    if(${versionLength} GREATER 3)
        list(GET VersionString 3 LIBSEDML_VERSION_RELEASE )
    endif()

endif()

MATH(EXPR LIBSEDML_VERSION_NUMERIC "${LIBSEDML_VERSION_MAJOR} * 10000 + ${LIBSEDML_VERSION_MINOR} * 100 + ${LIBSEDML_VERSION_PATCH}" )
set(LIBSEDML_VERSION "${LIBSEDML_VERSION_MAJOR}.${LIBSEDML_VERSION_MINOR}.${LIBSEDML_VERSION_PATCH}${LIBSEDML_VERSION_RELEASE}")
set(LIBSEDML_DOTTED_VERSION ${LIBSEDML_VERSION})
set(PACKAGE_NAME "libSEDML")

project (libsedml VERSION "${LIBSEDML_VERSION_MAJOR}.${LIBSEDML_VERSION_MINOR}.${LIBSEDML_VERSION_PATCH}"
                  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

SET (CONAN_PATHS ${CMAKE_BINARY_DIR}/../conan_paths.cmake)
if (NOT EXISTS ${CONAN_PATHS})
SET (CONAN_PATHS ${CMAKE_BINARY_DIR}/conan_paths.cmake)
endif()

if (EXISTS ${CONAN_PATHS})
include (${CONAN_PATHS})
endif()

set (CONAN_BUILDINFO ${CMAKE_BINARY_DIR}/../conanbuildinfo.cmake)
if (NOT EXISTS ${CONAN_BUILDINFO})
set (CONAN_BUILDINFO ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()

if (EXISTS ${CONAN_BUILDINFO})
include(${CONAN_BUILDINFO})
conan_basic_setup()
endif()

include (CMakeTestCXXCompiler)
include (CheckCXXSourceCompiles)
include (CheckStructHasMember)
include (CheckLibraryExists)
include (CheckFunctionExists)
include (CheckCCompilerFlag)
include (CheckCSourceRuns)
include (CheckSymbolExists)
include (CheckTypeSize)
include(GNUInstallDirs)

set(PACKAGE_CONFIG_DIR "${CMAKE_INSTALL_LIBDIR}/cmake" CACHE PATH
    "Path into which the cmake config files should be installed")

# PACKAGE_VERSION gets overridden by using other packages, so setting
# the PROJECT_VERSION, which will be used when exporting targets in
# src/CMakeLists.txt
set(PROJECT_VERSION ${LIBSEDML_VERSION})

###############################################################################
#
# The next lines configure the parameters for packaging the binaries.
# They can be invoked with "make package" or "nmake package" or by using
# cpack -G zip|deb|rpm|dmg|nsis
#

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An API library for reading/writing/manipulating SED-ML.")
set(CPACK_PACKAGE_NAME "${PACKAGE_NAME}")
set(CPACK_PACKAGE_VENDOR "The SED-ML Team")
set(CPACK_PACKAGE_CONTACT "LibSEDML Team <libsedml-team@caltech.edu>")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_PACKAGE_VERSION_MAJOR "${LIBSEDML_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${LIBSEDML_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${LIBSEDML_VERSION_PATCH}")
set(CPACK_RPM_PACKAGE_LICENSE "BSD")
set(CPACK_RPM_PACKAGE_GROUP "Libraries/Development")
set(CPACK_DEBIAN_PACKAGE_SECTION "Libraries")

set(CPACK_SOURCE_IGNORE_FILES "${CMAKE_CURRENT_BINARY_DIR};/out/;/.git/;/.svn/;/.libs/;/.deps/;/.bzr/;.*.pyc$;.*.o$;.*.lo$;.*.la$;${CPACK_SOURCE_IGNORE_FILES};/.DS_Store;/.svnignore;blib;libsedml-dist;/.vscode;/.vs;/build/")

if(UNIX)
    set(CPACK_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
    set(CPACK_SET_DESTDIR "ON")
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386")
    set(CPACK_RPM_PACKAGE_ARCHITECTURE "i386")
else()
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
    set(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")
endif()

include(CPack)


###############################################################################
#
# Here we have the main configuration options for libsedml.
#

# Build static / shared library
# option(BUILD_SHARED_LIBS  "Build shared library. (Set to OFF to build static libraries.)" OFF)

# Whether to compile examples
option(WITH_EXAMPLES "Compile the libSEDML example programs."  OFF)

# Which language bindings should be built
option(WITH_CSHARP   "Generate C# language bindings."     OFF)
option(WITH_JAVA     "Generate Java language bindings."   OFF)
option(WITH_PYTHON   "Generate Python language bindings." OFF)
option(WITH_PERL     "Generate Perl language bindings."   OFF)
option(WITH_RUBY     "Generate Ruby language bindings"    OFF)
option(WITH_R        "Generate R language bindings"       OFF)
option(WITH_OCTAVE   "Generate Octave language bindings." OFF)
option(WITH_MATLAB   "Generate MATLAB language bindings." OFF)

option(FIND_LIBSBML  "Search for the libsbml library (must set variables manually if off)." ON)
mark_as_advanced(FIND_LIBSBML)
option(FIND_LIBNUML  "Search for the libnuml library (must set variables manually if off)." ON)
mark_as_advanced(FIND_LIBNUML)


# Add an option to compile with all warnings shown
option(WITH_WALL     "Compile with -Wall, so that the compiler will display all warnings." OFF)
mark_as_advanced(WITH_WALL)

if(WITH_WALL)
    if(MSVC OR USING_INTEL)
        add_definitions(/W4)
    else()
        add_definitions(-Wall)
    endif()
endif()


set(LIBSEDML_BUILD_TYPE "native")
if (CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(LIBSEDML_BUILD_TYPE "32bit")
else()
  set(LIBSEDML_BUILD_TYPE "64bit")
endif()
if (APPLE AND ENABLE_UNIVERSAL)
  set(LIBSEDML_BUILD_TYPE "universal")
endif()


# Use the version number in the shared library.
#
option (LIBSEDML_SHARED_VERSION "Build the libsedml shared library with version information" ON)
mark_as_advanced(LIBSEDML_SHARED_VERSION)

# Use C++ namespace.
option(WITH_CPP_NAMESPACE "Use a C++ namespace for libSEDML."   OFF)

# Generate documentation.
option(WITH_DOXYGEN  "Generate documentation for libSEDML using Doxygen."  OFF )
# marks as advanced, so as to hide documentation generation
mark_as_advanced(WITH_DOXYGEN)

# Re-generate the swig bindings? This really should be on by default
# otherwise one might have the wrong wrapper code without support for
# the libsbml packages one wants.
option(WITH_SWIG     "Regenerate SWIG-based language bindings."  ON )

# Set build type default.
set(CMAKE_BUILD_TYPE "Release" CACHE STRING
    "Choose the build type. The options are: None (CMAKE_CXX_FLAGS or
     CMAKE_C_FLAGS are used), Debug, Release, RelWithDebInfo, MinSizeRel.")
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
  "Choose the build type. The options are: None (CMAKE_CXX_FLAGS or
  CMAKE_C_FLAGS are used), Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
endif()

# Set the default dependency directory.
set(LIBSEDML_DEPENDENCY_DIR ${CMAKE_SOURCE_DIR}/dependencies/ CACHE PATH
    "Directory containing libraries that libSEDML depends upon. (Particularly important on Windows.)")
if("${LIBSEDML_DEPENDENCY_DIR}" STREQUAL "")
  set(LIBSEDML_DEPENDENCY_DIR ${CMAKE_SOURCE_DIR}/dependencies/ CACHE PATH
  "Directory containing libraries that libSEDML depends upon. (Particularly important on Windows.)" FORCE)
endif()


# Update cmake path variables
if (LIBSEDML_DEPENDENCY_DIR AND EXISTS ${LIBSEDML_DEPENDENCY_DIR})
  set(CMAKE_PREFIX_PATH "${LIBSEDML_DEPENDENCY_DIR}/lib/cmake;${CMAKE_PREFIX_PATH}")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}")
# install libsedml find module so it can be found easily later
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules/FindLIBSEDML.cmake" 
        DESTINATION share/cmake/Modules)


###############################################################################
#
# If WITH_SWIG is selected, we need to find swig
#

set (LIBSEDML_USE_CPP_NAMESPACE 0)
if(WITH_CPP_NAMESPACE)
    add_definitions(-DLIBSEDML_USE_CPP_NAMESPACE)
    set (LIBSEDML_USE_CPP_NAMESPACE 1)
endif()

if (SWIG_EXECUTABLE AND NOT EXISTS "${SWIG_EXECUTABLE}")
unset(SWIG_EXECUTABLE CACHE )
unset(SWIG_DIR CACHE )
unset(SWIG_VERSION CACHE )
endif()

if(WITH_SWIG)
    find_program(SWIG_EXECUTABLE
      NAMES swig
      PATHS
        c:/swigwin-3.0.12
        c:/swigwin-3.0.11
        c:/swigwin-3.0.10
        c:/swigwin-3.0.9
        c:/swigwin-3.0.8
        c:/swigwin-3.0.7
        c:/swigwin-3.0.6
        c:/swigwin-3.0.5
        c:/swigwin-3.0.2
        c:/swigwin-3.0.0
        c:/swigwin-2.0.12
        c:/swigwin-2.0.11
        c:/swigwin-2.0.10
        c:/swigwin-2.0.9
        c:/swigwin-2.0.8
        c:/swigwin-2.0.7
        c:/swigwin-2.0.4
        c:/swigwin-2.0.2
        c:/swigwin-2.0.1
        c:/swigwin-2.0.0
        $ENV{ProgramFiles}/swig
        $ENV{ProgramW6432}/swig
        /usr/local/bin
        /opt/local/bin
        /usr/bin
      DOC "The file name of the swig executable."
      )
    set(SWIG_EXTRA_ARGS)
endif(WITH_SWIG)

###############################################################################
#
# Need some variables set up, such as the name for the libSEDML
# library and the Path and file separator characters. The
# MISC_PREFIX variable will cause libsbml bindings, examples and
# documentation to be installed in PREFIX/${MISC_PREFIX}.
#

set( MISC_PREFIX )
if(UNIX OR CYGWIN OR MINGW)
    set(PATH_SEP "/")
    set(FILE_SEP ":")
    set( MISC_PREFIX "${CMAKE_INSTALL_DATADIR}/libsedml/" )
    set(LIBSEDML_LIBRARY sedml)
else()
    set( MISC_PREFIX "./" )
    set(PATH_SEP "\\")
    set(FILE_SEP ";")
    if(MINGW)
        set(LIBSEDML_LIBRARY sedml)
    else()
        set(LIBSEDML_LIBRARY libsedml)
    endif()
endif()

###############################################################################
#
# Locate libsbml
#
if(FIND_LIBSBML)
   find_package(LIBSBML REQUIRED)
endif()
if(FIND_LIBNUML)
   find_package(LIBNUML REQUIRED)
endif()

SET(LIBSEDML_LIBS ${LIBNUML_LIBRARY_NAME} ${LIBSBML_LIBRARY})


###############################################################################
#
# list of additional files to link against.
#

set(EXTRA_LIBS "" CACHE STRING "List of additional libraries to link against." )
set(EXTRA_INCLUDE_DIRS "" CACHE STRING "List of additional include directories to add." )
set(EXTRA_DEFS "" CACHE STRING "List of additional flag to add." )


###############################################################################
#
# Locate zlib
#

set(ZLIB_INITIAL_VALUE)
find_library(LIBZ_LIBRARY
    NAMES zdll.lib z zlib.lib
    PATHS /usr/lib /usr/local/lib
          ${LIBSEDML_DEPENDENCY_DIR}/lib
    DOC "The file name of the zip compression library."
    )

if(EXISTS ${LIBZ_LIBRARY})
    set(ZLIB_INITIAL_VALUE ON)
else()
    set(ZLIB_INITIAL_VALUE OFF)
endif()
option(WITH_ZLIB     "Enable the use of zip compression."    ${ZLIB_INITIAL_VALUE} )

if(WITH_ZLIB)

    find_path(LIBZ_INCLUDE_DIR
        NAMES zlib.h zlib/zlib.h
        PATHS /usr/include /usr/local/include
              ${LIBSEDML_DEPENDENCY_DIR}/include
        DOC "The directory containing the zlib include files."
              )

    add_definitions( -DUSE_ZLIB )

    # make sure that we have a valid zip library
    check_library_exists("${LIBZ_LIBRARY}" "gzopen" "" LIBZ_FOUND_SYMBOL)
    if(NOT LIBZ_FOUND_SYMBOL)
        # this is odd, but on windows this check always fails! must be a
        # bug in the current cmake version so for now only issue this
        # warning on linux
        if(UNIX)
            message(WARNING "The zlib library does not appear to be valid because it is missing certain required symbols. Please check that ${LIBZ_LIBRARY} is the zlib library. For details about the error, please see ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log")
        endif()
    endif()

endif(WITH_ZLIB)


###############################################################################
#
# Find the C# compiler to use and set name for resulting library
#

if(WITH_CSHARP)
   FILE(TO_CMAKE_PATH "$ENV{WINDIR}" windir)
    find_program(CSHARP_COMPILER
        NAMES gmcs csc mcs
        PATHS ${windir}/Microsoft.NET/Framework/v2.0.50727/ 
              /usr/bin /usr/local/bin
        DOC "The file name of the C# compiler."
        )
    if(UNIX)
    else()
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            # mark libsbml library as x86
            set(CSHARP_EXTRA_ARGS -platform:x86 )
        elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
            # mark libsbml library as x64
            set(CSHARP_EXTRA_ARGS -platform:x64 )
        endif()
    endif()

endif(WITH_CSHARP)


###############################################################################
#
# Enable support for testing ... can be invoked by running ctest
# or make test
#

enable_testing()

# On some Linux  (64bit) systems (64bit) the libraries should be installed into lib64 rather
# than lib. It will default to 'lib' but can be overwritten.

set(CMAKE_INSTALL_LIBDIR lib CACHE PATH "Full path to the library output directory")
mark_as_advanced(CMAKE_INSTALL_LIBDIR)

###############################################################################
#
# Set up remaining variables, add option for universal binaries
#

set(USING_INTEL)
if (WIN32 AND CMAKE_C_COMPILER AND CMAKE_C_COMPILER MATCHES ".*icl.*$")
  message(STATUS "Detected Intel Compiler")
  set(USING_INTEL TRUE)
endif ()


set(BUILD_DEFINITIONS)
if(UNIX)
    if(APPLE)
        # on osx starting with xcode 4.3 the system root is in
        # the app bundle, however cmake (up to 2.8.8) does not seem
        # to update the path, so lets try it here
        if (CMAKE_OSX_SYSROOT AND NOT EXISTS ${CMAKE_OSX_SYSROOT})
          if (EXISTS "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/${CMAKE_OSX_SYSROOT}")
            set(CMAKE_OSX_SYSROOT "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/${CMAKE_OSX_SYSROOT}" CACHE STRING "The SDK root to be used" FORCE)
          endif()
        endif()
        add_definitions(-DMACOSX)
        set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DMACOSX")

        # Since we are encountering errors with the use of libc++ on OSX
        # this option allows to override which stdlib to use
        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
          option(CLANG_USE_STDLIB "Use libstdc++ rather than libc++" OFF)
          if (CLANG_USE_STDLIB)
            SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libstdc++" )
          endif()
        endif()
        
        # On OSX it is common to build universal binaries to support multiple
        # processor architectures. The default behavior is not to build
        # multiple architectures, as most users might not need that.
        option(ENABLE_UNIVERSAL "Create universal binaries on Mac OS X." OFF)

        set(CMAKE_OSX_ARCHITECTURES "${CMAKE_OSX_ARCHITECTURES}" CACHE STRING
           "A semicolon-separated list of build architectures to be used.")
        if(ENABLE_UNIVERSAL)
            # if universal binaries are requested and none defined so far
            # overwrite them with all three common architectures. If the user
            # specified their own list of architectures do not touch!
            if(CMAKE_OSX_ARCHITECTURES STREQUAL "")
                STRING(REGEX REPLACE "^.*MacOSX([0-9]*\\.[0-9]*)\\.sdk$" "\\1"
                       OSX_SDK_VERSION "${CMAKE_OSX_SYSROOT}")
                if(OSX_SDK_VERSION  VERSION_EQUAL "10.7" OR OSX_SDK_VERSION  VERSION_EQUAL "10.8")
                   # OSX Lion no longer supports ppc architecture
                   set(CMAKE_OSX_ARCHITECTURES "i386;x86_64" CACHE STRING
                      "A semicolon-separated list of build architectures to be used." FORCE)
                else()
                   set(CMAKE_OSX_ARCHITECTURES "i386;ppc;x86_64" CACHE STRING
                       "A semicolon-separated list of build architectures to be used." FORCE)
                endif()
            endif()
        endif(ENABLE_UNIVERSAL)
    else(APPLE)
        add_definitions(-DLINUX)

        if(NOT CYGWIN)
            # on cygwin all code is position independent so -fPIC is not needed
            set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing -fPIC")
            set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-strict-aliasing -fPIC")
        endif()

        set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DLINUX")
    endif(APPLE)

    add_definitions( -DPACKAGE_VERSION=\"${LIBSEDML_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\")
    set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DPACKAGE_VERSION=\"${LIBSEDML_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\"")

else(UNIX)
    add_definitions(-DPACKAGE_VERSION=\"${LIBSEDML_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\")
    
    add_definitions(-DWIN32)
    set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DWIN32")
 
    if(MSVC OR USING_INTEL)
      add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_DEPRECATE)
      set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -D_CRT_SECURE_NO_WARNINGS")
      option(WITH_STATIC_RUNTIME "Compile using the static MSVC Runtime." OFF)
      if(WITH_STATIC_RUNTIME)
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
      set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
      endif(WITH_STATIC_RUNTIME)

      # CMake no longer creates PDB files for static libraries after 2.8.11
      # so we store debug information in the object files instead
      if (${CMAKE_VERSION} VERSION_GREATER "2.8.11")
        foreach(flag_var
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
            CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
      
            if(${flag_var} MATCHES "/Zi")
              STRING(REPLACE "/Zi"  "/Z7" "${flag_var}" "${${flag_var}}")
            endif(${flag_var} MATCHES "/Zi")
      
        endforeach(flag_var)      
      endif()
        
      file(GLOB WIN32_BINARIES ${LIBSEDML_DEPENDENCY_DIR}/bin/*.dll)
      INSTALL(FILES ${WIN32_BINARIES} DESTINATION "${CMAKE_INSTALL_BINDIR}")
      file(GLOB WIN32_DEPENDENCIES ${LIBSEDML_DEPENDENCY_DIR}/lib/*.lib)
      install(FILES ${WIN32_DEPENDENCIES} DESTINATION "${CMAKE_INSTALL_LIBDIR}")
      if(WITH_LIBXML AND WITH_STATIC_RUNTIME)
        if (EXTRA_LIBS STREQUAL "")
        # populate EXTRA_LIBS variable
            find_library(LIBICONV_LIBRARY
                NAMES libiconv.lib iconv.lib iconv
                PATHS /usr/lib /usr/local/lib
                      ${LIBSEDML_DEPENDENCY_DIR}/lib
                DOC "The file name of the libiconv library."
                )
        set(EXTRA_LIBS "WS2_32.lib;${LIBICONV_LIBRARY};${LIBZ_LIBRARY};" CACHE STRING "List of additional libraries to link against." FORCE)
        endif()
      endif()
    elseif(CYGWIN)
        add_definitions(-DCYGWIN)
        set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DCYGWIN")
    elseif(MINGW)
        if(WITH_LIBXML)
            # this is necessary to build with libxml2 on mingw
            add_definitions(-DLIBXML_STATIC)
        endif(WITH_LIBXML)
    endif(MSVC OR USING_INTEL)

endif(UNIX)


###############################################################################
#
# Disable in-source build
#

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}" )
    message(FATAL_ERROR "In-source builds of libSEDML are disabled. Please create a separate build directory.")
endif()


if (LIBSEDML_PACKAGE_INCLUDES)
  list(REMOVE_DUPLICATES LIBSEDML_PACKAGE_INCLUDES)
endif()

###############################################################################
#
# Build the actual libSEDML library
#

###############################################################################
#
# Initialize SED-ML sources
#
set(LIBSEDML_SOURCES)

###############################################################################
#
# utility macro for copying files only if they have changed, for this it is
# assumed that the source file is always created. Then the macro is called.
# If the target file will only be overwritten if it does not yet exist, or
# its content is different. At the end the source file will be removed.
#
macro(copy_if_different_and_remove source target)
# message(
# "
# copy_if_different_and_remove called with:
#   source = ${source}
#   target = ${target}
# "
# )
file(READ ${source} CONTENT)

if (EXISTS ${target})
  # message("target exists")
  file(READ ${target} CURRENT_CONTENT)
  string(COMPARE EQUAL ${CURRENT_CONTENT} ${CONTENT} IS_SAME)
  if (NOT ${IS_SAME})
    #message("content is different")
    file(WRITE ${target} ${CONTENT})
  endif()
else()
  #message("target does not exist")
  file(WRITE ${target} ${CONTENT})
endif()

file(REMOVE ${source})

endmacro(copy_if_different_and_remove)


###############################################################################
#
# create libsedml-config-common.h
#
include(CheckIncludeFiles)
check_include_files (check.h HAVE_CHECK_H)
check_include_files (expat.h HAVE_EXPAT_H)
check_include_files (errno.h HAVE_ERRNO_H)
check_include_files (math.h HAVE_MATH_H)
check_include_files (sys/types.h HAVE_SYS_TYPES_H)
check_include_files (float.h STDC_HEADERS)
check_include_files (stdarg.h STDC_HEADERS)
check_include_files (stdlib.h STDC_HEADERS)
check_include_files (string.h STDC_HEADERS)

set(WORDS_BIGENDIAN)
if (UNIX)
  include (TestBigEndian)
  test_big_endian(WORDS_BIGENDIAN)
else()
  # test_big_endian seems to fail with nmake (VS 2010) on windows
  # however, windows is always little endian, so catch this here
  set(WORDS_BIGENDIAN FALSE)
endif()

# for whatever reason some of the values are not correctly picked up
# so we encode these values here
if (MSVC)
  set(HAVE_ERRNO_H TRUE)
  set(STDC_HEADERS TRUE)
  set(HAVE_MATH_H TRUE)
  set(HAVE_SYS_TYPES_H TRUE)
endif()

##############################################################################
#
# create library
# 
add_subdirectory(src/sedml)

##############################################################################
#
# create language bindings
# 
add_subdirectory(src/bindings)



###############################################################################
#
# Build examples if specified
#

if(WITH_EXAMPLES)

    # code that builds the examples
    add_subdirectory(examples)

endif(WITH_EXAMPLES)
#
#
#if(WITH_DOXYGEN)
#    add_subdirectory(docs)
#endif()


###############################################################################
#
# Install documentation
#

set(DOCUMENTATION_FILES
        LICENSE.txt
        README.md
        VERSION.txt
)

install(FILES ${DOCUMENTATION_FILES} DESTINATION ${MISC_PREFIX})


###############################################################################
#
# Print Summary
#

if (NOT HOSTNAME)
 site_name(HOSTNAME)
endif()

message(STATUS "
----------------------------------------------------------------------
libSEDML version ${PROJECT_VERSION}
----------------------------------------------------------------------

   More information and the latest version are available online at
   https://github.com/fbergmann/libSEDML/

   Please report problems using the issue tracker at
   https://github.com/fbergmann/libSEDML/issues

   To contact the developers directly, email fbergman@caltech.edu

   Configured on host '${HOSTNAME}'
     host type                     = ${CMAKE_SYSTEM_NAME}
     host operating system         = ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}
     host CPU architecture         = ${CMAKE_SYSTEM_PROCESSOR}

   General build flags:
     CC                            = ${CMAKE_C_COMPILER}
     CXX                           = ${CMAKE_CXX_COMPILER}
     CPPFLAGS                      = ${BUILD_DEFINITIONS}
     CFLAGS                        = ${CMAKE_C_FLAGS}
     CXXFLAGS                      = ${CMAKE_CXX_FLAGS}
     LDFLAGS                       = ${CMAKE_EXE_LINKER_FLAGS}

   SBML library configuration:
     SBML library                  = ${LIBSBML_LIBRARY}
     SBML include                  = -I${LIBSBML_INCLUDE_DIR}

   NUML library configuration:
     NUML library                  = ${LIBNUML_LIBRARY}
     NUML include                  = -I${LIBNUML_INCLUDE_DIR}

  Other libSEDML configuration settings:
     Installation $prefix          = ${CMAKE_INSTALL_PREFIX}")



if(UNIX)
    if(APPLE)
        message(STATUS "  Value of $DYLD_LIBRARY_PATH   = $ENV{DYLD_LIBRARY_PATH}")
    else()
        message(STATUS "  Value of $LD_LIBRARY_PATH     = $ENV{LD_LIBRARY_PATH}")
    endif()
endif()

if(WITH_SWIG)
    message(STATUS "  Using SWIG                    = ${SWIG_EXECUTABLE}")
endif()


if(WITH_CSHARP)
    message(STATUS "  Using C#                      = ${CSHARP_COMPILER}")
endif()

if(WITH_JAVA)
    message(STATUS "  Using Java                    = ${Java_JAVA_EXECUTABLE}")
endif()

if(WITH_PYTHON)
    message(STATUS "  Using Python                  = ${PYTHON_EXECUTABLE}")
endif()

if(WITH_PERL)
    message(STATUS "  Using Perl                    = ${PERL_EXECUTABLE}")
endif()

if(WITH_RUBY)
    message(STATUS "  Using Ruby                    = ${RUBY_EXECUTABLE}")
endif()

if(WITH_OCTAVE)
    message(STATUS "  Using Octave                  = ${MKOCTFILE_EXECUTABLE}")
endif()

if(WITH_MATLAB)
    message(STATUS "  Using Matlab                  = ${MATLAB_ROOT_PATH}")
endif()

if(WITH_CHECK)
    message(STATUS "  Using libcheck                = ${LIBCHECK_LIBRARY}")
endif()
message(STATUS "
")

if(WITH_CPP_NAMESPACE)
    message(STATUS "  Using C++ namespace for libSEDML (libsedml) = yes")
else()
    message(STATUS "  Using C++ namespace for libSEDML (libsedml) = no")
endif()

if(APPLE)
    if(CMAKE_OSX_ARCHITECTURES STREQUAL "")
        message(STATUS "  Building universal binaries                 = no (using native arch)")
    else()
        list(REMOVE_DUPLICATES CMAKE_OSX_ARCHITECTURES)
        list(REMOVE_ITEM CMAKE_OSX_ARCHITECTURES "")
        list(SORT CMAKE_OSX_ARCHITECTURES)
        list(LENGTH CMAKE_OSX_ARCHITECTURES NUM_ARCHS)
        if(NUMARCHS EQUAL 1)
            message(STATUS "  Building universal binaries                 = no (using ${CMAKE_OSX_ARCHITECTURES})")
        else()
            message(STATUS "  Building universal binaries                 = yes (using ${CMAKE_OSX_ARCHITECTURES})")
        endif()
    endif()
endif()


# print selected packages if configured previously
if(EXISTS ${CMAKE_BINARY_DIR}/CMakeCache.txt)

    file(STRINGS  ${CMAKE_BINARY_DIR}/CMakeCache.txt cache)
    set(last_line)
    foreach(line ${cache})
        string(LENGTH "${line}" length)
        if(${length} GREATER 7)
            string(SUBSTRING "${line}" 0 7 start)
            if("${start}" STREQUAL  "ENABLE_")
                if("${line}" MATCHES "^.*ON")
                    message(STATUS "  ${last_line} = yes")
                else()
                    message(STATUS "  ${last_line} = no")
                endif()
            endif()

            math(EXPR length_minus_two "${length} - 2")
            if(${length_minus_two} GREATER 3)
          math(EXPR length_minus_one "${length} - 1")
                string(SUBSTRING "${line}" ${length_minus_one} 1 last_char)
    if("x${last_char}" STREQUAL "x.")
              math(EXPR length_minus_three "${length} - 3")
                    string(SUBSTRING "${line}" 2 ${length_minus_three} last_line)
                else()
                    string(SUBSTRING "${line}" 2 ${length_minus_two} last_line)
                endif()
            endif()
        else()
            set(last_line "")
            message("")
        endif()
    endforeach()

endif()

message(STATUS "
----------------------------------------------------------------------")


add_subdirectory(tests)

## To compile a test program simply comment out the lines below ...
#
#OPTION(WITH_TEST_PROGRAM " COMPILE SMALL TEST PROGRAM " ON)
#
#if(WITH_TEST_PROGRAM)
#
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#
#add_executable(libsbml_test test.cpp)
#target_link_libraries(libsbml_test ${LIBSEDML_LIBRARY}-static)
#
#endif()
#
