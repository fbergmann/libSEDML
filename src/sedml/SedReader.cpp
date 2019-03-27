/**
 * @file SedReader.cpp
 * @brief Implementation of the SedReader class.
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

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

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
 * If the filename ends with @em .gz, the file will be read as a @em gzip file.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * read as a @em zip or @em bzip2 file, respectively. Otherwise, the fill will be
 * read as an uncompressed file.
 * If the filename ends with @em .zip, only the first file in the archive will
 * be read if the zip archive contains two or more files.
 *
 * To read a gzip/zip file, underlying libSEDML needs to be linked with zlib
 * at compile time. Also, underlying libSEDML needs to be linked with bzip2 
 * to read a bzip2 file. File unreadable error will be logged if a compressed 
 * file name is given and underlying libSEDML is not linked with the corresponding 
 * required library.
 * SedReader::hasZlib() and SedReader::hasBzip2() can be used to check 
 * whether libSEDML is linked with each library.
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
 * libSEDML is linked with zlib.
 *
 * @return @c true if libSEDML is linked with zlib, @c false otherwise.
 */
bool 
SedReader::hasZlib() 
{
  return LIBSBML_CPP_NAMESPACE ::hasZlib();
}


/*
 * Predicate returning @c true if
 * libSEDML is linked with bzip2.
 *
 * @return @c true if libSEDML is linked with bzip2, @c false otherwise.
 */
bool 
SedReader::hasBzip2() 
{
  return LIBSBML_CPP_NAMESPACE ::hasBzip2();
}


/** @cond doxygenLibsedmlInternal */
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


/** @cond doxygenLibsedmlInternal */
/*
 * Used by readSedML() and readSedMLFromString().
 */
SedDocument*
SedReader::readInternal (const char* content, bool isFile)
{
  SedDocument* d = new SedDocument();

  if (isFile && content != NULL && (util_file_exists(content) == false))
  {
    d->getErrorLog()->logError(XMLFileUnreadable);
  }
  else 
  {
    XMLInputStream stream(content, isFile, "", d->getErrorLog());

    if (stream.peek().isStart() && stream.peek().getName() != "sedML")
    {
      // the root element ought to be an sedml element. 
      d->getErrorLog()->logError(SedNotSchemaConformant);
	  return d;
    }
	
    d->read(stream);
    
    if (stream.isError())
    {
      // If we encountered an error, some parsers will report it sooner
      // than others.  Unfortunately, those that fail sooner do it in an
      // opaque call, so we can't change the behavior.  Since we don't want
      // different parsers to report different validation errors, we bring
      // all parsers back to the same point.

      for (unsigned int i = 0; i < d->getNumErrors(); ++i)      
      {
        if (isCriticalError(d->getError(i)->getErrorId()))
        {
          // If we find even one critical error, all other errors are
          // suspect and may be bogus.  Remove them.

          for (int n = (int)d->getNumErrors()-1; n >= 0; --n)
            if (!isCriticalError(d->getError((unsigned int)n)->getErrorId()))
            {
              d->getErrorLog()->remove(d->getError((unsigned int)n)->getErrorId());
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


#endif /* __cplusplus */
/** @cond doxygenIgnored */
LIBSEDML_EXTERN
SedReader_t *
SedReader_create ()
{
  return new (nothrow) SedReader;
}


LIBSEDML_EXTERN
void
SedReader_free (SedReader_t *sr)
{
  delete sr;
}


LIBSEDML_EXTERN
SedDocument_t *
SedReader_readSedML (SedReader_t *sr, const char *filename)
{
  if (sr != NULL)
    return (filename != NULL) ? sr->readSedML(filename) : sr->readSedML("");
  else
    return NULL;
}


LIBSEDML_EXTERN
SedDocument_t *
SedReader_readSedMLFromFile (SedReader_t *sr, const char *filename)
{
  if (sr != NULL)
    return (filename != NULL) ? sr->readSedML(filename) : sr->readSedML("");
  else
    return NULL;
}


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


LIBSEDML_EXTERN
int
SedReader_hasZlib (void)
{
  return static_cast<int>( SedReader::hasZlib() );
}


LIBSEDML_EXTERN
int
SedReader_hasBzip2 (void)
{
  return static_cast<int>( SedReader::hasBzip2() );
}


LIBSEDML_EXTERN
SedDocument_t *
readSedML (const char *filename)
{
  SedReader sr;
  return (filename != NULL) ? sr.readSedML(filename) : sr.readSedML("");
}


LIBSEDML_EXTERN
SedDocument_t *
readSedMLFromFile (const char *filename)
{
  SedReader sr;
  return (filename != NULL) ? sr.readSedML(filename) : sr.readSedML("");
}


LIBSEDML_EXTERN
SedDocument_t *
readSedMLFromString (const char *xml)
{
  SedReader sr;
  return (xml != NULL) ? sr.readSedMLFromString(xml) : sr.readSedMLFromString("");
}

LIBSEDML_CPP_NAMESPACE_END
/** @endcond */

