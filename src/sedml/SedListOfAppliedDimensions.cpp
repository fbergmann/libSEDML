/**
 * @file SedListOfAppliedDimensions.cpp
 * @brief Implementation of the SedListOfAppliedDimensions class.
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
#include <sedml/SedListOfAppliedDimensions.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfAppliedDimensions using the given SED-ML Level and @
 * p version values.
 */
SedListOfAppliedDimensions::SedListOfAppliedDimensions(unsigned int level,
                                                           unsigned int
                                                             version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfAppliedDimensions using the given SedNamespaces
 * object @p sedmlns.
 */
SedListOfAppliedDimensions::SedListOfAppliedDimensions(SedNamespaces
  *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfAppliedDimensions.
 */
SedListOfAppliedDimensions::SedListOfAppliedDimensions(const
  SedListOfAppliedDimensions& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfAppliedDimensions.
 */
SedListOfAppliedDimensions&
SedListOfAppliedDimensions::operator=(const SedListOfAppliedDimensions&
  rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfAppliedDimensions object.
 */
SedListOfAppliedDimensions*
SedListOfAppliedDimensions::clone() const
{
  return new SedListOfAppliedDimensions(*this);
}


/*
 * Destructor for SedListOfAppliedDimensions.
 */
SedListOfAppliedDimensions::~SedListOfAppliedDimensions()
{
}


/*
 * Get a SedAppliedDimension from the SedListOfAppliedDimensions.
 */
SedAppliedDimension*
SedListOfAppliedDimensions::get(unsigned int n)
{
  return static_cast<SedAppliedDimension*>(SedListOf::get(n));
}


/*
 * Get a SedAppliedDimension from the SedListOfAppliedDimensions.
 */
const SedAppliedDimension*
SedListOfAppliedDimensions::get(unsigned int n) const
{
  return static_cast<const SedAppliedDimension*>(SedListOf::get(n));
}


/*
 * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
 * its identifier.
 */
SedAppliedDimension*
SedListOfAppliedDimensions::get(const std::string& sid)
{
  return const_cast<SedAppliedDimension*>(static_cast<const
    SedListOfAppliedDimensions&>(*this).get(sid));
}


/*
 * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
 * its identifier.
 */
const SedAppliedDimension*
SedListOfAppliedDimensions::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAppliedDimension>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedAppliedDimension*> (*result);
}


/*
 * Removes the nth SedAppliedDimension from this SedListOfAppliedDimensions
 * and returns a pointer to it.
 */
SedAppliedDimension*
SedListOfAppliedDimensions::remove(unsigned int n)
{
  return static_cast<SedAppliedDimension*>(SedListOf::remove(n));
}


/*
 * Removes the SedAppliedDimension from this SedListOfAppliedDimensions
 * based on its identifier and returns a pointer to it.
 */
SedAppliedDimension*
SedListOfAppliedDimensions::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAppliedDimension>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedAppliedDimension*> (item);
}


/*
 * Adds a copy of the given SedAppliedDimension to this
 * SedListOfAppliedDimensions.
 */
int
SedListOfAppliedDimensions::addAppliedDimension(const
  SedAppliedDimension* srd)
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
 * Get the number of SedAppliedDimension objects in this
 * SedListOfAppliedDimensions.
 */
unsigned int
SedListOfAppliedDimensions::getNumAppliedDimensions() const
{
  return size();
}


/*
 * Creates a new SedAppliedDimension object, adds it to this
 * SedListOfAppliedDimensions object and returns the SedAppliedDimension
 * object created.
 */
SedAppliedDimension*
SedListOfAppliedDimensions::createAppliedDimension()
{
  SedAppliedDimension* srd = NULL;

  try
  {
    srd = new SedAppliedDimension(getSedNamespaces());
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
 * Used by SedListOfAppliedDimensions::get() to lookup a
 * SedAppliedDimension based on its Target.
 */
struct SedIdEqT
{
  const string& id;
   
  SedIdEqT (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedAppliedDimension*>(sb)->getTarget() == id);
  }
};


/*
 * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
 * the Target to which it refers.
 */
const SedAppliedDimension*
SedListOfAppliedDimensions::getByTarget(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqT(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedAppliedDimension*> (*result);
}


/*
 * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
 * the Target to which it refers.
 */
SedAppliedDimension*
SedListOfAppliedDimensions::getByTarget(const std::string& sid)
{
  return const_cast<SedAppliedDimension*>(static_cast<const
    SedListOfAppliedDimensions&>(*this).getByTarget(sid));
}


/*
 * Used by SedListOfAppliedDimensions::get() to lookup a
 * SedAppliedDimension based on its DimensionTarget.
 */
struct SedIdEqDT
{
  const string& id;
   
  SedIdEqDT (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedAppliedDimension*>(sb)->getDimensionTarget() == id);
  }
};


/*
 * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
 * the DimensionTarget to which it refers.
 */
const SedAppliedDimension*
SedListOfAppliedDimensions::getByDimensionTarget(const std::string& sid)
  const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqDT(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedAppliedDimension*> (*result);
}


/*
 * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
 * the DimensionTarget to which it refers.
 */
SedAppliedDimension*
SedListOfAppliedDimensions::getByDimensionTarget(const std::string& sid)
{
  return const_cast<SedAppliedDimension*>(static_cast<const
    SedListOfAppliedDimensions&>(*this).getByDimensionTarget(sid));
}


/*
 * Returns the XML element name of this SedListOfAppliedDimensions object.
 */
const std::string&
SedListOfAppliedDimensions::getElementName() const
{
  static const string name = "listOfAppliedDimensions";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfAppliedDimensions object.
 */
int
SedListOfAppliedDimensions::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfAppliedDimensions object.
 */
int
SedListOfAppliedDimensions::getItemTypeCode() const
{
  return SEDML_APPLIEDDIMENSION;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedAppliedDimension in this SedListOfAppliedDimensions
 */
SedBase*
SedListOfAppliedDimensions::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "appliedDimension")
  {
    object = new SedAppliedDimension(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedAppliedDimension_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedListOfAppliedDimensions_getAppliedDimension(SedListOf_t* slo,
                                                   unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfAppliedDimensions*>(slo)->get(n);
}


/*
 * Get a SedAppliedDimension_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedListOfAppliedDimensions_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfAppliedDimensions*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedAppliedDimension_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedListOfAppliedDimensions_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfAppliedDimensions*>(slo)->remove(n);
}


/*
 * Removes the SedAppliedDimension_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedListOfAppliedDimensions_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfAppliedDimensions*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


