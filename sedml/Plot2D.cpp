/**
 * @file:   Plot2D.cpp
 * @brief:  Implementation of the Plot2D class
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


#include <sedml/Plot2D.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Plot2D with the given level, version, and package version.
 */
Plot2D::Plot2D (unsigned int level, unsigned int version)
	: Output(level, version)
	, mCurve (level, version)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new Plot2D with the given SedMLNamespaces object.
 */
Plot2D::Plot2D (SedMLNamespaces* sedmlns)
	: Output(sedmlns)
	, mCurve (sedmlns)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for Plot2D.
 */
Plot2D::Plot2D (const Plot2D& orig)
	: Output(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mCurve  = orig.mCurve;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for Plot2D.
 */
Plot2D&
Plot2D::operator=(const Plot2D& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		Output::operator=(rhs);
		mCurve  = rhs.mCurve;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for Plot2D.
 */
Plot2D*
Plot2D::clone () const
{
	return new Plot2D(*this);
}


/*
 * Destructor for Plot2D.
 */
Plot2D::~Plot2D ()
{
}


/*
 * Returns the  "SedListOfSedMLCurves" in this Plot2D object.
 */
const SedListOfSedMLCurves*
Plot2D::getListOfSedMLCurves() const
{
	return &mCurve;
}


/*
 * Removes the nth SedMLCurve from the SedListOfSedMLCurves.
 */
SedMLCurve*
Plot2D::removeSedMLCurve(unsigned int n)
{
	return mCurve.remove(n);
}


/*
 * Removes the a SedMLCurve with given id from the SedListOfSedMLCurves.
 */
SedMLCurve*
Plot2D::removeSedMLCurve(const std::string& sid)
{
	return mCurve.remove(sid);
}


/*
 * Return the nth SedMLCurve in the SedListOfSedMLCurves within this Plot2D.
 */
SedMLCurve*
Plot2D::getSedMLCurve(unsigned int n)
{
	return mCurve.get(n);
}


/*
 * Return the nth SedMLCurve in the SedListOfSedMLCurves within this Plot2D.
 */
const SedMLCurve*
Plot2D::getSedMLCurve(unsigned int n) const
{
	return mCurve.get(n);
}


/*
 * Return a SedMLCurve from the SedListOfSedMLCurves by id.
 */
SedMLCurve*
Plot2D::getSedMLCurve(const std::string& sid)
{
	return mCurve.get(sid);
}


/*
 * Return a SedMLCurve from the SedListOfSedMLCurves by id.
 */
const SedMLCurve*
Plot2D::getSedMLCurve(const std::string& sid) const
{
	return mCurve.get(sid);
}


/**
 * Adds a copy the given "SedMLCurve" to this Plot2D.
 *
 * @param smlc; the SedMLCurve object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
Plot2D::addSedMLCurve(const SedMLCurve* smlc)
{
	if(smlc == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mCurve.append(smlc);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedMLCurve objects in this Plot2D.
 *
 * @return the number of SedMLCurve objects in this Plot2D
 */
unsigned int 
Plot2D::getNumSedMLCurves() const
{
	return mCurve.size();
}

/**
 * Creates a new SedMLCurve object, adds it to this Plot2Ds
 * Plot2D and returns the SedMLCurve object created. 
 *
 * @return a new SedMLCurve object instance
 *
 * @see addSedMLCurve(const SedMLCurve* smlc)
 */
SedMLCurve* 
Plot2D::createSedMLCurve()
{
	SedMLCurve *temp = new SedMLCurve();
	if (temp != NULL) mCurve.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
Plot2D::getElementName () const
{
	static const string name = "plot2D";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
Plot2D::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	Output::connectToChild();

	if (name == "listOfCurves")
	{
		object = &mCurve;
	}

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Plot2D::connectToChild ()
{
	Output::connectToChild();

	mCurve.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Plot2D::getTypeCode () const
{
	return SEDML_OUTPUT_PLOT2D;
}


/*
 * check if all the required attributes are set
 */
bool
Plot2D::hasRequiredAttributes () const
{
	bool allPresent = Output::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
Plot2D::hasRequiredElements () const
{
	bool allPresent = Output::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
Plot2D::writeElements (XMLOutputStream& stream) const
{
	Output::writeElements(stream);
	if (getNumSedMLCurves() > 0)
	{
		mCurve.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Plot2D::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Plot2D::setSedMLDocument (SedMLDocument* d)
{
	Output::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Plot2D::addExpectedAttributes(ExpectedAttributes& attributes)
{
	Output::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Plot2D::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	Output::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
Plot2D::writeAttributes (XMLOutputStream& stream) const
{
	Output::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
Plot2D_t *
Plot2D_create(unsigned int level, unsigned int version)
{
	return new Plot2D(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Plot2D_free(Plot2D_t * pd)
{
	if (pd != NULL)
		delete pd;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Plot2D_t *
Plot2D_clone(Plot2D_t * pd)
{
	if (pd != NULL)
	{
		return static_cast<Plot2D_t*>(pd->clone());
	}
	else
	{
		return NULL;
	}
}


LIBSEDML_EXTERN
int
Plot2D_addSedMLCurve(Plot2D_t * pd, SedMLCurve_t * smlc)
{
	return  (pd != NULL) ? pd->addSedMLCurve(smlc) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_createSedMLCurve(Plot2D_t * pd)
{
	return  (pd != NULL) ? pd->createSedMLCurve() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
Plot2D_getSedListOfSedMLCurves(Plot2D_t * pd)
{
	return  (pd != NULL) ? (SedListOf_t *)pd->getListOfSedMLCurves() : NULL;
}

LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_getSedMLCurve(Plot2D_t * pd, unsigned int n)
{
	return  (pd != NULL) ? pd->getSedMLCurve(n) : NULL;
}

LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_getSedMLCurveById(Plot2D_t * pd, const char * sid)
{
	return  (pd != NULL) ? pd->getSedMLCurve(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
Plot2D_getNumSedMLCurves(Plot2D_t * pd)
{
	return  (pd != NULL) ? pd->getNumSedMLCurves() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_removeSedMLCurve(Plot2D_t * pd, unsigned int n)
{
	return  (pd != NULL) ? pd->removeSedMLCurve(n) : NULL;
}

LIBSEDML_EXTERN
SedMLCurve_t *
Plot2D_removeSedMLCurveById(Plot2D_t * pd, const char * sid)
{
	return  (pd != NULL) ? pd->removeSedMLCurve(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
Plot2D_hasRequiredAttributes(Plot2D_t * pd)
{
	return (pd != NULL) ? static_cast<int>(pd->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Plot2D_hasRequiredElements(Plot2D_t * pd)
{
	return (pd != NULL) ? static_cast<int>(pd->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


