/**
 * @file:   ComputeChange.cpp
 * @brief:  Implementation of the ComputeChange class
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


#include <sedml/ComputeChange.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new ComputeChange with the given level, version, and package version.
 */
ComputeChange::ComputeChange (unsigned int level, unsigned int version)
	: Change(level, version)
	, mVariable (level, version)
	, mParameter (level, version)
	, mMath (NULL)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new ComputeChange with the given SedMLNamespaces object.
 */
ComputeChange::ComputeChange (SedMLNamespaces* sedmlns)
	: Change(sedmlns)
	, mVariable (sedmlns)
	, mParameter (sedmlns)
	, mMath (NULL)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for ComputeChange.
 */
ComputeChange::ComputeChange (const ComputeChange& orig)
	: Change(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mVariable  = orig.mVariable;
		mParameter  = orig.mParameter;
		mMath  = orig.mMath != NULL ? orig.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for ComputeChange.
 */
ComputeChange&
ComputeChange::operator=(const ComputeChange& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		Change::operator=(rhs);
		mVariable  = rhs.mVariable;
		mParameter  = rhs.mParameter;
		mMath  = rhs.mMath != NULL ? rhs.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for ComputeChange.
 */
ComputeChange*
ComputeChange::clone () const
{
	return new ComputeChange(*this);
}


/*
 * Destructor for ComputeChange.
 */
ComputeChange::~ComputeChange ()
{
}


/*
 * Returns the value of the "math" attribute of this ComputeChange.
 */
const ASTNode*
ComputeChange::getMath() const
{
	return mMath;
}


/*
/*
 * Returns true/false if math is set.
 */
bool
ComputeChange::isSetMath() const
{
	return (mMath != NULL);
}


/*
 * Sets math and returns value indicating success.
 */
int
ComputeChange::setMath(ASTNode* math)
{
	if (mMath == math)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else if (math == NULL)
	{
		delete mMath;
		mMath = NULL;
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else if (!(math->isWellFormedASTNode()))
	{
		return LIBSEDML_INVALID_OBJECT;
	}
	else
	{
		delete mMath;
		mMath = (math != NULL) ?
			math->deepCopy() : NULL;
		if (mMath != NULL)
		{
		}
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets math and returns value indicating success.
 */
int
ComputeChange::unsetMath()
{
	delete mMath;
	mMath = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfSedMLVariables" in this ComputeChange object.
 */
const SedListOfSedMLVariables*
ComputeChange::getListOfSedMLVariables() const
{
	return &mVariable;
}


/*
 * Removes the nth SedMLVariable from the SedListOfSedMLVariables.
 */
SedMLVariable*
ComputeChange::removeSedMLVariable(unsigned int n)
{
	return mVariable.remove(n);
}


/*
 * Removes the a SedMLVariable with given id from the SedListOfSedMLVariables.
 */
SedMLVariable*
ComputeChange::removeSedMLVariable(const std::string& sid)
{
	return mVariable.remove(sid);
}


/*
 * Return the nth SedMLVariable in the SedListOfSedMLVariables within this ComputeChange.
 */
SedMLVariable*
ComputeChange::getSedMLVariable(unsigned int n)
{
	return mVariable.get(n);
}


/*
 * Return the nth SedMLVariable in the SedListOfSedMLVariables within this ComputeChange.
 */
const SedMLVariable*
ComputeChange::getSedMLVariable(unsigned int n) const
{
	return mVariable.get(n);
}


/*
 * Return a SedMLVariable from the SedListOfSedMLVariables by id.
 */
SedMLVariable*
ComputeChange::getSedMLVariable(const std::string& sid)
{
	return mVariable.get(sid);
}


/*
 * Return a SedMLVariable from the SedListOfSedMLVariables by id.
 */
const SedMLVariable*
ComputeChange::getSedMLVariable(const std::string& sid) const
{
	return mVariable.get(sid);
}


/**
 * Adds a copy the given "SedMLVariable" to this ComputeChange.
 *
 * @param smlv; the SedMLVariable object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
ComputeChange::addSedMLVariable(const SedMLVariable* smlv)
{
	if(smlv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mVariable.append(smlv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedMLVariable objects in this ComputeChange.
 *
 * @return the number of SedMLVariable objects in this ComputeChange
 */
unsigned int 
ComputeChange::getNumSedMLVariables() const
{
	return mVariable.size();
}

/**
 * Creates a new SedMLVariable object, adds it to this ComputeChanges
 * ComputeChange and returns the SedMLVariable object created. 
 *
 * @return a new SedMLVariable object instance
 *
 * @see addSedMLVariable(const SedMLVariable* smlv)
 */
SedMLVariable* 
ComputeChange::createSedMLVariable()
{
	SedMLVariable *temp = new SedMLVariable();
	if (temp != NULL) mVariable.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSedMLParameters" in this ComputeChange object.
 */
const SedListOfSedMLParameters*
ComputeChange::getListOfSedMLParameters() const
{
	return &mParameter;
}


/*
 * Removes the nth SedMLParameter from the SedListOfSedMLParameters.
 */
SedMLParameter*
ComputeChange::removeSedMLParameter(unsigned int n)
{
	return mParameter.remove(n);
}


/*
 * Removes the a SedMLParameter with given id from the SedListOfSedMLParameters.
 */
SedMLParameter*
ComputeChange::removeSedMLParameter(const std::string& sid)
{
	return mParameter.remove(sid);
}


/*
 * Return the nth SedMLParameter in the SedListOfSedMLParameters within this ComputeChange.
 */
SedMLParameter*
ComputeChange::getSedMLParameter(unsigned int n)
{
	return mParameter.get(n);
}


/*
 * Return the nth SedMLParameter in the SedListOfSedMLParameters within this ComputeChange.
 */
const SedMLParameter*
ComputeChange::getSedMLParameter(unsigned int n) const
{
	return mParameter.get(n);
}


/*
 * Return a SedMLParameter from the SedListOfSedMLParameters by id.
 */
SedMLParameter*
ComputeChange::getSedMLParameter(const std::string& sid)
{
	return mParameter.get(sid);
}


/*
 * Return a SedMLParameter from the SedListOfSedMLParameters by id.
 */
const SedMLParameter*
ComputeChange::getSedMLParameter(const std::string& sid) const
{
	return mParameter.get(sid);
}


/**
 * Adds a copy the given "SedMLParameter" to this ComputeChange.
 *
 * @param smlp; the SedMLParameter object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
ComputeChange::addSedMLParameter(const SedMLParameter* smlp)
{
	if(smlp == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mParameter.append(smlp);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedMLParameter objects in this ComputeChange.
 *
 * @return the number of SedMLParameter objects in this ComputeChange
 */
unsigned int 
ComputeChange::getNumSedMLParameters() const
{
	return mParameter.size();
}

/**
 * Creates a new SedMLParameter object, adds it to this ComputeChanges
 * ComputeChange and returns the SedMLParameter object created. 
 *
 * @return a new SedMLParameter object instance
 *
 * @see addSedMLParameter(const SedMLParameter* smlp)
 */
SedMLParameter* 
ComputeChange::createSedMLParameter()
{
	SedMLParameter *temp = new SedMLParameter();
	if (temp != NULL) mParameter.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
ComputeChange::getElementName () const
{
	static const string name = "computeChange";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
ComputeChange::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	Change::connectToChild();

	if (name == "listOfVariables")
	{
		object = &mVariable;
	}

	if (name == "listOfParameters")
	{
		object = &mParameter;
	}

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
ComputeChange::connectToChild ()
{
	Change::connectToChild();

	mVariable.connectToParent(this);
	mParameter.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
ComputeChange::getTypeCode () const
{
	return SEDML_CHANGE_COMPUTECHANGE;
}


/*
 * check if all the required attributes are set
 */
bool
ComputeChange::hasRequiredAttributes () const
{
	bool allPresent = Change::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
ComputeChange::hasRequiredElements () const
{
	bool allPresent = Change::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
ComputeChange::writeElements (XMLOutputStream& stream) const
{
	Change::writeElements(stream);
	if (getNumSedMLVariables() > 0)
	{
		mVariable.write(stream);
	}
	if (getNumSedMLParameters() > 0)
	{
		mParameter.write(stream);
	}
	if (isSetMath() == true)
	{
		writeMathML(getMath(), stream, NULL);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
ComputeChange::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
ComputeChange::setSedMLDocument (SedMLDocument* d)
{
	Change::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
ComputeChange::addExpectedAttributes(ExpectedAttributes& attributes)
{
	Change::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
ComputeChange::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	Change::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

bool
ComputeChange::readOtherXML (XMLInputStream& stream)
{
	bool          read = false;
	const string& name = stream.peek().getName();

	if (name == "math")
	{
		const XMLToken elem = stream.peek();
		const std::string prefix = checkMathMLNamespace(elem);

		delete mMath;
		mMath = readMathML(stream, prefix);
		read = true;
	}

	if (Change::readOtherXML(stream))
		{
		read = true;
	}
	return read;
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
ComputeChange::writeAttributes (XMLOutputStream& stream) const
{
	Change::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
ComputeChange_t *
ComputeChange_create(unsigned int level, unsigned int version)
{
	return new ComputeChange(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
ComputeChange_free(ComputeChange_t * cc)
{
	if (cc != NULL)
		delete cc;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
ComputeChange_t *
ComputeChange_clone(ComputeChange_t * cc)
{
	if (cc != NULL)
	{
		return static_cast<ComputeChange_t*>(cc->clone());
	}
	else
	{
		return NULL;
	}
}


LIBSEDML_EXTERN
int
ComputeChange_addSedMLVariable(ComputeChange_t * cc, SedMLVariable_t * smlv)
{
	return  (cc != NULL) ? cc->addSedMLVariable(smlv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedMLVariable_t *
ComputeChange_createSedMLVariable(ComputeChange_t * cc)
{
	return  (cc != NULL) ? cc->createSedMLVariable() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
ComputeChange_getSedListOfSedMLVariables(ComputeChange_t * cc)
{
	return  (cc != NULL) ? (SedListOf_t *)cc->getListOfSedMLVariables() : NULL;
}

LIBSEDML_EXTERN
SedMLVariable_t *
ComputeChange_getSedMLVariable(ComputeChange_t * cc, unsigned int n)
{
	return  (cc != NULL) ? cc->getSedMLVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedMLVariable_t *
ComputeChange_getSedMLVariableById(ComputeChange_t * cc, const char * sid)
{
	return  (cc != NULL) ? cc->getSedMLVariable(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
ComputeChange_getNumSedMLVariables(ComputeChange_t * cc)
{
	return  (cc != NULL) ? cc->getNumSedMLVariables() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedMLVariable_t *
ComputeChange_removeSedMLVariable(ComputeChange_t * cc, unsigned int n)
{
	return  (cc != NULL) ? cc->removeSedMLVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedMLVariable_t *
ComputeChange_removeSedMLVariableById(ComputeChange_t * cc, const char * sid)
{
	return  (cc != NULL) ? cc->removeSedMLVariable(sid) : NULL;
}

LIBSEDML_EXTERN
int
ComputeChange_addSedMLParameter(ComputeChange_t * cc, SedMLParameter_t * smlp)
{
	return  (cc != NULL) ? cc->addSedMLParameter(smlp) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedMLParameter_t *
ComputeChange_createSedMLParameter(ComputeChange_t * cc)
{
	return  (cc != NULL) ? cc->createSedMLParameter() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
ComputeChange_getSedListOfSedMLParameters(ComputeChange_t * cc)
{
	return  (cc != NULL) ? (SedListOf_t *)cc->getListOfSedMLParameters() : NULL;
}

LIBSEDML_EXTERN
SedMLParameter_t *
ComputeChange_getSedMLParameter(ComputeChange_t * cc, unsigned int n)
{
	return  (cc != NULL) ? cc->getSedMLParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedMLParameter_t *
ComputeChange_getSedMLParameterById(ComputeChange_t * cc, const char * sid)
{
	return  (cc != NULL) ? cc->getSedMLParameter(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
ComputeChange_getNumSedMLParameters(ComputeChange_t * cc)
{
	return  (cc != NULL) ? cc->getNumSedMLParameters() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedMLParameter_t *
ComputeChange_removeSedMLParameter(ComputeChange_t * cc, unsigned int n)
{
	return  (cc != NULL) ? cc->removeSedMLParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedMLParameter_t *
ComputeChange_removeSedMLParameterById(ComputeChange_t * cc, const char * sid)
{
	return  (cc != NULL) ? cc->removeSedMLParameter(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
ComputeChange_hasRequiredAttributes(ComputeChange_t * cc)
{
	return (cc != NULL) ? static_cast<int>(cc->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
ComputeChange_hasRequiredElements(ComputeChange_t * cc)
{
	return (cc != NULL) ? static_cast<int>(cc->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


