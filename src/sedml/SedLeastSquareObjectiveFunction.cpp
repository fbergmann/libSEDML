/**
 * @file SedLeastSquareObjectiveFunction.cpp
 * @brief Implementation of the SedLeastSquareObjectiveFunction class.
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
#include <sedml/SedLeastSquareObjectiveFunction.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedLeastSquareObjectiveFunction using the given SED-ML Level
 * and @ p version values.
 */
SedLeastSquareObjectiveFunction::SedLeastSquareObjectiveFunction(
                                                                 unsigned int
                                                                   level,
                                                                 unsigned int
                                                                   version)
  : SedObjective(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedLeastSquareObjectiveFunction using the given SedNamespaces
 * object @p sedmlns.
 */
SedLeastSquareObjectiveFunction::SedLeastSquareObjectiveFunction(SedNamespaces
  *sedmlns)
  : SedObjective(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedLeastSquareObjectiveFunction.
 */
SedLeastSquareObjectiveFunction::SedLeastSquareObjectiveFunction(const
  SedLeastSquareObjectiveFunction& orig)
  : SedObjective( orig )
{
}


/*
 * Assignment operator for SedLeastSquareObjectiveFunction.
 */
SedLeastSquareObjectiveFunction&
SedLeastSquareObjectiveFunction::operator=(const
  SedLeastSquareObjectiveFunction& rhs)
{
  if (&rhs != this)
  {
    SedObjective::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedLeastSquareObjectiveFunction
 * object.
 */
SedLeastSquareObjectiveFunction*
SedLeastSquareObjectiveFunction::clone() const
{
  return new SedLeastSquareObjectiveFunction(*this);
}


/*
 * Destructor for SedLeastSquareObjectiveFunction.
 */
SedLeastSquareObjectiveFunction::~SedLeastSquareObjectiveFunction()
{
}


/*
 * Returns the XML element name of this SedLeastSquareObjectiveFunction object.
 */
const std::string&
SedLeastSquareObjectiveFunction::getElementName() const
{
  static const string name = "leastSquareObjectiveFunction";
  return name;
}


/*
 * Returns the libSEDML type code for this SedLeastSquareObjectiveFunction
 * object.
 */
int
SedLeastSquareObjectiveFunction::getTypeCode() const
{
  return SEDML_LEAST_SQUARE_OBJECTIVE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedLeastSquareObjectiveFunction object have been set.
 */
bool
SedLeastSquareObjectiveFunction::hasRequiredAttributes() const
{
  bool allPresent = SedObjective::hasRequiredAttributes();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedLeastSquareObjectiveFunction::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedObjective::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedLeastSquareObjectiveFunction::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedLeastSquareObjectiveFunction::setSedDocument(SedDocument* d)
{
  SedObjective::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::getAttribute(const std::string& attributeName,
                                              bool& value) const
{
  int return_value = SedObjective::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::getAttribute(const std::string& attributeName,
                                              int& value) const
{
  int return_value = SedObjective::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::getAttribute(const std::string& attributeName,
                                              double& value) const
{
  int return_value = SedObjective::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::getAttribute(const std::string& attributeName,
                                              unsigned int& value) const
{
  int return_value = SedObjective::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::getAttribute(const std::string& attributeName,
                                              std::string& value) const
{
  int return_value = SedObjective::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedLeastSquareObjectiveFunction's
 * attribute "attributeName" is set.
 */
bool
SedLeastSquareObjectiveFunction::isSetAttribute(const std::string&
  attributeName) const
{
  bool value = SedObjective::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::setAttribute(const std::string& attributeName,
                                              bool value)
{
  int return_value = SedObjective::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::setAttribute(const std::string& attributeName,
                                              int value)
{
  int return_value = SedObjective::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::setAttribute(const std::string& attributeName,
                                              double value)
{
  int return_value = SedObjective::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::setAttribute(const std::string& attributeName,
                                              unsigned int value)
{
  int return_value = SedObjective::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::setAttribute(const std::string& attributeName,
                                              const std::string& value)
{
  int return_value = SedObjective::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedLeastSquareObjectiveFunction.
 */
int
SedLeastSquareObjectiveFunction::unsetAttribute(const std::string&
  attributeName)
{
  int value = SedObjective::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedLeastSquareObjectiveFunction::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = SedObjective::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedLeastSquareObjectiveFunction::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedObjective::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedLeastSquareObjectiveFunction::readAttributes(
                                                const
                                                  LIBSBML_CPP_NAMESPACE_QUALIFIER
                                                    XMLAttributes& attributes,
                                                const
                                                  LIBSBML_CPP_NAMESPACE_QUALIFIER
                                                    ExpectedAttributes&
                                                      expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedObjective::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedUnknown, level, version, details, getLine(),
          getColumn());
      }
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedLeastSquareObjectiveFunction::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedObjective::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedLeastSquareObjectiveFunction_t using the given SED-ML Level
 * and @ p version values.
 */
LIBSEDML_EXTERN
SedLeastSquareObjectiveFunction_t *
SedLeastSquareObjectiveFunction_create(unsigned int level,
                                       unsigned int version)
{
  return new SedLeastSquareObjectiveFunction(level, version);
}


/*
 * Creates and returns a deep copy of this SedLeastSquareObjectiveFunction_t
 * object.
 */
LIBSEDML_EXTERN
SedLeastSquareObjectiveFunction_t*
SedLeastSquareObjectiveFunction_clone(const SedLeastSquareObjectiveFunction_t*
  slsof)
{
  if (slsof != NULL)
  {
    return static_cast<SedLeastSquareObjectiveFunction_t*>(slsof->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedLeastSquareObjectiveFunction_t object.
 */
LIBSEDML_EXTERN
void
SedLeastSquareObjectiveFunction_free(SedLeastSquareObjectiveFunction_t* slsof)
{
  if (slsof != NULL)
  {
    delete slsof;
  }
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedLeastSquareObjectiveFunction_t object have been set.
 */
LIBSEDML_EXTERN
int
SedLeastSquareObjectiveFunction_hasRequiredAttributes(const
  SedLeastSquareObjectiveFunction_t * slsof)
{
  return (slsof != NULL) ? static_cast<int>(slsof->hasRequiredAttributes()) :
    0;
}




LIBSEDML_CPP_NAMESPACE_END


