/**
 * @file:   SedPlot3D.cpp
 * @brief:  Implementation of the SedPlot3D class
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


#include <sedml/SedPlot3D.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedPlot3D with the given level, version, and package version.
 */
SedPlot3D::SedPlot3D (unsigned int level, unsigned int version)
	: SedOutput(level, version)
	, mSurfaces (level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedPlot3D with the given SedNamespaces object.
 */
SedPlot3D::SedPlot3D (SedNamespaces* sedns)
	: SedOutput(sedns)
	, mSurfaces (sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedPlot3D.
 */
SedPlot3D::SedPlot3D (const SedPlot3D& orig)
	: SedOutput(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mSurfaces  = orig.mSurfaces;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedPlot3D.
 */
SedPlot3D&
SedPlot3D::operator=(const SedPlot3D& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedOutput::operator=(rhs);
		mSurfaces  = rhs.mSurfaces;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedPlot3D.
 */
SedPlot3D*
SedPlot3D::clone () const
{
	return new SedPlot3D(*this);
}


/*
 * Destructor for SedPlot3D.
 */
SedPlot3D::~SedPlot3D ()
{
}


/*
 * Returns the  "SedListOfSurfaces" in this SedPlot3D object.
 */
const SedListOfSurfaces*
SedPlot3D::getListOfSurfaces() const
{
	return &mSurfaces;
}


/*
 * Removes the nth Surface from the SedListOfSurfaces.
 */
SedSurface*
SedPlot3D::removeSurface(unsigned int n)
{
	return mSurfaces.remove(n);
}


/*
 * Removes the a Surface with given id from the SedListOfSurfaces.
 */
SedSurface*
SedPlot3D::removeSurface(const std::string& sid)
{
	return mSurfaces.remove(sid);
}


/*
 * Return the nth Surface in the SedListOfSurfaces within this SedPlot3D.
 */
SedSurface*
SedPlot3D::getSurface(unsigned int n)
{
	return mSurfaces.get(n);
}


/*
 * Return the nth Surface in the SedListOfSurfaces within this SedPlot3D.
 */
const SedSurface*
SedPlot3D::getSurface(unsigned int n) const
{
	return mSurfaces.get(n);
}


/*
 * Return a Surface from the SedListOfSurfaces by id.
 */
SedSurface*
SedPlot3D::getSurface(const std::string& sid)
{
	return mSurfaces.get(sid);
}


/*
 * Return a Surface from the SedListOfSurfaces by id.
 */
const SedSurface*
SedPlot3D::getSurface(const std::string& sid) const
{
	return mSurfaces.get(sid);
}


/**
 * Adds a copy the given "SedSurface" to this SedPlot3D.
 *
 * @param ss; the SedSurface object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedPlot3D::addSurface(const SedSurface* ss)
{
	if(ss == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mSurfaces.append(ss);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSurface objects in this SedPlot3D.
 *
 * @return the number of SedSurface objects in this SedPlot3D
 */
unsigned int 
SedPlot3D::getNumSurfaces() const
{
	return mSurfaces.size();
}

/**
 * Creates a new SedSurface object, adds it to this SedPlot3Ds
 * SedPlot3D and returns the SedSurface object created. 
 *
 * @return a new SedSurface object instance
 *
 * @see addSedSurface(const SedSurface* ss)
 */
SedSurface* 
SedPlot3D::createSurface()
{
	SedSurface *temp = new SedSurface();
	if (temp != NULL) mSurfaces.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedPlot3D::getElementName () const
{
	static const string name = "plot3D";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedPlot3D::createObject(XMLInputStream& stream)
{
	SedBase* object = SedOutput::createObject(stream);

	const string& name   = stream.peek().getName();

	if (name == "listOfSurfaces")
	{
		object = &mSurfaces;
	}

	connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedPlot3D::connectToChild ()
{
	SedOutput::connectToChild();

	mSurfaces.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedPlot3D::getTypeCode () const
{
	return SEDML_OUTPUT_PLOT3D;
}


/*
 * check if all the required attributes are set
 */
bool
SedPlot3D::hasRequiredAttributes () const
{
	bool allPresent = SedOutput::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedPlot3D::hasRequiredElements () const
{
	bool allPresent = SedOutput::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedPlot3D::writeElements (XMLOutputStream& stream) const
{
	SedOutput::writeElements(stream);
	if (getNumSurfaces() > 0)
	{
		mSurfaces.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedPlot3D::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedPlot3D::setSedDocument (SedDocument* d)
{
	SedOutput::setSedDocument(d);
	mSurfaces.setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedPlot3D::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedOutput::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedPlot3D::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedOutput::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedPlot3D::writeAttributes (XMLOutputStream& stream) const
{
	SedOutput::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedPlot3D_t *
SedPlot3D_create(unsigned int level, unsigned int version)
{
	return new SedPlot3D(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedPlot3D_free(SedPlot3D_t * spd)
{
	if (spd != NULL)
		delete spd;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedPlot3D_t *
SedPlot3D_clone(SedPlot3D_t * spd)
{
	if (spd != NULL)
	{
		return static_cast<SedPlot3D_t*>(spd->clone());
	}
	else
	{
		return NULL;
	}
}


LIBSEDML_EXTERN
int
SedPlot3D_addSurface(SedPlot3D_t * spd, SedSurface_t * ss)
{
	return  (spd != NULL) ? spd->addSurface(ss) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedSurface_t *
SedPlot3D_createSurface(SedPlot3D_t * spd)
{
	return  (spd != NULL) ? spd->createSurface() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedPlot3D_getSedListOfSurfaces(SedPlot3D_t * spd)
{
	return  (spd != NULL) ? (SedListOf_t *)spd->getListOfSurfaces() : NULL;
}

LIBSEDML_EXTERN
SedSurface_t *
SedPlot3D_getSurface(SedPlot3D_t * spd, unsigned int n)
{
	return  (spd != NULL) ? spd->getSurface(n) : NULL;
}

LIBSEDML_EXTERN
SedSurface_t *
SedPlot3D_getSurfaceById(SedPlot3D_t * spd, const char * sid)
{
	return  (spd != NULL) ? spd->getSurface(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedPlot3D_getNumSurfaces(SedPlot3D_t * spd)
{
	return  (spd != NULL) ? spd->getNumSurfaces() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSurface_t *
SedPlot3D_removeSurface(SedPlot3D_t * spd, unsigned int n)
{
	return  (spd != NULL) ? spd->removeSurface(n) : NULL;
}

LIBSEDML_EXTERN
SedSurface_t *
SedPlot3D_removeSurfaceById(SedPlot3D_t * spd, const char * sid)
{
	return  (spd != NULL) ? spd->removeSurface(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedPlot3D_hasRequiredAttributes(SedPlot3D_t * spd)
{
	return (spd != NULL) ? static_cast<int>(spd->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedPlot3D_hasRequiredElements(SedPlot3D_t * spd)
{
	return (spd != NULL) ? static_cast<int>(spd->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


