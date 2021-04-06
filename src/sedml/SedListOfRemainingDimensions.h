/**
 * @file SedListOfRemainingDimensions.h
 * @brief Definition of the SedListOfRemainingDimensions class.
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
 * @class SedListOfRemainingDimensions
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfRemainingDimensions class.
 */


#ifndef SedListOfRemainingDimensions_H__
#define SedListOfRemainingDimensions_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedRemainingDimension.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfRemainingDimensions : public SedListOf
{

public:

  /**
   * Creates a new SedListOfRemainingDimensions using the given SED-ML Level and
   * @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfRemainingDimensions.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfRemainingDimensions.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfRemainingDimensions(unsigned int level = SEDML_DEFAULT_LEVEL,
                               unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfRemainingDimensions using the given SedNamespaces
   * object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfRemainingDimensions(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfRemainingDimensions.
   *
   * @param orig the SedListOfRemainingDimensions instance to copy.
   */
  SedListOfRemainingDimensions(const SedListOfRemainingDimensions& orig);


  /**
   * Assignment operator for SedListOfRemainingDimensions.
   *
   * @param rhs the SedListOfRemainingDimensions object whose values are to be
   * used as the basis of the assignment.
   */
  SedListOfRemainingDimensions& operator=(const SedListOfRemainingDimensions&
    rhs);


  /**
   * Creates and returns a deep copy of this SedListOfRemainingDimensions
   * object.
   *
   * @return a (deep) copy of this SedListOfRemainingDimensions object.
   */
  virtual SedListOfRemainingDimensions* clone() const;


  /**
   * Destructor for SedListOfRemainingDimensions.
   */
  virtual ~SedListOfRemainingDimensions();


  /**
   * Get a SedRemainingDimension from the SedListOfRemainingDimensions.
   *
   * @param n an unsigned int representing the index of the
   * SedRemainingDimension to retrieve.
   *
   * @return the nth SedRemainingDimension in this SedListOfRemainingDimensions
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see get(const std::string& sid)
   * @see getNumRemainingDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedRemainingDimension* get(unsigned int n);


  /**
   * Get a SedRemainingDimension from the SedListOfRemainingDimensions.
   *
   * @param n an unsigned int representing the index of the
   * SedRemainingDimension to retrieve.
   *
   * @return the nth SedRemainingDimension in this SedListOfRemainingDimensions
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see get(const std::string& sid)
   * @see getNumRemainingDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedRemainingDimension* get(unsigned int n) const;


  /**
   * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
   * its identifier.
   *
   * @param sid a string representing the identifier of the
   * SedRemainingDimension to retrieve.
   *
   * @return the SedRemainingDimension in this SedListOfRemainingDimensions
   * with the given @p sid or @c NULL if no such SedRemainingDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see get(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedRemainingDimension* get(const std::string& sid);


  /**
   * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
   * its identifier.
   *
   * @param sid a string representing the identifier of the
   * SedRemainingDimension to retrieve.
   *
   * @return the SedRemainingDimension in this SedListOfRemainingDimensions
   * with the given @p sid or @c NULL if no such SedRemainingDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see get(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedRemainingDimension* get(const std::string& sid) const;


  /**
   * Removes the nth SedRemainingDimension from this
   * SedListOfRemainingDimensions and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * SedRemainingDimension to remove.
   *
   * @return a pointer to the nth SedRemainingDimension in this
   * SedListOfRemainingDimensions.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see remove(const std::string& sid)
   */
  virtual SedRemainingDimension* remove(unsigned int n);


  /**
   * Removes the SedRemainingDimension from this SedListOfRemainingDimensions
   * based on its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the
   * SedRemainingDimension to remove.
   *
   * @return the SedRemainingDimension in this SedListOfRemainingDimensions
   * based on the identifier or NULL if no such SedRemainingDimension exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see remove(unsigned int n)
   */
  virtual SedRemainingDimension* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedRemainingDimension to this
   * SedListOfRemainingDimensions.
   *
   * @param srd the SedRemainingDimension object to add.
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
   * @see createRemainingDimension()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addRemainingDimension(const SedRemainingDimension* srd);


  /**
   * Get the number of SedRemainingDimension objects in this
   * SedListOfRemainingDimensions.
   *
   * @return the number of SedRemainingDimension objects in this
   * SedListOfRemainingDimensions.
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see createRemainingDimension()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumRemainingDimensions() const;


  /**
   * Creates a new SedRemainingDimension object, adds it to this
   * SedListOfRemainingDimensions object and returns the SedRemainingDimension
   * object created.
   *
   * @return a new SedRemainingDimension object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRemainingDimension(const SedRemainingDimension* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRemainingDimensions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedRemainingDimension* createRemainingDimension();


  /**
   * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
   * the Target to which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedRemainingDimension object to retrieve.
   *
   * @return the first SedRemainingDimension in this
   * SedListOfRemainingDimensions based on the given target attribute or NULL
   * if no such SedRemainingDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedRemainingDimension* getByTarget(const std::string& sid) const;


  /**
   * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
   * the Target to which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedRemainingDimension object to retrieve.
   *
   * @return the first SedRemainingDimension in this
   * SedListOfRemainingDimensions based on the given target attribute or NULL
   * if no such SedRemainingDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedRemainingDimension* getByTarget(const std::string& sid);


  /**
   * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
   * the DimensionTarget to which it refers.
   *
   * @param sid a string representing the "dimensionTarget" attribute of the
   * SedRemainingDimension object to retrieve.
   *
   * @return the first SedRemainingDimension in this
   * SedListOfRemainingDimensions based on the given dimensionTarget attribute
   * or NULL if no such SedRemainingDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedRemainingDimension* getByDimensionTarget(const std::string& sid)
    const;


  /**
   * Get a SedRemainingDimension from the SedListOfRemainingDimensions based on
   * the DimensionTarget to which it refers.
   *
   * @param sid a string representing the "dimensionTarget" attribute of the
   * SedRemainingDimension object to retrieve.
   *
   * @return the first SedRemainingDimension in this
   * SedListOfRemainingDimensions based on the given dimensionTarget attribute
   * or NULL if no such SedRemainingDimension exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedRemainingDimension* getByDimensionTarget(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfRemainingDimensions object.
   *
   * For SedListOfRemainingDimensions, the XML element name is always
   * @c "listOfRemainingDimensions".
   *
   * @return the name of this element, i.e. @c "listOfRemainingDimensions".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfRemainingDimensions
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
   * SedListOfRemainingDimensions object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfRemainingDimensions:
   * @sedmlconstant{SEDML_REMAININGDIMENSION, SedTypeCode_t}.
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
   * Creates a new SedRemainingDimension in this SedListOfRemainingDimensions
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
 * Get a SedRemainingDimension_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedRemainingDimension_t to retrieve.
 *
 * @return the nth SedRemainingDimension_t in this SedListOf_t or @c NULL if no
 * such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfRemainingDimensions_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedListOfRemainingDimensions_getRemainingDimension(SedListOf_t* slo,
                                                   unsigned int n);


/**
 * Get a SedRemainingDimension_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * SedRemainingDimension_t to retrieve.
 *
 * @return the SedRemainingDimension_t in this SedListOf_t with the given @p
 * sid or @c NULL if no such SedRemainingDimension_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfRemainingDimensions_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedListOfRemainingDimensions_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedRemainingDimension_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedRemainingDimension_t to remove.
 *
 * @return a pointer to the nth SedRemainingDimension_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfRemainingDimensions_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedListOfRemainingDimensions_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedRemainingDimension_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * SedRemainingDimension_t to remove.
 *
 * @return the SedRemainingDimension_t in this SedListOf_t based on the
 * identifier or NULL if no such SedRemainingDimension_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfRemainingDimensions_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedListOfRemainingDimensions_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfRemainingDimensions_H__ */


