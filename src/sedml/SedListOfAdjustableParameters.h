/**
 * @file SedListOfAdjustableParameters.h
 * @brief Definition of the SedListOfAdjustableParameters class.
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
 * @class SedListOfAdjustableParameters
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfAdjustableParameters
 * class.
 */


#ifndef SedListOfAdjustableParameters_H__
#define SedListOfAdjustableParameters_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedAdjustableParameter.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfAdjustableParameters : public SedListOf
{

public:

  /**
   * Creates a new SedListOfAdjustableParameters using the given SED-ML Level
   * and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfAdjustableParameters.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfAdjustableParameters.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfAdjustableParameters(unsigned int level = SEDML_DEFAULT_LEVEL,
                                unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfAdjustableParameters using the given SedNamespaces
   * object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfAdjustableParameters(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfAdjustableParameters.
   *
   * @param orig the SedListOfAdjustableParameters instance to copy.
   */
  SedListOfAdjustableParameters(const SedListOfAdjustableParameters& orig);


  /**
   * Assignment operator for SedListOfAdjustableParameters.
   *
   * @param rhs the SedListOfAdjustableParameters object whose values are to be
   * used as the basis of the assignment.
   */
  SedListOfAdjustableParameters& operator=(const SedListOfAdjustableParameters&
    rhs);


  /**
   * Creates and returns a deep copy of this SedListOfAdjustableParameters
   * object.
   *
   * @return a (deep) copy of this SedListOfAdjustableParameters object.
   */
  virtual SedListOfAdjustableParameters* clone() const;


  /**
   * Destructor for SedListOfAdjustableParameters.
   */
  virtual ~SedListOfAdjustableParameters();


  /**
   * Get a SedAdjustableParameter from the SedListOfAdjustableParameters.
   *
   * @param n an unsigned int representing the index of the
   * SedAdjustableParameter to retrieve.
   *
   * @return the nth SedAdjustableParameter in this
   * SedListOfAdjustableParameters or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see get(const std::string& sid)
   * @see getNumAdjustableParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAdjustableParameter* get(unsigned int n);


  /**
   * Get a SedAdjustableParameter from the SedListOfAdjustableParameters.
   *
   * @param n an unsigned int representing the index of the
   * SedAdjustableParameter to retrieve.
   *
   * @return the nth SedAdjustableParameter in this
   * SedListOfAdjustableParameters or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see get(const std::string& sid)
   * @see getNumAdjustableParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAdjustableParameter* get(unsigned int n) const;


  /**
   * Get a SedAdjustableParameter from the SedListOfAdjustableParameters based
   * on its identifier.
   *
   * @param sid a string representing the identifier of the
   * SedAdjustableParameter to retrieve.
   *
   * @return the SedAdjustableParameter in this SedListOfAdjustableParameters
   * with the given @p sid or @c NULL if no such SedAdjustableParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see get(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAdjustableParameter* get(const std::string& sid);


  /**
   * Get a SedAdjustableParameter from the SedListOfAdjustableParameters based
   * on its identifier.
   *
   * @param sid a string representing the identifier of the
   * SedAdjustableParameter to retrieve.
   *
   * @return the SedAdjustableParameter in this SedListOfAdjustableParameters
   * with the given @p sid or @c NULL if no such SedAdjustableParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see get(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAdjustableParameter* get(const std::string& sid) const;


  /**
   * Removes the nth SedAdjustableParameter from this
   * SedListOfAdjustableParameters and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * SedAdjustableParameter to remove.
   *
   * @return a pointer to the nth SedAdjustableParameter in this
   * SedListOfAdjustableParameters.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see remove(const std::string& sid)
   */
  virtual SedAdjustableParameter* remove(unsigned int n);


  /**
   * Removes the SedAdjustableParameter from this SedListOfAdjustableParameters
   * based on its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the
   * SedAdjustableParameter to remove.
   *
   * @return the SedAdjustableParameter in this SedListOfAdjustableParameters
   * based on the identifier or NULL if no such SedAdjustableParameter exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see remove(unsigned int n)
   */
  virtual SedAdjustableParameter* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedAdjustableParameter to this
   * SedListOfAdjustableParameters.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addAdjustableParameter(const SedAdjustableParameter* sap);


  /**
   * Get the number of SedAdjustableParameter objects in this
   * SedListOfAdjustableParameters.
   *
   * @return the number of SedAdjustableParameter objects in this
   * SedListOfAdjustableParameters.
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see createAdjustableParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumAdjustableParameters() const;


  /**
   * Creates a new SedAdjustableParameter object, adds it to this
   * SedListOfAdjustableParameters object and returns the
   * SedAdjustableParameter object created.
   *
   * @return a new SedAdjustableParameter object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAdjustableParameter(const SedAdjustableParameter* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAdjustableParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedAdjustableParameter* createAdjustableParameter();


  /**
   * Get a SedAdjustableParameter from the SedListOfAdjustableParameters based
   * on the ModelReference to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedAdjustableParameter object to retrieve.
   *
   * @return the first SedAdjustableParameter in this
   * SedListOfAdjustableParameters based on the given modelReference attribute
   * or NULL if no such SedAdjustableParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAdjustableParameter* getByModelReference(const std::string& sid)
    const;


  /**
   * Get a SedAdjustableParameter from the SedListOfAdjustableParameters based
   * on the ModelReference to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedAdjustableParameter object to retrieve.
   *
   * @return the first SedAdjustableParameter in this
   * SedListOfAdjustableParameters based on the given modelReference attribute
   * or NULL if no such SedAdjustableParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAdjustableParameter* getByModelReference(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfAdjustableParameters object.
   *
   * For SedListOfAdjustableParameters, the XML element name is always
   * @c "listOfAdjustableParameters".
   *
   * @return the name of this element, i.e. @c "listOfAdjustableParameters".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfAdjustableParameters
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
   * SedListOfAdjustableParameters object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfAdjustableParameters:
   * @sedmlconstant{SEDML_ADJUSTABLE_PARAMETER, SedTypeCode_t}.
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
   * Creates a new SedAdjustableParameter in this SedListOfAdjustableParameters
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
 * Get a SedAdjustableParameter_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAdjustableParameter_t to retrieve.
 *
 * @return the nth SedAdjustableParameter_t in this SedListOf_t or @c NULL if
 * no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfAdjustableParameters_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedListOfAdjustableParameters_getAdjustableParameter(SedListOf_t* slo,
                                                     unsigned int n);


/**
 * Get a SedAdjustableParameter_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * SedAdjustableParameter_t to retrieve.
 *
 * @return the SedAdjustableParameter_t in this SedListOf_t with the given @p
 * sid or @c NULL if no such SedAdjustableParameter_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfAdjustableParameters_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedListOfAdjustableParameters_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedAdjustableParameter_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAdjustableParameter_t to remove.
 *
 * @return a pointer to the nth SedAdjustableParameter_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfAdjustableParameters_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedListOfAdjustableParameters_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedAdjustableParameter_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * SedAdjustableParameter_t to remove.
 *
 * @return the SedAdjustableParameter_t in this SedListOf_t based on the
 * identifier or NULL if no such SedAdjustableParameter_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfAdjustableParameters_t
 */
LIBSEDML_EXTERN
SedAdjustableParameter_t*
SedListOfAdjustableParameters_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfAdjustableParameters_H__ */


