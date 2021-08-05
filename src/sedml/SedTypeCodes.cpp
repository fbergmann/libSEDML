/**
 * @file SedTypeCodes.cpp
 * @brief Implementation of the SedTypeCodes class.
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



#include <sedml/common/common.h>
#include <sedml/SedTypeCodes.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

static
const char* SEDML_TYPE_CODE_STRINGS[] =
{
    "(Unknown SED-ML Type)"
  , "SedDocument"
  , "Model"
  , "Change"
  , "AddXML"
  , "ChangeAttribute"
  , "Variable"
  , "Parameter"
  , "Simulation"
  , "UniformTimeCourse"
  , "Algorithm"
  , "AbstractTask"
  , "Task"
  , "DataGenerator"
  , "Output"
  , "Plot"
  , "Plot2D"
  , "Plot3D"
  , "AbstractCurve"
  , "Curve"
  , "Surface"
  , "DataSet"
  , "Report"
  , "AlgorithmParameter"
  , "Range"
  , "ChangeXML"
  , "RemoveXML"
  , "SetValue"
  , "UniformRange"
  , "VectorRange"
  , "FunctionalRange"
  , "SubTask"
  , "Analysis"
  , "OneStep"
  , "SteadyState"
  , "RepeatedTask"
  , "ComputeChange"
  , "DataDescription"
  , "DataSource"
  , "Slice"
  , "ParameterEstimationTask"
  , "Objective"
  , "LeastSquareObjectiveFunction"
  , "AdjustableParameter"
  , "ExperimentReference"
  , "FitExperiment"
  , "FitMapping"
  , "Bounds"
  , "Figure"
  , "SubPlot"
  , "Axis"
  , "Style"
  , "Line"
  , "Marker"
  , "Fill"
  , "AppliedDimension"
  , "DataRange"
  , "ShadedArea"
  , "ParameterEstimationResultPlot"
  , "WaterfallPlot"
  , "ParameterEstimationReport"
  , "SedListOf"
};


LIBSEDML_EXTERN
const char *
SedTypeCode_toString (int tc)
{
  int max = SEDML_LIST_OF;

  if (tc < SEDML_UNKNOWN + 1 || tc > max)
  {
    tc = SEDML_UNKNOWN;
  }

  return SEDML_TYPE_CODE_STRINGS[tc];
}

LIBSEDML_CPP_NAMESPACE_END

