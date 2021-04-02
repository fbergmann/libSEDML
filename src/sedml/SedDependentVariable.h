/**
 * @file SedDependentVariable.h
 * @brief Definition of the SedDependentVariable class.
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
 * @class SedDependentVariable
 * @sbmlbrief{sedml} TODO:Definition of the SedDependentVariable class.
 */


#ifndef SedDependentVariable_H__
#define SedDependentVariable_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedVariable.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDependentVariable : public SedVariable
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mTerm;
  std::string mTarget2;
  std::string mSymbol2;

  /** @endcond */

public:

  /**
   * Creates a new SedDependentVariable using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedDependentVariable.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedDependentVariable.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDependentVariable(unsigned int level = SEDML_DEFAULT_LEVEL,
                       unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDependentVariable using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDependentVariable(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedDependentVariable.
   *
   * @param orig the SedDependentVariable instance to copy.
   */
  SedDependentVariable(const SedDependentVariable& orig);


  /**
   * Assignment operator for SedDependentVariable.
   *
   * @param rhs the SedDependentVariable object whose values are to be used as
   * the basis of the assignment.
   */
  SedDependentVariable& operator=(const SedDependentVariable& rhs);


  /**
   * Creates and returns a deep copy of this SedDependentVariable object.
   *
   * @return a (deep) copy of this SedDependentVariable object.
   */
  virtual SedDependentVariable* clone() const;


  /**
   * Destructor for SedDependentVariable.
   */
  virtual ~SedDependentVariable();


  /**
   * Returns the value of the "term" attribute of this SedDependentVariable.
   *
   * @return the value of the "term" attribute of this SedDependentVariable as
   * a string.
   */
  const std::string& getTerm() const;


  /**
   * Returns the value of the "target2" attribute of this SedDependentVariable.
   *
   * @return the value of the "target2" attribute of this SedDependentVariable
   * as a string.
   */
  const std::string& getTarget2() const;


  /**
   * Returns the value of the "symbol2" attribute of this SedDependentVariable.
   *
   * @return the value of the "symbol2" attribute of this SedDependentVariable
   * as a string.
   */
  const std::string& getSymbol2() const;


  /**
   * Predicate returning @c true if this SedDependentVariable's "term"
   * attribute is set.
   *
   * @return @c true if this SedDependentVariable's "term" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetTerm() const;


  /**
   * Predicate returning @c true if this SedDependentVariable's "target2"
   * attribute is set.
   *
   * @return @c true if this SedDependentVariable's "target2" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetTarget2() const;


  /**
   * Predicate returning @c true if this SedDependentVariable's "symbol2"
   * attribute is set.
   *
   * @return @c true if this SedDependentVariable's "symbol2" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetSymbol2() const;


  /**
   * Sets the value of the "term" attribute of this SedDependentVariable.
   *
   * @param term std::string& value of the "term" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p term = @c NULL or an empty string is
   * equivalent to calling unsetTerm().
   */
  int setTerm(const std::string& term);


  /**
   * Sets the value of the "target2" attribute of this SedDependentVariable.
   *
   * @param target2 std::string& value of the "target2" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p target2 = @c NULL or an empty string is
   * equivalent to calling unsetTarget2().
   */
  int setTarget2(const std::string& target2);


  /**
   * Sets the value of the "symbol2" attribute of this SedDependentVariable.
   *
   * @param symbol2 std::string& value of the "symbol2" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p symbol2 = @c NULL or an empty string is
   * equivalent to calling unsetSymbol2().
   */
  int setSymbol2(const std::string& symbol2);


  /**
   * Unsets the value of the "term" attribute of this SedDependentVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTerm();


  /**
   * Unsets the value of the "target2" attribute of this SedDependentVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget2();


  /**
   * Unsets the value of the "symbol2" attribute of this SedDependentVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSymbol2();


  /**
   * Returns the XML element name of this SedDependentVariable object.
   *
   * For SedDependentVariable, the XML element name is always
   * @c "dependentVariable".
   *
   * @return the name of this element, i.e. @c "dependentVariable".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedDependentVariable object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_DEPENDENTVARIABLE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedDependentVariable object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedDependentVariable have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedDependentVariable object are:
   * @li "term"
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
   * Gets the value of the "attributeName" attribute of this
   * SedDependentVariable.
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
   * SedDependentVariable.
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
   * SedDependentVariable.
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
   * SedDependentVariable.
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
   * SedDependentVariable.
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
   * Predicate returning @c true if this SedDependentVariable's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedDependentVariable's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedDependentVariable.
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
   * SedDependentVariable.
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
   * SedDependentVariable.
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
   * SedDependentVariable.
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
   * SedDependentVariable.
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
   * SedDependentVariable.
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
 * Creates a new SedDependentVariable_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedDependentVariable_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedDependentVariable_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
SedDependentVariable_t *
SedDependentVariable_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedDependentVariable_t object.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @return a (deep) copy of this SedDependentVariable_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
SedDependentVariable_t*
SedDependentVariable_clone(const SedDependentVariable_t* sdv);


/**
 * Frees this SedDependentVariable_t object.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
void
SedDependentVariable_free(SedDependentVariable_t* sdv);


/**
 * Returns the value of the "term" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure whose term is sought.
 *
 * @return the value of the "term" attribute of this SedDependentVariable_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
char *
SedDependentVariable_getTerm(const SedDependentVariable_t * sdv);


/**
 * Returns the value of the "target2" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure whose target2 is sought.
 *
 * @return the value of the "target2" attribute of this SedDependentVariable_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
char *
SedDependentVariable_getTarget2(const SedDependentVariable_t * sdv);


/**
 * Returns the value of the "symbol2" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure whose symbol2 is sought.
 *
 * @return the value of the "symbol2" attribute of this SedDependentVariable_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
char *
SedDependentVariable_getSymbol2(const SedDependentVariable_t * sdv);


/**
 * Predicate returning @c 1 (true) if this SedDependentVariable_t's "term"
 * attribute is set.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @return @c 1 (true) if this SedDependentVariable_t's "term" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_isSetTerm(const SedDependentVariable_t * sdv);


/**
 * Predicate returning @c 1 (true) if this SedDependentVariable_t's "target2"
 * attribute is set.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @return @c 1 (true) if this SedDependentVariable_t's "target2" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_isSetTarget2(const SedDependentVariable_t * sdv);


/**
 * Predicate returning @c 1 (true) if this SedDependentVariable_t's "symbol2"
 * attribute is set.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @return @c 1 (true) if this SedDependentVariable_t's "symbol2" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_isSetSymbol2(const SedDependentVariable_t * sdv);


/**
 * Sets the value of the "term" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @param term const char * value of the "term" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p term = @c NULL or an empty string is
 * equivalent to calling SedDependentVariable_unsetTerm().
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_setTerm(SedDependentVariable_t * sdv, const char * term);


/**
 * Sets the value of the "target2" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @param target2 const char * value of the "target2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p target2 = @c NULL or an empty string is
 * equivalent to calling SedDependentVariable_unsetTarget2().
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_setTarget2(SedDependentVariable_t * sdv,
                                const char * target2);


/**
 * Sets the value of the "symbol2" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @param symbol2 const char * value of the "symbol2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p symbol2 = @c NULL or an empty string is
 * equivalent to calling SedDependentVariable_unsetSymbol2().
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_setSymbol2(SedDependentVariable_t * sdv,
                                const char * symbol2);


/**
 * Unsets the value of the "term" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_unsetTerm(SedDependentVariable_t * sdv);


/**
 * Unsets the value of the "target2" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_unsetTarget2(SedDependentVariable_t * sdv);


/**
 * Unsets the value of the "symbol2" attribute of this SedDependentVariable_t.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_unsetSymbol2(SedDependentVariable_t * sdv);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDependentVariable_t object have been set.
 *
 * @param sdv the SedDependentVariable_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedDependentVariable_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedDependentVariable_t object are:
 * @li "term"
 *
 * @memberof SedDependentVariable_t
 */
LIBSEDML_EXTERN
int
SedDependentVariable_hasRequiredAttributes(const SedDependentVariable_t * sdv);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedDependentVariable_H__ */


