/**
 * @file SedListOfVariables.cpp
 * @brief Implementation of the SedListOfVariables class.
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
#include <sedml/SedListOfVariables.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedVariable.h>

using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfVariables using the given SED-ML Level and @ p version
 * values.
 */
SedListOfVariables::SedListOfVariables(unsigned int level,
                                       unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfVariables using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfVariables::SedListOfVariables(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfVariables.
 */
SedListOfVariables::SedListOfVariables(const SedListOfVariables& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfVariables.
 */
SedListOfVariables&
SedListOfVariables::operator=(const SedListOfVariables& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfVariables object.
 */
SedListOfVariables*
SedListOfVariables::clone() const
{
  return new SedListOfVariables(*this);
}


/*
 * Destructor for SedListOfVariables.
 */
SedListOfVariables::~SedListOfVariables()
{
}


/*
 * Get a SedVariable from the SedListOfVariables.
 */
SedVariable*
SedListOfVariables::get(unsigned int n)
{
  return static_cast<SedVariable*>(SedListOf::get(n));
}


/*
 * Get a SedVariable from the SedListOfVariables.
 */
const SedVariable*
SedListOfVariables::get(unsigned int n) const
{
  return static_cast<const SedVariable*>(SedListOf::get(n));
}


/*
 * Get a SedVariable from the SedListOfVariables based on its identifier.
 */
SedVariable*
SedListOfVariables::get(const std::string& sid)
{
  return const_cast<SedVariable*>(static_cast<const
    SedListOfVariables&>(*this).get(sid));
}


/*
 * Get a SedVariable from the SedListOfVariables based on its identifier.
 */
const SedVariable*
SedListOfVariables::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedVariable>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedVariable*>
    (*result);
}


/*
 * Removes the nth SedVariable from this SedListOfVariables and returns a
 * pointer to it.
 */
SedVariable*
SedListOfVariables::remove(unsigned int n)
{
  return static_cast<SedVariable*>(SedListOf::remove(n));
}


/*
 * Removes the SedVariable from this SedListOfVariables based on its identifier
 * and returns a pointer to it.
 */
SedVariable*
SedListOfVariables::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedVariable>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedVariable*> (item);
}


/*
 * Adds a copy of the given SedVariable to this SedListOfVariables.
 */
int
SedListOfVariables::addVariable(const SedVariable* sv)
{
  if (sv == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sv->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sv->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sv->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sv)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sv);
  }
}


/*
 * Get the number of SedVariable objects in this SedListOfVariables.
 */
unsigned int
SedListOfVariables::getNumVariables() const
{
  return size();
}


/*
 * Creates a new SedVariable object, adds it to this SedListOfVariables object
 * and returns the SedVariable object created.
 */
SedVariable*
SedListOfVariables::createVariable()
{
  SedVariable* sv = NULL;

  try
  {
    sv = new SedVariable(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sv != NULL)
  {
    appendAndOwn(sv);
  }

  return sv;
}


/** @cond doxygenLibSEDMLInternal */

/*
 * checks concrete types
 */
bool
SedListOfVariables::isValidTypeForList(SedBase* item)
{
  unsigned int tc = item->getTypeCode();

  return (tc == SEDML_VARIABLE);
}

/** @endcond */


/*
 * Used by SedListOfVariables::get() to lookup a SedVariable based on its
 * TaskReference.
 */
struct SedIdEqTR
{
  const string& id;
   
  SedIdEqTR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedVariable*>(sb)->getTaskReference() == id);
  }
};


/*
 * Get a SedVariable from the SedListOfVariables based on the TaskReference to
 * which it refers.
 */
const SedVariable*
SedListOfVariables::getByTaskReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqTR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedVariable*>
    (*result);
}


/*
 * Get a SedVariable from the SedListOfVariables based on the TaskReference to
 * which it refers.
 */
SedVariable*
SedListOfVariables::getByTaskReference(const std::string& sid)
{
  return const_cast<SedVariable*>(static_cast<const
    SedListOfVariables&>(*this).getByTaskReference(sid));
}


/*
 * Used by SedListOfVariables::get() to lookup a SedVariable based on its
 * ModelReference.
 */
struct SedIdEqMR
{
  const string& id;
   
  SedIdEqMR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedVariable*>(sb)->getModelReference() == id);
  }
};


/*
 * Get a SedVariable from the SedListOfVariables based on the ModelReference to
 * which it refers.
 */
const SedVariable*
SedListOfVariables::getByModelReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqMR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedVariable*>
    (*result);
}


/*
 * Get a SedVariable from the SedListOfVariables based on the ModelReference to
 * which it refers.
 */
SedVariable*
SedListOfVariables::getByModelReference(const std::string& sid)
{
  return const_cast<SedVariable*>(static_cast<const
    SedListOfVariables&>(*this).getByModelReference(sid));
}


/*
 * Returns the XML element name of this SedListOfVariables object.
 */
const std::string&
SedListOfVariables::getElementName() const
{
  static const string name = "listOfVariables";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfVariables object.
 */
int
SedListOfVariables::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfVariables object.
 */
int
SedListOfVariables::getItemTypeCode() const
{
  return SEDML_VARIABLE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedVariable in this SedListOfVariables
 */
SedBase*
SedListOfVariables::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "variable")
  {
    object = new SedVariable(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedVariable_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedListOfVariables_getVariable(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfVariables*>(slo)->get(n);
}


/*
 * Get a SedVariable_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedListOfVariables_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfVariables*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedVariable_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedListOfVariables_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfVariables*>(slo)->remove(n);
}


/*
 * Removes the SedVariable_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedVariable_t*
SedListOfVariables_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfVariables*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


