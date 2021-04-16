/**
 * @file SedAxis.h
 * @brief Definition of the SedAxis class.
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
 * @class SedAxis
 * @sbmlbrief{sedml} TODO:Definition of the SedAxis class.
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
 * @class doc_sedaxis_type
 *
 * @par
 * The attribute "type" on a SedAxis object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sedml specification, the following are the
 * allowable values for "type":
 * <ul>
 * <li> @c "linear", TODO:add description
 *
 * <li> @c "log10", TODO:add description
 *
 * </ul>
 */


#ifndef SedAxis_H__
#define SedAxis_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/common/SedmlEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedAxis : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  AxisType_t mType;
  double mMin;
  bool mIsSetMin;
  double mMax;
  bool mIsSetMax;
  bool mGrid;
  bool mIsSetGrid;
  bool mReverse;
  bool mIsSetReverse;
  std::string mStyle;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedAxis using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedAxis.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedAxis.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAxis(unsigned int level = SEDML_DEFAULT_LEVEL,
          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedAxis using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAxis(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedAxis.
   *
   * @param orig the SedAxis instance to copy.
   */
  SedAxis(const SedAxis& orig);


  /**
   * Assignment operator for SedAxis.
   *
   * @param rhs the SedAxis object whose values are to be used as the basis of
   * the assignment.
   */
  SedAxis& operator=(const SedAxis& rhs);


  /**
   * Creates and returns a deep copy of this SedAxis object.
   *
   * @return a (deep) copy of this SedAxis object.
   */
  virtual SedAxis* clone() const;


  /**
   * Destructor for SedAxis.
   */
  virtual ~SedAxis();


  /**
   * Returns the value of the "type" attribute of this SedAxis.
   *
   * @return the value of the "type" attribute of this SedAxis as a AxisType_t.
   *
   * @copydetails doc_sedaxis_type
   * @if clike The value is drawn from the enumeration @ref AxisType_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SEDML_AXISTYPE_LINEAR, AxisType_t}
   * @li @sbmlconstant{SEDML_AXISTYPE_LOG10, AxisType_t}
   * @li @sbmlconstant{SEDML_AXISTYPE_INVALID, AxisType_t}
   */
  AxisType_t getType() const;


  /**
   * Returns the value of the "type" attribute of this SedAxis.
   *
   * @return the value of the "type" attribute of this SedAxis as a string.
   *
   * @copydetails doc_sedaxis_type
   * The possible values returned by this method are:
   * @li @c "linear"
   * @li @c "log10"
   * @li @c "invalid AxisType value"
   */
  std::string getTypeAsString() const;


  /**
   * Returns the value of the "min" attribute of this SedAxis.
   *
   * @return the value of the "min" attribute of this SedAxis as a double.
   */
  double getMin() const;


  /**
   * Returns the value of the "max" attribute of this SedAxis.
   *
   * @return the value of the "max" attribute of this SedAxis as a double.
   */
  double getMax() const;


  /**
   * Returns the value of the "grid" attribute of this SedAxis.
   *
   * @return the value of the "grid" attribute of this SedAxis as a boolean.
   */
  bool getGrid() const;


  /**
   * Returns the value of the "reverse" attribute of this SedAxis.
   *
   * @return the value of the "reverse" attribute of this SedAxis as a boolean.
   */
  bool getReverse() const;


  /**
   * Returns the value of the "style" attribute of this SedAxis.
   *
   * @return the value of the "style" attribute of this SedAxis as a string.
   */
  const std::string& getStyle() const;


  /**
   * Predicate returning @c true if this SedAxis's "type" attribute is set.
   *
   * @return @c true if this SedAxis's "type" attribute has been set, otherwise
   * @c false is returned.
   *
   * @copydetails doc_sedaxis_type
   */
  bool isSetType() const;


  /**
   * Predicate returning @c true if this SedAxis's "min" attribute is set.
   *
   * @return @c true if this SedAxis's "min" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetMin() const;


  /**
   * Predicate returning @c true if this SedAxis's "max" attribute is set.
   *
   * @return @c true if this SedAxis's "max" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetMax() const;


  /**
   * Predicate returning @c true if this SedAxis's "grid" attribute is set.
   *
   * @return @c true if this SedAxis's "grid" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetGrid() const;


  /**
   * Predicate returning @c true if this SedAxis's "reverse" attribute is set.
   *
   * @return @c true if this SedAxis's "reverse" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetReverse() const;


  /**
   * Predicate returning @c true if this SedAxis's "style" attribute is set.
   *
   * @return @c true if this SedAxis's "style" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetStyle() const;


  /**
   * Sets the value of the "type" attribute of this SedAxis.
   *
   * @param type @if clike AxisType_t@else int@endif value of the "type"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedaxis_type
   */
  int setType(const AxisType_t type);


  /**
   * Sets the value of the "type" attribute of this SedAxis.
   *
   * @param type std::string& of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedaxis_type
   */
  int setType(const std::string& type);


  /**
   * Sets the value of the "min" attribute of this SedAxis.
   *
   * @param min double value of the "min" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMin(double min);


  /**
   * Sets the value of the "max" attribute of this SedAxis.
   *
   * @param max double value of the "max" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMax(double max);


  /**
   * Sets the value of the "grid" attribute of this SedAxis.
   *
   * @param grid bool value of the "grid" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setGrid(bool grid);


  /**
   * Sets the value of the "reverse" attribute of this SedAxis.
   *
   * @param reverse bool value of the "reverse" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setReverse(bool reverse);


  /**
   * Sets the value of the "style" attribute of this SedAxis.
   *
   * @param style std::string& value of the "style" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStyle(const std::string& style);


  /**
   * Unsets the value of the "type" attribute of this SedAxis.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sedaxis_type
   */
  int unsetType();


  /**
   * Unsets the value of the "min" attribute of this SedAxis.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMin();


  /**
   * Unsets the value of the "max" attribute of this SedAxis.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMax();


  /**
   * Unsets the value of the "grid" attribute of this SedAxis.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetGrid();


  /**
   * Unsets the value of the "reverse" attribute of this SedAxis.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetReverse();


  /**
   * Unsets the value of the "style" attribute of this SedAxis.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStyle();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedAxis object.
   *
   * For SedAxis, the XML element name is always @c "axis".
   *
   * @return the name of this element, i.e. @c "axis".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedAxis object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedAxis object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_AXIS, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedAxis object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedAxis have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedAxis object are:
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
   * Gets the value of the "attributeName" attribute of this SedAxis.
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
   * Gets the value of the "attributeName" attribute of this SedAxis.
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
   * Gets the value of the "attributeName" attribute of this SedAxis.
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
   * Gets the value of the "attributeName" attribute of this SedAxis.
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
   * Gets the value of the "attributeName" attribute of this SedAxis.
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
   * Predicate returning @c true if this SedAxis's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedAxis's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedAxis.
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
   * Sets the value of the "attributeName" attribute of this SedAxis.
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
   * Sets the value of the "attributeName" attribute of this SedAxis.
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
   * Sets the value of the "attributeName" attribute of this SedAxis.
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
   * Sets the value of the "attributeName" attribute of this SedAxis.
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
   * Unsets the value of the "attributeName" attribute of this SedAxis.
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
 * Creates a new SedAxis_t using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedAxis_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAxis_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
SedAxis_t *
SedAxis_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedAxis_t object.
 *
 * @param sa the SedAxis_t structure.
 *
 * @return a (deep) copy of this SedAxis_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
SedAxis_t*
SedAxis_clone(const SedAxis_t* sa);


/**
 * Frees this SedAxis_t object.
 *
 * @param sa the SedAxis_t structure.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
void
SedAxis_free(SedAxis_t* sa);


/**
 * Returns the value of the "type" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedAxis_t as a AxisType_t.
 *
 * @copydetails doc_sedaxis_type
 * @if clike The value is drawn from the enumeration @ref AxisType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SEDML_AXISTYPE_LINEAR, AxisType_t}
 * @li @sbmlconstant{SEDML_AXISTYPE_LOG10, AxisType_t}
 * @li @sbmlconstant{SEDML_AXISTYPE_INVALID, AxisType_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
AxisType_t
SedAxis_getType(const SedAxis_t * sa);


/**
 * Returns the value of the "type" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedAxis_t as a const char
 * *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sedaxis_type
 * The possible values returned by this method are:
 * @li @c "linear"
 * @li @c "log10"
 * @li @c "invalid AxisType value"
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
char *
SedAxis_getTypeAsString(const SedAxis_t * sa);


/**
 * Returns the value of the "min" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure whose min is sought.
 *
 * @return the value of the "min" attribute of this SedAxis_t as a double.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
double
SedAxis_getMin(const SedAxis_t * sa);


/**
 * Returns the value of the "max" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure whose max is sought.
 *
 * @return the value of the "max" attribute of this SedAxis_t as a double.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
double
SedAxis_getMax(const SedAxis_t * sa);


/**
 * Returns the value of the "grid" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure whose grid is sought.
 *
 * @return the value of the "grid" attribute of this SedAxis_t as a boolean.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_getGrid(const SedAxis_t * sa);


/**
 * Returns the value of the "reverse" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure whose reverse is sought.
 *
 * @return the value of the "reverse" attribute of this SedAxis_t as a boolean.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_getReverse(const SedAxis_t* sa);


/**
 * Returns the value of the "style" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure whose style is sought.
 *
 * @return the value of the "style" attribute of this SedAxis_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
char *
SedAxis_getStyle(const SedAxis_t * sa);


/**
 * Predicate returning @c 1 (true) if this SedAxis_t's "type" attribute is set.
 *
 * @param sa the SedAxis_t structure.
 *
 * @return @c 1 (true) if this SedAxis_t's "type" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sedaxis_type
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_isSetType(const SedAxis_t * sa);


/**
 * Predicate returning @c 1 (true) if this SedAxis_t's "min" attribute is set.
 *
 * @param sa the SedAxis_t structure.
 *
 * @return @c 1 (true) if this SedAxis_t's "min" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_isSetMin(const SedAxis_t * sa);


/**
 * Predicate returning @c 1 (true) if this SedAxis_t's "max" attribute is set.
 *
 * @param sa the SedAxis_t structure.
 *
 * @return @c 1 (true) if this SedAxis_t's "max" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_isSetMax(const SedAxis_t * sa);


/**
 * Predicate returning @c 1 (true) if this SedAxis_t's "grid" attribute is set.
 *
 * @param sa the SedAxis_t structure.
 *
 * @return @c 1 (true) if this SedAxis_t's "grid" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_isSetGrid(const SedAxis_t * sa);


/**
 * Predicate returning @c 1 (true) if this SedAxis_t's "reverse" attribute is set.
 *
 * @param sa the SedAxis_t structure.
 *
 * @return @c 1 (true) if this SedAxis_t's "reverse" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_isSetReverse(const SedAxis_t* sa);


/**
 * Predicate returning @c 1 (true) if this SedAxis_t's "style" attribute is
 * set.
 *
 * @param sa the SedAxis_t structure.
 *
 * @return @c 1 (true) if this SedAxis_t's "style" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_isSetStyle(const SedAxis_t * sa);


/**
 * Sets the value of the "type" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @param type AxisType_t value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedaxis_type
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_setType(SedAxis_t * sa, AxisType_t type);


/**
 * Sets the value of the "type" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @param type const char * of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedaxis_type
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_setTypeAsString(SedAxis_t * sa, const char * type);


/**
 * Sets the value of the "min" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @param min double value of the "min" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_setMin(SedAxis_t * sa, double min);


/**
 * Sets the value of the "max" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @param max double value of the "max" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_setMax(SedAxis_t * sa, double max);


/**
 * Sets the value of the "grid" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @param grid int value of the "grid" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_setGrid(SedAxis_t * sa, int grid);


/**
 * Sets the value of the "reverse" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @param reverse int value of the "reverse" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_setReverse(SedAxis_t* sa, int reverse);


/**
 * Sets the value of the "style" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @param style const char * value of the "style" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_setStyle(SedAxis_t * sa, const char * style);


/**
 * Unsets the value of the "type" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedaxis_type
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_unsetType(SedAxis_t * sa);


/**
 * Unsets the value of the "min" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_unsetMin(SedAxis_t * sa);


/**
 * Unsets the value of the "max" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_unsetMax(SedAxis_t * sa);


/**
 * Unsets the value of the "grid" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_unsetGrid(SedAxis_t * sa);


/**
 * Unsets the value of the "reverse" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_unsetReverse(SedAxis_t* sa);


/**
 * Unsets the value of the "style" attribute of this SedAxis_t.
 *
 * @param sa the SedAxis_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_unsetStyle(SedAxis_t * sa);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAxis_t object have been set.
 *
 * @param sa the SedAxis_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedAxis_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedAxis_t object are:
 * @li "type"
 *
 * @memberof SedAxis_t
 */
LIBSEDML_EXTERN
int
SedAxis_hasRequiredAttributes(const SedAxis_t * sa);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedAxis_H__ */


