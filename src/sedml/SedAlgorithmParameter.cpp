/**
 * @file SedAlgorithmParameter.cpp
 * @brief Implementation of the SedAlgorithmParameter class.
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
#include <sedml/SedAlgorithmParameter.h>
#include <sedml/SedListOfAlgorithmParameters.h>
#include <sbml/xml/XMLInputStream.h>
#include <map>

using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN

extern map<int, string> g_kisaomap;



#ifdef __cplusplus


/*
 * Creates a new SedAlgorithmParameter using the given SED-ML Level and @ p
 * version values.
 */
SedAlgorithmParameter::SedAlgorithmParameter(unsigned int level,
                                             unsigned int version)
  : SedBase(level, version)
  , mKisaoID ("")
  , mValue ("")
  , mAlgorithmParameters (new SedListOfAlgorithmParameters (level, version))
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedAlgorithmParameter using the given SedNamespaces object @p
 * sedmlns.
 */
SedAlgorithmParameter::SedAlgorithmParameter(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mKisaoID ("")
  , mValue ("")
  , mAlgorithmParameters (new SedListOfAlgorithmParameters (sedmlns))
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedAlgorithmParameter.
 */
SedAlgorithmParameter::SedAlgorithmParameter(const SedAlgorithmParameter& orig)
  : SedBase( orig )
  , mKisaoID ( orig.mKisaoID )
  , mValue ( orig.mValue )
  , mAlgorithmParameters ( NULL )
{
  if (orig.mAlgorithmParameters != NULL)
  {
    mAlgorithmParameters = orig.mAlgorithmParameters->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedAlgorithmParameter.
 */
SedAlgorithmParameter&
SedAlgorithmParameter::operator=(const SedAlgorithmParameter& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mKisaoID = rhs.mKisaoID;
    mValue = rhs.mValue;
    delete mAlgorithmParameters;
    if (rhs.mAlgorithmParameters != NULL)
    {
      mAlgorithmParameters = rhs.mAlgorithmParameters->clone();
    }
    else
    {
      mAlgorithmParameters = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAlgorithmParameter object.
 */
SedAlgorithmParameter*
SedAlgorithmParameter::clone() const
{
  return new SedAlgorithmParameter(*this);
}


/*
 * Destructor for SedAlgorithmParameter.
 */
SedAlgorithmParameter::~SedAlgorithmParameter()
{
  delete mAlgorithmParameters;
  mAlgorithmParameters = NULL;
}


/*
 * Returns the value of the "kisaoID" attribute of this SedAlgorithmParameter.
 */
const std::string&
SedAlgorithmParameter::getKisaoID() const
{
  return mKisaoID;
}


/*
 * Returns the value of the "value" attribute of this SedAlgorithmParameter.
 */
const std::string&
SedAlgorithmParameter::getValue() const
{
  return mValue;
}


/*
 * Predicate returning @c true if this SedAlgorithmParameter's "kisaoID"
 * attribute is set.
 */
bool
SedAlgorithmParameter::isSetKisaoID() const
{
  return (mKisaoID.empty() == false);
}


/*
 * Predicate returning @c true if this SedAlgorithmParameter's "value"
 * attribute is set.
 */
bool
SedAlgorithmParameter::isSetValue() const
{
  return (mValue.empty() == false);
}


/*
 * Sets the value of the "kisaoID" attribute of this SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::setKisaoID(const std::string& kisaoID)
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
 * Sets the value of the "value" attribute of this SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::setValue(const std::string& value)
{
  mValue = value;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "kisaoID" attribute of this SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::unsetKisaoID()
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
 * Unsets the value of the "value" attribute of this SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::unsetValue()
{
  mValue.erase();

  if (mValue.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfAlgorithmParameters * from this SedAlgorithmParameter.
 */
const SedListOfAlgorithmParameters *
SedAlgorithmParameter::getListOfAlgorithmParameters() const
{
  return mAlgorithmParameters;
}


/*
 * Returns the SedListOfAlgorithmParameters * from this SedAlgorithmParameter.
 */
SedListOfAlgorithmParameters *
SedAlgorithmParameter::getListOfAlgorithmParameters()
{
  return mAlgorithmParameters;
}


/*
 * Get a SedAlgorithmParameter from the SedAlgorithmParameter.
 */
SedAlgorithmParameter*
SedAlgorithmParameter::getAlgorithmParameter(unsigned int n)
{
  return mAlgorithmParameters->get(n);
}


/*
 * Get a SedAlgorithmParameter from the SedAlgorithmParameter.
 */
const SedAlgorithmParameter*
SedAlgorithmParameter::getAlgorithmParameter(unsigned int n) const
{
  return mAlgorithmParameters->get(n);
}


/*
 * Adds a copy of the given SedAlgorithmParameter to this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::addAlgorithmParameter(const SedAlgorithmParameter* sap1)
{
  if (sap1 == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sap1->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sap1->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sap1->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sap1)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mAlgorithmParameters->append(sap1);
  }
}


/*
 * Get the number of SedAlgorithmParameter objects in this
 * SedAlgorithmParameter.
 */
unsigned int
SedAlgorithmParameter::getNumAlgorithmParameters() const
{
  return mAlgorithmParameters->size();
}


/*
 * Creates a new SedAlgorithmParameter object, adds it to this
 * SedAlgorithmParameter object and returns the SedAlgorithmParameter object
 * created.
 */
SedAlgorithmParameter*
SedAlgorithmParameter::createAlgorithmParameter()
{
  SedAlgorithmParameter* sap1 = NULL;

  try
  {
    sap1 = new SedAlgorithmParameter(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sap1 != NULL)
  {
    mAlgorithmParameters->appendAndOwn(sap1);
  }

  return sap1;
}


/*
 * Removes the nth SedAlgorithmParameter from this SedAlgorithmParameter and
 * returns a pointer to it.
 */
SedAlgorithmParameter*
SedAlgorithmParameter::removeAlgorithmParameter(unsigned int n)
{
  return mAlgorithmParameters->remove(n);
}


/*
 * Returns the XML element name of this SedAlgorithmParameter object.
 */
const std::string&
SedAlgorithmParameter::getElementName() const
{
  static const string name = "algorithmParameter";
  return name;
}


/*
 * Returns the libSEDML type code for this SedAlgorithmParameter object.
 */
int
SedAlgorithmParameter::getTypeCode() const
{
  return SEDML_SIMULATION_ALGORITHM_PARAMETER;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAlgorithmParameter object have been set.
 */
bool
SedAlgorithmParameter::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetKisaoID() == false)
  {
    allPresent = false;
  }

  if (isSetValue() == false)
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
SedAlgorithmParameter::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (getNumAlgorithmParameters() > 0)
  {
    mAlgorithmParameters->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAlgorithmParameter::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAlgorithmParameter::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mAlgorithmParameters->setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedAlgorithmParameter::connectToChild()
{
  SedBase::connectToChild();

  mAlgorithmParameters->connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::getAttribute(const std::string& attributeName,
                                    bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::getAttribute(const std::string& attributeName,
                                    int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::getAttribute(const std::string& attributeName,
                                    double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::getAttribute(const std::string& attributeName,
                                    unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "value")
  {
    value = getValue();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedAlgorithmParameter's attribute
 * "attributeName" is set.
 */
bool
SedAlgorithmParameter::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "kisaoID")
  {
    value = isSetKisaoID();
  }
  else if (attributeName == "value")
  {
    value = isSetValue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::setAttribute(const std::string& attributeName,
                                    bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::setAttribute(const std::string& attributeName,
                                    int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::setAttribute(const std::string& attributeName,
                                    double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::setAttribute(const std::string& attributeName,
                                    unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::setAttribute(const std::string& attributeName,
                                    const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "kisaoID")
  {
    return_value = setKisaoID(value);
  }
  else if (attributeName == "value")
  {
    return_value = setValue(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "kisaoID")
  {
    value = unsetKisaoID();
  }
  else if (attributeName == "value")
  {
    value = unsetValue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates and returns an new "elementName" object in this
 * SedAlgorithmParameter.
 */
SedBase*
SedAlgorithmParameter::createChildObject(const std::string& elementName)
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
 * Adds a new "elementName" object to this SedAlgorithmParameter.
 */
int
SedAlgorithmParameter::addChildObject(const std::string& elementName,
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
 * SedAlgorithmParameter.
 */
SedBase*
SedAlgorithmParameter::removeChildObject(const std::string& elementName,
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
 * Returns the number of "elementName" in this SedAlgorithmParameter.
 */
unsigned int
SedAlgorithmParameter::getNumObjects(const std::string& elementName)
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
 * Returns the nth object of "objectName" in this SedAlgorithmParameter.
 */
SedBase*
SedAlgorithmParameter::getObject(const std::string& elementName,
                                 unsigned int index)
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
SedAlgorithmParameter::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mAlgorithmParameters->getElementBySId(id);

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
SedAlgorithmParameter::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  SED_ADD_FILTERED_POINTER(ret, sublist, mAlgorithmParameters, filter);

  return ret;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedAlgorithmParameter::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfAlgorithmParameters")
  {
    if (getErrorLog() && mAlgorithmParameters->size() != 0)
    {
      getErrorLog()->logError(SedmlAlgorithmParameterAllowedElements,
        getLevel(), getVersion(), "", getLine(), getColumn());
    }

    obj = mAlgorithmParameters;
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
SedAlgorithmParameter::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("kisaoID");

  attributes.add("value");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAlgorithmParameter::readAttributes(
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
    static_cast<SedListOfAlgorithmParameters*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlAlgorithmLOAlgorithmParametersAllowedCoreAttributes,
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
        log->logError(SedmlAlgorithmParameterAllowedAttributes, level, version,
          details, getLine(), getColumn());
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
      logEmptyString(mKisaoID, level, version, "<SedAlgorithmParameter>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'kisaoID' is missing from the "
        "<SedAlgorithmParameter> element.";
      log->logError(SedmlAlgorithmParameterAllowedAttributes, level, version,
        message, getLine(), getColumn());
    }
  }

  // 
  // value string (use = "required" )
  // 

  assigned = attributes.readInto("value", mValue);

  if (assigned == true)
  {
    if (mValue.empty() == true)
    {
      logEmptyString(mValue, level, version, "<SedAlgorithmParameter>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'value' is missing from the "
        "<SedAlgorithmParameter> element.";
      log->logError(SedmlAlgorithmParameterAllowedAttributes, level, version,
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
SedAlgorithmParameter::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetKisaoID() == true)
  {
    stream.writeAttribute("kisaoID", getPrefix(), mKisaoID);
  }

  if (isSetValue() == true)
  {
    stream.writeAttribute("value", getPrefix(), mValue);
  }
}

/** @endcond */


/*
 * @returns the KisaoTerm as integer
 */

int 
SedAlgorithmParameter::getKisaoIDasInt() const
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
SedAlgorithmParameter::setKisaoID(int kisaoID)
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
 * Creates a new SedAlgorithmParameter_t using the given SED-ML Level and @ p
 * version values.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedAlgorithmParameter_create(unsigned int level, unsigned int version)
{
  return new SedAlgorithmParameter(level, version);
}


/*
 * Creates and returns a deep copy of this SedAlgorithmParameter_t object.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithmParameter_clone(const SedAlgorithmParameter_t* sap)
{
  if (sap != NULL)
  {
    return static_cast<SedAlgorithmParameter_t*>(sap->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAlgorithmParameter_t object.
 */
LIBSEDML_EXTERN
void
SedAlgorithmParameter_free(SedAlgorithmParameter_t* sap)
{
  if (sap != NULL)
  {
    delete sap;
  }
}


/*
 * Returns the value of the "kisaoID" attribute of this
 * SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
char *
SedAlgorithmParameter_getKisaoID(const SedAlgorithmParameter_t * sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return sap->getKisaoID().empty() ? NULL :
    safe_strdup(sap->getKisaoID().c_str());
}


/*
 * Returns the value of the "value" attribute of this SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
char *
SedAlgorithmParameter_getValue(const SedAlgorithmParameter_t * sap)
{
  if (sap == NULL)
  {
    return NULL;
  }

  return sap->getValue().empty() ? NULL : safe_strdup(sap->getValue().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedAlgorithmParameter_t's "kisaoID"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_isSetKisaoID(const SedAlgorithmParameter_t * sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetKisaoID()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedAlgorithmParameter_t's "value"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_isSetValue(const SedAlgorithmParameter_t * sap)
{
  return (sap != NULL) ? static_cast<int>(sap->isSetValue()) : 0;
}


/*
 * Sets the value of the "kisaoID" attribute of this SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_setKisaoID(SedAlgorithmParameter_t * sap,
                                 const char * kisaoID)
{
  return (sap != NULL) ? sap->setKisaoID(kisaoID) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "value" attribute of this SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_setValue(SedAlgorithmParameter_t * sap,
                               const char * value)
{
  return (sap != NULL) ? sap->setValue(value) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "kisaoID" attribute of this SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_unsetKisaoID(SedAlgorithmParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetKisaoID() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "value" attribute of this SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_unsetValue(SedAlgorithmParameter_t * sap)
{
  return (sap != NULL) ? sap->unsetValue() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SedAlgorithmParameter_t objects from this
 * SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedAlgorithmParameter_getListOfAlgorithmParameters(SedAlgorithmParameter_t*
  sap)
{
  return (sap != NULL) ? sap->getListOfAlgorithmParameters() : NULL;
}


/*
 * Get a SedAlgorithmParameter_t from the SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithmParameter_getAlgorithmParameter(SedAlgorithmParameter_t* sap,
                                            unsigned int n)
{
  return (sap != NULL) ? sap->getAlgorithmParameter(n) : NULL;
}


/*
 * Adds a copy of the given SedAlgorithmParameter_t to this
 * SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_addAlgorithmParameter(SedAlgorithmParameter_t* sap,
                                            const SedAlgorithmParameter_t*
                                              sap1)
{
  return (sap != NULL) ? sap->addAlgorithmParameter(sap1) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedAlgorithmParameter_t objects in this
 * SedAlgorithmParameter_t.
 */
LIBSEDML_EXTERN
unsigned int
SedAlgorithmParameter_getNumAlgorithmParameters(SedAlgorithmParameter_t* sap)
{
  return (sap != NULL) ? sap->getNumAlgorithmParameters() : SEDML_INT_MAX;
}


/*
 * Creates a new SedAlgorithmParameter_t object, adds it to this
 * SedAlgorithmParameter_t object and returns the SedAlgorithmParameter_t
 * object created.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithmParameter_createAlgorithmParameter(SedAlgorithmParameter_t* sap)
{
  return (sap != NULL) ? sap->createAlgorithmParameter() : NULL;
}


/*
 * Removes the nth SedAlgorithmParameter_t from this SedAlgorithmParameter_t
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithmParameter_removeAlgorithmParameter(SedAlgorithmParameter_t* sap,
                                               unsigned int n)
{
  return (sap != NULL) ? sap->removeAlgorithmParameter(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAlgorithmParameter_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_hasRequiredAttributes(const SedAlgorithmParameter_t *
  sap)
{
  return (sap != NULL) ? static_cast<int>(sap->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


