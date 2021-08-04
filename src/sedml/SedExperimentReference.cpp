/**
 * @file SedExperimentReference.cpp
 * @brief Implementation of the SedExperimentReference class.
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
#include <sedml/SedExperimentReference.h>
#include <sedml/SedListOfExperimentReferences.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedExperimentReference using the given SED-ML Level and @ p version
 * values.
 */
SedExperimentReference::SedExperimentReference(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mExperimentId ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedExperimentReference using the given SedNamespaces object @p
 * sedmlns.
 */
SedExperimentReference::SedExperimentReference(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mExperimentId ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedExperimentReference.
 */
SedExperimentReference::SedExperimentReference(const SedExperimentReference& orig)
  : SedBase( orig )
  , mExperimentId ( orig.mExperimentId )
{
}


/*
 * Assignment operator for SedExperimentReference.
 */
SedExperimentReference&
SedExperimentReference::operator=(const SedExperimentReference& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mExperimentId = rhs.mExperimentId;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedExperimentReference object.
 */
SedExperimentReference*
SedExperimentReference::clone() const
{
  return new SedExperimentReference(*this);
}


/*
 * Destructor for SedExperimentReference.
 */
SedExperimentReference::~SedExperimentReference()
{
}


/*
 * Returns the value of the "experimentId" attribute of this SedExperimentReference.
 */
const std::string&
SedExperimentReference::getExperimentId() const
{
  return mExperimentId;
}


/*
 * Predicate returning @c true if this SedExperimentReference's "experimentId"
 * attribute is set.
 */
bool
SedExperimentReference::isSetExperimentId() const
{
  return (mExperimentId.empty() == false);
}


/*
 * Sets the value of the "experimentId" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::setExperimentId(const std::string& experimentId)
{
  if (!(SyntaxChecker::isValidInternalSId(experimentId)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mExperimentId = experimentId;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "experimentId" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::unsetExperimentId()
{
  mExperimentId.erase();

  if (mExperimentId.empty() == true)
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
SedExperimentReference::renameSIdRefs(const std::string& oldid,
                                const std::string& newid)
{
  if (isSetExperimentId() && mExperimentId == oldid)
  {
    setExperimentId(newid);
  }
}


/*
 * Returns the XML element name of this SedExperimentReference object.
 */
const std::string&
SedExperimentReference::getElementName() const
{
  static const string name = "experimentReference";
  return name;
}


/*
 * Returns the libSEDML type code for this SedExperimentReference object.
 */
int
SedExperimentReference::getTypeCode() const
{
  return SEDML_EXPERIMENT_REFERENCE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedExperimentReference object have been set.
 */
bool
SedExperimentReference::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedExperimentReference::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedExperimentReference::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedExperimentReference::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::getAttribute(const std::string& attributeName,
                               bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::getAttribute(const std::string& attributeName,
                               int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::getAttribute(const std::string& attributeName,
                               double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::getAttribute(const std::string& attributeName,
                               unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::getAttribute(const std::string& attributeName,
                               std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "experimentId")
  {
    value = getExperimentId();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedExperimentReference's attribute
 * "attributeName" is set.
 */
bool
SedExperimentReference::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "experimentId")
  {
    value = isSetExperimentId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::setAttribute(const std::string& attributeName,
                               unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::setAttribute(const std::string& attributeName,
                               const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "experimentId")
  {
    return_value = setExperimentId(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedExperimentReference.
 */
int
SedExperimentReference::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "experimentId")
  {
    value = unsetExperimentId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedExperimentReference::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("experimentId");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedExperimentReference::readAttributes(
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
    static_cast<SedListOfExperimentReferences*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlAdjustableParameterLOExperimentReferencesAllowedCoreAttributes,
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
        log->logError(SedmlExperimentReferenceAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // experimentId SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("experimentId", mExperimentId);

  if (assigned == true)
  {
    if (mExperimentId.empty() == true)
    {
      logEmptyString(mExperimentId, level, version, "<SedExperimentReference>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mExperimentId) == false)
    {
      std::string msg = "The experimentId attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mExperimentId + "', which does not conform to the "
        "syntax.";
      logError(SedmlExperimentReferenceExperimentIdMustBeFitExperiment, level,
        version, msg, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedExperimentReference::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetExperimentId() == true)
  {
    stream.writeAttribute("experimentId", getPrefix(), mExperimentId);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedExperimentReference_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedExperimentReference_t *
SedExperimentReference_create(unsigned int level, unsigned int version)
{
  return new SedExperimentReference(level, version);
}


/*
 * Creates and returns a deep copy of this SedExperimentReference_t object.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedExperimentReference_clone(const SedExperimentReference_t* ser)
{
  if (ser != NULL)
  {
    return static_cast<SedExperimentReference_t*>(ser->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedExperimentReference_t object.
 */
LIBSEDML_EXTERN
void
SedExperimentReference_free(SedExperimentReference_t* ser)
{
  if (ser != NULL)
  {
    delete ser;
  }
}


/*
 * Returns the value of the "experimentId" attribute of this
 * SedExperimentReference_t.
 */
LIBSEDML_EXTERN
char *
SedExperimentReference_getExperimentId(const SedExperimentReference_t * ser)
{
  if (ser == NULL)
  {
    return NULL;
  }

  return ser->getExperimentId().empty() ? NULL :
    safe_strdup(ser->getExperimentId().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedExperimentReference_t's "experimentId"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedExperimentReference_isSetExperimentId(const SedExperimentReference_t * ser)
{
  return (ser != NULL) ? static_cast<int>(ser->isSetExperimentId()) : 0;
}


/*
 * Sets the value of the "experimentId" attribute of this SedExperimentReference_t.
 */
LIBSEDML_EXTERN
int
SedExperimentReference_setExperimentId(SedExperimentReference_t * ser,
                                 const char * experimentId)
{
  return (ser != NULL) ? ser->setExperimentId(experimentId) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "experimentId" attribute of this SedExperimentReference_t.
 */
LIBSEDML_EXTERN
int
SedExperimentReference_unsetExperimentId(SedExperimentReference_t * ser)
{
  return (ser != NULL) ? ser->unsetExperimentId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedExperimentReference_t object have been set.
 */
LIBSEDML_EXTERN
int
SedExperimentReference_hasRequiredAttributes(const SedExperimentReference_t * ser)
{
  return (ser != NULL) ? static_cast<int>(ser->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


