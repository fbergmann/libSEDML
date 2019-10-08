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
 * Creates a new SedStyle using the given SEDML Level and @ p version values.
 */
SedStyle::SedStyle(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mBaseStyle ("")
  , mLine (NULL)
  , mMarker (NULL)
  , mFill (NULL)
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
  , mLine (NULL)
  , mMarker (NULL)
  , mFill (NULL)
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
  , mLine ( NULL )
  , mMarker ( NULL )
  , mFill ( NULL )
{
  if (orig.mLine != NULL)
  {
    mLine = orig.mLine->clone();
  }

  if (orig.mMarker != NULL)
  {
    mMarker = orig.mMarker->clone();
  }

  if (orig.mFill != NULL)
  {
    mFill = orig.mFill->clone();
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
    delete mLine;
    if (rhs.mLine != NULL)
    {
      mLine = rhs.mLine->clone();
    }
    else
    {
      mLine = NULL;
    }

    delete mMarker;
    if (rhs.mMarker != NULL)
    {
      mMarker = rhs.mMarker->clone();
    }
    else
    {
      mMarker = NULL;
    }

    delete mFill;
    if (rhs.mFill != NULL)
    {
      mFill = rhs.mFill->clone();
    }
    else
    {
      mFill = NULL;
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
  delete mLine;
  mLine = NULL;
  delete mMarker;
  mMarker = NULL;
  delete mFill;
  mFill = NULL;
}


/*
 * Returns the value of the "id" attribute of this SedStyle.
 */
const std::string&
SedStyle::getId() const
{
  return mId;
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
 * Predicate returning @c true if this SedStyle's "id" attribute is set.
 */
bool
SedStyle::isSetId() const
{
  return (mId.empty() == false);
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
 * Sets the value of the "id" attribute of this SedStyle.
 */
int
SedStyle::setId(const std::string& id)
{
  mId = id;
  return LIBSEDML_OPERATION_SUCCESS;
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
 * Unsets the value of the "id" attribute of this SedStyle.
 */
int
SedStyle::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
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
  return mLine;
}


/*
 * Returns the value of the "line" element of this SedStyle.
 */
SedLine*
SedStyle::getLineStyle()
{
  return mLine;
}


/*
 * Returns the value of the "marker" element of this SedStyle.
 */
const SedMarker*
SedStyle::getMarker() const
{
  return mMarker;
}


/*
 * Returns the value of the "marker" element of this SedStyle.
 */
SedMarker*
SedStyle::getMarker()
{
  return mMarker;
}


/*
 * Returns the value of the "fill" element of this SedStyle.
 */
const SedFill*
SedStyle::getFill() const
{
  return mFill;
}


/*
 * Returns the value of the "fill" element of this SedStyle.
 */
SedFill*
SedStyle::getFill()
{
  return mFill;
}


/*
 * Predicate returning @c true if this SedStyle's "line" element is set.
 */
bool
SedStyle::isSetLineStyle() const
{
  return (mLine != NULL);
}


/*
 * Predicate returning @c true if this SedStyle's "marker" element is set.
 */
bool
SedStyle::isSetMarker() const
{
  return (mMarker != NULL);
}


/*
 * Predicate returning @c true if this SedStyle's "fill" element is set.
 */
bool
SedStyle::isSetFill() const
{
  return (mFill != NULL);
}


/*
 * Sets the value of the "line" element of this SedStyle.
 */
int
SedStyle::setLineStyle(const SedLine* line)
{
  if (mLine == line)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (line == NULL)
  {
    delete mLine;
    mLine = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mLine;
    mLine = (line != NULL) ? line->clone() : NULL;
    if (mLine != NULL)
    {
      mLine->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "marker" element of this SedStyle.
 */
int
SedStyle::setMarker(const SedMarker* marker)
{
  if (mMarker == marker)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (marker == NULL)
  {
    delete mMarker;
    mMarker = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mMarker;
    mMarker = (marker != NULL) ? marker->clone() : NULL;
    if (mMarker != NULL)
    {
      mMarker->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "fill" element of this SedStyle.
 */
int
SedStyle::setFill(const SedFill* fill)
{
  if (mFill == fill)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (fill == NULL)
  {
    delete mFill;
    mFill = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mFill;
    mFill = (fill != NULL) ? fill->clone() : NULL;
    if (mFill != NULL)
    {
      mFill->connectToParent(this);
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
  if (mLine != NULL)
  {
    delete mLine;
  }

  mLine = new SedLine(getSedNamespaces());

  connectToChild();

  return mLine;
}


/*
 * Creates a new SedMarker object, adds it to this SedStyle object and returns
 * the SedMarker object created.
 */
SedMarker*
SedStyle::createMarker()
{
  if (mMarker != NULL)
  {
    delete mMarker;
  }

  mMarker = new SedMarker(getSedNamespaces());

  connectToChild();

  return mMarker;
}


/*
 * Creates a new SedFill object, adds it to this SedStyle object and returns
 * the SedFill object created.
 */
SedFill*
SedStyle::createFill()
{
  if (mFill != NULL)
  {
    delete mFill;
  }

  mFill = new SedFill(getSedNamespaces());

  connectToChild();

  return mFill;
}


/*
 * Unsets the value of the "line" element of this SedStyle.
 */
int
SedStyle::unsetLineStyle()
{
  delete mLine;
  mLine = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "marker" element of this SedStyle.
 */
int
SedStyle::unsetMarker()
{
  delete mMarker;
  mMarker = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "fill" element of this SedStyle.
 */
int
SedStyle::unsetFill()
{
  delete mFill;
  mFill = NULL;
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
    mLine->write(stream);
  }

  if (isSetMarker() == true)
  {
    mMarker->write(stream);
  }

  if (isSetFill() == true)
  {
    mFill->write(stream);
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

  if (mLine != NULL)
  {
    mLine->setSedDocument(d);
  }

  if (mMarker != NULL)
  {
    mMarker->setSedDocument(d);
  }

  if (mFill != NULL)
  {
    mFill->setSedDocument(d);
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

  if (mLine != NULL)
  {
    mLine->connectToParent(this);
  }

  if (mMarker != NULL)
  {
    mMarker->connectToParent(this);
  }

  if (mFill != NULL)
  {
    mFill->connectToParent(this);
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
    return createMarker();
  }
  else if (elementName == "fill")
  {
    return createFill();
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
    return setMarker((const SedMarker*)(element));
  }
  else if (elementName == "fill" && element->getTypeCode() == SEDML_FILL)
  {
    return setFill((const SedFill*)(element));
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
    SedLine * obj = getLineStyle();
    if (unsetLineStyle() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "marker")
  {
    SedMarker * obj = getMarker();
    if (unsetMarker() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "fill")
  {
    SedFill * obj = getFill();
    if (unsetFill() == LIBSBML_OPERATION_SUCCESS) return obj;
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
    if (isSetMarker())
    {
      return 1;
    }
  }
  else if (elementName == "fill")
  {
    if (isSetFill())
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
    return getMarker();
  }
  else if (elementName == "fill")
  {
    return getFill();
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

  if (mLine != NULL)
  {
    if (mLine->getId() == id)
    {
      return mLine;
    }

    obj = mLine->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mMarker != NULL)
  {
    if (mMarker->getId() == id)
    {
      return mMarker;
    }

    obj = mMarker->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mFill != NULL)
  {
    if (mFill->getId() == id)
    {
      return mFill;
    }

    obj = mFill->getElementBySId(id);
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

    delete mLine;
    mLine = new SedLine(getSedNamespaces());
    obj = mLine;
  }
  else if (name == "marker")
  {
    if (getErrorLog() && isSetMarker())
    {
      getErrorLog()->logError(SedmlStyleAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mMarker;
    mMarker = new SedMarker(getSedNamespaces());
    obj = mMarker;
  }
  else if (name == "fill")
  {
    if (getErrorLog() && isSetFill())
    {
      getErrorLog()->logError(SedmlStyleAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mFill;
    mFill = new SedFill(getSedNamespaces());
    obj = mFill;
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

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<SedStyle>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SedmlIdSyntaxRule, level, version, "The id on the <" +
        getElementName() + "> is '" + mId + "', which does not conform to the "
          "syntax.");
    }
  }
  else
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
      logError(SedmlStyleBaseStyleMustBeStyle, level, version, msg);
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

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetBaseStyle() == true)
  {
    stream.writeAttribute("baseStyle", getPrefix(), mBaseStyle);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedStyle_t using the given SEDML Level and @ p version values.
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
SedStyle_getLine(const SedStyle_t * ss)
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
SedStyle_getMarker(const SedStyle_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedMarker_t*)(ss->getMarker());
}


/*
 * Returns the value of the "fill" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
const SedFill_t*
SedStyle_getFill(const SedStyle_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedFill_t*)(ss->getFill());
}


/*
 * Predicate returning @c 1 (true) if this SedStyle_t's "line" element is set.
 */
LIBSEDML_EXTERN
int
SedStyle_isSetLine(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetLineStyle()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedStyle_t's "marker" element is
 * set.
 */
LIBSEDML_EXTERN
int
SedStyle_isSetMarker(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetMarker()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedStyle_t's "fill" element is set.
 */
LIBSEDML_EXTERN
int
SedStyle_isSetFill(const SedStyle_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetFill()) : 0;
}


/*
 * Sets the value of the "line" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_setLine(SedStyle_t * ss, const SedLine_t* line)
{
  return (ss != NULL) ? ss->setLineStyle(line) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "marker" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_setMarker(SedStyle_t * ss, const SedMarker_t* marker)
{
  return (ss != NULL) ? ss->setMarker(marker) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "fill" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_setFill(SedStyle_t * ss, const SedFill_t* fill)
{
  return (ss != NULL) ? ss->setFill(fill) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedLine_t object, adds it to this SedStyle_t object and
 * returns the SedLine_t object created.
 */
LIBSEDML_EXTERN
SedLine_t*
SedStyle_createLine(SedStyle_t* ss)
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
SedStyle_createMarker(SedStyle_t* ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedMarker_t*)(ss->createMarker());
}


/*
 * Creates a new SedFill_t object, adds it to this SedStyle_t object and
 * returns the SedFill_t object created.
 */
LIBSEDML_EXTERN
SedFill_t*
SedStyle_createFill(SedStyle_t* ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedFill_t*)(ss->createFill());
}


/*
 * Unsets the value of the "line" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_unsetLine(SedStyle_t * ss)
{
  return (ss != NULL) ? ss->unsetLineStyle() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "marker" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_unsetMarker(SedStyle_t * ss)
{
  return (ss != NULL) ? ss->unsetMarker() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "fill" element of this SedStyle_t.
 */
LIBSEDML_EXTERN
int
SedStyle_unsetFill(SedStyle_t * ss)
{
  return (ss != NULL) ? ss->unsetFill() : LIBSEDML_INVALID_OBJECT;
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


