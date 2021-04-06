/**
 * @file SedUniformRange.cpp
 * @brief Implementation of the SedUniformRange class.
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
#include <sedml/SedUniformRange.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedUniformRange using the given SED-ML Level and @ p version
 * values.
 */
SedUniformRange::SedUniformRange(unsigned int level, unsigned int version)
  : SedRange(level, version)
  , mStart (util_NaN())
  , mIsSetStart (false)
  , mEnd (util_NaN())
  , mIsSetEnd (false)
  , mNumberOfSteps (SEDML_INT_MAX)
  , mIsSetNumberOfSteps (false)
  , mType ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedUniformRange using the given SedNamespaces object @p
 * sedmlns.
 */
SedUniformRange::SedUniformRange(SedNamespaces *sedmlns)
  : SedRange(sedmlns)
  , mStart (util_NaN())
  , mIsSetStart (false)
  , mEnd (util_NaN())
  , mIsSetEnd (false)
  , mNumberOfSteps (SEDML_INT_MAX)
  , mIsSetNumberOfSteps (false)
  , mType ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedUniformRange.
 */
SedUniformRange::SedUniformRange(const SedUniformRange& orig)
  : SedRange( orig )
  , mStart ( orig.mStart )
  , mIsSetStart ( orig.mIsSetStart )
  , mEnd ( orig.mEnd )
  , mIsSetEnd ( orig.mIsSetEnd )
  , mNumberOfSteps ( orig.mNumberOfSteps )
  , mIsSetNumberOfSteps ( orig.mIsSetNumberOfSteps )
  , mType ( orig.mType )
{
}


/*
 * Assignment operator for SedUniformRange.
 */
SedUniformRange&
SedUniformRange::operator=(const SedUniformRange& rhs)
{
  if (&rhs != this)
  {
    SedRange::operator=(rhs);
    mStart = rhs.mStart;
    mIsSetStart = rhs.mIsSetStart;
    mEnd = rhs.mEnd;
    mIsSetEnd = rhs.mIsSetEnd;
    mNumberOfSteps = rhs.mNumberOfSteps;
    mIsSetNumberOfSteps = rhs.mIsSetNumberOfSteps;
    mType = rhs.mType;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedUniformRange object.
 */
SedUniformRange*
SedUniformRange::clone() const
{
  return new SedUniformRange(*this);
}


/*
 * Destructor for SedUniformRange.
 */
SedUniformRange::~SedUniformRange()
{
}


/*
 * Returns the value of the "start" attribute of this SedUniformRange.
 */
double
SedUniformRange::getStart() const
{
  return mStart;
}


/*
 * Returns the value of the "end" attribute of this SedUniformRange.
 */
double
SedUniformRange::getEnd() const
{
  return mEnd;
}


/*
 * Returns the value of the "numberOfSteps" attribute of this SedUniformRange.
 */
int
SedUniformRange::getNumberOfPoints() const
{
  return mNumberOfSteps;
}


/*
 * Returns the value of the "numberOfSteps" attribute of this SedUniformRange.
 */
int
SedUniformRange::getNumberOfSteps() const
{
    return mNumberOfSteps;
}


/*
 * Returns the value of the "type" attribute of this SedUniformRange.
 */
const std::string&
SedUniformRange::getType() const
{
  return mType;
}


/*
 * Predicate returning @c true if this SedUniformRange's "start" attribute is
 * set.
 */
bool
SedUniformRange::isSetStart() const
{
  return mIsSetStart;
}


/*
 * Predicate returning @c true if this SedUniformRange's "end" attribute is
 * set.
 */
bool
SedUniformRange::isSetEnd() const
{
  return mIsSetEnd;
}


/*
 * Predicate returning @c true if this SedUniformRange's "numberOfSteps"
 * attribute is set.
 */
bool
SedUniformRange::isSetNumberOfPoints() const
{
  return mIsSetNumberOfSteps;
}


/*
 * Predicate returning @c true if this SedUniformRange's "numberOfSteps"
 * attribute is set.
 */
bool
SedUniformRange::isSetNumberOfSteps() const
{
    return mIsSetNumberOfSteps;
}


/*
 * Predicate returning @c true if this SedUniformRange's "type" attribute is
 * set.
 */
bool
SedUniformRange::isSetType() const
{
  return (mType.empty() == false);
}


/*
 * Sets the value of the "start" attribute of this SedUniformRange.
 */
int
SedUniformRange::setStart(double start)
{
  mStart = start;
  mIsSetStart = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "end" attribute of this SedUniformRange.
 */
int
SedUniformRange::setEnd(double end)
{
  mEnd = end;
  mIsSetEnd = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "numberOfSteps" attribute of this SedUniformRange.
 */
int
SedUniformRange::setNumberOfPoints(int numberOfSteps)
{
  mNumberOfSteps = numberOfSteps;
  mIsSetNumberOfSteps = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "numberOfSteps" attribute of this SedUniformRange.
 */
int
SedUniformRange::setNumberOfSteps(int numberOfSteps)
{
    mNumberOfSteps = numberOfSteps;
    mIsSetNumberOfSteps = true;
    return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "type" attribute of this SedUniformRange.
 */
int
SedUniformRange::setType(const std::string& type)
{
  mType = type;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "start" attribute of this SedUniformRange.
 */
int
SedUniformRange::unsetStart()
{
  mStart = util_NaN();
  mIsSetStart = false;

  if (isSetStart() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "end" attribute of this SedUniformRange.
 */
int
SedUniformRange::unsetEnd()
{
  mEnd = util_NaN();
  mIsSetEnd = false;

  if (isSetEnd() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "numberOfSteps" attribute of this SedUniformRange.
 */
int
SedUniformRange::unsetNumberOfPoints()
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
 * Unsets the value of the "numberOfSteps" attribute of this SedUniformRange.
 */
int
SedUniformRange::unsetNumberOfSteps()
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
 * Unsets the value of the "type" attribute of this SedUniformRange.
 */
int
SedUniformRange::unsetType()
{
  mType.erase();

  if (mType.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedUniformRange object.
 */
const std::string&
SedUniformRange::getElementName() const
{
  static const string name = "uniformRange";
  return name;
}


/*
 * Returns the libSEDML type code for this SedUniformRange object.
 */
int
SedUniformRange::getTypeCode() const
{
  return SEDML_RANGE_UNIFORMRANGE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedUniformRange object have been set.
 */
bool
SedUniformRange::hasRequiredAttributes() const
{
  bool allPresent = SedRange::hasRequiredAttributes();

  if (isSetStart() == false)
  {
    allPresent = false;
  }

  if (isSetEnd() == false)
  {
    allPresent = false;
  }

  if (isSetNumberOfSteps() == false)
  {
    allPresent = false;
  }

  if (isSetType() == false)
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
SedUniformRange::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedRange::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedUniformRange::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedUniformRange::setSedDocument(SedDocument* d)
{
  SedRange::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::getAttribute(const std::string& attributeName,
                              bool& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::getAttribute(const std::string& attributeName,
                              int& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "numberOfSteps" || attributeName == "numberOfPoints")
  {
    value = getNumberOfSteps();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::getAttribute(const std::string& attributeName,
                              double& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "start")
  {
    value = getStart();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "end")
  {
    value = getEnd();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::getAttribute(const std::string& attributeName,
                              unsigned int& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::getAttribute(const std::string& attributeName,
                              std::string& value) const
{
  int return_value = SedRange::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "type")
  {
    value = getType();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedUniformRange's attribute
 * "attributeName" is set.
 */
bool
SedUniformRange::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedRange::isSetAttribute(attributeName);

  if (attributeName == "start")
  {
    value = isSetStart();
  }
  else if (attributeName == "end")
  {
    value = isSetEnd();
  }
  else if (attributeName == "numberOfSteps" || attributeName == "numberOfPoints")
  {
    value = isSetNumberOfSteps();
  }
  else if (attributeName == "type")
  {
    value = isSetType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  if (attributeName == "numberOfSteps" || attributeName == "numberOfPoints")
  {
    return_value = setNumberOfSteps(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  if (attributeName == "start")
  {
    return_value = setStart(value);
  }
  else if (attributeName == "end")
  {
    return_value = setEnd(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::setAttribute(const std::string& attributeName,
                              unsigned int value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::setAttribute(const std::string& attributeName,
                              const std::string& value)
{
  int return_value = SedRange::setAttribute(attributeName, value);

  if (attributeName == "type")
  {
    return_value = setType(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedUniformRange.
 */
int
SedUniformRange::unsetAttribute(const std::string& attributeName)
{
  int value = SedRange::unsetAttribute(attributeName);

  if (attributeName == "start")
  {
    value = unsetStart();
  }
  else if (attributeName == "end")
  {
    value = unsetEnd();
  }
  else if (attributeName == "numberOfSteps" || attributeName == "numberOfPoints")
  {
    value = unsetNumberOfSteps();
  }
  else if (attributeName == "type")
  {
    value = unsetType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedUniformRange::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedRange::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedUniformRange::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedRange::addExpectedAttributes(attributes);

  attributes.add("start");

  attributes.add("end");

  attributes.add("numberOfPoints");

  if (getVersion() >= 4 || getLevel() > 1) {
      attributes.add("numberOfSteps");
  }

  attributes.add("type");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedUniformRange::readAttributes(
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

  SedRange::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlUniformRangeAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // start double (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetStart = attributes.readInto("start", mStart);

  if ( mIsSetStart == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'start' from the <SedUniformRange> "
        "element must be an integer.";
      log->logError(SedmlUniformRangeStartMustBeDouble, level, version,
        message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'start' is missing from the "
        "<SedUniformRange> element.";
      log->logError(SedmlUniformRangeAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // end double (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetEnd = attributes.readInto("end", mEnd);

  if ( mIsSetEnd == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'end' from the <SedUniformRange> "
        "element must be an integer.";
      log->logError(SedmlUniformRangeEndMustBeDouble, level, version, message,
        getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'end' is missing from the "
        "<SedUniformRange> element.";
      log->logError(SedmlUniformRangeAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // numberOfSteps int (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetNumberOfSteps = attributes.readInto("numberOfSteps",
    mNumberOfSteps);

  if (!mIsSetNumberOfSteps) {
      mIsSetNumberOfSteps = attributes.readInto("numberOfPoints",
          mNumberOfSteps);
  }

  if ( mIsSetNumberOfSteps == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'numberOfSteps' from the "
        "<SedUniformRange> element must be an integer.";
      log->logError(SedmlUniformRangeNumberOfPointsMustBeInteger, level,
        version, message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'numberOfSteps' is missing from "
        "the <SedUniformRange> element.";
      log->logError(SedmlUniformRangeAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // type string (use = "required" )
  // 

  assigned = attributes.readInto("type", mType);

  if (assigned == true)
  {
    if (mType.empty() == true)
    {
      logEmptyString(mType, level, version, "<SedUniformRange>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'type' is missing from the "
        "<SedUniformRange> element.";
      log->logError(SedmlUniformRangeAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedUniformRange::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedRange::writeAttributes(stream);

  if (isSetStart() == true)
  {
    stream.writeAttribute("start", getPrefix(), mStart);
  }

  if (isSetEnd() == true)
  {
    stream.writeAttribute("end", getPrefix(), mEnd);
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

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), mType);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedUniformRange_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedUniformRange_t *
SedUniformRange_create(unsigned int level, unsigned int version)
{
  return new SedUniformRange(level, version);
}


/*
 * Creates and returns a deep copy of this SedUniformRange_t object.
 */
LIBSEDML_EXTERN
SedUniformRange_t*
SedUniformRange_clone(const SedUniformRange_t* sur)
{
  if (sur != NULL)
  {
    return static_cast<SedUniformRange_t*>(sur->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedUniformRange_t object.
 */
LIBSEDML_EXTERN
void
SedUniformRange_free(SedUniformRange_t* sur)
{
  if (sur != NULL)
  {
    delete sur;
  }
}


/*
 * Returns the value of the "start" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
double
SedUniformRange_getStart(const SedUniformRange_t * sur)
{
  return (sur != NULL) ? sur->getStart() : util_NaN();
}


/*
 * Returns the value of the "end" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
double
SedUniformRange_getEnd(const SedUniformRange_t * sur)
{
  return (sur != NULL) ? sur->getEnd() : util_NaN();
}


/*
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_getNumberOfPoints(const SedUniformRange_t * sur)
{
  return (sur != NULL) ? sur->getNumberOfPoints() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_getNumberOfSteps(const SedUniformRange_t* sur)
{
    return (sur != NULL) ? sur->getNumberOfSteps() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "type" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
char *
SedUniformRange_getType(const SedUniformRange_t * sur)
{
  if (sur == NULL)
  {
    return NULL;
  }

  return sur->getType().empty() ? NULL : safe_strdup(sur->getType().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "start"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetStart(const SedUniformRange_t * sur)
{
  return (sur != NULL) ? static_cast<int>(sur->isSetStart()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "end" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetEnd(const SedUniformRange_t * sur)
{
  return (sur != NULL) ? static_cast<int>(sur->isSetEnd()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "numberOfSteps"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetNumberOfPoints(const SedUniformRange_t * sur)
{
  return (sur != NULL) ? static_cast<int>(sur->isSetNumberOfPoints()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "numberOfSteps"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetNumberOfSteps(const SedUniformRange_t* sur)
{
    return (sur != NULL) ? static_cast<int>(sur->isSetNumberOfSteps()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "type" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetType(const SedUniformRange_t * sur)
{
  return (sur != NULL) ? static_cast<int>(sur->isSetType()) : 0;
}


/*
 * Sets the value of the "start" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_setStart(SedUniformRange_t * sur, double start)
{
  return (sur != NULL) ? sur->setStart(start) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "end" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_setEnd(SedUniformRange_t * sur, double end)
{
  return (sur != NULL) ? sur->setEnd(end) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "numberOfSteps" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_setNumberOfPoints(SedUniformRange_t * sur, int numberOfSteps)
{
  return (sur != NULL) ? sur->setNumberOfPoints(numberOfSteps) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "numberOfSteps" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_setNumberOfSteps(SedUniformRange_t* sur, int numberOfSteps)
{
    return (sur != NULL) ? sur->setNumberOfSteps(numberOfSteps) :
        LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_setType(SedUniformRange_t * sur, const char * type)
{
  return (sur != NULL) ? sur->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "start" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetStart(SedUniformRange_t * sur)
{
  return (sur != NULL) ? sur->unsetStart() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "end" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetEnd(SedUniformRange_t * sur)
{
  return (sur != NULL) ? sur->unsetEnd() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetNumberOfPoints(SedUniformRange_t * sur)
{
  return (sur != NULL) ? sur->unsetNumberOfPoints() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetNumberOfSteps(SedUniformRange_t* sur)
{
    return (sur != NULL) ? sur->unsetNumberOfSteps() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this SedUniformRange_t.
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetType(SedUniformRange_t * sur)
{
  return (sur != NULL) ? sur->unsetType() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedUniformRange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedUniformRange_hasRequiredAttributes(const SedUniformRange_t * sur)
{
  return (sur != NULL) ? static_cast<int>(sur->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


