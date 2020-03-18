/**
 * @file SedVariable.cpp
 * @brief Implementation of the SedVariable class.
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
#include <sedml/SedVariable.h>
#include <sedml/SedListOfVariables.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedVariable using the given SEDML Level and @ p version
 * values.
 */
SedVariable::SedVariable(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mName ("")
  , mSymbol ("")
  , mTarget ("")
  , mTaskReference ("")
  , mModelReference ("")
  , mRemainingDimensions (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedVariable using the given SedNamespaces object @p sedmlns.
 */
SedVariable::SedVariable(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mName ("")
  , mSymbol ("")
  , mTarget ("")
  , mTaskReference ("")
  , mModelReference ("")
  , mRemainingDimensions (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedVariable.
 */
SedVariable::SedVariable(const SedVariable& orig)
  : SedBase( orig )
  , mName ( orig.mName )
  , mSymbol ( orig.mSymbol )
  , mTarget ( orig.mTarget )
  , mTaskReference ( orig.mTaskReference )
  , mModelReference ( orig.mModelReference )
  , mRemainingDimensions ( orig.mRemainingDimensions )
{
  connectToChild();
}


/*
 * Assignment operator for SedVariable.
 */
SedVariable&
SedVariable::operator=(const SedVariable& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mName = rhs.mName;
    mSymbol = rhs.mSymbol;
    mTarget = rhs.mTarget;
    mTaskReference = rhs.mTaskReference;
    mModelReference = rhs.mModelReference;
    mRemainingDimensions = rhs.mRemainingDimensions;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedVariable object.
 */
SedVariable*
SedVariable::clone() const
{
  return new SedVariable(*this);
}


/*
 * Destructor for SedVariable.
 */
SedVariable::~SedVariable()
{
}


/*
 * Returns the value of the "id" attribute of this SedVariable.
 */
const std::string&
SedVariable::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this SedVariable.
 */
const std::string&
SedVariable::getName() const
{
  return mName;
}


/*
 * Returns the value of the "symbol" attribute of this SedVariable.
 */
const std::string&
SedVariable::getSymbol() const
{
  return mSymbol;
}


/*
 * Returns the value of the "target" attribute of this SedVariable.
 */
const std::string&
SedVariable::getTarget() const
{
  return mTarget;
}


/*
 * Returns the value of the "taskReference" attribute of this SedVariable.
 */
const std::string&
SedVariable::getTaskReference() const
{
  return mTaskReference;
}


/*
 * Returns the value of the "modelReference" attribute of this SedVariable.
 */
const std::string&
SedVariable::getModelReference() const
{
  return mModelReference;
}


/*
 * Predicate returning @c true if this SedVariable's "id" attribute is set.
 */
bool
SedVariable::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SedVariable's "name" attribute is set.
 */
bool
SedVariable::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true if this SedVariable's "symbol" attribute is set.
 */
bool
SedVariable::isSetSymbol() const
{
  return (mSymbol.empty() == false);
}


/*
 * Predicate returning @c true if this SedVariable's "target" attribute is set.
 */
bool
SedVariable::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Predicate returning @c true if this SedVariable's "taskReference" attribute
 * is set.
 */
bool
SedVariable::isSetTaskReference() const
{
  return (mTaskReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedVariable's "modelReference" attribute
 * is set.
 */
bool
SedVariable::isSetModelReference() const
{
  return (mModelReference.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this SedVariable.
 */
int
SedVariable::setId(const std::string& id)
{
  mId = id;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "name" attribute of this SedVariable.
 */
int
SedVariable::setName(const std::string& name)
{
  mName = name;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "symbol" attribute of this SedVariable.
 */
int
SedVariable::setSymbol(const std::string& symbol)
{
  mSymbol = symbol;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "target" attribute of this SedVariable.
 */
int
SedVariable::setTarget(const std::string& target)
{
  mTarget = target;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "taskReference" attribute of this SedVariable.
 */
int
SedVariable::setTaskReference(const std::string& taskReference)
{
  if (!(SyntaxChecker::isValidInternalSId(taskReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTaskReference = taskReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "modelReference" attribute of this SedVariable.
 */
int
SedVariable::setModelReference(const std::string& modelReference)
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
 * Unsets the value of the "id" attribute of this SedVariable.
 */
int
SedVariable::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "name" attribute of this SedVariable.
 */
int
SedVariable::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "symbol" attribute of this SedVariable.
 */
int
SedVariable::unsetSymbol()
{
  mSymbol.erase();

  if (mSymbol.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "target" attribute of this SedVariable.
 */
int
SedVariable::unsetTarget()
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
 * Unsets the value of the "taskReference" attribute of this SedVariable.
 */
int
SedVariable::unsetTaskReference()
{
  mTaskReference.erase();

  if (mTaskReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "modelReference" attribute of this SedVariable.
 */
int
SedVariable::unsetModelReference()
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
 * Returns the SedListOfRemainingDimensions from this SedVariable.
 */
const SedListOfRemainingDimensions*
SedVariable::getListOfRemainingDimensions() const
{
  return &mRemainingDimensions;
}


/*
 * Returns the SedListOfRemainingDimensions from this SedVariable.
 */
SedListOfRemainingDimensions*
SedVariable::getListOfRemainingDimensions()
{
  return &mRemainingDimensions;
}


/*
 * Get a SedRemainingDimension from the SedVariable.
 */
SedRemainingDimension*
SedVariable::getRemainingDimension(unsigned int n)
{
  return mRemainingDimensions.get(n);
}


/*
 * Get a SedRemainingDimension from the SedVariable.
 */
const SedRemainingDimension*
SedVariable::getRemainingDimension(unsigned int n) const
{
  return mRemainingDimensions.get(n);
}


/*
 * Get a SedRemainingDimension from the SedVariable based on the Target to
 * which it refers.
 */
const SedRemainingDimension*
SedVariable::getRemainingDimensionByTarget(const std::string& sid) const
{
  return mRemainingDimensions.getByTarget(sid);
}


/*
 * Get a SedRemainingDimension from the SedVariable based on the Target to
 * which it refers.
 */
SedRemainingDimension*
SedVariable::getRemainingDimensionByTarget(const std::string& sid)
{
  return mRemainingDimensions.getByTarget(sid);
}


/*
 * Get a SedRemainingDimension from the SedVariable based on the
 * DimensionTarget to which it refers.
 */
const SedRemainingDimension*
SedVariable::getRemainingDimensionByDimensionTarget(const std::string& sid)
  const
{
  return mRemainingDimensions.getByDimensionTarget(sid);
}


/*
 * Get a SedRemainingDimension from the SedVariable based on the
 * DimensionTarget to which it refers.
 */
SedRemainingDimension*
SedVariable::getRemainingDimensionByDimensionTarget(const std::string& sid)
{
  return mRemainingDimensions.getByDimensionTarget(sid);
}


/*
 * Adds a copy of the given SedRemainingDimension to this SedVariable.
 */
int
SedVariable::addRemainingDimension(const SedRemainingDimension* srd)
{
  if (srd == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (srd->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != srd->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != srd->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(srd)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mRemainingDimensions.append(srd);
  }
}


/*
 * Get the number of SedRemainingDimension objects in this SedVariable.
 */
unsigned int
SedVariable::getNumRemainingDimensions() const
{
  return mRemainingDimensions.size();
}


/*
 * Creates a new SedRemainingDimension object, adds it to this SedVariable
 * object and returns the SedRemainingDimension object created.
 */
SedRemainingDimension*
SedVariable::createRemainingDimension()
{
  SedRemainingDimension* srd = NULL;

  try
  {
    srd = new SedRemainingDimension(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (srd != NULL)
  {
    mRemainingDimensions.appendAndOwn(srd);
  }

  return srd;
}


/*
 * Removes the nth SedRemainingDimension from this SedVariable and returns a
 * pointer to it.
 */
SedRemainingDimension*
SedVariable::removeRemainingDimension(unsigned int n)
{
  return mRemainingDimensions.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedVariable::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetTaskReference() && mTaskReference == oldid)
  {
    setTaskReference(newid);
  }

  if (isSetModelReference() && mModelReference == oldid)
  {
    setModelReference(newid);
  }
}


/*
 * Returns the XML element name of this SedVariable object.
 */
const std::string&
SedVariable::getElementName() const
{
  static const string name = "variable";
  return name;
}


/*
 * Returns the libSEDML type code for this SedVariable object.
 */
int
SedVariable::getTypeCode() const
{
  return SEDML_VARIABLE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedVariable object have been set.
 */
bool
SedVariable::hasRequiredAttributes() const
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
SedVariable::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (getNumRemainingDimensions() > 0)
  {
    mRemainingDimensions.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedVariable::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedVariable::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mRemainingDimensions.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedVariable::connectToChild()
{
  SedBase::connectToChild();

  mRemainingDimensions.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "name")
  {
    value = getName();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "symbol")
  {
    value = getSymbol();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "taskReference")
  {
    value = getTaskReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "modelReference")
  {
    value = getModelReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedVariable's attribute "attributeName"
 * is set.
 */
bool
SedVariable::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "name")
  {
    value = isSetName();
  }
  else if (attributeName == "symbol")
  {
    value = isSetSymbol();
  }
  else if (attributeName == "target")
  {
    value = isSetTarget();
  }
  else if (attributeName == "taskReference")
  {
    value = isSetTaskReference();
  }
  else if (attributeName == "modelReference")
  {
    value = isSetModelReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "name")
  {
    return_value = setName(value);
  }
  else if (attributeName == "symbol")
  {
    return_value = setSymbol(value);
  }
  else if (attributeName == "target")
  {
    return_value = setTarget(value);
  }
  else if (attributeName == "taskReference")
  {
    return_value = setTaskReference(value);
  }
  else if (attributeName == "modelReference")
  {
    return_value = setModelReference(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedVariable.
 */
int
SedVariable::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "name")
  {
    value = unsetName();
  }
  else if (attributeName == "symbol")
  {
    value = unsetSymbol();
  }
  else if (attributeName == "target")
  {
    value = unsetTarget();
  }
  else if (attributeName == "taskReference")
  {
    value = unsetTaskReference();
  }
  else if (attributeName == "modelReference")
  {
    value = unsetModelReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedVariable.
 */
SedBase*
SedVariable::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "remainingDimension")
  {
    return createRemainingDimension();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedVariable.
 */
int
SedVariable::addChildObject(const std::string& elementName,
                            const SedBase* element)
{
  if (elementName == "remainingDimension" && element->getTypeCode() ==
    SEDML_REMAININGDIMENSION)
  {
    return addRemainingDimension((const SedRemainingDimension*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedVariable.
 */
SedBase*
SedVariable::removeChildObject(const std::string& elementName,
                               const std::string& id)
{
  if (elementName == "remainingDimension")
  {
    for (unsigned int i = 0; i < getNumRemainingDimensions(); i++)
    {
      if (getRemainingDimension(i)->getId() == id)
      {
        return removeRemainingDimension(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedVariable.
 */
unsigned int
SedVariable::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "remainingDimension")
  {
    return getNumRemainingDimensions();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedVariable.
 */
SedBase*
SedVariable::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "remainingDimension")
  {
    return getRemainingDimension(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedVariable::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mRemainingDimensions.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedVariable::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfRemainingDimensions")
  {
    if (getErrorLog() && mRemainingDimensions.size() != 0)
    {
      getErrorLog()->logError(SedmlVariableAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mRemainingDimensions;
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
SedVariable::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");

  attributes.add("symbol");

  attributes.add("target");

  attributes.add("taskReference");

  attributes.add("modelReference");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedVariable::readAttributes(
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
    static_cast<SedListOfVariables*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDataGeneratorLOVariablesAllowedCoreAttributes,
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
        log->logError(SedmlVariableAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<SedVariable>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SedmlIdSyntaxRule, level, version, "The id on the <" +
        getElementName() + "> is '" + mId + "', which does not conform to the "
          "syntax.", getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedVariable> element.";
      log->logError(SedmlVariableAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<SedVariable>");
    }
  }

  // 
  // symbol string (use = "optional" )
  // 

  assigned = attributes.readInto("symbol", mSymbol);

  if (assigned == true)
  {
    if (mSymbol.empty() == true)
    {
      logEmptyString(mSymbol, level, version, "<SedVariable>");
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
      logEmptyString(mTarget, level, version, "<SedVariable>");
    }
  }

  // 
  // taskReference SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("taskReference", mTaskReference);

  if (assigned == true)
  {
    if (mTaskReference.empty() == true)
    {
      logEmptyString(mTaskReference, level, version, "<SedVariable>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mTaskReference) == false)
    {
      std::string msg = "The taskReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTaskReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlVariableTaskReferenceMustBeTask, level, version, msg,
        getLine(), getColumn());
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
      logEmptyString(mModelReference, level, version, "<SedVariable>");
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
      logError(SedmlVariableModelReferenceMustBeModel, level, version, msg,
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
SedVariable::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }

  if (isSetSymbol() == true)
  {
    stream.writeAttribute("symbol", getPrefix(), mSymbol);
  }

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }

  if (isSetTaskReference() == true)
  {
    stream.writeAttribute("taskReference", getPrefix(), mTaskReference);
  }

  if (isSetModelReference() == true)
  {
    stream.writeAttribute("modelReference", getPrefix(), mModelReference);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedVariable_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedVariable_t *
SedVariable_create(unsigned int level, unsigned int version)
{
  return new SedVariable(level, version);
}


/*
 * Creates and returns a deep copy of this SedVariable_t object.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedVariable_clone(const SedVariable_t* sv)
{
  if (sv != NULL)
  {
    return static_cast<SedVariable_t*>(sv->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedVariable_t object.
 */
LIBSEDML_EXTERN
void
SedVariable_free(SedVariable_t* sv)
{
  if (sv != NULL)
  {
    delete sv;
  }
}


/*
 * Returns the value of the "id" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getId(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getId().empty() ? NULL : safe_strdup(sv->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getName(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getName().empty() ? NULL : safe_strdup(sv->getName().c_str());
}


/*
 * Returns the value of the "symbol" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getSymbol(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getSymbol().empty() ? NULL : safe_strdup(sv->getSymbol().c_str());
}


/*
 * Returns the value of the "target" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getTarget(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getTarget().empty() ? NULL : safe_strdup(sv->getTarget().c_str());
}


/*
 * Returns the value of the "taskReference" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getTaskReference(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getTaskReference().empty() ? NULL :
    safe_strdup(sv->getTaskReference().c_str());
}


/*
 * Returns the value of the "modelReference" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getModelReference(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getModelReference().empty() ? NULL :
    safe_strdup(sv->getModelReference().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "id" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetId(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "name" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetName(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "symbol" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetSymbol(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetSymbol()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "target" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTarget(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetTarget()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "taskReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTaskReference(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetTaskReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "modelReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetModelReference(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetModelReference()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setId(SedVariable_t * sv, const char * id)
{
  return (sv != NULL) ? sv->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setName(SedVariable_t * sv, const char * name)
{
  return (sv != NULL) ? sv->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "symbol" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setSymbol(SedVariable_t * sv, const char * symbol)
{
  return (sv != NULL) ? sv->setSymbol(symbol) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "target" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setTarget(SedVariable_t * sv, const char * target)
{
  return (sv != NULL) ? sv->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "taskReference" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setTaskReference(SedVariable_t * sv, const char * taskReference)
{
  return (sv != NULL) ? sv->setTaskReference(taskReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "modelReference" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setModelReference(SedVariable_t * sv, const char * modelReference)
{
  return (sv != NULL) ? sv->setModelReference(modelReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetId(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetName(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "symbol" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetSymbol(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetSymbol() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTarget(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "taskReference" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTaskReference(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetTaskReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "modelReference" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetModelReference(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedRemainingDimension_t objects from this
 * SedVariable_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedVariable_getListOfRemainingDimensions(SedVariable_t* sv)
{
  return (sv != NULL) ? sv->getListOfRemainingDimensions() : NULL;
}


/*
 * Get a SedRemainingDimension_t from the SedVariable_t.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_getRemainingDimension(SedVariable_t* sv, unsigned int n)
{
  return (sv != NULL) ? sv->getRemainingDimension(n) : NULL;
}


/*
 * Get a SedRemainingDimension_t from the SedVariable_t based on the Target to
 * which it refers.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_getRemainingDimensionByTarget(SedVariable_t* sv, const char *sid)
{
  return (sv != NULL && sid != NULL) ? sv->getRemainingDimensionByTarget(sid) :
    NULL;
}


/*
 * Get a SedRemainingDimension_t from the SedVariable_t based on the
 * DimensionTarget to which it refers.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_getRemainingDimensionByDimensionTarget(SedVariable_t* sv,
                                                   const char *sid)
{
  return (sv != NULL && sid != NULL) ?
    sv->getRemainingDimensionByDimensionTarget(sid) : NULL;
}


/*
 * Adds a copy of the given SedRemainingDimension_t to this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_addRemainingDimension(SedVariable_t* sv,
                                  const SedRemainingDimension_t* srd)
{
  return (sv != NULL) ? sv->addRemainingDimension(srd) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedRemainingDimension_t objects in this SedVariable_t.
 */
LIBSEDML_EXTERN
unsigned int
SedVariable_getNumRemainingDimensions(SedVariable_t* sv)
{
  return (sv != NULL) ? sv->getNumRemainingDimensions() : SEDML_INT_MAX;
}


/*
 * Creates a new SedRemainingDimension_t object, adds it to this SedVariable_t
 * object and returns the SedRemainingDimension_t object created.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_createRemainingDimension(SedVariable_t* sv)
{
  return (sv != NULL) ? sv->createRemainingDimension() : NULL;
}


/*
 * Removes the nth SedRemainingDimension_t from this SedVariable_t and returns
 * a pointer to it.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_removeRemainingDimension(SedVariable_t* sv, unsigned int n)
{
  return (sv != NULL) ? sv->removeRemainingDimension(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedVariable_t object have been set.
 */
LIBSEDML_EXTERN
int
SedVariable_hasRequiredAttributes(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


