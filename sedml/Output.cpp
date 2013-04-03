/**
 * @file:   Output.cpp
 * @brief:  Implementation of the Output class
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


#include <sedml/Output.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Output with the given level, version, and package version.
 */
Output::Output (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new Output with the given SedMLNamespaces object.
 */
Output::Output (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mName ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for Output.
 */
Output::Output (const Output& orig)
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

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for Output.
 */
Output&
Output::operator=(const Output& rhs)
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

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for Output.
 */
Output*
Output::clone () const
{
	return new Output(*this);
}


/*
 * Destructor for Output.
 */
Output::~Output ()
{
}


/*
 * Returns the value of the "id" attribute of this Output.
 */
const std::string&
Output::getId() const
{
	return mId;
}


/*
/*
 * Returns the value of the "name" attribute of this Output.
 */
const std::string&
Output::getName() const
{
	return mName;
}


/*
/*
 * Returns true/false if id is set.
 */
bool
Output::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
Output::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
Output::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
Output::setName(const std::string& name)
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
 * Unsets id and returns value indicating success.
 */
int
Output::unsetId()
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
Output::unsetName()
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
 * Returns the XML element name of this object
 */
const std::string&
Output::getElementName () const
{
	static const string name = "output";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
Output::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	SedBase::connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Output::connectToChild ()
{
	SedBase::connectToChild();

}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Output::getTypeCode () const
{
	return SEDML_OUTPUT;
}


/*
 * check if all the required attributes are set
 */
bool
Output::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetId() == false)
		allPresent = false;

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
Output::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
Output::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Output::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Output::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Output::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Output::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<Output>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<Output>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
Output::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfOutputs::SedListOfOutputs(unsigned int level, 
	                 unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfOutputs::SedListOfOutputs(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfOutputs 
 */
SedListOfOutputs* 
SedListOfOutputs::clone () const
 {
	return new SedListOfOutputs(*this);
}


/*
 * Get a Output from the SedListOfOutputs by index.
*/
Output*
SedListOfOutputs::get(unsigned int n)
{
	return static_cast<Output*>(SedListOf::get(n));
}


/*
 * Get a Output from the SedListOfOutputs by index.
 */
const Output*
SedListOfOutputs::get(unsigned int n) const
{
	return static_cast<const Output*>(SedListOf::get(n));
}


/*
 * Get a Output from the SedListOfOutputs by id.
 */
Output*
SedListOfOutputs::get(const std::string& sid)
{
	return const_cast<Output*>(
	  static_cast<const SedListOfOutputs&>(*this).get(sid));
}


/*
 * Get a Output from the SedListOfOutputs by id.
 */
const Output*
SedListOfOutputs::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Output>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <Output*> (*result);
}


/*
 * Removes the nth Output from this SedListOfOutputs
 */
Output*
SedListOfOutputs::remove(unsigned int n)
{
	return static_cast<Output*>(SedListOf::remove(n));
}


/*
 * Removes the Output from this SedListOfOutputs with the given identifier
 */
Output*
SedListOfOutputs::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Output>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <Output*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfOutputs::getElementName () const
{
	static const string name = "listOfOutputs";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfOutputs::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfOutputs::getItemTypeCode () const
{
	return SEDML_OUTPUT;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new Output in this SedListOfOutputs
 */
SedBase*
SedListOfOutputs::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "output")
	{
		object = new Output(getSedMLNamespaces());
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
SedListOfOutputs::writeXMLNS(XMLOutputStream& stream) const
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
Output_t *
Output_create(unsigned int level, unsigned int version)
{
	return new Output(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Output_free(Output_t * o)
{
	if (o != NULL)
		delete o;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Output_t *
Output_clone(Output_t * o)
{
	if (o != NULL)
	{
		return static_cast<Output_t*>(o->clone());
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
Output_getId(Output_t * o)
{
	if (o == NULL)
		return NULL;

	return o->getId().empty() ? NULL : safe_strdup(o->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
Output_getName(Output_t * o)
{
	if (o == NULL)
		return NULL;

	return o->getName().empty() ? NULL : safe_strdup(o->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Output_isSetId(Output_t * o)
{
	return (o != NULL) ? static_cast<int>(o->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Output_isSetName(Output_t * o)
{
	return (o != NULL) ? static_cast<int>(o->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Output_setId(Output_t * o, const char * id)
{
	return (o != NULL) ? o->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Output_setName(Output_t * o, const char * name)
{
	return (o != NULL) ? o->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Output_unsetId(Output_t * o)
{
	return (o != NULL) ? o->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Output_unsetName(Output_t * o)
{
	return (o != NULL) ? o->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Output_hasRequiredAttributes(Output_t * o)
{
	return (o != NULL) ? static_cast<int>(o->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Output_hasRequiredElements(Output_t * o)
{
	return (o != NULL) ? static_cast<int>(o->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Output_t *
SedListOfOutputs_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfOutputs *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Output_t *
SedListOfOutputs_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfOutputs *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


