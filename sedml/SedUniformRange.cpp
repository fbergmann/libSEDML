/**
 * @file:   SedUniformRange.cpp
 * @brief:  Implementation of the SedUniformRange class
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


#include <sedml/SedUniformRange.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedUniformRange with the given level, version, and package version.
 */
SedUniformRange::SedUniformRange (unsigned int level, unsigned int version)
	: SedRange(level, version)
	, mStart (numeric_limits<double>::quiet_NaN())
	, mIsSetStart (false)
	, mEnd (numeric_limits<double>::quiet_NaN())
	, mIsSetEnd (false)
	, mNumberOfPoints (SEDML_INT_MAX)
	, mIsSetNumberOfPoints (false)
	, mType ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedUniformRange with the given SedNamespaces object.
 */
SedUniformRange::SedUniformRange (SedNamespaces* sedns)
	: SedRange(sedns)
	, mStart (numeric_limits<double>::quiet_NaN())
	, mIsSetStart (false)
	, mEnd (numeric_limits<double>::quiet_NaN())
	, mIsSetEnd (false)
	, mNumberOfPoints (SEDML_INT_MAX)
	, mIsSetNumberOfPoints (false)
	, mType ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedUniformRange.
 */
SedUniformRange::SedUniformRange (const SedUniformRange& orig)
	: SedRange(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mStart  = orig.mStart;
		mIsSetStart  = orig.mIsSetStart;
		mEnd  = orig.mEnd;
		mIsSetEnd  = orig.mIsSetEnd;
		mNumberOfPoints  = orig.mNumberOfPoints;
		mIsSetNumberOfPoints  = orig.mIsSetNumberOfPoints;
		mType  = orig.mType;
	}
}


/*
 * Assignment for SedUniformRange.
 */
SedUniformRange&
SedUniformRange::operator=(const SedUniformRange& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedRange::operator=(rhs);
		mStart  = rhs.mStart;
		mIsSetStart  = rhs.mIsSetStart;
		mEnd  = rhs.mEnd;
		mIsSetEnd  = rhs.mIsSetEnd;
		mNumberOfPoints  = rhs.mNumberOfPoints;
		mIsSetNumberOfPoints  = rhs.mIsSetNumberOfPoints;
		mType  = rhs.mType;
	}
	return *this;
}


/*
 * Clone for SedUniformRange.
 */
SedUniformRange*
SedUniformRange::clone () const
{
	return new SedUniformRange(*this);
}


/*
 * Destructor for SedUniformRange.
 */
SedUniformRange::~SedUniformRange ()
{
}


/*
 * Returns the value of the "start" attribute of this SedUniformRange.
 */
const double
SedUniformRange::getStart() const
{
	return mStart;
}


/*
 * Returns the value of the "end" attribute of this SedUniformRange.
 */
const double
SedUniformRange::getEnd() const
{
	return mEnd;
}


/*
 * Returns the value of the "numberOfPoints" attribute of this SedUniformRange.
 */
const int
SedUniformRange::getNumberOfPoints() const
{
	return mNumberOfPoints;
}


/*
 * Returns the value of the "type" attribute of this SedUniformRange.
 */
const std::string&
SedUniformRange::getType() const
{
	return mType;
}


/*
 * Returns true/false if start is set.
 */
bool
SedUniformRange::isSetStart() const
{
	return mIsSetStart;
}


/*
 * Returns true/false if end is set.
 */
bool
SedUniformRange::isSetEnd() const
{
	return mIsSetEnd;
}


/*
 * Returns true/false if numberOfPoints is set.
 */
bool
SedUniformRange::isSetNumberOfPoints() const
{
	return mIsSetNumberOfPoints;
}


/*
 * Returns true/false if type is set.
 */
bool
SedUniformRange::isSetType() const
{
	return (mType.empty() == false);
}


/*
 * Sets start and returns value indicating success.
 */
int
SedUniformRange::setStart(double start)
{
	mStart = start;
	mIsSetStart = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets end and returns value indicating success.
 */
int
SedUniformRange::setEnd(double end)
{
	mEnd = end;
	mIsSetEnd = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets numberOfPoints and returns value indicating success.
 */
int
SedUniformRange::setNumberOfPoints(int numberOfPoints)
{
	mNumberOfPoints = numberOfPoints;
	mIsSetNumberOfPoints = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets type and returns value indicating success.
 */
int
SedUniformRange::setType(const std::string& type)
{
	if (&(type) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mType = type;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets start and returns value indicating success.
 */
int
SedUniformRange::unsetStart()
{
	mStart = numeric_limits<double>::quiet_NaN();
	mIsSetStart = false;

	if (isSetStart() == false)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets end and returns value indicating success.
 */
int
SedUniformRange::unsetEnd()
{
	mEnd = numeric_limits<double>::quiet_NaN();
	mIsSetEnd = false;

	if (isSetEnd() == false)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets numberOfPoints and returns value indicating success.
 */
int
SedUniformRange::unsetNumberOfPoints()
{
	mNumberOfPoints = SEDML_INT_MAX;
	mIsSetNumberOfPoints = false;

	if (isSetNumberOfPoints() == false)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets type and returns value indicating success.
 */
int
SedUniformRange::unsetType()
{
	mType.erase();

	if (mType.empty() == true)
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
SedUniformRange::getElementName () const
{
	static const string name = "uniformRange";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedUniformRange::createObject(XMLInputStream& stream)
{
	SedBase* object = SedRange::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedUniformRange::getTypeCode () const
{
	return SEDML_RANGE_UNIFORMRANGE;
}


/*
 * check if all the required attributes are set
 */
bool
SedUniformRange::hasRequiredAttributes () const
{
	bool allPresent = SedRange::hasRequiredAttributes();

	if (isSetStart() == false)
		allPresent = false;

	if (isSetEnd() == false)
		allPresent = false;

	if (isSetNumberOfPoints() == false)
		allPresent = false;

	if (isSetType() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedUniformRange::writeElements (XMLOutputStream& stream) const
{
	SedRange::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedUniformRange::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedUniformRange::setSedDocument (SedDocument* d)
{
	SedRange::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedUniformRange::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedRange::addExpectedAttributes(attributes);

	attributes.add("start");
	attributes.add("end");
	attributes.add("numberOfPoints");
	attributes.add("type");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedUniformRange::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedRange::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// start double   ( use = "required" )
	//
	mIsSetStart = attributes.readInto("start", mStart, getErrorLog(), true);

	//
	// end double   ( use = "required" )
	//
	mIsSetEnd = attributes.readInto("end", mEnd, getErrorLog(), true);

	//
	// numberOfPoints int   ( use = "required" )
	//
	mIsSetNumberOfPoints = attributes.readInto("numberOfPoints", mNumberOfPoints, getErrorLog(), true);

	//
	// type string   ( use = "required" )
	//
	assigned = attributes.readInto("type", mType, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty

		if (mType.empty() == true)
		{
			logEmptyString(mType, getLevel(), getVersion(), "<SedUniformRange>");
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedUniformRange::writeAttributes (XMLOutputStream& stream) const
{
	SedRange::writeAttributes(stream);

	if (isSetStart() == true)
		stream.writeAttribute("start", getPrefix(), mStart);

	if (isSetEnd() == true)
		stream.writeAttribute("end", getPrefix(), mEnd);

	if (isSetNumberOfPoints() == true)
		stream.writeAttribute("numberOfPoints", getPrefix(), mNumberOfPoints);

	if (isSetType() == true)
		stream.writeAttribute("type", getPrefix(), mType);

}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedUniformRange_t *
SedUniformRange_create(unsigned int level, unsigned int version)
{
	return new SedUniformRange(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedUniformRange_free(SedUniformRange_t * sur)
{
	if (sur != NULL)
		delete sur;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedUniformRange_t *
SedUniformRange_clone(SedUniformRange_t * sur)
{
	if (sur != NULL)
	{
		return static_cast<SedUniformRange_t*>(sur->clone());
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
double
SedUniformRange_getStart(SedUniformRange_t * sur)
{
	return (sur != NULL) ? sur->getStart() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
double
SedUniformRange_getEnd(SedUniformRange_t * sur)
{
	return (sur != NULL) ? sur->getEnd() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_getNumberOfPoints(SedUniformRange_t * sur)
{
	return (sur != NULL) ? sur->getNumberOfPoints() : SEDML_INT_MAX;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedUniformRange_getType(SedUniformRange_t * sur)
{
	if (sur == NULL)
		return NULL;

	return sur->getType().empty() ? NULL : safe_strdup(sur->getType().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetStart(SedUniformRange_t * sur)
{
	return (sur != NULL) ? static_cast<int>(sur->isSetStart()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetEnd(SedUniformRange_t * sur)
{
	return (sur != NULL) ? static_cast<int>(sur->isSetEnd()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetNumberOfPoints(SedUniformRange_t * sur)
{
	return (sur != NULL) ? static_cast<int>(sur->isSetNumberOfPoints()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_isSetType(SedUniformRange_t * sur)
{
	return (sur != NULL) ? static_cast<int>(sur->isSetType()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_setStart(SedUniformRange_t * sur, double start)
{
	return (sur != NULL) ? sur->setStart(start) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_setEnd(SedUniformRange_t * sur, double end)
{
	return (sur != NULL) ? sur->setEnd(end) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_setNumberOfPoints(SedUniformRange_t * sur, int numberOfPoints)
{
	return (sur != NULL) ? sur->setNumberOfPoints(numberOfPoints) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_setType(SedUniformRange_t * sur, const char * type)
{
	return (sur != NULL) ? sur->setType(type) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetStart(SedUniformRange_t * sur)
{
	return (sur != NULL) ? sur->unsetStart() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetEnd(SedUniformRange_t * sur)
{
	return (sur != NULL) ? sur->unsetEnd() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetNumberOfPoints(SedUniformRange_t * sur)
{
	return (sur != NULL) ? sur->unsetNumberOfPoints() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_unsetType(SedUniformRange_t * sur)
{
	return (sur != NULL) ? sur->unsetType() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformRange_hasRequiredAttributes(SedUniformRange_t * sur)
{
	return (sur != NULL) ? static_cast<int>(sur->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


