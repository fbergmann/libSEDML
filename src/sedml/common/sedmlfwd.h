/**
 * @file sedmlfwd.h
 * @brief Definition of sedmlfwd.
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


#ifndef sedmlfwd_H__
#define sedmlfwd_H__


#include <sedml/common/libsedml-namespace.h>

/**
 * Forward declaration of all opaque C types.
 *
 * Declaring all types up-front avoids "redefinition of type Foo" compile
 * errors and allows our combined C/C++ headers to depend minimally upon each
 * other. Put another way, the type definitions below serve the same purpose as
 * "class Foo;" forward declarations in C++ code.
 */

#ifdef __cplusplus
# define CLASS_OR_STRUCT class
#else
# define CLASS_OR_STRUCT struct
#endif /* __cplusplus */


LIBSEDML_CPP_NAMESPACE_BEGIN


typedef CLASS_OR_STRUCT SedDocument                      SedDocument_t;
typedef CLASS_OR_STRUCT SedModel                         SedModel_t;
typedef CLASS_OR_STRUCT SedChange                        SedChange_t;
typedef CLASS_OR_STRUCT SedAddXML                        SedAddXML_t;
typedef CLASS_OR_STRUCT SedChangeAttribute               SedChangeAttribute_t;
typedef CLASS_OR_STRUCT SedVariable                      SedVariable_t;
typedef CLASS_OR_STRUCT SedParameter                     SedParameter_t;
typedef CLASS_OR_STRUCT SedSimulation                    SedSimulation_t;
typedef CLASS_OR_STRUCT SedUniformTimeCourse             SedUniformTimeCourse_t;
typedef CLASS_OR_STRUCT SedAlgorithm                     SedAlgorithm_t;
typedef CLASS_OR_STRUCT SedAnalysis                      SedAnalysis_t;
typedef CLASS_OR_STRUCT SedAbstractTask                  SedAbstractTask_t;
typedef CLASS_OR_STRUCT SedTask                          SedTask_t;
typedef CLASS_OR_STRUCT SedDataGenerator                 SedDataGenerator_t;
typedef CLASS_OR_STRUCT SedOutput                        SedOutput_t;
typedef CLASS_OR_STRUCT SedPlot                          SedPlot_t;
typedef CLASS_OR_STRUCT SedPlot2D                        SedPlot2D_t;
typedef CLASS_OR_STRUCT SedPlot3D                        SedPlot3D_t;
typedef CLASS_OR_STRUCT SedAbstractCurve                 SedAbstractCurve_t;
typedef CLASS_OR_STRUCT SedCurve                         SedCurve_t;
typedef CLASS_OR_STRUCT SedSurface                       SedSurface_t;
typedef CLASS_OR_STRUCT SedDataSet                       SedDataSet_t;
typedef CLASS_OR_STRUCT SedReport                        SedReport_t;
typedef CLASS_OR_STRUCT SedAlgorithmParameter            SedAlgorithmParameter_t;
typedef CLASS_OR_STRUCT SedRange                         SedRange_t;
typedef CLASS_OR_STRUCT SedChangeXML                     SedChangeXML_t;
typedef CLASS_OR_STRUCT SedRemoveXML                     SedRemoveXML_t;
typedef CLASS_OR_STRUCT SedSetValue                      SedSetValue_t;
typedef CLASS_OR_STRUCT SedUniformRange                  SedUniformRange_t;
typedef CLASS_OR_STRUCT SedVectorRange                   SedVectorRange_t;
typedef CLASS_OR_STRUCT SedFunctionalRange               SedFunctionalRange_t;
typedef CLASS_OR_STRUCT SedSubTask                       SedSubTask_t;
typedef CLASS_OR_STRUCT SedOneStep                       SedOneStep_t;
typedef CLASS_OR_STRUCT SedSteadyState                   SedSteadyState_t;
typedef CLASS_OR_STRUCT SedRepeatedTask                  SedRepeatedTask_t;
typedef CLASS_OR_STRUCT SedComputeChange                 SedComputeChange_t;
typedef CLASS_OR_STRUCT SedDataDescription               SedDataDescription_t;
typedef CLASS_OR_STRUCT SedDataSource                    SedDataSource_t;
typedef CLASS_OR_STRUCT SedSlice                         SedSlice_t;
typedef CLASS_OR_STRUCT SedParameterEstimationTask       SedParameterEstimationTask_t;
typedef CLASS_OR_STRUCT SedObjective                     SedObjective_t;
typedef CLASS_OR_STRUCT SedLeastSquareObjectiveFunction  SedLeastSquareObjectiveFunction_t;
typedef CLASS_OR_STRUCT SedAdjustableParameter           SedAdjustableParameter_t;
typedef CLASS_OR_STRUCT SedExperimentReference                 SedExperimentReference_t;
typedef CLASS_OR_STRUCT SedFitExperiment                 SedFitExperiment_t;
typedef CLASS_OR_STRUCT SedFitMapping                    SedFitMapping_t;
typedef CLASS_OR_STRUCT SedBounds                        SedBounds_t;
typedef CLASS_OR_STRUCT SedFigure                        SedFigure_t;
typedef CLASS_OR_STRUCT SedSubPlot                       SedSubPlot_t;
typedef CLASS_OR_STRUCT SedAxis                          SedAxis_t;
typedef CLASS_OR_STRUCT SedStyle                         SedStyle_t;
typedef CLASS_OR_STRUCT SedLine                          SedLine_t;
typedef CLASS_OR_STRUCT SedMarker                        SedMarker_t;
typedef CLASS_OR_STRUCT SedFill                          SedFill_t;
typedef CLASS_OR_STRUCT SedAppliedDimension              SedAppliedDimension_t;
typedef CLASS_OR_STRUCT SedDataRange                     SedDataRange_t;
typedef CLASS_OR_STRUCT SedShadedArea                    SedShadedArea_t;
typedef CLASS_OR_STRUCT SedParameterEstimationResultPlot SedParameterEstimationResultPlot_t;
typedef CLASS_OR_STRUCT SedWaterfallPlot                 SedWaterfallPlot_t;
typedef CLASS_OR_STRUCT SedParameterEstimationReport     SedParameterEstimationReport_t;
typedef CLASS_OR_STRUCT SedBase                          SedBase_t;
typedef CLASS_OR_STRUCT SedListOf                        SedListOf_t;
typedef CLASS_OR_STRUCT SedReader                        SedReader_t;
typedef CLASS_OR_STRUCT SedWriter                        SedWriter_t;
typedef CLASS_OR_STRUCT SedNamespaces                    SedNamespaces_t;
typedef CLASS_OR_STRUCT SedError                         SedError_t;


LIBSEDML_CPP_NAMESPACE_END

#include <sbml/common/libsbml-namespace.h>

LIBSBML_CPP_NAMESPACE_BEGIN

/**
 * @var typedef class ASTNode ASTNode_t
 * @copydoc ASTNode
 */
typedef CLASS_OR_STRUCT ASTNode ASTNode_t;

/**
 * @var typedef class XMLNode XMLNode_t
 * @copydoc XMLNode
 */
typedef CLASS_OR_STRUCT XMLNode XMLNode_t;

LIBSBML_CPP_NAMESPACE_END

#include <numl/common/libnuml-namespace.h>

LIBNUML_CPP_NAMESPACE_BEGIN

typedef CLASS_OR_STRUCT DimensionDescription                     DimensionDescription_t;

LIBNUML_CPP_NAMESPACE_END

#undef CLASS_OR_STRUCT


#endif /* !sedmlfwd_H__ */


