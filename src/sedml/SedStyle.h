/**
 * @file SedStyle.h
 * @brief Definition of the SedStyle class.
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
 * @class SedStyle
 * @sbmlbrief{sedml} TODO:Definition of the SedStyle class.
 */


#ifndef SedStyle_H__
#define SedStyle_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedLine.h>
#include <sedml/SedMarker.h>
#include <sedml/SedFill.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedStyle : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mBaseStyle;
  SedLine* mLineStyle;
  SedMarker* mMarkerStyle;
  SedFill* mFillStyle;

  /** @endcond */

public:

  /**
   * Creates a new SedStyle using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedStyle.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedStyle.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedStyle(unsigned int level = SEDML_DEFAULT_LEVEL,
           unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedStyle using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedStyle(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedStyle.
   *
   * @param orig the SedStyle instance to copy.
   */
  SedStyle(const SedStyle& orig);


  /**
   * Assignment operator for SedStyle.
   *
   * @param rhs the SedStyle object whose values are to be used as the basis of
   * the assignment.
   */
  SedStyle& operator=(const SedStyle& rhs);


  /**
   * Creates and returns a deep copy of this SedStyle object.
   *
   * @return a (deep) copy of this SedStyle object.
   */
  virtual SedStyle* clone() const;


  /**
   * Destructor for SedStyle.
   */
  virtual ~SedStyle();


  /**
   * Returns the value of the "baseStyle" attribute of this SedStyle.
   *
   * @return the value of the "baseStyle" attribute of this SedStyle as a
   * string.
   */
  const std::string& getBaseStyle() const;


  /**
   * Predicate returning @c true if this SedStyle's "baseStyle" attribute is
   * set.
   *
   * @return @c true if this SedStyle's "baseStyle" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetBaseStyle() const;


  /**
   * Sets the value of the "baseStyle" attribute of this SedStyle.
   *
   * @param baseStyle std::string& value of the "baseStyle" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBaseStyle(const std::string& baseStyle);


  /**
   * Unsets the value of the "baseStyle" attribute of this SedStyle.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBaseStyle();


  /**
   * Returns the value of the "line" element of this SedStyle.
   *
   * @return the value of the "line" element of this SedStyle as a SedLine*.
   */
  const SedLine* getLineStyle() const;


  /**
   * Returns the value of the "line" element of this SedStyle.
   *
   * @return the value of the "line" element of this SedStyle as a SedLine*.
   */
  SedLine* getLineStyle();


  /**
   * Returns the value of the "marker" element of this SedStyle.
   *
   * @return the value of the "marker" element of this SedStyle as a
   * SedMarker*.
   */
  const SedMarker* getMarkerStyle() const;


  /**
   * Returns the value of the "marker" element of this SedStyle.
   *
   * @return the value of the "marker" element of this SedStyle as a
   * SedMarker*.
   */
  SedMarker* getMarkerStyle();


  /**
   * Returns the value of the "fill" element of this SedStyle.
   *
   * @return the value of the "fill" element of this SedStyle as a SedFill*.
   * SedFill*.
   */
  const SedFill* getFillStyle() const;


  /**
   * Returns the value of the "fill" element of this SedStyle.
   *
   * @return the value of the "fill" element of this SedStyle as a SedFill*.
   */
  SedFill* getFillStyle();


  /**
   * Predicate returning @c true if this SedStyle's "line" element is set.
   *
   * @return @c true if this SedStyle's "line" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetLineStyle() const;


  /**
   * Predicate returning @c true if this SedStyle's "marker" element is set.
   *
   * @return @c true if this SedStyle's "marker" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetMarkerStyle() const;


  /**
   * Predicate returning @c true if this SedStyle's "fill" element is set.
   *
   * @return @c true if this SedStyle's "fill" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetFillStyle() const;


  /**
   * Sets the value of the "line" element of this SedStyle.
   *
   * @param line SedLine* value of the "line" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLineStyle(const SedLine* lineStyle);


  /**
   * Sets the value of the "marker" element of this SedStyle.
   *
   * @param marker SedMarker* value of the "marker" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMarkerStyle(const SedMarker* markerStyle);


  /**
   * Sets the value of the "fill" element of this SedStyle.
   *
   * @param fill SedFill* value of the "fill" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setFillStyle(const SedFill* fillStyle);


  /**
   * Creates a new SedLine object, adds it to this SedStyle object and returns
   * the SedLine object created.
   *
   * @return a new SedLine object instance.
   */
  SedLine* createLineStyle();


  /**
   * Creates a new SedMarker object, adds it to this SedStyle object and
   * returns the SedMarker object created.
   *
   * @return a new SedMarker object instance.
   */
  SedMarker* createMarkerStyle();


  /**
   * Creates a new SedFill object, adds it to this SedStyle object and returns
   * the SedFill object created.
   *
   * @return a new SedFill object instance.
   */
  SedFill* createFillStyle();


  /**
   * Unsets the value of the "line" element of this SedStyle.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLineStyle();


  /**
   * Unsets the value of the "marker" element of this SedStyle.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMarkerStyle();


  /**
   * Unsets the value of the "fill" element of this SedStyle.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFillStyle();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedStyle object.
   *
   * For SedStyle, the XML element name is always @c "style".
   *
   * @return the name of this element, i.e. @c "style".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedStyle object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_STYLE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedStyle object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedStyle have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedStyle object are:
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
   * Gets the value of the "attributeName" attribute of this SedStyle.
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
   * Gets the value of the "attributeName" attribute of this SedStyle.
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
   * Gets the value of the "attributeName" attribute of this SedStyle.
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
   * Gets the value of the "attributeName" attribute of this SedStyle.
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
   * Gets the value of the "attributeName" attribute of this SedStyle.
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
   * Predicate returning @c true if this SedStyle's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedStyle's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedStyle.
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
   * Sets the value of the "attributeName" attribute of this SedStyle.
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
   * Sets the value of the "attributeName" attribute of this SedStyle.
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
   * Sets the value of the "attributeName" attribute of this SedStyle.
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
   * Sets the value of the "attributeName" attribute of this SedStyle.
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
   * Unsets the value of the "attributeName" attribute of this SedStyle.
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
   * Creates and returns an new "elementName" object in this SedStyle.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedStyle.
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
   * SedStyle.
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
   * Returns the number of "elementName" in this SedStyle.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedStyle.
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
 * Creates a new SedStyle_t using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedStyle_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedStyle_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
SedStyle_t *
SedStyle_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedStyle_t object.
 *
 * @param ss the SedStyle_t structure.
 *
 * @return a (deep) copy of this SedStyle_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
SedStyle_t*
SedStyle_clone(const SedStyle_t* ss);


/**
 * Frees this SedStyle_t object.
 *
 * @param ss the SedStyle_t structure.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
void
SedStyle_free(SedStyle_t* ss);


/**
 * Returns the value of the "id" attribute of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedStyle_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
char *
SedStyle_getId(const SedStyle_t * ss);


/**
 * Returns the value of the "baseStyle" attribute of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure whose baseStyle is sought.
 *
 * @return the value of the "baseStyle" attribute of this SedStyle_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
char *
SedStyle_getBaseStyle(const SedStyle_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedStyle_t's "id" attribute is set.
 *
 * @param ss the SedStyle_t structure.
 *
 * @return @c 1 (true) if this SedStyle_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_isSetId(const SedStyle_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedStyle_t's "baseStyle" attribute
 * is set.
 *
 * @param ss the SedStyle_t structure.
 *
 * @return @c 1 (true) if this SedStyle_t's "baseStyle" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_isSetBaseStyle(const SedStyle_t * ss);


/**
 * Sets the value of the "id" attribute of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
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
 * to calling SedStyle_unsetId().
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_setId(SedStyle_t * ss, const char * id);


/**
 * Sets the value of the "baseStyle" attribute of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @param baseStyle const char * value of the "baseStyle" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_setBaseStyle(SedStyle_t * ss, const char * baseStyle);


/**
 * Unsets the value of the "id" attribute of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_unsetId(SedStyle_t * ss);


/**
 * Unsets the value of the "baseStyle" attribute of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_unsetBaseStyle(SedStyle_t * ss);


/**
 * Returns the value of the "line" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure whose line is sought.
 *
 * @return the value of the "line" element of this SedStyle_t as a SedLine*.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
const SedLine_t*
SedStyle_getLineStyle(const SedStyle_t * ss);


/**
 * Returns the value of the "marker" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure whose marker is sought.
 *
 * @return the value of the "marker" element of this SedStyle_t as a
 * SedMarker*.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
const SedMarker_t*
SedStyle_getMarkerStyle(const SedStyle_t * ss);


/**
 * Returns the value of the "fill" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure whose fill is sought.
 *
 * @return the value of the "fill" element of this SedStyle_t as a SedFill*.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
const SedFill_t*
SedStyle_getFillStyle(const SedStyle_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedStyle_t's "line" element is set.
 *
 * @param ss the SedStyle_t structure.
 *
 * @return @c 1 (true) if this SedStyle_t's "line" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_isSetLineStyle(const SedStyle_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedStyle_t's "marker" element is
 * set.
 *
 * @param ss the SedStyle_t structure.
 *
 * @return @c 1 (true) if this SedStyle_t's "marker" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_isSetMarkerStyle(const SedStyle_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedStyle_t's "fill" element is set.
 *
 * @param ss the SedStyle_t structure.
 *
 * @return @c 1 (true) if this SedStyle_t's "fill" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_isSetFillStyle(const SedStyle_t * ss);


/**
 * Sets the value of the "line" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @param line SedLine_t* value of the "line" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_setLineStyle(SedStyle_t * ss, const SedLine_t* lineStyle);


/**
 * Sets the value of the "marker" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @param marker SedMarker_t* value of the "marker" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_setMarkerStyle(SedStyle_t * ss, const SedMarker_t* markerStyle);


/**
 * Sets the value of the "fill" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @param fill SedFill_t* value of the "fill" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_setFillStyle(SedStyle_t * ss, const SedFill_t* fillStyle);


/**
 * Creates a new SedLine_t object, adds it to this SedStyle_t object and
 * returns the SedLine_t object created.
 *
 * @param ss the SedStyle_t structure to which the SedLine_t should be added.
 *
 * @return a new SedLine_t object instance.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
SedLine_t*
SedStyle_createLineStyle(SedStyle_t* ss);


/**
 * Creates a new SedMarker_t object, adds it to this SedStyle_t object and
 * returns the SedMarker_t object created.
 *
 * @param ss the SedStyle_t structure to which the SedMarker_t should be added.
 *
 * @return a new SedMarker_t object instance.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
SedMarker_t*
SedStyle_createMarkerStyle(SedStyle_t* ss);


/**
 * Creates a new SedFill_t object, adds it to this SedStyle_t object and
 * returns the SedFill_t object created.
 *
 * @param ss the SedStyle_t structure to which the SedFill_t should be added.
 *
 * @return a new SedFill_t object instance.
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
SedFill_t*
SedStyle_createFillStyle(SedStyle_t* ss);


/**
 * Unsets the value of the "line" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_unsetLineStyle(SedStyle_t * ss);


/**
 * Unsets the value of the "marker" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_unsetMarkerStyle(SedStyle_t * ss);


/**
 * Unsets the value of the "fill" element of this SedStyle_t.
 *
 * @param ss the SedStyle_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_unsetFillStyle(SedStyle_t * ss);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedStyle_t object have been set.
 *
 * @param ss the SedStyle_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedStyle_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedStyle_t object are:
 * @li "id"
 *
 * @memberof SedStyle_t
 */
LIBSEDML_EXTERN
int
SedStyle_hasRequiredAttributes(const SedStyle_t * ss);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedStyle_H__ */


