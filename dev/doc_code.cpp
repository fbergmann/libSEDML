

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

/*
 *
 * Subclasses should override this method to write their xmlns attriubutes
 * (if any) to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 *
 */
void
SedMLDocument::writeXMLNS (XMLOutputStream& stream) const
{
  // need to check that we have indeed a namespace set!
  XMLNamespaces * thisNs = this->getNamespaces();

  // the sbml namespace is missing - add it
  if (thisNs == NULL)
  {
    XMLNamespaces xmlns;
    xmlns.add(SEDML_XMLNS_L1);

    mSedMLNamespaces->setNamespaces(&xmlns);
    thisNs = getNamespaces();
  }
  else if (thisNs->getLength() == 0)
  {
     thisNs->add(SEDML_XMLNS_L1);
  }
  else
  {
    // check that there is an sbml namespace
    std::string sedmlURI = SedMLNamespaces::getSedMLNamespaceURI(mLevel, mVersion);
    std::string sedmlPrefix = thisNs->getPrefix(sedmlURI);
    if (thisNs->hasNS(sedmlURI, sedmlPrefix) == false)
    {
      // the sbml ns is not present
      std::string other = thisNs->getURI(sedmlPrefix);
      if (other.empty() == false)
      {
        // there is another ns with the prefix that the sbml ns expects to have
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
  * @return the Namespaces associated with this SBML object
  */
XMLNamespaces* 
SedMLDocument::getNamespaces() const
{
  return mSedMLNamespaces->getNamespaces();
}