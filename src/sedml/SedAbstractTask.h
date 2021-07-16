/**
 * @file SedAbstractTask.h
 * @brief Definition of the SedAbstractTask class.
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
 * @class SedAbstractTask
 * @sbmlbrief{sedml} TODO:Definition of the SedAbstractTask class.
 */


#ifndef SedAbstractTask_H__
#define SedAbstractTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedTask;
class SedRepeatedTask;
class SedParameterEstimationTask;

class LIBSEDML_EXTERN SedAbstractTask : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedAbstractTask using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedAbstractTask.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedAbstractTask.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAbstractTask(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedAbstractTask using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAbstractTask(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedAbstractTask.
   *
   * @param orig the SedAbstractTask instance to copy.
   */
  SedAbstractTask(const SedAbstractTask& orig);


  /**
   * Assignment operator for SedAbstractTask.
   *
   * @param rhs the SedAbstractTask object whose values are to be used as the
   * basis of the assignment.
   */
  SedAbstractTask& operator=(const SedAbstractTask& rhs);


  /**
   * Creates and returns a deep copy of this SedAbstractTask object.
   *
   * @return a (deep) copy of this SedAbstractTask object.
   */
  virtual SedAbstractTask* clone() const;


  /**
   * Destructor for SedAbstractTask.
   */
  virtual ~SedAbstractTask();



  /**
   * Predicate returning @c true if this abstract "SedAbstractTask" is of type
   * SedTask
   *
   * @return @c true if this abstract "SedAbstractTask" is of type SedTask,
   * @c false otherwise
   */
  virtual bool isSedTask() const;


  /**
   * Predicate returning @c true if this abstract "SedAbstractTask" is of type
   * SedRepeatedTask
   *
   * @return @c true if this abstract "SedAbstractTask" is of type
   * SedRepeatedTask, @c false otherwise
   */
  virtual bool isSedRepeatedTask() const;


  /**
   * Predicate returning @c true if this abstract "SedAbstractTask" is of type
   * SedParameterEstimationTask
   *
   * @return @c true if this abstract "SedAbstractTask" is of type
   * SedParameterEstimationTask, @c false otherwise
   */
  virtual bool isSedParameterEstimationTask() const;


  /**
   * Returns the XML element name of this SedAbstractTask object.
   *
   * For SedAbstractTask, the XML element name is always @c "task".
   *
   * @return the name of this element, i.e. @c "task".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedAbstractTask object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedAbstractTask object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_SEDML_ABSTRACTTASK, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedAbstractTask object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedAbstractTask have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedAbstractTask object are:
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




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Predicate returning @c true if this SedAbstractTask's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedAbstractTask's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Unsets the value of the "attributeName" attribute of this SedAbstractTask.
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
 * Creates a new SedTask using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAbstractTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAbstractTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedTask_t *
SedAbstractTask_createTask(unsigned int level, unsigned int version);


/**
 * Creates a new SedRepeatedTask using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAbstractTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAbstractTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedAbstractTask_createRepeatedTask(unsigned int level, unsigned int version);


/**
 * Creates a new SedParameterEstimationTask using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAbstractTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAbstractTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t *
SedAbstractTask_createParameterEstimationTask(unsigned int level,
                                              unsigned int version);


/**
 * Creates and returns a deep copy of this SedAbstractTask_t object.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return a (deep) copy of this SedAbstractTask_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedAbstractTask_clone(const SedAbstractTask_t* sat);


/**
 * Frees this SedAbstractTask_t object.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
void
SedAbstractTask_free(SedAbstractTask_t* sat);


/**
 * Returns the value of the "id" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedAbstractTask_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
char *
SedAbstractTask_getId(const SedAbstractTask_t * sat);


/**
 * Returns the value of the "name" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedAbstractTask_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
char *
SedAbstractTask_getName(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 (true) if this SedAbstractTask_t's "id" attribute
 * is set.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 (true) if this SedAbstractTask_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSetId(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 (true) if this SedAbstractTask_t's "name" attribute
 * is set.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 (true) if this SedAbstractTask_t's "name" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSetName(const SedAbstractTask_t * sat);


/**
 * Sets the value of the "id" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure.
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
 * to calling SedAbstractTask_unsetId().
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_setId(SedAbstractTask_t * sat, const char * id);


/**
 * Sets the value of the "name" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedAbstractTask_unsetName().
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_setName(SedAbstractTask_t * sat, const char * name);


/**
 * Unsets the value of the "id" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_unsetId(SedAbstractTask_t * sat);


/**
 * Unsets the value of the "name" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_unsetName(SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 if this SedAbstractTask_t is of type SedTask_t
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 if this SedAbstractTask_t is of type SedTask_t, @c 0 otherwise
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedTask(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 if this SedAbstractTask_t is of type
 * SedRepeatedTask_t
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 if this SedAbstractTask_t is of type SedRepeatedTask_t, @c 0
 * otherwise
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedRepeatedTask(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 if this SedAbstractTask_t is of type
 * SedParameterEstimationTask_t
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 if this SedAbstractTask_t is of type
 * SedParameterEstimationTask_t, @c 0 otherwise
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedParameterEstimationTask(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAbstractTask_t object have been set.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedAbstractTask_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedAbstractTask_t object are:
 * @li "id"
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_hasRequiredAttributes(const SedAbstractTask_t * sat);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedAbstractTask_H__ */


