/**
 * @file SedListOfTasks.h
 * @brief Definition of the SedListOfTasks class.
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
 * @class SedListOfTasks
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfTasks class.
 */


#ifndef SedListOfTasks_H__
#define SedListOfTasks_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedAbstractTask.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedTask;
class SedRepeatedTask;
class SedParameterEstimationTask;

class LIBSEDML_EXTERN SedListOfTasks : public SedListOf
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedListOfTasks using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfTasks.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfTasks.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfTasks(unsigned int level = SEDML_DEFAULT_LEVEL,
                 unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfTasks using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfTasks(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfTasks.
   *
   * @param orig the SedListOfTasks instance to copy.
   */
  SedListOfTasks(const SedListOfTasks& orig);


  /**
   * Assignment operator for SedListOfTasks.
   *
   * @param rhs the SedListOfTasks object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfTasks& operator=(const SedListOfTasks& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfTasks object.
   *
   * @return a (deep) copy of this SedListOfTasks object.
   */
  virtual SedListOfTasks* clone() const;


  /**
   * Destructor for SedListOfTasks.
   */
  virtual ~SedListOfTasks();


  /**
   * Get a SedAbstractTask from the SedListOfTasks.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * retrieve.
   *
   * @return the nth SedAbstractTask in this SedListOfTasks or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAbstractTask* get(unsigned int n);


  /**
   * Get a SedAbstractTask from the SedListOfTasks.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * retrieve.
   *
   * @return the nth SedAbstractTask in this SedListOfTasks or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAbstractTask* get(unsigned int n) const;


  /**
   * Get a SedAbstractTask from the SedListOfTasks based on its identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * retrieve.
   *
   * @return the SedAbstractTask in this SedListOfTasks with the given @p sid
   * or @c NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAbstractTask* get(const std::string& sid);


  /**
   * Get a SedAbstractTask from the SedListOfTasks based on its identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * retrieve.
   *
   * @return the SedAbstractTask in this SedListOfTasks with the given @p sid
   * or @c NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAbstractTask* get(const std::string& sid) const;


  /**
   * Removes the nth SedAbstractTask from this SedListOfTasks and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * remove.
   *
   * @return a pointer to the nth SedAbstractTask in this SedListOfTasks.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   */
  virtual SedAbstractTask* remove(unsigned int n);


  /**
   * Removes the SedAbstractTask from this SedListOfTasks based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * remove.
   *
   * @return the SedAbstractTask in this SedListOfTasks based on the identifier
   * or NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(unsigned int n)
   */
  virtual SedAbstractTask* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedAbstractTask to this SedListOfTasks.
   *
   * @param sat the SedAbstractTask object to add.
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
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addAbstractTask(const SedAbstractTask* sat);


  /**
   * Get the number of SedAbstractTask objects in this SedListOfTasks.
   *
   * @return the number of SedAbstractTask objects in this SedListOfTasks.
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumAbstractTasks() const;


  /**
   * Creates a new SedTask object, adds it to this SedListOfTasks object and
   * returns the SedTask object created.
   *
   * @return a new SedTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedTask* createTask();


  /**
   * Creates a new SedRepeatedTask object, adds it to this SedListOfTasks
   * object and returns the SedRepeatedTask object created.
   *
   * @return a new SedRepeatedTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedRepeatedTask* createRepeatedTask();


  /**
   * Creates a new SedParameterEstimationTask object, adds it to this
   * SedListOfTasks object and returns the SedParameterEstimationTask object
   * created.
   *
   * @return a new SedParameterEstimationTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedParameterEstimationTask* createParameterEstimationTask();


  /**
   * Returns the XML element name of this SedListOfTasks object.
   *
   * For SedListOfTasks, the XML element name is always
   * @c "listOfAbstractTasks".
   *
   * @return the name of this element, i.e. @c "listOfAbstractTasks".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedListOfTasks object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedListOfTasks object.
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
   * SedListOfTasks object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfTasks:
   * @sedmlconstant{SEDML_SEDML_ABSTRACTTASK, SedTypeCode_t}.
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
   * Creates a new SedAbstractTask in this SedListOfTasks
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * checks concrete types
   */
  virtual bool isValidTypeForList(SedBase* item);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedAbstractTask_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractTask_t to
 * retrieve.
 *
 * @return the nth SedAbstractTask_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfTasks_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfTasks_getAbstractTask(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedAbstractTask_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractTask_t to
 * retrieve.
 *
 * @return the SedAbstractTask_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedAbstractTask_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfTasks_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfTasks_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedAbstractTask_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractTask_t to
 * remove.
 *
 * @return a pointer to the nth SedAbstractTask_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfTasks_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfTasks_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedAbstractTask_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractTask_t to
 * remove.
 *
 * @return the SedAbstractTask_t in this SedListOf_t based on the identifier or
 * NULL if no such SedAbstractTask_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfTasks_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfTasks_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfTasks_H__ */


