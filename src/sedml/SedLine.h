/**
 * @file SedLine.h
 * @brief Definition of the SedLine class.
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
 * @class SedLine
 * @sbmlbrief{sedml} TODO:Definition of the SedLine class.
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
 * @class doc_sedline_type
 *
 * @par
 * The attribute "type" on a SedLine object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sedml specification, the following are the
 * allowable values for "type":
 * <ul>
 * <li> @c "none", TODO:add description
 *
 * <li> @c "solid", TODO:add description
 *
 * <li> @c "dash", TODO:add description
 *
 * <li> @c "dot", TODO:add description
 *
 * <li> @c "dashDot", TODO:add description
 *
 * <li> @c "dashDotDot", TODO:add description
 *
 * </ul>
 */


#ifndef SedLine_H__
#define SedLine_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/common/SedmlEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedLine : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  LineType_t mType;
  std::string mColor;
  double mThickness;
  bool mIsSetThickness;

  /** @endcond */

public:

  /**
   * Creates a new SedLine using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedLine.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedLine.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedLine(unsigned int level = SEDML_DEFAULT_LEVEL,
          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedLine using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedLine(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedLine.
   *
   * @param orig the SedLine instance to copy.
   */
  SedLine(const SedLine& orig);


  /**
   * Assignment operator for SedLine.
   *
   * @param rhs the SedLine object whose values are to be used as the basis of
   * the assignment.
   */
  SedLine& operator=(const SedLine& rhs);


  /**
   * Creates and returns a deep copy of this SedLine object.
   *
   * @return a (deep) copy of this SedLine object.
   */
  virtual SedLine* clone() const;


  /**
   * Destructor for SedLine.
   */
  virtual ~SedLine();


  /**
   * Returns the value of the "type" attribute of this SedLine.
   *
   * @return the value of the "type" attribute of this SedLine as a
   * LineType_t.
   *
   * @copydetails doc_sedline_type
   * @if clike The value is drawn from the enumeration @ref LineType_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SEDML_LINETYPE_NONE, LineType_t}
   * @li @sbmlconstant{SEDML_LINETYPE_SOLID, LineType_t}
   * @li @sbmlconstant{SEDML_LINETYPE_DASH, LineType_t}
   * @li @sbmlconstant{SEDML_LINETYPE_DOT, LineType_t}
   * @li @sbmlconstant{SEDML_LINETYPE_DASHDOT, LineType_t}
   * @li @sbmlconstant{SEDML_LINETYPE_DASHDOTDOT, LineType_t}
   * @li @sbmlconstant{SEDML_LINETYPE_INVALID, LineType_t}
   */
  LineType_t getType() const;


  /**
   * Returns the value of the "type" attribute of this SedLine.
   *
   * @return the value of the "type" attribute of this SedLine as a string.
   *
   * @copydetails doc_sedline_type
   * The possible values returned by this method are:
   * @li @c "none"
   * @li @c "solid"
   * @li @c "dash"
   * @li @c "dot"
   * @li @c "dashDot"
   * @li @c "dashDotDot"
   * @li @c "invalid LineType value"
   */
  std::string getTypeAsString() const;


  /**
   * Returns the value of the "color" attribute of this SedLine.
   *
   * @return the value of the "color" attribute of this SedLine as a string.
   */
  const std::string& getColor() const;


  /**
   * Returns the value of the "thickness" attribute of this SedLine.
   *
   * @return the value of the "thickness" attribute of this SedLine as a
   * double.
   */
  double getThickness() const;


  /**
   * Predicate returning @c true if this SedLine's "type" attribute is set.
   *
   * @return @c true if this SedLine's "type" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sedline_type
   */
  bool isSetType() const;


  /**
   * Predicate returning @c true if this SedLine's "color" attribute is set.
   *
   * @return @c true if this SedLine's "color" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetColor() const;


  /**
   * Predicate returning @c true if this SedLine's "thickness" attribute is
   * set.
   *
   * @return @c true if this SedLine's "thickness" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetThickness() const;


  /**
   * Sets the value of the "type" attribute of this SedLine.
   *
   * @param type @if clike LineType_t@else int@endif value of the "type"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedline_type
   */
  int setType(const LineType_t type);


  /**
   * Sets the value of the "type" attribute of this SedLine.
   *
   * @param type std::string& of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedline_type
   */
  int setType(const std::string& type);


  /**
   * Sets the value of the "color" attribute of this SedLine.
   *
   * @param color std::string& value of the "color" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p color = @c NULL or an empty string is
   * equivalent to calling unsetColor().
   */
  int setColor(const std::string& color);


  /**
   * Sets the value of the "thickness" attribute of this SedLine.
   *
   * @param thickness double value of the "thickness" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setThickness(double thickness);


  /**
   * Unsets the value of the "type" attribute of this SedLine.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sedline_type
   */
  int unsetType();


  /**
   * Unsets the value of the "color" attribute of this SedLine.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetColor();


  /**
   * Unsets the value of the "thickness" attribute of this SedLine.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetThickness();


  /**
   * Returns the XML element name of this SedLine object.
   *
   * For SedLine, the XML element name is always @c "line".
   *
   * @return the name of this element, i.e. @c "line".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedLine object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_LINE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedLine object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedLine have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SedLine.
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
   * Gets the value of the "attributeName" attribute of this SedLine.
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
   * Gets the value of the "attributeName" attribute of this SedLine.
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
   * Gets the value of the "attributeName" attribute of this SedLine.
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
   * Gets the value of the "attributeName" attribute of this SedLine.
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
   * Predicate returning @c true if this SedLine's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedLine's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedLine.
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
   * Sets the value of the "attributeName" attribute of this SedLine.
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
   * Sets the value of the "attributeName" attribute of this SedLine.
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
   * Sets the value of the "attributeName" attribute of this SedLine.
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
   * Sets the value of the "attributeName" attribute of this SedLine.
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
   * Unsets the value of the "attributeName" attribute of this SedLine.
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
 * Creates a new SedLine_t using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedLine_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedLine_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
SedLine_t *
SedLine_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedLine_t object.
 *
 * @param sl the SedLine_t structure.
 *
 * @return a (deep) copy of this SedLine_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
SedLine_t*
SedLine_clone(const SedLine_t* sl);


/**
 * Frees this SedLine_t object.
 *
 * @param sl the SedLine_t structure.
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
void
SedLine_free(SedLine_t* sl);


/**
 * Returns the value of the "type" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedLine_t as a
 * LineType_t.
 *
 * @copydetails doc_sedline_type
 * @if clike The value is drawn from the enumeration @ref LineType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SEDML_LINETYPE_NONE, LineType_t}
 * @li @sbmlconstant{SEDML_LINETYPE_SOLID, LineType_t}
 * @li @sbmlconstant{SEDML_LINETYPE_DASH, LineType_t}
 * @li @sbmlconstant{SEDML_LINETYPE_DOT, LineType_t}
 * @li @sbmlconstant{SEDML_LINETYPE_DASHDOT, LineType_t}
 * @li @sbmlconstant{SEDML_LINETYPE_DASHDOTDOT, LineType_t}
 * @li @sbmlconstant{SEDML_LINETYPE_INVALID, LineType_t}
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
LineType_t
SedLine_getType(const SedLine_t * sl);


/**
 * Returns the value of the "type" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedLine_t as a const char
 * *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sedline_type
 * The possible values returned by this method are:
 * @li @c "none"
 * @li @c "solid"
 * @li @c "dash"
 * @li @c "dot"
 * @li @c "dashDot"
 * @li @c "dashDotDot"
 * @li @c "invalid LineType value"
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
char *
SedLine_getTypeAsString(const SedLine_t * sl);


/**
 * Returns the value of the "color" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure whose color is sought.
 *
 * @return the value of the "color" attribute of this SedLine_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
char *
SedLine_getColor(const SedLine_t * sl);


/**
 * Returns the value of the "thickness" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure whose thickness is sought.
 *
 * @return the value of the "thickness" attribute of this SedLine_t as a
 * double.
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
double
SedLine_getThickness(const SedLine_t * sl);


/**
 * Predicate returning @c 1 (true) if this SedLine_t's "type" attribute is
 * set.
 *
 * @param sl the SedLine_t structure.
 *
 * @return @c 1 (true) if this SedLine_t's "type" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sedline_type
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_isSetType(const SedLine_t * sl);


/**
 * Predicate returning @c 1 (true) if this SedLine_t's "color" attribute is
 * set.
 *
 * @param sl the SedLine_t structure.
 *
 * @return @c 1 (true) if this SedLine_t's "color" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_isSetColor(const SedLine_t * sl);


/**
 * Predicate returning @c 1 (true) if this SedLine_t's "thickness" attribute is
 * set.
 *
 * @param sl the SedLine_t structure.
 *
 * @return @c 1 (true) if this SedLine_t's "thickness" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_isSetThickness(const SedLine_t * sl);


/**
 * Sets the value of the "type" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure.
 *
 * @param type LineType_t value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedline_type
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_setType(SedLine_t * sl, LineType_t type);


/**
 * Sets the value of the "type" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure.
 *
 * @param type const char * of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedline_type
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_setTypeAsString(SedLine_t * sl, const char * type);


/**
 * Sets the value of the "color" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure.
 *
 * @param color const char * value of the "color" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p color = @c NULL or an empty string is
 * equivalent to calling SedLine_unsetColor().
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_setColor(SedLine_t * sl, const char * color);


/**
 * Sets the value of the "thickness" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure.
 *
 * @param thickness double value of the "thickness" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_setThickness(SedLine_t * sl, double thickness);


/**
 * Unsets the value of the "type" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedline_type
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_unsetType(SedLine_t * sl);


/**
 * Unsets the value of the "color" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_unsetColor(SedLine_t * sl);


/**
 * Unsets the value of the "thickness" attribute of this SedLine_t.
 *
 * @param sl the SedLine_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_unsetThickness(SedLine_t * sl);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedLine_t object have been set.
 *
 * @param sl the SedLine_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedLine_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedLine_t
 */
LIBSEDML_EXTERN
int
SedLine_hasRequiredAttributes(const SedLine_t * sl);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedLine_H__ */


