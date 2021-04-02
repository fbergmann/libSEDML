/**
 * @file SedListOfDataSets.h
 * @brief Definition of the SedListOfDataSets class.
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
 * @class SedListOfDataSets
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfDataSets class.
 */


#ifndef SedListOfDataSets_H__
#define SedListOfDataSets_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedDataSet.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfDataSets : public SedListOf
{

public:

  /**
   * Creates a new SedListOfDataSets using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfDataSets.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfDataSets.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfDataSets(unsigned int level = SEDML_DEFAULT_LEVEL,
                    unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfDataSets using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfDataSets(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfDataSets.
   *
   * @param orig the SedListOfDataSets instance to copy.
   */
  SedListOfDataSets(const SedListOfDataSets& orig);


  /**
   * Assignment operator for SedListOfDataSets.
   *
   * @param rhs the SedListOfDataSets object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfDataSets& operator=(const SedListOfDataSets& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfDataSets object.
   *
   * @return a (deep) copy of this SedListOfDataSets object.
   */
  virtual SedListOfDataSets* clone() const;


  /**
   * Destructor for SedListOfDataSets.
   */
  virtual ~SedListOfDataSets();


  /**
   * Get a SedDataSet from the SedListOfDataSets.
   *
   * @param n an unsigned int representing the index of the SedDataSet to
   * retrieve.
   *
   * @return the nth SedDataSet in this SedListOfDataSets or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see get(const std::string& sid)
   * @see getNumDataSets()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedDataSet* get(unsigned int n);


  /**
   * Get a SedDataSet from the SedListOfDataSets.
   *
   * @param n an unsigned int representing the index of the SedDataSet to
   * retrieve.
   *
   * @return the nth SedDataSet in this SedListOfDataSets or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see get(const std::string& sid)
   * @see getNumDataSets()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedDataSet* get(unsigned int n) const;


  /**
   * Get a SedDataSet from the SedListOfDataSets based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataSet to
   * retrieve.
   *
   * @return the SedDataSet in this SedListOfDataSets with the given @p sid or
   * @c NULL if no such SedDataSet exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see get(unsigned int n)
   * @see getNumDataSets()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedDataSet* get(const std::string& sid);


  /**
   * Get a SedDataSet from the SedListOfDataSets based on its identifier.
   *
   * @param sid a string representing the identifier of the SedDataSet to
   * retrieve.
   *
   * @return the SedDataSet in this SedListOfDataSets with the given @p sid or
   * @c NULL if no such SedDataSet exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see get(unsigned int n)
   * @see getNumDataSets()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedDataSet* get(const std::string& sid) const;


  /**
   * Removes the nth SedDataSet from this SedListOfDataSets and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedDataSet to
   * remove.
   *
   * @return a pointer to the nth SedDataSet in this SedListOfDataSets.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataSets()
   * @see remove(const std::string& sid)
   */
  virtual SedDataSet* remove(unsigned int n);


  /**
   * Removes the SedDataSet from this SedListOfDataSets based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedDataSet to
   * remove.
   *
   * @return the SedDataSet in this SedListOfDataSets based on the identifier
   * or NULL if no such SedDataSet exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataSets()
   * @see remove(unsigned int n)
   */
  virtual SedDataSet* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedDataSet to this SedListOfDataSets.
   *
   * @param sds the SedDataSet object to add.
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
   * @see createDataSet()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataSets()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addDataSet(const SedDataSet* sds);


  /**
   * Get the number of SedDataSet objects in this SedListOfDataSets.
   *
   * @return the number of SedDataSet objects in this SedListOfDataSets.
   *
   * @see addDataSet(const SedDataSet* object)
   * @see createDataSet()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumDataSets() const;


  /**
   * Creates a new SedDataSet object, adds it to this SedListOfDataSets object
   * and returns the SedDataSet object created.
   *
   * @return a new SedDataSet object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataSet(const SedDataSet* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataSets()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedDataSet* createDataSet();


  /**
   * Get a SedDataSet from the SedListOfDataSets based on the DataReference to
   * which it refers.
   *
   * @param sid a string representing the "dataReference" attribute of the
   * SedDataSet object to retrieve.
   *
   * @return the first SedDataSet in this SedListOfDataSets based on the given
   * dataReference attribute or NULL if no such SedDataSet exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedDataSet* getByDataReference(const std::string& sid) const;


  /**
   * Get a SedDataSet from the SedListOfDataSets based on the DataReference to
   * which it refers.
   *
   * @param sid a string representing the "dataReference" attribute of the
   * SedDataSet object to retrieve.
   *
   * @return the first SedDataSet in this SedListOfDataSets based on the given
   * dataReference attribute or NULL if no such SedDataSet exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedDataSet* getByDataReference(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfDataSets object.
   *
   * For SedListOfDataSets, the XML element name is always @c "listOfDataSets".
   *
   * @return the name of this element, i.e. @c "listOfDataSets".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfDataSets object.
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
   * SedListOfDataSets object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfDataSets:
   * @sedmlconstant{SEDML_OUTPUT_DATASET, SedTypeCode_t}.
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
   * Creates a new SedDataSet in this SedListOfDataSets
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
 * Get a SedDataSet_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataSet_t to
 * retrieve.
 *
 * @return the nth SedDataSet_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfDataSets_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedListOfDataSets_getDataSet(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedDataSet_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataSet_t to
 * retrieve.
 *
 * @return the SedDataSet_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedDataSet_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfDataSets_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedListOfDataSets_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedDataSet_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataSet_t to
 * remove.
 *
 * @return a pointer to the nth SedDataSet_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfDataSets_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedListOfDataSets_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedDataSet_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataSet_t to
 * remove.
 *
 * @return the SedDataSet_t in this SedListOf_t based on the identifier or NULL
 * if no such SedDataSet_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfDataSets_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedListOfDataSets_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfDataSets_H__ */


