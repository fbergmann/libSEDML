/**
 * @file:   ChangeAttribute.h
 * @brief:  Implementation of the ChangeAttribute class
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


#ifndef ChangeAttribute_H__
#define ChangeAttribute_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/Change.h>


class LIBSEDML_EXTERN ChangeAttribute : public Change
{

protected:

	std::string   mNewValue;


public:

	/**
	 * Creates a new ChangeAttribute with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this ChangeAttribute
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this ChangeAttribute
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this ChangeAttribute
	 */
	ChangeAttribute(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new ChangeAttribute with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	ChangeAttribute(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for ChangeAttribute.
	 *
	 * @param orig; the ChangeAttribute instance to copy.
	 */
	ChangeAttribute(const ChangeAttribute& orig);


 	/**
	 * Assignment operator for ChangeAttribute.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	ChangeAttribute& operator=(const ChangeAttribute& rhs);


 	/**
	 * Creates and returns a deep copy of this ChangeAttribute object.
	 *
	 * @return a (deep) copy of this ChangeAttribute object.
	 */
	virtual ChangeAttribute* clone () const;


 	/**
	 * Destructor for ChangeAttribute.
	 */
	virtual ~ChangeAttribute();


 	/**
	 * Returns the value of the "newValue" attribute of this ChangeAttribute.
	 *
	 * @return the value of the "newValue" attribute of this ChangeAttribute as a string.
	 */
	virtual const std::string& getNewValue() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * ChangeAttribute's "newValue" attribute has been set.
	 *
	 * @return @c true if this ChangeAttribute's "newValue" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetNewValue() const;


	/**
	 * Sets the value of the "newValue" attribute of this ChangeAttribute.
	 *
	 * @param newValue; const std::string& value of the "newValue" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setNewValue(const std::string& newValue);


	/**
	 * Unsets the value of the "newValue" attribute of this ChangeAttribute.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetNewValue();


	/**
	 * Returns the XML element name of this object, which for ChangeAttribute, is
	 * always @c "changeAttribute".
	 *
	 * @return the name of this element, i.e. @c "changeAttribute".
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
	 * for this ChangeAttribute object have been set.
	 *
	 * @note The required attributes for a ChangeAttribute object are:
	 * @li "newValue"
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



LIBSEDML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSEDML_EXTERN
ChangeAttribute_t *
ChangeAttribute_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
ChangeAttribute_free(ChangeAttribute_t * ca);


LIBSEDML_EXTERN
ChangeAttribute_t *
ChangeAttribute_clone(ChangeAttribute_t * ca);


LIBSEDML_EXTERN
char *
ChangeAttribute_getNewValue(ChangeAttribute_t * ca);


LIBSEDML_EXTERN
int
ChangeAttribute_isSetNewValue(ChangeAttribute_t * ca);


LIBSEDML_EXTERN
int
ChangeAttribute_setNewValue(ChangeAttribute_t * ca, const char * newValue);


LIBSEDML_EXTERN
int
ChangeAttribute_unsetNewValue(ChangeAttribute_t * ca);


LIBSEDML_EXTERN
int
ChangeAttribute_hasRequiredAttributes(ChangeAttribute_t * ca);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  ChangeAttribute_H__  */

