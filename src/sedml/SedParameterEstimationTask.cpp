/**
 * @file SedParameterEstimationTask.cpp
 * @brief Implementation of the SedParameterEstimationTask class.
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
#include <sedml/SedParameterEstimationTask.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedLeastSquareObjectiveFunction.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedParameterEstimationTask using the given SED-ML Level and @ p
 * version values.
 */
SedParameterEstimationTask::SedParameterEstimationTask(unsigned int level,
                                                       unsigned int version)
  : SedAbstractTask(level, version)
  , mAlgorithm (NULL)
  , mObjective (NULL)
  , mAdjustableParameters (level, version)
  , mFitExperiments (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedParameterEstimationTask using the given SedNamespaces
 * object @p sedmlns.
 */
SedParameterEstimationTask::SedParameterEstimationTask(SedNamespaces *sedmlns)
  : SedAbstractTask(sedmlns)
  , mAlgorithm (NULL)
  , mObjective (NULL)
  , mAdjustableParameters (sedmlns)
  , mFitExperiments (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedParameterEstimationTask.
 */
SedParameterEstimationTask::SedParameterEstimationTask(const
  SedParameterEstimationTask& orig)
  : SedAbstractTask( orig )
  , mAlgorithm ( NULL )
  , mObjective ( NULL )
  , mAdjustableParameters ( orig.mAdjustableParameters )
  , mFitExperiments ( orig.mFitExperiments )
{
  if (orig.mAlgorithm != NULL)
  {
    mAlgorithm = orig.mAlgorithm->clone();
  }

  if (orig.mObjective != NULL)
  {
    mObjective = orig.mObjective->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedParameterEstimationTask.
 */
SedParameterEstimationTask&
SedParameterEstimationTask::operator=(const SedParameterEstimationTask& rhs)
{
  if (&rhs != this)
  {
    SedAbstractTask::operator=(rhs);
    mAdjustableParameters = rhs.mAdjustableParameters;
    mFitExperiments = rhs.mFitExperiments;
    delete mAlgorithm;
    if (rhs.mAlgorithm != NULL)
    {
      mAlgorithm = rhs.mAlgorithm->clone();
    }
    else
    {
      mAlgorithm = NULL;
    }

    delete mObjective;
    if (rhs.mObjective != NULL)
    {
      mObjective = rhs.mObjective->clone();
    }
    else
    {
      mObjective = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedParameterEstimationTask object.
 */
SedParameterEstimationTask*
SedParameterEstimationTask::clone() const
{
  return new SedParameterEstimationTask(*this);
}


/*
 * Destructor for SedParameterEstimationTask.
 */
SedParameterEstimationTask::~SedParameterEstimationTask()
{
  delete mAlgorithm;
  mAlgorithm = NULL;
  delete mObjective;
  mObjective = NULL;
}


/*
 * Returns the value of the "algorithm" element of this
 * SedParameterEstimationTask.
 */
const SedAlgorithm*
SedParameterEstimationTask::getAlgorithm() const
{
  return mAlgorithm;
}


/*
 * Returns the value of the "algorithm" element of this
 * SedParameterEstimationTask.
 */
SedAlgorithm*
SedParameterEstimationTask::getAlgorithm()
{
  return mAlgorithm;
}


/*
 * Returns the value of the "objective" element of this
 * SedParameterEstimationTask.
 */
const SedObjective*
SedParameterEstimationTask::getObjective() const
{
  return mObjective;
}


/*
 * Returns the value of the "objective" element of this
 * SedParameterEstimationTask.
 */
SedObjective*
SedParameterEstimationTask::getObjective()
{
  return mObjective;
}


/*
 * Predicate returning @c true if this SedParameterEstimationTask's "algorithm"
 * element is set.
 */
bool
SedParameterEstimationTask::isSetAlgorithm() const
{
  return (mAlgorithm != NULL);
}


/*
 * Predicate returning @c true if this SedParameterEstimationTask's "objective"
 * element is set.
 */
bool
SedParameterEstimationTask::isSetObjective() const
{
  return (mObjective != NULL);
}


/*
 * Sets the value of the "algorithm" element of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::setAlgorithm(const SedAlgorithm* algorithm)
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
 * Sets the value of the "objective" element of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::setObjective(const SedObjective* objective)
{
  if (mObjective == objective)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (objective == NULL)
  {
    delete mObjective;
    mObjective = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mObjective;
    mObjective = (objective != NULL) ? objective->clone() : NULL;
    if (mObjective != NULL)
    {
      mObjective->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedAlgorithm object, adds it to this
 * SedParameterEstimationTask object and returns the SedAlgorithm object
 * created.
 */
SedAlgorithm*
SedParameterEstimationTask::createAlgorithm()
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
 * Creates a new SedLeastSquareObjectiveFunction object, adds it to this
 * SedParameterEstimationTask object and returns the
 * SedLeastSquareObjectiveFunction object created.
 */
SedLeastSquareObjectiveFunction*
SedParameterEstimationTask::createLeastSquareObjectiveFunction()
{
  if (mObjective != NULL)
  {
    delete mObjective;
  }

  mObjective = new SedLeastSquareObjectiveFunction(getSedNamespaces());

  connectToChild();

  return static_cast<SedLeastSquareObjectiveFunction*>(mObjective);
}


/*
 * Unsets the value of the "algorithm" element of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::unsetAlgorithm()
{
  delete mAlgorithm;
  mAlgorithm = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "objective" element of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::unsetObjective()
{
  delete mObjective;
  mObjective = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfAdjustableParameters from this
 * SedParameterEstimationTask.
 */
const SedListOfAdjustableParameters*
SedParameterEstimationTask::getListOfAdjustableParameters() const
{
  return &mAdjustableParameters;
}


/*
 * Returns the SedListOfAdjustableParameters from this
 * SedParameterEstimationTask.
 */
SedListOfAdjustableParameters*
SedParameterEstimationTask::getListOfAdjustableParameters()
{
  return &mAdjustableParameters;
}


/*
 * Get a SedAdjustableParameter from the SedParameterEstimationTask.
 */
SedAdjustableParameter*
SedParameterEstimationTask::getAdjustableParameter(unsigned int n)
{
  return mAdjustableParameters.get(n);
}


/*
 * Get a SedAdjustableParameter from the SedParameterEstimationTask.
 */
const SedAdjustableParameter*
SedParameterEstimationTask::getAdjustableParameter(unsigned int n) const
{
  return mAdjustableParameters.get(n);
}


/*
 * Get a SedAdjustableParameter from the SedParameterEstimationTask based on
 * the ModelReference to which it refers.
 */
const SedAdjustableParameter*
SedParameterEstimationTask::getAdjustableParameterByModelReference(const
  std::string& sid) const
{
  return mAdjustableParameters.getByModelReference(sid);
}


/*
 * Get a SedAdjustableParameter from the SedParameterEstimationTask based on
 * the ModelReference to which it refers.
 */
SedAdjustableParameter*
SedParameterEstimationTask::getAdjustableParameterByModelReference(const
  std::string& sid)
{
  return mAdjustableParameters.getByModelReference(sid);
}


/*
 * Adds a copy of the given SedAdjustableParameter to this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::addAdjustableParameter(const
  SedAdjustableParameter* sap)
{
  if (sap == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sap->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sap->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sap->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sap)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mAdjustableParameters.append(sap);
  }
}


/*
 * Get the number of SedAdjustableParameter objects in this
 * SedParameterEstimationTask.
 */
unsigned int
SedParameterEstimationTask::getNumAdjustableParameters() const
{
  return mAdjustableParameters.size();
}


/*
 * Creates a new SedAdjustableParameter object, adds it to this
 * SedParameterEstimationTask object and returns the SedAdjustableParameter
 * object created.
 */
SedAdjustableParameter*
SedParameterEstimationTask::createAdjustableParameter()
{
  SedAdjustableParameter* sap = NULL;

  try
  {
    sap = new SedAdjustableParameter(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sap != NULL)
  {
    mAdjustableParameters.appendAndOwn(sap);
  }

  return sap;
}


/*
 * Removes the nth SedAdjustableParameter from this SedParameterEstimationTask
 * and returns a pointer to it.
 */
SedAdjustableParameter*
SedParameterEstimationTask::removeAdjustableParameter(unsigned int n)
{
  return mAdjustableParameters.remove(n);
}


/*
 * Returns the SedListOfFitExperiments from this SedParameterEstimationTask.
 */
const SedListOfFitExperiments*
SedParameterEstimationTask::getListOfFitExperiments() const
{
  return &mFitExperiments;
}


/*
 * Returns the SedListOfFitExperiments from this SedParameterEstimationTask.
 */
SedListOfFitExperiments*
SedParameterEstimationTask::getListOfFitExperiments()
{
  return &mFitExperiments;
}


/*
 * Get a SedFitExperiment from the SedParameterEstimationTask.
 */
SedFitExperiment*
SedParameterEstimationTask::getFitExperiment(unsigned int n)
{
  return mFitExperiments.get(n);
}


/*
 * Get a SedFitExperiment from the SedParameterEstimationTask.
 */
const SedFitExperiment*
SedParameterEstimationTask::getFitExperiment(unsigned int n) const
{
  return mFitExperiments.get(n);
}


/*
 * Get a SedFitExperiment from the SedParameterEstimationTask based on its
 * identifier.
 */
SedFitExperiment*
SedParameterEstimationTask::getFitExperiment(const std::string& sid)
{
  return mFitExperiments.get(sid);
}


/*
 * Get a SedFitExperiment from the SedParameterEstimationTask based on its
 * identifier.
 */
const SedFitExperiment*
SedParameterEstimationTask::getFitExperiment(const std::string& sid) const
{
  return mFitExperiments.get(sid);
}


/*
 * Adds a copy of the given SedFitExperiment to this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::addFitExperiment(const SedFitExperiment* sfe)
{
  if (sfe == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sfe->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sfe->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sfe->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sfe)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sfe->isSetId() && (mFitExperiments.get(sfe->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mFitExperiments.append(sfe);
  }
}


/*
 * Get the number of SedFitExperiment objects in this
 * SedParameterEstimationTask.
 */
unsigned int
SedParameterEstimationTask::getNumFitExperiments() const
{
  return mFitExperiments.size();
}


/*
 * Creates a new SedFitExperiment object, adds it to this
 * SedParameterEstimationTask object and returns the SedFitExperiment object
 * created.
 */
SedFitExperiment*
SedParameterEstimationTask::createFitExperiment()
{
  SedFitExperiment* sfe = NULL;

  try
  {
    sfe = new SedFitExperiment(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sfe != NULL)
  {
    mFitExperiments.appendAndOwn(sfe);
  }

  return sfe;
}


/*
 * Removes the nth SedFitExperiment from this SedParameterEstimationTask and
 * returns a pointer to it.
 */
SedFitExperiment*
SedParameterEstimationTask::removeFitExperiment(unsigned int n)
{
  return mFitExperiments.remove(n);
}


/*
 * Removes the SedFitExperiment from this SedParameterEstimationTask based on
 * its identifier and returns a pointer to it.
 */
SedFitExperiment*
SedParameterEstimationTask::removeFitExperiment(const std::string& sid)
{
  return mFitExperiments.remove(sid);
}


/*
 * Returns the XML element name of this SedParameterEstimationTask object.
 */
const std::string&
SedParameterEstimationTask::getElementName() const
{
  static const string name = "parameterEstimationTask";
  return name;
}


/*
 * Returns the libSEDML type code for this SedParameterEstimationTask object.
 */
int
SedParameterEstimationTask::getTypeCode() const
{
  return SEDML_TASK_PARAMETER_ESTIMATION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedParameterEstimationTask object have been set.
 */
bool
SedParameterEstimationTask::hasRequiredAttributes() const
{
  bool allPresent = SedAbstractTask::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedParameterEstimationTask object have been set.
 */
bool
SedParameterEstimationTask::hasRequiredElements() const
{
  bool allPresent = SedAbstractTask::hasRequiredElements();

  if (isSetAlgorithm() == false)
  {
    allPresent = false;
  }

  if (isSetObjective() == false)
  {
    allPresent = false;
  }

  if (getNumAdjustableParameters() == 0)
  {
    allPresent = false;
  }

  if (getNumFitExperiments() == 0)
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
SedParameterEstimationTask::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedAbstractTask::writeElements(stream);

  if (isSetAlgorithm() == true)
  {
    mAlgorithm->write(stream);
  }

  if (isSetObjective() == true)
  {
    mObjective->write(stream);
  }

  if (getNumAdjustableParameters() > 0)
  {
    mAdjustableParameters.write(stream);
  }

  if (getNumFitExperiments() > 0)
  {
    mFitExperiments.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedParameterEstimationTask::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedParameterEstimationTask::setSedDocument(SedDocument* d)
{
  SedAbstractTask::setSedDocument(d);

  if (mAlgorithm != NULL)
  {
    mAlgorithm->setSedDocument(d);
  }

  if (mObjective != NULL)
  {
    mObjective->setSedDocument(d);
  }

  mAdjustableParameters.setSedDocument(d);

  mFitExperiments.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedParameterEstimationTask::connectToChild()
{
  SedAbstractTask::connectToChild();

  if (mAlgorithm != NULL)
  {
    mAlgorithm->connectToParent(this);
  }

  if (mObjective != NULL)
  {
    mObjective->connectToParent(this);
  }

  mAdjustableParameters.connectToParent(this);

  mFitExperiments.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::getAttribute(const std::string& attributeName,
                                         bool& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::getAttribute(const std::string& attributeName,
                                         int& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::getAttribute(const std::string& attributeName,
                                         double& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::getAttribute(const std::string& attributeName,
                                         unsigned int& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::getAttribute(const std::string& attributeName,
                                         std::string& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedParameterEstimationTask's attribute
 * "attributeName" is set.
 */
bool
SedParameterEstimationTask::isSetAttribute(const std::string& attributeName)
  const
{
  bool value = SedAbstractTask::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::setAttribute(const std::string& attributeName,
                                         bool value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::setAttribute(const std::string& attributeName,
                                         int value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::setAttribute(const std::string& attributeName,
                                         double value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::setAttribute(const std::string& attributeName,
                                         unsigned int value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::setAttribute(const std::string& attributeName,
                                         const std::string& value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::unsetAttribute(const std::string& attributeName)
{
  int value = SedAbstractTask::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this
 * SedParameterEstimationTask.
 */
SedBase*
SedParameterEstimationTask::createChildObject(const std::string& elementName)
{
  SedAbstractTask* obj = NULL;

  if (elementName == "algorithm")
  {
    return createAlgorithm();
  }
  else if (elementName == "leastSquareObjectiveFunction")
  {
    return createLeastSquareObjectiveFunction();
  }
  else if (elementName == "adjustableParameter")
  {
    return createAdjustableParameter();
  }
  else if (elementName == "fitExperiment")
  {
    return createFitExperiment();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedParameterEstimationTask.
 */
int
SedParameterEstimationTask::addChildObject(const std::string& elementName,
                                           const SedBase* element)
{
  if (elementName == "algorithm" && element->getTypeCode() ==
    SEDML_SIMULATION_ALGORITHM)
  {
    return setAlgorithm((const SedAlgorithm*)(element));
  }
  else if (elementName == "leastSquareObjectiveFunction" &&
    element->getTypeCode() == SEDML_LEAST_SQUARE_OBJECTIVE)
  {
    return setObjective((const SedObjective*)(element));
  }
  else if (elementName == "adjustableParameter" && element->getTypeCode() ==
    SEDML_ADJUSTABLE_PARAMETER)
  {
    return addAdjustableParameter((const SedAdjustableParameter*)(element));
  }
  else if (elementName == "fitExperiment" && element->getTypeCode() ==
    SEDML_FIT_EXPERIMENT)
  {
    return addFitExperiment((const SedFitExperiment*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedParameterEstimationTask.
 */
SedBase*
SedParameterEstimationTask::removeChildObject(const std::string& elementName,
                                              const std::string& id)
{
  if (elementName == "algorithm")
  {
    SedAlgorithm * obj = mAlgorithm;
    mAlgorithm = NULL; return obj;
  }
  else if (elementName == "leastSquareObjectiveFunction")
  {
    SedObjective * obj = mObjective;
    mObjective = NULL;
    return obj;
  }
  else if (elementName == "adjustableParameter")
  {
    for (unsigned int i = 0; i < getNumAdjustableParameters(); i++)
    {
      if (getAdjustableParameter(i)->getId() == id)
      {
        return removeAdjustableParameter(i);
      }
    }
  }
  else if (elementName == "fitExperiment")
  {
    return removeFitExperiment(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedParameterEstimationTask.
 */
unsigned int
SedParameterEstimationTask::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "algorithm")
  {
    if (isSetAlgorithm())
    {
      return 1;
    }
  }
  else if (elementName == "objective")
  {
    if (isSetObjective())
    {
      return 1;
    }
  }
  else if (elementName == "adjustableParameter")
  {
    return getNumAdjustableParameters();
  }
  else if (elementName == "fitExperiment")
  {
    return getNumFitExperiments();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedParameterEstimationTask.
 */
SedBase*
SedParameterEstimationTask::getObject(const std::string& elementName,
                                      unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "algorithm")
  {
    return getAlgorithm();
  }
  else if (elementName == "objective")
  {
    return getObjective();
  }
  else if (elementName == "adjustableParameter")
  {
    return getAdjustableParameter(index);
  }
  else if (elementName == "fitExperiment")
  {
    return getFitExperiment(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedParameterEstimationTask::getElementBySId(const std::string& id)
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

  if (mObjective != NULL)
  {
    if (mObjective->getId() == id)
    {
      return mObjective;
    }

    obj = mObjective->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mAdjustableParameters.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mFitExperiments.getElementBySId(id);

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
SedParameterEstimationTask::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  SED_ADD_FILTERED_POINTER(ret, sublist, mAlgorithm, filter);
  SED_ADD_FILTERED_POINTER(ret, sublist, mObjective, filter);

  SED_ADD_FILTERED_LIST(ret, sublist, mAdjustableParameters, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mFitExperiments, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedParameterEstimationTask::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = SedAbstractTask::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "leastSquareObjectiveFunction")
  {
    if (getErrorLog() && isSetObjective())
    {
      getErrorLog()->logError(SedmlParameterEstimationTaskAllowedElements,
        getLevel(), getVersion(), "", getLine(), getColumn());
    }

    delete mObjective;
    mObjective = new SedLeastSquareObjectiveFunction(getSedNamespaces());
    obj = mObjective;
  }
  else if (name == "algorithm")
  {
    if (getErrorLog() && isSetAlgorithm())
    {
      getErrorLog()->logError(SedmlParameterEstimationTaskAllowedElements,
        getLevel(), getVersion(), "", getLine(), getColumn());
    }

    delete mAlgorithm;
    mAlgorithm = new SedAlgorithm(getSedNamespaces());
    obj = mAlgorithm;
  }

  if (name == "listOfAdjustableParameters")
  {
    if (getErrorLog() && mAdjustableParameters.size() != 0)
    {
      getErrorLog()->logError(SedmlParameterEstimationTaskAllowedElements,
        getLevel(), getVersion(), "", getLine(), getColumn());
    }

    obj = &mAdjustableParameters;
  }
  else if (name == "listOfFitExperiments")
  {
    if (getErrorLog() && mFitExperiments.size() != 0)
    {
      getErrorLog()->logError(SedmlParameterEstimationTaskAllowedElements,
        getLevel(), getVersion(), "", getLine(), getColumn());
    }

    obj = &mFitExperiments;
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
SedParameterEstimationTask::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedAbstractTask::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedParameterEstimationTask::readAttributes(
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

  SedAbstractTask::readAttributes(attributes, expectedAttributes);

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
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedParameterEstimationTask::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedAbstractTask::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedParameterEstimationTask_t using the given SED-ML Level and @
 * p version values.
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t *
SedParameterEstimationTask_create(unsigned int level, unsigned int version)
{
  return new SedParameterEstimationTask(level, version);
}


/*
 * Creates and returns a deep copy of this SedParameterEstimationTask_t object.
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t*
SedParameterEstimationTask_clone(const SedParameterEstimationTask_t* spet)
{
  if (spet != NULL)
  {
    return static_cast<SedParameterEstimationTask_t*>(spet->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedParameterEstimationTask_t object.
 */
LIBSEDML_EXTERN
void
SedParameterEstimationTask_free(SedParameterEstimationTask_t* spet)
{
  if (spet != NULL)
  {
    delete spet;
  }
}


/*
 * Returns the value of the "algorithm" element of this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedParameterEstimationTask_getAlgorithm(const SedParameterEstimationTask_t *
  spet)
{
  if (spet == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(spet->getAlgorithm());
}


/*
 * Returns the value of the "objective" element of this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
const SedObjective_t*
SedParameterEstimationTask_getObjective(const SedParameterEstimationTask_t *
  spet)
{
  if (spet == NULL)
  {
    return NULL;
  }

  return (SedObjective_t*)(spet->getObjective());
}


/*
 * Predicate returning @c 1 (true) if this SedParameterEstimationTask_t's
 * "algorithm" element is set.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_isSetAlgorithm(const SedParameterEstimationTask_t *
  spet)
{
  return (spet != NULL) ? static_cast<int>(spet->isSetAlgorithm()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedParameterEstimationTask_t's
 * "objective" element is set.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_isSetObjective(const SedParameterEstimationTask_t *
  spet)
{
  return (spet != NULL) ? static_cast<int>(spet->isSetObjective()) : 0;
}


/*
 * Sets the value of the "algorithm" element of this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_setAlgorithm(SedParameterEstimationTask_t * spet,
                                        const SedAlgorithm_t* algorithm)
{
  return (spet != NULL) ? spet->setAlgorithm(algorithm) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "objective" element of this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_setObjective(SedParameterEstimationTask_t * spet,
                                        const SedObjective_t* objective)
{
  return (spet != NULL) ? spet->setObjective(objective) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedAlgorithm_t object, adds it to this
 * SedParameterEstimationTask_t object and returns the SedAlgorithm_t object
 * created.
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedParameterEstimationTask_createAlgorithm(SedParameterEstimationTask_t* spet)
{
  if (spet == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(spet->createAlgorithm());
}


/*
 * Creates a new SedLeastSquareObjectiveFunction_t object, adds it to this
 * SedParameterEstimationTask_t object and returns the
 * SedLeastSquareObjectiveFunction_t object created.
 */
LIBSEDML_EXTERN
SedLeastSquareObjectiveFunction_t*
SedParameterEstimationTask_createLeastSquareObjectiveFunction(SedParameterEstimationTask_t*
  spet)
{
  return (spet != NULL) ? spet->createLeastSquareObjectiveFunction() : NULL;
}


/*
 * Unsets the value of the "algorithm" element of this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_unsetAlgorithm(SedParameterEstimationTask_t * spet)
{
  return (spet != NULL) ? spet->unsetAlgorithm() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "objective" element of this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_unsetObjective(SedParameterEstimationTask_t * spet)
{
  return (spet != NULL) ? spet->unsetObjective() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedAdjustableParameter_t objects from this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedParameterEstimationTask_getListOfAdjustableParameters(SedParameterEstimationTask_t*
  spet)
{
  return (spet != NULL) ? spet->getListOfAdjustableParameters() : NULL;
}


/*
 * Get a SedAdjustableParameter_t from the SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedParameterEstimationTask_getAdjustableParameter(
                                                  SedParameterEstimationTask_t*
                                                    spet,
                                                  unsigned int n)
{
  return (spet != NULL) ? spet->getAdjustableParameter(n) : NULL;
}


/*
 * Get a SedAdjustableParameter_t from the SedParameterEstimationTask_t based
 * on the ModelReference to which it refers.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedParameterEstimationTask_getAdjustableParameterByModelReference(
                                                                  SedParameterEstimationTask_t*
                                                                    spet,
                                                                  const char
                                                                    *sid)
{
  return (spet != NULL && sid != NULL) ?
    spet->getAdjustableParameterByModelReference(sid) : NULL;
}


/*
 * Adds a copy of the given SedAdjustableParameter_t to this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_addAdjustableParameter(
                                                  SedParameterEstimationTask_t*
                                                    spet,
                                                  const
                                                    SedAdjustableParameter_t*
                                                      sap)
{
  return (spet != NULL) ? spet->addAdjustableParameter(sap) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedAdjustableParameter_t objects in this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
unsigned int
SedParameterEstimationTask_getNumAdjustableParameters(SedParameterEstimationTask_t*
  spet)
{
  return (spet != NULL) ? spet->getNumAdjustableParameters() : SEDML_INT_MAX;
}


/*
 * Creates a new SedAdjustableParameter_t object, adds it to this
 * SedParameterEstimationTask_t object and returns the SedAdjustableParameter_t
 * object created.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedParameterEstimationTask_createAdjustableParameter(SedParameterEstimationTask_t*
  spet)
{
  return (spet != NULL) ? spet->createAdjustableParameter() : NULL;
}


/*
 * Removes the nth SedAdjustableParameter_t from this
 * SedParameterEstimationTask_t and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedParameterEstimationTask_removeAdjustableParameter(
                                                     SedParameterEstimationTask_t*
                                                       spet,
                                                     unsigned int n)
{
  return (spet != NULL) ? spet->removeAdjustableParameter(n) : NULL;
}


/*
 * Returns a ListOf_t * containing SedFitExperiment_t objects from this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedParameterEstimationTask_getListOfFitExperiments(SedParameterEstimationTask_t*
  spet)
{
  return (spet != NULL) ? spet->getListOfFitExperiments() : NULL;
}


/*
 * Get a SedFitExperiment_t from the SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_getFitExperiment(SedParameterEstimationTask_t* spet,
                                            unsigned int n)
{
  return (spet != NULL) ? spet->getFitExperiment(n) : NULL;
}


/*
 * Get a SedFitExperiment_t from the SedParameterEstimationTask_t based on its
 * identifier.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_getFitExperimentById(
                                                SedParameterEstimationTask_t*
                                                  spet,
                                                const char *sid)
{
  return (spet != NULL && sid != NULL) ? spet->getFitExperiment(sid) : NULL;
}


/*
 * Adds a copy of the given SedFitExperiment_t to this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_addFitExperiment(SedParameterEstimationTask_t* spet,
                                            const SedFitExperiment_t* sfe)
{
  return (spet != NULL) ? spet->addFitExperiment(sfe) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedFitExperiment_t objects in this
 * SedParameterEstimationTask_t.
 */
LIBSEDML_EXTERN
unsigned int
SedParameterEstimationTask_getNumFitExperiments(SedParameterEstimationTask_t*
  spet)
{
  return (spet != NULL) ? spet->getNumFitExperiments() : SEDML_INT_MAX;
}


/*
 * Creates a new SedFitExperiment_t object, adds it to this
 * SedParameterEstimationTask_t object and returns the SedFitExperiment_t
 * object created.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_createFitExperiment(SedParameterEstimationTask_t*
  spet)
{
  return (spet != NULL) ? spet->createFitExperiment() : NULL;
}


/*
 * Removes the nth SedFitExperiment_t from this SedParameterEstimationTask_t
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_removeFitExperiment(
                                               SedParameterEstimationTask_t*
                                                 spet,
                                               unsigned int n)
{
  return (spet != NULL) ? spet->removeFitExperiment(n) : NULL;
}


/*
 * Removes the SedFitExperiment_t from this SedParameterEstimationTask_t based
 * on its identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_removeFitExperimentById(
                                                   SedParameterEstimationTask_t*
                                                     spet,
                                                   const char* sid)
{
  return (spet != NULL && sid != NULL) ? spet->removeFitExperiment(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedParameterEstimationTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_hasRequiredAttributes(const
  SedParameterEstimationTask_t * spet)
{
  return (spet != NULL) ? static_cast<int>(spet->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedParameterEstimationTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_hasRequiredElements(const
  SedParameterEstimationTask_t * spet)
{
  return (spet != NULL) ? static_cast<int>(spet->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


