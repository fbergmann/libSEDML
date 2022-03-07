/**
 * @file SedBase.h
 * @brief Definition of the SedBase class.
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
 * @class SedBase
 * @sbmlbrief{} TODO:Definition of the SedBase class.
 */


#ifndef SedBase_h
#define SedBase_h


#include <sedml/common/extern.h>
#include <sedml/common/libsedml-namespace.h>
#include <sbml/common/libsbml-namespace.h>
#include <sedml/common/sedmlfwd.h>
#include <sedml/SedTypeCodes.h>
#include <sedml/SedNamespaces.h>
#include <sedml/SedConstructorException.h>
#include <sedml/SedElementFilter.h>
#include <sbml/util/List.h>
#include <sbml/SyntaxChecker.h>
#include <sbml/ExpectedAttributes.h>
#include <sbml/xml/XMLNode.h>

#ifdef __cplusplus


#include <string>
#include <stdexcept>
#include <algorithm>

#include <sedml/SedErrorLog.h>
#include <sedml/SedVisitor.h>

LIBSBML_CPP_NAMESPACE_BEGIN

class Model;

class List;

class XMLAttributes;
class XMLInputStream;
class XMLNamespaces;
class XMLOutputStream;
class XMLToken;

LIBSBML_CPP_NAMESPACE_END

LIBSEDML_CPP_NAMESPACE_BEGIN

class SedDocument;


class LIBSEDML_EXTERN SedBase
{
public:

  /**
   * Destroys this object.
   */
  virtual ~SedBase ();


  /**
   * Assignment operator for SedBase.
   *
   * @param rhs The object whose values are used as the basis of the
   * assignment.
   */
  SedBase& operator=(const SedBase& rhs);


  /** @cond doxygenLibsedmlInternal */
  /**
   * Accepts the given SedVisitor for this SedBase object.
   *
   * @param v the SedVisitor instance to be used
   *
   * @return the result of calling <code>v.visit()</code>.
   */
  virtual bool accept (SedVisitor& v) const = 0;
  /** @endcond */


  /**
   * Creates and returns a deep copy of this SedBase object.
   *
   * @return the (deep) copy of this SedBase object.
   */
  virtual SedBase* clone () const = 0;


  /**
   * Returns the first child element it can find with a specific "id"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param id string representing the "id" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given identifier.
   */
  virtual SedBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element it can find with a specific "id"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param id string representing the "id" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given identifier.
   */
  virtual const SedBase* getElementBySId(const std::string& metaid) const;


  /**
   * Returns the first child element it can find with a specific "metaid"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param metaid string representing the "metaid" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given meta-identifier.
   */
  virtual SedBase* getElementByMetaId(const std::string& metaid);

  /**
   * Returns the first child element it can find with a specific "metaid"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param metaid string representing the "metaid" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given meta-identifier.
   */
  virtual const SedBase* getElementByMetaId(const std::string& metaid) const;

  /**
   * Returns a List of all child SedBase objects, including those nested to
   * an arbitrary depth.
   *
   * @return a pointer to a List of pointers to all children objects.
   */
  virtual List* getAllElements(SedElementFilter* filter = NULL);


  /**
   * Returns the value of the "metaid" attribute of this object.
   *
   * @copydetails doc_what_is_metaid
   *  
   * @return the meta-identifier of this SED-ML object.
   *
   * @see isSetMetaId()
   * @see setMetaId(const std::string& metaid)
   */
  const std::string& getMetaId () const;


  /**
   * Returns the value of the "metaid" attribute of this object.
   *
   * @copydetails doc_what_is_metaid
   *  
   * @return the meta-identifier of this SED-ML object, as a string.
   *
   * @see isSetMetaId()
   * @see setMetaId(const std::string& metaid)
   */
  std::string& getMetaId ();

  
  /*
   * @return the id of this SED-ML object.
   *
   * @note The fact that the value of attribute "id" is defined on the
   * SedBase parent class object is a convenience provided by libSEDML, and
   * <b>does not strictly follow SED-ML specifications</b>.  This libSEDML
   * implementation of SedBase allows client applications to use more
   * generalized code in some situations (for instance, when manipulating
   * objects that are all known to have identifiers), but beware that not
   * all SED-ML object classes provide an "id" attribute.  LibSEDML will allow
   * the identifier to be set, but it will not read nor write "id"
   * attributes for objects that do not possess them according to the SED-ML
   * specification for the Level and Version in use.
   *
   */
  virtual const std::string& getId() const;


  /**
   * @return the value of the "name" attribute (or an empty string).
   *
   * @note The "name" attribute was added to the SedBase class in
   * Level 1 version 4, and its presence here does not indicate
   * whether the attribute was allowed on any given class in
   * previous levels or versions.  LibSEDML will return an empty
   * string if the attribute was not allowed on the current
   * level/version of the class.
   */
  virtual const std::string& getName() const;


  /**
   * Returns the content of the "notes" subelement of this object as
   * a tree of XMLNode objects.
   *
   * The "notes" element content returned by this method will be in XML
   * form, but libSEDML does not provide an object model specifically for
   * the content of notes.  Callers will need to traverse the XML tree
   * structure using the facilities available on XMLNode and related
   * objects.  For an alternative method of accessing the notes, see
   * getNotesString().
   *
   * @return the content of the "notes" subelement of this SED-ML object as a
   * tree structure composed of XMLNode objects.
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getNotes();


  /**
   * Returns the content of the "notes" subelement of this object as
   * a tree of XMLNode objects.
   *
   * The "notes" element content returned by this method will be in XML
   * form, but libSEDML does not provide an object model specifically for
   * the content of notes.  Callers will need to traverse the XML tree
   * structure using the facilities available on XMLNode and related
   * objects.  For an alternative method of accessing the notes, see
   * getNotesString().
   *
   * @return the content of the "notes" subelement of this SED-ML object as a
   * tree structure composed of XMLNode objects.
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getNotes() const;


  /**
   * Returns the content of the "notes" subelement of this object as a
   * string.
   *
   * For an alternative method of accessing the notes, see getNotes(),
   * which returns the content as an XMLNode tree structure.  Depending on
   * an application's needs, one or the other method may be more
   * convenient.
   *
   * @return the content of the "notes" subelement of this SED-ML object as a
   * string.
   *
   * @see getNotes()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  std::string getNotesString ();


  /**
   * Returns the content of the "notes" subelement of this object as a
   * string.
   *
   * For an alternative method of accessing the notes, see getNotes(),
   * which returns the content as an XMLNode tree structure.  Depending on
   * an application's needs, one or the other method may be more
   * convenient.
   *
   * @return the content of the "notes" subelement of this SED-ML object as a
   * string.
   *
   * @see getNotes()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  std::string getNotesString () const;


  /**
   * Returns the content of the "annotation" subelement of this object as
   * a tree of XMLNode objects.
   *
   * The annotations returned by this method will be in XML form.  LibSEDML
   * provides an object model and related interfaces for certain specific
   * kinds of annotations, namely model history information and RDF
   * content.  See the ModelHistory, CVTerm and RDFAnnotationParser classes
   * for more information about the facilities available.
   *
   * @return the annotation of this SED-ML object as a tree of XMLNode objects.
   *
   * @see getAnnotationString()
   * @see isSetAnnotation()
   * @see setAnnotation(const XMLNode* annotation)
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const std::string& annotation)
   * @see unsetAnnotation()
   */
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getAnnotation ();


  /**
   * Returns the content of the "annotation" subelement of this object as
   * a tree of XMLNode objects.
   *
   * The annotations returned by this method will be in XML form.  LibSEDML
   * provides an object model and related interfaces for certain specific
   * kinds of annotations, namely model history information and RDF
   * content.  See the ModelHistory, CVTerm and RDFAnnotationParser classes
   * for more information about the facilities available.
   *
   * @return the annotation of this SED-ML object as a tree of XMLNode objects.
   *
   * @see getAnnotationString()
   * @see isSetAnnotation()
   * @see setAnnotation(const XMLNode* annotation)
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const std::string& annotation)
   * @see unsetAnnotation()
   */
  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* getAnnotation () const;


  /**
   * Returns the content of the "annotation" subelement of this object as a
   * character string.
   *
   * The annotations returned by this method will be in string form.  See the
   * method getAnnotation() for a version that returns annotations in XML form.
   *
   * @return the annotation of this SED-ML object as a character string.
   *
   * @see getAnnotation()
   * @see isSetAnnotation()
   * @see setAnnotation(const XMLNode* annotation)
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const std::string& annotation)
   * @see unsetAnnotation()
   */
  std::string getAnnotationString ();


  /**
   * Returns the content of the "annotation" subelement of this object as a
   * character string.
   *
   * The annotations returned by this method will be in string form.  See the
   * method getAnnotation() for a version that returns annotations in XML form.
   *
   * @return the annotation of this SED-ML object as a character string.
   *
   * @see getAnnotation()
   * @see isSetAnnotation()
   * @see setAnnotation(const XMLNode* annotation)
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const std::string& annotation)
   * @see unsetAnnotation()
   */
  std::string getAnnotationString () const;


  /**
   * Returns a list of the XML Namespaces declared on the SED-ML document
   * owning this object.
   *
   * The SedNamespaces object encapsulates SED-ML Level/Version/namespaces
   * information.  It is used to communicate the SED-ML Level, Version, and (in
   * Level&nbsp;3) packages used in addition to SED-ML Level&nbsp;3 Core.
   *
   * @return the XML Namespaces associated with this SED-ML object, or @c NULL
   * in certain very usual circumstances where a namespace is not set.
   *
   * @see getLevel()
   * @see getVersion()
   */
  virtual const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getNamespaces() const ;

  /**
   * Returns a list of the XML Namespaces declared on this object.
   *
   * @return the XML Namespaces associated with this SED-ML object, or @c NULL
   * in certain very usual circumstances where a namespace is not set.
   *
   * @see getLevel()
   * @see getVersion()
   */
  virtual const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getElementNamespaces() const;


  /**
   * Returns a list of the XML Namespaces declared on the SED-ML document
   * owning this object.
   *
   * The SedNamespaces object encapsulates SED-ML Level/Version/namespaces
   * information.  It is used to communicate the SED-ML Level, Version, and (in
   * Level&nbsp;3) packages used in addition to SED-ML Level&nbsp;3 Core.
   *
   * @return the XML Namespaces associated with this SED-ML object, or @c NULL
   * in certain very usual circumstances where a namespace is not set.
   *
   * @see getLevel()
   * @see getVersion()
   */
  virtual LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getNamespaces();


  /**
   * Returns the SedDocument object containing this object instance.
   *
   * This method allows the caller to obtain the SedDocument for the
   * current object.
   * 
   * @return the parent SedDocument object of this SED-ML object.
   *
   * @see getParentSedObject()
   * @see getModel()
   */
  const SedDocument* getSedDocument () const;


  /**
   * Returns the SedDocument object containing this object instance.
   *
   * This method allows the caller to obtain the SedDocument for the
   * current object.
   * 
   * @return the parent SedDocument object of this SED-ML object.
   *
   * @see getParentSedObject()
   * @see getModel()
   */
  SedDocument* getSedDocument ();


  /**
   * Returns the parent SED-ML object containing this object.
   *
   * This returns the immediately-containing object.  This method is
   * convenient when holding an object nested inside other objects in an
   * SED-ML model.  
   * 
   * @return the parent SED-ML object of this SED-ML object.
   *
   * @see getSedDocument()
   * @see getModel()
   */
  SedBase* getParentSedObject();


  /**
   * Returns the parent SED-ML object containing this object.
   *
   * This returns the immediately-containing object.  This method is
   * convenient when holding an object nested inside other objects in an
   * SED-ML model.  
   * 
   * @return the parent SED-ML object of this SED-ML object.
   *
   * @see getSedDocument()
   * @see getModel()
   */
  const SedBase* getParentSedObject() const;


  /**
   * Returns the first ancestor object that has the given SED-ML type code.
   *
   * @if clike LibSEDML attaches an identifying code to every kind of SED-ML
   * object.  These are known as <em>SED-ML type codes</em>.  The set of
   * possible type codes is defined in the enumeration #SedTypeCode_t.
   * The names of the type codes all begin with the characters @c
   * SEDML_. @endif@if java LibSEDML attaches an identifying code to every
   * kind of SED-ML object.  These are known as <em>SED-ML type codes</em>.  In
   * other languages, the set of type codes is stored in an enumeration; in
   * the Java language interface for libSEDML, the type codes are defined as
   * static integer constants in the interface class {@link
   * libsedmlConstants}.  The names of the type codes all begin with the
   * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
   * code to every kind of SED-ML object.  These are known as <em>SED-ML type
   * codes</em>.  In the Python language interface for libSEDML, the type
   * codes are defined as static integer constants in the interface class
   * @link libsedml@endlink.  The names of the type codes all begin with the
   * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
   * code to every kind of SED-ML object.  These are known as <em>SED-ML type
   * codes</em>.  In the C# language interface for libSEDML, the type codes
   * are defined as static integer constants in the interface class @link
   * libsedmlcs.libsedml libsedml@endlink.  The names of the type codes all begin with
   * the characters @c SEDML_. @endif@~
   *
   * This method searches the tree of objects that are parents of this
   * object, and returns the first one that has the given SED-ML type code from 
   * the given @p pkgName.
   *
   * @param type the SED-ML type code of the object sought
   *
   * @return the ancestor SED-ML object of this SED-ML object that corresponds
   * to the given @if clike #SedTypeCode_t value@else SED-ML object type
   * code@endif, or @c NULL if no ancestor exists.
   */
  SedBase* getAncestorOfType(int type);


  /**
   * Returns the first ancestor object that has the given SED-ML type code.
   *
   * @if clike LibSEDML attaches an identifying code to every kind of SED-ML
   * object.  These are known as <em>SED-ML type codes</em>.  The set of
   * possible type codes is defined in the enumeration #SedTypeCode_t.
   * The names of the type codes all begin with the characters @c
   * SEDML_. @endif@if java LibSEDML attaches an identifying code to every
   * kind of SED-ML object.  These are known as <em>SED-ML type codes</em>.  In
   * other languages, the set of type codes is stored in an enumeration; in
   * the Java language interface for libSEDML, the type codes are defined as
   * static integer constants in the interface class {@link
   * libsedmlConstants}.  The names of the type codes all begin with the
   * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
   * code to every kind of SED-ML object.  These are known as <em>SED-ML type
   * codes</em>.  In the Python language interface for libSEDML, the type
   * codes are defined as static integer constants in the interface class
   * @link libsedml@endlink.  The names of the type codes all begin with the
   * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
   * code to every kind of SED-ML object.  These are known as <em>SED-ML type
   * codes</em>.  In the C# language interface for libSEDML, the type codes
   * are defined as static integer constants in the interface class @link
   * libsedmlcs.libsedml libsedml@endlink.  The names of the type codes all begin with
   * the characters @c SEDML_. @endif@~
   *
   * This method searches the tree of objects that are parents of this
   * object, and returns the first one that has the given SED-ML type code from 
   * the given @p pkgName.
   *
   * @param type the SED-ML type code of the object sought
   *
   * @return the ancestor SED-ML object of this SED-ML object that corresponds
   * to the given @if clike #SedTypeCode_t value@else SED-ML object type
   * code@endif, or @c NULL if no ancestor exists.
   *
   */
  const SedBase* getAncestorOfType(int type) const;


  /**
   * Returns the line number on which this object first appears in the XML
   * representation of the SED-ML document, or '0' if the object was created,
   * not read from a file.
   *
   * @return the line number of this SED-ML object, or '0' if no such value.
   *
   * @note The line number for each construct in an SED-ML model is set upon
   * reading the model.  The accuracy of the line number depends on the
   * correctness of the XML representation of the model, and on the
   * particular XML parser library being used.  The former limitation
   * relates to the following problem: if the model is actually invalid
   * XML, then the parser may not be able to interpret the data correctly
   * and consequently may not be able to establish the real line number.
   * The latter limitation is simply that different parsers seem to have
   * their own accuracy limitations, and out of all the parsers supported
   * by libSEDML, none have been 100% accurate in all situations. (At this
   * time, libSEDML supports the use of <a target="_blank"
   * href="http://xmlsoft.org">libxml2</a>, <a target="_blank"
   * href="http://expat.sourceforge.net/">Expat</a> and <a target="_blank"
   * href="http://xerces.apache.org/xerces-c/">Xerces</a>.)
   *
   * @see getColumn()
   */
  unsigned int getLine () const;


  /**
   * Returns the column number on which this object first appears in the XML
   * representation of the SED-ML document, or '0' if the object was created,
   * not read from a file.
   * 
   * @return the column number of this SED-ML object, or '0' if no such value.
   * 
   * @note The column number for each construct in an SED-ML model is set
   * upon reading the model.  The accuracy of the column number depends on
   * the correctness of the XML representation of the model, and on the
   * particular XML parser library being used.  The former limitation
   * relates to the following problem: if the model is actually invalid
   * XML, then the parser may not be able to interpret the data correctly
   * and consequently may not be able to establish the real column number.
   * The latter limitation is simply that different parsers seem to have
   * their own accuracy limitations, and out of all the parsers supported
   * by libSEDML, none have been 100% accurate in all situations. (At this
   * time, libSEDML supports the use of <a target="_blank"
   * href="http://xmlsoft.org">libxml2</a>, <a target="_blank"
   * href="http://expat.sourceforge.net/">Expat</a> and <a target="_blank"
   * href="http://xerces.apache.org/xerces-c/">Xerces</a>.)
   * 
   * @see getLine()
   */
  unsigned int getColumn () const;


  /**
   * Predicate returning @c true if this object's "metaid" attribute is set.
   *
   * @return @c true if the "metaid" attribute of this SED-ML object is
   * set, @c false otherwise.
   *
   * @see getMetaId()
   * @see setMetaId(const std::string& metaid)
   */
  bool isSetMetaId () const;


  /**
   * Predicate returning @c true if this object's "id" attribute is set.
   *
   * @return @c true if the "id" attribute of this SED-ML object is
   * set, @c false otherwise.
   *
   * @see getId()
   */
  virtual bool isSetId() const;

  /**
   * Predicate returning @c true if this element's "name" attribute is set.
   *
   * @return @c true if this element's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;

  /**
   * Predicate returning @c true if this
   * object's "notes" subelement exists and has content.
   *
   * The optional SED-ML element named "notes", present on every major SED-ML
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type SedBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libSEDML provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode xhtml@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://sedml.org/Documents/Specifications">SED-ML specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The SED-ML Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @return @c true if a "notes" subelement exists, @c false otherwise.
   * 
   * @see getNotes()
   * @see getNotesString()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  bool isSetNotes () const;


  /**
   * Predicate returning @c true if this
   * object's "annotation" subelement exists and has content.
   *
   * Whereas the SedBase "notes" subelement is a container for content to be
   * shown directly to humans, the "annotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from SedBase can have its own value for
   * "annotation".  The element's content type is <a target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type
   * "any"</a>, allowing essentially arbitrary well-formed XML data
   * content.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * @return @c true if a "annotation" subelement exists, @c false
   * otherwise.
   * 
   * @see getAnnotation()
   * @see getAnnotationString()
   * @see setAnnotation(const XMLNode* annotation)
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const std::string& annotation)
   * @see unsetAnnotation()
   */
  bool isSetAnnotation () const;


  /**
   * Sets the value of the meta-identifier attribute of this object.
   *
   * @copydetails doc_what_is_metaid 
   *
   * The string @p metaid is copied.  
   *
   * @param metaid the identifier string to use as the value of the
   * "metaid" attribute
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
   * 
   * @see getMetaId()
   * @see isSetMetaId()
   */
  int setMetaId (const std::string& metaid);


  /**
   * Sets the value of the "id" attribute of this SED-ML object.
   *
   * @copydetails doc_set_id
   */
  virtual int setId(const std::string& sid);


  /**
   * Sets the value of the "name" attribute of this element.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p name = @c NULL or an empty string is
   * equivalent to calling unsetName().
   */
  virtual int setName(const std::string& name);


  /**
   * Sets the value of the "annotation" subelement of this SED-ML object.
   *
   * The content of @p annotation is copied, and any previous content of
   * this object's "annotation" subelement is deleted.
   * 
   * Whereas the SedBase "notes" subelement is a container for content to be
   * shown directly to humans, the "annotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from SedBase can have its own value for
   * "annotation".  The element's content type is <a target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type
   * "any"</a>, allowing essentially arbitrary well-formed XML data
   * content.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * Call this method will result in any existing content of the
   * "annotation" subelement to be discarded.  Unless you have taken steps
   * to first copy and reconstitute any existing annotations into the @p
   * annotation that is about to be assigned, it is likely that performing
   * such wholesale replacement is unfriendly towards other software
   * applications whose annotations are discarded.  An alternative may be
   * to use SedBase::appendAnnotation(const XMLNode* annotation) or
   * SedBase::appendAnnotation(const std::string& annotation).
   *
   * @param annotation an XML structure that is to be used as the new content
   * of the "annotation" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   *
   * @see getAnnotationString()
   * @see isSetAnnotation()
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const std::string& annotation)
   * @see unsetAnnotation()
   */
  virtual int setAnnotation (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation);


  /**
   * Sets the value of the "annotation" subelement of this SED-ML object.
   *
   * The content of @p annotation is copied, and any previous content of
   * this object's "annotation" subelement is deleted.
   * 
   * Whereas the SedBase "notes" subelement is a container for content to be
   * shown directly to humans, the "annotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from SedBase can have its own value for
   * "annotation".  The element's content type is <a target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type
   * "any"</a>, allowing essentially arbitrary well-formed XML data
   * content.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * Call this method will result in any existing content of the
   * "annotation" subelement to be discarded.  Unless you have taken steps
   * to first copy and reconstitute any existing annotations into the @p
   * annotation that is about to be assigned, it is likely that performing
   * such wholesale replacement is unfriendly towards other software
   * applications whose annotations are discarded.  An alternative may be
   * to use SedBase::appendAnnotation(const XMLNode* annotation) or
   * SedBase::appendAnnotation(const std::string& annotation).
   *
   * @param annotation an XML string that is to be used as the content
   * of the "annotation" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   *
   * @see getAnnotationString()
   * @see isSetAnnotation()
   * @see setAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const std::string& annotation)
   * @see unsetAnnotation()
   */
  virtual int setAnnotation (const std::string& annotation);


  /**
   * Appends the given @p annotation to the "annotation" subelement of this
   * object.
   * 
   * Whereas the SedBase "notes" subelement is a container for content to be
   * shown directly to humans, the "annotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from SedBase can have its own value for
   * "annotation".  The element's content type is <a
   * target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type "any"</a>,
   * allowing essentially arbitrary well-formed XML data content.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * Unlike SedBase::setAnnotation(const XMLNode* annotation) or
   * SedBase::setAnnotation(const std::string& annotation), this method
   * allows other annotations to be preserved when an application adds its
   * own data.
   *
   * @param annotation an XML structure that is to be copied and appended
   * to the content of the "annotation" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   *
   * @see getAnnotationString()
   * @see isSetAnnotation()
   * @see setAnnotation(const XMLNode* annotation)
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const std::string& annotation)
   * @see unsetAnnotation()
   */
  virtual int appendAnnotation (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation);


  /**
   * Appends the given @p annotation to the "annotation" subelement of this
   * object.
   *
   * Whereas the SedBase "notes" subelement is a container for content to be
   * shown directly to humans, the "annotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from SedBase can have its own value for
   * "annotation".  The element's content type is <a
   * target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type "any"</a>,
   * allowing essentially arbitrary well-formed XML data content.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * Unlike SedBase::setAnnotation(const XMLNode* annotation) or
   * SedBase::setAnnotation(const std::string& annotation), this method
   * allows other annotations to be preserved when an application adds its
   * own data.
   *
   * @param annotation an XML string that is to be copied and appended
   * to the content of the "annotation" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   *
   * @see getAnnotationString()
   * @see isSetAnnotation()
   * @see setAnnotation(const XMLNode* annotation)
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see unsetAnnotation()
   */
  virtual int appendAnnotation (const std::string& annotation);


  /**
   * Removes the top-level element within the "annotation" subelement of this
   * SED-ML object with the given name and optional URI.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * Calling this method allows a particular annotation element to be removed
   * whilst the remaining annotations remain intact.
   *
   * @param elementName a string representing the name of the top level
   * annotation element that is to be removed
   * @param elementURI an optional string that is used to check both the name
   * and URI of the top level element to be removed
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_ANNOTATION_NAME_NOT_FOUND LIBSEDML_ANNOTATION_NAME_NOT_FOUND @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_ANNOTATION_NS_NOT_FOUND LIBSEDML_ANNOTATION_NS_NOT_FOUND @endlink
   *
   * @see replaceTopLevelAnnotationElement(const XMLNode *)
   * @see replaceTopLevelAnnotationElement(const std::string&)
   */
  int removeTopLevelAnnotationElement(const std::string elementName,
                                      const std::string elementURI = "");


  /**
   * Replaces the given top-level element within the "annotation"
   * subelement of this SED-ML object and with the annotation element supplied.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * This method determines the name of the element to be replaced from the
   * annotation argument. Functionally it is equivalent to calling
   * <code> removeTopLevelAnnotationElement(name); appendAnnotation(annotation_with_name);
   * </code> with the exception that the placement of the annotation element remains
   * the same.
   *
   * @param annotation XMLNode representing the replacement top level annotation
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   *
   * @see removeTopLevelAnnotationElement(const std::string elementName, const std::string elementURI)
   * @see replaceTopLevelAnnotationElement(const std::string&)
   */
  int replaceTopLevelAnnotationElement(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation);


  /**
   * Replaces the given top-level element within the "annotation"
   * subelement of this SED-ML object and with the annotation element supplied.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * This method determines the name of the element to be replaced from the
   * annotation argument. Functionally it is equivalent to calling
   * <code> removeTopLevelAnnotationElement(name); appendAnnotation(annotation_with_name);
   * </code> with the exception that the placement of the annotation element remains
   * the same.
   *
   * @param annotation string representing the replacement top level annotation
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   *
   * @see removeTopLevelAnnotationElement(const std::string elementName, const std::string elementURI)
   * @see replaceTopLevelAnnotationElement(const XMLNode*)
   */
  int replaceTopLevelAnnotationElement(const std::string& annotation);


  /**
   * Sets the value of the "notes" subelement of this SED-ML object.
   *
   * The content of @p notes is copied, and any existing content of this
   * object's "notes" subelement is deleted.
   *
   * The optional SED-ML element named "notes", present on every major SED-ML
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type SedBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libSEDML provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode xhtml@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://sedml.org/Documents/Specifications">SED-ML specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The SED-ML Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @param notes an XML structure that is to be used as the content of the
   * "notes" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const std::string& notes, bool addXHTMLMarkup)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int setNotes(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes);


  /**
   * Sets the value of the "notes" subelement of this SED-ML object to a copy
   * of the string @p notes.
   *
   * The content of @p notes is copied, and any existing content of this
   * object's "notes" subelement is deleted.
   *
   * The optional SED-ML element named "notes", present on every major SED-ML
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type SedBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libSEDML provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://sedml.org/Documents/Specifications">SED-ML specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The SED-ML Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @param notes an XML string that is to be used as the content of the
   * "notes" subelement of this object
   *
   * @param addXHTMLMarkup a boolean indicating whether to wrap the contents
   * of the @p notes argument with XHTML paragraph (<code>&lt;p&gt;</code>)
   * tags.  This is appropriate when the string in @p notes does not already
   * containg the appropriate XHTML markup.
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int setNotes(const std::string& notes, bool addXHTMLMarkup = false);


  /**
   * Appends the given @p notes to the "notes" subelement of this object.
   *
   * The content of @p notes is copied.
   *
   * The optional SED-ML element named "notes", present on every major SED-ML
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type SedBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libSEDML provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://sedml.org/Documents/Specifications">SED-ML specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The SED-ML Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   * 
   * @param notes an XML node structure that is to appended to the content
   * of the "notes" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes, bool addXHTMLMarkup)
   * @see appendNotes(const std::string& notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int appendNotes(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes);


  /**
   * Appends the given @p notes to the "notes" subelement of this object.
   *
   * The content of the parameter @p notes is copied.
   *
   * The optional SED-ML element named "notes", present on every major SED-ML
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type SedBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libSEDML provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://sedml.org/Documents/Specifications">SED-ML specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The SED-ML Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @param notes an XML string that is to appended to the content of
   * the "notes" subelement of this object
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes, bool addXHTMLMarkup)
   * @see appendNotes(const XMLNode* notes)
   * @see unsetNotes()
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int appendNotes(const std::string& notes);


  /** @cond doxygenLibsedmlInternal */
  /**
   * Sets the parent SedDocument of this SED-ML object.
   *
   * @param d the SedDocument object to use
   *
   * @see connectToChild()
   * @if clike
   * @see enablePackageInternal()
   * @endif@~
   */
  virtual void setSedDocument (SedDocument* d);
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /**
   * Sets the parent SED-ML object of this SED-ML object.
   * (Creates a child-parent relationship by the child)
   * This function is called when a child element is
   * set/added/created by its parent element (e.g. by setXXX,
   * addXXX, createXXX, and connectToChild functions of the
   * parent element).
   *
   * @param parent the SED-ML object to use
   */
  virtual void connectToParent (SedBase* parent);


  /**
   * Sets this SED-ML object to child SED-ML objects (if any).
   * (Creates a child-parent relationship by the parent)
   *
   * Subclasses must override this function if they define
   * one ore more child elements.
   * Basically, this function needs to be called in
   * constructor, copy constructor, assignment operator.
   *
   * @if clike
   * @see setSedDocument()
   * @see enablePackageInternal()
   * @endif@~
   */
  virtual void connectToChild ();

  /** @endcond */


  /**
   * Sets the namespaces relevant of this SED-ML object.
   *
   * The content of @p xmlns is copied, and this object's existing
   * namespace content is deleted.
   *
   * The SedNamespaces object encapsulates SED-ML Level/Version/namespaces
   * information.  It is used to communicate the SED-ML Level, Version, and
   * (in Level&nbsp;3) packages used in addition to SED-ML Level&nbsp;3 Core.
   * 
   * @param xmlns the namespaces to set
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  int setNamespaces(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns);


  /**
   * Unsets the value of the "metaid" attribute of this SED-ML object.
   *
   */
  int unsetMetaId ();


  /**
   * Unsets the value of the "id" attribute of this SED-ML object.
   *
   * @copydetails doc_unset_id
   */
  virtual int unsetId ();

  /**
    * Unsets the value of the "name" attribute of this SedSurface.
    *
    * @copydetails doc_returns_success_code
    * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
    * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
    */
   virtual int unsetName();


  /**
   * Unsets the value of the "notes" subelement of this SED-ML object.
   *
   * The optional SED-ML element named "notes", present on every major SED-ML
   * component type, is intended as a place for storing optional
   * information intended to be seen by humans.  An example use of the
   * "notes" element would be to contain formatted user comments about the
   * model element in which the "notes" element is enclosed.  Every object
   * derived directly or indirectly from type SedBase can have a separate
   * value for "notes", allowing users considerable freedom when adding
   * comments to their models.
   *
   * The format of "notes" elements must be <a target="_blank"
   * href="http://www.w3.org/TR/xhtml1/">XHTML&nbsp;1.0</a>.  To help
   * verify the formatting of "notes" content, libSEDML provides the static
   * utility method SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif); however,
   * readers are urged to consult the appropriate <a target="_blank"
   * href="http://sedml.org/Documents/Specifications">SED-ML specification
   * document</a> for the Level and Version of their model for more
   * in-depth explanations.  The SED-ML Level&nbsp;2 and &nbsp;3
   * specifications have considerable detail about how "notes" element
   * content must be structured.
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   *
   * @see getNotesString()
   * @see isSetNotes()
   * @see setNotes(const XMLNode* notes)
   * @see setNotes(const std::string& notes, bool addXHTMLMarkup)
   * @see appendNotes(const XMLNode* notes)
   * @see appendNotes(const std::string& notes)
   * @see SyntaxChecker::hasExpectedXHTMLSyntax(@if java XMLNode@endif)
   */
  int unsetNotes ();


  /**
   * Unsets the value of the "annotation" subelement of this SED-ML object.
   *
   * Whereas the SedBase "notes" subelement is a container for content to be
   * shown directly to humans, the "annotation" element is a container for
   * optional software-generated content @em not meant to be shown to
   * humans.  Every object derived from SedBase can have its own value for
   * "annotation".  The element's content type is <a target="_blank"
   * href="http://www.w3.org/TR/2004/REC-xml-20040204/#elemdecls">XML type
   * "any"</a>, allowing essentially arbitrary well-formed XML data
   * content.
   *
   * SED-ML places a few restrictions on the organization of the content of
   * annotations; these are intended to help software tools read and write
   * the data as well as help reduce conflicts between annotations added by
   * different tools.  Please see the SED-ML specifications for more details.
   *
   * @return integer value indicating success/failure of the
   * function.  The possible values returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   *
   * @see getAnnotation()
   * @see getAnnotationString()
   * @see isSetAnnotation()
   * @see setAnnotation(const XMLNode* annotation)
   * @see setAnnotation(const std::string& annotation)
   * @see appendAnnotation(const XMLNode* annotation)
   * @see appendAnnotation(const std::string& annotation)
   */
  int unsetAnnotation ();


  /**
   * Returns the SED-ML Level of the SedDocument object containing @em this
   * object.
   * 
   * @return the SED-ML level of this SED-ML object.
   * 
   * @see getVersion()
   * @see getNamespaces()
   * @see getPackageVersion()
   */
  unsigned int getLevel () const;


  /**
   * Returns the Version within the SED-ML Level of the SedDocument object
   * containing @em this object.
   * 
   * @return the SED-ML version of this SED-ML object.
   *
   * @see getLevel()
   * @see getNamespaces()
   */
  unsigned int getVersion () const;


  /**
   * Returns the libSEDML type code for this object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @copydetails doc_additional_typecode_details
   *
   * @return the @if clike #SedTypeCode_t value@else SED-ML object type
   * code@endif@~ of this SED-ML object, or @sedmlconstant{SEDML_UNKNOWN,
   * SedTypeCode_t} (the default).  The latter is possible because
   * subclasses of SedBase are not required to implement this method to return
   * a type code.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getPackageName()
   * @see getElementName()
   */
  virtual int getTypeCode () const;


  /**
   * Predicate returning @c true if this object's level/version and namespace
   * values correspond to a valid SED-ML specification.
   *
   * @return @c true if the level, version and namespace values of this 
   * SED-ML object correspond to a valid set of values, @c false otherwise.
   */
  bool hasValidLevelVersionNamespaceCombination();

  
  /**
   * Returns the XML element name of this object.
   *
   * This is overridden by subclasses to return a string appropriate to the
   * SED-ML component.  For example, Model defines it as returning @c
   * "model", CompartmentType defines it as returning @c "compartmentType",
   * and so on.
   */
  virtual const std::string& getElementName () const = 0;


  /**
   * Returns a string consisting of a partial SED-ML corresponding to just
   * this object.
   * 
   * @return the partial SED-ML that describes this SED-ML object.
   *
   * @warning <span class="warning">This is primarily provided for testing
   * and debugging purposes.  It may be removed in a future version of
   * libSEDML.</span>
   */
  char* toSed();


  // ------------------------------------------------------------------

  #ifndef SWIG
   /** @cond doxygenLibsedmlInternal */


   virtual int getAttribute(const std::string& attributeName, double& value) const;

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int getAttribute(const std::string& attributeName, bool& value) const;

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int getAttribute(const std::string& attributeName, unsigned int& value) const;

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int getAttribute(const std::string& attributeName, std::string& value) const;

  /** @endcond */

//   virtual int getAttribute(const std::string& attributeName, const char * value) const;


   virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int setAttribute(const std::string& attributeName, unsigned int value);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int setAttribute(const std::string& attributeName, const std::string& value);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

//   virtual int setAttribute(const std::string& attributeName, const char* value);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual SedBase* createChildObject(const std::string& elementName);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual int addChildObject(const std::string& elementName, const SedBase* element);

   /** @endcond */

   /** @cond doxygenLibsedmlInternal */

   virtual SedBase* removeChildObject(const std::string& elementName, const std::string& id);

   /** @endcond */

   /** @cond doxygenLibsedmlInternal */

   virtual unsigned int getNumObjects(const std::string& objectName);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

   virtual SedBase* getObject(const std::string& objectName, unsigned int index);

  /** @endcond */

  /** @cond doxygenLibsedmlInternal */

  template<typename T> T getAttribute(const std::string& attributeName)
  {
    T result;
    getAttribute(attributeName, result);
    return result;
  }
  /** @endcond */

#endif /* SWIG */



  /** @cond doxygenLibsedmlInternal */
  /**
   * Reads (initializes) this SED-ML object by reading from XMLInputStream.
   */
  void read (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream);
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /**
   * Writes (serializes) this SED-ML object by writing it to XMLOutputStream.
   */
  virtual void write (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const;
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /**
   * Subclasses should override this method to write out their contained
   * SED-ML objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.  For example:@if clike
   * <pre>
   *   SedBase::writeElements();
   *   mReactants.write(stream);
   *   mProducts.write(stream);
   *   ...
   * </pre>@endif@~
   */
  virtual void writeElements (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const;
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /* function returns true if component has all the required
   * attributes
   * needs to be overloaded for each component
   */
  virtual bool hasRequiredAttributes() const ;
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /* function returns true if component has all the required
   * elements
   * needs to be overloaded for each component
   */
  virtual bool hasRequiredElements() const ;
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /* function returns value if the object matches level/version/namespace
   */
  int checkCompatibility(const SedBase * object) const ;
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /* sets the Sednamespaces - internal use only*/
  int setSedNamespaces(SedNamespaces * sedmlns);

  /* sets the SedNamaepaces and owns the given object - internal use only */
  void setSedNamespacesAndOwn(SedNamespaces * disownedNs);
  /** @endcond */


  /** @cond doxygenLibsedmlInternal */
  /* gets the Sednamespaces - internal use only*/
  virtual SedNamespaces * getSedNamespaces() const;
  /** @endcond */


  /**
   * Removes this object from its parent.
   *
   * If the parent was storing this object as a pointer, it is deleted.  If
   * not, it is simply cleared (as in SedListOf objects).  This is a pure
   * virtual method, as every SedBase element has different parents, and
   * therefore different methods of removing itself.  Will fail (and not
   * delete itself) if it has no parent object.  This function is designed to
   * be overridden, but for all objects whose parent is of the class SedListOf,
   * the default implementation will work.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int removeFromParentAndDelete();


  /**
   * Returns @c true if this object's set of XML namespaces are the same
   * as the given object's XML namespaces.
   *
   * @param sb an object to compare with respect to namespaces
   *
   * @return boolean, @c true if this object's collection of namespaces is
   * the same as @p sb's, @c false otherwise.
   */
  bool matchesSedNamespaces(const SedBase * sb);


  /**
   * Returns @c true if this object's set of XML namespaces are the same
   * as the given object's XML namespaces.
   *
   * @param sb an object to compare with respect to namespaces
   *
   * @return boolean, @c true if this object's collection of namespaces is
   * the same as @p sb's, @c false otherwise.
   */
  bool matchesSedNamespaces(const SedBase * sb) const;


  /**
   * Returns @c true if this object's set of XML namespaces are a subset
   * of the given object's XML namespaces.
   *
   * @param sb an object to compare with respect to namespaces
   *
   * @return boolean, @c true if this object's collection of namespaces is
   * a subset of @p sb's, @c false otherwise.
   */
  bool matchesRequiredSedNamespacesForAddition(const SedBase * sb);
  
  
  /**
   * Returns @c true if this object's set of XML namespaces are a subset
   * of the given object's XML namespaces.
   *
   * @param sb an object to compare with respect to namespaces
   *
   * @return boolean, @c true if this object's collection of namespaces is
   * a subset of @p sb's, @c false otherwise.
   */
  bool matchesRequiredSedNamespacesForAddition(const SedBase * sb) const;


  /**
   * Sets the user data of this element.
   *
   * @copydetails doc_what_is_user_data
   *
   * @param userData specifies the new user data.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int setUserData(void *userData);


  /**
   * Returns the user data that has been previously set via setUserData().
   *
   * @copydetails doc_what_is_user_data
   *
   * @return the user data of this node, or @c NULL if no user data has been set.
   *
   * @if clike
   * @see ASTNode::setUserData(void *userData)
   * @endif@~
   */
  void *getUserData() const;

  /**
   * Predicate returning true or false depending on whether
   * the user data of this element has been set.
   *
   * @copydetails doc_what_is_user_data
   *
   * @return boolean, @c true if this object's user data has been set,
   * @c false otherwise.
   */
  bool isSetUserData() const;


  /**
   * Unsets the user data of this element.
   *
   * @copydetails doc_what_is_user_data
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUserData();


  /**
   * Returns the SedErrorLog used to log errors while reading and
   * validating SED-ML.
   *
   * @return the SedErrorLog used to log errors while reading and
   * validating SED-ML.
   */
  SedErrorLog* getErrorLog ();

protected:

  bool getHasBeenDeleted() const;

  /** 
   * When overridden allows SedBase elements to use the text included in between
   * the elements tags. The default implementation does nothing.
   * 
   * @param text the text string found between the element tags.
   */ 
  virtual void setElementText(const std::string &text);


  /** @cond doxygenLibsedmlInternal */

  bool matchesCoreSedNamespace(const SedBase * sb);

  bool matchesCoreSedNamespace(const SedBase * sb) const;

  /**
   * Creates a new SedBase object with the given SED-ML level, version.
   */
  SedBase (unsigned int level, unsigned int version);


  /**
   * Creates a new SedBase object with the given SedNamespaces.
   * Only subclasses may create SedBase objects.
   */
  SedBase (SedNamespaces* sedmlns);


  /**
  * Copy constructor. Creates a copy of this SedBase object.
   *
   * @param orig the object to copy.
  */
  SedBase(const SedBase& orig);


  /**
   * Subclasses should override this method to create, store, and then
   * return an SED-ML object corresponding to the next XMLToken in the
   * XMLInputStream.
   *
   * @return the SED-ML object corresponding to next XMLToken in the
   * XMLInputStream or @c NULL if the token was not recognized.
   */
  virtual SedBase* createObject (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream);


  /**
   * Predicate returning @c true if this
   * object's level/version and namespace values correspond to a valid
   * SED-ML specification.
   *
   * @param typecode the typecode for this element
   * @param xmlns the namespaces used by this element.
   *
   * @note  This function is provided as convenience method to be called from constructors. This 
   *        allows to use it in scenarios where the namespaces or typecode have not yet been initialized. 
   * 
   * @return @c true if the level, version and namespace values of this 
   * SED-ML object correspond to a valid set of values, @c false otherwise.
   */
  bool hasValidLevelVersionNamespaceCombination(int typecode, LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns);


  /**
   * Subclasses should override this method to read (and store) XHTML,
   * MathML, etc. directly from the XMLInputStream.
   *
   * @return true if the subclass read from the stream, false otherwise.
   */
  virtual bool readOtherXML (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream);


  /**
   * The SED-ML XML Schema is written such that the order of child elements
   * is significant.  LibSEDML can read elements out of order.  If you
   * override this method to indicate the ordinal position of element with
   * respect to its siblings, libSEDML will log an error if the element is
   * read out of order.
   *
   * @return the ordinal position of the element with respect to its
   * siblings or @c -1 (the default) to indicate the position is not
   * significant.
   */
  virtual int getElementPosition () const;


  /**
   * Convenience method for easily logging problems from within method
   * implementations.
   *
   * This is essentially a short form of getErrorLog()->logError(...)
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  void logError (  unsigned int       id
                 , const unsigned int level   = 2
                 , const unsigned int version = 3
                 , const std::string& details = ""
                 , unsigned int line = 0
                 , unsigned int column = 0 );

  /**
   * Helper to log a common type of error.
   */
  void logUnknownAttribute( const std::string& attribute,
          const unsigned int level,
          const unsigned int version,
          const std::string& element,
          const std::string& prefix="");


  /**
   * Helper to log a common type of error.
   */
  void logUnknownElement( const std::string& element,
        const unsigned int level,
        const unsigned int version );

 
  /**
   * Helper to log a common type of error.
   */
  void logEmptyString( const std::string& attribute,
                       const unsigned int level,
                       const unsigned int version,
                       const std::string& element);


  /**
   * Subclasses should override this method to add the list of
   * expected attributes. Be sure to call your parents implementation 
   * of this method as well.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /**
   * Subclasses should override this method to read values from the given
   * XMLAttributes set into their specific fields.  Be sure to call your
   * parents implementation of this method as well.
   */
  virtual void readAttributes (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes& attributes, 
                               const LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes& expectedAttributes);


  /**
   * Subclasses should override this method to write their XML attributes
   * to the XMLOutputStream.  Be sure to call your parents implementation
   * of this method as well.  For example:
   *
   *   SedBase::writeAttributes(stream);
   *   stream.writeAttribute( "id"  , mId   );
   *   stream.writeAttribute( "name", mName );
   *   ...
   *
   * (NOTICE) this function doesn't write xmlns attributes.
   * Be sure to implement wirteXMLNS() function to write xmlns attributes.
   *
   */
  virtual void writeAttributes (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const;


  /**
   *
   * Subclasses should override this method to write their xmlns attriubutes
   * (if any) to the XMLOutputStream. 
   *
   */
  virtual void writeXMLNS (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const;


  /**
   * Checks that an SED-ML SedListOf element is populated.  
   * If a listOf element has been declared with no elements, 
   * an error is logged.
   */
  void checkSedListOfPopulated(SedBase* object);

  /**
   * Checks that the given default namespace in the given element is valid.
   * If the given default namespace is not valid, an error is logged.
   */
  void checkDefaultNamespace(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns, 
    const std::string& elementName, const std::string& prefix = "");

  /**
   * Checks the annotation does not declare an sedml namespace.
   * If the annotation declares an sedml namespace an error is logged.
   */
  void checkAnnotation();


  /**
   * Checks that the XHTML is valid.
   * If the xhtml does not conform to the specification of valid xhtml within
   * an sedml document, an error is logged.
   */
  void checkXHTML(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode *);


  /**
   * Checks that the math ml ns has been declared
   */
  const std::string checkMathMLNamespace(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken elem);

   /**
   * Sets the XML namespace to which this element belongs to.
   * For example, all elements that belong to SED-ML Level 3 Version 1 Core
   * must set the namespace to <code>"http://www.sedml.org/sedml/level3/version1/core"</code>; 
   * all elements that belong to Layout Extension Version 1 for SED-ML Level 3
   * Version 1 Core must set the namespace to 
   * <code>"http://www.sedml.org/sedml/level3/version1/layout/version1"</code>.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  int setElementNamespace(const std::string &uri);


  /**
   * Gets the XML namespace (URI) to which this element belongs to.
   */
  const std::string& getElementNamespace() const;

  std::string getURI() const;

  std::string getPrefix() const;

  /**
   * Return the SED-ML XML namespace prefix of this element.
   *
   * This will be the same as getPrefix() unless the element in question is
   * an element of an SED-ML extension class.
   *
   * @return the XML namespace prefix
   */
  std::string getSedPrefix() const;


  /**
   * Returns the root element of the node tree to which this element is connected.
   *
   * @note The root element may not be an SedDocument element. For example,
   * this element is the root element if this element doesn't have a parent
   * SED-ML object (i.e. mParentSedObject is NULL)
   *
   * @see enablePackageInternal
   */
  SedBase* getRootElement();


  // ------------------------------------------------------------------


  std::string     mMetaId;
  std::string     mId;
  std::string     mName;
  bool            mIdAllowedPreV4;
  bool            mNameAllowedPreV4;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*        mNotes;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*        mAnnotation;
  SedDocument*   mSed;
  SedNamespaces* mSedNamespaces;
  void*          mUserData;

  unsigned int mLine;
  unsigned int mColumn;

  /* store the parent SED-ML object */
  SedBase* mParentSedObject;
  bool mHasBeenDeleted;

  std::string mEmptyString;

  //
  // namespace to which this SedBase object belongs.
  // This variable can be publicly accessible by getElementNamespace function.
  //
  // For example, mURI of elements defined in L3 Core (or defined in Level 2 
  // or before) will be the URI defined in the corresponding SED-ML specification
  // (e.g. "http://www.sedml.org/sedml/level3/version1" for L3V1 Core); and mURI
  // will be "http://www.sedml.org/sedml/level3/version1/layout/version1" for 
  // elements defined in layout extension L3V1-V1.
  // The purpuse of this data member is to explicitly distinguish elements in core 
  // package and extension packages.
  // 
  // From the implementation point of view, this variable is needed to identify
  // if the prefix needs to be added when printing elements in some package extension.
  // (i.e. used in getPrefix function)
  //
  std::string mURI;

  
  /** @endcond */

private:
  /** @cond doxygenLibsedmlInternal */
  /**
   * Stores the location (line and column) and any XML namespaces (for
   * roundtripping) declared on this SED-ML (XML) element.
   */
  void setSedBaseFields (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken& element);


  /**
   * Reads an annotation from the stream and returns true if successful.
   *
   * @return true if read an <annotation> element from the stream
   */
  bool readAnnotation (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream);


  /**
   * Reads the notes from the stream and returns true if successful.
   *
   * @return true if read a <notes> element from the stream
   */
  bool readNotes (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream);


  /** @endcond */
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */



#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Returns the value of the "metaid" attribute of the given SedBase_t
 * structure.
 *
 * @param sb the SedBase_t structure
 *
 * @return the value of the "metaid" attribute of @p sb
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
const char *
SedBase_getMetaId (SedBase_t *sb);


/**
 * Returns the parent SedDocument_t structure of the given SedBase_t
 * structure.
 *
 * @param sb the SedBase_t structure
 *
 * @return the parent SedDocument of this SED-ML structure.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
const SedDocument_t *
SedBase_getSedDocument (SedBase_t *sb);


/**
 * Returns the parent SedBase_t structure of the given SedBase_t
 * structure.
 *
 * @param sb the SedBase_t structure
 *
 * @return the parent SedBase  of this SED-ML structure.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
const SedBase_t *
SedBase_getParentSedObject (SedBase_t *sb);


/**
 * Returns the ancestor SedBase_t structure of the given SedBase_t
 * structure that corresponds to the given type.
 *
 * This function allows any structure to determine its exact
 * location/function within a model. For example a
 * StoichiometryMath_t structure has ancestors of type SpeciesReference_t,
 * SedListOf_t(Products/Reactants), Reaction_t, SedListOfReactions_t and Model_t;
 * any of which can be accessed via this function.
 *
 * @param sb the SedBase_t structure
 * @param type the typecode (int) of the structure to be returned
 *
 * @return the ancestor SedBase_t structure of this SED-ML structure with
 * the corresponding typecode (int), NULL if there is no ancestor of
 * this type.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
const SedBase_t *
SedBase_getAncestorOfType (SedBase_t *sb, int type);

/**
 * Returns the line number on which the given structure first appears in the
 * XML representation of the SED-ML document, or '0' if the object was created,
 * not read from a file.
 *
 * @param sb the SedBase_t structure
 *
 * @return the line number of the given structure, or '0' if no such value.
 *
 * @see getColumn().
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
unsigned int
SedBase_getLine (const SedBase_t *sb);


/**
 * Returns the column number on which the given structure first appears in the
 * XML representation of the SED-ML document, or '0' if the object was created,
 * not read from a file.
 *
 * @param sb the SedBase_t structure
 *
 * @return the column number of this SED-ML structure, or '0' if no such value.
 *
 * @see getLine().
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
unsigned int
SedBase_getColumn (const SedBase_t *sb);


/**
 * Returns the notes from given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 *
 * @return the XMLNode_t structure representing the notes from this structure.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
XMLNode_t *
SedBase_getNotes (SedBase_t *sb);


/**
 * Returns the notes string from given SED-ML structure.
 * The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @param sb the given SED-ML structure.
 *
 * @return the string (char*) representing the notes from this structure.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
char*
SedBase_getNotesString (SedBase_t *sb);


/**
 * Returns the annotation from given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 *
 * @return the XMLNode_t structure representing the annotation from this structure.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
XMLNode_t *
SedBase_getAnnotation (SedBase_t *sb);


/**
 * Returns the annotation string from given SED-ML structure.
 * The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @param sb the given SED-ML structure.
 *
 * @return the string (char*) representing the annotation from this structure.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
char*
SedBase_getAnnotationString (SedBase_t *sb);


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "metaid" attribute is set.
 *
 * @param sb the SedBase_t structure to query
 *
 * @return nonzero (for true) if the "metaid" attribute of this SED-ML structure
 * is set, zero (for false) otherwise.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_isSetMetaId (const SedBase_t *sb);


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "notes" subelement is set.
 *
 * @param sb the SedBase_t structure to query
 *
 * @return nonzero (for true) if the "notes" subelement of this SED-ML structure
 * is set, zero (for false) otherwise.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_isSetNotes (const SedBase_t *sb);


/**
 * Predicate returning nonzero true or false depending on whether the given
 * structure's "annotation" subelement is set.
 *
 * @param sb the SedBase_t structure to query
 *
 * @return nonzero (for true) if the "annotation" subelement of this SED-ML structure
 * is set, zero (for false) otherwise.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_isSetAnnotation (const SedBase_t *sb);


/**
 * Sets the value of the "metaid" attribute of the given structure.
 *
 * The string @p metaid is copied.  The value of @p metaid must be an
 * identifier conforming to the syntax defined by the XML 1.0 data type
 * ID.  Among other things, this type requires that a value is unique
 * among all the values of type XML ID in an SedDocument_t.  Although SED-ML
 * only uses XML ID for the "metaid" attribute, callers should be careful
 * if they use XML ID's in XML portions of a model that are not defined
 * by SED-ML, such as in the application-specific content of the
 * "annotation" subelement.
 *
 * @param sb the SedBase_t structure
 *
 * @param metaid the identifier string to use as the value of the
 * "metaid" attribute
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with the metaid set to NULL is equivalent to
 * unsetting the "metaid" attribute.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setMetaId (SedBase_t *sb, const char *metaid);


/**
 * Sets the namespaces relevant of this SED-ML structure.
 *
 * @param sb the SedBase_t structure
 *
 * @param xmlns the namespaces to set
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setNamespaces (SedBase_t *sb, XMLNamespaces_t *xmlns);


/**
 * Sets the notes for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param notes the XMLNode_t structure respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setNotes (SedBase_t *sb, XMLNode_t *notes);


/**
 * Sets the notes for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setNotesString (SedBase_t *sb, const char *notes);


/**
 * Sets the notes for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setNotesStringAddMarkup (SedBase_t *sb, const char *notes);


/**
 * Appends the notes for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param notes the XMLNode_t structure respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_appendNotes (SedBase_t *sb, XMLNode_t *notes);


/**
 * Appends the notes for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param notes the string (const char*) respresenting the notes.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_appendNotesString (SedBase_t *sb, const char *notes);


/**
 * Sets the annotation for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param annotation the XMLNode_t structure respresenting the annotation.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setAnnotation (SedBase_t *sb, XMLNode_t *annotation);


/**
 * Sets the annotation for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param annotation the string (const char*) respresenting the annotation.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setAnnotationString (SedBase_t *sb, const char *annotation);


/**
 * Appends the annotation for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param annotation the XMLNode_t structure respresenting the annotation.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_appendAnnotation (SedBase_t *sb, XMLNode_t *annotation);


/**
 * Appends the annotation for the given SED-ML structure.
 *
 * @param sb the given SED-ML structure.
 * @param annotation the string (const char*) respresenting the annotation.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_appendAnnotationString (SedBase_t *sb, const char *annotation);


/**
 * Unsets the "metaid" attribute of the given structure.
 *
 * @param sb the SedBase_t structure
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_unsetMetaId (SedBase_t *sb);


/**
 * Unsets the "notes" subelement of the given structure.
 *
 * @param sb the SedBase_t structure
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_unsetNotes (SedBase_t *sb);


/**
 * Unsets the "annotation" subelement of the given structure.
 *
 * @param sb the SedBase_t structure
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_unsetAnnotation (SedBase_t *sb);


/**
 * Returns the Model_t structure in which the given instance is located.
 *
 * @param sb the SedBase_t structure
 *
 * @return the parent Model_t strucdture of the given structure.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
const Model_t *
SedBase_getModel (const SedBase_t *sb);


/**
 * Returns the SED-ML Level of the overall SED-ML document.
 *
 * @param sb the SedBase_t structure to query
 *
 * @return the SED-ML level of the given structure.
 *
 * @see getVersion()
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
unsigned int
SedBase_getLevel (const SedBase_t *sb);


/**
 * Returns the Version within the SED-ML Level of the overall SED-ML document.
 *
 * @param sb the SedBase_t structure to query
 *
 * @return the SED-ML version of the given structure.
 *
 * @see getLevel()
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
unsigned int
SedBase_getVersion (const SedBase_t *sb);


/**
 * Returns the libSEDML type code for this structure.
 *
 * This method MAY return the typecode of this SED-ML structure or it MAY
 * return SEDML_UNKNOWN.  That is, subclasses of SedBase are not required to
 * implement this method to return a typecode.  This method is meant
 * primarily for the LibSEDML C interface where class and subclass
 * information is not readily available.
 *
 * @note In libSEDML 5, the type of return value has been changed from
 * typecode (int) to int. The return value is one of enum values defined for
 * each package. For example, return values will be one of typecode (int) if
 * this structure is defined in SED-ML core package, return values will be one of
 * SedLayoutTypeCode_t if this structure is defined in Layout extension
 * (i.e. similar enum types are defined in each package extension for each
 * SedBase subclass) The value of each typecode can be duplicated between those
 * of different packages. Thus, to distinguish the typecodes of different
 * packages, not only the return value of getTypeCode() but also that of
 * getPackageName() must be checked.
 *
 * @param sb the SedBase_t structure
 *
 * @return the typecode (int value) of this SED-ML structure or SEDML_UNKNOWN
 * (default).
 *
 * @see getElementName()
 * @see getPackageName()
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_getTypeCode (const SedBase_t *sb);


/**
 * Returns the XML element name of the given structure.
 *
 * This is overridden by subclasses to return a string appropriate to the
 * SED-ML component.  For example, Model defines it as returning "model",
 * CompartmentType defines it as returning "compartmentType", etc.
 *
 * @param sb the SedBase_t structure
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
const char *
SedBase_getElementName (const SedBase_t *sb);


/**
 * Predicate returning nonzero true or false depending on whether the
 * structure's level/version and namespace values correspond to a valid
 * SED-ML specification.
 *
 * @param sb the SedBase_t structure
 *
 * @return nonzero (true) if the level, version and namespace values of this
 * SED-ML structure correspond to a valid set of values, zero (false) otherwise.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_hasValidLevelVersionNamespaceCombination(SedBase_t *sb);


/**
 * Sets the user data of this node. This can be used by the application
 * developer to attach custom information to the node. In case of a deep
 * copy this attribute will passed as it is. The attribute will be never
 * interpreted by this class.
 *
 * @param sb defines the node of which the user data should be set.
 * @param userData specifies the new user data.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int 
SedBase_setUserData(SedBase_t* sb, void *userData);

/**
 * Returns the user data that has been previously set by setUserData().
 *
 * @param sb the SedBase_t structure in question.
 * @return the user data of this node. NULL if no user data has been.
 * @see SedBase_setUserData
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
void *
SedBase_getUserData(const SedBase_t* sb);

/**
 * Predicate returning nonzero true or false depending on whether the
 * structure's user data object has been set.
 *
 * @param sb defines the node of which the user data should be queried.
 *
 * @return nonzero (true) if the user data object of this
 * SED-ML structure has been set, zero (false) otherwise.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int 
SedBase_isSetUserData(const SedBase_t* sb);

/**
 * Unsets the user data of this node. 
 *
 * @param sb defines the node of which the user data should be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int 
SedBase_unsetUserData(SedBase_t* sb);


/**
 * Returns the value of the "id" attribute of this SedBase_t.
 *
 * @param element the SedBase_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedBase_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
char *
SedBase_getId(const SedBase_t * element);


/**
 * Returns the value of the "name" attribute of this SedBase_t.
 *
 * @param element the SedBase_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedBase_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
char *
SedBase_getName(const SedBase_t * element);


/**
 * Predicate returning @c 1 (true) if this SedBase_t's "id" attribute is
 * set.
 *
 * @param element the SedBase_t structure.
 *
 * @return @c 1 (true) if this SedBase_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_isSetId(const SedBase_t * element);


/**
 * Predicate returning @c 1 (true) if this SedBase_t's "name" attribute
 * is set.
 *
 * @param element the SedBase_t structure.
 *
 * @return @c 1 (true) if this SedBase_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_isSetName(const SedBase_t * element);


/**
 * Sets the value of the "id" attribute of this SedBase_t.
 *
 * @param element the SedBase_t structure.
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
 * to calling SedBase_unsetId().
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setId(SedBase_t * element, const char * id);


/**
 * Sets the value of the "name" attribute of this SedBase_t.
 *
 * @param element the SedBase_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SedBase_unsetName().
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_setName(SedBase_t * element, const char * name);


/**
 * Unsets the value of the "id" attribute of this SedBase_t.
 *
 * @param element the SedBase_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_unsetId(SedBase_t * element);


/**
 * Unsets the value of the "name" attribute of this SedBase_t.
 *
 * @param element the SedBase_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SedBase_t
 */
LIBSEDML_EXTERN
int
SedBase_unsetName(SedBase_t * element);

END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* !SWIG   */
#endif  /* SedBase_h */
