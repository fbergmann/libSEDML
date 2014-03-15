/**
 * @file:   SedSimulation.cpp
 * @brief:  Implementation of the SedSimulation class
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


#include <sedml/SedSimulation.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedSimulation with the given level, version, and package version.
 */
SedSimulation::SedSimulation (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mAlgorithm (NULL)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedSimulation with the given SedNamespaces object.
 */
SedSimulation::SedSimulation (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")
	, mName ("")
	, mAlgorithm (NULL)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedSimulation.
 */
SedSimulation::SedSimulation (const SedSimulation& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mId  = orig.mId;
		mName  = orig.mName;
		mAlgorithm  = orig.mAlgorithm;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedSimulation.
 */
SedSimulation&
SedSimulation::operator=(const SedSimulation& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mId  = rhs.mId;
		mName  = rhs.mName;
		mAlgorithm  = rhs.mAlgorithm;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedSimulation.
 */
SedSimulation*
SedSimulation::clone () const
{
	return new SedSimulation(*this);
}


/*
 * Destructor for SedSimulation.
 */
SedSimulation::~SedSimulation ()
{
}


/*
 * Returns the value of the "id" attribute of this SedSimulation.
 */
const std::string&
SedSimulation::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedSimulation.
 */
const std::string&
SedSimulation::getName() const
{
	return mName;
}


/*
 * Returns the value of the "algorithm" attribute of this SedSimulation.
 */
const SedAlgorithm*
SedSimulation::getAlgorithm() const
{
	return mAlgorithm;
}


/*
 * Creates a new "algorithm" element of this SedSimulation and returns it.
 */
SedAlgorithm*
SedSimulation::createAlgorithm()
{
	mAlgorithm = new SedAlgorithm();
	return mAlgorithm;
}


/*
 * Returns true/false if id is set.
 */
bool
SedSimulation::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedSimulation::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if algorithm is set.
 */
bool
SedSimulation::isSetAlgorithm() const
{
	return (mAlgorithm != NULL);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedSimulation::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedSimulation::setName(const std::string& name)
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
 * Sets algorithm and returns value indicating success.
 */
int
SedSimulation::setAlgorithm(SedAlgorithm* algorithm)
{
	if (mAlgorithm == algorithm)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else if (algorithm == NULL)
	{
		delete mAlgorithm;
		mAlgorithm = NULL;
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		delete mAlgorithm;
		mAlgorithm = (algorithm != NULL) ?
			static_cast<SedAlgorithm*>(algorithm->clone()) : NULL;
		if (mAlgorithm != NULL)
		{
			mAlgorithm->connectToParent(this);
		}
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedSimulation::unsetId()
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
SedSimulation::unsetName()
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
 * Unsets algorithm and returns value indicating success.
 */
int
SedSimulation::unsetAlgorithm()
{
	delete mAlgorithm;
	mAlgorithm = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedSimulation::getElementName () const
{
	static const string name = "simulation";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedSimulation::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	if (name == "algorithm")
	{
		mAlgorithm= new SedAlgorithm();
		object = mAlgorithm;
	}

	connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedSimulation::connectToChild ()
{
	SedBase::connectToChild();

	if (mAlgorithm != NULL)
		mAlgorithm->connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedSimulation::getTypeCode () const
{
	return SEDML_SIMULATION;
}


/*
 * check if all the required attributes are set
 */
bool
SedSimulation::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetId() == false)
		allPresent = false;

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedSimulation::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedSimulation::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (isSetAlgorithm() == true)
	{
		mAlgorithm->write(stream);
	}
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedSimulation::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedSimulation::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
	if (mAlgorithm != NULL)
		mAlgorithm->setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedSimulation::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedSimulation::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// id SId  ( use = "required" )
	//
	assigned = attributes.readInto("id", mId, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mId.empty() == true)
		{
			logEmptyString(mId, getLevel(), getVersion(), "<SedSimulation>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mId) == false)
		{
			logError(SedInvalidIdSyntax);
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedSimulation>");
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedSimulation::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor 
 */
SedListOfSimulations::SedListOfSimulations(unsigned int level, 
	                     unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSimulations::SedListOfSimulations(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSimulations 
 */
SedListOfSimulations* 
SedListOfSimulations::clone () const
 {
	return new SedListOfSimulations(*this);
}


/*
 * Get a Simulation from the SedListOfSimulations by index.
*/
SedSimulation*
SedListOfSimulations::get(unsigned int n)
{
	return static_cast<SedSimulation*>(SedListOf::get(n));
}


/*
 * Get a Simulation from the SedListOfSimulations by index.
 */
const SedSimulation*
SedListOfSimulations::get(unsigned int n) const
{
	return static_cast<const SedSimulation*>(SedListOf::get(n));
}


/*
 * Get a Simulation from the SedListOfSimulations by id.
 */
SedSimulation*
SedListOfSimulations::get(const std::string& sid)
{
	return const_cast<SedSimulation*>(
	  static_cast<const SedListOfSimulations&>(*this).get(sid));
}


/*
 * Get a Simulation from the SedListOfSimulations by id.
 */
const SedSimulation*
SedListOfSimulations::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedSimulation>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedSimulation*> (*result);
}


/**
 * Adds a copy the given "SedSimulation" to this SedListOfSimulations.
 *
 * @param ss; the SedSimulation object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfSimulations::addSimulation(const SedSimulation* ss)
{
	if(ss == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(ss);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSimulation objects in this SedListOfSimulations.
 *
 * @return the number of SedSimulation objects in this SedListOfSimulations
 */
unsigned int 
SedListOfSimulations::getNumSimulations() const
{
	return size();
}

/**
 * Creates a new SedUniformTimeCourse object, adds it to this SedListOfSimulations
 * uniformTimeCourse and returns the SedUniformTimeCourse object created. 
 *
 * @return a new SedUniformTimeCourse object instance
 *
 * @see addUniformTimeCourse(const SedSimulation* ss)
 */
SedUniformTimeCourse* 
SedListOfSimulations::createUniformTimeCourse()
{
	SedUniformTimeCourse *temp = new SedUniformTimeCourse();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedOneStep object, adds it to this SedListOfSimulations
 * oneStep and returns the SedOneStep object created. 
 *
 * @return a new SedOneStep object instance
 *
 * @see addOneStep(const SedSimulation* ss)
 */
SedOneStep* 
SedListOfSimulations::createOneStep()
{
	SedOneStep *temp = new SedOneStep();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedSteadyState object, adds it to this SedListOfSimulations
 * steadyState and returns the SedSteadyState object created. 
 *
 * @return a new SedSteadyState object instance
 *
 * @see addSteadyState(const SedSimulation* ss)
 */
SedSteadyState* 
SedListOfSimulations::createSteadyState()
{
	SedSteadyState *temp = new SedSteadyState();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Simulation from this SedListOfSimulations
 */
SedSimulation*
SedListOfSimulations::remove(unsigned int n)
{
	return static_cast<SedSimulation*>(SedListOf::remove(n));
}


/*
 * Removes the Simulation from this SedListOfSimulations with the given identifier
 */
SedSimulation*
SedListOfSimulations::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedSimulation>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedSimulation*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSimulations::getElementName () const
{
	static const string name = "listOfSimulations";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSimulations::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSimulations::getItemTypeCode () const
{
	return SEDML_SIMULATION;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedSimulation in this SedListOfSimulations
 */
SedBase*
SedListOfSimulations::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "uniformTimeCourse")
	{
		object = new SedUniformTimeCourse(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "oneStep")
	{
		object = new SedOneStep(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "steadyState")
	{
		object = new SedSteadyState(getSedNamespaces());
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
SedListOfSimulations::writeXMLNS(XMLOutputStream& stream) const
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
SedSimulation_t *
SedSimulation_create(unsigned int level, unsigned int version)
{
	return new SedSimulation(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedSimulation_free(SedSimulation_t * ss)
{
	if (ss != NULL)
		delete ss;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSimulation_t *
SedSimulation_clone(SedSimulation_t * ss)
{
	if (ss != NULL)
	{
		return static_cast<SedSimulation_t*>(ss->clone());
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
SedSimulation_getId(SedSimulation_t * ss)
{
	if (ss == NULL)
		return NULL;

	return ss->getId().empty() ? NULL : safe_strdup(ss->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedSimulation_getName(SedSimulation_t * ss)
{
	if (ss == NULL)
		return NULL;

	return ss->getName().empty() ? NULL : safe_strdup(ss->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedSimulation_getAlgorithm(SedSimulation_t * ss)
{
	if (ss == NULL)
		return NULL;

	return (SedAlgorithm_t*)ss->getAlgorithm();
}


LIBSEDML_EXTERN
SedAlgorithm_t*
SedSimulation_createAlgorithm(SedSimulation_t * ss)
{
	if (ss == NULL)
		return NULL;

	return (SedAlgorithm_t*)ss->createAlgorithm();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetId(SedSimulation_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetName(SedSimulation_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetAlgorithm(SedSimulation_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->isSetAlgorithm()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_setId(SedSimulation_t * ss, const char * id)
{
	return (ss != NULL) ? ss->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_setName(SedSimulation_t * ss, const char * name)
{
	return (ss != NULL) ? ss->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_setAlgorithm(SedSimulation_t * ss, SedAlgorithm_t* algorithm)
{
	return (ss != NULL) ? ss->setAlgorithm(algorithm) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetId(SedSimulation_t * ss)
{
	return (ss != NULL) ? ss->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetName(SedSimulation_t * ss)
{
	return (ss != NULL) ? ss->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetAlgorithm(SedSimulation_t * ss)
{
	return (ss != NULL) ? ss->unsetAlgorithm() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_hasRequiredAttributes(SedSimulation_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSimulation_hasRequiredElements(SedSimulation_t * ss)
{
	return (ss != NULL) ? static_cast<int>(ss->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSimulation_t *
SedListOfSimulations_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSimulations *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSimulation_t *
SedListOfSimulations_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSimulations *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


