/**
 * @file SedSpecificTimeCourse.h
 * @brief Definition of the SedSpecificTimeCourse class.
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
 * @class SedSpecificTimeCourse
 * @sbmlbrief{sedml} TODO:Definition of the SedSpecificTimeCourse class.
 */


#ifndef SedSpecificTimeCourse_H__
#define SedSpecificTimeCourse_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>
#include <vector>

#include <sedml/SedSimulation.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSpecificTimeCourse : public SedSimulation
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mInitialTime;
  bool mIsSetInitialTime;
  std::string mOutputTimePoints;

  /** @endcond */

public:

  /**
   * Creates a new SedSpecificTimeCourse using the given SEDML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedSpecificTimeCourse.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedSpecificTimeCourse.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSpecificTimeCourse(unsigned int level = SEDML_DEFAULT_LEVEL,
                        unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedSpecificTimeCourse using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSpecificTimeCourse(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedSpecificTimeCourse.
   *
   * @param orig the SedSpecificTimeCourse instance to copy.
   */
  SedSpecificTimeCourse(const SedSpecificTimeCourse& orig);


  /**
   * Assignment operator for SedSpecificTimeCourse.
   *
   * @param rhs the SedSpecificTimeCourse object whose values are to be used as
   * the basis of the assignment.
   */
  SedSpecificTimeCourse& operator=(const SedSpecificTimeCourse& rhs);


  /**
   * Creates and returns a deep copy of this SedSpecificTimeCourse object.
   *
   * @return a (deep) copy of this SedSpecificTimeCourse object.
   */
  virtual SedSpecificTimeCourse* clone() const;


  /**
   * Destructor for SedSpecificTimeCourse.
   */
  virtual ~SedSpecificTimeCourse();


  /**
   * Returns the value of the "initialTime" attribute of this
   * SedSpecificTimeCourse.
   *
   * @return the value of the "initialTime" attribute of this
   * SedSpecificTimeCourse as a double.
   */
  double getInitialTime() const;


  /**
   * Returns the value of the "outputTimePoints" attribute of this
   * SedSpecificTimeCourse.
   *
   * @return the value of the "outputTimePoints" attribute of this
   * SedSpecificTimeCourse as a string.
   */
  const std::string& getOutputTimePoints() const;

  std::vector<double> getOutputTimePointsVector() const;

  /**
   * Predicate returning @c true if this SedSpecificTimeCourse's "initialTime"
   * attribute is set.
   *
   * @return @c true if this SedSpecificTimeCourse's "initialTime" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetInitialTime() const;


  /**
   * Predicate returning @c true if this SedSpecificTimeCourse's
   * "outputTimePoints" attribute is set.
   *
   * @return @c true if this SedSpecificTimeCourse's "outputTimePoints"
   * attribute has been set, otherwise @c false is returned.
   */
  bool isSetOutputTimePoints() const;


  /**
   * Sets the value of the "initialTime" attribute of this
   * SedSpecificTimeCourse.
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
   * Sets the value of the "outputTimePoints" attribute of this
   * SedSpecificTimeCourse.
   *
   * @param outputTimePoints std::string& value of the "outputTimePoints"
   * attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p outputTimePoints = @c NULL or an empty
   * string is equivalent to calling unsetOutputTimePoints().
   */
  int setOutputTimePoints(const std::string& outputTimePoints);

  int setOutputTimePoints(const std::vector<double>& outputTimePoints);

  /**
   * Unsets the value of the "initialTime" attribute of this
   * SedSpecificTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetInitialTime();


  /**
   * Unsets the value of the "outputTimePoints" attribute of this
   * SedSpecificTimeCourse.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOutputTimePoints();


  /**
   * Returns the XML element name of this SedSpecificTimeCourse object.
   *
   * For SedSpecificTimeCourse, the XML element name is always
   * @c "specificTimeCourse".
   *
   * @return the name of this element, i.e. @c "specificTimeCourse".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedSpecificTimeCourse object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   * @sedmlconstant{SEDML_SIMULATION_SPECIFICTIMECOURSE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedSpecificTimeCourse object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedSpecificTimeCourse have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedSpecificTimeCourse object are:
   * @li "initialTime"
   * @li "outputTimePoints"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const;

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
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
   * Predicate returning @c true if this SedSpecificTimeCourse's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedSpecificTimeCourse's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
   * SedSpecificTimeCourse.
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
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedSpecificTimeCourse_t using the given SEDML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedSpecificTimeCourse_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedSpecificTimeCourse_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
SedSpecificTimeCourse_t *
SedSpecificTimeCourse_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedSpecificTimeCourse_t object.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @return a (deep) copy of this SedSpecificTimeCourse_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
SedSpecificTimeCourse_t*
SedSpecificTimeCourse_clone(const SedSpecificTimeCourse_t* sstc);


/**
 * Frees this SedSpecificTimeCourse_t object.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
void
SedSpecificTimeCourse_free(SedSpecificTimeCourse_t* sstc);


/**
 * Returns the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse_t.
 *
 * @param sstc the SedSpecificTimeCourse_t structure whose initialTime is
 * sought.
 *
 * @return the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse_t as a double.
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
double
SedSpecificTimeCourse_getInitialTime(const SedSpecificTimeCourse_t * sstc);


/**
 * Returns the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse_t.
 *
 * @param sstc the SedSpecificTimeCourse_t structure whose outputTimePoints is
 * sought.
 *
 * @return the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
char *
SedSpecificTimeCourse_getOutputTimePoints(const SedSpecificTimeCourse_t *
  sstc);


/**
 * Predicate returning @c 1 (true) if this SedSpecificTimeCourse_t's
 * "initialTime" attribute is set.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedSpecificTimeCourse_t's "initialTime"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_isSetInitialTime(const SedSpecificTimeCourse_t * sstc);


/**
 * Predicate returning @c 1 (true) if this SedSpecificTimeCourse_t's
 * "outputTimePoints" attribute is set.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @return @c 1 (true) if this SedSpecificTimeCourse_t's "outputTimePoints"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_isSetOutputTimePoints(const SedSpecificTimeCourse_t *
  sstc);


/**
 * Sets the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse_t.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @param initialTime double value of the "initialTime" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_setInitialTime(SedSpecificTimeCourse_t * sstc,
                                     double initialTime);


/**
 * Sets the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse_t.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @param outputTimePoints const char * value of the "outputTimePoints"
 * attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p outputTimePoints = @c NULL or an empty string
 * is equivalent to calling SedSpecificTimeCourse_unsetOutputTimePoints().
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_setOutputTimePoints(SedSpecificTimeCourse_t * sstc,
                                          const char * outputTimePoints);


/**
 * Unsets the value of the "initialTime" attribute of this
 * SedSpecificTimeCourse_t.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_unsetInitialTime(SedSpecificTimeCourse_t * sstc);


/**
 * Unsets the value of the "outputTimePoints" attribute of this
 * SedSpecificTimeCourse_t.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_unsetOutputTimePoints(SedSpecificTimeCourse_t * sstc);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSpecificTimeCourse_t object have been set.
 *
 * @param sstc the SedSpecificTimeCourse_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedSpecificTimeCourse_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedSpecificTimeCourse_t object are:
 * @li "initialTime"
 * @li "outputTimePoints"
 *
 * @memberof SedSpecificTimeCourse_t
 */
LIBSEDML_EXTERN
int
SedSpecificTimeCourse_hasRequiredAttributes(const SedSpecificTimeCourse_t *
  sstc);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedSpecificTimeCourse_H__ */


