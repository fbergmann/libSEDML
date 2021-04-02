/**
 * @file SedListOfSetValues.cpp
 * @brief Implementation of the SedListOfSetValues class.
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
#include <sedml/SedListOfSetValues.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfSetValues using the given SED-ML Level and @ p version
 * values.
 */
SedListOfSetValues::SedListOfSetValues(unsigned int level,
                                       unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfSetValues using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfSetValues::SedListOfSetValues(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfSetValues.
 */
SedListOfSetValues::SedListOfSetValues(const SedListOfSetValues& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfSetValues.
 */
SedListOfSetValues&
SedListOfSetValues::operator=(const SedListOfSetValues& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfSetValues object.
 */
SedListOfSetValues*
SedListOfSetValues::clone() const
{
  return new SedListOfSetValues(*this);
}


/*
 * Destructor for SedListOfSetValues.
 */
SedListOfSetValues::~SedListOfSetValues()
{
}


/*
 * Get a SedSetValue from the SedListOfSetValues.
 */
SedSetValue*
SedListOfSetValues::get(unsigned int n)
{
  return static_cast<SedSetValue*>(SedListOf::get(n));
}


/*
 * Get a SedSetValue from the SedListOfSetValues.
 */
const SedSetValue*
SedListOfSetValues::get(unsigned int n) const
{
  return static_cast<const SedSetValue*>(SedListOf::get(n));
}


/*
 * Get a SedSetValue from the SedListOfSetValues based on its identifier.
 */
SedSetValue*
SedListOfSetValues::get(const std::string& sid)
{
  return const_cast<SedSetValue*>(static_cast<const
    SedListOfSetValues&>(*this).get(sid));
}


/*
 * Get a SedSetValue from the SedListOfSetValues based on its identifier.
 */
const SedSetValue*
SedListOfSetValues::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSetValue>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSetValue*>
    (*result);
}


/*
 * Removes the nth SedSetValue from this SedListOfSetValues and returns a
 * pointer to it.
 */
SedSetValue*
SedListOfSetValues::remove(unsigned int n)
{
  return static_cast<SedSetValue*>(SedListOf::remove(n));
}


/*
 * Removes the SedSetValue from this SedListOfSetValues based on its identifier
 * and returns a pointer to it.
 */
SedSetValue*
SedListOfSetValues::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSetValue>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedSetValue*> (item);
}


/*
 * Adds a copy of the given SedSetValue to this SedListOfSetValues.
 */
int
SedListOfSetValues::addTaskChange(const SedSetValue* ssv)
{
  if (ssv == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ssv->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (ssv->hasRequiredElements() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != ssv->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ssv->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(ssv)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(ssv);
  }
}


/*
 * Get the number of SedSetValue objects in this SedListOfSetValues.
 */
unsigned int
SedListOfSetValues::getNumTaskChanges() const
{
  return size();
}


/*
 * Creates a new SedSetValue object, adds it to this SedListOfSetValues object
 * and returns the SedSetValue object created.
 */
SedSetValue*
SedListOfSetValues::createSetValue()
{
  SedSetValue* ssv = NULL;

  try
  {
    ssv = new SedSetValue(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ssv != NULL)
  {
    appendAndOwn(ssv);
  }

  return ssv;
}


/*
 * Used by SedListOfSetValues::get() to lookup a SedSetValue based on its
 * ModelReference.
 */
struct SedIdEqMR
{
  const string& id;
   
  SedIdEqMR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSetValue*>(sb)->getModelReference() == id);
  }
};


/*
 * Get a SedSetValue from the SedListOfSetValues based on the ModelReference to
 * which it refers.
 */
const SedSetValue*
SedListOfSetValues::getByModelReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqMR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSetValue*>
    (*result);
}


/*
 * Get a SedSetValue from the SedListOfSetValues based on the ModelReference to
 * which it refers.
 */
SedSetValue*
SedListOfSetValues::getByModelReference(const std::string& sid)
{
  return const_cast<SedSetValue*>(static_cast<const
    SedListOfSetValues&>(*this).getByModelReference(sid));
}


/*
 * Used by SedListOfSetValues::get() to lookup a SedSetValue based on its
 * Range.
 */
struct SedIdEqR
{
  const string& id;
   
  SedIdEqR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSetValue*>(sb)->getRange() == id);
  }
};


/*
 * Get a SedSetValue from the SedListOfSetValues based on the Range to which it
 * refers.
 */
const SedSetValue*
SedListOfSetValues::getByRange(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSetValue*>
    (*result);
}


/*
 * Get a SedSetValue from the SedListOfSetValues based on the Range to which it
 * refers.
 */
SedSetValue*
SedListOfSetValues::getByRange(const std::string& sid)
{
  return const_cast<SedSetValue*>(static_cast<const
    SedListOfSetValues&>(*this).getByRange(sid));
}


/*
 * Returns the XML element name of this SedListOfSetValues object.
 */
const std::string&
SedListOfSetValues::getElementName() const
{
  static const string name = "listOfChanges";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfSetValues object.
 */
int
SedListOfSetValues::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfSetValues object.
 */
int
SedListOfSetValues::getItemTypeCode() const
{
  return SEDML_TASK_SETVALUE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedSetValue in this SedListOfSetValues
 */
SedBase*
SedListOfSetValues::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "setValue")
  {
    object = new SedSetValue(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedSetValue_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedListOfSetValues_getTaskChange(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSetValues*>(slo)->get(n);
}


/*
 * Get a SedSetValue_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedListOfSetValues_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSetValues*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedSetValue_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedListOfSetValues_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSetValues*>(slo)->remove(n);
}


/*
 * Removes the SedSetValue_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedListOfSetValues_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSetValues*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


