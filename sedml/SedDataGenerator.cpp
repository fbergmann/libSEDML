/**
 * @file:   SedDataGenerator.cpp
 * @brief:  Implementation of the SedDataGenerator class
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


#include <sedml/SedDataGenerator.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedDataGenerator with the given level, version, and package version.
 */
SedDataGenerator::SedDataGenerator (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
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
 * Creates a new SedDataGenerator with the given SedNamespaces object.
 */
SedDataGenerator::SedDataGenerator (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")
	, mName ("")
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
 * Copy constructor for SedDataGenerator.
 */
SedDataGenerator::SedDataGenerator (const SedDataGenerator& orig)
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
		mVariables  = orig.mVariables;
		mParameters  = orig.mParameters;
		mMath  = orig.mMath != NULL ? orig.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedDataGenerator.
 */
SedDataGenerator&
SedDataGenerator::operator=(const SedDataGenerator& rhs)
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
		mVariables  = rhs.mVariables;
		mParameters  = rhs.mParameters;
		mMath  = rhs.mMath != NULL ? rhs.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedDataGenerator.
 */
SedDataGenerator*
SedDataGenerator::clone () const
{
	return new SedDataGenerator(*this);
}


/*
 * Destructor for SedDataGenerator.
 */
SedDataGenerator::~SedDataGenerator ()
{
}


/*
 * Returns the value of the "id" attribute of this SedDataGenerator.
 */
const std::string&
SedDataGenerator::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedDataGenerator.
 */
const std::string&
SedDataGenerator::getName() const
{
	return mName;
}


/*
 * Returns the value of the "math" attribute of this SedDataGenerator.
 */
const ASTNode*
SedDataGenerator::getMath() const
{
	return mMath;
}


/*
 * Returns true/false if id is set.
 */
bool
SedDataGenerator::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedDataGenerator::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if math is set.
 */
bool
SedDataGenerator::isSetMath() const
{
	return (mMath != NULL);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedDataGenerator::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedDataGenerator::setName(const std::string& name)
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
 * Sets math and returns value indicating success.
 */
int
SedDataGenerator::setMath(ASTNode* math)
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
 * Unsets id and returns value indicating success.
 */
int
SedDataGenerator::unsetId()
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
SedDataGenerator::unsetName()
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
 * Unsets math and returns value indicating success.
 */
int
SedDataGenerator::unsetMath()
{
	delete mMath;
	mMath = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfVariables" in this SedDataGenerator object.
 */
const SedListOfVariables*
SedDataGenerator::getListOfVariables() const
{
	return &mVariables;
}


/*
 * Removes the nth Variable from the SedListOfVariables.
 */
SedVariable*
SedDataGenerator::removeVariable(unsigned int n)
{
	return mVariables.remove(n);
}


/*
 * Removes the a Variable with given id from the SedListOfVariables.
 */
SedVariable*
SedDataGenerator::removeVariable(const std::string& sid)
{
	return mVariables.remove(sid);
}


/*
 * Return the nth Variable in the SedListOfVariables within this SedDataGenerator.
 */
SedVariable*
SedDataGenerator::getVariable(unsigned int n)
{
	return mVariables.get(n);
}


/*
 * Return the nth Variable in the SedListOfVariables within this SedDataGenerator.
 */
const SedVariable*
SedDataGenerator::getVariable(unsigned int n) const
{
	return mVariables.get(n);
}


/*
 * Return a Variable from the SedListOfVariables by id.
 */
SedVariable*
SedDataGenerator::getVariable(const std::string& sid)
{
	return mVariables.get(sid);
}


/*
 * Return a Variable from the SedListOfVariables by id.
 */
const SedVariable*
SedDataGenerator::getVariable(const std::string& sid) const
{
	return mVariables.get(sid);
}


/**
 * Adds a copy the given "SedVariable" to this SedDataGenerator.
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
SedDataGenerator::addVariable(const SedVariable* sv)
{
	if(sv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mVariables.append(sv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedVariable objects in this SedDataGenerator.
 *
 * @return the number of SedVariable objects in this SedDataGenerator
 */
unsigned int 
SedDataGenerator::getNumVariables() const
{
	return mVariables.size();
}

/**
 * Creates a new SedVariable object, adds it to this SedDataGenerators
 * SedDataGenerator and returns the SedVariable object created. 
 *
 * @return a new SedVariable object instance
 *
 * @see addSedVariable(const SedVariable* sv)
 */
SedVariable* 
SedDataGenerator::createVariable()
{
	SedVariable *temp = new SedVariable();
	if (temp != NULL) mVariables.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfParameters" in this SedDataGenerator object.
 */
const SedListOfParameters*
SedDataGenerator::getListOfParameters() const
{
	return &mParameters;
}


/*
 * Removes the nth Parameter from the SedListOfParameters.
 */
SedParameter*
SedDataGenerator::removeParameter(unsigned int n)
{
	return mParameters.remove(n);
}


/*
 * Removes the a Parameter with given id from the SedListOfParameters.
 */
SedParameter*
SedDataGenerator::removeParameter(const std::string& sid)
{
	return mParameters.remove(sid);
}


/*
 * Return the nth Parameter in the SedListOfParameters within this SedDataGenerator.
 */
SedParameter*
SedDataGenerator::getParameter(unsigned int n)
{
	return mParameters.get(n);
}


/*
 * Return the nth Parameter in the SedListOfParameters within this SedDataGenerator.
 */
const SedParameter*
SedDataGenerator::getParameter(unsigned int n) const
{
	return mParameters.get(n);
}


/*
 * Return a Parameter from the SedListOfParameters by id.
 */
SedParameter*
SedDataGenerator::getParameter(const std::string& sid)
{
	return mParameters.get(sid);
}


/*
 * Return a Parameter from the SedListOfParameters by id.
 */
const SedParameter*
SedDataGenerator::getParameter(const std::string& sid) const
{
	return mParameters.get(sid);
}


/**
 * Adds a copy the given "SedParameter" to this SedDataGenerator.
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
SedDataGenerator::addParameter(const SedParameter* sp)
{
	if(sp == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mParameters.append(sp);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedParameter objects in this SedDataGenerator.
 *
 * @return the number of SedParameter objects in this SedDataGenerator
 */
unsigned int 
SedDataGenerator::getNumParameters() const
{
	return mParameters.size();
}

/**
 * Creates a new SedParameter object, adds it to this SedDataGenerators
 * SedDataGenerator and returns the SedParameter object created. 
 *
 * @return a new SedParameter object instance
 *
 * @see addSedParameter(const SedParameter* sp)
 */
SedParameter* 
SedDataGenerator::createParameter()
{
	SedParameter *temp = new SedParameter();
	if (temp != NULL) mParameters.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedDataGenerator::getElementName () const
{
	static const string name = "dataGenerator";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedDataGenerator::createObject(XMLInputStream& stream)
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
SedDataGenerator::connectToChild ()
{
	SedBase::connectToChild();

	mVariables.connectToParent(this);
	mParameters.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedDataGenerator::getTypeCode () const
{
	return SEDML_DATAGENERATOR;
}


/*
 * check if all the required attributes are set
 */
bool
SedDataGenerator::hasRequiredAttributes () const
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
SedDataGenerator::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedDataGenerator::writeElements (XMLOutputStream& stream) const
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
SedDataGenerator::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedDataGenerator::setSedDocument (SedDocument* d)
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
SedDataGenerator::addExpectedAttributes(ExpectedAttributes& attributes)
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
SedDataGenerator::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedDataGenerator>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedDataGenerator>");
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

bool
SedDataGenerator::readOtherXML (XMLInputStream& stream)
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
SedDataGenerator::writeAttributes (XMLOutputStream& stream) const
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
SedListOfDataGenerators::SedListOfDataGenerators(unsigned int level, 
	                        unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfDataGenerators::SedListOfDataGenerators(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfDataGenerators 
 */
SedListOfDataGenerators* 
SedListOfDataGenerators::clone () const
 {
	return new SedListOfDataGenerators(*this);
}


/*
 * Get a DataGenerator from the SedListOfDataGenerators by index.
*/
SedDataGenerator*
SedListOfDataGenerators::get(unsigned int n)
{
	return static_cast<SedDataGenerator*>(SedListOf::get(n));
}


/*
 * Get a DataGenerator from the SedListOfDataGenerators by index.
 */
const SedDataGenerator*
SedListOfDataGenerators::get(unsigned int n) const
{
	return static_cast<const SedDataGenerator*>(SedListOf::get(n));
}


/*
 * Get a DataGenerator from the SedListOfDataGenerators by id.
 */
SedDataGenerator*
SedListOfDataGenerators::get(const std::string& sid)
{
	return const_cast<SedDataGenerator*>(
	  static_cast<const SedListOfDataGenerators&>(*this).get(sid));
}


/*
 * Get a DataGenerator from the SedListOfDataGenerators by id.
 */
const SedDataGenerator*
SedListOfDataGenerators::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedDataGenerator>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedDataGenerator*> (*result);
}


/**
 * Adds a copy the given "SedDataGenerator" to this SedListOfDataGenerators.
 *
 * @param sdg; the SedDataGenerator object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfDataGenerators::addDataGenerator(const SedDataGenerator* sdg)
{
	if(sdg == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sdg);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedDataGenerator objects in this SedListOfDataGenerators.
 *
 * @return the number of SedDataGenerator objects in this SedListOfDataGenerators
 */
unsigned int 
SedListOfDataGenerators::getNumDataGenerators() const
{
	return size();
}

/**
 * Creates a new SedDataGenerator object, adds it to this SedListOfDataGeneratorss
 * SedDataGenerator and returns the SedDataGenerator object created. 
 *
 * @return a new SedDataGenerator object instance
 *
 * @see addSedDataGenerator(const SedDataGenerator* sdg)
 */
SedDataGenerator* 
SedListOfDataGenerators::createDataGenerator()
{
	SedDataGenerator *temp = new SedDataGenerator();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth DataGenerator from this SedListOfDataGenerators
 */
SedDataGenerator*
SedListOfDataGenerators::remove(unsigned int n)
{
	return static_cast<SedDataGenerator*>(SedListOf::remove(n));
}


/*
 * Removes the DataGenerator from this SedListOfDataGenerators with the given identifier
 */
SedDataGenerator*
SedListOfDataGenerators::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedDataGenerator>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedDataGenerator*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfDataGenerators::getElementName () const
{
	static const string name = "listOfDataGenerators";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfDataGenerators::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfDataGenerators::getItemTypeCode () const
{
	return SEDML_DATAGENERATOR;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedDataGenerator in this SedListOfDataGenerators
 */
SedBase*
SedListOfDataGenerators::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "dataGenerator")
	{
		object = new SedDataGenerator(getSedNamespaces());
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
SedListOfDataGenerators::writeXMLNS(XMLOutputStream& stream) const
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
SedDataGenerator_t *
SedDataGenerator_create(unsigned int level, unsigned int version)
{
	return new SedDataGenerator(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedDataGenerator_free(SedDataGenerator_t * sdg)
{
	if (sdg != NULL)
		delete sdg;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataGenerator_t *
SedDataGenerator_clone(SedDataGenerator_t * sdg)
{
	if (sdg != NULL)
	{
		return static_cast<SedDataGenerator_t*>(sdg->clone());
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
SedDataGenerator_getId(SedDataGenerator_t * sdg)
{
	if (sdg == NULL)
		return NULL;

	return sdg->getId().empty() ? NULL : safe_strdup(sdg->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataGenerator_getName(SedDataGenerator_t * sdg)
{
	if (sdg == NULL)
		return NULL;

	return sdg->getName().empty() ? NULL : safe_strdup(sdg->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
ASTNode_t*
SedDataGenerator_getMath(SedDataGenerator_t * sdg)
{
	if (sdg == NULL)
		return NULL;

	return (ASTNode_t*)sdg->getMath();
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetId(SedDataGenerator_t * sdg)
{
	return (sdg != NULL) ? static_cast<int>(sdg->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetName(SedDataGenerator_t * sdg)
{
	return (sdg != NULL) ? static_cast<int>(sdg->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_isSetMath(SedDataGenerator_t * sdg)
{
	return (sdg != NULL) ? static_cast<int>(sdg->isSetMath()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setId(SedDataGenerator_t * sdg, const char * id)
{
	return (sdg != NULL) ? sdg->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setName(SedDataGenerator_t * sdg, const char * name)
{
	return (sdg != NULL) ? sdg->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_setMath(SedDataGenerator_t * sdg, ASTNode_t* math)
{
	return (sdg != NULL) ? sdg->setMath(math) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetId(SedDataGenerator_t * sdg)
{
	return (sdg != NULL) ? sdg->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetName(SedDataGenerator_t * sdg)
{
	return (sdg != NULL) ? sdg->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_unsetMath(SedDataGenerator_t * sdg)
{
	return (sdg != NULL) ? sdg->unsetMath() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedDataGenerator_addVariable(SedDataGenerator_t * sdg, SedVariable_t * sv)
{
	return  (sdg != NULL) ? sdg->addVariable(sv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedVariable_t *
SedDataGenerator_createVariable(SedDataGenerator_t * sdg)
{
	return  (sdg != NULL) ? sdg->createVariable() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDataGenerator_getSedListOfVariables(SedDataGenerator_t * sdg)
{
	return  (sdg != NULL) ? (SedListOf_t *)sdg->getListOfVariables() : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedDataGenerator_getVariable(SedDataGenerator_t * sdg, unsigned int n)
{
	return  (sdg != NULL) ? sdg->getVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedDataGenerator_getVariableById(SedDataGenerator_t * sdg, const char * sid)
{
	return  (sdg != NULL) ? sdg->getVariable(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDataGenerator_getNumVariables(SedDataGenerator_t * sdg)
{
	return  (sdg != NULL) ? sdg->getNumVariables() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedVariable_t *
SedDataGenerator_removeVariable(SedDataGenerator_t * sdg, unsigned int n)
{
	return  (sdg != NULL) ? sdg->removeVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedVariable_t *
SedDataGenerator_removeVariableById(SedDataGenerator_t * sdg, const char * sid)
{
	return  (sdg != NULL) ? sdg->removeVariable(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedDataGenerator_addParameter(SedDataGenerator_t * sdg, SedParameter_t * sp)
{
	return  (sdg != NULL) ? sdg->addParameter(sp) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedParameter_t *
SedDataGenerator_createParameter(SedDataGenerator_t * sdg)
{
	return  (sdg != NULL) ? sdg->createParameter() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDataGenerator_getSedListOfParameters(SedDataGenerator_t * sdg)
{
	return  (sdg != NULL) ? (SedListOf_t *)sdg->getListOfParameters() : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedDataGenerator_getParameter(SedDataGenerator_t * sdg, unsigned int n)
{
	return  (sdg != NULL) ? sdg->getParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedDataGenerator_getParameterById(SedDataGenerator_t * sdg, const char * sid)
{
	return  (sdg != NULL) ? sdg->getParameter(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDataGenerator_getNumParameters(SedDataGenerator_t * sdg)
{
	return  (sdg != NULL) ? sdg->getNumParameters() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedParameter_t *
SedDataGenerator_removeParameter(SedDataGenerator_t * sdg, unsigned int n)
{
	return  (sdg != NULL) ? sdg->removeParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedParameter_t *
SedDataGenerator_removeParameterById(SedDataGenerator_t * sdg, const char * sid)
{
	return  (sdg != NULL) ? sdg->removeParameter(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_hasRequiredAttributes(SedDataGenerator_t * sdg)
{
	return (sdg != NULL) ? static_cast<int>(sdg->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataGenerator_hasRequiredElements(SedDataGenerator_t * sdg)
{
	return (sdg != NULL) ? static_cast<int>(sdg->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataGenerator_t *
SedListOfDataGenerators_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfDataGenerators *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataGenerator_t *
SedListOfDataGenerators_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfDataGenerators *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


