/**
 * @file SedDataDescription.cpp
 * @brief Implementation of the SedDataDescription class.
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
#include <sedml/SedDataDescription.h>
#include <sedml/SedListOfDataDescriptions.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedDataDescription using the given SED-ML Level and @ p version
 * values.
 */
SedDataDescription::SedDataDescription(unsigned int level,
                                       unsigned int version)
  : SedBase(level, version)
  , mFormat ("")
  , mSource ("")
  , mDimensionDescription (NULL)
  , mDataSources (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Creates a new SedDataDescription using the given SedNamespaces object @p
 * sedmlns.
 */
SedDataDescription::SedDataDescription(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mFormat ("")
  , mSource ("")
  , mDimensionDescription (NULL)
  , mDataSources (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
  mIdAllowedPreV4 = true;
  mNameAllowedPreV4 = true;
}


/*
 * Copy constructor for SedDataDescription.
 */
SedDataDescription::SedDataDescription(const SedDataDescription& orig)
  : SedBase( orig )
  , mFormat ( orig.mFormat )
  , mSource ( orig.mSource )
  , mDimensionDescription ( NULL )
  , mDataSources ( orig.mDataSources )
{
  if (orig.mDimensionDescription != NULL)
  {
    mDimensionDescription = orig.mDimensionDescription->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedDataDescription.
 */
SedDataDescription&
SedDataDescription::operator=(const SedDataDescription& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mFormat = rhs.mFormat;
    mSource = rhs.mSource;
    mDataSources = rhs.mDataSources;
    delete mDimensionDescription;
    if (rhs.mDimensionDescription != NULL)
    {
      mDimensionDescription = rhs.mDimensionDescription->clone();
    }
    else
    {
      mDimensionDescription = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedDataDescription object.
 */
SedDataDescription*
SedDataDescription::clone() const
{
  return new SedDataDescription(*this);
}


/*
 * Destructor for SedDataDescription.
 */
SedDataDescription::~SedDataDescription()
{
  delete mDimensionDescription;
  mDimensionDescription = NULL;
}


/*
 * Returns the value of the "format" attribute of this SedDataDescription.
 */
const std::string&
SedDataDescription::getFormat() const
{
  return mFormat;
}


/*
 * Returns the value of the "source" attribute of this SedDataDescription.
 */
const std::string&
SedDataDescription::getSource() const
{
  return mSource;
}


/*
 * Predicate returning @c true if this SedDataDescription's "format" attribute
 * is set.
 */
bool
SedDataDescription::isSetFormat() const
{
  return (mFormat.empty() == false);
}


/*
 * Predicate returning @c true if this SedDataDescription's "source" attribute
 * is set.
 */
bool
SedDataDescription::isSetSource() const
{
  return (mSource.empty() == false);
}


/*
 * Sets the value of the "format" attribute of this SedDataDescription.
 */
int
SedDataDescription::setFormat(const std::string& format)
{
  mFormat = format;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "source" attribute of this SedDataDescription.
 */
int
SedDataDescription::setSource(const std::string& source)
{
  mSource = source;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "format" attribute of this SedDataDescription.
 */
int
SedDataDescription::unsetFormat()
{
  mFormat.erase();

  if (mFormat.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "source" attribute of this SedDataDescription.
 */
int
SedDataDescription::unsetSource()
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
 * Returns the value of the "dimensionDescription" element of this
 * SedDataDescription.
 */
const LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription*
SedDataDescription::getDimensionDescription() const
{
  return mDimensionDescription;
}


/*
 * Returns the value of the "dimensionDescription" element of this
 * SedDataDescription.
 */
LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription*
SedDataDescription::getDimensionDescription()
{
  return mDimensionDescription;
}


/*
 * Predicate returning @c true if this SedDataDescription's
 * "dimensionDescription" element is set.
 */
bool
SedDataDescription::isSetDimensionDescription() const
{
  return (mDimensionDescription != NULL);
}


/*
 * Sets the value of the "dimensionDescription" element of this
 * SedDataDescription.
 */
int
SedDataDescription::setDimensionDescription(const LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription*
  dimensionDescription)
{
  if (mDimensionDescription == dimensionDescription)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (dimensionDescription == NULL)
  {
    delete mDimensionDescription;
    mDimensionDescription = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mDimensionDescription;
    mDimensionDescription = (dimensionDescription != NULL) ?
      dimensionDescription->clone() : NULL;
    if (mDimensionDescription != NULL)
    {
      //mDimensionDescription->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new DimensionDescription object, adds it to this
 * SedDataDescription object and returns the DimensionDescription object
 * created.
 */
LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription*
SedDataDescription::createDimensionDescription()
{
  if (mDimensionDescription != NULL)
  {
    delete mDimensionDescription;
  }

  mDimensionDescription = new LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription();

  connectToChild();

  return mDimensionDescription;
}


/*
 * Unsets the value of the "dimensionDescription" element of this
 * SedDataDescription.
 */
int
SedDataDescription::unsetDimensionDescription()
{
  delete mDimensionDescription;
  mDimensionDescription = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the SedListOfDataSources from this SedDataDescription.
 */
const SedListOfDataSources*
SedDataDescription::getListOfDataSources() const
{
  return &mDataSources;
}


/*
 * Returns the SedListOfDataSources from this SedDataDescription.
 */
SedListOfDataSources*
SedDataDescription::getListOfDataSources()
{
  return &mDataSources;
}


/*
 * Get a SedDataSource from the SedDataDescription.
 */
SedDataSource*
SedDataDescription::getDataSource(unsigned int n)
{
  return mDataSources.get(n);
}


/*
 * Get a SedDataSource from the SedDataDescription.
 */
const SedDataSource*
SedDataDescription::getDataSource(unsigned int n) const
{
  return mDataSources.get(n);
}


/*
 * Get a SedDataSource from the SedDataDescription based on its identifier.
 */
SedDataSource*
SedDataDescription::getDataSource(const std::string& sid)
{
  return mDataSources.get(sid);
}


/*
 * Get a SedDataSource from the SedDataDescription based on its identifier.
 */
const SedDataSource*
SedDataDescription::getDataSource(const std::string& sid) const
{
  return mDataSources.get(sid);
}


/*
 * Get a SedDataSource from the SedDataDescription based on the IndexSet to
 * which it refers.
 */
const SedDataSource*
SedDataDescription::getDataSourceByIndexSet(const std::string& sid) const
{
  return mDataSources.getByIndexSet(sid);
}


/*
 * Get a SedDataSource from the SedDataDescription based on the IndexSet to
 * which it refers.
 */
SedDataSource*
SedDataDescription::getDataSourceByIndexSet(const std::string& sid)
{
  return mDataSources.getByIndexSet(sid);
}


/*
 * Adds a copy of the given SedDataSource to this SedDataDescription.
 */
int
SedDataDescription::addDataSource(const SedDataSource* sds)
{
  if (sds == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sds->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sds->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sds->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sds)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sds->isSetId() && (mDataSources.get(sds->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mDataSources.append(sds);
  }
}


/*
 * Get the number of SedDataSource objects in this SedDataDescription.
 */
unsigned int
SedDataDescription::getNumDataSources() const
{
  return mDataSources.size();
}


/*
 * Creates a new SedDataSource object, adds it to this SedDataDescription
 * object and returns the SedDataSource object created.
 */
SedDataSource*
SedDataDescription::createDataSource()
{
  SedDataSource* sds = NULL;

  try
  {
    sds = new SedDataSource(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sds != NULL)
  {
    mDataSources.appendAndOwn(sds);
  }

  return sds;
}


/*
 * Removes the nth SedDataSource from this SedDataDescription and returns a
 * pointer to it.
 */
SedDataSource*
SedDataDescription::removeDataSource(unsigned int n)
{
  return mDataSources.remove(n);
}


/*
 * Removes the SedDataSource from this SedDataDescription based on its
 * identifier and returns a pointer to it.
 */
SedDataSource*
SedDataDescription::removeDataSource(const std::string& sid)
{
  return mDataSources.remove(sid);
}


/*
 * Returns the XML element name of this SedDataDescription object.
 */
const std::string&
SedDataDescription::getElementName() const
{
  static const string name = "dataDescription";
  return name;
}


/*
 * Returns the libSEDML type code for this SedDataDescription object.
 */
int
SedDataDescription::getTypeCode() const
{
  return SEDML_DATA_DESCRIPTION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedDataDescription object have been set.
 */
bool
SedDataDescription::hasRequiredAttributes() const
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
SedDataDescription::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (isSetDimensionDescription() == true)
  {
    mDimensionDescription->write(stream);
  }

  if (getNumDataSources() > 0)
  {
    mDataSources.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedDataDescription::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedDataDescription::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  if (mDimensionDescription != NULL)
  {
    //mDimensionDescription->setSedDocument(d);
  }

  mDataSources.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedDataDescription::connectToChild()
{
  SedBase::connectToChild();

  if (mDimensionDescription != NULL)
  {
    //mDimensionDescription->connectToParent(this);
  }

  mDataSources.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::getAttribute(const std::string& attributeName,
                                 bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::getAttribute(const std::string& attributeName,
                                 int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::getAttribute(const std::string& attributeName,
                                 double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::getAttribute(const std::string& attributeName,
                                 unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::getAttribute(const std::string& attributeName,
                                 std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "format")
  {
    value = getFormat();
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
 * Predicate returning @c true if this SedDataDescription's attribute
 * "attributeName" is set.
 */
bool
SedDataDescription::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "format")
  {
    value = isSetFormat();
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
 * Sets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::setAttribute(const std::string& attributeName,
                                 double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::setAttribute(const std::string& attributeName,
                                 unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedDataDescription.
 */
int
SedDataDescription::setAttribute(const std::string& attributeName,
                                 const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "format")
  {
    return_value = setFormat(value);
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
 * Unsets the value of the "attributeName" attribute of this
 * SedDataDescription.
 */
int
SedDataDescription::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "name")
  {
    value = unsetName();
  }
  else if (attributeName == "format")
  {
    value = unsetFormat();
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
 * Creates and returns an new "elementName" object in this SedDataDescription.
 */
SedBase*
SedDataDescription::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "dimensionDescription")
  {
    //return createDimensionDescription();
    return NULL;
  }
  else if (elementName == "dataSource")
  {
    return createDataSource();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedDataDescription.
 */
int
SedDataDescription::addChildObject(const std::string& elementName,
                                   const SedBase* element)
{
  if (elementName == "dataSource" && element->getTypeCode() ==
    SEDML_DATA_SOURCE)
  {
    return addDataSource((const SedDataSource*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedDataDescription.
 */
SedBase*
SedDataDescription::removeChildObject(const std::string& elementName,
                                      const std::string& id)
{
  if (elementName == "dataSource")
  {
    return removeDataSource(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedDataDescription.
 */
unsigned int
SedDataDescription::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "dimensionDescription")
  {
    if (isSetDimensionDescription())
    {
      return 1;
    }
  }
  else if (elementName == "dataSource")
  {
    return getNumDataSources();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedDataDescription.
 */
SedBase*
SedDataDescription::getObject(const std::string& elementName,
                              unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "dataSource")
  {
    return getDataSource(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedDataDescription::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mDataSources.getElementBySId(id);

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
SedDataDescription::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  //SED_ADD_FILTERED_POINTER(ret, sublist, mDimensionDescription, filter);

  SED_ADD_FILTERED_LIST(ret, sublist, mDataSources, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedDataDescription::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfDataSources")
  {
    if (getErrorLog() && mDataSources.size() != 0)
    {
      getErrorLog()->logError(SedmlDataDescriptionAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mDataSources;
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
SedDataDescription::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("format");

  attributes.add("source");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedDataDescription::readAttributes(
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
    static_cast<SedListOfDataDescriptions*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlDocumentLODataDescriptionsAllowedCoreAttributes,
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
        log->logError(SedmlDataDescriptionAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  if (!isSetId())
  {
    if (log)
    {
      std::string message = "Sedml attribute 'id' is missing from the "
        "<SedDataDescription> element.";
      log->logError(SedmlDataDescriptionAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // format string (use = "optional" )
  // 

  assigned = attributes.readInto("format", mFormat);

  if (assigned == true)
  {
    if (mFormat.empty() == true)
    {
      logEmptyString(mFormat, level, version, "<SedDataDescription>");
    }
  }

  // 
  // source string (use = "optional" )
  // 

  assigned = attributes.readInto("source", mSource);

  if (assigned == true)
  {
    if (mSource.empty() == true)
    {
      logEmptyString(mSource, level, version, "<SedDataDescription>");
    }
  }
}

/** @endcond */

/** @cond doxygenLibSEDMLInternal */

bool 
SedDataDescription::readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  bool          read = false;
  const string& name = stream.peek().getName();

  if (name == "dimensionDescription")
  {
    mDimensionDescription = new LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription();
    mDimensionDescription->read(stream);
    read = true;
  }

  if (SedBase::readOtherXML(stream))
  {
    read = true;
  }

  return read;
}

/** @endcond */

/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedDataDescription::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetFormat() == true)
  {
    stream.writeAttribute("format", getPrefix(), mFormat);
  }

  if (isSetSource() == true)
  {
    stream.writeAttribute("source", getPrefix(), mSource);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDataDescription_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedDataDescription_t *
SedDataDescription_create(unsigned int level, unsigned int version)
{
  return new SedDataDescription(level, version);
}


/*
 * Creates and returns a deep copy of this SedDataDescription_t object.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDataDescription_clone(const SedDataDescription_t* sdd)
{
  if (sdd != NULL)
  {
    return static_cast<SedDataDescription_t*>(sdd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedDataDescription_t object.
 */
LIBSEDML_EXTERN
void
SedDataDescription_free(SedDataDescription_t* sdd)
{
  if (sdd != NULL)
  {
    delete sdd;
  }
}


/*
 * Returns the value of the "id" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getId(const SedDataDescription_t * sdd)
{
  if (sdd == NULL)
  {
    return NULL;
  }

  return sdd->getId().empty() ? NULL : safe_strdup(sdd->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getName(const SedDataDescription_t * sdd)
{
  if (sdd == NULL)
  {
    return NULL;
  }

  return sdd->getName().empty() ? NULL : safe_strdup(sdd->getName().c_str());
}


/*
 * Returns the value of the "format" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getFormat(const SedDataDescription_t * sdd)
{
  if (sdd == NULL)
  {
    return NULL;
  }

  return sdd->getFormat().empty() ? NULL :
    safe_strdup(sdd->getFormat().c_str());
}


/*
 * Returns the value of the "source" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getSource(const SedDataDescription_t * sdd)
{
  if (sdd == NULL)
  {
    return NULL;
  }

  return sdd->getSource().empty() ? NULL :
    safe_strdup(sdd->getSource().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedDataDescription_t's "id"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetId(const SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDataDescription_t's "name"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetName(const SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDataDescription_t's "format"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetFormat(const SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetFormat()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedDataDescription_t's "source"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetSource(const SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetSource()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_setId(SedDataDescription_t * sdd, const char * id)
{
  return (sdd != NULL) ? sdd->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_setName(SedDataDescription_t * sdd, const char * name)
{
  return (sdd != NULL) ? sdd->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "format" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_setFormat(SedDataDescription_t * sdd, const char * format)
{
  return (sdd != NULL) ? sdd->setFormat(format) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "source" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_setSource(SedDataDescription_t * sdd, const char * source)
{
  return (sdd != NULL) ? sdd->setSource(source) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetId(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetName(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "format" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetFormat(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetFormat() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "source" attribute of this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetSource(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetSource() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "dimensionDescription" element of this
 * SedDataDescription_t.
 */
LIBSEDML_EXTERN
const LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription_t*
SedDataDescription_getDimensionDescription(const SedDataDescription_t * sdd)
{
  if (sdd == NULL)
  {
    return NULL;
  }

  return (LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription_t*)(sdd->getDimensionDescription());
}


/*
 * Predicate returning @c 1 (true) if this SedDataDescription_t's
 * "dimensionDescription" element is set.
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetDimensionDescription(const SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetDimensionDescription()) :
    0;
}


/*
 * Sets the value of the "dimensionDescription" element of this
 * SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_setDimensionDescription(SedDataDescription_t * sdd,
                                           const LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription_t*
                                             dimensionDescription)
{
  return (sdd != NULL) ? sdd->setDimensionDescription(dimensionDescription) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new DimensionDescription_t object, adds it to this
 * SedDataDescription_t object and returns the DimensionDescription_t object
 * created.
 */
LIBSEDML_EXTERN
LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription_t*
SedDataDescription_createDimensionDescription(SedDataDescription_t* sdd)
{
  if (sdd == NULL)
  {
    return NULL;
  }

  return (LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription_t*)(sdd->createDimensionDescription());
}


/*
 * Unsets the value of the "dimensionDescription" element of this
 * SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetDimensionDescription(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetDimensionDescription() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedDataSource_t objects from this
 * SedDataDescription_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataDescription_getListOfDataSources(SedDataDescription_t* sdd)
{
  return (sdd != NULL) ? sdd->getListOfDataSources() : NULL;
}


/*
 * Get a SedDataSource_t from the SedDataDescription_t.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_getDataSource(SedDataDescription_t* sdd, unsigned int n)
{
  return (sdd != NULL) ? sdd->getDataSource(n) : NULL;
}


/*
 * Get a SedDataSource_t from the SedDataDescription_t based on its identifier.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_getDataSourceById(SedDataDescription_t* sdd,
                                     const char *sid)
{
  return (sdd != NULL && sid != NULL) ? sdd->getDataSource(sid) : NULL;
}


/*
 * Get a SedDataSource_t from the SedDataDescription_t based on the IndexSet to
 * which it refers.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_getDataSourceByIndexSet(SedDataDescription_t* sdd,
                                           const char *sid)
{
  return (sdd != NULL && sid != NULL) ? sdd->getDataSourceByIndexSet(sid) :
    NULL;
}


/*
 * Adds a copy of the given SedDataSource_t to this SedDataDescription_t.
 */
LIBSEDML_EXTERN
int
SedDataDescription_addDataSource(SedDataDescription_t* sdd,
                                 const SedDataSource_t* sds)
{
  return (sdd != NULL) ? sdd->addDataSource(sds) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedDataSource_t objects in this SedDataDescription_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDataDescription_getNumDataSources(SedDataDescription_t* sdd)
{
  return (sdd != NULL) ? sdd->getNumDataSources() : SEDML_INT_MAX;
}


/*
 * Creates a new SedDataSource_t object, adds it to this SedDataDescription_t
 * object and returns the SedDataSource_t object created.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_createDataSource(SedDataDescription_t* sdd)
{
  return (sdd != NULL) ? sdd->createDataSource() : NULL;
}


/*
 * Removes the nth SedDataSource_t from this SedDataDescription_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_removeDataSource(SedDataDescription_t* sdd, unsigned int n)
{
  return (sdd != NULL) ? sdd->removeDataSource(n) : NULL;
}


/*
 * Removes the SedDataSource_t from this SedDataDescription_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_removeDataSourceById(SedDataDescription_t* sdd,
                                        const char* sid)
{
  return (sdd != NULL && sid != NULL) ? sdd->removeDataSource(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDataDescription_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDataDescription_hasRequiredAttributes(const SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


