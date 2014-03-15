/**
 * @file:   SedTask.cpp
 * @brief:  Implementation of the SedTask class
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


#include <sedml/SedTask.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedTask with the given level, version, and package version.
 */
SedTask::SedTask (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mModelReference ("")
	, mSimulationReference ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedTask with the given SedNamespaces object.
 */
SedTask::SedTask (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")
	, mName ("")
	, mModelReference ("")
	, mSimulationReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedTask.
 */
SedTask::SedTask (const SedTask& orig)
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
		mModelReference  = orig.mModelReference;
		mSimulationReference  = orig.mSimulationReference;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedTask.
 */
SedTask&
SedTask::operator=(const SedTask& rhs)
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
		mModelReference  = rhs.mModelReference;
		mSimulationReference  = rhs.mSimulationReference;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedTask.
 */
SedTask*
SedTask::clone () const
{
	return new SedTask(*this);
}


/*
 * Destructor for SedTask.
 */
SedTask::~SedTask ()
{
}


/*
 * Returns the value of the "id" attribute of this SedTask.
 */
const std::string&
SedTask::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedTask.
 */
const std::string&
SedTask::getName() const
{
	return mName;
}


/*
 * Returns the value of the "modelReference" attribute of this SedTask.
 */
const std::string&
SedTask::getModelReference() const
{
	return mModelReference;
}


/*
 * Returns the value of the "simulationReference" attribute of this SedTask.
 */
const std::string&
SedTask::getSimulationReference() const
{
	return mSimulationReference;
}


/*
 * Returns true/false if id is set.
 */
bool
SedTask::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedTask::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if modelReference is set.
 */
bool
SedTask::isSetModelReference() const
{
	return (mModelReference.empty() == false);
}


/*
 * Returns true/false if simulationReference is set.
 */
bool
SedTask::isSetSimulationReference() const
{
	return (mSimulationReference.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedTask::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedTask::setName(const std::string& name)
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
 * Sets modelReference and returns value indicating success.
 */
int
SedTask::setModelReference(const std::string& modelReference)
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
 * Sets simulationReference and returns value indicating success.
 */
int
SedTask::setSimulationReference(const std::string& simulationReference)
{
	if (&(simulationReference) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(simulationReference)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mSimulationReference = simulationReference;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedTask::unsetId()
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
SedTask::unsetName()
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
 * Unsets modelReference and returns value indicating success.
 */
int
SedTask::unsetModelReference()
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
 * Unsets simulationReference and returns value indicating success.
 */
int
SedTask::unsetSimulationReference()
{
	mSimulationReference.erase();

	if (mSimulationReference.empty() == true)
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
SedTask::getElementName () const
{
	static const string name = "task";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedTask::createObject(XMLInputStream& stream)
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
SedTask::connectToChild ()
{
	SedBase::connectToChild();

}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedTask::getTypeCode () const
{
	return SEDML_TASK;
}


/*
 * check if all the required attributes are set
 */
bool
SedTask::hasRequiredAttributes () const
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
SedTask::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedTask::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedTask::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedTask::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedTask::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
	attributes.add("modelReference");
	attributes.add("simulationReference");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedTask::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedTask>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedTask>");
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
			logEmptyString(mModelReference, getLevel(), getVersion(), "<SedTask>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

	//
	// simulationReference SIdRef   ( use = "optional" )
	//
	assigned = attributes.readInto("simulationReference", mSimulationReference, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mSimulationReference.empty() == true)
		{
			logEmptyString(mSimulationReference, getLevel(), getVersion(), "<SedTask>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mSimulationReference) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedTask::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

	if (isSetModelReference() == true)
		stream.writeAttribute("modelReference", getPrefix(), mModelReference);

	if (isSetSimulationReference() == true)
		stream.writeAttribute("simulationReference", getPrefix(), mSimulationReference);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor 
 */
SedListOfTasks::SedListOfTasks(unsigned int level, 
	               unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfTasks::SedListOfTasks(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfTasks 
 */
SedListOfTasks* 
SedListOfTasks::clone () const
 {
	return new SedListOfTasks(*this);
}


/*
 * Get a Task from the SedListOfTasks by index.
*/
SedTask*
SedListOfTasks::get(unsigned int n)
{
	return static_cast<SedTask*>(SedListOf::get(n));
}


/*
 * Get a Task from the SedListOfTasks by index.
 */
const SedTask*
SedListOfTasks::get(unsigned int n) const
{
	return static_cast<const SedTask*>(SedListOf::get(n));
}


/*
 * Get a Task from the SedListOfTasks by id.
 */
SedTask*
SedListOfTasks::get(const std::string& sid)
{
	return const_cast<SedTask*>(
	  static_cast<const SedListOfTasks&>(*this).get(sid));
}


/*
 * Get a Task from the SedListOfTasks by id.
 */
const SedTask*
SedListOfTasks::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedTask>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedTask*> (*result);
}


/**
 * Adds a copy the given "SedTask" to this SedListOfTasks.
 *
 * @param st; the SedTask object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfTasks::addTask(const SedTask* st)
{
	if(st == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(st);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedTask objects in this SedListOfTasks.
 *
 * @return the number of SedTask objects in this SedListOfTasks
 */
unsigned int 
SedListOfTasks::getNumTasks() const
{
	return size();
}

/**
 * Creates a new SedTask object, adds it to this SedListOfTasks
 * task and returns the SedTask object created. 
 *
 * @return a new SedTask object instance
 *
 * @see addTask(const SedTask* st)
 */
SedTask* 
SedListOfTasks::createTask()
{
	SedTask *temp = new SedTask();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedRepeatedTask object, adds it to this SedListOfTasks
 * repeatedTask and returns the SedRepeatedTask object created. 
 *
 * @return a new SedRepeatedTask object instance
 *
 * @see addRepeatedTask(const SedTask* st)
 */
SedRepeatedTask* 
SedListOfTasks::createRepeatedTask()
{
	SedRepeatedTask *temp = new SedRepeatedTask();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Task from this SedListOfTasks
 */
SedTask*
SedListOfTasks::remove(unsigned int n)
{
	return static_cast<SedTask*>(SedListOf::remove(n));
}


/*
 * Removes the Task from this SedListOfTasks with the given identifier
 */
SedTask*
SedListOfTasks::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedTask>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedTask*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfTasks::getElementName () const
{
	static const string name = "listOfTasks";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfTasks::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfTasks::getItemTypeCode () const
{
	return SEDML_TASK;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedTask in this SedListOfTasks
 */
SedBase*
SedListOfTasks::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "task")
	{
		object = new SedTask(getSedNamespaces());
		appendAndOwn(object);
	}

	if (name == "repeatedTask")
	{
		object = new SedRepeatedTask(getSedNamespaces());
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
SedListOfTasks::writeXMLNS(XMLOutputStream& stream) const
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
SedTask_t *
SedTask_create(unsigned int level, unsigned int version)
{
	return new SedTask(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedTask_free(SedTask_t * st)
{
	if (st != NULL)
		delete st;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedTask_t *
SedTask_clone(SedTask_t * st)
{
	if (st != NULL)
	{
		return static_cast<SedTask_t*>(st->clone());
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
SedTask_getId(SedTask_t * st)
{
	if (st == NULL)
		return NULL;

	return st->getId().empty() ? NULL : safe_strdup(st->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedTask_getName(SedTask_t * st)
{
	if (st == NULL)
		return NULL;

	return st->getName().empty() ? NULL : safe_strdup(st->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedTask_getModelReference(SedTask_t * st)
{
	if (st == NULL)
		return NULL;

	return st->getModelReference().empty() ? NULL : safe_strdup(st->getModelReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedTask_getSimulationReference(SedTask_t * st)
{
	if (st == NULL)
		return NULL;

	return st->getSimulationReference().empty() ? NULL : safe_strdup(st->getSimulationReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_isSetId(SedTask_t * st)
{
	return (st != NULL) ? static_cast<int>(st->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_isSetName(SedTask_t * st)
{
	return (st != NULL) ? static_cast<int>(st->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_isSetModelReference(SedTask_t * st)
{
	return (st != NULL) ? static_cast<int>(st->isSetModelReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_isSetSimulationReference(SedTask_t * st)
{
	return (st != NULL) ? static_cast<int>(st->isSetSimulationReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_setId(SedTask_t * st, const char * id)
{
	return (st != NULL) ? st->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_setName(SedTask_t * st, const char * name)
{
	return (st != NULL) ? st->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_setModelReference(SedTask_t * st, const char * modelReference)
{
	return (st != NULL) ? st->setModelReference(modelReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_setSimulationReference(SedTask_t * st, const char * simulationReference)
{
	return (st != NULL) ? st->setSimulationReference(simulationReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_unsetId(SedTask_t * st)
{
	return (st != NULL) ? st->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_unsetName(SedTask_t * st)
{
	return (st != NULL) ? st->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_unsetModelReference(SedTask_t * st)
{
	return (st != NULL) ? st->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_unsetSimulationReference(SedTask_t * st)
{
	return (st != NULL) ? st->unsetSimulationReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_hasRequiredAttributes(SedTask_t * st)
{
	return (st != NULL) ? static_cast<int>(st->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedTask_hasRequiredElements(SedTask_t * st)
{
	return (st != NULL) ? static_cast<int>(st->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedTask_t *
SedListOfTasks_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfTasks *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedTask_t *
SedListOfTasks_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfTasks *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


