/**
 * @file SedSubTask.cpp
 * @brief Implementation of the SedSubTask class.
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
#include <sedml/SedSubTask.h>
#include <sedml/SedListOfSubTasks.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSubTask using the given SED-ML Level and @ p version values.
 */
SedSubTask::SedSubTask(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mOrder (SEDML_INT_MAX)
  , mIsSetOrder (false)
  , mTask ("")
  , mSetValues (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSubTask using the given SedNamespaces object @p sedmlns.
 */
SedSubTask::SedSubTask(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mOrder (SEDML_INT_MAX)
  , mIsSetOrder (false)
  , mTask ("")
  , mSetValues (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedSubTask.
 */
SedSubTask::SedSubTask(const SedSubTask& orig)
  : SedBase( orig )
  , mOrder ( orig.mOrder )
  , mIsSetOrder ( orig.mIsSetOrder )
  , mTask ( orig.mTask )
  , mSetValues ( orig.mSetValues )
{
}


/*
 * Assignment operator for SedSubTask.
 */
SedSubTask&
SedSubTask::operator=(const SedSubTask& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mOrder = rhs.mOrder;
    mIsSetOrder = rhs.mIsSetOrder;
    mTask = rhs.mTask;
    mSetValues = rhs.mSetValues;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSubTask object.
 */
SedSubTask*
SedSubTask::clone() const
{
  return new SedSubTask(*this);
}


/*
 * Destructor for SedSubTask.
 */
SedSubTask::~SedSubTask()
{
}


/*
 * Returns the value of the "order" attribute of this SedSubTask.
 */
int
SedSubTask::getOrder() const
{
  return mOrder;
}


/*
 * Returns the value of the "task" attribute of this SedSubTask.
 */
const std::string&
SedSubTask::getTask() const
{
  return mTask;
}


/*
 * Predicate returning @c true if this SedSubTask's "order" attribute is set.
 */
bool
SedSubTask::isSetOrder() const
{
  return mIsSetOrder;
}


/*
 * Predicate returning @c true if this SedSubTask's "task" attribute is set.
 */
bool
SedSubTask::isSetTask() const
{
  return (mTask.empty() == false);
}


/*
 * Sets the value of the "order" attribute of this SedSubTask.
 */
int
SedSubTask::setOrder(int order)
{
  mOrder = order;
  mIsSetOrder = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "task" attribute of this SedSubTask.
 */
int
SedSubTask::setTask(const std::string& task)
{
  if (!(SyntaxChecker::isValidInternalSId(task)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTask = task;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "order" attribute of this SedSubTask.
 */
int
SedSubTask::unsetOrder()
{
  mOrder = SEDML_INT_MAX;
  mIsSetOrder = false;

  if (isSetOrder() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "task" attribute of this SedSubTask.
 */
int
SedSubTask::unsetTask()
{
  mTask.erase();

  if (mTask.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfSetValues from this SedSubTask.
 */
const SedListOfSetValues*
SedSubTask::getListOfTaskChanges() const
{
    return &mSetValues;
}


/*
 * Returns the SedListOfSetValues from this SedSubTask.
 */
SedListOfSetValues*
SedSubTask::getListOfTaskChanges()
{
    return &mSetValues;
}


/*
 * Get a SedSetValue from the SedSubTask.
 */
SedSetValue*
SedSubTask::getTaskChange(unsigned int n)
{
    return mSetValues.get(n);
}


/*
 * Get a SedSetValue from the SedSubTask.
 */
SedSetValue*
SedSubTask::getTaskChange(const string& id)
{
    return mSetValues.get(id);
}


/*
 * Get a SedSetValue from the SedSubTask.
 */
const SedSetValue*
SedSubTask::getTaskChange(unsigned int n) const
{
    return mSetValues.get(n);
}


/*
 * Get a SedSetValue from the SedSubTask based on the ModelReference to
 * which it refers.
 */
const SedSetValue*
SedSubTask::getTaskChangeByModelReference(const std::string& sid) const
{
    return mSetValues.getByModelReference(sid);
}


/*
 * Get a SedSetValue from the SedSubTask based on the ModelReference to
 * which it refers.
 */
SedSetValue*
SedSubTask::getTaskChangeByModelReference(const std::string& sid)
{
    return mSetValues.getByModelReference(sid);
}


/*
 * Get a SedSetValue from the SedSubTask based on the Range to which it
 * refers.
 */
const SedSetValue*
SedSubTask::getTaskChangeByRange(const std::string& sid) const
{
    return mSetValues.getByRange(sid);
}


/*
 * Get a SedSetValue from the SedSubTask based on the Range to which it
 * refers.
 */
SedSetValue*
SedSubTask::getTaskChangeByRange(const std::string& sid)
{
    return mSetValues.getByRange(sid);
}


/*
 * Adds a copy of the given SedSetValue to this SedSubTask.
 */
int
SedSubTask::addTaskChange(const SedSetValue* ssv)
{
    if (ssv == NULL)
    {
        return LIBSEDML_OPERATION_FAILED;
    }
    else if (getLevel() == 1 && getVersion() < 4)
    {
        return LIBSEDML_INVALID_OBJECT;
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
 * Get the number of SedSetValue objects in this SedSubTask.
 */
unsigned int
SedSubTask::getNumTaskChanges() const
{
    return mSetValues.size();
}


/*
 * Creates a new SedSetValue object, adds it to this SedSubTask object and
 * returns the SedSetValue object created.
 */
SedSetValue*
SedSubTask::createTaskChange()
{
    SedSetValue* ssv = NULL;

    if (getLevel() == 1 && getVersion() < 4)
    {
        return ssv;
    }

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
 * Removes the nth SedSetValue from this SedSubTask and returns a pointer
 * to it.
 */
SedSetValue*
SedSubTask::removeTaskChange(unsigned int n)
{
    return mSetValues.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedSubTask::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetTask() && mTask == oldid)
  {
    setTask(newid);
  }
}


/*
 * Returns the XML element name of this SedSubTask object.
 */
const std::string&
SedSubTask::getElementName() const
{
  static const string name = "subTask";
  return name;
}


/*
 * Returns the libSEDML type code for this SedSubTask object.
 */
int
SedSubTask::getTypeCode() const
{
  return SEDML_TASK_SUBTASK;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedSubTask object have been set.
 */
bool
SedSubTask::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetOrder() == false)
  {
    allPresent = false;
  }

  if (isSetTask() == false)
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
SedSubTask::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if ((getLevel() > 1 || getVersion() >= 4) && getNumTaskChanges() > 0)
  {
      mSetValues.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedSubTask::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSubTask::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mSetValues.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedSubTask::connectToChild()
{
    SedBase::connectToChild();

    mSetValues.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedSubTask.
 */
SedBase*
SedSubTask::createChildObject(const std::string& elementName)
{
    SedBase* obj = NULL;

    if (elementName == "setValue")
    {
        return createTaskChange();
    }

    return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedSubTask.
 */
int
SedSubTask::addChildObject(const std::string& elementName,
    const SedBase* element)
{
    if (elementName == "setValue" && element->getTypeCode() ==
        SEDML_TASK_SETVALUE)
    {
        return addTaskChange((const SedSetValue*)(element));
    }

    return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedSubTask.
 */
SedBase*
SedSubTask::removeChildObject(const std::string& elementName,
    const std::string& id)
{
    if (elementName == "setValue")
    {
        for (unsigned int i = 0; i < getNumTaskChanges(); i++)
        {
            if (getTaskChange(i)->getId() == id)
            {
                return removeTaskChange(i);
            }
        }
    }

    return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedSubTask.
 */
unsigned int
SedSubTask::getNumObjects(const std::string& elementName)
{
    unsigned int n = 0;

    if (elementName == "setValue")
    {
        return getNumTaskChanges();
    }

    return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedSubTask.
 */
SedBase*
SedSubTask::getObject(const std::string& elementName, unsigned int index)
{
    SedBase* obj = NULL;

    if (elementName == "setValue")
    {
        return getTaskChange(index);
    }

    return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedSubTask::getElementBySId(const std::string& id)
{
    if (id.empty())
    {
        return NULL;
    }

    SedBase* obj = NULL;

    obj = mSetValues.getElementBySId(id);

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
SedSubTask::getAllElements(SedElementFilter* filter)
{
    List* ret = new List();
    List* sublist = NULL;

    SED_ADD_FILTERED_LIST(ret, sublist, mSetValues, filter);

    return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedSubTask::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream)
{
    SedBase* obj = SedBase::createObject(stream);

    const std::string& name = stream.peek().getName();

    if (name == "listOfChanges")
    {
        if (getErrorLog() && mSetValues.size() != 0)
        {
            getErrorLog()->logError(SedmlSubTaskAllowedElements, getLevel(),
                getVersion(), "", getLine(), getColumn());
        }

        obj = &mSetValues;
    }

    connectToChild();

    return obj;
}

/** @endcond */



/*
 * Gets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "order")
  {
    value = getOrder();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "task")
  {
    value = getTask();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedSubTask's attribute "attributeName"
 * is set.
 */
bool
SedSubTask::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "order")
  {
    value = isSetOrder();
  }
  else if (attributeName == "task")
  {
    value = isSetTask();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "order")
  {
    return_value = setOrder(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "task")
  {
    return_value = setTask(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedSubTask.
 */
int
SedSubTask::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "order")
  {
    value = unsetOrder();
  }
  else if (attributeName == "task")
  {
    value = unsetTask();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSubTask::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("order");

  attributes.add("task");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSubTask::readAttributes(
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&
                             attributes,
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER
                             ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  if (log && getParentSedObject() &&
    static_cast<SedListOfSubTasks*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlModelLOChangesAllowedCoreElements, level,
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
        log->logError(SedmlSubTaskAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // order int (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetOrder = attributes.readInto("order", mOrder);

  if ( mIsSetOrder == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'order' from the <SedSubTask> "
        "element must be an integer.";
      log->logError(SedmlSubTaskOrderMustBeInteger, level, version, message,
        getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'order' is missing from the "
        "<SedSubTask> element.";
      log->logError(SedmlSubTaskAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // task SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("task", mTask);

  if (assigned == true)
  {
    if (mTask.empty() == true)
    {
      logEmptyString(mTask, level, version, "<SedSubTask>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mTask) == false)
    {
      std::string msg = "The task attribute on the <" + getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTask + "', which does not conform to the syntax.";
      logError(SedmlSubTaskTaskMustBeAbstractTask, level, version, msg,
        getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'task' is missing from the "
        "<SedSubTask> element.";
      log->logError(SedmlSubTaskAllowedAttributes, level, version, message,
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
SedSubTask::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetOrder() == true)
  {
    stream.writeAttribute("order", getPrefix(), mOrder);
  }

  if (isSetTask() == true)
  {
    stream.writeAttribute("task", getPrefix(), mTask);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSubTask_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedSubTask_t *
SedSubTask_create(unsigned int level, unsigned int version)
{
  return new SedSubTask(level, version);
}


/*
 * Creates and returns a deep copy of this SedSubTask_t object.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedSubTask_clone(const SedSubTask_t* sst)
{
  if (sst != NULL)
  {
    return static_cast<SedSubTask_t*>(sst->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSubTask_t object.
 */
LIBSEDML_EXTERN
void
SedSubTask_free(SedSubTask_t* sst)
{
  if (sst != NULL)
  {
    delete sst;
  }
}


/*
 * Returns the value of the "order" attribute of this SedSubTask_t.
 */
LIBSEDML_EXTERN
int
SedSubTask_getOrder(const SedSubTask_t * sst)
{
  return (sst != NULL) ? sst->getOrder() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "task" attribute of this SedSubTask_t.
 */
LIBSEDML_EXTERN
char *
SedSubTask_getTask(const SedSubTask_t * sst)
{
  if (sst == NULL)
  {
    return NULL;
  }

  return sst->getTask().empty() ? NULL : safe_strdup(sst->getTask().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedSubTask_t's "order" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSubTask_isSetOrder(const SedSubTask_t * sst)
{
  return (sst != NULL) ? static_cast<int>(sst->isSetOrder()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSubTask_t's "task" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSubTask_isSetTask(const SedSubTask_t * sst)
{
  return (sst != NULL) ? static_cast<int>(sst->isSetTask()) : 0;
}


/*
 * Sets the value of the "order" attribute of this SedSubTask_t.
 */
LIBSEDML_EXTERN
int
SedSubTask_setOrder(SedSubTask_t * sst, int order)
{
  return (sst != NULL) ? sst->setOrder(order) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "task" attribute of this SedSubTask_t.
 */
LIBSEDML_EXTERN
int
SedSubTask_setTask(SedSubTask_t * sst, const char * task)
{
  return (sst != NULL) ? sst->setTask(task) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "order" attribute of this SedSubTask_t.
 */
LIBSEDML_EXTERN
int
SedSubTask_unsetOrder(SedSubTask_t * sst)
{
  return (sst != NULL) ? sst->unsetOrder() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "task" attribute of this SedSubTask_t.
 */
LIBSEDML_EXTERN
int
SedSubTask_unsetTask(SedSubTask_t * sst)
{
  return (sst != NULL) ? sst->unsetTask() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedSetValue_t objects from this
 * SedSubTask_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedSubTask_getListOfTaskChanges(SedSubTask_t* srt)
{
    return (srt != NULL) ? srt->getListOfTaskChanges() : NULL;
}


/*
 * Get a SedSetValue_t from the SedSubTask_t.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedSubTask_getTaskChange(SedSubTask_t* srt, unsigned int n)
{
    return (srt != NULL) ? srt->getTaskChange(n) : NULL;
}


/*
 * Get a SedSetValue_t from the SedSubTask_t based on the ModelReference
 * to which it refers.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedSubTask_getTaskChangeByModelReference(SedSubTask_t* srt,
    const char* sid)
{
    return (srt != NULL && sid != NULL) ? srt->getTaskChangeByModelReference(sid)
        : NULL;
}


/*
 * Get a SedSetValue_t from the SedSubTask_t based on the Range to which
 * it refers.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedSubTask_getTaskChangeByRange(SedSubTask_t* srt, const char* sid)
{
    return (srt != NULL && sid != NULL) ? srt->getTaskChangeByRange(sid) : NULL;
}


/*
 * Adds a copy of the given SedSetValue_t to this SedSubTask_t.
 */
LIBSEDML_EXTERN
int
SedSubTask_addTaskChange(SedSubTask_t* srt,
    const SedSetValue_t* ssv)
{
    return (srt != NULL) ? srt->addTaskChange(ssv) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedSetValue_t objects in this SedSubTask_t.
 */
LIBSEDML_EXTERN
unsigned int
SedSubTask_getNumTaskChanges(SedSubTask_t* srt)
{
    return (srt != NULL) ? srt->getNumTaskChanges() : SEDML_INT_MAX;
}


/*
 * Creates a new SedSetValue_t object, adds it to this SedSubTask_t object
 * and returns the SedSetValue_t object created.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedSubTask_createTaskChange(SedSubTask_t* srt)
{
    return (srt != NULL) ? srt->createTaskChange() : NULL;
}


/*
 * Removes the nth SedSetValue_t from this SedSubTask_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedSubTask_removeTaskChange(SedSubTask_t* srt, unsigned int n)
{
    return (srt != NULL) ? srt->removeTaskChange(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSubTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSubTask_hasRequiredAttributes(const SedSubTask_t * sst)
{
  return (sst != NULL) ? static_cast<int>(sst->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


