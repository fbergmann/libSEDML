/**
 * @file SedListOfDataDescriptions.cpp
 * @brief Implementation of the SedListOfDataDescriptions class.
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
#include <sedml/SedListOfDataDescriptions.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfDataDescriptions using the given SED-ML Level and @ p
 * version values.
 */
SedListOfDataDescriptions::SedListOfDataDescriptions(unsigned int level,
                                                     unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfDataDescriptions using the given SedNamespaces object
 * @p sedmlns.
 */
SedListOfDataDescriptions::SedListOfDataDescriptions(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfDataDescriptions.
 */
SedListOfDataDescriptions::SedListOfDataDescriptions(const
  SedListOfDataDescriptions& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfDataDescriptions.
 */
SedListOfDataDescriptions&
SedListOfDataDescriptions::operator=(const SedListOfDataDescriptions& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfDataDescriptions object.
 */
SedListOfDataDescriptions*
SedListOfDataDescriptions::clone() const
{
  return new SedListOfDataDescriptions(*this);
}


/*
 * Destructor for SedListOfDataDescriptions.
 */
SedListOfDataDescriptions::~SedListOfDataDescriptions()
{
}


/*
 * Get a SedDataDescription from the SedListOfDataDescriptions.
 */
SedDataDescription*
SedListOfDataDescriptions::get(unsigned int n)
{
  return static_cast<SedDataDescription*>(SedListOf::get(n));
}


/*
 * Get a SedDataDescription from the SedListOfDataDescriptions.
 */
const SedDataDescription*
SedListOfDataDescriptions::get(unsigned int n) const
{
  return static_cast<const SedDataDescription*>(SedListOf::get(n));
}


/*
 * Get a SedDataDescription from the SedListOfDataDescriptions based on its
 * identifier.
 */
SedDataDescription*
SedListOfDataDescriptions::get(const std::string& sid)
{
  return const_cast<SedDataDescription*>(static_cast<const
    SedListOfDataDescriptions&>(*this).get(sid));
}


/*
 * Get a SedDataDescription from the SedListOfDataDescriptions based on its
 * identifier.
 */
const SedDataDescription*
SedListOfDataDescriptions::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedDataDescription>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedDataDescription*>
    (*result);
}


/*
 * Removes the nth SedDataDescription from this SedListOfDataDescriptions and
 * returns a pointer to it.
 */
SedDataDescription*
SedListOfDataDescriptions::remove(unsigned int n)
{
  return static_cast<SedDataDescription*>(SedListOf::remove(n));
}


/*
 * Removes the SedDataDescription from this SedListOfDataDescriptions based on
 * its identifier and returns a pointer to it.
 */
SedDataDescription*
SedListOfDataDescriptions::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedDataDescription>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedDataDescription*> (item);
}


/*
 * Adds a copy of the given SedDataDescription to this
 * SedListOfDataDescriptions.
 */
int
SedListOfDataDescriptions::addDataDescription(const SedDataDescription* sdd)
{
  if (sdd == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sdd->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sdd->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sdd->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sdd)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sdd);
  }
}


/*
 * Get the number of SedDataDescription objects in this
 * SedListOfDataDescriptions.
 */
unsigned int
SedListOfDataDescriptions::getNumDataDescriptions() const
{
  return size();
}


/*
 * Creates a new SedDataDescription object, adds it to this
 * SedListOfDataDescriptions object and returns the SedDataDescription object
 * created.
 */
SedDataDescription*
SedListOfDataDescriptions::createDataDescription()
{
  SedDataDescription* sdd = NULL;

  try
  {
    sdd = new SedDataDescription(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sdd != NULL)
  {
    appendAndOwn(sdd);
  }

  return sdd;
}


/*
 * Returns the XML element name of this SedListOfDataDescriptions object.
 */
const std::string&
SedListOfDataDescriptions::getElementName() const
{
  static const string name = "listOfDataDescriptions";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfDataDescriptions object.
 */
int
SedListOfDataDescriptions::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfDataDescriptions object.
 */
int
SedListOfDataDescriptions::getItemTypeCode() const
{
  return SEDML_DATA_DESCRIPTION;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedDataDescription in this SedListOfDataDescriptions
 */
SedBase*
SedListOfDataDescriptions::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "dataDescription")
  {
    object = new SedDataDescription(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedDataDescription_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedListOfDataDescriptions_getDataDescription(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfDataDescriptions*>(slo)->get(n);
}


/*
 * Get a SedDataDescription_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedListOfDataDescriptions_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfDataDescriptions*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedDataDescription_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedListOfDataDescriptions_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfDataDescriptions*>(slo)->remove(n);
}


/*
 * Removes the SedDataDescription_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedListOfDataDescriptions_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfDataDescriptions*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


