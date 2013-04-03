/**
 * @file:   DataGenerator.cpp
 * @brief:  Implementation of the DataGenerator class
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


#include <sedml/DataGenerator.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new DataGenerator with the given level, version, and package version.
 */
DataGenerator::DataGenerator (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
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
 * Creates a new DataGenerator with the given SedMLNamespaces object.
 */
DataGenerator::DataGenerator (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mName ("")
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
 * Copy constructor for DataGenerator.
 */
DataGenerator::DataGenerator (const DataGenerator& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mId  = orig.mId;
		mName  = orig.mName;
		mVariable  = orig.mVariable;
		mParameter  = orig.mParameter;
		mMath  = orig.mMath != NULL ? orig.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for DataGenerator.
 */
DataGenerator&
DataGenerator::operator=(const DataGenerator& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mId  = rhs.mId;
		mName  = rhs.mName;
		mVariable  = rhs.mVariable;
		mParameter  = rhs.mParameter;
		mMath  = rhs.mMath != NULL ? rhs.mMath->deepCopy() : NULL;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for DataGenerator.
 */
DataGenerator*
DataGenerator::clone () const
{
	return new DataGenerator(*this);
}


/*
 * Destructor for DataGenerator.
 */
DataGenerator::~DataGenerator ()
{
}


/*
 * Returns the value of the "id" attribute of this DataGenerator.
 */
const std::string&
DataGenerator::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this DataGenerator.
 */
const std::string&
DataGenerator::getName() const
{
	return mName;
}


/*
 * Returns the value of the "math" attribute of this DataGenerator.
 */
const ASTNode*
DataGenerator::getMath() const
{
	return mMath;
}


/*
 * Returns true/false if id is set.
 */
bool
DataGenerator::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
DataGenerator::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if math is set.
 */
bool
DataGenerator::isSetMath() const
{
	return (mMath != NULL);
}


/*
 * Sets id and returns value indicating success.
 */
int
DataGenerator::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
DataGenerator::setName(const std::string& name)
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
DataGenerator::setMath(ASTNode* math)
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
DataGenerator::unsetId()
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
DataGenerator::unsetName()
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
DataGenerator::unsetMath()
{
	delete mMath;
	mMath = NULL;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfSedMLVariables" in this DataGenerator object.
 */
const SedListOfSedMLVariables*
DataGenerator::getListOfSedMLVariables() const
{
	return &mVariable;
}


/*
 * Removes the nth SedMLVariable from the SedListOfSedMLVariables.
 */
SedMLVariable*
DataGenerator::removeSedMLVariable(unsigned int n)
{
	return mVariable.remove(n);
}


/*
 * Removes the a SedMLVariable with given id from the SedListOfSedMLVariables.
 */
SedMLVariable*
DataGenerator::removeSedMLVariable(const std::string& sid)
{
	return mVariable.remove(sid);
}


/*
 * Return the nth SedMLVariable in the SedListOfSedMLVariables within this DataGenerator.
 */
SedMLVariable*
DataGenerator::getSedMLVariable(unsigned int n)
{
	return mVariable.get(n);
}


/*
 * Return the nth SedMLVariable in the SedListOfSedMLVariables within this DataGenerator.
 */
const SedMLVariable*
DataGenerator::getSedMLVariable(unsigned int n) const
{
	return mVariable.get(n);
}


/*
 * Return a SedMLVariable from the SedListOfSedMLVariables by id.
 */
SedMLVariable*
DataGenerator::getSedMLVariable(const std::string& sid)
{
	return mVariable.get(sid);
}


/*
 * Return a SedMLVariable from the SedListOfSedMLVariables by id.
 */
const SedMLVariable*
DataGenerator::getSedMLVariable(const std::string& sid) const
{
	return mVariable.get(sid);
}


/**
 * Adds a copy the given "SedMLVariable" to this DataGenerator.
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
DataGenerator::addSedMLVariable(const SedMLVariable* smlv)
{
	if(smlv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mVariable.append(smlv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedMLVariable objects in this DataGenerator.
 *
 * @return the number of SedMLVariable objects in this DataGenerator
 */
unsigned int 
DataGenerator::getNumSedMLVariables() const
{
	return mVariable.size();
}

/**
 * Creates a new SedMLVariable object, adds it to this DataGenerators
 * DataGenerator and returns the SedMLVariable object created. 
 *
 * @return a new SedMLVariable object instance
 *
 * @see addSedMLVariable(const SedMLVariable* smlv)
 */
SedMLVariable* 
DataGenerator::createSedMLVariable()
{
	SedMLVariable *temp = new SedMLVariable();
	if (temp != NULL) mVariable.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSedMLParameters" in this DataGenerator object.
 */
const SedListOfSedMLParameters*
DataGenerator::getListOfSedMLParameters() const
{
	return &mParameter;
}


/*
 * Removes the nth SedMLParameter from the SedListOfSedMLParameters.
 */
SedMLParameter*
DataGenerator::removeSedMLParameter(unsigned int n)
{
	return mParameter.remove(n);
}


/*
 * Removes the a SedMLParameter with given id from the SedListOfSedMLParameters.
 */
SedMLParameter*
DataGenerator::removeSedMLParameter(const std::string& sid)
{
	return mParameter.remove(sid);
}


/*
 * Return the nth SedMLParameter in the SedListOfSedMLParameters within this DataGenerator.
 */
SedMLParameter*
DataGenerator::getSedMLParameter(unsigned int n)
{
	return mParameter.get(n);
}


/*
 * Return the nth SedMLParameter in the SedListOfSedMLParameters within this DataGenerator.
 */
const SedMLParameter*
DataGenerator::getSedMLParameter(unsigned int n) const
{
	return mParameter.get(n);
}


/*
 * Return a SedMLParameter from the SedListOfSedMLParameters by id.
 */
SedMLParameter*
DataGenerator::getSedMLParameter(const std::string& sid)
{
	return mParameter.get(sid);
}


/*
 * Return a SedMLParameter from the SedListOfSedMLParameters by id.
 */
const SedMLParameter*
DataGenerator::getSedMLParameter(const std::string& sid) const
{
	return mParameter.get(sid);
}


/**
 * Adds a copy the given "SedMLParameter" to this DataGenerator.
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
DataGenerator::addSedMLParameter(const SedMLParameter* smlp)
{
	if(smlp == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mParameter.append(smlp);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedMLParameter objects in this DataGenerator.
 *
 * @return the number of SedMLParameter objects in this DataGenerator
 */
unsigned int 
DataGenerator::getNumSedMLParameters() const
{
	return mParameter.size();
}

/**
 * Creates a new SedMLParameter object, adds it to this DataGenerators
 * DataGenerator and returns the SedMLParameter object created. 
 *
 * @return a new SedMLParameter object instance
 *
 * @see addSedMLParameter(const SedMLParameter* smlp)
 */
SedMLParameter* 
DataGenerator::createSedMLParameter()
{
	SedMLParameter *temp = new SedMLParameter();
	if (temp != NULL) mParameter.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
DataGenerator::getElementName () const
{
	static const string name = "dataGenerator";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
DataGenerator::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	SedBase::connectToChild();

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
DataGenerator::connectToChild ()
{
	SedBase::connectToChild();

	mVariable.connectToParent(this);
	mParameter.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
DataGenerator::getTypeCode () const
{
	return SEDML_DATAGENERATOR;
}


/*
 * check if all the required attributes are set
 */
bool
DataGenerator::hasRequiredAttributes () const
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
DataGenerator::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
DataGenerator::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
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
DataGenerator::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
DataGenerator::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
DataGenerator::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
DataGenerator::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<DataGenerator>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mId) == false)
		{
			logError(InvalidIdSyntax);
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
			logEmptyString(mName, getLevel(), getVersion(), "<DataGenerator>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

bool
DataGenerator::readOtherXML (XMLInputStream& stream)
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


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
DataGenerator::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfDataGenerators::SedListOfDataGenerators(unsigned int level, 
	                        unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfDataGenerators::SedListOfDataGenerators(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
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
DataGenerator*
SedListOfDataGenerators::get(unsigned int n)
{
	return static_cast<DataGenerator*>(SedListOf::get(n));
}


/*
 * Get a DataGenerator from the SedListOfDataGenerators by index.
 */
const DataGenerator*
SedListOfDataGenerators::get(unsigned int n) const
{
	return static_cast<const DataGenerator*>(SedListOf::get(n));
}


/*
 * Get a DataGenerator from the SedListOfDataGenerators by id.
 */
DataGenerator*
SedListOfDataGenerators::get(const std::string& sid)
{
	return const_cast<DataGenerator*>(
	  static_cast<const SedListOfDataGenerators&>(*this).get(sid));
}


/*
 * Get a DataGenerator from the SedListOfDataGenerators by id.
 */
const DataGenerator*
SedListOfDataGenerators::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<DataGenerator>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <DataGenerator*> (*result);
}


/*
 * Removes the nth DataGenerator from this SedListOfDataGenerators
 */
DataGenerator*
SedListOfDataGenerators::remove(unsigned int n)
{
	return static_cast<DataGenerator*>(SedListOf::remove(n));
}


/*
 * Removes the DataGenerator from this SedListOfDataGenerators with the given identifier
 */
DataGenerator*
SedListOfDataGenerators::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<DataGenerator>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <DataGenerator*> (item);
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


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new DataGenerator in this SedListOfDataGenerators
 */
SedBase*
SedListOfDataGenerators::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "dataGenerator")
	{
		object = new DataGenerator(getSedMLNamespaces());
		appendAndOwn(object);
	}

	return object;
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write the namespace for the SedML package.
 */
void
SedListOfDataGenerators::writeXMLNS(XMLOutputStream& stream) const
{
	XMLNamespaces xmlns;

	std::string prefix = getPrefix();

	if (prefix.empty())
	{
		if (getNamespaces() != NULL && !getNamespaces()->hasURI(SEDML_XMLNS_L1))
		{
			xmlns.add(SEDML_XMLNS_L1,prefix);
		}
	}

	stream << xmlns;
}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
DataGenerator_t *
DataGenerator_create(unsigned int level, unsigned int version)
{
	return new DataGenerator(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
DataGenerator_free(DataGenerator_t * dg)
{
	if (dg != NULL)
		delete dg;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
DataGenerator_t *
DataGenerator_clone(DataGenerator_t * dg)
{
	if (dg != NULL)
	{
		return static_cast<DataGenerator_t*>(dg->clone());
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
DataGenerator_getId(DataGenerator_t * dg)
{
	if (dg == NULL)
		return NULL;

	return dg->getId().empty() ? NULL : safe_strdup(dg->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
DataGenerator_getName(DataGenerator_t * dg)
{
	if (dg == NULL)
		return NULL;

	return dg->getName().empty() ? NULL : safe_strdup(dg->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataGenerator_isSetId(DataGenerator_t * dg)
{
	return (dg != NULL) ? static_cast<int>(dg->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataGenerator_isSetName(DataGenerator_t * dg)
{
	return (dg != NULL) ? static_cast<int>(dg->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataGenerator_setId(DataGenerator_t * dg, const char * id)
{
	return (dg != NULL) ? dg->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataGenerator_setName(DataGenerator_t * dg, const char * name)
{
	return (dg != NULL) ? dg->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataGenerator_unsetId(DataGenerator_t * dg)
{
	return (dg != NULL) ? dg->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataGenerator_unsetName(DataGenerator_t * dg)
{
	return (dg != NULL) ? dg->unsetName() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
DataGenerator_addSedMLVariable(DataGenerator_t * dg, SedMLVariable_t * smlv)
{
	return  (dg != NULL) ? dg->addSedMLVariable(smlv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedMLVariable_t *
DataGenerator_createSedMLVariable(DataGenerator_t * dg)
{
	return  (dg != NULL) ? dg->createSedMLVariable() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
DataGenerator_getSedListOfSedMLVariables(DataGenerator_t * dg)
{
	return  (dg != NULL) ? (SedListOf_t *)dg->getListOfSedMLVariables() : NULL;
}

LIBSEDML_EXTERN
SedMLVariable_t *
DataGenerator_getSedMLVariable(DataGenerator_t * dg, unsigned int n)
{
	return  (dg != NULL) ? dg->getSedMLVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedMLVariable_t *
DataGenerator_getSedMLVariableById(DataGenerator_t * dg, const char * sid)
{
	return  (dg != NULL) ? dg->getSedMLVariable(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
DataGenerator_getNumSedMLVariables(DataGenerator_t * dg)
{
	return  (dg != NULL) ? dg->getNumSedMLVariables() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedMLVariable_t *
DataGenerator_removeSedMLVariable(DataGenerator_t * dg, unsigned int n)
{
	return  (dg != NULL) ? dg->removeSedMLVariable(n) : NULL;
}

LIBSEDML_EXTERN
SedMLVariable_t *
DataGenerator_removeSedMLVariableById(DataGenerator_t * dg, const char * sid)
{
	return  (dg != NULL) ? dg->removeSedMLVariable(sid) : NULL;
}

LIBSEDML_EXTERN
int
DataGenerator_addSedMLParameter(DataGenerator_t * dg, SedMLParameter_t * smlp)
{
	return  (dg != NULL) ? dg->addSedMLParameter(smlp) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedMLParameter_t *
DataGenerator_createSedMLParameter(DataGenerator_t * dg)
{
	return  (dg != NULL) ? dg->createSedMLParameter() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
DataGenerator_getSedListOfSedMLParameters(DataGenerator_t * dg)
{
	return  (dg != NULL) ? (SedListOf_t *)dg->getListOfSedMLParameters() : NULL;
}

LIBSEDML_EXTERN
SedMLParameter_t *
DataGenerator_getSedMLParameter(DataGenerator_t * dg, unsigned int n)
{
	return  (dg != NULL) ? dg->getSedMLParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedMLParameter_t *
DataGenerator_getSedMLParameterById(DataGenerator_t * dg, const char * sid)
{
	return  (dg != NULL) ? dg->getSedMLParameter(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
DataGenerator_getNumSedMLParameters(DataGenerator_t * dg)
{
	return  (dg != NULL) ? dg->getNumSedMLParameters() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedMLParameter_t *
DataGenerator_removeSedMLParameter(DataGenerator_t * dg, unsigned int n)
{
	return  (dg != NULL) ? dg->removeSedMLParameter(n) : NULL;
}

LIBSEDML_EXTERN
SedMLParameter_t *
DataGenerator_removeSedMLParameterById(DataGenerator_t * dg, const char * sid)
{
	return  (dg != NULL) ? dg->removeSedMLParameter(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataGenerator_hasRequiredAttributes(DataGenerator_t * dg)
{
	return (dg != NULL) ? static_cast<int>(dg->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataGenerator_hasRequiredElements(DataGenerator_t * dg)
{
	return (dg != NULL) ? static_cast<int>(dg->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
DataGenerator_t *
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
DataGenerator_t *
SedListOfDataGenerators_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfDataGenerators *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


