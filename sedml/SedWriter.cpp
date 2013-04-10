/**
 * @file    SedWriter.cpp
 * @brief   Writes an Sed Document to file or in-memory string
 * @author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSed.  Please visit http://sbml.org for more
 * information about Sed, and the latest version of libSed.
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

#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>

#include <sedml/common/common.h>
#include <sbml/xml/XMLOutputStream.h>

#include <sedml/SedError.h>
#include <sedml/SedErrorLog.h>
#include <sedml/SedDocument.h>
#include <sedml/SedWriter.h>

#include <sbml/compress/CompressCommon.h>
#include <sbml/compress/OutputCompressor.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

/*
 * Creates a new SedWriter.
 */
SedWriter::SedWriter ()
{
}


/*
 * Destroys this SedWriter.
 */
SedWriter::~SedWriter ()
{
}


/*
 * Sets the name of this program. i.\ e.\ the one about to write out the
 * SedDocument.  If the program name and version are set
 * (setProgramVersion()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libsbml version <libsbml version>. -->
 */
int
SedWriter::setProgramName (const std::string& name)
{
  if (&(name) == NULL)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else  
  {
    mProgramName = name;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the version of this program. i.\ e.\ the one about to write out the
 * SedDocument.  If the program version and name are set
 * (setProgramName()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libsbml version <libsbml version>. -->
 */
int
SedWriter::setProgramVersion (const std::string& version)
{
  if (&(version) == NULL)
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else  
  {
    mProgramVersion = version;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Writes the given Sed document to filename.
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 * If the filename ends with @em .zip, a filename that will be added to the
 * zip archive file will end with @em .xml or @em .sbml. For example, the filename
 * in the zip archive will be @em test.xml if the given filename is @em test.xml.zip
 * or @em test.zip. Also, the filename in the archive will be @em test.sbml if the
 * given filename is @em test.sbml.zip.
 *
 * @note To create a gzip/zip file, underlying libSed needs to be linked with zlib at 
 * compile time. Also, underlying libSed needs to be linked with bzip2 to create a 
 * bzip2 file.
 * File unwritable error will be logged and @c false will be returned if a compressed 
 * file name is given and underlying libSed is not linked with the corresponding 
 * required library.
 * SedWriter::hasZlib() and SedWriter::hasBzip2() can be used to check whether
 * underlying libSed is linked with the library.
 *
 * @return true on success and false if the filename could not be opened
 * for writing.
 */
bool
SedWriter::writeSedML (const SedDocument* d, const std::string& filename)
{
  std::ostream* stream = NULL;

  try
  {
    // open an uncompressed XML file.
    if ( string::npos != filename.find(".xml", filename.length() - 4) )
    {
      stream = new(std::nothrow) std::ofstream(filename.c_str());
    }
    // open a gzip file
    else if ( string::npos != filename.find(".gz", filename.length() - 3) )
    {
     stream = OutputCompressor::openGzipOStream(filename);
    }
    // open a bz2 file
    else if ( string::npos != filename.find(".bz2", filename.length() - 4) )
    {
      stream = OutputCompressor::openBzip2OStream(filename);
    }
    // open a zip file
    else if ( string::npos != filename.find(".zip", filename.length() - 4) )
    {
      std::string filenameinzip = filename.substr(0, filename.length() - 4);
  
      if ( ( string::npos == filenameinzip.find(".xml",  filenameinzip.length() - 4) ) &&
           ( string::npos == filenameinzip.find(".sbml", filenameinzip.length() - 5) )
         )
      {
        filenameinzip += ".xml";
      }


#if defined(WIN32) && !defined(CYGWIN)
      char sepr = '\\';
#else
      char sepr = '/';
#endif
      size_t spos = filenameinzip.rfind(sepr, filenameinzip.length() - 1);
      if( spos != string::npos )
      {
        filenameinzip = filenameinzip.substr(spos + 1, filenameinzip.length() - 1);
      }

      
      stream = OutputCompressor::openZipOStream(filename, filenameinzip);
    }
    else
    {
      stream = new(std::nothrow) std::ofstream(filename.c_str());
    }
  }
  catch ( ZlibNotLinked& )
  {
    // libSed is not linked with zlib.
    XMLErrorLog *log = (const_cast<SedDocument *>(d))->getErrorLog();
    std::ostringstream oss;
    oss << "Tried to write " << filename << ". Writing a gzip/zip file is not enabled because "
        << "underlying libSed is not linked with zlib."; 
    log->add(XMLError( XMLFileUnwritable, oss.str(), 0, 0) );
    return false;
  } 
  catch ( Bzip2NotLinked& )
  {
    // libSed is not linked with bzip2.
    XMLErrorLog *log = (const_cast<SedDocument *>(d))->getErrorLog();
    std::ostringstream oss;
    oss << "Tried to write " << filename << ". Writing a bzip2 file is not enabled because "
        << "underlying libSed is not linked with bzip2."; 
    log->add(XMLError( XMLFileUnwritable, oss.str(), 0, 0) );
    return false;
  } 


  if ( stream == NULL || stream->fail() || stream->bad())
  {
    SedErrorLog *log = (const_cast<SedDocument *>(d))->getErrorLog();
    log->logError(XMLFileUnwritable);
    return false;
  }

   bool result = writeSedML(d, *stream);
   delete stream;

   return result;

}


/*
 * Writes the given Sed document to the output stream.
 *
 * @return true on success and false if one of the underlying parser
 * components fail (rare).
 */
bool
SedWriter::writeSedML (const SedDocument* d, std::ostream& stream)
{
  bool result = false;

  try
  {
    stream.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    XMLOutputStream xos(stream, "UTF-8", true, mProgramName, 
                                               mProgramVersion);
    d->write(xos);
    stream << endl;

    result = true;
  }
  catch (ios_base::failure&)
  {
    SedErrorLog *log = (const_cast<SedDocument *>(d))->getErrorLog();
    log->logError(XMLFileOperationError);
  }

  return result;
}


/** @cond doxygen-libsbml-internal */
/*
 * Writes the given Sed document to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @return the string on success and 0 if one of the underlying parser
 * components fail (rare).
 */
LIBSEDML_EXTERN
char*
SedWriter::writeToString (const SedDocument* d)
{
  ostringstream stream;
  writeSedML(d, stream);

  return safe_strdup( stream.str().c_str() );
}


LIBSEDML_EXTERN
char*
SedWriter::writeSedMLToString (const SedDocument* d)
{
  return writeToString(d);
}
/** @endcond */


LIBSEDML_EXTERN
bool
SedWriter::writeSedMLToFile (const SedDocument* d, const std::string& filename)
{
  return writeSedML(d, filename);
}


/*
 * Predicate returning @c true if
 * underlying libSed is linked with zlib.
 *
 * @return @c true if libSed is linked with zlib, @c false otherwise.
 */
bool 
SedWriter::hasZlib() 
{
  return LIBSEDML_CPP_NAMESPACE ::hasZlib();
}


/*
 * Predicate returning @c true if
 * underlying libSed is linked with bzip2.
 *
 * @return @c true if libSed is linked with bzip2, @c false otherwise.
 */
bool 
SedWriter::hasBzip2() 
{
  return LIBSEDML_CPP_NAMESPACE ::hasBzip2();
}



/**
 * Creates a new SedWriter and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedWriter_t *
SedWriter_create ()
{
  return new(nothrow) SedWriter;
}


/**
 * Frees the given SedWriter.
 */
LIBSEDML_EXTERN
void
SedWriter_free (SedWriter_t *sw)
{
  delete sw;
}


/**
 * Sets the name of this program. i.\ e.\  the one about to write out the
 * SedDocument.  If the program name and version are set
 * (setProgramVersion()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libsbml version <libsbml version>. -->
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
 */
LIBSEDML_EXTERN
int
SedWriter_setProgramName (SedWriter_t *sw, const char *name)
{
  if (sw != NULL)
    return (name == NULL) ? sw->setProgramName("") : sw->setProgramName(name);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Sets the version of this program. i.\ e.\ the one about to write out the
 * SedDocument.  If the program version and name are set
 * (setProgramName()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libsbml version <libsbml version>. -->
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif@~ The possible values
 * returned by this function are:
 * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
 */
LIBSEDML_EXTERN
int
SedWriter_setProgramVersion (SedWriter_t *sw, const char *version)
{
  if (sw != NULL)
    return (version == NULL) ? sw->setProgramVersion("") :
                             sw->setProgramVersion(version);
  else
    return LIBSEDML_INVALID_OBJECT;
}


/**
 * Writes the given Sed document to filename.
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 * If the filename ends with @em .zip, a filename that will be added to the
 * zip archive file will end with @em .xml or @em .sbml. For example, the filename
 * in the zip archive will be @em test.xml if the given filename is @em test.xml.zip
 * or @em test.zip. Also, the filename in the archive will be @em test.sbml if the
 * given filename is @em test.sbml.zip.
 *
 * @note To create a gzip/zip file, libSed needs to be linked with zlib at 
 * compile time. Also, libSed needs to be linked with bzip2 to create a bzip2 file.
 * File unwritable error will be logged and @c zero will be returned if a compressed 
 * file name is given and libSed is not linked with the required library.
 * SedWriter_hasZlib() and SedWriter_hasBzip2() can be used to check whether
 * libSed was linked with the library at compile time.
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 */
LIBSEDML_EXTERN
int
SedWriter_writeSedML ( SedWriter_t         *sw,
                       const SedDocument_t *d,
                       const char           *filename )
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return (filename != NULL) ? 
      static_cast<int>( sw->writeSedML(d, filename) ) : 0;
}


/**
 * Writes the given Sed document to filename.
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 * If the filename ends with @em .zip, a filename that will be added to the
 * zip archive file will end with @em .xml or @em .sbml. For example, the filename
 * in the zip archive will be @em test.xml if the given filename is @em test.xml.zip
 * or @em test.zip. Also, the filename in the archive will be @em test.sbml if the
 * given filename is @em test.sbml.zip.
 *
 * @note To create a gzip/zip file, libSed needs to be linked with zlib at 
 * compile time. Also, libSed needs to be linked with bzip2 to create a bzip2 file.
 * File unwritable error will be logged and @c zero will be returned if a compressed 
 * file name is given and libSed is not linked with the required library.
 * SedWriter_hasZlib() and SedWriter_hasBzip2() can be used to check whether
 * libSed was linked with the library at compile time.
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 */
LIBSEDML_EXTERN
int
SedWriter_writeSedMLToFile ( SedWriter_t         *sw,
                       const SedDocument_t *d,
                       const char           *filename )
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return (filename != NULL) ? 
      static_cast<int>( sw->writeSedML(d, filename) ) : 0;
}


/**
 * Writes the given Sed document to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @return the string on success and NULL if one of the underlying parser
 * components fail (rare).
 */
LIBSEDML_EXTERN
char *
SedWriter_writeSedMLToString (SedWriter_t *sw, const SedDocument_t *d)
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return sw->writeToString(d);
}


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSed is linked with zlib at compile time.
 *
 * @return @c non-zero if zlib is linked, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedWriter_hasZlib ()
{
  return static_cast<int>( SedWriter::hasZlib() );
}


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSed is linked with bzip2 at compile time.
 *
 * @return @c non-zero if bzip2 is linked, @c zero otherwise.
 */
LIBSEDML_EXTERN
int
SedWriter_hasBzip2 ()
{
   return static_cast<int>( SedWriter::hasBzip2() );
}


/**
 * Writes the given Sed document to filename.  This convenience function
 * is functionally equivalent to:
 *
 *   SedWriter_writeSedML(SedWriter_create(), d, filename);
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 */
LIBSEDML_EXTERN
int
writeSedML (const SedDocument_t *d, const char *filename)
{
  SedWriter sw;
  if (d == NULL || filename == NULL)
    return 0;
  else
    return static_cast<int>( sw.writeSedML(d, filename) );
}


/**
 * Writes the given Sed document to filename.  This convenience function
 * is functionally equivalent to:
 *
 *   SedWriter_writeSedMLToFile(SedWriter_create(), d, filename);
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 */
LIBSEDML_EXTERN
int
writeSedMLToFile (const SedDocument_t *d, const char *filename)
{
  SedWriter sw;
  if (d == NULL || filename == NULL)
    return 0;
  else
    return static_cast<int>( sw.writeSedML(d, filename) );
}


/**
 * Writes the given Sed document to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.  This convenience function is
 * functionally equivalent to:
 *
 *   SedWriter_writeSedMLToString(SedWriter_create(), d);
 *
 * @return the string on success and NULL if one of the underlying parser
 * components fail (rare).
 */
LIBSEDML_EXTERN
char *
writeSedMLToString (const SedDocument_t *d)
{
  SedWriter sw;
  if (d == NULL)
    return NULL;
  else
    return sw.writeToString(d);
}

LIBSEDML_CPP_NAMESPACE_END

