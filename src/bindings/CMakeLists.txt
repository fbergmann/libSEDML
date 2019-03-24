#
# When checked removes all generated SWIG wrappers upon configure
#
option(LIBSEDML_REMOVE_WRAPPERS   "Remove generated SWIG wrappers." OFF)
mark_as_advanced(LIBSEDML_REMOVE_WRAPPERS)

#
# and build selected language bindings
#

if(WITH_CSHARP)
add_subdirectory(csharp)
endif()

if(WITH_JAVA)
add_subdirectory(java)
endif()

if(WITH_PYTHON)
add_subdirectory(python)
endif()


if(WITH_PERL)
add_subdirectory(perl)
endif()

if(WITH_RUBY)
add_subdirectory(ruby)
endif()

if(WITH_R)
add_subdirectory(r)
endif()

