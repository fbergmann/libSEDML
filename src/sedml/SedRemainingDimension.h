/**
 * @file SedRemainingDimension.h
 * @brief Definition of the SedRemainingDimension class.
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
 * @class SedRemainingDimension
 * @sbmlbrief{sedml} TODO:Definition of the SedRemainingDimension class.
 */


#ifndef SedRemainingDimension_H__
#define SedRemainingDimension_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedRemainingDimension : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mTarget;
  std::string mDimensionTarget;

  /** @endcond */

public:

  /**
   * Creates a new SedRemainingDimension using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedRemainingDimension.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedRemainingDimension.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedRemainingDimension(unsigned int level = SEDML_DEFAULT_LEVEL,
                        unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedRemainingDimension using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedRemainingDimension(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedRemainingDimension.
   *
   * @param orig the SedRemainingDimension instance to copy.
   */
  SedRemainingDimension(const SedRemainingDimension& orig);


  /**
   * Assignment operator for SedRemainingDimension.
   *
   * @param rhs the SedRemainingDimension object whose values are to be used as
   * the basis of the assignment.
   */
  SedRemainingDimension& operator=(const SedRemainingDimension& rhs);


  /**
   * Creates and returns a deep copy of this SedRemainingDimension object.
   *
   * @return a (deep) copy of this SedRemainingDimension object.
   */
  virtual SedRemainingDimension* clone() const;


  /**
   * Destructor for SedRemainingDimension.
   */
  virtual ~SedRemainingDimension();


  /**
   * Returns the value of the "target" attribute of this SedRemainingDimension.
   *
   * @return the value of the "target" attribute of this SedRemainingDimension
   * as a string.
   */
  const std::string& getTarget() const;


  /**
   * Returns the value of the "dimensionTarget" attribute of this
   * SedRemainingDimension.
   *
   * @return the value of the "dimensionTarget" attribute of this
   * SedRemainingDimension as a string.
   */
  const std::string& getDimensionTarget() const;


  /**
   * Predicate returning @c true if this SedRemainingDimension's "target"
   * attribute is set.
   *
   * @return @c true if this SedRemainingDimension's "target" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Predicate returning @c true if this SedRemainingDimension's
   * "dimensionTarget" attribute is set.
   *
   * @return @c true if this SedRemainingDimension's "dimensionTarget"
   * attribute has been set, otherwise @c false is returned.
   */
  bool isSetDimensionTarget() const;


  /**
   * Sets the value of the "target" attribute of this SedRemainingDimension.
   *
   * @param target std::string& value of the "target" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTarget(const std::string& target);


  /**
   * Sets the value of the "dimensionTarget" attribute of this
   * SedRemainingDimension.
   *
   * @param dimensionTarget std::string& value of the "dimensionTarget"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDimensionTarget(const std::string& dimensionTarget);


  /**
   * Unsets the value of the "target" attribute of this SedRemainingDimension.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Unsets the value of the "dimensionTarget" attribute of this
   * SedRemainingDimension.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDimensionTarget();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedRemainingDimension object.
   *
   * For SedRemainingDimension, the XML element name is always
   * @c "remainingDimension".
   *
   * @return the name of this element, i.e. @c "remainingDimension".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedRemainingDimension object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_REMAININGDIMENSION, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedRemainingDimension object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedRemainingDimension have been set, otherwise @c false is returned.
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
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
   * Predicate returning @c true if this SedRemainingDimension's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedRemainingDimension's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
   * SedRemainingDimension.
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
 * Creates a new SedRemainingDimension_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedRemainingDimension_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedRemainingDimension_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t *
SedRemainingDimension_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedRemainingDimension_t object.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @return a (deep) copy of this SedRemainingDimension_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
SedRemainingDimension_t*
SedRemainingDimension_clone(const SedRemainingDimension_t* srd);


/**
 * Frees this SedRemainingDimension_t object.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
void
SedRemainingDimension_free(SedRemainingDimension_t* srd);


/**
 * Returns the value of the "target" attribute of this SedRemainingDimension_t.
 *
 * @param srd the SedRemainingDimension_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SedRemainingDimension_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
char *
SedRemainingDimension_getTarget(const SedRemainingDimension_t * srd);


/**
 * Returns the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension_t.
 *
 * @param srd the SedRemainingDimension_t structure whose dimensionTarget is
 * sought.
 *
 * @return the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
char *
SedRemainingDimension_getDimensionTarget(const SedRemainingDimension_t * srd);


/**
 * Predicate returning @c 1 (true) if this SedRemainingDimension_t's "target"
 * attribute is set.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @return @c 1 (true) if this SedRemainingDimension_t's "target" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_isSetTarget(const SedRemainingDimension_t * srd);


/**
 * Predicate returning @c 1 (true) if this SedRemainingDimension_t's
 * "dimensionTarget" attribute is set.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @return @c 1 (true) if this SedRemainingDimension_t's "dimensionTarget"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_isSetDimensionTarget(const SedRemainingDimension_t *
  srd);


/**
 * Sets the value of the "target" attribute of this SedRemainingDimension_t.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_setTarget(SedRemainingDimension_t * srd,
                                const char * target);


/**
 * Sets the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension_t.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @param dimensionTarget const char * value of the "dimensionTarget" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_setDimensionTarget(SedRemainingDimension_t * srd,
                                         const char * dimensionTarget);


/**
 * Unsets the value of the "target" attribute of this SedRemainingDimension_t.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_unsetTarget(SedRemainingDimension_t * srd);


/**
 * Unsets the value of the "dimensionTarget" attribute of this
 * SedRemainingDimension_t.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_unsetDimensionTarget(SedRemainingDimension_t * srd);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedRemainingDimension_t object have been set.
 *
 * @param srd the SedRemainingDimension_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedRemainingDimension_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedRemainingDimension_t
 */
LIBSEDML_EXTERN
int
SedRemainingDimension_hasRequiredAttributes(const SedRemainingDimension_t *
  srd);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedRemainingDimension_H__ */


