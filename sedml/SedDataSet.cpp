/**
 * @file:   SedDataSet.cpp
 * @brief:  Implementation of the SedDataSet class
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


#include <sedml/SedDataSet.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedDataSet with the given level, version, and package version.
 */
SedDataSet::SedDataSet (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mLabel ("")
	, mName ("")
	, mDataReference ("")

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedDataSet with the given SedNamespaces object.
 */
SedDataSet::SedDataSet (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")
	, mLabel ("")
	, mName ("")
	, mDataReference ("")

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedDataSet.
 */
SedDataSet::SedDataSet (const SedDataSet& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
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
 * Assignment for SedDataSet.
 */
SedDataSet&
SedDataSet::operator=(const SedDataSet& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
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
 * Clone for SedDataSet.
 */
SedDataSet*
SedDataSet::clone () const
{
	return new SedDataSet(*this);
}


/*
 * Destructor for SedDataSet.
 */
SedDataSet::~SedDataSet ()
{
}


/*
 * Returns the value of the "id" attribute of this SedDataSet.
 */
const std::string&
SedDataSet::getId() const
{
	return mId;
}


/*
 * Returns the value of the "label" attribute of this SedDataSet.
 */
const std::string&
SedDataSet::getLabel() const
{
	return mLabel;
}


/*
 * Returns the value of the "name" attribute of this SedDataSet.
 */
const std::string&
SedDataSet::getName() const
{
	return mName;
}


/*
 * Returns the value of the "dataReference" attribute of this SedDataSet.
 */
const std::string&
SedDataSet::getDataReference() const
{
	return mDataReference;
}


/*
 * Returns true/false if id is set.
 */
bool
SedDataSet::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if label is set.
 */
bool
SedDataSet::isSetLabel() const
{
	return (mLabel.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedDataSet::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if dataReference is set.
 */
bool
SedDataSet::isSetDataReference() const
{
	return (mDataReference.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedDataSet::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets label and returns value indicating success.
 */
int
SedDataSet::setLabel(const std::string& label)
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
SedDataSet::setName(const std::string& name)
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
SedDataSet::setDataReference(const std::string& dataReference)
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
SedDataSet::unsetId()
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
SedDataSet::unsetLabel()
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
SedDataSet::unsetName()
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
SedDataSet::unsetDataReference()
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
SedDataSet::getElementName () const
{
	static const string name = "dataSet";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedDataSet::getTypeCode () const
{
	return SEDML_OUTPUT_DATASET;
}


/*
 * check if all the required attributes are set
 */
bool
SedDataSet::hasRequiredAttributes () const
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
SedDataSet::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedDataSet::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedDataSet::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedDataSet::addExpectedAttributes(ExpectedAttributes& attributes)
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
SedDataSet::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedDataSet>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mId) == false)
		{
			logError(SedInvalidIdSyntax);
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
			logEmptyString(mLabel, getLevel(), getVersion(), "<SedDataSet>");
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedDataSet>");
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
			logEmptyString(mDataReference, getLevel(), getVersion(), "<SedDataSet>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mDataReference) == false)
		{
			logError(SedInvalidIdSyntax);
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedDataSet::writeAttributes (XMLOutputStream& stream) const
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
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfDataSets::SedListOfDataSets(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
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
SedDataSet*
SedListOfDataSets::get(unsigned int n)
{
	return static_cast<SedDataSet*>(SedListOf::get(n));
}


/*
 * Get a DataSet from the SedListOfDataSets by index.
 */
const SedDataSet*
SedListOfDataSets::get(unsigned int n) const
{
	return static_cast<const SedDataSet*>(SedListOf::get(n));
}


/*
 * Get a DataSet from the SedListOfDataSets by id.
 */
SedDataSet*
SedListOfDataSets::get(const std::string& sid)
{
	return const_cast<SedDataSet*>(
	  static_cast<const SedListOfDataSets&>(*this).get(sid));
}


/*
 * Get a DataSet from the SedListOfDataSets by id.
 */
const SedDataSet*
SedListOfDataSets::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedDataSet>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedDataSet*> (*result);
}


/**
 * Adds a copy the given "SedDataSet" to this SedListOfDataSets.
 *
 * @param sds; the SedDataSet object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedListOfDataSets::addDataSet(const SedDataSet* sds)
{
	if(sds == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sds);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedDataSet objects in this SedListOfDataSets.
 *
 * @return the number of SedDataSet objects in this SedListOfDataSets
 */
unsigned int 
SedListOfDataSets::getNumDataSets() const
{
	return size();
}

/**
 * Creates a new SedDataSet object, adds it to this SedListOfDataSetss
 * SedDataSet and returns the SedDataSet object created. 
 *
 * @return a new SedDataSet object instance
 *
 * @see addSedDataSet(const SedDataSet* sds)
 */
SedDataSet* 
SedListOfDataSets::createDataSet()
{
	SedDataSet *temp = new SedDataSet();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth DataSet from this SedListOfDataSets
 */
SedDataSet*
SedListOfDataSets::remove(unsigned int n)
{
	return static_cast<SedDataSet*>(SedListOf::remove(n));
}


/*
 * Removes the DataSet from this SedListOfDataSets with the given identifier
 */
SedDataSet*
SedListOfDataSets::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedDataSet>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedDataSet*> (item);
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
 * Creates a new SedDataSet in this SedListOfDataSets
 */
SedBase*
SedListOfDataSets::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "dataSet")
	{
		object = new SedDataSet(getSedNamespaces());
		appendAndOwn(object);
	}

	return object;
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write the namespace for the Sed package.
 */
void
SedListOfDataSets::writeXMLNS(XMLOutputStream& stream) const
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


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataSet_t *
SedDataSet_create(unsigned int level, unsigned int version)
{
	return new SedDataSet(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedDataSet_free(SedDataSet_t * sds)
{
	if (sds != NULL)
		delete sds;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataSet_t *
SedDataSet_clone(SedDataSet_t * sds)
{
	if (sds != NULL)
	{
		return static_cast<SedDataSet_t*>(sds->clone());
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
SedDataSet_getId(SedDataSet_t * sds)
{
	if (sds == NULL)
		return NULL;

	return sds->getId().empty() ? NULL : safe_strdup(sds->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataSet_getLabel(SedDataSet_t * sds)
{
	if (sds == NULL)
		return NULL;

	return sds->getLabel().empty() ? NULL : safe_strdup(sds->getLabel().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataSet_getName(SedDataSet_t * sds)
{
	if (sds == NULL)
		return NULL;

	return sds->getName().empty() ? NULL : safe_strdup(sds->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedDataSet_getDataReference(SedDataSet_t * sds)
{
	if (sds == NULL)
		return NULL;

	return sds->getDataReference().empty() ? NULL : safe_strdup(sds->getDataReference().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetId(SedDataSet_t * sds)
{
	return (sds != NULL) ? static_cast<int>(sds->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetLabel(SedDataSet_t * sds)
{
	return (sds != NULL) ? static_cast<int>(sds->isSetLabel()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetName(SedDataSet_t * sds)
{
	return (sds != NULL) ? static_cast<int>(sds->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_isSetDataReference(SedDataSet_t * sds)
{
	return (sds != NULL) ? static_cast<int>(sds->isSetDataReference()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_setId(SedDataSet_t * sds, const char * id)
{
	return (sds != NULL) ? sds->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_setLabel(SedDataSet_t * sds, const char * label)
{
	return (sds != NULL) ? sds->setLabel(label) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_setName(SedDataSet_t * sds, const char * name)
{
	return (sds != NULL) ? sds->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_setDataReference(SedDataSet_t * sds, const char * dataReference)
{
	return (sds != NULL) ? sds->setDataReference(dataReference) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetId(SedDataSet_t * sds)
{
	return (sds != NULL) ? sds->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetLabel(SedDataSet_t * sds)
{
	return (sds != NULL) ? sds->unsetLabel() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetName(SedDataSet_t * sds)
{
	return (sds != NULL) ? sds->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_unsetDataReference(SedDataSet_t * sds)
{
	return (sds != NULL) ? sds->unsetDataReference() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedDataSet_hasRequiredAttributes(SedDataSet_t * sds)
{
	return (sds != NULL) ? static_cast<int>(sds->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedDataSet_t *
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
SedDataSet_t *
SedListOfDataSets_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfDataSets *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


