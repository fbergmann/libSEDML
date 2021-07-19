/**
 * @file SedRepeatedTask.h
 * @brief Definition of the SedRepeatedTask class.
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
 * @class SedRepeatedTask
 * @sbmlbrief{sedml} TODO:Definition of the SedRepeatedTask class.
 */


#ifndef SedRepeatedTask_H__
#define SedRepeatedTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedAbstractTask.h>
#include <sedml/SedListOfRanges.h>
#include <sedml/SedListOfSetValues.h>
#include <sedml/SedListOfSubTasks.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedRepeatedTask : public SedAbstractTask
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mRange;
  bool mResetModel;
  bool mIsSetResetModel;
  bool mConcatenate;
  bool mIsSetConcatenate;
  SedListOfRanges mRanges;
  SedListOfSetValues mSetValues;
  SedListOfSubTasks mSubTasks;

  /** @endcond */

public:

  /**
   * Creates a new SedRepeatedTask using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedRepeatedTask.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedRepeatedTask.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedRepeatedTask(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedRepeatedTask using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedRepeatedTask(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedRepeatedTask.
   *
   * @param orig the SedRepeatedTask instance to copy.
   */
  SedRepeatedTask(const SedRepeatedTask& orig);


  /**
   * Assignment operator for SedRepeatedTask.
   *
   * @param rhs the SedRepeatedTask object whose values are to be used as the
   * basis of the assignment.
   */
  SedRepeatedTask& operator=(const SedRepeatedTask& rhs);


  /**
   * Creates and returns a deep copy of this SedRepeatedTask object.
   *
   * @return a (deep) copy of this SedRepeatedTask object.
   */
  virtual SedRepeatedTask* clone() const;


  /**
   * Destructor for SedRepeatedTask.
   */
  virtual ~SedRepeatedTask();


  /**
   * Returns the value of the "range" attribute of this SedRepeatedTask.
   *
   * @return the value of the "range" attribute of this SedRepeatedTask as a
   * string.
   */
  const std::string& getRangeId() const;


  /**
   * Returns the value of the "resetModel" attribute of this SedRepeatedTask.
   *
   * @return the value of the "resetModel" attribute of this SedRepeatedTask as
   * a boolean.
   */
  bool getResetModel() const;


  /**
   * Returns the value of the "concatenate" attribute of this SedRepeatedTask.
   *
   * @return the value of the "concatenate" attribute of this SedRepeatedTask as
   * a boolean.
   */
  bool getConcatenate() const;


  /**
   * Predicate returning @c true if this SedRepeatedTask's "range" attribute is
   * set.
   *
   * @return @c true if this SedRepeatedTask's "range" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRangeId() const;


  /**
   * Predicate returning @c true if this SedRepeatedTask's "resetModel"
   * attribute is set.
   *
   * @return @c true if this SedRepeatedTask's "resetModel" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetResetModel() const;


  /**
   * Predicate returning @c true if this SedRepeatedTask's "concatenate"
   * attribute is set.
   *
   * @return @c true if this SedRepeatedTask's "concatenate" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetConcatenate() const;


  /**
   * Sets the value of the "range" attribute of this SedRepeatedTask.
   *
   * @param rangeId std::string& value of the "range" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRangeId(const std::string& rangeId);


  /**
   * Sets the value of the "resetModel" attribute of this SedRepeatedTask.
   *
   * @param resetModel bool value of the "resetModel" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setResetModel(bool resetModel);


  /**
   * Sets the value of the "concatenate" attribute of this SedRepeatedTask.
   *
   * @param concatenate bool value of the "concatenate" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setConcatenate(bool concatenate);


  /**
   * Unsets the value of the "range" attribute of this SedRepeatedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRangeId();


  /**
   * Unsets the value of the "resetModel" attribute of this SedRepeatedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetResetModel();


  /**
   * Unsets the value of the "concatenate" attribute of this SedRepeatedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetConcatenate();


  /**
   * Returns the SedListOfRanges from this SedRepeatedTask.
   *
   * @return the SedListOfRanges from this SedRepeatedTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  const SedListOfRanges* getListOfRanges() const;


  /**
   * Returns the SedListOfRanges from this SedRepeatedTask.
   *
   * @return the SedListOfRanges from this SedRepeatedTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  SedListOfRanges* getListOfRanges();


  /**
   * Get a SedRange from the SedRepeatedTask.
   *
   * @param n an unsigned int representing the index of the SedRange to
   * retrieve.
   *
   * @return the nth SedRange in the SedListOfRanges within this
   * SedRepeatedTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(const std::string& sid)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  SedRange* getRange(unsigned int n);


  /**
   * Get a SedRange from the SedRepeatedTask.
   *
   * @param n an unsigned int representing the index of the SedRange to
   * retrieve.
   *
   * @return the nth SedRange in the SedListOfRanges within this
   * SedRepeatedTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(const std::string& sid)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  const SedRange* getRange(unsigned int n) const;


  /**
   * Get a SedRange from the SedRepeatedTask based on its identifier.
   *
   * @param sid a string representing the identifier of the SedRange to
   * retrieve.
   *
   * @return the SedRange in the SedListOfRanges within this SedRepeatedTask
   * with the given @p sid or @c NULL if no such SedRange exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  SedRange* getRange(const std::string& sid);


  /**
   * Get a SedRange from the SedRepeatedTask based on its identifier.
   *
   * @param sid a string representing the identifier of the SedRange to
   * retrieve.
   *
   * @return the SedRange in the SedListOfRanges within this SedRepeatedTask
   * with the given @p sid or @c NULL if no such SedRange exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  const SedRange* getRange(const std::string& sid) const;


  /**
   * Adds a copy of the given SedRange to this SedRepeatedTask.
   *
   * @param sr the SedRange object to add.
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
   * @see createRange()
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  int addRange(const SedRange* sr);


  /**
   * Get the number of SedRange objects in this SedRepeatedTask.
   *
   * @return the number of SedRange objects in this SedRepeatedTask.
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  unsigned int getNumRanges() const;


  /**
   * Creates a new SedUniformRange object, adds it to this SedRepeatedTask
   * object and returns the SedUniformRange object created.
   *
   * @return a new SedUniformRange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  SedUniformRange* createUniformRange();


  /**
   * Creates a new SedVectorRange object, adds it to this SedRepeatedTask
   * object and returns the SedVectorRange object created.
   *
   * @return a new SedVectorRange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  SedVectorRange* createVectorRange();


  /**
   * Creates a new SedFunctionalRange object, adds it to this SedRepeatedTask
   * object and returns the SedFunctionalRange object created.
   *
   * @return a new SedFunctionalRange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  SedFunctionalRange* createFunctionalRange();


  /**
   * Creates a new SedDataRange object, adds it to this SedRepeatedTask object
   * and returns the SedDataRange object created.
   *
   * @return a new SedDataRange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   * @see removeRange(unsigned int n)
   */
  SedDataRange* createDataRange();


  /**
   * Removes the nth SedRange from this SedRepeatedTask and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedRange to remove.
   *
   * @return a pointer to the nth SedRange in this SedRepeatedTask.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(const std::string& sid)
   */
  SedRange* removeRange(unsigned int n);


  /**
   * Removes the SedRange from this SedRepeatedTask based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedRange to remove.
   *
   * @return the SedRange in this SedRepeatedTask based on the identifier or
   * NULL if no such SedRange exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see getRange(const std::string& sid)
   * @see getRange(unsigned int n)
   * @see getNumRanges()
   * @see removeRange(unsigned int n)
   */
  SedRange* removeRange(const std::string& sid);


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
   * Returns the SedListOfSubTasks from this SedRepeatedTask.
   *
   * @return the SedListOfSubTasks from this SedRepeatedTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see getSubTask(const std::string& sid)
   * @see getSubTask(unsigned int n)
   * @see getNumSubTasks()
   * @see removeSubTask(const std::string& sid)
   * @see removeSubTask(unsigned int n)
   */
  const SedListOfSubTasks* getListOfSubTasks() const;


  /**
   * Returns the SedListOfSubTasks from this SedRepeatedTask.
   *
   * @return the SedListOfSubTasks from this SedRepeatedTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see getSubTask(const std::string& sid)
   * @see getSubTask(unsigned int n)
   * @see getNumSubTasks()
   * @see removeSubTask(const std::string& sid)
   * @see removeSubTask(unsigned int n)
   */
  SedListOfSubTasks* getListOfSubTasks();


  /**
   * Get a SedSubTask from the SedRepeatedTask.
   *
   * @param n an unsigned int representing the index of the SedSubTask to
   * retrieve.
   *
   * @return the nth SedSubTask in the SedListOfSubTasks within this
   * SedRepeatedTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see getSubTask(const std::string& sid)
   * @see getNumSubTasks()
   * @see removeSubTask(const std::string& sid)
   * @see removeSubTask(unsigned int n)
   */
  SedSubTask* getSubTask(unsigned int n);


  /**
   * Get a SedSubTask from the SedRepeatedTask.
   *
   * @param n an unsigned int representing the index of the SedSubTask to
   * retrieve.
   *
   * @return the nth SedSubTask in the SedListOfSubTasks within this
   * SedRepeatedTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see getSubTask(const std::string& sid)
   * @see getNumSubTasks()
   * @see removeSubTask(const std::string& sid)
   * @see removeSubTask(unsigned int n)
   */
  const SedSubTask* getSubTask(unsigned int n) const;


  /**
   * Get a SedSubTask from the SedRepeatedTask based on the Task to which it
   * refers.
   *
   * @param sid a string representing the "task" attribute of the SedSubTask
   * object to retrieve.
   *
   * @return the first SedSubTask in this SedRepeatedTask based on the given
   * task attribute or NULL if no such SedSubTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSubTask* getSubTaskByTask(const std::string& sid) const;


  /**
   * Get a SedSubTask from the SedRepeatedTask based on the Task to which it
   * refers.
   *
   * @param sid a string representing the "task" attribute of the SedSubTask
   * object to retrieve.
   *
   * @return the first SedSubTask in this SedRepeatedTask based on the given
   * task attribute or NULL if no such SedSubTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSubTask* getSubTaskByTask(const std::string& sid);


  /**
   * Adds a copy of the given SedSubTask to this SedRepeatedTask.
   *
   * @param sst the SedSubTask object to add.
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
   * @see createSubTask()
   * @see getSubTask(const std::string& sid)
   * @see getSubTask(unsigned int n)
   * @see getNumSubTasks()
   * @see removeSubTask(const std::string& sid)
   * @see removeSubTask(unsigned int n)
   */
  int addSubTask(const SedSubTask* sst);


  /**
   * Get the number of SedSubTask objects in this SedRepeatedTask.
   *
   * @return the number of SedSubTask objects in this SedRepeatedTask.
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see getSubTask(const std::string& sid)
   * @see getSubTask(unsigned int n)
   * @see removeSubTask(const std::string& sid)
   * @see removeSubTask(unsigned int n)
   */
  unsigned int getNumSubTasks() const;


  /**
   * Creates a new SedSubTask object, adds it to this SedRepeatedTask object
   * and returns the SedSubTask object created.
   *
   * @return a new SedSubTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see getSubTask(const std::string& sid)
   * @see getSubTask(unsigned int n)
   * @see getNumSubTasks()
   * @see removeSubTask(const std::string& sid)
   * @see removeSubTask(unsigned int n)
   */
  SedSubTask* createSubTask();


  /**
   * Removes the nth SedSubTask from this SedRepeatedTask and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedSubTask to
   * remove.
   *
   * @return a pointer to the nth SedSubTask in this SedRepeatedTask.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see getSubTask(const std::string& sid)
   * @see getSubTask(unsigned int n)
   * @see getNumSubTasks()
   * @see removeSubTask(const std::string& sid)
   */
  SedSubTask* removeSubTask(unsigned int n);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedRepeatedTask object.
   *
   * For SedRepeatedTask, the XML element name is always @c "repeatedTask".
   *
   * @return the name of this element, i.e. @c "repeatedTask".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedRepeatedTask object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_TASK_REPEATEDTASK, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedRepeatedTask object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedRepeatedTask have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedRepeatedTask object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedRepeatedTask have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedRepeatedTask object are:
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
   * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Gets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Predicate returning @c true if this SedRepeatedTask's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedRepeatedTask's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Sets the value of the "attributeName" attribute of this SedRepeatedTask.
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
   * Unsets the value of the "attributeName" attribute of this SedRepeatedTask.
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
 * Creates a new SedRepeatedTask_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedRepeatedTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedRepeatedTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedRepeatedTask_t object.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return a (deep) copy of this SedRepeatedTask_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedRepeatedTask_t*
SedRepeatedTask_clone(const SedRepeatedTask_t* srt);


/**
 * Frees this SedRepeatedTask_t object.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
void
SedRepeatedTask_free(SedRepeatedTask_t* srt);


/**
 * Returns the value of the "range" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure whose range is sought.
 *
 * @return the value of the "range" attribute of this SedRepeatedTask_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
char *
SedRepeatedTask_getRangeId(const SedRepeatedTask_t * srt);


/**
 * Returns the value of the "resetModel" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure whose resetModel is sought.
 *
 * @return the value of the "resetModel" attribute of this SedRepeatedTask_t as
 * a boolean.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_getResetModel(const SedRepeatedTask_t * srt);


/**
 * Returns the value of the "concatenate" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure whose concatenate is sought.
 *
 * @return the value of the "concatenate" attribute of this SedRepeatedTask_t as
 * a boolean.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_getConcatenate(const SedRepeatedTask_t* srt);


/**
 * Predicate returning @c 1 (true) if this SedRepeatedTask_t's "range"
 * attribute is set.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return @c 1 (true) if this SedRepeatedTask_t's "range" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetRangeId(const SedRepeatedTask_t * srt);


/**
 * Predicate returning @c 1 (true) if this SedRepeatedTask_t's "resetModel"
 * attribute is set.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return @c 1 (true) if this SedRepeatedTask_t's "resetModel" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetResetModel(const SedRepeatedTask_t * srt);


/**
 * Predicate returning @c 1 (true) if this SedRepeatedTask_t's "concatenate"
 * attribute is set.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return @c 1 (true) if this SedRepeatedTask_t's "concatenate" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetConcatenate(const SedRepeatedTask_t* srt);


/**
 * Sets the value of the "range" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @param rangeId const char * value of the "range" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setRangeId(SedRepeatedTask_t * srt, const char * rangeId);


/**
 * Sets the value of the "resetModel" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @param resetModel int value of the "resetModel" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setResetModel(SedRepeatedTask_t * srt, int resetModel);


/**
 * Sets the value of the "concatenate" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @param concatenate int value of the "concatenate" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setConcatenate(SedRepeatedTask_t* srt, int concatenate);


/**
 * Unsets the value of the "range" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetRangeId(SedRepeatedTask_t * srt);


/**
 * Unsets the value of the "resetModel" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetResetModel(SedRepeatedTask_t * srt);


/**
 * Unsets the value of the "concatenate" attribute of this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetConcatenate(SedRepeatedTask_t* srt);


/**
 * Returns a ListOf_t * containing SedRange_t objects from this
 * SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure whose SedListOfRanges is sought.
 *
 * @return the SedListOfRanges from this SedRepeatedTask_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedRepeatedTask_addRange()
 * @see SedRepeatedTask_createRange()
 * @see SedRepeatedTask_getRangeById()
 * @see SedRepeatedTask_getRange()
 * @see SedRepeatedTask_getNumRanges()
 * @see SedRepeatedTask_removeRangeById()
 * @see SedRepeatedTask_removeRange()
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedRepeatedTask_getListOfRanges(SedRepeatedTask_t* srt);


/**
 * Get a SedRange_t from the SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedRange_t to
 * retrieve.
 *
 * @return the nth SedRange_t in the SedListOfRanges within this
 * SedRepeatedTask or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedRepeatedTask_getRange(SedRepeatedTask_t* srt, unsigned int n);


/**
 * Get a SedRange_t from the SedRepeatedTask_t based on its identifier.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param sid a string representing the identifier of the SedRange_t to
 * retrieve.
 *
 * @return the SedRange_t in the SedListOfRanges within this SedRepeatedTask
 * with the given @p sid or @c NULL if no such SedRange_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedRepeatedTask_getRangeById(SedRepeatedTask_t* srt, const char *sid);


/**
 * Adds a copy of the given SedRange_t to this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedRange_t should be
 * added.
 *
 * @param sr the SedRange_t object to add.
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
SedRepeatedTask_addRange(SedRepeatedTask_t* srt, const SedRange_t* sr);


/**
 * Get the number of SedRange_t objects in this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to query.
 *
 * @return the number of SedRange_t objects in this SedRepeatedTask_t.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumRanges(SedRepeatedTask_t* srt);


/**
 * Creates a new SedUniformRange_t object, adds it to this SedRepeatedTask_t
 * object and returns the SedUniformRange_t object created.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedUniformRange_t
 * should be added.
 *
 * @return a new SedUniformRange_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedUniformRange_t*
SedRepeatedTask_createUniformRange(SedRepeatedTask_t* srt);


/**
 * Creates a new SedVectorRange_t object, adds it to this SedRepeatedTask_t
 * object and returns the SedVectorRange_t object created.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedVectorRange_t
 * should be added.
 *
 * @return a new SedVectorRange_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedVectorRange_t*
SedRepeatedTask_createVectorRange(SedRepeatedTask_t* srt);


/**
 * Creates a new SedFunctionalRange_t object, adds it to this SedRepeatedTask_t
 * object and returns the SedFunctionalRange_t object created.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedFunctionalRange_t
 * should be added.
 *
 * @return a new SedFunctionalRange_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedFunctionalRange_t*
SedRepeatedTask_createFunctionalRange(SedRepeatedTask_t* srt);


/**
 * Creates a new SedDataRange_t object, adds it to this SedRepeatedTask_t
 * object and returns the SedDataRange_t object created.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedDataRange_t
 * should be added.
 *
 * @return a new SedDataRange_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedDataRange_t*
SedRepeatedTask_createDataRange(SedRepeatedTask_t* srt);


/**
 * Removes the nth SedRange_t from this SedRepeatedTask_t and returns a pointer
 * to it.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedRange_t to remove.
 *
 * @return a pointer to the nth SedRange_t in this SedRepeatedTask_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedRepeatedTask_removeRange(SedRepeatedTask_t* srt, unsigned int n);


/**
 * Removes the SedRange_t from this SedRepeatedTask_t based on its identifier
 * and returns a pointer to it.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param sid a string representing the identifier of the SedRange_t to remove.
 *
 * @return the SedRange_t in this SedRepeatedTask_t based on the identifier or
 * NULL if no such SedRange_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedRepeatedTask_removeRangeById(SedRepeatedTask_t* srt, const char* sid);


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
                                              const char *sid);


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
SedRepeatedTask_getTaskChangeByRange(SedRepeatedTask_t* srt, const char *sid);


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
 * Returns a ListOf_t * containing SedSubTask_t objects from this
 * SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure whose SedListOfSubTasks is
 * sought.
 *
 * @return the SedListOfSubTasks from this SedRepeatedTask_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedRepeatedTask_addSubTask()
 * @see SedRepeatedTask_createSubTask()
 * @see SedRepeatedTask_getSubTaskById()
 * @see SedRepeatedTask_getSubTask()
 * @see SedRepeatedTask_getNumSubTasks()
 * @see SedRepeatedTask_removeSubTaskById()
 * @see SedRepeatedTask_removeSubTask()
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedRepeatedTask_getListOfSubTasks(SedRepeatedTask_t* srt);


/**
 * Get a SedSubTask_t from the SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSubTask_t to
 * retrieve.
 *
 * @return the nth SedSubTask_t in the SedListOfSubTasks within this
 * SedRepeatedTask or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedRepeatedTask_getSubTask(SedRepeatedTask_t* srt, unsigned int n);


/**
 * Get a SedSubTask_t from the SedRepeatedTask_t based on the Task to which it
 * refers.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param sid a string representing the "task" attribute of the SedSubTask_t
 * object to retrieve.
 *
 * @return the first SedSubTask_t in this SedRepeatedTask_t based on the given
 * task attribute or NULL if no such SedSubTask_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedRepeatedTask_getSubTaskByTask(SedRepeatedTask_t* srt, const char *sid);


/**
 * Adds a copy of the given SedSubTask_t to this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedSubTask_t should
 * be added.
 *
 * @param sst the SedSubTask_t object to add.
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
SedRepeatedTask_addSubTask(SedRepeatedTask_t* srt, const SedSubTask_t* sst);


/**
 * Get the number of SedSubTask_t objects in this SedRepeatedTask_t.
 *
 * @param srt the SedRepeatedTask_t structure to query.
 *
 * @return the number of SedSubTask_t objects in this SedRepeatedTask_t.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumSubTasks(SedRepeatedTask_t* srt);


/**
 * Creates a new SedSubTask_t object, adds it to this SedRepeatedTask_t object
 * and returns the SedSubTask_t object created.
 *
 * @param srt the SedRepeatedTask_t structure to which the SedSubTask_t should
 * be added.
 *
 * @return a new SedSubTask_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedRepeatedTask_createSubTask(SedRepeatedTask_t* srt);


/**
 * Removes the nth SedSubTask_t from this SedRepeatedTask_t and returns a
 * pointer to it.
 *
 * @param srt the SedRepeatedTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSubTask_t to
 * remove.
 *
 * @return a pointer to the nth SedSubTask_t in this SedRepeatedTask_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedRepeatedTask_removeSubTask(SedRepeatedTask_t* srt, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedRepeatedTask_t object have been set.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedRepeatedTask_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredAttributes(const SedRepeatedTask_t * srt);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedRepeatedTask_t object have been set.
 *
 * @param srt the SedRepeatedTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedRepeatedTask_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedRepeatedTask_t object are:
 *
 * @memberof SedRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredElements(const SedRepeatedTask_t * srt);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedRepeatedTask_H__ */


