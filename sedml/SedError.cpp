/**
 * @file    SedError.cpp
 * @brief   Represents Sed errors and other diagnostics
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

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <sbml/xml/XMLError.h>
#include <sedml/SedError.h>
#include <sedml/SedErrorTable.h>


/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libsbml-internal **/
/** 
 * Helper function for SedError().  Takes an index, Sed level and version,
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
 * Table of strings corresponding to the values from SedErrorCategory_t.
 * The enumeration starts at a number higher than 0, so each entry is keyed
 * by its enum value.
 *
 * A similar table for severity strings is currently unnecessary because
 * libSed never returns anything more than the XMLSeverityCode_t values.
 */
static struct sbmlCategoryString {
  unsigned int catCode;
  const char * catString;
} sbmlCategoryStringTable[] = {
  { LIBSEDML_CAT_SEDML,                   "General Sed conformance"    },
  { LIBSEDML_CAT_GENERAL_CONSISTENCY,	"Sed component consistency"  },
  { LIBSEDML_CAT_IDENTIFIER_CONSISTENCY,	"Sed identifier consistency" },
  { LIBSEDML_CAT_MATHML_CONSISTENCY,     "MathML consistency"          },
  { LIBSEDML_CAT_INTERNAL_CONSISTENCY,   "Internal consistency"        }
};

static unsigned int sbmlCategoryStringTableSize
  = sizeof(sbmlCategoryStringTable)/sizeof(sbmlCategoryStringTable[0]);

/*
 * @return the category as a string for the given @n code.
 */
std::string SedError::stringForCategory(unsigned int code) const
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


SedError::SedError (  const unsigned int errorId
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
            && mErrorId < SedCodesUpperBound )
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

    if ( index == 0 && mErrorId != SedUnknownError )
    {
      // The id is in the range of error numbers that are supposed to be in
      // the Sed layer, but it's NOT in our table. This is an internal error.
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
    // internal bookkeeping is done in libSed 3, and also to provide
    // additional info in the messages.

    mCategory     = errorTable[index].category;
    mShortMessage = errorTable[index].shortMessage;

    if ( mErrorId == SedInconsistentArgUnitsWarnings
         || mErrorId == SedInconsistentPowerUnitsWarnings
         || mErrorId == SedInconsistentExponUnitsWarnings )
    {
      mErrorId = SedInconsistentArgUnits;
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
      // libSed should errors for documents having levels/versions < L2v3.
      // LibSed handles this internally by using the special severity code
      // SchemaError in SedErrorTable.h for those Sed level/version
      // combinations that didn't have separate validation rules, then
      // here, we translate the errors into the same basic error code and
      // add some elaboration to the error text message.

      mErrorId  = SedNotSchemaConformant;
      mSeverity = LIBSEDML_SEV_ERROR;
      newMsg << errorTable[3].message << " "; // FIXME
    }
    else if (mSeverity == LIBSEDML_SEV_GENERAL_WARNING)
    {
      // General warnings are our internal code for non-XML-schema issues
      // that were not defined as errors in prior levels/versions, but then
      // were defined as errors at some later time.  Like with SchemaError,
      // we use the GeneralWarning code for those cases in SedErrorTable.h
      // and then here we translate them into regular warnings.

      mSeverity = LIBSEDML_SEV_WARNING;
      newMsg << "[Although Sed Level " << level
             << " Version " << version << " does not explicitly define the "
             << "following as an error, other Levels and/or Versions "
             << "of Sed do.] " << endl;
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



  // It's not an error code in the Sed layer, so assume the caller has
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


/** @cond doxygen-libsbml-internal **/
/*
 * clone function
 */
SedError* 
SedError::clone() const
{
  return new SedError(*this);
}
/** @endcond **/


/** @cond doxygen-libsbml-internal **/
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


/** @cond doxygen-libsbml-internal */
void
SedError::adjustErrorId(unsigned int offset)
{
  // actually dont do this since it means a user cannot 
  // look for the specific error
  //mErrorId = mErrorId - offset;
}
/** @endcond */


LIBSEDML_CPP_NAMESPACE_END

