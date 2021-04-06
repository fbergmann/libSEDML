/**
 * @file SedListOfSubPlots.h
 * @brief Definition of the SedListOfSubPlots class.
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
 * @class SedListOfSubPlots
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfSubPlots class.
 */


#ifndef SedListOfSubPlots_H__
#define SedListOfSubPlots_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedSubPlot.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfSubPlots : public SedListOf
{

public:

  /**
   * Creates a new SedListOfSubPlots using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfSubPlots.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfSubPlots.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSubPlots(unsigned int level = SEDML_DEFAULT_LEVEL,
                    unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfSubPlots using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSubPlots(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfSubPlots.
   *
   * @param orig the SedListOfSubPlots instance to copy.
   */
  SedListOfSubPlots(const SedListOfSubPlots& orig);


  /**
   * Assignment operator for SedListOfSubPlots.
   *
   * @param rhs the SedListOfSubPlots object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfSubPlots& operator=(const SedListOfSubPlots& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfSubPlots object.
   *
   * @return a (deep) copy of this SedListOfSubPlots object.
   */
  virtual SedListOfSubPlots* clone() const;


  /**
   * Destructor for SedListOfSubPlots.
   */
  virtual ~SedListOfSubPlots();


  /**
   * Get a SedSubPlot from the SedListOfSubPlots.
   *
   * @param n an unsigned int representing the index of the SedSubPlot to
   * retrieve.
   *
   * @return the nth SedSubPlot in this SedListOfSubPlots or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see get(const std::string& sid)
   * @see getNumSubPlots()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSubPlot* get(unsigned int n);


  /**
   * Get a SedSubPlot from the SedListOfSubPlots.
   *
   * @param n an unsigned int representing the index of the SedSubPlot to
   * retrieve.
   *
   * @return the nth SedSubPlot in this SedListOfSubPlots or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see get(const std::string& sid)
   * @see getNumSubPlots()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSubPlot* get(unsigned int n) const;


  /**
   * Get a SedSubPlot from the SedListOfSubPlots based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSubPlot to
   * retrieve.
   *
   * @return the SedSubPlot in this SedListOfSubPlots with the given @p sid or
   * @c NULL if no such SedSubPlot exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see get(unsigned int n)
   * @see getNumSubPlots()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSubPlot* get(const std::string& sid);


  /**
   * Get a SedSubPlot from the SedListOfSubPlots based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSubPlot to
   * retrieve.
   *
   * @return the SedSubPlot in this SedListOfSubPlots with the given @p sid or
   * @c NULL if no such SedSubPlot exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see get(unsigned int n)
   * @see getNumSubPlots()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSubPlot* get(const std::string& sid) const;


  /**
   * Removes the nth SedSubPlot from this SedListOfSubPlots and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedSubPlot to
   * remove.
   *
   * @return a pointer to the nth SedSubPlot in this SedListOfSubPlots.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSubPlots()
   * @see remove(const std::string& sid)
   */
  virtual SedSubPlot* remove(unsigned int n);


  /**
   * Removes the SedSubPlot from this SedListOfSubPlots based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedSubPlot to
   * remove.
   *
   * @return the SedSubPlot in this SedListOfSubPlots based on the identifier
   * or NULL if no such SedSubPlot exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSubPlots()
   * @see remove(unsigned int n)
   */
  virtual SedSubPlot* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedSubPlot to this SedListOfSubPlots.
   *
   * @param ssp the SedSubPlot object to add.
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
   * @see createSubPlot()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSubPlots()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addSubPlot(const SedSubPlot* ssp);


  /**
   * Get the number of SedSubPlot objects in this SedListOfSubPlots.
   *
   * @return the number of SedSubPlot objects in this SedListOfSubPlots.
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumSubPlots() const;


  /**
   * Creates a new SedSubPlot object, adds it to this SedListOfSubPlots object
   * and returns the SedSubPlot object created.
   *
   * @return a new SedSubPlot object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSubPlots()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedSubPlot* createSubPlot();


  /**
   * Get a SedSubPlot from the SedListOfSubPlots based on the Plot to which it
   * refers.
   *
   * @param sid a string representing the "plot" attribute of the SedSubPlot
   * object to retrieve.
   *
   * @return the first SedSubPlot in this SedListOfSubPlots based on the given
   * plot attribute or NULL if no such SedSubPlot exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSubPlot* getByPlot(const std::string& sid) const;


  /**
   * Get a SedSubPlot from the SedListOfSubPlots based on the Plot to which it
   * refers.
   *
   * @param sid a string representing the "plot" attribute of the SedSubPlot
   * object to retrieve.
   *
   * @return the first SedSubPlot in this SedListOfSubPlots based on the given
   * plot attribute or NULL if no such SedSubPlot exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSubPlot* getByPlot(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfSubPlots object.
   *
   * For SedListOfSubPlots, the XML element name is always @c "listOfSubPlots".
   *
   * @return the name of this element, i.e. @c "listOfSubPlots".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfSubPlots object.
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
   * SedListOfSubPlots object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfSubPlots:
   * @sedmlconstant{SEDML_SUBPLOT, SedTypeCode_t}.
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
   * Creates a new SedSubPlot in this SedListOfSubPlots
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
 * Get a SedSubPlot_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSubPlot_t to
 * retrieve.
 *
 * @return the nth SedSubPlot_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSubPlots_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedListOfSubPlots_getSubPlot(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedSubPlot_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSubPlot_t to
 * retrieve.
 *
 * @return the SedSubPlot_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedSubPlot_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSubPlots_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedListOfSubPlots_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedSubPlot_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSubPlot_t to
 * remove.
 *
 * @return a pointer to the nth SedSubPlot_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSubPlots_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedListOfSubPlots_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedSubPlot_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSubPlot_t to
 * remove.
 *
 * @return the SedSubPlot_t in this SedListOf_t based on the identifier or NULL
 * if no such SedSubPlot_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSubPlots_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedListOfSubPlots_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfSubPlots_H__ */


