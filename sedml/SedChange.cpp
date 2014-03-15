/**
 * @file:   SedChange.cpp
 * @brief:  Implementation of the SedChange class
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


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedChange::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedChange::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedChange::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedChange::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("target");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

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


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

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


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor 
 */
SedListOfChanges::SedListOfChanges(unsigned int level, 
	                 unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfChanges::SedListOfChanges(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
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
SedChange*
SedListOfChanges::get(unsigned int n)
{
	return static_cast<SedChange*>(SedListOf::get(n));
}


/*
 * Get a Change from the SedListOfChanges by index.
 */
const SedChange*
SedListOfChanges::get(unsigned int n) const
{
	return static_cast<const SedChange*>(SedListOf::get(n));
}


/*
 * Get a Change from the SedListOfChanges by id.
 */
SedChange*
SedListOfChanges::get(const std::string& sid)
{
	return const_cast<SedChange*>(
	  static_cast<const SedListOfChanges&>(*this).get(sid));
}


/*
 * Get a Change from the SedListOfChanges by id.
 */
const SedChange*
SedListOfChanges::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedChange>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedChange*> (*result);
}


/**
 * Adds a copy the given "SedChange" to this SedListOfChanges.
 *
 * @param sc; the SedChange object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfChanges::addChange(const SedChange* sc)
{
	if(sc == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sc);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedChange objects in this SedListOfChanges.
 *
 * @return the number of SedChange objects in this SedListOfChanges
 */
unsigned int 
SedListOfChanges::getNumChanges() const
{
	return size();
}

/**
 * Creates a new SedAddXML object, adds it to this SedListOfChanges
 * addXML and returns the SedAddXML object created. 
 *
 * @return a new SedAddXML object instance
 *
 * @see addAddXML(const SedChange* sc)
 */
SedAddXML* 
SedListOfChanges::createAddXML()
{
	SedAddXML *temp = new SedAddXML();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedChangeXML object, adds it to this SedListOfChanges
 * changeXML and returns the SedChangeXML object created. 
 *
 * @return a new SedChangeXML object instance
 *
 * @see addChangeXML(const SedChange* sc)
 */
SedChangeXML* 
SedListOfChanges::createChangeXML()
{
	SedChangeXML *temp = new SedChangeXML();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedRemoveXML object, adds it to this SedListOfChanges
 * removeXML and returns the SedRemoveXML object created. 
 *
 * @return a new SedRemoveXML object instance
 *
 * @see addRemoveXML(const SedChange* sc)
 */
SedRemoveXML* 
SedListOfChanges::createRemoveXML()
{
	SedRemoveXML *temp = new SedRemoveXML();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedChangeAttribute object, adds it to this SedListOfChanges
 * changeAttribute and returns the SedChangeAttribute object created. 
 *
 * @return a new SedChangeAttribute object instance
 *
 * @see addChangeAttribute(const SedChange* sc)
 */
SedChangeAttribute* 
SedListOfChanges::createChangeAttribute()
{
	SedChangeAttribute *temp = new SedChangeAttribute();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedComputeChange object, adds it to this SedListOfChanges
 * computeChange and returns the SedComputeChange object created. 
 *
 * @return a new SedComputeChange object instance
 *
 * @see addComputeChange(const SedChange* sc)
 */
SedComputeChange* 
SedListOfChanges::createComputeChange()
{
	SedComputeChange *temp = new SedComputeChange();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Change from this SedListOfChanges
 */
SedChange*
SedListOfChanges::remove(unsigned int n)
{
	return static_cast<SedChange*>(SedListOf::remove(n));
}


/*
 * Removes the Change from this SedListOfChanges with the given identifier
 */
SedChange*
SedListOfChanges::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedChange>(sid) );

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


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedChange in this SedListOfChanges
 */
SedBase*
SedListOfChanges::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "addXML")
	{
		object = new SedAddXML(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "changeXML")
	{
		object = new SedChangeXML(getSedNamespaces());
		appendAndOwn(object);
	}

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


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write the namespace for the Sed package.
 */
void
SedListOfChanges::writeXMLNS(XMLOutputStream& stream) const
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


/** @endcond doxygen-libsedml-internal */


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
SedChange_t *
SedListOfChanges_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfChanges *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


