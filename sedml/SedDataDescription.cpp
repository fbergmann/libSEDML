/**
 * @file:   SedDataDescription.cpp
 * @brief:  Implementation of the SedDataDescription class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 *
 * Copyright (c) 2013-2016, Frank T. Bergmann
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
 * ------------------------------------------------------------------------ -->
 */


#include <sedml/SedDataDescription.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>

#include <numl/DimensionDescription.h>

using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedDataDescription with the given level, version, and package version.
 */
SedDataDescription::SedDataDescription(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mId("")
  , mName("")
  , mSource("")
  , mDimensionDescription(NULL)
  , mDataSources(level, version)

{
  // set an SedNamespaces derived object of this package
  setSedNamespacesAndOwn(new SedNamespaces(level, version));

  // connect to child objects
  connectToChild();
}


/*
 * Creates a new SedDataDescription with the given SedNamespaces object.
 */
SedDataDescription::SedDataDescription(SedNamespaces* sedns)
  : SedBase(sedns)
  , mId("")
  , mName("")
  , mSource("")
  , mDimensionDescription(NULL)
  , mDataSources(sedns)

{
  // set the element namespace of this object
  setElementNamespace(sedns->getURI());

  // connect to child objects
  connectToChild();
}


/*
 * Copy constructor for SedDataDescription.
 */
SedDataDescription::SedDataDescription(const SedDataDescription& orig)
  : SedBase(orig)
{
  mId  = orig.mId;
  mName  = orig.mName;
  mSource  = orig.mSource;
  mDimensionDescription  = orig.mDimensionDescription != NULL ? orig.mDimensionDescription->clone() : NULL;
  mDataSources  = orig.mDataSources;

  // connect to child objects
  connectToChild();
}


/*
 * Assignment for SedDataDescription.
 */
SedDataDescription&
SedDataDescription::operator=(const SedDataDescription& rhs)
{
  if (&rhs != this)
    {
      SedBase::operator=(rhs);
      mId  = rhs.mId;
      mName  = rhs.mName;
      mSource  = rhs.mSource;
      mDimensionDescription  = rhs.mDimensionDescription != NULL ? rhs.mDimensionDescription->clone() : NULL;
      mDataSources  = rhs.mDataSources;

      // connect to child objects
      connectToChild();
    }

  return *this;
}


/*
 * Clone for SedDataDescription.
 */
SedDataDescription*
SedDataDescription::clone() const
{
  return new SedDataDescription(*this);
}


/*
 * Destructor for SedDataDescription.
 */
SedDataDescription::~SedDataDescription()
{
}


/*
 * Returns the value of the "id" attribute of this SedDataDescription.
 */
const std::string&
SedDataDescription::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this SedDataDescription.
 */
const std::string&
SedDataDescription::getName() const
{
  return mName;
}


/*
 * Returns the value of the "source" attribute of this SedDataDescription.
 */
const std::string&
SedDataDescription::getSource() const
{
  return mSource;
}


/*
 * Returns the value of the "dimensionDescription" attribute of this SedDataDescription.
 */
const DimensionDescription*
SedDataDescription::getDimensionDescription() const
{
  return mDimensionDescription;
}


/*
 * Creates a new "dimensionDescription" element of this SedDataDescription and returns it.
 */
DimensionDescription*
SedDataDescription::createDimensionDescription()
{
  if (mDimensionDescription != NULL)
    delete mDimensionDescription;

  mDimensionDescription = new DimensionDescription();
  return mDimensionDescription;
}


/*
 * Returns true/false if id is set.
 */
bool
SedDataDescription::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedDataDescription::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Returns true/false if source is set.
 */
bool
SedDataDescription::isSetSource() const
{
  return (mSource.empty() == false);
}


/*
 * Returns true/false if dimensionDescription is set.
 */
bool
SedDataDescription::isSetDimensionDescription() const
{
  return (mDimensionDescription != NULL);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedDataDescription::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedDataDescription::setName(const std::string& name)
{
  {
    mName = name;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets source and returns value indicating success.
 */
int
SedDataDescription::setSource(const std::string& source)
{
  {
    mSource = source;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets dimensionDescription and returns value indicating success.
 */
int
SedDataDescription::setDimensionDescription(DimensionDescription* dimensionDescription)
{
  if (mDimensionDescription == dimensionDescription)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else if (dimensionDescription == NULL)
    {
      delete mDimensionDescription;
      mDimensionDescription = NULL;
      return LIBSEDML_OPERATION_SUCCESS;
    }

  delete mDimensionDescription;
  mDimensionDescription = (dimensionDescription != NULL) ?
                          dimensionDescription->clone() : NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedDataDescription::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets name and returns value indicating success.
 */
int
SedDataDescription::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets source and returns value indicating success.
 */
int
SedDataDescription::unsetSource()
{
  mSource.erase();

  if (mSource.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets dimensionDescription and returns value indicating success.
 */
int
SedDataDescription::unsetDimensionDescription()
{
  delete mDimensionDescription;
  mDimensionDescription = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfDataSources" in this SedDataDescription object.
 */
const SedListOfDataSources*
SedDataDescription::getListOfDataSources() const
{
  return &mDataSources;
}


/*
 * Removes the nth DataSource from the SedListOfDataSources.
 */
SedDataSource*
SedDataDescription::removeDataSource(unsigned int n)
{
  return mDataSources.remove(n);
}


/*
 * Removes the a DataSource with given id from the SedListOfDataSources.
 */
SedDataSource*
SedDataDescription::removeDataSource(const std::string& sid)
{
  return mDataSources.remove(sid);
}


/*
 * Return the nth DataSource in the SedListOfDataSources within this SedDataDescription.
 */
SedDataSource*
SedDataDescription::getDataSource(unsigned int n)
{
  return mDataSources.get(n);
}


/*
 * Return the nth DataSource in the SedListOfDataSources within this SedDataDescription.
 */
const SedDataSource*
SedDataDescription::getDataSource(unsigned int n) const
{
  return mDataSources.get(n);
}


/*
 * Return a DataSource from the SedListOfDataSources by id.
 */
SedDataSource*
SedDataDescription::getDataSource(const std::string& sid)
{
  return mDataSources.get(sid);
}


/*
 * Return a DataSource from the SedListOfDataSources by id.
 */
const SedDataSource*
SedDataDescription::getDataSource(const std::string& sid) const
{
  return mDataSources.get(sid);
}


/**
 * Adds a copy the given "SedDataSource" to this SedDataDescription.
 *
 * @param sds; the SedDataSource object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedDataDescription::addDataSource(const SedDataSource* sds)
{
  if (sds == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;

  mDataSources.append(sds);
  return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedDataSource objects in this SedDataDescription.
 *
 * @return the number of SedDataSource objects in this SedDataDescription
 */
unsigned int
SedDataDescription::getNumDataSources() const
{
  return mDataSources.size();
}

/**
 * Creates a new SedDataSource object, adds it to this SedDataDescriptions
 * SedDataDescription and returns the SedDataSource object created.
 *
 * @return a new SedDataSource object instance
 *
 * @see addSedDataSource(const SedDataSource* sds)
 */
SedDataSource*
SedDataDescription::createDataSource()
{
  SedDataSource *temp = new SedDataSource();

  if (temp != NULL) mDataSources.appendAndOwn(temp);

  return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedDataDescription::getElementName() const
{
  static const string name = "dataDescription";
  return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedDataDescription::createObject(XMLInputStream& stream)
{
  SedBase* object = NULL;

  const string& name   = stream.peek().getName();

  if (name == "listOfDataSources")
    {
      object = &mDataSources;
    }

  connectToChild();

  return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedDataDescription::connectToChild()
{
  SedBase::connectToChild();

  mDataSources.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedDataDescription::getTypeCode() const
{
  return SEDML_DATA_DESCRIPTION;
}


/*
 * check if all the required attributes are set
 */
bool
SedDataDescription::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
    allPresent = false;

  if (isSetDimensionDescription() == false)
    allPresent = false;

  return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedDataDescription::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedDataDescription::writeElements(XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (getNumDataSources() > 0)
    {
      mDataSources.write(stream);
    }

  if (isSetDimensionDescription() == true)
    {
      mDimensionDescription->write(stream);
    }
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedDataDescription::accept(SedVisitor& v) const
{
  return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedDataDescription::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
  mDataSources.setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedDataDescription::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");
  attributes.add("name");
  attributes.add("source");
  attributes.add("dimensionDescription");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedDataDescription::readAttributes(const XMLAttributes& attributes,
                                   const ExpectedAttributes& expectedAttributes)
{
  SedBase::readAttributes(attributes, expectedAttributes);

  bool assigned = false;

  //
  // id SId  ( use = "required" )
  //
  assigned = attributes.readInto("id", mId, getErrorLog(), true);

  if (assigned == true)
    {
      // check string is not empty and correct syntax

      if (mId.empty() == true)
        {
          logEmptyString(mId, getLevel(), getVersion(), "<SedDataDescription>");
        }
      else if (SyntaxChecker::isValidSBMLSId(mId) == false)
        {
          logError(SedInvalidIdSyntax);
        }
    }

  //
  // name string   ( use = "optional" )
  //
  assigned = attributes.readInto("name", mName, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty

      if (mName.empty() == true)
        {
          logEmptyString(mName, getLevel(), getVersion(), "<SedDataDescription>");
        }
    }

  //
  // source string   ( use = "optional" )
  //
  assigned = attributes.readInto("source", mSource, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty

      if (mSource.empty() == true)
        {
          logEmptyString(mSource, getLevel(), getVersion(), "<SedDataDescription>");
        }
    }

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

bool
SedDataDescription::readOtherXML(XMLInputStream& stream)
{
  bool          read = false;
  const string& name = stream.peek().getName();

  if (name == "dimensionDescription")
    {
      const XMLToken& token = stream.next();
      stream.skipText();
      mDimensionDescription = new DimensionDescription();
      mDimensionDescription->read(stream);
      stream.skipPastEnd(token);
      read = true;
    }

  if (SedBase::readOtherXML(stream))
    {
      read = true;
    }

  return read;
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
void
SedDataDescription::writeAttributes(XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
    stream.writeAttribute("id", getPrefix(), mId);

  if (isSetName() == true)
    stream.writeAttribute("name", getPrefix(), mName);

  if (isSetSource() == true)
    stream.writeAttribute("source", getPrefix(), mSource);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor
 */
SedListOfDataDescriptions::SedListOfDataDescriptions(unsigned int level,
    unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Constructor
 */
SedListOfDataDescriptions::SedListOfDataDescriptions(SedNamespaces* sedns)
  : SedListOf(sedns)
{
  setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfDataDescriptions
 */
SedListOfDataDescriptions*
SedListOfDataDescriptions::clone() const
{
  return new SedListOfDataDescriptions(*this);
}


/*
 * Get a DataDescription from the SedListOfDataDescriptions by index.
*/
SedDataDescription*
SedListOfDataDescriptions::get(unsigned int n)
{
  return static_cast<SedDataDescription*>(SedListOf::get(n));
}


/*
 * Get a DataDescription from the SedListOfDataDescriptions by index.
 */
const SedDataDescription*
SedListOfDataDescriptions::get(unsigned int n) const
{
  return static_cast<const SedDataDescription*>(SedListOf::get(n));
}


/*
 * Get a DataDescription from the SedListOfDataDescriptions by id.
 */
SedDataDescription*
SedListOfDataDescriptions::get(const std::string& sid)
{
  return const_cast<SedDataDescription*>(
           static_cast<const SedListOfDataDescriptions&>(*this).get(sid));
}


/*
 * Get a DataDescription from the SedListOfDataDescriptions by id.
 */
const SedDataDescription*
SedListOfDataDescriptions::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedDataDescription>(sid));
  return (result == mItems.end()) ? 0 : static_cast <SedDataDescription*>(*result);
}


/**
 * Adds a copy the given "SedDataDescription" to this SedListOfDataDescriptions.
 *
 * @param sdd; the SedDataDescription object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfDataDescriptions::addDataDescription(const SedDataDescription* sdd)
{
  if (sdd == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;

  append(sdd);
  return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedDataDescription objects in this SedListOfDataDescriptions.
 *
 * @return the number of SedDataDescription objects in this SedListOfDataDescriptions
 */
unsigned int
SedListOfDataDescriptions::getNumDataDescriptions() const
{
  return size();
}

/**
 * Creates a new SedDataDescription object, adds it to this SedListOfDataDescriptionss
 * SedDataDescription and returns the SedDataDescription object created.
 *
 * @return a new SedDataDescription object instance
 *
 * @see addSedDataDescription(const SedDataDescription* sdd)
 */
SedDataDescription*
SedListOfDataDescriptions::createDataDescription()
{
  SedDataDescription *temp = new SedDataDescription();

  if (temp != NULL) appendAndOwn(temp);

  return temp;
}

/*
 * Removes the nth DataDescription from this SedListOfDataDescriptions
 */
SedDataDescription*
SedListOfDataDescriptions::remove(unsigned int n)
{
  return static_cast<SedDataDescription*>(SedListOf::remove(n));
}


/*
 * Removes the DataDescription from this SedListOfDataDescriptions with the given identifier
 */
SedDataDescription*
SedListOfDataDescriptions::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedDataDescription>(sid));

  if (result != mItems.end())
    {
      item = *result;
      mItems.erase(result);
    }

  return static_cast <SedDataDescription*>(item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfDataDescriptions::getElementName() const
{
  static const string name = "listOfDataDescriptions";
  return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfDataDescriptions::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfDataDescriptions::getItemTypeCode() const
{
  return SEDML_DATA_DESCRIPTION;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedDataDescription in this SedListOfDataDescriptions
 */
SedBase*
SedListOfDataDescriptions::createObject(XMLInputStream& stream)
{
  const std::string& name   = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "dataDescription")
    {
      object = new SedDataDescription(getSedNamespaces());
      appendAndOwn(object);
    }

  return object;
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write the namespace for the Sed package.
 */
void
SedListOfDataDescriptions::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;

  std::string prefix = getPrefix();

  if (prefix.empty())
    {
      if (getNamespaces() != NULL && !getNamespaces()->hasURI(SEDML_XMLNS_L1) && !getNamespaces()->hasURI(SEDML_XMLNS_L1V2) && !getNamespaces()->hasURI(SEDML_XMLNS_L1V3))
        {
          if (getVersion() == 2) xmlns.add(SEDML_XMLNS_L1V2, prefix);
          else if (getVersion() == 3) xmlns.add(SEDML_XMLNS_L1V3, prefix);
          else xmlns.add(SEDML_XMLNS_L1V2, prefix);
        }
    }

  stream << xmlns;
}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataDescription_t *
SedDataDescription_create(unsigned int level, unsigned int version)
{
  return new SedDataDescription(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedDataDescription_free(SedDataDescription_t * sdd)
{
  if (sdd != NULL)
    delete sdd;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataDescription_t *
SedDataDescription_clone(SedDataDescription_t * sdd)
{
  if (sdd != NULL)
    {
      return static_cast<SedDataDescription_t*>(sdd->clone());
    }
  else
    {
      return NULL;
    }
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getId(SedDataDescription_t * sdd)
{
  if (sdd == NULL)
    return NULL;

  return sdd->getId().empty() ? NULL : safe_strdup(sdd->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getName(SedDataDescription_t * sdd)
{
  if (sdd == NULL)
    return NULL;

  return sdd->getName().empty() ? NULL : safe_strdup(sdd->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataDescription_getSource(SedDataDescription_t * sdd)
{
  if (sdd == NULL)
    return NULL;

  return sdd->getSource().empty() ? NULL : safe_strdup(sdd->getSource().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
DimensionDescription*
SedDataDescription_getDimensionDescription(SedDataDescription_t * sdd)
{
  return sdd == NULL ? NULL : const_cast<DimensionDescription*>(sdd->getDimensionDescription());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetId(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetName(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetSource(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetSource()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_isSetDimensionDescription(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->isSetDimensionDescription()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_setId(SedDataDescription_t * sdd, const char * id)
{
  return (sdd != NULL) ? sdd->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_setName(SedDataDescription_t * sdd, const char * name)
{
  return (sdd != NULL) ? sdd->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_setSource(SedDataDescription_t * sdd, const char * source)
{
  return (sdd != NULL) ? sdd->setSource(source) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_setDimensionDescription(SedDataDescription_t * sdd, DimensionDescription* dimensionDescription)
{
  return (sdd != NULL) ? sdd->setDimensionDescription(dimensionDescription) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetId(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetName(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetSource(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetSource() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_unsetDimensionDescription(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->unsetDimensionDescription() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedDataDescription_addDataSource(SedDataDescription_t * sdd, SedDataSource_t * sds)
{
  return (sdd != NULL) ? sdd->addDataSource(sds) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_createDataSource(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->createDataSource() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDataDescription_getSedListOfDataSources(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? (SedListOf_t *)sdd->getListOfDataSources() : NULL;
}

LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_getDataSource(SedDataDescription_t * sdd, unsigned int n)
{
  return (sdd != NULL) ? sdd->getDataSource(n) : NULL;
}

LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_getDataSourceById(SedDataDescription_t * sdd, const char * sid)
{
  return (sdd != NULL) ? sdd->getDataSource(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDataDescription_getNumDataSources(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? sdd->getNumDataSources() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_removeDataSource(SedDataDescription_t * sdd, unsigned int n)
{
  return (sdd != NULL) ? sdd->removeDataSource(n) : NULL;
}

LIBSEDML_EXTERN
SedDataSource_t *
SedDataDescription_removeDataSourceById(SedDataDescription_t * sdd, const char * sid)
{
  return (sdd != NULL) ? sdd->removeDataSource(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_hasRequiredAttributes(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataDescription_hasRequiredElements(SedDataDescription_t * sdd)
{
  return (sdd != NULL) ? static_cast<int>(sdd->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataDescription_t *
SedListOfDataDescriptions_getById(SedListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <SedListOfDataDescriptions *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataDescription_t *
SedListOfDataDescriptions_removeById(SedListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <SedListOfDataDescriptions *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


