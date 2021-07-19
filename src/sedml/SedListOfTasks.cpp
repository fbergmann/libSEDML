/**
 * @file SedListOfTasks.cpp
 * @brief Implementation of the SedListOfTasks class.
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
#include <sedml/SedListOfTasks.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedTask.h>
#include <sedml/SedRepeatedTask.h>
#include <sedml/SedParameterEstimationTask.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfTasks using the given SED-ML Level and @ p version
 * values.
 */
SedListOfTasks::SedListOfTasks(unsigned int level, unsigned int version)
  : SedListOf(level, version)
  , mElementName("listOfTasks")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfTasks using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfTasks::SedListOfTasks(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
  , mElementName("listOfTasks")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfTasks.
 */
SedListOfTasks::SedListOfTasks(const SedListOfTasks& orig)
  : SedListOf( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedListOfTasks.
 */
SedListOfTasks&
SedListOfTasks::operator=(const SedListOfTasks& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfTasks object.
 */
SedListOfTasks*
SedListOfTasks::clone() const
{
  return new SedListOfTasks(*this);
}


/*
 * Destructor for SedListOfTasks.
 */
SedListOfTasks::~SedListOfTasks()
{
}


/*
 * Get a SedAbstractTask from the SedListOfTasks.
 */
SedAbstractTask*
SedListOfTasks::get(unsigned int n)
{
  return static_cast<SedAbstractTask*>(SedListOf::get(n));
}


/*
 * Get a SedAbstractTask from the SedListOfTasks.
 */
const SedAbstractTask*
SedListOfTasks::get(unsigned int n) const
{
  return static_cast<const SedAbstractTask*>(SedListOf::get(n));
}


/*
 * Get a SedAbstractTask from the SedListOfTasks based on its identifier.
 */
SedAbstractTask*
SedListOfTasks::get(const std::string& sid)
{
  return const_cast<SedAbstractTask*>(static_cast<const
    SedListOfTasks&>(*this).get(sid));
}


/*
 * Get a SedAbstractTask from the SedListOfTasks based on its identifier.
 */
const SedAbstractTask*
SedListOfTasks::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAbstractTask>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedAbstractTask*>
    (*result);
}


/*
 * Removes the nth SedAbstractTask from this SedListOfTasks and returns a
 * pointer to it.
 */
SedAbstractTask*
SedListOfTasks::remove(unsigned int n)
{
  return static_cast<SedAbstractTask*>(SedListOf::remove(n));
}


/*
 * Removes the SedAbstractTask from this SedListOfTasks based on its identifier
 * and returns a pointer to it.
 */
SedAbstractTask*
SedListOfTasks::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAbstractTask>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedAbstractTask*> (item);
}


/*
 * Adds a copy of the given SedAbstractTask to this SedListOfTasks.
 */
int
SedListOfTasks::addAbstractTask(const SedAbstractTask* sat)
{
  if (sat == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sat->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sat->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sat->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sat)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sat);
  }
}


/*
 * Get the number of SedAbstractTask objects in this SedListOfTasks.
 */
unsigned int
SedListOfTasks::getNumAbstractTasks() const
{
  return size();
}


/*
 * Creates a new SedTask object, adds it to this SedListOfTasks object and
 * returns the SedTask object created.
 */
SedTask*
SedListOfTasks::createTask()
{
  SedTask* st = NULL;

  try
  {
    st = new SedTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (st != NULL)
  {
    appendAndOwn(st);
  }

  return st;
}


/*
 * Creates a new SedRepeatedTask object, adds it to this SedListOfTasks object
 * and returns the SedRepeatedTask object created.
 */
SedRepeatedTask*
SedListOfTasks::createRepeatedTask()
{
  SedRepeatedTask* srt = NULL;

  try
  {
    srt = new SedRepeatedTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (srt != NULL)
  {
    appendAndOwn(srt);
  }

  return srt;
}


/*
 * Creates a new SedParameterEstimationTask object, adds it to this
 * SedListOfTasks object and returns the SedParameterEstimationTask object
 * created.
 */
SedParameterEstimationTask*
SedListOfTasks::createParameterEstimationTask()
{
  SedParameterEstimationTask* spet = NULL;

  try
  {
    spet = new SedParameterEstimationTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (spet != NULL)
  {
    appendAndOwn(spet);
  }

  return spet;
}


/*
 * Returns the XML element name of this SedListOfTasks object.
 */
const std::string&
SedListOfTasks::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedListOfTasks object.
 */
void
SedListOfTasks::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedListOfTasks object.
 */
int
SedListOfTasks::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfTasks object.
 */
int
SedListOfTasks::getItemTypeCode() const
{
  return SEDML_SEDML_ABSTRACTTASK;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedAbstractTask in this SedListOfTasks
 */
SedBase*
SedListOfTasks::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "task")
  {
    object = new SedTask(getSedNamespaces());
    if (object)
    {
      dynamic_cast<SedAbstractTask*>(object)->setElementName(name);
    }

    appendAndOwn(object);
  }

  if (name == "repeatedTask")
  {
    object = new SedRepeatedTask(getSedNamespaces());
    if (object)
    {
      dynamic_cast<SedAbstractTask*>(object)->setElementName(name);
    }

    appendAndOwn(object);
  }

  if (name == "parameterEstimationTask")
  {
    object = new SedParameterEstimationTask(getSedNamespaces());
    if (object)
    {
      dynamic_cast<SedAbstractTask*>(object)->setElementName(name);
    }

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
SedListOfTasks::isValidTypeForList(SedBase* item)
{
  unsigned int tc = item->getTypeCode();

  return ((tc == SEDML_TASK) || (tc == SEDML_TASK_REPEATEDTASK) || (tc ==
    SEDML_TASK_PARAMETER_ESTIMATION));
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedAbstractTask_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfTasks_getAbstractTask(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfTasks*>(slo)->get(n);
}


/*
 * Get a SedAbstractTask_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfTasks_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfTasks*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedAbstractTask_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfTasks_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfTasks*>(slo)->remove(n);
}


/*
 * Removes the SedAbstractTask_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfTasks_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfTasks*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


