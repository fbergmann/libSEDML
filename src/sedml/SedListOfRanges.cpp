/**
 * @file SedListOfRanges.cpp
 * @brief Implementation of the SedListOfRanges class.
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
#include <sedml/SedListOfRanges.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedUniformRange.h>
#include <sedml/SedVectorRange.h>
#include <sedml/SedFunctionalRange.h>
#include <sedml/SedDataRange.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfRanges using the given SED-ML Level and @ p version
 * values.
 */
SedListOfRanges::SedListOfRanges(unsigned int level, unsigned int version)
  : SedListOf(level, version)
  , mElementName("listOfRanges")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfRanges using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfRanges::SedListOfRanges(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
  , mElementName("listOfRanges")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfRanges.
 */
SedListOfRanges::SedListOfRanges(const SedListOfRanges& orig)
  : SedListOf( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedListOfRanges.
 */
SedListOfRanges&
SedListOfRanges::operator=(const SedListOfRanges& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfRanges object.
 */
SedListOfRanges*
SedListOfRanges::clone() const
{
  return new SedListOfRanges(*this);
}


/*
 * Destructor for SedListOfRanges.
 */
SedListOfRanges::~SedListOfRanges()
{
}


/*
 * Get a SedRange from the SedListOfRanges.
 */
SedRange*
SedListOfRanges::get(unsigned int n)
{
  return static_cast<SedRange*>(SedListOf::get(n));
}


/*
 * Get a SedRange from the SedListOfRanges.
 */
const SedRange*
SedListOfRanges::get(unsigned int n) const
{
  return static_cast<const SedRange*>(SedListOf::get(n));
}


/*
 * Get a SedRange from the SedListOfRanges based on its identifier.
 */
SedRange*
SedListOfRanges::get(const std::string& sid)
{
  return const_cast<SedRange*>(static_cast<const
    SedListOfRanges&>(*this).get(sid));
}


/*
 * Get a SedRange from the SedListOfRanges based on its identifier.
 */
const SedRange*
SedListOfRanges::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedRange>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedRange*>
    (*result);
}


/*
 * Removes the nth SedRange from this SedListOfRanges and returns a pointer to
 * it.
 */
SedRange*
SedListOfRanges::remove(unsigned int n)
{
  return static_cast<SedRange*>(SedListOf::remove(n));
}


/*
 * Removes the SedRange from this SedListOfRanges based on its identifier and
 * returns a pointer to it.
 */
SedRange*
SedListOfRanges::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedRange>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedRange*> (item);
}


/*
 * Adds a copy of the given SedRange to this SedListOfRanges.
 */
int
SedListOfRanges::addRange(const SedRange* sr)
{
  if (sr == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sr->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sr->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sr->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sr)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sr);
  }
}


/*
 * Get the number of SedRange objects in this SedListOfRanges.
 */
unsigned int
SedListOfRanges::getNumRanges() const
{
  return size();
}


/*
 * Creates a new SedUniformRange object, adds it to this SedListOfRanges object
 * and returns the SedUniformRange object created.
 */
SedUniformRange*
SedListOfRanges::createUniformRange()
{
  SedUniformRange* sur = NULL;

  try
  {
    sur = new SedUniformRange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sur != NULL)
  {
    appendAndOwn(sur);
  }

  return sur;
}


/*
 * Creates a new SedVectorRange object, adds it to this SedListOfRanges object
 * and returns the SedVectorRange object created.
 */
SedVectorRange*
SedListOfRanges::createVectorRange()
{
  SedVectorRange* svr = NULL;

  try
  {
    svr = new SedVectorRange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (svr != NULL)
  {
    appendAndOwn(svr);
  }

  return svr;
}


/*
 * Creates a new SedFunctionalRange object, adds it to this SedListOfRanges
 * object and returns the SedFunctionalRange object created.
 */
SedFunctionalRange*
SedListOfRanges::createFunctionalRange()
{
  SedFunctionalRange* sfr = NULL;

  try
  {
    sfr = new SedFunctionalRange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sfr != NULL)
  {
    appendAndOwn(sfr);
  }

  return sfr;
}


/*
 * Creates a new SedDataRange object, adds it to this SedListOfRanges object
 * and returns the SedDataRange object created.
 */
SedDataRange*
SedListOfRanges::createDataRange()
{
  SedDataRange* sdr = NULL;

  try
  {
    sdr = new SedDataRange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sdr != NULL)
  {
    appendAndOwn(sdr);
  }

  return sdr;
}


/*
 * Returns the XML element name of this SedListOfRanges object.
 */
const std::string&
SedListOfRanges::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedListOfRanges object.
 */
void
SedListOfRanges::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedListOfRanges object.
 */
int
SedListOfRanges::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfRanges object.
 */
int
SedListOfRanges::getItemTypeCode() const
{
  return SEDML_RANGE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedRange in this SedListOfRanges
 */
SedBase*
SedListOfRanges::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "range")
  {
    object = new SedRange(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "uniformRange")
  {
    object = new SedUniformRange(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "vectorRange")
  {
    object = new SedVectorRange(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "functionalRange")
  {
    object = new SedFunctionalRange(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "dataRange")
  {
    object = new SedDataRange(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * checks concrete types
 */
bool
SedListOfRanges::isValidTypeForList(SedBase* item)
{
  unsigned int tc = item->getTypeCode();

  return ((tc == SEDML_RANGE_UNIFORMRANGE) || (tc == SEDML_RANGE_VECTORRANGE)
    || (tc == SEDML_RANGE_FUNCTIONALRANGE) || (tc == SEDML_DATA_RANGE));
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedRange_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedRange_t*
SedListOfRanges_getRange(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfRanges*>(slo)->get(n);
}


/*
 * Get a SedRange_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedRange_t*
SedListOfRanges_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfRanges*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedRange_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedRange_t*
SedListOfRanges_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfRanges*>(slo)->remove(n);
}


/*
 * Removes the SedRange_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedRange_t*
SedListOfRanges_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfRanges*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


