/**
 * @file:   SedDataSource.h
 * @brief:  Implementation of the SedDataSource class
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


#ifndef SedDataSource_H__
#define SedDataSource_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedNamespaces.h>
#include <sedml/SedSlice.h>




LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDataSource : public SedBase
{

protected:

  std::string   mId;
  std::string   mName;
  std::string   mIndexSet;
  SedListOfSlices   mSlices;


public:

  /**
   * Creates a new SedDataSource with the given level, version, and package version.
   *
   * @param level an unsigned int, the SEDML Level to assign to this SedDataSource
   *
   * @param version an unsigned int, the SEDML Version to assign to this SedDataSource
   *
   * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedDataSource
   */
  SedDataSource(unsigned int level      = SEDML_DEFAULT_LEVEL,
                unsigned int version    = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDataSource with the given SedNamespaces object.
   *
   * @param sedns the SedNamespaces object
   */
  SedDataSource(SedNamespaces* sedns);


  /**
   * Copy constructor for SedDataSource.
   *
   * @param orig; the SedDataSource instance to copy.
   */
  SedDataSource(const SedDataSource& orig);


  /**
   * Assignment operator for SedDataSource.
   *
   * @param rhs; the object whose values are used as the basis
   * of the assignment
   */
  SedDataSource& operator=(const SedDataSource& rhs);


  /**
   * Creates and returns a deep copy of this SedDataSource object.
   *
   * @return a (deep) copy of this SedDataSource object.
   */
  virtual SedDataSource* clone() const;


  /**
   * Destructor for SedDataSource.
   */
  virtual ~SedDataSource();


  /**
   * Returns the value of the "id" attribute of this SedDataSource.
   *
   * @return the value of the "id" attribute of this SedDataSource as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedDataSource's "id" attribute has been set.
   *
   * @return @c true if this SedDataSource's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this SedDataSource.
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
   * Unsets the value of the "id" attribute of this SedDataSource.
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
   * Returns the value of the "name" attribute of this SedDataSource.
   *
   * @return the value of the "name" attribute of this SedDataSource as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedDataSource's "name" attribute has been set.
   *
   * @return @c true if this SedDataSource's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Sets the value of the "name" attribute of this SedDataSource.
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
   * Unsets the value of the "name" attribute of this SedDataSource.
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
   * Returns the value of the "indexSet" attribute of this SedDataSource.
   *
   * @return the value of the "indexSet" attribute of this SedDataSource as a string.
   */
  virtual const std::string& getIndexSet() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedDataSource's "indexSet" attribute has been set.
   *
   * @return @c true if this SedDataSource's "indexSet" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetIndexSet() const;


  /**
   * Sets the value of the "indexSet" attribute of this SedDataSource.
   *
   * @param indexSet; const std::string& value of the "indexSet" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setIndexSet(const std::string& indexSet);


  /**
   * Unsets the value of the "indexSet" attribute of this SedDataSource.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_OPERATION_FAILED
   */
  virtual int unsetIndexSet();


  /**
   * Returns the  "SedListOfSlices" in this SedDataSource object.
   *
   * @return the "SedListOfSlices" attribute of this SedDataSource.
   */
  const SedListOfSlices* getListOfSlices() const;


  /**
   * Get a Slice from the SedListOfSlices.
   *
   * @param n the index number of the Slice to get.
   *
   * @return the nth Slice in the SedListOfSlices within this SedDataSource.
   *
   * @see getNumSlices()
   */
  SedSlice* getSlice(unsigned int n);


  /**
   * Get a Slice from the SedListOfSlices.
   *
   * @param n the index number of the Slice to get.
   *
   * @return the nth Slice in the SedListOfSlices within this SedDataSource.
   *
   * @see getNumSlices()
   */
  const SedSlice* getSlice(unsigned int n) const;


  /**
   * Get a Slice from the SedListOfSlices
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the Slice to get.
   *
   * @return the Slice in the SedListOfSlices
   * with the given id or NULL if no such
   * Slice exists.
   *
   * @see getSlice(unsigned int n)
   *
   * @see getNumSlices()
   */
  SedSlice* getSlice(const std::string& sid);


  /**
   * Get a Slice from the SedListOfSlices
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the Slice to get.
   *
   * @return the Slice in the SedListOfSlices
   * with the given id or NULL if no such
   * Slice exists.
   *
   * @see getSlice(unsigned int n)
   *
   * @see getNumSlices()
   */
  const SedSlice* getSlice(const std::string& sid) const;


  /**
   * Adds a copy the given "SedSlice" to this SedDataSource.
   *
   * @param ss; the SedSlice object to add
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  int addSlice(const SedSlice* ss);


  /**
   * Get the number of SedSlice objects in this SedDataSource.
   *
   * @return the number of SedSlice objects in this SedDataSource
   */
  unsigned int getNumSlices() const;


  /**
   * Creates a new SedSlice object, adds it to this SedDataSources
   * SedListOfSlices and returns the SedSlice object created.
   *
   * @return a new SedSlice object instance
   *
   * @see addSlice(const SedSlice* ss)
   */
  SedSlice* createSlice();


  /**
   * Removes the nth Slice from the SedListOfSlices within this SedDataSource.
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the Slice to remove.
   *
   * @see getNumSlices()
   */
  SedSlice* removeSlice(unsigned int n);


  /**
   * Removes the Slice with the given identifier from the SedListOfSlices within this SedDataSource
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
  SedSlice* removeSlice(const std::string& sid);


  /**
   * Returns the XML element name of this object, which for SedDataSource, is
   * always @c "sedDataSource".
   *
   * @return the name of this element, i.e. @c "sedDataSource".
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
   * for this SedDataSource object have been set.
   *
   * @note The required attributes for a SedDataSource object are:
   *
   * @return a boolean value indicating whether all the required
   * attributes for this object have been defined.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements
   * for this SedDataSource object have been set.
   *
   * @note The required elements for a SedDataSource object are:
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

class LIBSEDML_EXTERN SedListOfDataSources : public SedListOf
{

public:

  /**
   * Creates a new SedListOfDataSources with the given level, version, and package version.
   *
   * @param level an unsigned int, the SEDML Level to assign to this SedListOfDataSources
   *
   * @param version an unsigned int, the SEDML Version to assign to this SedListOfDataSources
   *
   * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedListOfDataSources
   */
  SedListOfDataSources(unsigned int level      = SEDML_DEFAULT_LEVEL,
                       unsigned int version    = SEDML_DEFAULT_VERSION
                      );


  /**
   * Creates a new SedListOfDataSources with the given SedNamespaces object.
   *
   * @param sedns the SedNamespaces object
   */
  SedListOfDataSources(SedNamespaces* sedns);


  /**
   * Creates and returns a deep copy of this SedListOfDataSources object.
   *
   * @return a (deep) copy of this SedListOfDataSources object.
   */
  virtual SedListOfDataSources* clone() const;


  /**
   * Get a DataSource from the SedListOfDataSources.
   *
   * @param n the index number of the DataSource to get.
   *
   * @return the nth DataSource in this SedListOfDataSources.
   *
   * @see size()
   */
  virtual SedDataSource* get(unsigned int n);


  /**
   * Get a DataSource from the SedListOfDataSources.
   *
   * @param n the index number of the DataSource to get.
   *
   * @return the nth DataSource in this SedListOfDataSources.
   *
   * @see size()
   */
  virtual const SedDataSource* get(unsigned int n) const;


  /**
   * Get a DataSource from the SedListOfDataSources
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the DataSource to get.
   *
   * @return DataSource in this SedListOfDataSources
   * with the given id or NULL if no such
   * DataSource exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual SedDataSource* get(const std::string& sid);


  /**
   * Get a DataSource from the SedListOfDataSources
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the DataSource to get.
   *
   * @return DataSource in this SedListOfDataSources
   * with the given id or NULL if no such
   * DataSource exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual const SedDataSource* get(const std::string& sid) const;


  /**
   * Adds a copy the given "DataSource" to this SedListOfDataSources.
   *
   * @param ds; the DataSource object to add
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  int addDataSource(const SedDataSource* ds);


  /**
   * Get the number of DataSource objects in this SedListOfDataSources.
   *
   * @return the number of DataSource objects in this SedListOfDataSources
   */
  unsigned int getNumDataSources() const;


  /**
   * Creates a new DataSource object, adds it to the
   * SedListOfDataSources and returns the DataSource object created.
   *
   * @return a new DataSource object instance
   *
   * @see addDataSource(const SedDataSource* ds)
   */
  SedDataSource* createDataSource();


  /**
   * Removes the nth DataSource from this SedListOfDataSources
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the DataSource to remove.
   *
   * @see size()
   */
  virtual SedDataSource* remove(unsigned int n);


  /**
   * Removes the DataSource from this SedListOfDataSources with the given identifier
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   * If none of the items in this list have the identifier @p sid, then
   * @c NULL is returned.
   *
   * @param sid the identifier of the DataSource to remove.
   *
   * @return the DataSource removed. As mentioned above, the caller owns the
   * returned item.
   */
  virtual SedDataSource* remove(const std::string& sid);


  /**
   * Returns the XML element name of this object, which for SedListOfDataSources, is
   * always @c "sedListOfDataSources".
   *
   * @return the name of this element, i.e. @c "sedListOfDataSources".
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
   * Creates a new DataSource in this SedListOfDataSources
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
SedDataSource_t *
SedDataSource_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedDataSource_free(SedDataSource_t * sds);


LIBSEDML_EXTERN
SedDataSource_t *
SedDataSource_clone(SedDataSource_t * sds);


LIBSEDML_EXTERN
char *
SedDataSource_getId(SedDataSource_t * sds);


LIBSEDML_EXTERN
char *
SedDataSource_getName(SedDataSource_t * sds);


LIBSEDML_EXTERN
char *
SedDataSource_getIndexSet(SedDataSource_t * sds);


LIBSEDML_EXTERN
int
SedDataSource_isSetId(SedDataSource_t * sds);


LIBSEDML_EXTERN
int
SedDataSource_isSetName(SedDataSource_t * sds);


LIBSEDML_EXTERN
int
SedDataSource_isSetIndexSet(SedDataSource_t * sds);


LIBSEDML_EXTERN
int
SedDataSource_setId(SedDataSource_t * sds, const char * id);


LIBSEDML_EXTERN
int
SedDataSource_setName(SedDataSource_t * sds, const char * name);


LIBSEDML_EXTERN
int
SedDataSource_setIndexSet(SedDataSource_t * sds, const char * indexSet);


LIBSEDML_EXTERN
int
SedDataSource_unsetId(SedDataSource_t * sds);


LIBSEDML_EXTERN
int
SedDataSource_unsetName(SedDataSource_t * sds);


LIBSEDML_EXTERN
int
SedDataSource_unsetIndexSet(SedDataSource_t * sds);


LIBSEDML_EXTERN
int
SedDataSource_addSlice(SedDataSource_t * sds, SedSlice_t * ss);


LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_createSlice(SedDataSource_t * sds);


LIBSEDML_EXTERN
SedListOf_t *
SedDataSource_getSedListOfSlices(SedDataSource_t * sds);


LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_getSlice(SedDataSource_t * sds, unsigned int n);


LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_getSliceById(SedDataSource_t * sds, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedDataSource_getNumSlices(SedDataSource_t * sds);


LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_removeSlice(SedDataSource_t * sds, unsigned int n);


LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_removeSliceById(SedDataSource_t * sds, const char * sid);


LIBSEDML_EXTERN
int
SedDataSource_hasRequiredAttributes(SedDataSource_t * sds);


LIBSEDML_EXTERN
int
SedDataSource_hasRequiredElements(SedDataSource_t * sds);


LIBSEDML_EXTERN
SedDataSource_t *
SedListOfDataSources_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedDataSource_t *
SedListOfDataSources_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedDataSource_H__  */

