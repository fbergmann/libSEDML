/**
 * @file SedListOfDataGenerators.cpp
 * @brief Implementation of the SedListOfDataGenerators class.
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
#include <sedml/SedListOfDataGenerators.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfDataGenerators using the given SED-ML Level and @ p
 * version values.
 */
SedListOfDataGenerators::SedListOfDataGenerators(unsigned int level,
                                                 unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfDataGenerators using the given SedNamespaces object
 * @p sedmlns.
 */
SedListOfDataGenerators::SedListOfDataGenerators(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfDataGenerators.
 */
SedListOfDataGenerators::SedListOfDataGenerators(const SedListOfDataGenerators&
  orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfDataGenerators.
 */
SedListOfDataGenerators&
SedListOfDataGenerators::operator=(const SedListOfDataGenerators& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfDataGenerators object.
 */
SedListOfDataGenerators*
SedListOfDataGenerators::clone() const
{
  return new SedListOfDataGenerators(*this);
}


/*
 * Destructor for SedListOfDataGenerators.
 */
SedListOfDataGenerators::~SedListOfDataGenerators()
{
}


/*
 * Get a SedDataGenerator from the SedListOfDataGenerators.
 */
SedDataGenerator*
SedListOfDataGenerators::get(unsigned int n)
{
  return static_cast<SedDataGenerator*>(SedListOf::get(n));
}


/*
 * Get a SedDataGenerator from the SedListOfDataGenerators.
 */
const SedDataGenerator*
SedListOfDataGenerators::get(unsigned int n) const
{
  return static_cast<const SedDataGenerator*>(SedListOf::get(n));
}


/*
 * Get a SedDataGenerator from the SedListOfDataGenerators based on its
 * identifier.
 */
SedDataGenerator*
SedListOfDataGenerators::get(const std::string& sid)
{
  return const_cast<SedDataGenerator*>(static_cast<const
    SedListOfDataGenerators&>(*this).get(sid));
}


/*
 * Get a SedDataGenerator from the SedListOfDataGenerators based on its
 * identifier.
 */
const SedDataGenerator*
SedListOfDataGenerators::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedDataGenerator>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedDataGenerator*>
    (*result);
}


/*
 * Removes the nth SedDataGenerator from this SedListOfDataGenerators and
 * returns a pointer to it.
 */
SedDataGenerator*
SedListOfDataGenerators::remove(unsigned int n)
{
  return static_cast<SedDataGenerator*>(SedListOf::remove(n));
}


/*
 * Removes the SedDataGenerator from this SedListOfDataGenerators based on its
 * identifier and returns a pointer to it.
 */
SedDataGenerator*
SedListOfDataGenerators::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedDataGenerator>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedDataGenerator*> (item);
}


/*
 * Adds a copy of the given SedDataGenerator to this SedListOfDataGenerators.
 */
int
SedListOfDataGenerators::addDataGenerator(const SedDataGenerator* sdg)
{
  if (sdg == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sdg->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (sdg->hasRequiredElements() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sdg->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sdg->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sdg)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sdg);
  }
}


/*
 * Get the number of SedDataGenerator objects in this SedListOfDataGenerators.
 */
unsigned int
SedListOfDataGenerators::getNumDataGenerators() const
{
  return size();
}


/*
 * Creates a new SedDataGenerator object, adds it to this
 * SedListOfDataGenerators object and returns the SedDataGenerator object
 * created.
 */
SedDataGenerator*
SedListOfDataGenerators::createDataGenerator()
{
  SedDataGenerator* sdg = NULL;

  try
  {
    sdg = new SedDataGenerator(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sdg != NULL)
  {
    appendAndOwn(sdg);
  }

  return sdg;
}


/*
 * Returns the XML element name of this SedListOfDataGenerators object.
 */
const std::string&
SedListOfDataGenerators::getElementName() const
{
  static const string name = "listOfDataGenerators";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfDataGenerators object.
 */
int
SedListOfDataGenerators::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfDataGenerators object.
 */
int
SedListOfDataGenerators::getItemTypeCode() const
{
  return SEDML_DATAGENERATOR;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedDataGenerator in this SedListOfDataGenerators
 */
SedBase*
SedListOfDataGenerators::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "dataGenerator")
  {
    object = new SedDataGenerator(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedDataGenerator_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedListOfDataGenerators_getDataGenerator(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfDataGenerators*>(slo)->get(n);
}


/*
 * Get a SedDataGenerator_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedListOfDataGenerators_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfDataGenerators*>(slo)->get(sid)
    : NULL;
}


/*
 * Removes the nth SedDataGenerator_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedListOfDataGenerators_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfDataGenerators*>(slo)->remove(n);
}


/*
 * Removes the SedDataGenerator_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedListOfDataGenerators_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfDataGenerators*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


