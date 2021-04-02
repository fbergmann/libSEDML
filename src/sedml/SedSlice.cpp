/**
 * @file SedSlice.cpp
 * @brief Implementation of the SedSlice class.
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
#include <sedml/SedSlice.h>
#include <sedml/SedListOfSlices.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSlice using the given SED-ML Level and @ p version values.
 */
SedSlice::SedSlice(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mReference ("")
  , mValue ("")
  , mIndex ("")
  , mStartIndex (SEDML_INT_MAX)
  , mIsSetStartIndex (false)
  , mEndIndex (SEDML_INT_MAX)
  , mIsSetEndIndex (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSlice using the given SedNamespaces object @p sedmlns.
 */
SedSlice::SedSlice(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mReference ("")
  , mValue ("")
  , mIndex ("")
  , mStartIndex (SEDML_INT_MAX)
  , mIsSetStartIndex (false)
  , mEndIndex (SEDML_INT_MAX)
  , mIsSetEndIndex (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedSlice.
 */
SedSlice::SedSlice(const SedSlice& orig)
  : SedBase( orig )
  , mReference ( orig.mReference )
  , mValue ( orig.mValue )
  , mIndex ( orig.mIndex )
  , mStartIndex ( orig.mStartIndex )
  , mIsSetStartIndex ( orig.mIsSetStartIndex )
  , mEndIndex ( orig.mEndIndex )
  , mIsSetEndIndex ( orig.mIsSetEndIndex )
{
}


/*
 * Assignment operator for SedSlice.
 */
SedSlice&
SedSlice::operator=(const SedSlice& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mReference = rhs.mReference;
    mValue = rhs.mValue;
    mIndex = rhs.mIndex;
    mStartIndex = rhs.mStartIndex;
    mIsSetStartIndex = rhs.mIsSetStartIndex;
    mEndIndex = rhs.mEndIndex;
    mIsSetEndIndex = rhs.mIsSetEndIndex;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSlice object.
 */
SedSlice*
SedSlice::clone() const
{
  return new SedSlice(*this);
}


/*
 * Destructor for SedSlice.
 */
SedSlice::~SedSlice()
{
}


/*
 * Returns the value of the "reference" attribute of this SedSlice.
 */
const std::string&
SedSlice::getReference() const
{
  return mReference;
}


/*
 * Returns the value of the "value" attribute of this SedSlice.
 */
const std::string&
SedSlice::getValue() const
{
  return mValue;
}


/*
 * Returns the value of the "index" attribute of this SedSlice.
 */
const std::string&
SedSlice::getIndex() const
{
  return mIndex;
}


/*
 * Returns the value of the "startIndex" attribute of this SedSlice.
 */
int
SedSlice::getStartIndex() const
{
  return mStartIndex;
}


/*
 * Returns the value of the "endIndex" attribute of this SedSlice.
 */
int
SedSlice::getEndIndex() const
{
  return mEndIndex;
}


/*
 * Predicate returning @c true if this SedSlice's "reference" attribute is set.
 */
bool
SedSlice::isSetReference() const
{
  return (mReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedSlice's "value" attribute is set.
 */
bool
SedSlice::isSetValue() const
{
  return (mValue.empty() == false);
}


/*
 * Predicate returning @c true if this SedSlice's "index" attribute is set.
 */
bool
SedSlice::isSetIndex() const
{
  return (mIndex.empty() == false);
}


/*
 * Predicate returning @c true if this SedSlice's "startIndex" attribute is
 * set.
 */
bool
SedSlice::isSetStartIndex() const
{
  return mIsSetStartIndex;
}


/*
 * Predicate returning @c true if this SedSlice's "endIndex" attribute is set.
 */
bool
SedSlice::isSetEndIndex() const
{
  return mIsSetEndIndex;
}


/*
 * Sets the value of the "reference" attribute of this SedSlice.
 */
int
SedSlice::setReference(const std::string& reference)
{
  if (!(SyntaxChecker::isValidInternalSId(reference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mReference = reference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "value" attribute of this SedSlice.
 */
int
SedSlice::setValue(const std::string& value)
{
  mValue = value;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "index" attribute of this SedSlice.
 */
int
SedSlice::setIndex(const std::string& index)
{
  if (!(SyntaxChecker::isValidInternalSId(index)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mIndex = index;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "startIndex" attribute of this SedSlice.
 */
int
SedSlice::setStartIndex(int startIndex)
{
  mStartIndex = startIndex;
  mIsSetStartIndex = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "endIndex" attribute of this SedSlice.
 */
int
SedSlice::setEndIndex(int endIndex)
{
  mEndIndex = endIndex;
  mIsSetEndIndex = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "reference" attribute of this SedSlice.
 */
int
SedSlice::unsetReference()
{
  mReference.erase();

  if (mReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "value" attribute of this SedSlice.
 */
int
SedSlice::unsetValue()
{
  mValue.erase();

  if (mValue.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "index" attribute of this SedSlice.
 */
int
SedSlice::unsetIndex()
{
  mIndex.erase();

  if (mIndex.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "startIndex" attribute of this SedSlice.
 */
int
SedSlice::unsetStartIndex()
{
  mStartIndex = SEDML_INT_MAX;
  mIsSetStartIndex = false;

  if (isSetStartIndex() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "endIndex" attribute of this SedSlice.
 */
int
SedSlice::unsetEndIndex()
{
  mEndIndex = SEDML_INT_MAX;
  mIsSetEndIndex = false;

  if (isSetEndIndex() == false)
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
SedSlice::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetReference() && mReference == oldid)
  {
    setReference(newid);
  }

  if (isSetIndex() && mIndex == oldid)
  {
    setIndex(newid);
  }
}


/*
 * Returns the XML element name of this SedSlice object.
 */
const std::string&
SedSlice::getElementName() const
{
  static const string name = "slice";
  return name;
}


/*
 * Returns the libSEDML type code for this SedSlice object.
 */
int
SedSlice::getTypeCode() const
{
  return SEDML_DATA_SLICE;
}


/*
 * Predicate returning @c true if all the required attributes for this SedSlice
 * object have been set.
 */
bool
SedSlice::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetReference() == false)
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
SedSlice::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SedSlice::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSlice::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "startIndex")
  {
    value = getStartIndex();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "endIndex")
  {
    value = getEndIndex();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "reference")
  {
    value = getReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "value")
  {
    value = getValue();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "index")
  {
    value = getIndex();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedSlice's attribute "attributeName" is
 * set.
 */
bool
SedSlice::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "reference")
  {
    value = isSetReference();
  }
  else if (attributeName == "value")
  {
    value = isSetValue();
  }
  else if (attributeName == "index")
  {
    value = isSetIndex();
  }
  else if (attributeName == "startIndex")
  {
    value = isSetStartIndex();
  }
  else if (attributeName == "endIndex")
  {
    value = isSetEndIndex();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "startIndex")
  {
    return_value = setStartIndex(value);
  }
  else if (attributeName == "endIndex")
  {
    return_value = setEndIndex(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "reference")
  {
    return_value = setReference(value);
  }
  else if (attributeName == "value")
  {
    return_value = setValue(value);
  }
  else if (attributeName == "index")
  {
    return_value = setIndex(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedSlice.
 */
int
SedSlice::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "reference")
  {
    value = unsetReference();
  }
  else if (attributeName == "value")
  {
    value = unsetValue();
  }
  else if (attributeName == "index")
  {
    value = unsetIndex();
  }
  else if (attributeName == "startIndex")
  {
    value = unsetStartIndex();
  }
  else if (attributeName == "endIndex")
  {
    value = unsetEndIndex();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSlice::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("reference");

  attributes.add("value");

  attributes.add("index");

  attributes.add("startIndex");

  attributes.add("endIndex");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSlice::readAttributes(
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

  if (log && getParentSedObject() &&
    static_cast<SedListOfSlices*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDataSourceLOSlicesAllowedCoreAttributes, level,
          version, details, getLine(), getColumn());
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
        log->logError(SedmlSliceAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // reference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("reference", mReference);

  if (assigned == true)
  {
    if (mReference.empty() == true)
    {
      logEmptyString(mReference, level, version, "<SedSlice>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mReference) == false)
    {
      std::string msg = "The reference attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mReference + "', which does not conform to the syntax.";
      logError(SedmlSliceReferenceMustBeSId, level, version, msg, getLine(),
        getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'reference' is missing from the "
        "<SedSlice> element.";
      log->logError(SedmlSliceAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // value string (use = "required" )
  // 

  assigned = attributes.readInto("value", mValue);

  if (assigned == true)
  {
    if (mValue.empty() == true)
    {
      logEmptyString(mValue, level, version, "<SedSlice>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'value' is missing from the "
        "<SedSlice> element.";
      log->logError(SedmlSliceAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // index SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("index", mIndex);

  if (assigned == true)
  {
    if (mIndex.empty() == true)
    {
      logEmptyString(mIndex, level, version, "<SedSlice>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mIndex) == false)
    {
      std::string msg = "The index attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mIndex + "', which does not conform to the syntax.";
      logError(SedmlSliceIndexMustBeSId, level, version, msg, getLine(),
        getColumn());
    }
  }

  // 
  // startIndex int (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetStartIndex = attributes.readInto("startIndex", mStartIndex);

  if ( mIsSetStartIndex == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'startIndex' from the <SedSlice> "
        "element must be an integer.";
      log->logError(SedmlSliceStartIndexMustBeInteger, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // endIndex int (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetEndIndex = attributes.readInto("endIndex", mEndIndex);

  if ( mIsSetEndIndex == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'endIndex' from the <SedSlice> "
        "element must be an integer.";
      log->logError(SedmlSliceEndIndexMustBeInteger, level, version, message,
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
SedSlice::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetReference() == true)
  {
    stream.writeAttribute("reference", getPrefix(), mReference);
  }

  if (isSetValue() == true)
  {
    stream.writeAttribute("value", getPrefix(), mValue);
  }

  if (isSetIndex() == true)
  {
    stream.writeAttribute("index", getPrefix(), mIndex);
  }

  if (isSetStartIndex() == true)
  {
    stream.writeAttribute("startIndex", getPrefix(), mStartIndex);
  }

  if (isSetEndIndex() == true)
  {
    stream.writeAttribute("endIndex", getPrefix(), mEndIndex);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSlice_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedSlice_t *
SedSlice_create(unsigned int level, unsigned int version)
{
  return new SedSlice(level, version);
}


/*
 * Creates and returns a deep copy of this SedSlice_t object.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedSlice_clone(const SedSlice_t* ss)
{
  if (ss != NULL)
  {
    return static_cast<SedSlice_t*>(ss->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSlice_t object.
 */
LIBSEDML_EXTERN
void
SedSlice_free(SedSlice_t* ss)
{
  if (ss != NULL)
  {
    delete ss;
  }
}


/*
 * Returns the value of the "reference" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
char *
SedSlice_getReference(const SedSlice_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getReference().empty() ? NULL :
    safe_strdup(ss->getReference().c_str());
}


/*
 * Returns the value of the "value" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
char *
SedSlice_getValue(const SedSlice_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getValue().empty() ? NULL : safe_strdup(ss->getValue().c_str());
}


/*
 * Returns the value of the "index" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
char *
SedSlice_getIndex(const SedSlice_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getIndex().empty() ? NULL : safe_strdup(ss->getIndex().c_str());
}


/*
 * Returns the value of the "startIndex" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_getStartIndex(const SedSlice_t * ss)
{
  return (ss != NULL) ? ss->getStartIndex() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "endIndex" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_getEndIndex(const SedSlice_t * ss)
{
  return (ss != NULL) ? ss->getEndIndex() : SEDML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this SedSlice_t's "reference" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedSlice_isSetReference(const SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSlice_t's "value" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSlice_isSetValue(const SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetValue()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSlice_t's "index" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSlice_isSetIndex(const SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetIndex()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSlice_t's "startIndex" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedSlice_isSetStartIndex(const SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetStartIndex()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSlice_t's "endIndex" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSlice_isSetEndIndex(const SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetEndIndex()) : 0;
}


/*
 * Sets the value of the "reference" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_setReference(SedSlice_t * ss, const char * reference)
{
  return (ss != NULL) ? ss->setReference(reference) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "value" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_setValue(SedSlice_t * ss, const char * value)
{
  return (ss != NULL) ? ss->setValue(value) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "index" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_setIndex(SedSlice_t * ss, const char * index)
{
  return (ss != NULL) ? ss->setIndex(index) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "startIndex" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_setStartIndex(SedSlice_t * ss, int startIndex)
{
  return (ss != NULL) ? ss->setStartIndex(startIndex) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "endIndex" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_setEndIndex(SedSlice_t * ss, int endIndex)
{
  return (ss != NULL) ? ss->setEndIndex(endIndex) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "reference" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_unsetReference(SedSlice_t * ss)
{
  return (ss != NULL) ? ss->unsetReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "value" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_unsetValue(SedSlice_t * ss)
{
  return (ss != NULL) ? ss->unsetValue() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "index" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_unsetIndex(SedSlice_t * ss)
{
  return (ss != NULL) ? ss->unsetIndex() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "startIndex" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_unsetStartIndex(SedSlice_t * ss)
{
  return (ss != NULL) ? ss->unsetStartIndex() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "endIndex" attribute of this SedSlice_t.
 */
LIBSEDML_EXTERN
int
SedSlice_unsetEndIndex(SedSlice_t * ss)
{
  return (ss != NULL) ? ss->unsetEndIndex() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSlice_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSlice_hasRequiredAttributes(const SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


