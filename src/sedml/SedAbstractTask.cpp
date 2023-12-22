/**
 * @file SedAbstractTask.cpp
 * @brief Implementation of the SedAbstractTask class.
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
#include <sedml/SedAbstractTask.h>
#include <sedml/SedListOfTasks.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedTask.h>
#include <sedml/SedRepeatedTask.h>
#include <sedml/SedParameterEstimationTask.h>
#include <sedml/SedAlgorithm.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAbstractTask using the given SED-ML Level and @ p version
 * values.
 */
SedAbstractTask::SedAbstractTask(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mElementName("task")
  , mAlgorithm (NULL)
{
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedAbstractTask using the given SedNamespaces object @p
 * sedmlns.
 */
SedAbstractTask::SedAbstractTask(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mElementName("task")
  , mAlgorithm (NULL)
{
  setElementNamespace(sedmlns->getURI());
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Copy constructor for SedAbstractTask.
 */
SedAbstractTask::SedAbstractTask(const SedAbstractTask& orig)
  : SedBase( orig )
  , mElementName ( orig.mElementName )
  , mAlgorithm (NULL)
{
    if (orig.mAlgorithm != NULL)
    {
        mAlgorithm = orig.mAlgorithm->clone();
    }

    connectToChild();
}


/*
 * Assignment operator for SedAbstractTask.
 */
SedAbstractTask&
SedAbstractTask::operator=(const SedAbstractTask& rhs)
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
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAbstractTask object.
 */
SedAbstractTask*
SedAbstractTask::clone() const
{
  return new SedAbstractTask(*this);
}


/*
 * Destructor for SedAbstractTask.
 */
SedAbstractTask::~SedAbstractTask()
{
    delete mAlgorithm;
    mAlgorithm = NULL;
}


/*
 * Returns the value of the "algorithm" element of this SedAbstractTask.
 */
const SedAlgorithm*
SedAbstractTask::getAlgorithm() const
{
    return mAlgorithm;
}


/*
 * Returns the value of the "algorithm" element of this SedAbstractTask.
 */
SedAlgorithm*
SedAbstractTask::getAlgorithm()
{
    return mAlgorithm;
}


/*
 * Predicate returning @c true if this SedAbstractTask's "algorithm" element is
 * set.
 */
bool
SedAbstractTask::isSetAlgorithm() const
{
    return (mAlgorithm != NULL);
}


/*
 * Sets the value of the "algorithm" element of this SedAbstractTask.
 */
int
SedAbstractTask::setAlgorithm(const SedAlgorithm* algorithm)
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
 * Creates a new SedAlgorithm object, adds it to this SedAbstractTask object and
 * returns the SedAlgorithm object created.
 */
SedAlgorithm*
SedAbstractTask::createAlgorithm()
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
 * Unsets the value of the "algorithm" element of this SedAbstractTask.
 */
int
SedAbstractTask::unsetAlgorithm()
{
    delete mAlgorithm;
    mAlgorithm = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Predicate returning @c true if this abstract "SedAbstractTask" is of type
 * SedTask
 */
bool
SedAbstractTask::isSedTask() const
{
  return dynamic_cast<const SedTask*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedAbstractTask" is of type
 * SedRepeatedTask
 */
bool
SedAbstractTask::isSedRepeatedTask() const
{
  return dynamic_cast<const SedRepeatedTask*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedAbstractTask" is of type
 * SedParameterEstimationTask
 */
bool
SedAbstractTask::isSedParameterEstimationTask() const
{
  return dynamic_cast<const SedParameterEstimationTask*>(this) != NULL;
}


/*
 * Returns the XML element name of this SedAbstractTask object.
 */
const std::string&
SedAbstractTask::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedAbstractTask object.
 */
void
SedAbstractTask::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedAbstractTask object.
 */
int
SedAbstractTask::getTypeCode() const
{
  return SEDML_SEDML_ABSTRACTTASK;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAbstractTask object have been set.
 */
bool
SedAbstractTask::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
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
SedAbstractTask::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (isSetAlgorithm() == true)
  {
      if (getLevel() > 1 || getVersion() >= 5) {
          mAlgorithm->write(stream);
      }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAbstractTask::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAbstractTask::setSedDocument(SedDocument* d)
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
SedAbstractTask::connectToChild()
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
 * Gets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::getAttribute(const std::string& attributeName,
                              bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::getAttribute(const std::string& attributeName,
                              int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::getAttribute(const std::string& attributeName,
                              double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::getAttribute(const std::string& attributeName,
                              unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::getAttribute(const std::string& attributeName,
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
 * Predicate returning @c true if this SedAbstractTask's attribute
 * "attributeName" is set.
 */
bool
SedAbstractTask::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::setAttribute(const std::string& attributeName,
                              unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::setAttribute(const std::string& attributeName,
                              const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedAbstractTask.
 */
int
SedAbstractTask::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedAbstractTask.
 */
SedBase*
SedAbstractTask::createChildObject(const std::string& elementName)
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
 * Adds a new "elementName" object to this SedAbstractTask.
 */
int
SedAbstractTask::addChildObject(const std::string& elementName,
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
 * SedAbstractTask.
 */
SedBase*
SedAbstractTask::removeChildObject(const std::string& elementName,
    const std::string& id)
{
    if (elementName == "algorithm")
    {
        SedAlgorithm* obj = mAlgorithm;
        mAlgorithm = NULL; return obj;
    }

    return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedAbstractTask.
 */
unsigned int
SedAbstractTask::getNumObjects(const std::string& elementName)
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
 * Returns the nth object of "objectName" in this SedAbstractTask.
 */
SedBase*
SedAbstractTask::getObject(const std::string& elementName, unsigned int index)
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
SedAbstractTask::getElementBySId(const std::string& id)
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
SedAbstractTask::getAllElements(SedElementFilter* filter)
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
SedAbstractTask::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
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
SedAbstractTask::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
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
SedAbstractTask::readAttributes(
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
    static_cast<SedListOfTasks*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlTaskAllowedAttributes, level,
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
        log->logError(SedmlAbstractTaskAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // id SId (use = "required" )
  // 

  if (!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedAbstractTask> element.";
      log->logError(SedmlAbstractTaskAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedAbstractTask::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedTask using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedTask_t *
SedAbstractTask_createTask(unsigned int level, unsigned int version)
{
  return new SedTask(level, version);
}


/*
 * Creates a new SedRepeatedTask using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedAbstractTask_createRepeatedTask(unsigned int level, unsigned int version)
{
  return new SedRepeatedTask(level, version);
}


/*
 * Creates a new SedParameterEstimationTask using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t *
SedAbstractTask_createParameterEstimationTask(unsigned int level,
                                              unsigned int version)
{
  return new SedParameterEstimationTask(level, version);
}


/*
 * Creates and returns a deep copy of this SedAbstractTask_t object.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedAbstractTask_clone(const SedAbstractTask_t* sat)
{
  if (sat != NULL)
  {
    return static_cast<SedAbstractTask_t*>(sat->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAbstractTask_t object.
 */
LIBSEDML_EXTERN
void
SedAbstractTask_free(SedAbstractTask_t* sat)
{
  if (sat != NULL)
  {
    delete sat;
  }
}


/*
 * Returns the value of the "id" attribute of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
char *
SedAbstractTask_getId(const SedAbstractTask_t * sat)
{
  if (sat == NULL)
  {
    return NULL;
  }

  return sat->getId().empty() ? NULL : safe_strdup(sat->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
char *
SedAbstractTask_getName(const SedAbstractTask_t * sat)
{
  if (sat == NULL)
  {
    return NULL;
  }

  return sat->getName().empty() ? NULL : safe_strdup(sat->getName().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractTask_t's "id" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSetId(const SedAbstractTask_t * sat)
{
  return (sat != NULL) ? static_cast<int>(sat->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractTask_t's "name" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSetName(const SedAbstractTask_t * sat)
{
  return (sat != NULL) ? static_cast<int>(sat->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
int
SedAbstractTask_setId(SedAbstractTask_t * sat, const char * id)
{
  return (sat != NULL) ? sat->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
int
SedAbstractTask_setName(SedAbstractTask_t * sat, const char * name)
{
  return (sat != NULL) ? sat->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
int
SedAbstractTask_unsetId(SedAbstractTask_t * sat)
{
  return (sat != NULL) ? sat->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
int
SedAbstractTask_unsetName(SedAbstractTask_t * sat)
{
  return (sat != NULL) ? sat->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "algorithm" element of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedSimulation_getAlgorithm(const SedAbstractTask_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(ss->getAlgorithm());
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractTask_t's "algorithm"
 * element is set.
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetAlgorithm(const SedAbstractTask_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetAlgorithm()) : 0;
}


/*
 * Sets the value of the "algorithm" element of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_setAlgorithm(SedAbstractTask_t * ss,
                           const SedAlgorithm_t* algorithm)
{
  return (ss != NULL) ? ss->setAlgorithm(algorithm) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedAlgorithm_t object, adds it to this SedAbstractTask_t object
 * and returns the SedAlgorithm_t object created.
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedSimulation_createAlgorithm(SedAbstractTask_t* ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(ss->createAlgorithm());
}


/*
 * Unsets the value of the "algorithm" element of this SedAbstractTask_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetAlgorithm(SedAbstractTask_t * ss)
{
  return (ss != NULL) ? ss->unsetAlgorithm() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if this SedAbstractTask_t is of type SedTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedTask(const SedAbstractTask_t * sat)
{
  return (sat != NULL) ? static_cast<int>(sat->isSedTask()) : 0;
}


/*
 * Predicate returning @c 1 if this SedAbstractTask_t is of type
 * SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedRepeatedTask(const SedAbstractTask_t * sat)
{
  return (sat != NULL) ? static_cast<int>(sat->isSedRepeatedTask()) : 0;
}


/*
 * Predicate returning @c 1 if this SedAbstractTask_t is of type
 * SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedParameterEstimationTask(const SedAbstractTask_t * sat)
{
  return (sat != NULL) ? static_cast<int>(sat->isSedParameterEstimationTask())
    : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAbstractTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAbstractTask_hasRequiredAttributes(const SedAbstractTask_t * sat)
{
  return (sat != NULL) ? static_cast<int>(sat->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


