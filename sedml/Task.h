/**
 * @file:   Task.h
 * @brief:  Implementation of the Task class
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


#ifndef Task_H__
#define Task_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN Task : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;
	std::string   mModelReference;
	std::string   mSimulationReference;


public:

	/**
	 * Creates a new Task with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this Task
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this Task
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this Task
	 */
	Task(unsigned int level      = SEDML_DEFAULT_LEVEL,
	     unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new Task with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	Task(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for Task.
	 *
	 * @param orig; the Task instance to copy.
	 */
	Task(const Task& orig);


 	/**
	 * Assignment operator for Task.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	Task& operator=(const Task& rhs);


 	/**
	 * Creates and returns a deep copy of this Task object.
	 *
	 * @return a (deep) copy of this Task object.
	 */
	virtual Task* clone () const;


 	/**
	 * Destructor for Task.
	 */
	virtual ~Task();


 	/**
	 * Returns the value of the "id" attribute of this Task.
	 *
	 * @return the value of the "id" attribute of this Task as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Task's "id" attribute has been set.
	 *
	 * @return @c true if this Task's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this Task.
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
	 * Unsets the value of the "id" attribute of this Task.
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
	 * Returns the value of the "name" attribute of this Task.
	 *
	 * @return the value of the "name" attribute of this Task as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Task's "name" attribute has been set.
	 *
	 * @return @c true if this Task's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this Task.
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
	 * Unsets the value of the "name" attribute of this Task.
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
	 * Returns the value of the "modelReference" attribute of this Task.
	 *
	 * @return the value of the "modelReference" attribute of this Task as a string.
	 */
	virtual const std::string& getModelReference() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Task's "modelReference" attribute has been set.
	 *
	 * @return @c true if this Task's "modelReference" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetModelReference() const;


	/**
	 * Sets the value of the "modelReference" attribute of this Task.
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
	 * Unsets the value of the "modelReference" attribute of this Task.
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
	 * Returns the value of the "simulationReference" attribute of this Task.
	 *
	 * @return the value of the "simulationReference" attribute of this Task as a string.
	 */
	virtual const std::string& getSimulationReference() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Task's "simulationReference" attribute has been set.
	 *
	 * @return @c true if this Task's "simulationReference" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetSimulationReference() const;


	/**
	 * Sets the value of the "simulationReference" attribute of this Task.
	 *
	 * @param simulationReference; const std::string& value of the "simulationReference" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setSimulationReference(const std::string& simulationReference);


	/**
	 * Unsets the value of the "simulationReference" attribute of this Task.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetSimulationReference();


	/**
	 * Returns the XML element name of this object, which for Task, is
	 * always @c "task".
	 *
	 * @return the name of this element, i.e. @c "task".
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
	 * for this Task object have been set.
	 *
	 * @note The required attributes for a Task object are:
	 * @li "id"
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this Task object have been set.
	 *
	 * @note The required elements for a Task object are:
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

class LIBSEDML_EXTERN SedListOfTasks : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfTasks with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfTasks
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfTasks
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfTasks
	 */
	SedListOfTasks(unsigned int level      = SEDML_DEFAULT_LEVEL,
	               unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfTasks with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfTasks(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfTasks object.
	 *
	 * @return a (deep) copy of this SedListOfTasks object.
	 */
	virtual SedListOfTasks* clone () const;


 	/**
	 * Get a Task from the SedListOfTasks.
	 *
	 * @param n the index number of the Task to get.
	 *
	 * @return the nth Task in this SedListOfTasks.
	 *
	 * @see size()
	 */
	virtual Task* get(unsigned int n);


	/**
	 * Get a Task from the SedListOfTasks.
	 *
	 * @param n the index number of the Task to get.
	 *
	 * @return the nth Task in this SedListOfTasks.
	 *
	 * @see size()
	 */
	virtual const Task* get(unsigned int n) const;


	/**
	 * Get a Task from the SedListOfTasks
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Task to get.
	 *
	 * @return Task in this SedListOfTasks
	 * with the given id or NULL if no such
	 * Task exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual Task* get(const std::string& sid);


	/**
	 * Get a Task from the SedListOfTasks
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Task to get.
	 *
	 * @return Task in this SedListOfTasks
	 * with the given id or NULL if no such
	 * Task exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const Task* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "Task" to this SedListOfTasks.
	 *
	 * @param t; the Task object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addTask(const Task* t);


	/**
	 * Get the number of Task objects in this SedListOfTasks.
	 *
	 * @return the number of Task objects in this SedListOfTasks
	 */
	unsigned int getNumTasks() const;


	/**
	 * Creates a new Task object, adds it to the
	 * SedListOfTasks and returns the Task object created. 
	 *
	 * @return a new Task object instance
	 *
	 * @see addTask(const Task* t)
	 */
	Task* createTask();


	/**
	 * Removes the nth Task from this SedListOfTasks
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Task to remove.
	 *
	 * @see size()
	 */
	virtual Task* remove(unsigned int n);


	/**
	 * Removes the Task from this SedListOfTasks with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Task to remove.
	 *
	 * @return the Task removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual Task* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfTasks, is
	 * always @c "sedListOfTasks".
	 *
	 * @return the name of this element, i.e. @c "sedListOfTasks".
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
	 * Creates a new Task in this SedListOfTasks
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
Task_t *
Task_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
Task_free(Task_t * t);


LIBSEDML_EXTERN
Task_t *
Task_clone(Task_t * t);


LIBSEDML_EXTERN
char *
Task_getId(Task_t * t);


LIBSEDML_EXTERN
char *
Task_getName(Task_t * t);


LIBSEDML_EXTERN
char *
Task_getModelReference(Task_t * t);


LIBSEDML_EXTERN
char *
Task_getSimulationReference(Task_t * t);


LIBSEDML_EXTERN
int
Task_isSetId(Task_t * t);


LIBSEDML_EXTERN
int
Task_isSetName(Task_t * t);


LIBSEDML_EXTERN
int
Task_isSetModelReference(Task_t * t);


LIBSEDML_EXTERN
int
Task_isSetSimulationReference(Task_t * t);


LIBSEDML_EXTERN
int
Task_setId(Task_t * t, const char * id);


LIBSEDML_EXTERN
int
Task_setName(Task_t * t, const char * name);


LIBSEDML_EXTERN
int
Task_setModelReference(Task_t * t, const char * modelReference);


LIBSEDML_EXTERN
int
Task_setSimulationReference(Task_t * t, const char * simulationReference);


LIBSEDML_EXTERN
int
Task_unsetId(Task_t * t);


LIBSEDML_EXTERN
int
Task_unsetName(Task_t * t);


LIBSEDML_EXTERN
int
Task_unsetModelReference(Task_t * t);


LIBSEDML_EXTERN
int
Task_unsetSimulationReference(Task_t * t);


LIBSEDML_EXTERN
int
Task_hasRequiredAttributes(Task_t * t);


LIBSEDML_EXTERN
int
Task_hasRequiredElements(Task_t * t);


LIBSEDML_EXTERN
Task_t *
SedListOfTasks_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
Task_t *
SedListOfTasks_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  Task_H__  */

