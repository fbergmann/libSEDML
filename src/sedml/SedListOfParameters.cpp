/**
 * @file SedListOfParameters.cpp
 * @brief Implementation of the SedListOfParameters class.
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
#include <sedml/SedListOfParameters.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfParameters using the given SED-ML Level and @ p
 * version values.
 */
SedListOfParameters::SedListOfParameters(unsigned int level,
                                         unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfParameters using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfParameters::SedListOfParameters(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfParameters.
 */
SedListOfParameters::SedListOfParameters(const SedListOfParameters& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfParameters.
 */
SedListOfParameters&
SedListOfParameters::operator=(const SedListOfParameters& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfParameters object.
 */
SedListOfParameters*
SedListOfParameters::clone() const
{
  return new SedListOfParameters(*this);
}


/*
 * Destructor for SedListOfParameters.
 */
SedListOfParameters::~SedListOfParameters()
{
}


/*
 * Get a SedParameter from the SedListOfParameters.
 */
SedParameter*
SedListOfParameters::get(unsigned int n)
{
  return static_cast<SedParameter*>(SedListOf::get(n));
}


/*
 * Get a SedParameter from the SedListOfParameters.
 */
const SedParameter*
SedListOfParameters::get(unsigned int n) const
{
  return static_cast<const SedParameter*>(SedListOf::get(n));
}


/*
 * Get a SedParameter from the SedListOfParameters based on its identifier.
 */
SedParameter*
SedListOfParameters::get(const std::string& sid)
{
  return const_cast<SedParameter*>(static_cast<const
    SedListOfParameters&>(*this).get(sid));
}


/*
 * Get a SedParameter from the SedListOfParameters based on its identifier.
 */
const SedParameter*
SedListOfParameters::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedParameter>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedParameter*>
    (*result);
}


/*
 * Removes the nth SedParameter from this SedListOfParameters and returns a
 * pointer to it.
 */
SedParameter*
SedListOfParameters::remove(unsigned int n)
{
  return static_cast<SedParameter*>(SedListOf::remove(n));
}


/*
 * Removes the SedParameter from this SedListOfParameters based on its
 * identifier and returns a pointer to it.
 */
SedParameter*
SedListOfParameters::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedParameter>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedParameter*> (item);
}


/*
 * Adds a copy of the given SedParameter to this SedListOfParameters.
 */
int
SedListOfParameters::addParameter(const SedParameter* sp)
{
  if (sp == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sp->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sp->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sp->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sp)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sp);
  }
}


/*
 * Get the number of SedParameter objects in this SedListOfParameters.
 */
unsigned int
SedListOfParameters::getNumParameters() const
{
  return size();
}


/*
 * Creates a new SedParameter object, adds it to this SedListOfParameters
 * object and returns the SedParameter object created.
 */
SedParameter*
SedListOfParameters::createParameter()
{
  SedParameter* sp = NULL;

  try
  {
    sp = new SedParameter(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sp != NULL)
  {
    appendAndOwn(sp);
  }

  return sp;
}


/*
 * Returns the XML element name of this SedListOfParameters object.
 */
const std::string&
SedListOfParameters::getElementName() const
{
  static const string name = "listOfParameters";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfParameters object.
 */
int
SedListOfParameters::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfParameters object.
 */
int
SedListOfParameters::getItemTypeCode() const
{
  return SEDML_PARAMETER;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedParameter in this SedListOfParameters
 */
SedBase*
SedListOfParameters::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "parameter")
  {
    object = new SedParameter(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedParameter_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedListOfParameters_getParameter(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfParameters*>(slo)->get(n);
}


/*
 * Get a SedParameter_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedListOfParameters_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfParameters*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedParameter_t from this SedListOf_t and returns a pointer
 * to it.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedListOfParameters_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfParameters*>(slo)->remove(n);
}


/*
 * Removes the SedParameter_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedParameter_t*
SedListOfParameters_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfParameters*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


