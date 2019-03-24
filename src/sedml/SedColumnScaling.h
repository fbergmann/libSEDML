/**
 * @file SedColumnScaling.h
 * @brief Definition of the SedColumnScaling class.
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
 * @class SedColumnScaling
 * @sbmlbrief{sedml} TODO:Definition of the SedColumnScaling class.
 */


#ifndef SedColumnScaling_H__
#define SedColumnScaling_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedScaling.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedColumnScaling : public SedScaling
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mDataSource;

  /** @endcond */

public:

  /**
   * Creates a new SedColumnScaling using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedColumnScaling.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedColumnScaling.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedColumnScaling(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedColumnScaling using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedColumnScaling(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedColumnScaling.
   *
   * @param orig the SedColumnScaling instance to copy.
   */
  SedColumnScaling(const SedColumnScaling& orig);


  /**
   * Assignment operator for SedColumnScaling.
   *
   * @param rhs the SedColumnScaling object whose values are to be used as the
   * basis of the assignment.
   */
  SedColumnScaling& operator=(const SedColumnScaling& rhs);


  /**
   * Creates and returns a deep copy of this SedColumnScaling object.
   *
   * @return a (deep) copy of this SedColumnScaling object.
   */
  virtual SedColumnScaling* clone() const;


  /**
   * Destructor for SedColumnScaling.
   */
  virtual ~SedColumnScaling();


  /**
   * Returns the value of the "dataSource" attribute of this SedColumnScaling.
   *
   * @return the value of the "dataSource" attribute of this SedColumnScaling
   * as a string.
   */
  const std::string& getDataSource() const;


  /**
   * Predicate returning @c true if this SedColumnScaling's "dataSource"
   * attribute is set.
   *
   * @return @c true if this SedColumnScaling's "dataSource" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetDataSource() const;


  /**
   * Sets the value of the "dataSource" attribute of this SedColumnScaling.
   *
   * @param dataSource std::string& value of the "dataSource" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDataSource(const std::string& dataSource);


  /**
   * Unsets the value of the "dataSource" attribute of this SedColumnScaling.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDataSource();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedColumnScaling object.
   *
   * For SedColumnScaling, the XML element name is always @c "columnScaling".
   *
   * @return the name of this element, i.e. @c "columnScaling".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedColumnScaling object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   * @sedmlconstant{SEDML_COLUMNSCALING, SEDMLSedmlTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedColumnScaling object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedColumnScaling have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedColumnScaling object are:
   * @li "dataSource"
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
   * Gets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Gets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Gets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Gets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Gets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Predicate returning @c true if this SedColumnScaling's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedColumnScaling's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Sets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Sets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Sets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * Sets the value of the "attributeName" attribute of this SedColumnScaling.
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
   * SedColumnScaling.
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
 * Creates a new SedColumnScaling_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedColumnScaling_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedColumnScaling_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedColumnScaling_t
 */
LIBSEDML_EXTERN
SedColumnScaling_t *
SedColumnScaling_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedColumnScaling_t object.
 *
 * @param scs the SedColumnScaling_t structure.
 *
 * @return a (deep) copy of this SedColumnScaling_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedColumnScaling_t
 */
LIBSEDML_EXTERN
SedColumnScaling_t*
SedColumnScaling_clone(const SedColumnScaling_t* scs);


/**
 * Frees this SedColumnScaling_t object.
 *
 * @param scs the SedColumnScaling_t structure.
 *
 * @memberof SedColumnScaling_t
 */
LIBSEDML_EXTERN
void
SedColumnScaling_free(SedColumnScaling_t* scs);


/**
 * Returns the value of the "dataSource" attribute of this SedColumnScaling_t.
 *
 * @param scs the SedColumnScaling_t structure whose dataSource is sought.
 *
 * @return the value of the "dataSource" attribute of this SedColumnScaling_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedColumnScaling_t
 */
LIBSEDML_EXTERN
char *
SedColumnScaling_getDataSource(const SedColumnScaling_t * scs);


/**
 * Predicate returning @c 1 (true) if this SedColumnScaling_t's "dataSource"
 * attribute is set.
 *
 * @param scs the SedColumnScaling_t structure.
 *
 * @return @c 1 (true) if this SedColumnScaling_t's "dataSource" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedColumnScaling_t
 */
LIBSEDML_EXTERN
int
SedColumnScaling_isSetDataSource(const SedColumnScaling_t * scs);


/**
 * Sets the value of the "dataSource" attribute of this SedColumnScaling_t.
 *
 * @param scs the SedColumnScaling_t structure.
 *
 * @param dataSource const char * value of the "dataSource" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedColumnScaling_t
 */
LIBSEDML_EXTERN
int
SedColumnScaling_setDataSource(SedColumnScaling_t * scs,
                               const char * dataSource);


/**
 * Unsets the value of the "dataSource" attribute of this SedColumnScaling_t.
 *
 * @param scs the SedColumnScaling_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedColumnScaling_t
 */
LIBSEDML_EXTERN
int
SedColumnScaling_unsetDataSource(SedColumnScaling_t * scs);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedColumnScaling_t object have been set.
 *
 * @param scs the SedColumnScaling_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedColumnScaling_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedColumnScaling_t object are:
 * @li "dataSource"
 *
 * @memberof SedColumnScaling_t
 */
LIBSEDML_EXTERN
int
SedColumnScaling_hasRequiredAttributes(const SedColumnScaling_t * scs);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedColumnScaling_H__ */


