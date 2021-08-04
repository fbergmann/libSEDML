/**
 * @file SedFunctionalRange.cpp
 * @brief Implementation of the SedFunctionalRange class.
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
#include <sedml/SedFunctionalRange.h>
#include <sedml/SedVariable.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedFunctionalRange using the given SED-ML Level and @ p version
 * values.
 */
SedFunctionalRange::SedFunctionalRange(unsigned int level,
                                       unsigned int version)
  : SedRange(level, version)
  , mRange ("")
  , mMath (NULL)
  , mVariables (level, version)
  , mParameters (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedFunctionalRange using the given SedNamespaces object @p
 * sedmlns.
 */
SedFunctionalRange::SedFunctionalRange(SedNamespaces *sedmlns)
  : SedRange(sedmlns)
  , mRange ("")
  , mMath (NULL)
  , mVariables (sedmlns)
  , mParameters (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedFunctionalRange.
 */
SedFunctionalRange::SedFunctionalRange(const SedFunctionalRange& orig)
  : SedRange( orig )
  , mRange ( orig.mRange )
  , mMath ( NULL )
  , mVariables ( orig.mVariables )
  , mParameters ( orig.mParameters )
{
  if (orig.mMath != NULL)
  {
    mMath = orig.mMath->deepCopy();
  }

  connectToChild();
}


/*
 * Assignment operator for SedFunctionalRange.
 */
SedFunctionalRange&
SedFunctionalRange::operator=(const SedFunctionalRange& rhs)
{
  if (&rhs != this)
  {
    SedRange::operator=(rhs);
    mRange = rhs.mRange;
    mVariables = rhs.mVariables;
    mParameters = rhs.mParameters;
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
 * Creates and returns a deep copy of this SedFunctionalRange object.
 */
SedFunctionalRange*
SedFunctionalRange::clone() const
{
  return new SedFunctionalRange(*this);
}


/*
 * Destructor for SedFunctionalRange.
 */
SedFunctionalRange::~SedFunctionalRange()
{
  delete mMath;
  mMath = NULL;
}


/*
 * Returns the value of the "range" attribute of this SedFunctionalRange.
 */
const std::string&
SedFunctionalRange::getRange() const
{
  return mRange;
}


/*
 * Predicate returning @c true if this SedFunctionalRange's "range" attribute
 * is set.
 */
bool
SedFunctionalRange::isSetRange() const
{
  return (mRange.empty() == false);
}


/*
 * Sets the value of the "range" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::setRange(const std::string& range)
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
 * Unsets the value of the "range" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::unsetRange()
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
 * Returns the value of the "math" element of this SedFunctionalRange.
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
SedFunctionalRange::getMath() const
{
  return mMath;
}


/*
 * Returns the value of the "math" element of this SedFunctionalRange.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
SedFunctionalRange::getMath()
{
  return mMath;
}


/*
 * Predicate returning @c true if this SedFunctionalRange's "math" element is
 * set.
 */
bool
SedFunctionalRange::isSetMath() const
{
  return (mMath != NULL);
}


/*
 * Sets the value of the "math" element of this SedFunctionalRange.
 */
int
SedFunctionalRange::setMath(const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*
  math)
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
 * Unsets the value of the "math" element of this SedFunctionalRange.
 */
int
SedFunctionalRange::unsetMath()
{
  delete mMath;
  mMath = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfVariables from this SedFunctionalRange.
 */
const SedListOfVariables*
SedFunctionalRange::getListOfVariables() const
{
  return &mVariables;
}


/*
 * Returns the SedListOfVariables from this SedFunctionalRange.
 */
SedListOfVariables*
SedFunctionalRange::getListOfVariables()
{
  return &mVariables;
}


/*
 * Get a SedVariable from the SedFunctionalRange.
 */
SedVariable*
SedFunctionalRange::getVariable(unsigned int n)
{
  return mVariables.get(n);
}


/*
 * Get a SedVariable from the SedFunctionalRange.
 */
const SedVariable*
SedFunctionalRange::getVariable(unsigned int n) const
{
  return mVariables.get(n);
}


/*
 * Get a SedVariable from the SedFunctionalRange based on its identifier.
 */
SedVariable*
SedFunctionalRange::getVariable(const std::string& sid)
{
  return mVariables.get(sid);
}


/*
 * Get a SedVariable from the SedFunctionalRange based on its identifier.
 */
const SedVariable*
SedFunctionalRange::getVariable(const std::string& sid) const
{
  return mVariables.get(sid);
}


/*
 * Get a SedVariable from the SedFunctionalRange based on the TaskReference to
 * which it refers.
 */
const SedVariable*
SedFunctionalRange::getVariableByTaskReference(const std::string& sid) const
{
  return mVariables.getByTaskReference(sid);
}


/*
 * Get a SedVariable from the SedFunctionalRange based on the TaskReference to
 * which it refers.
 */
SedVariable*
SedFunctionalRange::getVariableByTaskReference(const std::string& sid)
{
  return mVariables.getByTaskReference(sid);
}


/*
 * Get a SedVariable from the SedFunctionalRange based on the ModelReference to
 * which it refers.
 */
const SedVariable*
SedFunctionalRange::getVariableByModelReference(const std::string& sid) const
{
  return mVariables.getByModelReference(sid);
}


/*
 * Get a SedVariable from the SedFunctionalRange based on the ModelReference to
 * which it refers.
 */
SedVariable*
SedFunctionalRange::getVariableByModelReference(const std::string& sid)
{
  return mVariables.getByModelReference(sid);
}


/*
 * Adds a copy of the given SedVariable to this SedFunctionalRange.
 */
int
SedFunctionalRange::addVariable(const SedVariable* sv)
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
 * Get the number of SedVariable objects in this SedFunctionalRange.
 */
unsigned int
SedFunctionalRange::getNumVariables() const
{
  return mVariables.size();
}


/*
 * Creates a new SedVariable object, adds it to this SedFunctionalRange object
 * and returns the SedVariable object created.
 */
SedVariable*
SedFunctionalRange::createVariable()
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
 * Removes the nth SedVariable from this SedFunctionalRange and returns a
 * pointer to it.
 */
SedVariable*
SedFunctionalRange::removeVariable(unsigned int n)
{
  return mVariables.remove(n);
}


/*
 * Removes the SedVariable from this SedFunctionalRange based on its identifier
 * and returns a pointer to it.
 */
SedVariable*
SedFunctionalRange::removeVariable(const std::string& sid)
{
  return mVariables.remove(sid);
}


/*
 * Returns the SedListOfParameters from this SedFunctionalRange.
 */
const SedListOfParameters*
SedFunctionalRange::getListOfParameters() const
{
  return &mParameters;
}


/*
 * Returns the SedListOfParameters from this SedFunctionalRange.
 */
SedListOfParameters*
SedFunctionalRange::getListOfParameters()
{
  return &mParameters;
}


/*
 * Get a SedParameter from the SedFunctionalRange.
 */
SedParameter*
SedFunctionalRange::getParameter(unsigned int n)
{
  return mParameters.get(n);
}


/*
 * Get a SedParameter from the SedFunctionalRange.
 */
const SedParameter*
SedFunctionalRange::getParameter(unsigned int n) const
{
  return mParameters.get(n);
}


/*
 * Get a SedParameter from the SedFunctionalRange based on its identifier.
 */
SedParameter*
SedFunctionalRange::getParameter(const std::string& sid)
{
  return mParameters.get(sid);
}


/*
 * Get a SedParameter from the SedFunctionalRange based on its identifier.
 */
const SedParameter*
SedFunctionalRange::getParameter(const std::string& sid) const
{
  return mParameters.get(sid);
}


/*
 * Adds a copy of the given SedParameter to this SedFunctionalRange.
 */
int
SedFunctionalRange::addParameter(const SedParameter* sp)
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
 * Get the number of SedParameter objects in this SedFunctionalRange.
 */
unsigned int
SedFunctionalRange::getNumParameters() const
{
  return mParameters.size();
}


/*
 * Creates a new SedParameter object, adds it to this SedFunctionalRange object
 * and returns the SedParameter object created.
 */
SedParameter*
SedFunctionalRange::createParameter()
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
 * Removes the nth SedParameter from this SedFunctionalRange and returns a
 * pointer to it.
 */
SedParameter*
SedFunctionalRange::removeParameter(unsigned int n)
{
  return mParameters.remove(n);
}


/*
 * Removes the SedParameter from this SedFunctionalRange based on its
 * identifier and returns a pointer to it.
 */
SedParameter*
SedFunctionalRange::removeParameter(const std::string& sid)
{
  return mParameters.remove(sid);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedFunctionalRange::renameSIdRefs(const std::string& oldid,
                                  const std::string& newid)
{
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
 * Returns the XML element name of this SedFunctionalRange object.
 */
const std::string&
SedFunctionalRange::getElementName() const
{
  static const string name = "functionalRange";
  return name;
}


/*
 * Returns the libSEDML type code for this SedFunctionalRange object.
 */
int
SedFunctionalRange::getTypeCode() const
{
  return SEDML_RANGE_FUNCTIONALRANGE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedFunctionalRange object have been set.
 */
bool
SedFunctionalRange::hasRequiredAttributes() const
{
  bool allPresent = SedRange::hasRequiredAttributes();

  if (isSetRange() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedFunctionalRange object have been set.
 */
bool
SedFunctionalRange::hasRequiredElements() const
{
  bool allPresent = SedRange::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedFunctionalRange::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedRange::writeElements(stream);

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
SedFunctionalRange::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedFunctionalRange::setSedDocument(SedDocument* d)
{
  SedRange::setSedDocument(d);

  mVariables.setSedDocument(d);

  mParameters.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedFunctionalRange::connectToChild()
{
  SedRange::connectToChild();

  mVariables.connectToParent(this);

  mParameters.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::getAttribute(const std::string& attributeName,
                                 bool& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::getAttribute(const std::string& attributeName,
                                 int& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::getAttribute(const std::string& attributeName,
                                 double& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::getAttribute(const std::string& attributeName,
                                 unsigned int& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::getAttribute(const std::string& attributeName,
                                 std::string& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "range")
  {
    value = getRange();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedFunctionalRange's attribute
 * "attributeName" is set.
 */
bool
SedFunctionalRange::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedRange::isSetAttribute(attributeName);

  if (attributeName == "range")
  {
    value = isSetRange();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::setAttribute(const std::string& attributeName,
                                 double value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::setAttribute(const std::string& attributeName,
                                 unsigned int value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFunctionalRange.
 */
int
SedFunctionalRange::setAttribute(const std::string& attributeName,
                                 const std::string& value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  if (attributeName == "range")
  {
    return_value = setRange(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedFunctionalRange.
 */
int
SedFunctionalRange::unsetAttribute(const std::string& attributeName)
{
  int value = SedRange::unsetAttribute(attributeName);

  if (attributeName == "range")
  {
    value = unsetRange();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedFunctionalRange.
 */
SedBase*
SedFunctionalRange::createChildObject(const std::string& elementName)
{
  SedRange* obj = NULL;

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
 * Adds a new "elementName" object to this SedFunctionalRange.
 */
int
SedFunctionalRange::addChildObject(const std::string& elementName,
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
 * SedFunctionalRange.
 */
SedBase*
SedFunctionalRange::removeChildObject(const std::string& elementName,
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
 * Returns the number of "elementName" in this SedFunctionalRange.
 */
unsigned int
SedFunctionalRange::getNumObjects(const std::string& elementName)
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
 * Returns the nth object of "objectName" in this SedFunctionalRange.
 */
SedBase*
SedFunctionalRange::getObject(const std::string& elementName,
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
SedFunctionalRange::getElementBySId(const std::string& id)
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
SedFunctionalRange::getAllElements(SedElementFilter* filter)
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
SedFunctionalRange::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = SedRange::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "listOfVariables")
  {
    if (getErrorLog() && mVariables.size() != 0)
    {
      getErrorLog()->logError(SedmlFunctionalRangeAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mVariables;
  }
  else if (name == "listOfParameters")
  {
    if (getErrorLog() && mParameters.size() != 0)
    {
      getErrorLog()->logError(SedmlFunctionalRangeAllowedElements, getLevel(),
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
SedFunctionalRange::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedRange::addExpectedAttributes(attributes);

  attributes.add("range");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedFunctionalRange::readAttributes(
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

  SedRange::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlFunctionalRangeAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // range SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("range", mRange);

  if (assigned == true)
  {
    if (mRange.empty() == true)
    {
      logEmptyString(mRange, level, version, "<SedFunctionalRange>");
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
      logError(SedmlFunctionalRangeRangeMustBeRange, level, version, msg,
        getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'range' is missing from the "
        "<SedFunctionalRange> element.";
      log->logError(SedmlFunctionalRangeAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
SedFunctionalRange::readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
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

  if (SedRange::readOtherXML(stream))
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
SedFunctionalRange::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedRange::writeAttributes(stream);

  if (isSetRange() == true)
  {
    stream.writeAttribute("range", getPrefix(), mRange);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedFunctionalRange_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedFunctionalRange_t *
SedFunctionalRange_create(unsigned int level, unsigned int version)
{
  return new SedFunctionalRange(level, version);
}


/*
 * Creates and returns a deep copy of this SedFunctionalRange_t object.
 */
LIBSEDML_EXTERN
SedFunctionalRange_t*
SedFunctionalRange_clone(const SedFunctionalRange_t* sfr)
{
  if (sfr != NULL)
  {
    return static_cast<SedFunctionalRange_t*>(sfr->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedFunctionalRange_t object.
 */
LIBSEDML_EXTERN
void
SedFunctionalRange_free(SedFunctionalRange_t* sfr)
{
  if (sfr != NULL)
  {
    delete sfr;
  }
}


/*
 * Returns the value of the "range" attribute of this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
char *
SedFunctionalRange_getRange(const SedFunctionalRange_t * sfr)
{
  if (sfr == NULL)
  {
    return NULL;
  }

  return sfr->getRange().empty() ? NULL : safe_strdup(sfr->getRange().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedFunctionalRange_t's "range"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_isSetRange(const SedFunctionalRange_t * sfr)
{
  return (sfr != NULL) ? static_cast<int>(sfr->isSetRange()) : 0;
}


/*
 * Sets the value of the "range" attribute of this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_setRange(SedFunctionalRange_t * sfr, const char * range)
{
  return (sfr != NULL) ? sfr->setRange(range) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "range" attribute of this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_unsetRange(SedFunctionalRange_t * sfr)
{
  return (sfr != NULL) ? sfr->unsetRange() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "math" element of this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
SedFunctionalRange_getMath(const SedFunctionalRange_t * sfr)
{
  if (sfr == NULL)
  {
    return NULL;
  }

  return (LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*)(sfr->getMath());
}


/*
 * Predicate returning @c 1 (true) if this SedFunctionalRange_t's "math"
 * element is set.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_isSetMath(const SedFunctionalRange_t * sfr)
{
  return (sfr != NULL) ? static_cast<int>(sfr->isSetMath()) : 0;
}


/*
 * Sets the value of the "math" element of this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_setMath(SedFunctionalRange_t * sfr,
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
                             math)
{
  return (sfr != NULL) ? sfr->setMath(math) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "math" element of this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_unsetMath(SedFunctionalRange_t * sfr)
{
  return (sfr != NULL) ? sfr->unsetMath() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedVariable_t objects from this
 * SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedFunctionalRange_getListOfVariables(SedFunctionalRange_t* sfr)
{
  return (sfr != NULL) ? sfr->getListOfVariables() : NULL;
}


/*
 * Get a SedVariable_t from the SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_getVariable(SedFunctionalRange_t* sfr, unsigned int n)
{
  return (sfr != NULL) ? sfr->getVariable(n) : NULL;
}


/*
 * Get a SedVariable_t from the SedFunctionalRange_t based on its identifier.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_getVariableById(SedFunctionalRange_t* sfr, const char *sid)
{
  return (sfr != NULL && sid != NULL) ? sfr->getVariable(sid) : NULL;
}


/*
 * Get a SedVariable_t from the SedFunctionalRange_t based on the TaskReference
 * to which it refers.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_getVariableByTaskReference(SedFunctionalRange_t* sfr,
                                              const char *sid)
{
  return (sfr != NULL && sid != NULL) ? sfr->getVariableByTaskReference(sid) :
    NULL;
}


/*
 * Get a SedVariable_t from the SedFunctionalRange_t based on the
 * ModelReference to which it refers.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_getVariableByModelReference(SedFunctionalRange_t* sfr,
                                               const char *sid)
{
  return (sfr != NULL && sid != NULL) ? sfr->getVariableByModelReference(sid) :
    NULL;
}


/*
 * Adds a copy of the given SedVariable_t to this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_addVariable(SedFunctionalRange_t* sfr,
                               const SedVariable_t* sv)
{
  return (sfr != NULL) ? sfr->addVariable(sv) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedVariable_t objects in this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
unsigned int
SedFunctionalRange_getNumVariables(SedFunctionalRange_t* sfr)
{
  return (sfr != NULL) ? sfr->getNumVariables() : SEDML_INT_MAX;
}


/*
 * Creates a new SedVariable_t object, adds it to this SedFunctionalRange_t
 * object and returns the SedVariable_t object created.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_createVariable(SedFunctionalRange_t* sfr)
{
  return (sfr != NULL) ? sfr->createVariable() : NULL;
}


/*
 * Removes the nth SedVariable_t from this SedFunctionalRange_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_removeVariable(SedFunctionalRange_t* sfr, unsigned int n)
{
  return (sfr != NULL) ? sfr->removeVariable(n) : NULL;
}


/*
 * Removes the SedVariable_t from this SedFunctionalRange_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_removeVariableById(SedFunctionalRange_t* sfr,
                                      const char* sid)
{
  return (sfr != NULL && sid != NULL) ? sfr->removeVariable(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SedParameter_t objects from this
 * SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedFunctionalRange_getListOfParameters(SedFunctionalRange_t* sfr)
{
  return (sfr != NULL) ? sfr->getListOfParameters() : NULL;
}


/*
 * Get a SedParameter_t from the SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_getParameter(SedFunctionalRange_t* sfr, unsigned int n)
{
  return (sfr != NULL) ? sfr->getParameter(n) : NULL;
}


/*
 * Get a SedParameter_t from the SedFunctionalRange_t based on its identifier.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_getParameterById(SedFunctionalRange_t* sfr,
                                    const char *sid)
{
  return (sfr != NULL && sid != NULL) ? sfr->getParameter(sid) : NULL;
}


/*
 * Adds a copy of the given SedParameter_t to this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_addParameter(SedFunctionalRange_t* sfr,
                                const SedParameter_t* sp)
{
  return (sfr != NULL) ? sfr->addParameter(sp) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedParameter_t objects in this SedFunctionalRange_t.
 */
LIBSEDML_EXTERN
unsigned int
SedFunctionalRange_getNumParameters(SedFunctionalRange_t* sfr)
{
  return (sfr != NULL) ? sfr->getNumParameters() : SEDML_INT_MAX;
}


/*
 * Creates a new SedParameter_t object, adds it to this SedFunctionalRange_t
 * object and returns the SedParameter_t object created.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_createParameter(SedFunctionalRange_t* sfr)
{
  return (sfr != NULL) ? sfr->createParameter() : NULL;
}


/*
 * Removes the nth SedParameter_t from this SedFunctionalRange_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_removeParameter(SedFunctionalRange_t* sfr, unsigned int n)
{
  return (sfr != NULL) ? sfr->removeParameter(n) : NULL;
}


/*
 * Removes the SedParameter_t from this SedFunctionalRange_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_removeParameterById(SedFunctionalRange_t* sfr,
                                       const char* sid)
{
  return (sfr != NULL && sid != NULL) ? sfr->removeParameter(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFunctionalRange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_hasRequiredAttributes(const SedFunctionalRange_t * sfr)
{
  return (sfr != NULL) ? static_cast<int>(sfr->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedFunctionalRange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_hasRequiredElements(const SedFunctionalRange_t * sfr)
{
  return (sfr != NULL) ? static_cast<int>(sfr->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


