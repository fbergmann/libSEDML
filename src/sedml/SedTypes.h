/**
 * @file SedTypes.h
 * @brief Definition of the SedTypes class.
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



#ifndef SedTypes_h
#define SedTypes_h


#include <sedml/common/sedmlfwd.h>

#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>

#include <sedml/SedDocument.h>
#include <sedml/SedModel.h>
#include <sedml/SedChange.h>
#include <sedml/SedAddXML.h>
#include <sedml/SedChangeAttribute.h>
#include <sedml/SedVariable.h>
#include <sedml/SedParameter.h>
#include <sedml/SedSimulation.h>
#include <sedml/SedUniformTimeCourse.h>
#include <sedml/SedAlgorithm.h>
#include <sedml/SedAbstractTask.h>
#include <sedml/SedTask.h>
#include <sedml/SedDataGenerator.h>
#include <sedml/SedOutput.h>
#include <sedml/SedPlot.h>
#include <sedml/SedPlot2D.h>
#include <sedml/SedPlot3D.h>
#include <sedml/SedAbstractCurve.h>
#include <sedml/SedCurve.h>
#include <sedml/SedSurface.h>
#include <sedml/SedDataSet.h>
#include <sedml/SedReport.h>
#include <sedml/SedAlgorithmParameter.h>
#include <sedml/SedRange.h>
#include <sedml/SedChangeXML.h>
#include <sedml/SedRemoveXML.h>
#include <sedml/SedSetValue.h>
#include <sedml/SedUniformRange.h>
#include <sedml/SedVectorRange.h>
#include <sedml/SedFunctionalRange.h>
#include <sedml/SedSubTask.h>
#include <sedml/SedAnalysis.h>
#include <sedml/SedOneStep.h>
#include <sedml/SedSteadyState.h>
#include <sedml/SedRepeatedTask.h>
#include <sedml/SedComputeChange.h>
#include <sedml/SedDataDescription.h>
#include <sedml/SedDataSource.h>
#include <sedml/SedSlice.h>
#include <sedml/SedParameterEstimationTask.h>
#include <sedml/SedObjective.h>
#include <sedml/SedLeastSquareObjectiveFunction.h>
#include <sedml/SedAdjustableParameter.h>
#include <sedml/SedExperimentReference.h>
#include <sedml/SedFitExperiment.h>
#include <sedml/SedFitMapping.h>
#include <sedml/SedBounds.h>
#include <sedml/SedFigure.h>
#include <sedml/SedSubPlot.h>
#include <sedml/SedAxis.h>
#include <sedml/SedStyle.h>
#include <sedml/SedLine.h>
#include <sedml/SedMarker.h>
#include <sedml/SedFill.h>
#include <sedml/SedAppliedDimension.h>
#include <sedml/SedDataRange.h>
#include <sedml/SedShadedArea.h>
#include <sedml/SedParameterEstimationResultPlot.h>
#include <sedml/SedWaterfallPlot.h>
#include <sedml/SedParameterEstimationReport.h>

#include <sedml/SedReader.h>
#include <sedml/SedWriter.h>

#include <sbml/math/FormulaFormatter.h>  

#endif  /* SedTypes_h */
