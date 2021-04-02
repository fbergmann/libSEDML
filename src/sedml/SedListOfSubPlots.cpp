/**
 * @file SedListOfSubPlots.cpp
 * @brief Implementation of the SedListOfSubPlots class.
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
#include <sedml/SedListOfSubPlots.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfSubPlots using the given SED-ML Level and @ p version
 * values.
 */
SedListOfSubPlots::SedListOfSubPlots(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfSubPlots using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfSubPlots::SedListOfSubPlots(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfSubPlots.
 */
SedListOfSubPlots::SedListOfSubPlots(const SedListOfSubPlots& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfSubPlots.
 */
SedListOfSubPlots&
SedListOfSubPlots::operator=(const SedListOfSubPlots& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfSubPlots object.
 */
SedListOfSubPlots*
SedListOfSubPlots::clone() const
{
  return new SedListOfSubPlots(*this);
}


/*
 * Destructor for SedListOfSubPlots.
 */
SedListOfSubPlots::~SedListOfSubPlots()
{
}


/*
 * Get a SedSubPlot from the SedListOfSubPlots.
 */
SedSubPlot*
SedListOfSubPlots::get(unsigned int n)
{
  return static_cast<SedSubPlot*>(SedListOf::get(n));
}


/*
 * Get a SedSubPlot from the SedListOfSubPlots.
 */
const SedSubPlot*
SedListOfSubPlots::get(unsigned int n) const
{
  return static_cast<const SedSubPlot*>(SedListOf::get(n));
}


/*
 * Get a SedSubPlot from the SedListOfSubPlots based on its identifier.
 */
SedSubPlot*
SedListOfSubPlots::get(const std::string& sid)
{
  return const_cast<SedSubPlot*>(static_cast<const
    SedListOfSubPlots&>(*this).get(sid));
}


/*
 * Get a SedSubPlot from the SedListOfSubPlots based on its identifier.
 */
const SedSubPlot*
SedListOfSubPlots::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSubPlot>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSubPlot*>
    (*result);
}


/*
 * Removes the nth SedSubPlot from this SedListOfSubPlots and returns a pointer
 * to it.
 */
SedSubPlot*
SedListOfSubPlots::remove(unsigned int n)
{
  return static_cast<SedSubPlot*>(SedListOf::remove(n));
}


/*
 * Removes the SedSubPlot from this SedListOfSubPlots based on its identifier
 * and returns a pointer to it.
 */
SedSubPlot*
SedListOfSubPlots::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSubPlot>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedSubPlot*> (item);
}


/*
 * Adds a copy of the given SedSubPlot to this SedListOfSubPlots.
 */
int
SedListOfSubPlots::addSubPlot(const SedSubPlot* ssp)
{
  if (ssp == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ssp->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ssp->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ssp->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ssp)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(ssp);
  }
}


/*
 * Get the number of SedSubPlot objects in this SedListOfSubPlots.
 */
unsigned int
SedListOfSubPlots::getNumSubPlots() const
{
  return size();
}


/*
 * Creates a new SedSubPlot object, adds it to this SedListOfSubPlots object
 * and returns the SedSubPlot object created.
 */
SedSubPlot*
SedListOfSubPlots::createSubPlot()
{
  SedSubPlot* ssp = NULL;

  try
  {
    ssp = new SedSubPlot(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ssp != NULL)
  {
    appendAndOwn(ssp);
  }

  return ssp;
}


/*
 * Used by SedListOfSubPlots::get() to lookup a SedSubPlot based on its Plot.
 */
struct SedIdEqP
{
  const string& id;
   
  SedIdEqP (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSubPlot*>(sb)->getPlot() == id);
  }
};


/*
 * Get a SedSubPlot from the SedListOfSubPlots based on the Plot to which it
 * refers.
 */
const SedSubPlot*
SedListOfSubPlots::getByPlot(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqP(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSubPlot*>
    (*result);
}


/*
 * Get a SedSubPlot from the SedListOfSubPlots based on the Plot to which it
 * refers.
 */
SedSubPlot*
SedListOfSubPlots::getByPlot(const std::string& sid)
{
  return const_cast<SedSubPlot*>(static_cast<const
    SedListOfSubPlots&>(*this).getByPlot(sid));
}


/*
 * Returns the XML element name of this SedListOfSubPlots object.
 */
const std::string&
SedListOfSubPlots::getElementName() const
{
  static const string name = "listOfSubPlots";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfSubPlots object.
 */
int
SedListOfSubPlots::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfSubPlots object.
 */
int
SedListOfSubPlots::getItemTypeCode() const
{
  return SEDML_SUBPLOT;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedSubPlot in this SedListOfSubPlots
 */
SedBase*
SedListOfSubPlots::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "subPlot")
  {
    object = new SedSubPlot(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedSubPlot_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedListOfSubPlots_getSubPlot(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSubPlots*>(slo)->get(n);
}


/*
 * Get a SedSubPlot_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedListOfSubPlots_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSubPlots*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedSubPlot_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedListOfSubPlots_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSubPlots*>(slo)->remove(n);
}


/*
 * Removes the SedSubPlot_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedListOfSubPlots_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSubPlots*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


