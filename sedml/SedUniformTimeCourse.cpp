/**
 * @file:   SedUniformTimeCourse.cpp
 * @brief:  Implementation of the SedUniformTimeCourse class
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


#include <sedml/SedUniformTimeCourse.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedUniformTimeCourse with the given level, version, and package version.
 */
SedUniformTimeCourse::SedUniformTimeCourse (unsigned int level, unsigned int version)
	: SedSimulation(level, version)
	, mInitialTime (numeric_limits<double>::quiet_NaN())
	, mIsSetInitialTime (false)
	, mOutputStartTime (numeric_limits<double>::quiet_NaN())
	, mIsSetOutputStartTime (false)
	, mOutputEndTime (numeric_limits<double>::quiet_NaN())
	, mIsSetOutputEndTime (false)
	, mNumberOfPoints (SEDML_INT_MAX)
	, mIsSetNumberOfPoints (false)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedUniformTimeCourse with the given SedNamespaces object.
 */
SedUniformTimeCourse::SedUniformTimeCourse (SedNamespaces* sedns)
	: SedSimulation(sedns)
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
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedUniformTimeCourse.
 */
SedUniformTimeCourse::SedUniformTimeCourse (const SedUniformTimeCourse& orig)
	: SedSimulation(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
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
 * Assignment for SedUniformTimeCourse.
 */
SedUniformTimeCourse&
SedUniformTimeCourse::operator=(const SedUniformTimeCourse& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedSimulation::operator=(rhs);
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
 * Clone for SedUniformTimeCourse.
 */
SedUniformTimeCourse*
SedUniformTimeCourse::clone () const
{
	return new SedUniformTimeCourse(*this);
}


/*
 * Destructor for SedUniformTimeCourse.
 */
SedUniformTimeCourse::~SedUniformTimeCourse ()
{
}


/*
 * Returns the value of the "initialTime" attribute of this SedUniformTimeCourse.
 */
const double
SedUniformTimeCourse::getInitialTime() const
{
	return mInitialTime;
}


/*
 * Returns the value of the "outputStartTime" attribute of this SedUniformTimeCourse.
 */
const double
SedUniformTimeCourse::getOutputStartTime() const
{
	return mOutputStartTime;
}


/*
 * Returns the value of the "outputEndTime" attribute of this SedUniformTimeCourse.
 */
const double
SedUniformTimeCourse::getOutputEndTime() const
{
	return mOutputEndTime;
}


/*
 * Returns the value of the "numberOfPoints" attribute of this SedUniformTimeCourse.
 */
const int
SedUniformTimeCourse::getNumberOfPoints() const
{
	return mNumberOfPoints;
}


/*
 * Returns true/false if initialTime is set.
 */
bool
SedUniformTimeCourse::isSetInitialTime() const
{
	return mIsSetInitialTime;
}


/*
 * Returns true/false if outputStartTime is set.
 */
bool
SedUniformTimeCourse::isSetOutputStartTime() const
{
	return mIsSetOutputStartTime;
}


/*
 * Returns true/false if outputEndTime is set.
 */
bool
SedUniformTimeCourse::isSetOutputEndTime() const
{
	return mIsSetOutputEndTime;
}


/*
 * Returns true/false if numberOfPoints is set.
 */
bool
SedUniformTimeCourse::isSetNumberOfPoints() const
{
	return mIsSetNumberOfPoints;
}


/*
 * Sets initialTime and returns value indicating success.
 */
int
SedUniformTimeCourse::setInitialTime(double initialTime)
{
	mInitialTime = initialTime;
	mIsSetInitialTime = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets outputStartTime and returns value indicating success.
 */
int
SedUniformTimeCourse::setOutputStartTime(double outputStartTime)
{
	mOutputStartTime = outputStartTime;
	mIsSetOutputStartTime = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets outputEndTime and returns value indicating success.
 */
int
SedUniformTimeCourse::setOutputEndTime(double outputEndTime)
{
	mOutputEndTime = outputEndTime;
	mIsSetOutputEndTime = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets numberOfPoints and returns value indicating success.
 */
int
SedUniformTimeCourse::setNumberOfPoints(int numberOfPoints)
{
	mNumberOfPoints = numberOfPoints;
	mIsSetNumberOfPoints = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets initialTime and returns value indicating success.
 */
int
SedUniformTimeCourse::unsetInitialTime()
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
SedUniformTimeCourse::unsetOutputStartTime()
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
SedUniformTimeCourse::unsetOutputEndTime()
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
SedUniformTimeCourse::unsetNumberOfPoints()
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
SedUniformTimeCourse::getElementName () const
{
	static const string name = "uniformTimeCourse";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedUniformTimeCourse::createObject(XMLInputStream& stream)
{
	SedBase* object = SedSimulation::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedUniformTimeCourse::getTypeCode () const
{
	return SEDML_SIMULATION_UNIFORMTIMECOURSE;
}


/*
 * check if all the required attributes are set
 */
bool
SedUniformTimeCourse::hasRequiredAttributes () const
{
	bool allPresent = SedSimulation::hasRequiredAttributes();

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
SedUniformTimeCourse::writeElements (XMLOutputStream& stream) const
{
	SedSimulation::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedUniformTimeCourse::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedUniformTimeCourse::setSedDocument (SedDocument* d)
{
	SedSimulation::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedUniformTimeCourse::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedSimulation::addExpectedAttributes(attributes);

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
SedUniformTimeCourse::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedSimulation::readAttributes(attributes, expectedAttributes);

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
SedUniformTimeCourse::writeAttributes (XMLOutputStream& stream) const
{
	SedSimulation::writeAttributes(stream);

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
SedUniformTimeCourse_t *
SedUniformTimeCourse_create(unsigned int level, unsigned int version)
{
	return new SedUniformTimeCourse(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedUniformTimeCourse_free(SedUniformTimeCourse_t * sutc)
{
	if (sutc != NULL)
		delete sutc;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedUniformTimeCourse_t *
SedUniformTimeCourse_clone(SedUniformTimeCourse_t * sutc)
{
	if (sutc != NULL)
	{
		return static_cast<SedUniformTimeCourse_t*>(sutc->clone());
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
SedUniformTimeCourse_getInitialTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? sutc->getInitialTime() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
double
SedUniformTimeCourse_getOutputStartTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? sutc->getOutputStartTime() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
double
SedUniformTimeCourse_getOutputEndTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? sutc->getOutputEndTime() : numeric_limits<double>::quiet_NaN();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_getNumberOfPoints(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? sutc->getNumberOfPoints() : SEDML_INT_MAX;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetInitialTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? static_cast<int>(sutc->isSetInitialTime()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetOutputStartTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? static_cast<int>(sutc->isSetOutputStartTime()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetOutputEndTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? static_cast<int>(sutc->isSetOutputEndTime()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_isSetNumberOfPoints(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? static_cast<int>(sutc->isSetNumberOfPoints()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setInitialTime(SedUniformTimeCourse_t * sutc, double initialTime)
{
	return (sutc != NULL) ? sutc->setInitialTime(initialTime) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setOutputStartTime(SedUniformTimeCourse_t * sutc, double outputStartTime)
{
	return (sutc != NULL) ? sutc->setOutputStartTime(outputStartTime) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setOutputEndTime(SedUniformTimeCourse_t * sutc, double outputEndTime)
{
	return (sutc != NULL) ? sutc->setOutputEndTime(outputEndTime) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_setNumberOfPoints(SedUniformTimeCourse_t * sutc, int numberOfPoints)
{
	return (sutc != NULL) ? sutc->setNumberOfPoints(numberOfPoints) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetInitialTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? sutc->unsetInitialTime() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetOutputStartTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? sutc->unsetOutputStartTime() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetOutputEndTime(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? sutc->unsetOutputEndTime() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_unsetNumberOfPoints(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? sutc->unsetNumberOfPoints() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedUniformTimeCourse_hasRequiredAttributes(SedUniformTimeCourse_t * sutc)
{
	return (sutc != NULL) ? static_cast<int>(sutc->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


