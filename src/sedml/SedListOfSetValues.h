/**
 * @file SedListOfSetValues.h
 * @brief Definition of the SedListOfSetValues class.
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
 * @class SedListOfSetValues
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfSetValues class.
 */


#ifndef SedListOfSetValues_H__
#define SedListOfSetValues_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedSetValue.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfSetValues : public SedListOf
{

public:

  /**
   * Creates a new SedListOfSetValues using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfSetValues.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfSetValues.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSetValues(unsigned int level = SEDML_DEFAULT_LEVEL,
                     unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfSetValues using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSetValues(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfSetValues.
   *
   * @param orig the SedListOfSetValues instance to copy.
   */
  SedListOfSetValues(const SedListOfSetValues& orig);


  /**
   * Assignment operator for SedListOfSetValues.
   *
   * @param rhs the SedListOfSetValues object whose values are to be used as
   * the basis of the assignment.
   */
  SedListOfSetValues& operator=(const SedListOfSetValues& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfSetValues object.
   *
   * @return a (deep) copy of this SedListOfSetValues object.
   */
  virtual SedListOfSetValues* clone() const;


  /**
   * Destructor for SedListOfSetValues.
   */
  virtual ~SedListOfSetValues();


  /**
   * Get a SedSetValue from the SedListOfSetValues.
   *
   * @param n an unsigned int representing the index of the SedSetValue to
   * retrieve.
   *
   * @return the nth SedSetValue in this SedListOfSetValues or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createSetValue()
   * @see get(const std::string& sid)
   * @see getNumTaskChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSetValue* get(unsigned int n);


  /**
   * Get a SedSetValue from the SedListOfSetValues.
   *
   * @param n an unsigned int representing the index of the SedSetValue to
   * retrieve.
   *
   * @return the nth SedSetValue in this SedListOfSetValues or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createSetValue()
   * @see get(const std::string& sid)
   * @see getNumTaskChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSetValue* get(unsigned int n) const;


  /**
   * Get a SedSetValue from the SedListOfSetValues based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSetValue to
   * retrieve.
   *
   * @return the SedSetValue in this SedListOfSetValues with the given @p sid
   * or @c NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createSetValue()
   * @see get(unsigned int n)
   * @see getNumTaskChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSetValue* get(const std::string& sid);


  /**
   * Get a SedSetValue from the SedListOfSetValues based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSetValue to
   * retrieve.
   *
   * @return the SedSetValue in this SedListOfSetValues with the given @p sid
   * or @c NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createSetValue()
   * @see get(unsigned int n)
   * @see getNumTaskChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSetValue* get(const std::string& sid) const;


  /**
   * Removes the nth SedSetValue from this SedListOfSetValues and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedSetValue to
   * remove.
   *
   * @return a pointer to the nth SedSetValue in this SedListOfSetValues.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createSetValue()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumTaskChanges()
   * @see remove(const std::string& sid)
   */
  virtual SedSetValue* remove(unsigned int n);


  /**
   * Removes the SedSetValue from this SedListOfSetValues based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedSetValue to
   * remove.
   *
   * @return the SedSetValue in this SedListOfSetValues based on the identifier
   * or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createSetValue()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumTaskChanges()
   * @see remove(unsigned int n)
   */
  virtual SedSetValue* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedSetValue to this SedListOfSetValues.
   *
   * @param ssv the SedSetValue object to add.
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
   * @see createSetValue()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumTaskChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addTaskChange(const SedSetValue* ssv);


  /**
   * Get the number of SedSetValue objects in this SedListOfSetValues.
   *
   * @return the number of SedSetValue objects in this SedListOfSetValues.
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see createSetValue()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumTaskChanges() const;


  /**
   * Creates a new SedSetValue object, adds it to this SedListOfSetValues
   * object and returns the SedSetValue object created.
   *
   * @return a new SedSetValue object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addTaskChange(const SedSetValue* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumTaskChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedSetValue* createSetValue();


  /**
   * Get a SedSetValue from the SedListOfSetValues based on the ModelReference
   * to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedSetValue object to retrieve.
   *
   * @return the first SedSetValue in this SedListOfSetValues based on the
   * given modelReference attribute or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSetValue* getByModelReference(const std::string& sid) const;


  /**
   * Get a SedSetValue from the SedListOfSetValues based on the ModelReference
   * to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedSetValue object to retrieve.
   *
   * @return the first SedSetValue in this SedListOfSetValues based on the
   * given modelReference attribute or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSetValue* getByModelReference(const std::string& sid);


  /**
   * Get a SedSetValue from the SedListOfSetValues based on the Range to which
   * it refers.
   *
   * @param sid a string representing the "range" attribute of the SedSetValue
   * object to retrieve.
   *
   * @return the first SedSetValue in this SedListOfSetValues based on the
   * given range attribute or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSetValue* getByRange(const std::string& sid) const;


  /**
   * Get a SedSetValue from the SedListOfSetValues based on the Range to which
   * it refers.
   *
   * @param sid a string representing the "range" attribute of the SedSetValue
   * object to retrieve.
   *
   * @return the first SedSetValue in this SedListOfSetValues based on the
   * given range attribute or NULL if no such SedSetValue exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSetValue* getByRange(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfSetValues object.
   *
   * For SedListOfSetValues, the XML element name is always
   * @c "listOfChanges".
   *
   * @return the name of this element, i.e. @c "listOfChanges".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfSetValues object.
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
   * SedListOfSetValues object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfSetValues:
   * @sedmlconstant{SEDML_TASK_SETVALUE, SedTypeCode_t}.
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
   * Creates a new SedSetValue in this SedListOfSetValues
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
 * Get a SedSetValue_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSetValue_t to
 * retrieve.
 *
 * @return the nth SedSetValue_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSetValues_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedListOfSetValues_getTaskChange(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedSetValue_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSetValue_t to
 * retrieve.
 *
 * @return the SedSetValue_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedSetValue_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSetValues_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedListOfSetValues_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedSetValue_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSetValue_t to
 * remove.
 *
 * @return a pointer to the nth SedSetValue_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSetValues_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedListOfSetValues_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedSetValue_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSetValue_t to
 * remove.
 *
 * @return the SedSetValue_t in this SedListOf_t based on the identifier or
 * NULL if no such SedSetValue_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSetValues_t
 */
LIBSEDML_EXTERN
SedSetValue_t*
SedListOfSetValues_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfSetValues_H__ */


