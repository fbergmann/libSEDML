/**
 * @file:   SedSteadyState.cpp
 * @brief:  Implementation of the SedSteadyState class
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


#include <sedml/SedSteadyState.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedSteadyState with the given level, version, and package version.
 */
SedSteadyState::SedSteadyState (unsigned int level, unsigned int version)
	: SedSimulation(level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSteadyState with the given SedNamespaces object.
 */
SedSteadyState::SedSteadyState (SedNamespaces* sedns)
	: SedSimulation(sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedSteadyState.
 */
SedSteadyState::SedSteadyState (const SedSteadyState& orig)
	: SedSimulation(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
	}
}


/*
 * Assignment for SedSteadyState.
 */
SedSteadyState&
SedSteadyState::operator=(const SedSteadyState& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedSimulation::operator=(rhs);
	}
	return *this;
}


/*
 * Clone for SedSteadyState.
 */
SedSteadyState*
SedSteadyState::clone () const
{
	return new SedSteadyState(*this);
}


/*
 * Destructor for SedSteadyState.
 */
SedSteadyState::~SedSteadyState ()
{
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedSteadyState::getElementName () const
{
	static const string name = "steadyState";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedSteadyState::createObject(XMLInputStream& stream)
{
	SedBase* object = SedSimulation::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedSteadyState::getTypeCode () const
{
	return SEDML_SIMULATION_STEADYSTATE;
}


/*
 * check if all the required attributes are set
 */
bool
SedSteadyState::hasRequiredAttributes () const
{
	bool allPresent = SedSimulation::hasRequiredAttributes();

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedSteadyState::writeElements (XMLOutputStream& stream) const
{
	SedSimulation::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedSteadyState::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedSteadyState::setSedDocument (SedDocument* d)
{
	SedSimulation::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedSteadyState::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedSimulation::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedSteadyState::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedSimulation::readAttributes(attributes, expectedAttributes);

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedSteadyState::writeAttributes (XMLOutputStream& stream) const
{
	SedSimulation::writeAttributes(stream);

}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSteadyState_t *
SedSteadyState_create(unsigned int level, unsigned int version)
{
	return new SedSteadyState(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedSteadyState_free(SedSteadyState_t * sss)
{
	if (sss != NULL)
		delete sss;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSteadyState_t *
SedSteadyState_clone(SedSteadyState_t * sss)
{
	if (sss != NULL)
	{
		return static_cast<SedSteadyState_t*>(sss->clone());
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
SedSteadyState_hasRequiredAttributes(SedSteadyState_t * sss)
{
	return (sss != NULL) ? static_cast<int>(sss->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


