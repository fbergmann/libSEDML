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
#include <sedml/SedListOfRemainingDimensions.h>
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
  SedListOfRemainingDimensions mRemainingDimensions;

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
   * Returns the SedListOfRemainingDimensions from this SedVariable.
   *
   * @return the SedListOfRemainingDimensions from this SedVariable.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see getRemainingDimension(const std::string& sid)
   * @see getRemainingDimension(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see removeRemainingDimension(const std::string& sid)
   * @see removeRemainingDimension(unsigned int n)
   */
  const SedListOfRemainingDimensions* getListOfRemainingDimensions() const;


  /**
   * Returns the SedListOfRemainingDimensions from this SedVariable.
   *
   * @return the SedListOfRemainingDimensions from this SedVariable.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see getRemainingDimension(const std::string& sid)
   * @see getRemainingDimension(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see removeRemainingDimension(const std::string& sid)
   * @see removeRemainingDimension(unsigned int n)
   */
  SedListOfRemainingDimensions* getListOfRemainingDimensions();


  /**
   * Get a SedRemainingDimension from the SedVariable.
   *
   * @param n an unsigned int representing the index of the
   * SedRemainingDimension to retrieve.
   *
   * @return the nth SedRemainingDimension in the SedListOfRemainingDimensions
   * within this SedVariable or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see getRemainingDimension(const std::string& sid)
   * @see getNumRemainingDimensions()
   * @see removeRemainingDimension(const std::string& sid)
   * @see removeRemainingDimension(unsigned int n)
   */
  SedRemainingDimension* getRemainingDimension(unsigned int n);


  /**
   * Get a SedRemainingDimension from the SedVariable.
   *
   * @param n an unsigned int representing the index of the
   * SedRemainingDimension to retrieve.
   *
   * @return the nth SedRemainingDimension in the SedListOfRemainingDimensions
   * within this SedVariable or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see getRemainingDimension(const std::string& sid)
   * @see getNumRemainingDimensions()
   * @see removeRemainingDimension(const std::string& sid)
   * @see removeRemainingDimension(unsigned int n)
   */
  const SedRemainingDimension* getRemainingDimension(unsigned int n) const;


  /**
   * Get a SedRemainingDimension from the SedVariable based on the Target to
   * which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedRemainingDimension object to retrieve.
   *
   * @return the first SedRemainingDimension in this SedVariable based on the
   * given target attribute or NULL if no such SedRemainingDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedRemainingDimension* getRemainingDimensionByTarget(const std::string&
    sid) const;


  /**
   * Get a SedRemainingDimension from the SedVariable based on the Target to
   * which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedRemainingDimension object to retrieve.
   *
   * @return the first SedRemainingDimension in this SedVariable based on the
   * given target attribute or NULL if no such SedRemainingDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedRemainingDimension* getRemainingDimensionByTarget(const std::string& sid);


  /**
   * Get a SedRemainingDimension from the SedVariable based on the
   * DimensionTarget to which it refers.
   *
   * @param sid a string representing the "dimensionTarget" attribute of the
   * SedRemainingDimension object to retrieve.
   *
   * @return the first SedRemainingDimension in this SedVariable based on the
   * given dimensionTarget attribute or NULL if no such SedRemainingDimension
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedRemainingDimension* getRemainingDimensionByDimensionTarget(const
    std::string& sid) const;


  /**
   * Get a SedRemainingDimension from the SedVariable based on the
   * DimensionTarget to which it refers.
   *
   * @param sid a string representing the "dimensionTarget" attribute of the
   * SedRemainingDimension object to retrieve.
   *
   * @return the first SedRemainingDimension in this SedVariable based on the
   * given dimensionTarget attribute or NULL if no such SedRemainingDimension
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedRemainingDimension* getRemainingDimensionByDimensionTarget(const
    std::string& sid);


  /**
   * Adds a copy of the given SedRemainingDimension to this SedVariable.
   *
   * @param srd the SedRemainingDimension object to add.
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
   * @see createRemainingDimension()
   * @see getRemainingDimension(const std::string& sid)
   * @see getRemainingDimension(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see removeRemainingDimension(const std::string& sid)
   * @see removeRemainingDimension(unsigned int n)
   */
  int addRemainingDimension(const SedRemainingDimension* srd);


  /**
   * Get the number of SedRemainingDimension objects in this SedVariable.
   *
   * @return the number of SedRemainingDimension objects in this SedVariable.
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see getRemainingDimension(const std::string& sid)
   * @see getRemainingDimension(unsigned int n)
   * @see removeRemainingDimension(const std::string& sid)
   * @see removeRemainingDimension(unsigned int n)
   */
  unsigned int getNumRemainingDimensions() const;


  /**
   * Creates a new SedRemainingDimension object, adds it to this SedVariable
   * object and returns the SedRemainingDimension object created.
   *
   * @return a new SedRemainingDimension object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see getRemainingDimension(const std::string& sid)
   * @see getRemainingDimension(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see removeRemainingDimension(const std::string& sid)
   * @see removeRemainingDimension(unsigned int n)
   */
  SedRemainingDimension* createRemainingDimension();


  /**
   * Removes the nth SedRemainingDimension from this SedVariable and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * SedRemainingDimension to remove.
   *
   * @return a pointer to the nth SedRemainingDimension in this SedVariable.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see getRemainingDimension(const std::string& sid)
   * @see getRemainingDimension(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see removeRemainingDimension(const std::string& sid)
   */
  SedRemainingDimension* removeRemainingDimension(unsigned int n);


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
 * Returns the value of the "id" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedVariable_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getId(const SedVariable_t * sv);


/**
 * Returns the value of the "name" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedVariable_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
char *
SedVariable_getName(const SedVariable_t * sv);


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
 * Predicate returning @c 1 (true) if this SedVariable_t's "id" attribute is
 * set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetId(const SedVariable_t * sv);


/**
 * Predicate returning @c 1 (true) if this SedVariable_t's "name" attribute is
 * set.
 *
 * @param sv the SedVariable_t structure.
 *
 * @return @c 1 (true) if this SedVariable_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_isSetName(const SedVariable_t * sv);


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
 * Sets the value of the "id" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling SedVariable_unsetId().
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setId(SedVariable_t * sv, const char * id);


/**
 * Sets the value of the "name" attribute of this SedVariable_t.
 *
 * @param sv the SedVariable_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedVariable_unsetName().
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
int
SedVariable_setName(SedVariable_t * sv, const char * name);


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
 * Unsets the value of the "id" attribute of this SedVariable_t.
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
SedVariable_unsetId(SedVariable_t * sv);


/**
 * Unsets the value of the "name" attribute of this SedVariable_t.
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
SedVariable_unsetName(SedVariable_t * sv);


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
 * Returns a ListOf_t * containing SedRemainingDimension_t objects from this
 * SedVariable_t.
 *
 * @param sv the SedVariable_t structure whose SedListOfRemainingDimensions is
 * sought.
 *
 * @return the SedListOfRemainingDimensions from this SedVariable_t as a
 * ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedVariable_addRemainingDimension()
 * @see SedVariable_createRemainingDimension()
 * @see SedVariable_getRemainingDimensionById()
 * @see SedVariable_getRemainingDimension()
 * @see SedVariable_getNumRemainingDimensions()
 * @see SedVariable_removeRemainingDimensionById()
 * @see SedVariable_removeRemainingDimension()
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedVariable_getListOfRemainingDimensions(SedVariable_t* sv);


/**
 * Get a SedRemainingDimension_t from the SedVariable_t.
 *
 * @param sv the SedVariable_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedRemainingDimension_t to retrieve.
 *
 * @return the nth SedRemainingDimension_t in the SedListOfRemainingDimensions
 * within this SedVariable or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_getRemainingDimension(SedVariable_t* sv, unsigned int n);


/**
 * Get a SedRemainingDimension_t from the SedVariable_t based on the Target to
 * which it refers.
 *
 * @param sv the SedVariable_t structure to search.
 *
 * @param sid a string representing the "target" attribute of the
 * SedRemainingDimension_t object to retrieve.
 *
 * @return the first SedRemainingDimension_t in this SedVariable_t based on the
 * given target attribute or NULL if no such SedRemainingDimension_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_getRemainingDimensionByTarget(SedVariable_t* sv, const char *sid);


/**
 * Get a SedRemainingDimension_t from the SedVariable_t based on the
 * DimensionTarget to which it refers.
 *
 * @param sv the SedVariable_t structure to search.
 *
 * @param sid a string representing the "dimensionTarget" attribute of the
 * SedRemainingDimension_t object to retrieve.
 *
 * @return the first SedRemainingDimension_t in this SedVariable_t based on the
 * given dimensionTarget attribute or NULL if no such SedRemainingDimension_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_getRemainingDimensionByDimensionTarget(SedVariable_t* sv,
                                                   const char *sid);


/**
 * Adds a copy of the given SedRemainingDimension_t to this SedVariable_t.
 *
 * @param sv the SedVariable_t structure to which the SedRemainingDimension_t
 * should be added.
 *
 * @param srd the SedRemainingDimension_t object to add.
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
SedVariable_addRemainingDimension(SedVariable_t* sv,
                                  const SedRemainingDimension_t* srd);


/**
 * Get the number of SedRemainingDimension_t objects in this SedVariable_t.
 *
 * @param sv the SedVariable_t structure to query.
 *
 * @return the number of SedRemainingDimension_t objects in this SedVariable_t.
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
unsigned int
SedVariable_getNumRemainingDimensions(SedVariable_t* sv);


/**
 * Creates a new SedRemainingDimension_t object, adds it to this SedVariable_t
 * object and returns the SedRemainingDimension_t object created.
 *
 * @param sv the SedVariable_t structure to which the SedRemainingDimension_t
 * should be added.
 *
 * @return a new SedRemainingDimension_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_createRemainingDimension(SedVariable_t* sv);


/**
 * Removes the nth SedRemainingDimension_t from this SedVariable_t and returns
 * a pointer to it.
 *
 * @param sv the SedVariable_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedRemainingDimension_t to remove.
 *
 * @return a pointer to the nth SedRemainingDimension_t in this SedVariable_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedVariable_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedVariable_removeRemainingDimension(SedVariable_t* sv, unsigned int n);


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


