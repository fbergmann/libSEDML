/**
 * @file SedOutput.h
 * @brief Definition of the SedOutput class.
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
 * @class SedOutput
 * @sbmlbrief{sedml} TODO:Definition of the SedOutput class.
 */


#ifndef SedOutput_H__
#define SedOutput_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedReport;
class SedPlot2D;
class SedPlot3D;
class SedFigure;
class SedParameterEstimationResultPlot;

class LIBSEDML_EXTERN SedOutput : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedOutput using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedOutput.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedOutput.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedOutput(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedOutput using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedOutput(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedOutput.
   *
   * @param orig the SedOutput instance to copy.
   */
  SedOutput(const SedOutput& orig);


  /**
   * Assignment operator for SedOutput.
   *
   * @param rhs the SedOutput object whose values are to be used as the basis
   * of the assignment.
   */
  SedOutput& operator=(const SedOutput& rhs);


  /**
   * Creates and returns a deep copy of this SedOutput object.
   *
   * @return a (deep) copy of this SedOutput object.
   */
  virtual SedOutput* clone() const;


  /**
   * Destructor for SedOutput.
   */
  virtual ~SedOutput();


  /**
   * Predicate returning @c true if this abstract "SedOutput" is of type
   * SedReport
   *
   * @return @c true if this abstract "SedOutput" is of type SedReport,
   * @c false otherwise
   */
  virtual bool isSedReport() const;


  /**
   * Predicate returning @c true if this abstract "SedOutput" is of type
   * SedPlot2D
   *
   * @return @c true if this abstract "SedOutput" is of type SedPlot2D,
   * @c false otherwise
   */
  virtual bool isSedPlot2D() const;


  /**
   * Predicate returning @c true if this abstract "SedOutput" is of type
   * SedPlot3D
   *
   * @return @c true if this abstract "SedOutput" is of type SedPlot3D,
   * @c false otherwise
   */
  virtual bool isSedPlot3D() const;


  /**
   * Predicate returning @c true if this abstract "SedOutput" is of type
   * SedFigure
   *
   * @return @c true if this abstract "SedOutput" is of type SedFigure,
   * @c false otherwise
   */
  virtual bool isSedFigure() const;


  /**
   * Predicate returning @c true if this abstract "SedOutput" is of type
   * SedParameterEstimationResultPlot
   *
   * @return @c true if this abstract "SedOutput" is of type
   * SedParameterEstimationResultPlot, @c false otherwise
   */
  virtual bool isSedParameterEstimationResultPlot() const;


  /**
   * Returns the XML element name of this SedOutput object.
   *
   * For SedOutput, the XML element name is always @c "output".
   *
   * @return the name of this element, i.e. @c "output".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedOutput object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedOutput object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_OUTPUT, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedOutput object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedOutput have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SedOutput.
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
   * Gets the value of the "attributeName" attribute of this SedOutput.
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
   * Gets the value of the "attributeName" attribute of this SedOutput.
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
   * Gets the value of the "attributeName" attribute of this SedOutput.
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
   * Gets the value of the "attributeName" attribute of this SedOutput.
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
   * Predicate returning @c true if this SedOutput's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedOutput's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedOutput.
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
   * Sets the value of the "attributeName" attribute of this SedOutput.
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
   * Sets the value of the "attributeName" attribute of this SedOutput.
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
   * Sets the value of the "attributeName" attribute of this SedOutput.
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
   * Sets the value of the "attributeName" attribute of this SedOutput.
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
   * Unsets the value of the "attributeName" attribute of this SedOutput.
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
 * Creates a new SedReport using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedOutput_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedOutput_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
SedReport_t *
SedOutput_createReport(unsigned int level, unsigned int version);


/**
 * Creates a new SedPlot2D using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedOutput_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedOutput_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
SedPlot2D_t *
SedOutput_createPlot2D(unsigned int level, unsigned int version);


/**
 * Creates a new SedPlot3D using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedOutput_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedOutput_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
SedPlot3D_t *
SedOutput_createPlot3D(unsigned int level, unsigned int version);


/**
 * Creates a new SedFigure using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedOutput_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedOutput_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
SedFigure_t *
SedOutput_createFigure(unsigned int level, unsigned int version);


/**
 * Creates a new SedParameterEstimationResultPlot using the given SED-ML Level
 * and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedOutput_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedOutput_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
SedParameterEstimationResultPlot_t *
SedOutput_createParameterEstimationResultPlot(unsigned int level,
                                              unsigned int version);


/**
 * Creates and returns a deep copy of this SedOutput_t object.
 *
 * @param so the SedOutput_t structure.
 *
 * @return a (deep) copy of this SedOutput_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedOutput_clone(const SedOutput_t* so);


/**
 * Frees this SedOutput_t object.
 *
 * @param so the SedOutput_t structure.
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
void
SedOutput_free(SedOutput_t* so);


/**
 * Returns the value of the "id" attribute of this SedOutput_t.
 *
 * @param so the SedOutput_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedOutput_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
char *
SedOutput_getId(const SedOutput_t * so);


/**
 * Returns the value of the "name" attribute of this SedOutput_t.
 *
 * @param so the SedOutput_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedOutput_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
char *
SedOutput_getName(const SedOutput_t * so);


/**
 * Predicate returning @c 1 (true) if this SedOutput_t's "id" attribute is set.
 *
 * @param so the SedOutput_t structure.
 *
 * @return @c 1 (true) if this SedOutput_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSetId(const SedOutput_t * so);


/**
 * Predicate returning @c 1 (true) if this SedOutput_t's "name" attribute is
 * set.
 *
 * @param so the SedOutput_t structure.
 *
 * @return @c 1 (true) if this SedOutput_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSetName(const SedOutput_t * so);


/**
 * Sets the value of the "id" attribute of this SedOutput_t.
 *
 * @param so the SedOutput_t structure.
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
 * to calling SedOutput_unsetId().
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_setId(SedOutput_t * so, const char * id);


/**
 * Sets the value of the "name" attribute of this SedOutput_t.
 *
 * @param so the SedOutput_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedOutput_unsetName().
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_setName(SedOutput_t * so, const char * name);


/**
 * Unsets the value of the "id" attribute of this SedOutput_t.
 *
 * @param so the SedOutput_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_unsetId(SedOutput_t * so);


/**
 * Unsets the value of the "name" attribute of this SedOutput_t.
 *
 * @param so the SedOutput_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_unsetName(SedOutput_t * so);


/**
 * Predicate returning @c 1 if this SedOutput_t is of type SedReport_t
 *
 * @param so the SedOutput_t structure.
 *
 * @return @c 1 if this SedOutput_t is of type SedReport_t, @c 0 otherwise
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedReport(const SedOutput_t * so);


/**
 * Predicate returning @c 1 if this SedOutput_t is of type SedPlot2D_t
 *
 * @param so the SedOutput_t structure.
 *
 * @return @c 1 if this SedOutput_t is of type SedPlot2D_t, @c 0 otherwise
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedPlot2D(const SedOutput_t * so);


/**
 * Predicate returning @c 1 if this SedOutput_t is of type SedPlot3D_t
 *
 * @param so the SedOutput_t structure.
 *
 * @return @c 1 if this SedOutput_t is of type SedPlot3D_t, @c 0 otherwise
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedPlot3D(const SedOutput_t * so);


/**
 * Predicate returning @c 1 if this SedOutput_t is of type SedFigure_t
 *
 * @param so the SedOutput_t structure.
 *
 * @return @c 1 if this SedOutput_t is of type SedFigure_t, @c 0 otherwise
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedFigure(const SedOutput_t * so);


/**
 * Predicate returning @c 1 if this SedOutput_t is of type
 * SedParameterEstimationResultPlot_t
 *
 * @param so the SedOutput_t structure.
 *
 * @return @c 1 if this SedOutput_t is of type
 * SedParameterEstimationResultPlot_t, @c 0 otherwise
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSedParameterEstimationResultPlot(const SedOutput_t * so);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedOutput_t object have been set.
 *
 * @param so the SedOutput_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedOutput_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_hasRequiredAttributes(const SedOutput_t * so);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedOutput_H__ */


