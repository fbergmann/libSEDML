/**
 * @file SedSurface.cpp
 * @brief Implementation of the SedSurface class.
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
#include <sedml/SedSurface.h>
#include <sedml/SedListOfSurfaces.h>
#include <sbml/xml/XMLInputStream.h>
#include <sedml/SedPlot3D.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSurface using the given SED-ML Level and @ p version values.
 */
SedSurface::SedSurface(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mXDataReference ("")
  , mYDataReference ("")
  , mZDataReference ("")
  , mType (SEDML_SURFACETYPE_INVALID)
  , mStyle ("")
  , mLogX (false)
  , mIsSetLogX (false)
  , mLogY (false)
  , mIsSetLogY (false)
  , mLogZ (false)
  , mIsSetLogZ (false)
  , mOrder (SEDML_INT_MAX)
  , mIsSetOrder (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  mNameAllowedPreV4 = true;
  mIdAllowedPreV4 = true;
}


/*
 * Creates a new SedSurface using the given SedNamespaces object @p sedmlns.
 */
SedSurface::SedSurface(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mXDataReference ("")
  , mYDataReference ("")
  , mZDataReference ("")
  , mType (SEDML_SURFACETYPE_INVALID)
  , mStyle ("")
  , mLogX (false)
  , mIsSetLogX (false)
  , mLogY (false)
  , mIsSetLogY (false)
  , mLogZ (false)
  , mIsSetLogZ (false)
  , mOrder (SEDML_INT_MAX)
  , mIsSetOrder (false)
{
  setElementNamespace(sedmlns->getURI());
  mNameAllowedPreV4 = true;
  mIdAllowedPreV4 = true;
}


/*
 * Copy constructor for SedSurface.
 */
SedSurface::SedSurface(const SedSurface& orig)
  : SedBase( orig )
  , mXDataReference ( orig.mXDataReference )
  , mYDataReference ( orig.mYDataReference )
  , mZDataReference ( orig.mZDataReference )
  , mType ( orig.mType )
  , mStyle ( orig.mStyle )
  , mLogX ( orig.mLogX )
  , mIsSetLogX ( orig.mIsSetLogX )
  , mLogY ( orig.mLogY )
  , mIsSetLogY ( orig.mIsSetLogY )
  , mLogZ ( orig.mLogZ )
  , mIsSetLogZ ( orig.mIsSetLogZ )
  , mOrder ( orig.mOrder )
  , mIsSetOrder ( orig.mIsSetOrder )
{
}


/*
 * Assignment operator for SedSurface.
 */
SedSurface&
SedSurface::operator=(const SedSurface& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mXDataReference = rhs.mXDataReference;
    mYDataReference = rhs.mYDataReference;
    mZDataReference = rhs.mZDataReference;
    mType = rhs.mType;
    mStyle = rhs.mStyle;
    mLogX = rhs.mLogX;
    mIsSetLogX = rhs.mIsSetLogX;
    mLogY = rhs.mLogY;
    mIsSetLogY = rhs.mIsSetLogY;
    mLogZ = rhs.mLogZ;
    mIsSetLogZ = rhs.mIsSetLogZ;
    mOrder = rhs.mOrder;
    mIsSetOrder = rhs.mIsSetOrder;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSurface object.
 */
SedSurface*
SedSurface::clone() const
{
  return new SedSurface(*this);
}


/*
 * Destructor for SedSurface.
 */
SedSurface::~SedSurface()
{
}


/*
 * Returns the value of the "xDataReference" attribute of this SedSurface.
 */
const std::string&
SedSurface::getXDataReference() const
{
  return mXDataReference;
}


/*
 * Returns the value of the "yDataReference" attribute of this SedSurface.
 */
const std::string&
SedSurface::getYDataReference() const
{
  return mYDataReference;
}


/*
 * Returns the value of the "zDataReference" attribute of this SedSurface.
 */
const std::string&
SedSurface::getZDataReference() const
{
  return mZDataReference;
}


/*
 * Returns the value of the "type" attribute of this SedSurface.
 */
SurfaceType_t
SedSurface::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this SedSurface.
 */
std::string
SedSurface::getTypeAsString() const
{
  std::string code_str = SurfaceType_toString(mType);
  return code_str;
}


/*
 * Returns the value of the "style" attribute of this SedSurface.
 */
const std::string&
SedSurface::getStyle() const
{
  return mStyle;
}


/*
 * Returns the value of the "logX" attribute of this SedSurface.
 */
bool
SedSurface::getLogX() const
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
 * Returns the value of the "logY" attribute of this SedSurface.
 */
bool
SedSurface::getLogY() const
{
    if (getVersion() < 4)
    {
        return mLogY;
    }
    if (isSetLogY())
    {
        return mLogY;
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
                const SedAxis* axis = plot->getYAxis();
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
    return mLogY;
}


/*
 * Returns the value of the "logZ" attribute of this SedSurface.
 */
bool
SedSurface::getLogZ() const
{
    if (getVersion() < 4)
    {
        return mLogZ;
    }
    if (isSetLogZ())
    {
        return mLogZ;
    }
    const SedBase* parent = getParentSedObject();
    if (parent)
    {
        parent = parent->getParentSedObject();
    }
    if (parent)
    {
        if (parent->getTypeCode() == SEDML_OUTPUT_PLOT3D)
        {
            const SedPlot3D* plot = static_cast<const SedPlot3D*>(parent);
            if (plot)
            {
                const SedAxis* axis = plot->getZAxis();
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
    return mLogZ;
}


/*
 * Returns the value of the "order" attribute of this SedSurface.
 */
int
SedSurface::getOrder() const
{
  return mOrder;
}


/*
 * Predicate returning @c true if this SedSurface's "xDataReference" attribute
 * is set.
 */
bool
SedSurface::isSetXDataReference() const
{
  return (mXDataReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedSurface's "yDataReference" attribute
 * is set.
 */
bool
SedSurface::isSetYDataReference() const
{
  return (mYDataReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedSurface's "zDataReference" attribute
 * is set.
 */
bool
SedSurface::isSetZDataReference() const
{
  return (mZDataReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedSurface's "type" attribute is set.
 */
bool
SedSurface::isSetType() const
{
  return (mType != SEDML_SURFACETYPE_INVALID);
}


/*
 * Predicate returning @c true if this SedSurface's "style" attribute is set.
 */
bool
SedSurface::isSetStyle() const
{
  return (mStyle.empty() == false);
}


/*
 * Predicate returning @c true if this SedSurface's "logX" attribute is set.
 */
bool
SedSurface::isSetLogX() const
{
  return mIsSetLogX;
}


/*
 * Predicate returning @c true if this SedSurface's "logY" attribute is set.
 */
bool
SedSurface::isSetLogY() const
{
  return mIsSetLogY;
}


/*
 * Predicate returning @c true if this SedSurface's "logZ" attribute is set.
 */
bool
SedSurface::isSetLogZ() const
{
  return mIsSetLogZ;
}


/*
 * Predicate returning @c true if this SedSurface's "order" attribute is set.
 */
bool
SedSurface::isSetOrder() const
{
  return mIsSetOrder;
}


/*
 * Sets the value of the "xDataReference" attribute of this SedSurface.
 */
int
SedSurface::setXDataReference(const std::string& xDataReference)
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
 * Sets the value of the "yDataReference" attribute of this SedSurface.
 */
int
SedSurface::setYDataReference(const std::string& yDataReference)
{
  if (!(SyntaxChecker::isValidInternalSId(yDataReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mYDataReference = yDataReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "zDataReference" attribute of this SedSurface.
 */
int
SedSurface::setZDataReference(const std::string& zDataReference)
{
  if (!(SyntaxChecker::isValidInternalSId(zDataReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mZDataReference = zDataReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedSurface.
 */
int
SedSurface::setType(const SurfaceType_t type)
{
  if (SurfaceType_isValid(type) == 0)
  {
    mType = SEDML_SURFACETYPE_INVALID;
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this SedSurface.
 */
int
SedSurface::setType(const std::string& type)
{
  mType = SurfaceType_fromString(type.c_str());

  if (mType == SEDML_SURFACETYPE_INVALID)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "style" attribute of this SedSurface.
 */
int
SedSurface::setStyle(const std::string& style)
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
 * Sets the value of the "logX" attribute of this SedSurface.
 */
int
SedSurface::setLogX(bool logX)
{
  mLogX = logX;
  mIsSetLogX = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "logY" attribute of this SedSurface.
 */
int
SedSurface::setLogY(bool logY)
{
  mLogY = logY;
  mIsSetLogY = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "logZ" attribute of this SedSurface.
 */
int
SedSurface::setLogZ(bool logZ)
{
  mLogZ = logZ;
  mIsSetLogZ = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "order" attribute of this SedSurface.
 */
int
SedSurface::setOrder(int order)
{
  mOrder = order;
  mIsSetOrder = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "xDataReference" attribute of this SedSurface.
 */
int
SedSurface::unsetXDataReference()
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
 * Unsets the value of the "yDataReference" attribute of this SedSurface.
 */
int
SedSurface::unsetYDataReference()
{
  mYDataReference.erase();

  if (mYDataReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "zDataReference" attribute of this SedSurface.
 */
int
SedSurface::unsetZDataReference()
{
  mZDataReference.erase();

  if (mZDataReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "type" attribute of this SedSurface.
 */
int
SedSurface::unsetType()
{
  mType = SEDML_SURFACETYPE_INVALID;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "style" attribute of this SedSurface.
 */
int
SedSurface::unsetStyle()
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
 * Unsets the value of the "logX" attribute of this SedSurface.
 */
int
SedSurface::unsetLogX()
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
 * Unsets the value of the "logY" attribute of this SedSurface.
 */
int
SedSurface::unsetLogY()
{
  mLogY = false;
  mIsSetLogY = false;

  if (isSetLogY() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "logZ" attribute of this SedSurface.
 */
int
SedSurface::unsetLogZ()
{
  mLogZ = false;
  mIsSetLogZ = false;

  if (isSetLogZ() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "order" attribute of this SedSurface.
 */
int
SedSurface::unsetOrder()
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
 * @copydoc doc_renamesidref_common
 */
void
SedSurface::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetXDataReference() && mXDataReference == oldid)
  {
    setXDataReference(newid);
  }

  if (isSetYDataReference() && mYDataReference == oldid)
  {
    setYDataReference(newid);
  }

  if (isSetZDataReference() && mZDataReference == oldid)
  {
    setZDataReference(newid);
  }

  if (isSetStyle() && mStyle == oldid)
  {
    setStyle(newid);
  }
}


/*
 * Returns the XML element name of this SedSurface object.
 */
const std::string&
SedSurface::getElementName() const
{
  static const string name = "surface";
  return name;
}


/*
 * Returns the libSEDML type code for this SedSurface object.
 */
int
SedSurface::getTypeCode() const
{
  return SEDML_OUTPUT_SURFACE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedSurface object have been set.
 */
bool
SedSurface::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetZDataReference() == false)
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
SedSurface::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedSurface::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSurface::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::getAttribute(const std::string& attributeName, bool& value) const
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
  else if (attributeName == "logY")
  {
    value = getLogY();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "logZ")
  {
    value = getLogZ();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::getAttribute(const std::string& attributeName, int& value) const
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
 * Gets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "xDataReference")
  {
    value = getXDataReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "yDataReference")
  {
    value = getYDataReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "zDataReference")
  {
    value = getZDataReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "type")
  {
    value = getTypeAsString();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "style")
  {
    value = getStyle();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedSurface's attribute "attributeName"
 * is set.
 */
bool
SedSurface::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "xDataReference")
  {
    value = isSetXDataReference();
  }
  else if (attributeName == "yDataReference")
  {
    value = isSetYDataReference();
  }
  else if (attributeName == "zDataReference")
  {
    value = isSetZDataReference();
  }
  else if (attributeName == "type")
  {
    value = isSetType();
  }
  else if (attributeName == "style")
  {
    value = isSetStyle();
  }
  else if (attributeName == "logX")
  {
    value = isSetLogX();
  }
  else if (attributeName == "logY")
  {
    value = isSetLogY();
  }
  else if (attributeName == "logZ")
  {
    value = isSetLogZ();
  }
  else if (attributeName == "order")
  {
    value = isSetOrder();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "logX")
  {
    return_value = setLogX(value);
  }
  else if (attributeName == "logY")
  {
    return_value = setLogY(value);
  }
  else if (attributeName == "logZ")
  {
    return_value = setLogZ(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::setAttribute(const std::string& attributeName, int value)
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
 * Sets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "xDataReference")
  {
    return_value = setXDataReference(value);
  }
  else if (attributeName == "yDataReference")
  {
    return_value = setYDataReference(value);
  }
  else if (attributeName == "zDataReference")
  {
    return_value = setZDataReference(value);
  }
  else if (attributeName == "type")
  {
    return_value = setType(value);
  }
  else if (attributeName == "style")
  {
    return_value = setStyle(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "xDataReference")
  {
    value = unsetXDataReference();
  }
  else if (attributeName == "yDataReference")
  {
    value = unsetYDataReference();
  }
  else if (attributeName == "zDataReference")
  {
    value = unsetZDataReference();
  }
  else if (attributeName == "type")
  {
    value = unsetType();
  }
  else if (attributeName == "style")
  {
    value = unsetStyle();
  }
  else if (attributeName == "logX")
  {
    value = unsetLogX();
  }
  else if (attributeName == "logY")
  {
    value = unsetLogY();
  }
  else if (attributeName == "logZ")
  {
    value = unsetLogZ();
  }
  else if (attributeName == "order")
  {
    value = unsetOrder();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSurface::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("xDataReference");

  attributes.add("yDataReference");

  attributes.add("zDataReference");

  attributes.add("type");

  attributes.add("style");

  attributes.add("logX");

  attributes.add("logY");

  attributes.add("logZ");

  attributes.add("order");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSurface::readAttributes(
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
    static_cast<SedListOfSurfaces*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlPlot3DLOSurfacesAllowedCoreAttributes, level,
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
        log->logError(SedmlSurfaceAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
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
      logEmptyString(mXDataReference, level, version, "<SedSurface>");
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
      logError(SedmlSurfaceXDataReferenceMustBeDataGenerator, level, version,
        msg, getLine(), getColumn());
    }
  }
  else if (getLevel() > 1 || getVersion() >= 4)
  {
      if (log)
      {
          std::string message = "Sedml attribute 'xDataReference' is missing from "
              "the <SedSurface> element.";
          log->logError(SedmlSurfaceAllowedAttributes, level, version, message,
              getLine(), getColumn());
      }
  }

  // 
  // yDataReference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("yDataReference", mYDataReference);

  if (assigned == true)
  {
    if (mYDataReference.empty() == true)
    {
      logEmptyString(mYDataReference, level, version, "<SedSurface>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mYDataReference) == false)
    {
      std::string msg = "The yDataReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mYDataReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlSurfaceYDataReferenceMustBeDataGenerator, level, version,
        msg, getLine(), getColumn());
    }
  }
  else if (getLevel() >1 || getVersion() >= 4)
  {
      if (log)
      {
          std::string message = "Sedml attribute 'yDataReference' is missing from "
              "the <SedSurface> element.";
          log->logError(SedmlSurfaceAllowedAttributes, level, version, message,
              getLine(), getColumn());
      }
  }

  // 
  // zDataReference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("zDataReference", mZDataReference);

  if (assigned == true)
  {
    if (mZDataReference.empty() == true)
    {
      logEmptyString(mZDataReference, level, version, "<SedSurface>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mZDataReference) == false)
    {
      std::string msg = "The zDataReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mZDataReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlSurfaceZDataReferenceMustBeDataGenerator, level, version,
        msg, getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'zDataReference' is missing from "
        "the <SedSurface> element.";
      log->logError(SedmlSurfaceAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // type enum (use = "optional" )
  // 

  std::string type;
  assigned = attributes.readInto("type", type);

  if (assigned == true)
  {
    if (type.empty() == true)
    {
      logEmptyString(type, level, version, "<SedSurface>");
    }
    else
    {
      mType = SurfaceType_fromString(type.c_str());

      if (log && SurfaceType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <SedSurface> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logError(SedmlSurfaceTypeMustBeSurfaceTypeEnum, level, version,
          msg, getLine(), getColumn());
      }
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
      logEmptyString(mStyle, level, version, "<SedSurface>");
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
      logError(SedmlSurfaceStyleMustBeStyle, level, version, msg, getLine(),
        getColumn());
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
      log->logError(SedmlSurfaceLogXMustBeBoolean, level, version);
    }
  }

  // 
  // logY bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLogY = attributes.readInto("logY", mLogY);

  if (mIsSetLogY == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlSurfaceLogYMustBeBoolean, level, version);
    }
  }

  // 
  // logZ bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLogZ = attributes.readInto("logZ", mLogZ);

  if (mIsSetLogZ == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlSurfaceLogZMustBeBoolean, level, version);
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
      std::string message = "Sedml attribute 'order' from the <SedSurface> "
        "element must be an integer.";
      log->logError(SedmlSurfaceOrderMustBeInteger, level, version, message,
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
SedSurface::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetXDataReference() == true)
  {
    stream.writeAttribute("xDataReference", getPrefix(), mXDataReference);
  }

  if (isSetYDataReference() == true)
  {
    stream.writeAttribute("yDataReference", getPrefix(), mYDataReference);
  }

  if (isSetZDataReference() == true)
  {
    stream.writeAttribute("zDataReference", getPrefix(), mZDataReference);
  }

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), SurfaceType_toString(mType));
  }

  if (isSetStyle() == true)
  {
    stream.writeAttribute("style", getPrefix(), mStyle);
  }

  if (isSetLogX() == true)
  {
    stream.writeAttribute("logX", getPrefix(), mLogX);
  }

  if (isSetLogY() == true)
  {
    stream.writeAttribute("logY", getPrefix(), mLogY);
  }

  if (isSetLogZ() == true)
  {
    stream.writeAttribute("logZ", getPrefix(), mLogZ);
  }

  if (isSetOrder() == true)
  {
    stream.writeAttribute("order", getPrefix(), mOrder);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSurface_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedSurface_t *
SedSurface_create(unsigned int level, unsigned int version)
{
  return new SedSurface(level, version);
}


/*
 * Creates and returns a deep copy of this SedSurface_t object.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedSurface_clone(const SedSurface_t* ss)
{
  if (ss != NULL)
  {
    return static_cast<SedSurface_t*>(ss->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSurface_t object.
 */
LIBSEDML_EXTERN
void
SedSurface_free(SedSurface_t* ss)
{
  if (ss != NULL)
  {
    delete ss;
  }
}


/*
 * Returns the value of the "id" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
char *
SedSurface_getId(const SedSurface_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getId().empty() ? NULL : safe_strdup(ss->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
char *
SedSurface_getName(const SedSurface_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getName().empty() ? NULL : safe_strdup(ss->getName().c_str());
}


/*
 * Returns the value of the "xDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
char *
SedSurface_getXDataReference(const SedSurface_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getXDataReference().empty() ? NULL :
    safe_strdup(ss->getXDataReference().c_str());
}


/*
 * Returns the value of the "yDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
char *
SedSurface_getYDataReference(const SedSurface_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getYDataReference().empty() ? NULL :
    safe_strdup(ss->getYDataReference().c_str());
}


/*
 * Returns the value of the "zDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
char *
SedSurface_getZDataReference(const SedSurface_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getZDataReference().empty() ? NULL :
    safe_strdup(ss->getZDataReference().c_str());
}


/*
 * Returns the value of the "type" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
SurfaceType_t
SedSurface_getType(const SedSurface_t * ss)
{
  if (ss == NULL)
  {
    return SEDML_SURFACETYPE_INVALID;
  }

  return ss->getType();
}


/*
 * Returns the value of the "type" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
char *
SedSurface_getTypeAsString(const SedSurface_t * ss)
{
  return (char*)(SurfaceType_toString(ss->getType()));
}


/*
 * Returns the value of the "style" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
char *
SedSurface_getStyle(const SedSurface_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getStyle().empty() ? NULL : safe_strdup(ss->getStyle().c_str());
}


/*
 * Returns the value of the "logX" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_getLogX(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->getLogX()) : 0;
}


/*
 * Returns the value of the "logY" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_getLogY(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->getLogY()) : 0;
}


/*
 * Returns the value of the "logZ" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_getLogZ(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->getLogZ()) : 0;
}


/*
 * Returns the value of the "order" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_getOrder(const SedSurface_t * ss)
{
  return (ss != NULL) ? ss->getOrder() : SEDML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "id" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetId(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "name" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetName(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "xDataReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetXDataReference(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetXDataReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "yDataReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetYDataReference(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetYDataReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "zDataReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetZDataReference(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetZDataReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "type" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetType(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetType()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "style" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetStyle(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetStyle()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "logX" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetLogX(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetLogX()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "logY" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetLogY(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetLogY()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "logZ" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetLogZ(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetLogZ()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSurface_t's "order" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetOrder(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetOrder()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setId(SedSurface_t * ss, const char * id)
{
  return (ss != NULL) ? ss->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setName(SedSurface_t * ss, const char * name)
{
  return (ss != NULL) ? ss->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "xDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setXDataReference(SedSurface_t * ss, const char * xDataReference)
{
  return (ss != NULL) ? ss->setXDataReference(xDataReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "yDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setYDataReference(SedSurface_t * ss, const char * yDataReference)
{
  return (ss != NULL) ? ss->setYDataReference(yDataReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "zDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setZDataReference(SedSurface_t * ss, const char * zDataReference)
{
  return (ss != NULL) ? ss->setZDataReference(zDataReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setType(SedSurface_t * ss, SurfaceType_t type)
{
  return (ss != NULL) ? ss->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setTypeAsString(SedSurface_t * ss, const char * type)
{
  return (ss != NULL) ? ss->setType(type): LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "style" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setStyle(SedSurface_t * ss, const char * style)
{
  return (ss != NULL) ? ss->setStyle(style) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "logX" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setLogX(SedSurface_t * ss, int logX)
{
  return (ss != NULL) ? ss->setLogX(logX) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "logY" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setLogY(SedSurface_t * ss, int logY)
{
  return (ss != NULL) ? ss->setLogY(logY) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "logZ" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setLogZ(SedSurface_t * ss, int logZ)
{
  return (ss != NULL) ? ss->setLogZ(logZ) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "order" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setOrder(SedSurface_t * ss, int order)
{
  return (ss != NULL) ? ss->setOrder(order) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetId(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetName(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "xDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetXDataReference(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetXDataReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "yDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetYDataReference(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetYDataReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "zDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetZDataReference(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetZDataReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetType(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetType() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "style" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetStyle(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetStyle() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "logX" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetLogX(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetLogX() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "logY" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetLogY(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetLogY() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "logZ" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetLogZ(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetLogZ() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "order" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetOrder(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetOrder() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSurface_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSurface_hasRequiredAttributes(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


