/**
 * @file SedStyle.cpp
 * @brief Implementation of the SedStyle class.
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
#include <sedml/SedStyle.h>
#include <sedml/SedListOfStyles.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedStyle using the given SED-ML Level and @ p version values.
 */
SedStyle::SedStyle(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mBaseStyle ("")
  , mLineStyle (NULL)
  , mMarkerStyle (NULL)
  , mFillStyle (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedStyle using the given SedNamespaces object @p sedmlns.
 */
SedStyle::SedStyle(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mBaseStyle ("")
  , mLineStyle (NULL)
  , mMarkerStyle (NULL)
  , mFillStyle (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedStyle.
 */
SedStyle::SedStyle(const SedStyle& orig)
  : SedBase( orig )
  , mBaseStyle ( orig.mBaseStyle )
  , mLineStyle ( NULL )
  , mMarkerStyle ( NULL )
  , mFillStyle ( NULL )
{
  if (orig.mLineStyle != NULL)
  {
    mLineStyle = orig.mLineStyle->clone();
  }

  if (orig.mMarkerStyle != NULL)
  {
    mMarkerStyle = orig.mMarkerStyle->clone();
  }

  if (orig.mFillStyle != NULL)
  {
    mFillStyle = orig.mFillStyle->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedStyle.
 */
SedStyle&
SedStyle::operator=(const SedStyle& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mBaseStyle = rhs.mBaseStyle;
    delete mLineStyle;
    if (rhs.mLineStyle != NULL)
    {
      mLineStyle = rhs.mLineStyle->clone();
    }
    else
    {
      mLineStyle = NULL;
    }

    delete mMarkerStyle;
    if (rhs.mMarkerStyle != NULL)
    {
      mMarkerStyle = rhs.mMarkerStyle->clone();
    }
    else
    {
      mMarkerStyle = NULL;
    }

    delete mFillStyle;
    if (rhs.mFillStyle != NULL)
    {
      mFillStyle = rhs.mFillStyle->clone();
    }
    else
    {
      mFillStyle = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedStyle object.
 */
SedStyle*
SedStyle::clone() const
{
  return new SedStyle(*this);
}


/*
 * Destructor for SedStyle.
 */
SedStyle::~SedStyle()
{
  delete mLineStyle;
  mLineStyle = NULL;
  delete mMarkerStyle;
  mMarkerStyle = NULL;
  delete mFillStyle;
  mFillStyle = NULL;
}


/*
 * Returns the value of the "baseStyle" attribute of this SedStyle.
 */
const std::string&
SedStyle::getBaseStyle() const
{
  return mBaseStyle;
}


/*
 * Predicate returning @c true if this SedStyle's "baseStyle" attribute is set.
 */
bool
SedStyle::isSetBaseStyle() const
{
  return (mBaseStyle.empty() == false);
}


/*
 * Sets the value of the "baseStyle" attribute of this SedStyle.
 */
int
SedStyle::setBaseStyle(const std::string& baseStyle)
{
  if (!(SyntaxChecker::isValidInternalSId(baseStyle)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mBaseStyle = baseStyle;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "baseStyle" attribute of this SedStyle.
 */
int
SedStyle::unsetBaseStyle()
{
  mBaseStyle.erase();

  if (mBaseStyle.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "line" element of this SedStyle.
 */
const SedLine*
SedStyle::getLineStyle() const
{
  return mLineStyle;
}


/*
 * Returns the value of the "line" element of this SedStyle.
 */
SedLine*
SedStyle::getLineStyle()
{
  return mLineStyle;
}


/*
 * Returns the value of the "marker" element of this SedStyle.
 */
const SedMarker*
SedStyle::getMarkerStyle() const
{
  return mMarkerStyle;
}


/*
 * Returns the value of the "marker" element of this SedStyle.
 */
SedMarker*
SedStyle::getMarkerStyle()
{
  return mMarkerStyle;
}


/*
 * Returns the value of the "fill" element of this SedStyle.
 */
const SedFill*
SedStyle::getFillStyle() const
{
  return mFillStyle;
}


/*
 * Returns the value of the "fill" element of this SedStyle.
 */
SedFill*
SedStyle::getFillStyle()
{
  return mFillStyle;
}


/*
 * Predicate returning @c true if this SedStyle's "line" element is set.
 */
bool
SedStyle::isSetLineStyle() const
{
  return (mLineStyle != NULL);
}


/*
 * Predicate returning @c true if this SedStyle's "marker" element is set.
 */
bool
SedStyle::isSetMarkerStyle() const
{
  return (mMarkerStyle != NULL);
}


/*
 * Predicate returning @c true if this SedStyle's "fill" element is set.
 */
bool
SedStyle::isSetFillStyle() const
{
  return (mFillStyle != NULL);
}


/*
 * Sets the value of the "line" element of this SedStyle.
 */
int
SedStyle::setLineStyle(const SedLine* lineStyle)
{
  if (mLineStyle == lineStyle)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (lineStyle == NULL)
  {
    delete mLineStyle;
    mLineStyle = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mLineStyle;
    mLineStyle = (lineStyle != NULL) ? lineStyle->clone() : NULL;
    if (mLineStyle != NULL)
    {
      mLineStyle->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "marker" element of this SedStyle.
 */
int
SedStyle::setMarkerStyle(const SedMarker* markerStyle)
{
  if (mMarkerStyle == markerStyle)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (markerStyle == NULL)
  {
    delete mMarkerStyle;
    mMarkerStyle = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mMarkerStyle;
    mMarkerStyle = (markerStyle != NULL) ? markerStyle->clone() : NULL;
    if (mMarkerStyle != NULL)
    {
      mMarkerStyle->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "fill" element of this SedStyle.
 */
int
SedStyle::setFillStyle(const SedFill* fillStyle)
{
  if (mFillStyle == fillStyle)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (fillStyle == NULL)
  {
    delete mFillStyle;
    mFillStyle = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mFillStyle;
    mFillStyle = (fillStyle != NULL) ? fillStyle->clone() : NULL;
    if (mFillStyle != NULL)
    {
      mFillStyle->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedLine object, adds it to this SedStyle object and returns
 * the SedLine object created.
 */
SedLine*
SedStyle::createLineStyle()
{
  if (mLineStyle != NULL)
  {
    delete mLineStyle;
  }

  mLineStyle = new SedLine(getSedNamespaces());


  connectToChild();

  return mLineStyle;
}


/*
 * Creates a new SedMarker object, adds it to this SedStyle object and returns
 * the SedMarker object created.
 */
SedMarker*
SedStyle::createMarkerStyle()
{
  if (mMarkerStyle != NULL)
  {
    delete mMarkerStyle;
  }

  mMarkerStyle = new SedMarker(getSedNamespaces());


  connectToChild();

  return mMarkerStyle;
}


/*
 * Creates a new SedFill object, adds it to this SedStyle object and returns
 * the SedFill object created.
 */
SedFill*
SedStyle::createFillStyle()
{
  if (mFillStyle != NULL)
  {
    delete mFillStyle;
  }

  mFillStyle = new SedFill(getSedNamespaces());


  connectToChild();

  return mFillStyle;
}


/*
 * Unsets the value of the "line" element of this SedStyle.
 */
int
SedStyle::unsetLineStyle()
{
  delete mLineStyle;
  mLineStyle = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "marker" element of this SedStyle.
 */
int
SedStyle::unsetMarkerStyle()
{
  delete mMarkerStyle;
  mMarkerStyle = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "fill" element of this SedStyle.
 */
int
SedStyle::unsetFillStyle()
{
  delete mFillStyle;
  mFillStyle = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedStyle::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetBaseStyle() && mBaseStyle == oldid)
  {
    setBaseStyle(newid);
  }
}


/*
 * Returns the XML element name of this SedStyle object.
 */
const std::string&
SedStyle::getElementName() const
{
  static const string name = "style";
  return name;
}


/*
 * Returns the libSEDML type code for this SedStyle object.
 */
int
SedStyle::getTypeCode() const
{
  return SEDML_STYLE;
}


/*
 * Predicate returning @c true if all the required attributes for this SedStyle
 * object have been set.
 */
bool
SedStyle::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
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
SedStyle::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (isSetLineStyle() == true)
  {
    mLineStyle->write(stream);
  }

  if (isSetMarkerStyle() == true)
  {
    mMarkerStyle->write(stream);
  }

  if (isSetFillStyle() == true)
  {
    mFillStyle->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedStyle::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedStyle::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  if (mLineStyle != NULL)
  {
    mLineStyle->setSedDocument(d);
  }

  if (mMarkerStyle != NULL)
  {
    mMarkerStyle->setSedDocument(d);
  }

  if (mFillStyle != NULL)
  {
    mFillStyle->setSedDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedStyle::connectToChild()
{
  SedBase::connectToChild();

  if (mLineStyle != NULL)
  {
    mLineStyle->connectToParent(this);
  }

  if (mMarkerStyle != NULL)
  {
    mMarkerStyle->connectToParent(this);
  }

  if (mFillStyle != NULL)
  {
    mFillStyle->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "baseStyle")
  {
    value = getBaseStyle();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedStyle's attribute "attributeName" is
 * set.
 */
bool
SedStyle::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "baseStyle")
  {
    value = isSetBaseStyle();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "baseStyle")
  {
    return_value = setBaseStyle(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedStyle.
 */
int
SedStyle::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "baseStyle")
  {
    value = unsetBaseStyle();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedStyle.
 */
SedBase*
SedStyle::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "line")
  {
    return createLineStyle();
  }
  else if (elementName == "marker")
  {
    return createMarkerStyle();
  }
  else if (elementName == "fill")
  {
    return createFillStyle();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedStyle.
 */
int
SedStyle::addChildObject(const std::string& elementName,
                         const SedBase* element)
{
  if (elementName == "line" && element->getTypeCode() == SEDML_LINE)
  {
    return setLineStyle((const SedLine*)(element));
  }
  else if (elementName == "marker" && element->getTypeCode() == SEDML_MARKER)
  {
    return setMarkerStyle((const SedMarker*)(element));
  }
  else if (elementName == "fill" && element->getTypeCode() == SEDML_FILL)
  {
    return setFillStyle((const SedFill*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedStyle.
 */
SedBase*
SedStyle::removeChildObject(const std::string& elementName,
                            const std::string& id)
{
  if (elementName == "line")
  {
    SedLine * obj = mLineStyle;
    mLineStyle = NULL; return obj;
  }
  else if (elementName == "marker")
  {
    SedMarker * obj = mMarkerStyle;
    mMarkerStyle = NULL; return obj;
  }
  else if (elementName == "fill")
  {
    SedFill * obj = mFillStyle;
    mFillStyle = NULL; return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedStyle.
 */
unsigned int
SedStyle::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "line")
  {
    if (isSetLineStyle())
    {
      return 1;
    }
  }
  else if (elementName == "marker")
  {
    if (isSetMarkerStyle())
    {
      return 1;
    }
  }
  else if (elementName == "fill")
  {
    if (isSetFillStyle())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedStyle.
 */
SedBase*
SedStyle::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "line")
  {
    return getLineStyle();
  }
  else if (elementName == "marker")
  {
    return getMarkerStyle();
  }
  else if (elementName == "fill")
  {
    return getFillStyle();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedStyle::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mLineStyle != NULL)
  {
    if (mLineStyle->getId() == id)
    {
      return mLineStyle;
    }

    obj = mLineStyle->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mMarkerStyle != NULL)
  {
    if (mMarkerStyle->getId() == id)
    {
      return mMarkerStyle;
    }

    obj = mMarkerStyle->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mFillStyle != NULL)
  {
    if (mFillStyle->getId() == id)
    {
      return mFillStyle;
    }

    obj = mFillStyle->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns a List of all child SedBase objects, including those nested to an
 * arbitrary depth.
 */
List*
SedStyle::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  SED_ADD_FILTERED_POINTER(ret, sublist, mLineStyle, filter);
  SED_ADD_FILTERED_POINTER(ret, sublist, mMarkerStyle, filter);
  SED_ADD_FILTERED_POINTER(ret, sublist, mFillStyle, filter);


  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedStyle::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "line")
  {
    if (getErrorLog() && isSetLineStyle())
    {
      getErrorLog()->logError(SedmlStyleAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mLineStyle;
    mLineStyle = new SedLine(getSedNamespaces());

    obj = mLineStyle;
  }
  else if (name == "marker")
  {
    if (getErrorLog() && isSetMarkerStyle())
    {
      getErrorLog()->logError(SedmlStyleAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mMarkerStyle;
    mMarkerStyle = new SedMarker(getSedNamespaces());

    obj = mMarkerStyle;
  }
  else if (name == "fill")
  {
    if (getErrorLog() && isSetFillStyle())
    {
      getErrorLog()->logError(SedmlStyleAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mFillStyle;
    mFillStyle = new SedFill(getSedNamespaces());

    obj = mFillStyle;
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
SedStyle::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("baseStyle");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedStyle::readAttributes(
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
    static_cast<SedListOfStyles*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDocumentLOStylesAllowedCoreAttributes, level,
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
        log->logError(SedmlStyleAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  if(!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedStyle> element.";
      log->logError(SedmlStyleAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // baseStyle SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("baseStyle", mBaseStyle);

  if (assigned == true)
  {
    if (mBaseStyle.empty() == true)
    {
      logEmptyString(mBaseStyle, level, version, "<SedStyle>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mBaseStyle) == false)
    {
      std::string msg = "The baseStyle attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mBaseStyle + "', which does not conform to the syntax.";
      logError(SedmlStyleBaseStyleMustBeStyle, level, version, msg, getLine(),
        getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedStyle::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetBaseStyle() == true)
  {
    stream.writeAttribute("baseStyle", getPrefix(), mBaseStyle);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedStyle_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedStyle_t *
SedStyle_create(unsigned int level, unsigned int version)
{
  return new SedStyle(level, version);
}


/*
 * Creates and returns a deep copy of this SedStyle_t object.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedStyle_clone(const SedStyle_t* ss)
{
  if (ss != NULL)
  {
    return static_cast<SedStyle_t*>(ss->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedStyle_t object.
 */
LIBSEDML_EXTERN
void
SedStyle_free(SedStyle_t* ss)
{
  if (ss != NULL)
  {
    delete ss;
  }
}


/*
 * Returns the value of the "id" attribute of this SedStyle_t.
 */
LIBSEDML_EXTERN
char *
SedStyle_getId(const SedStyle_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getId().empty() ? NULL : safe_strdup(ss->getId().c_str());
}


/*
 * Returns the value of the "baseStyle" attribute of this SedStyle_t.
 */
LIBSEDML_EXTERN
char *
SedStyle_getBaseStyle(const SedStyle_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getBaseStyle().empty() ? NULL :
    safe_strdup(ss->getBaseStyle().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedStyle_t's "id" attribute is set.
 */
LIBSEDML_EXTERN
int
SedStyle_isSetId(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedStyle_t's "baseStyle" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedStyle_isSetBaseStyle(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetBaseStyle()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_setId(SedStyle_t * ss, const char * id)
{
  return (ss != NULL) ? ss->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "baseStyle" attribute of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_setBaseStyle(SedStyle_t * ss, const char * baseStyle)
{
  return (ss != NULL) ? ss->setBaseStyle(baseStyle) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_unsetId(SedStyle_t * ss)
{
  return (ss != NULL) ? ss->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "baseStyle" attribute of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_unsetBaseStyle(SedStyle_t * ss)
{
  return (ss != NULL) ? ss->unsetBaseStyle() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "line" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
const SedLine_t*
SedStyle_getLineStyle(const SedStyle_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedLine_t*)(ss->getLineStyle());
}


/*
 * Returns the value of the "marker" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
const SedMarker_t*
SedStyle_getMarkerStyle(const SedStyle_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedMarker_t*)(ss->getMarkerStyle());
}


/*
 * Returns the value of the "fill" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
const SedFill_t*
SedStyle_getFillStyle(const SedStyle_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedFill_t*)(ss->getFillStyle());
}


/*
 * Predicate returning @c 1 (true) if this SedStyle_t's "line" element is set.
 */
LIBSEDML_EXTERN
int
SedStyle_isSetLineStyle(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetLineStyle()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedStyle_t's "marker" element is
 * set.
 */
LIBSEDML_EXTERN
int
SedStyle_isSetMarkerStyle(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetMarkerStyle()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedStyle_t's "fill" element is set.
 */
LIBSEDML_EXTERN
int
SedStyle_isSetFillStyle(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetFillStyle()) : 0;
}


/*
 * Sets the value of the "line" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_setLineStyle(SedStyle_t * ss, const SedLine_t* lineStyle)
{
  return (ss != NULL) ? ss->setLineStyle(lineStyle) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "marker" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_setMarkerStyle(SedStyle_t * ss, const SedMarker_t* markerStyle)
{
  return (ss != NULL) ? ss->setMarkerStyle(markerStyle) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "fill" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_setFillStyle(SedStyle_t * ss, const SedFill_t* fillStyle)
{
  return (ss != NULL) ? ss->setFillStyle(fillStyle) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedLine_t object, adds it to this SedStyle_t object and
 * returns the SedLine_t object created.
 */
LIBSEDML_EXTERN
SedLine_t*
SedStyle_createLineStyle(SedStyle_t* ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedLine_t*)(ss->createLineStyle());
}


/*
 * Creates a new SedMarker_t object, adds it to this SedStyle_t object and
 * returns the SedMarker_t object created.
 */
LIBSEDML_EXTERN
SedMarker_t*
SedStyle_createMarkerStyle(SedStyle_t* ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedMarker_t*)(ss->createMarkerStyle());
}


/*
 * Creates a new SedFill_t object, adds it to this SedStyle_t object and
 * returns the SedFill_t object created.
 */
LIBSEDML_EXTERN
SedFill_t*
SedStyle_createFillStyle(SedStyle_t* ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedFill_t*)(ss->createFillStyle());
}


/*
 * Unsets the value of the "line" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_unsetLineStyle(SedStyle_t * ss)
{
  return (ss != NULL) ? ss->unsetLineStyle() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "marker" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_unsetMarkerStyle(SedStyle_t * ss)
{
  return (ss != NULL) ? ss->unsetMarkerStyle() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "fill" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_unsetFillStyle(SedStyle_t * ss)
{
  return (ss != NULL) ? ss->unsetFillStyle() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedStyle_t object have been set.
 */
LIBSEDML_EXTERN
int
SedStyle_hasRequiredAttributes(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


