/**
 * @file SedScaling.cpp
 * @brief Implementation of the SedScaling class.
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
#include <sedml/SedScaling.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedValueScaling.h>
#include <sedml/SedColumnScaling.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedScaling using the given SEDML Level and @ p version values.
 */
SedScaling::SedScaling(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mElementName("scaling")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedScaling using the given SedNamespaces object @p sedmlns.
 */
SedScaling::SedScaling(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mElementName("scaling")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedScaling.
 */
SedScaling::SedScaling(const SedScaling& orig)
  : SedBase( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedScaling.
 */
SedScaling&
SedScaling::operator=(const SedScaling& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedScaling object.
 */
SedScaling*
SedScaling::clone() const
{
  return new SedScaling(*this);
}


/*
 * Destructor for SedScaling.
 */
SedScaling::~SedScaling()
{
}


/*
 * Predicate returning @c true if this abstract "SedScaling" is of type
 * SedValueScaling
 */
bool
SedScaling::isSedValueScaling() const
{
  return dynamic_cast<const SedValueScaling*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "SedScaling" is of type
 * SedColumnScaling
 */
bool
SedScaling::isSedColumnScaling() const
{
  return dynamic_cast<const SedColumnScaling*>(this) != NULL;
}


/*
 * Returns the XML element name of this SedScaling object.
 */
const std::string&
SedScaling::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedScaling object.
 */
void
SedScaling::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedScaling object.
 */
int
SedScaling::getTypeCode() const
{
  return SEDML_SCALING;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedScaling::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedScaling::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedScaling::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedScaling's attribute "attributeName"
 * is set.
 */
bool
SedScaling::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedScaling.
 */
int
SedScaling::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedValueScaling (SedScaling_t) using the given SEDML Level and
 * @ p version values.
 */
LIBSEDML_EXTERN
SedScaling_t *
SedScaling_createValueScaling(unsigned int level, unsigned int version)
{
  return new SedValueScaling(level, version);
}


/*
 * Creates a new SedColumnScaling (SedScaling_t) using the given SEDML Level
 * and @ p version values.
 */
LIBSEDML_EXTERN
SedScaling_t *
SedScaling_createColumnScaling(unsigned int level, unsigned int version)
{
  return new SedColumnScaling(level, version);
}


/*
 * Creates and returns a deep copy of this SedScaling_t object.
 */
LIBSEDML_EXTERN
SedScaling_t*
SedScaling_clone(const SedScaling_t* ss)
{
  if (ss != NULL)
  {
    return static_cast<SedScaling_t*>(ss->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedScaling_t object.
 */
LIBSEDML_EXTERN
void
SedScaling_free(SedScaling_t* ss)
{
  if (ss != NULL)
  {
    delete ss;
  }
}


/*
 * Predicate returning @c 1 if this SedScaling_t is of type SedValueScaling_t
 */
LIBSEDML_EXTERN
int
SedScaling_isSedValueScaling(const SedScaling_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSedValueScaling()) : 0;
}


/*
 * Predicate returning @c 1 if this SedScaling_t is of type SedColumnScaling_t
 */
LIBSEDML_EXTERN
int
SedScaling_isSedColumnScaling(const SedScaling_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSedColumnScaling()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


