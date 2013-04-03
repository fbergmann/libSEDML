/**
 * @file:   SedMLModel.cpp
 * @brief:  Implementation of the SedMLModel class
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


#include <sedml/SedMLModel.h>
#include <sedml/SedMLTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedMLModel with the given level, version, and package version.
 */
SedMLModel::SedMLModel (unsigned int level, unsigned int version)
	: SedBase(level, version)
	, mId ("")
	, mName ("")
	, mLanguage ("")
	, mSource ("")
	, mChange (level, version)

{
	// set an SedMLNamespaces derived object of this package
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedMLModel with the given SedMLNamespaces object.
 */
SedMLModel::SedMLModel (SedMLNamespaces* sedmlns)
	: SedBase(sedmlns)
	, mId ("")
	, mName ("")
	, mLanguage ("")
	, mSource ("")
	, mChange (sedmlns)

{
	// set the element namespace of this object
	setElementNamespace(sedmlns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedMLModel.
 */
SedMLModel::SedMLModel (const SedMLModel& orig)
	: SedBase(orig)
{
	if (&orig == NULL)
	{
		throw SedMLConstructorException("Null argument to copy constructor");
	}
	else
	{
		mId  = orig.mId;
		mName  = orig.mName;
		mLanguage  = orig.mLanguage;
		mSource  = orig.mSource;
		mChange  = orig.mChange;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedMLModel.
 */
SedMLModel&
SedMLModel::operator=(const SedMLModel& rhs)
{
	if (&rhs == NULL)
	{
		throw SedMLConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedBase::operator=(rhs);
		mId  = rhs.mId;
		mName  = rhs.mName;
		mLanguage  = rhs.mLanguage;
		mSource  = rhs.mSource;
		mChange  = rhs.mChange;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedMLModel.
 */
SedMLModel*
SedMLModel::clone () const
{
	return new SedMLModel(*this);
}


/*
 * Destructor for SedMLModel.
 */
SedMLModel::~SedMLModel ()
{
}


/*
 * Returns the value of the "id" attribute of this SedMLModel.
 */
const std::string&
SedMLModel::getId() const
{
	return mId;
}


/*
/*
 * Returns the value of the "name" attribute of this SedMLModel.
 */
const std::string&
SedMLModel::getName() const
{
	return mName;
}


/*
/*
 * Returns the value of the "language" attribute of this SedMLModel.
 */
const std::string&
SedMLModel::getLanguage() const
{
	return mLanguage;
}


/*
/*
 * Returns the value of the "source" attribute of this SedMLModel.
 */
const std::string&
SedMLModel::getSource() const
{
	return mSource;
}


/*
/*
 * Returns true/false if id is set.
 */
bool
SedMLModel::isSetId() const
{
	return (mId.empty() == false);
}


/*
 * Returns true/false if name is set.
 */
bool
SedMLModel::isSetName() const
{
	return (mName.empty() == false);
}


/*
 * Returns true/false if language is set.
 */
bool
SedMLModel::isSetLanguage() const
{
	return (mLanguage.empty() == false);
}


/*
 * Returns true/false if source is set.
 */
bool
SedMLModel::isSetSource() const
{
	return (mSource.empty() == false);
}


/*
 * Sets id and returns value indicating success.
 */
int
SedMLModel::setId(const std::string& id)
{
	return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets name and returns value indicating success.
 */
int
SedMLModel::setName(const std::string& name)
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
SedMLModel::setLanguage(const std::string& language)
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
SedMLModel::setSource(const std::string& source)
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
SedMLModel::unsetId()
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
SedMLModel::unsetName()
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
SedMLModel::unsetLanguage()
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
SedMLModel::unsetSource()
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
 * Returns the  "SedListOfChanges" in this SedMLModel object.
 */
const SedListOfChanges*
SedMLModel::getListOfChanges() const
{
	return &mChange;
}


/*
 * Removes the nth Change from the SedListOfChanges.
 */
Change*
SedMLModel::removeChange(unsigned int n)
{
	return mChange.remove(n);
}


/*
 * Removes the a Change with given id from the SedListOfChanges.
 */
Change*
SedMLModel::removeChange(const std::string& sid)
{
	return mChange.remove(sid);
}


/*
 * Return the nth Change in the SedListOfChanges within this SedMLModel.
 */
Change*
SedMLModel::getChange(unsigned int n)
{
	return mChange.get(n);
}


/*
 * Return the nth Change in the SedListOfChanges within this SedMLModel.
 */
const Change*
SedMLModel::getChange(unsigned int n) const
{
	return mChange.get(n);
}


/*
 * Return a Change from the SedListOfChanges by id.
 */
Change*
SedMLModel::getChange(const std::string& sid)
{
	return mChange.get(sid);
}


/*
 * Return a Change from the SedListOfChanges by id.
 */
const Change*
SedMLModel::getChange(const std::string& sid) const
{
	return mChange.get(sid);
}


/**
 * Adds a copy the given "Change" to this SedMLModel.
 *
 * @param c; the Change object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedMLModel::addChange(const Change* c)
{
	if(c == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mChange.append(c);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of Change objects in this SedMLModel.
 *
 * @return the number of Change objects in this SedMLModel
 */
unsigned int 
SedMLModel::getNumChanges() const
{
	return mChange.size();
}

/**
 * Creates a new Change object, adds it to this SedMLModels
 * SedMLModel and returns the Change object created. 
 *
 * @return a new Change object instance
 *
 * @see addChange(const Change* c)
 */
Change* 
SedMLModel::createChange()
{
	Change *temp = new Change();
	if (temp != NULL) mChange.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedMLModel::getElementName () const
{
	static const string name = "model";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedMLModel::createObject(XMLInputStream& stream)
{
	SedBase* object = NULL;

	const string& name   = stream.peek().getName();

	SedBase::connectToChild();

	if (name == "listOfChanges")
	{
		object = &mChange;
	}

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedMLModel::connectToChild ()
{
	SedBase::connectToChild();

	mChange.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedMLModel::getTypeCode () const
{
	return SEDML_MODEL;
}


/*
 * check if all the required attributes are set
 */
bool
SedMLModel::hasRequiredAttributes () const
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
SedMLModel::hasRequiredElements () const
{
	bool allPresent = true;

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedMLModel::writeElements (XMLOutputStream& stream) const
{
	SedBase::writeElements(stream);
	if (getNumChanges() > 0)
	{
		mChange.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedMLVisitor.
 */
bool
SedMLModel::accept (SedMLVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedMLDocument.
 */
void
SedMLModel::setSedMLDocument (SedMLDocument* d)
{
	SedBase::setSedMLDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedMLModel::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedBase::addExpectedAttributes(attributes);

	attributes.add("id");
	attributes.add("name");
	attributes.add("language");
	attributes.add("source");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedMLModel::readAttributes (const XMLAttributes& attributes,
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
			logEmptyString(mId, getLevel(), getVersion(), "<SedMLModel>");
		}
		else if (SyntaxChecker::isValidSBMLSId(mId) == false)
		{
			logError(InvalidIdSyntax);
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
			logEmptyString(mName, getLevel(), getVersion(), "<SedMLModel>");
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
			logEmptyString(mLanguage, getLevel(), getVersion(), "<SedMLModel>");
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
			logEmptyString(mSource, getLevel(), getVersion(), "<SedMLModel>");
		}
	}

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedMLModel::writeAttributes (XMLOutputStream& stream) const
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


/** @endcond doxygen-libsbml-internal */


/*
 * Constructor 
 */
SedListOfSedMLModels::SedListOfSedMLModels(unsigned int level, 
	                     unsigned int version)
 : SedListOf(level, version)
{
	setSedMLNamespacesAndOwn(new SedMLNamespaces(level, version)); 
}


/*
 * Constructor 
 */
SedListOfSedMLModels::SedListOfSedMLModels(SedMLNamespaces* sedmlns)
  : SedListOf(sedmlns)
{
	setElementNamespace(sedmlns->getURI());
}


/*
 * Returns a deep copy of this SedListOfSedMLModels 
 */
SedListOfSedMLModels* 
SedListOfSedMLModels::clone () const
 {
	return new SedListOfSedMLModels(*this);
}


/*
 * Get a SedMLModel from the SedListOfSedMLModels by index.
*/
SedMLModel*
SedListOfSedMLModels::get(unsigned int n)
{
	return static_cast<SedMLModel*>(SedListOf::get(n));
}


/*
 * Get a SedMLModel from the SedListOfSedMLModels by index.
 */
const SedMLModel*
SedListOfSedMLModels::get(unsigned int n) const
{
	return static_cast<const SedMLModel*>(SedListOf::get(n));
}


/*
 * Get a SedMLModel from the SedListOfSedMLModels by id.
 */
SedMLModel*
SedListOfSedMLModels::get(const std::string& sid)
{
	return const_cast<SedMLModel*>(
	  static_cast<const SedListOfSedMLModels&>(*this).get(sid));
}


/*
 * Get a SedMLModel from the SedListOfSedMLModels by id.
 */
const SedMLModel*
SedListOfSedMLModels::get(const std::string& sid) const
{
	vector<SedBase*>::const_iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLModel>(sid) );
	return (result == mItems.end()) ? 0 : static_cast <SedMLModel*> (*result);
}


/*
 * Removes the nth SedMLModel from this SedListOfSedMLModels
 */
SedMLModel*
SedListOfSedMLModels::remove(unsigned int n)
{
	return static_cast<SedMLModel*>(SedListOf::remove(n));
}


/*
 * Removes the SedMLModel from this SedListOfSedMLModels with the given identifier
 */
SedMLModel*
SedListOfSedMLModels::remove(const std::string& sid)
{
	SedBase* item = NULL;
	vector<SedBase*>::iterator result;

	result = find_if( mItems.begin(), mItems.end(), IdEq<SedMLModel>(sid) );

	if (result != mItems.end())
	{
		item = *result;
		mItems.erase(result);
	}

	return static_cast <SedMLModel*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedListOfSedMLModels::getElementName () const
{
	static const string name = "listOfModels";
	return name;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedListOfSedMLModels::getTypeCode () const
{
	return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the objects in this LIST_OF.
 */
int
SedListOfSedMLModels::getItemTypeCode () const
{
	return SEDML_MODEL;
}


/** @cond doxygen-libsbml-internal */

/*
 * Creates a new SedMLModel in this SedListOfSedMLModels
 */
SedBase*
SedListOfSedMLModels::createObject(XMLInputStream& stream)
{
	const std::string& name   = stream.peek().getName();
	SedBase* object = NULL;

	if (name == "sedMLModel")
	{
		object = new SedMLModel(getSedMLNamespaces());
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
SedListOfSedMLModels::writeXMLNS(XMLOutputStream& stream) const
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
SedMLModel_t *
SedMLModel_create(unsigned int level, unsigned int version)
{
	return new SedMLModel(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedMLModel_free(SedMLModel_t * smlm)
{
	if (smlm != NULL)
		delete smlm;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLModel_t *
SedMLModel_clone(SedMLModel_t * smlm)
{
	if (smlm != NULL)
	{
		return static_cast<SedMLModel_t*>(smlm->clone());
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
SedMLModel_getId(SedMLModel_t * smlm)
{
	if (smlm == NULL)
		return NULL;

	return smlm->getId().empty() ? NULL : safe_strdup(smlm->getId().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLModel_getName(SedMLModel_t * smlm)
{
	if (smlm == NULL)
		return NULL;

	return smlm->getName().empty() ? NULL : safe_strdup(smlm->getName().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLModel_getLanguage(SedMLModel_t * smlm)
{
	if (smlm == NULL)
		return NULL;

	return smlm->getLanguage().empty() ? NULL : safe_strdup(smlm->getLanguage().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
char *
SedMLModel_getSource(SedMLModel_t * smlm)
{
	if (smlm == NULL)
		return NULL;

	return smlm->getSource().empty() ? NULL : safe_strdup(smlm->getSource().c_str());
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_isSetId(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? static_cast<int>(smlm->isSetId()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_isSetName(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? static_cast<int>(smlm->isSetName()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_isSetLanguage(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? static_cast<int>(smlm->isSetLanguage()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_isSetSource(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? static_cast<int>(smlm->isSetSource()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_setId(SedMLModel_t * smlm, const char * id)
{
	return (smlm != NULL) ? smlm->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_setName(SedMLModel_t * smlm, const char * name)
{
	return (smlm != NULL) ? smlm->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_setLanguage(SedMLModel_t * smlm, const char * language)
{
	return (smlm != NULL) ? smlm->setLanguage(language) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_setSource(SedMLModel_t * smlm, const char * source)
{
	return (smlm != NULL) ? smlm->setSource(source) : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_unsetId(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? smlm->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_unsetName(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? smlm->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_unsetLanguage(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? smlm->unsetLanguage() : LIBSEDML_INVALID_OBJECT;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_unsetSource(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? smlm->unsetSource() : LIBSEDML_INVALID_OBJECT;
}


LIBSEDML_EXTERN
int
SedMLModel_addChange(SedMLModel_t * smlm, Change_t * c)
{
	return  (smlm != NULL) ? smlm->addChange(c) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
Change_t *
SedMLModel_createChange(SedMLModel_t * smlm)
{
	return  (smlm != NULL) ? smlm->createChange() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedMLModel_getSedListOfChanges(SedMLModel_t * smlm)
{
	return  (smlm != NULL) ? (SedListOf_t *)smlm->getListOfChanges() : NULL;
}

LIBSEDML_EXTERN
Change_t *
SedMLModel_getChange(SedMLModel_t * smlm, unsigned int n)
{
	return  (smlm != NULL) ? smlm->getChange(n) : NULL;
}

LIBSEDML_EXTERN
Change_t *
SedMLModel_getChangeById(SedMLModel_t * smlm, const char * sid)
{
	return  (smlm != NULL) ? smlm->getChange(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedMLModel_getNumChanges(SedMLModel_t * smlm)
{
	return  (smlm != NULL) ? smlm->getNumChanges() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
Change_t *
SedMLModel_removeChange(SedMLModel_t * smlm, unsigned int n)
{
	return  (smlm != NULL) ? smlm->removeChange(n) : NULL;
}

LIBSEDML_EXTERN
Change_t *
SedMLModel_removeChangeById(SedMLModel_t * smlm, const char * sid)
{
	return  (smlm != NULL) ? smlm->removeChange(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_hasRequiredAttributes(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? static_cast<int>(smlm->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedMLModel_hasRequiredElements(SedMLModel_t * smlm)
{
	return (smlm != NULL) ? static_cast<int>(smlm->hasRequiredElements()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLModel_t *
SedListOfSedMLModels_getById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLModels *>(lo)->get(sid) : NULL;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedMLModel_t *
SedListOfSedMLModels_removeById(SedListOf_t * lo, const char * sid)
{
	if (lo == NULL)
		return NULL;

	return (sid != NULL) ? static_cast <SedListOfSedMLModels *>(lo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


