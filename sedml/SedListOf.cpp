/**
 * @file    SedListOf.cpp
 * @brief   Wraps List and inherits from SedBase
 * @author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSed.  Please visit http://sbml.org for more
 * information about Sed, and the latest version of libSed.
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
 * ---------------------------------------------------------------------- -->*/

#include <algorithm>
#include <functional>

#include <sedml/SedVisitor.h>
#include <sedml/SedListOf.h>
#include <sedml/common/common.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

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
SedListOf::SedListOf (SedNamespaces* sbmlns)
: SedBase(sbmlns)
{
    if (!hasValidLevelVersionNamespaceCombination())
    throw SedConstructorException();
}


/**
 * Used by the Destructor to delete each item in mItems.
 */
struct Delete : public unary_function<SedBase*, void>
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
struct Clone : public unary_function<SedBase*, SedBase*>
{
  SedBase* operator() (SedBase* sb) { return sb->clone(); }
};


/*
 * Copy constructor. Creates a copy of this SedListOf items.
 */
SedListOf::SedListOf (const SedListOf& orig) : SedBase(orig)
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

/*
 * Accepts the given SedVisitor.
 */
bool
SedListOf::accept (SedVisitor& v) const
{
  v.visit(*this, getItemTypeCode() );
  for (unsigned int n = 0 ; n < mItems.size() && mItems[n]->accept(v); ++n) ;
  v.leave(*this, getItemTypeCode() );

  return true;
}


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

bool 
SedListOf::isValidTypeForList(SedBase * item) const
{
  return true;
  //return item->getTypeCode() == getItemTypeCode();
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
  return appendAndOwn( item->clone() );
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
  if (getItemTypeCode() != list->getItemTypeCode()) {
    return LIBSEDML_INVALID_OBJECT;
  }
  int ret = LIBSEDML_OPERATION_SUCCESS;
  for (unsigned int item=0; item<list->size(); item++) {
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
SedListOf::getElementBySId(std::string id)
{
  if (id.empty()) return NULL;
  for (unsigned int i = 0; i < size(); i++)
  {
    SedBase* obj = get(i);
    if (obj->isSetId() && obj->getId() == id)
    {
      return obj;
    }
    obj = obj->getElementBySId(id);
    if (obj != NULL) return obj;
  }

  return NULL;
}

SedBase*
SedListOf::getElementByMetaId(std::string metaid)
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
SedListOf::getAllElements()
{
  List* ret = new List();
  List* sublist = NULL;
  for (unsigned int i = 0; i < size(); i++) {
    SedBase* obj = get(i);
    ret->add(obj);
    sublist = obj->getAllElements();
    ret->transferFrom(sublist);
    delete sublist;
  }
  return ret;
}
/**
 * Used by SedListOf::get() to lookup an SedBase based by its id.
 */
//struct IdEq : public unary_function<SedBase*, bool>
//{
//  const string& id;
//
//  IdEq (const string& id) : id(id) { }
//  bool operator() (SedBase* sb) { return sb->getId() == id; }
//};


/*
 * @return item in this SedListOf items with the given @p id or @c NULL if no such
 * item exists.
 */
//const SedBase*
//SedListOf::get (const std::string& sid) const
//{
//  vector<SedBase*>::const_iterator result;
//
//  result = find_if( mItems.begin(), mItems.end(), IdEq(sid) );
//  return (result == mItems.end()) ? 0 : *result;
//}


/*
 * @return item in this SedListOf items with the given @p id or @c NULL if no such
 * item exists.
 */
//SedBase*
//SedListOf::get (const std::string& sid)
//{
//  return const_cast<SedBase*>( static_cast<const SedListOf&>(*this).get(sid) );
//}


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
  unsetId(); //Just in case
  unsetMetaId();
  unsetName(); //Just in case
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
 * Removes item in this SedListOf items with the given @p id or @c NULL if no such
 * item exists.  The caller owns the returned item and is repsonsible for
 * deleting it.
 */
//SedBase*
//SedListOf::remove (const std::string& sid)
//{
//  SedBase* item = 0;
//  vector<SedBase*>::iterator result;
//
//  result = find_if( mItems.begin(), mItems.end(), IdEq(sid) );
//
//  if (result != mItems.end())
//  {
//    item = *result;
//    mItems.erase(result);
//  }
//
//  return item;
//}
//

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
struct SetSedDocument : public unary_function<SedBase*, void>
{
  SedDocument* d;

  SetSedDocument (SedDocument* d) : d(d) { }
  void operator() (SedBase* sbase) { sbase->setSedDocument(d); }
};


/**
 * Used by SedListOf::setParentSedObject().
 */
struct SetParentSedObject : public unary_function<SedBase*, void>
{
  SedBase* sb;

  SetParentSedObject (SedBase *sb) : sb(sb) { }
  void operator() (SedBase* sbase) { sbase->connectToParent(sb); }
};

/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument of this Sed object.
 */
void
SedListOf::setSedDocument (SedDocument* d)
{
  SedBase::setSedDocument(d);
  for_each( mItems.begin(), mItems.end(), SetSedDocument(d) );
}


/*
 * Sets this Sed object to child Sed objects (if any).
 * (Creates a child-parent relationship by the parent)
  */
void
SedListOf::connectToChild()
{
  for_each( mItems.begin(), mItems.end(), SetParentSedObject(this) );
}

/** @endcond */


/*
 * @return the typecode (int) of this Sed object or SEDML_UNKNOWN
 * (default).
 */
int
SedListOf::getTypeCode () const
{
  return SEDML_LIST_OF;
}


/*
 * @return the typecode (int) of Sed objects contained in this SedListOf or
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
struct Write : public unary_function<SedBase*, void>
{
  XMLOutputStream& stream;

  Write (XMLOutputStream& s) : stream(s) { }
  void operator() (SedBase* sbase) { sbase->write(stream); }
};


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to write out their contained
 * Sed objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
SedListOf::writeElements (XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);
  for_each( mItems.begin(), mItems.end(), Write(stream) );

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

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v3 ->)
  // is written in SedBase::writeAttributes()
  //

}

/** @endcond */



/** @cond doxygen-c-only */


/**
 * Creates a new SedListOf.
 *
 * @return a pointer to created SedListOf.
 */
LIBSEDML_EXTERN
SedListOf_t *
SedListOf_create (unsigned int level, unsigned int version)
{
  return new(nothrow) SedListOf(level,version);
}


/**
 * Frees the given SedListOf and its constituent items.
 *
 * This function assumes each item in the list is derived from SedBase.
 */
LIBSEDML_EXTERN
void
SedListOf_free (SedListOf_t *lo)
{
  if (lo != NULL)
  delete lo;
}


/**
 * @return a (deep) copy of this SedListOf items.
 */
LIBSEDML_EXTERN
SedListOf_t *
SedListOf_clone (const SedListOf_t *lo)
{
  return (lo != NULL) ? static_cast<SedListOf_t*>( lo->clone() ) : NULL;
}


/**
 * Adds a copy of item to the end of this SedListOf items.
 */
LIBSEDML_EXTERN
int
SedListOf_append (SedListOf_t *lo, const SedBase *item)
{
  if (lo != NULL)
    return lo->append(item);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Adds the given item to the end of this SedListOf items.
 */
LIBSEDML_EXTERN
int
SedListOf_appendAndOwn (SedListOf_t *lo, SedBase_t *item)
{
  if (lo != NULL)
    return lo->appendAndOwn(item);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Adds clones of the given items from the second list to the end of this SedListOf items.
 */
LIBSEDML_EXTERN
int
SedListOf_appendFrom (SedListOf_t *lo, SedListOf_t *list)
{
  if (lo != NULL)
    return lo->appendFrom(list);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * inserts a copy of item to this SedListOf items at the given position.
 */
LIBSEDML_EXTERN
int
SedListOf_insert (SedListOf_t *lo, int location, const SedBase_t *item)
{
  if (lo != NULL)
    return lo->insert(location, item);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * inserts the item to this SedListOf items at the given position.
 */
LIBSEDML_EXTERN
int
SedListOf_insertAndOwn (SedListOf_t *lo, int location, SedBase_t *item)
{
  if (lo != NULL)
    return lo->insertAndOwn(location, item);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Returns the nth item in this SedListOf items.
 */
LIBSEDML_EXTERN
SedBase *
SedListOf_get (SedListOf_t *lo, unsigned int n)
{
  return (lo != NULL) ? lo->get(n) : NULL;
}


/*
 * @return item in this SedListOf items with the given @p id or @c NULL if no such
 * item exists.
 */
//LIBSEDML_EXTERN
//SedBase *
//SedListOf_getById (SedListOf_t *lo, const char *sid)
//{
//  return (sid != NULL) ? lo->get(sid) : NULL;
//}
//

/**
 * Removes all items in this SedListOf object.
 *
 * If doDelete is true (non-zero), all items in this SedListOf object are deleted
 * and cleared, and thus the caller doesn't have to delete those items.
 * Otherwise (zero), all items are just cleared from this SedListOf object and the 
 * caller is responsible for deleting all items (In this case, pointers to all 
 * items should be stored elsewhere before calling this function by the caller).
 */
LIBSEDML_EXTERN
void
SedListOf_clear (SedListOf_t *lo, int doDelete)
{
  if (lo != NULL)
  lo->clear(doDelete);
}


/**
 * Removes the nth item from this SedListOf items and returns a pointer to
 * it.  The caller owns the returned item and is responsible for deleting
 * it.
 */
LIBSEDML_EXTERN
SedBase *
SedListOf_remove (SedListOf_t *lo, unsigned int n)
{
  return (lo != NULL) ? lo->remove(n) : NULL;
}


/*
 * Removes item in this SedListOf items with the given @p id or @c NULL if no such
 * item exists.  The caller owns the returned item and is repsonsible for
 * deleting it.
 */
//LIBSEDML_EXTERN
//SedBase *
//SedListOf_removeById (SedListOf_t *lo, const char *sid)
//{
//  return (sid != NULL) ? lo->remove(sid) : NULL;
//}


/**
 * Returns the number of items in this SedListOf items.
 */
LIBSEDML_EXTERN
unsigned int
SedListOf_size (const SedListOf_t *lo)
{
  return (lo != NULL) ? lo->size() : SEDML_INT_MAX;
}


/**
 * @return the typecode (int) of this Sed object or SEDML_UNKNOWN
 * SEDML_UNKNOWN (default).
 */
LIBSEDML_EXTERN
int
SedListOf_getItemTypeCode (const SedListOf_t *lo)
{
  return (lo != NULL) ? lo->getItemTypeCode() : SEDML_UNKNOWN;
}

/** @endcond */

LIBSEDML_CPP_NAMESPACE_END

