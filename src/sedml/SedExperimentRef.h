/**
 * @file SedExperimentRef.h
 * @brief Definition of the SedExperimentRef class.
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
 * @class SedExperimentRef
 * @sbmlbrief{sedml} TODO:Definition of the SedExperimentRef class.
 */


#ifndef SedExperimentRef_H__
#define SedExperimentRef_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedExperimentRef : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mExperimentId;

  /** @endcond */

public:

  /**
   * Creates a new SedExperimentRef using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedExperimentRef.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedExperimentRef.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedExperimentRef(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedExperimentRef using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedExperimentRef(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedExperimentRef.
   *
   * @param orig the SedExperimentRef instance to copy.
   */
  SedExperimentRef(const SedExperimentRef& orig);


  /**
   * Assignment operator for SedExperimentRef.
   *
   * @param rhs the SedExperimentRef object whose values are to be used as the
   * basis of the assignment.
   */
  SedExperimentRef& operator=(const SedExperimentRef& rhs);


  /**
   * Creates and returns a deep copy of this SedExperimentRef object.
   *
   * @return a (deep) copy of this SedExperimentRef object.
   */
  virtual SedExperimentRef* clone() const;


  /**
   * Destructor for SedExperimentRef.
   */
  virtual ~SedExperimentRef();


  /**
   * Returns the value of the "experimentId" attribute of this
   * SedExperimentRef.
   *
   * @return the value of the "experimentId" attribute of this SedExperimentRef
   * as a string.
   */
  const std::string& getExperimentId() const;


  /**
   * Predicate returning @c true if this SedExperimentRef's "experimentId"
   * attribute is set.
   *
   * @return @c true if this SedExperimentRef's "experimentId" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetExperimentId() const;


  /**
   * Sets the value of the "experimentId" attribute of this SedExperimentRef.
   *
   * @param experimentId std::string& value of the "experimentId" attribute to
   * be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setExperimentId(const std::string& experimentId);


  /**
   * Unsets the value of the "experimentId" attribute of this SedExperimentRef.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetExperimentId();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedExperimentRef object.
   *
   * For SedExperimentRef, the XML element name is always @c "experimentRef".
   *
   * @return the name of this element, i.e. @c "experimentRef".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedExperimentRef object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_EXPERIMENT_REF, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedExperimentRef object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedExperimentRef have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Predicate returning @c true if this SedExperimentRef's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedExperimentRef's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Sets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Sets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Sets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * Sets the value of the "attributeName" attribute of this SedExperimentRef.
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
   * SedExperimentRef.
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
 * Creates a new SedExperimentRef_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedExperimentRef_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedExperimentRef_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedExperimentRef_t
 */
LIBSEDML_EXTERN
SedExperimentRef_t *
SedExperimentRef_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedExperimentRef_t object.
 *
 * @param ser the SedExperimentRef_t structure.
 *
 * @return a (deep) copy of this SedExperimentRef_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedExperimentRef_t
 */
LIBSEDML_EXTERN
SedExperimentRef_t*
SedExperimentRef_clone(const SedExperimentRef_t* ser);


/**
 * Frees this SedExperimentRef_t object.
 *
 * @param ser the SedExperimentRef_t structure.
 *
 * @memberof SedExperimentRef_t
 */
LIBSEDML_EXTERN
void
SedExperimentRef_free(SedExperimentRef_t* ser);


/**
 * Returns the value of the "experimentId" attribute of this
 * SedExperimentRef_t.
 *
 * @param ser the SedExperimentRef_t structure whose experimentId is sought.
 *
 * @return the value of the "experimentId" attribute of this SedExperimentRef_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedExperimentRef_t
 */
LIBSEDML_EXTERN
char *
SedExperimentRef_getExperimentId(const SedExperimentRef_t * ser);


/**
 * Predicate returning @c 1 (true) if this SedExperimentRef_t's "experimentId"
 * attribute is set.
 *
 * @param ser the SedExperimentRef_t structure.
 *
 * @return @c 1 (true) if this SedExperimentRef_t's "experimentId" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedExperimentRef_t
 */
LIBSEDML_EXTERN
int
SedExperimentRef_isSetExperimentId(const SedExperimentRef_t * ser);


/**
 * Sets the value of the "experimentId" attribute of this SedExperimentRef_t.
 *
 * @param ser the SedExperimentRef_t structure.
 *
 * @param experimentId const char * value of the "experimentId" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedExperimentRef_t
 */
LIBSEDML_EXTERN
int
SedExperimentRef_setExperimentId(SedExperimentRef_t * ser,
                                 const char * experimentId);


/**
 * Unsets the value of the "experimentId" attribute of this SedExperimentRef_t.
 *
 * @param ser the SedExperimentRef_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedExperimentRef_t
 */
LIBSEDML_EXTERN
int
SedExperimentRef_unsetExperimentId(SedExperimentRef_t * ser);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedExperimentRef_t object have been set.
 *
 * @param ser the SedExperimentRef_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedExperimentRef_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedExperimentRef_t
 */
LIBSEDML_EXTERN
int
SedExperimentRef_hasRequiredAttributes(const SedExperimentRef_t * ser);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedExperimentRef_H__ */


