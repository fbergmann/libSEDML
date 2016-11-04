/**
 * @file:   SedDataSource.cpp
 * @brief:  Implementation of the SedDataSource class
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


#include <sedml/SedDataSource.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedDataSource with the given level, version, and package version.
 */
SedDataSource::SedDataSource(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mId("")
  , mName("")
  , mIndexSet("")
  , mSlices(level, version)

{
  // set an SedNamespaces derived object of this package
  setSedNamespacesAndOwn(new SedNamespaces(level, version));

  // connect to child objects
  connectToChild();
}


/*
 * Creates a new SedDataSource with the given SedNamespaces object.
 */
SedDataSource::SedDataSource(SedNamespaces* sedns)
  : SedBase(sedns)
  , mId("")
  , mName("")
  , mIndexSet("")
  , mSlices(sedns)

{
  // set the element namespace of this object
  setElementNamespace(sedns->getURI());

  // connect to child objects
  connectToChild();
}


/*
 * Copy constructor for SedDataSource.
 */
SedDataSource::SedDataSource(const SedDataSource& orig)
  : SedBase(orig)
{
  mId  = orig.mId;
  mName  = orig.mName;
  mIndexSet  = orig.mIndexSet;
  mSlices  = orig.mSlices;

  // connect to child objects
  connectToChild();
}


/*
 * Assignment for SedDataSource.
 */
SedDataSource&
SedDataSource::operator=(const SedDataSource& rhs)
{
  if (&rhs != this)
    {
      SedBase::operator=(rhs);
      mId  = rhs.mId;
      mName  = rhs.mName;
      mIndexSet  = rhs.mIndexSet;
      mSlices  = rhs.mSlices;

      // connect to child objects
      connectToChild();
    }

  return *this;
}


/*
 * Clone for SedDataSource.
 */
SedDataSource*
SedDataSource::clone() const
{
  return new SedDataSource(*this);
}


/*
 * Destructor for SedDataSource.
 */
SedDataSource::~SedDataSource()
{
}


/*
 * Returns the value of the "id" attribute of this SedDataSource.
 */
const std::string&
SedDataSource::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this SedDataSource.
 */
const std::string&
SedDataSource::getName() const
{
  return mName;
}


/*
 * Returns the value of the "indexSet" attribute of this SedDataSource.
 */
const std::string&
SedDataSource::getIndexSet() const
{
  return mIndexSet;
}


/*
 * Returns true/false if id is set.
 */
bool
SedDataSource::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedDataSource::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Returns true/false if indexSet is set.
 */
bool
SedDataSource::isSetIndexSet() const
{
  return (mIndexSet.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedDataSource::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedDataSource::setName(const std::string& name)
{
  {
    mName = name;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets indexSet and returns value indicating success.
 */
int
SedDataSource::setIndexSet(const std::string& indexSet)
{
  {
    mIndexSet = indexSet;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedDataSource::unsetId()
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
SedDataSource::unsetName()
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
 * Unsets indexSet and returns value indicating success.
 */
int
SedDataSource::unsetIndexSet()
{
  mIndexSet.erase();

  if (mIndexSet.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Returns the  "SedListOfSlices" in this SedDataSource object.
 */
const SedListOfSlices*
SedDataSource::getListOfSlices() const
{
  return &mSlices;
}


/*
 * Removes the nth Slice from the SedListOfSlices.
 */
SedSlice*
SedDataSource::removeSlice(unsigned int n)
{
  return mSlices.remove(n);
}


/*
 * Removes the a Slice with given id from the SedListOfSlices.
 */
SedSlice*
SedDataSource::removeSlice(const std::string& sid)
{
  return mSlices.remove(sid);
}


/*
 * Return the nth Slice in the SedListOfSlices within this SedDataSource.
 */
SedSlice*
SedDataSource::getSlice(unsigned int n)
{
  return mSlices.get(n);
}


/*
 * Return the nth Slice in the SedListOfSlices within this SedDataSource.
 */
const SedSlice*
SedDataSource::getSlice(unsigned int n) const
{
  return mSlices.get(n);
}


/*
 * Return a Slice from the SedListOfSlices by id.
 */
SedSlice*
SedDataSource::getSlice(const std::string& sid)
{
  return mSlices.get(sid);
}


/*
 * Return a Slice from the SedListOfSlices by id.
 */
const SedSlice*
SedDataSource::getSlice(const std::string& sid) const
{
  return mSlices.get(sid);
}


/**
 * Adds a copy the given "SedSlice" to this SedDataSource.
 *
 * @param ss; the SedSlice object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedDataSource::addSlice(const SedSlice* ss)
{
  if (ss == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;

  mSlices.append(ss);
  return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSlice objects in this SedDataSource.
 *
 * @return the number of SedSlice objects in this SedDataSource
 */
unsigned int
SedDataSource::getNumSlices() const
{
  return mSlices.size();
}

/**
 * Creates a new SedSlice object, adds it to this SedDataSources
 * SedDataSource and returns the SedSlice object created.
 *
 * @return a new SedSlice object instance
 *
 * @see addSedSlice(const SedSlice* ss)
 */
SedSlice*
SedDataSource::createSlice()
{
  SedSlice *temp = new SedSlice();

  if (temp != NULL) mSlices.appendAndOwn(temp);

  return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedDataSource::getElementName() const
{
  static const string name = "dataSource";
  return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedDataSource::createObject(XMLInputStream& stream)
{
  SedBase* object = NULL;

  const string& name   = stream.peek().getName();

  if (name == "listOfSlices")
    {
      object = &mSlices;
    }

  connectToChild();

  return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedDataSource::connectToChild()
{
  SedBase::connectToChild();

  mSlices.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedDataSource::getTypeCode() const
{
  return SEDML_DATA_SOURCE;
}


/*
 * check if all the required attributes are set
 */
bool
SedDataSource::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
    allPresent = false;

  return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedDataSource::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedDataSource::writeElements(XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (getNumSlices() > 0)
    {
      mSlices.write(stream);
    }
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedDataSource::accept(SedVisitor& v) const
{
  return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedDataSource::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
  mSlices.setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedDataSource::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");
  attributes.add("name");
  attributes.add("indexSet");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedDataSource::readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes)
{
  SedBase::readAttributes(attributes, expectedAttributes);

  bool assigned = false;

  //
  // id SId  ( use = "optional" )
  //
  assigned = attributes.readInto("id", mId, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty and correct syntax

      if (mId.empty() == true)
        {
          logEmptyString(mId, getLevel(), getVersion(), "<SedDataSource>");
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
          logEmptyString(mName, getLevel(), getVersion(), "<SedDataSource>");
        }
    }

  //
  // indexSet string   ( use = "optional" )
  //
  assigned = attributes.readInto("indexSet", mIndexSet, getErrorLog(), false);

  if (assigned == true)
    {
      // check string is not empty

      if (mIndexSet.empty() == true)
        {
          logEmptyString(mIndexSet, getLevel(), getVersion(), "<SedDataSource>");
        }
    }

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
void
SedDataSource::writeAttributes(XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
    stream.writeAttribute("id", getPrefix(), mId);

  if (isSetName() == true)
    stream.writeAttribute("name", getPrefix(), mName);

  if (isSetIndexSet() == true)
    stream.writeAttribute("indexSet", getPrefix(), mIndexSet);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor
 */
SedListOfDataSources::SedListOfDataSources(unsigned int level,
    unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Constructor
 */
SedListOfDataSources::SedListOfDataSources(SedNamespaces* sedns)
  : SedListOf(sedns)
{
  setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfDataSources
 */
SedListOfDataSources*
SedListOfDataSources::clone() const
{
  return new SedListOfDataSources(*this);
}


/*
 * Get a DataSource from the SedListOfDataSources by index.
*/
SedDataSource*
SedListOfDataSources::get(unsigned int n)
{
  return static_cast<SedDataSource*>(SedListOf::get(n));
}


/*
 * Get a DataSource from the SedListOfDataSources by index.
 */
const SedDataSource*
SedListOfDataSources::get(unsigned int n) const
{
  return static_cast<const SedDataSource*>(SedListOf::get(n));
}


/*
 * Get a DataSource from the SedListOfDataSources by id.
 */
SedDataSource*
SedListOfDataSources::get(const std::string& sid)
{
  return const_cast<SedDataSource*>(
           static_cast<const SedListOfDataSources&>(*this).get(sid));
}


/*
 * Get a DataSource from the SedListOfDataSources by id.
 */
const SedDataSource*
SedListOfDataSources::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedDataSource>(sid));
  return (result == mItems.end()) ? 0 : static_cast <SedDataSource*>(*result);
}


/**
 * Adds a copy the given "SedDataSource" to this SedListOfDataSources.
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
SedListOfDataSources::addDataSource(const SedDataSource* sds)
{
  if (sds == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;

  append(sds);
  return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedDataSource objects in this SedListOfDataSources.
 *
 * @return the number of SedDataSource objects in this SedListOfDataSources
 */
unsigned int
SedListOfDataSources::getNumDataSources() const
{
  return size();
}

/**
 * Creates a new SedDataSource object, adds it to this SedListOfDataSourcess
 * SedDataSource and returns the SedDataSource object created.
 *
 * @return a new SedDataSource object instance
 *
 * @see addSedDataSource(const SedDataSource* sds)
 */
SedDataSource*
SedListOfDataSources::createDataSource()
{
  SedDataSource *temp = new SedDataSource();

  if (temp != NULL) appendAndOwn(temp);

  return temp;
}

/*
 * Removes the nth DataSource from this SedListOfDataSources
 */
SedDataSource*
SedListOfDataSources::remove(unsigned int n)
{
  return static_cast<SedDataSource*>(SedListOf::remove(n));
}


/*
 * Removes the DataSource from this SedListOfDataSources with the given identifier
 */
SedDataSource*
SedListOfDataSources::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedDataSource>(sid));

  if (result != mItems.end())
    {
      item = *result;
      mItems.erase(result);
    }

  return static_cast <SedDataSource*>(item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfDataSources::getElementName() const
{
  static const string name = "listOfDataSources";
  return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfDataSources::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfDataSources::getItemTypeCode() const
{
  return SEDML_DATA_SOURCE;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedDataSource in this SedListOfDataSources
 */
SedBase*
SedListOfDataSources::createObject(XMLInputStream& stream)
{
  const std::string& name   = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "dataSource")
    {
      object = new SedDataSource(getSedNamespaces());
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
SedListOfDataSources::writeXMLNS(XMLOutputStream& stream) const
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
SedDataSource_t *
SedDataSource_create(unsigned int level, unsigned int version)
{
  return new SedDataSource(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedDataSource_free(SedDataSource_t * sds)
{
  if (sds != NULL)
    delete sds;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataSource_t *
SedDataSource_clone(SedDataSource_t * sds)
{
  if (sds != NULL)
    {
      return static_cast<SedDataSource_t*>(sds->clone());
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
SedDataSource_getId(SedDataSource_t * sds)
{
  if (sds == NULL)
    return NULL;

  return sds->getId().empty() ? NULL : safe_strdup(sds->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataSource_getName(SedDataSource_t * sds)
{
  if (sds == NULL)
    return NULL;

  return sds->getName().empty() ? NULL : safe_strdup(sds->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataSource_getIndexSet(SedDataSource_t * sds)
{
  if (sds == NULL)
    return NULL;

  return sds->getIndexSet().empty() ? NULL : safe_strdup(sds->getIndexSet().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetId(SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetName(SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_isSetIndexSet(SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->isSetIndexSet()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_setId(SedDataSource_t * sds, const char * id)
{
  return (sds != NULL) ? sds->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_setName(SedDataSource_t * sds, const char * name)
{
  return (sds != NULL) ? sds->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_setIndexSet(SedDataSource_t * sds, const char * indexSet)
{
  return (sds != NULL) ? sds->setIndexSet(indexSet) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetId(SedDataSource_t * sds)
{
  return (sds != NULL) ? sds->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetName(SedDataSource_t * sds)
{
  return (sds != NULL) ? sds->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_unsetIndexSet(SedDataSource_t * sds)
{
  return (sds != NULL) ? sds->unsetIndexSet() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedDataSource_addSlice(SedDataSource_t * sds, SedSlice_t * ss)
{
  return (sds != NULL) ? sds->addSlice(ss) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_createSlice(SedDataSource_t * sds)
{
  return (sds != NULL) ? sds->createSlice() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDataSource_getSedListOfSlices(SedDataSource_t * sds)
{
  return (sds != NULL) ? (SedListOf_t *)sds->getListOfSlices() : NULL;
}

LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_getSlice(SedDataSource_t * sds, unsigned int n)
{
  return (sds != NULL) ? sds->getSlice(n) : NULL;
}

LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_getSliceById(SedDataSource_t * sds, const char * sid)
{
  return (sds != NULL) ? sds->getSlice(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDataSource_getNumSlices(SedDataSource_t * sds)
{
  return (sds != NULL) ? sds->getNumSlices() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_removeSlice(SedDataSource_t * sds, unsigned int n)
{
  return (sds != NULL) ? sds->removeSlice(n) : NULL;
}

LIBSEDML_EXTERN
SedSlice_t *
SedDataSource_removeSliceById(SedDataSource_t * sds, const char * sid)
{
  return (sds != NULL) ? sds->removeSlice(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_hasRequiredAttributes(SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSource_hasRequiredElements(SedDataSource_t * sds)
{
  return (sds != NULL) ? static_cast<int>(sds->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataSource_t *
SedListOfDataSources_getById(SedListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <SedListOfDataSources *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataSource_t *
SedListOfDataSources_removeById(SedListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <SedListOfDataSources *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


