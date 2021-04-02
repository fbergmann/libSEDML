/**
 * @file SedListOfCurves.h
 * @brief Definition of the SedListOfCurves class.
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
 * @class SedListOfCurves
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfCurves class.
 */


#ifndef SedListOfCurves_H__
#define SedListOfCurves_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedAbstractCurve.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedCurve;
class SedShadedArea;

class LIBSEDML_EXTERN SedListOfCurves : public SedListOf
{

public:

  /**
   * Creates a new SedListOfCurves using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfCurves.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfCurves.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfCurves(unsigned int level = SEDML_DEFAULT_LEVEL,
                  unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfCurves using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfCurves(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfCurves.
   *
   * @param orig the SedListOfCurves instance to copy.
   */
  SedListOfCurves(const SedListOfCurves& orig);


  /**
   * Assignment operator for SedListOfCurves.
   *
   * @param rhs the SedListOfCurves object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfCurves& operator=(const SedListOfCurves& rhs);


  /**
   * Sort the SedListOfCurves according to the 'order' attribute.
   *
   */
  void sort();


  /**
   * Creates and returns a deep copy of this SedListOfCurves object.
   *
   * @return a (deep) copy of this SedListOfCurves object.
   */
  virtual SedListOfCurves* clone() const;


  /**
   * Destructor for SedListOfCurves.
   */
  virtual ~SedListOfCurves();


  /**
   * Get a SedAbstractCurve from the SedListOfCurves.
   *
   * @param n an unsigned int representing the index of the SedAbstractCurve to
   * retrieve.
   *
   * @return the nth SedAbstractCurve in this SedListOfCurves or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see get(const std::string& sid)
   * @see getNumCurves()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAbstractCurve* get(unsigned int n);


  /**
   * Get a SedAbstractCurve from the SedListOfCurves.
   *
   * @param n an unsigned int representing the index of the SedAbstractCurve to
   * retrieve.
   *
   * @return the nth SedAbstractCurve in this SedListOfCurves or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see get(const std::string& sid)
   * @see getNumCurves()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAbstractCurve* get(unsigned int n) const;


  /**
   * Get a SedAbstractCurve from the SedListOfCurves based on its identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractCurve to
   * retrieve.
   *
   * @return the SedAbstractCurve in this SedListOfCurves with the given @p sid
   * or @c NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see get(unsigned int n)
   * @see getNumCurves()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAbstractCurve* get(const std::string& sid);


  /**
   * Get a SedAbstractCurve from the SedListOfCurves based on its identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractCurve to
   * retrieve.
   *
   * @return the SedAbstractCurve in this SedListOfCurves with the given @p sid
   * or @c NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see get(unsigned int n)
   * @see getNumCurves()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAbstractCurve* get(const std::string& sid) const;


  /**
   * Removes the nth SedAbstractCurve from this SedListOfCurves and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedAbstractCurve to
   * remove.
   *
   * @return a pointer to the nth SedAbstractCurve in this SedListOfCurves.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumCurves()
   * @see remove(const std::string& sid)
   */
  virtual SedAbstractCurve* remove(unsigned int n);


  /**
   * Removes the SedAbstractCurve from this SedListOfCurves based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedAbstractCurve to
   * remove.
   *
   * @return the SedAbstractCurve in this SedListOfCurves based on the
   * identifier or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumCurves()
   * @see remove(unsigned int n)
   */
  virtual SedAbstractCurve* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedAbstractCurve to this SedListOfCurves.
   *
   * @param sac the SedAbstractCurve object to add.
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
   * @see createCurve()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumCurves()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addCurve(const SedAbstractCurve* sac);


  /**
   * Get the number of SedAbstractCurve objects in this SedListOfCurves.
   *
   * @return the number of SedAbstractCurve objects in this SedListOfCurves.
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see createCurve()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumCurves() const;


  /**
   * Creates a new SedCurve object, adds it to this SedListOfCurves object and
   * returns the SedCurve object created.
   *
   * @return a new SedCurve object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumCurves()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedCurve* createCurve();


  /**
   * Creates a new SedShadedArea object, adds it to this SedListOfCurves object
   * and returns the SedShadedArea object created.
   *
   * @return a new SedShadedArea object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCurve(const SedAbstractCurve* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumCurves()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedShadedArea* createShadedArea();


  /**
   * Get a SedAbstractCurve from the SedListOfCurves based on the Style to
   * which it refers.
   *
   * @param sid a string representing the "style" attribute of the
   * SedAbstractCurve object to retrieve.
   *
   * @return the first SedAbstractCurve in this SedListOfCurves based on the
   * given style attribute or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAbstractCurve* getByStyle(const std::string& sid) const;


  /**
   * Get a SedAbstractCurve from the SedListOfCurves based on the Style to
   * which it refers.
   *
   * @param sid a string representing the "style" attribute of the
   * SedAbstractCurve object to retrieve.
   *
   * @return the first SedAbstractCurve in this SedListOfCurves based on the
   * given style attribute or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAbstractCurve* getByStyle(const std::string& sid);


  /**
   * Get a SedAbstractCurve from the SedListOfCurves based on the
   * XDataReference to which it refers.
   *
   * @param sid a string representing the "xDataReference" attribute of the
   * SedAbstractCurve object to retrieve.
   *
   * @return the first SedAbstractCurve in this SedListOfCurves based on the
   * given xDataReference attribute or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedAbstractCurve* getByXDataReference(const std::string& sid) const;


  /**
   * Get a SedAbstractCurve from the SedListOfCurves based on the
   * XDataReference to which it refers.
   *
   * @param sid a string representing the "xDataReference" attribute of the
   * SedAbstractCurve object to retrieve.
   *
   * @return the first SedAbstractCurve in this SedListOfCurves based on the
   * given xDataReference attribute or NULL if no such SedAbstractCurve exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedAbstractCurve* getByXDataReference(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfCurves object.
   *
   * For SedListOfCurves, the XML element name is always
   * @c "listOfCurves".
   *
   * @return the name of this element, i.e. @c "listOfCurves".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfCurves object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_LIST_OF, SEDMLTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSEDML type code for the SED-ML objects contained in this
   * SedListOfCurves object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfCurves:
   * @sedmlconstant{SEDML_ABSTRACTCURVE, SedmlmlTypeCode_t}.
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
   * Creates a new SedAbstractCurve in this SedListOfCurves
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * checks concrete types
   */
  virtual bool isValidTypeForList(SedBase* item);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedAbstractCurve_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractCurve_t to
 * retrieve.
 *
 * @return the nth SedAbstractCurve_t in this SedListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfCurves_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedListOfCurves_getCurve(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedAbstractCurve_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractCurve_t to
 * retrieve.
 *
 * @return the SedAbstractCurve_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedAbstractCurve_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfCurves_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedListOfCurves_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedAbstractCurve_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractCurve_t to
 * remove.
 *
 * @return a pointer to the nth SedAbstractCurve_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfCurves_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedListOfCurves_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedAbstractCurve_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractCurve_t to
 * remove.
 *
 * @return the SedAbstractCurve_t in this SedListOf_t based on the identifier
 * or NULL if no such SedAbstractCurve_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedListOfCurves_t
 */
LIBSEDML_EXTERN
SedAbstractCurve_t*
SedListOfCurves_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfCurves_H__ */


