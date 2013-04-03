/**
 * @file:   Simulation.cpp
 * @brief:  Implementation of the Simulation class
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


#include <sedml/Simulation.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Simulation with the given level, version, and package version.
 */
Simulation::Simulation (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mAlgorithm (NULL)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new Simulation with the given SedMLNamespaces object.
 */
Simulation::Simulation (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mName ("")
	, mAlgorithm (NULL)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for Simulation.
 */
Simulation::Simulation (const Simulation& orig)
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
		mAlgorithm  = orig.mAlgorithm;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for Simulation.
 */
Simulation&
Simulation::operator=(const Simulation& rhs)
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
		mAlgorithm  = rhs.mAlgorithm;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for Simulation.
 */
Simulation*
Simulation::clone () const
{
	return new Simulation(*this);
}


/*
 * Destructor for Simulation.
 */
Simulation::~Simulation ()
{
}


/*
 * Returns the value of the "id" attribute of this Simulation.
 */
const std::string&
Simulation::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this Simulation.
 */
const std::string&
Simulation::getName() const
{
	return mName;
}


/*
 * Returns the value of the "algorithm" attribute of this Simulation.
 */
const Algorithm*
Simulation::getAlgorithm() const
{
	return mAlgorithm;
}


/*
 * Creates a new "algorithm" element of this Simulation and returns it.
 */
Algorithm*
Simulation::createAlgorithm()
{
	mAlgorithm = new Algorithm();
	return mAlgorithm;
}


/*
 * Returns true/false if id is set.
 */
bool
Simulation::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
Simulation::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if algorithm is set.
 */
bool
Simulation::isSetAlgorithm() const
{
	return (mAlgorithm != NULL);
}


/*
 * Sets id and returns value indicating success.
 */
int
Simulation::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
Simulation::setName(const std::string& name)
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
Simulation::setAlgorithm(Algorithm* algorithm)
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
			static_cast<Algorithm*>(algorithm->clone()) : NULL;
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
Simulation::unsetId()
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
Simulation::unsetName()
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
Simulation::unsetAlgorithm()
{
	delete mAlgorithm;
	mAlgorithm = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this object
 */
const std::string&
Simulation::getElementName () const
{
	static const string name = "simulation";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
Simulation::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	SedBase::connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Simulation::connectToChild ()
{
	SedBase::connectToChild();

}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Simulation::getTypeCode () const
{
	return SEDML_SIMULATION;
}


/*
 * check if all the required attributes are set
 */
bool
Simulation::hasRequiredAttributes () const
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
Simulation::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
Simulation::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (isSetAlgorithm() == true)
	{
		mAlgorithm->write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Simulation::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Simulation::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Simulation::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Simulation::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<Simulation>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<Simulation>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
Simulation::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfSimulations::SedListOfSimulations(unsigned int level, 
	                     unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSimulations::SedListOfSimulations(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
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
Simulation*
SedListOfSimulations::get(unsigned int n)
{
	return static_cast<Simulation*>(SedListOf::get(n));
}


/*
 * Get a Simulation from the SedListOfSimulations by index.
 */
const Simulation*
SedListOfSimulations::get(unsigned int n) const
{
	return static_cast<const Simulation*>(SedListOf::get(n));
}


/*
 * Get a Simulation from the SedListOfSimulations by id.
 */
Simulation*
SedListOfSimulations::get(const std::string& sid)
{
	return const_cast<Simulation*>(
	  static_cast<const SedListOfSimulations&>(*this).get(sid));
}


/*
 * Get a Simulation from the SedListOfSimulations by id.
 */
const Simulation*
SedListOfSimulations::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Simulation>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <Simulation*> (*result);
}


/*
 * Removes the nth Simulation from this SedListOfSimulations
 */
Simulation*
SedListOfSimulations::remove(unsigned int n)
{
	return static_cast<Simulation*>(SedListOf::remove(n));
}


/*
 * Removes the Simulation from this SedListOfSimulations with the given identifier
 */
Simulation*
SedListOfSimulations::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Simulation>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <Simulation*> (item);
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


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new Simulation in this SedListOfSimulations
 */
SedBase*
SedListOfSimulations::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "simulation")
	{
		object = new Simulation(getSedMLNamespaces());
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
SedListOfSimulations::writeXMLNS(XMLOutputStream& stream) const
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
Simulation_t *
Simulation_create(unsigned int level, unsigned int version)
{
	return new Simulation(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Simulation_free(Simulation_t * s)
{
	if (s != NULL)
		delete s;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Simulation_t *
Simulation_clone(Simulation_t * s)
{
	if (s != NULL)
	{
		return static_cast<Simulation_t*>(s->clone());
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
Simulation_getId(Simulation_t * s)
{
	if (s == NULL)
		return NULL;

	return s->getId().empty() ? NULL : safe_strdup(s->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
Simulation_getName(Simulation_t * s)
{
	if (s == NULL)
		return NULL;

	return s->getName().empty() ? NULL : safe_strdup(s->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Simulation_isSetId(Simulation_t * s)
{
	return (s != NULL) ? static_cast<int>(s->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Simulation_isSetName(Simulation_t * s)
{
	return (s != NULL) ? static_cast<int>(s->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Simulation_setId(Simulation_t * s, const char * id)
{
	return (s != NULL) ? s->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Simulation_setName(Simulation_t * s, const char * name)
{
	return (s != NULL) ? s->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Simulation_unsetId(Simulation_t * s)
{
	return (s != NULL) ? s->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Simulation_unsetName(Simulation_t * s)
{
	return (s != NULL) ? s->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Simulation_hasRequiredAttributes(Simulation_t * s)
{
	return (s != NULL) ? static_cast<int>(s->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Simulation_hasRequiredElements(Simulation_t * s)
{
	return (s != NULL) ? static_cast<int>(s->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Simulation_t *
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
Simulation_t *
SedListOfSimulations_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSimulations *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


