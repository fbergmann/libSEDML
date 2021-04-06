/**
 * @file SedListOfFitExperiments.h
 * @brief Definition of the SedListOfFitExperiments class.
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
 * @class SedListOfFitExperiments
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfFitExperiments class.
 */


#ifndef SedListOfFitExperiments_H__
#define SedListOfFitExperiments_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedFitExperiment.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfFitExperiments : public SedListOf
{

public:

  /**
   * Creates a new SedListOfFitExperiments using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfFitExperiments.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfFitExperiments.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfFitExperiments(unsigned int level = SEDML_DEFAULT_LEVEL,
                          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfFitExperiments using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfFitExperiments(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfFitExperiments.
   *
   * @param orig the SedListOfFitExperiments instance to copy.
   */
  SedListOfFitExperiments(const SedListOfFitExperiments& orig);


  /**
   * Assignment operator for SedListOfFitExperiments.
   *
   * @param rhs the SedListOfFitExperiments object whose values are to be used
   * as the basis of the assignment.
   */
  SedListOfFitExperiments& operator=(const SedListOfFitExperiments& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfFitExperiments object.
   *
   * @return a (deep) copy of this SedListOfFitExperiments object.
   */
  virtual SedListOfFitExperiments* clone() const;


  /**
   * Destructor for SedListOfFitExperiments.
   */
  virtual ~SedListOfFitExperiments();


  /**
   * Get a SedFitExperiment from the SedListOfFitExperiments.
   *
   * @param n an unsigned int representing the index of the SedFitExperiment to
   * retrieve.
   *
   * @return the nth SedFitExperiment in this SedListOfFitExperiments or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see get(const std::string& sid)
   * @see getNumFitExperiments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedFitExperiment* get(unsigned int n);


  /**
   * Get a SedFitExperiment from the SedListOfFitExperiments.
   *
   * @param n an unsigned int representing the index of the SedFitExperiment to
   * retrieve.
   *
   * @return the nth SedFitExperiment in this SedListOfFitExperiments or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see get(const std::string& sid)
   * @see getNumFitExperiments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedFitExperiment* get(unsigned int n) const;


  /**
   * Get a SedFitExperiment from the SedListOfFitExperiments based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedFitExperiment to
   * retrieve.
   *
   * @return the SedFitExperiment in this SedListOfFitExperiments with the
   * given @p sid or @c NULL if no such SedFitExperiment exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see get(unsigned int n)
   * @see getNumFitExperiments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedFitExperiment* get(const std::string& sid);


  /**
   * Get a SedFitExperiment from the SedListOfFitExperiments based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedFitExperiment to
   * retrieve.
   *
   * @return the SedFitExperiment in this SedListOfFitExperiments with the
   * given @p sid or @c NULL if no such SedFitExperiment exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see get(unsigned int n)
   * @see getNumFitExperiments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedFitExperiment* get(const std::string& sid) const;


  /**
   * Removes the nth SedFitExperiment from this SedListOfFitExperiments and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedFitExperiment to
   * remove.
   *
   * @return a pointer to the nth SedFitExperiment in this
   * SedListOfFitExperiments.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFitExperiments()
   * @see remove(const std::string& sid)
   */
  virtual SedFitExperiment* remove(unsigned int n);


  /**
   * Removes the SedFitExperiment from this SedListOfFitExperiments based on
   * its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedFitExperiment to
   * remove.
   *
   * @return the SedFitExperiment in this SedListOfFitExperiments based on the
   * identifier or NULL if no such SedFitExperiment exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFitExperiments()
   * @see remove(unsigned int n)
   */
  virtual SedFitExperiment* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedFitExperiment to this SedListOfFitExperiments.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFitExperiments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addFitExperiment(const SedFitExperiment* sfe);


  /**
   * Get the number of SedFitExperiment objects in this
   * SedListOfFitExperiments.
   *
   * @return the number of SedFitExperiment objects in this
   * SedListOfFitExperiments.
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see createFitExperiment()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumFitExperiments() const;


  /**
   * Creates a new SedFitExperiment object, adds it to this
   * SedListOfFitExperiments object and returns the SedFitExperiment object
   * created.
   *
   * @return a new SedFitExperiment object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitExperiment(const SedFitExperiment* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFitExperiments()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedFitExperiment* createFitExperiment();


  /**
   * Returns the XML element name of this SedListOfFitExperiments object.
   *
   * For SedListOfFitExperiments, the XML element name is always
   * @c "listOfFitExperiments".
   *
   * @return the name of this element, i.e. @c "listOfFitExperiments".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfFitExperiments object.
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
   * SedListOfFitExperiments object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfFitExperiments:
   * @sedmlconstant{SEDML_FIT_EXPERIMENT, SedTypeCode_t}.
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
   * Creates a new SedFitExperiment in this SedListOfFitExperiments
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedFitExperiment_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedFitExperiment_t to
 * retrieve.
 *
 * @return the nth SedFitExperiment_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfFitExperiments_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedListOfFitExperiments_getFitExperiment(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedFitExperiment_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedFitExperiment_t to
 * retrieve.
 *
 * @return the SedFitExperiment_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedFitExperiment_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfFitExperiments_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedListOfFitExperiments_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedFitExperiment_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedFitExperiment_t to
 * remove.
 *
 * @return a pointer to the nth SedFitExperiment_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfFitExperiments_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedListOfFitExperiments_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedFitExperiment_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedFitExperiment_t to
 * remove.
 *
 * @return the SedFitExperiment_t in this SedListOf_t based on the identifier
 * or NULL if no such SedFitExperiment_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfFitExperiments_t
 */
LIBSEDML_EXTERN
SedFitExperiment_t*
SedListOfFitExperiments_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfFitExperiments_H__ */


