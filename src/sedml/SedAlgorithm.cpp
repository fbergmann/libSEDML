/**
 * @file SedAlgorithm.cpp
 * @brief Implementation of the SedAlgorithm class.
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
#include <sedml/SedAlgorithm.h>
#include <sbml/xml/XMLInputStream.h>

#include <map>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN

extern map<int, string> g_kisaomap;



#ifdef __cplusplus


/*
 * Creates a new SedAlgorithm using the given SED-ML Level and @ p version
 * values.
 */
SedAlgorithm::SedAlgorithm(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mKisaoID ("")
  , mAlgorithmParameters (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedAlgorithm using the given SedNamespaces object @p sedmlns.
 */
SedAlgorithm::SedAlgorithm(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mKisaoID ("")
  , mAlgorithmParameters (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedAlgorithm.
 */
SedAlgorithm::SedAlgorithm(const SedAlgorithm& orig)
  : SedBase( orig )
  , mKisaoID ( orig.mKisaoID )
  , mAlgorithmParameters ( orig.mAlgorithmParameters )
{
  connectToChild();
}


/*
 * Assignment operator for SedAlgorithm.
 */
SedAlgorithm&
SedAlgorithm::operator=(const SedAlgorithm& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mKisaoID = rhs.mKisaoID;
    mAlgorithmParameters = rhs.mAlgorithmParameters;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAlgorithm object.
 */
SedAlgorithm*
SedAlgorithm::clone() const
{
  return new SedAlgorithm(*this);
}


/*
 * Destructor for SedAlgorithm.
 */
SedAlgorithm::~SedAlgorithm()
{
}


/*
 * Returns the value of the "kisaoID" attribute of this SedAlgorithm.
 */
const std::string&
SedAlgorithm::getKisaoID() const
{
  return mKisaoID;
}


/*
 * Predicate returning @c true if this SedAlgorithm's "kisaoID" attribute is
 * set.
 */
bool
SedAlgorithm::isSetKisaoID() const
{
  return (mKisaoID.empty() == false);
}


/*
 * Sets the value of the "kisaoID" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::setKisaoID(const std::string& kisaoID)
{
  mKisaoID = kisaoID;
  if (!isSetName()) {
      int knum = getKisaoIDasInt();
      if (g_kisaomap.find(knum) != g_kisaomap.end()) {
          setName(g_kisaomap[knum]);
      }
  }
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "kisaoID" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::unsetKisaoID()
{
  mKisaoID.erase();

  if (mKisaoID.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfAlgorithmParameters from this SedAlgorithm.
 */
const SedListOfAlgorithmParameters*
SedAlgorithm::getListOfAlgorithmParameters() const
{
  return &mAlgorithmParameters;
}


/*
 * Returns the SedListOfAlgorithmParameters from this SedAlgorithm.
 */
SedListOfAlgorithmParameters*
SedAlgorithm::getListOfAlgorithmParameters()
{
  return &mAlgorithmParameters;
}


/*
 * Get a SedAlgorithmParameter from the SedAlgorithm.
 */
SedAlgorithmParameter*
SedAlgorithm::getAlgorithmParameter(unsigned int n)
{
  return mAlgorithmParameters.get(n);
}


/*
 * Get a SedAlgorithmParameter from the SedAlgorithm.
 */
const SedAlgorithmParameter*
SedAlgorithm::getAlgorithmParameter(unsigned int n) const
{
  return mAlgorithmParameters.get(n);
}


/*
 * Adds a copy of the given SedAlgorithmParameter to this SedAlgorithm.
 */
int
SedAlgorithm::addAlgorithmParameter(const SedAlgorithmParameter* sap)
{
  if (sap == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sap->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sap->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sap->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sap)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mAlgorithmParameters.append(sap);
  }
}


/*
 * Get the number of SedAlgorithmParameter objects in this SedAlgorithm.
 */
unsigned int
SedAlgorithm::getNumAlgorithmParameters() const
{
  return mAlgorithmParameters.size();
}


/*
 * Creates a new SedAlgorithmParameter object, adds it to this SedAlgorithm
 * object and returns the SedAlgorithmParameter object created.
 */
SedAlgorithmParameter*
SedAlgorithm::createAlgorithmParameter()
{
  SedAlgorithmParameter* sap = NULL;

  try
  {
    sap = new SedAlgorithmParameter(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sap != NULL)
  {
    mAlgorithmParameters.appendAndOwn(sap);
  }

  return sap;
}


/*
 * Removes the nth SedAlgorithmParameter from this SedAlgorithm and returns a
 * pointer to it.
 */
SedAlgorithmParameter*
SedAlgorithm::removeAlgorithmParameter(unsigned int n)
{
  return mAlgorithmParameters.remove(n);
}


/*
 * Removes the SedAlgorithmParameter with the given id from this SedAlgorithm and returns a
 * pointer to it.
 */
SedAlgorithmParameter*
SedAlgorithm::removeAlgorithmParameter(const string& id)
{
    return mAlgorithmParameters.remove(id);
}


/*
 * Returns the XML element name of this SedAlgorithm object.
 */
const std::string&
SedAlgorithm::getElementName() const
{
  static const string name = "algorithm";
  return name;
}


/*
 * Returns the libSEDML type code for this SedAlgorithm object.
 */
int
SedAlgorithm::getTypeCode() const
{
  return SEDML_SIMULATION_ALGORITHM;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAlgorithm object have been set.
 */
bool
SedAlgorithm::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetKisaoID() == false)
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
SedAlgorithm::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (getNumAlgorithmParameters() > 0)
  {
    mAlgorithmParameters.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAlgorithm::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAlgorithm::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mAlgorithmParameters.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedAlgorithm::connectToChild()
{
  SedBase::connectToChild();

  mAlgorithmParameters.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "kisaoID")
  {
    value = getKisaoID();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedAlgorithm's attribute "attributeName"
 * is set.
 */
bool
SedAlgorithm::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "kisaoID")
  {
    value = isSetKisaoID();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "kisaoID")
  {
    return_value = setKisaoID(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedAlgorithm.
 */
int
SedAlgorithm::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "kisaoID")
  {
    value = unsetKisaoID();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this SedAlgorithm.
 */
SedBase*
SedAlgorithm::createChildObject(const std::string& elementName)
{
  SedBase* obj = NULL;

  if (elementName == "algorithmParameter")
  {
    return createAlgorithmParameter();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds a new "elementName" object to this SedAlgorithm.
 */
int
SedAlgorithm::addChildObject(const std::string& elementName,
                             const SedBase* element)
{
  if (elementName == "algorithmParameter" && element->getTypeCode() ==
    SEDML_SIMULATION_ALGORITHM_PARAMETER)
  {
    return addAlgorithmParameter((const SedAlgorithmParameter*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SedAlgorithm.
 */
SedBase*
SedAlgorithm::removeChildObject(const std::string& elementName,
                                const std::string& id)
{
  if (elementName == "algorithmParameter")
  {
    for (unsigned int i = 0; i < getNumAlgorithmParameters(); i++)
    {
      if (getAlgorithmParameter(i)->getId() == id)
      {
        return removeAlgorithmParameter(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the number of "elementName" in this SedAlgorithm.
 */
unsigned int
SedAlgorithm::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "algorithmParameter")
  {
    return getNumAlgorithmParameters();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Returns the nth object of "objectName" in this SedAlgorithm.
 */
SedBase*
SedAlgorithm::getObject(const std::string& elementName, unsigned int index)
{
  SedBase* obj = NULL;

  if (elementName == "algorithmParameter")
  {
    return getAlgorithmParameter(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedAlgorithm::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mAlgorithmParameters.getElementBySId(id);

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
SedAlgorithm::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_LIST(ret, sublist, mAlgorithmParameters, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedAlgorithm::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfAlgorithmParameters")
  {
    if (getErrorLog() && mAlgorithmParameters.size() != 0)
    {
      getErrorLog()->logError(SedmlAlgorithmAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mAlgorithmParameters;
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
SedAlgorithm::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("kisaoID");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAlgorithm::readAttributes(
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
        log->logError(SedmlAlgorithmAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // kisaoID string (use = "required" )
  // 

  assigned = attributes.readInto("kisaoID", mKisaoID);

  if (assigned == true)
  {
    if (mKisaoID.empty() == true)
    {
      logEmptyString(mKisaoID, level, version, "<SedAlgorithm>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'kisaoID' is missing from the "
        "<SedAlgorithm> element.";
      log->logError(SedmlAlgorithmAllowedAttributes, level, version, message,
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
SedAlgorithm::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetKisaoID() == true)
  {
    stream.writeAttribute("kisaoID", getPrefix(), mKisaoID);
  }
}

/** @endcond */


/*
 * @returns the KisaoTerm as integer
 */

int 
SedAlgorithm::getKisaoIDasInt() const
{
  std::string::size_type pos = mKisaoID.find(':');
  if (pos == std::string::npos)
    pos = mKisaoID.find('_');
  
  if (pos == std::string::npos)
    return -1;
  
  std::stringstream str(mKisaoID.substr(pos+1));
  int result; str >> result;
  return result;
}
 
/*
 * Sets the KisaoId as integer
 */ 
int 
SedAlgorithm::setKisaoID(int kisaoID)
{
  std::stringstream str; 
  str << "KISAO:" 
      << std::setfill('0') 
      << std::setw(7)
      << kisaoID; 
  mKisaoID = str.str();
  if (!isSetName() && g_kisaomap.find(kisaoID) != g_kisaomap.end()) {
      setName(g_kisaomap[kisaoID]);
  }
  return LIBSEDML_OPERATION_SUCCESS;
}

#endif /* __cplusplus */


/*
 * Creates a new SedAlgorithm_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedAlgorithm_t *
SedAlgorithm_create(unsigned int level, unsigned int version)
{
  return new SedAlgorithm(level, version);
}


/*
 * Creates and returns a deep copy of this SedAlgorithm_t object.
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedAlgorithm_clone(const SedAlgorithm_t* sa)
{
  if (sa != NULL)
  {
    return static_cast<SedAlgorithm_t*>(sa->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAlgorithm_t object.
 */
LIBSEDML_EXTERN
void
SedAlgorithm_free(SedAlgorithm_t* sa)
{
  if (sa != NULL)
  {
    delete sa;
  }
}


/*
 * Returns the value of the "kisaoID" attribute of this SedAlgorithm_t.
 */
LIBSEDML_EXTERN
char *
SedAlgorithm_getKisaoID(const SedAlgorithm_t * sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return sa->getKisaoID().empty() ? NULL :
    safe_strdup(sa->getKisaoID().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedAlgorithm_t's "kisaoID" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedAlgorithm_isSetKisaoID(const SedAlgorithm_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetKisaoID()) : 0;
}


/*
 * Sets the value of the "kisaoID" attribute of this SedAlgorithm_t.
 */
LIBSEDML_EXTERN
int
SedAlgorithm_setKisaoID(SedAlgorithm_t * sa, const char * kisaoID)
{
  return (sa != NULL) ? sa->setKisaoID(kisaoID) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "kisaoID" attribute of this SedAlgorithm_t.
 */
LIBSEDML_EXTERN
int
SedAlgorithm_unsetKisaoID(SedAlgorithm_t * sa)
{
  return (sa != NULL) ? sa->unsetKisaoID() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedAlgorithmParameter_t objects from this
 * SedAlgorithm_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedAlgorithm_getListOfAlgorithmParameters(SedAlgorithm_t* sa)
{
  return (sa != NULL) ? sa->getListOfAlgorithmParameters() : NULL;
}


/*
 * Get a SedAlgorithmParameter_t from the SedAlgorithm_t.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithm_getAlgorithmParameter(SedAlgorithm_t* sa, unsigned int n)
{
  return (sa != NULL) ? sa->getAlgorithmParameter(n) : NULL;
}


/*
 * Adds a copy of the given SedAlgorithmParameter_t to this SedAlgorithm_t.
 */
LIBSEDML_EXTERN
int
SedAlgorithm_addAlgorithmParameter(SedAlgorithm_t* sa,
                                   const SedAlgorithmParameter_t* sap)
{
  return (sa != NULL) ? sa->addAlgorithmParameter(sap) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedAlgorithmParameter_t objects in this SedAlgorithm_t.
 */
LIBSEDML_EXTERN
unsigned int
SedAlgorithm_getNumAlgorithmParameters(SedAlgorithm_t* sa)
{
  return (sa != NULL) ? sa->getNumAlgorithmParameters() : SEDML_INT_MAX;
}


/*
 * Creates a new SedAlgorithmParameter_t object, adds it to this SedAlgorithm_t
 * object and returns the SedAlgorithmParameter_t object created.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithm_createAlgorithmParameter(SedAlgorithm_t* sa)
{
  return (sa != NULL) ? sa->createAlgorithmParameter() : NULL;
}


/*
 * Removes the nth SedAlgorithmParameter_t from this SedAlgorithm_t and returns
 * a pointer to it.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithm_removeAlgorithmParameter(SedAlgorithm_t* sa, unsigned int n)
{
  return (sa != NULL) ? sa->removeAlgorithmParameter(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAlgorithm_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAlgorithm_hasRequiredAttributes(const SedAlgorithm_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


