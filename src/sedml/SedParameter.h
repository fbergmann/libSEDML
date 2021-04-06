/**
 * @file SedParameter.h
 * @brief Definition of the SedParameter class.
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
 * @class SedParameter
 * @sbmlbrief{sedml} TODO:Definition of the SedParameter class.
 */


#ifndef SedParameter_H__
#define SedParameter_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedParameter : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mValue;
  bool mIsSetValue;

  /** @endcond */

public:

  /**
   * Creates a new SedParameter using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedParameter.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedParameter.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedParameter(unsigned int level = SEDML_DEFAULT_LEVEL,
               unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedParameter using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedParameter(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedParameter.
   *
   * @param orig the SedParameter instance to copy.
   */
  SedParameter(const SedParameter& orig);


  /**
   * Assignment operator for SedParameter.
   *
   * @param rhs the SedParameter object whose values are to be used as the
   * basis of the assignment.
   */
  SedParameter& operator=(const SedParameter& rhs);


  /**
   * Creates and returns a deep copy of this SedParameter object.
   *
   * @return a (deep) copy of this SedParameter object.
   */
  virtual SedParameter* clone() const;


  /**
   * Destructor for SedParameter.
   */
  virtual ~SedParameter();


  /**
   * Returns the value of the "value" attribute of this SedParameter.
   *
   * @return the value of the "value" attribute of this SedParameter as a
   * double.
   */
  double getValue() const;


  /**
   * Predicate returning @c true if this SedParameter's "value" attribute is
   * set.
   *
   * @return @c true if this SedParameter's "value" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetValue() const;


  /**
   * Sets the value of the "value" attribute of this SedParameter.
   *
   * @param value double value of the "value" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setValue(double value);


  /**
   * Unsets the value of the "value" attribute of this SedParameter.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetValue();


  /**
   * Returns the XML element name of this SedParameter object.
   *
   * For SedParameter, the XML element name is always @c "parameter".
   *
   * @return the name of this element, i.e. @c "parameter".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedParameter object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_PARAMETER, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedParameter object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedParameter have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedParameter object are:
   * @li "id"
   * @li "value"
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
   * Gets the value of the "attributeName" attribute of this SedParameter.
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
   * Gets the value of the "attributeName" attribute of this SedParameter.
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
   * Gets the value of the "attributeName" attribute of this SedParameter.
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
   * Gets the value of the "attributeName" attribute of this SedParameter.
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
   * Gets the value of the "attributeName" attribute of this SedParameter.
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
   * Predicate returning @c true if this SedParameter's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedParameter's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedParameter.
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
   * Sets the value of the "attributeName" attribute of this SedParameter.
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
   * Sets the value of the "attributeName" attribute of this SedParameter.
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
   * Sets the value of the "attributeName" attribute of this SedParameter.
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
   * Sets the value of the "attributeName" attribute of this SedParameter.
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
   * Unsets the value of the "attributeName" attribute of this SedParameter.
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
 * Creates a new SedParameter_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedParameter_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedParameter_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
SedParameter_t *
SedParameter_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedParameter_t object.
 *
 * @param sp the SedParameter_t structure.
 *
 * @return a (deep) copy of this SedParameter_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
SedParameter_t*
SedParameter_clone(const SedParameter_t* sp);


/**
 * Frees this SedParameter_t object.
 *
 * @param sp the SedParameter_t structure.
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
void
SedParameter_free(SedParameter_t* sp);


/**
 * Returns the value of the "id" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedParameter_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
char *
SedParameter_getId(const SedParameter_t * sp);


/**
 * Returns the value of the "name" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedParameter_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
char *
SedParameter_getName(const SedParameter_t * sp);


/**
 * Returns the value of the "value" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure whose value is sought.
 *
 * @return the value of the "value" attribute of this SedParameter_t as a
 * double.
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
double
SedParameter_getValue(const SedParameter_t * sp);


/**
 * Predicate returning @c 1 (true) if this SedParameter_t's "id" attribute is
 * set.
 *
 * @param sp the SedParameter_t structure.
 *
 * @return @c 1 (true) if this SedParameter_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_isSetId(const SedParameter_t * sp);


/**
 * Predicate returning @c 1 (true) if this SedParameter_t's "name" attribute is
 * set.
 *
 * @param sp the SedParameter_t structure.
 *
 * @return @c 1 (true) if this SedParameter_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_isSetName(const SedParameter_t * sp);


/**
 * Predicate returning @c 1 (true) if this SedParameter_t's "value" attribute
 * is set.
 *
 * @param sp the SedParameter_t structure.
 *
 * @return @c 1 (true) if this SedParameter_t's "value" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_isSetValue(const SedParameter_t * sp);


/**
 * Sets the value of the "id" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling SedParameter_unsetId().
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_setId(SedParameter_t * sp, const char * id);


/**
 * Sets the value of the "name" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedParameter_unsetName().
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_setName(SedParameter_t * sp, const char * name);


/**
 * Sets the value of the "value" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure.
 *
 * @param value double value of the "value" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_setValue(SedParameter_t * sp, double value);


/**
 * Unsets the value of the "id" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_unsetId(SedParameter_t * sp);


/**
 * Unsets the value of the "name" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_unsetName(SedParameter_t * sp);


/**
 * Unsets the value of the "value" attribute of this SedParameter_t.
 *
 * @param sp the SedParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_unsetValue(SedParameter_t * sp);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedParameter_t object have been set.
 *
 * @param sp the SedParameter_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedParameter_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedParameter_t object are:
 * @li "id"
 * @li "value"
 *
 * @memberof SedParameter_t
 */
LIBSEDML_EXTERN
int
SedParameter_hasRequiredAttributes(const SedParameter_t * sp);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedParameter_H__ */


