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
 * Creates a new SedVariable using the given SED-ML Level and @ p version
 * values.
 */
SedVariable::SedVariable(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mSymbol ("")
  , mTarget ("")
  , mTaskReference ("")
  , mModelReference ("")
  , mAppliedDimensions (level, version)
  , mTerm ("")
  , mSymbol2 ("")
  , mTarget2 ("")
  , mDimensionTerm ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Creates a new SedVariable using the given SedNamespaces object @p sedmlns.
 */
SedVariable::SedVariable(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mSymbol ("")
  , mTarget ("")
  , mTaskReference ("")
  , mModelReference ("")
  , mAppliedDimensions (sedmlns)
  , mTerm ("")
  , mSymbol2 ("")
  , mTarget2 ("")
  , mDimensionTerm ("")
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Copy constructor for SedVariable.
 */
SedVariable::SedVariable(const SedVariable& orig)
  : SedBase( orig )
  , mSymbol ( orig.mSymbol )
  , mTarget ( orig.mTarget )
  , mTaskReference ( orig.mTaskReference )
  , mModelReference ( orig.mModelReference )
  , mAppliedDimensions ( orig.mAppliedDimensions )
  , mTerm ( orig.mTerm )
  , mSymbol2 ( orig.mSymbol2 )
  , mTarget2 ( orig.mTarget2 )
  , mDimensionTerm ( orig.mDimensionTerm )
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
    mSymbol = rhs.mSymbol;
    mTarget = rhs.mTarget;
    mTaskReference = rhs.mTaskReference;
    mModelReference = rhs.mModelReference;
    mAppliedDimensions = rhs.mAppliedDimensions;
    mTerm = rhs.mTerm;
    mSymbol2 = rhs.mSymbol2;
    mTarget2 = rhs.mTarget2;
    mDimensionTerm = rhs.mDimensionTerm;
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
 * Returns the value of the "term" attribute of this SedVariable.
 */
const std::string&
SedVariable::getTerm() const
{
  return mTerm;
}


/*
 * Returns the value of the "symbol2" attribute of this SedVariable.
 */
const std::string&
SedVariable::getSymbol2() const
{
  return mSymbol2;
}


/*
 * Returns the value of the "target2" attribute of this SedVariable.
 */
const std::string&
SedVariable::getTarget2() const
{
  return mTarget2;
}


/*
 * Returns the value of the "dimensionTerm" attribute of this SedVariable.
 */
const std::string&
SedVariable::getDimensionTerm() const
{
  return mDimensionTerm;
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
 * Predicate returning @c true if this SedVariable's "term" attribute is set.
 */
bool
SedVariable::isSetTerm() const
{
  return (mTerm.empty() == false);
}


/*
 * Predicate returning @c true if this SedVariable's "symbol2" attribute is
 * set.
 */
bool
SedVariable::isSetSymbol2() const
{
  return (mSymbol2.empty() == false);
}


/*
 * Predicate returning @c true if this SedVariable's "target2" attribute is
 * set.
 */
bool
SedVariable::isSetTarget2() const
{
  return (mTarget2.empty() == false);
}


/*
 * Predicate returning @c true if this SedVariable's "dimensionTerm" attribute
 * is set.
 */
bool
SedVariable::isSetDimensionTerm() const
{
  return (mDimensionTerm.empty() == false);
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
 * Sets the value of the "term" attribute of this SedVariable.
 */
int
SedVariable::setTerm(const std::string& term)
{
  mTerm = term;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "symbol2" attribute of this SedVariable.
 */
int
SedVariable::setSymbol2(const std::string& symbol2)
{
  mSymbol2 = symbol2;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "target2" attribute of this SedVariable.
 */
int
SedVariable::setTarget2(const std::string& target2)
{
  mTarget2 = target2;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "dimensionTerm" attribute of this SedVariable.
 */
int
SedVariable::setDimensionTerm(const std::string& dimensionTerm)
{
  mDimensionTerm = dimensionTerm;
  return LIBSEDML_OPERATION_SUCCESS;
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
 * Unsets the value of the "term" attribute of this SedVariable.
 */
int
SedVariable::unsetTerm()
{
  mTerm.erase();

  if (mTerm.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "symbol2" attribute of this SedVariable.
 */
int
SedVariable::unsetSymbol2()
{
  mSymbol2.erase();

  if (mSymbol2.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "target2" attribute of this SedVariable.
 */
int
SedVariable::unsetTarget2()
{
  mTarget2.erase();

  if (mTarget2.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "dimensionTerm" attribute of this SedVariable.
 */
int
SedVariable::unsetDimensionTerm()
{
  mDimensionTerm.erase();

  if (mDimensionTerm.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfAppliedDimensions from this SedVariable.
 */
const SedListOfAppliedDimensions*
SedVariable::getListOfAppliedDimensions() const
{
  return &mAppliedDimensions;
}


/*
 * Returns the SedListOfAppliedDimensions from this SedVariable.
 */
SedListOfAppliedDimensions*
SedVariable::getListOfAppliedDimensions()
{
  return &mAppliedDimensions;
}


/*
 * Get a SedAppliedDimension from the SedVariable.
 */
SedAppliedDimension*
SedVariable::getAppliedDimension(unsigned int n)
{
  return mAppliedDimensions.get(n);
}


/*
 * Get a SedAppliedDimension from the SedVariable.
 */
const SedAppliedDimension*
SedVariable::getAppliedDimension(unsigned int n) const
{
  return mAppliedDimensions.get(n);
}


/*
 * Get a SedAppliedDimension from the SedVariable based on the Target to which
 * it refers.
 */
const SedAppliedDimension*
SedVariable::getAppliedDimensionByTarget(const std::string& sid) const
{
  return mAppliedDimensions.getByTarget(sid);
}


/*
 * Get a SedAppliedDimension from the SedVariable based on the Target to which
 * it refers.
 */
SedAppliedDimension*
SedVariable::getAppliedDimensionByTarget(const std::string& sid)
{
  return mAppliedDimensions.getByTarget(sid);
}


/*
 * Get a SedAppliedDimension from the SedVariable based on the DimensionTarget
 * to which it refers.
 */
const SedAppliedDimension*
SedVariable::getAppliedDimensionByDimensionTarget(const std::string& sid) const
{
  return mAppliedDimensions.getByDimensionTarget(sid);
}


/*
 * Get a SedAppliedDimension from the SedVariable based on the DimensionTarget
 * to which it refers.
 */
SedAppliedDimension*
SedVariable::getAppliedDimensionByDimensionTarget(const std::string& sid)
{
  return mAppliedDimensions.getByDimensionTarget(sid);
}


/*
 * Adds a copy of the given SedAppliedDimension to this SedVariable.
 */
int
SedVariable::addAppliedDimension(const SedAppliedDimension* sad)
{
  if (sad == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sad->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sad->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sad->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sad)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mAppliedDimensions.append(sad);
  }
}


/*
 * Get the number of SedAppliedDimension objects in this SedVariable.
 */
unsigned int
SedVariable::getNumAppliedDimensions() const
{
  return mAppliedDimensions.size();
}


/*
 * Creates a new SedAppliedDimension object, adds it to this SedVariable object
 * and returns the SedAppliedDimension object created.
 */
SedAppliedDimension*
SedVariable::createAppliedDimension()
{
  SedAppliedDimension* sad = NULL;

  try
  {
    sad = new SedAppliedDimension(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sad != NULL)
  {
    mAppliedDimensions.appendAndOwn(sad);
  }

  return sad;
}


/*
 * Removes the nth SedAppliedDimension from this SedVariable and returns a
 * pointer to it.
 */
SedAppliedDimension*
SedVariable::removeAppliedDimension(unsigned int n)
{
  return mAppliedDimensions.remove(n);
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

  if (getNumAppliedDimensions() > 0)
  {
    mAppliedDimensions.write(stream);
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

  mAppliedDimensions.setSedDocument(d);
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

  mAppliedDimensions.connectToParent(this);
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

  if (attributeName == "symbol")
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
  else if (attributeName == "term")
  {
    value = getTerm();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "symbol2")
  {
    value = getSymbol2();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "target2")
  {
    value = getTarget2();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "dimensionTerm")
  {
    value = getDimensionTerm();
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

  if (attributeName == "symbol")
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
  else if (attributeName == "term")
  {
    value = isSetTerm();
  }
  else if (attributeName == "symbol2")
  {
    value = isSetSymbol2();
  }
  else if (attributeName == "target2")
  {
    value = isSetTarget2();
  }
  else if (attributeName == "dimensionTerm")
  {
    value = isSetDimensionTerm();
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

  if (attributeName == "symbol")
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
  else if (attributeName == "term")
  {
    return_value = setTerm(value);
  }
  else if (attributeName == "symbol2")
  {
    return_value = setSymbol2(value);
  }
  else if (attributeName == "target2")
  {
    return_value = setTarget2(value);
  }
  else if (attributeName == "dimensionTerm")
  {
    return_value = setDimensionTerm(value);
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

  if (attributeName == "symbol")
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
  else if (attributeName == "term")
  {
    value = unsetTerm();
  }
  else if (attributeName == "symbol2")
  {
    value = unsetSymbol2();
  }
  else if (attributeName == "target2")
  {
    value = unsetTarget2();
  }
  else if (attributeName == "dimensionTerm")
  {
    value = unsetDimensionTerm();
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

  if (elementName == "appliedDimension")
  {
    return createAppliedDimension();
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
  if (elementName == "appliedDimension" && element->getTypeCode() ==
    SEDML_APPLIEDDIMENSION)
  {
    return addAppliedDimension((const SedAppliedDimension*)(element));
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
  if (elementName == "appliedDimension")
  {
    for (unsigned int i = 0; i < getNumAppliedDimensions(); i++)
    {
      if (getAppliedDimension(i)->getId() == id)
      {
        return removeAppliedDimension(i);
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

  if (elementName == "appliedDimension")
  {
    return getNumAppliedDimensions();
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

  if (elementName == "appliedDimension")
  {
    return getAppliedDimension(index);
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

  obj = mAppliedDimensions.getElementBySId(id);

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
SedVariable::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mAppliedDimensions, filter);

  return ret;
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

  if (name == "listOfAppliedDimensions")
  {
    if (getErrorLog() && mAppliedDimensions.size() != 0)
    {
      getErrorLog()->logError(SedmlVariableAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mAppliedDimensions;
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

  attributes.add("symbol");

  attributes.add("target");

  attributes.add("taskReference");

  attributes.add("modelReference");

  attributes.add("term");

  attributes.add("symbol2");

  attributes.add("target2");

  attributes.add("dimensionTerm");
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

  if(!isSetId())
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
      logError(SedmlVariableTaskReferenceMustBeAbstractTask, level, version,
        msg, getLine(), getColumn());
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

  // 
  // term string (use = "optional" )
  // 

  assigned = attributes.readInto("term", mTerm);

  if (assigned == true)
  {
    if (mTerm.empty() == true)
    {
      logEmptyString(mTerm, level, version, "<SedVariable>");
    }
  }

  // 
  // symbol2 string (use = "optional" )
  // 

  assigned = attributes.readInto("symbol2", mSymbol2);

  if (assigned == true)
  {
    if (mSymbol2.empty() == true)
    {
      logEmptyString(mSymbol2, level, version, "<SedVariable>");
    }
  }

  // 
  // target2 string (use = "optional" )
  // 

  assigned = attributes.readInto("target2", mTarget2);

  if (assigned == true)
  {
    if (mTarget2.empty() == true)
    {
      logEmptyString(mTarget2, level, version, "<SedVariable>");
    }
  }

  // 
  // dimensionTerm string (use = "optional" )
  // 

  assigned = attributes.readInto("dimensionTerm", mDimensionTerm);

  if (assigned == true)
  {
    if (mDimensionTerm.empty() == true)
    {
      logEmptyString(mDimensionTerm, level, version, "<SedVariable>");
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

  if (isSetTerm() == true)
  {
    stream.writeAttribute("term", getPrefix(), mTerm);
  }

  if (isSetSymbol2() == true)
  {
    stream.writeAttribute("symbol2", getPrefix(), mSymbol2);
  }

  if (isSetTarget2() == true)
  {
    stream.writeAttribute("target2", getPrefix(), mTarget2);
  }

  if (isSetDimensionTerm() == true)
  {
    stream.writeAttribute("dimensionTerm", getPrefix(), mDimensionTerm);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedVariable_t using the given SED-ML Level and @ p version
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
 * Returns the value of the "term" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getTerm(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getTerm().empty() ? NULL : safe_strdup(sv->getTerm().c_str());
}


/*
 * Returns the value of the "symbol2" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getSymbol2(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getSymbol2().empty() ? NULL :
    safe_strdup(sv->getSymbol2().c_str());
}


/*
 * Returns the value of the "target2" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getTarget2(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getTarget2().empty() ? NULL :
    safe_strdup(sv->getTarget2().c_str());
}


/*
 * Returns the value of the "dimensionTerm" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
char *
SedVariable_getDimensionTerm(const SedVariable_t * sv)
{
  if (sv == NULL)
  {
    return NULL;
  }

  return sv->getDimensionTerm().empty() ? NULL :
    safe_strdup(sv->getDimensionTerm().c_str());
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
 * Predicate returning @c 1 (true) if this SedVariable_t's "term" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTerm(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetTerm()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "symbol2" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetSymbol2(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetSymbol2()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "target2" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTarget2(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetTarget2()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedVariable_t's "dimensionTerm"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedVariable_isSetDimensionTerm(const SedVariable_t * sv)
{
  return (sv != NULL) ? static_cast<int>(sv->isSetDimensionTerm()) : 0;
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
 * Sets the value of the "term" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setTerm(SedVariable_t * sv, const char * term)
{
  return (sv != NULL) ? sv->setTerm(term) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "symbol2" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setSymbol2(SedVariable_t * sv, const char * symbol2)
{
  return (sv != NULL) ? sv->setSymbol2(symbol2) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "target2" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setTarget2(SedVariable_t * sv, const char * target2)
{
  return (sv != NULL) ? sv->setTarget2(target2) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "dimensionTerm" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_setDimensionTerm(SedVariable_t * sv, const char * dimensionTerm)
{
  return (sv != NULL) ? sv->setDimensionTerm(dimensionTerm) :
    LIBSEDML_INVALID_OBJECT;
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
 * Unsets the value of the "term" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTerm(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetTerm() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "symbol2" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetSymbol2(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetSymbol2() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target2" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTarget2(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetTarget2() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "dimensionTerm" attribute of this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_unsetDimensionTerm(SedVariable_t * sv)
{
  return (sv != NULL) ? sv->unsetDimensionTerm() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedAppliedDimension_t objects from this
 * SedVariable_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedVariable_getListOfAppliedDimensions(SedVariable_t* sv)
{
  return (sv != NULL) ? sv->getListOfAppliedDimensions() : NULL;
}


/*
 * Get a SedAppliedDimension_t from the SedVariable_t.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_getAppliedDimension(SedVariable_t* sv, unsigned int n)
{
  return (sv != NULL) ? sv->getAppliedDimension(n) : NULL;
}


/*
 * Get a SedAppliedDimension_t from the SedVariable_t based on the Target to
 * which it refers.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_getAppliedDimensionByTarget(SedVariable_t* sv, const char *sid)
{
  return (sv != NULL && sid != NULL) ? sv->getAppliedDimensionByTarget(sid) :
    NULL;
}


/*
 * Get a SedAppliedDimension_t from the SedVariable_t based on the
 * DimensionTarget to which it refers.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_getAppliedDimensionByDimensionTarget(SedVariable_t* sv,
                                                 const char *sid)
{
  return (sv != NULL && sid != NULL) ?
    sv->getAppliedDimensionByDimensionTarget(sid) : NULL;
}


/*
 * Adds a copy of the given SedAppliedDimension_t to this SedVariable_t.
 */
LIBSEDML_EXTERN
int
SedVariable_addAppliedDimension(SedVariable_t* sv,
                                const SedAppliedDimension_t* sad)
{
  return (sv != NULL) ? sv->addAppliedDimension(sad) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedAppliedDimension_t objects in this SedVariable_t.
 */
LIBSEDML_EXTERN
unsigned int
SedVariable_getNumAppliedDimensions(SedVariable_t* sv)
{
  return (sv != NULL) ? sv->getNumAppliedDimensions() : SEDML_INT_MAX;
}


/*
 * Creates a new SedAppliedDimension_t object, adds it to this SedVariable_t
 * object and returns the SedAppliedDimension_t object created.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_createAppliedDimension(SedVariable_t* sv)
{
  return (sv != NULL) ? sv->createAppliedDimension() : NULL;
}


/*
 * Removes the nth SedAppliedDimension_t from this SedVariable_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_removeAppliedDimension(SedVariable_t* sv, unsigned int n)
{
  return (sv != NULL) ? sv->removeAppliedDimension(n) : NULL;
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


