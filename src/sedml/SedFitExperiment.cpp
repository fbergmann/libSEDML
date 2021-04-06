/**
 * @file SedFitExperiment.cpp
 * @brief Implementation of the SedFitExperiment class.
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
#include <sedml/SedFitExperiment.h>
#include <sedml/SedListOfFitExperiments.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedFitExperiment using the given SED-ML Level and @ p version
 * values.
 */
SedFitExperiment::SedFitExperiment(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mType (SEDML_EXPERIMENTTYPE_INVALID)
  , mAlgorithm (NULL)
  , mFitMappings (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedFitExperiment using the given SedNamespaces object @p
 * sedmlns.
 */
SedFitExperiment::SedFitExperiment(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mType (SEDML_EXPERIMENTTYPE_INVALID)
  , mAlgorithm (NULL)
  , mFitMappings (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedFitExperiment.
 */
SedFitExperiment::SedFitExperiment(const SedFitExperiment& orig)
  : SedBase( orig )
  , mType ( orig.mType )
  , mAlgorithm ( NULL )
  , mFitMappings ( orig.mFitMappings )
{
  if (orig.mAlgorithm != NULL)
  {
    mAlgorithm = orig.mAlgorithm->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedFitExperiment.
 */
SedFitExperiment&
SedFitExperiment::operator=(const SedFitExperiment& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mType = rhs.mType;
    mFitMappings = rhs.mFitMappings;
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
 * Creates and returns a deep copy of this SedFitExperiment object.
 */
SedFitExperiment*
SedFitExperiment::clone() const
{
  return new SedFitExperiment(*this);
}


/*
 * Destructor for SedFitExperiment.
 */
SedFitExperiment::~SedFitExperiment()
{
  delete mAlgorithm;
  mAlgorithm = NULL;
}


/*
 * Returns the value of the "type" attribute of this SedFitExperiment.
 */
ExperimentType_t
SedFitExperiment::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this SedFitExperiment.
 */
std::string
SedFitExperiment::getTypeAsString() const
{
  std::string code_str = ExperimentType_toString(mType);
  return code_str;
}


/*
 * Predicate returning @c true if this SedFitExperiment's "type" attribute is
 * set.
 */
bool
SedFitExperiment::isSetType() const
{
  return (mType != SEDML_EXPERIMENTTYPE_INVALID);
}


/*
 * Sets the value of the "type" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::setType(const ExperimentType_t type)
{
  if (ExperimentType_isValid(type) == 0)
  {
    mType = SEDML_EXPERIMENTTYPE_INVALID;
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::setType(const std::string& type)
{
  mType = ExperimentType_fromString(type.c_str());

  if (mType == SEDML_EXPERIMENTTYPE_INVALID)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "type" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::unsetType()
{
  mType = SEDML_EXPERIMENTTYPE_INVALID;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the value of the "algorithm" element of this SedFitExperiment.
 */
const SedAlgorithm*
SedFitExperiment::getAlgorithm() const
{
  return mAlgorithm;
}


/*
 * Returns the value of the "algorithm" element of this SedFitExperiment.
 */
SedAlgorithm*
SedFitExperiment::getAlgorithm()
{
  return mAlgorithm;
}


/*
 * Predicate returning @c true if this SedFitExperiment's "algorithm" element
 * is set.
 */
bool
SedFitExperiment::isSetAlgorithm() const
{
  return (mAlgorithm != NULL);
}


/*
 * Sets the value of the "algorithm" element of this SedFitExperiment.
 */
int
SedFitExperiment::setAlgorithm(const SedAlgorithm* algorithm)
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
 * Creates a new SedAlgorithm object, adds it to this SedFitExperiment object
 * and returns the SedAlgorithm object created.
 */
SedAlgorithm*
SedFitExperiment::createAlgorithm()
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
 * Unsets the value of the "algorithm" element of this SedFitExperiment.
 */
int
SedFitExperiment::unsetAlgorithm()
{
  delete mAlgorithm;
  mAlgorithm = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfFitMappings from this SedFitExperiment.
 */
const SedListOfFitMappings*
SedFitExperiment::getListOfFitMappings() const
{
  return &mFitMappings;
}


/*
 * Returns the SedListOfFitMappings from this SedFitExperiment.
 */
SedListOfFitMappings*
SedFitExperiment::getListOfFitMappings()
{
  return &mFitMappings;
}


/*
 * Get a SedFitMapping from the SedFitExperiment.
 */
SedFitMapping*
SedFitExperiment::getFitMapping(unsigned int n)
{
  return mFitMappings.get(n);
}


/*
 * Get a SedFitMapping from the SedFitExperiment.
 */
const SedFitMapping*
SedFitExperiment::getFitMapping(unsigned int n) const
{
  return mFitMappings.get(n);
}


/*
 * Get a SedFitMapping from the SedFitExperiment based on the DataSource to
 * which it refers.
 */
const SedFitMapping*
SedFitExperiment::getFitMappingByDataSource(const std::string& sid) const
{
  return mFitMappings.getByDataSource(sid);
}


/*
 * Get a SedFitMapping from the SedFitExperiment based on the DataSource to
 * which it refers.
 */
SedFitMapping*
SedFitExperiment::getFitMappingByDataSource(const std::string& sid)
{
  return mFitMappings.getByDataSource(sid);
}


/*
 * Get a SedFitMapping from the SedFitExperiment based on the Target to which
 * it refers.
 */
const SedFitMapping*
SedFitExperiment::getFitMappingByTarget(const std::string& sid) const
{
  return mFitMappings.getByTarget(sid);
}


/*
 * Get a SedFitMapping from the SedFitExperiment based on the Target to which
 * it refers.
 */
SedFitMapping*
SedFitExperiment::getFitMappingByTarget(const std::string& sid)
{
  return mFitMappings.getByTarget(sid);
}


/*
 * Get a SedFitMapping from the SedFitExperiment based on the PointWeight to
 * which it refers.
 */
const SedFitMapping*
SedFitExperiment::getFitMappingByPointWeight(const std::string& sid) const
{
  return mFitMappings.getByPointWeight(sid);
}


/*
 * Get a SedFitMapping from the SedFitExperiment based on the PointWeight to
 * which it refers.
 */
SedFitMapping*
SedFitExperiment::getFitMappingByPointWeight(const std::string& sid)
{
  return mFitMappings.getByPointWeight(sid);
}


/*
 * Adds a copy of the given SedFitMapping to this SedFitExperiment.
 */
int
SedFitExperiment::addFitMapping(const SedFitMapping* sfm)
{
  if (sfm == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sfm->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sfm->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sfm->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sfm)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mFitMappings.append(sfm);
  }
}


/*
 * Get the number of SedFitMapping objects in this SedFitExperiment.
 */
unsigned int
SedFitExperiment::getNumFitMappings() const
{
  return mFitMappings.size();
}


/*
 * Creates a new SedFitMapping object, adds it to this SedFitExperiment object
 * and returns the SedFitMapping object created.
 */
SedFitMapping*
SedFitExperiment::createFitMapping()
{
  SedFitMapping* sfm = NULL;

  try
  {
    sfm = new SedFitMapping(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sfm != NULL)
  {
    mFitMappings.appendAndOwn(sfm);
  }

  return sfm;
}


/*
 * Removes the nth SedFitMapping from this SedFitExperiment and returns a
 * pointer to it.
 */
SedFitMapping*
SedFitExperiment::removeFitMapping(unsigned int n)
{
  return mFitMappings.remove(n);
}


/*
 * Returns the XML element name of this SedFitExperiment object.
 */
const std::string&
SedFitExperiment::getElementName() const
{
  static const string name = "fitExperiment";
  return name;
}


/*
 * Returns the libSEDML type code for this SedFitExperiment object.
 */
int
SedFitExperiment::getTypeCode() const
{
  return SEDML_FIT_EXPERIMENT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedFitExperiment object have been set.
 */
bool
SedFitExperiment::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedFitExperiment::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (isSetAlgorithm() == true)
  {
    mAlgorithm->write(stream);
  }

  if (getNumFitMappings() > 0)
  {
    mFitMappings.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedFitExperiment::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedFitExperiment::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  if (mAlgorithm != NULL)
  {
    mAlgorithm->setSedDocument(d);
  }

  mFitMappings.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedFitExperiment::connectToChild()
{
  SedBase::connectToChild();

  if (mAlgorithm != NULL)
  {
    mAlgorithm->connectToParent(this);
  }

  mFitMappings.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::getAttribute(const std::string& attributeName,
                               bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::getAttribute(const std::string& attributeName,
                               int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::getAttribute(const std::string& attributeName,
                               double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::getAttribute(const std::string& attributeName,
                               unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::getAttribute(const std::string& attributeName,
                               std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "type")
  {
    value = getTypeAsString();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedFitExperiment's attribute
 * "attributeName" is set.
 */
bool
SedFitExperiment::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "type")
  {
    value = isSetType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::setAttribute(const std::string& attributeName,
                               unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::setAttribute(const std::string& attributeName,
                               const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "type")
  {
    return_value = setType(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedFitExperiment.
 */
int
SedFitExperiment::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "type")
  {
    value = unsetType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedFitExperiment.
 */
SedBase*
SedFitExperiment::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "algorithm")
  {
    return createAlgorithm();
  }
  else if (elementName == "fitMapping")
  {
    return createFitMapping();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedFitExperiment.
 */
int
SedFitExperiment::addChildObject(const std::string& elementName,
                                 const SedBase* element)
{
  if (elementName == "algorithm" && element->getTypeCode() ==
    SEDML_SIMULATION_ALGORITHM)
  {
    return setAlgorithm((const SedAlgorithm*)(element));
  }
  else if (elementName == "fitMapping" && element->getTypeCode() ==
    SEDML_FITMAPPING)
  {
    return addFitMapping((const SedFitMapping*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedFitExperiment.
 */
SedBase*
SedFitExperiment::removeChildObject(const std::string& elementName,
                                    const std::string& id)
{
  if (elementName == "algorithm")
  {
    SedAlgorithm * obj = mAlgorithm;
    mAlgorithm = NULL; return obj;
  }
  else if (elementName == "fitMapping")
  {
    for (unsigned int i = 0; i < getNumFitMappings(); i++)
    {
      if (getFitMapping(i)->getId() == id)
      {
        return removeFitMapping(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedFitExperiment.
 */
unsigned int
SedFitExperiment::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "algorithm")
  {
    if (isSetAlgorithm())
    {
      return 1;
    }
  }
  else if (elementName == "fitMapping")
  {
    return getNumFitMappings();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedFitExperiment.
 */
SedBase*
SedFitExperiment::getObject(const std::string& elementName,
                            unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "algorithm")
  {
    return getAlgorithm();
  }
  else if (elementName == "fitMapping")
  {
    return getFitMapping(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedFitExperiment::getElementBySId(const std::string& id)
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

  obj = mFitMappings.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns a List of all child SedBase objects, including those nested to an
 * arbitrary depth.
 */
List*
SedFitExperiment::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  SED_ADD_FILTERED_POINTER(ret, sublist, mAlgorithm, filter);

  SED_ADD_FILTERED_LIST(ret, sublist, mFitMappings, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedFitExperiment::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "algorithm")
  {
    if (getErrorLog() && isSetAlgorithm())
    {
      getErrorLog()->logError(SedmlFitExperimentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mAlgorithm;
    mAlgorithm = new SedAlgorithm(getSedNamespaces());
    obj = mAlgorithm;
  }
  else if (name == "listOfFitMappings")
  {
    if (getErrorLog() && mFitMappings.size() != 0)
    {
      getErrorLog()->logError(SedmlFitExperimentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mFitMappings;
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
SedFitExperiment::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("type");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedFitExperiment::readAttributes(
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
    static_cast<SedListOfFitExperiments*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlParameterEstimationTaskLOFitExperimentsAllowedCoreAttributes,
          level, version, details, getLine(), getColumn());
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
        log->logError(SedmlFitExperimentAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // type enum (use = "optional" )
  // 

  std::string type;
  assigned = attributes.readInto("type", type);

  if (assigned == true)
  {
    if (type.empty() == true)
    {
      logEmptyString(type, level, version, "<SedFitExperiment>");
    }
    else
    {
      mType = ExperimentType_fromString(type.c_str());

      if (log && ExperimentType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <SedFitExperiment> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logError(SedmlFitExperimentTypeMustBeExperimentTypeEnum, level,
          version, msg, getLine(), getColumn());
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
SedFitExperiment::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), ExperimentType_toString(mType));
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedFitExperiment_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedFitExperiment_t *
SedFitExperiment_create(unsigned int level, unsigned int version)
{
  return new SedFitExperiment(level, version);
}


/*
 * Creates and returns a deep copy of this SedFitExperiment_t object.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedFitExperiment_clone(const SedFitExperiment_t* sfe)
{
  if (sfe != NULL)
  {
    return static_cast<SedFitExperiment_t*>(sfe->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedFitExperiment_t object.
 */
LIBSEDML_EXTERN
void
SedFitExperiment_free(SedFitExperiment_t* sfe)
{
  if (sfe != NULL)
  {
    delete sfe;
  }
}


/*
 * Returns the value of the "id" attribute of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
char *
SedFitExperiment_getId(const SedFitExperiment_t * sfe)
{
  if (sfe == NULL)
  {
    return NULL;
  }

  return sfe->getId().empty() ? NULL : safe_strdup(sfe->getId().c_str());
}


/*
 * Returns the value of the "type" attribute of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
ExperimentType_t
SedFitExperiment_getType(const SedFitExperiment_t * sfe)
{
  if (sfe == NULL)
  {
    return SEDML_EXPERIMENTTYPE_INVALID;
  }

  return sfe->getType();
}


/*
 * Returns the value of the "type" attribute of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
char *
SedFitExperiment_getTypeAsString(const SedFitExperiment_t * sfe)
{
  return (char*)(ExperimentType_toString(sfe->getType()));
}


/*
 * Predicate returning @c 1 (true) if this SedFitExperiment_t's "id" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_isSetId(const SedFitExperiment_t * sfe)
{
  return (sfe != NULL) ? static_cast<int>(sfe->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedFitExperiment_t's "type"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_isSetType(const SedFitExperiment_t * sfe)
{
  return (sfe != NULL) ? static_cast<int>(sfe->isSetType()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_setId(SedFitExperiment_t * sfe, const char * id)
{
  return (sfe != NULL) ? sfe->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_setType(SedFitExperiment_t * sfe, ExperimentType_t type)
{
  return (sfe != NULL) ? sfe->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_setTypeAsString(SedFitExperiment_t * sfe, const char * type)
{
  return (sfe != NULL) ? sfe->setType(type): LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_unsetId(SedFitExperiment_t * sfe)
{
  return (sfe != NULL) ? sfe->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_unsetType(SedFitExperiment_t * sfe)
{
  return (sfe != NULL) ? sfe->unsetType() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "algorithm" element of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedFitExperiment_getAlgorithm(const SedFitExperiment_t * sfe)
{
  if (sfe == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(sfe->getAlgorithm());
}


/*
 * Predicate returning @c 1 (true) if this SedFitExperiment_t's "algorithm"
 * element is set.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_isSetAlgorithm(const SedFitExperiment_t * sfe)
{
  return (sfe != NULL) ? static_cast<int>(sfe->isSetAlgorithm()) : 0;
}


/*
 * Sets the value of the "algorithm" element of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_setAlgorithm(SedFitExperiment_t * sfe,
                              const SedAlgorithm_t* algorithm)
{
  return (sfe != NULL) ? sfe->setAlgorithm(algorithm) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedAlgorithm_t object, adds it to this SedFitExperiment_t
 * object and returns the SedAlgorithm_t object created.
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedFitExperiment_createAlgorithm(SedFitExperiment_t* sfe)
{
  if (sfe == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(sfe->createAlgorithm());
}


/*
 * Unsets the value of the "algorithm" element of this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_unsetAlgorithm(SedFitExperiment_t * sfe)
{
  return (sfe != NULL) ? sfe->unsetAlgorithm() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedFitMapping_t objects from this
 * SedFitExperiment_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedFitExperiment_getListOfFitMappings(SedFitExperiment_t* sfe)
{
  return (sfe != NULL) ? sfe->getListOfFitMappings() : NULL;
}


/*
 * Get a SedFitMapping_t from the SedFitExperiment_t.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_getFitMapping(SedFitExperiment_t* sfe, unsigned int n)
{
  return (sfe != NULL) ? sfe->getFitMapping(n) : NULL;
}


/*
 * Get a SedFitMapping_t from the SedFitExperiment_t based on the DataSource to
 * which it refers.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_getFitMappingByDataSource(SedFitExperiment_t* sfe,
                                           const char *sid)
{
  return (sfe != NULL && sid != NULL) ? sfe->getFitMappingByDataSource(sid) :
    NULL;
}


/*
 * Get a SedFitMapping_t from the SedFitExperiment_t based on the Target to
 * which it refers.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_getFitMappingByTarget(SedFitExperiment_t* sfe,
                                       const char *sid)
{
  return (sfe != NULL && sid != NULL) ? sfe->getFitMappingByTarget(sid) : NULL;
}


/*
 * Get a SedFitMapping_t from the SedFitExperiment_t based on the PointWeight
 * to which it refers.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_getFitMappingByPointWeight(SedFitExperiment_t* sfe,
                                            const char *sid)
{
  return (sfe != NULL && sid != NULL) ? sfe->getFitMappingByPointWeight(sid) :
    NULL;
}


/*
 * Adds a copy of the given SedFitMapping_t to this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_addFitMapping(SedFitExperiment_t* sfe,
                               const SedFitMapping_t* sfm)
{
  return (sfe != NULL) ? sfe->addFitMapping(sfm) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedFitMapping_t objects in this SedFitExperiment_t.
 */
LIBSEDML_EXTERN
unsigned int
SedFitExperiment_getNumFitMappings(SedFitExperiment_t* sfe)
{
  return (sfe != NULL) ? sfe->getNumFitMappings() : SEDML_INT_MAX;
}


/*
 * Creates a new SedFitMapping_t object, adds it to this SedFitExperiment_t
 * object and returns the SedFitMapping_t object created.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_createFitMapping(SedFitExperiment_t* sfe)
{
  return (sfe != NULL) ? sfe->createFitMapping() : NULL;
}


/*
 * Removes the nth SedFitMapping_t from this SedFitExperiment_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_removeFitMapping(SedFitExperiment_t* sfe, unsigned int n)
{
  return (sfe != NULL) ? sfe->removeFitMapping(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFitExperiment_t object have been set.
 */
LIBSEDML_EXTERN
int
SedFitExperiment_hasRequiredAttributes(const SedFitExperiment_t * sfe)
{
  return (sfe != NULL) ? static_cast<int>(sfe->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


