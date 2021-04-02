/**
 * @file SedListOfSubTasks.h
 * @brief Definition of the SedListOfSubTasks class.
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
 * @class SedListOfSubTasks
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfSubTasks class.
 */


#ifndef SedListOfSubTasks_H__
#define SedListOfSubTasks_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedSubTask.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfSubTasks : public SedListOf
{

public:

  /**
   * Creates a new SedListOfSubTasks using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfSubTasks.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfSubTasks.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSubTasks(unsigned int level = SEDML_DEFAULT_LEVEL,
                    unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfSubTasks using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSubTasks(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfSubTasks.
   *
   * @param orig the SedListOfSubTasks instance to copy.
   */
  SedListOfSubTasks(const SedListOfSubTasks& orig);


  /**
   * Assignment operator for SedListOfSubTasks.
   *
   * @param rhs the SedListOfSubTasks object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfSubTasks& operator=(const SedListOfSubTasks& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfSubTasks object.
   *
   * @return a (deep) copy of this SedListOfSubTasks object.
   */
  virtual SedListOfSubTasks* clone() const;


  /**
   * Destructor for SedListOfSubTasks.
   */
  virtual ~SedListOfSubTasks();

  
  /**
   * Sort the SedListOfSubTasks according to the 'order' attribute.
   * 
   */
  void sort();


  /**
   * Get a SedSubTask from the SedListOfSubTasks.
   *
   * @param n an unsigned int representing the index of the SedSubTask to
   * retrieve.
   *
   * @return the nth SedSubTask in this SedListOfSubTasks or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see get(const std::string& sid)
   * @see getNumSubTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSubTask* get(unsigned int n);


  /**
   * Get a SedSubTask from the SedListOfSubTasks.
   *
   * @param n an unsigned int representing the index of the SedSubTask to
   * retrieve.
   *
   * @return the nth SedSubTask in this SedListOfSubTasks or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see get(const std::string& sid)
   * @see getNumSubTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSubTask* get(unsigned int n) const;


  /**
   * Get a SedSubTask from the SedListOfSubTasks based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSubTask to
   * retrieve.
   *
   * @return the SedSubTask in this SedListOfSubTasks with the given @p sid or
   * @c NULL if no such SedSubTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see get(unsigned int n)
   * @see getNumSubTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSubTask* get(const std::string& sid);


  /**
   * Get a SedSubTask from the SedListOfSubTasks based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSubTask to
   * retrieve.
   *
   * @return the SedSubTask in this SedListOfSubTasks with the given @p sid or
   * @c NULL if no such SedSubTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see get(unsigned int n)
   * @see getNumSubTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSubTask* get(const std::string& sid) const;


  /**
   * Removes the nth SedSubTask from this SedListOfSubTasks and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedSubTask to
   * remove.
   *
   * @return a pointer to the nth SedSubTask in this SedListOfSubTasks.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSubTasks()
   * @see remove(const std::string& sid)
   */
  virtual SedSubTask* remove(unsigned int n);


  /**
   * Removes the SedSubTask from this SedListOfSubTasks based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedSubTask to
   * remove.
   *
   * @return the SedSubTask in this SedListOfSubTasks based on the identifier
   * or NULL if no such SedSubTask exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSubTasks()
   * @see remove(unsigned int n)
   */
  virtual SedSubTask* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedSubTask to this SedListOfSubTasks.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSubTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addSubTask(const SedSubTask* sst);


  /**
   * Get the number of SedSubTask objects in this SedListOfSubTasks.
   *
   * @return the number of SedSubTask objects in this SedListOfSubTasks.
   *
   * @see addSubTask(const SedSubTask* object)
   * @see createSubTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumSubTasks() const;


  /**
   * Creates a new SedSubTask object, adds it to this SedListOfSubTasks object
   * and returns the SedSubTask object created.
   *
   * @return a new SedSubTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubTask(const SedSubTask* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSubTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedSubTask* createSubTask();


  /**
   * Get a SedSubTask from the SedListOfSubTasks based on the Task to which it
   * refers.
   *
   * @param sid a string representing the "task" attribute of the SedSubTask
   * object to retrieve.
   *
   * @return the first SedSubTask in this SedListOfSubTasks based on the given
   * task attribute or NULL if no such SedSubTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSubTask* getByTask(const std::string& sid) const;


  /**
   * Get a SedSubTask from the SedListOfSubTasks based on the Task to which it
   * refers.
   *
   * @param sid a string representing the "task" attribute of the SedSubTask
   * object to retrieve.
   *
   * @return the first SedSubTask in this SedListOfSubTasks based on the given
   * task attribute or NULL if no such SedSubTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSubTask* getByTask(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfSubTasks object.
   *
   * For SedListOfSubTasks, the XML element name is always @c "listOfSubTasks".
   *
   * @return the name of this element, i.e. @c "listOfSubTasks".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfSubTasks object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_LIST_OF, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSEDML type code for the SED-ML objects contained in this
   * SedListOfSubTasks object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfSubTasks:
   * @sedmlconstant{SEDML_TASK_SUBTASK, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new SedSubTask in this SedListOfSubTasks
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedSubTask_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSubTask_t to
 * retrieve.
 *
 * @return the nth SedSubTask_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSubTasks_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedListOfSubTasks_getSubTask(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedSubTask_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSubTask_t to
 * retrieve.
 *
 * @return the SedSubTask_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedSubTask_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSubTasks_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedListOfSubTasks_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedSubTask_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSubTask_t to
 * remove.
 *
 * @return a pointer to the nth SedSubTask_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSubTasks_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedListOfSubTasks_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedSubTask_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSubTask_t to
 * remove.
 *
 * @return the SedSubTask_t in this SedListOf_t based on the identifier or NULL
 * if no such SedSubTask_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSubTasks_t
 */
LIBSEDML_EXTERN
SedSubTask_t*
SedListOfSubTasks_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfSubTasks_H__ */


