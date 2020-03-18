/**
 * @file SedSetValue.cpp
 * @brief Implementation of the SedSetValue class.
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
#include <sedml/SedSetValue.h>
#include <sedml/SedListOfSetValues.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSetValue using the given SEDML Level and @ p version
 * values.
 */
SedSetValue::SedSetValue(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mModelReference ("")
  , mSymbol ("")
  , mTarget ("")
  , mRange ("")
  , mMath (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedSetValue using the given SedNamespaces object @p sedmlns.
 */
SedSetValue::SedSetValue(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mModelReference ("")
  , mSymbol ("")
  , mTarget ("")
  , mRange ("")
  , mMath (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedSetValue.
 */
SedSetValue::SedSetValue(const SedSetValue& orig)
  : SedBase( orig )
  , mModelReference ( orig.mModelReference )
  , mSymbol ( orig.mSymbol )
  , mTarget ( orig.mTarget )
  , mRange ( orig.mRange )
  , mMath ( NULL )
{
  if (orig.mMath != NULL)
  {
    mMath = orig.mMath->deepCopy();
  }

  connectToChild();
}


/*
 * Assignment operator for SedSetValue.
 */
SedSetValue&
SedSetValue::operator=(const SedSetValue& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mModelReference = rhs.mModelReference;
    mSymbol = rhs.mSymbol;
    mTarget = rhs.mTarget;
    mRange = rhs.mRange;
    delete mMath;
    if (rhs.mMath != NULL)
    {
      mMath = rhs.mMath->deepCopy();
    }
    else
    {
      mMath = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSetValue object.
 */
SedSetValue*
SedSetValue::clone() const
{
  return new SedSetValue(*this);
}


/*
 * Destructor for SedSetValue.
 */
SedSetValue::~SedSetValue()
{
  delete mMath;
  mMath = NULL;
}


/*
 * Returns the value of the "modelReference" attribute of this SedSetValue.
 */
const std::string&
SedSetValue::getModelReference() const
{
  return mModelReference;
}


/*
 * Returns the value of the "symbol" attribute of this SedSetValue.
 */
const std::string&
SedSetValue::getSymbol() const
{
  return mSymbol;
}


/*
 * Returns the value of the "target" attribute of this SedSetValue.
 */
const std::string&
SedSetValue::getTarget() const
{
  return mTarget;
}


/*
 * Returns the value of the "range" attribute of this SedSetValue.
 */
const std::string&
SedSetValue::getRange() const
{
  return mRange;
}


/*
 * Predicate returning @c true if this SedSetValue's "modelReference" attribute
 * is set.
 */
bool
SedSetValue::isSetModelReference() const
{
  return (mModelReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedSetValue's "symbol" attribute is set.
 */
bool
SedSetValue::isSetSymbol() const
{
  return (mSymbol.empty() == false);
}


/*
 * Predicate returning @c true if this SedSetValue's "target" attribute is set.
 */
bool
SedSetValue::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Predicate returning @c true if this SedSetValue's "range" attribute is set.
 */
bool
SedSetValue::isSetRange() const
{
  return (mRange.empty() == false);
}


/*
 * Sets the value of the "modelReference" attribute of this SedSetValue.
 */
int
SedSetValue::setModelReference(const std::string& modelReference)
{
  if (!(SyntaxChecker::isValidInternalSId(modelReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mModelReference = modelReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "symbol" attribute of this SedSetValue.
 */
int
SedSetValue::setSymbol(const std::string& symbol)
{
  mSymbol = symbol;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "target" attribute of this SedSetValue.
 */
int
SedSetValue::setTarget(const std::string& target)
{
  mTarget = target;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "range" attribute of this SedSetValue.
 */
int
SedSetValue::setRange(const std::string& range)
{
  if (!(SyntaxChecker::isValidInternalSId(range)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mRange = range;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "modelReference" attribute of this SedSetValue.
 */
int
SedSetValue::unsetModelReference()
{
  mModelReference.erase();

  if (mModelReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "symbol" attribute of this SedSetValue.
 */
int
SedSetValue::unsetSymbol()
{
  mSymbol.erase();

  if (mSymbol.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "target" attribute of this SedSetValue.
 */
int
SedSetValue::unsetTarget()
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
 * Unsets the value of the "range" attribute of this SedSetValue.
 */
int
SedSetValue::unsetRange()
{
  mRange.erase();

  if (mRange.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "math" element of this SedSetValue.
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
SedSetValue::getMath() const
{
  return mMath;
}


/*
 * Returns the value of the "math" element of this SedSetValue.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
SedSetValue::getMath()
{
  return mMath;
}


/*
 * Predicate returning @c true if this SedSetValue's "math" element is set.
 */
bool
SedSetValue::isSetMath() const
{
  return (mMath != NULL);
}


/*
 * Sets the value of the "math" element of this SedSetValue.
 */
int
SedSetValue::setMath(const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* math)
{
  if (mMath == math)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (math == NULL)
  {
    delete mMath;
    mMath = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (!(math->isWellFormedASTNode()))
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else
  {
    delete mMath;
    mMath = (math != NULL) ? math->deepCopy() : NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "math" element of this SedSetValue.
 */
int
SedSetValue::unsetMath()
{
  delete mMath;
  mMath = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedSetValue::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetModelReference() && mModelReference == oldid)
  {
    setModelReference(newid);
  }

  if (isSetRange() && mRange == oldid)
  {
    setRange(newid);
  }

  if (isSetMath())
  {
    mMath->renameSIdRefs(oldid, newid);
  }
}


/*
 * Returns the XML element name of this SedSetValue object.
 */
const std::string&
SedSetValue::getElementName() const
{
  static const string name = "setValue";
  return name;
}


/*
 * Returns the libSEDML type code for this SedSetValue object.
 */
int
SedSetValue::getTypeCode() const
{
  return SEDML_TASK_SETVALUE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedSetValue object have been set.
 */
bool
SedSetValue::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetModelReference() == false)
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
SedSetValue::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (isSetMath() == true)
  {
    writeMathML(getMath(), stream, NULL);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedSetValue::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSetValue::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedSetValue::connectToChild()
{
  SedBase::connectToChild();
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "modelReference")
  {
    value = getModelReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "symbol")
  {
    value = getSymbol();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "range")
  {
    value = getRange();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedSetValue's attribute "attributeName"
 * is set.
 */
bool
SedSetValue::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "modelReference")
  {
    value = isSetModelReference();
  }
  else if (attributeName == "symbol")
  {
    value = isSetSymbol();
  }
  else if (attributeName == "target")
  {
    value = isSetTarget();
  }
  else if (attributeName == "range")
  {
    value = isSetRange();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "modelReference")
  {
    return_value = setModelReference(value);
  }
  else if (attributeName == "symbol")
  {
    return_value = setSymbol(value);
  }
  else if (attributeName == "target")
  {
    return_value = setTarget(value);
  }
  else if (attributeName == "range")
  {
    return_value = setRange(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedSetValue.
 */
int
SedSetValue::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "modelReference")
  {
    value = unsetModelReference();
  }
  else if (attributeName == "symbol")
  {
    value = unsetSymbol();
  }
  else if (attributeName == "target")
  {
    value = unsetTarget();
  }
  else if (attributeName == "range")
  {
    value = unsetRange();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSetValue::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("modelReference");

  attributes.add("symbol");

  attributes.add("target");

  attributes.add("range");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSetValue::readAttributes(
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
    static_cast<SedListOfSetValues*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlRepeatedTaskLOSetValuesAllowedCoreAttributes, level,
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
        log->logError(SedmlSetValueAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // modelReference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("modelReference", mModelReference);

  if (assigned == true)
  {
    if (mModelReference.empty() == true)
    {
      logEmptyString(mModelReference, level, version, "<SedSetValue>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
    {
      std::string msg = "The modelReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mModelReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlSetValueModelReferenceMustBeModel, level, version, msg,
        getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'modelReference' is missing from "
        "the <SedSetValue> element.";
      log->logError(SedmlSetValueAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // symbol string (use = "optional" )
  // 

  assigned = attributes.readInto("symbol", mSymbol);

  if (assigned == true)
  {
    if (mSymbol.empty() == true)
    {
      logEmptyString(mSymbol, level, version, "<SedSetValue>");
    }
  }

  // 
  // target string (use = "optional" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<SedSetValue>");
    }
  }

  // 
  // range SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("range", mRange);

  if (assigned == true)
  {
    if (mRange.empty() == true)
    {
      logEmptyString(mRange, level, version, "<SedSetValue>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRange) == false)
    {
      std::string msg = "The range attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mRange + "', which does not conform to the syntax.";
      logError(SedmlSetValueRangeMustBeRange, level, version, msg, getLine(),
        getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
SedSetValue::readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  bool read = false;
  const string& name = stream.peek().getName();

  if (name == "math")
  {
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken elem = stream.peek();
    const std::string prefix = checkMathMLNamespace(elem);
    delete mMath;
    mMath = readMathML(stream, prefix);
    read = true;
  }

  if (SedBase::readOtherXML(stream))
  {
    read = true;
  }

  return read;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedSetValue::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetModelReference() == true)
  {
    stream.writeAttribute("modelReference", getPrefix(), mModelReference);
  }

  if (isSetSymbol() == true)
  {
    stream.writeAttribute("symbol", getPrefix(), mSymbol);
  }

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }

  if (isSetRange() == true)
  {
    stream.writeAttribute("range", getPrefix(), mRange);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSetValue_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedSetValue_t *
SedSetValue_create(unsigned int level, unsigned int version)
{
  return new SedSetValue(level, version);
}


/*
 * Creates and returns a deep copy of this SedSetValue_t object.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedSetValue_clone(const SedSetValue_t* ssv)
{
  if (ssv != NULL)
  {
    return static_cast<SedSetValue_t*>(ssv->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSetValue_t object.
 */
LIBSEDML_EXTERN
void
SedSetValue_free(SedSetValue_t* ssv)
{
  if (ssv != NULL)
  {
    delete ssv;
  }
}


/*
 * Returns the value of the "modelReference" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
char *
SedSetValue_getModelReference(const SedSetValue_t * ssv)
{
  if (ssv == NULL)
  {
    return NULL;
  }

  return ssv->getModelReference().empty() ? NULL :
    safe_strdup(ssv->getModelReference().c_str());
}


/*
 * Returns the value of the "symbol" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
char *
SedSetValue_getSymbol(const SedSetValue_t * ssv)
{
  if (ssv == NULL)
  {
    return NULL;
  }

  return ssv->getSymbol().empty() ? NULL :
    safe_strdup(ssv->getSymbol().c_str());
}


/*
 * Returns the value of the "target" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
char *
SedSetValue_getTarget(const SedSetValue_t * ssv)
{
  if (ssv == NULL)
  {
    return NULL;
  }

  return ssv->getTarget().empty() ? NULL :
    safe_strdup(ssv->getTarget().c_str());
}


/*
 * Returns the value of the "range" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
char *
SedSetValue_getRange(const SedSetValue_t * ssv)
{
  if (ssv == NULL)
  {
    return NULL;
  }

  return ssv->getRange().empty() ? NULL : safe_strdup(ssv->getRange().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedSetValue_t's "modelReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetModelReference(const SedSetValue_t * ssv)
{
  return (ssv != NULL) ? static_cast<int>(ssv->isSetModelReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSetValue_t's "symbol" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetSymbol(const SedSetValue_t * ssv)
{
  return (ssv != NULL) ? static_cast<int>(ssv->isSetSymbol()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSetValue_t's "target" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetTarget(const SedSetValue_t * ssv)
{
  return (ssv != NULL) ? static_cast<int>(ssv->isSetTarget()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSetValue_t's "range" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetRange(const SedSetValue_t * ssv)
{
  return (ssv != NULL) ? static_cast<int>(ssv->isSetRange()) : 0;
}


/*
 * Sets the value of the "modelReference" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_setModelReference(SedSetValue_t * ssv,
                              const char * modelReference)
{
  return (ssv != NULL) ? ssv->setModelReference(modelReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "symbol" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_setSymbol(SedSetValue_t * ssv, const char * symbol)
{
  return (ssv != NULL) ? ssv->setSymbol(symbol) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "target" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_setTarget(SedSetValue_t * ssv, const char * target)
{
  return (ssv != NULL) ? ssv->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "range" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_setRange(SedSetValue_t * ssv, const char * range)
{
  return (ssv != NULL) ? ssv->setRange(range) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "modelReference" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetModelReference(SedSetValue_t * ssv)
{
  return (ssv != NULL) ? ssv->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "symbol" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetSymbol(SedSetValue_t * ssv)
{
  return (ssv != NULL) ? ssv->unsetSymbol() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetTarget(SedSetValue_t * ssv)
{
  return (ssv != NULL) ? ssv->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "range" attribute of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetRange(SedSetValue_t * ssv)
{
  return (ssv != NULL) ? ssv->unsetRange() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "math" element of this SedSetValue_t.
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
SedSetValue_getMath(const SedSetValue_t * ssv)
{
  if (ssv == NULL)
  {
    return NULL;
  }

  return (LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*)(ssv->getMath());
}


/*
 * Predicate returning @c 1 (true) if this SedSetValue_t's "math" element is
 * set.
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetMath(const SedSetValue_t * ssv)
{
  return (ssv != NULL) ? static_cast<int>(ssv->isSetMath()) : 0;
}


/*
 * Sets the value of the "math" element of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_setMath(SedSetValue_t * ssv,
                    const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t* math)
{
  return (ssv != NULL) ? ssv->setMath(math) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "math" element of this SedSetValue_t.
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetMath(SedSetValue_t * ssv)
{
  return (ssv != NULL) ? ssv->unsetMath() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSetValue_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSetValue_hasRequiredAttributes(const SedSetValue_t * ssv)
{
  return (ssv != NULL) ? static_cast<int>(ssv->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


