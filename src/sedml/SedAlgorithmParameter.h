/**
 * @file SedAlgorithmParameter.h
 * @brief Definition of the SedAlgorithmParameter class.
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
 * @class SedAlgorithmParameter
 * @sbmlbrief{sedml} TODO:Definition of the SedAlgorithmParameter class.
 */


#ifndef SedAlgorithmParameter_H__
#define SedAlgorithmParameter_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedListOfAlgorithmParameters;

class LIBSEDML_EXTERN SedAlgorithmParameter : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mKisaoID;
  std::string mValue;
  SedListOfAlgorithmParameters * mAlgorithmParameters;

  /** @endcond */

public:

  /**
   * Creates a new SedAlgorithmParameter using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedAlgorithmParameter.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedAlgorithmParameter.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAlgorithmParameter(unsigned int level = SEDML_DEFAULT_LEVEL,
                        unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedAlgorithmParameter using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAlgorithmParameter(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedAlgorithmParameter.
   *
   * @param orig the SedAlgorithmParameter instance to copy.
   */
  SedAlgorithmParameter(const SedAlgorithmParameter& orig);


  /**
   * Assignment operator for SedAlgorithmParameter.
   *
   * @param rhs the SedAlgorithmParameter object whose values are to be used as
   * the basis of the assignment.
   */
  SedAlgorithmParameter& operator=(const SedAlgorithmParameter& rhs);


  /**
   * Creates and returns a deep copy of this SedAlgorithmParameter object.
   *
   * @return a (deep) copy of this SedAlgorithmParameter object.
   */
  virtual SedAlgorithmParameter* clone() const;


  /**
   * Destructor for SedAlgorithmParameter.
   */
  virtual ~SedAlgorithmParameter();


  /**
   * Returns the value of the "kisaoID" attribute of this
   * SedAlgorithmParameter.
   *
   * @return the value of the "kisaoID" attribute of this SedAlgorithmParameter
   * as a string.
   */
  const std::string& getKisaoID() const;


  /**
   * Returns the value of the "value" attribute of this SedAlgorithmParameter.
   *
   * @return the value of the "value" attribute of this SedAlgorithmParameter
   * as a string.
   */
  const std::string& getValue() const;


  /**
   * Predicate returning @c true if this SedAlgorithmParameter's "kisaoID"
   * attribute is set.
   *
   * @return @c true if this SedAlgorithmParameter's "kisaoID" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetKisaoID() const;


  /**
   * Predicate returning @c true if this SedAlgorithmParameter's "value"
   * attribute is set.
   *
   * @return @c true if this SedAlgorithmParameter's "value" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetValue() const;


  /**
   * Sets the value of the "kisaoID" attribute of this SedAlgorithmParameter.
   *
   * @param kisaoID std::string& value of the "kisaoID" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p kisaoID = @c NULL or an empty string is
   * equivalent to calling unsetKisaoID().
   */
  int setKisaoID(const std::string& kisaoID);


  /**
   * Sets the value of the "value" attribute of this SedAlgorithmParameter.
   *
   * @param value std::string& value of the "value" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p value = @c NULL or an empty string is
   * equivalent to calling unsetValue().
   */
  int setValue(const std::string& value);


  /**
   * Unsets the value of the "kisaoID" attribute of this SedAlgorithmParameter.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetKisaoID();


  /**
   * Unsets the value of the "value" attribute of this SedAlgorithmParameter.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetValue();


  /**
   * Returns the SedListOfAlgorithmParameters * from this
   * SedAlgorithmParameter.
   *
   * @return the SedListOfAlgorithmParameters * from this
   * SedAlgorithmParameter.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  const SedListOfAlgorithmParameters * getListOfAlgorithmParameters() const;


  /**
   * Returns the SedListOfAlgorithmParameters * from this
   * SedAlgorithmParameter.
   *
   * @return the SedListOfAlgorithmParameters * from this
   * SedAlgorithmParameter.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  SedListOfAlgorithmParameters * getListOfAlgorithmParameters();


  /**
   * Get a SedAlgorithmParameter from the SedAlgorithmParameter.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the nth SedAlgorithmParameter in the SedListOfAlgorithmParameters
   * * within this SedAlgorithmParameter or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  SedAlgorithmParameter* getAlgorithmParameter(unsigned int n);


  /**
   * Get a SedAlgorithmParameter from the SedAlgorithmParameter.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to retrieve.
   *
   * @return the nth SedAlgorithmParameter in the SedListOfAlgorithmParameters
   * * within this SedAlgorithmParameter or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  const SedAlgorithmParameter* getAlgorithmParameter(unsigned int n) const;


  /**
   * Adds a copy of the given SedAlgorithmParameter to this
   * SedAlgorithmParameter.
   *
   * @param sap1 the SedAlgorithmParameter object to add.
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
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  int addAlgorithmParameter(const SedAlgorithmParameter* sap1);


  /**
   * Get the number of SedAlgorithmParameter objects in this
   * SedAlgorithmParameter.
   *
   * @return the number of SedAlgorithmParameter objects in this
   * SedAlgorithmParameter.
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  unsigned int getNumAlgorithmParameters() const;


  /**
   * Creates a new SedAlgorithmParameter object, adds it to this
   * SedAlgorithmParameter object and returns the SedAlgorithmParameter object
   * created.
   *
   * @return a new SedAlgorithmParameter object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   * @see removeAlgorithmParameter(unsigned int n)
   */
  SedAlgorithmParameter* createAlgorithmParameter();


  /**
   * Removes the nth SedAlgorithmParameter from this SedAlgorithmParameter and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * SedAlgorithmParameter to remove.
   *
   * @return a pointer to the nth SedAlgorithmParameter in this
   * SedAlgorithmParameter.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addAlgorithmParameter(const SedAlgorithmParameter* object)
   * @see createAlgorithmParameter()
   * @see getAlgorithmParameter(const std::string& sid)
   * @see getAlgorithmParameter(unsigned int n)
   * @see getNumAlgorithmParameters()
   * @see removeAlgorithmParameter(const std::string& sid)
   */
  SedAlgorithmParameter* removeAlgorithmParameter(unsigned int n);


  /**
   * Returns the XML element name of this SedAlgorithmParameter object.
   *
   * For SedAlgorithmParameter, the XML element name is always
   * @c "algorithmParameter".
   *
   * @return the name of this element, i.e. @c "algorithmParameter".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedAlgorithmParameter object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_SIMULATION_ALGORITHM_PARAMETER, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedAlgorithmParameter object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedAlgorithmParameter have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedAlgorithmParameter object are:
   * @li "kisaoID"
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



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * Predicate returning @c true if this SedAlgorithmParameter's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedAlgorithmParameter's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * Creates and returns an new "elementName" object in this
   * SedAlgorithmParameter.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedAlgorithmParameter.
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
   * SedAlgorithmParameter.
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
   * Returns the number of "elementName" in this SedAlgorithmParameter.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedAlgorithmParameter.
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


public: 

  /**
   * @returns the KisaoTerm as integer if possible or -1 in 
   * case of failure
   */
   int getKisaoIDasInt() const; 
   
   /**
    * Sets the KisaoId as integer
    */ 
   int setKisaoID(int kisaoID);

};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedAlgorithmParameter_t using the given SED-ML Level and @ p
 * version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAlgorithmParameter_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAlgorithmParameter_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedAlgorithmParameter_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedAlgorithmParameter_t object.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @return a (deep) copy of this SedAlgorithmParameter_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithmParameter_clone(const SedAlgorithmParameter_t* sap);


/**
 * Frees this SedAlgorithmParameter_t object.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
void
SedAlgorithmParameter_free(SedAlgorithmParameter_t* sap);


/**
 * Returns the value of the "kisaoID" attribute of this
 * SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure whose kisaoID is sought.
 *
 * @return the value of the "kisaoID" attribute of this SedAlgorithmParameter_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
char *
SedAlgorithmParameter_getKisaoID(const SedAlgorithmParameter_t * sap);


/**
 * Returns the value of the "value" attribute of this SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure whose value is sought.
 *
 * @return the value of the "value" attribute of this SedAlgorithmParameter_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
char *
SedAlgorithmParameter_getValue(const SedAlgorithmParameter_t * sap);


/**
 * Predicate returning @c 1 (true) if this SedAlgorithmParameter_t's "kisaoID"
 * attribute is set.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @return @c 1 (true) if this SedAlgorithmParameter_t's "kisaoID" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_isSetKisaoID(const SedAlgorithmParameter_t * sap);


/**
 * Predicate returning @c 1 (true) if this SedAlgorithmParameter_t's "value"
 * attribute is set.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @return @c 1 (true) if this SedAlgorithmParameter_t's "value" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_isSetValue(const SedAlgorithmParameter_t * sap);


/**
 * Sets the value of the "kisaoID" attribute of this SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @param kisaoID const char * value of the "kisaoID" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p kisaoID = @c NULL or an empty string is
 * equivalent to calling SedAlgorithmParameter_unsetKisaoID().
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_setKisaoID(SedAlgorithmParameter_t * sap,
                                 const char * kisaoID);


/**
 * Sets the value of the "value" attribute of this SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @param value const char * value of the "value" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p value = @c NULL or an empty string is
 * equivalent to calling SedAlgorithmParameter_unsetValue().
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_setValue(SedAlgorithmParameter_t * sap,
                               const char * value);


/**
 * Unsets the value of the "kisaoID" attribute of this SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_unsetKisaoID(SedAlgorithmParameter_t * sap);


/**
 * Unsets the value of the "value" attribute of this SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_unsetValue(SedAlgorithmParameter_t * sap);


/**
 * Returns a ListOf_t * containing SedAlgorithmParameter_t objects from this
 * SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure whose
 * SedListOfAlgorithmParameters * is sought.
 *
 * @return the SedListOfAlgorithmParameters * from this SedAlgorithmParameter_t
 * as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedAlgorithmParameter_addAlgorithmParameter()
 * @see SedAlgorithmParameter_createAlgorithmParameter()
 * @see SedAlgorithmParameter_getAlgorithmParameterById()
 * @see SedAlgorithmParameter_getAlgorithmParameter()
 * @see SedAlgorithmParameter_getNumAlgorithmParameters()
 * @see SedAlgorithmParameter_removeAlgorithmParameterById()
 * @see SedAlgorithmParameter_removeAlgorithmParameter()
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedAlgorithmParameter_getListOfAlgorithmParameters(SedAlgorithmParameter_t*
  sap);


/**
 * Get a SedAlgorithmParameter_t from the SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAlgorithmParameter_t to retrieve.
 *
 * @return the nth SedAlgorithmParameter_t in the SedListOfAlgorithmParameters
 * * within this SedAlgorithmParameter or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithmParameter_getAlgorithmParameter(SedAlgorithmParameter_t* sap,
                                            unsigned int n);


/**
 * Adds a copy of the given SedAlgorithmParameter_t to this
 * SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure to which the
 * SedAlgorithmParameter_t should be added.
 *
 * @param sap1 the SedAlgorithmParameter_t object to add.
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
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_addAlgorithmParameter(SedAlgorithmParameter_t* sap,
                                            const SedAlgorithmParameter_t*
                                              sap1);


/**
 * Get the number of SedAlgorithmParameter_t objects in this
 * SedAlgorithmParameter_t.
 *
 * @param sap the SedAlgorithmParameter_t structure to query.
 *
 * @return the number of SedAlgorithmParameter_t objects in this
 * SedAlgorithmParameter_t.
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
unsigned int
SedAlgorithmParameter_getNumAlgorithmParameters(SedAlgorithmParameter_t* sap);


/**
 * Creates a new SedAlgorithmParameter_t object, adds it to this
 * SedAlgorithmParameter_t object and returns the SedAlgorithmParameter_t
 * object created.
 *
 * @param sap the SedAlgorithmParameter_t structure to which the
 * SedAlgorithmParameter_t should be added.
 *
 * @return a new SedAlgorithmParameter_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithmParameter_createAlgorithmParameter(SedAlgorithmParameter_t* sap);


/**
 * Removes the nth SedAlgorithmParameter_t from this SedAlgorithmParameter_t
 * and returns a pointer to it.
 *
 * @param sap the SedAlgorithmParameter_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * SedAlgorithmParameter_t to remove.
 *
 * @return a pointer to the nth SedAlgorithmParameter_t in this
 * SedAlgorithmParameter_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t*
SedAlgorithmParameter_removeAlgorithmParameter(SedAlgorithmParameter_t* sap,
                                               unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAlgorithmParameter_t object have been set.
 *
 * @param sap the SedAlgorithmParameter_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedAlgorithmParameter_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedAlgorithmParameter_t object are:
 * @li "kisaoID"
 * @li "value"
 *
 * @memberof SedAlgorithmParameter_t
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_hasRequiredAttributes(const SedAlgorithmParameter_t *
  sap);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedAlgorithmParameter_H__ */


