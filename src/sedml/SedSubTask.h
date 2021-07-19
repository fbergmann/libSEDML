/**
 * @file SedSubTask.h
 * @brief Definition of the SedSubTask class.
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
 * @class SedSubTask
 * @sbmlbrief{sedml} TODO:Definition of the SedSubTask class.
 */


#ifndef SedSubTask_H__
#define SedSubTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOfSetValues.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSubTask : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  int mOrder;
  bool mIsSetOrder;
  std::string mTask;
  SedListOfSetValues mSetValues;

  /** @endcond */

public:

  /**
   * Creates a new SedSubTask using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedSubTask.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedSubTask.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSubTask(unsigned int level = SEDML_DEFAULT_LEVEL,
             unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedSubTask using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSubTask(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedSubTask.
   *
   * @param orig the SedSubTask instance to copy.
   */
  SedSubTask(const SedSubTask& orig);


  /**
   * Assignment operator for SedSubTask.
   *
   * @param rhs the SedSubTask object whose values are to be used as the basis
   * of the assignment.
   */
  SedSubTask& operator=(const SedSubTask& rhs);


  /**
   * Creates and returns a deep copy of this SedSubTask object.
   *
   * @return a (deep) copy of this SedSubTask object.
   */
  virtual SedSubTask* clone() const;


  /**
   * Destructor for SedSubTask.
   */
  virtual ~SedSubTask();


  /**
   * Returns the value of the "order" attribute of this SedSubTask.
   *
   * @return the value of the "order" attribute of this SedSubTask as a
   * integer.
   */
  int getOrder() const;


  /**
   * Returns the value of the "task" attribute of this SedSubTask.
   *
   * @return the value of the "task" attribute of this SedSubTask as a string.
   */
  const std::string& getTask() const;


  /**
   * Predicate returning @c true if this SedSubTask's "order" attribute is set.
   *
   * @return @c true if this SedSubTask's "order" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetOrder() const;


  /**
   * Predicate returning @c true if this SedSubTask's "task" attribute is set.
   *
   * @return @c true if this SedSubTask's "task" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTask() const;


  /**
   * Sets the value of the "order" attribute of this SedSubTask.
   *
   * @param order int value of the "order" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOrder(int order);


  /**
   * Sets the value of the "task" attribute of this SedSubTask.
   *
   * @param task std::string& value of the "task" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTask(const std::string& task);


  /**
   * Unsets the value of the "order" attribute of this SedSubTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOrder();


  /**
   * Unsets the value of the "task" attribute of this SedSubTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTask();


  /**
   * Returns the SedListOfSetValues from this SedRepeatedTask.
   *
   * @return the SedListOfSetValues from this SedRepeatedTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createTaskChange()
   * @see getTaskChange(const std::string& sid)
   * @see getTaskChange(unsigned int n)
   * @see getNumTaskChanges()
   * @see removeTaskChange(const std::string& sid)
   * @see removeTaskChange(unsigned int n)
   */
  const SedListOfSetValues* getListOfTaskChanges() const;


  /**
   * Returns the SedListOfSetValues from this SedRepeatedTask.
   *
   * @return the SedListOfSetValues from this SedRepeatedTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createTaskChange()
   * @see getTaskChange(const std::string& sid)
   * @see getTaskChange(unsigned int n)
   * @see getNumTaskChanges()
   * @see removeTaskChange(const std::string& sid)
   * @see removeTaskChange(unsigned int n)
   */
  SedListOfSetValues* getListOfTaskChanges();


  /**
   * Get a SedSetValue from the SedRepeatedTask.
   *
   * @param n an unsigned int representing the index of the SedSetValue to
   * retrieve.
   *
   * @return the nth SedSetValue in the SedListOfSetValues within this
   * SedRepeatedTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createTaskChange()
   * @see getTaskChange(const std::string& sid)
   * @see getNumTaskChanges()
   * @see removeTaskChange(const std::string& sid)
   * @see removeTaskChange(unsigned int n)
   */
  SedSetValue* getTaskChange(unsigned int n);


  /**
   * Get a SedSetValue from the SedRepeatedTask.
   *
   * @param id the id of the SedSetValue to
   * retrieve.
   *
   * @return the SedSetValue in the SedListOfSetValues within this
   * SedRepeatedTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createTaskChange()
   * @see getTaskChange(const std::string& sid)
   * @see getNumTaskChanges()
   * @see removeTaskChange(const std::string& sid)
   * @see removeTaskChange(unsigned int n)
   */
  SedSetValue* getTaskChange(const std::string& id);


  /**
   * Get a SedSetValue from the SedRepeatedTask.
   *
   * @param n an unsigned int representing the index of the SedSetValue to
   * retrieve.
   *
   * @return the nth SedSetValue in the SedListOfSetValues within this
   * SedRepeatedTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createTaskChange()
   * @see getTaskChange(const std::string& sid)
   * @see getNumTaskChanges()
   * @see removeTaskChange(const std::string& sid)
   * @see removeTaskChange(unsigned int n)
   */
  const SedSetValue* getTaskChange(unsigned int n) const;


  /**
   * Get a SedSetValue from the SedRepeatedTask based on the ModelReference to
   * which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedSetValue object to retrieve.
   *
   * @return the first SedSetValue in this SedRepeatedTask based on the given
   * modelReference attribute or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSetValue* getTaskChangeByModelReference(const std::string& sid) const;


  /**
   * Get a SedSetValue from the SedRepeatedTask based on the ModelReference to
   * which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedSetValue object to retrieve.
   *
   * @return the first SedSetValue in this SedRepeatedTask based on the given
   * modelReference attribute or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSetValue* getTaskChangeByModelReference(const std::string& sid);


  /**
   * Get a SedSetValue from the SedRepeatedTask based on the Range to which it
   * refers.
   *
   * @param sid a string representing the "range" attribute of the SedSetValue
   * object to retrieve.
   *
   * @return the first SedSetValue in this SedRepeatedTask based on the given
   * range attribute or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSetValue* getTaskChangeByRange(const std::string& sid) const;


  /**
   * Get a SedSetValue from the SedRepeatedTask based on the Range to which it
   * refers.
   *
   * @param sid a string representing the "range" attribute of the SedSetValue
   * object to retrieve.
   *
   * @return the first SedSetValue in this SedRepeatedTask based on the given
   * range attribute or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSetValue* getTaskChangeByRange(const std::string& sid);


  /**
   * Adds a copy of the given SedSetValue to this SedRepeatedTask.
   *
   * @param ssv the SedSetValue object to add.
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
   * @see createTaskChange()
   * @see getTaskChange(const std::string& sid)
   * @see getTaskChange(unsigned int n)
   * @see getNumTaskChanges()
   * @see removeTaskChange(const std::string& sid)
   * @see removeTaskChange(unsigned int n)
   */
  int addTaskChange(const SedSetValue* ssv);


  /**
   * Get the number of SedSetValue objects in this SedRepeatedTask.
   *
   * @return the number of SedSetValue objects in this SedRepeatedTask.
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createTaskChange()
   * @see getTaskChange(const std::string& sid)
   * @see getTaskChange(unsigned int n)
   * @see removeTaskChange(const std::string& sid)
   * @see removeTaskChange(unsigned int n)
   */
  unsigned int getNumTaskChanges() const;


  /**
   * Creates a new SedSetValue object, adds it to this SedRepeatedTask object
   * and returns the SedSetValue object created.
   *
   * @return a new SedSetValue object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see getTaskChange(const std::string& sid)
   * @see getTaskChange(unsigned int n)
   * @see getNumTaskChanges()
   * @see removeTaskChange(const std::string& sid)
   * @see removeTaskChange(unsigned int n)
   */
  SedSetValue* createTaskChange();


  /**
   * Removes the nth SedSetValue from this SedRepeatedTask and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedSetValue to
   * remove.
   *
   * @return a pointer to the nth SedSetValue in this SedRepeatedTask.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createTaskChange()
   * @see getTaskChange(const std::string& sid)
   * @see getTaskChange(unsigned int n)
   * @see getNumTaskChanges()
   * @see removeTaskChange(const std::string& sid)
   */
  SedSetValue* removeTaskChange(unsigned int n);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedSubTask object.
   *
   * For SedSubTask, the XML element name is always @c "subTask".
   *
   * @return the name of this element, i.e. @c "subTask".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedSubTask object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_TASK_SUBTASK, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedSubTask object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedSubTask have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedSubTask object are:
   * @li "order"
   * @li "task"
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
   * Gets the value of the "attributeName" attribute of this SedSubTask.
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
   * Gets the value of the "attributeName" attribute of this SedSubTask.
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
   * Gets the value of the "attributeName" attribute of this SedSubTask.
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
   * Gets the value of the "attributeName" attribute of this SedSubTask.
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
   * Gets the value of the "attributeName" attribute of this SedSubTask.
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
   * Predicate returning @c true if this SedSubTask's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedSubTask's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedSubTask.
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
   * Sets the value of the "attributeName" attribute of this SedSubTask.
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
   * Sets the value of the "attributeName" attribute of this SedSubTask.
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
   * Sets the value of the "attributeName" attribute of this SedSubTask.
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
   * Sets the value of the "attributeName" attribute of this SedSubTask.
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
   * Unsets the value of the "attributeName" attribute of this SedSubTask.
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
   * Creates and returns an new "elementName" object in this SedRepeatedTask.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedRepeatedTask.
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
   * SedRepeatedTask.
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
   * Returns the number of "elementName" in this SedRepeatedTask.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedRepeatedTask.
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
  virtual List* getAllElements(SedElementFilter* filter = NULL);


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
 * Creates a new SedSubTask_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedSubTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedSubTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
SedSubTask_t *
SedSubTask_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedSubTask_t object.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @return a (deep) copy of this SedSubTask_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedSubTask_clone(const SedSubTask_t* sst);


/**
 * Frees this SedSubTask_t object.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
void
SedSubTask_free(SedSubTask_t* sst);


/**
 * Returns the value of the "order" attribute of this SedSubTask_t.
 *
 * @param sst the SedSubTask_t structure whose order is sought.
 *
 * @return the value of the "order" attribute of this SedSubTask_t as a
 * integer.
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
int
SedSubTask_getOrder(const SedSubTask_t * sst);


/**
 * Returns the value of the "task" attribute of this SedSubTask_t.
 *
 * @param sst the SedSubTask_t structure whose task is sought.
 *
 * @return the value of the "task" attribute of this SedSubTask_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
char *
SedSubTask_getTask(const SedSubTask_t * sst);


/**
 * Predicate returning @c 1 (true) if this SedSubTask_t's "order" attribute is
 * set.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @return @c 1 (true) if this SedSubTask_t's "order" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
int
SedSubTask_isSetOrder(const SedSubTask_t * sst);


/**
 * Predicate returning @c 1 (true) if this SedSubTask_t's "task" attribute is
 * set.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @return @c 1 (true) if this SedSubTask_t's "task" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
int
SedSubTask_isSetTask(const SedSubTask_t * sst);


/**
 * Sets the value of the "order" attribute of this SedSubTask_t.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @param order int value of the "order" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
int
SedSubTask_setOrder(SedSubTask_t * sst, int order);


/**
 * Sets the value of the "task" attribute of this SedSubTask_t.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @param task const char * value of the "task" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
int
SedSubTask_setTask(SedSubTask_t * sst, const char * task);


/**
 * Unsets the value of the "order" attribute of this SedSubTask_t.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
int
SedSubTask_unsetOrder(SedSubTask_t * sst);


/**
 * Unsets the value of the "task" attribute of this SedSubTask_t.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
int
SedSubTask_unsetTask(SedSubTask_t * sst);


/**
 * Returns a ListOf_t * containing SedSetValue_t objects from this
 * SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure whose SedListOfSetValues is
 * sought.
 *
 * @return the SedListOfSetValues from this SedRepeatedTask_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedRepeatedTask_addTaskChange()
 * @see SedRepeatedTask_createTaskChange()
 * @see SedRepeatedTask_getTaskChangeById()
 * @see SedRepeatedTask_getTaskChange()
 * @see SedRepeatedTask_getNumTaskChanges()
 * @see SedRepeatedTask_removeTaskChangeById()
 * @see SedRepeatedTask_removeTaskChange()
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedRepeatedTask_getListOfTaskChanges(SedRepeatedTask_t* srt);


/**
 * Get a SedSetValue_t from the SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSetValue_t to
 * retrieve.
 *
 * @return the nth SedSetValue_t in the SedListOfSetValues within this
 * SedRepeatedTask or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_getTaskChange(SedRepeatedTask_t* srt, unsigned int n);


/**
 * Get a SedSetValue_t from the SedRepeatedTask_t based on the ModelReference
 * to which it refers.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param sid a string representing the "modelReference" attribute of the
 * SedSetValue_t object to retrieve.
 *
 * @return the first SedSetValue_t in this SedRepeatedTask_t based on the given
 * modelReference attribute or NULL if no such SedSetValue_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_getTaskChangeByModelReference(SedRepeatedTask_t* srt,
    const char* sid);


/**
 * Get a SedSetValue_t from the SedRepeatedTask_t based on the Range to which
 * it refers.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param sid a string representing the "range" attribute of the SedSetValue_t
 * object to retrieve.
 *
 * @return the first SedSetValue_t in this SedRepeatedTask_t based on the given
 * range attribute or NULL if no such SedSetValue_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_getTaskChangeByRange(SedRepeatedTask_t* srt, const char* sid);


/**
 * Adds a copy of the given SedSetValue_t to this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedSetValue_t should
 * be added.
 *
 * @param ssv the SedSetValue_t object to add.
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
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_addTaskChange(SedRepeatedTask_t* srt,
    const SedSetValue_t* ssv);


/**
 * Get the number of SedSetValue_t objects in this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to query.
 *
 * @return the number of SedSetValue_t objects in this SedRepeatedTask_t.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumTaskChanges(SedRepeatedTask_t* srt);


/**
 * Creates a new SedSetValue_t object, adds it to this SedRepeatedTask_t object
 * and returns the SedSetValue_t object created.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedSetValue_t should
 * be added.
 *
 * @return a new SedSetValue_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_createTaskChange(SedRepeatedTask_t* srt);


/**
 * Removes the nth SedSetValue_t from this SedRepeatedTask_t and returns a
 * pointer to it.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSetValue_t to
 * remove.
 *
 * @return a pointer to the nth SedSetValue_t in this SedRepeatedTask_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedRepeatedTask_removeTaskChange(SedRepeatedTask_t* srt, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSubTask_t object have been set.
 *
 * @param sst the SedSubTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedSubTask_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedSubTask_t object are:
 * @li "order"
 * @li "task"
 *
 * @memberof SedSubTask_t
 */
LIBSEDML_EXTERN
int
SedSubTask_hasRequiredAttributes(const SedSubTask_t * sst);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedSubTask_H__ */


