/**
 * @file SedListOfSurfaces.cpp
 * @brief Implementation of the SedListOfSurfaces class.
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
#include <sedml/SedListOfSurfaces.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfSurfaces using the given SED-ML Level and @ p version
 * values.
 */
SedListOfSurfaces::SedListOfSurfaces(unsigned int level, unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfSurfaces using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfSurfaces::SedListOfSurfaces(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfSurfaces.
 */
SedListOfSurfaces::SedListOfSurfaces(const SedListOfSurfaces& orig)
  : SedListOf( orig )
{
}


/*
 * Assignment operator for SedListOfSurfaces.
 */
SedListOfSurfaces&
SedListOfSurfaces::operator=(const SedListOfSurfaces& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
  }

  return *this;
}


struct SurfaceOrderComparator
{
    // Compare two SedSubTasks objects using the 'order' attribute.
    bool operator ()(const SedBase* obj1, const SedBase* obj2)
    {
        if (obj1 == NULL || obj2 == NULL)
        {
            return false;
        }
        const SedSurface* at1 = static_cast<const SedSurface*>(obj1);
        const SedSurface* at2 = static_cast<const SedSurface*>(obj2);
        if (!at1->isSetOrder() || !at2->isSetOrder())
        {
            return false;
        }

        return at1->getOrder() < at2->getOrder();
    }
};

void SedListOfSurfaces::sort()
{
    std::sort(mItems.begin(), mItems.end(), SurfaceOrderComparator());
}

/*
 * Creates and returns a deep copy of this SedListOfSurfaces object.
 */
SedListOfSurfaces*
SedListOfSurfaces::clone() const
{
  return new SedListOfSurfaces(*this);
}


/*
 * Destructor for SedListOfSurfaces.
 */
SedListOfSurfaces::~SedListOfSurfaces()
{
}


/*
 * Get a SedSurface from the SedListOfSurfaces.
 */
SedSurface*
SedListOfSurfaces::get(unsigned int n)
{
  return static_cast<SedSurface*>(SedListOf::get(n));
}


/*
 * Get a SedSurface from the SedListOfSurfaces.
 */
const SedSurface*
SedListOfSurfaces::get(unsigned int n) const
{
  return static_cast<const SedSurface*>(SedListOf::get(n));
}


/*
 * Get a SedSurface from the SedListOfSurfaces based on its identifier.
 */
SedSurface*
SedListOfSurfaces::get(const std::string& sid)
{
  return const_cast<SedSurface*>(static_cast<const
    SedListOfSurfaces&>(*this).get(sid));
}


/*
 * Get a SedSurface from the SedListOfSurfaces based on its identifier.
 */
const SedSurface*
SedListOfSurfaces::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSurface>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSurface*>
    (*result);
}


/*
 * Removes the nth SedSurface from this SedListOfSurfaces and returns a pointer
 * to it.
 */
SedSurface*
SedListOfSurfaces::remove(unsigned int n)
{
  return static_cast<SedSurface*>(SedListOf::remove(n));
}


/*
 * Removes the SedSurface from this SedListOfSurfaces based on its identifier
 * and returns a pointer to it.
 */
SedSurface*
SedListOfSurfaces::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSurface>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedSurface*> (item);
}


/*
 * Adds a copy of the given SedSurface to this SedListOfSurfaces.
 */
int
SedListOfSurfaces::addSurface(const SedSurface* ss)
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
 * Get the number of SedSurface objects in this SedListOfSurfaces.
 */
unsigned int
SedListOfSurfaces::getNumSurfaces() const
{
  return size();
}


/*
 * Creates a new SedSurface object, adds it to this SedListOfSurfaces object
 * and returns the SedSurface object created.
 */
SedSurface*
SedListOfSurfaces::createSurface()
{
  SedSurface* ss = NULL;

  try
  {
    ss = new SedSurface(getSedNamespaces());
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
 * Used by SedListOfSurfaces::get() to lookup a SedSurface based on its
 * XDataReference.
 */
struct SedIdEqXDR
{
  const string& id;
   
  SedIdEqXDR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSurface*>(sb)->getXDataReference() == id);
  }
};


/*
 * Get a SedSurface from the SedListOfSurfaces based on the XDataReference to
 * which it refers.
 */
const SedSurface*
SedListOfSurfaces::getByXDataReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqXDR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSurface*>
    (*result);
}


/*
 * Get a SedSurface from the SedListOfSurfaces based on the XDataReference to
 * which it refers.
 */
SedSurface*
SedListOfSurfaces::getByXDataReference(const std::string& sid)
{
  return const_cast<SedSurface*>(static_cast<const
    SedListOfSurfaces&>(*this).getByXDataReference(sid));
}


/*
 * Used by SedListOfSurfaces::get() to lookup a SedSurface based on its
 * YDataReference.
 */
struct SedIdEqYDR
{
  const string& id;
   
  SedIdEqYDR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSurface*>(sb)->getYDataReference() == id);
  }
};


/*
 * Get a SedSurface from the SedListOfSurfaces based on the YDataReference to
 * which it refers.
 */
const SedSurface*
SedListOfSurfaces::getByYDataReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqYDR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSurface*>
    (*result);
}


/*
 * Get a SedSurface from the SedListOfSurfaces based on the YDataReference to
 * which it refers.
 */
SedSurface*
SedListOfSurfaces::getByYDataReference(const std::string& sid)
{
  return const_cast<SedSurface*>(static_cast<const
    SedListOfSurfaces&>(*this).getByYDataReference(sid));
}


/*
 * Used by SedListOfSurfaces::get() to lookup a SedSurface based on its
 * ZDataReference.
 */
struct SedIdEqZDR
{
  const string& id;
   
  SedIdEqZDR (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSurface*>(sb)->getZDataReference() == id);
  }
};


/*
 * Get a SedSurface from the SedListOfSurfaces based on the ZDataReference to
 * which it refers.
 */
const SedSurface*
SedListOfSurfaces::getByZDataReference(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqZDR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSurface*>
    (*result);
}


/*
 * Get a SedSurface from the SedListOfSurfaces based on the ZDataReference to
 * which it refers.
 */
SedSurface*
SedListOfSurfaces::getByZDataReference(const std::string& sid)
{
  return const_cast<SedSurface*>(static_cast<const
    SedListOfSurfaces&>(*this).getByZDataReference(sid));
}


/*
 * Used by SedListOfSurfaces::get() to lookup a SedSurface based on its Style.
 */
struct SedIdEqS
{
  const string& id;
   
  SedIdEqS (const string& id) : id(id) { }
  bool operator() (SedBase* sb)
  {
  return (static_cast<SedSurface*>(sb)->getStyle() == id);
  }
};


/*
 * Get a SedSurface from the SedListOfSurfaces based on the Style to which it
 * refers.
 */
const SedSurface*
SedListOfSurfaces::getByStyle(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEqS(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedSurface*>
    (*result);
}


/*
 * Get a SedSurface from the SedListOfSurfaces based on the Style to which it
 * refers.
 */
SedSurface*
SedListOfSurfaces::getByStyle(const std::string& sid)
{
  return const_cast<SedSurface*>(static_cast<const
    SedListOfSurfaces&>(*this).getByStyle(sid));
}


/*
 * Returns the XML element name of this SedListOfSurfaces object.
 */
const std::string&
SedListOfSurfaces::getElementName() const
{
  static const string name = "listOfSurfaces";
  return name;
}


/*
 * Returns the libSEDML type code for this SedListOfSurfaces object.
 */
int
SedListOfSurfaces::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfSurfaces object.
 */
int
SedListOfSurfaces::getItemTypeCode() const
{
  return SEDML_OUTPUT_SURFACE;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedSurface in this SedListOfSurfaces
 */
SedBase*
SedListOfSurfaces::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "surface")
  {
    object = new SedSurface(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedSurface_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedListOfSurfaces_getSurface(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSurfaces*>(slo)->get(n);
}


/*
 * Get a SedSurface_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedListOfSurfaces_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSurfaces*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedSurface_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedListOfSurfaces_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfSurfaces*>(slo)->remove(n);
}


/*
 * Removes the SedSurface_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedSurface_t*
SedListOfSurfaces_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfSurfaces*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


