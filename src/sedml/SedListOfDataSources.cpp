/**
 * @file SedListOfDataSources.cpp
 * @brief Implementation of the SedListOfDataSources class.
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
#include <sedml/SedListOfDataSources.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfDataSources using the given SED-ML Level and @ p
 * version values.
 */
SedListOfDataSources::SedListOfDataSources(unsigned int level,
                                           unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfDataSources using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfDataSources::SedListOfDataSources(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfDataSources.
 */
SedListOfDataSources::SedListOfDataSources(const SedListOfDataSources& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfDataSources.
 */
SedListOfDataSources&
SedListOfDataSources::operator=(const SedListOfDataSources& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfDataSources object.
 */
SedListOfDataSources*
SedListOfDataSources::clone() const
{
  return new SedListOfDataSources(*this);
}


/*
 * Destructor for SedListOfDataSources.
 */
SedListOfDataSources::~SedListOfDataSources()
{
}


/*
 * Get a SedDataSource from the SedListOfDataSources.
 */
SedDataSource*
SedListOfDataSources::get(unsigned int n)
{
  return static_cast<SedDataSource*>(SedListOf::get(n));
}


/*
 * Get a SedDataSource from the SedListOfDataSources.
 */
const SedDataSource*
SedListOfDataSources::get(unsigned int n) const
{
  return static_cast<const SedDataSource*>(SedListOf::get(n));
}


/*
 * Get a SedDataSource from the SedListOfDataSources based on its identifier.
 */
SedDataSource*
SedListOfDataSources::get(const std::string& sid)
{
  return const_cast<SedDataSource*>(static_cast<const
    SedListOfDataSources&>(*this).get(sid));
}


/*
 * Get a SedDataSource from the SedListOfDataSources based on its identifier.
 */
const SedDataSource*
SedListOfDataSources::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedDataSource>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedDataSource*>
    (*result);
}


/*
 * Removes the nth SedDataSource from this SedListOfDataSources and returns a
 * pointer to it.
 */
SedDataSource*
SedListOfDataSources::remove(unsigned int n)
{
  return static_cast<SedDataSource*>(SedListOf::remove(n));
}


/*
 * Removes the SedDataSource from this SedListOfDataSources based on its
 * identifier and returns a pointer to it.
 */
SedDataSource*
SedListOfDataSources::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedDataSource>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedDataSource*> (item);
}


/*
 * Adds a copy of the given SedDataSource to this SedListOfDataSources.
 */
int
SedListOfDataSources::addDataSource(const SedDataSource* sds)
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
  else
  {
    return append(sds);
  }
}


/*
 * Get the number of SedDataSource objects in this SedListOfDataSources.
 */
unsigned int
SedListOfDataSources::getNumDataSources() const
{
  return size();
}


/*
 * Creates a new SedDataSource object, adds it to this SedListOfDataSources
 * object and returns the SedDataSource object created.
 */
SedDataSource*
SedListOfDataSources::createDataSource()
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
    appendAndOwn(sds);
  }

  return sds;
}


/*
 * Used by SedListOfDataSources::get() to lookup a SedDataSource based on its
 * IndexSet.
 */
struct SedIdEqIS
{
  const string& id;
   
  SedIdEqIS (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedDataSource*>(sb)->getIndexSet() == id);
  }
};


/*
 * Get a SedDataSource from the SedListOfDataSources based on the IndexSet to
 * which it refers.
 */
const SedDataSource*
SedListOfDataSources::getByIndexSet(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqIS(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedDataSource*>
    (*result);
}


/*
 * Get a SedDataSource from the SedListOfDataSources based on the IndexSet to
 * which it refers.
 */
SedDataSource*
SedListOfDataSources::getByIndexSet(const std::string& sid)
{
  return const_cast<SedDataSource*>(static_cast<const
    SedListOfDataSources&>(*this).getByIndexSet(sid));
}


/*
 * Returns the XML element name of this SedListOfDataSources object.
 */
const std::string&
SedListOfDataSources::getElementName() const
{
  static const string name = "listOfDataSources";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfDataSources object.
 */
int
SedListOfDataSources::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfDataSources object.
 */
int
SedListOfDataSources::getItemTypeCode() const
{
  return SEDML_DATA_SOURCE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedDataSource in this SedListOfDataSources
 */
SedBase*
SedListOfDataSources::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "dataSource")
  {
    object = new SedDataSource(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedDataSource_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedListOfDataSources_getDataSource(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfDataSources*>(slo)->get(n);
}


/*
 * Get a SedDataSource_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedListOfDataSources_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfDataSources*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedDataSource_t from this SedListOf_t and returns a pointer
 * to it.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedListOfDataSources_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfDataSources*>(slo)->remove(n);
}


/*
 * Removes the SedDataSource_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedListOfDataSources_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfDataSources*>(slo)->remove(sid)
    : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


