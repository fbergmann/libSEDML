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


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedFitMapping using the given SED-ML Level and @ p version
 * values.
 */
SedFitMapping::SedFitMapping(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mDataSource ("")
  , mTarget ("")
  , mType (SEDML_MAPPINGTYPE_INVALID)
  , mWeight (util_NaN())
  , mIsSetWeight (false)
  , mPointWeight ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedFitMapping using the given SedNamespaces object @p sedmlns.
 */
SedFitMapping::SedFitMapping(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mDataSource ("")
  , mTarget ("")
  , mType (SEDML_MAPPINGTYPE_INVALID)
  , mWeight (util_NaN())
  , mIsSetWeight (false)
  , mPointWeight ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedFitMapping.
 */
SedFitMapping::SedFitMapping(const SedFitMapping& orig)
  : SedBase( orig )
  , mDataSource ( orig.mDataSource )
  , mTarget ( orig.mTarget )
  , mType ( orig.mType )
  , mWeight ( orig.mWeight )
  , mIsSetWeight ( orig.mIsSetWeight )
  , mPointWeight ( orig.mPointWeight )
{
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
    mTarget = rhs.mTarget;
    mType = rhs.mType;
    mWeight = rhs.mWeight;
    mIsSetWeight = rhs.mIsSetWeight;
    mPointWeight = rhs.mPointWeight;
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
 * Returns the value of the "target" attribute of this SedFitMapping.
 */
const std::string&
SedFitMapping::getTarget() const
{
  return mTarget;
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
 * Returns the value of the "weight" attribute of this SedFitMapping.
 */
double
SedFitMapping::getWeight() const
{
  return mWeight;
}


/*
 * Returns the value of the "pointWeight" attribute of this SedFitMapping.
 */
const std::string&
SedFitMapping::getPointWeight() const
{
  return mPointWeight;
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
 * Predicate returning @c true if this SedFitMapping's "target" attribute is
 * set.
 */
bool
SedFitMapping::isSetTarget() const
{
  return (mTarget.empty() == false);
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
 * Predicate returning @c true if this SedFitMapping's "weight" attribute is
 * set.
 */
bool
SedFitMapping::isSetWeight() const
{
  return mIsSetWeight;
}


/*
 * Predicate returning @c true if this SedFitMapping's "pointWeight" attribute
 * is set.
 */
bool
SedFitMapping::isSetPointWeight() const
{
  return (mPointWeight.empty() == false);
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
 * Sets the value of the "target" attribute of this SedFitMapping.
 */
int
SedFitMapping::setTarget(const std::string& target)
{
  if (!(SyntaxChecker::isValidInternalSId(target)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTarget = target;
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
 * Sets the value of the "weight" attribute of this SedFitMapping.
 */
int
SedFitMapping::setWeight(double weight)
{
  mWeight = weight;
  mIsSetWeight = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "pointWeight" attribute of this SedFitMapping.
 */
int
SedFitMapping::setPointWeight(const std::string& pointWeight)
{
  if (!(SyntaxChecker::isValidInternalSId(pointWeight)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mPointWeight = pointWeight;
    return LIBSEDML_OPERATION_SUCCESS;
  }
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
 * Unsets the value of the "target" attribute of this SedFitMapping.
 */
int
SedFitMapping::unsetTarget()
{
  mTarget.erase();

  if (mTarget.empty() == true)
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
 * Unsets the value of the "weight" attribute of this SedFitMapping.
 */
int
SedFitMapping::unsetWeight()
{
  mWeight = util_NaN();
  mIsSetWeight = false;

  if (isSetWeight() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "pointWeight" attribute of this SedFitMapping.
 */
int
SedFitMapping::unsetPointWeight()
{
  mPointWeight.erase();

  if (mPointWeight.empty() == true)
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
SedFitMapping::renameSIdRefs(const std::string& oldid,
                             const std::string& newid)
{
  if (isSetDataSource() && mDataSource == oldid)
  {
    setDataSource(newid);
  }

  if (isSetTarget() && mTarget == oldid)
  {
    setTarget(newid);
  }

  if (isSetPointWeight() && mPointWeight == oldid)
  {
    setPointWeight(newid);
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

  if (isSetTarget() == false)
  {
    allPresent = false;
  }

  if (isSetType() == false)
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

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "weight")
  {
    value = getWeight();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

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
  else if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "type")
  {
    value = getTypeAsString();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "pointWeight")
  {
    value = getPointWeight();
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
  else if (attributeName == "target")
  {
    value = isSetTarget();
  }
  else if (attributeName == "type")
  {
    value = isSetType();
  }
  else if (attributeName == "weight")
  {
    value = isSetWeight();
  }
  else if (attributeName == "pointWeight")
  {
    value = isSetPointWeight();
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

  if (attributeName == "weight")
  {
    return_value = setWeight(value);
  }

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
  else if (attributeName == "target")
  {
    return_value = setTarget(value);
  }
  else if (attributeName == "type")
  {
    return_value = setType(value);
  }
  else if (attributeName == "pointWeight")
  {
    return_value = setPointWeight(value);
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
  else if (attributeName == "target")
  {
    value = unsetTarget();
  }
  else if (attributeName == "type")
  {
    value = unsetType();
  }
  else if (attributeName == "weight")
  {
    value = unsetWeight();
  }
  else if (attributeName == "pointWeight")
  {
    value = unsetPointWeight();
  }

  return value;
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

  attributes.add("target");

  attributes.add("type");

  attributes.add("weight");

  attributes.add("pointWeight");
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
        log->logError(SedmlFitMappingAllowedAttributes, level, version,
          details, getLine(), getColumn());
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
      logError(SedmlFitMappingDataSourceMustBeDataSource, level, version, msg,
        getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'dataSource' is missing from the "
        "<SedFitMapping> element.";
      log->logError(SedmlFitMappingAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // target SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<SedFitMapping>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mTarget) == false)
    {
      std::string msg = "The target attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTarget + "', which does not conform to the syntax.";
      logError(SedmlFitMappingTargetMustBeDataGenerator, level, version, msg,
        getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'target' is missing from the "
        "<SedFitMapping> element.";
      log->logError(SedmlFitMappingAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
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

      if (log && MappingType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <SedFitMapping> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logError(SedmlFitMappingTypeMustBeMappingTypeEnum, level, version,
          msg, getLine(), getColumn());
      }
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'type' is missing.";
      log->logError(SedmlFitMappingAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // weight double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetWeight = attributes.readInto("weight", mWeight);

  if ( mIsSetWeight == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'weight' from the <SedFitMapping> "
        "element must be an integer.";
      log->logError(SedmlFitMappingWeightMustBeDouble, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // pointWeight SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("pointWeight", mPointWeight);

  if (assigned == true)
  {
    if (mPointWeight.empty() == true)
    {
      logEmptyString(mPointWeight, level, version, "<SedFitMapping>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mPointWeight) == false)
    {
      std::string msg = "The pointWeight attribute on the <" + getElementName()
        + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mPointWeight + "', which does not conform to the "
        "syntax.";
      logError(SedmlFitMappingPointWeightMustBeDataSource, level, version, msg,
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
SedFitMapping::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetDataSource() == true)
  {
    stream.writeAttribute("dataSource", getPrefix(), mDataSource);
  }

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), MappingType_toString(mType));
  }

  if (isSetWeight() == true)
  {
    stream.writeAttribute("weight", getPrefix(), mWeight);
  }

  if (isSetPointWeight() == true)
  {
    stream.writeAttribute("pointWeight", getPrefix(), mPointWeight);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedFitMapping_t using the given SED-ML Level and @ p version
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
 * Returns the value of the "target" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getTarget(const SedFitMapping_t * sfm)
{
  if (sfm == NULL)
  {
    return NULL;
  }

  return sfm->getTarget().empty() ? NULL :
    safe_strdup(sfm->getTarget().c_str());
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
 * Returns the value of the "weight" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
double
SedFitMapping_getWeight(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? sfm->getWeight() : util_NaN();
}


/*
 * Returns the value of the "pointWeight" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getPointWeight(const SedFitMapping_t * sfm)
{
  if (sfm == NULL)
  {
    return NULL;
  }

  return sfm->getPointWeight().empty() ? NULL :
    safe_strdup(sfm->getPointWeight().c_str());
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
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "target" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetTarget(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->isSetTarget()) : 0;
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
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "weight" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetWeight(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->isSetWeight()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "pointWeight"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetPointWeight(const SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? static_cast<int>(sfm->isSetPointWeight()) : 0;
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
 * Sets the value of the "target" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_setTarget(SedFitMapping_t * sfm, const char * target)
{
  return (sfm != NULL) ? sfm->setTarget(target) : LIBSEDML_INVALID_OBJECT;
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
 * Sets the value of the "weight" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_setWeight(SedFitMapping_t * sfm, double weight)
{
  return (sfm != NULL) ? sfm->setWeight(weight) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "pointWeight" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_setPointWeight(SedFitMapping_t * sfm, const char * pointWeight)
{
  return (sfm != NULL) ? sfm->setPointWeight(pointWeight) :
    LIBSEDML_INVALID_OBJECT;
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
 * Unsets the value of the "target" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetTarget(SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? sfm->unsetTarget() : LIBSEDML_INVALID_OBJECT;
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
 * Unsets the value of the "weight" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetWeight(SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? sfm->unsetWeight() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "pointWeight" attribute of this SedFitMapping_t.
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetPointWeight(SedFitMapping_t * sfm)
{
  return (sfm != NULL) ? sfm->unsetPointWeight() : LIBSEDML_INVALID_OBJECT;
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




LIBSEDML_CPP_NAMESPACE_END


