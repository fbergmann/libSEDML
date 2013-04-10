/**
 * @file:   SedDocument.cpp
 * @brief:  Implementation of the SedDocument class
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


#include <sedml/SedDocument.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedDocument with the given level, version, and package version.
 */
SedDocument::SedDocument (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mLevel (SEDML_INT_MAX)
	, mIsSetLevel (false)
	, mVersion (SEDML_INT_MAX)
	, mIsSetVersion (false)
	, mSimulation (level, version)
	, mModel (level, version)
	, mTask (level, version)
	, mDataGenerator (level, version)
	, mOutput (level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedDocument with the given SedNamespaces object.
 */
SedDocument::SedDocument (SedNamespaces* sedns)
	: SedBase(sedns)
	, mLevel (SEDML_INT_MAX)
	, mIsSetLevel (false)
	, mVersion (SEDML_INT_MAX)
	, mIsSetVersion (false)
	, mSimulation (sedns)
	, mModel (sedns)
	, mTask (sedns)
	, mDataGenerator (sedns)
	, mOutput (sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedDocument.
 */
SedDocument::SedDocument (const SedDocument& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mLevel  = orig.mLevel;
		mIsSetLevel  = orig.mIsSetLevel;
		mVersion  = orig.mVersion;
		mIsSetVersion  = orig.mIsSetVersion;
		mSimulation  = orig.mSimulation;
		mModel  = orig.mModel;
		mTask  = orig.mTask;
		mDataGenerator  = orig.mDataGenerator;
		mOutput  = orig.mOutput;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedDocument.
 */
SedDocument&
SedDocument::operator=(const SedDocument& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mLevel  = rhs.mLevel;
		mIsSetLevel  = rhs.mIsSetLevel;
		mVersion  = rhs.mVersion;
		mIsSetVersion  = rhs.mIsSetVersion;
		mSimulation  = rhs.mSimulation;
		mModel  = rhs.mModel;
		mTask  = rhs.mTask;
		mDataGenerator  = rhs.mDataGenerator;
		mOutput  = rhs.mOutput;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedDocument.
 */
SedDocument*
SedDocument::clone () const
{
	return new SedDocument(*this);
}


/*
 * Destructor for SedDocument.
 */
SedDocument::~SedDocument ()
{
}


/*
 * Returns the value of the "level" attribute of this SedDocument.
 */
const int
SedDocument::getLevel() const
{
	return mLevel;
}


/*
 * Returns the value of the "version" attribute of this SedDocument.
 */
const int
SedDocument::getVersion() const
{
	return mVersion;
}


/*
 * Returns true/false if level is set.
 */
bool
SedDocument::isSetLevel() const
{
	return mIsSetLevel;
}


/*
 * Returns true/false if version is set.
 */
bool
SedDocument::isSetVersion() const
{
	return mIsSetVersion;
}


/*
 * Sets level and returns value indicating success.
 */
int
SedDocument::setLevel(int level)
{
	mLevel = level;
	mIsSetLevel = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets version and returns value indicating success.
 */
int
SedDocument::setVersion(int version)
{
	mVersion = version;
	mIsSetVersion = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets level and returns value indicating success.
 */
int
SedDocument::unsetLevel()
{
	mLevel = SEDML_INT_MAX;
	mIsSetLevel = false;

	if (isSetLevel() == false)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets version and returns value indicating success.
 */
int
SedDocument::unsetVersion()
{
	mVersion = SEDML_INT_MAX;
	mIsSetVersion = false;

	if (isSetVersion() == false)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Returns the  "SedListOfSedSimulations" in this SedDocument object.
 */
const SedListOfSedSimulations*
SedDocument::getListOfSedSimulations() const
{
	return &mSimulation;
}


/*
 * Removes the nth SedSimulation from the SedListOfSedSimulations.
 */
SedSimulation*
SedDocument::removeSedSimulation(unsigned int n)
{
	return mSimulation.remove(n);
}


/*
 * Removes the a SedSimulation with given id from the SedListOfSedSimulations.
 */
SedSimulation*
SedDocument::removeSedSimulation(const std::string& sid)
{
	return mSimulation.remove(sid);
}


/*
 * Return the nth SedSimulation in the SedListOfSedSimulations within this SedDocument.
 */
SedSimulation*
SedDocument::getSedSimulation(unsigned int n)
{
	return mSimulation.get(n);
}


/*
 * Return the nth SedSimulation in the SedListOfSedSimulations within this SedDocument.
 */
const SedSimulation*
SedDocument::getSedSimulation(unsigned int n) const
{
	return mSimulation.get(n);
}


/*
 * Return a SedSimulation from the SedListOfSedSimulations by id.
 */
SedSimulation*
SedDocument::getSedSimulation(const std::string& sid)
{
	return mSimulation.get(sid);
}


/*
 * Return a SedSimulation from the SedListOfSedSimulations by id.
 */
const SedSimulation*
SedDocument::getSedSimulation(const std::string& sid) const
{
	return mSimulation.get(sid);
}


/**
 * Adds a copy the given "SedSimulation" to this SedDocument.
 *
 * @param ss; the SedSimulation object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedDocument::addSedSimulation(const SedSimulation* ss)
{
	if(ss == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mSimulation.append(ss);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedSimulation objects in this SedDocument.
 *
 * @return the number of SedSimulation objects in this SedDocument
 */
unsigned int 
SedDocument::getNumSedSimulations() const
{
	return mSimulation.size();
}

/**
 * Creates a new SedUniformTimeCourse object, adds it to this SedDocuments
 * SedDocument and returns the SedUniformTimeCourse object created. 
 *
 * @return a new SedUniformTimeCourse object instance
 *
 * @see addSedSimulation(const SedSimulation* ss)
 */
SedUniformTimeCourse* 
SedDocument::createSedUniformTimeCourse()
{
	SedUniformTimeCourse *temp = new SedUniformTimeCourse();
	if (temp != NULL) mSimulation.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSedModels" in this SedDocument object.
 */
const SedListOfSedModels*
SedDocument::getListOfSedModels() const
{
	return &mModel;
}


/*
 * Removes the nth SedModel from the SedListOfSedModels.
 */
SedModel*
SedDocument::removeSedModel(unsigned int n)
{
	return mModel.remove(n);
}


/*
 * Removes the a SedModel with given id from the SedListOfSedModels.
 */
SedModel*
SedDocument::removeSedModel(const std::string& sid)
{
	return mModel.remove(sid);
}


/*
 * Return the nth SedModel in the SedListOfSedModels within this SedDocument.
 */
SedModel*
SedDocument::getSedModel(unsigned int n)
{
	return mModel.get(n);
}


/*
 * Return the nth SedModel in the SedListOfSedModels within this SedDocument.
 */
const SedModel*
SedDocument::getSedModel(unsigned int n) const
{
	return mModel.get(n);
}


/*
 * Return a SedModel from the SedListOfSedModels by id.
 */
SedModel*
SedDocument::getSedModel(const std::string& sid)
{
	return mModel.get(sid);
}


/*
 * Return a SedModel from the SedListOfSedModels by id.
 */
const SedModel*
SedDocument::getSedModel(const std::string& sid) const
{
	return mModel.get(sid);
}


/**
 * Adds a copy the given "SedModel" to this SedDocument.
 *
 * @param sm; the SedModel object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedDocument::addSedModel(const SedModel* sm)
{
	if(sm == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mModel.append(sm);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedModel objects in this SedDocument.
 *
 * @return the number of SedModel objects in this SedDocument
 */
unsigned int 
SedDocument::getNumSedModels() const
{
	return mModel.size();
}

/**
 * Creates a new SedModel object, adds it to this SedDocuments
 * SedDocument and returns the SedModel object created. 
 *
 * @return a new SedModel object instance
 *
 * @see addSedModel(const SedModel* sm)
 */
SedModel* 
SedDocument::createSedModel()
{
	SedModel *temp = new SedModel();
	if (temp != NULL) mModel.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSedTasks" in this SedDocument object.
 */
const SedListOfSedTasks*
SedDocument::getListOfSedTasks() const
{
	return &mTask;
}


/*
 * Removes the nth SedTask from the SedListOfSedTasks.
 */
SedTask*
SedDocument::removeSedTask(unsigned int n)
{
	return mTask.remove(n);
}


/*
 * Removes the a SedTask with given id from the SedListOfSedTasks.
 */
SedTask*
SedDocument::removeSedTask(const std::string& sid)
{
	return mTask.remove(sid);
}


/*
 * Return the nth SedTask in the SedListOfSedTasks within this SedDocument.
 */
SedTask*
SedDocument::getSedTask(unsigned int n)
{
	return mTask.get(n);
}


/*
 * Return the nth SedTask in the SedListOfSedTasks within this SedDocument.
 */
const SedTask*
SedDocument::getSedTask(unsigned int n) const
{
	return mTask.get(n);
}


/*
 * Return a SedTask from the SedListOfSedTasks by id.
 */
SedTask*
SedDocument::getSedTask(const std::string& sid)
{
	return mTask.get(sid);
}


/*
 * Return a SedTask from the SedListOfSedTasks by id.
 */
const SedTask*
SedDocument::getSedTask(const std::string& sid) const
{
	return mTask.get(sid);
}


/**
 * Adds a copy the given "SedTask" to this SedDocument.
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
SedDocument::addSedTask(const SedTask* st)
{
	if(st == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mTask.append(st);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedTask objects in this SedDocument.
 *
 * @return the number of SedTask objects in this SedDocument
 */
unsigned int 
SedDocument::getNumSedTasks() const
{
	return mTask.size();
}

/**
 * Creates a new SedTask object, adds it to this SedDocuments
 * SedDocument and returns the SedTask object created. 
 *
 * @return a new SedTask object instance
 *
 * @see addSedTask(const SedTask* st)
 */
SedTask* 
SedDocument::createSedTask()
{
	SedTask *temp = new SedTask();
	if (temp != NULL) mTask.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSedDataGenerators" in this SedDocument object.
 */
const SedListOfSedDataGenerators*
SedDocument::getListOfSedDataGenerators() const
{
	return &mDataGenerator;
}


/*
 * Removes the nth SedDataGenerator from the SedListOfSedDataGenerators.
 */
SedDataGenerator*
SedDocument::removeSedDataGenerator(unsigned int n)
{
	return mDataGenerator.remove(n);
}


/*
 * Removes the a SedDataGenerator with given id from the SedListOfSedDataGenerators.
 */
SedDataGenerator*
SedDocument::removeSedDataGenerator(const std::string& sid)
{
	return mDataGenerator.remove(sid);
}


/*
 * Return the nth SedDataGenerator in the SedListOfSedDataGenerators within this SedDocument.
 */
SedDataGenerator*
SedDocument::getSedDataGenerator(unsigned int n)
{
	return mDataGenerator.get(n);
}


/*
 * Return the nth SedDataGenerator in the SedListOfSedDataGenerators within this SedDocument.
 */
const SedDataGenerator*
SedDocument::getSedDataGenerator(unsigned int n) const
{
	return mDataGenerator.get(n);
}


/*
 * Return a SedDataGenerator from the SedListOfSedDataGenerators by id.
 */
SedDataGenerator*
SedDocument::getSedDataGenerator(const std::string& sid)
{
	return mDataGenerator.get(sid);
}


/*
 * Return a SedDataGenerator from the SedListOfSedDataGenerators by id.
 */
const SedDataGenerator*
SedDocument::getSedDataGenerator(const std::string& sid) const
{
	return mDataGenerator.get(sid);
}


/**
 * Adds a copy the given "SedDataGenerator" to this SedDocument.
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
SedDocument::addSedDataGenerator(const SedDataGenerator* sdg)
{
	if(sdg == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mDataGenerator.append(sdg);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedDataGenerator objects in this SedDocument.
 *
 * @return the number of SedDataGenerator objects in this SedDocument
 */
unsigned int 
SedDocument::getNumSedDataGenerators() const
{
	return mDataGenerator.size();
}

/**
 * Creates a new SedDataGenerator object, adds it to this SedDocuments
 * SedDocument and returns the SedDataGenerator object created. 
 *
 * @return a new SedDataGenerator object instance
 *
 * @see addSedDataGenerator(const SedDataGenerator* sdg)
 */
SedDataGenerator* 
SedDocument::createSedDataGenerator()
{
	SedDataGenerator *temp = new SedDataGenerator();
	if (temp != NULL) mDataGenerator.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSedOutputs" in this SedDocument object.
 */
const SedListOfSedOutputs*
SedDocument::getListOfSedOutputs() const
{
	return &mOutput;
}


/*
 * Removes the nth SedOutput from the SedListOfSedOutputs.
 */
SedOutput*
SedDocument::removeSedOutput(unsigned int n)
{
	return mOutput.remove(n);
}


/*
 * Removes the a SedOutput with given id from the SedListOfSedOutputs.
 */
SedOutput*
SedDocument::removeSedOutput(const std::string& sid)
{
	return mOutput.remove(sid);
}


/*
 * Return the nth SedOutput in the SedListOfSedOutputs within this SedDocument.
 */
SedOutput*
SedDocument::getSedOutput(unsigned int n)
{
	return mOutput.get(n);
}


/*
 * Return the nth SedOutput in the SedListOfSedOutputs within this SedDocument.
 */
const SedOutput*
SedDocument::getSedOutput(unsigned int n) const
{
	return mOutput.get(n);
}


/*
 * Return a SedOutput from the SedListOfSedOutputs by id.
 */
SedOutput*
SedDocument::getSedOutput(const std::string& sid)
{
	return mOutput.get(sid);
}


/*
 * Return a SedOutput from the SedListOfSedOutputs by id.
 */
const SedOutput*
SedDocument::getSedOutput(const std::string& sid) const
{
	return mOutput.get(sid);
}


/**
 * Adds a copy the given "SedOutput" to this SedDocument.
 *
 * @param so; the SedOutput object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedDocument::addSedOutput(const SedOutput* so)
{
	if(so == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mOutput.append(so);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedOutput objects in this SedDocument.
 *
 * @return the number of SedOutput objects in this SedDocument
 */
unsigned int 
SedDocument::getNumSedOutputs() const
{
	return mOutput.size();
}

/**
 * Creates a new SedReport object, adds it to this SedDocuments
 * SedDocument and returns the SedReport object created. 
 *
 * @return a new SedReport object instance
 *
 * @see addSedOutput(const SedOutput* so)
 */
SedReport* 
SedDocument::createSedReport()
{
	SedReport *temp = new SedReport();
	if (temp != NULL) mOutput.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedPlot2D object, adds it to this SedDocuments
 * SedDocument and returns the SedPlot2D object created. 
 *
 * @return a new SedPlot2D object instance
 *
 * @see addSedOutput(const SedOutput* so)
 */
SedPlot2D* 
SedDocument::createSedPlot2D()
{
	SedPlot2D *temp = new SedPlot2D();
	if (temp != NULL) mOutput.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedPlot3D object, adds it to this SedDocuments
 * SedDocument and returns the SedPlot3D object created. 
 *
 * @return a new SedPlot3D object instance
 *
 * @see addSedOutput(const SedOutput* so)
 */
SedPlot3D* 
SedDocument::createSedPlot3D()
{
	SedPlot3D *temp = new SedPlot3D();
	if (temp != NULL) mOutput.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedDocument::getElementName () const
{
	static const string name = "sedML";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedDocument::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	SedBase::connectToChild();

	if (name == "listOfSimulations")
	{
		object = &mSimulation;
	}

	if (name == "listOfModels")
	{
		object = &mModel;
	}

	if (name == "listOfTasks")
	{
		object = &mTask;
	}

	if (name == "listOfDataGenerators")
	{
		object = &mDataGenerator;
	}

	if (name == "listOfOutputs")
	{
		object = &mOutput;
	}

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedDocument::connectToChild ()
{
	SedBase::connectToChild();

	mSimulation.connectToParent(this);
	mModel.connectToParent(this);
	mTask.connectToParent(this);
	mDataGenerator.connectToParent(this);
	mOutput.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedDocument::getTypeCode () const
{
	return SEDML_DOCUMENT;
}


/*
 * check if all the required attributes are set
 */
bool
SedDocument::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetLevel() == false)
		allPresent = false;

	if (isSetVersion() == false)
		allPresent = false;

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedDocument::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedDocument::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (getNumSedSimulations() > 0)
	{
		mSimulation.write(stream);
	}
	if (getNumSedModels() > 0)
	{
		mModel.write(stream);
	}
	if (getNumSedTasks() > 0)
	{
		mTask.write(stream);
	}
	if (getNumSedDataGenerators() > 0)
	{
		mDataGenerator.write(stream);
	}
	if (getNumSedOutputs() > 0)
	{
		mOutput.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedDocument::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedDocument::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedDocument::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("level");
	attributes.add("version");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedDocument::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedBase::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

	//
	// level int   ( use = "required" )
	//
	mIsSetLevel = attributes.readInto("level", mLevel, getErrorLog(), true);

	//
	// version int   ( use = "required" )
	//
	mIsSetVersion = attributes.readInto("version", mVersion, getErrorLog(), true);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedDocument::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetLevel() == true)
		stream.writeAttribute("level", getPrefix(), mLevel);

	if (isSetVersion() == true)
		stream.writeAttribute("version", getPrefix(), mVersion);

}


/** @endcond doxygen-libsbml-internal */




/*
 * @return the nth error encountered during the parse of this
 * SedDocument or @c NULL if n > getNumErrors() - 1.
 */
const SedError*
SedDocument::getError (unsigned int n) const
{
  return mErrorLog.getError(n);
}


/*
 * @return the number of errors encountered during the parse of this
 * SedDocument.
 */
unsigned int
SedDocument::getNumErrors () const
{
  return mErrorLog.getNumErrors();
}


unsigned int 
SedDocument::getNumErrors (unsigned int severity) const
{
  return getErrorLog()->getNumFailsWithSeverity(severity);
}


/*
 * @return the SedErrorLog used to log errors during while reading and
 * validating Sed.
 */
SedErrorLog*
SedDocument::getErrorLog ()
{
  return &mErrorLog;
}


/*
 * @return the SedErrorLog used to log errors during while reading and
 * validating Sed.
 */
const SedErrorLog*
SedDocument::getErrorLog () const
{
  return &mErrorLog;
}

/*
 *
 * Subclasses should override this method to write their xmlns attriubutes
 * (if any) to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 *
 */
void
SedDocument::writeXMLNS (XMLOutputStream& stream) const
{
  // need to check that we have indeed a namespace set!
  XMLNamespaces * thisNs = this->getNamespaces();

  // the sbml namespace is missing - add it
  if (thisNs == NULL)
  {
    XMLNamespaces xmlns;
    xmlns.add(SEDML_XMLNS_L1);

    mSedNamespaces->setNamespaces(&xmlns);
    thisNs = getNamespaces();
  }
  else if (thisNs->getLength() == 0)
  {
     thisNs->add(SEDML_XMLNS_L1);
  }
  else
  {
    // check that there is an sbml namespace
    std::string sedmlURI = SedNamespaces::getSedNamespaceURI(mLevel, mVersion);
    std::string sedmlPrefix = thisNs->getPrefix(sedmlURI);
    if (thisNs->hasNS(sedmlURI, sedmlPrefix) == false)
    {
      // the sbml ns is not present
      std::string other = thisNs->getURI(sedmlPrefix);
      if (other.empty() == false)
      {
        // there is another ns with the prefix that the sbml ns expects to have
        //remove the this ns, add the sbml ns and 
        //add the new ns with a new prefix
        thisNs->remove(sedmlPrefix);
        thisNs->add(sedmlURI, sedmlPrefix);
        thisNs->add(other, "addedPrefix");
      }
      else
      {
        thisNs->add(sedmlURI, sedmlPrefix);
      }
    }
  }

  XMLNamespaces * xmlns = thisNs->clone();
  if (xmlns != NULL) 
  {
    stream << *(xmlns);
    delete xmlns;
  }
}

/*
  * @return the Namespaces associated with this SBML object
  */
XMLNamespaces* 
SedDocument::getNamespaces() const
{
  return mSedNamespaces->getNamespaces();
}/**
 * write comments
 */
LIBSEDML_EXTERN
SedDocument_t *
SedDocument_create(unsigned int level, unsigned int version)
{
	return new SedDocument(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedDocument_free(SedDocument_t * sd)
{
	if (sd != NULL)
		delete sd;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDocument_t *
SedDocument_clone(SedDocument_t * sd)
{
	if (sd != NULL)
	{
		return static_cast<SedDocument_t*>(sd->clone());
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
SedDocument_getLevel(SedDocument_t * sd)
{
	return (sd != NULL) ? sd->getLevel() : SEDML_INT_MAX;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_getVersion(SedDocument_t * sd)
{
	return (sd != NULL) ? sd->getVersion() : SEDML_INT_MAX;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_isSetLevel(SedDocument_t * sd)
{
	return (sd != NULL) ? static_cast<int>(sd->isSetLevel()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_isSetVersion(SedDocument_t * sd)
{
	return (sd != NULL) ? static_cast<int>(sd->isSetVersion()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_setLevel(SedDocument_t * sd, int level)
{
	return (sd != NULL) ? sd->setLevel(level) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_setVersion(SedDocument_t * sd, int version)
{
	return (sd != NULL) ? sd->setVersion(version) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_unsetLevel(SedDocument_t * sd)
{
	return (sd != NULL) ? sd->unsetLevel() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_unsetVersion(SedDocument_t * sd)
{
	return (sd != NULL) ? sd->unsetVersion() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedDocument_addSedSimulation(SedDocument_t * sd, SedSimulation_t * ss)
{
	return  (sd != NULL) ? sd->addSedSimulation(ss) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedUniformTimeCourse_t *
SedDocument_createSedUniformTimeCourse(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->createSedUniformTimeCourse() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDocument_getSedListOfSedSimulations(SedDocument_t * sd)
{
	return  (sd != NULL) ? (SedListOf_t *)sd->getListOfSedSimulations() : NULL;
}

LIBSEDML_EXTERN
SedSimulation_t *
SedDocument_getSedSimulation(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->getSedSimulation(n) : NULL;
}

LIBSEDML_EXTERN
SedSimulation_t *
SedDocument_getSedSimulationById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->getSedSimulation(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDocument_getNumSedSimulations(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->getNumSedSimulations() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedSimulation_t *
SedDocument_removeSedSimulation(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->removeSedSimulation(n) : NULL;
}

LIBSEDML_EXTERN
SedSimulation_t *
SedDocument_removeSedSimulationById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->removeSedSimulation(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedDocument_addSedModel(SedDocument_t * sd, SedModel_t * sm)
{
	return  (sd != NULL) ? sd->addSedModel(sm) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedModel_t *
SedDocument_createSedModel(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->createSedModel() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDocument_getSedListOfSedModels(SedDocument_t * sd)
{
	return  (sd != NULL) ? (SedListOf_t *)sd->getListOfSedModels() : NULL;
}

LIBSEDML_EXTERN
SedModel_t *
SedDocument_getSedModel(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->getSedModel(n) : NULL;
}

LIBSEDML_EXTERN
SedModel_t *
SedDocument_getSedModelById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->getSedModel(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDocument_getNumSedModels(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->getNumSedModels() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedModel_t *
SedDocument_removeSedModel(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->removeSedModel(n) : NULL;
}

LIBSEDML_EXTERN
SedModel_t *
SedDocument_removeSedModelById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->removeSedModel(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedDocument_addSedTask(SedDocument_t * sd, SedTask_t * st)
{
	return  (sd != NULL) ? sd->addSedTask(st) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedTask_t *
SedDocument_createSedTask(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->createSedTask() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDocument_getSedListOfSedTasks(SedDocument_t * sd)
{
	return  (sd != NULL) ? (SedListOf_t *)sd->getListOfSedTasks() : NULL;
}

LIBSEDML_EXTERN
SedTask_t *
SedDocument_getSedTask(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->getSedTask(n) : NULL;
}

LIBSEDML_EXTERN
SedTask_t *
SedDocument_getSedTaskById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->getSedTask(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDocument_getNumSedTasks(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->getNumSedTasks() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedTask_t *
SedDocument_removeSedTask(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->removeSedTask(n) : NULL;
}

LIBSEDML_EXTERN
SedTask_t *
SedDocument_removeSedTaskById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->removeSedTask(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedDocument_addSedDataGenerator(SedDocument_t * sd, SedDataGenerator_t * sdg)
{
	return  (sd != NULL) ? sd->addSedDataGenerator(sdg) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedDataGenerator_t *
SedDocument_createSedDataGenerator(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->createSedDataGenerator() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDocument_getSedListOfSedDataGenerators(SedDocument_t * sd)
{
	return  (sd != NULL) ? (SedListOf_t *)sd->getListOfSedDataGenerators() : NULL;
}

LIBSEDML_EXTERN
SedDataGenerator_t *
SedDocument_getSedDataGenerator(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->getSedDataGenerator(n) : NULL;
}

LIBSEDML_EXTERN
SedDataGenerator_t *
SedDocument_getSedDataGeneratorById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->getSedDataGenerator(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDocument_getNumSedDataGenerators(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->getNumSedDataGenerators() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedDataGenerator_t *
SedDocument_removeSedDataGenerator(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->removeSedDataGenerator(n) : NULL;
}

LIBSEDML_EXTERN
SedDataGenerator_t *
SedDocument_removeSedDataGeneratorById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->removeSedDataGenerator(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedDocument_addSedOutput(SedDocument_t * sd, SedOutput_t * so)
{
	return  (sd != NULL) ? sd->addSedOutput(so) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedReport_t *
SedDocument_createSedReport(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->createSedReport() : NULL;
}

LIBSEDML_EXTERN
SedPlot2D_t *
SedDocument_createSedPlot2D(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->createSedPlot2D() : NULL;
}

LIBSEDML_EXTERN
SedPlot3D_t *
SedDocument_createSedPlot3D(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->createSedPlot3D() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedDocument_getSedListOfSedOutputs(SedDocument_t * sd)
{
	return  (sd != NULL) ? (SedListOf_t *)sd->getListOfSedOutputs() : NULL;
}

LIBSEDML_EXTERN
SedOutput_t *
SedDocument_getSedOutput(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->getSedOutput(n) : NULL;
}

LIBSEDML_EXTERN
SedOutput_t *
SedDocument_getSedOutputById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->getSedOutput(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedDocument_getNumSedOutputs(SedDocument_t * sd)
{
	return  (sd != NULL) ? sd->getNumSedOutputs() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedOutput_t *
SedDocument_removeSedOutput(SedDocument_t * sd, unsigned int n)
{
	return  (sd != NULL) ? sd->removeSedOutput(n) : NULL;
}

LIBSEDML_EXTERN
SedOutput_t *
SedDocument_removeSedOutputById(SedDocument_t * sd, const char * sid)
{
	return  (sd != NULL) ? sd->removeSedOutput(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_hasRequiredAttributes(SedDocument_t * sd)
{
	return (sd != NULL) ? static_cast<int>(sd->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDocument_hasRequiredElements(SedDocument_t * sd)
{
	return (sd != NULL) ? static_cast<int>(sd->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


