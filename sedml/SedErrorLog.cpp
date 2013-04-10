/**
 * @file    SedMLErrorLog.cpp
 * @brief   Stores errors (and messages) encountered while processing SedML.
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

#include <algorithm>
#include <functional>
#include <string>
#include <list>

#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLParser.h>
#include <sedml/SedMLError.h>
#include <sedml/SedMLErrorLog.h>


/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libsbml-internal */
/** Most of the methods are internal.  A few visible ones are at the end. */


/*
 * Creates a new empty SedMLErrorLog.
 */
SedMLErrorLog::SedMLErrorLog ()
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
 * Destroys this SedMLErrorLog.
 */
SedMLErrorLog::~SedMLErrorLog ()
{
/*
  //
  // debug code for SedMLErrorLog::remove(const unsigned int)
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
 * See SedMLError for a list of SedML error codes and XMLError
 * for a list of system and XML-level error codes.
 */
void
SedMLErrorLog::logError ( const unsigned int errorId
                       , const unsigned int level
                       , const unsigned int version
                       , const std::string& details
                       , const unsigned int line
                       , const unsigned int column
                       , const unsigned int severity
                       , const unsigned int category )
{
  add( SedMLError( errorId, level, version, details, line, column,
                  severity, category ));
}


void
SedMLErrorLog::logPackageError ( const std::string& package
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
  add( SedMLError( errorId, level, version, details, line, column,
                  severity, category, package, pkgVersion));
}


/*
 * Adds the given SedMLError to the log.
 *
 * @param error SedMLError, the error to be logged.
 */
void
SedMLErrorLog::add (const SedMLError& error)
{
  if (error.getSeverity() != LIBSEDML_SEV_NOT_APPLICABLE)
    XMLErrorLog::add(error);
}


/*
 * Logs (copies) the SedMLErrors in the given SedMLError list to this
 * SedMLErrorLog.
 *
 * @param errors list, a list of SedMLError to be added to the log.
 */
void
SedMLErrorLog::add (const std::list<SedMLError>& errors)
{
  list<SedMLError>::const_iterator end = errors.end();
  list<SedMLError>::const_iterator iter;

  for (iter = errors.begin(); iter != end; ++iter)
    XMLErrorLog::add( *iter );
}

/*
 * Logs (copies) the SedMLErrors in the given SedMLError vector to this
 * SedMLErrorLog.
 *
 * @param errors vector, a vector of SedMLError to be added to the log.
 */
void
SedMLErrorLog::add (const std::vector<SedMLError>& errors)
{
  vector<SedMLError>::const_iterator end = errors.end();
  vector<SedMLError>::const_iterator iter;

  for (iter = errors.begin(); iter != end; ++iter)
    XMLErrorLog::add( *iter );
}

/*
 * Helper class used by SedMLErrorLog::remove.
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
 * Removes an error having errorId from the SedMLError list.
 *
 * Only the first item will be removed if there are multiple errors
 * with the given errorId.
 *
 * @param errorId the error identifier of the error to be removed.
 */
void
SedMLErrorLog::remove (const unsigned int errorId)
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
SedMLErrorLog::contains (const unsigned int errorId)
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
 * SedMLErrorLog::getNumFailsWithSeverity(SedMLErrorSeverity_t).
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
SedMLErrorLog::getNumFailsWithSeverity(unsigned int severity) const
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
SedMLErrorLog::getNumFailsWithSeverity(unsigned int severity)
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
 * Returns the nth SedMLError in this log.
 *
 * @param n unsigned int number of the error to retrieve.
 *
 * @return the nth SedMLError in this log.
 */
const SedMLError*
SedMLErrorLog::getError (unsigned int n) const
{
  return static_cast<const SedMLError*>(XMLErrorLog::getError(n));
}

LIBSEDML_CPP_NAMESPACE_END

