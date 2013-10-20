/**
 * @file:   SedFunctionalRange.cpp
 * @brief:  Implementation of the SedFunctionalRange class
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


#include <sedml/SedFunctionalRange.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedFunctionalRange with the given level, version, and package version.
 */
SedFunctionalRange::SedFunctionalRange (unsigned int level, unsigned int version)
	: SedRange(level, version)
	, mVariables (level, version)
	, mParameters (level, version)
	, mRange ("")
	, mMath (NULL)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedFunctionalRange with the given SedNamespaces object.
 */
SedFunctionalRange::SedFunctionalRange (SedNamespaces* sedns)
	: SedRange(sedns)
	, mVariables (sedns)
	, mParameters (sedns)
	, mRange ("")
	, mMath (NULL)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedFunctionalRange.
 */
SedFunctionalRange::SedFunctionalRange (const SedFunctionalRange& orig)
	: SedRange(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mVariables  = orig.mVariables;
		mParameters  = orig.mParameters;
		mRange  = orig.mRange;
		mMath  = orig.mMath != NULL ? orig.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedFunctionalRange.
 */
SedFunctionalRange&
SedFunctionalRange::operator=(const SedFunctionalRange& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedRange::operator=(rhs);
		mVariables  = rhs.mVariables;
		mParameters  = rhs.mParameters;
		mRange  = rhs.mRange;
		mMath  = rhs.mMath != NULL ? rhs.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedFunctionalRange.
 */
SedFunctionalRange*
SedFunctionalRange::clone () const
{
	return new SedFunctionalRange(*this);
}


/*
 * Destructor for SedFunctionalRange.
 */
SedFunctionalRange::~SedFunctionalRange ()
{
}


/*
 * Returns the value of the "range" attribute of this SedFunctionalRange.
 */
const std::string&
SedFunctionalRange::getRange() const
{
	return mRange;
}


/*
 * Returns the value of the "math" attribute of this SedFunctionalRange.
 */
const ASTNode*
SedFunctionalRange::getMath() const
{
	return mMath;
}


/*
 * Returns true/false if range is set.
 */
bool
SedFunctionalRange::isSetRange() const
{
	return (mRange.empty() == false);
}


/*
 * Returns true/false if math is set.
 */
bool
SedFunctionalRange::isSetMath() const
{
	return (mMath != NULL);
}


/*
 * Sets range and returns value indicating success.
 */
int
SedFunctionalRange::setRange(const std::string& range)
{
	if (&(range) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(range)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mRange = range;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets math and returns value indicating success.
 */
int
SedFunctionalRange::setMath(ASTNode* math)
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
 * Unsets range and returns value indicating success.
 */
int
SedFunctionalRange::unsetRange()
{
	mRange.erase();

	if (mRange.empty() == true)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets math and returns value indicating success.
 */
int
SedFunctionalRange::unsetMath()
{
	delete mMath;
	mMath = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfVariables" in this SedFunctionalRange object.
 */
const SedListOfVariables*
SedFunctionalRange::getListOfVariables() const
{
	return &mVariables;
}


/*
 * Removes the nth Variable from the SedListOfVariables.
 */
SedVariable*
SedFunctionalRange::removeVariable(unsigned int n)
{
	return mVariables.remove(n);
}


/*
 * Removes the a Variable with given id from the SedListOfVariables.
 */
SedVariable*
SedFunctionalRange::removeVariable(const std::string& sid)
{
	return mVariables.remove(sid);
}


/*
 * Return the nth Variable in the SedListOfVariables within this SedFunctionalRange.
 */
SedVariable*
SedFunctionalRange::getVariable(unsigned int n)
{
	return mVariables.get(n);
}


/*
 * Return the nth Variable in the SedListOfVariables within this SedFunctionalRange.
 */
const SedVariable*
SedFunctionalRange::getVariable(unsigned int n) const
{
	return mVariables.get(n);
}


/*
 * Return a Variable from the SedListOfVariables by id.
 */
SedVariable*
SedFunctionalRange::getVariable(const std::string& sid)
{
	return mVariables.get(sid);
}


/*
 * Return a Variable from the SedListOfVariables by id.
 */
const SedVariable*
SedFunctionalRange::getVariable(const std::string& sid) const
{
	return mVariables.get(sid);
}


/**
 * Adds a copy the given "SedVariable" to this SedFunctionalRange.
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
SedFunctionalRange::addVariable(const SedVariable* sv)
{
	if(sv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mVariables.append(sv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedVariable objects in this SedFunctionalRange.
 *
 * @return the number of SedVariable objects in this SedFunctionalRange
 */
unsigned int 
SedFunctionalRange::getNumVariables() const
{
	return mVariables.size();
}

/**
 * Creates a new SedVariable object, adds it to this SedFunctionalRanges
 * SedFunctionalRange and returns the SedVariable object created. 
 *
 * @return a new SedVariable object instance
 *
 * @see addSedVariable(const SedVariable* sv)
 */
SedVariable* 
SedFunctionalRange::createVariable()
{
	SedVariable *temp = new SedVariable();
	if (temp != NULL) mVariables.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfParameters" in this SedFunctionalRange object.
 */
const SedListOfParameters*
SedFunctionalRange::getListOfParameters() const
{
	return &mParameters;
}


/*
 * Removes the nth Parameter from the SedListOfParameters.
 */
SedParameter*
SedFunctionalRange::removeParameter(unsigned int n)
{
	return mParameters.remove(n);
}


/*
 * Removes the a Parameter with given id from the SedListOfParameters.
 */
SedParameter*
SedFunctionalRange::removeParameter(const std::string& sid)
{
	return mParameters.remove(sid);
}


/*
 * Return the nth Parameter in the SedListOfParameters within this SedFunctionalRange.
 */
SedParameter*
SedFunctionalRange::getParameter(unsigned int n)
{
	return mParameters.get(n);
}


/*
 * Return the nth Parameter in the SedListOfParameters within this SedFunctionalRange.
 */
const SedParameter*
SedFunctionalRange::getParameter(unsigned int n) const
{
	return mParameters.get(n);
}


/*
 * Return a Parameter from the SedListOfParameters by id.
 */
SedParameter*
SedFunctionalRange::getParameter(const std::string& sid)
{
	return mParameters.get(sid);
}


/*
 * Return a Parameter from the SedListOfParameters by id.
 */
const SedParameter*
SedFunctionalRange::getParameter(const std::string& sid) const
{
	return mParameters.get(sid);
}


/**
 * Adds a copy the given "SedParameter" to this SedFunctionalRange.
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
SedFunctionalRange::addParameter(const SedParameter* sp)
{
	if(sp == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mParameters.append(sp);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedParameter objects in this SedFunctionalRange.
 *
 * @return the number of SedParameter objects in this SedFunctionalRange
 */
unsigned int 
SedFunctionalRange::getNumParameters() const
{
	return mParameters.size();
}

/**
 * Creates a new SedParameter object, adds it to this SedFunctionalRanges
 * SedFunctionalRange and returns the SedParameter object created. 
 *
 * @return a new SedParameter object instance
 *
 * @see addSedParameter(const SedParameter* sp)
 */
SedParameter* 
SedFunctionalRange::createParameter()
{
	SedParameter *temp = new SedParameter();
	if (temp != NULL) mParameters.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedFunctionalRange::getElementName () const
{
	static const string name = "functionalRange";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedFunctionalRange::createObject(XMLInputStream& stream)
{
	SedBase* object = SedRange::createObject(stream);

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
SedFunctionalRange::connectToChild ()
{
	SedRange::connectToChild();

	mVariables.connectToParent(this);
	mParameters.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedFunctionalRange::getTypeCode () const
{
	return SEDML_RANGE_FUNCTIONALRANGE;
}


/*
 * check if all the required attributes are set
 */
bool
SedFunctionalRange::hasRequiredAttributes () const
{
	bool allPresent = SedRange::hasRequiredAttributes();

	if (isSetRange() == false)
		allPresent = false;

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedFunctionalRange::hasRequiredElements () const
{
	bool allPresent = SedRange::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedFunctionalRange::writeElements (XMLOutputStream& stream) const
{
	SedRange::writeElements(stream);
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


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedFunctionalRange::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedFunctionalRange::setSedDocument (SedDocument* d)
{
	SedRange::setSedDocument(d);
	mVariables.setSedDocument(d);
	mParameters.setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedFunctionalRange::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedRange::addExpectedAttributes(attributes);

	attributes.add("range");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedFunctionalRange::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedRange::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// range SIdRef   ( use = "required" )
	//
	assigned = attributes.readInto("range", mRange, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mRange.empty() == true)
		{
			logEmptyString(mRange, getLevel(), getVersion(), "<SedFunctionalRange>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mRange) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

bool
SedFunctionalRange::readOtherXML (XMLInputStream& stream)
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

	if (SedRange::readOtherXML(stream))
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
SedFunctionalRange::writeAttributes (XMLOutputStream& stream) const
{
	SedRange::writeAttributes(stream);

	if (isSetRange() == true)
		stream.writeAttribute("range", getPrefix(), mRange);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfFunctionalRanges::SedListOfFunctionalRanges(unsigned int level, 
	                          unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfFunctionalRanges::SedListOfFunctionalRanges(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfFunctionalRanges 
 */
SedListOfFunctionalRanges* 
SedListOfFunctionalRanges::clone () const
 {
	return new SedListOfFunctionalRanges(*this);
}


/*
 * Get a FunctionalRange from the SedListOfFunctionalRanges by index.
*/
SedFunctionalRange*
SedListOfFunctionalRanges::get(unsigned int n)
{
	return static_cast<SedFunctionalRange*>(SedListOf::get(n));
}


/*
 * Get a FunctionalRange from the SedListOfFunctionalRanges by index.
 */
const SedFunctionalRange*
SedListOfFunctionalRanges::get(unsigned int n) const
{
	return static_cast<const SedFunctionalRange*>(SedListOf::get(n));
}


/*
 * Get a FunctionalRange from the SedListOfFunctionalRanges by id.
 */
SedFunctionalRange*
SedListOfFunctionalRanges::get(const std::string& sid)
{
	return const_cast<SedFunctionalRange*>(
	  static_cast<const SedListOfFunctionalRanges&>(*this).get(sid));
}


/*
 * Get a FunctionalRange from the SedListOfFunctionalRanges by id.
 */
const SedFunctionalRange*
SedListOfFunctionalRanges::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedFunctionalRange>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedFunctionalRange*> (*result);
}


/**
 * Adds a copy the given "SedFunctionalRange" to this SedListOfFunctionalRanges.
 *
 * @param sfr; the SedFunctionalRange object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfFunctionalRanges::addFunctionalRange(const SedFunctionalRange* sfr)
{
	if(sfr == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sfr);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedFunctionalRange objects in this SedListOfFunctionalRanges.
 *
 * @return the number of SedFunctionalRange objects in this SedListOfFunctionalRanges
 */
unsigned int 
SedListOfFunctionalRanges::getNumFunctionalRanges() const
{
	return size();
}

/**
 * Creates a new SedFunctionalRange object, adds it to this SedListOfFunctionalRangess
 * SedFunctionalRange and returns the SedFunctionalRange object created. 
 *
 * @return a new SedFunctionalRange object instance
 *
 * @see addSedFunctionalRange(const SedFunctionalRange* sfr)
 */
SedFunctionalRange* 
SedListOfFunctionalRanges::createFunctionalRange()
{
	SedFunctionalRange *temp = new SedFunctionalRange();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth FunctionalRange from this SedListOfFunctionalRanges
 */
SedFunctionalRange*
SedListOfFunctionalRanges::remove(unsigned int n)
{
	return static_cast<SedFunctionalRange*>(SedListOf::remove(n));
}


/*
 * Removes the FunctionalRange from this SedListOfFunctionalRanges with the given identifier
 */
SedFunctionalRange*
SedListOfFunctionalRanges::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedFunctionalRange>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedFunctionalRange*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfFunctionalRanges::getElementName () const
{
	static const string name = "listOfFunctionalRanges";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfFunctionalRanges::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfFunctionalRanges::getItemTypeCode () const
{
	return SEDML_RANGE_FUNCTIONALRANGE;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedFunctionalRange in this SedListOfFunctionalRanges
 */
SedBase*
SedListOfFunctionalRanges::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "functionalRange")
	{
		object = new SedFunctionalRange(getSedNamespaces());
		appendAndOwn(object);
	}

	return object;
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write the namespace for the Sed package.
 */
void
SedListOfFunctionalRanges::writeXMLNS(XMLOutputStream& stream) const
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


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedFunctionalRange_t *
SedFunctionalRange_create(unsigned int level, unsigned int version)
{
	return new SedFunctionalRange(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedFunctionalRange_free(SedFunctionalRange_t * sfr)
{
	if (sfr != NULL)
		delete sfr;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedFunctionalRange_t *
SedFunctionalRange_clone(SedFunctionalRange_t * sfr)
{
	if (sfr != NULL)
	{
		return static_cast<SedFunctionalRange_t*>(sfr->clone());
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
SedFunctionalRange_getRange(SedFunctionalRange_t * sfr)
{
	if (sfr == NULL)
		return NULL;

	return sfr->getRange().empty() ? NULL : safe_strdup(sfr->getRange().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
ASTNode_t*
SedFunctionalRange_getMath(SedFunctionalRange_t * sfr)
{
	if (sfr == NULL)
		return NULL;

	return (ASTNode_t*)sfr->getMath();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_isSetRange(SedFunctionalRange_t * sfr)
{
	return (sfr != NULL) ? static_cast<int>(sfr->isSetRange()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_isSetMath(SedFunctionalRange_t * sfr)
{
	return (sfr != NULL) ? static_cast<int>(sfr->isSetMath()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_setRange(SedFunctionalRange_t * sfr, const char * range)
{
	return (sfr != NULL) ? sfr->setRange(range) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_setMath(SedFunctionalRange_t * sfr, ASTNode_t* math)
{
	return (sfr != NULL) ? sfr->setMath(math) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_unsetRange(SedFunctionalRange_t * sfr)
{
	return (sfr != NULL) ? sfr->unsetRange() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_unsetMath(SedFunctionalRange_t * sfr)
{
	return (sfr != NULL) ? sfr->unsetMath() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedFunctionalRange_addVariable(SedFunctionalRange_t * sfr, SedVariable_t * sv)
{
	return  (sfr != NULL) ? sfr->addVariable(sv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedVariable_t *
SedFunctionalRange_createVariable(SedFunctionalRange_t * sfr)
{
	return  (sfr != NULL) ? sfr->createVariable() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedFunctionalRange_getSedListOfVariables(SedFunctionalRange_t * sfr)
{
	return  (sfr != NULL) ? (SedListOf_t *)sfr->getListOfVariables() : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedFunctionalRange_getVariable(SedFunctionalRange_t * sfr, unsigned int n)
{
	return  (sfr != NULL) ? sfr->getVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedFunctionalRange_getVariableById(SedFunctionalRange_t * sfr, const char * sid)
{
	return  (sfr != NULL) ? sfr->getVariable(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedFunctionalRange_getNumVariables(SedFunctionalRange_t * sfr)
{
	return  (sfr != NULL) ? sfr->getNumVariables() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedVariable_t *
SedFunctionalRange_removeVariable(SedFunctionalRange_t * sfr, unsigned int n)
{
	return  (sfr != NULL) ? sfr->removeVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedFunctionalRange_removeVariableById(SedFunctionalRange_t * sfr, const char * sid)
{
	return  (sfr != NULL) ? sfr->removeVariable(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedFunctionalRange_addParameter(SedFunctionalRange_t * sfr, SedParameter_t * sp)
{
	return  (sfr != NULL) ? sfr->addParameter(sp) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedParameter_t *
SedFunctionalRange_createParameter(SedFunctionalRange_t * sfr)
{
	return  (sfr != NULL) ? sfr->createParameter() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedFunctionalRange_getSedListOfParameters(SedFunctionalRange_t * sfr)
{
	return  (sfr != NULL) ? (SedListOf_t *)sfr->getListOfParameters() : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedFunctionalRange_getParameter(SedFunctionalRange_t * sfr, unsigned int n)
{
	return  (sfr != NULL) ? sfr->getParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedFunctionalRange_getParameterById(SedFunctionalRange_t * sfr, const char * sid)
{
	return  (sfr != NULL) ? sfr->getParameter(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedFunctionalRange_getNumParameters(SedFunctionalRange_t * sfr)
{
	return  (sfr != NULL) ? sfr->getNumParameters() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedParameter_t *
SedFunctionalRange_removeParameter(SedFunctionalRange_t * sfr, unsigned int n)
{
	return  (sfr != NULL) ? sfr->removeParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedFunctionalRange_removeParameterById(SedFunctionalRange_t * sfr, const char * sid)
{
	return  (sfr != NULL) ? sfr->removeParameter(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_hasRequiredAttributes(SedFunctionalRange_t * sfr)
{
	return (sfr != NULL) ? static_cast<int>(sfr->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedFunctionalRange_hasRequiredElements(SedFunctionalRange_t * sfr)
{
	return (sfr != NULL) ? static_cast<int>(sfr->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedFunctionalRange_t *
SedListOfFunctionalRanges_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfFunctionalRanges *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedFunctionalRange_t *
SedListOfFunctionalRanges_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfFunctionalRanges *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


