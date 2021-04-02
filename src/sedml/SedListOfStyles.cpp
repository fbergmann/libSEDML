/**
 * @file SedListOfStyles.cpp
 * @brief Implementation of the SedListOfStyles class.
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
#include <sedml/SedListOfStyles.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfStyles using the given SED-ML Level and @ p version
 * values.
 */
SedListOfStyles::SedListOfStyles(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfStyles using the given SedNamespaces object @p
 * sedMLns.
 */
SedListOfStyles::SedListOfStyles(SedNamespaces *sedMLns)
  : SedListOf(sedMLns)
{
  setElementNamespace(sedMLns->getURI());
}


/*
 * Copy constructor for SedListOfStyles.
 */
SedListOfStyles::SedListOfStyles(const SedListOfStyles& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfStyles.
 */
SedListOfStyles&
SedListOfStyles::operator=(const SedListOfStyles& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfStyles object.
 */
SedListOfStyles*
SedListOfStyles::clone() const
{
  return new SedListOfStyles(*this);
}


/*
 * Destructor for SedListOfStyles.
 */
SedListOfStyles::~SedListOfStyles()
{
}


/*
 * Get a SedStyle from the SedListOfStyles.
 */
SedStyle*
SedListOfStyles::get(unsigned int n)
{
  return static_cast<SedStyle*>(SedListOf::get(n));
}


/*
 * Get a SedStyle from the SedListOfStyles.
 */
const SedStyle*
SedListOfStyles::get(unsigned int n) const
{
  return static_cast<const SedStyle*>(SedListOf::get(n));
}


/*
 * Get a SedStyle from the SedListOfStyles based on its identifier.
 */
SedStyle*
SedListOfStyles::get(const std::string& sid)
{
  return const_cast<SedStyle*>(static_cast<const
    SedListOfStyles&>(*this).get(sid));
}


/*
 * Get a SedStyle from the SedListOfStyles based on its identifier.
 */
const SedStyle*
SedListOfStyles::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedStyle>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedStyle*>
    (*result);
}


/*
 * Removes the nth SedStyle from this SedListOfStyles and returns a pointer to
 * it.
 */
SedStyle*
SedListOfStyles::remove(unsigned int n)
{
  return static_cast<SedStyle*>(SedListOf::remove(n));
}


/*
 * Removes the SedStyle from this SedListOfStyles based on its identifier and
 * returns a pointer to it.
 */
SedStyle*
SedListOfStyles::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedStyle>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedStyle*> (item);
}


/*
 * Adds a copy of the given SedStyle to this SedListOfStyles.
 */
int
SedListOfStyles::addStyle(const SedStyle* ss)
{
  if (ss == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (ss->hasRequiredAttributes() == false)
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
 * Get the number of SedStyle objects in this SedListOfStyles.
 */
unsigned int
SedListOfStyles::getNumStyles() const
{
  return size();
}


/*
 * Creates a new SedStyle object, adds it to this SedListOfStyles object and
 * returns the SedStyle object created.
 */
SedStyle*
SedListOfStyles::createStyle()
{
  SedStyle* ss = NULL;

  try
  {
    ss = new SedStyle(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ss != NULL)
  {
    appendAndOwn(ss);
  }

  return ss;
}


/*
 * Used by SedListOfStyles::get() to lookup a SedStyle based on its BaseStyle.
 */
struct SedIdEqBS
{
  const string& id;
   
  SedIdEqBS (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedStyle*>(sb)->getBaseStyle() == id);
  }
};


/*
 * Get a SedStyle from the SedListOfStyles based on the BaseStyle to which it
 * refers.
 */
const SedStyle*
SedListOfStyles::getByBaseStyle(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqBS(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedStyle*>
    (*result);
}


/*
 * Get a SedStyle from the SedListOfStyles based on the BaseStyle to which it
 * refers.
 */
SedStyle*
SedListOfStyles::getByBaseStyle(const std::string& sid)
{
  return const_cast<SedStyle*>(static_cast<const
    SedListOfStyles&>(*this).getByBaseStyle(sid));
}


/*
 * Returns the XML element name of this SedListOfStyles object.
 */
const std::string&
SedListOfStyles::getElementName() const
{
  static const string name = "listOfStyles";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfStyles object.
 */
int
SedListOfStyles::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfStyles object.
 */
int
SedListOfStyles::getItemTypeCode() const
{
  return SEDML_STYLE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedStyle in this SedListOfStyles
 */
SedBase*
SedListOfStyles::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "style")
  {
    object = new SedStyle(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedStyle_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedListOfStyles_getStyle(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfStyles*>(slo)->get(n);
}


/*
 * Get a SedStyle_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedListOfStyles_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfStyles*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedStyle_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedListOfStyles_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfStyles*>(slo)->remove(n);
}


/*
 * Removes the SedStyle_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedStyle_t*
SedListOfStyles_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfStyles*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


