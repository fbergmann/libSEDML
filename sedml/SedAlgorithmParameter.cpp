/**
 * @file:   SedAlgorithmParameter.cpp
 * @brief:  Implementation of the SedAlgorithmParameter class
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


#include <sedml/SedAlgorithmParameter.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedAlgorithmParameter with the given level, version, and package version.
 */
SedAlgorithmParameter::SedAlgorithmParameter (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mKisaoID ("")
	, mValue ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedAlgorithmParameter with the given SedNamespaces object.
 */
SedAlgorithmParameter::SedAlgorithmParameter (SedNamespaces* sedns)
	: SedBase(sedns)
	, mKisaoID ("")
	, mValue ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedAlgorithmParameter.
 */
SedAlgorithmParameter::SedAlgorithmParameter (const SedAlgorithmParameter& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mKisaoID  = orig.mKisaoID;
		mValue  = orig.mValue;
	}
}


/*
 * Assignment for SedAlgorithmParameter.
 */
SedAlgorithmParameter&
SedAlgorithmParameter::operator=(const SedAlgorithmParameter& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mKisaoID  = rhs.mKisaoID;
		mValue  = rhs.mValue;
	}
	return *this;
}


/*
 * Clone for SedAlgorithmParameter.
 */
SedAlgorithmParameter*
SedAlgorithmParameter::clone () const
{
	return new SedAlgorithmParameter(*this);
}


/*
 * Destructor for SedAlgorithmParameter.
 */
SedAlgorithmParameter::~SedAlgorithmParameter ()
{
}


/*
 * Returns the value of the "kisaoID" attribute of this SedAlgorithmParameter.
 */
const std::string&
SedAlgorithmParameter::getKisaoID() const
{
	return mKisaoID;
}


/*
 * Returns the value of the "value" attribute of this SedAlgorithmParameter.
 */
const std::string&
SedAlgorithmParameter::getValue() const
{
	return mValue;
}


/*
 * Returns true/false if kisaoID is set.
 */
bool
SedAlgorithmParameter::isSetKisaoID() const
{
	return (mKisaoID.empty() == false);
}


/*
 * Returns true/false if value is set.
 */
bool
SedAlgorithmParameter::isSetValue() const
{
	return (mValue.empty() == false);
}


/*
 * Sets kisaoID and returns value indicating success.
 */
int
SedAlgorithmParameter::setKisaoID(const std::string& kisaoID)
{
	if (&(kisaoID) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mKisaoID = kisaoID;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets value and returns value indicating success.
 */
int
SedAlgorithmParameter::setValue(const std::string& value)
{
	if (&(value) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mValue = value;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets kisaoID and returns value indicating success.
 */
int
SedAlgorithmParameter::unsetKisaoID()
{
	mKisaoID.erase();

	if (mKisaoID.empty() == true)
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
SedAlgorithmParameter::unsetValue()
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
SedAlgorithmParameter::getElementName () const
{
	static const string name = "algorithmParameter";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedAlgorithmParameter::getTypeCode () const
{
	return SEDML_SIMULATION_ALGORITHM_PARAMETER;
}


/*
 * check if all the required attributes are set
 */
bool
SedAlgorithmParameter::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetKisaoID() == false)
		allPresent = false;

	if (isSetValue() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedAlgorithmParameter::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedAlgorithmParameter::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedAlgorithmParameter::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedAlgorithmParameter::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("kisaoID");
	attributes.add("value");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedAlgorithmParameter::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// kisaoID string   ( use = "required" )
	//
	assigned = attributes.readInto("kisaoID", mKisaoID, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty

		if (mKisaoID.empty() == true)
		{
			logEmptyString(mKisaoID, getLevel(), getVersion(), "<SedAlgorithmParameter>");
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
			logEmptyString(mValue, getLevel(), getVersion(), "<SedAlgorithmParameter>");
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedAlgorithmParameter::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetKisaoID() == true)
		stream.writeAttribute("kisaoID", getPrefix(), mKisaoID);

	if (isSetValue() == true)
		stream.writeAttribute("value", getPrefix(), mValue);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor 
 */
SedListOfAlgorithmParameters::SedListOfAlgorithmParameters(unsigned int level, 
	                             unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfAlgorithmParameters::SedListOfAlgorithmParameters(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfAlgorithmParameters 
 */
SedListOfAlgorithmParameters* 
SedListOfAlgorithmParameters::clone () const
 {
	return new SedListOfAlgorithmParameters(*this);
}


/*
 * Get a AlgorithmParameter from the SedListOfAlgorithmParameters by index.
*/
SedAlgorithmParameter*
SedListOfAlgorithmParameters::get(unsigned int n)
{
	return static_cast<SedAlgorithmParameter*>(SedListOf::get(n));
}


/*
 * Get a AlgorithmParameter from the SedListOfAlgorithmParameters by index.
 */
const SedAlgorithmParameter*
SedListOfAlgorithmParameters::get(unsigned int n) const
{
	return static_cast<const SedAlgorithmParameter*>(SedListOf::get(n));
}


/*
 * Get a AlgorithmParameter from the SedListOfAlgorithmParameters by id.
 */
SedAlgorithmParameter*
SedListOfAlgorithmParameters::get(const std::string& sid)
{
	return const_cast<SedAlgorithmParameter*>(
	  static_cast<const SedListOfAlgorithmParameters&>(*this).get(sid));
}


/*
 * Get a AlgorithmParameter from the SedListOfAlgorithmParameters by id.
 */
const SedAlgorithmParameter*
SedListOfAlgorithmParameters::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedAlgorithmParameter>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedAlgorithmParameter*> (*result);
}


/**
 * Adds a copy the given "SedAlgorithmParameter" to this SedListOfAlgorithmParameters.
 *
 * @param sap; the SedAlgorithmParameter object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfAlgorithmParameters::addAlgorithmParameter(const SedAlgorithmParameter* sap)
{
	if(sap == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sap);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedAlgorithmParameter objects in this SedListOfAlgorithmParameters.
 *
 * @return the number of SedAlgorithmParameter objects in this SedListOfAlgorithmParameters
 */
unsigned int 
SedListOfAlgorithmParameters::getNumAlgorithmParameters() const
{
	return size();
}

/**
 * Creates a new SedAlgorithmParameter object, adds it to this SedListOfAlgorithmParameterss
 * SedAlgorithmParameter and returns the SedAlgorithmParameter object created. 
 *
 * @return a new SedAlgorithmParameter object instance
 *
 * @see addSedAlgorithmParameter(const SedAlgorithmParameter* sap)
 */
SedAlgorithmParameter* 
SedListOfAlgorithmParameters::createAlgorithmParameter()
{
	SedAlgorithmParameter *temp = new SedAlgorithmParameter();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth AlgorithmParameter from this SedListOfAlgorithmParameters
 */
SedAlgorithmParameter*
SedListOfAlgorithmParameters::remove(unsigned int n)
{
	return static_cast<SedAlgorithmParameter*>(SedListOf::remove(n));
}


/*
 * Removes the AlgorithmParameter from this SedListOfAlgorithmParameters with the given identifier
 */
SedAlgorithmParameter*
SedListOfAlgorithmParameters::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedAlgorithmParameter>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedAlgorithmParameter*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfAlgorithmParameters::getElementName () const
{
	static const string name = "listOfAlgorithmParameters";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfAlgorithmParameters::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfAlgorithmParameters::getItemTypeCode () const
{
	return SEDML_SIMULATION_ALGORITHM_PARAMETER;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedAlgorithmParameter in this SedListOfAlgorithmParameters
 */
SedBase*
SedListOfAlgorithmParameters::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "algorithmParameter")
	{
		object = new SedAlgorithmParameter(getSedNamespaces());
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
SedListOfAlgorithmParameters::writeXMLNS(XMLOutputStream& stream) const
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
SedAlgorithmParameter_t *
SedAlgorithmParameter_create(unsigned int level, unsigned int version)
{
	return new SedAlgorithmParameter(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedAlgorithmParameter_free(SedAlgorithmParameter_t * sap)
{
	if (sap != NULL)
		delete sap;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedAlgorithmParameter_clone(SedAlgorithmParameter_t * sap)
{
	if (sap != NULL)
	{
		return static_cast<SedAlgorithmParameter_t*>(sap->clone());
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
SedAlgorithmParameter_getKisaoID(SedAlgorithmParameter_t * sap)
{
	if (sap == NULL)
		return NULL;

	return sap->getKisaoID().empty() ? NULL : safe_strdup(sap->getKisaoID().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedAlgorithmParameter_getValue(SedAlgorithmParameter_t * sap)
{
	if (sap == NULL)
		return NULL;

	return sap->getValue().empty() ? NULL : safe_strdup(sap->getValue().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_isSetKisaoID(SedAlgorithmParameter_t * sap)
{
	return (sap != NULL) ? static_cast<int>(sap->isSetKisaoID()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_isSetValue(SedAlgorithmParameter_t * sap)
{
	return (sap != NULL) ? static_cast<int>(sap->isSetValue()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_setKisaoID(SedAlgorithmParameter_t * sap, const char * kisaoID)
{
	return (sap != NULL) ? sap->setKisaoID(kisaoID) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_setValue(SedAlgorithmParameter_t * sap, const char * value)
{
	return (sap != NULL) ? sap->setValue(value) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_unsetKisaoID(SedAlgorithmParameter_t * sap)
{
	return (sap != NULL) ? sap->unsetKisaoID() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_unsetValue(SedAlgorithmParameter_t * sap)
{
	return (sap != NULL) ? sap->unsetValue() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithmParameter_hasRequiredAttributes(SedAlgorithmParameter_t * sap)
{
	return (sap != NULL) ? static_cast<int>(sap->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedListOfAlgorithmParameters_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfAlgorithmParameters *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedListOfAlgorithmParameters_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfAlgorithmParameters *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


