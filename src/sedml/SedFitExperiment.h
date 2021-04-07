/**
 * @file SedFitExperiment.h
 * @brief Definition of the SedFitExperiment class.
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
 * @class SedFitExperiment
 * @sbmlbrief{sedml} TODO:Definition of the SedFitExperiment class.
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
 * @class doc_sedfitexperiment_type
 *
 * @par
 * The attribute "type" on a SedFitExperiment object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sedml specification, the following are the
 * allowable values for "type":
 * <ul>
 * <li> @c "SteadyState", TODO:add description
 *
 * <li> @c "TimeCourse", TODO:add description
 *
 * </ul>
 */


#ifndef SedFitExperiment_H__
#define SedFitExperiment_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/common/SedmlEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedAlgorithm.h>
#include <sedml/SedListOfFitMappings.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedFitExperiment : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  ExperimentType_t mType;
  SedAlgorithm* mAlgorithm;
  SedListOfFitMappings mFitMappings;

  /** @endcond */

public:

  /**
   * Creates a new SedFitExperiment using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedFitExperiment.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedFitExperiment.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFitExperiment(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedFitExperiment using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFitExperiment(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedFitExperiment.
   *
   * @param orig the SedFitExperiment instance to copy.
   */
  SedFitExperiment(const SedFitExperiment& orig);


  /**
   * Assignment operator for SedFitExperiment.
   *
   * @param rhs the SedFitExperiment object whose values are to be used as the
   * basis of the assignment.
   */
  SedFitExperiment& operator=(const SedFitExperiment& rhs);


  /**
   * Creates and returns a deep copy of this SedFitExperiment object.
   *
   * @return a (deep) copy of this SedFitExperiment object.
   */
  virtual SedFitExperiment* clone() const;


  /**
   * Destructor for SedFitExperiment.
   */
  virtual ~SedFitExperiment();


  /**
   * Returns the value of the "type" attribute of this SedFitExperiment.
   *
   * @return the value of the "type" attribute of this SedFitExperiment as a
   * ExperimentType_t.
   *
   * @copydetails doc_sedfitexperiment_type
   * @if clike The value is drawn from the enumeration @ref ExperimentType_t
   * @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SEDML_EXPERIMENTTYPE_STEADYSTATE, ExperimentType_t}
   * @li @sbmlconstant{SEDML_EXPERIMENTTYPE_TIMECOURSE, ExperimentType_t}
   * @li @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t}
   */
  ExperimentType_t getType() const;


  /**
   * Returns the value of the "type" attribute of this SedFitExperiment.
   *
   * @return the value of the "type" attribute of this SedFitExperiment as a
   * string.
   *
   * @copydetails doc_sedfitexperiment_type
   * The possible values returned by this method are:
   * @li @c "SteadyState"
   * @li @c "TimeCourse"
   * @li @c "invalid ExperimentType value"
   */
  std::string getTypeAsString() const;


  /**
   * Predicate returning @c true if this SedFitExperiment's "type" attribute is
   * set.
   *
   * @return @c true if this SedFitExperiment's "type" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sedfitexperiment_type
   */
  bool isSetType() const;


  /**
   * Sets the value of the "type" attribute of this SedFitExperiment.
   *
   * @param type @if clike ExperimentType_t@else int@endif value of the "type"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedfitexperiment_type
   */
  int setType(const ExperimentType_t type);


  /**
   * Sets the value of the "type" attribute of this SedFitExperiment.
   *
   * @param type std::string& of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedfitexperiment_type
   */
  int setType(const std::string& type);


  /**
   * Unsets the value of the "type" attribute of this SedFitExperiment.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sedfitexperiment_type
   */
  int unsetType();


  /**
   * Returns the value of the "algorithm" element of this SedFitExperiment.
   *
   * @return the value of the "algorithm" element of this SedFitExperiment as a
   * SedAlgorithm*.
   */
  const SedAlgorithm* getAlgorithm() const;


  /**
   * Returns the value of the "algorithm" element of this SedFitExperiment.
   *
   * @return the value of the "algorithm" element of this SedFitExperiment as a
   * SedAlgorithm*.
   */
  SedAlgorithm* getAlgorithm();


  /**
   * Predicate returning @c true if this SedFitExperiment's "algorithm" element
   * is set.
   *
   * @return @c true if this SedFitExperiment's "algorithm" element has been
   * set, otherwise @c false is returned.
   */
  bool isSetAlgorithm() const;


  /**
   * Sets the value of the "algorithm" element of this SedFitExperiment.
   *
   * @param algorithm SedAlgorithm* value of the "algorithm" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAlgorithm(const SedAlgorithm* algorithm);


  /**
   * Creates a new SedAlgorithm object, adds it to this SedFitExperiment object
   * and returns the SedAlgorithm object created.
   *
   * @return a new SedAlgorithm object instance.
   */
  SedAlgorithm* createAlgorithm();


  /**
   * Unsets the value of the "algorithm" element of this SedFitExperiment.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAlgorithm();


  /**
   * Returns the SedListOfFitMappings from this SedFitExperiment.
   *
   * @return the SedListOfFitMappings from this SedFitExperiment.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see getFitMapping(const std::string& sid)
   * @see getFitMapping(unsigned int n)
   * @see getNumFitMappings()
   * @see removeFitMapping(const std::string& sid)
   * @see removeFitMapping(unsigned int n)
   */
  const SedListOfFitMappings* getListOfFitMappings() const;


  /**
   * Returns the SedListOfFitMappings from this SedFitExperiment.
   *
   * @return the SedListOfFitMappings from this SedFitExperiment.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see getFitMapping(const std::string& sid)
   * @see getFitMapping(unsigned int n)
   * @see getNumFitMappings()
   * @see removeFitMapping(const std::string& sid)
   * @see removeFitMapping(unsigned int n)
   */
  SedListOfFitMappings* getListOfFitMappings();


  /**
   * Get a SedFitMapping from the SedFitExperiment.
   *
   * @param n an unsigned int representing the index of the SedFitMapping to
   * retrieve.
   *
   * @return the nth SedFitMapping in the SedListOfFitMappings within this
   * SedFitExperiment or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see getFitMapping(const std::string& sid)
   * @see getNumFitMappings()
   * @see removeFitMapping(const std::string& sid)
   * @see removeFitMapping(unsigned int n)
   */
  SedFitMapping* getFitMapping(unsigned int n);


  /**
   * Get a SedFitMapping from the SedFitExperiment.
   *
   * @param n an unsigned int representing the index of the SedFitMapping to
   * retrieve.
   *
   * @return the nth SedFitMapping in the SedListOfFitMappings within this
   * SedFitExperiment or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see getFitMapping(const std::string& sid)
   * @see getNumFitMappings()
   * @see removeFitMapping(const std::string& sid)
   * @see removeFitMapping(unsigned int n)
   */
  const SedFitMapping* getFitMapping(unsigned int n) const;


  /**
   * Get a SedFitMapping from the SedFitExperiment based on the DataSource to
   * which it refers.
   *
   * @param sid a string representing the "dataSource" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedFitExperiment based on the
   * given dataSource attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedFitMapping* getFitMappingByDataSource(const std::string& sid) const;


  /**
   * Get a SedFitMapping from the SedFitExperiment based on the DataSource to
   * which it refers.
   *
   * @param sid a string representing the "dataSource" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedFitExperiment based on the
   * given dataSource attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedFitMapping* getFitMappingByDataSource(const std::string& sid);


  /**
   * Get a SedFitMapping from the SedFitExperiment based on the Target to which
   * it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedFitExperiment based on the
   * given target attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedFitMapping* getFitMappingByTarget(const std::string& sid) const;


  /**
   * Get a SedFitMapping from the SedFitExperiment based on the Target to which
   * it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedFitExperiment based on the
   * given target attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedFitMapping* getFitMappingByTarget(const std::string& sid);


  /**
   * Get a SedFitMapping from the SedFitExperiment based on the PointWeight to
   * which it refers.
   *
   * @param sid a string representing the "pointWeight" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedFitExperiment based on the
   * given pointWeight attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedFitMapping* getFitMappingByPointWeight(const std::string& sid)
    const;


  /**
   * Get a SedFitMapping from the SedFitExperiment based on the PointWeight to
   * which it refers.
   *
   * @param sid a string representing the "pointWeight" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedFitExperiment based on the
   * given pointWeight attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedFitMapping* getFitMappingByPointWeight(const std::string& sid);


  /**
   * Adds a copy of the given SedFitMapping to this SedFitExperiment.
   *
   * @param sfm the SedFitMapping object to add.
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
   * @see createFitMapping()
   * @see getFitMapping(const std::string& sid)
   * @see getFitMapping(unsigned int n)
   * @see getNumFitMappings()
   * @see removeFitMapping(const std::string& sid)
   * @see removeFitMapping(unsigned int n)
   */
  int addFitMapping(const SedFitMapping* sfm);


  /**
   * Get the number of SedFitMapping objects in this SedFitExperiment.
   *
   * @return the number of SedFitMapping objects in this SedFitExperiment.
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see getFitMapping(const std::string& sid)
   * @see getFitMapping(unsigned int n)
   * @see removeFitMapping(const std::string& sid)
   * @see removeFitMapping(unsigned int n)
   */
  unsigned int getNumFitMappings() const;


  /**
   * Creates a new SedFitMapping object, adds it to this SedFitExperiment
   * object and returns the SedFitMapping object created.
   *
   * @return a new SedFitMapping object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see getFitMapping(const std::string& sid)
   * @see getFitMapping(unsigned int n)
   * @see getNumFitMappings()
   * @see removeFitMapping(const std::string& sid)
   * @see removeFitMapping(unsigned int n)
   */
  SedFitMapping* createFitMapping();


  /**
   * Removes the nth SedFitMapping from this SedFitExperiment and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedFitMapping to
   * remove.
   *
   * @return a pointer to the nth SedFitMapping in this SedFitExperiment.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see getFitMapping(const std::string& sid)
   * @see getFitMapping(unsigned int n)
   * @see getNumFitMappings()
   * @see removeFitMapping(const std::string& sid)
   */
  SedFitMapping* removeFitMapping(unsigned int n);


  /**
   * Returns the XML element name of this SedFitExperiment object.
   *
   * For SedFitExperiment, the XML element name is always @c "fitExperiment".
   *
   * @return the name of this element, i.e. @c "fitExperiment".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedFitExperiment object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_FIT_EXPERIMENT, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedFitExperiment object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedFitExperiment have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Gets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Gets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Gets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Gets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Predicate returning @c true if this SedFitExperiment's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedFitExperiment's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Sets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Sets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Sets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * Sets the value of the "attributeName" attribute of this SedFitExperiment.
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
   * SedFitExperiment.
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
   * Creates and returns an new "elementName" object in this SedFitExperiment.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedFitExperiment.
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
   * SedFitExperiment.
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
   * Returns the number of "elementName" in this SedFitExperiment.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedFitExperiment.
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
 * Creates a new SedFitExperiment_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedFitExperiment_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedFitExperiment_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t *
SedFitExperiment_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedFitExperiment_t object.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @return a (deep) copy of this SedFitExperiment_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedFitExperiment_clone(const SedFitExperiment_t* sfe);


/**
 * Frees this SedFitExperiment_t object.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
void
SedFitExperiment_free(SedFitExperiment_t* sfe);


/**
 * Returns the value of the "id" attribute of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedFitExperiment_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
char *
SedFitExperiment_getId(const SedFitExperiment_t * sfe);


/**
 * Returns the value of the "type" attribute of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedFitExperiment_t as a
 * ExperimentType_t.
 *
 * @copydetails doc_sedfitexperiment_type
 * @if clike The value is drawn from the enumeration @ref ExperimentType_t
 * @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SEDML_EXPERIMENTTYPE_STEADYSTATE, ExperimentType_t}
 * @li @sbmlconstant{SEDML_EXPERIMENTTYPE_TIMECOURSE, ExperimentType_t}
 * @li @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t}
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
ExperimentType_t
SedFitExperiment_getType(const SedFitExperiment_t * sfe);


/**
 * Returns the value of the "type" attribute of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedFitExperiment_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sedfitexperiment_type
 * The possible values returned by this method are:
 * @li @c "SteadyState"
 * @li @c "TimeCourse"
 * @li @c "invalid ExperimentType value"
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
char *
SedFitExperiment_getTypeAsString(const SedFitExperiment_t * sfe);


/**
 * Predicate returning @c 1 (true) if this SedFitExperiment_t's "id" attribute
 * is set.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @return @c 1 (true) if this SedFitExperiment_t's "id" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_isSetId(const SedFitExperiment_t * sfe);


/**
 * Predicate returning @c 1 (true) if this SedFitExperiment_t's "type"
 * attribute is set.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @return @c 1 (true) if this SedFitExperiment_t's "type" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sedfitexperiment_type
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_isSetType(const SedFitExperiment_t * sfe);


/**
 * Sets the value of the "id" attribute of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure.
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
 * to calling SedFitExperiment_unsetId().
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_setId(SedFitExperiment_t * sfe, const char * id);


/**
 * Sets the value of the "type" attribute of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @param type ExperimentType_t value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedfitexperiment_type
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_setType(SedFitExperiment_t * sfe, ExperimentType_t type);


/**
 * Sets the value of the "type" attribute of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @param type const char * of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedfitexperiment_type
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_setTypeAsString(SedFitExperiment_t * sfe, const char * type);


/**
 * Unsets the value of the "id" attribute of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_unsetId(SedFitExperiment_t * sfe);


/**
 * Unsets the value of the "type" attribute of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedfitexperiment_type
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_unsetType(SedFitExperiment_t * sfe);


/**
 * Returns the value of the "algorithm" element of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure whose algorithm is sought.
 *
 * @return the value of the "algorithm" element of this SedFitExperiment_t as a
 * SedAlgorithm*.
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedFitExperiment_getAlgorithm(const SedFitExperiment_t * sfe);


/**
 * Predicate returning @c 1 (true) if this SedFitExperiment_t's "algorithm"
 * element is set.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @return @c 1 (true) if this SedFitExperiment_t's "algorithm" element has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_isSetAlgorithm(const SedFitExperiment_t * sfe);


/**
 * Sets the value of the "algorithm" element of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @param algorithm SedAlgorithm_t* value of the "algorithm" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_setAlgorithm(SedFitExperiment_t * sfe,
                              const SedAlgorithm_t* algorithm);


/**
 * Creates a new SedAlgorithm_t object, adds it to this SedFitExperiment_t
 * object and returns the SedAlgorithm_t object created.
 *
 * @param sfe the SedFitExperiment_t structure to which the SedAlgorithm_t
 * should be added.
 *
 * @return a new SedAlgorithm_t object instance.
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedFitExperiment_createAlgorithm(SedFitExperiment_t* sfe);


/**
 * Unsets the value of the "algorithm" element of this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_unsetAlgorithm(SedFitExperiment_t * sfe);


/**
 * Returns a ListOf_t * containing SedFitMapping_t objects from this
 * SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure whose SedListOfFitMappings is
 * sought.
 *
 * @return the SedListOfFitMappings from this SedFitExperiment_t as a ListOf_t
 * *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedFitExperiment_addFitMapping()
 * @see SedFitExperiment_createFitMapping()
 * @see SedFitExperiment_getFitMappingById()
 * @see SedFitExperiment_getFitMapping()
 * @see SedFitExperiment_getNumFitMappings()
 * @see SedFitExperiment_removeFitMappingById()
 * @see SedFitExperiment_removeFitMapping()
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedFitExperiment_getListOfFitMappings(SedFitExperiment_t* sfe);


/**
 * Get a SedFitMapping_t from the SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedFitMapping_t to
 * retrieve.
 *
 * @return the nth SedFitMapping_t in the SedListOfFitMappings within this
 * SedFitExperiment or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_getFitMapping(SedFitExperiment_t* sfe, unsigned int n);


/**
 * Get a SedFitMapping_t from the SedFitExperiment_t based on the DataSource to
 * which it refers.
 *
 * @param sfe the SedFitExperiment_t structure to search.
 *
 * @param sid a string representing the "dataSource" attribute of the
 * SedFitMapping_t object to retrieve.
 *
 * @return the first SedFitMapping_t in this SedFitExperiment_t based on the
 * given dataSource attribute or NULL if no such SedFitMapping_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_getFitMappingByDataSource(SedFitExperiment_t* sfe,
                                           const char *sid);


/**
 * Get a SedFitMapping_t from the SedFitExperiment_t based on the Target to
 * which it refers.
 *
 * @param sfe the SedFitExperiment_t structure to search.
 *
 * @param sid a string representing the "target" attribute of the
 * SedFitMapping_t object to retrieve.
 *
 * @return the first SedFitMapping_t in this SedFitExperiment_t based on the
 * given target attribute or NULL if no such SedFitMapping_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_getFitMappingByTarget(SedFitExperiment_t* sfe,
                                       const char *sid);


/**
 * Get a SedFitMapping_t from the SedFitExperiment_t based on the PointWeight
 * to which it refers.
 *
 * @param sfe the SedFitExperiment_t structure to search.
 *
 * @param sid a string representing the "pointWeight" attribute of the
 * SedFitMapping_t object to retrieve.
 *
 * @return the first SedFitMapping_t in this SedFitExperiment_t based on the
 * given pointWeight attribute or NULL if no such SedFitMapping_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_getFitMappingByPointWeight(SedFitExperiment_t* sfe,
                                            const char *sid);


/**
 * Adds a copy of the given SedFitMapping_t to this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure to which the SedFitMapping_t
 * should be added.
 *
 * @param sfm the SedFitMapping_t object to add.
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
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_addFitMapping(SedFitExperiment_t* sfe,
                               const SedFitMapping_t* sfm);


/**
 * Get the number of SedFitMapping_t objects in this SedFitExperiment_t.
 *
 * @param sfe the SedFitExperiment_t structure to query.
 *
 * @return the number of SedFitMapping_t objects in this SedFitExperiment_t.
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
unsigned int
SedFitExperiment_getNumFitMappings(SedFitExperiment_t* sfe);


/**
 * Creates a new SedFitMapping_t object, adds it to this SedFitExperiment_t
 * object and returns the SedFitMapping_t object created.
 *
 * @param sfe the SedFitExperiment_t structure to which the SedFitMapping_t
 * should be added.
 *
 * @return a new SedFitMapping_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_createFitMapping(SedFitExperiment_t* sfe);


/**
 * Removes the nth SedFitMapping_t from this SedFitExperiment_t and returns a
 * pointer to it.
 *
 * @param sfe the SedFitExperiment_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedFitMapping_t to
 * remove.
 *
 * @return a pointer to the nth SedFitMapping_t in this SedFitExperiment_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitExperiment_removeFitMapping(SedFitExperiment_t* sfe, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFitExperiment_t object have been set.
 *
 * @param sfe the SedFitExperiment_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedFitExperiment_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitExperiment_t
 */
LIBSEDML_EXTERN
int
SedFitExperiment_hasRequiredAttributes(const SedFitExperiment_t * sfe);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedFitExperiment_H__ */


