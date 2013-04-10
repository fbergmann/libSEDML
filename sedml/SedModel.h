/**
 * @file:   SedMLModel.h
 * @brief:  Implementation of the SedMLModel class
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


#ifndef SedMLModel_H__
#define SedMLModel_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/Change.h>


class LIBSEDML_EXTERN SedMLModel : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;
	std::string   mLanguage;
	std::string   mSource;
	SedListOfChanges   mChange;


public:

	/**
	 * Creates a new SedMLModel with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedMLModel
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedMLModel
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedMLModel
	 */
	SedMLModel(unsigned int level      = SEDML_DEFAULT_LEVEL,
	           unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedMLModel with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedMLModel(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for SedMLModel.
	 *
	 * @param orig; the SedMLModel instance to copy.
	 */
	SedMLModel(const SedMLModel& orig);


 	/**
	 * Assignment operator for SedMLModel.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedMLModel& operator=(const SedMLModel& rhs);


 	/**
	 * Creates and returns a deep copy of this SedMLModel object.
	 *
	 * @return a (deep) copy of this SedMLModel object.
	 */
	virtual SedMLModel* clone () const;


 	/**
	 * Destructor for SedMLModel.
	 */
	virtual ~SedMLModel();


 	/**
	 * Returns the value of the "id" attribute of this SedMLModel.
	 *
	 * @return the value of the "id" attribute of this SedMLModel as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLModel's "id" attribute has been set.
	 *
	 * @return @c true if this SedMLModel's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this SedMLModel.
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
	 * Unsets the value of the "id" attribute of this SedMLModel.
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
	 * Returns the value of the "name" attribute of this SedMLModel.
	 *
	 * @return the value of the "name" attribute of this SedMLModel as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLModel's "name" attribute has been set.
	 *
	 * @return @c true if this SedMLModel's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this SedMLModel.
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
	 * Unsets the value of the "name" attribute of this SedMLModel.
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
	 * Returns the value of the "language" attribute of this SedMLModel.
	 *
	 * @return the value of the "language" attribute of this SedMLModel as a string.
	 */
	virtual const std::string& getLanguage() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLModel's "language" attribute has been set.
	 *
	 * @return @c true if this SedMLModel's "language" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetLanguage() const;


	/**
	 * Sets the value of the "language" attribute of this SedMLModel.
	 *
	 * @param language; const std::string& value of the "language" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setLanguage(const std::string& language);


	/**
	 * Unsets the value of the "language" attribute of this SedMLModel.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetLanguage();


	/**
	 * Returns the value of the "source" attribute of this SedMLModel.
	 *
	 * @return the value of the "source" attribute of this SedMLModel as a string.
	 */
	virtual const std::string& getSource() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLModel's "source" attribute has been set.
	 *
	 * @return @c true if this SedMLModel's "source" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetSource() const;


	/**
	 * Sets the value of the "source" attribute of this SedMLModel.
	 *
	 * @param source; const std::string& value of the "source" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setSource(const std::string& source);


	/**
	 * Unsets the value of the "source" attribute of this SedMLModel.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetSource();


	/**
	 * Returns the  "SedListOfChanges" in this SedMLModel object.
	 *
	 * @return the "SedListOfChanges" attribute of this SedMLModel.
	 */
	const SedListOfChanges* getListOfChanges() const;


	/**
	 * Get a Change from the SedListOfChanges.
	 *
	 * @param n the index number of the Change to get.
	 *
	 * @return the nth Change in the SedListOfChanges within this SedMLModel.
	 *
	 * @see getNumChanges()
	 */
	Change* getChange(unsigned int n);


	/**
	 * Get a Change from the SedListOfChanges.
	 *
	 * @param n the index number of the Change to get.
	 *
	 * @return the nth Change in the SedListOfChanges within this SedMLModel.
	 *
	 * @see getNumChanges()
	 */
	const Change* getChange(unsigned int n) const;


	/**
	 * Get a Change from the SedListOfChanges
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Change to get.
	 *
	 * @return the Change in the SedListOfChanges
	 * with the given id or NULL if no such
	 * Change exists.
	 *
	 * @see getChange(unsigned int n)
	 *
	 * @see getNumChanges()
	 */
	Change* getChange(const std::string& sid);


	/**
	 * Get a Change from the SedListOfChanges
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Change to get.
	 *
	 * @return the Change in the SedListOfChanges
	 * with the given id or NULL if no such
	 * Change exists.
	 *
	 * @see getChange(unsigned int n)
	 *
	 * @see getNumChanges()
	 */
	const Change* getChange(const std::string& sid) const;


	/**
	 * Adds a copy the given "Change" to this SedMLModel.
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
	int addChange(const Change* c);


	/**
	 * Get the number of Change objects in this SedMLModel.
	 *
	 * @return the number of Change objects in this SedMLModel
	 */
	unsigned int getNumChanges() const;


	/**
	 * Creates a new RemoveXML object, adds it to this SedMLModels
	 * SedListOfChanges and returns the RemoveXML object created. 
	 *
	 * @return a new RemoveXML object instance
	 *
	 * @see addChange(const Change* c)
	 */
	RemoveXML* createRemoveXML();


	/**
	 * Creates a new ChangeAttribute object, adds it to this SedMLModels
	 * SedListOfChanges and returns the ChangeAttribute object created. 
	 *
	 * @return a new ChangeAttribute object instance
	 *
	 * @see addChange(const Change* c)
	 */
	ChangeAttribute* createChangeAttribute();


	/**
	 * Creates a new ComputeChange object, adds it to this SedMLModels
	 * SedListOfChanges and returns the ComputeChange object created. 
	 *
	 * @return a new ComputeChange object instance
	 *
	 * @see addChange(const Change* c)
	 */
	ComputeChange* createComputeChange();


	/**
	 * Removes the nth Change from the SedListOfChanges within this SedMLModel.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Change to remove.
	 *
	 * @see getNumChanges()
	 */
	Change* removeChange(unsigned int n);


	/**
	 * Removes the Change with the given identifier from the SedListOfChanges within this SedMLModel
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
	Change* removeChange(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedMLModel, is
	 * always @c "sedMLModel".
	 *
	 * @return the name of this element, i.e. @c "sedMLModel".
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
	 * for this SedMLModel object have been set.
	 *
	 * @note The required attributes for a SedMLModel object are:
	 * @li "id"
	 * @li "source"
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this SedMLModel object have been set.
	 *
	 * @note The required elements for a SedMLModel object are:
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

class LIBSEDML_EXTERN SedListOfSedMLModels : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfSedMLModels with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfSedMLModels
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfSedMLModels
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfSedMLModels
	 */
	SedListOfSedMLModels(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                     unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfSedMLModels with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfSedMLModels(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfSedMLModels object.
	 *
	 * @return a (deep) copy of this SedListOfSedMLModels object.
	 */
	virtual SedListOfSedMLModels* clone () const;


 	/**
	 * Get a SedMLModel from the SedListOfSedMLModels.
	 *
	 * @param n the index number of the SedMLModel to get.
	 *
	 * @return the nth SedMLModel in this SedListOfSedMLModels.
	 *
	 * @see size()
	 */
	virtual SedMLModel* get(unsigned int n);


	/**
	 * Get a SedMLModel from the SedListOfSedMLModels.
	 *
	 * @param n the index number of the SedMLModel to get.
	 *
	 * @return the nth SedMLModel in this SedListOfSedMLModels.
	 *
	 * @see size()
	 */
	virtual const SedMLModel* get(unsigned int n) const;


	/**
	 * Get a SedMLModel from the SedListOfSedMLModels
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLModel to get.
	 *
	 * @return SedMLModel in this SedListOfSedMLModels
	 * with the given id or NULL if no such
	 * SedMLModel exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual SedMLModel* get(const std::string& sid);


	/**
	 * Get a SedMLModel from the SedListOfSedMLModels
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLModel to get.
	 *
	 * @return SedMLModel in this SedListOfSedMLModels
	 * with the given id or NULL if no such
	 * SedMLModel exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const SedMLModel* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedMLModel" to this SedListOfSedMLModels.
	 *
	 * @param smlm; the SedMLModel object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSedMLModel(const SedMLModel* smlm);


	/**
	 * Get the number of SedMLModel objects in this SedListOfSedMLModels.
	 *
	 * @return the number of SedMLModel objects in this SedListOfSedMLModels
	 */
	unsigned int getNumSedMLModels() const;


	/**
	 * Creates a new SedMLModel object, adds it to the
	 * SedListOfSedMLModels and returns the SedMLModel object created. 
	 *
	 * @return a new SedMLModel object instance
	 *
	 * @see addSedMLModel(const SedMLModel* smlm)
	 */
	SedMLModel* createSedMLModel();


	/**
	 * Removes the nth SedMLModel from this SedListOfSedMLModels
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the SedMLModel to remove.
	 *
	 * @see size()
	 */
	virtual SedMLModel* remove(unsigned int n);


	/**
	 * Removes the SedMLModel from this SedListOfSedMLModels with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the SedMLModel to remove.
	 *
	 * @return the SedMLModel removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual SedMLModel* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfSedMLModels, is
	 * always @c "sedListOfSedMLModels".
	 *
	 * @return the name of this element, i.e. @c "sedListOfSedMLModels".
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
	 * Creates a new SedMLModel in this SedListOfSedMLModels
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
SedMLModel_t *
SedMLModel_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedMLModel_free(SedMLModel_t * smlm);


LIBSEDML_EXTERN
SedMLModel_t *
SedMLModel_clone(SedMLModel_t * smlm);


LIBSEDML_EXTERN
char *
SedMLModel_getId(SedMLModel_t * smlm);


LIBSEDML_EXTERN
char *
SedMLModel_getName(SedMLModel_t * smlm);


LIBSEDML_EXTERN
char *
SedMLModel_getLanguage(SedMLModel_t * smlm);


LIBSEDML_EXTERN
char *
SedMLModel_getSource(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_isSetId(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_isSetName(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_isSetLanguage(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_isSetSource(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_setId(SedMLModel_t * smlm, const char * id);


LIBSEDML_EXTERN
int
SedMLModel_setName(SedMLModel_t * smlm, const char * name);


LIBSEDML_EXTERN
int
SedMLModel_setLanguage(SedMLModel_t * smlm, const char * language);


LIBSEDML_EXTERN
int
SedMLModel_setSource(SedMLModel_t * smlm, const char * source);


LIBSEDML_EXTERN
int
SedMLModel_unsetId(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_unsetName(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_unsetLanguage(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_unsetSource(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_addChange(SedMLModel_t * smlm, Change_t * c);


LIBSEDML_EXTERN
RemoveXML_t *
SedMLModel_createRemoveXML(SedMLModel_t * smlm);


LIBSEDML_EXTERN
ChangeAttribute_t *
SedMLModel_createChangeAttribute(SedMLModel_t * smlm);


LIBSEDML_EXTERN
ComputeChange_t *
SedMLModel_createComputeChange(SedMLModel_t * smlm);


LIBSEDML_EXTERN
SedListOf_t *
SedMLModel_getSedListOfChanges(SedMLModel_t * smlm);


LIBSEDML_EXTERN
Change_t *
SedMLModel_getChange(SedMLModel_t * smlm, unsigned int n);


LIBSEDML_EXTERN
Change_t *
SedMLModel_getChangeById(SedMLModel_t * smlm, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedMLModel_getNumChanges(SedMLModel_t * smlm);


LIBSEDML_EXTERN
Change_t *
SedMLModel_removeChange(SedMLModel_t * smlm, unsigned int n);


LIBSEDML_EXTERN
Change_t *
SedMLModel_removeChangeById(SedMLModel_t * smlm, const char * sid);


LIBSEDML_EXTERN
int
SedMLModel_hasRequiredAttributes(SedMLModel_t * smlm);


LIBSEDML_EXTERN
int
SedMLModel_hasRequiredElements(SedMLModel_t * smlm);


LIBSEDML_EXTERN
SedMLModel_t *
SedListOfSedMLModels_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedMLModel_t *
SedListOfSedMLModels_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedMLModel_H__  */

