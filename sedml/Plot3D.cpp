/**
 * @file:   Plot3D.cpp
 * @brief:  Implementation of the Plot3D class
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


#include <sedml/Plot3D.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Plot3D with the given level, version, and package version.
 */
Plot3D::Plot3D (unsigned int level, unsigned int version)
	: Output(level, version)
	, mSurface (level, version)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new Plot3D with the given SedMLNamespaces object.
 */
Plot3D::Plot3D (SedMLNamespaces* sedmlns)
	: Output(sedmlns)
	, mSurface (sedmlns)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for Plot3D.
 */
Plot3D::Plot3D (const Plot3D& orig)
	: Output(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mSurface  = orig.mSurface;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for Plot3D.
 */
Plot3D&
Plot3D::operator=(const Plot3D& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		Output::operator=(rhs);
		mSurface  = rhs.mSurface;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for Plot3D.
 */
Plot3D*
Plot3D::clone () const
{
	return new Plot3D(*this);
}


/*
 * Destructor for Plot3D.
 */
Plot3D::~Plot3D ()
{
}


/*
 * Returns the  "SedListOfSurfaces" in this Plot3D object.
 */
const SedListOfSurfaces*
Plot3D::getListOfSurfaces() const
{
	return &mSurface;
}


/*
 * Removes the nth Surface from the SedListOfSurfaces.
 */
Surface*
Plot3D::removeSurface(unsigned int n)
{
	return mSurface.remove(n);
}


/*
 * Removes the a Surface with given id from the SedListOfSurfaces.
 */
Surface*
Plot3D::removeSurface(const std::string& sid)
{
	return mSurface.remove(sid);
}


/*
 * Return the nth Surface in the SedListOfSurfaces within this Plot3D.
 */
Surface*
Plot3D::getSurface(unsigned int n)
{
	return mSurface.get(n);
}


/*
 * Return the nth Surface in the SedListOfSurfaces within this Plot3D.
 */
const Surface*
Plot3D::getSurface(unsigned int n) const
{
	return mSurface.get(n);
}


/*
 * Return a Surface from the SedListOfSurfaces by id.
 */
Surface*
Plot3D::getSurface(const std::string& sid)
{
	return mSurface.get(sid);
}


/*
 * Return a Surface from the SedListOfSurfaces by id.
 */
const Surface*
Plot3D::getSurface(const std::string& sid) const
{
	return mSurface.get(sid);
}


/**
 * Adds a copy the given "Surface" to this Plot3D.
 *
 * @param s; the Surface object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
Plot3D::addSurface(const Surface* s)
{
	if(s == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mSurface.append(s);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of Surface objects in this Plot3D.
 *
 * @return the number of Surface objects in this Plot3D
 */
unsigned int 
Plot3D::getNumSurfaces() const
{
	return mSurface.size();
}

/**
 * Creates a new Surface object, adds it to this Plot3Ds
 * Plot3D and returns the Surface object created. 
 *
 * @return a new Surface object instance
 *
 * @see addSurface(const Surface* s)
 */
Surface* 
Plot3D::createSurface()
{
	Surface *temp = new Surface();
	if (temp != NULL) mSurface.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
Plot3D::getElementName () const
{
	static const string name = "plot3D";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
Plot3D::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	Output::connectToChild();

	if (name == "listOfSurfaces")
	{
		object = &mSurface;
	}

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Plot3D::connectToChild ()
{
	Output::connectToChild();

	mSurface.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Plot3D::getTypeCode () const
{
	return SEDML_OUTPUT_PLOT3D;
}


/*
 * check if all the required attributes are set
 */
bool
Plot3D::hasRequiredAttributes () const
{
	bool allPresent = Output::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
Plot3D::hasRequiredElements () const
{
	bool allPresent = Output::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
Plot3D::writeElements (XMLOutputStream& stream) const
{
	Output::writeElements(stream);
	if (getNumSurfaces() > 0)
	{
		mSurface.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Plot3D::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Plot3D::setSedMLDocument (SedMLDocument* d)
{
	Output::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Plot3D::addExpectedAttributes(ExpectedAttributes& attributes)
{
	Output::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Plot3D::readAttributes (const XMLAttributes& attributes,
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
Plot3D::writeAttributes (XMLOutputStream& stream) const
{
	Output::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
Plot3D_t *
Plot3D_create(unsigned int level, unsigned int version)
{
	return new Plot3D(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Plot3D_free(Plot3D_t * pd)
{
	if (pd != NULL)
		delete pd;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Plot3D_t *
Plot3D_clone(Plot3D_t * pd)
{
	if (pd != NULL)
	{
		return static_cast<Plot3D_t*>(pd->clone());
	}
	else
	{
		return NULL;
	}
}


LIBSEDML_EXTERN
int
Plot3D_addSurface(Plot3D_t * pd, Surface_t * s)
{
	return  (pd != NULL) ? pd->addSurface(s) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
Surface_t *
Plot3D_createSurface(Plot3D_t * pd)
{
	return  (pd != NULL) ? pd->createSurface() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
Plot3D_getSedListOfSurfaces(Plot3D_t * pd)
{
	return  (pd != NULL) ? (SedListOf_t *)pd->getListOfSurfaces() : NULL;
}

LIBSEDML_EXTERN
Surface_t *
Plot3D_getSurface(Plot3D_t * pd, unsigned int n)
{
	return  (pd != NULL) ? pd->getSurface(n) : NULL;
}

LIBSEDML_EXTERN
Surface_t *
Plot3D_getSurfaceById(Plot3D_t * pd, const char * sid)
{
	return  (pd != NULL) ? pd->getSurface(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
Plot3D_getNumSurfaces(Plot3D_t * pd)
{
	return  (pd != NULL) ? pd->getNumSurfaces() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
Surface_t *
Plot3D_removeSurface(Plot3D_t * pd, unsigned int n)
{
	return  (pd != NULL) ? pd->removeSurface(n) : NULL;
}

LIBSEDML_EXTERN
Surface_t *
Plot3D_removeSurfaceById(Plot3D_t * pd, const char * sid)
{
	return  (pd != NULL) ? pd->removeSurface(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
Plot3D_hasRequiredAttributes(Plot3D_t * pd)
{
	return (pd != NULL) ? static_cast<int>(pd->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Plot3D_hasRequiredElements(Plot3D_t * pd)
{
	return (pd != NULL) ? static_cast<int>(pd->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


