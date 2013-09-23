/**
 * @file    SedTypeCodes.cpp
 * @brief   Enumeration to identify SEDML objects at runtime
 * @author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sbml.org for more
 * information about SEDML, and the latest version of libSEDML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <sedml/common/common.h>
#include <sedml/SedTypeCodes.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

static
const char* SEDML_TYPE_CODE_STRINGS[] =
{
      "(Unknown SEDML Type)"
    , "SedDocument"
    , "Model"
    , "Change"
    , "ChangeAttribute"
    , "RemoveXML"
    , "ComputeChange"
    , "AddXML"
    , "ChangeXML"
    , "DataGenerator"
    , "Variable"
    , "Parameter"
    , "Task"
    , "SubTask"
    , "SetValue"
    , "RepeatedTask"
    , "Output"
    , "DataSet"
    , "Curve"
    , "Surface"
    , "Report"
    , "Plot2D"
    , "Plot3D"
	, "Simulation"
	, "Algorithm"
	, "UniformTimeCourse"
    , "AlgorithmParameter"
    , "OneStep"
    , "SteadyState"
    , "Range"
    , "UniformRange"
    , "VectorRange"
    , "FunctionalRange"
	, "SedListOf"
};


/**
 * @return a human readable name for the given typecode and package name.  
 * The caller does not own the returned string and is therefore not allowed 
 * to modify it.
 */
LIBSEDML_EXTERN
const char *
SedTypeCode_toString (int tc)
{
    int max = SEDML_LIST_OF;

    if (tc < SEDML_DOCUMENT || tc > max)
    {
      tc = SEDML_UNKNOWN;
    }

    return SEDML_TYPE_CODE_STRINGS[tc];
}

LIBSEDML_CPP_NAMESPACE_END

