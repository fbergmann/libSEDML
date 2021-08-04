/**
 * @file SedAdjustableParameter.h
 * @brief Definition of the SedAdjustableParameter class.
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
 * @class SedAdjustableParameter
 * @sbmlbrief{sedml} TODO:Definition of the SedAdjustableParameter class.
 */


#ifndef SedAdjustableParameter_H__
#define SedAdjustableParameter_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedBounds.h>
#include <sedml/SedListOfExperimentReferences.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedAdjustableParameter : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mInitialValue;
  bool mIsSetInitialValue;
  SedBounds* mBounds;
  SedListOfExperimentReferences mExperimentReferences;
  std::string mModelReference;
  std::string mTarget;

  /** @endcond */

public:

  /**
   * Creates a new SedAdjustableParameter using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedAdjustableParameter.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedAdjustableParameter.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAdjustableParameter(unsigned int level = SEDML_DEFAULT_LEVEL,
                         unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedAdjustableParameter using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAdjustableParameter(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedAdjustableParameter.
   *
   * @param orig the SedAdjustableParameter instance to copy.
   */
  SedAdjustableParameter(const SedAdjustableParameter& orig);


  /**
   * Assignment operator for SedAdjustableParameter.
   *
   * @param rhs the SedAdjustableParameter object whose values are to be used
   * as the basis of the assignment.
   */
  SedAdjustableParameter& operator=(const SedAdjustableParameter& rhs);


  /**
   * Creates and returns a deep copy of this SedAdjustableParameter object.
   *
   * @return a (deep) copy of this SedAdjustableParameter object.
   */
  virtual SedAdjustableParameter* clone() const;


  /**
   * Destructor for SedAdjustableParameter.
   */
  virtual ~SedAdjustableParameter();


  /**
   * Returns the value of the "initialValue" attribute of this
   * SedAdjustableParameter.
   *
   * @return the value of the "initialValue" attribute of this
   * SedAdjustableParameter as a double.
   */
  double getInitialValue() const;


  /**
   * Returns the value of the "modelReference" attribute of this
   * SedAdjustableParameter.
   *
   * @return the value of the "modelReference" attribute of this
   * SedAdjustableParameter as a string.
   */
  const std::string& getModelReference() const;


  /**
   * Returns the value of the "target" attribute of this
   * SedAdjustableParameter.
   *
   * @return the value of the "target" attribute of this SedAdjustableParameter
   * as a string.
   */
  const std::string& getTarget() const;


  /**
   * Predicate returning @c true if this SedAdjustableParameter's
   * "initialValue" attribute is set.
   *
   * @return @c true if this SedAdjustableParameter's "initialValue" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetInitialValue() const;


  /**
   * Predicate returning @c true if this SedAdjustableParameter's
   * "modelReference" attribute is set.
   *
   * @return @c true if this SedAdjustableParameter's "modelReference"
   * attribute has been set, otherwise @c false is returned.
   */
  bool isSetModelReference() const;


  /**
   * Predicate returning @c true if this SedAdjustableParameter's "target"
   * attribute is set.
   *
   * @return @c true if this SedAdjustableParameter's "target" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Sets the value of the "initialValue" attribute of this
   * SedAdjustableParameter.
   *
   * @param initialValue double value of the "initialValue" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setInitialValue(double initialValue);


  /**
   * Sets the value of the "modelReference" attribute of this
   * SedAdjustableParameter.
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
   * Sets the value of the "target" attribute of this SedAdjustableParameter.
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
   * Unsets the value of the "initialValue" attribute of this
   * SedAdjustableParameter.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetInitialValue();


  /**
   * Unsets the value of the "modelReference" attribute of this
   * SedAdjustableParameter.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetModelReference();


  /**
   * Unsets the value of the "target" attribute of this SedAdjustableParameter.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Returns the value of the "bounds" element of this SedAdjustableParameter.
   *
   * @return the value of the "bounds" element of this SedAdjustableParameter
   * as a SedBounds*.
   */
  const SedBounds* getBounds() const;


  /**
   * Returns the value of the "bounds" element of this SedAdjustableParameter.
   *
   * @return the value of the "bounds" element of this SedAdjustableParameter
   * as a SedBounds*.
   */
  SedBounds* getBounds();


  /**
   * Predicate returning @c true if this SedAdjustableParameter's "bounds"
   * element is set.
   *
   * @return @c true if this SedAdjustableParameter's "bounds" element has been
   * set, otherwise @c false is returned.
   */
  bool isSetBounds() const;


  /**
   * Sets the value of the "bounds" element of this SedAdjustableParameter.
   *
   * @param bounds SedBounds* value of the "bounds" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBounds(const SedBounds* bounds);


  /**
   * Creates a new SedBounds object, adds it to this SedAdjustableParameter
   * object and returns the SedBounds object created.
   *
   * @return a new SedBounds object instance.
   */
  SedBounds* createBounds();


  /**
   * Unsets the value of the "bounds" element of this SedAdjustableParameter.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBounds();


  /**
   * Returns the SedListOfExperimentReferences from this SedAdjustableParameter.
   *
   * @return the SedListOfExperimentReferences from this SedAdjustableParameter.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see getExperimentReference(const std::string& sid)
   * @see getExperimentReference(unsigned int n)
   * @see getNumExperimentReferences()
   * @see removeExperimentReference(const std::string& sid)
   * @see removeExperimentReference(unsigned int n)
   */
  const SedListOfExperimentReferences* getListOfExperimentReferences() const;


  /**
   * Returns the SedListOfExperimentReferences from this SedAdjustableParameter.
   *
   * @return the SedListOfExperimentReferences from this SedAdjustableParameter.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see getExperimentReference(const std::string& sid)
   * @see getExperimentReference(unsigned int n)
   * @see getNumExperimentReferences()
   * @see removeExperimentReference(const std::string& sid)
   * @see removeExperimentReference(unsigned int n)
   */
  SedListOfExperimentReferences* getListOfExperimentReferences();


  /**
   * Get a SedExperimentReference from the SedAdjustableParameter.
   *
   * @param n an unsigned int representing the index of the SedExperimentReference to
   * retrieve.
   *
   * @return the nth SedExperimentReference in the SedListOfExperimentReferences within
   * this SedAdjustableParameter.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see getExperimentReference(const std::string& sid)
   * @see getNumExperimentReferences()
   * @see removeExperimentReference(const std::string& sid)
   * @see removeExperimentReference(unsigned int n)
   */
  SedExperimentReference* getExperimentReference(unsigned int n);


  /**
   * Get a SedExperimentReference from the SedAdjustableParameter.
   *
   * @param n an unsigned int representing the index of the SedExperimentReference to
   * retrieve.
   *
   * @return the nth SedExperimentReference in the SedListOfExperimentReferences within
   * this SedAdjustableParameter.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see getExperimentReference(const std::string& sid)
   * @see getNumExperimentReferences()
   * @see removeExperimentReference(const std::string& sid)
   * @see removeExperimentReference(unsigned int n)
   */
  const SedExperimentReference* getExperimentReference(unsigned int n) const;


  /**
   * Get a SedExperimentReference from the SedAdjustableParameter based on the
   * ExperimentId to which it refers.
   *
   * @param sid a string representing the "experimentId" attribute of the
   * SedExperimentReference object to retrieve.
   *
   * @return the first SedExperimentReference in this SedAdjustableParameter based on
   * the given experimentId attribute or NULL if no such SedExperimentReference
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedExperimentReference* getExperimentReferenceByExperimentId(const std::string&
    sid) const;


  /**
   * Get a SedExperimentReference from the SedAdjustableParameter based on the
   * ExperimentId to which it refers.
   *
   * @param sid a string representing the "experimentId" attribute of the
   * SedExperimentReference object to retrieve.
   *
   * @return the first SedExperimentReference in this SedAdjustableParameter based on
   * the given experimentId attribute or NULL if no such SedExperimentReference
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedExperimentReference* getExperimentReferenceByExperimentId(const std::string& sid);


  /**
   * Adds a copy of the given SedExperimentReference to this SedAdjustableParameter.
   *
   * @param ser the SedExperimentReference object to add.
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
   * @see createExperimentReference()
   * @see getExperimentReference(const std::string& sid)
   * @see getExperimentReference(unsigned int n)
   * @see getNumExperimentReferences()
   * @see removeExperimentReference(const std::string& sid)
   * @see removeExperimentReference(unsigned int n)
   */
  int addExperimentReference(const SedExperimentReference* ser);


  /**
   * Get the number of SedExperimentReference objects in this SedAdjustableParameter.
   *
   * @return the number of SedExperimentReference objects in this
   * SedAdjustableParameter.
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see getExperimentReference(const std::string& sid)
   * @see getExperimentReference(unsigned int n)
   * @see removeExperimentReference(const std::string& sid)
   * @see removeExperimentReference(unsigned int n)
   */
  unsigned int getNumExperimentReferences() const;


  /**
   * Creates a new SedExperimentReference object, adds it to this
   * SedAdjustableParameter object and returns the SedExperimentReference object
   * created.
   *
   * @return a new SedExperimentReference object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see getExperimentReference(const std::string& sid)
   * @see getExperimentReference(unsigned int n)
   * @see getNumExperimentReferences()
   * @see removeExperimentReference(const std::string& sid)
   * @see removeExperimentReference(unsigned int n)
   */
  SedExperimentReference* createExperimentReference();


  /**
   * Removes the nth SedExperimentReference from this SedAdjustableParameter and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedExperimentReference to
   * remove.
   *
   * @return a pointer to the nth SedExperimentReference in this
   * SedAdjustableParameter.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see getExperimentReference(const std::string& sid)
   * @see getExperimentReference(unsigned int n)
   * @see getNumExperimentReferences()
   * @see removeExperimentReference(const std::string& sid)
   */
  SedExperimentReference* removeExperimentReference(unsigned int n);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedAdjustableParameter object.
   *
   * For SedAdjustableParameter, the XML element name is always
   * @c "adjustableParameter".
   *
   * @return the name of this element, i.e. @c "adjustableParameter".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedAdjustableParameter object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_ADJUSTABLE_PARAMETER, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedAdjustableParameter object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedAdjustableParameter have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedAdjustableParameter object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedAdjustableParameter have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedAdjustableParameter object are:
   * @li "bounds"
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * Predicate returning @c true if this SedAdjustableParameter's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedAdjustableParameter's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * SedAdjustableParameter.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedAdjustableParameter.
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
   * SedAdjustableParameter.
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
   * Returns the number of "elementName" in this SedAdjustableParameter.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedAdjustableParameter.
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
 * Creates a new SedAdjustableParameter_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAdjustableParameter_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAdjustableParameter_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t *
SedAdjustableParameter_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedAdjustableParameter_t object.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @return a (deep) copy of this SedAdjustableParameter_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedAdjustableParameter_clone(const SedAdjustableParameter_t* sap);


/**
 * Frees this SedAdjustableParameter_t object.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
void
SedAdjustableParameter_free(SedAdjustableParameter_t* sap);


/**
 * Returns the value of the "initialValue" attribute of this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure whose initialValue is
 * sought.
 *
 * @return the value of the "initialValue" attribute of this
 * SedAdjustableParameter_t as a double.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
double
SedAdjustableParameter_getInitialValue(const SedAdjustableParameter_t * sap);


/**
 * Returns the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure whose modelReference is
 * sought.
 *
 * @return the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
char *
SedAdjustableParameter_getModelReference(const SedAdjustableParameter_t * sap);


/**
 * Returns the value of the "target" attribute of this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SedAdjustableParameter_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
char *
SedAdjustableParameter_getTarget(const SedAdjustableParameter_t * sap);


/**
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's
 * "initialValue" attribute is set.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @return @c 1 (true) if this SedAdjustableParameter_t's "initialValue"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetInitialValue(const SedAdjustableParameter_t * sap);


/**
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's
 * "modelReference" attribute is set.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @return @c 1 (true) if this SedAdjustableParameter_t's "modelReference"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetModelReference(const SedAdjustableParameter_t *
  sap);


/**
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's "target"
 * attribute is set.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @return @c 1 (true) if this SedAdjustableParameter_t's "target" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetTarget(const SedAdjustableParameter_t * sap);


/**
 * Sets the value of the "initialValue" attribute of this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @param initialValue double value of the "initialValue" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setInitialValue(SedAdjustableParameter_t * sap,
                                       double initialValue);


/**
 * Sets the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure.
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
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setModelReference(SedAdjustableParameter_t * sap,
                                         const char * modelReference);


/**
 * Sets the value of the "target" attribute of this SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p target = @c NULL or an empty string is
 * equivalent to calling SedAdjustableParameter_unsetTarget().
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setTarget(SedAdjustableParameter_t * sap,
                                 const char * target);


/**
 * Unsets the value of the "initialValue" attribute of this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetInitialValue(SedAdjustableParameter_t * sap);


/**
 * Unsets the value of the "modelReference" attribute of this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetModelReference(SedAdjustableParameter_t * sap);


/**
 * Unsets the value of the "target" attribute of this SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetTarget(SedAdjustableParameter_t * sap);


/**
 * Returns the value of the "bounds" element of this SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure whose bounds is sought.
 *
 * @return the value of the "bounds" element of this SedAdjustableParameter_t
 * as a SedBounds*.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
const SedBounds_t*
SedAdjustableParameter_getBounds(const SedAdjustableParameter_t * sap);


/**
 * Predicate returning @c 1 (true) if this SedAdjustableParameter_t's "bounds"
 * element is set.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @return @c 1 (true) if this SedAdjustableParameter_t's "bounds" element has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_isSetBounds(const SedAdjustableParameter_t * sap);


/**
 * Sets the value of the "bounds" element of this SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @param bounds SedBounds_t* value of the "bounds" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_setBounds(SedAdjustableParameter_t * sap,
                                 const SedBounds_t* bounds);


/**
 * Creates a new SedBounds_t object, adds it to this SedAdjustableParameter_t
 * object and returns the SedBounds_t object created.
 *
 * @param sap the SedAdjustableParameter_t structure to which the SedBounds_t
 * should be added.
 *
 * @return a new SedBounds_t object instance.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
SedBounds_t*
SedAdjustableParameter_createBounds(SedAdjustableParameter_t* sap);


/**
 * Unsets the value of the "bounds" element of this SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_unsetBounds(SedAdjustableParameter_t * sap);


/**
 * Returns a ListOf_t * containing SedExperimentReference_t objects from this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure whose
 * SedListOfExperimentReferences is sought.
 *
 * @return the SedListOfExperimentReferences from this SedAdjustableParameter_t as a
 * ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedAdjustableParameter_addExperimentReference()
 * @see SedAdjustableParameter_createExperimentReference()
 * @see SedAdjustableParameter_getExperimentReferenceById()
 * @see SedAdjustableParameter_getExperimentReference()
 * @see SedAdjustableParameter_getNumExperimentReferences()
 * @see SedAdjustableParameter_removeExperimentReferenceById()
 * @see SedAdjustableParameter_removeExperimentReference()
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedAdjustableParameter_getListOfExperimentReferences(SedAdjustableParameter_t* sap);


/**
 * Get a SedExperimentReference_t from the SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedExperimentReference_t to
 * retrieve.
 *
 * @return the nth SedExperimentReference_t in the SedListOfExperimentReferences within
 * this SedAdjustableParameter.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedAdjustableParameter_getExperimentReference(SedAdjustableParameter_t* sap,
                                        unsigned int n);


/**
 * Get a SedExperimentReference_t from the SedAdjustableParameter_t based on the
 * ExperimentId to which it refers.
 *
 * @param sap the SedAdjustableParameter_t structure to search.
 *
 * @param sid a string representing the "experimentId" attribute of the
 * SedExperimentReference_t object to retrieve.
 *
 * @return the first SedExperimentReference_t in this SedAdjustableParameter_t based
 * on the given experimentId attribute or NULL if no such SedExperimentReference_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedAdjustableParameter_getExperimentReferenceByExperimentId(
                                                      SedAdjustableParameter_t*
                                                        sap,
                                                      const char *sid);


/**
 * Adds a copy of the given SedExperimentReference_t to this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure to which the
 * SedExperimentReference_t should be added.
 *
 * @param ser the SedExperimentReference_t object to add.
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
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_addExperimentReference(SedAdjustableParameter_t* sap,
                                        const SedExperimentReference_t* ser);


/**
 * Get the number of SedExperimentReference_t objects in this
 * SedAdjustableParameter_t.
 *
 * @param sap the SedAdjustableParameter_t structure to query.
 *
 * @return the number of SedExperimentReference_t objects in this
 * SedAdjustableParameter_t.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
unsigned int
SedAdjustableParameter_getNumExperimentReferences(SedAdjustableParameter_t* sap);


/**
 * Creates a new SedExperimentReference_t object, adds it to this
 * SedAdjustableParameter_t object and returns the SedExperimentReference_t object
 * created.
 *
 * @param sap the SedAdjustableParameter_t structure to which the
 * SedExperimentReference_t should be added.
 *
 * @return a new SedExperimentReference_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedAdjustableParameter_createExperimentReference(SedAdjustableParameter_t* sap);


/**
 * Removes the nth SedExperimentReference_t from this SedAdjustableParameter_t and
 * returns a pointer to it.
 *
 * @param sap the SedAdjustableParameter_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedExperimentReference_t to
 * remove.
 *
 * @return a pointer to the nth SedExperimentReference_t in this
 * SedAdjustableParameter_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedAdjustableParameter_removeExperimentReference(SedAdjustableParameter_t* sap,
                                           unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAdjustableParameter_t object have been set.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedAdjustableParameter_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_hasRequiredAttributes(const SedAdjustableParameter_t *
  sap);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedAdjustableParameter_t object have been set.
 *
 * @param sap the SedAdjustableParameter_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedAdjustableParameter_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedAdjustableParameter_t object are:
 * @li "bounds"
 *
 * @memberof SedAdjustableParameter_t
 */
LIBSEDML_EXTERN
int
SedAdjustableParameter_hasRequiredElements(const SedAdjustableParameter_t *
  sap);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedAdjustableParameter_H__ */


