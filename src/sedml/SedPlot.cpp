/**
 * @file SedPlot.cpp
 * @brief Implementation of the SedPlot class.
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
#include <sedml/SedPlot.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedPlot using the given SED-ML Level and @ p version values.
 */
SedPlot::SedPlot(unsigned int level, unsigned int version)
  : SedOutput(level, version)
  , mLegend (false)
  , mIsSetLegend (false)
  , mHeight (util_NaN())
  , mIsSetHeight (false)
  , mWidth (util_NaN())
  , mIsSetWidth (false)
  , mXAxis (NULL)
  , mYAxis (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedPlot using the given SedNamespaces object @p sedmlns.
 */
SedPlot::SedPlot(SedNamespaces *sedmlns)
  : SedOutput(sedmlns)
  , mLegend (false)
  , mIsSetLegend (false)
  , mHeight (util_NaN())
  , mIsSetHeight (false)
  , mWidth (util_NaN())
  , mIsSetWidth (false)
  , mXAxis (NULL)
  , mYAxis (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedPlot.
 */
SedPlot::SedPlot(const SedPlot& orig)
  : SedOutput( orig )
  , mLegend ( orig.mLegend )
  , mIsSetLegend ( orig.mIsSetLegend )
  , mHeight ( orig.mHeight )
  , mIsSetHeight ( orig.mIsSetHeight )
  , mWidth ( orig.mWidth )
  , mIsSetWidth ( orig.mIsSetWidth )
  , mXAxis ( NULL )
  , mYAxis ( NULL )
{
  if (orig.mXAxis != NULL)
  {
    mXAxis = orig.mXAxis->clone();
  }

  if (orig.mYAxis != NULL)
  {
    mYAxis = orig.mYAxis->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedPlot.
 */
SedPlot&
SedPlot::operator=(const SedPlot& rhs)
{
  if (&rhs != this)
  {
    SedOutput::operator=(rhs);
    mLegend = rhs.mLegend;
    mIsSetLegend = rhs.mIsSetLegend;
    mHeight = rhs.mHeight;
    mIsSetHeight = rhs.mIsSetHeight;
    mWidth = rhs.mWidth;
    mIsSetWidth = rhs.mIsSetWidth;
    delete mXAxis;
    if (rhs.mXAxis != NULL)
    {
      mXAxis = rhs.mXAxis->clone();
    }
    else
    {
      mXAxis = NULL;
    }

    delete mYAxis;
    if (rhs.mYAxis != NULL)
    {
      mYAxis = rhs.mYAxis->clone();
    }
    else
    {
      mYAxis = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedPlot object.
 */
SedPlot*
SedPlot::clone() const
{
  return new SedPlot(*this);
}


/*
 * Destructor for SedPlot.
 */
SedPlot::~SedPlot()
{
  delete mXAxis;
  mXAxis = NULL;
  delete mYAxis;
  mYAxis = NULL;
}


/*
 * Returns the value of the "legend" attribute of this SedPlot.
 */
bool
SedPlot::getLegend() const
{
  return mLegend;
}


/*
 * Returns the value of the "height" attribute of this SedPlot.
 */
double
SedPlot::getHeight() const
{
  return mHeight;
}


/*
 * Returns the value of the "width" attribute of this SedPlot.
 */
double
SedPlot::getWidth() const
{
  return mWidth;
}


/*
 * Predicate returning @c true if this SedPlot's "legend" attribute is set.
 */
bool
SedPlot::isSetLegend() const
{
  return mIsSetLegend;
}


/*
 * Predicate returning @c true if this SedPlot's "height" attribute is set.
 */
bool
SedPlot::isSetHeight() const
{
  return mIsSetHeight;
}


/*
 * Predicate returning @c true if this SedPlot's "width" attribute is set.
 */
bool
SedPlot::isSetWidth() const
{
  return mIsSetWidth;
}


/*
 * Sets the value of the "legend" attribute of this SedPlot.
 */
int
SedPlot::setLegend(bool legend)
{
  mLegend = legend;
  mIsSetLegend = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "height" attribute of this SedPlot.
 */
int
SedPlot::setHeight(double height)
{
  mHeight = height;
  mIsSetHeight = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "width" attribute of this SedPlot.
 */
int
SedPlot::setWidth(double width)
{
  mWidth = width;
  mIsSetWidth = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "legend" attribute of this SedPlot.
 */
int
SedPlot::unsetLegend()
{
  mLegend = false;
  mIsSetLegend = false;

  if (isSetLegend() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "height" attribute of this SedPlot.
 */
int
SedPlot::unsetHeight()
{
  mHeight = util_NaN();
  mIsSetHeight = false;

  if (isSetHeight() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "width" attribute of this SedPlot.
 */
int
SedPlot::unsetWidth()
{
  mWidth = util_NaN();
  mIsSetWidth = false;

  if (isSetWidth() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "xAxis" element of this SedPlot.
 */
const SedAxis*
SedPlot::getXAxis() const
{
  return mXAxis;
}


/*
 * Returns the value of the "xAxis" element of this SedPlot.
 */
SedAxis*
SedPlot::getXAxis()
{
  return mXAxis;
}


/*
 * Returns the value of the "yAxis" element of this SedPlot.
 */
const SedAxis*
SedPlot::getYAxis() const
{
  return mYAxis;
}


/*
 * Returns the value of the "yAxis" element of this SedPlot.
 */
SedAxis*
SedPlot::getYAxis()
{
  return mYAxis;
}


/*
 * Predicate returning @c true if this SedPlot's "xAxis" element is set.
 */
bool
SedPlot::isSetXAxis() const
{
  return (mXAxis != NULL);
}


/*
 * Predicate returning @c true if this SedPlot's "yAxis" element is set.
 */
bool
SedPlot::isSetYAxis() const
{
  return (mYAxis != NULL);
}


/*
 * Sets the value of the "xAxis" element of this SedPlot.
 */
int
SedPlot::setXAxis(const SedAxis* xAxis)
{
  if (mXAxis == xAxis)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (xAxis == NULL)
  {
    delete mXAxis;
    mXAxis = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mXAxis;
    mXAxis = (xAxis != NULL) ? xAxis->clone() : NULL;
    if (mXAxis != NULL)
    {
      mXAxis->setElementName("xAxis");
      mXAxis->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "yAxis" element of this SedPlot.
 */
int
SedPlot::setYAxis(const SedAxis* yAxis)
{
  if (mYAxis == yAxis)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (yAxis == NULL)
  {
    delete mYAxis;
    mYAxis = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mYAxis;
    mYAxis = (yAxis != NULL) ? yAxis->clone() : NULL;
    if (mYAxis != NULL)
    {
      mYAxis->setElementName("yAxis");
      mYAxis->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedAxis object, adds it to this SedPlot object and returns the
 * SedAxis object created.
 */
SedAxis*
SedPlot::createXAxis()
{
  if (mXAxis != NULL)
  {
    delete mXAxis;
  }

  mXAxis = new SedAxis(getSedNamespaces());

  mXAxis->setElementName("xAxis");

  connectToChild();

  return mXAxis;
}


/*
 * Creates a new SedAxis object, adds it to this SedPlot object and returns the
 * SedAxis object created.
 */
SedAxis*
SedPlot::createYAxis()
{
  if (mYAxis != NULL)
  {
    delete mYAxis;
  }

  mYAxis = new SedAxis(getSedNamespaces());

  mYAxis->setElementName("yAxis");

  connectToChild();

  return mYAxis;
}


/*
 * Unsets the value of the "xAxis" element of this SedPlot.
 */
int
SedPlot::unsetXAxis()
{
  delete mXAxis;
  mXAxis = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "yAxis" element of this SedPlot.
 */
int
SedPlot::unsetYAxis()
{
  delete mYAxis;
  mYAxis = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this SedPlot object.
 */
const std::string&
SedPlot::getElementName() const
{
  static const string name = "plot";
  return name;
}


/*
 * Returns the libSEDML type code for this SedPlot object.
 */
int
SedPlot::getTypeCode() const
{
  return SEDML_OUTPUT_PLOT;
}


/*
 * Predicate returning @c true if all the required attributes for this SedPlot
 * object have been set.
 */
bool
SedPlot::hasRequiredAttributes() const
{
  bool allPresent = SedOutput::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SedPlot
 * object have been set.
 */
bool
SedPlot::hasRequiredElements() const
{
  bool allPresent = SedOutput::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedPlot::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SedOutput::writeElements(stream);

  if (isSetXAxis() == true)
  {
    mXAxis->write(stream);
  }

  if (isSetYAxis() == true)
  {
    mYAxis->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedPlot::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedPlot::setSedDocument(SedDocument* d)
{
  SedOutput::setSedDocument(d);

  if (mXAxis != NULL)
  {
    mXAxis->setSedDocument(d);
  }

  if (mYAxis != NULL)
  {
    mYAxis->setSedDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedPlot::connectToChild()
{
  SedOutput::connectToChild();

  if (mXAxis != NULL)
  {
    mXAxis->connectToParent(this);
  }

  if (mYAxis != NULL)
  {
    mYAxis->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "legend")
  {
    value = getLegend();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "height")
  {
    value = getHeight();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "width")
  {
    value = getWidth();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::getAttribute(const std::string& attributeName,
                      unsigned int& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::getAttribute(const std::string& attributeName,
                      std::string& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedPlot's attribute "attributeName" is
 * set.
 */
bool
SedPlot::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedOutput::isSetAttribute(attributeName);

  if (attributeName == "legend")
  {
    value = isSetLegend();
  }
  else if (attributeName == "height")
  {
    value = isSetHeight();
  }
  else if (attributeName == "width")
  {
    value = isSetWidth();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  if (attributeName == "legend")
  {
    return_value = setLegend(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  if (attributeName == "height")
  {
    return_value = setHeight(value);
  }
  else if (attributeName == "width")
  {
    return_value = setWidth(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::setAttribute(const std::string& attributeName,
                      const std::string& value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedPlot.
 */
int
SedPlot::unsetAttribute(const std::string& attributeName)
{
  int value = SedOutput::unsetAttribute(attributeName);

  if (attributeName == "legend")
  {
    value = unsetLegend();
  }
  else if (attributeName == "height")
  {
    value = unsetHeight();
  }
  else if (attributeName == "width")
  {
    value = unsetWidth();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedPlot.
 */
SedBase*
SedPlot::createChildObject(const std::string& elementName)
{
  SedOutput* obj = NULL;

  if (elementName == "xAxis")
  {
    return createXAxis();
  }
  else if (elementName == "yAxis")
  {
    return createYAxis();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedPlot.
 */
int
SedPlot::addChildObject(const std::string& elementName,
                        const SedBase* element)
{
  if (elementName == "xAxis" && element->getTypeCode() == SEDML_AXIS)
  {
    return setXAxis((const SedAxis*)(element));
  }
  else if (elementName == "yAxis" && element->getTypeCode() == SEDML_AXIS)
  {
    return setYAxis((const SedAxis*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedPlot.
 */
SedBase*
SedPlot::removeChildObject(const std::string& elementName,
                           const std::string& id)
{
  if (elementName == "xAxis")
  {
    SedAxis * obj = mXAxis;
    mXAxis = NULL; return obj;
  }
  else if (elementName == "yAxis")
  {
    SedAxis * obj = mYAxis;
    mYAxis = NULL; return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedPlot.
 */
unsigned int
SedPlot::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "xAxis")
  {
    if (isSetXAxis())
    {
      return 1;
    }
  }
  else if (elementName == "yAxis")
  {
    if (isSetYAxis())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedPlot.
 */
SedBase*
SedPlot::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "xAxis")
  {
    return getXAxis();
  }
  else if (elementName == "yAxis")
  {
    return getYAxis();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedPlot::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mXAxis != NULL)
  {
    if (mXAxis->getId() == id)
    {
      return mXAxis;
    }

    obj = mXAxis->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mYAxis != NULL)
  {
    if (mYAxis->getId() == id)
    {
      return mYAxis;
    }

    obj = mYAxis->getElementBySId(id);
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
SedPlot::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  SED_ADD_FILTERED_POINTER(ret, sublist, mXAxis, filter);
  SED_ADD_FILTERED_POINTER(ret, sublist, mYAxis, filter);


  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedPlot::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = SedOutput::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "xAxis")
  {
    if (getErrorLog() && isSetXAxis())
    {
      getErrorLog()->logError(SedmlPlotAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mXAxis;
    mXAxis = new SedAxis(getSedNamespaces());
    mXAxis->setElementName(name);
    obj = mXAxis;
  }
  else if (name == "yAxis")
  {
    if (getErrorLog() && isSetYAxis())
    {
      getErrorLog()->logError(SedmlPlotAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mYAxis;
    mYAxis = new SedAxis(getSedNamespaces());
    mYAxis->setElementName(name);
    obj = mYAxis;
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
SedPlot::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedOutput::addExpectedAttributes(attributes);

  attributes.add("legend");

  attributes.add("height");

  attributes.add("width");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedPlot::readAttributes(
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
        log->logError(SedmlPlotAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // legend bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLegend = attributes.readInto("legend", mLegend);

  if (mIsSetLegend == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlPlotLegendMustBeBoolean, level, version);
    }
  }

  // 
  // height double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetHeight = attributes.readInto("height", mHeight);

  if ( mIsSetHeight == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'height' from the <SedPlot> "
        "element must be an integer.";
      log->logError(SedmlPlotHeightMustBeDouble, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // width double (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetWidth = attributes.readInto("width", mWidth);

  if ( mIsSetWidth == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'width' from the <SedPlot> element "
        "must be an integer.";
      log->logError(SedmlPlotWidthMustBeDouble, level, version, message,
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
SedPlot::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedOutput::writeAttributes(stream);

  if (isSetLegend() == true)
  {
    stream.writeAttribute("legend", getPrefix(), mLegend);
  }

  if (isSetHeight() == true)
  {
    stream.writeAttribute("height", getPrefix(), mHeight);
  }

  if (isSetWidth() == true)
  {
    stream.writeAttribute("width", getPrefix(), mWidth);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedPlot_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedPlot_t *
SedPlot_create(unsigned int level, unsigned int version)
{
  return new SedPlot(level, version);
}


/*
 * Creates and returns a deep copy of this SedPlot_t object.
 */
LIBSEDML_EXTERN
SedPlot_t*
SedPlot_clone(const SedPlot_t* sp)
{
  if (sp != NULL)
  {
    return static_cast<SedPlot_t*>(sp->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedPlot_t object.
 */
LIBSEDML_EXTERN
void
SedPlot_free(SedPlot_t* sp)
{
  if (sp != NULL)
  {
    delete sp;
  }
}


/*
 * Returns the value of the "legend" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_getLegend(const SedPlot_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->getLegend()) : 0;
}


/*
 * Returns the value of the "height" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
double
SedPlot_getHeight(const SedPlot_t * sp)
{
  return (sp != NULL) ? sp->getHeight() : util_NaN();
}


/*
 * Returns the value of the "width" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
double
SedPlot_getWidth(const SedPlot_t * sp)
{
  return (sp != NULL) ? sp->getWidth() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SedPlot_t's "legend" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedPlot_isSetLegend(const SedPlot_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetLegend()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedPlot_t's "height" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedPlot_isSetHeight(const SedPlot_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetHeight()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedPlot_t's "width" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedPlot_isSetWidth(const SedPlot_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetWidth()) : 0;
}


/*
 * Sets the value of the "legend" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_setLegend(SedPlot_t * sp, int legend)
{
  return (sp != NULL) ? sp->setLegend(legend) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "height" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_setHeight(SedPlot_t * sp, double height)
{
  return (sp != NULL) ? sp->setHeight(height) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "width" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_setWidth(SedPlot_t * sp, double width)
{
  return (sp != NULL) ? sp->setWidth(width) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "legend" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_unsetLegend(SedPlot_t * sp)
{
  return (sp != NULL) ? sp->unsetLegend() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "height" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_unsetHeight(SedPlot_t * sp)
{
  return (sp != NULL) ? sp->unsetHeight() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "width" attribute of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_unsetWidth(SedPlot_t * sp)
{
  return (sp != NULL) ? sp->unsetWidth() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "xAxis" element of this SedPlot_t.
 */
LIBSEDML_EXTERN
const SedAxis_t*
SedPlot_getXAxis(const SedPlot_t * sp)
{
  if (sp == NULL)
  {
    return NULL;
  }

  return (SedAxis_t*)(sp->getXAxis());
}


/*
 * Returns the value of the "yAxis" element of this SedPlot_t.
 */
LIBSEDML_EXTERN
const SedAxis_t*
SedPlot_getYAxis(const SedPlot_t * sp)
{
  if (sp == NULL)
  {
    return NULL;
  }

  return (SedAxis_t*)(sp->getYAxis());
}


/*
 * Predicate returning @c 1 (true) if this SedPlot_t's "xAxis" element is set.
 */
LIBSEDML_EXTERN
int
SedPlot_isSetXAxis(const SedPlot_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetXAxis()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedPlot_t's "yAxis" element is set.
 */
LIBSEDML_EXTERN
int
SedPlot_isSetYAxis(const SedPlot_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetYAxis()) : 0;
}


/*
 * Sets the value of the "xAxis" element of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_setXAxis(SedPlot_t * sp, const SedAxis_t* xAxis)
{
  return (sp != NULL) ? sp->setXAxis(xAxis) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "yAxis" element of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_setYAxis(SedPlot_t * sp, const SedAxis_t* yAxis)
{
  return (sp != NULL) ? sp->setYAxis(yAxis) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedAxis_t object, adds it to this SedPlot_t object and returns
 * the SedAxis_t object created.
 */
LIBSEDML_EXTERN
SedAxis_t*
SedPlot_createXAxis(SedPlot_t* sp)
{
  if (sp == NULL)
  {
    return NULL;
  }

  return (SedAxis_t*)(sp->createXAxis());
}


/*
 * Creates a new SedAxis_t object, adds it to this SedPlot_t object and returns
 * the SedAxis_t object created.
 */
LIBSEDML_EXTERN
SedAxis_t*
SedPlot_createYAxis(SedPlot_t* sp)
{
  if (sp == NULL)
  {
    return NULL;
  }

  return (SedAxis_t*)(sp->createYAxis());
}


/*
 * Unsets the value of the "xAxis" element of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_unsetXAxis(SedPlot_t * sp)
{
  return (sp != NULL) ? sp->unsetXAxis() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "yAxis" element of this SedPlot_t.
 */
LIBSEDML_EXTERN
int
SedPlot_unsetYAxis(SedPlot_t * sp)
{
  return (sp != NULL) ? sp->unsetYAxis() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedPlot_t object have been set.
 */
LIBSEDML_EXTERN
int
SedPlot_hasRequiredAttributes(const SedPlot_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedPlot_t object have been set.
 */
LIBSEDML_EXTERN
int
SedPlot_hasRequiredElements(const SedPlot_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


