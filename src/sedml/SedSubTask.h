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
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSubTask : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  int mOrder;
  bool mIsSetOrder;
  std::string mTask;

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




  #endif /* !SWIG */


protected:


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


