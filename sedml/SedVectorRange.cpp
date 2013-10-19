/**
 * @file:   SedVectorRange.cpp
 * @brief:  Implementation of the SedVectorRange class
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


#include <sedml/SedVectorRange.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedVectorRange with the given level, version, and package version.
 */
SedVectorRange::SedVectorRange (unsigned int level, unsigned int version)
	: SedRange(level, version)
	, mValues ()

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedVectorRange with the given SedNamespaces object.
 */
SedVectorRange::SedVectorRange (SedNamespaces* sedns)
	: SedRange(sedns)
	, mValues ()

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());
}


/*
 * Copy constructor for SedVectorRange.
 */
SedVectorRange::SedVectorRange (const SedVectorRange& orig)
	: SedRange(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mValues  = orig.mValues;
	}
}


/*
 * Assignment for SedVectorRange.
 */
SedVectorRange&
SedVectorRange::operator=(const SedVectorRange& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedRange::operator=(rhs);
		mValues  = rhs.mValues;
	}
	return *this;
}


/*
 * Clone for SedVectorRange.
 */
SedVectorRange*
SedVectorRange::clone () const
{
	return new SedVectorRange(*this);
}


/*
 * Destructor for SedVectorRange.
 */
SedVectorRange::~SedVectorRange ()
{
}


/*
 * Returns the value of the "value" attribute of this SedVectorRange.
 */
const std::vector<double>&
SedVectorRange::getValues() const
{
	return mValues;
}


/*
 * Returns the value of the "value" attribute of this SedVectorRange.
 */
std::vector<double>&
SedVectorRange::getValues()
{
	return mValues;
}


/**
 * Predicate returning @c true or @c false depending on whether this
 * SedVectorRange's "value" element has elements set.
 *
 * @return @c true if this SedVectorRange's "value" element has been set,
 * otherwise @c false is returned.
 */
bool
SedVectorRange::hasValues() const
{
	return mValues.size() > 0;
}


/**
 * Returning the number of elements in this
 * SedVectorRange's "value" .
 *
 * @return number of elements in this SedVectorRange's "value" 
 */
unsigned int
SedVectorRange::getNumValues() const
{
	return (unsigned int)mValues.size();
}


/**
 * Sets the value of the "value" attribute of this SedVectorRange.
 *
 * @param value; std::vector<double> value of the "value" attribute to be set
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedVectorRange::setValues(const std::vector<double>& value)
{
	mValues = value;
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Adds another value to the "value" attribute of this SedVectorRange.
 *
 * @param value; double value of the "value" attribute to be added 
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedVectorRange::addValue(double value)
{
	mValues.push_back(value);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Clears the "value" element of this SedVectorRange.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_OPERATION_FAILED
 */
int
SedVectorRange::clearValues()
{
	mValues.clear();
	return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this object
 */
const std::string&
SedVectorRange::getElementName () const
{
	static const string name = "vectorRange";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedVectorRange::createObject(XMLInputStream& stream)
{
	SedBase* object = SedRange::createObject(stream);

	connectToChild();

	return object;
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedVectorRange::getTypeCode () const
{
	return SEDML_RANGE_VECTORRANGE;
}


/*
 * check if all the required attributes are set
 */
bool
SedVectorRange::hasRequiredAttributes () const
{
	bool allPresent = SedRange::hasRequiredAttributes();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedVectorRange::writeElements (XMLOutputStream& stream) const
{
	SedRange::writeElements(stream);
	if(hasValues())
	{
		for (std::vector<double>::const_iterator it = mValues.begin(); it != mValues.end(); ++it)
		{
			stream.startElement("value");
			stream.setAutoIndent(false);
			stream << " " << *it << " ";
			stream.endElement("value");
			stream.setAutoIndent(true);
		}
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedVectorRange::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedVectorRange::setSedDocument (SedDocument* d)
{
	SedRange::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedVectorRange::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedRange::addExpectedAttributes(attributes);

	attributes.add("value");
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedVectorRange::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedRange::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

bool
SedVectorRange::readOtherXML (XMLInputStream& stream)
{
	bool          read = false;
	const string& name = stream.peek().getName();

	while (stream.peek().getName() == "value")
	{
	  stream.next(); // consume start
	  stringstream text;
	  while(stream.isGood() && stream.peek().isText())
	    text << stream.next().getCharacters();
	  double value; text >> value;
	  if (!text.fail())
	    mValues.push_back(value);
	  stream.next(); // consume end
	  read = true;
	}
	if (SedRange::readOtherXML(stream))
	{
		read = true;
	}
	return read;
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedVectorRange::writeAttributes (XMLOutputStream& stream) const
{
	SedRange::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedVectorRange_t *
SedVectorRange_create(unsigned int level, unsigned int version)
{
	return new SedVectorRange(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedVectorRange_free(SedVectorRange_t * svr)
{
	if (svr != NULL)
		delete svr;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedVectorRange_t *
SedVectorRange_clone(SedVectorRange_t * svr)
{
	if (svr != NULL)
	{
		return static_cast<SedVectorRange_t*>(svr->clone());
	}
	else
	{
		return NULL;
	}
}


/**
 * write comments
 */
/**
 * write comments
 */
/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedVectorRange_hasRequiredAttributes(SedVectorRange_t * svr)
{
	return (svr != NULL) ? static_cast<int>(svr->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


