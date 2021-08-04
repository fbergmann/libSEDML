/**
 * @file SedFunctionalRange.h
 * @brief Definition of the SedFunctionalRange class.
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
 * @class SedFunctionalRange
 * @sbmlbrief{sedml} TODO:Definition of the SedFunctionalRange class.
 */


#ifndef SedFunctionalRange_H__
#define SedFunctionalRange_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedRange.h>
#include <sbml/math/ASTNode.h>
#include <sedml/SedListOfVariables.h>
#include <sedml/SedListOfParameters.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedFunctionalRange : public SedRange
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mRange;
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* mMath;
  SedListOfVariables mVariables;
  SedListOfParameters mParameters;

  /** @endcond */

public:

  /**
   * Creates a new SedFunctionalRange using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedFunctionalRange.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedFunctionalRange.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFunctionalRange(unsigned int level = SEDML_DEFAULT_LEVEL,
                     unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedFunctionalRange using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFunctionalRange(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedFunctionalRange.
   *
   * @param orig the SedFunctionalRange instance to copy.
   */
  SedFunctionalRange(const SedFunctionalRange& orig);


  /**
   * Assignment operator for SedFunctionalRange.
   *
   * @param rhs the SedFunctionalRange object whose values are to be used as
   * the basis of the assignment.
   */
  SedFunctionalRange& operator=(const SedFunctionalRange& rhs);


  /**
   * Creates and returns a deep copy of this SedFunctionalRange object.
   *
   * @return a (deep) copy of this SedFunctionalRange object.
   */
  virtual SedFunctionalRange* clone() const;


  /**
   * Destructor for SedFunctionalRange.
   */
  virtual ~SedFunctionalRange();


  /**
   * Returns the value of the "range" attribute of this SedFunctionalRange.
   *
   * @return the value of the "range" attribute of this SedFunctionalRange as a
   * string.
   */
  const std::string& getRange() const;


  /**
   * Predicate returning @c true if this SedFunctionalRange's "range" attribute
   * is set.
   *
   * @return @c true if this SedFunctionalRange's "range" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetRange() const;


  /**
   * Sets the value of the "range" attribute of this SedFunctionalRange.
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
   * Unsets the value of the "range" attribute of this SedFunctionalRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRange();


  /**
   * Returns the value of the "math" element of this SedFunctionalRange.
   *
   * @return the value of the "math" element of this SedFunctionalRange as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath() const;


  /**
   * Returns the value of the "math" element of this SedFunctionalRange.
   *
   * @return the value of the "math" element of this SedFunctionalRange as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath();


  /**
   * Predicate returning @c true if this SedFunctionalRange's "math" element is
   * set.
   *
   * @return @c true if this SedFunctionalRange's "math" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMath() const;


  /**
   * Sets the value of the "math" element of this SedFunctionalRange.
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
   * Unsets the value of the "math" element of this SedFunctionalRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMath();


  /**
   * Returns the SedListOfVariables from this SedFunctionalRange.
   *
   * @return the SedListOfVariables from this SedFunctionalRange.
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
   * Returns the SedListOfVariables from this SedFunctionalRange.
   *
   * @return the SedListOfVariables from this SedFunctionalRange.
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
   * Get a SedVariable from the SedFunctionalRange.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in the SedListOfVariables within this
   * SedFunctionalRange or @c NULL if no such object exists.
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
   * Get a SedVariable from the SedFunctionalRange.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in the SedListOfVariables within this
   * SedFunctionalRange or @c NULL if no such object exists.
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
   * Get a SedVariable from the SedFunctionalRange based on its identifier.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * retrieve.
   *
   * @return the SedVariable in the SedListOfVariables within this
   * SedFunctionalRange with the given @p sid or @c NULL if no such SedVariable
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
   * Get a SedVariable from the SedFunctionalRange based on its identifier.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * retrieve.
   *
   * @return the SedVariable in the SedListOfVariables within this
   * SedFunctionalRange with the given @p sid or @c NULL if no such SedVariable
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
   * Get a SedVariable from the SedFunctionalRange based on the TaskReference
   * to which it refers.
   *
   * @param sid a string representing the "taskReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedFunctionalRange based on the
   * given taskReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedVariable* getVariableByTaskReference(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedFunctionalRange based on the TaskReference
   * to which it refers.
   *
   * @param sid a string representing the "taskReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedFunctionalRange based on the
   * given taskReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedVariable* getVariableByTaskReference(const std::string& sid);


  /**
   * Get a SedVariable from the SedFunctionalRange based on the ModelReference
   * to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedFunctionalRange based on the
   * given modelReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedVariable* getVariableByModelReference(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedFunctionalRange based on the ModelReference
   * to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedFunctionalRange based on the
   * given modelReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedVariable* getVariableByModelReference(const std::string& sid);


  /**
   * Adds a copy of the given SedVariable to this SedFunctionalRange.
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
   * Get the number of SedVariable objects in this SedFunctionalRange.
   *
   * @return the number of SedVariable objects in this SedFunctionalRange.
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
   * Creates a new SedVariable object, adds it to this SedFunctionalRange
   * object and returns the SedVariable object created.
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
   * Removes the nth SedVariable from this SedFunctionalRange and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * remove.
   *
   * @return a pointer to the nth SedVariable in this SedFunctionalRange.
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
   * Removes the SedVariable from this SedFunctionalRange based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * remove.
   *
   * @return the SedVariable in this SedFunctionalRange based on the identifier
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
   * Returns the SedListOfParameters from this SedFunctionalRange.
   *
   * @return the SedListOfParameters from this SedFunctionalRange.
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
   * Returns the SedListOfParameters from this SedFunctionalRange.
   *
   * @return the SedListOfParameters from this SedFunctionalRange.
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
   * Get a SedParameter from the SedFunctionalRange.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in the SedListOfParameters within this
   * SedFunctionalRange or @c NULL if no such object exists.
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
   * Get a SedParameter from the SedFunctionalRange.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in the SedListOfParameters within this
   * SedFunctionalRange or @c NULL if no such object exists.
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
   * Get a SedParameter from the SedFunctionalRange based on its identifier.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * retrieve.
   *
   * @return the SedParameter in the SedListOfParameters within this
   * SedFunctionalRange with the given @p sid or @c NULL if no such
   * SedParameter exists.
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
   * Get a SedParameter from the SedFunctionalRange based on its identifier.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * retrieve.
   *
   * @return the SedParameter in the SedListOfParameters within this
   * SedFunctionalRange with the given @p sid or @c NULL if no such
   * SedParameter exists.
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
   * Adds a copy of the given SedParameter to this SedFunctionalRange.
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
   * Get the number of SedParameter objects in this SedFunctionalRange.
   *
   * @return the number of SedParameter objects in this SedFunctionalRange.
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
   * Creates a new SedParameter object, adds it to this SedFunctionalRange
   * object and returns the SedParameter object created.
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
   * Removes the nth SedParameter from this SedFunctionalRange and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * remove.
   *
   * @return a pointer to the nth SedParameter in this SedFunctionalRange.
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
   * Removes the SedParameter from this SedFunctionalRange based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * remove.
   *
   * @return the SedParameter in this SedFunctionalRange based on the
   * identifier or NULL if no such SedParameter exists.
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
   * Returns the XML element name of this SedFunctionalRange object.
   *
   * For SedFunctionalRange, the XML element name is always
   * @c "functionalRange".
   *
   * @return the name of this element, i.e. @c "functionalRange".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedFunctionalRange object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_RANGE_FUNCTIONALRANGE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedFunctionalRange object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedFunctionalRange have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedFunctionalRange object are:
   * @li "range"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedFunctionalRange object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedFunctionalRange have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedFunctionalRange object are:
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
   * Gets the value of the "attributeName" attribute of this
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * Predicate returning @c true if this SedFunctionalRange's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedFunctionalRange's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * Creates and returns an new "elementName" object in this
   * SedFunctionalRange.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedFunctionalRange.
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
   * SedFunctionalRange.
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
   * Returns the number of "elementName" in this SedFunctionalRange.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedFunctionalRange.
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
 * Creates a new SedFunctionalRange_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedFunctionalRange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedFunctionalRange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedFunctionalRange_t *
SedFunctionalRange_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedFunctionalRange_t object.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @return a (deep) copy of this SedFunctionalRange_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedFunctionalRange_t*
SedFunctionalRange_clone(const SedFunctionalRange_t* sfr);


/**
 * Frees this SedFunctionalRange_t object.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
void
SedFunctionalRange_free(SedFunctionalRange_t* sfr);


/**
 * Returns the value of the "range" attribute of this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure whose range is sought.
 *
 * @return the value of the "range" attribute of this SedFunctionalRange_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
char *
SedFunctionalRange_getRange(const SedFunctionalRange_t * sfr);


/**
 * Predicate returning @c 1 (true) if this SedFunctionalRange_t's "range"
 * attribute is set.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @return @c 1 (true) if this SedFunctionalRange_t's "range" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_isSetRange(const SedFunctionalRange_t * sfr);


/**
 * Sets the value of the "range" attribute of this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @param range const char * value of the "range" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_setRange(SedFunctionalRange_t * sfr, const char * range);


/**
 * Unsets the value of the "range" attribute of this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_unsetRange(SedFunctionalRange_t * sfr);


/**
 * Returns the value of the "math" element of this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure whose math is sought.
 *
 * @return the value of the "math" element of this SedFunctionalRange_t as a
 * pointer to an ASTNode_t object.
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
SedFunctionalRange_getMath(const SedFunctionalRange_t * sfr);


/**
 * Predicate returning @c 1 (true) if this SedFunctionalRange_t's "math"
 * element is set.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @return @c 1 (true) if this SedFunctionalRange_t's "math" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_isSetMath(const SedFunctionalRange_t * sfr);


/**
 * Sets the value of the "math" element of this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure.
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
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_setMath(SedFunctionalRange_t * sfr,
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
                             math);


/**
 * Unsets the value of the "math" element of this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_unsetMath(SedFunctionalRange_t * sfr);


/**
 * Returns a ListOf_t * containing SedVariable_t objects from this
 * SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure whose SedListOfVariables is
 * sought.
 *
 * @return the SedListOfVariables from this SedFunctionalRange_t as a ListOf_t
 * *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedFunctionalRange_addVariable()
 * @see SedFunctionalRange_createVariable()
 * @see SedFunctionalRange_getVariableById()
 * @see SedFunctionalRange_getVariable()
 * @see SedFunctionalRange_getNumVariables()
 * @see SedFunctionalRange_removeVariableById()
 * @see SedFunctionalRange_removeVariable()
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedFunctionalRange_getListOfVariables(SedFunctionalRange_t* sfr);


/**
 * Get a SedVariable_t from the SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * retrieve.
 *
 * @return the nth SedVariable_t in the SedListOfVariables within this
 * SedFunctionalRange or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_getVariable(SedFunctionalRange_t* sfr, unsigned int n);


/**
 * Get a SedVariable_t from the SedFunctionalRange_t based on its identifier.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param sid a string representing the identifier of the SedVariable_t to
 * retrieve.
 *
 * @return the SedVariable_t in the SedListOfVariables within this
 * SedFunctionalRange with the given @p sid or @c NULL if no such SedVariable_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_getVariableById(SedFunctionalRange_t* sfr,
                                   const char *sid);


/**
 * Get a SedVariable_t from the SedFunctionalRange_t based on the TaskReference
 * to which it refers.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param sid a string representing the "taskReference" attribute of the
 * SedVariable_t object to retrieve.
 *
 * @return the first SedVariable_t in this SedFunctionalRange_t based on the
 * given taskReference attribute or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_getVariableByTaskReference(SedFunctionalRange_t* sfr,
                                              const char *sid);


/**
 * Get a SedVariable_t from the SedFunctionalRange_t based on the
 * ModelReference to which it refers.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param sid a string representing the "modelReference" attribute of the
 * SedVariable_t object to retrieve.
 *
 * @return the first SedVariable_t in this SedFunctionalRange_t based on the
 * given modelReference attribute or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_getVariableByModelReference(SedFunctionalRange_t* sfr,
                                               const char *sid);


/**
 * Adds a copy of the given SedVariable_t to this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure to which the SedVariable_t
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
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_addVariable(SedFunctionalRange_t* sfr,
                               const SedVariable_t* sv);


/**
 * Get the number of SedVariable_t objects in this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure to query.
 *
 * @return the number of SedVariable_t objects in this SedFunctionalRange_t.
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
unsigned int
SedFunctionalRange_getNumVariables(SedFunctionalRange_t* sfr);


/**
 * Creates a new SedVariable_t object, adds it to this SedFunctionalRange_t
 * object and returns the SedVariable_t object created.
 *
 * @param sfr the SedFunctionalRange_t structure to which the SedVariable_t
 * should be added.
 *
 * @return a new SedVariable_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_createVariable(SedFunctionalRange_t* sfr);


/**
 * Removes the nth SedVariable_t from this SedFunctionalRange_t and returns a
 * pointer to it.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * remove.
 *
 * @return a pointer to the nth SedVariable_t in this SedFunctionalRange_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_removeVariable(SedFunctionalRange_t* sfr, unsigned int n);


/**
 * Removes the SedVariable_t from this SedFunctionalRange_t based on its
 * identifier and returns a pointer to it.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param sid a string representing the identifier of the SedVariable_t to
 * remove.
 *
 * @return the SedVariable_t in this SedFunctionalRange_t based on the
 * identifier or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedFunctionalRange_removeVariableById(SedFunctionalRange_t* sfr,
                                      const char* sid);


/**
 * Returns a ListOf_t * containing SedParameter_t objects from this
 * SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure whose SedListOfParameters is
 * sought.
 *
 * @return the SedListOfParameters from this SedFunctionalRange_t as a ListOf_t
 * *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedFunctionalRange_addParameter()
 * @see SedFunctionalRange_createParameter()
 * @see SedFunctionalRange_getParameterById()
 * @see SedFunctionalRange_getParameter()
 * @see SedFunctionalRange_getNumParameters()
 * @see SedFunctionalRange_removeParameterById()
 * @see SedFunctionalRange_removeParameter()
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedFunctionalRange_getListOfParameters(SedFunctionalRange_t* sfr);


/**
 * Get a SedParameter_t from the SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * retrieve.
 *
 * @return the nth SedParameter_t in the SedListOfParameters within this
 * SedFunctionalRange or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_getParameter(SedFunctionalRange_t* sfr, unsigned int n);


/**
 * Get a SedParameter_t from the SedFunctionalRange_t based on its identifier.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param sid a string representing the identifier of the SedParameter_t to
 * retrieve.
 *
 * @return the SedParameter_t in the SedListOfParameters within this
 * SedFunctionalRange with the given @p sid or @c NULL if no such
 * SedParameter_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_getParameterById(SedFunctionalRange_t* sfr,
                                    const char *sid);


/**
 * Adds a copy of the given SedParameter_t to this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure to which the SedParameter_t
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
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_addParameter(SedFunctionalRange_t* sfr,
                                const SedParameter_t* sp);


/**
 * Get the number of SedParameter_t objects in this SedFunctionalRange_t.
 *
 * @param sfr the SedFunctionalRange_t structure to query.
 *
 * @return the number of SedParameter_t objects in this SedFunctionalRange_t.
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
unsigned int
SedFunctionalRange_getNumParameters(SedFunctionalRange_t* sfr);


/**
 * Creates a new SedParameter_t object, adds it to this SedFunctionalRange_t
 * object and returns the SedParameter_t object created.
 *
 * @param sfr the SedFunctionalRange_t structure to which the SedParameter_t
 * should be added.
 *
 * @return a new SedParameter_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_createParameter(SedFunctionalRange_t* sfr);


/**
 * Removes the nth SedParameter_t from this SedFunctionalRange_t and returns a
 * pointer to it.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * remove.
 *
 * @return a pointer to the nth SedParameter_t in this SedFunctionalRange_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_removeParameter(SedFunctionalRange_t* sfr, unsigned int n);


/**
 * Removes the SedParameter_t from this SedFunctionalRange_t based on its
 * identifier and returns a pointer to it.
 *
 * @param sfr the SedFunctionalRange_t structure to search.
 *
 * @param sid a string representing the identifier of the SedParameter_t to
 * remove.
 *
 * @return the SedParameter_t in this SedFunctionalRange_t based on the
 * identifier or NULL if no such SedParameter_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedFunctionalRange_removeParameterById(SedFunctionalRange_t* sfr,
                                       const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFunctionalRange_t object have been set.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedFunctionalRange_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedFunctionalRange_t object are:
 * @li "range"
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_hasRequiredAttributes(const SedFunctionalRange_t * sfr);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedFunctionalRange_t object have been set.
 *
 * @param sfr the SedFunctionalRange_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedFunctionalRange_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedFunctionalRange_t object are:
 *
 * @memberof SedFunctionalRange_t
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_hasRequiredElements(const SedFunctionalRange_t * sfr);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedFunctionalRange_H__ */


