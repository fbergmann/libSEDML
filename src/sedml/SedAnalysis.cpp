/**
 * @file SedAnalysis.cpp
 * @brief Implementation of the SedAnalysis class.
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
#include <sedml/SedAnalysis.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAnalysis using the given SED-ML Level and @ p version
 * values.
 */
SedAnalysis::SedAnalysis(unsigned int level, unsigned int version)
  : SedSimulation(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedAnalysis using the given SedNamespaces object @p
 * sedmlns.
 */
SedAnalysis::SedAnalysis(SedNamespaces *sedmlns)
  : SedSimulation(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedAnalysis.
 */
SedAnalysis::SedAnalysis(const SedAnalysis& orig)
  : SedSimulation( orig )
{
}


/*
 * Assignment operator for SedAnalysis.
 */
SedAnalysis&
SedAnalysis::operator=(const SedAnalysis& rhs)
{
  if (&rhs != this)
  {
    SedSimulation::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAnalysis object.
 */
SedAnalysis*
SedAnalysis::clone() const
{
  return new SedAnalysis(*this);
}


/*
 * Destructor for SedAnalysis.
 */
SedAnalysis::~SedAnalysis()
{
}


/*
 * Returns the XML element name of this SedAnalysis object.
 */
const std::string&
SedAnalysis::getElementName() const
{
  static const string name = "analysis";
  return name;
}


/*
 * Returns the libSEDML type code for this SedAnalysis object.
 */
int
SedAnalysis::getTypeCode() const
{
  return SEDML_SIMULATION_ANALYSIS;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAnalysis object have been set.
 */
bool
SedAnalysis::hasRequiredAttributes() const
{
  bool allPresent = SedSimulation::hasRequiredAttributes();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedAnalysis::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedSimulation::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAnalysis::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAnalysis::setSedDocument(SedDocument* d)
{
  SedSimulation::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::getAttribute(const std::string& attributeName,
                             bool& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::getAttribute(const std::string& attributeName,
                             int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::getAttribute(const std::string& attributeName,
                             double& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::getAttribute(const std::string& attributeName,
                             unsigned int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::getAttribute(const std::string& attributeName,
                             std::string& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedAnalysis's attribute
 * "attributeName" is set.
 */
bool
SedAnalysis::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedSimulation::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::setAttribute(const std::string& attributeName,
                             unsigned int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::setAttribute(const std::string& attributeName,
                             const std::string& value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedAnalysis.
 */
int
SedAnalysis::unsetAttribute(const std::string& attributeName)
{
  int value = SedSimulation::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedAnalysis::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedSimulation::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedAnalysis::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedSimulation::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAnalysis::readAttributes(
                               const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                 XMLAttributes& attributes,
                               const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                 ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedSimulation::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlSimulationAllowedAttributes, level, version,
          details, getLine(), getColumn());
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
SedAnalysis::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedSimulation::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedAnalysis_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedAnalysis_t *
SedAnalysis_create(unsigned int level, unsigned int version)
{
  return new SedAnalysis(level, version);
}


/*
 * Creates and returns a deep copy of this SedAnalysis_t object.
 */
LIBSEDML_EXTERN
SedAnalysis_t*
SedAnalysis_clone(const SedAnalysis_t* sss)
{
  if (sss != NULL)
  {
    return static_cast<SedAnalysis_t*>(sss->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAnalysis_t object.
 */
LIBSEDML_EXTERN
void
SedAnalysis_free(SedAnalysis_t* sss)
{
  if (sss != NULL)
  {
    delete sss;
  }
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAnalysis_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAnalysis_hasRequiredAttributes(const SedAnalysis_t * sss)
{
  return (sss != NULL) ? static_cast<int>(sss->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


