/**
 * @file SedListOfAppliedDimensions.h
 * @brief Definition of the SedListOfAppliedDimensions class.
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
 * @class SedListOfAppliedDimensions
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfAppliedDimensions class.
 */


#ifndef SedListOfAppliedDimensions_H__
#define SedListOfAppliedDimensions_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedAppliedDimension.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfAppliedDimensions : public SedListOf
{

public:

  /**
   * Creates a new SedListOfAppliedDimensions using the given SED-ML Level and
   * @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfAppliedDimensions.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfAppliedDimensions.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfAppliedDimensions(unsigned int level = SEDML_DEFAULT_LEVEL,
                               unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfAppliedDimensions using the given SedNamespaces
   * object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfAppliedDimensions(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfAppliedDimensions.
   *
   * @param orig the SedListOfAppliedDimensions instance to copy.
   */
  SedListOfAppliedDimensions(const SedListOfAppliedDimensions& orig);


  /**
   * Assignment operator for SedListOfAppliedDimensions.
   *
   * @param rhs the SedListOfAppliedDimensions object whose values are to be
   * used as the basis of the assignment.
   */
  SedListOfAppliedDimensions& operator=(const SedListOfAppliedDimensions&
    rhs);


  /**
   * Creates and returns a deep copy of this SedListOfAppliedDimensions
   * object.
   *
   * @return a (deep) copy of this SedListOfAppliedDimensions object.
   */
  virtual SedListOfAppliedDimensions* clone() const;


  /**
   * Destructor for SedListOfAppliedDimensions.
   */
  virtual ~SedListOfAppliedDimensions();


  /**
   * Get a SedAppliedDimension from the SedListOfAppliedDimensions.
   *
   * @param n an unsigned int representing the index of the
   * SedAppliedDimension to retrieve.
   *
   * @return the nth SedAppliedDimension in this SedListOfAppliedDimensions
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see get(const std::string& sid)
   * @see getNumAppliedDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAppliedDimension* get(unsigned int n);


  /**
   * Get a SedAppliedDimension from the SedListOfAppliedDimensions.
   *
   * @param n an unsigned int representing the index of the
   * SedAppliedDimension to retrieve.
   *
   * @return the nth SedAppliedDimension in this SedListOfAppliedDimensions
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see get(const std::string& sid)
   * @see getNumAppliedDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAppliedDimension* get(unsigned int n) const;


  /**
   * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
   * its identifier.
   *
   * @param sid a string representing the identifier of the
   * SedAppliedDimension to retrieve.
   *
   * @return the SedAppliedDimension in this SedListOfAppliedDimensions
   * with the given @p sid or @c NULL if no such SedAppliedDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see get(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAppliedDimension* get(const std::string& sid);


  /**
   * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
   * its identifier.
   *
   * @param sid a string representing the identifier of the
   * SedAppliedDimension to retrieve.
   *
   * @return the SedAppliedDimension in this SedListOfAppliedDimensions
   * with the given @p sid or @c NULL if no such SedAppliedDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see get(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAppliedDimension* get(const std::string& sid) const;


  /**
   * Removes the nth SedAppliedDimension from this
   * SedListOfAppliedDimensions and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * SedAppliedDimension to remove.
   *
   * @return a pointer to the nth SedAppliedDimension in this
   * SedListOfAppliedDimensions.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see remove(const std::string& sid)
   */
  virtual SedAppliedDimension* remove(unsigned int n);


  /**
   * Removes the SedAppliedDimension from this SedListOfAppliedDimensions
   * based on its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the
   * SedAppliedDimension to remove.
   *
   * @return the SedAppliedDimension in this SedListOfAppliedDimensions
   * based on the identifier or NULL if no such SedAppliedDimension exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see remove(unsigned int n)
   */
  virtual SedAppliedDimension* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedAppliedDimension to this
   * SedListOfAppliedDimensions.
   *
   * @param srd the SedAppliedDimension object to add.
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
   * @see createAppliedDimension()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addAppliedDimension(const SedAppliedDimension* srd);


  /**
   * Get the number of SedAppliedDimension objects in this
   * SedListOfAppliedDimensions.
   *
   * @return the number of SedAppliedDimension objects in this
   * SedListOfAppliedDimensions.
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see createAppliedDimension()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumAppliedDimensions() const;


  /**
   * Creates a new SedAppliedDimension object, adds it to this
   * SedListOfAppliedDimensions object and returns the SedAppliedDimension
   * object created.
   *
   * @return a new SedAppliedDimension object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAppliedDimension(const SedAppliedDimension* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAppliedDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedAppliedDimension* createAppliedDimension();


  /**
   * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
   * the Target to which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedAppliedDimension object to retrieve.
   *
   * @return the first SedAppliedDimension in this
   * SedListOfAppliedDimensions based on the given target attribute or NULL
   * if no such SedAppliedDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAppliedDimension* getByTarget(const std::string& sid) const;


  /**
   * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
   * the Target to which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedAppliedDimension object to retrieve.
   *
   * @return the first SedAppliedDimension in this
   * SedListOfAppliedDimensions based on the given target attribute or NULL
   * if no such SedAppliedDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAppliedDimension* getByTarget(const std::string& sid);


  /**
   * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
   * the DimensionTarget to which it refers.
   *
   * @param sid a string representing the "dimensionTarget" attribute of the
   * SedAppliedDimension object to retrieve.
   *
   * @return the first SedAppliedDimension in this
   * SedListOfAppliedDimensions based on the given dimensionTarget attribute
   * or NULL if no such SedAppliedDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAppliedDimension* getByDimensionTarget(const std::string& sid)
    const;


  /**
   * Get a SedAppliedDimension from the SedListOfAppliedDimensions based on
   * the DimensionTarget to which it refers.
   *
   * @param sid a string representing the "dimensionTarget" attribute of the
   * SedAppliedDimension object to retrieve.
   *
   * @return the first SedAppliedDimension in this
   * SedListOfAppliedDimensions based on the given dimensionTarget attribute
   * or NULL if no such SedAppliedDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAppliedDimension* getByDimensionTarget(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfAppliedDimensions object.
   *
   * For SedListOfAppliedDimensions, the XML element name is always
   * @c "listOfAppliedDimensions".
   *
   * @return the name of this element, i.e. @c "listOfAppliedDimensions".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfAppliedDimensions
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
   * SedListOfAppliedDimensions object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfAppliedDimensions:
   * @sedmlconstant{SEDML_APPLIEDDIMENSION, SedTypeCode_t}.
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
   * Creates a new SedAppliedDimension in this SedListOfAppliedDimensions
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
 * Get a SedAppliedDimension_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAppliedDimension_t to retrieve.
 *
 * @return the nth SedAppliedDimension_t in this SedListOf_t or @c NULL if no
 * such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfAppliedDimensions_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedListOfAppliedDimensions_getAppliedDimension(SedListOf_t* slo,
                                                   unsigned int n);


/**
 * Get a SedAppliedDimension_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * SedAppliedDimension_t to retrieve.
 *
 * @return the SedAppliedDimension_t in this SedListOf_t with the given @p
 * sid or @c NULL if no such SedAppliedDimension_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfAppliedDimensions_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedListOfAppliedDimensions_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedAppliedDimension_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAppliedDimension_t to remove.
 *
 * @return a pointer to the nth SedAppliedDimension_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfAppliedDimensions_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedListOfAppliedDimensions_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedAppliedDimension_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * SedAppliedDimension_t to remove.
 *
 * @return the SedAppliedDimension_t in this SedListOf_t based on the
 * identifier or NULL if no such SedAppliedDimension_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfAppliedDimensions_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedListOfAppliedDimensions_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfAppliedDimensions_H__ */


