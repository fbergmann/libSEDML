/**
 * @file SedListOfOutputs.h
 * @brief Definition of the SedListOfOutputs class.
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
 * @class SedListOfOutputs
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfOutputs class.
 */


#ifndef SedListOfOutputs_H__
#define SedListOfOutputs_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedOutput.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedReport;
class SedPlot2D;
class SedPlot3D;
class SedFigure;
class SedParameterEstimationResultPlot;

class LIBSEDML_EXTERN SedListOfOutputs : public SedListOf
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedListOfOutputs using the given SED-ML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfOutputs.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfOutputs.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfOutputs(unsigned int level = SEDML_DEFAULT_LEVEL,
                   unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfOutputs using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfOutputs(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfOutputs.
   *
   * @param orig the SedListOfOutputs instance to copy.
   */
  SedListOfOutputs(const SedListOfOutputs& orig);


  /**
   * Assignment operator for SedListOfOutputs.
   *
   * @param rhs the SedListOfOutputs object whose values are to be used as the
   * basis of the assignment.
   */
  SedListOfOutputs& operator=(const SedListOfOutputs& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfOutputs object.
   *
   * @return a (deep) copy of this SedListOfOutputs object.
   */
  virtual SedListOfOutputs* clone() const;


  /**
   * Destructor for SedListOfOutputs.
   */
  virtual ~SedListOfOutputs();


  /**
   * Get a SedOutput from the SedListOfOutputs.
   *
   * @param n an unsigned int representing the index of the SedOutput to
   * retrieve.
   *
   * @return the nth SedOutput in this SedListOfOutputs or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see get(const std::string& sid)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedOutput* get(unsigned int n);


  /**
   * Get a SedOutput from the SedListOfOutputs.
   *
   * @param n an unsigned int representing the index of the SedOutput to
   * retrieve.
   *
   * @return the nth SedOutput in this SedListOfOutputs or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see get(const std::string& sid)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedOutput* get(unsigned int n) const;


  /**
   * Get a SedOutput from the SedListOfOutputs based on its identifier.
   *
   * @param sid a string representing the identifier of the SedOutput to
   * retrieve.
   *
   * @return the SedOutput in this SedListOfOutputs with the given @p sid or
   * @c NULL if no such SedOutput exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedOutput* get(const std::string& sid);


  /**
   * Get a SedOutput from the SedListOfOutputs based on its identifier.
   *
   * @param sid a string representing the identifier of the SedOutput to
   * retrieve.
   *
   * @return the SedOutput in this SedListOfOutputs with the given @p sid or
   * @c NULL if no such SedOutput exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedOutput* get(const std::string& sid) const;


  /**
   * Removes the nth SedOutput from this SedListOfOutputs and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SedOutput to
   * remove.
   *
   * @return a pointer to the nth SedOutput in this SedListOfOutputs.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   */
  virtual SedOutput* remove(unsigned int n);


  /**
   * Removes the SedOutput from this SedListOfOutputs based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedOutput to
   * remove.
   *
   * @return the SedOutput in this SedListOfOutputs based on the identifier or
   * NULL if no such SedOutput exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(unsigned int n)
   */
  virtual SedOutput* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedOutput to this SedListOfOutputs.
   *
   * @param so the SedOutput object to add.
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
   * @see createOutput()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addOutput(const SedOutput* so);


  /**
   * Get the number of SedOutput objects in this SedListOfOutputs.
   *
   * @return the number of SedOutput objects in this SedListOfOutputs.
   *
   * @see addOutput(const SedOutput* object)
   * @see createOutput()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumOutputs() const;


  /**
   * Creates a new SedReport object, adds it to this SedListOfOutputs object
   * and returns the SedReport object created.
   *
   * @return a new SedReport object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedReport* createReport();


  /**
   * Creates a new SedPlot2D object, adds it to this SedListOfOutputs object
   * and returns the SedPlot2D object created.
   *
   * @return a new SedPlot2D object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedPlot2D* createPlot2D();


  /**
   * Creates a new SedPlot3D object, adds it to this SedListOfOutputs object
   * and returns the SedPlot3D object created.
   *
   * @return a new SedPlot3D object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedPlot3D* createPlot3D();


  /**
   * Creates a new SedFigure object, adds it to this SedListOfOutputs object
   * and returns the SedFigure object created.
   *
   * @return a new SedFigure object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedFigure* createFigure();


  /**
   * Creates a new SedParameterEstimationResultPlot object, adds it to this
   * SedListOfOutputs object and returns the SedParameterEstimationResultPlot
   * object created.
   *
   * @return a new SedParameterEstimationResultPlot object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addOutput(const SedOutput* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumOutputs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedParameterEstimationResultPlot* createParameterEstimationResultPlot();


  /**
   * Returns the XML element name of this SedListOfOutputs object.
   *
   * For SedListOfOutputs, the XML element name is always @c "listOfOutputs".
   *
   * @return the name of this element, i.e. @c "listOfOutputs".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedListOfOutputs object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedListOfOutputs object.
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
   * SedListOfOutputs object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfOutputs:
   * @sedmlconstant{SEDML_OUTPUT, SedTypeCode_t}.
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
   * Creates a new SedOutput in this SedListOfOutputs
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
 * Get a SedOutput_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedOutput_t to
 * retrieve.
 *
 * @return the nth SedOutput_t in this SedListOf_t or @c NULL if no such object
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfOutputs_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedListOfOutputs_getOutput(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedOutput_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedOutput_t to
 * retrieve.
 *
 * @return the SedOutput_t in this SedListOf_t with the given @p sid or @c NULL
 * if no such SedOutput_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfOutputs_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedListOfOutputs_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedOutput_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedOutput_t to
 * remove.
 *
 * @return a pointer to the nth SedOutput_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfOutputs_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedListOfOutputs_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedOutput_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedOutput_t to
 * remove.
 *
 * @return the SedOutput_t in this SedListOf_t based on the identifier or NULL
 * if no such SedOutput_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfOutputs_t
 */
LIBSEDML_EXTERN
SedOutput_t*
SedListOfOutputs_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfOutputs_H__ */


