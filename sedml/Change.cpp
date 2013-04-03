/**
 * @file:   Change.cpp
 * @brief:  Implementation of the Change class
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


#include <sedml/Change.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Change with the given level, version, and package version.
 */
Change::Change (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mTarget ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new Change with the given SedMLNamespaces object.
 */
Change::Change (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mTarget ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for Change.
 */
Change::Change (const Change& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mTarget  = orig.mTarget;
	}
}


/*
 * Assignment for Change.
 */
Change&
Change::operator=(const Change& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mTarget  = rhs.mTarget;
	}
	return *this;
}


/*
 * Clone for Change.
 */
Change*
Change::clone () const
{
	return new Change(*this);
}


/*
 * Destructor for Change.
 */
Change::~Change ()
{
}


/*
 * Returns the value of the "target" attribute of this Change.
 */
const std::string&
Change::getTarget() const
{
	return mTarget;
}


/*
 * Returns true/false if target is set.
 */
bool
Change::isSetTarget() const
{
	return (mTarget.empty() == false);
}


/*
 * Sets target and returns value indicating success.
 */
int
Change::setTarget(const std::string& target)
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
Change::unsetTarget()
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
Change::getElementName () const
{
	static const string name = "change";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Change::getTypeCode () const
{
	return SEDML_CHANGE;
}


/*
 * check if all the required attributes are set
 */
bool
Change::hasRequiredAttributes () const
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
Change::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Change::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Change::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Change::addExpectedAttributes(ExpectedAttributes& attributes)
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
Change::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mTarget, getLevel(), getVersion(), "<Change>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
Change::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetTarget() == true)
		stream.writeAttribute("target", getPrefix(), mTarget);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfChanges::SedListOfChanges(unsigned int level, 
	                 unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfChanges::SedListOfChanges(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfChanges 
 */
SedListOfChanges* 
SedListOfChanges::clone () const
 {
	return new SedListOfChanges(*this);
}


/*
 * Get a Change from the SedListOfChanges by index.
*/
Change*
SedListOfChanges::get(unsigned int n)
{
	return static_cast<Change*>(SedListOf::get(n));
}


/*
 * Get a Change from the SedListOfChanges by index.
 */
const Change*
SedListOfChanges::get(unsigned int n) const
{
	return static_cast<const Change*>(SedListOf::get(n));
}


/*
 * Get a Change from the SedListOfChanges by id.
 */
Change*
SedListOfChanges::get(const std::string& sid)
{
	return const_cast<Change*>(
	  static_cast<const SedListOfChanges&>(*this).get(sid));
}


/*
 * Get a Change from the SedListOfChanges by id.
 */
const Change*
SedListOfChanges::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Change>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <Change*> (*result);
}


/*
 * Removes the nth Change from this SedListOfChanges
 */
Change*
SedListOfChanges::remove(unsigned int n)
{
	return static_cast<Change*>(SedListOf::remove(n));
}


/*
 * Removes the Change from this SedListOfChanges with the given identifier
 */
Change*
SedListOfChanges::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Change>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <Change*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfChanges::getElementName () const
{
	static const string name = "listOfChanges";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfChanges::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfChanges::getItemTypeCode () const
{
	return SEDML_CHANGE;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new Change in this SedListOfChanges
 */
SedBase*
SedListOfChanges::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "change")
	{
		object = new Change(getSedMLNamespaces());
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
SedListOfChanges::writeXMLNS(XMLOutputStream& stream) const
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
Change_t *
Change_create(unsigned int level, unsigned int version)
{
	return new Change(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Change_free(Change_t * c)
{
	if (c != NULL)
		delete c;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Change_t *
Change_clone(Change_t * c)
{
	if (c != NULL)
	{
		return static_cast<Change_t*>(c->clone());
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
Change_getTarget(Change_t * c)
{
	if (c == NULL)
		return NULL;

	return c->getTarget().empty() ? NULL : safe_strdup(c->getTarget().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Change_isSetTarget(Change_t * c)
{
	return (c != NULL) ? static_cast<int>(c->isSetTarget()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Change_setTarget(Change_t * c, const char * target)
{
	return (c != NULL) ? c->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Change_unsetTarget(Change_t * c)
{
	return (c != NULL) ? c->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Change_hasRequiredAttributes(Change_t * c)
{
	return (c != NULL) ? static_cast<int>(c->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Change_t *
SedListOfChanges_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfChanges *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Change_t *
SedListOfChanges_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfChanges *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


