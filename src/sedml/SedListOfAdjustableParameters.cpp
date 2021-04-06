/**
 * @file SedListOfAdjustableParameters.cpp
 * @brief Implementation of the SedListOfAdjustableParameters class.
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
#include <sedml/SedListOfAdjustableParameters.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfAdjustableParameters using the given SED-ML Level and
 * @ p version values.
 */
SedListOfAdjustableParameters::SedListOfAdjustableParameters(
                                                             unsigned int
                                                               level,
                                                             unsigned int
                                                               version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfAdjustableParameters using the given SedNamespaces
 * object @p sedmlns.
 */
SedListOfAdjustableParameters::SedListOfAdjustableParameters(SedNamespaces
  *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfAdjustableParameters.
 */
SedListOfAdjustableParameters::SedListOfAdjustableParameters(const
  SedListOfAdjustableParameters& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfAdjustableParameters.
 */
SedListOfAdjustableParameters&
SedListOfAdjustableParameters::operator=(const SedListOfAdjustableParameters&
  rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfAdjustableParameters
 * object.
 */
SedListOfAdjustableParameters*
SedListOfAdjustableParameters::clone() const
{
  return new SedListOfAdjustableParameters(*this);
}


/*
 * Destructor for SedListOfAdjustableParameters.
 */
SedListOfAdjustableParameters::~SedListOfAdjustableParameters()
{
}


/*
 * Get a SedAdjustableParameter from the SedListOfAdjustableParameters.
 */
SedAdjustableParameter*
SedListOfAdjustableParameters::get(unsigned int n)
{
  return static_cast<SedAdjustableParameter*>(SedListOf::get(n));
}


/*
 * Get a SedAdjustableParameter from the SedListOfAdjustableParameters.
 */
const SedAdjustableParameter*
SedListOfAdjustableParameters::get(unsigned int n) const
{
  return static_cast<const SedAdjustableParameter*>(SedListOf::get(n));
}


/*
 * Get a SedAdjustableParameter from the SedListOfAdjustableParameters based on
 * its identifier.
 */
SedAdjustableParameter*
SedListOfAdjustableParameters::get(const std::string& sid)
{
  return const_cast<SedAdjustableParameter*>(static_cast<const
    SedListOfAdjustableParameters&>(*this).get(sid));
}


/*
 * Get a SedAdjustableParameter from the SedListOfAdjustableParameters based on
 * its identifier.
 */
const SedAdjustableParameter*
SedListOfAdjustableParameters::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAdjustableParameter>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedAdjustableParameter*> (*result);
}


/*
 * Removes the nth SedAdjustableParameter from this
 * SedListOfAdjustableParameters and returns a pointer to it.
 */
SedAdjustableParameter*
SedListOfAdjustableParameters::remove(unsigned int n)
{
  return static_cast<SedAdjustableParameter*>(SedListOf::remove(n));
}


/*
 * Removes the SedAdjustableParameter from this SedListOfAdjustableParameters
 * based on its identifier and returns a pointer to it.
 */
SedAdjustableParameter*
SedListOfAdjustableParameters::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAdjustableParameter>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedAdjustableParameter*> (item);
}


/*
 * Adds a copy of the given SedAdjustableParameter to this
 * SedListOfAdjustableParameters.
 */
int
SedListOfAdjustableParameters::addAdjustableParameter(const
  SedAdjustableParameter* sap)
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
 * Get the number of SedAdjustableParameter objects in this
 * SedListOfAdjustableParameters.
 */
unsigned int
SedListOfAdjustableParameters::getNumAdjustableParameters() const
{
  return size();
}


/*
 * Creates a new SedAdjustableParameter object, adds it to this
 * SedListOfAdjustableParameters object and returns the SedAdjustableParameter
 * object created.
 */
SedAdjustableParameter*
SedListOfAdjustableParameters::createAdjustableParameter()
{
  SedAdjustableParameter* sap = NULL;

  try
  {
    sap = new SedAdjustableParameter(getSedNamespaces());
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
 * Used by SedListOfAdjustableParameters::get() to lookup a
 * SedAdjustableParameter based on its ModelReference.
 */
struct SedIdEqMR
{
  const string& id;
   
  SedIdEqMR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedAdjustableParameter*>(sb)->getModelReference() == id);
  }
};


/*
 * Get a SedAdjustableParameter from the SedListOfAdjustableParameters based on
 * the ModelReference to which it refers.
 */
const SedAdjustableParameter*
SedListOfAdjustableParameters::getByModelReference(const std::string& sid)
  const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqMR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const
    SedAdjustableParameter*> (*result);
}


/*
 * Get a SedAdjustableParameter from the SedListOfAdjustableParameters based on
 * the ModelReference to which it refers.
 */
SedAdjustableParameter*
SedListOfAdjustableParameters::getByModelReference(const std::string& sid)
{
  return const_cast<SedAdjustableParameter*>(static_cast<const
    SedListOfAdjustableParameters&>(*this).getByModelReference(sid));
}


/*
 * Returns the XML element name of this SedListOfAdjustableParameters object.
 */
const std::string&
SedListOfAdjustableParameters::getElementName() const
{
  static const string name = "listOfAdjustableParameters";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfAdjustableParameters
 * object.
 */
int
SedListOfAdjustableParameters::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfAdjustableParameters object.
 */
int
SedListOfAdjustableParameters::getItemTypeCode() const
{
  return SEDML_ADJUSTABLE_PARAMETER;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedAdjustableParameter in this SedListOfAdjustableParameters
 */
SedBase*
SedListOfAdjustableParameters::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "adjustableParameter")
  {
    object = new SedAdjustableParameter(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedAdjustableParameter_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedListOfAdjustableParameters_getAdjustableParameter(SedListOf_t* slo,
                                                     unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfAdjustableParameters*>(slo)->get(n);
}


/*
 * Get a SedAdjustableParameter_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedListOfAdjustableParameters_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfAdjustableParameters*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedAdjustableParameter_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedListOfAdjustableParameters_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfAdjustableParameters*>(slo)->remove(n);
}


/*
 * Removes the SedAdjustableParameter_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedListOfAdjustableParameters_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfAdjustableParameters*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


