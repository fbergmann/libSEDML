/**
 * @file SedOneStep.h
 * @brief Definition of the SedOneStep class.
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
 * @class SedOneStep
 * @sbmlbrief{sedml} TODO:Definition of the SedOneStep class.
 */


#ifndef SedOneStep_H__
#define SedOneStep_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedSimulation.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedOneStep : public SedSimulation
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  double mStep;
  bool mIsSetStep;

  /** @endcond */

public:

  /**
   * Creates a new SedOneStep using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedOneStep.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedOneStep.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedOneStep(unsigned int level = SEDML_DEFAULT_LEVEL,
             unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedOneStep using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedOneStep(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedOneStep.
   *
   * @param orig the SedOneStep instance to copy.
   */
  SedOneStep(const SedOneStep& orig);


  /**
   * Assignment operator for SedOneStep.
   *
   * @param rhs the SedOneStep object whose values are to be used as the basis
   * of the assignment.
   */
  SedOneStep& operator=(const SedOneStep& rhs);


  /**
   * Creates and returns a deep copy of this SedOneStep object.
   *
   * @return a (deep) copy of this SedOneStep object.
   */
  virtual SedOneStep* clone() const;


  /**
   * Destructor for SedOneStep.
   */
  virtual ~SedOneStep();


  /**
   * Returns the value of the "step" attribute of this SedOneStep.
   *
   * @return the value of the "step" attribute of this SedOneStep as a double.
   */
  double getStep() const;


  /**
   * Predicate returning @c true if this SedOneStep's "step" attribute is set.
   *
   * @return @c true if this SedOneStep's "step" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetStep() const;


  /**
   * Sets the value of the "step" attribute of this SedOneStep.
   *
   * @param step double value of the "step" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStep(double step);


  /**
   * Unsets the value of the "step" attribute of this SedOneStep.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStep();


  /**
   * Returns the XML element name of this SedOneStep object.
   *
   * For SedOneStep, the XML element name is always @c "oneStep".
   *
   * @return the name of this element, i.e. @c "oneStep".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedOneStep object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_SIMULATION_ONESTEP, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedOneStep object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedOneStep have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedOneStep object are:
   * @li "step"
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
   * Gets the value of the "attributeName" attribute of this SedOneStep.
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
   * Gets the value of the "attributeName" attribute of this SedOneStep.
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
   * Gets the value of the "attributeName" attribute of this SedOneStep.
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
   * Gets the value of the "attributeName" attribute of this SedOneStep.
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
   * Gets the value of the "attributeName" attribute of this SedOneStep.
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
   * Predicate returning @c true if this SedOneStep's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedOneStep's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedOneStep.
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
   * Sets the value of the "attributeName" attribute of this SedOneStep.
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
   * Sets the value of the "attributeName" attribute of this SedOneStep.
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
   * Sets the value of the "attributeName" attribute of this SedOneStep.
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
   * Sets the value of the "attributeName" attribute of this SedOneStep.
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
   * Unsets the value of the "attributeName" attribute of this SedOneStep.
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
 * Creates a new SedOneStep_t using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedOneStep_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedOneStep_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedOneStep_t
 */
LIBSEDML_EXTERN
SedOneStep_t *
SedOneStep_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedOneStep_t object.
 *
 * @param sos the SedOneStep_t structure.
 *
 * @return a (deep) copy of this SedOneStep_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedOneStep_t
 */
LIBSEDML_EXTERN
SedOneStep_t*
SedOneStep_clone(const SedOneStep_t* sos);


/**
 * Frees this SedOneStep_t object.
 *
 * @param sos the SedOneStep_t structure.
 *
 * @memberof SedOneStep_t
 */
LIBSEDML_EXTERN
void
SedOneStep_free(SedOneStep_t* sos);


/**
 * Returns the value of the "step" attribute of this SedOneStep_t.
 *
 * @param sos the SedOneStep_t structure whose step is sought.
 *
 * @return the value of the "step" attribute of this SedOneStep_t as a double.
 *
 * @memberof SedOneStep_t
 */
LIBSEDML_EXTERN
double
SedOneStep_getStep(const SedOneStep_t * sos);


/**
 * Predicate returning @c 1 (true) if this SedOneStep_t's "step" attribute is
 * set.
 *
 * @param sos the SedOneStep_t structure.
 *
 * @return @c 1 (true) if this SedOneStep_t's "step" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedOneStep_t
 */
LIBSEDML_EXTERN
int
SedOneStep_isSetStep(const SedOneStep_t * sos);


/**
 * Sets the value of the "step" attribute of this SedOneStep_t.
 *
 * @param sos the SedOneStep_t structure.
 *
 * @param step double value of the "step" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedOneStep_t
 */
LIBSEDML_EXTERN
int
SedOneStep_setStep(SedOneStep_t * sos, double step);


/**
 * Unsets the value of the "step" attribute of this SedOneStep_t.
 *
 * @param sos the SedOneStep_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedOneStep_t
 */
LIBSEDML_EXTERN
int
SedOneStep_unsetStep(SedOneStep_t * sos);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedOneStep_t object have been set.
 *
 * @param sos the SedOneStep_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedOneStep_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedOneStep_t object are:
 * @li "step"
 *
 * @memberof SedOneStep_t
 */
LIBSEDML_EXTERN
int
SedOneStep_hasRequiredAttributes(const SedOneStep_t * sos);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedOneStep_H__ */


