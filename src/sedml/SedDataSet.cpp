/**
 * @file SedDataSet.cpp
 * @brief Implementation of the SedDataSet class.
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
#include <sedml/SedDataSet.h>
#include <sedml/SedListOfDataSets.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedDataSet using the given SED-ML Level and @ p version values.
 */
SedDataSet::SedDataSet(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mLabel ("")
  , mDataReference ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  mNameAllowedPreV4 = true;
  mIdAllowedPreV4 = true;
}


/*
 * Creates a new SedDataSet using the given SedNamespaces object @p sedmlns.
 */
SedDataSet::SedDataSet(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mLabel ("")
  , mDataReference ("")
{
  setElementNamespace(sedmlns->getURI());
  mNameAllowedPreV4 = true;
  mIdAllowedPreV4 = true;
}


/*
 * Copy constructor for SedDataSet.
 */
SedDataSet::SedDataSet(const SedDataSet& orig)
  : SedBase( orig )
  , mLabel ( orig.mLabel )
  , mDataReference ( orig.mDataReference )
{
}


/*
 * Assignment operator for SedDataSet.
 */
SedDataSet&
SedDataSet::operator=(const SedDataSet& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mLabel = rhs.mLabel;
    mDataReference = rhs.mDataReference;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedDataSet object.
 */
SedDataSet*
SedDataSet::clone() const
{
  return new SedDataSet(*this);
}


/*
 * Destructor for SedDataSet.
 */
SedDataSet::~SedDataSet()
{
}


/*
 * Returns the value of the "label" attribute of this SedDataSet.
 */
const std::string&
SedDataSet::getLabel() const
{
  return mLabel;
}


/*
 * Returns the value of the "dataReference" attribute of this SedDataSet.
 */
const std::string&
SedDataSet::getDataReference() const
{
  return mDataReference;
}


/*
 * Predicate returning @c true if this SedDataSet's "label" attribute is set.
 */
bool
SedDataSet::isSetLabel() const
{
  return (mLabel.empty() == false);
}


/*
 * Predicate returning @c true if this SedDataSet's "dataReference" attribute
 * is set.
 */
bool
SedDataSet::isSetDataReference() const
{
  return (mDataReference.empty() == false);
}


/*
 * Sets the value of the "label" attribute of this SedDataSet.
 */
int
SedDataSet::setLabel(const std::string& label)
{
  mLabel = label;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "dataReference" attribute of this SedDataSet.
 */
int
SedDataSet::setDataReference(const std::string& dataReference)
{
  if (!(SyntaxChecker::isValidInternalSId(dataReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mDataReference = dataReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "label" attribute of this SedDataSet.
 */
int
SedDataSet::unsetLabel()
{
  mLabel.erase();

  if (mLabel.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "dataReference" attribute of this SedDataSet.
 */
int
SedDataSet::unsetDataReference()
{
  mDataReference.erase();

  if (mDataReference.empty() == true)
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
SedDataSet::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetDataReference() && mDataReference == oldid)
  {
    setDataReference(newid);
  }
}


/*
 * Returns the XML element name of this SedDataSet object.
 */
const std::string&
SedDataSet::getElementName() const
{
  static const string name = "dataSet";
  return name;
}


/*
 * Returns the libSEDML type code for this SedDataSet object.
 */
int
SedDataSet::getTypeCode() const
{
  return SEDML_OUTPUT_DATASET;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedDataSet object have been set.
 */
bool
SedDataSet::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetLabel() == false)
  {
    allPresent = false;
  }

  if (isSetDataReference() == false)
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
SedDataSet::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SedDataSet::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedDataSet::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "label")
  {
    value = getLabel();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "dataReference")
  {
    value = getDataReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedDataSet's attribute "attributeName"
 * is set.
 */
bool
SedDataSet::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "label")
  {
    value = isSetLabel();
  }
  else if (attributeName == "dataReference")
  {
    value = isSetDataReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "label")
  {
    return_value = setLabel(value);
  }
  else if (attributeName == "dataReference")
  {
    return_value = setDataReference(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedDataSet.
 */
int
SedDataSet::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "label")
  {
    value = unsetLabel();
  }
  else if (attributeName == "dataReference")
  {
    value = unsetDataReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedDataSet::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("label");

  attributes.add("dataReference");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedDataSet::readAttributes(
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
    static_cast<SedListOfDataSets*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlReportLODataSetsAllowedCoreAttributes, level,
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
        log->logError(SedmlDataSetAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  if(!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedDataSet> element.";
      log->logError(SedmlDataSetAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // label string (use = "required" )
  // 

  assigned = attributes.readInto("label", mLabel);

  if (assigned == true)
  {
    if (mLabel.empty() == true)
    {
      logEmptyString(mLabel, level, version, "<SedDataSet>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'label' is missing from the "
        "<SedDataSet> element.";
      log->logError(SedmlDataSetAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // dataReference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("dataReference", mDataReference);

  if (assigned == true)
  {
    if (mDataReference.empty() == true)
    {
      logEmptyString(mDataReference, level, version, "<SedDataSet>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mDataReference) == false)
    {
      std::string msg = "The dataReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mDataReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlDataSetDataReferenceMustBeDataGenerator, level, version,
        msg, getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'dataReference' is missing from "
        "the <SedDataSet> element.";
      log->logError(SedmlDataSetAllowedAttributes, level, version, message,
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
SedDataSet::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetLabel() == true)
  {
    stream.writeAttribute("label", getPrefix(), mLabel);
  }

  if (isSetDataReference() == true)
  {
    stream.writeAttribute("dataReference", getPrefix(), mDataReference);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDataSet_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedDataSet_t *
SedDataSet_create(unsigned int level, unsigned int version)
{
  return new SedDataSet(level, version);
}


/*
 * Creates and returns a deep copy of this SedDataSet_t object.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedDataSet_clone(const SedDataSet_t* sds)
{
  if (sds != NULL)
  {
    return static_cast<SedDataSet_t*>(sds->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedDataSet_t object.
 */
LIBSEDML_EXTERN
void
SedDataSet_free(SedDataSet_t* sds)
{
  if (sds != NULL)
  {
    delete sds;
  }
}


/*
 * Returns the value of the "id" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
char *
SedDataSet_getId(const SedDataSet_t * sds)
{
  if (sds == NULL)
  {
    return NULL;
  }

  return sds->getId().empty() ? NULL : safe_strdup(sds->getId().c_str());
}


/*
 * Returns the value of the "label" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
char *
SedDataSet_getLabel(const SedDataSet_t * sds)
{
  if (sds == NULL)
  {
    return NULL;
  }

  return sds->getLabel().empty() ? NULL : safe_strdup(sds->getLabel().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
char *
SedDataSet_getName(const SedDataSet_t * sds)
{
  if (sds == NULL)
  {
    return NULL;
  }

  return sds->getName().empty() ? NULL : safe_strdup(sds->getName().c_str());
}


/*
 * Returns the value of the "dataReference" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
char *
SedDataSet_getDataReference(const SedDataSet_t * sds)
{
  if (sds == NULL)
  {
    return NULL;
  }

  return sds->getDataReference().empty() ? NULL :
    safe_strdup(sds->getDataReference().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedDataSet_t's "id" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetId(const SedDataSet_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDataSet_t's "label" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetLabel(const SedDataSet_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetLabel()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDataSet_t's "name" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetName(const SedDataSet_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDataSet_t's "dataReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetDataReference(const SedDataSet_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetDataReference()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
int
SedDataSet_setId(SedDataSet_t * sds, const char * id)
{
  return (sds != NULL) ? sds->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "label" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
int
SedDataSet_setLabel(SedDataSet_t * sds, const char * label)
{
  return (sds != NULL) ? sds->setLabel(label) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
int
SedDataSet_setName(SedDataSet_t * sds, const char * name)
{
  return (sds != NULL) ? sds->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "dataReference" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
int
SedDataSet_setDataReference(SedDataSet_t * sds, const char * dataReference)
{
  return (sds != NULL) ? sds->setDataReference(dataReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetId(SedDataSet_t * sds)
{
  return (sds != NULL) ? sds->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "label" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetLabel(SedDataSet_t * sds)
{
  return (sds != NULL) ? sds->unsetLabel() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetName(SedDataSet_t * sds)
{
  return (sds != NULL) ? sds->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "dataReference" attribute of this SedDataSet_t.
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetDataReference(SedDataSet_t * sds)
{
  return (sds != NULL) ? sds->unsetDataReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDataSet_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDataSet_hasRequiredAttributes(const SedDataSet_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


