/**
 * @file SedFill.cpp
 * @brief Implementation of the SedFill class.
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
#include <sedml/SedFill.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedFill using the given SED-ML Level and @ p version values.
 */
SedFill::SedFill(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mColor ("")
  //, mSecondColor ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedFill using the given SedNamespaces object @p sedmlns.
 */
SedFill::SedFill(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mColor ("")
  //, mSecondColor ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedFill.
 */
SedFill::SedFill(const SedFill& orig)
  : SedBase( orig )
  , mColor ( orig.mColor )
  //, mSecondColor ( orig.mSecondColor )
{
}


/*
 * Assignment operator for SedFill.
 */
SedFill&
SedFill::operator=(const SedFill& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mColor = rhs.mColor;
    //mSecondColor = rhs.mSecondColor;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedFill object.
 */
SedFill*
SedFill::clone() const
{
  return new SedFill(*this);
}


/*
 * Destructor for SedFill.
 */
SedFill::~SedFill()
{
}


/*
 * Returns the value of the "color" attribute of this SedFill.
 */
const std::string&
SedFill::getColor() const
{
  return mColor;
}


/*
 * Returns the value of the "secondColor" attribute of this SedFill.
 */
//const std::string&
//SedFill::getSecondColor() const
//{
//  return mSecondColor;
//}


/*
 * Predicate returning @c true if this SedFill's "color" attribute is set.
 */
bool
SedFill::isSetColor() const
{
  return (mColor.empty() == false);
}


/*
 * Predicate returning @c true if this SedFill's "secondColor" attribute is
 * set.
 */
//bool
//SedFill::isSetSecondColor() const
//{
//  return (mSecondColor.empty() == false);
//}


/*
 * Sets the value of the "color" attribute of this SedFill.
 */
int
SedFill::setColor(const std::string& color)
{
  mColor = color;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "secondColor" attribute of this SedFill.
 */
//int
//SedFill::setSecondColor(const std::string& secondColor)
//{
//  mSecondColor = secondColor;
//  return LIBSEDML_OPERATION_SUCCESS;
//}


/*
 * Unsets the value of the "color" attribute of this SedFill.
 */
int
SedFill::unsetColor()
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
 * Unsets the value of the "secondColor" attribute of this SedFill.
 */
//int
//SedFill::unsetSecondColor()
//{
//  mSecondColor.erase();
//
//  if (mSecondColor.empty() == true)
//  {
//    return LIBSEDML_OPERATION_SUCCESS;
//  }
//  else
//  {
//    return LIBSEDML_OPERATION_FAILED;
//  }
//}


/*
 * Returns the XML element name of this SedFill object.
 */
const std::string&
SedFill::getElementName() const
{
  static const string name = "fill";
  return name;
}


/*
 * Returns the libSEDML type code for this SedFill object.
 */
int
SedFill::getTypeCode() const
{
  return SEDML_FILL;
}


/*
 * Predicate returning @c true if all the required attributes for this SedFill
 * object have been set.
 */
bool
SedFill::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetColor() == false)
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
SedFill::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
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
SedFill::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedFill::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::getAttribute(const std::string& attributeName,
                      unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::getAttribute(const std::string& attributeName,
                      std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "color")
  {
    value = getColor();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  //else if (attributeName == "secondColor")
  //{
  //  value = getSecondColor();
  //  return_value = LIBSEDML_OPERATION_SUCCESS;
  //}

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedFill's attribute "attributeName" is
 * set.
 */
bool
SedFill::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "color")
  {
    value = isSetColor();
  }
  //else if (attributeName == "secondColor")
  //{
  //  value = isSetSecondColor();
  //}

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::setAttribute(const std::string& attributeName,
                      const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "color")
  {
    return_value = setColor(value);
  }
  //else if (attributeName == "secondColor")
  //{
  //  return_value = setSecondColor(value);
  //}

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedFill.
 */
int
SedFill::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "color")
  {
    value = unsetColor();
  }
  //else if (attributeName == "secondColor")
  //{
  //  value = unsetSecondColor();
  //}

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedFill::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("color");

  //attributes.add("secondColor");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedFill::readAttributes(
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
        log->logError(SedmlFillAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // color string (use = "required" )
  // 

  assigned = attributes.readInto("color", mColor);

  if (assigned == true)
  {
    if (mColor.empty() == true)
    {
      logEmptyString(mColor, level, version, "<SedFill>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'color' is missing from the "
        "<SedFill> element.";
      log->logError(SedmlFillAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // secondColor string (use = "optional" )
  // 

  //assigned = attributes.readInto("secondColor", mSecondColor);

  //if (assigned == true)
  //{
  //  if (mSecondColor.empty() == true)
  //  {
  //    logEmptyString(mSecondColor, level, version, "<SedFill>");
  //  }
  //}
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedFill::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetColor() == true)
  {
    stream.writeAttribute("color", getPrefix(), mColor);
  }

  //if (isSetSecondColor() == true)
  //{
  //  stream.writeAttribute("secondColor", getPrefix(), mSecondColor);
  //}
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedFill_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedFill_t *
SedFill_create(unsigned int level, unsigned int version)
{
  return new SedFill(level, version);
}


/*
 * Creates and returns a deep copy of this SedFill_t object.
 */
LIBSEDML_EXTERN
SedFill_t*
SedFill_clone(const SedFill_t* sf)
{
  if (sf != NULL)
  {
    return static_cast<SedFill_t*>(sf->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedFill_t object.
 */
LIBSEDML_EXTERN
void
SedFill_free(SedFill_t* sf)
{
  if (sf != NULL)
  {
    delete sf;
  }
}


/*
 * Returns the value of the "color" attribute of this SedFill_t.
 */
LIBSEDML_EXTERN
char *
SedFill_getColor(const SedFill_t * sf)
{
  if (sf == NULL)
  {
    return NULL;
  }

  return sf->getColor().empty() ? NULL : safe_strdup(sf->getColor().c_str());
}


/*
 * Returns the value of the "secondColor" attribute of this SedFill_t.
 */
//LIBSEDML_EXTERN
//char *
//SedFill_getSecondColor(const SedFill_t * sf)
//{
//  if (sf == NULL)
//  {
//    return NULL;
//  }
//
//  return sf->getSecondColor().empty() ? NULL :
//    safe_strdup(sf->getSecondColor().c_str());
//}


/*
 * Predicate returning @c 1 (true) if this SedFill_t's "color" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedFill_isSetColor(const SedFill_t * sf)
{
  return (sf != NULL) ? static_cast<int>(sf->isSetColor()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedFill_t's "secondColor" attribute
 * is set.
 */
//LIBSEDML_EXTERN
//int
//SedFill_isSetSecondColor(const SedFill_t * sf)
//{
//  return (sf != NULL) ? static_cast<int>(sf->isSetSecondColor()) : 0;
//}


/*
 * Sets the value of the "color" attribute of this SedFill_t.
 */
LIBSEDML_EXTERN
int
SedFill_setColor(SedFill_t * sf, const char * color)
{
  return (sf != NULL) ? sf->setColor(color) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "secondColor" attribute of this SedFill_t.
 */
//LIBSEDML_EXTERN
//int
//SedFill_setSecondColor(SedFill_t * sf, const char * secondColor)
//{
//  return (sf != NULL) ? sf->setSecondColor(secondColor) :
//    LIBSEDML_INVALID_OBJECT;
//}


/*
 * Unsets the value of the "color" attribute of this SedFill_t.
 */
LIBSEDML_EXTERN
int
SedFill_unsetColor(SedFill_t * sf)
{
  return (sf != NULL) ? sf->unsetColor() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "secondColor" attribute of this SedFill_t.
 */
//LIBSEDML_EXTERN
//int
//SedFill_unsetSecondColor(SedFill_t * sf)
//{
//  return (sf != NULL) ? sf->unsetSecondColor() : LIBSEDML_INVALID_OBJECT;
//}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFill_t object have been set.
 */
LIBSEDML_EXTERN
int
SedFill_hasRequiredAttributes(const SedFill_t * sf)
{
  return (sf != NULL) ? static_cast<int>(sf->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


