/**
 * @file SedSimulation.cpp
 * @brief Implementation of the SedSimulation class.
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
#include <sedml/SedSimulation.h>
#include <sedml/SedListOfSimulations.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedUniformTimeCourse.h>
#include <sedml/SedOneStep.h>
#include <sedml/SedSteadyState.h>
#include <sedml/SedAnalysis.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSimulation using the given SED-ML Level and @ p version
 * values.
 */
SedSimulation::SedSimulation(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mAlgorithm (NULL)
  , mElementName("simulation")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Creates a new SedSimulation using the given SedNamespaces object @p sedmlns.
 */
SedSimulation::SedSimulation(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mAlgorithm (NULL)
  , mElementName("simulation")
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Copy constructor for SedSimulation.
 */
SedSimulation::SedSimulation(const SedSimulation& orig)
  : SedBase( orig )
  , mAlgorithm ( NULL )
  , mElementName ( orig.mElementName )
{
  if (orig.mAlgorithm != NULL)
  {
    mAlgorithm = orig.mAlgorithm->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedSimulation.
 */
SedSimulation&
SedSimulation::operator=(const SedSimulation& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mElementName = rhs.mElementName;
    delete mAlgorithm;
    if (rhs.mAlgorithm != NULL)
    {
      mAlgorithm = rhs.mAlgorithm->clone();
    }
    else
    {
      mAlgorithm = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSimulation object.
 */
SedSimulation*
SedSimulation::clone() const
{
  return new SedSimulation(*this);
}


/*
 * Destructor for SedSimulation.
 */
SedSimulation::~SedSimulation()
{
  delete mAlgorithm;
  mAlgorithm = NULL;
}


/*
 * Returns the value of the "algorithm" element of this SedSimulation.
 */
const SedAlgorithm*
SedSimulation::getAlgorithm() const
{
  return mAlgorithm;
}


/*
 * Returns the value of the "algorithm" element of this SedSimulation.
 */
SedAlgorithm*
SedSimulation::getAlgorithm()
{
  return mAlgorithm;
}


/*
 * Predicate returning @c true if this SedSimulation's "algorithm" element is
 * set.
 */
bool
SedSimulation::isSetAlgorithm() const
{
  return (mAlgorithm != NULL);
}


/*
 * Sets the value of the "algorithm" element of this SedSimulation.
 */
int
SedSimulation::setAlgorithm(const SedAlgorithm* algorithm)
{
  if (mAlgorithm == algorithm)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (algorithm == NULL)
  {
    delete mAlgorithm;
    mAlgorithm = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mAlgorithm;
    mAlgorithm = (algorithm != NULL) ? algorithm->clone() : NULL;
    if (mAlgorithm != NULL)
    {
      mAlgorithm->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedAlgorithm object, adds it to this SedSimulation object and
 * returns the SedAlgorithm object created.
 */
SedAlgorithm*
SedSimulation::createAlgorithm()
{
  if (mAlgorithm != NULL)
  {
    delete mAlgorithm;
  }

  mAlgorithm = new SedAlgorithm(getSedNamespaces());

  connectToChild();

  return mAlgorithm;
}


/*
 * Unsets the value of the "algorithm" element of this SedSimulation.
 */
int
SedSimulation::unsetAlgorithm()
{
  delete mAlgorithm;
  mAlgorithm = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Predicate returning @c true if this abstract "SedSimulation" is of type
 * SedUniformTimeCourse
 */
bool
SedSimulation::isSedUniformTimeCourse() const
{
  return dynamic_cast<const SedUniformTimeCourse*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedSimulation" is of type
 * SedOneStep
 */
bool
SedSimulation::isSedOneStep() const
{
  return dynamic_cast<const SedOneStep*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedSimulation" is of type
 * SedSteadyState
 */
bool
SedSimulation::isSedSteadyState() const
{
  return dynamic_cast<const SedSteadyState*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedSimulation" is of type
 * SedAnalysis
 */
bool
SedSimulation::isSedAnalysis() const
{
    return dynamic_cast<const SedAnalysis*>(this) != NULL;
}


/*
 * Returns the XML element name of this SedSimulation object.
 */
const std::string&
SedSimulation::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedSimulation object.
 */
void
SedSimulation::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedSimulation object.
 */
int
SedSimulation::getTypeCode() const
{
  return SEDML_SIMULATION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedSimulation object have been set.
 */
bool
SedSimulation::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedSimulation object have been set.
 */
bool
SedSimulation::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetAlgorithm() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedSimulation::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (isSetAlgorithm() == true)
  {
    mAlgorithm->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedSimulation::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSimulation::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  if (mAlgorithm != NULL)
  {
    mAlgorithm->setSedDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedSimulation::connectToChild()
{
  SedBase::connectToChild();

  if (mAlgorithm != NULL)
  {
    mAlgorithm->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::getAttribute(const std::string& attributeName,
                            bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::getAttribute(const std::string& attributeName,
                            int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::getAttribute(const std::string& attributeName,
                            double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::getAttribute(const std::string& attributeName,
                            unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::getAttribute(const std::string& attributeName,
                            std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedSimulation's attribute
 * "attributeName" is set.
 */
bool
SedSimulation::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::setAttribute(const std::string& attributeName,
                            unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::setAttribute(const std::string& attributeName,
                            const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedSimulation.
 */
int
SedSimulation::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedSimulation.
 */
SedBase*
SedSimulation::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "algorithm")
  {
    return createAlgorithm();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedSimulation.
 */
int
SedSimulation::addChildObject(const std::string& elementName,
                              const SedBase* element)
{
  if (elementName == "algorithm" && element->getTypeCode() ==
    SEDML_SIMULATION_ALGORITHM)
  {
    return setAlgorithm((const SedAlgorithm*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedSimulation.
 */
SedBase*
SedSimulation::removeChildObject(const std::string& elementName,
                                 const std::string& id)
{
  if (elementName == "algorithm")
  {
    SedAlgorithm * obj = mAlgorithm;
    mAlgorithm = NULL; return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedSimulation.
 */
unsigned int
SedSimulation::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "algorithm")
  {
    if (isSetAlgorithm())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedSimulation.
 */
SedBase*
SedSimulation::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "algorithm")
  {
    return getAlgorithm();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedSimulation::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mAlgorithm != NULL)
  {
    if (mAlgorithm->getId() == id)
    {
      return mAlgorithm;
    }

    obj = mAlgorithm->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns a List of all child SedBase objects, including those nested to an
 * arbitrary depth.
 */
List*
SedSimulation::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  SED_ADD_FILTERED_POINTER(ret, sublist, mAlgorithm, filter);


  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedSimulation::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "algorithm")
  {
    if (getErrorLog() && isSetAlgorithm())
    {
      getErrorLog()->logError(SedmlSimulationAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mAlgorithm;
    mAlgorithm = new SedAlgorithm(getSedNamespaces());
    obj = mAlgorithm;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSimulation::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSimulation::readAttributes(
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

  if (log && getParentSedObject() &&
    static_cast<SedListOfSimulations*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDocumentLOSimulationsAllowedCoreAttributes, level,
          version, details, getLine(), getColumn());
      }
    }
  }

  SedBase::readAttributes(attributes, expectedAttributes);

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

  if(!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedSimulation> element.";
      log->logError(SedmlSimulationAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedSimulation::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedUniformTimeCourse using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedUniformTimeCourse_t *
SedSimulation_createUniformTimeCourse(unsigned int level,
                                      unsigned int version)
{
  return new SedUniformTimeCourse(level, version);
}


/*
 * Creates a new SedOneStep using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedOneStep_t *
SedSimulation_createOneStep(unsigned int level, unsigned int version)
{
  return new SedOneStep(level, version);
}


/*
 * Creates a new SedSteadyState using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedSteadyState_t *
SedSimulation_createSteadyState(unsigned int level, unsigned int version)
{
  return new SedSteadyState(level, version);
}


/*
 * Creates a new SedAnalysis using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedAnalysis_t*
SedSimulation_createAnalysis(unsigned int level, unsigned int version)
{
    return new SedAnalysis(level, version);
}


/*
 * Creates and returns a deep copy of this SedSimulation_t object.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedSimulation_clone(const SedSimulation_t* ss)
{
  if (ss != NULL)
  {
    return static_cast<SedSimulation_t*>(ss->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSimulation_t object.
 */
LIBSEDML_EXTERN
void
SedSimulation_free(SedSimulation_t* ss)
{
  if (ss != NULL)
  {
    delete ss;
  }
}


/*
 * Returns the value of the "id" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
char *
SedSimulation_getId(const SedSimulation_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getId().empty() ? NULL : safe_strdup(ss->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
char *
SedSimulation_getName(const SedSimulation_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getName().empty() ? NULL : safe_strdup(ss->getName().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedSimulation_t's "id" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetId(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSimulation_t's "name" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetName(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_setId(SedSimulation_t * ss, const char * id)
{
  return (ss != NULL) ? ss->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_setName(SedSimulation_t * ss, const char * name)
{
  return (ss != NULL) ? ss->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetId(SedSimulation_t * ss)
{
  return (ss != NULL) ? ss->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetName(SedSimulation_t * ss)
{
  return (ss != NULL) ? ss->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "algorithm" element of this SedSimulation_t.
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedSimulation_getAlgorithm(const SedSimulation_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(ss->getAlgorithm());
}


/*
 * Predicate returning @c 1 (true) if this SedSimulation_t's "algorithm"
 * element is set.
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetAlgorithm(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetAlgorithm()) : 0;
}


/*
 * Sets the value of the "algorithm" element of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_setAlgorithm(SedSimulation_t * ss,
                           const SedAlgorithm_t* algorithm)
{
  return (ss != NULL) ? ss->setAlgorithm(algorithm) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedAlgorithm_t object, adds it to this SedSimulation_t object
 * and returns the SedAlgorithm_t object created.
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedSimulation_createAlgorithm(SedSimulation_t* ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(ss->createAlgorithm());
}


/*
 * Unsets the value of the "algorithm" element of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetAlgorithm(SedSimulation_t * ss)
{
  return (ss != NULL) ? ss->unsetAlgorithm() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if this SedSimulation_t is of type
 * SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedSimulation_isSedUniformTimeCourse(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSedUniformTimeCourse()) : 0;
}


/*
 * Predicate returning @c 1 if this SedSimulation_t is of type SedOneStep_t
 */
LIBSEDML_EXTERN
int
SedSimulation_isSedOneStep(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSedOneStep()) : 0;
}


/*
 * Predicate returning @c 1 if this SedSimulation_t is of type SedSteadyState_t
 */
LIBSEDML_EXTERN
int
SedSimulation_isSedSteadyState(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSedSteadyState()) : 0;
}


/*
 * Predicate returning @c 1 if this SedSimulation_t is of type SedAnalysis_t
 */
LIBSEDML_EXTERN
int
SedSimulation_isSedAnalysis(const SedSimulation_t* ss)
{
    return (ss != NULL) ? static_cast<int>(ss->isSedAnalysis()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSimulation_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSimulation_hasRequiredAttributes(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedSimulation_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSimulation_hasRequiredElements(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


