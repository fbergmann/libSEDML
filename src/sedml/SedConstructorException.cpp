/**
 * @file SedConstructorException.cpp
 * @brief Implementation of the SedConstructorException class.
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


#include <sedml/SedConstructorException.h>

#include <sedml/SedNamespaces.h>
#include <sbml/xml/XMLNamespaces.h>
#include <sbml/xml/XMLOutputStream.h>

#include <string>
#include <sstream>

LIBSEDML_CPP_NAMESPACE_BEGIN


/** @cond doxygenLibsedmlInternal */

SedConstructorException::SedConstructorException(std::string errmsg) :
      std::invalid_argument("Level/version/namespaces combination is invalid")
    , mSedErrMsg(errmsg)
{
}


SedConstructorException::SedConstructorException (std::string errmsg, std::string sedmlErrMsg) :
    std::invalid_argument(errmsg)
  , mSedErrMsg(sedmlErrMsg)
{
}


SedConstructorException::SedConstructorException (std::string elementName, SedNamespaces* sedmlns) :
    std::invalid_argument("Level/version/namespaces combination is invalid")
  , mSedErrMsg(elementName)
{
  if (sedmlns == NULL) return;
  
  XMLNamespaces* xmlns = sedmlns->getNamespaces();
  
  if (xmlns == NULL) return;
    
  std::ostringstream oss;
  XMLOutputStream xos(oss);
  xos << *xmlns;
  mSedErrMsg.append(oss.str());
  
}


SedConstructorException::~SedConstructorException() throw()
{
}

/** @endcond */

LIBSEDML_CPP_NAMESPACE_END

