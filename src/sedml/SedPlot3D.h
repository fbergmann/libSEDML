/**
 * @file SedPlot3D.h
 * @brief Definition of the SedPlot3D class.
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
 * @class SedPlot3D
 * @sbmlbrief{sedml} TODO:Definition of the SedPlot3D class.
 */


#ifndef SedPlot3D_H__
#define SedPlot3D_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedPlot.h>
#include <sedml/SedAxis.h>
#include <sedml/SedListOfSurfaces.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedPlot3D : public SedPlot
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  SedListOfSurfaces mSurfaces;
  SedAxis* mZAxis;

  /** @endcond */

public:

  /**
   * Creates a new SedPlot3D using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedPlot3D.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedPlot3D.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedPlot3D(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedPlot3D using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedPlot3D(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedPlot3D.
   *
   * @param orig the SedPlot3D instance to copy.
   */
  SedPlot3D(const SedPlot3D& orig);


  /**
   * Assignment operator for SedPlot3D.
   *
   * @param rhs the SedPlot3D object whose values are to be used as the basis
   * of the assignment.
   */
  SedPlot3D& operator=(const SedPlot3D& rhs);


  /**
   * Creates and returns a deep copy of this SedPlot3D object.
   *
   * @return a (deep) copy of this SedPlot3D object.
   */
  virtual SedPlot3D* clone() const;


  /**
   * Destructor for SedPlot3D.
   */
  virtual ~SedPlot3D();


  /**
   * Returns the value of the "zAxis" element of this SedPlot3D.
   *
   * @return the value of the "zAxis" element of this SedPlot3D as a SedAxis*.
   */
  const SedAxis* getZAxis() const;


  /**
   * Returns the value of the "zAxis" element of this SedPlot3D.
   *
   * @return the value of the "zAxis" element of this SedPlot3D as a SedAxis*.
   */
  SedAxis* getZAxis();


  /**
   * Predicate returning @c true if this SedPlot3D's "zAxis" element is set.
   *
   * @return @c true if this SedPlot3D's "zAxis" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetZAxis() const;


  /**
   * Sets the value of the "zAxis" element of this SedPlot3D.
   *
   * @param zAxis SedAxis* value of the "zAxis" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setZAxis(const SedAxis* zAxis);


  /**
   * Creates a new SedAxis object, adds it to this SedPlot3D object and returns
   * the SedAxis object created.
   *
   * @return a new SedAxis object instance.
   */
  SedAxis* createZAxis();


  /**
   * Unsets the value of the "zAxis" element of this SedPlot3D.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetZAxis();


  /**
   * Returns the SedListOfSurfaces from this SedPlot3D.
   *
   * @return the SedListOfSurfaces from this SedPlot3D.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(const std::string& sid)
   * @see getSurface(unsigned int n)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  const SedListOfSurfaces* getListOfSurfaces() const;


  /**
   * Returns the SedListOfSurfaces from this SedPlot3D.
   *
   * @return the SedListOfSurfaces from this SedPlot3D.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(const std::string& sid)
   * @see getSurface(unsigned int n)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  SedListOfSurfaces* getListOfSurfaces();


  /**
   * Get a SedSurface from the SedPlot3D.
   *
   * @param n an unsigned int representing the index of the SedSurface to
   * retrieve.
   *
   * @return the nth SedSurface in the SedListOfSurfaces within this SedPlot3D
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(const std::string& sid)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  SedSurface* getSurface(unsigned int n);


  /**
   * Get a SedSurface from the SedPlot3D.
   *
   * @param n an unsigned int representing the index of the SedSurface to
   * retrieve.
   *
   * @return the nth SedSurface in the SedListOfSurfaces within this SedPlot3D
   * or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(const std::string& sid)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  const SedSurface* getSurface(unsigned int n) const;


  /**
   * Get a SedSurface from the SedPlot3D based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSurface to
   * retrieve.
   *
   * @return the SedSurface in the SedListOfSurfaces within this SedPlot3D with
   * the given @p sid or @c NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(unsigned int n)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  SedSurface* getSurface(const std::string& sid);


  /**
   * Get a SedSurface from the SedPlot3D based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSurface to
   * retrieve.
   *
   * @return the SedSurface in the SedListOfSurfaces within this SedPlot3D with
   * the given @p sid or @c NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(unsigned int n)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  const SedSurface* getSurface(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedPlot3D based on the XDataReference to which
   * it refers.
   *
   * @param sid a string representing the "xDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedPlot3D based on the given
   * xDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSurface* getSurfaceByXDataReference(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedPlot3D based on the XDataReference to which
   * it refers.
   *
   * @param sid a string representing the "xDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedPlot3D based on the given
   * xDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSurface* getSurfaceByXDataReference(const std::string& sid);


  /**
   * Get a SedSurface from the SedPlot3D based on the YDataReference to which
   * it refers.
   *
   * @param sid a string representing the "yDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedPlot3D based on the given
   * yDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSurface* getSurfaceByYDataReference(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedPlot3D based on the YDataReference to which
   * it refers.
   *
   * @param sid a string representing the "yDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedPlot3D based on the given
   * yDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSurface* getSurfaceByYDataReference(const std::string& sid);


  /**
   * Get a SedSurface from the SedPlot3D based on the ZDataReference to which
   * it refers.
   *
   * @param sid a string representing the "zDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedPlot3D based on the given
   * zDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSurface* getSurfaceByZDataReference(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedPlot3D based on the ZDataReference to which
   * it refers.
   *
   * @param sid a string representing the "zDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedPlot3D based on the given
   * zDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSurface* getSurfaceByZDataReference(const std::string& sid);


  /**
   * Get a SedSurface from the SedPlot3D based on the Style to which it refers.
   *
   * @param sid a string representing the "style" attribute of the SedSurface
   * object to retrieve.
   *
   * @return the first SedSurface in this SedPlot3D based on the given style
   * attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSurface* getSurfaceByStyle(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedPlot3D based on the Style to which it refers.
   *
   * @param sid a string representing the "style" attribute of the SedSurface
   * object to retrieve.
   *
   * @return the first SedSurface in this SedPlot3D based on the given style
   * attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSurface* getSurfaceByStyle(const std::string& sid);


  /**
   * Adds a copy of the given SedSurface to this SedPlot3D.
   *
   * @param ss the SedSurface object to add.
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
   * @see createSurface()
   * @see getSurface(const std::string& sid)
   * @see getSurface(unsigned int n)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  int addSurface(const SedSurface* ss);


  /**
   * Get the number of SedSurface objects in this SedPlot3D.
   *
   * @return the number of SedSurface objects in this SedPlot3D.
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(const std::string& sid)
   * @see getSurface(unsigned int n)
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  unsigned int getNumSurfaces() const;


  /**
   * Creates a new SedSurface object, adds it to this SedPlot3D object and
   * returns the SedSurface object created.
   *
   * @return a new SedSurface object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see getSurface(const std::string& sid)
   * @see getSurface(unsigned int n)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   * @see removeSurface(unsigned int n)
   */
  SedSurface* createSurface();


  /**
   * Removes the nth SedSurface from this SedPlot3D and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SedSurface to
   * remove.
   *
   * @return a pointer to the nth SedSurface in this SedPlot3D.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(const std::string& sid)
   * @see getSurface(unsigned int n)
   * @see getNumSurfaces()
   * @see removeSurface(const std::string& sid)
   */
  SedSurface* removeSurface(unsigned int n);


  /**
   * Removes the SedSurface from this SedPlot3D based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedSurface to
   * remove.
   *
   * @return the SedSurface in this SedPlot3D based on the identifier or NULL
   * if no such SedSurface exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see getSurface(const std::string& sid)
   * @see getSurface(unsigned int n)
   * @see getNumSurfaces()
   * @see removeSurface(unsigned int n)
   */
  SedSurface* removeSurface(const std::string& sid);


  /**
   * Returns the XML element name of this SedPlot3D object.
   *
   * For SedPlot3D, the XML element name is always @c "plot3D".
   *
   * @return the name of this element, i.e. @c "plot3D".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedPlot3D object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_OUTPUT_PLOT3D, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedPlot3D object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedPlot3D have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedPlot3D object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedPlot3D have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedPlot3D object are:
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
   * Gets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Gets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Gets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Gets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Gets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Predicate returning @c true if this SedPlot3D's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedPlot3D's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Sets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Sets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Sets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Sets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Unsets the value of the "attributeName" attribute of this SedPlot3D.
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
   * Creates and returns an new "elementName" object in this SedPlot3D.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedPlot3D.
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
   * SedPlot3D.
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
   * Returns the number of "elementName" in this SedPlot3D.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedPlot3D.
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
 * Creates a new SedPlot3D_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedPlot3D_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedPlot3D_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedPlot3D_t *
SedPlot3D_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedPlot3D_t object.
 *
 * @param spd the SedPlot3D_t structure.
 *
 * @return a (deep) copy of this SedPlot3D_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedPlot3D_t*
SedPlot3D_clone(const SedPlot3D_t* spd);


/**
 * Frees this SedPlot3D_t object.
 *
 * @param spd the SedPlot3D_t structure.
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
void
SedPlot3D_free(SedPlot3D_t* spd);


/**
 * Returns the value of the "zAxis" element of this SedPlot3D_t.
 *
 * @param spd the SedPlot3D_t structure whose zAxis is sought.
 *
 * @return the value of the "zAxis" element of this SedPlot3D_t as a SedAxis*.
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
const SedAxis_t*
SedPlot3D_getZAxis(const SedPlot3D_t * spd);


/**
 * Predicate returning @c 1 (true) if this SedPlot3D_t's "zAxis" element is
 * set.
 *
 * @param spd the SedPlot3D_t structure.
 *
 * @return @c 1 (true) if this SedPlot3D_t's "zAxis" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
int
SedPlot3D_isSetZAxis(const SedPlot3D_t * spd);


/**
 * Sets the value of the "zAxis" element of this SedPlot3D_t.
 *
 * @param spd the SedPlot3D_t structure.
 *
 * @param zAxis SedAxis_t* value of the "zAxis" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
int
SedPlot3D_setZAxis(SedPlot3D_t * spd, const SedAxis_t* zAxis);


/**
 * Creates a new SedAxis_t object, adds it to this SedPlot3D_t object and
 * returns the SedAxis_t object created.
 *
 * @param spd the SedPlot3D_t structure to which the SedAxis_t should be added.
 *
 * @return a new SedAxis_t object instance.
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedAxis_t*
SedPlot3D_createZAxis(SedPlot3D_t* spd);


/**
 * Unsets the value of the "zAxis" element of this SedPlot3D_t.
 *
 * @param spd the SedPlot3D_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
int
SedPlot3D_unsetZAxis(SedPlot3D_t * spd);


/**
 * Returns a ListOf_t * containing SedSurface_t objects from this SedPlot3D_t.
 *
 * @param spd the SedPlot3D_t structure whose SedListOfSurfaces is sought.
 *
 * @return the SedListOfSurfaces from this SedPlot3D_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SedPlot3D_addSurface()
 * @see SedPlot3D_createSurface()
 * @see SedPlot3D_getSurfaceById()
 * @see SedPlot3D_getSurface()
 * @see SedPlot3D_getNumSurfaces()
 * @see SedPlot3D_removeSurfaceById()
 * @see SedPlot3D_removeSurface()
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedPlot3D_getListOfSurfaces(SedPlot3D_t* spd);


/**
 * Get a SedSurface_t from the SedPlot3D_t.
 *
 * @param spd the SedPlot3D_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSurface_t to
 * retrieve.
 *
 * @return the nth SedSurface_t in the SedListOfSurfaces within this SedPlot3D
 * or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurface(SedPlot3D_t* spd, unsigned int n);


/**
 * Get a SedSurface_t from the SedPlot3D_t based on its identifier.
 *
 * @param spd the SedPlot3D_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSurface_t to
 * retrieve.
 *
 * @return the SedSurface_t in the SedListOfSurfaces within this SedPlot3D with
 * the given @p sid or @c NULL if no such SedSurface_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceById(SedPlot3D_t* spd, const char *sid);


/**
 * Get a SedSurface_t from the SedPlot3D_t based on the XDataReference to which
 * it refers.
 *
 * @param spd the SedPlot3D_t structure to search.
 *
 * @param sid a string representing the "xDataReference" attribute of the
 * SedSurface_t object to retrieve.
 *
 * @return the first SedSurface_t in this SedPlot3D_t based on the given
 * xDataReference attribute or NULL if no such SedSurface_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceByXDataReference(SedPlot3D_t* spd, const char *sid);


/**
 * Get a SedSurface_t from the SedPlot3D_t based on the YDataReference to which
 * it refers.
 *
 * @param spd the SedPlot3D_t structure to search.
 *
 * @param sid a string representing the "yDataReference" attribute of the
 * SedSurface_t object to retrieve.
 *
 * @return the first SedSurface_t in this SedPlot3D_t based on the given
 * yDataReference attribute or NULL if no such SedSurface_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceByYDataReference(SedPlot3D_t* spd, const char *sid);


/**
 * Get a SedSurface_t from the SedPlot3D_t based on the ZDataReference to which
 * it refers.
 *
 * @param spd the SedPlot3D_t structure to search.
 *
 * @param sid a string representing the "zDataReference" attribute of the
 * SedSurface_t object to retrieve.
 *
 * @return the first SedSurface_t in this SedPlot3D_t based on the given
 * zDataReference attribute or NULL if no such SedSurface_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceByZDataReference(SedPlot3D_t* spd, const char *sid);


/**
 * Get a SedSurface_t from the SedPlot3D_t based on the Style to which it
 * refers.
 *
 * @param spd the SedPlot3D_t structure to search.
 *
 * @param sid a string representing the "style" attribute of the SedSurface_t
 * object to retrieve.
 *
 * @return the first SedSurface_t in this SedPlot3D_t based on the given style
 * attribute or NULL if no such SedSurface_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_getSurfaceByStyle(SedPlot3D_t* spd, const char *sid);


/**
 * Adds a copy of the given SedSurface_t to this SedPlot3D_t.
 *
 * @param spd the SedPlot3D_t structure to which the SedSurface_t should be
 * added.
 *
 * @param ss the SedSurface_t object to add.
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
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
int
SedPlot3D_addSurface(SedPlot3D_t* spd, const SedSurface_t* ss);


/**
 * Get the number of SedSurface_t objects in this SedPlot3D_t.
 *
 * @param spd the SedPlot3D_t structure to query.
 *
 * @return the number of SedSurface_t objects in this SedPlot3D_t.
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
unsigned int
SedPlot3D_getNumSurfaces(SedPlot3D_t* spd);


/**
 * Creates a new SedSurface_t object, adds it to this SedPlot3D_t object and
 * returns the SedSurface_t object created.
 *
 * @param spd the SedPlot3D_t structure to which the SedSurface_t should be
 * added.
 *
 * @return a new SedSurface_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_createSurface(SedPlot3D_t* spd);


/**
 * Removes the nth SedSurface_t from this SedPlot3D_t and returns a pointer to
 * it.
 *
 * @param spd the SedPlot3D_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSurface_t to
 * remove.
 *
 * @return a pointer to the nth SedSurface_t in this SedPlot3D_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_removeSurface(SedPlot3D_t* spd, unsigned int n);


/**
 * Removes the SedSurface_t from this SedPlot3D_t based on its identifier and
 * returns a pointer to it.
 *
 * @param spd the SedPlot3D_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSurface_t to
 * remove.
 *
 * @return the SedSurface_t in this SedPlot3D_t based on the identifier or NULL
 * if no such SedSurface_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedPlot3D_removeSurfaceById(SedPlot3D_t* spd, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedPlot3D_t object have been set.
 *
 * @param spd the SedPlot3D_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedPlot3D_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
int
SedPlot3D_hasRequiredAttributes(const SedPlot3D_t * spd);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedPlot3D_t object have been set.
 *
 * @param spd the SedPlot3D_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedPlot3D_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedPlot3D_t object are:
 *
 * @memberof SedPlot3D_t
 */
LIBSEDML_EXTERN
int
SedPlot3D_hasRequiredElements(const SedPlot3D_t * spd);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedPlot3D_H__ */


