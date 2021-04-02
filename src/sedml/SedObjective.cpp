/**
 * @file SedObjective.cpp
 * @brief Implementation of the SedObjective class.
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
#include <sedml/SedObjective.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedLeastSquareObjectiveFunction.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedObjective using the given SED-ML Level and @ p version
 * values.
 */
SedObjective::SedObjective(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mElementName("objective")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedObjective using the given SedNamespaces object @p sedmlns.
 */
SedObjective::SedObjective(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mElementName("objective")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedObjective.
 */
SedObjective::SedObjective(const SedObjective& orig)
  : SedBase( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedObjective.
 */
SedObjective&
SedObjective::operator=(const SedObjective& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedObjective object.
 */
SedObjective*
SedObjective::clone() const
{
  return new SedObjective(*this);
}


/*
 * Destructor for SedObjective.
 */
SedObjective::~SedObjective()
{
}


/*
 * Predicate returning @c true if this abstract "SedObjective" is of type
 * SedLeastSquareObjectiveFunction
 */
bool
SedObjective::isSedLeastSquareObjectiveFunction() const
{
  return dynamic_cast<const SedLeastSquareObjectiveFunction*>(this) != NULL;
}


/*
 * Returns the XML element name of this SedObjective object.
 */
const std::string&
SedObjective::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedObjective object.
 */
void
SedObjective::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedObjective object.
 */
int
SedObjective::getTypeCode() const
{
  return SEDML_OBJECTIVE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedObjective::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedObjective::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedObjective::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedObjective's attribute "attributeName"
 * is set.
 */
bool
SedObjective::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedObjective.
 */
int
SedObjective::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedLeastSquareObjectiveFunction using the given SED-ML Level
 * and @ p version values.
 */
LIBSEDML_EXTERN
SedLeastSquareObjectiveFunction_t *
SedObjective_createLeastSquareObjectiveFunction(unsigned int level,
                                                unsigned int version)
{
  return new SedLeastSquareObjectiveFunction(level, version);
}


/*
 * Creates and returns a deep copy of this SedObjective_t object.
 */
LIBSEDML_EXTERN
SedObjective_t*
SedObjective_clone(const SedObjective_t* so)
{
  if (so != NULL)
  {
    return static_cast<SedObjective_t*>(so->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedObjective_t object.
 */
LIBSEDML_EXTERN
void
SedObjective_free(SedObjective_t* so)
{
  if (so != NULL)
  {
    delete so;
  }
}


/*
 * Predicate returning @c 1 if this SedObjective_t is of type
 * SedLeastSquareObjectiveFunction_t
 */
LIBSEDML_EXTERN
int
SedObjective_isSedLeastSquareObjectiveFunction(const SedObjective_t * so)
{
  return (so != NULL) ?
    static_cast<int>(so->isSedLeastSquareObjectiveFunction()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


