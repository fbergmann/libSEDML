/**
 * @file SedListOfExperimentRefs.cpp
 * @brief Implementation of the SedListOfExperimentRefs class.
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
#include <sedml/SedListOfExperimentRefs.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfExperimentRefs using the given SEDML Level and @ p
 * version values.
 */
SedListOfExperimentRefs::SedListOfExperimentRefs(unsigned int level,
                                                 unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfExperimentRefs using the given SedNamespaces object
 * @p sedmlns.
 */
SedListOfExperimentRefs::SedListOfExperimentRefs(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfExperimentRefs.
 */
SedListOfExperimentRefs::SedListOfExperimentRefs(const SedListOfExperimentRefs&
  orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfExperimentRefs.
 */
SedListOfExperimentRefs&
SedListOfExperimentRefs::operator=(const SedListOfExperimentRefs& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfExperimentRefs object.
 */
SedListOfExperimentRefs*
SedListOfExperimentRefs::clone() const
{
  return new SedListOfExperimentRefs(*this);
}


/*
 * Destructor for SedListOfExperimentRefs.
 */
SedListOfExperimentRefs::~SedListOfExperimentRefs()
{
}


/*
 * Get a SedExperimentRef from the SedListOfExperimentRefs.
 */
SedExperimentRef*
SedListOfExperimentRefs::get(unsigned int n)
{
  return static_cast<SedExperimentRef*>(SedListOf::get(n));
}


/*
 * Get a SedExperimentRef from the SedListOfExperimentRefs.
 */
const SedExperimentRef*
SedListOfExperimentRefs::get(unsigned int n) const
{
  return static_cast<const SedExperimentRef*>(SedListOf::get(n));
}


/*
 * Get a SedExperimentRef from the SedListOfExperimentRefs based on its
 * identifier.
 */
SedExperimentRef*
SedListOfExperimentRefs::get(const std::string& sid)
{
  return const_cast<SedExperimentRef*>(static_cast<const
    SedListOfExperimentRefs&>(*this).get(sid));
}


/*
 * Get a SedExperimentRef from the SedListOfExperimentRefs based on its
 * identifier.
 */
const SedExperimentRef*
SedListOfExperimentRefs::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedExperimentRef>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedExperimentRef*>
    (*result);
}


/*
 * Removes the nth SedExperimentRef from this SedListOfExperimentRefs and
 * returns a pointer to it.
 */
SedExperimentRef*
SedListOfExperimentRefs::remove(unsigned int n)
{
  return static_cast<SedExperimentRef*>(SedListOf::remove(n));
}


/*
 * Removes the SedExperimentRef from this SedListOfExperimentRefs based on its
 * identifier and returns a pointer to it.
 */
SedExperimentRef*
SedListOfExperimentRefs::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedExperimentRef>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedExperimentRef*> (item);
}


/*
 * Adds a copy of the given SedExperimentRef to this SedListOfExperimentRefs.
 */
int
SedListOfExperimentRefs::addExperimentRef(const SedExperimentRef* ser)
{
  if (ser == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ser->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ser->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ser->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ser)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(ser);
  }
}


/*
 * Get the number of SedExperimentRef objects in this SedListOfExperimentRefs.
 */
unsigned int
SedListOfExperimentRefs::getNumExperimentRefs() const
{
  return size();
}


/*
 * Creates a new SedExperimentRef object, adds it to this
 * SedListOfExperimentRefs object and returns the SedExperimentRef object
 * created.
 */
SedExperimentRef*
SedListOfExperimentRefs::createExperimentRef()
{
  SedExperimentRef* ser = NULL;

  try
  {
    ser = new SedExperimentRef(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ser != NULL)
  {
    appendAndOwn(ser);
  }

  return ser;
}


/*
 * Used by SedListOfExperimentRefs::get() to lookup a SedExperimentRef based on
 * its ExperimentId.
 */
struct SedIdEqEI
{
  const string& id;
   
  SedIdEqEI (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedExperimentRef*>(sb)->getExperimentId() == id);
  }
};


/*
 * Get a SedExperimentRef from the SedListOfExperimentRefs based on the
 * ExperimentId to which it refers.
 */
const SedExperimentRef*
SedListOfExperimentRefs::getByExperimentId(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqEI(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedExperimentRef*>
    (*result);
}


/*
 * Get a SedExperimentRef from the SedListOfExperimentRefs based on the
 * ExperimentId to which it refers.
 */
SedExperimentRef*
SedListOfExperimentRefs::getByExperimentId(const std::string& sid)
{
  return const_cast<SedExperimentRef*>(static_cast<const
    SedListOfExperimentRefs&>(*this).getByExperimentId(sid));
}


/*
 * Returns the XML element name of this SedListOfExperimentRefs object.
 */
const std::string&
SedListOfExperimentRefs::getElementName() const
{
  static const string name = "listOfExperimentRefs";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfExperimentRefs object.
 */
int
SedListOfExperimentRefs::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SEDML objects contained in this
 * SedListOfExperimentRefs object.
 */
int
SedListOfExperimentRefs::getItemTypeCode() const
{
  return SEDML_EXPERIMENT_REF;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedExperimentRef in this SedListOfExperimentRefs
 */
SedBase*
SedListOfExperimentRefs::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "experimentRef")
  {
    object = new SedExperimentRef(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedExperimentRef_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedListOfExperimentRefs_getExperimentRef(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfExperimentRefs*>(slo)->get(n);
}


/*
 * Get a SedExperimentRef_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedListOfExperimentRefs_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfExperimentRefs*>(slo)->get(sid)
    : NULL;
}


/*
 * Removes the nth SedExperimentRef_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedListOfExperimentRefs_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfExperimentRefs*>(slo)->remove(n);
}


/*
 * Removes the SedExperimentRef_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedListOfExperimentRefs_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfExperimentRefs*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


