/**
 * @file SedDocument.cpp
 * @brief Implementation of the SedDocument class.
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
#include <sedml/SedDocument.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedUniformTimeCourse.h>
#include <sedml/SedOneStep.h>
#include <sedml/SedSteadyState.h>
#include <sedml/SedAnalysis.h>
#include <sedml/SedTask.h>
#include <sedml/SedRepeatedTask.h>
#include <sedml/SedParameterEstimationTask.h>
#include <sedml/SedReport.h>
#include <sedml/SedPlot2D.h>
#include <sedml/SedPlot3D.h>
#include <sedml/SedFigure.h>
#include <sedml/SedParameterEstimationResultPlot.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedDocument using the given SED-ML Level and @ p version
 * values.
 */
SedDocument::SedDocument(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mLevel (SEDML_INT_MAX)
  , mIsSetLevel (false)
  , mVersion (SEDML_INT_MAX)
  , mIsSetVersion (false)
  , mAlgorithmParameters (level, version)
  , mDataDescriptions (level, version)
  , mModels (level, version)
  , mSimulations (level, version)
  , mAbstractTasks (level, version)
  , mDataGenerators (level, version)
  , mOutputs (level, version)
  , mStyles (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  setLevel(level);
  setVersion(version);
  setSedDocument(this);
  connectToChild();
}


/*
 * Creates a new SedDocument using the given SedNamespaces object @p sedmlns.
 */
SedDocument::SedDocument(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mLevel (SEDML_INT_MAX)
  , mIsSetLevel (false)
  , mVersion (SEDML_INT_MAX)
  , mIsSetVersion (false)
  , mAlgorithmParameters (sedmlns)
  , mDataDescriptions (sedmlns)
  , mModels (sedmlns)
  , mSimulations (sedmlns)
  , mAbstractTasks (sedmlns)
  , mDataGenerators (sedmlns)
  , mOutputs (sedmlns)
  , mStyles (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  setLevel(sedmlns->getLevel());
  setVersion(sedmlns->getVersion());
  setSedDocument(this);
  connectToChild();
}


/*
 * Copy constructor for SedDocument.
 */
SedDocument::SedDocument(const SedDocument& orig)
  : SedBase( orig )
  , mLevel ( orig.mLevel )
  , mIsSetLevel ( orig.mIsSetLevel )
  , mVersion ( orig.mVersion )
  , mIsSetVersion ( orig.mIsSetVersion )
  , mAlgorithmParameters (orig.mAlgorithmParameters)
  , mDataDescriptions ( orig.mDataDescriptions )
  , mModels ( orig.mModels )
  , mSimulations ( orig.mSimulations )
  , mAbstractTasks ( orig.mAbstractTasks )
  , mDataGenerators ( orig.mDataGenerators )
  , mOutputs ( orig.mOutputs )
  , mStyles ( orig.mStyles )
{
  setSedDocument(this);

  connectToChild();
}


/*
 * Assignment operator for SedDocument.
 */
SedDocument&
SedDocument::operator=(const SedDocument& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mLevel = rhs.mLevel;
    mIsSetLevel = rhs.mIsSetLevel;
    mVersion = rhs.mVersion;
    mIsSetVersion = rhs.mIsSetVersion;
    mAlgorithmParameters = rhs.mAlgorithmParameters;
    mDataDescriptions = rhs.mDataDescriptions;
    mModels = rhs.mModels;
    mSimulations = rhs.mSimulations;
    mAbstractTasks = rhs.mAbstractTasks;
    mDataGenerators = rhs.mDataGenerators;
    mOutputs = rhs.mOutputs;
    mStyles = rhs.mStyles;
    connectToChild();
    setSedDocument(this);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedDocument object.
 */
SedDocument*
SedDocument::clone() const
{
  return new SedDocument(*this);
}


/*
 * Destructor for SedDocument.
 */
SedDocument::~SedDocument()
{
}


/*
 * Returns the value of the "level" attribute of this SedDocument.
 */
unsigned int
SedDocument::getLevel() const
{
  return mLevel;
}


/*
 * Returns the value of the "version" attribute of this SedDocument.
 */
unsigned int
SedDocument::getVersion() const
{
  return mVersion;
}


/*
 * Predicate returning @c true if this SedDocument's "level" attribute is set.
 */
bool
SedDocument::isSetLevel() const
{
  return mIsSetLevel;
}


/*
 * Predicate returning @c true if this SedDocument's "version" attribute is
 * set.
 */
bool
SedDocument::isSetVersion() const
{
  return mIsSetVersion;
}


/*
 * Sets the value of the "level" attribute of this SedDocument.
 */
int
SedDocument::setLevel(unsigned int level)
{
  mLevel = level;
  mIsSetLevel = true;

  if (mIsSetVersion)
  {
    setSedNamespacesAndOwn(new SedNamespaces(level, mVersion));
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "version" attribute of this SedDocument.
 */
int
SedDocument::setVersion(unsigned int version)
{
  mVersion = version;
  mIsSetVersion = true;

  if (mIsSetLevel)
  {
    setSedNamespacesAndOwn(new SedNamespaces(mLevel, version));
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "level" attribute of this SedDocument.
 */
int
SedDocument::unsetLevel()
{
  mLevel = SEDML_INT_MAX;
  mIsSetLevel = false;

  if (isSetLevel() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "version" attribute of this SedDocument.
 */
int
SedDocument::unsetVersion()
{
  mVersion = SEDML_INT_MAX;
  mIsSetVersion = false;

  if (isSetVersion() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfAlgorithmParameters from this SedDocument.
 */
const SedListOfAlgorithmParameters*
SedDocument::getListOfAlgorithmParameters() const
{
    return &mAlgorithmParameters;
}


/*
 * Returns the SedListOfAlgorithmParameters from this SedDocument.
 */
SedListOfAlgorithmParameters*
SedDocument::getListOfAlgorithmParameters()
{
    return &mAlgorithmParameters;
}


/*
 * Get a SedAlgorithmParameter from the SedDocument.
 */
SedAlgorithmParameter*
SedDocument::getAlgorithmParameter(unsigned int n)
{
    return mAlgorithmParameters.get(n);
}


/*
 * Get a SedAlgorithmParameter from the SedDocument.
 */
const SedAlgorithmParameter*
SedDocument::getAlgorithmParameter(unsigned int n) const
{
    return mAlgorithmParameters.get(n);
}


/*
 * Get a SedAlgorithmParameter from the SedDocument.
 */
SedAlgorithmParameter*
SedDocument::getAlgorithmParameter(const string& id)
{
    return mAlgorithmParameters.get(id);
}


/*
 * Get a SedAlgorithmParameter from the SedDocument.
 */
const SedAlgorithmParameter*
SedDocument::getAlgorithmParameter(const string& id) const
{
    return mAlgorithmParameters.get(id);
}


/*
 * Adds a copy of the given SedAlgorithmParameter to this SedDocument.
 */
int
SedDocument::addAlgorithmParameter(const SedAlgorithmParameter* sap)
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
    else if (getLevel() == 1 && getVersion() < 4)
    {
        return LIBSEDML_INVALID_OBJECT;
    }
    else
    {
        return mAlgorithmParameters.append(sap);
    }
}


/*
 * Get the number of SedAlgorithmParameter objects in this SedDocument.
 */
unsigned int
SedDocument::getNumAlgorithmParameters() const
{
    return mAlgorithmParameters.size();
}


/*
 * Creates a new SedAlgorithmParameter object, adds it to this SedDocument
 * object and returns the SedAlgorithmParameter object created.
 */
SedAlgorithmParameter*
SedDocument::createAlgorithmParameter()
{
    SedAlgorithmParameter* sap = NULL;
    if (getLevel() == 1 && getVersion() < 4)
    {
        return sap;
    }

    try
    {
        sap = new SedAlgorithmParameter(getSedNamespaces());
    }
    catch (...)
    {
    }

    if (sap != NULL)
    {
        mAlgorithmParameters.appendAndOwn(sap);
    }

    return sap;
}


/*
 * Removes the nth SedAlgorithmParameter from this SedDocument and returns a
 * pointer to it.
 */
SedAlgorithmParameter*
SedDocument::removeAlgorithmParameter(unsigned int n)
{
    return mAlgorithmParameters.remove(n);
}


/*
 * Removes the SedAlgorithmParameter with the given id from this SedDocument and returns a
 * pointer to it.
 */
SedAlgorithmParameter*
SedDocument::removeAlgorithmParameter(const string& id)
{
    return mAlgorithmParameters.remove(id);
}


/*
 * Returns the SedListOfDataDescriptions from this SedDocument.
 */
const SedListOfDataDescriptions*
SedDocument::getListOfDataDescriptions() const
{
  return &mDataDescriptions;
}


/*
 * Returns the SedListOfDataDescriptions from this SedDocument.
 */
SedListOfDataDescriptions*
SedDocument::getListOfDataDescriptions()
{
  return &mDataDescriptions;
}


/*
 * Get a SedDataDescription from the SedDocument.
 */
SedDataDescription*
SedDocument::getDataDescription(unsigned int n)
{
  return mDataDescriptions.get(n);
}


/*
 * Get a SedDataDescription from the SedDocument.
 */
const SedDataDescription*
SedDocument::getDataDescription(unsigned int n) const
{
  return mDataDescriptions.get(n);
}


/*
 * Get a SedDataDescription from the SedDocument based on its identifier.
 */
SedDataDescription*
SedDocument::getDataDescription(const std::string& sid)
{
  return mDataDescriptions.get(sid);
}


/*
 * Get a SedDataDescription from the SedDocument based on its identifier.
 */
const SedDataDescription*
SedDocument::getDataDescription(const std::string& sid) const
{
  return mDataDescriptions.get(sid);
}


/*
 * Adds a copy of the given SedDataDescription to this SedDocument.
 */
int
SedDocument::addDataDescription(const SedDataDescription* sdd)
{
  if (sdd == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sdd->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sdd->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sdd->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sdd)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sdd->isSetId() && (mDataDescriptions.get(sdd->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mDataDescriptions.append(sdd);
  }
}


/*
 * Get the number of SedDataDescription objects in this SedDocument.
 */
unsigned int
SedDocument::getNumDataDescriptions() const
{
  return mDataDescriptions.size();
}


/*
 * Creates a new SedDataDescription object, adds it to this SedDocument object
 * and returns the SedDataDescription object created.
 */
SedDataDescription*
SedDocument::createDataDescription()
{
  SedDataDescription* sdd = NULL;

  try
  {
    sdd = new SedDataDescription(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sdd != NULL)
  {
    mDataDescriptions.appendAndOwn(sdd);
  }

  return sdd;
}


/*
 * Removes the nth SedDataDescription from this SedDocument and returns a
 * pointer to it.
 */
SedDataDescription*
SedDocument::removeDataDescription(unsigned int n)
{
  return mDataDescriptions.remove(n);
}


/*
 * Removes the SedDataDescription from this SedDocument based on its identifier
 * and returns a pointer to it.
 */
SedDataDescription*
SedDocument::removeDataDescription(const std::string& sid)
{
  return mDataDescriptions.remove(sid);
}


/*
 * Returns the SedListOfModels from this SedDocument.
 */
const SedListOfModels*
SedDocument::getListOfModels() const
{
  return &mModels;
}


/*
 * Returns the SedListOfModels from this SedDocument.
 */
SedListOfModels*
SedDocument::getListOfModels()
{
  return &mModels;
}


/*
 * Get a SedModel from the SedDocument.
 */
SedModel*
SedDocument::getModel(unsigned int n)
{
  return mModels.get(n);
}


/*
 * Get a SedModel from the SedDocument.
 */
const SedModel*
SedDocument::getModel(unsigned int n) const
{
  return mModels.get(n);
}


/*
 * Get a SedModel from the SedDocument based on its identifier.
 */
SedModel*
SedDocument::getModel(const std::string& sid)
{
  return mModels.get(sid);
}


/*
 * Get a SedModel from the SedDocument based on its identifier.
 */
const SedModel*
SedDocument::getModel(const std::string& sid) const
{
  return mModels.get(sid);
}


/*
 * Adds a copy of the given SedModel to this SedDocument.
 */
int
SedDocument::addModel(const SedModel* sm)
{
  if (sm == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sm->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sm->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sm->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sm)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sm->isSetId() && (mModels.get(sm->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mModels.append(sm);
  }
}


/*
 * Get the number of SedModel objects in this SedDocument.
 */
unsigned int
SedDocument::getNumModels() const
{
  return mModels.size();
}


/*
 * Creates a new SedModel object, adds it to this SedDocument object and
 * returns the SedModel object created.
 */
SedModel*
SedDocument::createModel()
{
  SedModel* sm = NULL;

  try
  {
    sm = new SedModel(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sm != NULL)
  {
    mModels.appendAndOwn(sm);
  }

  return sm;
}


/*
 * Removes the nth SedModel from this SedDocument and returns a pointer to it.
 */
SedModel*
SedDocument::removeModel(unsigned int n)
{
  return mModels.remove(n);
}


/*
 * Removes the SedModel from this SedDocument based on its identifier and
 * returns a pointer to it.
 */
SedModel*
SedDocument::removeModel(const std::string& sid)
{
  return mModels.remove(sid);
}


/*
 * Returns the SedListOfSimulations from this SedDocument.
 */
const SedListOfSimulations*
SedDocument::getListOfSimulations() const
{
  return &mSimulations;
}


/*
 * Returns the SedListOfSimulations from this SedDocument.
 */
SedListOfSimulations*
SedDocument::getListOfSimulations()
{
  return &mSimulations;
}


/*
 * Get a SedSimulation from the SedDocument.
 */
SedSimulation*
SedDocument::getSimulation(unsigned int n)
{
  return mSimulations.get(n);
}


/*
 * Get a SedSimulation from the SedDocument.
 */
const SedSimulation*
SedDocument::getSimulation(unsigned int n) const
{
  return mSimulations.get(n);
}


/*
 * Get a SedSimulation from the SedDocument based on its identifier.
 */
SedSimulation*
SedDocument::getSimulation(const std::string& sid)
{
  return mSimulations.get(sid);
}


/*
 * Get a SedSimulation from the SedDocument based on its identifier.
 */
const SedSimulation*
SedDocument::getSimulation(const std::string& sid) const
{
  return mSimulations.get(sid);
}


/*
 * Adds a copy of the given SedSimulation to this SedDocument.
 */
int
SedDocument::addSimulation(const SedSimulation* ss)
{
  if (ss == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ss->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (ss->hasRequiredElements() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ss->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ss->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ss)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (ss->isSetId() && (mSimulations.get(ss->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mSimulations.append(ss);
  }
}


/*
 * Get the number of SedSimulation objects in this SedDocument.
 */
unsigned int
SedDocument::getNumSimulations() const
{
  return mSimulations.size();
}


/*
 * Creates a new SedUniformTimeCourse object, adds it to this SedDocument
 * object and returns the SedUniformTimeCourse object created.
 */
SedUniformTimeCourse*
SedDocument::createUniformTimeCourse()
{
  SedUniformTimeCourse* sutc = NULL;

  try
  {
    sutc = new SedUniformTimeCourse(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sutc != NULL)
  {
    mSimulations.appendAndOwn(sutc);
  }

  return sutc;
}


/*
 * Creates a new SedOneStep object, adds it to this SedDocument object and
 * returns the SedOneStep object created.
 */
SedOneStep*
SedDocument::createOneStep()
{
  SedOneStep* sos = NULL;

  try
  {
    sos = new SedOneStep(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sos != NULL)
  {
    mSimulations.appendAndOwn(sos);
  }

  return sos;
}


/*
 * Creates a new SedSteadyState object, adds it to this SedDocument object and
 * returns the SedSteadyState object created.
 */
SedSteadyState*
SedDocument::createSteadyState()
{
  SedSteadyState* sss = NULL;

  try
  {
    sss = new SedSteadyState(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sss != NULL)
  {
    mSimulations.appendAndOwn(sss);
  }

  return sss;
}


/*
 * Creates a new SedAnalysis object, adds it to this SedDocument object and
 * returns the SedAnalysis object created.
 */
SedAnalysis*
SedDocument::createAnalysis()
{
    SedAnalysis* sss = NULL;

    try
    {
        sss = new SedAnalysis(getSedNamespaces());
    }
    catch (...)
    {
    }

    if (sss != NULL)
    {
        mSimulations.appendAndOwn(sss);
    }

    return sss;
}


/*
 * Removes the nth SedSimulation from this SedDocument and returns a pointer to
 * it.
 */
SedSimulation*
SedDocument::removeSimulation(unsigned int n)
{
  return mSimulations.remove(n);
}


/*
 * Removes the SedSimulation from this SedDocument based on its identifier and
 * returns a pointer to it.
 */
SedSimulation*
SedDocument::removeSimulation(const std::string& sid)
{
  return mSimulations.remove(sid);
}


/*
 * Returns the SedListOfTasks from this SedDocument.
 */
const SedListOfTasks*
SedDocument::getListOfTasks() const
{
  return &mAbstractTasks;
}


/*
 * Returns the SedListOfTasks from this SedDocument.
 */
SedListOfTasks*
SedDocument::getListOfTasks()
{
  return &mAbstractTasks;
}


/*
 * Get a SedAbstractTask from the SedDocument.
 */
SedAbstractTask*
SedDocument::getTask(unsigned int n)
{
  return mAbstractTasks.get(n);
}


/*
 * Get a SedAbstractTask from the SedDocument.
 */
const SedAbstractTask*
SedDocument::getTask(unsigned int n) const
{
  return mAbstractTasks.get(n);
}


/*
 * Get a SedAbstractTask from the SedDocument based on its identifier.
 */
SedAbstractTask*
SedDocument::getTask(const std::string& sid)
{
  return mAbstractTasks.get(sid);
}


/*
 * Get a SedAbstractTask from the SedDocument based on its identifier.
 */
const SedAbstractTask*
SedDocument::getTask(const std::string& sid) const
{
  return mAbstractTasks.get(sid);
}


/*
 * Adds a copy of the given SedAbstractTask to this SedDocument.
 */
int
SedDocument::addTask(const SedAbstractTask* sat)
{
  if (sat == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sat->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sat->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sat->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sat)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sat->isSetId() && (mAbstractTasks.get(sat->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mAbstractTasks.append(sat);
  }
}


/*
 * Get the number of SedAbstractTask objects in this SedDocument.
 */
unsigned int
SedDocument::getNumTasks() const
{
  return mAbstractTasks.size();
}


/*
 * Creates a new SedTask object, adds it to this SedDocument object and returns
 * the SedTask object created.
 */
SedTask*
SedDocument::createTask()
{
  SedTask* st = NULL;

  try
  {
    st = new SedTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (st != NULL)
  {
    mAbstractTasks.appendAndOwn(st);
  }

  return st;
}


/*
 * Creates a new SedRepeatedTask object, adds it to this SedDocument object and
 * returns the SedRepeatedTask object created.
 */
SedRepeatedTask*
SedDocument::createRepeatedTask()
{
  SedRepeatedTask* srt = NULL;

  try
  {
    srt = new SedRepeatedTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (srt != NULL)
  {
    mAbstractTasks.appendAndOwn(srt);
  }

  return srt;
}


/*
 * Creates a new SedParameterEstimationTask object, adds it to this SedDocument
 * object and returns the SedParameterEstimationTask object created.
 */
SedParameterEstimationTask*
SedDocument::createParameterEstimationTask()
{
  SedParameterEstimationTask* spet = NULL;

  try
  {
    spet = new SedParameterEstimationTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (spet != NULL)
  {
    mAbstractTasks.appendAndOwn(spet);
  }

  return spet;
}


/*
 * Removes the nth SedAbstractTask from this SedDocument and returns a pointer
 * to it.
 */
SedAbstractTask*
SedDocument::removeTask(unsigned int n)
{
  return mAbstractTasks.remove(n);
}


/*
 * Removes the SedAbstractTask from this SedDocument based on its identifier
 * and returns a pointer to it.
 */
SedAbstractTask*
SedDocument::removeTask(const std::string& sid)
{
  return mAbstractTasks.remove(sid);
}


/*
 * Returns the SedListOfDataGenerators from this SedDocument.
 */
const SedListOfDataGenerators*
SedDocument::getListOfDataGenerators() const
{
  return &mDataGenerators;
}


/*
 * Returns the SedListOfDataGenerators from this SedDocument.
 */
SedListOfDataGenerators*
SedDocument::getListOfDataGenerators()
{
  return &mDataGenerators;
}


/*
 * Get a SedDataGenerator from the SedDocument.
 */
SedDataGenerator*
SedDocument::getDataGenerator(unsigned int n)
{
  return mDataGenerators.get(n);
}


/*
 * Get a SedDataGenerator from the SedDocument.
 */
const SedDataGenerator*
SedDocument::getDataGenerator(unsigned int n) const
{
  return mDataGenerators.get(n);
}


/*
 * Get a SedDataGenerator from the SedDocument based on its identifier.
 */
SedDataGenerator*
SedDocument::getDataGenerator(const std::string& sid)
{
  return mDataGenerators.get(sid);
}


/*
 * Get a SedDataGenerator from the SedDocument based on its identifier.
 */
const SedDataGenerator*
SedDocument::getDataGenerator(const std::string& sid) const
{
  return mDataGenerators.get(sid);
}


/*
 * Adds a copy of the given SedDataGenerator to this SedDocument.
 */
int
SedDocument::addDataGenerator(const SedDataGenerator* sdg)
{
  if (sdg == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sdg->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (sdg->hasRequiredElements() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sdg->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sdg->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sdg)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sdg->isSetId() && (mDataGenerators.get(sdg->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mDataGenerators.append(sdg);
  }
}


/*
 * Get the number of SedDataGenerator objects in this SedDocument.
 */
unsigned int
SedDocument::getNumDataGenerators() const
{
  return mDataGenerators.size();
}


/*
 * Creates a new SedDataGenerator object, adds it to this SedDocument object
 * and returns the SedDataGenerator object created.
 */
SedDataGenerator*
SedDocument::createDataGenerator()
{
  SedDataGenerator* sdg = NULL;

  try
  {
    sdg = new SedDataGenerator(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sdg != NULL)
  {
    mDataGenerators.appendAndOwn(sdg);
  }

  return sdg;
}


/*
 * Removes the nth SedDataGenerator from this SedDocument and returns a pointer
 * to it.
 */
SedDataGenerator*
SedDocument::removeDataGenerator(unsigned int n)
{
  return mDataGenerators.remove(n);
}


/*
 * Removes the SedDataGenerator from this SedDocument based on its identifier
 * and returns a pointer to it.
 */
SedDataGenerator*
SedDocument::removeDataGenerator(const std::string& sid)
{
  return mDataGenerators.remove(sid);
}


/*
 * Returns the SedListOfOutputs from this SedDocument.
 */
const SedListOfOutputs*
SedDocument::getListOfOutputs() const
{
  return &mOutputs;
}


/*
 * Returns the SedListOfOutputs from this SedDocument.
 */
SedListOfOutputs*
SedDocument::getListOfOutputs()
{
  return &mOutputs;
}


/*
 * Get a SedOutput from the SedDocument.
 */
SedOutput*
SedDocument::getOutput(unsigned int n)
{
  return mOutputs.get(n);
}


/*
 * Get a SedOutput from the SedDocument.
 */
const SedOutput*
SedDocument::getOutput(unsigned int n) const
{
  return mOutputs.get(n);
}


/*
 * Get a SedOutput from the SedDocument based on its identifier.
 */
SedOutput*
SedDocument::getOutput(const std::string& sid)
{
  return mOutputs.get(sid);
}


/*
 * Get a SedOutput from the SedDocument based on its identifier.
 */
const SedOutput*
SedDocument::getOutput(const std::string& sid) const
{
  return mOutputs.get(sid);
}


/*
 * Adds a copy of the given SedOutput to this SedDocument.
 */
int
SedDocument::addOutput(const SedOutput* so)
{
  if (so == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (so->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != so->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != so->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(so)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (so->isSetId() && (mOutputs.get(so->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mOutputs.append(so);
  }
}


/*
 * Get the number of SedOutput objects in this SedDocument.
 */
unsigned int
SedDocument::getNumOutputs() const
{
  return mOutputs.size();
}


/*
 * Creates a new SedReport object, adds it to this SedDocument object and
 * returns the SedReport object created.
 */
SedReport*
SedDocument::createReport()
{
  SedReport* sr = NULL;

  try
  {
    sr = new SedReport(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sr != NULL)
  {
    mOutputs.appendAndOwn(sr);
  }

  return sr;
}


/*
 * Creates a new SedPlot2D object, adds it to this SedDocument object and
 * returns the SedPlot2D object created.
 */
SedPlot2D*
SedDocument::createPlot2D()
{
  SedPlot2D* spd = NULL;

  try
  {
    spd = new SedPlot2D(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (spd != NULL)
  {
    mOutputs.appendAndOwn(spd);
  }

  return spd;
}


/*
 * Creates a new SedPlot3D object, adds it to this SedDocument object and
 * returns the SedPlot3D object created.
 */
SedPlot3D*
SedDocument::createPlot3D()
{
  SedPlot3D* spd = NULL;

  try
  {
    spd = new SedPlot3D(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (spd != NULL)
  {
    mOutputs.appendAndOwn(spd);
  }

  return spd;
}


/*
 * Creates a new SedFigure object, adds it to this SedDocument object and
 * returns the SedFigure object created.
 */
SedFigure*
SedDocument::createFigure()
{
  SedFigure* sf = NULL;

  try
  {
    sf = new SedFigure(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sf != NULL)
  {
    mOutputs.appendAndOwn(sf);
  }

  return sf;
}


/*
 * Creates a new SedParameterEstimationResultPlot object, adds it to this
 * SedDocument object and returns the SedParameterEstimationResultPlot object
 * created.
 */
SedParameterEstimationResultPlot*
SedDocument::createParameterEstimationResultPlot()
{
  SedParameterEstimationResultPlot* sperp = NULL;

  try
  {
    sperp = new SedParameterEstimationResultPlot(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sperp != NULL)
  {
    mOutputs.appendAndOwn(sperp);
  }

  return sperp;
}


/*
 * Removes the nth SedOutput from this SedDocument and returns a pointer to it.
 */
SedOutput*
SedDocument::removeOutput(unsigned int n)
{
  return mOutputs.remove(n);
}


/*
 * Removes the SedOutput from this SedDocument based on its identifier and
 * returns a pointer to it.
 */
SedOutput*
SedDocument::removeOutput(const std::string& sid)
{
  return mOutputs.remove(sid);
}


/*
 * Returns the SedListOfStyles from this SedDocument.
 */
const SedListOfStyles*
SedDocument::getListOfStyles() const
{
  return &mStyles;
}


/*
 * Returns the SedListOfStyles from this SedDocument.
 */
SedListOfStyles*
SedDocument::getListOfStyles()
{
  return &mStyles;
}


/*
 * Get a SedStyle from the SedDocument.
 */
SedStyle*
SedDocument::getStyle(unsigned int n)
{
  return mStyles.get(n);
}


/*
 * Get a SedStyle from the SedDocument.
 */
const SedStyle*
SedDocument::getStyle(unsigned int n) const
{
  return mStyles.get(n);
}


/*
 * Get a SedStyle from the SedDocument based on its identifier.
 */
SedStyle*
SedDocument::getStyle(const std::string& sid)
{
  return mStyles.get(sid);
}


/*
 * Get a SedStyle from the SedDocument based on its identifier.
 */
const SedStyle*
SedDocument::getStyle(const std::string& sid) const
{
  return mStyles.get(sid);
}


/*
 * Get a SedStyle from the SedDocument based on its identifier.
 */
SedStyle
SedDocument::getEffectiveStyle(const std::string& sid) const
{
    const SedStyle* top =  mStyles.get(sid);
    if (top == NULL)
    {
        return SedStyle(mLevel, mVersion);
    }
    if (!top->isSetBaseStyle())
    {
        return SedStyle(*top);
    }
    SedStyle base = getEffectiveStyle(top->getBaseStyle());
    base.setId(top->getId());
    base.setName(top->getName());
    base.unsetBaseStyle();

    if (top->isSetLineStyle())
    {
        if (base.isSetLineStyle())
        {
            const SedLine* topline = top->getLineStyle();
            SedLine* baseline = base.getLineStyle();

            if (topline->isSetColor())
            {
                baseline->setColor(topline->getColor());
            }

            if (topline->isSetType())
            {
                baseline->setType(topline->getType());
            }

            if (topline->isSetThickness())
            {
                baseline->setThickness(topline->getThickness());
            }
        }
        else
        {
            base.setLineStyle(top->getLineStyle());
        }
    }

    if (top->isSetMarkerStyle())
    {
        if (base.isSetMarkerStyle())
        {
            const SedMarker* topmarker = top->getMarkerStyle();
            SedMarker* basemarker = base.getMarkerStyle();

            if (topmarker->isSetType())
            {
                basemarker->setType(topmarker->getType());
            }

            if (topmarker->isSetSize())
            {
                basemarker->setSize(topmarker->getSize());
            }

            if (topmarker->isSetFill())
            {
                basemarker->setFill(topmarker->getFill());
            }

            if (topmarker->isSetLineColor())
            {
                basemarker->setLineColor(topmarker->getLineColor());
            }

            if (topmarker->isSetLineThickness())
            {
                basemarker->setLineThickness(topmarker->getLineThickness());
            }
        }
        else
        {
            base.setMarkerStyle(top->getMarkerStyle());
        }
    }

    if (top->isSetFillStyle())
    {
        if (base.isSetFillStyle())
        {
            const SedFill* topfill = top->getFillStyle();
            SedFill* basefill = base.getFillStyle();

            if (topfill->isSetColor())
            {
                basefill->setColor(topfill->getColor());
            }

            //if (topfill->isSetSecondColor())
            //{
            //    basefill->setSecondColor(topfill->getSecondColor());
            //}
        }
        else
        {
            base.setFillStyle(top->getFillStyle());
        }
    }
    return base;
}


/*
 * Get a SedStyle from the SedDocument based on the BaseStyle to which it
 * refers.
 */
const SedStyle*
SedDocument::getStyleByBaseStyle(const std::string& sid) const
{
  return mStyles.getByBaseStyle(sid);
}


/*
 * Get a SedStyle from the SedDocument based on the BaseStyle to which it
 * refers.
 */
SedStyle*
SedDocument::getStyleByBaseStyle(const std::string& sid)
{
  return mStyles.getByBaseStyle(sid);
}


/*
 * Adds a copy of the given SedStyle to this SedDocument.
 */
int
SedDocument::addStyle(const SedStyle* ss)
{
  if (ss == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ss->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ss->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ss->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ss)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (ss->isSetId() && (mStyles.get(ss->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mStyles.append(ss);
  }
}


/*
 * Get the number of SedStyle objects in this SedDocument.
 */
unsigned int
SedDocument::getNumStyles() const
{
  return mStyles.size();
}


/*
 * Creates a new SedStyle object, adds it to this SedDocument object and
 * returns the SedStyle object created.
 */
SedStyle*
SedDocument::createStyle()
{
  SedStyle* ss = NULL;

  try
  {
    ss = new SedStyle(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ss != NULL)
  {
    mStyles.appendAndOwn(ss);
  }

  return ss;
}


/*
 * Removes the nth SedStyle from this SedDocument and returns a pointer to it.
 */
SedStyle*
SedDocument::removeStyle(unsigned int n)
{
  return mStyles.remove(n);
}


/*
 * Removes the SedStyle from this SedDocument based on its identifier and
 * returns a pointer to it.
 */
SedStyle*
SedDocument::removeStyle(const std::string& sid)
{
  return mStyles.remove(sid);
}


/*
 * Returns the XML element name of this SedDocument object.
 */
const std::string&
SedDocument::getElementName() const
{
  static const string name = "sedML";
  return name;
}


/*
 * Returns the libSEDML type code for this SedDocument object.
 */
int
SedDocument::getTypeCode() const
{
  return SEDML_DOCUMENT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedDocument object have been set.
 */
bool
SedDocument::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetLevel() == false)
  {
    allPresent = false;
  }

  if (isSetVersion() == false)
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
SedDocument::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (getNumAlgorithmParameters() > 0 && (getLevel() > 1 || getVersion() >= 4))
  {
    mAlgorithmParameters.write(stream);
  }

  if (getNumDataDescriptions() > 0)
  {
    mDataDescriptions.write(stream);
  }

  if (getNumModels() > 0)
  {
    mModels.write(stream);
  }

  if (getNumSimulations() > 0)
  {
    mSimulations.write(stream);
  }

  if (getNumTasks() > 0)
  {
    mAbstractTasks.write(stream);
  }

  if (getNumDataGenerators() > 0)
  {
    mDataGenerators.write(stream);
  }

  if (getNumOutputs() > 0)
  {
    mOutputs.write(stream);
  }

  if (getNumStyles() > 0)
  {
    mStyles.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedDocument::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedDocument::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mAlgorithmParameters.setSedDocument(d);

  mDataDescriptions.setSedDocument(d);

  mModels.setSedDocument(d);

  mSimulations.setSedDocument(d);

  mAbstractTasks.setSedDocument(d);

  mDataGenerators.setSedDocument(d);

  mOutputs.setSedDocument(d);

  mStyles.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedDocument::connectToChild()
{
  SedBase::connectToChild();

  mAlgorithmParameters.connectToParent(this);

  mDataDescriptions.connectToParent(this);

  mModels.connectToParent(this);

  mSimulations.connectToParent(this);

  mAbstractTasks.connectToParent(this);

  mDataGenerators.connectToParent(this);

  mOutputs.connectToParent(this);

  mStyles.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "level")
  {
    value = getLevel();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "version")
  {
    value = getVersion();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedDocument's attribute "attributeName"
 * is set.
 */
bool
SedDocument::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "level")
  {
    value = isSetLevel();
  }
  else if (attributeName == "version")
  {
    value = isSetVersion();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "level")
  {
    return_value = setLevel(value);
  }
  else if (attributeName == "version")
  {
    return_value = setVersion(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedDocument.
 */
int
SedDocument::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "level")
  {
    value = unsetLevel();
  }
  else if (attributeName == "version")
  {
    value = unsetVersion();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedDocument.
 */
SedBase*
SedDocument::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "algorithmParameter")
  {
    return createAlgorithmParameter();
  }

  if (elementName == "dataDescription")
  {
    return createDataDescription();
  }
  else if (elementName == "model")
  {
    return createModel();
  }
  else if (elementName == "uniformTimeCourse")
  {
    return createUniformTimeCourse();
  }
  else if (elementName == "oneStep")
  {
    return createOneStep();
  }
  else if (elementName == "steadyState")
  {
    return createSteadyState();
  }
  else if (elementName == "analysis")
  {
      return createAnalysis();
  }
  else if (elementName == "task")
  {
    return createTask();
  }
  else if (elementName == "repeatedTask")
  {
    return createRepeatedTask();
  }
  else if (elementName == "parameterEstimationTask")
  {
    return createParameterEstimationTask();
  }
  else if (elementName == "dataGenerator")
  {
    return createDataGenerator();
  }
  else if (elementName == "report")
  {
    return createReport();
  }
  else if (elementName == "plot2D")
  {
    return createPlot2D();
  }
  else if (elementName == "plot3D")
  {
    return createPlot3D();
  }
  else if (elementName == "figure")
  {
    return createFigure();
  }
  else if (elementName == "parameterEstimationResultPlot")
  {
    return createParameterEstimationResultPlot();
  }
  else if (elementName == "style")
  {
    return createStyle();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedDocument.
 */
int
SedDocument::addChildObject(const std::string& elementName,
                            const SedBase* element)
{
  if (elementName == "algorithmParameter" && element->getTypeCode() ==
    SEDML_SIMULATION_ALGORITHM_PARAMETER)
  {
    return addAlgorithmParameter((const SedAlgorithmParameter*)(element));
  }
  else if (elementName == "dataDescription" && element->getTypeCode() ==
    SEDML_DATA_DESCRIPTION)
  {
    return addDataDescription((const SedDataDescription*)(element));
  }
  else if (elementName == "model" && element->getTypeCode() == SEDML_MODEL)
  {
    return addModel((const SedModel*)(element));
  }
  else if (elementName == "uniformTimeCourse" && element->getTypeCode() ==
    SEDML_SIMULATION_UNIFORMTIMECOURSE)
  {
    return addSimulation((const SedSimulation*)(element));
  }
  else if (elementName == "oneStep" && element->getTypeCode() ==
    SEDML_SIMULATION_ONESTEP)
  {
    return addSimulation((const SedSimulation*)(element));
  }
  else if (elementName == "steadyState" && element->getTypeCode() ==
    SEDML_SIMULATION_STEADYSTATE)
  {
    return addSimulation((const SedSimulation*)(element));
  }
  else if (elementName == "analysis" && element->getTypeCode() ==
      SEDML_SIMULATION_ANALYSIS)
  {
      return addSimulation((const SedSimulation*)(element));
  }
  else if (elementName == "task" && element->getTypeCode() == SEDML_TASK)
  {
    return addTask((const SedAbstractTask*)(element));
  }
  else if (elementName == "repeatedTask" && element->getTypeCode() ==
    SEDML_TASK_REPEATEDTASK)
  {
    return addTask((const SedAbstractTask*)(element));
  }
  else if (elementName == "parameterEstimationTask" && element->getTypeCode()
    == SEDML_TASK_PARAMETER_ESTIMATION)
  {
    return addTask((const SedAbstractTask*)(element));
  }
  else if (elementName == "dataGenerator" && element->getTypeCode() ==
    SEDML_DATAGENERATOR)
  {
    return addDataGenerator((const SedDataGenerator*)(element));
  }
  else if (elementName == "report" && element->getTypeCode() ==
    SEDML_OUTPUT_REPORT)
  {
    return addOutput((const SedOutput*)(element));
  }
  else if (elementName == "plot2D" && element->getTypeCode() ==
    SEDML_OUTPUT_PLOT2D)
  {
    return addOutput((const SedOutput*)(element));
  }
  else if (elementName == "plot3D" && element->getTypeCode() ==
    SEDML_OUTPUT_PLOT3D)
  {
    return addOutput((const SedOutput*)(element));
  }
  else if (elementName == "figure" && element->getTypeCode() == SEDML_FIGURE)
  {
    return addOutput((const SedOutput*)(element));
  }
  else if (elementName == "parameterEstimationResultPlot" &&
    element->getTypeCode() == SEDML_PARAMETERESTIMATIONRESULTPLOT)
  {
    return addOutput((const SedOutput*)(element));
  }
  else if (elementName == "style" && element->getTypeCode() == SEDML_STYLE)
  {
    return addStyle((const SedStyle*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedDocument.
 */
SedBase*
SedDocument::removeChildObject(const std::string& elementName,
                               const std::string& id)
{
  if (elementName == "algorithmParameter")
  {
    return removeAlgorithmParameter(id);
  }
  if (elementName == "dataDescription")
  {
    return removeDataDescription(id);
  }
  else if (elementName == "model")
  {
    return removeModel(id);
  }
  else if (elementName == "uniformTimeCourse")
  {
    return removeSimulation(id);
  }
  else if (elementName == "oneStep")
  {
    return removeSimulation(id);
  }
  else if (elementName == "steadyState")
  {
    return removeSimulation(id);
  }
  else if (elementName == "analysis")
  {
      return removeSimulation(id);
  }
  else if (elementName == "task")
  {
    return removeTask(id);
  }
  else if (elementName == "repeatedTask")
  {
    return removeTask(id);
  }
  else if (elementName == "parameterEstimationTask")
  {
    return removeTask(id);
  }
  else if (elementName == "dataGenerator")
  {
    return removeDataGenerator(id);
  }
  else if (elementName == "report")
  {
    return removeOutput(id);
  }
  else if (elementName == "plot2D")
  {
    return removeOutput(id);
  }
  else if (elementName == "plot3D")
  {
    return removeOutput(id);
  }
  else if (elementName == "figure")
  {
    return removeOutput(id);
  }
  else if (elementName == "parameterEstimationResultPlot")
  {
    return removeOutput(id);
  }
  else if (elementName == "style")
  {
    return removeStyle(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedDocument.
 */
unsigned int
SedDocument::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "algorithmParameter")
  {
    return getNumAlgorithmParameters();
  }
  else if (elementName == "dataDescription")
  {
      return getNumDataDescriptions();
  }
  else if (elementName == "model")
  {
    return getNumModels();
  }
  else if (elementName == "simulation")
  {
    return getNumSimulations();
  }
  else if (elementName == "task")
  {
    return getNumTasks();
  }
  else if (elementName == "dataGenerator")
  {
    return getNumDataGenerators();
  }
  else if (elementName == "output")
  {
    return getNumOutputs();
  }
  else if (elementName == "style")
  {
    return getNumStyles();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedDocument.
 */
SedBase*
SedDocument::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "algorithmParameter")
  {
    return getAlgorithmParameter(index);
  }
  else if (elementName == "dataDescription")
  {
    return getDataDescription(index);
  }
  else if (elementName == "model")
  {
    return getModel(index);
  }
  else if (elementName == "simulation")
  {
    return getSimulation(index);
  }
  else if (elementName == "task")
  {
    return getTask(index);
  }
  else if (elementName == "dataGenerator")
  {
    return getDataGenerator(index);
  }
  else if (elementName == "output")
  {
    return getOutput(index);
  }
  else if (elementName == "style")
  {
    return getStyle(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedDocument::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mAlgorithmParameters.getElementBySId(id);

  if (obj != NULL)
  {
      return obj;
  }

  obj = mDataDescriptions.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mModels.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mSimulations.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mAbstractTasks.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mDataGenerators.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mOutputs.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mStyles.getElementBySId(id);

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
SedDocument::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mAlgorithmParameters, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mDataDescriptions, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mModels, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mSimulations, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mAbstractTasks, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mDataGenerators, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mOutputs, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mStyles, filter);

  return ret;
}


/*
 * Returns the value of the "Namespaces" element of this SedDocument.
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SedDocument::getNamespaces() const
{
  return mSedNamespaces->getNamespaces();
}


/*
 * Returns the value of the "Namespaces" element of this SedDocument.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SedDocument::getNamespaces()
{
  return mSedNamespaces->getNamespaces();
}


/*
 * Returns the value of the "SedErrorLog" element of this SedDocument.
 */
const SedErrorLog*
SedDocument::getErrorLog() const
{
  return &mErrorLog;
}


/*
 * Returns the value of the "SedErrorLog" element of this SedDocument.
 */
SedErrorLog*
SedDocument::getErrorLog()
{
  return &mErrorLog;
}


/*
 * Get a SedError from the SedDocument.
 */
SedError*
SedDocument::getError(unsigned int n)
{
  return const_cast<SedError*>(mErrorLog.getError(n));
}


/*
 * Get a SedError from the SedDocument.
 */
const SedError*
SedDocument::getError(unsigned int n) const
{
  return mErrorLog.getError(n);
}


/*
 * Get the number of SedError objects in this SedDocument.
 */
unsigned int
SedDocument::getNumErrors() const
{
  return mErrorLog.getNumErrors();
}


/*
 * Get the number of SedError objects in this SedDocument with the given
 * severity.
 */
unsigned int
SedDocument::getNumErrors(unsigned int severity) const
{
  return getErrorLog()->getNumFailsWithSeverity(severity);
}

void SedDocument::sortOrderedObjects()
{
    for (unsigned int o = 0; o < mOutputs.size(); o++)
    {
        SedOutput* output = mOutputs.get(o);
        int type = output->getTypeCode();
        if (type == SEDML_OUTPUT_PLOT2D) 
        {
            SedPlot2D* sp2d = static_cast<SedPlot2D*>(output);
            sp2d->getListOfCurves()->sort();
        }
        else if (type == SEDML_OUTPUT_PLOT3D) 
        {
            SedPlot3D* sp3d = static_cast<SedPlot3D*>(output);
            sp3d->getListOfSurfaces()->sort();
        }
    }
    for (unsigned int t = 0; t < mAbstractTasks.size(); t++)
    {
        SedAbstractTask* task = mAbstractTasks.get(t);
        int type = task->getTypeCode();
        if (type == SEDML_TASK_REPEATEDTASK)
        {
            SedRepeatedTask* rtask = static_cast<SedRepeatedTask*>(task);
            rtask->getListOfSubTasks()->sort();
        }
    }
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedDocument::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfAlgorithmParameters")
  {
      if (getErrorLog() && mAlgorithmParameters.size() != 0)
      {
          getErrorLog()->logError(SedmlAlgorithmAllowedElements, getLevel(),
              getVersion(), "", getLine(), getColumn());
      }

      obj = &mAlgorithmParameters;
  }
  else if (name == "listOfDataDescriptions")
  {
    if (getErrorLog() && mDataDescriptions.size() != 0)
    {
      getErrorLog()->logError(SedmlDocumentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mDataDescriptions;
  }
  else if (name == "listOfModels")
  {
    if (getErrorLog() && mModels.size() != 0)
    {
      getErrorLog()->logError(SedmlDocumentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mModels;
  }
  else if (name == "listOfSimulations")
  {
    if (getErrorLog() && mSimulations.size() != 0)
    {
      getErrorLog()->logError(SedmlDocumentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mSimulations;
  }
  else if (name == "listOfTasks")
  {
    if (getErrorLog() && mAbstractTasks.size() != 0)
    {
      getErrorLog()->logError(SedmlDocumentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mAbstractTasks;
  }
  else if (name == "listOfDataGenerators")
  {
    if (getErrorLog() && mDataGenerators.size() != 0)
    {
      getErrorLog()->logError(SedmlDocumentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mDataGenerators;
  }
  else if (name == "listOfOutputs")
  {
    if (getErrorLog() && mOutputs.size() != 0)
    {
      getErrorLog()->logError(SedmlDocumentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mOutputs;
  }
  else if (name == "listOfStyles")
  {
    if (getErrorLog() && mStyles.size() != 0)
    {
      getErrorLog()->logError(SedmlDocumentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mStyles;
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
SedDocument::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("level");

  attributes.add("version");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedDocument::readAttributes(
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
        log->logError(SedmlDocumentAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  //
  // level uint (use = "required" )
  //

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLevel = attributes.readInto("level", mLevel);

  if ( mIsSetLevel == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'level' from the <SedDocument> "
        "element must be an integer.";
      log->logError(SedmlDocumentLevelMustBeNonNegativeInteger, level, version,
        message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'level' is missing from the "
        "<SedDocument> element.";
      log->logError(SedmlDocumentAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  //
  // version uint (use = "required" )
  //

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetVersion = attributes.readInto("version", mVersion);

  if ( mIsSetVersion == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'version' from the <SedDocument> "
        "element must be an integer.";
      log->logError(SedmlDocumentVersionMustBeNonNegativeInteger, level,
        version, message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'version' is missing from the "
        "<SedDocument> element.";
      log->logError(SedmlDocumentAllowedAttributes, level, version, message,
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
SedDocument::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetLevel() == true)
  {
    stream.writeAttribute("level", getPrefix(), mLevel);
  }

  if (isSetVersion() == true)
  {
    stream.writeAttribute("version", getPrefix(), mVersion);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the namespace for the Sedml package
 */
void
SedDocument::writeXMLNS(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
 // need to check that we have indeed a namespace set!
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces * thisNs =
    const_cast<LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *>(getNamespaces());

  // the SED-ML namespace is missing - add it
  if (thisNs == NULL)
    {
      XMLNamespaces xmlns;

      if (getVersion() == 1)
        xmlns.add(SEDML_XMLNS_L1V1);
      else if (getVersion() == 2)
        xmlns.add(SEDML_XMLNS_L1V2);
      else if (getVersion() == 3)
        xmlns.add(SEDML_XMLNS_L1V3);
      else
        xmlns.add(SEDML_XMLNS_L1V4);

      mSedNamespaces->setNamespaces(&xmlns);
      thisNs =  const_cast<LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *>(getNamespaces());
    }
  else if (thisNs->getLength() == 0)
    {
      if (getVersion() == 1)
        thisNs->add(SEDML_XMLNS_L1V1);
      else if (getVersion() == 2)
        thisNs->add(SEDML_XMLNS_L1V2);
      else if (getVersion() == 3)
        thisNs->add(SEDML_XMLNS_L1V3);
      else
        thisNs->add(SEDML_XMLNS_L1V4);
    }
  else
    {
      // check that there is an SED-ML namespace
      std::string sedmlURI = SedNamespaces::getSedNamespaceURI(getLevel(), getVersion());
      std::string sedmlPrefix = thisNs->getPrefix(sedmlURI);

      if (thisNs->hasNS(sedmlURI, sedmlPrefix) == false)
        {
          // the SED-ML ns is not present
          std::string other = thisNs->getURI(sedmlPrefix);

          if (other.empty() == false)
            {
              // there is another ns with the prefix that the SED-ML ns expects to have
              //remove the this ns, add the sbml ns and
              //add the new ns with a new prefix
              thisNs->remove(sedmlPrefix);
              thisNs->add(sedmlURI, sedmlPrefix);
              thisNs->add(other, "addedPrefix");
            }
          else
            {
              thisNs->add(sedmlURI, sedmlPrefix);
            }
        }
    }

  XMLNamespaces * xmlns = thisNs->clone();

  if (xmlns != NULL)
    {
      stream << *(xmlns);
      delete xmlns;
    }

}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDocument_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedDocument_t *
SedDocument_create(unsigned int level, unsigned int version)
{
  return new SedDocument(level, version);
}


/*
 * Creates and returns a deep copy of this SedDocument_t object.
 */
LIBSEDML_EXTERN
SedDocument_t*
SedDocument_clone(const SedDocument_t* sd)
{
  if (sd != NULL)
  {
    return static_cast<SedDocument_t*>(sd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedDocument_t object.
 */
LIBSEDML_EXTERN
void
SedDocument_free(SedDocument_t* sd)
{
  if (sd != NULL)
  {
    delete sd;
  }
}


/*
 * Returns the value of the "level" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getLevel(const SedDocument_t * sd)
{
  return (sd != NULL) ? sd->getLevel() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "version" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getVersion(const SedDocument_t * sd)
{
  return (sd != NULL) ? sd->getVersion() : SEDML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this SedDocument_t's "level" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedDocument_isSetLevel(const SedDocument_t * sd)
{
  return (sd != NULL) ? static_cast<int>(sd->isSetLevel()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDocument_t's "version" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedDocument_isSetVersion(const SedDocument_t * sd)
{
  return (sd != NULL) ? static_cast<int>(sd->isSetVersion()) : 0;
}


/*
 * Sets the value of the "level" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_setLevel(SedDocument_t * sd, unsigned int level)
{
  return (sd != NULL) ? sd->setLevel(level) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "version" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_setVersion(SedDocument_t * sd, unsigned int version)
{
  return (sd != NULL) ? sd->setVersion(version) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "level" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_unsetLevel(SedDocument_t * sd)
{
  return (sd != NULL) ? sd->unsetLevel() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "version" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_unsetVersion(SedDocument_t * sd)
{
  return (sd != NULL) ? sd->unsetVersion() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedDataDescription_t objects from this
 * SedDocument_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfDataDescriptions(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfDataDescriptions() : NULL;
}


/*
 * Get a SedDataDescription_t from the SedDocument_t.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_getDataDescription(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getDataDescription(n) : NULL;
}


/*
 * Get a SedDataDescription_t from the SedDocument_t based on its identifier.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_getDataDescriptionById(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getDataDescription(sid) : NULL;
}


/*
 * Adds a copy of the given SedDataDescription_t to this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_addDataDescription(SedDocument_t* sd,
                               const SedDataDescription_t* sdd)
{
  return (sd != NULL) ? sd->addDataDescription(sdd) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedDataDescription_t objects in this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumDataDescriptions(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumDataDescriptions() : SEDML_INT_MAX;
}


/*
 * Creates a new SedDataDescription_t object, adds it to this SedDocument_t
 * object and returns the SedDataDescription_t object created.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_createDataDescription(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createDataDescription() : NULL;
}


/*
 * Removes the nth SedDataDescription_t from this SedDocument_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_removeDataDescription(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeDataDescription(n) : NULL;
}


/*
 * Removes the SedDataDescription_t from this SedDocument_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_removeDataDescriptionById(SedDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeDataDescription(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedModel_t objects from this SedDocument_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfModels(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfModels() : NULL;
}


/*
 * Get a SedModel_t from the SedDocument_t.
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_getModel(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getModel(n) : NULL;
}


/*
 * Get a SedModel_t from the SedDocument_t based on its identifier.
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_getModelById(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getModel(sid) : NULL;
}


/*
 * Adds a copy of the given SedModel_t to this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_addModel(SedDocument_t* sd, const SedModel_t* sm)
{
  return (sd != NULL) ? sd->addModel(sm) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedModel_t objects in this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumModels(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumModels() : SEDML_INT_MAX;
}


/*
 * Creates a new SedModel_t object, adds it to this SedDocument_t object and
 * returns the SedModel_t object created.
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_createModel(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createModel() : NULL;
}


/*
 * Removes the nth SedModel_t from this SedDocument_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_removeModel(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeModel(n) : NULL;
}


/*
 * Removes the SedModel_t from this SedDocument_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_removeModelById(SedDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeModel(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedSimulation_t objects from this
 * SedDocument_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfSimulations(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfSimulations() : NULL;
}


/*
 * Get a SedSimulation_t from the SedDocument_t.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedDocument_getSimulation(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getSimulation(n) : NULL;
}


/*
 * Get a SedSimulation_t from the SedDocument_t based on its identifier.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedDocument_getSimulationById(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getSimulation(sid) : NULL;
}


/*
 * Adds a copy of the given SedSimulation_t to this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_addSimulation(SedDocument_t* sd, const SedSimulation_t* ss)
{
  return (sd != NULL) ? sd->addSimulation(ss) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedSimulation_t objects in this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumSimulations(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumSimulations() : SEDML_INT_MAX;
}


/*
 * Creates a new SedUniformTimeCourse_t object, adds it to this SedDocument_t
 * object and returns the SedUniformTimeCourse_t object created.
 */
LIBSEDML_EXTERN
SedUniformTimeCourse_t*
SedDocument_createUniformTimeCourse(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createUniformTimeCourse() : NULL;
}


/*
 * Creates a new SedOneStep_t object, adds it to this SedDocument_t object and
 * returns the SedOneStep_t object created.
 */
LIBSEDML_EXTERN
SedOneStep_t*
SedDocument_createOneStep(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createOneStep() : NULL;
}


/*
 * Creates a new SedSteadyState_t object, adds it to this SedDocument_t object
 * and returns the SedSteadyState_t object created.
 */
LIBSEDML_EXTERN
SedSteadyState_t*
SedDocument_createSteadyState(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createSteadyState() : NULL;
}


/*
 * Creates a new SedAnalysis_t object, adds it to this SedDocument_t object
 * and returns the SedAnalysis_t object created.
 */
LIBSEDML_EXTERN
SedAnalysis_t*
SedDocument_createAnalysis(SedDocument_t* sd)
{
    return (sd != NULL) ? sd->createAnalysis() : NULL;
}


/*
 * Removes the nth SedSimulation_t from this SedDocument_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedDocument_removeSimulation(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeSimulation(n) : NULL;
}


/*
 * Removes the SedSimulation_t from this SedDocument_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedDocument_removeSimulationById(SedDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeSimulation(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedAbstractTask_t objects from this
 * SedDocument_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfTasks(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfTasks() : NULL;
}


/*
 * Get a SedAbstractTask_t from the SedDocument_t.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedDocument_getTask(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getTask(n) : NULL;
}


/*
 * Get a SedAbstractTask_t from the SedDocument_t based on its identifier.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedDocument_getTaskById(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getTask(sid) : NULL;
}


/*
 * Adds a copy of the given SedAbstractTask_t to this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_addTask(SedDocument_t* sd, const SedAbstractTask_t* sat)
{
  return (sd != NULL) ? sd->addTask(sat) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedAbstractTask_t objects in this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumTasks(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumTasks() : SEDML_INT_MAX;
}


/*
 * Creates a new SedTask_t object, adds it to this SedDocument_t object and
 * returns the SedTask_t object created.
 */
LIBSEDML_EXTERN
SedTask_t*
SedDocument_createTask(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createTask() : NULL;
}


/*
 * Creates a new SedRepeatedTask_t object, adds it to this SedDocument_t object
 * and returns the SedRepeatedTask_t object created.
 */
LIBSEDML_EXTERN
SedRepeatedTask_t*
SedDocument_createRepeatedTask(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createRepeatedTask() : NULL;
}


/*
 * Creates a new SedParameterEstimationTask_t object, adds it to this
 * SedDocument_t object and returns the SedParameterEstimationTask_t object
 * created.
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t*
SedDocument_createParameterEstimationTask(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createParameterEstimationTask() : NULL;
}


/*
 * Removes the nth SedAbstractTask_t from this SedDocument_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedDocument_removeTask(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeTask(n) : NULL;
}


/*
 * Removes the SedAbstractTask_t from this SedDocument_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedDocument_removeTaskById(SedDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeTask(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedDataGenerator_t objects from this
 * SedDocument_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfDataGenerators(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfDataGenerators() : NULL;
}


/*
 * Get a SedDataGenerator_t from the SedDocument_t.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_getDataGenerator(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getDataGenerator(n) : NULL;
}


/*
 * Get a SedDataGenerator_t from the SedDocument_t based on its identifier.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_getDataGeneratorById(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getDataGenerator(sid) : NULL;
}


/*
 * Adds a copy of the given SedDataGenerator_t to this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_addDataGenerator(SedDocument_t* sd, const SedDataGenerator_t* sdg)
{
  return (sd != NULL) ? sd->addDataGenerator(sdg) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedDataGenerator_t objects in this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumDataGenerators(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumDataGenerators() : SEDML_INT_MAX;
}


/*
 * Creates a new SedDataGenerator_t object, adds it to this SedDocument_t
 * object and returns the SedDataGenerator_t object created.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_createDataGenerator(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createDataGenerator() : NULL;
}


/*
 * Removes the nth SedDataGenerator_t from this SedDocument_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_removeDataGenerator(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeDataGenerator(n) : NULL;
}


/*
 * Removes the SedDataGenerator_t from this SedDocument_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_removeDataGeneratorById(SedDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeDataGenerator(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedOutput_t objects from this SedDocument_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfOutputs(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfOutputs() : NULL;
}


/*
 * Get a SedOutput_t from the SedDocument_t.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedDocument_getOutput(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getOutput(n) : NULL;
}


/*
 * Get a SedOutput_t from the SedDocument_t based on its identifier.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedDocument_getOutputById(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getOutput(sid) : NULL;
}


/*
 * Adds a copy of the given SedOutput_t to this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_addOutput(SedDocument_t* sd, const SedOutput_t* so)
{
  return (sd != NULL) ? sd->addOutput(so) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedOutput_t objects in this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumOutputs(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumOutputs() : SEDML_INT_MAX;
}


/*
 * Creates a new SedReport_t object, adds it to this SedDocument_t object and
 * returns the SedReport_t object created.
 */
LIBSEDML_EXTERN
SedReport_t*
SedDocument_createReport(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createReport() : NULL;
}


/*
 * Creates a new SedPlot2D_t object, adds it to this SedDocument_t object and
 * returns the SedPlot2D_t object created.
 */
LIBSEDML_EXTERN
SedPlot2D_t*
SedDocument_createPlot2D(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createPlot2D() : NULL;
}


/*
 * Creates a new SedPlot3D_t object, adds it to this SedDocument_t object and
 * returns the SedPlot3D_t object created.
 */
LIBSEDML_EXTERN
SedPlot3D_t*
SedDocument_createPlot3D(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createPlot3D() : NULL;
}


/*
 * Creates a new SedFigure_t object, adds it to this SedDocument_t object and
 * returns the SedFigure_t object created.
 */
LIBSEDML_EXTERN
SedFigure_t*
SedDocument_createFigure(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createFigure() : NULL;
}


/*
 * Creates a new SedParameterEstimationResultPlot_t object, adds it to this
 * SedDocument_t object and returns the SedParameterEstimationResultPlot_t
 * object created.
 */
LIBSEDML_EXTERN
SedParameterEstimationResultPlot_t*
SedDocument_createParameterEstimationResultPlot(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createParameterEstimationResultPlot() : NULL;
}


/*
 * Removes the nth SedOutput_t from this SedDocument_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedDocument_removeOutput(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeOutput(n) : NULL;
}


/*
 * Removes the SedOutput_t from this SedDocument_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedDocument_removeOutputById(SedDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeOutput(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedStyle_t objects from this SedDocument_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfStyles(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfStyles() : NULL;
}


/*
 * Get a SedStyle_t from the SedDocument_t.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_getStyle(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getStyle(n) : NULL;
}


/*
 * Get a SedStyle_t from the SedDocument_t based on its identifier.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_getStyleById(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getStyle(sid) : NULL;
}


/*
 * Get a SedStyle_t from the SedDocument_t based on the BaseStyle to which it
 * refers.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_getStyleByBaseStyle(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getStyleByBaseStyle(sid) : NULL;
}


/*
 * Adds a copy of the given SedStyle_t to this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_addStyle(SedDocument_t* sd, const SedStyle_t* ss)
{
  return (sd != NULL) ? sd->addStyle(ss) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedStyle_t objects in this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumStyles(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumStyles() : SEDML_INT_MAX;
}


/*
 * Creates a new SedStyle_t object, adds it to this SedDocument_t object and
 * returns the SedStyle_t object created.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_createStyle(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createStyle() : NULL;
}


/*
 * Removes the nth SedStyle_t from this SedDocument_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_removeStyle(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeStyle(n) : NULL;
}


/*
 * Removes the SedStyle_t from this SedDocument_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_removeStyleById(SedDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeStyle(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDocument_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDocument_hasRequiredAttributes(const SedDocument_t * sd)
{
  return (sd != NULL) ? static_cast<int>(sd->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


