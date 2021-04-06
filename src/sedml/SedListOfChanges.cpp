/**
 * @file SedListOfChanges.cpp
 * @brief Implementation of the SedListOfChanges class.
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
#include <sedml/SedListOfChanges.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedAddXML.h>
#include <sedml/SedChangeXML.h>
#include <sedml/SedRemoveXML.h>
#include <sedml/SedChangeAttribute.h>
#include <sedml/SedComputeChange.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfChanges using the given SED-ML Level and @ p version
 * values.
 */
SedListOfChanges::SedListOfChanges(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfChanges using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfChanges::SedListOfChanges(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfChanges.
 */
SedListOfChanges::SedListOfChanges(const SedListOfChanges& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfChanges.
 */
SedListOfChanges&
SedListOfChanges::operator=(const SedListOfChanges& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfChanges object.
 */
SedListOfChanges*
SedListOfChanges::clone() const
{
  return new SedListOfChanges(*this);
}


/*
 * Destructor for SedListOfChanges.
 */
SedListOfChanges::~SedListOfChanges()
{
}


/*
 * Get a SedChange from the SedListOfChanges.
 */
SedChange*
SedListOfChanges::get(unsigned int n)
{
  return static_cast<SedChange*>(SedListOf::get(n));
}


/*
 * Get a SedChange from the SedListOfChanges.
 */
const SedChange*
SedListOfChanges::get(unsigned int n) const
{
  return static_cast<const SedChange*>(SedListOf::get(n));
}


/*
 * Get a SedChange from the SedListOfChanges based on its identifier.
 */
SedChange*
SedListOfChanges::get(const std::string& sid)
{
  return const_cast<SedChange*>(static_cast<const
    SedListOfChanges&>(*this).get(sid));
}


/*
 * Get a SedChange from the SedListOfChanges based on its identifier.
 */
const SedChange*
SedListOfChanges::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedChange>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedChange*>
    (*result);
}


/*
 * Removes the nth SedChange from this SedListOfChanges and returns a pointer
 * to it.
 */
SedChange*
SedListOfChanges::remove(unsigned int n)
{
  return static_cast<SedChange*>(SedListOf::remove(n));
}


/*
 * Removes the SedChange from this SedListOfChanges based on its identifier and
 * returns a pointer to it.
 */
SedChange*
SedListOfChanges::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedChange>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedChange*> (item);
}


/*
 * Adds a copy of the given SedChange to this SedListOfChanges.
 */
int
SedListOfChanges::addChange(const SedChange* sc)
{
  if (sc == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sc->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sc->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sc->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sc)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sc);
  }
}


/*
 * Get the number of SedChange objects in this SedListOfChanges.
 */
unsigned int
SedListOfChanges::getNumChanges() const
{
  return size();
}


/*
 * Creates a new SedAddXML object, adds it to this SedListOfChanges object and
 * returns the SedAddXML object created.
 */
SedAddXML*
SedListOfChanges::createAddXML()
{
  SedAddXML* saxml = NULL;

  try
  {
    saxml = new SedAddXML(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (saxml != NULL)
  {
    appendAndOwn(saxml);
  }

  return saxml;
}


/*
 * Creates a new SedChangeXML object, adds it to this SedListOfChanges object
 * and returns the SedChangeXML object created.
 */
SedChangeXML*
SedListOfChanges::createChangeXML()
{
  SedChangeXML* scxml = NULL;

  try
  {
    scxml = new SedChangeXML(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (scxml != NULL)
  {
    appendAndOwn(scxml);
  }

  return scxml;
}


/*
 * Creates a new SedRemoveXML object, adds it to this SedListOfChanges object
 * and returns the SedRemoveXML object created.
 */
SedRemoveXML*
SedListOfChanges::createRemoveXML()
{
  SedRemoveXML* srxml = NULL;

  try
  {
    srxml = new SedRemoveXML(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (srxml != NULL)
  {
    appendAndOwn(srxml);
  }

  return srxml;
}


/*
 * Creates a new SedChangeAttribute object, adds it to this SedListOfChanges
 * object and returns the SedChangeAttribute object created.
 */
SedChangeAttribute*
SedListOfChanges::createChangeAttribute()
{
  SedChangeAttribute* sca = NULL;

  try
  {
    sca = new SedChangeAttribute(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sca != NULL)
  {
    appendAndOwn(sca);
  }

  return sca;
}


/*
 * Creates a new SedComputeChange object, adds it to this SedListOfChanges
 * object and returns the SedComputeChange object created.
 */
SedComputeChange*
SedListOfChanges::createComputeChange()
{
  SedComputeChange* scc = NULL;

  try
  {
    scc = new SedComputeChange(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (scc != NULL)
  {
    appendAndOwn(scc);
  }

  return scc;
}


/*
 * Returns the XML element name of this SedListOfChanges object.
 */
const std::string&
SedListOfChanges::getElementName() const
{
  static const string name = "listOfChanges";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfChanges object.
 */
int
SedListOfChanges::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfChanges object.
 */
int
SedListOfChanges::getItemTypeCode() const
{
  return SEDML_CHANGE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedChange in this SedListOfChanges
 */
SedBase*
SedListOfChanges::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "change")
  {
    object = new SedChange(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "addXML")
  {
    object = new SedAddXML(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "changeXML")
  {
    object = new SedChangeXML(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "removeXML")
  {
    object = new SedRemoveXML(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "changeAttribute")
  {
    object = new SedChangeAttribute(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "computeChange")
  {
    object = new SedComputeChange(getSedNamespaces());
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
SedListOfChanges::isValidTypeForList(SedBase* item)
{
  unsigned int tc = item->getTypeCode();

  return ((tc == SEDML_CHANGE_ADDXML) || (tc == SEDML_CHANGE_CHANGEXML) || (tc
    == SEDML_CHANGE_REMOVEXML) || (tc == SEDML_CHANGE_ATTRIBUTE) || (tc ==
      SEDML_CHANGE_COMPUTECHANGE));
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedChange_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedChange_t*
SedListOfChanges_getChange(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfChanges*>(slo)->get(n);
}


/*
 * Get a SedChange_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedChange_t*
SedListOfChanges_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfChanges*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedChange_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedChange_t*
SedListOfChanges_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfChanges*>(slo)->remove(n);
}


/*
 * Removes the SedChange_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedChange_t*
SedListOfChanges_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfChanges*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


