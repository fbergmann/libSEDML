/**
 * @file ListWrapper.h
 * @brief Definition of the ListWrapper class.
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
 * @class ListWrapper
 * @sbmlbrief{} TODO:Definition of the ListWrapper class.
 */


#ifndef ListWrapper_h
#define ListWrapper_h

#include <sbml/util/List.h>
#include <sedml/common/extern.h>

LIBSEDML_CPP_NAMESPACE_USE

/**
 *
 * ListWrapper : a wrapper template class for List class.
 */
template<typename IType>
class LIBSEDML_EXTERN ListWrapper
{
  private:
    List *mList;
    bool mMemOwn;

  public:
    /**
     * Creates a new List.
     *
     * A ListXXX object is newly created (i.e. owned by the caller) and 
     * deleted by the destructor below if the constructor of this class 
     * invoked without an argument. 
     */
    ListWrapper() : mList(new List()), mMemOwn(true) {}


#ifndef SWIG
    /**
     * Creates a new List.
     * (internal implementation)
     *
     * An existing List object is given (i.e. not owned by the caller)
     * and stored.
     *
     */
    ListWrapper(List* list, bool memown = false) : mList(list), mMemOwn(memown) {}

    List* getList() { return mList; }
#endif


    /**
     * destructor
     */
    virtual ~ListWrapper() { if (mMemOwn) delete mList; }


    /**
     * Adds @p item to the end of this List.
     *
     * @param item a pointer to the item to be added.
     */
    void add(IType* item) 
    { 
      if (mList) mList->add(static_cast<void*>(item)); 
    }


    /**
     * Get the nth item in this List.
     *
     * If @p n > <code>listobj.size()</code>, this method returns @c 0.
     *
     * @return the nth item in this List.
     *
     * @see remove()
     *
     */
    IType* get(unsigned int n) const 
    { 
      return (mList) ? static_cast<IType*>(mList->get(n)) : 0; 
    }


    /**
     * Adds @p item to the beginning of this List.
     *
     * @param item a pointer to the item to be added.
     */
    void prepend(IType* item) 
    { 
      if (mList) mList->prepend(static_cast<void*>(item)); 
    }


    /**
     * Removes the nth item from this List and returns a pointer to it.
     *
     * If @p n > <code>listobj.size()</code>, this method returns @c 0.
     *
     * @return the nth item in this List.
     *
     * @see get()
     */
     IType* remove(unsigned int n) 
    { 
      return (mList) ? static_cast<IType*>(mList->remove(n)) : 0; 
    }


    /**
     * Get the number of items in this List.
     * 
     * @return the number of elements in this List.
     */
    unsigned int getSize() const 
    { 
      return (mList) ? mList->getSize() : 0; 
    }
};

#endif // ListWrapper_h
