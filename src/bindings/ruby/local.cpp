/**
 * @file local.cpp
 * @brief Implementation of the local class.
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



#include <cstddef>
#include "sedml/SedBase.h"

/**
* @return the most specific Swig type for the given SedBase object.
*/
struct swig_type_info*
GetDowncastSwigType (SedBase* sb)
{
  if (sb == 0) return SWIGTYPE_p_SedBase;

  std::string name;

  switch (sb->getTypeCode())
  {
  case SEDML_DOCUMENT:
    return SWIGTYPE_p_SedDocument;

    case SEDML_MODEL:
      return SWIGTYPE_p_SedModel;

    case SEDML_CHANGE:
      return SWIGTYPE_p_SedChange;

    case SEDML_CHANGE_ADDXML:
      return SWIGTYPE_p_SedAddXML;

    case SEDML_CHANGE_ATTRIBUTE:
      return SWIGTYPE_p_SedChangeAttribute;

    case SEDML_VARIABLE:
      return SWIGTYPE_p_SedVariable;

    case SEDML_PARAMETER:
      return SWIGTYPE_p_SedParameter;

    case SEDML_SIMULATION:
      return SWIGTYPE_p_SedSimulation;

    case SEDML_SIMULATION_UNIFORMTIMECOURSE:
      return SWIGTYPE_p_SedUniformTimeCourse;

    case SEDML_SIMULATION_ALGORITHM:
      return SWIGTYPE_p_SedAlgorithm;

    case SEDML_SEDML_ABSTRACTTASK:
      return SWIGTYPE_p_SedAbstractTask;

    case SEDML_TASK:
      return SWIGTYPE_p_SedTask;

    case SEDML_DATAGENERATOR:
      return SWIGTYPE_p_SedDataGenerator;

    case SEDML_OUTPUT:
      return SWIGTYPE_p_SedOutput;

    case SEDML_OUTPUT_PLOT:
      return SWIGTYPE_p_SedPlot;

    case SEDML_OUTPUT_PLOT2D:
      return SWIGTYPE_p_SedPlot2D;

    case SEDML_OUTPUT_PLOT3D:
      return SWIGTYPE_p_SedPlot3D;

    case SEDML_PARAMETERESTIMATIONRESULTPLOT:
      return SWIGTYPE_p_SedParameterEstimationResultPlot;

    case SEDML_ABSTRACTCURVE:
      return SWIGTYPE_p_SedAbstractCurve;

    case SEDML_OUTPUT_CURVE:
      return SWIGTYPE_p_SedCurve;

    case SEDML_OUTPUT_SURFACE:
      return SWIGTYPE_p_SedSurface;

    case SEDML_OUTPUT_DATASET:
      return SWIGTYPE_p_SedDataSet;

    case SEDML_OUTPUT_REPORT:
      return SWIGTYPE_p_SedReport;

    case SEDML_SIMULATION_ALGORITHM_PARAMETER:
      return SWIGTYPE_p_SedAlgorithmParameter;

    case SEDML_RANGE:
      return SWIGTYPE_p_SedRange;

    case SEDML_CHANGE_CHANGEXML:
      return SWIGTYPE_p_SedChangeXML;

    case SEDML_CHANGE_REMOVEXML:
      return SWIGTYPE_p_SedRemoveXML;

    case SEDML_TASK_SETVALUE:
      return SWIGTYPE_p_SedSetValue;

    case SEDML_RANGE_UNIFORMRANGE:
      return SWIGTYPE_p_SedUniformRange;

    case SEDML_RANGE_VECTORRANGE:
      return SWIGTYPE_p_SedVectorRange;

    case SEDML_RANGE_FUNCTIONALRANGE:
      return SWIGTYPE_p_SedFunctionalRange;

    case SEDML_TASK_SUBTASK:
      return SWIGTYPE_p_SedSubTask;

    case SEDML_SIMULATION_ONESTEP:
      return SWIGTYPE_p_SedOneStep;

    case SEDML_SIMULATION_ANALYSIS:
      return SWIGTYPE_p_SedAnalysis;
      
    case SEDML_SIMULATION_STEADYSTATE:
      return SWIGTYPE_p_SedSteadyState;

    case SEDML_TASK_REPEATEDTASK:
      return SWIGTYPE_p_SedRepeatedTask;

    case SEDML_CHANGE_COMPUTECHANGE:
      return SWIGTYPE_p_SedComputeChange;

    case SEDML_DATA_DESCRIPTION:
      return SWIGTYPE_p_SedDataDescription;

    case SEDML_DATA_SOURCE:
      return SWIGTYPE_p_SedDataSource;

    case SEDML_DATA_SLICE:
      return SWIGTYPE_p_SedSlice;

    case SEDML_TASK_PARAMETER_ESTIMATION:
      return SWIGTYPE_p_SedParameterEstimationTask;

    case SEDML_OBJECTIVE:
      return SWIGTYPE_p_SedObjective;

    case SEDML_LEAST_SQUARE_OBJECTIVE:
      return SWIGTYPE_p_SedLeastSquareObjectiveFunction;

    case SEDML_ADJUSTABLE_PARAMETER:
      return SWIGTYPE_p_SedAdjustableParameter;

    case SEDML_EXPERIMENT_REFERENCE:
      return SWIGTYPE_p_SedExperimentReference;

    case SEDML_FIT_EXPERIMENT:
      return SWIGTYPE_p_SedFitExperiment;

    case SEDML_FITMAPPING:
      return SWIGTYPE_p_SedFitMapping;

    case SEDML_BOUNDS:
      return SWIGTYPE_p_SedBounds;

    case SEDML_FIGURE:
      return SWIGTYPE_p_SedFigure;

    case SEDML_SUBPLOT:
      return SWIGTYPE_p_SedSubPlot;

    case SEDML_AXIS:
      return SWIGTYPE_p_SedAxis;

    case SEDML_STYLE:
      return SWIGTYPE_p_SedStyle;

    case SEDML_LINE:
      return SWIGTYPE_p_SedLine;

    case SEDML_MARKER:
      return SWIGTYPE_p_SedMarker;

    case SEDML_FILL:
      return SWIGTYPE_p_SedFill;

    case SEDML_APPLIEDDIMENSION:
      return SWIGTYPE_p_SedAppliedDimension;

    case SEDML_DATA_RANGE:
      return SWIGTYPE_p_SedDataRange;

    case SEDML_SHADEDAREA:
      return SWIGTYPE_p_SedShadedArea;

    case SEDML_LIST_OF:
      name = sb->getElementName();
      if(name == "listOf")
      {
        return SWIGTYPE_p_SedListOf;
      }
      else if (name == "listOfModels")
      {
         return SWIGTYPE_p_SedListOfModels;
      }
      else if (name == "listOfChanges")
      {
         return SWIGTYPE_p_SedListOfChanges;
      }
      else if (name == "listOfVariables")
      {
         return SWIGTYPE_p_SedListOfVariables;
      }
      else if (name == "listOfParameters")
      {
         return SWIGTYPE_p_SedListOfParameters;
      }
      else if (name == "listOfSimulations")
      {
         return SWIGTYPE_p_SedListOfSimulations;
      }
      else if (name == "listOfTasks")
      {
         return SWIGTYPE_p_SedListOfTasks;
      }
      else if (name == "listOfDataGenerators")
      {
         return SWIGTYPE_p_SedListOfDataGenerators;
      }
      else if (name == "listOfOutputs")
      {
         return SWIGTYPE_p_SedListOfOutputs;
      }
      else if (name == "listOfCurves")
      {
         return SWIGTYPE_p_SedListOfCurves;
      }
      else if (name == "listOfSurfaces")
      {
         return SWIGTYPE_p_SedListOfSurfaces;
      }
      else if (name == "listOfDataSets")
      {
         return SWIGTYPE_p_SedListOfDataSets;
      }
      else if (name == "listOfAlgorithmParameters")
      {
         return SWIGTYPE_p_SedListOfAlgorithmParameters;
      }
      else if (name == "listOfRanges")
      {
         return SWIGTYPE_p_SedListOfRanges;
      }
      else if (name == "listOfChanges")
      {
         return SWIGTYPE_p_SedListOfSetValues;
      }
      else if (name == "listOfSubTasks")
      {
         return SWIGTYPE_p_SedListOfSubTasks;
      }
      else if (name == "listOfDataDescriptions")
      {
         return SWIGTYPE_p_SedListOfDataDescriptions;
      }
      else if (name == "listOfDataSources")
      {
         return SWIGTYPE_p_SedListOfDataSources;
      }
      else if (name == "listOfSlices")
      {
         return SWIGTYPE_p_SedListOfSlices;
      }
      else if (name == "listOfAdjustableParameters")
      {
         return SWIGTYPE_p_SedListOfAdjustableParameters;
      }
      else if (name == "listOfExperimentReferences")
      {
         return SWIGTYPE_p_SedListOfExperimentReferences;
      }
      else if (name == "listOfFitExperiments")
      {
         return SWIGTYPE_p_SedListOfFitExperiments;
      }
      else if (name == "listOfFitMappings")
      {
         return SWIGTYPE_p_SedListOfFitMappings;
      }
      else if (name == "listOfSubPlots")
      {
         return SWIGTYPE_p_SedListOfSubPlots;
      }
      else if (name == "listOfAppliedDimensions")
      {
         return SWIGTYPE_p_SedListOfAppliedDimensions;
      }
      else if (name == "listOfStyles")
      {
         return SWIGTYPE_p_SedListOfStyles;
      }
    
    return SWIGTYPE_p_SedListOf;
    
  default:
    return SWIGTYPE_p_SedBase;
  }

  return SWIGTYPE_p_SedBase;
}

/* Compatibility bug fix for swig 2.0.7 and Python 3. 
* See http://patch-tracker.debian.org/patch/series/view/swig2.0/2.0.7-3/pyint_fromsize_t.diff
*/
#if (PY_MAJOR_VERSION >= 3)
#define PyInt_FromSize_t(x) PyLong_FromSize_t(x)
#endif

int fixNegativeIndex(int i, SedListOf *l){
  if (i < 0){
    return i + l->size();
  } else {
    return i;
  }
}
