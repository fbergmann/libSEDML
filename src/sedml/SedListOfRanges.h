/**
 * @file SedListOfRanges.h
 * @brief Definition of the SedListOfRanges class.
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
 * @class SedListOfRanges
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfRanges class.
 */


#ifndef SedListOfRanges_H__
#define SedListOfRanges_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedRange.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedUniformRange;
class SedVectorRange;
class SedFunctionalRange;
class SedDataRange;

class LIBSEDML_EXTERN SedListOfRanges : public SedListOf
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedListOfRanges using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfRanges.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfRanges.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfRanges(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfRanges using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfRanges(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfRanges.
   *
   * @param orig the SedListOfRanges instance to copy.
   */
  SedListOfRanges(const SedListOfRanges& orig);


  /**
   * Assignment operator for SedListOfRanges.
   *
   * @param rhs the SedListOfRanges object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfRanges& operator=(const SedListOfRanges& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfRanges object.
   *
   * @return a (deep) copy of this SedListOfRanges object.
   */
  virtual SedListOfRanges* clone() const;


  /**
   * Destructor for SedListOfRanges.
   */
  virtual ~SedListOfRanges();


  /**
   * Get a SedRange from the SedListOfRanges.
   *
   * @param n an unsigned int representing the index of the SedRange to
   * retrieve.
   *
   * @return the nth SedRange in this SedListOfRanges or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see get(const std::string& sid)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedRange* get(unsigned int n);


  /**
   * Get a SedRange from the SedListOfRanges.
   *
   * @param n an unsigned int representing the index of the SedRange to
   * retrieve.
   *
   * @return the nth SedRange in this SedListOfRanges or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see get(const std::string& sid)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedRange* get(unsigned int n) const;


  /**
   * Get a SedRange from the SedListOfRanges based on its identifier.
   *
   * @param sid a string representing the identifier of the SedRange to
   * retrieve.
   *
   * @return the SedRange in this SedListOfRanges with the given @p sid or
   * @c NULL if no such SedRange exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedRange* get(const std::string& sid);


  /**
   * Get a SedRange from the SedListOfRanges based on its identifier.
   *
   * @param sid a string representing the identifier of the SedRange to
   * retrieve.
   *
   * @return the SedRange in this SedListOfRanges with the given @p sid or
   * @c NULL if no such SedRange exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedRange* get(const std::string& sid) const;


  /**
   * Removes the nth SedRange from this SedListOfRanges and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedRange to remove.
   *
   * @return a pointer to the nth SedRange in this SedListOfRanges.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   */
  virtual SedRange* remove(unsigned int n);


  /**
   * Removes the SedRange from this SedListOfRanges based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedRange to remove.
   *
   * @return the SedRange in this SedListOfRanges based on the identifier or
   * NULL if no such SedRange exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(unsigned int n)
   */
  virtual SedRange* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedRange to this SedListOfRanges.
   *
   * @param sr the SedRange object to add.
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
   * @see createRange()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addRange(const SedRange* sr);


  /**
   * Get the number of SedRange objects in this SedListOfRanges.
   *
   * @return the number of SedRange objects in this SedListOfRanges.
   *
   * @see addRange(const SedRange* object)
   * @see createRange()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumRanges() const;


  /**
   * Creates a new SedUniformRange object, adds it to this SedListOfRanges
   * object and returns the SedUniformRange object created.
   *
   * @return a new SedUniformRange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedUniformRange* createUniformRange();


  /**
   * Creates a new SedVectorRange object, adds it to this SedListOfRanges
   * object and returns the SedVectorRange object created.
   *
   * @return a new SedVectorRange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedVectorRange* createVectorRange();


  /**
   * Creates a new SedFunctionalRange object, adds it to this SedListOfRanges
   * object and returns the SedFunctionalRange object created.
   *
   * @return a new SedFunctionalRange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedFunctionalRange* createFunctionalRange();


  /**
   * Creates a new SedDataRange object, adds it to this SedListOfRanges object
   * and returns the SedDataRange object created.
   *
   * @return a new SedDataRange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addRange(const SedRange* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumRanges()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedDataRange* createDataRange();


  /**
   * Returns the XML element name of this SedListOfRanges object.
   *
   * For SedListOfRanges, the XML element name is always @c "listOfRanges".
   *
   * @return the name of this element, i.e. @c "listOfRanges".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedListOfRanges object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedListOfRanges object.
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
   * SedListOfRanges object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfRanges:
   * @sedmlconstant{SEDML_RANGE, SedTypeCode_t}.
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
   * Creates a new SedRange in this SedListOfRanges
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
 * Get a SedRange_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedRange_t to
 * retrieve.
 *
 * @return the nth SedRange_t in this SedListOf_t or @c NULL if no such object
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfRanges_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedListOfRanges_getRange(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedRange_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedRange_t to
 * retrieve.
 *
 * @return the SedRange_t in this SedListOf_t with the given @p sid or @c NULL
 * if no such SedRange_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfRanges_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedListOfRanges_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedRange_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedRange_t to remove.
 *
 * @return a pointer to the nth SedRange_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfRanges_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedListOfRanges_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedRange_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedRange_t to remove.
 *
 * @return the SedRange_t in this SedListOf_t based on the identifier or NULL
 * if no such SedRange_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfRanges_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedListOfRanges_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfRanges_H__ */


