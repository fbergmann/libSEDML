/**
 * @file:   SedSlice.h
 * @brief:  Implementation of the SedSlice class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 *
 * Copyright (c) 2013-2016, Frank T. Bergmann
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


#ifndef SedSlice_H__
#define SedSlice_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedNamespaces.h>




LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSlice : public SedBase
{

protected:

  std::string   mReference;
  std::string   mValue;


public:

  /**
   * Creates a new SedSlice with the given level, version, and package version.
   *
   * @param level an unsigned int, the SEDML Level to assign to this SedSlice
   *
   * @param version an unsigned int, the SEDML Version to assign to this SedSlice
   *
   * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedSlice
   */
  SedSlice(unsigned int level      = SEDML_DEFAULT_LEVEL,
           unsigned int version    = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedSlice with the given SedNamespaces object.
   *
   * @param sedns the SedNamespaces object
   */
  SedSlice(SedNamespaces* sedns);


  /**
   * Copy constructor for SedSlice.
   *
   * @param orig; the SedSlice instance to copy.
   */
  SedSlice(const SedSlice& orig);


  /**
   * Assignment operator for SedSlice.
   *
   * @param rhs; the object whose values are used as the basis
   * of the assignment
   */
  SedSlice& operator=(const SedSlice& rhs);


  /**
   * Creates and returns a deep copy of this SedSlice object.
   *
   * @return a (deep) copy of this SedSlice object.
   */
  virtual SedSlice* clone() const;


  /**
   * Destructor for SedSlice.
   */
  virtual ~SedSlice();


  /**
   * Returns the value of the "reference" attribute of this SedSlice.
   *
   * @return the value of the "reference" attribute of this SedSlice as a string.
   */
  virtual const std::string& getReference() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedSlice's "reference" attribute has been set.
   *
   * @return @c true if this SedSlice's "reference" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetReference() const;


  /**
   * Sets the value of the "reference" attribute of this SedSlice.
   *
   * @param reference; const std::string& value of the "reference" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setReference(const std::string& reference);


  /**
   * Unsets the value of the "reference" attribute of this SedSlice.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_OPERATION_FAILED
   */
  virtual int unsetReference();


  /**
   * Returns the value of the "value" attribute of this SedSlice.
   *
   * @return the value of the "value" attribute of this SedSlice as a string.
   */
  virtual const std::string& getValue() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedSlice's "value" attribute has been set.
   *
   * @return @c true if this SedSlice's "value" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetValue() const;


  /**
   * Sets the value of the "value" attribute of this SedSlice.
   *
   * @param value; const std::string& value of the "value" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setValue(const std::string& value);


  /**
   * Unsets the value of the "value" attribute of this SedSlice.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_OPERATION_FAILED
   */
  virtual int unsetValue();


  /**
   * Returns the XML element name of this object, which for SedSlice, is
   * always @c "sedSlice".
   *
   * @return the name of this element, i.e. @c "sedSlice".
   */
  virtual const std::string& getElementName() const;


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
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes
   * for this SedSlice object have been set.
   *
   * @note The required attributes for a SedSlice object are:
   * @li "reference"
   * @li "value"
   *
   * @return a boolean value indicating whether all the required
   * attributes for this object have been defined.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements
   * for this SedSlice object have been set.
   *
   * @note The required elements for a SedSlice object are:
   *
   * @return a boolean value indicating whether all the required
   * elements for this object have been defined.
   */
  virtual bool hasRequiredElements() const;


  /** @cond doxygen-libsedml-internal */

  /**
   * Subclasses should override this method to write out their contained
   * SEDML objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.
   */
  virtual void writeElements(XMLOutputStream& stream) const;


  /** @endcond doxygen-libsedml-internal */


  /** @cond doxygen-libsedml-internal */

  /**
   * Accepts the given SedVisitor.
   */
  virtual bool accept(SedVisitor& v) const;


  /** @endcond doxygen-libsedml-internal */


  /** @cond doxygen-libsedml-internal */

  /**
   * Sets the parent SedDocument.
   */
  virtual void setSedDocument(SedDocument* d);


  /** @endcond doxygen-libsedml-internal */


  /** @cond doxygen-libsedml-internal */

  /**
   * Connects to child elements.
   */
  virtual void connectToChild();


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
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);


  /** @endcond doxygen-libsedml-internal */


  /** @cond doxygen-libsedml-internal */

  /**
   * Write values of XMLAttributes to the output stream.
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;


  /** @endcond doxygen-libsedml-internal */



};

class LIBSEDML_EXTERN SedListOfSlices : public SedListOf
{

public:

  /**
   * Creates a new SedListOfSlices with the given level, version, and package version.
   *
   * @param level an unsigned int, the SEDML Level to assign to this SedListOfSlices
   *
   * @param version an unsigned int, the SEDML Version to assign to this SedListOfSlices
   *
   * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedListOfSlices
   */
  SedListOfSlices(unsigned int level      = SEDML_DEFAULT_LEVEL,
                  unsigned int version    = SEDML_DEFAULT_VERSION
                 );


  /**
   * Creates a new SedListOfSlices with the given SedNamespaces object.
   *
   * @param sedns the SedNamespaces object
   */
  SedListOfSlices(SedNamespaces* sedns);


  /**
   * Creates and returns a deep copy of this SedListOfSlices object.
   *
   * @return a (deep) copy of this SedListOfSlices object.
   */
  virtual SedListOfSlices* clone() const;


  /**
   * Get a Slice from the SedListOfSlices.
   *
   * @param n the index number of the Slice to get.
   *
   * @return the nth Slice in this SedListOfSlices.
   *
   * @see size()
   */
  virtual SedSlice* get(unsigned int n);


  /**
   * Get a Slice from the SedListOfSlices.
   *
   * @param n the index number of the Slice to get.
   *
   * @return the nth Slice in this SedListOfSlices.
   *
   * @see size()
   */
  virtual const SedSlice* get(unsigned int n) const;


  /**
   * Get a Slice from the SedListOfSlices
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the Slice to get.
   *
   * @return Slice in this SedListOfSlices
   * with the given id or NULL if no such
   * Slice exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual SedSlice* get(const std::string& sid);


  /**
   * Get a Slice from the SedListOfSlices
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the Slice to get.
   *
   * @return Slice in this SedListOfSlices
   * with the given id or NULL if no such
   * Slice exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual const SedSlice* get(const std::string& sid) const;


  /**
   * Adds a copy the given "Slice" to this SedListOfSlices.
   *
   * @param s; the Slice object to add
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  int addSlice(const SedSlice* s);


  /**
   * Get the number of Slice objects in this SedListOfSlices.
   *
   * @return the number of Slice objects in this SedListOfSlices
   */
  unsigned int getNumSlices() const;


  /**
   * Creates a new Slice object, adds it to the
   * SedListOfSlices and returns the Slice object created.
   *
   * @return a new Slice object instance
   *
   * @see addSlice(const SedSlice* s)
   */
  SedSlice* createSlice();


  /**
   * Removes the nth Slice from this SedListOfSlices
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the Slice to remove.
   *
   * @see size()
   */
  virtual SedSlice* remove(unsigned int n);


  /**
   * Removes the Slice from this SedListOfSlices with the given identifier
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   * If none of the items in this list have the identifier @p sid, then
   * @c NULL is returned.
   *
   * @param sid the identifier of the Slice to remove.
   *
   * @return the Slice removed. As mentioned above, the caller owns the
   * returned item.
   */
  virtual SedSlice* remove(const std::string& sid);


  /**
   * Returns the XML element name of this object, which for SedListOfSlices, is
   * always @c "sedListOfSlices".
   *
   * @return the name of this element, i.e. @c "sedListOfSlices".
   */
  virtual const std::string& getElementName() const;


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
  virtual int getTypeCode() const;


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
   * @return the SEDML type code for the objects in this SedListOf instance, or
   * @link SEDMLTypeCode_t#SEDML_UNKNOWN SEDML_UNKNOWN@endlink (default).
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;


protected:

  /** @cond doxygen-libsedml-internal */

  /**
   * Creates a new Slice in this SedListOfSlices
   */
  virtual SedBase* createObject(XMLInputStream& stream);


  /** @endcond doxygen-libsedml-internal */


  /** @cond doxygen-libsedml-internal */

  /**
   * Write the namespace for the Sed package.
   */
  virtual void writeXMLNS(XMLOutputStream& stream) const;


  /** @endcond doxygen-libsedml-internal */



};



LIBSEDML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSEDML_EXTERN
SedSlice_t *
SedSlice_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedSlice_free(SedSlice_t * ss);


LIBSEDML_EXTERN
SedSlice_t *
SedSlice_clone(SedSlice_t * ss);


LIBSEDML_EXTERN
char *
SedSlice_getReference(SedSlice_t * ss);


LIBSEDML_EXTERN
char *
SedSlice_getValue(SedSlice_t * ss);


LIBSEDML_EXTERN
int
SedSlice_isSetReference(SedSlice_t * ss);


LIBSEDML_EXTERN
int
SedSlice_isSetValue(SedSlice_t * ss);


LIBSEDML_EXTERN
int
SedSlice_setReference(SedSlice_t * ss, const char * reference);


LIBSEDML_EXTERN
int
SedSlice_setValue(SedSlice_t * ss, const char * value);


LIBSEDML_EXTERN
int
SedSlice_unsetReference(SedSlice_t * ss);


LIBSEDML_EXTERN
int
SedSlice_unsetValue(SedSlice_t * ss);


LIBSEDML_EXTERN
int
SedSlice_hasRequiredAttributes(SedSlice_t * ss);


LIBSEDML_EXTERN
int
SedSlice_hasRequiredElements(SedSlice_t * ss);


LIBSEDML_EXTERN
SedSlice_t *
SedListOfSlices_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedSlice_t *
SedListOfSlices_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedSlice_H__  */

