/**
 * @file SedLeastSquareObjectiveFunction.h
 * @brief Definition of the SedLeastSquareObjectiveFunction class.
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
 * @class SedLeastSquareObjectiveFunction
 * @sbmlbrief{sedml} TODO:Definition of the SedLeastSquareObjectiveFunction
 * class.
 */


#ifndef SedLeastSquareObjectiveFunction_H__
#define SedLeastSquareObjectiveFunction_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedObjective.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedLeastSquareObjectiveFunction : public SedObjective
{

public:

  /**
   * Creates a new SedLeastSquareObjectiveFunction using the given SED-ML Level
   * and @ p version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedLeastSquareObjectiveFunction.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedLeastSquareObjectiveFunction.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedLeastSquareObjectiveFunction(unsigned int level = SEDML_DEFAULT_LEVEL,
                                  unsigned int version =
                                    SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedLeastSquareObjectiveFunction using the given
   * SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedLeastSquareObjectiveFunction(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedLeastSquareObjectiveFunction.
   *
   * @param orig the SedLeastSquareObjectiveFunction instance to copy.
   */
  SedLeastSquareObjectiveFunction(const SedLeastSquareObjectiveFunction& orig);


  /**
   * Assignment operator for SedLeastSquareObjectiveFunction.
   *
   * @param rhs the SedLeastSquareObjectiveFunction object whose values are to
   * be used as the basis of the assignment.
   */
  SedLeastSquareObjectiveFunction& operator=(const
    SedLeastSquareObjectiveFunction& rhs);


  /**
   * Creates and returns a deep copy of this SedLeastSquareObjectiveFunction
   * object.
   *
   * @return a (deep) copy of this SedLeastSquareObjectiveFunction object.
   */
  virtual SedLeastSquareObjectiveFunction* clone() const;


  /**
   * Destructor for SedLeastSquareObjectiveFunction.
   */
  virtual ~SedLeastSquareObjectiveFunction();


  /**
   * Returns the XML element name of this SedLeastSquareObjectiveFunction
   * object.
   *
   * For SedLeastSquareObjectiveFunction, the XML element name is always
   * @c "leastSquareObjectiveFunction".
   *
   * @return the name of this element, i.e. @c "leastSquareObjectiveFunction".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedLeastSquareObjectiveFunction
   * object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_LEAST_SQUARE_OBJECTIVE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedLeastSquareObjectiveFunction object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedLeastSquareObjectiveFunction have been set, otherwise @c false is
   * returned.
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
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
   * Predicate returning @c true if this SedLeastSquareObjectiveFunction's
   * attribute "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedLeastSquareObjectiveFunction's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
   * SedLeastSquareObjectiveFunction.
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
 * Creates a new SedLeastSquareObjectiveFunction_t using the given SED-ML Level
 * and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this
 * SedLeastSquareObjectiveFunction_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedLeastSquareObjectiveFunction_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedLeastSquareObjectiveFunction_t
 */
LIBSEDML_EXTERN
SedLeastSquareObjectiveFunction_t *
SedLeastSquareObjectiveFunction_create(unsigned int level,
                                       unsigned int version);


/**
 * Creates and returns a deep copy of this SedLeastSquareObjectiveFunction_t
 * object.
 *
 * @param slsof the SedLeastSquareObjectiveFunction_t structure.
 *
 * @return a (deep) copy of this SedLeastSquareObjectiveFunction_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedLeastSquareObjectiveFunction_t
 */
LIBSEDML_EXTERN
SedLeastSquareObjectiveFunction_t*
SedLeastSquareObjectiveFunction_clone(const SedLeastSquareObjectiveFunction_t*
  slsof);


/**
 * Frees this SedLeastSquareObjectiveFunction_t object.
 *
 * @param slsof the SedLeastSquareObjectiveFunction_t structure.
 *
 * @memberof SedLeastSquareObjectiveFunction_t
 */
LIBSEDML_EXTERN
void
SedLeastSquareObjectiveFunction_free(SedLeastSquareObjectiveFunction_t* slsof);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedLeastSquareObjectiveFunction_t object have been set.
 *
 * @param slsof the SedLeastSquareObjectiveFunction_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedLeastSquareObjectiveFunction_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof SedLeastSquareObjectiveFunction_t
 */
LIBSEDML_EXTERN
int
SedLeastSquareObjectiveFunction_hasRequiredAttributes(const
  SedLeastSquareObjectiveFunction_t * slsof);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedLeastSquareObjectiveFunction_H__ */


