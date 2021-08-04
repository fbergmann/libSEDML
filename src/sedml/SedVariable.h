/**
 * @file SedVariable.h
 * @brief Definition of the SedVariable class.
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
 * @class SedVariable
 * @sbmlbrief{sedml} TODO:Definition of the SedVariable class.
 */


#ifndef SedVariable_H__
#define SedVariable_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOfAppliedDimensions.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedVariable : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mSymbol;
  std::string mTarget;
  std::string mTaskReference;
  std::string mModelReference;
  SedListOfAppliedDimensions mAppliedDimensions;
  std::string mTerm;
  std::string mSymbol2;
  std::string mTarget2;
  std::string mDimensionTerm;

  /** @endcond */

public:

  /**
   * Creates a new SedVariable using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedVariable.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedVariable.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedVariable(unsigned int level = SEDML_DEFAULT_LEVEL,
              unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedVariable using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedVariable(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedVariable.
   *
   * @param orig the SedVariable instance to copy.
   */
  SedVariable(const SedVariable& orig);


  /**
   * Assignment operator for SedVariable.
   *
   * @param rhs the SedVariable object whose values are to be used as the basis
   * of the assignment.
   */
  SedVariable& operator=(const SedVariable& rhs);


  /**
   * Creates and returns a deep copy of this SedVariable object.
   *
   * @return a (deep) copy of this SedVariable object.
   */
  virtual SedVariable* clone() const;


  /**
   * Destructor for SedVariable.
   */
  virtual ~SedVariable();


  /**
   * Returns the value of the "symbol" attribute of this SedVariable.
   *
   * @return the value of the "symbol" attribute of this SedVariable as a
   * string.
   */
  const std::string& getSymbol() const;


  /**
   * Returns the value of the "target" attribute of this SedVariable.
   *
   * @return the value of the "target" attribute of this SedVariable as a
   * string.
   */
  const std::string& getTarget() const;


  /**
   * Returns the value of the "taskReference" attribute of this SedVariable.
   *
   * @return the value of the "taskReference" attribute of this SedVariable as
   * a string.
   */
  const std::string& getTaskReference() const;


  /**
   * Returns the value of the "modelReference" attribute of this SedVariable.
   *
   * @return the value of the "modelReference" attribute of this SedVariable as
   * a string.
   */
  const std::string& getModelReference() const;


  /**
   * Returns the value of the "term" attribute of this SedVariable.
   *
   * @return the value of the "term" attribute of this SedVariable as a string.
   */
  const std::string& getTerm() const;


  /**
   * Returns the value of the "symbol2" attribute of this SedVariable.
   *
   * @return the value of the "symbol2" attribute of this SedVariable as a
   * string.
   */
  const std::string& getSymbol2() const;


  /**
   * Returns the value of the "target2" attribute of this SedVariable.
   *
   * @return the value of the "target2" attribute of this SedVariable as a
   * string.
   */
  const std::string& getTarget2() const;


  /**
   * Returns the value of the "dimensionTerm" attribute of this SedVariable.
   *
   * @return the value of the "dimensionTerm" attribute of this SedVariable as
   * a string.
   */
  const std::string& getDimensionTerm() const;


  /**
   * Predicate returning @c true if this SedVariable's "symbol" attribute is
   * set.
   *
   * @return @c true if this SedVariable's "symbol" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSymbol() const;


  /**
   * Predicate returning @c true if this SedVariable's "target" attribute is
   * set.
   *
   * @return @c true if this SedVariable's "target" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Predicate returning @c true if this SedVariable's "taskReference"
   * attribute is set.
   *
   * @return @c true if this SedVariable's "taskReference" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetTaskReference() const;


  /**
   * Predicate returning @c true if this SedVariable's "modelReference"
   * attribute is set.
   *
   * @return @c true if this SedVariable's "modelReference" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetModelReference() const;


  /**
   * Predicate returning @c true if this SedVariable's "term" attribute is set.
   *
   * @return @c true if this SedVariable's "term" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTerm() const;


  /**
   * Predicate returning @c true if this SedVariable's "symbol2" attribute is
   * set.
   *
   * @return @c true if this SedVariable's "symbol2" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSymbol2() const;


  /**
   * Predicate returning @c true if this SedVariable's "target2" attribute is
   * set.
   *
   * @return @c true if this SedVariable's "target2" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTarget2() const;


  /**
   * Predicate returning @c true if this SedVariable's "dimensionTerm"
   * attribute is set.
   *
   * @return @c true if this SedVariable's "dimensionTerm" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetDimensionTerm() const;


  /**
   * Sets the value of the "symbol" attribute of this SedVariable.
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
   * Sets the value of the "target" attribute of this SedVariable.
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
   * Sets the value of the "taskReference" attribute of this SedVariable.
   *
   * @param taskReference std::string& value of the "taskReference" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTaskReference(const std::string& taskReference);


  /**
   * Sets the value of the "modelReference" attribute of this SedVariable.
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
   * Sets the value of the "term" attribute of this SedVariable.
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
   * Sets the value of the "symbol2" attribute of this SedVariable.
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
   * Sets the value of the "target2" attribute of this SedVariable.
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
   * Sets the value of the "dimensionTerm" attribute of this SedVariable.
   *
   * @param dimensionTerm std::string& value of the "dimensionTerm" attribute
   * to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p dimensionTerm = @c NULL or an empty string
   * is equivalent to calling unsetDimensionTerm().
   */
  int setDimensionTerm(const std::string& dimensionTerm);


  /**
   * Unsets the value of the "symbol" attribute of this SedVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSymbol();


  /**
   * Unsets the value of the "target" attribute of this SedVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Unsets the value of the "taskReference" attribute of this SedVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTaskReference();


  /**
   * Unsets the value of the "modelReference" attribute of this SedVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetModelReference();


  /**
   * Unsets the value of the "term" attribute of this SedVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTerm();


  /**
   * Unsets the value of the "symbol2" attribute of this SedVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSymbol2();


  /**
   * Unsets the value of the "target2" attribute of this SedVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget2();


  /**
   * Unsets the value of the "dimensionTerm" attribute of this SedVariable.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDimensionTerm();


  /**
   * Returns the SedListOfAppliedDimensions from this SedVariable.
   *
   * @return the SedListOfAppliedDimensions from this SedVariable.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see getAppliedDimension(const std::string& sid)
   * @see getAppliedDimension(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see removeAppliedDimension(const std::string& sid)
   * @see removeAppliedDimension(unsigned int n)
   */
  const SedListOfAppliedDimensions* getListOfAppliedDimensions() const;


  /**
   * Returns the SedListOfAppliedDimensions from this SedVariable.
   *
   * @return the SedListOfAppliedDimensions from this SedVariable.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see getAppliedDimension(const std::string& sid)
   * @see getAppliedDimension(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see removeAppliedDimension(const std::string& sid)
   * @see removeAppliedDimension(unsigned int n)
   */
  SedListOfAppliedDimensions* getListOfAppliedDimensions();


  /**
   * Get a SedAppliedDimension from the SedVariable.
   *
   * @param n an unsigned int representing the index of the SedAppliedDimension
   * to retrieve.
   *
   * @return the nth SedAppliedDimension in the SedListOfAppliedDimensions
   * within this SedVariable or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see getAppliedDimension(const std::string& sid)
   * @see getNumAppliedDimensions()
   * @see removeAppliedDimension(const std::string& sid)
   * @see removeAppliedDimension(unsigned int n)
   */
  SedAppliedDimension* getAppliedDimension(unsigned int n);


  /**
   * Get a SedAppliedDimension from the SedVariable.
   *
   * @param n an unsigned int representing the index of the SedAppliedDimension
   * to retrieve.
   *
   * @return the nth SedAppliedDimension in the SedListOfAppliedDimensions
   * within this SedVariable or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see getAppliedDimension(const std::string& sid)
   * @see getNumAppliedDimensions()
   * @see removeAppliedDimension(const std::string& sid)
   * @see removeAppliedDimension(unsigned int n)
   */
  const SedAppliedDimension* getAppliedDimension(unsigned int n) const;


  /**
   * Get a SedAppliedDimension from the SedVariable based on the Target to
   * which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedAppliedDimension object to retrieve.
   *
   * @return the first SedAppliedDimension in this SedVariable based on the
   * given target attribute or NULL if no such SedAppliedDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAppliedDimension* getAppliedDimensionByTarget(const std::string&
    sid) const;


  /**
   * Get a SedAppliedDimension from the SedVariable based on the Target to
   * which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedAppliedDimension object to retrieve.
   *
   * @return the first SedAppliedDimension in this SedVariable based on the
   * given target attribute or NULL if no such SedAppliedDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAppliedDimension* getAppliedDimensionByTarget(const std::string& sid);


  /**
   * Get a SedAppliedDimension from the SedVariable based on the
   * DimensionTarget to which it refers.
   *
   * @param sid a string representing the "dimensionTarget" attribute of the
   * SedAppliedDimension object to retrieve.
   *
   * @return the first SedAppliedDimension in this SedVariable based on the
   * given dimensionTarget attribute or NULL if no such SedAppliedDimension
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAppliedDimension* getAppliedDimensionByDimensionTarget(const
    std::string& sid) const;


  /**
   * Get a SedAppliedDimension from the SedVariable based on the
   * DimensionTarget to which it refers.
   *
   * @param sid a string representing the "dimensionTarget" attribute of the
   * SedAppliedDimension object to retrieve.
   *
   * @return the first SedAppliedDimension in this SedVariable based on the
   * given dimensionTarget attribute or NULL if no such SedAppliedDimension
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAppliedDimension* getAppliedDimensionByDimensionTarget(const std::string&
    sid);


  /**
   * Adds a copy of the given SedAppliedDimension to this SedVariable.
   *
   * @param sad the SedAppliedDimension object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createAppliedDimension()
   * @see getAppliedDimension(const std::string& sid)
   * @see getAppliedDimension(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see removeAppliedDimension(const std::string& sid)
   * @see removeAppliedDimension(unsigned int n)
   */
  int addAppliedDimension(const SedAppliedDimension* sad);


  /**
   * Get the number of SedAppliedDimension objects in this SedVariable.
   *
   * @return the number of SedAppliedDimension objects in this SedVariable.
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see getAppliedDimension(const std::string& sid)
   * @see getAppliedDimension(unsigned int n)
   * @see removeAppliedDimension(const std::string& sid)
   * @see removeAppliedDimension(unsigned int n)
   */
  unsigned int getNumAppliedDimensions() const;


  /**
   * Creates a new SedAppliedDimension object, adds it to this SedVariable
   * object and returns the SedAppliedDimension object created.
   *
   * @return a new SedAppliedDimension object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see getAppliedDimension(const std::string& sid)
   * @see getAppliedDimension(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see removeAppliedDimension(const std::string& sid)
   * @see removeAppliedDimension(unsigned int n)
   */
  SedAppliedDimension* createAppliedDimension();


  /**
   * Removes the nth SedAppliedDimension from this SedVariable and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedAppliedDimension
   * to remove.
   *
   * @return a pointer to the nth SedAppliedDimension in this SedVariable.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see getAppliedDimension(const std::string& sid)
   * @see getAppliedDimension(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see removeAppliedDimension(const std::string& sid)
   */
  SedAppliedDimension* removeAppliedDimension(unsigned int n);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedVariable object.
   *
   * For SedVariable, the XML element name is always @c "variable".
   *
   * @return the name of this element, i.e. @c "variable".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedVariable object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_VARIABLE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedVariable object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedVariable have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedVariable object are:
   * @li "id"
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
   * Gets the value of the "attributeName" attribute of this SedVariable.
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
   * Gets the value of the "attributeName" attribute of this SedVariable.
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
   * Gets the value of the "attributeName" attribute of this SedVariable.
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
   * Gets the value of the "attributeName" attribute of this SedVariable.
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
   * Gets the value of the "attributeName" attribute of this SedVariable.
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
   * Predicate returning @c true if this SedVariable's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedVariable's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedVariable.
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
   * Sets the value of the "attributeName" attribute of this SedVariable.
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
   * Sets the value of the "attributeName" attribute of this SedVariable.
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
   * Sets the value of the "attributeName" attribute of this SedVariable.
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
   * Sets the value of the "attributeName" attribute of this SedVariable.
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
   * Unsets the value of the "attributeName" attribute of this SedVariable.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates and returns an new "elementName" object in this SedVariable.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedVariable.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SedBase* element);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * SedVariable.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SedBase* removeChildObject(const std::string& elementName,
                                     const std::string& id);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the number of "elementName" in this SedVariable.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedVariable.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SedBase* getObject(const std::string& elementName,
                             unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SedBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SedBase* getElementBySId(const std::string& id);


  /**
   * Returns a List of all child SedBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List pointer of pointers to all SedBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(SedElementFilter * filter = NULL);


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
 * Creates a new SedVariable_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedVariable_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedVariable_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedVariable_t *
SedVariable_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedVariable_t object.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return a (deep) copy of this SedVariable_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedVariable_clone(const SedVariable_t* sv);


/**
 * Frees this SedVariable_t object.
 *
 * @param sv the SedVariable_t structure.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
void
SedVariable_free(SedVariable_t* sv);


/**
 * Returns the value of the "symbol" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose symbol is sought.
 *
 * @return the value of the "symbol" attribute of this SedVariable_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getSymbol(const SedVariable_t * sv);


/**
 * Returns the value of the "target" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SedVariable_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getTarget(const SedVariable_t * sv);


/**
 * Returns the value of the "taskReference" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose taskReference is sought.
 *
 * @return the value of the "taskReference" attribute of this SedVariable_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getTaskReference(const SedVariable_t * sv);


/**
 * Returns the value of the "modelReference" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose modelReference is sought.
 *
 * @return the value of the "modelReference" attribute of this SedVariable_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getModelReference(const SedVariable_t * sv);


/**
 * Returns the value of the "term" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose term is sought.
 *
 * @return the value of the "term" attribute of this SedVariable_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getTerm(const SedVariable_t * sv);


/**
 * Returns the value of the "symbol2" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose symbol2 is sought.
 *
 * @return the value of the "symbol2" attribute of this SedVariable_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getSymbol2(const SedVariable_t * sv);


/**
 * Returns the value of the "target2" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose target2 is sought.
 *
 * @return the value of the "target2" attribute of this SedVariable_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getTarget2(const SedVariable_t * sv);


/**
 * Returns the value of the "dimensionTerm" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose dimensionTerm is sought.
 *
 * @return the value of the "dimensionTerm" attribute of this SedVariable_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getDimensionTerm(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "symbol" attribute
 * is set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "symbol" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetSymbol(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "target" attribute
 * is set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "target" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTarget(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "taskReference"
 * attribute is set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "taskReference" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTaskReference(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "modelReference"
 * attribute is set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "modelReference" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetModelReference(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "term" attribute is
 * set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "term" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTerm(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "symbol2" attribute
 * is set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "symbol2" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetSymbol2(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "target2" attribute
 * is set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "target2" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTarget2(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "dimensionTerm"
 * attribute is set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "dimensionTerm" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetDimensionTerm(const SedVariable_t * sv);


/**
 * Sets the value of the "symbol" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param symbol const char * value of the "symbol" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p symbol = @c NULL or an empty string is
 * equivalent to calling SedVariable_unsetSymbol().
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setSymbol(SedVariable_t * sv, const char * symbol);


/**
 * Sets the value of the "target" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p target = @c NULL or an empty string is
 * equivalent to calling SedVariable_unsetTarget().
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setTarget(SedVariable_t * sv, const char * target);


/**
 * Sets the value of the "taskReference" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param taskReference const char * value of the "taskReference" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setTaskReference(SedVariable_t * sv, const char * taskReference);


/**
 * Sets the value of the "modelReference" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
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
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setModelReference(SedVariable_t * sv,
                              const char * modelReference);


/**
 * Sets the value of the "term" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param term const char * value of the "term" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p term = @c NULL or an empty string is
 * equivalent to calling SedVariable_unsetTerm().
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setTerm(SedVariable_t * sv, const char * term);


/**
 * Sets the value of the "symbol2" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param symbol2 const char * value of the "symbol2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p symbol2 = @c NULL or an empty string is
 * equivalent to calling SedVariable_unsetSymbol2().
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setSymbol2(SedVariable_t * sv, const char * symbol2);


/**
 * Sets the value of the "target2" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param target2 const char * value of the "target2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p target2 = @c NULL or an empty string is
 * equivalent to calling SedVariable_unsetTarget2().
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setTarget2(SedVariable_t * sv, const char * target2);


/**
 * Sets the value of the "dimensionTerm" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param dimensionTerm const char * value of the "dimensionTerm" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p dimensionTerm = @c NULL or an empty string is
 * equivalent to calling SedVariable_unsetDimensionTerm().
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setDimensionTerm(SedVariable_t * sv, const char * dimensionTerm);


/**
 * Unsets the value of the "symbol" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_unsetSymbol(SedVariable_t * sv);


/**
 * Unsets the value of the "target" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTarget(SedVariable_t * sv);


/**
 * Unsets the value of the "taskReference" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTaskReference(SedVariable_t * sv);


/**
 * Unsets the value of the "modelReference" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_unsetModelReference(SedVariable_t * sv);


/**
 * Unsets the value of the "term" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTerm(SedVariable_t * sv);


/**
 * Unsets the value of the "symbol2" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_unsetSymbol2(SedVariable_t * sv);


/**
 * Unsets the value of the "target2" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTarget2(SedVariable_t * sv);


/**
 * Unsets the value of the "dimensionTerm" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_unsetDimensionTerm(SedVariable_t * sv);


/**
 * Returns a ListOf_t * containing SedAppliedDimension_t objects from this
 * SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose SedListOfAppliedDimensions is
 * sought.
 *
 * @return the SedListOfAppliedDimensions from this SedVariable_t as a ListOf_t
 * *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedVariable_addAppliedDimension()
 * @see SedVariable_createAppliedDimension()
 * @see SedVariable_getAppliedDimensionById()
 * @see SedVariable_getAppliedDimension()
 * @see SedVariable_getNumAppliedDimensions()
 * @see SedVariable_removeAppliedDimensionById()
 * @see SedVariable_removeAppliedDimension()
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedVariable_getListOfAppliedDimensions(SedVariable_t* sv);


/**
 * Get a SedAppliedDimension_t from the SedVariable_t.
 *
 * @param sv the SedVariable_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAppliedDimension_t
 * to retrieve.
 *
 * @return the nth SedAppliedDimension_t in the SedListOfAppliedDimensions
 * within this SedVariable or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_getAppliedDimension(SedVariable_t* sv, unsigned int n);


/**
 * Get a SedAppliedDimension_t from the SedVariable_t based on the Target to
 * which it refers.
 *
 * @param sv the SedVariable_t structure to search.
 *
 * @param sid a string representing the "target" attribute of the
 * SedAppliedDimension_t object to retrieve.
 *
 * @return the first SedAppliedDimension_t in this SedVariable_t based on the
 * given target attribute or NULL if no such SedAppliedDimension_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_getAppliedDimensionByTarget(SedVariable_t* sv, const char *sid);


/**
 * Get a SedAppliedDimension_t from the SedVariable_t based on the
 * DimensionTarget to which it refers.
 *
 * @param sv the SedVariable_t structure to search.
 *
 * @param sid a string representing the "dimensionTarget" attribute of the
 * SedAppliedDimension_t object to retrieve.
 *
 * @return the first SedAppliedDimension_t in this SedVariable_t based on the
 * given dimensionTarget attribute or NULL if no such SedAppliedDimension_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_getAppliedDimensionByDimensionTarget(SedVariable_t* sv,
                                                 const char *sid);


/**
 * Adds a copy of the given SedAppliedDimension_t to this SedVariable_t.
 *
 * @param sv the SedVariable_t structure to which the SedAppliedDimension_t
 * should be added.
 *
 * @param sad the SedAppliedDimension_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_addAppliedDimension(SedVariable_t* sv,
                                const SedAppliedDimension_t* sad);


/**
 * Get the number of SedAppliedDimension_t objects in this SedVariable_t.
 *
 * @param sv the SedVariable_t structure to query.
 *
 * @return the number of SedAppliedDimension_t objects in this SedVariable_t.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
unsigned int
SedVariable_getNumAppliedDimensions(SedVariable_t* sv);


/**
 * Creates a new SedAppliedDimension_t object, adds it to this SedVariable_t
 * object and returns the SedAppliedDimension_t object created.
 *
 * @param sv the SedVariable_t structure to which the SedAppliedDimension_t
 * should be added.
 *
 * @return a new SedAppliedDimension_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_createAppliedDimension(SedVariable_t* sv);


/**
 * Removes the nth SedAppliedDimension_t from this SedVariable_t and returns a
 * pointer to it.
 *
 * @param sv the SedVariable_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAppliedDimension_t
 * to remove.
 *
 * @return a pointer to the nth SedAppliedDimension_t in this SedVariable_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedVariable_removeAppliedDimension(SedVariable_t* sv, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedVariable_t object have been set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedVariable_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedVariable_t object are:
 * @li "id"
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_hasRequiredAttributes(const SedVariable_t * sv);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedVariable_H__ */


