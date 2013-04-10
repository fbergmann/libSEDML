/**
 * @file:   SedChange.cpp
 * @brief:  Implementation of the SedChange class
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


#include <sedml/SedChange.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedChange with the given level, version, and package version.
 */
SedChange::SedChange (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mTarget ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedChange with the given SedNamespaces object.
 */
SedChange::SedChange (SedNamespaces* sedns)
	: SedBase(sedns)
	, mTarget ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedChange.
 */
SedChange::SedChange (const SedChange& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mTarget  = orig.mTarget;
	}
}


/*
 * Assignment for SedChange.
 */
SedChange&
SedChange::operator=(const SedChange& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mTarget  = rhs.mTarget;
	}
	return *this;
}


/*
 * Clone for SedChange.
 */
SedChange*
SedChange::clone () const
{
	return new SedChange(*this);
}


/*
 * Destructor for SedChange.
 */
SedChange::~SedChange ()
{
}


/*
 * Returns the value of the "target" attribute of this SedChange.
 */
const std::string&
SedChange::getTarget() const
{
	return mTarget;
}


/*
 * Returns true/false if target is set.
 */
bool
SedChange::isSetTarget() const
{
	return (mTarget.empty() == false);
}


/*
 * Sets target and returns value indicating success.
 */
int
SedChange::setTarget(const std::string& target)
{
	if (&(target) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mTarget = target;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets target and returns value indicating success.
 */
int
SedChange::unsetTarget()
{
	mTarget.erase();

	if (mTarget.empty() == true)
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
SedChange::getElementName () const
{
	static const string name = "change";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedChange::getTypeCode () const
{
	return SEDML_CHANGE;
}


/*
 * check if all the required attributes are set
 */
bool
SedChange::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetTarget() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedChange::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedChange::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedChange::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedChange::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("target");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedChange::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// target string   ( use = "required" )
	//
	assigned = attributes.readInto("target", mTarget, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty

		if (mTarget.empty() == true)
		{
			logEmptyString(mTarget, getLevel(), getVersion(), "<SedChange>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedChange::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetTarget() == true)
		stream.writeAttribute("target", getPrefix(), mTarget);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfSedChanges::SedListOfSedChanges(unsigned int level, 
	                    unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSedChanges::SedListOfSedChanges(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSedChanges 
 */
SedListOfSedChanges* 
SedListOfSedChanges::clone () const
 {
	return new SedListOfSedChanges(*this);
}


/*
 * Get a SedChange from the SedListOfSedChanges by index.
*/
SedChange*
SedListOfSedChanges::get(unsigned int n)
{
	return static_cast<SedChange*>(SedListOf::get(n));
}


/*
 * Get a SedChange from the SedListOfSedChanges by index.
 */
const SedChange*
SedListOfSedChanges::get(unsigned int n) const
{
	return static_cast<const SedChange*>(SedListOf::get(n));
}


/*
 * Get a SedChange from the SedListOfSedChanges by id.
 */
SedChange*
SedListOfSedChanges::get(const std::string& sid)
{
	return const_cast<SedChange*>(
	  static_cast<const SedListOfSedChanges&>(*this).get(sid));
}


/*
 * Get a SedChange from the SedListOfSedChanges by id.
 */
const SedChange*
SedListOfSedChanges::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedChange>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedChange*> (*result);
}


/*
 * Removes the nth SedChange from this SedListOfSedChanges
 */
SedChange*
SedListOfSedChanges::remove(unsigned int n)
{
	return static_cast<SedChange*>(SedListOf::remove(n));
}


/*
 * Removes the SedChange from this SedListOfSedChanges with the given identifier
 */
SedChange*
SedListOfSedChanges::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedChange>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedChange*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSedChanges::getElementName () const
{
	static const string name = "listOfChanges";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSedChanges::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSedChanges::getItemTypeCode () const
{
	return SEDML_CHANGE;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedChange in this SedListOfSedChanges
 */
SedBase*
SedListOfSedChanges::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "removeXML")
	{
		object = new SedRemoveXML(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "changeAttribute")
	{
		object = new SedChangeAttribute(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "computeChange")
	{
		object = new SedComputeChange(getSedNamespaces());
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
SedListOfSedChanges::writeXMLNS(XMLOutputStream& stream) const
{
	XMLNamespaces xmlns;

	std::string prefix = getPrefix();

	if (prefix.empty())
	{
		if (getNamespaces() != NULL && !getNamespaces()->hasURI(SEDML_XMLNS_L1))
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
SedChange_t *
SedChange_create(unsigned int level, unsigned int version)
{
	return new SedChange(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedChange_free(SedChange_t * sc)
{
	if (sc != NULL)
		delete sc;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedChange_t *
SedChange_clone(SedChange_t * sc)
{
	if (sc != NULL)
	{
		return static_cast<SedChange_t*>(sc->clone());
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
SedChange_getTarget(SedChange_t * sc)
{
	if (sc == NULL)
		return NULL;

	return sc->getTarget().empty() ? NULL : safe_strdup(sc->getTarget().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedChange_isSetTarget(SedChange_t * sc)
{
	return (sc != NULL) ? static_cast<int>(sc->isSetTarget()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedChange_setTarget(SedChange_t * sc, const char * target)
{
	return (sc != NULL) ? sc->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedChange_unsetTarget(SedChange_t * sc)
{
	return (sc != NULL) ? sc->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedChange_hasRequiredAttributes(SedChange_t * sc)
{
	return (sc != NULL) ? static_cast<int>(sc->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedChange_t *
SedListOfSedChanges_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedChanges *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedChange_t *
SedListOfSedChanges_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedChanges *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


