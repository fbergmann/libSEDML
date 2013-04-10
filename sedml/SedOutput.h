/**
 * @file:   SedMLOutput.h
 * @brief:  Implementation of the SedMLOutput class
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


#ifndef SedMLOutput_H__
#define SedMLOutput_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN SedMLOutput : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;


public:

	/**
	 * Creates a new SedMLOutput with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedMLOutput
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedMLOutput
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedMLOutput
	 */
	SedMLOutput(unsigned int level      = SEDML_DEFAULT_LEVEL,
	            unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedMLOutput with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedMLOutput(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for SedMLOutput.
	 *
	 * @param orig; the SedMLOutput instance to copy.
	 */
	SedMLOutput(const SedMLOutput& orig);


 	/**
	 * Assignment operator for SedMLOutput.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedMLOutput& operator=(const SedMLOutput& rhs);


 	/**
	 * Creates and returns a deep copy of this SedMLOutput object.
	 *
	 * @return a (deep) copy of this SedMLOutput object.
	 */
	virtual SedMLOutput* clone () const;


 	/**
	 * Destructor for SedMLOutput.
	 */
	virtual ~SedMLOutput();


 	/**
	 * Returns the value of the "id" attribute of this SedMLOutput.
	 *
	 * @return the value of the "id" attribute of this SedMLOutput as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLOutput's "id" attribute has been set.
	 *
	 * @return @c true if this SedMLOutput's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this SedMLOutput.
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
	 * Unsets the value of the "id" attribute of this SedMLOutput.
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
	 * Returns the value of the "name" attribute of this SedMLOutput.
	 *
	 * @return the value of the "name" attribute of this SedMLOutput as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLOutput's "name" attribute has been set.
	 *
	 * @return @c true if this SedMLOutput's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this SedMLOutput.
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
	 * Unsets the value of the "name" attribute of this SedMLOutput.
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
	 * Returns the XML element name of this object, which for SedMLOutput, is
	 * always @c "sedMLOutput".
	 *
	 * @return the name of this element, i.e. @c "sedMLOutput".
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
	 * for this SedMLOutput object have been set.
	 *
	 * @note The required attributes for a SedMLOutput object are:
	 * @li "id"
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this SedMLOutput object have been set.
	 *
	 * @note The required elements for a SedMLOutput object are:
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

class LIBSEDML_EXTERN SedListOfSedMLOutputs : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfSedMLOutputs with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfSedMLOutputs
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfSedMLOutputs
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfSedMLOutputs
	 */
	SedListOfSedMLOutputs(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                      unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfSedMLOutputs with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfSedMLOutputs(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfSedMLOutputs object.
	 *
	 * @return a (deep) copy of this SedListOfSedMLOutputs object.
	 */
	virtual SedListOfSedMLOutputs* clone () const;


 	/**
	 * Get a SedMLOutput from the SedListOfSedMLOutputs.
	 *
	 * @param n the index number of the SedMLOutput to get.
	 *
	 * @return the nth SedMLOutput in this SedListOfSedMLOutputs.
	 *
	 * @see size()
	 */
	virtual SedMLOutput* get(unsigned int n);


	/**
	 * Get a SedMLOutput from the SedListOfSedMLOutputs.
	 *
	 * @param n the index number of the SedMLOutput to get.
	 *
	 * @return the nth SedMLOutput in this SedListOfSedMLOutputs.
	 *
	 * @see size()
	 */
	virtual const SedMLOutput* get(unsigned int n) const;


	/**
	 * Get a SedMLOutput from the SedListOfSedMLOutputs
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLOutput to get.
	 *
	 * @return SedMLOutput in this SedListOfSedMLOutputs
	 * with the given id or NULL if no such
	 * SedMLOutput exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual SedMLOutput* get(const std::string& sid);


	/**
	 * Get a SedMLOutput from the SedListOfSedMLOutputs
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLOutput to get.
	 *
	 * @return SedMLOutput in this SedListOfSedMLOutputs
	 * with the given id or NULL if no such
	 * SedMLOutput exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const SedMLOutput* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedMLOutput" to this SedListOfSedMLOutputs.
	 *
	 * @param smlo; the SedMLOutput object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSedMLOutput(const SedMLOutput* smlo);


	/**
	 * Get the number of SedMLOutput objects in this SedListOfSedMLOutputs.
	 *
	 * @return the number of SedMLOutput objects in this SedListOfSedMLOutputs
	 */
	unsigned int getNumSedMLOutputs() const;


	/**
	 * Creates a new SedMLOutput object, adds it to the
	 * SedListOfSedMLOutputs and returns the SedMLOutput object created. 
	 *
	 * @return a new SedMLOutput object instance
	 *
	 * @see addSedMLOutput(const SedMLOutput* smlo)
	 */
	SedMLOutput* createSedMLOutput();


	/**
	 * Removes the nth SedMLOutput from this SedListOfSedMLOutputs
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the SedMLOutput to remove.
	 *
	 * @see size()
	 */
	virtual SedMLOutput* remove(unsigned int n);


	/**
	 * Removes the SedMLOutput from this SedListOfSedMLOutputs with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the SedMLOutput to remove.
	 *
	 * @return the SedMLOutput removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual SedMLOutput* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfSedMLOutputs, is
	 * always @c "sedListOfSedMLOutputs".
	 *
	 * @return the name of this element, i.e. @c "sedListOfSedMLOutputs".
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
	 * Creates a new SedMLOutput in this SedListOfSedMLOutputs
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
SedMLOutput_t *
SedMLOutput_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedMLOutput_free(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
SedMLOutput_t *
SedMLOutput_clone(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
char *
SedMLOutput_getId(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
char *
SedMLOutput_getName(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
int
SedMLOutput_isSetId(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
int
SedMLOutput_isSetName(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
int
SedMLOutput_setId(SedMLOutput_t * smlo, const char * id);


LIBSEDML_EXTERN
int
SedMLOutput_setName(SedMLOutput_t * smlo, const char * name);


LIBSEDML_EXTERN
int
SedMLOutput_unsetId(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
int
SedMLOutput_unsetName(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
int
SedMLOutput_hasRequiredAttributes(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
int
SedMLOutput_hasRequiredElements(SedMLOutput_t * smlo);


LIBSEDML_EXTERN
SedMLOutput_t *
SedListOfSedMLOutputs_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedMLOutput_t *
SedListOfSedMLOutputs_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedMLOutput_H__  */

