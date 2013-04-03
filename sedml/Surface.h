/**
 * @file:   Surface.h
 * @brief:  Implementation of the Surface class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SEDML, and the latest version of libSEDML.
 *
 * Copyright (c) 2013, Frank T. Bergmann  
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


#ifndef Surface_H__
#define Surface_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/SedMLCurve.h>


class LIBSEDML_EXTERN Surface : public SedMLCurve
{

protected:

	bool          mLogZ;
	bool          mIsSetLogZ;
	std::string   mZDataReference;


public:

	/**
	 * Creates a new Surface with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this Surface
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this Surface
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this Surface
	 */
	Surface(unsigned int level      = SEDML_DEFAULT_LEVEL,
	        unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new Surface with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	Surface(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for Surface.
	 *
	 * @param orig; the Surface instance to copy.
	 */
	Surface(const Surface& orig);


 	/**
	 * Assignment operator for Surface.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	Surface& operator=(const Surface& rhs);


 	/**
	 * Creates and returns a deep copy of this Surface object.
	 *
	 * @return a (deep) copy of this Surface object.
	 */
	virtual Surface* clone () const;


 	/**
	 * Destructor for Surface.
	 */
	virtual ~Surface();


 	/**
	 * Returns the value of the "logZ" attribute of this Surface.
	 *
	 * @return the value of the "logZ" attribute of this Surface as a boolean.
	 */
	virtual const bool getLogZ() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Surface's "logZ" attribute has been set.
	 *
	 * @return @c true if this Surface's "logZ" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetLogZ() const;


	/**
	 * Sets the value of the "logZ" attribute of this Surface.
	 *
	 * @param logZ; bool value of the "logZ" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setLogZ(bool logZ);


	/**
	 * Unsets the value of the "logZ" attribute of this Surface.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetLogZ();


	/**
	 * Returns the value of the "zDataReference" attribute of this Surface.
	 *
	 * @return the value of the "zDataReference" attribute of this Surface as a string.
	 */
	virtual const std::string& getZDataReference() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Surface's "zDataReference" attribute has been set.
	 *
	 * @return @c true if this Surface's "zDataReference" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetZDataReference() const;


	/**
	 * Sets the value of the "zDataReference" attribute of this Surface.
	 *
	 * @param zDataReference; const std::string& value of the "zDataReference" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setZDataReference(const std::string& zDataReference);


	/**
	 * Unsets the value of the "zDataReference" attribute of this Surface.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetZDataReference();


	/**
	 * Returns the XML element name of this object, which for Surface, is
	 * always @c "surface".
	 *
	 * @return the name of this element, i.e. @c "surface".
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
	 * libsbmlConstants}.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the Python language interface for libSEDML, the type
	 * codes are defined as static integer constants in the interface class
	 * @link libsbml@endlink.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the C# language interface for libSEDML, the type codes
	 * are defined as static integer constants in the interface class @link
	 * libsbmlcs.libsbml@endlink.  The names of the type codes all begin with
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
	 * for this Surface object have been set.
	 *
	 * @note The required attributes for a Surface object are:
	 * @li "logZ"
	 * @li "zDataReference"
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


/** @cond doxygen-libsbml-internal */

	/**
	 * Subclasses should override this method to write out their contained
	 * SEDML objects as XML elements.  Be sure to call your parents
	 * implementation of this method as well.
	 */
	virtual void writeElements (XMLOutputStream& stream) const;


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Accepts the given SedMLVisitor.
	 */
	virtual bool accept (SedMLVisitor& v) const;


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Sets the parent SedMLDocument.
	 */
	virtual void setSedMLDocument (SedMLDocument* d);


/** @endcond doxygen-libsbml-internal */


protected:

/** @cond doxygen-libsbml-internal */

	/**
	 * Get the list of expected attributes for this element.
	 */
	virtual void addExpectedAttributes(ExpectedAttributes& attributes);


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Read values from the given XMLAttributes set into their specific fields.
	 */
	virtual void readAttributes (const XMLAttributes& attributes,
	                             const ExpectedAttributes& expectedAttributes);


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Write values of XMLAttributes to the output stream.
	 */
	virtual void writeAttributes (XMLOutputStream& stream) const;


/** @endcond doxygen-libsbml-internal */



};

class LIBSEDML_EXTERN SedListOfSurfaces : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfSurfaces with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfSurfaces
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfSurfaces
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfSurfaces
	 */
	SedListOfSurfaces(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                  unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfSurfaces with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfSurfaces(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfSurfaces object.
	 *
	 * @return a (deep) copy of this SedListOfSurfaces object.
	 */
	virtual SedListOfSurfaces* clone () const;


 	/**
	 * Get a Surface from the SedListOfSurfaces.
	 *
	 * @param n the index number of the Surface to get.
	 *
	 * @return the nth Surface in this SedListOfSurfaces.
	 *
	 * @see size()
	 */
	virtual Surface* get(unsigned int n);


	/**
	 * Get a Surface from the SedListOfSurfaces.
	 *
	 * @param n the index number of the Surface to get.
	 *
	 * @return the nth Surface in this SedListOfSurfaces.
	 *
	 * @see size()
	 */
	virtual const Surface* get(unsigned int n) const;


	/**
	 * Get a Surface from the SedListOfSurfaces
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Surface to get.
	 *
	 * @return Surface in this SedListOfSurfaces
	 * with the given id or NULL if no such
	 * Surface exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual Surface* get(const std::string& sid);


	/**
	 * Get a Surface from the SedListOfSurfaces
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Surface to get.
	 *
	 * @return Surface in this SedListOfSurfaces
	 * with the given id or NULL if no such
	 * Surface exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const Surface* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "Surface" to this SedListOfSurfaces.
	 *
	 * @param s; the Surface object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSurface(const Surface* s);


	/**
	 * Get the number of Surface objects in this SedListOfSurfaces.
	 *
	 * @return the number of Surface objects in this SedListOfSurfaces
	 */
	unsigned int getNumSurfaces() const;


	/**
	 * Creates a new Surface object, adds it to the
	 * SedListOfSurfaces and returns the Surface object created. 
	 *
	 * @return a new Surface object instance
	 *
	 * @see addSurface(const Surface* s)
	 */
	Surface* createSurface();


	/**
	 * Removes the nth Surface from this SedListOfSurfaces
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Surface to remove.
	 *
	 * @see size()
	 */
	virtual Surface* remove(unsigned int n);


	/**
	 * Removes the Surface from this SedListOfSurfaces with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Surface to remove.
	 *
	 * @return the Surface removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual Surface* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfSurfaces, is
	 * always @c "sedListOfSurfaces".
	 *
	 * @return the name of this element, i.e. @c "sedListOfSurfaces".
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
	 * libsbmlConstants}.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the Python language interface for libSEDML, the type
	 * codes are defined as static integer constants in the interface class
	 * @link libsbml@endlink.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the C# language interface for libSEDML, the type codes
	 * are defined as static integer constants in the interface class @link
	 * libsbmlcs.libsbml@endlink.  The names of the type codes all begin with
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
	 * libsbmlConstants}.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the Python language interface for libSEDML, the type
	 * codes are defined as static integer constants in the interface class
	 * @link libsbml@endlink.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the C# language interface for libSEDML, the type codes
	 * are defined as static integer constants in the interface class @link
	 * libsbmlcs.libsbml@endlink.  The names of the type codes all begin with
	 * the characters @c SEDML_. @endif
	 *
	 * @return the SEDML type code for the objects in this SedListOf instance, or
	 * @link SEDMLTypeCode_t#SEDML_UNKNOWN SEDML_UNKNOWN@endlink (default).
	 *
	 * @see getElementName()
	 */
	virtual int getItemTypeCode () const;


protected:

	/** @cond doxygen-libsbml-internal */

	/**
	 * Creates a new Surface in this SedListOfSurfaces
	 */
	virtual SedBase* createObject(XMLInputStream& stream);


	/** @endcond doxygen-libsbml-internal */


	/** @cond doxygen-libsbml-internal */

	/**
	 * Write the namespace for the SedML package.
	 */
	virtual void writeXMLNS(XMLOutputStream& stream) const;


	/** @endcond doxygen-libsbml-internal */



};



LIBSEDML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSEDML_EXTERN
Surface_t *
Surface_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
Surface_free(Surface_t * s);


LIBSEDML_EXTERN
Surface_t *
Surface_clone(Surface_t * s);


LIBSEDML_EXTERN
int
Surface_getLogZ(Surface_t * s);


LIBSEDML_EXTERN
char *
Surface_getZDataReference(Surface_t * s);


LIBSEDML_EXTERN
int
Surface_isSetLogZ(Surface_t * s);


LIBSEDML_EXTERN
int
Surface_isSetZDataReference(Surface_t * s);


LIBSEDML_EXTERN
int
Surface_setLogZ(Surface_t * s, int logZ);


LIBSEDML_EXTERN
int
Surface_setZDataReference(Surface_t * s, const char * zDataReference);


LIBSEDML_EXTERN
int
Surface_unsetLogZ(Surface_t * s);


LIBSEDML_EXTERN
int
Surface_unsetZDataReference(Surface_t * s);


LIBSEDML_EXTERN
int
Surface_hasRequiredAttributes(Surface_t * s);


LIBSEDML_EXTERN
Surface_t *
SedListOfSurfaces_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
Surface_t *
SedListOfSurfaces_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  Surface_H__  */

