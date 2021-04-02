/**
 * @file SedListOfDataSets.cpp
 * @brief Implementation of the SedListOfDataSets class.
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
#include <sedml/SedListOfDataSets.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfDataSets using the given SED-ML Level and @ p version
 * values.
 */
SedListOfDataSets::SedListOfDataSets(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfDataSets using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfDataSets::SedListOfDataSets(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfDataSets.
 */
SedListOfDataSets::SedListOfDataSets(const SedListOfDataSets& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfDataSets.
 */
SedListOfDataSets&
SedListOfDataSets::operator=(const SedListOfDataSets& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfDataSets object.
 */
SedListOfDataSets*
SedListOfDataSets::clone() const
{
  return new SedListOfDataSets(*this);
}


/*
 * Destructor for SedListOfDataSets.
 */
SedListOfDataSets::~SedListOfDataSets()
{
}


/*
 * Get a SedDataSet from the SedListOfDataSets.
 */
SedDataSet*
SedListOfDataSets::get(unsigned int n)
{
  return static_cast<SedDataSet*>(SedListOf::get(n));
}


/*
 * Get a SedDataSet from the SedListOfDataSets.
 */
const SedDataSet*
SedListOfDataSets::get(unsigned int n) const
{
  return static_cast<const SedDataSet*>(SedListOf::get(n));
}


/*
 * Get a SedDataSet from the SedListOfDataSets based on its identifier.
 */
SedDataSet*
SedListOfDataSets::get(const std::string& sid)
{
  return const_cast<SedDataSet*>(static_cast<const
    SedListOfDataSets&>(*this).get(sid));
}


/*
 * Get a SedDataSet from the SedListOfDataSets based on its identifier.
 */
const SedDataSet*
SedListOfDataSets::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedDataSet>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedDataSet*>
    (*result);
}


/*
 * Removes the nth SedDataSet from this SedListOfDataSets and returns a pointer
 * to it.
 */
SedDataSet*
SedListOfDataSets::remove(unsigned int n)
{
  return static_cast<SedDataSet*>(SedListOf::remove(n));
}


/*
 * Removes the SedDataSet from this SedListOfDataSets based on its identifier
 * and returns a pointer to it.
 */
SedDataSet*
SedListOfDataSets::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedDataSet>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedDataSet*> (item);
}


/*
 * Adds a copy of the given SedDataSet to this SedListOfDataSets.
 */
int
SedListOfDataSets::addDataSet(const SedDataSet* sds)
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
 * Get the number of SedDataSet objects in this SedListOfDataSets.
 */
unsigned int
SedListOfDataSets::getNumDataSets() const
{
  return size();
}


/*
 * Creates a new SedDataSet object, adds it to this SedListOfDataSets object
 * and returns the SedDataSet object created.
 */
SedDataSet*
SedListOfDataSets::createDataSet()
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
    appendAndOwn(sds);
  }

  return sds;
}


/*
 * Used by SedListOfDataSets::get() to lookup a SedDataSet based on its
 * DataReference.
 */
struct SedIdEqDR
{
  const string& id;
   
  SedIdEqDR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedDataSet*>(sb)->getDataReference() == id);
  }
};


/*
 * Get a SedDataSet from the SedListOfDataSets based on the DataReference to
 * which it refers.
 */
const SedDataSet*
SedListOfDataSets::getByDataReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqDR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedDataSet*>
    (*result);
}


/*
 * Get a SedDataSet from the SedListOfDataSets based on the DataReference to
 * which it refers.
 */
SedDataSet*
SedListOfDataSets::getByDataReference(const std::string& sid)
{
  return const_cast<SedDataSet*>(static_cast<const
    SedListOfDataSets&>(*this).getByDataReference(sid));
}


/*
 * Returns the XML element name of this SedListOfDataSets object.
 */
const std::string&
SedListOfDataSets::getElementName() const
{
  static const string name = "listOfDataSets";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfDataSets object.
 */
int
SedListOfDataSets::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfDataSets object.
 */
int
SedListOfDataSets::getItemTypeCode() const
{
  return SEDML_OUTPUT_DATASET;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedDataSet in this SedListOfDataSets
 */
SedBase*
SedListOfDataSets::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "dataSet")
  {
    object = new SedDataSet(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedDataSet_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedListOfDataSets_getDataSet(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfDataSets*>(slo)->get(n);
}


/*
 * Get a SedDataSet_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedListOfDataSets_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfDataSets*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedDataSet_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedListOfDataSets_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfDataSets*>(slo)->remove(n);
}


/*
 * Removes the SedDataSet_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedListOfDataSets_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfDataSets*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


