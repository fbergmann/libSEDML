/**
 * @file SedParameterEstimationReport.h
 * @brief Definition of the SedParameterEstimationReport class.
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
 * @class SedParameterEstimationReport
 * @sbmlbrief{sedml} TODO:Definition of the SedParameterEstimationReport class.
 */


#ifndef SedParameterEstimationReport_H__
#define SedParameterEstimationReport_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedOutput.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedParameterEstimationReport : public SedOutput
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mTaskReference;

  /** @endcond */

public:

  /**
   * Creates a new SedParameterEstimationReport using the given SED-ML Level and
   * @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedParameterEstimationReport.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedParameterEstimationReport.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedParameterEstimationReport(unsigned int level = SEDML_DEFAULT_LEVEL,
                               unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedParameterEstimationReport using the given SedNamespaces
   * object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedParameterEstimationReport(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedParameterEstimationReport.
   *
   * @param orig the SedParameterEstimationReport instance to copy.
   */
  SedParameterEstimationReport(const SedParameterEstimationReport& orig);


  /**
   * Assignment operator for SedParameterEstimationReport.
   *
   * @param rhs the SedParameterEstimationReport object whose values are to be
   * used as the basis of the assignment.
   */
  SedParameterEstimationReport& operator=(const SedParameterEstimationReport&
    rhs);


  /**
   * Creates and returns a deep copy of this SedParameterEstimationReport
   * object.
   *
   * @return a (deep) copy of this SedParameterEstimationReport object.
   */
  virtual SedParameterEstimationReport* clone() const;


  /**
   * Destructor for SedParameterEstimationReport.
   */
  virtual ~SedParameterEstimationReport();


  /**
   * Returns the value of the "taskReference" attribute of this
   * SedParameterEstimationReport.
   *
   * @return the value of the "taskReference" attribute of this
   * SedParameterEstimationReport as a string.
   */
  const std::string& getTaskReference() const;


  /**
   * Predicate returning @c true if this SedParameterEstimationReport's
   * "taskReference" attribute is set.
   *
   * @return @c true if this SedParameterEstimationReport's "taskReference" attribute
   * has been set, otherwise @c false is returned.
   */
  bool isSetTaskReference() const;


  /**
   * Sets the value of the "taskReference" attribute of this
   * SedParameterEstimationReport.
   *
   * @param taskReference std::string& value of the "taskReference" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTaskReference(const std::string& taskReference);


  /**
   * Unsets the value of the "taskReference" attribute of this
   * SedParameterEstimationReport.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTaskReference();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedParameterEstimationReport object.
   *
   * For SedParameterEstimationReport, the XML element name is always
   * @c "parameterEstimationReport".
   *
   * @return the name of this element, i.e. @c "parameterEstimationReport".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedParameterEstimationReport
   * object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_PARAMETERESTIMATIONREPORT, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedParameterEstimationReport object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedParameterEstimationReport have been set, otherwise @c false is
   * returned.
   *
   *
   * @note The required attributes for the SedParameterEstimationReport object
   * are:
   * @li "taskReference"
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
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Gets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Predicate returning @c true if this SedParameterEstimationReport's
   * attribute "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedParameterEstimationReport's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * Sets the value of the "attributeName" attribute of this
   * SedParameterEstimationReport.
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
   * SedParameterEstimationReport.
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
 * Creates a new SedParameterEstimationReport_t using the given SED-ML Level and
 * @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedParameterEstimationReport_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedParameterEstimationReport_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedParameterEstimationReport_t
 */
LIBSEDML_EXTERN
SedParameterEstimationReport_t *
SedParameterEstimationReport_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedParameterEstimationReport_t
 * object.
 *
 * @param sper the SedParameterEstimationReport_t structure.
 *
 * @return a (deep) copy of this SedParameterEstimationReport_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedParameterEstimationReport_t
 */
LIBSEDML_EXTERN
SedParameterEstimationReport_t*
SedParameterEstimationReport_clone(const SedParameterEstimationReport_t* sper);


/**
 * Frees this SedParameterEstimationReport_t object.
 *
 * @param sper the SedParameterEstimationReport_t structure.
 *
 * @memberof SedParameterEstimationReport_t
 */
LIBSEDML_EXTERN
void
SedParameterEstimationReport_free(SedParameterEstimationReport_t* sper);


/**
 * Returns the value of the "taskReference" attribute of this
 * SedParameterEstimationReport_t.
 *
 * @param sper the SedParameterEstimationReport_t structure whose taskReference is
 * sought.
 *
 * @return the value of the "taskReference" attribute of this
 * SedParameterEstimationReport_t as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedParameterEstimationReport_t
 */
LIBSEDML_EXTERN
char *
SedParameterEstimationReport_getTaskReference(const SedParameterEstimationReport_t *
  sper);


/**
 * Predicate returning @c 1 (true) if this SedParameterEstimationReport_t's
 * "taskReference" attribute is set.
 *
 * @param sper the SedParameterEstimationReport_t structure.
 *
 * @return @c 1 (true) if this SedParameterEstimationReport_t's "taskReference"
 * attribute has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedParameterEstimationReport_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationReport_isSetTaskReference(const SedParameterEstimationReport_t
  * sper);


/**
 * Sets the value of the "taskReference" attribute of this
 * SedParameterEstimationReport_t.
 *
 * @param sper the SedParameterEstimationReport_t structure.
 *
 * @param taskReference const char * value of the "taskReference" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationReport_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationReport_setTaskReference(SedParameterEstimationReport_t * sper,
                                        const char * taskReference);


/**
 * Unsets the value of the "taskReference" attribute of this
 * SedParameterEstimationReport_t.
 *
 * @param sper the SedParameterEstimationReport_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedParameterEstimationReport_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationReport_unsetTaskReference(SedParameterEstimationReport_t *
  sper);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedParameterEstimationReport_t object have been set.
 *
 * @param sper the SedParameterEstimationReport_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedParameterEstimationReport_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 *
 * @note The required attributes for the SedParameterEstimationReport_t object
 * are:
 * @li "taskReference"
 *
 * @memberof SedParameterEstimationReport_t
 */
LIBSEDML_EXTERN
int
SedParameterEstimationReport_hasRequiredAttributes(const
  SedParameterEstimationReport_t * sper);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedParameterEstimationReport_H__ */


