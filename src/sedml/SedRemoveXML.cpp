/**
 * @file SedRemoveXML.cpp
 * @brief Implementation of the SedRemoveXML class.
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
#include <sedml/SedRemoveXML.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedRemoveXML using the given SED-ML Level and @ p version
 * values.
 */
SedRemoveXML::SedRemoveXML(unsigned int level, unsigned int version)
  : SedChange(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedRemoveXML using the given SedNamespaces object @p sedmlns.
 */
SedRemoveXML::SedRemoveXML(SedNamespaces *sedmlns)
  : SedChange(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedRemoveXML.
 */
SedRemoveXML::SedRemoveXML(const SedRemoveXML& orig)
  : SedChange( orig )
{
}


/*
 * Assignment operator for SedRemoveXML.
 */
SedRemoveXML&
SedRemoveXML::operator=(const SedRemoveXML& rhs)
{
  if (&rhs != this)
  {
    SedChange::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedRemoveXML object.
 */
SedRemoveXML*
SedRemoveXML::clone() const
{
  return new SedRemoveXML(*this);
}


/*
 * Destructor for SedRemoveXML.
 */
SedRemoveXML::~SedRemoveXML()
{
}


/*
 * Returns the XML element name of this SedRemoveXML object.
 */
const std::string&
SedRemoveXML::getElementName() const
{
  static const string name = "removeXML";
  return name;
}


/*
 * Returns the libSEDML type code for this SedRemoveXML object.
 */
int
SedRemoveXML::getTypeCode() const
{
  return SEDML_CHANGE_REMOVEXML;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedRemoveXML object have been set.
 */
bool
SedRemoveXML::hasRequiredAttributes() const
{
  bool allPresent = SedChange::hasRequiredAttributes();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedRemoveXML::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedChange::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedRemoveXML::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedRemoveXML::setSedDocument(SedDocument* d)
{
  SedChange::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedRemoveXML's attribute "attributeName"
 * is set.
 */
bool
SedRemoveXML::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedChange::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedRemoveXML.
 */
int
SedRemoveXML::unsetAttribute(const std::string& attributeName)
{
  int value = SedChange::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedRemoveXML::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedChange::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedRemoveXML::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedChange::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedRemoveXML::readAttributes(
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

  SedChange::readAttributes(attributes, expectedAttributes);

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
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedRemoveXML::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedChange::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedRemoveXML_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedRemoveXML_t *
SedRemoveXML_create(unsigned int level, unsigned int version)
{
  return new SedRemoveXML(level, version);
}


/*
 * Creates and returns a deep copy of this SedRemoveXML_t object.
 */
LIBSEDML_EXTERN
SedRemoveXML_t*
SedRemoveXML_clone(const SedRemoveXML_t* srxml)
{
  if (srxml != NULL)
  {
    return static_cast<SedRemoveXML_t*>(srxml->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedRemoveXML_t object.
 */
LIBSEDML_EXTERN
void
SedRemoveXML_free(SedRemoveXML_t* srxml)
{
  if (srxml != NULL)
  {
    delete srxml;
  }
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedRemoveXML_t object have been set.
 */
LIBSEDML_EXTERN
int
SedRemoveXML_hasRequiredAttributes(const SedRemoveXML_t * srxml)
{
  return (srxml != NULL) ? static_cast<int>(srxml->hasRequiredAttributes()) :
    0;
}




LIBSEDML_CPP_NAMESPACE_END


