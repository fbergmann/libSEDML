/**
 * @file SedFigure.h
 * @brief Definition of the SedFigure class.
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
 * @class SedFigure
 * @sbmlbrief{sedml} TODO:Definition of the SedFigure class.
 */


#ifndef SedFigure_H__
#define SedFigure_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedOutput.h>
#include <sedml/SedListOfSubPlots.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedFigure : public SedOutput
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  int mNumRows;
  bool mIsSetNumRows;
  int mNumCols;
  bool mIsSetNumCols;
  SedListOfSubPlots mSubPlots;

  /** @endcond */

public:

  /**
   * Creates a new SedFigure using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedFigure.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedFigure.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFigure(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedFigure using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFigure(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedFigure.
   *
   * @param orig the SedFigure instance to copy.
   */
  SedFigure(const SedFigure& orig);


  /**
   * Assignment operator for SedFigure.
   *
   * @param rhs the SedFigure object whose values are to be used as the basis
   * of the assignment.
   */
  SedFigure& operator=(const SedFigure& rhs);


  /**
   * Creates and returns a deep copy of this SedFigure object.
   *
   * @return a (deep) copy of this SedFigure object.
   */
  virtual SedFigure* clone() const;


  /**
   * Destructor for SedFigure.
   */
  virtual ~SedFigure();


  /**
   * Returns the value of the "numRows" attribute of this SedFigure.
   *
   * @return the value of the "numRows" attribute of this SedFigure as a
   * integer.
   */
  int getNumRows() const;


  /**
   * Returns the value of the "numCols" attribute of this SedFigure.
   *
   * @return the value of the "numCols" attribute of this SedFigure as a
   * integer.
   */
  int getNumCols() const;


  /**
   * Predicate returning @c true if this SedFigure's "numRows" attribute is
   * set.
   *
   * @return @c true if this SedFigure's "numRows" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNumRows() const;


  /**
   * Predicate returning @c true if this SedFigure's "numCols" attribute is
   * set.
   *
   * @return @c true if this SedFigure's "numCols" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNumCols() const;


  /**
   * Sets the value of the "numRows" attribute of this SedFigure.
   *
   * @param numRows int value of the "numRows" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumRows(int numRows);


  /**
   * Sets the value of the "numCols" attribute of this SedFigure.
   *
   * @param numCols int value of the "numCols" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumCols(int numCols);


  /**
   * Unsets the value of the "numRows" attribute of this SedFigure.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumRows();


  /**
   * Unsets the value of the "numCols" attribute of this SedFigure.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumCols();


  /**
   * Returns the SedListOfSubPlots from this SedFigure.
   *
   * @return the SedListOfSubPlots from this SedFigure.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see getSubPlot(const std::string& sid)
   * @see getSubPlot(unsigned int n)
   * @see getNumSubPlots()
   * @see removeSubPlot(const std::string& sid)
   * @see removeSubPlot(unsigned int n)
   */
  const SedListOfSubPlots* getListOfSubPlots() const;


  /**
   * Returns the SedListOfSubPlots from this SedFigure.
   *
   * @return the SedListOfSubPlots from this SedFigure.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see getSubPlot(const std::string& sid)
   * @see getSubPlot(unsigned int n)
   * @see getNumSubPlots()
   * @see removeSubPlot(const std::string& sid)
   * @see removeSubPlot(unsigned int n)
   */
  SedListOfSubPlots* getListOfSubPlots();


  /**
   * Get a SedSubPlot from the SedFigure.
   *
   * @param n an unsigned int representing the index of the SedSubPlot to
   * retrieve.
   *
   * @return the nth SedSubPlot in the SedListOfSubPlots within this SedFigure
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see getSubPlot(const std::string& sid)
   * @see getNumSubPlots()
   * @see removeSubPlot(const std::string& sid)
   * @see removeSubPlot(unsigned int n)
   */
  SedSubPlot* getSubPlot(unsigned int n);


  /**
   * Get a SedSubPlot from the SedFigure.
   *
   * @param n an unsigned int representing the index of the SedSubPlot to
   * retrieve.
   *
   * @return the nth SedSubPlot in the SedListOfSubPlots within this SedFigure
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see getSubPlot(const std::string& sid)
   * @see getNumSubPlots()
   * @see removeSubPlot(const std::string& sid)
   * @see removeSubPlot(unsigned int n)
   */
  const SedSubPlot* getSubPlot(unsigned int n) const;


  /**
   * Get a SedSubPlot from the SedFigure based on the Plot to which it refers.
   *
   * @param sid a string representing the "plot" attribute of the SedSubPlot
   * object to retrieve.
   *
   * @return the first SedSubPlot in this SedFigure based on the given plot
   * attribute or NULL if no such SedSubPlot exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSubPlot* getSubPlotByPlot(const std::string& sid) const;


  /**
   * Get a SedSubPlot from the SedFigure based on the Plot to which it refers.
   *
   * @param sid a string representing the "plot" attribute of the SedSubPlot
   * object to retrieve.
   *
   * @return the first SedSubPlot in this SedFigure based on the given plot
   * attribute or NULL if no such SedSubPlot exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSubPlot* getSubPlotByPlot(const std::string& sid);


  /**
   * Adds a copy of the given SedSubPlot to this SedFigure.
   *
   * @param ssp the SedSubPlot object to add.
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
   * @see createSubPlot()
   * @see getSubPlot(const std::string& sid)
   * @see getSubPlot(unsigned int n)
   * @see getNumSubPlots()
   * @see removeSubPlot(const std::string& sid)
   * @see removeSubPlot(unsigned int n)
   */
  int addSubPlot(const SedSubPlot* ssp);


  /**
   * Get the number of SedSubPlot objects in this SedFigure.
   *
   * @return the number of SedSubPlot objects in this SedFigure.
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see getSubPlot(const std::string& sid)
   * @see getSubPlot(unsigned int n)
   * @see removeSubPlot(const std::string& sid)
   * @see removeSubPlot(unsigned int n)
   */
  unsigned int getNumSubPlots() const;


  /**
   * Creates a new SedSubPlot object, adds it to this SedFigure object and
   * returns the SedSubPlot object created.
   *
   * @return a new SedSubPlot object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see getSubPlot(const std::string& sid)
   * @see getSubPlot(unsigned int n)
   * @see getNumSubPlots()
   * @see removeSubPlot(const std::string& sid)
   * @see removeSubPlot(unsigned int n)
   */
  SedSubPlot* createSubPlot();


  /**
   * Removes the nth SedSubPlot from this SedFigure and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SedSubPlot to
   * remove.
   *
   * @return a pointer to the nth SedSubPlot in this SedFigure.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSubPlot(const SedSubPlot* object)
   * @see createSubPlot()
   * @see getSubPlot(const std::string& sid)
   * @see getSubPlot(unsigned int n)
   * @see getNumSubPlots()
   * @see removeSubPlot(const std::string& sid)
   */
  SedSubPlot* removeSubPlot(unsigned int n);


  /**
   * Returns the XML element name of this SedFigure object.
   *
   * For SedFigure, the XML element name is always @c "figure".
   *
   * @return the name of this element, i.e. @c "figure".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedFigure object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_FIGURE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedFigure object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedFigure have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedFigure object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedFigure have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedFigure object are:
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
   * Gets the value of the "attributeName" attribute of this SedFigure.
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
   * Gets the value of the "attributeName" attribute of this SedFigure.
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
   * Gets the value of the "attributeName" attribute of this SedFigure.
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
   * Gets the value of the "attributeName" attribute of this SedFigure.
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
   * Gets the value of the "attributeName" attribute of this SedFigure.
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
   * Predicate returning @c true if this SedFigure's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedFigure's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedFigure.
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
   * Sets the value of the "attributeName" attribute of this SedFigure.
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
   * Sets the value of the "attributeName" attribute of this SedFigure.
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
   * Sets the value of the "attributeName" attribute of this SedFigure.
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
   * Sets the value of the "attributeName" attribute of this SedFigure.
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
   * Unsets the value of the "attributeName" attribute of this SedFigure.
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
   * Creates and returns an new "elementName" object in this SedFigure.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedFigure.
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
   * SedFigure.
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
   * Returns the number of "elementName" in this SedFigure.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedFigure.
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
 * Creates a new SedFigure_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedFigure_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedFigure_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
SedFigure_t *
SedFigure_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedFigure_t object.
 *
 * @param sf the SedFigure_t structure.
 *
 * @return a (deep) copy of this SedFigure_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
SedFigure_t*
SedFigure_clone(const SedFigure_t* sf);


/**
 * Frees this SedFigure_t object.
 *
 * @param sf the SedFigure_t structure.
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
void
SedFigure_free(SedFigure_t* sf);


/**
 * Returns the value of the "numRows" attribute of this SedFigure_t.
 *
 * @param sf the SedFigure_t structure whose numRows is sought.
 *
 * @return the value of the "numRows" attribute of this SedFigure_t as a
 * integer.
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_getNumRows(const SedFigure_t * sf);


/**
 * Returns the value of the "numCols" attribute of this SedFigure_t.
 *
 * @param sf the SedFigure_t structure whose numCols is sought.
 *
 * @return the value of the "numCols" attribute of this SedFigure_t as a
 * integer.
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_getNumCols(const SedFigure_t * sf);


/**
 * Predicate returning @c 1 (true) if this SedFigure_t's "numRows" attribute is
 * set.
 *
 * @param sf the SedFigure_t structure.
 *
 * @return @c 1 (true) if this SedFigure_t's "numRows" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_isSetNumRows(const SedFigure_t * sf);


/**
 * Predicate returning @c 1 (true) if this SedFigure_t's "numCols" attribute is
 * set.
 *
 * @param sf the SedFigure_t structure.
 *
 * @return @c 1 (true) if this SedFigure_t's "numCols" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_isSetNumCols(const SedFigure_t * sf);


/**
 * Sets the value of the "numRows" attribute of this SedFigure_t.
 *
 * @param sf the SedFigure_t structure.
 *
 * @param numRows int value of the "numRows" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_setNumRows(SedFigure_t * sf, int numRows);


/**
 * Sets the value of the "numCols" attribute of this SedFigure_t.
 *
 * @param sf the SedFigure_t structure.
 *
 * @param numCols int value of the "numCols" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_setNumCols(SedFigure_t * sf, int numCols);


/**
 * Unsets the value of the "numRows" attribute of this SedFigure_t.
 *
 * @param sf the SedFigure_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_unsetNumRows(SedFigure_t * sf);


/**
 * Unsets the value of the "numCols" attribute of this SedFigure_t.
 *
 * @param sf the SedFigure_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_unsetNumCols(SedFigure_t * sf);


/**
 * Returns a ListOf_t * containing SedSubPlot_t objects from this SedFigure_t.
 *
 * @param sf the SedFigure_t structure whose SedListOfSubPlots is sought.
 *
 * @return the SedListOfSubPlots from this SedFigure_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedFigure_addSubPlot()
 * @see SedFigure_createSubPlot()
 * @see SedFigure_getSubPlotById()
 * @see SedFigure_getSubPlot()
 * @see SedFigure_getNumSubPlots()
 * @see SedFigure_removeSubPlotById()
 * @see SedFigure_removeSubPlot()
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedFigure_getListOfSubPlots(SedFigure_t* sf);


/**
 * Get a SedSubPlot_t from the SedFigure_t.
 *
 * @param sf the SedFigure_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSubPlot_t to
 * retrieve.
 *
 * @return the nth SedSubPlot_t in the SedListOfSubPlots within this SedFigure
 * or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedFigure_getSubPlot(SedFigure_t* sf, unsigned int n);


/**
 * Get a SedSubPlot_t from the SedFigure_t based on the Plot to which it
 * refers.
 *
 * @param sf the SedFigure_t structure to search.
 *
 * @param sid a string representing the "plot" attribute of the SedSubPlot_t
 * object to retrieve.
 *
 * @return the first SedSubPlot_t in this SedFigure_t based on the given plot
 * attribute or NULL if no such SedSubPlot_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedFigure_getSubPlotByPlot(SedFigure_t* sf, const char *sid);


/**
 * Adds a copy of the given SedSubPlot_t to this SedFigure_t.
 *
 * @param sf the SedFigure_t structure to which the SedSubPlot_t should be
 * added.
 *
 * @param ssp the SedSubPlot_t object to add.
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
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_addSubPlot(SedFigure_t* sf, const SedSubPlot_t* ssp);


/**
 * Get the number of SedSubPlot_t objects in this SedFigure_t.
 *
 * @param sf the SedFigure_t structure to query.
 *
 * @return the number of SedSubPlot_t objects in this SedFigure_t.
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
unsigned int
SedFigure_getNumSubPlots(SedFigure_t* sf);


/**
 * Creates a new SedSubPlot_t object, adds it to this SedFigure_t object and
 * returns the SedSubPlot_t object created.
 *
 * @param sf the SedFigure_t structure to which the SedSubPlot_t should be
 * added.
 *
 * @return a new SedSubPlot_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedFigure_createSubPlot(SedFigure_t* sf);


/**
 * Removes the nth SedSubPlot_t from this SedFigure_t and returns a pointer to
 * it.
 *
 * @param sf the SedFigure_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSubPlot_t to
 * remove.
 *
 * @return a pointer to the nth SedSubPlot_t in this SedFigure_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedFigure_removeSubPlot(SedFigure_t* sf, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFigure_t object have been set.
 *
 * @param sf the SedFigure_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedFigure_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_hasRequiredAttributes(const SedFigure_t * sf);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedFigure_t object have been set.
 *
 * @param sf the SedFigure_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedFigure_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedFigure_t object are:
 *
 * @memberof SedFigure_t
 */
LIBSEDML_EXTERN
int
SedFigure_hasRequiredElements(const SedFigure_t * sf);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedFigure_H__ */


