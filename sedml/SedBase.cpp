/**
 * @file    SedBase.cpp
 * @brief   Implementation of SedBase, the base object of all Sed objects.
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


//#include <sbml/validator/constraints/IdList.h>


/** @cond doxygen-ignored */

using namespace std;

LIBSEDML_CPP_NAMESPACE_BEGIN

/** @endcond */



SedBase*
SedBase::getElementBySId(std::string id)
{
  if (id.empty()) return NULL;
  return NULL;
}


SedBase*
SedBase::getElementByMetaId(std::string metaid)
{
  if (metaid.empty()) return NULL;
  return NULL;
}

List*
SedBase::getAllElements()
{
  return NULL;
}

/** @cond doxygen-libsbml-internal */
/*
 * Creates a new SedBase object with the given level and version.
 * Only subclasses may create SedBase objects.
 */
SedBase::SedBase (unsigned int level, unsigned int version) :
   mNotes     ( NULL )
 , mAnnotation( NULL )
 , mSed      ( NULL )
 , mSedNamespaces (NULL)
 , mUserData(NULL)
 , mLine      ( 0 )
 , mColumn    ( 0 )
 , mParentSedObject (NULL)
 , mHasBeenDeleted (false)
 , mEmptyString ("")
 , mURI("")
{
  mSedNamespaces = new SedNamespaces(level, version);

  //
  // Sets the XMLNS URI of corresponding Sed Level/Version to
  // the element namespace (mURI) of this object.
  //
  //
  setElementNamespace(mSedNamespaces->getURI());
}



/*
 * Creates a new SedBase object with the given SedNamespaces.
 * Only subclasses may create SedBase objects.
 */
SedBase::SedBase (SedNamespaces *sbmlns) :
   mNotes     ( NULL )
 , mAnnotation( NULL )
 , mSed      ( NULL )
 , mSedNamespaces (NULL)
 , mUserData(NULL)
 , mLine      ( 0 )
 , mColumn    ( 0 )
 , mParentSedObject (NULL)
 , mHasBeenDeleted (false)
 , mEmptyString ("")
 , mURI("")
{
  if (!sbmlns) 
  {
    std::string err("SedBase::SedBase(SedNamespaces*) : SedNamespaces is null");
    throw SedConstructorException(err);
  }
  mSedNamespaces = sbmlns->clone();

  //
  // Sets the XMLNS URI of corresponding Sed Level/Version to
  // the element namespace (mURI) of this object.
  //
  // (NOTES) Package developers must override the element namespace (mURI)
  //         of this object with the corresponding package's URI in the constructor
  //         of SedBase derived class in thier packages.
  //

#if 0
    cout << "[DEBUG] SedBase::SedBase(SedNamespaces*,...) " << static_cast<SedNamespaces>(*mSedNamespaces).getURI() << endl;
#endif

  setElementNamespace(static_cast<SedNamespaces>(*mSedNamespaces).getURI());
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Copy constructor. Creates a copy of this SedBase object.
 */
SedBase::SedBase(const SedBase& orig)
{
  if (&orig == NULL)
  {
    throw SedConstructorException("Null argument to copy constructor");
  }
  this->mMetaId = orig.mMetaId;

  if(orig.mNotes != NULL) 
    this->mNotes = new XMLNode(*const_cast<SedBase&>(orig).getNotes());
  else
    this->mNotes = NULL;
  
  if(orig.mAnnotation != NULL) 
    this->mAnnotation = new XMLNode(*const_cast<SedBase&>(orig).mAnnotation);
  else
    this->mAnnotation = NULL;
 
  /* the copy does not contain a pointer to the document since technically
   * a copy is not part of the document
   */
  this->mSed       = NULL;
  this->mLine       = orig.mLine;
  this->mColumn     = orig.mColumn;
  this->mParentSedObject = NULL;
  this->mUserData   = orig.mUserData;

  /* if the object belongs to document that has had the level/version reset
   * the copy will end up with the wrong namespace information
   * need to use the default namespace NOT the namespace local to the object
   */
  if(orig.getSedNamespaces() != NULL)
    this->mSedNamespaces = 
    new SedNamespaces(*const_cast<SedBase&>(orig).getSedNamespaces());
  else
    this->mSedNamespaces = NULL;

  
  this->mHasBeenDeleted = false;

  this->mURI = orig.mURI;
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
  if (&rhs == NULL)
  {
    throw SedConstructorException("Null argument to assignment operator");
  }
  else if(&rhs!=this)
  {
    this->mMetaId = rhs.mMetaId;

    delete this->mNotes;

    if(rhs.mNotes != NULL) 
      this->mNotes = new XMLNode(*const_cast<SedBase&>(rhs).getNotes());
    else
      this->mNotes = NULL;

    delete this->mAnnotation;

    if(rhs.mAnnotation != NULL) 
      this->mAnnotation = new XMLNode(*const_cast<SedBase&>(rhs).mAnnotation);
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
 * @return the metaid of this Sed object.
 */
const string&
SedBase::getMetaId () const
{
  return mMetaId;
}


/*
 * @return the metaid of this Sed object.
 */
string&
SedBase::getMetaId ()
{
  return mMetaId;
}


/** @cond doxygen-libsbml-internal */

/*
 * NOTE: THIS IS FOR BACKWARD COMPATABILITY REASONS
 *
 * @return the id of this Sed object.
 */
const string&
SedBase::getId () const
{
  return mEmptyString;
}



/*
 * NOTE: THIS IS FOR BACKWARD COMPATABILITY REASONS
 *
 * @return the name of this Sed object.
 */
const string&
SedBase::getName () const
{
  return mEmptyString;
}

/** @endcond */

/*
 * @return the notes of this Sed object.
 */
XMLNode*
SedBase::getNotes()
{
  return mNotes;
}


XMLNode*
SedBase::getNotes() const
{
  return mNotes;
}


/*
 * @return the notes of this Sed object by string.
 */
std::string
SedBase::getNotesString() 
{
  return XMLNode::convertXMLNodeToString(mNotes);
}


std::string
SedBase::getNotesString() const
{
  return XMLNode::convertXMLNodeToString(mNotes);
}


/*
 * @return the annotation of this Sed object.
 */
XMLNode* 
SedBase::getAnnotation ()
{
  syncAnnotation();

  return mAnnotation;
}


XMLNode* 
SedBase::getAnnotation () const
{
  return const_cast<SedBase *>(this)->getAnnotation();
}


/*
 * @return the annotation of this Sed object by string.
 */
std::string
SedBase::getAnnotationString ()
{
  return XMLNode::convertXMLNodeToString(getAnnotation());
}


std::string
SedBase::getAnnotationString () const
{
  return XMLNode::convertXMLNodeToString(getAnnotation());
}


/** @cond doxygen-libsbml-internal */
std::string 
SedBase::getURI() const
{
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
  if (mUserData != NULL)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}

/*
 * @return the Namespaces associated with this Sed object
 */
XMLNamespaces*
SedBase::getNamespaces() const
{
  if (mSed != NULL)
    return mSed->getSedNamespaces()->getNamespaces();
  else
    return mSedNamespaces->getNamespaces();
}


/*
 * @return the parent SedDocument of this Sed object.
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
 * @return the parent SedDocument of this Sed object.
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
 * @return the line number of this Sed object.
 */
unsigned int
SedBase::getLine () const
{
  return mLine;
}


/*
 * @return the column number of this Sed object.
 */
unsigned int
SedBase::getColumn () const
{
  return mColumn;
}



/*
 * @return true if the metaid of this Sed object is set, false
 * otherwise.
 */
bool
SedBase::isSetMetaId () const
{
  return (mMetaId.empty() == false);
}


/** @cond doxygen-libsbml-internal */

/*
 * NOTE: THIS IS FOR BACKWARD COMPATABILITY REASONS
 *
 * @return true if the id of this Sed object is set, false
 * otherwise.
 */
bool
SedBase::isSetId () const
{
  return (getId().empty() == false);
}


/*
 * NOTE: THIS IS FOR BACKWARD COMPATABILITY REASONS
 *
 * @return true if the name of this Sed object is set, false
 * otherwise.
 */
bool
SedBase::isSetName () const
{
  return (getName().empty() == false);
}


/** @endcond */


/*
 * @return true if the notes of this Sed object is set, false
 * otherwise.
 */
bool
SedBase::isSetNotes () const
{
  return (mNotes != NULL);
}


/*
 * @return true if the annotation of this Sed object is set,
 * false otherwise.
 */
bool
SedBase::isSetAnnotation () const
{
  const_cast <SedBase *> (this)->syncAnnotation();
  return (mAnnotation != NULL);
}




/*
 * Sets the metaid field of the given Sed object to a copy of metaid.
 */
int
SedBase::setMetaId (const std::string& metaid)
{
  if (&(metaid) == NULL)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else if (getLevel() == 1)
  {
    return LIBSEDML_UNEXPECTED_ATTRIBUTE;
  }
  else if (metaid.empty())
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


/** @cond doxygen-libsbml-internal */

/*
 * NOTE: THIS IS FOR BACKWARD COMPATABILITY REASONS
 *
 * Sets the id of this Sed object to a copy of sid.
 */
int
SedBase::setId (const std::string& sid)
{
  return LIBSEDML_UNEXPECTED_ATTRIBUTE;
}


/*
 * NOTE: THIS IS FOR BACKWARD COMPATABILITY REASONS
 * Sets the name of this Sed object to a copy of name.
 */
int
SedBase::setName (const std::string& name)
{
  return LIBSEDML_UNEXPECTED_ATTRIBUTE;
}


/** @endcond */


/*
 * Sets the annotation of this Sed object to a copy of annotation.
 */
int 
SedBase::setAnnotation (const XMLNode* annotation)
{
  //
  // (*NOTICE*) 
  //
  // syncAnnotation() must not be invoked in this function.
  // 
  // 

  if (annotation == NULL)
  {
    delete mAnnotation;
    mAnnotation = NULL;
  }


  //else if (!(math->isWellFormedASTNode()))
  //{
  //  return LIBSEDML_INVALID_OBJECT;
  //}
  if (mAnnotation != annotation)
  { 
    delete mAnnotation;

    // the annotation is an rdf annotation but the object has no metaid
    if (RDFAnnotationParser::hasRDFAnnotation(annotation) == true
      && (RDFAnnotationParser::hasCVTermRDFAnnotation(annotation) == true
      || RDFAnnotationParser::hasHistoryRDFAnnotation(annotation) == true)
      && isSetMetaId() == false)
    {
      mAnnotation = NULL;
      return LIBSEDML_UNEXPECTED_ATTRIBUTE;
    }
    else
    {
      // check for annotation tags and add if necessary
      const string&  name = annotation->getName();
      if (name != "annotation")
      {
        XMLToken ann_t = XMLToken(XMLTriple("annotation", "", ""), 
                                  XMLAttributes());
        mAnnotation = new XMLNode(ann_t);

        // The root node of the given XMLNode tree can be an empty XMLNode 
        // (i.e. neither start, end, nor text XMLNode) if the given annotation was 
        // converted from an XML string whose top level elements are neither 
        // "html" nor "body" and not enclosed with <annotation>..</annotation> tags
        // (e.g. <foo xmlns:foo="...">..</foo><bar xmlns:bar="...">..</bar> ) 
        if (!annotation->isStart() && !annotation->isEnd() && 
                                      !annotation->isText()) 
        {
          for (unsigned int i=0; i < annotation->getNumChildren(); i++)
          {
            mAnnotation->addChild(annotation->getChild(i));
          }
        }
        else
        {
          mAnnotation->addChild(*annotation);
        }
      }
      else
      {
        mAnnotation = annotation->clone();
      }
    }
  }


  return LIBSEDML_OPERATION_SUCCESS;
}

/*
 * Sets the annotation (by string) of this Sed object to a copy of annotation.
 */
int
SedBase::setAnnotation (const std::string& annotation)
{
  if (&(annotation) == NULL)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else  
  {
    int success = LIBSEDML_OPERATION_FAILED;

    //
    // (*NOTICE*) 
    //
    // syncAnnotation() must not be invoked in this function.
    // 
    // 

    if(annotation.empty()) 
    {
      unsetAnnotation();
      return LIBSEDML_OPERATION_SUCCESS;
    }

    XMLNode* annt_xmln;

    // you might not have a document !!
    if (getSedDocument() != NULL)
    {
      XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
      annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns); 
    }
    else
    {
      annt_xmln = XMLNode::convertStringToXMLNode(annotation);
    }

    if(annt_xmln != NULL)
    {
      success = setAnnotation(annt_xmln);
      delete annt_xmln;
    }
    return success;
  }
}


/*
 * Appends annotation to the existing annotations.
 * This allows other annotations to be preserved whilst
 * adding additional information.
 */
int 
SedBase::appendAnnotation (const XMLNode* annotation)
{
  int success = LIBSEDML_OPERATION_FAILED;
  unsigned int duplicates = 0;


  if(annotation == NULL) 
    return LIBSEDML_OPERATION_SUCCESS;


  XMLNode* new_annotation = NULL;
  const string&  name = annotation->getName();

  // check for annotation tags and add if necessary 
  if (name != "annotation")
  {
    XMLToken ann_t = XMLToken(XMLTriple("annotation", "", ""), XMLAttributes());
    new_annotation = new XMLNode(ann_t);
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
      success = setAnnotation(mAnnotation->clone());
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
  XMLNode* annt_xmln;
  if (getSedDocument() != NULL)
  {
    XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
    annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = XMLNode::convertStringToXMLNode(annotation);
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
    std::string prefix = mAnnotation->getChild(index).getPrefix();

    if (elementURI.empty() == false 
      && elementURI != mAnnotation->getChild(index).getNamespaceURI(prefix))
    {
      success = LIBSEDML_ANNOTATION_NS_NOT_FOUND;
      return success;
    }
    
    // remove the annotation at the index corresponding to the name
    mAnnotation->removeChild(index);
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
SedBase::replaceTopLevelAnnotationElement(const XMLNode* annotation)
{
  int success = LIBSEDML_OPERATION_FAILED;
  XMLNode * replacement = NULL;
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
  XMLNode* annt_xmln;
  if (getSedDocument() != NULL)
  {
    XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
    annt_xmln = XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = XMLNode::convertStringToXMLNode(annotation);
  }
  
  if(annt_xmln != NULL)
  {
    success = replaceTopLevelAnnotationElement(annt_xmln);
    delete annt_xmln;
  }

  return success;
}


/*
 * Sets the notes of this Sed object to a copy of notes.
 */
int 
SedBase::setNotes(const XMLNode* notes)
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
    mNotes = static_cast<XMLNode*>( notes->clone() );
  }
  else
  {
    XMLToken notes_t = XMLToken(XMLTriple("notes", "", ""), 
                                XMLAttributes());
    mNotes = new XMLNode(notes_t);
  
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
  
  // in L2v2 and beyond the XHTML content of notes is restricted
  // but I need the notes tag to use the function
  // so I havent tested it until now
  if (getLevel() > 2 
    || (getLevel() == 2 && getVersion() > 1))
  {
    if (!SyntaxChecker::hasExpectedXHTMLSyntax(mNotes, NULL /*getSedNamespaces()*/))
    {
      delete mNotes;
      mNotes = NULL;
      return LIBSEDML_INVALID_OBJECT;
    }
  }

  return LIBSEDML_OPERATION_SUCCESS;

}

/*
 * Sets the notes (by std::string) of this Sed object to a copy of notes.
 */
int
SedBase::setNotes(const std::string& notes, bool addXHTMLMarkup)
{
  int success = LIBSEDML_OPERATION_FAILED;
  if (&(notes) == NULL)
  {
    success = LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else if (notes.empty())
  {
    success = unsetNotes();
  }
  else
  {
    XMLNode* notes_xmln;

    // you might not have a document !!
    if (getSedDocument() != NULL)
    {
      XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
      notes_xmln = XMLNode::convertStringToXMLNode(notes,xmlns); 
    }
    else
    {
      notes_xmln = XMLNode::convertStringToXMLNode(notes);
    }

    if(notes_xmln != NULL)
    {
      if (addXHTMLMarkup == true)
      {
        // user has specified that they want the markup added
        if (getLevel() > 2 
          || (getLevel() == 2 && getVersion() > 1))
        {
          // just say the user passed a string that did not represent xhtml
          // the xmlnode will not get set as it is invalid
          if (notes_xmln->getNumChildren() == 0 
            && notes_xmln->isStart() == false
            && notes_xmln->isEnd() == false 
            && notes_xmln->isText() == true)
          {
            //create a parent node of xhtml type p
            XMLAttributes blank_att = XMLAttributes();
            XMLTriple triple = XMLTriple("p", "http://www.w3.org/1999/xhtml", "");
            XMLNamespaces xmlns = XMLNamespaces();
            xmlns.add("http://www.w3.org/1999/xhtml", "");
            XMLNode *xmlnode = new XMLNode(XMLToken(triple, blank_att, xmlns));

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
SedBase::appendNotes(const XMLNode* notes)
{
  int success = LIBSEDML_OPERATION_FAILED;
  if(notes == NULL) 
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }

  const string&  name = notes->getName();

  // The content of notes in Sed can consist only of the following 
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
  XMLNode   addedNotes;

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
    XMLNode tmpNotes(XMLTriple("notes","",""), XMLAttributes());

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

    if (!SyntaxChecker::hasExpectedXHTMLSyntax(&tmpNotes, NULL /*getSedNamespaces()*/))
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
    XMLNode&  curNotes = *mNotes;

    // curNotes.getChild(0) must be "html", "body", or any XHTML
    // element that would be permitted within a "body" element .

    const string& cname = curNotes.getChild(0).getName();
  
    if (cname == "html")
    {
      XMLNode& curHTML = curNotes.getChild(0);
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
      XMLNode& curHTML = curNotes.getChild(0); 
      XMLNode& curBody = curHTML.getChild(1);
      
      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current html tag
  
        XMLNode& addedBody = addedNotes.getChild(1);   
  
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
  
        XMLNode  addedHTML(addedNotes);
        XMLNode& addedBody = addedHTML.getChild(1);
        XMLNode& curBody   = curNotes.getChild(0);
  
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
  
        XMLNode& curBody = curNotes.getChild(0);
  
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
  
        XMLNode  addedHTML(addedNotes);
        XMLNode& addedBody = addedHTML.getChild(1);
  
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
  
        XMLNode addedBody(addedNotes);
  
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

  XMLNode* notes_xmln;
  // you might not have a document !!
  if (getSedDocument() != NULL)
  {
      XMLNamespaces* xmlns = getSedDocument()->getNamespaces();
      notes_xmln = XMLNode::convertStringToXMLNode(notes,xmlns); 
  }
  else
  {
      notes_xmln = XMLNode::convertStringToXMLNode(notes);
  }

  if(notes_xmln != NULL)
  {
    success = appendNotes(notes_xmln);
    delete notes_xmln;
  }
  return success;
}


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument of this Sed object.
 */
void
SedBase::setSedDocument (SedDocument* d)
{
  mSed = d;

}


/*
  * Sets the parent Sed object of this Sed object.
  *
  * @param sb the Sed object to use
  */
void 
SedBase::connectToParent (SedBase* parent)
{
  mParentSedObject = parent;
  if (mParentSedObject)
  {
    setSedDocument(mParentSedObject->getSedDocument());
  }
  else
  {
    setSedDocument(NULL);
  }
}


/*
 * Sets this Sed object to child Sed objects (if any).
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
SedBase::getAncestorOfType(int type, const std::string pkgName)
{
  if (pkgName == "core" && type ==SEDML_DOCUMENT)
    return getSedDocument();

  SedBase *child = this;
  SedBase *parent = getParentSedObject();

  while ( parent != NULL && 
          !( parent->getTypeCode() ==SEDML_DOCUMENT )
        )
  {
    if (parent->getTypeCode() == type )
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
SedBase::getAncestorOfType(int type, const std::string pkgName) const
{
  if (pkgName == "core" && type ==SEDML_DOCUMENT)
    return getSedDocument();

  const SedBase *child = this;
  const SedBase *parent = getParentSedObject();

  while ( parent != NULL && 
          !( parent->getTypeCode() ==SEDML_DOCUMENT )
        )
  {
    if (parent->getTypeCode() == type )
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
 * Sets the namespaces relevant of this Sed object.
 *
 * @param xmlns the namespaces to set
 */
int 
SedBase::setNamespaces(XMLNamespaces* xmlns)
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
 * Unsets the metaid of this Sed object.
 */
int
SedBase::unsetMetaId ()
{
  /* only in L2 onwards */
  if (getLevel() < 2)
  {
    return LIBSEDML_UNEXPECTED_ATTRIBUTE;
  }

  mMetaId.erase();

  if (mMetaId.empty())
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the id of this Sed object.
 */
int
SedBase::unsetId ()
{
  return LIBSEDML_OPERATION_FAILED;  
}


/*
 * Unsets the name of this Sed object.
 */
int
SedBase::unsetName ()
{
  return LIBSEDML_OPERATION_FAILED;  
}


/*
 * Unsets the notes of this Sed object.
 */
int
SedBase::unsetNotes ()
{
  delete mNotes;
  mNotes = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the annotation of this Sed object.
 */
int
SedBase::unsetAnnotation ()
{
  XMLNode* empty = NULL;
  return setAnnotation(empty);
}


/*
 * @return the Sed level of this Sed object.
 */
const int
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
 * @return the Sed version of this Sed object.
 */
const int
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
 * @return the typecode (int) of this Sed object orSEDML_UNKNOWN
 * (default).
 *
 * This method MAY return the typecode of this Sed object or it MAY
 * returnSEDML_UNKNOWN.  That is, subclasses of SedBase are not required to
 * implement this method to return a typecode.  This method is meant
 * primarily for the LibSed C interface where class and subclass
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
  XMLNamespaces *xmlns = getNamespaces();  

  return hasValidLevelVersionNamespaceCombination(typecode, xmlns);
}

/** @cond doxygen-libsbml-internal */

bool
SedBase::matchesSedNamespaces(const SedBase * sb)
{
  bool match = matchesCoreSedNamespace(sb);

  if (match == true)
  {
    SedNamespaces *sbmlns = getSedNamespaces();
    SedNamespaces *sbmlns_rhs = sb->getSedNamespaces();

	//TODO
    //if (sbmlns->getNamespaces()->containIdenticalSetNS(
    //  sbmlns_rhs->getNamespaces()) == false)
    //{
    //  match = false;
    //}
  }

  return match;
}

bool
SedBase::matchesSedNamespaces(const SedBase * sb) const
{
  bool match = matchesCoreSedNamespace(sb);

  if (match == true)
  {
    SedNamespaces *sbmlns = getSedNamespaces();
    SedNamespaces *sbmlns_rhs = sb->getSedNamespaces();

	// TODO: 
    //if (sbmlns->getNamespaces()->containIdenticalSetNS(
    //  sbmlns_rhs->getNamespaces()) == false)
    //{
    //  match = false;
    //}
  }

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

  SedNamespaces *sbmlns = getSedNamespaces();
  SedNamespaces *sbmlns_rhs = sb->getSedNamespaces();

  if (sbmlns->getLevel() != sbmlns_rhs->getLevel())
    return match;

  if (sbmlns->getVersion() != sbmlns_rhs->getVersion())
    return match;

  std::string coreNs = SedNamespaces::getSedNamespaceURI(
                       sbmlns->getLevel(), sbmlns->getVersion());

  if (sbmlns->getNamespaces()->containsUri(coreNs)
    && sbmlns_rhs->getNamespaces()->containsUri(coreNs))
  {
    match = true;
  }

  //if (sbmlns->getNamespaces()->containIdenticalSetNS(sbmlns_rhs->getNamespaces()) 
  //                                     == true)
  //{
  //  match = true;
  //}

  return match;
}


bool
SedBase::matchesCoreSedNamespace(const SedBase * sb) const
{
  bool match = false;

  SedNamespaces *sbmlns = getSedNamespaces();
  SedNamespaces *sbmlns_rhs = sb->getSedNamespaces();

  if (sbmlns->getLevel() != sbmlns_rhs->getLevel())
    return match;

  if (sbmlns->getVersion() != sbmlns_rhs->getVersion())
    return match;

  std::string coreNs = SedNamespaces::getSedNamespaceURI(
                       sbmlns->getLevel(), sbmlns->getVersion());

  if (sbmlns->getNamespaces()->containsUri(coreNs)
    && sbmlns_rhs->getNamespaces()->containsUri(coreNs))
  {
    match = true;
  }

  //if (sbmlns->getNamespaces()->containIdenticalSetNS(sbmlns_rhs->getNamespaces()) 
  //                                     == true)
  //{
  //  match = true;
  //}

  return match;
}


bool 
SedBase::hasValidLevelVersionNamespaceCombination(int typecode, XMLNamespaces *xmlns)
{
  
  
  //
  // (TODO) Currently, the following check code works only for
  //        elements in Sed core.
  //        This function may need to be extented for other elements 
  //        defined in each package extension.
  //

  bool valid = true;
  bool sedmlDeclared = false;
  std::string declaredURI("");
  unsigned int version = getVersion();
  
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

  return valid;
}

/* sets the Sednamespaces - internal use only*/
int 
SedBase::setSedNamespaces(SedNamespaces * sbmlns)
{
  if (sbmlns == NULL)
    return LIBSEDML_INVALID_OBJECT;

  SedNamespaces* sbmlnsClone = (sbmlns) ? sbmlns->clone() : 0;
  setSedNamespacesAndOwn(sbmlnsClone);

  return LIBSEDML_OPERATION_SUCCESS;
}

/*
 * sets the Sednamespaces - only for internal use in the
 * constructors of SedBase subclasses in extension packages.
 */
void
SedBase::setSedNamespacesAndOwn(SedNamespaces * sbmlns)
{
  delete mSedNamespaces;
  mSedNamespaces = sbmlns;

  if(sbmlns != NULL)
    setElementNamespace(sbmlns->getURI());
}


/* gets the Sednamespaces - internal use only*/
SedNamespaces *
SedBase::getSedNamespaces() const
{
  if (mSed != NULL)
    return mSed->mSedNamespaces;
  else if (mSedNamespaces != NULL)
    return mSedNamespaces;
  else
    return new SedNamespaces();
}

/** @endcond */



/*
 * @return the partial Sed that describes this Sed object.
 */
char*
SedBase::toSed ()
{
  ostringstream    os;
  XMLOutputStream  stream(os, "UTF-8", false);

  write(stream);

  return safe_strdup( os.str().c_str() );
}


/** @cond doxygen-libsbml-internal */
/*
 * Reads (initializes) this Sed object by reading from XMLInputStream.
 */
void
SedBase::read (XMLInputStream& stream)
{
  if ( !stream.peek().isStart() ) return;

  const XMLToken  element  = stream.next();
  int             position =  0;

  setSedBaseFields( element );

  ExpectedAttributes expectedAttributes;
  addExpectedAttributes(expectedAttributes);
  readAttributes( element.getAttributes(), expectedAttributes );

  /* if we are reading a document pass the
   * Sed Namespace information to the input stream object
   * thus the MathML reader can find out what level/version
   * of Sed it is parsing
   */
  if (element.getName() == "sedML")
  {
    SedNamespaces *ns = new SedNamespaces(getLevel(), getVersion());
    //stream.setNamespaces(this->getSedNamespaces());
    // need to check that any prefix on the sbmlns also occurs on element
    // remembering the horrible situation where the sbmlns might be declared
    // with more than one prefix
    XMLNamespaces * xmlns = this->getSedNamespaces()->getNamespaces();
    if (xmlns != NULL)
    {
      int i = xmlns->getIndexByPrefix(element.getPrefix());
      if (i < xmlns->getNumNamespaces())
      {
        bool errorLoggedAlready = false;
        bool error = false;
        if (i > -1)
        {
          if (xmlns->getURI(i) != ns->getURI())
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
          if (errorId == SedMissingOrInconsistentLevel
            || errorId == SedMissingOrInconsistentVersion
            || errorId == SedInvalidSedLevelVersion
            || errorId == SedInvalidNamespaceOnSed)
          {
            errorLoggedAlready = true;
          }
        }
       
        if (error == true && errorLoggedAlready == false)
        {
          static ostringstream errMsg;
          errMsg.str("");
          errMsg << "The prefix for the <sedML> element does not match "
            << "the prefix for the Sed namespace.  This means that "
            << "the <sedML> element in not in the SED-ML Namespace."<< endl;

          logError(SedInvalidNamespaceOnSed,
                    getLevel(), getVersion(), errMsg.str());
        }      


        // add it to the namespace
        ns->getNamespaces()->add(xmlns->getURI(i), xmlns->getPrefix(i));
      }
    }
    setSedNamespaces(ns);
  }
  else
  {
    //
    // checks if the given default namespace (if any) is a valid
    // Sed namespace
    //
    checkDefaultNamespace(mSedNamespaces->getNamespaces(), element.getName());
    if (!element.getPrefix().empty())
    {
      XMLNamespaces * prefixedNS = new XMLNamespaces();
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

    const XMLToken& next = stream.peek();

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
#if 0
      cout << "[DEBUG] SedBase::read " << nextName << " uri "
           << stream.peek().getURI() << endl;
#endif

      SedBase * object = createObject(stream);
      
      if (object != NULL)
      {
        checkOrderAndLogError(object, position);
        position = object->getElementPosition();

        object->connectToParent(static_cast <SedBase*>(this));

        object->read(stream);

        if ( !stream.isGood() ) break;

        checkListOfPopulated(object);
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

/** @cond doxygen-libsbml-internal */
/*
 * Writes (serializes) this Sed object by writing it to XMLOutputStream.
 */
void
SedBase::write (XMLOutputStream& stream) const
{
  XMLNamespaces *xmlns = getNamespaces();

  if (0)
  {
    cout << "[DEBUG] SedBase::write (element name) " << getElementName()
         << " (element ns) " << getElementNamespace(); 

    if (xmlns)
    {
      cout << " (xmlns) ";
      XMLOutputStream xos(std::cout);
      xos << *xmlns;
      cout << endl;
    }
  
  }

  stream.startElement( getElementName(), getPrefix() );

  writeXMLNS     ( stream );
  writeAttributes( stream );
  writeElements  ( stream );

  stream.endElement( getElementName(), getPrefix() );

}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to write out their contained
 * Sed objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
SedBase::writeElements (XMLOutputStream& stream) const
{
  if ( mNotes != NULL ) stream << *mNotes;

  /*
   * NOTE: CVTerms on a model have already been dealt with
   */

  const_cast <SedBase *> (this)->syncAnnotation();
  if (mAnnotation != NULL) stream << *mAnnotation;
}

/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to create, store, and then
 * return an Sed object corresponding to the next XMLToken in the
 * XMLInputStream.
 *
 * @return the Sed object corresponding to next XMLToken in the
 * XMLInputStream or @c NULL if the token was not recognized.
 */
SedBase*
SedBase::createObject (XMLInputStream& stream)
{
  return NULL;
}


/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to read (and store) XHTML,
 * MathML, etc. directly from the XMLInputStream.
 *
 * @return true if the subclass read from the stream, false otherwise.
 */
bool
SedBase::readOtherXML (XMLInputStream& stream)
{
  bool read = false;

  return read;
}


/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * @return true if read an <annotation> element from the stream
 */
bool
SedBase::readAnnotation (XMLInputStream& stream)
{
  const string& name = stream.peek().getName();

  if (name == "annotation" 
    || (getLevel() == 1 && getVersion() == 1 && name == "annotations"))
  {
//    XMLNode* new_annotation = NULL;
    // If this is a level 1 document then annotations are not allowed on
    // the sbml container
    if (getLevel() == 1 && getTypeCode() ==SEDML_DOCUMENT)
    {
      logError(SedAnnotationNotesNotAllowedLevel1);
    }


    // If an annotation already exists, log it as an error and replace
    // the content of the existing annotation with the new one.

    if (mAnnotation != NULL)
    {
      if (getLevel() < 3) 
      {
        logError(SedNotSchemaConformant, getLevel(), getVersion(),
	        "Only one <annotation> element is permitted inside a "
	        "particular containing element.");
      }
      else
      {
        logError(SedMultipleAnnotations, getLevel(), getVersion());
      }
    }

    delete mAnnotation;
    mAnnotation = new XMLNode(stream);
    checkAnnotation();
    return true;
  }

  return false;
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * @return true if read a <notes> element from the stream
 */
bool
SedBase::readNotes (XMLInputStream& stream)
{
  const string& name = stream.peek().getName();

  if (name == "notes")
  {
    // If this is a level 1 document then notes are not allowed on
    // the sbml container
    if (getLevel() == 1 && getTypeCode() ==SEDML_DOCUMENT)
    {
      logError(SedAnnotationNotesNotAllowedLevel1);
    }

    // If a notes element already exists, then it is an error.
    // If an annotation element already exists, then the ordering is wrong.
    // In either case, replace existing content with the new notes read.

    if (mNotes != NULL)
    {
      if (getLevel() < 3)
      {
        logError(SedNotSchemaConformant, getLevel(), getVersion(),
                "Only one <notes> element is permitted inside a "
	            "particular containing element.");
      }
      else
      {
        logError(SedOnlyOneNotesElementAllowed, getLevel(), getVersion());
      }
    }
    else if (mAnnotation != NULL)
    {
      logError(SedNotSchemaConformant, getLevel(), getVersion(),
               "Incorrect ordering of <annotation> and <notes> elements -- "
               "<notes> must come before <annotation> due to the way that "
               "the XML Schema for Sed is defined.");
    }

    delete mNotes;
    mNotes = new XMLNode(stream);

    //
    // checks if the given default namespace (if any) is a valid
    // Sed namespace
    //
    const XMLNamespaces &xmlns = mNotes->getNamespaces();
    checkDefaultNamespace(&xmlns,"notes");

    if (getSedDocument() != NULL)
    {
      //if (getSedDocument()->getNumErrors() == 0)
      //{
      //  checkXHTML(mNotes);
      //}
    }
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


/** @cond doxygen-libsbml-internal */
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


/** @cond doxygen-libsbml-internal */
/*
 * @return the SedErrorLog used to log errors during while reading and
 * validating Sed.
 */
SedErrorLog*
SedBase::getErrorLog ()
{
  return (mSed != NULL) ? mSed->getErrorLog() : NULL;
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
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

  {
    msg << "Attribute '" << attribute << "' is not part of the "
        << "definition of an Sed Level " << level
        << " Version " << version << " " << element << " element.";
  }
  /* Akiya made this note - so it needs checking BUT if it can crash due to no
   * SedDocument object then it can crash whatever level - so I put the catch outside
   */
  if (mSed)
  {
      getErrorLog()->logError(SedNotSchemaConformant,
  			    level, version, msg.str(), getLine(), getColumn());
  }
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Helper to log a common type of error.
 */
void
SedBase::logUnknownElement( const string& element,
			  const unsigned int level,
			  const unsigned int version )
{
  bool logged = false;
  ostringstream msg;

  
  if (logged == false)
  {

    ostringstream msg;

    msg << "Element '" << element << "' is not part of the definition of "
        << "Sed Level " << level << " Version " << version << ".";
      
    if (mSed != NULL)
    {
      getErrorLog()->logError(SedUnrecognizedElement,
			      level, version, msg.str(), getLine(), getColumn());
    }
  }
  
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
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


/** @cond doxygen-libsbml-internal */
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
                 , const std::string& details )
{
  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SedDocument attached.
  //
  if ( SedBase::getErrorLog() != NULL && mSed != NULL) 
    getErrorLog()->logError(id, getLevel(), getVersion(), details, getLine(), getColumn());
}
/** @endcond */


/** @cond doxygen-libsbml-internal */

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
  if (getLevel() > 1 )
    attributes.add("metaid");  

}


/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
SedBase::readAttributes (const XMLAttributes& attributes, 
                       const ExpectedAttributes& expectedAttributes)
{
  const_cast<XMLAttributes&>(attributes).setErrorLog(getErrorLog());

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
    // if we happen to be on the sbml element (document) then
    // getPrefix() and mURI have not been set and just return defaults
    // thus a prefix does not appear to come from the right place !!!
    if (!prefix.empty() && getElementName() == "sbml")
    {
      if (!expectedAttributes.hasAttribute(name))
      {
        logUnknownAttribute(name, level, version, getElementName());
      }    
    }
    else if (!expectedAttributes.hasAttribute(name))
    {
      logUnknownAttribute(name, level, version, getElementName(), prefix);
    }
  }

  if (level > 1)
  {
    bool assigned = attributes.readInto("metaid", mMetaId, getErrorLog(), false, getLine(), getColumn());
  
    if (assigned && mMetaId.empty())
    {
      logEmptyString("metaid", level, version,
                     SedTypeCode_toString(getTypeCode()));
    }

    if (isSetMetaId())
    {
      if (!SyntaxChecker::isValidXMLID(mMetaId))
      {
        logError(SedInvalidMetaidSyntax, getLevel(), getVersion());
      }
    }
  }

  
}

/** @endcond */


/** @cond doxygen-libsbml-internal */


/*
 * Returns the prefix of this element.
 */
std::string 
SedBase::getPrefix() const
{
  std::string prefix = "";

  XMLNamespaces *xmlns = getNamespaces();
  string uri = getURI();
  if(xmlns && mSed && false)//!mSed->isEnabledDefaultNS(uri))
  {
    prefix = xmlns->getPrefix(uri);  
#if 0
    std::cout << "[DEBUG] SedBase::getPrefix() " << prefix << " URI " << mURI 
              << " element " << getElementName() << std::endl;
#endif
  }
#if 0
  else
  {
    if (!xmlns)
    {
      std::cout << "[DEBUG] SedBase::getPrefix() [NO XMLNS] " << prefix << " URI " << mURI 
              << " element " << getElementName() << std::endl;
    }
    if (!mSed)
    {
      std::cout << "[DEBUG] SedBase::getPrefix() [NO mSed] " << prefix << " URI " << mURI 
              << " element " << getElementName() << std::endl;
    }
  
  }
#endif

  return prefix;
}


/*
 * Returns the prefix of this element.
 */
std::string 
SedBase::getSedPrefix() const
{
  std::string prefix = "";

  XMLNamespaces *xmlns = getNamespaces();
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
 * Sed object (i.e. mParentSedObject is NULL)
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
SedBase::writeAttributes (XMLOutputStream& stream) const
{
//  if (getTypeCode() ==SEDML_DOCUMENT)
//  {
//    if (this->getNamespaces()) stream << *(this->getNamespaces());
//  }
  unsigned int level   = getLevel();
  unsigned int version = getVersion();
  string sbmlPrefix    = getSedPrefix();
  if ( level > 1 && !mMetaId.empty() )
  {
    stream.writeAttribute("metaid", sbmlPrefix, mMetaId);
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
SedBase::writeXMLNS (XMLOutputStream& stream) const
{
  // do nothing.
}


/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Synchronizes the annotation of this Sed object. 
 */
void
SedBase::syncAnnotation ()
{

  if (mAnnotation == NULL)
  {
    XMLToken ann_token = XMLToken(XMLTriple("annotation", "", ""), 
                                      XMLAttributes());
    mAnnotation = new XMLNode(ann_token);
  }

  // if annotation still empty delete the annotation
  if (mAnnotation != NULL && mAnnotation->getNumChildren() == 0)
  {
    delete mAnnotation;
    mAnnotation = NULL;
  }

}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Checks that Sed element has been read in the proper order.  If object
 * is not in the expected position, an error is logged.
 */
void
SedBase::checkOrderAndLogError (SedBase* object, int expected)
{
  int actual = object->getElementPosition();

  if (actual != -1 && actual < expected)
  {
    SedErrorCode_t error = SedIncorrectOrderInModel;

    
    {
      if (object->getTypeCode() ==SEDML_LIST_OF)
      {
        int tc = static_cast<SedListOf*>(object)->getItemTypeCode();
        //typecode (int) tc = static_cast<SedListOf*>(object)->getItemTypeCode();

      }

      logError(error, getLevel(), getVersion());
    }
  }
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
  * Checks that an Sed SedListOf element has been populated.  
  * If a listOf element has been declared with no elements, 
  * an error is logged.
  */
void 
SedBase::checkListOfPopulated(SedBase* object)
{
  //
  // (TODO) Currently, the following check code works only for
  //        elements in Sed core.
  //        This function may need to be extented for other elements 
  //        defined in each package extension.
  //

  if (object->getTypeCode() ==SEDML_LIST_OF)
  {
    // Check that the list has at least one element.
    if (static_cast <SedListOf*> (object)->size() == 0)
    {
      //typecode (int) tc = static_cast<SedListOf*>(object)->getItemTypeCode();
      int tc = static_cast<SedListOf*>(object)->getItemTypeCode();
      SedErrorCode_t error = SedEmptyListElement;

      // By default, the error will be the EmptyListElement error, unless
      // we have a special case for which Sed has a separate error code.

      logError(error, getLevel(), getVersion());
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
  for (unsigned int i=0; i<parentList->size(); i++) {
    SedBase* sibling = parentList->get(i);
    if (sibling == this) {
      parentList->remove(i);
      delete this;
      return LIBSEDML_OPERATION_SUCCESS;
    }
  }
  return LIBSEDML_OPERATION_FAILED;
}

/** @cond doxygen-libsbml-internal */
const std::string
SedBase::checkMathMLNamespace(const XMLToken elem)
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
    logError(SedInvalidMathElement);
  }

  return prefix;
}
/** @endcond */


/** @cond doxygen-libsbml-internal */

void 
SedBase::checkDefaultNamespace(const XMLNamespaces* xmlns, 
                             const std::string& elementName,
                             const std::string& prefix)
{
  //
  // checks if the given default namespace (if any) is a valid
  // Sed namespace
  //
  if (xmlns != NULL && xmlns->getLength() > 0)
  {
    const std::string defaultURI = xmlns->getURI(prefix);
    if (!defaultURI.empty() && mURI != defaultURI)
    {
      static ostringstream errMsg;
      errMsg.str("");
      errMsg << "xmlns=\"" << defaultURI << "\" in <" << elementName
             << "> element is an invalid namespace." << endl;
      
      logError(SedNotSchemaConformant, getLevel(), getVersion(), errMsg.str());
    }
  }
}

/*
  * Checks the annotation does not declare an sbml namespace.
  * If the annotation declares an sbml namespace an error is logged.
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
  // Sed namespace
  //
  const XMLNamespaces &xmlns = mAnnotation->getNamespaces();
  checkDefaultNamespace(&xmlns,"annotation");

  while (nNodes < mAnnotation->getNumChildren())
  {
    XMLNode topLevel = mAnnotation->getChild(nNodes);

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
        logError(SedDuplicateAnnotationNamespaces);
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
      if(mSed != NULL &&  mSed->getNamespaces() != NULL)
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
    // cannot declare sbml namespace
    while(!match && n < topLevel.getNamespaces().getLength())
    {
      match += !strcmp(topLevel.getNamespaces().getURI(n).c_str(), 
                                          "http://sed-ml.org/");
      n++;
    }
    if (match > 0)
    {
      logError(SedSedNamespaceInAnnotation);
      break;
    }

    if (implicitNSdecl && prefix.empty())
    {
      /* if this is L3 a missing namespace with empty prefix means 
       * it is using the sbml ns - which is allowed in L3
       */
      if (getLevel() < 3)
      {
        logError(SedMissingAnnotationNamespace);
      }
      logError(SedSedNamespaceInAnnotation);
    }
    nNodes++;
  }
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Checks that the XHTML is valid.
 * If the xhtml does not conform to the specification of valid xhtml within
 * an sbml document, an error is logged.
 */
void
SedBase::checkXHTML(const XMLNode * xhtml)
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
  else if (name == "message")
  {
    errorNS   = SedConstraintNotInXHTMLNamespace;
    errorXML  = SedConstraintContainsXMLDecl;
    errorDOC  = SedConstraintContainsDOCTYPE;
    errorELEM = SedInvalidConstraintContent;
  }
  else                                  // We shouldn't ever get to this point.
  {
    logError(SedUnknownError);
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

  XMLNamespaces* toplevelNS = (mSed) ? mSed->getNamespaces() : NULL;

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
/** @cond doxygen-libsbml-internal */
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

void
SedBase::removeDuplicateAnnotations()
{
  bool resetNecessary = false;
  XMLNamespaces xmlns = XMLNamespaces();
  xmlns.add("http://www.sbml.org/libsbml/annotation", "");
  XMLTriple triple = XMLTriple("duplicateTopLevelElements",
    "http://www.sbml.org/libsbml/annotation", "");
  XMLAttributes att = XMLAttributes();
  XMLToken token = XMLToken(triple, att, xmlns);
  XMLNode * newNode = NULL;
  if (isSetAnnotation())
  { 
    //make a copy to work with
    XMLNode * newAnnotation = mAnnotation->clone();

    unsigned int numChildren = newAnnotation->getNumChildren();
    if (numChildren == 1)
      return;

    bool duplicate = false;
    for (unsigned int i = 0; i < numChildren; i++)
    {
      duplicate = false;
      std::string name = newAnnotation->getChild(i).getName();
      for (unsigned int j = numChildren-1; j > i; j--)
      {
        if (name == newAnnotation->getChild(j).getName())
        {
          resetNecessary = true;
          duplicate = true;
          if (newNode == NULL)
          {
            // need to  create the new node
            newNode = new XMLNode(token);
          }
          newNode->addChild(static_cast <XMLNode> 
                            (*(newAnnotation->removeChild(j))));
        }
      }
      if (duplicate)
        newNode->addChild(static_cast <XMLNode>
                          (*(newAnnotation->removeChild(i))));
      numChildren = newAnnotation->getNumChildren();
    }
    if (resetNecessary)
    {
      newAnnotation->addChild(*(newNode));
      setAnnotation(newAnnotation);
    }
  }


}


/** @endcond */

/** @cond doxygen-libsbml-internal */
/*
 * Stores the location (line and column) and any XML namespaces (for
 * roundtripping) declared on this Sed (XML) element.
 */
void
SedBase::setSedBaseFields (const XMLToken& element)
{
  mLine   = element.getLine  ();
  mColumn = element.getColumn();

  if (element.getNamespaces().getLength() > 0)
  {
    XMLNamespaces tmpxmlns(element.getNamespaces());
    setNamespaces(&tmpxmlns);
  }
  else
  {
    setNamespaces(NULL);
  }
}


/*
 *
 * Sets the XML namespace to which this element belogns to.
 * For example, all elements that belong to Sed Level 1 Version 1 
 * must set the namespace to "http://sed-ml.org/";
 *
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



/** @cond doxygen-c-only */


/**
 * Returns the value of the "metaid" attribute of the given SedBase_t
 * structure.
 *
 * @param sb the SedBase_t structure
 * 
 * @return the value of the "metaid" attribute of @p sb
 */
LIBSEDML_EXTERN
const char *
SedBase_getMetaId (SedBase_t *sb)
{
  return (sb != NULL && sb->isSetMetaId()) ? sb->getMetaId().c_str() : NULL;
}


///**
// * Returns the value of the "id" attribute of the given SedBase_t
// * structure.
// *
// * @param sb the SedBase_t structure
// * 
// * @return the value of the "id" attribute of @p sb
// */
//LIBSEDML_EXTERN
//const char *
//SedBase_getId (const SedBase_t *sb)
//{
//  return sb->isSetId() ? sb->getId().c_str() : NULL;
//}
//
//
///**
// * Returns the value of the "name" attribute of the given SedBase_t
// * structure.
// *
// * @param sb the SedBase_t structure
// * 
// * @return the value of the "name" attribute of @p sb
// */
//LIBSEDML_EXTERN
//const char *
//SedBase_getName (const SedBase_t *sb)
//{
//  return sb->isSetName() ? sb->getName().c_str() : NULL;
//}


/**
 * Returns the parent SedDocument_t structure of the given SedBase_t
 * structure.
 *
 * @param sb the SedBase_t structure
 * 
 * @return the parent SedDocument of this Sed object.
 */
LIBSEDML_EXTERN
const SedDocument_t *
SedBase_getSedDocument (SedBase_t *sb)
{
  return (sb != NULL) ? sb->getSedDocument() : NULL;
}


/**
 * Returns the parent SedBase_t structure of the given SedBase_t
 * structure.
 *
 * @param sb the SedBase_t structure
 * 
 * @return the parent SedBase  of this Sed object.
 */
LIBSEDML_EXTERN
const SedBase_t *
SedBase_getParentSedObject (SedBase_t *sb)
{
  return (sb != NULL) ? sb->getParentSedObject() : NULL;
}


/**
 * Returns the ancestor SedBase_t structure of the given SedBase_t
 * structure that corresponds to the given type.
 *
 * This function allows any object to determine its exact 
 * location/function within a model. For example a 
 * StoichiometryMath object has ancestors of type SpeciesReference,
 * SedListOf(Products/Reactants), Reaction, ListOfReactions and Model; 
 * any of which can be accessed via this function.
 *
 * @param sb the SedBase_t structure
 * @param type the typecode (int) of the structure to be returned
 * 
 * @return the ancestor SedBase_t structure of this Sed object with
 * the corresponding typecode (int), NULL if there is no ancestor of
 * this type.
 */
LIBSEDML_EXTERN
const SedBase_t *
SedBase_getAncestorOfType (SedBase_t *sb, int type, const char* pkgName)
{
  return (sb != NULL) ? sb->getAncestorOfType(type, pkgName) : NULL;
}


/**
 * Returns the Sed Level of the overall Sed document.
 *
 * @param sb the SedBase_t structure to query
 * 
 * @return the Sed level of the given object.
 * 
 * @see getVersion()
 */
LIBSEDML_EXTERN
unsigned int
SedBase_getLevel (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getLevel() :SEDML_INT_MAX;
}


/**
 * Returns the Version within the Sed Level of the overall Sed document.
 *
 * @param sb the SedBase_t structure to query
 * 
 * @return the Sed version of the given object.
 *
 * @see getLevel()
 */
LIBSEDML_EXTERN
unsigned int
SedBase_getVersion (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getVersion() :SEDML_INT_MAX;
}


/**
 * Returns the notes from given Sed object.
 *
 * @param sb the given Sed object.
 *
 * @return the XMLNode_t structure representing the notes from this object.
 */
LIBSEDML_EXTERN
XMLNode_t *
SedBase_getNotes (SedBase_t *sb)
{
  return (sb != NULL) ? sb->getNotes() : NULL;
}


/**
 * Returns the notes string from given Sed object.
 * The string is owned by the caller and should be freed
 * (with free()) when no longer needed.  
 *
 * @param sb the given Sed object.
 *
 * @return the string (char*) representing the notes from this object.
 */
LIBSEDML_EXTERN
char*
SedBase_getNotesString (SedBase_t *sb)
{
  return (sb != NULL && sb->isSetNotes()) ? 
    safe_strdup(sb->getNotesString().c_str()) : NULL;
}


/**
 * Returns the annotation from given Sed object.
 *
 * @param sb the given Sed object.
 *
 * @return the XMLNode_t structure representing the annotation from this object.
 */
LIBSEDML_EXTERN
XMLNode_t *
SedBase_getAnnotation (SedBase_t *sb)
{
  return (sb != NULL) ? sb->getAnnotation() : NULL;
}


/**
 * Returns the annotation string from given Sed object.
 * The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @param sb the given Sed object.
 *
 * @return the string (char*) representing the annotation from this object.
 */
LIBSEDML_EXTERN
char*
SedBase_getAnnotationString (SedBase_t *sb)
{
  return (sb != NULL && sb->isSetAnnotation()) ? 
    safe_strdup(sb->getAnnotationString().c_str()) : NULL;
}


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "metaid" attribute is set.
 *
 * @param sb the SedBase_t structure to query
 * 
 * @return nonzero (for true) if the "metaid" attribute of this Sed object
 * is set, zero (for false) otherwise.
 */
LIBSEDML_EXTERN
int
SedBase_isSetMetaId (const SedBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetMetaId() ) : 0;
}


///**
// * Predicate returning nonzero true or false depending on whether the given
// * structure's "id" attribute is set.
// *
// * @param sb the SedBase_t structure to query
// * 
// * @return nonzero (for true) if the "id" attribute of this Sed object
// * is set, zero (for false) otherwise.
// */
//LIBSEDML_EXTERN
//int
//SedBase_isSetId (const SedBase_t *sb)
//{
//  return static_cast<int>( sb->isSetId() );
//}
//
//
///**
// * Predicate returning nonzero true or false depending on whether the given
// * structure's "name" attribute is set.
// *
// * @param sb the SedBase_t structure to query
// * 
// * @return nonzero (for true) if the "name" attribute of this Sed object
// * is set, zero (for false) otherwise.
// */
//LIBSEDML_EXTERN
//int
//SedBase_isSetName (const SedBase_t *sb)
//{
//  return static_cast<int>( sb->isSetName() );
//}


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "notes" subelement is set.
 *
 * @param sb the SedBase_t structure to query
 * 
 * @return nonzero (for true) if the "notes" subelement of this Sed object
 * is set, zero (for false) otherwise.
 */
LIBSEDML_EXTERN
int
SedBase_isSetNotes (const SedBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetNotes() ) : 0;
}


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "annotation" subelement is set.
 *
 * @param sb the SedBase_t structure to query
 * 
 * @return nonzero (for true) if the "annotation" subelement of this Sed object
 * is set, zero (for false) otherwise.
 */
LIBSEDML_EXTERN
int
SedBase_isSetAnnotation (const SedBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetAnnotation() ) : 0;
}



/**
 * Sets the value of the "metaid" attribute of the given object.
 *
 * The string @p metaid is copied.  The value of @p metaid must be an
 * identifier conforming to the syntax defined by the XML 1.0 data type
 * ID.  Among other things, this type requires that a value is unique
 * among all the values of type XML ID in an SedDocument.  Although Sed
 * only uses XML ID for the "metaid" attribute, callers should be careful
 * if they use XML ID's in XML portions of a model that are not defined
 * by Sed, such as in the application-specific content of the
 * "annotation" subelement.
 *
 * @param sb the SedBase_t structure
 *
 * @param metaid the identifier string to use as the value of the
 * "metaid" attribute
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 * @li LIBSEDML_UNEXPECTED_ATTRIBUTE
 *
 * @note Using this function with the metaid set to NULL is equivalent to
 * unsetting the "metaid" attribute.
 */
LIBSEDML_EXTERN
int
SedBase_setMetaId (SedBase_t *sb, const char *metaid)
{
  if (sb != NULL)
    return (metaid == NULL) ? sb->unsetMetaId() : sb->setMetaId(metaid);
  else
    return LIBSEDML_INVALID_OBJECT;
}


///**
// * Sets the value of the "id" attribute of this Sed object.
// *
// * The string @p sid is copied.  Note that Sed has strict requirements
// * for the syntax of identifiers.  The following is summary of the
// * definition of the Sed identifier type @c SId (here expressed in an
// * extended form of BNF notation):
// * @code
// *   letter ::= 'a'..'z','A'..'Z'
// *   digit  ::= '0'..'9'
// *   idChar ::= letter | digit | '_'
// *   SId    ::= ( letter | '_' ) idChar*
// * @endcode
// * The equality of Sed identifiers is determined by an exact character
// * sequence match; i.e., comparisons must be performed in a
// * case-sensitive manner.  In addition, there are a few conditions for
// * the uniqueness of identifiers in an Sed model.  Please consult the
// * Sed specifications for the exact formulations.
// *
// * @param sb the SedBase_t structure
// *
// * @param sid the string to use as the identifier of this object
// *
// * @return integer value indicating success/failure of the
// * function.  @if clike The value is drawn from the
// * enumeration #OperationReturnValues_t. @endif@~ The possible values
// * returned by this function are:
// *
// * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
// * @li @link OperationReturnValues_t#LIBSEDML_INVALID_ATTRIBUTE_VALUE LIBSEDML_INVALID_ATTRIBUTE_VALUE @endlink
// *
// * @note Using this function with an id of NULL is equivalent to
// * unsetting the "id" attribute.
// */
//LIBSEDML_EXTERN
//int
//SedBase_setId (SedBase_t *sb, const char *sid)
//{
//  return (sid == NULL) ? sb->unsetId() : sb->setId(sid);
//}
//
//
///**
// * Sets the value of the "name" attribute of this Sed object.
// *
// * The string in @p name is copied.
// *
// * @param sb the SedBase_t structure
// *
// * @param name the new name for the object
// *
// * @return integer value indicating success/failure of the
// * function.  @if clike The value is drawn from the
// * enumeration #OperationReturnValues_t. @endif@~ The possible values
// * returned by this function are:
// *
// * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
// * @li @link OperationReturnValues_t#LIBSEDML_INVALID_ATTRIBUTE_VALUE LIBSEDML_INVALID_ATTRIBUTE_VALUE @endlink
// *
// * @note Using this function with the name set to NULL is equivalent to
// * unsetting the "name" attribute.
// */
//LIBSEDML_EXTERN
//int
//SedBase_setName (SedBase_t *sb, const char *name)
//{
//  return (name == NULL) ? sb->unsetName() : sb->setName(name);
//}



/**
 * Sets the namespaces relevant of this Sed object.
 *
 * @param sb the SedBase_t structure
 *
 * @param xmlns the namespaces to set
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 */
LIBSEDML_EXTERN
int
SedBase_setNamespaces (SedBase_t *sb, XMLNamespaces_t *xmlns)
{
  if (sb != NULL)
    return sb->setNamespaces(xmlns);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Sets the notes for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param notes the XMLNode_t structure respresenting the notes.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_OBJECT
 */
LIBSEDML_EXTERN
int
SedBase_setNotes (SedBase_t *sb, XMLNode_t *notes)
{
  if (sb != NULL)
    return sb->setNotes(notes);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Sets the notes for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_OBJECT
 * @li LIBSEDML_OPERATION_FAILED
 */
LIBSEDML_EXTERN
int
SedBase_setNotesString (SedBase_t *sb, char *notes)
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


/**
 * Sets the notes for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_OBJECT
 * @li LIBSEDML_OPERATION_FAILED
 */
LIBSEDML_EXTERN
int
SedBase_setNotesStringAddMarkup (SedBase_t *sb, char *notes)
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


/**
 * Appends the notes for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param notes the XMLNode_t structure respresenting the notes.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_OBJECT
 * @li LIBSEDML_OPERATION_FAILED
 */
LIBSEDML_EXTERN
int
SedBase_appendNotes (SedBase_t *sb, XMLNode_t *notes)
{
  if (sb != NULL)
    return sb->appendNotes(notes);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Appends the notes for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_OBJECT
 * @li LIBSEDML_OPERATION_FAILED
 */
LIBSEDML_EXTERN
int
SedBase_appendNotesString (SedBase_t *sb, char *notes)
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


/**
 * Sets the annotation for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param annotation the XMLNode_t structure respresenting the annotation.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 */
LIBSEDML_EXTERN
int
SedBase_setAnnotation (SedBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
    return sb->setAnnotation(annotation);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Sets the annotation for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param annotation the string (const char*) respresenting the annotation.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_OPERATION_FAILED
 */
LIBSEDML_EXTERN
int
SedBase_setAnnotationString (SedBase_t *sb, char *annotation)
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


/**
 * Appends the annotation for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param annotation the XMLNode_t structure respresenting the annotation.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_OPERATION_FAILED
 */
LIBSEDML_EXTERN
int
SedBase_appendAnnotation (SedBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
    return sb->appendAnnotation(annotation);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Appends the annotation for the given Sed object.
 *
 * @param sb the given Sed object.
 * @param annotation the string (const char*) respresenting the annotation.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_OPERATION_FAILED
 */
LIBSEDML_EXTERN
int
SedBase_appendAnnotationString (SedBase_t *sb, char *annotation)
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

/**
 * Removes the top-level element within the "annotation" 
 * subelement of this Sed object with the given name.
 *
 * Sed places a few restrictions on the organization of the content of
 * annotations; these are intended to help software tools read and write
 * the data as well as help reduce conflicts between annotations added by
 * different tools.  Please see the Sed specifications for more details.
 *
 * Calling this method allows a particular annotation element to be removed
 * whilst the remaining annotations remain intact.
 *
 * @param sb SedBase_t object containing the annotation to be altered
 * @param elementName a string representing the name of the top level
 * annotation element that is to be removed
 *
 * @return integer value indicating success/failure of the
 * function.  The possible values returned by this function are:
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_ANNOTATION_NAME_NOT_FOUND LIBSEDML_ANNOTATION_NAME_NOT_FOUND @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_ANNOTATION_NS_NOT_FOUND LIBSEDML_ANNOTATION_NS_NOT_FOUND @endlink
 *
 * @see SedBase_removeTopLevelAnnotationElementWithURI (SedBase_t *, 
 *  const char *, const char *)
 * @see SedBase_replaceTopLevelAnnotationElement (SedBase_t *, XMLNode_t *)
 * @see SedBase_replaceTopLevelAnnotationElementString (SedBase_t *, char *)
 */
LIBSEDML_EXTERN
int
SedBase_removeTopLevelAnnotationElement (SedBase_t *sb, char *name)
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


/**
 * Removes the top-level element within the "annotation" 
 * subelement of this Sed object with the given name and URI.
 *
 * Sed places a few restrictions on the organization of the content of
 * annotations; these are intended to help software tools read and write
 * the data as well as help reduce conflicts between annotations added by
 * different tools.  Please see the Sed specifications for more details.
 *
 * Calling this method allows a particular annotation element to be removed
 * whilst the remaining annotations remain intact.
 *
 * @param sb SedBase_t object containing the annotation to be altered
 * @param elementName a string representing the name of the top level
 * annotation element that is to be removed
 * @param elementURI a string that is used to check both the name
 * and URI of the top level element to be removed
 *
 * @return integer value indicating success/failure of the
 * function.  The possible values returned by this function are:
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_ANNOTATION_NAME_NOT_FOUND LIBSEDML_ANNOTATION_NAME_NOT_FOUND @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_ANNOTATION_NS_NOT_FOUND LIBSEDML_ANNOTATION_NS_NOT_FOUND @endlink
 *
 * @see SedBase_removeTopLevelAnnotationElement (SedBase_t *, const char *)
 * @see SedBase_replaceTopLevelAnnotationElement (SedBase_t *, XMLNode_t *)
 * @see SedBase_replaceTopLevelAnnotationElementString (SedBase_t *, char *)
 */
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


/**
 * Replaces the given top-level element within the "annotation" 
 * subelement of this Sed object and with the annotation element supplied.
 *
 * Sed places a few restrictions on the organization of the content of
 * annotations; these are intended to help software tools read and write
 * the data as well as help reduce conflicts between annotations added by
 * different tools.  Please see the Sed specifications for more details.
 *
 * This method determines the name of the element to be replaced from the
 * annotation argument. Functionally it is equivalent to calling
 * <code> SedBase_removeTopLevelAnnotationElement(sb, name); 
 * SedBase_appendAnnotation(sb, annotation_with_name);
 * </code> with the exception that the placement of the annotation element remains
 * the same.
 *
 * @param sb SedBase_t object containing the annotation to be altered
 * @param annotation XMLNode representing the replacement top level annotation 
 *
 * @return integer value indicating success/failure of the
 * function.  The possible values returned by this function are:
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
 *
 * @see SedBase_removeTopLevelAnnotationElement (SedBase_t *, const char *)
 * @see SedBase_removeTopLevelAnnotationElementWithURI (SedBase_t *, 
 *  const char *, const char *)
 * @see SedBase_replaceTopLevelAnnotationElementString (SedBase_t *, char *)
 */
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


/**
 * Replaces the given top-level element within the "annotation" 
 * subelement of this Sed object and with the annotation element supplied.
 *
 * Sed places a few restrictions on the organization of the content of
 * annotations; these are intended to help software tools read and write
 * the data as well as help reduce conflicts between annotations added by
 * different tools.  Please see the Sed specifications for more details.
 *
 * This method determines the name of the element to be replaced from the
 * annotation argument. Functionally it is equivalent to calling
 * <code> SedBase_removeTopLevelAnnotationElement(sb, name); 
 * SedBase_appendAnnotation(sb, annotation_with_name);
 * </code> with the exception that the placement of the annotation element remains
 * the same.
 *
 * @param sb SedBase_t object containing the annotation to be altered
 * @param annotation string representing the replacement top level annotation 
 *
 * @return integer value indicating success/failure of the
 * function.  The possible values returned by this function are:
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
 * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
 *
 * @see SedBase_removeTopLevelAnnotationElement (SedBase_t *, const char *)
 * @see SedBase_removeTopLevelAnnotationElementWithURI (SedBase_t *, 
 *  const char *, const char *)
 * @see SedBase_replaceTopLevelAnnotationElement (SedBase_t *, XMLNode_t *)
 */
LIBSEDML_EXTERN
int
SedBase_replaceTopLevelAnnotationElementString (SedBase_t *sb, char *annotation)
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


/**
 * Unsets the "metaid" attribute of the given object.
 *
 * @param sb the SedBase_t structure
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_OPERATION_FAILED
 */
LIBSEDML_EXTERN
int
SedBase_unsetMetaId (SedBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetMetaId();
  else
    return LIBSEDML_INVALID_OBJECT;
}


/*
* Unsets the "id" attribute of the given object.
*
* @param sb the SedBase_t structure
*
* @return integer value indicating success/failure of the
* function.  @if clike The value is drawn from the
* enumeration #OperationReturnValues_t. @endif@~ The possible values
* returned by this function are:
*
* @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
* @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
*/
LIBSEDML_EXTERN
int
SedBase_unsetId (SedBase_t *sb)
{
 return sb->unsetId();
}


///**
// * Unsets the "name" attribute of the given object.
// *
// * @param sb the SedBase_t structure
// *
// * @return integer value indicating success/failure of the
// * function.  @if clike The value is drawn from the
// * enumeration #OperationReturnValues_t. @endif@~ The possible values
// * returned by this function are:
// *
// * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
// * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
// */
//LIBSEDML_EXTERN
//int
//SedBase_unsetName (SedBase_t *sb)
//{
//  return sb->unsetName();
//}


/**
 * Unsets the "notes" subelement of the given object.
 *
 * @param sb the SedBase_t structure
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 */
LIBSEDML_EXTERN
int
SedBase_unsetNotes (SedBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetNotes();
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Unsets the "annotation" subelement of the given object.
 *
 * @param sb the SedBase_t structure
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 */
LIBSEDML_EXTERN
int
SedBase_unsetAnnotation (SedBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetAnnotation();
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Returns the libSed type code for this object.
 *
 * This method MAY return the typecode of this Sed object or it MAY
 * returnSEDML_UNKNOWN.  That is, subclasses of SedBase are not required to
 * implement this method to return a typecode.  This method is meant
 * primarily for the LibSed C interface where class and subclass
 * information is not readily available.
 *
 * @note In libSed 5, the type of return value has been changed from
 *       typecode (int) to int. The return value is one of enum values defined
 *       for each package. For example, return values will be one of
 *       typecode (int) if this object is defined in Sed core package,
 *       return values will be one of SedLayoutTypeCode_t if this object is
 *       defined in Layout extension (i.e. similar enum types are defined in
 *       each pacakge extension for each SedBase subclass)
 *       The value of each typecode can be duplicated between those of
 *       different packages. Thus, to distinguish the typecodes of different
 *       packages, not only the return value of getTypeCode() but also that of
 *       getPackageName() must be checked.
 *
 * @param sb the SedBase_t structure
 *
 * @return the typecode (int value) of this Sed object orSEDML_UNKNOWN
 * (default).
 *
 * @see getElementName()
 * @see getPackageName()
 */
LIBSEDML_EXTERN
int
SedBase_getTypeCode (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getTypeCode() :SEDML_UNKNOWN;
}


/**
 * Returns the XML element name of the given structure.
 *
 * This is overridden by subclasses to return a string appropriate to the
 * Sed component.  For example, Model defines it as returning "model",
 * CompartmentType defines it as returning "compartmentType", etc.
 *
 * @param sb the SedBase_t structure
 */
LIBSEDML_EXTERN
const char *
SedBase_getElementName (const SedBase_t *sb)
{
  return (sb != NULL && !(sb->getElementName().empty())) ? 
    sb->getElementName().c_str() : NULL;
}


/**
 * Returns the line number on which the given object first appears in the
 * XML representation of the Sed document.
 *
 * @param sb the SedBase_t structure
 * 
 * @return the line number of the given structure
 *
 * @see getColumn().
 */
LIBSEDML_EXTERN
unsigned int
SedBase_getLine (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getLine() : 0;
}


/**
 * Returns the column number on which the given object first appears in the
 * XML representation of the Sed document.
 *
 * @param sb the SedBase_t structure
 * 
 * @return the column number of this Sed object.
 * 
 * @see getLine().
 */
LIBSEDML_EXTERN
unsigned int
SedBase_getColumn (const SedBase_t *sb)
{
  return (sb != NULL) ? sb->getColumn() : 0;
}


/**
  * Predicate returning nonzero true or false depending on whether the
  * object's level/version and namespace values correspond to a valid
  * Sed specification.
  *
  *
  * @param sb the SedBase_t structure
  *
  * @return nonzero (true) if the level, version and namespace values of this 
  * Sed object correspond to a valid set of values, zero (false) otherwise.
  */
LIBSEDML_EXTERN
int
SedBase_hasValidLevelVersionNamespaceCombination(SedBase_t *sb)
{
  return (sb != NULL) ? 
    static_cast <int> (sb->hasValidLevelVersionNamespaceCombination()) : 0;
}



/**
 * Sets the user data of this node. This can be used by the application
 * developer to attach custom information to the node. In case of a deep
 * copy this attribute will passed as it is. The attribute will be never
 * interpreted by this class.
 * 
 * @param node defines the node of which the user data should be set.
 * @param userData specifies the new user data. 
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t.  @endif@~ The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_OPERATION_FAILED
 * @li LIBSEDML_INVALID_OBJECT
 */
LIBSEDML_EXTERN
int
SedBase_setUserData(SedBase_t* sb, void *userData)
{
  if (sb == NULL) return LIBSEDML_INVALID_OBJECT;
  return sb->setUserData(userData);
}


/**
 * Returns the user data that has been previously set by setUserData().
 *
 * @param node defines the node of interest.
 * @return the user data of this node. NULL if no user data has been.
 * @see SedBase_setUserData
 */
LIBSEDML_EXTERN
void *SedBase_getUserData(SedBase_t* sb)
{
  if (sb == NULL) return NULL;
  return sb->getUserData();
}

LIBSEDML_EXTERN 
SedBase_t* 
SedBase_getElementBySId(SedBase_t* sb, const char* id)
{
  if (sb == NULL) return NULL;
  return sb->getElementBySId(id);
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


LIBSEDML_CPP_NAMESPACE_END
