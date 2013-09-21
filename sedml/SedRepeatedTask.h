/**
 * @file:   SedRepeatedTask.h
 * @brief:  Implementation of the SedRepeatedTask class
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


#ifndef SedRepeatedTask_H__
#define SedRepeatedTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/SedRange.h>
#include <sedml/SedSetValue.h>
#include <sedml/SedSubTask.h>


class LIBSEDML_EXTERN SedRepeatedTask : public SedBase
{

protected:

	std::string   mRange;
	bool          mResetModel;
	bool          mIsSetResetModel;
	SedListOfRanges   mRanges;
	SedListOfTaskChanges   mTaskChanges;
	SedListOfSubTasks   mSubTasks;


public:

	/**
	 * Creates a new SedRepeatedTask with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedRepeatedTask
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedRepeatedTask
	 *
	 * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedRepeatedTask
	 */
	SedRepeatedTask(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedRepeatedTask with the given SedNamespaces object.
	 *
	 * @param sedns the SedNamespaces object
	 */
	SedRepeatedTask(SedNamespaces* sedns);


 	/**
	 * Copy constructor for SedRepeatedTask.
	 *
	 * @param orig; the SedRepeatedTask instance to copy.
	 */
	SedRepeatedTask(const SedRepeatedTask& orig);


 	/**
	 * Assignment operator for SedRepeatedTask.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedRepeatedTask& operator=(const SedRepeatedTask& rhs);


 	/**
	 * Creates and returns a deep copy of this SedRepeatedTask object.
	 *
	 * @return a (deep) copy of this SedRepeatedTask object.
	 */
	virtual SedRepeatedTask* clone () const;


 	/**
	 * Destructor for SedRepeatedTask.
	 */
	virtual ~SedRepeatedTask();


 	/**
	 * Returns the value of the "range" attribute of this SedRepeatedTask.
	 *
	 * @return the value of the "range" attribute of this SedRepeatedTask as a string.
	 */
	virtual const std::string& getRange() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedRepeatedTask's "range" attribute has been set.
	 *
	 * @return @c true if this SedRepeatedTask's "range" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetRange() const;


	/**
	 * Sets the value of the "range" attribute of this SedRepeatedTask.
	 *
	 * @param range; const std::string& value of the "range" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setRange(const std::string& range);


	/**
	 * Unsets the value of the "range" attribute of this SedRepeatedTask.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetRange();


	/**
	 * Returns the value of the "resetModel" attribute of this SedRepeatedTask.
	 *
	 * @return the value of the "resetModel" attribute of this SedRepeatedTask as a boolean.
	 */
	virtual const bool getResetModel() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedRepeatedTask's "resetModel" attribute has been set.
	 *
	 * @return @c true if this SedRepeatedTask's "resetModel" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetResetModel() const;


	/**
	 * Sets the value of the "resetModel" attribute of this SedRepeatedTask.
	 *
	 * @param resetModel; bool value of the "resetModel" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setResetModel(bool resetModel);


	/**
	 * Unsets the value of the "resetModel" attribute of this SedRepeatedTask.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetResetModel();


	/**
	 * Returns the  "SedListOfRanges" in this SedRepeatedTask object.
	 *
	 * @return the "SedListOfRanges" attribute of this SedRepeatedTask.
	 */
	const SedListOfRanges* getListOfRangess() const;


	/**
	 * Get a Ranges from the SedListOfRanges.
	 *
	 * @param n the index number of the Ranges to get.
	 *
	 * @return the nth Ranges in the SedListOfRanges within this SedRepeatedTask.
	 *
	 * @see getNumRangess()
	 */
	SedRange* getRanges(unsigned int n);


	/**
	 * Get a Ranges from the SedListOfRanges.
	 *
	 * @param n the index number of the Ranges to get.
	 *
	 * @return the nth Ranges in the SedListOfRanges within this SedRepeatedTask.
	 *
	 * @see getNumRangess()
	 */
	const SedRange* getRanges(unsigned int n) const;


	/**
	 * Get a Ranges from the SedListOfRanges
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Ranges to get.
	 *
	 * @return the Ranges in the SedListOfRanges
	 * with the given id or NULL if no such
	 * Ranges exists.
	 *
	 * @see getRanges(unsigned int n)
	 *
	 * @see getNumRangess()
	 */
	SedRange* getRanges(const std::string& sid);


	/**
	 * Get a Ranges from the SedListOfRanges
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Ranges to get.
	 *
	 * @return the Ranges in the SedListOfRanges
	 * with the given id or NULL if no such
	 * Ranges exists.
	 *
	 * @see getRanges(unsigned int n)
	 *
	 * @see getNumRangess()
	 */
	const SedRange* getRanges(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedRange" to this SedRepeatedTask.
	 *
	 * @param sr; the SedRange object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addRanges(const SedRange* sr);


	/**
	 * Get the number of SedRange objects in this SedRepeatedTask.
	 *
	 * @return the number of SedRange objects in this SedRepeatedTask
	 */
	unsigned int getNumRangess() const;


	/**
	 * Creates a new SedUniformRange object, adds it to this SedRepeatedTasks
	 * SedListOfRanges and returns the SedUniformRange object created. 
	 *
	 * @return a new SedUniformRange object instance
	 *
	 * @see addSedRange(const SedRange* sr)
	 */
	SedUniformRange* createUniformRange();


	/**
	 * Creates a new SedVectorRange object, adds it to this SedRepeatedTasks
	 * SedListOfRanges and returns the SedVectorRange object created. 
	 *
	 * @return a new SedVectorRange object instance
	 *
	 * @see addSedRange(const SedRange* sr)
	 */
	SedVectorRange* createVectorRange();


	/**
	 * Creates a new SedFunctionalRange object, adds it to this SedRepeatedTasks
	 * SedListOfRanges and returns the SedFunctionalRange object created. 
	 *
	 * @return a new SedFunctionalRange object instance
	 *
	 * @see addSedRange(const SedRange* sr)
	 */
	SedFunctionalRange* createFunctionalRange();


	/**
	 * Removes the nth Ranges from the SedListOfRanges within this SedRepeatedTask.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Ranges to remove.
	 *
	 * @see getNumRangess()
	 */
	SedRange* removeRanges(unsigned int n);


	/**
	 * Removes the Ranges with the given identifier from the SedListOfRanges within this SedRepeatedTask
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Ranges to remove.
	 *
	 * @return the Ranges removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	SedRange* removeRanges(const std::string& sid);


	/**
	 * Returns the  "SedListOfTaskChanges" in this SedRepeatedTask object.
	 *
	 * @return the "SedListOfTaskChanges" attribute of this SedRepeatedTask.
	 */
	const SedListOfTaskChanges* getListOfTaskChangess() const;


	/**
	 * Get a TaskChanges from the SedListOfTaskChanges.
	 *
	 * @param n the index number of the TaskChanges to get.
	 *
	 * @return the nth TaskChanges in the SedListOfTaskChanges within this SedRepeatedTask.
	 *
	 * @see getNumTaskChangess()
	 */
	SedSetValue* getTaskChanges(unsigned int n);


	/**
	 * Get a TaskChanges from the SedListOfTaskChanges.
	 *
	 * @param n the index number of the TaskChanges to get.
	 *
	 * @return the nth TaskChanges in the SedListOfTaskChanges within this SedRepeatedTask.
	 *
	 * @see getNumTaskChangess()
	 */
	const SedSetValue* getTaskChanges(unsigned int n) const;


	/**
	 * Get a TaskChanges from the SedListOfTaskChanges
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the TaskChanges to get.
	 *
	 * @return the TaskChanges in the SedListOfTaskChanges
	 * with the given id or NULL if no such
	 * TaskChanges exists.
	 *
	 * @see getTaskChanges(unsigned int n)
	 *
	 * @see getNumTaskChangess()
	 */
	SedSetValue* getTaskChanges(const std::string& sid);


	/**
	 * Get a TaskChanges from the SedListOfTaskChanges
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the TaskChanges to get.
	 *
	 * @return the TaskChanges in the SedListOfTaskChanges
	 * with the given id or NULL if no such
	 * TaskChanges exists.
	 *
	 * @see getTaskChanges(unsigned int n)
	 *
	 * @see getNumTaskChangess()
	 */
	const SedSetValue* getTaskChanges(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedSetValue" to this SedRepeatedTask.
	 *
	 * @param ssv; the SedSetValue object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addTaskChanges(const SedSetValue* ssv);


	/**
	 * Get the number of SedSetValue objects in this SedRepeatedTask.
	 *
	 * @return the number of SedSetValue objects in this SedRepeatedTask
	 */
	unsigned int getNumTaskChangess() const;


	/**
	 * Creates a new SedSetValue object, adds it to this SedRepeatedTasks
	 * SedListOfTaskChanges and returns the SedSetValue object created. 
	 *
	 * @return a new SedSetValue object instance
	 *
	 * @see addTaskChanges(const SedSetValue* ssv)
	 */
	SedSetValue* createTaskChanges();


	/**
	 * Removes the nth TaskChanges from the SedListOfTaskChanges within this SedRepeatedTask.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the TaskChanges to remove.
	 *
	 * @see getNumTaskChangess()
	 */
	SedSetValue* removeTaskChanges(unsigned int n);


	/**
	 * Removes the TaskChanges with the given identifier from the SedListOfTaskChanges within this SedRepeatedTask
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the TaskChanges to remove.
	 *
	 * @return the TaskChanges removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	SedSetValue* removeTaskChanges(const std::string& sid);


	/**
	 * Returns the  "SedListOfSubTasks" in this SedRepeatedTask object.
	 *
	 * @return the "SedListOfSubTasks" attribute of this SedRepeatedTask.
	 */
	const SedListOfSubTasks* getListOfSubTaskss() const;


	/**
	 * Get a SubTasks from the SedListOfSubTasks.
	 *
	 * @param n the index number of the SubTasks to get.
	 *
	 * @return the nth SubTasks in the SedListOfSubTasks within this SedRepeatedTask.
	 *
	 * @see getNumSubTaskss()
	 */
	SedSubTask* getSubTasks(unsigned int n);


	/**
	 * Get a SubTasks from the SedListOfSubTasks.
	 *
	 * @param n the index number of the SubTasks to get.
	 *
	 * @return the nth SubTasks in the SedListOfSubTasks within this SedRepeatedTask.
	 *
	 * @see getNumSubTaskss()
	 */
	const SedSubTask* getSubTasks(unsigned int n) const;


	/**
	 * Get a SubTasks from the SedListOfSubTasks
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SubTasks to get.
	 *
	 * @return the SubTasks in the SedListOfSubTasks
	 * with the given id or NULL if no such
	 * SubTasks exists.
	 *
	 * @see getSubTasks(unsigned int n)
	 *
	 * @see getNumSubTaskss()
	 */
	SedSubTask* getSubTasks(const std::string& sid);


	/**
	 * Get a SubTasks from the SedListOfSubTasks
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SubTasks to get.
	 *
	 * @return the SubTasks in the SedListOfSubTasks
	 * with the given id or NULL if no such
	 * SubTasks exists.
	 *
	 * @see getSubTasks(unsigned int n)
	 *
	 * @see getNumSubTaskss()
	 */
	const SedSubTask* getSubTasks(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedSubTask" to this SedRepeatedTask.
	 *
	 * @param sst; the SedSubTask object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSubTasks(const SedSubTask* sst);


	/**
	 * Get the number of SedSubTask objects in this SedRepeatedTask.
	 *
	 * @return the number of SedSubTask objects in this SedRepeatedTask
	 */
	unsigned int getNumSubTaskss() const;


	/**
	 * Creates a new SedSubTask object, adds it to this SedRepeatedTasks
	 * SedListOfSubTasks and returns the SedSubTask object created. 
	 *
	 * @return a new SedSubTask object instance
	 *
	 * @see addSubTasks(const SedSubTask* sst)
	 */
	SedSubTask* createSubTasks();


	/**
	 * Removes the nth SubTasks from the SedListOfSubTasks within this SedRepeatedTask.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the SubTasks to remove.
	 *
	 * @see getNumSubTaskss()
	 */
	SedSubTask* removeSubTasks(unsigned int n);


	/**
	 * Removes the SubTasks with the given identifier from the SedListOfSubTasks within this SedRepeatedTask
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the SubTasks to remove.
	 *
	 * @return the SubTasks removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	SedSubTask* removeSubTasks(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedRepeatedTask, is
	 * always @c "sedRepeatedTask".
	 *
	 * @return the name of this element, i.e. @c "sedRepeatedTask".
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
	 * for this SedRepeatedTask object have been set.
	 *
	 * @note The required attributes for a SedRepeatedTask object are:
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this SedRepeatedTask object have been set.
	 *
	 * @note The required elements for a SedRepeatedTask object are:
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
	 * Accepts the given SedVisitor.
	 */
	virtual bool accept (SedVisitor& v) const;


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Sets the parent SedDocument.
	 */
	virtual void setSedDocument (SedDocument* d);


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



LIBSEDML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedRepeatedTask_free(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_clone(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
char *
SedRepeatedTask_getRange(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
int
SedRepeatedTask_getResetModel(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
int
SedRepeatedTask_isSetRange(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
int
SedRepeatedTask_isSetResetModel(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
int
SedRepeatedTask_setRange(SedRepeatedTask_t * srt, const char * range);


LIBSEDML_EXTERN
int
SedRepeatedTask_setResetModel(SedRepeatedTask_t * srt, int resetModel);


LIBSEDML_EXTERN
int
SedRepeatedTask_unsetRange(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
int
SedRepeatedTask_unsetResetModel(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
int
SedRepeatedTask_addRanges(SedRepeatedTask_t * srt, SedRange_t * sr);


LIBSEDML_EXTERN
SedUniformRange_t *
SedRepeatedTask_createUniformRange(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedVectorRange_t *
SedRepeatedTask_createVectorRange(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedFunctionalRange_t *
SedRepeatedTask_createFunctionalRange(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfRanges(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_getRanges(SedRepeatedTask_t * srt, unsigned int n);


LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_getRangesById(SedRepeatedTask_t * srt, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumRangess(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_removeRanges(SedRepeatedTask_t * srt, unsigned int n);


LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_removeRangesById(SedRepeatedTask_t * srt, const char * sid);


LIBSEDML_EXTERN
int
SedRepeatedTask_addTaskChanges(SedRepeatedTask_t * srt, SedSetValue_t * ssv);


LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_createTaskChanges(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfTaskChanges(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_getTaskChanges(SedRepeatedTask_t * srt, unsigned int n);


LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_getTaskChangesById(SedRepeatedTask_t * srt, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumTaskChangess(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_removeTaskChanges(SedRepeatedTask_t * srt, unsigned int n);


LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_removeTaskChangesById(SedRepeatedTask_t * srt, const char * sid);


LIBSEDML_EXTERN
int
SedRepeatedTask_addSubTasks(SedRepeatedTask_t * srt, SedSubTask_t * sst);


LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_createSubTasks(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfSubTasks(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_getSubTasks(SedRepeatedTask_t * srt, unsigned int n);


LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_getSubTasksById(SedRepeatedTask_t * srt, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumSubTaskss(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_removeSubTasks(SedRepeatedTask_t * srt, unsigned int n);


LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_removeSubTasksById(SedRepeatedTask_t * srt, const char * sid);


LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredAttributes(SedRepeatedTask_t * srt);


LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredElements(SedRepeatedTask_t * srt);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedRepeatedTask_H__  */

