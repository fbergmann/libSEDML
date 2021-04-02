/**
 * @file SedChangeAttribute.h
 * @brief Definition of the SedChangeAttribute class.
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
 * @class SedChangeAttribute
 * @sbmlbrief{sedml} TODO:Definition of the SedChangeAttribute class.
 */


#ifndef SedChangeAttribute_H__
#define SedChangeAttribute_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedChange.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedChangeAttribute : public SedChange
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mNewValue;

  /** @endcond */

public:

  /**
   * Creates a new SedChangeAttribute using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedChangeAttribute.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedChangeAttribute.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedChangeAttribute(unsigned int level = SEDML_DEFAULT_LEVEL,
                     unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedChangeAttribute using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedChangeAttribute(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedChangeAttribute.
   *
   * @param orig the SedChangeAttribute instance to copy.
   */
  SedChangeAttribute(const SedChangeAttribute& orig);


  /**
   * Assignment operator for SedChangeAttribute.
   *
   * @param rhs the SedChangeAttribute object whose values are to be used as
   * the basis of the assignment.
   */
  SedChangeAttribute& operator=(const SedChangeAttribute& rhs);


  /**
   * Creates and returns a deep copy of this SedChangeAttribute object.
   *
   * @return a (deep) copy of this SedChangeAttribute object.
   */
  virtual SedChangeAttribute* clone() const;


  /**
   * Destructor for SedChangeAttribute.
   */
  virtual ~SedChangeAttribute();


  /**
   * Returns the value of the "newValue" attribute of this SedChangeAttribute.
   *
   * @return the value of the "newValue" attribute of this SedChangeAttribute
   * as a string.
   */
  const std::string& getNewValue() const;


  /**
   * Predicate returning @c true if this SedChangeAttribute's "newValue"
   * attribute is set.
   *
   * @return @c true if this SedChangeAttribute's "newValue" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetNewValue() const;


  /**
   * Sets the value of the "newValue" attribute of this SedChangeAttribute.
   *
   * @param newValue std::string& value of the "newValue" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p newValue = @c NULL or an empty string is
   * equivalent to calling unsetNewValue().
   */
  int setNewValue(const std::string& newValue);


  /**
   * Unsets the value of the "newValue" attribute of this SedChangeAttribute.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNewValue();


  /**
   * Returns the XML element name of this SedChangeAttribute object.
   *
   * For SedChangeAttribute, the XML element name is always
   * @c "changeAttribute".
   *
   * @return the name of this element, i.e. @c "changeAttribute".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedChangeAttribute object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_CHANGE_ATTRIBUTE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedChangeAttribute object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedChangeAttribute have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedChangeAttribute object are:
   * @li "newValue"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Accepts the given SedVisitor
   */
  virtual bool accept(SedVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the parent SedDocument
   */
  virtual void setSedDocument(SedDocument* d);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Predicate returning @c true if this SedChangeAttribute's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedChangeAttribute's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this
   * SedChangeAttribute.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedChangeAttribute_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedChangeAttribute_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedChangeAttribute_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChangeAttribute_t
 */
LIBSEDML_EXTERN
SedChangeAttribute_t *
SedChangeAttribute_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedChangeAttribute_t object.
 *
 * @param sca the SedChangeAttribute_t structure.
 *
 * @return a (deep) copy of this SedChangeAttribute_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChangeAttribute_t
 */
LIBSEDML_EXTERN
SedChangeAttribute_t*
SedChangeAttribute_clone(const SedChangeAttribute_t* sca);


/**
 * Frees this SedChangeAttribute_t object.
 *
 * @param sca the SedChangeAttribute_t structure.
 *
 * @memberof SedChangeAttribute_t
 */
LIBSEDML_EXTERN
void
SedChangeAttribute_free(SedChangeAttribute_t* sca);


/**
 * Returns the value of the "newValue" attribute of this SedChangeAttribute_t.
 *
 * @param sca the SedChangeAttribute_t structure whose newValue is sought.
 *
 * @return the value of the "newValue" attribute of this SedChangeAttribute_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedChangeAttribute_t
 */
LIBSEDML_EXTERN
char *
SedChangeAttribute_getNewValue(const SedChangeAttribute_t * sca);


/**
 * Predicate returning @c 1 (true) if this SedChangeAttribute_t's "newValue"
 * attribute is set.
 *
 * @param sca the SedChangeAttribute_t structure.
 *
 * @return @c 1 (true) if this SedChangeAttribute_t's "newValue" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedChangeAttribute_t
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_isSetNewValue(const SedChangeAttribute_t * sca);


/**
 * Sets the value of the "newValue" attribute of this SedChangeAttribute_t.
 *
 * @param sca the SedChangeAttribute_t structure.
 *
 * @param newValue const char * value of the "newValue" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p newValue = @c NULL or an empty string is
 * equivalent to calling SedChangeAttribute_unsetNewValue().
 *
 * @memberof SedChangeAttribute_t
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_setNewValue(SedChangeAttribute_t * sca,
                               const char * newValue);


/**
 * Unsets the value of the "newValue" attribute of this SedChangeAttribute_t.
 *
 * @param sca the SedChangeAttribute_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedChangeAttribute_t
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_unsetNewValue(SedChangeAttribute_t * sca);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedChangeAttribute_t object have been set.
 *
 * @param sca the SedChangeAttribute_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedChangeAttribute_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedChangeAttribute_t object are:
 * @li "newValue"
 *
 * @memberof SedChangeAttribute_t
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_hasRequiredAttributes(const SedChangeAttribute_t * sca);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedChangeAttribute_H__ */


