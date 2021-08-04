/**
 * @file SedComputeChange.h
 * @brief Definition of the SedComputeChange class.
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
 * @class SedComputeChange
 * @sbmlbrief{sedml} TODO:Definition of the SedComputeChange class.
 */


#ifndef SedComputeChange_H__
#define SedComputeChange_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedChange.h>
#include <sbml/math/ASTNode.h>
#include <sedml/SedListOfVariables.h>
#include <sedml/SedListOfParameters.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedComputeChange : public SedChange
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* mMath;
  SedListOfVariables mVariables;
  SedListOfParameters mParameters;
  std::string mSymbol;

  /** @endcond */

public:

  /**
   * Creates a new SedComputeChange using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedComputeChange.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedComputeChange.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedComputeChange(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedComputeChange using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedComputeChange(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedComputeChange.
   *
   * @param orig the SedComputeChange instance to copy.
   */
  SedComputeChange(const SedComputeChange& orig);


  /**
   * Assignment operator for SedComputeChange.
   *
   * @param rhs the SedComputeChange object whose values are to be used as the
   * basis of the assignment.
   */
  SedComputeChange& operator=(const SedComputeChange& rhs);


  /**
   * Creates and returns a deep copy of this SedComputeChange object.
   *
   * @return a (deep) copy of this SedComputeChange object.
   */
  virtual SedComputeChange* clone() const;


  /**
   * Destructor for SedComputeChange.
   */
  virtual ~SedComputeChange();


  /**
   * Returns the value of the "symbol" attribute of this SedComputeChange.
   *
   * @return the value of the "symbol" attribute of this SedComputeChange as a
   * string.
   */
  const std::string& getSymbol() const;


  /**
   * Predicate returning @c true if this SedComputeChange's "symbol" attribute is
   * set.
   *
   * @return @c true if this SedComputeChange's "symbol" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSymbol() const;


  /**
   * Sets the value of the "symbol" attribute of this SedComputeChange.
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
   * Unsets the value of the "symbol" attribute of this SedComputeChange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSymbol();


  /**
   * Returns the value of the "math" element of this SedComputeChange.
   *
   * @return the value of the "math" element of this SedComputeChange as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath() const;


  /**
   * Returns the value of the "math" element of this SedComputeChange.
   *
   * @return the value of the "math" element of this SedComputeChange as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath();


  /**
   * Predicate returning @c true if this SedComputeChange's "math" element is
   * set.
   *
   * @return @c true if this SedComputeChange's "math" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMath() const;


  /**
   * Sets the value of the "math" element of this SedComputeChange.
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
   * Unsets the value of the "math" element of this SedComputeChange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMath();


  /**
   * Returns the SedListOfVariables from this SedComputeChange.
   *
   * @return the SedListOfVariables from this SedComputeChange.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(const std::string& sid)
   * @see getVariable(unsigned int n)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  const SedListOfVariables* getListOfVariables() const;


  /**
   * Returns the SedListOfVariables from this SedComputeChange.
   *
   * @return the SedListOfVariables from this SedComputeChange.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(const std::string& sid)
   * @see getVariable(unsigned int n)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  SedListOfVariables* getListOfVariables();


  /**
   * Get a SedVariable from the SedComputeChange.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in the SedListOfVariables within this
   * SedComputeChange or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(const std::string& sid)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  SedVariable* getVariable(unsigned int n);


  /**
   * Get a SedVariable from the SedComputeChange.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in the SedListOfVariables within this
   * SedComputeChange or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(const std::string& sid)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  const SedVariable* getVariable(unsigned int n) const;


  /**
   * Get a SedVariable from the SedComputeChange based on its identifier.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * retrieve.
   *
   * @return the SedVariable in the SedListOfVariables within this
   * SedComputeChange with the given @p sid or @c NULL if no such SedVariable
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(unsigned int n)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  SedVariable* getVariable(const std::string& sid);


  /**
   * Get a SedVariable from the SedComputeChange based on its identifier.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * retrieve.
   *
   * @return the SedVariable in the SedListOfVariables within this
   * SedComputeChange with the given @p sid or @c NULL if no such SedVariable
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(unsigned int n)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  const SedVariable* getVariable(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedComputeChange based on the TaskReference to
   * which it refers.
   *
   * @param sid a string representing the "taskReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedComputeChange based on the given
   * taskReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedVariable* getVariableByTaskReference(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedComputeChange based on the TaskReference to
   * which it refers.
   *
   * @param sid a string representing the "taskReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedComputeChange based on the given
   * taskReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedVariable* getVariableByTaskReference(const std::string& sid);


  /**
   * Get a SedVariable from the SedComputeChange based on the ModelReference to
   * which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedComputeChange based on the given
   * modelReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedVariable* getVariableByModelReference(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedComputeChange based on the ModelReference to
   * which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedComputeChange based on the given
   * modelReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedVariable* getVariableByModelReference(const std::string& sid);


  /**
   * Adds a copy of the given SedVariable to this SedComputeChange.
   *
   * @param sv the SedVariable object to add.
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
   * @see createVariable()
   * @see getVariable(const std::string& sid)
   * @see getVariable(unsigned int n)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  int addVariable(const SedVariable* sv);


  /**
   * Get the number of SedVariable objects in this SedComputeChange.
   *
   * @return the number of SedVariable objects in this SedComputeChange.
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(const std::string& sid)
   * @see getVariable(unsigned int n)
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  unsigned int getNumVariables() const;


  /**
   * Creates a new SedVariable object, adds it to this SedComputeChange object
   * and returns the SedVariable object created.
   *
   * @return a new SedVariable object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see getVariable(const std::string& sid)
   * @see getVariable(unsigned int n)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   * @see removeVariable(unsigned int n)
   */
  SedVariable* createVariable();


  /**
   * Removes the nth SedVariable from this SedComputeChange and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * remove.
   *
   * @return a pointer to the nth SedVariable in this SedComputeChange.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(const std::string& sid)
   * @see getVariable(unsigned int n)
   * @see getNumVariables()
   * @see removeVariable(const std::string& sid)
   */
  SedVariable* removeVariable(unsigned int n);


  /**
   * Removes the SedVariable from this SedComputeChange based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * remove.
   *
   * @return the SedVariable in this SedComputeChange based on the identifier
   * or NULL if no such SedVariable exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see getVariable(const std::string& sid)
   * @see getVariable(unsigned int n)
   * @see getNumVariables()
   * @see removeVariable(unsigned int n)
   */
  SedVariable* removeVariable(const std::string& sid);


  /**
   * Returns the SedListOfParameters from this SedComputeChange.
   *
   * @return the SedListOfParameters from this SedComputeChange.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(const std::string& sid)
   * @see getParameter(unsigned int n)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  const SedListOfParameters* getListOfParameters() const;


  /**
   * Returns the SedListOfParameters from this SedComputeChange.
   *
   * @return the SedListOfParameters from this SedComputeChange.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(const std::string& sid)
   * @see getParameter(unsigned int n)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  SedListOfParameters* getListOfParameters();


  /**
   * Get a SedParameter from the SedComputeChange.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in the SedListOfParameters within this
   * SedComputeChange or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(const std::string& sid)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  SedParameter* getParameter(unsigned int n);


  /**
   * Get a SedParameter from the SedComputeChange.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in the SedListOfParameters within this
   * SedComputeChange or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(const std::string& sid)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  const SedParameter* getParameter(unsigned int n) const;


  /**
   * Get a SedParameter from the SedComputeChange based on its identifier.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * retrieve.
   *
   * @return the SedParameter in the SedListOfParameters within this
   * SedComputeChange with the given @p sid or @c NULL if no such SedParameter
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(unsigned int n)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  SedParameter* getParameter(const std::string& sid);


  /**
   * Get a SedParameter from the SedComputeChange based on its identifier.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * retrieve.
   *
   * @return the SedParameter in the SedListOfParameters within this
   * SedComputeChange with the given @p sid or @c NULL if no such SedParameter
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(unsigned int n)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  const SedParameter* getParameter(const std::string& sid) const;


  /**
   * Adds a copy of the given SedParameter to this SedComputeChange.
   *
   * @param sp the SedParameter object to add.
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
   * @see createParameter()
   * @see getParameter(const std::string& sid)
   * @see getParameter(unsigned int n)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  int addParameter(const SedParameter* sp);


  /**
   * Get the number of SedParameter objects in this SedComputeChange.
   *
   * @return the number of SedParameter objects in this SedComputeChange.
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(const std::string& sid)
   * @see getParameter(unsigned int n)
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  unsigned int getNumParameters() const;


  /**
   * Creates a new SedParameter object, adds it to this SedComputeChange object
   * and returns the SedParameter object created.
   *
   * @return a new SedParameter object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see getParameter(const std::string& sid)
   * @see getParameter(unsigned int n)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   * @see removeParameter(unsigned int n)
   */
  SedParameter* createParameter();


  /**
   * Removes the nth SedParameter from this SedComputeChange and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * remove.
   *
   * @return a pointer to the nth SedParameter in this SedComputeChange.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(const std::string& sid)
   * @see getParameter(unsigned int n)
   * @see getNumParameters()
   * @see removeParameter(const std::string& sid)
   */
  SedParameter* removeParameter(unsigned int n);


  /**
   * Removes the SedParameter from this SedComputeChange based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * remove.
   *
   * @return the SedParameter in this SedComputeChange based on the identifier
   * or NULL if no such SedParameter exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see getParameter(const std::string& sid)
   * @see getParameter(unsigned int n)
   * @see getNumParameters()
   * @see removeParameter(unsigned int n)
   */
  SedParameter* removeParameter(const std::string& sid);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedComputeChange object.
   *
   * For SedComputeChange, the XML element name is always @c "computeChange".
   *
   * @return the name of this element, i.e. @c "computeChange".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedComputeChange object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_CHANGE_COMPUTECHANGE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedComputeChange object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedComputeChange have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedComputeChange object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedComputeChange have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedComputeChange object are:
   */
  virtual bool hasRequiredElements() const;



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
   * Gets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Gets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Gets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Gets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Gets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Predicate returning @c true if this SedComputeChange's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedComputeChange's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Sets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Sets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Sets the value of the "attributeName" attribute of this SedComputeChange.
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
   * Sets the value of the "attributeName" attribute of this SedComputeChange.
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
   * SedComputeChange.
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
   * Creates and returns an new "elementName" object in this SedComputeChange.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedComputeChange.
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
   * SedComputeChange.
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
   * Returns the number of "elementName" in this SedComputeChange.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedComputeChange.
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
 * Creates a new SedComputeChange_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedComputeChange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedComputeChange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedComputeChange_t *
SedComputeChange_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedComputeChange_t object.
 *
 * @param scc the SedComputeChange_t structure.
 *
 * @return a (deep) copy of this SedComputeChange_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedComputeChange_t*
SedComputeChange_clone(const SedComputeChange_t* scc);


/**
 * Frees this SedComputeChange_t object.
 *
 * @param scc the SedComputeChange_t structure.
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
void
SedComputeChange_free(SedComputeChange_t* scc);


/**
 * Returns the value of the "symbol" attribute of this SedComputeChange_t.
 *
 * @param sv the SedComputeChange_t structure whose symbol is sought.
 *
 * @return the value of the "symbol" attribute of this SedComputeChange_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
char*
SedComputeChange_getSymbol(const SedComputeChange_t* sv);


/**
 * Predicate returning @c 1 (true) if this SedComputeChange_t's "symbol" attribute
 * is set.
 *
 * @param sv the SedComputeChange_t structure.
 *
 * @return @c 1 (true) if this SedComputeChange_t's "symbol" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_isSetSymbol(const SedComputeChange_t* sv);


/**
 * Sets the value of the "symbol" attribute of this SedComputeChange_t.
 *
 * @param sv the SedComputeChange_t structure.
 *
 * @param symbol const char * value of the "symbol" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p symbol = @c NULL or an empty string is
 * equivalent to calling SedComputeChange_unsetSymbol().
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_setSymbol(SedComputeChange_t* sv, const char* symbol);


/**
 * Unsets the value of the "symbol" attribute of this SedComputeChange_t.
 *
 * @param sv the SedComputeChange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_unsetSymbol(SedComputeChange_t* sv);


/**
 * Returns the value of the "math" element of this SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure whose math is sought.
 *
 * @return the value of the "math" element of this SedComputeChange_t as a
 * pointer to an ASTNode_t object.
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
SedComputeChange_getMath(const SedComputeChange_t * scc);


/**
 * Predicate returning @c 1 (true) if this SedComputeChange_t's "math" element
 * is set.
 *
 * @param scc the SedComputeChange_t structure.
 *
 * @return @c 1 (true) if this SedComputeChange_t's "math" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_isSetMath(const SedComputeChange_t * scc);


/**
 * Sets the value of the "math" element of this SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure.
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
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_setMath(SedComputeChange_t * scc,
                         const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
                           math);


/**
 * Unsets the value of the "math" element of this SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_unsetMath(SedComputeChange_t * scc);


/**
 * Returns a ListOf_t * containing SedVariable_t objects from this
 * SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure whose SedListOfVariables is
 * sought.
 *
 * @return the SedListOfVariables from this SedComputeChange_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedComputeChange_addVariable()
 * @see SedComputeChange_createVariable()
 * @see SedComputeChange_getVariableById()
 * @see SedComputeChange_getVariable()
 * @see SedComputeChange_getNumVariables()
 * @see SedComputeChange_removeVariableById()
 * @see SedComputeChange_removeVariable()
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedComputeChange_getListOfVariables(SedComputeChange_t* scc);


/**
 * Get a SedVariable_t from the SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * retrieve.
 *
 * @return the nth SedVariable_t in the SedListOfVariables within this
 * SedComputeChange or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_getVariable(SedComputeChange_t* scc, unsigned int n);


/**
 * Get a SedVariable_t from the SedComputeChange_t based on its identifier.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param sid a string representing the identifier of the SedVariable_t to
 * retrieve.
 *
 * @return the SedVariable_t in the SedListOfVariables within this
 * SedComputeChange with the given @p sid or @c NULL if no such SedVariable_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_getVariableById(SedComputeChange_t* scc, const char *sid);


/**
 * Get a SedVariable_t from the SedComputeChange_t based on the TaskReference
 * to which it refers.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param sid a string representing the "taskReference" attribute of the
 * SedVariable_t object to retrieve.
 *
 * @return the first SedVariable_t in this SedComputeChange_t based on the
 * given taskReference attribute or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_getVariableByTaskReference(SedComputeChange_t* scc,
                                            const char *sid);


/**
 * Get a SedVariable_t from the SedComputeChange_t based on the ModelReference
 * to which it refers.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param sid a string representing the "modelReference" attribute of the
 * SedVariable_t object to retrieve.
 *
 * @return the first SedVariable_t in this SedComputeChange_t based on the
 * given modelReference attribute or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_getVariableByModelReference(SedComputeChange_t* scc,
                                             const char *sid);


/**
 * Adds a copy of the given SedVariable_t to this SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure to which the SedVariable_t
 * should be added.
 *
 * @param sv the SedVariable_t object to add.
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
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_addVariable(SedComputeChange_t* scc,
                             const SedVariable_t* sv);


/**
 * Get the number of SedVariable_t objects in this SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure to query.
 *
 * @return the number of SedVariable_t objects in this SedComputeChange_t.
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
unsigned int
SedComputeChange_getNumVariables(SedComputeChange_t* scc);


/**
 * Creates a new SedVariable_t object, adds it to this SedComputeChange_t
 * object and returns the SedVariable_t object created.
 *
 * @param scc the SedComputeChange_t structure to which the SedVariable_t
 * should be added.
 *
 * @return a new SedVariable_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_createVariable(SedComputeChange_t* scc);


/**
 * Removes the nth SedVariable_t from this SedComputeChange_t and returns a
 * pointer to it.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * remove.
 *
 * @return a pointer to the nth SedVariable_t in this SedComputeChange_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_removeVariable(SedComputeChange_t* scc, unsigned int n);


/**
 * Removes the SedVariable_t from this SedComputeChange_t based on its
 * identifier and returns a pointer to it.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param sid a string representing the identifier of the SedVariable_t to
 * remove.
 *
 * @return the SedVariable_t in this SedComputeChange_t based on the identifier
 * or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedComputeChange_removeVariableById(SedComputeChange_t* scc, const char* sid);


/**
 * Returns a ListOf_t * containing SedParameter_t objects from this
 * SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure whose SedListOfParameters is
 * sought.
 *
 * @return the SedListOfParameters from this SedComputeChange_t as a ListOf_t
 * *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedComputeChange_addParameter()
 * @see SedComputeChange_createParameter()
 * @see SedComputeChange_getParameterById()
 * @see SedComputeChange_getParameter()
 * @see SedComputeChange_getNumParameters()
 * @see SedComputeChange_removeParameterById()
 * @see SedComputeChange_removeParameter()
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedComputeChange_getListOfParameters(SedComputeChange_t* scc);


/**
 * Get a SedParameter_t from the SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * retrieve.
 *
 * @return the nth SedParameter_t in the SedListOfParameters within this
 * SedComputeChange or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_getParameter(SedComputeChange_t* scc, unsigned int n);


/**
 * Get a SedParameter_t from the SedComputeChange_t based on its identifier.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param sid a string representing the identifier of the SedParameter_t to
 * retrieve.
 *
 * @return the SedParameter_t in the SedListOfParameters within this
 * SedComputeChange with the given @p sid or @c NULL if no such SedParameter_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_getParameterById(SedComputeChange_t* scc, const char *sid);


/**
 * Adds a copy of the given SedParameter_t to this SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure to which the SedParameter_t
 * should be added.
 *
 * @param sp the SedParameter_t object to add.
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
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_addParameter(SedComputeChange_t* scc,
                              const SedParameter_t* sp);


/**
 * Get the number of SedParameter_t objects in this SedComputeChange_t.
 *
 * @param scc the SedComputeChange_t structure to query.
 *
 * @return the number of SedParameter_t objects in this SedComputeChange_t.
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
unsigned int
SedComputeChange_getNumParameters(SedComputeChange_t* scc);


/**
 * Creates a new SedParameter_t object, adds it to this SedComputeChange_t
 * object and returns the SedParameter_t object created.
 *
 * @param scc the SedComputeChange_t structure to which the SedParameter_t
 * should be added.
 *
 * @return a new SedParameter_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_createParameter(SedComputeChange_t* scc);


/**
 * Removes the nth SedParameter_t from this SedComputeChange_t and returns a
 * pointer to it.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * remove.
 *
 * @return a pointer to the nth SedParameter_t in this SedComputeChange_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_removeParameter(SedComputeChange_t* scc, unsigned int n);


/**
 * Removes the SedParameter_t from this SedComputeChange_t based on its
 * identifier and returns a pointer to it.
 *
 * @param scc the SedComputeChange_t structure to search.
 *
 * @param sid a string representing the identifier of the SedParameter_t to
 * remove.
 *
 * @return the SedParameter_t in this SedComputeChange_t based on the
 * identifier or NULL if no such SedParameter_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedComputeChange_removeParameterById(SedComputeChange_t* scc,
                                     const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedComputeChange_t object have been set.
 *
 * @param scc the SedComputeChange_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedComputeChange_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_hasRequiredAttributes(const SedComputeChange_t * scc);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedComputeChange_t object have been set.
 *
 * @param scc the SedComputeChange_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedComputeChange_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedComputeChange_t object are:
 *
 * @memberof SedComputeChange_t
 */
LIBSEDML_EXTERN
int
SedComputeChange_hasRequiredElements(const SedComputeChange_t * scc);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedComputeChange_H__ */


