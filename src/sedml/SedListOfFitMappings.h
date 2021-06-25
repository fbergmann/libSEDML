/**
 * @file SedListOfFitMappings.h
 * @brief Definition of the SedListOfFitMappings class.
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
 * @class SedListOfFitMappings
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfFitMappings class.
 */


#ifndef SedListOfFitMappings_H__
#define SedListOfFitMappings_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedFitMapping.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfFitMappings : public SedListOf
{

public:

  /**
   * Creates a new SedListOfFitMappings using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfFitMappings.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfFitMappings.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfFitMappings(unsigned int level = SEDML_DEFAULT_LEVEL,
                       unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfFitMappings using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfFitMappings(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfFitMappings.
   *
   * @param orig the SedListOfFitMappings instance to copy.
   */
  SedListOfFitMappings(const SedListOfFitMappings& orig);


  /**
   * Assignment operator for SedListOfFitMappings.
   *
   * @param rhs the SedListOfFitMappings object whose values are to be used as
   * the basis of the assignment.
   */
  SedListOfFitMappings& operator=(const SedListOfFitMappings& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfFitMappings object.
   *
   * @return a (deep) copy of this SedListOfFitMappings object.
   */
  virtual SedListOfFitMappings* clone() const;


  /**
   * Destructor for SedListOfFitMappings.
   */
  virtual ~SedListOfFitMappings();


  /**
   * Get a SedFitMapping from the SedListOfFitMappings.
   *
   * @param n an unsigned int representing the index of the SedFitMapping to
   * retrieve.
   *
   * @return the nth SedFitMapping in this SedListOfFitMappings or @c NULL if
   * no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see get(const std::string& sid)
   * @see getNumFitMappings()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedFitMapping* get(unsigned int n);


  /**
   * Get a SedFitMapping from the SedListOfFitMappings.
   *
   * @param n an unsigned int representing the index of the SedFitMapping to
   * retrieve.
   *
   * @return the nth SedFitMapping in this SedListOfFitMappings or @c NULL if
   * no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see get(const std::string& sid)
   * @see getNumFitMappings()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedFitMapping* get(unsigned int n) const;


  /**
   * Get a SedFitMapping from the SedListOfFitMappings based on its identifier.
   *
   * @param sid a string representing the identifier of the SedFitMapping to
   * retrieve.
   *
   * @return the SedFitMapping in this SedListOfFitMappings with the given @p
   * sid or @c NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see get(unsigned int n)
   * @see getNumFitMappings()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedFitMapping* get(const std::string& sid);


  /**
   * Get a SedFitMapping from the SedListOfFitMappings based on its identifier.
   *
   * @param sid a string representing the identifier of the SedFitMapping to
   * retrieve.
   *
   * @return the SedFitMapping in this SedListOfFitMappings with the given @p
   * sid or @c NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see get(unsigned int n)
   * @see getNumFitMappings()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedFitMapping* get(const std::string& sid) const;


  /**
   * Removes the nth SedFitMapping from this SedListOfFitMappings and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedFitMapping to
   * remove.
   *
   * @return a pointer to the nth SedFitMapping in this SedListOfFitMappings.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFitMappings()
   * @see remove(const std::string& sid)
   */
  virtual SedFitMapping* remove(unsigned int n);


  /**
   * Removes the SedFitMapping from this SedListOfFitMappings based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedFitMapping to
   * remove.
   *
   * @return the SedFitMapping in this SedListOfFitMappings based on the
   * identifier or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFitMappings()
   * @see remove(unsigned int n)
   */
  virtual SedFitMapping* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedFitMapping to this SedListOfFitMappings.
   *
   * @param sfm the SedFitMapping object to add.
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
   * @see createFitMapping()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFitMappings()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addFitMapping(const SedFitMapping* sfm);


  /**
   * Get the number of SedFitMapping objects in this SedListOfFitMappings.
   *
   * @return the number of SedFitMapping objects in this SedListOfFitMappings.
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see createFitMapping()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumFitMappings() const;


  /**
   * Creates a new SedFitMapping object, adds it to this SedListOfFitMappings
   * object and returns the SedFitMapping object created.
   *
   * @return a new SedFitMapping object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFitMapping(const SedFitMapping* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumFitMappings()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedFitMapping* createFitMapping();


  /**
   * Get a SedFitMapping from the SedListOfFitMappings based on the DataSource
   * to which it refers.
   *
   * @param sid a string representing the "dataSource" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedListOfFitMappings based on the
   * given dataSource attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedFitMapping* getByDataSource(const std::string& sid) const;


  /**
   * Get a SedFitMapping from the SedListOfFitMappings based on the DataSource
   * to which it refers.
   *
   * @param sid a string representing the "dataSource" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedListOfFitMappings based on the
   * given dataSource attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedFitMapping* getByDataSource(const std::string& sid);


  /**
   * Get a SedFitMapping from the SedListOfFitMappings based on the Target to
   * which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedListOfFitMappings based on the
   * given target attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedFitMapping* getByTarget(const std::string& sid) const;


  /**
   * Get a SedFitMapping from the SedListOfFitMappings based on the Target to
   * which it refers.
   *
   * @param sid a string representing the "target" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedListOfFitMappings based on the
   * given target attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedFitMapping* getByTarget(const std::string& sid);


  /**
   * Get a SedFitMapping from the SedListOfFitMappings based on the PointWeight
   * to which it refers.
   *
   * @param sid a string representing the "pointWeight" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedListOfFitMappings based on the
   * given pointWeight attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedFitMapping* getByPointWeight(const std::string& sid) const;


  /**
   * Get a SedFitMapping from the SedListOfFitMappings based on the PointWeight
   * to which it refers.
   *
   * @param sid a string representing the "pointWeight" attribute of the
   * SedFitMapping object to retrieve.
   *
   * @return the first SedFitMapping in this SedListOfFitMappings based on the
   * given pointWeight attribute or NULL if no such SedFitMapping exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedFitMapping* getByPointWeight(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfFitMappings object.
   *
   * For SedListOfFitMappings, the XML element name is always
   * @c "listOfFitMappings".
   *
   * @return the name of this element, i.e. @c "listOfFitMappings".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfFitMappings object.
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
   * SedListOfFitMappings object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfFitMappings:
   * @sedmlconstant{SEDML_FITMAPPING, SedTypeCode_t}.
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
   * Creates a new SedFitMapping in this SedListOfFitMappings
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
 * Get a SedFitMapping_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedFitMapping_t to
 * retrieve.
 *
 * @return the nth SedFitMapping_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfFitMappings_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedListOfFitMappings_getFitMapping(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedFitMapping_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedFitMapping_t to
 * retrieve.
 *
 * @return the SedFitMapping_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedFitMapping_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfFitMappings_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedListOfFitMappings_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedFitMapping_t from this SedListOf_t and returns a pointer
 * to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedFitMapping_t to
 * remove.
 *
 * @return a pointer to the nth SedFitMapping_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfFitMappings_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedListOfFitMappings_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedFitMapping_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedFitMapping_t to
 * remove.
 *
 * @return the SedFitMapping_t in this SedListOf_t based on the identifier or
 * NULL if no such SedFitMapping_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfFitMappings_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedListOfFitMappings_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfFitMappings_H__ */


