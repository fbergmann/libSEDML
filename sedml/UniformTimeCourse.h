/**
 * @file:   UniformTimeCourse.h
 * @brief:  Implementation of the UniformTimeCourse class
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


#ifndef UniformTimeCourse_H__
#define UniformTimeCourse_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/Simulation.h>


class LIBSEDML_EXTERN UniformTimeCourse : public Simulation
{

protected:

	double        mInitialTime;
	bool          mIsSetInitialTime;
	double        mOutputStartTime;
	bool          mIsSetOutputStartTime;
	double        mOutputEndTime;
	bool          mIsSetOutputEndTime;
	int           mNumberOfPoints;
	bool          mIsSetNumberOfPoints;


public:

	/**
	 * Creates a new UniformTimeCourse with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this UniformTimeCourse
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this UniformTimeCourse
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this UniformTimeCourse
	 */
	UniformTimeCourse(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                  unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new UniformTimeCourse with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	UniformTimeCourse(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for UniformTimeCourse.
	 *
	 * @param orig; the UniformTimeCourse instance to copy.
	 */
	UniformTimeCourse(const UniformTimeCourse& orig);


 	/**
	 * Assignment operator for UniformTimeCourse.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	UniformTimeCourse& operator=(const UniformTimeCourse& rhs);


 	/**
	 * Creates and returns a deep copy of this UniformTimeCourse object.
	 *
	 * @return a (deep) copy of this UniformTimeCourse object.
	 */
	virtual UniformTimeCourse* clone () const;


 	/**
	 * Destructor for UniformTimeCourse.
	 */
	virtual ~UniformTimeCourse();


 	/**
	 * Returns the value of the "initialTime" attribute of this UniformTimeCourse.
	 *
	 * @return the value of the "initialTime" attribute of this UniformTimeCourse as a double.
	 */
	virtual const double getInitialTime() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * UniformTimeCourse's "initialTime" attribute has been set.
	 *
	 * @return @c true if this UniformTimeCourse's "initialTime" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetInitialTime() const;


	/**
	 * Sets the value of the "initialTime" attribute of this UniformTimeCourse.
	 *
	 * @param initialTime; double value of the "initialTime" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setInitialTime(double initialTime);


	/**
	 * Unsets the value of the "initialTime" attribute of this UniformTimeCourse.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetInitialTime();


	/**
	 * Returns the value of the "outputStartTime" attribute of this UniformTimeCourse.
	 *
	 * @return the value of the "outputStartTime" attribute of this UniformTimeCourse as a double.
	 */
	virtual const double getOutputStartTime() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * UniformTimeCourse's "outputStartTime" attribute has been set.
	 *
	 * @return @c true if this UniformTimeCourse's "outputStartTime" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetOutputStartTime() const;


	/**
	 * Sets the value of the "outputStartTime" attribute of this UniformTimeCourse.
	 *
	 * @param outputStartTime; double value of the "outputStartTime" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setOutputStartTime(double outputStartTime);


	/**
	 * Unsets the value of the "outputStartTime" attribute of this UniformTimeCourse.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetOutputStartTime();


	/**
	 * Returns the value of the "outputEndTime" attribute of this UniformTimeCourse.
	 *
	 * @return the value of the "outputEndTime" attribute of this UniformTimeCourse as a double.
	 */
	virtual const double getOutputEndTime() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * UniformTimeCourse's "outputEndTime" attribute has been set.
	 *
	 * @return @c true if this UniformTimeCourse's "outputEndTime" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetOutputEndTime() const;


	/**
	 * Sets the value of the "outputEndTime" attribute of this UniformTimeCourse.
	 *
	 * @param outputEndTime; double value of the "outputEndTime" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setOutputEndTime(double outputEndTime);


	/**
	 * Unsets the value of the "outputEndTime" attribute of this UniformTimeCourse.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetOutputEndTime();


	/**
	 * Returns the value of the "numberOfPoints" attribute of this UniformTimeCourse.
	 *
	 * @return the value of the "numberOfPoints" attribute of this UniformTimeCourse as a integer.
	 */
	virtual const int getNumberOfPoints() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * UniformTimeCourse's "numberOfPoints" attribute has been set.
	 *
	 * @return @c true if this UniformTimeCourse's "numberOfPoints" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetNumberOfPoints() const;


	/**
	 * Sets the value of the "numberOfPoints" attribute of this UniformTimeCourse.
	 *
	 * @param numberOfPoints; int value of the "numberOfPoints" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setNumberOfPoints(int numberOfPoints);


	/**
	 * Unsets the value of the "numberOfPoints" attribute of this UniformTimeCourse.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetNumberOfPoints();


	/**
	 * Returns the XML element name of this object, which for UniformTimeCourse, is
	 * always @c "uniformTimeCourse".
	 *
	 * @return the name of this element, i.e. @c "uniformTimeCourse".
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
	 * for this UniformTimeCourse object have been set.
	 *
	 * @note The required attributes for a UniformTimeCourse object are:
	 * @li "initialTime"
	 * @li "outputStartTime"
	 * @li "outputEndTime"
	 * @li "numberOfPoints"
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
UniformTimeCourse_t *
UniformTimeCourse_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
UniformTimeCourse_free(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
UniformTimeCourse_t *
UniformTimeCourse_clone(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
double
UniformTimeCourse_getInitialTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
double
UniformTimeCourse_getOutputStartTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
double
UniformTimeCourse_getOutputEndTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_getNumberOfPoints(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_isSetInitialTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_isSetOutputStartTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_isSetOutputEndTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_isSetNumberOfPoints(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_setInitialTime(UniformTimeCourse_t * utc, double initialTime);


LIBSEDML_EXTERN
int
UniformTimeCourse_setOutputStartTime(UniformTimeCourse_t * utc, double outputStartTime);


LIBSEDML_EXTERN
int
UniformTimeCourse_setOutputEndTime(UniformTimeCourse_t * utc, double outputEndTime);


LIBSEDML_EXTERN
int
UniformTimeCourse_setNumberOfPoints(UniformTimeCourse_t * utc, int numberOfPoints);


LIBSEDML_EXTERN
int
UniformTimeCourse_unsetInitialTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_unsetOutputStartTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_unsetOutputEndTime(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_unsetNumberOfPoints(UniformTimeCourse_t * utc);


LIBSEDML_EXTERN
int
UniformTimeCourse_hasRequiredAttributes(UniformTimeCourse_t * utc);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  UniformTimeCourse_H__  */

