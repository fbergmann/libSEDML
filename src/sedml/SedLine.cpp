/**
 * @file SedLine.cpp
 * @brief Implementation of the SedLine class.
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
#include <sedml/SedLine.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedLine using the given SED-ML Level and @ p version values.
 */
SedLine::SedLine(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mType (SEDML_LINETYPE_INVALID)
  , mColor ("")
  , mThickness (util_NaN())
  , mIsSetThickness (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedLine using the given SedNamespaces object @p sedmlns.
 */
SedLine::SedLine(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mType (SEDML_LINETYPE_INVALID)
  , mColor ("")
  , mThickness (util_NaN())
  , mIsSetThickness (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedLine.
 */
SedLine::SedLine(const SedLine& orig)
  : SedBase( orig )
  , mType ( orig.mType )
  , mColor ( orig.mColor )
  , mThickness ( orig.mThickness )
  , mIsSetThickness ( orig.mIsSetThickness )
{
}


/*
 * Assignment operator for SedLine.
 */
SedLine&
SedLine::operator=(const SedLine& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mType = rhs.mType;
    mColor = rhs.mColor;
    mThickness = rhs.mThickness;
    mIsSetThickness = rhs.mIsSetThickness;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedLine object.
 */
SedLine*
SedLine::clone() const
{
  return new SedLine(*this);
}


/*
 * Destructor for SedLine.
 */
SedLine::~SedLine()
{
}


/*
 * Returns the value of the "type" attribute of this SedLine.
 */
LineType_t
SedLine::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this SedLine.
 */
std::string
SedLine::getTypeAsString() const
{
  std::string code_str = LineType_toString(mType);
  return code_str;
}


/*
 * Returns the value of the "color" attribute of this SedLine.
 */
const std::string&
SedLine::getColor() const
{
  return mColor;
}


/*
 * Returns the value of the "thickness" attribute of this SedLine.
 */
double
SedLine::getThickness() const
{
  return mThickness;
}


/*
 * Predicate returning @c true if this SedLine's "type" attribute is set.
 */
bool
SedLine::isSetType() const
{
  return (mType != SEDML_LINETYPE_INVALID);
}


/*
 * Predicate returning @c true if this SedLine's "color" attribute is set.
 */
bool
SedLine::isSetColor() const
{
  return (mColor.empty() == false);
}


/*
 * Predicate returning @c true if this SedLine's "thickness" attribute is set.
 */
bool
SedLine::isSetThickness() const
{
  return mIsSetThickness;
}


/*
 * Sets the value of the "type" attribute of this SedLine.
 */
int
SedLine::setType(const LineType_t type)
{
  if (LineType_isValid(type) == 0)
  {
    mType = SEDML_LINETYPE_INVALID;
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedLine.
 */
int
SedLine::setType(const std::string& type)
{
  mType = LineType_fromString(type.c_str());

  if (mType == SEDML_LINETYPE_INVALID)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "color" attribute of this SedLine.
 */
int
SedLine::setColor(const std::string& color)
{
  mColor = color;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "thickness" attribute of this SedLine.
 */
int
SedLine::setThickness(double thickness)
{
  mThickness = thickness;
  mIsSetThickness = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "type" attribute of this SedLine.
 */
int
SedLine::unsetType()
{
  mType = SEDML_LINETYPE_INVALID;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "color" attribute of this SedLine.
 */
int
SedLine::unsetColor()
{
  mColor.erase();

  if (mColor.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "thickness" attribute of this SedLine.
 */
int
SedLine::unsetThickness()
{
  mThickness = util_NaN();
  mIsSetThickness = false;

  if (isSetThickness() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedLine object.
 */
const std::string&
SedLine::getElementName() const
{
  static const string name = "line";
  return name;
}


/*
 * Returns the libSEDML type code for this SedLine object.
 */
int
SedLine::getTypeCode() const
{
  return SEDML_LINE;
}


/*
 * Predicate returning @c true if all the required attributes for this SedLine
 * object have been set.
 */
bool
SedLine::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedLine::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
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
SedLine::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedLine::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "thickness")
  {
    value = getThickness();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::getAttribute(const std::string& attributeName,
                      unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "color")
  {
    value = getColor();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedLine's attribute "attributeName" is
 * set.
 */
bool
SedLine::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "type")
  {
    value = isSetType();
  }
  else if (attributeName == "color")
  {
    value = isSetColor();
  }
  else if (attributeName == "thickness")
  {
    value = isSetThickness();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "thickness")
  {
    return_value = setThickness(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::setAttribute(const std::string& attributeName,
                      const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "type")
  {
    return_value = setType(value);
  }
  else if (attributeName == "color")
  {
    return_value = setColor(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedLine.
 */
int
SedLine::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "type")
  {
    value = unsetType();
  }
  else if (attributeName == "color")
  {
    value = unsetColor();
  }
  else if (attributeName == "thickness")
  {
    value = unsetThickness();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedLine::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("type");

  attributes.add("color");

  attributes.add("thickness");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedLine::readAttributes(
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
        log->logError(SedmlLineAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
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
      logEmptyString(type, level, version, "<SedLine>");
    }
    else
    {
      mType = LineType_fromString(type.c_str());

      if (log && LineType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <SedLine> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logError(SedmlLineTypeMustBeLineTypeEnum, level, version, msg,
          getLine(), getColumn());
      }
    }
  }

  // 
  // color string (use = "optional" )
  // 

  assigned = attributes.readInto("color", mColor);

  if (assigned == true)
  {
    if (mColor.empty() == true)
    {
      logEmptyString(mColor, level, version, "<SedLine>");
    }
  }

  // 
  // thickness double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetThickness = attributes.readInto("thickness", mThickness);

  if ( mIsSetThickness == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'thickness' from the <SedLine> "
        "element must be an integer.";
      log->logError(SedmlLineThicknessMustBeDouble, level, version, message,
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
SedLine::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), LineType_toString(mType));
  }

  if (isSetColor() == true)
  {
    stream.writeAttribute("color", getPrefix(), mColor);
  }

  if (isSetThickness() == true)
  {
    stream.writeAttribute("thickness", getPrefix(), mThickness);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedLine_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedLine_t *
SedLine_create(unsigned int level, unsigned int version)
{
  return new SedLine(level, version);
}


/*
 * Creates and returns a deep copy of this SedLine_t object.
 */
LIBSEDML_EXTERN
SedLine_t*
SedLine_clone(const SedLine_t* sl)
{
  if (sl != NULL)
  {
    return static_cast<SedLine_t*>(sl->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedLine_t object.
 */
LIBSEDML_EXTERN
void
SedLine_free(SedLine_t* sl)
{
  if (sl != NULL)
  {
    delete sl;
  }
}


/*
 * Returns the value of the "type" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
LineType_t
SedLine_getType(const SedLine_t * sl)
{
  if (sl == NULL)
  {
    return SEDML_LINETYPE_INVALID;
  }

  return sl->getType();
}


/*
 * Returns the value of the "type" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
char *
SedLine_getTypeAsString(const SedLine_t * sl)
{
  return (char*)(LineType_toString(sl->getType()));
}


/*
 * Returns the value of the "color" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
char *
SedLine_getColor(const SedLine_t * sl)
{
  if (sl == NULL)
  {
    return NULL;
  }

  return sl->getColor().empty() ? NULL : safe_strdup(sl->getColor().c_str());
}


/*
 * Returns the value of the "thickness" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
double
SedLine_getThickness(const SedLine_t * sl)
{
  return (sl != NULL) ? sl->getThickness() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SedLine_t's "type" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedLine_isSetType(const SedLine_t * sl)
{
  return (sl != NULL) ? static_cast<int>(sl->isSetType()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedLine_t's "color" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedLine_isSetColor(const SedLine_t * sl)
{
  return (sl != NULL) ? static_cast<int>(sl->isSetColor()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedLine_t's "thickness" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedLine_isSetThickness(const SedLine_t * sl)
{
  return (sl != NULL) ? static_cast<int>(sl->isSetThickness()) : 0;
}


/*
 * Sets the value of the "type" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
int
SedLine_setType(SedLine_t * sl, LineType_t type)
{
  return (sl != NULL) ? sl->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
int
SedLine_setTypeAsString(SedLine_t * sl, const char * type)
{
  return (sl != NULL) ? sl->setType(type): LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "color" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
int
SedLine_setColor(SedLine_t * sl, const char * color)
{
  return (sl != NULL) ? sl->setColor(color) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "thickness" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
int
SedLine_setThickness(SedLine_t * sl, double thickness)
{
  return (sl != NULL) ? sl->setThickness(thickness) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
int
SedLine_unsetType(SedLine_t * sl)
{
  return (sl != NULL) ? sl->unsetType () : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "color" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
int
SedLine_unsetColor(SedLine_t * sl)
{
  return (sl != NULL) ? sl->unsetColor() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "thickness" attribute of this SedLine_t.
 */
LIBSEDML_EXTERN
int
SedLine_unsetThickness(SedLine_t * sl)
{
  return (sl != NULL) ? sl->unsetThickness() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedLine_t object have been set.
 */
LIBSEDML_EXTERN
int
SedLine_hasRequiredAttributes(const SedLine_t * sl)
{
  return (sl != NULL) ? static_cast<int>(sl->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


