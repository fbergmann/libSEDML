/**
 * @file SedDataGenerator.h
 * @brief Definition of the SedDataGenerator class.
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
 * @class SedDataGenerator
 * @sbmlbrief{sedml} TODO:Definition of the SedDataGenerator class.
 */


#ifndef SedDataGenerator_H__
#define SedDataGenerator_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/math/ASTNode.h>
#include <sedml/SedListOfVariables.h>
#include <sedml/SedListOfParameters.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDataGenerator : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  SedListOfVariables mVariables;
  SedListOfParameters mParameters;
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* mMath;

  /** @endcond */

public:

  /**
   * Creates a new SedDataGenerator using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedDataGenerator.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedDataGenerator.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDataGenerator(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDataGenerator using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDataGenerator(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedDataGenerator.
   *
   * @param orig the SedDataGenerator instance to copy.
   */
  SedDataGenerator(const SedDataGenerator& orig);


  /**
   * Assignment operator for SedDataGenerator.
   *
   * @param rhs the SedDataGenerator object whose values are to be used as the
   * basis of the assignment.
   */
  SedDataGenerator& operator=(const SedDataGenerator& rhs);


  /**
   * Creates and returns a deep copy of this SedDataGenerator object.
   *
   * @return a (deep) copy of this SedDataGenerator object.
   */
  virtual SedDataGenerator* clone() const;


  /**
   * Destructor for SedDataGenerator.
   */
  virtual ~SedDataGenerator();


  /**
   * Returns the value of the "math" element of this SedDataGenerator.
   *
   * @return the value of the "math" element of this SedDataGenerator as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath() const;


  /**
   * Returns the value of the "math" element of this SedDataGenerator.
   *
   * @return the value of the "math" element of this SedDataGenerator as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode* getMath();


  /**
   * Predicate returning @c true if this SedDataGenerator's "math" element is
   * set.
   *
   * @return @c true if this SedDataGenerator's "math" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMath() const;


  /**
   * Sets the value of the "math" element of this SedDataGenerator.
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
   * Unsets the value of the "math" element of this SedDataGenerator.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMath();


  /**
   * Returns the SedListOfVariables from this SedDataGenerator.
   *
   * @return the SedListOfVariables from this SedDataGenerator.
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
   * Returns the SedListOfVariables from this SedDataGenerator.
   *
   * @return the SedListOfVariables from this SedDataGenerator.
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
   * Get a SedVariable from the SedDataGenerator.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in the SedListOfVariables within this
   * SedDataGenerator.
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
   * Get a SedVariable from the SedDataGenerator.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in the SedListOfVariables within this
   * SedDataGenerator.
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
   * Get a SedVariable from the SedDataGenerator based on its identifier.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * retrieve.
   *
   * @return the SedVariable in the SedListOfVariables within this
   * SedDataGenerator with the given @p sid or @c NULL if no such SedVariable
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
   * Get a SedVariable from the SedDataGenerator based on its identifier.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * retrieve.
   *
   * @return the SedVariable in the SedListOfVariables within this
   * SedDataGenerator with the given @p sid or @c NULL if no such SedVariable
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
   * Get a SedVariable from the SedDataGenerator based on the TaskReference to
   * which it refers.
   *
   * @param sid a string representing the "taskReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedDataGenerator based on the given
   * taskReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedVariable* getVariableByTaskReference(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedDataGenerator based on the TaskReference to
   * which it refers.
   *
   * @param sid a string representing the "taskReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedDataGenerator based on the given
   * taskReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedVariable* getVariableByTaskReference(const std::string& sid);


  /**
   * Get a SedVariable from the SedDataGenerator based on the ModelReference to
   * which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedDataGenerator based on the given
   * modelReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedVariable* getVariableByModelReference(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedDataGenerator based on the ModelReference to
   * which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedDataGenerator based on the given
   * modelReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedVariable* getVariableByModelReference(const std::string& sid);


  /**
   * Adds a copy of the given SedVariable to this SedDataGenerator.
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
   * Get the number of SedVariable objects in this SedDataGenerator.
   *
   * @return the number of SedVariable objects in this SedDataGenerator.
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
   * Creates a new SedVariable object, adds it to this SedDataGenerator object
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
   * Removes the nth SedVariable from this SedDataGenerator and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * remove.
   *
   * @return a pointer to the nth SedVariable in this SedDataGenerator.
   *
   * @copydetails doc_returned_owned_pointer
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
   * Removes the SedVariable from this SedDataGenerator based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * remove.
   *
   * @return the SedVariable in this SedDataGenerator based on the identifier
   * or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_owned_pointer
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
   * Returns the SedListOfParameters from this SedDataGenerator.
   *
   * @return the SedListOfParameters from this SedDataGenerator.
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
   * Returns the SedListOfParameters from this SedDataGenerator.
   *
   * @return the SedListOfParameters from this SedDataGenerator.
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
   * Get a SedParameter from the SedDataGenerator.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in the SedListOfParameters within this
   * SedDataGenerator.
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
   * Get a SedParameter from the SedDataGenerator.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in the SedListOfParameters within this
   * SedDataGenerator.
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
   * Get a SedParameter from the SedDataGenerator based on its identifier.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * retrieve.
   *
   * @return the SedParameter in the SedListOfParameters within this
   * SedDataGenerator with the given @p sid or @c NULL if no such SedParameter
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
   * Get a SedParameter from the SedDataGenerator based on its identifier.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * retrieve.
   *
   * @return the SedParameter in the SedListOfParameters within this
   * SedDataGenerator with the given @p sid or @c NULL if no such SedParameter
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
   * Adds a copy of the given SedParameter to this SedDataGenerator.
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
   * Get the number of SedParameter objects in this SedDataGenerator.
   *
   * @return the number of SedParameter objects in this SedDataGenerator.
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
   * Creates a new SedParameter object, adds it to this SedDataGenerator object
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
   * Removes the nth SedParameter from this SedDataGenerator and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * remove.
   *
   * @return a pointer to the nth SedParameter in this SedDataGenerator.
   *
   * @copydetails doc_returned_owned_pointer
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
   * Removes the SedParameter from this SedDataGenerator based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * remove.
   *
   * @return the SedParameter in this SedDataGenerator based on the identifier
   * or NULL if no such SedParameter exists.
   *
   * @copydetails doc_returned_owned_pointer
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
   * Returns the XML element name of this SedDataGenerator object.
   *
   * For SedDataGenerator, the XML element name is always @c "dataGenerator".
   *
   * @return the name of this element, i.e. @c "dataGenerator".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedDataGenerator object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_DATAGENERATOR, SedmlmlTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedDataGenerator object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedDataGenerator have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedDataGenerator object are:
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
   * Gets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Gets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Gets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Gets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Gets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Predicate returning @c true if this SedDataGenerator's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedDataGenerator's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Sets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Sets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Sets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * Sets the value of the "attributeName" attribute of this SedDataGenerator.
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
   * SedDataGenerator.
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
   * Creates and returns an new "elementName" object in this SedDataGenerator.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedDataGenerator.
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
   * SedDataGenerator.
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
   * Returns the number of "elementName" in this SedDataGenerator.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedDataGenerator.
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
 * Creates a new SedDataGenerator_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedDataGenerator_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedDataGenerator_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t *
SedDataGenerator_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedDataGenerator_t object.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return a (deep) copy of this SedDataGenerator_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDataGenerator_clone(const SedDataGenerator_t* sdg);


/**
 * Frees this SedDataGenerator_t object.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
void
SedDataGenerator_free(SedDataGenerator_t* sdg);


/**
 * Returns the value of the "id" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedDataGenerator_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
char *
SedDataGenerator_getId(const SedDataGenerator_t * sdg);


/**
 * Returns the value of the "name" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedDataGenerator_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
char *
SedDataGenerator_getName(const SedDataGenerator_t * sdg);


/**
 * Predicate returning @c 1 (true) if this SedDataGenerator_t's "id" attribute
 * is set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 (true) if this SedDataGenerator_t's "id" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetId(const SedDataGenerator_t * sdg);


/**
 * Predicate returning @c 1 (true) if this SedDataGenerator_t's "name"
 * attribute is set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 (true) if this SedDataGenerator_t's "name" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetName(const SedDataGenerator_t * sdg);


/**
 * Sets the value of the "id" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
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
 * to calling SedDataGenerator_unsetId().
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setId(SedDataGenerator_t * sdg, const char * id);


/**
 * Sets the value of the "name" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedDataGenerator_unsetName().
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setName(SedDataGenerator_t * sdg, const char * name);


/**
 * Unsets the value of the "id" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetId(SedDataGenerator_t * sdg);


/**
 * Unsets the value of the "name" attribute of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetName(SedDataGenerator_t * sdg);


/**
 * Returns the value of the "math" element of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose math is sought.
 *
 * @return the value of the "math" element of this SedDataGenerator_t as a
 * pointer to an ASTNode_t object.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
SedDataGenerator_getMath(const SedDataGenerator_t * sdg);


/**
 * Predicate returning @c 1 (true) if this SedDataGenerator_t's "math" element
 * is set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 (true) if this SedDataGenerator_t's "math" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetMath(const SedDataGenerator_t * sdg);


/**
 * Sets the value of the "math" element of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
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
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setMath(SedDataGenerator_t * sdg,
                         const LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*
                           math);


/**
 * Unsets the value of the "math" element of this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetMath(SedDataGenerator_t * sdg);


/**
 * Returns a ListOf_t * containing SedVariable_t objects from this
 * SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose SedListOfVariables is
 * sought.
 *
 * @return the SedListOfVariables from this SedDataGenerator_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDataGenerator_addVariable()
 * @see SedDataGenerator_createVariable()
 * @see SedDataGenerator_getVariableById()
 * @see SedDataGenerator_getVariable()
 * @see SedDataGenerator_getNumVariables()
 * @see SedDataGenerator_removeVariableById()
 * @see SedDataGenerator_removeVariable()
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataGenerator_getListOfVariables(SedDataGenerator_t* sdg);


/**
 * Get a SedVariable_t from the SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * retrieve.
 *
 * @return the nth SedVariable_t in the SedListOfVariables within this
 * SedDataGenerator.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_getVariable(SedDataGenerator_t* sdg, unsigned int n);


/**
 * Get a SedVariable_t from the SedDataGenerator_t based on its identifier.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param sid a string representing the identifier of the SedVariable_t to
 * retrieve.
 *
 * @return the SedVariable_t in the SedListOfVariables within this
 * SedDataGenerator with the given @p sid or @c NULL if no such SedVariable_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_getVariableById(SedDataGenerator_t* sdg, const char *sid);


/**
 * Get a SedVariable_t from the SedDataGenerator_t based on the TaskReference
 * to which it refers.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param sid a string representing the "taskReference" attribute of the
 * SedVariable_t object to retrieve.
 *
 * @return the first SedVariable_t in this SedDataGenerator_t based on the
 * given taskReference attribute or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_getVariableByTaskReference(SedDataGenerator_t* sdg,
                                            const char *sid);


/**
 * Get a SedVariable_t from the SedDataGenerator_t based on the ModelReference
 * to which it refers.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param sid a string representing the "modelReference" attribute of the
 * SedVariable_t object to retrieve.
 *
 * @return the first SedVariable_t in this SedDataGenerator_t based on the
 * given modelReference attribute or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_getVariableByModelReference(SedDataGenerator_t* sdg,
                                             const char *sid);


/**
 * Adds a copy of the given SedVariable_t to this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to which the SedVariable_t
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
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_addVariable(SedDataGenerator_t* sdg,
                             const SedVariable_t* sv);


/**
 * Get the number of SedVariable_t objects in this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to query.
 *
 * @return the number of SedVariable_t objects in this SedDataGenerator_t.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
unsigned int
SedDataGenerator_getNumVariables(SedDataGenerator_t* sdg);


/**
 * Creates a new SedVariable_t object, adds it to this SedDataGenerator_t
 * object and returns the SedVariable_t object created.
 *
 * @param sdg the SedDataGenerator_t structure to which the SedVariable_t
 * should be added.
 *
 * @return a new SedVariable_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_createVariable(SedDataGenerator_t* sdg);


/**
 * Removes the nth SedVariable_t from this SedDataGenerator_t and returns a
 * pointer to it.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * remove.
 *
 * @return a pointer to the nth SedVariable_t in this SedDataGenerator_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_removeVariable(SedDataGenerator_t* sdg, unsigned int n);


/**
 * Removes the SedVariable_t from this SedDataGenerator_t based on its
 * identifier and returns a pointer to it.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param sid a string representing the identifier of the SedVariable_t to
 * remove.
 *
 * @return the SedVariable_t in this SedDataGenerator_t based on the identifier
 * or NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedDataGenerator_removeVariableById(SedDataGenerator_t* sdg, const char* sid);


/**
 * Returns a ListOf_t * containing SedParameter_t objects from this
 * SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure whose SedListOfParameters is
 * sought.
 *
 * @return the SedListOfParameters from this SedDataGenerator_t as a ListOf_t
 * *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDataGenerator_addParameter()
 * @see SedDataGenerator_createParameter()
 * @see SedDataGenerator_getParameterById()
 * @see SedDataGenerator_getParameter()
 * @see SedDataGenerator_getNumParameters()
 * @see SedDataGenerator_removeParameterById()
 * @see SedDataGenerator_removeParameter()
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDataGenerator_getListOfParameters(SedDataGenerator_t* sdg);


/**
 * Get a SedParameter_t from the SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * retrieve.
 *
 * @return the nth SedParameter_t in the SedListOfParameters within this
 * SedDataGenerator.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_getParameter(SedDataGenerator_t* sdg, unsigned int n);


/**
 * Get a SedParameter_t from the SedDataGenerator_t based on its identifier.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param sid a string representing the identifier of the SedParameter_t to
 * retrieve.
 *
 * @return the SedParameter_t in the SedListOfParameters within this
 * SedDataGenerator with the given @p sid or @c NULL if no such SedParameter_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_getParameterById(SedDataGenerator_t* sdg, const char *sid);


/**
 * Adds a copy of the given SedParameter_t to this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to which the SedParameter_t
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
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_addParameter(SedDataGenerator_t* sdg,
                              const SedParameter_t* sp);


/**
 * Get the number of SedParameter_t objects in this SedDataGenerator_t.
 *
 * @param sdg the SedDataGenerator_t structure to query.
 *
 * @return the number of SedParameter_t objects in this SedDataGenerator_t.
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
unsigned int
SedDataGenerator_getNumParameters(SedDataGenerator_t* sdg);


/**
 * Creates a new SedParameter_t object, adds it to this SedDataGenerator_t
 * object and returns the SedParameter_t object created.
 *
 * @param sdg the SedDataGenerator_t structure to which the SedParameter_t
 * should be added.
 *
 * @return a new SedParameter_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_createParameter(SedDataGenerator_t* sdg);


/**
 * Removes the nth SedParameter_t from this SedDataGenerator_t and returns a
 * pointer to it.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * remove.
 *
 * @return a pointer to the nth SedParameter_t in this SedDataGenerator_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_removeParameter(SedDataGenerator_t* sdg, unsigned int n);


/**
 * Removes the SedParameter_t from this SedDataGenerator_t based on its
 * identifier and returns a pointer to it.
 *
 * @param sdg the SedDataGenerator_t structure to search.
 *
 * @param sid a string representing the identifier of the SedParameter_t to
 * remove.
 *
 * @return the SedParameter_t in this SedDataGenerator_t based on the
 * identifier or NULL if no such SedParameter_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedDataGenerator_removeParameterById(SedDataGenerator_t* sdg,
                                     const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDataGenerator_t object have been set.
 *
 * @param sdg the SedDataGenerator_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedDataGenerator_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedDataGenerator_t object are:
 * @li "id"
 *
 * @memberof SedDataGenerator_t
 */
LIBSEDML_EXTERN
int
SedDataGenerator_hasRequiredAttributes(const SedDataGenerator_t * sdg);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedDataGenerator_H__ */


