/**
 * @file SedAppliedDimension.cpp
 * @brief Implementation of the SedAppliedDimension class.
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
#include <sedml/SedAppliedDimension.h>
#include <sedml/SedListOfAppliedDimensions.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAppliedDimension using the given SED-ML Level and @ p
 * version values.
 */
SedAppliedDimension::SedAppliedDimension(unsigned int level,
                                             unsigned int version)
  : SedBase(level, version)
  , mTarget ("")
  , mDimensionTarget ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedAppliedDimension using the given SedNamespaces object @p
 * sedmlns.
 */
SedAppliedDimension::SedAppliedDimension(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mTarget ("")
  , mDimensionTarget ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedAppliedDimension.
 */
SedAppliedDimension::SedAppliedDimension(const SedAppliedDimension& orig)
  : SedBase( orig )
  , mTarget ( orig.mTarget )
  , mDimensionTarget ( orig.mDimensionTarget )
{
}


/*
 * Assignment operator for SedAppliedDimension.
 */
SedAppliedDimension&
SedAppliedDimension::operator=(const SedAppliedDimension& rhs)
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
 * Creates and returns a deep copy of this SedAppliedDimension object.
 */
SedAppliedDimension*
SedAppliedDimension::clone() const
{
  return new SedAppliedDimension(*this);
}


/*
 * Destructor for SedAppliedDimension.
 */
SedAppliedDimension::~SedAppliedDimension()
{
}


/*
 * Returns the value of the "target" attribute of this SedAppliedDimension.
 */
const std::string&
SedAppliedDimension::getTarget() const
{
  return mTarget;
}


/*
 * Returns the value of the "dimensionTarget" attribute of this
 * SedAppliedDimension.
 */
const std::string&
SedAppliedDimension::getDimensionTarget() const
{
  return mDimensionTarget;
}


/*
 * Predicate returning @c true if this SedAppliedDimension's "target"
 * attribute is set.
 */
bool
SedAppliedDimension::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Predicate returning @c true if this SedAppliedDimension's
 * "dimensionTarget" attribute is set.
 */
bool
SedAppliedDimension::isSetDimensionTarget() const
{
  return (mDimensionTarget.empty() == false);
}


/*
 * Sets the value of the "target" attribute of this SedAppliedDimension.
 */
int
SedAppliedDimension::setTarget(const std::string& target)
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
 * SedAppliedDimension.
 */
int
SedAppliedDimension::setDimensionTarget(const std::string& dimensionTarget)
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
 * Unsets the value of the "target" attribute of this SedAppliedDimension.
 */
int
SedAppliedDimension::unsetTarget()
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
 * SedAppliedDimension.
 */
int
SedAppliedDimension::unsetDimensionTarget()
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
SedAppliedDimension::renameSIdRefs(const std::string& oldid,
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
 * Returns the XML element name of this SedAppliedDimension object.
 */
const std::string&
SedAppliedDimension::getElementName() const
{
  static const string name = "appliedDimension";
  return name;
}


/*
 * Returns the libSEDML type code for this SedAppliedDimension object.
 */
int
SedAppliedDimension::getTypeCode() const
{
  return SEDML_APPLIEDDIMENSION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAppliedDimension object have been set.
 */
bool
SedAppliedDimension::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedAppliedDimension::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
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
SedAppliedDimension::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAppliedDimension::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::getAttribute(const std::string& attributeName,
                                    bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::getAttribute(const std::string& attributeName,
                                    int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::getAttribute(const std::string& attributeName,
                                    double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::getAttribute(const std::string& attributeName,
                                    unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::getAttribute(const std::string& attributeName,
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
 * Predicate returning @c true if this SedAppliedDimension's attribute
 * "attributeName" is set.
 */
bool
SedAppliedDimension::isSetAttribute(const std::string& attributeName) const
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
 * SedAppliedDimension.
 */
int
SedAppliedDimension::setAttribute(const std::string& attributeName,
                                    bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::setAttribute(const std::string& attributeName,
                                    int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::setAttribute(const std::string& attributeName,
                                    double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::setAttribute(const std::string& attributeName,
                                    unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAppliedDimension.
 */
int
SedAppliedDimension::setAttribute(const std::string& attributeName,
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
 * SedAppliedDimension.
 */
int
SedAppliedDimension::unsetAttribute(const std::string& attributeName)
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
SedAppliedDimension::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
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
SedAppliedDimension::readAttributes(
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
    static_cast<SedListOfAppliedDimensions*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlVariableLOAppliedDimensionsAllowedCoreAttributes,
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
        log->logError(SedmlAppliedDimensionAllowedAttributes, level, version,
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
      logEmptyString(mTarget, level, version, "<SedAppliedDimension>");
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
      logError(SedmlAppliedDimensionTargetMustBeSId, level, version, msg,
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
        "<SedAppliedDimension>");
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
      logError(SedmlAppliedDimensionDimensionTargetMustBeSId, level, version,
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
SedAppliedDimension::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
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
 * Creates a new SedAppliedDimension_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t *
SedAppliedDimension_create(unsigned int level, unsigned int version)
{
  return new SedAppliedDimension(level, version);
}


/*
 * Creates and returns a deep copy of this SedAppliedDimension_t object.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedAppliedDimension_clone(const SedAppliedDimension_t* srd)
{
  if (srd != NULL)
  {
    return static_cast<SedAppliedDimension_t*>(srd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAppliedDimension_t object.
 */
LIBSEDML_EXTERN
void
SedAppliedDimension_free(SedAppliedDimension_t* srd)
{
  if (srd != NULL)
  {
    delete srd;
  }
}


/*
 * Returns the value of the "target" attribute of this SedAppliedDimension_t.
 */
LIBSEDML_EXTERN
char *
SedAppliedDimension_getTarget(const SedAppliedDimension_t * srd)
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
 * SedAppliedDimension_t.
 */
LIBSEDML_EXTERN
char *
SedAppliedDimension_getDimensionTarget(const SedAppliedDimension_t * srd)
{
  if (srd == NULL)
  {
    return NULL;
  }

  return srd->getDimensionTarget().empty() ? NULL :
    safe_strdup(srd->getDimensionTarget().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedAppliedDimension_t's "target"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_isSetTarget(const SedAppliedDimension_t * srd)
{
  return (srd != NULL) ? static_cast<int>(srd->isSetTarget()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAppliedDimension_t's
 * "dimensionTarget" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_isSetDimensionTarget(const SedAppliedDimension_t * srd)
{
  return (srd != NULL) ? static_cast<int>(srd->isSetDimensionTarget()) : 0;
}


/*
 * Sets the value of the "target" attribute of this SedAppliedDimension_t.
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_setTarget(SedAppliedDimension_t * srd,
                                const char * target)
{
  return (srd != NULL) ? srd->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "dimensionTarget" attribute of this
 * SedAppliedDimension_t.
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_setDimensionTarget(SedAppliedDimension_t * srd,
                                         const char * dimensionTarget)
{
  return (srd != NULL) ? srd->setDimensionTarget(dimensionTarget) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SedAppliedDimension_t.
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_unsetTarget(SedAppliedDimension_t * srd)
{
  return (srd != NULL) ? srd->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "dimensionTarget" attribute of this
 * SedAppliedDimension_t.
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_unsetDimensionTarget(SedAppliedDimension_t * srd)
{
  return (srd != NULL) ? srd->unsetDimensionTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAppliedDimension_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_hasRequiredAttributes(const SedAppliedDimension_t *
  srd)
{
  return (srd != NULL) ? static_cast<int>(srd->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


