/**
 * @file SedAdjustableParameter.cpp
 * @brief Implementation of the SedAdjustableParameter class.
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
#include <sedml/SedAdjustableParameter.h>
#include <sedml/SedListOfAdjustableParameters.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAdjustableParameter using the given SED-ML Level and @ p
 * version values.
 */
SedAdjustableParameter::SedAdjustableParameter(unsigned int level,
                                               unsigned int version)
  : SedBase(level, version)
  , mInitialValue (util_NaN())
  , mIsSetInitialValue (false)
  , mBounds (NULL)
  , mExperimentReferences (level, version)
  , mModelReference ("")
  , mTarget ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedAdjustableParameter using the given SedNamespaces object @p
 * sedmlns.
 */
SedAdjustableParameter::SedAdjustableParameter(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mInitialValue (util_NaN())
  , mIsSetInitialValue (false)
  , mBounds (NULL)
  , mExperimentReferences (sedmlns)
  , mModelReference ("")
  , mTarget ("")
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedAdjustableParameter.
 */
SedAdjustableParameter::SedAdjustableParameter(const SedAdjustableParameter&
  orig)
  : SedBase( orig )
  , mInitialValue ( orig.mInitialValue )
  , mIsSetInitialValue ( orig.mIsSetInitialValue )
  , mBounds ( NULL )
  , mExperimentReferences ( orig.mExperimentReferences )
  , mModelReference ( orig.mModelReference )
  , mTarget ( orig.mTarget )
{
  if (orig.mBounds != NULL)
  {
    mBounds = orig.mBounds->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedAdjustableParameter.
 */
SedAdjustableParameter&
SedAdjustableParameter::operator=(const SedAdjustableParameter& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mInitialValue = rhs.mInitialValue;
    mIsSetInitialValue = rhs.mIsSetInitialValue;
    mExperimentReferences = rhs.mExperimentReferences;
    mModelReference = rhs.mModelReference;
    mTarget = rhs.mTarget;
    delete mBounds;
    if (rhs.mBounds != NULL)
    {
      mBounds = rhs.mBounds->clone();
    }
    else
    {
      mBounds = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAdjustableParameter object.
 */
SedAdjustableParameter*
SedAdjustableParameter::clone() const
{
  return new SedAdjustableParameter(*this);
}


/*
 * Destructor for SedAdjustableParameter.
 */
SedAdjustableParameter::~SedAdjustableParameter()
{
  delete mBounds;
  mBounds = NULL;
}


/*
 * Returns the value of the "initialValue" attribute of this
 * SedAdjustableParameter.
 */
double
SedAdjustableParameter::getInitialValue() const
{
  return mInitialValue;
}


/*
 * Returns the value of the "modelReference" attribute of this
 * SedAdjustableParameter.
 */
const std::string&
SedAdjustableParameter::getModelReference() const
{
  return mModelReference;
}


/*
 * Returns the value of the "target" attribute of this SedAdjustableParameter.
 */
const std::string&
SedAdjustableParameter::getTarget() const
{
  return mTarget;
}


/*
 * Predicate returning @c true if this SedAdjustableParameter's "initialValue"
 * attribute is set.
 */
bool
SedAdjustableParameter::isSetInitialValue() const
{
  return mIsSetInitialValue;
}


/*
 * Predicate returning @c true if this SedAdjustableParameter's
 * "modelReference" attribute is set.
 */
bool
SedAdjustableParameter::isSetModelReference() const
{
  return (mModelReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedAdjustableParameter's "target"
 * attribute is set.
 */
bool
SedAdjustableParameter::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Sets the value of the "initialValue" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setInitialValue(double initialValue)
{
  mInitialValue = initialValue;
  mIsSetInitialValue = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "modelReference" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setModelReference(const std::string& modelReference)
{
  if (!(SyntaxChecker::isValidInternalSId(modelReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mModelReference = modelReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "target" attribute of this SedAdjustableParameter.
 */
int
SedAdjustableParameter::setTarget(const std::string& target)
{
  mTarget = target;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "initialValue" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetInitialValue()
{
  mInitialValue = util_NaN();
  mIsSetInitialValue = false;

  if (isSetInitialValue() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "modelReference" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetModelReference()
{
  mModelReference.erase();

  if (mModelReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "target" attribute of this SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetTarget()
{
  mTarget.erase();

  if (mTarget.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "bounds" element of this SedAdjustableParameter.
 */
const SedBounds*
SedAdjustableParameter::getBounds() const
{
  return mBounds;
}


/*
 * Returns the value of the "bounds" element of this SedAdjustableParameter.
 */
SedBounds*
SedAdjustableParameter::getBounds()
{
  return mBounds;
}


/*
 * Predicate returning @c true if this SedAdjustableParameter's "bounds"
 * element is set.
 */
bool
SedAdjustableParameter::isSetBounds() const
{
  return (mBounds != NULL);
}


/*
 * Sets the value of the "bounds" element of this SedAdjustableParameter.
 */
int
SedAdjustableParameter::setBounds(const SedBounds* bounds)
{
  if (mBounds == bounds)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (bounds == NULL)
  {
    delete mBounds;
    mBounds = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mBounds;
    mBounds = (bounds != NULL) ? bounds->clone() : NULL;
    if (mBounds != NULL)
    {
      mBounds->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedBounds object, adds it to this SedAdjustableParameter
 * object and returns the SedBounds object created.
 */
SedBounds*
SedAdjustableParameter::createBounds()
{
  if (mBounds != NULL)
  {
    delete mBounds;
  }

  mBounds = new SedBounds(getSedNamespaces());

  connectToChild();

  return mBounds;
}


/*
 * Unsets the value of the "bounds" element of this SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetBounds()
{
  delete mBounds;
  mBounds = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfExperimentReferences from this SedAdjustableParameter.
 */
const SedListOfExperimentReferences*
SedAdjustableParameter::getListOfExperimentReferences() const
{
  return &mExperimentReferences;
}


/*
 * Returns the SedListOfExperimentReferences from this SedAdjustableParameter.
 */
SedListOfExperimentReferences*
SedAdjustableParameter::getListOfExperimentReferences()
{
  return &mExperimentReferences;
}


/*
 * Get a SedExperimentReference from the SedAdjustableParameter.
 */
SedExperimentReference*
SedAdjustableParameter::getExperimentReference(unsigned int n)
{
  return mExperimentReferences.get(n);
}


/*
 * Get a SedExperimentReference from the SedAdjustableParameter.
 */
const SedExperimentReference*
SedAdjustableParameter::getExperimentReference(unsigned int n) const
{
  return mExperimentReferences.get(n);
}


/*
 * Get a SedExperimentReference from the SedAdjustableParameter based on the
 * ExperimentId to which it refers.
 */
const SedExperimentReference*
SedAdjustableParameter::getExperimentReferenceByExperimentId(const std::string& sid)
  const
{
  return mExperimentReferences.getByExperimentId(sid);
}


/*
 * Get a SedExperimentReference from the SedAdjustableParameter based on the
 * ExperimentId to which it refers.
 */
SedExperimentReference*
SedAdjustableParameter::getExperimentReferenceByExperimentId(const std::string& sid)
{
  return mExperimentReferences.getByExperimentId(sid);
}


/*
 * Adds a copy of the given SedExperimentReference to this SedAdjustableParameter.
 */
int
SedAdjustableParameter::addExperimentReference(const SedExperimentReference* ser)
{
  if (ser == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ser->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ser->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ser->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ser)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mExperimentReferences.append(ser);
  }
}


/*
 * Get the number of SedExperimentReference objects in this SedAdjustableParameter.
 */
unsigned int
SedAdjustableParameter::getNumExperimentReferences() const
{
  return mExperimentReferences.size();
}


/*
 * Creates a new SedExperimentReference object, adds it to this
 * SedAdjustableParameter object and returns the SedExperimentReference object
 * created.
 */
SedExperimentReference*
SedAdjustableParameter::createExperimentReference()
{
  SedExperimentReference* ser = NULL;

  try
  {
    ser = new SedExperimentReference(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ser != NULL)
  {
    mExperimentReferences.appendAndOwn(ser);
  }

  return ser;
}


/*
 * Removes the nth SedExperimentReference from this SedAdjustableParameter and
 * returns a pointer to it.
 */
SedExperimentReference*
SedAdjustableParameter::removeExperimentReference(unsigned int n)
{
  return mExperimentReferences.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedAdjustableParameter::renameSIdRefs(const std::string& oldid,
                                      const std::string& newid)
{
  if (isSetModelReference() && mModelReference == oldid)
  {
    setModelReference(newid);
  }
}


/*
 * Returns the XML element name of this SedAdjustableParameter object.
 */
const std::string&
SedAdjustableParameter::getElementName() const
{
  static const string name = "adjustableParameter";
  return name;
}


/*
 * Returns the libSEDML type code for this SedAdjustableParameter object.
 */
int
SedAdjustableParameter::getTypeCode() const
{
  return SEDML_ADJUSTABLE_PARAMETER;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAdjustableParameter object have been set.
 */
bool
SedAdjustableParameter::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedAdjustableParameter object have been set.
 */
bool
SedAdjustableParameter::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetBounds() == false)
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
SedAdjustableParameter::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (isSetBounds() == true)
  {
    mBounds->write(stream);
  }

  if (getNumExperimentReferences() > 0)
  {
    mExperimentReferences.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAdjustableParameter::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAdjustableParameter::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  if (mBounds != NULL)
  {
    mBounds->setSedDocument(d);
  }

  mExperimentReferences.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedAdjustableParameter::connectToChild()
{
  SedBase::connectToChild();

  if (mBounds != NULL)
  {
    mBounds->connectToParent(this);
  }

  mExperimentReferences.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "initialValue")
  {
    value = getInitialValue();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::getAttribute(const std::string& attributeName,
                                     std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "modelReference")
  {
    value = getModelReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedAdjustableParameter's attribute
 * "attributeName" is set.
 */
bool
SedAdjustableParameter::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "initialValue")
  {
    value = isSetInitialValue();
  }
  else if (attributeName == "modelReference")
  {
    value = isSetModelReference();
  }
  else if (attributeName == "target")
  {
    value = isSetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "initialValue")
  {
    return_value = setInitialValue(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::setAttribute(const std::string& attributeName,
                                     const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "modelReference")
  {
    return_value = setModelReference(value);
  }
  else if (attributeName == "target")
  {
    return_value = setTarget(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedAdjustableParameter.
 */
int
SedAdjustableParameter::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "initialValue")
  {
    value = unsetInitialValue();
  }
  else if (attributeName == "modelReference")
  {
    value = unsetModelReference();
  }
  else if (attributeName == "target")
  {
    value = unsetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this
 * SedAdjustableParameter.
 */
SedBase*
SedAdjustableParameter::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "bounds")
  {
    return createBounds();
  }
  else if (elementName == "experimentReference")
  {
    return createExperimentReference();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedAdjustableParameter.
 */
int
SedAdjustableParameter::addChildObject(const std::string& elementName,
                                       const SedBase* element)
{
  if (elementName == "bounds" && element->getTypeCode() == SEDML_BOUNDS)
  {
    return setBounds((const SedBounds*)(element));
  }
  else if (elementName == "experimentReference" && element->getTypeCode() ==
    SEDML_EXPERIMENT_REFERENCE)
  {
    return addExperimentReference((const SedExperimentReference*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedAdjustableParameter.
 */
SedBase*
SedAdjustableParameter::removeChildObject(const std::string& elementName,
                                          const std::string& id)
{
  if (elementName == "bounds")
  {
    SedBounds * obj = mBounds;
    mBounds = NULL; return obj;
  }
  else if (elementName == "experimentReference")
  {
    for (unsigned int i = 0; i < getNumExperimentReferences(); i++)
    {
      if (getExperimentReference(i)->getId() == id)
      {
        return removeExperimentReference(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedAdjustableParameter.
 */
unsigned int
SedAdjustableParameter::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "bounds")
  {
    if (isSetBounds())
    {
      return 1;
    }
  }
  else if (elementName == "experimentReference")
  {
    return getNumExperimentReferences();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedAdjustableParameter.
 */
SedBase*
SedAdjustableParameter::getObject(const std::string& elementName,
                                  unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "bounds")
  {
    return getBounds();
  }
  else if (elementName == "experimentReference")
  {
    return getExperimentReference(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedAdjustableParameter::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mBounds != NULL)
  {
    if (mBounds->getId() == id)
    {
      return mBounds;
    }

    obj = mBounds->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mExperimentReferences.getElementBySId(id);

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
SedAdjustableParameter::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  SED_ADD_FILTERED_POINTER(ret, sublist, mBounds, filter);

  SED_ADD_FILTERED_LIST(ret, sublist, mExperimentReferences, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedAdjustableParameter::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "bounds")
  {
    if (getErrorLog() && isSetBounds())
    {
      getErrorLog()->logError(SedmlAdjustableParameterAllowedElements,
        getLevel(), getVersion(), "", getLine(), getColumn());
    }

    delete mBounds;
    mBounds = new SedBounds(getSedNamespaces());
    obj = mBounds;
  }
  else if (name == "listOfExperimentReferences")
  {
    if (getErrorLog() && mExperimentReferences.size() != 0)
    {
      getErrorLog()->logError(SedmlAdjustableParameterAllowedElements,
        getLevel(), getVersion(), "", getLine(), getColumn());
    }

    obj = &mExperimentReferences;
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
SedAdjustableParameter::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("initialValue");

  attributes.add("modelReference");

  attributes.add("target");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAdjustableParameter::readAttributes(
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
    static_cast<SedListOfAdjustableParameters*>(getParentSedObject())->size() <
      2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlParameterEstimationTaskLOAdjustableParametersAllowedCoreAttributes,
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
        log->logError(SedmlAdjustableParameterAllowedAttributes, level,
          version, details, getLine(), getColumn());
      }
    }
  }

  // 
  // initialValue double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetInitialValue = attributes.readInto("initialValue", mInitialValue);

  if ( mIsSetInitialValue == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'initialValue' from the "
        "<SedAdjustableParameter> element must be an integer.";
      log->logError(SedmlAdjustableParameterInitialValueMustBeDouble, level,
        version, message, getLine(), getColumn());
    }
  }

  // 
  // modelReference SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("modelReference", mModelReference);

  if (assigned == true)
  {
    if (mModelReference.empty() == true)
    {
      logEmptyString(mModelReference, level, version,
        "<SedAdjustableParameter>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
    {
      std::string msg = "The modelReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mModelReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlAdjustableParameterModelReferenceMustBeModel, level,
        version, msg);
    }
  }

  // 
  // target string (use = "optional" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<SedAdjustableParameter>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedAdjustableParameter::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetInitialValue() == true)
  {
    stream.writeAttribute("initialValue", getPrefix(), mInitialValue);
  }

  if (isSetModelReference() == true)
  {
    stream.writeAttribute("modelReference", getPrefix(), mModelReference);
  }

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedAdjustableParameter_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t *
SedAdjustableParameter_create(unsigned int level, unsigned int version)
{
  return new SedAdjustableParameter(level, version);
}


/*
 * Creates and returns a deep copy of this SedAdjustableParameter_t object.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedAdjustableParameter_clone(const SedAdjustableParameter_t* sap)
{
  if (sap != NULL)
  {
    return static_cast<SedAdjustableParameter_t*>(sap->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAdjustableParameter_t object.
 */
LIBSEDML_EXTERN
void
SedAdjustableParameter_free(SedAdjustableParameter_t* sap)
{
  if (sap != NULL)
  {
    delete sap;
  }
}


/*
 * Returns the value of the "initialValue" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
double
SedAdjustableParameter_getInitialValue(const SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? sap->getInitialValue() : util_NaN();
}


/*
 * Returns the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
char *
SedAdjustableParameter_getModelReference(const SedAdjustableParameter_t * sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return sap->getModelReference().empty() ? NULL :
    safe_strdup(sap->getModelReference().c_str());
}


/*
 * Returns the value of the "target" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
char *
SedAdjustableParameter_getTarget(const SedAdjustableParameter_t * sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return sap->getTarget().empty() ? NULL :
    safe_strdup(sap->getTarget().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's
 * "initialValue" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetInitialValue(const SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetInitialValue()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's
 * "modelReference" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetModelReference(const SedAdjustableParameter_t *
  sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetModelReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's "target"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetTarget(const SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetTarget()) : 0;
}


/*
 * Sets the value of the "initialValue" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setInitialValue(SedAdjustableParameter_t * sap,
                                       double initialValue)
{
  return (sap != NULL) ? sap->setInitialValue(initialValue) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setModelReference(SedAdjustableParameter_t * sap,
                                         const char * modelReference)
{
  return (sap != NULL) ? sap->setModelReference(modelReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "target" attribute of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setTarget(SedAdjustableParameter_t * sap,
                                 const char * target)
{
  return (sap != NULL) ? sap->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "initialValue" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetInitialValue(SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetInitialValue() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetModelReference(SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetTarget(SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "bounds" element of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
const SedBounds_t*
SedAdjustableParameter_getBounds(const SedAdjustableParameter_t * sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return (SedBounds_t*)(sap->getBounds());
}


/*
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's "bounds"
 * element is set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetBounds(const SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetBounds()) : 0;
}


/*
 * Sets the value of the "bounds" element of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setBounds(SedAdjustableParameter_t * sap,
                                 const SedBounds_t* bounds)
{
  return (sap != NULL) ? sap->setBounds(bounds) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedBounds_t object, adds it to this SedAdjustableParameter_t
 * object and returns the SedBounds_t object created.
 */
LIBSEDML_EXTERN
SedBounds_t*
SedAdjustableParameter_createBounds(SedAdjustableParameter_t* sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return (SedBounds_t*)(sap->createBounds());
}


/*
 * Unsets the value of the "bounds" element of this SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetBounds(SedAdjustableParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetBounds() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedExperimentReference_t objects from this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedAdjustableParameter_getListOfExperimentReferences(SedAdjustableParameter_t* sap)
{
  return (sap != NULL) ? sap->getListOfExperimentReferences() : NULL;
}


/*
 * Get a SedExperimentReference_t from the SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedAdjustableParameter_getExperimentReference(SedAdjustableParameter_t* sap,
                                        unsigned int n)
{
  return (sap != NULL) ? sap->getExperimentReference(n) : NULL;
}


/*
 * Get a SedExperimentReference_t from the SedAdjustableParameter_t based on the
 * ExperimentId to which it refers.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedAdjustableParameter_getExperimentReferenceByExperimentId(
                                                      SedAdjustableParameter_t*
                                                        sap,
                                                      const char *sid)
{
  return (sap != NULL && sid != NULL) ?
    sap->getExperimentReferenceByExperimentId(sid) : NULL;
}


/*
 * Adds a copy of the given SedExperimentReference_t to this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_addExperimentReference(SedAdjustableParameter_t* sap,
                                        const SedExperimentReference_t* ser)
{
  return (sap != NULL) ? sap->addExperimentReference(ser) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedExperimentReference_t objects in this
 * SedAdjustableParameter_t.
 */
LIBSEDML_EXTERN
unsigned int
SedAdjustableParameter_getNumExperimentReferences(SedAdjustableParameter_t* sap)
{
  return (sap != NULL) ? sap->getNumExperimentReferences() : SEDML_INT_MAX;
}


/*
 * Creates a new SedExperimentReference_t object, adds it to this
 * SedAdjustableParameter_t object and returns the SedExperimentReference_t object
 * created.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedAdjustableParameter_createExperimentReference(SedAdjustableParameter_t* sap)
{
  return (sap != NULL) ? sap->createExperimentReference() : NULL;
}


/*
 * Removes the nth SedExperimentReference_t from this SedAdjustableParameter_t and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedAdjustableParameter_removeExperimentReference(SedAdjustableParameter_t* sap,
                                           unsigned int n)
{
  return (sap != NULL) ? sap->removeExperimentReference(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAdjustableParameter_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_hasRequiredAttributes(const SedAdjustableParameter_t *
  sap)
{
  return (sap != NULL) ? static_cast<int>(sap->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedAdjustableParameter_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_hasRequiredElements(const SedAdjustableParameter_t *
  sap)
{
  return (sap != NULL) ? static_cast<int>(sap->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


