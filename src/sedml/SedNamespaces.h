/**
 * @file SedNamespaces.h
 * @brief Definition of the SedNamespaces class.
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
 * @class SedNamespaces
 * @sbmlbrief{} TODO:Definition of the SedNamespaces class.
 */


#ifndef SedNamespaces_h
#define SedNamespaces_h

#include <sbml/xml/XMLNamespaces.h>
#include <sbml/util/List.h>

#include <sedml/common/common.h>
#include <sedml/common/sedmlfwd.h>

#ifdef __cplusplus
namespace LIBSEDML_CPP_NAMESPACE 
{
  const unsigned int SEDML_DEFAULT_LEVEL   = 1;
  const unsigned int SEDML_DEFAULT_VERSION = 5;
  const char* const SEDML_XMLNS_L1V1   = "http://sed-ml.org/";
  const char* const SEDML_XMLNS_L1V2   = "http://sed-ml.org/sed-ml/level1/version2";
  const char* const SEDML_XMLNS_L1V3   = "http://sed-ml.org/sed-ml/level1/version3";
  const char* const SEDML_XMLNS_L1V4   = "http://sed-ml.org/sed-ml/level1/version4";
  const char* const SEDML_XMLNS_L1V5   = "http://sed-ml.org/sed-ml/level1/version5";
}
#else
static const unsigned int SEDML_DEFAULT_LEVEL   = 1;
static const unsigned int SEDML_DEFAULT_VERSION = 3;
static const char* const SEDML_XMLNS_L1V1   = "http://sed-ml.org/";
static const char* const SEDML_XMLNS_L1V2   = "http://sed-ml.org/sed-ml/level1/version2";
static const char* const SEDML_XMLNS_L1V3   = "http://sed-ml.org/sed-ml/level1/version3";
static const char* const SEDML_XMLNS_L1V4   = "http://sed-ml.org/sed-ml/level1/version4";
static const char* const SEDML_XMLNS_L1V5   = "http://sed-ml.org/sed-ml/level1/version5";
#endif

#ifdef __cplusplus

#include <string>
#include <stdexcept>

LIBSEDML_CPP_NAMESPACE_BEGIN

class LIBSEDML_EXTERN SedNamespaces
{
public:

  /**
   * Creates a new SedNamespaces object corresponding to the given SED-ML
   * @p level and @p version.
   *
   * @param level the SED-ML level
   * @param version the SED-ML version
   * 
   */
  SedNamespaces(unsigned int level = SEDML_DEFAULT_LEVEL, 
                 unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Destroys this SedNamespaces object.
   */
  virtual ~SedNamespaces();

  
  /**
   * Copy constructor; creates a copy of a SedNamespaces.
   * 
   * @param orig the SedNamespaces instance to copy.
   */
  SedNamespaces(const SedNamespaces& orig);


  /**
   * Assignment operator for SedNamespaces.
   */
  SedNamespaces& operator=(const SedNamespaces& rhs);


  /**
   * Creates and returns a deep copy of this SedNamespaces object.
   *
   * @return the (deep) copy of this SedNamespaces object.
   */
  virtual SedNamespaces* clone () const;


  /**
   * Returns a string representing the SED-ML XML namespace for the 
   * given @p level and @p version of SED-ML.
   *
   * @param level the SED-ML level
   * @param version the SED-ML version
   *
   * @return a string representing the SED-ML namespace that reflects the
   * SED-ML Level and Version specified.
   */
  static std::string getSedNamespaceURI(unsigned int level,
                                         unsigned int version);

  
  /**
   * Returns a list of all supported SedNamespaces in this version of 
   * libsedml. 
   * 
   * @return a list with supported SED-ML namespaces. 
   */
  static const List* getSupportedNamespaces();


  /**
   * Frees the list of supported namespaces as generated by
   * getSupportedNamespaces().
   *
   * @param supportedNS the list to be freed.
   *
   * @copydetails doc_note_static_methods
   */
  static void freeSedNamespaces(List * supportedNS);


  /**
   * Returns a string representing the SED-ML XML namespace of this
   * object.
   *
   * @return a string representing the SED-ML namespace that reflects the
   * SED-ML Level and Version of this object.
   */
  virtual std::string getURI() const;


  /**
   * Get the SED-ML Level of this SedNamespaces object.
   *
   * @return the SED-ML Level of this SedNamespaces object.
   */
  unsigned int getLevel();


  /**
   * Get the SED-ML Level of this SedNamespaces object.
   *
   * @return the SED-ML Level of this SedNamespaces object.
   */
  unsigned int getLevel() const;


  /**
   * Get the SED-ML Version of this SedNamespaces object.
   *
   * @return the SED-ML Version of this SedNamespaces object.
   */
  unsigned int getVersion();


  /**
   * Get the SED-ML Version of this SedNamespaces object.
   *
   * @return the SED-ML Version of this SedNamespaces object.
   */
  unsigned int getVersion() const;


  /**
   * Get the XML namespaces list for this SedNamespaces object.
   *
   * @return the XML namespaces of this SedNamespaces object.
   */
  XMLNamespaces * getNamespaces();


  /**
   * Get the XML namespaces list for this SedNamespaces object.
   * 
   * @return the XML namespaces of this SedNamespaces object.
   */
  const XMLNamespaces * getNamespaces() const;


  /**
   * Add the given XML namespaces list to the set of namespaces within this
   * SedNamespaces object.
   *
   * @param xmlns the XML namespaces to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   */
  int addNamespaces(const XMLNamespaces * xmlns);


  /**
   * Add an XML namespace (a pair of URI and prefix) to the set of namespaces
   * within this SedNamespaces object.
   * 
   * @param uri    the XML namespace to be added.
   * @param prefix the prefix of the namespace to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   */
  int addNamespace(const std::string& uri, const std::string &prefix);


  /**
   * Removes an XML namespace from the set of namespaces within this 
   * SedNamespaces object.
   * 
   * @param uri    the XML namespace to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INDEX_EXCEEDS_SIZE, OperationReturnValues_t}
   */
  int removeNamespace(const std::string& uri);


  /**
   * Predicate returning @c true if the given URL is one of SED-ML XML
   * namespaces.
   *
   * @param uri the URI of namespace
   *
   * @return @c true if the "uri" is one of SED-ML namespaces, @c false otherwise.
   */
  static bool isSedNamespace(const std::string& uri);


  /**
   * Predicate returning @c true if the given set of namespaces represent a
   * valid set
   *
   * @return @c true if the set of namespaces is valid, @c false otherwise.
   */
  bool isValidCombination();


  /** @cond doxygenLibsedmlInternal */
  void setLevel(unsigned int level);


  void setVersion(unsigned int version);


  void setNamespaces(XMLNamespaces * xmlns);
  /** @endcond */

protected:  
  /** @cond doxygenLibsedmlInternal */
  void initSedNamespace();

  unsigned int    mLevel;
  unsigned int    mVersion;
  XMLNamespaces * mNamespaces;

  /** @endcond */
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */


#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Creates a new SedNamespaces_t structure corresponding to the given SED-ML
 * @p level and @p version.
 *
 * SedNamespaces_t structures are used in libSEDML to communicate SED-ML Level
 * and Version data between constructors and other methods.  The
 * SedNamespaces_t structure class tracks 3-tuples (triples) consisting of
 * SED-ML Level, Version, and the corresponding SED-ML XML namespace.  Most
 * constructors for SED-ML structures in libSEDML take a SedNamespaces_t structure
 * as an argument, thereby allowing the constructor to produce the proper
 * combination of attributes and other internal data structures for the
 * given SED-ML Level and Version.
 *
 * The plural name "SedNamespaces" is not a mistake, because in SED-ML
 * Level&nbsp;3, structures may have extensions added by Level&nbsp;3
 * packages used by a given model; however, until the introduction of
 * SED-ML Level&nbsp;3, the SedNamespaces_t structure only records one SED-ML
 * Level/Version/namespace combination at a time.
 *
 * @param level the SED-ML level
 * @param version the SED-ML version
 *
 * @return SedNamespaces_t structure created
 *
 * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif@~
 *
 * @memberof SedNamespaces_t
 */
LIBSEDML_EXTERN
SedNamespaces_t *
SedNamespaces_create(unsigned int level, unsigned int version);


/**
 * Destroys this SedNamespaces_t structure.
 *
 * @param ns SedNamespaces_t structure to be freed.
 *
 * @memberof SedNamespaces_t
 */
LIBSEDML_EXTERN
void
SedNamespaces_free (SedNamespaces_t *ns);


/**
 * Get the SED-ML Level of this SedNamespaces_t structure.
 *
 * @param sedmlns the SedNamespaces_t structure to query
 *
 * @return the SED-ML Level of this SedNamespaces_t structure.
 *
 * @memberof SedNamespaces_t
 */
LIBSEDML_EXTERN
unsigned int
SedNamespaces_getLevel(SedNamespaces_t *sedmlns);


/**
 * Get the SED-ML Version of this SedNamespaces_t structure.
 *
 * @param sedmlns the SedNamespaces_t structure to query
 *
 * @return the SED-ML Version of this SedNamespaces_t structure.
 *
 * @memberof SedNamespaces_t
 */
LIBSEDML_EXTERN
unsigned int
SedNamespaces_getVersion(SedNamespaces_t *sedmlns);


/**
 * Get the SED-ML Version of this SedNamespaces_t structure.
 *
 * @param sedmlns the SedNamespaces_t structure to query
 *
 * @return the XMLNamespaces_t structure of this SedNamespaces_t structure.
 *
 * @memberof SedNamespaces_t
 */
LIBSEDML_EXTERN
XMLNamespaces_t *
SedNamespaces_getNamespaces(SedNamespaces_t *sedmlns);


/**
 * Returns a string representing the SED-ML XML namespace for the 
 * given @p level and @p version of SED-ML.
 *
 * @param level the SED-ML level
 * @param version the SED-ML version
 *
 * @return a string representing the SED-ML namespace that reflects the
 * SED-ML Level and Version specified.
 *
 * @memberof SedNamespaces_t
 */
LIBSEDML_EXTERN
char *
SedNamespaces_getSedNamespaceURI(unsigned int level, unsigned int version);


/**
 * Add the XML namespaces list to the set of namespaces
 * within this SedNamespaces_t structure.
 * 
 * @param sedmlns the SedNamespaces_t structure to add to
 * @param xmlns the XML namespaces to be added.
 *
 * @memberof SedNamespaces_t
 */
LIBSEDML_EXTERN
int
SedNamespaces_addNamespaces(SedNamespaces_t *sedmlns,
                             const XMLNamespaces_t * xmlns);


/**
 * Returns an array of SED-ML Namespaces supported by this version of 
 * LibSEDML. 
 *
 * @param length an integer holding the length of the array
 * @return an array of SED-ML namespaces, or @c NULL if length is @c NULL. The array 
 *         has to be freed by the caller.
 *
 * @memberof SedNamespaces_t
 */
LIBSEDML_EXTERN
SedNamespaces_t **
SedNamespaces_getSupportedNamespaces(int *length);

END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* SedNamespaces_h */
