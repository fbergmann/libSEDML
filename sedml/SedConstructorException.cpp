/**
 * @file    SedConstructorException.cpp
 * @brief   Implementation of SedConstructorException, the exception class for constructor exceptions
 *
 * <!--------------------------------------------------------------------------
 *
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 *
 *
 * Copyright (c) 2013-2014, Frank T. Bergmann
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ---------------------------------------------------------------------- -->
 */


#include <sedml/SedConstructorException.h>

#include <sedml/SedNamespaces.h>
#include <sbml/xml/XMLNamespaces.h>
#include <sbml/xml/XMLOutputStream.h>

#include <string>
#include <sstream>

LIBSEDML_CPP_NAMESPACE_BEGIN


/** @cond doxygen-libsbml-internal */

SedConstructorException::SedConstructorException(std::string errmsg) :
  std::invalid_argument("Level/version/namespaces combination is invalid")
  , mSedErrMsg(errmsg)
{
}

SedConstructorException::SedConstructorException(std::string errmsg, std::string sbmlErrMsg) :
  std::invalid_argument(errmsg)
  , mSedErrMsg(sbmlErrMsg)
{
}

SedConstructorException::SedConstructorException(std::string elementName, SedNamespaces* sbmlns) :
  std::invalid_argument("Level/version/namespaces combination is invalid")
  , mSedErrMsg(elementName)
{
  if (sbmlns == NULL) return;

  XMLNamespaces* xmlns = sbmlns->getNamespaces();

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

