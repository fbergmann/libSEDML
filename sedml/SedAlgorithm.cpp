/**
 * @file:   SedAlgorithm.cpp
 * @brief:  Implementation of the SedAlgorithm class
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


#include <sedml/SedAlgorithm.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedAlgorithm with the given level, version, and package version.
 */
SedAlgorithm::SedAlgorithm (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mKisaoID ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedAlgorithm with the given SedNamespaces object.
 */
SedAlgorithm::SedAlgorithm (SedNamespaces* sedns)
	: SedBase(sedns)
	, mKisaoID ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedAlgorithm.
 */
SedAlgorithm::SedAlgorithm (const SedAlgorithm& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mKisaoID  = orig.mKisaoID;
	}
}


/*
 * Assignment for SedAlgorithm.
 */
SedAlgorithm&
SedAlgorithm::operator=(const SedAlgorithm& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mKisaoID  = rhs.mKisaoID;
	}
	return *this;
}


/*
 * Clone for SedAlgorithm.
 */
SedAlgorithm*
SedAlgorithm::clone () const
{
	return new SedAlgorithm(*this);
}


/*
 * Destructor for SedAlgorithm.
 */
SedAlgorithm::~SedAlgorithm ()
{
}


/*
 * Returns the value of the "kisaoID" attribute of this SedAlgorithm.
 */
const std::string&
SedAlgorithm::getKisaoID() const
{
	return mKisaoID;
}


/*
 * Returns true/false if kisaoID is set.
 */
bool
SedAlgorithm::isSetKisaoID() const
{
	return (mKisaoID.empty() == false);
}


/*
 * Sets kisaoID and returns value indicating success.
 */
int
SedAlgorithm::setKisaoID(const std::string& kisaoID)
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
SedAlgorithm::unsetKisaoID()
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
SedAlgorithm::getElementName () const
{
	static const string name = "algorithm";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedAlgorithm::getTypeCode () const
{
	return SEDML_SIMULATION_ALGORITHM;
}


/*
 * check if all the required attributes are set
 */
bool
SedAlgorithm::hasRequiredAttributes () const
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
SedAlgorithm::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedAlgorithm::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedAlgorithm::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedAlgorithm::addExpectedAttributes(ExpectedAttributes& attributes)
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
SedAlgorithm::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mKisaoID, getLevel(), getVersion(), "<SedAlgorithm>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedAlgorithm::writeAttributes (XMLOutputStream& stream) const
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
SedAlgorithm_t *
SedAlgorithm_create(unsigned int level, unsigned int version)
{
	return new SedAlgorithm(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedAlgorithm_free(SedAlgorithm_t * sa)
{
	if (sa != NULL)
		delete sa;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedAlgorithm_t *
SedAlgorithm_clone(SedAlgorithm_t * sa)
{
	if (sa != NULL)
	{
		return static_cast<SedAlgorithm_t*>(sa->clone());
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
SedAlgorithm_getKisaoID(SedAlgorithm_t * sa)
{
	if (sa == NULL)
		return NULL;

	return sa->getKisaoID().empty() ? NULL : safe_strdup(sa->getKisaoID().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithm_isSetKisaoID(SedAlgorithm_t * sa)
{
	return (sa != NULL) ? static_cast<int>(sa->isSetKisaoID()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithm_setKisaoID(SedAlgorithm_t * sa, const char * kisaoID)
{
	return (sa != NULL) ? sa->setKisaoID(kisaoID) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithm_unsetKisaoID(SedAlgorithm_t * sa)
{
	return (sa != NULL) ? sa->unsetKisaoID() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithm_hasRequiredAttributes(SedAlgorithm_t * sa)
{
	return (sa != NULL) ? static_cast<int>(sa->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


