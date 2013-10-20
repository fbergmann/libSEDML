/**
 * @file:   SedParameter.cpp
 * @brief:  Implementation of the SedParameter class
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


#include <sedml/SedParameter.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedParameter with the given level, version, and package version.
 */
SedParameter::SedParameter (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mValue (numeric_limits<double>::quiet_NaN())
	, mIsSetValue (false)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedParameter with the given SedNamespaces object.
 */
SedParameter::SedParameter (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")
	, mName ("")
	, mValue (numeric_limits<double>::quiet_NaN())
	, mIsSetValue (false)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedParameter.
 */
SedParameter::SedParameter (const SedParameter& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
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
 * Assignment for SedParameter.
 */
SedParameter&
SedParameter::operator=(const SedParameter& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
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
 * Clone for SedParameter.
 */
SedParameter*
SedParameter::clone () const
{
	return new SedParameter(*this);
}


/*
 * Destructor for SedParameter.
 */
SedParameter::~SedParameter ()
{
}


/*
 * Returns the value of the "id" attribute of this SedParameter.
 */
const std::string&
SedParameter::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedParameter.
 */
const std::string&
SedParameter::getName() const
{
	return mName;
}


/*
 * Returns the value of the "value" attribute of this SedParameter.
 */
const double
SedParameter::getValue() const
{
	return mValue;
}


/*
 * Returns true/false if id is set.
 */
bool
SedParameter::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedParameter::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if value is set.
 */
bool
SedParameter::isSetValue() const
{
	return mIsSetValue;
}


/*
 * Sets id and returns value indicating success.
 */
int
SedParameter::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedParameter::setName(const std::string& name)
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
SedParameter::setValue(double value)
{
	mValue = value;
	mIsSetValue = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedParameter::unsetId()
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
SedParameter::unsetName()
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
SedParameter::unsetValue()
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
SedParameter::getElementName () const
{
	static const string name = "parameter";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedParameter::getTypeCode () const
{
	return SEDML_PARAMETER;
}


/*
 * check if all the required attributes are set
 */
bool
SedParameter::hasRequiredAttributes () const
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
SedParameter::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedParameter::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedParameter::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedParameter::addExpectedAttributes(ExpectedAttributes& attributes)
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
SedParameter::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedParameter>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedParameter>");
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
SedParameter::writeAttributes (XMLOutputStream& stream) const
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
SedListOfParameters::SedListOfParameters(unsigned int level, 
	                    unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfParameters::SedListOfParameters(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfParameters 
 */
SedListOfParameters* 
SedListOfParameters::clone () const
 {
	return new SedListOfParameters(*this);
}


/*
 * Get a Parameter from the SedListOfParameters by index.
*/
SedParameter*
SedListOfParameters::get(unsigned int n)
{
	return static_cast<SedParameter*>(SedListOf::get(n));
}


/*
 * Get a Parameter from the SedListOfParameters by index.
 */
const SedParameter*
SedListOfParameters::get(unsigned int n) const
{
	return static_cast<const SedParameter*>(SedListOf::get(n));
}


/*
 * Get a Parameter from the SedListOfParameters by id.
 */
SedParameter*
SedListOfParameters::get(const std::string& sid)
{
	return const_cast<SedParameter*>(
	  static_cast<const SedListOfParameters&>(*this).get(sid));
}


/*
 * Get a Parameter from the SedListOfParameters by id.
 */
const SedParameter*
SedListOfParameters::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedParameter>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedParameter*> (*result);
}


/**
 * Adds a copy the given "SedParameter" to this SedListOfParameters.
 *
 * @param sp; the SedParameter object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfParameters::addParameter(const SedParameter* sp)
{
	if(sp == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sp);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedParameter objects in this SedListOfParameters.
 *
 * @return the number of SedParameter objects in this SedListOfParameters
 */
unsigned int 
SedListOfParameters::getNumParameters() const
{
	return size();
}

/**
 * Creates a new SedParameter object, adds it to this SedListOfParameterss
 * SedParameter and returns the SedParameter object created. 
 *
 * @return a new SedParameter object instance
 *
 * @see addSedParameter(const SedParameter* sp)
 */
SedParameter* 
SedListOfParameters::createParameter()
{
	SedParameter *temp = new SedParameter();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Parameter from this SedListOfParameters
 */
SedParameter*
SedListOfParameters::remove(unsigned int n)
{
	return static_cast<SedParameter*>(SedListOf::remove(n));
}


/*
 * Removes the Parameter from this SedListOfParameters with the given identifier
 */
SedParameter*
SedListOfParameters::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedParameter>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedParameter*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfParameters::getElementName () const
{
	static const string name = "listOfParameters";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfParameters::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfParameters::getItemTypeCode () const
{
	return SEDML_PARAMETER;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedParameter in this SedListOfParameters
 */
SedBase*
SedListOfParameters::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "parameter")
	{
		object = new SedParameter(getSedNamespaces());
		appendAndOwn(object);
	}

	return object;
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write the namespace for the Sed package.
 */
void
SedListOfParameters::writeXMLNS(XMLOutputStream& stream) const
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


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedParameter_t *
SedParameter_create(unsigned int level, unsigned int version)
{
	return new SedParameter(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedParameter_free(SedParameter_t * sp)
{
	if (sp != NULL)
		delete sp;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedParameter_t *
SedParameter_clone(SedParameter_t * sp)
{
	if (sp != NULL)
	{
		return static_cast<SedParameter_t*>(sp->clone());
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
SedParameter_getId(SedParameter_t * sp)
{
	if (sp == NULL)
		return NULL;

	return sp->getId().empty() ? NULL : safe_strdup(sp->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedParameter_getName(SedParameter_t * sp)
{
	if (sp == NULL)
		return NULL;

	return sp->getName().empty() ? NULL : safe_strdup(sp->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
double
SedParameter_getValue(SedParameter_t * sp)
{
	return (sp != NULL) ? sp->getValue() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_isSetId(SedParameter_t * sp)
{
	return (sp != NULL) ? static_cast<int>(sp->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_isSetName(SedParameter_t * sp)
{
	return (sp != NULL) ? static_cast<int>(sp->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_isSetValue(SedParameter_t * sp)
{
	return (sp != NULL) ? static_cast<int>(sp->isSetValue()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_setId(SedParameter_t * sp, const char * id)
{
	return (sp != NULL) ? sp->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_setName(SedParameter_t * sp, const char * name)
{
	return (sp != NULL) ? sp->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_setValue(SedParameter_t * sp, double value)
{
	return (sp != NULL) ? sp->setValue(value) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_unsetId(SedParameter_t * sp)
{
	return (sp != NULL) ? sp->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_unsetName(SedParameter_t * sp)
{
	return (sp != NULL) ? sp->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_unsetValue(SedParameter_t * sp)
{
	return (sp != NULL) ? sp->unsetValue() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedParameter_hasRequiredAttributes(SedParameter_t * sp)
{
	return (sp != NULL) ? static_cast<int>(sp->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedParameter_t *
SedListOfParameters_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfParameters *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedParameter_t *
SedListOfParameters_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfParameters *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


