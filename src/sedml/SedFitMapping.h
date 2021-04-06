/**
 * @file SedFitMapping.h
 * @brief Definition of the SedFitMapping class.
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
 * @class SedFitMapping
 * @sbmlbrief{sedml} TODO:Definition of the SedFitMapping class.
 */

/**
 * <!-- ~ ~ ~ ~ ~ Start of common documentation strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * The following text is used as common documentation blocks copied multiple
 * times elsewhere in this file. The use of @class is a hack needed because
 * Doxygen's @copydetails command has limited functionality. Symbols
 * beginning with "doc_" are marked as ignored in our Doxygen configuration.
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ -->
 *
 *
 * @class doc_sedfitmapping_type
 *
 * @par
 * The attribute "type" on a SedFitMapping object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sedml specification, the following are the
 * allowable values for "type":
 * <ul>
 * <li> @c "time", TODO:add description
 *
 * <li> @c "experimentalCondition", TODO:add description
 *
 * <li> @c "observable", TODO:add description
 *
 * </ul>
 */


#ifndef SedFitMapping_H__
#define SedFitMapping_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/common/SedmlEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedFitMapping : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mDataSource;
  std::string mTarget;
  MappingType_t mType;
  double mWeight;
  bool mIsSetWeight;
  std::string mPointWeight;

  /** @endcond */

public:

  /**
   * Creates a new SedFitMapping using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedFitMapping.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedFitMapping.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFitMapping(unsigned int level = SEDML_DEFAULT_LEVEL,
                unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedFitMapping using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFitMapping(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedFitMapping.
   *
   * @param orig the SedFitMapping instance to copy.
   */
  SedFitMapping(const SedFitMapping& orig);


  /**
   * Assignment operator for SedFitMapping.
   *
   * @param rhs the SedFitMapping object whose values are to be used as the
   * basis of the assignment.
   */
  SedFitMapping& operator=(const SedFitMapping& rhs);


  /**
   * Creates and returns a deep copy of this SedFitMapping object.
   *
   * @return a (deep) copy of this SedFitMapping object.
   */
  virtual SedFitMapping* clone() const;


  /**
   * Destructor for SedFitMapping.
   */
  virtual ~SedFitMapping();


  /**
   * Returns the value of the "dataSource" attribute of this SedFitMapping.
   *
   * @return the value of the "dataSource" attribute of this SedFitMapping as a
   * string.
   */
  const std::string& getDataSource() const;


  /**
   * Returns the value of the "target" attribute of this SedFitMapping.
   *
   * @return the value of the "target" attribute of this SedFitMapping as a
   * string.
   */
  const std::string& getTarget() const;


  /**
   * Returns the value of the "type" attribute of this SedFitMapping.
   *
   * @return the value of the "type" attribute of this SedFitMapping as a
   * MappingType_t.
   *
   * @copydetails doc_sedfitmapping_type
   * @if clike The value is drawn from the enumeration @ref MappingType_t
   * @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SEDML_MAPPINGTYPE_TIME, MappingType_t}
   * @li @sbmlconstant{SEDML_MAPPINGTYPE_EXPERIMENTALCONDITION, MappingType_t}
   * @li @sbmlconstant{SEDML_MAPPINGTYPE_OBSERVABLE, MappingType_t}
   * @li @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t}
   */
  MappingType_t getType() const;


  /**
   * Returns the value of the "type" attribute of this SedFitMapping.
   *
   * @return the value of the "type" attribute of this SedFitMapping as a
   * string.
   *
   * @copydetails doc_sedfitmapping_type
   * The possible values returned by this method are:
   * @li @c "time"
   * @li @c "experimentalCondition"
   * @li @c "observable"
   * @li @c "invalid MappingType value"
   */
  std::string getTypeAsString() const;


  /**
   * Returns the value of the "weight" attribute of this SedFitMapping.
   *
   * @return the value of the "weight" attribute of this SedFitMapping as a
   * double.
   */
  double getWeight() const;


  /**
   * Returns the value of the "pointWeight" attribute of this SedFitMapping.
   *
   * @return the value of the "pointWeight" attribute of this SedFitMapping as
   * a string.
   */
  const std::string& getPointWeight() const;


  /**
   * Predicate returning @c true if this SedFitMapping's "dataSource" attribute
   * is set.
   *
   * @return @c true if this SedFitMapping's "dataSource" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetDataSource() const;


  /**
   * Predicate returning @c true if this SedFitMapping's "target" attribute is
   * set.
   *
   * @return @c true if this SedFitMapping's "target" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Predicate returning @c true if this SedFitMapping's "type" attribute is
   * set.
   *
   * @return @c true if this SedFitMapping's "type" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sedfitmapping_type
   */
  bool isSetType() const;


  /**
   * Predicate returning @c true if this SedFitMapping's "weight" attribute is
   * set.
   *
   * @return @c true if this SedFitMapping's "weight" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetWeight() const;


  /**
   * Predicate returning @c true if this SedFitMapping's "pointWeight"
   * attribute is set.
   *
   * @return @c true if this SedFitMapping's "pointWeight" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetPointWeight() const;


  /**
   * Sets the value of the "dataSource" attribute of this SedFitMapping.
   *
   * @param dataSource std::string& value of the "dataSource" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDataSource(const std::string& dataSource);


  /**
   * Sets the value of the "target" attribute of this SedFitMapping.
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
   * Sets the value of the "type" attribute of this SedFitMapping.
   *
   * @param type @if clike MappingType_t@else int@endif value of the "type"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedfitmapping_type
   */
  int setType(const MappingType_t type);


  /**
   * Sets the value of the "type" attribute of this SedFitMapping.
   *
   * @param type std::string& of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedfitmapping_type
   */
  int setType(const std::string& type);


  /**
   * Sets the value of the "weight" attribute of this SedFitMapping.
   *
   * @param weight double value of the "weight" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setWeight(double weight);


  /**
   * Sets the value of the "pointWeight" attribute of this SedFitMapping.
   *
   * @param pointWeight std::string& value of the "pointWeight" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPointWeight(const std::string& pointWeight);


  /**
   * Unsets the value of the "dataSource" attribute of this SedFitMapping.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDataSource();


  /**
   * Unsets the value of the "target" attribute of this SedFitMapping.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Unsets the value of the "type" attribute of this SedFitMapping.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sedfitmapping_type
   */
  int unsetType();


  /**
   * Unsets the value of the "weight" attribute of this SedFitMapping.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetWeight();


  /**
   * Unsets the value of the "pointWeight" attribute of this SedFitMapping.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPointWeight();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedFitMapping object.
   *
   * For SedFitMapping, the XML element name is always @c "fitMapping".
   *
   * @return the name of this element, i.e. @c "fitMapping".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedFitMapping object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_FITMAPPING, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedFitMapping object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedFitMapping have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedFitMapping object are:
   * @li "dataSource"
   * @li "target"
   * @li "type"
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
   * Gets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Gets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Gets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Gets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Gets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Predicate returning @c true if this SedFitMapping's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedFitMapping's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Sets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Sets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Sets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Sets the value of the "attributeName" attribute of this SedFitMapping.
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
   * Unsets the value of the "attributeName" attribute of this SedFitMapping.
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
 * Creates a new SedFitMapping_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedFitMapping_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedFitMapping_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
SedFitMapping_t *
SedFitMapping_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedFitMapping_t object.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return a (deep) copy of this SedFitMapping_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
SedFitMapping_t*
SedFitMapping_clone(const SedFitMapping_t* sfm);


/**
 * Frees this SedFitMapping_t object.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
void
SedFitMapping_free(SedFitMapping_t* sfm);


/**
 * Returns the value of the "dataSource" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure whose dataSource is sought.
 *
 * @return the value of the "dataSource" attribute of this SedFitMapping_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getDataSource(const SedFitMapping_t * sfm);


/**
 * Returns the value of the "target" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SedFitMapping_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getTarget(const SedFitMapping_t * sfm);


/**
 * Returns the value of the "type" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedFitMapping_t as a
 * MappingType_t.
 *
 * @copydetails doc_sedfitmapping_type
 * @if clike The value is drawn from the enumeration @ref MappingType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SEDML_MAPPINGTYPE_TIME, MappingType_t}
 * @li @sbmlconstant{SEDML_MAPPINGTYPE_EXPERIMENTALCONDITION, MappingType_t}
 * @li @sbmlconstant{SEDML_MAPPINGTYPE_OBSERVABLE, MappingType_t}
 * @li @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
MappingType_t
SedFitMapping_getType(const SedFitMapping_t * sfm);


/**
 * Returns the value of the "type" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this SedFitMapping_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sedfitmapping_type
 * The possible values returned by this method are:
 * @li @c "time"
 * @li @c "experimentalCondition"
 * @li @c "observable"
 * @li @c "invalid MappingType value"
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getTypeAsString(const SedFitMapping_t * sfm);


/**
 * Returns the value of the "weight" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure whose weight is sought.
 *
 * @return the value of the "weight" attribute of this SedFitMapping_t as a
 * double.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
double
SedFitMapping_getWeight(const SedFitMapping_t * sfm);


/**
 * Returns the value of the "pointWeight" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure whose pointWeight is sought.
 *
 * @return the value of the "pointWeight" attribute of this SedFitMapping_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getPointWeight(const SedFitMapping_t * sfm);


/**
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "dataSource"
 * attribute is set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) if this SedFitMapping_t's "dataSource" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetDataSource(const SedFitMapping_t * sfm);


/**
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "target" attribute
 * is set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) if this SedFitMapping_t's "target" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetTarget(const SedFitMapping_t * sfm);


/**
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "type" attribute
 * is set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) if this SedFitMapping_t's "type" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sedfitmapping_type
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetType(const SedFitMapping_t * sfm);


/**
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "weight" attribute
 * is set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) if this SedFitMapping_t's "weight" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetWeight(const SedFitMapping_t * sfm);


/**
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "pointWeight"
 * attribute is set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) if this SedFitMapping_t's "pointWeight" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetPointWeight(const SedFitMapping_t * sfm);


/**
 * Sets the value of the "dataSource" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @param dataSource const char * value of the "dataSource" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_setDataSource(SedFitMapping_t * sfm, const char * dataSource);


/**
 * Sets the value of the "target" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_setTarget(SedFitMapping_t * sfm, const char * target);


/**
 * Sets the value of the "type" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @param type MappingType_t value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedfitmapping_type
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_setType(SedFitMapping_t * sfm, MappingType_t type);


/**
 * Sets the value of the "type" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @param type const char * of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedfitmapping_type
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_setTypeAsString(SedFitMapping_t * sfm, const char * type);


/**
 * Sets the value of the "weight" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @param weight double value of the "weight" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_setWeight(SedFitMapping_t * sfm, double weight);


/**
 * Sets the value of the "pointWeight" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @param pointWeight const char * value of the "pointWeight" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_setPointWeight(SedFitMapping_t * sfm, const char * pointWeight);


/**
 * Unsets the value of the "dataSource" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetDataSource(SedFitMapping_t * sfm);


/**
 * Unsets the value of the "target" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetTarget(SedFitMapping_t * sfm);


/**
 * Unsets the value of the "type" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedfitmapping_type
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetType(SedFitMapping_t * sfm);


/**
 * Unsets the value of the "weight" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetWeight(SedFitMapping_t * sfm);


/**
 * Unsets the value of the "pointWeight" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_unsetPointWeight(SedFitMapping_t * sfm);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFitMapping_t object have been set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedFitMapping_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedFitMapping_t object are:
 * @li "dataSource"
 * @li "target"
 * @li "type"
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_hasRequiredAttributes(const SedFitMapping_t * sfm);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedFitMapping_H__ */


