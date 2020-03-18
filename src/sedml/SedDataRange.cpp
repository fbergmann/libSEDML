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
 * Creates a new SedDataRange using the given SEDML Level and @ p version
 * values.
 */
SedDataRange::SedDataRange(unsigned int level, unsigned int version)
  : SedRange(level, version)
  , mSourceRef ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedDataRange using the given SedNamespaces object @p sedmlns.
 */
SedDataRange::SedDataRange(SedNamespaces *sedmlns)
  : SedRange(sedmlns)
  , mSourceRef ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedDataRange.
 */
SedDataRange::SedDataRange(const SedDataRange& orig)
  : SedRange( orig )
  , mSourceRef ( orig.mSourceRef )
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
    mSourceRef = rhs.mSourceRef;
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
 * Returns the value of the "sourceRef" attribute of this SedDataRange.
 */
const std::string&
SedDataRange::getSourceRef() const
{
  return mSourceRef;
}


/*
 * Predicate returning @c true if this SedDataRange's "sourceRef" attribute is
 * set.
 */
bool
SedDataRange::isSetSourceRef() const
{
  return (mSourceRef.empty() == false);
}


/*
 * Sets the value of the "sourceRef" attribute of this SedDataRange.
 */
int
SedDataRange::setSourceRef(const std::string& sourceRef)
{
  if (!(SyntaxChecker::isValidInternalSId(sourceRef)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSourceRef = sourceRef;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "sourceRef" attribute of this SedDataRange.
 */
int
SedDataRange::unsetSourceRef()
{
  mSourceRef.erase();

  if (mSourceRef.empty() == true)
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
  if (isSetSourceRef() && mSourceRef == oldid)
  {
    setSourceRef(newid);
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

  if (isSetSourceRef() == false)
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

  if (attributeName == "sourceRef")
  {
    value = getSourceRef();
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

  if (attributeName == "sourceRef")
  {
    value = isSetSourceRef();
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

  if (attributeName == "sourceRef")
  {
    return_value = setSourceRef(value);
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

  if (attributeName == "sourceRef")
  {
    value = unsetSourceRef();
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

  attributes.add("sourceRef");
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
  // sourceRef SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("sourceRef", mSourceRef);

  if (assigned == true)
  {
    if (mSourceRef.empty() == true)
    {
      logEmptyString(mSourceRef, level, version, "<SedDataRange>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mSourceRef) == false)
    {
      std::string msg = "The sourceRef attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mSourceRef + "', which does not conform to the syntax.";
      logError(SedmlDataRangeSourceRefMustBeSId, level, version, msg,
        getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'sourceRef' is missing from the "
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

  if (isSetSourceRef() == true)
  {
    stream.writeAttribute("sourceRef", getPrefix(), mSourceRef);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDataRange_t using the given SEDML Level and @ p version
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
 * Returns the value of the "sourceRef" attribute of this SedDataRange_t.
 */
LIBSEDML_EXTERN
char *
SedDataRange_getSourceRef(const SedDataRange_t * sdr)
{
  if (sdr == NULL)
  {
    return NULL;
  }

  return sdr->getSourceRef().empty() ? NULL :
    safe_strdup(sdr->getSourceRef().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedDataRange_t's "sourceRef"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataRange_isSetSourceRef(const SedDataRange_t * sdr)
{
  return (sdr != NULL) ? static_cast<int>(sdr->isSetSourceRef()) : 0;
}


/*
 * Sets the value of the "sourceRef" attribute of this SedDataRange_t.
 */
LIBSEDML_EXTERN
int
SedDataRange_setSourceRef(SedDataRange_t * sdr, const char * sourceRef)
{
  return (sdr != NULL) ? sdr->setSourceRef(sourceRef) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "sourceRef" attribute of this SedDataRange_t.
 */
LIBSEDML_EXTERN
int
SedDataRange_unsetSourceRef(SedDataRange_t * sdr)
{
  return (sdr != NULL) ? sdr->unsetSourceRef() : LIBSEDML_INVALID_OBJECT;
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


