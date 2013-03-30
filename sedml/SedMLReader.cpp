/**
 * @file    SedMLReader.cpp
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
 * ---------------------------------------------------------------------- -->*/

#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedMLErrorLog.h>
#include <sedml/SedMLVisitor.h>
#include <sedml/SedMLDocument.h>
#include <sedml/SedMLError.h>
#include <sedml/SedMLReader.h>

#include <sbml/compress/CompressCommon.h>
#include <sbml/compress/InputDecompressor.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

/*
 * Creates a new SedMLReader and returns it. 
 */
SedMLReader::SedMLReader ()
{
}


/*
 * Destorys this SedMLReader.
 */
SedMLReader::~SedMLReader ()
{
}


/*
 * Reads an SedML document from the given file.  If filename does not exist
 * or is not an SedML file, an error will be logged.  Errors can be
 * identified by their unique ids, e.g.:
 *
 * <code>
 *   SedMLDocument* d = reader.readSedML(filename);
 *
 *   if (d->getNumErrors() > 0)\n
 *   {\n
 *     if (d->getError(0)->getId() ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (d->getError(0)->getId() ==SEDML_READ_ERROR_NOT_SedML)\n
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
 * To read a gzip/zip file, underlying libSedML needs to be linked with zlib
 * at compile time. Also, underlying libSedML needs to be linked with bzip2 
 * to read a bzip2 file. File unreadable error will be logged if a compressed 
 * file name is given and underlying libSedML is not linked with the corresponding 
 * required library.
 * SedMLReader::hasZlib() and SedMLReader::hasBzip2() can be used to check 
 * whether libSedML is linked with each library.
 * 
 * @return a pointer to the SedMLDocument read.
 */
SedMLDocument*
SedMLReader::readSedML (const std::string& filename)
{
  return readInternal(filename.c_str(), true);
}


/*
 * Reads an SedML document from the given filename.
 */
SedMLDocument*
SedMLReader::readSedMLFromFile (const std::string& filename)
{
  return readInternal(filename.c_str(), true);
}


/*
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
SedMLDocument*
SedMLReader::readSedMLFromString (const std::string& xml)
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
 * libSedML is linked with zlib.
 *
 * @return @c true if libSedML is linked with zlib, @c false otherwise.
 */
bool 
SedMLReader::hasZlib() 
{
  return LIBSEDML_CPP_NAMESPACE ::hasZlib();
}


/*
 * Predicate returning @c true if
 * libSedML is linked with bzip2.
 *
 * @return @c true if libSedML is linked with bzip2, @c false otherwise.
 */
bool 
SedMLReader::hasBzip2() 
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
SedMLDocument*
SedMLReader::readInternal (const char* content, bool isFile)
{
  SedMLDocument* d = new SedMLDocument();
  if (isFile) {
    d->setLocationURI(string("file:") + content);
  }

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

      d->setModel(NULL);

      for (unsigned int i = 0; i < d->getNumErrors(); ++i)      
      {
        if (isCriticalError(d->getError(i)->getErrorId()))
        {
          // If we find even one critical error, all other errors are
          // suspect and may be bogus.  Remove them.

          for (int n = d->getNumErrors()-1; n >= 0; n--)      
            if (!isCriticalError(d->getError(n)->getErrorId()))
            {
              d->getErrorLog()->remove(d->getError(n)->getErrorId());
            }

          break;
        }
      }
    }
    else
    {
      // Low-level XML errors will have been caught in the first read,
      // before we even attempt to interpret the content as SedML.  Here
      // we want to start checking some basic SedML-level errors.

      if (stream.getEncoding() == "")
      {
        d->getErrorLog()->logError(MissingXMLEncoding);
      }
      else if (strcmp_insensitive(stream.getEncoding().c_str(), "UTF-8") != 0)
      {
        d->getErrorLog()->logError(NotUTF8);
      }

      if (stream.getVersion() == "")
      {
        d->getErrorLog()->logError(BadXMLDecl);
      }
      else if (strcmp_insensitive(stream.getVersion().c_str(), "1.0") != 0)
      {
        d->getErrorLog()->logError(BadXMLDecl);
      }

      if (d->getModel() == NULL)
      {
        d->getErrorLog()->logError(MissingModel, 
                                   d->getLevel(), d->getVersion());
      }
      else if (d->getLevel() == 1)
      {
	// In Level 1, some listOfElements were required.

        if (d->getModel()->getNumCompartments() == 0)
        {
          d->getErrorLog()->logError(NotSchemaConformant,
				     d->getLevel(), d->getVersion(), 
            "An SedML Level 1 model must contain at least one <compartment>.");
        }

        if (d->getVersion() == 1)
        {
          if (d->getModel()->getNumSpecies() == 0)
          {
            d->getErrorLog()->logError(NotSchemaConformant,
				       d->getLevel(), d->getVersion(), 
            "An SedML Level 1 Version 1 model must contain at least one <species>.");
          }
          if (d->getModel()->getNumReactions() == 0)
          {
            d->getErrorLog()->logError(NotSchemaConformant,
				       d->getLevel(), d->getVersion(), 
            "An SedML Level 1 Version 1 model must contain at least one <reaction>.");
          }
        }
      }
    }
  }
  return d;
}
/** @endcond */


/** @cond doxygen-c-only */


/**
 * Creates a new SedMLReader and returns it. 
 */
LIBSEDML_EXTERN
SedMLReader_t *
SedMLReader_create ()
{
  return new (nothrow) SedMLReader;
}


/**
 * Frees the given SedMLReader.
 */
LIBSEDML_EXTERN
void
SedMLReader_free (SedMLReader_t *sr)
{
  delete sr;
}


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
 *                                           ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedMLDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_NOT_SedML)\n
 *   }\n
 * </code>
 *
 * @return a pointer to the SedMLDocument read.
 */
LIBSEDML_EXTERN
SedMLDocument_t *
SedMLReader_readSedML (SedMLReader_t *sr, const char *filename)
{
  if (sr != NULL)
    return (filename != NULL) ? sr->readSedML(filename) : sr->readSedML("");
  else
    return NULL;
}


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
 *                                           ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedMLDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_NOT_SedML)\n
 *   }\n
 * </code>
 *
 * @return a pointer to the SedMLDocument read.
 */
LIBSEDML_EXTERN
SedMLDocument_t *
SedMLReader_readSedMLFromFile (SedMLReader_t *sr, const char *filename)
{
  if (sr != NULL)
    return (filename != NULL) ? sr->readSedML(filename) : sr->readSedML("");
  else
    return NULL;
}


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
SedMLReader_readSedMLFromString (SedMLReader_t *sr, const char *xml)
{
  if (sr != NULL)
    return (xml != NULL) ? sr->readSedMLFromString(xml) :
                         sr->readSedMLFromString("");
  else
    return NULL;
}


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * underlying libSedML is linked with zlib at compile time.
 *
 * @return @c non-zero if libSedML is linked with zlib, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedMLReader_hasZlib (void)
{
  return static_cast<int>( SedMLReader::hasZlib() );
}


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * underlying libSedML is linked with bzip2 at compile time.
 *
 * @return @c non-zero if libSedML is linked with bzip2, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedMLReader_hasBzip2 (void)
{
  return static_cast<int>( SedMLReader::hasBzip2() );
}


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
 *                                           ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedMLDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_NOT_SedML)\n
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
 * To read a gzip/zip file, underlying libSedML needs to be linked with zlib
 * at compile time. Also, underlying libSedML needs to be linked with bzip2 
 * to read a bzip2 file. File unreadable error will be logged if a compressed 
 * file name is given and underlying libSedML is not linked with the corresponding 
 * required library.
 * SedMLReader_hasZlib() and SedMLReader_hasBzip2() can be used to check 
 * whether libSedML is linked with each library.
 *
 * @return a pointer to the SedMLDocument read.
 */
LIBSEDML_EXTERN
SedMLDocument_t *
readSedML (const char *filename)
{
  SedMLReader sr;
  return (filename != NULL) ? sr.readSedML(filename) : sr.readSedML("");
}


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
 *                                           ==SEDML_READ_ERROR_FILE_NOT_FOUND)\n
 *     if (XMLError_getId(SedMLDocument_getError(d, 0))
 *                                           ==SEDML_READ_ERROR_NOT_SedML)\n
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
 * To read a gzip/zip file, underlying libSedML needs to be linked with zlib
 * at compile time. Also, underlying libSedML needs to be linked with bzip2 
 * to read a bzip2 file. File unreadable error will be logged if a compressed 
 * file name is given and underlying libSedML is not linked with the corresponding 
 * required library.
 * SedMLReader_hasZlib() and SedMLReader_hasBzip2() can be used to check 
 * whether libSedML is linked with each library.
 *
 * @return a pointer to the SedMLDocument read.
 */
LIBSEDML_EXTERN
SedMLDocument_t *
readSedMLFromFile (const char *filename)
{
  SedMLReader sr;
  return (filename != NULL) ? sr.readSedML(filename) : sr.readSedML("");
}


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
readSedMLFromString (const char *xml)
{
  SedMLReader sr;
  return (xml != NULL) ? sr.readSedMLFromString(xml) : sr.readSedMLFromString("");
}

LIBSEDML_CPP_NAMESPACE_END

/** @endcond */

