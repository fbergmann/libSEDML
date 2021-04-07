/**
 * @file SedPlot.h
 * @brief Definition of the SedPlot class.
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
 * @class SedPlot
 * @sbmlbrief{sedml} TODO:Definition of the SedPlot class.
 */


#ifndef SedPlot_H__
#define SedPlot_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedOutput.h>
#include <sedml/SedAxis.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedPlot : public SedOutput
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  bool mLegend;
  bool mIsSetLegend;
  double mHeight;
  bool mIsSetHeight;
  double mWidth;
  bool mIsSetWidth;
  SedAxis* mXAxis;
  SedAxis* mYAxis;

  /** @endcond */

public:

  /**
   * Creates a new SedPlot using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedPlot.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedPlot.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedPlot(unsigned int level = SEDML_DEFAULT_LEVEL,
          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedPlot using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedPlot(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedPlot.
   *
   * @param orig the SedPlot instance to copy.
   */
  SedPlot(const SedPlot& orig);


  /**
   * Assignment operator for SedPlot.
   *
   * @param rhs the SedPlot object whose values are to be used as the basis of
   * the assignment.
   */
  SedPlot& operator=(const SedPlot& rhs);


  /**
   * Creates and returns a deep copy of this SedPlot object.
   *
   * @return a (deep) copy of this SedPlot object.
   */
  virtual SedPlot* clone() const;


  /**
   * Destructor for SedPlot.
   */
  virtual ~SedPlot();


  /**
   * Returns the value of the "legend" attribute of this SedPlot.
   *
   * @return the value of the "legend" attribute of this SedPlot as a boolean.
   */
  bool getLegend() const;


  /**
   * Returns the value of the "height" attribute of this SedPlot.
   *
   * @return the value of the "height" attribute of this SedPlot as a double.
   */
  double getHeight() const;


  /**
   * Returns the value of the "width" attribute of this SedPlot.
   *
   * @return the value of the "width" attribute of this SedPlot as a double.
   */
  double getWidth() const;


  /**
   * Predicate returning @c true if this SedPlot's "legend" attribute is set.
   *
   * @return @c true if this SedPlot's "legend" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLegend() const;


  /**
   * Predicate returning @c true if this SedPlot's "height" attribute is set.
   *
   * @return @c true if this SedPlot's "height" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetHeight() const;


  /**
   * Predicate returning @c true if this SedPlot's "width" attribute is set.
   *
   * @return @c true if this SedPlot's "width" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetWidth() const;


  /**
   * Sets the value of the "legend" attribute of this SedPlot.
   *
   * @param legend bool value of the "legend" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLegend(bool legend);


  /**
   * Sets the value of the "height" attribute of this SedPlot.
   *
   * @param height double value of the "height" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setHeight(double height);


  /**
   * Sets the value of the "width" attribute of this SedPlot.
   *
   * @param width double value of the "width" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setWidth(double width);


  /**
   * Unsets the value of the "legend" attribute of this SedPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLegend();


  /**
   * Unsets the value of the "height" attribute of this SedPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetHeight();


  /**
   * Unsets the value of the "width" attribute of this SedPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetWidth();


  /**
   * Returns the value of the "xAxis" element of this SedPlot.
   *
   * @return the value of the "xAxis" element of this SedPlot as a SedAxis*.
   */
  const SedAxis* getXAxis() const;


  /**
   * Returns the value of the "xAxis" element of this SedPlot.
   *
   * @return the value of the "xAxis" element of this SedPlot as a SedAxis*.
   */
  SedAxis* getXAxis();


  /**
   * Returns the value of the "yAxis" element of this SedPlot.
   *
   * @return the value of the "yAxis" element of this SedPlot as a SedAxis*.
   */
  const SedAxis* getYAxis() const;


  /**
   * Returns the value of the "yAxis" element of this SedPlot.
   *
   * @return the value of the "yAxis" element of this SedPlot as a SedAxis*.
   */
  SedAxis* getYAxis();


  /**
   * Predicate returning @c true if this SedPlot's "xAxis" element is set.
   *
   * @return @c true if this SedPlot's "xAxis" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetXAxis() const;


  /**
   * Predicate returning @c true if this SedPlot's "yAxis" element is set.
   *
   * @return @c true if this SedPlot's "yAxis" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetYAxis() const;


  /**
   * Sets the value of the "xAxis" element of this SedPlot.
   *
   * @param xAxis SedAxis* value of the "xAxis" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setXAxis(const SedAxis* xAxis);


  /**
   * Sets the value of the "yAxis" element of this SedPlot.
   *
   * @param yAxis SedAxis* value of the "yAxis" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setYAxis(const SedAxis* yAxis);


  /**
   * Creates a new SedAxis object, adds it to this SedPlot object and returns
   * the SedAxis object created.
   *
   * @return a new SedAxis object instance.
   */
  SedAxis* createXAxis();


  /**
   * Creates a new SedAxis object, adds it to this SedPlot object and returns
   * the SedAxis object created.
   *
   * @return a new SedAxis object instance.
   */
  SedAxis* createYAxis();


  /**
   * Unsets the value of the "xAxis" element of this SedPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetXAxis();


  /**
   * Unsets the value of the "yAxis" element of this SedPlot.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetYAxis();


  /**
   * Returns the XML element name of this SedPlot object.
   *
   * For SedPlot, the XML element name is always @c "plot".
   *
   * @return the name of this element, i.e. @c "plot".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedPlot object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_OUTPUT_PLOT, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedPlot object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedPlot have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this SedPlot
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this SedPlot
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedPlot object are:
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
   * Gets the value of the "attributeName" attribute of this SedPlot.
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
   * Gets the value of the "attributeName" attribute of this SedPlot.
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
   * Gets the value of the "attributeName" attribute of this SedPlot.
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
   * Gets the value of the "attributeName" attribute of this SedPlot.
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
   * Gets the value of the "attributeName" attribute of this SedPlot.
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
   * Predicate returning @c true if this SedPlot's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedPlot's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedPlot.
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
   * Sets the value of the "attributeName" attribute of this SedPlot.
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
   * Sets the value of the "attributeName" attribute of this SedPlot.
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
   * Sets the value of the "attributeName" attribute of this SedPlot.
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
   * Sets the value of the "attributeName" attribute of this SedPlot.
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
   * Unsets the value of the "attributeName" attribute of this SedPlot.
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
   * Creates and returns an new "elementName" object in this SedPlot.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedPlot.
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
   * SedPlot.
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
   * Returns the number of "elementName" in this SedPlot.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedPlot.
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
 * Creates a new SedPlot_t using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedPlot_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedPlot_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
SedPlot_t *
SedPlot_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedPlot_t object.
 *
 * @param sp the SedPlot_t structure.
 *
 * @return a (deep) copy of this SedPlot_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
SedPlot_t*
SedPlot_clone(const SedPlot_t* sp);


/**
 * Frees this SedPlot_t object.
 *
 * @param sp the SedPlot_t structure.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
void
SedPlot_free(SedPlot_t* sp);


/**
 * Returns the value of the "legend" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure whose legend is sought.
 *
 * @return the value of the "legend" attribute of this SedPlot_t as a boolean.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_getLegend(const SedPlot_t * sp);


/**
 * Returns the value of the "height" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure whose height is sought.
 *
 * @return the value of the "height" attribute of this SedPlot_t as a double.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
double
SedPlot_getHeight(const SedPlot_t * sp);


/**
 * Returns the value of the "width" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure whose width is sought.
 *
 * @return the value of the "width" attribute of this SedPlot_t as a double.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
double
SedPlot_getWidth(const SedPlot_t * sp);


/**
 * Predicate returning @c 1 (true) if this SedPlot_t's "legend" attribute is
 * set.
 *
 * @param sp the SedPlot_t structure.
 *
 * @return @c 1 (true) if this SedPlot_t's "legend" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_isSetLegend(const SedPlot_t * sp);


/**
 * Predicate returning @c 1 (true) if this SedPlot_t's "height" attribute is
 * set.
 *
 * @param sp the SedPlot_t structure.
 *
 * @return @c 1 (true) if this SedPlot_t's "height" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_isSetHeight(const SedPlot_t * sp);


/**
 * Predicate returning @c 1 (true) if this SedPlot_t's "width" attribute is
 * set.
 *
 * @param sp the SedPlot_t structure.
 *
 * @return @c 1 (true) if this SedPlot_t's "width" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_isSetWidth(const SedPlot_t * sp);


/**
 * Sets the value of the "legend" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @param legend int value of the "legend" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_setLegend(SedPlot_t * sp, int legend);


/**
 * Sets the value of the "height" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @param height double value of the "height" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_setHeight(SedPlot_t * sp, double height);


/**
 * Sets the value of the "width" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @param width double value of the "width" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_setWidth(SedPlot_t * sp, double width);


/**
 * Unsets the value of the "legend" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_unsetLegend(SedPlot_t * sp);


/**
 * Unsets the value of the "height" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_unsetHeight(SedPlot_t * sp);


/**
 * Unsets the value of the "width" attribute of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_unsetWidth(SedPlot_t * sp);


/**
 * Returns the value of the "xAxis" element of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure whose xAxis is sought.
 *
 * @return the value of the "xAxis" element of this SedPlot_t as a SedAxis*.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
const SedAxis_t*
SedPlot_getXAxis(const SedPlot_t * sp);


/**
 * Returns the value of the "yAxis" element of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure whose yAxis is sought.
 *
 * @return the value of the "yAxis" element of this SedPlot_t as a SedAxis*.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
const SedAxis_t*
SedPlot_getYAxis(const SedPlot_t * sp);


/**
 * Predicate returning @c 1 (true) if this SedPlot_t's "xAxis" element is set.
 *
 * @param sp the SedPlot_t structure.
 *
 * @return @c 1 (true) if this SedPlot_t's "xAxis" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_isSetXAxis(const SedPlot_t * sp);


/**
 * Predicate returning @c 1 (true) if this SedPlot_t's "yAxis" element is set.
 *
 * @param sp the SedPlot_t structure.
 *
 * @return @c 1 (true) if this SedPlot_t's "yAxis" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_isSetYAxis(const SedPlot_t * sp);


/**
 * Sets the value of the "xAxis" element of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @param xAxis SedAxis_t* value of the "xAxis" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_setXAxis(SedPlot_t * sp, const SedAxis_t* xAxis);


/**
 * Sets the value of the "yAxis" element of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @param yAxis SedAxis_t* value of the "yAxis" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_setYAxis(SedPlot_t * sp, const SedAxis_t* yAxis);


/**
 * Creates a new SedAxis_t object, adds it to this SedPlot_t object and returns
 * the SedAxis_t object created.
 *
 * @param sp the SedPlot_t structure to which the SedAxis_t should be added.
 *
 * @return a new SedAxis_t object instance.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
SedAxis_t*
SedPlot_createXAxis(SedPlot_t* sp);


/**
 * Creates a new SedAxis_t object, adds it to this SedPlot_t object and returns
 * the SedAxis_t object created.
 *
 * @param sp the SedPlot_t structure to which the SedAxis_t should be added.
 *
 * @return a new SedAxis_t object instance.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
SedAxis_t*
SedPlot_createYAxis(SedPlot_t* sp);


/**
 * Unsets the value of the "xAxis" element of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_unsetXAxis(SedPlot_t * sp);


/**
 * Unsets the value of the "yAxis" element of this SedPlot_t.
 *
 * @param sp the SedPlot_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_unsetYAxis(SedPlot_t * sp);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedPlot_t object have been set.
 *
 * @param sp the SedPlot_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedPlot_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_hasRequiredAttributes(const SedPlot_t * sp);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedPlot_t object have been set.
 *
 * @param sp the SedPlot_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedPlot_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedPlot_t object are:
 *
 * @memberof SedPlot_t
 */
LIBSEDML_EXTERN
int
SedPlot_hasRequiredElements(const SedPlot_t * sp);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedPlot_H__ */


