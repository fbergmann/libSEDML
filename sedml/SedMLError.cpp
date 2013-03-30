/**
 * @file    SedMLError.cpp
 * @brief   Represents SedML errors and other diagnostics
 * @author  Michael Hucka
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

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <sbml/xml/XMLError.h>
#include <sedml/SedMLError.h>
#include <sedml/SedMLErrorTable.h>


/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libsbml-internal **/
/** 
 * Helper function for SedMLError().  Takes an index, SedML level and version,
 * and returns the appropriate field for the severity code out of the
   errorTable entry.
 */
static const unsigned int
getSeverityForEntry(unsigned int index,
                    unsigned int level,
                    unsigned int version)
{
    switch (version)
    {
    default:
    case 1:
      return errorTable[index].l1v1_severity;

    }
}


/*
 * @return the severity as a string for the given @n code.
 */
std::string SedMLError::stringForSeverity(unsigned int code) const
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
        break;
      case LIBSEDML_SEV_GENERAL_WARNING:
        return "General warning";
        break;
      case LIBSEDML_SEV_NOT_APPLICABLE:
        return "Not applicable";
        break;
      default:
        return "";
        break;
    }
  }
}

/*
 * Table of strings corresponding to the values from SedMLErrorCategory_t.
 * The enumeration starts at a number higher than 0, so each entry is keyed
 * by its enum value.
 *
 * A similar table for severity strings is currently unnecessary because
 * libSedML never returns anything more than the XMLSeverityCode_t values.
 */
static struct sbmlCategoryString {
  unsigned int catCode;
  const char * catString;
} sbmlCategoryStringTable[] = {
  { LIBSEDML_CAT_SEDML,                   "General SedML conformance"    },
  { LIBSEDML_CAT_GENERAL_CONSISTENCY,	"SedML component consistency"  },
  { LIBSEDML_CAT_IDENTIFIER_CONSISTENCY,	"SedML identifier consistency" },
  { LIBSEDML_CAT_MATHML_CONSISTENCY,     "MathML consistency"          },
  { LIBSEDML_CAT_INTERNAL_CONSISTENCY,   "Internal consistency"        }
};

static unsigned int sbmlCategoryStringTableSize
  = sizeof(sbmlCategoryStringTable)/sizeof(sbmlCategoryStringTable[0]);

/*
 * @return the category as a string for the given @n code.
 */
std::string SedMLError::stringForCategory(unsigned int code) const
{
  if ( code >= LIBSEDML_CAT_SEDML )
  {
    for ( unsigned int i = 0; i < sbmlCategoryStringTableSize; i++ )
      if ( sbmlCategoryStringTable[i].catCode == code )
        return sbmlCategoryStringTable[i].catString;
  }

  return XMLError::stringForCategory(code);
}

/** @endcond **/


SedMLError::SedMLError (  const unsigned int errorId
                      , const unsigned int level
                      , const unsigned int version 
                      , const std::string& details
                      , const unsigned int line
                      , const unsigned int column
                      , const unsigned int severity
                      , const unsigned int category 
                      , const std::string& package
                      , const unsigned int pkgVersion) :
    XMLError(errorId, details, line, column, severity, category)
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
            && mErrorId < SedMLCodesUpperBound )
  {
    unsigned int tableSize = sizeof(errorTable)/sizeof(errorTable[0]);
    unsigned int index = 0;

    for ( unsigned int i = 0; i < tableSize; i++ )
    {
      if ( mErrorId == errorTable[i].code )
      {
        index = i;
        break;
      }
    }

    if ( index == 0 && mErrorId != UnknownError )
    {
      // The id is in the range of error numbers that are supposed to be in
      // the SedML layer, but it's NOT in our table. This is an internal error.
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
    // internal bookkeeping is done in libSedML 3, and also to provide
    // additional info in the messages.

    mCategory     = errorTable[index].category;
    mShortMessage = errorTable[index].shortMessage;

    if ( mErrorId == InconsistentArgUnitsWarnings
         || mErrorId == InconsistentPowerUnitsWarnings
         || mErrorId == InconsistentExponUnitsWarnings )
    {
      mErrorId = InconsistentArgUnits;
    }

    ostringstream newMsg;
    mSeverity = getSeverityForEntry(index, level, version);

    if (mValidError == false)
      mSeverity = LIBSEDML_SEV_WARNING;

    if (mSeverity == LIBSEDML_SEV_SCHEMA_ERROR)
    {
      // Prior to L2v3, many possible errors were not listed separately as
      // validation rules because they were assumed to be caught by a
      // schema-aware XML parser.  In L2v3, we stopped relying on this and
      // listed schema errors separately.  This poses a problem for how
      // libSedML should errors for documents having levels/versions < L2v3.
      // LibSedML handles this internally by using the special severity code
      // SchemaError in SedMLErrorTable.h for those SedML level/version
      // combinations that didn't have separate validation rules, then
      // here, we translate the errors into the same basic error code and
      // add some elaboration to the error text message.

      mErrorId  = NotSchemaConformant;
      mSeverity = LIBSEDML_SEV_ERROR;
      newMsg << errorTable[3].message << " "; // FIXME
    }
    else if (mSeverity == LIBSEDML_SEV_GENERAL_WARNING)
    {
      // General warnings are our internal code for non-XML-schema issues
      // that were not defined as errors in prior levels/versions, but then
      // were defined as errors at some later time.  Like with SchemaError,
      // we use the GeneralWarning code for those cases in SedMLErrorTable.h
      // and then here we translate them into regular warnings.

      mSeverity = LIBSEDML_SEV_WARNING;
      newMsg << "[Although SedML Level " << level
             << " Version " << version << " does not explicitly define the "
             << "following as an error, other Levels and/or Versions "
             << "of SedML do.] " << endl;
    }

    // Finish updating the (full) error message.

    newMsg << errorTable[index].message;
    
    // look for individual references
    // if the code for this error does not yet exist skip

    if (!details.empty())
    {
      newMsg << " " << details;
    }      
    newMsg << endl;
    mMessage  = newMsg.str();

    // We mucked around with the severity code and (maybe) category code
    // after creating the XMLError object, so we may have to update the
    // corresponding strings.

    mSeverityString = stringForSeverity(mSeverity);
    mCategoryString = stringForCategory(mCategory);

    return;
  }



  // It's not an error code in the SedML layer, so assume the caller has
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
SedMLError::SedMLError(const SedMLError& orig) :
 XMLError(orig)
{
}


/** @cond doxygen-libsbml-internal **/
/*
 * clone function
 */
SedMLError* 
SedMLError::clone() const
{
  return new SedMLError(*this);
}
/** @endcond **/


/** @cond doxygen-libsbml-internal **/
/*
 * Outputs this SedMLError to stream in the following format (and followed by
 * a newline):
 *
 *   line: (error_id [severity]) message
 */
void
SedMLError::print(ostream& s) const
{
  if (getPackage().empty() == true || getPackage() == "core")
  {
    s << "line " << getLine() << ": ("
      << setfill('0') << setw(5) << getErrorId()
      << " [" << getSeverityAsString() << "]) "
      << getMessage() << endl;
  }
  else
  {
    s << "line " << getLine() << ": (" << getPackage() << "-"
      << setfill('0') << setw(5) << (getErrorId() - getErrorIdOffset())
      << " [" << getSeverityAsString() << "]) "
      << getMessage() << endl;
  }
}
/** @endcond **/


/** @cond doxygen-libsbml-internal */
void
SedMLError::adjustErrorId(unsigned int offset)
{
  // actually dont do this since it means a user cannot 
  // look for the specific error
  //mErrorId = mErrorId - offset;
}
/** @endcond */


LIBSEDML_CPP_NAMESPACE_END

