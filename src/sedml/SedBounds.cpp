/**
 * @file SedBounds.cpp
 * @brief Implementation of the SedBounds class.
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
#include <sedml/SedBounds.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedBounds using the given SEDML Level and @ p version values.
 */
SedBounds::SedBounds(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mInitialValue (util_NaN())
  , mIsSetInitialValue (false)
  , mLowerBound (util_NaN())
  , mIsSetLowerBound (false)
  , mUpperBound (util_NaN())
  , mIsSetUpperBound (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedBounds using the given SedNamespaces object @p sedmlns.
 */
SedBounds::SedBounds(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mInitialValue (util_NaN())
  , mIsSetInitialValue (false)
  , mLowerBound (util_NaN())
  , mIsSetLowerBound (false)
  , mUpperBound (util_NaN())
  , mIsSetUpperBound (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedBounds.
 */
SedBounds::SedBounds(const SedBounds& orig)
  : SedBase( orig )
  , mInitialValue ( orig.mInitialValue )
  , mIsSetInitialValue ( orig.mIsSetInitialValue )
  , mLowerBound ( orig.mLowerBound )
  , mIsSetLowerBound ( orig.mIsSetLowerBound )
  , mUpperBound ( orig.mUpperBound )
  , mIsSetUpperBound ( orig.mIsSetUpperBound )
{
}


/*
 * Assignment operator for SedBounds.
 */
SedBounds&
SedBounds::operator=(const SedBounds& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mInitialValue = rhs.mInitialValue;
    mIsSetInitialValue = rhs.mIsSetInitialValue;
    mLowerBound = rhs.mLowerBound;
    mIsSetLowerBound = rhs.mIsSetLowerBound;
    mUpperBound = rhs.mUpperBound;
    mIsSetUpperBound = rhs.mIsSetUpperBound;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedBounds object.
 */
SedBounds*
SedBounds::clone() const
{
  return new SedBounds(*this);
}


/*
 * Destructor for SedBounds.
 */
SedBounds::~SedBounds()
{
}


/*
 * Returns the value of the "initialValue" attribute of this SedBounds.
 */
double
SedBounds::getInitialValue() const
{
  return mInitialValue;
}


/*
 * Returns the value of the "lowerBound" attribute of this SedBounds.
 */
double
SedBounds::getLowerBound() const
{
  return mLowerBound;
}


/*
 * Returns the value of the "upperBound" attribute of this SedBounds.
 */
double
SedBounds::getUpperBound() const
{
  return mUpperBound;
}


/*
 * Predicate returning @c true if this SedBounds's "initialValue" attribute is
 * set.
 */
bool
SedBounds::isSetInitialValue() const
{
  return mIsSetInitialValue;
}


/*
 * Predicate returning @c true if this SedBounds's "lowerBound" attribute is
 * set.
 */
bool
SedBounds::isSetLowerBound() const
{
  return mIsSetLowerBound;
}


/*
 * Predicate returning @c true if this SedBounds's "upperBound" attribute is
 * set.
 */
bool
SedBounds::isSetUpperBound() const
{
  return mIsSetUpperBound;
}


/*
 * Sets the value of the "initialValue" attribute of this SedBounds.
 */
int
SedBounds::setInitialValue(double initialValue)
{
  mInitialValue = initialValue;
  mIsSetInitialValue = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "lowerBound" attribute of this SedBounds.
 */
int
SedBounds::setLowerBound(double lowerBound)
{
  mLowerBound = lowerBound;
  mIsSetLowerBound = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "upperBound" attribute of this SedBounds.
 */
int
SedBounds::setUpperBound(double upperBound)
{
  mUpperBound = upperBound;
  mIsSetUpperBound = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "initialValue" attribute of this SedBounds.
 */
int
SedBounds::unsetInitialValue()
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
 * Unsets the value of the "lowerBound" attribute of this SedBounds.
 */
int
SedBounds::unsetLowerBound()
{
  mLowerBound = util_NaN();
  mIsSetLowerBound = false;

  if (isSetLowerBound() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "upperBound" attribute of this SedBounds.
 */
int
SedBounds::unsetUpperBound()
{
  mUpperBound = util_NaN();
  mIsSetUpperBound = false;

  if (isSetUpperBound() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedBounds object.
 */
const std::string&
SedBounds::getElementName() const
{
  static const string name = "bounds";
  return name;
}


/*
 * Returns the libSEDML type code for this SedBounds object.
 */
int
SedBounds::getTypeCode() const
{
  return SEDML_BOUNDS;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedBounds object have been set.
 */
bool
SedBounds::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedBounds::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SedBounds::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedBounds::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::getAttribute(const std::string& attributeName, double& value) const
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
  else if (attributeName == "lowerBound")
  {
    value = getLowerBound();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "upperBound")
  {
    value = getUpperBound();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedBounds's attribute "attributeName" is
 * set.
 */
bool
SedBounds::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "initialValue")
  {
    value = isSetInitialValue();
  }
  else if (attributeName == "lowerBound")
  {
    value = isSetLowerBound();
  }
  else if (attributeName == "upperBound")
  {
    value = isSetUpperBound();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "initialValue")
  {
    return_value = setInitialValue(value);
  }
  else if (attributeName == "lowerBound")
  {
    return_value = setLowerBound(value);
  }
  else if (attributeName == "upperBound")
  {
    return_value = setUpperBound(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedBounds.
 */
int
SedBounds::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "initialValue")
  {
    value = unsetInitialValue();
  }
  else if (attributeName == "lowerBound")
  {
    value = unsetLowerBound();
  }
  else if (attributeName == "upperBound")
  {
    value = unsetUpperBound();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedBounds::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("initialValue");

  attributes.add("lowerBound");

  attributes.add("upperBound");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedBounds::readAttributes(
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
        log->logError(SedmlBoundsAllowedAttributes, level, version, details,
          getLine(), getColumn());
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
        "<SedBounds> element must be an integer.";
      log->logError(SedmlBoundsInitialValueMustBeDouble, level, version,
        message);
    }
  }

  // 
  // lowerBound double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLowerBound = attributes.readInto("lowerBound", mLowerBound);

  if ( mIsSetLowerBound == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'lowerBound' from the <SedBounds> "
        "element must be an integer.";
      log->logError(SedmlBoundsLowerBoundMustBeDouble, level, version,
        message);
    }
  }

  // 
  // upperBound double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetUpperBound = attributes.readInto("upperBound", mUpperBound);

  if ( mIsSetUpperBound == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'upperBound' from the <SedBounds> "
        "element must be an integer.";
      log->logError(SedmlBoundsUpperBoundMustBeDouble, level, version,
        message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedBounds::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetInitialValue() == true)
  {
    stream.writeAttribute("initialValue", getPrefix(), mInitialValue);
  }

  if (isSetLowerBound() == true)
  {
    stream.writeAttribute("lowerBound", getPrefix(), mLowerBound);
  }

  if (isSetUpperBound() == true)
  {
    stream.writeAttribute("upperBound", getPrefix(), mUpperBound);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedBounds_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedBounds_t *
SedBounds_create(unsigned int level, unsigned int version)
{
  return new SedBounds(level, version);
}


/*
 * Creates and returns a deep copy of this SedBounds_t object.
 */
LIBSEDML_EXTERN
SedBounds_t*
SedBounds_clone(const SedBounds_t* sb)
{
  if (sb != NULL)
  {
    return static_cast<SedBounds_t*>(sb->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedBounds_t object.
 */
LIBSEDML_EXTERN
void
SedBounds_free(SedBounds_t* sb)
{
  if (sb != NULL)
  {
    delete sb;
  }
}


/*
 * Returns the value of the "initialValue" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
double
SedBounds_getInitialValue(const SedBounds_t * sb)
{
  return (sb != NULL) ? sb->getInitialValue() : util_NaN();
}


/*
 * Returns the value of the "lowerBound" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
double
SedBounds_getLowerBound(const SedBounds_t * sb)
{
  return (sb != NULL) ? sb->getLowerBound() : util_NaN();
}


/*
 * Returns the value of the "upperBound" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
double
SedBounds_getUpperBound(const SedBounds_t * sb)
{
  return (sb != NULL) ? sb->getUpperBound() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SedBounds_t's "initialValue"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedBounds_isSetInitialValue(const SedBounds_t * sb)
{
  return (sb != NULL) ? static_cast<int>(sb->isSetInitialValue()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedBounds_t's "lowerBound" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedBounds_isSetLowerBound(const SedBounds_t * sb)
{
  return (sb != NULL) ? static_cast<int>(sb->isSetLowerBound()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedBounds_t's "upperBound" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedBounds_isSetUpperBound(const SedBounds_t * sb)
{
  return (sb != NULL) ? static_cast<int>(sb->isSetUpperBound()) : 0;
}


/*
 * Sets the value of the "initialValue" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
int
SedBounds_setInitialValue(SedBounds_t * sb, double initialValue)
{
  return (sb != NULL) ? sb->setInitialValue(initialValue) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "lowerBound" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
int
SedBounds_setLowerBound(SedBounds_t * sb, double lowerBound)
{
  return (sb != NULL) ? sb->setLowerBound(lowerBound) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "upperBound" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
int
SedBounds_setUpperBound(SedBounds_t * sb, double upperBound)
{
  return (sb != NULL) ? sb->setUpperBound(upperBound) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "initialValue" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
int
SedBounds_unsetInitialValue(SedBounds_t * sb)
{
  return (sb != NULL) ? sb->unsetInitialValue() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "lowerBound" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
int
SedBounds_unsetLowerBound(SedBounds_t * sb)
{
  return (sb != NULL) ? sb->unsetLowerBound() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "upperBound" attribute of this SedBounds_t.
 */
LIBSEDML_EXTERN
int
SedBounds_unsetUpperBound(SedBounds_t * sb)
{
  return (sb != NULL) ? sb->unsetUpperBound() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedBounds_t object have been set.
 */
LIBSEDML_EXTERN
int
SedBounds_hasRequiredAttributes(const SedBounds_t * sb)
{
  return (sb != NULL) ? static_cast<int>(sb->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


