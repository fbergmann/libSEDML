/**
 * @file:   Task.cpp
 * @brief:  Implementation of the Task class
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


#include <sedml/Task.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Task with the given level, version, and package version.
 */
Task::Task (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mModelReference ("")
	, mSimulationReference ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new Task with the given SedMLNamespaces object.
 */
Task::Task (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mName ("")
	, mModelReference ("")
	, mSimulationReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for Task.
 */
Task::Task (const Task& orig)
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
		mModelReference  = orig.mModelReference;
		mSimulationReference  = orig.mSimulationReference;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for Task.
 */
Task&
Task::operator=(const Task& rhs)
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
		mModelReference  = rhs.mModelReference;
		mSimulationReference  = rhs.mSimulationReference;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for Task.
 */
Task*
Task::clone () const
{
	return new Task(*this);
}


/*
 * Destructor for Task.
 */
Task::~Task ()
{
}


/*
 * Returns the value of the "id" attribute of this Task.
 */
const std::string&
Task::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this Task.
 */
const std::string&
Task::getName() const
{
	return mName;
}


/*
 * Returns the value of the "modelReference" attribute of this Task.
 */
const std::string&
Task::getModelReference() const
{
	return mModelReference;
}


/*
 * Returns the value of the "simulationReference" attribute of this Task.
 */
const std::string&
Task::getSimulationReference() const
{
	return mSimulationReference;
}


/*
 * Returns true/false if id is set.
 */
bool
Task::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
Task::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if modelReference is set.
 */
bool
Task::isSetModelReference() const
{
	return (mModelReference.empty() == false);
}


/*
 * Returns true/false if simulationReference is set.
 */
bool
Task::isSetSimulationReference() const
{
	return (mSimulationReference.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
Task::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
Task::setName(const std::string& name)
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
Task::setModelReference(const std::string& modelReference)
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
Task::setSimulationReference(const std::string& simulationReference)
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
Task::unsetId()
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
Task::unsetName()
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
Task::unsetModelReference()
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
Task::unsetSimulationReference()
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
Task::getElementName () const
{
	static const string name = "task";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
Task::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	SedBase::connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Task::connectToChild ()
{
	SedBase::connectToChild();

}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Task::getTypeCode () const
{
	return SEDML_TASK;
}


/*
 * check if all the required attributes are set
 */
bool
Task::hasRequiredAttributes () const
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
Task::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
Task::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Task::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Task::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Task::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
	attributes.add("modelReference");
	attributes.add("simulationReference");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Task::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<Task>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<Task>");
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
			logEmptyString(mModelReference, getLevel(), getVersion(), "<Task>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mModelReference) == false)
		{
			logError(InvalidIdSyntax);
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
			logEmptyString(mSimulationReference, getLevel(), getVersion(), "<Task>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mSimulationReference) == false)
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
Task::writeAttributes (XMLOutputStream& stream) const
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


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfTasks::SedListOfTasks(unsigned int level, 
	               unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfTasks::SedListOfTasks(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
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
Task*
SedListOfTasks::get(unsigned int n)
{
	return static_cast<Task*>(SedListOf::get(n));
}


/*
 * Get a Task from the SedListOfTasks by index.
 */
const Task*
SedListOfTasks::get(unsigned int n) const
{
	return static_cast<const Task*>(SedListOf::get(n));
}


/*
 * Get a Task from the SedListOfTasks by id.
 */
Task*
SedListOfTasks::get(const std::string& sid)
{
	return const_cast<Task*>(
	  static_cast<const SedListOfTasks&>(*this).get(sid));
}


/*
 * Get a Task from the SedListOfTasks by id.
 */
const Task*
SedListOfTasks::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Task>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <Task*> (*result);
}


/*
 * Removes the nth Task from this SedListOfTasks
 */
Task*
SedListOfTasks::remove(unsigned int n)
{
	return static_cast<Task*>(SedListOf::remove(n));
}


/*
 * Removes the Task from this SedListOfTasks with the given identifier
 */
Task*
SedListOfTasks::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<Task>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <Task*> (item);
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


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new Task in this SedListOfTasks
 */
SedBase*
SedListOfTasks::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "task")
	{
		object = new Task(getSedMLNamespaces());
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
SedListOfTasks::writeXMLNS(XMLOutputStream& stream) const
{
	XMLNamespaces xmlns;

	std::string prefix = getPrefix();

	if (prefix.empty())
	{
		if (!getNamespaces()->hasURI(SEDML_XMLNS_L1))
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
Task_t *
Task_create(unsigned int level, unsigned int version)
{
	return new Task(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Task_free(Task_t * t)
{
	if (t != NULL)
		delete t;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Task_t *
Task_clone(Task_t * t)
{
	if (t != NULL)
	{
		return static_cast<Task_t*>(t->clone());
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
Task_getId(Task_t * t)
{
	if (t == NULL)
		return NULL;

	return t->getId().empty() ? NULL : safe_strdup(t->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
Task_getName(Task_t * t)
{
	if (t == NULL)
		return NULL;

	return t->getName().empty() ? NULL : safe_strdup(t->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
Task_getModelReference(Task_t * t)
{
	if (t == NULL)
		return NULL;

	return t->getModelReference().empty() ? NULL : safe_strdup(t->getModelReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
Task_getSimulationReference(Task_t * t)
{
	if (t == NULL)
		return NULL;

	return t->getSimulationReference().empty() ? NULL : safe_strdup(t->getSimulationReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_isSetId(Task_t * t)
{
	return (t != NULL) ? static_cast<int>(t->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_isSetName(Task_t * t)
{
	return (t != NULL) ? static_cast<int>(t->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_isSetModelReference(Task_t * t)
{
	return (t != NULL) ? static_cast<int>(t->isSetModelReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_isSetSimulationReference(Task_t * t)
{
	return (t != NULL) ? static_cast<int>(t->isSetSimulationReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_setId(Task_t * t, const char * id)
{
	return (t != NULL) ? t->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_setName(Task_t * t, const char * name)
{
	return (t != NULL) ? t->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_setModelReference(Task_t * t, const char * modelReference)
{
	return (t != NULL) ? t->setModelReference(modelReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_setSimulationReference(Task_t * t, const char * simulationReference)
{
	return (t != NULL) ? t->setSimulationReference(simulationReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_unsetId(Task_t * t)
{
	return (t != NULL) ? t->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_unsetName(Task_t * t)
{
	return (t != NULL) ? t->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_unsetModelReference(Task_t * t)
{
	return (t != NULL) ? t->unsetModelReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_unsetSimulationReference(Task_t * t)
{
	return (t != NULL) ? t->unsetSimulationReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_hasRequiredAttributes(Task_t * t)
{
	return (t != NULL) ? static_cast<int>(t->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Task_hasRequiredElements(Task_t * t)
{
	return (t != NULL) ? static_cast<int>(t->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Task_t *
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
Task_t *
SedListOfTasks_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfTasks *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


