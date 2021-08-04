/**
 * @file SedExperimentReference.h
 * @brief Definition of the SedExperimentReference class.
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
 * @class SedExperimentReference
 * @sbmlbrief{sedml} TODO:Definition of the SedExperimentReference class.
 */


#ifndef SedExperimentReference_H__
#define SedExperimentReference_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedExperimentReference : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mExperimentId;

  /** @endcond */

public:

  /**
   * Creates a new SedExperimentReference using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedExperimentReference.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedExperimentReference.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedExperimentReference(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedExperimentReference using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedExperimentReference(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedExperimentReference.
   *
   * @param orig the SedExperimentReference instance to copy.
   */
  SedExperimentReference(const SedExperimentReference& orig);


  /**
   * Assignment operator for SedExperimentReference.
   *
   * @param rhs the SedExperimentReference object whose values are to be used as the
   * basis of the assignment.
   */
  SedExperimentReference& operator=(const SedExperimentReference& rhs);


  /**
   * Creates and returns a deep copy of this SedExperimentReference object.
   *
   * @return a (deep) copy of this SedExperimentReference object.
   */
  virtual SedExperimentReference* clone() const;


  /**
   * Destructor for SedExperimentReference.
   */
  virtual ~SedExperimentReference();


  /**
   * Returns the value of the "experimentId" attribute of this
   * SedExperimentReference.
   *
   * @return the value of the "experimentId" attribute of this SedExperimentReference
   * as a string.
   */
  const std::string& getExperimentId() const;


  /**
   * Predicate returning @c true if this SedExperimentReference's "experimentId"
   * attribute is set.
   *
   * @return @c true if this SedExperimentReference's "experimentId" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetExperimentId() const;


  /**
   * Sets the value of the "experimentId" attribute of this SedExperimentReference.
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
   * Unsets the value of the "experimentId" attribute of this SedExperimentReference.
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
   * Returns the XML element name of this SedExperimentReference object.
   *
   * For SedExperimentReference, the XML element name is always @c "experimentReference".
   *
   * @return the name of this element, i.e. @c "experimentReference".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedExperimentReference object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_EXPERIMENT_REFERENCE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedExperimentReference object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedExperimentReference have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Gets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Predicate returning @c true if this SedExperimentReference's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedExperimentReference's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Sets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Sets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Sets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * Sets the value of the "attributeName" attribute of this SedExperimentReference.
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
   * SedExperimentReference.
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
 * Creates a new SedExperimentReference_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedExperimentReference_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedExperimentReference_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedExperimentReference_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t *
SedExperimentReference_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedExperimentReference_t object.
 *
 * @param ser the SedExperimentReference_t structure.
 *
 * @return a (deep) copy of this SedExperimentReference_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedExperimentReference_t
 */
LIBSEDML_EXTERN
SedExperimentReference_t*
SedExperimentReference_clone(const SedExperimentReference_t* ser);


/**
 * Frees this SedExperimentReference_t object.
 *
 * @param ser the SedExperimentReference_t structure.
 *
 * @memberof SedExperimentReference_t
 */
LIBSEDML_EXTERN
void
SedExperimentReference_free(SedExperimentReference_t* ser);


/**
 * Returns the value of the "experimentId" attribute of this
 * SedExperimentReference_t.
 *
 * @param ser the SedExperimentReference_t structure whose experimentId is sought.
 *
 * @return the value of the "experimentId" attribute of this SedExperimentReference_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedExperimentReference_t
 */
LIBSEDML_EXTERN
char *
SedExperimentReference_getExperimentId(const SedExperimentReference_t * ser);


/**
 * Predicate returning @c 1 (true) if this SedExperimentReference_t's "experimentId"
 * attribute is set.
 *
 * @param ser the SedExperimentReference_t structure.
 *
 * @return @c 1 (true) if this SedExperimentReference_t's "experimentId" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedExperimentReference_t
 */
LIBSEDML_EXTERN
int
SedExperimentReference_isSetExperimentId(const SedExperimentReference_t * ser);


/**
 * Sets the value of the "experimentId" attribute of this SedExperimentReference_t.
 *
 * @param ser the SedExperimentReference_t structure.
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
 * @memberof SedExperimentReference_t
 */
LIBSEDML_EXTERN
int
SedExperimentReference_setExperimentId(SedExperimentReference_t * ser,
                                 const char * experimentId);


/**
 * Unsets the value of the "experimentId" attribute of this SedExperimentReference_t.
 *
 * @param ser the SedExperimentReference_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedExperimentReference_t
 */
LIBSEDML_EXTERN
int
SedExperimentReference_unsetExperimentId(SedExperimentReference_t * ser);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedExperimentReference_t object have been set.
 *
 * @param ser the SedExperimentReference_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedExperimentReference_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedExperimentReference_t
 */
LIBSEDML_EXTERN
int
SedExperimentReference_hasRequiredAttributes(const SedExperimentReference_t * ser);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedExperimentReference_H__ */


