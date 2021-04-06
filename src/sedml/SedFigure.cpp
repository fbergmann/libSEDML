/**
 * @file SedFigure.cpp
 * @brief Implementation of the SedFigure class.
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
#include <sedml/SedFigure.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedFigure using the given SED-ML Level and @ p version values.
 */
SedFigure::SedFigure(unsigned int level, unsigned int version)
  : SedOutput(level, version)
  , mNumRows (SEDML_INT_MAX)
  , mIsSetNumRows (false)
  , mNumCols (SEDML_INT_MAX)
  , mIsSetNumCols (false)
  , mSubPlots (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedFigure using the given SedNamespaces object @p sedmlns.
 */
SedFigure::SedFigure(SedNamespaces *sedmlns)
  : SedOutput(sedmlns)
  , mNumRows (SEDML_INT_MAX)
  , mIsSetNumRows (false)
  , mNumCols (SEDML_INT_MAX)
  , mIsSetNumCols (false)
  , mSubPlots (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedFigure.
 */
SedFigure::SedFigure(const SedFigure& orig)
  : SedOutput( orig )
  , mNumRows ( orig.mNumRows )
  , mIsSetNumRows ( orig.mIsSetNumRows )
  , mNumCols ( orig.mNumCols )
  , mIsSetNumCols ( orig.mIsSetNumCols )
  , mSubPlots ( orig.mSubPlots )
{
  connectToChild();
}


/*
 * Assignment operator for SedFigure.
 */
SedFigure&
SedFigure::operator=(const SedFigure& rhs)
{
  if (&rhs != this)
  {
    SedOutput::operator=(rhs);
    mNumRows = rhs.mNumRows;
    mIsSetNumRows = rhs.mIsSetNumRows;
    mNumCols = rhs.mNumCols;
    mIsSetNumCols = rhs.mIsSetNumCols;
    mSubPlots = rhs.mSubPlots;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedFigure object.
 */
SedFigure*
SedFigure::clone() const
{
  return new SedFigure(*this);
}


/*
 * Destructor for SedFigure.
 */
SedFigure::~SedFigure()
{
}


/*
 * Returns the value of the "numRows" attribute of this SedFigure.
 */
int
SedFigure::getNumRows() const
{
  return mNumRows;
}


/*
 * Returns the value of the "numCols" attribute of this SedFigure.
 */
int
SedFigure::getNumCols() const
{
  return mNumCols;
}


/*
 * Predicate returning @c true if this SedFigure's "numRows" attribute is set.
 */
bool
SedFigure::isSetNumRows() const
{
  return mIsSetNumRows;
}


/*
 * Predicate returning @c true if this SedFigure's "numCols" attribute is set.
 */
bool
SedFigure::isSetNumCols() const
{
  return mIsSetNumCols;
}


/*
 * Sets the value of the "numRows" attribute of this SedFigure.
 */
int
SedFigure::setNumRows(int numRows)
{
  mNumRows = numRows;
  mIsSetNumRows = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "numCols" attribute of this SedFigure.
 */
int
SedFigure::setNumCols(int numCols)
{
  mNumCols = numCols;
  mIsSetNumCols = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "numRows" attribute of this SedFigure.
 */
int
SedFigure::unsetNumRows()
{
  mNumRows = SEDML_INT_MAX;
  mIsSetNumRows = false;

  if (isSetNumRows() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "numCols" attribute of this SedFigure.
 */
int
SedFigure::unsetNumCols()
{
  mNumCols = SEDML_INT_MAX;
  mIsSetNumCols = false;

  if (isSetNumCols() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfSubPlots from this SedFigure.
 */
const SedListOfSubPlots*
SedFigure::getListOfSubPlots() const
{
  return &mSubPlots;
}


/*
 * Returns the SedListOfSubPlots from this SedFigure.
 */
SedListOfSubPlots*
SedFigure::getListOfSubPlots()
{
  return &mSubPlots;
}


/*
 * Get a SedSubPlot from the SedFigure.
 */
SedSubPlot*
SedFigure::getSubPlot(unsigned int n)
{
  return mSubPlots.get(n);
}


/*
 * Get a SedSubPlot from the SedFigure.
 */
const SedSubPlot*
SedFigure::getSubPlot(unsigned int n) const
{
  return mSubPlots.get(n);
}


/*
 * Get a SedSubPlot from the SedFigure based on the Plot to which it refers.
 */
const SedSubPlot*
SedFigure::getSubPlotByPlot(const std::string& sid) const
{
  return mSubPlots.getByPlot(sid);
}


/*
 * Get a SedSubPlot from the SedFigure based on the Plot to which it refers.
 */
SedSubPlot*
SedFigure::getSubPlotByPlot(const std::string& sid)
{
  return mSubPlots.getByPlot(sid);
}


/*
 * Adds a copy of the given SedSubPlot to this SedFigure.
 */
int
SedFigure::addSubPlot(const SedSubPlot* ssp)
{
  if (ssp == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ssp->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ssp->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ssp->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ssp)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mSubPlots.append(ssp);
  }
}


/*
 * Get the number of SedSubPlot objects in this SedFigure.
 */
unsigned int
SedFigure::getNumSubPlots() const
{
  return mSubPlots.size();
}


/*
 * Creates a new SedSubPlot object, adds it to this SedFigure object and
 * returns the SedSubPlot object created.
 */
SedSubPlot*
SedFigure::createSubPlot()
{
  SedSubPlot* ssp = NULL;

  try
  {
    ssp = new SedSubPlot(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ssp != NULL)
  {
    mSubPlots.appendAndOwn(ssp);
  }

  return ssp;
}


/*
 * Removes the nth SedSubPlot from this SedFigure and returns a pointer to it.
 */
SedSubPlot*
SedFigure::removeSubPlot(unsigned int n)
{
  return mSubPlots.remove(n);
}


/*
 * Returns the XML element name of this SedFigure object.
 */
const std::string&
SedFigure::getElementName() const
{
  static const string name = "figure";
  return name;
}


/*
 * Returns the libSEDML type code for this SedFigure object.
 */
int
SedFigure::getTypeCode() const
{
  return SEDML_FIGURE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedFigure object have been set.
 */
bool
SedFigure::hasRequiredAttributes() const
{
  bool allPresent = SedOutput::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SedFigure
 * object have been set.
 */
bool
SedFigure::hasRequiredElements() const
{
  bool allPresent = SedOutput::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedFigure::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedOutput::writeElements(stream);

  if (getNumSubPlots() > 0)
  {
    mSubPlots.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedFigure::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedFigure::setSedDocument(SedDocument* d)
{
  SedOutput::setSedDocument(d);

  mSubPlots.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedFigure::connectToChild()
{
  SedOutput::connectToChild();

  mSubPlots.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "numRows")
  {
    value = getNumRows();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "numCols")
  {
    value = getNumCols();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedFigure's attribute "attributeName" is
 * set.
 */
bool
SedFigure::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedOutput::isSetAttribute(attributeName);

  if (attributeName == "numRows")
  {
    value = isSetNumRows();
  }
  else if (attributeName == "numCols")
  {
    value = isSetNumCols();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  if (attributeName == "numRows")
  {
    return_value = setNumRows(value);
  }
  else if (attributeName == "numCols")
  {
    return_value = setNumCols(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedFigure.
 */
int
SedFigure::unsetAttribute(const std::string& attributeName)
{
  int value = SedOutput::unsetAttribute(attributeName);

  if (attributeName == "numRows")
  {
    value = unsetNumRows();
  }
  else if (attributeName == "numCols")
  {
    value = unsetNumCols();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedFigure.
 */
SedBase*
SedFigure::createChildObject(const std::string& elementName)
{
  SedOutput* obj = NULL;

  if (elementName == "subPlot")
  {
    return createSubPlot();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedFigure.
 */
int
SedFigure::addChildObject(const std::string& elementName,
                          const SedBase* element)
{
  if (elementName == "subPlot" && element->getTypeCode() == SEDML_SUBPLOT)
  {
    return addSubPlot((const SedSubPlot*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedFigure.
 */
SedBase*
SedFigure::removeChildObject(const std::string& elementName,
                             const std::string& id)
{
  if (elementName == "subPlot")
  {
    for (unsigned int i = 0; i < getNumSubPlots(); i++)
    {
      if (getSubPlot(i)->getId() == id)
      {
        return removeSubPlot(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedFigure.
 */
unsigned int
SedFigure::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "subPlot")
  {
    return getNumSubPlots();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedFigure.
 */
SedBase*
SedFigure::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "subPlot")
  {
    return getSubPlot(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedFigure::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mSubPlots.getElementBySId(id);

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
SedFigure::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mSubPlots, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedFigure::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = SedOutput::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "listOfSubPlots")
  {
    if (getErrorLog() && mSubPlots.size() != 0)
    {
      getErrorLog()->logError(SedmlFigureAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mSubPlots;
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
SedFigure::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedOutput::addExpectedAttributes(attributes);

  attributes.add("numRows");

  attributes.add("numCols");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedFigure::readAttributes(
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

  SedOutput::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlFigureAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // numRows int (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetNumRows = attributes.readInto("numRows", mNumRows);

  if ( mIsSetNumRows == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'numRows' from the <SedFigure> "
        "element must be an integer.";
      log->logError(SedmlFigureNumRowsMustBeInteger, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // numCols int (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetNumCols = attributes.readInto("numCols", mNumCols);

  if ( mIsSetNumCols == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'numCols' from the <SedFigure> "
        "element must be an integer.";
      log->logError(SedmlFigureNumColsMustBeInteger, level, version, message,
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
SedFigure::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedOutput::writeAttributes(stream);

  if (isSetNumRows() == true)
  {
    stream.writeAttribute("numRows", getPrefix(), mNumRows);
  }

  if (isSetNumCols() == true)
  {
    stream.writeAttribute("numCols", getPrefix(), mNumCols);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedFigure_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedFigure_t *
SedFigure_create(unsigned int level, unsigned int version)
{
  return new SedFigure(level, version);
}


/*
 * Creates and returns a deep copy of this SedFigure_t object.
 */
LIBSEDML_EXTERN
SedFigure_t*
SedFigure_clone(const SedFigure_t* sf)
{
  if (sf != NULL)
  {
    return static_cast<SedFigure_t*>(sf->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedFigure_t object.
 */
LIBSEDML_EXTERN
void
SedFigure_free(SedFigure_t* sf)
{
  if (sf != NULL)
  {
    delete sf;
  }
}


/*
 * Returns the value of the "numRows" attribute of this SedFigure_t.
 */
LIBSEDML_EXTERN
int
SedFigure_getNumRows(const SedFigure_t * sf)
{
  return (sf != NULL) ? sf->getNumRows() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "numCols" attribute of this SedFigure_t.
 */
LIBSEDML_EXTERN
int
SedFigure_getNumCols(const SedFigure_t * sf)
{
  return (sf != NULL) ? sf->getNumCols() : SEDML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this SedFigure_t's "numRows" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedFigure_isSetNumRows(const SedFigure_t * sf)
{
  return (sf != NULL) ? static_cast<int>(sf->isSetNumRows()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedFigure_t's "numCols" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedFigure_isSetNumCols(const SedFigure_t * sf)
{
  return (sf != NULL) ? static_cast<int>(sf->isSetNumCols()) : 0;
}


/*
 * Sets the value of the "numRows" attribute of this SedFigure_t.
 */
LIBSEDML_EXTERN
int
SedFigure_setNumRows(SedFigure_t * sf, int numRows)
{
  return (sf != NULL) ? sf->setNumRows(numRows) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "numCols" attribute of this SedFigure_t.
 */
LIBSEDML_EXTERN
int
SedFigure_setNumCols(SedFigure_t * sf, int numCols)
{
  return (sf != NULL) ? sf->setNumCols(numCols) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "numRows" attribute of this SedFigure_t.
 */
LIBSEDML_EXTERN
int
SedFigure_unsetNumRows(SedFigure_t * sf)
{
  return (sf != NULL) ? sf->unsetNumRows() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "numCols" attribute of this SedFigure_t.
 */
LIBSEDML_EXTERN
int
SedFigure_unsetNumCols(SedFigure_t * sf)
{
  return (sf != NULL) ? sf->unsetNumCols() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedSubPlot_t objects from this SedFigure_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedFigure_getListOfSubPlots(SedFigure_t* sf)
{
  return (sf != NULL) ? sf->getListOfSubPlots() : NULL;
}


/*
 * Get a SedSubPlot_t from the SedFigure_t.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedFigure_getSubPlot(SedFigure_t* sf, unsigned int n)
{
  return (sf != NULL) ? sf->getSubPlot(n) : NULL;
}


/*
 * Get a SedSubPlot_t from the SedFigure_t based on the Plot to which it
 * refers.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedFigure_getSubPlotByPlot(SedFigure_t* sf, const char *sid)
{
  return (sf != NULL && sid != NULL) ? sf->getSubPlotByPlot(sid) : NULL;
}


/*
 * Adds a copy of the given SedSubPlot_t to this SedFigure_t.
 */
LIBSEDML_EXTERN
int
SedFigure_addSubPlot(SedFigure_t* sf, const SedSubPlot_t* ssp)
{
  return (sf != NULL) ? sf->addSubPlot(ssp) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedSubPlot_t objects in this SedFigure_t.
 */
LIBSEDML_EXTERN
unsigned int
SedFigure_getNumSubPlots(SedFigure_t* sf)
{
  return (sf != NULL) ? sf->getNumSubPlots() : SEDML_INT_MAX;
}


/*
 * Creates a new SedSubPlot_t object, adds it to this SedFigure_t object and
 * returns the SedSubPlot_t object created.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedFigure_createSubPlot(SedFigure_t* sf)
{
  return (sf != NULL) ? sf->createSubPlot() : NULL;
}


/*
 * Removes the nth SedSubPlot_t from this SedFigure_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedFigure_removeSubPlot(SedFigure_t* sf, unsigned int n)
{
  return (sf != NULL) ? sf->removeSubPlot(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFigure_t object have been set.
 */
LIBSEDML_EXTERN
int
SedFigure_hasRequiredAttributes(const SedFigure_t * sf)
{
  return (sf != NULL) ? static_cast<int>(sf->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedFigure_t object have been set.
 */
LIBSEDML_EXTERN
int
SedFigure_hasRequiredElements(const SedFigure_t * sf)
{
  return (sf != NULL) ? static_cast<int>(sf->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


