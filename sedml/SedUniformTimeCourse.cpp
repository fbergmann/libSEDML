/**
 * @file:   UniformTimeCourse.cpp
 * @brief:  Implementation of the UniformTimeCourse class
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


#include <sedml/UniformTimeCourse.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new UniformTimeCourse with the given level, version, and package version.
 */
UniformTimeCourse::UniformTimeCourse (unsigned int level, unsigned int version)
	: Simulation(level, version)
	, mInitialTime (numeric_limits<double>::quiet_NaN())
	, mIsSetInitialTime (false)
	, mOutputStartTime (numeric_limits<double>::quiet_NaN())
	, mIsSetOutputStartTime (false)
	, mOutputEndTime (numeric_limits<double>::quiet_NaN())
	, mIsSetOutputEndTime (false)
	, mNumberOfPoints (SEDML_INT_MAX)
	, mIsSetNumberOfPoints (false)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new UniformTimeCourse with the given SedMLNamespaces object.
 */
UniformTimeCourse::UniformTimeCourse (SedMLNamespaces* sedmlns)
	: Simulation(sedmlns)
	, mInitialTime (numeric_limits<double>::quiet_NaN())
	, mIsSetInitialTime (false)
	, mOutputStartTime (numeric_limits<double>::quiet_NaN())
	, mIsSetOutputStartTime (false)
	, mOutputEndTime (numeric_limits<double>::quiet_NaN())
	, mIsSetOutputEndTime (false)
	, mNumberOfPoints (SEDML_INT_MAX)
	, mIsSetNumberOfPoints (false)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for UniformTimeCourse.
 */
UniformTimeCourse::UniformTimeCourse (const UniformTimeCourse& orig)
	: Simulation(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mInitialTime  = orig.mInitialTime;
		mIsSetInitialTime  = orig.mIsSetInitialTime;
		mOutputStartTime  = orig.mOutputStartTime;
		mIsSetOutputStartTime  = orig.mIsSetOutputStartTime;
		mOutputEndTime  = orig.mOutputEndTime;
		mIsSetOutputEndTime  = orig.mIsSetOutputEndTime;
		mNumberOfPoints  = orig.mNumberOfPoints;
		mIsSetNumberOfPoints  = orig.mIsSetNumberOfPoints;
	}
}


/*
 * Assignment for UniformTimeCourse.
 */
UniformTimeCourse&
UniformTimeCourse::operator=(const UniformTimeCourse& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		Simulation::operator=(rhs);
		mInitialTime  = rhs.mInitialTime;
		mIsSetInitialTime  = rhs.mIsSetInitialTime;
		mOutputStartTime  = rhs.mOutputStartTime;
		mIsSetOutputStartTime  = rhs.mIsSetOutputStartTime;
		mOutputEndTime  = rhs.mOutputEndTime;
		mIsSetOutputEndTime  = rhs.mIsSetOutputEndTime;
		mNumberOfPoints  = rhs.mNumberOfPoints;
		mIsSetNumberOfPoints  = rhs.mIsSetNumberOfPoints;
	}
	return *this;
}


/*
 * Clone for UniformTimeCourse.
 */
UniformTimeCourse*
UniformTimeCourse::clone () const
{
	return new UniformTimeCourse(*this);
}


/*
 * Destructor for UniformTimeCourse.
 */
UniformTimeCourse::~UniformTimeCourse ()
{
}


/*
 * Returns the value of the "initialTime" attribute of this UniformTimeCourse.
 */
const double
UniformTimeCourse::getInitialTime() const
{
	return mInitialTime;
}


/*
 * Returns the value of the "outputStartTime" attribute of this UniformTimeCourse.
 */
const double
UniformTimeCourse::getOutputStartTime() const
{
	return mOutputStartTime;
}


/*
 * Returns the value of the "outputEndTime" attribute of this UniformTimeCourse.
 */
const double
UniformTimeCourse::getOutputEndTime() const
{
	return mOutputEndTime;
}


/*
 * Returns the value of the "numberOfPoints" attribute of this UniformTimeCourse.
 */
const int
UniformTimeCourse::getNumberOfPoints() const
{
	return mNumberOfPoints;
}


/*
 * Returns true/false if initialTime is set.
 */
bool
UniformTimeCourse::isSetInitialTime() const
{
	return mIsSetInitialTime;
}


/*
 * Returns true/false if outputStartTime is set.
 */
bool
UniformTimeCourse::isSetOutputStartTime() const
{
	return mIsSetOutputStartTime;
}


/*
 * Returns true/false if outputEndTime is set.
 */
bool
UniformTimeCourse::isSetOutputEndTime() const
{
	return mIsSetOutputEndTime;
}


/*
 * Returns true/false if numberOfPoints is set.
 */
bool
UniformTimeCourse::isSetNumberOfPoints() const
{
	return mIsSetNumberOfPoints;
}


/*
 * Sets initialTime and returns value indicating success.
 */
int
UniformTimeCourse::setInitialTime(double initialTime)
{
	mInitialTime = initialTime;
	mIsSetInitialTime = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets outputStartTime and returns value indicating success.
 */
int
UniformTimeCourse::setOutputStartTime(double outputStartTime)
{
	mOutputStartTime = outputStartTime;
	mIsSetOutputStartTime = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets outputEndTime and returns value indicating success.
 */
int
UniformTimeCourse::setOutputEndTime(double outputEndTime)
{
	mOutputEndTime = outputEndTime;
	mIsSetOutputEndTime = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets numberOfPoints and returns value indicating success.
 */
int
UniformTimeCourse::setNumberOfPoints(int numberOfPoints)
{
	mNumberOfPoints = numberOfPoints;
	mIsSetNumberOfPoints = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets initialTime and returns value indicating success.
 */
int
UniformTimeCourse::unsetInitialTime()
{
	mInitialTime = numeric_limits<double>::quiet_NaN();
	mIsSetInitialTime = false;

	if (isSetInitialTime() == false)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets outputStartTime and returns value indicating success.
 */
int
UniformTimeCourse::unsetOutputStartTime()
{
	mOutputStartTime = numeric_limits<double>::quiet_NaN();
	mIsSetOutputStartTime = false;

	if (isSetOutputStartTime() == false)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets outputEndTime and returns value indicating success.
 */
int
UniformTimeCourse::unsetOutputEndTime()
{
	mOutputEndTime = numeric_limits<double>::quiet_NaN();
	mIsSetOutputEndTime = false;

	if (isSetOutputEndTime() == false)
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
UniformTimeCourse::unsetNumberOfPoints()
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
 * Returns the XML element name of this object
 */
const std::string&
UniformTimeCourse::getElementName () const
{
	static const string name = "uniformTimeCourse";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
UniformTimeCourse::createObject(XMLInputStream& stream)
{
	SedBase* object = Simulation::createObject(stream);

	const string& name   = stream.peek().getName();

	Simulation::connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
UniformTimeCourse::getTypeCode () const
{
	return SEDML_SIMULATION_UNIFORMTIMECOURSE;
}


/*
 * check if all the required attributes are set
 */
bool
UniformTimeCourse::hasRequiredAttributes () const
{
	bool allPresent = Simulation::hasRequiredAttributes();

	if (isSetInitialTime() == false)
		allPresent = false;

	if (isSetOutputStartTime() == false)
		allPresent = false;

	if (isSetOutputEndTime() == false)
		allPresent = false;

	if (isSetNumberOfPoints() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
UniformTimeCourse::writeElements (XMLOutputStream& stream) const
{
	Simulation::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
UniformTimeCourse::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
UniformTimeCourse::setSedMLDocument (SedMLDocument* d)
{
	Simulation::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
UniformTimeCourse::addExpectedAttributes(ExpectedAttributes& attributes)
{
	Simulation::addExpectedAttributes(attributes);

	attributes.add("initialTime");
	attributes.add("outputStartTime");
	attributes.add("outputEndTime");
	attributes.add("numberOfPoints");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
UniformTimeCourse::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	Simulation::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// initialTime double   ( use = "required" )
	//
	mIsSetInitialTime = attributes.readInto("initialTime", mInitialTime, getErrorLog(), true);

	//
	// outputStartTime double   ( use = "required" )
	//
	mIsSetOutputStartTime = attributes.readInto("outputStartTime", mOutputStartTime, getErrorLog(), true);

	//
	// outputEndTime double   ( use = "required" )
	//
	mIsSetOutputEndTime = attributes.readInto("outputEndTime", mOutputEndTime, getErrorLog(), true);

	//
	// numberOfPoints int   ( use = "required" )
	//
	mIsSetNumberOfPoints = attributes.readInto("numberOfPoints", mNumberOfPoints, getErrorLog(), true);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
UniformTimeCourse::writeAttributes (XMLOutputStream& stream) const
{
	Simulation::writeAttributes(stream);

	if (isSetInitialTime() == true)
		stream.writeAttribute("initialTime", getPrefix(), mInitialTime);

	if (isSetOutputStartTime() == true)
		stream.writeAttribute("outputStartTime", getPrefix(), mOutputStartTime);

	if (isSetOutputEndTime() == true)
		stream.writeAttribute("outputEndTime", getPrefix(), mOutputEndTime);

	if (isSetNumberOfPoints() == true)
		stream.writeAttribute("numberOfPoints", getPrefix(), mNumberOfPoints);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
UniformTimeCourse_t *
UniformTimeCourse_create(unsigned int level, unsigned int version)
{
	return new UniformTimeCourse(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
UniformTimeCourse_free(UniformTimeCourse_t * utc)
{
	if (utc != NULL)
		delete utc;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
UniformTimeCourse_t *
UniformTimeCourse_clone(UniformTimeCourse_t * utc)
{
	if (utc != NULL)
	{
		return static_cast<UniformTimeCourse_t*>(utc->clone());
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
UniformTimeCourse_getInitialTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? utc->getInitialTime() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
double
UniformTimeCourse_getOutputStartTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? utc->getOutputStartTime() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
double
UniformTimeCourse_getOutputEndTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? utc->getOutputEndTime() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_getNumberOfPoints(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? utc->getNumberOfPoints() : SEDML_INT_MAX;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_isSetInitialTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? static_cast<int>(utc->isSetInitialTime()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_isSetOutputStartTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? static_cast<int>(utc->isSetOutputStartTime()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_isSetOutputEndTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? static_cast<int>(utc->isSetOutputEndTime()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_isSetNumberOfPoints(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? static_cast<int>(utc->isSetNumberOfPoints()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_setInitialTime(UniformTimeCourse_t * utc, double initialTime)
{
	return (utc != NULL) ? utc->setInitialTime(initialTime) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_setOutputStartTime(UniformTimeCourse_t * utc, double outputStartTime)
{
	return (utc != NULL) ? utc->setOutputStartTime(outputStartTime) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_setOutputEndTime(UniformTimeCourse_t * utc, double outputEndTime)
{
	return (utc != NULL) ? utc->setOutputEndTime(outputEndTime) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_setNumberOfPoints(UniformTimeCourse_t * utc, int numberOfPoints)
{
	return (utc != NULL) ? utc->setNumberOfPoints(numberOfPoints) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_unsetInitialTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? utc->unsetInitialTime() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_unsetOutputStartTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? utc->unsetOutputStartTime() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_unsetOutputEndTime(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? utc->unsetOutputEndTime() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_unsetNumberOfPoints(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? utc->unsetNumberOfPoints() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
UniformTimeCourse_hasRequiredAttributes(UniformTimeCourse_t * utc)
{
	return (utc != NULL) ? static_cast<int>(utc->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


