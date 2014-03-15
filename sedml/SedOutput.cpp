/**
 * @file:   SedOutput.cpp
 * @brief:  Implementation of the SedOutput class
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


#include <sedml/SedOutput.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedOutput with the given level, version, and package version.
 */
SedOutput::SedOutput (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedOutput with the given SedNamespaces object.
 */
SedOutput::SedOutput (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")
	, mName ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedOutput.
 */
SedOutput::SedOutput (const SedOutput& orig)
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

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedOutput.
 */
SedOutput&
SedOutput::operator=(const SedOutput& rhs)
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

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedOutput.
 */
SedOutput*
SedOutput::clone () const
{
	return new SedOutput(*this);
}


/*
 * Destructor for SedOutput.
 */
SedOutput::~SedOutput ()
{
}


/*
 * Returns the value of the "id" attribute of this SedOutput.
 */
const std::string&
SedOutput::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedOutput.
 */
const std::string&
SedOutput::getName() const
{
	return mName;
}


/*
 * Returns true/false if id is set.
 */
bool
SedOutput::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedOutput::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedOutput::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedOutput::setName(const std::string& name)
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
 * Unsets id and returns value indicating success.
 */
int
SedOutput::unsetId()
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
SedOutput::unsetName()
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
 * Returns the XML element name of this object
 */
const std::string&
SedOutput::getElementName () const
{
	static const string name = "output";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedOutput::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedOutput::connectToChild ()
{
	SedBase::connectToChild();

}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedOutput::getTypeCode () const
{
	return SEDML_OUTPUT;
}


/*
 * check if all the required attributes are set
 */
bool
SedOutput::hasRequiredAttributes () const
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
SedOutput::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedOutput::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedOutput::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedOutput::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedOutput::addExpectedAttributes(ExpectedAttributes& attributes)
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
SedOutput::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedOutput>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedOutput>");
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedOutput::writeAttributes (XMLOutputStream& stream) const
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
SedListOfOutputs::SedListOfOutputs(unsigned int level, 
	                 unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfOutputs::SedListOfOutputs(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfOutputs 
 */
SedListOfOutputs* 
SedListOfOutputs::clone () const
 {
	return new SedListOfOutputs(*this);
}


/*
 * Get a Output from the SedListOfOutputs by index.
*/
SedOutput*
SedListOfOutputs::get(unsigned int n)
{
	return static_cast<SedOutput*>(SedListOf::get(n));
}


/*
 * Get a Output from the SedListOfOutputs by index.
 */
const SedOutput*
SedListOfOutputs::get(unsigned int n) const
{
	return static_cast<const SedOutput*>(SedListOf::get(n));
}


/*
 * Get a Output from the SedListOfOutputs by id.
 */
SedOutput*
SedListOfOutputs::get(const std::string& sid)
{
	return const_cast<SedOutput*>(
	  static_cast<const SedListOfOutputs&>(*this).get(sid));
}


/*
 * Get a Output from the SedListOfOutputs by id.
 */
const SedOutput*
SedListOfOutputs::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedOutput>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedOutput*> (*result);
}


/**
 * Adds a copy the given "SedOutput" to this SedListOfOutputs.
 *
 * @param so; the SedOutput object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfOutputs::addOutput(const SedOutput* so)
{
	if(so == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(so);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedOutput objects in this SedListOfOutputs.
 *
 * @return the number of SedOutput objects in this SedListOfOutputs
 */
unsigned int 
SedListOfOutputs::getNumOutputs() const
{
	return size();
}

/**
 * Creates a new SedReport object, adds it to this SedListOfOutputs
 * report and returns the SedReport object created. 
 *
 * @return a new SedReport object instance
 *
 * @see addReport(const SedOutput* so)
 */
SedReport* 
SedListOfOutputs::createReport()
{
	SedReport *temp = new SedReport();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedPlot2D object, adds it to this SedListOfOutputs
 * plot2D and returns the SedPlot2D object created. 
 *
 * @return a new SedPlot2D object instance
 *
 * @see addPlot2D(const SedOutput* so)
 */
SedPlot2D* 
SedListOfOutputs::createPlot2D()
{
	SedPlot2D *temp = new SedPlot2D();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedPlot3D object, adds it to this SedListOfOutputs
 * plot3D and returns the SedPlot3D object created. 
 *
 * @return a new SedPlot3D object instance
 *
 * @see addPlot3D(const SedOutput* so)
 */
SedPlot3D* 
SedListOfOutputs::createPlot3D()
{
	SedPlot3D *temp = new SedPlot3D();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Output from this SedListOfOutputs
 */
SedOutput*
SedListOfOutputs::remove(unsigned int n)
{
	return static_cast<SedOutput*>(SedListOf::remove(n));
}


/*
 * Removes the Output from this SedListOfOutputs with the given identifier
 */
SedOutput*
SedListOfOutputs::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedOutput>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedOutput*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfOutputs::getElementName () const
{
	static const string name = "listOfOutputs";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfOutputs::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfOutputs::getItemTypeCode () const
{
	return SEDML_OUTPUT;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedOutput in this SedListOfOutputs
 */
SedBase*
SedListOfOutputs::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "report")
	{
		object = new SedReport(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "plot2D")
	{
		object = new SedPlot2D(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "plot3D")
	{
		object = new SedPlot3D(getSedNamespaces());
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
SedListOfOutputs::writeXMLNS(XMLOutputStream& stream) const
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
SedOutput_t *
SedOutput_create(unsigned int level, unsigned int version)
{
	return new SedOutput(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedOutput_free(SedOutput_t * so)
{
	if (so != NULL)
		delete so;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedOutput_t *
SedOutput_clone(SedOutput_t * so)
{
	if (so != NULL)
	{
		return static_cast<SedOutput_t*>(so->clone());
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
SedOutput_getId(SedOutput_t * so)
{
	if (so == NULL)
		return NULL;

	return so->getId().empty() ? NULL : safe_strdup(so->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedOutput_getName(SedOutput_t * so)
{
	if (so == NULL)
		return NULL;

	return so->getName().empty() ? NULL : safe_strdup(so->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOutput_isSetId(SedOutput_t * so)
{
	return (so != NULL) ? static_cast<int>(so->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOutput_isSetName(SedOutput_t * so)
{
	return (so != NULL) ? static_cast<int>(so->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOutput_setId(SedOutput_t * so, const char * id)
{
	return (so != NULL) ? so->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOutput_setName(SedOutput_t * so, const char * name)
{
	return (so != NULL) ? so->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOutput_unsetId(SedOutput_t * so)
{
	return (so != NULL) ? so->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOutput_unsetName(SedOutput_t * so)
{
	return (so != NULL) ? so->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOutput_hasRequiredAttributes(SedOutput_t * so)
{
	return (so != NULL) ? static_cast<int>(so->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedOutput_hasRequiredElements(SedOutput_t * so)
{
	return (so != NULL) ? static_cast<int>(so->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedOutput_t *
SedListOfOutputs_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfOutputs *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedOutput_t *
SedListOfOutputs_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfOutputs *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


