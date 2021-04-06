/**
 * @file SedParameter.cpp
 * @brief Implementation of the SedParameter class.
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
#include <sedml/SedParameter.h>
#include <sedml/SedListOfParameters.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedParameter using the given SED-ML Level and @ p version
 * values.
 */
SedParameter::SedParameter(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mValue (util_NaN())
  , mIsSetValue (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Creates a new SedParameter using the given SedNamespaces object @p sedmlns.
 */
SedParameter::SedParameter(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mValue (util_NaN())
  , mIsSetValue (false)
{
  setElementNamespace(sedmlns->getURI());
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Copy constructor for SedParameter.
 */
SedParameter::SedParameter(const SedParameter& orig)
  : SedBase( orig )
  , mValue ( orig.mValue )
  , mIsSetValue ( orig.mIsSetValue )
{
}


/*
 * Assignment operator for SedParameter.
 */
SedParameter&
SedParameter::operator=(const SedParameter& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mValue = rhs.mValue;
    mIsSetValue = rhs.mIsSetValue;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedParameter object.
 */
SedParameter*
SedParameter::clone() const
{
  return new SedParameter(*this);
}


/*
 * Destructor for SedParameter.
 */
SedParameter::~SedParameter()
{
}


/*
 * Returns the value of the "value" attribute of this SedParameter.
 */
double
SedParameter::getValue() const
{
  return mValue;
}


/*
 * Predicate returning @c true if this SedParameter's "value" attribute is set.
 */
bool
SedParameter::isSetValue() const
{
  return mIsSetValue;
}


/*
 * Sets the value of the "value" attribute of this SedParameter.
 */
int
SedParameter::setValue(double value)
{
  mValue = value;
  mIsSetValue = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "value" attribute of this SedParameter.
 */
int
SedParameter::unsetValue()
{
  mValue = util_NaN();
  mIsSetValue = false;

  if (isSetValue() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedParameter object.
 */
const std::string&
SedParameter::getElementName() const
{
  static const string name = "parameter";
  return name;
}


/*
 * Returns the libSEDML type code for this SedParameter object.
 */
int
SedParameter::getTypeCode() const
{
  return SEDML_PARAMETER;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedParameter object have been set.
 */
bool
SedParameter::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetValue() == false)
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
SedParameter::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SedParameter::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedParameter::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "value")
  {
    value = getValue();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedParameter's attribute "attributeName"
 * is set.
 */
bool
SedParameter::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "value")
  {
    value = isSetValue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "value")
  {
    return_value = setValue(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedParameter.
 */
int
SedParameter::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "value")
  {
    value = unsetValue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedParameter::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("value");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedParameter::readAttributes(
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
    static_cast<SedListOfParameters*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDataGeneratorLOParametersAllowedCoreAttributes,
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
        log->logError(SedmlParameterAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  if(!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedParameter> element.";
      log->logError(SedmlParameterAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // value double (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetValue = attributes.readInto("value", mValue);

  if ( mIsSetValue == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'value' from the <SedParameter> "
        "element must be an integer.";
      log->logError(SedmlParameterValueMustBeDouble, level, version, message,
        getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'value' is missing from the "
        "<SedParameter> element.";
      log->logError(SedmlParameterAllowedAttributes, level, version, message,
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
SedParameter::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetValue() == true)
  {
    stream.writeAttribute("value", getPrefix(), mValue);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedParameter_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedParameter_t *
SedParameter_create(unsigned int level, unsigned int version)
{
  return new SedParameter(level, version);
}


/*
 * Creates and returns a deep copy of this SedParameter_t object.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedParameter_clone(const SedParameter_t* sp)
{
  if (sp != NULL)
  {
    return static_cast<SedParameter_t*>(sp->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedParameter_t object.
 */
LIBSEDML_EXTERN
void
SedParameter_free(SedParameter_t* sp)
{
  if (sp != NULL)
  {
    delete sp;
  }
}


/*
 * Returns the value of the "id" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
char *
SedParameter_getId(const SedParameter_t * sp)
{
  if (sp == NULL)
  {
    return NULL;
  }

  return sp->getId().empty() ? NULL : safe_strdup(sp->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
char *
SedParameter_getName(const SedParameter_t * sp)
{
  if (sp == NULL)
  {
    return NULL;
  }

  return sp->getName().empty() ? NULL : safe_strdup(sp->getName().c_str());
}


/*
 * Returns the value of the "value" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
double
SedParameter_getValue(const SedParameter_t * sp)
{
  return (sp != NULL) ? sp->getValue() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SedParameter_t's "id" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedParameter_isSetId(const SedParameter_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedParameter_t's "name" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedParameter_isSetName(const SedParameter_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedParameter_t's "value" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedParameter_isSetValue(const SedParameter_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetValue()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
int
SedParameter_setId(SedParameter_t * sp, const char * id)
{
  return (sp != NULL) ? sp->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
int
SedParameter_setName(SedParameter_t * sp, const char * name)
{
  return (sp != NULL) ? sp->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "value" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
int
SedParameter_setValue(SedParameter_t * sp, double value)
{
  return (sp != NULL) ? sp->setValue(value) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
int
SedParameter_unsetId(SedParameter_t * sp)
{
  return (sp != NULL) ? sp->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
int
SedParameter_unsetName(SedParameter_t * sp)
{
  return (sp != NULL) ? sp->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "value" attribute of this SedParameter_t.
 */
LIBSEDML_EXTERN
int
SedParameter_unsetValue(SedParameter_t * sp)
{
  return (sp != NULL) ? sp->unsetValue() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedParameter_t object have been set.
 */
LIBSEDML_EXTERN
int
SedParameter_hasRequiredAttributes(const SedParameter_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


