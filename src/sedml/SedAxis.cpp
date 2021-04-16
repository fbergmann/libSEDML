/**
 * @file SedAxis.cpp
 * @brief Implementation of the SedAxis class.
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
#include <sedml/SedAxis.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAxis using the given SED-ML Level and @ p version values.
 */
SedAxis::SedAxis(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mType (SEDML_AXISTYPE_INVALID)
  , mMin (util_NaN())
  , mIsSetMin (false)
  , mMax (util_NaN())
  , mIsSetMax (false)
  , mGrid (false)
  , mIsSetGrid (false)
  , mReverse (false)
  , mIsSetReverse (false)
  , mStyle ("")
  , mElementName("axis")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedAxis using the given SedNamespaces object @p sedmlns.
 */
SedAxis::SedAxis(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mType (SEDML_AXISTYPE_INVALID)
  , mMin (util_NaN())
  , mIsSetMin (false)
  , mMax (util_NaN())
  , mIsSetMax (false)
  , mGrid (false)
  , mIsSetGrid (false)
  , mReverse (false)
  , mIsSetReverse (false)
  , mStyle ("")
  , mElementName("axis")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedAxis.
 */
SedAxis::SedAxis(const SedAxis& orig)
  : SedBase( orig )
  , mType ( orig.mType )
  , mMin ( orig.mMin )
  , mIsSetMin ( orig.mIsSetMin )
  , mMax ( orig.mMax )
  , mIsSetMax ( orig.mIsSetMax )
  , mGrid ( orig.mGrid )
  , mIsSetGrid ( orig.mIsSetGrid )
  , mReverse ( orig.mReverse )
  , mIsSetReverse ( orig.mIsSetReverse )
  , mStyle ( orig.mStyle )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedAxis.
 */
SedAxis&
SedAxis::operator=(const SedAxis& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mType = rhs.mType;
    mMin = rhs.mMin;
    mIsSetMin = rhs.mIsSetMin;
    mMax = rhs.mMax;
    mIsSetMax = rhs.mIsSetMax;
    mGrid = rhs.mGrid;
    mIsSetGrid = rhs.mIsSetGrid;
    mReverse = rhs.mReverse;
    mIsSetReverse = rhs.mIsSetReverse;
    mStyle = rhs.mStyle;
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAxis object.
 */
SedAxis*
SedAxis::clone() const
{
  return new SedAxis(*this);
}


/*
 * Destructor for SedAxis.
 */
SedAxis::~SedAxis()
{
}


/*
 * Returns the value of the "type" attribute of this SedAxis.
 */
AxisType_t
SedAxis::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this SedAxis.
 */
std::string
SedAxis::getTypeAsString() const
{
  std::string code_str = AxisType_toString(mType);
  return code_str;
}


/*
 * Returns the value of the "min" attribute of this SedAxis.
 */
double
SedAxis::getMin() const
{
  return mMin;
}


/*
 * Returns the value of the "max" attribute of this SedAxis.
 */
double
SedAxis::getMax() const
{
  return mMax;
}


/*
 * Returns the value of the "grid" attribute of this SedAxis.
 */
bool
SedAxis::getGrid() const
{
  return mGrid;
}


/*
 * Returns the value of the "reverse" attribute of this SedAxis.
 */
bool
SedAxis::getReverse() const
{
    return mReverse;
}


/*
 * Returns the value of the "style" attribute of this SedAxis.
 */
const std::string&
SedAxis::getStyle() const
{
  return mStyle;
}


/*
 * Predicate returning @c true if this SedAxis's "type" attribute is set.
 */
bool
SedAxis::isSetType() const
{
  return (mType != SEDML_AXISTYPE_INVALID);
}


/*
 * Predicate returning @c true if this SedAxis's "min" attribute is set.
 */
bool
SedAxis::isSetMin() const
{
  return mIsSetMin;
}


/*
 * Predicate returning @c true if this SedAxis's "max" attribute is set.
 */
bool
SedAxis::isSetMax() const
{
  return mIsSetMax;
}


/*
 * Predicate returning @c true if this SedAxis's "grid" attribute is set.
 */
bool
SedAxis::isSetGrid() const
{
  return mIsSetGrid;
}


/*
 * Predicate returning @c true if this SedAxis's "reverse" attribute is set.
 */
bool
SedAxis::isSetReverse() const
{
    return mIsSetReverse;
}


/*
 * Predicate returning @c true if this SedAxis's "style" attribute is set.
 */
bool
SedAxis::isSetStyle() const
{
  return (mStyle.empty() == false);
}


/*
 * Sets the value of the "type" attribute of this SedAxis.
 */
int
SedAxis::setType(const AxisType_t type)
{
  if (AxisType_isValid(type) == 0)
  {
    mType = SEDML_AXISTYPE_INVALID;
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedAxis.
 */
int
SedAxis::setType(const std::string& type)
{
  mType = AxisType_fromString(type.c_str());

  if (mType == SEDML_AXISTYPE_INVALID)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "min" attribute of this SedAxis.
 */
int
SedAxis::setMin(double min)
{
  mMin = min;
  mIsSetMin = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "max" attribute of this SedAxis.
 */
int
SedAxis::setMax(double max)
{
  mMax = max;
  mIsSetMax = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "grid" attribute of this SedAxis.
 */
int
SedAxis::setGrid(bool grid)
{
  mGrid = grid;
  mIsSetGrid = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "reverse" attribute of this SedAxis.
 */
int
SedAxis::setReverse(bool reverse)
{
    mReverse = reverse;
    mIsSetReverse = true;
    return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "style" attribute of this SedAxis.
 */
int
SedAxis::setStyle(const std::string& style)
{
  if (!(SyntaxChecker::isValidInternalSId(style)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mStyle = style;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "type" attribute of this SedAxis.
 */
int
SedAxis::unsetType()
{
  mType = SEDML_AXISTYPE_INVALID;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "min" attribute of this SedAxis.
 */
int
SedAxis::unsetMin()
{
  mMin = util_NaN();
  mIsSetMin = false;

  if (isSetMin() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "max" attribute of this SedAxis.
 */
int
SedAxis::unsetMax()
{
  mMax = util_NaN();
  mIsSetMax = false;

  if (isSetMax() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "grid" attribute of this SedAxis.
 */
int
SedAxis::unsetGrid()
{
  mGrid = false;
  mIsSetGrid = false;

  if (isSetGrid() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "reverse" attribute of this SedAxis.
 */
int
SedAxis::unsetReverse()
{
    mReverse = false;
    mIsSetReverse = false;

    if (isSetReverse() == false)
    {
        return LIBSEDML_OPERATION_SUCCESS;
    }
    else
    {
        return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets the value of the "style" attribute of this SedAxis.
 */
int
SedAxis::unsetStyle()
{
  mStyle.erase();

  if (mStyle.empty() == true)
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
SedAxis::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetStyle() && mStyle == oldid)
  {
    setStyle(newid);
  }
}


/*
 * Returns the XML element name of this SedAxis object.
 */
const std::string&
SedAxis::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedAxis object.
 */
void
SedAxis::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedAxis object.
 */
int
SedAxis::getTypeCode() const
{
  return SEDML_AXIS;
}


/*
 * Predicate returning @c true if all the required attributes for this SedAxis
 * object have been set.
 */
bool
SedAxis::hasRequiredAttributes() const
{
  bool allPresent = true;

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
SedAxis::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAxis::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAxis::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "grid")
  {
    value = getGrid();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  if (attributeName == "reverse")
  {
      value = getReverse();
      return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "min")
  {
    value = getMin();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "max")
  {
    value = getMax();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::getAttribute(const std::string& attributeName,
                      unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::getAttribute(const std::string& attributeName,
                      std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "type")
  {
    value = getTypeAsString();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "style")
  {
    value = getStyle();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedAxis's attribute "attributeName" is
 * set.
 */
bool
SedAxis::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "type")
  {
    value = isSetType();
  }
  else if (attributeName == "min")
  {
    value = isSetMin();
  }
  else if (attributeName == "max")
  {
    value = isSetMax();
  }
  else if (attributeName == "grid")
  {
    value = isSetGrid();
  }
  else if (attributeName == "reverse")
  {
      value = isSetReverse();
  }
  else if (attributeName == "style")
  {
    value = isSetStyle();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "grid")
  {
    return_value = setGrid(value);
  }
  else if (attributeName == "reverse")
  {
      return_value = setReverse(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "min")
  {
    return_value = setMin(value);
  }
  else if (attributeName == "max")
  {
    return_value = setMax(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::setAttribute(const std::string& attributeName,
                      const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "type")
  {
    return_value = setType(value);
  }
  else if (attributeName == "style")
  {
    return_value = setStyle(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedAxis.
 */
int
SedAxis::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "type")
  {
    value = unsetType();
  }
  else if (attributeName == "min")
  {
    value = unsetMin();
  }
  else if (attributeName == "max")
  {
    value = unsetMax();
  }
  else if (attributeName == "grid")
  {
    value = unsetGrid();
  }
  else if (attributeName == "reverse")
  {
      value = unsetReverse();
  }
  else if (attributeName == "style")
  {
    value = unsetStyle();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedAxis::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("type");

  attributes.add("min");

  attributes.add("max");

  attributes.add("grid");

  attributes.add("reverse");

  attributes.add("style");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAxis::readAttributes(
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
        log->logError(SedmlAxisAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // type enum (use = "required" )
  // 

  std::string type;
  assigned = attributes.readInto("type", type);

  if (assigned == true)
  {
    if (type.empty() == true)
    {
      logEmptyString(type, level, version, "<SedAxis>");
    }
    else
    {
      mType = AxisType_fromString(type.c_str());

      if (log && AxisType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <SedAxis> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logError(SedmlAxisTypeMustBeAxisTypeEnum, level, version, msg,
          getLine(), getColumn());
      }
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'type' is missing.";
      log->logError(SedmlAxisAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // min double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetMin = attributes.readInto("min", mMin);

  if ( mIsSetMin == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'min' from the <SedAxis> element "
        "must be an integer.";
      log->logError(SedmlAxisMinMustBeDouble, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // max double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetMax = attributes.readInto("max", mMax);

  if ( mIsSetMax == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'max' from the <SedAxis> element "
        "must be an integer.";
      log->logError(SedmlAxisMaxMustBeDouble, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // grid bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetGrid = attributes.readInto("grid", mGrid);

  if (mIsSetGrid == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlAxisGridMustBeBoolean, level, version);
    }
  }

  // 
  // reverse bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetReverse = attributes.readInto("reverse", mReverse);

  if (mIsSetReverse == false)
  {
      if (log && log->getNumErrors() == numErrs + 1 &&
          log->contains(XMLAttributeTypeMismatch))
      {
          log->remove(XMLAttributeTypeMismatch);
          log->logError(SedmlAxisReverseMustBeBoolean, level, version);
      }
  }

  // 
  // style SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("style", mStyle);

  if (assigned == true)
  {
    if (mStyle.empty() == true)
    {
      logEmptyString(mStyle, level, version, "<SedAxis>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mStyle) == false)
    {
      std::string msg = "The style attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mStyle + "', which does not conform to the syntax.";
      logError(SedmlAxisStyleMustBeStyle, level, version, msg, getLine(),
        getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedAxis::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), AxisType_toString(mType));
  }

  if (isSetMin() == true)
  {
    stream.writeAttribute("min", getPrefix(), mMin);
  }

  if (isSetMax() == true)
  {
    stream.writeAttribute("max", getPrefix(), mMax);
  }

  if (isSetGrid() == true)
  {
    stream.writeAttribute("grid", getPrefix(), mGrid);
  }

  if (isSetReverse() == true)
  {
      stream.writeAttribute("reverse", getPrefix(), mReverse);
  }

  if (isSetStyle() == true)
  {
    stream.writeAttribute("style", getPrefix(), mStyle);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedAxis_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedAxis_t *
SedAxis_create(unsigned int level, unsigned int version)
{
  return new SedAxis(level, version);
}


/*
 * Creates and returns a deep copy of this SedAxis_t object.
 */
LIBSEDML_EXTERN
SedAxis_t*
SedAxis_clone(const SedAxis_t* sa)
{
  if (sa != NULL)
  {
    return static_cast<SedAxis_t*>(sa->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAxis_t object.
 */
LIBSEDML_EXTERN
void
SedAxis_free(SedAxis_t* sa)
{
  if (sa != NULL)
  {
    delete sa;
  }
}


/*
 * Returns the value of the "type" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
AxisType_t
SedAxis_getType(const SedAxis_t * sa)
{
  if (sa == NULL)
  {
    return SEDML_AXISTYPE_INVALID;
  }

  return sa->getType();
}


/*
 * Returns the value of the "type" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
char *
SedAxis_getTypeAsString(const SedAxis_t * sa)
{
  return (char*)(AxisType_toString(sa->getType()));
}


/*
 * Returns the value of the "min" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
double
SedAxis_getMin(const SedAxis_t * sa)
{
  return (sa != NULL) ? sa->getMin() : util_NaN();
}


/*
 * Returns the value of the "max" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
double
SedAxis_getMax(const SedAxis_t * sa)
{
  return (sa != NULL) ? sa->getMax() : util_NaN();
}


/*
 * Returns the value of the "grid" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_getGrid(const SedAxis_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->getGrid()) : 0;
}


/*
 * Returns the value of the "reverse" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_getReverse(const SedAxis_t* sa)
{
    return (sa != NULL) ? static_cast<int>(sa->getReverse()) : 0;
}


/*
 * Returns the value of the "style" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
char *
SedAxis_getStyle(const SedAxis_t * sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return sa->getStyle().empty() ? NULL : safe_strdup(sa->getStyle().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedAxis_t's "type" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAxis_isSetType(const SedAxis_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetType()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAxis_t's "min" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAxis_isSetMin(const SedAxis_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetMin()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAxis_t's "max" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAxis_isSetMax(const SedAxis_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetMax()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAxis_t's "grid" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAxis_isSetGrid(const SedAxis_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetGrid()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAxis_t's "reverse" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAxis_isSetReverse(const SedAxis_t* sa)
{
    return (sa != NULL) ? static_cast<int>(sa->isSetReverse()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAxis_t's "style" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedAxis_isSetStyle(const SedAxis_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetStyle()) : 0;
}


/*
 * Sets the value of the "type" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_setType(SedAxis_t * sa, AxisType_t type)
{
  return (sa != NULL) ? sa->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_setTypeAsString(SedAxis_t * sa, const char * type)
{
  return (sa != NULL) ? sa->setType(type): LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "min" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_setMin(SedAxis_t * sa, double min)
{
  return (sa != NULL) ? sa->setMin(min) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "max" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_setMax(SedAxis_t * sa, double max)
{
  return (sa != NULL) ? sa->setMax(max) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "grid" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_setGrid(SedAxis_t * sa, int grid)
{
  return (sa != NULL) ? sa->setGrid(grid) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "reverse" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_setReverse(SedAxis_t* sa, int reverse)
{
    return (sa != NULL) ? sa->setReverse(reverse) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "style" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_setStyle(SedAxis_t * sa, const char * style)
{
  return (sa != NULL) ? sa->setStyle(style) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_unsetType(SedAxis_t * sa)
{
  return (sa != NULL) ? sa->unsetType() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "min" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_unsetMin(SedAxis_t * sa)
{
  return (sa != NULL) ? sa->unsetMin() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "max" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_unsetMax(SedAxis_t * sa)
{
  return (sa != NULL) ? sa->unsetMax() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "grid" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_unsetGrid(SedAxis_t * sa)
{
  return (sa != NULL) ? sa->unsetGrid() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "reverse" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_unsetReverse(SedAxis_t* sa)
{
    return (sa != NULL) ? sa->unsetReverse() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "style" attribute of this SedAxis_t.
 */
LIBSEDML_EXTERN
int
SedAxis_unsetStyle(SedAxis_t * sa)
{
  return (sa != NULL) ? sa->unsetStyle() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAxis_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAxis_hasRequiredAttributes(const SedAxis_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


