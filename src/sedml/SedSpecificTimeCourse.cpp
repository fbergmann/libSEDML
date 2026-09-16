/**
 * @file SedSpecificTimeCourse.cpp
 * @brief Implementation of the SedSpecificTimeCourse class.
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
#include <sedml/SedSpecificTimeCourse.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSpecificTimeCourse using the given SEDML Level and @ p
 * version values.
 */
SedSpecificTimeCourse::SedSpecificTimeCourse(unsigned int level,
                                             unsigned int version)
  : SedSimulation(level, version)
  , mInitialTime (util_NaN())
  , mIsSetInitialTime (false)
  , mOutputTimePoints ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSpecificTimeCourse using the given SedNamespaces object @p
 * sedmlns.
 */
SedSpecificTimeCourse::SedSpecificTimeCourse(SedNamespaces *sedmlns)
  : SedSimulation(sedmlns)
  , mInitialTime (util_NaN())
  , mIsSetInitialTime (false)
  , mOutputTimePoints ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedSpecificTimeCourse.
 */
SedSpecificTimeCourse::SedSpecificTimeCourse(const SedSpecificTimeCourse& orig)
  : SedSimulation( orig )
  , mInitialTime ( orig.mInitialTime )
  , mIsSetInitialTime ( orig.mIsSetInitialTime )
  , mOutputTimePoints ( orig.mOutputTimePoints )
{
}


/*
 * Assignment operator for SedSpecificTimeCourse.
 */
SedSpecificTimeCourse&
SedSpecificTimeCourse::operator=(const SedSpecificTimeCourse& rhs)
{
  if (&rhs != this)
  {
    SedSimulation::operator=(rhs);
    mInitialTime = rhs.mInitialTime;
    mIsSetInitialTime = rhs.mIsSetInitialTime;
    mOutputTimePoints = rhs.mOutputTimePoints;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSpecificTimeCourse object.
 */
SedSpecificTimeCourse*
SedSpecificTimeCourse::clone() const
{
  return new SedSpecificTimeCourse(*this);
}


/*
 * Destructor for SedSpecificTimeCourse.
 */
SedSpecificTimeCourse::~SedSpecificTimeCourse()
{
}


/*
 * Returns the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse.
 */
double
SedSpecificTimeCourse::getInitialTime() const
{
  return mInitialTime;
}


/*
 * Returns the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse.
 */
const std::string&
SedSpecificTimeCourse::getOutputTimePoints() const
{
  return mOutputTimePoints;
}

std::vector<double>
SedSpecificTimeCourse::getOutputTimePointsVector() const
{
  std::vector<double> result;
  std::stringstream str(mOutputTimePoints);

  double value;
  while (str >> value)
      result.push_back(value);
      
  return result;
}

/*
 * Predicate returning @c true if this SedSpecificTimeCourse's "initialTime"
 * attribute is set.
 */
bool
SedSpecificTimeCourse::isSetInitialTime() const
{
  return mIsSetInitialTime;
}


/*
 * Predicate returning @c true if this SedSpecificTimeCourse's
 * "outputTimePoints" attribute is set.
 */
bool
SedSpecificTimeCourse::isSetOutputTimePoints() const
{
  return (mOutputTimePoints.empty() == false);
}


/*
 * Sets the value of the "initialTime" attribute of this SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::setInitialTime(double initialTime)
{
  mInitialTime = initialTime;
  mIsSetInitialTime = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::setOutputTimePoints(const std::string& outputTimePoints)
{
  mOutputTimePoints = outputTimePoints;
  return LIBSEDML_OPERATION_SUCCESS;
}

int
SedSpecificTimeCourse::setOutputTimePoints(const std::vector<double>& outputTimePoints)
{
  std::stringstream str;
  for (double v : outputTimePoints)
    str << v << ' ';
  return setOutputTimePoints(str.str());
}

/*
 * Unsets the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::unsetInitialTime()
{
  mInitialTime = util_NaN();
  mIsSetInitialTime = false;

  if (isSetInitialTime() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::unsetOutputTimePoints()
{
  mOutputTimePoints.erase();

  if (mOutputTimePoints.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedSpecificTimeCourse object.
 */
const std::string&
SedSpecificTimeCourse::getElementName() const
{
  static const string name = "specificTimeCourse";
  return name;
}


/*
 * Returns the libSEDML type code for this SedSpecificTimeCourse object.
 */
int
SedSpecificTimeCourse::getTypeCode() const
{
  return SEDML_SIMULATION_SPECIFICTIMECOURSE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedSpecificTimeCourse object have been set.
 */
bool
SedSpecificTimeCourse::hasRequiredAttributes() const
{
  bool allPresent = SedSimulation::hasRequiredAttributes();

  if (isSetInitialTime() == false)
  {
    allPresent = false;
  }

  if (isSetOutputTimePoints() == false)
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
SedSpecificTimeCourse::writeElements(XMLOutputStream& stream) const
{
  SedSimulation::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedSpecificTimeCourse::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSpecificTimeCourse::setSedDocument(SedDocument* d)
{
  SedSimulation::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::getAttribute(const std::string& attributeName,
                                    bool& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::getAttribute(const std::string& attributeName,
                                    int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::getAttribute(const std::string& attributeName,
                                    double& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "initialTime")
  {
    value = getInitialTime();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::getAttribute(const std::string& attributeName,
                                    unsigned int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::getAttribute(const std::string& attributeName,
                                    std::string& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "outputTimePoints")
  {
    value = getOutputTimePoints();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedSpecificTimeCourse's attribute
 * "attributeName" is set.
 */
bool
SedSpecificTimeCourse::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedSimulation::isSetAttribute(attributeName);

  if (attributeName == "initialTime")
  {
    value = isSetInitialTime();
  }
  else if (attributeName == "outputTimePoints")
  {
    value = isSetOutputTimePoints();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::setAttribute(const std::string& attributeName,
                                    bool value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::setAttribute(const std::string& attributeName,
                                    int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::setAttribute(const std::string& attributeName,
                                    double value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  if (attributeName == "initialTime")
  {
    return_value = setInitialTime(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::setAttribute(const std::string& attributeName,
                                    unsigned int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::setAttribute(const std::string& attributeName,
                                    const std::string& value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  if (attributeName == "outputTimePoints")
  {
    return_value = setOutputTimePoints(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedSpecificTimeCourse.
 */
int
SedSpecificTimeCourse::unsetAttribute(const std::string& attributeName)
{
  int value = SedSimulation::unsetAttribute(attributeName);

  if (attributeName == "initialTime")
  {
    value = unsetInitialTime();
  }
  else if (attributeName == "outputTimePoints")
  {
    value = unsetOutputTimePoints();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedSpecificTimeCourse::createObject(XMLInputStream& stream)
{
  SedBase* obj = SedSimulation::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSpecificTimeCourse::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedSimulation::addExpectedAttributes(attributes);

  attributes.add("initialTime");

  attributes.add("outputTimePoints");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSpecificTimeCourse::readAttributes(const XMLAttributes& attributes,
                                      const ExpectedAttributes&
                                        expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedSimulation::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedUnknown, level, version, details, getLine(),
          getColumn());
      }
    }
  }

  // 
  // initialTime double (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetInitialTime = attributes.readInto("initialTime", mInitialTime);

  if ( mIsSetInitialTime == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'initialTime' from the "
        "<SedSpecificTimeCourse> element must be an integer.";
      log->logError(SedUnknown, level, version, message, getLine(),
        getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'initialTime' is missing from the "
        "<SedSpecificTimeCourse> element.";
      log->logError(SedUnknown, level, version, message, getLine(),
        getColumn());
    }
  }

  // 
  // outputTimePoints string (use = "required" )
  // 

  assigned = attributes.readInto("outputTimePoints", mOutputTimePoints);

  if (assigned == true)
  {
    if (mOutputTimePoints.empty() == true)
    {
      logEmptyString(mOutputTimePoints, level, version,
        "<SedSpecificTimeCourse>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'outputTimePoints' is missing from "
        "the <SedSpecificTimeCourse> element.";
      log->logError(SedUnknown, level, version, message, getLine(),
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
SedSpecificTimeCourse::writeAttributes(XMLOutputStream& stream) const
{
  SedSimulation::writeAttributes(stream);

  if (isSetInitialTime() == true)
  {
    stream.writeAttribute("initialTime", getPrefix(), mInitialTime);
  }

  if (isSetOutputTimePoints() == true)
  {
    stream.writeAttribute("outputTimePoints", getPrefix(), mOutputTimePoints);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSpecificTimeCourse_t using the given SEDML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedSpecificTimeCourse_t *
SedSpecificTimeCourse_create(unsigned int level, unsigned int version)
{
  return new SedSpecificTimeCourse(level, version);
}


/*
 * Creates and returns a deep copy of this SedSpecificTimeCourse_t object.
 */
LIBSEDML_EXTERN
SedSpecificTimeCourse_t*
SedSpecificTimeCourse_clone(const SedSpecificTimeCourse_t* sstc)
{
  if (sstc != NULL)
  {
    return static_cast<SedSpecificTimeCourse_t*>(sstc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSpecificTimeCourse_t object.
 */
LIBSEDML_EXTERN
void
SedSpecificTimeCourse_free(SedSpecificTimeCourse_t* sstc)
{
  if (sstc != NULL)
  {
    delete sstc;
  }
}


/*
 * Returns the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse_t.
 */
LIBSEDML_EXTERN
double
SedSpecificTimeCourse_getInitialTime(const SedSpecificTimeCourse_t * sstc)
{
  return (sstc != NULL) ? sstc->getInitialTime() : util_NaN();
}


/*
 * Returns the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse_t.
 */
LIBSEDML_EXTERN
char *
SedSpecificTimeCourse_getOutputTimePoints(const SedSpecificTimeCourse_t * sstc)
{
  if (sstc == NULL)
  {
    return NULL;
  }

  return sstc->getOutputTimePoints().empty() ? NULL :
    safe_strdup(sstc->getOutputTimePoints().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedSpecificTimeCourse_t's
 * "initialTime" attribute is set.
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_isSetInitialTime(const SedSpecificTimeCourse_t * sstc)
{
  return (sstc != NULL) ? static_cast<int>(sstc->isSetInitialTime()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSpecificTimeCourse_t's
 * "outputTimePoints" attribute is set.
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_isSetOutputTimePoints(const SedSpecificTimeCourse_t *
  sstc)
{
  return (sstc != NULL) ? static_cast<int>(sstc->isSetOutputTimePoints()) : 0;
}


/*
 * Sets the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_setInitialTime(SedSpecificTimeCourse_t * sstc,
                                     double initialTime)
{
  return (sstc != NULL) ? sstc->setInitialTime(initialTime) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_setOutputTimePoints(SedSpecificTimeCourse_t * sstc,
                                          const char * outputTimePoints)
{
  return (sstc != NULL) ? sstc->setOutputTimePoints(outputTimePoints) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_unsetInitialTime(SedSpecificTimeCourse_t * sstc)
{
  return (sstc != NULL) ? sstc->unsetInitialTime() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_unsetOutputTimePoints(SedSpecificTimeCourse_t * sstc)
{
  return (sstc != NULL) ? sstc->unsetOutputTimePoints() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSpecificTimeCourse_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_hasRequiredAttributes(const SedSpecificTimeCourse_t *
  sstc)
{
  return (sstc != NULL) ? static_cast<int>(sstc->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


