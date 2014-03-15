/*
 * @return the nth error encountered during the parse of this
 * SedDocument or @c NULL if n > getNumErrors() - 1.
 */
const SedError*
SedDocument::getError (unsigned int n) const
{
  return mErrorLog.getError(n);
}


/*
 * @return the number of errors encountered during the parse of this
 * SedDocument.
 */
unsigned int
SedDocument::getNumErrors () const
{
  return mErrorLog.getNumErrors();
}


unsigned int 
SedDocument::getNumErrors (unsigned int severity) const
{
  return getErrorLog()->getNumFailsWithSeverity(severity);
}


/*
 * @return the SedErrorLog used to log errors during while reading and
 * validating Sed.
 */
SedErrorLog*
SedDocument::getErrorLog ()
{
  return &mErrorLog;
}


/*
 * @return the SedErrorLog used to log errors during while reading and
 * validating Sed.
 */
const SedErrorLog*
SedDocument::getErrorLog () const
{
  return &mErrorLog;
}

/*
 *
 * Subclasses should override this method to write their xmlns attriubutes
 * (if any) to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 *
 */
void
SedDocument::writeXMLNS (XMLOutputStream& stream) const
{
  // need to check that we have indeed a namespace set!
  XMLNamespaces * thisNs = this->getNamespaces();

  // the SED-ML namespace is missing - add it
  if (thisNs == NULL)
  {
    XMLNamespaces xmlns;
    if (getVersion() == 1)
    xmlns.add(SEDML_XMLNS_L1V1);
    else 
    xmlns.add(SEDML_XMLNS_L1V2);

    mSedNamespaces->setNamespaces(&xmlns);
    thisNs = getNamespaces();
  }
  else if (thisNs->getLength() == 0)
  {
     if (getVersion() == 1)
     thisNs->add(SEDML_XMLNS_L1V1);
	else
     thisNs->add(SEDML_XMLNS_L1V2);
  }
  else
  {
    // check that there is an SED-ML namespace
    std::string sedmlURI = SedNamespaces::getSedNamespaceURI(getLevel(), getVersion());
    std::string sedmlPrefix = thisNs->getPrefix(sedmlURI);
    if (thisNs->hasNS(sedmlURI, sedmlPrefix) == false)
    {
      // the SED-ML ns is not present
      std::string other = thisNs->getURI(sedmlPrefix);
      if (other.empty() == false)
      {
        // there is another ns with the prefix that the SED-ML ns expects to have
        //remove the this ns, add the sbml ns and 
        //add the new ns with a new prefix
        thisNs->remove(sedmlPrefix);
        thisNs->add(sedmlURI, sedmlPrefix);
        thisNs->add(other, "addedPrefix");
      }
      else
      {
        thisNs->add(sedmlURI, sedmlPrefix);
      }
    }
  }

  XMLNamespaces * xmlns = thisNs->clone();
  if (xmlns != NULL) 
  {
    stream << *(xmlns);
    delete xmlns;
  }
}

/*
  * @return the Namespaces associated with this SED-ML object
  */
XMLNamespaces* 
SedDocument::getNamespaces() const
{
  return mSedNamespaces->getNamespaces();
}