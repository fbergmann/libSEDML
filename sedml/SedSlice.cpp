/**
 * @file:   SedSlice.cpp
 * @brief:  Implementation of the SedSlice class
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


#include <sedml/SedSlice.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedSlice with the given level, version, and package version.
 */
SedSlice::SedSlice(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mReference("")
  , mValue("")

{
  // set an SedNamespaces derived object of this package
  setSedNamespacesAndOwn(new SedNamespaces(level, version));

  // connect to child objects
  connectToChild();
}


/*
 * Creates a new SedSlice with the given SedNamespaces object.
 */
SedSlice::SedSlice(SedNamespaces* sedns)
  : SedBase(sedns)
  , mReference("")
  , mValue("")

{
  // set the element namespace of this object
  setElementNamespace(sedns->getURI());

  // connect to child objects
  connectToChild();
}


/*
 * Copy constructor for SedSlice.
 */
SedSlice::SedSlice(const SedSlice& orig)
  : SedBase(orig)
{
  mReference  = orig.mReference;
  mValue  = orig.mValue;

  // connect to child objects
  connectToChild();
}


/*
 * Assignment for SedSlice.
 */
SedSlice&
SedSlice::operator=(const SedSlice& rhs)
{
  if (&rhs != this)
    {
      SedBase::operator=(rhs);
      mReference  = rhs.mReference;
      mValue  = rhs.mValue;

      // connect to child objects
      connectToChild();
    }

  return *this;
}


/*
 * Clone for SedSlice.
 */
SedSlice*
SedSlice::clone() const
{
  return new SedSlice(*this);
}


/*
 * Destructor for SedSlice.
 */
SedSlice::~SedSlice()
{
}


/*
 * Returns the value of the "reference" attribute of this SedSlice.
 */
const std::string&
SedSlice::getReference() const
{
  return mReference;
}


/*
 * Returns the value of the "value" attribute of this SedSlice.
 */
const std::string&
SedSlice::getValue() const
{
  return mValue;
}


/*
 * Returns true/false if reference is set.
 */
bool
SedSlice::isSetReference() const
{
  return (mReference.empty() == false);
}


/*
 * Returns true/false if value is set.
 */
bool
SedSlice::isSetValue() const
{
  return (mValue.empty() == false);
}


/*
 * Sets reference and returns value indicating success.
 */
int
SedSlice::setReference(const std::string& reference)
{
  if (!(SyntaxChecker::isValidInternalSId(reference)))
    {
      return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
    }
  else
    {
      mReference = reference;
      return LIBSEDML_OPERATION_SUCCESS;
    }
}


/*
 * Sets value and returns value indicating success.
 */
int
SedSlice::setValue(const std::string& value)
{
  {
    mValue = value;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets reference and returns value indicating success.
 */
int
SedSlice::unsetReference()
{
  mReference.erase();

  if (mReference.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Unsets value and returns value indicating success.
 */
int
SedSlice::unsetValue()
{
  mValue.erase();

  if (mValue.empty() == true)
    {
      return LIBSEDML_OPERATION_SUCCESS;
    }
  else
    {
      return LIBSEDML_OPERATION_FAILED;
    }
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedSlice::getElementName() const
{
  static const string name = "slice";
  return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedSlice::createObject(XMLInputStream& stream)
{
  SedBase* object = NULL;

  const string& name   = stream.peek().getName();

  connectToChild();

  return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedSlice::connectToChild()
{
  SedBase::connectToChild();

}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedSlice::getTypeCode() const
{
  return SEDML_DATA_SLICE;
}


/*
 * check if all the required attributes are set
 */
bool
SedSlice::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetReference() == false)
    allPresent = false;

  if (isSetValue() == false)
    allPresent = false;

  return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedSlice::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedSlice::writeElements(XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedSlice::accept(SedVisitor& v) const
{
  return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedSlice::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedSlice::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("reference");
  attributes.add("value");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedSlice::readAttributes(const XMLAttributes& attributes,
                         const ExpectedAttributes& expectedAttributes)
{
  SedBase::readAttributes(attributes, expectedAttributes);

  bool assigned = false;

  //
  // reference SIdRef   ( use = "required" )
  //
  assigned = attributes.readInto("reference", mReference, getErrorLog(), true);

  if (assigned == true)
    {
      // check string is not empty and correct syntax

      if (mReference.empty() == true)
        {
          logEmptyString(mReference, getLevel(), getVersion(), "<SedSlice>");
        }
      else if (SyntaxChecker::isValidSBMLSId(mReference) == false)
        {
          logError(SedInvalidIdSyntax);
        }
    }

  //
  // value string   ( use = "required" )
  //
  assigned = attributes.readInto("value", mValue, getErrorLog(), true);

  if (assigned == true)
    {
      // check string is not empty

      if (mValue.empty() == true)
        {
          logEmptyString(mValue, getLevel(), getVersion(), "<SedSlice>");
        }
    }

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
void
SedSlice::writeAttributes(XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetReference() == true)
    stream.writeAttribute("reference", getPrefix(), mReference);

  if (isSetValue() == true)
    stream.writeAttribute("value", getPrefix(), mValue);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor
 */
SedListOfSlices::SedListOfSlices(unsigned int level,
                                 unsigned int version)
  : SedListOf(level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Constructor
 */
SedListOfSlices::SedListOfSlices(SedNamespaces* sedns)
  : SedListOf(sedns)
{
  setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSlices
 */
SedListOfSlices*
SedListOfSlices::clone() const
{
  return new SedListOfSlices(*this);
}


/*
 * Get a Slice from the SedListOfSlices by index.
*/
SedSlice*
SedListOfSlices::get(unsigned int n)
{
  return static_cast<SedSlice*>(SedListOf::get(n));
}


/*
 * Get a Slice from the SedListOfSlices by index.
 */
const SedSlice*
SedListOfSlices::get(unsigned int n) const
{
  return static_cast<const SedSlice*>(SedListOf::get(n));
}


/*
 * Get a Slice from the SedListOfSlices by id.
 */
SedSlice*
SedListOfSlices::get(const std::string& sid)
{
  return const_cast<SedSlice*>(
           static_cast<const SedListOfSlices&>(*this).get(sid));
}


/*
 * Get a Slice from the SedListOfSlices by id.
 */
const SedSlice*
SedListOfSlices::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSlice>(sid));
  return (result == mItems.end()) ? 0 : static_cast <SedSlice*>(*result);
}


/**
 * Adds a copy the given "SedSlice" to this SedListOfSlices.
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
SedListOfSlices::addSlice(const SedSlice* ss)
{
  if (ss == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;

  append(ss);
  return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSlice objects in this SedListOfSlices.
 *
 * @return the number of SedSlice objects in this SedListOfSlices
 */
unsigned int
SedListOfSlices::getNumSlices() const
{
  return size();
}

/**
 * Creates a new SedSlice object, adds it to this SedListOfSlicess
 * SedSlice and returns the SedSlice object created.
 *
 * @return a new SedSlice object instance
 *
 * @see addSedSlice(const SedSlice* ss)
 */
SedSlice*
SedListOfSlices::createSlice()
{
  SedSlice *temp = new SedSlice();

  if (temp != NULL) appendAndOwn(temp);

  return temp;
}

/*
 * Removes the nth Slice from this SedListOfSlices
 */
SedSlice*
SedListOfSlices::remove(unsigned int n)
{
  return static_cast<SedSlice*>(SedListOf::remove(n));
}


/*
 * Removes the Slice from this SedListOfSlices with the given identifier
 */
SedSlice*
SedListOfSlices::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedSlice>(sid));

  if (result != mItems.end())
    {
      item = *result;
      mItems.erase(result);
    }

  return static_cast <SedSlice*>(item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSlices::getElementName() const
{
  static const string name = "listOfSlices";
  return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSlices::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSlices::getItemTypeCode() const
{
  return SEDML_DATA_SLICE;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedSlice in this SedListOfSlices
 */
SedBase*
SedListOfSlices::createObject(XMLInputStream& stream)
{
  const std::string& name   = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "slice")
    {
      object = new SedSlice(getSedNamespaces());
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
SedListOfSlices::writeXMLNS(XMLOutputStream& stream) const
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
SedSlice_t *
SedSlice_create(unsigned int level, unsigned int version)
{
  return new SedSlice(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedSlice_free(SedSlice_t * ss)
{
  if (ss != NULL)
    delete ss;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSlice_t *
SedSlice_clone(SedSlice_t * ss)
{
  if (ss != NULL)
    {
      return static_cast<SedSlice_t*>(ss->clone());
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
SedSlice_getReference(SedSlice_t * ss)
{
  if (ss == NULL)
    return NULL;

  return ss->getReference().empty() ? NULL : safe_strdup(ss->getReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedSlice_getValue(SedSlice_t * ss)
{
  if (ss == NULL)
    return NULL;

  return ss->getValue().empty() ? NULL : safe_strdup(ss->getValue().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSlice_isSetReference(SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSlice_isSetValue(SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetValue()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSlice_setReference(SedSlice_t * ss, const char * reference)
{
  return (ss != NULL) ? ss->setReference(reference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSlice_setValue(SedSlice_t * ss, const char * value)
{
  return (ss != NULL) ? ss->setValue(value) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSlice_unsetReference(SedSlice_t * ss)
{
  return (ss != NULL) ? ss->unsetReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSlice_unsetValue(SedSlice_t * ss)
{
  return (ss != NULL) ? ss->unsetValue() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSlice_hasRequiredAttributes(SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSlice_hasRequiredElements(SedSlice_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSlice_t *
SedListOfSlices_getById(SedListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <SedListOfSlices *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSlice_t *
SedListOfSlices_removeById(SedListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <SedListOfSlices *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


