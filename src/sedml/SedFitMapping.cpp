/**
 * @file SedFitMapping.cpp
 * @brief Implementation of the SedFitMapping class.
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
#include <sedml/SedFitMapping.h>
#include <sedml/SedListOfFitMappings.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedValueScaling.h>
#include <sedml/SedColumnScaling.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedFitMapping using the given SEDML Level and @ p version
 * values.
 */
SedFitMapping::SedFitMapping(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mDataSource ("")
  , mDataGenerator ("")
  , mType (SEDML_MAPPINGTYPE_INVALID)
  , mScaling (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedFitMapping using the given SedNamespaces object @p sedmlns.
 */
SedFitMapping::SedFitMapping(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mDataSource ("")
  , mDataGenerator ("")
  , mType (SEDML_MAPPINGTYPE_INVALID)
  , mScaling (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedFitMapping.
 */
SedFitMapping::SedFitMapping(const SedFitMapping& orig)
  : SedBase( orig )
  , mDataSource ( orig.mDataSource )
  , mDataGenerator ( orig.mDataGenerator )
  , mType ( orig.mType )
  , mScaling ( NULL )
{
  if (orig.mScaling != NULL)
  {
    mScaling = orig.mScaling->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedFitMapping.
 */
SedFitMapping&
SedFitMapping::operator=(const SedFitMapping& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mDataSource = rhs.mDataSource;
    mDataGenerator = rhs.mDataGenerator;
    mType = rhs.mType;
    delete mScaling;
    if (rhs.mScaling != NULL)
    {
      mScaling = rhs.mScaling->clone();
    }
    else
    {
      mScaling = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedFitMapping object.
 */
SedFitMapping*
SedFitMapping::clone() const
{
  return new SedFitMapping(*this);
}


/*
 * Destructor for SedFitMapping.
 */
SedFitMapping::~SedFitMapping()
{
  delete mScaling;
  mScaling = NULL;
}


/*
 * Returns the value of the "dataSource" attribute of this SedFitMapping.
 */
const std::string&
SedFitMapping::getDataSource() const
{
  return mDataSource;
}


/*
 * Returns the value of the "dataGenerator" attribute of this SedFitMapping.
 */
const std::string&
SedFitMapping::getDataGenerator() const
{
  return mDataGenerator;
}


/*
 * Returns the value of the "type" attribute of this SedFitMapping.
 */
MappingType_t
SedFitMapping::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this SedFitMapping.
 */
std::string
SedFitMapping::getTypeAsString() const
{
  std::string code_str = MappingType_toString(mType);
  return code_str;
}


/*
 * Predicate returning @c true if this SedFitMapping's "dataSource" attribute
 * is set.
 */
bool
SedFitMapping::isSetDataSource() const
{
  return (mDataSource.empty() == false);
}


/*
 * Predicate returning @c true if this SedFitMapping's "dataGenerator"
 * attribute is set.
 */
bool
SedFitMapping::isSetDataGenerator() const
{
  return (mDataGenerator.empty() == false);
}


/*
 * Predicate returning @c true if this SedFitMapping's "type" attribute is set.
 */
bool
SedFitMapping::isSetType() const
{
  return (mType != SEDML_MAPPINGTYPE_INVALID);
}


/*
 * Sets the value of the "dataSource" attribute of this SedFitMapping.
 */
int
SedFitMapping::setDataSource(const std::string& dataSource)
{
  if (!(SyntaxChecker::isValidInternalSId(dataSource)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mDataSource = dataSource;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "dataGenerator" attribute of this SedFitMapping.
 */
int
SedFitMapping::setDataGenerator(const std::string& dataGenerator)
{
  if (!(SyntaxChecker::isValidInternalSId(dataGenerator)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mDataGenerator = dataGenerator;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedFitMapping.
 */
int
SedFitMapping::setType(const MappingType_t type)
{
  if (MappingType_isValid(type) == 0)
  {
    mType = SEDML_MAPPINGTYPE_INVALID;
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedFitMapping.
 */
int
SedFitMapping::setType(const std::string& type)
{
  mType = MappingType_fromString(type.c_str());

  if (mType == SEDML_MAPPINGTYPE_INVALID)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "dataSource" attribute of this SedFitMapping.
 */
int
SedFitMapping::unsetDataSource()
{
  mDataSource.erase();

  if (mDataSource.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "dataGenerator" attribute of this SedFitMapping.
 */
int
SedFitMapping::unsetDataGenerator()
{
  mDataGenerator.erase();

  if (mDataGenerator.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "type" attribute of this SedFitMapping.
 */
int
SedFitMapping::unsetType()
{
  mType = SEDML_MAPPINGTYPE_INVALID;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the value of the "scaling" element of this SedFitMapping.
 */
const SedScaling*
SedFitMapping::getScaling() const
{
  return mScaling;
}


/*
 * Returns the value of the "scaling" element of this SedFitMapping.
 */
SedScaling*
SedFitMapping::getScaling()
{
  return mScaling;
}


/*
 * Predicate returning @c true if this SedFitMapping's "scaling" element is
 * set.
 */
bool
SedFitMapping::isSetScaling() const
{
  return (mScaling != NULL);
}


/*
 * Sets the value of the "scaling" element of this SedFitMapping.
 */
int
SedFitMapping::setScaling(const SedScaling* scaling)
{
  if (mScaling == scaling)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (scaling == NULL)
  {
    delete mScaling;
    mScaling = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mScaling;
    mScaling = (scaling != NULL) ? scaling->clone() : NULL;
    if (mScaling != NULL)
    {
      mScaling->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedValueScaling object, adds it to this SedFitMapping object
 * and returns the SedValueScaling object created.
 */
SedValueScaling*
SedFitMapping::createValueScaling()
{
  if (mScaling != NULL)
  {
    delete mScaling;
  }

  mScaling = new SedValueScaling(getSedNamespaces());

  connectToChild();

  return static_cast<SedValueScaling*>(mScaling);
}


/*
 * Creates a new SedColumnScaling object, adds it to this SedFitMapping object
 * and returns the SedColumnScaling object created.
 */
SedColumnScaling*
SedFitMapping::createColumnScaling()
{
  if (mScaling != NULL)
  {
    delete mScaling;
  }

  mScaling = new SedColumnScaling(getSedNamespaces());

  connectToChild();

  return static_cast<SedColumnScaling*>(mScaling);
}


/*
 * Unsets the value of the "scaling" element of this SedFitMapping.
 */
int
SedFitMapping::unsetScaling()
{
  delete mScaling;
  mScaling = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedFitMapping::renameSIdRefs(const std::string& oldid,
                             const std::string& newid)
{
  if (isSetDataSource() && mDataSource == oldid)
  {
    setDataSource(newid);
  }

  if (isSetDataGenerator() && mDataGenerator == oldid)
  {
    setDataGenerator(newid);
  }
}


/*
 * Returns the XML element name of this SedFitMapping object.
 */
const std::string&
SedFitMapping::getElementName() const
{
  static const string name = "fitMapping";
  return name;
}


/*
 * Returns the libSEDML type code for this SedFitMapping object.
 */
int
SedFitMapping::getTypeCode() const
{
  return SEDML_FITMAPPING;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedFitMapping object have been set.
 */
bool
SedFitMapping::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetDataSource() == false)
  {
    allPresent = false;
  }

  if (isSetDataGenerator() == false)
  {
    allPresent = false;
  }

  if (isSetType() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedFitMapping object have been set.
 */
bool
SedFitMapping::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetScaling() == false)
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
SedFitMapping::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (isSetScaling() == true)
  {
    mScaling->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedFitMapping::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedFitMapping::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  if (mScaling != NULL)
  {
    mScaling->setSedDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedFitMapping::connectToChild()
{
  SedBase::connectToChild();

  if (mScaling != NULL)
  {
    mScaling->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::getAttribute(const std::string& attributeName,
                            bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::getAttribute(const std::string& attributeName,
                            int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::getAttribute(const std::string& attributeName,
                            double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::getAttribute(const std::string& attributeName,
                            unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::getAttribute(const std::string& attributeName,
                            std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "dataSource")
  {
    value = getDataSource();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "dataGenerator")
  {
    value = getDataGenerator();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "type")
  {
    value = getTypeAsString();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedFitMapping's attribute
 * "attributeName" is set.
 */
bool
SedFitMapping::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "dataSource")
  {
    value = isSetDataSource();
  }
  else if (attributeName == "dataGenerator")
  {
    value = isSetDataGenerator();
  }
  else if (attributeName == "type")
  {
    value = isSetType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::setAttribute(const std::string& attributeName,
                            unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::setAttribute(const std::string& attributeName,
                            const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "dataSource")
  {
    return_value = setDataSource(value);
  }
  else if (attributeName == "dataGenerator")
  {
    return_value = setDataGenerator(value);
  }
  else if (attributeName == "type")
  {
    return_value = setType(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedFitMapping.
 */
int
SedFitMapping::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "dataSource")
  {
    value = unsetDataSource();
  }
  else if (attributeName == "dataGenerator")
  {
    value = unsetDataGenerator();
  }
  else if (attributeName == "type")
  {
    value = unsetType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedFitMapping.
 */
SedBase*
SedFitMapping::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "valueScaling")
  {
    return createValueScaling();
  }
  else if (elementName == "columnScaling")
  {
    return createColumnScaling();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedFitMapping.
 */
int
SedFitMapping::addChildObject(const std::string& elementName,
                              const SedBase* element)
{
  if (elementName == "valueScaling" && element->getTypeCode() ==
    SEDML_VALUESCALING)
  {
    return setScaling((const SedScaling*)(element));
  }
  else if (elementName == "columnScaling" && element->getTypeCode() ==
    SEDML_COLUMNSCALING)
  {
    return setScaling((const SedScaling*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedFitMapping.
 */
SedBase*
SedFitMapping::removeChildObject(const std::string& elementName,
                                 const std::string& id)
{
  if (elementName == "valueScaling")
  {
    SedScaling * obj = getScaling();
    if (unsetScaling() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "columnScaling")
  {
    SedScaling * obj = getScaling();
    if (unsetScaling() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedFitMapping.
 */
unsigned int
SedFitMapping::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "scaling")
  {
    if (isSetScaling())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedFitMapping.
 */
SedBase*
SedFitMapping::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "scaling")
  {
    return getScaling();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedFitMapping::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mScaling != NULL)
  {
    if (mScaling->getId() == id)
    {
      return mScaling;
    }

    obj = mScaling->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedFitMapping::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "valueScaling")
  {
    if (isSetScaling())
    {
      getErrorLog()->logError(SedmlFitMappingAllowedElements, getLevel(),
        getVersion());
    }

    delete mScaling;
    mScaling = new SedValueScaling(getSedNamespaces());
    obj = mScaling;
  }
  else if (name == "columnScaling")
  {
    if (isSetScaling())
    {
      getErrorLog()->logError(SedmlFitMappingAllowedElements, getLevel(),
        getVersion());
    }

    delete mScaling;
    mScaling = new SedColumnScaling(getSedNamespaces());
    obj = mScaling;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedFitMapping::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("dataSource");

  attributes.add("dataGenerator");

  attributes.add("type");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedFitMapping::readAttributes(
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
    static_cast<SedListOfFitMappings*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlFitExperimentLOFitMappingsAllowedCoreAttributes,
          level, version, details);
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
        log->logError(SedmlFitMappingAllowedAttributes, level, version,
          details);
      }
    }
  }

  // 
  // dataSource SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("dataSource", mDataSource);

  if (assigned == true)
  {
    if (mDataSource.empty() == true)
    {
      logEmptyString(mDataSource, level, version, "<SedFitMapping>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mDataSource) == false)
    {
      std::string msg = "The dataSource attribute on the <" + getElementName()
        + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mDataSource + "', which does not conform to the "
        "syntax.";
      logError(SedmlFitMappingDataSourceMustBeDataSource, level, version, msg);
    }
  }
  else
  {
    std::string message = "Sedml attribute 'dataSource' is missing from the "
      "<SedFitMapping> element.";
    log->logError(SedmlFitMappingAllowedAttributes, level, version, message);
  }

  // 
  // dataGenerator SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("dataGenerator", mDataGenerator);

  if (assigned == true)
  {
    if (mDataGenerator.empty() == true)
    {
      logEmptyString(mDataGenerator, level, version, "<SedFitMapping>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mDataGenerator) == false)
    {
      std::string msg = "The dataGenerator attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mDataGenerator + "', which does not conform to the "
        "syntax.";
      logError(SedmlFitMappingDataGeneratorMustBeDataGenerator, level, version,
        msg);
    }
  }
  else
  {
    std::string message = "Sedml attribute 'dataGenerator' is missing from the "
      "<SedFitMapping> element.";
    log->logError(SedmlFitMappingAllowedAttributes, level, version, message);
  }

  // 
  // type enum (use = "required" )
  // 

  std::string type;
  assigned = attributes.readInto("type", type);

  if (assigned == true)
  {
    if (type.empty() == true)
    {
      logEmptyString(type, level, version, "<SedFitMapping>");
    }
    else
    {
      mType = MappingType_fromString(type.c_str());

      if (MappingType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <SedFitMapping> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logError(SedmlFitMappingTypeMustBeMappingTypeEnum, level, version,
          msg);
      }
    }
  }
  else
  {
    std::string message = "Sedml attribute 'type' is missing.";
    log->logError(SedmlFitMappingAllowedAttributes, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedFitMapping::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetDataSource() == true)
  {
    stream.writeAttribute("dataSource", getPrefix(), mDataSource);
  }

  if (isSetDataGenerator() == true)
  {
    stream.writeAttribute("dataGenerator", getPrefix(), mDataGenerator);
  }

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), MappingType_toString(mType));
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedFitMapping_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedFitMapping_t *
SedFitMapping_create(unsigned int level, unsigned int version)
{
  return new SedFitMapping(level, version);
}


/*
 * Creates and returns a deep copy of this SedFitMapping_t object.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitMapping_clone(const SedFitMapping_t* sfm)
{
  if (sfm != NULL)
  {
    return static_cast<SedFitMapping_t*>(sfm->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedFitMapping_t object.
 */
LIBSEDML_EXTERN
void
SedFitMapping_free(SedFitMapping_t* sfm)
{
  if (sfm != NULL)
  {
    delete sfm;
  }
}


/*
 * Returns the value of the "dataSource" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getDataSource(const SedFitMapping_t * sfm)
{
  if (sfm == NULL)
  {
    return NULL;
  }

  return sfm->getDataSource().empty() ? NULL :
    safe_strdup(sfm->getDataSource().c_str());
}


/*
 * Returns the value of the "dataGenerator" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getDataGenerator(const SedFitMapping_t * sfm)
{
  if (sfm == NULL)
  {
    return NULL;
  }

  return sfm->getDataGenerator().empty() ? NULL :
    safe_strdup(sfm->getDataGenerator().c_str());
}


/*
 * Returns the value of the "type" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
MappingType_t
SedFitMapping_getType(const SedFitMapping_t * sfm)
{
  if (sfm == NULL)
  {
    return SEDML_MAPPINGTYPE_INVALID;
  }

  return sfm->getType();
}


/*
 * Returns the value of the "type" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getTypeAsString(const SedFitMapping_t * sfm)
{
  return (char*)(MappingType_toString(sfm->getType()));
}


/*
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "dataSource"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetDataSource(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->isSetDataSource()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "dataGenerator"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetDataGenerator(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->isSetDataGenerator()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "type" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetType(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->isSetType()) : 0;
}


/*
 * Sets the value of the "dataSource" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_setDataSource(SedFitMapping_t * sfm, const char * dataSource)
{
  return (sfm != NULL) ? sfm->setDataSource(dataSource) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "dataGenerator" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_setDataGenerator(SedFitMapping_t * sfm,
                               const char * dataGenerator)
{
  return (sfm != NULL) ? sfm->setDataGenerator(dataGenerator) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_setType(SedFitMapping_t * sfm, MappingType_t type)
{
  return (sfm != NULL) ? sfm->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_setTypeAsString(SedFitMapping_t * sfm, const char * type)
{
  return (sfm != NULL) ? sfm->setType(type): LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "dataSource" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetDataSource(SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? sfm->unsetDataSource() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "dataGenerator" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetDataGenerator(SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? sfm->unsetDataGenerator() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetType(SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? sfm->unsetType() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "scaling" element of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
const SedScaling_t*
SedFitMapping_getScaling(const SedFitMapping_t * sfm)
{
  if (sfm == NULL)
  {
    return NULL;
  }

  return (SedScaling_t*)(sfm->getScaling());
}


/*
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "scaling" element
 * is set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetScaling(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->isSetScaling()) : 0;
}


/*
 * Sets the value of the "scaling" element of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_setScaling(SedFitMapping_t * sfm, const SedScaling_t* scaling)
{
  return (sfm != NULL) ? sfm->setScaling(scaling) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedValueScaling_t object, adds it to this SedFitMapping_t
 * object and returns the SedValueScaling_t object created.
 */
LIBSEDML_EXTERN
SedValueScaling_t*
SedFitMapping_createValueScaling(SedFitMapping_t* sfm)
{
  return (sfm != NULL) ? sfm->createValueScaling() : NULL;
}


/*
 * Creates a new SedColumnScaling_t object, adds it to this SedFitMapping_t
 * object and returns the SedColumnScaling_t object created.
 */
LIBSEDML_EXTERN
SedColumnScaling_t*
SedFitMapping_createColumnScaling(SedFitMapping_t* sfm)
{
  return (sfm != NULL) ? sfm->createColumnScaling() : NULL;
}


/*
 * Unsets the value of the "scaling" element of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetScaling(SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? sfm->unsetScaling() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFitMapping_t object have been set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_hasRequiredAttributes(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedFitMapping_t object have been set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_hasRequiredElements(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


