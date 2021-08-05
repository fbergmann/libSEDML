/**
 * @file SedBounds.h
 * @brief Definition of the SedBounds class.
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
 * @class SedBounds
 * @sbmlbrief{sedml} TODO:Definition of the SedBounds class.
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
 * @class doc_sedbounds_scale
 *
 * @par
 * The attribute "scale" on a SedBounds object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sedml specification, the following are the
 * allowable values for "scale":
 * <ul>
 * <li> @c "linear", TODO:add description
 *
 * <li> @c "log", TODO:add description
 *
 * <li> @c "log10", TODO:add description
 *
 * </ul>
 */


#ifndef SedBounds_H__
#define SedBounds_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/common/SedmlEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedBounds : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mLowerBound;
  bool mIsSetLowerBound;
  double mUpperBound;
  bool mIsSetUpperBound;
  ScaleType_t mScale;

  /** @endcond */

public:

  /**
   * Creates a new SedBounds using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedBounds.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedBounds.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedBounds(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedBounds using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedBounds(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedBounds.
   *
   * @param orig the SedBounds instance to copy.
   */
  SedBounds(const SedBounds& orig);


  /**
   * Assignment operator for SedBounds.
   *
   * @param rhs the SedBounds object whose values are to be used as the basis
   * of the assignment.
   */
  SedBounds& operator=(const SedBounds& rhs);


  /**
   * Creates and returns a deep copy of this SedBounds object.
   *
   * @return a (deep) copy of this SedBounds object.
   */
  virtual SedBounds* clone() const;


  /**
   * Destructor for SedBounds.
   */
  virtual ~SedBounds();


  /**
   * Returns the value of the "lowerBound" attribute of this SedBounds.
   *
   * @return the value of the "lowerBound" attribute of this SedBounds as a
   * double.
   */
  double getLowerBound() const;


  /**
   * Returns the value of the "upperBound" attribute of this SedBounds.
   *
   * @return the value of the "upperBound" attribute of this SedBounds as a
   * double.
   */
  double getUpperBound() const;


  /**
   * Returns the value of the "scale" attribute of this SedBounds.
   *
   * @return the value of the "scale" attribute of this SedBounds as a
   * ScaleType_t.
   *
   * @copydetails doc_sedbounds_scale
   * @if clike The value is drawn from the enumeration @ref ScaleType_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SEDML_SCALETYPE_LINEAR, ScaleType_t}
   * @li @sbmlconstant{SEDML_SCALETYPE_LOG, ScaleType_t}
   * @li @sbmlconstant{SEDML_SCALETYPE_LOG10, ScaleType_t}
   * @li @sbmlconstant{SEDML_SCALETYPE_INVALID, ScaleType_t}
   */
  ScaleType_t getScale() const;


  /**
   * Returns the value of the "scale" attribute of this SedBounds.
   *
   * @return the value of the "scale" attribute of this SedBounds as a string.
   *
   * @copydetails doc_sedbounds_scale
   * The possible values returned by this method are:
   * @li @c "linear"
   * @li @c "log"
   * @li @c "log10"
   * @li @c "invalid ScaleType value"
   */
  std::string getScaleAsString() const;


  /**
   * Predicate returning @c true if this SedBounds's "lowerBound" attribute is
   * set.
   *
   * @return @c true if this SedBounds's "lowerBound" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLowerBound() const;


  /**
   * Predicate returning @c true if this SedBounds's "upperBound" attribute is
   * set.
   *
   * @return @c true if this SedBounds's "upperBound" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetUpperBound() const;


  /**
   * Predicate returning @c true if this SedBounds's "scale" attribute is set.
   *
   * @return @c true if this SedBounds's "scale" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sedbounds_scale
   */
  bool isSetScale() const;


  /**
   * Sets the value of the "lowerBound" attribute of this SedBounds.
   *
   * @param lowerBound double value of the "lowerBound" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLowerBound(double lowerBound);


  /**
   * Sets the value of the "upperBound" attribute of this SedBounds.
   *
   * @param upperBound double value of the "upperBound" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUpperBound(double upperBound);


  /**
   * Sets the value of the "scale" attribute of this SedBounds.
   *
   * @param scale @if clike ScaleType_t@else int@endif value of the "scale"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedbounds_scale
   */
  int setScale(const ScaleType_t scale);


  /**
   * Sets the value of the "scale" attribute of this SedBounds.
   *
   * @param scale std::string& of the "scale" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedbounds_scale
   */
  int setScale(const std::string& scale);


  /**
   * Unsets the value of the "lowerBound" attribute of this SedBounds.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLowerBound();


  /**
   * Unsets the value of the "upperBound" attribute of this SedBounds.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUpperBound();


  /**
   * Unsets the value of the "scale" attribute of this SedBounds.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sedbounds_scale
   */
  int unsetScale();


  /**
   * Returns the XML element name of this SedBounds object.
   *
   * For SedBounds, the XML element name is always @c "bounds".
   *
   * @return the name of this element, i.e. @c "bounds".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedBounds object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_BOUNDS, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedBounds object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedBounds have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SedBounds.
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
   * Gets the value of the "attributeName" attribute of this SedBounds.
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
   * Gets the value of the "attributeName" attribute of this SedBounds.
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
   * Gets the value of the "attributeName" attribute of this SedBounds.
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
   * Gets the value of the "attributeName" attribute of this SedBounds.
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
   * Predicate returning @c true if this SedBounds's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedBounds's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedBounds.
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
   * Sets the value of the "attributeName" attribute of this SedBounds.
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
   * Sets the value of the "attributeName" attribute of this SedBounds.
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
   * Sets the value of the "attributeName" attribute of this SedBounds.
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
   * Sets the value of the "attributeName" attribute of this SedBounds.
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
   * Unsets the value of the "attributeName" attribute of this SedBounds.
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
 * Creates a new SedBounds_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedBounds_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedBounds_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
SedBounds_t *
SedBounds_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedBounds_t object.
 *
 * @param sb the SedBounds_t structure.
 *
 * @return a (deep) copy of this SedBounds_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
SedBounds_t*
SedBounds_clone(const SedBounds_t* sb);


/**
 * Frees this SedBounds_t object.
 *
 * @param sb the SedBounds_t structure.
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
void
SedBounds_free(SedBounds_t* sb);


/**
 * Returns the value of the "lowerBound" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure whose lowerBound is sought.
 *
 * @return the value of the "lowerBound" attribute of this SedBounds_t as a
 * double.
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
double
SedBounds_getLowerBound(const SedBounds_t * sb);


/**
 * Returns the value of the "upperBound" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure whose upperBound is sought.
 *
 * @return the value of the "upperBound" attribute of this SedBounds_t as a
 * double.
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
double
SedBounds_getUpperBound(const SedBounds_t * sb);


/**
 * Returns the value of the "scale" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure whose scale is sought.
 *
 * @return the value of the "scale" attribute of this SedBounds_t as a
 * ScaleType_t.
 *
 * @copydetails doc_sedbounds_scale
 * @if clike The value is drawn from the enumeration @ref ScaleType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SEDML_SCALETYPE_LINEAR, ScaleType_t}
 * @li @sbmlconstant{SEDML_SCALETYPE_LOG, ScaleType_t}
 * @li @sbmlconstant{SEDML_SCALETYPE_LOG10, ScaleType_t}
 * @li @sbmlconstant{SEDML_SCALETYPE_INVALID, ScaleType_t}
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
ScaleType_t
SedBounds_getScale(const SedBounds_t * sb);


/**
 * Returns the value of the "scale" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure whose scale is sought.

 *
 * @return the value of the "scale" attribute of this SedBounds_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sedbounds_scale
 * The possible values returned by this method are:
 * @li @c "linear"
 * @li @c "log"
 * @li @c "log10"
 * @li @c "invalid ScaleType value"
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
char *
SedBounds_getScaleAsString(const SedBounds_t * sb);


/**
 * Predicate returning @c 1 (true) if this SedBounds_t's "lowerBound" attribute
 * is set.
 *
 * @param sb the SedBounds_t structure.
 *
 * @return @c 1 (true) if this SedBounds_t's "lowerBound" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_isSetLowerBound(const SedBounds_t * sb);


/**
 * Predicate returning @c 1 (true) if this SedBounds_t's "upperBound" attribute
 * is set.
 *
 * @param sb the SedBounds_t structure.
 *
 * @return @c 1 (true) if this SedBounds_t's "upperBound" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_isSetUpperBound(const SedBounds_t * sb);


/**
 * Predicate returning @c 1 (true) if this SedBounds_t's "scale" attribute is
 * set.
 *
 * @param sb the SedBounds_t structure.
 *
 * @return @c 1 (true) if this SedBounds_t's "scale" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sedbounds_scale
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_isSetScale(const SedBounds_t * sb);


/**
 * Sets the value of the "lowerBound" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure.
 *
 * @param lowerBound double value of the "lowerBound" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_setLowerBound(SedBounds_t * sb, double lowerBound);


/**
 * Sets the value of the "upperBound" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure.
 *
 * @param upperBound double value of the "upperBound" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_setUpperBound(SedBounds_t * sb, double upperBound);


/**
 * Sets the value of the "scale" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure.
 *
 * @param scale ScaleType_t value of the "scale" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedbounds_scale
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_setScale(SedBounds_t * sb, ScaleType_t scale);


/**
 * Sets the value of the "scale" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure.
 *
 * @param scale const char * of the "scale" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedbounds_scale
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_setScaleAsString(SedBounds_t * sb, const char * scale);


/**
 * Unsets the value of the "lowerBound" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_unsetLowerBound(SedBounds_t * sb);


/**
 * Unsets the value of the "upperBound" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_unsetUpperBound(SedBounds_t * sb);


/**
 * Unsets the value of the "scale" attribute of this SedBounds_t.
 *
 * @param sb the SedBounds_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedbounds_scale
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_unsetScale(SedBounds_t * sb);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedBounds_t object have been set.
 *
 * @param sb the SedBounds_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedBounds_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedBounds_t
 */
LIBSEDML_EXTERN
int
SedBounds_hasRequiredAttributes(const SedBounds_t * sb);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedBounds_H__ */


