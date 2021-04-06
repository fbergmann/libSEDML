/**
 * @file SedChange.cpp
 * @brief Implementation of the SedChange class.
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
#include <sedml/SedChange.h>
#include <sedml/SedListOfChanges.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedAddXML.h>
#include <sedml/SedChangeXML.h>
#include <sedml/SedRemoveXML.h>
#include <sedml/SedChangeAttribute.h>
#include <sedml/SedComputeChange.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedChange using the given SED-ML Level and @ p version values.
 */
SedChange::SedChange(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mTarget ("")
  , mElementName("change")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedChange using the given SedNamespaces object @p sedmlns.
 */
SedChange::SedChange(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mTarget ("")
  , mElementName("change")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedChange.
 */
SedChange::SedChange(const SedChange& orig)
  : SedBase( orig )
  , mTarget ( orig.mTarget )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedChange.
 */
SedChange&
SedChange::operator=(const SedChange& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mTarget = rhs.mTarget;
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedChange object.
 */
SedChange*
SedChange::clone() const
{
  return new SedChange(*this);
}


/*
 * Destructor for SedChange.
 */
SedChange::~SedChange()
{
}


/*
 * Returns the value of the "target" attribute of this SedChange.
 */
const std::string&
SedChange::getTarget() const
{
  return mTarget;
}


/*
 * Predicate returning @c true if this SedChange's "target" attribute is set.
 */
bool
SedChange::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Sets the value of the "target" attribute of this SedChange.
 */
int
SedChange::setTarget(const std::string& target)
{
  mTarget = target;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "target" attribute of this SedChange.
 */
int
SedChange::unsetTarget()
{
  mTarget.erase();

  if (mTarget.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Predicate returning @c true if this abstract "SedChange" is of type
 * SedAddXML
 */
bool
SedChange::isSedAddXML() const
{
  return dynamic_cast<const SedAddXML*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedChange" is of type
 * SedChangeXML
 */
bool
SedChange::isSedChangeXML() const
{
  return dynamic_cast<const SedChangeXML*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedChange" is of type
 * SedRemoveXML
 */
bool
SedChange::isSedRemoveXML() const
{
  return dynamic_cast<const SedRemoveXML*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedChange" is of type
 * SedChangeAttribute
 */
bool
SedChange::isSedChangeAttribute() const
{
  return dynamic_cast<const SedChangeAttribute*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedChange" is of type
 * SedComputeChange
 */
bool
SedChange::isSedComputeChange() const
{
  return dynamic_cast<const SedComputeChange*>(this) != NULL;
}


/*
 * Returns the XML element name of this SedChange object.
 */
const std::string&
SedChange::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedChange object.
 */
void
SedChange::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedChange object.
 */
int
SedChange::getTypeCode() const
{
  return SEDML_CHANGE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedChange object have been set.
 */
bool
SedChange::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetTarget() == false)
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
SedChange::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SedChange::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedChange::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedChange's attribute "attributeName" is
 * set.
 */
bool
SedChange::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "target")
  {
    value = isSetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "target")
  {
    return_value = setTarget(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedChange.
 */
int
SedChange::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "target")
  {
    value = unsetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedChange::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("target");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedChange::readAttributes(
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
    static_cast<SedListOfChanges*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlModelLOChangesAllowedCoreAttributes, level, version,
          details, getLine(), getColumn());
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
        log->logError(SedmlChangeAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // target string (use = "required" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<SedChange>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'target' is missing from the "
        "<SedChange> element.";
      log->logError(SedmlChangeAllowedAttributes, level, version, message,
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
SedChange::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }
}

std::string SedChange::_trim(const std::string& text)
{
  static const string whitespace(" \t\r\n");

  string::size_type begin = text.find_first_not_of(whitespace);
  string::size_type end = text.find_last_not_of(whitespace);

  return (begin == string::npos) ? std::string() : text.substr(begin, end - begin + 1);
}
/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedAddXML using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedAddXML_t *
SedChange_createAddXML(unsigned int level, unsigned int version)
{
  return new SedAddXML(level, version);
}


/*
 * Creates a new SedChangeXML using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedChangeXML_t *
SedChange_createChangeXML(unsigned int level, unsigned int version)
{
  return new SedChangeXML(level, version);
}


/*
 * Creates a new SedRemoveXML using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedRemoveXML_t *
SedChange_createRemoveXML(unsigned int level, unsigned int version)
{
  return new SedRemoveXML(level, version);
}


/*
 * Creates a new SedChangeAttribute using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedChangeAttribute_t *
SedChange_createChangeAttribute(unsigned int level, unsigned int version)
{
  return new SedChangeAttribute(level, version);
}


/*
 * Creates a new SedComputeChange using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedComputeChange_t *
SedChange_createComputeChange(unsigned int level, unsigned int version)
{
  return new SedComputeChange(level, version);
}


/*
 * Creates and returns a deep copy of this SedChange_t object.
 */
LIBSEDML_EXTERN
SedChange_t*
SedChange_clone(const SedChange_t* sc)
{
  if (sc != NULL)
  {
    return static_cast<SedChange_t*>(sc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedChange_t object.
 */
LIBSEDML_EXTERN
void
SedChange_free(SedChange_t* sc)
{
  if (sc != NULL)
  {
    delete sc;
  }
}


/*
 * Returns the value of the "target" attribute of this SedChange_t.
 */
LIBSEDML_EXTERN
char *
SedChange_getTarget(const SedChange_t * sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return sc->getTarget().empty() ? NULL : safe_strdup(sc->getTarget().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedChange_t's "target" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedChange_isSetTarget(const SedChange_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetTarget()) : 0;
}


/*
 * Sets the value of the "target" attribute of this SedChange_t.
 */
LIBSEDML_EXTERN
int
SedChange_setTarget(SedChange_t * sc, const char * target)
{
  return (sc != NULL) ? sc->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SedChange_t.
 */
LIBSEDML_EXTERN
int
SedChange_unsetTarget(SedChange_t * sc)
{
  return (sc != NULL) ? sc->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if this SedChange_t is of type SedAddXML_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedAddXML(const SedChange_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSedAddXML()) : 0;
}


/*
 * Predicate returning @c 1 if this SedChange_t is of type SedChangeXML_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedChangeXML(const SedChange_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSedChangeXML()) : 0;
}


/*
 * Predicate returning @c 1 if this SedChange_t is of type SedRemoveXML_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedRemoveXML(const SedChange_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSedRemoveXML()) : 0;
}


/*
 * Predicate returning @c 1 if this SedChange_t is of type SedChangeAttribute_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedChangeAttribute(const SedChange_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSedChangeAttribute()) : 0;
}


/*
 * Predicate returning @c 1 if this SedChange_t is of type SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedComputeChange(const SedChange_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSedComputeChange()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedChange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedChange_hasRequiredAttributes(const SedChange_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


