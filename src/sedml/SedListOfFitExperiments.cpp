/**
 * @file SedListOfFitExperiments.cpp
 * @brief Implementation of the SedListOfFitExperiments class.
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
#include <sedml/SedListOfFitExperiments.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfFitExperiments using the given SED-ML Level and @ p
 * version values.
 */
SedListOfFitExperiments::SedListOfFitExperiments(unsigned int level,
                                                 unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfFitExperiments using the given SedNamespaces object
 * @p sedmlns.
 */
SedListOfFitExperiments::SedListOfFitExperiments(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfFitExperiments.
 */
SedListOfFitExperiments::SedListOfFitExperiments(const SedListOfFitExperiments&
  orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfFitExperiments.
 */
SedListOfFitExperiments&
SedListOfFitExperiments::operator=(const SedListOfFitExperiments& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfFitExperiments object.
 */
SedListOfFitExperiments*
SedListOfFitExperiments::clone() const
{
  return new SedListOfFitExperiments(*this);
}


/*
 * Destructor for SedListOfFitExperiments.
 */
SedListOfFitExperiments::~SedListOfFitExperiments()
{
}


/*
 * Get a SedFitExperiment from the SedListOfFitExperiments.
 */
SedFitExperiment*
SedListOfFitExperiments::get(unsigned int n)
{
  return static_cast<SedFitExperiment*>(SedListOf::get(n));
}


/*
 * Get a SedFitExperiment from the SedListOfFitExperiments.
 */
const SedFitExperiment*
SedListOfFitExperiments::get(unsigned int n) const
{
  return static_cast<const SedFitExperiment*>(SedListOf::get(n));
}


/*
 * Get a SedFitExperiment from the SedListOfFitExperiments based on its
 * identifier.
 */
SedFitExperiment*
SedListOfFitExperiments::get(const std::string& sid)
{
  return const_cast<SedFitExperiment*>(static_cast<const
    SedListOfFitExperiments&>(*this).get(sid));
}


/*
 * Get a SedFitExperiment from the SedListOfFitExperiments based on its
 * identifier.
 */
const SedFitExperiment*
SedListOfFitExperiments::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedFitExperiment>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedFitExperiment*>
    (*result);
}


/*
 * Removes the nth SedFitExperiment from this SedListOfFitExperiments and
 * returns a pointer to it.
 */
SedFitExperiment*
SedListOfFitExperiments::remove(unsigned int n)
{
  return static_cast<SedFitExperiment*>(SedListOf::remove(n));
}


/*
 * Removes the SedFitExperiment from this SedListOfFitExperiments based on its
 * identifier and returns a pointer to it.
 */
SedFitExperiment*
SedListOfFitExperiments::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedFitExperiment>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedFitExperiment*> (item);
}


/*
 * Adds a copy of the given SedFitExperiment to this SedListOfFitExperiments.
 */
int
SedListOfFitExperiments::addFitExperiment(const SedFitExperiment* sfe)
{
  if (sfe == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sfe->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sfe->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sfe->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sfe)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sfe);
  }
}


/*
 * Get the number of SedFitExperiment objects in this SedListOfFitExperiments.
 */
unsigned int
SedListOfFitExperiments::getNumFitExperiments() const
{
  return size();
}


/*
 * Creates a new SedFitExperiment object, adds it to this
 * SedListOfFitExperiments object and returns the SedFitExperiment object
 * created.
 */
SedFitExperiment*
SedListOfFitExperiments::createFitExperiment()
{
  SedFitExperiment* sfe = NULL;

  try
  {
    sfe = new SedFitExperiment(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sfe != NULL)
  {
    appendAndOwn(sfe);
  }

  return sfe;
}


/*
 * Returns the XML element name of this SedListOfFitExperiments object.
 */
const std::string&
SedListOfFitExperiments::getElementName() const
{
  static const string name = "listOfFitExperiments";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfFitExperiments object.
 */
int
SedListOfFitExperiments::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfFitExperiments object.
 */
int
SedListOfFitExperiments::getItemTypeCode() const
{
  return SEDML_FIT_EXPERIMENT;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedFitExperiment in this SedListOfFitExperiments
 */
SedBase*
SedListOfFitExperiments::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "fitExperiment")
  {
    object = new SedFitExperiment(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedFitExperiment_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedListOfFitExperiments_getFitExperiment(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfFitExperiments*>(slo)->get(n);
}


/*
 * Get a SedFitExperiment_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedListOfFitExperiments_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfFitExperiments*>(slo)->get(sid)
    : NULL;
}


/*
 * Removes the nth SedFitExperiment_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedListOfFitExperiments_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfFitExperiments*>(slo)->remove(n);
}


/*
 * Removes the SedFitExperiment_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedListOfFitExperiments_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfFitExperiments*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


