/**
 * @file SedAbstractTask.h
 * @brief Definition of the SedAbstractTask class.
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
 * @class SedAbstractTask
 * @sbmlbrief{sedml} TODO:Definition of the SedAbstractTask class.
 */


#ifndef SedAbstractTask_H__
#define SedAbstractTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedTask;
class SedRepeatedTask;
class SedParameterEstimationTask;

class LIBSEDML_EXTERN SedAbstractTask : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mElementName;
  SedAlgorithm* mAlgorithm;

  /** @endcond */

public:

  /**
   * Creates a new SedAbstractTask using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedAbstractTask.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedAbstractTask.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAbstractTask(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedAbstractTask using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAbstractTask(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedAbstractTask.
   *
   * @param orig the SedAbstractTask instance to copy.
   */
  SedAbstractTask(const SedAbstractTask& orig);


  /**
   * Assignment operator for SedAbstractTask.
   *
   * @param rhs the SedAbstractTask object whose values are to be used as the
   * basis of the assignment.
   */
  SedAbstractTask& operator=(const SedAbstractTask& rhs);


  /**
   * Creates and returns a deep copy of this SedAbstractTask object.
   *
   * @return a (deep) copy of this SedAbstractTask object.
   */
  virtual SedAbstractTask* clone() const;


  /**
   * Destructor for SedAbstractTask.
   */
  virtual ~SedAbstractTask();



  /**
   * Returns the value of the "algorithm" element of this SedAbstractTask.
   *
   * @return the value of the "algorithm" element of this SedAbstractTask as a
   * SedAlgorithm*.
   */
  const SedAlgorithm* getAlgorithm() const;


  /**
   * Returns the value of the "algorithm" element of this SedAbstractTask.
   *
   * @return the value of the "algorithm" element of this SedAbstractTask as a
   * SedAlgorithm*.
   */
  SedAlgorithm* getAlgorithm();


  /**
   * Predicate returning @c true if this SedAbstractTask's "algorithm" element is
   * set.
   *
   * @return @c true if this SedAbstractTask's "algorithm" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetAlgorithm() const;


  /**
   * Sets the value of the "algorithm" element of this SedAbstractTask.
   *
   * @param algorithm SedAlgorithm* value of the "algorithm" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAlgorithm(const SedAlgorithm* algorithm);


  /**
   * Creates a new SedAlgorithm object, adds it to this SedAbstractTask object
   * and returns the SedAlgorithm object created.
   *
   * @return a new SedAlgorithm object instance.
   */
  SedAlgorithm* createAlgorithm();


  /**
   * Unsets the value of the "algorithm" element of this SedAbstractTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAlgorithm();


  /**
   * Predicate returning @c true if this abstract "SedAbstractTask" is of type
   * SedTask
   *
   * @return @c true if this abstract "SedAbstractTask" is of type SedTask,
   * @c false otherwise
   */
  virtual bool isSedTask() const;


  /**
   * Predicate returning @c true if this abstract "SedAbstractTask" is of type
   * SedRepeatedTask
   *
   * @return @c true if this abstract "SedAbstractTask" is of type
   * SedRepeatedTask, @c false otherwise
   */
  virtual bool isSedRepeatedTask() const;


  /**
   * Predicate returning @c true if this abstract "SedAbstractTask" is of type
   * SedParameterEstimationTask
   *
   * @return @c true if this abstract "SedAbstractTask" is of type
   * SedParameterEstimationTask, @c false otherwise
   */
  virtual bool isSedParameterEstimationTask() const;


  /**
   * Returns the XML element name of this SedAbstractTask object.
   *
   * For SedAbstractTask, the XML element name is always @c "task".
   *
   * @return the name of this element, i.e. @c "task".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedAbstractTask object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedAbstractTask object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_SEDML_ABSTRACTTASK, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedAbstractTask object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedAbstractTask have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedAbstractTask object are:
   * @li "id"
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Predicate returning @c true if this SedAbstractTask's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedAbstractTask's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Unsets the value of the "attributeName" attribute of this SedAbstractTask.
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
   * Creates and returns an new "elementName" object in this SedAbstractTask.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedAbstractTask.
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
   * SedAbstractTask.
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
   * Returns the number of "elementName" in this SedAbstractTask.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedAbstractTask.
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
 * Creates a new SedTask using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAbstractTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAbstractTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedTask_t *
SedAbstractTask_createTask(unsigned int level, unsigned int version);


/**
 * Creates a new SedRepeatedTask using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAbstractTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAbstractTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedAbstractTask_createRepeatedTask(unsigned int level, unsigned int version);


/**
 * Creates a new SedParameterEstimationTask using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAbstractTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAbstractTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedParameterEstimationTask_t *
SedAbstractTask_createParameterEstimationTask(unsigned int level,
                                              unsigned int version);


/**
 * Creates and returns a deep copy of this SedAbstractTask_t object.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return a (deep) copy of this SedAbstractTask_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedAbstractTask_clone(const SedAbstractTask_t* sat);


/**
 * Frees this SedAbstractTask_t object.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
void
SedAbstractTask_free(SedAbstractTask_t* sat);


/**
 * Returns the value of the "id" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedAbstractTask_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
char *
SedAbstractTask_getId(const SedAbstractTask_t * sat);


/**
 * Returns the value of the "name" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedAbstractTask_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
char *
SedAbstractTask_getName(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 (true) if this SedAbstractTask_t's "id" attribute
 * is set.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 (true) if this SedAbstractTask_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSetId(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 (true) if this SedAbstractTask_t's "name" attribute
 * is set.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 (true) if this SedAbstractTask_t's "name" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSetName(const SedAbstractTask_t * sat);


/**
 * Sets the value of the "id" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure.
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
 * to calling SedAbstractTask_unsetId().
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_setId(SedAbstractTask_t * sat, const char * id);


/**
 * Sets the value of the "name" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedAbstractTask_unsetName().
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_setName(SedAbstractTask_t * sat, const char * name);


/**
 * Unsets the value of the "id" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_unsetId(SedAbstractTask_t * sat);


/**
 * Unsets the value of the "name" attribute of this SedAbstractTask_t.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_unsetName(SedAbstractTask_t * sat);


/**
 * Returns the value of the "algorithm" element of this SedAbstractTask_t.
 *
 * @param ss the SedAbstractTask_t structure whose algorithm is sought.
 *
 * @return the value of the "algorithm" element of this SedAbstractTask_t as a
 * SedAlgorithm*.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedAbstractTask_getAlgorithm(const SedAbstractTask_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedAbstractTask_t's "algorithm"
 * element is set.
 *
 * @param ss the SedAbstractTask_t structure.
 *
 * @return @c 1 (true) if this SedAbstractTask_t's "algorithm" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSetAlgorithm(const SedAbstractTask_t * ss);


/**
 * Sets the value of the "algorithm" element of this SedAbstractTask_t.
 *
 * @param ss the SedAbstractTask_t structure.
 *
 * @param algorithm SedAlgorithm_t* value of the "algorithm" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_setAlgorithm(SedAbstractTask_t * ss,
                           const SedAlgorithm_t* algorithm);


/**
 * Creates a new SedAlgorithm_t object, adds it to this SedAbstractTask_t object
 * and returns the SedAlgorithm_t object created.
 *
 * @param ss the SedAbstractTask_t structure to which the SedAlgorithm_t should
 * be added.
 *
 * @return a new SedAlgorithm_t object instance.
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedAbstractTask_createAlgorithm(SedAbstractTask_t* ss);


/**
 * Unsets the value of the "algorithm" element of this SedAbstractTask_t.
 *
 * @param ss the SedAbstractTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_unsetAlgorithm(SedAbstractTask_t * ss);


/**
 * Predicate returning @c 1 if this SedAbstractTask_t is of type SedTask_t
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 if this SedAbstractTask_t is of type SedTask_t, @c 0 otherwise
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedTask(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 if this SedAbstractTask_t is of type
 * SedRepeatedTask_t
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 if this SedAbstractTask_t is of type SedRepeatedTask_t, @c 0
 * otherwise
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedRepeatedTask(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 if this SedAbstractTask_t is of type
 * SedParameterEstimationTask_t
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 if this SedAbstractTask_t is of type
 * SedParameterEstimationTask_t, @c 0 otherwise
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_isSedParameterEstimationTask(const SedAbstractTask_t * sat);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAbstractTask_t object have been set.
 *
 * @param sat the SedAbstractTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedAbstractTask_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedAbstractTask_t object are:
 * @li "id"
 *
 * @memberof SedAbstractTask_t
 */
LIBSEDML_EXTERN
int
SedAbstractTask_hasRequiredAttributes(const SedAbstractTask_t * sat);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedAbstractTask_H__ */


