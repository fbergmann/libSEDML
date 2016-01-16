/**
 * @file:   SedDataDescription.h
 * @brief:  Implementation of the SedDataDescription class
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


#ifndef SedDataDescription_H__
#define SedDataDescription_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedNamespaces.h>
#include <numl/DimensionDescription.h>
#include <sedml/SedDataSource.h>




LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDataDescription : public SedBase
{

protected:

  std::string   mId;
  std::string   mName;
  std::string   mSource;
  DimensionDescription*   mDimensionDescription;
  SedListOfDataSources   mDataSources;


public:

  /**
   * Creates a new SedDataDescription with the given level, version, and package version.
   *
   * @param level an unsigned int, the SEDML Level to assign to this SedDataDescription
   *
   * @param version an unsigned int, the SEDML Version to assign to this SedDataDescription
   *
   * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedDataDescription
   */
  SedDataDescription(unsigned int level      = SEDML_DEFAULT_LEVEL,
                     unsigned int version    = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDataDescription with the given SedNamespaces object.
   *
   * @param sedns the SedNamespaces object
   */
  SedDataDescription(SedNamespaces* sedns);


  /**
   * Copy constructor for SedDataDescription.
   *
   * @param orig; the SedDataDescription instance to copy.
   */
  SedDataDescription(const SedDataDescription& orig);


  /**
   * Assignment operator for SedDataDescription.
   *
   * @param rhs; the object whose values are used as the basis
   * of the assignment
   */
  SedDataDescription& operator=(const SedDataDescription& rhs);


  /**
   * Creates and returns a deep copy of this SedDataDescription object.
   *
   * @return a (deep) copy of this SedDataDescription object.
   */
  virtual SedDataDescription* clone() const;


  /**
   * Destructor for SedDataDescription.
   */
  virtual ~SedDataDescription();


  /**
   * Returns the value of the "id" attribute of this SedDataDescription.
   *
   * @return the value of the "id" attribute of this SedDataDescription as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedDataDescription's "id" attribute has been set.
   *
   * @return @c true if this SedDataDescription's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this SedDataDescription.
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
   * Unsets the value of the "id" attribute of this SedDataDescription.
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
   * Returns the value of the "name" attribute of this SedDataDescription.
   *
   * @return the value of the "name" attribute of this SedDataDescription as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedDataDescription's "name" attribute has been set.
   *
   * @return @c true if this SedDataDescription's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Sets the value of the "name" attribute of this SedDataDescription.
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
   * Unsets the value of the "name" attribute of this SedDataDescription.
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
   * Returns the value of the "source" attribute of this SedDataDescription.
   *
   * @return the value of the "source" attribute of this SedDataDescription as a string.
   */
  virtual const std::string& getSource() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedDataDescription's "source" attribute has been set.
   *
   * @return @c true if this SedDataDescription's "source" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetSource() const;


  /**
   * Sets the value of the "source" attribute of this SedDataDescription.
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
   * Unsets the value of the "source" attribute of this SedDataDescription.
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
   * Returns the value of the "dimensionDescription" attribute of this SedDataDescription.
   *
   * @return the value of the "dimensionDescription" attribute of this SedDataDescription as a DimensionDescription*.
   */
  virtual const DimensionDescription* getDimensionDescription() const;


  /**
   * Creates a new "DimensionDescription*" and sets it for this SedDataDescription.
   *
   * @return the created "DimensionDescription*" element of this SedDataDescription.
   */
  virtual DimensionDescription* createDimensionDescription();


  /**
   * Predicate returning @c true or @c false depending on whether this
   * SedDataDescription's "dimensionDescription" attribute has been set.
   *
   * @return @c true if this SedDataDescription's "dimensionDescription" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetDimensionDescription() const;


  /**
   * Sets the value of the "dimensionDescription" attribute of this SedDataDescription.
   *
   * @param dimensionDescription; DimensionDescription* value of the "dimensionDescription" attribute to be set
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  virtual int setDimensionDescription(DimensionDescription* dimensionDescription);


  /**
   * Unsets the value of the "dimensionDescription" attribute of this SedDataDescription.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_OPERATION_FAILED
   */
  virtual int unsetDimensionDescription();


  /**
   * Returns the  "SedListOfDataSources" in this SedDataDescription object.
   *
   * @return the "SedListOfDataSources" attribute of this SedDataDescription.
   */
  const SedListOfDataSources* getListOfDataSources() const;


  /**
   * Get a DataSource from the SedListOfDataSources.
   *
   * @param n the index number of the DataSource to get.
   *
   * @return the nth DataSource in the SedListOfDataSources within this SedDataDescription.
   *
   * @see getNumDataSources()
   */
  SedDataSource* getDataSource(unsigned int n);


  /**
   * Get a DataSource from the SedListOfDataSources.
   *
   * @param n the index number of the DataSource to get.
   *
   * @return the nth DataSource in the SedListOfDataSources within this SedDataDescription.
   *
   * @see getNumDataSources()
   */
  const SedDataSource* getDataSource(unsigned int n) const;


  /**
   * Get a DataSource from the SedListOfDataSources
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the DataSource to get.
   *
   * @return the DataSource in the SedListOfDataSources
   * with the given id or NULL if no such
   * DataSource exists.
   *
   * @see getDataSource(unsigned int n)
   *
   * @see getNumDataSources()
   */
  SedDataSource* getDataSource(const std::string& sid);


  /**
   * Get a DataSource from the SedListOfDataSources
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the DataSource to get.
   *
   * @return the DataSource in the SedListOfDataSources
   * with the given id or NULL if no such
   * DataSource exists.
   *
   * @see getDataSource(unsigned int n)
   *
   * @see getNumDataSources()
   */
  const SedDataSource* getDataSource(const std::string& sid) const;


  /**
   * Adds a copy the given "SedDataSource" to this SedDataDescription.
   *
   * @param sds; the SedDataSource object to add
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  int addDataSource(const SedDataSource* sds);


  /**
   * Get the number of SedDataSource objects in this SedDataDescription.
   *
   * @return the number of SedDataSource objects in this SedDataDescription
   */
  unsigned int getNumDataSources() const;


  /**
   * Creates a new SedDataSource object, adds it to this SedDataDescriptions
   * SedListOfDataSources and returns the SedDataSource object created.
   *
   * @return a new SedDataSource object instance
   *
   * @see addDataSource(const SedDataSource* sds)
   */
  SedDataSource* createDataSource();


  /**
   * Removes the nth DataSource from the SedListOfDataSources within this SedDataDescription.
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the DataSource to remove.
   *
   * @see getNumDataSources()
   */
  SedDataSource* removeDataSource(unsigned int n);


  /**
   * Removes the DataSource with the given identifier from the SedListOfDataSources within this SedDataDescription
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
  SedDataSource* removeDataSource(const std::string& sid);


  /**
   * Returns the XML element name of this object, which for SedDataDescription, is
   * always @c "sedDataDescription".
   *
   * @return the name of this element, i.e. @c "sedDataDescription".
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
   * for this SedDataDescription object have been set.
   *
   * @note The required attributes for a SedDataDescription object are:
   * @li "id"
   * @li "dimensionDescription"
   *
   * @return a boolean value indicating whether all the required
   * attributes for this object have been defined.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements
   * for this SedDataDescription object have been set.
   *
   * @note The required elements for a SedDataDescription object are:
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
   * Subclasses should override this method ro read other XML.
   *
   * return true if read from stream, false otherwise.
   */
  virtual bool readOtherXML(XMLInputStream& stream);


  /** @endcond doxygen-libsedml-internal */


  /** @cond doxygen-libsedml-internal */

  /**
   * Write values of XMLAttributes to the output stream.
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;


  /** @endcond doxygen-libsedml-internal */



};

class LIBSEDML_EXTERN SedListOfDataDescriptions : public SedListOf
{

public:

  /**
   * Creates a new SedListOfDataDescriptions with the given level, version, and package version.
   *
   * @param level an unsigned int, the SEDML Level to assign to this SedListOfDataDescriptions
   *
   * @param version an unsigned int, the SEDML Version to assign to this SedListOfDataDescriptions
   *
   * @param pkgVersion an unsigned int, the SEDML Sed Version to assign to this SedListOfDataDescriptions
   */
  SedListOfDataDescriptions(unsigned int level      = SEDML_DEFAULT_LEVEL,
                            unsigned int version    = SEDML_DEFAULT_VERSION
                           );


  /**
   * Creates a new SedListOfDataDescriptions with the given SedNamespaces object.
   *
   * @param sedns the SedNamespaces object
   */
  SedListOfDataDescriptions(SedNamespaces* sedns);


  /**
   * Creates and returns a deep copy of this SedListOfDataDescriptions object.
   *
   * @return a (deep) copy of this SedListOfDataDescriptions object.
   */
  virtual SedListOfDataDescriptions* clone() const;


  /**
   * Get a DataDescription from the SedListOfDataDescriptions.
   *
   * @param n the index number of the DataDescription to get.
   *
   * @return the nth DataDescription in this SedListOfDataDescriptions.
   *
   * @see size()
   */
  virtual SedDataDescription* get(unsigned int n);


  /**
   * Get a DataDescription from the SedListOfDataDescriptions.
   *
   * @param n the index number of the DataDescription to get.
   *
   * @return the nth DataDescription in this SedListOfDataDescriptions.
   *
   * @see size()
   */
  virtual const SedDataDescription* get(unsigned int n) const;


  /**
   * Get a DataDescription from the SedListOfDataDescriptions
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the DataDescription to get.
   *
   * @return DataDescription in this SedListOfDataDescriptions
   * with the given id or NULL if no such
   * DataDescription exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual SedDataDescription* get(const std::string& sid);


  /**
   * Get a DataDescription from the SedListOfDataDescriptions
   * based on its identifier.
   *
   * @param sid a string representing the identifier
   * of the DataDescription to get.
   *
   * @return DataDescription in this SedListOfDataDescriptions
   * with the given id or NULL if no such
   * DataDescription exists.
   *
   * @see get(unsigned int n)   *
   * @see size()
   */
  virtual const SedDataDescription* get(const std::string& sid) const;


  /**
   * Adds a copy the given "DataDescription" to this SedListOfDataDescriptions.
   *
   * @param dd; the DataDescription object to add
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif The possible values
   * returned by this function are:
   * @li LIBSEDML_OPERATION_SUCCESS
   * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
   */
  int addDataDescription(const SedDataDescription* dd);


  /**
   * Get the number of DataDescription objects in this SedListOfDataDescriptions.
   *
   * @return the number of DataDescription objects in this SedListOfDataDescriptions
   */
  unsigned int getNumDataDescriptions() const;


  /**
   * Creates a new DataDescription object, adds it to the
   * SedListOfDataDescriptions and returns the DataDescription object created.
   *
   * @return a new DataDescription object instance
   *
   * @see addDataDescription(const SedDataDescription* dd)
   */
  SedDataDescription* createDataDescription();


  /**
   * Removes the nth DataDescription from this SedListOfDataDescriptions
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the DataDescription to remove.
   *
   * @see size()
   */
  virtual SedDataDescription* remove(unsigned int n);


  /**
   * Removes the DataDescription from this SedListOfDataDescriptions with the given identifier
   * and returns a pointer to it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   * If none of the items in this list have the identifier @p sid, then
   * @c NULL is returned.
   *
   * @param sid the identifier of the DataDescription to remove.
   *
   * @return the DataDescription removed. As mentioned above, the caller owns the
   * returned item.
   */
  virtual SedDataDescription* remove(const std::string& sid);


  /**
   * Returns the XML element name of this object, which for SedListOfDataDescriptions, is
   * always @c "sedListOfDataDescriptions".
   *
   * @return the name of this element, i.e. @c "sedListOfDataDescriptions".
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
   * Creates a new DataDescription in this SedListOfDataDescriptions
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
SedDataDescription_t *
SedDataDescription_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedDataDescription_free(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
SedDataDescription_t *
SedDataDescription_clone(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
char *
SedDataDescription_getId(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
char *
SedDataDescription_getName(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
char *
SedDataDescription_getSource(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
DimensionDescription*
SedDataDescription_getDimensionDescription(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_isSetId(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_isSetName(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_isSetSource(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_isSetDimensionDescription(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_setId(SedDataDescription_t * sdd, const char * id);


LIBSEDML_EXTERN
int
SedDataDescription_setName(SedDataDescription_t * sdd, const char * name);


LIBSEDML_EXTERN
int
SedDataDescription_setSource(SedDataDescription_t * sdd, const char * source);


LIBSEDML_EXTERN
int
SedDataDescription_setDimensionDescription(SedDataDescription_t * sdd, DimensionDescription* dimensionDescription);


LIBSEDML_EXTERN
int
SedDataDescription_unsetId(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_unsetName(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_unsetSource(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_unsetDimensionDescription(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_addDataSource(SedDataDescription_t * sdd, SedDataSource_t * sds);


LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_createDataSource(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
SedListOf_t *
SedDataDescription_getSedListOfDataSources(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_getDataSource(SedDataDescription_t * sdd, unsigned int n);


LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_getDataSourceById(SedDataDescription_t * sdd, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedDataDescription_getNumDataSources(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_removeDataSource(SedDataDescription_t * sdd, unsigned int n);


LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_removeDataSourceById(SedDataDescription_t * sdd, const char * sid);


LIBSEDML_EXTERN
int
SedDataDescription_hasRequiredAttributes(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
int
SedDataDescription_hasRequiredElements(SedDataDescription_t * sdd);


LIBSEDML_EXTERN
SedDataDescription_t *
SedListOfDataDescriptions_getById(SedListOf_t * lo, const char * sid);


LIBSEDML_EXTERN
SedDataDescription_t *
SedListOfDataDescriptions_removeById(SedListOf_t * lo, const char * sid);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedDataDescription_H__  */

