/**
 * @file SedSimpleRepeatedTask.h
 * @brief Definition of the SedSimpleRepeatedTask class.
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
 * @class SedSimpleRepeatedTask
 * @sbmlbrief{sedml} TODO:Definition of the SedSimpleRepeatedTask class.
 */


#ifndef SedSimpleRepeatedTask_H__
#define SedSimpleRepeatedTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedTask.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSimpleRepeatedTask : public SedTask
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  bool mResetModel;
  bool mIsSetResetModel;
  int mNumRepeats;
  bool mIsSetNumRepeats;

  /** @endcond */

public:

  /**
   * Creates a new SedSimpleRepeatedTask using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedSimpleRepeatedTask.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedSimpleRepeatedTask.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSimpleRepeatedTask(unsigned int level = SEDML_DEFAULT_LEVEL,
                        unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedSimpleRepeatedTask using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSimpleRepeatedTask(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedSimpleRepeatedTask.
   *
   * @param orig the SedSimpleRepeatedTask instance to copy.
   */
  SedSimpleRepeatedTask(const SedSimpleRepeatedTask& orig);


  /**
   * Assignment operator for SedSimpleRepeatedTask.
   *
   * @param rhs the SedSimpleRepeatedTask object whose values are to be used as
   * the basis of the assignment.
   */
  SedSimpleRepeatedTask& operator=(const SedSimpleRepeatedTask& rhs);


  /**
   * Creates and returns a deep copy of this SedSimpleRepeatedTask object.
   *
   * @return a (deep) copy of this SedSimpleRepeatedTask object.
   */
  virtual SedSimpleRepeatedTask* clone() const;


  /**
   * Destructor for SedSimpleRepeatedTask.
   */
  virtual ~SedSimpleRepeatedTask();


  /**
   * Returns the value of the "resetModel" attribute of this
   * SedSimpleRepeatedTask.
   *
   * @return the value of the "resetModel" attribute of this
   * SedSimpleRepeatedTask as a boolean.
   */
  bool getResetModel() const;


  /**
   * Returns the value of the "numRepeats" attribute of this
   * SedSimpleRepeatedTask.
   *
   * @return the value of the "numRepeats" attribute of this
   * SedSimpleRepeatedTask as a integer.
   */
  int getNumRepeats() const;


  /**
   * Predicate returning @c true if this SedSimpleRepeatedTask's "resetModel"
   * attribute is set.
   *
   * @return @c true if this SedSimpleRepeatedTask's "resetModel" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetResetModel() const;


  /**
   * Predicate returning @c true if this SedSimpleRepeatedTask's "numRepeats"
   * attribute is set.
   *
   * @return @c true if this SedSimpleRepeatedTask's "numRepeats" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetNumRepeats() const;


  /**
   * Sets the value of the "resetModel" attribute of this
   * SedSimpleRepeatedTask.
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
   * Sets the value of the "numRepeats" attribute of this
   * SedSimpleRepeatedTask.
   *
   * @param numRepeats int value of the "numRepeats" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumRepeats(int numRepeats);


  /**
   * Unsets the value of the "resetModel" attribute of this
   * SedSimpleRepeatedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetResetModel();


  /**
   * Unsets the value of the "numRepeats" attribute of this
   * SedSimpleRepeatedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumRepeats();


  /**
   * Returns the XML element name of this SedSimpleRepeatedTask object.
   *
   * For SedSimpleRepeatedTask, the XML element name is always
   * @c "simpleRepeatedTask".
   *
   * @return the name of this element, i.e. @c "simpleRepeatedTask".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedSimpleRepeatedTask object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_TASK_SIMPLEREPEATEDTASK, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedSimpleRepeatedTask object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedSimpleRepeatedTask have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedSimpleRepeatedTask object are:
   * @li "resetModel"
   * @li "numRepeats"
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
   * Gets the value of the "attributeName" attribute of this
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
   * Predicate returning @c true if this SedSimpleRepeatedTask's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedSimpleRepeatedTask's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
   * SedSimpleRepeatedTask.
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
 * Creates a new SedSimpleRepeatedTask_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedSimpleRepeatedTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedSimpleRepeatedTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSimpleRepeatedTask_t *
SedSimpleRepeatedTask_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedSimpleRepeatedTask_t object.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @return a (deep) copy of this SedSimpleRepeatedTask_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
SedSimpleRepeatedTask_t*
SedSimpleRepeatedTask_clone(const SedSimpleRepeatedTask_t* ssrt);


/**
 * Frees this SedSimpleRepeatedTask_t object.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
void
SedSimpleRepeatedTask_free(SedSimpleRepeatedTask_t* ssrt);


/**
 * Returns the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask_t.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure whose resetModel is
 * sought.
 *
 * @return the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask_t as a boolean.
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_getResetModel(const SedSimpleRepeatedTask_t * ssrt);


/**
 * Returns the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask_t.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure whose numRepeats is
 * sought.
 *
 * @return the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask_t as a integer.
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_getNumRepeats(const SedSimpleRepeatedTask_t * ssrt);


/**
 * Predicate returning @c 1 (true) if this SedSimpleRepeatedTask_t's
 * "resetModel" attribute is set.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @return @c 1 (true) if this SedSimpleRepeatedTask_t's "resetModel" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_isSetResetModel(const SedSimpleRepeatedTask_t * ssrt);


/**
 * Predicate returning @c 1 (true) if this SedSimpleRepeatedTask_t's
 * "numRepeats" attribute is set.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @return @c 1 (true) if this SedSimpleRepeatedTask_t's "numRepeats" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_isSetNumRepeats(const SedSimpleRepeatedTask_t * ssrt);


/**
 * Sets the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask_t.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @param resetModel int value of the "resetModel" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_setResetModel(SedSimpleRepeatedTask_t * ssrt,
                                    int resetModel);


/**
 * Sets the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask_t.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @param numRepeats int value of the "numRepeats" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_setNumRepeats(SedSimpleRepeatedTask_t * ssrt,
                                    int numRepeats);


/**
 * Unsets the value of the "resetModel" attribute of this
 * SedSimpleRepeatedTask_t.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_unsetResetModel(SedSimpleRepeatedTask_t * ssrt);


/**
 * Unsets the value of the "numRepeats" attribute of this
 * SedSimpleRepeatedTask_t.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_unsetNumRepeats(SedSimpleRepeatedTask_t * ssrt);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSimpleRepeatedTask_t object have been set.
 *
 * @param ssrt the SedSimpleRepeatedTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedSimpleRepeatedTask_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedSimpleRepeatedTask_t object are:
 * @li "resetModel"
 * @li "numRepeats"
 *
 * @memberof SedSimpleRepeatedTask_t
 */
LIBSEDML_EXTERN
int
SedSimpleRepeatedTask_hasRequiredAttributes(const SedSimpleRepeatedTask_t *
  ssrt);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedSimpleRepeatedTask_H__ */


