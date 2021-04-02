/**
 * @file SedShadedArea.h
 * @brief Definition of the SedShadedArea class.
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
 * @class SedShadedArea
 * @sbmlbrief{sedml} TODO:Definition of the SedShadedArea class.
 */


#ifndef SedShadedArea_H__
#define SedShadedArea_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedAbstractCurve.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedShadedArea : public SedAbstractCurve
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mYDataReferenceFrom;
  std::string mYDataReferenceTo;

  /** @endcond */

public:

  /**
   * Creates a new SedShadedArea using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedShadedArea.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedShadedArea.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedShadedArea(unsigned int level = SEDML_DEFAULT_LEVEL,
                unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedShadedArea using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedShadedArea(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedShadedArea.
   *
   * @param orig the SedShadedArea instance to copy.
   */
  SedShadedArea(const SedShadedArea& orig);


  /**
   * Assignment operator for SedShadedArea.
   *
   * @param rhs the SedShadedArea object whose values are to be used as the
   * basis of the assignment.
   */
  SedShadedArea& operator=(const SedShadedArea& rhs);


  /**
   * Creates and returns a deep copy of this SedShadedArea object.
   *
   * @return a (deep) copy of this SedShadedArea object.
   */
  virtual SedShadedArea* clone() const;


  /**
   * Destructor for SedShadedArea.
   */
  virtual ~SedShadedArea();


  /**
   * Returns the value of the "yDataReferenceFrom" attribute of this
   * SedShadedArea.
   *
   * @return the value of the "yDataReferenceFrom" attribute of this
   * SedShadedArea as a string.
   */
  const std::string& getYDataReferenceFrom() const;


  /**
   * Returns the value of the "yDataReferenceTo" attribute of this
   * SedShadedArea.
   *
   * @return the value of the "yDataReferenceTo" attribute of this
   * SedShadedArea as a string.
   */
  const std::string& getYDataReferenceTo() const;


  /**
   * Predicate returning @c true if this SedShadedArea's "yDataReferenceFrom"
   * attribute is set.
   *
   * @return @c true if this SedShadedArea's "yDataReferenceFrom" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetYDataReferenceFrom() const;


  /**
   * Predicate returning @c true if this SedShadedArea's "yDataReferenceTo"
   * attribute is set.
   *
   * @return @c true if this SedShadedArea's "yDataReferenceTo" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetYDataReferenceTo() const;


  /**
   * Sets the value of the "yDataReferenceFrom" attribute of this
   * SedShadedArea.
   *
   * @param yDataReferenceFrom std::string& value of the "yDataReferenceFrom"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setYDataReferenceFrom(const std::string& yDataReferenceFrom);


  /**
   * Sets the value of the "yDataReferenceTo" attribute of this SedShadedArea.
   *
   * @param yDataReferenceTo std::string& value of the "yDataReferenceTo"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setYDataReferenceTo(const std::string& yDataReferenceTo);


  /**
   * Unsets the value of the "yDataReferenceFrom" attribute of this
   * SedShadedArea.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetYDataReferenceFrom();


  /**
   * Unsets the value of the "yDataReferenceTo" attribute of this
   * SedShadedArea.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetYDataReferenceTo();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedShadedArea object.
   *
   * For SedShadedArea, the XML element name is always @c "shadedArea".
   *
   * @return the name of this element, i.e. @c "shadedArea".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedShadedArea object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_SHADEDAREA, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedShadedArea object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedShadedArea have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedShadedArea object are:
   * @li "yDataReferenceFrom"
   * @li "yDataReferenceTo"
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
   * Gets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Gets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Gets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Gets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Gets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Predicate returning @c true if this SedShadedArea's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedShadedArea's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Sets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Sets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Sets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Sets the value of the "attributeName" attribute of this SedShadedArea.
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
   * Unsets the value of the "attributeName" attribute of this SedShadedArea.
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
 * Creates a new SedShadedArea_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedShadedArea_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedShadedArea_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
SedShadedArea_t *
SedShadedArea_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedShadedArea_t object.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @return a (deep) copy of this SedShadedArea_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
SedShadedArea_t*
SedShadedArea_clone(const SedShadedArea_t* ssa);


/**
 * Frees this SedShadedArea_t object.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
void
SedShadedArea_free(SedShadedArea_t* ssa);


/**
 * Returns the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea_t.
 *
 * @param ssa the SedShadedArea_t structure whose yDataReferenceFrom is sought.
 *
 * @return the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
char *
SedShadedArea_getYDataReferenceFrom(const SedShadedArea_t * ssa);


/**
 * Returns the value of the "yDataReferenceTo" attribute of this
 * SedShadedArea_t.
 *
 * @param ssa the SedShadedArea_t structure whose yDataReferenceTo is sought.
 *
 * @return the value of the "yDataReferenceTo" attribute of this
 * SedShadedArea_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
char *
SedShadedArea_getYDataReferenceTo(const SedShadedArea_t * ssa);


/**
 * Predicate returning @c 1 (true) if this SedShadedArea_t's
 * "yDataReferenceFrom" attribute is set.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @return @c 1 (true) if this SedShadedArea_t's "yDataReferenceFrom" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
int
SedShadedArea_isSetYDataReferenceFrom(const SedShadedArea_t * ssa);


/**
 * Predicate returning @c 1 (true) if this SedShadedArea_t's "yDataReferenceTo"
 * attribute is set.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @return @c 1 (true) if this SedShadedArea_t's "yDataReferenceTo" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
int
SedShadedArea_isSetYDataReferenceTo(const SedShadedArea_t * ssa);


/**
 * Sets the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea_t.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @param yDataReferenceFrom const char * value of the "yDataReferenceFrom"
 * attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
int
SedShadedArea_setYDataReferenceFrom(SedShadedArea_t * ssa,
                                    const char * yDataReferenceFrom);


/**
 * Sets the value of the "yDataReferenceTo" attribute of this SedShadedArea_t.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @param yDataReferenceTo const char * value of the "yDataReferenceTo"
 * attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
int
SedShadedArea_setYDataReferenceTo(SedShadedArea_t * ssa,
                                  const char * yDataReferenceTo);


/**
 * Unsets the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea_t.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
int
SedShadedArea_unsetYDataReferenceFrom(SedShadedArea_t * ssa);


/**
 * Unsets the value of the "yDataReferenceTo" attribute of this
 * SedShadedArea_t.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
int
SedShadedArea_unsetYDataReferenceTo(SedShadedArea_t * ssa);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedShadedArea_t object have been set.
 *
 * @param ssa the SedShadedArea_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedShadedArea_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedShadedArea_t object are:
 * @li "yDataReferenceFrom"
 * @li "yDataReferenceTo"
 *
 * @memberof SedShadedArea_t
 */
LIBSEDML_EXTERN
int
SedShadedArea_hasRequiredAttributes(const SedShadedArea_t * ssa);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedShadedArea_H__ */


