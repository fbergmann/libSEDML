/**
 * @file:   SedMLDocument.h
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


#ifndef SedMLDocument_H__
#define SedMLDocument_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>
#include <sedml/SedMLNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


#include <sedml/SedMLModel.h>
#include <sedml/Simulation.h>
#include <sedml/Task.h>
#include <sedml/DataGenerator.h>
#include <sedml/Output.h>


class LIBSEDML_EXTERN SedMLDocument : public SedBase
{

protected:

	int           mLevel;
	bool          mIsSetLevel;
	int           mVersion;
	bool          mIsSetVersion;
	SedListOfSedMLModels   mModel;
	SedListOfSimulations   mSimulation;
	SedListOfTasks   mTask;
	SedListOfDataGenerators   mDataGenerator;
	SedListOfOutputs   mOutput;


public:

	/**
	 * Creates a new SedMLDocument with the given level, version, and package version.
	 *
	 * @param level an unsigned int, the SEDML Level to assign to this SedMLDocument
	 *
	 * @param version an unsigned int, the SEDML Version to assign to this SedMLDocument
	 *
	 * @param pkgVersion an unsigned int, the SEDML SedML Version to assign to this SedMLDocument
	 */
	SedMLDocument(unsigned int level      = SEDML_DEFAULT_LEVEL,
	              unsigned int version    = SEDML_DEFAULT_VERSION);


	/**
	 * Creates a new SedMLDocument with the given SedMLNamespaces object.
	 *
	 * @param sedmlns the SedMLNamespaces object
	 */
	SedMLDocument(SedMLNamespaces* sedmlns);


 	/**
	 * Copy constructor for SedMLDocument.
	 *
	 * @param orig; the SedMLDocument instance to copy.
	 */
	SedMLDocument(const SedMLDocument& orig);


 	/**
	 * Assignment operator for SedMLDocument.
	 *
	 * @param rhs; the object whose values are used as the basis
	 * of the assignment
	 */
	SedMLDocument& operator=(const SedMLDocument& rhs);


 	/**
	 * Creates and returns a deep copy of this SedMLDocument object.
	 *
	 * @return a (deep) copy of this SedMLDocument object.
	 */
	virtual SedMLDocument* clone () const;


 	/**
	 * Destructor for SedMLDocument.
	 */
	virtual ~SedMLDocument();


 	/**
	 * Returns the value of the "level" attribute of this SedMLDocument.
	 *
	 * @return the value of the "level" attribute of this SedMLDocument as a integer.
	 */
	virtual const int getLevel() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLDocument's "level" attribute has been set.
	 *
	 * @return @c true if this SedMLDocument's "level" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetLevel() const;


	/**
	 * Sets the value of the "level" attribute of this SedMLDocument.
	 *
	 * @param level; int value of the "level" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setLevel(int level);


	/**
	 * Unsets the value of the "level" attribute of this SedMLDocument.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetLevel();


	/**
	 * Returns the value of the "version" attribute of this SedMLDocument.
	 *
	 * @return the value of the "version" attribute of this SedMLDocument as a integer.
	 */
	virtual const int getVersion() const;


	/**
	 * Predicate returning @c true or @c false depending on whether this
	 * SedMLDocument's "version" attribute has been set.
	 *
	 * @return @c true if this SedMLDocument's "version" attribute has been set,
	 * otherwise @c false is returned.
	 */
	virtual bool isSetVersion() const;


	/**
	 * Sets the value of the "version" attribute of this SedMLDocument.
	 *
	 * @param version; int value of the "version" attribute to be set
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	virtual int setVersion(int version);


	/**
	 * Unsets the value of the "version" attribute of this SedMLDocument.
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_OPERATION_FAILED
	 */
	virtual int unsetVersion();


	/**
	 * Returns the  "SedListOfSedMLModels" in this SedMLDocument object.
	 *
	 * @return the "SedListOfSedMLModels" attribute of this SedMLDocument.
	 */
	const SedListOfSedMLModels* getListOfSedMLModels() const;


	/**
	 * Get a SedMLModel from the SedListOfSedMLModels.
	 *
	 * @param n the index number of the SedMLModel to get.
	 *
	 * @return the nth SedMLModel in the SedListOfSedMLModels within this SedMLDocument.
	 *
	 * @see getNumSedMLModels()
	 */
	SedMLModel* getSedMLModel(unsigned int n);


	/**
	 * Get a SedMLModel from the SedListOfSedMLModels.
	 *
	 * @param n the index number of the SedMLModel to get.
	 *
	 * @return the nth SedMLModel in the SedListOfSedMLModels within this SedMLDocument.
	 *
	 * @see getNumSedMLModels()
	 */
	const SedMLModel* getSedMLModel(unsigned int n) const;


	/**
	 * Get a SedMLModel from the SedListOfSedMLModels
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLModel to get.
	 *
	 * @return the SedMLModel in the SedListOfSedMLModels
	 * with the given id or NULL if no such
	 * SedMLModel exists.
	 *
	 * @see getSedMLModel(unsigned int n)
	 *
	 * @see getNumSedMLModels()
	 */
	SedMLModel* getSedMLModel(const std::string& sid);


	/**
	 * Get a SedMLModel from the SedListOfSedMLModels
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the SedMLModel to get.
	 *
	 * @return the SedMLModel in the SedListOfSedMLModels
	 * with the given id or NULL if no such
	 * SedMLModel exists.
	 *
	 * @see getSedMLModel(unsigned int n)
	 *
	 * @see getNumSedMLModels()
	 */
	const SedMLModel* getSedMLModel(const std::string& sid) const;


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
	int addSedMLModel(const SedMLModel* smlm);


	/**
	 * Get the number of SedMLModel objects in this SedMLDocument.
	 *
	 * @return the number of SedMLModel objects in this SedMLDocument
	 */
	unsigned int getNumSedMLModels() const;


	/**
	 * Creates a new SedMLModel object, adds it to this SedMLDocuments
	 * SedListOfSedMLModels and returns the SedMLModel object created. 
	 *
	 * @return a new SedMLModel object instance
	 *
	 * @see addSedMLModel(const SedMLModel* smlm)
	 */
	SedMLModel* createSedMLModel();


	/**
	 * Removes the nth SedMLModel from the SedListOfSedMLModels within this SedMLDocument.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the SedMLModel to remove.
	 *
	 * @see getNumSedMLModels()
	 */
	SedMLModel* removeSedMLModel(unsigned int n);


	/**
	 * Removes the SedMLModel with the given identifier from the SedListOfSedMLModels within this SedMLDocument
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the SedMLModel to remove.
	 *
	 * @return the SedMLModel removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	SedMLModel* removeSedMLModel(const std::string& sid);


	/**
	 * Returns the  "SedListOfSimulations" in this SedMLDocument object.
	 *
	 * @return the "SedListOfSimulations" attribute of this SedMLDocument.
	 */
	const SedListOfSimulations* getListOfSimulations() const;


	/**
	 * Get a Simulation from the SedListOfSimulations.
	 *
	 * @param n the index number of the Simulation to get.
	 *
	 * @return the nth Simulation in the SedListOfSimulations within this SedMLDocument.
	 *
	 * @see getNumSimulations()
	 */
	Simulation* getSimulation(unsigned int n);


	/**
	 * Get a Simulation from the SedListOfSimulations.
	 *
	 * @param n the index number of the Simulation to get.
	 *
	 * @return the nth Simulation in the SedListOfSimulations within this SedMLDocument.
	 *
	 * @see getNumSimulations()
	 */
	const Simulation* getSimulation(unsigned int n) const;


	/**
	 * Get a Simulation from the SedListOfSimulations
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Simulation to get.
	 *
	 * @return the Simulation in the SedListOfSimulations
	 * with the given id or NULL if no such
	 * Simulation exists.
	 *
	 * @see getSimulation(unsigned int n)
	 *
	 * @see getNumSimulations()
	 */
	Simulation* getSimulation(const std::string& sid);


	/**
	 * Get a Simulation from the SedListOfSimulations
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Simulation to get.
	 *
	 * @return the Simulation in the SedListOfSimulations
	 * with the given id or NULL if no such
	 * Simulation exists.
	 *
	 * @see getSimulation(unsigned int n)
	 *
	 * @see getNumSimulations()
	 */
	const Simulation* getSimulation(const std::string& sid) const;


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
	int addSimulation(const Simulation* s);


	/**
	 * Get the number of Simulation objects in this SedMLDocument.
	 *
	 * @return the number of Simulation objects in this SedMLDocument
	 */
	unsigned int getNumSimulations() const;


	/**
	 * Creates a new Simulation object, adds it to this SedMLDocuments
	 * SedListOfSimulations and returns the Simulation object created. 
	 *
	 * @return a new Simulation object instance
	 *
	 * @see addSimulation(const Simulation* s)
	 */
	Simulation* createSimulation();


	/**
	 * Removes the nth Simulation from the SedListOfSimulations within this SedMLDocument.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Simulation to remove.
	 *
	 * @see getNumSimulations()
	 */
	Simulation* removeSimulation(unsigned int n);


	/**
	 * Removes the Simulation with the given identifier from the SedListOfSimulations within this SedMLDocument
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Simulation to remove.
	 *
	 * @return the Simulation removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	Simulation* removeSimulation(const std::string& sid);


	/**
	 * Returns the  "SedListOfTasks" in this SedMLDocument object.
	 *
	 * @return the "SedListOfTasks" attribute of this SedMLDocument.
	 */
	const SedListOfTasks* getListOfTasks() const;


	/**
	 * Get a Task from the SedListOfTasks.
	 *
	 * @param n the index number of the Task to get.
	 *
	 * @return the nth Task in the SedListOfTasks within this SedMLDocument.
	 *
	 * @see getNumTasks()
	 */
	Task* getTask(unsigned int n);


	/**
	 * Get a Task from the SedListOfTasks.
	 *
	 * @param n the index number of the Task to get.
	 *
	 * @return the nth Task in the SedListOfTasks within this SedMLDocument.
	 *
	 * @see getNumTasks()
	 */
	const Task* getTask(unsigned int n) const;


	/**
	 * Get a Task from the SedListOfTasks
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Task to get.
	 *
	 * @return the Task in the SedListOfTasks
	 * with the given id or NULL if no such
	 * Task exists.
	 *
	 * @see getTask(unsigned int n)
	 *
	 * @see getNumTasks()
	 */
	Task* getTask(const std::string& sid);


	/**
	 * Get a Task from the SedListOfTasks
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Task to get.
	 *
	 * @return the Task in the SedListOfTasks
	 * with the given id or NULL if no such
	 * Task exists.
	 *
	 * @see getTask(unsigned int n)
	 *
	 * @see getNumTasks()
	 */
	const Task* getTask(const std::string& sid) const;


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
	int addTask(const Task* t);


	/**
	 * Get the number of Task objects in this SedMLDocument.
	 *
	 * @return the number of Task objects in this SedMLDocument
	 */
	unsigned int getNumTasks() const;


	/**
	 * Creates a new Task object, adds it to this SedMLDocuments
	 * SedListOfTasks and returns the Task object created. 
	 *
	 * @return a new Task object instance
	 *
	 * @see addTask(const Task* t)
	 */
	Task* createTask();


	/**
	 * Removes the nth Task from the SedListOfTasks within this SedMLDocument.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Task to remove.
	 *
	 * @see getNumTasks()
	 */
	Task* removeTask(unsigned int n);


	/**
	 * Removes the Task with the given identifier from the SedListOfTasks within this SedMLDocument
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Task to remove.
	 *
	 * @return the Task removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	Task* removeTask(const std::string& sid);


	/**
	 * Returns the  "SedListOfDataGenerators" in this SedMLDocument object.
	 *
	 * @return the "SedListOfDataGenerators" attribute of this SedMLDocument.
	 */
	const SedListOfDataGenerators* getListOfDataGenerators() const;


	/**
	 * Get a DataGenerator from the SedListOfDataGenerators.
	 *
	 * @param n the index number of the DataGenerator to get.
	 *
	 * @return the nth DataGenerator in the SedListOfDataGenerators within this SedMLDocument.
	 *
	 * @see getNumDataGenerators()
	 */
	DataGenerator* getDataGenerator(unsigned int n);


	/**
	 * Get a DataGenerator from the SedListOfDataGenerators.
	 *
	 * @param n the index number of the DataGenerator to get.
	 *
	 * @return the nth DataGenerator in the SedListOfDataGenerators within this SedMLDocument.
	 *
	 * @see getNumDataGenerators()
	 */
	const DataGenerator* getDataGenerator(unsigned int n) const;


	/**
	 * Get a DataGenerator from the SedListOfDataGenerators
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the DataGenerator to get.
	 *
	 * @return the DataGenerator in the SedListOfDataGenerators
	 * with the given id or NULL if no such
	 * DataGenerator exists.
	 *
	 * @see getDataGenerator(unsigned int n)
	 *
	 * @see getNumDataGenerators()
	 */
	DataGenerator* getDataGenerator(const std::string& sid);


	/**
	 * Get a DataGenerator from the SedListOfDataGenerators
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the DataGenerator to get.
	 *
	 * @return the DataGenerator in the SedListOfDataGenerators
	 * with the given id or NULL if no such
	 * DataGenerator exists.
	 *
	 * @see getDataGenerator(unsigned int n)
	 *
	 * @see getNumDataGenerators()
	 */
	const DataGenerator* getDataGenerator(const std::string& sid) const;


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
	int addDataGenerator(const DataGenerator* dg);


	/**
	 * Get the number of DataGenerator objects in this SedMLDocument.
	 *
	 * @return the number of DataGenerator objects in this SedMLDocument
	 */
	unsigned int getNumDataGenerators() const;


	/**
	 * Creates a new DataGenerator object, adds it to this SedMLDocuments
	 * SedListOfDataGenerators and returns the DataGenerator object created. 
	 *
	 * @return a new DataGenerator object instance
	 *
	 * @see addDataGenerator(const DataGenerator* dg)
	 */
	DataGenerator* createDataGenerator();


	/**
	 * Removes the nth DataGenerator from the SedListOfDataGenerators within this SedMLDocument.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the DataGenerator to remove.
	 *
	 * @see getNumDataGenerators()
	 */
	DataGenerator* removeDataGenerator(unsigned int n);


	/**
	 * Removes the DataGenerator with the given identifier from the SedListOfDataGenerators within this SedMLDocument
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the DataGenerator to remove.
	 *
	 * @return the DataGenerator removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	DataGenerator* removeDataGenerator(const std::string& sid);


	/**
	 * Returns the  "SedListOfOutputs" in this SedMLDocument object.
	 *
	 * @return the "SedListOfOutputs" attribute of this SedMLDocument.
	 */
	const SedListOfOutputs* getListOfOutputs() const;


	/**
	 * Get a Output from the SedListOfOutputs.
	 *
	 * @param n the index number of the Output to get.
	 *
	 * @return the nth Output in the SedListOfOutputs within this SedMLDocument.
	 *
	 * @see getNumOutputs()
	 */
	Output* getOutput(unsigned int n);


	/**
	 * Get a Output from the SedListOfOutputs.
	 *
	 * @param n the index number of the Output to get.
	 *
	 * @return the nth Output in the SedListOfOutputs within this SedMLDocument.
	 *
	 * @see getNumOutputs()
	 */
	const Output* getOutput(unsigned int n) const;


	/**
	 * Get a Output from the SedListOfOutputs
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Output to get.
	 *
	 * @return the Output in the SedListOfOutputs
	 * with the given id or NULL if no such
	 * Output exists.
	 *
	 * @see getOutput(unsigned int n)
	 *
	 * @see getNumOutputs()
	 */
	Output* getOutput(const std::string& sid);


	/**
	 * Get a Output from the SedListOfOutputs
	 * based on its identifier.
	 *
	 * @param sid a string representing the identifier
	 * of the Output to get.
	 *
	 * @return the Output in the SedListOfOutputs
	 * with the given id or NULL if no such
	 * Output exists.
	 *
	 * @see getOutput(unsigned int n)
	 *
	 * @see getNumOutputs()
	 */
	const Output* getOutput(const std::string& sid) const;


	/**
	 * Adds a copy the given "Output" to this SedMLDocument.
	 *
	 * @param o; the Output object to add
	 *
	 * @return integer value indicating success/failure of the
	 * function.  @if clike The value is drawn from the
	 * enumeration #OperationReturnValues_t. @endif The possible values
	 * returned by this function are:
	 * @li LIBSEDML_OPERATION_SUCCESS
	 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
	 */
	int addOutput(const Output* o);


	/**
	 * Get the number of Output objects in this SedMLDocument.
	 *
	 * @return the number of Output objects in this SedMLDocument
	 */
	unsigned int getNumOutputs() const;


	/**
	 * Creates a new Output object, adds it to this SedMLDocuments
	 * SedListOfOutputs and returns the Output object created. 
	 *
	 * @return a new Output object instance
	 *
	 * @see addOutput(const Output* o)
	 */
	Output* createOutput();


	/**
	 * Removes the nth Output from the SedListOfOutputs within this SedMLDocument.
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 *
	 * @param n the index of the Output to remove.
	 *
	 * @see getNumOutputs()
	 */
	Output* removeOutput(unsigned int n);


	/**
	 * Removes the Output with the given identifier from the SedListOfOutputs within this SedMLDocument
	 * and returns a pointer to it.
	 *
	 * The caller owns the returned item and is responsible for deleting it.
	 * If none of the items in this list have the identifier @p sid, then
	 * @c NULL is returned.
	 *
	 * @param sid the identifier of the Output to remove.
	 *
	 * @return the Output removed. As mentioned above, the caller owns the
	 * returned item.
	 */
	Output* removeOutput(const std::string& sid);


	/**
	 * Returns the XML element name of this object, which for SedMLDocument, is
	 * always @c "sedMLDocument".
	 *
	 * @return the name of this element, i.e. @c "sedMLDocument".
	 */
	virtual const std::string& getElementName () const;


	/**
	 * Returns the libSEDML type code for this SEDML object.
	 * 
	 * @if clike LibSEDML attaches an identifying code to every kind of SEDML
	 * object.  These are known as <em>SEDML type codes</em>.  The set of
	 * possible type codes is defined in the enumeration #SEDMLTypeCode_t.
	 * The names of the type codes all begin with the characters @c
	 * SEDML_. @endif@if java LibSEDML attaches an identifying code to every
	 * kind of SEDML object.  These are known as <em>SEDML type codes</em>.  In
	 * other languages, the set of type codes is stored in an enumeration; in
	 * the Java language interface for libSEDML, the type codes are defined as
	 * static integer constants in the interface class {@link
	 * libsbmlConstants}.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the Python language interface for libSEDML, the type
	 * codes are defined as static integer constants in the interface class
	 * @link libsbml@endlink.  The names of the type codes all begin with the
	 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
	 * code to every kind of SEDML object.  These are known as <em>SEDML type
	 * codes</em>.  In the C# language interface for libSEDML, the type codes
	 * are defined as static integer constants in the interface class @link
	 * libsbmlcs.libsbml@endlink.  The names of the type codes all begin with
	 * the characters @c SEDML_. @endif
	 *
	 * @return the SEDML type code for this object, or
	 * @link SEDMLTypeCode_t#SEDML_UNKNOWN SEDML_UNKNOWN@endlink (default).
	 *
	 * @see getElementName()
	 */
	virtual int getTypeCode () const;


	/**
	 * Predicate returning @c true if all the required attributes
	 * for this SedMLDocument object have been set.
	 *
	 * @note The required attributes for a SedMLDocument object are:
	 * @li "level"
	 * @li "version"
	 *
	 * @return a boolean value indicating whether all the required
	 * attributes for this object have been defined.
	 */
	virtual bool hasRequiredAttributes() const;


	/**
	 * Predicate returning @c true if all the required elements
	 * for this SedMLDocument object have been set.
	 *
	 * @note The required elements for a SedMLDocument object are:
	 *
	 * @return a boolean value indicating whether all the required
	 * elements for this object have been defined.
	 */
	virtual bool hasRequiredElements() const;


/** @cond doxygen-libsbml-internal */

	/**
	 * Subclasses should override this method to write out their contained
	 * SEDML objects as XML elements.  Be sure to call your parents
	 * implementation of this method as well.
	 */
	virtual void writeElements (XMLOutputStream& stream) const;


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Accepts the given SedMLVisitor.
	 */
	virtual bool accept (SedMLVisitor& v) const;


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Sets the parent SedMLDocument.
	 */
	virtual void setSedMLDocument (SedMLDocument* d);


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Connects to child elements.
	 */
	virtual void connectToChild ();


/** @endcond doxygen-libsbml-internal */


protected:

/** @cond doxygen-libsbml-internal */

	/**
	 * return the SEDML object corresponding to next XMLToken.
	 */
	virtual SedBase* createObject(XMLInputStream& stream);


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Get the list of expected attributes for this element.
	 */
	virtual void addExpectedAttributes(ExpectedAttributes& attributes);


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Read values from the given XMLAttributes set into their specific fields.
	 */
	virtual void readAttributes (const XMLAttributes& attributes,
	                             const ExpectedAttributes& expectedAttributes);


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

	/**
	 * Write values of XMLAttributes to the output stream.
	 */
	virtual void writeAttributes (XMLOutputStream& stream) const;


/** @endcond doxygen-libsbml-internal */



};



LIBSEDML_CPP_NAMESPACE_END

#endif  /*  __cplusplus  */

#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

LIBSEDML_EXTERN
SedMLDocument_t *
SedMLDocument_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
void
SedMLDocument_free(SedMLDocument_t * smld);


LIBSEDML_EXTERN
SedMLDocument_t *
SedMLDocument_clone(SedMLDocument_t * smld);


LIBSEDML_EXTERN
int
SedMLDocument_getLevel(SedMLDocument_t * smld);


LIBSEDML_EXTERN
int
SedMLDocument_getVersion(SedMLDocument_t * smld);


LIBSEDML_EXTERN
int
SedMLDocument_isSetLevel(SedMLDocument_t * smld);


LIBSEDML_EXTERN
int
SedMLDocument_isSetVersion(SedMLDocument_t * smld);


LIBSEDML_EXTERN
int
SedMLDocument_setLevel(SedMLDocument_t * smld, int level);


LIBSEDML_EXTERN
int
SedMLDocument_setVersion(SedMLDocument_t * smld, int version);


LIBSEDML_EXTERN
int
SedMLDocument_unsetLevel(SedMLDocument_t * smld);


LIBSEDML_EXTERN
int
SedMLDocument_unsetVersion(SedMLDocument_t * smld);


LIBSEDML_EXTERN
int
SedMLDocument_addSedMLModel(SedMLDocument_t * smld, SedMLModel_t * smlm);


LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_createSedMLModel(SedMLDocument_t * smld);


LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfSedMLModels(SedMLDocument_t * smld);


LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_getSedMLModel(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_getSedMLModelById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumSedMLModels(SedMLDocument_t * smld);


LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_removeSedMLModel(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
SedMLModel_t *
SedMLDocument_removeSedMLModelById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
int
SedMLDocument_addSimulation(SedMLDocument_t * smld, Simulation_t * s);


LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_createSimulation(SedMLDocument_t * smld);


LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfSimulations(SedMLDocument_t * smld);


LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_getSimulation(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_getSimulationById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumSimulations(SedMLDocument_t * smld);


LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_removeSimulation(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
Simulation_t *
SedMLDocument_removeSimulationById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
int
SedMLDocument_addTask(SedMLDocument_t * smld, Task_t * t);


LIBSEDML_EXTERN
Task_t *
SedMLDocument_createTask(SedMLDocument_t * smld);


LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfTasks(SedMLDocument_t * smld);


LIBSEDML_EXTERN
Task_t *
SedMLDocument_getTask(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
Task_t *
SedMLDocument_getTaskById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumTasks(SedMLDocument_t * smld);


LIBSEDML_EXTERN
Task_t *
SedMLDocument_removeTask(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
Task_t *
SedMLDocument_removeTaskById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
int
SedMLDocument_addDataGenerator(SedMLDocument_t * smld, DataGenerator_t * dg);


LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_createDataGenerator(SedMLDocument_t * smld);


LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfDataGenerators(SedMLDocument_t * smld);


LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_getDataGenerator(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_getDataGeneratorById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumDataGenerators(SedMLDocument_t * smld);


LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_removeDataGenerator(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
DataGenerator_t *
SedMLDocument_removeDataGeneratorById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
int
SedMLDocument_addOutput(SedMLDocument_t * smld, Output_t * o);


LIBSEDML_EXTERN
Output_t *
SedMLDocument_createOutput(SedMLDocument_t * smld);


LIBSEDML_EXTERN
SedListOf_t *
SedMLDocument_getSedListOfOutputs(SedMLDocument_t * smld);


LIBSEDML_EXTERN
Output_t *
SedMLDocument_getOutput(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
Output_t *
SedMLDocument_getOutputById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
unsigned int
SedMLDocument_getNumOutputs(SedMLDocument_t * smld);


LIBSEDML_EXTERN
Output_t *
SedMLDocument_removeOutput(SedMLDocument_t * smld, unsigned int n);


LIBSEDML_EXTERN
Output_t *
SedMLDocument_removeOutputById(SedMLDocument_t * smld, const char * sid);


LIBSEDML_EXTERN
int
SedMLDocument_hasRequiredAttributes(SedMLDocument_t * smld);


LIBSEDML_EXTERN
int
SedMLDocument_hasRequiredElements(SedMLDocument_t * smld);




END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /*  !SWIG  */

#endif /*  SedMLDocument_H__  */

