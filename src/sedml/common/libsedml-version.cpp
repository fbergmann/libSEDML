/**
 * @file libsedml-version.cpp
 * @brief Implementation of the libsedml-version class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */



#include "sedml/common/libsedml-version.h"
#include <string.h>


LIBSEDML_CPP_NAMESPACE_BEGIN

LIBSEDML_EXTERN
int 
getLibSEDMLVersion() 
{ 
  return LIBSEDML_VERSION; 
}


LIBSEDML_EXTERN
const char* 
getLibSEDMLDottedVersion() 
{ 
  return LIBSEDML_DOTTED_VERSION;
}


LIBSEDML_EXTERN
const char* 
getLibSEDMLVersionString() 
{ 
  return LIBSEDML_VERSION_STRING;
}

LIBSEDML_CPP_NAMESPACE_END


