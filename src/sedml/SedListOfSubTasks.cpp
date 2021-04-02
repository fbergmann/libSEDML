/**
 * @file SedListOfSubTasks.cpp
 * @brief Implementation of the SedListOfSubTasks class.
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
#include <sedml/SedListOfSubTasks.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfSubTasks using the given SED-ML Level and @ p version
 * values.
 */
SedListOfSubTasks::SedListOfSubTasks(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfSubTasks using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfSubTasks::SedListOfSubTasks(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfSubTasks.
 */
SedListOfSubTasks::SedListOfSubTasks(const SedListOfSubTasks& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfSubTasks.
 */
SedListOfSubTasks&
SedListOfSubTasks::operator=(const SedListOfSubTasks& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfSubTasks object.
 */
SedListOfSubTasks*
SedListOfSubTasks::clone() const
{
  return new SedListOfSubTasks(*this);
}


/*
 * Destructor for SedListOfSubTasks.
 */
SedListOfSubTasks::~SedListOfSubTasks()
{
}


struct SubTaskOrderComparator
{
    // Compare two SedSubTasks objects using the 'order' attribute.
    bool operator ()(const SedBase* obj1, const SedBase* obj2)
    {
        if (obj1 == NULL || obj2 == NULL)
        {
            return false;
        }
        const SedSubTask* at1 = static_cast<const SedSubTask*>(obj1);
        const SedSubTask* at2 = static_cast<const SedSubTask*>(obj2);
        if (!at1->isSetOrder() || !at2->isSetOrder())
        {
            return false;
        }

        return at1->getOrder() < at2->getOrder();
    }
};

void SedListOfSubTasks::sort()
{
    std::sort(mItems.begin(), mItems.end(), SubTaskOrderComparator());
}



/*
 * Get a SedSubTask from the SedListOfSubTasks.
 */
SedSubTask*
SedListOfSubTasks::get(unsigned int n)
{
  return static_cast<SedSubTask*>(SedListOf::get(n));
}


/*
 * Get a SedSubTask from the SedListOfSubTasks.
 */
const SedSubTask*
SedListOfSubTasks::get(unsigned int n) const
{
  return static_cast<const SedSubTask*>(SedListOf::get(n));
}


/*
 * Get a SedSubTask from the SedListOfSubTasks based on its identifier.
 */
SedSubTask*
SedListOfSubTasks::get(const std::string& sid)
{
  return const_cast<SedSubTask*>(static_cast<const
    SedListOfSubTasks&>(*this).get(sid));
}


/*
 * Get a SedSubTask from the SedListOfSubTasks based on its identifier.
 */
const SedSubTask*
SedListOfSubTasks::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSubTask>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSubTask*>
    (*result);
}


/*
 * Removes the nth SedSubTask from this SedListOfSubTasks and returns a pointer
 * to it.
 */
SedSubTask*
SedListOfSubTasks::remove(unsigned int n)
{
  return static_cast<SedSubTask*>(SedListOf::remove(n));
}


/*
 * Removes the SedSubTask from this SedListOfSubTasks based on its identifier
 * and returns a pointer to it.
 */
SedSubTask*
SedListOfSubTasks::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSubTask>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedSubTask*> (item);
}


/*
 * Adds a copy of the given SedSubTask to this SedListOfSubTasks.
 */
int
SedListOfSubTasks::addSubTask(const SedSubTask* sst)
{
  if (sst == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sst->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sst->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sst->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sst)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sst);
  }
}


/*
 * Get the number of SedSubTask objects in this SedListOfSubTasks.
 */
unsigned int
SedListOfSubTasks::getNumSubTasks() const
{
  return size();
}


/*
 * Creates a new SedSubTask object, adds it to this SedListOfSubTasks object
 * and returns the SedSubTask object created.
 */
SedSubTask*
SedListOfSubTasks::createSubTask()
{
  SedSubTask* sst = NULL;

  try
  {
    sst = new SedSubTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sst != NULL)
  {
    appendAndOwn(sst);
  }

  return sst;
}


/*
 * Used by SedListOfSubTasks::get() to lookup a SedSubTask based on its Task.
 */
struct SedIdEqT
{
  const string& id;
   
  SedIdEqT (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSubTask*>(sb)->getTask() == id);
  }
};


/*
 * Get a SedSubTask from the SedListOfSubTasks based on the Task to which it
 * refers.
 */
const SedSubTask*
SedListOfSubTasks::getByTask(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqT(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSubTask*>
    (*result);
}


/*
 * Get a SedSubTask from the SedListOfSubTasks based on the Task to which it
 * refers.
 */
SedSubTask*
SedListOfSubTasks::getByTask(const std::string& sid)
{
  return const_cast<SedSubTask*>(static_cast<const
    SedListOfSubTasks&>(*this).getByTask(sid));
}


/*
 * Returns the XML element name of this SedListOfSubTasks object.
 */
const std::string&
SedListOfSubTasks::getElementName() const
{
  static const string name = "listOfSubTasks";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfSubTasks object.
 */
int
SedListOfSubTasks::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfSubTasks object.
 */
int
SedListOfSubTasks::getItemTypeCode() const
{
  return SEDML_TASK_SUBTASK;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedSubTask in this SedListOfSubTasks
 */
SedBase*
SedListOfSubTasks::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "subTask")
  {
    object = new SedSubTask(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedSubTask_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedListOfSubTasks_getSubTask(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSubTasks*>(slo)->get(n);
}


/*
 * Get a SedSubTask_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedListOfSubTasks_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSubTasks*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedSubTask_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedListOfSubTasks_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSubTasks*>(slo)->remove(n);
}


/*
 * Removes the SedSubTask_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedListOfSubTasks_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSubTasks*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


