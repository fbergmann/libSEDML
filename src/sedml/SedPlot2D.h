/**
 * @file SedPlot2D.h
 * @brief Definition of the SedPlot2D class.
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
 * @class SedPlot2D
 * @sbmlbrief{sedml} TODO:Definition of the SedPlot2D class.
 */


#ifndef SedPlot2D_H__
#define SedPlot2D_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedPlot.h>
#include <sedml/SedAxis.h>
#include <sedml/SedListOfCurves.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedPlot2D : public SedPlot
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  SedListOfCurves mAbstractCurves;
  SedAxis* mRightYAxis;

  /** @endcond */

public:

  /**
   * Creates a new SedPlot2D using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedPlot2D.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedPlot2D.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedPlot2D(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedPlot2D using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedPlot2D(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedPlot2D.
   *
   * @param orig the SedPlot2D instance to copy.
   */
  SedPlot2D(const SedPlot2D& orig);


  /**
   * Assignment operator for SedPlot2D.
   *
   * @param rhs the SedPlot2D object whose values are to be used as the basis
   * of the assignment.
   */
  SedPlot2D& operator=(const SedPlot2D& rhs);


  /**
   * Creates and returns a deep copy of this SedPlot2D object.
   *
   * @return a (deep) copy of this SedPlot2D object.
   */
  virtual SedPlot2D* clone() const;


  /**
   * Destructor for SedPlot2D.
   */
  virtual ~SedPlot2D();


  /**
   * Returns the value of the "rightYAxis" element of this SedPlot2D.
   *
   * @return the value of the "rightYAxis" element of this SedPlot2D as a
   * SedAxis*.
   */
  const SedAxis* getRightYAxis() const;


  /**
   * Returns the value of the "rightYAxis" element of this SedPlot2D.
   *
   * @return the value of the "rightYAxis" element of this SedPlot2D as a
   * SedAxis*.
   */
  SedAxis* getRightYAxis();


  /**
   * Predicate returning @c true if this SedPlot2D's "rightYAxis" element is
   * set.
   *
   * @return @c true if this SedPlot2D's "rightYAxis" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetRightYAxis() const;


  /**
   * Sets the value of the "rightYAxis" element of this SedPlot2D.
   *
   * @param rightYAxis SedAxis* value of the "rightYAxis" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRightYAxis(const SedAxis* rightYAxis);


  /**
   * Creates a new SedAxis object, adds it to this SedPlot2D object and returns
   * the SedAxis object created.
   *
   * @return a new SedAxis object instance.
   */
  SedAxis* createRightYAxis();


  /**
   * Unsets the value of the "rightYAxis" element of this SedPlot2D.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRightYAxis();


  /**
   * Returns the SedListOfCurves from this SedPlot2D.
   *
   * @return the SedListOfCurves from this SedPlot2D.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(const std::string& sid)
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  const SedListOfCurves* getListOfCurves() const;


  /**
   * Returns the SedListOfCurves from this SedPlot2D.
   *
   * @return the SedListOfCurves from this SedPlot2D.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(const std::string& sid)
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  SedListOfCurves* getListOfCurves();


  /**
   * Get a SedAbstractCurve from the SedPlot2D.
   *
   * @param n an unsigned int representing the index of the SedAbstractCurve to
   * retrieve.
   *
   * @return the nth SedAbstractCurve in the SedListOfCurves within this
   * SedPlot2D or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(const std::string& sid)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  SedAbstractCurve* getCurve(unsigned int n);


  /**
   * Get a SedAbstractCurve from the SedPlot2D.
   *
   * @param n an unsigned int representing the index of the SedAbstractCurve to
   * retrieve.
   *
   * @return the nth SedAbstractCurve in the SedListOfCurves within this
   * SedPlot2D or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(const std::string& sid)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  const SedAbstractCurve* getCurve(unsigned int n) const;


  /**
   * Get a SedAbstractCurve from the SedPlot2D based on its identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractCurve to
   * retrieve.
   *
   * @return the SedAbstractCurve in the SedListOfCurves within this SedPlot2D
   * with the given @p sid or @c NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  SedAbstractCurve* getCurve(const std::string& sid);


  /**
   * Get a SedAbstractCurve from the SedPlot2D based on its identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractCurve to
   * retrieve.
   *
   * @return the SedAbstractCurve in the SedListOfCurves within this SedPlot2D
   * with the given @p sid or @c NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  const SedAbstractCurve* getCurve(const std::string& sid) const;


  /**
   * Get a SedAbstractCurve from the SedPlot2D based on the Style to which it
   * refers.
   *
   * @param sid a string representing the "style" attribute of the
   * SedAbstractCurve object to retrieve.
   *
   * @return the first SedAbstractCurve in this SedPlot2D based on the given
   * style attribute or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAbstractCurve* getCurveByStyle(const std::string& sid) const;


  /**
   * Get a SedAbstractCurve from the SedPlot2D based on the Style to which it
   * refers.
   *
   * @param sid a string representing the "style" attribute of the
   * SedAbstractCurve object to retrieve.
   *
   * @return the first SedAbstractCurve in this SedPlot2D based on the given
   * style attribute or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAbstractCurve* getCurveByStyle(const std::string& sid);


  /**
   * Get a SedAbstractCurve from the SedPlot2D based on the XDataReference to
   * which it refers.
   *
   * @param sid a string representing the "xDataReference" attribute of the
   * SedAbstractCurve object to retrieve.
   *
   * @return the first SedAbstractCurve in this SedPlot2D based on the given
   * xDataReference attribute or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAbstractCurve* getCurveByXDataReference(const std::string& sid)
    const;


  /**
   * Get a SedAbstractCurve from the SedPlot2D based on the XDataReference to
   * which it refers.
   *
   * @param sid a string representing the "xDataReference" attribute of the
   * SedAbstractCurve object to retrieve.
   *
   * @return the first SedAbstractCurve in this SedPlot2D based on the given
   * xDataReference attribute or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAbstractCurve* getCurveByXDataReference(const std::string& sid);


  /**
   * Adds a copy of the given SedAbstractCurve to this SedPlot2D.
   *
   * @param sac the SedAbstractCurve object to add.
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
   * @see createCurve()
   * @see getCurve(const std::string& sid)
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  int addCurve(const SedAbstractCurve* sac);


  /**
   * Get the number of SedAbstractCurve objects in this SedPlot2D.
   *
   * @return the number of SedAbstractCurve objects in this SedPlot2D.
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(const std::string& sid)
   * @see getCurve(unsigned int n)
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  unsigned int getNumCurves() const;


  /**
   * Creates a new SedCurve object, adds it to this SedPlot2D object and
   * returns the SedCurve object created.
   *
   * @return a new SedCurve object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see getCurve(const std::string& sid)
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  SedCurve* createCurve();


  /**
   * Creates a new SedShadedArea object, adds it to this SedPlot2D object and
   * returns the SedShadedArea object created.
   *
   * @return a new SedShadedArea object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see getCurve(const std::string& sid)
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   * @see removeCurve(unsigned int n)
   */
  SedShadedArea* createShadedArea();


  /**
   * Removes the nth SedAbstractCurve from this SedPlot2D and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedAbstractCurve to
   * remove.
   *
   * @return a pointer to the nth SedAbstractCurve in this SedPlot2D.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(const std::string& sid)
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(const std::string& sid)
   */
  SedAbstractCurve* removeCurve(unsigned int n);


  /**
   * Removes the SedAbstractCurve from this SedPlot2D based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedAbstractCurve to
   * remove.
   *
   * @return the SedAbstractCurve in this SedPlot2D based on the identifier or
   * NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see getCurve(const std::string& sid)
   * @see getCurve(unsigned int n)
   * @see getNumCurves()
   * @see removeCurve(unsigned int n)
   */
  SedAbstractCurve* removeCurve(const std::string& sid);


  /**
   * Returns the XML element name of this SedPlot2D object.
   *
   * For SedPlot2D, the XML element name is always @c "plot2D".
   *
   * @return the name of this element, i.e. @c "plot2D".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedPlot2D object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_OUTPUT_PLOT2D, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedPlot2D object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedPlot2D have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedPlot2D object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedPlot2D have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedPlot2D object are:
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
   * Gets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Gets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Gets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Gets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Gets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Predicate returning @c true if this SedPlot2D's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedPlot2D's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Sets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Sets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Sets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Sets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Unsets the value of the "attributeName" attribute of this SedPlot2D.
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
   * Creates and returns an new "elementName" object in this SedPlot2D.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedPlot2D.
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
   * SedPlot2D.
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
   * Returns the number of "elementName" in this SedPlot2D.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedPlot2D.
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
 * Creates a new SedPlot2D_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedPlot2D_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedPlot2D_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedPlot2D_t *
SedPlot2D_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedPlot2D_t object.
 *
 * @param spd the SedPlot2D_t structure.
 *
 * @return a (deep) copy of this SedPlot2D_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedPlot2D_t*
SedPlot2D_clone(const SedPlot2D_t* spd);


/**
 * Frees this SedPlot2D_t object.
 *
 * @param spd the SedPlot2D_t structure.
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
void
SedPlot2D_free(SedPlot2D_t* spd);


/**
 * Returns the value of the "rightYAxis" element of this SedPlot2D_t.
 *
 * @param spd the SedPlot2D_t structure whose rightYAxis is sought.
 *
 * @return the value of the "rightYAxis" element of this SedPlot2D_t as a
 * SedAxis*.
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
const SedAxis_t*
SedPlot2D_getRightYAxis(const SedPlot2D_t * spd);


/**
 * Predicate returning @c 1 (true) if this SedPlot2D_t's "rightYAxis" element
 * is set.
 *
 * @param spd the SedPlot2D_t structure.
 *
 * @return @c 1 (true) if this SedPlot2D_t's "rightYAxis" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
int
SedPlot2D_isSetRightYAxis(const SedPlot2D_t * spd);


/**
 * Sets the value of the "rightYAxis" element of this SedPlot2D_t.
 *
 * @param spd the SedPlot2D_t structure.
 *
 * @param rightYAxis SedAxis_t* value of the "rightYAxis" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
int
SedPlot2D_setRightYAxis(SedPlot2D_t * spd, const SedAxis_t* rightYAxis);


/**
 * Creates a new SedAxis_t object, adds it to this SedPlot2D_t object and
 * returns the SedAxis_t object created.
 *
 * @param spd the SedPlot2D_t structure to which the SedAxis_t should be added.
 *
 * @return a new SedAxis_t object instance.
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedAxis_t*
SedPlot2D_createRightYAxis(SedPlot2D_t* spd);


/**
 * Unsets the value of the "rightYAxis" element of this SedPlot2D_t.
 *
 * @param spd the SedPlot2D_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
int
SedPlot2D_unsetRightYAxis(SedPlot2D_t * spd);


/**
 * Returns a ListOf_t * containing SedAbstractCurve_t objects from this
 * SedPlot2D_t.
 *
 * @param spd the SedPlot2D_t structure whose SedListOfCurves is sought.
 *
 * @return the SedListOfCurves from this SedPlot2D_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedPlot2D_addCurve()
 * @see SedPlot2D_createCurve()
 * @see SedPlot2D_getCurveById()
 * @see SedPlot2D_getCurve()
 * @see SedPlot2D_getNumCurves()
 * @see SedPlot2D_removeCurveById()
 * @see SedPlot2D_removeCurve()
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedPlot2D_getListOfCurves(SedPlot2D_t* spd);


/**
 * Get a SedAbstractCurve_t from the SedPlot2D_t.
 *
 * @param spd the SedPlot2D_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractCurve_t to
 * retrieve.
 *
 * @return the nth SedAbstractCurve_t in the SedListOfCurves within this
 * SedPlot2D or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_getCurve(SedPlot2D_t* spd, unsigned int n);


/**
 * Get a SedAbstractCurve_t from the SedPlot2D_t based on its identifier.
 *
 * @param spd the SedPlot2D_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractCurve_t to
 * retrieve.
 *
 * @return the SedAbstractCurve_t in the SedListOfCurves within this SedPlot2D
 * with the given @p sid or @c NULL if no such SedAbstractCurve_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_getCurveById(SedPlot2D_t* spd, const char *sid);


/**
 * Get a SedAbstractCurve_t from the SedPlot2D_t based on the Style to which it
 * refers.
 *
 * @param spd the SedPlot2D_t structure to search.
 *
 * @param sid a string representing the "style" attribute of the
 * SedAbstractCurve_t object to retrieve.
 *
 * @return the first SedAbstractCurve_t in this SedPlot2D_t based on the given
 * style attribute or NULL if no such SedAbstractCurve_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_getCurveByStyle(SedPlot2D_t* spd, const char *sid);


/**
 * Get a SedAbstractCurve_t from the SedPlot2D_t based on the XDataReference to
 * which it refers.
 *
 * @param spd the SedPlot2D_t structure to search.
 *
 * @param sid a string representing the "xDataReference" attribute of the
 * SedAbstractCurve_t object to retrieve.
 *
 * @return the first SedAbstractCurve_t in this SedPlot2D_t based on the given
 * xDataReference attribute or NULL if no such SedAbstractCurve_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_getCurveByXDataReference(SedPlot2D_t* spd, const char *sid);


/**
 * Adds a copy of the given SedAbstractCurve_t to this SedPlot2D_t.
 *
 * @param spd the SedPlot2D_t structure to which the SedAbstractCurve_t should
 * be added.
 *
 * @param sac the SedAbstractCurve_t object to add.
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
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
int
SedPlot2D_addCurve(SedPlot2D_t* spd, const SedAbstractCurve_t* sac);


/**
 * Get the number of SedAbstractCurve_t objects in this SedPlot2D_t.
 *
 * @param spd the SedPlot2D_t structure to query.
 *
 * @return the number of SedAbstractCurve_t objects in this SedPlot2D_t.
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
unsigned int
SedPlot2D_getNumCurves(SedPlot2D_t* spd);


/**
 * Creates a new SedCurve_t object, adds it to this SedPlot2D_t object and
 * returns the SedCurve_t object created.
 *
 * @param spd the SedPlot2D_t structure to which the SedCurve_t should be
 * added.
 *
 * @return a new SedCurve_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedCurve_t*
SedPlot2D_createCurve(SedPlot2D_t* spd);


/**
 * Creates a new SedShadedArea_t object, adds it to this SedPlot2D_t object and
 * returns the SedShadedArea_t object created.
 *
 * @param spd the SedPlot2D_t structure to which the SedShadedArea_t should be
 * added.
 *
 * @return a new SedShadedArea_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedShadedArea_t*
SedPlot2D_createShadedArea(SedPlot2D_t* spd);


/**
 * Removes the nth SedAbstractCurve_t from this SedPlot2D_t and returns a
 * pointer to it.
 *
 * @param spd the SedPlot2D_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractCurve_t to
 * remove.
 *
 * @return a pointer to the nth SedAbstractCurve_t in this SedPlot2D_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_removeCurve(SedPlot2D_t* spd, unsigned int n);


/**
 * Removes the SedAbstractCurve_t from this SedPlot2D_t based on its identifier
 * and returns a pointer to it.
 *
 * @param spd the SedPlot2D_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractCurve_t to
 * remove.
 *
 * @return the SedAbstractCurve_t in this SedPlot2D_t based on the identifier
 * or NULL if no such SedAbstractCurve_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedPlot2D_removeCurveById(SedPlot2D_t* spd, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedPlot2D_t object have been set.
 *
 * @param spd the SedPlot2D_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedPlot2D_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
int
SedPlot2D_hasRequiredAttributes(const SedPlot2D_t * spd);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedPlot2D_t object have been set.
 *
 * @param spd the SedPlot2D_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedPlot2D_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedPlot2D_t object are:
 *
 * @memberof SedPlot2D_t
 */
LIBSEDML_EXTERN
int
SedPlot2D_hasRequiredElements(const SedPlot2D_t * spd);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedPlot2D_H__ */


