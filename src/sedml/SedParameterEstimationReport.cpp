/**
 * @file SedParameterEstimationReport.cpp
 * @brief Implementation of the SedParameterEstimationReport class.
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
#include <sedml/SedParameterEstimationReport.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedParameterEstimationReport using the given SEDML Level and @
 * p version values.
 */
SedParameterEstimationReport::SedParameterEstimationReport(unsigned int level,
                                                           unsigned int
                                                             version)
  : SedOutput(level, version)
  , mTaskRef ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedParameterEstimationReport using the given SedNamespaces
 * object @p sedmlns.
 */
SedParameterEstimationReport::SedParameterEstimationReport(SedNamespaces
  *sedmlns)
  : SedOutput(sedmlns)
  , mTaskRef ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedParameterEstimationReport.
 */
SedParameterEstimationReport::SedParameterEstimationReport(const
  SedParameterEstimationReport& orig)
  : SedOutput( orig )
  , mTaskRef ( orig.mTaskRef )
{
}


/*
 * Assignment operator for SedParameterEstimationReport.
 */
SedParameterEstimationReport&
SedParameterEstimationReport::operator=(const SedParameterEstimationReport&
  rhs)
{
  if (&rhs != this)
  {
    SedOutput::operator=(rhs);
    mTaskRef = rhs.mTaskRef;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedParameterEstimationReport object.
 */
SedParameterEstimationReport*
SedParameterEstimationReport::clone() const
{
  return new SedParameterEstimationReport(*this);
}


/*
 * Destructor for SedParameterEstimationReport.
 */
SedParameterEstimationReport::~SedParameterEstimationReport()
{
}


/*
 * Returns the value of the "taskRef" attribute of this
 * SedParameterEstimationReport.
 */
const std::string&
SedParameterEstimationReport::getTaskRef() const
{
  return mTaskRef;
}


/*
 * Predicate returning @c true if this SedParameterEstimationReport's "taskRef"
 * attribute is set.
 */
bool
SedParameterEstimationReport::isSetTaskRef() const
{
  return (mTaskRef.empty() == false);
}


/*
 * Sets the value of the "taskRef" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::setTaskRef(const std::string& taskRef)
{
  if (!(SyntaxChecker::isValidInternalSId(taskRef)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTaskRef = taskRef;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "taskRef" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::unsetTaskRef()
{
  mTaskRef.erase();

  if (mTaskRef.empty() == true)
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
SedParameterEstimationReport::renameSIdRefs(const std::string& oldid,
                                            const std::string& newid)
{
  if (isSetTaskRef() && mTaskRef == oldid)
  {
    setTaskRef(newid);
  }
}


/*
 * Returns the XML element name of this SedParameterEstimationReport object.
 */
const std::string&
SedParameterEstimationReport::getElementName() const
{
  static const string name = "parameterEstimationReport";
  return name;
}


/*
 * Returns the libSEDML type code for this SedParameterEstimationReport object.
 */
int
SedParameterEstimationReport::getTypeCode() const
{
  return SEDML_PARAMETERESTIMATIONREPORT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedParameterEstimationReport object have been set.
 */
bool
SedParameterEstimationReport::hasRequiredAttributes() const
{
  bool allPresent = SedOutput::hasRequiredAttributes();

  if (isSetTaskRef() == false)
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
SedParameterEstimationReport::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedOutput::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedParameterEstimationReport::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedParameterEstimationReport::setSedDocument(SedDocument* d)
{
  SedOutput::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::getAttribute(const std::string& attributeName,
                                           bool& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::getAttribute(const std::string& attributeName,
                                           int& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::getAttribute(const std::string& attributeName,
                                           double& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::getAttribute(const std::string& attributeName,
                                           unsigned int& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::getAttribute(const std::string& attributeName,
                                           std::string& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "taskRef")
  {
    value = getTaskRef();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedParameterEstimationReport's attribute
 * "attributeName" is set.
 */
bool
SedParameterEstimationReport::isSetAttribute(const std::string& attributeName)
  const
{
  bool value = SedOutput::isSetAttribute(attributeName);

  if (attributeName == "taskRef")
  {
    value = isSetTaskRef();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::setAttribute(const std::string& attributeName,
                                           bool value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::setAttribute(const std::string& attributeName,
                                           int value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::setAttribute(const std::string& attributeName,
                                           double value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::setAttribute(const std::string& attributeName,
                                           unsigned int value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::setAttribute(const std::string& attributeName,
                                           const std::string& value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  if (attributeName == "taskRef")
  {
    return_value = setTaskRef(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedParameterEstimationReport.
 */
int
SedParameterEstimationReport::unsetAttribute(const std::string& attributeName)
{
  int value = SedOutput::unsetAttribute(attributeName);

  if (attributeName == "taskRef")
  {
    value = unsetTaskRef();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedParameterEstimationReport::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = SedOutput::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedParameterEstimationReport::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedOutput::addExpectedAttributes(attributes);

  attributes.add("taskRef");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedParameterEstimationReport::readAttributes(
                                             const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                               XMLAttributes& attributes,
                                             const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                               ExpectedAttributes&
                                                 expectedAttributes)
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
        log->logError(SedmlParameterEstimationReportAllowedAttributes, level,
          version, details, getLine(), getColumn());
      }
    }
  }

  // 
  // taskRef SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("taskRef", mTaskRef);

  if (assigned == true)
  {
    if (mTaskRef.empty() == true)
    {
      logEmptyString(mTaskRef, level, version,
        "<SedParameterEstimationReport>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mTaskRef) == false)
    {
      std::string msg = "The taskRef attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTaskRef + "', which does not conform to the syntax.";
      logError(SedmlParameterEstimationReportTaskRefMustBeTask, level, version,
        msg, getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'taskRef' is missing from the "
        "<SedParameterEstimationReport> element.";
      log->logError(SedmlParameterEstimationReportAllowedAttributes, level,
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
SedParameterEstimationReport::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedOutput::writeAttributes(stream);

  if (isSetTaskRef() == true)
  {
    stream.writeAttribute("taskRef", getPrefix(), mTaskRef);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedParameterEstimationReport_t using the given SEDML Level and
 * @ p version values.
 */
LIBSEDML_EXTERN
SedParameterEstimationReport_t *
SedParameterEstimationReport_create(unsigned int level, unsigned int version)
{
  return new SedParameterEstimationReport(level, version);
}


/*
 * Creates and returns a deep copy of this SedParameterEstimationReport_t
 * object.
 */
LIBSEDML_EXTERN
SedParameterEstimationReport_t*
SedParameterEstimationReport_clone(const SedParameterEstimationReport_t* sper)
{
  if (sper != NULL)
  {
    return static_cast<SedParameterEstimationReport_t*>(sper->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedParameterEstimationReport_t object.
 */
LIBSEDML_EXTERN
void
SedParameterEstimationReport_free(SedParameterEstimationReport_t* sper)
{
  if (sper != NULL)
  {
    delete sper;
  }
}


/*
 * Returns the value of the "taskRef" attribute of this
 * SedParameterEstimationReport_t.
 */
LIBSEDML_EXTERN
char *
SedParameterEstimationReport_getTaskRef(const SedParameterEstimationReport_t *
  sper)
{
  if (sper == NULL)
  {
    return NULL;
  }

  return sper->getTaskRef().empty() ? NULL :
    safe_strdup(sper->getTaskRef().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedParameterEstimationReport_t's
 * "taskRef" attribute is set.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationReport_isSetTaskRef(const SedParameterEstimationReport_t
  * sper)
{
  return (sper != NULL) ? static_cast<int>(sper->isSetTaskRef()) : 0;
}


/*
 * Sets the value of the "taskRef" attribute of this
 * SedParameterEstimationReport_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationReport_setTaskRef(SedParameterEstimationReport_t * sper,
                                        const char * taskRef)
{
  return (sper != NULL) ? sper->setTaskRef(taskRef) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "taskRef" attribute of this
 * SedParameterEstimationReport_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationReport_unsetTaskRef(SedParameterEstimationReport_t *
  sper)
{
  return (sper != NULL) ? sper->unsetTaskRef() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedParameterEstimationReport_t object have been set.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationReport_hasRequiredAttributes(const
  SedParameterEstimationReport_t * sper)
{
  return (sper != NULL) ? static_cast<int>(sper->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


