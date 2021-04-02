/**
 * @file SedRemainingDimension.cpp
 * @brief Implementation of the SedRemainingDimension class.
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
#include <sedml/SedRemainingDimension.h>
#include <sedml/SedListOfRemainingDimensions.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedRemainingDimension using the given SED-ML Level and @ p
 * version values.
 */
SedRemainingDimension::SedRemainingDimension(unsigned int level,
                                             unsigned int version)
  : SedBase(level, version)
  , mTarget ("")
  , mDimensionTarget ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedRemainingDimension using the given SedNamespaces object @p
 * sedmlns.
 */
SedRemainingDimension::SedRemainingDimension(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mTarget ("")
  , mDimensionTarget ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedRemainingDimension.
 */
SedRemainingDimension::SedRemainingDimension(const SedRemainingDimension& orig)
  : SedBase( orig )
  , mTarget ( orig.mTarget )
  , mDimensionTarget ( orig.mDimensionTarget )
{
}


/*
 * Assignment operator for SedRemainingDimension.
 */
SedRemainingDimension&
SedRemainingDimension::operator=(const SedRemainingDimension& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mTarget = rhs.mTarget;
    mDimensionTarget = rhs.mDimensionTarget;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedRemainingDimension object.
 */
SedRemainingDimension*
SedRemainingDimension::clone() const
{
  return new SedRemainingDimension(*this);
}


/*
 * Destructor for SedRemainingDimension.
 */
SedRemainingDimension::~SedRemainingDimension()
{
}


/*
 * Returns the value of the "target" attribute of this SedRemainingDimension.
 */
const std::string&
SedRemainingDimension::getTarget() const
{
  return mTarget;
}


/*
 * Returns the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension.
 */
const std::string&
SedRemainingDimension::getDimensionTarget() const
{
  return mDimensionTarget;
}


/*
 * Predicate returning @c true if this SedRemainingDimension's "target"
 * attribute is set.
 */
bool
SedRemainingDimension::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Predicate returning @c true if this SedRemainingDimension's
 * "dimensionTarget" attribute is set.
 */
bool
SedRemainingDimension::isSetDimensionTarget() const
{
  return (mDimensionTarget.empty() == false);
}


/*
 * Sets the value of the "target" attribute of this SedRemainingDimension.
 */
int
SedRemainingDimension::setTarget(const std::string& target)
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
 * Sets the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::setDimensionTarget(const std::string& dimensionTarget)
{
  if (!(SyntaxChecker::isValidInternalSId(dimensionTarget)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mDimensionTarget = dimensionTarget;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "target" attribute of this SedRemainingDimension.
 */
int
SedRemainingDimension::unsetTarget()
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
 * Unsets the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::unsetDimensionTarget()
{
  mDimensionTarget.erase();

  if (mDimensionTarget.empty() == true)
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
SedRemainingDimension::renameSIdRefs(const std::string& oldid,
                                     const std::string& newid)
{
  if (isSetTarget() && mTarget == oldid)
  {
    setTarget(newid);
  }

  if (isSetDimensionTarget() && mDimensionTarget == oldid)
  {
    setDimensionTarget(newid);
  }
}


/*
 * Returns the XML element name of this SedRemainingDimension object.
 */
const std::string&
SedRemainingDimension::getElementName() const
{
  static const string name = "remainingDimension";
  return name;
}


/*
 * Returns the libSEDML type code for this SedRemainingDimension object.
 */
int
SedRemainingDimension::getTypeCode() const
{
  return SEDML_REMAININGDIMENSION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedRemainingDimension object have been set.
 */
bool
SedRemainingDimension::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedRemainingDimension::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
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
SedRemainingDimension::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedRemainingDimension::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::getAttribute(const std::string& attributeName,
                                    bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::getAttribute(const std::string& attributeName,
                                    int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::getAttribute(const std::string& attributeName,
                                    double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::getAttribute(const std::string& attributeName,
                                    unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::getAttribute(const std::string& attributeName,
                                    std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "dimensionTarget")
  {
    value = getDimensionTarget();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedRemainingDimension's attribute
 * "attributeName" is set.
 */
bool
SedRemainingDimension::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "target")
  {
    value = isSetTarget();
  }
  else if (attributeName == "dimensionTarget")
  {
    value = isSetDimensionTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::setAttribute(const std::string& attributeName,
                                    bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::setAttribute(const std::string& attributeName,
                                    int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::setAttribute(const std::string& attributeName,
                                    double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::setAttribute(const std::string& attributeName,
                                    unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::setAttribute(const std::string& attributeName,
                                    const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "target")
  {
    return_value = setTarget(value);
  }
  else if (attributeName == "dimensionTarget")
  {
    return_value = setDimensionTarget(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedRemainingDimension.
 */
int
SedRemainingDimension::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "target")
  {
    value = unsetTarget();
  }
  else if (attributeName == "dimensionTarget")
  {
    value = unsetDimensionTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedRemainingDimension::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("target");

  attributes.add("dimensionTarget");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedRemainingDimension::readAttributes(
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
    static_cast<SedListOfRemainingDimensions*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlVariableLORemainingDimensionsAllowedCoreAttributes,
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
        log->logError(SedmlRemainingDimensionAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // target SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<SedRemainingDimension>");
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
      logError(SedmlRemainingDimensionTargetMustBeSId, level, version, msg,
        getLine(), getColumn());
    }
  }

  // 
  // dimensionTarget SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("dimensionTarget", mDimensionTarget);

  if (assigned == true)
  {
    if (mDimensionTarget.empty() == true)
    {
      logEmptyString(mDimensionTarget, level, version,
        "<SedRemainingDimension>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mDimensionTarget) == false)
    {
      std::string msg = "The dimensionTarget attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mDimensionTarget + "', which does not conform to the "
        "syntax.";
      logError(SedmlRemainingDimensionDimensionTargetMustBeSId, level, version,
        msg, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedRemainingDimension::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }

  if (isSetDimensionTarget() == true)
  {
    stream.writeAttribute("dimensionTarget", getPrefix(), mDimensionTarget);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedRemainingDimension_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t *
SedRemainingDimension_create(unsigned int level, unsigned int version)
{
  return new SedRemainingDimension(level, version);
}


/*
 * Creates and returns a deep copy of this SedRemainingDimension_t object.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedRemainingDimension_clone(const SedRemainingDimension_t* srd)
{
  if (srd != NULL)
  {
    return static_cast<SedRemainingDimension_t*>(srd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedRemainingDimension_t object.
 */
LIBSEDML_EXTERN
void
SedRemainingDimension_free(SedRemainingDimension_t* srd)
{
  if (srd != NULL)
  {
    delete srd;
  }
}


/*
 * Returns the value of the "target" attribute of this SedRemainingDimension_t.
 */
LIBSEDML_EXTERN
char *
SedRemainingDimension_getTarget(const SedRemainingDimension_t * srd)
{
  if (srd == NULL)
  {
    return NULL;
  }

  return srd->getTarget().empty() ? NULL :
    safe_strdup(srd->getTarget().c_str());
}


/*
 * Returns the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension_t.
 */
LIBSEDML_EXTERN
char *
SedRemainingDimension_getDimensionTarget(const SedRemainingDimension_t * srd)
{
  if (srd == NULL)
  {
    return NULL;
  }

  return srd->getDimensionTarget().empty() ? NULL :
    safe_strdup(srd->getDimensionTarget().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedRemainingDimension_t's "target"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_isSetTarget(const SedRemainingDimension_t * srd)
{
  return (srd != NULL) ? static_cast<int>(srd->isSetTarget()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedRemainingDimension_t's
 * "dimensionTarget" attribute is set.
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_isSetDimensionTarget(const SedRemainingDimension_t * srd)
{
  return (srd != NULL) ? static_cast<int>(srd->isSetDimensionTarget()) : 0;
}


/*
 * Sets the value of the "target" attribute of this SedRemainingDimension_t.
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_setTarget(SedRemainingDimension_t * srd,
                                const char * target)
{
  return (srd != NULL) ? srd->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension_t.
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_setDimensionTarget(SedRemainingDimension_t * srd,
                                         const char * dimensionTarget)
{
  return (srd != NULL) ? srd->setDimensionTarget(dimensionTarget) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SedRemainingDimension_t.
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_unsetTarget(SedRemainingDimension_t * srd)
{
  return (srd != NULL) ? srd->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension_t.
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_unsetDimensionTarget(SedRemainingDimension_t * srd)
{
  return (srd != NULL) ? srd->unsetDimensionTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedRemainingDimension_t object have been set.
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_hasRequiredAttributes(const SedRemainingDimension_t *
  srd)
{
  return (srd != NULL) ? static_cast<int>(srd->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


