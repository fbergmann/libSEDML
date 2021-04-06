/**
 * @file SedAbstractCurve.h
 * @brief Definition of the SedAbstractCurve class.
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
 * @class SedAbstractCurve
 * @sbmlbrief{sedml} TODO:Definition of the SedAbstractCurve class.
 */


#ifndef SedAbstractCurve_H__
#define SedAbstractCurve_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedCurve;
class SedShadedArea;

class LIBSEDML_EXTERN SedAbstractCurve : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  bool mLogX;
  bool mIsSetLogX;
  int mOrder;
  bool mIsSetOrder;
  std::string mStyle;
  std::string mYAxis;
  std::string mXDataReference;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedAbstractCurve using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedAbstractCurve.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedAbstractCurve.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAbstractCurve(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedAbstractCurve using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedAbstractCurve(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedAbstractCurve.
   *
   * @param orig the SedAbstractCurve instance to copy.
   */
  SedAbstractCurve(const SedAbstractCurve& orig);


  /**
   * Assignment operator for SedAbstractCurve.
   *
   * @param rhs the SedAbstractCurve object whose values are to be used as the
   * basis of the assignment.
   */
  SedAbstractCurve& operator=(const SedAbstractCurve& rhs);


  /**
   * Creates and returns a deep copy of this SedAbstractCurve object.
   *
   * @return a (deep) copy of this SedAbstractCurve object.
   */
  virtual SedAbstractCurve* clone() const;


  /**
   * Destructor for SedAbstractCurve.
   */
  virtual ~SedAbstractCurve();


  /**
   * Returns the value of the "logX" attribute of this SedAbstractCurve.
   *
   * @return the value of the "logX" attribute of this SedAbstractCurve as a
   * boolean.
   */
  bool getLogX() const;


  /**
   * Returns the value of the "order" attribute of this SedAbstractCurve.
   *
   * @return the value of the "order" attribute of this SedAbstractCurve as a
   * integer.
   */
  int getOrder() const;


  /**
   * Returns the value of the "style" attribute of this SedAbstractCurve.
   *
   * @return the value of the "style" attribute of this SedAbstractCurve as a
   * string.
   */
  const std::string& getStyle() const;


  /**
   * Returns the value of the "yAxis" attribute of this SedAbstractCurve.
   *
   * @return the value of the "yAxis" attribute of this SedAbstractCurve as a
   * string.
   */
  const std::string& getYAxis() const;


  /**
   * Returns the value of the "xDataReference" attribute of this
   * SedAbstractCurve.
   *
   * @return the value of the "xDataReference" attribute of this
   * SedAbstractCurve as a string.
   */
  const std::string& getXDataReference() const;


  /**
   * Predicate returning @c true if this SedAbstractCurve's "logX" attribute is
   * set.
   *
   * @return @c true if this SedAbstractCurve's "logX" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLogX() const;


  /**
   * Predicate returning @c true if this SedAbstractCurve's "order" attribute
   * is set.
   *
   * @return @c true if this SedAbstractCurve's "order" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetOrder() const;


  /**
   * Predicate returning @c true if this SedAbstractCurve's "style" attribute
   * is set.
   *
   * @return @c true if this SedAbstractCurve's "style" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetStyle() const;


  /**
   * Predicate returning @c true if this SedAbstractCurve's "yAxis" attribute
   * is set.
   *
   * @return @c true if this SedAbstractCurve's "yAxis" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetYAxis() const;


  /**
   * Predicate returning @c true if this SedAbstractCurve's "xDataReference"
   * attribute is set.
   *
   * @return @c true if this SedAbstractCurve's "xDataReference" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetXDataReference() const;


  /**
   * Sets the value of the "logX" attribute of this SedAbstractCurve.
   *
   * @param logX bool value of the "logX" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLogX(bool logX);


  /**
   * Sets the value of the "order" attribute of this SedAbstractCurve.
   *
   * @param order int value of the "order" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOrder(int order);


  /**
   * Sets the value of the "style" attribute of this SedAbstractCurve.
   *
   * @param style std::string& value of the "style" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStyle(const std::string& style);


  /**
   * Sets the value of the "yAxis" attribute of this SedAbstractCurve.
   *
   * @param yAxis std::string& value of the "yAxis" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p yAxis = @c NULL or an empty string is
   * equivalent to calling unsetYAxis().
   */
  int setYAxis(const std::string& yAxis);


  /**
   * Sets the value of the "xDataReference" attribute of this SedAbstractCurve.
   *
   * @param xDataReference std::string& value of the "xDataReference" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setXDataReference(const std::string& xDataReference);


  /**
   * Unsets the value of the "logX" attribute of this SedAbstractCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLogX();


  /**
   * Unsets the value of the "order" attribute of this SedAbstractCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOrder();


  /**
   * Unsets the value of the "style" attribute of this SedAbstractCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStyle();


  /**
   * Unsets the value of the "yAxis" attribute of this SedAbstractCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetYAxis();


  /**
   * Unsets the value of the "xDataReference" attribute of this
   * SedAbstractCurve.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetXDataReference();


  /**
   * Predicate returning @c true if this abstract "SedAbstractCurve" is of type
   * SedCurve
   *
   * @return @c true if this abstract "SedAbstractCurve" is of type SedCurve,
   * @c false otherwise
   */
  virtual bool isSedCurve() const;


  /**
   * Predicate returning @c true if this abstract "SedAbstractCurve" is of type
   * SedShadedArea
   *
   * @return @c true if this abstract "SedAbstractCurve" is of type
   * SedShadedArea, @c false otherwise
   */
  virtual bool isSedShadedArea() const;


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedAbstractCurve object.
   *
   * For SedAbstractCurve, the XML element name is always @c "abstractCurve".
   *
   * @return the name of this element, i.e. @c "abstractCurve".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedAbstractCurve object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedAbstractCurve object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_ABSTRACTCURVE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedAbstractCurve object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedAbstractCurve have been set, otherwise @c false is returned.
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




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Gets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Predicate returning @c true if this SedAbstractCurve's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedAbstractCurve's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * Sets the value of the "attributeName" attribute of this SedAbstractCurve.
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
   * SedAbstractCurve.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:


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
 * Creates a new SedCurve using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAbstractCurve_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAbstractCurve_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
SedCurve_t *
SedAbstractCurve_createCurve(unsigned int level, unsigned int version);


/**
 * Creates a new SedShadedArea using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedAbstractCurve_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedAbstractCurve_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
SedShadedArea_t *
SedAbstractCurve_createShadedArea(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedAbstractCurve_t object.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return a (deep) copy of this SedAbstractCurve_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedAbstractCurve_clone(const SedAbstractCurve_t* sac);


/**
 * Frees this SedAbstractCurve_t object.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
void
SedAbstractCurve_free(SedAbstractCurve_t* sac);


/**
 * Returns the value of the "id" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedAbstractCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getId(const SedAbstractCurve_t * sac);


/**
 * Returns the value of the "name" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedAbstractCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getName(const SedAbstractCurve_t * sac);


/**
 * Returns the value of the "logX" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure whose logX is sought.
 *
 * @return the value of the "logX" attribute of this SedAbstractCurve_t as a
 * boolean.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_getLogX(const SedAbstractCurve_t * sac);


/**
 * Returns the value of the "order" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure whose order is sought.
 *
 * @return the value of the "order" attribute of this SedAbstractCurve_t as a
 * integer.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_getOrder(const SedAbstractCurve_t * sac);


/**
 * Returns the value of the "style" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure whose style is sought.
 *
 * @return the value of the "style" attribute of this SedAbstractCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getStyle(const SedAbstractCurve_t * sac);


/**
 * Returns the value of the "yAxis" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure whose yAxis is sought.
 *
 * @return the value of the "yAxis" attribute of this SedAbstractCurve_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getYAxis(const SedAbstractCurve_t * sac);


/**
 * Returns the value of the "xDataReference" attribute of this
 * SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure whose xDataReference is sought.
 *
 * @return the value of the "xDataReference" attribute of this
 * SedAbstractCurve_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
char *
SedAbstractCurve_getXDataReference(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "id" attribute
 * is set.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 (true) if this SedAbstractCurve_t's "id" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetId(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "name"
 * attribute is set.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 (true) if this SedAbstractCurve_t's "name" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetName(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "logX"
 * attribute is set.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 (true) if this SedAbstractCurve_t's "logX" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetLogX(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "order"
 * attribute is set.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 (true) if this SedAbstractCurve_t's "order" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetOrder(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "style"
 * attribute is set.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 (true) if this SedAbstractCurve_t's "style" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetStyle(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's "yAxis"
 * attribute is set.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 (true) if this SedAbstractCurve_t's "yAxis" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetYAxis(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 (true) if this SedAbstractCurve_t's
 * "xDataReference" attribute is set.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 (true) if this SedAbstractCurve_t's "xDataReference" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSetXDataReference(const SedAbstractCurve_t * sac);


/**
 * Sets the value of the "id" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
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
 * to calling SedAbstractCurve_unsetId().
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setId(SedAbstractCurve_t * sac, const char * id);


/**
 * Sets the value of the "name" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedAbstractCurve_unsetName().
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setName(SedAbstractCurve_t * sac, const char * name);


/**
 * Sets the value of the "logX" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @param logX int value of the "logX" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setLogX(SedAbstractCurve_t * sac, int logX);


/**
 * Sets the value of the "order" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @param order int value of the "order" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setOrder(SedAbstractCurve_t * sac, int order);


/**
 * Sets the value of the "style" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @param style const char * value of the "style" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setStyle(SedAbstractCurve_t * sac, const char * style);


/**
 * Sets the value of the "yAxis" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @param yAxis const char * value of the "yAxis" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p yAxis = @c NULL or an empty string is
 * equivalent to calling SedAbstractCurve_unsetYAxis().
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setYAxis(SedAbstractCurve_t * sac, const char * yAxis);


/**
 * Sets the value of the "xDataReference" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @param xDataReference const char * value of the "xDataReference" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_setXDataReference(SedAbstractCurve_t * sac,
                                   const char * xDataReference);


/**
 * Unsets the value of the "id" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetId(SedAbstractCurve_t * sac);


/**
 * Unsets the value of the "name" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetName(SedAbstractCurve_t * sac);


/**
 * Unsets the value of the "logX" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetLogX(SedAbstractCurve_t * sac);


/**
 * Unsets the value of the "order" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetOrder(SedAbstractCurve_t * sac);


/**
 * Unsets the value of the "style" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetStyle(SedAbstractCurve_t * sac);


/**
 * Unsets the value of the "yAxis" attribute of this SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetYAxis(SedAbstractCurve_t * sac);


/**
 * Unsets the value of the "xDataReference" attribute of this
 * SedAbstractCurve_t.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_unsetXDataReference(SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 if this SedAbstractCurve_t is of type SedCurve_t
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 if this SedAbstractCurve_t is of type SedCurve_t, @c 0
 * otherwise
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSedCurve(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 if this SedAbstractCurve_t is of type
 * SedShadedArea_t
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 if this SedAbstractCurve_t is of type SedShadedArea_t, @c 0
 * otherwise
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_isSedShadedArea(const SedAbstractCurve_t * sac);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAbstractCurve_t object have been set.
 *
 * @param sac the SedAbstractCurve_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedAbstractCurve_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedAbstractCurve_t
 */
LIBSEDML_EXTERN
int
SedAbstractCurve_hasRequiredAttributes(const SedAbstractCurve_t * sac);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedAbstractCurve_H__ */


