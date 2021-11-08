/**
 * @file SedCurve.cpp
 * @brief Implementation of the SedCurve class.
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
#include <sedml/SedCurve.h>
#include <sbml/xml/XMLInputStream.h>
#include <sedml/SedPlot2D.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedCurve using the given SED-ML Level and @ p version values.
 */
SedCurve::SedCurve(unsigned int level, unsigned int version)
  : SedAbstractCurve(level, version)
  , mLogY (false)
  , mIsSetLogY (false)
  , mYDataReference ("")
  , mType (SEDML_CURVETYPE_INVALID)
  , mXErrorUpper ("")
  , mXErrorLower ("")
  , mYErrorUpper ("")
  , mYErrorLower ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedCurve using the given SedNamespaces object @p sedmlns.
 */
SedCurve::SedCurve(SedNamespaces *sedmlns)
  : SedAbstractCurve(sedmlns)
  , mLogY (false)
  , mIsSetLogY (false)
  , mYDataReference ("")
  , mType (SEDML_CURVETYPE_INVALID)
  , mXErrorUpper ("")
  , mXErrorLower ("")
  , mYErrorUpper ("")
  , mYErrorLower ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedCurve.
 */
SedCurve::SedCurve(const SedCurve& orig)
  : SedAbstractCurve( orig )
  , mLogY ( orig.mLogY )
  , mIsSetLogY ( orig.mIsSetLogY )
  , mYDataReference ( orig.mYDataReference )
  , mType ( orig.mType )
  , mXErrorUpper ( orig.mXErrorUpper )
  , mXErrorLower ( orig.mXErrorLower )
  , mYErrorUpper ( orig.mYErrorUpper )
  , mYErrorLower ( orig.mYErrorLower )
{
}


/*
 * Assignment operator for SedCurve.
 */
SedCurve&
SedCurve::operator=(const SedCurve& rhs)
{
  if (&rhs != this)
  {
    SedAbstractCurve::operator=(rhs);
    mLogY = rhs.mLogY;
    mIsSetLogY = rhs.mIsSetLogY;
    mYDataReference = rhs.mYDataReference;
    mType = rhs.mType;
    mXErrorUpper = rhs.mXErrorUpper;
    mXErrorLower = rhs.mXErrorLower;
    mYErrorUpper = rhs.mYErrorUpper;
    mYErrorLower = rhs.mYErrorLower;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedCurve object.
 */
SedCurve*
SedCurve::clone() const
{
  return new SedCurve(*this);
}


/*
 * Destructor for SedCurve.
 */
SedCurve::~SedCurve()
{
}


/*
 * Returns the value of the "logY" attribute of this SedCurve.
 */
bool
SedCurve::getLogY() const
{
  if (getVersion() < 4)
  {
      return mLogY;
  }
  if (isSetLogY())
  {
      return mLogY;
  }
  const SedBase* parent = getParentSedObject();
  if (parent)
  {
      parent = parent->getParentSedObject();
  }
  if (parent)
  {
      if (parent->getTypeCode() == SEDML_OUTPUT_PLOT2D)
      {
          const SedPlot2D* plot = static_cast<const SedPlot2D*>(parent);
          if (plot)
          {
              const SedAxis* axis = plot->getYAxis();
              if (getYAxis() == "right")
              {
                  axis = plot->getRightYAxis();
              }
              if (axis && axis->isSetType())
              {
                  return axis->getType() == SEDML_AXISTYPE_LOG10;
              }
              else
              {
                  return false;
              }
          }
      }
  }
  return mLogY;
}


/*
 * Returns the value of the "yDataReference" attribute of this SedCurve.
 */
const std::string&
SedCurve::getYDataReference() const
{
  return mYDataReference;
}


/*
 * Returns the value of the "type" attribute of this SedCurve.
 */
CurveType_t
SedCurve::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this SedCurve.
 */
std::string
SedCurve::getTypeAsString() const
{
  std::string code_str = CurveType_toString(mType);
  return code_str;
}


/*
 * Returns the value of the "xErrorUpper" attribute of this SedCurve.
 */
const std::string&
SedCurve::getXErrorUpper() const
{
  return mXErrorUpper;
}


/*
 * Returns the value of the "xErrorLower" attribute of this SedCurve.
 */
const std::string&
SedCurve::getXErrorLower() const
{
  return mXErrorLower;
}


/*
 * Returns the value of the "yErrorUpper" attribute of this SedCurve.
 */
const std::string&
SedCurve::getYErrorUpper() const
{
  return mYErrorUpper;
}


/*
 * Returns the value of the "yErrorLower" attribute of this SedCurve.
 */
const std::string&
SedCurve::getYErrorLower() const
{
  return mYErrorLower;
}


/*
 * Predicate returning @c true if this SedCurve's "logY" attribute is set.
 */
bool
SedCurve::isSetLogY() const
{
  return mIsSetLogY;
}


/*
 * Predicate returning @c true if this SedCurve's "yDataReference" attribute is
 * set.
 */
bool
SedCurve::isSetYDataReference() const
{
  return (mYDataReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedCurve's "type" attribute is set.
 */
bool
SedCurve::isSetType() const
{
  return (mType != SEDML_CURVETYPE_INVALID);
}


/*
 * Predicate returning @c true if this SedCurve's "xErrorUpper" attribute is
 * set.
 */
bool
SedCurve::isSetXErrorUpper() const
{
  return (mXErrorUpper.empty() == false);
}


/*
 * Predicate returning @c true if this SedCurve's "xErrorLower" attribute is
 * set.
 */
bool
SedCurve::isSetXErrorLower() const
{
  return (mXErrorLower.empty() == false);
}


/*
 * Predicate returning @c true if this SedCurve's "yErrorUpper" attribute is
 * set.
 */
bool
SedCurve::isSetYErrorUpper() const
{
  return (mYErrorUpper.empty() == false);
}


/*
 * Predicate returning @c true if this SedCurve's "yErrorLower" attribute is
 * set.
 */
bool
SedCurve::isSetYErrorLower() const
{
  return (mYErrorLower.empty() == false);
}


/*
 * Sets the value of the "logY" attribute of this SedCurve.
 */
int
SedCurve::setLogY(bool logY)
{
  mLogY = logY;
  mIsSetLogY = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "yDataReference" attribute of this SedCurve.
 */
int
SedCurve::setYDataReference(const std::string& yDataReference)
{
  if (!(SyntaxChecker::isValidInternalSId(yDataReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mYDataReference = yDataReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedCurve.
 */
int
SedCurve::setType(const CurveType_t type)
{
  if (CurveType_isValid(type) == 0)
  {
    mType = SEDML_CURVETYPE_INVALID;
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedCurve.
 */
int
SedCurve::setType(const std::string& type)
{
  mType = CurveType_fromString(type.c_str());

  if (mType == SEDML_CURVETYPE_INVALID)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "xErrorUpper" attribute of this SedCurve.
 */
int
SedCurve::setXErrorUpper(const std::string& xErrorUpper)
{
  if (!(SyntaxChecker::isValidInternalSId(xErrorUpper)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mXErrorUpper = xErrorUpper;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "xErrorLower" attribute of this SedCurve.
 */
int
SedCurve::setXErrorLower(const std::string& xErrorLower)
{
  if (!(SyntaxChecker::isValidInternalSId(xErrorLower)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mXErrorLower = xErrorLower;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "yErrorUpper" attribute of this SedCurve.
 */
int
SedCurve::setYErrorUpper(const std::string& yErrorUpper)
{
  if (!(SyntaxChecker::isValidInternalSId(yErrorUpper)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mYErrorUpper = yErrorUpper;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "yErrorLower" attribute of this SedCurve.
 */
int
SedCurve::setYErrorLower(const std::string& yErrorLower)
{
  if (!(SyntaxChecker::isValidInternalSId(yErrorLower)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mYErrorLower = yErrorLower;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "logY" attribute of this SedCurve.
 */
int
SedCurve::unsetLogY()
{
  mLogY = false;
  mIsSetLogY = false;

  if (isSetLogY() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "yDataReference" attribute of this SedCurve.
 */
int
SedCurve::unsetYDataReference()
{
  mYDataReference.erase();

  if (mYDataReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "type" attribute of this SedCurve.
 */
int
SedCurve::unsetType()
{
  mType = SEDML_CURVETYPE_INVALID;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "xErrorUpper" attribute of this SedCurve.
 */
int
SedCurve::unsetXErrorUpper()
{
  mXErrorUpper.erase();

  if (mXErrorUpper.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "xErrorLower" attribute of this SedCurve.
 */
int
SedCurve::unsetXErrorLower()
{
  mXErrorLower.erase();

  if (mXErrorLower.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "yErrorUpper" attribute of this SedCurve.
 */
int
SedCurve::unsetYErrorUpper()
{
  mYErrorUpper.erase();

  if (mYErrorUpper.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "yErrorLower" attribute of this SedCurve.
 */
int
SedCurve::unsetYErrorLower()
{
  mYErrorLower.erase();

  if (mYErrorLower.empty() == true)
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
SedCurve::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetYDataReference() && mYDataReference == oldid)
  {
    setYDataReference(newid);
  }

  if (isSetXErrorUpper() && mXErrorUpper == oldid)
  {
    setXErrorUpper(newid);
  }

  if (isSetXErrorLower() && mXErrorLower == oldid)
  {
    setXErrorLower(newid);
  }

  if (isSetYErrorUpper() && mYErrorUpper == oldid)
  {
    setYErrorUpper(newid);
  }

  if (isSetYErrorLower() && mYErrorLower == oldid)
  {
    setYErrorLower(newid);
  }
}


/*
 * Returns the XML element name of this SedCurve object.
 */
const std::string&
SedCurve::getElementName() const
{
  static const string name = "curve";
  return name;
}


/*
 * Returns the libSEDML type code for this SedCurve object.
 */
int
SedCurve::getTypeCode() const
{
  return SEDML_OUTPUT_CURVE;
}


/*
 * Predicate returning @c true if all the required attributes for this SedCurve
 * object have been set.
 */
bool
SedCurve::hasRequiredAttributes() const
{
  bool allPresent = SedAbstractCurve::hasRequiredAttributes();

  if (isSetYDataReference() == false)
  {
    allPresent = false;
  }

  if (isSetType() == false)
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
SedCurve::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedAbstractCurve::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedCurve::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedCurve::setSedDocument(SedDocument* d)
{
  SedAbstractCurve::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "logY")
  {
    value = getLogY();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "yDataReference")
  {
    value = getYDataReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "type")
  {
    value = getTypeAsString();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "xErrorUpper")
  {
    value = getXErrorUpper();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "xErrorLower")
  {
    value = getXErrorLower();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "yErrorUpper")
  {
    value = getYErrorUpper();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "yErrorLower")
  {
    value = getYErrorLower();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedCurve's attribute "attributeName" is
 * set.
 */
bool
SedCurve::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedAbstractCurve::isSetAttribute(attributeName);

  if (attributeName == "logY")
  {
    value = isSetLogY();
  }
  else if (attributeName == "yDataReference")
  {
    value = isSetYDataReference();
  }
  else if (attributeName == "type")
  {
    value = isSetType();
  }
  else if (attributeName == "xErrorUpper")
  {
    value = isSetXErrorUpper();
  }
  else if (attributeName == "xErrorLower")
  {
    value = isSetXErrorLower();
  }
  else if (attributeName == "yErrorUpper")
  {
    value = isSetYErrorUpper();
  }
  else if (attributeName == "yErrorLower")
  {
    value = isSetYErrorLower();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  if (attributeName == "logY")
  {
    return_value = setLogY(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  if (attributeName == "yDataReference")
  {
    return_value = setYDataReference(value);
  }
  else if (attributeName == "type")
  {
    return_value = setType(value);
  }
  else if (attributeName == "xErrorUpper")
  {
    return_value = setXErrorUpper(value);
  }
  else if (attributeName == "xErrorLower")
  {
    return_value = setXErrorLower(value);
  }
  else if (attributeName == "yErrorUpper")
  {
    return_value = setYErrorUpper(value);
  }
  else if (attributeName == "yErrorLower")
  {
    return_value = setYErrorLower(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedCurve.
 */
int
SedCurve::unsetAttribute(const std::string& attributeName)
{
  int value = SedAbstractCurve::unsetAttribute(attributeName);

  if (attributeName == "logY")
  {
    value = unsetLogY();
  }
  else if (attributeName == "yDataReference")
  {
    value = unsetYDataReference();
  }
  else if (attributeName == "type")
  {
    value = unsetType();
  }
  else if (attributeName == "xErrorUpper")
  {
    value = unsetXErrorUpper();
  }
  else if (attributeName == "xErrorLower")
  {
    value = unsetXErrorLower();
  }
  else if (attributeName == "yErrorUpper")
  {
    value = unsetYErrorUpper();
  }
  else if (attributeName == "yErrorLower")
  {
    value = unsetYErrorLower();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedCurve::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = SedAbstractCurve::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedCurve::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedAbstractCurve::addExpectedAttributes(attributes);

  attributes.add("logY");

  attributes.add("yDataReference");

  attributes.add("type");

  attributes.add("xErrorUpper");

  attributes.add("xErrorLower");

  attributes.add("yErrorUpper");

  attributes.add("yErrorLower");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedCurve::readAttributes(
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

  SedAbstractCurve::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlCurveAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // logY bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLogY = attributes.readInto("logY", mLogY);

  if (mIsSetLogY == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlCurveLogYMustBeBoolean, level, version);
    }
  }

  // 
  // yDataReference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("yDataReference", mYDataReference);

  if (assigned == true)
  {
    if (mYDataReference.empty() == true)
    {
      logEmptyString(mYDataReference, level, version, "<SedCurve>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mYDataReference) == false)
    {
      std::string msg = "The yDataReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mYDataReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlCurveYDataReferenceMustBeDataGenerator, level, version,
        msg, getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'yDataReference' is missing from "
        "the <SedCurve> element.";
      log->logError(SedmlCurveAllowedAttributes, level, version, message,
        getLine(), getColumn());
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
      logEmptyString(type, level, version, "<SedCurve>");
    }
    else
    {
      mType = CurveType_fromString(type.c_str());

      if (log && CurveType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <SedCurve> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logError(SedmlCurveTypeMustBeCurveTypeEnum, level, version, msg,
          getLine(), getColumn());
      }
    }
  }

  // 
  // xErrorUpper SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("xErrorUpper", mXErrorUpper);

  if (assigned == true)
  {
    if (mXErrorUpper.empty() == true)
    {
      logEmptyString(mXErrorUpper, level, version, "<SedCurve>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mXErrorUpper) == false)
    {
      std::string msg = "The xErrorUpper attribute on the <" + getElementName()
        + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mXErrorUpper + "', which does not conform to the "
        "syntax.";
      logError(SedmlCurveXErrorUpperMustBeDataGenerator, level, version, msg,
        getLine(), getColumn());
    }
  }

  // 
  // xErrorLower SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("xErrorLower", mXErrorLower);

  if (assigned == true)
  {
    if (mXErrorLower.empty() == true)
    {
      logEmptyString(mXErrorLower, level, version, "<SedCurve>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mXErrorLower) == false)
    {
      std::string msg = "The xErrorLower attribute on the <" + getElementName()
        + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mXErrorLower + "', which does not conform to the "
        "syntax.";
      logError(SedmlCurveXErrorLowerMustBeDataGenerator, level, version, msg,
        getLine(), getColumn());
    }
  }

  // 
  // yErrorUpper SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("yErrorUpper", mYErrorUpper);

  if (assigned == true)
  {
    if (mYErrorUpper.empty() == true)
    {
      logEmptyString(mYErrorUpper, level, version, "<SedCurve>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mYErrorUpper) == false)
    {
      std::string msg = "The yErrorUpper attribute on the <" + getElementName()
        + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mYErrorUpper + "', which does not conform to the "
        "syntax.";
      logError(SedmlCurveYErrorUpperMustBeDataGenerator, level, version, msg,
        getLine(), getColumn());
    }
  }

  // 
  // yErrorLower SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("yErrorLower", mYErrorLower);

  if (assigned == true)
  {
    if (mYErrorLower.empty() == true)
    {
      logEmptyString(mYErrorLower, level, version, "<SedCurve>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mYErrorLower) == false)
    {
      std::string msg = "The yErrorLower attribute on the <" + getElementName()
        + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mYErrorLower + "', which does not conform to the "
        "syntax.";
      logError(SedmlCurveYErrorLowerMustBeDataGenerator, level, version, msg,
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
SedCurve::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedAbstractCurve::writeAttributes(stream);

  if (isSetLogY() == true)
  {
    stream.writeAttribute("logY", getPrefix(), mLogY);
  }

  if (isSetYDataReference() == true)
  {
    stream.writeAttribute("yDataReference", getPrefix(), mYDataReference);
  }

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), CurveType_toString(mType));
  }

  if (isSetXErrorUpper() == true)
  {
    stream.writeAttribute("xErrorUpper", getPrefix(), mXErrorUpper);
  }

  if (isSetXErrorLower() == true)
  {
    stream.writeAttribute("xErrorLower", getPrefix(), mXErrorLower);
  }

  if (isSetYErrorUpper() == true)
  {
    stream.writeAttribute("yErrorUpper", getPrefix(), mYErrorUpper);
  }

  if (isSetYErrorLower() == true)
  {
    stream.writeAttribute("yErrorLower", getPrefix(), mYErrorLower);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedCurve_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedCurve_t *
SedCurve_create(unsigned int level, unsigned int version)
{
  return new SedCurve(level, version);
}


/*
 * Creates and returns a deep copy of this SedCurve_t object.
 */
LIBSEDML_EXTERN
SedCurve_t*
SedCurve_clone(const SedCurve_t* sc)
{
  if (sc != NULL)
  {
    return static_cast<SedCurve_t*>(sc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedCurve_t object.
 */
LIBSEDML_EXTERN
void
SedCurve_free(SedCurve_t* sc)
{
  if (sc != NULL)
  {
    delete sc;
  }
}


/*
 * Returns the value of the "logY" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_getLogY(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->getLogY()) : 0;
}


/*
 * Returns the value of the "yDataReference" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
char *
SedCurve_getYDataReference(const SedCurve_t * sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return sc->getYDataReference().empty() ? NULL :
    safe_strdup(sc->getYDataReference().c_str());
}


/*
 * Returns the value of the "type" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
CurveType_t
SedCurve_getType(const SedCurve_t * sc)
{
  if (sc == NULL)
  {
    return SEDML_CURVETYPE_INVALID;
  }

  return sc->getType();
}


/*
 * Returns the value of the "type" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
char *
SedCurve_getTypeAsString(const SedCurve_t * sc)
{
  return (char*)(CurveType_toString(sc->getType()));
}


/*
 * Returns the value of the "xErrorUpper" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
char *
SedCurve_getXErrorUpper(const SedCurve_t * sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return sc->getXErrorUpper().empty() ? NULL :
    safe_strdup(sc->getXErrorUpper().c_str());
}


/*
 * Returns the value of the "xErrorLower" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
char *
SedCurve_getXErrorLower(const SedCurve_t * sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return sc->getXErrorLower().empty() ? NULL :
    safe_strdup(sc->getXErrorLower().c_str());
}


/*
 * Returns the value of the "yErrorUpper" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
char *
SedCurve_getYErrorUpper(const SedCurve_t * sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return sc->getYErrorUpper().empty() ? NULL :
    safe_strdup(sc->getYErrorUpper().c_str());
}


/*
 * Returns the value of the "yErrorLower" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
char *
SedCurve_getYErrorLower(const SedCurve_t * sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return sc->getYErrorLower().empty() ? NULL :
    safe_strdup(sc->getYErrorLower().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedCurve_t's "logY" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedCurve_isSetLogY(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetLogY()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedCurve_t's "yDataReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedCurve_isSetYDataReference(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetYDataReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedCurve_t's "type" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedCurve_isSetType(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetType()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedCurve_t's "xErrorUpper" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedCurve_isSetXErrorUpper(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetXErrorUpper()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedCurve_t's "xErrorLower" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedCurve_isSetXErrorLower(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetXErrorLower()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedCurve_t's "yErrorUpper" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedCurve_isSetYErrorUpper(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetYErrorUpper()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedCurve_t's "yErrorLower" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedCurve_isSetYErrorLower(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetYErrorLower()) : 0;
}


/*
 * Sets the value of the "logY" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_setLogY(SedCurve_t * sc, int logY)
{
  return (sc != NULL) ? sc->setLogY(logY) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "yDataReference" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_setYDataReference(SedCurve_t * sc, const char * yDataReference)
{
  return (sc != NULL) ? sc->setYDataReference(yDataReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_setType(SedCurve_t * sc, CurveType_t type)
{
  return (sc != NULL) ? sc->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_setTypeAsString(SedCurve_t * sc, const char * type)
{
  return (sc != NULL) ? sc->setType(type): LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "xErrorUpper" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_setXErrorUpper(SedCurve_t * sc, const char * xErrorUpper)
{
  return (sc != NULL) ? sc->setXErrorUpper(xErrorUpper) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "xErrorLower" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_setXErrorLower(SedCurve_t * sc, const char * xErrorLower)
{
  return (sc != NULL) ? sc->setXErrorLower(xErrorLower) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "yErrorUpper" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_setYErrorUpper(SedCurve_t * sc, const char * yErrorUpper)
{
  return (sc != NULL) ? sc->setYErrorUpper(yErrorUpper) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "yErrorLower" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_setYErrorLower(SedCurve_t * sc, const char * yErrorLower)
{
  return (sc != NULL) ? sc->setYErrorLower(yErrorLower) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "logY" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_unsetLogY(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetLogY() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "yDataReference" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_unsetYDataReference(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetYDataReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_unsetType(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetType() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "xErrorUpper" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_unsetXErrorUpper(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetXErrorUpper() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "xErrorLower" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_unsetXErrorLower(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetXErrorLower() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "yErrorUpper" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_unsetYErrorUpper(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetYErrorUpper() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "yErrorLower" attribute of this SedCurve_t.
 */
LIBSEDML_EXTERN
int
SedCurve_unsetYErrorLower(SedCurve_t * sc)
{
  return (sc != NULL) ? sc->unsetYErrorLower() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedCurve_t object have been set.
 */
LIBSEDML_EXTERN
int
SedCurve_hasRequiredAttributes(const SedCurve_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


