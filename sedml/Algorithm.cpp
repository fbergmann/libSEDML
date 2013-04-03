/**
 * @file:   Algorithm.cpp
 * @brief:  Implementation of the Algorithm class
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


#include <sedml/Algorithm.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Algorithm with the given level, version, and package version.
 */
Algorithm::Algorithm (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mKisaoID ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new Algorithm with the given SedMLNamespaces object.
 */
Algorithm::Algorithm (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mKisaoID ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for Algorithm.
 */
Algorithm::Algorithm (const Algorithm& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mKisaoID  = orig.mKisaoID;
	}
}


/*
 * Assignment for Algorithm.
 */
Algorithm&
Algorithm::operator=(const Algorithm& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mKisaoID  = rhs.mKisaoID;
	}
	return *this;
}


/*
 * Clone for Algorithm.
 */
Algorithm*
Algorithm::clone () const
{
	return new Algorithm(*this);
}


/*
 * Destructor for Algorithm.
 */
Algorithm::~Algorithm ()
{
}


/*
 * Returns the value of the "kisaoID" attribute of this Algorithm.
 */
const std::string&
Algorithm::getKisaoID() const
{
	return mKisaoID;
}


/*
/*
 * Returns true/false if kisaoID is set.
 */
bool
Algorithm::isSetKisaoID() const
{
	return (mKisaoID.empty() == false);
}


/*
 * Sets kisaoID and returns value indicating success.
 */
int
Algorithm::setKisaoID(const std::string& kisaoID)
{
	if (&(kisaoID) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mKisaoID = kisaoID;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets kisaoID and returns value indicating success.
 */
int
Algorithm::unsetKisaoID()
{
	mKisaoID.erase();

	if (mKisaoID.empty() == true)
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
Algorithm::getElementName () const
{
	static const string name = "algorithm";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Algorithm::getTypeCode () const
{
	return SEDML_SIMULATION_ALGORITHM;
}


/*
 * check if all the required attributes are set
 */
bool
Algorithm::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetKisaoID() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
Algorithm::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Algorithm::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Algorithm::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Algorithm::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("kisaoID");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Algorithm::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// kisaoID string   ( use = "required" )
	//
	assigned = attributes.readInto("kisaoID", mKisaoID, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty

		if (mKisaoID.empty() == true)
		{
			logEmptyString(mKisaoID, getLevel(), getVersion(), "<Algorithm>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
Algorithm::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetKisaoID() == true)
		stream.writeAttribute("kisaoID", getPrefix(), mKisaoID);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
Algorithm_t *
Algorithm_create(unsigned int level, unsigned int version)
{
	return new Algorithm(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Algorithm_free(Algorithm_t * a)
{
	if (a != NULL)
		delete a;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Algorithm_t *
Algorithm_clone(Algorithm_t * a)
{
	if (a != NULL)
	{
		return static_cast<Algorithm_t*>(a->clone());
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
Algorithm_getKisaoID(Algorithm_t * a)
{
	if (a == NULL)
		return NULL;

	return a->getKisaoID().empty() ? NULL : safe_strdup(a->getKisaoID().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Algorithm_isSetKisaoID(Algorithm_t * a)
{
	return (a != NULL) ? static_cast<int>(a->isSetKisaoID()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Algorithm_setKisaoID(Algorithm_t * a, const char * kisaoID)
{
	return (a != NULL) ? a->setKisaoID(kisaoID) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Algorithm_unsetKisaoID(Algorithm_t * a)
{
	return (a != NULL) ? a->unsetKisaoID() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Algorithm_hasRequiredAttributes(Algorithm_t * a)
{
	return (a != NULL) ? static_cast<int>(a->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


