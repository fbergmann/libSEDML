/**
 * @file SedListOf.h
 * @brief Definition of the SedListOf class.
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
 *
 * @class SedListOf
 * @sbmlbrief{} TODO:Definition of the SedListOf class.
 */


#ifndef SedListOf_h
#define SedListOf_h


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/SedTypeCodes.h>


#ifdef __cplusplus


#include <vector>
#include <algorithm>
#include <functional>

#include <sedml/SedBase.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

class SedVisitor;


/** @cond doxygenLibsedmlInternal */
/**
 * Used by SedListOf::get() to lookup an SedBase based by its id.
 */
#ifndef SWIG
template<class CNAME>
struct SedIdEq
{
  const std::string& id;

  SedIdEq (const std::string& id) : id(id) { }
  bool operator() (SedBase* sb) 
       { return static_cast <CNAME*> (sb)->getId() == id; }
};
#endif /* SWIG */
/** @endcond */


class LIBSEDML_EXTERN SedListOf : public SedBase
{
public:

  /**
   * Creates a new SedListOf object.
   *
   * @param level the SED-ML Level; if not assigned, defaults to the
   * value of SEDML_DEFAULT_LEVEL.
   *
   * @param version the Version within the SED-ML Level; if not assigned,
   * defaults to the value of SEDML_DEFAULT_VERSION.
   */
  SedListOf (unsigned int level   = SEDML_DEFAULT_LEVEL,
          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOf with a given SedNamespaces object.
   *
   * @param sedmlns the set of SED-ML namespaces that this SedListOf should
   * contain.
   */
  SedListOf (SedNamespaces* sedmlns);


  /**
   * Destroys this SedListOf and the items inside it.
   */
  virtual ~SedListOf ();


  /**
   * Copy constructor; creates a copy of this SedListOf.
   *
   * @param orig the SedListOf instance to copy.
   */
  SedListOf (const SedListOf& orig);


  /**
   * Assignment operator for SedListOf.
   */
  SedListOf& operator=(const SedListOf& rhs);



  /** @cond doxygenLibsedmlInternal */
  /**
   * Accepts the given SedVisitor.
   *
   * @param v the SedVisitor instance to be used.
   *
   * @return the result of calling <code>v.visit()</code>, which indicates
   * whether the Visitor would like to visit the next item in the
   * list.
   */
  virtual bool accept (SedVisitor& v) const;
  /** @endcond */


  /**
   * Creates and returns a deep copy of this SedListOf object.
   *
   * @return the (deep) copy of this SedListOf object.
   */
  virtual SedListOf* clone () const;


  /**
   * Adds an item to the end of this SedListOf's list of items.
   *
   * This method makes a clone of the @p item handed to it.  This means that
   * when the SedListOf object is destroyed, the original items will not be
   * destroyed.  For a method with an alternative ownership behavior, see the
   * SedListOf::appendAndOwn(@if java SedBase@endif) method.
   *
   * @param item the item to be added to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see appendAndOwn(SedBase* disownedItem)
   * @see appendFrom(const SedListOf* list)
   */
  int append (const SedBase* item);


  /**
   * Adds an item to the end of this SedListOf's list of items.
   *
   * This method does not clone the @p disownedItem handed to it; instead, it assumes
   * ownership of it.  This means that when the SedListOf is destroyed, the item
   * will be destroyed along with it.  For a method with an alternative
   * ownership behavior, see the SedListOf::append(SedBase* item) method.
   *
   * @param disownedItem the item to be added to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see append(const SedBase* item)
   * @see appendFrom(const SedListOf* list)
   */
  int appendAndOwn (SedBase* disownedItem);


  /**
   * Adds a clone of a list of items to this SedListOf's list.
   *
   * Note that because this clones the objects handed to it, the original
   * items will not be destroyed when this SedListOf object is destroyed.
   *
   * @param list a list of items to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see append(const SedBase* item)
   * @see appendAndOwn(SedBase* disownedItem)
   */
  virtual int appendFrom (const SedListOf* list);


  /**
   * Inserts an item at a given position in this SedListOf's list of items.
   *
   * This variant of the method makes a clone of the @p item handed to it.
   * This means that when the SedListOf is destroyed, the original @p item will
   * <em>not</em> be destroyed.
   *
   * @param location the location in the list where to insert the item.
   * @param item the item to be inserted to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see insertAndOwn(int location, SedBase* item)
   */
  int insert (int location, const SedBase* item);


  /**
   * Inserts an item at a given position in this SedListOf's list of items.
   *
   * This variant of the method does not make a clone of the @p disownedItem handed to it.
   * This means that when the SedListOf is destroyed, the original @p item
   * <em>will</em> be destroyed.
   *
   * @param location the location where to insert the item
   * @param disownedItem the item to be inserted to the list
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see insert(int location, const SedBase* item)
   */
  int insertAndOwn(int location, SedBase* disownedItem);


  /**
   * Get an item from the list.
   *
   * @param n the index number of the item to get.
   *
   * @return the <em>n</em>th item in this SedListOf items, or a null pointer if
   * the index number @p n refers to a nonexistent position in this list.
   *
   * @see size()
   */
  virtual const SedBase* get (unsigned int n) const;


  /**
   * Get an item from the list.
   *
   * @param n the index number of the item to get.
   * 
   * @return the <em>n</em>th item in this SedListOf items, or a null pointer if
   * the index number @p n refers to a nonexistent position in this list.
   *
   * @see size()
   */
  virtual SedBase* get (unsigned int n);


  /**
   * Returns the first child element it can find with a specific "id"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param id string representing the "id" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given identifier.
   */
  virtual SedBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element found with the given meta-identifier.
   *
   * @param metaid string representing the "metaid" attribute of the object
   * to find.
   *
   * @return the first element found with the given @p metaid, or @c NULL if
   * no such object is found.
   */
  virtual SedBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SedBase objects.
   *
   * The values returned include all children of the objects in this SedListOf
   * list, nested to an arbitrary depth.
   *
   * @return a List of pointers to all child objects.
   */
  virtual List* getAllElements(SedElementFilter* filter = NULL);


  /**
   * Removes all items in this SedListOf object.
   *
   * If parameter @p doDelete is @c true (default), all items in this SedListOf
   * object are deleted and cleared, and thus the caller doesn't have to
   * delete those items.  Otherwise, all items are cleared only from this
   * SedListOf object; the caller is still responsible for deleting the actual
   * items.  (In the latter case, callers are advised to store pointers to
   * all items elsewhere before calling this function.)
   *
   * @param doDelete if @c true (default), all items are deleted and cleared.
   * Otherwise, all items are just cleared and not deleted.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  void clear (bool doDelete = true);


  /**
   * Removes all items in this SedListOf object and deletes its properties too.
   *
   * This performs a call to clear() with an argument of @c true (thus removing
   * all the child objects in the list), followed by calls to various libSEDML
   * <code>unset<em>Foo</em></code> methods to delete everything else: CVTerm
   * objects, model history objects, etc.
   *
   * @if cpp Implementations of subclasses of SedListOf may need to override
   * this method if different handling of child objects is needed.@endif@~
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int removeFromParentAndDelete();


  /**
   * Removes the <em>n</em>th item from this SedListOf list of items and returns
   * it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the item to remove
   *
   * @see size()
   */
  virtual SedBase* remove (unsigned int n);


  /**
   * Returns number of items in this SedListOf list.
   *
   * @return the number of items in this SedListOf items.
   */
  unsigned int size () const;


  /** @cond doxygenLibsedmlInternal */
  /**
   * Sets the parent SedDocument of this SED-ML object.
   *
   * @param d the SedDocument that should become the parent of this
   * SedListOf.
   */
  virtual void setSedDocument (SedDocument* d);
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /**
   * Sets this SED-ML object to child SED-ML objects (if any).
   * (Creates a child-parent relationship by the parent)
   *
   * Subclasses must override this function if they define
   * one ore more child elements.
   * Basically, this function needs to be called in
   * constructor, copy constructor and assignment operator.
   *
   * @if cpp
   * @see setSedDocument()
   * @see enablePackageInternal()
   * @endif
   */
  virtual void connectToChild ();
  /** @endcond */


  /**
   * Returns the libSEDML type code for this object, namely,
   * @sedmlconstant{SEDML_LIST_OF, SedTypeCode_t}.
   * 
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_LIST_OF, SedTypeCode_t} (default).
   *
   * @note The various SedListOf classes mostly differ from each other in what they
   * contain.  Hence, one must call getItemTypeCode() to fully determine the
   * class of this SED-ML object.
   *
   * @see getItemTypeCode()
   * @see getElementName()
   */
  virtual int getTypeCode () const;


  /**
   * Get the type code of the objects contained in this SedListOf.
   *
   * Classes that inherit from the SedListOf class should override this method
   * to return the SED-ML type code for the objects contained in this SedListOf.
   * If they do not, this method will return
   * @sedmlconstant{SEDML_UNKNOWN, SedTypeCode_t}
   *
   * @return The SedListOf base class contains no SED-ML objects, and therefore
   * this method returns @sedmlconstant{SEDML_UNKNOWN, SedTypeCode_t}.
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode () const;


  /**
   * Returns the XML element name of this object, which for SedListOf, is
   * always @c "listOf".
   *
   * @return the XML name of this element.
   */
  virtual const std::string& getElementName () const;


  /** @cond doxygenLibsedmlInternal */
  /**
   * Subclasses should override this method to write out their contained
   * SED-ML objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.
   */
  virtual void writeElements (XMLOutputStream& stream) const;
  /** @endcond */


protected:
  /** @cond doxygenLibsedmlInternal */
  typedef std::vector<SedBase*>           ListItem;
  typedef std::vector<SedBase*>::iterator ListItemIter;

  /**
   * Subclasses should override this method to get the list of
   * expected attributes.
   * This function is invoked from corresponding readAttributes()
   * function.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  
  /**
   * Subclasses should override this method to read values from the given
   * XMLAttributes set into their specific fields.  Be sure to call your
   * parents implementation of this method as well.
   */
  virtual void readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes);

  /**
   * Subclasses should override this method to write their XML attributes
   * to the XMLOutputStream.  Be sure to call your parents implementation
   * of this method as well.  For example:
   *
   *   SedBase::writeAttributes(stream);
   *   stream.writeAttribute( "id"  , mId   );
   *   stream.writeAttribute( "name", mName );
   *   ...
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;

  virtual bool isValidTypeForList(SedBase * item);

  ListItem mItems;

  /** @endcond */
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */


#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * Creates a new instance of a SedListOf_t structure.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedListOf_t structure.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedListOf_t structure.
 *
 * @return a pointer to the newly-created SedListOf_t structure.
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
SedListOf_t *
SedListOf_create (unsigned int level, unsigned int version);


/**
 * Frees the given SedListOf_t structure.
 *
 * This function assumes each item in the list is derived from SedBase_t.
 *
 * @param lo the SedListOf_t structure to be freed.
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
void
SedListOf_free (SedListOf_t *lo);


/**
 * Creates a deep copy of the given SedListOf_t structure.
 *
 * @param lo the SedListOf_t structure to be copied.
 *
 * @return a (deep) copy of the given SedListOf_t structure, or a null
 * pointer if a failure occurred.
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
SedListOf_t *
SedListOf_clone (const SedListOf_t *lo);


/**
 * Adds a copy of a given item to the end of a SedListOf_t list.
 *
 * @param lo the SedListOf_t structure to which the @p item should be appended.
 * @param item the item to append to the list.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see SedListOf_appendAndOwn()
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
int
SedListOf_append (SedListOf_t *lo, const SedBase_t *item);


/**
 * Adds the given item to the end of a SedListOf_t list.
 *
 * @param lo the SedListOf_t structure to which the @p disownedItem should be appended.
 * @param disownedItem the item to append to the list.
 *
 * Unlike SedListOf_append(), this function does not copy the @p disownedItem.
 * The given @p lo list will contain the original item.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see SedListOf_append()
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
int
SedListOf_appendAndOwn (SedListOf_t *lo, SedBase_t *disownedItem);


/**
 * Adds clones a list of items from one list to another.
 *
 * @param lo the SedListOf_t list to which @p list will be appended.
 * @param list the list of items to append to @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
int
SedListOf_appendFrom (SedListOf_t *lo, SedListOf_t *list);


/**
 * Inserts a copy of an item into a SedListOf_t list at a given position.
 *
 * @param lo the list into which @p item will be inserted.
 * @param location the starting index for the @p item in the @p lo list.
 * @param item the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
int
SedListOf_insert (SedListOf_t *lo, int location, const SedBase_t *item);


/**
 * Inserts an item into a SedListOf_t list at a given position.
 *
 * Unlike SedListOf_insert(), this function does not clone @p disownedItem before
 * inserting it into @p lo, which means that @p lo becomes the owner.
 *
 * @param lo the list into which @p disownedItem will be inserted.
 * @param location the starting index for the @p disownedItem in the @p lo list.
 * @param disownedItem the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
int
SedListOf_insertAndOwn (SedListOf_t *lo, int location, SedBase_t *disownedItem);


/**
 * Returns the <em>n</em>th item of a given list.
 *
 * @param lo the list from which to retrieve the item.
 * @param n the index of the item to retrieve.
 *
 * @return the <em>n</em>th item in this SedListOf items, or a null pointer if
 * the index number @p n refers to a nonexistent position in @p lo.
 *
 * @see SedListOf_size()
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
SedBase_t *
SedListOf_get (SedListOf_t *lo, unsigned int n);


/**
 * Removes all items in this SedListOf_t structure.
 *
 * If @p doDelete is true (non-zero), all items in this SedListOf_t structure
 * are both deleted and cleared, and thus the caller doesn't have to delete
 * those items.  Otherwise, if @p doDelete is false (zero), all items are
 * only cleared from this SedListOf_t structure and the caller is responsible
 * for deleting all items.  (In the latter case, callers are advised to store
 * pointers to all items elsewhere before calling this function.)
 *
 * @param lo the SedListOf_t structure to clear
 * @param doDelete whether to delete the items.
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
void
SedListOf_clear (SedListOf_t *lo, int doDelete);


/**
 * Removes the <em>n</em>th item from this SedListOf_t list and returns it.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list from which the item should be removed.
 * @param n the index number of the item to remove.
 *
 * @return the item removed, or a null pointer if no item existed at the
 * index @p n.
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
SedBase_t *
SedListOf_remove (SedListOf_t *lo, unsigned int n);


/**
 * Returns the number of items in this SedListOf_t items.
 *
 * @param lo the SedListOf_t structure to count.
 *
 * @return the number of items in @p lo.
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
unsigned int
SedListOf_size (const SedListOf_t *lo);


/**
 * Get the type code of the objects contained in the given SedListOf_t
 * structure.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @param lo the SedListOf_t whose item type codes are sought.
 *
 * @return the type code corresponding to the objects in @p lo,
 * or @sedmlconstant{SEDML_UNKNOWN, SedTypeCode_t}.
 *
 * @memberof SedListOf_t
 */
LIBSEDML_EXTERN
int
SedListOf_getItemTypeCode (const SedListOf_t *lo);


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* SedListOf_h */

