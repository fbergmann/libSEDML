/**
 * @file SedListOfSimulations.h
 * @brief Definition of the SedListOfSimulations class.
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
 * @class SedListOfSimulations
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfSimulations class.
 */


#ifndef SedListOfSimulations_H__
#define SedListOfSimulations_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedSimulation.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedUniformTimeCourse;
class SedOneStep;
class SedSteadyState;
class SedAnalysis;

class LIBSEDML_EXTERN SedListOfSimulations : public SedListOf
{

public:

  /**
   * Creates a new SedListOfSimulations using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfSimulations.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfSimulations.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSimulations(unsigned int level = SEDML_DEFAULT_LEVEL,
                       unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfSimulations using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSimulations(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfSimulations.
   *
   * @param orig the SedListOfSimulations instance to copy.
   */
  SedListOfSimulations(const SedListOfSimulations& orig);


  /**
   * Assignment operator for SedListOfSimulations.
   *
   * @param rhs the SedListOfSimulations object whose values are to be used as
   * the basis of the assignment.
   */
  SedListOfSimulations& operator=(const SedListOfSimulations& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfSimulations object.
   *
   * @return a (deep) copy of this SedListOfSimulations object.
   */
  virtual SedListOfSimulations* clone() const;


  /**
   * Destructor for SedListOfSimulations.
   */
  virtual ~SedListOfSimulations();


  /**
   * Get a SedSimulation from the SedListOfSimulations.
   *
   * @param n an unsigned int representing the index of the SedSimulation to
   * retrieve.
   *
   * @return the nth SedSimulation in this SedListOfSimulations or @c NULL if
   * no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see get(const std::string& sid)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSimulation* get(unsigned int n);


  /**
   * Get a SedSimulation from the SedListOfSimulations.
   *
   * @param n an unsigned int representing the index of the SedSimulation to
   * retrieve.
   *
   * @return the nth SedSimulation in this SedListOfSimulations or @c NULL if
   * no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see get(const std::string& sid)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSimulation* get(unsigned int n) const;


  /**
   * Get a SedSimulation from the SedListOfSimulations based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSimulation to
   * retrieve.
   *
   * @return the SedSimulation in this SedListOfSimulations with the given @p
   * sid or @c NULL if no such SedSimulation exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSimulation* get(const std::string& sid);


  /**
   * Get a SedSimulation from the SedListOfSimulations based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSimulation to
   * retrieve.
   *
   * @return the SedSimulation in this SedListOfSimulations with the given @p
   * sid or @c NULL if no such SedSimulation exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSimulation* get(const std::string& sid) const;


  /**
   * Removes the nth SedSimulation from this SedListOfSimulations and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedSimulation to
   * remove.
   *
   * @return a pointer to the nth SedSimulation in this SedListOfSimulations.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   */
  virtual SedSimulation* remove(unsigned int n);


  /**
   * Removes the SedSimulation from this SedListOfSimulations based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedSimulation to
   * remove.
   *
   * @return the SedSimulation in this SedListOfSimulations based on the
   * identifier or NULL if no such SedSimulation exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(unsigned int n)
   */
  virtual SedSimulation* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedSimulation to this SedListOfSimulations.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addSimulation(const SedSimulation* ss);


  /**
   * Get the number of SedSimulation objects in this SedListOfSimulations.
   *
   * @return the number of SedSimulation objects in this SedListOfSimulations.
   *
   * @see addSimulation(const SedSimulation* object)
   * @see createSimulation()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumSimulations() const;


  /**
   * Creates a new SedUniformTimeCourse object, adds it to this
   * SedListOfSimulations object and returns the SedUniformTimeCourse object
   * created.
   *
   * @return a new SedUniformTimeCourse object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedUniformTimeCourse* createUniformTimeCourse();


  /**
   * Creates a new SedOneStep object, adds it to this SedListOfSimulations
   * object and returns the SedOneStep object created.
   *
   * @return a new SedOneStep object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedOneStep* createOneStep();


  /**
   * Creates a new SedSteadyState object, adds it to this SedListOfSimulations
   * object and returns the SedSteadyState object created.
   *
   * @return a new SedSteadyState object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedSteadyState* createSteadyState();


  /**
   * Creates a new SedAnalysis object, adds it to this SedListOfSimulations
   * object and returns the SedAnalysis object created.
   *
   * @return a new SedAnalysis object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSimulation(const SedSimulation* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSimulations()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedAnalysis* createAnalysis();


  /**
   * Returns the XML element name of this SedListOfSimulations object.
   *
   * For SedListOfSimulations, the XML element name is always
   * @c "listOfSimulations".
   *
   * @return the name of this element, i.e. @c "listOfSimulations".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfSimulations object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_LIST_OF, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSEDML type code for the SED-ML objects contained in this
   * SedListOfSimulations object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfSimulations:
   * @sedmlconstant{SEDML_SIMULATION, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new SedSimulation in this SedListOfSimulations
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * checks concrete types
   */
  virtual bool isValidTypeForList(SedBase* item);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedSimulation_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSimulation_t to
 * retrieve.
 *
 * @return the nth SedSimulation_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSimulations_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedListOfSimulations_getSimulation(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedSimulation_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSimulation_t to
 * retrieve.
 *
 * @return the SedSimulation_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedSimulation_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSimulations_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedListOfSimulations_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedSimulation_t from this SedListOf_t and returns a pointer
 * to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSimulation_t to
 * remove.
 *
 * @return a pointer to the nth SedSimulation_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSimulations_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedListOfSimulations_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedSimulation_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSimulation_t to
 * remove.
 *
 * @return the SedSimulation_t in this SedListOf_t based on the identifier or
 * NULL if no such SedSimulation_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSimulations_t
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedListOfSimulations_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfSimulations_H__ */


