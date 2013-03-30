/**
 * @file    SedMLNamespaces.cpp
 * @brief   SedMLNamespaces class to store level/version and namespace 
 * @author  Sarah Keating
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSedML.  Please visit http://sbml.org for more
 * information about SedML, and the latest version of libSedML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->
 */

#include <sstream>
#include <iostream>
 
#include <sedml/common/common.h>
#include <sedml/common/operationReturnCodes.h>
#include <sbml/util/List.h>
#include <sedml/SedMLNamespaces.h>
#include <sedml/SedMLConstructorException.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */


LIBSEDML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libsbml-internal */
void 
SedMLNamespaces::initSedMLNamespace()
{
  mNamespaces = new XMLNamespaces();

  switch (mLevel)
  {
  case 1:
    switch (mVersion)
    {
    case 1:
    case 2:
      mNamespaces->add(SEDML_XMLNS_L1);
      break;
    }
    break;	
  }

  if (mNamespaces->getLength() == 0)
  {
    mLevel =SEDML_INT_MAX;
    mVersion =SEDML_INT_MAX;
    delete mNamespaces;
    mNamespaces = NULL;
  }
}
/** @endcond */


SedMLNamespaces::SedMLNamespaces(unsigned int level, unsigned int version)
 : mLevel(level)
  ,mVersion(version)
{
  initSedMLNamespace();
}

SedMLNamespaces::~SedMLNamespaces()
{
  if (mNamespaces != NULL)
    delete mNamespaces;
}


/*
 * Copy constructor; creates a copy of a SedMLNamespaces.
 */
SedMLNamespaces::SedMLNamespaces(const SedMLNamespaces& orig)
{
  if (&orig == NULL)
  {
    throw SedMLConstructorException("Null argument to copy constructor");
  }
  else
  {
    mLevel   = orig.mLevel;
    mVersion = orig.mVersion;
 
    if(orig.mNamespaces != NULL)
      this->mNamespaces = 
            new XMLNamespaces(*const_cast<SedMLNamespaces&>(orig).mNamespaces);
    else
      this->mNamespaces = NULL;
  }
}


const List * 
SedMLNamespaces::getSupportedNamespaces()
{
  List *result = new List();
  result->add(new SedMLNamespaces(1,1));
  return result;
}

/*
 * Assignment operator for SedMLNamespaces.
 */
SedMLNamespaces&
SedMLNamespaces::operator=(const SedMLNamespaces& rhs)
{
  if (&rhs == NULL)
  {
    throw SedMLConstructorException("Null argument to assignment operator");
  }
  else if (&rhs != this)
  {
    mLevel   = rhs.mLevel;
    mVersion = rhs.mVersion;
    delete this->mNamespaces;
    if(rhs.mNamespaces != NULL)
      this->mNamespaces = 
            new XMLNamespaces(*const_cast<SedMLNamespaces&>(rhs).mNamespaces);
    else
      this->mNamespaces = NULL;
  }

  return *this;
}



/*
 * Creates and returns a deep copy of this SedMLNamespaces.
 */
SedMLNamespaces *
SedMLNamespaces::clone () const
{
  return new SedMLNamespaces(*this);
}


std::string 
SedMLNamespaces::getSedMLNamespaceURI(unsigned int level,
                                 unsigned int version)
{
  std::string uri = "";
  switch (level)
  {
  case 1:
    uri =SEDML_XMLNS_L1;
    break;
  }
  return uri;
}


std::string
SedMLNamespaces::getURI() const
{
  return getSedMLNamespaceURI(mLevel,mVersion);
}


unsigned int 
SedMLNamespaces::getLevel()
{
  return mLevel;
}


unsigned int 
SedMLNamespaces::getLevel() const
{
  return mLevel;
}


unsigned int 
SedMLNamespaces::getVersion()
{
  return mVersion;
}


unsigned int 
SedMLNamespaces::getVersion() const
{
  return mVersion;
}


XMLNamespaces * 
SedMLNamespaces::getNamespaces()
{
  return mNamespaces;
}


const XMLNamespaces * 
SedMLNamespaces::getNamespaces() const
{
  return mNamespaces;
}


int
SedMLNamespaces::addNamespaces(const XMLNamespaces * xmlns)
{
  int success = LIBSEDML_OPERATION_SUCCESS;

  if (xmlns == NULL)
    return LIBSEDML_INVALID_OBJECT;

  if (!mNamespaces) 
  {
    initSedMLNamespace();
  }

  /* check whether the namespace already exists
   * add if it does not
   */
  for (int i = 0; i < xmlns->getLength(); i++)
  {
    if (!(mNamespaces->hasNS(xmlns->getURI(i), xmlns->getPrefix(i))))
    {
      success = mNamespaces->add(xmlns->getURI(i), xmlns->getPrefix(i));
    }
  }

  return success;
}

int
SedMLNamespaces::addNamespace(const std::string &uri, const std::string &prefix)
{
  if (!mNamespaces) 
  {
    initSedMLNamespace();
  }

  return mNamespaces->add(uri, prefix);
}


int
SedMLNamespaces::removeNamespace(const std::string &uri)
{
  if (!mNamespaces) 
  {
    initSedMLNamespace();
  }

  return mNamespaces->remove(mNamespaces->getIndex(uri));
}


/*
 * Predicate returning @c true if the given
 * URL is one of SedML XML namespaces.
 */
bool 
SedMLNamespaces::isSedMLNamespace(const std::string& uri)
{
  if (uri ==SEDML_XMLNS_L1)   return true;

  return false;
}

bool 
SedMLNamespaces::isValidCombination()
{
  bool valid = true;
  bool sedmlDeclared = false;
  std::string declaredURI("");
  unsigned int version = getVersion();
  XMLNamespaces *xmlns = getNamespaces();

  if (xmlns != NULL)
  {
    // 
    // checks defined SedML XMLNamespace
    // returns false if different SedML XMLNamespaces 
    // (e.g.SEDML_XMLNS_L2V1 andSEDML_XMLNS_L2V3) are defined.
    //
    int numNS = 0;

    if (xmlns->hasURI(SEDML_XMLNS_L1))
    {
      // checks different SedML XMLNamespaces
      if (numNS > 0) return false;
      ++numNS;
      declaredURI.assign(SEDML_XMLNS_L1);
    }

    // checks if the SedML Namespace is explicitly defined.
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
        case 2:
          // the namespaces contains the sbml namespaces
          // check it is the correct ns for the level/version
          if (sedmlDeclared)
          {
            if (declaredURI != string(SEDML_XMLNS_L1))
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


/** @cond doxygen-libsbml-internal */
void 
SedMLNamespaces::setLevel(unsigned int level)
{
  mLevel = level;
}


void 
SedMLNamespaces::setVersion(unsigned int version)
{
  mVersion = version;
}


void 
SedMLNamespaces::setNamespaces(XMLNamespaces * xmlns)
{
  delete mNamespaces;
  if (xmlns != NULL)
    mNamespaces = xmlns->clone();
  else
    mNamespaces = NULL;
}
/** @endcond */

/** @cond doxygen-c-only */

/**
 * Creates a new SedMLNamespaces_t structure corresponding to the given SedML
 * @p level and @p version.
 *
 * SedMLNamespaces objects are used in libSedML to communicate SedML Level
 * and Version data between constructors and other methods.  The
 * SedMLNamespaces object class tracks 3-tuples (triples) consisting of
 * SedML Level, Version, and the corresponding SedML XML namespace.  Most
 * constructors for SedML objects in libSedML take a SedMLNamespaces object
 * as an argument, thereby allowing the constructor to produce the proper
 * combination of attributes and other internal data structures for the
 * given SedML Level and Version.
 *
 * The plural name "SedMLNamespaces" is not a mistake, because in SedML
 * Level&nbsp;3, objects may have extensions added by Level&nbsp;3
 * packages used by a given model; however, until the introduction of
 * SedML Level&nbsp;3, the SedMLNamespaces object only records one SedML
 * Level/Version/namespace combination at a time.
 *
 * @param level the SedML level
 * @param version the SedML version
 *
 * @return SedMLNamespaces_t structure created
 *
 * @if notcpp @htmlinclude warn-default-args-in-docs.html @endif@~
 */

LIBSEDML_EXTERN
SedMLNamespaces_t *
SedMLNamespaces_create(unsigned int level, unsigned int version)
{
  return new SedMLNamespaces(level, version);
}


/**
 * Get the SedML Level of this SedMLNamespaces_t structure.
 *
 * @param sbmlns the SedMLNamespaces_t structure to query
 *
 * @return the SedML Level of this SedMLNamespaces_t structure.
 */
LIBSEDML_EXTERN
unsigned int
SedMLNamespaces_getLevel(SedMLNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getLevel() :SEDML_INT_MAX;
}


/**
 * Get the SedML Version of this SedMLNamespaces_t structure.
 *
 * @param sbmlns the SedMLNamespaces_t structure to query
 *
 * @return the SedML Version of this SedMLNamespaces_t structure.
 */
LIBSEDML_EXTERN
unsigned int
SedMLNamespaces_getVersion(SedMLNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getVersion() :SEDML_INT_MAX;
}


/**
 * Get the SedML Version of this SedMLNamespaces_t structure.
 *
 * @param sbmlns the SedMLNamespaces_t structure to query
 *
 * @return the XMLNamespaces_t structure of this SedMLNamespaces_t structure.
 */
LIBSEDML_EXTERN
XMLNamespaces_t *
SedMLNamespaces_getNamespaces(SedMLNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getNamespaces() : NULL;
}


/**
 * Returns a string representing the SedML XML namespace for the 
 * given @p level and @p version of SedML.
 *
 * @param level the SedML level
 * @param version the SedML version
 *
 * @return a string representing the SedML namespace that reflects the
 * SedML Level and Version specified.
 */
LIBSEDML_EXTERN
char *
SedMLNamespaces_getSedMLNamespaceURI(unsigned int level, unsigned int version)
{
  return safe_strdup(SedMLNamespaces::getSedMLNamespaceURI(level, version).c_str());
}


/**
 * Add the XML namespaces list to the set of namespaces
 * within this SedMLNamespaces_t structure.
 * 
 * @param sbmlns the SedMLNamespaces_t structure to add to
 * @param xmlns the XML namespaces to be added.
 */
LIBSEDML_EXTERN
int
SedMLNamespaces_addNamespaces(SedMLNamespaces_t *sbmlns,
                             const XMLNamespaces_t * xmlns)
{
  if (sbmlns != NULL)
    return sbmlns->addNamespaces(xmlns);
  else
    return LIBSEDML_INVALID_OBJECT;
}

/**
 * Returns an array of SedML Namespaces supported by this version of 
 * LibSedML. 
 *
 * @param length an integer holding the length of the array
 * @return an array of SedML namespaces, or @c NULL if length is @c NULL. The array 
 *         has to be freed by the caller.
 */
LIBSEDML_EXTERN
SedMLNamespaces_t **
SedMLNamespaces_getSupportedNamespaces(int *length)
{
  if (length == NULL) return NULL;
   const List* supported = SedMLNamespaces::getSupportedNamespaces();
  
   *length = (int) supported->getSize();
  SedMLNamespaces_t ** result = (SedMLNamespaces_t**)malloc(sizeof(SedMLNamespaces_t*)*(*length));
  memset(result, 0, sizeof(SedMLNamespaces_t*)*(*length));
  for (int i = 0; i < *length; i++)
  {
    result[i] = ((SedMLNamespaces*)supported->get(i))->clone();
  }
  return result;
}

/** @endcond */

LIBSEDML_CPP_NAMESPACE_END

