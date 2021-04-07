/**
 * @file SedDataDescription.h
 * @brief Definition of the SedDataDescription class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedDataDescription
 * @sbmlbrief{sedml} TODO:Definition of the SedDataDescription class.
 */


#ifndef SedDataDescription_H__
#define SedDataDescription_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <numl/DimensionDescription.h>
#include <sedml/SedListOfDataSources.h>
#include <sbml/common/libsbml-namespace.h>
#include <numl/common/libnuml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDataDescription : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mFormat;
  std::string mSource;
  LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription* mDimensionDescription;
  SedListOfDataSources mDataSources;

  /** @endcond */

public:

  /**
   * Creates a new SedDataDescription using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedDataDescription.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedDataDescription.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDataDescription(unsigned int level = SEDML_DEFAULT_LEVEL,
                     unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDataDescription using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDataDescription(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedDataDescription.
   *
   * @param orig the SedDataDescription instance to copy.
   */
  SedDataDescription(const SedDataDescription& orig);


  /**
   * Assignment operator for SedDataDescription.
   *
   * @param rhs the SedDataDescription object whose values are to be used as
   * the basis of the assignment.
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
   * Returns the value of the "format" attribute of this SedDataDescription.
   *
   * @return the value of the "format" attribute of this SedDataDescription as
   * a string.
   */
  const std::string& getFormat() const;


  /**
   * Returns the value of the "source" attribute of this SedDataDescription.
   *
   * @return the value of the "source" attribute of this SedDataDescription as
   * a string.
   */
  const std::string& getSource() const;


  /**
   * Predicate returning @c true if this SedDataDescription's "format"
   * attribute is set.
   *
   * @return @c true if this SedDataDescription's "format" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetFormat() const;


  /**
   * Predicate returning @c true if this SedDataDescription's "source"
   * attribute is set.
   *
   * @return @c true if this SedDataDescription's "source" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetSource() const;


  /**
   * Sets the value of the "format" attribute of this SedDataDescription.
   *
   * @param format std::string& value of the "format" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p format = @c NULL or an empty string is
   * equivalent to calling unsetFormat().
   */
  int setFormat(const std::string& format);


  /**
   * Sets the value of the "source" attribute of this SedDataDescription.
   *
   * @param source std::string& value of the "source" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p source = @c NULL or an empty string is
   * equivalent to calling unsetSource().
   */
  int setSource(const std::string& source);


  /**
   * Unsets the value of the "format" attribute of this SedDataDescription.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFormat();


  /**
   * Unsets the value of the "source" attribute of this SedDataDescription.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSource();


  /**
   * Returns the value of the "dimensionDescription" element of this
   * SedDataDescription.
   *
   * @return the value of the "dimensionDescription" element of this
   * SedDataDescription as a LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription*.
   */
  const LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription* getDimensionDescription() const;


  /**
   * Returns the value of the "dimensionDescription" element of this
   * SedDataDescription.
   *
   * @return the value of the "dimensionDescription" element of this
   * SedDataDescription as a LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription*.
   */
  LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription* getDimensionDescription();


  /**
   * Predicate returning @c true if this SedDataDescription's
   * "dimensionDescription" element is set.
   *
   * @return @c true if this SedDataDescription's "dimensionDescription"
   * element has been set, otherwise @c false is returned.
   */
  bool isSetDimensionDescription() const;


  /**
   * Sets the value of the "dimensionDescription" element of this
   * SedDataDescription.
   *
   * @param dimensionDescription LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription* value of the
   * "dimensionDescription" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDimensionDescription(const LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription*
    dimensionDescription);


  /**
   * Creates a new DimensionDescription object, adds it to this
   * SedDataDescription object and returns the DimensionDescription object
   * created.
   *
   * @return a new DimensionDescription object instance.
   */
  LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription* createDimensionDescription();


  /**
   * Unsets the value of the "dimensionDescription" element of this
   * SedDataDescription.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDimensionDescription();


  /**
   * Returns the SedListOfDataSources from this SedDataDescription.
   *
   * @return the SedListOfDataSources from this SedDataDescription.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getDataSource(const std::string& sid)
   * @see getDataSource(unsigned int n)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  const SedListOfDataSources* getListOfDataSources() const;


  /**
   * Returns the SedListOfDataSources from this SedDataDescription.
   *
   * @return the SedListOfDataSources from this SedDataDescription.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getDataSource(const std::string& sid)
   * @see getDataSource(unsigned int n)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  SedListOfDataSources* getListOfDataSources();


  /**
   * Get a SedDataSource from the SedDataDescription.
   *
   * @param n an unsigned int representing the index of the SedDataSource to
   * retrieve.
   *
   * @return the nth SedDataSource in the SedListOfDataSources within this
   * SedDataDescription.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getDataSource(const std::string& sid)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  SedDataSource* getDataSource(unsigned int n);


  /**
   * Get a SedDataSource from the SedDataDescription.
   *
   * @param n an unsigned int representing the index of the SedDataSource to
   * retrieve.
   *
   * @return the nth SedDataSource in the SedListOfDataSources within this
   * SedDataDescription.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getDataSource(const std::string& sid)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  const SedDataSource* getDataSource(unsigned int n) const;


  /**
   * Get a SedDataSource from the SedDataDescription based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataSource to
   * retrieve.
   *
   * @return the SedDataSource in the SedListOfDataSources within this
   * SedDataDescription with the given @p sid or @c NULL if no such
   * SedDataSource exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getDataSource(unsigned int n)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  SedDataSource* getDataSource(const std::string& sid);


  /**
   * Get a SedDataSource from the SedDataDescription based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataSource to
   * retrieve.
   *
   * @return the SedDataSource in the SedListOfDataSources within this
   * SedDataDescription with the given @p sid or @c NULL if no such
   * SedDataSource exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getDataSource(unsigned int n)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  const SedDataSource* getDataSource(const std::string& sid) const;


  /**
   * Get a SedDataSource from the SedDataDescription based on the IndexSet to
   * which it refers.
   *
   * @param sid a string representing the "indexSet" attribute of the
   * SedDataSource object to retrieve.
   *
   * @return the first SedDataSource in this SedDataDescription based on the
   * given indexSet attribute or NULL if no such SedDataSource exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedDataSource* getDataSourceByIndexSet(const std::string& sid) const;


  /**
   * Get a SedDataSource from the SedDataDescription based on the IndexSet to
   * which it refers.
   *
   * @param sid a string representing the "indexSet" attribute of the
   * SedDataSource object to retrieve.
   *
   * @return the first SedDataSource in this SedDataDescription based on the
   * given indexSet attribute or NULL if no such SedDataSource exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedDataSource* getDataSourceByIndexSet(const std::string& sid);


  /**
   * Adds a copy of the given SedDataSource to this SedDataDescription.
   *
   * @param sds the SedDataSource object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createDataSource()
   * @see getDataSource(const std::string& sid)
   * @see getDataSource(unsigned int n)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  int addDataSource(const SedDataSource* sds);


  /**
   * Get the number of SedDataSource objects in this SedDataDescription.
   *
   * @return the number of SedDataSource objects in this SedDataDescription.
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getDataSource(const std::string& sid)
   * @see getDataSource(unsigned int n)
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  unsigned int getNumDataSources() const;


  /**
   * Creates a new SedDataSource object, adds it to this SedDataDescription
   * object and returns the SedDataSource object created.
   *
   * @return a new SedDataSource object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see getDataSource(const std::string& sid)
   * @see getDataSource(unsigned int n)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   * @see removeDataSource(unsigned int n)
   */
  SedDataSource* createDataSource();


  /**
   * Removes the nth SedDataSource from this SedDataDescription and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedDataSource to
   * remove.
   *
   * @return a pointer to the nth SedDataSource in this SedDataDescription.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getDataSource(const std::string& sid)
   * @see getDataSource(unsigned int n)
   * @see getNumDataSources()
   * @see removeDataSource(const std::string& sid)
   */
  SedDataSource* removeDataSource(unsigned int n);


  /**
   * Removes the SedDataSource from this SedDataDescription based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedDataSource to
   * remove.
   *
   * @return the SedDataSource in this SedDataDescription based on the
   * identifier or NULL if no such SedDataSource exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addSedDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see getSedDataSource(const std::string& sid)
   * @see getSedDataSource(unsigned int n)
   * @see getNumDataSources()
   * @see removeSedDataSource(unsigned int n)
   */
  SedDataSource* removeDataSource(const std::string& sid);


  /**
   * Returns the XML element name of this SedDataDescription object.
   *
   * For SedDataDescription, the XML element name is always
   * @c "dataDescription".
   *
   * @return the name of this element, i.e. @c "dataDescription".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedDataDescription object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_DATA_DESCRIPTION, SedmlmlTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedDataDescription object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedDataDescription have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedDataDescription object are:
   * @li "id"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Accepts the given SedVisitor
   */
  virtual bool accept(SedVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the parent SedDocument
   */
  virtual void setSedDocument(SedDocument* d);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Predicate returning @c true if this SedDataDescription's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedDataDescription's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this
   * SedDataDescription.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates and returns an new "elementName" object in this
   * SedDataDescription.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedDataDescription.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SedBase* element);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * SedDataDescription.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SedBase* removeChildObject(const std::string& elementName,
                                     const std::string& id);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the number of "elementName" in this SedDataDescription.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedDataDescription.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SedBase* getObject(const std::string& elementName,
                             unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SedBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SedBase* getElementBySId(const std::string& id);


  /**
   * Returns a List of all child SedBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List pointer of pointers to all SedBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(SedElementFilter * filter = NULL);


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */


  /** @cond doxygen-libsedml-internal */

  /**
   * Subclasses should override this method ro read other XML.
   *
   * return true if read from stream, false otherwise.
   */
  virtual bool readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream);


  /** @endcond doxygen-libsedml-internal */

  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedDataDescription_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedDataDescription_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedDataDescription_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedDataDescription_t *
SedDataDescription_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedDataDescription_t object.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @return a (deep) copy of this SedDataDescription_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDataDescription_clone(const SedDataDescription_t* sdd);


/**
 * Frees this SedDataDescription_t object.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
void
SedDataDescription_free(SedDataDescription_t* sdd);


/**
 * Returns the value of the "id" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedDataDescription_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getId(const SedDataDescription_t * sdd);


/**
 * Returns the value of the "name" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedDataDescription_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getName(const SedDataDescription_t * sdd);


/**
 * Returns the value of the "format" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure whose format is sought.
 *
 * @return the value of the "format" attribute of this SedDataDescription_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getFormat(const SedDataDescription_t * sdd);


/**
 * Returns the value of the "source" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure whose source is sought.
 *
 * @return the value of the "source" attribute of this SedDataDescription_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getSource(const SedDataDescription_t * sdd);


/**
 * Predicate returning @c 1 (true) if this SedDataDescription_t's "id"
 * attribute is set.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @return @c 1 (true) if this SedDataDescription_t's "id" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetId(const SedDataDescription_t * sdd);


/**
 * Predicate returning @c 1 (true) if this SedDataDescription_t's "name"
 * attribute is set.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @return @c 1 (true) if this SedDataDescription_t's "name" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetName(const SedDataDescription_t * sdd);


/**
 * Predicate returning @c 1 (true) if this SedDataDescription_t's "format"
 * attribute is set.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @return @c 1 (true) if this SedDataDescription_t's "format" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetFormat(const SedDataDescription_t * sdd);


/**
 * Predicate returning @c 1 (true) if this SedDataDescription_t's "source"
 * attribute is set.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @return @c 1 (true) if this SedDataDescription_t's "source" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetSource(const SedDataDescription_t * sdd);


/**
 * Sets the value of the "id" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling SedDataDescription_unsetId().
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_setId(SedDataDescription_t * sdd, const char * id);


/**
 * Sets the value of the "name" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedDataDescription_unsetName().
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_setName(SedDataDescription_t * sdd, const char * name);


/**
 * Sets the value of the "format" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @param format const char * value of the "format" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p format = @c NULL or an empty string is
 * equivalent to calling SedDataDescription_unsetFormat().
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_setFormat(SedDataDescription_t * sdd, const char * format);


/**
 * Sets the value of the "source" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @param source const char * value of the "source" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p source = @c NULL or an empty string is
 * equivalent to calling SedDataDescription_unsetSource().
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_setSource(SedDataDescription_t * sdd, const char * source);


/**
 * Unsets the value of the "id" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetId(SedDataDescription_t * sdd);


/**
 * Unsets the value of the "name" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetName(SedDataDescription_t * sdd);


/**
 * Unsets the value of the "format" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetFormat(SedDataDescription_t * sdd);


/**
 * Unsets the value of the "source" attribute of this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetSource(SedDataDescription_t * sdd);


/**
 * Returns the value of the "dimensionDescription" element of this
 * SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure whose dimensionDescription is
 * sought.
 *
 * @return the value of the "dimensionDescription" element of this
 * SedDataDescription_t as a LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription*.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
const LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription_t*
SedDataDescription_getDimensionDescription(const SedDataDescription_t * sdd);


/**
 * Predicate returning @c 1 (true) if this SedDataDescription_t's
 * "dimensionDescription" element is set.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @return @c 1 (true) if this SedDataDescription_t's "dimensionDescription"
 * element has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetDimensionDescription(const SedDataDescription_t * sdd);


/**
 * Sets the value of the "dimensionDescription" element of this
 * SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @param dimensionDescription DimensionDescription_t* value of the
 * "dimensionDescription" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_setDimensionDescription(SedDataDescription_t * sdd,
                                           const LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription_t*
                                             dimensionDescription);


/**
 * Creates a new DimensionDescription_t object, adds it to this
 * SedDataDescription_t object and returns the DimensionDescription_t object
 * created.
 *
 * @param sdd the SedDataDescription_t structure to which the
 * DimensionDescription_t should be added.
 *
 * @return a new DimensionDescription_t object instance.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription_t*
SedDataDescription_createDimensionDescription(SedDataDescription_t* sdd);


/**
 * Unsets the value of the "dimensionDescription" element of this
 * SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetDimensionDescription(SedDataDescription_t * sdd);


/**
 * Returns a ListOf_t * containing SedDataSource_t objects from this
 * SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure whose SedListOfDataSources is
 * sought.
 *
 * @return the SedListOfDataSources from this SedDataDescription_t as a
 * ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDataDescription_addDataSource()
 * @see SedDataDescription_createDataSource()
 * @see SedDataDescription_getDataSourceById()
 * @see SedDataDescription_getDataSource()
 * @see SedDataDescription_getNumDataSources()
 * @see SedDataDescription_removeDataSourceById()
 * @see SedDataDescription_removeDataSource()
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataDescription_getListOfDataSources(SedDataDescription_t* sdd);


/**
 * Get a SedDataSource_t from the SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataSource_t to
 * retrieve.
 *
 * @return the nth SedDataSource_t in the SedListOfDataSources within this
 * SedDataDescription.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_getDataSource(SedDataDescription_t* sdd, unsigned int n);


/**
 * Get a SedDataSource_t from the SedDataDescription_t based on its identifier.
 *
 * @param sdd the SedDataDescription_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataSource_t to
 * retrieve.
 *
 * @return the SedDataSource_t in the SedListOfDataSources within this
 * SedDataDescription with the given @p sid or @c NULL if no such
 * SedDataSource_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_getDataSourceById(SedDataDescription_t* sdd,
                                     const char *sid);


/**
 * Get a SedDataSource_t from the SedDataDescription_t based on the IndexSet to
 * which it refers.
 *
 * @param sdd the SedDataDescription_t structure to search.
 *
 * @param sid a string representing the "indexSet" attribute of the
 * SedDataSource_t object to retrieve.
 *
 * @return the first SedDataSource_t in this SedDataDescription_t based on the
 * given indexSet attribute or NULL if no such SedDataSource_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_getDataSourceByIndexSet(SedDataDescription_t* sdd,
                                           const char *sid);


/**
 * Adds a copy of the given SedDataSource_t to this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure to which the SedDataSource_t
 * should be added.
 *
 * @param sds the SedDataSource_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_addDataSource(SedDataDescription_t* sdd,
                                 const SedDataSource_t* sds);


/**
 * Get the number of SedDataSource_t objects in this SedDataDescription_t.
 *
 * @param sdd the SedDataDescription_t structure to query.
 *
 * @return the number of SedDataSource_t objects in this SedDataDescription_t.
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
unsigned int
SedDataDescription_getNumDataSources(SedDataDescription_t* sdd);


/**
 * Creates a new SedDataSource_t object, adds it to this SedDataDescription_t
 * object and returns the SedDataSource_t object created.
 *
 * @param sdd the SedDataDescription_t structure to which the SedDataSource_t
 * should be added.
 *
 * @return a new SedDataSource_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_createDataSource(SedDataDescription_t* sdd);


/**
 * Removes the nth SedDataSource_t from this SedDataDescription_t and returns a
 * pointer to it.
 *
 * @param sdd the SedDataDescription_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataSource_t to
 * remove.
 *
 * @return a pointer to the nth SedDataSource_t in this SedDataDescription_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_removeDataSource(SedDataDescription_t* sdd,
                                    unsigned int n);


/**
 * Removes the SedDataSource_t from this SedDataDescription_t based on its
 * identifier and returns a pointer to it.
 *
 * @param sdd the SedDataDescription_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataSource_t to
 * remove.
 *
 * @return the SedDataSource_t in this SedDataDescription_t based on the
 * identifier or NULL if no such SedDataSource_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataDescription_removeDataSourceById(SedDataDescription_t* sdd,
                                        const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDataDescription_t object have been set.
 *
 * @param sdd the SedDataDescription_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedDataDescription_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedDataDescription_t object are:
 * @li "id"
 *
 * @memberof SedDataDescription_t
 */
LIBSEDML_EXTERN
int
SedDataDescription_hasRequiredAttributes(const SedDataDescription_t * sdd);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedDataDescription_H__ */


