/**
 * @file SedError.cpp
 * @brief Implementation of the SedError class.
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



#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <sbml/xml/XMLError.h>

#include <sedml/SedError.h>
#include <sedml/SedErrorTable.h>


/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibsedmlInternal **/
/** 
 * Helper function for SedError().  Takes an index, SED-ML level and version,
 * and returns the appropriate field for the severity code out of the
   sedmlErrorTable entry.
 */
static const unsigned int
getSeverityForEntry(unsigned int index,
                    unsigned int level,
                    unsigned int version)
{
  if ( level == 1 )
  {
    switch (version)
    {
    case 1:
    default:
      return sedmlErrorTable[index].l1v1_severity;
    }
  }
  else
  {
    return sedmlErrorTable[index].l1v1_severity;
  }
}


/*
 * @return the severity as a string for the given @n code.
 */
std::string SedError::stringForSeverity(unsigned int code) const
{
  /* it should never happen that an error ends up with a severity
   * that is not in the XMLSeverity_t enumeration
   * but just in case:
   */
  if (code < LIBSEDML_SEV_SCHEMA_ERROR)
  {
    return XMLError::stringForSeverity(code);
  }
  else
  {
    switch (code)
    {
      case LIBSEDML_SEV_SCHEMA_ERROR:
        return "Schema error";

      case LIBSEDML_SEV_GENERAL_WARNING:
        return "General warning";

      case LIBSEDML_SEV_NOT_APPLICABLE:
        return "Not applicable";

      default:
        return "";
    }
  }
}

/*
 * Table of strings corresponding to the values from SedErrorCategory_t.
 * The enumeration starts at a number higher than 0, so each entry is keyed
 * by its enum value.
 *
 * A similar table for severity strings is currently unnecessary because
 * libSEDML never returns anything more than the XMLSeverityCode_t values.
 */
static struct sedmlCategoryString {
  unsigned int catCode;
  const char * catString;
} sedmlCategoryStringTable[] = 
{
  { LIBSEDML_CAT_SEDML,                   "General SED-ML conformance"    },
  { LIBSEDML_CAT_GENERAL_CONSISTENCY,	"SED-ML component consistency"  },
  { LIBSEDML_CAT_IDENTIFIER_CONSISTENCY,	"SED-ML identifier consistency" },
  { LIBSEDML_CAT_MATHML_CONSISTENCY,     "MathML consistency"          },
  { LIBSEDML_CAT_INTERNAL_CONSISTENCY,   "Internal consistency"        }
};

static unsigned int sedmlCategoryStringTableSize
  = sizeof(sedmlCategoryStringTable)/sizeof(sedmlCategoryStringTable[0]);

/*
 * @return the category as a string for the given @n code.
 */
std::string SedError::stringForCategory(unsigned int code) const
{
  if ( code >= LIBSEDML_CAT_SEDML )
  {
    for ( unsigned int i = 0; i < sedmlCategoryStringTableSize; i++ )
      if ( sedmlCategoryStringTable[i].catCode == code )
        return sedmlCategoryStringTable[i].catString;
  }

  return XMLError::stringForCategory(code);
}
/** @endcond **/


SedError::SedError (  const unsigned int errorId
                      , const unsigned int level
                      , const unsigned int version 
                      , const std::string& details
                      , const unsigned int line
                      , const unsigned int column
                      , const unsigned int severity
                      , const unsigned int category) :
    XMLError((int)errorId, details, line, column, severity, category)
{
  // Check if the given @p id is one we have in our table of error codes.  If
  // it is, fill in the fields of the error object with the appropriate
  // content.  If it's not in the table, take the content as-is.

  if ( /*mErrorId >= 0 &&*/ mErrorId < XMLErrorCodesUpperBound )
  {
    // The error was caught during the XML read and the XMLError
    // constructor will have filled in all the right pieces.
    return;
  }
  else if ( mErrorId > XMLErrorCodesUpperBound
            && mErrorId < SedCodesUpperBound )
  {
    unsigned int tableSize = sizeof(sedmlErrorTable)/sizeof(sedmlErrorTable[0]);
    unsigned int index = 0;

    for ( unsigned int i = 0; i < tableSize; i++ )
    {
      if ( mErrorId == sedmlErrorTable[i].code )
      {
        index = i;
        break;
      }
    }

    if ( index == 0 && mErrorId != SedUnknown )
    {
      // The id is in the range of error numbers that are supposed to be in
      // the SED-ML layer, but it's NOT in our table. This is an internal error.
      // Unfortunately, we don't have an error log or anywhere to report it
      // except the measure of last resort: the standard error output.
    
      //cerr << "Internal error: unknown error code '" << mErrorId
      //     << "' encountered while processing error." << endl;
      //return;
      // Changed this behaviour

      // Now we log the error as an UnKnown Error and mark it as invalid

      mValidError = false;
    }

    // The rest of this block massages the results to account for how some
    // internal bookkeeping is done in libSEDML 3, and also to provide
    // additional info in the messages.

    mCategory     = sedmlErrorTable[index].category;
    mShortMessage = sedmlErrorTable[index].shortMessage;

    ostringstream newMsg;
    mSeverity = getSeverityForEntry(index, level, version);

    if (mValidError == false)
      mSeverity = LIBSEDML_SEV_WARNING;

    if (mSeverity == LIBSEDML_SEV_SCHEMA_ERROR)
    {
      mErrorId  = SedNotSchemaConformant;
      mSeverity = LIBSEDML_SEV_ERROR;
      newMsg << sedmlErrorTable[3].message << " "; // FIXME
    }
    else if (mSeverity == LIBSEDML_SEV_GENERAL_WARNING)
    {

      mSeverity = LIBSEDML_SEV_WARNING;
      newMsg << "[Although SED-ML Level " << level
             << " Version " << version << " does not explicitly define the "
             << "following as an error, other Levels and/or Versions "
             << "of SED-ML do.] " << endl;
    }

    // Finish updating the (full) error message.

    if (!((string)sedmlErrorTable[index].message).empty()) {
      newMsg << sedmlErrorTable[index].message << endl;
    }

    // look for individual references
    // if the code for this error does not yet exist skip

    if (sedmlErrorTable[index].reference.ref_l1v1 != NULL)
    {

      std::string ref;
      switch(level)
      {
      case 1:
      default:
       switch(version)
        {
        case 1:
        default:
          ref = sedmlErrorTable[index].reference.ref_l1v1;
        break;
        }
       break;
      }

      if (!ref.empty())
      {
        newMsg << "Reference: " << ref << endl;
      }
    }
    if (!details.empty())
    {
      newMsg << " " << details;
      if (details[details.size()-1] != '\n') {
        newMsg << endl;
      }
    }      
    mMessage  = newMsg.str();

    // We mucked around with the severity code and (maybe) category code
    // after creating the XMLError object, so we may have to update the
    // corresponding strings.

    mSeverityString = stringForSeverity(mSeverity);
    mCategoryString = stringForCategory(mCategory);

    return;
  }


   // It's not an error code in the SED-ML layer, so assume the caller has
  // filled in all the relevant additional data.  (If they didn't, the
  // following merely assigns the defaults.)
  mMessage        = details;
  mSeverity       = severity;
  mCategory       = category;
  mSeverityString = stringForSeverity(mSeverity);
  mCategoryString = stringForCategory(mCategory);
}


/*
 * Copy Constructor
 */
SedError::SedError(const SedError& orig) :
 XMLError(orig)
{
}

SedError& 
SedError::operator=(const SedError& rhs)
{
  if (&rhs != this)
  {
    XMLError::operator=(rhs);
  }
  return *this;
}

 /*
 * Destroys this SedError.
 */
SedError::~SedError ()
{
}


/** @cond doxygenLibsedmlInternal **/
/*
 * clone function
 */
SedError* 
SedError::clone() const
{
  return new SedError(*this);
}
/** @endcond **/


/** @cond doxygenLibsedmlInternal **/
/*
 * Outputs this SedError to stream in the following format (and followed by
 * a newline):
 *
 *   line: (error_id [severity]) message
 */
void
SedError::print(ostream& s) const
{
    s << "line " << getLine() << ": ("
      << setfill('0') << setw(5) << getErrorId()
      << " [" << getSeverityAsString() << "]) "
      << getMessage() << endl;
}
/** @endcond **/


#endif /* __cplusplus */

LIBSEDML_CPP_NAMESPACE_END

