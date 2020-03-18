/**
 * @file SedSetValue.h
 * @brief Definition of the SedSetValue class.
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
 * @class SedSetValue
 * @sbmlbrief{sedml} TODO:Definition of the SedSetValue class.
 */


#ifndef SedSetValue_H__
#define SedSetValue_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/math/ASTNode.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSetValue : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mModelReference;
  std::string mSymbol;
  std::string mTarget;
  std::string mRange;
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* mMath;

  /** @endcond */

public:

  /**
   * Creates a new SedSetValue using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedSetValue.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedSetValue.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSetValue(unsigned int level = SEDML_DEFAULT_LEVEL,
              unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedSetValue using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSetValue(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedSetValue.
   *
   * @param orig the SedSetValue instance to copy.
   */
  SedSetValue(const SedSetValue& orig);


  /**
   * Assignment operator for SedSetValue.
   *
   * @param rhs the SedSetValue object whose values are to be used as the basis
   * of the assignment.
   */
  SedSetValue& operator=(const SedSetValue& rhs);


  /**
   * Creates and returns a deep copy of this SedSetValue object.
   *
   * @return a (deep) copy of this SedSetValue object.
   */
  virtual SedSetValue* clone() const;


  /**
   * Destructor for SedSetValue.
   */
  virtual ~SedSetValue();


  /**
   * Returns the value of the "modelReference" attribute of this SedSetValue.
   *
   * @return the value of the "modelReference" attribute of this SedSetValue as
   * a string.
   */
  const std::string& getModelReference() const;


  /**
   * Returns the value of the "symbol" attribute of this SedSetValue.
   *
   * @return the value of the "symbol" attribute of this SedSetValue as a
   * string.
   */
  const std::string& getSymbol() const;


  /**
   * Returns the value of the "target" attribute of this SedSetValue.
   *
   * @return the value of the "target" attribute of this SedSetValue as a
   * string.
   */
  const std::string& getTarget() const;


  /**
   * Returns the value of the "range" attribute of this SedSetValue.
   *
   * @return the value of the "range" attribute of this SedSetValue as a
   * string.
   */
  const std::string& getRange() const;


  /**
   * Predicate returning @c true if this SedSetValue's "modelReference"
   * attribute is set.
   *
   * @return @c true if this SedSetValue's "modelReference" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetModelReference() const;


  /**
   * Predicate returning @c true if this SedSetValue's "symbol" attribute is
   * set.
   *
   * @return @c true if this SedSetValue's "symbol" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSymbol() const;


  /**
   * Predicate returning @c true if this SedSetValue's "target" attribute is
   * set.
   *
   * @return @c true if this SedSetValue's "target" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Predicate returning @c true if this SedSetValue's "range" attribute is
   * set.
   *
   * @return @c true if this SedSetValue's "range" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRange() const;


  /**
   * Sets the value of the "modelReference" attribute of this SedSetValue.
   *
   * @param modelReference std::string& value of the "modelReference" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setModelReference(const std::string& modelReference);


  /**
   * Sets the value of the "symbol" attribute of this SedSetValue.
   *
   * @param symbol std::string& value of the "symbol" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p symbol = @c NULL or an empty string is
   * equivalent to calling unsetSymbol().
   */
  int setSymbol(const std::string& symbol);


  /**
   * Sets the value of the "target" attribute of this SedSetValue.
   *
   * @param target std::string& value of the "target" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p target = @c NULL or an empty string is
   * equivalent to calling unsetTarget().
   */
  int setTarget(const std::string& target);


  /**
   * Sets the value of the "range" attribute of this SedSetValue.
   *
   * @param range std::string& value of the "range" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRange(const std::string& range);


  /**
   * Unsets the value of the "modelReference" attribute of this SedSetValue.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetModelReference();


  /**
   * Unsets the value of the "symbol" attribute of this SedSetValue.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSymbol();


  /**
   * Unsets the value of the "target" attribute of this SedSetValue.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Unsets the value of the "range" attribute of this SedSetValue.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRange();


  /**
   * Returns the value of the "math" element of this SedSetValue.
   *
   * @return the value of the "math" element of this SedSetValue as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath() const;


  /**
   * Returns the value of the "math" element of this SedSetValue.
   *
   * @return the value of the "math" element of this SedSetValue as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath();


  /**
   * Predicate returning @c true if this SedSetValue's "math" element is set.
   *
   * @return @c true if this SedSetValue's "math" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMath() const;


  /**
   * Sets the value of the "math" element of this SedSetValue.
   *
   * @param math LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* value of the "math"
   * element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMath(const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* math);


  /**
   * Unsets the value of the "math" element of this SedSetValue.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMath();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedSetValue object.
   *
   * For SedSetValue, the XML element name is always @c "setValue".
   *
   * @return the name of this element, i.e. @c "setValue".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedSetValue object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   * @sedmlconstant{SEDML_TASK_SETVALUE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedSetValue object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedSetValue have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedSetValue object are:
   * @li "modelReference"
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



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedSetValue.
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
   * Gets the value of the "attributeName" attribute of this SedSetValue.
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
   * Gets the value of the "attributeName" attribute of this SedSetValue.
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
   * Gets the value of the "attributeName" attribute of this SedSetValue.
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
   * Gets the value of the "attributeName" attribute of this SedSetValue.
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
   * Predicate returning @c true if this SedSetValue's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedSetValue's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedSetValue.
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
   * Sets the value of the "attributeName" attribute of this SedSetValue.
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
   * Sets the value of the "attributeName" attribute of this SedSetValue.
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
   * Sets the value of the "attributeName" attribute of this SedSetValue.
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
   * Sets the value of the "attributeName" attribute of this SedSetValue.
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
   * Unsets the value of the "attributeName" attribute of this SedSetValue.
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
   * Reads other XML such as math/notes etc.
   */
  virtual bool readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

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
 * Creates a new SedSetValue_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedSetValue_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedSetValue_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
SedSetValue_t *
SedSetValue_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedSetValue_t object.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @return a (deep) copy of this SedSetValue_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedSetValue_clone(const SedSetValue_t* ssv);


/**
 * Frees this SedSetValue_t object.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
void
SedSetValue_free(SedSetValue_t* ssv);


/**
 * Returns the value of the "modelReference" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure whose modelReference is sought.
 *
 * @return the value of the "modelReference" attribute of this SedSetValue_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
char *
SedSetValue_getModelReference(const SedSetValue_t * ssv);


/**
 * Returns the value of the "symbol" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure whose symbol is sought.
 *
 * @return the value of the "symbol" attribute of this SedSetValue_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
char *
SedSetValue_getSymbol(const SedSetValue_t * ssv);


/**
 * Returns the value of the "target" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SedSetValue_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
char *
SedSetValue_getTarget(const SedSetValue_t * ssv);


/**
 * Returns the value of the "range" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure whose range is sought.
 *
 * @return the value of the "range" attribute of this SedSetValue_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
char *
SedSetValue_getRange(const SedSetValue_t * ssv);


/**
 * Predicate returning @c 1 (true) if this SedSetValue_t's "modelReference"
 * attribute is set.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @return @c 1 (true) if this SedSetValue_t's "modelReference" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetModelReference(const SedSetValue_t * ssv);


/**
 * Predicate returning @c 1 (true) if this SedSetValue_t's "symbol" attribute
 * is set.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @return @c 1 (true) if this SedSetValue_t's "symbol" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetSymbol(const SedSetValue_t * ssv);


/**
 * Predicate returning @c 1 (true) if this SedSetValue_t's "target" attribute
 * is set.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @return @c 1 (true) if this SedSetValue_t's "target" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetTarget(const SedSetValue_t * ssv);


/**
 * Predicate returning @c 1 (true) if this SedSetValue_t's "range" attribute is
 * set.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @return @c 1 (true) if this SedSetValue_t's "range" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetRange(const SedSetValue_t * ssv);


/**
 * Sets the value of the "modelReference" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @param modelReference const char * value of the "modelReference" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_setModelReference(SedSetValue_t * ssv,
                              const char * modelReference);


/**
 * Sets the value of the "symbol" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @param symbol const char * value of the "symbol" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p symbol = @c NULL or an empty string is
 * equivalent to calling SedSetValue_unsetSymbol().
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_setSymbol(SedSetValue_t * ssv, const char * symbol);


/**
 * Sets the value of the "target" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p target = @c NULL or an empty string is
 * equivalent to calling SedSetValue_unsetTarget().
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_setTarget(SedSetValue_t * ssv, const char * target);


/**
 * Sets the value of the "range" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @param range const char * value of the "range" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_setRange(SedSetValue_t * ssv, const char * range);


/**
 * Unsets the value of the "modelReference" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetModelReference(SedSetValue_t * ssv);


/**
 * Unsets the value of the "symbol" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetSymbol(SedSetValue_t * ssv);


/**
 * Unsets the value of the "target" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetTarget(SedSetValue_t * ssv);


/**
 * Unsets the value of the "range" attribute of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetRange(SedSetValue_t * ssv);


/**
 * Returns the value of the "math" element of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure whose math is sought.
 *
 * @return the value of the "math" element of this SedSetValue_t as a pointer
 * to an ASTNode_t object.
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
SedSetValue_getMath(const SedSetValue_t * ssv);


/**
 * Predicate returning @c 1 (true) if this SedSetValue_t's "math" element is
 * set.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @return @c 1 (true) if this SedSetValue_t's "math" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetMath(const SedSetValue_t * ssv);


/**
 * Sets the value of the "math" element of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @param math LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t* value of the "math"
 * element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_setMath(SedSetValue_t * ssv,
                    const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t* math);


/**
 * Unsets the value of the "math" element of this SedSetValue_t.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetMath(SedSetValue_t * ssv);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSetValue_t object have been set.
 *
 * @param ssv the SedSetValue_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedSetValue_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedSetValue_t object are:
 * @li "modelReference"
 *
 * @memberof SedSetValue_t
 */
LIBSEDML_EXTERN
int
SedSetValue_hasRequiredAttributes(const SedSetValue_t * ssv);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedSetValue_H__ */


