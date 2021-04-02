/**
 * @file SedListOfAlgorithmParameters.cpp
 * @brief Implementation of the SedListOfAlgorithmParameters class.
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
#include <sedml/SedListOfAlgorithmParameters.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfAlgorithmParameters using the given SED-ML Level and @
 * p version values.
 */
SedListOfAlgorithmParameters::SedListOfAlgorithmParameters(unsigned int level,
                                                           unsigned int
                                                             version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfAlgorithmParameters using the given SedNamespaces
 * object @p sedmlns.
 */
SedListOfAlgorithmParameters::SedListOfAlgorithmParameters(SedNamespaces
  *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfAlgorithmParameters.
 */
SedListOfAlgorithmParameters::SedListOfAlgorithmParameters(const
  SedListOfAlgorithmParameters& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfAlgorithmParameters.
 */
SedListOfAlgorithmParameters&
SedListOfAlgorithmParameters::operator=(const SedListOfAlgorithmParameters&
  rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfAlgorithmParameters object.
 */
SedListOfAlgorithmParameters*
SedListOfAlgorithmParameters::clone() const
{
  return new SedListOfAlgorithmParameters(*this);
}


/*
 * Destructor for SedListOfAlgorithmParameters.
 */
SedListOfAlgorithmParameters::~SedListOfAlgorithmParameters()
{
}


/*
 * Get a SedAlgorithmParameter from the SedListOfAlgorithmParameters.
 */
SedAlgorithmParameter*
SedListOfAlgorithmParameters::get(unsigned int n)
{
  return static_cast<SedAlgorithmParameter*>(SedListOf::get(n));
}


/*
 * Get a SedAlgorithmParameter from the SedListOfAlgorithmParameters.
 */
const SedAlgorithmParameter*
SedListOfAlgorithmParameters::get(unsigned int n) const
{
  return static_cast<const SedAlgorithmParameter*>(SedListOf::get(n));
}


/*
 * Get a SedAlgorithmParameter from the SedListOfAlgorithmParameters based on
 * its identifier.
 */
SedAlgorithmParameter*
SedListOfAlgorithmParameters::get(const std::string& sid)
{
  return const_cast<SedAlgorithmParameter*>(static_cast<const
    SedListOfAlgorithmParameters&>(*this).get(sid));
}


/*
 * Get a SedAlgorithmParameter from the SedListOfAlgorithmParameters based on
 * its identifier.
 */
const SedAlgorithmParameter*
SedListOfAlgorithmParameters::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAlgorithmParameter>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedAlgorithmParameter*> (*result);
}


/*
 * Removes the nth SedAlgorithmParameter from this SedListOfAlgorithmParameters
 * and returns a pointer to it.
 */
SedAlgorithmParameter*
SedListOfAlgorithmParameters::remove(unsigned int n)
{
  return static_cast<SedAlgorithmParameter*>(SedListOf::remove(n));
}


/*
 * Removes the SedAlgorithmParameter from this SedListOfAlgorithmParameters
 * based on its identifier and returns a pointer to it.
 */
SedAlgorithmParameter*
SedListOfAlgorithmParameters::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAlgorithmParameter>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedAlgorithmParameter*> (item);
}


/*
 * Adds a copy of the given SedAlgorithmParameter to this
 * SedListOfAlgorithmParameters.
 */
int
SedListOfAlgorithmParameters::addAlgorithmParameter(const
  SedAlgorithmParameter* sap)
{
  if (sap == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sap->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sap->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sap->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sap)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sap);
  }
}


/*
 * Get the number of SedAlgorithmParameter objects in this
 * SedListOfAlgorithmParameters.
 */
unsigned int
SedListOfAlgorithmParameters::getNumAlgorithmParameters() const
{
  return size();
}


/*
 * Creates a new SedAlgorithmParameter object, adds it to this
 * SedListOfAlgorithmParameters object and returns the SedAlgorithmParameter
 * object created.
 */
SedAlgorithmParameter*
SedListOfAlgorithmParameters::createAlgorithmParameter()
{
  SedAlgorithmParameter* sap = NULL;

  try
  {
    sap = new SedAlgorithmParameter(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sap != NULL)
  {
    appendAndOwn(sap);
  }

  return sap;
}


/*
 * Returns the XML element name of this SedListOfAlgorithmParameters object.
 */
const std::string&
SedListOfAlgorithmParameters::getElementName() const
{
  static const string name = "listOfAlgorithmParameters";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfAlgorithmParameters object.
 */
int
SedListOfAlgorithmParameters::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfAlgorithmParameters object.
 */
int
SedListOfAlgorithmParameters::getItemTypeCode() const
{
  return SEDML_SIMULATION_ALGORITHM_PARAMETER;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedAlgorithmParameter in this SedListOfAlgorithmParameters
 */
SedBase*
SedListOfAlgorithmParameters::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "algorithmParameter")
  {
    object = new SedAlgorithmParameter(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedAlgorithmParameter_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedListOfAlgorithmParameters_getAlgorithmParameter(SedListOf_t* slo,
                                                   unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfAlgorithmParameters*>(slo)->get(n);
}


/*
 * Get a SedAlgorithmParameter_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedListOfAlgorithmParameters_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfAlgorithmParameters*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedAlgorithmParameter_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedListOfAlgorithmParameters_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfAlgorithmParameters*>(slo)->remove(n);
}


/*
 * Removes the SedAlgorithmParameter_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedListOfAlgorithmParameters_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfAlgorithmParameters*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


