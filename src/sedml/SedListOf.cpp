/**
 * @file SedListOf.cpp
 * @brief Implementation of the SedListOf class.
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


#include <algorithm>
#include <functional>

#include <sedml/SedVisitor.h>
#include <sedml/SedListOf.h>
#include <sedml/common/common.h>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN
#ifdef __cplusplus

/*
 * Creates a new SedListOf items.
 */
SedListOf::SedListOf (unsigned int level, unsigned int version)
: SedBase(level,version)
{
    if (!hasValidLevelVersionNamespaceCombination())
    throw SedConstructorException();
}


/*
 * Creates a new SedListOf items.
 */
SedListOf::SedListOf (SedNamespaces* sedmlns)
: SedBase(sedmlns)
{
    if (!hasValidLevelVersionNamespaceCombination())
    throw SedConstructorException();
}


/**
 * Used by the Destructor to delete each item in mItems.
 */
struct Delete
{
  void operator() (SedBase* sb) { delete sb; }
};


/*
 * Destroys the given SedListOf and its constituent items.
 */
SedListOf::~SedListOf ()
{
  for_each( mItems.begin(), mItems.end(), Delete() );
}


/**
 * Used by the Copy Constructor to clone each item in mItems.
 */
struct Clone
{
  SedBase* operator() (SedBase* sb) { return sb->clone(); }
};


/*
 * Copy constructor. Creates a copy of this SedListOf items.
 */
SedListOf::SedListOf (const SedListOf& orig) : SedBase(orig), mItems()
{
  mItems.resize( orig.size() );
  transform( orig.mItems.begin(), orig.mItems.end(), mItems.begin(), Clone() );
  connectToChild();
}


/*
 * Assignment operator
 */
SedListOf& SedListOf::operator=(const SedListOf& rhs)
{
  if(&rhs!=this)
  {
    this->SedBase::operator =(rhs);
    // Deletes existing items
    for_each( mItems.begin(), mItems.end(), Delete() );
    mItems.resize( rhs.size() );
    transform( rhs.mItems.begin(), rhs.mItems.end(), mItems.begin(), Clone() );
    connectToChild();
  }

  return *this;
}

/** @cond doxygenLibsedmlInternal */
bool
SedListOf::accept (SedVisitor& v) const
{
  v.visit(*this, getItemTypeCode() );
  for (unsigned int n = 0 ; n < mItems.size() && mItems[n]->accept(v); ++n) ;
  v.leave(*this, getItemTypeCode() );

  return true;
}
/** @endcond */


/*
 * @return a (deep) copy of this SedListOf items.
 */
SedListOf*
SedListOf::clone () const
{
  return new SedListOf(*this);
}


/*
 * Inserts the item at the given location.  This SedListOf items assumes
 * no ownership of item and will not delete it.
 */
int 
SedListOf::insert(int location, const SedBase* item)
{
  return insertAndOwn(location, item->clone());
}


/*
 * Inserts the item at the given location.  This SedListOf items assumes
 * ownership of item and will delete it.
 */
int 
SedListOf::insertAndOwn(int location, SedBase* item)
{
  /* no list elements yet */
  if (this->getItemTypeCode() == SEDML_UNKNOWN )
  {
    mItems.insert( mItems.begin() + location, item );
    item->connectToParent(this);
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (!isValidTypeForList(item))
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else
  {
    mItems.insert( mItems.begin() + location, item );
    item->connectToParent(this);
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Adds item to the end of this SedListOf items.  This SedListOf items assumes
 * no ownership of item and will not delete it.
 */
int
SedListOf::append (const SedBase* item)
{
  SedBase* clone = item->clone();
  int ret = appendAndOwn( clone );
  if (ret != LIBSEDML_OPERATION_SUCCESS) 
  {
    delete clone;
  }
  return ret;
}


/*
 * Adds item to the end of this SedListOf items.  This SedListOf items assumes
 * ownership of item and will delete it.
 */
int
SedListOf::appendAndOwn (SedBase* item)
{
  /* no list elements yet */
  if (this->getItemTypeCode() == SEDML_UNKNOWN )
  {
    mItems.push_back( item );
    item->connectToParent(this);
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (!isValidTypeForList(item))
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else
  {
    mItems.push_back( item );
    item->connectToParent(this);
    return LIBSEDML_OPERATION_SUCCESS;
  }
}

int SedListOf::appendFrom(const SedListOf* list)
{
  if (list==NULL) return LIBSEDML_INVALID_OBJECT;
  
  if (getItemTypeCode() != list->getItemTypeCode()) 
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  
  int ret = LIBSEDML_OPERATION_SUCCESS;
  
  for (unsigned int item=0; item<list->size(); item++) 
  {
    ret = appendAndOwn(list->get(item)->clone());
    if (ret != LIBSEDML_OPERATION_SUCCESS) return ret;
  }
  return ret;
}

/*
 * @return the nth item in this SedListOf items.
 */
const SedBase*
SedListOf::get (unsigned int n) const
{
  return (n < mItems.size()) ? mItems[n] : NULL;
}


/*
 * @return the nth item in this SedListOf items.
 */
SedBase*
SedListOf::get (unsigned int n)
{
  return const_cast<SedBase*>( static_cast<const SedListOf&>(*this).get(n) );
}


SedBase*
SedListOf::getElementBySId(const std::string& id)
{
  if (id.empty()) return NULL;
  
  for (unsigned int i = 0; i < size(); i++)
  {
    SedBase* obj = get(i);
    if (obj->getId() == id)
    {
      return obj;
    }
    
    obj = obj->getElementBySId(id);
    
    if (obj != NULL) return obj;
  }

  return NULL;
}


SedBase*
SedListOf::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty()) return NULL;
  
  for (unsigned int i = 0; i < size(); i++)
  {
    SedBase* obj = get(i);
    if (obj->getMetaId() == metaid)
    {
      return obj;
    }
    
    obj = obj->getElementByMetaId(metaid);
    
    if (obj != NULL) return obj;
  }

  return NULL;
}


List*
SedListOf::getAllElements(SedElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;
  
  for (unsigned int i = 0; i < size(); i++) 
  {
    SedBase* obj = get(i);
    if (filter == NULL || filter->filter(obj))
      ret->add(obj);
    sublist = obj->getAllElements(filter);
    ret->transferFrom(sublist);
    delete sublist;
  }

  return ret;
}


/*
 * Removes all items in this SedListOf object.
 *
 * If doDelete is true (default), all items in this SedListOf object are deleted
 * and cleared, and thus the caller doesn't have to delete those items.
 * Otherwise, all items are just cleared from this SedListOf object and the caller
 * is responsible for deleting all items (In this case, pointers to all items
 * should be stored elsewhere before calling this function by the caller).
 */
void
SedListOf::clear (bool doDelete)
{
  if (doDelete)
    for_each( mItems.begin(), mItems.end(), Delete() );
  
  mItems.clear();
}


int SedListOf::removeFromParentAndDelete()
{
  clear(true);
  unsetAnnotation();
  unsetMetaId();
  unsetNotes();
  return LIBSEDML_OPERATION_SUCCESS;
}

/*
 * Removes the nth item from this SedListOf items and returns a pointer to
 * it.  The caller owns the returned item and is responsible for deleting
 * it.
 */
SedBase*
SedListOf::remove (unsigned int n)
{
  SedBase* item = get(n);
  
  if (item != NULL) mItems.erase( mItems.begin() + n );
  
  return item;
}


/*
 * @return the number of items in this SedListOf items.
 */
unsigned int
SedListOf::size () const
{
  return (unsigned int)mItems.size();
}


/**
 * Used by SedListOf::setSedDocument().
 */
struct SetSedDocument
{
  SedDocument* d;

  SetSedDocument (SedDocument* d) : d(d) { }
  void operator() (SedBase* sbase) { sbase->setSedDocument(d); }
};


/**
 * Used by SedListOf::setParentSedObject().
 */
struct SetParentSedObject
{
  SedBase* sb;

  SetParentSedObject (SedBase *sb) : sb(sb) { }
  void operator() (SedBase* sbase) { sbase->connectToParent(sb); }
};

/** @cond doxygenLibsedmlInternal */

/*
 * Sets the parent SedDocument of this SED-ML object.
 */
void
SedListOf::setSedDocument (SedDocument* d)
{
  SedBase::setSedDocument(d);
  for_each( mItems.begin(), mItems.end(), SetSedDocument(d) );
}


/*
 * Sets this SED-ML object to child SED-ML objects (if any).
 * (Creates a child-parent relationship by the parent)
  */
void
SedListOf::connectToChild()
{
  SedBase::connectToChild();
  for_each( mItems.begin(), mItems.end(), SetParentSedObject(this) );
}

/** @endcond */


/*
 * @return the typecode (int) of this SED-ML object or SEDML_UNKNOWN
 * (default).
 */
int
SedListOf::getTypeCode () const
{
  return SEDML_LIST_OF;
}


/*
 * @return the typecode (int) of SED-ML objects contained in this SedListOf or
 * SEDML_UNKNOWN (default).
 */
int
SedListOf::getItemTypeCode () const
{
  return SEDML_UNKNOWN;
}


/*
 * @return the name of this element ie "listOf".
 
 */
const string&
SedListOf::getElementName () const
{
  static const string name = "listOf";
  return name;
}


/**
 * Used by SedListOf::writeElements().
 */
struct Write
{
  XMLOutputStream& stream;

  Write (XMLOutputStream& s) : stream(s) { }
  void operator() (SedBase* sbase) { sbase->write(stream); }
};


/** @cond doxygenLibsedmlInternal */
/*
 * Subclasses should override this method to write out their contained
 * SED-ML objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
SedListOf::writeElements (XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);
  for_each( mItems.begin(), mItems.end(), Write(stream) );
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
SedListOf::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);
}


/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
SedListOf::readAttributes (const XMLAttributes& attributes,
                       const ExpectedAttributes& expectedAttributes)
{
  SedBase::readAttributes(attributes,expectedAttributes);

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v3 ->)
  // is read in SedBase::readAttributes()
  //
}

void 
SedListOf::writeAttributes (XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);
}


bool
SedListOf::isValidTypeForList(SedBase * item)
{
  bool match = false;

  match = (item->getTypeCode() == getItemTypeCode());

  return match;
}
/** @endcond */



#endif /* __cplusplus */
/** @cond doxygenIgnored */
LIBSEDML_EXTERN
SedListOf_t *
SedListOf_create (unsigned int level, unsigned int version)
{
  return new(nothrow) SedListOf(level,version);
}


LIBSEDML_EXTERN
void
SedListOf_free (SedListOf_t *lo)
{
  if (lo != NULL)
  delete lo;
}


LIBSEDML_EXTERN
SedListOf_t *
SedListOf_clone (const SedListOf_t *lo)
{
  return (lo != NULL) ? static_cast<SedListOf_t*>( lo->clone() ) : NULL;
}


LIBSEDML_EXTERN
int
SedListOf_append (SedListOf_t *lo, const SedBase *item)
{
  if (lo != NULL)
    return lo->append(item);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedListOf_appendAndOwn (SedListOf_t *lo, SedBase_t *item)
{
  if (lo != NULL)
    return lo->appendAndOwn(item);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedListOf_appendFrom (SedListOf_t *lo, SedListOf_t *list)
{
  if (lo != NULL)
    return lo->appendFrom(list);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedListOf_insert (SedListOf_t *lo, int location, const SedBase_t *item)
{
  if (lo != NULL)
    return lo->insert(location, item);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedListOf_insertAndOwn (SedListOf_t *lo, int location, SedBase_t *item)
{
  if (lo != NULL)
    return lo->insertAndOwn(location, item);
  else
    return LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
SedBase *
SedListOf_get (SedListOf_t *lo, unsigned int n)
{
  return (lo != NULL) ? lo->get(n) : NULL;
}


LIBSEDML_EXTERN
void
SedListOf_clear (SedListOf_t *lo, int doDelete)
{
  if (lo != NULL)
  lo->clear(doDelete);
}


LIBSEDML_EXTERN
SedBase *
SedListOf_remove (SedListOf_t *lo, unsigned int n)
{
  return (lo != NULL) ? lo->remove(n) : NULL;
}


LIBSEDML_EXTERN
unsigned int
SedListOf_size (const SedListOf_t *lo)
{
  return (lo != NULL) ? lo->size() : SEDML_INT_MAX;
}


LIBSEDML_EXTERN
int
SedListOf_getItemTypeCode (const SedListOf_t *lo)
{
  return (lo != NULL) ? lo->getItemTypeCode() : SEDML_UNKNOWN;
}

/** @endcond */

LIBSEDML_CPP_NAMESPACE_END

