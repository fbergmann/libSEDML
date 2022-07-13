###############################################################################
#
# Description       : CMake build script for libSEDML
#
###############################################################################


include(CheckLibraryExists)
include(CMakePackageConfigHelpers)

check_library_exists(m sqrt "" HAVE_LIBM)

# generate configuration for this system
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/common/libsedml-config-common.h.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-config-common.h"
  )

# Replace: @PACKAGE_VERSION@ and @LIBSEDML_VERSION_NUMERIC@
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/common/libsedml-version.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-version.h"
  )

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/common/libsedml-namespace.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-namespace.h"
  )


###############################################################################
#
# mark header files for installation
#
foreach(dir annotation common compress conversion extension math units util validator xml  )

  file(GLOB header_files "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.h")
  install(FILES ${header_files} DESTINATION include/sedml/${dir})

endforeach(dir)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
install(FILES ${files} DESTINATION include/sedml)

# install generated headers
install(FILES
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-version.h"
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-config-common.h"
       "${CMAKE_CURRENT_BINARY_DIR}/common/libsedml-namespace.h"
        DESTINATION include/sedml/common)

###############################################################################
#
# specify include directories
#
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/..)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/..)

if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

if (EXTRA_DEFS)
add_definitions(${EXTRA_DEFS})
endif()

###############################################################################
#
# Find all sources
#

foreach (directory common sedml )

  set(dir ${directory})

  if ("${directory}" STREQUAL "sedml")
    set(dir ".")
  endif()


  file(GLOB temp
      ${dir}/*.cpp
      ${dir}/*.c
      ${dir}/*.h)

  # create source group for IDEs
  source_group(${directory} FILES ${temp})

  # add to libsedml sources
  set(LIBSEDML_SOURCES ${LIBSEDML_SOURCES} ${temp})

endforeach()

###############################################################################
#
# Build library
#

if (NOT LIBSEDML_SKIP_SHARED_LIBRARY)

add_library (${LIBSEDML_LIBRARY} SHARED ${LIBSEDML_SOURCES} )

if (LIBSEDML_SHARED_VERSION)
  set_target_properties(${LIBSEDML_LIBRARY} PROPERTIES COMPILE_DEFINITIONS "LIBSEDML_EXPORTS=1")
  set_target_properties(${LIBSEDML_LIBRARY} PROPERTIES
                      SOVERSION ${LIBSEDML_VERSION_MAJOR}
                      VERSION ${LIBSEDML_VERSION_MAJOR}.${LIBSEDML_VERSION_MINOR}.${LIBSEDML_VERSION_PATCH})
endif()


target_link_libraries(${LIBSEDML_LIBRARY}
    ${LIBNUML_LIBRARY_NAME}
    ${LIBSBML_LIBRARY_NAME}
    ${EXTRA_LIBS})

INSTALL(TARGETS ${LIBSEDML_LIBRARY}
  EXPORT ${LIBSEDML_LIBRARY}-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION include
  )

install(EXPORT ${LIBSEDML_LIBRARY}-targets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

CONFIGURE_PACKAGE_CONFIG_FILE(
  ${CMAKE_CURRENT_LIST_DIR}/libsedml-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${LIBSEDML_LIBRARY}-config.cmake
  INSTALL_DESTINATION ${PACKAGE_CONFIG_DIR}
)

WRITE_BASIC_PACKAGE_VERSION_FILE(
   ${CMAKE_CURRENT_BINARY_DIR}/${LIBSEDML_LIBRARY}-config-version.cmake
   VERSION ${PROJECT_VERSION}
   COMPATIBILITY AnyNewerVersion
)
install(FILES
          ${CMAKE_CURRENT_BINARY_DIR}/${LIBSEDML_LIBRARY}-config.cmake
          ${CMAKE_CURRENT_BINARY_DIR}/${LIBSEDML_LIBRARY}-config-version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

endif()

add_library (${LIBSEDML_LIBRARY}-static STATIC ${LIBSEDML_SOURCES} )
if (WIN32 AND NOT CYGWIN)
  # don't decorate static library
  set_target_properties(${LIBSEDML_LIBRARY}-static PROPERTIES COMPILE_DEFINITIONS "LIBSEDML_STATIC=1")
endif(WIN32 AND NOT CYGWIN)

target_link_libraries(${LIBSEDML_LIBRARY}-static
        ${LIBNUML_LIBRARY_NAME}
        ${LIBSBML_LIBRARY_NAME}
        ${EXTRA_LIBS})

install(TARGETS ${LIBSEDML_LIBRARY}-static
  EXPORT ${LIBSEDML_LIBRARY}-static-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION include
  )

# and install the exported target configuration
install(EXPORT ${LIBSEDML_LIBRARY}-static-targets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)

CONFIGURE_PACKAGE_CONFIG_FILE(
  ${CMAKE_CURRENT_LIST_DIR}/libsedml-static-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${LIBSEDML_LIBRARY}-static-config.cmake
  INSTALL_DESTINATION ${PACKAGE_CONFIG_DIR}
)

WRITE_BASIC_PACKAGE_VERSION_FILE(
  ${CMAKE_CURRENT_BINARY_DIR}/${LIBSEDML_LIBRARY}-static-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBSEDML_LIBRARY}-static-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBSEDML_LIBRARY}-static-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)
