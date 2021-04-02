/**
 * @file SedListOfDataGenerators.h
 * @brief Definition of the SedListOfDataGenerators class.
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
 * @class SedListOfDataGenerators
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfDataGenerators class.
 */


#ifndef SedListOfDataGenerators_H__
#define SedListOfDataGenerators_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedDataGenerator.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfDataGenerators : public SedListOf
{

public:

  /**
   * Creates a new SedListOfDataGenerators using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfDataGenerators.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfDataGenerators.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfDataGenerators(unsigned int level = SEDML_DEFAULT_LEVEL,
                          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfDataGenerators using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfDataGenerators(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfDataGenerators.
   *
   * @param orig the SedListOfDataGenerators instance to copy.
   */
  SedListOfDataGenerators(const SedListOfDataGenerators& orig);


  /**
   * Assignment operator for SedListOfDataGenerators.
   *
   * @param rhs the SedListOfDataGenerators object whose values are to be used
   * as the basis of the assignment.
   */
  SedListOfDataGenerators& operator=(const SedListOfDataGenerators& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfDataGenerators object.
   *
   * @return a (deep) copy of this SedListOfDataGenerators object.
   */
  virtual SedListOfDataGenerators* clone() const;


  /**
   * Destructor for SedListOfDataGenerators.
   */
  virtual ~SedListOfDataGenerators();


  /**
   * Get a SedDataGenerator from the SedListOfDataGenerators.
   *
   * @param n an unsigned int representing the index of the SedDataGenerator to
   * retrieve.
   *
   * @return the nth SedDataGenerator in this SedListOfDataGenerators or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see get(const std::string& sid)
   * @see getNumDataGenerators()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedDataGenerator* get(unsigned int n);


  /**
   * Get a SedDataGenerator from the SedListOfDataGenerators.
   *
   * @param n an unsigned int representing the index of the SedDataGenerator to
   * retrieve.
   *
   * @return the nth SedDataGenerator in this SedListOfDataGenerators or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see get(const std::string& sid)
   * @see getNumDataGenerators()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedDataGenerator* get(unsigned int n) const;


  /**
   * Get a SedDataGenerator from the SedListOfDataGenerators based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedDataGenerator to
   * retrieve.
   *
   * @return the SedDataGenerator in this SedListOfDataGenerators with the
   * given @p sid or @c NULL if no such SedDataGenerator exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see get(unsigned int n)
   * @see getNumDataGenerators()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedDataGenerator* get(const std::string& sid);


  /**
   * Get a SedDataGenerator from the SedListOfDataGenerators based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedDataGenerator to
   * retrieve.
   *
   * @return the SedDataGenerator in this SedListOfDataGenerators with the
   * given @p sid or @c NULL if no such SedDataGenerator exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see get(unsigned int n)
   * @see getNumDataGenerators()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedDataGenerator* get(const std::string& sid) const;


  /**
   * Removes the nth SedDataGenerator from this SedListOfDataGenerators and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedDataGenerator to
   * remove.
   *
   * @return a pointer to the nth SedDataGenerator in this
   * SedListOfDataGenerators.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataGenerators()
   * @see remove(const std::string& sid)
   */
  virtual SedDataGenerator* remove(unsigned int n);


  /**
   * Removes the SedDataGenerator from this SedListOfDataGenerators based on
   * its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedDataGenerator to
   * remove.
   *
   * @return the SedDataGenerator in this SedListOfDataGenerators based on the
   * identifier or NULL if no such SedDataGenerator exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataGenerators()
   * @see remove(unsigned int n)
   */
  virtual SedDataGenerator* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedDataGenerator to this SedListOfDataGenerators.
   *
   * @param sdg the SedDataGenerator object to add.
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
   * @see createDataGenerator()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataGenerators()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addDataGenerator(const SedDataGenerator* sdg);


  /**
   * Get the number of SedDataGenerator objects in this
   * SedListOfDataGenerators.
   *
   * @return the number of SedDataGenerator objects in this
   * SedListOfDataGenerators.
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see createDataGenerator()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumDataGenerators() const;


  /**
   * Creates a new SedDataGenerator object, adds it to this
   * SedListOfDataGenerators object and returns the SedDataGenerator object
   * created.
   *
   * @return a new SedDataGenerator object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataGenerator(const SedDataGenerator* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataGenerators()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedDataGenerator* createDataGenerator();


  /**
   * Returns the XML element name of this SedListOfDataGenerators object.
   *
   * For SedListOfDataGenerators, the XML element name is always
   * @c "listOfDataGenerators".
   *
   * @return the name of this element, i.e. @c "listOfDataGenerators".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfDataGenerators object.
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
   * SedListOfDataGenerators object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfDataGenerators:
   * @sedmlconstant{SEDML_DATAGENERATOR, SedTypeCode_t}.
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
   * Creates a new SedDataGenerator in this SedListOfDataGenerators
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
 * Get a SedDataGenerator_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataGenerator_t to
 * retrieve.
 *
 * @return the nth SedDataGenerator_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfDataGenerators_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedListOfDataGenerators_getDataGenerator(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedDataGenerator_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataGenerator_t to
 * retrieve.
 *
 * @return the SedDataGenerator_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedDataGenerator_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfDataGenerators_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedListOfDataGenerators_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedDataGenerator_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataGenerator_t to
 * remove.
 *
 * @return a pointer to the nth SedDataGenerator_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfDataGenerators_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedListOfDataGenerators_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedDataGenerator_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataGenerator_t to
 * remove.
 *
 * @return the SedDataGenerator_t in this SedListOf_t based on the identifier
 * or NULL if no such SedDataGenerator_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfDataGenerators_t
 */
LIBSEDML_EXTERN
SedDataGenerator_t*
SedListOfDataGenerators_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfDataGenerators_H__ */


