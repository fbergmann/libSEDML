/**
 * @file SedFill.h
 * @brief Definition of the SedFill class.
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
 * @class SedFill
 * @sbmlbrief{sedml} TODO:Definition of the SedFill class.
 */


#ifndef SedFill_H__
#define SedFill_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedFill : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mColor;
  //std::string mSecondColor;

  /** @endcond */

public:

  /**
   * Creates a new SedFill using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedFill.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedFill.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFill(unsigned int level = SEDML_DEFAULT_LEVEL,
          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedFill using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedFill(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedFill.
   *
   * @param orig the SedFill instance to copy.
   */
  SedFill(const SedFill& orig);


  /**
   * Assignment operator for SedFill.
   *
   * @param rhs the SedFill object whose values are to be used as the basis of
   * the assignment.
   */
  SedFill& operator=(const SedFill& rhs);


  /**
   * Creates and returns a deep copy of this SedFill object.
   *
   * @return a (deep) copy of this SedFill object.
   */
  virtual SedFill* clone() const;


  /**
   * Destructor for SedFill.
   */
  virtual ~SedFill();


  /**
   * Returns the value of the "color" attribute of this SedFill.
   *
   * @return the value of the "color" attribute of this SedFill as a string.
   */
  const std::string& getColor() const;


  /*
   * Returns the value of the "secondColor" attribute of this SedFill.
   *
   * @return the value of the "secondColor" attribute of this SedFill as a
   * string.
   */
  //const std::string& getSecondColor() const;


  /**
   * Predicate returning @c true if this SedFill's "color" attribute is set.
   *
   * @return @c true if this SedFill's "color" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetColor() const;


  /*
   * Predicate returning @c true if this SedFill's "secondColor" attribute is
   * set.
   *
   * @return @c true if this SedFill's "secondColor" attribute has been set,
   * otherwise @c false is returned.
   */
  //bool isSetSecondColor() const;


  /**
   * Sets the value of the "color" attribute of this SedFill.
   *
   * @param color std::string& value of the "color" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p color = @c NULL or an empty string is
   * equivalent to calling unsetColor().
   */
  int setColor(const std::string& color);


  /*
   * Sets the value of the "secondColor" attribute of this SedFill.
   *
   * @param secondColor std::string& value of the "secondColor" attribute to be
   * set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p secondColor = @c NULL or an empty string is
   * equivalent to calling unsetSecondColor().
   */
  //int setSecondColor(const std::string& secondColor);


  /**
   * Unsets the value of the "color" attribute of this SedFill.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetColor();


  /*
   * Unsets the value of the "secondColor" attribute of this SedFill.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  //int unsetSecondColor();


  /**
   * Returns the XML element name of this SedFill object.
   *
   * For SedFill, the XML element name is always @c "fill".
   *
   * @return the name of this element, i.e. @c "fill".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedFill object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_FILL, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedFill object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedFill have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedFill object are:
   * @li "color"
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
   * Gets the value of the "attributeName" attribute of this SedFill.
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
   * Gets the value of the "attributeName" attribute of this SedFill.
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
   * Gets the value of the "attributeName" attribute of this SedFill.
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
   * Gets the value of the "attributeName" attribute of this SedFill.
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
   * Gets the value of the "attributeName" attribute of this SedFill.
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
   * Predicate returning @c true if this SedFill's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedFill's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedFill.
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
   * Sets the value of the "attributeName" attribute of this SedFill.
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
   * Sets the value of the "attributeName" attribute of this SedFill.
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
   * Sets the value of the "attributeName" attribute of this SedFill.
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
   * Sets the value of the "attributeName" attribute of this SedFill.
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
   * Unsets the value of the "attributeName" attribute of this SedFill.
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
 * Creates a new SedFill_t using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedFill_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedFill_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFill_t
 */
LIBSEDML_EXTERN
SedFill_t *
SedFill_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedFill_t object.
 *
 * @param sf the SedFill_t structure.
 *
 * @return a (deep) copy of this SedFill_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedFill_t
 */
LIBSEDML_EXTERN
SedFill_t*
SedFill_clone(const SedFill_t* sf);


/**
 * Frees this SedFill_t object.
 *
 * @param sf the SedFill_t structure.
 *
 * @memberof SedFill_t
 */
LIBSEDML_EXTERN
void
SedFill_free(SedFill_t* sf);


/**
 * Returns the value of the "color" attribute of this SedFill_t.
 *
 * @param sf the SedFill_t structure whose color is sought.
 *
 * @return the value of the "color" attribute of this SedFill_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedFill_t
 */
LIBSEDML_EXTERN
char *
SedFill_getColor(const SedFill_t * sf);


/*
 * Returns the value of the "secondColor" attribute of this SedFill_t.
 *
 * @param sf the SedFill_t structure whose secondColor is sought.
 *
 * @return the value of the "secondColor" attribute of this SedFill_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedFill_t
 */
//LIBSEDML_EXTERN
//char *
//SedFill_getSecondColor(const SedFill_t * sf);


/**
 * Predicate returning @c 1 (true) if this SedFill_t's "color" attribute is
 * set.
 *
 * @param sf the SedFill_t structure.
 *
 * @return @c 1 (true) if this SedFill_t's "color" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedFill_t
 */
LIBSEDML_EXTERN
int
SedFill_isSetColor(const SedFill_t * sf);


/*
 * Predicate returning @c 1 (true) if this SedFill_t's "secondColor" attribute
 * is set.
 *
 * @param sf the SedFill_t structure.
 *
 * @return @c 1 (true) if this SedFill_t's "secondColor" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedFill_t
 */
//LIBSEDML_EXTERN
//int
//SedFill_isSetSecondColor(const SedFill_t * sf);


/**
 * Sets the value of the "color" attribute of this SedFill_t.
 *
 * @param sf the SedFill_t structure.
 *
 * @param color const char * value of the "color" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p color = @c NULL or an empty string is
 * equivalent to calling SedFill_unsetColor().
 *
 * @memberof SedFill_t
 */
LIBSEDML_EXTERN
int
SedFill_setColor(SedFill_t * sf, const char * color);


/*
 * Sets the value of the "secondColor" attribute of this SedFill_t.
 *
 * @param sf the SedFill_t structure.
 *
 * @param secondColor const char * value of the "secondColor" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p secondColor = @c NULL or an empty string is
 * equivalent to calling SedFill_unsetSecondColor().
 *
 * @memberof SedFill_t
 */
//LIBSEDML_EXTERN
//int
//SedFill_setSecondColor(SedFill_t * sf, const char * secondColor);


/**
 * Unsets the value of the "color" attribute of this SedFill_t.
 *
 * @param sf the SedFill_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFill_t
 */
LIBSEDML_EXTERN
int
SedFill_unsetColor(SedFill_t * sf);


/*
 * Unsets the value of the "secondColor" attribute of this SedFill_t.
 *
 * @param sf the SedFill_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedFill_t
 */
//LIBSEDML_EXTERN
//int
//SedFill_unsetSecondColor(SedFill_t * sf);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedFill_t object have been set.
 *
 * @param sf the SedFill_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedFill_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedFill_t object are:
 * @li "color"
 *
 * @memberof SedFill_t
 */
LIBSEDML_EXTERN
int
SedFill_hasRequiredAttributes(const SedFill_t * sf);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedFill_H__ */


