/**
 * @file:   SedRepeatedTask.cpp
 * @brief:  Implementation of the SedRepeatedTask class
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


#include <sedml/SedRepeatedTask.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedRepeatedTask with the given level, version, and package version.
 */
SedRepeatedTask::SedRepeatedTask (unsigned int level, unsigned int version)
	: SedTask(level, version)
	, mRangeId ("")
	, mResetModel (false)
	, mIsSetResetModel (false)
	, mRanges (level, version)
	, mTaskChanges (level, version)
	, mSubTasks (level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedRepeatedTask with the given SedNamespaces object.
 */
SedRepeatedTask::SedRepeatedTask (SedNamespaces* sedns)
	: SedTask(sedns)
	, mRangeId ("")
	, mResetModel (false)
	, mIsSetResetModel (false)
	, mRanges (sedns)
	, mTaskChanges (sedns)
	, mSubTasks (sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedRepeatedTask.
 */
SedRepeatedTask::SedRepeatedTask (const SedRepeatedTask& orig)
	: SedTask(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mRangeId  = orig.mRangeId;
		mResetModel  = orig.mResetModel;
		mIsSetResetModel  = orig.mIsSetResetModel;
		mRanges  = orig.mRanges;
		mTaskChanges  = orig.mTaskChanges;
		mSubTasks  = orig.mSubTasks;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedRepeatedTask.
 */
SedRepeatedTask&
SedRepeatedTask::operator=(const SedRepeatedTask& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedTask::operator=(rhs);
		mRangeId  = rhs.mRangeId;
		mResetModel  = rhs.mResetModel;
		mIsSetResetModel  = rhs.mIsSetResetModel;
		mRanges  = rhs.mRanges;
		mTaskChanges  = rhs.mTaskChanges;
		mSubTasks  = rhs.mSubTasks;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedRepeatedTask.
 */
SedRepeatedTask*
SedRepeatedTask::clone () const
{
	return new SedRepeatedTask(*this);
}


/*
 * Destructor for SedRepeatedTask.
 */
SedRepeatedTask::~SedRepeatedTask ()
{
}


/*
 * Returns the value of the "rangeId" attribute of this SedRepeatedTask.
 */
const std::string&
SedRepeatedTask::getRangeId() const
{
	return mRangeId;
}


/*
 * Returns the value of the "resetModel" attribute of this SedRepeatedTask.
 */
const bool
SedRepeatedTask::getResetModel() const
{
	return mResetModel;
}


/*
 * Returns true/false if rangeId is set.
 */
bool
SedRepeatedTask::isSetRangeId() const
{
	return (mRangeId.empty() == false);
}


/*
 * Returns true/false if resetModel is set.
 */
bool
SedRepeatedTask::isSetResetModel() const
{
	return mIsSetResetModel;
}


/*
 * Sets rangeId and returns value indicating success.
 */
int
SedRepeatedTask::setRangeId(const std::string& rangeId)
{
	if (&(rangeId) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(rangeId)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mRangeId = rangeId;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets resetModel and returns value indicating success.
 */
int
SedRepeatedTask::setResetModel(bool resetModel)
{
	mResetModel = resetModel;
	mIsSetResetModel = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets rangeId and returns value indicating success.
 */
int
SedRepeatedTask::unsetRangeId()
{
	mRangeId.erase();

	if (mRangeId.empty() == true)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets resetModel and returns value indicating success.
 */
int
SedRepeatedTask::unsetResetModel()
{
	mResetModel = false;
	mIsSetResetModel = false;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the  "SedListOfRanges" in this SedRepeatedTask object.
 */
const SedListOfRanges*
SedRepeatedTask::getListOfRanges() const
{
	return &mRanges;
}


/*
 * Removes the nth Range from the SedListOfRanges.
 */
SedRange*
SedRepeatedTask::removeRange(unsigned int n)
{
	return mRanges.remove(n);
}


/*
 * Removes the a Range with given id from the SedListOfRanges.
 */
SedRange*
SedRepeatedTask::removeRange(const std::string& sid)
{
	return mRanges.remove(sid);
}


/*
 * Return the nth Range in the SedListOfRanges within this SedRepeatedTask.
 */
SedRange*
SedRepeatedTask::getRange(unsigned int n)
{
	return mRanges.get(n);
}


/*
 * Return the nth Range in the SedListOfRanges within this SedRepeatedTask.
 */
const SedRange*
SedRepeatedTask::getRange(unsigned int n) const
{
	return mRanges.get(n);
}


/*
 * Return a Range from the SedListOfRanges by id.
 */
SedRange*
SedRepeatedTask::getRange(const std::string& sid)
{
	return mRanges.get(sid);
}


/*
 * Return a Range from the SedListOfRanges by id.
 */
const SedRange*
SedRepeatedTask::getRange(const std::string& sid) const
{
	return mRanges.get(sid);
}


/**
 * Adds a copy the given "SedRange" to this SedRepeatedTask.
 *
 * @param sr; the SedRange object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedRepeatedTask::addRange(const SedRange* sr)
{
	if(sr == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mRanges.append(sr);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedRange objects in this SedRepeatedTask.
 *
 * @return the number of SedRange objects in this SedRepeatedTask
 */
unsigned int 
SedRepeatedTask::getNumRanges() const
{
	return mRanges.size();
}

/**
 * Creates a new SedUniformRange object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedUniformRange object created. 
 *
 * @return a new SedUniformRange object instance
 *
 * @see addUniformRange(const SedRange* sr)
 */
SedUniformRange* 
SedRepeatedTask::createUniformRange()
{
	SedUniformRange *temp = new SedUniformRange();
	if (temp != NULL) mRanges.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedVectorRange object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedVectorRange object created. 
 *
 * @return a new SedVectorRange object instance
 *
 * @see addVectorRange(const SedRange* sr)
 */
SedVectorRange* 
SedRepeatedTask::createVectorRange()
{
	SedVectorRange *temp = new SedVectorRange();
	if (temp != NULL) mRanges.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedFunctionalRange object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedFunctionalRange object created. 
 *
 * @return a new SedFunctionalRange object instance
 *
 * @see addFunctionalRange(const SedRange* sr)
 */
SedFunctionalRange* 
SedRepeatedTask::createFunctionalRange()
{
	SedFunctionalRange *temp = new SedFunctionalRange();
	if (temp != NULL) mRanges.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfTaskChanges" in this SedRepeatedTask object.
 */
const SedListOfTaskChanges*
SedRepeatedTask::getListOfTaskChanges() const
{
	return &mTaskChanges;
}


/*
 * Removes the nth TaskChange from the SedListOfTaskChanges.
 */
SedSetValue*
SedRepeatedTask::removeTaskChange(unsigned int n)
{
	return mTaskChanges.remove(n);
}


/*
 * Removes the a TaskChange with given id from the SedListOfTaskChanges.
 */
SedSetValue*
SedRepeatedTask::removeTaskChange(const std::string& sid)
{
	return mTaskChanges.remove(sid);
}


/*
 * Return the nth TaskChange in the SedListOfTaskChanges within this SedRepeatedTask.
 */
SedSetValue*
SedRepeatedTask::getTaskChange(unsigned int n)
{
	return mTaskChanges.get(n);
}


/*
 * Return the nth TaskChange in the SedListOfTaskChanges within this SedRepeatedTask.
 */
const SedSetValue*
SedRepeatedTask::getTaskChange(unsigned int n) const
{
	return mTaskChanges.get(n);
}


/*
 * Return a TaskChange from the SedListOfTaskChanges by id.
 */
SedSetValue*
SedRepeatedTask::getTaskChange(const std::string& sid)
{
	return mTaskChanges.get(sid);
}


/*
 * Return a TaskChange from the SedListOfTaskChanges by id.
 */
const SedSetValue*
SedRepeatedTask::getTaskChange(const std::string& sid) const
{
	return mTaskChanges.get(sid);
}


/**
 * Adds a copy the given "SedSetValue" to this SedRepeatedTask.
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
SedRepeatedTask::addTaskChange(const SedSetValue* ssv)
{
	if(ssv == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mTaskChanges.append(ssv);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSetValue objects in this SedRepeatedTask.
 *
 * @return the number of SedSetValue objects in this SedRepeatedTask
 */
unsigned int 
SedRepeatedTask::getNumTaskChanges() const
{
	return mTaskChanges.size();
}

/**
 * Creates a new SedSetValue object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedSetValue object created. 
 *
 * @return a new SedSetValue object instance
 *
 * @see addSedSetValue(const SedSetValue* ssv)
 */
SedSetValue* 
SedRepeatedTask::createTaskChange()
{
	SedSetValue *temp = new SedSetValue();
	if (temp != NULL) mTaskChanges.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSubTasks" in this SedRepeatedTask object.
 */
const SedListOfSubTasks*
SedRepeatedTask::getListOfSubTasks() const
{
	return &mSubTasks;
}


/*
 * Removes the nth SubTask from the SedListOfSubTasks.
 */
SedSubTask*
SedRepeatedTask::removeSubTask(unsigned int n)
{
	return mSubTasks.remove(n);
}


/*
 * Removes the a SubTask with given id from the SedListOfSubTasks.
 */
SedSubTask*
SedRepeatedTask::removeSubTask(const std::string& sid)
{
	return mSubTasks.remove(sid);
}


/*
 * Return the nth SubTask in the SedListOfSubTasks within this SedRepeatedTask.
 */
SedSubTask*
SedRepeatedTask::getSubTask(unsigned int n)
{
	return mSubTasks.get(n);
}


/*
 * Return the nth SubTask in the SedListOfSubTasks within this SedRepeatedTask.
 */
const SedSubTask*
SedRepeatedTask::getSubTask(unsigned int n) const
{
	return mSubTasks.get(n);
}


/*
 * Return a SubTask from the SedListOfSubTasks by id.
 */
SedSubTask*
SedRepeatedTask::getSubTask(const std::string& sid)
{
	return mSubTasks.get(sid);
}


/*
 * Return a SubTask from the SedListOfSubTasks by id.
 */
const SedSubTask*
SedRepeatedTask::getSubTask(const std::string& sid) const
{
	return mSubTasks.get(sid);
}


/**
 * Adds a copy the given "SedSubTask" to this SedRepeatedTask.
 *
 * @param sst; the SedSubTask object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedRepeatedTask::addSubTask(const SedSubTask* sst)
{
	if(sst == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mSubTasks.append(sst);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSubTask objects in this SedRepeatedTask.
 *
 * @return the number of SedSubTask objects in this SedRepeatedTask
 */
unsigned int 
SedRepeatedTask::getNumSubTasks() const
{
	return mSubTasks.size();
}

/**
 * Creates a new SedSubTask object, adds it to this SedRepeatedTasks
 * SedRepeatedTask and returns the SedSubTask object created. 
 *
 * @return a new SedSubTask object instance
 *
 * @see addSedSubTask(const SedSubTask* sst)
 */
SedSubTask* 
SedRepeatedTask::createSubTask()
{
	SedSubTask *temp = new SedSubTask();
	if (temp != NULL) mSubTasks.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedRepeatedTask::getElementName () const
{
	static const string name = "repeatedTask";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedRepeatedTask::createObject(XMLInputStream& stream)
{
	SedBase* object = SedTask::createObject(stream);

	const string& name   = stream.peek().getName();

	if (name == "listOfRanges")
	{
		object = &mRanges;
	}

	if (name == "listOfChanges")
	{
		object = &mTaskChanges;
	}

	if (name == "listOfSubTasks")
	{
		object = &mSubTasks;
	}

	connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedRepeatedTask::connectToChild ()
{
	SedTask::connectToChild();

	mRanges.connectToParent(this);
	mTaskChanges.connectToParent(this);
	mSubTasks.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedRepeatedTask::getTypeCode () const
{
	return SEDML_TASK_REPEATEDTASK;
}


/*
 * check if all the required attributes are set
 */
bool
SedRepeatedTask::hasRequiredAttributes () const
{
	bool allPresent = SedTask::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedRepeatedTask::hasRequiredElements () const
{
	bool allPresent = SedTask::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedRepeatedTask::writeElements (XMLOutputStream& stream) const
{
	SedTask::writeElements(stream);
	if (getNumRanges() > 0)
	{
		mRanges.write(stream);
	}
	if (getNumTaskChanges() > 0)
	{
		mTaskChanges.write(stream);
	}
	if (getNumSubTasks() > 0)
	{
		mSubTasks.write(stream);
	}
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedRepeatedTask::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedRepeatedTask::setSedDocument (SedDocument* d)
{
	SedTask::setSedDocument(d);
	mRanges.setSedDocument(d);
	mTaskChanges.setSedDocument(d);
	mSubTasks.setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedRepeatedTask::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedTask::addExpectedAttributes(attributes);

	attributes.add("range");
	attributes.add("resetModel");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedRepeatedTask::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedTask::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// rangeId SIdRef   ( use = "optional" )
	//
	assigned = attributes.readInto("range", mRangeId, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mRangeId.empty() == true)
		{
			logEmptyString(mRangeId, getLevel(), getVersion(), "<SedRepeatedTask>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mRangeId) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

	//
	// resetModel bool   ( use = "optional" )
	//
	mIsSetResetModel = attributes.readInto("resetModel", mResetModel, getErrorLog(), false);

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedRepeatedTask::writeAttributes (XMLOutputStream& stream) const
{
	SedTask::writeAttributes(stream);

	if (isSetRangeId() == true)
		stream.writeAttribute("range", getPrefix(), mRangeId);

	if (isSetResetModel() == true)
		stream.writeAttribute("resetModel", getPrefix(), mResetModel);

}


/** @endcond doxygen-libsedml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_create(unsigned int level, unsigned int version)
{
	return new SedRepeatedTask(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedRepeatedTask_free(SedRepeatedTask_t * srt)
{
	if (srt != NULL)
		delete srt;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_clone(SedRepeatedTask_t * srt)
{
	if (srt != NULL)
	{
		return static_cast<SedRepeatedTask_t*>(srt->clone());
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
SedRepeatedTask_getRangeId(SedRepeatedTask_t * srt)
{
	if (srt == NULL)
		return NULL;

	return srt->getRangeId().empty() ? NULL : safe_strdup(srt->getRangeId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_getResetModel(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->getResetModel()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetRangeId(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->isSetRangeId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetResetModel(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->isSetResetModel()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setRangeId(SedRepeatedTask_t * srt, const char * rangeId)
{
	return (srt != NULL) ? srt->setRangeId(rangeId) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setResetModel(SedRepeatedTask_t * srt, int resetModel)
{
	return (srt != NULL) ? srt->setResetModel(resetModel) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetRangeId(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? srt->unsetRangeId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetResetModel(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? srt->unsetResetModel() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedRepeatedTask_addRange(SedRepeatedTask_t * srt, SedRange_t * sr)
{
	return  (srt != NULL) ? srt->addRange(sr) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedUniformRange_t *
SedRepeatedTask_createUniformRange(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createUniformRange() : NULL;
}

LIBSEDML_EXTERN
SedVectorRange_t *
SedRepeatedTask_createVectorRange(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createVectorRange() : NULL;
}

LIBSEDML_EXTERN
SedFunctionalRange_t *
SedRepeatedTask_createFunctionalRange(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createFunctionalRange() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfRanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfRanges() : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_getRange(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getRange(n) : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_getRangeById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getRange(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumRanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumRanges() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_removeRange(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeRange(n) : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_removeRangeById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeRange(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedRepeatedTask_addTaskChange(SedRepeatedTask_t * srt, SedSetValue_t * ssv)
{
	return  (srt != NULL) ? srt->addTaskChange(ssv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_createTaskChange(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createTaskChange() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfTaskChanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfTaskChanges() : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_getTaskChange(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getTaskChange(n) : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_getTaskChangeById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getTaskChange(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumTaskChanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumTaskChanges() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_removeTaskChange(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeTaskChange(n) : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_removeTaskChangeById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeTaskChange(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedRepeatedTask_addSubTask(SedRepeatedTask_t * srt, SedSubTask_t * sst)
{
	return  (srt != NULL) ? srt->addSubTask(sst) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_createSubTask(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createSubTask() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfSubTasks(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfSubTasks() : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_getSubTask(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getSubTask(n) : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_getSubTaskById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getSubTask(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumSubTasks(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumSubTasks() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_removeSubTask(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeSubTask(n) : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_removeSubTaskById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeSubTask(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredAttributes(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredElements(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


