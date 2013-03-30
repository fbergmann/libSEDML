/**
 * @file    SedMLReader.h
 * @brief   Reads an SedML Document into memory
 * @author  Ben Bornstein
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
 * @class SedMLReader
 * @ingroup Core
 * @brief Methods for reading SedML from files and text strings.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * The SedMLReader class provides the main interface for reading SedML
 * content from files and strings.  The methods for reading SedML all return
 * an SedMLDocument object representing the results.
 *
 * In the case of failures (such as if the SedML contains errors or a file
 * cannot be read), the errors will be recorded with the SedMLErrorLog
 * object kept in the SedMLDocument returned by SedMLReader.  Consequently,
 * immediately after calling a method on SedMLReader, callers should always
 * check for errors and warnings using the methods for this purpose
 * provided by SedMLDocument.
 *
 * For convenience as well as easy access from other languages besides C++,
 * this file also defines two global functions,
 * libsbml::readSedML(@if java String filename@endif)
 * and libsbml::readSedMLFromString(@if java String xml@endif).
 * They are equivalent to creating an SedMLReader
 * object and then calling the
 * SedMLReader::readSedML(@if java String filename@endif) or
 * SedMLReader::readSedMLFromString(@if java String xml@endif)
 * methods, respectively.
 *
 * @section compression Support for reading compressed files
 *
 * LibSedML provides support for reading (as well as writing) compressed
 * SedML files.  The process is transparent to the calling
 * application&mdash;the application does not need to do anything
 * deliberate to invoke the functionality.  If a given SedML filename ends
 * with an extension for the @em gzip, @em zip or @em bzip2 compression
 * formats (respectively, @c .gz, @c .zip, or @c .bz2), then the methods
 * SedMLReader::readSedML(@if java String filename@endif) and
 * SedMLWriter::writeSedML(@if java SedMLDocument d, String filename@endif)
 * will automatically decompress and compress the file while writing and
 * reading it.  If the filename has no such extension, it
 * will be read and written uncompressed as normal.
 *
 * The compression feature requires that the @em zlib (for @em gzip and @em
 * zip formats) and/or @em bzip2 (for @em bzip2 format) be available on the
 * system running libSedML, and that libSedML was configured with their
 * support compiled-in.  Please see the libSedML @if clike <a href="libsbml-installation.html">installation instructions</a> @endif@if python <a href="libsbml-installation.html">installation instructions</a> @endif@if java  <a href="../../../libsbml-installation.html">installation instructions</a> @endif@~ for more information about this.  The methods
 * @if java SedMLReader::hasZlib()@else hasZlib()@endif@~ and
 * @if java SedMLReader::hasBzip2()@else hasBzip2()@endif@~
 * can be used by an application to query at run-time whether support
 * for the compression libraries is available in the present copy of
 * libSedML.
 *
 * Support for compression is not mandated by the SedML standard, but
 * applications may find it helpful, particularly when large SedML models
 * are being communicated across data links of limited bandwidth.
 */

#ifndef SedMLReader_h
#define SedMLReader_h


#include <sedml/common/extern.h>
#include <sedml/common/sbmlfwd.h>
#include <sbml/util/util.h>


#ifdef __cplusplus


#include <string>

LIBSEDML_CPP_NAMESPACE_BEGIN

class SedMLDocument;


class LIBSEDML_EXTERN SedMLReader
{
public:

  /**
   * Creates a new SedMLReader and returns it. 
   *
   * The libSedML SedMLReader objects offer methods for reading SedML in
   * XML form from files and text strings.
   */
  SedMLReader ();


  /**
   * Destroys this SedMLReader.
   */
  virtual ~SedMLReader ();


  /**
   * Reads an SedML document from a file.
   *
   * This method is identical to SedMLReader::readSedMLFromFile(@if java String filename@endif).
   *
   * If the file named @p filename does not exist or its content is not
   * valid SedML, one or more errors will be logged with the SedMLDocument
   * object returned by this method.  Callers can use the methods on
   * SedMLDocument such as SedMLDocument::getNumErrors() and
   * SedMLDocument::getError(@if java long n@endif) to get the errors.  The object returned by
   * SedMLDocument::getError(@if java long n@endif) is an SedMLError object, and it has methods to
   * get the error code, category, and severity level of the problem, as
   * well as a textual description of the problem.  The possible severity
   * levels range from informational messages to fatal errors; see the
   * documentation for SedMLError for more information.
   *
   * If the file @p filename could not be read, the file-reading error will
   * appear first.  The error code @if clike (a value drawn from the enumeration
   * #XMLErrorCode_t) @endif@~ can provide a clue about what happened.  For example,
   * a file might be unreadable (either because it does not actually exist
   * or because the user does not have the necessary access priviledges to
   * read it) or some sort of file operation error may have been reported
   * by the underlying operating system.  Callers can check for these
   * situations using a program fragment such as the following:
   * @if clike
 @verbatim
 SedMLReader reader;
 SedMLDocument* doc  = reader.readSedMLFromFile(filename);
 
 if (doc->getNumErrors() > 0)
 {
   if (doc->getError(0)->getErrorId() == XMLError::XMLFileUnreadable)
   {
     // Handle case of unreadable file here.
   } 
   else if (doc->getError(0)->getErrorId() == XMLError::XMLFileOperationError)
   {
     // Handle case of other file operation error here.
   }
   else
   {
     // Handle other cases -- see error codes defined in XMLErrorCode_t
     // for other possible cases to check.
   }
 }
 @endverbatim
 @endif@if java
 @verbatim
 SedMLReader reader = new SedMLReader();
 SedMLDocument doc  = reader.readSedMLFromFile(filename);
 
 if (doc.getNumErrors() > 0)
 {
     if (doc.getError(0).getErrorId() == libsbmlConstants.XMLFileUnreadable)
     {
         // Handle case of unreadable file here.
     } 
     else if (doc.getError(0).getErrorId() == libsbmlConstants.XMLFileOperationError)
     {
         // Handle case of other file operation error here.
     }
     else
     {
         // Handle other error cases.
     }
 }
 @endverbatim
 @endif@if python
 @verbatim
 reader = SedMLReader()
 doc    = reader.readSedMLFromFile(filename)
 
 if doc.getNumErrors() > 0:
   if doc.getError(0).getErrorId() == libsbml.XMLFileUnreadable:
     # Handle case of unreadable file here.
   elif doc.getError(0).getErrorId() == libsbml.XMLFileOperationError:
     # Handle case of other file error here.
   else:
     # Handle other error cases here.
   
 @endverbatim
 @endif@if csharp
 @verbatim
 SedMLReader reader = new SedMLReader();
 SedMLDocument doc = reader.readSedMLFromFile(filename);

 if (doc.getNumErrors() > 0)
 {
     if (doc.getError(0).getErrorId() == libsbmlcs.libsbml.XMLFileUnreadable)
     {
          // Handle case of unreadable file here.
     }
     else if (doc.getError(0).getErrorId() == libsbmlcs.libsbml.XMLFileOperationError)
     {
          // Handle case of other file operation error here.
     }
     else
     {
          // Handle other cases -- see error codes defined in XMLErrorCode_t
          // for other possible cases to check.
     }
  }
 @endverbatim
 @endif@~
   *
   * If the given filename ends with the suffix @c ".gz" (for example, @c
   * "myfile.xml.gz"), the file is assumed to be compressed in @em gzip
   * format and will be automatically decompressed upon reading.
   * Similarly, if the given filename ends with @c ".zip" or @c ".bz2", the
   * file is assumed to be compressed in @em zip or @em bzip2 format
   * (respectively).  Files whose names lack these suffixes will be read
   * uncompressed.  Note that if the file is in @em zip format but the
   * archive contains more than one file, only the first file in the
   * archive will be read and the rest ignored.
   *
   * @htmlinclude note-reading-zipped-files.html
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the SedMLDocument created from the SedML content.
   *
   * @note LibSedML versions 2.x and later versions behave differently in
   * error handling in several respects.  One difference is how early some
   * errors are caught and whether libSedML continues processing a file in
   * the face of some early errors.  In general, libSedML versions after 2.x
   * stop parsing SedML inputs sooner than libSedML version 2.x in the face
   * of XML errors, because the errors may invalidate any further SedML
   * content.  For example, a missing XML declaration at the beginning of
   * the file was ignored by libSedML 2.x but in version 3.x and later, it
   * will cause libSedML to stop parsing the rest of the input altogether.
   * While this behavior may seem more severe and intolerant, it was
   * necessary in order to provide uniform behavior regardless of which
   * underlying XML parser (Expat, Xerces, libxml2) is being used by
   * libSedML.  The XML parsers themselves behave differently in their error
   * reporting, and sometimes libSedML has to resort to the lowest common
   * denominator.
   *
   * @see SedMLError
   */
  SedMLDocument* readSedML (const std::string& filename);


  /**
   * Reads an SedML document from a file.
   *
   * This method is identical to SedMLReader::readSedML(@if java String filename@endif).
   *
   * If the file named @p filename does not exist or its content is not
   * valid SedML, one or more errors will be logged with the SedMLDocument
   * object returned by this method.  Callers can use the methods on
   * SedMLDocument such as SedMLDocument::getNumErrors() and
   * SedMLDocument::getError(@if java long n@endif) to get the errors.  The object returned by
   * SedMLDocument::getError(@if java long n@endif) is an SedMLError object, and it has methods to
   * get the error code, category, and severity level of the problem, as
   * well as a textual description of the problem.  The possible severity
   * levels range from informational messages to fatal errors; see the
   * documentation for SedMLError for more information.
   *
   * If the file @p filename could not be read, the file-reading error will
   * appear first.  The error code @if clike (a value drawn from the enumeration
   * #XMLErrorCode_t)@endif@~ can provide a clue about what happened.  For example,
   * a file might be unreadable (either because it does not actually exist
   * or because the user does not have the necessary access priviledges to
   * read it) or some sort of file operation error may have been reported
   * by the underlying operating system.  Callers can check for these
   * situations using a program fragment such as the following:
   * @if clike
 @verbatim
 SedMLReader* reader = new SedMLReader();
 SedMLDocument* doc  = reader.readSedML(filename);
 
 if (doc->getNumErrors() > 0)
 {
   if (doc->getError(0)->getErrorId() == XMLError::FileUnreadable)
   {
     // Handle case of unreadable file here.
   } 
   else if (doc->getError(0)->getErrorId() == XMLError::FileOperationError)
   {
     // Handle case of other file operation error here.
   }
   else
   {
     // Handle other cases -- see error codes defined in XMLErrorCode_t
     // for other possible cases to check.
   }
 }
 @endverbatim
 @endif@if java
 @verbatim
 SedMLReader reader = new SedMLReader();
 SedMLDocument doc  = reader.readSedMLFromFile(filename);
 
 if (doc.getNumErrors() > 0)
 {
     if (doc.getError(0).getErrorId() == libsbmlConstants.XMLFileUnreadable)
     {
         // Handle case of unreadable file here.
     } 
     else if (doc.getError(0).getErrorId() == libsbmlConstants.XMLFileOperationError)
     {
         // Handle case of other file operation error here.
     }
     else
     {
         // Handle other error cases.
     }
 }
 @endverbatim
 @endif@if python
 @verbatim
 reader = SedMLReader()
 doc    = reader.readSedMLFromFile(filename)
 
 if doc.getNumErrors() > 0:
   if doc.getError(0).getErrorId() == libsbml.XMLFileUnreadable:
     # Handle case of unreadable file here.
   elif doc.getError(0).getErrorId() == libsbml.XMLFileOperationError:
     # Handle case of other file error here.
   else:
     # Handle other error cases here.
   
 @endverbatim
 @endif@~
   *
   * If the given filename ends with the suffix @c ".gz" (for example, @c
   * "myfile.xml.gz"), the file is assumed to be compressed in @em gzip
   * format and will be automatically decompressed upon reading.
   * Similarly, if the given filename ends with @c ".zip" or @c ".bz2", the
   * file is assumed to be compressed in @em zip or @em bzip2 format
   * (respectively).  Files whose names lack these suffixes will be read
   * uncompressed.  Note that if the file is in @em zip format but the
   * archive contains more than one file, only the first file in the
   * archive will be read and the rest ignored.
   *
   * @htmlinclude note-reading-zipped-files.html
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the SedMLDocument created from the SedML content.
   *
   * @note LibSedML versions 2.x and later versions behave differently in
   * error handling in several respects.  One difference is how early some
   * errors are caught and whether libSedML continues processing a file in
   * the face of some early errors.  In general, libSedML versions after 2.x
   * stop parsing SedML inputs sooner than libSedML version 2.x in the face
   * of XML errors, because the errors may invalidate any further SedML
   * content.  For example, a missing XML declaration at the beginning of
   * the file was ignored by libSedML 2.x but in version 3.x and later, it
   * will cause libSedML to stop parsing the rest of the input altogether.
   * While this behavior may seem more severe and intolerant, it was
   * necessary in order to provide uniform behavior regardless of which
   * underlying XML parser (Expat, Xerces, libxml2) is being used by
   * libSedML.  The XML parsers themselves behave differently in their error
   * reporting, and sometimes libSedML has to resort to the lowest common
   * denominator.
   *
   * @see SedMLError
   * @see SedMLDocument
   */
  SedMLDocument* readSedMLFromFile (const std::string& filename);


  /**
   * Reads an SedML document from the given XML string.
   *
   * This method is flexible with respect to the presence of an XML
   * declaration at the beginning of the string.  In particular, if the
   * string in @p xml does not begin with the XML declaration
   * <code>&lt;?xml version='1.0' encoding='UTF-8'?&gt;</code>, then this
   * method will automatically prepend the declaration to @p xml.
   *
   * This method will log a fatal error if the content given in the
   * parameter @p xml is not SedML.  See the method documentation for
   * SedMLReader::readSedML(@if java String filename@endif)
   * for an example of code for testing the returned error code.
   *
   * @param xml a string containing a full SedML model
   *
   * @return a pointer to the SedMLDocument created from the SedML content.
   *
   * @see SedMLReader::readSedML(@if java String filename@endif)
   */
  SedMLDocument* readSedMLFromString (const std::string& xml);


  /**
   * Static method; returns @c true if this copy of libSedML supports
   * <i>gzip</I> and <i>zip</i> format compression.
   *
   * @return @c true if libSedML has been linked with the <i>zlib</i>
   * library, @c false otherwise.
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSedML will contain two variants.  One
   * will be a static method on the class (i.e., SedMLReader), and the other
   * will be a standalone top-level function with the name
   * SedMLReader_hasZlib(). They are functionally identical. @endif@~
   *
   * @see @if clike hasBzip2() @else SedMLReader::hasBzip2() @endif@~
   */
  static bool hasZlib();


  /**
   * Static method; returns @c true if this copy of libSedML supports
   * <i>bzip2</i> format compression.
   *
   * @return @c true if libSedML is linked with the <i>bzip2</i>
   * libraries, @c false otherwise.
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSedML will contain two variants.  One
   * will be a static method on the class (i.e., SedMLReader), and the other
   * will be a standalone top-level function with the name
   * SedMLReader_hasBzip2(). They are functionally identical. @endif@~
   *
   * @see @if clike hasZlib() @else SedMLReader::hasZlib() @endif@~
   */
  static bool hasBzip2();


protected:
  /** @cond doxygen-libsbml-internal */

  /**
   * Used by readSedML() and readSedMLFromString().
   *
   * @if notcpp @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  SedMLDocument* readInternal (const char* content, bool isFile = true);

  /** @endcond */
};

LIBSEDML_CPP_NAMESPACE_END

#endif /* __cplusplus */

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


#ifndef SWIG


/**
 * Creates a new SedMLReader and returns it.  By default XML Schema
 * validation is off.
 */
LIBSEDML_EXTERN
SedMLReader_t *
SedMLReader_create (void);

/**
 * Frees the given SedMLReader.
 */
LIBSEDML_EXTERN
void
SedMLReader_free (SedMLReader_t *sr);


/**
 * Reads an SedML document from the given file.  If filename does not exist
 * or is not an SedML file, an error will be logged.  Errors can be
 * identified by their unique ids, e.g.:
 *
 * <code>
 *   SedMLReader_t   *sr;\n
 *   SedMLDocument_t *d;
 *
 *   sr = SedMLReader_create();
 *
 *   d = SedMLReader_readSedML(reader, filename);
 *
 *   if (SedMLDocument_getNumErrors(d) > 0)\n
 *   {\n
 *     if (XMLError_getId(SedMLDocument_getError(d, 0))
 *                                           == SedML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedMLDocument_getError(d, 0))
 *                                           == SedML_READ_ERROR_NOT_SedML)\n
 *   }\n
 * </code>
 *
 * If the given filename ends with the suffix @c ".gz" (for example, @c
 * "myfile.xml.gz"), the file is assumed to be compressed in @em gzip
 * format and will be automatically decompressed upon reading.
 * Similarly, if the given filename ends with @c ".zip" or @c ".bz2", the
 * file is assumed to be compressed in @em zip or @em bzip2 format
 * (respectively).  Files whose names lack these suffixes will be read
 * uncompressed.  Note that if the file is in @em zip format but the
 * archive contains more than one file, only the first file in the
 * archive will be read and the rest ignored.
 *
 * @note LibSedML versions 2.x and 3.x behave differently in error
 * handling in several respects.  One difference is how early some errors
 * are caught and whether libSedML continues processing a file in the face
 * of some early errors.  In general, libSedML 3.x stops parsing SedML
 * inputs sooner than libSedML 2.x in the face of XML errors because the
 * errors may invalidate any further SedML content.  For example, a
 * missing XML declaration at the beginning of the file was ignored by
 * libSedML 2.x but in version 3.x, it will cause libSedML to stop parsing
 * the rest of the input altogether.  While this behavior may seem more
 * severe and intolerant, it was necessary in order to provide uniform
 * behavior regardless of which underlying XML parser (Expat, Xerces,
 * libxml2) is being used by libSedML.  The XML parsers themselves behave
 * differently in their error reporting, and sometimes libSedML has to
 * resort to the lowest common denominator.
 *
 * @htmlinclude note-reading-zipped-files.html
 *
 * @return a pointer to the SedMLDocument read.
 */
LIBSEDML_EXTERN
SedMLDocument_t *
SedMLReader_readSedML (SedMLReader_t *sr, const char *filename);

LIBSEDML_EXTERN
SedMLDocument_t *
SedMLReader_readSedMLFromFile (SedMLReader_t *sr, const char *filename);

/**
 * Reads an SedML document from the given XML string.
 *
 * If the string does not begin with XML declaration:
 *
 *   <?xml version='1.0' encoding='UTF-8'?>
 *
 * it will be prepended.
 *
 * This method will log a fatal error if the XML string is not SedML.  See
 * the method documentation for readSedML(filename) for example error
 * checking code.
 *
 * @return a pointer to the SedMLDocument read.
 */
LIBSEDML_EXTERN
SedMLDocument_t *
SedMLReader_readSedMLFromString (SedMLReader_t *sr, const char *xml);


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * underlying libSedML is linked with..
 *
 * @return @c non-zero if libSedML is linked with zlib, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedMLReader_hasZlib ();


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSedML is linked with bzip2.
 *
 * @return @c non-zero if libSedML is linked with bzip2, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedMLReader_hasBzip2 ();

#endif  /* !SWIG */


/**
 * Reads an SedML document from the given file @p filename.
 *
 * If @p filename does not exist, or it is not an SedML file, an error will
 * be logged in the error log of the SedMLDocument object returned by this
 * method.  Calling programs can inspect this error log to determine
 * the nature of the problem.  Please refer to the definition of
 * SedMLDocument for more information about the error reporting mechanism.
 *
 * @return a pointer to the SedMLDocument read.
 */
LIBSEDML_EXTERN
SedMLDocument_t *
readSedML (const char *filename);


LIBSEDML_EXTERN
SedMLDocument_t *
readSedMLFromFile (const char *filename);


/**
 * Reads an SedML document from a string assumed to be in XML format.
 *
 * If the string does not begin with XML declaration,
 *@verbatim
<?xml version='1.0' encoding='UTF-8'?>
@endverbatim
 *
 * an XML declaration string will be prepended.
 *
 * This method will report an error if the given string @p xml is not SedML.
 * The error will be logged in the error log of the SedMLDocument object
 * returned by this method.  Calling programs can inspect this error log to
 * determine the nature of the problem.  Please refer to the definition of
 * SedMLDocument for more information about the error reporting mechanism.
 *
 * @return a pointer to the SedMLDocument read.
 */
LIBSEDML_EXTERN
SedMLDocument_t *
readSedMLFromString (const char *xml);


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* SedMLReader_h */
