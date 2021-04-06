/**
 * @file SedErrorLog.h
 * @brief Definition of the SedErrorLog class.
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
 *
 * @class SedErrorLog
 * @sbmlbrief{} TODO:Definition of the SedErrorLog class.
 */


#ifndef SedErrorLog_h
#define SedErrorLog_h


#include <sedml/common/extern.h>
#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>
#include <sedml/SedError.h>


#ifdef __cplusplus

#include <vector>

LIBSEDML_CPP_NAMESPACE_BEGIN

class LIBSEDML_EXTERN SedErrorLog : public XMLErrorLog
{
public:

  /**
   * Returns the <i>n</i>th SedError object in this log.
   *
   * Index @p n is counted from 0.  Callers should first inquire about the
   * number of items in the log by using the
   * @if java XMLErrorLog::getNumErrors()@else getNumErrors()@endif@~ method.
   * Attempts to use an error index number that exceeds the actual number
   * of errors in the log will result in a @c NULL being returned.
   *
   * @param n the index number of the error to retrieve (with 0 being the
   * first error).
   *
   * @return the <i>n</i>th SedError in this log, or @c NULL if @p n is
   * greater than or equal to
   * @if java XMLErrorLog::getNumErrors()@else getNumErrors()@endif.
   *
   * @see getNumErrors()
   */
  const SedError* getError (unsigned int n) const;


  /**
   * Returns the <i>n</i>th SedError object with given severity in this log.
   *
   * Index @p n is counted from 0.  Callers should first inquire about the
   * number of items in the log by using the
   * @if java SedErrorLog::getNumFailsWithSeverity(long severity)@else getNumFailsWithSeverity()@endif@~ method.
   * Attempts to use an error index number that exceeds the actual number
   * of errors in the log will result in a @c NULL being returned.
   *
   * @param n the index number of the error to retrieve (with 0 being the
   * first error).
   * @param severity the severity of the error to retrieve 
   *
   * @return the <i>n</i>th SedError in this log, or @c NULL if @p n is
   * greater than or equal to
   * @if java SedErrorLog::getNumFailsWithSeverity(long severity)@else getNumFailsWithSeverity()@endif.
   *
   * @see getNumFailsWithSeverity(unsigned int severity)
   */
  const SedError* getErrorWithSeverity(unsigned int n, unsigned int severity) const;


  /**
   * Returns the number of errors that have been logged with the given
   * severity code.
   *
   * @if clike @param severity a value from
   * #SedErrorSeverity_t @endif@if java @param severity a
   * value from the set of <code>LIBSEDML_SEV_</code> constants defined by
   * the interface class <code><a
   * href="libsedmlConstants.html">libsedmlConstants</a></code> @endif@if python @param severity a
   * value from the set of <code>LIBSEDML_SEV_</code> constants defined by
   * the interface class @link libsedml libsedml@endlink. @endif@~
   *
   * @return a count of the number of errors with the given severity code.
   *
   * @see getNumErrors()
   */
  unsigned int getNumFailsWithSeverity(unsigned int severity);


   /**
   * Returns the number of errors that have been logged with the given
   * severity code.
   *
   * @if clike @param severity a value from
   * #SedErrorSeverity_t @endif@if java @param severity a
   * value from the set of <code>LIBSEDML_SEV_</code> constants defined by
   * the interface class <code><a
   * href="libsedmlConstants.html">libsedmlConstants</a></code> @endif@if python @param severity a
   * value from the set of <code>LIBSEDML_SEV_</code> constants defined by
   * the interface class @link libsedml libsedml@endlink. @endif@~
   *
   * @return a count of the number of errors with the given severity code.
   *
   * @see getNumErrors()
   */
  unsigned int getNumFailsWithSeverity(unsigned int severity) const;


  /** @cond doxygenLibsedmlInternal */
  
  /**
   * Creates a new, empty SedErrorLog.
   */
  SedErrorLog ();


  /**
   * Copy Constructor
   */
  SedErrorLog (const SedErrorLog& other);


  /**
   * Assignment operator for SedErrorLog
   */
  SedErrorLog& operator=(const SedErrorLog& other);


  /**
   * Destroys this SedErrorLog.
   */
  virtual ~SedErrorLog ();


  /**
   * Convenience function that combines creating an SedError object and
   * adding it to the log.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level an unsigned int, the SED-ML Level
   *
   * @param version an unsigned int, the SED-ML Level's Version
   * 
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by SedError,
   * the given message is @em appended to a predefined message associated
   * with the given code.  If the error code is not recognized, the message
   * is stored as-is as the text of the error.
   * 
   * @param line an unsigned int, the line number at which the error occured.
   * 
   * @param column an unsigned int, the column number at which the error occured.
   * 
   * @param severity an integer indicating severity of the error.
   * 
   * @param category an integer indicating the category to which the error
   * belongs.
   */
  void logError
  (
      const unsigned int errorId  = 0
    , const unsigned int level    = SEDML_DEFAULT_LEVEL
    , const unsigned int version  = SEDML_DEFAULT_VERSION
    , const std::string& details  = ""
    , const unsigned int line     = 0
    , const unsigned int column   = 0
    , const unsigned int severity = LIBSEDML_SEV_ERROR
    , const unsigned int category = LIBSEDML_CAT_SEDML
  );


  /**
   * Adds the given SedError to the log.
   *
   * @param error SedError, the error to be logged.
   */
  void add (const SedError& error);


  /** @cond doxygenCppOnly */

  /**
   * Adds (copies) the SedErrors in the given SedError list to this
   * SedErrorLog.
   *
   * @param errors list, a list of SedError to be added to the log.
   */
  void add (const std::list<SedError>& errors);


  /**
   * Adds (copies) the SedErrors in the given SedError vector to this
   * SedErrorLog.
   *
   * @param errors vector, a vector of SedError to be added to the log.
   */
  void add (const std::vector<SedError>& errors);

  /** @endcond */


  /**
   * Removes an error having errorId from the SedError list.
   *  
   * Only the first item will be removed if there are multiple errors
   * with the given errorId.
   *
   * @param errorId the error identifier of the error to be removed.
   */
  void remove (const unsigned int errorId);


  /**
   * Removes all errors having errorId from the SedError list.
   *
   * @param errorId the error identifier of the error to be removed.
   */
  void removeAll(const unsigned int errorId);

  /**
   * Returns true if SedErrorLog contains an errorId
   *
   * @param errorId the error identifier of the error to be found.
   */
  bool contains (const unsigned int errorId) const;


  /** @endcond */
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* SedErrorLog_h */
