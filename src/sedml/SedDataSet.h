/**
 * @file SedDataSet.h
 * @brief Definition of the SedDataSet class.
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
 * @class SedDataSet
 * @sbmlbrief{sedml} TODO:Definition of the SedDataSet class.
 */


#ifndef SedDataSet_H__
#define SedDataSet_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDataSet : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mLabel;
  std::string mDataReference;

  /** @endcond */

public:

  /**
   * Creates a new SedDataSet using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedDataSet.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedDataSet.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDataSet(unsigned int level = SEDML_DEFAULT_LEVEL,
             unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDataSet using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedDataSet(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedDataSet.
   *
   * @param orig the SedDataSet instance to copy.
   */
  SedDataSet(const SedDataSet& orig);


  /**
   * Assignment operator for SedDataSet.
   *
   * @param rhs the SedDataSet object whose values are to be used as the basis
   * of the assignment.
   */
  SedDataSet& operator=(const SedDataSet& rhs);


  /**
   * Creates and returns a deep copy of this SedDataSet object.
   *
   * @return a (deep) copy of this SedDataSet object.
   */
  virtual SedDataSet* clone() const;


  /**
   * Destructor for SedDataSet.
   */
  virtual ~SedDataSet();


  /**
   * Returns the value of the "label" attribute of this SedDataSet.
   *
   * @return the value of the "label" attribute of this SedDataSet as a string.
   */
  const std::string& getLabel() const;


  /**
   * Returns the value of the "dataReference" attribute of this SedDataSet.
   *
   * @return the value of the "dataReference" attribute of this SedDataSet as a
   * string.
   */
  const std::string& getDataReference() const;


  /**
   * Predicate returning @c true if this SedDataSet's "label" attribute is set.
   *
   * @return @c true if this SedDataSet's "label" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLabel() const;


  /**
   * Predicate returning @c true if this SedDataSet's "dataReference" attribute
   * is set.
   *
   * @return @c true if this SedDataSet's "dataReference" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetDataReference() const;


  /**
   * Sets the value of the "label" attribute of this SedDataSet.
   *
   * @param label std::string& value of the "label" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p label = @c NULL or an empty string is
   * equivalent to calling unsetLabel().
   */
  int setLabel(const std::string& label);


  /**
   * Sets the value of the "dataReference" attribute of this SedDataSet.
   *
   * @param dataReference std::string& value of the "dataReference" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDataReference(const std::string& dataReference);


  /**
   * Unsets the value of the "label" attribute of this SedDataSet.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLabel();


  /**
   * Unsets the value of the "dataReference" attribute of this SedDataSet.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDataReference();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedDataSet object.
   *
   * For SedDataSet, the XML element name is always @c "dataSet".
   *
   * @return the name of this element, i.e. @c "dataSet".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedDataSet object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_OUTPUT_DATASET, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedDataSet object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedDataSet have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedDataSet object are:
   * @li "id"
   * @li "label"
   * @li "dataReference"
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
   * Gets the value of the "attributeName" attribute of this SedDataSet.
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
   * Gets the value of the "attributeName" attribute of this SedDataSet.
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
   * Gets the value of the "attributeName" attribute of this SedDataSet.
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
   * Gets the value of the "attributeName" attribute of this SedDataSet.
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
   * Gets the value of the "attributeName" attribute of this SedDataSet.
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
   * Predicate returning @c true if this SedDataSet's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedDataSet's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDataSet.
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
   * Sets the value of the "attributeName" attribute of this SedDataSet.
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
   * Sets the value of the "attributeName" attribute of this SedDataSet.
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
   * Sets the value of the "attributeName" attribute of this SedDataSet.
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
   * Sets the value of the "attributeName" attribute of this SedDataSet.
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
   * Unsets the value of the "attributeName" attribute of this SedDataSet.
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
 * Creates a new SedDataSet_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedDataSet_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedDataSet_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
SedDataSet_t *
SedDataSet_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedDataSet_t object.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @return a (deep) copy of this SedDataSet_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
SedDataSet_t*
SedDataSet_clone(const SedDataSet_t* sds);


/**
 * Frees this SedDataSet_t object.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
void
SedDataSet_free(SedDataSet_t* sds);


/**
 * Returns the value of the "id" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedDataSet_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
char *
SedDataSet_getId(const SedDataSet_t * sds);


/**
 * Returns the value of the "label" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure whose label is sought.
 *
 * @return the value of the "label" attribute of this SedDataSet_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
char *
SedDataSet_getLabel(const SedDataSet_t * sds);


/**
 * Returns the value of the "name" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedDataSet_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
char *
SedDataSet_getName(const SedDataSet_t * sds);


/**
 * Returns the value of the "dataReference" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure whose dataReference is sought.
 *
 * @return the value of the "dataReference" attribute of this SedDataSet_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
char *
SedDataSet_getDataReference(const SedDataSet_t * sds);


/**
 * Predicate returning @c 1 (true) if this SedDataSet_t's "id" attribute is
 * set.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @return @c 1 (true) if this SedDataSet_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetId(const SedDataSet_t * sds);


/**
 * Predicate returning @c 1 (true) if this SedDataSet_t's "label" attribute is
 * set.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @return @c 1 (true) if this SedDataSet_t's "label" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetLabel(const SedDataSet_t * sds);


/**
 * Predicate returning @c 1 (true) if this SedDataSet_t's "name" attribute is
 * set.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @return @c 1 (true) if this SedDataSet_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetName(const SedDataSet_t * sds);


/**
 * Predicate returning @c 1 (true) if this SedDataSet_t's "dataReference"
 * attribute is set.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @return @c 1 (true) if this SedDataSet_t's "dataReference" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetDataReference(const SedDataSet_t * sds);


/**
 * Sets the value of the "id" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure.
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
 * to calling SedDataSet_unsetId().
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_setId(SedDataSet_t * sds, const char * id);


/**
 * Sets the value of the "label" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @param label const char * value of the "label" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p label = @c NULL or an empty string is
 * equivalent to calling SedDataSet_unsetLabel().
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_setLabel(SedDataSet_t * sds, const char * label);


/**
 * Sets the value of the "name" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedDataSet_unsetName().
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_setName(SedDataSet_t * sds, const char * name);


/**
 * Sets the value of the "dataReference" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @param dataReference const char * value of the "dataReference" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_setDataReference(SedDataSet_t * sds, const char * dataReference);


/**
 * Unsets the value of the "id" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetId(SedDataSet_t * sds);


/**
 * Unsets the value of the "label" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetLabel(SedDataSet_t * sds);


/**
 * Unsets the value of the "name" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetName(SedDataSet_t * sds);


/**
 * Unsets the value of the "dataReference" attribute of this SedDataSet_t.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetDataReference(SedDataSet_t * sds);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedDataSet_t object have been set.
 *
 * @param sds the SedDataSet_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedDataSet_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedDataSet_t object are:
 * @li "id"
 * @li "label"
 * @li "dataReference"
 *
 * @memberof SedDataSet_t
 */
LIBSEDML_EXTERN
int
SedDataSet_hasRequiredAttributes(const SedDataSet_t * sds);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedDataSet_H__ */


