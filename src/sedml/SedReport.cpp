/**
 * @file SedReport.cpp
 * @brief Implementation of the SedReport class.
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
#include <sedml/SedReport.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedReport using the given SED-ML Level and @ p version values.
 */
SedReport::SedReport(unsigned int level, unsigned int version)
  : SedOutput(level, version)
  , mDataSets (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedReport using the given SedNamespaces object @p sedmlns.
 */
SedReport::SedReport(SedNamespaces *sedmlns)
  : SedOutput(sedmlns)
  , mDataSets (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedReport.
 */
SedReport::SedReport(const SedReport& orig)
  : SedOutput( orig )
  , mDataSets ( orig.mDataSets )
{
  connectToChild();
}


/*
 * Assignment operator for SedReport.
 */
SedReport&
SedReport::operator=(const SedReport& rhs)
{
  if (&rhs != this)
  {
    SedOutput::operator=(rhs);
    mDataSets = rhs.mDataSets;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedReport object.
 */
SedReport*
SedReport::clone() const
{
  return new SedReport(*this);
}


/*
 * Destructor for SedReport.
 */
SedReport::~SedReport()
{
}


/*
 * Returns the SedListOfDataSets from this SedReport.
 */
const SedListOfDataSets*
SedReport::getListOfDataSets() const
{
  return &mDataSets;
}


/*
 * Returns the SedListOfDataSets from this SedReport.
 */
SedListOfDataSets*
SedReport::getListOfDataSets()
{
  return &mDataSets;
}


/*
 * Get a SedDataSet from the SedReport.
 */
SedDataSet*
SedReport::getDataSet(unsigned int n)
{
  return mDataSets.get(n);
}


/*
 * Get a SedDataSet from the SedReport.
 */
const SedDataSet*
SedReport::getDataSet(unsigned int n) const
{
  return mDataSets.get(n);
}


/*
 * Get a SedDataSet from the SedReport based on its identifier.
 */
SedDataSet*
SedReport::getDataSet(const std::string& sid)
{
  return mDataSets.get(sid);
}


/*
 * Get a SedDataSet from the SedReport based on its identifier.
 */
const SedDataSet*
SedReport::getDataSet(const std::string& sid) const
{
  return mDataSets.get(sid);
}


/*
 * Get a SedDataSet from the SedReport based on the DataReference to which it
 * refers.
 */
const SedDataSet*
SedReport::getDataSetByDataReference(const std::string& sid) const
{
  return mDataSets.getByDataReference(sid);
}


/*
 * Get a SedDataSet from the SedReport based on the DataReference to which it
 * refers.
 */
SedDataSet*
SedReport::getDataSetByDataReference(const std::string& sid)
{
  return mDataSets.getByDataReference(sid);
}


/*
 * Adds a copy of the given SedDataSet to this SedReport.
 */
int
SedReport::addDataSet(const SedDataSet* sds)
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
  else if (sds->isSetId() && (mDataSets.get(sds->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mDataSets.append(sds);
  }
}


/*
 * Get the number of SedDataSet objects in this SedReport.
 */
unsigned int
SedReport::getNumDataSets() const
{
  return mDataSets.size();
}


/*
 * Creates a new SedDataSet object, adds it to this SedReport object and
 * returns the SedDataSet object created.
 */
SedDataSet*
SedReport::createDataSet()
{
  SedDataSet* sds = NULL;

  try
  {
    sds = new SedDataSet(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sds != NULL)
  {
    mDataSets.appendAndOwn(sds);
  }

  return sds;
}


/*
 * Removes the nth SedDataSet from this SedReport and returns a pointer to it.
 */
SedDataSet*
SedReport::removeDataSet(unsigned int n)
{
  return mDataSets.remove(n);
}


/*
 * Removes the SedDataSet from this SedReport based on its identifier and
 * returns a pointer to it.
 */
SedDataSet*
SedReport::removeDataSet(const std::string& sid)
{
  return mDataSets.remove(sid);
}


/*
 * Returns the XML element name of this SedReport object.
 */
const std::string&
SedReport::getElementName() const
{
  static const string name = "report";
  return name;
}


/*
 * Returns the libSEDML type code for this SedReport object.
 */
int
SedReport::getTypeCode() const
{
  return SEDML_OUTPUT_REPORT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedReport object have been set.
 */
bool
SedReport::hasRequiredAttributes() const
{
  bool allPresent = SedOutput::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SedReport
 * object have been set.
 */
bool
SedReport::hasRequiredElements() const
{
  bool allPresent = SedOutput::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedReport::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedOutput::writeElements(stream);

  if (getNumDataSets() > 0)
  {
    mDataSets.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedReport::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedReport::setSedDocument(SedDocument* d)
{
  SedOutput::setSedDocument(d);

  mDataSets.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedReport::connectToChild()
{
  SedOutput::connectToChild();

  mDataSets.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SedOutput::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedReport's attribute "attributeName" is
 * set.
 */
bool
SedReport::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedOutput::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedOutput::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedReport.
 */
int
SedReport::unsetAttribute(const std::string& attributeName)
{
  int value = SedOutput::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedReport.
 */
SedBase*
SedReport::createChildObject(const std::string& elementName)
{
  SedOutput* obj = NULL;

  if (elementName == "dataSet")
  {
    return createDataSet();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedReport.
 */
int
SedReport::addChildObject(const std::string& elementName,
                          const SedBase* element)
{
  if (elementName == "dataSet" && element->getTypeCode() ==
    SEDML_OUTPUT_DATASET)
  {
    return addDataSet((const SedDataSet*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedReport.
 */
SedBase*
SedReport::removeChildObject(const std::string& elementName,
                             const std::string& id)
{
  if (elementName == "dataSet")
  {
    return removeDataSet(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedReport.
 */
unsigned int
SedReport::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "dataSet")
  {
    return getNumDataSets();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedReport.
 */
SedBase*
SedReport::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "dataSet")
  {
    return getDataSet(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedReport::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mDataSets.getElementBySId(id);

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
SedReport::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mDataSets, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedReport::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = SedOutput::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "listOfDataSets")
  {
    if (getErrorLog() && mDataSets.size() != 0)
    {
      getErrorLog()->logError(SedmlReportAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mDataSets;
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
SedReport::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedOutput::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedReport::readAttributes(
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

  SedOutput::readAttributes(attributes, expectedAttributes);

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
SedReport::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedOutput::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedReport_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedReport_t *
SedReport_create(unsigned int level, unsigned int version)
{
  return new SedReport(level, version);
}


/*
 * Creates and returns a deep copy of this SedReport_t object.
 */
LIBSEDML_EXTERN
SedReport_t*
SedReport_clone(const SedReport_t* sr)
{
  if (sr != NULL)
  {
    return static_cast<SedReport_t*>(sr->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedReport_t object.
 */
LIBSEDML_EXTERN
void
SedReport_free(SedReport_t* sr)
{
  if (sr != NULL)
  {
    delete sr;
  }
}


/*
 * Returns a ListOf_t * containing SedDataSet_t objects from this SedReport_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedReport_getListOfDataSets(SedReport_t* sr)
{
  return (sr != NULL) ? sr->getListOfDataSets() : NULL;
}


/*
 * Get a SedDataSet_t from the SedReport_t.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_getDataSet(SedReport_t* sr, unsigned int n)
{
  return (sr != NULL) ? sr->getDataSet(n) : NULL;
}


/*
 * Get a SedDataSet_t from the SedReport_t based on its identifier.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_getDataSetById(SedReport_t* sr, const char *sid)
{
  return (sr != NULL && sid != NULL) ? sr->getDataSet(sid) : NULL;
}


/*
 * Get a SedDataSet_t from the SedReport_t based on the DataReference to which
 * it refers.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_getDataSetByDataReference(SedReport_t* sr, const char *sid)
{
  return (sr != NULL && sid != NULL) ? sr->getDataSetByDataReference(sid) :
    NULL;
}


/*
 * Adds a copy of the given SedDataSet_t to this SedReport_t.
 */
LIBSEDML_EXTERN
int
SedReport_addDataSet(SedReport_t* sr, const SedDataSet_t* sds)
{
  return (sr != NULL) ? sr->addDataSet(sds) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedDataSet_t objects in this SedReport_t.
 */
LIBSEDML_EXTERN
unsigned int
SedReport_getNumDataSets(SedReport_t* sr)
{
  return (sr != NULL) ? sr->getNumDataSets() : SEDML_INT_MAX;
}


/*
 * Creates a new SedDataSet_t object, adds it to this SedReport_t object and
 * returns the SedDataSet_t object created.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_createDataSet(SedReport_t* sr)
{
  return (sr != NULL) ? sr->createDataSet() : NULL;
}


/*
 * Removes the nth SedDataSet_t from this SedReport_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_removeDataSet(SedReport_t* sr, unsigned int n)
{
  return (sr != NULL) ? sr->removeDataSet(n) : NULL;
}


/*
 * Removes the SedDataSet_t from this SedReport_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_removeDataSetById(SedReport_t* sr, const char* sid)
{
  return (sr != NULL && sid != NULL) ? sr->removeDataSet(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedReport_t object have been set.
 */
LIBSEDML_EXTERN
int
SedReport_hasRequiredAttributes(const SedReport_t * sr)
{
  return (sr != NULL) ? static_cast<int>(sr->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedReport_t object have been set.
 */
LIBSEDML_EXTERN
int
SedReport_hasRequiredElements(const SedReport_t * sr)
{
  return (sr != NULL) ? static_cast<int>(sr->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


