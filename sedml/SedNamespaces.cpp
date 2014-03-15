/**
 * @file    SedNamespaces.cpp
 * @brief   SedNamespaces class to store level/version and namespace 
 * 
 * <!--------------------------------------------------------------------------
 *
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on 
 * github: https://github.com/fbergmann/libSEDML/
 * 
 * 
 * Copyright (c) 2013-2014, Frank T. Bergmann  
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ---------------------------------------------------------------------- -->
 */

#include <sstream>
#include <iostream>
 
#include <sedml/common/common.h>
#include <sedml/common/operationReturnValues.h>
#include <sbml/util/List.h>
#include <sedml/SedNamespaces.h>
#include <sedml/SedConstructorException.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */


LIBSEDML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libsbml-internal */
void 
SedNamespaces::initSedNamespace()
{
  mNamespaces = new XMLNamespaces();

  switch (mLevel)
  {
  case 1:
    switch (mVersion)
    {
    case 1:
      mNamespaces->add(SEDML_XMLNS_L1V1);
	 break;
    case 2:
      mNamespaces->add(SEDML_XMLNS_L1V2);
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


SedNamespaces::SedNamespaces(unsigned int level, unsigned int version)
 : mLevel(level)
  ,mVersion(version)
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
{
  if (&orig == NULL)
  {
    throw SedConstructorException("Null argument to copy constructor");
  }
  else
  {
    mLevel   = orig.mLevel;
    mVersion = orig.mVersion;
 
    if(orig.mNamespaces != NULL)
      this->mNamespaces = 
            new XMLNamespaces(*const_cast<SedNamespaces&>(orig).mNamespaces);
    else
      this->mNamespaces = NULL;
  }
}


const List * 
SedNamespaces::getSupportedNamespaces()
{
  List *result = new List();
  result->add(new SedNamespaces(1,1));
  result->add(new SedNamespaces(1,2));
  return result;
}

/*
 * Assignment operator for SedNamespaces.
 */
SedNamespaces&
SedNamespaces::operator=(const SedNamespaces& rhs)
{
  if (&rhs == NULL)
  {
    throw SedConstructorException("Null argument to assignment operator");
  }
  else if (&rhs != this)
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
    if (version == 1)
	uri = SEDML_XMLNS_L1V1;
    else 
	uri = SEDML_XMLNS_L1V2;
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
    if (!(mNamespaces->hasNS(xmlns->getURI(i), xmlns->getPrefix(i))))
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

  return mNamespaces->add(uri, prefix);
}


int
SedNamespaces::removeNamespace(const std::string &uri)
{
  if (!mNamespaces) 
  {
    initSedNamespace();
  }

  return mNamespaces->remove(mNamespaces->getIndex(uri));
}


/*
 * Predicate returning @c true if the given
 * URL is one of Sed XML namespaces.
 */
bool 
SedNamespaces::isSedNamespace(const std::string& uri)
{
  if (uri ==SEDML_XMLNS_L1)   return true;
  if (uri ==SEDML_XMLNS_L1V2)   return true;

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
    // 
    // checks defined Sed XMLNamespace
    // returns false if different Sed XMLNamespaces 
    // (e.g.SEDML_XMLNS_L2V1 andSEDML_XMLNS_L2V3) are defined.
    //
    int numNS = 0;

    if (xmlns->hasURI(SEDML_XMLNS_L1))
    {
      // checks different Sed XMLNamespaces
      if (numNS > 0) return false;
      ++numNS;
      declaredURI.assign(SEDML_XMLNS_L1);
    }
    if (xmlns->hasURI(SEDML_XMLNS_L1V2))
    {
      // checks different Sed XMLNamespaces
      if (numNS > 0) return false;
      ++numNS;
      declaredURI.assign(SEDML_XMLNS_L1V2);
    }

    // checks if the Sed Namespace is explicitly defined.
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
          // the namespaces contains the sbml namespaces
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
          // the namespaces contains the sbml namespaces
          // check it is the correct ns for the level/version
          if (sedmlDeclared)
          {
            if (declaredURI != string(SEDML_XMLNS_L1V2))
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

/** @cond doxygen-c-only */

/**
 * Creates a new SedNamespaces_t structure corresponding to the given Sed
 * @p level and @p version.
 *
 * SedNamespaces objects are used in libSed to communicate Sed Level
 * and Version data between constructors and other methods.  The
 * SedNamespaces object class tracks 3-tuples (triples) consisting of
 * Sed Level, Version, and the corresponding Sed XML namespace.  Most
 * constructors for Sed objects in libSed take a SedNamespaces object
 * as an argument, thereby allowing the constructor to produce the proper
 * combination of attributes and other internal data structures for the
 * given Sed Level and Version.
 *
 * The plural name "SedNamespaces" is not a mistake, because in Sed
 * Level&nbsp;3, objects may have extensions added by Level&nbsp;3
 * packages used by a given model; however, until the introduction of
 * Sed Level&nbsp;3, the SedNamespaces object only records one Sed
 * Level/Version/namespace combination at a time.
 *
 * @param level the Sed level
 * @param version the Sed version
 *
 * @return SedNamespaces_t structure created
 *
 * @if notcpp @htmlinclude warn-default-args-in-docs.html @endif@~
 */

LIBSEDML_EXTERN
SedNamespaces_t *
SedNamespaces_create(unsigned int level, unsigned int version)
{
  return new SedNamespaces(level, version);
}


/**
 * Get the Sed Level of this SedNamespaces_t structure.
 *
 * @param sbmlns the SedNamespaces_t structure to query
 *
 * @return the Sed Level of this SedNamespaces_t structure.
 */
LIBSEDML_EXTERN
unsigned int
SedNamespaces_getLevel(SedNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getLevel() :SEDML_INT_MAX;
}


/**
 * Get the Sed Version of this SedNamespaces_t structure.
 *
 * @param sbmlns the SedNamespaces_t structure to query
 *
 * @return the Sed Version of this SedNamespaces_t structure.
 */
LIBSEDML_EXTERN
unsigned int
SedNamespaces_getVersion(SedNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getVersion() :SEDML_INT_MAX;
}


/**
 * Get the Sed Version of this SedNamespaces_t structure.
 *
 * @param sbmlns the SedNamespaces_t structure to query
 *
 * @return the XMLNamespaces_t structure of this SedNamespaces_t structure.
 */
LIBSEDML_EXTERN
XMLNamespaces_t *
SedNamespaces_getNamespaces(SedNamespaces_t *sbmlns)
{
  return (sbmlns != NULL) ? sbmlns->getNamespaces() : NULL;
}


/**
 * Returns a string representing the Sed XML namespace for the 
 * given @p level and @p version of Sed.
 *
 * @param level the Sed level
 * @param version the Sed version
 *
 * @return a string representing the Sed namespace that reflects the
 * Sed Level and Version specified.
 */
LIBSEDML_EXTERN
char *
SedNamespaces_getSedNamespaceURI(unsigned int level, unsigned int version)
{
  return safe_strdup(SedNamespaces::getSedNamespaceURI(level, version).c_str());
}


/**
 * Add the XML namespaces list to the set of namespaces
 * within this SedNamespaces_t structure.
 * 
 * @param sbmlns the SedNamespaces_t structure to add to
 * @param xmlns the XML namespaces to be added.
 */
LIBSEDML_EXTERN
int
SedNamespaces_addNamespaces(SedNamespaces_t *sbmlns,
                             const XMLNamespaces_t * xmlns)
{
  if (sbmlns != NULL)
    return sbmlns->addNamespaces(xmlns);
  else
    return LIBSEDML_INVALID_OBJECT;
}

/**
 * Returns an array of Sed Namespaces supported by this version of 
 * LibSed. 
 *
 * @param length an integer holding the length of the array
 * @return an array of Sed namespaces, or @c NULL if length is @c NULL. The array 
 *         has to be freed by the caller.
 */
LIBSEDML_EXTERN
SedNamespaces_t **
SedNamespaces_getSupportedNamespaces(int *length)
{
  if (length == NULL) return NULL;
   const List* supported = SedNamespaces::getSupportedNamespaces();
  
   *length = (int) supported->getSize();
  SedNamespaces_t ** result = (SedNamespaces_t**)malloc(sizeof(SedNamespaces_t*)*(*length));
  memset(result, 0, sizeof(SedNamespaces_t*)*(*length));
  for (int i = 0; i < *length; i++)
  {
    result[i] = ((SedNamespaces*)supported->get(i))->clone();
  }
  return result;
}

/** @endcond */

LIBSEDML_CPP_NAMESPACE_END

