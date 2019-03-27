/**
 * @file SedWriter.cpp
 * @brief Implementation of the SedWriter class.
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

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

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
 *   on yyyy-MM-dd HH:mm with libsedml version <libsedml version>. -->
 */
int
SedWriter::setProgramName (const std::string& name)
{
  mProgramName = name;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the version of this program. i.\ e.\ the one about to write out the
 * SedDocument.  If the program version and name are set
 * (setProgramName()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libsedml version <libsedml version>. -->
 */
int
SedWriter::setProgramVersion (const std::string& version)
{
  mProgramVersion = version;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Writes the given SedDocument to filename.
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 *
 * @note To create a gzip/zip file, underlying libSEDML needs to be linked with zlib at 
 * compile time. Also, underlying libSEDML needs to be linked with bzip2 to create a 
 * bzip2 file.
 * File unwritable error will be logged and @c false will be returned if a compressed 
 * file name is given and underlying libSEDML is not linked with the corresponding 
 * required library.
 * SedWriter::hasZlib() and SedWriter::hasBzip2() can be used to check whether
 * underlying libSEDML is linked with the library.
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
           ( string::npos == filenameinzip.find(".sedml", filenameinzip.length() - 5) )
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
    // libSEDML is not linked with zlib.
    XMLErrorLog *log = (const_cast<SedDocument *>(d))->getErrorLog();
    std::ostringstream oss;
    oss << "Tried to write " << filename << ". Writing a gzip/zip file is not enabled because "
        << "underlying libSEDML is not linked with zlib."; 
    log->add(XMLError( XMLFileUnwritable, oss.str(), 0, 0) );
    return false;
  } 
  catch ( Bzip2NotLinked& )
  {
    // libSEDML is not linked with bzip2.
    XMLErrorLog *log = (const_cast<SedDocument *>(d))->getErrorLog();
    std::ostringstream oss;
    oss << "Tried to write " << filename << ". Writing a bzip2 file is not enabled because "
        << "underlying libSEDML is not linked with bzip2."; 
    log->add(XMLError( XMLFileUnwritable, oss.str(), 0, 0) );
    return false;
  } 


  if ( stream == NULL || stream->fail() || stream->bad())
  {
    SedErrorLog *log = (const_cast<SedDocument *>(d))->getErrorLog();
    log->logError(XMLFileUnwritable);
    delete stream;
    return false;
  }

   bool result = writeSedML(d, *stream);
   delete stream;

   return result;

}


/*
 * Writes the given SedDocument to the output stream.
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


/** @cond doxygenLibsedmlInternal */
/*
 * Writes the given SedDocument to an in-memory string and returns a
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

std::string 
SedWriter::writeSedMLToStdString(const SedDocument* d)
{
  if (d == NULL) return "";
  
  ostringstream stream;
  writeSedML(d, stream);
  return stream.str();
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
 * underlying libSEDML is linked with zlib.
 *
 * @return @c true if libSEDML is linked with zlib, @c false otherwise.
 */
bool 
SedWriter::hasZlib() 
{
  return LIBSBML_CPP_NAMESPACE ::hasZlib();
}


/*
 * Predicate returning @c true if
 * underlying libSEDML is linked with bzip2.
 *
 * @return @c true if libSEDML is linked with bzip2, @c false otherwise.
 */
bool 
SedWriter::hasBzip2() 
{
  return LIBSBML_CPP_NAMESPACE ::hasBzip2();
}


#endif /* __cplusplus */
/** @cond doxygenIgnored */
LIBSEDML_EXTERN
SedWriter_t *
SedWriter_create ()
{
  return new(nothrow) SedWriter;
}


LIBSEDML_EXTERN
void
SedWriter_free (SedWriter_t *sw)
{
  delete sw;
}


LIBSEDML_EXTERN
int
SedWriter_setProgramName (SedWriter_t *sw, const char *name)
{
  if (sw != NULL)
    return (name == NULL) ? sw->setProgramName("") : sw->setProgramName(name);
  else
    return LIBSEDML_INVALID_OBJECT;
}


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


LIBSEDML_EXTERN
char *
SedWriter_writeSedMLToString (SedWriter_t *sw, const SedDocument_t *d)
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return sw->writeToString(d);
}


LIBSEDML_EXTERN
int
SedWriter_hasZlib ()
{
  return static_cast<int>( SedWriter::hasZlib() );
}


LIBSEDML_EXTERN
int
SedWriter_hasBzip2 ()
{
   return static_cast<int>( SedWriter::hasBzip2() );
}


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

LIBSEDML_EXTERN
std::string writeSedMLToStdString(const SedDocument* d)
{
  SedWriter sw;
  if (d == NULL)
    return "";
  else
    return sw.writeSedMLToStdString(d);
}
/** @endcond */

LIBSEDML_CPP_NAMESPACE_END

