/**
 * @file SedListOfOutputs.cpp
 * @brief Implementation of the SedListOfOutputs class.
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
#include <sedml/SedListOfOutputs.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedReport.h>
#include <sedml/SedPlot2D.h>
#include <sedml/SedPlot3D.h>
#include <sedml/SedFigure.h>
#include <sedml/SedParameterEstimationResultPlot.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfOutputs using the given SED-ML Level and @ p version
 * values.
 */
SedListOfOutputs::SedListOfOutputs(unsigned int level, unsigned int version)
  : SedListOf(level, version)
  , mElementName("listOfOutputs")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfOutputs using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfOutputs::SedListOfOutputs(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
  , mElementName("listOfOutputs")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfOutputs.
 */
SedListOfOutputs::SedListOfOutputs(const SedListOfOutputs& orig)
  : SedListOf( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedListOfOutputs.
 */
SedListOfOutputs&
SedListOfOutputs::operator=(const SedListOfOutputs& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfOutputs object.
 */
SedListOfOutputs*
SedListOfOutputs::clone() const
{
  return new SedListOfOutputs(*this);
}


/*
 * Destructor for SedListOfOutputs.
 */
SedListOfOutputs::~SedListOfOutputs()
{
}


/*
 * Get a SedOutput from the SedListOfOutputs.
 */
SedOutput*
SedListOfOutputs::get(unsigned int n)
{
  return static_cast<SedOutput*>(SedListOf::get(n));
}


/*
 * Get a SedOutput from the SedListOfOutputs.
 */
const SedOutput*
SedListOfOutputs::get(unsigned int n) const
{
  return static_cast<const SedOutput*>(SedListOf::get(n));
}


/*
 * Get a SedOutput from the SedListOfOutputs based on its identifier.
 */
SedOutput*
SedListOfOutputs::get(const std::string& sid)
{
  return const_cast<SedOutput*>(static_cast<const
    SedListOfOutputs&>(*this).get(sid));
}


/*
 * Get a SedOutput from the SedListOfOutputs based on its identifier.
 */
const SedOutput*
SedListOfOutputs::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedOutput>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedOutput*>
    (*result);
}


/*
 * Removes the nth SedOutput from this SedListOfOutputs and returns a pointer
 * to it.
 */
SedOutput*
SedListOfOutputs::remove(unsigned int n)
{
  return static_cast<SedOutput*>(SedListOf::remove(n));
}


/*
 * Removes the SedOutput from this SedListOfOutputs based on its identifier and
 * returns a pointer to it.
 */
SedOutput*
SedListOfOutputs::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SedIdEq<SedOutput>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedOutput*> (item);
}


/*
 * Adds a copy of the given SedOutput to this SedListOfOutputs.
 */
int
SedListOfOutputs::addOutput(const SedOutput* so)
{
  if (so == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (so->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != so->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != so->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(so)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(so);
  }
}


/*
 * Get the number of SedOutput objects in this SedListOfOutputs.
 */
unsigned int
SedListOfOutputs::getNumOutputs() const
{
  return size();
}


/*
 * Creates a new SedReport object, adds it to this SedListOfOutputs object and
 * returns the SedReport object created.
 */
SedReport*
SedListOfOutputs::createReport()
{
  SedReport* sr = NULL;

  try
  {
    sr = new SedReport(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sr != NULL)
  {
    appendAndOwn(sr);
  }

  return sr;
}


/*
 * Creates a new SedPlot2D object, adds it to this SedListOfOutputs object and
 * returns the SedPlot2D object created.
 */
SedPlot2D*
SedListOfOutputs::createPlot2D()
{
  SedPlot2D* spd = NULL;

  try
  {
    spd = new SedPlot2D(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (spd != NULL)
  {
    appendAndOwn(spd);
  }

  return spd;
}


/*
 * Creates a new SedPlot3D object, adds it to this SedListOfOutputs object and
 * returns the SedPlot3D object created.
 */
SedPlot3D*
SedListOfOutputs::createPlot3D()
{
  SedPlot3D* spd = NULL;

  try
  {
    spd = new SedPlot3D(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (spd != NULL)
  {
    appendAndOwn(spd);
  }

  return spd;
}


/*
 * Creates a new SedFigure object, adds it to this SedListOfOutputs object and
 * returns the SedFigure object created.
 */
SedFigure*
SedListOfOutputs::createFigure()
{
  SedFigure* sf = NULL;

  try
  {
    sf = new SedFigure(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sf != NULL)
  {
    appendAndOwn(sf);
  }

  return sf;
}


/*
 * Creates a new SedParameterEstimationResultPlot object, adds it to this
 * SedListOfOutputs object and returns the SedParameterEstimationResultPlot
 * object created.
 */
SedParameterEstimationResultPlot*
SedListOfOutputs::createParameterEstimationResultPlot()
{
  SedParameterEstimationResultPlot* sperp = NULL;

  try
  {
    sperp = new SedParameterEstimationResultPlot(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sperp != NULL)
  {
    appendAndOwn(sperp);
  }

  return sperp;
}


/*
 * Returns the XML element name of this SedListOfOutputs object.
 */
const std::string&
SedListOfOutputs::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedListOfOutputs object.
 */
void
SedListOfOutputs::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedListOfOutputs object.
 */
int
SedListOfOutputs::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SED-ML objects contained in this
 * SedListOfOutputs object.
 */
int
SedListOfOutputs::getItemTypeCode() const
{
  return SEDML_OUTPUT;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedOutput in this SedListOfOutputs
 */
SedBase*
SedListOfOutputs::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "output")
  {
    object = new SedOutput(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "report")
  {
    object = new SedReport(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "plot2D")
  {
    object = new SedPlot2D(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "plot3D")
  {
    object = new SedPlot3D(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "figure")
  {
    object = new SedFigure(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "parameterEstimationResultPlot")
  {
    object = new SedParameterEstimationResultPlot(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * checks concrete types
 */
bool
SedListOfOutputs::isValidTypeForList(SedBase* item)
{
  unsigned int tc = item->getTypeCode();

  return ((tc == SEDML_OUTPUT_REPORT) || (tc == SEDML_OUTPUT_PLOT2D) || (tc ==
    SEDML_OUTPUT_PLOT3D) || (tc == SEDML_FIGURE) || (tc ==
      SEDML_PARAMETERESTIMATIONRESULTPLOT));
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedOutput_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedListOfOutputs_getOutput(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfOutputs*>(slo)->get(n);
}


/*
 * Get a SedOutput_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedListOfOutputs_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfOutputs*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SedOutput_t from this SedListOf_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedListOfOutputs_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfOutputs*>(slo)->remove(n);
}


/*
 * Removes the SedOutput_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedOutput_t*
SedListOfOutputs_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfOutputs*>(slo)->remove(sid) :
    NULL;
}




LIBSEDML_CPP_NAMESPACE_END


