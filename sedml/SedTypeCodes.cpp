/**
 * @file    SedTypeCodes.cpp
 * @brief   Enumeration to identify SEDML objects at runtime
 * 
 * <!--------------------------------------------------------------------------
 *
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on 
 * github: https://github.com/fbergmann/libSEDML/
 * 
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
 * 
 * ---------------------------------------------------------------------- -->
 */

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

