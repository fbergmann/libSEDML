/**
 * @file:   SedParameter.h
 * @brief:  Implementation of the SedParameter class
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


#ifndef SedParameter_H__
#define SedParameter_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN SedParameter : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;
	double        mValue;
	bool          mIsSetValue;


public:

	/**
	 * Creates a new SedParameter with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedParameter
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedParameter
	 *
	 * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedParameter
	 */
	SedParameter(unsigned int level      = SEDML_DEFAULT_LEVEL,
	             unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedParameter with the given SedNamespaces object.
	 *
	 * @param sedns the SedNamespaces object
	 */
	SedParameter(SedNamespaces* sedns);


 	/**
	 * Copy constructor for SedParameter.
	 *
	 * @param orig; the SedParameter instance to copy.
	 */
	SedParameter(const SedParameter& orig);


 	/**
	 * Assignment operator for SedParameter.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedParameter& operator=(const SedParameter& rhs);


 	/**
	 * Creates and returns a deep copy of this SedParameter object.
	 *
	 * @return a (deep) copy of this SedParameter object.
	 */
	virtual SedParameter* clone () const;


 	/**
	 * Destructor for SedParameter.
	 */
	virtual ~SedParameter();


 	/**
	 * Returns the value of the "id" attribute of this SedParameter.
	 *
	 * @return the value of the "id" attribute of this SedParameter as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedParameter's "id" attribute has been set.
	 *
	 * @return @c true if this SedParameter's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this SedParameter.
	 *
	 * @param id; const std::string& value of the "id" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setId(const std::string& id);


	/**
	 * Unsets the value of the "id" attribute of this SedParameter.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetId();


	/**
	 * Returns the value of the "name" attribute of this SedParameter.
	 *
	 * @return the value of the "name" attribute of this SedParameter as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedParameter's "name" attribute has been set.
	 *
	 * @return @c true if this SedParameter's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this SedParameter.
	 *
	 * @param name; const std::string& value of the "name" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setName(const std::string& name);


	/**
	 * Unsets the value of the "name" attribute of this SedParameter.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetName();


	/**
	 * Returns the value of the "value" attribute of this SedParameter.
	 *
	 * @return the value of the "value" attribute of this SedParameter as a double.
	 */
	virtual const double getValue() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedParameter's "value" attribute has been set.
	 *
	 * @return @c true if this SedParameter's "value" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetValue() const;


	/**
	 * Sets the value of the "value" attribute of this SedParameter.
	 *
	 * @param value; double value of the "value" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setValue(double value);


	/**
	 * Unsets the value of the "value" attribute of this SedParameter.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetValue();


	/**
	 * Returns the XML element name of this object, which for SedParameter, is
	 * always @c "sedParameter".
	 *
	 * @return the name of this element, i.e. @c "sedParameter".
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
	 * for this SedParameter object have been set.
	 *
	 * @note The required attributes for a SedParameter object are:
	 * @li "id"
	 * @li "value"
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

class LIBSEDML_EXTERN SedListOfParameters : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfParameters with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfParameters
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfParameters
	 *
	 * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedListOfParameters
	 */
	SedListOfParameters(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                    unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfParameters with the given SedNamespaces object.
	 *
	 * @param sedns the SedNamespaces object
	 */
	SedListOfParameters(SedNamespaces* sedns);


 	/**
	 * Creates and returns a deep copy of this SedListOfParameters object.
	 *
	 * @return a (deep) copy of this SedListOfParameters object.
	 */
	virtual SedListOfParameters* clone () const;


 	/**
	 * Get a Parameter from the SedListOfParameters.
	 *
	 * @param n the index number of the Parameter to get.
	 *
	 * @return the nth Parameter in this SedListOfParameters.
	 *
	 * @see size()
	 */
	virtual SedParameter* get(unsigned int n);


	/**
	 * Get a Parameter from the SedListOfParameters.
	 *
	 * @param n the index number of the Parameter to get.
	 *
	 * @return the nth Parameter in this SedListOfParameters.
	 *
	 * @see size()
	 */
	virtual const SedParameter* get(unsigned int n) const;


	/**
	 * Get a Parameter from the SedListOfParameters
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Parameter to get.
	 *
	 * @return Parameter in this SedListOfParameters
	 * with the given id or NULL if no such
	 * Parameter exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual SedParameter* get(const std::string& sid);


	/**
	 * Get a Parameter from the SedListOfParameters
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Parameter to get.
	 *
	 * @return Parameter in this SedListOfParameters
	 * with the given id or NULL if no such
	 * Parameter exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const SedParameter* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "Parameter" to this SedListOfParameters.
	 *
	 * @param p; the Parameter object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addParameter(const SedParameter* p);


	/**
	 * Get the number of Parameter objects in this SedListOfParameters.
	 *
	 * @return the number of Parameter objects in this SedListOfParameters
	 */
	unsigned int getNumParameters() const;


	/**
	 * Creates a new Parameter object, adds it to the
	 * SedListOfParameters and returns the Parameter object created.
	 *
	 * @return a new Parameter object instance
	 *
	 * @see addParameter(const SedParameter* p)
	 */
	SedParameter* createParameter();


	/**
	 * Removes the nth Parameter from this SedListOfParameters
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Parameter to remove.
	 *
	 * @see size()
	 */
	virtual SedParameter* remove(unsigned int n);


	/**
	 * Removes the Parameter from this SedListOfParameters with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Parameter to remove.
	 *
	 * @return the Parameter removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual SedParameter* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfParameters, is
	 * always @c "sedListOfParameters".
	 *
	 * @return the name of this element, i.e. @c "sedListOfParameters".
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
	 * Creates a new Parameter in this SedListOfParameters
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
SedParameter_t *
SedParameter_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedParameter_free(SedParameter_t * sp);


LIBSEDML_EXTERN
SedParameter_t *
SedParameter_clone(SedParameter_t * sp);


LIBSEDML_EXTERN
char *
SedParameter_getId(SedParameter_t * sp);


LIBSEDML_EXTERN
char *
SedParameter_getName(SedParameter_t * sp);


LIBSEDML_EXTERN
double
SedParameter_getValue(SedParameter_t * sp);


LIBSEDML_EXTERN
int
SedParameter_isSetId(SedParameter_t * sp);


LIBSEDML_EXTERN
int
SedParameter_isSetName(SedParameter_t * sp);


LIBSEDML_EXTERN
int
SedParameter_isSetValue(SedParameter_t * sp);


LIBSEDML_EXTERN
int
SedParameter_setId(SedParameter_t * sp, const char * id);


LIBSEDML_EXTERN
int
SedParameter_setName(SedParameter_t * sp, const char * name);


LIBSEDML_EXTERN
int
SedParameter_setValue(SedParameter_t * sp, double value);


LIBSEDML_EXTERN
int
SedParameter_unsetId(SedParameter_t * sp);


LIBSEDML_EXTERN
int
SedParameter_unsetName(SedParameter_t * sp);


LIBSEDML_EXTERN
int
SedParameter_unsetValue(SedParameter_t * sp);


LIBSEDML_EXTERN
int
SedParameter_hasRequiredAttributes(SedParameter_t * sp);


LIBSEDML_EXTERN
SedParameter_t *
SedListOfParameters_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedParameter_t *
SedListOfParameters_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedParameter_H__  */

