/**
 * @file SedAbstractCurve.cpp
 * @brief Implementation of the SedAbstractCurve class.
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
#include <sedml/SedAbstractCurve.h>
#include <sedml/SedListOfCurves.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedCurve.h>
#include <sedml/SedShadedArea.h>
#include <sedml/SedPlot.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAbstractCurve using the given SED-ML Level and @ p version
 * values.
 */
SedAbstractCurve::SedAbstractCurve(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mLogX (false)
  , mIsSetLogX (false)
  , mOrder (SEDML_INT_MAX)
  , mIsSetOrder (false)
  , mStyle ("")
  , mYAxis ("")
  , mXDataReference ("")
  , mElementName("abstractCurve")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  mNameAllowedPreV4 = true;
  mIdAllowedPreV4 = true;
}


/*
 * Creates a new SedAbstractCurve using the given SedNamespaces object @p
 * sedmlns.
 */
SedAbstractCurve::SedAbstractCurve(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mLogX (false)
  , mIsSetLogX (false)
  , mOrder (SEDML_INT_MAX)
  , mIsSetOrder (false)
  , mStyle ("")
  , mYAxis ("")
  , mXDataReference ("")
  , mElementName("abstractCurve")
{
  setElementNamespace(sedmlns->getURI());
  mNameAllowedPreV4 = true;
  mIdAllowedPreV4 = true;
}


/*
 * Copy constructor for SedAbstractCurve.
 */
SedAbstractCurve::SedAbstractCurve(const SedAbstractCurve& orig)
  : SedBase( orig )
  , mLogX ( orig.mLogX )
  , mIsSetLogX ( orig.mIsSetLogX )
  , mOrder ( orig.mOrder )
  , mIsSetOrder ( orig.mIsSetOrder )
  , mStyle ( orig.mStyle )
  , mYAxis ( orig.mYAxis )
  , mXDataReference ( orig.mXDataReference )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedAbstractCurve.
 */
SedAbstractCurve&
SedAbstractCurve::operator=(const SedAbstractCurve& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mLogX = rhs.mLogX;
    mIsSetLogX = rhs.mIsSetLogX;
    mOrder = rhs.mOrder;
    mIsSetOrder = rhs.mIsSetOrder;
    mStyle = rhs.mStyle;
    mYAxis = rhs.mYAxis;
    mXDataReference = rhs.mXDataReference;
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAbstractCurve object.
 */
SedAbstractCurve*
SedAbstractCurve::clone() const
{
  return new SedAbstractCurve(*this);
}


/*
 * Destructor for SedAbstractCurve.
 */
SedAbstractCurve::~SedAbstractCurve()
{
}


/*
 * Returns the value of the "logX" attribute of this SedAbstractCurve.
 */
bool
SedAbstractCurve::getLogX() const
{
    if (getVersion() < 4)
    {
        return mLogX;
    }
    if (isSetLogX())
    {
        return mLogX;
    }
    const SedBase* parent = getParentSedObject();
    if (parent) 
    {
        parent = parent->getParentSedObject();
    }
    if (parent)
    {
        if (parent->getTypeCode() == SEDML_OUTPUT_PLOT2D || 
            parent->getTypeCode() == SEDML_OUTPUT_PLOT3D)
        {
            const SedPlot* plot = static_cast<const SedPlot*>(parent);
            if (plot)
            {
                const SedAxis* axis = plot->getXAxis();
                if (axis && axis->isSetType())
                {
                    return axis->getType() == SEDML_AXISTYPE_LOG10;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return mLogX;
}


/*
 * Returns the value of the "order" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::getOrder() const
{
  return mOrder;
}


/*
 * Returns the value of the "style" attribute of this SedAbstractCurve.
 */
const std::string&
SedAbstractCurve::getStyle() const
{
  return mStyle;
}


/*
 * Returns the value of the "yAxis" attribute of this SedAbstractCurve.
 */
const std::string&
SedAbstractCurve::getYAxis() const
{
  return mYAxis;
}


/*
 * Returns the value of the "xDataReference" attribute of this
 * SedAbstractCurve.
 */
const std::string&
SedAbstractCurve::getXDataReference() const
{
  return mXDataReference;
}


/*
 * Predicate returning @c true if this SedAbstractCurve's "logX" attribute is
 * set.
 */
bool
SedAbstractCurve::isSetLogX() const
{
  return mIsSetLogX;
}


/*
 * Predicate returning @c true if this SedAbstractCurve's "order" attribute is
 * set.
 */
bool
SedAbstractCurve::isSetOrder() const
{
  return mIsSetOrder;
}


/*
 * Predicate returning @c true if this SedAbstractCurve's "style" attribute is
 * set.
 */
bool
SedAbstractCurve::isSetStyle() const
{
  return (mStyle.empty() == false);
}


/*
 * Predicate returning @c true if this SedAbstractCurve's "yAxis" attribute is
 * set.
 */
bool
SedAbstractCurve::isSetYAxis() const
{
  return (mYAxis.empty() == false);
}


/*
 * Predicate returning @c true if this SedAbstractCurve's "xDataReference"
 * attribute is set.
 */
bool
SedAbstractCurve::isSetXDataReference() const
{
  return (mXDataReference.empty() == false);
}


/*
 * Sets the value of the "logX" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setLogX(bool logX)
{
  mLogX = logX;
  mIsSetLogX = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "order" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setOrder(int order)
{
  mOrder = order;
  mIsSetOrder = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "style" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setStyle(const std::string& style)
{
  if (!(SyntaxChecker::isValidInternalSId(style)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mStyle = style;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "yAxis" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setYAxis(const std::string& yAxis)
{
  mYAxis = yAxis;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "xDataReference" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setXDataReference(const std::string& xDataReference)
{
  if (!(SyntaxChecker::isValidInternalSId(xDataReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mXDataReference = xDataReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "logX" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::unsetLogX()
{
  mLogX = false;
  mIsSetLogX = false;

  if (isSetLogX() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "order" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::unsetOrder()
{
  mOrder = SEDML_INT_MAX;
  mIsSetOrder = false;

  if (isSetOrder() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "style" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::unsetStyle()
{
  mStyle.erase();

  if (mStyle.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "yAxis" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::unsetYAxis()
{
  mYAxis.erase();

  if (mYAxis.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "xDataReference" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::unsetXDataReference()
{
  mXDataReference.erase();

  if (mXDataReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Predicate returning @c true if this abstract "SedAbstractCurve" is of type
 * SedCurve
 */
bool
SedAbstractCurve::isSedCurve() const
{
  return dynamic_cast<const SedCurve*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedAbstractCurve" is of type
 * SedShadedArea
 */
bool
SedAbstractCurve::isSedShadedArea() const
{
  return dynamic_cast<const SedShadedArea*>(this) != NULL;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedAbstractCurve::renameSIdRefs(const std::string& oldid,
                                const std::string& newid)
{
  if (isSetStyle() && mStyle == oldid)
  {
    setStyle(newid);
  }

  if (isSetXDataReference() && mXDataReference == oldid)
  {
    setXDataReference(newid);
  }
}


/*
 * Returns the XML element name of this SedAbstractCurve object.
 */
const std::string&
SedAbstractCurve::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedAbstractCurve object.
 */
void
SedAbstractCurve::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedAbstractCurve object.
 */
int
SedAbstractCurve::getTypeCode() const
{
  return SEDML_ABSTRACTCURVE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAbstractCurve object have been set.
 */
bool
SedAbstractCurve::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedAbstractCurve::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
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
SedAbstractCurve::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAbstractCurve::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::getAttribute(const std::string& attributeName,
                               bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "logX")
  {
    value = getLogX();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::getAttribute(const std::string& attributeName,
                               int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "order")
  {
    value = getOrder();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::getAttribute(const std::string& attributeName,
                               double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::getAttribute(const std::string& attributeName,
                               unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::getAttribute(const std::string& attributeName,
                               std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "style")
  {
    value = getStyle();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "yAxis")
  {
    value = getYAxis();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "xDataReference")
  {
    value = getXDataReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedAbstractCurve's attribute
 * "attributeName" is set.
 */
bool
SedAbstractCurve::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "logX")
  {
    value = isSetLogX();
  }
  else if (attributeName == "order")
  {
    value = isSetOrder();
  }
  else if (attributeName == "style")
  {
    value = isSetStyle();
  }
  else if (attributeName == "yAxis")
  {
    value = isSetYAxis();
  }
  else if (attributeName == "xDataReference")
  {
    value = isSetXDataReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "logX")
  {
    return_value = setLogX(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "order")
  {
    return_value = setOrder(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setAttribute(const std::string& attributeName,
                               unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::setAttribute(const std::string& attributeName,
                               const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "style")
  {
    return_value = setStyle(value);
  }
  else if (attributeName == "yAxis")
  {
    return_value = setYAxis(value);
  }
  else if (attributeName == "xDataReference")
  {
    return_value = setXDataReference(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedAbstractCurve.
 */
int
SedAbstractCurve::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "logX")
  {
    value = unsetLogX();
  }
  else if (attributeName == "order")
  {
    value = unsetOrder();
  }
  else if (attributeName == "style")
  {
    value = unsetStyle();
  }
  else if (attributeName == "yAxis")
  {
    value = unsetYAxis();
  }
  else if (attributeName == "xDataReference")
  {
    value = unsetXDataReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedAbstractCurve::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("logX");

  attributes.add("order");

  attributes.add("style");

  attributes.add("yAxis");

  attributes.add("xDataReference");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAbstractCurve::readAttributes(
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
    static_cast<SedListOfCurves*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlCurveAllowedAttributes, level, version,
          details, getLine(), getColumn());
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
        log->logError(SedmlAbstractCurveAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // logX bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLogX = attributes.readInto("logX", mLogX);

  if (mIsSetLogX == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlAbstractCurveLogXMustBeBoolean, level, version);
    }
  }

  // 
  // order int (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetOrder = attributes.readInto("order", mOrder);

  if ( mIsSetOrder == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'order' from the "
        "<SedAbstractCurve> element must be an integer.";
      log->logError(SedmlAbstractCurveOrderMustBeInteger, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // style SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("style", mStyle);

  if (assigned == true)
  {
    if (mStyle.empty() == true)
    {
      logEmptyString(mStyle, level, version, "<SedAbstractCurve>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mStyle) == false)
    {
      std::string msg = "The style attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mStyle + "', which does not conform to the syntax.";
      logError(SedmlAbstractCurveStyleMustBeStyle, level, version, msg,
        getLine(), getColumn());
    }
  }

  // 
  // yAxis string (use = "optional" )
  // 

  assigned = attributes.readInto("yAxis", mYAxis);

  if (assigned == true)
  {
    if (mYAxis.empty() == true)
    {
      logEmptyString(mYAxis, level, version, "<SedAbstractCurve>");
    }
  }

  // 
  // xDataReference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("xDataReference", mXDataReference);

  if (assigned == true)
  {
    if (mXDataReference.empty() == true)
    {
      logEmptyString(mXDataReference, level, version, "<SedAbstractCurve>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mXDataReference) == false)
    {
      std::string msg = "The xDataReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mXDataReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlAbstractCurveXDataReferenceMustBeDataReference, level,
        version, msg, getLine(), getColumn());
    }
  }
  else if (getLevel() > 1 || getVersion() >= 4)
  {
      if (log)
      {
          std::string message = "Sedml attribute 'xDataReference' is missing from the "
              "<SedAbstractCurve> element.";
          log->logError(SedmlAbstractCurveAllowedAttributes, level, version, message,
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
SedAbstractCurve::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetLogX() == true)
  {
    stream.writeAttribute("logX", getPrefix(), mLogX);
  }

  if (isSetOrder() == true)
  {
    stream.writeAttribute("order", getPrefix(), mOrder);
  }

  if (isSetStyle() == true)
  {
    stream.writeAttribute("style", getPrefix(), mStyle);
  }

  if (isSetYAxis() == true)
  {
    stream.writeAttribute("yAxis", getPrefix(), mYAxis);
  }

  if (isSetXDataReference() == true)
  {
    stream.writeAttribute("xDataReference", getPrefix(), mXDataReference);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedCurve using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedCurve_t *
SedAbstractCurve_createCurve(unsigned int level, unsigned int version)
{
  return new SedCurve(level, version);
}


/*
 * Creates a new SedShadedArea using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedShadedArea_t *
SedAbstractCurve_createShadedArea(unsigned int level, unsigned int version)
{
  return new SedShadedArea(level, version);
}


/*
 * Creates and returns a deep copy of this SedAbstractCurve_t object.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedAbstractCurve_clone(const SedAbstractCurve_t* sac)
{
  if (sac != NULL)
  {
    return static_cast<SedAbstractCurve_t*>(sac->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAbstractCurve_t object.
 */
LIBSEDML_EXTERN
void
SedAbstractCurve_free(SedAbstractCurve_t* sac)
{
  if (sac != NULL)
  {
    delete sac;
  }
}


/*
 * Returns the value of the "id" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getId(const SedAbstractCurve_t * sac)
{
  if (sac == NULL)
  {
    return NULL;
  }

  return sac->getId().empty() ? NULL : safe_strdup(sac->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getName(const SedAbstractCurve_t * sac)
{
  if (sac == NULL)
  {
    return NULL;
  }

  return sac->getName().empty() ? NULL : safe_strdup(sac->getName().c_str());
}


/*
 * Returns the value of the "logX" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_getLogX(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->getLogX()) : 0;
}


/*
 * Returns the value of the "order" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_getOrder(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? sac->getOrder() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "style" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getStyle(const SedAbstractCurve_t * sac)
{
  if (sac == NULL)
  {
    return NULL;
  }

  return sac->getStyle().empty() ? NULL : safe_strdup(sac->getStyle().c_str());
}


/*
 * Returns the value of the "yAxis" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getYAxis(const SedAbstractCurve_t * sac)
{
  if (sac == NULL)
  {
    return NULL;
  }

  return sac->getYAxis().empty() ? NULL : safe_strdup(sac->getYAxis().c_str());
}


/*
 * Returns the value of the "xDataReference" attribute of this
 * SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getXDataReference(const SedAbstractCurve_t * sac)
{
  if (sac == NULL)
  {
    return NULL;
  }

  return sac->getXDataReference().empty() ? NULL :
    safe_strdup(sac->getXDataReference().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "id" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetId(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "name"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetName(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "logX"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetLogX(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSetLogX()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "order"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetOrder(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSetOrder()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "style"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetStyle(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSetStyle()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "yAxis"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetYAxis(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSetYAxis()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's
 * "xDataReference" attribute is set.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetXDataReference(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSetXDataReference()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setId(SedAbstractCurve_t * sac, const char * id)
{
  return (sac != NULL) ? sac->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setName(SedAbstractCurve_t * sac, const char * name)
{
  return (sac != NULL) ? sac->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "logX" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setLogX(SedAbstractCurve_t * sac, int logX)
{
  return (sac != NULL) ? sac->setLogX(logX) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "order" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setOrder(SedAbstractCurve_t * sac, int order)
{
  return (sac != NULL) ? sac->setOrder(order) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "style" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setStyle(SedAbstractCurve_t * sac, const char * style)
{
  return (sac != NULL) ? sac->setStyle(style) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "yAxis" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setYAxis(SedAbstractCurve_t * sac, const char * yAxis)
{
  return (sac != NULL) ? sac->setYAxis(yAxis) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "xDataReference" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setXDataReference(SedAbstractCurve_t * sac,
                                   const char * xDataReference)
{
  return (sac != NULL) ? sac->setXDataReference(xDataReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetId(SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? sac->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetName(SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? sac->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "logX" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetLogX(SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? sac->unsetLogX() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "order" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetOrder(SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? sac->unsetOrder() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "style" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetStyle(SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? sac->unsetStyle() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "yAxis" attribute of this SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetYAxis(SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? sac->unsetYAxis() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "xDataReference" attribute of this
 * SedAbstractCurve_t.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetXDataReference(SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? sac->unsetXDataReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if this SedAbstractCurve_t is of type SedCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSedCurve(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSedCurve()) : 0;
}


/*
 * Predicate returning @c 1 if this SedAbstractCurve_t is of type
 * SedShadedArea_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSedShadedArea(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->isSedShadedArea()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAbstractCurve_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_hasRequiredAttributes(const SedAbstractCurve_t * sac)
{
  return (sac != NULL) ? static_cast<int>(sac->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


