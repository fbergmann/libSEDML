/**
 * @file SedSimpleRepeatedTask.cpp
 * @brief Implementation of the SedSimpleRepeatedTask class.
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
#include <sedml/SedSimpleRepeatedTask.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSimpleRepeatedTask using the given SED-ML Level and @ p
 * version values.
 */
SedSimpleRepeatedTask::SedSimpleRepeatedTask(unsigned int level,
                                             unsigned int version)
  : SedTask(level, version)
  , mResetModel (false)
  , mIsSetResetModel (false)
  , mNumRepeats (SEDML_INT_MAX)
  , mIsSetNumRepeats (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSimpleRepeatedTask using the given SedNamespaces object @p
 * sedmlns.
 */
SedSimpleRepeatedTask::SedSimpleRepeatedTask(SedNamespaces *sedmlns)
  : SedTask(sedmlns)
  , mResetModel (false)
  , mIsSetResetModel (false)
  , mNumRepeats (SEDML_INT_MAX)
  , mIsSetNumRepeats (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedSimpleRepeatedTask.
 */
SedSimpleRepeatedTask::SedSimpleRepeatedTask(const SedSimpleRepeatedTask& orig)
  : SedTask( orig )
  , mResetModel ( orig.mResetModel )
  , mIsSetResetModel ( orig.mIsSetResetModel )
  , mNumRepeats ( orig.mNumRepeats )
  , mIsSetNumRepeats ( orig.mIsSetNumRepeats )
{
}


/*
 * Assignment operator for SedSimpleRepeatedTask.
 */
SedSimpleRepeatedTask&
SedSimpleRepeatedTask::operator=(const SedSimpleRepeatedTask& rhs)
{
  if (&rhs != this)
  {
    SedTask::operator=(rhs);
    mResetModel = rhs.mResetModel;
    mIsSetResetModel = rhs.mIsSetResetModel;
    mNumRepeats = rhs.mNumRepeats;
    mIsSetNumRepeats = rhs.mIsSetNumRepeats;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSimpleRepeatedTask object.
 */
SedSimpleRepeatedTask*
SedSimpleRepeatedTask::clone() const
{
  return new SedSimpleRepeatedTask(*this);
}


/*
 * Destructor for SedSimpleRepeatedTask.
 */
SedSimpleRepeatedTask::~SedSimpleRepeatedTask()
{
}


/*
 * Returns the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask.
 */
bool
SedSimpleRepeatedTask::getResetModel() const
{
  return mResetModel;
}


/*
 * Returns the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::getNumRepeats() const
{
  return mNumRepeats;
}


/*
 * Predicate returning @c true if this SedSimpleRepeatedTask's "resetModel"
 * attribute is set.
 */
bool
SedSimpleRepeatedTask::isSetResetModel() const
{
  return mIsSetResetModel;
}


/*
 * Predicate returning @c true if this SedSimpleRepeatedTask's "numRepeats"
 * attribute is set.
 */
bool
SedSimpleRepeatedTask::isSetNumRepeats() const
{
  return mIsSetNumRepeats;
}


/*
 * Sets the value of the "resetModel" attribute of this SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::setResetModel(bool resetModel)
{
  mResetModel = resetModel;
  mIsSetResetModel = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "numRepeats" attribute of this SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::setNumRepeats(int numRepeats)
{
  mNumRepeats = numRepeats;
  mIsSetNumRepeats = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::unsetResetModel()
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
 * Unsets the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::unsetNumRepeats()
{
  mNumRepeats = SEDML_INT_MAX;
  mIsSetNumRepeats = false;

  if (isSetNumRepeats() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedSimpleRepeatedTask object.
 */
const std::string&
SedSimpleRepeatedTask::getElementName() const
{
  static const string name = "simpleRepeatedTask";
  return name;
}


/*
 * Returns the libSEDML type code for this SedSimpleRepeatedTask object.
 */
int
SedSimpleRepeatedTask::getTypeCode() const
{
  return SEDML_TASK_SIMPLEREPEATEDTASK;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedSimpleRepeatedTask object have been set.
 */
bool
SedSimpleRepeatedTask::hasRequiredAttributes() const
{
  bool allPresent = SedTask::hasRequiredAttributes();

  if (isSetResetModel() == false)
  {
    allPresent = false;
  }

  if (isSetNumRepeats() == false)
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
SedSimpleRepeatedTask::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedTask::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedSimpleRepeatedTask::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSimpleRepeatedTask::setSedDocument(SedDocument* d)
{
  SedTask::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::getAttribute(const std::string& attributeName,
                                    bool& value) const
{
  int return_value = SedTask::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "resetModel")
  {
    value = getResetModel();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::getAttribute(const std::string& attributeName,
                                    int& value) const
{
  int return_value = SedTask::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "numRepeats")
  {
    value = getNumRepeats();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::getAttribute(const std::string& attributeName,
                                    double& value) const
{
  int return_value = SedTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::getAttribute(const std::string& attributeName,
                                    unsigned int& value) const
{
  int return_value = SedTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::getAttribute(const std::string& attributeName,
                                    std::string& value) const
{
  int return_value = SedTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedSimpleRepeatedTask's attribute
 * "attributeName" is set.
 */
bool
SedSimpleRepeatedTask::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedTask::isSetAttribute(attributeName);

  if (attributeName == "resetModel")
  {
    value = isSetResetModel();
  }
  else if (attributeName == "numRepeats")
  {
    value = isSetNumRepeats();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::setAttribute(const std::string& attributeName,
                                    bool value)
{
  int return_value = SedTask::setAttribute(attributeName, value);

  if (attributeName == "resetModel")
  {
    return_value = setResetModel(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::setAttribute(const std::string& attributeName,
                                    int value)
{
  int return_value = SedTask::setAttribute(attributeName, value);

  if (attributeName == "numRepeats")
  {
    return_value = setNumRepeats(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::setAttribute(const std::string& attributeName,
                                    double value)
{
  int return_value = SedTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::setAttribute(const std::string& attributeName,
                                    unsigned int value)
{
  int return_value = SedTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::setAttribute(const std::string& attributeName,
                                    const std::string& value)
{
  int return_value = SedTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedSimpleRepeatedTask.
 */
int
SedSimpleRepeatedTask::unsetAttribute(const std::string& attributeName)
{
  int value = SedTask::unsetAttribute(attributeName);

  if (attributeName == "resetModel")
  {
    value = unsetResetModel();
  }
  else if (attributeName == "numRepeats")
  {
    value = unsetNumRepeats();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedSimpleRepeatedTask::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = SedTask::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSimpleRepeatedTask::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedTask::addExpectedAttributes(attributes);

  attributes.add("resetModel");

  attributes.add("numRepeats");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSimpleRepeatedTask::readAttributes(
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

  SedTask::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlSimpleRepeatedTaskAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // resetModel bool (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetResetModel = attributes.readInto("resetModel", mResetModel);

  if (log && mIsSetResetModel == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlSimpleRepeatedTaskResetModelMustBeBoolean, level,
        version);
    }
    else
    {
      std::string message = "Sedml attribute 'resetModel' is missing from the "
        "<SedSimpleRepeatedTask> element.";
      log->logError(SedmlSimpleRepeatedTaskAllowedAttributes, level, version,
        message);
    }
  }

  // 
  // numRepeats int (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetNumRepeats = attributes.readInto("numRepeats", mNumRepeats);

  if ( mIsSetNumRepeats == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'numRepeats' from the "
        "<SedSimpleRepeatedTask> element must be an integer.";
      log->logError(SedmlSimpleRepeatedTaskNumRepeatsMustBeInteger, level,
        version, message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'numRepeats' is missing from the "
        "<SedSimpleRepeatedTask> element.";
      log->logError(SedmlSimpleRepeatedTaskAllowedAttributes, level, version,
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
SedSimpleRepeatedTask::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedTask::writeAttributes(stream);

  if (isSetResetModel() == true)
  {
    stream.writeAttribute("resetModel", getPrefix(), mResetModel);
  }

  if (isSetNumRepeats() == true)
  {
    stream.writeAttribute("numRepeats", getPrefix(), mNumRepeats);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSimpleRepeatedTask_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedSimpleRepeatedTask_t *
SedSimpleRepeatedTask_create(unsigned int level, unsigned int version)
{
  return new SedSimpleRepeatedTask(level, version);
}


/*
 * Creates and returns a deep copy of this SedSimpleRepeatedTask_t object.
 */
LIBSEDML_EXTERN
SedSimpleRepeatedTask_t*
SedSimpleRepeatedTask_clone(const SedSimpleRepeatedTask_t* ssrt)
{
  if (ssrt != NULL)
  {
    return static_cast<SedSimpleRepeatedTask_t*>(ssrt->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSimpleRepeatedTask_t object.
 */
LIBSEDML_EXTERN
void
SedSimpleRepeatedTask_free(SedSimpleRepeatedTask_t* ssrt)
{
  if (ssrt != NULL)
  {
    delete ssrt;
  }
}


/*
 * Returns the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_getResetModel(const SedSimpleRepeatedTask_t * ssrt)
{
  return (ssrt != NULL) ? static_cast<int>(ssrt->getResetModel()) : 0;
}


/*
 * Returns the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_getNumRepeats(const SedSimpleRepeatedTask_t * ssrt)
{
  return (ssrt != NULL) ? ssrt->getNumRepeats() : SEDML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this SedSimpleRepeatedTask_t's
 * "resetModel" attribute is set.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_isSetResetModel(const SedSimpleRepeatedTask_t * ssrt)
{
  return (ssrt != NULL) ? static_cast<int>(ssrt->isSetResetModel()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSimpleRepeatedTask_t's
 * "numRepeats" attribute is set.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_isSetNumRepeats(const SedSimpleRepeatedTask_t * ssrt)
{
  return (ssrt != NULL) ? static_cast<int>(ssrt->isSetNumRepeats()) : 0;
}


/*
 * Sets the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_setResetModel(SedSimpleRepeatedTask_t * ssrt,
                                    int resetModel)
{
  return (ssrt != NULL) ? ssrt->setResetModel(resetModel) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_setNumRepeats(SedSimpleRepeatedTask_t * ssrt,
                                    int numRepeats)
{
  return (ssrt != NULL) ? ssrt->setNumRepeats(numRepeats) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_unsetResetModel(SedSimpleRepeatedTask_t * ssrt)
{
  return (ssrt != NULL) ? ssrt->unsetResetModel() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_unsetNumRepeats(SedSimpleRepeatedTask_t * ssrt)
{
  return (ssrt != NULL) ? ssrt->unsetNumRepeats() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSimpleRepeatedTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_hasRequiredAttributes(const SedSimpleRepeatedTask_t *
  ssrt)
{
  return (ssrt != NULL) ? static_cast<int>(ssrt->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


