/**
 * @file:   SedRepeatedTask.cpp
 * @brief:  Implementation of the SedRepeatedTask class
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


#include <sedml/SedRepeatedTask.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedRepeatedTask with the given level, version, and package version.
 */
SedRepeatedTask::SedRepeatedTask (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mRange ("")
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
	: SedBase(sedns)
	, mRange ("")
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
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mRange  = orig.mRange;
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
		SedBase::operator=(rhs);
		mRange  = rhs.mRange;
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
 * Returns the value of the "range" attribute of this SedRepeatedTask.
 */
const std::string&
SedRepeatedTask::getRange() const
{
	return mRange;
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
 * Returns true/false if range is set.
 */
bool
SedRepeatedTask::isSetRange() const
{
	return (mRange.empty() == false);
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
 * Sets range and returns value indicating success.
 */
int
SedRepeatedTask::setRange(const std::string& range)
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
 * Unsets range and returns value indicating success.
 */
int
SedRepeatedTask::unsetRange()
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
SedRepeatedTask::getListOfRangess() const
{
	return &mRanges;
}


/*
 * Removes the nth Ranges from the SedListOfRanges.
 */
SedRange*
SedRepeatedTask::removeRanges(unsigned int n)
{
	return mRanges.remove(n);
}


/*
 * Removes the a Ranges with given id from the SedListOfRanges.
 */
SedRange*
SedRepeatedTask::removeRanges(const std::string& sid)
{
	return mRanges.remove(sid);
}


/*
 * Return the nth Ranges in the SedListOfRanges within this SedRepeatedTask.
 */
SedRange*
SedRepeatedTask::getRanges(unsigned int n)
{
	return mRanges.get(n);
}


/*
 * Return the nth Ranges in the SedListOfRanges within this SedRepeatedTask.
 */
const SedRange*
SedRepeatedTask::getRanges(unsigned int n) const
{
	return mRanges.get(n);
}


/*
 * Return a Ranges from the SedListOfRanges by id.
 */
SedRange*
SedRepeatedTask::getRanges(const std::string& sid)
{
	return mRanges.get(sid);
}


/*
 * Return a Ranges from the SedListOfRanges by id.
 */
const SedRange*
SedRepeatedTask::getRanges(const std::string& sid) const
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
SedRepeatedTask::addRanges(const SedRange* sr)
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
SedRepeatedTask::getNumRangess() const
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
SedRepeatedTask::getListOfTaskChangess() const
{
	return &mTaskChanges;
}


/*
 * Removes the nth TaskChanges from the SedListOfTaskChanges.
 */
SedSetValue*
SedRepeatedTask::removeTaskChanges(unsigned int n)
{
	return mTaskChanges.remove(n);
}


/*
 * Removes the a TaskChanges with given id from the SedListOfTaskChanges.
 */
SedSetValue*
SedRepeatedTask::removeTaskChanges(const std::string& sid)
{
	return mTaskChanges.remove(sid);
}


/*
 * Return the nth TaskChanges in the SedListOfTaskChanges within this SedRepeatedTask.
 */
SedSetValue*
SedRepeatedTask::getTaskChanges(unsigned int n)
{
	return mTaskChanges.get(n);
}


/*
 * Return the nth TaskChanges in the SedListOfTaskChanges within this SedRepeatedTask.
 */
const SedSetValue*
SedRepeatedTask::getTaskChanges(unsigned int n) const
{
	return mTaskChanges.get(n);
}


/*
 * Return a TaskChanges from the SedListOfTaskChanges by id.
 */
SedSetValue*
SedRepeatedTask::getTaskChanges(const std::string& sid)
{
	return mTaskChanges.get(sid);
}


/*
 * Return a TaskChanges from the SedListOfTaskChanges by id.
 */
const SedSetValue*
SedRepeatedTask::getTaskChanges(const std::string& sid) const
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
SedRepeatedTask::addTaskChanges(const SedSetValue* ssv)
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
SedRepeatedTask::getNumTaskChangess() const
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
SedRepeatedTask::createTaskChanges()
{
	SedSetValue *temp = new SedSetValue();
	if (temp != NULL) mTaskChanges.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSubTasks" in this SedRepeatedTask object.
 */
const SedListOfSubTasks*
SedRepeatedTask::getListOfSubTaskss() const
{
	return &mSubTasks;
}


/*
 * Removes the nth SubTasks from the SedListOfSubTasks.
 */
SedSubTask*
SedRepeatedTask::removeSubTasks(unsigned int n)
{
	return mSubTasks.remove(n);
}


/*
 * Removes the a SubTasks with given id from the SedListOfSubTasks.
 */
SedSubTask*
SedRepeatedTask::removeSubTasks(const std::string& sid)
{
	return mSubTasks.remove(sid);
}


/*
 * Return the nth SubTasks in the SedListOfSubTasks within this SedRepeatedTask.
 */
SedSubTask*
SedRepeatedTask::getSubTasks(unsigned int n)
{
	return mSubTasks.get(n);
}


/*
 * Return the nth SubTasks in the SedListOfSubTasks within this SedRepeatedTask.
 */
const SedSubTask*
SedRepeatedTask::getSubTasks(unsigned int n) const
{
	return mSubTasks.get(n);
}


/*
 * Return a SubTasks from the SedListOfSubTasks by id.
 */
SedSubTask*
SedRepeatedTask::getSubTasks(const std::string& sid)
{
	return mSubTasks.get(sid);
}


/*
 * Return a SubTasks from the SedListOfSubTasks by id.
 */
const SedSubTask*
SedRepeatedTask::getSubTasks(const std::string& sid) const
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
SedRepeatedTask::addSubTasks(const SedSubTask* sst)
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
SedRepeatedTask::getNumSubTaskss() const
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
SedRepeatedTask::createSubTasks()
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
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	if (name == "listOfRangess")
	{
		object = &mRanges;
	}

	if (name == "listOfTaskChangess")
	{
		object = &mTaskChanges;
	}

	if (name == "listOfSubTaskss")
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
	SedBase::connectToChild();

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
	bool allPresent = true;

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedRepeatedTask::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedRepeatedTask::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (getNumRangess() > 0)
	{
		mRanges.write(stream);
	}
	if (getNumTaskChangess() > 0)
	{
		mTaskChanges.write(stream);
	}
	if (getNumSubTaskss() > 0)
	{
		mSubTasks.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedRepeatedTask::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedRepeatedTask::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
	mRanges.setSedDocument(d);
	mTaskChanges.setSedDocument(d);
	mSubTasks.setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedRepeatedTask::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("range");
	attributes.add("resetModel");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedRepeatedTask::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mRange, getLevel(), getVersion(), "<SedRepeatedTask>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mRange) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

	//
	// resetModel bool   ( use = "optional" )
	//
	mIsSetResetModel = attributes.readInto("resetModel", mResetModel, getErrorLog(), false);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedRepeatedTask::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetRange() == true)
		stream.writeAttribute("range", getPrefix(), mRange);

	if (isSetResetModel() == true)
		stream.writeAttribute("resetModel", getPrefix(), mResetModel);

}


/** @endcond doxygen-libsbml-internal */


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
SedRepeatedTask_getRange(SedRepeatedTask_t * srt)
{
	if (srt == NULL)
		return NULL;

	return srt->getRange().empty() ? NULL : safe_strdup(srt->getRange().c_str());
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
SedRepeatedTask_isSetRange(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? static_cast<int>(srt->isSetRange()) : 0;
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
SedRepeatedTask_setRange(SedRepeatedTask_t * srt, const char * range)
{
	return (srt != NULL) ? srt->setRange(range) : LIBSEDML_INVALID_OBJECT;
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
SedRepeatedTask_unsetRange(SedRepeatedTask_t * srt)
{
	return (srt != NULL) ? srt->unsetRange() : LIBSEDML_INVALID_OBJECT;
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
SedRepeatedTask_addRanges(SedRepeatedTask_t * srt, SedRange_t * sr)
{
	return  (srt != NULL) ? srt->addRanges(sr) : LIBSBML_INVALID_OBJECT;
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
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfRangess() : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_getRanges(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getRanges(n) : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_getRangesById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getRanges(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumRangess(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumRangess() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_removeRanges(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeRanges(n) : NULL;
}

LIBSEDML_EXTERN
SedRange_t *
SedRepeatedTask_removeRangesById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeRanges(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedRepeatedTask_addTaskChanges(SedRepeatedTask_t * srt, SedSetValue_t * ssv)
{
	return  (srt != NULL) ? srt->addTaskChanges(ssv) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_createTaskChanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createTaskChanges() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfTaskChanges(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfTaskChangess() : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_getTaskChanges(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getTaskChanges(n) : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_getTaskChangesById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getTaskChanges(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumTaskChangess(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumTaskChangess() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_removeTaskChanges(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeTaskChanges(n) : NULL;
}

LIBSEDML_EXTERN
SedSetValue_t *
SedRepeatedTask_removeTaskChangesById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeTaskChanges(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedRepeatedTask_addSubTasks(SedRepeatedTask_t * srt, SedSubTask_t * sst)
{
	return  (srt != NULL) ? srt->addSubTasks(sst) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_createSubTasks(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->createSubTasks() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedRepeatedTask_getSedListOfSubTasks(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? (SedListOf_t *)srt->getListOfSubTaskss() : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_getSubTasks(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->getSubTasks(n) : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_getSubTasksById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->getSubTasks(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedRepeatedTask_getNumSubTaskss(SedRepeatedTask_t * srt)
{
	return  (srt != NULL) ? srt->getNumSubTaskss() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_removeSubTasks(SedRepeatedTask_t * srt, unsigned int n)
{
	return  (srt != NULL) ? srt->removeSubTasks(n) : NULL;
}

LIBSEDML_EXTERN
SedSubTask_t *
SedRepeatedTask_removeSubTasksById(SedRepeatedTask_t * srt, const char * sid)
{
	return  (srt != NULL) ? srt->removeSubTasks(sid) : NULL;
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


