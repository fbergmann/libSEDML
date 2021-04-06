/**
 * @file SedOutput.cpp
 * @brief Implementation of the SedOutput class.
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
#include <sedml/SedOutput.h>
#include <sedml/SedListOfOutputs.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedReport.h>
#include <sedml/SedPlot2D.h>
#include <sedml/SedPlot3D.h>
#include <sedml/SedFigure.h>
#include <sedml/SedParameterEstimationResultPlot.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedOutput using the given SED-ML Level and @ p version values.
 */
SedOutput::SedOutput(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mElementName("output")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Creates a new SedOutput using the given SedNamespaces object @p sedmlns.
 */
SedOutput::SedOutput(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mElementName("output")
{
  setElementNamespace(sedmlns->getURI());
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Copy constructor for SedOutput.
 */
SedOutput::SedOutput(const SedOutput& orig)
  : SedBase( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedOutput.
 */
SedOutput&
SedOutput::operator=(const SedOutput& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedOutput object.
 */
SedOutput*
SedOutput::clone() const
{
  return new SedOutput(*this);
}


/*
 * Destructor for SedOutput.
 */
SedOutput::~SedOutput()
{
}


/*
 * Predicate returning @c true if this abstract "SedOutput" is of type
 * SedReport
 */
bool
SedOutput::isSedReport() const
{
  return dynamic_cast<const SedReport*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedOutput" is of type
 * SedPlot2D
 */
bool
SedOutput::isSedPlot2D() const
{
  return dynamic_cast<const SedPlot2D*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedOutput" is of type
 * SedPlot3D
 */
bool
SedOutput::isSedPlot3D() const
{
  return dynamic_cast<const SedPlot3D*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedOutput" is of type
 * SedFigure
 */
bool
SedOutput::isSedFigure() const
{
  return dynamic_cast<const SedFigure*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedOutput" is of type
 * SedParameterEstimationResultPlot
 */
bool
SedOutput::isSedParameterEstimationResultPlot() const
{
  return dynamic_cast<const SedParameterEstimationResultPlot*>(this) != NULL;
}


/*
 * Returns the XML element name of this SedOutput object.
 */
const std::string&
SedOutput::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedOutput object.
 */
void
SedOutput::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedOutput object.
 */
int
SedOutput::getTypeCode() const
{
  return SEDML_OUTPUT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedOutput object have been set.
 */
bool
SedOutput::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedOutput::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedOutput::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedOutput::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedOutput's attribute "attributeName" is
 * set.
 */
bool
SedOutput::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedOutput.
 */
int
SedOutput::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedOutput::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedOutput::readAttributes(
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

  if (log && getParentSedObject() &&
    static_cast<SedListOfOutputs*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDocumentLOOutputsAllowedCoreAttributes, level,
          version, details, getLine(), getColumn());
      }
    }
  }

  SedBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlOutputAllowedAttributes, level, version, details,
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
SedOutput::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedReport using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedReport_t *
SedOutput_createReport(unsigned int level, unsigned int version)
{
  return new SedReport(level, version);
}


/*
 * Creates a new SedPlot2D using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedPlot2D_t *
SedOutput_createPlot2D(unsigned int level, unsigned int version)
{
  return new SedPlot2D(level, version);
}


/*
 * Creates a new SedPlot3D using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedPlot3D_t *
SedOutput_createPlot3D(unsigned int level, unsigned int version)
{
  return new SedPlot3D(level, version);
}


/*
 * Creates a new SedFigure using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedFigure_t *
SedOutput_createFigure(unsigned int level, unsigned int version)
{
  return new SedFigure(level, version);
}


/*
 * Creates a new SedParameterEstimationResultPlot using the given SED-ML Level
 * and @ p version values.
 */
LIBSEDML_EXTERN
SedParameterEstimationResultPlot_t *
SedOutput_createParameterEstimationResultPlot(unsigned int level,
                                              unsigned int version)
{
  return new SedParameterEstimationResultPlot(level, version);
}


/*
 * Creates and returns a deep copy of this SedOutput_t object.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedOutput_clone(const SedOutput_t* so)
{
  if (so != NULL)
  {
    return static_cast<SedOutput_t*>(so->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedOutput_t object.
 */
LIBSEDML_EXTERN
void
SedOutput_free(SedOutput_t* so)
{
  if (so != NULL)
  {
    delete so;
  }
}


/*
 * Returns the value of the "id" attribute of this SedOutput_t.
 */
LIBSEDML_EXTERN
char *
SedOutput_getId(const SedOutput_t * so)
{
  if (so == NULL)
  {
    return NULL;
  }

  return so->getId().empty() ? NULL : safe_strdup(so->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedOutput_t.
 */
LIBSEDML_EXTERN
char *
SedOutput_getName(const SedOutput_t * so)
{
  if (so == NULL)
  {
    return NULL;
  }

  return so->getName().empty() ? NULL : safe_strdup(so->getName().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedOutput_t's "id" attribute is set.
 */
LIBSEDML_EXTERN
int
SedOutput_isSetId(const SedOutput_t * so)
{
  return (so != NULL) ? static_cast<int>(so->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedOutput_t's "name" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedOutput_isSetName(const SedOutput_t * so)
{
  return (so != NULL) ? static_cast<int>(so->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedOutput_t.
 */
LIBSEDML_EXTERN
int
SedOutput_setId(SedOutput_t * so, const char * id)
{
  return (so != NULL) ? so->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedOutput_t.
 */
LIBSEDML_EXTERN
int
SedOutput_setName(SedOutput_t * so, const char * name)
{
  return (so != NULL) ? so->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedOutput_t.
 */
LIBSEDML_EXTERN
int
SedOutput_unsetId(SedOutput_t * so)
{
  return (so != NULL) ? so->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedOutput_t.
 */
LIBSEDML_EXTERN
int
SedOutput_unsetName(SedOutput_t * so)
{
  return (so != NULL) ? so->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if this SedOutput_t is of type SedReport_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedReport(const SedOutput_t * so)
{
  return (so != NULL) ? static_cast<int>(so->isSedReport()) : 0;
}


/*
 * Predicate returning @c 1 if this SedOutput_t is of type SedPlot2D_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedPlot2D(const SedOutput_t * so)
{
  return (so != NULL) ? static_cast<int>(so->isSedPlot2D()) : 0;
}


/*
 * Predicate returning @c 1 if this SedOutput_t is of type SedPlot3D_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedPlot3D(const SedOutput_t * so)
{
  return (so != NULL) ? static_cast<int>(so->isSedPlot3D()) : 0;
}


/*
 * Predicate returning @c 1 if this SedOutput_t is of type SedFigure_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedFigure(const SedOutput_t * so)
{
  return (so != NULL) ? static_cast<int>(so->isSedFigure()) : 0;
}


/*
 * Predicate returning @c 1 if this SedOutput_t is of type
 * SedParameterEstimationResultPlot_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedParameterEstimationResultPlot(const SedOutput_t * so)
{
  return (so != NULL) ?
    static_cast<int>(so->isSedParameterEstimationResultPlot()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedOutput_t object have been set.
 */
LIBSEDML_EXTERN
int
SedOutput_hasRequiredAttributes(const SedOutput_t * so)
{
  return (so != NULL) ? static_cast<int>(so->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


