/**
 * @file:   SedRange.cpp
 * @brief:  Implementation of the SedRange class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on 
 * github: https://github.com/fbergmann/libSEDML/
 *
 * Copyright (c) 2013-2014, Frank T. Bergmann  
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


#include <sedml/SedRange.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedRange with the given level, version, and package version.
 */
SedRange::SedRange (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedRange with the given SedNamespaces object.
 */
SedRange::SedRange (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedRange.
 */
SedRange::SedRange (const SedRange& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mId  = orig.mId;
	}
}


/*
 * Assignment for SedRange.
 */
SedRange&
SedRange::operator=(const SedRange& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mId  = rhs.mId;
	}
	return *this;
}


/*
 * Clone for SedRange.
 */
SedRange*
SedRange::clone () const
{
	return new SedRange(*this);
}


/*
 * Destructor for SedRange.
 */
SedRange::~SedRange ()
{
}


/*
 * Returns the value of the "id" attribute of this SedRange.
 */
const std::string&
SedRange::getId() const
{
	return mId;
}


/*
 * Returns true/false if id is set.
 */
bool
SedRange::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedRange::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedRange::unsetId()
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
 * Returns the XML element name of this object
 */
const std::string&
SedRange::getElementName () const
{
	static const string name = "range";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedRange::getTypeCode () const
{
	return SEDML_RANGE;
}


/*
 * check if all the required attributes are set
 */
bool
SedRange::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetId() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedRange::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedRange::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedRange::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedRange::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedRange::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedRange>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mId) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedRange::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor 
 */
SedListOfRanges::SedListOfRanges(unsigned int level, 
	                unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfRanges::SedListOfRanges(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfRanges 
 */
SedListOfRanges* 
SedListOfRanges::clone () const
 {
	return new SedListOfRanges(*this);
}


/*
 * Get a Range from the SedListOfRanges by index.
*/
SedRange*
SedListOfRanges::get(unsigned int n)
{
	return static_cast<SedRange*>(SedListOf::get(n));
}


/*
 * Get a Range from the SedListOfRanges by index.
 */
const SedRange*
SedListOfRanges::get(unsigned int n) const
{
	return static_cast<const SedRange*>(SedListOf::get(n));
}


/*
 * Get a Range from the SedListOfRanges by id.
 */
SedRange*
SedListOfRanges::get(const std::string& sid)
{
	return const_cast<SedRange*>(
	  static_cast<const SedListOfRanges&>(*this).get(sid));
}


/*
 * Get a Range from the SedListOfRanges by id.
 */
const SedRange*
SedListOfRanges::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedRange>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedRange*> (*result);
}


/**
 * Adds a copy the given "SedRange" to this SedListOfRanges.
 *
 * @param sr; the SedRange object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfRanges::addRange(const SedRange* sr)
{
	if(sr == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sr);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedRange objects in this SedListOfRanges.
 *
 * @return the number of SedRange objects in this SedListOfRanges
 */
unsigned int 
SedListOfRanges::getNumRanges() const
{
	return size();
}

/**
 * Creates a new SedUniformRange object, adds it to this SedListOfRanges
 * uniformRange and returns the SedUniformRange object created. 
 *
 * @return a new SedUniformRange object instance
 *
 * @see addUniformRange(const SedRange* sr)
 */
SedUniformRange* 
SedListOfRanges::createUniformRange()
{
	SedUniformRange *temp = new SedUniformRange();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedVectorRange object, adds it to this SedListOfRanges
 * vectorRange and returns the SedVectorRange object created. 
 *
 * @return a new SedVectorRange object instance
 *
 * @see addVectorRange(const SedRange* sr)
 */
SedVectorRange* 
SedListOfRanges::createVectorRange()
{
	SedVectorRange *temp = new SedVectorRange();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedFunctionalRange object, adds it to this SedListOfRanges
 * functionalRange and returns the SedFunctionalRange object created. 
 *
 * @return a new SedFunctionalRange object instance
 *
 * @see addFunctionalRange(const SedRange* sr)
 */
SedFunctionalRange* 
SedListOfRanges::createFunctionalRange()
{
	SedFunctionalRange *temp = new SedFunctionalRange();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Range from this SedListOfRanges
 */
SedRange*
SedListOfRanges::remove(unsigned int n)
{
	return static_cast<SedRange*>(SedListOf::remove(n));
}


/*
 * Removes the Range from this SedListOfRanges with the given identifier
 */
SedRange*
SedListOfRanges::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedRange>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedRange*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfRanges::getElementName () const
{
	static const string name = "listOfRanges";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfRanges::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfRanges::getItemTypeCode () const
{
	return SEDML_RANGE;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedRange in this SedListOfRanges
 */
SedBase*
SedListOfRanges::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "uniformRange")
	{
		object = new SedUniformRange(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "vectorRange")
	{
		object = new SedVectorRange(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "functionalRange")
	{
		object = new SedFunctionalRange(getSedNamespaces());
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
SedListOfRanges::writeXMLNS(XMLOutputStream& stream) const
{
	XMLNamespaces xmlns;

	std::string prefix = getPrefix();

	if (prefix.empty())
	{
		if (getNamespaces() != NULL && !getNamespaces()->hasURI(SEDML_XMLNS_L1) && !getNamespaces()->hasURI(SEDML_XMLNS_L1V2))
		{
			if (getVersion() == 2) xmlns.add(SEDML_XMLNS_L1V2,prefix);
			else xmlns.add(SEDML_XMLNS_L1V2,prefix);
		}
	}

	stream << xmlns;
}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRange_t *
SedRange_create(unsigned int level, unsigned int version)
{
	return new SedRange(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedRange_free(SedRange_t * sr)
{
	if (sr != NULL)
		delete sr;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRange_t *
SedRange_clone(SedRange_t * sr)
{
	if (sr != NULL)
	{
		return static_cast<SedRange_t*>(sr->clone());
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
SedRange_getId(SedRange_t * sr)
{
	if (sr == NULL)
		return NULL;

	return sr->getId().empty() ? NULL : safe_strdup(sr->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRange_isSetId(SedRange_t * sr)
{
	return (sr != NULL) ? static_cast<int>(sr->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRange_setId(SedRange_t * sr, const char * id)
{
	return (sr != NULL) ? sr->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRange_unsetId(SedRange_t * sr)
{
	return (sr != NULL) ? sr->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRange_hasRequiredAttributes(SedRange_t * sr)
{
	return (sr != NULL) ? static_cast<int>(sr->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRange_t *
SedListOfRanges_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfRanges *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRange_t *
SedListOfRanges_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfRanges *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


