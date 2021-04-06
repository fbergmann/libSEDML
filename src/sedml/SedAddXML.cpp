/**
 * @file SedAddXML.cpp
 * @brief Implementation of the SedAddXML class.
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
#include <sedml/SedAddXML.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAddXML using the given SED-ML Level and @ p version values.
 */
SedAddXML::SedAddXML(unsigned int level, unsigned int version)
  : SedChange(level, version)
  , mNewXML (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedAddXML using the given SedNamespaces object @p sedmlns.
 */
SedAddXML::SedAddXML(SedNamespaces *sedmlns)
  : SedChange(sedmlns)
  , mNewXML (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedAddXML.
 */
SedAddXML::SedAddXML(const SedAddXML& orig)
  : SedChange( orig )
  , mNewXML ( NULL )
{
  if (orig.mNewXML != NULL)
  {
    mNewXML = orig.mNewXML->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedAddXML.
 */
SedAddXML&
SedAddXML::operator=(const SedAddXML& rhs)
{
  if (&rhs != this)
  {
    SedChange::operator=(rhs);
    delete mNewXML;
    if (rhs.mNewXML != NULL)
    {
      mNewXML = rhs.mNewXML->clone();
    }
    else
    {
      mNewXML = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAddXML object.
 */
SedAddXML*
SedAddXML::clone() const
{
  return new SedAddXML(*this);
}


/*
 * Destructor for SedAddXML.
 */
SedAddXML::~SedAddXML()
{
  delete mNewXML;
  mNewXML = NULL;
}


/*
 * Returns the value of the "newXML" element of this SedAddXML.
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SedAddXML::getNewXML() const
{
  return mNewXML;
}


/*
 * Returns the value of the "newXML" element of this SedAddXML.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SedAddXML::getNewXML()
{
  return mNewXML;
}


/*
 * Predicate returning @c true if this SedAddXML's "newXML" element is set.
 */
bool
SedAddXML::isSetNewXML() const
{
  return (mNewXML != NULL);
}


/*
 * Sets the value of the "newXML" element of this SedAddXML.
 */
int
SedAddXML::setNewXML(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* newXML)
{
  if (mNewXML == newXML)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (newXML == NULL)
  {
    delete mNewXML;
    mNewXML = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mNewXML;
    mNewXML = (newXML != NULL) ? newXML->clone() : NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "newXML" element of this SedAddXML.
 */
int
SedAddXML::unsetNewXML()
{
  delete mNewXML;
  mNewXML = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this SedAddXML object.
 */
const std::string&
SedAddXML::getElementName() const
{
  static const string name = "addXML";
  return name;
}


/*
 * Returns the libSEDML type code for this SedAddXML object.
 */
int
SedAddXML::getTypeCode() const
{
  return SEDML_CHANGE_ADDXML;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAddXML object have been set.
 */
bool
SedAddXML::hasRequiredAttributes() const
{
  bool allPresent = SedChange::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SedAddXML
 * object have been set.
 */
bool
SedAddXML::hasRequiredElements() const
{
  bool allPresent = SedChange::hasRequiredElements();

  if (isSetNewXML() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedAddXML::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedChange::writeElements(stream);

  if (isSetNewXML() == true)
  {
    stream.startElement("newXML");
    stream << *mNewXML;
    stream.endElement("newXML");
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAddXML::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAddXML::setSedDocument(SedDocument* d)
{
  SedChange::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedAddXML::connectToChild()
{
  SedChange::connectToChild();
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SedChange::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedAddXML's attribute "attributeName" is
 * set.
 */
bool
SedAddXML::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedChange::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SedChange::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedAddXML.
 */
int
SedAddXML::unsetAttribute(const std::string& attributeName)
{
  int value = SedChange::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedAddXML::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SedBase* obj = SedChange::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedAddXML::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedChange::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAddXML::readAttributes(
                          const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&
                            attributes,
                          const LIBSBML_CPP_NAMESPACE_QUALIFIER
                            ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedChange::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlChangeAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
SedAddXML::readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  bool read = false;
  const string& name = stream.peek().getName();
  std::string newElementText;

  if (name == "newXML")
  {
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken& token = stream.next();

    while (stream.isGood() && stream.peek().isText())
    {
      newElementText += stream.next().getCharacters();
    }
    newElementText = _trim(newElementText);

    delete mNewXML;
    mNewXML = NULL;

    while (stream.isGood())
    {
      const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken& next = stream.peek();
      if (!stream.isGood()) break;

      if (next.isEndFor(token))
      {
        stream.next();
        break;
      }
      else if (next.isStart())
      {
        if (mNewXML == NULL)
        {
          mNewXML = new
            LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode();

          if (!newElementText.empty())
            mNewXML->addChild(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(newElementText));
        }

        mNewXML->addChild(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(stream));
      }
      else if (next.isText())
      {
        std::string s = _trim(next.getCharacters());

        if (s != "" && mNewXML != NULL)
          mNewXML->addChild(stream.next());
        else
          stream.skipText();
      }
      else
      {
        stream.skipPastEnd(stream.next());
      }
    }

    if (mNewXML != NULL && mNewXML->getNumChildren() == 1)
    {
      // for convenience if we have just one element hide the nesting
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* copy = new
        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(mNewXML->getChild(0));
      delete mNewXML;
      mNewXML = copy;
    }

    if (mNewXML == NULL && !newElementText.empty())
      mNewXML = new
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(newElementText);

    read = true;
  }

  if (SedChange::readOtherXML(stream))
  {
    read = true;
  }

  return read;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedAddXML::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedChange::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedAddXML_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedAddXML_t *
SedAddXML_create(unsigned int level, unsigned int version)
{
  return new SedAddXML(level, version);
}


/*
 * Creates and returns a deep copy of this SedAddXML_t object.
 */
LIBSEDML_EXTERN
SedAddXML_t*
SedAddXML_clone(const SedAddXML_t* saxml)
{
  if (saxml != NULL)
  {
    return static_cast<SedAddXML_t*>(saxml->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAddXML_t object.
 */
LIBSEDML_EXTERN
void
SedAddXML_free(SedAddXML_t* saxml)
{
  if (saxml != NULL)
  {
    delete saxml;
  }
}


/*
 * Returns the value of the "newXML" element of this SedAddXML_t.
 */
LIBSEDML_EXTERN
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*
SedAddXML_getNewXML(const SedAddXML_t * saxml)
{
  if (saxml == NULL)
  {
    return NULL;
  }

  return (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t*)(saxml->getNewXML());
}


/*
 * Predicate returning @c 1 (true) if this SedAddXML_t's "newXML" element is
 * set.
 */
LIBSEDML_EXTERN
int
SedAddXML_isSetNewXML(const SedAddXML_t * saxml)
{
  return (saxml != NULL) ? static_cast<int>(saxml->isSetNewXML()) : 0;
}


/*
 * Sets the value of the "newXML" element of this SedAddXML_t.
 */
LIBSEDML_EXTERN
int
SedAddXML_setNewXML(SedAddXML_t * saxml,
                    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode_t* newXML)
{
  return (saxml != NULL) ? saxml->setNewXML(newXML) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "newXML" element of this SedAddXML_t.
 */
LIBSEDML_EXTERN
int
SedAddXML_unsetNewXML(SedAddXML_t * saxml)
{
  return (saxml != NULL) ? saxml->unsetNewXML() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedAddXML_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAddXML_hasRequiredAttributes(const SedAddXML_t * saxml)
{
  return (saxml != NULL) ? static_cast<int>(saxml->hasRequiredAttributes()) :
    0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SedAddXML_t object have been set.
 */
LIBSEDML_EXTERN
int
SedAddXML_hasRequiredElements(const SedAddXML_t * saxml)
{
  return (saxml != NULL) ? static_cast<int>(saxml->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


