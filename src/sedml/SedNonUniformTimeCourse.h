/**
 * @file SedNonUniformTimeCourse.h
 * @brief Definition of the SedNonUniformTimeCourse class.
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
 * @class SedNonUniformTimeCourse
 * @sbmlbrief{sedml} TODO:Definition of the SedNonUniformTimeCourse class.
 */


#ifndef SedNonUniformTimeCourse_H__
#define SedNonUniformTimeCourse_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedSimulation.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedNonUniformTimeCourse : public SedSimulation
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mInitialTime;
  bool mIsSetInitialTime;
  double mOutputStartTime;
  bool mIsSetOutputStartTime;
  double mOutputEndTime;
  bool mIsSetOutputEndTime;

  /** @endcond */

public:

  /**
   * Creates a new SedNonUniformTimeCourse using the given SEDML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedNonUniformTimeCourse.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedNonUniformTimeCourse.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedNonUniformTimeCourse(unsigned int level = SEDML_DEFAULT_LEVEL,
                          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedNonUniformTimeCourse using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedNonUniformTimeCourse(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedNonUniformTimeCourse.
   *
   * @param orig the SedNonUniformTimeCourse instance to copy.
   */
  SedNonUniformTimeCourse(const SedNonUniformTimeCourse& orig);


  /**
   * Assignment operator for SedNonUniformTimeCourse.
   *
   * @param rhs the SedNonUniformTimeCourse object whose values are to be used
   * as the basis of the assignment.
   */
  SedNonUniformTimeCourse& operator=(const SedNonUniformTimeCourse& rhs);


  /**
   * Creates and returns a deep copy of this SedNonUniformTimeCourse object.
   *
   * @return a (deep) copy of this SedNonUniformTimeCourse object.
   */
  virtual SedNonUniformTimeCourse* clone() const;


  /**
   * Destructor for SedNonUniformTimeCourse.
   */
  virtual ~SedNonUniformTimeCourse();


  /**
   * Returns the value of the "initialTime" attribute of this
   * SedNonUniformTimeCourse.
   *
   * @return the value of the "initialTime" attribute of this
   * SedNonUniformTimeCourse as a double.
   */
  double getInitialTime() const;


  /**
   * Returns the value of the "outputStartTime" attribute of this
   * SedNonUniformTimeCourse.
   *
   * @return the value of the "outputStartTime" attribute of this
   * SedNonUniformTimeCourse as a double.
   */
  double getOutputStartTime() const;


  /**
   * Returns the value of the "outputEndTime" attribute of this
   * SedNonUniformTimeCourse.
   *
   * @return the value of the "outputEndTime" attribute of this
   * SedNonUniformTimeCourse as a double.
   */
  double getOutputEndTime() const;


  /**
   * Predicate returning @c true if this SedNonUniformTimeCourse's
   * "initialTime" attribute is set.
   *
   * @return @c true if this SedNonUniformTimeCourse's "initialTime" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetInitialTime() const;


  /**
   * Predicate returning @c true if this SedNonUniformTimeCourse's
   * "outputStartTime" attribute is set.
   *
   * @return @c true if this SedNonUniformTimeCourse's "outputStartTime"
   * attribute has been set, otherwise @c false is returned.
   */
  bool isSetOutputStartTime() const;


  /**
   * Predicate returning @c true if this SedNonUniformTimeCourse's
   * "outputEndTime" attribute is set.
   *
   * @return @c true if this SedNonUniformTimeCourse's "outputEndTime"
   * attribute has been set, otherwise @c false is returned.
   */
  bool isSetOutputEndTime() const;


  /**
   * Sets the value of the "initialTime" attribute of this
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * Unsets the value of the "initialTime" attribute of this
   * SedNonUniformTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetInitialTime();


  /**
   * Unsets the value of the "outputStartTime" attribute of this
   * SedNonUniformTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOutputStartTime();


  /**
   * Unsets the value of the "outputEndTime" attribute of this
   * SedNonUniformTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOutputEndTime();


  /**
   * Returns the XML element name of this SedNonUniformTimeCourse object.
   *
   * For SedNonUniformTimeCourse, the XML element name is always
   * @c "nonUniformTimeCourse".
   *
   * @return the name of this element, i.e. @c "nonUniformTimeCourse".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedNonUniformTimeCourse object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   * @sedmlconstant{SEDML_SIMULATION_NONUNIFORMTIMECOURSE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedNonUniformTimeCourse object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedNonUniformTimeCourse have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedNonUniformTimeCourse object are:
   * @li "initialTime"
   * @li "outputStartTime"
   * @li "outputEndTime"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * Predicate returning @c true if this SedNonUniformTimeCourse's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedNonUniformTimeCourse's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
   * SedNonUniformTimeCourse.
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
  virtual SedBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedNonUniformTimeCourse_t using the given SEDML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedNonUniformTimeCourse_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedNonUniformTimeCourse_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
SedNonUniformTimeCourse_t *
SedNonUniformTimeCourse_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedNonUniformTimeCourse_t object.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @return a (deep) copy of this SedNonUniformTimeCourse_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
SedNonUniformTimeCourse_t*
SedNonUniformTimeCourse_clone(const SedNonUniformTimeCourse_t* snutc);


/**
 * Frees this SedNonUniformTimeCourse_t object.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
void
SedNonUniformTimeCourse_free(SedNonUniformTimeCourse_t* snutc);


/**
 * Returns the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure whose initialTime is
 * sought.
 *
 * @return the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse_t as a double.
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
double
SedNonUniformTimeCourse_getInitialTime(const SedNonUniformTimeCourse_t *
  snutc);


/**
 * Returns the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure whose outputStartTime
 * is sought.
 *
 * @return the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse_t as a double.
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
double
SedNonUniformTimeCourse_getOutputStartTime(const SedNonUniformTimeCourse_t *
  snutc);


/**
 * Returns the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure whose outputEndTime is
 * sought.
 *
 * @return the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse_t as a double.
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
double
SedNonUniformTimeCourse_getOutputEndTime(const SedNonUniformTimeCourse_t *
  snutc);


/**
 * Predicate returning @c 1 (true) if this SedNonUniformTimeCourse_t's
 * "initialTime" attribute is set.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedNonUniformTimeCourse_t's "initialTime"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_isSetInitialTime(const SedNonUniformTimeCourse_t *
  snutc);


/**
 * Predicate returning @c 1 (true) if this SedNonUniformTimeCourse_t's
 * "outputStartTime" attribute is set.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedNonUniformTimeCourse_t's "outputStartTime"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_isSetOutputStartTime(const SedNonUniformTimeCourse_t *
  snutc);


/**
 * Predicate returning @c 1 (true) if this SedNonUniformTimeCourse_t's
 * "outputEndTime" attribute is set.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedNonUniformTimeCourse_t's "outputEndTime"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_isSetOutputEndTime(const SedNonUniformTimeCourse_t *
  snutc);


/**
 * Sets the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @param initialTime double value of the "initialTime" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_setInitialTime(SedNonUniformTimeCourse_t * snutc,
                                       double initialTime);


/**
 * Sets the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
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
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_setOutputStartTime(SedNonUniformTimeCourse_t * snutc,
                                           double outputStartTime);


/**
 * Sets the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
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
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_setOutputEndTime(SedNonUniformTimeCourse_t * snutc,
                                         double outputEndTime);


/**
 * Unsets the value of the "initialTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_unsetInitialTime(SedNonUniformTimeCourse_t * snutc);


/**
 * Unsets the value of the "outputStartTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_unsetOutputStartTime(SedNonUniformTimeCourse_t *
  snutc);


/**
 * Unsets the value of the "outputEndTime" attribute of this
 * SedNonUniformTimeCourse_t.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_unsetOutputEndTime(SedNonUniformTimeCourse_t * snutc);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedNonUniformTimeCourse_t object have been set.
 *
 * @param snutc the SedNonUniformTimeCourse_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedNonUniformTimeCourse_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedNonUniformTimeCourse_t object are:
 * @li "initialTime"
 * @li "outputStartTime"
 * @li "outputEndTime"
 *
 * @memberof SedNonUniformTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedNonUniformTimeCourse_hasRequiredAttributes(const SedNonUniformTimeCourse_t *
  snutc);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedNonUniformTimeCourse_H__ */


