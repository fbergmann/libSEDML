/**
 * @file:   Output.h
 * @brief:  Implementation of the Output class
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


#ifndef Output_H__
#define Output_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN Output : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;


public:

	/**
	 * Creates a new Output with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this Output
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this Output
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this Output
	 */
	Output(unsigned int level      = SEDML_DEFAULT_LEVEL,
	       unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new Output with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	Output(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for Output.
	 *
	 * @param orig; the Output instance to copy.
	 */
	Output(const Output& orig);


 	/**
	 * Assignment operator for Output.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	Output& operator=(const Output& rhs);


 	/**
	 * Creates and returns a deep copy of this Output object.
	 *
	 * @return a (deep) copy of this Output object.
	 */
	virtual Output* clone () const;


 	/**
	 * Destructor for Output.
	 */
	virtual ~Output();


 	/**
	 * Returns the value of the "id" attribute of this Output.
	 *
	 * @return the value of the "id" attribute of this Output as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Output's "id" attribute has been set.
	 *
	 * @return @c true if this Output's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this Output.
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
	 * Unsets the value of the "id" attribute of this Output.
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
	 * Returns the value of the "name" attribute of this Output.
	 *
	 * @return the value of the "name" attribute of this Output as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Output's "name" attribute has been set.
	 *
	 * @return @c true if this Output's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this Output.
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
	 * Unsets the value of the "name" attribute of this Output.
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
	 * Returns the XML element name of this object, which for Output, is
	 * always @c "output".
	 *
	 * @return the name of this element, i.e. @c "output".
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
	 * for this Output object have been set.
	 *
	 * @note The required attributes for a Output object are:
	 * @li "id"
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this Output object have been set.
	 *
	 * @note The required elements for a Output object are:
	 *
	 * @return a boolean value indicating whether all the required
	 * elements for this object have been defined.
	 */
	virtual bool hasRequiredElements() const;


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


/** @cond doxygen-libsbml-internal */

	/**
	 * Connects to child elements.
	 */
	virtual void connectToChild ();


/** @endcond doxygen-libsbml-internal */


protected:

/** @cond doxygen-libsbml-internal */

	/**
	 * return the SEDML object corresponding to next XMLToken.
	 */
	virtual SedBase* createObject(XMLInputStream& stream);


/** @endcond doxygen-libsbml-internal */


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

class LIBSEDML_EXTERN SedListOfOutputs : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfOutputs with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfOutputs
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfOutputs
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfOutputs
	 */
	SedListOfOutputs(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                 unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfOutputs with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfOutputs(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfOutputs object.
	 *
	 * @return a (deep) copy of this SedListOfOutputs object.
	 */
	virtual SedListOfOutputs* clone () const;


 	/**
	 * Get a Output from the SedListOfOutputs.
	 *
	 * @param n the index number of the Output to get.
	 *
	 * @return the nth Output in this SedListOfOutputs.
	 *
	 * @see size()
	 */
	virtual Output* get(unsigned int n);


	/**
	 * Get a Output from the SedListOfOutputs.
	 *
	 * @param n the index number of the Output to get.
	 *
	 * @return the nth Output in this SedListOfOutputs.
	 *
	 * @see size()
	 */
	virtual const Output* get(unsigned int n) const;


	/**
	 * Get a Output from the SedListOfOutputs
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Output to get.
	 *
	 * @return Output in this SedListOfOutputs
	 * with the given id or NULL if no such
	 * Output exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual Output* get(const std::string& sid);


	/**
	 * Get a Output from the SedListOfOutputs
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Output to get.
	 *
	 * @return Output in this SedListOfOutputs
	 * with the given id or NULL if no such
	 * Output exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const Output* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "Output" to this SedListOfOutputs.
	 *
	 * @param o; the Output object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addOutput(const Output* o);


	/**
	 * Get the number of Output objects in this SedListOfOutputs.
	 *
	 * @return the number of Output objects in this SedListOfOutputs
	 */
	unsigned int getNumOutputs() const;


	/**
	 * Creates a new Output object, adds it to the
	 * SedListOfOutputs and returns the Output object created. 
	 *
	 * @return a new Output object instance
	 *
	 * @see addOutput(const Output* o)
	 */
	Output* createOutput();


	/**
	 * Removes the nth Output from this SedListOfOutputs
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Output to remove.
	 *
	 * @see size()
	 */
	virtual Output* remove(unsigned int n);


	/**
	 * Removes the Output from this SedListOfOutputs with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Output to remove.
	 *
	 * @return the Output removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual Output* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfOutputs, is
	 * always @c "sedListOfOutputs".
	 *
	 * @return the name of this element, i.e. @c "sedListOfOutputs".
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
	 * Creates a new Output in this SedListOfOutputs
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
Output_t *
Output_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
Output_free(Output_t * o);


LIBSEDML_EXTERN
Output_t *
Output_clone(Output_t * o);


LIBSEDML_EXTERN
char *
Output_getId(Output_t * o);


LIBSEDML_EXTERN
char *
Output_getName(Output_t * o);


LIBSEDML_EXTERN
int
Output_isSetId(Output_t * o);


LIBSEDML_EXTERN
int
Output_isSetName(Output_t * o);


LIBSEDML_EXTERN
int
Output_setId(Output_t * o, const char * id);


LIBSEDML_EXTERN
int
Output_setName(Output_t * o, const char * name);


LIBSEDML_EXTERN
int
Output_unsetId(Output_t * o);


LIBSEDML_EXTERN
int
Output_unsetName(Output_t * o);


LIBSEDML_EXTERN
int
Output_hasRequiredAttributes(Output_t * o);


LIBSEDML_EXTERN
int
Output_hasRequiredElements(Output_t * o);


LIBSEDML_EXTERN
Output_t *
SedListOfOutputs_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
Output_t *
SedListOfOutputs_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  Output_H__  */

