/**
 * @file SedErrorLog.cpp
 * @brief Implementation of the SedErrorLog class.
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


#include <algorithm>
#include <functional>
#include <string>
#include <list>

#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLParser.h>

#include <sedml/SedError.h>
#include <sedml/SedErrorLog.h>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibsedmlInternal */

/*
 * Creates a new empty SedErrorLog.
 */
SedErrorLog::SedErrorLog ()
{
}

/*
* Copy Constructor
*/
SedErrorLog::SedErrorLog (const SedErrorLog& other)
  : XMLErrorLog(other)
{
}

/*
* Assignment operator
*/
SedErrorLog& SedErrorLog::operator=(const SedErrorLog& other)
{
  if (&other != this)
  {
  XMLErrorLog::operator=(other);
  }
  return *this;
}



/*
 * Used by the Destructor to delete each item in mErrors.
 */
struct Delete
{
  void operator() (XMLError* error) { delete error; }
};


/*
 * Destroys this SedErrorLog.
 */
SedErrorLog::~SedErrorLog ()
{
}


/*
 * See SedError for a list of SED-ML error codes and XMLError
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

void
SedErrorLog::removeAll (const unsigned int errorId)
{
  vector<XMLError*>::iterator delIter;

  // finds an item with the given errorId (the first item will be found if
  // there are two or more items with the same Id)
  delIter = find_if(mErrors.begin(), mErrors.end(), MatchErrorId(errorId));

  while ( delIter != mErrors.end() )
  {
    // deletes (invoke delete operator for the matched item) and erases (removes
    // the pointer from mErrors) the matched item (if any)
    delete *delIter;
    mErrors.erase(delIter);

    delIter = find_if(mErrors.begin(), mErrors.end(), MatchErrorId(errorId));
  }
}


bool
SedErrorLog::contains (const unsigned int errorId) const
{
  vector<XMLError*>::const_iterator iter;

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
  unsigned int n = 0;

#if defined(__SUNPRO_CC)
  // Workaround for Sun cc which is missing:
  count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity), n);
#else
  n = (unsigned int)count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity));
#endif

  return n;
}


/*
 * Returns number of errors that are logged with severity Error
 */
unsigned int
SedErrorLog::getNumFailsWithSeverity(unsigned int severity)
{
  unsigned int n = 0;

#if defined(__SUNPRO_CC)
  // Workaround for Sun cc which is missing:
  count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity), n);
#else
  n = (unsigned int)count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity));
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


/*
 * Returns the nth SedError with severity in this log.
 *
 * @param n unsigned int number of the error to retrieve.
 * @param severity the severity sought
 *
 * @return the nth SedError in this log.
 */
const SedError*
SedErrorLog::getErrorWithSeverity(unsigned int n, unsigned int severity) const
{
  unsigned int count = 0;
  MatchSeverity matcher(severity);
  std::vector<XMLError*>::const_iterator it = mErrors.begin();
  for (; it != mErrors.end(); ++it)
  {
    if (matcher(*it))
    {
      if (count == n) return dynamic_cast<const SedError*>(*it);
      ++count;
    }
  }
  return NULL;
}

#endif /* __cplusplus */


/** @cond doxygenIgnored */
/** @endcond */
LIBSEDML_CPP_NAMESPACE_END

