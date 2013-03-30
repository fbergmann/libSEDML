/**
 * @file    SedMLNamespaces.h
 * @brief   SedMLNamespaces class to store level/version and namespace 
 * @author  Sarah Keating
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSedML.  Please visit http://sbml.org for more
 * information about SedML, and the latest version of libSedML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedMLNamespaces
 * @ingroup Core
 * @brief Class to store SedML level, version and namespace information.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * There are differences in the definitions of components between different
 * SedML Levels, as well as Versions within Levels.  For example, the
 * "sboTerm" attribute was not introduced until Level&nbsp;2
 * Version&nbsp;2, and then only on certain component classes; the SedML
 * Level&nbsp;2 Version&nbsp;3 specification moved the "sboTerm" attribute
 * to the SBase class, thereby allowing nearly all components to have SBO
 * annotations.  As a result of differences such as those, libSedML needs to
 * track the SedML Level and Version of every object created.
 * 
 * The purpose of the SedMLNamespaces object class is to make it easier to
 * communicate SedML Level and Version data between libSedML constructors and
 * other methods.  The SedMLNamespaces object class tracks 3-tuples
 * (triples) consisting of SedML Level, Version, and the corresponding SedML
 * XML namespace.
 *
 * The plural name (SedMLNamespaces) is not a mistake, because in SedML
 * Level&nbsp;3, objects may have extensions added by Level&nbsp;3 packages
 * used by a given model and therefore may have multiple namespaces
 * associated with them; however, until the introduction of SedML
 * Level&nbsp;3, the SedMLNamespaces object only records one SedML
 * Level/Version/namespace combination at a time.  Most constructors for
 * SedML objects in libSedML take a SedMLNamespaces object as an argument,
 * thereby allowing the constructor to produce the proper combination of
 * attributes and other internal data structures for the given SedML Level
 * and Version.
 */

#ifndef SedMLNamespaces_h
#define SedMLNamespaces_h

#include <sbml/xml/XMLNamespaces.h>
#include <sedml/common/common.h>
#include <sedml/common/sedmlfwd.h>

#ifdef __cplusplus
namespace LIBSEDML_CPP_NAMESPACE {
  const unsigned int SEDML_DEFAULT_LEVEL   = 1;
  const unsigned int SEDML_DEFAULT_VERSION = 1;
  const char* const SEDML_XMLNS_L1   = "http://sed-ml.org/";  
}
#else
static const unsigned int SEDML_DEFAULT_LEVEL   = 1;
static const unsigned int SEDML_DEFAULT_VERSION = 1;
static const char* const SEDML_XMLNS_L1   = "http://sed-ml.org/";
#endif

#ifdef __cplusplus

#include <string>
#include <stdexcept>

LIBSEDML_CPP_NAMESPACE_BEGIN

class LIBSEDML_EXTERN SedMLNamespaces
{
public:

  /**
   * Creates a new SedMLNamespaces object corresponding to the given SedML
   * @p level and @p version.
   *
   * SedMLNamespaces objects are used in libSedML to communicate SedML Level
   * and Version data between constructors and other methods.  The
   * SedMLNamespaces object class tracks 3-tuples (triples) consisting of
   * SedML Level, Version, and the corresponding SedML XML namespace.  Most
   * constructors for SedML objects in libSedML take a SedMLNamespaces object
   * as an argument, thereby allowing the constructor to produce the proper
   * combination of attributes and other internal data structures for the
   * given SedML Level and Version.
   *
   * The plural name (SedMLNamespaces) is not a mistake, because in SedML
   * Level&nbsp;3, objects may have extensions added by Level&nbsp;3
   * packages used by a given model and therefore may have multiple
   * namespaces associated with them; however, until the introduction of
   * SedML Level&nbsp;3, the SedMLNamespaces object only records one SedML
   * Level/Version/namespace combination at a time.  Most constructors for
   * SedML objects in libSedML take a SedMLNamespaces object as an argument,
   * thereby allowing the constructor to produce the proper combination of
   * attributes and other internal data structures for the given SedML Level
   * and Version.
   *
   * @param level the SedML level
   * @param version the SedML version
   * 
   * @if notcpp @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  SedMLNamespaces(unsigned int level = SEDML_DEFAULT_LEVEL, 
                 unsigned int version = SEDML_DEFAULT_VERSION);

  /**
   * Destroys this SedMLNamespaces object.
   */
  virtual ~SedMLNamespaces();

  
  /**
   * Copy constructor; creates a copy of a SedMLNamespaces.
   * 
   * @param orig the SedMLNamespaces instance to copy.
   *
   * @throws @if python ValueError @else SedMLConstructorException @endif@~
   * Thrown if the argument @p orig is @c NULL.
   */
  SedMLNamespaces(const SedMLNamespaces& orig);


  /**
   * Assignment operator for SedMLNamespaces.
   *
   * @throws @if python ValueError @else SedMLConstructorException @endif@~
   * Thrown if the argument @p rhs is @c NULL.
   */
  SedMLNamespaces& operator=(const SedMLNamespaces& rhs);


  /**
   * Creates and returns a deep copy of this SedMLNamespaces.
   * 
   * @return a (deep) copy of this SedMLNamespaces.
   */
  virtual SedMLNamespaces* clone () const;


  /**
   * Returns a string representing the SedML XML namespace for the 
   * given @p level and @p version of SedML.
   *
   * @param level the SedML level
   * @param version the SedML version
   *
   * @return a string representing the SedML namespace that reflects the
   * SedML Level and Version specified.
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSedML will contain two variants.  One
   * will be a static method on the class (i.e., SedMLNamespaces), and the
   * other will be a standalone top-level function with the name
   * SedMLNamespaces_getSedMLNamespaceURI(). They are functionally
   * identical. @endif@~
   */
  static std::string getSedMLNamespaceURI(unsigned int level,
                                         unsigned int version);
  
  /**
   * Returns a list of all supported SedMLNamespaces in this version of 
   * libsbml. 
   * 
   * @return a list with supported SedML namespaces. 
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSedML will contain two variants.  One
   * will be a static method on the class (i.e., SedMLNamespaces), and the
   * other will be a standalone top-level function with the name
   * SedMLNamespaces_getSupportedNamespaces(). They are functionally
   * identical. @endif@~
   */
  static const List* getSupportedNamespaces();


  /**
   * Returns a string representing the SedML XML namespace of this
   * object.
   *
   * @return a string representing the SedML namespace that reflects the
   * SedML Level and Version of this object.
   */
  virtual std::string getURI() const;

  
  /**
   * Get the SedML Level of this SedMLNamespaces object.
   *
   * @return the SedML Level of this SedMLNamespaces object.
   */
  unsigned int getLevel();


  /**
   * Get the SedML Level of this SedMLNamespaces object.
   *
   * @return the SedML Level of this SedMLNamespaces object.
   */
  unsigned int getLevel() const;


  /**
   * Get the SedML Version of this SedMLNamespaces object.
   *
   * @return the SedML Version of this SedMLNamespaces object.
   */
  unsigned int getVersion();


  /**
   * Get the SedML Version of this SedMLNamespaces object.
   *
   * @return the SedML Version of this SedMLNamespaces object.
   */
  unsigned int getVersion() const;


  /**
   * Get the XML namespaces list for this SedMLNamespaces object.
   * 
   * The plural is not a mistake, because in SedML Level&nbsp;3, objects may
   * have extensions added by Level&nbsp;3 packages used by a given model,
   * and therefore there may be multiple XML namespaces involved too.
   * However, until the introduction of SedML Level&nbsp;3, the
   * SedMLNamespaces object only records one SedML Level/Version/namespace
   * combination at a time, and so this method will also only return
   * a list of one item.
   *
   * @return the XML namespaces of this SedMLNamespaces object.
   */
  XMLNamespaces * getNamespaces();


  /**
   * Get the XML namespaces list for this SedMLNamespaces object.
   * 
   * The plural is not a mistake, because in SedML Level&nbsp;3, objects may
   * have extensions added by Level&nbsp;3 packages used by a given model,
   * and therefore there may be multiple XML namespaces involved too.
   * However, until the introduction of SedML Level&nbsp;3, the
   * SedMLNamespaces object only records one SedML Level/Version/namespace
   * combination at a time, and so this method will also only return
   * a list of one item.
   *
   * @return the XML namespaces of this SedMLNamespaces object.
   */
  const XMLNamespaces * getNamespaces() const;


  /**
   * Add the given XML namespaces list to the set of namespaces within this
   * SedMLNamespaces object.
   *
   * The following code gives an example of how one could add the XHTML
   * namespace to the list of namespaces recorded by the top-level
   * <code>&lt;sbml&gt;</code> element of a model.  It gives the new
   * namespace a prefix of <code>html</code>.  @if clike
   * @verbatim
SedMLDocument *sd;
try 
{
    sd = new SedMLDocument(3, 1);
} 
catch (SedMLConstructorException e)
{
    // Here, have code to handle a truly exceptional situation. Candidate
    // causes include invalid combinations of SedML Level and Version
    // (impossible if hardwired as given here), running out of memory, and
    // unknown system exceptions.
}

SedMLNamespaces sn = sd->getNamespaces();
if (sn != NULL)
{
    sn->add("http://www.w3.org/1999/xhtml", "html");
}
else
{
    // Handle another truly exceptional situation.
}
@endverbatim
   * @endif@if java
@verbatim
SedMLDocument sd;
try 
{
    sd = new SedMLDocument(3, 1);
} 
catch (SedMLConstructorException e)
{
    // Here, have code to handle a truly exceptional situation. Candidate
    // causes include invalid combinations of SedML Level and Version
    // (impossible if hardwired as given here), running out of memory, and
    // unknown system exceptions.
}

SedMLNamespaces sn = sd.getNamespaces();
if (sn != null)
{
    sn.add("http://www.w3.org/1999/xhtml", "html");
}
else
{
    // Handle another truly exceptional situation.
 }
@endverbatim
   * @endif@if python
@verbatim
sbmlDoc = None
try:
  sbmlDoc = SedMLDocument(3, 1)
except ValueError:
  # Do something to handle exceptional situation.  Candidate
  # causes include invalid combinations of SedML Level and Version
  # (impossible if hardwired as given here), running out of memory, and
  # unknown system exceptions.

namespaces = sbmlDoc.getNamespaces()
if namespaces == None:
  # Do something to handle case of no namespaces.

status = namespaces.add("http://www.w3.org/1999/xhtml", "html")
if status != LIBSEDML_OPERATION_SUCCESS:
  # Do something to handle failure.
@endverbatim
   * @endif@if csharp
@verbatim
SedMLDocument sd = null;
try
{
    sd = new SedMLDocument(3, 1);
}
catch (SedMLConstructorException e)
{
    // Here, have code to handle a truly exceptional situation.
    // Candidate causes include invalid combinations of SedML
    // Level and Version (impossible if hardwired as given here),
    // running out of memory, and unknown system exceptions.
}

XMLNamespaces sn = sd.getNamespaces();
if (sn != null)
{
    sn.add("http://www.w3.org/1999/xhtml", "html");            
}
else
{
    // Handle another truly exceptional situation.
}
@endverbatim
   * @endif@~
   *
   * @param xmlns the XML namespaces to be added.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif@~ The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   */
  int addNamespaces(const XMLNamespaces * xmlns);


  /**
   * Add an XML namespace (a pair of URI and prefix) to the set of namespaces
   * within this SedMLNamespaces object.
   * 
   * @param uri    the XML namespace to be added.
   * @param prefix the prefix of the namespace to be added.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif@~ The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   */
  int addNamespace(const std::string& uri, const std::string &prefix);


  /**
   * Removes an XML namespace from the set of namespaces within this 
   * SedMLNamespaces object.
   * 
   * @param uri    the XML namespace to be added.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif@~ The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INDEX_EXCEEDS_SIZE LIBSEDML_INDEX_EXCEEDS_SIZE @endlink
   */
  int removeNamespace(const std::string& uri);


  /**
   * Predicate returning @c true if the given
   * URL is one of SedML XML namespaces.
   *
   * @param uri the URI of namespace
   *
   * @return @c true if the "uri" is one of SedML namespaces, @c false otherwise.
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSedML will contain two variants.  One
   * will be a static method on the class (i.e., SedMLNamespaces), and the
   * other will be a standalone top-level function with the name
   * SedMLNamespaces_isSedMLNamespace(). They are functionally
   * identical. @endif@~
   */
  static bool isSedMLNamespace(const std::string& uri);


  /**
   * Predicate returning @c true if the given
   * set of namespaces represent a valid set
   *
   * @return @c true if the set of namespaces is valid, @c false otherwise.
   */
  bool isValidCombination();


  /** @cond doxygen-libsbml-internal */
  void setLevel(unsigned int level);


  void setVersion(unsigned int version);


  void setNamespaces(XMLNamespaces * xmlns);
  /** @endcond */

	
protected:  
  /** @cond doxygen-libsbml-internal */

  void initSedMLNamespace();

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

/* ----------------------------------------------------------------------------
 * See the .cpp file for the documentation of the following functions.
 * --------------------------------------------------------------------------*/

LIBSEDML_EXTERN
SedMLNamespaces_t *
SedMLNamespaces_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
unsigned int
SedMLNamespaces_getLevel(SedMLNamespaces_t *sbmlns);


LIBSEDML_EXTERN
unsigned int
SedMLNamespaces_getVersion(SedMLNamespaces_t *sbmlns);


LIBSEDML_EXTERN
XMLNamespaces_t *
SedMLNamespaces_getNamespaces(SedMLNamespaces_t *sbmlns);


LIBSEDML_EXTERN
char *
SedMLNamespaces_getSedMLNamespaceURI(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
int
SedMLNamespaces_addNamespaces(SedMLNamespaces_t *sbmlns,
                             const XMLNamespaces_t * xmlns);


LIBSEDML_EXTERN
SedMLNamespaces_t **
SedMLNamespaces_getSupportedNamespaces(int *length);

END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* SedMLNamespaces_h */
