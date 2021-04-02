/**
 * @file SedChangeAttribute.cpp
 * @brief Implementation of the SedChangeAttribute class.
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
#include <sedml/SedChangeAttribute.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedChangeAttribute using the given SED-ML Level and @ p version
 * values.
 */
SedChangeAttribute::SedChangeAttribute(unsigned int level,
                                       unsigned int version)
  : SedChange(level, version)
  , mNewValue ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedChangeAttribute using the given SedNamespaces object @p
 * sedmlns.
 */
SedChangeAttribute::SedChangeAttribute(SedNamespaces *sedmlns)
  : SedChange(sedmlns)
  , mNewValue ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedChangeAttribute.
 */
SedChangeAttribute::SedChangeAttribute(const SedChangeAttribute& orig)
  : SedChange( orig )
  , mNewValue ( orig.mNewValue )
{
}


/*
 * Assignment operator for SedChangeAttribute.
 */
SedChangeAttribute&
SedChangeAttribute::operator=(const SedChangeAttribute& rhs)
{
  if (&rhs != this)
  {
    SedChange::operator=(rhs);
    mNewValue = rhs.mNewValue;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedChangeAttribute object.
 */
SedChangeAttribute*
SedChangeAttribute::clone() const
{
  return new SedChangeAttribute(*this);
}


/*
 * Destructor for SedChangeAttribute.
 */
SedChangeAttribute::~SedChangeAttribute()
{
}


/*
 * Returns the value of the "newValue" attribute of this SedChangeAttribute.
 */
const std::string&
SedChangeAttribute::getNewValue() const
{
  return mNewValue;
}


/*
 * Predicate returning @c true if this SedChangeAttribute's "newValue"
 * attribute is set.
 */
bool
SedChangeAttribute::isSetNewValue() const
{
  return (mNewValue.empty() == false);
}


/*
 * Sets the value of the "newValue" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::setNewValue(const std::string& newValue)
{
  mNewValue = newValue;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "newValue" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::unsetNewValue()
{
  mNewValue.erase();

  if (mNewValue.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedChangeAttribute object.
 */
const std::string&
SedChangeAttribute::getElementName() const
{
  static const string name = "changeAttribute";
  return name;
}


/*
 * Returns the libSEDML type code for this SedChangeAttribute object.
 */
int
SedChangeAttribute::getTypeCode() const
{
  return SEDML_CHANGE_ATTRIBUTE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedChangeAttribute object have been set.
 */
bool
SedChangeAttribute::hasRequiredAttributes() const
{
  bool allPresent = SedChange::hasRequiredAttributes();

  if (isSetNewValue() == false)
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
SedChangeAttribute::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedChange::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedChangeAttribute::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedChangeAttribute::setSedDocument(SedDocument* d)
{
  SedChange::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::getAttribute(const std::string& attributeName,
                                 bool& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::getAttribute(const std::string& attributeName,
                                 int& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::getAttribute(const std::string& attributeName,
                                 double& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::getAttribute(const std::string& attributeName,
                                 unsigned int& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::getAttribute(const std::string& attributeName,
                                 std::string& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "newValue")
  {
    value = getNewValue();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedChangeAttribute's attribute
 * "attributeName" is set.
 */
bool
SedChangeAttribute::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedChange::isSetAttribute(attributeName);

  if (attributeName == "newValue")
  {
    value = isSetNewValue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::setAttribute(const std::string& attributeName,
                                 double value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::setAttribute(const std::string& attributeName,
                                 unsigned int value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChangeAttribute.
 */
int
SedChangeAttribute::setAttribute(const std::string& attributeName,
                                 const std::string& value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  if (attributeName == "newValue")
  {
    return_value = setNewValue(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedChangeAttribute.
 */
int
SedChangeAttribute::unsetAttribute(const std::string& attributeName)
{
  int value = SedChange::unsetAttribute(attributeName);

  if (attributeName == "newValue")
  {
    value = unsetNewValue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedChangeAttribute::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = SedChange::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedChangeAttribute::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedChange::addExpectedAttributes(attributes);

  attributes.add("newValue");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedChangeAttribute::readAttributes(
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

  SedChange::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlChangeAttributeAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // newValue string (use = "required" )
  // 

  assigned = attributes.readInto("newValue", mNewValue);

  if (assigned == true)
  {
    if (mNewValue.empty() == true)
    {
      logEmptyString(mNewValue, level, version, "<SedChangeAttribute>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'newValue' is missing from the "
        "<SedChangeAttribute> element.";
      log->logError(SedmlChangeAttributeAllowedAttributes, level, version,
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
SedChangeAttribute::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedChange::writeAttributes(stream);

  if (isSetNewValue() == true)
  {
    stream.writeAttribute("newValue", getPrefix(), mNewValue);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedChangeAttribute_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedChangeAttribute_t *
SedChangeAttribute_create(unsigned int level, unsigned int version)
{
  return new SedChangeAttribute(level, version);
}


/*
 * Creates and returns a deep copy of this SedChangeAttribute_t object.
 */
LIBSEDML_EXTERN
SedChangeAttribute_t*
SedChangeAttribute_clone(const SedChangeAttribute_t* sca)
{
  if (sca != NULL)
  {
    return static_cast<SedChangeAttribute_t*>(sca->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedChangeAttribute_t object.
 */
LIBSEDML_EXTERN
void
SedChangeAttribute_free(SedChangeAttribute_t* sca)
{
  if (sca != NULL)
  {
    delete sca;
  }
}


/*
 * Returns the value of the "newValue" attribute of this SedChangeAttribute_t.
 */
LIBSEDML_EXTERN
char *
SedChangeAttribute_getNewValue(const SedChangeAttribute_t * sca)
{
  if (sca == NULL)
  {
    return NULL;
  }

  return sca->getNewValue().empty() ? NULL :
    safe_strdup(sca->getNewValue().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedChangeAttribute_t's "newValue"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_isSetNewValue(const SedChangeAttribute_t * sca)
{
  return (sca != NULL) ? static_cast<int>(sca->isSetNewValue()) : 0;
}


/*
 * Sets the value of the "newValue" attribute of this SedChangeAttribute_t.
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_setNewValue(SedChangeAttribute_t * sca,
                               const char * newValue)
{
  return (sca != NULL) ? sca->setNewValue(newValue) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "newValue" attribute of this SedChangeAttribute_t.
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_unsetNewValue(SedChangeAttribute_t * sca)
{
  return (sca != NULL) ? sca->unsetNewValue() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedChangeAttribute_t object have been set.
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_hasRequiredAttributes(const SedChangeAttribute_t * sca)
{
  return (sca != NULL) ? static_cast<int>(sca->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


