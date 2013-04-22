###############################################################################
#
# Description       : CMake build script for libSEDML bindings
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

