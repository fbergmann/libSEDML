/**
 * @file:   SedVariable.cpp
 * @brief:  Implementation of the SedVariable class
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


#include <sedml/SedVariable.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedVariable with the given level, version, and package version.
 */
SedVariable::SedVariable (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mSymbol ("")
	, mTarget ("")
	, mTaskReference ("")
	, mModelReference ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedVariable with the given SedNamespaces object.
 */
SedVariable::SedVariable (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")
	, mName ("")
	, mSymbol ("")
	, mTarget ("")
	, mTaskReference ("")
	, mModelReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedVariable.
 */
SedVariable::SedVariable (const SedVariable& orig)
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
		mSymbol  = orig.mSymbol;
		mTarget  = orig.mTarget;
		mTaskReference  = orig.mTaskReference;
		mModelReference  = orig.mModelReference;
	}
}


/*
 * Assignment for SedVariable.
 */
SedVariable&
SedVariable::operator=(const SedVariable& rhs)
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
		mSymbol  = rhs.mSymbol;
		mTarget  = rhs.mTarget;
		mTaskReference  = rhs.mTaskReference;
		mModelReference  = rhs.mModelReference;
	}
	return *this;
}


/*
 * Clone for SedVariable.
 */
SedVariable*
SedVariable::clone () const
{
	return new SedVariable(*this);
}


/*
 * Destructor for SedVariable.
 */
SedVariable::~SedVariable ()
{
}


/*
 * Returns the value of the "id" attribute of this SedVariable.
 */
const std::string&
SedVariable::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedVariable.
 */
const std::string&
SedVariable::getName() const
{
	return mName;
}


/*
 * Returns the value of the "symbol" attribute of this SedVariable.
 */
const std::string&
SedVariable::getSymbol() const
{
	return mSymbol;
}


/*
 * Returns the value of the "target" attribute of this SedVariable.
 */
const std::string&
SedVariable::getTarget() const
{
	return mTarget;
}


/*
 * Returns the value of the "taskReference" attribute of this SedVariable.
 */
const std::string&
SedVariable::getTaskReference() const
{
	return mTaskReference;
}


/*
 * Returns the value of the "modelReference" attribute of this SedVariable.
 */
const std::string&
SedVariable::getModelReference() const
{
	return mModelReference;
}


/*
 * Returns true/false if id is set.
 */
bool
SedVariable::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedVariable::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if symbol is set.
 */
bool
SedVariable::isSetSymbol() const
{
	return (mSymbol.empty() == false);
}


/*
 * Returns true/false if target is set.
 */
bool
SedVariable::isSetTarget() const
{
	return (mTarget.empty() == false);
}


/*
 * Returns true/false if taskReference is set.
 */
bool
SedVariable::isSetTaskReference() const
{
	return (mTaskReference.empty() == false);
}


/*
 * Returns true/false if modelReference is set.
 */
bool
SedVariable::isSetModelReference() const
{
	return (mModelReference.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedVariable::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedVariable::setName(const std::string& name)
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
 * Sets symbol and returns value indicating success.
 */
int
SedVariable::setSymbol(const std::string& symbol)
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
SedVariable::setTarget(const std::string& target)
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
 * Sets taskReference and returns value indicating success.
 */
int
SedVariable::setTaskReference(const std::string& taskReference)
{
	if (&(taskReference) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(taskReference)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mTaskReference = taskReference;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets modelReference and returns value indicating success.
 */
int
SedVariable::setModelReference(const std::string& modelReference)
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
 * Unsets id and returns value indicating success.
 */
int
SedVariable::unsetId()
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
SedVariable::unsetName()
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
 * Unsets symbol and returns value indicating success.
 */
int
SedVariable::unsetSymbol()
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
SedVariable::unsetTarget()
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
 * Unsets taskReference and returns value indicating success.
 */
int
SedVariable::unsetTaskReference()
{
	mTaskReference.erase();

	if (mTaskReference.empty() == true)
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
SedVariable::unsetModelReference()
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
 * Returns the XML element name of this object
 */
const std::string&
SedVariable::getElementName () const
{
	static const string name = "variable";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedVariable::getTypeCode () const
{
	return SEDML_VARIABLE;
}


/*
 * check if all the required attributes are set
 */
bool
SedVariable::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetId() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedVariable::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedVariable::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedVariable::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedVariable::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
	attributes.add("symbol");
	attributes.add("target");
	attributes.add("taskReference");
	attributes.add("modelReference");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedVariable::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedVariable>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedVariable>");
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
			logEmptyString(mSymbol, getLevel(), getVersion(), "<SedVariable>");
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
			logEmptyString(mTarget, getLevel(), getVersion(), "<SedVariable>");
		}
	}

	//
	// taskReference SIdRef   ( use = "optional" )
	//
	assigned = attributes.readInto("taskReference", mTaskReference, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mTaskReference.empty() == true)
		{
			logEmptyString(mTaskReference, getLevel(), getVersion(), "<SedVariable>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mTaskReference) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

	//
	// modelReference SIdRef   ( use = "optional" )
	//
	assigned = attributes.readInto("modelReference", mModelReference, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mModelReference.empty() == true)
		{
			logEmptyString(mModelReference, getLevel(), getVersion(), "<SedVariable>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedVariable::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

	if (isSetSymbol() == true)
		stream.writeAttribute("symbol", getPrefix(), mSymbol);

	if (isSetTarget() == true)
		stream.writeAttribute("target", getPrefix(), mTarget);

	if (isSetTaskReference() == true)
		stream.writeAttribute("taskReference", getPrefix(), mTaskReference);

	if (isSetModelReference() == true)
		stream.writeAttribute("modelReference", getPrefix(), mModelReference);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfVariables::SedListOfVariables(unsigned int level, 
	                   unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfVariables::SedListOfVariables(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfVariables 
 */
SedListOfVariables* 
SedListOfVariables::clone () const
 {
	return new SedListOfVariables(*this);
}


/*
 * Get a Variable from the SedListOfVariables by index.
*/
SedVariable*
SedListOfVariables::get(unsigned int n)
{
	return static_cast<SedVariable*>(SedListOf::get(n));
}


/*
 * Get a Variable from the SedListOfVariables by index.
 */
const SedVariable*
SedListOfVariables::get(unsigned int n) const
{
	return static_cast<const SedVariable*>(SedListOf::get(n));
}


/*
 * Get a Variable from the SedListOfVariables by id.
 */
SedVariable*
SedListOfVariables::get(const std::string& sid)
{
	return const_cast<SedVariable*>(
	  static_cast<const SedListOfVariables&>(*this).get(sid));
}


/*
 * Get a Variable from the SedListOfVariables by id.
 */
const SedVariable*
SedListOfVariables::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedVariable>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedVariable*> (*result);
}


/**
 * Adds a copy the given "SedVariable" to this SedListOfVariables.
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
SedListOfVariables::addVariable(const SedVariable* sv)
{
	if(sv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedVariable objects in this SedListOfVariables.
 *
 * @return the number of SedVariable objects in this SedListOfVariables
 */
unsigned int 
SedListOfVariables::getNumVariables() const
{
	return size();
}

/**
 * Creates a new SedVariable object, adds it to this SedListOfVariabless
 * SedVariable and returns the SedVariable object created. 
 *
 * @return a new SedVariable object instance
 *
 * @see addSedVariable(const SedVariable* sv)
 */
SedVariable* 
SedListOfVariables::createVariable()
{
	SedVariable *temp = new SedVariable();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Variable from this SedListOfVariables
 */
SedVariable*
SedListOfVariables::remove(unsigned int n)
{
	return static_cast<SedVariable*>(SedListOf::remove(n));
}


/*
 * Removes the Variable from this SedListOfVariables with the given identifier
 */
SedVariable*
SedListOfVariables::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedVariable>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedVariable*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfVariables::getElementName () const
{
	static const string name = "listOfVariables";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfVariables::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfVariables::getItemTypeCode () const
{
	return SEDML_VARIABLE;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedVariable in this SedListOfVariables
 */
SedBase*
SedListOfVariables::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "variable")
	{
		object = new SedVariable(getSedNamespaces());
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
SedListOfVariables::writeXMLNS(XMLOutputStream& stream) const
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
SedVariable_t *
SedVariable_create(unsigned int level, unsigned int version)
{
	return new SedVariable(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedVariable_free(SedVariable_t * sv)
{
	if (sv != NULL)
		delete sv;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedVariable_t *
SedVariable_clone(SedVariable_t * sv)
{
	if (sv != NULL)
	{
		return static_cast<SedVariable_t*>(sv->clone());
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
SedVariable_getId(SedVariable_t * sv)
{
	if (sv == NULL)
		return NULL;

	return sv->getId().empty() ? NULL : safe_strdup(sv->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedVariable_getName(SedVariable_t * sv)
{
	if (sv == NULL)
		return NULL;

	return sv->getName().empty() ? NULL : safe_strdup(sv->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedVariable_getSymbol(SedVariable_t * sv)
{
	if (sv == NULL)
		return NULL;

	return sv->getSymbol().empty() ? NULL : safe_strdup(sv->getSymbol().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedVariable_getTarget(SedVariable_t * sv)
{
	if (sv == NULL)
		return NULL;

	return sv->getTarget().empty() ? NULL : safe_strdup(sv->getTarget().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedVariable_getTaskReference(SedVariable_t * sv)
{
	if (sv == NULL)
		return NULL;

	return sv->getTaskReference().empty() ? NULL : safe_strdup(sv->getTaskReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedVariable_getModelReference(SedVariable_t * sv)
{
	if (sv == NULL)
		return NULL;

	return sv->getModelReference().empty() ? NULL : safe_strdup(sv->getModelReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_isSetId(SedVariable_t * sv)
{
	return (sv != NULL) ? static_cast<int>(sv->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_isSetName(SedVariable_t * sv)
{
	return (sv != NULL) ? static_cast<int>(sv->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_isSetSymbol(SedVariable_t * sv)
{
	return (sv != NULL) ? static_cast<int>(sv->isSetSymbol()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTarget(SedVariable_t * sv)
{
	return (sv != NULL) ? static_cast<int>(sv->isSetTarget()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_isSetTaskReference(SedVariable_t * sv)
{
	return (sv != NULL) ? static_cast<int>(sv->isSetTaskReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_isSetModelReference(SedVariable_t * sv)
{
	return (sv != NULL) ? static_cast<int>(sv->isSetModelReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_setId(SedVariable_t * sv, const char * id)
{
	return (sv != NULL) ? sv->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_setName(SedVariable_t * sv, const char * name)
{
	return (sv != NULL) ? sv->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_setSymbol(SedVariable_t * sv, const char * symbol)
{
	return (sv != NULL) ? sv->setSymbol(symbol) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_setTarget(SedVariable_t * sv, const char * target)
{
	return (sv != NULL) ? sv->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_setTaskReference(SedVariable_t * sv, const char * taskReference)
{
	return (sv != NULL) ? sv->setTaskReference(taskReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_setModelReference(SedVariable_t * sv, const char * modelReference)
{
	return (sv != NULL) ? sv->setModelReference(modelReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_unsetId(SedVariable_t * sv)
{
	return (sv != NULL) ? sv->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_unsetName(SedVariable_t * sv)
{
	return (sv != NULL) ? sv->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_unsetSymbol(SedVariable_t * sv)
{
	return (sv != NULL) ? sv->unsetSymbol() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTarget(SedVariable_t * sv)
{
	return (sv != NULL) ? sv->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_unsetTaskReference(SedVariable_t * sv)
{
	return (sv != NULL) ? sv->unsetTaskReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_unsetModelReference(SedVariable_t * sv)
{
	return (sv != NULL) ? sv->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVariable_hasRequiredAttributes(SedVariable_t * sv)
{
	return (sv != NULL) ? static_cast<int>(sv->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedVariable_t *
SedListOfVariables_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfVariables *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedVariable_t *
SedListOfVariables_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfVariables *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


