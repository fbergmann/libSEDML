
public: 
  /**
   * Returns the list of errors or warnings logged during parsing, 
   * consistency checking, or attempted translation of this model.
   * 
   * @return the SBMLErrorLog used for this SBMLDocument
   * 
   * @see SBMLDocument::getNumErrors()
   */
  virtual SedMLErrorLog* getErrorLog ();


  /**
   * Returns a constant pointer to the list of errors or warnings 
   * logged during parsing, consistency checking, or attempted translation 
   * of this model.
   * 
   * @return the SBMLErrorLog used for this SBMLDocument
   * 
   * @see SBMLDocument::getNumErrors()
   */
  const SedMLErrorLog* getErrorLog () const;

  /**
   * Returns the nth error or warning encountered during parsing,
   * consistency checking, or attempted translation of this model.
   *
   * Callers can use method XMLError::getSeverity() on the result to assess
   * the severity of the problem.  The possible severity levels range from
   * informational messages to fatal errors.
   *
   * @return the error or warning indexed by integer @p n, or return @c
   * NULL if <code>n &gt; (getNumErrors() - 1)</code>.
   *
   * @param n the integer index of the error sought.
   *
   * @see SBMLDocument::getNumErrors()
   */
  const SedMLError* getError (unsigned int n) const;


  /**
   * Returns the number of errors or warnings encountered during parsing,
   * consistency checking, or attempted translation of this model.
   *
   * @return the number of errors or warnings encountered
   *
   * @see SBMLDocument::getError(unsigned int n)
   */
  unsigned int getNumErrors () const;

  /**
   * Returns the number of errors or warnings encountered with the given 
   * severity during parsing,
   * consistency checking, or attempted translation of this model.
   *
   * @param severity the severity of the error sought. 
   *
   * @return the number of errors or warnings encountered
   *
   * @see SBMLDocument::getError(unsigned int n)
   */
  unsigned int getNumErrors (unsigned int severity) const;

protected:
  /**
   *
   * Subclasses should override this method to write their xmlns attriubutes
   * (if any) to the XMLOutputStream.  Be sure to call your parents implementation
   * of this method as well.
   *
   */
  virtual void writeXMLNS (XMLOutputStream& stream) const;  
private: 

	SedMLErrorLog mErrorLog;