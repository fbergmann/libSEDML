/**
 * @file:   Plot2D.h
 * @brief:  Implementation of the Plot2D class
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


#ifndef Plot2D_H__
#define Plot2D_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/SedMLOutput.h>
#include <sedml/SedMLCurve.h>


class LIBSEDML_EXTERN Plot2D : public SedMLOutput
{

protected:

	SedListOfSedMLCurves   mCurve;


public:

	/**
	 * Creates a new Plot2D with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this Plot2D
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this Plot2D
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this Plot2D
	 */
	Plot2D(unsigned int level      = SEDML_DEFAULT_LEVEL,
	       unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new Plot2D with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	Plot2D(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for Plot2D.
	 *
	 * @param orig; the Plot2D instance to copy.
	 */
	Plot2D(const Plot2D& orig);


 	/**
	 * Assignment operator for Plot2D.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	Plot2D& operator=(const Plot2D& rhs);


 	/**
	 * Creates and returns a deep copy of this Plot2D object.
	 *
	 * @return a (deep) copy of this Plot2D object.
	 */
	virtual Plot2D* clone () const;


 	/**
	 * Destructor for Plot2D.
	 */
	virtual ~Plot2D();


 	/**
	 * Returns the  "SedListOfSedMLCurves" in this Plot2D object.
	 *
	 * @return the "SedListOfSedMLCurves" attribute of this Plot2D.
	 */
	const SedListOfSedMLCurves* getListOfSedMLCurves() const;


	/**
	 * Get a SedMLCurve from the SedListOfSedMLCurves.
	 *
	 * @param n the index number of the SedMLCurve to get.
	 *
	 * @return the nth SedMLCurve in the SedListOfSedMLCurves within this Plot2D.
	 *
	 * @see getNumSedMLCurves()
	 */
	SedMLCurve* getSedMLCurve(unsigned int n);


	/**
	 * Get a SedMLCurve from the SedListOfSedMLCurves.
	 *
	 * @param n the index number of the SedMLCurve to get.
	 *
	 * @return the nth SedMLCurve in the SedListOfSedMLCurves within this Plot2D.
	 *
	 * @see getNumSedMLCurves()
	 */
	const SedMLCurve* getSedMLCurve(unsigned int n) const;


	/**
	 * Get a SedMLCurve from the SedListOfSedMLCurves
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLCurve to get.
	 *
	 * @return the SedMLCurve in the SedListOfSedMLCurves
	 * with the given id or NULL if no such
	 * SedMLCurve exists.
	 *
	 * @see getSedMLCurve(unsigned int n)
	 *
	 * @see getNumSedMLCurves()
	 */
	SedMLCurve* getSedMLCurve(const std::string& sid);


	/**
	 * Get a SedMLCurve from the SedListOfSedMLCurves
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLCurve to get.
	 *
	 * @return the SedMLCurve in the SedListOfSedMLCurves
	 * with the given id or NULL if no such
	 * SedMLCurve exists.
	 *
	 * @see getSedMLCurve(unsigned int n)
	 *
	 * @see getNumSedMLCurves()
	 */
	const SedMLCurve* getSedMLCurve(const std::string& sid) const;


	/**
	 * Adds a copy the given "SedMLCurve" to this Plot2D.
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
	 * Get the number of SedMLCurve objects in this Plot2D.
	 *
	 * @return the number of SedMLCurve objects in this Plot2D
	 */
	unsigned int getNumSedMLCurves() const;


	/**
	 * Creates a new SedMLCurve object, adds it to this Plot2Ds
	 * SedListOfSedMLCurves and returns the SedMLCurve object created. 
	 *
	 * @return a new SedMLCurve object instance
	 *
	 * @see addSedMLCurve(const SedMLCurve* smlc)
	 */
	SedMLCurve* createSedMLCurve();


	/**
	 * Removes the nth SedMLCurve from the SedListOfSedMLCurves within this Plot2D.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the SedMLCurve to remove.
	 *
	 * @see getNumSedMLCurves()
	 */
	SedMLCurve* removeSedMLCurve(unsigned int n);


	/**
	 * Removes the SedMLCurve with the given identifier from the SedListOfSedMLCurves within this Plot2D
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
	SedMLCurve* removeSedMLCurve(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for Plot2D, is
	 * always @c "plot2D".
	 *
	 * @return the name of this element, i.e. @c "plot2D".
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
	 * for this Plot2D object have been set.
	 *
	 * @note The required attributes for a Plot2D object are:
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this Plot2D object have been set.
	 *
	 * @note The required elements for a Plot2D object are:
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



LIBSEDML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSEDML_EXTERN
Plot2D_t *
Plot2D_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
Plot2D_free(Plot2D_t * pd);


LIBSEDML_EXTERN
Plot2D_t *
Plot2D_clone(Plot2D_t * pd);


LIBSEDML_EXTERN
int
Plot2D_addSedMLCurve(Plot2D_t * pd, SedMLCurve_t * smlc);


LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_createSedMLCurve(Plot2D_t * pd);


LIBSEDML_EXTERN
SedListOf_t *
Plot2D_getSedListOfSedMLCurves(Plot2D_t * pd);


LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_getSedMLCurve(Plot2D_t * pd, unsigned int n);


LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_getSedMLCurveById(Plot2D_t * pd, const char * sid);


LIBSEDML_EXTERN
unsigned int
Plot2D_getNumSedMLCurves(Plot2D_t * pd);


LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_removeSedMLCurve(Plot2D_t * pd, unsigned int n);


LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_removeSedMLCurveById(Plot2D_t * pd, const char * sid);


LIBSEDML_EXTERN
int
Plot2D_hasRequiredAttributes(Plot2D_t * pd);


LIBSEDML_EXTERN
int
Plot2D_hasRequiredElements(Plot2D_t * pd);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  Plot2D_H__  */

