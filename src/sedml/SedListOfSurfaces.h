/**
 * @file SedListOfSurfaces.h
 * @brief Definition of the SedListOfSurfaces class.
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
 * @class SedListOfSurfaces
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfSurfaces class.
 */


#ifndef SedListOfSurfaces_H__
#define SedListOfSurfaces_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedSurface.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfSurfaces : public SedListOf
{

public:

  /**
   * Creates a new SedListOfSurfaces using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfSurfaces.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfSurfaces.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSurfaces(unsigned int level = SEDML_DEFAULT_LEVEL,
                    unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfSurfaces using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfSurfaces(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfSurfaces.
   *
   * @param orig the SedListOfSurfaces instance to copy.
   */
  SedListOfSurfaces(const SedListOfSurfaces& orig);


  /**
   * Assignment operator for SedListOfSurfaces.
   *
   * @param rhs the SedListOfSurfaces object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfSurfaces& operator=(const SedListOfSurfaces& rhs);


  /**
   * Sort the SedListOfCurves according to the 'order' attribute.
   *
   */
  void sort();

   /**
   * Creates and returns a deep copy of this SedListOfSurfaces object.
   *
   * @return a (deep) copy of this SedListOfSurfaces object.
   */
  virtual SedListOfSurfaces* clone() const;


  /**
   * Destructor for SedListOfSurfaces.
   */
  virtual ~SedListOfSurfaces();


  /**
   * Get a SedSurface from the SedListOfSurfaces.
   *
   * @param n an unsigned int representing the index of the SedSurface to
   * retrieve.
   *
   * @return the nth SedSurface in this SedListOfSurfaces or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see get(const std::string& sid)
   * @see getNumSurfaces()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSurface* get(unsigned int n);


  /**
   * Get a SedSurface from the SedListOfSurfaces.
   *
   * @param n an unsigned int representing the index of the SedSurface to
   * retrieve.
   *
   * @return the nth SedSurface in this SedListOfSurfaces or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see get(const std::string& sid)
   * @see getNumSurfaces()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSurface* get(unsigned int n) const;


  /**
   * Get a SedSurface from the SedListOfSurfaces based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSurface to
   * retrieve.
   *
   * @return the SedSurface in this SedListOfSurfaces with the given @p sid or
   * @c NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see get(unsigned int n)
   * @see getNumSurfaces()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedSurface* get(const std::string& sid);


  /**
   * Get a SedSurface from the SedListOfSurfaces based on its identifier.
   *
   * @param sid a string representing the identifier of the SedSurface to
   * retrieve.
   *
   * @return the SedSurface in this SedListOfSurfaces with the given @p sid or
   * @c NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see get(unsigned int n)
   * @see getNumSurfaces()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedSurface* get(const std::string& sid) const;


  /**
   * Removes the nth SedSurface from this SedListOfSurfaces and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedSurface to
   * remove.
   *
   * @return a pointer to the nth SedSurface in this SedListOfSurfaces.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSurfaces()
   * @see remove(const std::string& sid)
   */
  virtual SedSurface* remove(unsigned int n);


  /**
   * Removes the SedSurface from this SedListOfSurfaces based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedSurface to
   * remove.
   *
   * @return the SedSurface in this SedListOfSurfaces based on the identifier
   * or NULL if no such SedSurface exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSurfaces()
   * @see remove(unsigned int n)
   */
  virtual SedSurface* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedSurface to this SedListOfSurfaces.
   *
   * @param ss the SedSurface object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createSurface()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSurfaces()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addSurface(const SedSurface* ss);


  /**
   * Get the number of SedSurface objects in this SedListOfSurfaces.
   *
   * @return the number of SedSurface objects in this SedListOfSurfaces.
   *
   * @see addSurface(const SedSurface* object)
   * @see createSurface()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumSurfaces() const;


  /**
   * Creates a new SedSurface object, adds it to this SedListOfSurfaces object
   * and returns the SedSurface object created.
   *
   * @return a new SedSurface object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addSurface(const SedSurface* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumSurfaces()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedSurface* createSurface();


  /**
   * Get a SedSurface from the SedListOfSurfaces based on the XDataReference to
   * which it refers.
   *
   * @param sid a string representing the "xDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedListOfSurfaces based on the given
   * xDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSurface* getByXDataReference(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedListOfSurfaces based on the XDataReference to
   * which it refers.
   *
   * @param sid a string representing the "xDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedListOfSurfaces based on the given
   * xDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSurface* getByXDataReference(const std::string& sid);


  /**
   * Get a SedSurface from the SedListOfSurfaces based on the YDataReference to
   * which it refers.
   *
   * @param sid a string representing the "yDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedListOfSurfaces based on the given
   * yDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSurface* getByYDataReference(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedListOfSurfaces based on the YDataReference to
   * which it refers.
   *
   * @param sid a string representing the "yDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedListOfSurfaces based on the given
   * yDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSurface* getByYDataReference(const std::string& sid);


  /**
   * Get a SedSurface from the SedListOfSurfaces based on the ZDataReference to
   * which it refers.
   *
   * @param sid a string representing the "zDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedListOfSurfaces based on the given
   * zDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSurface* getByZDataReference(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedListOfSurfaces based on the ZDataReference to
   * which it refers.
   *
   * @param sid a string representing the "zDataReference" attribute of the
   * SedSurface object to retrieve.
   *
   * @return the first SedSurface in this SedListOfSurfaces based on the given
   * zDataReference attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSurface* getByZDataReference(const std::string& sid);


  /**
   * Get a SedSurface from the SedListOfSurfaces based on the Style to which it
   * refers.
   *
   * @param sid a string representing the "style" attribute of the SedSurface
   * object to retrieve.
   *
   * @return the first SedSurface in this SedListOfSurfaces based on the given
   * style attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedSurface* getByStyle(const std::string& sid) const;


  /**
   * Get a SedSurface from the SedListOfSurfaces based on the Style to which it
   * refers.
   *
   * @param sid a string representing the "style" attribute of the SedSurface
   * object to retrieve.
   *
   * @return the first SedSurface in this SedListOfSurfaces based on the given
   * style attribute or NULL if no such SedSurface exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedSurface* getByStyle(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfSurfaces object.
   *
   * For SedListOfSurfaces, the XML element name is always @c "listOfSurfaces".
   *
   * @return the name of this element, i.e. @c "listOfSurfaces".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfSurfaces object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_LIST_OF, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSEDML type code for the SED-ML objects contained in this
   * SedListOfSurfaces object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfSurfaces:
   * @sedmlconstant{SEDML_OUTPUT_SURFACE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new SedSurface in this SedListOfSurfaces
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedSurface_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSurface_t to
 * retrieve.
 *
 * @return the nth SedSurface_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSurfaces_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedListOfSurfaces_getSurface(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedSurface_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSurface_t to
 * retrieve.
 *
 * @return the SedSurface_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedSurface_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfSurfaces_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedListOfSurfaces_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedSurface_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedSurface_t to
 * remove.
 *
 * @return a pointer to the nth SedSurface_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSurfaces_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedListOfSurfaces_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedSurface_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedSurface_t to
 * remove.
 *
 * @return the SedSurface_t in this SedListOf_t based on the identifier or NULL
 * if no such SedSurface_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfSurfaces_t
 */
LIBSEDML_EXTERN
SedSurface_t*
SedListOfSurfaces_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfSurfaces_H__ */


