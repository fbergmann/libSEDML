/**
 * @file    SedErrorLog.cpp
 * @brief   Stores errors (and messages) encountered while processing Sed.
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


#include <algorithm>
#include <functional>
#include <string>
#include <list>

#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLParser.h>
#include <sedml/SedError.h>
#include <sedml/SedErrorLog.h>


/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libsbml-internal */
/** Most of the methods are internal.  A few visible ones are at the end. */


/*
 * Creates a new empty SedErrorLog.
 */
SedErrorLog::SedErrorLog ()
{
}


/*
 * Used by the Destructor to delete each item in mErrors.
 */
struct Delete : public unary_function<XMLError*, void>
{
  void operator() (XMLError* error) { delete error; }
};


/*
 * Destroys this SedErrorLog.
 */
SedErrorLog::~SedErrorLog ()
{
/*
  //
  // debug code for SedErrorLog::remove(const unsigned int)
  //
  vector<XMLError*>::iterator iter;

  int count = 0;
  iter = mErrors.begin();
  while(iter != mErrors.end() )
  {
    ++count;
    unsigned int errid  = (*iter)->getErrorId();
    unsigned int column = (*iter)->getColumn();
    cout << "(" << count << ") ErrorId " << errid << " column " << column << endl;
    remove (errid);
    cout << "Size of mErrors " << mErrors.size() << endl;
    iter = mErrors.begin();
  }
*/
}


/*
 * See SedError for a list of Sed error codes and XMLError
 * for a list of system and XML-level error codes.
 */
void
SedErrorLog::logError ( const unsigned int errorId
                       , const unsigned int level
                       , const unsigned int version
                       , const std::string& details
                       , const unsigned int line
                       , const unsigned int column
                       , const unsigned int severity
                       , const unsigned int category )
{
  add( SedError( errorId, level, version, details, line, column,
                  severity, category ));
}


void
SedErrorLog::logPackageError ( const std::string& package
                       , const unsigned int errorId
                       , const unsigned int pkgVersion
                       , const unsigned int level
                       , const unsigned int version
                       , const std::string& details
                       , const unsigned int line
                       , const unsigned int column
                       , const unsigned int severity
                       , const unsigned int category )
{
  add( SedError( errorId, level, version, details, line, column,
                  severity, category, package, pkgVersion));
}


/*
 * Adds the given SedError to the log.
 *
 * @param error SedError, the error to be logged.
 */
void
SedErrorLog::add (const SedError& error)
{
  if (error.getSeverity() != LIBSEDML_SEV_NOT_APPLICABLE)
    XMLErrorLog::add(error);
}


/*
 * Logs (copies) the SedErrors in the given SedError list to this
 * SedErrorLog.
 *
 * @param errors list, a list of SedError to be added to the log.
 */
void
SedErrorLog::add (const std::list<SedError>& errors)
{
  list<SedError>::const_iterator end = errors.end();
  list<SedError>::const_iterator iter;

  for (iter = errors.begin(); iter != end; ++iter)
    XMLErrorLog::add( *iter );
}

/*
 * Logs (copies) the SedErrors in the given SedError vector to this
 * SedErrorLog.
 *
 * @param errors vector, a vector of SedError to be added to the log.
 */
void
SedErrorLog::add (const std::vector<SedError>& errors)
{
  vector<SedError>::const_iterator end = errors.end();
  vector<SedError>::const_iterator iter;

  for (iter = errors.begin(); iter != end; ++iter)
    XMLErrorLog::add( *iter );
}

/*
 * Helper class used by SedErrorLog::remove.
 */
class MatchErrorId
{
public:
  MatchErrorId(const unsigned int theId) : idToFind(theId) {};

  bool operator() (XMLError* e) const
  {
    return e->getErrorId() == idToFind;
  };

private:
  unsigned int idToFind;
};


/*
 * Removes an error having errorId from the SedError list.
 *
 * Only the first item will be removed if there are multiple errors
 * with the given errorId.
 *
 * @param errorId the error identifier of the error to be removed.
 */
void
SedErrorLog::remove (const unsigned int errorId)
{
  //
  // "mErrors.erase( remove_if( ...))" can't be used for removing
  // the matched items from the list, because the type of the vector container is pointer
  // of XMLError object.
  //
  // (Effective STL 50 Specific Ways to Improve Your Use of the Standard Template Library
  //  Scott Meyers
  //  Item 33: Be wary of remove-like algorithms on containers of pointers. 143)
  //
  //
  vector<XMLError*>::iterator delIter;

  // finds an item with the given errorId (the first item will be found if
  // there are two or more items with the same Id)
  delIter = find_if(mErrors.begin(), mErrors.end(), MatchErrorId(errorId));

  if ( delIter != mErrors.end() )
  {
    // deletes (invoke delete operator for the matched item) and erases (removes
    // the pointer from mErrors) the matched item (if any)
    delete *delIter;
    mErrors.erase(delIter);
  }
}


bool
SedErrorLog::contains (const unsigned int errorId)
{
  vector<XMLError*>::iterator iter;

  // finds an item with the given errorId (the first item will be found if
  // there are two or more items with the same Id)
  iter = find_if(mErrors.begin(), mErrors.end(), MatchErrorId(errorId));

  if ( iter != mErrors.end() )
  {
    return true;
  }
  else
  {
    return false;
  }
}


/*
 * Helper class used by
 * SedErrorLog::getNumFailsWithSeverity(SedErrorSeverity_t).
 */
class MatchSeverity
{
public:
  MatchSeverity(const unsigned int s) : severity(s) {};

  bool operator() (XMLError* e) const
  {
    return e->getSeverity() == severity;
  };

private:
  unsigned int severity;
};



/** @endcond */

unsigned int
SedErrorLog::getNumFailsWithSeverity(unsigned int severity) const
{
  int n = 0;

#if defined(__SUNPRO_CC)
  // Workaround for Sun cc which is missing:
  count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity), n);
#else
  n = (int)count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity));
#endif

  return n;
}

/*
 * Returns number of errors that are logged with severity Error
 */
unsigned int
SedErrorLog::getNumFailsWithSeverity(unsigned int severity)
{
  int n = 0;

#if defined(__SUNPRO_CC)
  // Workaround for Sun cc which is missing:
  count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity), n);
#else
  n = (int)count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity));
#endif

  return n;
}


/*
 * Returns the nth SedError in this log.
 *
 * @param n unsigned int number of the error to retrieve.
 *
 * @return the nth SedError in this log.
 */
const SedError*
SedErrorLog::getError (unsigned int n) const
{
  return static_cast<const SedError*>(XMLErrorLog::getError(n));
}

LIBSEDML_CPP_NAMESPACE_END

