/**
 * @file SedChangeXML.h
 * @brief Definition of the SedChangeXML class.
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
 * @class SedChangeXML
 * @sbmlbrief{sedml} TODO:Definition of the SedChangeXML class.
 */


#ifndef SedChangeXML_H__
#define SedChangeXML_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedChange.h>
#include <sbml/xml/XMLNode.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedChangeXML : public SedChange
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* mNewXML;

  /** @endcond */

public:

  /**
   * Creates a new SedChangeXML using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedChangeXML.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedChangeXML.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedChangeXML(unsigned int level = SEDML_DEFAULT_LEVEL,
               unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedChangeXML using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedChangeXML(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedChangeXML.
   *
   * @param orig the SedChangeXML instance to copy.
   */
  SedChangeXML(const SedChangeXML& orig);


  /**
   * Assignment operator for SedChangeXML.
   *
   * @param rhs the SedChangeXML object whose values are to be used as the
   * basis of the assignment.
   */
  SedChangeXML& operator=(const SedChangeXML& rhs);


  /**
   * Creates and returns a deep copy of this SedChangeXML object.
   *
   * @return a (deep) copy of this SedChangeXML object.
   */
  virtual SedChangeXML* clone() const;


  /**
   * Destructor for SedChangeXML.
   */
  virtual ~SedChangeXML();


  /**
   * Returns the value of the "newXML" element of this SedChangeXML.
   *
   * @return the value of the "newXML" element of this SedChangeXML as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getNewXML() const;


  /**
   * Returns the value of the "newXML" element of this SedChangeXML.
   *
   * @return the value of the "newXML" element of this SedChangeXML as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getNewXML();


  /**
   * Predicate returning @c true if this SedChangeXML's "newXML" element is
   * set.
   *
   * @return @c true if this SedChangeXML's "newXML" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetNewXML() const;


  /**
   * Sets the value of the "newXML" element of this SedChangeXML.
   *
   * @param newXML LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* value of the
   * "newXML" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNewXML(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* newXML);


  /**
   * Unsets the value of the "newXML" element of this SedChangeXML.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNewXML();


  /**
   * Returns the XML element name of this SedChangeXML object.
   *
   * For SedChangeXML, the XML element name is always @c "changeXML".
   *
   * @return the name of this element, i.e. @c "changeXML".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedChangeXML object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_CHANGE_CHANGEXML, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedChangeXML object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedChangeXML have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedChangeXML object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedChangeXML have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedChangeXML object are:
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
   * Gets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Gets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Gets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Gets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Gets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Predicate returning @c true if this SedChangeXML's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedChangeXML's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Sets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Sets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Sets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Sets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Unsets the value of the "attributeName" attribute of this SedChangeXML.
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
   * Reads other XML such as math/notes etc.
   */
  virtual bool readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

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
 * Creates a new SedChangeXML_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedChangeXML_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedChangeXML_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
SedChangeXML_t *
SedChangeXML_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedChangeXML_t object.
 *
 * @param scxml the SedChangeXML_t structure.
 *
 * @return a (deep) copy of this SedChangeXML_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
SedChangeXML_t*
SedChangeXML_clone(const SedChangeXML_t* scxml);


/**
 * Frees this SedChangeXML_t object.
 *
 * @param scxml the SedChangeXML_t structure.
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
void
SedChangeXML_free(SedChangeXML_t* scxml);


/**
 * Returns the value of the "newXML" element of this SedChangeXML_t.
 *
 * @param scxml the SedChangeXML_t structure whose newXML is sought.
 *
 * @return the value of the "newXML" element of this SedChangeXML_t as a
 * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*.
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*
SedChangeXML_getNewXML(const SedChangeXML_t * scxml);


/**
 * Predicate returning @c 1 (true) if this SedChangeXML_t's "newXML" element is
 * set.
 *
 * @param scxml the SedChangeXML_t structure.
 *
 * @return @c 1 (true) if this SedChangeXML_t's "newXML" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
int
SedChangeXML_isSetNewXML(const SedChangeXML_t * scxml);


/**
 * Sets the value of the "newXML" element of this SedChangeXML_t.
 *
 * @param scxml the SedChangeXML_t structure.
 *
 * @param newXML LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t* value of the
 * "newXML" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
int
SedChangeXML_setNewXML(SedChangeXML_t * scxml,
                       const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*
                         newXML);


/**
 * Unsets the value of the "newXML" element of this SedChangeXML_t.
 *
 * @param scxml the SedChangeXML_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
int
SedChangeXML_unsetNewXML(SedChangeXML_t * scxml);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedChangeXML_t object have been set.
 *
 * @param scxml the SedChangeXML_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedChangeXML_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
int
SedChangeXML_hasRequiredAttributes(const SedChangeXML_t * scxml);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedChangeXML_t object have been set.
 *
 * @param scxml the SedChangeXML_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SedChangeXML_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SedChangeXML_t object are:
 *
 * @memberof SedChangeXML_t
 */
LIBSEDML_EXTERN
int
SedChangeXML_hasRequiredElements(const SedChangeXML_t * scxml);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedChangeXML_H__ */


