/**
 * @file SedDependentVariable.cpp
 * @brief Implementation of the SedDependentVariable class.
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
#include <sedml/SedDependentVariable.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedDependentVariable using the given SED-ML Level and @ p
 * version values.
 */
SedDependentVariable::SedDependentVariable(unsigned int level,
                                           unsigned int version)
  : SedVariable(level, version)
  , mTerm ("")
  , mTarget2 ("")
  , mSymbol2 ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedDependentVariable using the given SedNamespaces object @p
 * sedmlns.
 */
SedDependentVariable::SedDependentVariable(SedNamespaces *sedmlns)
  : SedVariable(sedmlns)
  , mTerm ("")
  , mTarget2 ("")
  , mSymbol2 ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedDependentVariable.
 */
SedDependentVariable::SedDependentVariable(const SedDependentVariable& orig)
  : SedVariable( orig )
  , mTerm ( orig.mTerm )
  , mTarget2 ( orig.mTarget2 )
  , mSymbol2 ( orig.mSymbol2 )
{
}


/*
 * Assignment operator for SedDependentVariable.
 */
SedDependentVariable&
SedDependentVariable::operator=(const SedDependentVariable& rhs)
{
  if (&rhs != this)
  {
    SedVariable::operator=(rhs);
    mTerm = rhs.mTerm;
    mTarget2 = rhs.mTarget2;
    mSymbol2 = rhs.mSymbol2;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedDependentVariable object.
 */
SedDependentVariable*
SedDependentVariable::clone() const
{
  return new SedDependentVariable(*this);
}


/*
 * Destructor for SedDependentVariable.
 */
SedDependentVariable::~SedDependentVariable()
{
}


/*
 * Returns the value of the "term" attribute of this SedDependentVariable.
 */
const std::string&
SedDependentVariable::getTerm() const
{
  return mTerm;
}


/*
 * Returns the value of the "target2" attribute of this SedDependentVariable.
 */
const std::string&
SedDependentVariable::getTarget2() const
{
  return mTarget2;
}


/*
 * Returns the value of the "symbol2" attribute of this SedDependentVariable.
 */
const std::string&
SedDependentVariable::getSymbol2() const
{
  return mSymbol2;
}


/*
 * Predicate returning @c true if this SedDependentVariable's "term" attribute
 * is set.
 */
bool
SedDependentVariable::isSetTerm() const
{
  return (mTerm.empty() == false);
}


/*
 * Predicate returning @c true if this SedDependentVariable's "target2"
 * attribute is set.
 */
bool
SedDependentVariable::isSetTarget2() const
{
  return (mTarget2.empty() == false);
}


/*
 * Predicate returning @c true if this SedDependentVariable's "symbol2"
 * attribute is set.
 */
bool
SedDependentVariable::isSetSymbol2() const
{
  return (mSymbol2.empty() == false);
}


/*
 * Sets the value of the "term" attribute of this SedDependentVariable.
 */
int
SedDependentVariable::setTerm(const std::string& term)
{
  mTerm = term;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "target2" attribute of this SedDependentVariable.
 */
int
SedDependentVariable::setTarget2(const std::string& target2)
{
  mTarget2 = target2;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "symbol2" attribute of this SedDependentVariable.
 */
int
SedDependentVariable::setSymbol2(const std::string& symbol2)
{
  mSymbol2 = symbol2;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "term" attribute of this SedDependentVariable.
 */
int
SedDependentVariable::unsetTerm()
{
  mTerm.erase();

  if (mTerm.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "target2" attribute of this SedDependentVariable.
 */
int
SedDependentVariable::unsetTarget2()
{
  mTarget2.erase();

  if (mTarget2.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "symbol2" attribute of this SedDependentVariable.
 */
int
SedDependentVariable::unsetSymbol2()
{
  mSymbol2.erase();

  if (mSymbol2.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedDependentVariable object.
 */
const std::string&
SedDependentVariable::getElementName() const
{
  static const string name = "dependentVariable";
  return name;
}


/*
 * Returns the libSEDML type code for this SedDependentVariable object.
 */
int
SedDependentVariable::getTypeCode() const
{
  return SEDML_DEPENDENTVARIABLE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedDependentVariable object have been set.
 */
bool
SedDependentVariable::hasRequiredAttributes() const
{
  bool allPresent = SedVariable::hasRequiredAttributes();

  if (isSetTerm() == false)
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
SedDependentVariable::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedVariable::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedDependentVariable::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedDependentVariable::setSedDocument(SedDocument* d)
{
  SedVariable::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::getAttribute(const std::string& attributeName,
                                   bool& value) const
{
  int return_value = SedVariable::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::getAttribute(const std::string& attributeName,
                                   int& value) const
{
  int return_value = SedVariable::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::getAttribute(const std::string& attributeName,
                                   double& value) const
{
  int return_value = SedVariable::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::getAttribute(const std::string& attributeName,
                                   unsigned int& value) const
{
  int return_value = SedVariable::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::getAttribute(const std::string& attributeName,
                                   std::string& value) const
{
  int return_value = SedVariable::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "term")
  {
    value = getTerm();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "target2")
  {
    value = getTarget2();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "symbol2")
  {
    value = getSymbol2();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedDependentVariable's attribute
 * "attributeName" is set.
 */
bool
SedDependentVariable::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedVariable::isSetAttribute(attributeName);

  if (attributeName == "term")
  {
    value = isSetTerm();
  }
  else if (attributeName == "target2")
  {
    value = isSetTarget2();
  }
  else if (attributeName == "symbol2")
  {
    value = isSetSymbol2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::setAttribute(const std::string& attributeName,
                                   bool value)
{
  int return_value = SedVariable::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::setAttribute(const std::string& attributeName,
                                   int value)
{
  int return_value = SedVariable::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::setAttribute(const std::string& attributeName,
                                   double value)
{
  int return_value = SedVariable::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::setAttribute(const std::string& attributeName,
                                   unsigned int value)
{
  int return_value = SedVariable::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::setAttribute(const std::string& attributeName,
                                   const std::string& value)
{
  int return_value = SedVariable::setAttribute(attributeName, value);

  if (attributeName == "term")
  {
    return_value = setTerm(value);
  }
  else if (attributeName == "target2")
  {
    return_value = setTarget2(value);
  }
  else if (attributeName == "symbol2")
  {
    return_value = setSymbol2(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedDependentVariable.
 */
int
SedDependentVariable::unsetAttribute(const std::string& attributeName)
{
  int value = SedVariable::unsetAttribute(attributeName);

  if (attributeName == "term")
  {
    value = unsetTerm();
  }
  else if (attributeName == "target2")
  {
    value = unsetTarget2();
  }
  else if (attributeName == "symbol2")
  {
    value = unsetSymbol2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedDependentVariable::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = SedVariable::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedDependentVariable::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedVariable::addExpectedAttributes(attributes);

  attributes.add("term");

  attributes.add("target2");

  attributes.add("symbol2");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedDependentVariable::readAttributes(
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

  SedVariable::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDependentVariableAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // term string (use = "required" )
  // 

  assigned = attributes.readInto("term", mTerm);

  if (assigned == true)
  {
    if (mTerm.empty() == true)
    {
      logEmptyString(mTerm, level, version, "<SedDependentVariable>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'term' is missing from the "
        "<SedDependentVariable> element.";
      log->logError(SedmlDependentVariableAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // target2 string (use = "optional" )
  // 

  assigned = attributes.readInto("target2", mTarget2);

  if (assigned == true)
  {
    if (mTarget2.empty() == true)
    {
      logEmptyString(mTarget2, level, version, "<SedDependentVariable>");
    }
  }

  // 
  // symbol2 string (use = "optional" )
  // 

  assigned = attributes.readInto("symbol2", mSymbol2);

  if (assigned == true)
  {
    if (mSymbol2.empty() == true)
    {
      logEmptyString(mSymbol2, level, version, "<SedDependentVariable>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedDependentVariable::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedVariable::writeAttributes(stream);

  if (isSetTerm() == true)
  {
    stream.writeAttribute("term", getPrefix(), mTerm);
  }

  if (isSetTarget2() == true)
  {
    stream.writeAttribute("target2", getPrefix(), mTarget2);
  }

  if (isSetSymbol2() == true)
  {
    stream.writeAttribute("symbol2", getPrefix(), mSymbol2);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDependentVariable_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedDependentVariable_t *
SedDependentVariable_create(unsigned int level, unsigned int version)
{
  return new SedDependentVariable(level, version);
}


/*
 * Creates and returns a deep copy of this SedDependentVariable_t object.
 */
LIBSEDML_EXTERN
SedDependentVariable_t*
SedDependentVariable_clone(const SedDependentVariable_t* sdv)
{
  if (sdv != NULL)
  {
    return static_cast<SedDependentVariable_t*>(sdv->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedDependentVariable_t object.
 */
LIBSEDML_EXTERN
void
SedDependentVariable_free(SedDependentVariable_t* sdv)
{
  if (sdv != NULL)
  {
    delete sdv;
  }
}


/*
 * Returns the value of the "term" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
char *
SedDependentVariable_getTerm(const SedDependentVariable_t * sdv)
{
  if (sdv == NULL)
  {
    return NULL;
  }

  return sdv->getTerm().empty() ? NULL : safe_strdup(sdv->getTerm().c_str());
}


/*
 * Returns the value of the "target2" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
char *
SedDependentVariable_getTarget2(const SedDependentVariable_t * sdv)
{
  if (sdv == NULL)
  {
    return NULL;
  }

  return sdv->getTarget2().empty() ? NULL :
    safe_strdup(sdv->getTarget2().c_str());
}


/*
 * Returns the value of the "symbol2" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
char *
SedDependentVariable_getSymbol2(const SedDependentVariable_t * sdv)
{
  if (sdv == NULL)
  {
    return NULL;
  }

  return sdv->getSymbol2().empty() ? NULL :
    safe_strdup(sdv->getSymbol2().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedDependentVariable_t's "term"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_isSetTerm(const SedDependentVariable_t * sdv)
{
  return (sdv != NULL) ? static_cast<int>(sdv->isSetTerm()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDependentVariable_t's "target2"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_isSetTarget2(const SedDependentVariable_t * sdv)
{
  return (sdv != NULL) ? static_cast<int>(sdv->isSetTarget2()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDependentVariable_t's "symbol2"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_isSetSymbol2(const SedDependentVariable_t * sdv)
{
  return (sdv != NULL) ? static_cast<int>(sdv->isSetSymbol2()) : 0;
}


/*
 * Sets the value of the "term" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_setTerm(SedDependentVariable_t * sdv, const char * term)
{
  return (sdv != NULL) ? sdv->setTerm(term) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "target2" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_setTarget2(SedDependentVariable_t * sdv,
                                const char * target2)
{
  return (sdv != NULL) ? sdv->setTarget2(target2) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "symbol2" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_setSymbol2(SedDependentVariable_t * sdv,
                                const char * symbol2)
{
  return (sdv != NULL) ? sdv->setSymbol2(symbol2) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "term" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_unsetTerm(SedDependentVariable_t * sdv)
{
  return (sdv != NULL) ? sdv->unsetTerm() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target2" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_unsetTarget2(SedDependentVariable_t * sdv)
{
  return (sdv != NULL) ? sdv->unsetTarget2() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "symbol2" attribute of this SedDependentVariable_t.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_unsetSymbol2(SedDependentVariable_t * sdv)
{
  return (sdv != NULL) ? sdv->unsetSymbol2() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDependentVariable_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDependentVariable_hasRequiredAttributes(const SedDependentVariable_t * sdv)
{
  return (sdv != NULL) ? static_cast<int>(sdv->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


