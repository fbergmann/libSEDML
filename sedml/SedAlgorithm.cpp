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
	, mAlgorithmParameters (level, version)
	, mKisaoID ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedAlgorithm with the given SedNamespaces object.
 */
SedAlgorithm::SedAlgorithm (SedNamespaces* sedns)
	: SedBase(sedns)
	, mAlgorithmParameters (sedns)
	, mKisaoID ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
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
		mAlgorithmParameters  = orig.mAlgorithmParameters;
		mKisaoID  = orig.mKisaoID;

		// connect to child objects
		connectToChild();
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
		mAlgorithmParameters  = rhs.mAlgorithmParameters;
		mKisaoID  = rhs.mKisaoID;

		// connect to child objects
		connectToChild();
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
 * Returns the  "SedListOfAlgorithmParameters" in this SedAlgorithm object.
 */
const SedListOfAlgorithmParameters*
SedAlgorithm::getListOfAlgorithmParameters() const
{
	return &mAlgorithmParameters;
}


/*
 * Removes the nth AlgorithmParameter from the SedListOfAlgorithmParameters.
 */
SedAlgorithmParameter*
SedAlgorithm::removeAlgorithmParameter(unsigned int n)
{
	return mAlgorithmParameters.remove(n);
}


/*
 * Removes the a AlgorithmParameter with given id from the SedListOfAlgorithmParameters.
 */
SedAlgorithmParameter*
SedAlgorithm::removeAlgorithmParameter(const std::string& sid)
{
	return mAlgorithmParameters.remove(sid);
}


/*
 * Return the nth AlgorithmParameter in the SedListOfAlgorithmParameters within this SedAlgorithm.
 */
SedAlgorithmParameter*
SedAlgorithm::getAlgorithmParameter(unsigned int n)
{
	return mAlgorithmParameters.get(n);
}


/*
 * Return the nth AlgorithmParameter in the SedListOfAlgorithmParameters within this SedAlgorithm.
 */
const SedAlgorithmParameter*
SedAlgorithm::getAlgorithmParameter(unsigned int n) const
{
	return mAlgorithmParameters.get(n);
}


/*
 * Return a AlgorithmParameter from the SedListOfAlgorithmParameters by id.
 */
SedAlgorithmParameter*
SedAlgorithm::getAlgorithmParameter(const std::string& sid)
{
	return mAlgorithmParameters.get(sid);
}


/*
 * Return a AlgorithmParameter from the SedListOfAlgorithmParameters by id.
 */
const SedAlgorithmParameter*
SedAlgorithm::getAlgorithmParameter(const std::string& sid) const
{
	return mAlgorithmParameters.get(sid);
}


/**
 * Adds a copy the given "SedAlgorithmParameter" to this SedAlgorithm.
 *
 * @param sap; the SedAlgorithmParameter object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedAlgorithm::addAlgorithmParameter(const SedAlgorithmParameter* sap)
{
	if(sap == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mAlgorithmParameters.append(sap);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedAlgorithmParameter objects in this SedAlgorithm.
 *
 * @return the number of SedAlgorithmParameter objects in this SedAlgorithm
 */
unsigned int 
SedAlgorithm::getNumAlgorithmParameters() const
{
	return mAlgorithmParameters.size();
}

/**
 * Creates a new SedAlgorithmParameter object, adds it to this SedAlgorithms
 * SedAlgorithm and returns the SedAlgorithmParameter object created. 
 *
 * @return a new SedAlgorithmParameter object instance
 *
 * @see addSedAlgorithmParameter(const SedAlgorithmParameter* sap)
 */
SedAlgorithmParameter* 
SedAlgorithm::createAlgorithmParameter()
{
	SedAlgorithmParameter *temp = new SedAlgorithmParameter();
	if (temp != NULL) mAlgorithmParameters.appendAndOwn(temp);
	return temp;
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


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedAlgorithm::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	if (name == "listOfAlgorithmParameters")
	{
		object = &mAlgorithmParameters;
	}

	connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedAlgorithm::connectToChild ()
{
	SedBase::connectToChild();

	mAlgorithmParameters.connectToParent(this);
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


/*
 * check if all the required elements are set
 */
bool
SedAlgorithm::hasRequiredElements () const
{
	bool allPresent = true;

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
	if (getNumAlgorithmParameters() > 0)
	{
		mAlgorithmParameters.write(stream);
	}
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
	mAlgorithmParameters.setSedDocument(d);
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


LIBSEDML_EXTERN
int
SedAlgorithm_addAlgorithmParameter(SedAlgorithm_t * sa, SedAlgorithmParameter_t * sap)
{
	return  (sa != NULL) ? sa->addAlgorithmParameter(sap) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedAlgorithm_createAlgorithmParameter(SedAlgorithm_t * sa)
{
	return  (sa != NULL) ? sa->createAlgorithmParameter() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedAlgorithm_getSedListOfAlgorithmParameters(SedAlgorithm_t * sa)
{
	return  (sa != NULL) ? (SedListOf_t *)sa->getListOfAlgorithmParameters() : NULL;
}

LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedAlgorithm_getAlgorithmParameter(SedAlgorithm_t * sa, unsigned int n)
{
	return  (sa != NULL) ? sa->getAlgorithmParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedAlgorithm_getAlgorithmParameterById(SedAlgorithm_t * sa, const char * sid)
{
	return  (sa != NULL) ? sa->getAlgorithmParameter(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedAlgorithm_getNumAlgorithmParameters(SedAlgorithm_t * sa)
{
	return  (sa != NULL) ? sa->getNumAlgorithmParameters() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedAlgorithm_removeAlgorithmParameter(SedAlgorithm_t * sa, unsigned int n)
{
	return  (sa != NULL) ? sa->removeAlgorithmParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedAlgorithmParameter_t *
SedAlgorithm_removeAlgorithmParameterById(SedAlgorithm_t * sa, const char * sid)
{
	return  (sa != NULL) ? sa->removeAlgorithmParameter(sid) : NULL;
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


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedAlgorithm_hasRequiredElements(SedAlgorithm_t * sa)
{
	return (sa != NULL) ? static_cast<int>(sa->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


