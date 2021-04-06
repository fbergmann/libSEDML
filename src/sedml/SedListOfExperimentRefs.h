/**
 * @file SedListOfExperimentRefs.h
 * @brief Definition of the SedListOfExperimentRefs class.
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
 * @class SedListOfExperimentRefs
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfExperimentRefs class.
 */


#ifndef SedListOfExperimentRefs_H__
#define SedListOfExperimentRefs_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedExperimentRef.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfExperimentRefs : public SedListOf
{

public:

  /**
   * Creates a new SedListOfExperimentRefs using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfExperimentRefs.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfExperimentRefs.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfExperimentRefs(unsigned int level = SEDML_DEFAULT_LEVEL,
                          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfExperimentRefs using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfExperimentRefs(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfExperimentRefs.
   *
   * @param orig the SedListOfExperimentRefs instance to copy.
   */
  SedListOfExperimentRefs(const SedListOfExperimentRefs& orig);


  /**
   * Assignment operator for SedListOfExperimentRefs.
   *
   * @param rhs the SedListOfExperimentRefs object whose values are to be used
   * as the basis of the assignment.
   */
  SedListOfExperimentRefs& operator=(const SedListOfExperimentRefs& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfExperimentRefs object.
   *
   * @return a (deep) copy of this SedListOfExperimentRefs object.
   */
  virtual SedListOfExperimentRefs* clone() const;


  /**
   * Destructor for SedListOfExperimentRefs.
   */
  virtual ~SedListOfExperimentRefs();


  /**
   * Get a SedExperimentRef from the SedListOfExperimentRefs.
   *
   * @param n an unsigned int representing the index of the SedExperimentRef to
   * retrieve.
   *
   * @return the nth SedExperimentRef in this SedListOfExperimentRefs or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentRef(const SedExperimentRef* object)
   * @see createExperimentRef()
   * @see get(const std::string& sid)
   * @see getNumExperimentRefs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedExperimentRef* get(unsigned int n);


  /**
   * Get a SedExperimentRef from the SedListOfExperimentRefs.
   *
   * @param n an unsigned int representing the index of the SedExperimentRef to
   * retrieve.
   *
   * @return the nth SedExperimentRef in this SedListOfExperimentRefs or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentRef(const SedExperimentRef* object)
   * @see createExperimentRef()
   * @see get(const std::string& sid)
   * @see getNumExperimentRefs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedExperimentRef* get(unsigned int n) const;


  /**
   * Get a SedExperimentRef from the SedListOfExperimentRefs based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedExperimentRef to
   * retrieve.
   *
   * @return the SedExperimentRef in this SedListOfExperimentRefs with the
   * given @p sid or @c NULL if no such SedExperimentRef exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentRef(const SedExperimentRef* object)
   * @see createExperimentRef()
   * @see get(unsigned int n)
   * @see getNumExperimentRefs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedExperimentRef* get(const std::string& sid);


  /**
   * Get a SedExperimentRef from the SedListOfExperimentRefs based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedExperimentRef to
   * retrieve.
   *
   * @return the SedExperimentRef in this SedListOfExperimentRefs with the
   * given @p sid or @c NULL if no such SedExperimentRef exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentRef(const SedExperimentRef* object)
   * @see createExperimentRef()
   * @see get(unsigned int n)
   * @see getNumExperimentRefs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedExperimentRef* get(const std::string& sid) const;


  /**
   * Removes the nth SedExperimentRef from this SedListOfExperimentRefs and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedExperimentRef to
   * remove.
   *
   * @return a pointer to the nth SedExperimentRef in this
   * SedListOfExperimentRefs.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addExperimentRef(const SedExperimentRef* object)
   * @see createExperimentRef()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumExperimentRefs()
   * @see remove(const std::string& sid)
   */
  virtual SedExperimentRef* remove(unsigned int n);


  /**
   * Removes the SedExperimentRef from this SedListOfExperimentRefs based on
   * its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedExperimentRef to
   * remove.
   *
   * @return the SedExperimentRef in this SedListOfExperimentRefs based on the
   * identifier or NULL if no such SedExperimentRef exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addExperimentRef(const SedExperimentRef* object)
   * @see createExperimentRef()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumExperimentRefs()
   * @see remove(unsigned int n)
   */
  virtual SedExperimentRef* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedExperimentRef to this SedListOfExperimentRefs.
   *
   * @param ser the SedExperimentRef object to add.
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
   * @see createExperimentRef()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumExperimentRefs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addExperimentRef(const SedExperimentRef* ser);


  /**
   * Get the number of SedExperimentRef objects in this
   * SedListOfExperimentRefs.
   *
   * @return the number of SedExperimentRef objects in this
   * SedListOfExperimentRefs.
   *
   * @see addExperimentRef(const SedExperimentRef* object)
   * @see createExperimentRef()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumExperimentRefs() const;


  /**
   * Creates a new SedExperimentRef object, adds it to this
   * SedListOfExperimentRefs object and returns the SedExperimentRef object
   * created.
   *
   * @return a new SedExperimentRef object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExperimentRef(const SedExperimentRef* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumExperimentRefs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedExperimentRef* createExperimentRef();


  /**
   * Get a SedExperimentRef from the SedListOfExperimentRefs based on the
   * ExperimentId to which it refers.
   *
   * @param sid a string representing the "experimentId" attribute of the
   * SedExperimentRef object to retrieve.
   *
   * @return the first SedExperimentRef in this SedListOfExperimentRefs based
   * on the given experimentId attribute or NULL if no such SedExperimentRef
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedExperimentRef* getByExperimentId(const std::string& sid) const;


  /**
   * Get a SedExperimentRef from the SedListOfExperimentRefs based on the
   * ExperimentId to which it refers.
   *
   * @param sid a string representing the "experimentId" attribute of the
   * SedExperimentRef object to retrieve.
   *
   * @return the first SedExperimentRef in this SedListOfExperimentRefs based
   * on the given experimentId attribute or NULL if no such SedExperimentRef
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedExperimentRef* getByExperimentId(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfExperimentRefs object.
   *
   * For SedListOfExperimentRefs, the XML element name is always
   * @c "listOfExperimentRefs".
   *
   * @return the name of this element, i.e. @c "listOfExperimentRefs".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfExperimentRefs object.
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
   * SedListOfExperimentRefs object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfExperimentRefs:
   * @sedmlconstant{SEDML_EXPERIMENT_REF, SedTypeCode_t}.
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
   * Creates a new SedExperimentRef in this SedListOfExperimentRefs
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
 * Get a SedExperimentRef_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedExperimentRef_t to
 * retrieve.
 *
 * @return the nth SedExperimentRef_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfExperimentRefs_t
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedListOfExperimentRefs_getExperimentRef(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedExperimentRef_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedExperimentRef_t to
 * retrieve.
 *
 * @return the SedExperimentRef_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedExperimentRef_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfExperimentRefs_t
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedListOfExperimentRefs_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedExperimentRef_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedExperimentRef_t to
 * remove.
 *
 * @return a pointer to the nth SedExperimentRef_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfExperimentRefs_t
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedListOfExperimentRefs_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedExperimentRef_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedExperimentRef_t to
 * remove.
 *
 * @return the SedExperimentRef_t in this SedListOf_t based on the identifier
 * or NULL if no such SedExperimentRef_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfExperimentRefs_t
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedListOfExperimentRefs_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfExperimentRefs_H__ */


