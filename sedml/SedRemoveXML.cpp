/**
 * @file:   RemoveXML.cpp
 * @brief:  Implementation of the RemoveXML class
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


#include <sedml/RemoveXML.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new RemoveXML with the given level, version, and package version.
 */
RemoveXML::RemoveXML (unsigned int level, unsigned int version)
	: Change(level, version)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new RemoveXML with the given SedMLNamespaces object.
 */
RemoveXML::RemoveXML (SedMLNamespaces* sedmlns)
	: Change(sedmlns)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for RemoveXML.
 */
RemoveXML::RemoveXML (const RemoveXML& orig)
	: Change(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
	}
}


/*
 * Assignment for RemoveXML.
 */
RemoveXML&
RemoveXML::operator=(const RemoveXML& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		Change::operator=(rhs);
	}
	return *this;
}


/*
 * Clone for RemoveXML.
 */
RemoveXML*
RemoveXML::clone () const
{
	return new RemoveXML(*this);
}


/*
 * Destructor for RemoveXML.
 */
RemoveXML::~RemoveXML ()
{
}


/*
 * Returns the XML element name of this object
 */
const std::string&
RemoveXML::getElementName () const
{
	static const string name = "removeXML";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
RemoveXML::createObject(XMLInputStream& stream)
{
	SedBase* object = Change::createObject(stream);

	const string& name   = stream.peek().getName();

	Change::connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
RemoveXML::getTypeCode () const
{
	return SEDML_CHANGE_REMOVEXML;
}


/*
 * check if all the required attributes are set
 */
bool
RemoveXML::hasRequiredAttributes () const
{
	bool allPresent = Change::hasRequiredAttributes();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
RemoveXML::writeElements (XMLOutputStream& stream) const
{
	Change::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
RemoveXML::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
RemoveXML::setSedMLDocument (SedMLDocument* d)
{
	Change::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
RemoveXML::addExpectedAttributes(ExpectedAttributes& attributes)
{
	Change::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
RemoveXML::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	Change::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
RemoveXML::writeAttributes (XMLOutputStream& stream) const
{
	Change::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
RemoveXML_t *
RemoveXML_create(unsigned int level, unsigned int version)
{
	return new RemoveXML(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
RemoveXML_free(RemoveXML_t * rxml)
{
	if (rxml != NULL)
		delete rxml;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
RemoveXML_t *
RemoveXML_clone(RemoveXML_t * rxml)
{
	if (rxml != NULL)
	{
		return static_cast<RemoveXML_t*>(rxml->clone());
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
RemoveXML_hasRequiredAttributes(RemoveXML_t * rxml)
{
	return (rxml != NULL) ? static_cast<int>(rxml->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


