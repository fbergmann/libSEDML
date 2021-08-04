/**
 * @file SedRepeatedTask.cpp
 * @brief Implementation of the SedRepeatedTask class.
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
#include <sedml/SedRepeatedTask.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedUniformRange.h>
#include <sedml/SedVectorRange.h>
#include <sedml/SedFunctionalRange.h>
#include <sedml/SedDataRange.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedRepeatedTask using the given SED-ML Level and @ p version
 * values.
 */
SedRepeatedTask::SedRepeatedTask(unsigned int level, unsigned int version)
  : SedAbstractTask(level, version)
  , mRange ("")
  , mResetModel (false)
  , mIsSetResetModel (false)
  , mConcatenate (false)
  , mIsSetConcatenate (false)
  , mRanges (level, version)
  , mSetValues (level, version)
  , mSubTasks (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedRepeatedTask using the given SedNamespaces object @p
 * sedmlns.
 */
SedRepeatedTask::SedRepeatedTask(SedNamespaces *sedmlns)
  : SedAbstractTask(sedmlns)
  , mRange ("")
  , mResetModel (false)
  , mIsSetResetModel (false)
  , mConcatenate(false)
  , mIsSetConcatenate(false)
  , mRanges (sedmlns)
  , mSetValues (sedmlns)
  , mSubTasks (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedRepeatedTask.
 */
SedRepeatedTask::SedRepeatedTask(const SedRepeatedTask& orig)
  : SedAbstractTask( orig )
  , mRange ( orig.mRange )
  , mResetModel ( orig.mResetModel )
  , mIsSetResetModel ( orig.mIsSetResetModel )
  , mConcatenate( orig.mConcatenate)
  , mIsSetConcatenate( orig.mIsSetConcatenate)
  , mRanges ( orig.mRanges )
  , mSetValues ( orig.mSetValues )
  , mSubTasks ( orig.mSubTasks )
{
  connectToChild();
}


/*
 * Assignment operator for SedRepeatedTask.
 */
SedRepeatedTask&
SedRepeatedTask::operator=(const SedRepeatedTask& rhs)
{
  if (&rhs != this)
  {
    SedAbstractTask::operator=(rhs);
    mRange = rhs.mRange;
    mResetModel = rhs.mResetModel;
    mIsSetResetModel = rhs.mIsSetResetModel;
    mConcatenate = rhs.mConcatenate;
    mIsSetConcatenate = rhs.mIsSetConcatenate;
    mRanges = rhs.mRanges;
    mSetValues = rhs.mSetValues;
    mSubTasks = rhs.mSubTasks;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedRepeatedTask object.
 */
SedRepeatedTask*
SedRepeatedTask::clone() const
{
  return new SedRepeatedTask(*this);
}


/*
 * Destructor for SedRepeatedTask.
 */
SedRepeatedTask::~SedRepeatedTask()
{
}


/*
 * Returns the value of the "range" attribute of this SedRepeatedTask.
 */
const std::string&
SedRepeatedTask::getRangeId() const
{
  return mRange;
}


/*
 * Returns the value of the "resetModel" attribute of this SedRepeatedTask.
 */
bool
SedRepeatedTask::getResetModel() const
{
  return mResetModel;
}


/*
 * Returns the value of the "concatenate" attribute of this SedRepeatedTask.
 */
bool
SedRepeatedTask::getConcatenate() const
{
    return mConcatenate;
}


/*
 * Predicate returning @c true if this SedRepeatedTask's "range" attribute is
 * set.
 */
bool
SedRepeatedTask::isSetRangeId() const
{
  return (mRange.empty() == false);
}


/*
 * Predicate returning @c true if this SedRepeatedTask's "resetModel" attribute
 * is set.
 */
bool
SedRepeatedTask::isSetResetModel() const
{
  return mIsSetResetModel;
}


/*
 * Predicate returning @c true if this SedRepeatedTask's "concatenate" attribute
 * is set.
 */
bool
SedRepeatedTask::isSetConcatenate() const
{
    return mIsSetConcatenate;
}


/*
 * Sets the value of the "range" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setRangeId(const std::string& rangeId)
{
  if (!(SyntaxChecker::isValidInternalSId(rangeId)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mRange = rangeId;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "resetModel" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setResetModel(bool resetModel)
{
  mResetModel = resetModel;
  mIsSetResetModel = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "concatenate" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setConcatenate(bool concatenate)
{
    if (getLevel() == 1 && getVersion() < 4)
    {
        return LIBSEDML_UNEXPECTED_ATTRIBUTE;
    }
    mConcatenate= concatenate;
    mIsSetConcatenate= true;
    return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "range" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::unsetRangeId()
{
  mRange.erase();

  if (mRange.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "resetModel" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::unsetResetModel()
{
  mResetModel = false;
  mIsSetResetModel = false;

  if (isSetResetModel() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "concatenate" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::unsetConcatenate()
{
    mConcatenate = false;
    mIsSetConcatenate = false;

    if (isSetConcatenate() == false)
    {
        return LIBSEDML_OPERATION_SUCCESS;
    }
    else
    {
        return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Returns the SedListOfRanges from this SedRepeatedTask.
 */
const SedListOfRanges*
SedRepeatedTask::getListOfRanges() const
{
  return &mRanges;
}


/*
 * Returns the SedListOfRanges from this SedRepeatedTask.
 */
SedListOfRanges*
SedRepeatedTask::getListOfRanges()
{
  return &mRanges;
}


/*
 * Get a SedRange from the SedRepeatedTask.
 */
SedRange*
SedRepeatedTask::getRange(unsigned int n)
{
  return mRanges.get(n);
}


/*
 * Get a SedRange from the SedRepeatedTask.
 */
const SedRange*
SedRepeatedTask::getRange(unsigned int n) const
{
  return mRanges.get(n);
}


/*
 * Get a SedRange from the SedRepeatedTask based on its identifier.
 */
SedRange*
SedRepeatedTask::getRange(const std::string& sid)
{
  return mRanges.get(sid);
}


/*
 * Get a SedRange from the SedRepeatedTask based on its identifier.
 */
const SedRange*
SedRepeatedTask::getRange(const std::string& sid) const
{
  return mRanges.get(sid);
}


/*
 * Adds a copy of the given SedRange to this SedRepeatedTask.
 */
int
SedRepeatedTask::addRange(const SedRange* sr)
{
  if (sr == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sr->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sr->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sr->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sr)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sr->isSetId() && (mRanges.get(sr->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mRanges.append(sr);
  }
}


/*
 * Get the number of SedRange objects in this SedRepeatedTask.
 */
unsigned int
SedRepeatedTask::getNumRanges() const
{
  return mRanges.size();
}


/*
 * Creates a new SedUniformRange object, adds it to this SedRepeatedTask object
 * and returns the SedUniformRange object created.
 */
SedUniformRange*
SedRepeatedTask::createUniformRange()
{
  SedUniformRange* sur = NULL;

  try
  {
    sur = new SedUniformRange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sur != NULL)
  {
    mRanges.appendAndOwn(sur);
  }

  return sur;
}


/*
 * Creates a new SedVectorRange object, adds it to this SedRepeatedTask object
 * and returns the SedVectorRange object created.
 */
SedVectorRange*
SedRepeatedTask::createVectorRange()
{
  SedVectorRange* svr = NULL;

  try
  {
    svr = new SedVectorRange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (svr != NULL)
  {
    mRanges.appendAndOwn(svr);
  }

  return svr;
}


/*
 * Creates a new SedFunctionalRange object, adds it to this SedRepeatedTask
 * object and returns the SedFunctionalRange object created.
 */
SedFunctionalRange*
SedRepeatedTask::createFunctionalRange()
{
  SedFunctionalRange* sfr = NULL;

  try
  {
    sfr = new SedFunctionalRange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sfr != NULL)
  {
    mRanges.appendAndOwn(sfr);
  }

  return sfr;
}


/*
 * Creates a new SedDataRange object, adds it to this SedRepeatedTask object
 * and returns the SedDataRange object created.
 */
SedDataRange*
SedRepeatedTask::createDataRange()
{
  SedDataRange* sdr = NULL;

  try
  {
    sdr = new SedDataRange(getSedNamespaces());
  }
  catch (const SedConstructorException&)
  {
    return NULL;
  }

  if (sdr != NULL)
  {
    mRanges.appendAndOwn(sdr);
  }

  return sdr;
}


/*
 * Removes the nth SedRange from this SedRepeatedTask and returns a pointer to
 * it.
 */
SedRange*
SedRepeatedTask::removeRange(unsigned int n)
{
  return mRanges.remove(n);
}


/*
 * Removes the SedRange from this SedRepeatedTask based on its identifier and
 * returns a pointer to it.
 */
SedRange*
SedRepeatedTask::removeRange(const std::string& sid)
{
  return mRanges.remove(sid);
}


/*
 * Returns the SedListOfSetValues from this SedRepeatedTask.
 */
const SedListOfSetValues*
SedRepeatedTask::getListOfTaskChanges() const
{
  return &mSetValues;
}


/*
 * Returns the SedListOfSetValues from this SedRepeatedTask.
 */
SedListOfSetValues*
SedRepeatedTask::getListOfTaskChanges()
{
  return &mSetValues;
}


/*
 * Get a SedSetValue from the SedRepeatedTask.
 */
SedSetValue*
SedRepeatedTask::getTaskChange(unsigned int n)
{
  return mSetValues.get(n);
}


/*
 * Get a SedSetValue from the SedRepeatedTask.
 */
const SedSetValue*
SedRepeatedTask::getTaskChange(unsigned int n) const
{
  return mSetValues.get(n);
}


/*
 * Get a SedSetValue from the SedRepeatedTask based on the ModelReference to
 * which it refers.
 */
const SedSetValue*
SedRepeatedTask::getTaskChangeByModelReference(const std::string& sid) const
{
  return mSetValues.getByModelReference(sid);
}


/*
 * Get a SedSetValue from the SedRepeatedTask based on the ModelReference to
 * which it refers.
 */
SedSetValue*
SedRepeatedTask::getTaskChangeByModelReference(const std::string& sid)
{
  return mSetValues.getByModelReference(sid);
}


/*
 * Get a SedSetValue from the SedRepeatedTask based on the Range to which it
 * refers.
 */
const SedSetValue*
SedRepeatedTask::getTaskChangeByRange(const std::string& sid) const
{
  return mSetValues.getByRange(sid);
}


/*
 * Get a SedSetValue from the SedRepeatedTask based on the Range to which it
 * refers.
 */
SedSetValue*
SedRepeatedTask::getTaskChangeByRange(const std::string& sid)
{
  return mSetValues.getByRange(sid);
}


/*
 * Adds a copy of the given SedSetValue to this SedRepeatedTask.
 */
int
SedRepeatedTask::addTaskChange(const SedSetValue* ssv)
{
  if (ssv == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ssv->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (ssv->hasRequiredElements() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ssv->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ssv->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ssv)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mSetValues.append(ssv);
  }
}


/*
 * Get the number of SedSetValue objects in this SedRepeatedTask.
 */
unsigned int
SedRepeatedTask::getNumTaskChanges() const
{
  return mSetValues.size();
}


/*
 * Creates a new SedSetValue object, adds it to this SedRepeatedTask object and
 * returns the SedSetValue object created.
 */
SedSetValue*
SedRepeatedTask::createTaskChange()
{
  SedSetValue* ssv = NULL;

  try
  {
    ssv = new SedSetValue(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ssv != NULL)
  {
    mSetValues.appendAndOwn(ssv);
  }

  return ssv;
}


/*
 * Removes the nth SedSetValue from this SedRepeatedTask and returns a pointer
 * to it.
 */
SedSetValue*
SedRepeatedTask::removeTaskChange(unsigned int n)
{
  return mSetValues.remove(n);
}


/*
 * Returns the SedListOfSubTasks from this SedRepeatedTask.
 */
const SedListOfSubTasks*
SedRepeatedTask::getListOfSubTasks() const
{
  return &mSubTasks;
}


/*
 * Returns the SedListOfSubTasks from this SedRepeatedTask.
 */
SedListOfSubTasks*
SedRepeatedTask::getListOfSubTasks()
{
  return &mSubTasks;
}


/*
 * Get a SedSubTask from the SedRepeatedTask.
 */
SedSubTask*
SedRepeatedTask::getSubTask(unsigned int n)
{
  return mSubTasks.get(n);
}


/*
 * Get a SedSubTask from the SedRepeatedTask.
 */
const SedSubTask*
SedRepeatedTask::getSubTask(unsigned int n) const
{
  return mSubTasks.get(n);
}


/*
 * Get a SedSubTask from the SedRepeatedTask based on the Task to which it
 * refers.
 */
const SedSubTask*
SedRepeatedTask::getSubTaskByTask(const std::string& sid) const
{
  return mSubTasks.getByTask(sid);
}


/*
 * Get a SedSubTask from the SedRepeatedTask based on the Task to which it
 * refers.
 */
SedSubTask*
SedRepeatedTask::getSubTaskByTask(const std::string& sid)
{
  return mSubTasks.getByTask(sid);
}


/*
 * Adds a copy of the given SedSubTask to this SedRepeatedTask.
 */
int
SedRepeatedTask::addSubTask(const SedSubTask* sst)
{
  if (sst == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sst->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sst->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sst->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sst)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mSubTasks.append(sst);
  }
}


/*
 * Get the number of SedSubTask objects in this SedRepeatedTask.
 */
unsigned int
SedRepeatedTask::getNumSubTasks() const
{
  return mSubTasks.size();
}


/*
 * Creates a new SedSubTask object, adds it to this SedRepeatedTask object and
 * returns the SedSubTask object created.
 */
SedSubTask*
SedRepeatedTask::createSubTask()
{
  SedSubTask* sst = NULL;

  try
  {
    sst = new SedSubTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sst != NULL)
  {
    mSubTasks.appendAndOwn(sst);
  }

  return sst;
}


/*
 * Removes the nth SedSubTask from this SedRepeatedTask and returns a pointer
 * to it.
 */
SedSubTask*
SedRepeatedTask::removeSubTask(unsigned int n)
{
  return mSubTasks.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedRepeatedTask::renameSIdRefs(const std::string& oldid,
                               const std::string& newid)
{
  if (isSetRangeId() && mRange == oldid)
  {
    setRangeId(newid);
  }
}


/*
 * Returns the XML element name of this SedRepeatedTask object.
 */
const std::string&
SedRepeatedTask::getElementName() const
{
  static const string name = "repeatedTask";
  return name;
}


/*
 * Returns the libSEDML type code for this SedRepeatedTask object.
 */
int
SedRepeatedTask::getTypeCode() const
{
  return SEDML_TASK_REPEATEDTASK;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedRepeatedTask object have been set.
 */
bool
SedRepeatedTask::hasRequiredAttributes() const
{
  bool allPresent = SedAbstractTask::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedRepeatedTask object have been set.
 */
bool
SedRepeatedTask::hasRequiredElements() const
{
  bool allPresent = SedAbstractTask::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedRepeatedTask::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedAbstractTask::writeElements(stream);

  if (getNumRanges() > 0)
  {
    mRanges.write(stream);
  }

  if (getNumTaskChanges() > 0)
  {
    mSetValues.write(stream);
  }

  if (getNumSubTasks() > 0)
  {
    mSubTasks.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedRepeatedTask::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedRepeatedTask::setSedDocument(SedDocument* d)
{
  SedAbstractTask::setSedDocument(d);

  mRanges.setSedDocument(d);

  mSetValues.setSedDocument(d);

  mSubTasks.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedRepeatedTask::connectToChild()
{
  SedAbstractTask::connectToChild();

  mRanges.connectToParent(this);

  mSetValues.connectToParent(this);

  mSubTasks.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::getAttribute(const std::string& attributeName,
                              bool& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "resetModel")
  {
    value = getResetModel();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  if (attributeName == "concatenate")
  {
      value = getConcatenate();
      return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::getAttribute(const std::string& attributeName,
                              int& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::getAttribute(const std::string& attributeName,
                              double& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::getAttribute(const std::string& attributeName,
                              unsigned int& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::getAttribute(const std::string& attributeName,
                              std::string& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "range")
  {
    value = getRangeId();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedRepeatedTask's attribute
 * "attributeName" is set.
 */
bool
SedRepeatedTask::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedAbstractTask::isSetAttribute(attributeName);

  if (attributeName == "range")
  {
    value = isSetRangeId();
  }
  else if (attributeName == "resetModel")
  {
    value = isSetResetModel();
  }
  else if (attributeName == "concatenate")
  {
      value = isSetConcatenate();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  if (attributeName == "resetModel")
  {
    return_value = setResetModel(value);
  }
  else if (attributeName == "concatenate")
  {
      return_value = setConcatenate(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setAttribute(const std::string& attributeName,
                              unsigned int value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setAttribute(const std::string& attributeName,
                              const std::string& value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  if (attributeName == "range")
  {
    return_value = setRangeId(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::unsetAttribute(const std::string& attributeName)
{
  int value = SedAbstractTask::unsetAttribute(attributeName);

  if (attributeName == "range")
  {
    value = unsetRangeId();
  }
  else if (attributeName == "resetModel")
  {
    value = unsetResetModel();
  }
  else if (attributeName == "concatenate")
  {
      value = unsetConcatenate();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedRepeatedTask.
 */
SedBase*
SedRepeatedTask::createChildObject(const std::string& elementName)
{
  SedAbstractTask* obj = NULL;

  if (elementName == "uniformRange")
  {
    return createUniformRange();
  }
  else if (elementName == "vectorRange")
  {
    return createVectorRange();
  }
  else if (elementName == "functionalRange")
  {
    return createFunctionalRange();
  }
  else if (elementName == "dataRange")
  {
    return createDataRange();
  }
  else if (elementName == "setValue")
  {
    return createTaskChange();
  }
  else if (elementName == "subTask")
  {
    return createSubTask();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedRepeatedTask.
 */
int
SedRepeatedTask::addChildObject(const std::string& elementName,
                                const SedBase* element)
{
  if (elementName == "uniformRange" && element->getTypeCode() ==
    SEDML_RANGE_UNIFORMRANGE)
  {
    return addRange((const SedRange*)(element));
  }
  else if (elementName == "vectorRange" && element->getTypeCode() ==
    SEDML_RANGE_VECTORRANGE)
  {
    return addRange((const SedRange*)(element));
  }
  else if (elementName == "functionalRange" && element->getTypeCode() ==
    SEDML_RANGE_FUNCTIONALRANGE)
  {
    return addRange((const SedRange*)(element));
  }
  else if (elementName == "dataRange" && element->getTypeCode() ==
    SEDML_DATA_RANGE)
  {
    return addRange((const SedRange*)(element));
  }
  else if (elementName == "setValue" && element->getTypeCode() ==
    SEDML_TASK_SETVALUE)
  {
    return addTaskChange((const SedSetValue*)(element));
  }
  else if (elementName == "subTask" && element->getTypeCode() ==
    SEDML_TASK_SUBTASK)
  {
    return addSubTask((const SedSubTask*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedRepeatedTask.
 */
SedBase*
SedRepeatedTask::removeChildObject(const std::string& elementName,
                                   const std::string& id)
{
  if (elementName == "uniformRange")
  {
    return removeRange(id);
  }
  else if (elementName == "vectorRange")
  {
    return removeRange(id);
  }
  else if (elementName == "functionalRange")
  {
    return removeRange(id);
  }
  else if (elementName == "dataRange")
  {
    return removeRange(id);
  }
  else if (elementName == "setValue")
  {
    for (unsigned int i = 0; i < getNumTaskChanges(); i++)
    {
      if (getTaskChange(i)->getId() == id)
      {
        return removeTaskChange(i);
      }
    }
  }
  else if (elementName == "subTask")
  {
    for (unsigned int i = 0; i < getNumSubTasks(); i++)
    {
      if (getSubTask(i)->getId() == id)
      {
        return removeSubTask(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedRepeatedTask.
 */
unsigned int
SedRepeatedTask::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "range")
  {
    return getNumRanges();
  }
  else if (elementName == "setValue")
  {
    return getNumTaskChanges();
  }
  else if (elementName == "subTask")
  {
    return getNumSubTasks();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedRepeatedTask.
 */
SedBase*
SedRepeatedTask::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "range")
  {
    return getRange(index);
  }
  else if (elementName == "setValue")
  {
    return getTaskChange(index);
  }
  else if (elementName == "subTask")
  {
    return getSubTask(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedRepeatedTask::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mRanges.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mSetValues.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mSubTasks.getElementBySId(id);

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
SedRepeatedTask::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mRanges, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mSetValues, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mSubTasks, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedRepeatedTask::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedAbstractTask::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "listOfRanges")
  {
    if (getErrorLog() && mRanges.size() != 0)
    {
      getErrorLog()->logError(SedmlRepeatedTaskAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mRanges;
  }
  else if (name == "listOfChanges")
  {
    if (getErrorLog() && mSetValues.size() != 0)
    {
      getErrorLog()->logError(SedmlRepeatedTaskAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mSetValues;
  }
  else if (name == "listOfSubTasks")
  {
    if (getErrorLog() && mSubTasks.size() != 0)
    {
      getErrorLog()->logError(SedmlRepeatedTaskAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mSubTasks;
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
SedRepeatedTask::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedAbstractTask::addExpectedAttributes(attributes);

  attributes.add("range");

  attributes.add("resetModel");

  attributes.add("concatenate");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedRepeatedTask::readAttributes(
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
        log->logError(SedmlRepeatedTaskAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // range SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("range", mRange);

  if (assigned == true)
  {
    if (mRange.empty() == true)
    {
      logEmptyString(mRange, level, version, "<SedRepeatedTask>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRange) == false)
    {
      std::string msg = "The range attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mRange + "', which does not conform to the syntax.";
      logError(SedmlRepeatedTaskRangeMustBeRange, level, version, msg,
        getLine(), getColumn());
    }
  }

  // 
  // resetModel bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetResetModel = attributes.readInto("resetModel", mResetModel);

  if (mIsSetResetModel == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlRepeatedTaskResetModelMustBeBoolean, level, version);
    }
  }

  // 
  // concatentate bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetConcatenate = attributes.readInto("concatentate", mConcatenate);

  if (mIsSetConcatenate == false)
  {
      if (log && log->getNumErrors() == numErrs + 1 &&
          log->contains(XMLAttributeTypeMismatch))
      {
          log->remove(XMLAttributeTypeMismatch);
          log->logError(SedmlRepeatedTaskConcatenateMustBeBoolean, level, version);
      }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedRepeatedTask::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedAbstractTask::writeAttributes(stream);

  if (isSetRangeId() == true)
  {
    stream.writeAttribute("range", getPrefix(), mRange);
  }

  if (isSetResetModel() == true)
  {
    stream.writeAttribute("resetModel", getPrefix(), mResetModel);
  }

  if (isSetConcatenate() == true && (getLevel()>1 || getVersion() >=4))
  {
      stream.writeAttribute("concatenate", getPrefix(), mConcatenate);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedRepeatedTask_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_create(unsigned int level, unsigned int version)
{
  return new SedRepeatedTask(level, version);
}


/*
 * Creates and returns a deep copy of this SedRepeatedTask_t object.
 */
LIBSEDML_EXTERN
SedRepeatedTask_t*
SedRepeatedTask_clone(const SedRepeatedTask_t* srt)
{
  if (srt != NULL)
  {
    return static_cast<SedRepeatedTask_t*>(srt->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedRepeatedTask_t object.
 */
LIBSEDML_EXTERN
void
SedRepeatedTask_free(SedRepeatedTask_t* srt)
{
  if (srt != NULL)
  {
    delete srt;
  }
}


/*
 * Returns the value of the "range" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
char *
SedRepeatedTask_getRangeId(const SedRepeatedTask_t * srt)
{
  if (srt == NULL)
  {
    return NULL;
  }

  return srt->getRangeId().empty() ? NULL : safe_strdup(srt->getRangeId().c_str());
}


/*
 * Returns the value of the "resetModel" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_getResetModel(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->getResetModel()) : 0;
}


/*
 * Returns the value of the "concatenate" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_getConcatenate(const SedRepeatedTask_t* srt)
{
    return (srt != NULL) ? static_cast<int>(srt->getConcatenate()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedRepeatedTask_t's "range"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetRangeId(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->isSetRangeId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedRepeatedTask_t's "resetModel"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetResetModel(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->isSetResetModel()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedRepeatedTask_t's "concatenate"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetConcatenate(const SedRepeatedTask_t* srt)
{
    return (srt != NULL) ? static_cast<int>(srt->isSetConcatenate()) : 0;
}


/*
 * Sets the value of the "range" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setRangeId(SedRepeatedTask_t * srt, const char * rangeId)
{
  return (srt != NULL) ? srt->setRangeId(rangeId) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "resetModel" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setResetModel(SedRepeatedTask_t * srt, int resetModel)
{
  return (srt != NULL) ? srt->setResetModel(resetModel) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "concatenate" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setConcatenate(SedRepeatedTask_t* srt, int concatenate)
{
    return (srt != NULL) ? srt->setConcatenate(concatenate) :
        LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "range" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetRangeId(SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? srt->unsetRangeId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "resetModel" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetResetModel(SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? srt->unsetResetModel() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "concatenate" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetConcatenate(SedRepeatedTask_t* srt)
{
    return (srt != NULL) ? srt->unsetConcatenate() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedRange_t objects from this
 * SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedRepeatedTask_getListOfRanges(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->getListOfRanges() : NULL;
}


/*
 * Get a SedRange_t from the SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
SedRange_t*
SedRepeatedTask_getRange(SedRepeatedTask_t* srt, unsigned int n)
{
  return (srt != NULL) ? srt->getRange(n) : NULL;
}


/*
 * Get a SedRange_t from the SedRepeatedTask_t based on its identifier.
 */
LIBSEDML_EXTERN
SedRange_t*
SedRepeatedTask_getRangeById(SedRepeatedTask_t* srt, const char *sid)
{
  return (srt != NULL && sid != NULL) ? srt->getRange(sid) : NULL;
}


/*
 * Adds a copy of the given SedRange_t to this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_addRange(SedRepeatedTask_t* srt, const SedRange_t* sr)
{
  return (srt != NULL) ? srt->addRange(sr) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedRange_t objects in this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumRanges(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->getNumRanges() : SEDML_INT_MAX;
}


/*
 * Creates a new SedUniformRange_t object, adds it to this SedRepeatedTask_t
 * object and returns the SedUniformRange_t object created.
 */
LIBSEDML_EXTERN
SedUniformRange_t*
SedRepeatedTask_createUniformRange(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->createUniformRange() : NULL;
}


/*
 * Creates a new SedVectorRange_t object, adds it to this SedRepeatedTask_t
 * object and returns the SedVectorRange_t object created.
 */
LIBSEDML_EXTERN
SedVectorRange_t*
SedRepeatedTask_createVectorRange(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->createVectorRange() : NULL;
}


/*
 * Creates a new SedFunctionalRange_t object, adds it to this SedRepeatedTask_t
 * object and returns the SedFunctionalRange_t object created.
 */
LIBSEDML_EXTERN
SedFunctionalRange_t*
SedRepeatedTask_createFunctionalRange(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->createFunctionalRange() : NULL;
}


/*
 * Creates a new SedDataRange_t object, adds it to this SedRepeatedTask_t
 * object and returns the SedDataRange_t object created.
 */
LIBSEDML_EXTERN
SedDataRange_t*
SedRepeatedTask_createDataRange(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->createDataRange() : NULL;
}


/*
 * Removes the nth SedRange_t from this SedRepeatedTask_t and returns a pointer
 * to it.
 */
LIBSEDML_EXTERN
SedRange_t*
SedRepeatedTask_removeRange(SedRepeatedTask_t* srt, unsigned int n)
{
  return (srt != NULL) ? srt->removeRange(n) : NULL;
}


/*
 * Removes the SedRange_t from this SedRepeatedTask_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedRange_t*
SedRepeatedTask_removeRangeById(SedRepeatedTask_t* srt, const char* sid)
{
  return (srt != NULL && sid != NULL) ? srt->removeRange(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedSetValue_t objects from this
 * SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedRepeatedTask_getListOfTaskChanges(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->getListOfTaskChanges() : NULL;
}


/*
 * Get a SedSetValue_t from the SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_getTaskChange(SedRepeatedTask_t* srt, unsigned int n)
{
  return (srt != NULL) ? srt->getTaskChange(n) : NULL;
}


/*
 * Get a SedSetValue_t from the SedRepeatedTask_t based on the ModelReference
 * to which it refers.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_getTaskChangeByModelReference(SedRepeatedTask_t* srt,
                                              const char *sid)
{
  return (srt != NULL && sid != NULL) ? srt->getTaskChangeByModelReference(sid)
    : NULL;
}


/*
 * Get a SedSetValue_t from the SedRepeatedTask_t based on the Range to which
 * it refers.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_getTaskChangeByRange(SedRepeatedTask_t* srt, const char *sid)
{
  return (srt != NULL && sid != NULL) ? srt->getTaskChangeByRange(sid) : NULL;
}


/*
 * Adds a copy of the given SedSetValue_t to this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_addTaskChange(SedRepeatedTask_t* srt,
                              const SedSetValue_t* ssv)
{
  return (srt != NULL) ? srt->addTaskChange(ssv) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedSetValue_t objects in this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumTaskChanges(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->getNumTaskChanges() : SEDML_INT_MAX;
}


/*
 * Creates a new SedSetValue_t object, adds it to this SedRepeatedTask_t object
 * and returns the SedSetValue_t object created.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_createTaskChange(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->createTaskChange() : NULL;
}


/*
 * Removes the nth SedSetValue_t from this SedRepeatedTask_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_removeTaskChange(SedRepeatedTask_t* srt, unsigned int n)
{
  return (srt != NULL) ? srt->removeTaskChange(n) : NULL;
}


/*
 * Returns a ListOf_t * containing SedSubTask_t objects from this
 * SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedRepeatedTask_getListOfSubTasks(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->getListOfSubTasks() : NULL;
}


/*
 * Get a SedSubTask_t from the SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedRepeatedTask_getSubTask(SedRepeatedTask_t* srt, unsigned int n)
{
  return (srt != NULL) ? srt->getSubTask(n) : NULL;
}


/*
 * Get a SedSubTask_t from the SedRepeatedTask_t based on the Task to which it
 * refers.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedRepeatedTask_getSubTaskByTask(SedRepeatedTask_t* srt, const char *sid)
{
  return (srt != NULL && sid != NULL) ? srt->getSubTaskByTask(sid) : NULL;
}


/*
 * Adds a copy of the given SedSubTask_t to this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_addSubTask(SedRepeatedTask_t* srt, const SedSubTask_t* sst)
{
  return (srt != NULL) ? srt->addSubTask(sst) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedSubTask_t objects in this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumSubTasks(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->getNumSubTasks() : SEDML_INT_MAX;
}


/*
 * Creates a new SedSubTask_t object, adds it to this SedRepeatedTask_t object
 * and returns the SedSubTask_t object created.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedRepeatedTask_createSubTask(SedRepeatedTask_t* srt)
{
  return (srt != NULL) ? srt->createSubTask() : NULL;
}


/*
 * Removes the nth SedSubTask_t from this SedRepeatedTask_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedRepeatedTask_removeSubTask(SedRepeatedTask_t* srt, unsigned int n)
{
  return (srt != NULL) ? srt->removeSubTask(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedRepeatedTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredAttributes(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedRepeatedTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredElements(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


