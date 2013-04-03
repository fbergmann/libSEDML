/**
 * @file:   SedMLOutput.cpp
 * @brief:  Implementation of the SedMLOutput class
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


#include <sedml/SedMLOutput.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedMLOutput with the given level, version, and package version.
 */
SedMLOutput::SedMLOutput (unsigned int level, unsigned int version)
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
 * Creates a new SedMLOutput with the given SedMLNamespaces object.
 */
SedMLOutput::SedMLOutput (SedMLNamespaces* sedmlns)
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
 * Copy constructor for SedMLOutput.
 */
SedMLOutput::SedMLOutput (const SedMLOutput& orig)
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
 * Assignment for SedMLOutput.
 */
SedMLOutput&
SedMLOutput::operator=(const SedMLOutput& rhs)
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
 * Clone for SedMLOutput.
 */
SedMLOutput*
SedMLOutput::clone () const
{
	return new SedMLOutput(*this);
}


/*
 * Destructor for SedMLOutput.
 */
SedMLOutput::~SedMLOutput ()
{
}


/*
 * Returns the value of the "id" attribute of this SedMLOutput.
 */
const std::string&
SedMLOutput::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedMLOutput.
 */
const std::string&
SedMLOutput::getName() const
{
	return mName;
}


/*
 * Returns true/false if id is set.
 */
bool
SedMLOutput::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedMLOutput::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedMLOutput::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedMLOutput::setName(const std::string& name)
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
SedMLOutput::unsetId()
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
SedMLOutput::unsetName()
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
SedMLOutput::getElementName () const
{
	static const string name = "output";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedMLOutput::createObject(XMLInputStream& stream)
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
SedMLOutput::connectToChild ()
{
	SedBase::connectToChild();

}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedMLOutput::getTypeCode () const
{
	return SEDML_OUTPUT;
}


/*
 * check if all the required attributes are set
 */
bool
SedMLOutput::hasRequiredAttributes () const
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
SedMLOutput::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedMLOutput::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
SedMLOutput::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
SedMLOutput::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedMLOutput::addExpectedAttributes(ExpectedAttributes& attributes)
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
SedMLOutput::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedMLOutput>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedMLOutput>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedMLOutput::writeAttributes (XMLOutputStream& stream) const
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
SedListOfSedMLOutputs::SedListOfSedMLOutputs(unsigned int level, 
	                      unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSedMLOutputs::SedListOfSedMLOutputs(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSedMLOutputs 
 */
SedListOfSedMLOutputs* 
SedListOfSedMLOutputs::clone () const
 {
	return new SedListOfSedMLOutputs(*this);
}


/*
 * Get a SedMLOutput from the SedListOfSedMLOutputs by index.
*/
SedMLOutput*
SedListOfSedMLOutputs::get(unsigned int n)
{
	return static_cast<SedMLOutput*>(SedListOf::get(n));
}


/*
 * Get a SedMLOutput from the SedListOfSedMLOutputs by index.
 */
const SedMLOutput*
SedListOfSedMLOutputs::get(unsigned int n) const
{
	return static_cast<const SedMLOutput*>(SedListOf::get(n));
}


/*
 * Get a SedMLOutput from the SedListOfSedMLOutputs by id.
 */
SedMLOutput*
SedListOfSedMLOutputs::get(const std::string& sid)
{
	return const_cast<SedMLOutput*>(
	  static_cast<const SedListOfSedMLOutputs&>(*this).get(sid));
}


/*
 * Get a SedMLOutput from the SedListOfSedMLOutputs by id.
 */
const SedMLOutput*
SedListOfSedMLOutputs::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLOutput>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedMLOutput*> (*result);
}


/*
 * Removes the nth SedMLOutput from this SedListOfSedMLOutputs
 */
SedMLOutput*
SedListOfSedMLOutputs::remove(unsigned int n)
{
	return static_cast<SedMLOutput*>(SedListOf::remove(n));
}


/*
 * Removes the SedMLOutput from this SedListOfSedMLOutputs with the given identifier
 */
SedMLOutput*
SedListOfSedMLOutputs::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLOutput>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedMLOutput*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSedMLOutputs::getElementName () const
{
	static const string name = "listOfOutputs";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSedMLOutputs::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSedMLOutputs::getItemTypeCode () const
{
	return SEDML_OUTPUT;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedMLOutput in this SedListOfSedMLOutputs
 */
SedBase*
SedListOfSedMLOutputs::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "sedMLOutput")
	{
		object = new SedMLOutput(getSedMLNamespaces());
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
SedListOfSedMLOutputs::writeXMLNS(XMLOutputStream& stream) const
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
SedMLOutput_t *
SedMLOutput_create(unsigned int level, unsigned int version)
{
	return new SedMLOutput(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedMLOutput_free(SedMLOutput_t * smlo)
{
	if (smlo != NULL)
		delete smlo;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLOutput_t *
SedMLOutput_clone(SedMLOutput_t * smlo)
{
	if (smlo != NULL)
	{
		return static_cast<SedMLOutput_t*>(smlo->clone());
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
SedMLOutput_getId(SedMLOutput_t * smlo)
{
	if (smlo == NULL)
		return NULL;

	return smlo->getId().empty() ? NULL : safe_strdup(smlo->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLOutput_getName(SedMLOutput_t * smlo)
{
	if (smlo == NULL)
		return NULL;

	return smlo->getName().empty() ? NULL : safe_strdup(smlo->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLOutput_isSetId(SedMLOutput_t * smlo)
{
	return (smlo != NULL) ? static_cast<int>(smlo->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLOutput_isSetName(SedMLOutput_t * smlo)
{
	return (smlo != NULL) ? static_cast<int>(smlo->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLOutput_setId(SedMLOutput_t * smlo, const char * id)
{
	return (smlo != NULL) ? smlo->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLOutput_setName(SedMLOutput_t * smlo, const char * name)
{
	return (smlo != NULL) ? smlo->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLOutput_unsetId(SedMLOutput_t * smlo)
{
	return (smlo != NULL) ? smlo->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLOutput_unsetName(SedMLOutput_t * smlo)
{
	return (smlo != NULL) ? smlo->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLOutput_hasRequiredAttributes(SedMLOutput_t * smlo)
{
	return (smlo != NULL) ? static_cast<int>(smlo->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLOutput_hasRequiredElements(SedMLOutput_t * smlo)
{
	return (smlo != NULL) ? static_cast<int>(smlo->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLOutput_t *
SedListOfSedMLOutputs_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLOutputs *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLOutput_t *
SedListOfSedMLOutputs_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLOutputs *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


