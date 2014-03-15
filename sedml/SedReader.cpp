/**
 * @file    SedReader.cpp
 * @brief   Reads an Sed Document into memory
 * 
 * <!--------------------------------------------------------------------------
 *
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on 
 * github: https://github.com/fbergmann/libSEDML/
 * 
 * 
 * Copyright (c) 2013-2014, Frank T. Bergmann  
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * ---------------------------------------------------------------------- -->
 */

#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedErrorLog.h>
#include <sedml/SedVisitor.h>
#include <sedml/SedDocument.h>
#include <sedml/SedError.h>
#include <sedml/SedReader.h>

#include <sbml/compress/CompressCommon.h>
#include <sbml/compress/InputDecompressor.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

/*
 * Creates a new SedReader and returns it. 
 */
SedReader::SedReader ()
{
}


/*
 * Destorys this SedReader.
 */
SedReader::~SedReader ()
{
}


/*
 * Reads an Sed document from the given file.  If filename does not exist
 * or is not an Sed file, an error will be logged.  Errors can be
 * identified by their unique ids, e.g.:
 *
 * <code>
 *   SedDocument* d = reader.readSedML(filename);
 *
 *   if (d->getNumErrors() > 0)\n
 *   {\n
 *     if (d->getError(0)->getId() ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (d->getError(0)->getId() ==SEDML_READ_ERROR_NOT_Sed)\n
 *   }\n
 * </code>
 *
 * If the filename ends with @em .gz, the file will be read as a @em gzip file.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * read as a @em zip or @em bzip2 file, respectively. Otherwise, the fill will be
 * read as an uncompressed file.
 * If the filename ends with @em .zip, only the first file in the archive will
 * be read if the zip archive contains two or more files.
 *
 * To read a gzip/zip file, underlying libSed needs to be linked with zlib
 * at compile time. Also, underlying libSed needs to be linked with bzip2 
 * to read a bzip2 file. File unreadable error will be logged if a compressed 
 * file name is given and underlying libSed is not linked with the corresponding 
 * required library.
 * SedReader::hasZlib() and SedReader::hasBzip2() can be used to check 
 * whether libSed is linked with each library.
 * 
 * @return a pointer to the SedDocument read.
 */
SedDocument*
SedReader::readSedML (const std::string& filename)
{
  return readInternal(filename.c_str(), true);
}


/*
 * Reads an Sed document from the given filename.
 */
SedDocument*
SedReader::readSedMLFromFile (const std::string& filename)
{
  return readInternal(filename.c_str(), true);
}


/*
 * Reads an Sed document from the given XML string.
 *
 * If the string does not begin with XML declaration:
 *
 *   <?xml version='1.0' encoding='UTF-8'?>
 *
 * it will be prepended.
 *
 * This method will log a fatal error if the XML string is not Sed.  See
 * the method documentation for readSedML(filename) for example error
 * checking code.
 *
 * @return a pointer to the SedDocument read.
 */
SedDocument*
SedReader::readSedMLFromString (const std::string& xml)
{
  if (&xml == NULL) return NULL;

  const static string dummy_xml ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");  
  
  if (!strncmp(xml.c_str(), dummy_xml.c_str(), 14))
  {
    return readInternal(xml.c_str(), false);
  }
  else
  {
    const std::string temp = (dummy_xml + xml);
    return readInternal(temp.c_str(), false);
  }
  
  
}


/*
 * Predicate returning @c true if
 * libSed is linked with zlib.
 *
 * @return @c true if libSed is linked with zlib, @c false otherwise.
 */
bool 
SedReader::hasZlib() 
{
  return LIBSEDML_CPP_NAMESPACE ::hasZlib();
}


/*
 * Predicate returning @c true if
 * libSed is linked with bzip2.
 *
 * @return @c true if libSed is linked with bzip2, @c false otherwise.
 */
bool 
SedReader::hasBzip2() 
{
  return LIBSEDML_CPP_NAMESPACE ::hasBzip2();
}


/** @cond doxygen-libsbml-internal */
static bool
isCriticalError(const unsigned int errorId)
{
  switch (errorId)
  {
  case InternalXMLParserError:
  case UnrecognizedXMLParserCode:
  case XMLTranscoderError:
  case BadlyFormedXML:
  case InvalidXMLConstruct:
  case UnclosedXMLToken:
  case XMLTagMismatch:
  case BadXMLPrefix:
  case MissingXMLAttributeValue:
  case BadXMLComment:
  case XMLUnexpectedEOF:
  case UninterpretableXMLContent:
  case BadXMLDocumentStructure:
  case InvalidAfterXMLContent:
  case XMLExpectedQuotedString:
  case XMLEmptyValueNotPermitted:
  case MissingXMLElements:
  case BadXMLDeclLocation:
    return true;

  default:
    return false;
  }
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Used by readSedML() and readSedMLFromString().
 */
SedDocument*
SedReader::readInternal (const char* content, bool isFile)
{
  SedDocument* d = new SedDocument();
  //if (isFile) {
  //  d->setURI(content);
  //}

  if (isFile && content != NULL && (util_file_exists(content) == false))
  {
    d->getErrorLog()->logError(XMLFileUnreadable);
  }
  else
  {
    XMLInputStream stream(content, isFile, "", d->getErrorLog());

    d->read(stream);
    
    if (stream.isError())
    {
      // If we encountered an error, some parsers will report it sooner
      // than others.  Unfortunately, those that fail sooner do it in an
      // opaque call, so we can't change the behavior.  Since we don't want
      // different parsers to report different validation errors, we bring
      // all parsers back to the same point.


      for (unsigned int i = 0; i < d->getErrorLog()->getNumErrors(); ++i)      
      {
        if (isCriticalError(d->getErrorLog()->getError(i)->getErrorId()))
        {
          // If we find even one critical error, all other errors are
          // suspect and may be bogus.  Remove them.

          for (int n = d->getErrorLog()->getNumErrors()-1; n >= 0; n--)      
            if (!isCriticalError(d->getErrorLog()->getError(n)->getErrorId()))
            {
              d->getErrorLog()->remove(d->getErrorLog()->getError(n)->getErrorId());
            }

          break;
        }
      }
    }
    else
    {
      // Low-level XML errors will have been caught in the first read,
      // before we even attempt to interpret the content as Sed.  Here
      // we want to start checking some basic Sed-level errors.

      if (stream.getEncoding() == "")
      {
        d->getErrorLog()->logError(MissingXMLEncoding);
      }
      else if (strcmp_insensitive(stream.getEncoding().c_str(), "UTF-8") != 0)
      {
        d->getErrorLog()->logError(SedNotUTF8);
      }

      if (stream.getVersion() == "")
      {
        d->getErrorLog()->logError(BadXMLDecl);
      }
      else if (strcmp_insensitive(stream.getVersion().c_str(), "1.0") != 0)
      {
        d->getErrorLog()->logError(BadXMLDecl);
      }
    }
  }
  return d;
}
/** @endcond */


/** @cond doxygen-c-only */


/**
 * Creates a new SedReader and returns it. 
 */
LIBSEDML_EXTERN
SedReader_t *
SedReader_create ()
{
  return new (nothrow) SedReader;
}


/**
 * Frees the given SedReader.
 */
LIBSEDML_EXTERN
void
SedReader_free (SedReader_t *sr)
{
  delete sr;
}


/**
 * Reads an Sed document from the given file.  If filename does not exist
 * or is not an Sed file, an error will be logged.  Errors can be
 * identified by their unique ids, e.g.:
 *
 * <code>
 *   SedReader_t   *sr;\n
 *   SedDocument_t *d;
 *
 *   sr = SedReader_create();
 *
 *   d = SedReader_readSedML(reader, filename);
 *
 *   if (SedDocument_getNumErrors(d) > 0)\n
 *   {\n
 *     if (XMLError_getId(SedDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_NOT_Sed)\n
 *   }\n
 * </code>
 *
 * @return a pointer to the SedDocument read.
 */
LIBSEDML_EXTERN
SedDocument_t *
SedReader_readSedML (SedReader_t *sr, const char *filename)
{
  if (sr != NULL)
    return (filename != NULL) ? sr->readSedML(filename) : sr->readSedML("");
  else
    return NULL;
}


/**
 * Reads an Sed document from the given file.  If filename does not exist
 * or is not an Sed file, an error will be logged.  Errors can be
 * identified by their unique ids, e.g.:
 *
 * <code>
 *   SedReader_t   *sr;\n
 *   SedDocument_t *d;
 *
 *   sr = SedReader_create();
 *
 *   d = SedReader_readSedML(reader, filename);
 *
 *   if (SedDocument_getNumErrors(d) > 0)\n
 *   {\n
 *     if (XMLError_getId(SedDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_NOT_Sed)\n
 *   }\n
 * </code>
 *
 * @return a pointer to the SedDocument read.
 */
LIBSEDML_EXTERN
SedDocument_t *
SedReader_readSedMLFromFile (SedReader_t *sr, const char *filename)
{
  if (sr != NULL)
    return (filename != NULL) ? sr->readSedML(filename) : sr->readSedML("");
  else
    return NULL;
}


/**
 * Reads an Sed document from the given XML string.
 *
 * If the string does not begin with XML declaration:
 *
 *   <?xml version='1.0' encoding='UTF-8'?>
 *
 * it will be prepended.
 *
 * This method will log a fatal error if the XML string is not Sed.  See
 * the method documentation for readSedML(filename) for example error
 * checking code.
 *
 * @return a pointer to the SedDocument read.
 */
LIBSEDML_EXTERN
SedDocument_t *
SedReader_readSedMLFromString (SedReader_t *sr, const char *xml)
{
  if (sr != NULL)
    return (xml != NULL) ? sr->readSedMLFromString(xml) :
                         sr->readSedMLFromString("");
  else
    return NULL;
}


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * underlying libSed is linked with zlib at compile time.
 *
 * @return @c non-zero if libSed is linked with zlib, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedReader_hasZlib (void)
{
  return static_cast<int>( SedReader::hasZlib() );
}


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * underlying libSed is linked with bzip2 at compile time.
 *
 * @return @c non-zero if libSed is linked with bzip2, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedReader_hasBzip2 (void)
{
  return static_cast<int>( SedReader::hasBzip2() );
}


/**
 * Reads an Sed document from the given file.  If filename does not exist
 * or is not an Sed file, an error will be logged.  Errors can be
 * identified by their unique ids, e.g.:
 *
 * <code>
 *   SedReader_t   *sr;\n
 *   SedDocument_t *d;
 *
 *   sr = SedReader_create();
 *
 *   d = SedReader_readSedML(reader, filename);
 *
 *   if (SedDocument_getNumErrors(d) > 0)\n
 *   {\n
 *     if (XMLError_getId(SedDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_NOT_Sed)\n
 *   }\n
 * </code>
 *
 * If the filename ends with @em .gz, the file will be read as a @em gzip file.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * read as a @em zip or @em bzip2 file, respectively. Otherwise, the fill will be
 * read as an uncompressed file.
 * If the filename ends with @em .zip, only the first file in the archive will
 * be read if the zip archive contains two or more files.
 *
 * To read a gzip/zip file, underlying libSed needs to be linked with zlib
 * at compile time. Also, underlying libSed needs to be linked with bzip2 
 * to read a bzip2 file. File unreadable error will be logged if a compressed 
 * file name is given and underlying libSed is not linked with the corresponding 
 * required library.
 * SedReader_hasZlib() and SedReader_hasBzip2() can be used to check 
 * whether libSed is linked with each library.
 *
 * @return a pointer to the SedDocument read.
 */
LIBSEDML_EXTERN
SedDocument_t *
readSedML (const char *filename)
{
  SedReader sr;
  return (filename != NULL) ? sr.readSedML(filename) : sr.readSedML("");
}


/**
 * Reads an Sed document from the given file.  If filename does not exist
 * or is not an Sed file, an error will be logged.  Errors can be
 * identified by their unique ids, e.g.:
 *
 * <code>
 *   SedReader_t   *sr;\n
 *   SedDocument_t *d;
 *
 *   sr = SedReader_create();
 *
 *   d = SedReader_readSedML(reader, filename);
 *
 *   if (SedDocument_getNumErrors(d) > 0)\n
 *   {\n
 *     if (XMLError_getId(SedDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_NOT_Sed)\n
 *   }\n
 * </code>
 *
 * If the filename ends with @em .gz, the file will be read as a @em gzip file.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * read as a @em zip or @em bzip2 file, respectively. Otherwise, the fill will be
 * read as an uncompressed file.
 * If the filename ends with @em .zip, only the first file in the archive will
 * be read if the zip archive contains two or more files.
 *
 * To read a gzip/zip file, underlying libSed needs to be linked with zlib
 * at compile time. Also, underlying libSed needs to be linked with bzip2 
 * to read a bzip2 file. File unreadable error will be logged if a compressed 
 * file name is given and underlying libSed is not linked with the corresponding 
 * required library.
 * SedReader_hasZlib() and SedReader_hasBzip2() can be used to check 
 * whether libSed is linked with each library.
 *
 * @return a pointer to the SedDocument read.
 */
LIBSEDML_EXTERN
SedDocument_t *
readSedMLFromFile (const char *filename)
{
  SedReader sr;
  return (filename != NULL) ? sr.readSedML(filename) : sr.readSedML("");
}


/**
 * Reads an Sed document from the given XML string.
 *
 * If the string does not begin with XML declaration:
 *
 *   <?xml version='1.0' encoding='UTF-8'?>
 *
 * it will be prepended.
 *
 * This method will log a fatal error if the XML string is not Sed.  See
 * the method documentation for readSedML(filename) for example error
 * checking code.
 *
 * @return a pointer to the SedDocument read.
 */
LIBSEDML_EXTERN
SedDocument_t *
readSedMLFromString (const char *xml)
{
  SedReader sr;
  return (xml != NULL) ? sr.readSedMLFromString(xml) : sr.readSedMLFromString("");
}

LIBSEDML_CPP_NAMESPACE_END

/** @endcond */

