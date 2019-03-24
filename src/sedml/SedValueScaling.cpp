/**
 * @file SedValueScaling.cpp
 * @brief Implementation of the SedValueScaling class.
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
#include <sedml/SedValueScaling.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedValueScaling using the given SEDML Level and @ p version
 * values.
 */
SedValueScaling::SedValueScaling(unsigned int level, unsigned int version)
  : SedScaling(level, version)
  , mWeight ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedValueScaling using the given SedNamespaces object @p
 * sedmlns.
 */
SedValueScaling::SedValueScaling(SedNamespaces *sedmlns)
  : SedScaling(sedmlns)
  , mWeight ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedValueScaling.
 */
SedValueScaling::SedValueScaling(const SedValueScaling& orig)
  : SedScaling( orig )
  , mWeight ( orig.mWeight )
{
}


/*
 * Assignment operator for SedValueScaling.
 */
SedValueScaling&
SedValueScaling::operator=(const SedValueScaling& rhs)
{
  if (&rhs != this)
  {
    SedScaling::operator=(rhs);
    mWeight = rhs.mWeight;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedValueScaling object.
 */
SedValueScaling*
SedValueScaling::clone() const
{
  return new SedValueScaling(*this);
}


/*
 * Destructor for SedValueScaling.
 */
SedValueScaling::~SedValueScaling()
{
}


/*
 * Returns the value of the "weight" attribute of this SedValueScaling.
 */
const std::string&
SedValueScaling::getWeight() const
{
  return mWeight;
}


/*
 * Predicate returning @c true if this SedValueScaling's "weight" attribute is
 * set.
 */
bool
SedValueScaling::isSetWeight() const
{
  return (mWeight.empty() == false);
}


/*
 * Sets the value of the "weight" attribute of this SedValueScaling.
 */
int
SedValueScaling::setWeight(const std::string& weight)
{
  mWeight = weight;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "weight" attribute of this SedValueScaling.
 */
int
SedValueScaling::unsetWeight()
{
  mWeight.erase();

  if (mWeight.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SedValueScaling object.
 */
const std::string&
SedValueScaling::getElementName() const
{
  static const string name = "valueScaling";
  return name;
}


/*
 * Returns the libSEDML type code for this SedValueScaling object.
 */
int
SedValueScaling::getTypeCode() const
{
  return SEDML_VALUESCALING;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedValueScaling object have been set.
 */
bool
SedValueScaling::hasRequiredAttributes() const
{
  bool allPresent = SedScaling::hasRequiredAttributes();

  if (isSetWeight() == false)
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
SedValueScaling::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedScaling::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedValueScaling::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedValueScaling::setSedDocument(SedDocument* d)
{
  SedScaling::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::getAttribute(const std::string& attributeName,
                              bool& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::getAttribute(const std::string& attributeName,
                              int& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::getAttribute(const std::string& attributeName,
                              double& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::getAttribute(const std::string& attributeName,
                              unsigned int& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::getAttribute(const std::string& attributeName,
                              std::string& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "weight")
  {
    value = getWeight();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedValueScaling's attribute
 * "attributeName" is set.
 */
bool
SedValueScaling::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedScaling::isSetAttribute(attributeName);

  if (attributeName == "weight")
  {
    value = isSetWeight();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::setAttribute(const std::string& attributeName,
                              unsigned int value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::setAttribute(const std::string& attributeName,
                              const std::string& value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  if (attributeName == "weight")
  {
    return_value = setWeight(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedValueScaling.
 */
int
SedValueScaling::unsetAttribute(const std::string& attributeName)
{
  int value = SedScaling::unsetAttribute(attributeName);

  if (attributeName == "weight")
  {
    value = unsetWeight();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedValueScaling::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedScaling::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedValueScaling::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedScaling::addExpectedAttributes(attributes);

  attributes.add("weight");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedValueScaling::readAttributes(
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

  SedScaling::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlValueScalingAllowedAttributes, level, version,
          details);
      }
    }
  }

  // 
  // weight string (use = "required" )
  // 

  assigned = attributes.readInto("weight", mWeight);

  if (assigned == true)
  {
    if (mWeight.empty() == true)
    {
      logEmptyString(mWeight, level, version, "<SedValueScaling>");
    }
  }
  else
  {
    std::string message = "Sedml attribute 'weight' is missing from the "
      "<SedValueScaling> element.";
    log->logError(SedmlValueScalingAllowedAttributes, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedValueScaling::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedScaling::writeAttributes(stream);

  if (isSetWeight() == true)
  {
    stream.writeAttribute("weight", getPrefix(), mWeight);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedValueScaling_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedValueScaling_t *
SedValueScaling_create(unsigned int level, unsigned int version)
{
  return new SedValueScaling(level, version);
}


/*
 * Creates and returns a deep copy of this SedValueScaling_t object.
 */
LIBSEDML_EXTERN
SedValueScaling_t*
SedValueScaling_clone(const SedValueScaling_t* svs)
{
  if (svs != NULL)
  {
    return static_cast<SedValueScaling_t*>(svs->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedValueScaling_t object.
 */
LIBSEDML_EXTERN
void
SedValueScaling_free(SedValueScaling_t* svs)
{
  if (svs != NULL)
  {
    delete svs;
  }
}


/*
 * Returns the value of the "weight" attribute of this SedValueScaling_t.
 */
LIBSEDML_EXTERN
char *
SedValueScaling_getWeight(const SedValueScaling_t * svs)
{
  if (svs == NULL)
  {
    return NULL;
  }

  return svs->getWeight().empty() ? NULL :
    safe_strdup(svs->getWeight().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedValueScaling_t's "weight"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedValueScaling_isSetWeight(const SedValueScaling_t * svs)
{
  return (svs != NULL) ? static_cast<int>(svs->isSetWeight()) : 0;
}


/*
 * Sets the value of the "weight" attribute of this SedValueScaling_t.
 */
LIBSEDML_EXTERN
int
SedValueScaling_setWeight(SedValueScaling_t * svs, const char * weight)
{
  return (svs != NULL) ? svs->setWeight(weight) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "weight" attribute of this SedValueScaling_t.
 */
LIBSEDML_EXTERN
int
SedValueScaling_unsetWeight(SedValueScaling_t * svs)
{
  return (svs != NULL) ? svs->unsetWeight() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedValueScaling_t object have been set.
 */
LIBSEDML_EXTERN
int
SedValueScaling_hasRequiredAttributes(const SedValueScaling_t * svs)
{
  return (svs != NULL) ? static_cast<int>(svs->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


