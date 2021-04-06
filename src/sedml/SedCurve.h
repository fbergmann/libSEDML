/**
 * @file SedCurve.h
 * @brief Definition of the SedCurve class.
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
 * @class SedCurve
 * @sbmlbrief{sedml} TODO:Definition of the SedCurve class.
 */

/**
 * <!-- ~ ~ ~ ~ ~ Start of common documentation strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * The following text is used as common documentation blocks copied multiple
 * times elsewhere in this file. The use of @class is a hack needed because
 * Doxygen's @copydetails command has limited functionality. Symbols
 * beginning with "doc_" are marked as ignored in our Doxygen configuration.
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ -->
 *
 *
 * @class doc_sedcurve_type
 *
 * @par
 * The attribute "type" on a SedCurve object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sedml specification, the following are the
 * allowable values for "type":
 * <ul>
 * <li> @c "points", TODO:add description
 *
 * <li> @c "bar", TODO:add description
 *
 * <li> @c "barStacked", TODO:add description
 *
 * <li> @c "horizontalBar", TODO:add description
 *
 * <li> @c "horizontalBarStacked", TODO:add description
 *
 * </ul>
 */


#ifndef SedCurve_H__
#define SedCurve_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/common/SedmlEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedAbstractCurve.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedCurve : public SedAbstractCurve
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  bool mLogY;
  bool mIsSetLogY;
  std::string mYDataReference;
  CurveType_t mType;
  std::string mXErrorUpper;
  std::string mXErrorLower;
  std::string mYErrorUpper;
  std::string mYErrorLower;

  /** @endcond */

public:

  /**
   * Creates a new SedCurve using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedCurve.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedCurve.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedCurve(unsigned int level = SEDML_DEFAULT_LEVEL,
           unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedCurve using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedCurve(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedCurve.
   *
   * @param orig the SedCurve instance to copy.
   */
  SedCurve(const SedCurve& orig);


  /**
   * Assignment operator for SedCurve.
   *
   * @param rhs the SedCurve object whose values are to be used as the basis of
   * the assignment.
   */
  SedCurve& operator=(const SedCurve& rhs);


  /**
   * Creates and returns a deep copy of this SedCurve object.
   *
   * @return a (deep) copy of this SedCurve object.
   */
  virtual SedCurve* clone() const;


  /**
   * Destructor for SedCurve.
   */
  virtual ~SedCurve();


  /**
   * Returns the value of the "logY" attribute of this SedCurve.
   *
   * @return the value of the "logY" attribute of this SedCurve as a boolean.
   */
  bool getLogY() const;


  /**
   * Returns the value of the "yDataReference" attribute of this SedCurve.
   *
   * @return the value of the "yDataReference" attribute of this SedCurve as a
   * string.
   */
  const std::string& getYDataReference() const;


  /**
   * Returns the value of the "type" attribute of this SedCurve.
   *
   * @return the value of the "type" attribute of this SedCurve as a
   * CurveType_t.
   *
   * @copydetails doc_sedcurve_type
   * @if clike The value is drawn from the enumeration @ref CurveType_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SEDML_CURVETYPE_POINTS, CurveType_t}
   * @li @sbmlconstant{SEDML_CURVETYPE_BAR, CurveType_t}
   * @li @sbmlconstant{SEDML_CURVETYPE_BARSTACKED, CurveType_t}
   * @li @sbmlconstant{SEDML_CURVETYPE_HORIZONTALBAR, CurveType_t}
   * @li @sbmlconstant{SEDML_CURVETYPE_HORIZONTALBARSTACKED, CurveType_t}
   * @li @sbmlconstant{SEDML_CURVETYPE_INVALID, CurveType_t}
   */
  CurveType_t getType() const;


  /**
   * Returns the value of the "type" attribute of this SedCurve.
   *
   * @return the value of the "type" attribute of this SedCurve as a string.
   *
   * @copydetails doc_sedcurve_type
   * The possible values returned by this method are:
   * @li @c "points"
   * @li @c "bar"
   * @li @c "barStacked"
   * @li @c "horizontalBar"
   * @li @c "horizontalBarStacked"
   * @li @c "invalid CurveType value"
   */
  std::string getTypeAsString() const;


  /**
   * Returns the value of the "xErrorUpper" attribute of this SedCurve.
   *
   * @return the value of the "xErrorUpper" attribute of this SedCurve as a
   * string.
   */
  const std::string& getXErrorUpper() const;


  /**
   * Returns the value of the "xErrorLower" attribute of this SedCurve.
   *
   * @return the value of the "xErrorLower" attribute of this SedCurve as a
   * string.
   */
  const std::string& getXErrorLower() const;


  /**
   * Returns the value of the "yErrorUpper" attribute of this SedCurve.
   *
   * @return the value of the "yErrorUpper" attribute of this SedCurve as a
   * string.
   */
  const std::string& getYErrorUpper() const;


  /**
   * Returns the value of the "yErrorLower" attribute of this SedCurve.
   *
   * @return the value of the "yErrorLower" attribute of this SedCurve as a
   * string.
   */
  const std::string& getYErrorLower() const;


  /**
   * Predicate returning @c true if this SedCurve's "logY" attribute is set.
   *
   * @return @c true if this SedCurve's "logY" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLogY() const;


  /**
   * Predicate returning @c true if this SedCurve's "yDataReference" attribute
   * is set.
   *
   * @return @c true if this SedCurve's "yDataReference" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetYDataReference() const;


  /**
   * Predicate returning @c true if this SedCurve's "type" attribute is set.
   *
   * @return @c true if this SedCurve's "type" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sedcurve_type
   */
  bool isSetType() const;


  /**
   * Predicate returning @c true if this SedCurve's "xErrorUpper" attribute is
   * set.
   *
   * @return @c true if this SedCurve's "xErrorUpper" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetXErrorUpper() const;


  /**
   * Predicate returning @c true if this SedCurve's "xErrorLower" attribute is
   * set.
   *
   * @return @c true if this SedCurve's "xErrorLower" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetXErrorLower() const;


  /**
   * Predicate returning @c true if this SedCurve's "yErrorUpper" attribute is
   * set.
   *
   * @return @c true if this SedCurve's "yErrorUpper" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetYErrorUpper() const;


  /**
   * Predicate returning @c true if this SedCurve's "yErrorLower" attribute is
   * set.
   *
   * @return @c true if this SedCurve's "yErrorLower" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetYErrorLower() const;


  /**
   * Sets the value of the "logY" attribute of this SedCurve.
   *
   * @param logY bool value of the "logY" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLogY(bool logY);


  /**
   * Sets the value of the "yDataReference" attribute of this SedCurve.
   *
   * @param yDataReference std::string& value of the "yDataReference" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setYDataReference(const std::string& yDataReference);


  /**
   * Sets the value of the "type" attribute of this SedCurve.
   *
   * @param type @if clike CurveType_t@else int@endif value of the "type"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedcurve_type
   */
  int setType(const CurveType_t type);


  /**
   * Sets the value of the "type" attribute of this SedCurve.
   *
   * @param type std::string& of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedcurve_type
   */
  int setType(const std::string& type);


  /**
   * Sets the value of the "xErrorUpper" attribute of this SedCurve.
   *
   * @param xErrorUpper std::string& value of the "xErrorUpper" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setXErrorUpper(const std::string& xErrorUpper);


  /**
   * Sets the value of the "xErrorLower" attribute of this SedCurve.
   *
   * @param xErrorLower std::string& value of the "xErrorLower" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setXErrorLower(const std::string& xErrorLower);


  /**
   * Sets the value of the "yErrorUpper" attribute of this SedCurve.
   *
   * @param yErrorUpper std::string& value of the "yErrorUpper" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setYErrorUpper(const std::string& yErrorUpper);


  /**
   * Sets the value of the "yErrorLower" attribute of this SedCurve.
   *
   * @param yErrorLower std::string& value of the "yErrorLower" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setYErrorLower(const std::string& yErrorLower);


  /**
   * Unsets the value of the "logY" attribute of this SedCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLogY();


  /**
   * Unsets the value of the "yDataReference" attribute of this SedCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetYDataReference();


  /**
   * Unsets the value of the "type" attribute of this SedCurve.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sedcurve_type
   */
  int unsetType();


  /**
   * Unsets the value of the "xErrorUpper" attribute of this SedCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetXErrorUpper();


  /**
   * Unsets the value of the "xErrorLower" attribute of this SedCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetXErrorLower();


  /**
   * Unsets the value of the "yErrorUpper" attribute of this SedCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetYErrorUpper();


  /**
   * Unsets the value of the "yErrorLower" attribute of this SedCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetYErrorLower();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedCurve object.
   *
   * For SedCurve, the XML element name is always @c "curve".
   *
   * @return the name of this element, i.e. @c "curve".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedCurve object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_OUTPUT_CURVE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedCurve object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedCurve have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedCurve object are:
   * @li "yDataReference"
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
   * Gets the value of the "attributeName" attribute of this SedCurve.
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
   * Gets the value of the "attributeName" attribute of this SedCurve.
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
   * Gets the value of the "attributeName" attribute of this SedCurve.
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
   * Gets the value of the "attributeName" attribute of this SedCurve.
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
   * Gets the value of the "attributeName" attribute of this SedCurve.
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
   * Predicate returning @c true if this SedCurve's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedCurve's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedCurve.
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
   * Sets the value of the "attributeName" attribute of this SedCurve.
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
   * Sets the value of the "attributeName" attribute of this SedCurve.
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
   * Sets the value of the "attributeName" attribute of this SedCurve.
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
   * Sets the value of the "attributeName" attribute of this SedCurve.
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
   * Unsets the value of the "attributeName" attribute of this SedCurve.
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
 * Creates a new SedCurve_t using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedCurve_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedCurve_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
SedCurve_t *
SedCurve_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedCurve_t object.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return a (deep) copy of this SedCurve_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
SedCurve_t*
SedCurve_clone(const SedCurve_t* sc);


/**
 * Frees this SedCurve_t object.
 *
 * @param sc the SedCurve_t structure.
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
void
SedCurve_free(SedCurve_t* sc);


/**
 * Returns the value of the "logY" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure whose logY is sought.
 *
 * @return the value of the "logY" attribute of this SedCurve_t as a boolean.
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_getLogY(const SedCurve_t * sc);


/**
 * Returns the value of the "yDataReference" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure whose yDataReference is sought.
 *
 * @return the value of the "yDataReference" attribute of this SedCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
char *
SedCurve_getYDataReference(const SedCurve_t * sc);


/**
 * Returns the value of the "type" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedCurve_t as a
 * CurveType_t.
 *
 * @copydetails doc_sedcurve_type
 * @if clike The value is drawn from the enumeration @ref CurveType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SEDML_CURVETYPE_POINTS, CurveType_t}
 * @li @sbmlconstant{SEDML_CURVETYPE_BAR, CurveType_t}
 * @li @sbmlconstant{SEDML_CURVETYPE_BARSTACKED, CurveType_t}
 * @li @sbmlconstant{SEDML_CURVETYPE_HORIZONTALBAR, CurveType_t}
 * @li @sbmlconstant{SEDML_CURVETYPE_HORIZONTALBARSTACKED, CurveType_t}
 * @li @sbmlconstant{SEDML_CURVETYPE_INVALID, CurveType_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
CurveType_t
SedCurve_getType(const SedCurve_t * sc);


/**
 * Returns the value of the "type" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedCurve_t as a const char
 * *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sedcurve_type
 * The possible values returned by this method are:
 * @li @c "points"
 * @li @c "bar"
 * @li @c "barStacked"
 * @li @c "horizontalBar"
 * @li @c "horizontalBarStacked"
 * @li @c "invalid CurveType value"
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
char *
SedCurve_getTypeAsString(const SedCurve_t * sc);


/**
 * Returns the value of the "xErrorUpper" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure whose xErrorUpper is sought.
 *
 * @return the value of the "xErrorUpper" attribute of this SedCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
char *
SedCurve_getXErrorUpper(const SedCurve_t * sc);


/**
 * Returns the value of the "xErrorLower" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure whose xErrorLower is sought.
 *
 * @return the value of the "xErrorLower" attribute of this SedCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
char *
SedCurve_getXErrorLower(const SedCurve_t * sc);


/**
 * Returns the value of the "yErrorUpper" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure whose yErrorUpper is sought.
 *
 * @return the value of the "yErrorUpper" attribute of this SedCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
char *
SedCurve_getYErrorUpper(const SedCurve_t * sc);


/**
 * Returns the value of the "yErrorLower" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure whose yErrorLower is sought.
 *
 * @return the value of the "yErrorLower" attribute of this SedCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
char *
SedCurve_getYErrorLower(const SedCurve_t * sc);


/**
 * Predicate returning @c 1 (true) if this SedCurve_t's "logY" attribute is
 * set.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return @c 1 (true) if this SedCurve_t's "logY" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_isSetLogY(const SedCurve_t * sc);


/**
 * Predicate returning @c 1 (true) if this SedCurve_t's "yDataReference"
 * attribute is set.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return @c 1 (true) if this SedCurve_t's "yDataReference" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_isSetYDataReference(const SedCurve_t * sc);


/**
 * Predicate returning @c 1 (true) if this SedCurve_t's "type" attribute is
 * set.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return @c 1 (true) if this SedCurve_t's "type" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sedcurve_type
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_isSetType(const SedCurve_t * sc);


/**
 * Predicate returning @c 1 (true) if this SedCurve_t's "xErrorUpper" attribute
 * is set.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return @c 1 (true) if this SedCurve_t's "xErrorUpper" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_isSetXErrorUpper(const SedCurve_t * sc);


/**
 * Predicate returning @c 1 (true) if this SedCurve_t's "xErrorLower" attribute
 * is set.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return @c 1 (true) if this SedCurve_t's "xErrorLower" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_isSetXErrorLower(const SedCurve_t * sc);


/**
 * Predicate returning @c 1 (true) if this SedCurve_t's "yErrorUpper" attribute
 * is set.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return @c 1 (true) if this SedCurve_t's "yErrorUpper" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_isSetYErrorUpper(const SedCurve_t * sc);


/**
 * Predicate returning @c 1 (true) if this SedCurve_t's "yErrorLower" attribute
 * is set.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return @c 1 (true) if this SedCurve_t's "yErrorLower" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_isSetYErrorLower(const SedCurve_t * sc);


/**
 * Sets the value of the "logY" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @param logY int value of the "logY" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_setLogY(SedCurve_t * sc, int logY);


/**
 * Sets the value of the "yDataReference" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @param yDataReference const char * value of the "yDataReference" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_setYDataReference(SedCurve_t * sc, const char * yDataReference);


/**
 * Sets the value of the "type" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @param type CurveType_t value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedcurve_type
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_setType(SedCurve_t * sc, CurveType_t type);


/**
 * Sets the value of the "type" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @param type const char * of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedcurve_type
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_setTypeAsString(SedCurve_t * sc, const char * type);


/**
 * Sets the value of the "xErrorUpper" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @param xErrorUpper const char * value of the "xErrorUpper" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_setXErrorUpper(SedCurve_t * sc, const char * xErrorUpper);


/**
 * Sets the value of the "xErrorLower" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @param xErrorLower const char * value of the "xErrorLower" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_setXErrorLower(SedCurve_t * sc, const char * xErrorLower);


/**
 * Sets the value of the "yErrorUpper" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @param yErrorUpper const char * value of the "yErrorUpper" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_setYErrorUpper(SedCurve_t * sc, const char * yErrorUpper);


/**
 * Sets the value of the "yErrorLower" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @param yErrorLower const char * value of the "yErrorLower" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_setYErrorLower(SedCurve_t * sc, const char * yErrorLower);


/**
 * Unsets the value of the "logY" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_unsetLogY(SedCurve_t * sc);


/**
 * Unsets the value of the "yDataReference" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_unsetYDataReference(SedCurve_t * sc);


/**
 * Unsets the value of the "type" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedcurve_type
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_unsetType(SedCurve_t * sc);


/**
 * Unsets the value of the "xErrorUpper" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_unsetXErrorUpper(SedCurve_t * sc);


/**
 * Unsets the value of the "xErrorLower" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_unsetXErrorLower(SedCurve_t * sc);


/**
 * Unsets the value of the "yErrorUpper" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_unsetYErrorUpper(SedCurve_t * sc);


/**
 * Unsets the value of the "yErrorLower" attribute of this SedCurve_t.
 *
 * @param sc the SedCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_unsetYErrorLower(SedCurve_t * sc);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedCurve_t object have been set.
 *
 * @param sc the SedCurve_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedCurve_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedCurve_t object are:
 * @li "yDataReference"
 *
 * @memberof SedCurve_t
 */
LIBSEDML_EXTERN
int
SedCurve_hasRequiredAttributes(const SedCurve_t * sc);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedCurve_H__ */


