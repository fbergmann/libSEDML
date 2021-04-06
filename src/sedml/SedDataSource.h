/**
 * @file SedDataSource.h
 * @brief Definition of the SedDataSource class.
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
 * @class SedDataSource
 * @sbmlbrief{sedml} TODO:Definition of the SedDataSource class.
 */


#ifndef SedDataSource_H__
#define SedDataSource_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOfSlices.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDataSource : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mIndexSet;
  SedListOfSlices mSlices;

  /** @endcond */

public:

  /**
   * Creates a new SedDataSource using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedDataSource.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedDataSource.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDataSource(unsigned int level = SEDML_DEFAULT_LEVEL,
                unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDataSource using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDataSource(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedDataSource.
   *
   * @param orig the SedDataSource instance to copy.
   */
  SedDataSource(const SedDataSource& orig);


  /**
   * Assignment operator for SedDataSource.
   *
   * @param rhs the SedDataSource object whose values are to be used as the
   * basis of the assignment.
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
   * Returns the value of the "indexSet" attribute of this SedDataSource.
   *
   * @return the value of the "indexSet" attribute of this SedDataSource as a
   * string.
   */
  const std::string& getIndexSet() const;


  /**
   * Predicate returning @c true if this SedDataSource's "indexSet" attribute
   * is set.
   *
   * @return @c true if this SedDataSource's "indexSet" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetIndexSet() const;


  /**
   * Sets the value of the "indexSet" attribute of this SedDataSource.
   *
   * @param indexSet std::string& value of the "indexSet" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setIndexSet(const std::string& indexSet);


  /**
   * Unsets the value of the "indexSet" attribute of this SedDataSource.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetIndexSet();


  /**
   * Returns the SedListOfSlices from this SedDataSource.
   *
   * @return the SedListOfSlices from this SedDataSource.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSlice(const SedSlice* object)
   * @see createSlice()
   * @see getSlice(const std::string& sid)
   * @see getSlice(unsigned int n)
   * @see getNumSlices()
   * @see removeSlice(const std::string& sid)
   * @see removeSlice(unsigned int n)
   */
  const SedListOfSlices* getListOfSlices() const;


  /**
   * Returns the SedListOfSlices from this SedDataSource.
   *
   * @return the SedListOfSlices from this SedDataSource.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSlice(const SedSlice* object)
   * @see createSlice()
   * @see getSlice(const std::string& sid)
   * @see getSlice(unsigned int n)
   * @see getNumSlices()
   * @see removeSlice(const std::string& sid)
   * @see removeSlice(unsigned int n)
   */
  SedListOfSlices* getListOfSlices();


  /**
   * Get a SedSlice from the SedDataSource.
   *
   * @param n an unsigned int representing the index of the SedSlice to
   * retrieve.
   *
   * @return the nth SedSlice in the SedListOfSlices within this SedDataSource
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSlice(const SedSlice* object)
   * @see createSlice()
   * @see getSlice(const std::string& sid)
   * @see getNumSlices()
   * @see removeSlice(const std::string& sid)
   * @see removeSlice(unsigned int n)
   */
  SedSlice* getSlice(unsigned int n);


  /**
   * Get a SedSlice from the SedDataSource.
   *
   * @param n an unsigned int representing the index of the SedSlice to
   * retrieve.
   *
   * @return the nth SedSlice in the SedListOfSlices within this SedDataSource
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSlice(const SedSlice* object)
   * @see createSlice()
   * @see getSlice(const std::string& sid)
   * @see getNumSlices()
   * @see removeSlice(const std::string& sid)
   * @see removeSlice(unsigned int n)
   */
  const SedSlice* getSlice(unsigned int n) const;


  /**
   * Get a SedSlice from the SedDataSource based on the Reference to which it
   * refers.
   *
   * @param sid a string representing the "reference" attribute of the SedSlice
   * object to retrieve.
   *
   * @return the first SedSlice in this SedDataSource based on the given
   * reference attribute or NULL if no such SedSlice exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSlice* getSliceByReference(const std::string& sid) const;


  /**
   * Get a SedSlice from the SedDataSource based on the Reference to which it
   * refers.
   *
   * @param sid a string representing the "reference" attribute of the SedSlice
   * object to retrieve.
   *
   * @return the first SedSlice in this SedDataSource based on the given
   * reference attribute or NULL if no such SedSlice exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSlice* getSliceByReference(const std::string& sid);


  /**
   * Get a SedSlice from the SedDataSource based on the Index to which it
   * refers.
   *
   * @param sid a string representing the "index" attribute of the SedSlice
   * object to retrieve.
   *
   * @return the first SedSlice in this SedDataSource based on the given index
   * attribute or NULL if no such SedSlice exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSlice* getSliceByIndex(const std::string& sid) const;


  /**
   * Get a SedSlice from the SedDataSource based on the Index to which it
   * refers.
   *
   * @param sid a string representing the "index" attribute of the SedSlice
   * object to retrieve.
   *
   * @return the first SedSlice in this SedDataSource based on the given index
   * attribute or NULL if no such SedSlice exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSlice* getSliceByIndex(const std::string& sid);


  /**
   * Adds a copy of the given SedSlice to this SedDataSource.
   *
   * @param ss the SedSlice object to add.
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
   * @see createSlice()
   * @see getSlice(const std::string& sid)
   * @see getSlice(unsigned int n)
   * @see getNumSlices()
   * @see removeSlice(const std::string& sid)
   * @see removeSlice(unsigned int n)
   */
  int addSlice(const SedSlice* ss);


  /**
   * Get the number of SedSlice objects in this SedDataSource.
   *
   * @return the number of SedSlice objects in this SedDataSource.
   *
   * @see addSlice(const SedSlice* object)
   * @see createSlice()
   * @see getSlice(const std::string& sid)
   * @see getSlice(unsigned int n)
   * @see removeSlice(const std::string& sid)
   * @see removeSlice(unsigned int n)
   */
  unsigned int getNumSlices() const;


  /**
   * Creates a new SedSlice object, adds it to this SedDataSource object and
   * returns the SedSlice object created.
   *
   * @return a new SedSlice object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSlice(const SedSlice* object)
   * @see getSlice(const std::string& sid)
   * @see getSlice(unsigned int n)
   * @see getNumSlices()
   * @see removeSlice(const std::string& sid)
   * @see removeSlice(unsigned int n)
   */
  SedSlice* createSlice();


  /**
   * Removes the nth SedSlice from this SedDataSource and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SedSlice to remove.
   *
   * @return a pointer to the nth SedSlice in this SedDataSource.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSlice(const SedSlice* object)
   * @see createSlice()
   * @see getSlice(const std::string& sid)
   * @see getSlice(unsigned int n)
   * @see getNumSlices()
   * @see removeSlice(const std::string& sid)
   */
  SedSlice* removeSlice(unsigned int n);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedDataSource object.
   *
   * For SedDataSource, the XML element name is always @c "dataSource".
   *
   * @return the name of this element, i.e. @c "dataSource".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedDataSource object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_DATA_SOURCE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedDataSource object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedDataSource have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedDataSource object are:
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
   * Gets the value of the "attributeName" attribute of this SedDataSource.
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
   * Gets the value of the "attributeName" attribute of this SedDataSource.
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
   * Gets the value of the "attributeName" attribute of this SedDataSource.
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
   * Gets the value of the "attributeName" attribute of this SedDataSource.
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
   * Gets the value of the "attributeName" attribute of this SedDataSource.
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
   * Predicate returning @c true if this SedDataSource's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedDataSource's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDataSource.
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
   * Sets the value of the "attributeName" attribute of this SedDataSource.
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
   * Sets the value of the "attributeName" attribute of this SedDataSource.
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
   * Sets the value of the "attributeName" attribute of this SedDataSource.
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
   * Sets the value of the "attributeName" attribute of this SedDataSource.
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
   * Unsets the value of the "attributeName" attribute of this SedDataSource.
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
   * Creates and returns an new "elementName" object in this SedDataSource.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedDataSource.
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
   * SedDataSource.
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
   * Returns the number of "elementName" in this SedDataSource.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedDataSource.
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
 * Creates a new SedDataSource_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedDataSource_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedDataSource_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
SedDataSource_t *
SedDataSource_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedDataSource_t object.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @return a (deep) copy of this SedDataSource_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedDataSource_clone(const SedDataSource_t* sds);


/**
 * Frees this SedDataSource_t object.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
void
SedDataSource_free(SedDataSource_t* sds);


/**
 * Returns the value of the "id" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedDataSource_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
char *
SedDataSource_getId(const SedDataSource_t * sds);


/**
 * Returns the value of the "name" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedDataSource_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
char *
SedDataSource_getName(const SedDataSource_t * sds);


/**
 * Returns the value of the "indexSet" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure whose indexSet is sought.
 *
 * @return the value of the "indexSet" attribute of this SedDataSource_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
char *
SedDataSource_getIndexSet(const SedDataSource_t * sds);


/**
 * Predicate returning @c 1 (true) if this SedDataSource_t's "id" attribute is
 * set.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @return @c 1 (true) if this SedDataSource_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetId(const SedDataSource_t * sds);


/**
 * Predicate returning @c 1 (true) if this SedDataSource_t's "name" attribute
 * is set.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @return @c 1 (true) if this SedDataSource_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetName(const SedDataSource_t * sds);


/**
 * Predicate returning @c 1 (true) if this SedDataSource_t's "indexSet"
 * attribute is set.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @return @c 1 (true) if this SedDataSource_t's "indexSet" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetIndexSet(const SedDataSource_t * sds);


/**
 * Sets the value of the "id" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure.
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
 * to calling SedDataSource_unsetId().
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_setId(SedDataSource_t * sds, const char * id);


/**
 * Sets the value of the "name" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedDataSource_unsetName().
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_setName(SedDataSource_t * sds, const char * name);


/**
 * Sets the value of the "indexSet" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @param indexSet const char * value of the "indexSet" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_setIndexSet(SedDataSource_t * sds, const char * indexSet);


/**
 * Unsets the value of the "id" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetId(SedDataSource_t * sds);


/**
 * Unsets the value of the "name" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetName(SedDataSource_t * sds);


/**
 * Unsets the value of the "indexSet" attribute of this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetIndexSet(SedDataSource_t * sds);


/**
 * Returns a ListOf_t * containing SedSlice_t objects from this
 * SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure whose SedListOfSlices is sought.
 *
 * @return the SedListOfSlices from this SedDataSource_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDataSource_addSlice()
 * @see SedDataSource_createSlice()
 * @see SedDataSource_getSliceById()
 * @see SedDataSource_getSlice()
 * @see SedDataSource_getNumSlices()
 * @see SedDataSource_removeSliceById()
 * @see SedDataSource_removeSlice()
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataSource_getListOfSlices(SedDataSource_t* sds);


/**
 * Get a SedSlice_t from the SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSlice_t to
 * retrieve.
 *
 * @return the nth SedSlice_t in the SedListOfSlices within this SedDataSource
 * or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_getSlice(SedDataSource_t* sds, unsigned int n);


/**
 * Get a SedSlice_t from the SedDataSource_t based on the Reference to which it
 * refers.
 *
 * @param sds the SedDataSource_t structure to search.
 *
 * @param sid a string representing the "reference" attribute of the SedSlice_t
 * object to retrieve.
 *
 * @return the first SedSlice_t in this SedDataSource_t based on the given
 * reference attribute or NULL if no such SedSlice_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_getSliceByReference(SedDataSource_t* sds, const char *sid);


/**
 * Get a SedSlice_t from the SedDataSource_t based on the Index to which it
 * refers.
 *
 * @param sds the SedDataSource_t structure to search.
 *
 * @param sid a string representing the "index" attribute of the SedSlice_t
 * object to retrieve.
 *
 * @return the first SedSlice_t in this SedDataSource_t based on the given
 * index attribute or NULL if no such SedSlice_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_getSliceByIndex(SedDataSource_t* sds, const char *sid);


/**
 * Adds a copy of the given SedSlice_t to this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure to which the SedSlice_t should be
 * added.
 *
 * @param ss the SedSlice_t object to add.
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
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_addSlice(SedDataSource_t* sds, const SedSlice_t* ss);


/**
 * Get the number of SedSlice_t objects in this SedDataSource_t.
 *
 * @param sds the SedDataSource_t structure to query.
 *
 * @return the number of SedSlice_t objects in this SedDataSource_t.
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
unsigned int
SedDataSource_getNumSlices(SedDataSource_t* sds);


/**
 * Creates a new SedSlice_t object, adds it to this SedDataSource_t object and
 * returns the SedSlice_t object created.
 *
 * @param sds the SedDataSource_t structure to which the SedSlice_t should be
 * added.
 *
 * @return a new SedSlice_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_createSlice(SedDataSource_t* sds);


/**
 * Removes the nth SedSlice_t from this SedDataSource_t and returns a pointer
 * to it.
 *
 * @param sds the SedDataSource_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSlice_t to remove.
 *
 * @return a pointer to the nth SedSlice_t in this SedDataSource_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
SedSlice_t*
SedDataSource_removeSlice(SedDataSource_t* sds, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDataSource_t object have been set.
 *
 * @param sds the SedDataSource_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedDataSource_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedDataSource_t object are:
 * @li "id"
 *
 * @memberof SedDataSource_t
 */
LIBSEDML_EXTERN
int
SedDataSource_hasRequiredAttributes(const SedDataSource_t * sds);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedDataSource_H__ */


