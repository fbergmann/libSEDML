/**
 * @file:   DataSet.cpp
 * @brief:  Implementation of the DataSet class
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


#include <sedml/DataSet.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new DataSet with the given level, version, and package version.
 */
DataSet::DataSet (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mLabel ("")
	, mName ("")
	, mDataReference ("")

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));
}


/*
 * Creates a new DataSet with the given SedMLNamespaces object.
 */
DataSet::DataSet (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mLabel ("")
	, mName ("")
	, mDataReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for DataSet.
 */
DataSet::DataSet (const DataSet& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mId  = orig.mId;
		mLabel  = orig.mLabel;
		mName  = orig.mName;
		mDataReference  = orig.mDataReference;
	}
}


/*
 * Assignment for DataSet.
 */
DataSet&
DataSet::operator=(const DataSet& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mId  = rhs.mId;
		mLabel  = rhs.mLabel;
		mName  = rhs.mName;
		mDataReference  = rhs.mDataReference;
	}
	return *this;
}


/*
 * Clone for DataSet.
 */
DataSet*
DataSet::clone () const
{
	return new DataSet(*this);
}


/*
 * Destructor for DataSet.
 */
DataSet::~DataSet ()
{
}


/*
 * Returns the value of the "id" attribute of this DataSet.
 */
const std::string&
DataSet::getId() const
{
	return mId;
}


/*
/*
 * Returns the value of the "label" attribute of this DataSet.
 */
const std::string&
DataSet::getLabel() const
{
	return mLabel;
}


/*
/*
 * Returns the value of the "name" attribute of this DataSet.
 */
const std::string&
DataSet::getName() const
{
	return mName;
}


/*
/*
 * Returns the value of the "dataReference" attribute of this DataSet.
 */
const std::string&
DataSet::getDataReference() const
{
	return mDataReference;
}


/*
/*
 * Returns true/false if id is set.
 */
bool
DataSet::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if label is set.
 */
bool
DataSet::isSetLabel() const
{
	return (mLabel.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
DataSet::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if dataReference is set.
 */
bool
DataSet::isSetDataReference() const
{
	return (mDataReference.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
DataSet::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets label and returns value indicating success.
 */
int
DataSet::setLabel(const std::string& label)
{
	if (&(label) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mLabel = label;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets name and returns value indicating success.
 */
int
DataSet::setName(const std::string& name)
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
 * Sets dataReference and returns value indicating success.
 */
int
DataSet::setDataReference(const std::string& dataReference)
{
	if (&(dataReference) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else if (!(SyntaxChecker::isValidInternalSId(dataReference)))
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mDataReference = dataReference;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets id and returns value indicating success.
 */
int
DataSet::unsetId()
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
 * Unsets label and returns value indicating success.
 */
int
DataSet::unsetLabel()
{
	mLabel.erase();

	if (mLabel.empty() == true)
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
DataSet::unsetName()
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
 * Unsets dataReference and returns value indicating success.
 */
int
DataSet::unsetDataReference()
{
	mDataReference.erase();

	if (mDataReference.empty() == true)
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
DataSet::getElementName () const
{
	static const string name = "dataSet";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
DataSet::getTypeCode () const
{
	return SEDML_OUTPUT_DATASET;
}


/*
 * check if all the required attributes are set
 */
bool
DataSet::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetId() == false)
		allPresent = false;

	if (isSetLabel() == false)
		allPresent = false;

	if (isSetDataReference() == false)
		allPresent = false;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
DataSet::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
DataSet::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
DataSet::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
DataSet::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("label");
	attributes.add("name");
	attributes.add("dataReference");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
DataSet::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<DataSet>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mId) == false)
		{
			logError(InvalidIdSyntax);
		}
	}

	//
	// label string   ( use = "required" )
	//
	assigned = attributes.readInto("label", mLabel, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty

		if (mLabel.empty() == true)
		{
			logEmptyString(mLabel, getLevel(), getVersion(), "<DataSet>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<DataSet>");
		}
	}

	//
	// dataReference SIdRef   ( use = "required" )
	//
	assigned = attributes.readInto("dataReference", mDataReference, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty and correct syntax

		if (mDataReference.empty() == true)
		{
			logEmptyString(mDataReference, getLevel(), getVersion(), "<DataSet>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mDataReference) == false)
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
DataSet::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetLabel() == true)
		stream.writeAttribute("label", getPrefix(), mLabel);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

	if (isSetDataReference() == true)
		stream.writeAttribute("dataReference", getPrefix(), mDataReference);

}


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfDataSets::SedListOfDataSets(unsigned int level, 
	                  unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfDataSets::SedListOfDataSets(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfDataSets 
 */
SedListOfDataSets* 
SedListOfDataSets::clone () const
 {
	return new SedListOfDataSets(*this);
}


/*
 * Get a DataSet from the SedListOfDataSets by index.
*/
DataSet*
SedListOfDataSets::get(unsigned int n)
{
	return static_cast<DataSet*>(SedListOf::get(n));
}


/*
 * Get a DataSet from the SedListOfDataSets by index.
 */
const DataSet*
SedListOfDataSets::get(unsigned int n) const
{
	return static_cast<const DataSet*>(SedListOf::get(n));
}


/*
 * Get a DataSet from the SedListOfDataSets by id.
 */
DataSet*
SedListOfDataSets::get(const std::string& sid)
{
	return const_cast<DataSet*>(
	  static_cast<const SedListOfDataSets&>(*this).get(sid));
}


/*
 * Get a DataSet from the SedListOfDataSets by id.
 */
const DataSet*
SedListOfDataSets::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<DataSet>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <DataSet*> (*result);
}


/*
 * Removes the nth DataSet from this SedListOfDataSets
 */
DataSet*
SedListOfDataSets::remove(unsigned int n)
{
	return static_cast<DataSet*>(SedListOf::remove(n));
}


/*
 * Removes the DataSet from this SedListOfDataSets with the given identifier
 */
DataSet*
SedListOfDataSets::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<DataSet>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <DataSet*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfDataSets::getElementName () const
{
	static const string name = "listOfDataSets";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfDataSets::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfDataSets::getItemTypeCode () const
{
	return SEDML_OUTPUT_DATASET;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new DataSet in this SedListOfDataSets
 */
SedBase*
SedListOfDataSets::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "dataSet")
	{
		object = new DataSet(getSedMLNamespaces());
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
SedListOfDataSets::writeXMLNS(XMLOutputStream& stream) const
{
	XMLNamespaces xmlns;

	std::string prefix = getPrefix();

	if (prefix.empty())
	{
		if (getNamespaces()->hasURI(SEDML_XMLNS_L1))
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
DataSet_t *
DataSet_create(unsigned int level, unsigned int version)
{
	return new DataSet(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
DataSet_free(DataSet_t * ds)
{
	if (ds != NULL)
		delete ds;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
DataSet_t *
DataSet_clone(DataSet_t * ds)
{
	if (ds != NULL)
	{
		return static_cast<DataSet_t*>(ds->clone());
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
DataSet_getId(DataSet_t * ds)
{
	if (ds == NULL)
		return NULL;

	return ds->getId().empty() ? NULL : safe_strdup(ds->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
DataSet_getLabel(DataSet_t * ds)
{
	if (ds == NULL)
		return NULL;

	return ds->getLabel().empty() ? NULL : safe_strdup(ds->getLabel().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
DataSet_getName(DataSet_t * ds)
{
	if (ds == NULL)
		return NULL;

	return ds->getName().empty() ? NULL : safe_strdup(ds->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
DataSet_getDataReference(DataSet_t * ds)
{
	if (ds == NULL)
		return NULL;

	return ds->getDataReference().empty() ? NULL : safe_strdup(ds->getDataReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_isSetId(DataSet_t * ds)
{
	return (ds != NULL) ? static_cast<int>(ds->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_isSetLabel(DataSet_t * ds)
{
	return (ds != NULL) ? static_cast<int>(ds->isSetLabel()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_isSetName(DataSet_t * ds)
{
	return (ds != NULL) ? static_cast<int>(ds->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_isSetDataReference(DataSet_t * ds)
{
	return (ds != NULL) ? static_cast<int>(ds->isSetDataReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_setId(DataSet_t * ds, const char * id)
{
	return (ds != NULL) ? ds->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_setLabel(DataSet_t * ds, const char * label)
{
	return (ds != NULL) ? ds->setLabel(label) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_setName(DataSet_t * ds, const char * name)
{
	return (ds != NULL) ? ds->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_setDataReference(DataSet_t * ds, const char * dataReference)
{
	return (ds != NULL) ? ds->setDataReference(dataReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_unsetId(DataSet_t * ds)
{
	return (ds != NULL) ? ds->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_unsetLabel(DataSet_t * ds)
{
	return (ds != NULL) ? ds->unsetLabel() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_unsetName(DataSet_t * ds)
{
	return (ds != NULL) ? ds->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_unsetDataReference(DataSet_t * ds)
{
	return (ds != NULL) ? ds->unsetDataReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
DataSet_hasRequiredAttributes(DataSet_t * ds)
{
	return (ds != NULL) ? static_cast<int>(ds->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
DataSet_t *
SedListOfDataSets_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfDataSets *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
DataSet_t *
SedListOfDataSets_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfDataSets *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


