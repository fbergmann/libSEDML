###############################################################################
#
# Description       : CMake build script for libSEDML
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

cmake_minimum_required(VERSION 2.8)
project(libsedml)

include (CMakeTestCCompiler)
include (CheckCSourceCompiles)
include (CheckCXXSourceCompiles)
include (CheckStructHasMember)
include (CheckLibraryExists)
include (CheckFunctionExists)
include (CheckCCompilerFlag)
include (CheckCSourceRuns)
include (CheckSymbolExists)
include (CheckTypeSize)

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

set(LIBSEDML_VERSION_NUMERIC "${LIBSEDML_VERSION_MAJOR}${LIBSEDML_VERSION_MINOR}${LIBSEDML_VERSION_PATCH}${LIBSEDML_VERSION_RELEASE}")
set(PACKAGE_VERSION "${LIBSEDML_VERSION_MAJOR}.${LIBSEDML_VERSION_MINOR}.${LIBSEDML_VERSION_PATCH}${LIBSEDML_VERSION_RELEASE}")
set(PACKAGE_NAME "libSEDML")

# add make dist and make check target as they are already familiar for
# everyone using the gnumake build
add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)

###############################################################################
#
# The next lines configure the parameters for packaging the binaries.
# They can be invoked with "make package" or "nmake package" or by using
# cpack -G zip|deb|rpm|dmg|nsis
#

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An API library for reading/writing/manipulating SEDML.")
set(CPACK_PACKAGE_NAME "${PACKAGE_NAME}")
set(CPACK_PACKAGE_VENDOR "The SEDML Team")
set(CPACK_PACKAGE_CONTACT "LibSEDML Team <libsedml-team@caltech.edu>")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${LIBSEDML_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${LIBSEDML_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${LIBSEDML_VERSION_PATCH}")
set(CPACK_RPM_PACKAGE_LICENSE "BSD")
set(CPACK_RPM_PACKAGE_GROUP "Libraries/Development")
set(CPACK_DEBIAN_PACKAGE_SECTION "Libraries")

set(CPACK_SOURCE_IGNORE_FILES "${CMAKE_CURRENT_BINARY_DIR};/out/;/.git/;/.svn/;/.libs/;/.deps/;/.bzr/;.*.pyc$;.*.o$;.*.lo$;.*.la$;${CPACK_SOURCE_IGNORE_FILES};/.DS_Store;/.svnignore;blib;libsedml-dist")

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

# Enable the generation of unit tests. If enabled, all test runners
# will be created and can be run with "make test" or ctest.
# This won't work in Visual Studio 2003, so we disable this option there.
#
if(NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio 6" AND NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio 7")
    option(WITH_CHECK    "Compile unit tests. Run with 'make test' or 'ctest'." OFF)
endif()

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


###############################################################################
#
# If WITH_SWIG is selected, we need to find swig
#

if(WITH_CPP_NAMESPACE)
    add_definitions(-DLIBSEDML_USE_CPP_NAMESPACE)
endif()

if(WITH_SWIG)
    find_program(SWIG_EXECUTABLE
        NAMES swig
        PATHS
		      c:/swigwin-2.0.7
		      c:/swigwin-2.0.4
              c:/swigwin-2.0.2
              c:/swigwin-2.0.1
              c:/swigwin-2.0.0
              /usr/local/bin
              /opt/local/bin
              /usr/bin
        DOC "The file name of the swig executable."
        )
    set(SWIG_EXTRA_ARGS)
endif(WITH_SWIG)

###############################################################################
#
# Locate libsbml
#
find_library(LIBSBML_LIBRARY
    NAMES libsbml-static.lib sbml-static libsbml.lib sbml
    PATHS /usr/lib /usr/local/lib
          ${LIBSEDML_DEPENDENCY_DIR}/lib
    DOC "The file name of the sbml library."
)

find_path(LIBSBML_INCLUDE_DIR
    NAMES sbml/SBase.h
    PATHS /usr/include /usr/local/include
          /usr/include/libxml2
          /usr/local/include/libxml2
          ${LIBSEDML_DEPENDENCY_DIR}/include
    DOC "The directory containing the sbml include files."
)

set(LIBSBML_STATIC OFF CACHE BOOL "is libsbml statically compiled")
if (WIN32 AND NOT CYGWIN)
if (LIBSBML_LIBRARY AND LIBSBML_LIBRARY MATCHES ".*-static*$")
set(LIBSBML_STATIC ON CACHE BOOL "is libsbml statically compiled")
else()
	option(LIBSBML_STATIC "The LibSBML library was statically compiled" ON)
endif()
endif()

if(NOT EXISTS "${LIBSBML_INCLUDE_DIR}/sbml/SBase.h")
    message(FATAL_ERROR "The include directory specified for sbml appears to be invalid.  It should contain the file sbml/SBase.h, but it does not.")
endif()


###############################################################################
#
# list of additional files to link against.
#

set(EXTRA_LIBS "" CACHE STRING "List of additional libraries to link against." )
set(EXTRA_INCLUDE "" CACHE STRING "List of additional include directories to add." )
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

    if(NOT EXISTS "${LIBZ_INCLUDE_DIR}/zlib.h")
        message(FATAL_ERROR "The zlib include directory does not appear to be valid. It should contain the file zlib.h, but it does not.")
    endif()

endif(WITH_ZLIB)


###############################################################################
#
# Find the C# compiler to use and set name for resulting library
#

if(WITH_CSHARP)
    find_program(CSHARP_COMPILER
        NAMES gmcs csc
        PATHS C:/Windows/Microsoft.NET/Framework/v2.0.50727/ /usr/bin /usr/local/bin
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

if(WITH_CHECK)

    # we do use tests, that require 2.8.4
    cmake_minimum_required(VERSION 2.8.4)

    enable_testing()

    find_library(LIBCHECK_LIBRARY
        NAMES check libcheck
        PATHS /usr/lib /usr/local/lib ${LIBSEDML_DEPENDENCY_DIR}/lib
        DOC "The file name of the libcheck library."
    )

    find_path(LIBCHECK_INCLUDE_DIR
        NAMES check.h
        PATHS /usr/include /usr/local/include  ${LIBSEDML_DEPENDENCY_DIR}/include
        DOC "The directory containing the libcheck include files."
              )

    if(NOT EXISTS "${LIBCHECK_INCLUDE_DIR}/check.h")
        message(FATAL_ERROR "The 'check' include directory appears to be invalid. It should contain the file check.h, but it does not.")
    endif()

    if(${CMAKE_GENERATOR} MATCHES "Visual Studio 6" OR ${CMAKE_GENERATOR} MATCHES "Visual Studio 7")
        message(WARNING "Libcheck is not compatible with Visual Studio 2003 (or earlier versions).")
    endif()


endif(WITH_CHECK)


###############################################################################
#
# Need some variables set up, such as the name for the libSEDML
# library and the Path and file separator characters. The
# MISC_PREFIX variable will cause libsbml bindings, examples and
# documentation to be installed in PREFIX/${MISC_PREFIX}.
#

set( MISC_PREFIX )
if(UNIX OR CYGWIN)
    set(PATH_SEP "/")
    set(FILE_SEP ":")
    set( MISC_PREFIX "share/libsedml/" )
    set(LIBSEDML_LIBRARY sedml)
else()
    set( MISC_PREFIX "" )
    set(PATH_SEP "\\")
    set(FILE_SEP ";")
    if(MINGW)
        set(LIBSEDML_LIBRARY sedml)
    else()
        set(LIBSEDML_LIBRARY libsedml)
    endif()
endif()

# On some Linux  (64bit) systems (64bit) the libraries should be installed into lib64 rather
# than lib. It will default to 'lib' but can be overwritten.

set(CMAKE_INSTALL_LIBDIR lib CACHE PATH "Full path to the library output directory")
mark_as_advanced(CMAKE_INSTALL_LIBDIR)

###############################################################################
#
# Set up remaining variables, add option for universal binaries
#

set(USING_INTEL)
if (WIN32 AND CMAKE_C_COMPILER AND ${CMAKE_C_COMPILER} MATCHES ".*icl.*$")
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

    add_definitions( -DPACKAGE_VERSION=\"${PACKAGE_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\")
    set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DPACKAGE_VERSION=\"${PACKAGE_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\"")

else(UNIX)
    add_definitions(-DPACKAGE_VERSION=\"${PACKAGE_VERSION}\"  -DPACKAGE_NAME=\"${PROJECT_NAME}\")
		
    add_definitions(-DWIN32)
    set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DWIN32")

	if (LIBSBML_STATIC)
      add_definitions(-DLIBSBML_STATIC -DLIBLAX_STATIC)
      set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DLIBSBML_STATIC -DLIBLAX_STATIC")
	else()
      add_definitions(-DLIBSBML_EXPORTS -DLIBLAX_EXPORTS)
      set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -DLIBSBML_EXPORTS -DLIBLAX_EXPORTS")
	endif()
	
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
        endif(WITH_STATIC_RUNTIME)

        file(GLOB WIN32_BINARIES ${LIBSEDML_DEPENDENCY_DIR}/bin/*.dll)
        INSTALL(FILES ${WIN32_BINARIES} DESTINATION bin)
        file(GLOB WIN32_DEPENDENCIES ${LIBSEDML_DEPENDENCY_DIR}/lib/*.lib)
        install(FILES ${WIN32_DEPENDENCIES} DESTINATION lib)
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
# Initialize SEDML sources
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
# 	source = ${source}
# 	target = ${target}
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
check_include_files (ieeefp.h HAVE_IEEEFP_H)
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
  set(HAVE_IEEEFP_H TRUE)
  set(STDC_HEADERS TRUE)
  set(HAVE_MATH_H TRUE)
  set(HAVE_SYS_TYPES_H TRUE)
endif()

##############################################################################
#
# create library
# 
add_subdirectory(sedml)

##############################################################################
#
# create language bindings
# 
add_subdirectory(bindings)



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

install(FILES ${DOCUMENTATION_FILES} DESTINATION ${MISC_PREFIX}.)


###############################################################################
#
# Print Summary
#

message(STATUS "
----------------------------------------------------------------------
libSEDML version ${PACKAGE_VERSION}
----------------------------------------------------------------------

   More information and the latest version are available online at
   http://sbml.org/Software/libSEDML

   Please report problems using the issue tracker at
   http://sbml.org/Software/libsedml/issue-tracker

   To contact the developers directly, email libsedml-team@caltech.edu

   Configured on host "$ENV{COMPUTERNAME}" ${HOSTNAME}
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
        message(STATUS "  Building universal binaries               = no (using native arch)")
    else()
        list(REMOVE_DUPLICATES CMAKE_OSX_ARCHITECTURES)
        list(REMOVE_ITEM CMAKE_OSX_ARCHITECTURES "")
        list(SORT CMAKE_OSX_ARCHITECTURES)
        list(LENGTH CMAKE_OSX_ARCHITECTURES NUM_ARCHS)
        if(NUMARCHS EQUAL 1)
            message(STATUS "  Building universal binaries               = no (using ${CMAKE_OSX_ARCHITECTURES})")
        else()
            message(STATUS "  Building universal binaries               = yes (using ${CMAKE_OSX_ARCHITECTURES})")
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
