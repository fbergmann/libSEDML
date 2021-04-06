/**
 * @file SedChange.h
 * @brief Definition of the SedChange class.
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
 * @class SedChange
 * @sbmlbrief{sedml} TODO:Definition of the SedChange class.
 */


#ifndef SedChange_H__
#define SedChange_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedAddXML;
class SedChangeXML;
class SedRemoveXML;
class SedChangeAttribute;
class SedComputeChange;

class LIBSEDML_EXTERN SedChange : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mTarget;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedChange using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this SedChange.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedChange.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedChange(unsigned int level = SEDML_DEFAULT_LEVEL,
            unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedChange using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedChange(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedChange.
   *
   * @param orig the SedChange instance to copy.
   */
  SedChange(const SedChange& orig);


  /**
   * Assignment operator for SedChange.
   *
   * @param rhs the SedChange object whose values are to be used as the basis
   * of the assignment.
   */
  SedChange& operator=(const SedChange& rhs);


  /**
   * Creates and returns a deep copy of this SedChange object.
   *
   * @return a (deep) copy of this SedChange object.
   */
  virtual SedChange* clone() const;


  /**
   * Destructor for SedChange.
   */
  virtual ~SedChange();


  /**
   * Returns the value of the "target" attribute of this SedChange.
   *
   * @return the value of the "target" attribute of this SedChange as a string.
   */
  const std::string& getTarget() const;


  /**
   * Predicate returning @c true if this SedChange's "target" attribute is set.
   *
   * @return @c true if this SedChange's "target" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Sets the value of the "target" attribute of this SedChange.
   *
   * @param target std::string& value of the "target" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p target = @c NULL or an empty string is
   * equivalent to calling unsetTarget().
   */
  int setTarget(const std::string& target);


  /**
   * Unsets the value of the "target" attribute of this SedChange.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Predicate returning @c true if this abstract "SedChange" is of type
   * SedAddXML
   *
   * @return @c true if this abstract "SedChange" is of type SedAddXML,
   * @c false otherwise
   */
  virtual bool isSedAddXML() const;


  /**
   * Predicate returning @c true if this abstract "SedChange" is of type
   * SedChangeXML
   *
   * @return @c true if this abstract "SedChange" is of type SedChangeXML,
   * @c false otherwise
   */
  virtual bool isSedChangeXML() const;


  /**
   * Predicate returning @c true if this abstract "SedChange" is of type
   * SedRemoveXML
   *
   * @return @c true if this abstract "SedChange" is of type SedRemoveXML,
   * @c false otherwise
   */
  virtual bool isSedRemoveXML() const;


  /**
   * Predicate returning @c true if this abstract "SedChange" is of type
   * SedChangeAttribute
   *
   * @return @c true if this abstract "SedChange" is of type
   * SedChangeAttribute, @c false otherwise
   */
  virtual bool isSedChangeAttribute() const;


  /**
   * Predicate returning @c true if this abstract "SedChange" is of type
   * SedComputeChange
   *
   * @return @c true if this abstract "SedChange" is of type SedComputeChange,
   * @c false otherwise
   */
  virtual bool isSedComputeChange() const;


  /**
   * Returns the XML element name of this SedChange object.
   *
   * For SedChange, the XML element name is always @c "change".
   *
   * @return the name of this element, i.e. @c "change".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedChange object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedChange object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_CHANGE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedChange object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedChange have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedChange object are:
   * @li "target"
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
   * Gets the value of the "attributeName" attribute of this SedChange.
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
   * Gets the value of the "attributeName" attribute of this SedChange.
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
   * Gets the value of the "attributeName" attribute of this SedChange.
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
   * Gets the value of the "attributeName" attribute of this SedChange.
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
   * Gets the value of the "attributeName" attribute of this SedChange.
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
   * Predicate returning @c true if this SedChange's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedChange's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedChange.
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
   * Sets the value of the "attributeName" attribute of this SedChange.
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
   * Sets the value of the "attributeName" attribute of this SedChange.
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
   * Sets the value of the "attributeName" attribute of this SedChange.
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
   * Sets the value of the "attributeName" attribute of this SedChange.
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
   * Unsets the value of the "attributeName" attribute of this SedChange.
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

  static std::string _trim(const std::string& text);

};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedAddXML using the given SED-ML Level and @ p version values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedChange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedChange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
SedAddXML_t *
SedChange_createAddXML(unsigned int level, unsigned int version);


/**
 * Creates a new SedChangeXML using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedChange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedChange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
SedChangeXML_t *
SedChange_createChangeXML(unsigned int level, unsigned int version);


/**
 * Creates a new SedRemoveXML using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedChange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedChange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
SedRemoveXML_t *
SedChange_createRemoveXML(unsigned int level, unsigned int version);


/**
 * Creates a new SedChangeAttribute using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedChange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedChange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
SedChangeAttribute_t *
SedChange_createChangeAttribute(unsigned int level, unsigned int version);


/**
 * Creates a new SedComputeChange using the given SED-ML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SED-ML Level to assign to this SedChange_t.
 *
 * @param version an unsigned int, the SED-ML Version to assign to this
 * SedChange_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
SedComputeChange_t *
SedChange_createComputeChange(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedChange_t object.
 *
 * @param sc the SedChange_t structure.
 *
 * @return a (deep) copy of this SedChange_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
SedChange_t*
SedChange_clone(const SedChange_t* sc);


/**
 * Frees this SedChange_t object.
 *
 * @param sc the SedChange_t structure.
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
void
SedChange_free(SedChange_t* sc);


/**
 * Returns the value of the "target" attribute of this SedChange_t.
 *
 * @param sc the SedChange_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SedChange_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
char *
SedChange_getTarget(const SedChange_t * sc);


/**
 * Predicate returning @c 1 (true) if this SedChange_t's "target" attribute is
 * set.
 *
 * @param sc the SedChange_t structure.
 *
 * @return @c 1 (true) if this SedChange_t's "target" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_isSetTarget(const SedChange_t * sc);


/**
 * Sets the value of the "target" attribute of this SedChange_t.
 *
 * @param sc the SedChange_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p target = @c NULL or an empty string is
 * equivalent to calling SedChange_unsetTarget().
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_setTarget(SedChange_t * sc, const char * target);


/**
 * Unsets the value of the "target" attribute of this SedChange_t.
 *
 * @param sc the SedChange_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_unsetTarget(SedChange_t * sc);


/**
 * Predicate returning @c 1 if this SedChange_t is of type SedAddXML_t
 *
 * @param sc the SedChange_t structure.
 *
 * @return @c 1 if this SedChange_t is of type SedAddXML_t, @c 0 otherwise
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedAddXML(const SedChange_t * sc);


/**
 * Predicate returning @c 1 if this SedChange_t is of type SedChangeXML_t
 *
 * @param sc the SedChange_t structure.
 *
 * @return @c 1 if this SedChange_t is of type SedChangeXML_t, @c 0 otherwise
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedChangeXML(const SedChange_t * sc);


/**
 * Predicate returning @c 1 if this SedChange_t is of type SedRemoveXML_t
 *
 * @param sc the SedChange_t structure.
 *
 * @return @c 1 if this SedChange_t is of type SedRemoveXML_t, @c 0 otherwise
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedRemoveXML(const SedChange_t * sc);


/**
 * Predicate returning @c 1 if this SedChange_t is of type SedChangeAttribute_t
 *
 * @param sc the SedChange_t structure.
 *
 * @return @c 1 if this SedChange_t is of type SedChangeAttribute_t, @c 0
 * otherwise
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedChangeAttribute(const SedChange_t * sc);


/**
 * Predicate returning @c 1 if this SedChange_t is of type SedComputeChange_t
 *
 * @param sc the SedChange_t structure.
 *
 * @return @c 1 if this SedChange_t is of type SedComputeChange_t, @c 0
 * otherwise
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_isSedComputeChange(const SedChange_t * sc);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedChange_t object have been set.
 *
 * @param sc the SedChange_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedChange_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedChange_t object are:
 * @li "target"
 *
 * @memberof SedChange_t
 */
LIBSEDML_EXTERN
int
SedChange_hasRequiredAttributes(const SedChange_t * sc);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedChange_H__ */


