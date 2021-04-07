/**
 * @file SedPlot2D.cpp
 * @brief Implementation of the SedPlot2D class.
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
#include <sedml/SedPlot2D.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedCurve.h>
#include <sedml/SedShadedArea.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedPlot2D using the given SED-ML Level and @ p version values.
 */
SedPlot2D::SedPlot2D(unsigned int level, unsigned int version)
  : SedPlot(level, version)
  , mAbstractCurves (level, version)
  , mRightYAxis (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedPlot2D using the given SedNamespaces object @p sedmlns.
 */
SedPlot2D::SedPlot2D(SedNamespaces *sedmlns)
  : SedPlot(sedmlns)
  , mAbstractCurves (sedmlns)
  , mRightYAxis (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedPlot2D.
 */
SedPlot2D::SedPlot2D(const SedPlot2D& orig)
  : SedPlot( orig )
  , mAbstractCurves ( orig.mAbstractCurves )
  , mRightYAxis ( NULL )
{
  if (orig.mRightYAxis != NULL)
  {
    mRightYAxis = orig.mRightYAxis->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedPlot2D.
 */
SedPlot2D&
SedPlot2D::operator=(const SedPlot2D& rhs)
{
  if (&rhs != this)
  {
    SedPlot::operator=(rhs);
    mAbstractCurves = rhs.mAbstractCurves;
    delete mRightYAxis;
    if (rhs.mRightYAxis != NULL)
    {
      mRightYAxis = rhs.mRightYAxis->clone();
    }
    else
    {
      mRightYAxis = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedPlot2D object.
 */
SedPlot2D*
SedPlot2D::clone() const
{
  return new SedPlot2D(*this);
}


/*
 * Destructor for SedPlot2D.
 */
SedPlot2D::~SedPlot2D()
{
  delete mRightYAxis;
  mRightYAxis = NULL;
}


/*
 * Returns the value of the "rightYAxis" element of this SedPlot2D.
 */
const SedAxis*
SedPlot2D::getRightYAxis() const
{
  return mRightYAxis;
}


/*
 * Returns the value of the "rightYAxis" element of this SedPlot2D.
 */
SedAxis*
SedPlot2D::getRightYAxis()
{
  return mRightYAxis;
}


/*
 * Predicate returning @c true if this SedPlot2D's "rightYAxis" element is set.
 */
bool
SedPlot2D::isSetRightYAxis() const
{
  return (mRightYAxis != NULL);
}


/*
 * Sets the value of the "rightYAxis" element of this SedPlot2D.
 */
int
SedPlot2D::setRightYAxis(const SedAxis* rightYAxis)
{
  if (mRightYAxis == rightYAxis)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (rightYAxis == NULL)
  {
    delete mRightYAxis;
    mRightYAxis = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mRightYAxis;
    mRightYAxis = (rightYAxis != NULL) ? rightYAxis->clone() : NULL;
    if (mRightYAxis != NULL)
    {
      mRightYAxis->setElementName("rightYAxis");
      mRightYAxis->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedAxis object, adds it to this SedPlot2D object and returns
 * the SedAxis object created.
 */
SedAxis*
SedPlot2D::createRightYAxis()
{
  if (mRightYAxis != NULL)
  {
    delete mRightYAxis;
  }

  mRightYAxis = new SedAxis(getSedNamespaces());

  mRightYAxis->setElementName("rightYAxis");

  connectToChild();

  return mRightYAxis;
}


/*
 * Unsets the value of the "rightYAxis" element of this SedPlot2D.
 */
int
SedPlot2D::unsetRightYAxis()
{
  delete mRightYAxis;
  mRightYAxis = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfCurves from this SedPlot2D.
 */
const SedListOfCurves*
SedPlot2D::getListOfCurves() const
{
  return &mAbstractCurves;
}


/*
 * Returns the SedListOfCurves from this SedPlot2D.
 */
SedListOfCurves*
SedPlot2D::getListOfCurves()
{
  return &mAbstractCurves;
}


/*
 * Get a SedAbstractCurve from the SedPlot2D.
 */
SedAbstractCurve*
SedPlot2D::getCurve(unsigned int n)
{
  return mAbstractCurves.get(n);
}


/*
 * Get a SedAbstractCurve from the SedPlot2D.
 */
const SedAbstractCurve*
SedPlot2D::getCurve(unsigned int n) const
{
  return mAbstractCurves.get(n);
}


/*
 * Get a SedAbstractCurve from the SedPlot2D based on its identifier.
 */
SedAbstractCurve*
SedPlot2D::getCurve(const std::string& sid)
{
  return mAbstractCurves.get(sid);
}


/*
 * Get a SedAbstractCurve from the SedPlot2D based on its identifier.
 */
const SedAbstractCurve*
SedPlot2D::getCurve(const std::string& sid) const
{
  return mAbstractCurves.get(sid);
}


/*
 * Get a SedAbstractCurve from the SedPlot2D based on the Style to which it
 * refers.
 */
const SedAbstractCurve*
SedPlot2D::getCurveByStyle(const std::string& sid) const
{
  return mAbstractCurves.getByStyle(sid);
}


/*
 * Get a SedAbstractCurve from the SedPlot2D based on the Style to which it
 * refers.
 */
SedAbstractCurve*
SedPlot2D::getCurveByStyle(const std::string& sid)
{
  return mAbstractCurves.getByStyle(sid);
}


/*
 * Get a SedAbstractCurve from the SedPlot2D based on the XDataReference to
 * which it refers.
 */
const SedAbstractCurve*
SedPlot2D::getCurveByXDataReference(const std::string& sid) const
{
  return mAbstractCurves.getByXDataReference(sid);
}


/*
 * Get a SedAbstractCurve from the SedPlot2D based on the XDataReference to
 * which it refers.
 */
SedAbstractCurve*
SedPlot2D::getCurveByXDataReference(const std::string& sid)
{
  return mAbstractCurves.getByXDataReference(sid);
}


/*
 * Adds a copy of the given SedAbstractCurve to this SedPlot2D.
 */
int
SedPlot2D::addCurve(const SedAbstractCurve* sac)
{
  if (sac == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sac->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sac->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sac->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sac)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sac->isSetId() && (mAbstractCurves.get(sac->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mAbstractCurves.append(sac);
  }
}


/*
 * Get the number of SedAbstractCurve objects in this SedPlot2D.
 */
unsigned int
SedPlot2D::getNumCurves() const
{
  return mAbstractCurves.size();
}


/*
 * Creates a new SedCurve object, adds it to this SedPlot2D object and returns
 * the SedCurve object created.
 */
SedCurve*
SedPlot2D::createCurve()
{
  SedCurve* sc = NULL;

  try
  {
    sc = new SedCurve(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sc != NULL)
  {
    mAbstractCurves.appendAndOwn(sc);
  }

  return sc;
}


/*
 * Creates a new SedShadedArea object, adds it to this SedPlot2D object and
 * returns the SedShadedArea object created.
 */
SedShadedArea*
SedPlot2D::createShadedArea()
{
  SedShadedArea* ssa = NULL;

  try
  {
    ssa = new SedShadedArea(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ssa != NULL)
  {
    mAbstractCurves.appendAndOwn(ssa);
  }

  return ssa;
}


/*
 * Removes the nth SedAbstractCurve from this SedPlot2D and returns a pointer
 * to it.
 */
SedAbstractCurve*
SedPlot2D::removeCurve(unsigned int n)
{
  return mAbstractCurves.remove(n);
}


/*
 * Removes the SedAbstractCurve from this SedPlot2D based on its identifier and
 * returns a pointer to it.
 */
SedAbstractCurve*
SedPlot2D::removeCurve(const std::string& sid)
{
  return mAbstractCurves.remove(sid);
}


/*
 * Returns the XML element name of this SedPlot2D object.
 */
const std::string&
SedPlot2D::getElementName() const
{
  static const string name = "plot2D";
  return name;
}


/*
 * Returns the libSEDML type code for this SedPlot2D object.
 */
int
SedPlot2D::getTypeCode() const
{
  return SEDML_OUTPUT_PLOT2D;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedPlot2D object have been set.
 */
bool
SedPlot2D::hasRequiredAttributes() const
{
  bool allPresent = SedPlot::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SedPlot2D
 * object have been set.
 */
bool
SedPlot2D::hasRequiredElements() const
{
  bool allPresent = SedPlot::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedPlot2D::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedPlot::writeElements(stream);

  if (isSetRightYAxis() == true)
  {
    mRightYAxis->write(stream);
  }

  if (getNumCurves() > 0)
  {
    mAbstractCurves.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedPlot2D::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedPlot2D::setSedDocument(SedDocument* d)
{
  SedPlot::setSedDocument(d);

  if (mRightYAxis != NULL)
  {
    mRightYAxis->setSedDocument(d);
  }

  mAbstractCurves.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedPlot2D::connectToChild()
{
  SedPlot::connectToChild();

  if (mRightYAxis != NULL)
  {
    mRightYAxis->connectToParent(this);
  }

  mAbstractCurves.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedPlot2D's attribute "attributeName" is
 * set.
 */
bool
SedPlot2D::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedPlot::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedPlot2D.
 */
int
SedPlot2D::unsetAttribute(const std::string& attributeName)
{
  int value = SedPlot::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedPlot2D.
 */
SedBase*
SedPlot2D::createChildObject(const std::string& elementName)
{
  SedPlot* obj = NULL;

  if (elementName == "rightYAxis")
  {
    return createRightYAxis();
  }
  else if (elementName == "curve")
  {
    return createCurve();
  }
  else if (elementName == "shadedArea")
  {
    return createShadedArea();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedPlot2D.
 */
int
SedPlot2D::addChildObject(const std::string& elementName,
                          const SedBase* element)
{
  if (elementName == "rightYAxis" && element->getTypeCode() == SEDML_AXIS)
  {
    return setRightYAxis((const SedAxis*)(element));
  }
  else if (elementName == "curve" && element->getTypeCode() ==
    SEDML_OUTPUT_CURVE)
  {
    return addCurve((const SedAbstractCurve*)(element));
  }
  else if (elementName == "shadedArea" && element->getTypeCode() ==
    SEDML_SHADEDAREA)
  {
    return addCurve((const SedAbstractCurve*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedPlot2D.
 */
SedBase*
SedPlot2D::removeChildObject(const std::string& elementName,
                             const std::string& id)
{
  if (elementName == "rightYAxis")
  {
    SedAxis * obj = mRightYAxis;
    mRightYAxis = NULL; return obj;
  }
  else if (elementName == "curve")
  {
    return removeCurve(id);
  }
  else if (elementName == "shadedArea")
  {
    return removeCurve(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedPlot2D.
 */
unsigned int
SedPlot2D::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "rightYAxis")
  {
    if (isSetRightYAxis())
    {
      return 1;
    }
  }
  else if (elementName == "abstractCurve")
  {
    return getNumCurves();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedPlot2D.
 */
SedBase*
SedPlot2D::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "rightYAxis")
  {
    return getRightYAxis();
  }
  else if (elementName == "abstractCurve")
  {
    return getCurve(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedPlot2D::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mRightYAxis != NULL)
  {
    if (mRightYAxis->getId() == id)
    {
      return mRightYAxis;
    }

    obj = mRightYAxis->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mAbstractCurves.getElementBySId(id);

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
SedPlot2D::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  SED_ADD_FILTERED_POINTER(ret, sublist, mRightYAxis, filter);

  SED_ADD_FILTERED_LIST(ret, sublist, mAbstractCurves, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedPlot2D::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = SedPlot::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "rightYAxis")
  {
    if (getErrorLog() && isSetRightYAxis())
    {
      getErrorLog()->logError(SedmlPlot2DAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mRightYAxis;
    mRightYAxis = new SedAxis(getSedNamespaces());
    mRightYAxis->setElementName(name);
    obj = mRightYAxis;
  }
  else if (name == "listOfCurves")
  {
    if (getErrorLog() && mAbstractCurves.size() != 0)
    {
      getErrorLog()->logError(SedmlPlot2DAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mAbstractCurves;
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
SedPlot2D::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
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
SedPlot2D::readAttributes(
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
SedPlot2D::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedPlot::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedPlot2D_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedPlot2D_t *
SedPlot2D_create(unsigned int level, unsigned int version)
{
  return new SedPlot2D(level, version);
}


/*
 * Creates and returns a deep copy of this SedPlot2D_t object.
 */
LIBSEDML_EXTERN
SedPlot2D_t*
SedPlot2D_clone(const SedPlot2D_t* spd)
{
  if (spd != NULL)
  {
    return static_cast<SedPlot2D_t*>(spd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedPlot2D_t object.
 */
LIBSEDML_EXTERN
void
SedPlot2D_free(SedPlot2D_t* spd)
{
  if (spd != NULL)
  {
    delete spd;
  }
}


/*
 * Returns the value of the "rightYAxis" element of this SedPlot2D_t.
 */
LIBSEDML_EXTERN
const SedAxis_t*
SedPlot2D_getRightYAxis(const SedPlot2D_t * spd)
{
  if (spd == NULL)
  {
    return NULL;
  }

  return (SedAxis_t*)(spd->getRightYAxis());
}


/*
 * Predicate returning @c 1 (true) if this SedPlot2D_t's "rightYAxis" element
 * is set.
 */
LIBSEDML_EXTERN
int
SedPlot2D_isSetRightYAxis(const SedPlot2D_t * spd)
{
  return (spd != NULL) ? static_cast<int>(spd->isSetRightYAxis()) : 0;
}


/*
 * Sets the value of the "rightYAxis" element of this SedPlot2D_t.
 */
LIBSEDML_EXTERN
int
SedPlot2D_setRightYAxis(SedPlot2D_t * spd, const SedAxis_t* rightYAxis)
{
  return (spd != NULL) ? spd->setRightYAxis(rightYAxis) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedAxis_t object, adds it to this SedPlot2D_t object and
 * returns the SedAxis_t object created.
 */
LIBSEDML_EXTERN
SedAxis_t*
SedPlot2D_createRightYAxis(SedPlot2D_t* spd)
{
  if (spd == NULL)
  {
    return NULL;
  }

  return (SedAxis_t*)(spd->createRightYAxis());
}


/*
 * Unsets the value of the "rightYAxis" element of this SedPlot2D_t.
 */
LIBSEDML_EXTERN
int
SedPlot2D_unsetRightYAxis(SedPlot2D_t * spd)
{
  return (spd != NULL) ? spd->unsetRightYAxis() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedAbstractCurve_t objects from this
 * SedPlot2D_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedPlot2D_getListOfCurves(SedPlot2D_t* spd)
{
  return (spd != NULL) ? spd->getListOfCurves() : NULL;
}


/*
 * Get a SedAbstractCurve_t from the SedPlot2D_t.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_getCurve(SedPlot2D_t* spd, unsigned int n)
{
  return (spd != NULL) ? spd->getCurve(n) : NULL;
}


/*
 * Get a SedAbstractCurve_t from the SedPlot2D_t based on its identifier.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_getCurveById(SedPlot2D_t* spd, const char *sid)
{
  return (spd != NULL && sid != NULL) ? spd->getCurve(sid) : NULL;
}


/*
 * Get a SedAbstractCurve_t from the SedPlot2D_t based on the Style to which it
 * refers.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_getCurveByStyle(SedPlot2D_t* spd, const char *sid)
{
  return (spd != NULL && sid != NULL) ? spd->getCurveByStyle(sid) :
    NULL;
}


/*
 * Get a SedAbstractCurve_t from the SedPlot2D_t based on the XDataReference to
 * which it refers.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_getCurveByXDataReference(SedPlot2D_t* spd, const char *sid)
{
  return (spd != NULL && sid != NULL) ?
    spd->getCurveByXDataReference(sid) : NULL;
}


/*
 * Adds a copy of the given SedAbstractCurve_t to this SedPlot2D_t.
 */
LIBSEDML_EXTERN
int
SedPlot2D_addCurve(SedPlot2D_t* spd, const SedAbstractCurve_t* sac)
{
  return (spd != NULL) ? spd->addCurve(sac) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedAbstractCurve_t objects in this SedPlot2D_t.
 */
LIBSEDML_EXTERN
unsigned int
SedPlot2D_getNumCurves(SedPlot2D_t* spd)
{
  return (spd != NULL) ? spd->getNumCurves() : SEDML_INT_MAX;
}


/*
 * Creates a new SedCurve_t object, adds it to this SedPlot2D_t object and
 * returns the SedCurve_t object created.
 */
LIBSEDML_EXTERN
SedCurve_t*
SedPlot2D_createCurve(SedPlot2D_t* spd)
{
  return (spd != NULL) ? spd->createCurve() : NULL;
}


/*
 * Creates a new SedShadedArea_t object, adds it to this SedPlot2D_t object and
 * returns the SedShadedArea_t object created.
 */
LIBSEDML_EXTERN
SedShadedArea_t*
SedPlot2D_createShadedArea(SedPlot2D_t* spd)
{
  return (spd != NULL) ? spd->createShadedArea() : NULL;
}


/*
 * Removes the nth SedAbstractCurve_t from this SedPlot2D_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_removeCurve(SedPlot2D_t* spd, unsigned int n)
{
  return (spd != NULL) ? spd->removeCurve(n) : NULL;
}


/*
 * Removes the SedAbstractCurve_t from this SedPlot2D_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_removeCurveById(SedPlot2D_t* spd, const char* sid)
{
  return (spd != NULL && sid != NULL) ? spd->removeCurve(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedPlot2D_t object have been set.
 */
LIBSEDML_EXTERN
int
SedPlot2D_hasRequiredAttributes(const SedPlot2D_t * spd)
{
  return (spd != NULL) ? static_cast<int>(spd->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedPlot2D_t object have been set.
 */
LIBSEDML_EXTERN
int
SedPlot2D_hasRequiredElements(const SedPlot2D_t * spd)
{
  return (spd != NULL) ? static_cast<int>(spd->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


