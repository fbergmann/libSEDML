/**
 * @file:   SedComputeChange.cpp
 * @brief:  Implementation of the SedComputeChange class
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


#include <sedml/SedComputeChange.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedComputeChange with the given level, version, and package version.
 */
SedComputeChange::SedComputeChange (unsigned int level, unsigned int version)
	: SedChange(level, version)
	, mVariables (level, version)
	, mParameters (level, version)
	, mMath (NULL)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedComputeChange with the given SedNamespaces object.
 */
SedComputeChange::SedComputeChange (SedNamespaces* sedns)
	: SedChange(sedns)
	, mVariables (sedns)
	, mParameters (sedns)
	, mMath (NULL)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedComputeChange.
 */
SedComputeChange::SedComputeChange (const SedComputeChange& orig)
	: SedChange(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mVariables  = orig.mVariables;
		mParameters  = orig.mParameters;
		mMath  = orig.mMath != NULL ? orig.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedComputeChange.
 */
SedComputeChange&
SedComputeChange::operator=(const SedComputeChange& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedChange::operator=(rhs);
		mVariables  = rhs.mVariables;
		mParameters  = rhs.mParameters;
		mMath  = rhs.mMath != NULL ? rhs.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedComputeChange.
 */
SedComputeChange*
SedComputeChange::clone () const
{
	return new SedComputeChange(*this);
}


/*
 * Destructor for SedComputeChange.
 */
SedComputeChange::~SedComputeChange ()
{
}


/*
 * Returns the value of the "math" attribute of this SedComputeChange.
 */
const ASTNode*
SedComputeChange::getMath() const
{
	return mMath;
}


/*
 * Returns true/false if math is set.
 */
bool
SedComputeChange::isSetMath() const
{
	return (mMath != NULL);
}


/*
 * Sets math and returns value indicating success.
 */
int
SedComputeChange::setMath(ASTNode* math)
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
SedComputeChange::unsetMath()
{
	delete mMath;
	mMath = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfVariables" in this SedComputeChange object.
 */
const SedListOfVariables*
SedComputeChange::getListOfVariables() const
{
	return &mVariables;
}


/*
 * Removes the nth Variable from the SedListOfVariables.
 */
SedVariable*
SedComputeChange::removeVariable(unsigned int n)
{
	return mVariables.remove(n);
}


/*
 * Removes the a Variable with given id from the SedListOfVariables.
 */
SedVariable*
SedComputeChange::removeVariable(const std::string& sid)
{
	return mVariables.remove(sid);
}


/*
 * Return the nth Variable in the SedListOfVariables within this SedComputeChange.
 */
SedVariable*
SedComputeChange::getVariable(unsigned int n)
{
	return mVariables.get(n);
}


/*
 * Return the nth Variable in the SedListOfVariables within this SedComputeChange.
 */
const SedVariable*
SedComputeChange::getVariable(unsigned int n) const
{
	return mVariables.get(n);
}


/*
 * Return a Variable from the SedListOfVariables by id.
 */
SedVariable*
SedComputeChange::getVariable(const std::string& sid)
{
	return mVariables.get(sid);
}


/*
 * Return a Variable from the SedListOfVariables by id.
 */
const SedVariable*
SedComputeChange::getVariable(const std::string& sid) const
{
	return mVariables.get(sid);
}


/**
 * Adds a copy the given "SedVariable" to this SedComputeChange.
 *
 * @param sv; the SedVariable object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedComputeChange::addVariable(const SedVariable* sv)
{
	if(sv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mVariables.append(sv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedVariable objects in this SedComputeChange.
 *
 * @return the number of SedVariable objects in this SedComputeChange
 */
unsigned int 
SedComputeChange::getNumVariables() const
{
	return mVariables.size();
}

/**
 * Creates a new SedVariable object, adds it to this SedComputeChanges
 * SedComputeChange and returns the SedVariable object created. 
 *
 * @return a new SedVariable object instance
 *
 * @see addSedVariable(const SedVariable* sv)
 */
SedVariable* 
SedComputeChange::createVariable()
{
	SedVariable *temp = new SedVariable();
	if (temp != NULL) mVariables.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfParameters" in this SedComputeChange object.
 */
const SedListOfParameters*
SedComputeChange::getListOfParameters() const
{
	return &mParameters;
}


/*
 * Removes the nth Parameter from the SedListOfParameters.
 */
SedParameter*
SedComputeChange::removeParameter(unsigned int n)
{
	return mParameters.remove(n);
}


/*
 * Removes the a Parameter with given id from the SedListOfParameters.
 */
SedParameter*
SedComputeChange::removeParameter(const std::string& sid)
{
	return mParameters.remove(sid);
}


/*
 * Return the nth Parameter in the SedListOfParameters within this SedComputeChange.
 */
SedParameter*
SedComputeChange::getParameter(unsigned int n)
{
	return mParameters.get(n);
}


/*
 * Return the nth Parameter in the SedListOfParameters within this SedComputeChange.
 */
const SedParameter*
SedComputeChange::getParameter(unsigned int n) const
{
	return mParameters.get(n);
}


/*
 * Return a Parameter from the SedListOfParameters by id.
 */
SedParameter*
SedComputeChange::getParameter(const std::string& sid)
{
	return mParameters.get(sid);
}


/*
 * Return a Parameter from the SedListOfParameters by id.
 */
const SedParameter*
SedComputeChange::getParameter(const std::string& sid) const
{
	return mParameters.get(sid);
}


/**
 * Adds a copy the given "SedParameter" to this SedComputeChange.
 *
 * @param sp; the SedParameter object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedComputeChange::addParameter(const SedParameter* sp)
{
	if(sp == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mParameters.append(sp);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedParameter objects in this SedComputeChange.
 *
 * @return the number of SedParameter objects in this SedComputeChange
 */
unsigned int 
SedComputeChange::getNumParameters() const
{
	return mParameters.size();
}

/**
 * Creates a new SedParameter object, adds it to this SedComputeChanges
 * SedComputeChange and returns the SedParameter object created. 
 *
 * @return a new SedParameter object instance
 *
 * @see addSedParameter(const SedParameter* sp)
 */
SedParameter* 
SedComputeChange::createParameter()
{
	SedParameter *temp = new SedParameter();
	if (temp != NULL) mParameters.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedComputeChange::getElementName () const
{
	static const string name = "computeChange";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedComputeChange::createObject(XMLInputStream& stream)
{
	SedBase* object = SedChange::createObject(stream);

	const string& name   = stream.peek().getName();

	if (name == "listOfVariables")
	{
		object = &mVariables;
	}

	if (name == "listOfParameters")
	{
		object = &mParameters;
	}

	connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedComputeChange::connectToChild ()
{
	SedChange::connectToChild();

	mVariables.connectToParent(this);
	mParameters.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedComputeChange::getTypeCode () const
{
	return SEDML_CHANGE_COMPUTECHANGE;
}


/*
 * check if all the required attributes are set
 */
bool
SedComputeChange::hasRequiredAttributes () const
{
	bool allPresent = SedChange::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedComputeChange::hasRequiredElements () const
{
	bool allPresent = SedChange::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedComputeChange::writeElements (XMLOutputStream& stream) const
{
	SedChange::writeElements(stream);
	if (getNumVariables() > 0)
	{
		mVariables.write(stream);
	}
	if (getNumParameters() > 0)
	{
		mParameters.write(stream);
	}
	if (isSetMath() == true)
	{
		writeMathML(getMath(), stream, NULL);
	}
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedComputeChange::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedComputeChange::setSedDocument (SedDocument* d)
{
	SedChange::setSedDocument(d);
	mVariables.setSedDocument(d);
	mParameters.setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedComputeChange::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedChange::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedComputeChange::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedChange::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

bool
SedComputeChange::readOtherXML (XMLInputStream& stream)
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

	if (SedChange::readOtherXML(stream))
	{
		read = true;
	}
	return read;
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedComputeChange::writeAttributes (XMLOutputStream& stream) const
{
	SedChange::writeAttributes(stream);

}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedComputeChange_t *
SedComputeChange_create(unsigned int level, unsigned int version)
{
	return new SedComputeChange(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedComputeChange_free(SedComputeChange_t * scc)
{
	if (scc != NULL)
		delete scc;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedComputeChange_t *
SedComputeChange_clone(SedComputeChange_t * scc)
{
	if (scc != NULL)
	{
		return static_cast<SedComputeChange_t*>(scc->clone());
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
ASTNode_t*
SedComputeChange_getMath(SedComputeChange_t * scc)
{
	if (scc == NULL)
		return NULL;

	return (ASTNode_t*)scc->getMath();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedComputeChange_isSetMath(SedComputeChange_t * scc)
{
	return (scc != NULL) ? static_cast<int>(scc->isSetMath()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedComputeChange_setMath(SedComputeChange_t * scc, ASTNode_t* math)
{
	return (scc != NULL) ? scc->setMath(math) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedComputeChange_unsetMath(SedComputeChange_t * scc)
{
	return (scc != NULL) ? scc->unsetMath() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedComputeChange_addVariable(SedComputeChange_t * scc, SedVariable_t * sv)
{
	return  (scc != NULL) ? scc->addVariable(sv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedVariable_t *
SedComputeChange_createVariable(SedComputeChange_t * scc)
{
	return  (scc != NULL) ? scc->createVariable() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedComputeChange_getSedListOfVariables(SedComputeChange_t * scc)
{
	return  (scc != NULL) ? (SedListOf_t *)scc->getListOfVariables() : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedComputeChange_getVariable(SedComputeChange_t * scc, unsigned int n)
{
	return  (scc != NULL) ? scc->getVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedComputeChange_getVariableById(SedComputeChange_t * scc, const char * sid)
{
	return  (scc != NULL) ? scc->getVariable(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedComputeChange_getNumVariables(SedComputeChange_t * scc)
{
	return  (scc != NULL) ? scc->getNumVariables() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedVariable_t *
SedComputeChange_removeVariable(SedComputeChange_t * scc, unsigned int n)
{
	return  (scc != NULL) ? scc->removeVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedComputeChange_removeVariableById(SedComputeChange_t * scc, const char * sid)
{
	return  (scc != NULL) ? scc->removeVariable(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedComputeChange_addParameter(SedComputeChange_t * scc, SedParameter_t * sp)
{
	return  (scc != NULL) ? scc->addParameter(sp) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedParameter_t *
SedComputeChange_createParameter(SedComputeChange_t * scc)
{
	return  (scc != NULL) ? scc->createParameter() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedComputeChange_getSedListOfParameters(SedComputeChange_t * scc)
{
	return  (scc != NULL) ? (SedListOf_t *)scc->getListOfParameters() : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedComputeChange_getParameter(SedComputeChange_t * scc, unsigned int n)
{
	return  (scc != NULL) ? scc->getParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedComputeChange_getParameterById(SedComputeChange_t * scc, const char * sid)
{
	return  (scc != NULL) ? scc->getParameter(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedComputeChange_getNumParameters(SedComputeChange_t * scc)
{
	return  (scc != NULL) ? scc->getNumParameters() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedParameter_t *
SedComputeChange_removeParameter(SedComputeChange_t * scc, unsigned int n)
{
	return  (scc != NULL) ? scc->removeParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedComputeChange_removeParameterById(SedComputeChange_t * scc, const char * sid)
{
	return  (scc != NULL) ? scc->removeParameter(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedComputeChange_hasRequiredAttributes(SedComputeChange_t * scc)
{
	return (scc != NULL) ? static_cast<int>(scc->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedComputeChange_hasRequiredElements(SedComputeChange_t * scc)
{
	return (scc != NULL) ? static_cast<int>(scc->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


