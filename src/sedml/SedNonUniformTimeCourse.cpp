/**
 * @file SedNonUniformTimeCourse.cpp
 * @brief Implementation of the SedNonUniformTimeCourse class.
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
#include <sedml/SedNonUniformTimeCourse.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedNonUniformTimeCourse using the given SEDML Level and @ p
 * version values.
 */
SedNonUniformTimeCourse::SedNonUniformTimeCourse(unsigned int level,
                                                 unsigned int version)
  : SedSimulation(level, version)
  , mInitialTime (util_NaN())
  , mIsSetInitialTime (false)
  , mOutputStartTime (util_NaN())
  , mIsSetOutputStartTime (false)
  , mOutputEndTime (util_NaN())
  , mIsSetOutputEndTime (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedNonUniformTimeCourse using the given SedNamespaces object
 * @p sedmlns.
 */
SedNonUniformTimeCourse::SedNonUniformTimeCourse(SedNamespaces *sedmlns)
  : SedSimulation(sedmlns)
  , mInitialTime (util_NaN())
  , mIsSetInitialTime (false)
  , mOutputStartTime (util_NaN())
  , mIsSetOutputStartTime (false)
  , mOutputEndTime (util_NaN())
  , mIsSetOutputEndTime (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedNonUniformTimeCourse.
 */
SedNonUniformTimeCourse::SedNonUniformTimeCourse(const SedNonUniformTimeCourse&
  orig)
  : SedSimulation( orig )
  , mInitialTime ( orig.mInitialTime )
  , mIsSetInitialTime ( orig.mIsSetInitialTime )
  , mOutputStartTime ( orig.mOutputStartTime )
  , mIsSetOutputStartTime ( orig.mIsSetOutputStartTime )
  , mOutputEndTime ( orig.mOutputEndTime )
  , mIsSetOutputEndTime ( orig.mIsSetOutputEndTime )
{
}


/*
 * Assignment operator for SedNonUniformTimeCourse.
 */
SedNonUniformTimeCourse&
SedNonUniformTimeCourse::operator=(const SedNonUniformTimeCourse& rhs)
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
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedNonUniformTimeCourse object.
 */
SedNonUniformTimeCourse*
SedNonUniformTimeCourse::clone() const
{
  return new SedNonUniformTimeCourse(*this);
}


/*
 * Destructor for SedNonUniformTimeCourse.
 */
SedNonUniformTimeCourse::~SedNonUniformTimeCourse()
{
}


/*
 * Returns the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse.
 */
double
SedNonUniformTimeCourse::getInitialTime() const
{
  return mInitialTime;
}


/*
 * Returns the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse.
 */
double
SedNonUniformTimeCourse::getOutputStartTime() const
{
  return mOutputStartTime;
}


/*
 * Returns the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse.
 */
double
SedNonUniformTimeCourse::getOutputEndTime() const
{
  return mOutputEndTime;
}


/*
 * Predicate returning @c true if this SedNonUniformTimeCourse's "initialTime"
 * attribute is set.
 */
bool
SedNonUniformTimeCourse::isSetInitialTime() const
{
  return mIsSetInitialTime;
}


/*
 * Predicate returning @c true if this SedNonUniformTimeCourse's
 * "outputStartTime" attribute is set.
 */
bool
SedNonUniformTimeCourse::isSetOutputStartTime() const
{
  return mIsSetOutputStartTime;
}


/*
 * Predicate returning @c true if this SedNonUniformTimeCourse's
 * "outputEndTime" attribute is set.
 */
bool
SedNonUniformTimeCourse::isSetOutputEndTime() const
{
  return mIsSetOutputEndTime;
}


/*
 * Sets the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::setInitialTime(double initialTime)
{
  mInitialTime = initialTime;
  mIsSetInitialTime = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::setOutputStartTime(double outputStartTime)
{
  mOutputStartTime = outputStartTime;
  mIsSetOutputStartTime = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::setOutputEndTime(double outputEndTime)
{
  mOutputEndTime = outputEndTime;
  mIsSetOutputEndTime = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::unsetInitialTime()
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
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::unsetOutputStartTime()
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
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::unsetOutputEndTime()
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
 * Returns the XML element name of this SedNonUniformTimeCourse object.
 */
const std::string&
SedNonUniformTimeCourse::getElementName() const
{
  static const string name = "nonUniformTimeCourse";
  return name;
}


/*
 * Returns the libSEDML type code for this SedNonUniformTimeCourse object.
 */
int
SedNonUniformTimeCourse::getTypeCode() const
{
  return SEDML_SIMULATION_NONUNIFORMTIMECOURSE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedNonUniformTimeCourse object have been set.
 */
bool
SedNonUniformTimeCourse::hasRequiredAttributes() const
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
SedNonUniformTimeCourse::writeElements(XMLOutputStream& stream) const
{
  SedSimulation::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedNonUniformTimeCourse::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedNonUniformTimeCourse::setSedDocument(SedDocument* d)
{
  SedSimulation::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::getAttribute(const std::string& attributeName,
                                      bool& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::getAttribute(const std::string& attributeName,
                                      int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::getAttribute(const std::string& attributeName,
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
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::getAttribute(const std::string& attributeName,
                                      unsigned int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::getAttribute(const std::string& attributeName,
                                      std::string& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedNonUniformTimeCourse's attribute
 * "attributeName" is set.
 */
bool
SedNonUniformTimeCourse::isSetAttribute(const std::string& attributeName) const
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

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::setAttribute(const std::string& attributeName,
                                      bool value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::setAttribute(const std::string& attributeName,
                                      int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::setAttribute(const std::string& attributeName,
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
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::setAttribute(const std::string& attributeName,
                                      unsigned int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::setAttribute(const std::string& attributeName,
                                      const std::string& value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedNonUniformTimeCourse.
 */
int
SedNonUniformTimeCourse::unsetAttribute(const std::string& attributeName)
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

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedNonUniformTimeCourse::createObject(XMLInputStream& stream)
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
SedNonUniformTimeCourse::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedSimulation::addExpectedAttributes(attributes);

  attributes.add("initialTime");

  attributes.add("outputStartTime");

  attributes.add("outputEndTime");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedNonUniformTimeCourse::readAttributes(const XMLAttributes& attributes,
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
        "<SedNonUniformTimeCourse> element must be an integer.";
      log->logError(SedUnknown, level, version, message, getLine(),
        getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'initialTime' is missing from the "
        "<SedNonUniformTimeCourse> element.";
      log->logError(SedUnknown, level, version, message, getLine(),
        getColumn());
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
        "<SedNonUniformTimeCourse> element must be an integer.";
      log->logError(SedUnknown, level, version, message, getLine(),
        getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'outputStartTime' is missing from "
        "the <SedNonUniformTimeCourse> element.";
      log->logError(SedUnknown, level, version, message, getLine(),
        getColumn());
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
        "<SedNonUniformTimeCourse> element must be an integer.";
      log->logError(SedUnknown, level, version, message, getLine(),
        getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'outputEndTime' is missing from "
        "the <SedNonUniformTimeCourse> element.";
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
SedNonUniformTimeCourse::writeAttributes(XMLOutputStream& stream) const
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
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedNonUniformTimeCourse_t using the given SEDML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedNonUniformTimeCourse_t *
SedNonUniformTimeCourse_create(unsigned int level, unsigned int version)
{
  return new SedNonUniformTimeCourse(level, version);
}


/*
 * Creates and returns a deep copy of this SedNonUniformTimeCourse_t object.
 */
LIBSEDML_EXTERN
SedNonUniformTimeCourse_t*
SedNonUniformTimeCourse_clone(const SedNonUniformTimeCourse_t* snutc)
{
  if (snutc != NULL)
  {
    return static_cast<SedNonUniformTimeCourse_t*>(snutc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedNonUniformTimeCourse_t object.
 */
LIBSEDML_EXTERN
void
SedNonUniformTimeCourse_free(SedNonUniformTimeCourse_t* snutc)
{
  if (snutc != NULL)
  {
    delete snutc;
  }
}


/*
 * Returns the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
double
SedNonUniformTimeCourse_getInitialTime(const SedNonUniformTimeCourse_t * snutc)
{
  return (snutc != NULL) ? snutc->getInitialTime() : util_NaN();
}


/*
 * Returns the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
double
SedNonUniformTimeCourse_getOutputStartTime(const SedNonUniformTimeCourse_t *
  snutc)
{
  return (snutc != NULL) ? snutc->getOutputStartTime() : util_NaN();
}


/*
 * Returns the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
double
SedNonUniformTimeCourse_getOutputEndTime(const SedNonUniformTimeCourse_t *
  snutc)
{
  return (snutc != NULL) ? snutc->getOutputEndTime() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SedNonUniformTimeCourse_t's
 * "initialTime" attribute is set.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_isSetInitialTime(const SedNonUniformTimeCourse_t *
  snutc)
{
  return (snutc != NULL) ? static_cast<int>(snutc->isSetInitialTime()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedNonUniformTimeCourse_t's
 * "outputStartTime" attribute is set.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_isSetOutputStartTime(const SedNonUniformTimeCourse_t *
  snutc)
{
  return (snutc != NULL) ? static_cast<int>(snutc->isSetOutputStartTime()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedNonUniformTimeCourse_t's
 * "outputEndTime" attribute is set.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_isSetOutputEndTime(const SedNonUniformTimeCourse_t *
  snutc)
{
  return (snutc != NULL) ? static_cast<int>(snutc->isSetOutputEndTime()) : 0;
}


/*
 * Sets the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_setInitialTime(SedNonUniformTimeCourse_t * snutc,
                                       double initialTime)
{
  return (snutc != NULL) ? snutc->setInitialTime(initialTime) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_setOutputStartTime(SedNonUniformTimeCourse_t * snutc,
                                           double outputStartTime)
{
  return (snutc != NULL) ? snutc->setOutputStartTime(outputStartTime) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_setOutputEndTime(SedNonUniformTimeCourse_t * snutc,
                                         double outputEndTime)
{
  return (snutc != NULL) ? snutc->setOutputEndTime(outputEndTime) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_unsetInitialTime(SedNonUniformTimeCourse_t * snutc)
{
  return (snutc != NULL) ? snutc->unsetInitialTime() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_unsetOutputStartTime(SedNonUniformTimeCourse_t * snutc)
{
  return (snutc != NULL) ? snutc->unsetOutputStartTime() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse_t.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_unsetOutputEndTime(SedNonUniformTimeCourse_t * snutc)
{
  return (snutc != NULL) ? snutc->unsetOutputEndTime() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedNonUniformTimeCourse_t object have been set.
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_hasRequiredAttributes(const SedNonUniformTimeCourse_t *
  snutc)
{
  return (snutc != NULL) ? static_cast<int>(snutc->hasRequiredAttributes()) :
    0;
}




LIBSEDML_CPP_NAMESPACE_END


