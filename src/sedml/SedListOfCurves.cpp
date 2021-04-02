/**
 * @file SedListOfCurves.cpp
 * @brief Implementation of the SedListOfCurves class.
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
#include <sedml/SedListOfCurves.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedCurve.h>
#include <sedml/SedShadedArea.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfCurves using the given SED-ML Level and @ p version
 * values.
 */
SedListOfCurves::SedListOfCurves(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfCurves using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfCurves::SedListOfCurves(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfCurves.
 */
SedListOfCurves::SedListOfCurves(const SedListOfCurves& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfCurves.
 */
SedListOfCurves&
SedListOfCurves::operator=(const SedListOfCurves& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


struct AbstractCurvesOrderComparator
{
    // Compare two SedSubTasks objects using the 'order' attribute.
    bool operator ()(const SedBase* obj1, const SedBase* obj2)
    {
        if (obj1 == NULL || obj2 == NULL)
        {
            return false;
        }
        const SedAbstractCurve* at1 = static_cast<const SedAbstractCurve*>(obj1);
        const SedAbstractCurve* at2 = static_cast<const SedAbstractCurve*>(obj2);
        if (!at1->isSetOrder() || !at2->isSetOrder())
        {
            return false;
        }

        return at1->getOrder() < at2->getOrder();
    }
};

void SedListOfCurves::sort()
{
    std::sort(mItems.begin(), mItems.end(), AbstractCurvesOrderComparator());
}

/*
 * Creates and returns a deep copy of this SedListOfCurves object.
 */
SedListOfCurves*
SedListOfCurves::clone() const
{
  return new SedListOfCurves(*this);
}


/*
 * Destructor for SedListOfCurves.
 */
SedListOfCurves::~SedListOfCurves()
{
}


/*
 * Get a SedAbstractCurve from the SedListOfCurves.
 */
SedAbstractCurve*
SedListOfCurves::get(unsigned int n)
{
  return static_cast<SedAbstractCurve*>(SedListOf::get(n));
}


/*
 * Get a SedAbstractCurve from the SedListOfCurves.
 */
const SedAbstractCurve*
SedListOfCurves::get(unsigned int n) const
{
  return static_cast<const SedAbstractCurve*>(SedListOf::get(n));
}


/*
 * Get a SedAbstractCurve from the SedListOfCurves based on its identifier.
 */
SedAbstractCurve*
SedListOfCurves::get(const std::string& sid)
{
  return const_cast<SedAbstractCurve*>(static_cast<const
    SedListOfCurves&>(*this).get(sid));
}


/*
 * Get a SedAbstractCurve from the SedListOfCurves based on its identifier.
 */
const SedAbstractCurve*
SedListOfCurves::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAbstractCurve>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedAbstractCurve*>
    (*result);
}


/*
 * Removes the nth SedAbstractCurve from this SedListOfCurves and returns a
 * pointer to it.
 */
SedAbstractCurve*
SedListOfCurves::remove(unsigned int n)
{
  return static_cast<SedAbstractCurve*>(SedListOf::remove(n));
}


/*
 * Removes the SedAbstractCurve from this SedListOfCurves based on its
 * identifier and returns a pointer to it.
 */
SedAbstractCurve*
SedListOfCurves::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAbstractCurve>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedAbstractCurve*> (item);
}


/*
 * Adds a copy of the given SedAbstractCurve to this SedListOfCurves.
 */
int
SedListOfCurves::addCurve(const SedAbstractCurve* sac)
{
  if (sac == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sac->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sac->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sac->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sac)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sac);
  }
}


/*
 * Get the number of SedAbstractCurve objects in this SedListOfCurves.
 */
unsigned int
SedListOfCurves::getNumCurves() const
{
  return size();
}


/*
 * Creates a new SedCurve object, adds it to this SedListOfCurves object and
 * returns the SedCurve object created.
 */
SedCurve*
SedListOfCurves::createCurve()
{
  SedCurve* sc = NULL;

  try
  {
    sc = new SedCurve(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sc != NULL)
  {
    appendAndOwn(sc);
  }

  return sc;
}


/*
 * Creates a new SedShadedArea object, adds it to this SedListOfCurves object
 * and returns the SedShadedArea object created.
 */
SedShadedArea*
SedListOfCurves::createShadedArea()
{
  SedShadedArea* ssa = NULL;

  try
  {
    ssa = new SedShadedArea(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ssa != NULL)
  {
    appendAndOwn(ssa);
  }

  return ssa;
}


/*
 * Used by SedListOfCurves::get() to lookup a SedAbstractCurve based on its
 * Style.
 */
struct SedIdEqS
{
  const string& id;
   
  SedIdEqS (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedAbstractCurve*>(sb)->getStyle() == id);
  }
};


/*
 * Get a SedAbstractCurve from the SedListOfCurves based on the Style to which
 * it refers.
 */
const SedAbstractCurve*
SedListOfCurves::getByStyle(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqS(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedAbstractCurve*>
    (*result);
}


/*
 * Get a SedAbstractCurve from the SedListOfCurves based on the Style to which
 * it refers.
 */
SedAbstractCurve*
SedListOfCurves::getByStyle(const std::string& sid)
{
  return const_cast<SedAbstractCurve*>(static_cast<const
    SedListOfCurves&>(*this).getByStyle(sid));
}


/*
 * Used by SedListOfCurves::get() to lookup a SedAbstractCurve based on its
 * XDataReference.
 */
struct SedIdEqXDR
{
  const string& id;
   
  SedIdEqXDR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedAbstractCurve*>(sb)->getXDataReference() == id);
  }
};


/*
 * Get a SedAbstractCurve from the SedListOfCurves based on the XDataReference
 * to which it refers.
 */
const SedAbstractCurve*
SedListOfCurves::getByXDataReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqXDR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedAbstractCurve*>
    (*result);
}


/*
 * Get a SedAbstractCurve from the SedListOfCurves based on the XDataReference
 * to which it refers.
 */
SedAbstractCurve*
SedListOfCurves::getByXDataReference(const std::string& sid)
{
  return const_cast<SedAbstractCurve*>(static_cast<const
    SedListOfCurves&>(*this).getByXDataReference(sid));
}


/*
 * Returns the XML element name of this SedListOfCurves object.
 */
const std::string&
SedListOfCurves::getElementName() const
{
  static const string name = "listOfCurves";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfCurves object.
 */
int
SedListOfCurves::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfCurves object.
 */
int
SedListOfCurves::getItemTypeCode() const
{
  return SEDML_ABSTRACTCURVE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedAbstractCurve in this SedListOfCurves
 */
SedBase*
SedListOfCurves::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "abstractCurve")
  {
    object = new SedAbstractCurve(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "curve")
  {
    object = new SedCurve(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "shadedArea")
  {
    object = new SedShadedArea(getSedNamespaces());
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
SedListOfCurves::isValidTypeForList(SedBase* item)
{
  unsigned int tc = item->getTypeCode();

  return ((tc == SEDML_OUTPUT_CURVE) || (tc == SEDML_SHADEDAREA));
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedAbstractCurve_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedListOfCurves_getCurve(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfCurves*>(slo)->get(n);
}


/*
 * Get a SedAbstractCurve_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedListOfCurves_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfCurves*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedAbstractCurve_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedListOfCurves_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfCurves*>(slo)->remove(n);
}


/*
 * Removes the SedAbstractCurve_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedListOfCurves_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfCurves*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


