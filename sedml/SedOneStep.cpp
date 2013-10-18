/**
 * @file:   SedOneStep.cpp
 * @brief:  Implementation of the SedOneStep class
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


#include <sedml/SedOneStep.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedOneStep with the given level, version, and package version.
 */
SedOneStep::SedOneStep (unsigned int level, unsigned int version)
	: SedSimulation(level, version)
	, mStep (numeric_limits<double>::quiet_NaN())
	, mIsSetStep (false)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedOneStep with the given SedNamespaces object.
 */
SedOneStep::SedOneStep (SedNamespaces* sedns)
	: SedSimulation(sedns)
	, mStep (numeric_limits<double>::quiet_NaN())
	, mIsSetStep (false)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedOneStep.
 */
SedOneStep::SedOneStep (const SedOneStep& orig)
	: SedSimulation(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mStep  = orig.mStep;
		mIsSetStep  = orig.mIsSetStep;
	}
}


/*
 * Assignment for SedOneStep.
 */
SedOneStep&
SedOneStep::operator=(const SedOneStep& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedSimulation::operator=(rhs);
		mStep  = rhs.mStep;
		mIsSetStep  = rhs.mIsSetStep;
	}
	return *this;
}


/*
 * Clone for SedOneStep.
 */
SedOneStep*
SedOneStep::clone () const
{
	return new SedOneStep(*this);
}


/*
 * Destructor for SedOneStep.
 */
SedOneStep::~SedOneStep ()
{
}


/*
 * Returns the value of the "step" attribute of this SedOneStep.
 */
const double
SedOneStep::getStep() const
{
	return mStep;
}


/*
 * Returns true/false if step is set.
 */
bool
SedOneStep::isSetStep() const
{
	return mIsSetStep;
}


/*
 * Sets step and returns value indicating success.
 */
int
SedOneStep::setStep(double step)
{
	mStep = step;
	mIsSetStep = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets step and returns value indicating success.
 */
int
SedOneStep::unsetStep()
{
	mStep = numeric_limits<double>::quiet_NaN();
	mIsSetStep = false;

	if (isSetStep() == false)
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
SedOneStep::getElementName () const
{
	static const string name = "oneStep";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedOneStep::createObject(XMLInputStream& stream)
{
	SedBase* object = SedSimulation::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedOneStep::getTypeCode () const
{
	return SEDML_SIMULATION_ONESTEP;
}


/*
 * check if all the required attributes are set
 */
bool
SedOneStep::hasRequiredAttributes () const
{
	bool allPresent = SedSimulation::hasRequiredAttributes();

	if (isSetStep() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedOneStep::writeElements (XMLOutputStream& stream) const
{
	SedSimulation::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedOneStep::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedOneStep::setSedDocument (SedDocument* d)
{
	SedSimulation::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedOneStep::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedSimulation::addExpectedAttributes(attributes);

	attributes.add("step");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedOneStep::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedSimulation::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// step double   ( use = "required" )
	//
	mIsSetStep = attributes.readInto("step", mStep, getErrorLog(), true);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedOneStep::writeAttributes (XMLOutputStream& stream) const
{
	SedSimulation::writeAttributes(stream);

	if (isSetStep() == true)
		stream.writeAttribute("step", getPrefix(), mStep);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedOneStep_t *
SedOneStep_create(unsigned int level, unsigned int version)
{
	return new SedOneStep(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedOneStep_free(SedOneStep_t * sos)
{
	if (sos != NULL)
		delete sos;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedOneStep_t *
SedOneStep_clone(SedOneStep_t * sos)
{
	if (sos != NULL)
	{
		return static_cast<SedOneStep_t*>(sos->clone());
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
SedOneStep_getStep(SedOneStep_t * sos)
{
	return (sos != NULL) ? sos->getStep() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOneStep_isSetStep(SedOneStep_t * sos)
{
	return (sos != NULL) ? static_cast<int>(sos->isSetStep()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOneStep_setStep(SedOneStep_t * sos, double step)
{
	return (sos != NULL) ? sos->setStep(step) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOneStep_unsetStep(SedOneStep_t * sos)
{
	return (sos != NULL) ? sos->unsetStep() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOneStep_hasRequiredAttributes(SedOneStep_t * sos)
{
	return (sos != NULL) ? static_cast<int>(sos->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


