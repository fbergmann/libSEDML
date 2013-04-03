/**
 * @file:   Plot3D.h
 * @brief:  Implementation of the Plot3D class
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


#ifndef Plot3D_H__
#define Plot3D_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/SedMLOutput.h>
#include <sedml/Surface.h>


class LIBSEDML_EXTERN Plot3D : public SedMLOutput
{

protected:

	SedListOfSurfaces   mSurface;


public:

	/**
	 * Creates a new Plot3D with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this Plot3D
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this Plot3D
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this Plot3D
	 */
	Plot3D(unsigned int level      = SEDML_DEFAULT_LEVEL,
	       unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new Plot3D with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	Plot3D(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for Plot3D.
	 *
	 * @param orig; the Plot3D instance to copy.
	 */
	Plot3D(const Plot3D& orig);


 	/**
	 * Assignment operator for Plot3D.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	Plot3D& operator=(const Plot3D& rhs);


 	/**
	 * Creates and returns a deep copy of this Plot3D object.
	 *
	 * @return a (deep) copy of this Plot3D object.
	 */
	virtual Plot3D* clone () const;


 	/**
	 * Destructor for Plot3D.
	 */
	virtual ~Plot3D();


 	/**
	 * Returns the  "SedListOfSurfaces" in this Plot3D object.
	 *
	 * @return the "SedListOfSurfaces" attribute of this Plot3D.
	 */
	const SedListOfSurfaces* getListOfSurfaces() const;


	/**
	 * Get a Surface from the SedListOfSurfaces.
	 *
	 * @param n the index number of the Surface to get.
	 *
	 * @return the nth Surface in the SedListOfSurfaces within this Plot3D.
	 *
	 * @see getNumSurfaces()
	 */
	Surface* getSurface(unsigned int n);


	/**
	 * Get a Surface from the SedListOfSurfaces.
	 *
	 * @param n the index number of the Surface to get.
	 *
	 * @return the nth Surface in the SedListOfSurfaces within this Plot3D.
	 *
	 * @see getNumSurfaces()
	 */
	const Surface* getSurface(unsigned int n) const;


	/**
	 * Get a Surface from the SedListOfSurfaces
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Surface to get.
	 *
	 * @return the Surface in the SedListOfSurfaces
	 * with the given id or NULL if no such
	 * Surface exists.
	 *
	 * @see getSurface(unsigned int n)
	 *
	 * @see getNumSurfaces()
	 */
	Surface* getSurface(const std::string& sid);


	/**
	 * Get a Surface from the SedListOfSurfaces
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Surface to get.
	 *
	 * @return the Surface in the SedListOfSurfaces
	 * with the given id or NULL if no such
	 * Surface exists.
	 *
	 * @see getSurface(unsigned int n)
	 *
	 * @see getNumSurfaces()
	 */
	const Surface* getSurface(const std::string& sid) const;


	/**
	 * Adds a copy the given "Surface" to this Plot3D.
	 *
	 * @param s; the Surface object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSurface(const Surface* s);


	/**
	 * Get the number of Surface objects in this Plot3D.
	 *
	 * @return the number of Surface objects in this Plot3D
	 */
	unsigned int getNumSurfaces() const;


	/**
	 * Creates a new Surface object, adds it to this Plot3Ds
	 * SedListOfSurfaces and returns the Surface object created. 
	 *
	 * @return a new Surface object instance
	 *
	 * @see addSurface(const Surface* s)
	 */
	Surface* createSurface();


	/**
	 * Removes the nth Surface from the SedListOfSurfaces within this Plot3D.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Surface to remove.
	 *
	 * @see getNumSurfaces()
	 */
	Surface* removeSurface(unsigned int n);


	/**
	 * Removes the Surface with the given identifier from the SedListOfSurfaces within this Plot3D
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Surface to remove.
	 *
	 * @return the Surface removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	Surface* removeSurface(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for Plot3D, is
	 * always @c "plot3D".
	 *
	 * @return the name of this element, i.e. @c "plot3D".
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
	 * for this Plot3D object have been set.
	 *
	 * @note The required attributes for a Plot3D object are:
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this Plot3D object have been set.
	 *
	 * @note The required elements for a Plot3D object are:
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
Plot3D_t *
Plot3D_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
Plot3D_free(Plot3D_t * pd);


LIBSEDML_EXTERN
Plot3D_t *
Plot3D_clone(Plot3D_t * pd);


LIBSEDML_EXTERN
int
Plot3D_addSurface(Plot3D_t * pd, Surface_t * s);


LIBSEDML_EXTERN
Surface_t *
Plot3D_createSurface(Plot3D_t * pd);


LIBSEDML_EXTERN
SedListOf_t *
Plot3D_getSedListOfSurfaces(Plot3D_t * pd);


LIBSEDML_EXTERN
Surface_t *
Plot3D_getSurface(Plot3D_t * pd, unsigned int n);


LIBSEDML_EXTERN
Surface_t *
Plot3D_getSurfaceById(Plot3D_t * pd, const char * sid);


LIBSEDML_EXTERN
unsigned int
Plot3D_getNumSurfaces(Plot3D_t * pd);


LIBSEDML_EXTERN
Surface_t *
Plot3D_removeSurface(Plot3D_t * pd, unsigned int n);


LIBSEDML_EXTERN
Surface_t *
Plot3D_removeSurfaceById(Plot3D_t * pd, const char * sid);


LIBSEDML_EXTERN
int
Plot3D_hasRequiredAttributes(Plot3D_t * pd);


LIBSEDML_EXTERN
int
Plot3D_hasRequiredElements(Plot3D_t * pd);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  Plot3D_H__  */

