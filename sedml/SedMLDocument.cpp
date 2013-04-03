/**
 * @file:   SedMLDocument.cpp
 * @brief:  Implementation of the SedMLDocument class
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


#include <sedml/SedMLDocument.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedMLDocument with the given level, version, and package version.
 */
SedMLDocument::SedMLDocument (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mLevel (SEDML_INT_MAX)
	, mIsSetLevel (false)
	, mVersion (SEDML_INT_MAX)
	, mIsSetVersion (false)
	, mModel (level, version)
	, mSimulation (level, version)
	, mTask (level, version)
	, mDataGenerator (level, version)
	, mOutput (level, version)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedMLDocument with the given SedMLNamespaces object.
 */
SedMLDocument::SedMLDocument (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mLevel (SEDML_INT_MAX)
	, mIsSetLevel (false)
	, mVersion (SEDML_INT_MAX)
	, mIsSetVersion (false)
	, mModel (sedmlns)
	, mSimulation (sedmlns)
	, mTask (sedmlns)
	, mDataGenerator (sedmlns)
	, mOutput (sedmlns)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedMLDocument.
 */
SedMLDocument::SedMLDocument (const SedMLDocument& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mLevel  = orig.mLevel;
		mIsSetLevel  = orig.mIsSetLevel;
		mVersion  = orig.mVersion;
		mIsSetVersion  = orig.mIsSetVersion;
		mModel  = orig.mModel;
		mSimulation  = orig.mSimulation;
		mTask  = orig.mTask;
		mDataGenerator  = orig.mDataGenerator;
		mOutput  = orig.mOutput;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedMLDocument.
 */
SedMLDocument&
SedMLDocument::operator=(const SedMLDocument& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mLevel  = rhs.mLevel;
		mIsSetLevel  = rhs.mIsSetLevel;
		mVersion  = rhs.mVersion;
		mIsSetVersion  = rhs.mIsSetVersion;
		mModel  = rhs.mModel;
		mSimulation  = rhs.mSimulation;
		mTask  = rhs.mTask;
		mDataGenerator  = rhs.mDataGenerator;
		mOutput  = rhs.mOutput;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedMLDocument.
 */
SedMLDocument*
SedMLDocument::clone () const
{
	return new SedMLDocument(*this);
}


/*
 * Destructor for SedMLDocument.
 */
SedMLDocument::~SedMLDocument ()
{
}


/*
 * Returns the value of the "level" attribute of this SedMLDocument.
 */
const int
SedMLDocument::getLevel() const
{
	return mLevel;
}


/*
 * Returns the value of the "version" attribute of this SedMLDocument.
 */
const int
SedMLDocument::getVersion() const
{
	return mVersion;
}


/*
 * Returns true/false if level is set.
 */
bool
SedMLDocument::isSetLevel() const
{
	return mIsSetLevel;
}


/*
 * Returns true/false if version is set.
 */
bool
SedMLDocument::isSetVersion() const
{
	return mIsSetVersion;
}


/*
 * Sets level and returns value indicating success.
 */
int
SedMLDocument::setLevel(int level)
{
	mLevel = level;
	mIsSetLevel = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets version and returns value indicating success.
 */
int
SedMLDocument::setVersion(int version)
{
	mVersion = version;
	mIsSetVersion = true;
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets level and returns value indicating success.
 */
int
SedMLDocument::unsetLevel()
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
SedMLDocument::unsetVersion()
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
 * Returns the  "SedListOfSedMLModels" in this SedMLDocument object.
 */
const SedListOfSedMLModels*
SedMLDocument::getListOfSedMLModels() const
{
	return &mModel;
}


/*
 * Removes the nth SedMLModel from the SedListOfSedMLModels.
 */
SedMLModel*
SedMLDocument::removeSedMLModel(unsigned int n)
{
	return mModel.remove(n);
}


/*
 * Removes the a SedMLModel with given id from the SedListOfSedMLModels.
 */
SedMLModel*
SedMLDocument::removeSedMLModel(const std::string& sid)
{
	return mModel.remove(sid);
}


/*
 * Return the nth SedMLModel in the SedListOfSedMLModels within this SedMLDocument.
 */
SedMLModel*
SedMLDocument::getSedMLModel(unsigned int n)
{
	return mModel.get(n);
}


/*
 * Return the nth SedMLModel in the SedListOfSedMLModels within this SedMLDocument.
 */
const SedMLModel*
SedMLDocument::getSedMLModel(unsigned int n) const
{
	return mModel.get(n);
}


/*
 * Return a SedMLModel from the SedListOfSedMLModels by id.
 */
SedMLModel*
SedMLDocument::getSedMLModel(const std::string& sid)
{
	return mModel.get(sid);
}


/*
 * Return a SedMLModel from the SedListOfSedMLModels by id.
 */
const SedMLModel*
SedMLDocument::getSedMLModel(const std::string& sid) const
{
	return mModel.get(sid);
}


/**
 * Adds a copy the given "SedMLModel" to this SedMLDocument.
 *
 * @param smlm; the SedMLModel object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedMLDocument::addSedMLModel(const SedMLModel* smlm)
{
	if(smlm == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mModel.append(smlm);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedMLModel objects in this SedMLDocument.
 *
 * @return the number of SedMLModel objects in this SedMLDocument
 */
unsigned int 
SedMLDocument::getNumSedMLModels() const
{
	return mModel.size();
}

/**
 * Creates a new SedMLModel object, adds it to this SedMLDocuments
 * SedMLDocument and returns the SedMLModel object created. 
 *
 * @return a new SedMLModel object instance
 *
 * @see addSedMLModel(const SedMLModel* smlm)
 */
SedMLModel* 
SedMLDocument::createSedMLModel()
{
	SedMLModel *temp = new SedMLModel();
	if (temp != NULL) mModel.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSimulations" in this SedMLDocument object.
 */
const SedListOfSimulations*
SedMLDocument::getListOfSimulations() const
{
	return &mSimulation;
}


/*
 * Removes the nth Simulation from the SedListOfSimulations.
 */
Simulation*
SedMLDocument::removeSimulation(unsigned int n)
{
	return mSimulation.remove(n);
}


/*
 * Removes the a Simulation with given id from the SedListOfSimulations.
 */
Simulation*
SedMLDocument::removeSimulation(const std::string& sid)
{
	return mSimulation.remove(sid);
}


/*
 * Return the nth Simulation in the SedListOfSimulations within this SedMLDocument.
 */
Simulation*
SedMLDocument::getSimulation(unsigned int n)
{
	return mSimulation.get(n);
}


/*
 * Return the nth Simulation in the SedListOfSimulations within this SedMLDocument.
 */
const Simulation*
SedMLDocument::getSimulation(unsigned int n) const
{
	return mSimulation.get(n);
}


/*
 * Return a Simulation from the SedListOfSimulations by id.
 */
Simulation*
SedMLDocument::getSimulation(const std::string& sid)
{
	return mSimulation.get(sid);
}


/*
 * Return a Simulation from the SedListOfSimulations by id.
 */
const Simulation*
SedMLDocument::getSimulation(const std::string& sid) const
{
	return mSimulation.get(sid);
}


/**
 * Adds a copy the given "Simulation" to this SedMLDocument.
 *
 * @param s; the Simulation object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedMLDocument::addSimulation(const Simulation* s)
{
	if(s == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mSimulation.append(s);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of Simulation objects in this SedMLDocument.
 *
 * @return the number of Simulation objects in this SedMLDocument
 */
unsigned int 
SedMLDocument::getNumSimulations() const
{
	return mSimulation.size();
}

/**
 * Creates a new Simulation object, adds it to this SedMLDocuments
 * SedMLDocument and returns the Simulation object created. 
 *
 * @return a new Simulation object instance
 *
 * @see addSimulation(const Simulation* s)
 */
Simulation* 
SedMLDocument::createSimulation()
{
	Simulation *temp = new Simulation();
	if (temp != NULL) mSimulation.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfTasks" in this SedMLDocument object.
 */
const SedListOfTasks*
SedMLDocument::getListOfTasks() const
{
	return &mTask;
}


/*
 * Removes the nth Task from the SedListOfTasks.
 */
Task*
SedMLDocument::removeTask(unsigned int n)
{
	return mTask.remove(n);
}


/*
 * Removes the a Task with given id from the SedListOfTasks.
 */
Task*
SedMLDocument::removeTask(const std::string& sid)
{
	return mTask.remove(sid);
}


/*
 * Return the nth Task in the SedListOfTasks within this SedMLDocument.
 */
Task*
SedMLDocument::getTask(unsigned int n)
{
	return mTask.get(n);
}


/*
 * Return the nth Task in the SedListOfTasks within this SedMLDocument.
 */
const Task*
SedMLDocument::getTask(unsigned int n) const
{
	return mTask.get(n);
}


/*
 * Return a Task from the SedListOfTasks by id.
 */
Task*
SedMLDocument::getTask(const std::string& sid)
{
	return mTask.get(sid);
}


/*
 * Return a Task from the SedListOfTasks by id.
 */
const Task*
SedMLDocument::getTask(const std::string& sid) const
{
	return mTask.get(sid);
}


/**
 * Adds a copy the given "Task" to this SedMLDocument.
 *
 * @param t; the Task object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedMLDocument::addTask(const Task* t)
{
	if(t == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mTask.append(t);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of Task objects in this SedMLDocument.
 *
 * @return the number of Task objects in this SedMLDocument
 */
unsigned int 
SedMLDocument::getNumTasks() const
{
	return mTask.size();
}

/**
 * Creates a new Task object, adds it to this SedMLDocuments
 * SedMLDocument and returns the Task object created. 
 *
 * @return a new Task object instance
 *
 * @see addTask(const Task* t)
 */
Task* 
SedMLDocument::createTask()
{
	Task *temp = new Task();
	if (temp != NULL) mTask.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfDataGenerators" in this SedMLDocument object.
 */
const SedListOfDataGenerators*
SedMLDocument::getListOfDataGenerators() const
{
	return &mDataGenerator;
}


/*
 * Removes the nth DataGenerator from the SedListOfDataGenerators.
 */
DataGenerator*
SedMLDocument::removeDataGenerator(unsigned int n)
{
	return mDataGenerator.remove(n);
}


/*
 * Removes the a DataGenerator with given id from the SedListOfDataGenerators.
 */
DataGenerator*
SedMLDocument::removeDataGenerator(const std::string& sid)
{
	return mDataGenerator.remove(sid);
}


/*
 * Return the nth DataGenerator in the SedListOfDataGenerators within this SedMLDocument.
 */
DataGenerator*
SedMLDocument::getDataGenerator(unsigned int n)
{
	return mDataGenerator.get(n);
}


/*
 * Return the nth DataGenerator in the SedListOfDataGenerators within this SedMLDocument.
 */
const DataGenerator*
SedMLDocument::getDataGenerator(unsigned int n) const
{
	return mDataGenerator.get(n);
}


/*
 * Return a DataGenerator from the SedListOfDataGenerators by id.
 */
DataGenerator*
SedMLDocument::getDataGenerator(const std::string& sid)
{
	return mDataGenerator.get(sid);
}


/*
 * Return a DataGenerator from the SedListOfDataGenerators by id.
 */
const DataGenerator*
SedMLDocument::getDataGenerator(const std::string& sid) const
{
	return mDataGenerator.get(sid);
}


/**
 * Adds a copy the given "DataGenerator" to this SedMLDocument.
 *
 * @param dg; the DataGenerator object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedMLDocument::addDataGenerator(const DataGenerator* dg)
{
	if(dg == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mDataGenerator.append(dg);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of DataGenerator objects in this SedMLDocument.
 *
 * @return the number of DataGenerator objects in this SedMLDocument
 */
unsigned int 
SedMLDocument::getNumDataGenerators() const
{
	return mDataGenerator.size();
}

/**
 * Creates a new DataGenerator object, adds it to this SedMLDocuments
 * SedMLDocument and returns the DataGenerator object created. 
 *
 * @return a new DataGenerator object instance
 *
 * @see addDataGenerator(const DataGenerator* dg)
 */
DataGenerator* 
SedMLDocument::createDataGenerator()
{
	DataGenerator *temp = new DataGenerator();
	if (temp != NULL) mDataGenerator.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the  "SedListOfSedMLOutputs" in this SedMLDocument object.
 */
const SedListOfSedMLOutputs*
SedMLDocument::getListOfSedMLOutputs() const
{
	return &mOutput;
}


/*
 * Removes the nth SedMLOutput from the SedListOfSedMLOutputs.
 */
SedMLOutput*
SedMLDocument::removeSedMLOutput(unsigned int n)
{
	return mOutput.remove(n);
}


/*
 * Removes the a SedMLOutput with given id from the SedListOfSedMLOutputs.
 */
SedMLOutput*
SedMLDocument::removeSedMLOutput(const std::string& sid)
{
	return mOutput.remove(sid);
}


/*
 * Return the nth SedMLOutput in the SedListOfSedMLOutputs within this SedMLDocument.
 */
SedMLOutput*
SedMLDocument::getSedMLOutput(unsigned int n)
{
	return mOutput.get(n);
}


/*
 * Return the nth SedMLOutput in the SedListOfSedMLOutputs within this SedMLDocument.
 */
const SedMLOutput*
SedMLDocument::getSedMLOutput(unsigned int n) const
{
	return mOutput.get(n);
}


/*
 * Return a SedMLOutput from the SedListOfSedMLOutputs by id.
 */
SedMLOutput*
SedMLDocument::getSedMLOutput(const std::string& sid)
{
	return mOutput.get(sid);
}


/*
 * Return a SedMLOutput from the SedListOfSedMLOutputs by id.
 */
const SedMLOutput*
SedMLDocument::getSedMLOutput(const std::string& sid) const
{
	return mOutput.get(sid);
}


/**
 * Adds a copy the given "SedMLOutput" to this SedMLDocument.
 *
 * @param smlo; the SedMLOutput object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedMLDocument::addSedMLOutput(const SedMLOutput* smlo)
{
	if(smlo == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mOutput.append(smlo);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedMLOutput objects in this SedMLDocument.
 *
 * @return the number of SedMLOutput objects in this SedMLDocument
 */
unsigned int 
SedMLDocument::getNumSedMLOutputs() const
{
	return mOutput.size();
}

/**
 * Creates a new SedMLOutput object, adds it to this SedMLDocuments
 * SedMLDocument and returns the SedMLOutput object created. 
 *
 * @return a new SedMLOutput object instance
 *
 * @see addSedMLOutput(const SedMLOutput* smlo)
 */
SedMLOutput* 
SedMLDocument::createSedMLOutput()
{
	SedMLOutput *temp = new SedMLOutput();
	if (temp != NULL) mOutput.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedMLDocument::getElementName () const
{
	static const string name = "sedML";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedMLDocument::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	SedBase::connectToChild();

	if (name == "listOfModels")
	{
		object = &mModel;
	}

	if (name == "listOfSimulations")
	{
		object = &mSimulation;
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
SedMLDocument::connectToChild ()
{
	SedBase::connectToChild();

	mModel.connectToParent(this);
	mSimulation.connectToParent(this);
	mTask.connectToParent(this);
	mDataGenerator.connectToParent(this);
	mOutput.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedMLDocument::getTypeCode () const
{
	return SEDML_DOCUMENT;
}


/*
 * check if all the required attributes are set
 */
bool
SedMLDocument::hasRequiredAttributes () const
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
SedMLDocument::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedMLDocument::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (getNumSedMLModels() > 0)
	{
		mModel.write(stream);
	}
	if (getNumSimulations() > 0)
	{
		mSimulation.write(stream);
	}
	if (getNumTasks() > 0)
	{
		mTask.write(stream);
	}
	if (getNumDataGenerators() > 0)
	{
		mDataGenerator.write(stream);
	}
	if (getNumSedMLOutputs() > 0)
	{
		mOutput.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
SedMLDocument::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
SedMLDocument::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedMLDocument::addExpectedAttributes(ExpectedAttributes& attributes)
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
SedMLDocument::readAttributes (const XMLAttributes& attributes,
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
SedMLDocument::writeAttributes (XMLOutputStream& stream) const
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
 * SedMLDocument or @c NULL if n > getNumErrors() - 1.
 */
const SedMLError*
SedMLDocument::getError (unsigned int n) const
{
  return mErrorLog.getError(n);
}


/*
 * @return the number of errors encountered during the parse of this
 * SedMLDocument.
 */
unsigned int
SedMLDocument::getNumErrors () const
{
  return mErrorLog.getNumErrors();
}


unsigned int 
SedMLDocument::getNumErrors (unsigned int severity) const
{
  return getErrorLog()->getNumFailsWithSeverity(severity);
}


/*
 * @return the SedMLErrorLog used to log errors during while reading and
 * validating SedML.
 */
SedMLErrorLog*
SedMLDocument::getErrorLog ()
{
  return &mErrorLog;
}


/*
 * @return the SedMLErrorLog used to log errors during while reading and
 * validating SedML.
 */
const SedMLErrorLog*
SedMLDocument::getErrorLog () const
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
SedMLDocument::writeXMLNS (XMLOutputStream& stream) const
{
  // need to check that we have indeed a namespace set!
  XMLNamespaces * thisNs = this->getNamespaces();

  // the sbml namespace is missing - add it
  if (thisNs == NULL)
  {
    XMLNamespaces xmlns;
    xmlns.add(SEDML_XMLNS_L1);

    mSedMLNamespaces->setNamespaces(&xmlns);
    thisNs = getNamespaces();
  }
  else if (thisNs->getLength() == 0)
  {
     thisNs->add(SEDML_XMLNS_L1);
  }
  else
  {
    // check that there is an sbml namespace
    std::string sedmlURI = SedMLNamespaces::getSedMLNamespaceURI(mLevel, mVersion);
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
/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLDocument_t *
SedMLDocument_create(unsigned int level, unsigned int version)
{
	return new SedMLDocument(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedMLDocument_free(SedMLDocument_t * smld)
{
	if (smld != NULL)
		delete smld;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLDocument_t *
SedMLDocument_clone(SedMLDocument_t * smld)
{
	if (smld != NULL)
	{
		return static_cast<SedMLDocument_t*>(smld->clone());
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
SedMLDocument_getLevel(SedMLDocument_t * smld)
{
	return (smld != NULL) ? smld->getLevel() : SEDML_INT_MAX;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_getVersion(SedMLDocument_t * smld)
{
	return (smld != NULL) ? smld->getVersion() : SEDML_INT_MAX;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_isSetLevel(SedMLDocument_t * smld)
{
	return (smld != NULL) ? static_cast<int>(smld->isSetLevel()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_isSetVersion(SedMLDocument_t * smld)
{
	return (smld != NULL) ? static_cast<int>(smld->isSetVersion()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_setLevel(SedMLDocument_t * smld, int level)
{
	return (smld != NULL) ? smld->setLevel(level) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_setVersion(SedMLDocument_t * smld, int version)
{
	return (smld != NULL) ? smld->setVersion(version) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_unsetLevel(SedMLDocument_t * smld)
{
	return (smld != NULL) ? smld->unsetLevel() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_unsetVersion(SedMLDocument_t * smld)
{
	return (smld != NULL) ? smld->unsetVersion() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedMLDocument_addSedMLModel(SedMLDocument_t * smld, SedMLModel_t * smlm)
{
	return  (smld != NULL) ? smld->addSedMLModel(smlm) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_createSedMLModel(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->createSedMLModel() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfSedMLModels(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? (SedListOf_t *)smld->getListOfSedMLModels() : NULL;
}

LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_getSedMLModel(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->getSedMLModel(n) : NULL;
}

LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_getSedMLModelById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->getSedMLModel(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumSedMLModels(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->getNumSedMLModels() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_removeSedMLModel(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->removeSedMLModel(n) : NULL;
}

LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_removeSedMLModelById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->removeSedMLModel(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedMLDocument_addSimulation(SedMLDocument_t * smld, Simulation_t * s)
{
	return  (smld != NULL) ? smld->addSimulation(s) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_createSimulation(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->createSimulation() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfSimulations(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? (SedListOf_t *)smld->getListOfSimulations() : NULL;
}

LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_getSimulation(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->getSimulation(n) : NULL;
}

LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_getSimulationById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->getSimulation(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumSimulations(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->getNumSimulations() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_removeSimulation(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->removeSimulation(n) : NULL;
}

LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_removeSimulationById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->removeSimulation(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedMLDocument_addTask(SedMLDocument_t * smld, Task_t * t)
{
	return  (smld != NULL) ? smld->addTask(t) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
Task_t *
SedMLDocument_createTask(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->createTask() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfTasks(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? (SedListOf_t *)smld->getListOfTasks() : NULL;
}

LIBSEDML_EXTERN
Task_t *
SedMLDocument_getTask(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->getTask(n) : NULL;
}

LIBSEDML_EXTERN
Task_t *
SedMLDocument_getTaskById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->getTask(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumTasks(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->getNumTasks() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
Task_t *
SedMLDocument_removeTask(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->removeTask(n) : NULL;
}

LIBSEDML_EXTERN
Task_t *
SedMLDocument_removeTaskById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->removeTask(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedMLDocument_addDataGenerator(SedMLDocument_t * smld, DataGenerator_t * dg)
{
	return  (smld != NULL) ? smld->addDataGenerator(dg) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_createDataGenerator(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->createDataGenerator() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfDataGenerators(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? (SedListOf_t *)smld->getListOfDataGenerators() : NULL;
}

LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_getDataGenerator(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->getDataGenerator(n) : NULL;
}

LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_getDataGeneratorById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->getDataGenerator(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumDataGenerators(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->getNumDataGenerators() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_removeDataGenerator(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->removeDataGenerator(n) : NULL;
}

LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_removeDataGeneratorById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->removeDataGenerator(sid) : NULL;
}

LIBSEDML_EXTERN
int
SedMLDocument_addSedMLOutput(SedMLDocument_t * smld, SedMLOutput_t * smlo)
{
	return  (smld != NULL) ? smld->addSedMLOutput(smlo) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedMLOutput_t *
SedMLDocument_createSedMLOutput(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->createSedMLOutput() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfSedMLOutputs(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? (SedListOf_t *)smld->getListOfSedMLOutputs() : NULL;
}

LIBSEDML_EXTERN
SedMLOutput_t *
SedMLDocument_getSedMLOutput(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->getSedMLOutput(n) : NULL;
}

LIBSEDML_EXTERN
SedMLOutput_t *
SedMLDocument_getSedMLOutputById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->getSedMLOutput(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumSedMLOutputs(SedMLDocument_t * smld)
{
	return  (smld != NULL) ? smld->getNumSedMLOutputs() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedMLOutput_t *
SedMLDocument_removeSedMLOutput(SedMLDocument_t * smld, unsigned int n)
{
	return  (smld != NULL) ? smld->removeSedMLOutput(n) : NULL;
}

LIBSEDML_EXTERN
SedMLOutput_t *
SedMLDocument_removeSedMLOutputById(SedMLDocument_t * smld, const char * sid)
{
	return  (smld != NULL) ? smld->removeSedMLOutput(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_hasRequiredAttributes(SedMLDocument_t * smld)
{
	return (smld != NULL) ? static_cast<int>(smld->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLDocument_hasRequiredElements(SedMLDocument_t * smld)
{
	return (smld != NULL) ? static_cast<int>(smld->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


