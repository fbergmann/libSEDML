/**
 * @file SedModel.cpp
 * @brief Implementation of the SedModel class.
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
#include <sedml/SedModel.h>
#include <sedml/SedListOfModels.h>
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
 * Creates a new SedModel using the given SED-ML Level and @ p version values.
 */
SedModel::SedModel(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mLanguage ("")
  , mSource ("")
  , mChanges (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Creates a new SedModel using the given SedNamespaces object @p sedmlns.
 */
SedModel::SedModel(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mLanguage ("")
  , mSource ("")
  , mChanges (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Copy constructor for SedModel.
 */
SedModel::SedModel(const SedModel& orig)
  : SedBase( orig )
  , mLanguage ( orig.mLanguage )
  , mSource ( orig.mSource )
  , mChanges ( orig.mChanges )
{
  connectToChild();
}


/*
 * Assignment operator for SedModel.
 */
SedModel&
SedModel::operator=(const SedModel& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mLanguage = rhs.mLanguage;
    mSource = rhs.mSource;
    mChanges = rhs.mChanges;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedModel object.
 */
SedModel*
SedModel::clone() const
{
  return new SedModel(*this);
}


/*
 * Destructor for SedModel.
 */
SedModel::~SedModel()
{
}


/*
 * Returns the value of the "language" attribute of this SedModel.
 */
const std::string&
SedModel::getLanguage() const
{
  return mLanguage;
}


/*
 * Returns the value of the "source" attribute of this SedModel.
 */
const std::string&
SedModel::getSource() const
{
  return mSource;
}


/*
 * Predicate returning @c true if this SedModel's "language" attribute is set.
 */
bool
SedModel::isSetLanguage() const
{
  return (mLanguage.empty() == false);
}


/*
 * Predicate returning @c true if this SedModel's "source" attribute is set.
 */
bool
SedModel::isSetSource() const
{
  return (mSource.empty() == false);
}


/*
 * Sets the value of the "language" attribute of this SedModel.
 */
int
SedModel::setLanguage(const std::string& language)
{
  mLanguage = language;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "source" attribute of this SedModel.
 */
int
SedModel::setSource(const std::string& source)
{
  mSource = source;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "language" attribute of this SedModel.
 */
int
SedModel::unsetLanguage()
{
  mLanguage.erase();

  if (mLanguage.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "source" attribute of this SedModel.
 */
int
SedModel::unsetSource()
{
  mSource.erase();

  if (mSource.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfChanges from this SedModel.
 */
const SedListOfChanges*
SedModel::getListOfChanges() const
{
  return &mChanges;
}


/*
 * Returns the SedListOfChanges from this SedModel.
 */
SedListOfChanges*
SedModel::getListOfChanges()
{
  return &mChanges;
}


/*
 * Get a SedChange from the SedModel.
 */
SedChange*
SedModel::getChange(unsigned int n)
{
  return mChanges.get(n);
}


/*
 * Get a SedChange from the SedModel.
 */
const SedChange*
SedModel::getChange(unsigned int n) const
{
  return mChanges.get(n);
}


/*
 * Adds a copy of the given SedChange to this SedModel.
 */
int
SedModel::addChange(const SedChange* sc)
{
  if (sc == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sc->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sc->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sc->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sc)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mChanges.append(sc);
  }
}


/*
 * Get the number of SedChange objects in this SedModel.
 */
unsigned int
SedModel::getNumChanges() const
{
  return mChanges.size();
}


/*
 * Creates a new SedAddXML object, adds it to this SedModel object and returns
 * the SedAddXML object created.
 */
SedAddXML*
SedModel::createAddXML()
{
  SedAddXML* saxml = NULL;

  try
  {
    saxml = new SedAddXML(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (saxml != NULL)
  {
    mChanges.appendAndOwn(saxml);
  }

  return saxml;
}


/*
 * Creates a new SedChangeXML object, adds it to this SedModel object and
 * returns the SedChangeXML object created.
 */
SedChangeXML*
SedModel::createChangeXML()
{
  SedChangeXML* scxml = NULL;

  try
  {
    scxml = new SedChangeXML(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (scxml != NULL)
  {
    mChanges.appendAndOwn(scxml);
  }

  return scxml;
}


/*
 * Creates a new SedRemoveXML object, adds it to this SedModel object and
 * returns the SedRemoveXML object created.
 */
SedRemoveXML*
SedModel::createRemoveXML()
{
  SedRemoveXML* srxml = NULL;

  try
  {
    srxml = new SedRemoveXML(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (srxml != NULL)
  {
    mChanges.appendAndOwn(srxml);
  }

  return srxml;
}


/*
 * Creates a new SedChangeAttribute object, adds it to this SedModel object and
 * returns the SedChangeAttribute object created.
 */
SedChangeAttribute*
SedModel::createChangeAttribute()
{
  SedChangeAttribute* sca = NULL;

  try
  {
    sca = new SedChangeAttribute(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sca != NULL)
  {
    mChanges.appendAndOwn(sca);
  }

  return sca;
}


/*
 * Creates a new SedComputeChange object, adds it to this SedModel object and
 * returns the SedComputeChange object created.
 */
SedComputeChange*
SedModel::createComputeChange()
{
  SedComputeChange* scc = NULL;

  try
  {
    scc = new SedComputeChange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (scc != NULL)
  {
    mChanges.appendAndOwn(scc);
  }

  return scc;
}


/*
 * Removes the nth SedChange from this SedModel and returns a pointer to it.
 */
SedChange*
SedModel::removeChange(unsigned int n)
{
  return mChanges.remove(n);
}


/*
 * Returns the XML element name of this SedModel object.
 */
const std::string&
SedModel::getElementName() const
{
  static const string name = "model";
  return name;
}


/*
 * Returns the libSEDML type code for this SedModel object.
 */
int
SedModel::getTypeCode() const
{
  return SEDML_MODEL;
}


/*
 * Predicate returning @c true if all the required attributes for this SedModel
 * object have been set.
 */
bool
SedModel::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetSource() == false)
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
SedModel::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (getNumChanges() > 0)
  {
    mChanges.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedModel::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedModel::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mChanges.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedModel::connectToChild()
{
  SedBase::connectToChild();

  mChanges.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "language")
  {
    value = getLanguage();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "source")
  {
    value = getSource();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedModel's attribute "attributeName" is
 * set.
 */
bool
SedModel::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "language")
  {
    value = isSetLanguage();
  }
  else if (attributeName == "source")
  {
    value = isSetSource();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "language")
  {
    return_value = setLanguage(value);
  }
  else if (attributeName == "source")
  {
    return_value = setSource(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedModel.
 */
int
SedModel::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "language")
  {
    value = unsetLanguage();
  }
  else if (attributeName == "source")
  {
    value = unsetSource();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedModel.
 */
SedBase*
SedModel::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "addXML")
  {
    return createAddXML();
  }
  else if (elementName == "changeXML")
  {
    return createChangeXML();
  }
  else if (elementName == "removeXML")
  {
    return createRemoveXML();
  }
  else if (elementName == "changeAttribute")
  {
    return createChangeAttribute();
  }
  else if (elementName == "computeChange")
  {
    return createComputeChange();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedModel.
 */
int
SedModel::addChildObject(const std::string& elementName,
                         const SedBase* element)
{
  if (elementName == "addXML" && element->getTypeCode() == SEDML_CHANGE_ADDXML)
  {
    return addChange((const SedChange*)(element));
  }
  else if (elementName == "changeXML" && element->getTypeCode() ==
    SEDML_CHANGE_CHANGEXML)
  {
    return addChange((const SedChange*)(element));
  }
  else if (elementName == "removeXML" && element->getTypeCode() ==
    SEDML_CHANGE_REMOVEXML)
  {
    return addChange((const SedChange*)(element));
  }
  else if (elementName == "changeAttribute" && element->getTypeCode() ==
    SEDML_CHANGE_ATTRIBUTE)
  {
    return addChange((const SedChange*)(element));
  }
  else if (elementName == "computeChange" && element->getTypeCode() ==
    SEDML_CHANGE_COMPUTECHANGE)
  {
    return addChange((const SedChange*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedModel.
 */
SedBase*
SedModel::removeChildObject(const std::string& elementName,
                            const std::string& id)
{
  if (elementName == "addXML")
  {
    for (unsigned int i = 0; i < getNumChanges(); i++)
    {
      if (getChange(i)->getId() == id)
      {
        return removeChange(i);
      }
    }
  }
  else if (elementName == "changeXML")
  {
    for (unsigned int i = 0; i < getNumChanges(); i++)
    {
      if (getChange(i)->getId() == id)
      {
        return removeChange(i);
      }
    }
  }
  else if (elementName == "removeXML")
  {
    for (unsigned int i = 0; i < getNumChanges(); i++)
    {
      if (getChange(i)->getId() == id)
      {
        return removeChange(i);
      }
    }
  }
  else if (elementName == "changeAttribute")
  {
    for (unsigned int i = 0; i < getNumChanges(); i++)
    {
      if (getChange(i)->getId() == id)
      {
        return removeChange(i);
      }
    }
  }
  else if (elementName == "computeChange")
  {
    for (unsigned int i = 0; i < getNumChanges(); i++)
    {
      if (getChange(i)->getId() == id)
      {
        return removeChange(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedModel.
 */
unsigned int
SedModel::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "change")
  {
    return getNumChanges();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedModel.
 */
SedBase*
SedModel::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "change")
  {
    return getChange(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedModel::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mChanges.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns a List of all child SedBase objects, including those nested to an
 * arbitrary depth.
 */
List*
SedModel::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mChanges, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedModel::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfChanges")
  {
    if (getErrorLog() && mChanges.size() != 0)
    {
      getErrorLog()->logError(SedmlModelAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mChanges;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedModel::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("language");

  attributes.add("source");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedModel::readAttributes(
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
    static_cast<SedListOfModels*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDocumentLOModelsAllowedCoreAttributes, level,
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
        log->logError(SedmlModelAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  if(!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedModel> element.";
      log->logError(SedmlModelAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // language string (use = "required" )
  // 

  assigned = attributes.readInto("language", mLanguage);

  if (assigned == true)
  {
    if (mLanguage.empty() == true)
    {
      logEmptyString(mLanguage, level, version, "<SedModel>");
    }
  }
  else if (getLevel() > 1 || getVersion() >= 4)
  {
      if (log)
      {
          std::string message = "Sedml attribute 'language' is missing from the "
              "<SedModel> element.";
          log->logError(SedmlModelAllowedAttributes, level, version, message,
              getLine(), getColumn());
      }
  }

  // 
  // source string (use = "required" )
  // 

  assigned = attributes.readInto("source", mSource);

  if (assigned == true)
  {
    if (mSource.empty() == true)
    {
      logEmptyString(mSource, level, version, "<SedModel>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'source' is missing from the "
        "<SedModel> element.";
      log->logError(SedmlModelAllowedAttributes, level, version, message,
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
SedModel::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetLanguage() == true)
  {
    stream.writeAttribute("language", getPrefix(), mLanguage);
  }

  if (isSetSource() == true)
  {
    stream.writeAttribute("source", getPrefix(), mSource);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedModel_t using the given SED-ML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedModel_t *
SedModel_create(unsigned int level, unsigned int version)
{
  return new SedModel(level, version);
}


/*
 * Creates and returns a deep copy of this SedModel_t object.
 */
LIBSEDML_EXTERN
SedModel_t*
SedModel_clone(const SedModel_t* sm)
{
  if (sm != NULL)
  {
    return static_cast<SedModel_t*>(sm->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedModel_t object.
 */
LIBSEDML_EXTERN
void
SedModel_free(SedModel_t* sm)
{
  if (sm != NULL)
  {
    delete sm;
  }
}


/*
 * Returns the value of the "id" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
char *
SedModel_getId(const SedModel_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getId().empty() ? NULL : safe_strdup(sm->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
char *
SedModel_getName(const SedModel_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getName().empty() ? NULL : safe_strdup(sm->getName().c_str());
}


/*
 * Returns the value of the "language" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
char *
SedModel_getLanguage(const SedModel_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getLanguage().empty() ? NULL :
    safe_strdup(sm->getLanguage().c_str());
}


/*
 * Returns the value of the "source" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
char *
SedModel_getSource(const SedModel_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getSource().empty() ? NULL : safe_strdup(sm->getSource().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedModel_t's "id" attribute is set.
 */
LIBSEDML_EXTERN
int
SedModel_isSetId(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedModel_t's "name" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedModel_isSetName(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedModel_t's "language" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedModel_isSetLanguage(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetLanguage()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedModel_t's "source" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedModel_isSetSource(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetSource()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_setId(SedModel_t * sm, const char * id)
{
  return (sm != NULL) ? sm->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_setName(SedModel_t * sm, const char * name)
{
  return (sm != NULL) ? sm->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "language" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_setLanguage(SedModel_t * sm, const char * language)
{
  return (sm != NULL) ? sm->setLanguage(language) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "source" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_setSource(SedModel_t * sm, const char * source)
{
  return (sm != NULL) ? sm->setSource(source) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_unsetId(SedModel_t * sm)
{
  return (sm != NULL) ? sm->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_unsetName(SedModel_t * sm)
{
  return (sm != NULL) ? sm->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "language" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_unsetLanguage(SedModel_t * sm)
{
  return (sm != NULL) ? sm->unsetLanguage() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "source" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_unsetSource(SedModel_t * sm)
{
  return (sm != NULL) ? sm->unsetSource() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedChange_t objects from this SedModel_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedModel_getListOfChanges(SedModel_t* sm)
{
  return (sm != NULL) ? sm->getListOfChanges() : NULL;
}


/*
 * Get a SedChange_t from the SedModel_t.
 */
LIBSEDML_EXTERN
SedChange_t*
SedModel_getChange(SedModel_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->getChange(n) : NULL;
}


/*
 * Adds a copy of the given SedChange_t to this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_addChange(SedModel_t* sm, const SedChange_t* sc)
{
  return (sm != NULL) ? sm->addChange(sc) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedChange_t objects in this SedModel_t.
 */
LIBSEDML_EXTERN
unsigned int
SedModel_getNumChanges(SedModel_t* sm)
{
  return (sm != NULL) ? sm->getNumChanges() : SEDML_INT_MAX;
}


/*
 * Creates a new SedAddXML_t object, adds it to this SedModel_t object and
 * returns the SedAddXML_t object created.
 */
LIBSEDML_EXTERN
SedAddXML_t*
SedModel_createAddXML(SedModel_t* sm)
{
  return (sm != NULL) ? sm->createAddXML() : NULL;
}


/*
 * Creates a new SedChangeXML_t object, adds it to this SedModel_t object and
 * returns the SedChangeXML_t object created.
 */
LIBSEDML_EXTERN
SedChangeXML_t*
SedModel_createChangeXML(SedModel_t* sm)
{
  return (sm != NULL) ? sm->createChangeXML() : NULL;
}


/*
 * Creates a new SedRemoveXML_t object, adds it to this SedModel_t object and
 * returns the SedRemoveXML_t object created.
 */
LIBSEDML_EXTERN
SedRemoveXML_t*
SedModel_createRemoveXML(SedModel_t* sm)
{
  return (sm != NULL) ? sm->createRemoveXML() : NULL;
}


/*
 * Creates a new SedChangeAttribute_t object, adds it to this SedModel_t object
 * and returns the SedChangeAttribute_t object created.
 */
LIBSEDML_EXTERN
SedChangeAttribute_t*
SedModel_createChangeAttribute(SedModel_t* sm)
{
  return (sm != NULL) ? sm->createChangeAttribute() : NULL;
}


/*
 * Creates a new SedComputeChange_t object, adds it to this SedModel_t object
 * and returns the SedComputeChange_t object created.
 */
LIBSEDML_EXTERN
SedComputeChange_t*
SedModel_createComputeChange(SedModel_t* sm)
{
  return (sm != NULL) ? sm->createComputeChange() : NULL;
}


/*
 * Removes the nth SedChange_t from this SedModel_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedChange_t*
SedModel_removeChange(SedModel_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->removeChange(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedModel_t object have been set.
 */
LIBSEDML_EXTERN
int
SedModel_hasRequiredAttributes(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


