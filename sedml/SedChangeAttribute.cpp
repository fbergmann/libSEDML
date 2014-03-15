/**
 * @file:   SedChangeAttribute.cpp
 * @brief:  Implementation of the SedChangeAttribute class
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


#include <sedml/SedChangeAttribute.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedChangeAttribute with the given level, version, and package version.
 */
SedChangeAttribute::SedChangeAttribute (unsigned int level, unsigned int version)
	: SedChange(level, version)
	, mNewValue ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedChangeAttribute with the given SedNamespaces object.
 */
SedChangeAttribute::SedChangeAttribute (SedNamespaces* sedns)
	: SedChange(sedns)
	, mNewValue ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedChangeAttribute.
 */
SedChangeAttribute::SedChangeAttribute (const SedChangeAttribute& orig)
	: SedChange(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mNewValue  = orig.mNewValue;
	}
}


/*
 * Assignment for SedChangeAttribute.
 */
SedChangeAttribute&
SedChangeAttribute::operator=(const SedChangeAttribute& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedChange::operator=(rhs);
		mNewValue  = rhs.mNewValue;
	}
	return *this;
}


/*
 * Clone for SedChangeAttribute.
 */
SedChangeAttribute*
SedChangeAttribute::clone () const
{
	return new SedChangeAttribute(*this);
}


/*
 * Destructor for SedChangeAttribute.
 */
SedChangeAttribute::~SedChangeAttribute ()
{
}


/*
 * Returns the value of the "newValue" attribute of this SedChangeAttribute.
 */
const std::string&
SedChangeAttribute::getNewValue() const
{
	return mNewValue;
}


/*
 * Returns true/false if newValue is set.
 */
bool
SedChangeAttribute::isSetNewValue() const
{
	return (mNewValue.empty() == false);
}


/*
 * Sets newValue and returns value indicating success.
 */
int
SedChangeAttribute::setNewValue(const std::string& newValue)
{
	if (&(newValue) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mNewValue = newValue;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets newValue and returns value indicating success.
 */
int
SedChangeAttribute::unsetNewValue()
{
	mNewValue.erase();

	if (mNewValue.empty() == true)
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
SedChangeAttribute::getElementName () const
{
	static const string name = "changeAttribute";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedChangeAttribute::createObject(XMLInputStream& stream)
{
	SedBase* object = SedChange::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedChangeAttribute::getTypeCode () const
{
	return SEDML_CHANGE_ATTRIBUTE;
}


/*
 * check if all the required attributes are set
 */
bool
SedChangeAttribute::hasRequiredAttributes () const
{
	bool allPresent = SedChange::hasRequiredAttributes();

	if (isSetNewValue() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedChangeAttribute::writeElements (XMLOutputStream& stream) const
{
	SedChange::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedChangeAttribute::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedChangeAttribute::setSedDocument (SedDocument* d)
{
	SedChange::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedChangeAttribute::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedChange::addExpectedAttributes(attributes);

	attributes.add("newValue");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedChangeAttribute::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedChange::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// newValue string   ( use = "required" )
	//
	assigned = attributes.readInto("newValue", mNewValue, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty

		if (mNewValue.empty() == true)
		{
			logEmptyString(mNewValue, getLevel(), getVersion(), "<SedChangeAttribute>");
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedChangeAttribute::writeAttributes (XMLOutputStream& stream) const
{
	SedChange::writeAttributes(stream);

	if (isSetNewValue() == true)
		stream.writeAttribute("newValue", getPrefix(), mNewValue);

}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedChangeAttribute_t *
SedChangeAttribute_create(unsigned int level, unsigned int version)
{
	return new SedChangeAttribute(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedChangeAttribute_free(SedChangeAttribute_t * sca)
{
	if (sca != NULL)
		delete sca;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedChangeAttribute_t *
SedChangeAttribute_clone(SedChangeAttribute_t * sca)
{
	if (sca != NULL)
	{
		return static_cast<SedChangeAttribute_t*>(sca->clone());
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
SedChangeAttribute_getNewValue(SedChangeAttribute_t * sca)
{
	if (sca == NULL)
		return NULL;

	return sca->getNewValue().empty() ? NULL : safe_strdup(sca->getNewValue().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_isSetNewValue(SedChangeAttribute_t * sca)
{
	return (sca != NULL) ? static_cast<int>(sca->isSetNewValue()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_setNewValue(SedChangeAttribute_t * sca, const char * newValue)
{
	return (sca != NULL) ? sca->setNewValue(newValue) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_unsetNewValue(SedChangeAttribute_t * sca)
{
	return (sca != NULL) ? sca->unsetNewValue() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedChangeAttribute_hasRequiredAttributes(SedChangeAttribute_t * sca)
{
	return (sca != NULL) ? static_cast<int>(sca->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


