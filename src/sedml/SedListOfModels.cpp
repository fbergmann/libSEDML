/**
 * @file SedListOfModels.cpp
 * @brief Implementation of the SedListOfModels class.
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
#include <sedml/SedListOfModels.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfModels using the given SED-ML Level and @ p version
 * values.
 */
SedListOfModels::SedListOfModels(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfModels using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfModels::SedListOfModels(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfModels.
 */
SedListOfModels::SedListOfModels(const SedListOfModels& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfModels.
 */
SedListOfModels&
SedListOfModels::operator=(const SedListOfModels& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfModels object.
 */
SedListOfModels*
SedListOfModels::clone() const
{
  return new SedListOfModels(*this);
}


/*
 * Destructor for SedListOfModels.
 */
SedListOfModels::~SedListOfModels()
{
}


/*
 * Get a SedModel from the SedListOfModels.
 */
SedModel*
SedListOfModels::get(unsigned int n)
{
  return static_cast<SedModel*>(SedListOf::get(n));
}


/*
 * Get a SedModel from the SedListOfModels.
 */
const SedModel*
SedListOfModels::get(unsigned int n) const
{
  return static_cast<const SedModel*>(SedListOf::get(n));
}


/*
 * Get a SedModel from the SedListOfModels based on its identifier.
 */
SedModel*
SedListOfModels::get(const std::string& sid)
{
  return const_cast<SedModel*>(static_cast<const
    SedListOfModels&>(*this).get(sid));
}


/*
 * Get a SedModel from the SedListOfModels based on its identifier.
 */
const SedModel*
SedListOfModels::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedModel>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedModel*>
    (*result);
}


/*
 * Removes the nth SedModel from this SedListOfModels and returns a pointer to
 * it.
 */
SedModel*
SedListOfModels::remove(unsigned int n)
{
  return static_cast<SedModel*>(SedListOf::remove(n));
}


/*
 * Removes the SedModel from this SedListOfModels based on its identifier and
 * returns a pointer to it.
 */
SedModel*
SedListOfModels::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedModel>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedModel*> (item);
}


/*
 * Adds a copy of the given SedModel to this SedListOfModels.
 */
int
SedListOfModels::addModel(const SedModel* sm)
{
  if (sm == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sm->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sm->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sm->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sm)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sm);
  }
}


/*
 * Get the number of SedModel objects in this SedListOfModels.
 */
unsigned int
SedListOfModels::getNumModels() const
{
  return size();
}


/*
 * Creates a new SedModel object, adds it to this SedListOfModels object and
 * returns the SedModel object created.
 */
SedModel*
SedListOfModels::createModel()
{
  SedModel* sm = NULL;

  try
  {
    sm = new SedModel(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sm != NULL)
  {
    appendAndOwn(sm);
  }

  return sm;
}


/*
 * Returns the XML element name of this SedListOfModels object.
 */
const std::string&
SedListOfModels::getElementName() const
{
  static const string name = "listOfModels";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfModels object.
 */
int
SedListOfModels::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfModels object.
 */
int
SedListOfModels::getItemTypeCode() const
{
  return SEDML_MODEL;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedModel in this SedListOfModels
 */
SedBase*
SedListOfModels::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "model")
  {
    object = new SedModel(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedModel_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedModel_t*
SedListOfModels_getModel(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfModels*>(slo)->get(n);
}


/*
 * Get a SedModel_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedModel_t*
SedListOfModels_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfModels*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedModel_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedModel_t*
SedListOfModels_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfModels*>(slo)->remove(n);
}


/*
 * Removes the SedModel_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedModel_t*
SedListOfModels_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfModels*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


