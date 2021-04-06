/**
 * @file SedSubPlot.h
 * @brief Definition of the SedSubPlot class.
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
 * @class SedSubPlot
 * @sbmlbrief{sedml} TODO:Definition of the SedSubPlot class.
 */


#ifndef SedSubPlot_H__
#define SedSubPlot_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSubPlot : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mPlot;
  int mRow;
  bool mIsSetRow;
  int mCol;
  bool mIsSetCol;
  int mRowSpan;
  bool mIsSetRowSpan;
  int mColSpan;
  bool mIsSetColSpan;

  /** @endcond */

public:

  /**
   * Creates a new SedSubPlot using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedSubPlot.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedSubPlot.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSubPlot(unsigned int level = SEDML_DEFAULT_LEVEL,
             unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedSubPlot using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSubPlot(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedSubPlot.
   *
   * @param orig the SedSubPlot instance to copy.
   */
  SedSubPlot(const SedSubPlot& orig);


  /**
   * Assignment operator for SedSubPlot.
   *
   * @param rhs the SedSubPlot object whose values are to be used as the basis
   * of the assignment.
   */
  SedSubPlot& operator=(const SedSubPlot& rhs);


  /**
   * Creates and returns a deep copy of this SedSubPlot object.
   *
   * @return a (deep) copy of this SedSubPlot object.
   */
  virtual SedSubPlot* clone() const;


  /**
   * Destructor for SedSubPlot.
   */
  virtual ~SedSubPlot();


  /**
   * Returns the value of the "plot" attribute of this SedSubPlot.
   *
   * @return the value of the "plot" attribute of this SedSubPlot as a string.
   */
  const std::string& getPlot() const;


  /**
   * Returns the value of the "row" attribute of this SedSubPlot.
   *
   * @return the value of the "row" attribute of this SedSubPlot as a integer.
   */
  int getRow() const;


  /**
   * Returns the value of the "col" attribute of this SedSubPlot.
   *
   * @return the value of the "col" attribute of this SedSubPlot as a integer.
   */
  int getCol() const;


  /**
   * Returns the value of the "rowSpan" attribute of this SedSubPlot.
   *
   * @return the value of the "rowSpan" attribute of this SedSubPlot as a
   * integer.
   */
  int getRowSpan() const;


  /**
   * Returns the value of the "colSpan" attribute of this SedSubPlot.
   *
   * @return the value of the "colSpan" attribute of this SedSubPlot as a
   * integer.
   */
  int getColSpan() const;


  /**
   * Predicate returning @c true if this SedSubPlot's "plot" attribute is set.
   *
   * @return @c true if this SedSubPlot's "plot" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetPlot() const;


  /**
   * Predicate returning @c true if this SedSubPlot's "row" attribute is set.
   *
   * @return @c true if this SedSubPlot's "row" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRow() const;


  /**
   * Predicate returning @c true if this SedSubPlot's "col" attribute is set.
   *
   * @return @c true if this SedSubPlot's "col" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetCol() const;


  /**
   * Predicate returning @c true if this SedSubPlot's "rowSpan" attribute is
   * set.
   *
   * @return @c true if this SedSubPlot's "rowSpan" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRowSpan() const;


  /**
   * Predicate returning @c true if this SedSubPlot's "colSpan" attribute is
   * set.
   *
   * @return @c true if this SedSubPlot's "colSpan" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetColSpan() const;


  /**
   * Sets the value of the "plot" attribute of this SedSubPlot.
   *
   * @param plot std::string& value of the "plot" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPlot(const std::string& plot);


  /**
   * Sets the value of the "row" attribute of this SedSubPlot.
   *
   * @param row int value of the "row" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRow(int row);


  /**
   * Sets the value of the "col" attribute of this SedSubPlot.
   *
   * @param col int value of the "col" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCol(int col);


  /**
   * Sets the value of the "rowSpan" attribute of this SedSubPlot.
   *
   * @param rowSpan int value of the "rowSpan" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRowSpan(int rowSpan);


  /**
   * Sets the value of the "colSpan" attribute of this SedSubPlot.
   *
   * @param colSpan int value of the "colSpan" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setColSpan(int colSpan);


  /**
   * Unsets the value of the "plot" attribute of this SedSubPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPlot();


  /**
   * Unsets the value of the "row" attribute of this SedSubPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRow();


  /**
   * Unsets the value of the "col" attribute of this SedSubPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCol();


  /**
   * Unsets the value of the "rowSpan" attribute of this SedSubPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRowSpan();


  /**
   * Unsets the value of the "colSpan" attribute of this SedSubPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetColSpan();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedSubPlot object.
   *
   * For SedSubPlot, the XML element name is always @c "subPlot".
   *
   * @return the name of this element, i.e. @c "subPlot".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedSubPlot object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_SUBPLOT, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedSubPlot object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedSubPlot have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedSubPlot object are:
   * @li "plot"
   * @li "row"
   * @li "col"
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
   * Gets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Gets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Gets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Gets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Gets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Predicate returning @c true if this SedSubPlot's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedSubPlot's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Sets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Sets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Sets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Sets the value of the "attributeName" attribute of this SedSubPlot.
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
   * Unsets the value of the "attributeName" attribute of this SedSubPlot.
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
 * Creates a new SedSubPlot_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedSubPlot_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedSubPlot_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
SedSubPlot_t *
SedSubPlot_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedSubPlot_t object.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @return a (deep) copy of this SedSubPlot_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedSubPlot_clone(const SedSubPlot_t* ssp);


/**
 * Frees this SedSubPlot_t object.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
void
SedSubPlot_free(SedSubPlot_t* ssp);


/**
 * Returns the value of the "plot" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure whose plot is sought.
 *
 * @return the value of the "plot" attribute of this SedSubPlot_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
char *
SedSubPlot_getPlot(const SedSubPlot_t * ssp);


/**
 * Returns the value of the "row" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure whose row is sought.
 *
 * @return the value of the "row" attribute of this SedSubPlot_t as a integer.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_getRow(const SedSubPlot_t * ssp);


/**
 * Returns the value of the "col" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure whose col is sought.
 *
 * @return the value of the "col" attribute of this SedSubPlot_t as a integer.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_getCol(const SedSubPlot_t * ssp);


/**
 * Returns the value of the "rowSpan" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure whose rowSpan is sought.
 *
 * @return the value of the "rowSpan" attribute of this SedSubPlot_t as a
 * integer.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_getRowSpan(const SedSubPlot_t * ssp);


/**
 * Returns the value of the "colSpan" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure whose colSpan is sought.
 *
 * @return the value of the "colSpan" attribute of this SedSubPlot_t as a
 * integer.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_getColSpan(const SedSubPlot_t * ssp);


/**
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "plot" attribute is
 * set.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @return @c 1 (true) if this SedSubPlot_t's "plot" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetPlot(const SedSubPlot_t * ssp);


/**
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "row" attribute is
 * set.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @return @c 1 (true) if this SedSubPlot_t's "row" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetRow(const SedSubPlot_t * ssp);


/**
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "col" attribute is
 * set.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @return @c 1 (true) if this SedSubPlot_t's "col" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetCol(const SedSubPlot_t * ssp);


/**
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "rowSpan" attribute
 * is set.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @return @c 1 (true) if this SedSubPlot_t's "rowSpan" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetRowSpan(const SedSubPlot_t * ssp);


/**
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "colSpan" attribute
 * is set.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @return @c 1 (true) if this SedSubPlot_t's "colSpan" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetColSpan(const SedSubPlot_t * ssp);


/**
 * Sets the value of the "plot" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @param plot const char * value of the "plot" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_setPlot(SedSubPlot_t * ssp, const char * plot);


/**
 * Sets the value of the "row" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @param row int value of the "row" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_setRow(SedSubPlot_t * ssp, int row);


/**
 * Sets the value of the "col" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @param col int value of the "col" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_setCol(SedSubPlot_t * ssp, int col);


/**
 * Sets the value of the "rowSpan" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @param rowSpan int value of the "rowSpan" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_setRowSpan(SedSubPlot_t * ssp, int rowSpan);


/**
 * Sets the value of the "colSpan" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @param colSpan int value of the "colSpan" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_setColSpan(SedSubPlot_t * ssp, int colSpan);


/**
 * Unsets the value of the "plot" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetPlot(SedSubPlot_t * ssp);


/**
 * Unsets the value of the "row" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetRow(SedSubPlot_t * ssp);


/**
 * Unsets the value of the "col" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetCol(SedSubPlot_t * ssp);


/**
 * Unsets the value of the "rowSpan" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetRowSpan(SedSubPlot_t * ssp);


/**
 * Unsets the value of the "colSpan" attribute of this SedSubPlot_t.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetColSpan(SedSubPlot_t * ssp);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSubPlot_t object have been set.
 *
 * @param ssp the SedSubPlot_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedSubPlot_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedSubPlot_t object are:
 * @li "plot"
 * @li "row"
 * @li "col"
 *
 * @memberof SedSubPlot_t
 */
LIBSEDML_EXTERN
int
SedSubPlot_hasRequiredAttributes(const SedSubPlot_t * ssp);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedSubPlot_H__ */


