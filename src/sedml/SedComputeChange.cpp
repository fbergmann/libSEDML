/**
 * @file SedComputeChange.cpp
 * @brief Implementation of the SedComputeChange class.
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
#include <sedml/SedComputeChange.h>
#include <sedml/SedVariable.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedComputeChange using the given SED-ML Level and @ p version
 * values.
 */
SedComputeChange::SedComputeChange(unsigned int level, unsigned int version)
  : SedChange(level, version)
  , mMath (NULL)
  , mVariables (level, version)
  , mParameters (level, version)
  , mSymbol ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedComputeChange using the given SedNamespaces object @p
 * sedmlns.
 */
SedComputeChange::SedComputeChange(SedNamespaces *sedmlns)
  : SedChange(sedmlns)
  , mMath (NULL)
  , mVariables (sedmlns)
  , mParameters (sedmlns)
  , mSymbol ("")
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedComputeChange.
 */
SedComputeChange::SedComputeChange(const SedComputeChange& orig)
  : SedChange( orig )
  , mMath ( NULL )
  , mVariables ( orig.mVariables )
  , mParameters ( orig.mParameters )
  , mSymbol (orig.mSymbol)
{
  if (orig.mMath != NULL)
  {
    mMath = orig.mMath->deepCopy();
  }

  connectToChild();
}


/*
 * Assignment operator for SedComputeChange.
 */
SedComputeChange&
SedComputeChange::operator=(const SedComputeChange& rhs)
{
  if (&rhs != this)
  {
    SedChange::operator=(rhs);
    mVariables = rhs.mVariables;
    mParameters = rhs.mParameters;
    mSymbol = rhs.mSymbol;
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
 * Creates and returns a deep copy of this SedComputeChange object.
 */
SedComputeChange*
SedComputeChange::clone() const
{
  return new SedComputeChange(*this);
}


/*
 * Destructor for SedComputeChange.
 */
SedComputeChange::~SedComputeChange()
{
  delete mMath;
  mMath = NULL;
}


/*
 * Returns the value of the "symbol" attribute of this SedComputeChange.
 */
const std::string&
SedComputeChange::getSymbol() const
{
    if (getLevel() > 1 || getVersion() >= 4) {
        return mSymbol;
    }
    static string empty = "";
    return empty;
}


/*
 * Predicate returning @c true if this SedComputeChange's "symbol" attribute is set.
 */
bool
SedComputeChange::isSetSymbol() const
{
    if (getLevel() > 1 || getVersion() >= 4) {
        return (mSymbol.empty() == false);
    }
    return false;
}


/*
 * Sets the value of the "symbol" attribute of this SedComputeChange.
 */
int
SedComputeChange::setSymbol(const std::string& symbol)
{
    if (getLevel() > 1 || getVersion() >= 4) {
        mSymbol = symbol;
        return LIBSEDML_OPERATION_SUCCESS;
    }
    return LIBSEDML_UNEXPECTED_ATTRIBUTE;
}


/*
 * Unsets the value of the "symbol" attribute of this SedComputeChange.
 */
int
SedComputeChange::unsetSymbol()
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
 * Returns the value of the "math" element of this SedComputeChange.
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
SedComputeChange::getMath() const
{
  return mMath;
}


/*
 * Returns the value of the "math" element of this SedComputeChange.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
SedComputeChange::getMath()
{
  return mMath;
}


/*
 * Predicate returning @c true if this SedComputeChange's "math" element is
 * set.
 */
bool
SedComputeChange::isSetMath() const
{
  return (mMath != NULL);
}


/*
 * Sets the value of the "math" element of this SedComputeChange.
 */
int
SedComputeChange::setMath(const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* math)
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
 * Unsets the value of the "math" element of this SedComputeChange.
 */
int
SedComputeChange::unsetMath()
{
  delete mMath;
  mMath = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfVariables from this SedComputeChange.
 */
const SedListOfVariables*
SedComputeChange::getListOfVariables() const
{
  return &mVariables;
}


/*
 * Returns the SedListOfVariables from this SedComputeChange.
 */
SedListOfVariables*
SedComputeChange::getListOfVariables()
{
  return &mVariables;
}


/*
 * Get a SedVariable from the SedComputeChange.
 */
SedVariable*
SedComputeChange::getVariable(unsigned int n)
{
  return mVariables.get(n);
}


/*
 * Get a SedVariable from the SedComputeChange.
 */
const SedVariable*
SedComputeChange::getVariable(unsigned int n) const
{
  return mVariables.get(n);
}


/*
 * Get a SedVariable from the SedComputeChange based on its identifier.
 */
SedVariable*
SedComputeChange::getVariable(const std::string& sid)
{
  return mVariables.get(sid);
}


/*
 * Get a SedVariable from the SedComputeChange based on its identifier.
 */
const SedVariable*
SedComputeChange::getVariable(const std::string& sid) const
{
  return mVariables.get(sid);
}


/*
 * Get a SedVariable from the SedComputeChange based on the TaskReference to
 * which it refers.
 */
const SedVariable*
SedComputeChange::getVariableByTaskReference(const std::string& sid) const
{
  return mVariables.getByTaskReference(sid);
}


/*
 * Get a SedVariable from the SedComputeChange based on the TaskReference to
 * which it refers.
 */
SedVariable*
SedComputeChange::getVariableByTaskReference(const std::string& sid)
{
  return mVariables.getByTaskReference(sid);
}


/*
 * Get a SedVariable from the SedComputeChange based on the ModelReference to
 * which it refers.
 */
const SedVariable*
SedComputeChange::getVariableByModelReference(const std::string& sid) const
{
  return mVariables.getByModelReference(sid);
}


/*
 * Get a SedVariable from the SedComputeChange based on the ModelReference to
 * which it refers.
 */
SedVariable*
SedComputeChange::getVariableByModelReference(const std::string& sid)
{
  return mVariables.getByModelReference(sid);
}


/*
 * Adds a copy of the given SedVariable to this SedComputeChange.
 */
int
SedComputeChange::addVariable(const SedVariable* sv)
{
  if (sv == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sv->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sv->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sv->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sv)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sv->isSetId() && (mVariables.get(sv->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mVariables.append(sv);
  }
}


/*
 * Get the number of SedVariable objects in this SedComputeChange.
 */
unsigned int
SedComputeChange::getNumVariables() const
{
  return mVariables.size();
}


/*
 * Creates a new SedVariable object, adds it to this SedComputeChange object
 * and returns the SedVariable object created.
 */
SedVariable*
SedComputeChange::createVariable()
{
  SedVariable* sv = NULL;

  try
  {
    sv = new SedVariable(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sv != NULL)
  {
    mVariables.appendAndOwn(sv);
  }

  return sv;
}



/*
 * Removes the nth SedVariable from this SedComputeChange and returns a pointer
 * to it.
 */
SedVariable*
SedComputeChange::removeVariable(unsigned int n)
{
  return mVariables.remove(n);
}


/*
 * Removes the SedVariable from this SedComputeChange based on its identifier
 * and returns a pointer to it.
 */
SedVariable*
SedComputeChange::removeVariable(const std::string& sid)
{
  return mVariables.remove(sid);
}


/*
 * Returns the SedListOfParameters from this SedComputeChange.
 */
const SedListOfParameters*
SedComputeChange::getListOfParameters() const
{
  return &mParameters;
}


/*
 * Returns the SedListOfParameters from this SedComputeChange.
 */
SedListOfParameters*
SedComputeChange::getListOfParameters()
{
  return &mParameters;
}


/*
 * Get a SedParameter from the SedComputeChange.
 */
SedParameter*
SedComputeChange::getParameter(unsigned int n)
{
  return mParameters.get(n);
}


/*
 * Get a SedParameter from the SedComputeChange.
 */
const SedParameter*
SedComputeChange::getParameter(unsigned int n) const
{
  return mParameters.get(n);
}


/*
 * Get a SedParameter from the SedComputeChange based on its identifier.
 */
SedParameter*
SedComputeChange::getParameter(const std::string& sid)
{
  return mParameters.get(sid);
}


/*
 * Get a SedParameter from the SedComputeChange based on its identifier.
 */
const SedParameter*
SedComputeChange::getParameter(const std::string& sid) const
{
  return mParameters.get(sid);
}


/*
 * Adds a copy of the given SedParameter to this SedComputeChange.
 */
int
SedComputeChange::addParameter(const SedParameter* sp)
{
  if (sp == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sp->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sp->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sp->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sp)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sp->isSetId() && (mParameters.get(sp->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mParameters.append(sp);
  }
}


/*
 * Get the number of SedParameter objects in this SedComputeChange.
 */
unsigned int
SedComputeChange::getNumParameters() const
{
  return mParameters.size();
}


/*
 * Creates a new SedParameter object, adds it to this SedComputeChange object
 * and returns the SedParameter object created.
 */
SedParameter*
SedComputeChange::createParameter()
{
  SedParameter* sp = NULL;

  try
  {
    sp = new SedParameter(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sp != NULL)
  {
    mParameters.appendAndOwn(sp);
  }

  return sp;
}


/*
 * Removes the nth SedParameter from this SedComputeChange and returns a
 * pointer to it.
 */
SedParameter*
SedComputeChange::removeParameter(unsigned int n)
{
  return mParameters.remove(n);
}


/*
 * Removes the SedParameter from this SedComputeChange based on its identifier
 * and returns a pointer to it.
 */
SedParameter*
SedComputeChange::removeParameter(const std::string& sid)
{
  return mParameters.remove(sid);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedComputeChange::renameSIdRefs(const std::string& oldid,
                                const std::string& newid)
{
  if (isSetMath())
  {
    mMath->renameSIdRefs(oldid, newid);
  }
}


/*
 * Returns the XML element name of this SedComputeChange object.
 */
const std::string&
SedComputeChange::getElementName() const
{
  static const string name = "computeChange";
  return name;
}


/*
 * Returns the libSEDML type code for this SedComputeChange object.
 */
int
SedComputeChange::getTypeCode() const
{
  return SEDML_CHANGE_COMPUTECHANGE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedComputeChange object have been set.
 */
bool
SedComputeChange::hasRequiredAttributes() const
{
  bool allPresent = SedChange::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedComputeChange object have been set.
 */
bool
SedComputeChange::hasRequiredElements() const
{
  bool allPresent = SedChange::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedComputeChange::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedChange::writeElements(stream);

  if (isSetMath() == true)
  {
    writeMathML(getMath(), stream, NULL);
  }

  if (getNumVariables() > 0)
  {
    mVariables.write(stream);
  }

  if (getNumParameters() > 0)
  {
    mParameters.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedComputeChange::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedComputeChange::setSedDocument(SedDocument* d)
{
  SedChange::setSedDocument(d);

  mVariables.setSedDocument(d);

  mParameters.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedComputeChange::connectToChild()
{
  SedChange::connectToChild();

  mVariables.connectToParent(this);

  mParameters.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::getAttribute(const std::string& attributeName,
                               bool& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::getAttribute(const std::string& attributeName,
                               int& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::getAttribute(const std::string& attributeName,
                               double& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::getAttribute(const std::string& attributeName,
                               unsigned int& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::getAttribute(const std::string& attributeName,
                               std::string& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
      return return_value;
  }

  if (attributeName == "symbol")
  {
      value = getSymbol();
      return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedComputeChange's attribute
 * "attributeName" is set.
 */
bool
SedComputeChange::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedChange::isSetAttribute(attributeName);

  if (attributeName == "symbol")
  {
      value = isSetSymbol();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::setAttribute(const std::string& attributeName,
                               unsigned int value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::setAttribute(const std::string& attributeName,
                               const std::string& value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  if (attributeName == "symbol")
  {
      return_value = setSymbol(value);
  }
  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedComputeChange.
 */
int
SedComputeChange::unsetAttribute(const std::string& attributeName)
{
  int value = SedChange::unsetAttribute(attributeName);

  if (attributeName == "symbol")
  {
      value = unsetSymbol();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedComputeChange.
 */
SedBase*
SedComputeChange::createChildObject(const std::string& elementName)
{
  SedChange* obj = NULL;

  if (elementName == "variable")
  {
    return createVariable();
  }
  
  if (elementName == "parameter")
  {
    return createParameter();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedComputeChange.
 */
int
SedComputeChange::addChildObject(const std::string& elementName,
                                 const SedBase* element)
{
  if (elementName == "variable" && element->getTypeCode() == SEDML_VARIABLE)
  {
    return addVariable((const SedVariable*)(element));
  }
  else if (elementName == "parameter" && element->getTypeCode() ==
    SEDML_PARAMETER)
  {
    return addParameter((const SedParameter*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedComputeChange.
 */
SedBase*
SedComputeChange::removeChildObject(const std::string& elementName,
                                    const std::string& id)
{
  if (elementName == "variable")
  {
    return removeVariable(id);
  }
  else if (elementName == "parameter")
  {
    return removeParameter(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedComputeChange.
 */
unsigned int
SedComputeChange::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "variable")
  {
    return getNumVariables();
  }
  else if (elementName == "parameter")
  {
    return getNumParameters();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedComputeChange.
 */
SedBase*
SedComputeChange::getObject(const std::string& elementName,
                            unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "variable")
  {
    return getVariable(index);
  }
  else if (elementName == "parameter")
  {
    return getParameter(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedComputeChange::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mVariables.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mParameters.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns a List of all child SedBase objects, including those nested to an
 * arbitrary depth.
 */
List*
SedComputeChange::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mVariables, filter);
  SED_ADD_FILTERED_LIST(ret, sublist, mParameters, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedComputeChange::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedChange::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "listOfVariables")
  {
    if (getErrorLog() && mVariables.size() != 0)
    {
      getErrorLog()->logError(SedmlComputeChangeAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mVariables;
  }
  else if (name == "listOfParameters")
  {
    if (getErrorLog() && mParameters.size() != 0)
    {
      getErrorLog()->logError(SedmlComputeChangeAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mParameters;
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
SedComputeChange::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedChange::addExpectedAttributes(attributes);

  attributes.add("symbol");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedComputeChange::readAttributes(
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

  SedChange::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlChangeAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
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
          logEmptyString(mSymbol, level, version, "<SedComputeChange>");
      }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
SedComputeChange::readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
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

  if (SedChange::readOtherXML(stream))
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
SedComputeChange::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedChange::writeAttributes(stream);

  if (isSetSymbol() == true)
  {
      stream.writeAttribute("symbol", getPrefix(), mSymbol);
  }

}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedComputeChange_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedComputeChange_t *
SedComputeChange_create(unsigned int level, unsigned int version)
{
  return new SedComputeChange(level, version);
}


/*
 * Creates and returns a deep copy of this SedComputeChange_t object.
 */
LIBSEDML_EXTERN
SedComputeChange_t*
SedComputeChange_clone(const SedComputeChange_t* scc)
{
  if (scc != NULL)
  {
    return static_cast<SedComputeChange_t*>(scc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedComputeChange_t object.
 */
LIBSEDML_EXTERN
void
SedComputeChange_free(SedComputeChange_t* scc)
{
  if (scc != NULL)
  {
    delete scc;
  }
}


/*
 * Returns the value of the "symbol" attribute of this SedComputeChange_t.
 */
LIBSEDML_EXTERN
char*
SedComputeChange_getSymbol(const SedComputeChange_t* sv)
{
    if (sv == NULL)
    {
        return NULL;
    }

    return sv->getSymbol().empty() ? NULL : safe_strdup(sv->getSymbol().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedComputeChange_t's "symbol" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedComputeChange_isSetSymbol(const SedComputeChange_t* sv)
{
    return (sv != NULL) ? static_cast<int>(sv->isSetSymbol()) : 0;
}


/*
 * Sets the value of the "symbol" attribute of this SedComputeChange_t.
 */
LIBSEDML_EXTERN
int
SedComputeChange_setSymbol(SedComputeChange_t* sv, const char* symbol)
{
    return (sv != NULL) ? sv->setSymbol(symbol) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "symbol" attribute of this SedComputeChange_t.
 */
LIBSEDML_EXTERN
int
SedComputeChange_unsetSymbol(SedComputeChange_t* sv)
{
    return (sv != NULL) ? sv->unsetSymbol() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "math" element of this SedComputeChange_t.
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
SedComputeChange_getMath(const SedComputeChange_t * scc)
{
  if (scc == NULL)
  {
    return NULL;
  }

  return (LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*)(scc->getMath());
}


/*
 * Predicate returning @c 1 (true) if this SedComputeChange_t's "math" element
 * is set.
 */
LIBSEDML_EXTERN
int
SedComputeChange_isSetMath(const SedComputeChange_t * scc)
{
  return (scc != NULL) ? static_cast<int>(scc->isSetMath()) : 0;
}


/*
 * Sets the value of the "math" element of this SedComputeChange_t.
 */
LIBSEDML_EXTERN
int
SedComputeChange_setMath(SedComputeChange_t * scc,
                         const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t* math)
{
  return (scc != NULL) ? scc->setMath(math) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "math" element of this SedComputeChange_t.
 */
LIBSEDML_EXTERN
int
SedComputeChange_unsetMath(SedComputeChange_t * scc)
{
  return (scc != NULL) ? scc->unsetMath() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedVariable_t objects from this
 * SedComputeChange_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedComputeChange_getListOfVariables(SedComputeChange_t* scc)
{
  return (scc != NULL) ? scc->getListOfVariables() : NULL;
}


/*
 * Get a SedVariable_t from the SedComputeChange_t.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_getVariable(SedComputeChange_t* scc, unsigned int n)
{
  return (scc != NULL) ? scc->getVariable(n) : NULL;
}


/*
 * Get a SedVariable_t from the SedComputeChange_t based on its identifier.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_getVariableById(SedComputeChange_t* scc, const char *sid)
{
  return (scc != NULL && sid != NULL) ? scc->getVariable(sid) : NULL;
}


/*
 * Get a SedVariable_t from the SedComputeChange_t based on the TaskReference
 * to which it refers.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_getVariableByTaskReference(SedComputeChange_t* scc,
                                            const char *sid)
{
  return (scc != NULL && sid != NULL) ? scc->getVariableByTaskReference(sid) :
    NULL;
}


/*
 * Get a SedVariable_t from the SedComputeChange_t based on the ModelReference
 * to which it refers.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_getVariableByModelReference(SedComputeChange_t* scc,
                                             const char *sid)
{
  return (scc != NULL && sid != NULL) ? scc->getVariableByModelReference(sid) :
    NULL;
}


/*
 * Adds a copy of the given SedVariable_t to this SedComputeChange_t.
 */
LIBSEDML_EXTERN
int
SedComputeChange_addVariable(SedComputeChange_t* scc, const SedVariable_t* sv)
{
  return (scc != NULL) ? scc->addVariable(sv) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedVariable_t objects in this SedComputeChange_t.
 */
LIBSEDML_EXTERN
unsigned int
SedComputeChange_getNumVariables(SedComputeChange_t* scc)
{
  return (scc != NULL) ? scc->getNumVariables() : SEDML_INT_MAX;
}


/*
 * Creates a new SedVariable_t object, adds it to this SedComputeChange_t
 * object and returns the SedVariable_t object created.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_createVariable(SedComputeChange_t* scc)
{
  return (scc != NULL) ? scc->createVariable() : NULL;
}


/*
 * Removes the nth SedVariable_t from this SedComputeChange_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_removeVariable(SedComputeChange_t* scc, unsigned int n)
{
  return (scc != NULL) ? scc->removeVariable(n) : NULL;
}


/*
 * Removes the SedVariable_t from this SedComputeChange_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_removeVariableById(SedComputeChange_t* scc, const char* sid)
{
  return (scc != NULL && sid != NULL) ? scc->removeVariable(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedParameter_t objects from this
 * SedComputeChange_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedComputeChange_getListOfParameters(SedComputeChange_t* scc)
{
  return (scc != NULL) ? scc->getListOfParameters() : NULL;
}


/*
 * Get a SedParameter_t from the SedComputeChange_t.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_getParameter(SedComputeChange_t* scc, unsigned int n)
{
  return (scc != NULL) ? scc->getParameter(n) : NULL;
}


/*
 * Get a SedParameter_t from the SedComputeChange_t based on its identifier.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_getParameterById(SedComputeChange_t* scc, const char *sid)
{
  return (scc != NULL && sid != NULL) ? scc->getParameter(sid) : NULL;
}


/*
 * Adds a copy of the given SedParameter_t to this SedComputeChange_t.
 */
LIBSEDML_EXTERN
int
SedComputeChange_addParameter(SedComputeChange_t* scc,
                              const SedParameter_t* sp)
{
  return (scc != NULL) ? scc->addParameter(sp) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedParameter_t objects in this SedComputeChange_t.
 */
LIBSEDML_EXTERN
unsigned int
SedComputeChange_getNumParameters(SedComputeChange_t* scc)
{
  return (scc != NULL) ? scc->getNumParameters() : SEDML_INT_MAX;
}


/*
 * Creates a new SedParameter_t object, adds it to this SedComputeChange_t
 * object and returns the SedParameter_t object created.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_createParameter(SedComputeChange_t* scc)
{
  return (scc != NULL) ? scc->createParameter() : NULL;
}


/*
 * Removes the nth SedParameter_t from this SedComputeChange_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_removeParameter(SedComputeChange_t* scc, unsigned int n)
{
  return (scc != NULL) ? scc->removeParameter(n) : NULL;
}


/*
 * Removes the SedParameter_t from this SedComputeChange_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_removeParameterById(SedComputeChange_t* scc, const char* sid)
{
  return (scc != NULL && sid != NULL) ? scc->removeParameter(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedComputeChange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedComputeChange_hasRequiredAttributes(const SedComputeChange_t * scc)
{
  return (scc != NULL) ? static_cast<int>(scc->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedComputeChange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedComputeChange_hasRequiredElements(const SedComputeChange_t * scc)
{
  return (scc != NULL) ? static_cast<int>(scc->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


