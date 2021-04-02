/**
 * @file SedShadedArea.cpp
 * @brief Implementation of the SedShadedArea class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sedml/SedShadedArea.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedShadedArea using the given SED-ML Level and @ p version
 * values.
 */
SedShadedArea::SedShadedArea(unsigned int level, unsigned int version)
  : SedAbstractCurve(level, version)
  , mYDataReferenceFrom ("")
  , mYDataReferenceTo ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedShadedArea using the given SedNamespaces object @p sedmlns.
 */
SedShadedArea::SedShadedArea(SedNamespaces *sedmlns)
  : SedAbstractCurve(sedmlns)
  , mYDataReferenceFrom ("")
  , mYDataReferenceTo ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedShadedArea.
 */
SedShadedArea::SedShadedArea(const SedShadedArea& orig)
  : SedAbstractCurve( orig )
  , mYDataReferenceFrom ( orig.mYDataReferenceFrom )
  , mYDataReferenceTo ( orig.mYDataReferenceTo )
{
}


/*
 * Assignment operator for SedShadedArea.
 */
SedShadedArea&
SedShadedArea::operator=(const SedShadedArea& rhs)
{
  if (&rhs != this)
  {
    SedAbstractCurve::operator=(rhs);
    mYDataReferenceFrom = rhs.mYDataReferenceFrom;
    mYDataReferenceTo = rhs.mYDataReferenceTo;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedShadedArea object.
 */
SedShadedArea*
SedShadedArea::clone() const
{
  return new SedShadedArea(*this);
}


/*
 * Destructor for SedShadedArea.
 */
SedShadedArea::~SedShadedArea()
{
}


/*
 * Returns the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea.
 */
const std::string&
SedShadedArea::getYDataReferenceFrom() const
{
  return mYDataReferenceFrom;
}


/*
 * Returns the value of the "yDataReferenceTo" attribute of this SedShadedArea.
 */
const std::string&
SedShadedArea::getYDataReferenceTo() const
{
  return mYDataReferenceTo;
}


/*
 * Predicate returning @c true if this SedShadedArea's "yDataReferenceFrom"
 * attribute is set.
 */
bool
SedShadedArea::isSetYDataReferenceFrom() const
{
  return (mYDataReferenceFrom.empty() == false);
}


/*
 * Predicate returning @c true if this SedShadedArea's "yDataReferenceTo"
 * attribute is set.
 */
bool
SedShadedArea::isSetYDataReferenceTo() const
{
  return (mYDataReferenceTo.empty() == false);
}


/*
 * Sets the value of the "yDataReferenceFrom" attribute of this SedShadedArea.
 */
int
SedShadedArea::setYDataReferenceFrom(const std::string& yDataReferenceFrom)
{
  if (!(SyntaxChecker::isValidInternalSId(yDataReferenceFrom)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mYDataReferenceFrom = yDataReferenceFrom;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "yDataReferenceTo" attribute of this SedShadedArea.
 */
int
SedShadedArea::setYDataReferenceTo(const std::string& yDataReferenceTo)
{
  if (!(SyntaxChecker::isValidInternalSId(yDataReferenceTo)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mYDataReferenceTo = yDataReferenceTo;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea.
 */
int
SedShadedArea::unsetYDataReferenceFrom()
{
  mYDataReferenceFrom.erase();

  if (mYDataReferenceFrom.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "yDataReferenceTo" attribute of this SedShadedArea.
 */
int
SedShadedArea::unsetYDataReferenceTo()
{
  mYDataReferenceTo.erase();

  if (mYDataReferenceTo.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedShadedArea::renameSIdRefs(const std::string& oldid,
                             const std::string& newid)
{
  if (isSetYDataReferenceFrom() && mYDataReferenceFrom == oldid)
  {
    setYDataReferenceFrom(newid);
  }

  if (isSetYDataReferenceTo() && mYDataReferenceTo == oldid)
  {
    setYDataReferenceTo(newid);
  }
}


/*
 * Returns the XML element name of this SedShadedArea object.
 */
const std::string&
SedShadedArea::getElementName() const
{
  static const string name = "shadedArea";
  return name;
}


/*
 * Returns the libSEDML type code for this SedShadedArea object.
 */
int
SedShadedArea::getTypeCode() const
{
  return SEDML_SHADEDAREA;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedShadedArea object have been set.
 */
bool
SedShadedArea::hasRequiredAttributes() const
{
  bool allPresent = SedAbstractCurve::hasRequiredAttributes();

  if (isSetYDataReferenceFrom() == false)
  {
    allPresent = false;
  }

  if (isSetYDataReferenceTo() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedShadedArea::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedAbstractCurve::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedShadedArea::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedShadedArea::setSedDocument(SedDocument* d)
{
  SedAbstractCurve::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::getAttribute(const std::string& attributeName,
                            bool& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::getAttribute(const std::string& attributeName,
                            int& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::getAttribute(const std::string& attributeName,
                            double& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::getAttribute(const std::string& attributeName,
                            unsigned int& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::getAttribute(const std::string& attributeName,
                            std::string& value) const
{
  int return_value = SedAbstractCurve::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "yDataReferenceFrom")
  {
    value = getYDataReferenceFrom();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "yDataReferenceTo")
  {
    value = getYDataReferenceTo();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedShadedArea's attribute
 * "attributeName" is set.
 */
bool
SedShadedArea::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedAbstractCurve::isSetAttribute(attributeName);

  if (attributeName == "yDataReferenceFrom")
  {
    value = isSetYDataReferenceFrom();
  }
  else if (attributeName == "yDataReferenceTo")
  {
    value = isSetYDataReferenceTo();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::setAttribute(const std::string& attributeName,
                            unsigned int value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::setAttribute(const std::string& attributeName,
                            const std::string& value)
{
  int return_value = SedAbstractCurve::setAttribute(attributeName, value);

  if (attributeName == "yDataReferenceFrom")
  {
    return_value = setYDataReferenceFrom(value);
  }
  else if (attributeName == "yDataReferenceTo")
  {
    return_value = setYDataReferenceTo(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedShadedArea.
 */
int
SedShadedArea::unsetAttribute(const std::string& attributeName)
{
  int value = SedAbstractCurve::unsetAttribute(attributeName);

  if (attributeName == "yDataReferenceFrom")
  {
    value = unsetYDataReferenceFrom();
  }
  else if (attributeName == "yDataReferenceTo")
  {
    value = unsetYDataReferenceTo();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedShadedArea::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedAbstractCurve::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedShadedArea::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedAbstractCurve::addExpectedAttributes(attributes);

  attributes.add("yDataReferenceFrom");

  attributes.add("yDataReferenceTo");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedShadedArea::readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedAbstractCurve::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlShadedAreaAllowedAttributes, level, version,
          details, getLine(), getColumn());
      }
    }
  }

  // 
  // yDataReferenceFrom SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("yDataReferenceFrom", mYDataReferenceFrom);

  if (assigned == true)
  {
    if (mYDataReferenceFrom.empty() == true)
    {
      logEmptyString(mYDataReferenceFrom, level, version, "<SedShadedArea>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mYDataReferenceFrom) == false)
    {
      std::string msg = "The yDataReferenceFrom attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mYDataReferenceFrom + "', which does not conform to the "
        "syntax.";
      logError(SedmlShadedAreaYDataReferenceFromMustBeDataGenerator, level,
        version, msg, getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'yDataReferenceFrom' is missing "
        "from the <SedShadedArea> element.";
      log->logError(SedmlShadedAreaAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // yDataReferenceTo SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("yDataReferenceTo", mYDataReferenceTo);

  if (assigned == true)
  {
    if (mYDataReferenceTo.empty() == true)
    {
      logEmptyString(mYDataReferenceTo, level, version, "<SedShadedArea>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mYDataReferenceTo) == false)
    {
      std::string msg = "The yDataReferenceTo attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mYDataReferenceTo + "', which does not conform to the "
        "syntax.";
      logError(SedmlShadedAreaYDataReferenceToMustBeDataGenerator, level,
        version, msg, getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'yDataReferenceTo' is missing from "
        "the <SedShadedArea> element.";
      log->logError(SedmlShadedAreaAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedShadedArea::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedAbstractCurve::writeAttributes(stream);

  if (isSetYDataReferenceFrom() == true)
  {
    stream.writeAttribute("yDataReferenceFrom", getPrefix(),
      mYDataReferenceFrom);
  }

  if (isSetYDataReferenceTo() == true)
  {
    stream.writeAttribute("yDataReferenceTo", getPrefix(), mYDataReferenceTo);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedShadedArea_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedShadedArea_t *
SedShadedArea_create(unsigned int level, unsigned int version)
{
  return new SedShadedArea(level, version);
}


/*
 * Creates and returns a deep copy of this SedShadedArea_t object.
 */
LIBSEDML_EXTERN
SedShadedArea_t*
SedShadedArea_clone(const SedShadedArea_t* ssa)
{
  if (ssa != NULL)
  {
    return static_cast<SedShadedArea_t*>(ssa->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedShadedArea_t object.
 */
LIBSEDML_EXTERN
void
SedShadedArea_free(SedShadedArea_t* ssa)
{
  if (ssa != NULL)
  {
    delete ssa;
  }
}


/*
 * Returns the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea_t.
 */
LIBSEDML_EXTERN
char *
SedShadedArea_getYDataReferenceFrom(const SedShadedArea_t * ssa)
{
  if (ssa == NULL)
  {
    return NULL;
  }

  return ssa->getYDataReferenceFrom().empty() ? NULL :
    safe_strdup(ssa->getYDataReferenceFrom().c_str());
}


/*
 * Returns the value of the "yDataReferenceTo" attribute of this
 * SedShadedArea_t.
 */
LIBSEDML_EXTERN
char *
SedShadedArea_getYDataReferenceTo(const SedShadedArea_t * ssa)
{
  if (ssa == NULL)
  {
    return NULL;
  }

  return ssa->getYDataReferenceTo().empty() ? NULL :
    safe_strdup(ssa->getYDataReferenceTo().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedShadedArea_t's
 * "yDataReferenceFrom" attribute is set.
 */
LIBSEDML_EXTERN
int
SedShadedArea_isSetYDataReferenceFrom(const SedShadedArea_t * ssa)
{
  return (ssa != NULL) ? static_cast<int>(ssa->isSetYDataReferenceFrom()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedShadedArea_t's "yDataReferenceTo"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedShadedArea_isSetYDataReferenceTo(const SedShadedArea_t * ssa)
{
  return (ssa != NULL) ? static_cast<int>(ssa->isSetYDataReferenceTo()) : 0;
}


/*
 * Sets the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea_t.
 */
LIBSEDML_EXTERN
int
SedShadedArea_setYDataReferenceFrom(SedShadedArea_t * ssa,
                                    const char * yDataReferenceFrom)
{
  return (ssa != NULL) ? ssa->setYDataReferenceFrom(yDataReferenceFrom) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "yDataReferenceTo" attribute of this SedShadedArea_t.
 */
LIBSEDML_EXTERN
int
SedShadedArea_setYDataReferenceTo(SedShadedArea_t * ssa,
                                  const char * yDataReferenceTo)
{
  return (ssa != NULL) ? ssa->setYDataReferenceTo(yDataReferenceTo) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "yDataReferenceFrom" attribute of this
 * SedShadedArea_t.
 */
LIBSEDML_EXTERN
int
SedShadedArea_unsetYDataReferenceFrom(SedShadedArea_t * ssa)
{
  return (ssa != NULL) ? ssa->unsetYDataReferenceFrom() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "yDataReferenceTo" attribute of this
 * SedShadedArea_t.
 */
LIBSEDML_EXTERN
int
SedShadedArea_unsetYDataReferenceTo(SedShadedArea_t * ssa)
{
  return (ssa != NULL) ? ssa->unsetYDataReferenceTo() :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedShadedArea_t object have been set.
 */
LIBSEDML_EXTERN
int
SedShadedArea_hasRequiredAttributes(const SedShadedArea_t * ssa)
{
  return (ssa != NULL) ? static_cast<int>(ssa->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


