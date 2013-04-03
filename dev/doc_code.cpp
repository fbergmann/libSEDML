

/*
 * @return the nth error encountered during the parse of this
 * SedMLDocument or @c NULL if n > getNumErrors() - 1.
 */
const SedMLError*
SedMLDocument::getError (unsigned int n) const
{
  return mErrorLog.getError(n);
}


/*
 * @return the number of errors encountered during the parse of this
 * SedMLDocument.
 */
unsigned int
SedMLDocument::getNumErrors () const
{
  return mErrorLog.getNumErrors();
}


unsigned int 
SedMLDocument::getNumErrors (unsigned int severity) const
{
  return getErrorLog()->getNumFailsWithSeverity(severity);
}


/*
 * @return the SedMLErrorLog used to log errors during while reading and
 * validating SedML.
 */
SedMLErrorLog*
SedMLDocument::getErrorLog ()
{
  return &mErrorLog;
}


/*
 * @return the SedMLErrorLog used to log errors during while reading and
 * validating SedML.
 */
const SedMLErrorLog*
SedMLDocument::getErrorLog () const
{
  return &mErrorLog;
}

