/**
 * @file SedDocument.h
 * @brief Definition of the SedDocument class.
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
 * @class SedDocument
 * @sbmlbrief{sedml} TODO:Definition of the SedDocument class.
 */


#ifndef SedDocument_H__
#define SedDocument_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOfAlgorithmParameters.h>
#include <sedml/SedListOfDataDescriptions.h>
#include <sedml/SedListOfModels.h>
#include <sedml/SedListOfSimulations.h>
#include <sedml/SedListOfTasks.h>
#include <sedml/SedListOfDataGenerators.h>
#include <sedml/SedListOfOutputs.h>
#include <sedml/SedListOfStyles.h>
#include <sedml/SedErrorLog.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDocument : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  unsigned int mLevel;
  bool mIsSetLevel;
  unsigned int mVersion;
  bool mIsSetVersion;
  SedListOfAlgorithmParameters mAlgorithmParameters;
  SedListOfDataDescriptions mDataDescriptions;
  SedListOfModels mModels;
  SedListOfSimulations mSimulations;
  SedListOfTasks mAbstractTasks;
  SedListOfDataGenerators mDataGenerators;
  SedListOfOutputs mOutputs;
  SedListOfStyles mStyles;
  SedErrorLog mErrorLog;

  /** @endcond */

public:

  /**
   * Creates a new SedDocument using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedDocument.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedDocument.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDocument(unsigned int level = SEDML_DEFAULT_LEVEL,
              unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDocument using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDocument(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedDocument.
   *
   * @param orig the SedDocument instance to copy.
   */
  SedDocument(const SedDocument& orig);


  /**
   * Assignment operator for SedDocument.
   *
   * @param rhs the SedDocument object whose values are to be used as the basis
   * of the assignment.
   */
  SedDocument& operator=(const SedDocument& rhs);


  /**
   * Creates and returns a deep copy of this SedDocument object.
   *
   * @return a (deep) copy of this SedDocument object.
   */
  virtual SedDocument* clone() const;


  /**
   * Destructor for SedDocument.
   */
  virtual ~SedDocument();


  /**
   * Returns the value of the "level" attribute of this SedDocument.
   *
   * @return the value of the "level" attribute of this SedDocument as a
   * unsigned integer.
   */
  unsigned int getLevel() const;


  /**
   * Returns the value of the "version" attribute of this SedDocument.
   *
   * @return the value of the "version" attribute of this SedDocument as a
   * unsigned integer.
   */
  unsigned int getVersion() const;


  /**
   * Predicate returning @c true if this SedDocument's "level" attribute is
   * set.
   *
   * @return @c true if this SedDocument's "level" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLevel() const;


  /**
   * Predicate returning @c true if this SedDocument's "version" attribute is
   * set.
   *
   * @return @c true if this SedDocument's "version" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetVersion() const;


  /**
   * Sets the value of the "level" attribute of this SedDocument.
   *
   * @param level unsigned int value of the "level" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLevel(unsigned int level);


  /**
   * Sets the value of the "version" attribute of this SedDocument.
   *
   * @param version unsigned int value of the "version" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setVersion(unsigned int version);


  /**
   * Unsets the value of the "level" attribute of this SedDocument.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLevel();


  /**
   * Unsets the value of the "version" attribute of this SedDocument.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetVersion();


  /**
 * Returns the SedListOfAlgorithmParameters from this SedDocument.
 *
 * @return the SedListOfAlgorithmParameters from this SedDocument.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
 * @see createAlgorithmParameter()
 * @see getAlgorithmParameter(const std::string& sid)
 * @see getAlgorithmParameter(unsigned int n)
 * @see getNumAlgorithmParameters()
 * @see removeAlgorithmParameter(const std::string& sid)
 * @see removeAlgorithmParameter(unsigned int n)
 */
  const SedListOfAlgorithmParameters* getListOfAlgorithmParameters() const;


  /**
   * Returns the SedListOfAlgorithmParameters from this SedDocument.
   *
   * @return the SedListOfAlgorithmParameters from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  SedListOfAlgorithmParameters* getListOfAlgorithmParameters();


  /**
   * Get a SedAlgorithmParameter from the SedDocument.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the nth SedAlgorithmParameter in the SedListOfAlgorithmParameters
   * within this SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  SedAlgorithmParameter* getAlgorithmParameter(unsigned int n);


  /**
   * Get a SedAlgorithmParameter from the SedDocument.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the nth SedAlgorithmParameter in the SedListOfAlgorithmParameters
   * within this SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  const SedAlgorithmParameter* getAlgorithmParameter(unsigned int n) const;


  /**
   * Get a SedAlgorithmParameter from the SedDocument.
   *
   * @param id id of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the SedAlgorithmParameter in the SedListOfAlgorithmParameters
   * within this SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  SedAlgorithmParameter* getAlgorithmParameter(const std::string& id);


  /**
   * Get a SedAlgorithmParameter from the SedDocument.
   *
   * @param id id of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the SedAlgorithmParameter in the SedListOfAlgorithmParameters
   * within this SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  const SedAlgorithmParameter* getAlgorithmParameter(const std::string& id) const;


  /**
   * Adds a copy of the given SedAlgorithmParameter to this SedDocument.
   *
   * @param sap the SedAlgorithmParameter object to add.
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
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  int addAlgorithmParameter(const SedAlgorithmParameter* sap);


  /**
   * Get the number of SedAlgorithmParameter objects in this SedDocument.
   *
   * @return the number of SedAlgorithmParameter objects in this SedDocument.
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  unsigned int getNumAlgorithmParameters() const;


  /**
   * Creates a new SedAlgorithmParameter object, adds it to this SedDocument
   * object and returns the SedAlgorithmParameter object created.
   *
   * @return a new SedAlgorithmParameter object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  SedAlgorithmParameter* createAlgorithmParameter();


  /**
   * Removes the nth SedAlgorithmParameter from this SedDocument and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to remove.
   *
   * @return a pointer to the nth SedAlgorithmParameter in this SedDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   */
  SedAlgorithmParameter* removeAlgorithmParameter(unsigned int n);


  /**
   * Removes the SedAlgorithmParameter with the given id from this SedAlgorithm and returns a
   * pointer to it.
   *
   * @param id a string representing the id of the
   * SedAlgorithmParameter to remove.
   *
   * @return a pointer to the nth SedAlgorithmParameter in this SedAlgorithm.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   */
  SedAlgorithmParameter* removeAlgorithmParameter(const std::string& id);


  /**
   * Returns the SedListOfDataDescriptions from this SedDocument.
   *
   * @return the SedListOfDataDescriptions from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(const std::string& sid)
   * @see getDataDescription(unsigned int n)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  const SedListOfDataDescriptions* getListOfDataDescriptions() const;


  /**
   * Returns the SedListOfDataDescriptions from this SedDocument.
   *
   * @return the SedListOfDataDescriptions from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(const std::string& sid)
   * @see getDataDescription(unsigned int n)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  SedListOfDataDescriptions* getListOfDataDescriptions();


  /**
   * Get a SedDataDescription from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedDataDescription
   * to retrieve.
   *
   * @return the nth SedDataDescription in the SedListOfDataDescriptions within
   * this SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(const std::string& sid)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  SedDataDescription* getDataDescription(unsigned int n);


  /**
   * Get a SedDataDescription from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedDataDescription
   * to retrieve.
   *
   * @return the nth SedDataDescription in the SedListOfDataDescriptions within
   * this SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(const std::string& sid)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  const SedDataDescription* getDataDescription(unsigned int n) const;


  /**
   * Get a SedDataDescription from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataDescription
   * to retrieve.
   *
   * @return the SedDataDescription in the SedListOfDataDescriptions within
   * this SedDocument with the given @p sid or @c NULL if no such
   * SedDataDescription exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(unsigned int n)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  SedDataDescription* getDataDescription(const std::string& sid);


  /**
   * Get a SedDataDescription from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataDescription
   * to retrieve.
   *
   * @return the SedDataDescription in the SedListOfDataDescriptions within
   * this SedDocument with the given @p sid or @c NULL if no such
   * SedDataDescription exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(unsigned int n)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  const SedDataDescription* getDataDescription(const std::string& sid) const;


  /**
   * Adds a copy of the given SedDataDescription to this SedDocument.
   *
   * @param sdd the SedDataDescription object to add.
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
   * @see createDataDescription()
   * @see getDataDescription(const std::string& sid)
   * @see getDataDescription(unsigned int n)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  int addDataDescription(const SedDataDescription* sdd);


  /**
   * Get the number of SedDataDescription objects in this SedDocument.
   *
   * @return the number of SedDataDescription objects in this SedDocument.
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(const std::string& sid)
   * @see getDataDescription(unsigned int n)
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  unsigned int getNumDataDescriptions() const;


  /**
   * Creates a new SedDataDescription object, adds it to this SedDocument
   * object and returns the SedDataDescription object created.
   *
   * @return a new SedDataDescription object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see getDataDescription(const std::string& sid)
   * @see getDataDescription(unsigned int n)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   * @see removeDataDescription(unsigned int n)
   */
  SedDataDescription* createDataDescription();


  /**
   * Removes the nth SedDataDescription from this SedDocument and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedDataDescription
   * to remove.
   *
   * @return a pointer to the nth SedDataDescription in this SedDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(const std::string& sid)
   * @see getDataDescription(unsigned int n)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(const std::string& sid)
   */
  SedDataDescription* removeDataDescription(unsigned int n);


  /**
   * Removes the SedDataDescription from this SedDocument based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedDataDescription
   * to remove.
   *
   * @return the SedDataDescription in this SedDocument based on the identifier
   * or NULL if no such SedDataDescription exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see getDataDescription(const std::string& sid)
   * @see getDataDescription(unsigned int n)
   * @see getNumDataDescriptions()
   * @see removeDataDescription(unsigned int n)
   */
  SedDataDescription* removeDataDescription(const std::string& sid);


  /**
   * Returns the SedListOfModels from this SedDocument.
   *
   * @return the SedListOfModels from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(const std::string& sid)
   * @see getModel(unsigned int n)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  const SedListOfModels* getListOfModels() const;


  /**
   * Returns the SedListOfModels from this SedDocument.
   *
   * @return the SedListOfModels from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(const std::string& sid)
   * @see getModel(unsigned int n)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  SedListOfModels* getListOfModels();


  /**
   * Get a SedModel from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedModel to
   * retrieve.
   *
   * @return the nth SedModel in the SedListOfModels within this SedDocument or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(const std::string& sid)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  SedModel* getModel(unsigned int n);


  /**
   * Get a SedModel from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedModel to
   * retrieve.
   *
   * @return the nth SedModel in the SedListOfModels within this SedDocument or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(const std::string& sid)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  const SedModel* getModel(unsigned int n) const;


  /**
   * Get a SedModel from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedModel to
   * retrieve.
   *
   * @return the SedModel in the SedListOfModels within this SedDocument with
   * the given @p sid or @c NULL if no such SedModel exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(unsigned int n)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  SedModel* getModel(const std::string& sid);


  /**
   * Get a SedModel from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedModel to
   * retrieve.
   *
   * @return the SedModel in the SedListOfModels within this SedDocument with
   * the given @p sid or @c NULL if no such SedModel exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(unsigned int n)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  const SedModel* getModel(const std::string& sid) const;


  /**
   * Adds a copy of the given SedModel to this SedDocument.
   *
   * @param sm the SedModel object to add.
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
   * @see createModel()
   * @see getModel(const std::string& sid)
   * @see getModel(unsigned int n)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  int addModel(const SedModel* sm);


  /**
   * Get the number of SedModel objects in this SedDocument.
   *
   * @return the number of SedModel objects in this SedDocument.
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(const std::string& sid)
   * @see getModel(unsigned int n)
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  unsigned int getNumModels() const;


  /**
   * Creates a new SedModel object, adds it to this SedDocument object and
   * returns the SedModel object created.
   *
   * @return a new SedModel object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see getModel(const std::string& sid)
   * @see getModel(unsigned int n)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   * @see removeModel(unsigned int n)
   */
  SedModel* createModel();


  /**
   * Removes the nth SedModel from this SedDocument and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SedModel to remove.
   *
   * @return a pointer to the nth SedModel in this SedDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(const std::string& sid)
   * @see getModel(unsigned int n)
   * @see getNumModels()
   * @see removeModel(const std::string& sid)
   */
  SedModel* removeModel(unsigned int n);


  /**
   * Removes the SedModel from this SedDocument based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedModel to remove.
   *
   * @return the SedModel in this SedDocument based on the identifier or NULL
   * if no such SedModel exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addModel(const SedModel* object)
   * @see createModel()
   * @see getModel(const std::string& sid)
   * @see getModel(unsigned int n)
   * @see getNumModels()
   * @see removeModel(unsigned int n)
   */
  SedModel* removeModel(const std::string& sid);


  /**
   * Returns the SedListOfSimulations from this SedDocument.
   *
   * @return the SedListOfSimulations from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  const SedListOfSimulations* getListOfSimulations() const;


  /**
   * Returns the SedListOfSimulations from this SedDocument.
   *
   * @return the SedListOfSimulations from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  SedListOfSimulations* getListOfSimulations();


  /**
   * Get a SedSimulation from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedSimulation to
   * retrieve.
   *
   * @return the nth SedSimulation in the SedListOfSimulations within this
   * SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(const std::string& sid)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  SedSimulation* getSimulation(unsigned int n);


  /**
   * Get a SedSimulation from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedSimulation to
   * retrieve.
   *
   * @return the nth SedSimulation in the SedListOfSimulations within this
   * SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(const std::string& sid)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  const SedSimulation* getSimulation(unsigned int n) const;


  /**
   * Get a SedSimulation from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSimulation to
   * retrieve.
   *
   * @return the SedSimulation in the SedListOfSimulations within this
   * SedDocument with the given @p sid or @c NULL if no such SedSimulation
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  SedSimulation* getSimulation(const std::string& sid);


  /**
   * Get a SedSimulation from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSimulation to
   * retrieve.
   *
   * @return the SedSimulation in the SedListOfSimulations within this
   * SedDocument with the given @p sid or @c NULL if no such SedSimulation
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  const SedSimulation* getSimulation(const std::string& sid) const;


  /**
   * Adds a copy of the given SedSimulation to this SedDocument.
   *
   * @param ss the SedSimulation object to add.
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
   * @see createSimulation()
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  int addSimulation(const SedSimulation* ss);


  /**
   * Get the number of SedSimulation objects in this SedDocument.
   *
   * @return the number of SedSimulation objects in this SedDocument.
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  unsigned int getNumSimulations() const;


  /**
   * Creates a new SedUniformTimeCourse object, adds it to this SedDocument
   * object and returns the SedUniformTimeCourse object created.
   *
   * @return a new SedUniformTimeCourse object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  SedUniformTimeCourse* createUniformTimeCourse();


  /**
   * Creates a new SedOneStep object, adds it to this SedDocument object and
   * returns the SedOneStep object created.
   *
   * @return a new SedOneStep object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  SedOneStep* createOneStep();


  /**
   * Creates a new SedSteadyState object, adds it to this SedDocument object
   * and returns the SedSteadyState object created.
   *
   * @return a new SedSteadyState object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  SedSteadyState* createSteadyState();


  /**
   * Creates a new SedAnalysis object, adds it to this SedDocument object
   * and returns the SedAnalysis object created.
   *
   * @return a new SedAnalysis object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   * @see removeSimulation(unsigned int n)
   */
  SedAnalysis* createAnalysis();


  /**
   * Removes the nth SedSimulation from this SedDocument and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedSimulation to
   * remove.
   *
   * @return a pointer to the nth SedSimulation in this SedDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(const std::string& sid)
   */
  SedSimulation* removeSimulation(unsigned int n);


  /**
   * Removes the SedSimulation from this SedDocument based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedSimulation to
   * remove.
   *
   * @return the SedSimulation in this SedDocument based on the identifier or
   * NULL if no such SedSimulation exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see getSimulation(const std::string& sid)
   * @see getSimulation(unsigned int n)
   * @see getNumSimulations()
   * @see removeSimulation(unsigned int n)
   */
  SedSimulation* removeSimulation(const std::string& sid);


  /**
   * Returns the SedListOfTasks from this SedDocument.
   *
   * @return the SedListOfTasks from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  const SedListOfTasks* getListOfTasks() const;


  /**
   * Returns the SedListOfTasks from this SedDocument.
   *
   * @return the SedListOfTasks from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  SedListOfTasks* getListOfTasks();


  /**
   * Get a SedAbstractTask from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * retrieve.
   *
   * @return the nth SedAbstractTask in the SedListOfTasks within this
   * SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(const std::string& sid)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  SedAbstractTask* getTask(unsigned int n);


  /**
   * Get a SedAbstractTask from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * retrieve.
   *
   * @return the nth SedAbstractTask in the SedListOfTasks within this
   * SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(const std::string& sid)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  const SedAbstractTask* getTask(unsigned int n) const;


  /**
   * Get a SedAbstractTask from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * retrieve.
   *
   * @return the SedAbstractTask in the SedListOfTasks within this SedDocument
   * with the given @p sid or @c NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  SedAbstractTask* getTask(const std::string& sid);


  /**
   * Get a SedAbstractTask from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * retrieve.
   *
   * @return the SedAbstractTask in the SedListOfTasks within this SedDocument
   * with the given @p sid or @c NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  const SedAbstractTask* getTask(const std::string& sid) const;


  /**
   * Adds a copy of the given SedAbstractTask to this SedDocument.
   *
   * @param sat the SedAbstractTask object to add.
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
   * @see createTask()
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  int addTask(const SedAbstractTask* sat);


  /**
   * Get the number of SedAbstractTask objects in this SedDocument.
   *
   * @return the number of SedAbstractTask objects in this SedDocument.
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  unsigned int getNumTasks() const;


  /**
   * Creates a new SedTask object, adds it to this SedDocument object and
   * returns the SedTask object created.
   *
   * @return a new SedTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  SedTask* createTask();


  /**
   * Creates a new SedRepeatedTask object, adds it to this SedDocument object
   * and returns the SedRepeatedTask object created.
   *
   * @return a new SedRepeatedTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  SedRepeatedTask* createRepeatedTask();


  /**
   * Creates a new SedParameterEstimationTask object, adds it to this
   * SedDocument object and returns the SedParameterEstimationTask object
   * created.
   *
   * @return a new SedParameterEstimationTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   * @see removeTask(unsigned int n)
   */
  SedParameterEstimationTask* createParameterEstimationTask();


  /**
   * Removes the nth SedAbstractTask from this SedDocument and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * remove.
   *
   * @return a pointer to the nth SedAbstractTask in this SedDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(const std::string& sid)
   */
  SedAbstractTask* removeTask(unsigned int n);


  /**
   * Removes the SedAbstractTask from this SedDocument based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * remove.
   *
   * @return the SedAbstractTask in this SedDocument based on the identifier or
   * NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addTask(const SedAbstractTask* object)
   * @see createTask()
   * @see getTask(const std::string& sid)
   * @see getTask(unsigned int n)
   * @see getNumTasks()
   * @see removeTask(unsigned int n)
   */
  SedAbstractTask* removeTask(const std::string& sid);


  /**
   * Returns the SedListOfDataGenerators from this SedDocument.
   *
   * @return the SedListOfDataGenerators from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(const std::string& sid)
   * @see getDataGenerator(unsigned int n)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  const SedListOfDataGenerators* getListOfDataGenerators() const;


  /**
   * Returns the SedListOfDataGenerators from this SedDocument.
   *
   * @return the SedListOfDataGenerators from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(const std::string& sid)
   * @see getDataGenerator(unsigned int n)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  SedListOfDataGenerators* getListOfDataGenerators();


  /**
   * Get a SedDataGenerator from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedDataGenerator to
   * retrieve.
   *
   * @return the nth SedDataGenerator in the SedListOfDataGenerators within
   * this SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(const std::string& sid)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  SedDataGenerator* getDataGenerator(unsigned int n);


  /**
   * Get a SedDataGenerator from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedDataGenerator to
   * retrieve.
   *
   * @return the nth SedDataGenerator in the SedListOfDataGenerators within
   * this SedDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(const std::string& sid)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  const SedDataGenerator* getDataGenerator(unsigned int n) const;


  /**
   * Get a SedDataGenerator from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataGenerator to
   * retrieve.
   *
   * @return the SedDataGenerator in the SedListOfDataGenerators within this
   * SedDocument with the given @p sid or @c NULL if no such SedDataGenerator
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(unsigned int n)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  SedDataGenerator* getDataGenerator(const std::string& sid);


  /**
   * Get a SedDataGenerator from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataGenerator to
   * retrieve.
   *
   * @return the SedDataGenerator in the SedListOfDataGenerators within this
   * SedDocument with the given @p sid or @c NULL if no such SedDataGenerator
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(unsigned int n)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  const SedDataGenerator* getDataGenerator(const std::string& sid) const;


  /**
   * Adds a copy of the given SedDataGenerator to this SedDocument.
   *
   * @param sdg the SedDataGenerator object to add.
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
   * @see createDataGenerator()
   * @see getDataGenerator(const std::string& sid)
   * @see getDataGenerator(unsigned int n)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  int addDataGenerator(const SedDataGenerator* sdg);


  /**
   * Get the number of SedDataGenerator objects in this SedDocument.
   *
   * @return the number of SedDataGenerator objects in this SedDocument.
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(const std::string& sid)
   * @see getDataGenerator(unsigned int n)
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  unsigned int getNumDataGenerators() const;


  /**
   * Creates a new SedDataGenerator object, adds it to this SedDocument object
   * and returns the SedDataGenerator object created.
   *
   * @return a new SedDataGenerator object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see getDataGenerator(const std::string& sid)
   * @see getDataGenerator(unsigned int n)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   * @see removeDataGenerator(unsigned int n)
   */
  SedDataGenerator* createDataGenerator();


  /**
   * Removes the nth SedDataGenerator from this SedDocument and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedDataGenerator to
   * remove.
   *
   * @return a pointer to the nth SedDataGenerator in this SedDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(const std::string& sid)
   * @see getDataGenerator(unsigned int n)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(const std::string& sid)
   */
  SedDataGenerator* removeDataGenerator(unsigned int n);


  /**
   * Removes the SedDataGenerator from this SedDocument based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedDataGenerator to
   * remove.
   *
   * @return the SedDataGenerator in this SedDocument based on the identifier
   * or NULL if no such SedDataGenerator exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see getDataGenerator(const std::string& sid)
   * @see getDataGenerator(unsigned int n)
   * @see getNumDataGenerators()
   * @see removeDataGenerator(unsigned int n)
   */
  SedDataGenerator* removeDataGenerator(const std::string& sid);


  /**
   * Returns the SedListOfOutputs from this SedDocument.
   *
   * @return the SedListOfOutputs from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  const SedListOfOutputs* getListOfOutputs() const;


  /**
   * Returns the SedListOfOutputs from this SedDocument.
   *
   * @return the SedListOfOutputs from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  SedListOfOutputs* getListOfOutputs();


  /**
   * Get a SedOutput from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedOutput to
   * retrieve.
   *
   * @return the nth SedOutput in the SedListOfOutputs within this SedDocument
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(const std::string& sid)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  SedOutput* getOutput(unsigned int n);


  /**
   * Get a SedOutput from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedOutput to
   * retrieve.
   *
   * @return the nth SedOutput in the SedListOfOutputs within this SedDocument
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(const std::string& sid)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  const SedOutput* getOutput(unsigned int n) const;


  /**
   * Get a SedOutput from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedOutput to
   * retrieve.
   *
   * @return the SedOutput in the SedListOfOutputs within this SedDocument with
   * the given @p sid or @c NULL if no such SedOutput exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  SedOutput* getOutput(const std::string& sid);


  /**
   * Get a SedOutput from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedOutput to
   * retrieve.
   *
   * @return the SedOutput in the SedListOfOutputs within this SedDocument with
   * the given @p sid or @c NULL if no such SedOutput exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  const SedOutput* getOutput(const std::string& sid) const;


  /**
   * Adds a copy of the given SedOutput to this SedDocument.
   *
   * @param so the SedOutput object to add.
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
   * @see createOutput()
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  int addOutput(const SedOutput* so);


  /**
   * Get the number of SedOutput objects in this SedDocument.
   *
   * @return the number of SedOutput objects in this SedDocument.
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  unsigned int getNumOutputs() const;


  /**
   * Creates a new SedReport object, adds it to this SedDocument object and
   * returns the SedReport object created.
   *
   * @return a new SedReport object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  SedReport* createReport();


  /**
   * Creates a new SedPlot2D object, adds it to this SedDocument object and
   * returns the SedPlot2D object created.
   *
   * @return a new SedPlot2D object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  SedPlot2D* createPlot2D();


  /**
   * Creates a new SedPlot3D object, adds it to this SedDocument object and
   * returns the SedPlot3D object created.
   *
   * @return a new SedPlot3D object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  SedPlot3D* createPlot3D();


  /**
   * Creates a new SedFigure object, adds it to this SedDocument object and
   * returns the SedFigure object created.
   *
   * @return a new SedFigure object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  SedFigure* createFigure();


  /**
   * Creates a new SedParameterEstimationResultPlot object, adds it to this
   * SedDocument object and returns the SedParameterEstimationResultPlot object
   * created.
   *
   * @return a new SedParameterEstimationResultPlot object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   * @see removeOutput(unsigned int n)
   */
  SedParameterEstimationResultPlot* createParameterEstimationResultPlot();


  /**
   * Removes the nth SedOutput from this SedDocument and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SedOutput to
   * remove.
   *
   * @return a pointer to the nth SedOutput in this SedDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(const std::string& sid)
   */
  SedOutput* removeOutput(unsigned int n);


  /**
   * Removes the SedOutput from this SedDocument based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedOutput to
   * remove.
   *
   * @return the SedOutput in this SedDocument based on the identifier or NULL
   * if no such SedOutput exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see getOutput(const std::string& sid)
   * @see getOutput(unsigned int n)
   * @see getNumOutputs()
   * @see removeOutput(unsigned int n)
   */
  SedOutput* removeOutput(const std::string& sid);


  /**
   * Returns the SedListOfStyles from this SedDocument.
   *
   * @return the SedListOfStyles from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(const std::string& sid)
   * @see getStyle(unsigned int n)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  const SedListOfStyles* getListOfStyles() const;


  /**
   * Returns the SedListOfStyles from this SedDocument.
   *
   * @return the SedListOfStyles from this SedDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(const std::string& sid)
   * @see getStyle(unsigned int n)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  SedListOfStyles* getListOfStyles();


  /**
   * Get a SedStyle from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedStyle to
   * retrieve.
   *
   * @return the nth SedStyle in the SedListOfStyles within this SedDocument or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(const std::string& sid)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  SedStyle* getStyle(unsigned int n);


  /**
   * Get a SedStyle from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedStyle to
   * retrieve.
   *
   * @return the nth SedStyle in the SedListOfStyles within this SedDocument or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(const std::string& sid)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  const SedStyle* getStyle(unsigned int n) const;


  /**
   * Get a SedStyle from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedStyle to
   * retrieve.
   *
   * @return the SedStyle in the SedListOfStyles within this SedDocument with
   * the given @p sid or @c NULL if no such SedStyle exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(unsigned int n)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  SedStyle* getStyle(const std::string& sid);


  /**
   * Get a SedStyle from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedStyle to
   * retrieve.
   *
   * @return the SedStyle in the SedListOfStyles within this SedDocument with
   * the given @p sid or @c NULL if no such SedStyle exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(unsigned int n)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  const SedStyle* getStyle(const std::string& sid) const;

  /**
   * Get the effecive SedStyle from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedStyle to
   * retrieve.
   *
   * @return a new SedStyle based on the SedStyle in the 
   * SedListOfStyles, but changed so that any referenced styles
   * are applied.
   *
   */
  SedStyle getEffectiveStyle(const std::string& sid) const;


  /**
   * Get a SedStyle from the SedDocument based on the BaseStyle to which it
   * refers.
   *
   * @param sid a string representing the "baseStyle" attribute of the SedStyle
   * object to retrieve.
   *
   * @return the first SedStyle in this SedDocument based on the given
   * baseStyle attribute or NULL if no such SedStyle exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedStyle* getStyleByBaseStyle(const std::string& sid) const;


  /**
   * Get a SedStyle from the SedDocument based on the BaseStyle to which it
   * refers.
   *
   * @param sid a string representing the "baseStyle" attribute of the SedStyle
   * object to retrieve.
   *
   * @return the first SedStyle in this SedDocument based on the given
   * baseStyle attribute or NULL if no such SedStyle exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedStyle* getStyleByBaseStyle(const std::string& sid);


  /**
   * Adds a copy of the given SedStyle to this SedDocument.
   *
   * @param ss the SedStyle object to add.
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
   * @see createStyle()
   * @see getStyle(const std::string& sid)
   * @see getStyle(unsigned int n)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  int addStyle(const SedStyle* ss);


  /**
   * Get the number of SedStyle objects in this SedDocument.
   *
   * @return the number of SedStyle objects in this SedDocument.
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(const std::string& sid)
   * @see getStyle(unsigned int n)
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  unsigned int getNumStyles() const;


  /**
   * Creates a new SedStyle object, adds it to this SedDocument object and
   * returns the SedStyle object created.
   *
   * @return a new SedStyle object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see getStyle(const std::string& sid)
   * @see getStyle(unsigned int n)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   * @see removeStyle(unsigned int n)
   */
  SedStyle* createStyle();


  /**
   * Removes the nth SedStyle from this SedDocument and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SedStyle to remove.
   *
   * @return a pointer to the nth SedStyle in this SedDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(const std::string& sid)
   * @see getStyle(unsigned int n)
   * @see getNumStyles()
   * @see removeStyle(const std::string& sid)
   */
  SedStyle* removeStyle(unsigned int n);


  /**
   * Removes the SedStyle from this SedDocument based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedStyle to remove.
   *
   * @return the SedStyle in this SedDocument based on the identifier or NULL
   * if no such SedStyle exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see getStyle(const std::string& sid)
   * @see getStyle(unsigned int n)
   * @see getNumStyles()
   * @see removeStyle(unsigned int n)
   */
  SedStyle* removeStyle(const std::string& sid);


  /**
   * Returns the XML element name of this SedDocument object.
   *
   * For SedDocument, the XML element name is always @c "sedML".
   *
   * @return the name of this element, i.e. @c "sedML".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedDocument object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_DOCUMENT, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedDocument object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedDocument have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedDocument object are:
   * @li "level"
   * @li "version"
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
   * Gets the value of the "attributeName" attribute of this SedDocument.
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
   * Gets the value of the "attributeName" attribute of this SedDocument.
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
   * Gets the value of the "attributeName" attribute of this SedDocument.
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
   * Gets the value of the "attributeName" attribute of this SedDocument.
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
   * Gets the value of the "attributeName" attribute of this SedDocument.
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
   * Predicate returning @c true if this SedDocument's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedDocument's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDocument.
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
   * Sets the value of the "attributeName" attribute of this SedDocument.
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
   * Sets the value of the "attributeName" attribute of this SedDocument.
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
   * Sets the value of the "attributeName" attribute of this SedDocument.
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
   * Sets the value of the "attributeName" attribute of this SedDocument.
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
   * Unsets the value of the "attributeName" attribute of this SedDocument.
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
   * Creates and returns an new "elementName" object in this SedDocument.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedDocument.
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
   * SedDocument.
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
   * Returns the number of "elementName" in this SedDocument.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedDocument.
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
   * Returns the value of the "Namespaces" element of this SedDocument.
   *
   * @return the value of the "Namespaces" element of this SedDocument as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*.
   */
  virtual const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getNamespaces()
    const;


  /**
   * Returns the value of the "Namespaces" element of this SedDocument.
   *
   * @return the value of the "Namespaces" element of this SedDocument as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*.
   */
  virtual LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getNamespaces();


  /**
   * Returns the value of the "SedErrorLog" element of this SedDocument.
   *
   * @return the value of the "SedErrorLog" element of this SedDocument as a
   * SedErrorLog*.
   */
  const SedErrorLog* getErrorLog() const;


  /**
   * Returns the value of the "SedErrorLog" element of this SedDocument.
   *
   * @return the value of the "SedErrorLog" element of this SedDocument as a
   * SedErrorLog*.
   */
  SedErrorLog* getErrorLog();


  /**
   * Get a SedError from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedError to
   * retrieve.
   *
   * @return the nth SedError within this SedDocument or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see getNumErrors()
   */
  SedError* getError(unsigned int n);


  /**
   * Get a SedError from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedError to
   * retrieve.
   *
   * @return the nth SedError within this SedDocument or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see getNumErrors()
   */
  const SedError* getError(unsigned int n) const;


  /**
   * Get the number of SedError objects in this SedDocument.
   *
   * @return the number of SedError objects in this SedDocument.
   *
   * @see getError(unsigned int n)
   */
  unsigned int getNumErrors() const;


  /**
   * Get the number of SedError objects in this SedDocument with the given
   * severity.
   *
   * @param severity the severity of the SedError to return.
   *
   * @return the number of SedError objects in this SedDocument.
   *
   * @see getError(unsigned int n)
   */
  unsigned int getNumErrors(unsigned int severity) const;


  /**
  * Sort any SubTasks or Curves in the document according to
  * their 'order' attributes.
  */
  void sortOrderedObjects();

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



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the namespace for the Sedml package
   */
  virtual void writeXMLNS(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedDocument_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedDocument_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedDocument_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDocument_t *
SedDocument_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedDocument_t object.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return a (deep) copy of this SedDocument_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDocument_t*
SedDocument_clone(const SedDocument_t* sd);


/**
 * Frees this SedDocument_t object.
 *
 * @param sd the SedDocument_t structure.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
void
SedDocument_free(SedDocument_t* sd);


/**
 * Returns the value of the "level" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose level is sought.
 *
 * @return the value of the "level" attribute of this SedDocument_t as a
 * unsigned integer.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getLevel(const SedDocument_t * sd);


/**
 * Returns the value of the "version" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose version is sought.
 *
 * @return the value of the "version" attribute of this SedDocument_t as a
 * unsigned integer.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getVersion(const SedDocument_t * sd);


/**
 * Predicate returning @c 1 (true) if this SedDocument_t's "level" attribute is
 * set.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return @c 1 (true) if this SedDocument_t's "level" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_isSetLevel(const SedDocument_t * sd);


/**
 * Predicate returning @c 1 (true) if this SedDocument_t's "version" attribute
 * is set.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return @c 1 (true) if this SedDocument_t's "version" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_isSetVersion(const SedDocument_t * sd);


/**
 * Sets the value of the "level" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure.
 *
 * @param level unsigned int value of the "level" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_setLevel(SedDocument_t * sd, unsigned int level);


/**
 * Sets the value of the "version" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure.
 *
 * @param version unsigned int value of the "version" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_setVersion(SedDocument_t * sd, unsigned int version);


/**
 * Unsets the value of the "level" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_unsetLevel(SedDocument_t * sd);


/**
 * Unsets the value of the "version" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_unsetVersion(SedDocument_t * sd);


/**
 * Returns a ListOf_t * containing SedAlgorithmParameter_t objects from this
 * SedDocument_t.
 *
 * @param sa the SedDocument_t structure whose SedListOfAlgorithmParameters is
 * sought.
 *
 * @return the SedListOfAlgorithmParameters from this SedDocument_t as a
 * ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDocument_addAlgorithmParameter()
 * @see SedDocument_createAlgorithmParameter()
 * @see SedDocument_getAlgorithmParameterById()
 * @see SedDocument_getAlgorithmParameter()
 * @see SedDocument_getNumAlgorithmParameters()
 * @see SedDocument_removeAlgorithmParameterById()
 * @see SedDocument_removeAlgorithmParameter()
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfAlgorithmParameters(SedDocument_t* sa);


/**
 * Get a SedAlgorithmParameter_t from the SedDocument_t.
 *
 * @param sa the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAlgorithmParameter_t to retrieve.
 *
 * @return the nth SedAlgorithmParameter_t in the SedListOfAlgorithmParameters
 * within this SedDocument or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedDocument_getAlgorithmParameter(SedDocument_t* sa, unsigned int n);


/**
 * Adds a copy of the given SedAlgorithmParameter_t to this SedDocument_t.
 *
 * @param sa the SedDocument_t structure to which the SedAlgorithmParameter_t
 * should be added.
 *
 * @param sap the SedAlgorithmParameter_t object to add.
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
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addAlgorithmParameter(SedDocument_t* sa,
    const SedAlgorithmParameter_t* sap);


/**
 * Get the number of SedAlgorithmParameter_t objects in this SedDocument_t.
 *
 * @param sa the SedDocument_t structure to query.
 *
 * @return the number of SedAlgorithmParameter_t objects in this
 * SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumAlgorithmParameters(SedDocument_t* sa);


/**
 * Creates a new SedAlgorithmParameter_t object, adds it to this SedDocument_t
 * object and returns the SedAlgorithmParameter_t object created.
 *
 * @param sa the SedDocument_t structure to which the SedAlgorithmParameter_t
 * should be added.
 *
 * @return a new SedAlgorithmParameter_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedDocument_createAlgorithmParameter(SedDocument_t* sa);


/**
 * Removes the nth SedAlgorithmParameter_t from this SedDocument_t and returns
 * a pointer to it.
 *
 * @param sa the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAlgorithmParameter_t to remove.
 *
 * @return a pointer to the nth SedAlgorithmParameter_t in this SedDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedDocument_removeAlgorithmParameter(SedDocument_t* sa, unsigned int n);


/**
 * Returns a ListOf_t * containing SedDataDescription_t objects from this
 * SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose SedListOfDataDescriptions is
 * sought.
 *
 * @return the SedListOfDataDescriptions from this SedDocument_t as a ListOf_t
 * *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDocument_addDataDescription()
 * @see SedDocument_createDataDescription()
 * @see SedDocument_getDataDescriptionById()
 * @see SedDocument_getDataDescription()
 * @see SedDocument_getNumDataDescriptions()
 * @see SedDocument_removeDataDescriptionById()
 * @see SedDocument_removeDataDescription()
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfDataDescriptions(SedDocument_t* sd);


/**
 * Get a SedDataDescription_t from the SedDocument_t.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataDescription_t
 * to retrieve.
 *
 * @return the nth SedDataDescription_t in the SedListOfDataDescriptions within
 * this SedDocument or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_getDataDescription(SedDocument_t* sd, unsigned int n);


/**
 * Get a SedDataDescription_t from the SedDocument_t based on its identifier.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataDescription_t
 * to retrieve.
 *
 * @return the SedDataDescription_t in the SedListOfDataDescriptions within
 * this SedDocument with the given @p sid or @c NULL if no such
 * SedDataDescription_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_getDataDescriptionById(SedDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SedDataDescription_t to this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to which the SedDataDescription_t
 * should be added.
 *
 * @param sdd the SedDataDescription_t object to add.
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
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addDataDescription(SedDocument_t* sd,
                               const SedDataDescription_t* sdd);


/**
 * Get the number of SedDataDescription_t objects in this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to query.
 *
 * @return the number of SedDataDescription_t objects in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumDataDescriptions(SedDocument_t* sd);


/**
 * Creates a new SedDataDescription_t object, adds it to this SedDocument_t
 * object and returns the SedDataDescription_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedDataDescription_t
 * should be added.
 *
 * @return a new SedDataDescription_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_createDataDescription(SedDocument_t* sd);


/**
 * Removes the nth SedDataDescription_t from this SedDocument_t and returns a
 * pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataDescription_t
 * to remove.
 *
 * @return a pointer to the nth SedDataDescription_t in this SedDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_removeDataDescription(SedDocument_t* sd, unsigned int n);


/**
 * Removes the SedDataDescription_t from this SedDocument_t based on its
 * identifier and returns a pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataDescription_t
 * to remove.
 *
 * @return the SedDataDescription_t in this SedDocument_t based on the
 * identifier or NULL if no such SedDataDescription_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedDocument_removeDataDescriptionById(SedDocument_t* sd, const char* sid);


/**
 * Returns a ListOf_t * containing SedModel_t objects from this SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose SedListOfModels is sought.
 *
 * @return the SedListOfModels from this SedDocument_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDocument_addModel()
 * @see SedDocument_createModel()
 * @see SedDocument_getModelById()
 * @see SedDocument_getModel()
 * @see SedDocument_getNumModels()
 * @see SedDocument_removeModelById()
 * @see SedDocument_removeModel()
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfModels(SedDocument_t* sd);


/**
 * Get a SedModel_t from the SedDocument_t.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedModel_t to
 * retrieve.
 *
 * @return the nth SedModel_t in the SedListOfModels within this SedDocument or
 * @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_getModel(SedDocument_t* sd, unsigned int n);


/**
 * Get a SedModel_t from the SedDocument_t based on its identifier.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedModel_t to
 * retrieve.
 *
 * @return the SedModel_t in the SedListOfModels within this SedDocument with
 * the given @p sid or @c NULL if no such SedModel_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_getModelById(SedDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SedModel_t to this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to which the SedModel_t should be
 * added.
 *
 * @param sm the SedModel_t object to add.
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
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addModel(SedDocument_t* sd, const SedModel_t* sm);


/**
 * Get the number of SedModel_t objects in this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to query.
 *
 * @return the number of SedModel_t objects in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumModels(SedDocument_t* sd);


/**
 * Creates a new SedModel_t object, adds it to this SedDocument_t object and
 * returns the SedModel_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedModel_t should be
 * added.
 *
 * @return a new SedModel_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_createModel(SedDocument_t* sd);


/**
 * Removes the nth SedModel_t from this SedDocument_t and returns a pointer to
 * it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedModel_t to remove.
 *
 * @return a pointer to the nth SedModel_t in this SedDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_removeModel(SedDocument_t* sd, unsigned int n);


/**
 * Removes the SedModel_t from this SedDocument_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedModel_t to remove.
 *
 * @return the SedModel_t in this SedDocument_t based on the identifier or NULL
 * if no such SedModel_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_removeModelById(SedDocument_t* sd, const char* sid);


/**
 * Returns a ListOf_t * containing SedSimulation_t objects from this
 * SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose SedListOfSimulations is sought.
 *
 * @return the SedListOfSimulations from this SedDocument_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDocument_addSimulation()
 * @see SedDocument_createSimulation()
 * @see SedDocument_getSimulationById()
 * @see SedDocument_getSimulation()
 * @see SedDocument_getNumSimulations()
 * @see SedDocument_removeSimulationById()
 * @see SedDocument_removeSimulation()
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfSimulations(SedDocument_t* sd);


/**
 * Get a SedSimulation_t from the SedDocument_t.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSimulation_t to
 * retrieve.
 *
 * @return the nth SedSimulation_t in the SedListOfSimulations within this
 * SedDocument or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedDocument_getSimulation(SedDocument_t* sd, unsigned int n);


/**
 * Get a SedSimulation_t from the SedDocument_t based on its identifier.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSimulation_t to
 * retrieve.
 *
 * @return the SedSimulation_t in the SedListOfSimulations within this
 * SedDocument with the given @p sid or @c NULL if no such SedSimulation_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedDocument_getSimulationById(SedDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SedSimulation_t to this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to which the SedSimulation_t should be
 * added.
 *
 * @param ss the SedSimulation_t object to add.
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
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addSimulation(SedDocument_t* sd, const SedSimulation_t* ss);


/**
 * Get the number of SedSimulation_t objects in this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to query.
 *
 * @return the number of SedSimulation_t objects in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumSimulations(SedDocument_t* sd);


/**
 * Creates a new SedUniformTimeCourse_t object, adds it to this SedDocument_t
 * object and returns the SedUniformTimeCourse_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedUniformTimeCourse_t
 * should be added.
 *
 * @return a new SedUniformTimeCourse_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedUniformTimeCourse_t*
SedDocument_createUniformTimeCourse(SedDocument_t* sd);


/**
 * Creates a new SedOneStep_t object, adds it to this SedDocument_t object and
 * returns the SedOneStep_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedOneStep_t should be
 * added.
 *
 * @return a new SedOneStep_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedOneStep_t*
SedDocument_createOneStep(SedDocument_t* sd);


/**
 * Creates a new SedSteadyState_t object, adds it to this SedDocument_t object
 * and returns the SedSteadyState_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedSteadyState_t should
 * be added.
 *
 * @return a new SedSteadyState_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedSteadyState_t*
SedDocument_createSteadyState(SedDocument_t* sd);


/**
 * Creates a new SedAnalysis_t object, adds it to this SedDocument_t object
 * and returns the SedAnalysis_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedAnalysis_t should
 * be added.
 *
 * @return a new SedAnalysis_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedAnalysis_t*
SedDocument_createAnalysis(SedDocument_t* sd);


/**
 * Removes the nth SedSimulation_t from this SedDocument_t and returns a
 * pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSimulation_t to
 * remove.
 *
 * @return a pointer to the nth SedSimulation_t in this SedDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedDocument_removeSimulation(SedDocument_t* sd, unsigned int n);


/**
 * Removes the SedSimulation_t from this SedDocument_t based on its identifier
 * and returns a pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSimulation_t to
 * remove.
 *
 * @return the SedSimulation_t in this SedDocument_t based on the identifier or
 * NULL if no such SedSimulation_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedDocument_removeSimulationById(SedDocument_t* sd, const char* sid);


/**
 * Returns a ListOf_t * containing SedAbstractTask_t objects from this
 * SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose SedListOfTasks is sought.
 *
 * @return the SedListOfTasks from this SedDocument_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDocument_addTask()
 * @see SedDocument_createTask()
 * @see SedDocument_getTaskById()
 * @see SedDocument_getTask()
 * @see SedDocument_getNumTasks()
 * @see SedDocument_removeTaskById()
 * @see SedDocument_removeTask()
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfTasks(SedDocument_t* sd);


/**
 * Get a SedAbstractTask_t from the SedDocument_t.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractTask_t to
 * retrieve.
 *
 * @return the nth SedAbstractTask_t in the SedListOfTasks within this
 * SedDocument or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedDocument_getTask(SedDocument_t* sd, unsigned int n);


/**
 * Get a SedAbstractTask_t from the SedDocument_t based on its identifier.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractTask_t to
 * retrieve.
 *
 * @return the SedAbstractTask_t in the SedListOfTasks within this SedDocument
 * with the given @p sid or @c NULL if no such SedAbstractTask_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedDocument_getTaskById(SedDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SedAbstractTask_t to this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to which the SedAbstractTask_t should
 * be added.
 *
 * @param sat the SedAbstractTask_t object to add.
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
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addTask(SedDocument_t* sd, const SedAbstractTask_t* sat);


/**
 * Get the number of SedAbstractTask_t objects in this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to query.
 *
 * @return the number of SedAbstractTask_t objects in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumTasks(SedDocument_t* sd);


/**
 * Creates a new SedTask_t object, adds it to this SedDocument_t object and
 * returns the SedTask_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedTask_t should be
 * added.
 *
 * @return a new SedTask_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedTask_t*
SedDocument_createTask(SedDocument_t* sd);


/**
 * Creates a new SedRepeatedTask_t object, adds it to this SedDocument_t object
 * and returns the SedRepeatedTask_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedRepeatedTask_t should
 * be added.
 *
 * @return a new SedRepeatedTask_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedRepeatedTask_t*
SedDocument_createRepeatedTask(SedDocument_t* sd);


/**
 * Creates a new SedParameterEstimationTask_t object, adds it to this
 * SedDocument_t object and returns the SedParameterEstimationTask_t object
 * created.
 *
 * @param sd the SedDocument_t structure to which the
 * SedParameterEstimationTask_t should be added.
 *
 * @return a new SedParameterEstimationTask_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t*
SedDocument_createParameterEstimationTask(SedDocument_t* sd);


/**
 * Removes the nth SedAbstractTask_t from this SedDocument_t and returns a
 * pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractTask_t to
 * remove.
 *
 * @return a pointer to the nth SedAbstractTask_t in this SedDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedDocument_removeTask(SedDocument_t* sd, unsigned int n);


/**
 * Removes the SedAbstractTask_t from this SedDocument_t based on its
 * identifier and returns a pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractTask_t to
 * remove.
 *
 * @return the SedAbstractTask_t in this SedDocument_t based on the identifier
 * or NULL if no such SedAbstractTask_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedDocument_removeTaskById(SedDocument_t* sd, const char* sid);


/**
 * Returns a ListOf_t * containing SedDataGenerator_t objects from this
 * SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose SedListOfDataGenerators is
 * sought.
 *
 * @return the SedListOfDataGenerators from this SedDocument_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDocument_addDataGenerator()
 * @see SedDocument_createDataGenerator()
 * @see SedDocument_getDataGeneratorById()
 * @see SedDocument_getDataGenerator()
 * @see SedDocument_getNumDataGenerators()
 * @see SedDocument_removeDataGeneratorById()
 * @see SedDocument_removeDataGenerator()
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfDataGenerators(SedDocument_t* sd);


/**
 * Get a SedDataGenerator_t from the SedDocument_t.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataGenerator_t to
 * retrieve.
 *
 * @return the nth SedDataGenerator_t in the SedListOfDataGenerators within
 * this SedDocument or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_getDataGenerator(SedDocument_t* sd, unsigned int n);


/**
 * Get a SedDataGenerator_t from the SedDocument_t based on its identifier.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataGenerator_t to
 * retrieve.
 *
 * @return the SedDataGenerator_t in the SedListOfDataGenerators within this
 * SedDocument with the given @p sid or @c NULL if no such SedDataGenerator_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_getDataGeneratorById(SedDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SedDataGenerator_t to this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to which the SedDataGenerator_t should
 * be added.
 *
 * @param sdg the SedDataGenerator_t object to add.
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
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addDataGenerator(SedDocument_t* sd,
                             const SedDataGenerator_t* sdg);


/**
 * Get the number of SedDataGenerator_t objects in this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to query.
 *
 * @return the number of SedDataGenerator_t objects in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumDataGenerators(SedDocument_t* sd);


/**
 * Creates a new SedDataGenerator_t object, adds it to this SedDocument_t
 * object and returns the SedDataGenerator_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedDataGenerator_t should
 * be added.
 *
 * @return a new SedDataGenerator_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_createDataGenerator(SedDocument_t* sd);


/**
 * Removes the nth SedDataGenerator_t from this SedDocument_t and returns a
 * pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataGenerator_t to
 * remove.
 *
 * @return a pointer to the nth SedDataGenerator_t in this SedDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_removeDataGenerator(SedDocument_t* sd, unsigned int n);


/**
 * Removes the SedDataGenerator_t from this SedDocument_t based on its
 * identifier and returns a pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataGenerator_t to
 * remove.
 *
 * @return the SedDataGenerator_t in this SedDocument_t based on the identifier
 * or NULL if no such SedDataGenerator_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedDocument_removeDataGeneratorById(SedDocument_t* sd, const char* sid);


/**
 * Returns a ListOf_t * containing SedOutput_t objects from this SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose SedListOfOutputs is sought.
 *
 * @return the SedListOfOutputs from this SedDocument_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDocument_addOutput()
 * @see SedDocument_createOutput()
 * @see SedDocument_getOutputById()
 * @see SedDocument_getOutput()
 * @see SedDocument_getNumOutputs()
 * @see SedDocument_removeOutputById()
 * @see SedDocument_removeOutput()
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfOutputs(SedDocument_t* sd);


/**
 * Get a SedOutput_t from the SedDocument_t.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedOutput_t to
 * retrieve.
 *
 * @return the nth SedOutput_t in the SedListOfOutputs within this SedDocument
 * or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedDocument_getOutput(SedDocument_t* sd, unsigned int n);


/**
 * Get a SedOutput_t from the SedDocument_t based on its identifier.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedOutput_t to
 * retrieve.
 *
 * @return the SedOutput_t in the SedListOfOutputs within this SedDocument with
 * the given @p sid or @c NULL if no such SedOutput_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedDocument_getOutputById(SedDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SedOutput_t to this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to which the SedOutput_t should be
 * added.
 *
 * @param so the SedOutput_t object to add.
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
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addOutput(SedDocument_t* sd, const SedOutput_t* so);


/**
 * Get the number of SedOutput_t objects in this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to query.
 *
 * @return the number of SedOutput_t objects in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumOutputs(SedDocument_t* sd);


/**
 * Creates a new SedReport_t object, adds it to this SedDocument_t object and
 * returns the SedReport_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedReport_t should be
 * added.
 *
 * @return a new SedReport_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedReport_t*
SedDocument_createReport(SedDocument_t* sd);


/**
 * Creates a new SedPlot2D_t object, adds it to this SedDocument_t object and
 * returns the SedPlot2D_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedPlot2D_t should be
 * added.
 *
 * @return a new SedPlot2D_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedPlot2D_t*
SedDocument_createPlot2D(SedDocument_t* sd);


/**
 * Creates a new SedPlot3D_t object, adds it to this SedDocument_t object and
 * returns the SedPlot3D_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedPlot3D_t should be
 * added.
 *
 * @return a new SedPlot3D_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedPlot3D_t*
SedDocument_createPlot3D(SedDocument_t* sd);


/**
 * Creates a new SedFigure_t object, adds it to this SedDocument_t object and
 * returns the SedFigure_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedFigure_t should be
 * added.
 *
 * @return a new SedFigure_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedFigure_t*
SedDocument_createFigure(SedDocument_t* sd);


/**
 * Creates a new SedParameterEstimationResultPlot_t object, adds it to this
 * SedDocument_t object and returns the SedParameterEstimationResultPlot_t
 * object created.
 *
 * @param sd the SedDocument_t structure to which the
 * SedParameterEstimationResultPlot_t should be added.
 *
 * @return a new SedParameterEstimationResultPlot_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedParameterEstimationResultPlot_t*
SedDocument_createParameterEstimationResultPlot(SedDocument_t* sd);


/**
 * Removes the nth SedOutput_t from this SedDocument_t and returns a pointer to
 * it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedOutput_t to
 * remove.
 *
 * @return a pointer to the nth SedOutput_t in this SedDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedDocument_removeOutput(SedDocument_t* sd, unsigned int n);


/**
 * Removes the SedOutput_t from this SedDocument_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedOutput_t to
 * remove.
 *
 * @return the SedOutput_t in this SedDocument_t based on the identifier or
 * NULL if no such SedOutput_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedDocument_removeOutputById(SedDocument_t* sd, const char* sid);


/**
 * Returns a ListOf_t * containing SedStyle_t objects from this SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose SedListOfStyles is sought.
 *
 * @return the SedListOfStyles from this SedDocument_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedDocument_addStyle()
 * @see SedDocument_createStyle()
 * @see SedDocument_getStyleById()
 * @see SedDocument_getStyle()
 * @see SedDocument_getNumStyles()
 * @see SedDocument_removeStyleById()
 * @see SedDocument_removeStyle()
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfStyles(SedDocument_t* sd);


/**
 * Get a SedStyle_t from the SedDocument_t.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedStyle_t to
 * retrieve.
 *
 * @return the nth SedStyle_t in the SedListOfStyles within this SedDocument or
 * @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_getStyle(SedDocument_t* sd, unsigned int n);


/**
 * Get a SedStyle_t from the SedDocument_t based on its identifier.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedStyle_t to
 * retrieve.
 *
 * @return the SedStyle_t in the SedListOfStyles within this SedDocument with
 * the given @p sid or @c NULL if no such SedStyle_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_getStyleById(SedDocument_t* sd, const char *sid);


/**
 * Get a SedStyle_t from the SedDocument_t based on the BaseStyle to which it
 * refers.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the "baseStyle" attribute of the SedStyle_t
 * object to retrieve.
 *
 * @return the first SedStyle_t in this SedDocument_t based on the given
 * baseStyle attribute or NULL if no such SedStyle_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_getStyleByBaseStyle(SedDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SedStyle_t to this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to which the SedStyle_t should be
 * added.
 *
 * @param ss the SedStyle_t object to add.
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
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addStyle(SedDocument_t* sd, const SedStyle_t* ss);


/**
 * Get the number of SedStyle_t objects in this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to query.
 *
 * @return the number of SedStyle_t objects in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumStyles(SedDocument_t* sd);


/**
 * Creates a new SedStyle_t object, adds it to this SedDocument_t object and
 * returns the SedStyle_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedStyle_t should be
 * added.
 *
 * @return a new SedStyle_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_createStyle(SedDocument_t* sd);


/**
 * Removes the nth SedStyle_t from this SedDocument_t and returns a pointer to
 * it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedStyle_t to remove.
 *
 * @return a pointer to the nth SedStyle_t in this SedDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_removeStyle(SedDocument_t* sd, unsigned int n);


/**
 * Removes the SedStyle_t from this SedDocument_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedStyle_t to remove.
 *
 * @return the SedStyle_t in this SedDocument_t based on the identifier or NULL
 * if no such SedStyle_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedDocument_removeStyleById(SedDocument_t* sd, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDocument_t object have been set.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedDocument_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedDocument_t object are:
 * @li "level"
 * @li "version"
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_hasRequiredAttributes(const SedDocument_t * sd);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedDocument_H__ */


