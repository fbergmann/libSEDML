/**
 * @file:   SedSetValue.cpp
 * @brief:  Implementation of the SedSetValue class
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


#include <sedml/SedSetValue.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedSetValue with the given level, version, and package version.
 */
SedSetValue::SedSetValue (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mVariables (level, version)
	, mParameters (level, version)
	, mRange ("")
	, mModelReference ("")
	, mSymbol ("")
	, mTarget ("")
	, mMath (NULL)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedSetValue with the given SedNamespaces object.
 */
SedSetValue::SedSetValue (SedNamespaces* sedns)
	: SedBase(sedns)
	, mVariables (sedns)
	, mParameters (sedns)
	, mRange ("")
	, mModelReference ("")
	, mSymbol ("")
	, mTarget ("")
	, mMath (NULL)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedSetValue.
 */
SedSetValue::SedSetValue (const SedSetValue& orig)
	: SedBase(orig)
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
		mModelReference  = orig.mModelReference;
		mSymbol  = orig.mSymbol;
		mTarget  = orig.mTarget;
		mMath  = orig.mMath != NULL ? orig.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedSetValue.
 */
SedSetValue&
SedSetValue::operator=(const SedSetValue& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mVariables  = rhs.mVariables;
		mParameters  = rhs.mParameters;
		mRange  = rhs.mRange;
		mModelReference  = rhs.mModelReference;
		mSymbol  = rhs.mSymbol;
		mTarget  = rhs.mTarget;
		mMath  = rhs.mMath != NULL ? rhs.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedSetValue.
 */
SedSetValue*
SedSetValue::clone () const
{
	return new SedSetValue(*this);
}


/*
 * Destructor for SedSetValue.
 */
SedSetValue::~SedSetValue ()
{
}


/*
 * Returns the value of the "range" attribute of this SedSetValue.
 */
const std::string&
SedSetValue::getRange() const
{
	return mRange;
}


/*
 * Returns the value of the "modelReference" attribute of this SedSetValue.
 */
const std::string&
SedSetValue::getModelReference() const
{
	return mModelReference;
}


/*
 * Returns the value of the "symbol" attribute of this SedSetValue.
 */
const std::string&
SedSetValue::getSymbol() const
{
	return mSymbol;
}


/*
 * Returns the value of the "target" attribute of this SedSetValue.
 */
const std::string&
SedSetValue::getTarget() const
{
	return mTarget;
}


/*
 * Returns the value of the "math" attribute of this SedSetValue.
 */
const ASTNode*
SedSetValue::getMath() const
{
	return mMath;
}


/*
 * Returns true/false if range is set.
 */
bool
SedSetValue::isSetRange() const
{
	return (mRange.empty() == false);
}


/*
 * Returns true/false if modelReference is set.
 */
bool
SedSetValue::isSetModelReference() const
{
	return (mModelReference.empty() == false);
}


/*
 * Returns true/false if symbol is set.
 */
bool
SedSetValue::isSetSymbol() const
{
	return (mSymbol.empty() == false);
}


/*
 * Returns true/false if target is set.
 */
bool
SedSetValue::isSetTarget() const
{
	return (mTarget.empty() == false);
}


/*
 * Returns true/false if math is set.
 */
bool
SedSetValue::isSetMath() const
{
	return (mMath != NULL);
}


/*
 * Sets range and returns value indicating success.
 */
int
SedSetValue::setRange(const std::string& range)
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
 * Sets modelReference and returns value indicating success.
 */
int
SedSetValue::setModelReference(const std::string& modelReference)
{
	if (&(modelReference) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(modelReference)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mModelReference = modelReference;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets symbol and returns value indicating success.
 */
int
SedSetValue::setSymbol(const std::string& symbol)
{
	if (&(symbol) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mSymbol = symbol;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets target and returns value indicating success.
 */
int
SedSetValue::setTarget(const std::string& target)
{
	if (&(target) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mTarget = target;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets math and returns value indicating success.
 */
int
SedSetValue::setMath(ASTNode* math)
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
SedSetValue::unsetRange()
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
 * Unsets modelReference and returns value indicating success.
 */
int
SedSetValue::unsetModelReference()
{
	mModelReference.erase();

	if (mModelReference.empty() == true)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets symbol and returns value indicating success.
 */
int
SedSetValue::unsetSymbol()
{
	mSymbol.erase();

	if (mSymbol.empty() == true)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets target and returns value indicating success.
 */
int
SedSetValue::unsetTarget()
{
	mTarget.erase();

	if (mTarget.empty() == true)
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
SedSetValue::unsetMath()
{
	delete mMath;
	mMath = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfVariables" in this SedSetValue object.
 */
const SedListOfVariables*
SedSetValue::getListOfVariables() const
{
	return &mVariables;
}


/*
 * Removes the nth Variable from the SedListOfVariables.
 */
SedVariable*
SedSetValue::removeVariable(unsigned int n)
{
	return mVariables.remove(n);
}


/*
 * Removes the a Variable with given id from the SedListOfVariables.
 */
SedVariable*
SedSetValue::removeVariable(const std::string& sid)
{
	return mVariables.remove(sid);
}


/*
 * Return the nth Variable in the SedListOfVariables within this SedSetValue.
 */
SedVariable*
SedSetValue::getVariable(unsigned int n)
{
	return mVariables.get(n);
}


/*
 * Return the nth Variable in the SedListOfVariables within this SedSetValue.
 */
const SedVariable*
SedSetValue::getVariable(unsigned int n) const
{
	return mVariables.get(n);
}


/*
 * Return a Variable from the SedListOfVariables by id.
 */
SedVariable*
SedSetValue::getVariable(const std::string& sid)
{
	return mVariables.get(sid);
}


/*
 * Return a Variable from the SedListOfVariables by id.
 */
const SedVariable*
SedSetValue::getVariable(const std::string& sid) const
{
	return mVariables.get(sid);
}


/**
 * Adds a copy the given "SedVariable" to this SedSetValue.
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
SedSetValue::addVariable(const SedVariable* sv)
{
	if(sv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mVariables.append(sv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedVariable objects in this SedSetValue.
 *
 * @return the number of SedVariable objects in this SedSetValue
 */
unsigned int 
SedSetValue::getNumVariables() const
{
	return mVariables.size();
}

/**
 * Creates a new SedVariable object, adds it to this SedSetValues
 * SedSetValue and returns the SedVariable object created. 
 *
 * @return a new SedVariable object instance
 *
 * @see addSedVariable(const SedVariable* sv)
 */
SedVariable* 
SedSetValue::createVariable()
{
	SedVariable *temp = new SedVariable();
	if (temp != NULL) mVariables.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfParameters" in this SedSetValue object.
 */
const SedListOfParameters*
SedSetValue::getListOfParameters() const
{
	return &mParameters;
}


/*
 * Removes the nth Parameter from the SedListOfParameters.
 */
SedParameter*
SedSetValue::removeParameter(unsigned int n)
{
	return mParameters.remove(n);
}


/*
 * Removes the a Parameter with given id from the SedListOfParameters.
 */
SedParameter*
SedSetValue::removeParameter(const std::string& sid)
{
	return mParameters.remove(sid);
}


/*
 * Return the nth Parameter in the SedListOfParameters within this SedSetValue.
 */
SedParameter*
SedSetValue::getParameter(unsigned int n)
{
	return mParameters.get(n);
}


/*
 * Return the nth Parameter in the SedListOfParameters within this SedSetValue.
 */
const SedParameter*
SedSetValue::getParameter(unsigned int n) const
{
	return mParameters.get(n);
}


/*
 * Return a Parameter from the SedListOfParameters by id.
 */
SedParameter*
SedSetValue::getParameter(const std::string& sid)
{
	return mParameters.get(sid);
}


/*
 * Return a Parameter from the SedListOfParameters by id.
 */
const SedParameter*
SedSetValue::getParameter(const std::string& sid) const
{
	return mParameters.get(sid);
}


/**
 * Adds a copy the given "SedParameter" to this SedSetValue.
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
SedSetValue::addParameter(const SedParameter* sp)
{
	if(sp == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mParameters.append(sp);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedParameter objects in this SedSetValue.
 *
 * @return the number of SedParameter objects in this SedSetValue
 */
unsigned int 
SedSetValue::getNumParameters() const
{
	return mParameters.size();
}

/**
 * Creates a new SedParameter object, adds it to this SedSetValues
 * SedSetValue and returns the SedParameter object created. 
 *
 * @return a new SedParameter object instance
 *
 * @see addSedParameter(const SedParameter* sp)
 */
SedParameter* 
SedSetValue::createParameter()
{
	SedParameter *temp = new SedParameter();
	if (temp != NULL) mParameters.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedSetValue::getElementName () const
{
	static const string name = "setValue";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedSetValue::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

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
SedSetValue::connectToChild ()
{
	SedBase::connectToChild();

	mVariables.connectToParent(this);
	mParameters.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedSetValue::getTypeCode () const
{
	return SEDML_TASK_SETVALUE;
}


/*
 * check if all the required attributes are set
 */
bool
SedSetValue::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetModelReference() == false)
		allPresent = false;

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedSetValue::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedSetValue::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
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
SedSetValue::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedSetValue::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
	mVariables.setSedDocument(d);
	mParameters.setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedSetValue::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("range");
	attributes.add("modelReference");
	attributes.add("symbol");
	attributes.add("target");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedSetValue::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// range SIdRef   ( use = "optional" )
	//
	assigned = attributes.readInto("range", mRange, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mRange.empty() == true)
		{
			logEmptyString(mRange, getLevel(), getVersion(), "<SedSetValue>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mRange) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

	//
	// modelReference SIdRef   ( use = "required" )
	//
	assigned = attributes.readInto("modelReference", mModelReference, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mModelReference.empty() == true)
		{
			logEmptyString(mModelReference, getLevel(), getVersion(), "<SedSetValue>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

	//
	// symbol string   ( use = "optional" )
	//
	assigned = attributes.readInto("symbol", mSymbol, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty

		if (mSymbol.empty() == true)
		{
			logEmptyString(mSymbol, getLevel(), getVersion(), "<SedSetValue>");
		}
	}

	//
	// target string   ( use = "optional" )
	//
	assigned = attributes.readInto("target", mTarget, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty

		if (mTarget.empty() == true)
		{
			logEmptyString(mTarget, getLevel(), getVersion(), "<SedSetValue>");
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

bool
SedSetValue::readOtherXML (XMLInputStream& stream)
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

	if (SedBase::readOtherXML(stream))
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
SedSetValue::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetRange() == true)
		stream.writeAttribute("range", getPrefix(), mRange);

	if (isSetModelReference() == true)
		stream.writeAttribute("modelReference", getPrefix(), mModelReference);

	if (isSetSymbol() == true)
		stream.writeAttribute("symbol", getPrefix(), mSymbol);

	if (isSetTarget() == true)
		stream.writeAttribute("target", getPrefix(), mTarget);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor 
 */
SedListOfTaskChanges::SedListOfTaskChanges(unsigned int level, 
	                     unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfTaskChanges::SedListOfTaskChanges(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfTaskChanges 
 */
SedListOfTaskChanges* 
SedListOfTaskChanges::clone () const
 {
	return new SedListOfTaskChanges(*this);
}


/*
 * Get a SetValue from the SedListOfTaskChanges by index.
*/
SedSetValue*
SedListOfTaskChanges::get(unsigned int n)
{
	return static_cast<SedSetValue*>(SedListOf::get(n));
}


/*
 * Get a SetValue from the SedListOfTaskChanges by index.
 */
const SedSetValue*
SedListOfTaskChanges::get(unsigned int n) const
{
	return static_cast<const SedSetValue*>(SedListOf::get(n));
}


/*
 * Get a SetValue from the SedListOfTaskChanges by id.
 */
SedSetValue*
SedListOfTaskChanges::get(const std::string& sid)
{
	return const_cast<SedSetValue*>(
	  static_cast<const SedListOfTaskChanges&>(*this).get(sid));
}


/*
 * Get a SetValue from the SedListOfTaskChanges by id.
 */
const SedSetValue*
SedListOfTaskChanges::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedSetValue>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedSetValue*> (*result);
}


/**
 * Adds a copy the given "SedSetValue" to this SedListOfTaskChanges.
 *
 * @param ssv; the SedSetValue object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfTaskChanges::addSetValue(const SedSetValue* ssv)
{
	if(ssv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(ssv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSetValue objects in this SedListOfTaskChanges.
 *
 * @return the number of SedSetValue objects in this SedListOfTaskChanges
 */
unsigned int 
SedListOfTaskChanges::getNumSetValues() const
{
	return size();
}

/**
 * Creates a new SedSetValue object, adds it to this SedListOfTaskChangess
 * SedSetValue and returns the SedSetValue object created. 
 *
 * @return a new SedSetValue object instance
 *
 * @see addSedSetValue(const SedSetValue* ssv)
 */
SedSetValue* 
SedListOfTaskChanges::createSetValue()
{
	SedSetValue *temp = new SedSetValue();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth SetValue from this SedListOfTaskChanges
 */
SedSetValue*
SedListOfTaskChanges::remove(unsigned int n)
{
	return static_cast<SedSetValue*>(SedListOf::remove(n));
}


/*
 * Removes the SetValue from this SedListOfTaskChanges with the given identifier
 */
SedSetValue*
SedListOfTaskChanges::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedSetValue>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedSetValue*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfTaskChanges::getElementName () const
{
	static const string name = "listOfChanges";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfTaskChanges::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfTaskChanges::getItemTypeCode () const
{
	return SEDML_TASK_SETVALUE;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedSetValue in this SedListOfTaskChanges
 */
SedBase*
SedListOfTaskChanges::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "setValue")
	{
		object = new SedSetValue(getSedNamespaces());
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
SedListOfTaskChanges::writeXMLNS(XMLOutputStream& stream) const
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
SedSetValue_t *
SedSetValue_create(unsigned int level, unsigned int version)
{
	return new SedSetValue(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedSetValue_free(SedSetValue_t * ssv)
{
	if (ssv != NULL)
		delete ssv;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSetValue_t *
SedSetValue_clone(SedSetValue_t * ssv)
{
	if (ssv != NULL)
	{
		return static_cast<SedSetValue_t*>(ssv->clone());
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
SedSetValue_getRange(SedSetValue_t * ssv)
{
	if (ssv == NULL)
		return NULL;

	return ssv->getRange().empty() ? NULL : safe_strdup(ssv->getRange().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedSetValue_getModelReference(SedSetValue_t * ssv)
{
	if (ssv == NULL)
		return NULL;

	return ssv->getModelReference().empty() ? NULL : safe_strdup(ssv->getModelReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedSetValue_getSymbol(SedSetValue_t * ssv)
{
	if (ssv == NULL)
		return NULL;

	return ssv->getSymbol().empty() ? NULL : safe_strdup(ssv->getSymbol().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedSetValue_getTarget(SedSetValue_t * ssv)
{
	if (ssv == NULL)
		return NULL;

	return ssv->getTarget().empty() ? NULL : safe_strdup(ssv->getTarget().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
ASTNode_t*
SedSetValue_getMath(SedSetValue_t * ssv)
{
	if (ssv == NULL)
		return NULL;

	return (ASTNode_t*)ssv->getMath();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetRange(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? static_cast<int>(ssv->isSetRange()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetModelReference(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? static_cast<int>(ssv->isSetModelReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetSymbol(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? static_cast<int>(ssv->isSetSymbol()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetTarget(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? static_cast<int>(ssv->isSetTarget()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_isSetMath(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? static_cast<int>(ssv->isSetMath()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_setRange(SedSetValue_t * ssv, const char * range)
{
	return (ssv != NULL) ? ssv->setRange(range) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_setModelReference(SedSetValue_t * ssv, const char * modelReference)
{
	return (ssv != NULL) ? ssv->setModelReference(modelReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_setSymbol(SedSetValue_t * ssv, const char * symbol)
{
	return (ssv != NULL) ? ssv->setSymbol(symbol) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_setTarget(SedSetValue_t * ssv, const char * target)
{
	return (ssv != NULL) ? ssv->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_setMath(SedSetValue_t * ssv, ASTNode_t* math)
{
	return (ssv != NULL) ? ssv->setMath(math) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetRange(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? ssv->unsetRange() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetModelReference(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? ssv->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetSymbol(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? ssv->unsetSymbol() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetTarget(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? ssv->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_unsetMath(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? ssv->unsetMath() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedSetValue_addVariable(SedSetValue_t * ssv, SedVariable_t * sv)
{
	return  (ssv != NULL) ? ssv->addVariable(sv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedVariable_t *
SedSetValue_createVariable(SedSetValue_t * ssv)
{
	return  (ssv != NULL) ? ssv->createVariable() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedSetValue_getSedListOfVariables(SedSetValue_t * ssv)
{
	return  (ssv != NULL) ? (SedListOf_t *)ssv->getListOfVariables() : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedSetValue_getVariable(SedSetValue_t * ssv, unsigned int n)
{
	return  (ssv != NULL) ? ssv->getVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedSetValue_getVariableById(SedSetValue_t * ssv, const char * sid)
{
	return  (ssv != NULL) ? ssv->getVariable(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedSetValue_getNumVariables(SedSetValue_t * ssv)
{
	return  (ssv != NULL) ? ssv->getNumVariables() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedVariable_t *
SedSetValue_removeVariable(SedSetValue_t * ssv, unsigned int n)
{
	return  (ssv != NULL) ? ssv->removeVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedSetValue_removeVariableById(SedSetValue_t * ssv, const char * sid)
{
	return  (ssv != NULL) ? ssv->removeVariable(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedSetValue_addParameter(SedSetValue_t * ssv, SedParameter_t * sp)
{
	return  (ssv != NULL) ? ssv->addParameter(sp) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedParameter_t *
SedSetValue_createParameter(SedSetValue_t * ssv)
{
	return  (ssv != NULL) ? ssv->createParameter() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedSetValue_getSedListOfParameters(SedSetValue_t * ssv)
{
	return  (ssv != NULL) ? (SedListOf_t *)ssv->getListOfParameters() : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedSetValue_getParameter(SedSetValue_t * ssv, unsigned int n)
{
	return  (ssv != NULL) ? ssv->getParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedSetValue_getParameterById(SedSetValue_t * ssv, const char * sid)
{
	return  (ssv != NULL) ? ssv->getParameter(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedSetValue_getNumParameters(SedSetValue_t * ssv)
{
	return  (ssv != NULL) ? ssv->getNumParameters() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedParameter_t *
SedSetValue_removeParameter(SedSetValue_t * ssv, unsigned int n)
{
	return  (ssv != NULL) ? ssv->removeParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedSetValue_removeParameterById(SedSetValue_t * ssv, const char * sid)
{
	return  (ssv != NULL) ? ssv->removeParameter(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_hasRequiredAttributes(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? static_cast<int>(ssv->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSetValue_hasRequiredElements(SedSetValue_t * ssv)
{
	return (ssv != NULL) ? static_cast<int>(ssv->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSetValue_t *
SedListOfTaskChanges_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfTaskChanges *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSetValue_t *
SedListOfTaskChanges_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfTaskChanges *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


