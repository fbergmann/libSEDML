/**
 * @file SedVisitor.cpp
 * @brief Implementation of the SedVisitor class.
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



#include <sedml/SedVisitor.h>
#include <sedml/SedTypes.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

SedVisitor::~SedVisitor ()
{
}


void
SedVisitor::visit (const SedDocument& x)
{
  visit( static_cast<const SedBase&>(x) );
}


void
SedVisitor::visit (const SedListOf& x, int type)
{
  visit( static_cast<const SedBase&>(x) );
}


bool
SedVisitor::visit (const SedBase& sb)
{
  return false;
}


/*
 * Visit the SedModel
 */
bool
SedVisitor::visit(const SedModel& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedChange
 */
bool
SedVisitor::visit(const SedChange& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAddXML
 */
bool
SedVisitor::visit(const SedAddXML& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedChangeAttribute
 */
bool
SedVisitor::visit(const SedChangeAttribute& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedVariable
 */
bool
SedVisitor::visit(const SedVariable& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedParameter
 */
bool
SedVisitor::visit(const SedParameter& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSimulation
 */
bool
SedVisitor::visit(const SedSimulation& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedUniformTimeCourse
 */
bool
SedVisitor::visit(const SedUniformTimeCourse& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAlgorithm
 */
bool
SedVisitor::visit(const SedAlgorithm& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAbstractTask
 */
bool
SedVisitor::visit(const SedAbstractTask& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedTask
 */
bool
SedVisitor::visit(const SedTask& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedDataGenerator
 */
bool
SedVisitor::visit(const SedDataGenerator& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedOutput
 */
bool
SedVisitor::visit(const SedOutput& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedPlot
 */
bool
SedVisitor::visit(const SedPlot& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedPlot2D
 */
bool
SedVisitor::visit(const SedPlot2D& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedPlot3D
 */
bool
SedVisitor::visit(const SedPlot3D& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAbstractCurve
 */
bool
SedVisitor::visit(const SedAbstractCurve& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedCurve
 */
bool
SedVisitor::visit(const SedCurve& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSurface
 */
bool
SedVisitor::visit(const SedSurface& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedDataSet
 */
bool
SedVisitor::visit(const SedDataSet& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedReport
 */
bool
SedVisitor::visit(const SedReport& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAlgorithmParameter
 */
bool
SedVisitor::visit(const SedAlgorithmParameter& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedRange
 */
bool
SedVisitor::visit(const SedRange& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedChangeXML
 */
bool
SedVisitor::visit(const SedChangeXML& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedRemoveXML
 */
bool
SedVisitor::visit(const SedRemoveXML& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSetValue
 */
bool
SedVisitor::visit(const SedSetValue& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedUniformRange
 */
bool
SedVisitor::visit(const SedUniformRange& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedVectorRange
 */
bool
SedVisitor::visit(const SedVectorRange& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedFunctionalRange
 */
bool
SedVisitor::visit(const SedFunctionalRange& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSubTask
 */
bool
SedVisitor::visit(const SedSubTask& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedOneStep
 */
bool
SedVisitor::visit(const SedOneStep& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSteadyState
 */
bool
SedVisitor::visit(const SedSteadyState& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAnalysis
 */
bool
SedVisitor::visit(const SedAnalysis& x)
{
    return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedRepeatedTask
 */
bool
SedVisitor::visit(const SedRepeatedTask& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedComputeChange
 */
bool
SedVisitor::visit(const SedComputeChange& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedDataDescription
 */
bool
SedVisitor::visit(const SedDataDescription& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedDataSource
 */
bool
SedVisitor::visit(const SedDataSource& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSlice
 */
bool
SedVisitor::visit(const SedSlice& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedParameterEstimationTask
 */
bool
SedVisitor::visit(const SedParameterEstimationTask& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedObjective
 */
bool
SedVisitor::visit(const SedObjective& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedLeastSquareObjectiveFunction
 */
bool
SedVisitor::visit(const SedLeastSquareObjectiveFunction& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAdjustableParameter
 */
bool
SedVisitor::visit(const SedAdjustableParameter& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedExperimentReference
 */
bool
SedVisitor::visit(const SedExperimentReference& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedFitExperiment
 */
bool
SedVisitor::visit(const SedFitExperiment& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedFitMapping
 */
bool
SedVisitor::visit(const SedFitMapping& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedBounds
 */
bool
SedVisitor::visit(const SedBounds& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedFigure
 */
bool
SedVisitor::visit(const SedFigure& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSubPlot
 */
bool
SedVisitor::visit(const SedSubPlot& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAxis
 */
bool
SedVisitor::visit(const SedAxis& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedStyle
 */
bool
SedVisitor::visit(const SedStyle& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedLine
 */
bool
SedVisitor::visit(const SedLine& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedMarker
 */
bool
SedVisitor::visit(const SedMarker& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedFill
 */
bool
SedVisitor::visit(const SedFill& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAppliedDimension
 */
bool
SedVisitor::visit(const SedAppliedDimension& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedDataRange
 */
bool
SedVisitor::visit(const SedDataRange& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedShadedArea
 */
bool
SedVisitor::visit(const SedShadedArea& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedParameterEstimationResultPlot
 */
bool
SedVisitor::visit(const SedParameterEstimationResultPlot& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedWaterfallPlot
 */
bool
SedVisitor::visit(const SedWaterfallPlot& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedParameterEstimationReport
 */
bool
SedVisitor::visit(const SedParameterEstimationReport& x)
{
  return visit(static_cast<const SedBase&>(x));
}


void
SedVisitor::leave (const SedDocument& x)
{
}


void
SedVisitor::leave (const SedBase& sb)
{
}


void
SedVisitor::leave (const SedListOf& x, int type)
{
}


/*
 * Leave the SedModel
 */
void
SedVisitor::leave(const SedModel& x)
{
}


/*
 * Leave the SedChange
 */
void
SedVisitor::leave(const SedChange& x)
{
}


/*
 * Leave the SedAddXML
 */
void
SedVisitor::leave(const SedAddXML& x)
{
}


/*
 * Leave the SedChangeAttribute
 */
void
SedVisitor::leave(const SedChangeAttribute& x)
{
}


/*
 * Leave the SedVariable
 */
void
SedVisitor::leave(const SedVariable& x)
{
}


/*
 * Leave the SedParameter
 */
void
SedVisitor::leave(const SedParameter& x)
{
}


/*
 * Leave the SedSimulation
 */
void
SedVisitor::leave(const SedSimulation& x)
{
}


/*
 * Leave the SedUniformTimeCourse
 */
void
SedVisitor::leave(const SedUniformTimeCourse& x)
{
}


/*
 * Leave the SedAlgorithm
 */
void
SedVisitor::leave(const SedAlgorithm& x)
{
}


/*
 * Leave the SedAbstractTask
 */
void
SedVisitor::leave(const SedAbstractTask& x)
{
}


/*
 * Leave the SedTask
 */
void
SedVisitor::leave(const SedTask& x)
{
}


/*
 * Leave the SedDataGenerator
 */
void
SedVisitor::leave(const SedDataGenerator& x)
{
}


/*
 * Leave the SedOutput
 */
void
SedVisitor::leave(const SedOutput& x)
{
}


/*
 * Leave the SedPlot
 */
void
SedVisitor::leave(const SedPlot& x)
{
}


/*
 * Leave the SedPlot2D
 */
void
SedVisitor::leave(const SedPlot2D& x)
{
}


/*
 * Leave the SedPlot3D
 */
void
SedVisitor::leave(const SedPlot3D& x)
{
}


/*
 * Leave the SedAbstractCurve
 */
void
SedVisitor::leave(const SedAbstractCurve& x)
{
}


/*
 * Leave the SedCurve
 */
void
SedVisitor::leave(const SedCurve& x)
{
}


/*
 * Leave the SedSurface
 */
void
SedVisitor::leave(const SedSurface& x)
{
}


/*
 * Leave the SedDataSet
 */
void
SedVisitor::leave(const SedDataSet& x)
{
}


/*
 * Leave the SedReport
 */
void
SedVisitor::leave(const SedReport& x)
{
}


/*
 * Leave the SedAlgorithmParameter
 */
void
SedVisitor::leave(const SedAlgorithmParameter& x)
{
}


/*
 * Leave the SedRange
 */
void
SedVisitor::leave(const SedRange& x)
{
}


/*
 * Leave the SedChangeXML
 */
void
SedVisitor::leave(const SedChangeXML& x)
{
}


/*
 * Leave the SedRemoveXML
 */
void
SedVisitor::leave(const SedRemoveXML& x)
{
}


/*
 * Leave the SedSetValue
 */
void
SedVisitor::leave(const SedSetValue& x)
{
}


/*
 * Leave the SedUniformRange
 */
void
SedVisitor::leave(const SedUniformRange& x)
{
}


/*
 * Leave the SedVectorRange
 */
void
SedVisitor::leave(const SedVectorRange& x)
{
}


/*
 * Leave the SedFunctionalRange
 */
void
SedVisitor::leave(const SedFunctionalRange& x)
{
}


/*
 * Leave the SedSubTask
 */
void
SedVisitor::leave(const SedSubTask& x)
{
}


/*
 * Leave the SedOneStep
 */
void
SedVisitor::leave(const SedOneStep& x)
{
}


/*
 * Leave the SedSteadyState
 */
void
SedVisitor::leave(const SedSteadyState& x)
{
}


/*
 * Leave the SedAnalysis
 */
void
SedVisitor::leave(const SedAnalysis& x)
{
}


/*
 * Leave the SedRepeatedTask
 */
void
SedVisitor::leave(const SedRepeatedTask& x)
{
}


/*
 * Leave the SedComputeChange
 */
void
SedVisitor::leave(const SedComputeChange& x)
{
}


/*
 * Leave the SedDataDescription
 */
void
SedVisitor::leave(const SedDataDescription& x)
{
}


/*
 * Leave the SedDataSource
 */
void
SedVisitor::leave(const SedDataSource& x)
{
}


/*
 * Leave the SedSlice
 */
void
SedVisitor::leave(const SedSlice& x)
{
}


/*
 * Leave the SedParameterEstimationTask
 */
void
SedVisitor::leave(const SedParameterEstimationTask& x)
{
}


/*
 * Leave the SedObjective
 */
void
SedVisitor::leave(const SedObjective& x)
{
}


/*
 * Leave the SedLeastSquareObjectiveFunction
 */
void
SedVisitor::leave(const SedLeastSquareObjectiveFunction& x)
{
}


/*
 * Leave the SedAdjustableParameter
 */
void
SedVisitor::leave(const SedAdjustableParameter& x)
{
}


/*
 * Leave the SedExperimentReference
 */
void
SedVisitor::leave(const SedExperimentReference& x)
{
}


/*
 * Leave the SedFitExperiment
 */
void
SedVisitor::leave(const SedFitExperiment& x)
{
}


/*
 * Leave the SedFitMapping
 */
void
SedVisitor::leave(const SedFitMapping& x)
{
}


/*
 * Leave the SedBounds
 */
void
SedVisitor::leave(const SedBounds& x)
{
}


/*
 * Leave the SedFigure
 */
void
SedVisitor::leave(const SedFigure& x)
{
}


/*
 * Leave the SedSubPlot
 */
void
SedVisitor::leave(const SedSubPlot& x)
{
}


/*
 * Leave the SedAxis
 */
void
SedVisitor::leave(const SedAxis& x)
{
}


/*
 * Leave the SedStyle
 */
void
SedVisitor::leave(const SedStyle& x)
{
}


/*
 * Leave the SedLine
 */
void
SedVisitor::leave(const SedLine& x)
{
}


/*
 * Leave the SedMarker
 */
void
SedVisitor::leave(const SedMarker& x)
{
}


/*
 * Leave the SedFill
 */
void
SedVisitor::leave(const SedFill& x)
{
}


/*
 * Leave the SedAppliedDimension
 */
void
SedVisitor::leave(const SedAppliedDimension& x)
{
}


/*
 * Leave the SedDataRange
 */
void
SedVisitor::leave(const SedDataRange& x)
{
}


/*
 * Leave the SedShadedArea
 */
void
SedVisitor::leave(const SedShadedArea& x)
{
}


/*
 * Leave the SedParameterEstimationResultPlot
 */
void
SedVisitor::leave(const SedParameterEstimationResultPlot& x)
{
}


/*
 * Leave the SedWaterfallPlot
 */
void
SedVisitor::leave(const SedWaterfallPlot& x)
{
}


/*
 * Leave the SedParameterEstimationReport
 */
void
SedVisitor::leave(const SedParameterEstimationReport& x)
{
}



#endif /* __cplusplus */


LIBSEDML_CPP_NAMESPACE_END
