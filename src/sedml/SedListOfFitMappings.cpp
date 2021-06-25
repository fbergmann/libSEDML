/**
 * @file SedListOfFitMappings.cpp
 * @brief Implementation of the SedListOfFitMappings class.
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
#include <sedml/SedListOfFitMappings.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfFitMappings using the given SED-ML Level and @ p
 * version values.
 */
SedListOfFitMappings::SedListOfFitMappings(unsigned int level,
                                           unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfFitMappings using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfFitMappings::SedListOfFitMappings(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfFitMappings.
 */
SedListOfFitMappings::SedListOfFitMappings(const SedListOfFitMappings& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfFitMappings.
 */
SedListOfFitMappings&
SedListOfFitMappings::operator=(const SedListOfFitMappings& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfFitMappings object.
 */
SedListOfFitMappings*
SedListOfFitMappings::clone() const
{
  return new SedListOfFitMappings(*this);
}


/*
 * Destructor for SedListOfFitMappings.
 */
SedListOfFitMappings::~SedListOfFitMappings()
{
}


/*
 * Get a SedFitMapping from the SedListOfFitMappings.
 */
SedFitMapping*
SedListOfFitMappings::get(unsigned int n)
{
  return static_cast<SedFitMapping*>(SedListOf::get(n));
}


/*
 * Get a SedFitMapping from the SedListOfFitMappings.
 */
const SedFitMapping*
SedListOfFitMappings::get(unsigned int n) const
{
  return static_cast<const SedFitMapping*>(SedListOf::get(n));
}


/*
 * Get a SedFitMapping from the SedListOfFitMappings based on its identifier.
 */
SedFitMapping*
SedListOfFitMappings::get(const std::string& sid)
{
  return const_cast<SedFitMapping*>(static_cast<const
    SedListOfFitMappings&>(*this).get(sid));
}


/*
 * Get a SedFitMapping from the SedListOfFitMappings based on its identifier.
 */
const SedFitMapping*
SedListOfFitMappings::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedFitMapping>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedFitMapping*>
    (*result);
}


/*
 * Removes the nth SedFitMapping from this SedListOfFitMappings and returns a
 * pointer to it.
 */
SedFitMapping*
SedListOfFitMappings::remove(unsigned int n)
{
  return static_cast<SedFitMapping*>(SedListOf::remove(n));
}


/*
 * Removes the SedFitMapping from this SedListOfFitMappings based on its
 * identifier and returns a pointer to it.
 */
SedFitMapping*
SedListOfFitMappings::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedFitMapping>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedFitMapping*> (item);
}


/*
 * Adds a copy of the given SedFitMapping to this SedListOfFitMappings.
 */
int
SedListOfFitMappings::addFitMapping(const SedFitMapping* sfm)
{
  if (sfm == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sfm->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sfm->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sfm->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sfm)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sfm);
  }
}


/*
 * Get the number of SedFitMapping objects in this SedListOfFitMappings.
 */
unsigned int
SedListOfFitMappings::getNumFitMappings() const
{
  return size();
}


/*
 * Creates a new SedFitMapping object, adds it to this SedListOfFitMappings
 * object and returns the SedFitMapping object created.
 */
SedFitMapping*
SedListOfFitMappings::createFitMapping()
{
  SedFitMapping* sfm = NULL;

  try
  {
    sfm = new SedFitMapping(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sfm != NULL)
  {
    appendAndOwn(sfm);
  }

  return sfm;
}


/*
 * Used by SedListOfFitMappings::get() to lookup a SedFitMapping based on its
 * DataSource.
 */
struct SedIdEqDS
{
  const string& id;
   
  SedIdEqDS (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedFitMapping*>(sb)->getDataSource() == id);
  }
};


/*
 * Get a SedFitMapping from the SedListOfFitMappings based on the DataSource to
 * which it refers.
 */
const SedFitMapping*
SedListOfFitMappings::getByDataSource(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqDS(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedFitMapping*>
    (*result);
}


/*
 * Get a SedFitMapping from the SedListOfFitMappings based on the DataSource to
 * which it refers.
 */
SedFitMapping*
SedListOfFitMappings::getByDataSource(const std::string& sid)
{
  return const_cast<SedFitMapping*>(static_cast<const
    SedListOfFitMappings&>(*this).getByDataSource(sid));
}


/*
 * Used by SedListOfFitMappings::get() to lookup a SedFitMapping based on its
 * Target.
 */
struct SedIdEqT
{
  const string& id;
   
  SedIdEqT (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedFitMapping*>(sb)->getTarget() == id);
  }
};


/*
 * Get a SedFitMapping from the SedListOfFitMappings based on the Target to
 * which it refers.
 */
const SedFitMapping*
SedListOfFitMappings::getByTarget(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqT(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedFitMapping*>
    (*result);
}


/*
 * Get a SedFitMapping from the SedListOfFitMappings based on the Target to
 * which it refers.
 */
SedFitMapping*
SedListOfFitMappings::getByTarget(const std::string& sid)
{
  return const_cast<SedFitMapping*>(static_cast<const
    SedListOfFitMappings&>(*this).getByTarget(sid));
}


/*
 * Used by SedListOfFitMappings::get() to lookup a SedFitMapping based on its
 * PointWeight.
 */
struct SedIdEqPW
{
  const string& id;
   
  SedIdEqPW (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedFitMapping*>(sb)->getPointWeight() == id);
  }
};


/*
 * Get a SedFitMapping from the SedListOfFitMappings based on the PointWeight
 * to which it refers.
 */
const SedFitMapping*
SedListOfFitMappings::getByPointWeight(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqPW(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedFitMapping*>
    (*result);
}


/*
 * Get a SedFitMapping from the SedListOfFitMappings based on the PointWeight
 * to which it refers.
 */
SedFitMapping*
SedListOfFitMappings::getByPointWeight(const std::string& sid)
{
  return const_cast<SedFitMapping*>(static_cast<const
    SedListOfFitMappings&>(*this).getByPointWeight(sid));
}


/*
 * Returns the XML element name of this SedListOfFitMappings object.
 */
const std::string&
SedListOfFitMappings::getElementName() const
{
  static const string name = "listOfFitMappings";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfFitMappings object.
 */
int
SedListOfFitMappings::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfFitMappings object.
 */
int
SedListOfFitMappings::getItemTypeCode() const
{
  return SEDML_FITMAPPING;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedFitMapping in this SedListOfFitMappings
 */
SedBase*
SedListOfFitMappings::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "fitMapping")
  {
    object = new SedFitMapping(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedFitMapping_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedListOfFitMappings_getFitMapping(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfFitMappings*>(slo)->get(n);
}


/*
 * Get a SedFitMapping_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedListOfFitMappings_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfFitMappings*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedFitMapping_t from this SedListOf_t and returns a pointer
 * to it.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedListOfFitMappings_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfFitMappings*>(slo)->remove(n);
}


/*
 * Removes the SedFitMapping_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedListOfFitMappings_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfFitMappings*>(slo)->remove(sid)
    : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


