/**
 * @file:   Report.cpp
 * @brief:  Implementation of the Report class
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


#include <sedml/Report.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new Report with the given level, version, and package version.
 */
Report::Report (unsigned int level, unsigned int version)
	: Output(level, version)
	, mDataSet (level, version)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new Report with the given SedMLNamespaces object.
 */
Report::Report (SedMLNamespaces* sedmlns)
	: Output(sedmlns)
	, mDataSet (sedmlns)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for Report.
 */
Report::Report (const Report& orig)
	: Output(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mDataSet  = orig.mDataSet;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for Report.
 */
Report&
Report::operator=(const Report& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		Output::operator=(rhs);
		mDataSet  = rhs.mDataSet;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for Report.
 */
Report*
Report::clone () const
{
	return new Report(*this);
}


/*
 * Destructor for Report.
 */
Report::~Report ()
{
}


/*
 * Returns the  "SedListOfDataSets" in this Report object.
 */
const SedListOfDataSets*
Report::getListOfDataSets() const
{
	return &mDataSet;
}


/*
 * Removes the nth DataSet from the SedListOfDataSets.
 */
DataSet*
Report::removeDataSet(unsigned int n)
{
	return mDataSet.remove(n);
}


/*
 * Removes the a DataSet with given id from the SedListOfDataSets.
 */
DataSet*
Report::removeDataSet(const std::string& sid)
{
	return mDataSet.remove(sid);
}


/*
 * Return the nth DataSet in the SedListOfDataSets within this Report.
 */
DataSet*
Report::getDataSet(unsigned int n)
{
	return mDataSet.get(n);
}


/*
 * Return the nth DataSet in the SedListOfDataSets within this Report.
 */
const DataSet*
Report::getDataSet(unsigned int n) const
{
	return mDataSet.get(n);
}


/*
 * Return a DataSet from the SedListOfDataSets by id.
 */
DataSet*
Report::getDataSet(const std::string& sid)
{
	return mDataSet.get(sid);
}


/*
 * Return a DataSet from the SedListOfDataSets by id.
 */
const DataSet*
Report::getDataSet(const std::string& sid) const
{
	return mDataSet.get(sid);
}


/**
 * Adds a copy the given "DataSet" to this Report.
 *
 * @param ds; the DataSet object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
Report::addDataSet(const DataSet* ds)
{
	if(ds == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mDataSet.append(ds);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of DataSet objects in this Report.
 *
 * @return the number of DataSet objects in this Report
 */
unsigned int 
Report::getNumDataSets() const
{
	return mDataSet.size();
}

/**
 * Creates a new DataSet object, adds it to this Reports
 * Report and returns the DataSet object created. 
 *
 * @return a new DataSet object instance
 *
 * @see addDataSet(const DataSet* ds)
 */
DataSet* 
Report::createDataSet()
{
	DataSet *temp = new DataSet();
	if (temp != NULL) mDataSet.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
Report::getElementName () const
{
	static const string name = "report";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
Report::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	Output::connectToChild();

	if (name == "listOfDataSets")
	{
		object = &mDataSet;
	}

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Report::connectToChild ()
{
	Output::connectToChild();

	mDataSet.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
Report::getTypeCode () const
{
	return SEDML_OUTPUT_REPORT;
}


/*
 * check if all the required attributes are set
 */
bool
Report::hasRequiredAttributes () const
{
	bool allPresent = Output::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
Report::hasRequiredElements () const
{
	bool allPresent = Output::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
Report::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (getNumDataSets() > 0)
	{
		mDataSet.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
Report::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
Report::setSedMLDocument (SedMLDocument* d)
{
	Output::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
Report::addExpectedAttributes(ExpectedAttributes& attributes)
{
	Output::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
Report::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	Output::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
Report::writeAttributes (XMLOutputStream& stream) const
{
	Output::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
Report_t *
Report_create(unsigned int level, unsigned int version)
{
	return new Report(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
Report_free(Report_t * r)
{
	if (r != NULL)
		delete r;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
Report_t *
Report_clone(Report_t * r)
{
	if (r != NULL)
	{
		return static_cast<Report_t*>(r->clone());
	}
	else
	{
		return NULL;
	}
}


LIBSEDML_EXTERN
int
Report_addDataSet(Report_t * r, DataSet_t * ds)
{
	return  (r != NULL) ? r->addDataSet(ds) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
DataSet_t *
Report_createDataSet(Report_t * r)
{
	return  (r != NULL) ? r->createDataSet() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
Report_getSedListOfDataSets(Report_t * r)
{
	return  (r != NULL) ? (SedListOf_t *)r->getListOfDataSets() : NULL;
}

LIBSEDML_EXTERN
DataSet_t *
Report_getDataSet(Report_t * r, unsigned int n)
{
	return  (r != NULL) ? r->getDataSet(n) : NULL;
}

LIBSEDML_EXTERN
DataSet_t *
Report_getDataSetById(Report_t * r, const char * sid)
{
	return  (r != NULL) ? r->getDataSet(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
Report_getNumDataSets(Report_t * r)
{
	return  (r != NULL) ? r->getNumDataSets() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
DataSet_t *
Report_removeDataSet(Report_t * r, unsigned int n)
{
	return  (r != NULL) ? r->removeDataSet(n) : NULL;
}

LIBSEDML_EXTERN
DataSet_t *
Report_removeDataSetById(Report_t * r, const char * sid)
{
	return  (r != NULL) ? r->removeDataSet(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
Report_hasRequiredAttributes(Report_t * r)
{
	return (r != NULL) ? static_cast<int>(r->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
Report_hasRequiredElements(Report_t * r)
{
	return (r != NULL) ? static_cast<int>(r->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


