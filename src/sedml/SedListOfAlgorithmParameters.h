/**
 * @file SedListOfAlgorithmParameters.h
 * @brief Definition of the SedListOfAlgorithmParameters class.
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
 * @class SedListOfAlgorithmParameters
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfAlgorithmParameters class.
 */


#ifndef SedListOfAlgorithmParameters_H__
#define SedListOfAlgorithmParameters_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedAlgorithmParameter.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfAlgorithmParameters : public SedListOf
{

public:

  /**
   * Creates a new SedListOfAlgorithmParameters using the given SED-ML Level and
   * @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfAlgorithmParameters.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfAlgorithmParameters.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfAlgorithmParameters(unsigned int level = SEDML_DEFAULT_LEVEL,
                               unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfAlgorithmParameters using the given SedNamespaces
   * object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfAlgorithmParameters(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfAlgorithmParameters.
   *
   * @param orig the SedListOfAlgorithmParameters instance to copy.
   */
  SedListOfAlgorithmParameters(const SedListOfAlgorithmParameters& orig);


  /**
   * Assignment operator for SedListOfAlgorithmParameters.
   *
   * @param rhs the SedListOfAlgorithmParameters object whose values are to be
   * used as the basis of the assignment.
   */
  SedListOfAlgorithmParameters& operator=(const SedListOfAlgorithmParameters&
    rhs);


  /**
   * Creates and returns a deep copy of this SedListOfAlgorithmParameters
   * object.
   *
   * @return a (deep) copy of this SedListOfAlgorithmParameters object.
   */
  virtual SedListOfAlgorithmParameters* clone() const;


  /**
   * Destructor for SedListOfAlgorithmParameters.
   */
  virtual ~SedListOfAlgorithmParameters();


  /**
   * Get a SedAlgorithmParameter from the SedListOfAlgorithmParameters.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the nth SedAlgorithmParameter in this SedListOfAlgorithmParameters
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see get(const std::string& sid)
   * @see getNumAlgorithmParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAlgorithmParameter* get(unsigned int n);


  /**
   * Get a SedAlgorithmParameter from the SedListOfAlgorithmParameters.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the nth SedAlgorithmParameter in this SedListOfAlgorithmParameters
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see get(const std::string& sid)
   * @see getNumAlgorithmParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAlgorithmParameter* get(unsigned int n) const;


  /**
   * Get a SedAlgorithmParameter from the SedListOfAlgorithmParameters based on
   * its identifier.
   *
   * @param sid a string representing the identifier of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the SedAlgorithmParameter in this SedListOfAlgorithmParameters
   * with the given @p sid or @c NULL if no such SedAlgorithmParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see get(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAlgorithmParameter* get(const std::string& sid);


  /**
   * Get a SedAlgorithmParameter from the SedListOfAlgorithmParameters based on
   * its identifier.
   *
   * @param sid a string representing the identifier of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the SedAlgorithmParameter in this SedListOfAlgorithmParameters
   * with the given @p sid or @c NULL if no such SedAlgorithmParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see get(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAlgorithmParameter* get(const std::string& sid) const;


  /**
   * Removes the nth SedAlgorithmParameter from this
   * SedListOfAlgorithmParameters and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to remove.
   *
   * @return a pointer to the nth SedAlgorithmParameter in this
   * SedListOfAlgorithmParameters.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see remove(const std::string& sid)
   */
  virtual SedAlgorithmParameter* remove(unsigned int n);


  /**
   * Removes the SedAlgorithmParameter from this SedListOfAlgorithmParameters
   * based on its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the
   * SedAlgorithmParameter to remove.
   *
   * @return the SedAlgorithmParameter in this SedListOfAlgorithmParameters
   * based on the identifier or NULL if no such SedAlgorithmParameter exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see remove(unsigned int n)
   */
  virtual SedAlgorithmParameter* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedAlgorithmParameter to this
   * SedListOfAlgorithmParameters.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addAlgorithmParameter(const SedAlgorithmParameter* sap);


  /**
   * Get the number of SedAlgorithmParameter objects in this
   * SedListOfAlgorithmParameters.
   *
   * @return the number of SedAlgorithmParameter objects in this
   * SedListOfAlgorithmParameters.
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumAlgorithmParameters() const;


  /**
   * Creates a new SedAlgorithmParameter object, adds it to this
   * SedListOfAlgorithmParameters object and returns the SedAlgorithmParameter
   * object created.
   *
   * @return a new SedAlgorithmParameter object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedAlgorithmParameter* createAlgorithmParameter();


  /**
   * Returns the XML element name of this SedListOfAlgorithmParameters object.
   *
   * For SedListOfAlgorithmParameters, the XML element name is always
   * @c "listOfAlgorithmParameters".
   *
   * @return the name of this element, i.e. @c "listOfAlgorithmParameters".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfAlgorithmParameters
   * object.
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
   * SedListOfAlgorithmParameters object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfAlgorithmParameters:
   * @sedmlconstant{SEDML_SIMULATION_ALGORITHM_PARAMETER, SedTypeCode_t}.
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
   * Creates a new SedAlgorithmParameter in this SedListOfAlgorithmParameters
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
 * Get a SedAlgorithmParameter_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAlgorithmParameter_t to retrieve.
 *
 * @return the nth SedAlgorithmParameter_t in this SedListOf_t or @c NULL if no
 * such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfAlgorithmParameters_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedListOfAlgorithmParameters_getAlgorithmParameter(SedListOf_t* slo,
                                                   unsigned int n);


/**
 * Get a SedAlgorithmParameter_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * SedAlgorithmParameter_t to retrieve.
 *
 * @return the SedAlgorithmParameter_t in this SedListOf_t with the given @p
 * sid or @c NULL if no such SedAlgorithmParameter_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfAlgorithmParameters_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedListOfAlgorithmParameters_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedAlgorithmParameter_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAlgorithmParameter_t to remove.
 *
 * @return a pointer to the nth SedAlgorithmParameter_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfAlgorithmParameters_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedListOfAlgorithmParameters_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedAlgorithmParameter_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * SedAlgorithmParameter_t to remove.
 *
 * @return the SedAlgorithmParameter_t in this SedListOf_t based on the
 * identifier or NULL if no such SedAlgorithmParameter_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfAlgorithmParameters_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedListOfAlgorithmParameters_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfAlgorithmParameters_H__ */


