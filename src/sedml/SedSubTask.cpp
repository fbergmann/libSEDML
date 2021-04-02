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
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

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
        log->logError(SedmlRepeatedTaskLOSubTasksAllowedCoreAttributes, level,
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


