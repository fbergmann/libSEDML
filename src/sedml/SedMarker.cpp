/**
 * @file SedMarker.cpp
 * @brief Implementation of the SedMarker class.
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
#include <sedml/SedMarker.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedMarker using the given SED-ML Level and @ p version values.
 */
SedMarker::SedMarker(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mSize (util_NaN())
  , mIsSetSize (false)
  , mType (SEDML_MARKERTYPE_INVALID)
  , mFill ("")
  , mLineColor ("")
  , mLineThickness (util_NaN())
  , mIsSetLineThickness (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedMarker using the given SedNamespaces object @p sedmlns.
 */
SedMarker::SedMarker(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mSize (util_NaN())
  , mIsSetSize (false)
  , mType (SEDML_MARKERTYPE_INVALID)
  , mFill ("")
  , mLineColor ("")
  , mLineThickness (util_NaN())
  , mIsSetLineThickness (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedMarker.
 */
SedMarker::SedMarker(const SedMarker& orig)
  : SedBase( orig )
  , mSize ( orig.mSize )
  , mIsSetSize ( orig.mIsSetSize )
  , mType ( orig.mType )
  , mFill ( orig.mFill )
  , mLineColor ( orig.mLineColor )
  , mLineThickness ( orig.mLineThickness )
  , mIsSetLineThickness ( orig.mIsSetLineThickness )
{
}


/*
 * Assignment operator for SedMarker.
 */
SedMarker&
SedMarker::operator=(const SedMarker& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mSize = rhs.mSize;
    mIsSetSize = rhs.mIsSetSize;
    mType = rhs.mType;
    mFill = rhs.mFill;
    mLineColor = rhs.mLineColor;
    mLineThickness = rhs.mLineThickness;
    mIsSetLineThickness = rhs.mIsSetLineThickness;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedMarker object.
 */
SedMarker*
SedMarker::clone() const
{
  return new SedMarker(*this);
}


/*
 * Destructor for SedMarker.
 */
SedMarker::~SedMarker()
{
}


/*
 * Returns the value of the "size" attribute of this SedMarker.
 */
double
SedMarker::getSize() const
{
  return mSize;
}


/*
 * Returns the value of the "type" attribute of this SedMarker.
 */
MarkerType_t
SedMarker::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this SedMarker.
 */
std::string
SedMarker::getTypeAsString() const
{
  std::string code_str = MarkerType_toString(mType);
  return code_str;
}


/*
 * Returns the value of the "fill" attribute of this SedMarker.
 */
const std::string&
SedMarker::getFill() const
{
  return mFill;
}


/*
 * Returns the value of the "lineColor" attribute of this SedMarker.
 */
const std::string&
SedMarker::getLineColor() const
{
  return mLineColor;
}


/*
 * Returns the value of the "lineThickness" attribute of this SedMarker.
 */
double
SedMarker::getLineThickness() const
{
  return mLineThickness;
}


/*
 * Predicate returning @c true if this SedMarker's "size" attribute is set.
 */
bool
SedMarker::isSetSize() const
{
  return mIsSetSize;
}


/*
 * Predicate returning @c true if this SedMarker's "type" attribute is set.
 */
bool
SedMarker::isSetType() const
{
  return (mType != SEDML_MARKERTYPE_INVALID);
}


/*
 * Predicate returning @c true if this SedMarker's "fill" attribute is set.
 */
bool
SedMarker::isSetFill() const
{
  return (mFill.empty() == false);
}


/*
 * Predicate returning @c true if this SedMarker's "lineColor" attribute is
 * set.
 */
bool
SedMarker::isSetLineColor() const
{
  return (mLineColor.empty() == false);
}


/*
 * Predicate returning @c true if this SedMarker's "lineThickness" attribute is
 * set.
 */
bool
SedMarker::isSetLineThickness() const
{
  return mIsSetLineThickness;
}


/*
 * Sets the value of the "size" attribute of this SedMarker.
 */
int
SedMarker::setSize(double size)
{
  mSize = size;
  mIsSetSize = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "type" attribute of this SedMarker.
 */
int
SedMarker::setType(const MarkerType_t type)
{
  if (MarkerType_isValid(type) == 0)
  {
    mType = SEDML_MARKERTYPE_INVALID;
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedMarker.
 */
int
SedMarker::setType(const std::string& type)
{
  mType = MarkerType_fromString(type.c_str());

  if (mType == SEDML_MARKERTYPE_INVALID)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "fill" attribute of this SedMarker.
 */
int
SedMarker::setFill(const std::string& fill)
{
  mFill = fill;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "lineColor" attribute of this SedMarker.
 */
int
SedMarker::setLineColor(const std::string& lineColor)
{
  mLineColor = lineColor;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "lineThickness" attribute of this SedMarker.
 */
int
SedMarker::setLineThickness(double lineThickness)
{
  mLineThickness = lineThickness;
  mIsSetLineThickness = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "size" attribute of this SedMarker.
 */
int
SedMarker::unsetSize()
{
  mSize = util_NaN();
  mIsSetSize = false;

  if (isSetSize() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "type" attribute of this SedMarker.
 */
int
SedMarker::unsetType()
{
  mType = SEDML_MARKERTYPE_INVALID;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "fill" attribute of this SedMarker.
 */
int
SedMarker::unsetFill()
{
  mFill.erase();

  if (mFill.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "lineColor" attribute of this SedMarker.
 */
int
SedMarker::unsetLineColor()
{
  mLineColor.erase();

  if (mLineColor.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "lineThickness" attribute of this SedMarker.
 */
int
SedMarker::unsetLineThickness()
{
  mLineThickness = util_NaN();
  mIsSetLineThickness = false;

  if (isSetLineThickness() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedMarker object.
 */
const std::string&
SedMarker::getElementName() const
{
  static const string name = "marker";
  return name;
}


/*
 * Returns the libSEDML type code for this SedMarker object.
 */
int
SedMarker::getTypeCode() const
{
  return SEDML_MARKER;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedMarker object have been set.
 */
bool
SedMarker::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedMarker::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SedMarker::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedMarker::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "size")
  {
    value = getSize();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "lineThickness")
  {
    value = getLineThickness();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "fill")
  {
    value = getFill();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "lineColor")
  {
    value = getLineColor();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedMarker's attribute "attributeName" is
 * set.
 */
bool
SedMarker::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "size")
  {
    value = isSetSize();
  }
  else if (attributeName == "type")
  {
    value = isSetType();
  }
  else if (attributeName == "fill")
  {
    value = isSetFill();
  }
  else if (attributeName == "lineColor")
  {
    value = isSetLineColor();
  }
  else if (attributeName == "lineThickness")
  {
    value = isSetLineThickness();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "size")
  {
    return_value = setSize(value);
  }
  else if (attributeName == "lineThickness")
  {
    return_value = setLineThickness(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "type")
  {
    return_value = setType(value);
  }
  else if (attributeName == "fill")
  {
    return_value = setFill(value);
  }
  else if (attributeName == "lineColor")
  {
    return_value = setLineColor(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedMarker.
 */
int
SedMarker::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "size")
  {
    value = unsetSize();
  }
  else if (attributeName == "type")
  {
    value = unsetType();
  }
  else if (attributeName == "fill")
  {
    value = unsetFill();
  }
  else if (attributeName == "lineColor")
  {
    value = unsetLineColor();
  }
  else if (attributeName == "lineThickness")
  {
    value = unsetLineThickness();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedMarker::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("size");

  attributes.add("type");

  attributes.add("fill");

  attributes.add("lineColor");

  attributes.add("lineThickness");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedMarker::readAttributes(
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
        log->logError(SedmlMarkerAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // size double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetSize = attributes.readInto("size", mSize);

  if ( mIsSetSize == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'size' from the <SedMarker> "
        "element must be an integer.";
      log->logError(SedmlMarkerSizeMustBeDouble, level, version, message,
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
      logEmptyString(type, level, version, "<SedMarker>");
    }
    else
    {
      mType = MarkerType_fromString(type.c_str());

      if (log && MarkerType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <SedMarker> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logError(SedmlMarkerTypeMustBeMarkerTypeEnum, level, version,
          msg, getLine(), getColumn());
      }
    }
  }

  // 
  // fill string (use = "optional" )
  // 

  assigned = attributes.readInto("fill", mFill);

  if (assigned == true)
  {
    if (mFill.empty() == true)
    {
      logEmptyString(mFill, level, version, "<SedMarker>");
    }
  }

  // 
  // lineColor string (use = "optional" )
  // 

  assigned = attributes.readInto("lineColor", mLineColor);

  if (assigned == true)
  {
    if (mLineColor.empty() == true)
    {
      logEmptyString(mLineColor, level, version, "<SedMarker>");
    }
  }

  // 
  // lineThickness double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLineThickness = attributes.readInto("lineThickness", mLineThickness);

  if ( mIsSetLineThickness == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'lineThickness' from the "
        "<SedMarker> element must be an integer.";
      log->logError(SedmlMarkerLineThicknessMustBeDouble, level, version,
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
SedMarker::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetSize() == true)
  {
    stream.writeAttribute("size", getPrefix(), mSize);
  }

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), MarkerType_toString(mType));
  }

  if (isSetFill() == true)
  {
    stream.writeAttribute("fill", getPrefix(), mFill);
  }

  if (isSetLineColor() == true)
  {
    stream.writeAttribute("lineColor", getPrefix(), mLineColor);
  }

  if (isSetLineThickness() == true)
  {
    stream.writeAttribute("lineThickness", getPrefix(), mLineThickness);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedMarker_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedMarker_t *
SedMarker_create(unsigned int level, unsigned int version)
{
  return new SedMarker(level, version);
}


/*
 * Creates and returns a deep copy of this SedMarker_t object.
 */
LIBSEDML_EXTERN
SedMarker_t*
SedMarker_clone(const SedMarker_t* sm)
{
  if (sm != NULL)
  {
    return static_cast<SedMarker_t*>(sm->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedMarker_t object.
 */
LIBSEDML_EXTERN
void
SedMarker_free(SedMarker_t* sm)
{
  if (sm != NULL)
  {
    delete sm;
  }
}


/*
 * Returns the value of the "size" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
double
SedMarker_getSize(const SedMarker_t * sm)
{
  return (sm != NULL) ? sm->getSize() : util_NaN();
}


/*
 * Returns the value of the "type" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
MarkerType_t
SedMarker_getType(const SedMarker_t * sm)
{
  if (sm == NULL)
  {
    return SEDML_MARKERTYPE_INVALID;
  }

  return sm->getType();
}


/*
 * Returns the value of the "type" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
char *
SedMarker_getTypeAsString(const SedMarker_t * sm)
{
  return (char*)(MarkerType_toString(sm->getType()));
}


/*
 * Returns the value of the "fill" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
char *
SedMarker_getFill(const SedMarker_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getFill().empty() ? NULL : safe_strdup(sm->getFill().c_str());
}


/*
 * Returns the value of the "lineColor" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
char *
SedMarker_getLineColor(const SedMarker_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getLineColor().empty() ? NULL :
    safe_strdup(sm->getLineColor().c_str());
}


/*
 * Returns the value of the "lineThickness" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
double
SedMarker_getLineThickness(const SedMarker_t * sm)
{
  return (sm != NULL) ? sm->getLineThickness() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SedMarker_t's "size" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedMarker_isSetSize(const SedMarker_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetSize()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedMarker_t's "type" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedMarker_isSetType(const SedMarker_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetType()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedMarker_t's "fill" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedMarker_isSetFill(const SedMarker_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetFill()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedMarker_t's "lineColor" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedMarker_isSetLineColor(const SedMarker_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetLineColor()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedMarker_t's "lineThickness"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedMarker_isSetLineThickness(const SedMarker_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetLineThickness()) : 0;
}


/*
 * Sets the value of the "size" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_setSize(SedMarker_t * sm, double size)
{
  return (sm != NULL) ? sm->setSize(size) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_setType(SedMarker_t * sm, MarkerType_t type)
{
  return (sm != NULL) ? sm->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_setTypeAsString(SedMarker_t * sm, const char * type)
{
  return (sm != NULL) ? sm->setType(type): LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "fill" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_setFill(SedMarker_t * sm, const char * fill)
{
  return (sm != NULL) ? sm->setFill(fill) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "lineColor" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_setLineColor(SedMarker_t * sm, const char * lineColor)
{
  return (sm != NULL) ? sm->setLineColor(lineColor) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "lineThickness" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_setLineThickness(SedMarker_t * sm, double lineThickness)
{
  return (sm != NULL) ? sm->setLineThickness(lineThickness) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "size" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_unsetSize(SedMarker_t * sm)
{
  return (sm != NULL) ? sm->unsetSize() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_unsetType(SedMarker_t * sm)
{
  return (sm != NULL) ? sm->unsetType() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "fill" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_unsetFill(SedMarker_t * sm)
{
  return (sm != NULL) ? sm->unsetFill() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "lineColor" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_unsetLineColor(SedMarker_t * sm)
{
  return (sm != NULL) ? sm->unsetLineColor() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "lineThickness" attribute of this SedMarker_t.
 */
LIBSEDML_EXTERN
int
SedMarker_unsetLineThickness(SedMarker_t * sm)
{
  return (sm != NULL) ? sm->unsetLineThickness() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedMarker_t object have been set.
 */
LIBSEDML_EXTERN
int
SedMarker_hasRequiredAttributes(const SedMarker_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


