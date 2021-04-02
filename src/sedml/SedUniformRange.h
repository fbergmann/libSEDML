/**
 * @file SedUniformRange.h
 * @brief Definition of the SedUniformRange class.
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
 * @class SedUniformRange
 * @sbmlbrief{sedml} TODO:Definition of the SedUniformRange class.
 */


#ifndef SedUniformRange_H__
#define SedUniformRange_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedRange.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedUniformRange : public SedRange
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mStart;
  bool mIsSetStart;
  double mEnd;
  bool mIsSetEnd;
  int mNumberOfSteps;
  bool mIsSetNumberOfSteps;
  std::string mType;

  /** @endcond */

public:

  /**
   * Creates a new SedUniformRange using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedUniformRange.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedUniformRange.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedUniformRange(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedUniformRange using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedUniformRange(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedUniformRange.
   *
   * @param orig the SedUniformRange instance to copy.
   */
  SedUniformRange(const SedUniformRange& orig);


  /**
   * Assignment operator for SedUniformRange.
   *
   * @param rhs the SedUniformRange object whose values are to be used as the
   * basis of the assignment.
   */
  SedUniformRange& operator=(const SedUniformRange& rhs);


  /**
   * Creates and returns a deep copy of this SedUniformRange object.
   *
   * @return a (deep) copy of this SedUniformRange object.
   */
  virtual SedUniformRange* clone() const;


  /**
   * Destructor for SedUniformRange.
   */
  virtual ~SedUniformRange();


  /**
   * Returns the value of the "start" attribute of this SedUniformRange.
   *
   * @return the value of the "start" attribute of this SedUniformRange as a
   * double.
   */
  double getStart() const;


  /**
   * Returns the value of the "end" attribute of this SedUniformRange.
   *
   * @return the value of the "end" attribute of this SedUniformRange as a
   * double.
   */
  double getEnd() const;


  /**
   * Returns the value of the "numberOfSteps" attribute of this
   * SedUniformRange.
   *
   * @return the value of the "numberOfSteps" attribute of this
   * SedUniformRange as a integer.
   */
  int getNumberOfPoints() const;


  /**
   * Returns the value of the "numberOfSteps" attribute of this
   * SedUniformRange.
   *
   * @return the value of the "numberOfSteps" attribute of this
   * SedUniformRange as a integer.
   */
  int getNumberOfSteps() const;


  /**
   * Returns the value of the "type" attribute of this SedUniformRange.
   *
   * @return the value of the "type" attribute of this SedUniformRange as a
   * string.
   */
  const std::string& getType() const;


  /**
   * Predicate returning @c true if this SedUniformRange's "start" attribute is
   * set.
   *
   * @return @c true if this SedUniformRange's "start" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetStart() const;


  /**
   * Predicate returning @c true if this SedUniformRange's "end" attribute is
   * set.
   *
   * @return @c true if this SedUniformRange's "end" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetEnd() const;


  /**
   * Predicate returning @c true if this SedUniformRange's "numberOfSteps"
   * attribute is set.
   *
   * @return @c true if this SedUniformRange's "numberOfSteps" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetNumberOfPoints() const;


  /**
   * Predicate returning @c true if this SedUniformRange's "numberOfSteps"
   * attribute is set.
   *
   * @return @c true if this SedUniformRange's "numberOfSteps" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetNumberOfSteps() const;


  /**
   * Predicate returning @c true if this SedUniformRange's "type" attribute is
   * set.
   *
   * @return @c true if this SedUniformRange's "type" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetType() const;


  /**
   * Sets the value of the "start" attribute of this SedUniformRange.
   *
   * @param start double value of the "start" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStart(double start);


  /**
   * Sets the value of the "end" attribute of this SedUniformRange.
   *
   * @param end double value of the "end" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setEnd(double end);


  /**
   * Sets the value of the "numberOfSteps" attribute of this SedUniformRange.
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
   * Sets the value of the "numberOfSteps" attribute of this SedUniformRange.
   *
   * @param numberOfSteps int value of the "numberOfSteps" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumberOfSteps(int numberOfSteps);


  /**
   * Sets the value of the "type" attribute of this SedUniformRange.
   *
   * @param type std::string& value of the "type" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p type = @c NULL or an empty string is
   * equivalent to calling unsetType().
   */
  int setType(const std::string& type);


  /**
   * Unsets the value of the "start" attribute of this SedUniformRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStart();


  /**
   * Unsets the value of the "end" attribute of this SedUniformRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetEnd();


  /**
   * Unsets the value of the "numberOfSteps" attribute of this
   * SedUniformRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumberOfPoints();


  /**
   * Unsets the value of the "numberOfSteps" attribute of this
   * SedUniformRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumberOfSteps();


  /**
   * Unsets the value of the "type" attribute of this SedUniformRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetType();


  /**
   * Returns the XML element name of this SedUniformRange object.
   *
   * For SedUniformRange, the XML element name is always @c "uniformRange".
   *
   * @return the name of this element, i.e. @c "uniformRange".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedUniformRange object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_RANGE_UNIFORMRANGE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedUniformRange object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedUniformRange have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedUniformRange object are:
   * @li "start"
   * @li "end"
   * @li "numberOfSteps"
   * @li "type"
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
   * Gets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Gets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Gets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Gets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Gets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Predicate returning @c true if this SedUniformRange's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedUniformRange's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Sets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Sets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Sets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Sets the value of the "attributeName" attribute of this SedUniformRange.
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
   * Unsets the value of the "attributeName" attribute of this SedUniformRange.
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
 * Creates a new SedUniformRange_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedUniformRange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedUniformRange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
SedUniformRange_t *
SedUniformRange_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedUniformRange_t object.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @return a (deep) copy of this SedUniformRange_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
SedUniformRange_t*
SedUniformRange_clone(const SedUniformRange_t* sur);


/**
 * Frees this SedUniformRange_t object.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
void
SedUniformRange_free(SedUniformRange_t* sur);


/**
 * Returns the value of the "start" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure whose start is sought.
 *
 * @return the value of the "start" attribute of this SedUniformRange_t as a
 * double.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
double
SedUniformRange_getStart(const SedUniformRange_t * sur);


/**
 * Returns the value of the "end" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure whose end is sought.
 *
 * @return the value of the "end" attribute of this SedUniformRange_t as a
 * double.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
double
SedUniformRange_getEnd(const SedUniformRange_t * sur);


/**
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure whose numberOfSteps is sought.
 *
 * @return the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t as a integer.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_getNumberOfPoints(const SedUniformRange_t * sur);


/**
 * Returns the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure whose numberOfSteps is sought.
 *
 * @return the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t as a integer.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_getNumberOfSteps(const SedUniformRange_t* sur);


/**
 * Returns the value of the "type" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedUniformRange_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
char *
SedUniformRange_getType(const SedUniformRange_t * sur);


/**
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "start"
 * attribute is set.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @return @c 1 (true) if this SedUniformRange_t's "start" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetStart(const SedUniformRange_t * sur);


/**
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "end" attribute
 * is set.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @return @c 1 (true) if this SedUniformRange_t's "end" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetEnd(const SedUniformRange_t * sur);


/**
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "numberOfSteps"
 * attribute is set.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @return @c 1 (true) if this SedUniformRange_t's "numberOfSteps" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetNumberOfPoints(const SedUniformRange_t * sur);


/**
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "numberOfSteps"
 * attribute is set.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @return @c 1 (true) if this SedUniformRange_t's "numberOfSteps" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetNumberOfSteps(const SedUniformRange_t* sur);


/**
 * Predicate returning @c 1 (true) if this SedUniformRange_t's "type" attribute
 * is set.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @return @c 1 (true) if this SedUniformRange_t's "type" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetType(const SedUniformRange_t * sur);


/**
 * Sets the value of the "start" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @param start double value of the "start" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_setStart(SedUniformRange_t * sur, double start);


/**
 * Sets the value of the "end" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @param end double value of the "end" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_setEnd(SedUniformRange_t * sur, double end);


/**
 * Sets the value of the "numberOfSteps" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @param numberOfSteps int value of the "numberOfSteps" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_setNumberOfPoints(SedUniformRange_t * sur,
                                  int numberOfSteps);


/**
 * Sets the value of the "numberOfSteps" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @param numberOfSteps int value of the "numberOfSteps" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_setNumberOfSteps(SedUniformRange_t* sur,
    int numberOfSteps);


/**
 * Sets the value of the "type" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @param type const char * value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p type = @c NULL or an empty string is
 * equivalent to calling SedUniformRange_unsetType().
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_setType(SedUniformRange_t * sur, const char * type);


/**
 * Unsets the value of the "start" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetStart(SedUniformRange_t * sur);


/**
 * Unsets the value of the "end" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetEnd(SedUniformRange_t * sur);


/**
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetNumberOfPoints(SedUniformRange_t * sur);


/**
 * Unsets the value of the "numberOfSteps" attribute of this
 * SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetNumberOfSteps(SedUniformRange_t* sur);


/**
 * Unsets the value of the "type" attribute of this SedUniformRange_t.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetType(SedUniformRange_t * sur);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedUniformRange_t object have been set.
 *
 * @param sur the SedUniformRange_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedUniformRange_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedUniformRange_t object are:
 * @li "start"
 * @li "end"
 * @li "numberOfSteps"
 * @li "type"
 *
 * @memberof SedUniformRange_t
 */
LIBSEDML_EXTERN
int
SedUniformRange_hasRequiredAttributes(const SedUniformRange_t * sur);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedUniformRange_H__ */


