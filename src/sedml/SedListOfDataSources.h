/**
 * @file SedListOfDataSources.h
 * @brief Definition of the SedListOfDataSources class.
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
 * @class SedListOfDataSources
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfDataSources class.
 */


#ifndef SedListOfDataSources_H__
#define SedListOfDataSources_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedDataSource.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfDataSources : public SedListOf
{

public:

  /**
   * Creates a new SedListOfDataSources using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfDataSources.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfDataSources.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfDataSources(unsigned int level = SEDML_DEFAULT_LEVEL,
                       unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfDataSources using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfDataSources(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfDataSources.
   *
   * @param orig the SedListOfDataSources instance to copy.
   */
  SedListOfDataSources(const SedListOfDataSources& orig);


  /**
   * Assignment operator for SedListOfDataSources.
   *
   * @param rhs the SedListOfDataSources object whose values are to be used as
   * the basis of the assignment.
   */
  SedListOfDataSources& operator=(const SedListOfDataSources& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfDataSources object.
   *
   * @return a (deep) copy of this SedListOfDataSources object.
   */
  virtual SedListOfDataSources* clone() const;


  /**
   * Destructor for SedListOfDataSources.
   */
  virtual ~SedListOfDataSources();


  /**
   * Get a SedDataSource from the SedListOfDataSources.
   *
   * @param n an unsigned int representing the index of the SedDataSource to
   * retrieve.
   *
   * @return the nth SedDataSource in this SedListOfDataSources or @c NULL if
   * no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see get(const std::string& sid)
   * @see getNumDataSources()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedDataSource* get(unsigned int n);


  /**
   * Get a SedDataSource from the SedListOfDataSources.
   *
   * @param n an unsigned int representing the index of the SedDataSource to
   * retrieve.
   *
   * @return the nth SedDataSource in this SedListOfDataSources or @c NULL if
   * no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see get(const std::string& sid)
   * @see getNumDataSources()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedDataSource* get(unsigned int n) const;


  /**
   * Get a SedDataSource from the SedListOfDataSources based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataSource to
   * retrieve.
   *
   * @return the SedDataSource in this SedListOfDataSources with the given @p
   * sid or @c NULL if no such SedDataSource exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see get(unsigned int n)
   * @see getNumDataSources()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedDataSource* get(const std::string& sid);


  /**
   * Get a SedDataSource from the SedListOfDataSources based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataSource to
   * retrieve.
   *
   * @return the SedDataSource in this SedListOfDataSources with the given @p
   * sid or @c NULL if no such SedDataSource exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see get(unsigned int n)
   * @see getNumDataSources()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedDataSource* get(const std::string& sid) const;


  /**
   * Removes the nth SedDataSource from this SedListOfDataSources and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedDataSource to
   * remove.
   *
   * @return a pointer to the nth SedDataSource in this SedListOfDataSources.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataSources()
   * @see remove(const std::string& sid)
   */
  virtual SedDataSource* remove(unsigned int n);


  /**
   * Removes the SedDataSource from this SedListOfDataSources based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedDataSource to
   * remove.
   *
   * @return the SedDataSource in this SedListOfDataSources based on the
   * identifier or NULL if no such SedDataSource exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataSources()
   * @see remove(unsigned int n)
   */
  virtual SedDataSource* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedDataSource to this SedListOfDataSources.
   *
   * @param sds the SedDataSource object to add.
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
   * @see createDataSource()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataSources()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addDataSource(const SedDataSource* sds);


  /**
   * Get the number of SedDataSource objects in this SedListOfDataSources.
   *
   * @return the number of SedDataSource objects in this SedListOfDataSources.
   *
   * @see addDataSource(const SedDataSource* object)
   * @see createDataSource()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumDataSources() const;


  /**
   * Creates a new SedDataSource object, adds it to this SedListOfDataSources
   * object and returns the SedDataSource object created.
   *
   * @return a new SedDataSource object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSource(const SedDataSource* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataSources()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedDataSource* createDataSource();


  /**
   * Get a SedDataSource from the SedListOfDataSources based on the IndexSet to
   * which it refers.
   *
   * @param sid a string representing the "indexSet" attribute of the
   * SedDataSource object to retrieve.
   *
   * @return the first SedDataSource in this SedListOfDataSources based on the
   * given indexSet attribute or NULL if no such SedDataSource exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedDataSource* getByIndexSet(const std::string& sid) const;


  /**
   * Get a SedDataSource from the SedListOfDataSources based on the IndexSet to
   * which it refers.
   *
   * @param sid a string representing the "indexSet" attribute of the
   * SedDataSource object to retrieve.
   *
   * @return the first SedDataSource in this SedListOfDataSources based on the
   * given indexSet attribute or NULL if no such SedDataSource exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedDataSource* getByIndexSet(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfDataSources object.
   *
   * For SedListOfDataSources, the XML element name is always
   * @c "listOfDataSources".
   *
   * @return the name of this element, i.e. @c "listOfDataSources".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfDataSources object.
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
   * SedListOfDataSources object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfDataSources:
   * @sedmlconstant{SEDML_DATA_SOURCE, SedTypeCode_t}.
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
   * Creates a new SedDataSource in this SedListOfDataSources
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
 * Get a SedDataSource_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataSource_t to
 * retrieve.
 *
 * @return the nth SedDataSource_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfDataSources_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedListOfDataSources_getDataSource(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedDataSource_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataSource_t to
 * retrieve.
 *
 * @return the SedDataSource_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedDataSource_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfDataSources_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedListOfDataSources_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedDataSource_t from this SedListOf_t and returns a pointer
 * to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataSource_t to
 * remove.
 *
 * @return a pointer to the nth SedDataSource_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfDataSources_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedListOfDataSources_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedDataSource_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataSource_t to
 * remove.
 *
 * @return the SedDataSource_t in this SedListOf_t based on the identifier or
 * NULL if no such SedDataSource_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfDataSources_t
 */
LIBSEDML_EXTERN
SedDataSource_t*
SedListOfDataSources_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfDataSources_H__ */


