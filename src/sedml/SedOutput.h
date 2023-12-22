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
  SedAlgorithm* mAlgorithm;

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
   * Returns the value of the "algorithm" element of this SedOutput.
   *
   * @return the value of the "algorithm" element of this SedOutput as a
   * SedAlgorithm*.
   */
  const SedAlgorithm* getAlgorithm() const;


  /**
   * Returns the value of the "algorithm" element of this SedOutput.
   *
   * @return the value of the "algorithm" element of this SedOutput as a
   * SedAlgorithm*.
   */
  SedAlgorithm* getAlgorithm();


  /**
   * Predicate returning @c true if this SedOutput's "algorithm" element is
   * set.
   *
   * @return @c true if this SedOutput's "algorithm" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetAlgorithm() const;


  /**
   * Sets the value of the "algorithm" element of this SedOutput.
   *
   * @param algorithm SedAlgorithm* value of the "algorithm" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAlgorithm(const SedAlgorithm* algorithm);


  /**
   * Creates a new SedAlgorithm object, adds it to this SedOutput object
   * and returns the SedAlgorithm object created.
   *
   * @return a new SedAlgorithm object instance.
   */
  SedAlgorithm* createAlgorithm();


  /**
   * Unsets the value of the "algorithm" element of this SedOutput.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAlgorithm();


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




  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

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




  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates and returns an new "elementName" object in this SedOutput.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds a new "elementName" object to this SedOutput.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SedBase* element);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * SedOutput.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SedBase* removeChildObject(const std::string& elementName,
                                     const std::string& id);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the number of "elementName" in this SedOutput.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedOutput.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SedBase* getObject(const std::string& elementName,
                             unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SedBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SedBase* getElementBySId(const std::string& id);

  /**
   * Returns a List of all child SedBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List pointer of pointers to all SedBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(SedElementFilter * filter = NULL);
  
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
 * Returns the value of the "algorithm" element of this SedOutput_t.
 *
 * @param ss the SedOutput_t structure whose algorithm is sought.
 *
 * @return the value of the "algorithm" element of this SedOutput_t as a
 * SedAlgorithm*.
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedOutput_getAlgorithm(const SedOutput_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedOutput_t's "algorithm"
 * element is set.
 *
 * @param ss the SedOutput_t structure.
 *
 * @return @c 1 (true) if this SedOutput_t's "algorithm" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_isSetAlgorithm(const SedOutput_t * ss);


/**
 * Sets the value of the "algorithm" element of this SedOutput_t.
 *
 * @param ss the SedOutput_t structure.
 *
 * @param algorithm SedAlgorithm_t* value of the "algorithm" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
int
SedOutput_setAlgorithm(SedOutput_t * ss,
                           const SedAlgorithm_t* algorithm);


/**
 * Creates a new SedAlgorithm_t object, adds it to this SedOutput_t object
 * and returns the SedAlgorithm_t object created.
 *
 * @param ss the SedOutput_t structure to which the SedAlgorithm_t should
 * be added.
 *
 * @return a new SedAlgorithm_t object instance.
 *
 * @memberof SedOutput_t
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedOutput_createAlgorithm(SedOutput_t* ss);


/**
 * Unsets the value of the "algorithm" element of this SedOutput_t.
 *
 * @param ss the SedOutput_t structure.
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
SedOutput_unsetAlgorithm(SedOutput_t * ss);


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


