/**
 * @file:   ChangeAttribute.cpp
 * @brief:  Implementation of the ChangeAttribute class
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


#include <sedml/ChangeAttribute.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new ChangeAttribute with the given level, version, and package version.
 */
ChangeAttribute::ChangeAttribute (unsigned int level, unsigned int version)
	: Change(level, version)
	, mNewValue ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new ChangeAttribute with the given SedMLNamespaces object.
 */
ChangeAttribute::ChangeAttribute (SedMLNamespaces* sedmlns)
	: Change(sedmlns)
	, mNewValue ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for ChangeAttribute.
 */
ChangeAttribute::ChangeAttribute (const ChangeAttribute& orig)
	: Change(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mNewValue  = orig.mNewValue;
	}
}


/*
 * Assignment for ChangeAttribute.
 */
ChangeAttribute&
ChangeAttribute::operator=(const ChangeAttribute& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		Change::operator=(rhs);
		mNewValue  = rhs.mNewValue;
	}
	return *this;
}


/*
 * Clone for ChangeAttribute.
 */
ChangeAttribute*
ChangeAttribute::clone () const
{
	return new ChangeAttribute(*this);
}


/*
 * Destructor for ChangeAttribute.
 */
ChangeAttribute::~ChangeAttribute ()
{
}


/*
 * Returns the value of the "newValue" attribute of this ChangeAttribute.
 */
const std::string&
ChangeAttribute::getNewValue() const
{
	return mNewValue;
}


/*
/*
 * Returns true/false if newValue is set.
 */
bool
ChangeAttribute::isSetNewValue() const
{
	return (mNewValue.empty() == false);
}


/*
 * Sets newValue and returns value indicating success.
 */
int
ChangeAttribute::setNewValue(const std::string& newValue)
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
ChangeAttribute::unsetNewValue()
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
ChangeAttribute::getElementName () const
{
	static const string name = "changeAttribute";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
ChangeAttribute::getTypeCode () const
{
	return SEDML_CHANGE_ATTRIBUTE;
}


/*
 * check if all the required attributes are set
 */
bool
ChangeAttribute::hasRequiredAttributes () const
{
	bool allPresent = Change::hasRequiredAttributes();

	if (isSetNewValue() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
ChangeAttribute::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
ChangeAttribute::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
ChangeAttribute::setSedMLDocument (SedMLDocument* d)
{
	Change::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
ChangeAttribute::addExpectedAttributes(ExpectedAttributes& attributes)
{
	Change::addExpectedAttributes(attributes);

	attributes.add("newValue");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
ChangeAttribute::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	Change::readAttributes(attributes, expectedAttributes);

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
			logEmptyString(mNewValue, getLevel(), getVersion(), "<ChangeAttribute>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
ChangeAttribute::writeAttributes (XMLOutputStream& stream) const
{
	Change::writeAttributes(stream);

	if (isSetNewValue() == true)
		stream.writeAttribute("newValue", getPrefix(), mNewValue);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
ChangeAttribute_t *
ChangeAttribute_create(unsigned int level, unsigned int version)
{
	return new ChangeAttribute(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
ChangeAttribute_free(ChangeAttribute_t * ca)
{
	if (ca != NULL)
		delete ca;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
ChangeAttribute_t *
ChangeAttribute_clone(ChangeAttribute_t * ca)
{
	if (ca != NULL)
	{
		return static_cast<ChangeAttribute_t*>(ca->clone());
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
ChangeAttribute_getNewValue(ChangeAttribute_t * ca)
{
	if (ca == NULL)
		return NULL;

	return ca->getNewValue().empty() ? NULL : safe_strdup(ca->getNewValue().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
ChangeAttribute_isSetNewValue(ChangeAttribute_t * ca)
{
	return (ca != NULL) ? static_cast<int>(ca->isSetNewValue()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
ChangeAttribute_setNewValue(ChangeAttribute_t * ca, const char * newValue)
{
	return (ca != NULL) ? ca->setNewValue(newValue) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
ChangeAttribute_unsetNewValue(ChangeAttribute_t * ca)
{
	return (ca != NULL) ? ca->unsetNewValue() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
ChangeAttribute_hasRequiredAttributes(ChangeAttribute_t * ca)
{
	return (ca != NULL) ? static_cast<int>(ca->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


