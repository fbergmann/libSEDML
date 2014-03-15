/**
 * @file:   SedSubTask.cpp
 * @brief:  Implementation of the SedSubTask class
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


#include <sedml/SedSubTask.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedSubTask with the given level, version, and package version.
 */
SedSubTask::SedSubTask (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mOrder (SEDML_INT_MAX)
	, mIsSetOrder (false)
	, mTask ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSubTask with the given SedNamespaces object.
 */
SedSubTask::SedSubTask (SedNamespaces* sedns)
	: SedBase(sedns)
	, mOrder (SEDML_INT_MAX)
	, mIsSetOrder (false)
	, mTask ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedSubTask.
 */
SedSubTask::SedSubTask (const SedSubTask& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mOrder  = orig.mOrder;
		mIsSetOrder  = orig.mIsSetOrder;
		mTask  = orig.mTask;
	}
}


/*
 * Assignment for SedSubTask.
 */
SedSubTask&
SedSubTask::operator=(const SedSubTask& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mOrder  = rhs.mOrder;
		mIsSetOrder  = rhs.mIsSetOrder;
		mTask  = rhs.mTask;
	}
	return *this;
}


/*
 * Clone for SedSubTask.
 */
SedSubTask*
SedSubTask::clone () const
{
	return new SedSubTask(*this);
}


/*
 * Destructor for SedSubTask.
 */
SedSubTask::~SedSubTask ()
{
}


/*
 * Returns the value of the "order" attribute of this SedSubTask.
 */
const int
SedSubTask::getOrder() const
{
	return mOrder;
}


/*
 * Returns the value of the "task" attribute of this SedSubTask.
 */
const std::string&
SedSubTask::getTask() const
{
	return mTask;
}


/*
 * Returns true/false if order is set.
 */
bool
SedSubTask::isSetOrder() const
{
	return mIsSetOrder;
}


/*
 * Returns true/false if task is set.
 */
bool
SedSubTask::isSetTask() const
{
	return (mTask.empty() == false);
}


/*
 * Sets order and returns value indicating success.
 */
int
SedSubTask::setOrder(int order)
{
	mOrder = order;
	mIsSetOrder = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets task and returns value indicating success.
 */
int
SedSubTask::setTask(const std::string& task)
{
	if (&(task) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(task)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mTask = task;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets order and returns value indicating success.
 */
int
SedSubTask::unsetOrder()
{
	mOrder = SEDML_INT_MAX;
	mIsSetOrder = false;

	if (isSetOrder() == false)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets task and returns value indicating success.
 */
int
SedSubTask::unsetTask()
{
	mTask.erase();

	if (mTask.empty() == true)
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
SedSubTask::getElementName () const
{
	static const string name = "subTask";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedSubTask::getTypeCode () const
{
	return SEDML_TASK_SUBTASK;
}


/*
 * check if all the required attributes are set
 */
bool
SedSubTask::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetOrder() == false)
		allPresent = false;

	if (isSetTask() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedSubTask::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedSubTask::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedSubTask::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedSubTask::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("order");
	attributes.add("task");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedSubTask::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// order int   ( use = "required" )
	//
	mIsSetOrder = attributes.readInto("order", mOrder, getErrorLog(), true);

	//
	// task SIdRef   ( use = "required" )
	//
	assigned = attributes.readInto("task", mTask, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mTask.empty() == true)
		{
			logEmptyString(mTask, getLevel(), getVersion(), "<SedSubTask>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mTask) == false)
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
SedSubTask::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetOrder() == true)
		stream.writeAttribute("order", getPrefix(), mOrder);

	if (isSetTask() == true)
		stream.writeAttribute("task", getPrefix(), mTask);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor 
 */
SedListOfSubTasks::SedListOfSubTasks(unsigned int level, 
	                  unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSubTasks::SedListOfSubTasks(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSubTasks 
 */
SedListOfSubTasks* 
SedListOfSubTasks::clone () const
 {
	return new SedListOfSubTasks(*this);
}


/*
 * Get a SubTask from the SedListOfSubTasks by index.
*/
SedSubTask*
SedListOfSubTasks::get(unsigned int n)
{
	return static_cast<SedSubTask*>(SedListOf::get(n));
}


/*
 * Get a SubTask from the SedListOfSubTasks by index.
 */
const SedSubTask*
SedListOfSubTasks::get(unsigned int n) const
{
	return static_cast<const SedSubTask*>(SedListOf::get(n));
}


/*
 * Get a SubTask from the SedListOfSubTasks by id.
 */
SedSubTask*
SedListOfSubTasks::get(const std::string& sid)
{
	return const_cast<SedSubTask*>(
	  static_cast<const SedListOfSubTasks&>(*this).get(sid));
}


/*
 * Get a SubTask from the SedListOfSubTasks by id.
 */
const SedSubTask*
SedListOfSubTasks::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedSubTask>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedSubTask*> (*result);
}


/**
 * Adds a copy the given "SedSubTask" to this SedListOfSubTasks.
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
SedListOfSubTasks::addSubTask(const SedSubTask* sst)
{
	if(sst == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sst);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSubTask objects in this SedListOfSubTasks.
 *
 * @return the number of SedSubTask objects in this SedListOfSubTasks
 */
unsigned int 
SedListOfSubTasks::getNumSubTasks() const
{
	return size();
}

/**
 * Creates a new SedSubTask object, adds it to this SedListOfSubTaskss
 * SedSubTask and returns the SedSubTask object created. 
 *
 * @return a new SedSubTask object instance
 *
 * @see addSedSubTask(const SedSubTask* sst)
 */
SedSubTask* 
SedListOfSubTasks::createSubTask()
{
	SedSubTask *temp = new SedSubTask();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth SubTask from this SedListOfSubTasks
 */
SedSubTask*
SedListOfSubTasks::remove(unsigned int n)
{
	return static_cast<SedSubTask*>(SedListOf::remove(n));
}


/*
 * Removes the SubTask from this SedListOfSubTasks with the given identifier
 */
SedSubTask*
SedListOfSubTasks::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedSubTask>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedSubTask*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSubTasks::getElementName () const
{
	static const string name = "listOfSubTasks";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSubTasks::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSubTasks::getItemTypeCode () const
{
	return SEDML_TASK_SUBTASK;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedSubTask in this SedListOfSubTasks
 */
SedBase*
SedListOfSubTasks::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "subTask")
	{
		object = new SedSubTask(getSedNamespaces());
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
SedListOfSubTasks::writeXMLNS(XMLOutputStream& stream) const
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
SedSubTask_t *
SedSubTask_create(unsigned int level, unsigned int version)
{
	return new SedSubTask(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedSubTask_free(SedSubTask_t * sst)
{
	if (sst != NULL)
		delete sst;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSubTask_t *
SedSubTask_clone(SedSubTask_t * sst)
{
	if (sst != NULL)
	{
		return static_cast<SedSubTask_t*>(sst->clone());
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
int
SedSubTask_getOrder(SedSubTask_t * sst)
{
	return (sst != NULL) ? sst->getOrder() : SEDML_INT_MAX;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedSubTask_getTask(SedSubTask_t * sst)
{
	if (sst == NULL)
		return NULL;

	return sst->getTask().empty() ? NULL : safe_strdup(sst->getTask().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSubTask_isSetOrder(SedSubTask_t * sst)
{
	return (sst != NULL) ? static_cast<int>(sst->isSetOrder()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSubTask_isSetTask(SedSubTask_t * sst)
{
	return (sst != NULL) ? static_cast<int>(sst->isSetTask()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSubTask_setOrder(SedSubTask_t * sst, int order)
{
	return (sst != NULL) ? sst->setOrder(order) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSubTask_setTask(SedSubTask_t * sst, const char * task)
{
	return (sst != NULL) ? sst->setTask(task) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSubTask_unsetOrder(SedSubTask_t * sst)
{
	return (sst != NULL) ? sst->unsetOrder() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSubTask_unsetTask(SedSubTask_t * sst)
{
	return (sst != NULL) ? sst->unsetTask() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedSubTask_hasRequiredAttributes(SedSubTask_t * sst)
{
	return (sst != NULL) ? static_cast<int>(sst->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSubTask_t *
SedListOfSubTasks_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSubTasks *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedSubTask_t *
SedListOfSubTasks_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSubTasks *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


