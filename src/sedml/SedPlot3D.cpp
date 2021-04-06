/**
 * @file SedPlot3D.cpp
 * @brief Implementation of the SedPlot3D class.
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
#include <sedml/SedPlot3D.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedPlot3D using the given SED-ML Level and @ p version values.
 */
SedPlot3D::SedPlot3D(unsigned int level, unsigned int version)
  : SedPlot(level, version)
  , mSurfaces (level, version)
  , mZAxis (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedPlot3D using the given SedNamespaces object @p sedmlns.
 */
SedPlot3D::SedPlot3D(SedNamespaces *sedmlns)
  : SedPlot(sedmlns)
  , mSurfaces (sedmlns)
  , mZAxis (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedPlot3D.
 */
SedPlot3D::SedPlot3D(const SedPlot3D& orig)
  : SedPlot( orig )
  , mSurfaces ( orig.mSurfaces )
  , mZAxis ( NULL )
{
  if (orig.mZAxis != NULL)
  {
    mZAxis = orig.mZAxis->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedPlot3D.
 */
SedPlot3D&
SedPlot3D::operator=(const SedPlot3D& rhs)
{
  if (&rhs != this)
  {
    SedPlot::operator=(rhs);
    mSurfaces = rhs.mSurfaces;
    delete mZAxis;
    if (rhs.mZAxis != NULL)
    {
      mZAxis = rhs.mZAxis->clone();
    }
    else
    {
      mZAxis = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedPlot3D object.
 */
SedPlot3D*
SedPlot3D::clone() const
{
  return new SedPlot3D(*this);
}


/*
 * Destructor for SedPlot3D.
 */
SedPlot3D::~SedPlot3D()
{
  delete mZAxis;
  mZAxis = NULL;
}


/*
 * Returns the value of the "zAxis" element of this SedPlot3D.
 */
const SedAxis*
SedPlot3D::getZAxis() const
{
  return mZAxis;
}


/*
 * Returns the value of the "zAxis" element of this SedPlot3D.
 */
SedAxis*
SedPlot3D::getZAxis()
{
  return mZAxis;
}


/*
 * Predicate returning @c true if this SedPlot3D's "zAxis" element is set.
 */
bool
SedPlot3D::isSetZAxis() const
{
  return (mZAxis != NULL);
}


/*
 * Sets the value of the "zAxis" element of this SedPlot3D.
 */
int
SedPlot3D::setZAxis(const SedAxis* zAxis)
{
  if (mZAxis == zAxis)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (zAxis == NULL)
  {
    delete mZAxis;
    mZAxis = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mZAxis;
    mZAxis = (zAxis != NULL) ? zAxis->clone() : NULL;
    if (mZAxis != NULL)
    {
      mZAxis->setElementName("zAxis");
      mZAxis->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedAxis object, adds it to this SedPlot3D object and returns
 * the SedAxis object created.
 */
SedAxis*
SedPlot3D::createZAxis()
{
  if (mZAxis != NULL)
  {
    delete mZAxis;
  }

  mZAxis = new SedAxis(getSedNamespaces());

  mZAxis->setElementName("zAxis");

  connectToChild();

  return mZAxis;
}


/*
 * Unsets the value of the "zAxis" element of this SedPlot3D.
 */
int
SedPlot3D::unsetZAxis()
{
  delete mZAxis;
  mZAxis = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfSurfaces from this SedPlot3D.
 */
const SedListOfSurfaces*
SedPlot3D::getListOfSurfaces() const
{
  return &mSurfaces;
}


/*
 * Returns the SedListOfSurfaces from this SedPlot3D.
 */
SedListOfSurfaces*
SedPlot3D::getListOfSurfaces()
{
  return &mSurfaces;
}


/*
 * Get a SedSurface from the SedPlot3D.
 */
SedSurface*
SedPlot3D::getSurface(unsigned int n)
{
  return mSurfaces.get(n);
}


/*
 * Get a SedSurface from the SedPlot3D.
 */
const SedSurface*
SedPlot3D::getSurface(unsigned int n) const
{
  return mSurfaces.get(n);
}


/*
 * Get a SedSurface from the SedPlot3D based on its identifier.
 */
SedSurface*
SedPlot3D::getSurface(const std::string& sid)
{
  return mSurfaces.get(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on its identifier.
 */
const SedSurface*
SedPlot3D::getSurface(const std::string& sid) const
{
  return mSurfaces.get(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on the XDataReference to which it
 * refers.
 */
const SedSurface*
SedPlot3D::getSurfaceByXDataReference(const std::string& sid) const
{
  return mSurfaces.getByXDataReference(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on the XDataReference to which it
 * refers.
 */
SedSurface*
SedPlot3D::getSurfaceByXDataReference(const std::string& sid)
{
  return mSurfaces.getByXDataReference(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on the YDataReference to which it
 * refers.
 */
const SedSurface*
SedPlot3D::getSurfaceByYDataReference(const std::string& sid) const
{
  return mSurfaces.getByYDataReference(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on the YDataReference to which it
 * refers.
 */
SedSurface*
SedPlot3D::getSurfaceByYDataReference(const std::string& sid)
{
  return mSurfaces.getByYDataReference(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on the ZDataReference to which it
 * refers.
 */
const SedSurface*
SedPlot3D::getSurfaceByZDataReference(const std::string& sid) const
{
  return mSurfaces.getByZDataReference(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on the ZDataReference to which it
 * refers.
 */
SedSurface*
SedPlot3D::getSurfaceByZDataReference(const std::string& sid)
{
  return mSurfaces.getByZDataReference(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on the Style to which it refers.
 */
const SedSurface*
SedPlot3D::getSurfaceByStyle(const std::string& sid) const
{
  return mSurfaces.getByStyle(sid);
}


/*
 * Get a SedSurface from the SedPlot3D based on the Style to which it refers.
 */
SedSurface*
SedPlot3D::getSurfaceByStyle(const std::string& sid)
{
  return mSurfaces.getByStyle(sid);
}


/*
 * Adds a copy of the given SedSurface to this SedPlot3D.
 */
int
SedPlot3D::addSurface(const SedSurface* ss)
{
  if (ss == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ss->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ss->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ss->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ss)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (ss->isSetId() && (mSurfaces.get(ss->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mSurfaces.append(ss);
  }
}


/*
 * Get the number of SedSurface objects in this SedPlot3D.
 */
unsigned int
SedPlot3D::getNumSurfaces() const
{
  return mSurfaces.size();
}


/*
 * Creates a new SedSurface object, adds it to this SedPlot3D object and
 * returns the SedSurface object created.
 */
SedSurface*
SedPlot3D::createSurface()
{
  SedSurface* ss = NULL;

  try
  {
    ss = new SedSurface(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ss != NULL)
  {
    mSurfaces.appendAndOwn(ss);
  }

  return ss;
}


/*
 * Removes the nth SedSurface from this SedPlot3D and returns a pointer to it.
 */
SedSurface*
SedPlot3D::removeSurface(unsigned int n)
{
  return mSurfaces.remove(n);
}


/*
 * Removes the SedSurface from this SedPlot3D based on its identifier and
 * returns a pointer to it.
 */
SedSurface*
SedPlot3D::removeSurface(const std::string& sid)
{
  return mSurfaces.remove(sid);
}


/*
 * Returns the XML element name of this SedPlot3D object.
 */
const std::string&
SedPlot3D::getElementName() const
{
  static const string name = "plot3D";
  return name;
}


/*
 * Returns the libSEDML type code for this SedPlot3D object.
 */
int
SedPlot3D::getTypeCode() const
{
  return SEDML_OUTPUT_PLOT3D;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedPlot3D object have been set.
 */
bool
SedPlot3D::hasRequiredAttributes() const
{
  bool allPresent = SedPlot::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SedPlot3D
 * object have been set.
 */
bool
SedPlot3D::hasRequiredElements() const
{
  bool allPresent = SedPlot::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedPlot3D::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedPlot::writeElements(stream);

  if (isSetZAxis() == true)
  {
    mZAxis->write(stream);
  }

  if (getNumSurfaces() > 0)
  {
    mSurfaces.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedPlot3D::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedPlot3D::setSedDocument(SedDocument* d)
{
  SedPlot::setSedDocument(d);

  if (mZAxis != NULL)
  {
    mZAxis->setSedDocument(d);
  }

  mSurfaces.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedPlot3D::connectToChild()
{
  SedPlot::connectToChild();

  if (mZAxis != NULL)
  {
    mZAxis->connectToParent(this);
  }

  mSurfaces.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedPlot3D's attribute "attributeName" is
 * set.
 */
bool
SedPlot3D::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedPlot::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedPlot3D.
 */
int
SedPlot3D::unsetAttribute(const std::string& attributeName)
{
  int value = SedPlot::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedPlot3D.
 */
SedBase*
SedPlot3D::createChildObject(const std::string& elementName)
{
  SedPlot* obj = NULL;

  if (elementName == "zAxis")
  {
    return createZAxis();
  }
  else if (elementName == "surface")
  {
    return createSurface();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedPlot3D.
 */
int
SedPlot3D::addChildObject(const std::string& elementName,
                          const SedBase* element)
{
  if (elementName == "zAxis" && element->getTypeCode() == SEDML_AXIS)
  {
    return setZAxis((const SedAxis*)(element));
  }
  else if (elementName == "surface" && element->getTypeCode() ==
    SEDML_OUTPUT_SURFACE)
  {
    return addSurface((const SedSurface*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedPlot3D.
 */
SedBase*
SedPlot3D::removeChildObject(const std::string& elementName,
                             const std::string& id)
{
  if (elementName == "zAxis")
  {
    SedAxis * obj = mZAxis;
    mZAxis = NULL; return obj;
  }
  else if (elementName == "surface")
  {
    return removeSurface(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedPlot3D.
 */
unsigned int
SedPlot3D::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "zAxis")
  {
    if (isSetZAxis())
    {
      return 1;
    }
  }
  else if (elementName == "surface")
  {
    return getNumSurfaces();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedPlot3D.
 */
SedBase*
SedPlot3D::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "zAxis")
  {
    return getZAxis();
  }
  else if (elementName == "surface")
  {
    return getSurface(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedPlot3D::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mZAxis != NULL)
  {
    if (mZAxis->getId() == id)
    {
      return mZAxis;
    }

    obj = mZAxis->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mSurfaces.getElementBySId(id);

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
SedPlot3D::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  SED_ADD_FILTERED_POINTER(ret, sublist, mZAxis, filter);

  SED_ADD_FILTERED_LIST(ret, sublist, mSurfaces, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedPlot3D::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = SedPlot::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "zAxis")
  {
    if (getErrorLog() && isSetZAxis())
    {
      getErrorLog()->logError(SedmlPlot3DAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mZAxis;
    mZAxis = new SedAxis(getSedNamespaces());
    mZAxis->setElementName(name);
    obj = mZAxis;
  }
  else if (name == "listOfSurfaces")
  {
    if (getErrorLog() && mSurfaces.size() != 0)
    {
      getErrorLog()->logError(SedmlPlot3DAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mSurfaces;
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
SedPlot3D::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedPlot::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedPlot3D::readAttributes(
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

  SedPlot::readAttributes(attributes, expectedAttributes);

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
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedPlot3D::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedPlot::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedPlot3D_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedPlot3D_t *
SedPlot3D_create(unsigned int level, unsigned int version)
{
  return new SedPlot3D(level, version);
}


/*
 * Creates and returns a deep copy of this SedPlot3D_t object.
 */
LIBSEDML_EXTERN
SedPlot3D_t*
SedPlot3D_clone(const SedPlot3D_t* spd)
{
  if (spd != NULL)
  {
    return static_cast<SedPlot3D_t*>(spd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedPlot3D_t object.
 */
LIBSEDML_EXTERN
void
SedPlot3D_free(SedPlot3D_t* spd)
{
  if (spd != NULL)
  {
    delete spd;
  }
}


/*
 * Returns the value of the "zAxis" element of this SedPlot3D_t.
 */
LIBSEDML_EXTERN
const SedAxis_t*
SedPlot3D_getZAxis(const SedPlot3D_t * spd)
{
  if (spd == NULL)
  {
    return NULL;
  }

  return (SedAxis_t*)(spd->getZAxis());
}


/*
 * Predicate returning @c 1 (true) if this SedPlot3D_t's "zAxis" element is
 * set.
 */
LIBSEDML_EXTERN
int
SedPlot3D_isSetZAxis(const SedPlot3D_t * spd)
{
  return (spd != NULL) ? static_cast<int>(spd->isSetZAxis()) : 0;
}


/*
 * Sets the value of the "zAxis" element of this SedPlot3D_t.
 */
LIBSEDML_EXTERN
int
SedPlot3D_setZAxis(SedPlot3D_t * spd, const SedAxis_t* zAxis)
{
  return (spd != NULL) ? spd->setZAxis(zAxis) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedAxis_t object, adds it to this SedPlot3D_t object and
 * returns the SedAxis_t object created.
 */
LIBSEDML_EXTERN
SedAxis_t*
SedPlot3D_createZAxis(SedPlot3D_t* spd)
{
  if (spd == NULL)
  {
    return NULL;
  }

  return (SedAxis_t*)(spd->createZAxis());
}


/*
 * Unsets the value of the "zAxis" element of this SedPlot3D_t.
 */
LIBSEDML_EXTERN
int
SedPlot3D_unsetZAxis(SedPlot3D_t * spd)
{
  return (spd != NULL) ? spd->unsetZAxis() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedSurface_t objects from this SedPlot3D_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedPlot3D_getListOfSurfaces(SedPlot3D_t* spd)
{
  return (spd != NULL) ? spd->getListOfSurfaces() : NULL;
}


/*
 * Get a SedSurface_t from the SedPlot3D_t.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurface(SedPlot3D_t* spd, unsigned int n)
{
  return (spd != NULL) ? spd->getSurface(n) : NULL;
}


/*
 * Get a SedSurface_t from the SedPlot3D_t based on its identifier.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceById(SedPlot3D_t* spd, const char *sid)
{
  return (spd != NULL && sid != NULL) ? spd->getSurface(sid) : NULL;
}


/*
 * Get a SedSurface_t from the SedPlot3D_t based on the XDataReference to which
 * it refers.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceByXDataReference(SedPlot3D_t* spd, const char *sid)
{
  return (spd != NULL && sid != NULL) ? spd->getSurfaceByXDataReference(sid) :
    NULL;
}


/*
 * Get a SedSurface_t from the SedPlot3D_t based on the YDataReference to which
 * it refers.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceByYDataReference(SedPlot3D_t* spd, const char *sid)
{
  return (spd != NULL && sid != NULL) ? spd->getSurfaceByYDataReference(sid) :
    NULL;
}


/*
 * Get a SedSurface_t from the SedPlot3D_t based on the ZDataReference to which
 * it refers.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceByZDataReference(SedPlot3D_t* spd, const char *sid)
{
  return (spd != NULL && sid != NULL) ? spd->getSurfaceByZDataReference(sid) :
    NULL;
}


/*
 * Get a SedSurface_t from the SedPlot3D_t based on the Style to which it
 * refers.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceByStyle(SedPlot3D_t* spd, const char *sid)
{
  return (spd != NULL && sid != NULL) ? spd->getSurfaceByStyle(sid) : NULL;
}


/*
 * Adds a copy of the given SedSurface_t to this SedPlot3D_t.
 */
LIBSEDML_EXTERN
int
SedPlot3D_addSurface(SedPlot3D_t* spd, const SedSurface_t* ss)
{
  return (spd != NULL) ? spd->addSurface(ss) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedSurface_t objects in this SedPlot3D_t.
 */
LIBSEDML_EXTERN
unsigned int
SedPlot3D_getNumSurfaces(SedPlot3D_t* spd)
{
  return (spd != NULL) ? spd->getNumSurfaces() : SEDML_INT_MAX;
}


/*
 * Creates a new SedSurface_t object, adds it to this SedPlot3D_t object and
 * returns the SedSurface_t object created.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_createSurface(SedPlot3D_t* spd)
{
  return (spd != NULL) ? spd->createSurface() : NULL;
}


/*
 * Removes the nth SedSurface_t from this SedPlot3D_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_removeSurface(SedPlot3D_t* spd, unsigned int n)
{
  return (spd != NULL) ? spd->removeSurface(n) : NULL;
}


/*
 * Removes the SedSurface_t from this SedPlot3D_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_removeSurfaceById(SedPlot3D_t* spd, const char* sid)
{
  return (spd != NULL && sid != NULL) ? spd->removeSurface(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedPlot3D_t object have been set.
 */
LIBSEDML_EXTERN
int
SedPlot3D_hasRequiredAttributes(const SedPlot3D_t * spd)
{
  return (spd != NULL) ? static_cast<int>(spd->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedPlot3D_t object have been set.
 */
LIBSEDML_EXTERN
int
SedPlot3D_hasRequiredElements(const SedPlot3D_t * spd)
{
  return (spd != NULL) ? static_cast<int>(spd->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


