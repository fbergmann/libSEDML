/**
 * @file:   SedMLCurve.h
 * @brief:  Implementation of the SedMLCurve class
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


#ifndef SedMLCurve_H__
#define SedMLCurve_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN SedMLCurve : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;
	bool          mLogX;
	bool          mIsSetLogX;
	bool          mLogY;
	bool          mIsSetLogY;
	std::string   mXDataReference;
	std::string   mYDataReference;


public:

	/**
	 * Creates a new SedMLCurve with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedMLCurve
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedMLCurve
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedMLCurve
	 */
	SedMLCurve(unsigned int level      = SEDML_DEFAULT_LEVEL,
	           unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedMLCurve with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedMLCurve(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for SedMLCurve.
	 *
	 * @param orig; the SedMLCurve instance to copy.
	 */
	SedMLCurve(const SedMLCurve& orig);


 	/**
	 * Assignment operator for SedMLCurve.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedMLCurve& operator=(const SedMLCurve& rhs);


 	/**
	 * Creates and returns a deep copy of this SedMLCurve object.
	 *
	 * @return a (deep) copy of this SedMLCurve object.
	 */
	virtual SedMLCurve* clone () const;


 	/**
	 * Destructor for SedMLCurve.
	 */
	virtual ~SedMLCurve();


 	/**
	 * Returns the value of the "id" attribute of this SedMLCurve.
	 *
	 * @return the value of the "id" attribute of this SedMLCurve as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLCurve's "id" attribute has been set.
	 *
	 * @return @c true if this SedMLCurve's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this SedMLCurve.
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
	 * Unsets the value of the "id" attribute of this SedMLCurve.
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
	 * Returns the value of the "name" attribute of this SedMLCurve.
	 *
	 * @return the value of the "name" attribute of this SedMLCurve as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLCurve's "name" attribute has been set.
	 *
	 * @return @c true if this SedMLCurve's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this SedMLCurve.
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
	 * Unsets the value of the "name" attribute of this SedMLCurve.
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
	 * Returns the value of the "logX" attribute of this SedMLCurve.
	 *
	 * @return the value of the "logX" attribute of this SedMLCurve as a boolean.
	 */
	virtual const bool getLogX() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLCurve's "logX" attribute has been set.
	 *
	 * @return @c true if this SedMLCurve's "logX" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetLogX() const;


	/**
	 * Sets the value of the "logX" attribute of this SedMLCurve.
	 *
	 * @param logX; bool value of the "logX" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setLogX(bool logX);


	/**
	 * Unsets the value of the "logX" attribute of this SedMLCurve.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetLogX();


	/**
	 * Returns the value of the "logY" attribute of this SedMLCurve.
	 *
	 * @return the value of the "logY" attribute of this SedMLCurve as a boolean.
	 */
	virtual const bool getLogY() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLCurve's "logY" attribute has been set.
	 *
	 * @return @c true if this SedMLCurve's "logY" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetLogY() const;


	/**
	 * Sets the value of the "logY" attribute of this SedMLCurve.
	 *
	 * @param logY; bool value of the "logY" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setLogY(bool logY);


	/**
	 * Unsets the value of the "logY" attribute of this SedMLCurve.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetLogY();


	/**
	 * Returns the value of the "xDataReference" attribute of this SedMLCurve.
	 *
	 * @return the value of the "xDataReference" attribute of this SedMLCurve as a string.
	 */
	virtual const std::string& getXDataReference() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLCurve's "xDataReference" attribute has been set.
	 *
	 * @return @c true if this SedMLCurve's "xDataReference" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetXDataReference() const;


	/**
	 * Sets the value of the "xDataReference" attribute of this SedMLCurve.
	 *
	 * @param xDataReference; const std::string& value of the "xDataReference" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setXDataReference(const std::string& xDataReference);


	/**
	 * Unsets the value of the "xDataReference" attribute of this SedMLCurve.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetXDataReference();


	/**
	 * Returns the value of the "yDataReference" attribute of this SedMLCurve.
	 *
	 * @return the value of the "yDataReference" attribute of this SedMLCurve as a string.
	 */
	virtual const std::string& getYDataReference() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLCurve's "yDataReference" attribute has been set.
	 *
	 * @return @c true if this SedMLCurve's "yDataReference" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetYDataReference() const;


	/**
	 * Sets the value of the "yDataReference" attribute of this SedMLCurve.
	 *
	 * @param yDataReference; const std::string& value of the "yDataReference" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setYDataReference(const std::string& yDataReference);


	/**
	 * Unsets the value of the "yDataReference" attribute of this SedMLCurve.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetYDataReference();


	/**
	 * Returns the XML element name of this object, which for SedMLCurve, is
	 * always @c "sedMLCurve".
	 *
	 * @return the name of this element, i.e. @c "sedMLCurve".
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
	 * for this SedMLCurve object have been set.
	 *
	 * @note The required attributes for a SedMLCurve object are:
	 * @li "logX"
	 * @li "logY"
	 * @li "xDataReference"
	 * @li "yDataReference"
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

class LIBSEDML_EXTERN SedListOfSedMLCurves : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfSedMLCurves with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfSedMLCurves
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfSedMLCurves
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfSedMLCurves
	 */
	SedListOfSedMLCurves(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                     unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfSedMLCurves with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfSedMLCurves(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfSedMLCurves object.
	 *
	 * @return a (deep) copy of this SedListOfSedMLCurves object.
	 */
	virtual SedListOfSedMLCurves* clone () const;


 	/**
	 * Get a SedMLCurve from the SedListOfSedMLCurves.
	 *
	 * @param n the index number of the SedMLCurve to get.
	 *
	 * @return the nth SedMLCurve in this SedListOfSedMLCurves.
	 *
	 * @see size()
	 */
	virtual SedMLCurve* get(unsigned int n);


	/**
	 * Get a SedMLCurve from the SedListOfSedMLCurves.
	 *
	 * @param n the index number of the SedMLCurve to get.
	 *
	 * @return the nth SedMLCurve in this SedListOfSedMLCurves.
	 *
	 * @see size()
	 */
	virtual const SedMLCurve* get(unsigned int n) const;


	/**
	 * Get a SedMLCurve from the SedListOfSedMLCurves
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLCurve to get.
	 *
	 * @return SedMLCurve in this SedListOfSedMLCurves
	 * with the given id or NULL if no such
	 * SedMLCurve exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual SedMLCurve* get(const std::string& sid);


	/**
	 * Get a SedMLCurve from the SedListOfSedMLCurves
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLCurve to get.
	 *
	 * @return SedMLCurve in this SedListOfSedMLCurves
	 * with the given id or NULL if no such
	 * SedMLCurve exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const SedMLCurve* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedMLCurve" to this SedListOfSedMLCurves.
	 *
	 * @param smlc; the SedMLCurve object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSedMLCurve(const SedMLCurve* smlc);


	/**
	 * Get the number of SedMLCurve objects in this SedListOfSedMLCurves.
	 *
	 * @return the number of SedMLCurve objects in this SedListOfSedMLCurves
	 */
	unsigned int getNumSedMLCurves() const;


	/**
	 * Creates a new SedMLCurve object, adds it to the
	 * SedListOfSedMLCurves and returns the SedMLCurve object created. 
	 *
	 * @return a new SedMLCurve object instance
	 *
	 * @see addSedMLCurve(const SedMLCurve* smlc)
	 */
	SedMLCurve* createSedMLCurve();


	/**
	 * Removes the nth SedMLCurve from this SedListOfSedMLCurves
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the SedMLCurve to remove.
	 *
	 * @see size()
	 */
	virtual SedMLCurve* remove(unsigned int n);


	/**
	 * Removes the SedMLCurve from this SedListOfSedMLCurves with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the SedMLCurve to remove.
	 *
	 * @return the SedMLCurve removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual SedMLCurve* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfSedMLCurves, is
	 * always @c "sedListOfSedMLCurves".
	 *
	 * @return the name of this element, i.e. @c "sedListOfSedMLCurves".
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
	 * Creates a new SedMLCurve in this SedListOfSedMLCurves
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
SedMLCurve_t *
SedMLCurve_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedMLCurve_free(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
SedMLCurve_t *
SedMLCurve_clone(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
char *
SedMLCurve_getId(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
char *
SedMLCurve_getName(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_getLogX(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_getLogY(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
char *
SedMLCurve_getXDataReference(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
char *
SedMLCurve_getYDataReference(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_isSetId(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_isSetName(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_isSetLogX(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_isSetLogY(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_isSetXDataReference(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_isSetYDataReference(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_setId(SedMLCurve_t * smlc, const char * id);


LIBSEDML_EXTERN
int
SedMLCurve_setName(SedMLCurve_t * smlc, const char * name);


LIBSEDML_EXTERN
int
SedMLCurve_setLogX(SedMLCurve_t * smlc, int logX);


LIBSEDML_EXTERN
int
SedMLCurve_setLogY(SedMLCurve_t * smlc, int logY);


LIBSEDML_EXTERN
int
SedMLCurve_setXDataReference(SedMLCurve_t * smlc, const char * xDataReference);


LIBSEDML_EXTERN
int
SedMLCurve_setYDataReference(SedMLCurve_t * smlc, const char * yDataReference);


LIBSEDML_EXTERN
int
SedMLCurve_unsetId(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_unsetName(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_unsetLogX(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_unsetLogY(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_unsetXDataReference(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_unsetYDataReference(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
int
SedMLCurve_hasRequiredAttributes(SedMLCurve_t * smlc);


LIBSEDML_EXTERN
SedMLCurve_t *
SedListOfSedMLCurves_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedMLCurve_t *
SedListOfSedMLCurves_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedMLCurve_H__  */

