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
 * <li> @c "Variable", TODO:add description
 *
 * <li> @c "Parameter", TODO:add description
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
#include <sedml/SedScaling.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedFitMapping : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mDataSource;
  std::string mDataGenerator;
  MappingType_t mType;
  SedScaling* mScaling;

  /** @endcond */

public:

  /**
   * Creates a new SedFitMapping using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedFitMapping.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
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
   * Returns the value of the "dataGenerator" attribute of this SedFitMapping.
   *
   * @return the value of the "dataGenerator" attribute of this SedFitMapping
   * as a string.
   */
  const std::string& getDataGenerator() const;


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
   * @li @sbmlconstant{SEDML_MAPPINGTYPE_VARIABLE, MappingType_t}
   * @li @sbmlconstant{SEDML_MAPPINGTYPE_PARAMETER, MappingType_t}
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
   * @li @c "Variable"
   * @li @c "Parameter"
   * @li @c "invalid MappingType value"
   */
  std::string getTypeAsString() const;


  /**
   * Predicate returning @c true if this SedFitMapping's "dataSource" attribute
   * is set.
   *
   * @return @c true if this SedFitMapping's "dataSource" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetDataSource() const;


  /**
   * Predicate returning @c true if this SedFitMapping's "dataGenerator"
   * attribute is set.
   *
   * @return @c true if this SedFitMapping's "dataGenerator" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetDataGenerator() const;


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
   * Sets the value of the "dataGenerator" attribute of this SedFitMapping.
   *
   * @param dataGenerator std::string& value of the "dataGenerator" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDataGenerator(const std::string& dataGenerator);


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
   * Unsets the value of the "dataSource" attribute of this SedFitMapping.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDataSource();


  /**
   * Unsets the value of the "dataGenerator" attribute of this SedFitMapping.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDataGenerator();


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
   * Returns the value of the "scaling" element of this SedFitMapping.
   *
   * @return the value of the "scaling" element of this SedFitMapping as a
   * SedScaling*.
   */
  const SedScaling* getScaling() const;


  /**
   * Returns the value of the "scaling" element of this SedFitMapping.
   *
   * @return the value of the "scaling" element of this SedFitMapping as a
   * SedScaling*.
   */
  SedScaling* getScaling();


  /**
   * Predicate returning @c true if this SedFitMapping's "scaling" element is
   * set.
   *
   * @return @c true if this SedFitMapping's "scaling" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetScaling() const;


  /**
   * Sets the value of the "scaling" element of this SedFitMapping.
   *
   * @param scaling SedScaling* value of the "scaling" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setScaling(const SedScaling* scaling);


  /**
   * Creates a new SedValueScaling object, adds it to this SedFitMapping object
   * and returns the SedValueScaling object created.
   *
   * @return a new SedValueScaling object instance.
   */
  SedValueScaling* createValueScaling();


  /**
   * Creates a new SedColumnScaling object, adds it to this SedFitMapping
   * object and returns the SedColumnScaling object created.
   *
   * @return a new SedColumnScaling object instance.
   */
  SedColumnScaling* createColumnScaling();


  /**
   * Unsets the value of the "scaling" element of this SedFitMapping.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetScaling();


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
   * @return the SEDML type code for this object:
   * @sedmlconstant{SEDML_FITMAPPING, SEDMLSedmlTypeCode_t}.
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
   * @li "dataGenerator"
   * @li "type"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedFitMapping object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedFitMapping have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedFitMapping object are:
   * @li "scaling"
   */
  virtual bool hasRequiredElements() const;



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



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

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



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates and returns an new "elementName" object in this SedFitMapping.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedFitMapping.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SedBase* element);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * SedFitMapping.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SedBase* removeChildObject(const std::string& elementName,
                                     const std::string& id);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the number of "elementName" in this SedFitMapping.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedFitMapping.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SedBase* getObject(const std::string& elementName,
                             unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SedBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SedBase* getElementBySId(const std::string& id);


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
 * Creates a new SedFitMapping_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedFitMapping_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
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
 * Returns the value of the "dataGenerator" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure whose dataGenerator is sought.
 *
 * @return the value of the "dataGenerator" attribute of this SedFitMapping_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getDataGenerator(const SedFitMapping_t * sfm);


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
 * @li @sbmlconstant{SEDML_MAPPINGTYPE_VARIABLE, MappingType_t}
 * @li @sbmlconstant{SEDML_MAPPINGTYPE_PARAMETER, MappingType_t}
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
 * @li @c "Variable"
 * @li @c "Parameter"
 * @li @c "invalid MappingType value"
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
char *
SedFitMapping_getTypeAsString(const SedFitMapping_t * sfm);


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
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "dataGenerator"
 * attribute is set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) if this SedFitMapping_t's "dataGenerator" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetDataGenerator(const SedFitMapping_t * sfm);


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
 * Sets the value of the "dataGenerator" attribute of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @param dataGenerator const char * value of the "dataGenerator" attribute to
 * be set.
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
SedFitMapping_setDataGenerator(SedFitMapping_t * sfm,
                               const char * dataGenerator);


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
 * Unsets the value of the "dataGenerator" attribute of this SedFitMapping_t.
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
SedFitMapping_unsetDataGenerator(SedFitMapping_t * sfm);


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
 * Returns the value of the "scaling" element of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure whose scaling is sought.
 *
 * @return the value of the "scaling" element of this SedFitMapping_t as a
 * SedScaling*.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
const SedScaling_t*
SedFitMapping_getScaling(const SedFitMapping_t * sfm);


/**
 * Predicate returning @c 1 (true) if this SedFitMapping_t's "scaling" element
 * is set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) if this SedFitMapping_t's "scaling" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_isSetScaling(const SedFitMapping_t * sfm);


/**
 * Sets the value of the "scaling" element of this SedFitMapping_t.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @param scaling SedScaling_t* value of the "scaling" element to be set.
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
SedFitMapping_setScaling(SedFitMapping_t * sfm, const SedScaling_t* scaling);


/**
 * Creates a new SedValueScaling_t object, adds it to this SedFitMapping_t
 * object and returns the SedValueScaling_t object created.
 *
 * @param sfm the SedFitMapping_t structure to which the SedValueScaling_t
 * should be added.
 *
 * @return a new SedValueScaling_t object instance.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
SedValueScaling_t*
SedFitMapping_createValueScaling(SedFitMapping_t* sfm);


/**
 * Creates a new SedColumnScaling_t object, adds it to this SedFitMapping_t
 * object and returns the SedColumnScaling_t object created.
 *
 * @param sfm the SedFitMapping_t structure to which the SedColumnScaling_t
 * should be added.
 *
 * @return a new SedColumnScaling_t object instance.
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
SedColumnScaling_t*
SedFitMapping_createColumnScaling(SedFitMapping_t* sfm);


/**
 * Unsets the value of the "scaling" element of this SedFitMapping_t.
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
SedFitMapping_unsetScaling(SedFitMapping_t * sfm);


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
 * @li "dataGenerator"
 * @li "type"
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_hasRequiredAttributes(const SedFitMapping_t * sfm);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedFitMapping_t object have been set.
 *
 * @param sfm the SedFitMapping_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedFitMapping_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedFitMapping_t object are:
 * @li "scaling"
 *
 * @memberof SedFitMapping_t
 */
LIBSEDML_EXTERN
int
SedFitMapping_hasRequiredElements(const SedFitMapping_t * sfm);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedFitMapping_H__ */


