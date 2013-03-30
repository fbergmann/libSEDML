/**
 * @file    SedMLConstructorException.h
 * @brief   Definition of SedMLConstructorException, the exception class for constructor exceptions
 * @author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSedML.  Please visit http://sbml.org for more
 * information about SedML, and the latest version of libSedML.
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
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 * 
 * @class SedMLConstructorException
 * @ingroup Core
 * @brief Class of exceptions thrown by constructors of some libSedML objects.
 *
 * In some situations, constructors for SedML objects may need to indicate to
 * callers that the creation of the object failed.  The failure may be for
 * different reasons, such as an attempt to use invalid parameters or a
 * system condition such as a memory error.  To communicate this to callers,
 * those classes will throw an SedMLConstructorException.
 *
 * In languages that don't have an exception mechanism (e.g., C), the
 * constructors generally try to return an error code instead of throwing
 * an exception.
 */

#ifndef SEDML_CONSTRUCTOR_EXCEPTION_H
#define SEDML_CONSTRUCTOR_EXCEPTION_H

#include <sedml/common/extern.h>
#include <sedml/SedMLNamespaces.h>

#ifdef __cplusplus

#include <string>
#include <stdexcept>
#include <algorithm>

LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedMLConstructorException : public std::invalid_argument
{
public:

  /** @cond doxygen-libsbml-internal */

  /* constructor */
  SedMLConstructorException (std::string errmsg = "");
  SedMLConstructorException (std::string errmsg, std::string sbmlErrMsg);
  SedMLConstructorException (std::string elementName, SedMLNamespaces* xmlns);
  virtual ~SedMLConstructorException () throw();
  
 /** @endcond */

  /**
   * Returns the message associated with this SedML exception.
   *
   * @return the message string.
   */
  const std::string getSedMLErrMsg() const { return mSedMLErrMsg; }

private:
  std::string mSedMLErrMsg;
};


LIBSEDML_CPP_NAMESPACE_END

#endif /* __cplusplus */

#endif /*SEDML_CONSTRUCTOR_EXCEPTION_H */

