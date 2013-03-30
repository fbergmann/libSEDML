/**
 * @file    libsedml-version.cpp
 * @brief   Define libSEDML version numbers for access from client software.
 * @author  Akiya Jouraku
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sedml.org for more
 * information about SEDML, and the latest version of libSEDML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sedml.org/software/libsedml/license.html
 * ------------------------------------------------------------------------ -->
 */

#include "sedml/common/libsedml-version.h"

LIBSEDML_CPP_NAMESPACE_BEGIN

/**
 * Returns the libSEDML version as an integer: version 1.2.3 becomes 10203.
 *
 * @return the libSEDML version as an integer: version 1.2.3 becomes 10203.
 */
LIBSEDML_EXTERN
int 
getLibSEDMLVersion () 
{ 
  return LIBSEDML_VERSION; 
}


/**
 * Returns the libSEDML version as a string of the form "1.2.3".
 *
 * @return the libSEDML version as a string of the form "1.2.3".
 */
LIBSEDML_EXTERN
const char* 
getLibSEDMLDottedVersion () 
{ 
  return LIBSEDML_DOTTED_VERSION;
}


/**
 * Returns the libSEDML version as a string: version 1.2.3 becomes "10203".
 *
 * @return the libSEDML version as a string: version 1.2.3 becomes "10203".
 */
LIBSEDML_EXTERN
const char* 
getLibSEDMLVersionString () 
{ 
  return LIBSEDML_VERSION_STRING;
}

LIBSEDML_CPP_NAMESPACE_END


