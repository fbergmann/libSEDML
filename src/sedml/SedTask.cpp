/**
 * @file SedTask.cpp
 * @brief Implementation of the SedTask class.
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
#include <sedml/SedTask.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedTask using the given SED-ML Level and @ p version values.
 */
SedTask::SedTask(unsigned int level, unsigned int version)
  : SedAbstractTask(level, version)
  , mModelReference ("")
  , mSimulationReference ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedTask using the given SedNamespaces object @p sedmlns.
 */
SedTask::SedTask(SedNamespaces *sedmlns)
  : SedAbstractTask(sedmlns)
  , mModelReference ("")
  , mSimulationReference ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedTask.
 */
SedTask::SedTask(const SedTask& orig)
  : SedAbstractTask( orig )
  , mModelReference ( orig.mModelReference )
  , mSimulationReference ( orig.mSimulationReference )
{
}


/*
 * Assignment operator for SedTask.
 */
SedTask&
SedTask::operator=(const SedTask& rhs)
{
  if (&rhs != this)
  {
    SedAbstractTask::operator=(rhs);
    mModelReference = rhs.mModelReference;
    mSimulationReference = rhs.mSimulationReference;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedTask object.
 */
SedTask*
SedTask::clone() const
{
  return new SedTask(*this);
}


/*
 * Destructor for SedTask.
 */
SedTask::~SedTask()
{
}


/*
 * Returns the value of the "modelReference" attribute of this SedTask.
 */
const std::string&
SedTask::getModelReference() const
{
  return mModelReference;
}


/*
 * Returns the value of the "simulationReference" attribute of this SedTask.
 */
const std::string&
SedTask::getSimulationReference() const
{
  return mSimulationReference;
}


/*
 * Predicate returning @c true if this SedTask's "modelReference" attribute is
 * set.
 */
bool
SedTask::isSetModelReference() const
{
  return (mModelReference.empty() == false);
}


/*
 * Predicate returning @c true if this SedTask's "simulationReference"
 * attribute is set.
 */
bool
SedTask::isSetSimulationReference() const
{
  return (mSimulationReference.empty() == false);
}


/*
 * Sets the value of the "modelReference" attribute of this SedTask.
 */
int
SedTask::setModelReference(const std::string& modelReference)
{
  if (!(SyntaxChecker::isValidInternalSId(modelReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mModelReference = modelReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "simulationReference" attribute of this SedTask.
 */
int
SedTask::setSimulationReference(const std::string& simulationReference)
{
  if (!(SyntaxChecker::isValidInternalSId(simulationReference)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSimulationReference = simulationReference;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "modelReference" attribute of this SedTask.
 */
int
SedTask::unsetModelReference()
{
  mModelReference.erase();

  if (mModelReference.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "simulationReference" attribute of this SedTask.
 */
int
SedTask::unsetSimulationReference()
{
  mSimulationReference.erase();

  if (mSimulationReference.empty() == true)
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
SedTask::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetModelReference() && mModelReference == oldid)
  {
    setModelReference(newid);
  }

  if (isSetSimulationReference() && mSimulationReference == oldid)
  {
    setSimulationReference(newid);
  }
}


/*
 * Returns the XML element name of this SedTask object.
 */
const std::string&
SedTask::getElementName() const
{
  static const string name = "task";
  return name;
}


/*
 * Returns the libSEDML type code for this SedTask object.
 */
int
SedTask::getTypeCode() const
{
  return SEDML_TASK;
}


/*
 * Predicate returning @c true if all the required attributes for this SedTask
 * object have been set.
 */
bool
SedTask::hasRequiredAttributes() const
{
  bool allPresent = SedAbstractTask::hasRequiredAttributes();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedTask::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SedAbstractTask::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedTask::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedTask::setSedDocument(SedDocument* d)
{
  SedAbstractTask::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::getAttribute(const std::string& attributeName,
                      unsigned int& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::getAttribute(const std::string& attributeName,
                      std::string& value) const
{
  int return_value = SedAbstractTask::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "modelReference")
  {
    value = getModelReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "simulationReference")
  {
    value = getSimulationReference();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedTask's attribute "attributeName" is
 * set.
 */
bool
SedTask::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedAbstractTask::isSetAttribute(attributeName);

  if (attributeName == "modelReference")
  {
    value = isSetModelReference();
  }
  else if (attributeName == "simulationReference")
  {
    value = isSetSimulationReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::setAttribute(const std::string& attributeName,
                      const std::string& value)
{
  int return_value = SedAbstractTask::setAttribute(attributeName, value);

  if (attributeName == "modelReference")
  {
    return_value = setModelReference(value);
  }
  else if (attributeName == "simulationReference")
  {
    return_value = setSimulationReference(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedTask.
 */
int
SedTask::unsetAttribute(const std::string& attributeName)
{
  int value = SedAbstractTask::unsetAttribute(attributeName);

  if (attributeName == "modelReference")
  {
    value = unsetModelReference();
  }
  else if (attributeName == "simulationReference")
  {
    value = unsetSimulationReference();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedTask::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = SedAbstractTask::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedTask::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedAbstractTask::addExpectedAttributes(attributes);

  attributes.add("modelReference");

  attributes.add("simulationReference");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedTask::readAttributes(
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

  SedAbstractTask::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlTaskAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // modelReference SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("modelReference", mModelReference);

  if (assigned == true)
  {
    if (mModelReference.empty() == true)
    {
      logEmptyString(mModelReference, level, version, "<SedTask>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
    {
      std::string msg = "The modelReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mModelReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlTaskModelReferenceMustBeModel, level, version, msg,
        getLine(), getColumn());
    }
  }

  // 
  // simulationReference SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("simulationReference", mSimulationReference);

  if (assigned == true)
  {
    if (mSimulationReference.empty() == true)
    {
      logEmptyString(mSimulationReference, level, version, "<SedTask>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mSimulationReference) == false)
    {
      std::string msg = "The simulationReference attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mSimulationReference + "', which does not conform to the "
        "syntax.";
      logError(SedmlTaskSimulationReferenceMustBeSimulation, level, version,
        msg, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedTask::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedAbstractTask::writeAttributes(stream);

  if (isSetModelReference() == true)
  {
    stream.writeAttribute("modelReference", getPrefix(), mModelReference);
  }

  if (isSetSimulationReference() == true)
  {
    stream.writeAttribute("simulationReference", getPrefix(),
      mSimulationReference);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedTask_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedTask_t *
SedTask_create(unsigned int level, unsigned int version)
{
  return new SedTask(level, version);
}


/*
 * Creates and returns a deep copy of this SedTask_t object.
 */
LIBSEDML_EXTERN
SedTask_t*
SedTask_clone(const SedTask_t* st)
{
  if (st != NULL)
  {
    return static_cast<SedTask_t*>(st->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedTask_t object.
 */
LIBSEDML_EXTERN
void
SedTask_free(SedTask_t* st)
{
  if (st != NULL)
  {
    delete st;
  }
}


/*
 * Returns the value of the "modelReference" attribute of this SedTask_t.
 */
LIBSEDML_EXTERN
char *
SedTask_getModelReference(const SedTask_t * st)
{
  if (st == NULL)
  {
    return NULL;
  }

  return st->getModelReference().empty() ? NULL :
    safe_strdup(st->getModelReference().c_str());
}


/*
 * Returns the value of the "simulationReference" attribute of this SedTask_t.
 */
LIBSEDML_EXTERN
char *
SedTask_getSimulationReference(const SedTask_t * st)
{
  if (st == NULL)
  {
    return NULL;
  }

  return st->getSimulationReference().empty() ? NULL :
    safe_strdup(st->getSimulationReference().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedTask_t's "modelReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedTask_isSetModelReference(const SedTask_t * st)
{
  return (st != NULL) ? static_cast<int>(st->isSetModelReference()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedTask_t's "simulationReference"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedTask_isSetSimulationReference(const SedTask_t * st)
{
  return (st != NULL) ? static_cast<int>(st->isSetSimulationReference()) : 0;
}


/*
 * Sets the value of the "modelReference" attribute of this SedTask_t.
 */
LIBSEDML_EXTERN
int
SedTask_setModelReference(SedTask_t * st, const char * modelReference)
{
  return (st != NULL) ? st->setModelReference(modelReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "simulationReference" attribute of this SedTask_t.
 */
LIBSEDML_EXTERN
int
SedTask_setSimulationReference(SedTask_t * st,
                               const char * simulationReference)
{
  return (st != NULL) ? st->setSimulationReference(simulationReference) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "modelReference" attribute of this SedTask_t.
 */
LIBSEDML_EXTERN
int
SedTask_unsetModelReference(SedTask_t * st)
{
  return (st != NULL) ? st->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "simulationReference" attribute of this SedTask_t.
 */
LIBSEDML_EXTERN
int
SedTask_unsetSimulationReference(SedTask_t * st)
{
  return (st != NULL) ? st->unsetSimulationReference() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedTask_hasRequiredAttributes(const SedTask_t * st)
{
  return (st != NULL) ? static_cast<int>(st->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


