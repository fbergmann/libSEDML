/**
 * @file SedDataSource.cpp
 * @brief Implementation of the SedDataSource class.
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
#include <sedml/SedDataSource.h>
#include <sedml/SedListOfDataSources.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedDataSource using the given SED-ML Level and @ p version
 * values.
 */
SedDataSource::SedDataSource(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mIndexSet ("")
  , mSlices (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Creates a new SedDataSource using the given SedNamespaces object @p sedmlns.
 */
SedDataSource::SedDataSource(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mIndexSet ("")
  , mSlices (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Copy constructor for SedDataSource.
 */
SedDataSource::SedDataSource(const SedDataSource& orig)
  : SedBase( orig )
  , mIndexSet ( orig.mIndexSet )
  , mSlices ( orig.mSlices )
{
  connectToChild();
}


/*
 * Assignment operator for SedDataSource.
 */
SedDataSource&
SedDataSource::operator=(const SedDataSource& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mIndexSet = rhs.mIndexSet;
    mSlices = rhs.mSlices;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedDataSource object.
 */
SedDataSource*
SedDataSource::clone() const
{
  return new SedDataSource(*this);
}


/*
 * Destructor for SedDataSource.
 */
SedDataSource::~SedDataSource()
{
}


/*
 * Returns the value of the "indexSet" attribute of this SedDataSource.
 */
const std::string&
SedDataSource::getIndexSet() const
{
  return mIndexSet;
}


/*
 * Predicate returning @c true if this SedDataSource's "indexSet" attribute is
 * set.
 */
bool
SedDataSource::isSetIndexSet() const
{
  return (mIndexSet.empty() == false);
}


/*
 * Sets the value of the "indexSet" attribute of this SedDataSource.
 */
int
SedDataSource::setIndexSet(const std::string& indexSet)
{
  if (!(SyntaxChecker::isValidInternalSId(indexSet)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mIndexSet = indexSet;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "indexSet" attribute of this SedDataSource.
 */
int
SedDataSource::unsetIndexSet()
{
  mIndexSet.erase();

  if (mIndexSet.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfSlices from this SedDataSource.
 */
const SedListOfSlices*
SedDataSource::getListOfSlices() const
{
  return &mSlices;
}


/*
 * Returns the SedListOfSlices from this SedDataSource.
 */
SedListOfSlices*
SedDataSource::getListOfSlices()
{
  return &mSlices;
}


/*
 * Get a SedSlice from the SedDataSource.
 */
SedSlice*
SedDataSource::getSlice(unsigned int n)
{
  return mSlices.get(n);
}


/*
 * Get a SedSlice from the SedDataSource.
 */
const SedSlice*
SedDataSource::getSlice(unsigned int n) const
{
  return mSlices.get(n);
}


/*
 * Get a SedSlice from the SedDataSource based on the Reference to which it
 * refers.
 */
const SedSlice*
SedDataSource::getSliceByReference(const std::string& sid) const
{
  return mSlices.getByReference(sid);
}


/*
 * Get a SedSlice from the SedDataSource based on the Reference to which it
 * refers.
 */
SedSlice*
SedDataSource::getSliceByReference(const std::string& sid)
{
  return mSlices.getByReference(sid);
}


/*
 * Get a SedSlice from the SedDataSource based on the Index to which it refers.
 */
const SedSlice*
SedDataSource::getSliceByIndex(const std::string& sid) const
{
  return mSlices.getByIndex(sid);
}


/*
 * Get a SedSlice from the SedDataSource based on the Index to which it refers.
 */
SedSlice*
SedDataSource::getSliceByIndex(const std::string& sid)
{
  return mSlices.getByIndex(sid);
}


/*
 * Adds a copy of the given SedSlice to this SedDataSource.
 */
int
SedDataSource::addSlice(const SedSlice* ss)
{
  if (ss == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ss->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ss->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ss->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ss)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mSlices.append(ss);
  }
}


/*
 * Get the number of SedSlice objects in this SedDataSource.
 */
unsigned int
SedDataSource::getNumSlices() const
{
  return mSlices.size();
}


/*
 * Creates a new SedSlice object, adds it to this SedDataSource object and
 * returns the SedSlice object created.
 */
SedSlice*
SedDataSource::createSlice()
{
  SedSlice* ss = NULL;

  try
  {
    ss = new SedSlice(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ss != NULL)
  {
    mSlices.appendAndOwn(ss);
  }

  return ss;
}


/*
 * Removes the nth SedSlice from this SedDataSource and returns a pointer to
 * it.
 */
SedSlice*
SedDataSource::removeSlice(unsigned int n)
{
  return mSlices.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedDataSource::renameSIdRefs(const std::string& oldid,
                             const std::string& newid)
{
  if (isSetIndexSet() && mIndexSet == oldid)
  {
    setIndexSet(newid);
  }
}


/*
 * Returns the XML element name of this SedDataSource object.
 */
const std::string&
SedDataSource::getElementName() const
{
  static const string name = "dataSource";
  return name;
}


/*
 * Returns the libSEDML type code for this SedDataSource object.
 */
int
SedDataSource::getTypeCode() const
{
  return SEDML_DATA_SOURCE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedDataSource object have been set.
 */
bool
SedDataSource::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
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
SedDataSource::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (getNumSlices() > 0)
  {
    mSlices.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedDataSource::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedDataSource::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mSlices.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedDataSource::connectToChild()
{
  SedBase::connectToChild();

  mSlices.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::getAttribute(const std::string& attributeName,
                            bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::getAttribute(const std::string& attributeName,
                            int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::getAttribute(const std::string& attributeName,
                            double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::getAttribute(const std::string& attributeName,
                            unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::getAttribute(const std::string& attributeName,
                            std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "indexSet")
  {
    value = getIndexSet();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedDataSource's attribute
 * "attributeName" is set.
 */
bool
SedDataSource::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "indexSet")
  {
    value = isSetIndexSet();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::setAttribute(const std::string& attributeName,
                            unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::setAttribute(const std::string& attributeName,
                            const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "indexSet")
  {
    return_value = setIndexSet(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedDataSource.
 */
int
SedDataSource::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "indexSet")
  {
    value = unsetIndexSet();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedDataSource.
 */
SedBase*
SedDataSource::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "slice")
  {
    return createSlice();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedDataSource.
 */
int
SedDataSource::addChildObject(const std::string& elementName,
                              const SedBase* element)
{
  if (elementName == "slice" && element->getTypeCode() == SEDML_DATA_SLICE)
  {
    return addSlice((const SedSlice*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedDataSource.
 */
SedBase*
SedDataSource::removeChildObject(const std::string& elementName,
                                 const std::string& id)
{
  if (elementName == "slice")
  {
    for (unsigned int i = 0; i < getNumSlices(); i++)
    {
      if (getSlice(i)->getId() == id)
      {
        return removeSlice(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedDataSource.
 */
unsigned int
SedDataSource::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "slice")
  {
    return getNumSlices();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedDataSource.
 */
SedBase*
SedDataSource::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "slice")
  {
    return getSlice(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedDataSource::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mSlices.getElementBySId(id);

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
SedDataSource::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mSlices, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedDataSource::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfSlices")
  {
    if (getErrorLog() && mSlices.size() != 0)
    {
      getErrorLog()->logError(SedmlDataSourceAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mSlices;
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
SedDataSource::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("indexSet");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedDataSource::readAttributes(
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

  if (log && getParentSedObject() &&
    static_cast<SedListOfDataSources*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDataDescriptionLODataSourcesAllowedCoreAttributes,
          level, version, details, getLine(), getColumn());
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
        log->logError(SedmlDataSourceAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  if(!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedDataSource> element.";
      log->logError(SedmlDataSourceAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // indexSet SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("indexSet", mIndexSet);

  if (assigned == true)
  {
    if (mIndexSet.empty() == true)
    {
      logEmptyString(mIndexSet, level, version, "<SedDataSource>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mIndexSet) == false)
    {
      std::string msg = "The indexSet attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mIndexSet + "', which does not conform to the syntax.";
      logError(SedmlDataSourceIndexSetMustBeSId, level, version, msg,
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
SedDataSource::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetIndexSet() == true)
  {
    stream.writeAttribute("indexSet", getPrefix(), mIndexSet);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDataSource_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedDataSource_t *
SedDataSource_create(unsigned int level, unsigned int version)
{
  return new SedDataSource(level, version);
}


/*
 * Creates and returns a deep copy of this SedDataSource_t object.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataSource_clone(const SedDataSource_t* sds)
{
  if (sds != NULL)
  {
    return static_cast<SedDataSource_t*>(sds->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedDataSource_t object.
 */
LIBSEDML_EXTERN
void
SedDataSource_free(SedDataSource_t* sds)
{
  if (sds != NULL)
  {
    delete sds;
  }
}


/*
 * Returns the value of the "id" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
char *
SedDataSource_getId(const SedDataSource_t * sds)
{
  if (sds == NULL)
  {
    return NULL;
  }

  return sds->getId().empty() ? NULL : safe_strdup(sds->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
char *
SedDataSource_getName(const SedDataSource_t * sds)
{
  if (sds == NULL)
  {
    return NULL;
  }

  return sds->getName().empty() ? NULL : safe_strdup(sds->getName().c_str());
}


/*
 * Returns the value of the "indexSet" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
char *
SedDataSource_getIndexSet(const SedDataSource_t * sds)
{
  if (sds == NULL)
  {
    return NULL;
  }

  return sds->getIndexSet().empty() ? NULL :
    safe_strdup(sds->getIndexSet().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedDataSource_t's "id" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetId(const SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDataSource_t's "name" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetName(const SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDataSource_t's "indexSet"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetIndexSet(const SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetIndexSet()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
int
SedDataSource_setId(SedDataSource_t * sds, const char * id)
{
  return (sds != NULL) ? sds->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
int
SedDataSource_setName(SedDataSource_t * sds, const char * name)
{
  return (sds != NULL) ? sds->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "indexSet" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
int
SedDataSource_setIndexSet(SedDataSource_t * sds, const char * indexSet)
{
  return (sds != NULL) ? sds->setIndexSet(indexSet) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetId(SedDataSource_t * sds)
{
  return (sds != NULL) ? sds->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetName(SedDataSource_t * sds)
{
  return (sds != NULL) ? sds->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "indexSet" attribute of this SedDataSource_t.
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetIndexSet(SedDataSource_t * sds)
{
  return (sds != NULL) ? sds->unsetIndexSet() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedSlice_t objects from this
 * SedDataSource_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataSource_getListOfSlices(SedDataSource_t* sds)
{
  return (sds != NULL) ? sds->getListOfSlices() : NULL;
}


/*
 * Get a SedSlice_t from the SedDataSource_t.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_getSlice(SedDataSource_t* sds, unsigned int n)
{
  return (sds != NULL) ? sds->getSlice(n) : NULL;
}


/*
 * Get a SedSlice_t from the SedDataSource_t based on the Reference to which it
 * refers.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_getSliceByReference(SedDataSource_t* sds, const char *sid)
{
  return (sds != NULL && sid != NULL) ? sds->getSliceByReference(sid) : NULL;
}


/*
 * Get a SedSlice_t from the SedDataSource_t based on the Index to which it
 * refers.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_getSliceByIndex(SedDataSource_t* sds, const char *sid)
{
  return (sds != NULL && sid != NULL) ? sds->getSliceByIndex(sid) : NULL;
}


/*
 * Adds a copy of the given SedSlice_t to this SedDataSource_t.
 */
LIBSEDML_EXTERN
int
SedDataSource_addSlice(SedDataSource_t* sds, const SedSlice_t* ss)
{
  return (sds != NULL) ? sds->addSlice(ss) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedSlice_t objects in this SedDataSource_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDataSource_getNumSlices(SedDataSource_t* sds)
{
  return (sds != NULL) ? sds->getNumSlices() : SEDML_INT_MAX;
}


/*
 * Creates a new SedSlice_t object, adds it to this SedDataSource_t object and
 * returns the SedSlice_t object created.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_createSlice(SedDataSource_t* sds)
{
  return (sds != NULL) ? sds->createSlice() : NULL;
}


/*
 * Removes the nth SedSlice_t from this SedDataSource_t and returns a pointer
 * to it.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_removeSlice(SedDataSource_t* sds, unsigned int n)
{
  return (sds != NULL) ? sds->removeSlice(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDataSource_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDataSource_hasRequiredAttributes(const SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


