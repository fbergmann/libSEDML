/**
 * @file:   Surface.cpp
 * @brief:  Implementation of the Surface class
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


#include <sedml/Surface.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Surface with the given level, version, and package version.
 */
Surface::Surface (unsigned int level, unsigned int version)
	: SedMLCurve(level, version)
	, mLogZ (false)
	, mIsSetLogZ (false)
	, mZDataReference ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new Surface with the given SedMLNamespaces object.
 */
Surface::Surface (SedMLNamespaces* sedmlns)
	: SedMLCurve(sedmlns)
	, mLogZ (false)
	, mIsSetLogZ (false)
	, mZDataReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for Surface.
 */
Surface::Surface (const Surface& orig)
	: SedMLCurve(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mLogZ  = orig.mLogZ;
		mIsSetLogZ  = orig.mIsSetLogZ;
		mZDataReference  = orig.mZDataReference;
	}
}


/*
 * Assignment for Surface.
 */
Surface&
Surface::operator=(const Surface& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedMLCurve::operator=(rhs);
		mLogZ  = rhs.mLogZ;
		mIsSetLogZ  = rhs.mIsSetLogZ;
		mZDataReference  = rhs.mZDataReference;
	}
	return *this;
}


/*
 * Clone for Surface.
 */
Surface*
Surface::clone () const
{
	return new Surface(*this);
}


/*
 * Destructor for Surface.
 */
Surface::~Surface ()
{
}


/*
 * Returns the value of the "logZ" attribute of this Surface.
 */
const bool
Surface::getLogZ() const
{
	return mLogZ;
}


/*
/*
 * Returns the value of the "zDataReference" attribute of this Surface.
 */
const std::string&
Surface::getZDataReference() const
{
	return mZDataReference;
}


/*
/*
 * Returns true/false if logZ is set.
 */
bool
Surface::isSetLogZ() const
{
	return mIsSetLogZ;
}


/*
 * Returns true/false if zDataReference is set.
 */
bool
Surface::isSetZDataReference() const
{
	return (mZDataReference.empty() == false);
}


/*
 * Sets logZ and returns value indicating success.
 */
int
Surface::setLogZ(bool logZ)
{
	mLogZ = logZ;
	mIsSetLogZ = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets zDataReference and returns value indicating success.
 */
int
Surface::setZDataReference(const std::string& zDataReference)
{
	if (&(zDataReference) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(zDataReference)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mZDataReference = zDataReference;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets logZ and returns value indicating success.
 */
int
Surface::unsetLogZ()
{
	mLogZ = false;
	mIsSetLogZ = false;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets zDataReference and returns value indicating success.
 */
int
Surface::unsetZDataReference()
{
	mZDataReference.erase();

	if (mZDataReference.empty() == true)
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
Surface::getElementName () const
{
	static const string name = "surface";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Surface::getTypeCode () const
{
	return SEDML_OUTPUT_SURFACE;
}


/*
 * check if all the required attributes are set
 */
bool
Surface::hasRequiredAttributes () const
{
	bool allPresent = SedMLCurve::hasRequiredAttributes();

	if (isSetLogZ() == false)
		allPresent = false;

	if (isSetZDataReference() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
Surface::writeElements (XMLOutputStream& stream) const
{
	SedMLCurve::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Surface::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Surface::setSedMLDocument (SedMLDocument* d)
{
	SedMLCurve::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Surface::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedMLCurve::addExpectedAttributes(attributes);

	attributes.add("logZ");
	attributes.add("zDataReference");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Surface::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedMLCurve::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// logZ bool   ( use = "required" )
	//
	mIsSetLogZ = attributes.readInto("logZ", mLogZ, getErrorLog(), true);

	//
	// zDataReference SIdRef   ( use = "required" )
	//
	assigned = attributes.readInto("zDataReference", mZDataReference, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mZDataReference.empty() == true)
		{
			logEmptyString(mZDataReference, getLevel(), getVersion(), "<Surface>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mZDataReference) == false)
		{
			logError(InvalidIdSyntax);
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
Surface::writeAttributes (XMLOutputStream& stream) const
{
	SedMLCurve::writeAttributes(stream);

	if (isSetLogZ() == true)
		stream.writeAttribute("logZ", getPrefix(), mLogZ);

	if (isSetZDataReference() == true)
		stream.writeAttribute("zDataReference", getPrefix(), mZDataReference);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfSurfaces::SedListOfSurfaces(unsigned int level, 
	                  unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSurfaces::SedListOfSurfaces(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSurfaces 
 */
SedListOfSurfaces* 
SedListOfSurfaces::clone () const
 {
	return new SedListOfSurfaces(*this);
}


/*
 * Get a Surface from the SedListOfSurfaces by index.
*/
Surface*
SedListOfSurfaces::get(unsigned int n)
{
	return static_cast<Surface*>(SedListOf::get(n));
}


/*
 * Get a Surface from the SedListOfSurfaces by index.
 */
const Surface*
SedListOfSurfaces::get(unsigned int n) const
{
	return static_cast<const Surface*>(SedListOf::get(n));
}


/*
 * Get a Surface from the SedListOfSurfaces by id.
 */
Surface*
SedListOfSurfaces::get(const std::string& sid)
{
	return const_cast<Surface*>(
	  static_cast<const SedListOfSurfaces&>(*this).get(sid));
}


/*
 * Get a Surface from the SedListOfSurfaces by id.
 */
const Surface*
SedListOfSurfaces::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Surface>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <Surface*> (*result);
}


/*
 * Removes the nth Surface from this SedListOfSurfaces
 */
Surface*
SedListOfSurfaces::remove(unsigned int n)
{
	return static_cast<Surface*>(SedListOf::remove(n));
}


/*
 * Removes the Surface from this SedListOfSurfaces with the given identifier
 */
Surface*
SedListOfSurfaces::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Surface>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <Surface*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSurfaces::getElementName () const
{
	static const string name = "listOfSurfaces";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSurfaces::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSurfaces::getItemTypeCode () const
{
	return SEDML_OUTPUT_SURFACE;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new Surface in this SedListOfSurfaces
 */
SedBase*
SedListOfSurfaces::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "surface")
	{
		object = new Surface(getSedMLNamespaces());
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
SedListOfSurfaces::writeXMLNS(XMLOutputStream& stream) const
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
Surface_t *
Surface_create(unsigned int level, unsigned int version)
{
	return new Surface(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Surface_free(Surface_t * s)
{
	if (s != NULL)
		delete s;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Surface_t *
Surface_clone(Surface_t * s)
{
	if (s != NULL)
	{
		return static_cast<Surface_t*>(s->clone());
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
Surface_getLogZ(Surface_t * s)
{
	return (s != NULL) ? static_cast<int>(s->getLogZ()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
Surface_getZDataReference(Surface_t * s)
{
	if (s == NULL)
		return NULL;

	return s->getZDataReference().empty() ? NULL : safe_strdup(s->getZDataReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Surface_isSetLogZ(Surface_t * s)
{
	return (s != NULL) ? static_cast<int>(s->isSetLogZ()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Surface_isSetZDataReference(Surface_t * s)
{
	return (s != NULL) ? static_cast<int>(s->isSetZDataReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Surface_setLogZ(Surface_t * s, int logZ)
{
	return (s != NULL) ? s->setLogZ(logZ) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Surface_setZDataReference(Surface_t * s, const char * zDataReference)
{
	return (s != NULL) ? s->setZDataReference(zDataReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Surface_unsetLogZ(Surface_t * s)
{
	return (s != NULL) ? s->unsetLogZ() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Surface_unsetZDataReference(Surface_t * s)
{
	return (s != NULL) ? s->unsetZDataReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Surface_hasRequiredAttributes(Surface_t * s)
{
	return (s != NULL) ? static_cast<int>(s->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Surface_t *
SedListOfSurfaces_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSurfaces *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Surface_t *
SedListOfSurfaces_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSurfaces *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


