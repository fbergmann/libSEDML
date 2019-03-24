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


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSurface using the given SEDML Level and @ p version values.
 */
SedSurface::SedSurface(unsigned int level, unsigned int version)
  : SedCurve(level, version)
  , mLogZ (false)
  , mIsSetLogZ (false)
  , mZDataReference ("")
  , mSurfaceType (SEDML_SURFACETYPE_INVALID)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSurface using the given SedNamespaces object @p sedmlns.
 */
SedSurface::SedSurface(SedNamespaces *sedmlns)
  : SedCurve(sedmlns)
  , mLogZ (false)
  , mIsSetLogZ (false)
  , mZDataReference ("")
  , mSurfaceType (SEDML_SURFACETYPE_INVALID)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedSurface.
 */
SedSurface::SedSurface(const SedSurface& orig)
  : SedCurve( orig )
  , mLogZ ( orig.mLogZ )
  , mIsSetLogZ ( orig.mIsSetLogZ )
  , mZDataReference ( orig.mZDataReference )
  , mSurfaceType ( orig.mSurfaceType )
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
    SedCurve::operator=(rhs);
    mLogZ = rhs.mLogZ;
    mIsSetLogZ = rhs.mIsSetLogZ;
    mZDataReference = rhs.mZDataReference;
    mSurfaceType = rhs.mSurfaceType;
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
 * Returns the value of the "logZ" attribute of this SedSurface.
 */
bool
SedSurface::getLogZ() const
{
  return mLogZ;
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
 * Returns the value of the "surfaceType" attribute of this SedSurface.
 */
SurfaceType_t
SedSurface::getSurfaceType() const
{
  return mSurfaceType;
}


/*
 * Returns the value of the "surfaceType" attribute of this SedSurface.
 */
std::string
SedSurface::getSurfaceTypeAsString() const
{
  std::string code_str = SurfaceType_toString(mSurfaceType);
  return code_str;
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
 * Predicate returning @c true if this SedSurface's "zDataReference" attribute
 * is set.
 */
bool
SedSurface::isSetZDataReference() const
{
  return (mZDataReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedSurface's "surfaceType" attribute is
 * set.
 */
bool
SedSurface::isSetSurfaceType() const
{
  return (mSurfaceType != SEDML_SURFACETYPE_INVALID);
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
 * Sets the value of the "surfaceType" attribute of this SedSurface.
 */
int
SedSurface::setSurfaceType(const SurfaceType_t surfaceType)
{
  if (SurfaceType_isValid(surfaceType) == 0)
  {
    mSurfaceType = SEDML_SURFACETYPE_INVALID;
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSurfaceType = surfaceType;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "surfaceType" attribute of this SedSurface.
 */
int
SedSurface::setSurfaceType(const std::string& surfaceType)
{
  mSurfaceType = SurfaceType_fromString(surfaceType.c_str());

  if (mSurfaceType == SEDML_SURFACETYPE_INVALID)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSEDML_OPERATION_SUCCESS;
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
 * Unsets the value of the "surfaceType" attribute of this SedSurface.
 */
int
SedSurface::unsetSurfaceType()
{
  mSurfaceType = SEDML_SURFACETYPE_INVALID;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedSurface::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetZDataReference() && mZDataReference == oldid)
  {
    setZDataReference(newid);
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
  bool allPresent = SedCurve::hasRequiredAttributes();

  if (isSetLogZ() == false)
  {
    allPresent = false;
  }

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
  SedCurve::writeElements(stream);
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
  SedCurve::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSurface.
 */
int
SedSurface::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedCurve::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "logZ")
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
  int return_value = SedCurve::getAttribute(attributeName, value);

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
  int return_value = SedCurve::getAttribute(attributeName, value);

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
  int return_value = SedCurve::getAttribute(attributeName, value);

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
  int return_value = SedCurve::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "zDataReference")
  {
    value = getZDataReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "surfaceType")
  {
    value = getSurfaceTypeAsString();
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
  bool value = SedCurve::isSetAttribute(attributeName);

  if (attributeName == "logZ")
  {
    value = isSetLogZ();
  }
  else if (attributeName == "zDataReference")
  {
    value = isSetZDataReference();
  }
  else if (attributeName == "surfaceType")
  {
    value = isSetSurfaceType();
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
  int return_value = SedCurve::setAttribute(attributeName, value);

  if (attributeName == "logZ")
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
  int return_value = SedCurve::setAttribute(attributeName, value);

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
  int return_value = SedCurve::setAttribute(attributeName, value);

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
  int return_value = SedCurve::setAttribute(attributeName, value);

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
  int return_value = SedCurve::setAttribute(attributeName, value);

  if (attributeName == "zDataReference")
  {
    return_value = setZDataReference(value);
  }
  else if (attributeName == "surfaceType")
  {
    return_value = setSurfaceType(value);
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
  int value = SedCurve::unsetAttribute(attributeName);

  if (attributeName == "logZ")
  {
    value = unsetLogZ();
  }
  else if (attributeName == "zDataReference")
  {
    value = unsetZDataReference();
  }
  else if (attributeName == "surfaceType")
  {
    value = unsetSurfaceType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedSurface::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedCurve::createObject(stream);

  connectToChild();

  return obj;
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
  SedCurve::addExpectedAttributes(attributes);

  attributes.add("logZ");

  attributes.add("zDataReference");

  attributes.add("surfaceType");
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
          version, details);
      }
    }
  }

  SedCurve::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlSurfaceAllowedAttributes, level, version, details);
      }
    }
  }

  // 
  // logZ bool (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetLogZ = attributes.readInto("logZ", mLogZ);

  if (mIsSetLogZ == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(SedmlSurfaceLogZMustBeBoolean, level, version);
    }
    else
    {
      std::string message = "Sedml attribute 'logZ' is missing from the "
        "<SedSurface> element.";
      log->logError(SedmlSurfaceAllowedAttributes, level, version, message);
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
        msg);
    }
  }
  else
  {
    std::string message = "Sedml attribute 'zDataReference' is missing from the "
      "<SedSurface> element.";
    log->logError(SedmlSurfaceAllowedAttributes, level, version, message);
  }

  // 
  // surfaceType enum (use = "optional" )
  // 

  std::string surfaceType;
  assigned = attributes.readInto("surfaceType", surfaceType);

  if (assigned == true)
  {
    if (surfaceType.empty() == true)
    {
      logEmptyString(surfaceType, level, version, "<SedSurface>");
    }
    else
    {
      mSurfaceType = SurfaceType_fromString(surfaceType.c_str());

      if (SurfaceType_isValid(mSurfaceType) == 0)
      {
        std::string msg = "The surfaceType on the <SedSurface> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + surfaceType + "', which is not a valid option.";

        log->logError(SedmlSurfaceAllowedAttributes, level, version, msg);
      }
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
  SedCurve::writeAttributes(stream);

  if (isSetLogZ() == true)
  {
    stream.writeAttribute("logZ", getPrefix(), mLogZ);
  }

  if (isSetZDataReference() == true)
  {
    stream.writeAttribute("zDataReference", getPrefix(), mZDataReference);
  }

  if (isSetSurfaceType() == true)
  {
    stream.writeAttribute("surfaceType", getPrefix(),
      SurfaceType_toString(mSurfaceType));
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSurface_t using the given SEDML Level and @ p version
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
 * Returns the value of the "logZ" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_getLogZ(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->getLogZ()) : 0;
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
 * Returns the value of the "surfaceType" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
SurfaceType_t
SedSurface_getSurfaceType(const SedSurface_t * ss)
{
  if (ss == NULL)
  {
    return SEDML_SURFACETYPE_INVALID;
  }

  return ss->getSurfaceType();
}


/*
 * Returns the value of the "surfaceType" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
char *
SedSurface_getSurfaceTypeAsString(const SedSurface_t * ss)
{
  return (char*)(SurfaceType_toString(ss->getSurfaceType()));
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
 * Predicate returning @c 1 (true) if this SedSurface_t's "surfaceType"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedSurface_isSetSurfaceType(const SedSurface_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetSurfaceType()) : 0;
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
 * Sets the value of the "surfaceType" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setSurfaceType(SedSurface_t * ss, SurfaceType_t surfaceType)
{
  return (ss != NULL) ? ss->setSurfaceType(surfaceType) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "surfaceType" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_setSurfaceTypeAsString(SedSurface_t * ss, const char * surfaceType)
{
  return (ss != NULL) ? ss->setSurfaceType(surfaceType):
    LIBSEDML_INVALID_OBJECT;
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
 * Unsets the value of the "zDataReference" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetZDataReference(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetZDataReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "surfaceType" attribute of this SedSurface_t.
 */
LIBSEDML_EXTERN
int
SedSurface_unsetSurfaceType(SedSurface_t * ss)
{
  return (ss != NULL) ? ss->unsetSurfaceType() : LIBSEDML_INVALID_OBJECT;
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


