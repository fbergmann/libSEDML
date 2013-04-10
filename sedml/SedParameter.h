/**
 * @file:   SedMLParameter.h
 * @brief:  Implementation of the SedMLParameter class
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


#ifndef SedMLParameter_H__
#define SedMLParameter_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN SedMLParameter : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;
	double        mValue;
	bool          mIsSetValue;


public:

	/**
	 * Creates a new SedMLParameter with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedMLParameter
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedMLParameter
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedMLParameter
	 */
	SedMLParameter(unsigned int level      = SEDML_DEFAULT_LEVEL,
	               unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedMLParameter with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedMLParameter(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for SedMLParameter.
	 *
	 * @param orig; the SedMLParameter instance to copy.
	 */
	SedMLParameter(const SedMLParameter& orig);


 	/**
	 * Assignment operator for SedMLParameter.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedMLParameter& operator=(const SedMLParameter& rhs);


 	/**
	 * Creates and returns a deep copy of this SedMLParameter object.
	 *
	 * @return a (deep) copy of this SedMLParameter object.
	 */
	virtual SedMLParameter* clone () const;


 	/**
	 * Destructor for SedMLParameter.
	 */
	virtual ~SedMLParameter();


 	/**
	 * Returns the value of the "id" attribute of this SedMLParameter.
	 *
	 * @return the value of the "id" attribute of this SedMLParameter as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLParameter's "id" attribute has been set.
	 *
	 * @return @c true if this SedMLParameter's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this SedMLParameter.
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
	 * Unsets the value of the "id" attribute of this SedMLParameter.
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
	 * Returns the value of the "name" attribute of this SedMLParameter.
	 *
	 * @return the value of the "name" attribute of this SedMLParameter as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLParameter's "name" attribute has been set.
	 *
	 * @return @c true if this SedMLParameter's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this SedMLParameter.
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
	 * Unsets the value of the "name" attribute of this SedMLParameter.
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
	 * Returns the value of the "value" attribute of this SedMLParameter.
	 *
	 * @return the value of the "value" attribute of this SedMLParameter as a double.
	 */
	virtual const double getValue() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLParameter's "value" attribute has been set.
	 *
	 * @return @c true if this SedMLParameter's "value" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetValue() const;


	/**
	 * Sets the value of the "value" attribute of this SedMLParameter.
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
	 * Unsets the value of the "value" attribute of this SedMLParameter.
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
	 * Returns the XML element name of this object, which for SedMLParameter, is
	 * always @c "sedMLParameter".
	 *
	 * @return the name of this element, i.e. @c "sedMLParameter".
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
	 * for this SedMLParameter object have been set.
	 *
	 * @note The required attributes for a SedMLParameter object are:
	 * @li "id"
	 * @li "value"
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

class LIBSEDML_EXTERN SedListOfSedMLParameters : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfSedMLParameters with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfSedMLParameters
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfSedMLParameters
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfSedMLParameters
	 */
	SedListOfSedMLParameters(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                         unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfSedMLParameters with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfSedMLParameters(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfSedMLParameters object.
	 *
	 * @return a (deep) copy of this SedListOfSedMLParameters object.
	 */
	virtual SedListOfSedMLParameters* clone () const;


 	/**
	 * Get a SedMLParameter from the SedListOfSedMLParameters.
	 *
	 * @param n the index number of the SedMLParameter to get.
	 *
	 * @return the nth SedMLParameter in this SedListOfSedMLParameters.
	 *
	 * @see size()
	 */
	virtual SedMLParameter* get(unsigned int n);


	/**
	 * Get a SedMLParameter from the SedListOfSedMLParameters.
	 *
	 * @param n the index number of the SedMLParameter to get.
	 *
	 * @return the nth SedMLParameter in this SedListOfSedMLParameters.
	 *
	 * @see size()
	 */
	virtual const SedMLParameter* get(unsigned int n) const;


	/**
	 * Get a SedMLParameter from the SedListOfSedMLParameters
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLParameter to get.
	 *
	 * @return SedMLParameter in this SedListOfSedMLParameters
	 * with the given id or NULL if no such
	 * SedMLParameter exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual SedMLParameter* get(const std::string& sid);


	/**
	 * Get a SedMLParameter from the SedListOfSedMLParameters
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLParameter to get.
	 *
	 * @return SedMLParameter in this SedListOfSedMLParameters
	 * with the given id or NULL if no such
	 * SedMLParameter exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const SedMLParameter* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedMLParameter" to this SedListOfSedMLParameters.
	 *
	 * @param smlp; the SedMLParameter object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSedMLParameter(const SedMLParameter* smlp);


	/**
	 * Get the number of SedMLParameter objects in this SedListOfSedMLParameters.
	 *
	 * @return the number of SedMLParameter objects in this SedListOfSedMLParameters
	 */
	unsigned int getNumSedMLParameters() const;


	/**
	 * Creates a new SedMLParameter object, adds it to the
	 * SedListOfSedMLParameters and returns the SedMLParameter object created. 
	 *
	 * @return a new SedMLParameter object instance
	 *
	 * @see addSedMLParameter(const SedMLParameter* smlp)
	 */
	SedMLParameter* createSedMLParameter();


	/**
	 * Removes the nth SedMLParameter from this SedListOfSedMLParameters
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the SedMLParameter to remove.
	 *
	 * @see size()
	 */
	virtual SedMLParameter* remove(unsigned int n);


	/**
	 * Removes the SedMLParameter from this SedListOfSedMLParameters with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the SedMLParameter to remove.
	 *
	 * @return the SedMLParameter removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual SedMLParameter* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfSedMLParameters, is
	 * always @c "sedListOfSedMLParameters".
	 *
	 * @return the name of this element, i.e. @c "sedListOfSedMLParameters".
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
	 * Creates a new SedMLParameter in this SedListOfSedMLParameters
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
SedMLParameter_t *
SedMLParameter_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedMLParameter_free(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
SedMLParameter_t *
SedMLParameter_clone(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
char *
SedMLParameter_getId(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
char *
SedMLParameter_getName(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
double
SedMLParameter_getValue(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
int
SedMLParameter_isSetId(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
int
SedMLParameter_isSetName(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
int
SedMLParameter_isSetValue(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
int
SedMLParameter_setId(SedMLParameter_t * smlp, const char * id);


LIBSEDML_EXTERN
int
SedMLParameter_setName(SedMLParameter_t * smlp, const char * name);


LIBSEDML_EXTERN
int
SedMLParameter_setValue(SedMLParameter_t * smlp, double value);


LIBSEDML_EXTERN
int
SedMLParameter_unsetId(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
int
SedMLParameter_unsetName(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
int
SedMLParameter_unsetValue(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
int
SedMLParameter_hasRequiredAttributes(SedMLParameter_t * smlp);


LIBSEDML_EXTERN
SedMLParameter_t *
SedListOfSedMLParameters_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedMLParameter_t *
SedListOfSedMLParameters_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedMLParameter_H__  */

