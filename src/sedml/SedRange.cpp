/**
 * @file SedRange.cpp
 * @brief Implementation of the SedRange class.
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
#include <sedml/SedRange.h>
#include <sedml/SedListOfRanges.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedUniformRange.h>
#include <sedml/SedVectorRange.h>
#include <sedml/SedFunctionalRange.h>
#include <sedml/SedDataRange.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedRange using the given SED-ML Level and @ p version values.
 */
SedRange::SedRange(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mElementName("range")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  mIdAllowedPreV4 = true;
}


/*
 * Creates a new SedRange using the given SedNamespaces object @p sedmlns.
 */
SedRange::SedRange(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mElementName("range")
{
  setElementNamespace(sedmlns->getURI());
  mIdAllowedPreV4 = true;
}


/*
 * Copy constructor for SedRange.
 */
SedRange::SedRange(const SedRange& orig)
  : SedBase( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedRange.
 */
SedRange&
SedRange::operator=(const SedRange& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedRange object.
 */
SedRange*
SedRange::clone() const
{
  return new SedRange(*this);
}


/*
 * Destructor for SedRange.
 */
SedRange::~SedRange()
{
}


/*
 * Predicate returning @c true if this abstract "SedRange" is of type
 * SedUniformRange
 */
bool
SedRange::isSedUniformRange() const
{
  return dynamic_cast<const SedUniformRange*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedRange" is of type
 * SedVectorRange
 */
bool
SedRange::isSedVectorRange() const
{
  return dynamic_cast<const SedVectorRange*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedRange" is of type
 * SedFunctionalRange
 */
bool
SedRange::isSedFunctionalRange() const
{
  return dynamic_cast<const SedFunctionalRange*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedRange" is of type
 * SedDataRange
 */
bool
SedRange::isSedDataRange() const
{
  return dynamic_cast<const SedDataRange*>(this) != NULL;
}


/*
 * Returns the XML element name of this SedRange object.
 */
const std::string&
SedRange::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedRange object.
 */
void
SedRange::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedRange object.
 */
int
SedRange::getTypeCode() const
{
  return SEDML_RANGE;
}


/*
 * Predicate returning @c true if all the required attributes for this SedRange
 * object have been set.
 */
bool
SedRange::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
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
SedRange::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SedRange::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedRange::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedRange's attribute "attributeName" is
 * set.
 */
bool
SedRange::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedRange.
 */
int
SedRange::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedRange::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedRange::readAttributes(
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
    static_cast<SedListOfRanges*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlRepeatedTaskLORangesAllowedCoreAttributes, level,
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
        log->logError(SedmlRangeAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  if(!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedRange> element.";
      log->logError(SedmlRangeAllowedAttributes, level, version, message,
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
SedRange::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedUniformRange using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedUniformRange_t *
SedRange_createUniformRange(unsigned int level, unsigned int version)
{
  return new SedUniformRange(level, version);
}


/*
 * Creates a new SedVectorRange using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedVectorRange_t *
SedRange_createVectorRange(unsigned int level, unsigned int version)
{
  return new SedVectorRange(level, version);
}


/*
 * Creates a new SedFunctionalRange using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedFunctionalRange_t *
SedRange_createFunctionalRange(unsigned int level, unsigned int version)
{
  return new SedFunctionalRange(level, version);
}


/*
 * Creates a new SedDataRange using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedDataRange_t *
SedRange_createDataRange(unsigned int level, unsigned int version)
{
  return new SedDataRange(level, version);
}


/*
 * Creates and returns a deep copy of this SedRange_t object.
 */
LIBSEDML_EXTERN
SedRange_t*
SedRange_clone(const SedRange_t* sr)
{
  if (sr != NULL)
  {
    return static_cast<SedRange_t*>(sr->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedRange_t object.
 */
LIBSEDML_EXTERN
void
SedRange_free(SedRange_t* sr)
{
  if (sr != NULL)
  {
    delete sr;
  }
}


/*
 * Returns the value of the "id" attribute of this SedRange_t.
 */
LIBSEDML_EXTERN
char *
SedRange_getId(const SedRange_t * sr)
{
  if (sr == NULL)
  {
    return NULL;
  }

  return sr->getId().empty() ? NULL : safe_strdup(sr->getId().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedRange_t's "id" attribute is set.
 */
LIBSEDML_EXTERN
int
SedRange_isSetId(const SedRange_t * sr)
{
  return (sr != NULL) ? static_cast<int>(sr->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedRange_t.
 */
LIBSEDML_EXTERN
int
SedRange_setId(SedRange_t * sr, const char * id)
{
  return (sr != NULL) ? sr->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedRange_t.
 */
LIBSEDML_EXTERN
int
SedRange_unsetId(SedRange_t * sr)
{
  return (sr != NULL) ? sr->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if this SedRange_t is of type SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSedUniformRange(const SedRange_t * sr)
{
  return (sr != NULL) ? static_cast<int>(sr->isSedUniformRange()) : 0;
}


/*
 * Predicate returning @c 1 if this SedRange_t is of type SedVectorRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSedVectorRange(const SedRange_t * sr)
{
  return (sr != NULL) ? static_cast<int>(sr->isSedVectorRange()) : 0;
}


/*
 * Predicate returning @c 1 if this SedRange_t is of type SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSedFunctionalRange(const SedRange_t * sr)
{
  return (sr != NULL) ? static_cast<int>(sr->isSedFunctionalRange()) : 0;
}


/*
 * Predicate returning @c 1 if this SedRange_t is of type SedDataRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSedDataRange(const SedRange_t * sr)
{
  return (sr != NULL) ? static_cast<int>(sr->isSedDataRange()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedRange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedRange_hasRequiredAttributes(const SedRange_t * sr)
{
  return (sr != NULL) ? static_cast<int>(sr->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


