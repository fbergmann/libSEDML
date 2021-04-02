/**
 * @file SedListOfDataDescriptions.h
 * @brief Definition of the SedListOfDataDescriptions class.
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
 * @class SedListOfDataDescriptions
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfDataDescriptions class.
 */


#ifndef SedListOfDataDescriptions_H__
#define SedListOfDataDescriptions_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedDataDescription.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfDataDescriptions : public SedListOf
{

public:

  /**
   * Creates a new SedListOfDataDescriptions using the given SED-ML Level and @
   * p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfDataDescriptions.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfDataDescriptions.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfDataDescriptions(unsigned int level = SEDML_DEFAULT_LEVEL,
                            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfDataDescriptions using the given SedNamespaces
   * object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfDataDescriptions(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfDataDescriptions.
   *
   * @param orig the SedListOfDataDescriptions instance to copy.
   */
  SedListOfDataDescriptions(const SedListOfDataDescriptions& orig);


  /**
   * Assignment operator for SedListOfDataDescriptions.
   *
   * @param rhs the SedListOfDataDescriptions object whose values are to be
   * used as the basis of the assignment.
   */
  SedListOfDataDescriptions& operator=(const SedListOfDataDescriptions& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfDataDescriptions object.
   *
   * @return a (deep) copy of this SedListOfDataDescriptions object.
   */
  virtual SedListOfDataDescriptions* clone() const;


  /**
   * Destructor for SedListOfDataDescriptions.
   */
  virtual ~SedListOfDataDescriptions();


  /**
   * Get a SedDataDescription from the SedListOfDataDescriptions.
   *
   * @param n an unsigned int representing the index of the SedDataDescription
   * to retrieve.
   *
   * @return the nth SedDataDescription in this SedListOfDataDescriptions or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see get(const std::string& sid)
   * @see getNumDataDescriptions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedDataDescription* get(unsigned int n);


  /**
   * Get a SedDataDescription from the SedListOfDataDescriptions.
   *
   * @param n an unsigned int representing the index of the SedDataDescription
   * to retrieve.
   *
   * @return the nth SedDataDescription in this SedListOfDataDescriptions or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see get(const std::string& sid)
   * @see getNumDataDescriptions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedDataDescription* get(unsigned int n) const;


  /**
   * Get a SedDataDescription from the SedListOfDataDescriptions based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedDataDescription
   * to retrieve.
   *
   * @return the SedDataDescription in this SedListOfDataDescriptions with the
   * given @p sid or @c NULL if no such SedDataDescription exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see get(unsigned int n)
   * @see getNumDataDescriptions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedDataDescription* get(const std::string& sid);


  /**
   * Get a SedDataDescription from the SedListOfDataDescriptions based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedDataDescription
   * to retrieve.
   *
   * @return the SedDataDescription in this SedListOfDataDescriptions with the
   * given @p sid or @c NULL if no such SedDataDescription exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see get(unsigned int n)
   * @see getNumDataDescriptions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedDataDescription* get(const std::string& sid) const;


  /**
   * Removes the nth SedDataDescription from this SedListOfDataDescriptions and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedDataDescription
   * to remove.
   *
   * @return a pointer to the nth SedDataDescription in this
   * SedListOfDataDescriptions.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataDescriptions()
   * @see remove(const std::string& sid)
   */
  virtual SedDataDescription* remove(unsigned int n);


  /**
   * Removes the SedDataDescription from this SedListOfDataDescriptions based
   * on its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedDataDescription
   * to remove.
   *
   * @return the SedDataDescription in this SedListOfDataDescriptions based on
   * the identifier or NULL if no such SedDataDescription exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataDescriptions()
   * @see remove(unsigned int n)
   */
  virtual SedDataDescription* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedDataDescription to this
   * SedListOfDataDescriptions.
   *
   * @param sdd the SedDataDescription object to add.
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
   * @see createDataDescription()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataDescriptions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addDataDescription(const SedDataDescription* sdd);


  /**
   * Get the number of SedDataDescription objects in this
   * SedListOfDataDescriptions.
   *
   * @return the number of SedDataDescription objects in this
   * SedListOfDataDescriptions.
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see createDataDescription()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumDataDescriptions() const;


  /**
   * Creates a new SedDataDescription object, adds it to this
   * SedListOfDataDescriptions object and returns the SedDataDescription object
   * created.
   *
   * @return a new SedDataDescription object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addDataDescription(const SedDataDescription* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumDataDescriptions()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedDataDescription* createDataDescription();


  /**
   * Returns the XML element name of this SedListOfDataDescriptions object.
   *
   * For SedListOfDataDescriptions, the XML element name is always
   * @c "listOfDataDescriptions".
   *
   * @return the name of this element, i.e. @c "listOfDataDescriptions".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfDataDescriptions object.
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
   * SedListOfDataDescriptions object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfDataDescriptions:
   * @sedmlconstant{SEDML_DATA_DESCRIPTION, SedTypeCode_t}.
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
   * Creates a new SedDataDescription in this SedListOfDataDescriptions
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
 * Get a SedDataDescription_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataDescription_t
 * to retrieve.
 *
 * @return the nth SedDataDescription_t in this SedListOf_t or @c NULL if no
 * such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfDataDescriptions_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedListOfDataDescriptions_getDataDescription(SedListOf_t* slo,
                                             unsigned int n);


/**
 * Get a SedDataDescription_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataDescription_t
 * to retrieve.
 *
 * @return the SedDataDescription_t in this SedListOf_t with the given @p sid
 * or @c NULL if no such SedDataDescription_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfDataDescriptions_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedListOfDataDescriptions_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedDataDescription_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedDataDescription_t
 * to remove.
 *
 * @return a pointer to the nth SedDataDescription_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfDataDescriptions_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedListOfDataDescriptions_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedDataDescription_t from this SedListOf_t based on its
 * identifier and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedDataDescription_t
 * to remove.
 *
 * @return the SedDataDescription_t in this SedListOf_t based on the identifier
 * or NULL if no such SedDataDescription_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfDataDescriptions_t
 */
LIBSEDML_EXTERN
SedDataDescription_t*
SedListOfDataDescriptions_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfDataDescriptions_H__ */


