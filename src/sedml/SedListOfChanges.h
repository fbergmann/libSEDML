/**
 * @file SedListOfChanges.h
 * @brief Definition of the SedListOfChanges class.
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
 * @class SedListOfChanges
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfChanges class.
 */


#ifndef SedListOfChanges_H__
#define SedListOfChanges_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedChange.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedAddXML;
class SedChangeXML;
class SedRemoveXML;
class SedChangeAttribute;
class SedComputeChange;

class LIBSEDML_EXTERN SedListOfChanges : public SedListOf
{

public:

  /**
   * Creates a new SedListOfChanges using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfChanges.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfChanges.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfChanges(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfChanges using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfChanges(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfChanges.
   *
   * @param orig the SedListOfChanges instance to copy.
   */
  SedListOfChanges(const SedListOfChanges& orig);


  /**
   * Assignment operator for SedListOfChanges.
   *
   * @param rhs the SedListOfChanges object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfChanges& operator=(const SedListOfChanges& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfChanges object.
   *
   * @return a (deep) copy of this SedListOfChanges object.
   */
  virtual SedListOfChanges* clone() const;


  /**
   * Destructor for SedListOfChanges.
   */
  virtual ~SedListOfChanges();


  /**
   * Get a SedChange from the SedListOfChanges.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * retrieve.
   *
   * @return the nth SedChange in this SedListOfChanges or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see get(const std::string& sid)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedChange* get(unsigned int n);


  /**
   * Get a SedChange from the SedListOfChanges.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * retrieve.
   *
   * @return the nth SedChange in this SedListOfChanges or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see get(const std::string& sid)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedChange* get(unsigned int n) const;


  /**
   * Get a SedChange from the SedListOfChanges based on its identifier.
   *
   * @param sid a string representing the identifier of the SedChange to
   * retrieve.
   *
   * @return the SedChange in this SedListOfChanges with the given @p sid or
   * @c NULL if no such SedChange exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedChange* get(const std::string& sid);


  /**
   * Get a SedChange from the SedListOfChanges based on its identifier.
   *
   * @param sid a string representing the identifier of the SedChange to
   * retrieve.
   *
   * @return the SedChange in this SedListOfChanges with the given @p sid or
   * @c NULL if no such SedChange exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedChange* get(const std::string& sid) const;


  /**
   * Removes the nth SedChange from this SedListOfChanges and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * remove.
   *
   * @return a pointer to the nth SedChange in this SedListOfChanges.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   */
  virtual SedChange* remove(unsigned int n);


  /**
   * Removes the SedChange from this SedListOfChanges based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedChange to
   * remove.
   *
   * @return the SedChange in this SedListOfChanges based on the identifier or
   * NULL if no such SedChange exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(unsigned int n)
   */
  virtual SedChange* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedChange to this SedListOfChanges.
   *
   * @param sc the SedChange object to add.
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
   * @see createChange()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addChange(const SedChange* sc);


  /**
   * Get the number of SedChange objects in this SedListOfChanges.
   *
   * @return the number of SedChange objects in this SedListOfChanges.
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumChanges() const;


  /**
   * Creates a new SedAddXML object, adds it to this SedListOfChanges object
   * and returns the SedAddXML object created.
   *
   * @return a new SedAddXML object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedAddXML* createAddXML();


  /**
   * Creates a new SedChangeXML object, adds it to this SedListOfChanges object
   * and returns the SedChangeXML object created.
   *
   * @return a new SedChangeXML object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedChangeXML* createChangeXML();


  /**
   * Creates a new SedRemoveXML object, adds it to this SedListOfChanges object
   * and returns the SedRemoveXML object created.
   *
   * @return a new SedRemoveXML object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedRemoveXML* createRemoveXML();


  /**
   * Creates a new SedChangeAttribute object, adds it to this SedListOfChanges
   * object and returns the SedChangeAttribute object created.
   *
   * @return a new SedChangeAttribute object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedChangeAttribute* createChangeAttribute();


  /**
   * Creates a new SedComputeChange object, adds it to this SedListOfChanges
   * object and returns the SedComputeChange object created.
   *
   * @return a new SedComputeChange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumChanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedComputeChange* createComputeChange();


  /**
   * Returns the XML element name of this SedListOfChanges object.
   *
   * For SedListOfChanges, the XML element name is always @c "listOfChanges".
   *
   * @return the name of this element, i.e. @c "listOfChanges".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfChanges object.
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
   * SedListOfChanges object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfChanges:
   * @sedmlconstant{SEDML_CHANGE, SedTypeCode_t}.
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
   * Creates a new SedChange in this SedListOfChanges
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * checks concrete types
   */
  virtual bool isValidTypeForList(SedBase* item);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedChange_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedChange_t to
 * retrieve.
 *
 * @return the nth SedChange_t in this SedListOf_t or @c NULL if no such object
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfChanges_t
 */
LIBSEDML_EXTERN
SedChange_t*
SedListOfChanges_getChange(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedChange_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedChange_t to
 * retrieve.
 *
 * @return the SedChange_t in this SedListOf_t with the given @p sid or @c NULL
 * if no such SedChange_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfChanges_t
 */
LIBSEDML_EXTERN
SedChange_t*
SedListOfChanges_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedChange_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedChange_t to
 * remove.
 *
 * @return a pointer to the nth SedChange_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfChanges_t
 */
LIBSEDML_EXTERN
SedChange_t*
SedListOfChanges_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedChange_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedChange_t to
 * remove.
 *
 * @return the SedChange_t in this SedListOf_t based on the identifier or NULL
 * if no such SedChange_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfChanges_t
 */
LIBSEDML_EXTERN
SedChange_t*
SedListOfChanges_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfChanges_H__ */


