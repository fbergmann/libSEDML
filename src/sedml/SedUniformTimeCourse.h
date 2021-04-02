/**
 * @file SedUniformTimeCourse.h
 * @brief Definition of the SedUniformTimeCourse class.
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
 * @class SedUniformTimeCourse
 * @sbmlbrief{sedml} TODO:Definition of the SedUniformTimeCourse class.
 */


#ifndef SedUniformTimeCourse_H__
#define SedUniformTimeCourse_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedSimulation.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedUniformTimeCourse : public SedSimulation
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mInitialTime;
  bool mIsSetInitialTime;
  double mOutputStartTime;
  bool mIsSetOutputStartTime;
  double mOutputEndTime;
  bool mIsSetOutputEndTime;
  int mNumberOfSteps;
  bool mIsSetNumberOfSteps;

  /** @endcond */

public:

  /**
   * Creates a new SedUniformTimeCourse using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedUniformTimeCourse.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedUniformTimeCourse.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedUniformTimeCourse(unsigned int level = SEDML_DEFAULT_LEVEL,
                       unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedUniformTimeCourse using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedUniformTimeCourse(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedUniformTimeCourse.
   *
   * @param orig the SedUniformTimeCourse instance to copy.
   */
  SedUniformTimeCourse(const SedUniformTimeCourse& orig);


  /**
   * Assignment operator for SedUniformTimeCourse.
   *
   * @param rhs the SedUniformTimeCourse object whose values are to be used as
   * the basis of the assignment.
   */
  SedUniformTimeCourse& operator=(const SedUniformTimeCourse& rhs);


  /**
   * Creates and returns a deep copy of this SedUniformTimeCourse object.
   *
   * @return a (deep) copy of this SedUniformTimeCourse object.
   */
  virtual SedUniformTimeCourse* clone() const;


  /**
   * Destructor for SedUniformTimeCourse.
   */
  virtual ~SedUniformTimeCourse();


  /**
   * Returns the value of the "initialTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @return the value of the "initialTime" attribute of this
   * SedUniformTimeCourse as a double.
   */
  double getInitialTime() const;


  /**
   * Returns the value of the "outputStartTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @return the value of the "outputStartTime" attribute of this
   * SedUniformTimeCourse as a double.
   */
  double getOutputStartTime() const;


  /**
   * Returns the value of the "outputEndTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @return the value of the "outputEndTime" attribute of this
   * SedUniformTimeCourse as a double.
   */
  double getOutputEndTime() const;


  /**
   * Returns the value of the "numberOfSteps" attribute of this
   * SedUniformTimeCourse.
   *
   * @return the value of the "numberOfSteps" attribute of this
   * SedUniformTimeCourse as a integer.
   */
  int getNumberOfPoints() const;


  /**
   * Returns the value of the "numberOfSteps" attribute of this
   * SedUniformTimeCourse.
   *
   * @return the value of the "numberOfSteps" attribute of this
   * SedUniformTimeCourse as a integer.
   */
  int getNumberOfSteps() const;


  /**
   * Predicate returning @c true if this SedUniformTimeCourse's "initialTime"
   * attribute is set.
   *
   * @return @c true if this SedUniformTimeCourse's "initialTime" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetInitialTime() const;


  /**
   * Predicate returning @c true if this SedUniformTimeCourse's
   * "outputStartTime" attribute is set.
   *
   * @return @c true if this SedUniformTimeCourse's "outputStartTime" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetOutputStartTime() const;


  /**
   * Predicate returning @c true if this SedUniformTimeCourse's "outputEndTime"
   * attribute is set.
   *
   * @return @c true if this SedUniformTimeCourse's "outputEndTime" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetOutputEndTime() const;


  /**
   * Predicate returning @c true if this SedUniformTimeCourse's
   * "numberOfSteps" attribute is set.
   *
   * @return @c true if this SedUniformTimeCourse's "numberOfSteps" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetNumberOfPoints() const;


  /**
   * Predicate returning @c true if this SedUniformTimeCourse's "numberOfSteps"
   * attribute is set.
   *
   * @return @c true if this SedUniformTimeCourse's "numberOfSteps" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetNumberOfSteps() const;


  /**
   * Sets the value of the "initialTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @param initialTime double value of the "initialTime" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setInitialTime(double initialTime);


  /**
   * Sets the value of the "outputStartTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @param outputStartTime double value of the "outputStartTime" attribute to
   * be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOutputStartTime(double outputStartTime);


  /**
   * Sets the value of the "outputEndTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @param outputEndTime double value of the "outputEndTime" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOutputEndTime(double outputEndTime);


  /**
   * Sets the value of the "numberOfSteps" attribute of this
   * SedUniformTimeCourse.
   *
   * @param numberOfSteps int value of the "numberOfSteps" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumberOfPoints(int numberOfSteps);


  /**
   * Sets the value of the "numberOfSteps" attribute of this
   * SedUniformTimeCourse.
   *
   * @param numberOfSteps int value of the "numberOfSteps" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumberOfSteps(int numberOfSteps);


  /**
   * Unsets the value of the "initialTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetInitialTime();


  /**
   * Unsets the value of the "outputStartTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOutputStartTime();


  /**
   * Unsets the value of the "outputEndTime" attribute of this
   * SedUniformTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOutputEndTime();


  /**
   * Unsets the value of the "numberOfSteps" attribute of this
   * SedUniformTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumberOfPoints();


  /**
   * Unsets the value of the "numberOfSteps" attribute of this
   * SedUniformTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumberOfSteps();


  /**
   * Returns the XML element name of this SedUniformTimeCourse object.
   *
   * For SedUniformTimeCourse, the XML element name is always
   * @c "uniformTimeCourse".
   *
   * @return the name of this element, i.e. @c "uniformTimeCourse".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedUniformTimeCourse object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_SIMULATION_UNIFORMTIMECOURSE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedUniformTimeCourse object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedUniformTimeCourse have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedUniformTimeCourse object are:
   * @li "initialTime"
   * @li "outputStartTime"
   * @li "outputEndTime"
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
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
   * Predicate returning @c true if this SedUniformTimeCourse's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedUniformTimeCourse's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
   * SedUniformTimeCourse.
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
 * Creates a new SedUniformTimeCourse_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedUniformTimeCourse_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedUniformTimeCourse_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
SedUniformTimeCourse_t *
SedUniformTimeCourse_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedUniformTimeCourse_t object.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @return a (deep) copy of this SedUniformTimeCourse_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
SedUniformTimeCourse_t*
SedUniformTimeCourse_clone(const SedUniformTimeCourse_t* sutc);


/**
 * Frees this SedUniformTimeCourse_t object.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
void
SedUniformTimeCourse_free(SedUniformTimeCourse_t* sutc);


/**
 * Returns the value of the "initialTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure whose initialTime is
 * sought.
 *
 * @return the value of the "initialTime" attribute of this
 * SedUniformTimeCourse_t as a double.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
double
SedUniformTimeCourse_getInitialTime(const SedUniformTimeCourse_t * sutc);


/**
 * Returns the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure whose outputStartTime is
 * sought.
 *
 * @return the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse_t as a double.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
double
SedUniformTimeCourse_getOutputStartTime(const SedUniformTimeCourse_t * sutc);


/**
 * Returns the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure whose outputEndTime is
 * sought.
 *
 * @return the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse_t as a double.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
double
SedUniformTimeCourse_getOutputEndTime(const SedUniformTimeCourse_t * sutc);


/**
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure whose numberOfSteps is
 * sought.
 *
 * @return the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t as a integer.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_getNumberOfPoints(const SedUniformTimeCourse_t * sutc);


/**
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure whose numberOfSteps is
 * sought.
 *
 * @return the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t as a integer.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_getNumberOfSteps(const SedUniformTimeCourse_t * sutc);


/**
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "initialTime" attribute is set.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedUniformTimeCourse_t's "initialTime" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetInitialTime(const SedUniformTimeCourse_t * sutc);


/**
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "outputStartTime" attribute is set.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedUniformTimeCourse_t's "outputStartTime"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetOutputStartTime(const SedUniformTimeCourse_t * sutc);


/**
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "outputEndTime" attribute is set.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedUniformTimeCourse_t's "outputEndTime"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetOutputEndTime(const SedUniformTimeCourse_t * sutc);


/**
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "numberOfSteps" attribute is set.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedUniformTimeCourse_t's "numberOfSteps"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetNumberOfPoints(const SedUniformTimeCourse_t * sutc);


/**
 * Predicate returning @c 1 (true) if this SedUniformTimeCourse_t's
 * "numberOfSteps" attribute is set.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedUniformTimeCourse_t's "numberOfSteps"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetNumberOfSteps(const SedUniformTimeCourse_t * sutc);


/**
 * Sets the value of the "initialTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @param initialTime double value of the "initialTime" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setInitialTime(SedUniformTimeCourse_t * sutc,
                                    double initialTime);


/**
 * Sets the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @param outputStartTime double value of the "outputStartTime" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setOutputStartTime(SedUniformTimeCourse_t * sutc,
                                        double outputStartTime);


/**
 * Sets the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @param outputEndTime double value of the "outputEndTime" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setOutputEndTime(SedUniformTimeCourse_t * sutc,
                                      double outputEndTime);


/**
 * Sets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @param numberOfSteps int value of the "numberOfSteps" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setNumberOfPoints(SedUniformTimeCourse_t * sutc,
                                       int numberOfSteps);


/**
 * Sets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @param numberOfSteps int value of the "numberOfSteps" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setNumberOfSteps(SedUniformTimeCourse_t * sutc,
                                      int numberOfSteps);


/**
 * Unsets the value of the "initialTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetInitialTime(SedUniformTimeCourse_t * sutc);


/**
 * Unsets the value of the "outputStartTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetOutputStartTime(SedUniformTimeCourse_t * sutc);


/**
 * Unsets the value of the "outputEndTime" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetOutputEndTime(SedUniformTimeCourse_t * sutc);


/**
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetNumberOfPoints(SedUniformTimeCourse_t * sutc);


/**
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformTimeCourse_t.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetNumberOfSteps(SedUniformTimeCourse_t * sutc);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedUniformTimeCourse_t object have been set.
 *
 * @param sutc the SedUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedUniformTimeCourse_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedUniformTimeCourse_t object are:
 * @li "initialTime"
 * @li "outputStartTime"
 * @li "outputEndTime"
 *
 * @memberof SedUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_hasRequiredAttributes(const SedUniformTimeCourse_t *
  sutc);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedUniformTimeCourse_H__ */


