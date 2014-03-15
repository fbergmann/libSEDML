/**
 * @file:   SedAddXML.cpp
 * @brief:  Implementation of the SedAddXML class
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


#include <sedml/SedAddXML.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedAddXML with the given level, version, and package version.
 */
SedAddXML::SedAddXML (unsigned int level, unsigned int version)
	: SedChange(level, version)
	, mNewXML (NULL)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedAddXML with the given SedNamespaces object.
 */
SedAddXML::SedAddXML (SedNamespaces* sedns)
	: SedChange(sedns)
	, mNewXML (NULL)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedAddXML.
 */
SedAddXML::SedAddXML (const SedAddXML& orig)
	: SedChange(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mNewXML  = orig.mNewXML != NULL ? orig.mNewXML->clone() : NULL;
	}
}


/*
 * Assignment for SedAddXML.
 */
SedAddXML&
SedAddXML::operator=(const SedAddXML& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedChange::operator=(rhs);
		mNewXML  = rhs.mNewXML != NULL ? rhs.mNewXML->clone() : NULL;
	}
	return *this;
}


/*
 * Clone for SedAddXML.
 */
SedAddXML*
SedAddXML::clone () const
{
	return new SedAddXML(*this);
}


/*
 * Destructor for SedAddXML.
 */
SedAddXML::~SedAddXML ()
{
}


/*
 * Returns the value of the "newXML" attribute of this SedAddXML.
 */
const XMLNode*
SedAddXML::getNewXML() const
{
	return mNewXML;
}


/*
 * Returns true/false if newXML is set.
 */
bool
SedAddXML::isSetNewXML() const
{
	return (mNewXML != NULL);
}


/*
 * Sets newXML and returns value indicating success.
 */
int
SedAddXML::setNewXML(XMLNode* newXML)
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
	delete mNewXML;
	mNewXML = (newXML != NULL) ?
		newXML->clone() : NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets newXML and returns value indicating success.
 */
int
SedAddXML::unsetNewXML()
{
	delete mNewXML;
	mNewXML = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedAddXML::getElementName () const
{
	static const string name = "addXML";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedAddXML::createObject(XMLInputStream& stream)
{
	SedBase* object = SedChange::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedAddXML::getTypeCode () const
{
	return SEDML_CHANGE_ADDXML;
}


/*
 * check if all the required attributes are set
 */
bool
SedAddXML::hasRequiredAttributes () const
{
	bool allPresent = SedChange::hasRequiredAttributes();

	if (isSetNewXML() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedAddXML::writeElements (XMLOutputStream& stream) const
{
	SedChange::writeElements(stream);
	if (isSetNewXML() == true)
	{
		stream.startElement("newXML");
		stream << *mNewXML;
		stream.endElement("newXML");

	}
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedAddXML::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedAddXML::setSedDocument (SedDocument* d)
{
	SedChange::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedAddXML::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedChange::addExpectedAttributes(attributes);

	attributes.add("newXML");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedAddXML::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedChange::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

bool
SedAddXML::readOtherXML (XMLInputStream& stream)
{
	bool          read = false;
	const string& name = stream.peek().getName();

	if (name == "newXML")
	{
		const XMLToken& token = stream.next();
		stream.skipText();
		mNewXML = new XMLNode(stream);
		stream.skipPastEnd(token);
		read = true;
	}

	if (SedChange::readOtherXML(stream))
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
SedAddXML::writeAttributes (XMLOutputStream& stream) const
{
	SedChange::writeAttributes(stream);

}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedAddXML_t *
SedAddXML_create(unsigned int level, unsigned int version)
{
	return new SedAddXML(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedAddXML_free(SedAddXML_t * saxml)
{
	if (saxml != NULL)
		delete saxml;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedAddXML_t *
SedAddXML_clone(SedAddXML_t * saxml)
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


/**
 * write comments
 */
LIBSEDML_EXTERN
XMLNode_t*
SedAddXML_getNewXML(SedAddXML_t * saxml)
{
	if (saxml == NULL)
		return NULL;

	return (XMLNode_t*)saxml->getNewXML();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAddXML_isSetNewXML(SedAddXML_t * saxml)
{
	return (saxml != NULL) ? static_cast<int>(saxml->isSetNewXML()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAddXML_setNewXML(SedAddXML_t * saxml, XMLNode* newXML)
{
	return (saxml != NULL) ? saxml->setNewXML(newXML) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAddXML_unsetNewXML(SedAddXML_t * saxml)
{
	return (saxml != NULL) ? saxml->unsetNewXML() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAddXML_hasRequiredAttributes(SedAddXML_t * saxml)
{
	return (saxml != NULL) ? static_cast<int>(saxml->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


