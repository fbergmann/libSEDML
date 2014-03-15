/**
 * @file:   SedRemoveXML.cpp
 * @brief:  Implementation of the SedRemoveXML class
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


#include <sedml/SedRemoveXML.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedRemoveXML with the given level, version, and package version.
 */
SedRemoveXML::SedRemoveXML (unsigned int level, unsigned int version)
	: SedChange(level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedRemoveXML with the given SedNamespaces object.
 */
SedRemoveXML::SedRemoveXML (SedNamespaces* sedns)
	: SedChange(sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedRemoveXML.
 */
SedRemoveXML::SedRemoveXML (const SedRemoveXML& orig)
	: SedChange(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
	}
}


/*
 * Assignment for SedRemoveXML.
 */
SedRemoveXML&
SedRemoveXML::operator=(const SedRemoveXML& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedChange::operator=(rhs);
	}
	return *this;
}


/*
 * Clone for SedRemoveXML.
 */
SedRemoveXML*
SedRemoveXML::clone () const
{
	return new SedRemoveXML(*this);
}


/*
 * Destructor for SedRemoveXML.
 */
SedRemoveXML::~SedRemoveXML ()
{
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedRemoveXML::getElementName () const
{
	static const string name = "removeXML";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedRemoveXML::createObject(XMLInputStream& stream)
{
	SedBase* object = SedChange::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedRemoveXML::getTypeCode () const
{
	return SEDML_CHANGE_REMOVEXML;
}


/*
 * check if all the required attributes are set
 */
bool
SedRemoveXML::hasRequiredAttributes () const
{
	bool allPresent = SedChange::hasRequiredAttributes();

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedRemoveXML::writeElements (XMLOutputStream& stream) const
{
	SedChange::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedRemoveXML::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedRemoveXML::setSedDocument (SedDocument* d)
{
	SedChange::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedRemoveXML::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedChange::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedRemoveXML::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedChange::readAttributes(attributes, expectedAttributes);

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedRemoveXML::writeAttributes (XMLOutputStream& stream) const
{
	SedChange::writeAttributes(stream);

}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRemoveXML_t *
SedRemoveXML_create(unsigned int level, unsigned int version)
{
	return new SedRemoveXML(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedRemoveXML_free(SedRemoveXML_t * srxml)
{
	if (srxml != NULL)
		delete srxml;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRemoveXML_t *
SedRemoveXML_clone(SedRemoveXML_t * srxml)
{
	if (srxml != NULL)
	{
		return static_cast<SedRemoveXML_t*>(srxml->clone());
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
int
SedRemoveXML_hasRequiredAttributes(SedRemoveXML_t * srxml)
{
	return (srxml != NULL) ? static_cast<int>(srxml->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


