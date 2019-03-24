/**
 * @file SedColumnScaling.cpp
 * @brief Implementation of the SedColumnScaling class.
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
#include <sedml/SedColumnScaling.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedColumnScaling using the given SEDML Level and @ p version
 * values.
 */
SedColumnScaling::SedColumnScaling(unsigned int level, unsigned int version)
  : SedScaling(level, version)
  , mDataSource ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedColumnScaling using the given SedNamespaces object @p
 * sedmlns.
 */
SedColumnScaling::SedColumnScaling(SedNamespaces *sedmlns)
  : SedScaling(sedmlns)
  , mDataSource ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedColumnScaling.
 */
SedColumnScaling::SedColumnScaling(const SedColumnScaling& orig)
  : SedScaling( orig )
  , mDataSource ( orig.mDataSource )
{
}


/*
 * Assignment operator for SedColumnScaling.
 */
SedColumnScaling&
SedColumnScaling::operator=(const SedColumnScaling& rhs)
{
  if (&rhs != this)
  {
    SedScaling::operator=(rhs);
    mDataSource = rhs.mDataSource;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedColumnScaling object.
 */
SedColumnScaling*
SedColumnScaling::clone() const
{
  return new SedColumnScaling(*this);
}


/*
 * Destructor for SedColumnScaling.
 */
SedColumnScaling::~SedColumnScaling()
{
}


/*
 * Returns the value of the "dataSource" attribute of this SedColumnScaling.
 */
const std::string&
SedColumnScaling::getDataSource() const
{
  return mDataSource;
}


/*
 * Predicate returning @c true if this SedColumnScaling's "dataSource"
 * attribute is set.
 */
bool
SedColumnScaling::isSetDataSource() const
{
  return (mDataSource.empty() == false);
}


/*
 * Sets the value of the "dataSource" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::setDataSource(const std::string& dataSource)
{
  if (!(SyntaxChecker::isValidInternalSId(dataSource)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mDataSource = dataSource;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "dataSource" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::unsetDataSource()
{
  mDataSource.erase();

  if (mDataSource.empty() == true)
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
SedColumnScaling::renameSIdRefs(const std::string& oldid,
                                const std::string& newid)
{
  if (isSetDataSource() && mDataSource == oldid)
  {
    setDataSource(newid);
  }
}


/*
 * Returns the XML element name of this SedColumnScaling object.
 */
const std::string&
SedColumnScaling::getElementName() const
{
  static const string name = "columnScaling";
  return name;
}


/*
 * Returns the libSEDML type code for this SedColumnScaling object.
 */
int
SedColumnScaling::getTypeCode() const
{
  return SEDML_COLUMNSCALING;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedColumnScaling object have been set.
 */
bool
SedColumnScaling::hasRequiredAttributes() const
{
  bool allPresent = SedScaling::hasRequiredAttributes();

  if (isSetDataSource() == false)
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
SedColumnScaling::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedScaling::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedColumnScaling::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedColumnScaling::setSedDocument(SedDocument* d)
{
  SedScaling::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::getAttribute(const std::string& attributeName,
                               bool& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::getAttribute(const std::string& attributeName,
                               int& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::getAttribute(const std::string& attributeName,
                               double& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::getAttribute(const std::string& attributeName,
                               unsigned int& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::getAttribute(const std::string& attributeName,
                               std::string& value) const
{
  int return_value = SedScaling::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "dataSource")
  {
    value = getDataSource();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedColumnScaling's attribute
 * "attributeName" is set.
 */
bool
SedColumnScaling::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedScaling::isSetAttribute(attributeName);

  if (attributeName == "dataSource")
  {
    value = isSetDataSource();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::setAttribute(const std::string& attributeName,
                               unsigned int value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::setAttribute(const std::string& attributeName,
                               const std::string& value)
{
  int return_value = SedScaling::setAttribute(attributeName, value);

  if (attributeName == "dataSource")
  {
    return_value = setDataSource(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedColumnScaling.
 */
int
SedColumnScaling::unsetAttribute(const std::string& attributeName)
{
  int value = SedScaling::unsetAttribute(attributeName);

  if (attributeName == "dataSource")
  {
    value = unsetDataSource();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedColumnScaling::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedScaling::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedColumnScaling::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedScaling::addExpectedAttributes(attributes);

  attributes.add("dataSource");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedColumnScaling::readAttributes(
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

  SedScaling::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlColumnScalingAllowedAttributes, level, version,
          details);
      }
    }
  }

  // 
  // dataSource SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("dataSource", mDataSource);

  if (assigned == true)
  {
    if (mDataSource.empty() == true)
    {
      logEmptyString(mDataSource, level, version, "<SedColumnScaling>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mDataSource) == false)
    {
      std::string msg = "The dataSource attribute on the <" + getElementName()
        + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mDataSource + "', which does not conform to the "
        "syntax.";
      logError(SedmlColumnScalingDataSourceMustBeDataSource, level, version,
        msg);
    }
  }
  else
  {
    std::string message = "Sedml attribute 'dataSource' is missing from the "
      "<SedColumnScaling> element.";
    log->logError(SedmlColumnScalingAllowedAttributes, level, version,
      message);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedColumnScaling::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedScaling::writeAttributes(stream);

  if (isSetDataSource() == true)
  {
    stream.writeAttribute("dataSource", getPrefix(), mDataSource);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedColumnScaling_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedColumnScaling_t *
SedColumnScaling_create(unsigned int level, unsigned int version)
{
  return new SedColumnScaling(level, version);
}


/*
 * Creates and returns a deep copy of this SedColumnScaling_t object.
 */
LIBSEDML_EXTERN
SedColumnScaling_t*
SedColumnScaling_clone(const SedColumnScaling_t* scs)
{
  if (scs != NULL)
  {
    return static_cast<SedColumnScaling_t*>(scs->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedColumnScaling_t object.
 */
LIBSEDML_EXTERN
void
SedColumnScaling_free(SedColumnScaling_t* scs)
{
  if (scs != NULL)
  {
    delete scs;
  }
}


/*
 * Returns the value of the "dataSource" attribute of this SedColumnScaling_t.
 */
LIBSEDML_EXTERN
char *
SedColumnScaling_getDataSource(const SedColumnScaling_t * scs)
{
  if (scs == NULL)
  {
    return NULL;
  }

  return scs->getDataSource().empty() ? NULL :
    safe_strdup(scs->getDataSource().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SedColumnScaling_t's "dataSource"
 * attribute is set.
 */
LIBSEDML_EXTERN
int
SedColumnScaling_isSetDataSource(const SedColumnScaling_t * scs)
{
  return (scs != NULL) ? static_cast<int>(scs->isSetDataSource()) : 0;
}


/*
 * Sets the value of the "dataSource" attribute of this SedColumnScaling_t.
 */
LIBSEDML_EXTERN
int
SedColumnScaling_setDataSource(SedColumnScaling_t * scs,
                               const char * dataSource)
{
  return (scs != NULL) ? scs->setDataSource(dataSource) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "dataSource" attribute of this SedColumnScaling_t.
 */
LIBSEDML_EXTERN
int
SedColumnScaling_unsetDataSource(SedColumnScaling_t * scs)
{
  return (scs != NULL) ? scs->unsetDataSource() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedColumnScaling_t object have been set.
 */
LIBSEDML_EXTERN
int
SedColumnScaling_hasRequiredAttributes(const SedColumnScaling_t * scs)
{
  return (scs != NULL) ? static_cast<int>(scs->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


