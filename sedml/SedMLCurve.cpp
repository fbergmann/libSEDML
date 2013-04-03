/**
 * @file:   SedMLCurve.cpp
 * @brief:  Implementation of the SedMLCurve class
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


#include <sedml/SedMLCurve.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedMLCurve with the given level, version, and package version.
 */
SedMLCurve::SedMLCurve (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mLogX (false)
	, mIsSetLogX (false)
	, mLogY (false)
	, mIsSetLogY (false)
	, mXDataReference ("")
	, mYDataReference ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new SedMLCurve with the given SedMLNamespaces object.
 */
SedMLCurve::SedMLCurve (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mName ("")
	, mLogX (false)
	, mIsSetLogX (false)
	, mLogY (false)
	, mIsSetLogY (false)
	, mXDataReference ("")
	, mYDataReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedMLCurve.
 */
SedMLCurve::SedMLCurve (const SedMLCurve& orig)
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
		mLogX  = orig.mLogX;
		mIsSetLogX  = orig.mIsSetLogX;
		mLogY  = orig.mLogY;
		mIsSetLogY  = orig.mIsSetLogY;
		mXDataReference  = orig.mXDataReference;
		mYDataReference  = orig.mYDataReference;
	}
}


/*
 * Assignment for SedMLCurve.
 */
SedMLCurve&
SedMLCurve::operator=(const SedMLCurve& rhs)
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
		mLogX  = rhs.mLogX;
		mIsSetLogX  = rhs.mIsSetLogX;
		mLogY  = rhs.mLogY;
		mIsSetLogY  = rhs.mIsSetLogY;
		mXDataReference  = rhs.mXDataReference;
		mYDataReference  = rhs.mYDataReference;
	}
	return *this;
}


/*
 * Clone for SedMLCurve.
 */
SedMLCurve*
SedMLCurve::clone () const
{
	return new SedMLCurve(*this);
}


/*
 * Destructor for SedMLCurve.
 */
SedMLCurve::~SedMLCurve ()
{
}


/*
 * Returns the value of the "id" attribute of this SedMLCurve.
 */
const std::string&
SedMLCurve::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedMLCurve.
 */
const std::string&
SedMLCurve::getName() const
{
	return mName;
}


/*
 * Returns the value of the "logX" attribute of this SedMLCurve.
 */
const bool
SedMLCurve::getLogX() const
{
	return mLogX;
}


/*
 * Returns the value of the "logY" attribute of this SedMLCurve.
 */
const bool
SedMLCurve::getLogY() const
{
	return mLogY;
}


/*
 * Returns the value of the "xDataReference" attribute of this SedMLCurve.
 */
const std::string&
SedMLCurve::getXDataReference() const
{
	return mXDataReference;
}


/*
 * Returns the value of the "yDataReference" attribute of this SedMLCurve.
 */
const std::string&
SedMLCurve::getYDataReference() const
{
	return mYDataReference;
}


/*
 * Returns true/false if id is set.
 */
bool
SedMLCurve::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedMLCurve::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if logX is set.
 */
bool
SedMLCurve::isSetLogX() const
{
	return mIsSetLogX;
}


/*
 * Returns true/false if logY is set.
 */
bool
SedMLCurve::isSetLogY() const
{
	return mIsSetLogY;
}


/*
 * Returns true/false if xDataReference is set.
 */
bool
SedMLCurve::isSetXDataReference() const
{
	return (mXDataReference.empty() == false);
}


/*
 * Returns true/false if yDataReference is set.
 */
bool
SedMLCurve::isSetYDataReference() const
{
	return (mYDataReference.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedMLCurve::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedMLCurve::setName(const std::string& name)
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
 * Sets logX and returns value indicating success.
 */
int
SedMLCurve::setLogX(bool logX)
{
	mLogX = logX;
	mIsSetLogX = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets logY and returns value indicating success.
 */
int
SedMLCurve::setLogY(bool logY)
{
	mLogY = logY;
	mIsSetLogY = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets xDataReference and returns value indicating success.
 */
int
SedMLCurve::setXDataReference(const std::string& xDataReference)
{
	if (&(xDataReference) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(xDataReference)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mXDataReference = xDataReference;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets yDataReference and returns value indicating success.
 */
int
SedMLCurve::setYDataReference(const std::string& yDataReference)
{
	if (&(yDataReference) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(yDataReference)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mYDataReference = yDataReference;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedMLCurve::unsetId()
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
SedMLCurve::unsetName()
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
 * Unsets logX and returns value indicating success.
 */
int
SedMLCurve::unsetLogX()
{
	mLogX = false;
	mIsSetLogX = false;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets logY and returns value indicating success.
 */
int
SedMLCurve::unsetLogY()
{
	mLogY = false;
	mIsSetLogY = false;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets xDataReference and returns value indicating success.
 */
int
SedMLCurve::unsetXDataReference()
{
	mXDataReference.erase();

	if (mXDataReference.empty() == true)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets yDataReference and returns value indicating success.
 */
int
SedMLCurve::unsetYDataReference()
{
	mYDataReference.erase();

	if (mYDataReference.empty() == true)
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
SedMLCurve::getElementName () const
{
	static const string name = "curve";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedMLCurve::getTypeCode () const
{
	return SEDML_OUTPUT_CURVE;
}


/*
 * check if all the required attributes are set
 */
bool
SedMLCurve::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetLogX() == false)
		allPresent = false;

	if (isSetLogY() == false)
		allPresent = false;

	if (isSetXDataReference() == false)
		allPresent = false;

	if (isSetYDataReference() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedMLCurve::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
SedMLCurve::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
SedMLCurve::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedMLCurve::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
	attributes.add("logX");
	attributes.add("logY");
	attributes.add("xDataReference");
	attributes.add("yDataReference");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedMLCurve::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// id SId  ( use = "optional" )
	//
	assigned = attributes.readInto("id", mId, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mId.empty() == true)
		{
			logEmptyString(mId, getLevel(), getVersion(), "<SedMLCurve>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedMLCurve>");
		}
	}

	//
	// logX bool   ( use = "required" )
	//
	mIsSetLogX = attributes.readInto("logX", mLogX, getErrorLog(), true);

	//
	// logY bool   ( use = "required" )
	//
	mIsSetLogY = attributes.readInto("logY", mLogY, getErrorLog(), true);

	//
	// xDataReference SIdRef   ( use = "required" )
	//
	assigned = attributes.readInto("xDataReference", mXDataReference, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mXDataReference.empty() == true)
		{
			logEmptyString(mXDataReference, getLevel(), getVersion(), "<SedMLCurve>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mXDataReference) == false)
		{
			logError(InvalidIdSyntax);
		}
	}

	//
	// yDataReference SIdRef   ( use = "required" )
	//
	assigned = attributes.readInto("yDataReference", mYDataReference, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mYDataReference.empty() == true)
		{
			logEmptyString(mYDataReference, getLevel(), getVersion(), "<SedMLCurve>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mYDataReference) == false)
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
SedMLCurve::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

	if (isSetLogX() == true)
		stream.writeAttribute("logX", getPrefix(), mLogX);

	if (isSetLogY() == true)
		stream.writeAttribute("logY", getPrefix(), mLogY);

	if (isSetXDataReference() == true)
		stream.writeAttribute("xDataReference", getPrefix(), mXDataReference);

	if (isSetYDataReference() == true)
		stream.writeAttribute("yDataReference", getPrefix(), mYDataReference);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfSedMLCurves::SedListOfSedMLCurves(unsigned int level, 
	                     unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSedMLCurves::SedListOfSedMLCurves(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSedMLCurves 
 */
SedListOfSedMLCurves* 
SedListOfSedMLCurves::clone () const
 {
	return new SedListOfSedMLCurves(*this);
}


/*
 * Get a SedMLCurve from the SedListOfSedMLCurves by index.
*/
SedMLCurve*
SedListOfSedMLCurves::get(unsigned int n)
{
	return static_cast<SedMLCurve*>(SedListOf::get(n));
}


/*
 * Get a SedMLCurve from the SedListOfSedMLCurves by index.
 */
const SedMLCurve*
SedListOfSedMLCurves::get(unsigned int n) const
{
	return static_cast<const SedMLCurve*>(SedListOf::get(n));
}


/*
 * Get a SedMLCurve from the SedListOfSedMLCurves by id.
 */
SedMLCurve*
SedListOfSedMLCurves::get(const std::string& sid)
{
	return const_cast<SedMLCurve*>(
	  static_cast<const SedListOfSedMLCurves&>(*this).get(sid));
}


/*
 * Get a SedMLCurve from the SedListOfSedMLCurves by id.
 */
const SedMLCurve*
SedListOfSedMLCurves::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLCurve>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedMLCurve*> (*result);
}


/*
 * Removes the nth SedMLCurve from this SedListOfSedMLCurves
 */
SedMLCurve*
SedListOfSedMLCurves::remove(unsigned int n)
{
	return static_cast<SedMLCurve*>(SedListOf::remove(n));
}


/*
 * Removes the SedMLCurve from this SedListOfSedMLCurves with the given identifier
 */
SedMLCurve*
SedListOfSedMLCurves::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLCurve>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedMLCurve*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSedMLCurves::getElementName () const
{
	static const string name = "listOfCurves";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSedMLCurves::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSedMLCurves::getItemTypeCode () const
{
	return SEDML_OUTPUT_CURVE;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedMLCurve in this SedListOfSedMLCurves
 */
SedBase*
SedListOfSedMLCurves::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "sedMLCurve")
	{
		object = new SedMLCurve(getSedMLNamespaces());
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
SedListOfSedMLCurves::writeXMLNS(XMLOutputStream& stream) const
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
SedMLCurve_t *
SedMLCurve_create(unsigned int level, unsigned int version)
{
	return new SedMLCurve(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedMLCurve_free(SedMLCurve_t * smlc)
{
	if (smlc != NULL)
		delete smlc;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLCurve_t *
SedMLCurve_clone(SedMLCurve_t * smlc)
{
	if (smlc != NULL)
	{
		return static_cast<SedMLCurve_t*>(smlc->clone());
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
SedMLCurve_getId(SedMLCurve_t * smlc)
{
	if (smlc == NULL)
		return NULL;

	return smlc->getId().empty() ? NULL : safe_strdup(smlc->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLCurve_getName(SedMLCurve_t * smlc)
{
	if (smlc == NULL)
		return NULL;

	return smlc->getName().empty() ? NULL : safe_strdup(smlc->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_getLogX(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->getLogX()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_getLogY(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->getLogY()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLCurve_getXDataReference(SedMLCurve_t * smlc)
{
	if (smlc == NULL)
		return NULL;

	return smlc->getXDataReference().empty() ? NULL : safe_strdup(smlc->getXDataReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLCurve_getYDataReference(SedMLCurve_t * smlc)
{
	if (smlc == NULL)
		return NULL;

	return smlc->getYDataReference().empty() ? NULL : safe_strdup(smlc->getYDataReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_isSetId(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_isSetName(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_isSetLogX(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->isSetLogX()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_isSetLogY(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->isSetLogY()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_isSetXDataReference(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->isSetXDataReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_isSetYDataReference(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->isSetYDataReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_setId(SedMLCurve_t * smlc, const char * id)
{
	return (smlc != NULL) ? smlc->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_setName(SedMLCurve_t * smlc, const char * name)
{
	return (smlc != NULL) ? smlc->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_setLogX(SedMLCurve_t * smlc, int logX)
{
	return (smlc != NULL) ? smlc->setLogX(logX) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_setLogY(SedMLCurve_t * smlc, int logY)
{
	return (smlc != NULL) ? smlc->setLogY(logY) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_setXDataReference(SedMLCurve_t * smlc, const char * xDataReference)
{
	return (smlc != NULL) ? smlc->setXDataReference(xDataReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_setYDataReference(SedMLCurve_t * smlc, const char * yDataReference)
{
	return (smlc != NULL) ? smlc->setYDataReference(yDataReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_unsetId(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? smlc->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_unsetName(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? smlc->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_unsetLogX(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? smlc->unsetLogX() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_unsetLogY(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? smlc->unsetLogY() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_unsetXDataReference(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? smlc->unsetXDataReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_unsetYDataReference(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? smlc->unsetYDataReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLCurve_hasRequiredAttributes(SedMLCurve_t * smlc)
{
	return (smlc != NULL) ? static_cast<int>(smlc->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLCurve_t *
SedListOfSedMLCurves_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLCurves *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLCurve_t *
SedListOfSedMLCurves_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLCurves *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


