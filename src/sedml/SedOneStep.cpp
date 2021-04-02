/**
 * @file SedOneStep.cpp
 * @brief Implementation of the SedOneStep class.
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
#include <sedml/SedOneStep.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedOneStep using the given SED-ML Level and @ p version values.
 */
SedOneStep::SedOneStep(unsigned int level, unsigned int version)
  : SedSimulation(level, version)
  , mStep (util_NaN())
  , mIsSetStep (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedOneStep using the given SedNamespaces object @p sedmlns.
 */
SedOneStep::SedOneStep(SedNamespaces *sedmlns)
  : SedSimulation(sedmlns)
  , mStep (util_NaN())
  , mIsSetStep (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedOneStep.
 */
SedOneStep::SedOneStep(const SedOneStep& orig)
  : SedSimulation( orig )
  , mStep ( orig.mStep )
  , mIsSetStep ( orig.mIsSetStep )
{
}


/*
 * Assignment operator for SedOneStep.
 */
SedOneStep&
SedOneStep::operator=(const SedOneStep& rhs)
{
  if (&rhs != this)
  {
    SedSimulation::operator=(rhs);
    mStep = rhs.mStep;
    mIsSetStep = rhs.mIsSetStep;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedOneStep object.
 */
SedOneStep*
SedOneStep::clone() const
{
  return new SedOneStep(*this);
}


/*
 * Destructor for SedOneStep.
 */
SedOneStep::~SedOneStep()
{
}


/*
 * Returns the value of the "step" attribute of this SedOneStep.
 */
double
SedOneStep::getStep() const
{
  return mStep;
}


/*
 * Predicate returning @c true if this SedOneStep's "step" attribute is set.
 */
bool
SedOneStep::isSetStep() const
{
  return mIsSetStep;
}


/*
 * Sets the value of the "step" attribute of this SedOneStep.
 */
int
SedOneStep::setStep(double step)
{
  mStep = step;
  mIsSetStep = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "step" attribute of this SedOneStep.
 */
int
SedOneStep::unsetStep()
{
  mStep = util_NaN();
  mIsSetStep = false;

  if (isSetStep() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedOneStep object.
 */
const std::string&
SedOneStep::getElementName() const
{
  static const string name = "oneStep";
  return name;
}


/*
 * Returns the libSEDML type code for this SedOneStep object.
 */
int
SedOneStep::getTypeCode() const
{
  return SEDML_SIMULATION_ONESTEP;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedOneStep object have been set.
 */
bool
SedOneStep::hasRequiredAttributes() const
{
  bool allPresent = SedSimulation::hasRequiredAttributes();

  if (isSetStep() == false)
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
SedOneStep::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedSimulation::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedOneStep::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedOneStep::setSedDocument(SedDocument* d)
{
  SedSimulation::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "step")
  {
    value = getStep();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SedSimulation::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedOneStep's attribute "attributeName"
 * is set.
 */
bool
SedOneStep::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedSimulation::isSetAttribute(attributeName);

  if (attributeName == "step")
  {
    value = isSetStep();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  if (attributeName == "step")
  {
    return_value = setStep(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SedSimulation::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedOneStep.
 */
int
SedOneStep::unsetAttribute(const std::string& attributeName)
{
  int value = SedSimulation::unsetAttribute(attributeName);

  if (attributeName == "step")
  {
    value = unsetStep();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedOneStep::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
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
SedOneStep::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedSimulation::addExpectedAttributes(attributes);

  attributes.add("step");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedOneStep::readAttributes(
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
        log->logError(SedmlOneStepAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // step double (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetStep = attributes.readInto("step", mStep);

  if ( mIsSetStep == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'step' from the <SedOneStep> "
        "element must be an integer.";
      log->logError(SedmlOneStepStepMustBeDouble, level, version, message,
        getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'step' is missing from the "
        "<SedOneStep> element.";
      log->logError(SedmlOneStepAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedOneStep::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedSimulation::writeAttributes(stream);

  if (isSetStep() == true)
  {
    stream.writeAttribute("step", getPrefix(), mStep);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedOneStep_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedOneStep_t *
SedOneStep_create(unsigned int level, unsigned int version)
{
  return new SedOneStep(level, version);
}


/*
 * Creates and returns a deep copy of this SedOneStep_t object.
 */
LIBSEDML_EXTERN
SedOneStep_t*
SedOneStep_clone(const SedOneStep_t* sos)
{
  if (sos != NULL)
  {
    return static_cast<SedOneStep_t*>(sos->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedOneStep_t object.
 */
LIBSEDML_EXTERN
void
SedOneStep_free(SedOneStep_t* sos)
{
  if (sos != NULL)
  {
    delete sos;
  }
}


/*
 * Returns the value of the "step" attribute of this SedOneStep_t.
 */
LIBSEDML_EXTERN
double
SedOneStep_getStep(const SedOneStep_t * sos)
{
  return (sos != NULL) ? sos->getStep() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SedOneStep_t's "step" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedOneStep_isSetStep(const SedOneStep_t * sos)
{
  return (sos != NULL) ? static_cast<int>(sos->isSetStep()) : 0;
}


/*
 * Sets the value of the "step" attribute of this SedOneStep_t.
 */
LIBSEDML_EXTERN
int
SedOneStep_setStep(SedOneStep_t * sos, double step)
{
  return (sos != NULL) ? sos->setStep(step) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "step" attribute of this SedOneStep_t.
 */
LIBSEDML_EXTERN
int
SedOneStep_unsetStep(SedOneStep_t * sos)
{
  return (sos != NULL) ? sos->unsetStep() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedOneStep_t object have been set.
 */
LIBSEDML_EXTERN
int
SedOneStep_hasRequiredAttributes(const SedOneStep_t * sos)
{
  return (sos != NULL) ? static_cast<int>(sos->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


