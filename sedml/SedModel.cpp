/**
 * @file:   SedModel.cpp
 * @brief:  Implementation of the SedModel class
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


#include <sedml/SedModel.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedModel with the given level, version, and package version.
 */
SedModel::SedModel (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mLanguage ("")
	, mSource ("")
	, mChanges (level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedModel with the given SedNamespaces object.
 */
SedModel::SedModel (SedNamespaces* sedns)
	: SedBase(sedns)
	, mId ("")
	, mName ("")
	, mLanguage ("")
	, mSource ("")
	, mChanges (sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedModel.
 */
SedModel::SedModel (const SedModel& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mId  = orig.mId;
		mName  = orig.mName;
		mLanguage  = orig.mLanguage;
		mSource  = orig.mSource;
		mChanges  = orig.mChanges;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedModel.
 */
SedModel&
SedModel::operator=(const SedModel& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mId  = rhs.mId;
		mName  = rhs.mName;
		mLanguage  = rhs.mLanguage;
		mSource  = rhs.mSource;
		mChanges  = rhs.mChanges;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedModel.
 */
SedModel*
SedModel::clone () const
{
	return new SedModel(*this);
}


/*
 * Destructor for SedModel.
 */
SedModel::~SedModel ()
{
}


/*
 * Returns the value of the "id" attribute of this SedModel.
 */
const std::string&
SedModel::getId() const
{
	return mId;
}


/*
 * Returns the value of the "name" attribute of this SedModel.
 */
const std::string&
SedModel::getName() const
{
	return mName;
}


/*
 * Returns the value of the "language" attribute of this SedModel.
 */
const std::string&
SedModel::getLanguage() const
{
	return mLanguage;
}


/*
 * Returns the value of the "source" attribute of this SedModel.
 */
const std::string&
SedModel::getSource() const
{
	return mSource;
}


/*
 * Returns true/false if id is set.
 */
bool
SedModel::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedModel::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if language is set.
 */
bool
SedModel::isSetLanguage() const
{
	return (mLanguage.empty() == false);
}


/*
 * Returns true/false if source is set.
 */
bool
SedModel::isSetSource() const
{
	return (mSource.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedModel::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedModel::setName(const std::string& name)
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
 * Sets language and returns value indicating success.
 */
int
SedModel::setLanguage(const std::string& language)
{
	if (&(language) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mLanguage = language;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Sets source and returns value indicating success.
 */
int
SedModel::setSource(const std::string& source)
{
	if (&(source) == NULL)
	{
		return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	}
	else
	{
		mSource = source;
		return LIBSEDML_OPERATION_SUCCESS;
	}
}


/*
 * Unsets id and returns value indicating success.
 */
int
SedModel::unsetId()
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
SedModel::unsetName()
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
 * Unsets language and returns value indicating success.
 */
int
SedModel::unsetLanguage()
{
	mLanguage.erase();

	if (mLanguage.empty() == true)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Unsets source and returns value indicating success.
 */
int
SedModel::unsetSource()
{
	mSource.erase();

	if (mSource.empty() == true)
	{
		return LIBSEDML_OPERATION_SUCCESS;
	}
	else
	{
		return LIBSEDML_OPERATION_FAILED;
	}
}


/*
 * Returns the  "SedListOfChanges" in this SedModel object.
 */
const SedListOfChanges*
SedModel::getListOfChanges() const
{
	return &mChanges;
}


/*
 * Removes the nth Change from the SedListOfChanges.
 */
SedChange*
SedModel::removeChange(unsigned int n)
{
	return mChanges.remove(n);
}


/*
 * Removes the a Change with given id from the SedListOfChanges.
 */
SedChange*
SedModel::removeChange(const std::string& sid)
{
	return mChanges.remove(sid);
}


/*
 * Return the nth Change in the SedListOfChanges within this SedModel.
 */
SedChange*
SedModel::getChange(unsigned int n)
{
	return mChanges.get(n);
}


/*
 * Return the nth Change in the SedListOfChanges within this SedModel.
 */
const SedChange*
SedModel::getChange(unsigned int n) const
{
	return mChanges.get(n);
}


/*
 * Return a Change from the SedListOfChanges by id.
 */
SedChange*
SedModel::getChange(const std::string& sid)
{
	return mChanges.get(sid);
}


/*
 * Return a Change from the SedListOfChanges by id.
 */
const SedChange*
SedModel::getChange(const std::string& sid) const
{
	return mChanges.get(sid);
}


/**
 * Adds a copy the given "SedChange" to this SedModel.
 *
 * @param sc; the SedChange object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedModel::addChange(const SedChange* sc)
{
	if(sc == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mChanges.append(sc);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedChange objects in this SedModel.
 *
 * @return the number of SedChange objects in this SedModel
 */
unsigned int 
SedModel::getNumChanges() const
{
	return mChanges.size();
}

/**
 * Creates a new SedRemoveXML object, adds it to this SedModels
 * SedModel and returns the SedRemoveXML object created. 
 *
 * @return a new SedRemoveXML object instance
 *
 * @see addRemoveXML(const SedChange* sc)
 */
SedRemoveXML* 
SedModel::createRemoveXML()
{
	SedRemoveXML *temp = new SedRemoveXML();
	if (temp != NULL) mChanges.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedAddXML object, adds it to this SedModels
 * SedModel and returns the SedAddXML object created. 
 *
 * @return a new SedAddXML object instance
 *
 * @see addAddXML(const SedChange* sc)
 */
SedAddXML* 
SedModel::createAddXML()
{
	SedAddXML *temp = new SedAddXML();
	if (temp != NULL) mChanges.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedChangeXML object, adds it to this SedModels
 * SedModel and returns the SedChangeXML object created. 
 *
 * @return a new SedChangeXML object instance
 *
 * @see addChangeXML(const SedChange* sc)
 */
SedChangeXML* 
SedModel::createChangeXML()
{
	SedChangeXML *temp = new SedChangeXML();
	if (temp != NULL) mChanges.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedChangeAttribute object, adds it to this SedModels
 * SedModel and returns the SedChangeAttribute object created. 
 *
 * @return a new SedChangeAttribute object instance
 *
 * @see addChangeAttribute(const SedChange* sc)
 */
SedChangeAttribute* 
SedModel::createChangeAttribute()
{
	SedChangeAttribute *temp = new SedChangeAttribute();
	if (temp != NULL) mChanges.appendAndOwn(temp);
	return temp;
}

/**
 * Creates a new SedComputeChange object, adds it to this SedModels
 * SedModel and returns the SedComputeChange object created. 
 *
 * @return a new SedComputeChange object instance
 *
 * @see addComputeChange(const SedChange* sc)
 */
SedComputeChange* 
SedModel::createComputeChange()
{
	SedComputeChange *temp = new SedComputeChange();
	if (temp != NULL) mChanges.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedModel::getElementName () const
{
	static const string name = "model";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedModel::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	if (name == "listOfChanges")
	{
		object = &mChanges;
	}

	connectToChild();

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedModel::connectToChild ()
{
	SedBase::connectToChild();

	mChanges.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedModel::getTypeCode () const
{
	return SEDML_MODEL;
}


/*
 * check if all the required attributes are set
 */
bool
SedModel::hasRequiredAttributes () const
{
	bool allPresent = true;

	if (isSetId() == false)
		allPresent = false;

	if (isSetSource() == false)
		allPresent = false;

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedModel::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsedml-internal */

/*
 * write contained elements
 */
void
SedModel::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (getNumChanges() > 0)
	{
		mChanges.write(stream);
	}
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedModel::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedModel::setSedDocument (SedDocument* d)
{
	SedBase::setSedDocument(d);
	mChanges.setSedDocument(d);
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedModel::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
	attributes.add("language");
	attributes.add("source");
}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedModel::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedModel>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mId) == false)
		{
			logError(SedInvalidIdSyntax);
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedModel>");
		}
	}

	//
	// language string   ( use = "optional" )
	//
	assigned = attributes.readInto("language", mLanguage, getErrorLog(), false);

	if (assigned == true)
	{
		// check string is not empty

		if (mLanguage.empty() == true)
		{
			logEmptyString(mLanguage, getLevel(), getVersion(), "<SedModel>");
		}
	}

	//
	// source string   ( use = "required" )
	//
	assigned = attributes.readInto("source", mSource, getErrorLog(), true);

	if (assigned == true)
	{
		// check string is not empty

		if (mSource.empty() == true)
		{
			logEmptyString(mSource, getLevel(), getVersion(), "<SedModel>");
		}
	}

}


/** @endcond doxygen-libsedml-internal */


/** @cond doxygen-libsedml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedModel::writeAttributes (XMLOutputStream& stream) const
{
	SedBase::writeAttributes(stream);

	if (isSetId() == true)
		stream.writeAttribute("id", getPrefix(), mId);

	if (isSetName() == true)
		stream.writeAttribute("name", getPrefix(), mName);

	if (isSetLanguage() == true)
		stream.writeAttribute("language", getPrefix(), mLanguage);

	if (isSetSource() == true)
		stream.writeAttribute("source", getPrefix(), mSource);

}


/** @endcond doxygen-libsedml-internal */


/*
 * Constructor 
 */
SedListOfModels::SedListOfModels(unsigned int level, 
	                unsigned int version)
 : SedListOf(level, version)
{
	setSedNamespacesAndOwn(new SedNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfModels::SedListOfModels(SedNamespaces* sedns)
  : SedListOf(sedns)
{
	setElementNamespace(sedns->getURI());
}


/*
 * Returns a deep copy of this SedListOfModels 
 */
SedListOfModels* 
SedListOfModels::clone () const
 {
	return new SedListOfModels(*this);
}


/*
 * Get a Model from the SedListOfModels by index.
*/
SedModel*
SedListOfModels::get(unsigned int n)
{
	return static_cast<SedModel*>(SedListOf::get(n));
}


/*
 * Get a Model from the SedListOfModels by index.
 */
const SedModel*
SedListOfModels::get(unsigned int n) const
{
	return static_cast<const SedModel*>(SedListOf::get(n));
}


/*
 * Get a Model from the SedListOfModels by id.
 */
SedModel*
SedListOfModels::get(const std::string& sid)
{
	return const_cast<SedModel*>(
	  static_cast<const SedListOfModels&>(*this).get(sid));
}


/*
 * Get a Model from the SedListOfModels by id.
 */
const SedModel*
SedListOfModels::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedModel>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedModel*> (*result);
}


/**
 * Adds a copy the given "SedModel" to this SedListOfModels.
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
SedListOfModels::addModel(const SedModel* sm)
{
	if(sm == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	append(sm);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedModel objects in this SedListOfModels.
 *
 * @return the number of SedModel objects in this SedListOfModels
 */
unsigned int 
SedListOfModels::getNumModels() const
{
	return size();
}

/**
 * Creates a new SedModel object, adds it to this SedListOfModelss
 * SedModel and returns the SedModel object created. 
 *
 * @return a new SedModel object instance
 *
 * @see addSedModel(const SedModel* sm)
 */
SedModel* 
SedListOfModels::createModel()
{
	SedModel *temp = new SedModel();
	if (temp != NULL) appendAndOwn(temp);
	return temp;
}

/*
 * Removes the nth Model from this SedListOfModels
 */
SedModel*
SedListOfModels::remove(unsigned int n)
{
	return static_cast<SedModel*>(SedListOf::remove(n));
}


/*
 * Removes the Model from this SedListOfModels with the given identifier
 */
SedModel*
SedListOfModels::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), SedIdEq<SedModel>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedModel*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfModels::getElementName () const
{
	static const string name = "listOfModels";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfModels::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfModels::getItemTypeCode () const
{
	return SEDML_MODEL;
}


/** @cond doxygen-libsedml-internal */

/*
 * Creates a new SedModel in this SedListOfModels
 */
SedBase*
SedListOfModels::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "model")
	{
		object = new SedModel(getSedNamespaces());
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
SedListOfModels::writeXMLNS(XMLOutputStream& stream) const
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
SedModel_t *
SedModel_create(unsigned int level, unsigned int version)
{
	return new SedModel(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedModel_free(SedModel_t * sm)
{
	if (sm != NULL)
		delete sm;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedModel_t *
SedModel_clone(SedModel_t * sm)
{
	if (sm != NULL)
	{
		return static_cast<SedModel_t*>(sm->clone());
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
SedModel_getId(SedModel_t * sm)
{
	if (sm == NULL)
		return NULL;

	return sm->getId().empty() ? NULL : safe_strdup(sm->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedModel_getName(SedModel_t * sm)
{
	if (sm == NULL)
		return NULL;

	return sm->getName().empty() ? NULL : safe_strdup(sm->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedModel_getLanguage(SedModel_t * sm)
{
	if (sm == NULL)
		return NULL;

	return sm->getLanguage().empty() ? NULL : safe_strdup(sm->getLanguage().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedModel_getSource(SedModel_t * sm)
{
	if (sm == NULL)
		return NULL;

	return sm->getSource().empty() ? NULL : safe_strdup(sm->getSource().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_isSetId(SedModel_t * sm)
{
	return (sm != NULL) ? static_cast<int>(sm->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_isSetName(SedModel_t * sm)
{
	return (sm != NULL) ? static_cast<int>(sm->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_isSetLanguage(SedModel_t * sm)
{
	return (sm != NULL) ? static_cast<int>(sm->isSetLanguage()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_isSetSource(SedModel_t * sm)
{
	return (sm != NULL) ? static_cast<int>(sm->isSetSource()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_setId(SedModel_t * sm, const char * id)
{
	return (sm != NULL) ? sm->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_setName(SedModel_t * sm, const char * name)
{
	return (sm != NULL) ? sm->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_setLanguage(SedModel_t * sm, const char * language)
{
	return (sm != NULL) ? sm->setLanguage(language) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_setSource(SedModel_t * sm, const char * source)
{
	return (sm != NULL) ? sm->setSource(source) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_unsetId(SedModel_t * sm)
{
	return (sm != NULL) ? sm->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_unsetName(SedModel_t * sm)
{
	return (sm != NULL) ? sm->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_unsetLanguage(SedModel_t * sm)
{
	return (sm != NULL) ? sm->unsetLanguage() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_unsetSource(SedModel_t * sm)
{
	return (sm != NULL) ? sm->unsetSource() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedModel_addChange(SedModel_t * sm, SedChange_t * sc)
{
	return  (sm != NULL) ? sm->addChange(sc) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedRemoveXML_t *
SedModel_createRemoveXML(SedModel_t * sm)
{
	return  (sm != NULL) ? sm->createRemoveXML() : NULL;
}

LIBSEDML_EXTERN
SedAddXML_t *
SedModel_createAddXML(SedModel_t * sm)
{
	return  (sm != NULL) ? sm->createAddXML() : NULL;
}

LIBSEDML_EXTERN
SedChangeXML_t *
SedModel_createChangeXML(SedModel_t * sm)
{
	return  (sm != NULL) ? sm->createChangeXML() : NULL;
}

LIBSEDML_EXTERN
SedChangeAttribute_t *
SedModel_createChangeAttribute(SedModel_t * sm)
{
	return  (sm != NULL) ? sm->createChangeAttribute() : NULL;
}

LIBSEDML_EXTERN
SedComputeChange_t *
SedModel_createComputeChange(SedModel_t * sm)
{
	return  (sm != NULL) ? sm->createComputeChange() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedModel_getSedListOfChanges(SedModel_t * sm)
{
	return  (sm != NULL) ? (SedListOf_t *)sm->getListOfChanges() : NULL;
}

LIBSEDML_EXTERN
SedChange_t *
SedModel_getChange(SedModel_t * sm, unsigned int n)
{
	return  (sm != NULL) ? sm->getChange(n) : NULL;
}

LIBSEDML_EXTERN
SedChange_t *
SedModel_getChangeById(SedModel_t * sm, const char * sid)
{
	return  (sm != NULL) ? sm->getChange(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedModel_getNumChanges(SedModel_t * sm)
{
	return  (sm != NULL) ? sm->getNumChanges() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedChange_t *
SedModel_removeChange(SedModel_t * sm, unsigned int n)
{
	return  (sm != NULL) ? sm->removeChange(n) : NULL;
}

LIBSEDML_EXTERN
SedChange_t *
SedModel_removeChangeById(SedModel_t * sm, const char * sid)
{
	return  (sm != NULL) ? sm->removeChange(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_hasRequiredAttributes(SedModel_t * sm)
{
	return (sm != NULL) ? static_cast<int>(sm->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedModel_hasRequiredElements(SedModel_t * sm)
{
	return (sm != NULL) ? static_cast<int>(sm->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedModel_t *
SedListOfModels_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfModels *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedModel_t *
SedListOfModels_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfModels *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


