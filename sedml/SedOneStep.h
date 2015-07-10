/**
 * @file:   SedOneStep.h
 * @brief:  Implementation of the SedOneStep class
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


#ifndef SedOneStep_H__
#define SedOneStep_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/SedSimulation.h>


class LIBSEDML_EXTERN SedOneStep : public SedSimulation
{

protected:

	double        mStep;
	bool          mIsSetStep;


public:

	/**
	 * Creates a new SedOneStep with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedOneStep
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedOneStep
	 *
	 * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedOneStep
	 */
	SedOneStep(unsigned int level      = SEDML_DEFAULT_LEVEL,
	           unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedOneStep with the given SedNamespaces object.
	 *
	 * @param sedns the SedNamespaces object
	 */
	SedOneStep(SedNamespaces* sedns);


 	/**
	 * Copy constructor for SedOneStep.
	 *
	 * @param orig; the SedOneStep instance to copy.
	 */
	SedOneStep(const SedOneStep& orig);


 	/**
	 * Assignment operator for SedOneStep.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedOneStep& operator=(const SedOneStep& rhs);


 	/**
	 * Creates and returns a deep copy of this SedOneStep object.
	 *
	 * @return a (deep) copy of this SedOneStep object.
	 */
	virtual SedOneStep* clone () const;


 	/**
	 * Destructor for SedOneStep.
	 */
	virtual ~SedOneStep();


 	/**
	 * Returns the value of the "step" attribute of this SedOneStep.
	 *
	 * @return the value of the "step" attribute of this SedOneStep as a double.
	 */
	virtual const double getStep() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedOneStep's "step" attribute has been set.
	 *
	 * @return @c true if this SedOneStep's "step" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetStep() const;


	/**
	 * Sets the value of the "step" attribute of this SedOneStep.
	 *
	 * @param step; double value of the "step" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setStep(double step);


	/**
	 * Unsets the value of the "step" attribute of this SedOneStep.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetStep();


	/**
	 * Returns the XML element name of this object, which for SedOneStep, is
	 * always @c "sedOneStep".
	 *
	 * @return the name of this element, i.e. @c "sedOneStep".
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
	 * for this SedOneStep object have been set.
	 *
	 * @note The required attributes for a SedOneStep object are:
	 * @li "step"
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
	 * return the SEDML object corresponding to next XMLToken.
	 */
	virtual SedBase* createObject(XMLInputStream& stream);


/** @endcond doxygen-libsedml-internal */


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



LIBSEDML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSEDML_EXTERN
SedOneStep_t *
SedOneStep_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedOneStep_free(SedOneStep_t * sos);


LIBSEDML_EXTERN
SedOneStep_t *
SedOneStep_clone(SedOneStep_t * sos);


LIBSEDML_EXTERN
double
SedOneStep_getStep(SedOneStep_t * sos);


LIBSEDML_EXTERN
int
SedOneStep_isSetStep(SedOneStep_t * sos);


LIBSEDML_EXTERN
int
SedOneStep_setStep(SedOneStep_t * sos, double step);


LIBSEDML_EXTERN
int
SedOneStep_unsetStep(SedOneStep_t * sos);


LIBSEDML_EXTERN
int
SedOneStep_hasRequiredAttributes(SedOneStep_t * sos);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedOneStep_H__  */

