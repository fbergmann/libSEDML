/**
 * @file:   SedChange.h
 * @brief:  Implementation of the SedChange class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
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
 * ------------------------------------------------------------------------ -->
 */


#ifndef SedChange_H__
#define SedChange_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN SedChange : public SedBase
{

protected:

	std::string   mTarget;


public:

	/**
	 * Creates a new SedChange with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedChange
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedChange
	 *
	 * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedChange
	 */
	SedChange(unsigned int level      = SEDML_DEFAULT_LEVEL,
	          unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedChange with the given SedNamespaces object.
	 *
	 * @param sedns the SedNamespaces object
	 */
	SedChange(SedNamespaces* sedns);


 	/**
	 * Copy constructor for SedChange.
	 *
	 * @param orig; the SedChange instance to copy.
	 */
	SedChange(const SedChange& orig);


 	/**
	 * Assignment operator for SedChange.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedChange& operator=(const SedChange& rhs);


 	/**
	 * Creates and returns a deep copy of this SedChange object.
	 *
	 * @return a (deep) copy of this SedChange object.
	 */
	virtual SedChange* clone () const;


 	/**
	 * Destructor for SedChange.
	 */
	virtual ~SedChange();


 	/**
	 * Returns the value of the "target" attribute of this SedChange.
	 *
	 * @return the value of the "target" attribute of this SedChange as a string.
	 */
	virtual const std::string& getTarget() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedChange's "target" attribute has been set.
	 *
	 * @return @c true if this SedChange's "target" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetTarget() const;


	/**
	 * Sets the value of the "target" attribute of this SedChange.
	 *
	 * @param target; const std::string& value of the "target" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setTarget(const std::string& target);


	/**
	 * Unsets the value of the "target" attribute of this SedChange.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetTarget();


	/**
	 * Returns the XML element name of this object, which for SedChange, is
	 * always @c "sedChange".
	 *
	 * @return the name of this element, i.e. @c "sedChange".
	 */
	virtual const std::string& getElementName () const;


	/**
	 * Returns the libSEDML type code for this SEDML object.
	 *
	 * @if clike LibSEDML attaches an identifying code to every kind of SEDML
	 * object.  These are known as <em>SEDML type codes</em>.  The set of
	 * possible type codes is defined in the enumeration #SEDMLTypeCode_t.
	 * The names of the type codes all begin with the characters @c
	 * SEDML_. @endif@if java LibSEDML attaches an identifying code to every
	 * kind of SEDML object.  These are known as <em>SEDML type codes</em>.  In
	 * other languages, the set of type codes is stored in an enumeration; in
	 * the Java language interface for libSEDML, the type codes are defined as
	 * static integer constants in the interface class {@link
	 * libsedmlConstants}.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the Python language interface for libSEDML, the type
	 * codes are defined as static integer constants in the interface class
	 * @link libsedml@endlink.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the C# language interface for libSEDML, the type codes
	 * are defined as static integer constants in the interface class @link
	 * libsedmlcs.libsedml@endlink.  The names of the type codes all begin with
	 * the characters @c SEDML_. @endif
	 *
	 * @return the SEDML type code for this object, or
	 * @link SEDMLTypeCode_t#SEDML_UNKNOWN SEDML_UNKNOWN@endlink (default).
	 *
	 * @see getElementName()
	 */
	virtual int getTypeCode () const;


	/**
	 * Predicate returning @c true if all the required attributes
	 * for this SedChange object have been set.
	 *
	 * @note The required attributes for a SedChange object are:
	 * @li "target"
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


/** @cond doxygen-libsedml-internal */

	/**
	 * Subclasses should override this method to write out their contained
	 * SEDML objects as XML elements.  Be sure to call your parents
	 * implementation of this method as well.
	 */
	virtual void writeElements (XMLOutputStream& stream) const;


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

	/**
	 * Accepts the given SedVisitor.
	 */
	virtual bool accept (SedVisitor& v) const;


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

	/**
	 * Sets the parent SedDocument.
	 */
	virtual void setSedDocument (SedDocument* d);


/** @endcond doxygen-libsedml-internal */


protected:

/** @cond doxygen-libsedml-internal */

	/**
	 * Get the list of expected attributes for this element.
	 */
	virtual void addExpectedAttributes(ExpectedAttributes& attributes);


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

	/**
	 * Read values from the given XMLAttributes set into their specific fields.
	 */
	virtual void readAttributes (const XMLAttributes& attributes,
	                             const ExpectedAttributes& expectedAttributes);


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

	/**
	 * Write values of XMLAttributes to the output stream.
	 */
	virtual void writeAttributes (XMLOutputStream& stream) const;


/** @endcond doxygen-libsedml-internal */



};

class LIBSEDML_EXTERN SedListOfChanges : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfChanges with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfChanges
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfChanges
	 *
	 * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedListOfChanges
	 */
	SedListOfChanges(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                 unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfChanges with the given SedNamespaces object.
	 *
	 * @param sedns the SedNamespaces object
	 */
	SedListOfChanges(SedNamespaces* sedns);


 	/**
	 * Creates and returns a deep copy of this SedListOfChanges object.
	 *
	 * @return a (deep) copy of this SedListOfChanges object.
	 */
	virtual SedListOfChanges* clone () const;


 	/**
	 * Get a Change from the SedListOfChanges.
	 *
	 * @param n the index number of the Change to get.
	 *
	 * @return the nth Change in this SedListOfChanges.
	 *
	 * @see size()
	 */
	virtual SedChange* get(unsigned int n);


	/**
	 * Get a Change from the SedListOfChanges.
	 *
	 * @param n the index number of the Change to get.
	 *
	 * @return the nth Change in this SedListOfChanges.
	 *
	 * @see size()
	 */
	virtual const SedChange* get(unsigned int n) const;


	/**
	 * Get a Change from the SedListOfChanges
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Change to get.
	 *
	 * @return Change in this SedListOfChanges
	 * with the given id or NULL if no such
	 * Change exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual SedChange* get(const std::string& sid);


	/**
	 * Get a Change from the SedListOfChanges
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Change to get.
	 *
	 * @return Change in this SedListOfChanges
	 * with the given id or NULL if no such
	 * Change exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const SedChange* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "Change" to this SedListOfChanges.
	 *
	 * @param c; the Change object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addChange(const SedChange* c);


	/**
	 * Get the number of Change objects in this SedListOfChanges.
	 *
	 * @return the number of Change objects in this SedListOfChanges
	 */
	unsigned int getNumChanges() const;


	/**
	 * Creates a new Change object, adds it to the
	 * SedListOfChanges and returns the Change object created.
	 *
	 * @return a new Change object instance
	 *
	 * @see addChange(const SedChange* c)
	 */
	SedAddXML* createAddXML();


	/**
	 * Creates a new Change object, adds it to the
	 * SedListOfChanges and returns the Change object created.
	 *
	 * @return a new Change object instance
	 *
	 * @see addChange(const SedChange* c)
	 */
	SedChangeXML* createChangeXML();


	/**
	 * Creates a new Change object, adds it to the
	 * SedListOfChanges and returns the Change object created.
	 *
	 * @return a new Change object instance
	 *
	 * @see addChange(const SedChange* c)
	 */
	SedRemoveXML* createRemoveXML();


	/**
	 * Creates a new Change object, adds it to the
	 * SedListOfChanges and returns the Change object created.
	 *
	 * @return a new Change object instance
	 *
	 * @see addChange(const SedChange* c)
	 */
	SedChangeAttribute* createChangeAttribute();


	/**
	 * Creates a new Change object, adds it to the
	 * SedListOfChanges and returns the Change object created.
	 *
	 * @return a new Change object instance
	 *
	 * @see addChange(const SedChange* c)
	 */
	SedComputeChange* createComputeChange();


	/**
	 * Removes the nth Change from this SedListOfChanges
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Change to remove.
	 *
	 * @see size()
	 */
	virtual SedChange* remove(unsigned int n);


	/**
	 * Removes the Change from this SedListOfChanges with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Change to remove.
	 *
	 * @return the Change removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual SedChange* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfChanges, is
	 * always @c "sedListOfChanges".
	 *
	 * @return the name of this element, i.e. @c "sedListOfChanges".
	 */
	virtual const std::string& getElementName () const;


	/**
	 * Returns the libSEDML type code for this SEDML object.
	 *
	 * @if clike LibSEDML attaches an identifying code to every kind of SEDML
	 * object.  These are known as <em>SEDML type codes</em>.  The set of
	 * possible type codes is defined in the enumeration #SEDMLTypeCode_t.
	 * The names of the type codes all begin with the characters @c
	 * SEDML_. @endif@if java LibSEDML attaches an identifying code to every
	 * kind of SEDML object.  These are known as <em>SEDML type codes</em>.  In
	 * other languages, the set of type codes is stored in an enumeration; in
	 * the Java language interface for libSEDML, the type codes are defined as
	 * static integer constants in the interface class {@link
	 * libsedmlConstants}.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the Python language interface for libSEDML, the type
	 * codes are defined as static integer constants in the interface class
	 * @link libsedml@endlink.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the C# language interface for libSEDML, the type codes
	 * are defined as static integer constants in the interface class @link
	 * libsedmlcs.libsedml@endlink.  The names of the type codes all begin with
	 * the characters @c SEDML_. @endif
	 *
	 * @return the SEDML type code for this object, or
	 * @link SEDMLTypeCode_t#SEDML_UNKNOWN SEDML_UNKNOWN@endlink (default).
	 *
	 * @see getElementName()
	 */
	virtual int getTypeCode () const;


	/**
	 * Returns the libSEDML type code for the SEDML objects
	 * contained in this SedListOf object
	 *
	 * @if clike LibSEDML attaches an identifying code to every kind of SEDML
	 * object.  These are known as <em>SEDML type codes</em>.  The set of
	 * possible type codes is defined in the enumeration #SEDMLTypeCode_t.
	 * The names of the type codes all begin with the characters @c
	 * SEDML_. @endif@if java LibSEDML attaches an identifying code to every
	 * kind of SEDML object.  These are known as <em>SEDML type codes</em>.  In
	 * other languages, the set of type codes is stored in an enumeration; in
	 * the Java language interface for libSEDML, the type codes are defined as
	 * static integer constants in the interface class {@link
	 * libsedmlConstants}.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the Python language interface for libSEDML, the type
	 * codes are defined as static integer constants in the interface class
	 * @link libsedml@endlink.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the C# language interface for libSEDML, the type codes
	 * are defined as static integer constants in the interface class @link
	 * libsedmlcs.libsedml@endlink.  The names of the type codes all begin with
	 * the characters @c SEDML_. @endif
	 *
	 * @return the SEDML type code for the objects in this SedListOf instance, or
	 * @link SEDMLTypeCode_t#SEDML_UNKNOWN SEDML_UNKNOWN@endlink (default).
	 *
	 * @see getElementName()
	 */
	virtual int getItemTypeCode () const;


protected:

	/** @cond doxygen-libsedml-internal */

	/**
	 * Creates a new Change in this SedListOfChanges
	 */
	virtual SedBase* createObject(XMLInputStream& stream);


	/** @endcond doxygen-libsedml-internal */


	/** @cond doxygen-libsedml-internal */

	/**
	 * Write the namespace for the Sed package.
	 */
	virtual void writeXMLNS(XMLOutputStream& stream) const;


	/** @endcond doxygen-libsedml-internal */



};



LIBSEDML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSEDML_EXTERN
SedChange_t *
SedChange_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedChange_free(SedChange_t * sc);


LIBSEDML_EXTERN
SedChange_t *
SedChange_clone(SedChange_t * sc);


LIBSEDML_EXTERN
char *
SedChange_getTarget(SedChange_t * sc);


LIBSEDML_EXTERN
int
SedChange_isSetTarget(SedChange_t * sc);


LIBSEDML_EXTERN
int
SedChange_setTarget(SedChange_t * sc, const char * target);


LIBSEDML_EXTERN
int
SedChange_unsetTarget(SedChange_t * sc);


LIBSEDML_EXTERN
int
SedChange_hasRequiredAttributes(SedChange_t * sc);


LIBSEDML_EXTERN
SedChange_t *
SedListOfChanges_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedChange_t *
SedListOfChanges_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedChange_H__  */

