/**
 * @file SedRange.h
 * @brief Definition of the SedRange class.
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
 * @class SedRange
 * @sbmlbrief{sedml} TODO:Definition of the SedRange class.
 */


#ifndef SedRange_H__
#define SedRange_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedUniformRange;
class SedVectorRange;
class SedFunctionalRange;
class SedDataRange;

class LIBSEDML_EXTERN SedRange : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mElementName;
  SedAlgorithm* mAlgorithm;

  /** @endcond */

public:

  /**
   * Creates a new SedRange using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedRange.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedRange.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedRange(unsigned int level = SEDML_DEFAULT_LEVEL,
           unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedRange using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedRange(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedRange.
   *
   * @param orig the SedRange instance to copy.
   */
  SedRange(const SedRange& orig);


  /**
   * Assignment operator for SedRange.
   *
   * @param rhs the SedRange object whose values are to be used as the basis of
   * the assignment.
   */
  SedRange& operator=(const SedRange& rhs);


  /**
   * Creates and returns a deep copy of this SedRange object.
   *
   * @return a (deep) copy of this SedRange object.
   */
  virtual SedRange* clone() const;


  /**
   * Destructor for SedRange.
   */
  virtual ~SedRange();


  /**
   * Returns the value of the "algorithm" element of this SedRange.
   *
   * @return the value of the "algorithm" element of this SedRange as a
   * SedAlgorithm*.
   */
  const SedAlgorithm* getAlgorithm() const;


  /**
   * Returns the value of the "algorithm" element of this SedRange.
   *
   * @return the value of the "algorithm" element of this SedRange as a
   * SedAlgorithm*.
   */
  SedAlgorithm* getAlgorithm();


  /**
   * Predicate returning @c true if this SedRange's "algorithm" element is
   * set.
   *
   * @return @c true if this SedRange's "algorithm" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetAlgorithm() const;


  /**
   * Sets the value of the "algorithm" element of this SedRange.
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
   * Creates a new SedAlgorithm object, adds it to this SedRange object
   * and returns the SedAlgorithm object created.
   *
   * @return a new SedAlgorithm object instance.
   */
  SedAlgorithm* createAlgorithm();


  /**
   * Unsets the value of the "algorithm" element of this SedRange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAlgorithm();


  /**
   * Predicate returning @c true if this abstract "SedRange" is of type
   * SedUniformRange
   *
   * @return @c true if this abstract "SedRange" is of type SedUniformRange,
   * @c false otherwise
   */
  virtual bool isSedUniformRange() const;


  /**
   * Predicate returning @c true if this abstract "SedRange" is of type
   * SedVectorRange
   *
   * @return @c true if this abstract "SedRange" is of type SedVectorRange,
   * @c false otherwise
   */
  virtual bool isSedVectorRange() const;


  /**
   * Predicate returning @c true if this abstract "SedRange" is of type
   * SedFunctionalRange
   *
   * @return @c true if this abstract "SedRange" is of type SedFunctionalRange,
   * @c false otherwise
   */
  virtual bool isSedFunctionalRange() const;


  /**
   * Predicate returning @c true if this abstract "SedRange" is of type
   * SedDataRange
   *
   * @return @c true if this abstract "SedRange" is of type SedDataRange,
   * @c false otherwise
   */
  virtual bool isSedDataRange() const;


  /**
   * Returns the XML element name of this SedRange object.
   *
   * For SedRange, the XML element name is always @c "range".
   *
   * @return the name of this element, i.e. @c "range".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedRange object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedRange object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_RANGE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedRange object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedRange have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedRange object are:
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
   * Gets the value of the "attributeName" attribute of this SedRange.
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
   * Gets the value of the "attributeName" attribute of this SedRange.
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
   * Gets the value of the "attributeName" attribute of this SedRange.
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
   * Gets the value of the "attributeName" attribute of this SedRange.
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
   * Gets the value of the "attributeName" attribute of this SedRange.
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
   * Predicate returning @c true if this SedRange's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedRange's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedRange.
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
   * Sets the value of the "attributeName" attribute of this SedRange.
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
   * Sets the value of the "attributeName" attribute of this SedRange.
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
   * Sets the value of the "attributeName" attribute of this SedRange.
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
   * Sets the value of the "attributeName" attribute of this SedRange.
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
   * Unsets the value of the "attributeName" attribute of this SedRange.
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
   * Creates and returns an new "elementName" object in this SedRange.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedRange.
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
   * SedRange.
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
   * Returns the number of "elementName" in this SedRange.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedRange.
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
 * Creates a new SedUniformRange using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedRange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedRange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
SedUniformRange_t *
SedRange_createUniformRange(unsigned int level, unsigned int version);


/**
 * Creates a new SedVectorRange using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedRange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedRange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
SedVectorRange_t *
SedRange_createVectorRange(unsigned int level, unsigned int version);


/**
 * Creates a new SedFunctionalRange using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedRange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedRange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
SedFunctionalRange_t *
SedRange_createFunctionalRange(unsigned int level, unsigned int version);


/**
 * Creates a new SedDataRange using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedRange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedRange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
SedDataRange_t *
SedRange_createDataRange(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedRange_t object.
 *
 * @param sr the SedRange_t structure.
 *
 * @return a (deep) copy of this SedRange_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
SedRange_t*
SedRange_clone(const SedRange_t* sr);


/**
 * Frees this SedRange_t object.
 *
 * @param sr the SedRange_t structure.
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
void
SedRange_free(SedRange_t* sr);


/**
 * Returns the value of the "id" attribute of this SedRange_t.
 *
 * @param sr the SedRange_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedRange_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
char *
SedRange_getId(const SedRange_t * sr);


/**
 * Predicate returning @c 1 (true) if this SedRange_t's "id" attribute is set.
 *
 * @param sr the SedRange_t structure.
 *
 * @return @c 1 (true) if this SedRange_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSetId(const SedRange_t * sr);


/**
 * Sets the value of the "id" attribute of this SedRange_t.
 *
 * @param sr the SedRange_t structure.
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
 * to calling SedRange_unsetId().
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_setId(SedRange_t * sr, const char * id);


/**
 * Unsets the value of the "id" attribute of this SedRange_t.
 *
 * @param sr the SedRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_unsetId(SedRange_t * sr);


/**
 * Returns the value of the "algorithm" element of this SedRange_t.
 *
 * @param ss the SedRange_t structure whose algorithm is sought.
 *
 * @return the value of the "algorithm" element of this SedRange_t as a
 * SedAlgorithm*.
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedRange_getAlgorithm(const SedRange_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedRange_t's "algorithm"
 * element is set.
 *
 * @param ss the SedRange_t structure.
 *
 * @return @c 1 (true) if this SedRange_t's "algorithm" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSetAlgorithm(const SedRange_t * ss);


/**
 * Sets the value of the "algorithm" element of this SedRange_t.
 *
 * @param ss the SedRange_t structure.
 *
 * @param algorithm SedAlgorithm_t* value of the "algorithm" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_setAlgorithm(SedRange_t * ss,
                           const SedAlgorithm_t* algorithm);


/**
 * Creates a new SedAlgorithm_t object, adds it to this SedRange_t object
 * and returns the SedAlgorithm_t object created.
 *
 * @param ss the SedRange_t structure to which the SedAlgorithm_t should
 * be added.
 *
 * @return a new SedAlgorithm_t object instance.
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedRange_createAlgorithm(SedRange_t* ss);


/**
 * Unsets the value of the "algorithm" element of this SedRange_t.
 *
 * @param ss the SedRange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_unsetAlgorithm(SedRange_t * ss);


/**
 * Predicate returning @c 1 if this SedRange_t is of type SedUniformRange_t
 *
 * @param sr the SedRange_t structure.
 *
 * @return @c 1 if this SedRange_t is of type SedUniformRange_t, @c 0 otherwise
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSedUniformRange(const SedRange_t * sr);


/**
 * Predicate returning @c 1 if this SedRange_t is of type SedVectorRange_t
 *
 * @param sr the SedRange_t structure.
 *
 * @return @c 1 if this SedRange_t is of type SedVectorRange_t, @c 0 otherwise
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSedVectorRange(const SedRange_t * sr);


/**
 * Predicate returning @c 1 if this SedRange_t is of type SedFunctionalRange_t
 *
 * @param sr the SedRange_t structure.
 *
 * @return @c 1 if this SedRange_t is of type SedFunctionalRange_t, @c 0
 * otherwise
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSedFunctionalRange(const SedRange_t * sr);


/**
 * Predicate returning @c 1 if this SedRange_t is of type SedDataRange_t
 *
 * @param sr the SedRange_t structure.
 *
 * @return @c 1 if this SedRange_t is of type SedDataRange_t, @c 0 otherwise
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_isSedDataRange(const SedRange_t * sr);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedRange_t object have been set.
 *
 * @param sr the SedRange_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedRange_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedRange_t object are:
 * @li "id"
 *
 * @memberof SedRange_t
 */
LIBSEDML_EXTERN
int
SedRange_hasRequiredAttributes(const SedRange_t * sr);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedRange_H__ */


