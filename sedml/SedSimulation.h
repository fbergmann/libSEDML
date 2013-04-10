/**
 * @file:   Simulation.h
 * @brief:  Implementation of the Simulation class
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


#ifndef Simulation_H__
#define Simulation_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




class LIBSEDML_EXTERN Simulation : public SedBase
{

protected:

	std::string   mId;
	std::string   mName;
	Algorithm*      mAlgorithm;


public:

	/**
	 * Creates a new Simulation with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this Simulation
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this Simulation
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this Simulation
	 */
	Simulation(unsigned int level      = SEDML_DEFAULT_LEVEL,
	           unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new Simulation with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	Simulation(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for Simulation.
	 *
	 * @param orig; the Simulation instance to copy.
	 */
	Simulation(const Simulation& orig);


 	/**
	 * Assignment operator for Simulation.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	Simulation& operator=(const Simulation& rhs);


 	/**
	 * Creates and returns a deep copy of this Simulation object.
	 *
	 * @return a (deep) copy of this Simulation object.
	 */
	virtual Simulation* clone () const;


 	/**
	 * Destructor for Simulation.
	 */
	virtual ~Simulation();


 	/**
	 * Returns the value of the "id" attribute of this Simulation.
	 *
	 * @return the value of the "id" attribute of this Simulation as a string.
	 */
	virtual const std::string& getId() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Simulation's "id" attribute has been set.
	 *
	 * @return @c true if this Simulation's "id" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetId() const;


	/**
	 * Sets the value of the "id" attribute of this Simulation.
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
	 * Unsets the value of the "id" attribute of this Simulation.
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
	 * Returns the value of the "name" attribute of this Simulation.
	 *
	 * @return the value of the "name" attribute of this Simulation as a string.
	 */
	virtual const std::string& getName() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Simulation's "name" attribute has been set.
	 *
	 * @return @c true if this Simulation's "name" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetName() const;


	/**
	 * Sets the value of the "name" attribute of this Simulation.
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
	 * Unsets the value of the "name" attribute of this Simulation.
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
	 * Returns the "algorithm" element of this Simulation.
	 *
	 * @return the "algorithm" element of this Simulation.
	 */
	virtual const Algorithm* getAlgorithm() const;


	/**
	 * Creates a new "algorithm" and sets it for this Simulation.
	 *
	 * @return the created "algorithm" element of this Simulation.
	 */
	virtual Algorithm* createAlgorithm();


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * Simulation's "algorithm" element has been set.
	 *
	 * @return @c true if this Simulation's "algorithm" element has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetAlgorithm() const;


	/**
	 * Sets the "algorithm" element of this Simulation.
	 *
	 * @param algorithm; Algorithm* determining the value of the "resultLevel" attribute to be set.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setAlgorithm(Algorithm* algorithm);


	/**
	 * Unsets the "algorithm" element of this Simulation.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetAlgorithm();


	/**
	 * Returns the XML element name of this object, which for Simulation, is
	 * always @c "simulation".
	 *
	 * @return the name of this element, i.e. @c "simulation".
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
	 * for this Simulation object have been set.
	 *
	 * @note The required attributes for a Simulation object are:
	 * @li "id"
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this Simulation object have been set.
	 *
	 * @note The required elements for a Simulation object are:
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

class LIBSEDML_EXTERN SedListOfSimulations : public SedListOf
{

public:

	/**
	 * Creates a new SedListOfSimulations with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedListOfSimulations
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedListOfSimulations
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedListOfSimulations
	 */
	SedListOfSimulations(unsigned int level      = SEDML_DEFAULT_LEVEL,
	                     unsigned int version    = SEDML_DEFAULT_VERSION
);


	/**
	 * Creates a new SedListOfSimulations with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedListOfSimulations(SedMLNamespaces* sedmlns);


 	/**
	 * Creates and returns a deep copy of this SedListOfSimulations object.
	 *
	 * @return a (deep) copy of this SedListOfSimulations object.
	 */
	virtual SedListOfSimulations* clone () const;


 	/**
	 * Get a Simulation from the SedListOfSimulations.
	 *
	 * @param n the index number of the Simulation to get.
	 *
	 * @return the nth Simulation in this SedListOfSimulations.
	 *
	 * @see size()
	 */
	virtual Simulation* get(unsigned int n);


	/**
	 * Get a Simulation from the SedListOfSimulations.
	 *
	 * @param n the index number of the Simulation to get.
	 *
	 * @return the nth Simulation in this SedListOfSimulations.
	 *
	 * @see size()
	 */
	virtual const Simulation* get(unsigned int n) const;


	/**
	 * Get a Simulation from the SedListOfSimulations
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Simulation to get.
	 *
	 * @return Simulation in this SedListOfSimulations
	 * with the given id or NULL if no such
	 * Simulation exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual Simulation* get(const std::string& sid);


	/**
	 * Get a Simulation from the SedListOfSimulations
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Simulation to get.
	 *
	 * @return Simulation in this SedListOfSimulations
	 * with the given id or NULL if no such
	 * Simulation exists.
	 *
	 * @see get(unsigned int n)	 *
	 * @see size()
	 */
	virtual const Simulation* get(const std::string& sid) const;


	/**
	 * Adds a copy the given "Simulation" to this SedListOfSimulations.
	 *
	 * @param s; the Simulation object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addSimulation(const Simulation* s);


	/**
	 * Get the number of Simulation objects in this SedListOfSimulations.
	 *
	 * @return the number of Simulation objects in this SedListOfSimulations
	 */
	unsigned int getNumSimulations() const;


	/**
	 * Creates a new Simulation object, adds it to the
	 * SedListOfSimulations and returns the Simulation object created. 
	 *
	 * @return a new Simulation object instance
	 *
	 * @see addSimulation(const Simulation* s)
	 */
	Simulation* createSimulation();


	/**
	 * Removes the nth Simulation from this SedListOfSimulations
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Simulation to remove.
	 *
	 * @see size()
	 */
	virtual Simulation* remove(unsigned int n);


	/**
	 * Removes the Simulation from this SedListOfSimulations with the given identifier
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Simulation to remove.
	 *
	 * @return the Simulation removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	virtual Simulation* remove(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedListOfSimulations, is
	 * always @c "sedListOfSimulations".
	 *
	 * @return the name of this element, i.e. @c "sedListOfSimulations".
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
	 * Creates a new Simulation in this SedListOfSimulations
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
Simulation_t *
Simulation_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
Simulation_free(Simulation_t * s);


LIBSEDML_EXTERN
Simulation_t *
Simulation_clone(Simulation_t * s);


LIBSEDML_EXTERN
char *
Simulation_getId(Simulation_t * s);


LIBSEDML_EXTERN
char *
Simulation_getName(Simulation_t * s);


LIBSEDML_EXTERN
Algorithm_t*
Simulation_getAlgorithm(Simulation_t * s);


LIBSEDML_EXTERN
Algorithm_t*
Simulation_createAlgorithm(Simulation_t * s);


LIBSEDML_EXTERN
int
Simulation_isSetId(Simulation_t * s);


LIBSEDML_EXTERN
int
Simulation_isSetName(Simulation_t * s);


LIBSEDML_EXTERN
int
Simulation_isSetAlgorithm(Simulation_t * s);


LIBSEDML_EXTERN
int
Simulation_setId(Simulation_t * s, const char * id);


LIBSEDML_EXTERN
int
Simulation_setName(Simulation_t * s, const char * name);


LIBSEDML_EXTERN
int
Simulation_setAlgorithm(Simulation_t * s, Algorithm_t* algorithm);


LIBSEDML_EXTERN
int
Simulation_unsetId(Simulation_t * s);


LIBSEDML_EXTERN
int
Simulation_unsetName(Simulation_t * s);


LIBSEDML_EXTERN
int
Simulation_unsetAlgorithm(Simulation_t * s);


LIBSEDML_EXTERN
int
Simulation_hasRequiredAttributes(Simulation_t * s);


LIBSEDML_EXTERN
int
Simulation_hasRequiredElements(Simulation_t * s);


LIBSEDML_EXTERN
Simulation_t *
SedListOfSimulations_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
Simulation_t *
SedListOfSimulations_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  Simulation_H__  */

