/**
 * @file:   SedMLVariable.h
 * @brief:  Implementation of the SedMLVariable class
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


#ifndef SedMLVariable_H__
#define SedMLVariable_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN SedMLVariable : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;
	std::string   mSymbol;
	std::string   mTarget;
	std::string   mTaskReference;
	std::string   mModelReference;


public:

	/**
	 * Creates a new SedMLVariable with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedMLVariable
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedMLVariable
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedMLVariable
	 */
	SedMLVariable(unsigned int level      = SEDML_DEFAULT_LEVEL,
	              unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedMLVariable with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedMLVariable(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for SedMLVariable.
	 *
	 * @param orig; the SedMLVariable instance to copy.
	 */
	SedMLVariable(const SedMLVariable& orig);


 	/**
	 * Assignment operator for SedMLVariable.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedMLVariable& operator=(const SedMLVariable& rhs);


 	/**
	 * Creates and returns a deep copy of this SedMLVariable object.
	 *
	 * @return a (deep) copy of this SedMLVariable object.
	 */
	virtual SedMLVariable* clone () const;


 	/**
	 * Destructor for SedMLVariable.
	 */
	virtual ~SedMLVariable();


 	/**
	 * Returns the value of the "id" attribute of this SedMLVariable.
	 *
	 * @return the value of the "id" attribute of this SedMLVariable as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLVariable's "id" attribute has been set.
	 *
	 * @return @c true if this SedMLVariable's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this SedMLVariable.
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
	 * Unsets the value of the "id" attribute of this SedMLVariable.
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
	 * Returns the value of the "name" attribute of this SedMLVariable.
	 *
	 * @return the value of the "name" attribute of this SedMLVariable as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLVariable's "name" attribute has been set.
	 *
	 * @return @c true if this SedMLVariable's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this SedMLVariable.
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
	 * Unsets the value of the "name" attribute of this SedMLVariable.
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
	 * Returns the value of the "symbol" attribute of this SedMLVariable.
	 *
	 * @return the value of the "symbol" attribute of this SedMLVariable as a string.
	 */
	virtual const std::string& getSymbol() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLVariable's "symbol" attribute has been set.
	 *
	 * @return @c true if this SedMLVariable's "symbol" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetSymbol() const;


	/**
	 * Sets the value of the "symbol" attribute of this SedMLVariable.
	 *
	 * @param symbol; const std::string& value of the "symbol" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setSymbol(const std::string& symbol);


	/**
	 * Unsets the value of the "symbol" attribute of this SedMLVariable.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetSymbol();


	/**
	 * Returns the value of the "target" attribute of this SedMLVariable.
	 *
	 * @return the value of the "target" attribute of this SedMLVariable as a string.
	 */
	virtual const std::string& getTarget() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLVariable's "target" attribute has been set.
	 *
	 * @return @c true if this SedMLVariable's "target" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetTarget() const;


	/**
	 * Sets the value of the "target" attribute of this SedMLVariable.
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
	 * Unsets the value of the "target" attribute of this SedMLVariable.
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
	 * Returns the value of the "taskReference" attribute of this SedMLVariable.
	 *
	 * @return the value of the "taskReference" attribute of this SedMLVariable as a string.
	 */
	virtual const std::string& getTaskReference() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLVariable's "taskReference" attribute has been set.
	 *
	 * @return @c true if this SedMLVariable's "taskReference" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetTaskReference() const;


	/**
	 * Sets the value of the "taskReference" attribute of this SedMLVariable.
	 *
	 * @param taskReference; const std::string& value of the "taskReference" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setTaskReference(const std::string& taskReference);


	/**
	 * Unsets the value of the "taskReference" attribute of this SedMLVariable.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetTaskReference();


	/**
	 * Returns the value of the "modelReference" attribute of this SedMLVariable.
	 *
	 * @return the value of the "modelReference" attribute of this SedMLVariable as a string.
	 */
	virtual const std::string& getModelReference() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLVariable's "modelReference" attribute has been set.
	 *
	 * @return @c true if this SedMLVariable's "modelReference" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetModelReference() const;


	/**
	 * Sets the value of the "modelReference" attribute of this SedMLVariable.
	 *
	 * @param modelReference; const std::string& value of the "modelReference" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setModelReference(const std::string& modelReference);


	/**
	 * Unsets the value of the "modelReference" attribute of this SedMLVariable.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetModelReference();


	/**
	 * Returns the XML element name of this object, which for SedMLVariable, is
	 * always @c "sedMLVariable".
	 *
	 * @return the name of this element, i.e. @c "sedMLVariable".
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
	 * for this SedMLVariable object have been set.
	 *
	 * @note The required attributes for a SedMLVariable object are:
	 * @li "id"
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

class LIBSEDML_EXTERN SedListOfSedMLVariables : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfSedMLVariables with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfSedMLVariables
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfSedMLVariables
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfSedMLVariables
	 */
	SedListOfSedMLVariables(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                        unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfSedMLVariables with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfSedMLVariables(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfSedMLVariables object.
	 *
	 * @return a (deep) copy of this SedListOfSedMLVariables object.
	 */
	virtual SedListOfSedMLVariables* clone () const;


 	/**
	 * Get a SedMLVariable from the SedListOfSedMLVariables.
	 *
	 * @param n the index number of the SedMLVariable to get.
	 *
	 * @return the nth SedMLVariable in this SedListOfSedMLVariables.
	 *
	 * @see size()
	 */
	virtual SedMLVariable* get(unsigned int n);


	/**
	 * Get a SedMLVariable from the SedListOfSedMLVariables.
	 *
	 * @param n the index number of the SedMLVariable to get.
	 *
	 * @return the nth SedMLVariable in this SedListOfSedMLVariables.
	 *
	 * @see size()
	 */
	virtual const SedMLVariable* get(unsigned int n) const;


	/**
	 * Get a SedMLVariable from the SedListOfSedMLVariables
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLVariable to get.
	 *
	 * @return SedMLVariable in this SedListOfSedMLVariables
	 * with the given id or NULL if no such
	 * SedMLVariable exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual SedMLVariable* get(const std::string& sid);


	/**
	 * Get a SedMLVariable from the SedListOfSedMLVariables
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLVariable to get.
	 *
	 * @return SedMLVariable in this SedListOfSedMLVariables
	 * with the given id or NULL if no such
	 * SedMLVariable exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const SedMLVariable* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedMLVariable" to this SedListOfSedMLVariables.
	 *
	 * @param smlv; the SedMLVariable object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSedMLVariable(const SedMLVariable* smlv);


	/**
	 * Get the number of SedMLVariable objects in this SedListOfSedMLVariables.
	 *
	 * @return the number of SedMLVariable objects in this SedListOfSedMLVariables
	 */
	unsigned int getNumSedMLVariables() const;


	/**
	 * Creates a new SedMLVariable object, adds it to the
	 * SedListOfSedMLVariables and returns the SedMLVariable object created. 
	 *
	 * @return a new SedMLVariable object instance
	 *
	 * @see addSedMLVariable(const SedMLVariable* smlv)
	 */
	SedMLVariable* createSedMLVariable();


	/**
	 * Removes the nth SedMLVariable from this SedListOfSedMLVariables
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the SedMLVariable to remove.
	 *
	 * @see size()
	 */
	virtual SedMLVariable* remove(unsigned int n);


	/**
	 * Removes the SedMLVariable from this SedListOfSedMLVariables with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the SedMLVariable to remove.
	 *
	 * @return the SedMLVariable removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual SedMLVariable* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfSedMLVariables, is
	 * always @c "sedListOfSedMLVariables".
	 *
	 * @return the name of this element, i.e. @c "sedListOfSedMLVariables".
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
	 * Creates a new SedMLVariable in this SedListOfSedMLVariables
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
SedMLVariable_t *
SedMLVariable_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedMLVariable_free(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
SedMLVariable_t *
SedMLVariable_clone(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
char *
SedMLVariable_getId(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
char *
SedMLVariable_getName(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
char *
SedMLVariable_getSymbol(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
char *
SedMLVariable_getTarget(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
char *
SedMLVariable_getTaskReference(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
char *
SedMLVariable_getModelReference(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_isSetId(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_isSetName(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_isSetSymbol(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_isSetTarget(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_isSetTaskReference(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_isSetModelReference(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_setId(SedMLVariable_t * smlv, const char * id);


LIBSEDML_EXTERN
int
SedMLVariable_setName(SedMLVariable_t * smlv, const char * name);


LIBSEDML_EXTERN
int
SedMLVariable_setSymbol(SedMLVariable_t * smlv, const char * symbol);


LIBSEDML_EXTERN
int
SedMLVariable_setTarget(SedMLVariable_t * smlv, const char * target);


LIBSEDML_EXTERN
int
SedMLVariable_setTaskReference(SedMLVariable_t * smlv, const char * taskReference);


LIBSEDML_EXTERN
int
SedMLVariable_setModelReference(SedMLVariable_t * smlv, const char * modelReference);


LIBSEDML_EXTERN
int
SedMLVariable_unsetId(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_unsetName(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_unsetSymbol(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_unsetTarget(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_unsetTaskReference(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_unsetModelReference(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
int
SedMLVariable_hasRequiredAttributes(SedMLVariable_t * smlv);


LIBSEDML_EXTERN
SedMLVariable_t *
SedListOfSedMLVariables_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedMLVariable_t *
SedListOfSedMLVariables_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedMLVariable_H__  */

