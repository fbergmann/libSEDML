/**
 * @file SedTask.h
 * @brief Definition of the SedTask class.
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
 * @class SedTask
 * @sbmlbrief{sedml} TODO:Definition of the SedTask class.
 */


#ifndef SedTask_H__
#define SedTask_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedAbstractTask.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedTask : public SedAbstractTask
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mModelReference;
  std::string mSimulationReference;

  /** @endcond */

public:

  /**
   * Creates a new SedTask using the given SED-ML Level and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedTask.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedTask.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedTask(unsigned int level = SEDML_DEFAULT_LEVEL,
          unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedTask using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedTask(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedTask.
   *
   * @param orig the SedTask instance to copy.
   */
  SedTask(const SedTask& orig);


  /**
   * Assignment operator for SedTask.
   *
   * @param rhs the SedTask object whose values are to be used as the basis of
   * the assignment.
   */
  SedTask& operator=(const SedTask& rhs);


  /**
   * Creates and returns a deep copy of this SedTask object.
   *
   * @return a (deep) copy of this SedTask object.
   */
  virtual SedTask* clone() const;


  /**
   * Destructor for SedTask.
   */
  virtual ~SedTask();


  /**
   * Returns the value of the "modelReference" attribute of this SedTask.
   *
   * @return the value of the "modelReference" attribute of this SedTask as a
   * string.
   */
  const std::string& getModelReference() const;


  /**
   * Returns the value of the "simulationReference" attribute of this SedTask.
   *
   * @return the value of the "simulationReference" attribute of this SedTask
   * as a string.
   */
  const std::string& getSimulationReference() const;


  /**
   * Predicate returning @c true if this SedTask's "modelReference" attribute
   * is set.
   *
   * @return @c true if this SedTask's "modelReference" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetModelReference() const;


  /**
   * Predicate returning @c true if this SedTask's "simulationReference"
   * attribute is set.
   *
   * @return @c true if this SedTask's "simulationReference" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetSimulationReference() const;


  /**
   * Sets the value of the "modelReference" attribute of this SedTask.
   *
   * @param modelReference std::string& value of the "modelReference" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setModelReference(const std::string& modelReference);


  /**
   * Sets the value of the "simulationReference" attribute of this SedTask.
   *
   * @param simulationReference std::string& value of the "simulationReference"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setSimulationReference(const std::string& simulationReference);


  /**
   * Unsets the value of the "modelReference" attribute of this SedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetModelReference();


  /**
   * Unsets the value of the "simulationReference" attribute of this SedTask.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSimulationReference();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedTask object.
   *
   * For SedTask, the XML element name is always @c "task".
   *
   * @return the name of this element, i.e. @c "task".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedTask object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_TASK, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedTask object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedTask have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SedTask.
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
   * Gets the value of the "attributeName" attribute of this SedTask.
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
   * Gets the value of the "attributeName" attribute of this SedTask.
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
   * Gets the value of the "attributeName" attribute of this SedTask.
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
   * Gets the value of the "attributeName" attribute of this SedTask.
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
   * Predicate returning @c true if this SedTask's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedTask's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedTask.
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
   * Sets the value of the "attributeName" attribute of this SedTask.
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
   * Sets the value of the "attributeName" attribute of this SedTask.
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
   * Sets the value of the "attributeName" attribute of this SedTask.
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
   * Sets the value of the "attributeName" attribute of this SedTask.
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
   * Unsets the value of the "attributeName" attribute of this SedTask.
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
 * Creates a new SedTask_t using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedTask_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedTask_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
SedTask_t *
SedTask_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedTask_t object.
 *
 * @param st the SedTask_t structure.
 *
 * @return a (deep) copy of this SedTask_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
SedTask_t*
SedTask_clone(const SedTask_t* st);


/**
 * Frees this SedTask_t object.
 *
 * @param st the SedTask_t structure.
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
void
SedTask_free(SedTask_t* st);


/**
 * Returns the value of the "modelReference" attribute of this SedTask_t.
 *
 * @param st the SedTask_t structure whose modelReference is sought.
 *
 * @return the value of the "modelReference" attribute of this SedTask_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
char *
SedTask_getModelReference(const SedTask_t * st);


/**
 * Returns the value of the "simulationReference" attribute of this SedTask_t.
 *
 * @param st the SedTask_t structure whose simulationReference is sought.
 *
 * @return the value of the "simulationReference" attribute of this SedTask_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
char *
SedTask_getSimulationReference(const SedTask_t * st);


/**
 * Predicate returning @c 1 (true) if this SedTask_t's "modelReference"
 * attribute is set.
 *
 * @param st the SedTask_t structure.
 *
 * @return @c 1 (true) if this SedTask_t's "modelReference" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
int
SedTask_isSetModelReference(const SedTask_t * st);


/**
 * Predicate returning @c 1 (true) if this SedTask_t's "simulationReference"
 * attribute is set.
 *
 * @param st the SedTask_t structure.
 *
 * @return @c 1 (true) if this SedTask_t's "simulationReference" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
int
SedTask_isSetSimulationReference(const SedTask_t * st);


/**
 * Sets the value of the "modelReference" attribute of this SedTask_t.
 *
 * @param st the SedTask_t structure.
 *
 * @param modelReference const char * value of the "modelReference" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
int
SedTask_setModelReference(SedTask_t * st, const char * modelReference);


/**
 * Sets the value of the "simulationReference" attribute of this SedTask_t.
 *
 * @param st the SedTask_t structure.
 *
 * @param simulationReference const char * value of the "simulationReference"
 * attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
int
SedTask_setSimulationReference(SedTask_t * st,
                               const char * simulationReference);


/**
 * Unsets the value of the "modelReference" attribute of this SedTask_t.
 *
 * @param st the SedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
int
SedTask_unsetModelReference(SedTask_t * st);


/**
 * Unsets the value of the "simulationReference" attribute of this SedTask_t.
 *
 * @param st the SedTask_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
int
SedTask_unsetSimulationReference(SedTask_t * st);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedTask_t object have been set.
 *
 * @param st the SedTask_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedTask_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedTask_t
 */
LIBSEDML_EXTERN
int
SedTask_hasRequiredAttributes(const SedTask_t * st);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedTask_H__ */


