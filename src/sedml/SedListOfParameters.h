/**
 * @file SedListOfParameters.h
 * @brief Definition of the SedListOfParameters class.
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
 * @class SedListOfParameters
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfParameters class.
 */


#ifndef SedListOfParameters_H__
#define SedListOfParameters_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedParameter.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfParameters : public SedListOf
{

public:

  /**
   * Creates a new SedListOfParameters using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfParameters.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfParameters.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfParameters(unsigned int level = SEDML_DEFAULT_LEVEL,
                      unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfParameters using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfParameters(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfParameters.
   *
   * @param orig the SedListOfParameters instance to copy.
   */
  SedListOfParameters(const SedListOfParameters& orig);


  /**
   * Assignment operator for SedListOfParameters.
   *
   * @param rhs the SedListOfParameters object whose values are to be used as
   * the basis of the assignment.
   */
  SedListOfParameters& operator=(const SedListOfParameters& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfParameters object.
   *
   * @return a (deep) copy of this SedListOfParameters object.
   */
  virtual SedListOfParameters* clone() const;


  /**
   * Destructor for SedListOfParameters.
   */
  virtual ~SedListOfParameters();


  /**
   * Get a SedParameter from the SedListOfParameters.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in this SedListOfParameters or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see get(const std::string& sid)
   * @see getNumParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedParameter* get(unsigned int n);


  /**
   * Get a SedParameter from the SedListOfParameters.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * retrieve.
   *
   * @return the nth SedParameter in this SedListOfParameters or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see get(const std::string& sid)
   * @see getNumParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedParameter* get(unsigned int n) const;


  /**
   * Get a SedParameter from the SedListOfParameters based on its identifier.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * retrieve.
   *
   * @return the SedParameter in this SedListOfParameters with the given @p sid
   * or @c NULL if no such SedParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see get(unsigned int n)
   * @see getNumParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedParameter* get(const std::string& sid);


  /**
   * Get a SedParameter from the SedListOfParameters based on its identifier.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * retrieve.
   *
   * @return the SedParameter in this SedListOfParameters with the given @p sid
   * or @c NULL if no such SedParameter exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see get(unsigned int n)
   * @see getNumParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedParameter* get(const std::string& sid) const;


  /**
   * Removes the nth SedParameter from this SedListOfParameters and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedParameter to
   * remove.
   *
   * @return a pointer to the nth SedParameter in this SedListOfParameters.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumParameters()
   * @see remove(const std::string& sid)
   */
  virtual SedParameter* remove(unsigned int n);


  /**
   * Removes the SedParameter from this SedListOfParameters based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedParameter to
   * remove.
   *
   * @return the SedParameter in this SedListOfParameters based on the
   * identifier or NULL if no such SedParameter exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumParameters()
   * @see remove(unsigned int n)
   */
  virtual SedParameter* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedParameter to this SedListOfParameters.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addParameter(const SedParameter* sp);


  /**
   * Get the number of SedParameter objects in this SedListOfParameters.
   *
   * @return the number of SedParameter objects in this SedListOfParameters.
   *
   * @see addParameter(const SedParameter* object)
   * @see createParameter()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumParameters() const;


  /**
   * Creates a new SedParameter object, adds it to this SedListOfParameters
   * object and returns the SedParameter object created.
   *
   * @return a new SedParameter object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addParameter(const SedParameter* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumParameters()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedParameter* createParameter();


  /**
   * Returns the XML element name of this SedListOfParameters object.
   *
   * For SedListOfParameters, the XML element name is always
   * @c "listOfParameters".
   *
   * @return the name of this element, i.e. @c "listOfParameters".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfParameters object.
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
   * SedListOfParameters object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfParameters:
   * @sedmlconstant{SEDML_PARAMETER, SedTypeCode_t}.
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
   * Creates a new SedParameter in this SedListOfParameters
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
 * Get a SedParameter_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * retrieve.
 *
 * @return the nth SedParameter_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfParameters_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedListOfParameters_getParameter(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedParameter_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedParameter_t to
 * retrieve.
 *
 * @return the SedParameter_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedParameter_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfParameters_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedListOfParameters_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedParameter_t from this SedListOf_t and returns a pointer
 * to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedParameter_t to
 * remove.
 *
 * @return a pointer to the nth SedParameter_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfParameters_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedListOfParameters_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedParameter_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedParameter_t to
 * remove.
 *
 * @return the SedParameter_t in this SedListOf_t based on the identifier or
 * NULL if no such SedParameter_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfParameters_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedListOfParameters_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfParameters_H__ */


