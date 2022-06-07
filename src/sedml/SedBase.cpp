/**
 * @file SedBase.cpp
 * @brief Implementation of the SedBase class.
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


#include <sstream>
#include <vector>

#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>
#include <sbml/xml/XMLOutputStream.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLNode.h>

#include <sbml/util/util.h>

#include <sedml/SedError.h>
#include <sedml/SedErrorLog.h>
#include <sedml/SedDocument.h>
#include <sedml/SedListOf.h>
#include <sedml/SedBase.h>


/** @cond doxygenIgnored */
using namespace std;
/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

SedBase*
SedBase::getElementBySId(const std::string& id)
{
  if (id.empty()) return NULL;

  return NULL;
}


const SedBase*
SedBase::getElementBySId(const std::string& id) const 
{
  if (id.empty()) return NULL;

  return NULL;
}


SedBase*
SedBase::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty()) return NULL;

  return NULL;
}

const SedBase*
SedBase::getElementByMetaId(const std::string& metaid) const 
{
  if (metaid.empty()) return NULL;

  return NULL;
}


List*
SedBase::getAllElements(SedElementFilter* filter)
{
  return NULL;
}

/** @cond doxygenLibsedmlInternal */
/*
 * Creates a new SedBase object with the given level and version.
 * Only subclasses may create SedBase objects.
 */
SedBase::SedBase (unsigned int level, unsigned int version) 
 : mMetaId ("")
 , mId ("")
 , mName("")
 , mIdAllowedPreV4(false)
 , mNameAllowedPreV4(false)
 , mNotes(NULL)
 , mAnnotation( NULL )
 , mSed      ( NULL )
 , mSedNamespaces (NULL)
 , mUserData(NULL)
 , mLine      ( 0 )
 , mColumn    ( 0 )
 , mParentSedObject (NULL)
  , mHasBeenDeleted(false)
  , mEmptyString("")
 , mURI("")
{
  mSedNamespaces = new SedNamespaces(level, version);

  //
  // Sets the XMLNS URI of corresponding SED-ML Level/Version to
  // the element namespace (mURI) of this object.
  //
  //
  setElementNamespace(mSedNamespaces->getURI());
}



/*
 * Creates a new SedBase object with the given SedNamespaces.
 * Only subclasses may create SedBase objects.
 */
SedBase::SedBase (SedNamespaces *sedmlns) 
 : mMetaId("")
 , mId("")
 , mName("")
 , mIdAllowedPreV4(false)
 , mNameAllowedPreV4(false)
 , mNotes(NULL)
 , mAnnotation(NULL)
 , mSed(NULL)
 , mSedNamespaces(NULL)
 , mUserData(NULL)
 , mLine(0)
 , mColumn(0)
 , mParentSedObject(NULL)
 , mHasBeenDeleted(false)
 , mEmptyString("")
 , mURI("")
{
  if (!sedmlns)
  {
    std::string err("SedBase::SedBase(SedNamespaces*) : SedNamespaces is null");
    throw SedConstructorException(err);
  }
  mSedNamespaces = sedmlns->clone();

  setElementNamespace(static_cast<SedNamespaces>(*mSedNamespaces).getURI());
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * Copy constructor. Creates a copy of this SedBase object.
 */
SedBase::SedBase(const SedBase& orig)
  : mMetaId (orig.mMetaId)
  , mId (orig.mId)
  , mName(orig.mName)
  , mIdAllowedPreV4(orig.mIdAllowedPreV4)
  , mNameAllowedPreV4(orig.mNameAllowedPreV4)
  , mNotes (NULL)
  , mAnnotation (NULL)
  , mSed (NULL)
  , mSedNamespaces(NULL)
  , mUserData(orig.mUserData)
  , mLine(orig.mLine)
  , mColumn(orig.mColumn)
  , mParentSedObject(NULL)
  , mURI(orig.mURI)
{
  if(orig.mNotes != NULL)
    this->mNotes = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(*const_cast<SedBase&>(orig).getNotes());
  else
    this->mNotes = NULL;

  if(orig.mAnnotation != NULL)
    this->mAnnotation = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(*const_cast<SedBase&>(orig).mAnnotation);
  else
    this->mAnnotation = NULL;

  if(orig.getSedNamespaces() != NULL)
    this->mSedNamespaces =
    new SedNamespaces(*const_cast<SedBase&>(orig).getSedNamespaces());
  else
    this->mSedNamespaces = NULL;

  this->mHasBeenDeleted = false;
}
/** @endcond */


/*
 * Destroy this SedBase object.
 */
SedBase::~SedBase ()
{
  if (mNotes != NULL)       delete mNotes;
  if (mAnnotation != NULL)  delete mAnnotation;
  if (mSedNamespaces != NULL)  delete mSedNamespaces;
}

/*
 * Assignment operator
 */
SedBase& SedBase::operator=(const SedBase& rhs)
{
  if(&rhs!=this)
  {
    this->mMetaId = rhs.mMetaId;
    this->mId = rhs.mId;
    this->mName = rhs.mName;
    this->mIdAllowedPreV4 = rhs.mIdAllowedPreV4;
    this->mNameAllowedPreV4 = rhs.mNameAllowedPreV4;

    delete this->mNotes;

    if(rhs.mNotes != NULL)
      this->mNotes = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(*const_cast<SedBase&>(rhs).getNotes());
    else
      this->mNotes = NULL;

    delete this->mAnnotation;

    if(rhs.mAnnotation != NULL)
      this->mAnnotation = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(*const_cast<SedBase&>(rhs).mAnnotation);
    else
      this->mAnnotation = NULL;

    this->mSed       = rhs.mSed;
    this->mLine       = rhs.mLine;
    this->mColumn     = rhs.mColumn;
    this->mParentSedObject = rhs.mParentSedObject;
    this->mUserData   = rhs.mUserData;

    delete this->mSedNamespaces;

    if(rhs.mSedNamespaces != NULL)
      this->mSedNamespaces =
      new SedNamespaces(*const_cast<SedBase&>(rhs).mSedNamespaces);
    else
      this->mSedNamespaces = NULL;


    this->mURI = rhs.mURI;
  }

  return *this;
}


/*
 * @return the metaid of this SED-ML object.
 */
const string&
SedBase::getMetaId () const
{
  return mMetaId;
}


/*
 * @return the metaid of this SED-ML object.
 */
string&
SedBase::getMetaId ()
{
  return mMetaId;
}


const string&
SedBase::getId() const
{
    if (!mIdAllowedPreV4 && getVersion() < 4 && getLevel() == 1) {
        static string empty;
        return empty;
    }
    return mId;
}

const std::string& SedBase::getName() const
{
    if (!mNameAllowedPreV4 && getVersion() < 4 && getLevel() == 1) {
        static string empty;
        return empty;
    }
    return mName;
}


/*
 * @return the notes of this SED-ML object.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SedBase::getNotes()
{
  return mNotes;
}


const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SedBase::getNotes() const
{
  return mNotes;
}


/*
 * @return the notes of this SED-ML object by string.
 */
std::string
SedBase::getNotesString()
{
  return LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertXMLNodeToString(mNotes);
}


std::string
SedBase::getNotesString() const
{
  return LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertXMLNodeToString(mNotes);
}


/*
 * @return the annotation of this SED-ML object.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SedBase::getAnnotation ()
{
  return mAnnotation;
}


const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SedBase::getAnnotation () const
{
  return const_cast<SedBase *>(this)->getAnnotation();
}


/*
 * @return the annotation of this SED-ML object by string.
 */
std::string
SedBase::getAnnotationString ()
{
  return LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertXMLNodeToString(getAnnotation());
}


std::string
SedBase::getAnnotationString () const
{
  return LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertXMLNodeToString(getAnnotation());
}


/** @cond doxygenLibsedmlInternal */
std::string
SedBase::getURI() const
{
  const SedDocument* doc = getSedDocument();

  if (doc == NULL)
    return getElementNamespace();

  SedNamespaces* sedmlns = doc->getSedNamespaces();

  if (sedmlns == NULL)
    return getElementNamespace();

  return getElementNamespace();
}
/** @endcond */


void *
SedBase::getUserData() const
{
  return this->mUserData;
}


int
SedBase::setUserData(void *userData)
{
  this->mUserData = userData;
  if (userData == NULL && mUserData == NULL)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (mUserData != NULL)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}

bool
SedBase::isSetUserData() const
{
  if (mUserData != NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int
SedBase::unsetUserData()
{
  this->mUserData = NULL;
  if (mUserData == NULL)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}

/*
 * @return the Namespaces associated with this SED-ML object
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SedBase::getNamespaces()
{
  if (mSed != NULL)
    return mSed->getSedNamespaces()->getNamespaces();
  else
    return mSedNamespaces->getNamespaces();
}


/*
 * @return the Namespaces associated with this SED-ML object
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SedBase::getElementNamespaces() const
{
  if (mSedNamespaces == NULL) return NULL;
  return mSedNamespaces->getNamespaces();
}

const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SedBase::getNamespaces() const
{
  if (mSed != NULL)
    return mSed->getSedNamespaces()->getNamespaces();
  else
    return mSedNamespaces->getNamespaces();
}


/*
 * @return the parent SedDocument of this SED-ML object.
 */
const SedDocument*
SedBase::getSedDocument () const
{
  if (mSed != NULL)
  {
    // if the doc object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mSed->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mSed;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mSed;
}

/*
 * @return the parent SedDocument of this SED-ML object.
 */
SedDocument*
SedBase::getSedDocument ()
{
  if (mSed != NULL)
  {
    // if the doc object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mSed->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mSed;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }
  return mSed;
}
SedBase*
SedBase::getParentSedObject ()
{
  if (mParentSedObject != NULL)
  {
    // if the parent object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mParentSedObject->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mParentSedObject;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mParentSedObject;
}

const SedBase*
SedBase::getParentSedObject () const
{
  if (mParentSedObject != NULL)
  {
    // if the parent object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mParentSedObject->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mParentSedObject;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mParentSedObject;
}


/*
 * @return the line number of this SED-ML object.
 */
unsigned int
SedBase::getLine () const
{
  return mLine;
}


/*
 * @return the column number of this SED-ML object.
 */
unsigned int
SedBase::getColumn () const
{
  return mColumn;
}


/*
 * @return true if the metaid of this SED-ML object is set, false
 * otherwise.
 */
bool
SedBase::isSetMetaId () const
{
  return (mMetaId.empty() == false);
}


bool
SedBase::isSetId() const
{
  return (getId().empty() == false);
}

bool SedBase::isSetName() const
{
  return (getName().empty() == false);
}


/*
 * @return true if the notes of this SED-ML object is set, false
 * otherwise.
 */
bool
SedBase::isSetNotes () const
{
  return (mNotes != NULL);
}


/*
 * @return true if the annotation of this SED-ML object is set,
 * false otherwise.
 */
bool
SedBase::isSetAnnotation () const
{
  return (mAnnotation != NULL);
}


/*
 * Sets the metaid field of the given SED-ML object to a copy of metaid.
 */
int
SedBase::setMetaId (const std::string& metaid)
{
  if (metaid.empty())
  {
    mMetaId.erase();
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (!(SyntaxChecker::isValidXMLID(metaid)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mMetaId = metaid;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}

/*
 * Sets the id field of the given SED-ML object to a copy of sid.
 */
int
SedBase::setId (const std::string& sid)
{
  if (sid.empty())
  {
    mId.erase();
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (!(SyntaxChecker::isValidXMLID(sid)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else if (!mIdAllowedPreV4 && getVersion() < 4 && getLevel() == 1)
  {
      return LIBSEDML_UNEXPECTED_ATTRIBUTE;
  }
  mId = sid;
  return LIBSEDML_OPERATION_SUCCESS;
}

int SedBase::setName(const std::string& name)
{
    if (name.empty())
    {
        mName.erase();
        return LIBSEDML_OPERATION_SUCCESS;
    }
    else if (!mNameAllowedPreV4 && getVersion() < 4 && getLevel() == 1)
    {
        return LIBSEDML_UNEXPECTED_ATTRIBUTE;
    }
    mName = name;
    return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the annotation of this SED-ML object to a copy of annotation.
 */
int
SedBase::setAnnotation (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation)
{
  if (annotation == NULL)
  {
    delete mAnnotation;
    mAnnotation = NULL;
  }

  if (mAnnotation != annotation)
  {
    delete mAnnotation;

    mAnnotation = annotation->clone();
  }

  return LIBSEDML_OPERATION_SUCCESS;
}

/*
 * Sets the annotation (by string) of this SED-ML object to a copy of annotation.
 */
int
SedBase::setAnnotation (const std::string& annotation)
{
  
  int success = LIBSEDML_OPERATION_FAILED;
  
  if(annotation.empty())
  {
    unsetAnnotation();
    return LIBSEDML_OPERATION_SUCCESS;
  }
  
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annt_xmln;
  
  // you might not have a document !!
  if (getSedDocument() != NULL)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation);
  }
  
  if(annt_xmln != NULL)
  {
    success = setAnnotation(annt_xmln);
    delete annt_xmln;
  }
  return success;  
}


/*
 * Appends annotation to the existing annotations.
 * This allows other annotations to be preserved whilst
 * adding additional information.
 */
int
SedBase::appendAnnotation (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation)
{
  int success = LIBSEDML_OPERATION_FAILED;
  unsigned int duplicates = 0;

  if(annotation == NULL)
    return LIBSEDML_OPERATION_SUCCESS;

  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* new_annotation = NULL;
  const string&  name = annotation->getName();

  // check for annotation tags and add if necessary
  if (name != "annotation")
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken ann_t = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple("annotation", "", ""), LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes());
    new_annotation = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(ann_t);
    new_annotation->addChild(*annotation);
  }
  else
  {
    new_annotation = annotation->clone();
  }


  if (mAnnotation != NULL)
  {
    // if mAnnotation is just <annotation/> need to tell
    // it to no longer be an end
    if (mAnnotation->isEnd())
    {
      mAnnotation->unsetEnd();
    }


    // create a list of existing top level ns
      vector<string> topLevelNs;
    unsigned int i = 0;
    for(i = 0; i < mAnnotation->getNumChildren(); i++)
    {
          topLevelNs.push_back(mAnnotation->getChild(i).getName());
    }



    for(i = 0; i < new_annotation->getNumChildren(); i++)
    {
          if (find(topLevelNs.begin(), topLevelNs.end(), (new_annotation->getChild(i).getName())) != topLevelNs.end())
      {
        mAnnotation->addChild(new_annotation->getChild(i));
      }
      else
      {
        duplicates++;
      }
    }

    delete new_annotation;

    if (duplicates > 0)
    {
      success = LIBSEDML_DUPLICATE_ANNOTATION_NS;
    }
    else
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode *copy = mAnnotation->clone();
      success = setAnnotation(copy);
      delete copy;
    }


  }
  else
  {
    success = setAnnotation(new_annotation);

    delete new_annotation;
  }

  return success;
}

/*
 * Appends annotation (by string) to the existing annotations.
 * This allows other annotations to be preserved whilst
 * adding additional information.
 */
int
SedBase::appendAnnotation (const std::string& annotation)
{
  int success = LIBSEDML_OPERATION_FAILED;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annt_xmln;
  if (getSedDocument() != NULL)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation);
  }

  if(annt_xmln != NULL)
  {
    success = appendAnnotation(annt_xmln);
    delete annt_xmln;
  }

  return success;
}


int
SedBase::removeTopLevelAnnotationElement(const std::string elementName,
    const std::string elementURI)
{

  int success = LIBSEDML_OPERATION_FAILED;
  if (mAnnotation == NULL)
  {
    success = LIBSEDML_OPERATION_SUCCESS;
    return success;
  }

  int index = mAnnotation->getIndex(elementName);
  if (index < 0)
  {
    // the annotation does not have a child of this name
    success = LIBSEDML_ANNOTATION_NAME_NOT_FOUND;
    return success;
  }
  else
  {
    // check uri matches
    if (elementURI.empty() == false)
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode child = mAnnotation->getChild(index);
      std::string prefix = child.getPrefix();

      if (prefix.empty() == false
        && elementURI != child.getNamespaceURI(prefix))
      {
        success = LIBSEDML_ANNOTATION_NS_NOT_FOUND;
        return success;
      }
      else
      {
        bool match = false;
        int n = 0;

        while (match == false && n < child.getNamespacesLength())
        {
          if (elementURI == child.getNamespaceURI(n))
          {
            match = true;
          }
          n++;
        }

        if (match == false)
        {
          success = LIBSEDML_ANNOTATION_NS_NOT_FOUND;
          return success;
        }
      }
    }

    // remove the annotation at the index corresponding to the name
    delete mAnnotation->removeChild(index);

      if (mAnnotation->getNumChildren() == 0)
        {
          delete mAnnotation;
          mAnnotation = NULL;
        }

    // check success
    if (mAnnotation == NULL || mAnnotation->getIndex(elementName) < 0)
    {
      success = LIBSEDML_OPERATION_SUCCESS;
    }
  }

  return success;
}


int
SedBase::replaceTopLevelAnnotationElement(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation)
{
  int success = LIBSEDML_OPERATION_FAILED;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode * replacement = NULL;
  if (annotation->getName() == "annotation")
  {
    if (annotation->getNumChildren() != 1)
    {
      success = LIBSEDML_INVALID_OBJECT;
      return success;
    }
    else
    {
      replacement = annotation->getChild(0).clone();
    }
  }
  else
  {
    replacement = annotation->clone();
  }

  success = removeTopLevelAnnotationElement(replacement->getName());
  if (success == LIBSEDML_OPERATION_SUCCESS)
  {
    success = appendAnnotation(annotation);
  }

  delete (replacement);

  return success;
}


int
SedBase::replaceTopLevelAnnotationElement(const std::string& annotation)
{
  int success = LIBSEDML_OPERATION_FAILED;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annt_xmln;
  if (getSedDocument() != NULL)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation);
  }

  if(annt_xmln != NULL)
  {
    success = replaceTopLevelAnnotationElement(annt_xmln);
  }

  delete annt_xmln;

  return success;
}


/*
 * Sets the notes of this SED-ML object to a copy of notes.
 */
int
SedBase::setNotes(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes)
{
  if (mNotes == notes)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (notes == NULL)
  {
    delete mNotes;
    mNotes = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }

  delete mNotes;
  const string&  name = notes->getName();

  /* check for notes tags and add if necessary */

  if (name == "notes")
  {
    mNotes = static_cast<LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*>( notes->clone() );
  }
  else
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken notes_t = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple("notes", "", ""),
                                LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes());
    mNotes = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(notes_t);

    // The root node of the given XMLNode tree can be an empty XMLNode
    // (i.e. neither start, end, nor text XMLNode) if the given notes was
    // converted from an XML string whose top level elements are neither
    // "html" nor "body" and not enclosed with <notes>..</notes> tag
    // (e.g. <p ...>..</p><br/>).
    if (!notes->isStart() && !notes->isEnd() && !notes->isText() )
    {
      for (unsigned int i=0; i < notes->getNumChildren(); i++)
      {
        if (mNotes->addChild(notes->getChild(i)) < 0)
        {
          return LIBSEDML_OPERATION_FAILED;
        }
      }
    }
    else
    {
      if (mNotes->addChild(*notes) < 0)
        return LIBSEDML_OPERATION_FAILED;
    }
  }

    if (!SyntaxChecker::hasExpectedXHTMLSyntax(mNotes, NULL))
    {
      delete mNotes;
      mNotes = NULL;
      return LIBSEDML_INVALID_OBJECT;
    }

  return LIBSEDML_OPERATION_SUCCESS;

}

/*
 * Sets the notes (by std::string) of this SED-ML object to a copy of notes.
 */
int
SedBase::setNotes(const std::string& notes, bool addXHTMLMarkup)
{
  int success = LIBSEDML_OPERATION_FAILED;
  
  if (notes.empty())
  {
    success = unsetNotes();
  }
  else
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes_xmln;

    // you might not have a document !!
    if (getSedDocument() != NULL)
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
      notes_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(notes,xmlns);
    }
    else
    {
      notes_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(notes);
    }

    if (notes_xmln != NULL)
    {
      if (addXHTMLMarkup == true)
      {
        if (notes_xmln->getNumChildren() == 0
            && notes_xmln->isStart() == false
            && notes_xmln->isEnd() == false
            && notes_xmln->isText() == true)
        {
          //create a parent node of xhtml type p
          LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes blank_att = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes();
          LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple triple = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple("p", "http://www.w3.org/1999/xhtml", "");
          LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces xmlns = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces();
          xmlns.add("http://www.w3.org/1999/xhtml", "");
          LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode *xmlnode = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken(triple, blank_att, xmlns));

          // create a text node from the text given
          xmlnode->addChild(*notes_xmln);
          success = setNotes(xmlnode);
          delete xmlnode;
        }
        else
        {
          success = setNotes(notes_xmln);
        }
      }
      else
      {
        success = setNotes(notes_xmln);
      }

      delete notes_xmln;
    }
  }
  return success;
}


/*
 * Appends notes to the existing notes.
 * This allows other notes to be preserved whilst
 * adding additional information.
 */
int
SedBase::appendNotes(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes)
{
  int success = LIBSEDML_OPERATION_FAILED;
  if(notes == NULL)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }

  const string&  name = notes->getName();

  // The content of notes in SED-ML can consist only of the following
  // possibilities:
  //
  //  1. A complete XHTML document (minus the XML and DOCTYPE
  //     declarations), that is, XHTML content beginning with the
  //     html tag.
  //     (_NotesType is _ANotesHTML.)
  //
  //  2. The body element from an XHTML document.
  //     (_NotesType is _ANotesBody.)
  //
  //  3. Any XHTML content that would be permitted within a body
  //     element, each one must declare the XML namespace separately.
  //     (_NotesType is _ANotesAny.)
  //

  typedef enum { _ANotesHTML, _ANotesBody, _ANotesAny } _NotesType;

  _NotesType addedNotesType = _ANotesAny;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode   addedNotes;

  //------------------------------------------------------------
  //
  // STEP1 : identifies the type of the given notes
  //
  //------------------------------------------------------------

  if (name == "notes")
  {
    /* check for notes tags on the added notes and strip if present and
       the notes tag has "html" or "body" element */

    if (notes->getNumChildren() > 0)
    {
      // notes->getChild(0) must be "html", "body", or any XHTML
      // element that would be permitted within a "body" element
      // (e.g. <p>..</p>,  <br>..</br> and so forth).

      const string& cname = notes->getChild(0).getName();

      if (cname == "html")
      {
        addedNotes = notes->getChild(0);
        addedNotesType = _ANotesHTML;
      }
      else if (cname == "body")
      {
        addedNotes = notes->getChild(0);
        addedNotesType = _ANotesBody;
      }
      else
      {
        // the notes tag must NOT be stripped if notes->getChild(0) node
        // is neither "html" nor "body" element because the children of
        // the addedNotes will be added to the curNotes later if the node
        // is neither "html" nor "body".
        addedNotes = *notes;
        addedNotesType = _ANotesAny;
      }
    }
    else
    {
      // the given notes is empty
      return LIBSEDML_OPERATION_SUCCESS;
    }
  }
  else
  {
    // if the XMLNode argument notes has been created from a string and
    // it is a set of subelements there may be a single empty node
    // as parent - leaving this in doesnt affect the writing out of notes
    // but messes up the check for correct syntax
    if (!notes->isStart() && !notes->isEnd() && !notes->isText() )
    {
      if (notes->getNumChildren() > 0)
      {
        addedNotes = *notes;
        addedNotesType = _ANotesAny;
      }
      else
      {
        // the given notes is empty
        return LIBSEDML_OPERATION_SUCCESS;
      }
    }
    else
    {
      if (name == "html")
      {
        addedNotes = *notes;
        addedNotesType = _ANotesHTML;
      }
      else if (name == "body")
      {
        addedNotes = *notes;
        addedNotesType = _ANotesBody;
      }
      else
      {
        // The given notes node needs to be added to a parent node
        // if the node is neither "html" nor "body" element because the
        // children of addedNotes will be added to the curNotes later if the
        // node is neither "html" nor "body" (i.e. any XHTML element that
        // would be permitted within a "body" element)
        addedNotes.addChild(*notes);
        addedNotesType = _ANotesAny;
      }
    }
  }

  //
  // checks the addedNotes of "html" if the html tag contains "head" and
  // "body" tags which must be located in this order.
  //
  if (addedNotesType == _ANotesHTML)
  {
    if ((addedNotes.getNumChildren() != 2) ||
        ( (addedNotes.getChild(0).getName() != "head") ||
          (addedNotes.getChild(1).getName() != "body")
        )
       )
    {
      return LIBSEDML_INVALID_OBJECT;
    }
  }

  // check whether notes is valid xhtml
  if (getLevel() > 2
    || (getLevel() == 2 && getVersion() > 1))
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode tmpNotes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple("notes","",""), LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes());

    if (addedNotesType == _ANotesAny)
    {
      for (unsigned int i=0; i < addedNotes.getNumChildren(); i++)
      {
        tmpNotes.addChild(addedNotes.getChild(i));
      }
    }
    else
    {
      tmpNotes.addChild(addedNotes);
    }

    if (!SyntaxChecker::hasExpectedXHTMLSyntax(&tmpNotes, NULL))
    {
      return LIBSEDML_INVALID_OBJECT;
    }
  }


  if ( mNotes != NULL )
  {
    //------------------------------------------------------------
    //
    //  STEP2: identifies the type of the existing notes
    //
    //------------------------------------------------------------

    _NotesType curNotesType   = _ANotesAny;
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode&  curNotes = *mNotes;

    // curNotes.getChild(0) must be "html", "body", or any XHTML
    // element that would be permitted within a "body" element .

    const string& cname = curNotes.getChild(0).getName();

    if (cname == "html")
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curHTML = curNotes.getChild(0);
      //
      // checks the curHTML if the html tag contains "head" and "body" tags
      // which must be located in this order, otherwise nothing will be done.
      //
      if ((curHTML.getNumChildren() != 2) ||
          ( (curHTML.getChild(0).getName() != "head") ||
            (curHTML.getChild(1).getName() != "body")
          )
         )
      {
        return LIBSEDML_INVALID_OBJECT;
      }
      curNotesType = _ANotesHTML;
    }
    else if (cname == "body")
    {
      curNotesType = _ANotesBody;
    }
    else
    {
      curNotesType = _ANotesAny;
    }

    /*
     * BUT we also have the issue of the rules relating to notes
     * contents and where to add them ie we cannot add a second body element
     * etc...
     */

    //------------------------------------------------------------
    //
    //  STEP3: appends the given notes to the current notes
    //
    //------------------------------------------------------------

    unsigned int i;

    if (curNotesType == _ANotesHTML)
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curHTML = curNotes.getChild(0);
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curBody = curHTML.getChild(1);

      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current html tag

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& addedBody = addedNotes.getChild(1);

        for (i=0; i < addedBody.getNumChildren(); i++)
        {
          if (curBody.addChild(addedBody.getChild(i)) < 0 )
            return LIBSEDML_OPERATION_FAILED;
        }
      }
      else if ((addedNotesType == _ANotesBody)
             || (addedNotesType == _ANotesAny))
      {
        // adds the given body or other tag (permitted in the body) to the current
        // html tag

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curBody.addChild(addedNotes.getChild(i)) < 0 )
            return LIBSEDML_OPERATION_FAILED;
        }
      }
      success = LIBSEDML_OPERATION_SUCCESS;
    }
    else if (curNotesType == _ANotesBody)
    {
      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current body tag

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode  addedHTML(addedNotes);
        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& addedBody = addedHTML.getChild(1);
        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curBody   = curNotes.getChild(0);

        for (i=0; i < curBody.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curBody.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedHTML) < 0)
          return LIBSEDML_OPERATION_FAILED;
      }
      else if ((addedNotesType == _ANotesBody) || (addedNotesType == _ANotesAny))
      {
        // adds the given body or other tag (permitted in the body) to the current
        // body tag

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curBody = curNotes.getChild(0);

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curBody.addChild(addedNotes.getChild(i)) < 0)
            return LIBSEDML_OPERATION_FAILED;
        }
      }
      success = LIBSEDML_OPERATION_SUCCESS;
    }
    else if (curNotesType == _ANotesAny)
    {
      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current any tag permitted in the body.

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode  addedHTML(addedNotes);
        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& addedBody = addedHTML.getChild(1);

        for (i=0; i < curNotes.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curNotes.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedHTML) < 0)
          return LIBSEDML_OPERATION_FAILED;
      }
      else if (addedNotesType == _ANotesBody)
      {
        // adds the given body tag to the current any tag permitted in the body.

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode addedBody(addedNotes);

        for (i=0; i < curNotes.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curNotes.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedBody) < 0)
          return LIBSEDML_OPERATION_FAILED;
      }
      else if (addedNotesType == _ANotesAny)
      {
        // adds the given any tag permitted in the boy to that of the current
        // any tag.

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curNotes.addChild(addedNotes.getChild(i)) < 0)
            return LIBSEDML_OPERATION_FAILED;
        }
      }
      success = LIBSEDML_OPERATION_SUCCESS;
    }
  }
  else // if (mNotes == NULL)
  {
    // setNotes accepts XMLNode with/without top level notes tags.
    success = setNotes(notes);
  }

  return success;
}

/*
 * Appends notes (by string) to the existing notes.
 * This allows other notes to be preserved whilst
 * adding additional information.
 */
int
SedBase::appendNotes(const std::string& notes)
{
  int success = LIBSEDML_OPERATION_FAILED;
  if (notes.empty())
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }

  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes_xmln;
  // you might not have a document !!
  if (getSedDocument() != NULL)
  {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
      notes_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(notes,xmlns);
  }
  else
  {
      notes_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(notes);
  }

  if(notes_xmln != NULL)
  {
    success = appendNotes(notes_xmln);
    delete notes_xmln;
  }
  return success;
}


/** @cond doxygenLibsedmlInternal */
/*
 * Sets the parent SedDocument of this SED-ML object.
 */
void
SedBase::setSedDocument (SedDocument* d)
{
  mSed = d;
}


/*
  * Sets the parent SED-ML object of this SED-ML object.
  *
  * @param sb the SED-ML object to use
  */
void
SedBase::connectToParent (SedBase* parent)
{
  mParentSedObject = parent;
  if (mParentSedObject)
  {
#if 0
    cout << "[DEBUG] connectToParent " << this << " (parent) " << SedTypeCode_toString(parent->getTypeCode(),"core")
         << " " << parent->getSedDocument() << endl;
#endif
    setSedDocument(mParentSedObject->getSedDocument());
  }
  else
  {
    setSedDocument(NULL);
  }
}


/*
 * Sets this SED-ML object to child SED-ML objects (if any).
 * (Creates a child-parent relationship by the parent)
 *
 * Subclasses must override this function if they define
 * one ore more child elements.
 * Basically, this function needs to be called in
 * constructors, copy constructors and assignment operators.
 */
void
SedBase::connectToChild()
{
}
/** @endcond */

SedBase*
SedBase::getAncestorOfType(int type)
{
  if (type == SEDML_DOCUMENT)
    return getSedDocument();

  SedBase *child;
  SedBase *parent = getParentSedObject();

  while ( parent != NULL &&
          !( parent->getTypeCode() == SEDML_DOCUMENT )
        )
  {
    if (parent->getTypeCode() == type)
      return parent;
    else
    {
      child = parent;
      parent = child->getParentSedObject();
    }
  }

  // if we get here we havent found an ancestor of this type
  return NULL;

}


const SedBase*
SedBase::getAncestorOfType(int type) const
{
  if (type == SEDML_DOCUMENT)
    return getSedDocument();

  const SedBase *child;
  const SedBase *parent = getParentSedObject();

  while ( parent != NULL &&
          !( parent->getTypeCode() == SEDML_DOCUMENT )
        )
  {
    if (parent->getTypeCode() == type)
      return parent;
    else
    {
      child = parent;
      parent = child->getParentSedObject();
    }
  }

  // if we get here we havent found an ancestor of this type
  return NULL;

}


/*
 * Sets the namespaces relevant of this SED-ML object.
 *
 * @param xmlns the namespaces to set
 */
int
SedBase::setNamespaces(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns)
{
  if (xmlns == NULL)
  {
    mSedNamespaces->setNamespaces(NULL);
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    mSedNamespaces->setNamespaces(xmlns);
    return LIBSEDML_OPERATION_SUCCESS;
  }
}



/*
 * Unsets the metaid of this SED-ML object.
 */
int
SedBase::unsetMetaId ()
{
  mMetaId.erase();
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the id of this SED-ML object.
 */
int
SedBase::unsetId ()
{
  mId.erase();
  return LIBSEDML_OPERATION_SUCCESS;
}

int SedBase::unsetName()
{
    mName.erase();
    return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the notes of this SED-ML object.
 */
int
SedBase::unsetNotes ()
{
  delete mNotes;
  mNotes = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the annotation of this SED-ML object.
 */
int
SedBase::unsetAnnotation ()
{
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* empty = NULL;
  return setAnnotation(empty);
}


/*
 * @return the SED-ML level of this SED-ML object.
 */
unsigned int
SedBase::getLevel () const
{
  if (mSed != NULL)
    return mSed->getLevel();
  else if (mSedNamespaces != NULL)
    return mSedNamespaces->getLevel();
  else
    return SEDML_DEFAULT_LEVEL;
}


/*
 * @return the SED-ML version of this SED-ML object.
 */
unsigned int
SedBase::getVersion () const
{
  if (mSed != NULL)
    return mSed->getVersion();
  else if (mSedNamespaces != NULL)
    return mSedNamespaces->getVersion();
  else
    return SEDML_DEFAULT_VERSION;
}


/*
 * @return the typecode (int) of this SED-ML object or SEDML_UNKNOWN
 * (default).
 *
 * This method MAY return the typecode of this SED-ML object or it MAY
 * return SEDML_UNKNOWN.  That is, subclasses of SedBase are not required to
 * implement this method to return a typecode.  This method is meant
 * primarily for the LibSEDML C interface where class and subclass
 * information is not readily available.
 *
 * @see getElementName()
 */
int
SedBase::getTypeCode () const
{
  return SEDML_UNKNOWN;
}


bool
SedBase::hasValidLevelVersionNamespaceCombination()
{
  int typecode = getTypeCode();
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns = getNamespaces();

  return hasValidLevelVersionNamespaceCombination(typecode, xmlns);
}

/** @cond doxygenLibsedmlInternal */
bool
SedBase::matchesSedNamespaces(const SedBase * sb)
{
  bool match = matchesCoreSedNamespace(sb);

  return match;
}

bool
SedBase::matchesSedNamespaces(const SedBase * sb) const
{
  bool match = matchesCoreSedNamespace(sb);

  return match;
}


bool
SedBase::matchesRequiredSedNamespacesForAddition(const SedBase * sb)
{
  // if core does not match forget it
  bool match = matchesCoreSedNamespace(sb);

  return match;
}


bool
SedBase::matchesRequiredSedNamespacesForAddition(const SedBase * sb) const
{
  // if core does not match forget it
  bool match = matchesCoreSedNamespace(sb);

  return match;
}


bool
SedBase::matchesCoreSedNamespace(const SedBase * sb)
{
  bool match = false;

  SedNamespaces *sedmlns = getSedNamespaces();
  SedNamespaces *sedmlns_rhs = sb->getSedNamespaces();

  if (sedmlns->getLevel() != sedmlns_rhs->getLevel())
    return match;

  if (sedmlns->getVersion() != sedmlns_rhs->getVersion())
    return match;

  std::string coreNs = SedNamespaces::getSedNamespaceURI(
                       sedmlns->getLevel(), sedmlns->getVersion());

  if (sedmlns->getNamespaces()->containsUri(coreNs)
    && sedmlns_rhs->getNamespaces()->containsUri(coreNs))
  {
    match = true;
  }

  return match;
}


bool
SedBase::matchesCoreSedNamespace(const SedBase * sb) const
{
  bool match = false;

  SedNamespaces *sedmlns = getSedNamespaces();
  SedNamespaces *sedmlns_rhs = sb->getSedNamespaces();

  if (sedmlns->getLevel() != sedmlns_rhs->getLevel())
    return match;

  if (sedmlns->getVersion() != sedmlns_rhs->getVersion())
    return match;

  std::string coreNs = SedNamespaces::getSedNamespaceURI(
                       sedmlns->getLevel(), sedmlns->getVersion());

  if (sedmlns->getNamespaces()->containsUri(coreNs)
    && sedmlns_rhs->getNamespaces()->containsUri(coreNs))
  {
    match = true;
  }

  return match;
}


bool
SedBase::hasValidLevelVersionNamespaceCombination(int typecode, LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns)
{


  //
  // (TODO) Currently, the following check code works only for
  //        elements in SED-ML core.
  //        This function may need to be extented for other elements
  //        defined in each package extension.
  //

  bool valid = true;
  bool sedmlDeclared = false;
  std::string declaredURI("");

  if (xmlns != NULL)
  {
    int numNS = 0;

    if (xmlns->hasURI(SEDML_XMLNS_L1V1))
    {
      // checks different SED-ML XMLNamespaces
      if (numNS > 0) return false;
      ++numNS;
      declaredURI.assign(SEDML_XMLNS_L1V1);
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

  return valid;
}

/* sets the Sednamespaces - internal use only*/
int
SedBase::setSedNamespaces(SedNamespaces * sedmlns)
{
  if (sedmlns == NULL)
    return LIBSEDML_INVALID_OBJECT;

  SedNamespaces* sedmlnsClone = (sedmlns) ? sedmlns->clone() : 0;
  setSedNamespacesAndOwn(sedmlnsClone);

  return LIBSEDML_OPERATION_SUCCESS;
}

/*
 * sets the Sednamespaces - only for internal use in the
 * constructors of SedBase subclasses in extension packages.
 */
void
SedBase::setSedNamespacesAndOwn(SedNamespaces * sedmlns)
{
    XMLNamespaces* names = mSedNamespaces->getNamespaces();
    XMLNamespaces* newnames = sedmlns->getNamespaces();
    for (int name = 0; name < names->getNumNamespaces(); name++)
    {
        if (!names->getPrefix(name).empty())
        {
            if (!newnames->containsUri(names->getURI(name)))
            {
                sedmlns->addNamespace(names->getURI(name), names->getPrefix(name));
            }
        }
    }
    delete mSedNamespaces;
    mSedNamespaces = sedmlns;

    if (sedmlns != NULL)
        setElementNamespace(sedmlns->getURI());
}


/* gets the Sednamespaces - internal use only*/
SedNamespaces *
SedBase::getSedNamespaces() const
{
  if (mSed != NULL)
    return mSed->mSedNamespaces;
  
  // initialize SED-ML namespace if need be
  if (mSedNamespaces == NULL)
    const_cast<SedBase*>(this)->mSedNamespaces = new SedNamespaces(getLevel(), getVersion());
  return mSedNamespaces;  
}
/** @endcond */



/*
 * @return the partial SED-ML that describes this SED-ML object.
 */
char*
SedBase::toSed ()
{
  ostringstream    os;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream  stream(os, "UTF-8", false);

  write(stream);

  return safe_strdup( os.str().c_str() );
}


/** @cond doxygenLibsedmlInternal */
int 
SedBase::getAttribute(const std::string& attributeName, double& value) const
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::getAttribute(const std::string& attributeName, bool& value) const
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::getAttribute(const std::string& attributeName, int& value) const
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::getAttribute(const std::string& attributeName, unsigned int& value) const
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::getAttribute(const std::string& attributeName, std::string& value) const
{
  if (attributeName == "metaid")
  {
    value = getMetaId();
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "id")
  {
    value = getId();
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "name")
  {
      value = getName();
      return LIBSEDML_OPERATION_SUCCESS;
  }

  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
bool 
SedBase::isSetAttribute(const std::string& attributeName) const
{
  bool value = false;
  if (attributeName == "metaid")
  {
    value = isSetMetaId();
  }
  else if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "name")
  {
      value = isSetName();
  }

  return value;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::setAttribute(const std::string& attributeName, double value)
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::setAttribute(const std::string& attributeName, bool value)
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::setAttribute(const std::string& attributeName, int value)
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::setAttribute(const std::string& attributeName, unsigned int value)
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::setAttribute(const std::string& attributeName, const std::string& value)
{
  int return_value = LIBSEDML_OPERATION_FAILED;
  if (attributeName == "metaid")
  {
    return_value = setMetaId(value);
  }
  else if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "name")
  {
      return_value = setName(value);
  }

  return return_value;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
int 
SedBase::unsetAttribute(const std::string& attributeName)
{
  int value = LIBSEDML_OPERATION_FAILED;
  if (attributeName == "metaid")
  {
    value = unsetMetaId();
  }
  else if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "name")
  {
      value = unsetName();
  }

  return value;
}
/** @endcond */

/** @cond doxygenLibsedmlInternal */
SedBase* 
SedBase::createChildObject(const std::string& elementName)
{
  return NULL;
}
/** @endcond */

/** @cond doxygenLibsedmlInternal */
int
SedBase::addChildObject(const std::string& elementName, const SedBase* element)
{
  return LIBSEDML_OPERATION_FAILED;
}
/** @endcond */

/** @cond doxygenLibsedmlInternal */
SedBase*
SedBase::removeChildObject(const std::string& elementName, const std::string& id)
{
  return NULL;
}
/** @endcond */

/** @cond doxygenLibsedmlInternal */

unsigned int
  SedBase::getNumObjects(const std::string& objectName)
{
  return 0;
}

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

SedBase* 
SedBase::getObject(const std::string& objectName, unsigned int index)
{
  return NULL;
}

  /** @endcond */
/** @cond doxygenLibsedmlInternal */
/*
 * Reads (initializes) this SED-ML object by reading from XMLInputStream.
 */
void
SedBase::read (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  if ( !stream.peek().isStart() ) return;

  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken  element  = stream.next();
  int             position =  0;

  setSedBaseFields( element );

  ExpectedAttributes expectedAttributes;
  addExpectedAttributes(expectedAttributes);
  readAttributes( element.getAttributes(), expectedAttributes );

  /* if we are reading a document pass the
   * SED-ML Namespace information to the input stream object
   * thus the MathML reader can find out what level/version
   * of SED-ML it is parsing
   */
  if (element.getName() == "sedML")
  {      
    //   stream.setSedNamespaces(this->getSedNamespaces());
    // need to check that any prefix on the sedmlns also occurs on element
    // remembering the horrible situation where the sedmlns might be declared
    // with more than one prefix
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces * xmlns = this->getSedNamespaces()->getNamespaces();
    if (xmlns != NULL)
    {
      int i = xmlns->getIndexByPrefix(element.getPrefix());
      if (i < xmlns->getNumNamespaces())
      {
        bool errorLoggedAlready = false;
        bool error = false;
        if (i > -1)
        {
          std::string uri = xmlns->getURI(i);
          if (uri == SEDML_XMLNS_L1V1 || uri == SEDML_XMLNS_L1V2 || uri == SEDML_XMLNS_L1V3 || uri == SEDML_XMLNS_L1V4)
          {
            error = false;
          }
          else if ( uri != "http://www.w3.org/2001/XMLSchema-instance")
          {
            error = true;
          }
        }
        else if ( i == -1)
        {
          error = true;
        }

        /* if there is a mismatch in level/version this will already
         * be logged; do not need another error
         */
        for (unsigned int n = 0; n < this->getErrorLog()->getNumErrors(); n++)
        {
          unsigned int errorId =
                             this->getErrorLog()->getError(n)->getErrorId();
          if ( errorId == SedmlDocumentAllowedCoreAttributes
            || errorId == SedmlDocumentLevelMustBeNonNegativeInteger
            || errorId == SedmlDocumentVersionMustBeNonNegativeInteger
            || errorId == InvalidNamespaceOnSed)
          {
            errorLoggedAlready = true;
          }
        }

        if (error == true && errorLoggedAlready == false)
        {
          static ostringstream errMsg;
          errMsg.str("");
          errMsg << "The prefix for the <sedml> element does not match "
            << "the prefix for the SED-ML namespace.  This means that "
            << "the <sedml> element in not in the SedNamespace."<< endl;

          logError(InvalidNamespaceOnSed,
                    getLevel(), getVersion(), errMsg.str());
        }
      }
    }

  }
  else
  {
    //
    // checks if the given default namespace (if any) is a valid
    // SED-ML namespace
    //
    checkDefaultNamespace(mSedNamespaces->getNamespaces(), element.getName());
    if (!element.getPrefix().empty())
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces * prefixedNS = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces();
      prefixedNS->add(element.getURI(), element.getPrefix());
      checkDefaultNamespace(prefixedNS, element.getName(), element.getPrefix());
      delete prefixedNS;
    }
  }

  if ( element.isEnd() ) return;

  while ( stream.isGood() )
  {
    // this used to skip the text
    //    stream.skipText();
    // instead, read text and store in variable
    std::string text;
    while(stream.isGood() && stream.peek().isText())
    {
      text += stream.next().getCharacters();
    }
    setElementText(text);

    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken& next = stream.peek();

    // Re-check stream.isGood() because stream.peek() could hit something.
    if ( !stream.isGood() ) break;

    if ( next.isEndFor(element) )
    {
      stream.next();
      break;
    }
    else if ( next.isStart() )
    {
      const std::string nextName = next.getName();

      SedBase * object = createObject(stream);

      if (object != NULL)
      {
        position = object->getElementPosition();

        object->connectToParent(static_cast <SedBase*>(this));

        object->read(stream);

        if ( !stream.isGood() ) break;

        // checkSedListOfPopulated(object);
      }
      else if ( !( readOtherXML(stream)
                   || readAnnotation(stream)
                   || readNotes(stream) ))
      {
        logUnknownElement(nextName, getLevel(), getVersion());
        stream.skipPastEnd( stream.next() );
      }
    }
    else
    {
      stream.skipPastEnd( stream.next() );
    }
  }
}
/** @endcond */


void
SedBase::setElementText(const std::string &text)
{
}

/** @cond doxygenLibsedmlInternal */
/*
 * Writes (serializes) this SED-ML object by writing it to XMLOutputStream.
 */
void
SedBase::write (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const
{
  stream.startElement( getElementName(), getPrefix() );

  writeXMLNS     ( stream );
  writeAttributes( stream );
  writeElements  ( stream );

  stream.endElement( getElementName(), getPrefix() );

}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * Subclasses should override this method to write out their contained
 * SED-ML objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
SedBase::writeElements (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const
{
  if ( mNotes != NULL ) stream << *mNotes;

  if (mAnnotation != NULL) stream << *mAnnotation;
}


/** @cond doxygenLibsedmlInternal */
/*
 * Subclasses should override this method to create, store, and then
 * return an SED-ML object corresponding to the next XMLToken in the
 * XMLInputStream.
 *
 * @return the SED-ML object corresponding to next XMLToken in the
 * XMLInputStream or @c NULL if the token was not recognized.
 */
SedBase*
SedBase::createObject (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  return NULL;
}


/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * Subclasses should override this method to read (and store) XHTML,
 * MathML, etc. directly from the XMLInputStream.
 *
 * @return true if the subclass read from the stream, false otherwise.
 */
bool
SedBase::readOtherXML (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  bool read = false;
  return read;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * @return true if read an <annotation> element from the stream
 */
bool
SedBase::readAnnotation (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  const string& name = stream.peek().getName();

  if (name == "annotation")
  {
    // If an annotation already exists, log it as an error and replace
    // the content of the existing annotation with the new one.

    if (mAnnotation != NULL)
    {
      string msg = "A SED-ML <" + getElementName() + "> element ";
      msg += "has multiple <annotation> children.";
      logError(SedMultipleAnnotations, getLevel(), getVersion(), msg);
    }

    delete mAnnotation;
    mAnnotation = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(stream);
    checkAnnotation();
    return true;
  }

  return false;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * @return true if read a <notes> element from the stream
 */
bool
SedBase::readNotes (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  const string& name = stream.peek().getName();

  if (name == "notes")
  {
    // If a notes element already exists, then it is an error.
    // If an annotation element already exists, then the ordering is wrong.
    // In either case, replace existing content with the new notes read.

    if (mNotes != NULL)
    {
      logError(SedOnlyOneNotesElementAllowed, getLevel(), getVersion());
    }

    delete mNotes;
    mNotes = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(stream);

    //
    // checks if the given default namespace (if any) is a valid
    // SED-ML namespace
    //
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces &xmlns = mNotes->getNamespaces();
    checkDefaultNamespace(&xmlns,"notes");

    return true;
  }

  return false;
}

bool
SedBase::getHasBeenDeleted() const
{
  return mHasBeenDeleted;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * @return the ordinal position of the element with respect to its siblings
 * or -1 (default) to indicate the position is not significant.
 */
int
SedBase::getElementPosition () const
{
  return -1;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
SedErrorLog*
SedBase::getErrorLog ()
{
  return (mSed != NULL) ? mSed->getErrorLog() : NULL;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * Helper to log a common type of error.
 */
void
SedBase::logUnknownAttribute( const string& attribute,
                            const unsigned int level,
                            const unsigned int version,
                            const string& element,
                            const string& prefix)
{
  ostringstream msg;

    msg << "Attribute '" << attribute << "' is not part of the "
        << "definition of a SED-ML Level " << level
        << " Version " << version << " <" << element << "> element.";

  if (mSed)
  {
  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SedDocument attached.
  //
        getErrorLog()->logError(SedUnknownCoreAttribute, level,
          version, msg.str(), getLine(), getColumn());
  }
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * Helper to log a common type of error.
 */
void
SedBase::logUnknownElement( const string& element,
        const unsigned int level,
        const unsigned int version )
{


    ostringstream msg;

    msg << "Element '" << element << "' is not part of the definition of "
        << "SED-ML Level " << level << " Version " << version << ".";

    if (mSed != NULL)
    {
      getErrorLog()->logError(SedUnrecognizedElement,
            level, version, msg.str(), getLine(), getColumn());
    }
  

}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * Helper to log a common type of error.
 */
void
SedBase::logEmptyString( const string& attribute,
                       const unsigned int level,
                       const unsigned int version,
                       const string& element )

{
  ostringstream msg;

  msg << "Attribute '" << attribute << "' on an "
    << element << " must not be an empty string.";

  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SedDocument attached.
  //
  if (mSed != NULL)
    getErrorLog()->logError(SedNotSchemaConformant,
                            level, version, msg.str(), getLine(), getColumn());
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * Convenience method for easily logging problems from within method
 * implementations.
 *
 * This is essentially a short form of getErrorLog()->logError(...)
 */
void
SedBase::logError (  unsigned int       id
                 , const unsigned int level
                 , const unsigned int version
                 , const std::string& details
                 , unsigned int line
                 , unsigned int column )
{
  if (line == 0) line = getLine();
  if (column == 0) column = getColumn();

  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SedDocument attached.
  //
  if ( SedBase::getErrorLog() != NULL && mSed != NULL)
    getErrorLog()->logError(id, getLevel(), getVersion(), details, line, column);
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/**
 * Subclasses should override this method to get the list of
 * expected attributes.
 * This function is invoked from corresponding readAttributes()
 * function.
 */
void
SedBase::addExpectedAttributes(ExpectedAttributes& attributes)
{
  //
  // metaid: ID { use="optional" }  (L2v1 ->)
  //
  attributes.add("metaid");
  //Can't check version here because it might not have been set yet, so just
  // add id and name as expected all the time, and deal with pre-v4 elsewhere.
  attributes.add("id");
  attributes.add("name");
}


/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
SedBase::readAttributes (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes& attributes,
                       const LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes& expectedAttributes)
{
  const_cast<LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&>(attributes).setErrorLog(getErrorLog());

  const unsigned int level   = getLevel  ();
  const unsigned int version = getVersion();

  //
  // check that all attributes are expected
  //
  for (int i = 0; i < attributes.getLength(); i++)
  {
    std::string name   = attributes.getName(i);
    std::string uri    = attributes.getURI(i);
    std::string prefix = attributes.getPrefix(i);

    //
    // To allow prefixed attribute whose namespace doesn't belong to
    // core or extension package.
    //
    // (e.g. xsi:type attribute in Curve element in layout extension)
    //
    if (!prefix.empty())
    {
      if ( expectedAttributes.hasAttribute(prefix + ":" + name) ) continue;
    }

    //
    // Checks if there are attributes of unknown package extensions
    //
    // if we happen to be on the sedml element (document) then
    // getPrefix() and mURI have not been set and just return defaults
    // thus a prefix does not appear to come from the right place !!!
    if (!prefix.empty() && getElementName() == "sedML")
    {
      if (!expectedAttributes.hasAttribute(name))
      {
        if (uri == "http://www.w3.org/2001/XMLSchema-instance") 
          continue;

        logUnknownAttribute(name, level, version, getElementName());
      }
    }
    else if (!expectedAttributes.hasAttribute(name))
    {
      logUnknownAttribute(name, level, version, getElementName(), prefix);
    }
  }

  // 
  // id SId (use = "optional" )
  // 

  bool assigned = attributes.readInto("id", mId, getErrorLog(), false, getLine(), getColumn());

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, (string)"<" + getElementName() + ">");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SedmlIdSyntaxRule, level, version, "The id on the <" +
        getElementName() + "> is '" + mId + "', which does not conform to the "
          "syntax.", getLine(), getColumn());
    }
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName, getErrorLog(), false, getLine(), getColumn());

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, (string)"<" + getElementName() + ">");
    }
  }

  assigned = attributes.readInto("metaid", mMetaId, getErrorLog(), false, getLine(), getColumn());

    if (assigned && mMetaId.empty())
    {
      logEmptyString("metaid", level, version,
                     SedTypeCode_toString(getTypeCode()));
    }

    if (isSetMetaId())
    {
      if (!SyntaxChecker::isValidXMLID(mMetaId))
      {
        logError(SedInvalidMetaidSyntax, getLevel(), getVersion(), "The metaid '" + mMetaId + "' does not conform to the syntax.");
      }
  }

}


/** @cond doxygenLibsedmlInternal */
/*
 * Returns the prefix of this element.
 */
std::string
SedBase::getPrefix() const
{
  std::string prefix = "";

  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns = getNamespaces();
  string uri = getURI();
  if(xmlns && mSed)
  {
    prefix = xmlns->getPrefix(uri);
  }

  return prefix;
}


/*
 * Returns the prefix of this element.
 */
std::string
SedBase::getSedPrefix() const
{
  std::string prefix = "";

  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns = getNamespaces();
  if (xmlns == NULL)
    return getPrefix();

  for (int i = 0; i < xmlns->getNumNamespaces(); i++)
  {
    string uri = xmlns->getURI(i);
    if (SedNamespaces::isSedNamespace(uri))
      return xmlns->getPrefix(i);
  }

  return getPrefix();
}

/*
 * Returns the root element of this element.
 *
 * @note The root element may not be an SedDocument element. For example,
 * this element is the root element if this element doesn't have a parent
 * SED-ML object (i.e. mParentSedObject is NULL)
 */
SedBase*
SedBase::getRootElement()
{
  if (mSed)
  {
    return mSed;
  }
  else if (mParentSedObject)
  {
    return mParentSedObject->getRootElement();
  }
  else
  {
    return this;
  }
}


/*
 * Subclasses should override this method to write their XML attributes
 * to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 */
void
SedBase::writeAttributes (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const
{
  string sedmlPrefix    = getSedPrefix();
  if (!mId.empty() && (mIdAllowedPreV4 || getVersion()>=4 || getLevel()>1))
  {
      stream.writeAttribute("id", sedmlPrefix, mId);
  }
  if (!mName.empty() && (mNameAllowedPreV4 || getVersion() >= 4 || getLevel()>1))
  {
      stream.writeAttribute("name", sedmlPrefix, mName);
  }
  if ( !mMetaId.empty() )
  {
    stream.writeAttribute("metaid", sedmlPrefix, mMetaId);
  }

}


/*
 *
 * Subclasses should override this method to write their xmlns attriubutes
 * (if any) to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 *
 */
void
SedBase::writeXMLNS (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const
{
  // do nothing.
}
/** @endcond */



/** @cond doxygenLibsedmlInternal */
/*
  * Checks that an SED-ML SedListOf element has been populated.
  * If a listOf element has been declared with no elements,
  * an error is logged.
  */
void
SedBase::checkSedListOfPopulated(SedBase* object)
{
    // for now log the empty list
  if (object->getTypeCode() == SEDML_LIST_OF)
  {
    if (static_cast <SedListOf*> (object)->size() == 0)
    {
      SedErrorCode_t error = SedEmptyListElement;
      ostringstream errMsg;
      errMsg << object->getElementName() << " cannot be empty.";

      logError(error, getLevel(), getVersion(), errMsg.str());
    }
  }
}
/** @endcond */

//This assumes that the parent of the object is of the type SedListOf.  If this is not the case, it will need to be overridden.
int SedBase::removeFromParentAndDelete()
{
  SedBase* parent = getParentSedObject();

  if (parent==NULL) return LIBSEDML_OPERATION_FAILED;
  
  SedListOf* parentList = static_cast<SedListOf*>(parent);
  
  if (parentList == NULL) return LIBSEDML_OPERATION_FAILED;
  
  for (unsigned int i=0; i<parentList->size(); i++) 
  {
    SedBase* sibling = parentList->get(i);
    if (sibling == this) 
    {
      parentList->remove(i);
      delete this;
      return LIBSEDML_OPERATION_SUCCESS;
    }
  }
  return LIBSEDML_OPERATION_FAILED;
}

/** @cond doxygenLibsedmlInternal */
const std::string
SedBase::checkMathMLNamespace(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken elem)
{
  std::string prefix = "";
  unsigned int match = 0;
  int n;
  if (elem.getNamespaces().getLength() != 0)
  {
    for (n = 0; n < elem.getNamespaces().getLength(); n++)
    {
      if (!strcmp(elem.getNamespaces().getURI(n).c_str(),
                  "http://www.w3.org/1998/Math/MathML"))
      {
        match = 1;
        break;
      }
    }
  }
  if (match == 0)
  {
    if( mSed->getNamespaces() != NULL)
    /* check for implicit declaration */
    {
      for (n = 0; n < mSed->getNamespaces()->getLength(); n++)
      {
        if (!strcmp(mSed->getNamespaces()->getURI(n).c_str(),
                    "http://www.w3.org/1998/Math/MathML"))
        {
          match = 1;
          prefix = mSed->getNamespaces()->getPrefix(n);
          break;
        }
      }
    }
  }
  if (match == 0)
  {
    logError(SedInvalidMathElement, getLevel(), getVersion(), "The MathML namespace 'http://www.w3.org/1998/Math/MathML' was not found.");
  }

  return prefix;
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
void
SedBase::checkDefaultNamespace(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns,
                             const std::string& elementName,
                             const std::string& prefix)
{
  //
  // checks if the given default namespace (if any) is a valid
  // SED-ML namespace
  //
  if (xmlns == NULL || xmlns->getLength() == 0)
    return;

  const std::string defaultURI = xmlns->getURI(prefix);
  if (defaultURI.empty() || mURI == defaultURI)
    return;

  // if this element (SedBase derived) has notes or annotation elements,
  // it is ok for them to be in the SED-ML namespace!
  if ( SedNamespaces::isSedNamespace(defaultURI)
       && !SedNamespaces::isSedNamespace(mURI)
       && (elementName == "notes" || elementName == "annotation"))
    return;

  static ostringstream errMsg;
  errMsg.str("");
  errMsg << "xmlns=\"" << defaultURI << "\" in <" << elementName
         << "> element is an invalid namespace." << endl;

  logError(SedNotSchemaConformant, getLevel(), getVersion(), errMsg.str());

}

/*
  * Checks the annotation does not declare an sedml namespace.
  * If the annotation declares an sedml namespace an error is logged.
  */
void
SedBase::checkAnnotation()
{
  unsigned int nNodes = 0;
  unsigned int match = 0;
  int n = 0;
  std::vector<std::string> uri_list;
  uri_list.clear();

  if (mAnnotation == NULL) return;

  //
  // checks if the given default namespace (if any) is a valid
  // SED-ML namespace
  //
  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces &xmlns = mAnnotation->getNamespaces();
  checkDefaultNamespace(&xmlns,"annotation");

  while (nNodes < mAnnotation->getNumChildren())
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode topLevel = mAnnotation->getChild(nNodes);

    // the top level must be an element (so it should be a start)
    if (topLevel.isStart() == false)
    {
      logError(SedAnnotationNotElement, getLevel(), getVersion());
      nNodes++;
      continue;
    }
    std::string uri = topLevel.getURI();
    std::string prefix = topLevel.getPrefix();

#ifdef USE_LIBXML
    // sometimes libxml does not catch an empty ns with a prefix
    if (uri.empty() && !prefix.empty())
    {
      logError(BadXMLPrefix);
      nNodes++;
      continue;
    }
#endif

    // cannot be other toplevel element with this uri
    if (!uri.empty())
    {
      if (find(uri_list.begin(), uri_list.end(), uri)
                                               != uri_list.end())
      {
        string msg = "A SED-ML <" + getElementName() + "> element ";
        msg += "has an <annotation> child with multiple children with the same namespace.";
        logError(SedDuplicateAnnotationNamespaces, getLevel(), getVersion(), msg);
      }
      uri_list.push_back(uri);
    }

    match = 0;
    n = 0;

    bool implicitNSdecl = false;
   // must have a namespace
    if (topLevel.getNamespaces().getLength() == 0)
    {
      // not on actual element - is it explicit ??
      if(mSed != NULL && mSed->getNamespaces() != NULL)
      /* check for implicit declaration */
      {
        for (n = 0; n < mSed->getNamespaces()->getLength(); n++)
        {
          if (!strcmp(mSed->getNamespaces()->getPrefix(n).c_str(),
                        prefix.c_str()))
          {
            implicitNSdecl = true;
            break;
          }
        }
     }


      if (!implicitNSdecl)
      {
        logError(SedMissingAnnotationNamespace);
      }
    }
    // cannot declare sedml namespace
    while(!match && n < topLevel.getNamespaces().getLength())
    {
      match += !strcmp(topLevel.getNamespaces().getURI(n).c_str(),
                                          "http://sed-ml.org/");
      n++;
    }
    string msg = "A SED-ML <" + getElementName() + "> element ";
    if (match > 0)
    {
      msg += "uses a restricted namespace on an element in its child <annotation>.";
      logError(SedNamespaceInAnnotation, getLevel(), getVersion(), msg);
      break;
    }

    if (implicitNSdecl && prefix.empty())
    {
      msg += "assumes the sedml namespace on an element in its child <annotation>.";
      logError(SedMissingAnnotationNamespace, getLevel(), getVersion(), msg);
    }
    nNodes++;
  }
}
/** @endcond */


/** @cond doxygenLibsedmlInternal */
/*
 * Checks that the XHTML is valid.
 * If the xhtml does not conform to the specification of valid xhtml within
 * an sedml document, an error is logged.
 */
void
SedBase::checkXHTML(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode * xhtml)
{
  if (xhtml == NULL) return;

  const string&  name = xhtml->getName();
  unsigned int i, errorNS, errorXML, errorDOC, errorELEM;

  if (name == "notes")
  {
    errorNS   = SedNotesNotInXHTMLNamespace;
    errorXML  = SedNotesContainsXMLDecl;
    errorDOC  = SedNotesContainsDOCTYPE;
    errorELEM = SedInvalidNotesContent;
  }
  else                                  // We shouldn't ever get to this point.
  {
    logError(SedUnknown);
    return;
  }

  /*
  * errors relating to a misplaced XML or DOCTYPE declaration
  * will also cause a parser error.
  * since parsing will terminate at this error, then if it has occurred
  * it will be in the XML currently being checked and so a more
  * informative message can be added
  */
  for (i = 0; i < getErrorLog()->getNumErrors(); i++)
  {
    if (getErrorLog()->getError(i)->getErrorId() == BadXMLDeclLocation)
    {
      logError(errorXML);
    }
    if (getErrorLog()->getError(i)->getErrorId() == BadlyFormedXML)
    {
      logError(errorDOC);
    }
  }

  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* toplevelNS = (mSed) ? mSed->getNamespaces() : NULL;

  /*
  * namespace declaration is variable
  * if a whole html tag has been used
  * or a whole body tag then namespace can be implicitly declared
  */
  unsigned int children = xhtml->getNumChildren();

  if (children > 1)
  {
    for (i=0; i < children; i++)
    {
      if (SyntaxChecker::isAllowedElement(xhtml->getChild(i)))
      {
        if (!SyntaxChecker::hasDeclaredNS(xhtml->getChild(i),
                                                  toplevelNS))
        {
          logError(errorNS);
        }
      }
      else
      {
        logError(errorELEM);
      }
    }
  }
  else
  {
    /* only one element which can be html or body with either implicit/explicit
    * namespace declaration
    * OR could be one of the listed elements.
    */

    const string& top_name = xhtml->getChild(0).getName();

    if (top_name != "html" && top_name != "body"
      && !SyntaxChecker::isAllowedElement(xhtml->getChild(0)))
    {
      logError(errorELEM);
    }
    else
    {
      if (!SyntaxChecker::hasDeclaredNS(xhtml->getChild(0), toplevelNS))
      {
        logError(errorNS);
      }
      if (top_name == "html"
        && !SyntaxChecker::isCorrectHTMLNode(xhtml->getChild(0)))
      {
        logError(errorELEM);
      }
    }
  }
}
/** @endcond */
/** @cond doxygenLibsedmlInternal */
/* default for components that have no required attributes */
bool
SedBase::hasRequiredAttributes() const
{
  return true;
}

/* default for components that have no required elements */
bool
SedBase::hasRequiredElements() const
{
  return true;
}

int
SedBase::checkCompatibility(const SedBase * object) const
{
  if (object == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (!(object->hasRequiredAttributes()) || !(object->hasRequiredElements()))
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != object->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != object->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (this->matchesRequiredSedNamespacesForAddition(object) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
}

/** @endcond */

/** @cond doxygenLibsedmlInternal */
/*
 * Stores the location (line and column) and any XML namespaces (for
 * roundtripping) declared on this SED-ML (XML) element.
 */
void
SedBase::setSedBaseFields (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken& element)
{
  mLine   = element.getLine  ();
  mColumn = element.getColumn();

  if (element.getNamespaces().getLength() > 0)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces tmpxmlns(element.getNamespaces());
    setNamespaces(&tmpxmlns);
  }
  else
  {
    setNamespaces(NULL);
  }
}


/*
 * Sets the XML namespace to which this element belongs to.
 */
int
SedBase::setElementNamespace(const std::string &uri)
{
  mURI = uri;

  return LIBSEDML_OPERATION_SUCCESS;
}

/*
 * Gets the XML namespace to which this element belongs to.
 */
const std::string&
SedBase::getElementNamespace() const
{
  return mURI;
}
/** @endcond */

#endif /* __cplusplus */


LIBSEDML_EXTERN
int
SedBase_getTypeCode (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getTypeCode() : SEDML_UNKNOWN;
}


LIBSEDML_EXTERN
const char *
SedBase_getMetaId (SedBase_t *sb)
{
  return (sb != NULL && sb->isSetMetaId()) ? sb->getMetaId().c_str() : NULL;
}


LIBSEDML_EXTERN
const SedDocument_t *
SedBase_getSedDocument (SedBase_t *sb)
{
  return (sb != NULL) ? sb->getSedDocument() : NULL;
}


LIBSEDML_EXTERN
const SedBase_t *
SedBase_getParentSedObject (SedBase_t *sb)
{
  return (sb != NULL) ? sb->getParentSedObject() : NULL;
}


LIBSEDML_EXTERN
const SedBase_t *
SedBase_getAncestorOfType (SedBase_t *sb, int type)
{
  return (sb != NULL) ? sb->getAncestorOfType(type) : NULL;
}


LIBSEDML_EXTERN
unsigned int
SedBase_getLevel (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getLevel() : SEDML_INT_MAX;
}


LIBSEDML_EXTERN
unsigned int
SedBase_getVersion (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getVersion() : SEDML_INT_MAX;
}


LIBSEDML_EXTERN
XMLNode_t *
SedBase_getNotes (SedBase_t *sb)
{
  return (sb != NULL) ? sb->getNotes() : NULL;
}


LIBSEDML_EXTERN
char*
SedBase_getNotesString (SedBase_t *sb)
{
  return (sb != NULL && sb->isSetNotes()) ?
    safe_strdup(sb->getNotesString().c_str()) : NULL;
}


LIBSEDML_EXTERN
XMLNode_t *
SedBase_getAnnotation (SedBase_t *sb)
{
  return (sb != NULL) ? sb->getAnnotation() : NULL;
}


LIBSEDML_EXTERN
char*
SedBase_getAnnotationString (SedBase_t *sb)
{
  return (sb != NULL && sb->isSetAnnotation()) ?
    safe_strdup(sb->getAnnotationString().c_str()) : NULL;
}


LIBSEDML_EXTERN
int
SedBase_isSetMetaId (const SedBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetMetaId() ) : 0;
}


LIBSEDML_EXTERN
int
SedBase_isSetNotes (const SedBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetNotes() ) : 0;
}


LIBSEDML_EXTERN
int
SedBase_isSetAnnotation (const SedBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetAnnotation() ) : 0;
}


LIBSEDML_EXTERN
int
SedBase_setMetaId (SedBase_t *sb, const char *metaid)
{
  if (sb != NULL)
    return (metaid == NULL) ? sb->unsetMetaId() : sb->setMetaId(metaid);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_setNamespaces (SedBase_t *sb, XMLNamespaces_t *xmlns)
{
  if (sb != NULL)
    return sb->setNamespaces(xmlns);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_setNotes (SedBase_t *sb, XMLNode_t *notes)
{
  if (sb != NULL)
    return sb->setNotes(notes);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_setNotesString (SedBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if(notes == NULL)
    {
      return sb->unsetNotes();
    }
    else
    {
      return sb->setNotes(notes);
    }
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_setNotesStringAddMarkup (SedBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if(notes == NULL)
    {
      return sb->unsetNotes();
    }
    else
    {
      return sb->setNotes(notes, true);
    }
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_appendNotes (SedBase_t *sb, XMLNode_t *notes)
{
  if (sb != NULL)
    return sb->appendNotes(notes);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_appendNotesString (SedBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if (notes != NULL)
      return sb->appendNotes(notes);
    else
      return LIBSEDML_INVALID_OBJECT;
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_setAnnotation (SedBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
    return sb->setAnnotation(annotation);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_setAnnotationString (SedBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if(annotation == NULL)
    {
      return sb->unsetAnnotation();
    }
    else
    {
      return sb->setAnnotation(annotation);
    }
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_appendAnnotation (SedBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
    return sb->appendAnnotation(annotation);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_appendAnnotationString (SedBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->appendAnnotation(annotation);
    else
      return LIBSEDML_INVALID_OBJECT;
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
int
SedBase_removeTopLevelAnnotationElement (SedBase_t *sb, const char *name)
{
  if (sb != NULL)
  {
    if (name != NULL)
      return sb->removeTopLevelAnnotationElement(name);
    else
      return LIBSEDML_INVALID_OBJECT;
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_removeTopLevelAnnotationElementWithURI (SedBase_t *sb, const char *name,
                                              const char *uri)
{
  if (sb != NULL)
  {
    if (name != NULL && uri != NULL)
      return sb->removeTopLevelAnnotationElement(name, uri);
    else
      return LIBSEDML_INVALID_OBJECT;
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_replaceTopLevelAnnotationElement (SedBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->replaceTopLevelAnnotationElement(annotation);
    else
      return LIBSEDML_INVALID_OBJECT;
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_replaceTopLevelAnnotationElementString (SedBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->replaceTopLevelAnnotationElement(annotation);
    else
      return LIBSEDML_INVALID_OBJECT;
  }
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_unsetMetaId (SedBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetMetaId();
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_unsetNotes (SedBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetNotes();
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedBase_unsetAnnotation (SedBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetAnnotation();
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
const char *
SedBase_getElementName (const SedBase_t *sb)
{
  return (sb != NULL && !(sb->getElementName().empty())) ?
    sb->getElementName().c_str() : NULL;
}


LIBSEDML_EXTERN
unsigned int
SedBase_getLine (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getLine() : 0;
}


LIBSEDML_EXTERN
unsigned int
SedBase_getColumn (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getColumn() : 0;
}


LIBSEDML_EXTERN
int
SedBase_hasValidLevelVersionNamespaceCombination(SedBase_t *sb)
{
  return (sb != NULL) ?
    static_cast <int> (sb->hasValidLevelVersionNamespaceCombination()) : 0;
}


LIBSEDML_EXTERN
int
SedBase_setUserData(SedBase_t* sb, void *userData)
{
  if (sb == NULL) return LIBSEDML_INVALID_OBJECT;
  return sb->setUserData(userData);
}


LIBSEDML_EXTERN
void *
SedBase_getUserData(const SedBase_t* sb)
{
  if (sb == NULL) return NULL;
  return sb->getUserData();
}

LIBSEDML_EXTERN
int
SedBase_isSetUserData(const SedBase_t* sb)
{
  if (sb == NULL) return 0;
  return static_cast <int>(sb->isSetUserData());
}

LIBSEDML_EXTERN
int
SedBase_unsetUserData(SedBase_t* sb)
{
  if (sb == NULL) return LIBSEDML_INVALID_OBJECT;
  return sb->unsetUserData();
}

LIBSEDML_EXTERN
SedBase_t*
SedBase_getElementByMetaId(SedBase_t* sb, const char* metaid)
{
  if (sb == NULL) return NULL;
  return sb->getElementByMetaId(metaid);
}

LIBSEDML_EXTERN
List_t*
SedBase_getAllElements(SedBase_t* sb)
{
  if (sb == NULL) return NULL;
  return sb->getAllElements();
}


/*
 * Returns the value of the "id" attribute of this SedBase_t.
 */
LIBSEDML_EXTERN
char *
SedBase_getId(const SedBase_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getId().empty() ? NULL : safe_strdup(ss->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedBase_t.
 */
LIBSEDML_EXTERN
char *
SedBase_getName(const SedBase_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getName().empty() ? NULL : safe_strdup(ss->getName().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedBase_t's "id" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedBase_isSetId(const SedBase_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedBase_t's "name" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedBase_isSetName(const SedBase_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedBase_t.
 */
LIBSEDML_EXTERN
int
SedBase_setId(SedBase_t * ss, const char * id)
{
  return (ss != NULL) ? ss->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedBase_t.
 */
LIBSEDML_EXTERN
int
SedBase_setName(SedBase_t * ss, const char * name)
{
  return (ss != NULL) ? ss->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedBase_t.
 */
LIBSEDML_EXTERN
int
SedBase_unsetId(SedBase_t * ss)
{
  return (ss != NULL) ? ss->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedBase_t.
 */
LIBSEDML_EXTERN
int
SedBase_unsetName(SedBase_t * ss)
{
  return (ss != NULL) ? ss->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/** @endcond */

LIBSEDML_CPP_NAMESPACE_END
