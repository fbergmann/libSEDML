/**
 * @file SedUniformTimeCourse.cpp
 * @brief Implementation of the SedUniformTimeCourse class.
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
#include <sedml/SedUniformTimeCourse.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedUniformTimeCourse using the given SED-ML Level and @ p
 * version values.
 */
SedUniformTimeCourse::SedUniformTimeCourse(unsigned int level,
                                           unsigned int version)
  : SedSimulation(level, version)
  , mInitialTime (util_NaN())
  , mIsSetInitialTime (false)
  , mOutputStartTime (util_NaN())
  , mIsSetOutputStartTime (false)
  , mOutputEndTime (util_NaN())
  , mIsSetOutputEndTime (false)
  , mNumberOfSteps (SEDML_INT_MAX)
  , mIsSetNumberOfSteps (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedUniformTimeCourse using the given SedNamespaces object @p
 * sedmlns.
 */
SedUniformTimeCourse::SedUniformTimeCourse(SedNamespaces *sedmlns)
  : SedSimulation(sedmlns)
  , mInitialTime (util_NaN())
  , mIsSetInitialTime (false)
  , mOutputStartTime (util_NaN())
  , mIsSetOutputStartTime (false)
  , mOutputEndTime (util_NaN())
  , mIsSetOutputEndTime (false)
  , mNumberOfSteps (SEDML_INT_MAX)
  , mIsSetNumberOfSteps (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedUniformTimeCourse.
 */
SedUniformTimeCourse::SedUniformTimeCourse(const SedUniformTimeCourse& orig)
  : SedSimulation( orig )
  , mInitialTime ( orig.mInitialTime )
  , mIsSetInitialTime ( orig.mIsSetInitialTime )
  , mOutputStartTime ( orig.mOutputStartTime )
  , mIsSetOutputStartTime ( orig.mIsSetOutputStartTime )
  , mOutputEndTime ( orig.mOutputEndTime )
  , mIsSetOutputEndTime ( orig.mIsSetOutputEndTime )
  , mNumberOfSteps ( orig.mNumberOfSteps )
  , mIsSetNumberOfSteps ( orig.mIsSetNumberOfSteps )
{
}


/*
 * Assignment operator for SedUniformTimeCourse.
 */
SedUniformTimeCourse&
SedUniformTimeCourse::operator=(const SedUniformTimeCourse& rhs)
{
  if (&rhs != this)
  {
    SedSimulation::operator=(rhs);
    mInitialTime = rhs.mInitialTime;
    mIsSetInitialTime = rhs.mIsSetInitialTime;
    mOutputStartTime = rhs.mOutputStartTime;
    mIsSetOutputStartTime = rhs.mIsSetOutputStartTime;
    mOutputEndTime = rhs.mOutputEndTime;
    mIsSetOutputEndTime = rhs.mIsSetOutputEndTime;
    mNumberOfSteps = rhs.mNumberOfSteps;
    mIsSetNumberOfSteps = rhs.mIsSetNumberOfSteps;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedUniformTimeCourse object.
 */
SedUniformTimeCourse*
SedUniformTimeCourse::clone() const
{
  return new SedUniformTimeCourse(*this);
}


/*
 * Destructor for SedUniformTimeCourse.
 */
SedUniformTimeCourse::~SedUniformTimeCourse()
{
}


/*
 * Returns the value of the "initialTime" attribute of this
 * SedUniformTimeCourse.
 */
double
SedUniformTimeCourse::getInitialTime() const
{
  return mInitialTime;
}


/*
 * Returns the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse.
 */
double
SedUniformTimeCourse::getOutputStartTime() const
{
  return mOutputStartTime;
}


/*
 * Returns the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse.
 */
double
SedUniformTimeCourse::getOutputEndTime() const
{
  return mOutputEndTime;
}


/*
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::getNumberOfPoints() const
{
  return mNumberOfSteps;
}


/*
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::getNumberOfSteps() const
{
  return mNumberOfSteps;
}


/*
 * Predicate returning @c true if this SedUniformTimeCourse's "initialTime"
 * attribute is set.
 */
bool
SedUniformTimeCourse::isSetInitialTime() const
{
  return mIsSetInitialTime;
}


/*
 * Predicate returning @c true if this SedUniformTimeCourse's "outputStartTime"
 * attribute is set.
 */
bool
SedUniformTimeCourse::isSetOutputStartTime() const
{
  return mIsSetOutputStartTime;
}


/*
 * Predicate returning @c true if this SedUniformTimeCourse's "outputEndTime"
 * attribute is set.
 */
bool
SedUniformTimeCourse::isSetOutputEndTime() const
{
  return mIsSetOutputEndTime;
}


/*
 * Predicate returning @c true if this SedUniformTimeCourse's "numberOfSteps"
 * attribute is set.
 */
bool
SedUniformTimeCourse::isSetNumberOfPoints() const
{
  return mIsSetNumberOfSteps;
}


/*
 * Predicate returning @c true if this SedUniformTimeCourse's "numberOfSteps"
 * attribute is set.
 */
bool
SedUniformTimeCourse::isSetNumberOfSteps() const
{
  return mIsSetNumberOfSteps;
}


/*
 * Sets the value of the "initialTime" attribute of this SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setInitialTime(double initialTime)
{
  mInitialTime = initialTime;
  mIsSetInitialTime = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setOutputStartTime(double outputStartTime)
{
  mOutputStartTime = outputStartTime;
  mIsSetOutputStartTime = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setOutputEndTime(double outputEndTime)
{
  mOutputEndTime = outputEndTime;
  mIsSetOutputEndTime = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "numberOfPoints" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setNumberOfPoints(int numberOfSteps)
{
  mNumberOfSteps = numberOfSteps;
  mIsSetNumberOfSteps = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setNumberOfSteps(int numberOfSteps)
{
  mNumberOfSteps = numberOfSteps;
  mIsSetNumberOfSteps = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "initialTime" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::unsetInitialTime()
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
 * Unsets the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::unsetOutputStartTime()
{
  mOutputStartTime = util_NaN();
  mIsSetOutputStartTime = false;

  if (isSetOutputStartTime() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::unsetOutputEndTime()
{
  mOutputEndTime = util_NaN();
  mIsSetOutputEndTime = false;

  if (isSetOutputEndTime() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::unsetNumberOfPoints()
{
  mNumberOfSteps= SEDML_INT_MAX;
  mIsSetNumberOfSteps= false;

  if (isSetNumberOfSteps() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::unsetNumberOfSteps()
{
  mNumberOfSteps = SEDML_INT_MAX;
  mIsSetNumberOfSteps = false;

  if (isSetNumberOfSteps() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedUniformTimeCourse object.
 */
const std::string&
SedUniformTimeCourse::getElementName() const
{
  static const string name = "uniformTimeCourse";
  return name;
}


/*
 * Returns the libSEDML type code for this SedUniformTimeCourse object.
 */
int
SedUniformTimeCourse::getTypeCode() const
{
  return SEDML_SIMULATION_UNIFORMTIMECOURSE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedUniformTimeCourse object have been set.
 */
bool
SedUniformTimeCourse::hasRequiredAttributes() const
{
  bool allPresent = SedSimulation::hasRequiredAttributes();

  if (isSetInitialTime() == false)
  {
    allPresent = false;
  }

  if (isSetOutputStartTime() == false)
  {
    allPresent = false;
  }

  if (isSetOutputEndTime() == false)
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
SedUniformTimeCourse::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedSimulation::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedUniformTimeCourse::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedUniformTimeCourse::setSedDocument(SedDocument* d)
{
  SedSimulation::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::getAttribute(const std::string& attributeName,
                                   bool& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::getAttribute(const std::string& attributeName,
                                   int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "numberOfPoints" || attributeName == "numberOfSteps")
  {
    value = getNumberOfSteps();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "outputStartTime")
  {
    value = getOutputStartTime();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "outputEndTime")
  {
    value = getOutputEndTime();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::getAttribute(const std::string& attributeName,
                                   unsigned int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::getAttribute(const std::string& attributeName,
                                   std::string& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedUniformTimeCourse's attribute
 * "attributeName" is set.
 */
bool
SedUniformTimeCourse::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedSimulation::isSetAttribute(attributeName);

  if (attributeName == "initialTime")
  {
    value = isSetInitialTime();
  }
  else if (attributeName == "outputStartTime")
  {
    value = isSetOutputStartTime();
  }
  else if (attributeName == "outputEndTime")
  {
    value = isSetOutputEndTime();
  }
  else if (attributeName == "numberOfPoints" || attributeName == "numberOfSteps")
  {
    value = isSetNumberOfSteps();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setAttribute(const std::string& attributeName,
                                   bool value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setAttribute(const std::string& attributeName,
                                   int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  if (attributeName == "numberOfPoints" || attributeName == "numberOfSteps")
  {
    return_value = setNumberOfSteps(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setAttribute(const std::string& attributeName,
                                   double value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  if (attributeName == "initialTime")
  {
    return_value = setInitialTime(value);
  }
  else if (attributeName == "outputStartTime")
  {
    return_value = setOutputStartTime(value);
  }
  else if (attributeName == "outputEndTime")
  {
    return_value = setOutputEndTime(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setAttribute(const std::string& attributeName,
                                   unsigned int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::setAttribute(const std::string& attributeName,
                                   const std::string& value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedUniformTimeCourse.
 */
int
SedUniformTimeCourse::unsetAttribute(const std::string& attributeName)
{
  int value = SedSimulation::unsetAttribute(attributeName);

  if (attributeName == "initialTime")
  {
    value = unsetInitialTime();
  }
  else if (attributeName == "outputStartTime")
  {
    value = unsetOutputStartTime();
  }
  else if (attributeName == "outputEndTime")
  {
    value = unsetOutputEndTime();
  }
  else if (attributeName == "numberOfPoints" || attributeName == "numberOfSteps")
  {
    value = unsetNumberOfSteps();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedUniformTimeCourse::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
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
SedUniformTimeCourse::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedSimulation::addExpectedAttributes(attributes);

  attributes.add("initialTime");

  attributes.add("outputStartTime");

  attributes.add("outputEndTime");

  attributes.add("numberOfPoints");

  if (getVersion() >= 4 || getLevel() > 1) {
      attributes.add("numberOfSteps");
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedUniformTimeCourse::readAttributes(
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
        log->logError(SedmlUniformTimeCourseAllowedAttributes, level, version,
          details, getLine(), getColumn());
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
        "<SedUniformTimeCourse> element must be an integer.";
      log->logError(SedmlUniformTimeCourseInitialTimeMustBeDouble, level,
        version, message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'initialTime' is missing from the "
        "<SedUniformTimeCourse> element.";
      log->logError(SedmlUniformTimeCourseAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // outputStartTime double (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetOutputStartTime = attributes.readInto("outputStartTime",
    mOutputStartTime);

  if ( mIsSetOutputStartTime == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'outputStartTime' from the "
        "<SedUniformTimeCourse> element must be an integer.";
      log->logError(SedmlUniformTimeCourseOutputStartTimeMustBeDouble, level,
        version, message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'outputStartTime' is missing from "
        "the <SedUniformTimeCourse> element.";
      log->logError(SedmlUniformTimeCourseAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // outputEndTime double (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetOutputEndTime = attributes.readInto("outputEndTime", mOutputEndTime);

  if ( mIsSetOutputEndTime == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'outputEndTime' from the "
        "<SedUniformTimeCourse> element must be an integer.";
      log->logError(SedmlUniformTimeCourseOutputEndTimeMustBeDouble, level,
        version, message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'outputEndTime' is missing from "
        "the <SedUniformTimeCourse> element.";
      log->logError(SedmlUniformTimeCourseAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // numberOfSteps int (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetNumberOfSteps = attributes.readInto("numberOfSteps", mNumberOfSteps);

  if (!mIsSetNumberOfSteps) {
      mIsSetNumberOfSteps = attributes.readInto("numberOfPoints", mNumberOfSteps);
  }

  if ( mIsSetNumberOfSteps == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'numberOfSteps' from the "
        "<SedUniformTimeCourse> element must be an integer.";
      log->logError(SedmlUniformTimeCourseNumberOfStepsMustBeInteger, level,
        version, message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedUniformTimeCourse::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedSimulation::writeAttributes(stream);

  if (isSetInitialTime() == true)
  {
    stream.writeAttribute("initialTime", getPrefix(), mInitialTime);
  }

  if (isSetOutputStartTime() == true)
  {
    stream.writeAttribute("outputStartTime", getPrefix(), mOutputStartTime);
  }

  if (isSetOutputEndTime() == true)
  {
    stream.writeAttribute("outputEndTime", getPrefix(), mOutputEndTime);
  }

  if (isSetNumberOfSteps() == true)
  {
      if (getVersion() >= 4 || getLevel() > 1) {
          stream.writeAttribute("numberOfSteps", getPrefix(), mNumberOfSteps);
      }
      else {
          stream.writeAttribute("numberOfPoints", getPrefix(), mNumberOfSteps);
      }
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedUniformTimeCourse_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedUniformTimeCourse_t *
SedUniformTimeCourse_create(unsigned int level, unsigned int version)
{
  return new SedUniformTimeCourse(level, version);
}


/*
 * Creates and returns a deep copy of this SedUniformTimeCourse_t object.
 */
LIBSEDML_EXTERN
SedUniformTimeCourse_t*
SedUniformTimeCourse_clone(const SedUniformTimeCourse_t* sutc)
{
  if (sutc != NULL)
  {
    return static_cast<SedUniformTimeCourse_t*>(sutc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedUniformTimeCourse_t object.
 */
LIBSEDML_EXTERN
void
SedUniformTimeCourse_free(SedUniformTimeCourse_t* sutc)
{
  if (sutc != NULL)
  {
    delete sutc;
  }
}


/*
 * Returns the value of the "initialTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
double
SedUniformTimeCourse_getInitialTime(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->getInitialTime() : util_NaN();
}


/*
 * Returns the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
double
SedUniformTimeCourse_getOutputStartTime(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->getOutputStartTime() : util_NaN();
}


/*
 * Returns the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
double
SedUniformTimeCourse_getOutputEndTime(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->getOutputEndTime() : util_NaN();
}


/*
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_getNumberOfPoints(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->getNumberOfPoints() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_getNumberOfSteps(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->getNumberOfSteps() : SEDML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "initialTime" attribute is set.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetInitialTime(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? static_cast<int>(sutc->isSetInitialTime()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "outputStartTime" attribute is set.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetOutputStartTime(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? static_cast<int>(sutc->isSetOutputStartTime()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "outputEndTime" attribute is set.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetOutputEndTime(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? static_cast<int>(sutc->isSetOutputEndTime()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "numberOfSteps" attribute is set.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetNumberOfPoints(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? static_cast<int>(sutc->isSetNumberOfPoints()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "numberOfSteps" attribute is set.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetNumberOfSteps(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? static_cast<int>(sutc->isSetNumberOfSteps()) : 0;
}


/*
 * Sets the value of the "initialTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setInitialTime(SedUniformTimeCourse_t * sutc,
                                    double initialTime)
{
  return (sutc != NULL) ? sutc->setInitialTime(initialTime) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setOutputStartTime(SedUniformTimeCourse_t * sutc,
                                        double outputStartTime)
{
  return (sutc != NULL) ? sutc->setOutputStartTime(outputStartTime) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setOutputEndTime(SedUniformTimeCourse_t * sutc,
                                      double outputEndTime)
{
  return (sutc != NULL) ? sutc->setOutputEndTime(outputEndTime) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setNumberOfPoints(SedUniformTimeCourse_t * sutc,
                                       int numberOfSteps)
{
  return (sutc != NULL) ? sutc->setNumberOfPoints(numberOfSteps) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setNumberOfSteps(SedUniformTimeCourse_t * sutc,
                                      int numberOfSteps)
{
  return (sutc != NULL) ? sutc->setNumberOfSteps(numberOfSteps) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "initialTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetInitialTime(SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->unsetInitialTime() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetOutputStartTime(SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->unsetOutputStartTime() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetOutputEndTime(SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->unsetOutputEndTime() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetNumberOfPoints(SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->unsetNumberOfPoints() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetNumberOfSteps(SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? sutc->unsetNumberOfSteps() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedUniformTimeCourse_t object have been set.
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_hasRequiredAttributes(const SedUniformTimeCourse_t * sutc)
{
  return (sutc != NULL) ? static_cast<int>(sutc->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


