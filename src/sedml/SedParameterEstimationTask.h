/**
 * @file SedParameterEstimationTask.h
 * @brief Definition of the SedParameterEstimationTask class.
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
 * @class SedParameterEstimationTask
 * @sbmlbrief{sedml} TODO:Definition of the SedParameterEstimationTask class.
 */


#ifndef SedParameterEstimationTask_H__
#define SedParameterEstimationTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedAbstractTask.h>
#include <sedml/SedAlgorithm.h>
#include <sedml/SedObjective.h>
#include <sedml/SedListOfAdjustableParameters.h>
#include <sedml/SedListOfFitExperiments.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedParameterEstimationTask : public SedAbstractTask
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  SedAlgorithm* mAlgorithm;
  SedObjective* mObjective;
  SedListOfAdjustableParameters mAdjustableParameters;
  SedListOfFitExperiments mFitExperiments;

  /** @endcond */

public:

  /**
   * Creates a new SedParameterEstimationTask using the given SED-ML Level and @
   * p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedParameterEstimationTask.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedParameterEstimationTask.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedParameterEstimationTask(unsigned int level = SEDML_DEFAULT_LEVEL,
                             unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedParameterEstimationTask using the given SedNamespaces
   * object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedParameterEstimationTask(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedParameterEstimationTask.
   *
   * @param orig the SedParameterEstimationTask instance to copy.
   */
  SedParameterEstimationTask(const SedParameterEstimationTask& orig);


  /**
   * Assignment operator for SedParameterEstimationTask.
   *
   * @param rhs the SedParameterEstimationTask object whose values are to be
   * used as the basis of the assignment.
   */
  SedParameterEstimationTask& operator=(const SedParameterEstimationTask& rhs);


  /**
   * Creates and returns a deep copy of this SedParameterEstimationTask object.
   *
   * @return a (deep) copy of this SedParameterEstimationTask object.
   */
  virtual SedParameterEstimationTask* clone() const;


  /**
   * Destructor for SedParameterEstimationTask.
   */
  virtual ~SedParameterEstimationTask();


  /**
   * Returns the value of the "algorithm" element of this
   * SedParameterEstimationTask.
   *
   * @return the value of the "algorithm" element of this
   * SedParameterEstimationTask as a SedAlgorithm*.
   */
  const SedAlgorithm* getAlgorithm() const;


  /**
   * Returns the value of the "algorithm" element of this
   * SedParameterEstimationTask.
   *
   * @return the value of the "algorithm" element of this
   * SedParameterEstimationTask as a SedAlgorithm*.
   */
  SedAlgorithm* getAlgorithm();


  /**
   * Returns the value of the "objective" element of this
   * SedParameterEstimationTask.
   *
   * @return the value of the "objective" element of this
   * SedParameterEstimationTask as a SedObjective*.
   */
  const SedObjective* getObjective() const;


  /**
   * Returns the value of the "objective" element of this
   * SedParameterEstimationTask.
   *
   * @return the value of the "objective" element of this
   * SedParameterEstimationTask as a SedObjective*.
   */
  SedObjective* getObjective();


  /**
   * Predicate returning @c true if this SedParameterEstimationTask's
   * "algorithm" element is set.
   *
   * @return @c true if this SedParameterEstimationTask's "algorithm" element
   * has been set, otherwise @c false is returned.
   */
  bool isSetAlgorithm() const;


  /**
   * Predicate returning @c true if this SedParameterEstimationTask's
   * "objective" element is set.
   *
   * @return @c true if this SedParameterEstimationTask's "objective" element
   * has been set, otherwise @c false is returned.
   */
  bool isSetObjective() const;


  /**
   * Sets the value of the "algorithm" element of this
   * SedParameterEstimationTask.
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
   * Sets the value of the "objective" element of this
   * SedParameterEstimationTask.
   *
   * @param objective SedObjective* value of the "objective" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setObjective(const SedObjective* objective);


  /**
   * Creates a new SedAlgorithm object, adds it to this
   * SedParameterEstimationTask object and returns the SedAlgorithm object
   * created.
   *
   * @return a new SedAlgorithm object instance.
   */
  SedAlgorithm* createAlgorithm();


  /**
   * Creates a new SedLeastSquareObjectiveFunction object, adds it to this
   * SedParameterEstimationTask object and returns the
   * SedLeastSquareObjectiveFunction object created.
   *
   * @return a new SedLeastSquareObjectiveFunction object instance.
   */
  SedLeastSquareObjectiveFunction* createLeastSquareObjectiveFunction();


  /**
   * Unsets the value of the "algorithm" element of this
   * SedParameterEstimationTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAlgorithm();


  /**
   * Unsets the value of the "objective" element of this
   * SedParameterEstimationTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetObjective();


  /**
   * Returns the SedListOfAdjustableParameters from this
   * SedParameterEstimationTask.
   *
   * @return the SedListOfAdjustableParameters from this
   * SedParameterEstimationTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see getAdjustableParameter(const std::string& sid)
   * @see getAdjustableParameter(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see removeAdjustableParameter(const std::string& sid)
   * @see removeAdjustableParameter(unsigned int n)
   */
  const SedListOfAdjustableParameters* getListOfAdjustableParameters() const;


  /**
   * Returns the SedListOfAdjustableParameters from this
   * SedParameterEstimationTask.
   *
   * @return the SedListOfAdjustableParameters from this
   * SedParameterEstimationTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see getAdjustableParameter(const std::string& sid)
   * @see getAdjustableParameter(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see removeAdjustableParameter(const std::string& sid)
   * @see removeAdjustableParameter(unsigned int n)
   */
  SedListOfAdjustableParameters* getListOfAdjustableParameters();


  /**
   * Get a SedAdjustableParameter from the SedParameterEstimationTask.
   *
   * @param n an unsigned int representing the index of the
   * SedAdjustableParameter to retrieve.
   *
   * @return the nth SedAdjustableParameter in the
   * SedListOfAdjustableParameters within this SedParameterEstimationTask or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see getAdjustableParameter(const std::string& sid)
   * @see getNumAdjustableParameters()
   * @see removeAdjustableParameter(const std::string& sid)
   * @see removeAdjustableParameter(unsigned int n)
   */
  SedAdjustableParameter* getAdjustableParameter(unsigned int n);


  /**
   * Get a SedAdjustableParameter from the SedParameterEstimationTask.
   *
   * @param n an unsigned int representing the index of the
   * SedAdjustableParameter to retrieve.
   *
   * @return the nth SedAdjustableParameter in the
   * SedListOfAdjustableParameters within this SedParameterEstimationTask or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see getAdjustableParameter(const std::string& sid)
   * @see getNumAdjustableParameters()
   * @see removeAdjustableParameter(const std::string& sid)
   * @see removeAdjustableParameter(unsigned int n)
   */
  const SedAdjustableParameter* getAdjustableParameter(unsigned int n) const;


  /**
   * Get a SedAdjustableParameter from the SedParameterEstimationTask based on
   * the ModelReference to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedAdjustableParameter object to retrieve.
   *
   * @return the first SedAdjustableParameter in this
   * SedParameterEstimationTask based on the given modelReference attribute or
   * NULL if no such SedAdjustableParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAdjustableParameter* getAdjustableParameterByModelReference(const
    std::string& sid) const;


  /**
   * Get a SedAdjustableParameter from the SedParameterEstimationTask based on
   * the ModelReference to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedAdjustableParameter object to retrieve.
   *
   * @return the first SedAdjustableParameter in this
   * SedParameterEstimationTask based on the given modelReference attribute or
   * NULL if no such SedAdjustableParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAdjustableParameter* getAdjustableParameterByModelReference(const
    std::string& sid);


  /**
   * Adds a copy of the given SedAdjustableParameter to this
   * SedParameterEstimationTask.
   *
   * @param sap the SedAdjustableParameter object to add.
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
   * @see createAdjustableParameter()
   * @see getAdjustableParameter(const std::string& sid)
   * @see getAdjustableParameter(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see removeAdjustableParameter(const std::string& sid)
   * @see removeAdjustableParameter(unsigned int n)
   */
  int addAdjustableParameter(const SedAdjustableParameter* sap);


  /**
   * Get the number of SedAdjustableParameter objects in this
   * SedParameterEstimationTask.
   *
   * @return the number of SedAdjustableParameter objects in this
   * SedParameterEstimationTask.
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see getAdjustableParameter(const std::string& sid)
   * @see getAdjustableParameter(unsigned int n)
   * @see removeAdjustableParameter(const std::string& sid)
   * @see removeAdjustableParameter(unsigned int n)
   */
  unsigned int getNumAdjustableParameters() const;


  /**
   * Creates a new SedAdjustableParameter object, adds it to this
   * SedParameterEstimationTask object and returns the SedAdjustableParameter
   * object created.
   *
   * @return a new SedAdjustableParameter object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see getAdjustableParameter(const std::string& sid)
   * @see getAdjustableParameter(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see removeAdjustableParameter(const std::string& sid)
   * @see removeAdjustableParameter(unsigned int n)
   */
  SedAdjustableParameter* createAdjustableParameter();


  /**
   * Removes the nth SedAdjustableParameter from this
   * SedParameterEstimationTask and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * SedAdjustableParameter to remove.
   *
   * @return a pointer to the nth SedAdjustableParameter in this
   * SedParameterEstimationTask.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see getAdjustableParameter(const std::string& sid)
   * @see getAdjustableParameter(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see removeAdjustableParameter(const std::string& sid)
   */
  SedAdjustableParameter* removeAdjustableParameter(unsigned int n);


  /**
   * Returns the SedListOfFitExperiments from this SedParameterEstimationTask.
   *
   * @return the SedListOfFitExperiments from this SedParameterEstimationTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(const std::string& sid)
   * @see getFitExperiment(unsigned int n)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  const SedListOfFitExperiments* getListOfFitExperiments() const;


  /**
   * Returns the SedListOfFitExperiments from this SedParameterEstimationTask.
   *
   * @return the SedListOfFitExperiments from this SedParameterEstimationTask.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(const std::string& sid)
   * @see getFitExperiment(unsigned int n)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  SedListOfFitExperiments* getListOfFitExperiments();


  /**
   * Get a SedFitExperiment from the SedParameterEstimationTask.
   *
   * @param n an unsigned int representing the index of the SedFitExperiment to
   * retrieve.
   *
   * @return the nth SedFitExperiment in the SedListOfFitExperiments within
   * this SedParameterEstimationTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(const std::string& sid)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  SedFitExperiment* getFitExperiment(unsigned int n);


  /**
   * Get a SedFitExperiment from the SedParameterEstimationTask.
   *
   * @param n an unsigned int representing the index of the SedFitExperiment to
   * retrieve.
   *
   * @return the nth SedFitExperiment in the SedListOfFitExperiments within
   * this SedParameterEstimationTask or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(const std::string& sid)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  const SedFitExperiment* getFitExperiment(unsigned int n) const;


  /**
   * Get a SedFitExperiment from the SedParameterEstimationTask based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedFitExperiment to
   * retrieve.
   *
   * @return the SedFitExperiment in the SedListOfFitExperiments within this
   * SedParameterEstimationTask with the given @p sid or @c NULL if no such
   * SedFitExperiment exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(unsigned int n)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  SedFitExperiment* getFitExperiment(const std::string& sid);


  /**
   * Get a SedFitExperiment from the SedParameterEstimationTask based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedFitExperiment to
   * retrieve.
   *
   * @return the SedFitExperiment in the SedListOfFitExperiments within this
   * SedParameterEstimationTask with the given @p sid or @c NULL if no such
   * SedFitExperiment exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(unsigned int n)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  const SedFitExperiment* getFitExperiment(const std::string& sid) const;


  /**
   * Adds a copy of the given SedFitExperiment to this
   * SedParameterEstimationTask.
   *
   * @param sfe the SedFitExperiment object to add.
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
   * @see createFitExperiment()
   * @see getFitExperiment(const std::string& sid)
   * @see getFitExperiment(unsigned int n)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  int addFitExperiment(const SedFitExperiment* sfe);


  /**
   * Get the number of SedFitExperiment objects in this
   * SedParameterEstimationTask.
   *
   * @return the number of SedFitExperiment objects in this
   * SedParameterEstimationTask.
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(const std::string& sid)
   * @see getFitExperiment(unsigned int n)
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  unsigned int getNumFitExperiments() const;


  /**
   * Creates a new SedFitExperiment object, adds it to this
   * SedParameterEstimationTask object and returns the SedFitExperiment object
   * created.
   *
   * @return a new SedFitExperiment object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see getFitExperiment(const std::string& sid)
   * @see getFitExperiment(unsigned int n)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   * @see removeFitExperiment(unsigned int n)
   */
  SedFitExperiment* createFitExperiment();


  /**
   * Removes the nth SedFitExperiment from this SedParameterEstimationTask and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedFitExperiment to
   * remove.
   *
   * @return a pointer to the nth SedFitExperiment in this
   * SedParameterEstimationTask.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(const std::string& sid)
   * @see getFitExperiment(unsigned int n)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(const std::string& sid)
   */
  SedFitExperiment* removeFitExperiment(unsigned int n);


  /**
   * Removes the SedFitExperiment from this SedParameterEstimationTask based on
   * its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedFitExperiment to
   * remove.
   *
   * @return the SedFitExperiment in this SedParameterEstimationTask based on
   * the identifier or NULL if no such SedFitExperiment exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see getFitExperiment(const std::string& sid)
   * @see getFitExperiment(unsigned int n)
   * @see getNumFitExperiments()
   * @see removeFitExperiment(unsigned int n)
   */
  SedFitExperiment* removeFitExperiment(const std::string& sid);


  /**
   * Returns the XML element name of this SedParameterEstimationTask object.
   *
   * For SedParameterEstimationTask, the XML element name is always
   * @c "parameterEstimationTask".
   *
   * @return the name of this element, i.e. @c "parameterEstimationTask".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedParameterEstimationTask object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_TASK_PARAMETER_ESTIMATION, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedParameterEstimationTask object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedParameterEstimationTask have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedParameterEstimationTask object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedParameterEstimationTask have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedParameterEstimationTask object are:
   * @li "algorithm"
   * @li "objective"
   * @li "adjustableParameter"
   * @li "fitExperiment"
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * Predicate returning @c true if this SedParameterEstimationTask's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedParameterEstimationTask's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedParameterEstimationTask.
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
   * SedParameterEstimationTask.
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
   * Returns the number of "elementName" in this SedParameterEstimationTask.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedParameterEstimationTask.
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
 * Creates a new SedParameterEstimationTask_t using the given SED-ML Level and @
 * p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedParameterEstimationTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedParameterEstimationTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t *
SedParameterEstimationTask_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedParameterEstimationTask_t object.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @return a (deep) copy of this SedParameterEstimationTask_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t*
SedParameterEstimationTask_clone(const SedParameterEstimationTask_t* spet);


/**
 * Frees this SedParameterEstimationTask_t object.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
void
SedParameterEstimationTask_free(SedParameterEstimationTask_t* spet);


/**
 * Returns the value of the "algorithm" element of this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure whose algorithm is
 * sought.
 *
 * @return the value of the "algorithm" element of this
 * SedParameterEstimationTask_t as a SedAlgorithm*.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedParameterEstimationTask_getAlgorithm(const SedParameterEstimationTask_t *
  spet);


/**
 * Returns the value of the "objective" element of this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure whose objective is
 * sought.
 *
 * @return the value of the "objective" element of this
 * SedParameterEstimationTask_t as a SedObjective*.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
const SedObjective_t*
SedParameterEstimationTask_getObjective(const SedParameterEstimationTask_t *
  spet);


/**
 * Predicate returning @c 1 (true) if this SedParameterEstimationTask_t's
 * "algorithm" element is set.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @return @c 1 (true) if this SedParameterEstimationTask_t's "algorithm"
 * element has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_isSetAlgorithm(const SedParameterEstimationTask_t *
  spet);


/**
 * Predicate returning @c 1 (true) if this SedParameterEstimationTask_t's
 * "objective" element is set.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @return @c 1 (true) if this SedParameterEstimationTask_t's "objective"
 * element has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_isSetObjective(const SedParameterEstimationTask_t *
  spet);


/**
 * Sets the value of the "algorithm" element of this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @param algorithm SedAlgorithm_t* value of the "algorithm" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_setAlgorithm(SedParameterEstimationTask_t * spet,
                                        const SedAlgorithm_t* algorithm);


/**
 * Sets the value of the "objective" element of this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @param objective SedObjective_t* value of the "objective" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_setObjective(SedParameterEstimationTask_t * spet,
                                        const SedObjective_t* objective);


/**
 * Creates a new SedAlgorithm_t object, adds it to this
 * SedParameterEstimationTask_t object and returns the SedAlgorithm_t object
 * created.
 *
 * @param spet the SedParameterEstimationTask_t structure to which the
 * SedAlgorithm_t should be added.
 *
 * @return a new SedAlgorithm_t object instance.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedParameterEstimationTask_createAlgorithm(SedParameterEstimationTask_t* spet);


/**
 * Creates a new SedLeastSquareObjectiveFunction_t object, adds it to this
 * SedParameterEstimationTask_t object and returns the
 * SedLeastSquareObjectiveFunction_t object created.
 *
 * @param spet the SedParameterEstimationTask_t structure to which the
 * SedLeastSquareObjectiveFunction_t should be added.
 *
 * @return a new SedLeastSquareObjectiveFunction_t object instance.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedLeastSquareObjectiveFunction_t*
SedParameterEstimationTask_createLeastSquareObjectiveFunction(SedParameterEstimationTask_t*
  spet);


/**
 * Unsets the value of the "algorithm" element of this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_unsetAlgorithm(SedParameterEstimationTask_t * spet);


/**
 * Unsets the value of the "objective" element of this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_unsetObjective(SedParameterEstimationTask_t * spet);


/**
 * Returns a ListOf_t * containing SedAdjustableParameter_t objects from this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure whose
 * SedListOfAdjustableParameters is sought.
 *
 * @return the SedListOfAdjustableParameters from this
 * SedParameterEstimationTask_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedParameterEstimationTask_addAdjustableParameter()
 * @see SedParameterEstimationTask_createAdjustableParameter()
 * @see SedParameterEstimationTask_getAdjustableParameterById()
 * @see SedParameterEstimationTask_getAdjustableParameter()
 * @see SedParameterEstimationTask_getNumAdjustableParameters()
 * @see SedParameterEstimationTask_removeAdjustableParameterById()
 * @see SedParameterEstimationTask_removeAdjustableParameter()
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedParameterEstimationTask_getListOfAdjustableParameters(SedParameterEstimationTask_t*
  spet);


/**
 * Get a SedAdjustableParameter_t from the SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAdjustableParameter_t to retrieve.
 *
 * @return the nth SedAdjustableParameter_t in the
 * @return the nth SedAdjustableParameter_t in the SedListOfAdjustableParameters within this SedParameterEstimationTask or
 * @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedParameterEstimationTask_getAdjustableParameter(
                                                  SedParameterEstimationTask_t*
                                                    spet,
                                                  unsigned int n);


/**
 * Get a SedAdjustableParameter_t from the SedParameterEstimationTask_t based
 * on the ModelReference to which it refers.
 *
 * @param spet the SedParameterEstimationTask_t structure to search.
 *
 * @param sid a string representing the "modelReference" attribute of the
 * SedAdjustableParameter_t object to retrieve.
 *
 * @return the first SedAdjustableParameter_t in this
 * SedParameterEstimationTask_t based on the given modelReference attribute or
 * NULL if no such SedAdjustableParameter_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedParameterEstimationTask_getAdjustableParameterByModelReference(
                                                                  SedParameterEstimationTask_t*
                                                                    spet,
                                                                  const char
                                                                    *sid);


/**
 * Adds a copy of the given SedAdjustableParameter_t to this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure to which the
 * SedAdjustableParameter_t should be added.
 *
 * @param sap the SedAdjustableParameter_t object to add.
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
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_addAdjustableParameter(
                                                  SedParameterEstimationTask_t*
                                                    spet,
                                                  const
                                                    SedAdjustableParameter_t*
                                                      sap);


/**
 * Get the number of SedAdjustableParameter_t objects in this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure to query.
 *
 * @return the number of SedAdjustableParameter_t objects in this
 * SedParameterEstimationTask_t.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
unsigned int
SedParameterEstimationTask_getNumAdjustableParameters(SedParameterEstimationTask_t*
  spet);


/**
 * Creates a new SedAdjustableParameter_t object, adds it to this
 * SedParameterEstimationTask_t object and returns the SedAdjustableParameter_t
 * object created.
 *
 * @param spet the SedParameterEstimationTask_t structure to which the
 * SedAdjustableParameter_t should be added.
 *
 * @return a new SedAdjustableParameter_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedParameterEstimationTask_createAdjustableParameter(SedParameterEstimationTask_t*
  spet);


/**
 * Removes the nth SedAdjustableParameter_t from this
 * SedParameterEstimationTask_t and returns a pointer to it.
 *
 * @param spet the SedParameterEstimationTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAdjustableParameter_t to remove.
 *
 * @return a pointer to the nth SedAdjustableParameter_t in this
 * SedParameterEstimationTask_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedParameterEstimationTask_removeAdjustableParameter(
                                                     SedParameterEstimationTask_t*
                                                       spet,
                                                     unsigned int n);


/**
 * Returns a ListOf_t * containing SedFitExperiment_t objects from this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure whose
 * SedListOfFitExperiments is sought.
 *
 * @return the SedListOfFitExperiments from this SedParameterEstimationTask_t
 * as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedParameterEstimationTask_addFitExperiment()
 * @see SedParameterEstimationTask_createFitExperiment()
 * @see SedParameterEstimationTask_getFitExperimentById()
 * @see SedParameterEstimationTask_getFitExperiment()
 * @see SedParameterEstimationTask_getNumFitExperiments()
 * @see SedParameterEstimationTask_removeFitExperimentById()
 * @see SedParameterEstimationTask_removeFitExperiment()
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedParameterEstimationTask_getListOfFitExperiments(SedParameterEstimationTask_t*
  spet);


/**
 * Get a SedFitExperiment_t from the SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedFitExperiment_t to
 * retrieve.
 *
 * @return the nth SedFitExperiment_t in the SedListOfFitExperiments within
 * this SedParameterEstimationTask or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_getFitExperiment(SedParameterEstimationTask_t* spet,
                                            unsigned int n);


/**
 * Get a SedFitExperiment_t from the SedParameterEstimationTask_t based on its
 * identifier.
 *
 * @param spet the SedParameterEstimationTask_t structure to search.
 *
 * @param sid a string representing the identifier of the SedFitExperiment_t to
 * retrieve.
 *
 * @return the SedFitExperiment_t in the SedListOfFitExperiments within this
 * SedParameterEstimationTask with the given @p sid or @c NULL if no such
 * SedFitExperiment_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_getFitExperimentById(
                                                SedParameterEstimationTask_t*
                                                  spet,
                                                const char *sid);


/**
 * Adds a copy of the given SedFitExperiment_t to this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure to which the
 * SedFitExperiment_t should be added.
 *
 * @param sfe the SedFitExperiment_t object to add.
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
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_addFitExperiment(SedParameterEstimationTask_t* spet,
                                            const SedFitExperiment_t* sfe);


/**
 * Get the number of SedFitExperiment_t objects in this
 * SedParameterEstimationTask_t.
 *
 * @param spet the SedParameterEstimationTask_t structure to query.
 *
 * @return the number of SedFitExperiment_t objects in this
 * SedParameterEstimationTask_t.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
unsigned int
SedParameterEstimationTask_getNumFitExperiments(SedParameterEstimationTask_t*
  spet);


/**
 * Creates a new SedFitExperiment_t object, adds it to this
 * SedParameterEstimationTask_t object and returns the SedFitExperiment_t
 * object created.
 *
 * @param spet the SedParameterEstimationTask_t structure to which the
 * SedFitExperiment_t should be added.
 *
 * @return a new SedFitExperiment_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_createFitExperiment(SedParameterEstimationTask_t*
  spet);


/**
 * Removes the nth SedFitExperiment_t from this SedParameterEstimationTask_t
 * and returns a pointer to it.
 *
 * @param spet the SedParameterEstimationTask_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedFitExperiment_t to
 * remove.
 *
 * @return a pointer to the nth SedFitExperiment_t in this
 * SedParameterEstimationTask_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_removeFitExperiment(
                                               SedParameterEstimationTask_t*
                                                 spet,
                                               unsigned int n);


/**
 * Removes the SedFitExperiment_t from this SedParameterEstimationTask_t based
 * on its identifier and returns a pointer to it.
 *
 * @param spet the SedParameterEstimationTask_t structure to search.
 *
 * @param sid a string representing the identifier of the SedFitExperiment_t to
 * remove.
 *
 * @return the SedFitExperiment_t in this SedParameterEstimationTask_t based on
 * the identifier or NULL if no such SedFitExperiment_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedParameterEstimationTask_removeFitExperimentById(
                                                   SedParameterEstimationTask_t*
                                                     spet,
                                                   const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedParameterEstimationTask_t object have been set.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedParameterEstimationTask_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_hasRequiredAttributes(const
  SedParameterEstimationTask_t * spet);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedParameterEstimationTask_t object have been set.
 *
 * @param spet the SedParameterEstimationTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedParameterEstimationTask_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 *
 * @note The required elements for the SedParameterEstimationTask_t object are:
 * @li "algorithm"
 * @li "objective"
 * @li "adjustableParameter"
 * @li "fitExperiment"
 *
 * @memberof SedParameterEstimationTask_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationTask_hasRequiredElements(const
  SedParameterEstimationTask_t * spet);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedParameterEstimationTask_H__ */


