/**
 * @file SedDataRange.cpp
 * @brief Implementation of the SedDataRange class.
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
#include <sedml/SedDataRange.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedDataRange using the given SED-ML Level and @ p version
 * values.
 */
SedDataRange::SedDataRange(unsigned int level, unsigned int version)
  : SedRange(level, version)
  , mSourceReference ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedDataRange using the given SedNamespaces object @p sedmlns.
 */
SedDataRange::SedDataRange(SedNamespaces *sedmlns)
  : SedRange(sedmlns)
  , mSourceReference ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedDataRange.
 */
SedDataRange::SedDataRange(const SedDataRange& orig)
  : SedRange( orig )
  , mSourceReference ( orig.mSourceReference )
{
}


/*
 * Assignment operator for SedDataRange.
 */
SedDataRange&
SedDataRange::operator=(const SedDataRange& rhs)
{
  if (&rhs != this)
  {
    SedRange::operator=(rhs);
    mSourceReference = rhs.mSourceReference;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedDataRange object.
 */
SedDataRange*
SedDataRange::clone() const
{
  return new SedDataRange(*this);
}


/*
 * Destructor for SedDataRange.
 */
SedDataRange::~SedDataRange()
{
}


/*
 * Returns the value of the "sourceReference" attribute of this SedDataRange.
 */
const std::string&
SedDataRange::getSourceReference() const
{
  return mSourceReference;
}


/*
 * Predicate returning @c true if this SedDataRange's "sourceReference" attribute is
 * set.
 */
bool
SedDataRange::isSetSourceReference() const
{
  return (mSourceReference.empty() == false);
}


/*
 * Sets the value of the "sourceReference" attribute of this SedDataRange.
 */
int
SedDataRange::setSourceReference(const std::string& sourceReference)
{
  if (!(SyntaxChecker::isValidInternalSId(sourceReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSourceReference = sourceReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "sourceReference" attribute of this SedDataRange.
 */
int
SedDataRange::unsetSourceReference()
{
  mSourceReference.erase();

  if (mSourceReference.empty() == true)
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
SedDataRange::renameSIdRefs(const std::string& oldid,
                            const std::string& newid)
{
  if (isSetSourceReference() && mSourceReference == oldid)
  {
    setSourceReference(newid);
  }
}


/*
 * Returns the XML element name of this SedDataRange object.
 */
const std::string&
SedDataRange::getElementName() const
{
  static const string name = "dataRange";
  return name;
}


/*
 * Returns the libSEDML type code for this SedDataRange object.
 */
int
SedDataRange::getTypeCode() const
{
  return SEDML_DATA_RANGE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedDataRange object have been set.
 */
bool
SedDataRange::hasRequiredAttributes() const
{
  bool allPresent = SedRange::hasRequiredAttributes();

  if (isSetSourceReference() == false)
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
SedDataRange::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedRange::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedDataRange::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedDataRange::setSedDocument(SedDocument* d)
{
  SedRange::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "sourceReference")
  {
    value = getSourceReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedDataRange's attribute "attributeName"
 * is set.
 */
bool
SedDataRange::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedRange::isSetAttribute(attributeName);

  if (attributeName == "sourceReference")
  {
    value = isSetSourceReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  if (attributeName == "sourceReference")
  {
    return_value = setSourceReference(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedDataRange.
 */
int
SedDataRange::unsetAttribute(const std::string& attributeName)
{
  int value = SedRange::unsetAttribute(attributeName);

  if (attributeName == "sourceReference")
  {
    value = unsetSourceReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedDataRange::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedRange::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedDataRange::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedRange::addExpectedAttributes(attributes);

  attributes.add("sourceReference");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedDataRange::readAttributes(
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

  SedRange::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDataRangeAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // sourceReference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("sourceReference", mSourceReference);

  if (assigned == true)
  {
    if (mSourceReference.empty() == true)
    {
      logEmptyString(mSourceReference, level, version, "<SedDataRange>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mSourceReference) == false)
    {
      std::string msg = "The sourceReference attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mSourceReference + "', which does not conform to the syntax.";
      logError(SedmlDataRangeSourceReferenceMustBeSId, level, version, msg,
        getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'sourceReference' is missing from the "
        "<SedDataRange> element.";
      log->logError(SedmlDataRangeAllowedAttributes, level, version, message,
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
SedDataRange::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedRange::writeAttributes(stream);

  if (isSetSourceReference() == true)
  {
    stream.writeAttribute("sourceReference", getPrefix(), mSourceReference);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDataRange_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedDataRange_t *
SedDataRange_create(unsigned int level, unsigned int version)
{
  return new SedDataRange(level, version);
}


/*
 * Creates and returns a deep copy of this SedDataRange_t object.
 */
LIBSEDML_EXTERN
SedDataRange_t*
SedDataRange_clone(const SedDataRange_t* sdr)
{
  if (sdr != NULL)
  {
    return static_cast<SedDataRange_t*>(sdr->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedDataRange_t object.
 */
LIBSEDML_EXTERN
void
SedDataRange_free(SedDataRange_t* sdr)
{
  if (sdr != NULL)
  {
    delete sdr;
  }
}


/*
 * Returns the value of the "sourceReference" attribute of this SedDataRange_t.
 */
LIBSEDML_EXTERN
char *
SedDataRange_getSourceReference(const SedDataRange_t * sdr)
{
  if (sdr == NULL)
  {
    return NULL;
  }

  return sdr->getSourceReference().empty() ? NULL :
    safe_strdup(sdr->getSourceReference().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedDataRange_t's "sourceReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataRange_isSetSourceReference(const SedDataRange_t * sdr)
{
  return (sdr != NULL) ? static_cast<int>(sdr->isSetSourceReference()) : 0;
}


/*
 * Sets the value of the "sourceReference" attribute of this SedDataRange_t.
 */
LIBSEDML_EXTERN
int
SedDataRange_setSourceReference(SedDataRange_t * sdr, const char * sourceReference)
{
  return (sdr != NULL) ? sdr->setSourceReference(sourceReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "sourceReference" attribute of this SedDataRange_t.
 */
LIBSEDML_EXTERN
int
SedDataRange_unsetSourceReference(SedDataRange_t * sdr)
{
  return (sdr != NULL) ? sdr->unsetSourceReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDataRange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDataRange_hasRequiredAttributes(const SedDataRange_t * sdr)
{
  return (sdr != NULL) ? static_cast<int>(sdr->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


