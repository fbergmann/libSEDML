#ifndef ListWrapper_h
#define ListWrapper_h

/**
 * @file    ListWrapper.h
 * @brief   A wrapper template class for List class
 * @author  Akiya Jouraku
 *
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 *
 * Copyright (c) 2013-2016, Frank T. Bergmann
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
 * ------------------------------------------------------------------------ -->
 */

#include <sbml/util/List.h>
#include <sedml/common/extern.h>

LIBSEDML_CPP_NAMESPACE_USE

/**
 *
 * ListWrapper : a wrapper template class for List class.
 *
 * Currently (2009-05-26), this template class is used for wrapping
 * the following functions in each language bindings.
 *
 *  - List* ModelHistory::getListCreators()
 *  - List* ModelHistory::getListModifiedDates()
 *  - List* SBase::getCVTerms()
 *  - List* ASTNode::getListOfNodes()
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
