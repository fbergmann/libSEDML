/**
 * @file SedListOfRemainingDimensions.cpp
 * @brief Implementation of the SedListOfRemainingDimensions class.
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
#include <sedml/SedListOfRemainingDimensions.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfRemainingDimensions using the given SEDML Level and @
 * p version values.
 */
SedListOfRemainingDimensions::SedListOfRemainingDimensions(unsigned int level,
                                                           unsigned int
                                                             version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfRemainingDimensions using the given SedNamespaces
 * object @p sedmlns.
 */
SedListOfRemainingDimensions::SedListOfRemainingDimensions(SedNamespaces
  *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfRemainingDimensions.
 */
SedListOfRemainingDimensions::SedListOfRemainingDimensions(const
  SedListOfRemainingDimensions& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfRemainingDimensions.
 */
SedListOfRemainingDimensions&
SedListOfRemainingDimensions::operator=(const SedListOfRemainingDimensions&
  rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfRemainingDimensions object.
 */
SedListOfRemainingDimensions*
SedListOfRemainingDimensions::clone() const
{
  return new SedListOfRemainingDimensions(*this);
}


/*
 * Destructor for SedListOfRemainingDimensions.
 */
SedListOfRemainingDimensions::~SedListOfRemainingDimensions()
{
}


/*
 * Get a SedRemainingDimension from the SedListOfRemainingDimensions.
 */
SedRemainingDimension*
SedListOfRemainingDimensions::get(unsigned int n)
{
  return static_cast<SedRemainingDimension*>(SedListOf::get(n));
}


/*
 * Get a SedRemainingDimension from the SedListOfRemainingDimensions.
 */
const SedRemainingDimension*
SedListOfRemainingDimensions::get(unsigned int n) const
{
  return static_cast<const SedRemainingDimension*>(SedListOf::get(n));
}


/*
 * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
 * its identifier.
 */
SedRemainingDimension*
SedListOfRemainingDimensions::get(const std::string& sid)
{
  return const_cast<SedRemainingDimension*>(static_cast<const
    SedListOfRemainingDimensions&>(*this).get(sid));
}


/*
 * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
 * its identifier.
 */
const SedRemainingDimension*
SedListOfRemainingDimensions::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedRemainingDimension>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedRemainingDimension*> (*result);
}


/*
 * Removes the nth SedRemainingDimension from this SedListOfRemainingDimensions
 * and returns a pointer to it.
 */
SedRemainingDimension*
SedListOfRemainingDimensions::remove(unsigned int n)
{
  return static_cast<SedRemainingDimension*>(SedListOf::remove(n));
}


/*
 * Removes the SedRemainingDimension from this SedListOfRemainingDimensions
 * based on its identifier and returns a pointer to it.
 */
SedRemainingDimension*
SedListOfRemainingDimensions::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedRemainingDimension>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedRemainingDimension*> (item);
}


/*
 * Adds a copy of the given SedRemainingDimension to this
 * SedListOfRemainingDimensions.
 */
int
SedListOfRemainingDimensions::addRemainingDimension(const
  SedRemainingDimension* srd)
{
  if (srd == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (srd->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != srd->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != srd->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(srd)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(srd);
  }
}


/*
 * Get the number of SedRemainingDimension objects in this
 * SedListOfRemainingDimensions.
 */
unsigned int
SedListOfRemainingDimensions::getNumRemainingDimensions() const
{
  return size();
}


/*
 * Creates a new SedRemainingDimension object, adds it to this
 * SedListOfRemainingDimensions object and returns the SedRemainingDimension
 * object created.
 */
SedRemainingDimension*
SedListOfRemainingDimensions::createRemainingDimension()
{
  SedRemainingDimension* srd = NULL;

  try
  {
    srd = new SedRemainingDimension(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (srd != NULL)
  {
    appendAndOwn(srd);
  }

  return srd;
}


/*
 * Used by SedListOfRemainingDimensions::get() to lookup a
 * SedRemainingDimension based on its Target.
 */
struct SedIdEqT
{
  const string& id;
   
  SedIdEqT (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedRemainingDimension*>(sb)->getTarget() == id);
  }
};


/*
 * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
 * the Target to which it refers.
 */
const SedRemainingDimension*
SedListOfRemainingDimensions::getByTarget(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqT(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedRemainingDimension*> (*result);
}


/*
 * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
 * the Target to which it refers.
 */
SedRemainingDimension*
SedListOfRemainingDimensions::getByTarget(const std::string& sid)
{
  return const_cast<SedRemainingDimension*>(static_cast<const
    SedListOfRemainingDimensions&>(*this).getByTarget(sid));
}


/*
 * Used by SedListOfRemainingDimensions::get() to lookup a
 * SedRemainingDimension based on its DimensionTarget.
 */
struct SedIdEqDT
{
  const string& id;
   
  SedIdEqDT (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedRemainingDimension*>(sb)->getDimensionTarget() == id);
  }
};


/*
 * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
 * the DimensionTarget to which it refers.
 */
const SedRemainingDimension*
SedListOfRemainingDimensions::getByDimensionTarget(const std::string& sid)
  const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqDT(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedRemainingDimension*> (*result);
}


/*
 * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
 * the DimensionTarget to which it refers.
 */
SedRemainingDimension*
SedListOfRemainingDimensions::getByDimensionTarget(const std::string& sid)
{
  return const_cast<SedRemainingDimension*>(static_cast<const
    SedListOfRemainingDimensions&>(*this).getByDimensionTarget(sid));
}


/*
 * Returns the XML element name of this SedListOfRemainingDimensions object.
 */
const std::string&
SedListOfRemainingDimensions::getElementName() const
{
  static const string name = "listOfRemainingDimensions";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfRemainingDimensions object.
 */
int
SedListOfRemainingDimensions::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SEDML objects contained in this
 * SedListOfRemainingDimensions object.
 */
int
SedListOfRemainingDimensions::getItemTypeCode() const
{
  return SEDML_REMAININGDIMENSION;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedRemainingDimension in this SedListOfRemainingDimensions
 */
SedBase*
SedListOfRemainingDimensions::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "remainingDimension")
  {
    object = new SedRemainingDimension(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedRemainingDimension_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedListOfRemainingDimensions_getRemainingDimension(SedListOf_t* slo,
                                                   unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfRemainingDimensions*>(slo)->get(n);
}


/*
 * Get a SedRemainingDimension_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedListOfRemainingDimensions_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfRemainingDimensions*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedRemainingDimension_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedListOfRemainingDimensions_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfRemainingDimensions*>(slo)->remove(n);
}


/*
 * Removes the SedRemainingDimension_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedListOfRemainingDimensions_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfRemainingDimensions*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


