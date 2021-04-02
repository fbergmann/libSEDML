/**
 * @file SedListOfStyles.h
 * @brief Definition of the SedListOfStyles class.
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
 * @class SedListOfStyles
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfStyles class.
 */


#ifndef SedListOfStyles_H__
#define SedListOfStyles_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedStyle.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfStyles : public SedListOf
{

public:

  /**
   * Creates a new SedListOfStyles using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfStyles.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfStyles.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfStyles(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfStyles using the given SedNamespaces object @p
   * sedMLns.
   *
   * @param sedMLns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfStyles(SedNamespaces *sedMLns);


  /**
   * Copy constructor for SedListOfStyles.
   *
   * @param orig the SedListOfStyles instance to copy.
   */
  SedListOfStyles(const SedListOfStyles& orig);


  /**
   * Assignment operator for SedListOfStyles.
   *
   * @param rhs the SedListOfStyles object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfStyles& operator=(const SedListOfStyles& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfStyles object.
   *
   * @return a (deep) copy of this SedListOfStyles object.
   */
  virtual SedListOfStyles* clone() const;


  /**
   * Destructor for SedListOfStyles.
   */
  virtual ~SedListOfStyles();


  /**
   * Get a SedStyle from the SedListOfStyles.
   *
   * @param n an unsigned int representing the index of the SedStyle to
   * retrieve.
   *
   * @return the nth SedStyle in this SedListOfStyles or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see get(const std::string& sid)
   * @see getNumStyles()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedStyle* get(unsigned int n);


  /**
   * Get a SedStyle from the SedListOfStyles.
   *
   * @param n an unsigned int representing the index of the SedStyle to
   * retrieve.
   *
   * @return the nth SedStyle in this SedListOfStyles or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see get(const std::string& sid)
   * @see getNumStyles()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedStyle* get(unsigned int n) const;


  /**
   * Get a SedStyle from the SedListOfStyles based on its identifier.
   *
   * @param sid a string representing the identifier of the SedStyle to
   * retrieve.
   *
   * @return the SedStyle in this SedListOfStyles with the given @p sid or
   * @c NULL if no such SedStyle exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see get(unsigned int n)
   * @see getNumStyles()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedStyle* get(const std::string& sid);


  /**
   * Get a SedStyle from the SedListOfStyles based on its identifier.
   *
   * @param sid a string representing the identifier of the SedStyle to
   * retrieve.
   *
   * @return the SedStyle in this SedListOfStyles with the given @p sid or
   * @c NULL if no such SedStyle exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see get(unsigned int n)
   * @see getNumStyles()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedStyle* get(const std::string& sid) const;


  /**
   * Removes the nth SedStyle from this SedListOfStyles and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedStyle to remove.
   *
   * @return a pointer to the nth SedStyle in this SedListOfStyles.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumStyles()
   * @see remove(const std::string& sid)
   */
  virtual SedStyle* remove(unsigned int n);


  /**
   * Removes the SedStyle from this SedListOfStyles based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedStyle to remove.
   *
   * @return the SedStyle in this SedListOfStyles based on the identifier or
   * NULL if no such SedStyle exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumStyles()
   * @see remove(unsigned int n)
   */
  virtual SedStyle* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedStyle to this SedListOfStyles.
   *
   * @param ss the SedStyle object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedMLconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedMLconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sedMLconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sedMLconstant{LIBSEDML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sedMLconstant{LIBSEDML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedMLconstant{LIBSEDML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedMLconstant{LIBSEDML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createStyle()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumStyles()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addStyle(const SedStyle* ss);


  /**
   * Get the number of SedStyle objects in this SedListOfStyles.
   *
   * @return the number of SedStyle objects in this SedListOfStyles.
   *
   * @see addStyle(const SedStyle* object)
   * @see createStyle()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumStyles() const;


  /**
   * Creates a new SedStyle object, adds it to this SedListOfStyles object and
   * returns the SedStyle object created.
   *
   * @return a new SedStyle object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addStyle(const SedStyle* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumStyles()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedStyle* createStyle();


  /**
   * Get a SedStyle from the SedListOfStyles based on the BaseStyle to which it
   * refers.
   *
   * @param sid a string representing the "baseStyle" attribute of the SedStyle
   * object to retrieve.
   *
   * @return the first SedStyle in this SedListOfStyles based on the given
   * baseStyle attribute or NULL if no such SedStyle exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedStyle* getByBaseStyle(const std::string& sid) const;


  /**
   * Get a SedStyle from the SedListOfStyles based on the BaseStyle to which it
   * refers.
   *
   * @param sid a string representing the "baseStyle" attribute of the SedStyle
   * object to retrieve.
   *
   * @return the first SedStyle in this SedListOfStyles based on the given
   * baseStyle attribute or NULL if no such SedStyle exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedStyle* getByBaseStyle(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfStyles object.
   *
   * For SedListOfStyles, the XML element name is always @c "listOfStyles".
   *
   * @return the name of this element, i.e. @c "listOfStyles".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfStyles object.
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
   * SedListOfStyles object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfStyles:
   * @sedmlconstant{SEDML_STYLE, SedTypeCode_t}.
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
   * Creates a new SedStyle in this SedListOfStyles
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
 * Get a SedStyle_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedStyle_t to
 * retrieve.
 *
 * @return the nth SedStyle_t in this SedListOf_t or @c NULL if no such object
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfStyles_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedListOfStyles_getStyle(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedStyle_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedStyle_t to
 * retrieve.
 *
 * @return the SedStyle_t in this SedListOf_t with the given @p sid or @c NULL
 * if no such SedStyle_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfStyles_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedListOfStyles_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedStyle_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedStyle_t to remove.
 *
 * @return a pointer to the nth SedStyle_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfStyles_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedListOfStyles_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedStyle_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedStyle_t to remove.
 *
 * @return the SedStyle_t in this SedListOf_t based on the identifier or NULL
 * if no such SedStyle_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfStyles_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedListOfStyles_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfStyles_H__ */


