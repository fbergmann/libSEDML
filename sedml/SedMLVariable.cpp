/**
 * @file:   SedMLVariable.cpp
 * @brief:  Implementation of the SedMLVariable class
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


#include <sedml/SedMLVariable.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedMLVariable with the given level, version, and package version.
 */
SedMLVariable::SedMLVariable (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mSymbol ("")
	, mTarget ("")
	, mTaskReference ("")
	, mModelReference ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new SedMLVariable with the given SedMLNamespaces object.
 */
SedMLVariable::SedMLVariable (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mName ("")
	, mSymbol ("")
	, mTarget ("")
	, mTaskReference ("")
	, mModelReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedMLVariable.
 */
SedMLVariable::SedMLVariable (const SedMLVariable& orig)
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
		mSymbol  = orig.mSymbol;
		mTarget  = orig.mTarget;
		mTaskReference  = orig.mTaskReference;
		mModelReference  = orig.mModelReference;
	}
}


/*
 * Assignment for SedMLVariable.
 */
SedMLVariable&
SedMLVariable::operator=(const SedMLVariable& rhs)
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
		mSymbol  = rhs.mSymbol;
		mTarget  = rhs.mTarget;
		mTaskReference  = rhs.mTaskReference;
		mModelReference  = rhs.mModelReference;
	}
	return *this;
}


/*
 * Clone for SedMLVariable.
 */
SedMLVariable*
SedMLVariable::clone () const
{
	return new SedMLVariable(*this);
}


/*
 * Destructor for SedMLVariable.
 */
SedMLVariable::~SedMLVariable ()
{
}


/*
 * Returns the value of the "id" attribute of this SedMLVariable.
 */
const std::string&
SedMLVariable::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedMLVariable.
 */
const std::string&
SedMLVariable::getName() const
{
	return mName;
}


/*
 * Returns the value of the "symbol" attribute of this SedMLVariable.
 */
const std::string&
SedMLVariable::getSymbol() const
{
	return mSymbol;
}


/*
 * Returns the value of the "target" attribute of this SedMLVariable.
 */
const std::string&
SedMLVariable::getTarget() const
{
	return mTarget;
}


/*
 * Returns the value of the "taskReference" attribute of this SedMLVariable.
 */
const std::string&
SedMLVariable::getTaskReference() const
{
	return mTaskReference;
}


/*
 * Returns the value of the "modelReference" attribute of this SedMLVariable.
 */
const std::string&
SedMLVariable::getModelReference() const
{
	return mModelReference;
}


/*
 * Returns true/false if id is set.
 */
bool
SedMLVariable::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedMLVariable::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if symbol is set.
 */
bool
SedMLVariable::isSetSymbol() const
{
	return (mSymbol.empty() == false);
}


/*
 * Returns true/false if target is set.
 */
bool
SedMLVariable::isSetTarget() const
{
	return (mTarget.empty() == false);
}


/*
 * Returns true/false if taskReference is set.
 */
bool
SedMLVariable::isSetTaskReference() const
{
	return (mTaskReference.empty() == false);
}


/*
 * Returns true/false if modelReference is set.
 */
bool
SedMLVariable::isSetModelReference() const
{
	return (mModelReference.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedMLVariable::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedMLVariable::setName(const std::string& name)
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
SedMLVariable::setSymbol(const std::string& symbol)
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
SedMLVariable::setTarget(const std::string& target)
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
SedMLVariable::setTaskReference(const std::string& taskReference)
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
SedMLVariable::setModelReference(const std::string& modelReference)
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
SedMLVariable::unsetId()
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
SedMLVariable::unsetName()
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
SedMLVariable::unsetSymbol()
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
SedMLVariable::unsetTarget()
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
SedMLVariable::unsetTaskReference()
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
SedMLVariable::unsetModelReference()
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
SedMLVariable::getElementName () const
{
	static const string name = "variable";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedMLVariable::getTypeCode () const
{
	return SEDML_VARIABLE;
}


/*
 * check if all the required attributes are set
 */
bool
SedMLVariable::hasRequiredAttributes () const
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
SedMLVariable::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
SedMLVariable::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
SedMLVariable::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedMLVariable::addExpectedAttributes(ExpectedAttributes& attributes)
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
SedMLVariable::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedMLVariable>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedMLVariable>");
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
			logEmptyString(mSymbol, getLevel(), getVersion(), "<SedMLVariable>");
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
			logEmptyString(mTarget, getLevel(), getVersion(), "<SedMLVariable>");
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
			logEmptyString(mTaskReference, getLevel(), getVersion(), "<SedMLVariable>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mTaskReference) == false)
		{
			logError(InvalidIdSyntax);
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
			logEmptyString(mModelReference, getLevel(), getVersion(), "<SedMLVariable>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
		{
			logError(InvalidIdSyntax);
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedMLVariable::writeAttributes (XMLOutputStream& stream) const
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
SedListOfSedMLVariables::SedListOfSedMLVariables(unsigned int level, 
	                        unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSedMLVariables::SedListOfSedMLVariables(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSedMLVariables 
 */
SedListOfSedMLVariables* 
SedListOfSedMLVariables::clone () const
 {
	return new SedListOfSedMLVariables(*this);
}


/*
 * Get a SedMLVariable from the SedListOfSedMLVariables by index.
*/
SedMLVariable*
SedListOfSedMLVariables::get(unsigned int n)
{
	return static_cast<SedMLVariable*>(SedListOf::get(n));
}


/*
 * Get a SedMLVariable from the SedListOfSedMLVariables by index.
 */
const SedMLVariable*
SedListOfSedMLVariables::get(unsigned int n) const
{
	return static_cast<const SedMLVariable*>(SedListOf::get(n));
}


/*
 * Get a SedMLVariable from the SedListOfSedMLVariables by id.
 */
SedMLVariable*
SedListOfSedMLVariables::get(const std::string& sid)
{
	return const_cast<SedMLVariable*>(
	  static_cast<const SedListOfSedMLVariables&>(*this).get(sid));
}


/*
 * Get a SedMLVariable from the SedListOfSedMLVariables by id.
 */
const SedMLVariable*
SedListOfSedMLVariables::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLVariable>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedMLVariable*> (*result);
}


/*
 * Removes the nth SedMLVariable from this SedListOfSedMLVariables
 */
SedMLVariable*
SedListOfSedMLVariables::remove(unsigned int n)
{
	return static_cast<SedMLVariable*>(SedListOf::remove(n));
}


/*
 * Removes the SedMLVariable from this SedListOfSedMLVariables with the given identifier
 */
SedMLVariable*
SedListOfSedMLVariables::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLVariable>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedMLVariable*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSedMLVariables::getElementName () const
{
	static const string name = "listOfVariables";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSedMLVariables::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSedMLVariables::getItemTypeCode () const
{
	return SEDML_VARIABLE;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedMLVariable in this SedListOfSedMLVariables
 */
SedBase*
SedListOfSedMLVariables::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "variable")
	{
		object = new SedMLVariable(getSedMLNamespaces());
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
SedListOfSedMLVariables::writeXMLNS(XMLOutputStream& stream) const
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
SedMLVariable_t *
SedMLVariable_create(unsigned int level, unsigned int version)
{
	return new SedMLVariable(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedMLVariable_free(SedMLVariable_t * smlv)
{
	if (smlv != NULL)
		delete smlv;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLVariable_t *
SedMLVariable_clone(SedMLVariable_t * smlv)
{
	if (smlv != NULL)
	{
		return static_cast<SedMLVariable_t*>(smlv->clone());
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
SedMLVariable_getId(SedMLVariable_t * smlv)
{
	if (smlv == NULL)
		return NULL;

	return smlv->getId().empty() ? NULL : safe_strdup(smlv->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLVariable_getName(SedMLVariable_t * smlv)
{
	if (smlv == NULL)
		return NULL;

	return smlv->getName().empty() ? NULL : safe_strdup(smlv->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLVariable_getSymbol(SedMLVariable_t * smlv)
{
	if (smlv == NULL)
		return NULL;

	return smlv->getSymbol().empty() ? NULL : safe_strdup(smlv->getSymbol().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLVariable_getTarget(SedMLVariable_t * smlv)
{
	if (smlv == NULL)
		return NULL;

	return smlv->getTarget().empty() ? NULL : safe_strdup(smlv->getTarget().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLVariable_getTaskReference(SedMLVariable_t * smlv)
{
	if (smlv == NULL)
		return NULL;

	return smlv->getTaskReference().empty() ? NULL : safe_strdup(smlv->getTaskReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLVariable_getModelReference(SedMLVariable_t * smlv)
{
	if (smlv == NULL)
		return NULL;

	return smlv->getModelReference().empty() ? NULL : safe_strdup(smlv->getModelReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_isSetId(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? static_cast<int>(smlv->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_isSetName(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? static_cast<int>(smlv->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_isSetSymbol(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? static_cast<int>(smlv->isSetSymbol()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_isSetTarget(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? static_cast<int>(smlv->isSetTarget()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_isSetTaskReference(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? static_cast<int>(smlv->isSetTaskReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_isSetModelReference(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? static_cast<int>(smlv->isSetModelReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_setId(SedMLVariable_t * smlv, const char * id)
{
	return (smlv != NULL) ? smlv->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_setName(SedMLVariable_t * smlv, const char * name)
{
	return (smlv != NULL) ? smlv->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_setSymbol(SedMLVariable_t * smlv, const char * symbol)
{
	return (smlv != NULL) ? smlv->setSymbol(symbol) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_setTarget(SedMLVariable_t * smlv, const char * target)
{
	return (smlv != NULL) ? smlv->setTarget(target) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_setTaskReference(SedMLVariable_t * smlv, const char * taskReference)
{
	return (smlv != NULL) ? smlv->setTaskReference(taskReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_setModelReference(SedMLVariable_t * smlv, const char * modelReference)
{
	return (smlv != NULL) ? smlv->setModelReference(modelReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_unsetId(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? smlv->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_unsetName(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? smlv->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_unsetSymbol(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? smlv->unsetSymbol() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_unsetTarget(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? smlv->unsetTarget() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_unsetTaskReference(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? smlv->unsetTaskReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_unsetModelReference(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? smlv->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLVariable_hasRequiredAttributes(SedMLVariable_t * smlv)
{
	return (smlv != NULL) ? static_cast<int>(smlv->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLVariable_t *
SedListOfSedMLVariables_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLVariables *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLVariable_t *
SedListOfSedMLVariables_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLVariables *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


