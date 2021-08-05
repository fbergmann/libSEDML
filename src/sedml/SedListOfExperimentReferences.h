/**
 * @file SedListOfExperimentReferences.h
 * @brief Definition of the SedListOfExperimentReferences class.
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
 * @class SedListOfExperimentReferences
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfExperimentReferences class.
 */


#ifndef SedListOfExperimentReferences_H__
#define SedListOfExperimentReferences_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedExperimentReference.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfExperimentReferences : public SedListOf
{

public:

  /**
   * Creates a new SedListOfExperimentReferences using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfExperimentReferences.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfExperimentReferences.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfExperimentReferences(unsigned int level = SEDML_DEFAULT_LEVEL,
                          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfExperimentReferences using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfExperimentReferences(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfExperimentReferences.
   *
   * @param orig the SedListOfExperimentReferences instance to copy.
   */
  SedListOfExperimentReferences(const SedListOfExperimentReferences& orig);


  /**
   * Assignment operator for SedListOfExperimentReferences.
   *
   * @param rhs the SedListOfExperimentReferences object whose values are to be used
   * as the basis of the assignment.
   */
  SedListOfExperimentReferences& operator=(const SedListOfExperimentReferences& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfExperimentReferences object.
   *
   * @return a (deep) copy of this SedListOfExperimentReferences object.
   */
  virtual SedListOfExperimentReferences* clone() const;


  /**
   * Destructor for SedListOfExperimentReferences.
   */
  virtual ~SedListOfExperimentReferences();


  /**
   * Get a SedExperimentReference from the SedListOfExperimentReferences.
   *
   * @param n an unsigned int representing the index of the SedExperimentReference to
   * retrieve.
   *
   * @return the nth SedExperimentReference in this SedListOfExperimentReferences or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see get(const std::string& sid)
   * @see getNumExperimentReferences()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedExperimentReference* get(unsigned int n);


  /**
   * Get a SedExperimentReference from the SedListOfExperimentReferences.
   *
   * @param n an unsigned int representing the index of the SedExperimentReference to
   * retrieve.
   *
   * @return the nth SedExperimentReference in this SedListOfExperimentReferences or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see get(const std::string& sid)
   * @see getNumExperimentReferences()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedExperimentReference* get(unsigned int n) const;


  /**
   * Get a SedExperimentReference from the SedListOfExperimentReferences based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedExperimentReference to
   * retrieve.
   *
   * @return the SedExperimentReference in this SedListOfExperimentReferences with the
   * given @p sid or @c NULL if no such SedExperimentReference exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see get(unsigned int n)
   * @see getNumExperimentReferences()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedExperimentReference* get(const std::string& sid);


  /**
   * Get a SedExperimentReference from the SedListOfExperimentReferences based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedExperimentReference to
   * retrieve.
   *
   * @return the SedExperimentReference in this SedListOfExperimentReferences with the
   * given @p sid or @c NULL if no such SedExperimentReference exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see get(unsigned int n)
   * @see getNumExperimentReferences()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedExperimentReference* get(const std::string& sid) const;


  /**
   * Removes the nth SedExperimentReference from this SedListOfExperimentReferences and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedExperimentReference to
   * remove.
   *
   * @return a pointer to the nth SedExperimentReference in this
   * SedListOfExperimentReferences.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumExperimentReferences()
   * @see remove(const std::string& sid)
   */
  virtual SedExperimentReference* remove(unsigned int n);


  /**
   * Removes the SedExperimentReference from this SedListOfExperimentReferences based on
   * its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedExperimentReference to
   * remove.
   *
   * @return the SedExperimentReference in this SedListOfExperimentReferences based on the
   * identifier or NULL if no such SedExperimentReference exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumExperimentReferences()
   * @see remove(unsigned int n)
   */
  virtual SedExperimentReference* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedExperimentReference to this SedListOfExperimentReferences.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumExperimentReferences()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addExperimentReference(const SedExperimentReference* ser);


  /**
   * Get the number of SedExperimentReference objects in this
   * SedListOfExperimentReferences.
   *
   * @return the number of SedExperimentReference objects in this
   * SedListOfExperimentReferences.
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see createExperimentReference()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumExperimentReferences() const;


  /**
   * Creates a new SedExperimentReference object, adds it to this
   * SedListOfExperimentReferences object and returns the SedExperimentReference object
   * created.
   *
   * @return a new SedExperimentReference object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentReference(const SedExperimentReference* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumExperimentReferences()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedExperimentReference* createExperimentReference();


  /**
   * Get a SedExperimentReference from the SedListOfExperimentReferences based on the
   * ExperimentId to which it refers.
   *
   * @param sid a string representing the "experimentId" attribute of the
   * SedExperimentReference object to retrieve.
   *
   * @return the first SedExperimentReference in this SedListOfExperimentReferences based
   * on the given experimentId attribute or NULL if no such SedExperimentReference
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedExperimentReference* getByExperimentId(const std::string& sid) const;


  /**
   * Get a SedExperimentReference from the SedListOfExperimentReferences based on the
   * ExperimentId to which it refers.
   *
   * @param sid a string representing the "experimentId" attribute of the
   * SedExperimentReference object to retrieve.
   *
   * @return the first SedExperimentReference in this SedListOfExperimentReferences based
   * on the given experimentId attribute or NULL if no such SedExperimentReference
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedExperimentReference* getByExperimentId(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfExperimentReferences object.
   *
   * For SedListOfExperimentReferences, the XML element name is always
   * @c "listOfExperimentReferences".
   *
   * @return the name of this element, i.e. @c "listOfExperimentReferences".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfExperimentReferences object.
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
   * SedListOfExperimentReferences object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfExperimentReferences:
   * @sedmlconstant{SEDML_EXPERIMENT_REFERENCE, SedTypeCode_t}.
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
   * Creates a new SedExperimentReference in this SedListOfExperimentReferences
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
 * Get a SedExperimentReference_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedExperimentReference_t to
 * retrieve.
 *
 * @return the nth SedExperimentReference_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfExperimentReferences_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedListOfExperimentReferences_getExperimentReference(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedExperimentReference_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedExperimentReference_t to
 * retrieve.
 *
 * @return the SedExperimentReference_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedExperimentReference_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfExperimentReferences_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedListOfExperimentReferences_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedExperimentReference_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedExperimentReference_t to
 * remove.
 *
 * @return a pointer to the nth SedExperimentReference_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfExperimentReferences_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedListOfExperimentReferences_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedExperimentReference_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedExperimentReference_t to
 * remove.
 *
 * @return the SedExperimentReference_t in this SedListOf_t based on the identifier
 * or NULL if no such SedExperimentReference_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfExperimentReferences_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedListOfExperimentReferences_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfExperimentReferences_H__ */


