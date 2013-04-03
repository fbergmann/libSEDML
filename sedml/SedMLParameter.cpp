/**
 * @file:   SedMLParameter.cpp
 * @brief:  Implementation of the SedMLParameter class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SEDML, and the latest version of libSEDML.
 *
 * Copyright (c) 2013, Frank T. Bergmann  
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


#include <sedml/SedMLParameter.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedMLParameter with the given level, version, and package version.
 */
SedMLParameter::SedMLParameter (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mValue (numeric_limits<double>::quiet_NaN())
	, mIsSetValue (false)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new SedMLParameter with the given SedMLNamespaces object.
 */
SedMLParameter::SedMLParameter (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mName ("")
	, mValue (numeric_limits<double>::quiet_NaN())
	, mIsSetValue (false)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedMLParameter.
 */
SedMLParameter::SedMLParameter (const SedMLParameter& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mId  = orig.mId;
		mName  = orig.mName;
		mValue  = orig.mValue;
		mIsSetValue  = orig.mIsSetValue;
	}
}


/*
 * Assignment for SedMLParameter.
 */
SedMLParameter&
SedMLParameter::operator=(const SedMLParameter& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mId  = rhs.mId;
		mName  = rhs.mName;
		mValue  = rhs.mValue;
		mIsSetValue  = rhs.mIsSetValue;
	}
	return *this;
}


/*
 * Clone for SedMLParameter.
 */
SedMLParameter*
SedMLParameter::clone () const
{
	return new SedMLParameter(*this);
}


/*
 * Destructor for SedMLParameter.
 */
SedMLParameter::~SedMLParameter ()
{
}


/*
 * Returns the value of the "id" attribute of this SedMLParameter.
 */
const std::string&
SedMLParameter::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedMLParameter.
 */
const std::string&
SedMLParameter::getName() const
{
	return mName;
}


/*
 * Returns the value of the "value" attribute of this SedMLParameter.
 */
const double
SedMLParameter::getValue() const
{
	return mValue;
}


/*
 * Returns true/false if id is set.
 */
bool
SedMLParameter::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedMLParameter::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if value is set.
 */
bool
SedMLParameter::isSetValue() const
{
	return mIsSetValue;
}


/*
 * Sets id and returns value indicating success.
 */
int
SedMLParameter::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedMLParameter::setName(const std::string& name)
{
	if (&(name) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mName = name;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets value and returns value indicating success.
 */
int
SedMLParameter::setValue(double value)
{
	mValue = value;
	mIsSetValue = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedMLParameter::unsetId()
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
SedMLParameter::unsetName()
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
 * Unsets value and returns value indicating success.
 */
int
SedMLParameter::unsetValue()
{
	mValue = numeric_limits<double>::quiet_NaN();
	mIsSetValue = false;

	if (isSetValue() == false)
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
SedMLParameter::getElementName () const
{
	static const string name = "parameter";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedMLParameter::getTypeCode () const
{
	return SEDML_PARAMETER;
}


/*
 * check if all the required attributes are set
 */
bool
SedMLParameter::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetId() == false)
		allPresent = false;

	if (isSetValue() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedMLParameter::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
SedMLParameter::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
SedMLParameter::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedMLParameter::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
	attributes.add("value");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedMLParameter::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedMLParameter>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mId) == false)
		{
			logError(InvalidIdSyntax);
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedMLParameter>");
		}
	}

	//
	// value double   ( use = "required" )
	//
	mIsSetValue = attributes.readInto("value", mValue, getErrorLog(), true);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedMLParameter::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

	if (isSetValue() == true)
		stream.writeAttribute("value", getPrefix(), mValue);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfSedMLParameters::SedListOfSedMLParameters(unsigned int level, 
	                         unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSedMLParameters::SedListOfSedMLParameters(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSedMLParameters 
 */
SedListOfSedMLParameters* 
SedListOfSedMLParameters::clone () const
 {
	return new SedListOfSedMLParameters(*this);
}


/*
 * Get a SedMLParameter from the SedListOfSedMLParameters by index.
*/
SedMLParameter*
SedListOfSedMLParameters::get(unsigned int n)
{
	return static_cast<SedMLParameter*>(SedListOf::get(n));
}


/*
 * Get a SedMLParameter from the SedListOfSedMLParameters by index.
 */
const SedMLParameter*
SedListOfSedMLParameters::get(unsigned int n) const
{
	return static_cast<const SedMLParameter*>(SedListOf::get(n));
}


/*
 * Get a SedMLParameter from the SedListOfSedMLParameters by id.
 */
SedMLParameter*
SedListOfSedMLParameters::get(const std::string& sid)
{
	return const_cast<SedMLParameter*>(
	  static_cast<const SedListOfSedMLParameters&>(*this).get(sid));
}


/*
 * Get a SedMLParameter from the SedListOfSedMLParameters by id.
 */
const SedMLParameter*
SedListOfSedMLParameters::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLParameter>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedMLParameter*> (*result);
}


/*
 * Removes the nth SedMLParameter from this SedListOfSedMLParameters
 */
SedMLParameter*
SedListOfSedMLParameters::remove(unsigned int n)
{
	return static_cast<SedMLParameter*>(SedListOf::remove(n));
}


/*
 * Removes the SedMLParameter from this SedListOfSedMLParameters with the given identifier
 */
SedMLParameter*
SedListOfSedMLParameters::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLParameter>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedMLParameter*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSedMLParameters::getElementName () const
{
	static const string name = "listOfParameters";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSedMLParameters::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSedMLParameters::getItemTypeCode () const
{
	return SEDML_PARAMETER;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedMLParameter in this SedListOfSedMLParameters
 */
SedBase*
SedListOfSedMLParameters::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "sedMLParameter")
	{
		object = new SedMLParameter(getSedMLNamespaces());
		appendAndOwn(object);
	}

	return object;
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write the namespace for the SedML package.
 */
void
SedListOfSedMLParameters::writeXMLNS(XMLOutputStream& stream) const
{
	XMLNamespaces xmlns;

	std::string prefix = getPrefix();

	if (prefix.empty())
	{
		if (getNamespaces()->hasURI(SEDML_XMLNS_L1))
		{
			xmlns.add(SEDML_XMLNS_L1,prefix);
		}
	}

	stream << xmlns;
}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLParameter_t *
SedMLParameter_create(unsigned int level, unsigned int version)
{
	return new SedMLParameter(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedMLParameter_free(SedMLParameter_t * smlp)
{
	if (smlp != NULL)
		delete smlp;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLParameter_t *
SedMLParameter_clone(SedMLParameter_t * smlp)
{
	if (smlp != NULL)
	{
		return static_cast<SedMLParameter_t*>(smlp->clone());
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
SedMLParameter_getId(SedMLParameter_t * smlp)
{
	if (smlp == NULL)
		return NULL;

	return smlp->getId().empty() ? NULL : safe_strdup(smlp->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLParameter_getName(SedMLParameter_t * smlp)
{
	if (smlp == NULL)
		return NULL;

	return smlp->getName().empty() ? NULL : safe_strdup(smlp->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
double
SedMLParameter_getValue(SedMLParameter_t * smlp)
{
	return (smlp != NULL) ? smlp->getValue() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_isSetId(SedMLParameter_t * smlp)
{
	return (smlp != NULL) ? static_cast<int>(smlp->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_isSetName(SedMLParameter_t * smlp)
{
	return (smlp != NULL) ? static_cast<int>(smlp->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_isSetValue(SedMLParameter_t * smlp)
{
	return (smlp != NULL) ? static_cast<int>(smlp->isSetValue()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_setId(SedMLParameter_t * smlp, const char * id)
{
	return (smlp != NULL) ? smlp->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_setName(SedMLParameter_t * smlp, const char * name)
{
	return (smlp != NULL) ? smlp->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_setValue(SedMLParameter_t * smlp, double value)
{
	return (smlp != NULL) ? smlp->setValue(value) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_unsetId(SedMLParameter_t * smlp)
{
	return (smlp != NULL) ? smlp->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_unsetName(SedMLParameter_t * smlp)
{
	return (smlp != NULL) ? smlp->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_unsetValue(SedMLParameter_t * smlp)
{
	return (smlp != NULL) ? smlp->unsetValue() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLParameter_hasRequiredAttributes(SedMLParameter_t * smlp)
{
	return (smlp != NULL) ? static_cast<int>(smlp->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLParameter_t *
SedListOfSedMLParameters_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLParameters *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLParameter_t *
SedListOfSedMLParameters_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLParameters *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


