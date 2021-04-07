/**
 * @file SedModel.h
 * @brief Definition of the SedModel class.
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
 * @class SedModel
 * @sbmlbrief{sedml} TODO:Definition of the SedModel class.
 */


#ifndef SedModel_H__
#define SedModel_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOfChanges.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedModel : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mLanguage;
  std::string mSource;
  SedListOfChanges mChanges;

  /** @endcond */

public:

  /**
   * Creates a new SedModel using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedModel.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedModel.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedModel(unsigned int level = SEDML_DEFAULT_LEVEL,
           unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedModel using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedModel(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedModel.
   *
   * @param orig the SedModel instance to copy.
   */
  SedModel(const SedModel& orig);


  /**
   * Assignment operator for SedModel.
   *
   * @param rhs the SedModel object whose values are to be used as the basis of
   * the assignment.
   */
  SedModel& operator=(const SedModel& rhs);


  /**
   * Creates and returns a deep copy of this SedModel object.
   *
   * @return a (deep) copy of this SedModel object.
   */
  virtual SedModel* clone() const;


  /**
   * Destructor for SedModel.
   */
  virtual ~SedModel();


  /**
   * Returns the value of the "language" attribute of this SedModel.
   *
   * @return the value of the "language" attribute of this SedModel as a
   * string.
   */
  const std::string& getLanguage() const;


  /**
   * Returns the value of the "source" attribute of this SedModel.
   *
   * @return the value of the "source" attribute of this SedModel as a string.
   */
  const std::string& getSource() const;


  /**
   * Predicate returning @c true if this SedModel's "language" attribute is
   * set.
   *
   * @return @c true if this SedModel's "language" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLanguage() const;


  /**
   * Predicate returning @c true if this SedModel's "source" attribute is set.
   *
   * @return @c true if this SedModel's "source" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSource() const;


  /**
   * Sets the value of the "language" attribute of this SedModel.
   *
   * @param language std::string& value of the "language" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p language = @c NULL or an empty string is
   * equivalent to calling unsetLanguage().
   */
  int setLanguage(const std::string& language);


  /**
   * Sets the value of the "source" attribute of this SedModel.
   *
   * @param source std::string& value of the "source" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p source = @c NULL or an empty string is
   * equivalent to calling unsetSource().
   */
  int setSource(const std::string& source);


  /**
   * Unsets the value of the "language" attribute of this SedModel.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLanguage();


  /**
   * Unsets the value of the "source" attribute of this SedModel.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSource();


  /**
   * Returns the SedListOfChanges from this SedModel.
   *
   * @return the SedListOfChanges from this SedModel.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  const SedListOfChanges* getListOfChanges() const;


  /**
   * Returns the SedListOfChanges from this SedModel.
   *
   * @return the SedListOfChanges from this SedModel.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  SedListOfChanges* getListOfChanges();


  /**
   * Get a SedChange from the SedModel.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * retrieve.
   *
   * @return the nth SedChange in the SedListOfChanges within this SedModel or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see getChange(const std::string& sid)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  SedChange* getChange(unsigned int n);


  /**
   * Get a SedChange from the SedModel.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * retrieve.
   *
   * @return the nth SedChange in the SedListOfChanges within this SedModel or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see getChange(const std::string& sid)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  const SedChange* getChange(unsigned int n) const;


  /**
   * Adds a copy of the given SedChange to this SedModel.
   *
   * @param sc the SedChange object to add.
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
   * @see createChange()
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  int addChange(const SedChange* sc);


  /**
   * Get the number of SedChange objects in this SedModel.
   *
   * @return the number of SedChange objects in this SedModel.
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  unsigned int getNumChanges() const;


  /**
   * Creates a new SedAddXML object, adds it to this SedModel object and
   * returns the SedAddXML object created.
   *
   * @return a new SedAddXML object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  SedAddXML* createAddXML();


  /**
   * Creates a new SedChangeXML object, adds it to this SedModel object and
   * returns the SedChangeXML object created.
   *
   * @return a new SedChangeXML object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  SedChangeXML* createChangeXML();


  /**
   * Creates a new SedRemoveXML object, adds it to this SedModel object and
   * returns the SedRemoveXML object created.
   *
   * @return a new SedRemoveXML object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  SedRemoveXML* createRemoveXML();


  /**
   * Creates a new SedChangeAttribute object, adds it to this SedModel object
   * and returns the SedChangeAttribute object created.
   *
   * @return a new SedChangeAttribute object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  SedChangeAttribute* createChangeAttribute();


  /**
   * Creates a new SedComputeChange object, adds it to this SedModel object and
   * returns the SedComputeChange object created.
   *
   * @return a new SedComputeChange object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   * @see removeChange(unsigned int n)
   */
  SedComputeChange* createComputeChange();


  /**
   * Removes the nth SedChange from this SedModel and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * remove.
   *
   * @return a pointer to the nth SedChange in this SedModel.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addChange(const SedChange* object)
   * @see createChange()
   * @see getChange(const std::string& sid)
   * @see getChange(unsigned int n)
   * @see getNumChanges()
   * @see removeChange(const std::string& sid)
   */
  SedChange* removeChange(unsigned int n);


  /**
   * Returns the XML element name of this SedModel object.
   *
   * For SedModel, the XML element name is always @c "model".
   *
   * @return the name of this element, i.e. @c "model".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedModel object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_MODEL, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedModel object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedModel have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedModel object are:
   * @li "id"
   * @li "source"
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



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Predicate returning @c true if this SedModel's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedModel's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Unsets the value of the "attributeName" attribute of this SedModel.
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
   * Creates and returns an new "elementName" object in this SedModel.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedModel.
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
   * SedModel.
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
   * Returns the number of "elementName" in this SedModel.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedModel.
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


  /**
   * Returns a List of all child SedBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List pointer of pointers to all SedBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(SedElementFilter * filter = NULL);


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
 * Creates a new SedModel_t using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedModel_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedModel_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedModel_t *
SedModel_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedModel_t object.
 *
 * @param sm the SedModel_t structure.
 *
 * @return a (deep) copy of this SedModel_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedModel_clone(const SedModel_t* sm);


/**
 * Frees this SedModel_t object.
 *
 * @param sm the SedModel_t structure.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
void
SedModel_free(SedModel_t* sm);


/**
 * Returns the value of the "id" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedModel_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
char *
SedModel_getId(const SedModel_t * sm);


/**
 * Returns the value of the "name" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedModel_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
char *
SedModel_getName(const SedModel_t * sm);


/**
 * Returns the value of the "language" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure whose language is sought.
 *
 * @return the value of the "language" attribute of this SedModel_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
char *
SedModel_getLanguage(const SedModel_t * sm);


/**
 * Returns the value of the "source" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure whose source is sought.
 *
 * @return the value of the "source" attribute of this SedModel_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
char *
SedModel_getSource(const SedModel_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedModel_t's "id" attribute is set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 (true) if this SedModel_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_isSetId(const SedModel_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedModel_t's "name" attribute is
 * set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 (true) if this SedModel_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_isSetName(const SedModel_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedModel_t's "language" attribute is
 * set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 (true) if this SedModel_t's "language" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_isSetLanguage(const SedModel_t * sm);


/**
 * Predicate returning @c 1 (true) if this SedModel_t's "source" attribute is
 * set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 (true) if this SedModel_t's "source" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_isSetSource(const SedModel_t * sm);


/**
 * Sets the value of the "id" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
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
 * to calling SedModel_unsetId().
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_setId(SedModel_t * sm, const char * id);


/**
 * Sets the value of the "name" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedModel_unsetName().
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_setName(SedModel_t * sm, const char * name);


/**
 * Sets the value of the "language" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @param language const char * value of the "language" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p language = @c NULL or an empty string is
 * equivalent to calling SedModel_unsetLanguage().
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_setLanguage(SedModel_t * sm, const char * language);


/**
 * Sets the value of the "source" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @param source const char * value of the "source" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p source = @c NULL or an empty string is
 * equivalent to calling SedModel_unsetSource().
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_setSource(SedModel_t * sm, const char * source);


/**
 * Unsets the value of the "id" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_unsetId(SedModel_t * sm);


/**
 * Unsets the value of the "name" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_unsetName(SedModel_t * sm);


/**
 * Unsets the value of the "language" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_unsetLanguage(SedModel_t * sm);


/**
 * Unsets the value of the "source" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_unsetSource(SedModel_t * sm);


/**
 * Returns a ListOf_t * containing SedChange_t objects from this SedModel_t.
 *
 * @param sm the SedModel_t structure whose SedListOfChanges is sought.
 *
 * @return the SedListOfChanges from this SedModel_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedModel_addChange()
 * @see SedModel_createChange()
 * @see SedModel_getChangeById()
 * @see SedModel_getChange()
 * @see SedModel_getNumChanges()
 * @see SedModel_removeChangeById()
 * @see SedModel_removeChange()
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedModel_getListOfChanges(SedModel_t* sm);


/**
 * Get a SedChange_t from the SedModel_t.
 *
 * @param sm the SedModel_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedChange_t to
 * retrieve.
 *
 * @return the nth SedChange_t in the SedListOfChanges within this SedModel or
 * @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedChange_t*
SedModel_getChange(SedModel_t* sm, unsigned int n);


/**
 * Adds a copy of the given SedChange_t to this SedModel_t.
 *
 * @param sm the SedModel_t structure to which the SedChange_t should be added.
 *
 * @param sc the SedChange_t object to add.
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
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_addChange(SedModel_t* sm, const SedChange_t* sc);


/**
 * Get the number of SedChange_t objects in this SedModel_t.
 *
 * @param sm the SedModel_t structure to query.
 *
 * @return the number of SedChange_t objects in this SedModel_t.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
unsigned int
SedModel_getNumChanges(SedModel_t* sm);


/**
 * Creates a new SedAddXML_t object, adds it to this SedModel_t object and
 * returns the SedAddXML_t object created.
 *
 * @param sm the SedModel_t structure to which the SedAddXML_t should be added.
 *
 * @return a new SedAddXML_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedAddXML_t*
SedModel_createAddXML(SedModel_t* sm);


/**
 * Creates a new SedChangeXML_t object, adds it to this SedModel_t object and
 * returns the SedChangeXML_t object created.
 *
 * @param sm the SedModel_t structure to which the SedChangeXML_t should be
 * added.
 *
 * @return a new SedChangeXML_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedChangeXML_t*
SedModel_createChangeXML(SedModel_t* sm);


/**
 * Creates a new SedRemoveXML_t object, adds it to this SedModel_t object and
 * returns the SedRemoveXML_t object created.
 *
 * @param sm the SedModel_t structure to which the SedRemoveXML_t should be
 * added.
 *
 * @return a new SedRemoveXML_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedRemoveXML_t*
SedModel_createRemoveXML(SedModel_t* sm);


/**
 * Creates a new SedChangeAttribute_t object, adds it to this SedModel_t object
 * and returns the SedChangeAttribute_t object created.
 *
 * @param sm the SedModel_t structure to which the SedChangeAttribute_t should
 * be added.
 *
 * @return a new SedChangeAttribute_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedChangeAttribute_t*
SedModel_createChangeAttribute(SedModel_t* sm);


/**
 * Creates a new SedComputeChange_t object, adds it to this SedModel_t object
 * and returns the SedComputeChange_t object created.
 *
 * @param sm the SedModel_t structure to which the SedComputeChange_t should be
 * added.
 *
 * @return a new SedComputeChange_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedComputeChange_t*
SedModel_createComputeChange(SedModel_t* sm);


/**
 * Removes the nth SedChange_t from this SedModel_t and returns a pointer to
 * it.
 *
 * @param sm the SedModel_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedChange_t to
 * remove.
 *
 * @return a pointer to the nth SedChange_t in this SedModel_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedChange_t*
SedModel_removeChange(SedModel_t* sm, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedModel_t object have been set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedModel_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedModel_t object are:
 * @li "id"
 * @li "source"
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_hasRequiredAttributes(const SedModel_t * sm);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedModel_H__ */


