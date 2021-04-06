/**
 * @file SedListOfSlices.cpp
 * @brief Implementation of the SedListOfSlices class.
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
#include <sedml/SedListOfSlices.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfSlices using the given SED-ML Level and @ p version
 * values.
 */
SedListOfSlices::SedListOfSlices(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfSlices using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfSlices::SedListOfSlices(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfSlices.
 */
SedListOfSlices::SedListOfSlices(const SedListOfSlices& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfSlices.
 */
SedListOfSlices&
SedListOfSlices::operator=(const SedListOfSlices& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfSlices object.
 */
SedListOfSlices*
SedListOfSlices::clone() const
{
  return new SedListOfSlices(*this);
}


/*
 * Destructor for SedListOfSlices.
 */
SedListOfSlices::~SedListOfSlices()
{
}


/*
 * Get a SedSlice from the SedListOfSlices.
 */
SedSlice*
SedListOfSlices::get(unsigned int n)
{
  return static_cast<SedSlice*>(SedListOf::get(n));
}


/*
 * Get a SedSlice from the SedListOfSlices.
 */
const SedSlice*
SedListOfSlices::get(unsigned int n) const
{
  return static_cast<const SedSlice*>(SedListOf::get(n));
}


/*
 * Get a SedSlice from the SedListOfSlices based on its identifier.
 */
SedSlice*
SedListOfSlices::get(const std::string& sid)
{
  return const_cast<SedSlice*>(static_cast<const
    SedListOfSlices&>(*this).get(sid));
}


/*
 * Get a SedSlice from the SedListOfSlices based on its identifier.
 */
const SedSlice*
SedListOfSlices::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSlice>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSlice*>
    (*result);
}


/*
 * Removes the nth SedSlice from this SedListOfSlices and returns a pointer to
 * it.
 */
SedSlice*
SedListOfSlices::remove(unsigned int n)
{
  return static_cast<SedSlice*>(SedListOf::remove(n));
}


/*
 * Removes the SedSlice from this SedListOfSlices based on its identifier and
 * returns a pointer to it.
 */
SedSlice*
SedListOfSlices::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSlice>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedSlice*> (item);
}


/*
 * Adds a copy of the given SedSlice to this SedListOfSlices.
 */
int
SedListOfSlices::addSlice(const SedSlice* ss)
{
  if (ss == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ss->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ss->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ss->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ss)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(ss);
  }
}


/*
 * Get the number of SedSlice objects in this SedListOfSlices.
 */
unsigned int
SedListOfSlices::getNumSlices() const
{
  return size();
}


/*
 * Creates a new SedSlice object, adds it to this SedListOfSlices object and
 * returns the SedSlice object created.
 */
SedSlice*
SedListOfSlices::createSlice()
{
  SedSlice* ss = NULL;

  try
  {
    ss = new SedSlice(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ss != NULL)
  {
    appendAndOwn(ss);
  }

  return ss;
}


/*
 * Used by SedListOfSlices::get() to lookup a SedSlice based on its Reference.
 */
struct SedIdEqR
{
  const string& id;
   
  SedIdEqR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSlice*>(sb)->getReference() == id);
  }
};


/*
 * Get a SedSlice from the SedListOfSlices based on the Reference to which it
 * refers.
 */
const SedSlice*
SedListOfSlices::getByReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSlice*>
    (*result);
}


/*
 * Get a SedSlice from the SedListOfSlices based on the Reference to which it
 * refers.
 */
SedSlice*
SedListOfSlices::getByReference(const std::string& sid)
{
  return const_cast<SedSlice*>(static_cast<const
    SedListOfSlices&>(*this).getByReference(sid));
}


/*
 * Used by SedListOfSlices::get() to lookup a SedSlice based on its Index.
 */
struct SedIdEqI
{
  const string& id;
   
  SedIdEqI (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSlice*>(sb)->getIndex() == id);
  }
};


/*
 * Get a SedSlice from the SedListOfSlices based on the Index to which it
 * refers.
 */
const SedSlice*
SedListOfSlices::getByIndex(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqI(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSlice*>
    (*result);
}


/*
 * Get a SedSlice from the SedListOfSlices based on the Index to which it
 * refers.
 */
SedSlice*
SedListOfSlices::getByIndex(const std::string& sid)
{
  return const_cast<SedSlice*>(static_cast<const
    SedListOfSlices&>(*this).getByIndex(sid));
}


/*
 * Returns the XML element name of this SedListOfSlices object.
 */
const std::string&
SedListOfSlices::getElementName() const
{
  static const string name = "listOfSlices";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfSlices object.
 */
int
SedListOfSlices::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfSlices object.
 */
int
SedListOfSlices::getItemTypeCode() const
{
  return SEDML_DATA_SLICE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedSlice in this SedListOfSlices
 */
SedBase*
SedListOfSlices::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "slice")
  {
    object = new SedSlice(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedSlice_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedListOfSlices_getSlice(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSlices*>(slo)->get(n);
}


/*
 * Get a SedSlice_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedListOfSlices_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSlices*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedSlice_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedListOfSlices_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSlices*>(slo)->remove(n);
}


/*
 * Removes the SedSlice_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedSlice_t*
SedListOfSlices_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSlices*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


