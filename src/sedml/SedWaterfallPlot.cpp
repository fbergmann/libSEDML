/**
 * @file SedWaterfallPlot.cpp
 * @brief Implementation of the SedWaterfallPlot class.
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
#include <sedml/SedWaterfallPlot.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedWaterfallPlot using the given SED-ML Level and @ p version
 * values.
 */
SedWaterfallPlot::SedWaterfallPlot(unsigned int level, unsigned int version)
  : SedPlot(level, version)
  , mTaskRef ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedWaterfallPlot using the given SedNamespaces object @p
 * sedmlns.
 */
SedWaterfallPlot::SedWaterfallPlot(SedNamespaces *sedmlns)
  : SedPlot(sedmlns)
  , mTaskRef ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedWaterfallPlot.
 */
SedWaterfallPlot::SedWaterfallPlot(const SedWaterfallPlot& orig)
  : SedPlot( orig )
  , mTaskRef ( orig.mTaskRef )
{
}


/*
 * Assignment operator for SedWaterfallPlot.
 */
SedWaterfallPlot&
SedWaterfallPlot::operator=(const SedWaterfallPlot& rhs)
{
  if (&rhs != this)
  {
    SedPlot::operator=(rhs);
    mTaskRef = rhs.mTaskRef;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedWaterfallPlot object.
 */
SedWaterfallPlot*
SedWaterfallPlot::clone() const
{
  return new SedWaterfallPlot(*this);
}


/*
 * Destructor for SedWaterfallPlot.
 */
SedWaterfallPlot::~SedWaterfallPlot()
{
}


/*
 * Returns the value of the "taskRef" attribute of this SedWaterfallPlot.
 */
const std::string&
SedWaterfallPlot::getTaskRef() const
{
  return mTaskRef;
}


/*
 * Predicate returning @c true if this SedWaterfallPlot's "taskRef" attribute
 * is set.
 */
bool
SedWaterfallPlot::isSetTaskRef() const
{
  return (mTaskRef.empty() == false);
}


/*
 * Sets the value of the "taskRef" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::setTaskRef(const std::string& taskRef)
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
 * Unsets the value of the "taskRef" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::unsetTaskRef()
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
SedWaterfallPlot::renameSIdRefs(const std::string& oldid,
                                const std::string& newid)
{
  if (isSetTaskRef() && mTaskRef == oldid)
  {
    setTaskRef(newid);
  }
}


/*
 * Returns the XML element name of this SedWaterfallPlot object.
 */
const std::string&
SedWaterfallPlot::getElementName() const
{
  static const string name = "waterfallPlot";
  return name;
}


/*
 * Returns the libSEDML type code for this SedWaterfallPlot object.
 */
int
SedWaterfallPlot::getTypeCode() const
{
  return SEDML_WATERFALLPLOT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedWaterfallPlot object have been set.
 */
bool
SedWaterfallPlot::hasRequiredAttributes() const
{
  bool allPresent = SedPlot::hasRequiredAttributes();

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
SedWaterfallPlot::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
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
SedWaterfallPlot::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedWaterfallPlot::setSedDocument(SedDocument* d)
{
  SedPlot::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::getAttribute(const std::string& attributeName,
                               bool& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::getAttribute(const std::string& attributeName,
                               int& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::getAttribute(const std::string& attributeName,
                               double& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::getAttribute(const std::string& attributeName,
                               unsigned int& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::getAttribute(const std::string& attributeName,
                               std::string& value) const
{
  int return_value = SedPlot::getAttribute(attributeName, value);

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
 * Predicate returning @c true if this SedWaterfallPlot's attribute
 * "attributeName" is set.
 */
bool
SedWaterfallPlot::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedPlot::isSetAttribute(attributeName);

  if (attributeName == "taskRef")
  {
    value = isSetTaskRef();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::setAttribute(const std::string& attributeName,
                               unsigned int value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::setAttribute(const std::string& attributeName,
                               const std::string& value)
{
  int return_value = SedPlot::setAttribute(attributeName, value);

  if (attributeName == "taskRef")
  {
    return_value = setTaskRef(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedWaterfallPlot.
 */
int
SedWaterfallPlot::unsetAttribute(const std::string& attributeName)
{
  int value = SedPlot::unsetAttribute(attributeName);

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
SedWaterfallPlot::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
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
SedWaterfallPlot::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedPlot::addExpectedAttributes(attributes);

  attributes.add("taskRef");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedWaterfallPlot::readAttributes(
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
        log->logError(SedmlWaterfallPlotAllowedAttributes, level, version,
          details, getLine(), getColumn());
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
      logEmptyString(mTaskRef, level, version, "<SedWaterfallPlot>");
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
      logError(SedmlWaterfallPlotTaskRefMustBeTask, level, version, msg,
        getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'taskRef' is missing from the "
        "<SedWaterfallPlot> element.";
      log->logError(SedmlWaterfallPlotAllowedAttributes, level, version,
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
SedWaterfallPlot::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedPlot::writeAttributes(stream);

  if (isSetTaskRef() == true)
  {
    stream.writeAttribute("taskRef", getPrefix(), mTaskRef);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedWaterfallPlot_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedWaterfallPlot_t *
SedWaterfallPlot_create(unsigned int level, unsigned int version)
{
  return new SedWaterfallPlot(level, version);
}


/*
 * Creates and returns a deep copy of this SedWaterfallPlot_t object.
 */
LIBSEDML_EXTERN
SedWaterfallPlot_t*
SedWaterfallPlot_clone(const SedWaterfallPlot_t* swp)
{
  if (swp != NULL)
  {
    return static_cast<SedWaterfallPlot_t*>(swp->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedWaterfallPlot_t object.
 */
LIBSEDML_EXTERN
void
SedWaterfallPlot_free(SedWaterfallPlot_t* swp)
{
  if (swp != NULL)
  {
    delete swp;
  }
}


/*
 * Returns the value of the "taskRef" attribute of this SedWaterfallPlot_t.
 */
LIBSEDML_EXTERN
char *
SedWaterfallPlot_getTaskRef(const SedWaterfallPlot_t * swp)
{
  if (swp == NULL)
  {
    return NULL;
  }

  return swp->getTaskRef().empty() ? NULL :
    safe_strdup(swp->getTaskRef().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedWaterfallPlot_t's "taskRef"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedWaterfallPlot_isSetTaskRef(const SedWaterfallPlot_t * swp)
{
  return (swp != NULL) ? static_cast<int>(swp->isSetTaskRef()) : 0;
}


/*
 * Sets the value of the "taskRef" attribute of this SedWaterfallPlot_t.
 */
LIBSEDML_EXTERN
int
SedWaterfallPlot_setTaskRef(SedWaterfallPlot_t * swp, const char * taskRef)
{
  return (swp != NULL) ? swp->setTaskRef(taskRef) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "taskRef" attribute of this SedWaterfallPlot_t.
 */
LIBSEDML_EXTERN
int
SedWaterfallPlot_unsetTaskRef(SedWaterfallPlot_t * swp)
{
  return (swp != NULL) ? swp->unsetTaskRef() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedWaterfallPlot_t object have been set.
 */
LIBSEDML_EXTERN
int
SedWaterfallPlot_hasRequiredAttributes(const SedWaterfallPlot_t * swp)
{
  return (swp != NULL) ? static_cast<int>(swp->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


