/**
 * @file SedReport.h
 * @brief Definition of the SedReport class.
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
 * @class SedReport
 * @sbmlbrief{sedml} TODO:Definition of the SedReport class.
 */


#ifndef SedReport_H__
#define SedReport_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedOutput.h>
#include <sedml/SedListOfDataSets.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedReport : public SedOutput
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  SedListOfDataSets mDataSets;

  /** @endcond */

public:

  /**
   * Creates a new SedReport using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedReport.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedReport.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedReport(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedReport using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedReport(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedReport.
   *
   * @param orig the SedReport instance to copy.
   */
  SedReport(const SedReport& orig);


  /**
   * Assignment operator for SedReport.
   *
   * @param rhs the SedReport object whose values are to be used as the basis
   * of the assignment.
   */
  SedReport& operator=(const SedReport& rhs);


  /**
   * Creates and returns a deep copy of this SedReport object.
   *
   * @return a (deep) copy of this SedReport object.
   */
  virtual SedReport* clone() const;


  /**
   * Destructor for SedReport.
   */
  virtual ~SedReport();


  /**
   * Returns the SedListOfDataSets from this SedReport.
   *
   * @return the SedListOfDataSets from this SedReport.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(const std::string& sid)
   * @see getDataSet(unsigned int n)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  const SedListOfDataSets* getListOfDataSets() const;


  /**
   * Returns the SedListOfDataSets from this SedReport.
   *
   * @return the SedListOfDataSets from this SedReport.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(const std::string& sid)
   * @see getDataSet(unsigned int n)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  SedListOfDataSets* getListOfDataSets();


  /**
   * Get a SedDataSet from the SedReport.
   *
   * @param n an unsigned int representing the index of the SedDataSet to
   * retrieve.
   *
   * @return the nth SedDataSet in the SedListOfDataSets within this SedReport
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(const std::string& sid)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  SedDataSet* getDataSet(unsigned int n);


  /**
   * Get a SedDataSet from the SedReport.
   *
   * @param n an unsigned int representing the index of the SedDataSet to
   * retrieve.
   *
   * @return the nth SedDataSet in the SedListOfDataSets within this SedReport
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(const std::string& sid)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  const SedDataSet* getDataSet(unsigned int n) const;


  /**
   * Get a SedDataSet from the SedReport based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataSet to
   * retrieve.
   *
   * @return the SedDataSet in the SedListOfDataSets within this SedReport with
   * the given @p sid or @c NULL if no such SedDataSet exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(unsigned int n)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  SedDataSet* getDataSet(const std::string& sid);


  /**
   * Get a SedDataSet from the SedReport based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataSet to
   * retrieve.
   *
   * @return the SedDataSet in the SedListOfDataSets within this SedReport with
   * the given @p sid or @c NULL if no such SedDataSet exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(unsigned int n)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  const SedDataSet* getDataSet(const std::string& sid) const;


  /**
   * Get a SedDataSet from the SedReport based on the DataReference to which it
   * refers.
   *
   * @param sid a string representing the "dataReference" attribute of the
   * SedDataSet object to retrieve.
   *
   * @return the first SedDataSet in this SedReport based on the given
   * dataReference attribute or NULL if no such SedDataSet exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedDataSet* getDataSetByDataReference(const std::string& sid) const;


  /**
   * Get a SedDataSet from the SedReport based on the DataReference to which it
   * refers.
   *
   * @param sid a string representing the "dataReference" attribute of the
   * SedDataSet object to retrieve.
   *
   * @return the first SedDataSet in this SedReport based on the given
   * dataReference attribute or NULL if no such SedDataSet exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedDataSet* getDataSetByDataReference(const std::string& sid);


  /**
   * Adds a copy of the given SedDataSet to this SedReport.
   *
   * @param sds the SedDataSet object to add.
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
   * @see createDataSet()
   * @see getDataSet(const std::string& sid)
   * @see getDataSet(unsigned int n)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  int addDataSet(const SedDataSet* sds);


  /**
   * Get the number of SedDataSet objects in this SedReport.
   *
   * @return the number of SedDataSet objects in this SedReport.
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(const std::string& sid)
   * @see getDataSet(unsigned int n)
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  unsigned int getNumDataSets() const;


  /**
   * Creates a new SedDataSet object, adds it to this SedReport object and
   * returns the SedDataSet object created.
   *
   * @return a new SedDataSet object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see getDataSet(const std::string& sid)
   * @see getDataSet(unsigned int n)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   * @see removeDataSet(unsigned int n)
   */
  SedDataSet* createDataSet();


  /**
   * Removes the nth SedDataSet from this SedReport and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SedDataSet to
   * remove.
   *
   * @return a pointer to the nth SedDataSet in this SedReport.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(const std::string& sid)
   * @see getDataSet(unsigned int n)
   * @see getNumDataSets()
   * @see removeDataSet(const std::string& sid)
   */
  SedDataSet* removeDataSet(unsigned int n);


  /**
   * Removes the SedDataSet from this SedReport based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedDataSet to
   * remove.
   *
   * @return the SedDataSet in this SedReport based on the identifier or NULL
   * if no such SedDataSet exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see getDataSet(const std::string& sid)
   * @see getDataSet(unsigned int n)
   * @see getNumDataSets()
   * @see removeDataSet(unsigned int n)
   */
  SedDataSet* removeDataSet(const std::string& sid);


  /**
   * Returns the XML element name of this SedReport object.
   *
   * For SedReport, the XML element name is always @c "report".
   *
   * @return the name of this element, i.e. @c "report".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedReport object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_OUTPUT_REPORT, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedReport object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedReport have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedReport object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedReport have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedReport object are:
   */
  virtual bool hasRequiredElements() const;



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
   * Gets the value of the "attributeName" attribute of this SedReport.
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
   * Gets the value of the "attributeName" attribute of this SedReport.
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
   * Gets the value of the "attributeName" attribute of this SedReport.
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
   * Gets the value of the "attributeName" attribute of this SedReport.
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
   * Gets the value of the "attributeName" attribute of this SedReport.
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
   * Predicate returning @c true if this SedReport's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedReport's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedReport.
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
   * Sets the value of the "attributeName" attribute of this SedReport.
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
   * Sets the value of the "attributeName" attribute of this SedReport.
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
   * Sets the value of the "attributeName" attribute of this SedReport.
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
   * Sets the value of the "attributeName" attribute of this SedReport.
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
   * Unsets the value of the "attributeName" attribute of this SedReport.
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
   * Creates and returns an new "elementName" object in this SedReport.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedReport.
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
   * SedReport.
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
   * Returns the number of "elementName" in this SedReport.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedReport.
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
 * Creates a new SedReport_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedReport_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedReport_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedReport_t *
SedReport_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedReport_t object.
 *
 * @param sr the SedReport_t structure.
 *
 * @return a (deep) copy of this SedReport_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedReport_t*
SedReport_clone(const SedReport_t* sr);


/**
 * Frees this SedReport_t object.
 *
 * @param sr the SedReport_t structure.
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
void
SedReport_free(SedReport_t* sr);


/**
 * Returns a ListOf_t * containing SedDataSet_t objects from this SedReport_t.
 *
 * @param sr the SedReport_t structure whose SedListOfDataSets is sought.
 *
 * @return the SedListOfDataSets from this SedReport_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedReport_addDataSet()
 * @see SedReport_createDataSet()
 * @see SedReport_getDataSetById()
 * @see SedReport_getDataSet()
 * @see SedReport_getNumDataSets()
 * @see SedReport_removeDataSetById()
 * @see SedReport_removeDataSet()
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedReport_getListOfDataSets(SedReport_t* sr);


/**
 * Get a SedDataSet_t from the SedReport_t.
 *
 * @param sr the SedReport_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataSet_t to
 * retrieve.
 *
 * @return the nth SedDataSet_t in the SedListOfDataSets within this SedReport
 * or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_getDataSet(SedReport_t* sr, unsigned int n);


/**
 * Get a SedDataSet_t from the SedReport_t based on its identifier.
 *
 * @param sr the SedReport_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataSet_t to
 * retrieve.
 *
 * @return the SedDataSet_t in the SedListOfDataSets within this SedReport with
 * the given @p sid or @c NULL if no such SedDataSet_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_getDataSetById(SedReport_t* sr, const char *sid);


/**
 * Get a SedDataSet_t from the SedReport_t based on the DataReference to which
 * it refers.
 *
 * @param sr the SedReport_t structure to search.
 *
 * @param sid a string representing the "dataReference" attribute of the
 * SedDataSet_t object to retrieve.
 *
 * @return the first SedDataSet_t in this SedReport_t based on the given
 * dataReference attribute or NULL if no such SedDataSet_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_getDataSetByDataReference(SedReport_t* sr, const char *sid);


/**
 * Adds a copy of the given SedDataSet_t to this SedReport_t.
 *
 * @param sr the SedReport_t structure to which the SedDataSet_t should be
 * added.
 *
 * @param sds the SedDataSet_t object to add.
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
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
int
SedReport_addDataSet(SedReport_t* sr, const SedDataSet_t* sds);


/**
 * Get the number of SedDataSet_t objects in this SedReport_t.
 *
 * @param sr the SedReport_t structure to query.
 *
 * @return the number of SedDataSet_t objects in this SedReport_t.
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
unsigned int
SedReport_getNumDataSets(SedReport_t* sr);


/**
 * Creates a new SedDataSet_t object, adds it to this SedReport_t object and
 * returns the SedDataSet_t object created.
 *
 * @param sr the SedReport_t structure to which the SedDataSet_t should be
 * added.
 *
 * @return a new SedDataSet_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_createDataSet(SedReport_t* sr);


/**
 * Removes the nth SedDataSet_t from this SedReport_t and returns a pointer to
 * it.
 *
 * @param sr the SedReport_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataSet_t to
 * remove.
 *
 * @return a pointer to the nth SedDataSet_t in this SedReport_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_removeDataSet(SedReport_t* sr, unsigned int n);


/**
 * Removes the SedDataSet_t from this SedReport_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sr the SedReport_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataSet_t to
 * remove.
 *
 * @return the SedDataSet_t in this SedReport_t based on the identifier or NULL
 * if no such SedDataSet_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedReport_removeDataSetById(SedReport_t* sr, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedReport_t object have been set.
 *
 * @param sr the SedReport_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedReport_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
int
SedReport_hasRequiredAttributes(const SedReport_t * sr);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedReport_t object have been set.
 *
 * @param sr the SedReport_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedReport_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedReport_t object are:
 *
 * @memberof SedReport_t
 */
LIBSEDML_EXTERN
int
SedReport_hasRequiredElements(const SedReport_t * sr);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedReport_H__ */


