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

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedVectorRange with the given SedNamespaces object.
 */
SedVectorRange::SedVectorRange (SedNamespaces* sedns)
	: SedRange(sedns)

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
   * @return the number of items
   */
  unsigned int SedVectorRange::getNumValues() const
  {
    return mValues.size();
  }
  
  /**
   * @return the value at the given index, or NaN.
   */
  double SedVectorRange::getValue(unsigned int index) const
  {
    if (index > mValues.size())
      return numeric_limits<double>::quiet_NaN();
    return mValues[index];
  }
  
  /**
   * clears the vector of values
   */
  void SedVectorRange::clearValues()
  {
    mValues.clear();
  }
  
  /** 
   * adds the given value
   */ 
  void SedVectorRange::addValue(double value)
  {
    mValues.push_back(value);
  }
  
  /**
   * removes the item at the given index and returns it
   */
  double SedVectorRange::removeValueAt(unsigned int index)
  {
    std::vector<double>::iterator it = mValues.begin() + index;
    if (it == mValues.end())
      return numeric_limits<double>::quiet_NaN();
    double result = *it;
    mValues.erase(it);
    return result;
  }
  
  /**
   * sets the value at the given index
   */ 
  void SedVectorRange::setValue(unsigned int index, double value)
  {
    if (index > mValues.size())
     return;
    mValues[index] = value;
  }
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
LIBSEDML_EXTERN
int
SedVectorRange_hasRequiredAttributes(SedVectorRange_t * svr)
{
	return (svr != NULL) ? static_cast<int>(svr->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


