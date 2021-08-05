/**
 * @file SedParameterEstimationResultPlot.cpp
 * @brief Implementation of the SedParameterEstimationResultPlot class.
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
#include <sedml/SedParameterEstimationResultPlot.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedParameterEstimationResultPlot using the given SED-ML Level
 * and @ p version values.
 */
SedParameterEstimationResultPlot::SedParameterEstimationResultPlot(
                                                                   unsigned int
                                                                     level,
                                                                   unsigned int
                                                                     version)
  : SedPlot(level, version)
  , mTaskReference ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedParameterEstimationResultPlot using the given SedNamespaces
 * object @p sedmlns.
 */
SedParameterEstimationResultPlot::SedParameterEstimationResultPlot(SedNamespaces
  *sedmlns)
  : SedPlot(sedmlns)
  , mTaskReference ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedParameterEstimationResultPlot.
 */
SedParameterEstimationResultPlot::SedParameterEstimationResultPlot(const
  SedParameterEstimationResultPlot& orig)
  : SedPlot( orig )
  , mTaskReference ( orig.mTaskReference )
{
}


/*
 * Assignment operator for SedParameterEstimationResultPlot.
 */
SedParameterEstimationResultPlot&
SedParameterEstimationResultPlot::operator=(const
  SedParameterEstimationResultPlot& rhs)
{
  if (&rhs != this)
  {
    SedPlot::operator=(rhs);
    mTaskReference = rhs.mTaskReference;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedParameterEstimationResultPlot
 * object.
 */
SedParameterEstimationResultPlot*
SedParameterEstimationResultPlot::clone() const
{
  return new SedParameterEstimationResultPlot(*this);
}


/*
 * Destructor for SedParameterEstimationResultPlot.
 */
SedParameterEstimationResultPlot::~SedParameterEstimationResultPlot()
{
}


/*
 * Returns the value of the "taskReference" attribute of this
 * SedParameterEstimationResultPlot.
 */
const std::string&
SedParameterEstimationResultPlot::getTaskReference() const
{
  return mTaskReference;
}


/*
 * Predicate returning @c true if this SedParameterEstimationResultPlot's
 * "taskReference" attribute is set.
 */
bool
SedParameterEstimationResultPlot::isSetTaskReference() const
{
  return (mTaskReference.empty() == false);
}


/*
 * Sets the value of the "taskReference" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::setTaskReference(const std::string& taskReference)
{
  if (!(SyntaxChecker::isValidInternalSId(taskReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTaskReference = taskReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "taskReference" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::unsetTaskReference()
{
  mTaskReference.erase();

  if (mTaskReference.empty() == true)
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
SedParameterEstimationResultPlot::renameSIdRefs(const std::string& oldid,
                                                const std::string& newid)
{
  if (isSetTaskReference() && mTaskReference == oldid)
  {
    setTaskReference(newid);
  }
}


/*
 * Returns the XML element name of this SedParameterEstimationResultPlot
 * object.
 */
const std::string&
SedParameterEstimationResultPlot::getElementName() const
{
  static const string name = "parameterEstimationResultPlot";
  return name;
}


/*
 * Returns the libSEDML type code for this SedParameterEstimationResultPlot
 * object.
 */
int
SedParameterEstimationResultPlot::getTypeCode() const
{
  return SEDML_PARAMETERESTIMATIONRESULTPLOT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedParameterEstimationResultPlot object have been set.
 */
bool
SedParameterEstimationResultPlot::hasRequiredAttributes() const
{
  bool allPresent = SedPlot::hasRequiredAttributes();

  if (isSetTaskReference() == false)
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
SedParameterEstimationResultPlot::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedPlot::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedParameterEstimationResultPlot::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedParameterEstimationResultPlot::setSedDocument(SedDocument* d)
{
  SedPlot::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::getAttribute(
                                               const std::string&
                                                 attributeName,
                                               bool& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::getAttribute(
                                               const std::string&
                                                 attributeName,
                                               int& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::getAttribute(
                                               const std::string&
                                                 attributeName,
                                               double& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::getAttribute(
                                               const std::string&
                                                 attributeName,
                                               unsigned int& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::getAttribute(
                                               const std::string&
                                                 attributeName,
                                               std::string& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "taskReference")
  {
    value = getTaskReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedParameterEstimationResultPlot's
 * attribute "attributeName" is set.
 */
bool
SedParameterEstimationResultPlot::isSetAttribute(const std::string&
  attributeName) const
{
  bool value = SedPlot::isSetAttribute(attributeName);

  if (attributeName == "taskReference")
  {
    value = isSetTaskReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::setAttribute(
                                               const std::string&
                                                 attributeName,
                                               bool value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::setAttribute(
                                               const std::string&
                                                 attributeName,
                                               int value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::setAttribute(
                                               const std::string&
                                                 attributeName,
                                               double value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::setAttribute(
                                               const std::string&
                                                 attributeName,
                                               unsigned int value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::setAttribute(
                                               const std::string&
                                                 attributeName,
                                               const std::string& value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  if (attributeName == "taskReference")
  {
    return_value = setTaskReference(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedParameterEstimationResultPlot.
 */
int
SedParameterEstimationResultPlot::unsetAttribute(const std::string&
  attributeName)
{
  int value = SedPlot::unsetAttribute(attributeName);

  if (attributeName == "taskReference")
  {
    value = unsetTaskReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedParameterEstimationResultPlot::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = SedPlot::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedParameterEstimationResultPlot::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedPlot::addExpectedAttributes(attributes);

  attributes.add("taskReference");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedParameterEstimationResultPlot::readAttributes(
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
        log->logError(SedmlParameterEstimationResultPlotAllowedAttributes,
          level, version, details, getLine(), getColumn());
      }
    }
  }

  // 
  // taskReference SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("taskReference", mTaskReference);

  if (assigned == true)
  {
    if (mTaskReference.empty() == true)
    {
      logEmptyString(mTaskReference, level, version,
        "<SedParameterEstimationResultPlot>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mTaskReference) == false)
    {
      std::string msg = "The taskReference attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTaskReference + "', which does not conform to the syntax.";
      logError(SedmlParameterEstimationResultPlotTaskReferenceMustBeTask, level,
        version, msg, getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'taskReference' is missing from the "
        "<SedParameterEstimationResultPlot> element.";
      log->logError(SedmlParameterEstimationResultPlotAllowedAttributes, level,
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
SedParameterEstimationResultPlot::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedPlot::writeAttributes(stream);

  if (isSetTaskReference() == true)
  {
    stream.writeAttribute("taskReference", getPrefix(), mTaskReference);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedParameterEstimationResultPlot_t using the given SED-ML Level
 * and @ p version values.
 */
LIBSEDML_EXTERN
SedParameterEstimationResultPlot_t *
SedParameterEstimationResultPlot_create(unsigned int level,
                                        unsigned int version)
{
  return new SedParameterEstimationResultPlot(level, version);
}


/*
 * Creates and returns a deep copy of this SedParameterEstimationResultPlot_t
 * object.
 */
LIBSEDML_EXTERN
SedParameterEstimationResultPlot_t*
SedParameterEstimationResultPlot_clone(const
  SedParameterEstimationResultPlot_t* sperp)
{
  if (sperp != NULL)
  {
    return static_cast<SedParameterEstimationResultPlot_t*>(sperp->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedParameterEstimationResultPlot_t object.
 */
LIBSEDML_EXTERN
void
SedParameterEstimationResultPlot_free(SedParameterEstimationResultPlot_t*
  sperp)
{
  if (sperp != NULL)
  {
    delete sperp;
  }
}


/*
 * Returns the value of the "taskReference" attribute of this
 * SedParameterEstimationResultPlot_t.
 */
LIBSEDML_EXTERN
char *
SedParameterEstimationResultPlot_getTaskReference(const
  SedParameterEstimationResultPlot_t * sperp)
{
  if (sperp == NULL)
  {
    return NULL;
  }

  return sperp->getTaskReference().empty() ? NULL :
    safe_strdup(sperp->getTaskReference().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedParameterEstimationResultPlot_t's
 * "taskReference" attribute is set.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_isSetTaskReference(const
  SedParameterEstimationResultPlot_t * sperp)
{
  return (sperp != NULL) ? static_cast<int>(sperp->isSetTaskReference()) : 0;
}


/*
 * Sets the value of the "taskReference" attribute of this
 * SedParameterEstimationResultPlot_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_setTaskReference(
                                            SedParameterEstimationResultPlot_t
                                              * sperp,
                                            const char * taskReference)
{
  return (sperp != NULL) ? sperp->setTaskReference(taskReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "taskReference" attribute of this
 * SedParameterEstimationResultPlot_t.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_unsetTaskReference(SedParameterEstimationResultPlot_t
  * sperp)
{
  return (sperp != NULL) ? sperp->unsetTaskReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedParameterEstimationResultPlot_t object have been set.
 */
LIBSEDML_EXTERN
int
SedParameterEstimationResultPlot_hasRequiredAttributes(const
  SedParameterEstimationResultPlot_t * sperp)
{
  return (sperp != NULL) ? static_cast<int>(sperp->hasRequiredAttributes()) :
    0;
}




LIBSEDML_CPP_NAMESPACE_END


