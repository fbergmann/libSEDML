/**
 * @file SedAppliedDimension.h
 * @brief Definition of the SedAppliedDimension class.
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
 * @class SedAppliedDimension
 * @sbmlbrief{sedml} TODO:Definition of the SedAppliedDimension class.
 */


#ifndef SedAppliedDimension_H__
#define SedAppliedDimension_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedAppliedDimension : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mTarget;
  std::string mDimensionTarget;

  /** @endcond */

public:

  /**
   * Creates a new SedAppliedDimension using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedAppliedDimension.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedAppliedDimension.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAppliedDimension(unsigned int level = SEDML_DEFAULT_LEVEL,
                        unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedAppliedDimension using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAppliedDimension(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedAppliedDimension.
   *
   * @param orig the SedAppliedDimension instance to copy.
   */
  SedAppliedDimension(const SedAppliedDimension& orig);


  /**
   * Assignment operator for SedAppliedDimension.
   *
   * @param rhs the SedAppliedDimension object whose values are to be used as
   * the basis of the assignment.
   */
  SedAppliedDimension& operator=(const SedAppliedDimension& rhs);


  /**
   * Creates and returns a deep copy of this SedAppliedDimension object.
   *
   * @return a (deep) copy of this SedAppliedDimension object.
   */
  virtual SedAppliedDimension* clone() const;


  /**
   * Destructor for SedAppliedDimension.
   */
  virtual ~SedAppliedDimension();


  /**
   * Returns the value of the "target" attribute of this SedAppliedDimension.
   *
   * @return the value of the "target" attribute of this SedAppliedDimension
   * as a string.
   */
  const std::string& getTarget() const;


  /**
   * Returns the value of the "dimensionTarget" attribute of this
   * SedAppliedDimension.
   *
   * @return the value of the "dimensionTarget" attribute of this
   * SedAppliedDimension as a string.
   */
  const std::string& getDimensionTarget() const;


  /**
   * Predicate returning @c true if this SedAppliedDimension's "target"
   * attribute is set.
   *
   * @return @c true if this SedAppliedDimension's "target" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Predicate returning @c true if this SedAppliedDimension's
   * "dimensionTarget" attribute is set.
   *
   * @return @c true if this SedAppliedDimension's "dimensionTarget"
   * attribute has been set, otherwise @c false is returned.
   */
  bool isSetDimensionTarget() const;


  /**
   * Sets the value of the "target" attribute of this SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * Unsets the value of the "target" attribute of this SedAppliedDimension.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Unsets the value of the "dimensionTarget" attribute of this
   * SedAppliedDimension.
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
   * Returns the XML element name of this SedAppliedDimension object.
   *
   * For SedAppliedDimension, the XML element name is always
   * @c "appliedDimension".
   *
   * @return the name of this element, i.e. @c "appliedDimension".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedAppliedDimension object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_APPLIEDDIMENSION, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedAppliedDimension object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedAppliedDimension have been set, otherwise @c false is returned.
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
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * Predicate returning @c true if this SedAppliedDimension's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedAppliedDimension's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
   * SedAppliedDimension.
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
 * Creates a new SedAppliedDimension_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAppliedDimension_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAppliedDimension_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t *
SedAppliedDimension_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedAppliedDimension_t object.
 *
 * @param srd the SedAppliedDimension_t structure.
 *
 * @return a (deep) copy of this SedAppliedDimension_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
SedAppliedDimension_t*
SedAppliedDimension_clone(const SedAppliedDimension_t* srd);


/**
 * Frees this SedAppliedDimension_t object.
 *
 * @param srd the SedAppliedDimension_t structure.
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
void
SedAppliedDimension_free(SedAppliedDimension_t* srd);


/**
 * Returns the value of the "target" attribute of this SedAppliedDimension_t.
 *
 * @param srd the SedAppliedDimension_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SedAppliedDimension_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
char *
SedAppliedDimension_getTarget(const SedAppliedDimension_t * srd);


/**
 * Returns the value of the "dimensionTarget" attribute of this
 * SedAppliedDimension_t.
 *
 * @param srd the SedAppliedDimension_t structure whose dimensionTarget is
 * sought.
 *
 * @return the value of the "dimensionTarget" attribute of this
 * SedAppliedDimension_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
char *
SedAppliedDimension_getDimensionTarget(const SedAppliedDimension_t * srd);


/**
 * Predicate returning @c 1 (true) if this SedAppliedDimension_t's "target"
 * attribute is set.
 *
 * @param srd the SedAppliedDimension_t structure.
 *
 * @return @c 1 (true) if this SedAppliedDimension_t's "target" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_isSetTarget(const SedAppliedDimension_t * srd);


/**
 * Predicate returning @c 1 (true) if this SedAppliedDimension_t's
 * "dimensionTarget" attribute is set.
 *
 * @param srd the SedAppliedDimension_t structure.
 *
 * @return @c 1 (true) if this SedAppliedDimension_t's "dimensionTarget"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_isSetDimensionTarget(const SedAppliedDimension_t *
  srd);


/**
 * Sets the value of the "target" attribute of this SedAppliedDimension_t.
 *
 * @param srd the SedAppliedDimension_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_setTarget(SedAppliedDimension_t * srd,
                                const char * target);


/**
 * Sets the value of the "dimensionTarget" attribute of this
 * SedAppliedDimension_t.
 *
 * @param srd the SedAppliedDimension_t structure.
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
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_setDimensionTarget(SedAppliedDimension_t * srd,
                                         const char * dimensionTarget);


/**
 * Unsets the value of the "target" attribute of this SedAppliedDimension_t.
 *
 * @param srd the SedAppliedDimension_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_unsetTarget(SedAppliedDimension_t * srd);


/**
 * Unsets the value of the "dimensionTarget" attribute of this
 * SedAppliedDimension_t.
 *
 * @param srd the SedAppliedDimension_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_unsetDimensionTarget(SedAppliedDimension_t * srd);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAppliedDimension_t object have been set.
 *
 * @param srd the SedAppliedDimension_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedAppliedDimension_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAppliedDimension_t
 */
LIBSEDML_EXTERN
int
SedAppliedDimension_hasRequiredAttributes(const SedAppliedDimension_t *
  srd);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedAppliedDimension_H__ */


