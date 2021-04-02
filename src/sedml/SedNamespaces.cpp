/**
 * @file SedNamespaces.cpp
 * @brief Implementation of the SedNamespaces class.
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


#include <sedml/SedNamespaces.h>
#include <sstream>
#include <sedml/common/common.h>
#include <iostream>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */


LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibsedmlInternal */
void 
SedNamespaces::initSedNamespace()
{
  if (mNamespaces != NULL)
    delete mNamespaces;
  mNamespaces = new XMLNamespaces();

  switch (mLevel)
  {
  case 1:
  default:
    switch (mVersion)
    {
    case 1:
      mNamespaces->add(SEDML_XMLNS_L1V1);
      break;
    case 2:
      mNamespaces->add(SEDML_XMLNS_L1V2);
      break;
    case 3:
    default:
      mNamespaces->add(SEDML_XMLNS_L1V3);
      break;
    case 4:
      mNamespaces->add(SEDML_XMLNS_L1V4);
      break;
    }
    break;
  }

  if (mNamespaces->getLength() == 0)
  {
    mLevel = SEDML_INT_MAX;
    mVersion = SEDML_INT_MAX;
    delete mNamespaces;
    mNamespaces = NULL;
  }
}
/** @endcond */


SedNamespaces::SedNamespaces(unsigned int level, unsigned int version)
 : mLevel(level)
  ,mVersion(version)
  ,mNamespaces(NULL)
{
  initSedNamespace();
}


SedNamespaces::~SedNamespaces()
{
  if (mNamespaces != NULL)
    delete mNamespaces;
}


/*
 * Copy constructor; creates a copy of a SedNamespaces.
 */
SedNamespaces::SedNamespaces(const SedNamespaces& orig)
 : mLevel(orig.mLevel)
 , mVersion(orig.mVersion)
 , mNamespaces(NULL)
{
  if(orig.mNamespaces != NULL)
    this->mNamespaces = 
          new XMLNamespaces(*const_cast<SedNamespaces&>(orig).mNamespaces);
}


const List * 
SedNamespaces::getSupportedNamespaces()
{
  List *result = new List();
  result->add(new SedNamespaces(1,1));
  result->add(new SedNamespaces(1,2));
  result->add(new SedNamespaces(1,3));
  result->add(new SedNamespaces(1,4));
  return result;
}


void 
SedNamespaces::freeSedNamespaces(List * supportedNS)
{
  if (supportedNS == NULL) return;
  for (unsigned int i = 0; i < supportedNS->getSize(); i++)
  {
    delete (SedNamespaces*)supportedNS->get(i);
  }
  delete supportedNS;
}

/*
 * Assignment operator for SedNamespaces.
 */
SedNamespaces&
SedNamespaces::operator=(const SedNamespaces& rhs)
{
  if (&rhs != this)
  {
    mLevel   = rhs.mLevel;
    mVersion = rhs.mVersion;
    delete this->mNamespaces;
    if(rhs.mNamespaces != NULL)
      this->mNamespaces = 
            new XMLNamespaces(*const_cast<SedNamespaces&>(rhs).mNamespaces);
    else
      this->mNamespaces = NULL;
  }

  return *this;
}



/*
 * Creates and returns a deep copy of this SedNamespaces.
 */
SedNamespaces *
SedNamespaces::clone () const
{
  return new SedNamespaces(*this);
}


std::string 
SedNamespaces::getSedNamespaceURI(unsigned int level,
                                 unsigned int version)
{
  std::string uri = "";
  switch (level)
  {
  case 1:
  default:
    switch (version)
    {
    case 1:
      uri = SEDML_XMLNS_L1V1;
      break;
    case 2:
      uri = SEDML_XMLNS_L1V2;
      break;
    case 3:
    default:
      uri = SEDML_XMLNS_L1V3;
      break;
    case 4:
      uri = SEDML_XMLNS_L1V4;
      break;
    }
    break;
  }
  return uri;
}


std::string
SedNamespaces::getURI() const
{
  return getSedNamespaceURI(mLevel,mVersion);
}


unsigned int 
SedNamespaces::getLevel()
{
  return mLevel;
}


unsigned int 
SedNamespaces::getLevel() const
{
  return mLevel;
}


unsigned int 
SedNamespaces::getVersion()
{
  return mVersion;
}


unsigned int 
SedNamespaces::getVersion() const
{
  return mVersion;
}


XMLNamespaces * 
SedNamespaces::getNamespaces()
{
  return mNamespaces;
}


const XMLNamespaces * 
SedNamespaces::getNamespaces() const
{
  return mNamespaces;
}


int
SedNamespaces::addNamespaces(const XMLNamespaces * xmlns)
{
  int success = LIBSEDML_OPERATION_SUCCESS;

  if (xmlns == NULL)
    return LIBSEDML_INVALID_OBJECT;

  if (!mNamespaces) 
  {
    initSedNamespace();
  }

  /* check whether the namespace already exists
   * add if it does not
   */
  for (int i = 0; i < xmlns->getLength(); i++)
  {
    if (mNamespaces != NULL && !(mNamespaces->hasNS(xmlns->getURI(i), xmlns->getPrefix(i))))
    {
      success = mNamespaces->add(xmlns->getURI(i), xmlns->getPrefix(i));
    }
  }

  return success;
}


int
SedNamespaces::addNamespace(const std::string &uri, const std::string &prefix)
{
  if (!mNamespaces) 
  {
    initSedNamespace();
  }

  return mNamespaces != NULL ? mNamespaces->add(uri, prefix) : LIBSEDML_INVALID_OBJECT;
}


int
SedNamespaces::removeNamespace(const std::string &uri)
{
  if (!mNamespaces) 
  {
    initSedNamespace();
  }

  return mNamespaces != NULL ? mNamespaces->remove(mNamespaces->getIndex(uri)) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c true if the given
 * URL is one of SED-ML XML namespaces.
 */
bool 
SedNamespaces::isSedNamespace(const std::string& uri)
{
  if (uri == SEDML_XMLNS_L1V1)   return true;

  return false;
}

bool 
SedNamespaces::isValidCombination()
{
  bool valid = true;
  bool sedmlDeclared = false;
  std::string declaredURI("");
  unsigned int version = getVersion();
  XMLNamespaces *xmlns = getNamespaces();

  if (xmlns != NULL)
  {
    int numNS = 0;

    if (xmlns->hasURI(SEDML_XMLNS_L1V1))
    {
      ++numNS;
      declaredURI.assign(SEDML_XMLNS_L1V1);
    }

    if (xmlns->hasURI(SEDML_XMLNS_L1V2))
    {
      ++numNS;
      declaredURI.assign(SEDML_XMLNS_L1V2);
    }

    if (xmlns->hasURI(SEDML_XMLNS_L1V3))
    {
      ++numNS;
      declaredURI.assign(SEDML_XMLNS_L1V3);
    }

    if (xmlns->hasURI(SEDML_XMLNS_L1V4))
    {
      ++numNS;
      declaredURI.assign(SEDML_XMLNS_L1V4);
    }

    // checks if the SED-ML Namespace is explicitly defined.
    for (int i=0; i < xmlns->getLength(); i++)
    {
      if (!declaredURI.empty() && 
                      xmlns->getURI(i) == declaredURI)
      {
        sedmlDeclared = true;
        break;
      }
    }
  }


  switch (getLevel())
  {
    case 1:
     switch (version)
      {
        case 1:
          // the namespaces contains the sedml namespaces
          // check it is the correct ns for the level/version
          if (sedmlDeclared)
          {
            if (declaredURI != string(SEDML_XMLNS_L1V1))
            {
              valid = false;
            }
          }
          break;
        case 2:
          // the namespaces contains the sedml namespaces
          // check it is the correct ns for the level/version
          if (sedmlDeclared)
          {
            if (declaredURI != string(SEDML_XMLNS_L1V2))
            {
              valid = false;
            }
          }
          break;
        case 3:
          // the namespaces contains the sedml namespaces
          // check it is the correct ns for the level/version
          if (sedmlDeclared)
          {
            if (declaredURI != string(SEDML_XMLNS_L1V3))
            {
              valid = false;
            }
          }
          break;
        case 4:
          // the namespaces contains the sedml namespaces
          // check it is the correct ns for the level/version
          if (sedmlDeclared)
          {
            if (declaredURI != string(SEDML_XMLNS_L1V4))
            {
              valid = false;
            }
          }
          break;
        default:
          valid = false;
          break;
        }
      break;
    default:
      valid = false;
      break;
  }

  return valid;
}


/** @cond doxygenLibsedmlInternal */
void 
SedNamespaces::setLevel(unsigned int level)
{
  mLevel = level;
}


void 
SedNamespaces::setVersion(unsigned int version)
{
  mVersion = version;
}


void 
SedNamespaces::setNamespaces(XMLNamespaces * xmlns)
{
  delete mNamespaces;
  if (xmlns != NULL)
    mNamespaces = xmlns->clone();
  else
    mNamespaces = NULL;
}
/** @endcond */

#endif /* __cplusplus */


/** @cond doxygenIgnored */

LIBSEDML_EXTERN
SedNamespaces_t *
SedNamespaces_create(unsigned int level, unsigned int version)
{
  return new SedNamespaces(level, version);
}


LIBSEDML_EXTERN
void
SedNamespaces_free(SedNamespaces_t* ns)
{
  if (ns == NULL) return;
  delete static_cast<SedNamespaces*>(ns);
}


LIBSEDML_EXTERN
unsigned int
SedNamespaces_getLevel(SedNamespaces_t *sedmlns)
{
  return (sedmlns != NULL) ? sedmlns->getLevel() : SEDML_INT_MAX;
}


LIBSEDML_EXTERN
unsigned int
SedNamespaces_getVersion(SedNamespaces_t *sedmlns)
{
  return (sedmlns != NULL) ? sedmlns->getVersion() : SEDML_INT_MAX;
}


LIBSEDML_EXTERN
XMLNamespaces_t *
SedNamespaces_getNamespaces(SedNamespaces_t *sedmlns)
{
  return (sedmlns != NULL) ? sedmlns->getNamespaces() : NULL;
}


LIBSEDML_EXTERN
char *
SedNamespaces_getSedNamespaceURI(unsigned int level, unsigned int version)
{
  return safe_strdup(SedNamespaces::getSedNamespaceURI(level, version).c_str());
}


LIBSEDML_EXTERN
int
SedNamespaces_addNamespaces(SedNamespaces_t *sedmlns,
                             const XMLNamespaces_t * xmlns)
{
  if (sedmlns != NULL)
    return sedmlns->addNamespaces(xmlns);
  else
    return LIBSEDML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedNamespaces_t **
SedNamespaces_getSupportedNamespaces(int *length)
{
  if (length == NULL) return NULL;
   const List* supported = SedNamespaces::getSupportedNamespaces();
  
   *length = (int) supported->getSize();
  SedNamespaces_t ** result = (SedNamespaces_t**)malloc(sizeof(SedNamespaces_t*)*((unsigned long)*length));
  memset(result, 0, sizeof(SedNamespaces_t*)*((unsigned long)*length));
  for (int i = 0; i < *length; i++)
  {
    result[i] = ((SedNamespaces*)supported->get((unsigned int)i))->clone();
  }
  SedNamespaces::freeSedNamespaces(const_cast<List*>(supported));
  return result;
}
/** @endcond */

LIBSEDML_CPP_NAMESPACE_END

