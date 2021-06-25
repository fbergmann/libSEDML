/**
 * @file SedListOfSimulations.cpp
 * @brief Implementation of the SedListOfSimulations class.
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
#include <sedml/SedListOfSimulations.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedUniformTimeCourse.h>
#include <sedml/SedOneStep.h>
#include <sedml/SedSteadyState.h>
#include <sedml/SedAnalysis.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfSimulations using the given SED-ML Level and @ p
 * version values.
 */
SedListOfSimulations::SedListOfSimulations(unsigned int level,
                                           unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfSimulations using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfSimulations::SedListOfSimulations(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfSimulations.
 */
SedListOfSimulations::SedListOfSimulations(const SedListOfSimulations& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfSimulations.
 */
SedListOfSimulations&
SedListOfSimulations::operator=(const SedListOfSimulations& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfSimulations object.
 */
SedListOfSimulations*
SedListOfSimulations::clone() const
{
  return new SedListOfSimulations(*this);
}


/*
 * Destructor for SedListOfSimulations.
 */
SedListOfSimulations::~SedListOfSimulations()
{
}


/*
 * Get a SedSimulation from the SedListOfSimulations.
 */
SedSimulation*
SedListOfSimulations::get(unsigned int n)
{
  return static_cast<SedSimulation*>(SedListOf::get(n));
}


/*
 * Get a SedSimulation from the SedListOfSimulations.
 */
const SedSimulation*
SedListOfSimulations::get(unsigned int n) const
{
  return static_cast<const SedSimulation*>(SedListOf::get(n));
}


/*
 * Get a SedSimulation from the SedListOfSimulations based on its identifier.
 */
SedSimulation*
SedListOfSimulations::get(const std::string& sid)
{
  return const_cast<SedSimulation*>(static_cast<const
    SedListOfSimulations&>(*this).get(sid));
}


/*
 * Get a SedSimulation from the SedListOfSimulations based on its identifier.
 */
const SedSimulation*
SedListOfSimulations::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSimulation>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSimulation*>
    (*result);
}


/*
 * Removes the nth SedSimulation from this SedListOfSimulations and returns a
 * pointer to it.
 */
SedSimulation*
SedListOfSimulations::remove(unsigned int n)
{
  return static_cast<SedSimulation*>(SedListOf::remove(n));
}


/*
 * Removes the SedSimulation from this SedListOfSimulations based on its
 * identifier and returns a pointer to it.
 */
SedSimulation*
SedListOfSimulations::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSimulation>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedSimulation*> (item);
}


/*
 * Adds a copy of the given SedSimulation to this SedListOfSimulations.
 */
int
SedListOfSimulations::addSimulation(const SedSimulation* ss)
{
  if (ss == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ss->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (ss->hasRequiredElements() == false)
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
 * Get the number of SedSimulation objects in this SedListOfSimulations.
 */
unsigned int
SedListOfSimulations::getNumSimulations() const
{
  return size();
}


/*
 * Creates a new SedUniformTimeCourse object, adds it to this
 * SedListOfSimulations object and returns the SedUniformTimeCourse object
 * created.
 */
SedUniformTimeCourse*
SedListOfSimulations::createUniformTimeCourse()
{
  SedUniformTimeCourse* sutc = NULL;

  try
  {
    sutc = new SedUniformTimeCourse(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sutc != NULL)
  {
    appendAndOwn(sutc);
  }

  return sutc;
}


/*
 * Creates a new SedOneStep object, adds it to this SedListOfSimulations object
 * and returns the SedOneStep object created.
 */
SedOneStep*
SedListOfSimulations::createOneStep()
{
  SedOneStep* sos = NULL;

  try
  {
    sos = new SedOneStep(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sos != NULL)
  {
    appendAndOwn(sos);
  }

  return sos;
}


/*
 * Creates a new SedSteadyState object, adds it to this SedListOfSimulations
 * object and returns the SedSteadyState object created.
 */
SedSteadyState*
SedListOfSimulations::createSteadyState()
{
  SedSteadyState* sss = NULL;

  try
  {
    sss = new SedSteadyState(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sss != NULL)
  {
    appendAndOwn(sss);
  }

  return sss;
}


/*
 * Creates a new SedAnalysis object, adds it to this SedListOfSimulations
 * object and returns the SedAnalysis object created.
 */
SedAnalysis*
SedListOfSimulations::createAnalysis()
{
    SedAnalysis* sss = NULL;

    try
    {
        sss = new SedAnalysis(getSedNamespaces());
    }
    catch (...)
    {
    }

    if (sss != NULL)
    {
        appendAndOwn(sss);
    }

    return sss;
}


/*
 * Returns the XML element name of this SedListOfSimulations object.
 */
const std::string&
SedListOfSimulations::getElementName() const
{
  static const string name = "listOfSimulations";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfSimulations object.
 */
int
SedListOfSimulations::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfSimulations object.
 */
int
SedListOfSimulations::getItemTypeCode() const
{
  return SEDML_SIMULATION;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedSimulation in this SedListOfSimulations
 */
SedBase*
SedListOfSimulations::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "simulation")
  {
    object = new SedSimulation(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "uniformTimeCourse")
  {
    object = new SedUniformTimeCourse(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "oneStep")
  {
    object = new SedOneStep(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "steadyState")
  {
    object = new SedSteadyState(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "analysis")
  {
      object = new SedAnalysis(getSedNamespaces());
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
SedListOfSimulations::isValidTypeForList(SedBase* item)
{
  unsigned int tc = item->getTypeCode();

  return ((tc == SEDML_SIMULATION_UNIFORMTIMECOURSE) 
      ||  (tc == SEDML_SIMULATION_ONESTEP) 
      ||  (tc == SEDML_SIMULATION_STEADYSTATE)
      ||  (tc == SEDML_SIMULATION_ANALYSIS));
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedSimulation_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedListOfSimulations_getSimulation(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSimulations*>(slo)->get(n);
}


/*
 * Get a SedSimulation_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedListOfSimulations_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSimulations*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedSimulation_t from this SedListOf_t and returns a pointer
 * to it.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedListOfSimulations_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSimulations*>(slo)->remove(n);
}


/*
 * Removes the SedSimulation_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedListOfSimulations_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSimulations*>(slo)->remove(sid)
    : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


