/**
 * @file SedMarker.h
 * @brief Definition of the SedMarker class.
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
 * @class SedMarker
 * @sbmlbrief{sedml} TODO:Definition of the SedMarker class.
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
 * @class doc_sedmarker_type
 *
 * @par
 * The attribute "type" on a SedMarker object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sedml specification, the following are the
 * allowable values for "type":
 * <ul>
 * <li> @c "none", TODO:add description
 *
 * <li> @c "square", TODO:add description
 *
 * <li> @c "circle", TODO:add description
 *
 * <li> @c "diamond", TODO:add description
 *
 * <li> @c "xCross", TODO:add description
 *
 * <li> @c "plus", TODO:add description
 *
 * <li> @c "star", TODO:add description
 *
 * <li> @c "triangleUp", TODO:add description
 *
 * <li> @c "triangleDown", TODO:add description
 *
 * <li> @c "triangleLeft", TODO:add description
 *
 * <li> @c "triangleRight", TODO:add description
 *
 * <li> @c "hDash", TODO:add description
 *
 * <li> @c "vDash", TODO:add description
 *
 * </ul>
 */


#ifndef SedMarker_H__
#define SedMarker_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/common/SedmlEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedMarker : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mSize;
  bool mIsSetSize;
  MarkerType_t mType;
  std::string mFill;
  std::string mLineColor;
  double mLineThickness;
  bool mIsSetLineThickness;

  /** @endcond */

public:

  /**
   * Creates a new SedMarker using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedMarker.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedMarker.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedMarker(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedMarker using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedMarker(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedMarker.
   *
   * @param orig the SedMarker instance to copy.
   */
  SedMarker(const SedMarker& orig);


  /**
   * Assignment operator for SedMarker.
   *
   * @param rhs the SedMarker object whose values are to be used as the basis
   * of the assignment.
   */
  SedMarker& operator=(const SedMarker& rhs);


  /**
   * Creates and returns a deep copy of this SedMarker object.
   *
   * @return a (deep) copy of this SedMarker object.
   */
  virtual SedMarker* clone() const;


  /**
   * Destructor for SedMarker.
   */
  virtual ~SedMarker();


  /**
   * Returns the value of the "size" attribute of this SedMarker.
   *
   * @return the value of the "size" attribute of this SedMarker as a double.
   */
  double getSize() const;


  /**
   * Returns the value of the "type" attribute of this SedMarker.
   *
   * @return the value of the "type" attribute of this SedMarker as a
   * MarkerType_t.
   *
   * @copydetails doc_sedmarker_type
   * @if clike The value is drawn from the enumeration @ref MarkerType_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SEDML_MARKERTYPE_NONE, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_SQUARE, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_CIRCLE, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_DIAMOND, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_XCROSS, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_PLUS, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_STAR, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_TRIANGLEUP, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_TRIANGLEDOWN, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_TRIANGLELEFT, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_TRIANGLERIGHT, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_HDASH, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_VDASH, MarkerType_t}
   * @li @sbmlconstant{SEDML_MARKERTYPE_INVALID, MarkerType_t}
   */
  MarkerType_t getType() const;


  /**
   * Returns the value of the "type" attribute of this SedMarker.
   *
   * @return the value of the "type" attribute of this SedMarker as a string.
   *
   * @copydetails doc_sedmarker_type
   * The possible values returned by this method are:
   * @li @c "none"
   * @li @c "square"
   * @li @c "circle"
   * @li @c "diamond"
   * @li @c "xCross"
   * @li @c "plus"
   * @li @c "star"
   * @li @c "triangleUp"
   * @li @c "triangleDown"
   * @li @c "triangleLeft"
   * @li @c "triangleRight"
   * @li @c "hDash"
   * @li @c "vDash"
   * @li @c "invalid MarkerType value"
   */
  std::string getTypeAsString() const;


  /**
   * Returns the value of the "fill" attribute of this SedMarker.
   *
   * @return the value of the "fill" attribute of this SedMarker as a string.
   */
  const std::string& getFill() const;


  /**
   * Returns the value of the "lineColor" attribute of this SedMarker.
   *
   * @return the value of the "lineColor" attribute of this SedMarker as a
   * string.
   */
  const std::string& getLineColor() const;


  /**
   * Returns the value of the "lineThickness" attribute of this SedMarker.
   *
   * @return the value of the "lineThickness" attribute of this SedMarker as a
   * double.
   */
  double getLineThickness() const;


  /**
   * Predicate returning @c true if this SedMarker's "size" attribute is set.
   *
   * @return @c true if this SedMarker's "size" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSize() const;


  /**
   * Predicate returning @c true if this SedMarker's "type" attribute is set.
   *
   * @return @c true if this SedMarker's "type" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sedmarker_type
   */
  bool isSetType() const;


  /**
   * Predicate returning @c true if this SedMarker's "fill" attribute is set.
   *
   * @return @c true if this SedMarker's "fill" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetFill() const;


  /**
   * Predicate returning @c true if this SedMarker's "lineColor" attribute is
   * set.
   *
   * @return @c true if this SedMarker's "lineColor" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLineColor() const;


  /**
   * Predicate returning @c true if this SedMarker's "lineThickness" attribute
   * is set.
   *
   * @return @c true if this SedMarker's "lineThickness" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetLineThickness() const;


  /**
   * Sets the value of the "size" attribute of this SedMarker.
   *
   * @param size double value of the "size" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setSize(double size);


  /**
   * Sets the value of the "type" attribute of this SedMarker.
   *
   * @param type @if clike MarkerType_t@else int@endif value of the "type"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedmarker_type
   */
  int setType(const MarkerType_t type);


  /**
   * Sets the value of the "type" attribute of this SedMarker.
   *
   * @param type std::string& of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedmarker_type
   */
  int setType(const std::string& type);


  /**
   * Sets the value of the "fill" attribute of this SedMarker.
   *
   * @param fill std::string& value of the "fill" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p fill = @c NULL or an empty string is
   * equivalent to calling unsetFill().
   */
  int setFill(const std::string& fill);


  /**
   * Sets the value of the "lineColor" attribute of this SedMarker.
   *
   * @param lineColor std::string& value of the "lineColor" attribute to be
   * set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p lineColor = @c NULL or an empty string is
   * equivalent to calling unsetLineColor().
   */
  int setLineColor(const std::string& lineColor);


  /**
   * Sets the value of the "lineThickness" attribute of this SedMarker.
   *
   * @param lineThickness double value of the "lineThickness" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLineThickness(double lineThickness);


  /**
   * Unsets the value of the "size" attribute of this SedMarker.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSize();


  /**
   * Unsets the value of the "type" attribute of this SedMarker.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sedmarker_type
   */
  int unsetType();


  /**
   * Unsets the value of the "fill" attribute of this SedMarker.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFill();


  /**
   * Unsets the value of the "lineColor" attribute of this SedMarker.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLineColor();


  /**
   * Unsets the value of the "lineThickness" attribute of this SedMarker.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLineThickness();


  /**
   * Returns the XML element name of this SedMarker object.
   *
   * For SedMarker, the XML element name is always @c "marker".
   *
   * @return the name of this element, i.e. @c "marker".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedMarker object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_MARKER, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedMarker object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedMarker have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SedMarker.
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
   * Gets the value of the "attributeName" attribute of this SedMarker.
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
   * Gets the value of the "attributeName" attribute of this SedMarker.
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
   * Gets the value of the "attributeName" attribute of this SedMarker.
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
   * Gets the value of the "attributeName" attribute of this SedMarker.
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
   * Predicate returning @c true if this SedMarker's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedMarker's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedMarker.
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
   * Sets the value of the "attributeName" attribute of this SedMarker.
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
   * Sets the value of the "attributeName" attribute of this SedMarker.
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
   * Sets the value of the "attributeName" attribute of this SedMarker.
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
   * Sets the value of the "attributeName" attribute of this SedMarker.
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
   * Unsets the value of the "attributeName" attribute of this SedMarker.
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
 * Creates a new SedMarker_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedMarker_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedMarker_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
SedMarker_t *
SedMarker_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedMarker_t object.
 *
 * @param sm the SedMarker_t structure.
 *
 * @return a (deep) copy of this SedMarker_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
SedMarker_t*
SedMarker_clone(const SedMarker_t* sm);


/**
 * Frees this SedMarker_t object.
 *
 * @param sm the SedMarker_t structure.
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
void
SedMarker_free(SedMarker_t* sm);


/**
 * Returns the value of the "size" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure whose size is sought.
 *
 * @return the value of the "size" attribute of this SedMarker_t as a double.
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
double
SedMarker_getSize(const SedMarker_t * sm);


/**
 * Returns the value of the "type" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedMarker_t as a
 * MarkerType_t.
 *
 * @copydetails doc_sedmarker_type
 * @if clike The value is drawn from the enumeration @ref MarkerType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SEDML_MARKERTYPE_NONE, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_SQUARE, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_CIRCLE, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_DIAMOND, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_XCROSS, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_PLUS, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_STAR, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_TRIANGLEUP, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_TRIANGLEDOWN, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_TRIANGLELEFT, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_TRIANGLERIGHT, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_HDASH, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_VDASH, MarkerType_t}
 * @li @sbmlconstant{SEDML_MARKERTYPE_INVALID, MarkerType_t}
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
MarkerType_t
SedMarker_getType(const SedMarker_t * sm);


/**
 * Returns the value of the "type" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedMarker_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sedmarker_type
 * The possible values returned by this method are:
 * @li @c "none"
 * @li @c "square"
 * @li @c "circle"
 * @li @c "diamond"
 * @li @c "xCross"
 * @li @c "plus"
 * @li @c "star"
 * @li @c "triangleUp"
 * @li @c "triangleDown"
 * @li @c "triangleLeft"
 * @li @c "triangleRight"
 * @li @c "hDash"
 * @li @c "vDash"
 * @li @c "invalid MarkerType value"
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
char *
SedMarker_getTypeAsString(const SedMarker_t * sm);


/**
 * Returns the value of the "fill" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure whose fill is sought.
 *
 * @return the value of the "fill" attribute of this SedMarker_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
char *
SedMarker_getFill(const SedMarker_t * sm);


/**
 * Returns the value of the "lineColor" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure whose lineColor is sought.
 *
 * @return the value of the "lineColor" attribute of this SedMarker_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
char *
SedMarker_getLineColor(const SedMarker_t * sm);


/**
 * Returns the value of the "lineThickness" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure whose lineThickness is sought.
 *
 * @return the value of the "lineThickness" attribute of this SedMarker_t as a
 * double.
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
double
SedMarker_getLineThickness(const SedMarker_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedMarker_t's "size" attribute is
 * set.
 *
 * @param sm the SedMarker_t structure.
 *
 * @return @c 1 (true) if this SedMarker_t's "size" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_isSetSize(const SedMarker_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedMarker_t's "type" attribute is
 * set.
 *
 * @param sm the SedMarker_t structure.
 *
 * @return @c 1 (true) if this SedMarker_t's "type" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sedmarker_type
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_isSetType(const SedMarker_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedMarker_t's "fill" attribute is
 * set.
 *
 * @param sm the SedMarker_t structure.
 *
 * @return @c 1 (true) if this SedMarker_t's "fill" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_isSetFill(const SedMarker_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedMarker_t's "lineColor" attribute
 * is set.
 *
 * @param sm the SedMarker_t structure.
 *
 * @return @c 1 (true) if this SedMarker_t's "lineColor" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_isSetLineColor(const SedMarker_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedMarker_t's "lineThickness"
 * attribute is set.
 *
 * @param sm the SedMarker_t structure.
 *
 * @return @c 1 (true) if this SedMarker_t's "lineThickness" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_isSetLineThickness(const SedMarker_t * sm);


/**
 * Sets the value of the "size" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @param size double value of the "size" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_setSize(SedMarker_t * sm, double size);


/**
 * Sets the value of the "type" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @param type MarkerType_t value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedmarker_type
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_setType(SedMarker_t * sm, MarkerType_t type);


/**
 * Sets the value of the "type" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @param type const char * of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedmarker_type
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_setTypeAsString(SedMarker_t * sm, const char * type);


/**
 * Sets the value of the "fill" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @param fill const char * value of the "fill" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p fill = @c NULL or an empty string is
 * equivalent to calling SedMarker_unsetFill().
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_setFill(SedMarker_t * sm, const char * fill);


/**
 * Sets the value of the "lineColor" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @param lineColor const char * value of the "lineColor" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p lineColor = @c NULL or an empty string is
 * equivalent to calling SedMarker_unsetLineColor().
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_setLineColor(SedMarker_t * sm, const char * lineColor);


/**
 * Sets the value of the "lineThickness" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @param lineThickness double value of the "lineThickness" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_setLineThickness(SedMarker_t * sm, double lineThickness);


/**
 * Unsets the value of the "size" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_unsetSize(SedMarker_t * sm);


/**
 * Unsets the value of the "type" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedmarker_type
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_unsetType(SedMarker_t * sm);


/**
 * Unsets the value of the "fill" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_unsetFill(SedMarker_t * sm);


/**
 * Unsets the value of the "lineColor" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_unsetLineColor(SedMarker_t * sm);


/**
 * Unsets the value of the "lineThickness" attribute of this SedMarker_t.
 *
 * @param sm the SedMarker_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_unsetLineThickness(SedMarker_t * sm);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedMarker_t object have been set.
 *
 * @param sm the SedMarker_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedMarker_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedMarker_t
 */
LIBSEDML_EXTERN
int
SedMarker_hasRequiredAttributes(const SedMarker_t * sm);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedMarker_H__ */


