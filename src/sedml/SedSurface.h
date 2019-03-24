/**
 * @file SedSurface.h
 * @brief Definition of the SedSurface class.
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
 * @class SedSurface
 * @sbmlbrief{sedml} TODO:Definition of the SedSurface class.
 */

/**
 * <!-- ~ ~ ~ ~ ~ Start of common documentation strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * The following text is used as common documentation blocks copied multiple
 * times elsewhere in this file. The use of @class is a hack needed because
 * Doxygen's @copydetails command has limited functionality. Symbols
 * beginning with "doc_" are marked as ignored in our Doxygen configuration.
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ -->
 *
 *
 * @class doc_sedsurface_surfaceType
 *
 * @par
 * The attribute "surfaceType" on a SedSurface object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sedml specification, the following are the
 * allowable values for "surfaceType":
 * <ul>
 * <li> @c "parametricCurve", TODO:add description
 *
 * <li> @c "surfaceMesh", TODO:add description
 *
 * <li> @c "surfaceContour", TODO:add description
 *
 * <li> @c "contour", TODO:add description
 *
 * <li> @c "heatMap", TODO:add description
 *
 * <li> @c "stackedCurves", TODO:add description
 *
 * <li> @c "bar", TODO:add description
 *
 * </ul>
 */


#ifndef SedSurface_H__
#define SedSurface_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/common/SedmlEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedCurve.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedSurface : public SedCurve
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  bool mLogZ;
  bool mIsSetLogZ;
  std::string mZDataReference;
  SurfaceType_t mSurfaceType;

  /** @endcond */

public:

  /**
   * Creates a new SedSurface using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedSurface.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedSurface.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSurface(unsigned int level = SEDML_DEFAULT_LEVEL,
             unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedSurface using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedSurface(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedSurface.
   *
   * @param orig the SedSurface instance to copy.
   */
  SedSurface(const SedSurface& orig);


  /**
   * Assignment operator for SedSurface.
   *
   * @param rhs the SedSurface object whose values are to be used as the basis
   * of the assignment.
   */
  SedSurface& operator=(const SedSurface& rhs);


  /**
   * Creates and returns a deep copy of this SedSurface object.
   *
   * @return a (deep) copy of this SedSurface object.
   */
  virtual SedSurface* clone() const;


  /**
   * Destructor for SedSurface.
   */
  virtual ~SedSurface();


  /**
   * Returns the value of the "logZ" attribute of this SedSurface.
   *
   * @return the value of the "logZ" attribute of this SedSurface as a boolean.
   */
  bool getLogZ() const;


  /**
   * Returns the value of the "zDataReference" attribute of this SedSurface.
   *
   * @return the value of the "zDataReference" attribute of this SedSurface as
   * a string.
   */
  const std::string& getZDataReference() const;


  /**
   * Returns the value of the "surfaceType" attribute of this SedSurface.
   *
   * @return the value of the "surfaceType" attribute of this SedSurface as a
   * SurfaceType_t.
   *
   * @copydetails doc_sedsurface_surfaceType
   * @if clike The value is drawn from the enumeration @ref SurfaceType_t
   * @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SEDML_SURFACETYPE_PARAMETRICCURVE, SurfaceType_t}
   * @li @sbmlconstant{SEDML_SURFACETYPE_SURFACEMESH, SurfaceType_t}
   * @li @sbmlconstant{SEDML_SURFACETYPE_SURFACECONTOUR, SurfaceType_t}
   * @li @sbmlconstant{SEDML_SURFACETYPE_CONTOUR, SurfaceType_t}
   * @li @sbmlconstant{SEDML_SURFACETYPE_HEATMAP, SurfaceType_t}
   * @li @sbmlconstant{SEDML_SURFACETYPE_STACKEDCURVES, SurfaceType_t}
   * @li @sbmlconstant{SEDML_SURFACETYPE_BAR, SurfaceType_t}
   * @li @sbmlconstant{SEDML_SURFACETYPE_INVALID, SurfaceType_t}
   */
  SurfaceType_t getSurfaceType() const;


  /**
   * Returns the value of the "surfaceType" attribute of this SedSurface.
   *
   * @return the value of the "surfaceType" attribute of this SedSurface as a
   * string.
   *
   * @copydetails doc_sedsurface_surfaceType
   * The possible values returned by this method are:
   * @li @c "parametricCurve"
   * @li @c "surfaceMesh"
   * @li @c "surfaceContour"
   * @li @c "contour"
   * @li @c "heatMap"
   * @li @c "stackedCurves"
   * @li @c "bar"
   * @li @c "invalid SurfaceType value"
   */
  std::string getSurfaceTypeAsString() const;


  /**
   * Predicate returning @c true if this SedSurface's "logZ" attribute is set.
   *
   * @return @c true if this SedSurface's "logZ" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLogZ() const;


  /**
   * Predicate returning @c true if this SedSurface's "zDataReference"
   * attribute is set.
   *
   * @return @c true if this SedSurface's "zDataReference" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetZDataReference() const;


  /**
   * Predicate returning @c true if this SedSurface's "surfaceType" attribute
   * is set.
   *
   * @return @c true if this SedSurface's "surfaceType" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sedsurface_surfaceType
   */
  bool isSetSurfaceType() const;


  /**
   * Sets the value of the "logZ" attribute of this SedSurface.
   *
   * @param logZ bool value of the "logZ" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLogZ(bool logZ);


  /**
   * Sets the value of the "zDataReference" attribute of this SedSurface.
   *
   * @param zDataReference std::string& value of the "zDataReference" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setZDataReference(const std::string& zDataReference);


  /**
   * Sets the value of the "surfaceType" attribute of this SedSurface.
   *
   * @param surfaceType @if clike SurfaceType_t@else int@endif value of the
   * "surfaceType" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedsurface_surfaceType
   */
  int setSurfaceType(const SurfaceType_t surfaceType);


  /**
   * Sets the value of the "surfaceType" attribute of this SedSurface.
   *
   * @param surfaceType std::string& of the "surfaceType" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sedsurface_surfaceType
   */
  int setSurfaceType(const std::string& surfaceType);


  /**
   * Unsets the value of the "logZ" attribute of this SedSurface.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLogZ();


  /**
   * Unsets the value of the "zDataReference" attribute of this SedSurface.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetZDataReference();


  /**
   * Unsets the value of the "surfaceType" attribute of this SedSurface.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sedsurface_surfaceType
   */
  int unsetSurfaceType();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SedSurface object.
   *
   * For SedSurface, the XML element name is always @c "surface".
   *
   * @return the name of this element, i.e. @c "surface".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedSurface object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   * @sedmlconstant{SEDML_OUTPUT_SURFACE, SedmlmlTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedSurface object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedSurface have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedSurface object are:
   * @li "logZ"
   * @li "zDataReference"
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
   * Gets the value of the "attributeName" attribute of this SedSurface.
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
   * Gets the value of the "attributeName" attribute of this SedSurface.
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
   * Gets the value of the "attributeName" attribute of this SedSurface.
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
   * Gets the value of the "attributeName" attribute of this SedSurface.
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
   * Gets the value of the "attributeName" attribute of this SedSurface.
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
   * Predicate returning @c true if this SedSurface's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedSurface's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedSurface.
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
   * Sets the value of the "attributeName" attribute of this SedSurface.
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
   * Sets the value of the "attributeName" attribute of this SedSurface.
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
   * Sets the value of the "attributeName" attribute of this SedSurface.
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
   * Sets the value of the "attributeName" attribute of this SedSurface.
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
   * Unsets the value of the "attributeName" attribute of this SedSurface.
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
 * Creates a new SedSurface_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedSurface_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedSurface_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
SedSurface_t *
SedSurface_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedSurface_t object.
 *
 * @param ss the SedSurface_t structure.
 *
 * @return a (deep) copy of this SedSurface_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedSurface_clone(const SedSurface_t* ss);


/**
 * Frees this SedSurface_t object.
 *
 * @param ss the SedSurface_t structure.
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
void
SedSurface_free(SedSurface_t* ss);


/**
 * Returns the value of the "logZ" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure whose logZ is sought.
 *
 * @return the value of the "logZ" attribute of this SedSurface_t as a boolean.
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_getLogZ(const SedSurface_t * ss);


/**
 * Returns the value of the "zDataReference" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure whose zDataReference is sought.
 *
 * @return the value of the "zDataReference" attribute of this SedSurface_t as
 * a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
char *
SedSurface_getZDataReference(const SedSurface_t * ss);


/**
 * Returns the value of the "surfaceType" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure whose surfaceType is sought.
 *
 * @return the value of the "surfaceType" attribute of this SedSurface_t as a
 * SurfaceType_t.
 *
 * @copydetails doc_sedsurface_surfaceType
 * @if clike The value is drawn from the enumeration @ref SurfaceType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SEDML_SURFACETYPE_PARAMETRICCURVE, SurfaceType_t}
 * @li @sbmlconstant{SEDML_SURFACETYPE_SURFACEMESH, SurfaceType_t}
 * @li @sbmlconstant{SEDML_SURFACETYPE_SURFACECONTOUR, SurfaceType_t}
 * @li @sbmlconstant{SEDML_SURFACETYPE_CONTOUR, SurfaceType_t}
 * @li @sbmlconstant{SEDML_SURFACETYPE_HEATMAP, SurfaceType_t}
 * @li @sbmlconstant{SEDML_SURFACETYPE_STACKEDCURVES, SurfaceType_t}
 * @li @sbmlconstant{SEDML_SURFACETYPE_BAR, SurfaceType_t}
 * @li @sbmlconstant{SEDML_SURFACETYPE_INVALID, SurfaceType_t}
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
SurfaceType_t
SedSurface_getSurfaceType(const SedSurface_t * ss);


/**
 * Returns the value of the "surfaceType" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure whose surfaceType is sought.
 *
 * @return the value of the "surfaceType" attribute of this SedSurface_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sedsurface_surfaceType
 * The possible values returned by this method are:
 * @li @c "parametricCurve"
 * @li @c "surfaceMesh"
 * @li @c "surfaceContour"
 * @li @c "contour"
 * @li @c "heatMap"
 * @li @c "stackedCurves"
 * @li @c "bar"
 * @li @c "invalid SurfaceType value"
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
char *
SedSurface_getSurfaceTypeAsString(const SedSurface_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedSurface_t's "logZ" attribute is
 * set.
 *
 * @param ss the SedSurface_t structure.
 *
 * @return @c 1 (true) if this SedSurface_t's "logZ" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_isSetLogZ(const SedSurface_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedSurface_t's "zDataReference"
 * attribute is set.
 *
 * @param ss the SedSurface_t structure.
 *
 * @return @c 1 (true) if this SedSurface_t's "zDataReference" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_isSetZDataReference(const SedSurface_t * ss);


/**
 * Predicate returning @c 1 (true) if this SedSurface_t's "surfaceType"
 * attribute is set.
 *
 * @param ss the SedSurface_t structure.
 *
 * @return @c 1 (true) if this SedSurface_t's "surfaceType" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sedsurface_surfaceType
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_isSetSurfaceType(const SedSurface_t * ss);


/**
 * Sets the value of the "logZ" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure.
 *
 * @param logZ int value of the "logZ" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_setLogZ(SedSurface_t * ss, int logZ);


/**
 * Sets the value of the "zDataReference" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure.
 *
 * @param zDataReference const char * value of the "zDataReference" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_setZDataReference(SedSurface_t * ss, const char * zDataReference);


/**
 * Sets the value of the "surfaceType" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure.
 *
 * @param surfaceType SurfaceType_t value of the "surfaceType" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedsurface_surfaceType
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_setSurfaceType(SedSurface_t * ss, SurfaceType_t surfaceType);


/**
 * Sets the value of the "surfaceType" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure.
 *
 * @param surfaceType const char * of the "surfaceType" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedsurface_surfaceType
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_setSurfaceTypeAsString(SedSurface_t * ss,
                                  const char * surfaceType);


/**
 * Unsets the value of the "logZ" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_unsetLogZ(SedSurface_t * ss);


/**
 * Unsets the value of the "zDataReference" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_unsetZDataReference(SedSurface_t * ss);


/**
 * Unsets the value of the "surfaceType" attribute of this SedSurface_t.
 *
 * @param ss the SedSurface_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sedsurface_surfaceType
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_unsetSurfaceType(SedSurface_t * ss);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSurface_t object have been set.
 *
 * @param ss the SedSurface_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SedSurface_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SedSurface_t object are:
 * @li "logZ"
 * @li "zDataReference"
 *
 * @memberof SedSurface_t
 */
LIBSEDML_EXTERN
int
SedSurface_hasRequiredAttributes(const SedSurface_t * ss);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedSurface_H__ */


