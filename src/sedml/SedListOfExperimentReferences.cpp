/**
 * @file SedListOfExperimentReferences.cpp
 * @brief Implementation of the SedListOfExperimentReferences class.
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
#include <sedml/SedListOfExperimentReferences.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfExperimentReferences using the given SED-ML Level and @ p
 * version values.
 */
SedListOfExperimentReferences::SedListOfExperimentReferences(unsigned int level,
                                                 unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfExperimentReferences using the given SedNamespaces object
 * @p sedmlns.
 */
SedListOfExperimentReferences::SedListOfExperimentReferences(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfExperimentReferences.
 */
SedListOfExperimentReferences::SedListOfExperimentReferences(const SedListOfExperimentReferences&
  orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfExperimentReferences.
 */
SedListOfExperimentReferences&
SedListOfExperimentReferences::operator=(const SedListOfExperimentReferences& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfExperimentReferences object.
 */
SedListOfExperimentReferences*
SedListOfExperimentReferences::clone() const
{
  return new SedListOfExperimentReferences(*this);
}


/*
 * Destructor for SedListOfExperimentReferences.
 */
SedListOfExperimentReferences::~SedListOfExperimentReferences()
{
}


/*
 * Get a SedExperimentReference from the SedListOfExperimentReferences.
 */
SedExperimentReference*
SedListOfExperimentReferences::get(unsigned int n)
{
  return static_cast<SedExperimentReference*>(SedListOf::get(n));
}


/*
 * Get a SedExperimentReference from the SedListOfExperimentReferences.
 */
const SedExperimentReference*
SedListOfExperimentReferences::get(unsigned int n) const
{
  return static_cast<const SedExperimentReference*>(SedListOf::get(n));
}


/*
 * Get a SedExperimentReference from the SedListOfExperimentReferences based on its
 * identifier.
 */
SedExperimentReference*
SedListOfExperimentReferences::get(const std::string& sid)
{
  return const_cast<SedExperimentReference*>(static_cast<const
    SedListOfExperimentReferences&>(*this).get(sid));
}


/*
 * Get a SedExperimentReference from the SedListOfExperimentReferences based on its
 * identifier.
 */
const SedExperimentReference*
SedListOfExperimentReferences::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedExperimentReference>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedExperimentReference*>
    (*result);
}


/*
 * Removes the nth SedExperimentReference from this SedListOfExperimentReferences and
 * returns a pointer to it.
 */
SedExperimentReference*
SedListOfExperimentReferences::remove(unsigned int n)
{
  return static_cast<SedExperimentReference*>(SedListOf::remove(n));
}


/*
 * Removes the SedExperimentReference from this SedListOfExperimentReferences based on its
 * identifier and returns a pointer to it.
 */
SedExperimentReference*
SedListOfExperimentReferences::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedExperimentReference>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedExperimentReference*> (item);
}


/*
 * Adds a copy of the given SedExperimentReference to this SedListOfExperimentReferences.
 */
int
SedListOfExperimentReferences::addExperimentReference(const SedExperimentReference* ser)
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
 * Get the number of SedExperimentReference objects in this SedListOfExperimentReferences.
 */
unsigned int
SedListOfExperimentReferences::getNumExperimentReferences() const
{
  return size();
}


/*
 * Creates a new SedExperimentReference object, adds it to this
 * SedListOfExperimentReferences object and returns the SedExperimentReference object
 * created.
 */
SedExperimentReference*
SedListOfExperimentReferences::createExperimentReference()
{
  SedExperimentReference* ser = NULL;

  try
  {
    ser = new SedExperimentReference(getSedNamespaces());
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
 * Used by SedListOfExperimentReferences::get() to lookup a SedExperimentReference based on
 * its ExperimentId.
 */
struct SedIdEqEI
{
  const string& id;
   
  SedIdEqEI (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedExperimentReference*>(sb)->getExperimentId() == id);
  }
};


/*
 * Get a SedExperimentReference from the SedListOfExperimentReferences based on the
 * ExperimentId to which it refers.
 */
const SedExperimentReference*
SedListOfExperimentReferences::getByExperimentId(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqEI(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedExperimentReference*>
    (*result);
}


/*
 * Get a SedExperimentReference from the SedListOfExperimentReferences based on the
 * ExperimentId to which it refers.
 */
SedExperimentReference*
SedListOfExperimentReferences::getByExperimentId(const std::string& sid)
{
  return const_cast<SedExperimentReference*>(static_cast<const
    SedListOfExperimentReferences&>(*this).getByExperimentId(sid));
}


/*
 * Returns the XML element name of this SedListOfExperimentReferences object.
 */
const std::string&
SedListOfExperimentReferences::getElementName() const
{
  static const string name = "listOfExperimentReferences";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfExperimentReferences object.
 */
int
SedListOfExperimentReferences::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfExperimentReferences object.
 */
int
SedListOfExperimentReferences::getItemTypeCode() const
{
  return SEDML_EXPERIMENT_REFERENCE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedExperimentReference in this SedListOfExperimentReferences
 */
SedBase*
SedListOfExperimentReferences::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "experimentReference")
  {
    object = new SedExperimentReference(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedExperimentReference_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedListOfExperimentReferences_getExperimentReference(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfExperimentReferences*>(slo)->get(n);
}


/*
 * Get a SedExperimentReference_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedListOfExperimentReferences_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfExperimentReferences*>(slo)->get(sid)
    : NULL;
}


/*
 * Removes the nth SedExperimentReference_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedListOfExperimentReferences_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfExperimentReferences*>(slo)->remove(n);
}


/*
 * Removes the SedExperimentReference_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedListOfExperimentReferences_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfExperimentReferences*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


