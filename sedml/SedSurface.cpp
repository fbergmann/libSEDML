/**
 * @file:   SedSurface.cpp
 * @brief:  Implementation of the SedSurface class
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


#include <sedml/SedSurface.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedSurface with the given level, version, and package version.
 */
SedSurface::SedSurface (unsigned int level, unsigned int version)
	: SedCurve(level, version)
	, mLogZ (false)
	, mIsSetLogZ (false)
	, mZDataReference ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSurface with the given SedNamespaces object.
 */
SedSurface::SedSurface (SedNamespaces* sedns)
	: SedCurve(sedns)
	, mLogZ (false)
	, mIsSetLogZ (false)
	, mZDataReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedSurface.
 */
SedSurface::SedSurface (const SedSurface& orig)
	: SedCurve(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mLogZ  = orig.mLogZ;
		mIsSetLogZ  = orig.mIsSetLogZ;
		mZDataReference  = orig.mZDataReference;
	}
}


/*
 * Assignment for SedSurface.
 */
SedSurface&
SedSurface::operator=(const SedSurface& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedCurve::operator=(rhs);
		mLogZ  = rhs.mLogZ;
		mIsSetLogZ  = rhs.mIsSetLogZ;
		mZDataReference  = rhs.mZDataReference;
	}
	return *this;
}


/*
 * Clone for SedSurface.
 */
SedSurface*
SedSurface::clone () const
{
	return new SedSurface(*this);
}


/*
 * Destructor for SedSurface.
 */
SedSurface::~SedSurface ()
{
}


/*
 * Returns the value of the "logZ" attribute of this SedSurface.
 */
const bool
SedSurface::getLogZ() const
{
	return mLogZ;
}


/*
 * Returns the value of the "zDataReference" attribute of this SedSurface.
 */
const std::string&
SedSurface::getZDataReference() const
{
	return mZDataReference;
}


/*
 * Returns true/false if logZ is set.
 */
bool
SedSurface::isSetLogZ() const
{
	return mIsSetLogZ;
}


/*
 * Returns true/false if zDataReference is set.
 */
bool
SedSurface::isSetZDataReference() const
{
	return (mZDataReference.empty() == false);
}


/*
 * Sets logZ and returns value indicating success.
 */
int
SedSurface::setLogZ(bool logZ)
{
	mLogZ = logZ;
	mIsSetLogZ = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets zDataReference and returns value indicating success.
 */
int
SedSurface::setZDataReference(const std::string& zDataReference)
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
SedSurface::unsetLogZ()
{
	mLogZ = false;
	mIsSetLogZ = false;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets zDataReference and returns value indicating success.
 */
int
SedSurface::unsetZDataReference()
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
SedSurface::getElementName () const
{
	static const string name = "surface";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedSurface::createObject(XMLInputStream& stream)
{
	SedBase* object = SedCurve::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedSurface::getTypeCode () const
{
	return SEDML_OUTPUT_SURFACE;
}


/*
 * check if all the required attributes are set
 */
bool
SedSurface::hasRequiredAttributes () const
{
	bool allPresent = SedCurve::hasRequiredAttributes();

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
SedSurface::writeElements (XMLOutputStream& stream) const
{
	SedCurve::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedSurface::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedSurface::setSedDocument (SedDocument* d)
{
	SedCurve::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedSurface::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedCurve::addExpectedAttributes(attributes);

	attributes.add("logZ");
	attributes.add("zDataReference");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedSurface::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedCurve::readAttributes(attributes, expectedAttributes);

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
			logEmptyString(mZDataReference, getLevel(), getVersion(), "<SedSurface>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mZDataReference) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedSurface::writeAttributes (XMLOutputStream& stream) const
{
	SedCurve::writeAttributes(stream);

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
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSurfaces::SedListOfSurfaces(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
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
SedSurface*
SedListOfSurfaces::get(unsigned int n)
{
	return static_cast<SedSurface*>(SedListOf::get(n));
}


/*
 * Get a Surface from the SedListOfSurfaces by index.
 */
const SedSurface*
SedListOfSurfaces::get(unsigned int n) const
{
	return static_cast<const SedSurface*>(SedListOf::get(n));
}


/*
 * Get a Surface from the SedListOfSurfaces by id.
 */
SedSurface*
SedListOfSurfaces::get(const std::string& sid)
{
	return const_cast<SedSurface*>(
	  static_cast<const SedListOfSurfaces&>(*this).get(sid));
}


/*
 * Get a Surface from the SedListOfSurfaces by id.
 */
const SedSurface*
SedListOfSurfaces::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedSurface>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedSurface*> (*result);
}


/**
 * Adds a copy the given "SedSurface" to this SedListOfSurfaces.
 *
 * @param ss; the SedSurface object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfSurfaces::addSurface(const SedSurface* ss)
{
	if(ss == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(ss);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSurface objects in this SedListOfSurfaces.
 *
 * @return the number of SedSurface objects in this SedListOfSurfaces
 */
unsigned int 
SedListOfSurfaces::getNumSurfaces() const
{
	return size();
}

/**
 * Creates a new SedSurface object, adds it to this SedListOfSurfacess
 * SedSurface and returns the SedSurface object created. 
 *
 * @return a new SedSurface object instance
 *
 * @see addSedSurface(const SedSurface* ss)
 */
SedSurface* 
SedListOfSurfaces::createSurface()
{
	SedSurface *temp = new SedSurface();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Surface from this SedListOfSurfaces
 */
SedSurface*
SedListOfSurfaces::remove(unsigned int n)
{
	return static_cast<SedSurface*>(SedListOf::remove(n));
}


/*
 * Removes the Surface from this SedListOfSurfaces with the given identifier
 */
SedSurface*
SedListOfSurfaces::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedSurface>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedSurface*> (item);
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
 * Creates a new SedSurface in this SedListOfSurfaces
 */
SedBase*
SedListOfSurfaces::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "surface")
	{
		object = new SedSurface(getSedNamespaces());
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
SedListOfSurfaces::writeXMLNS(XMLOutputStream& stream) const
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


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSurface_t *
SedSurface_create(unsigned int level, unsigned int version)
{
	return new SedSurface(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedSurface_free(SedSurface_t * ss)
{
	if (ss != NULL)
		delete ss;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSurface_t *
SedSurface_clone(SedSurface_t * ss)
{
	if (ss != NULL)
	{
		return static_cast<SedSurface_t*>(ss->clone());
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
SedSurface_getLogZ(SedSurface_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->getLogZ()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedSurface_getZDataReference(SedSurface_t * ss)
{
	if (ss == NULL)
		return NULL;

	return ss->getZDataReference().empty() ? NULL : safe_strdup(ss->getZDataReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSurface_isSetLogZ(SedSurface_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->isSetLogZ()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSurface_isSetZDataReference(SedSurface_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->isSetZDataReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSurface_setLogZ(SedSurface_t * ss, int logZ)
{
	return (ss != NULL) ? ss->setLogZ(logZ) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSurface_setZDataReference(SedSurface_t * ss, const char * zDataReference)
{
	return (ss != NULL) ? ss->setZDataReference(zDataReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSurface_unsetLogZ(SedSurface_t * ss)
{
	return (ss != NULL) ? ss->unsetLogZ() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSurface_unsetZDataReference(SedSurface_t * ss)
{
	return (ss != NULL) ? ss->unsetZDataReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSurface_hasRequiredAttributes(SedSurface_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSurface_t *
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
SedSurface_t *
SedListOfSurfaces_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSurfaces *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


