/**
 * @file SedError.h
 * @brief Definition of the SedError class.
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


#ifndef SedError_h
#define SedError_h

#include <sedml/common/extern.h>
#include <sbml/xml/XMLError.h>
#include <sedml/SedNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * @enum SedErrorCode_t
 * Codes for all SEDML-level errors and warnings from the core specification.
 */
typedef enum
{
  SedUnknown                      = 10000 /*!< Encountered unknown internal libSEDML error. */
, SedNotUTF8                               = 10001 /*!< File does not use UTF-8 encoding. */
, SedUnrecognizedElement                   = 10002 /*!< Encountered unrecognized element. */
, SedNotSchemaConformant                   = 10003 /*!< Document does not conform to the SED-ML XML schema. */
, SedInvalidMathElement                    = 10201
, SedMissingAnnotationNamespace            = 10401 /*!< Missing declaration of the XML namespace for the annotation. */
, SedDuplicateAnnotationNamespaces         = 10402 /*!< Multiple annotations using the same XML namespace. */
, SedNamespaceInAnnotation             = 10403 /*!< The SED-ML XML namespace cannot be used in an Annotation object. */
, SedMultipleAnnotations                   = 10404 /*!< Only one Annotation object is permitted under a given SED-ML object. */
, SedAnnotationNotElement                  = 10405
, SedNotesNotInXHTMLNamespace              = 10801 /*!< Notes must be placed in the XHTML XML namespace. */
, SedNotesContainsXMLDecl                  = 10802 /*!< XML declarations are not permitted in Notes objects. */
, SedNotesContainsDOCTYPE                  = 10803 /*!< XML DOCTYPE elements are not permitted in Notes objects. */
, SedInvalidNotesContent                   = 10804 /*!< Invalid notes content found. */
, SedOnlyOneNotesElementAllowed            = 10805 /*!< Only one Notes subobject is permitted on a given SED-ML object. */
, SedmlNSUndeclared      = 10101
, SedmlElementNotInNs      = 10102
, SedmlDuplicateComponentId      = 10301
, SedmlIdSyntaxRule      = 10302
, SedInvalidMetaidSyntax      = 10303
, InvalidNamespaceOnSed      = 20101
, SedAllowedAttributes      = 20102
, SedEmptyListElement      = 20103
, SedmlDocumentAllowedCoreAttributes      = 20201
, SedmlDocumentAllowedCoreElements      = 20202
, SedmlDocumentAllowedAttributes      = 20203
, SedmlDocumentAllowedElements      = 20204
, SedmlDocumentLevelMustBeNonNegativeInteger      = 20205
, SedmlDocumentVersionMustBeNonNegativeInteger      = 20206
, SedmlDocumentLODataDescriptionsAllowedCoreElements      = 20207
, SedmlDocumentLOModelsAllowedCoreElements      = 20208
, SedmlDocumentLOSimulationsAllowedCoreElements      = 20209
, SedmlDocumentLOTasksAllowedCoreElements      = 20210
, SedmlDocumentLODataGeneratorsAllowedCoreElements      = 20211
, SedmlDocumentLOOutputsAllowedCoreElements      = 20212
, SedmlDocumentLOStylesAllowedCoreElements      = 20213
, SedmlDocumentLODataDescriptionsAllowedCoreAttributes      = 20214
, SedmlDocumentLOModelsAllowedCoreAttributes      = 20215
, SedmlDocumentLOSimulationsAllowedCoreAttributes      = 20216
, SedmlDocumentLOTasksAllowedCoreAttributes      = 20217
, SedmlDocumentLODataGeneratorsAllowedCoreAttributes      = 20218
, SedmlDocumentLOOutputsAllowedCoreAttributes      = 20219
, SedmlDocumentLOStylesAllowedCoreAttributes      = 20220
, SedmlDocumentLOAlgorithmParametersAllowedCoreElements = 20221
, SedmlDocumentLOAlgorithmParametersAllowedCoreAttributes = 20222
, SedmlModelAllowedCoreAttributes      = 20301
, SedmlModelAllowedCoreElements      = 20302
, SedmlModelAllowedAttributes      = 20303
, SedmlModelAllowedElements      = 20304
, SedmlModelSourceMustBeString      = 20305
, SedmlModelNameMustBeString      = 20306
, SedmlModelLanguageMustBeString      = 20307
, SedmlModelLOChangesAllowedCoreElements      = 20308
, SedmlModelLOChangesAllowedCoreAttributes      = 20309
, SedmlChangeAllowedCoreAttributes      = 20401
, SedmlChangeAllowedCoreElements      = 20402
, SedmlChangeAllowedAttributes      = 20403
, SedmlChangeTargetMustBeString      = 20404
, SedmlAddXMLAllowedCoreAttributes      = 20501
, SedmlAddXMLAllowedCoreElements      = 20502
, SedmlAddXMLAllowedElements      = 20503
, SedmlChangeAttributeAllowedCoreAttributes      = 20601
, SedmlChangeAttributeAllowedCoreElements      = 20602
, SedmlChangeAttributeAllowedAttributes      = 20603
, SedmlChangeAttributeNewValueMustBeString      = 20604
, SedmlVariableAllowedCoreAttributes      = 20701
, SedmlVariableAllowedCoreElements      = 20702
, SedmlVariableAllowedAttributes      = 20703
, SedmlVariableAllowedElements      = 20704
, SedmlVariableSymbolMustBeString      = 20705
, SedmlVariableTargetMustBeString      = 20706
, SedmlVariableTaskReferenceMustBeAbstractTask      = 20707
, SedmlVariableModelReferenceMustBeModel      = 20708
, SedmlVariableTermMustBeString      = 20709
, SedmlVariableSymbol2MustBeString      = 20710
, SedmlVariableTarget2MustBeString      = 20711
, SedmlVariableDimensionTermMustBeString      = 20712
, SedmlVariableLOAppliedDimensionsAllowedCoreElements      = 20713
, SedmlVariableLOAppliedDimensionsAllowedCoreAttributes      = 20714
, SedmlVariableNameMustBeString = 20715
, SedmlParameterAllowedCoreAttributes      = 20801
, SedmlParameterAllowedCoreElements      = 20802
, SedmlParameterAllowedAttributes      = 20803
, SedmlParameterValueMustBeDouble      = 20804
, SedmlParameterNameMustBeString      = 20805
, SedmlSimulationAllowedCoreAttributes      = 20901
, SedmlSimulationAllowedCoreElements      = 20902
, SedmlSimulationAllowedAttributes      = 20903
, SedmlSimulationAllowedElements      = 20904
, SedmlSimulationNameMustBeString      = 20905
, SedmlUniformTimeCourseAllowedCoreAttributes      = 21001
, SedmlUniformTimeCourseAllowedCoreElements      = 21002
, SedmlUniformTimeCourseAllowedAttributes      = 21003
, SedmlUniformTimeCourseInitialTimeMustBeDouble      = 21004
, SedmlUniformTimeCourseOutputStartTimeMustBeDouble      = 21005
, SedmlUniformTimeCourseOutputEndTimeMustBeDouble      = 21006
, SedmlUniformTimeCourseNumberOfPointsMustBeInteger      = 21007
, SedmlUniformTimeCourseNumberOfStepsMustBeInteger      = 21008
, SedmlAlgorithmAllowedCoreAttributes      = 21101
, SedmlAlgorithmAllowedCoreElements      = 21102
, SedmlAlgorithmAllowedAttributes      = 21103
, SedmlAlgorithmAllowedElements      = 21104
, SedmlAlgorithmKisaoIDMustBeString      = 21105
, SedmlAlgorithmLOAlgorithmParametersAllowedCoreElements      = 21106
, SedmlAlgorithmLOAlgorithmParametersAllowedCoreAttributes      = 21107
, SedmlAbstractTaskAllowedCoreAttributes      = 21201
, SedmlAbstractTaskAllowedCoreElements      = 21202
, SedmlAbstractTaskAllowedAttributes      = 21203
, SedmlAbstractTaskNameMustBeString      = 21204
, SedmlTaskAllowedCoreAttributes      = 21301
, SedmlTaskAllowedCoreElements      = 21302
, SedmlTaskAllowedAttributes      = 21303
, SedmlTaskModelReferenceMustBeModel      = 21304
, SedmlTaskSimulationReferenceMustBeSimulation      = 21305
, SedmlDataGeneratorAllowedCoreAttributes      = 21401
, SedmlDataGeneratorAllowedCoreElements      = 21402
, SedmlDataGeneratorAllowedAttributes      = 21403
, SedmlDataGeneratorAllowedElements      = 21404
, SedmlDataGeneratorNameMustBeString      = 21405
, SedmlDataGeneratorLOVariablesAllowedCoreElements      = 21406
, SedmlDataGeneratorLOParametersAllowedCoreElements      = 21407
, SedmlDataGeneratorLOVariablesAllowedCoreAttributes      = 21408
, SedmlDataGeneratorLOParametersAllowedCoreAttributes      = 21409
, SedmlOutputAllowedCoreAttributes      = 21501
, SedmlOutputAllowedCoreElements      = 21502
, SedmlOutputAllowedAttributes      = 21503
, SedmlOutputNameMustBeString      = 21504
, SedmlPlotAllowedCoreAttributes      = 21601
, SedmlPlotAllowedCoreElements      = 21602
, SedmlPlotAllowedAttributes      = 21603
, SedmlPlotAllowedElements      = 21604
, SedmlPlotLegendMustBeBoolean      = 21605
, SedmlPlotHeightMustBeDouble      = 21606
, SedmlPlotWidthMustBeDouble      = 21607
, SedmlPlot2DAllowedCoreAttributes      = 21701
, SedmlPlot2DAllowedCoreElements      = 21702
, SedmlPlot2DAllowedElements      = 21703
, SedmlPlot2DLOCurvesAllowedCoreElements      = 21704
, SedmlPlot2DLOCurvesAllowedCoreAttributes      = 21705
, SedmlPlot3DAllowedCoreAttributes      = 21801
, SedmlPlot3DAllowedCoreElements      = 21802
, SedmlPlot3DAllowedElements      = 21803
, SedmlPlot3DLOSurfacesAllowedCoreElements      = 21804
, SedmlPlot3DLOSurfacesAllowedCoreAttributes      = 21805
, SedmlAbstractCurveAllowedCoreAttributes      = 21901
, SedmlAbstractCurveAllowedCoreElements      = 21902
, SedmlAbstractCurveAllowedAttributes      = 21903
, SedmlAbstractCurveNameMustBeString      = 21904
, SedmlAbstractCurveLogXMustBeBoolean      = 21905
, SedmlAbstractCurveOrderMustBeInteger      = 21906
, SedmlAbstractCurveStyleMustBeStyle      = 21907
, SedmlAbstractCurveYAxisMustBeString      = 21908
, SedmlAbstractCurveXDataReferenceMustBeDataReference      = 21909
, SedmlCurveAllowedCoreAttributes      = 22001
, SedmlCurveAllowedCoreElements      = 22002
, SedmlCurveAllowedAttributes      = 22003
, SedmlCurveYDataReferenceMustBeDataGenerator      = 22004
, SedmlCurveLogYMustBeBoolean      = 22005
, SedmlCurveTypeMustBeCurveTypeEnum      = 22006
, SedmlCurveXErrorUpperMustBeDataGenerator      = 22007
, SedmlCurveXErrorLowerMustBeDataGenerator      = 22008
, SedmlCurveYErrorUpperMustBeDataGenerator      = 22009
, SedmlCurveYErrorLowerMustBeDataGenerator      = 22010
, SedmlSurfaceAllowedCoreAttributes      = 22101
, SedmlSurfaceAllowedCoreElements      = 22102
, SedmlSurfaceAllowedAttributes      = 22103
, SedmlSurfaceZDataReferenceMustBeDataGenerator      = 22104
, SedmlSurfaceNameMustBeString      = 22105
, SedmlSurfaceXDataReferenceMustBeDataGenerator      = 22106
, SedmlSurfaceYDataReferenceMustBeDataGenerator      = 22107
, SedmlSurfaceTypeMustBeSurfaceTypeEnum      = 22108
, SedmlSurfaceStyleMustBeStyle      = 22109
, SedmlSurfaceLogXMustBeBoolean      = 22110
, SedmlSurfaceLogYMustBeBoolean      = 22111
, SedmlSurfaceLogZMustBeBoolean      = 22112
, SedmlSurfaceOrderMustBeInteger      = 22113
, SedmlDataSetAllowedCoreAttributes      = 22201
, SedmlDataSetAllowedCoreElements      = 22202
, SedmlDataSetAllowedAttributes      = 22203
, SedmlDataSetLabelMustBeString      = 22204
, SedmlDataSetDataReferenceMustBeDataGenerator      = 22205
, SedmlDataSetNameMustBeString      = 22206
, SedmlReportAllowedCoreAttributes      = 22301
, SedmlReportAllowedCoreElements      = 22302
, SedmlReportAllowedElements      = 22303
, SedmlReportLODataSetsAllowedCoreElements      = 22304
, SedmlReportLODataSetsAllowedCoreAttributes      = 22305
, SedmlAlgorithmParameterAllowedCoreAttributes      = 22401
, SedmlAlgorithmParameterAllowedCoreElements      = 22402
, SedmlAlgorithmParameterAllowedAttributes      = 22403
, SedmlAlgorithmParameterAllowedElements      = 22404
, SedmlAlgorithmParameterKisaoIDMustBeString      = 22405
, SedmlAlgorithmParameterValueMustBeString      = 22406
, SedmlAlgorithmParameterLOAlgorithmParametersAllowedCoreElements      = 22407
, SedmlAlgorithmParameterLOAlgorithmParametersAllowedCoreAttributes      = 22408
, SedmlRangeAllowedCoreAttributes      = 22501
, SedmlRangeAllowedCoreElements      = 22502
, SedmlRangeAllowedAttributes      = 22503
, SedmlChangeXMLAllowedCoreAttributes      = 22601
, SedmlChangeXMLAllowedCoreElements      = 22602
, SedmlChangeXMLAllowedElements      = 22603
, SedmlRemoveXMLAllowedCoreAttributes      = 22701
, SedmlRemoveXMLAllowedCoreElements      = 22702
, SedmlSetValueAllowedCoreAttributes      = 22801
, SedmlSetValueAllowedCoreElements      = 22802
, SedmlSetValueAllowedAttributes      = 22803
, SedmlSetValueAllowedElements      = 22804
, SedmlSetValueModelReferenceMustBeModel      = 22805
, SedmlSetValueSymbolMustBeString      = 22806
, SedmlSetValueTargetMustBeString      = 22807
, SedmlSetValueRangeMustBeRange      = 22808
, SedmlUniformRangeAllowedCoreAttributes      = 22901
, SedmlUniformRangeAllowedCoreElements      = 22902
, SedmlUniformRangeAllowedAttributes      = 22903
, SedmlUniformRangeStartMustBeDouble      = 22904
, SedmlUniformRangeEndMustBeDouble      = 22905
, SedmlUniformRangeNumberOfPointsMustBeInteger      = 22906
, SedmlUniformRangeTypeMustBeString      = 22907
, SedmlVectorRangeAllowedCoreAttributes      = 23001
, SedmlVectorRangeAllowedCoreElements      = 23002
, SedmlVectorRangeAllowedAttributes      = 23003
, SedmlVectorRangeValueMustBeString      = 23004
, SedmlFunctionalRangeAllowedCoreAttributes      = 23101
, SedmlFunctionalRangeAllowedCoreElements      = 23102
, SedmlFunctionalRangeAllowedAttributes      = 23103
, SedmlFunctionalRangeAllowedElements      = 23104
, SedmlFunctionalRangeRangeMustBeRange      = 23105
, SedmlFunctionalRangeLOVariablesAllowedCoreElements      = 23106
, SedmlFunctionalRangeLOParametersAllowedCoreElements      = 23107
, SedmlFunctionalRangeLOVariablesAllowedCoreAttributes      = 23108
, SedmlFunctionalRangeLOParametersAllowedCoreAttributes      = 23109
, SedmlSubTaskAllowedCoreAttributes      = 23201
, SedmlSubTaskAllowedCoreElements      = 23202
, SedmlSubTaskAllowedAttributes      = 23203
, SedmlSubTaskOrderMustBeInteger      = 23204
, SedmlSubTaskTaskMustBeAbstractTask      = 23205
, SedmlSubTaskAllowedElements           = 23206
, SedmlOneStepAllowedCoreAttributes      = 23301
, SedmlOneStepAllowedCoreElements      = 23302
, SedmlOneStepAllowedAttributes      = 23303
, SedmlOneStepStepMustBeDouble      = 23304
, SedmlSteadyStateAllowedCoreAttributes      = 23401
, SedmlSteadyStateAllowedCoreElements      = 23402
, SedmlAnalysisAllowedCoreAttributes = 23403
, SedmlAnalysisAllowedCoreElements = 23404
, SedmlRepeatedTaskAllowedCoreAttributes      = 23501
, SedmlRepeatedTaskAllowedCoreElements      = 23502
, SedmlRepeatedTaskAllowedAttributes      = 23503
, SedmlRepeatedTaskAllowedElements      = 23504
, SedmlRepeatedTaskRangeMustBeRange      = 23505
, SedmlRepeatedTaskResetModelMustBeBoolean      = 23506
, SedmlRepeatedTaskLORangesAllowedCoreElements      = 23507
, SedmlRepeatedTaskLOSetValuesAllowedCoreElements      = 23508
, SedmlRepeatedTaskLOSubTasksAllowedCoreElements      = 23509
, SedmlRepeatedTaskLORangesAllowedCoreAttributes      = 23510
, SedmlRepeatedTaskLOSetValuesAllowedCoreAttributes      = 23511
, SedmlRepeatedTaskLOSubTasksAllowedCoreAttributes      = 23512
, SedmlRepeatedTaskConcatenateMustBeBoolean = 23513
, SedmlComputeChangeAllowedCoreAttributes      = 23601
, SedmlComputeChangeAllowedCoreElements      = 23602
, SedmlComputeChangeAllowedElements      = 23603
, SedmlComputeChangeLOVariablesAllowedCoreElements      = 23604
, SedmlComputeChangeLOParametersAllowedCoreElements      = 23605
, SedmlComputeChangeLOVariablesAllowedCoreAttributes      = 23606
, SedmlComputeChangeLOParametersAllowedCoreAttributes      = 23607
, SedmlDataDescriptionAllowedCoreAttributes      = 23701
, SedmlDataDescriptionAllowedCoreElements      = 23702
, SedmlDataDescriptionAllowedAttributes      = 23703
, SedmlDataDescriptionAllowedElements      = 23704
, SedmlDataDescriptionNameMustBeString      = 23705
, SedmlDataDescriptionFormatMustBeString      = 23706
, SedmlDataDescriptionSourceMustBeString      = 23707
, SedmlDataDescriptionLODataSourcesAllowedCoreElements      = 23708
, SedmlDataDescriptionLODataSourcesAllowedCoreAttributes      = 23709
, SedmlDataSourceAllowedCoreAttributes      = 23801
, SedmlDataSourceAllowedCoreElements      = 23802
, SedmlDataSourceAllowedAttributes      = 23803
, SedmlDataSourceAllowedElements      = 23804
, SedmlDataSourceNameMustBeString      = 23805
, SedmlDataSourceIndexSetMustBeSId      = 23806
, SedmlDataSourceLOSlicesAllowedCoreElements      = 23807
, SedmlDataSourceLOSlicesAllowedCoreAttributes      = 23808
, SedmlSliceAllowedCoreAttributes      = 23901
, SedmlSliceAllowedCoreElements      = 23902
, SedmlSliceAllowedAttributes      = 23903
, SedmlSliceReferenceMustBeSId      = 23904
, SedmlSliceValueMustBeString      = 23905
, SedmlSliceIndexMustBeSId      = 23906
, SedmlSliceStartIndexMustBeInteger      = 23907
, SedmlSliceEndIndexMustBeInteger      = 23908
, SedmlParameterEstimationTaskAllowedCoreAttributes      = 24001
, SedmlParameterEstimationTaskAllowedCoreElements      = 24002
, SedmlParameterEstimationTaskAllowedElements      = 24003
, SedmlParameterEstimationTaskLOAdjustableParametersAllowedCoreElements      = 24004
, SedmlParameterEstimationTaskLOFitExperimentsAllowedCoreElements      = 24005
, SedmlParameterEstimationTaskLOAdjustableParametersAllowedCoreAttributes      = 24006
, SedmlParameterEstimationTaskLOFitExperimentsAllowedCoreAttributes      = 24007
, SedmlObjectiveAllowedCoreAttributes      = 24101
, SedmlObjectiveAllowedCoreElements      = 24102
, SedmlLeastSquareObjectiveFunctionAllowedCoreAttributes      = 24201
, SedmlLeastSquareObjectiveFunctionAllowedCoreElements      = 24202
, SedmlAdjustableParameterAllowedCoreAttributes      = 24301
, SedmlAdjustableParameterAllowedCoreElements      = 24302
, SedmlAdjustableParameterAllowedAttributes      = 24303
, SedmlAdjustableParameterAllowedElements      = 24304
, SedmlAdjustableParameterInitialValueMustBeDouble      = 24305
, SedmlAdjustableParameterModelReferenceMustBeModel      = 24306
, SedmlAdjustableParameterTargetMustBeString      = 24307
, SedmlAdjustableParameterLOExperimentReferencesAllowedCoreElements      = 24308
, SedmlAdjustableParameterLOExperimentReferencesAllowedCoreAttributes      = 24309
, SedmlExperimentReferenceAllowedCoreAttributes      = 24401
, SedmlExperimentReferenceAllowedCoreElements      = 24402
, SedmlExperimentReferenceAllowedAttributes      = 24403
, SedmlExperimentReferenceExperimentIdMustBeFitExperiment      = 24404
, SedmlFitExperimentAllowedCoreAttributes      = 24501
, SedmlFitExperimentAllowedCoreElements      = 24502
, SedmlFitExperimentAllowedAttributes      = 24503
, SedmlFitExperimentAllowedElements      = 24504
, SedmlFitExperimentTypeMustBeExperimentTypeEnum      = 24505
, SedmlFitExperimentLOFitMappingsAllowedCoreElements      = 24506
, SedmlFitExperimentLOFitMappingsAllowedCoreAttributes      = 24507
, SedmlFitMappingAllowedCoreAttributes      = 24601
, SedmlFitMappingAllowedCoreElements      = 24602
, SedmlFitMappingAllowedAttributes      = 24603
, SedmlFitMappingDataSourceMustBeDataSource      = 24604
, SedmlFitMappingTargetMustBeDataGenerator      = 24605
, SedmlFitMappingTypeMustBeMappingTypeEnum      = 24606
, SedmlFitMappingWeightMustBeDouble      = 24607
, SedmlFitMappingPointWeightMustBeDataSource      = 24608
, SedmlBoundsAllowedCoreAttributes      = 24701
, SedmlBoundsAllowedCoreElements      = 24702
, SedmlBoundsAllowedAttributes      = 24703
, SedmlBoundsLowerBoundMustBeDouble      = 24704
, SedmlBoundsUpperBoundMustBeDouble      = 24705
, SedmlBoundsScaleMustBeScaleTypeEnum      = 24706
, SedmlFigureAllowedCoreAttributes      = 24801
, SedmlFigureAllowedCoreElements      = 24802
, SedmlFigureAllowedAttributes      = 24803
, SedmlFigureAllowedElements      = 24804
, SedmlFigureNumRowsMustBeInteger      = 24805
, SedmlFigureNumColsMustBeInteger      = 24806
, SedmlFigureLOSubPlotsAllowedCoreElements      = 24807
, SedmlFigureLOSubPlotsAllowedCoreAttributes      = 24808
, SedmlSubPlotAllowedCoreAttributes      = 24901
, SedmlSubPlotAllowedCoreElements      = 24902
, SedmlSubPlotAllowedAttributes      = 24903
, SedmlSubPlotPlotMustBePlot      = 24904
, SedmlSubPlotRowMustBeInteger      = 24905
, SedmlSubPlotColMustBeInteger      = 24906
, SedmlSubPlotRowSpanMustBeInteger      = 24907
, SedmlSubPlotColSpanMustBeInteger      = 24908
, SedmlAxisAllowedCoreAttributes      = 25001
, SedmlAxisAllowedCoreElements      = 25002
, SedmlAxisAllowedAttributes      = 25003
, SedmlAxisTypeMustBeAxisTypeEnum      = 25004
, SedmlAxisMinMustBeDouble      = 25005
, SedmlAxisMaxMustBeDouble      = 25006
, SedmlAxisGridMustBeBoolean      = 25007
, SedmlAxisStyleMustBeStyle      = 25008
, SedmlAxisReverseMustBeBoolean      = 25009
, SedmlStyleAllowedCoreAttributes      = 25101
, SedmlStyleAllowedCoreElements      = 25102
, SedmlStyleAllowedAttributes      = 25103
, SedmlStyleAllowedElements      = 25104
, SedmlStyleBaseStyleMustBeStyle      = 25105
, SedmlLineAllowedCoreAttributes      = 25201
, SedmlLineAllowedCoreElements      = 25202
, SedmlLineAllowedAttributes      = 25203
, SedmlLineTypeMustBeLineTypeEnum      = 25204
, SedmlLineColorMustBeString      = 25205
, SedmlLineThicknessMustBeDouble      = 25206
, SedmlMarkerAllowedCoreAttributes      = 25301
, SedmlMarkerAllowedCoreElements      = 25302
, SedmlMarkerAllowedAttributes      = 25303
, SedmlMarkerSizeMustBeDouble      = 25304
, SedmlMarkerTypeMustBeMarkerTypeEnum      = 25305
, SedmlMarkerFillMustBeString      = 25306
, SedmlMarkerLineColorMustBeString      = 25307
, SedmlMarkerLineThicknessMustBeDouble      = 25308
, SedmlFillAllowedCoreAttributes      = 25401
, SedmlFillAllowedCoreElements      = 25402
, SedmlFillAllowedAttributes      = 25403
, SedmlFillColorMustBeString      = 25404
, SedmlDependentVariableAllowedCoreAttributes      = 25501
, SedmlDependentVariableAllowedCoreElements      = 25502
, SedmlDependentVariableAllowedAttributes      = 25503
, SedmlDependentVariableTermMustBeString      = 25504
, SedmlDependentVariableTarget2MustBeString      = 25505
, SedmlDependentVariableSymbol2MustBeString      = 25506
, SedmlAppliedDimensionAllowedCoreAttributes      = 25601
, SedmlAppliedDimensionAllowedCoreElements      = 25602
, SedmlAppliedDimensionAllowedAttributes      = 25603
, SedmlAppliedDimensionTargetMustBeSId      = 25604
, SedmlAppliedDimensionDimensionTargetMustBeSId      = 25605
, SedmlDataRangeAllowedCoreAttributes      = 25701
, SedmlDataRangeAllowedCoreElements      = 25702
, SedmlDataRangeAllowedAttributes      = 25703
, SedmlDataRangeSourceReferenceMustBeSId      = 25704
, SedmlShadedAreaAllowedCoreAttributes      = 25901
, SedmlShadedAreaAllowedCoreElements      = 25902
, SedmlShadedAreaAllowedAttributes      = 25903
, SedmlShadedAreaYDataReferenceFromMustBeDataGenerator      = 25904
, SedmlShadedAreaYDataReferenceToMustBeDataGenerator      = 25905
, SedmlParameterEstimationResultPlotAllowedCoreAttributes      = 26001
, SedmlParameterEstimationResultPlotAllowedCoreElements      = 26002
, SedmlParameterEstimationResultPlotAllowedAttributes      = 26003
, SedmlParameterEstimationResultPlotTaskReferenceMustBeTask      = 26004
, SedmlWaterfallPlotAllowedCoreAttributes      = 26101
, SedmlWaterfallPlotAllowedCoreElements      = 26102
, SedmlWaterfallPlotAllowedAttributes      = 26103
, SedmlWaterfallPlotTaskReferenceMustBeTask      = 26104
, SedmlParameterEstimationReportAllowedCoreAttributes      = 26201
, SedmlParameterEstimationReportAllowedCoreElements      = 26202
, SedmlParameterEstimationReportAllowedAttributes      = 26203
, SedmlParameterEstimationReportTaskReferenceMustBeTask      = 26204
, SedUnknownCoreAttribute                  = 99994 /*!< Encountered an unknown attribute in the SED-ML Core namespace. */
, SedCodesUpperBound                   = 99999 /*!< Upper boundary of libSEDML-specific diagnostic codes. */
} SedErrorCode_t;


/**
 * @enum SedErrorCategory_t
 * Category codes for SedError diagnostics.
 *
 * Note that these are distinct from XMLError's category codes.  User
 * programs receiving an SedError object can use this distinction to
 * check whether the error represents a low-level XML problem or a
 * SED-ML problem.
 *
 * @see #XMLErrorCategory_t
 */
typedef enum
{
    LIBSEDML_CAT_INTERNAL = LIBSBML_CAT_INTERNAL,
    LIBSEDML_CAT_SYSTEM = LIBSBML_CAT_SYSTEM,
    LIBSEDML_CAT_XML = LIBSBML_CAT_XML,

    LIBSEDML_CAT_SEDML = (LIBSEDML_CAT_XML + 1)
    /*!< General SED-ML error  not falling into another category below. */

  , LIBSEDML_CAT_GENERAL_CONSISTENCY
    /*!< Category of errors that can occur while validating general SED-ML
     * constructs. */

  , LIBSEDML_CAT_IDENTIFIER_CONSISTENCY
    /*!< Category of errors that can occur while validating symbol
     * identifiers in a model. */

  , LIBSEDML_CAT_MATHML_CONSISTENCY
    /*!< Category of errors that can occur while validating MathML formulas
     * in a model.  With respect to the SED-ML specification, these concern
     * failures in applying the validation rules numbered 102xx in the
     * Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */

  , LIBSEDML_CAT_INTERNAL_CONSISTENCY
    /*!< Category of errors that can occur while validating libSEDML's
     * internal representation of SED-ML constructs. (These are tests
     * performed by libSEDML and do not have equivalent SED-ML validation
     * rules.)  */

} SedErrorCategory_t;


/**
 * @enum SedErrorSeverity_t
 * Severity codes for SedError diagnostics.
 *
 * The only publicly-reported values of this type are the four from #XMLErrorSeverity_t.
 * All other values are used internally only, with translation of those
 * codes done in SedError.cpp
 *
 * @see XMLErrorSeverity_t
 */
typedef enum
{
  /** @cond doxygenLibsedmlInternal **/

  /* The following are used internally in SedErrorTable, but publicly,
   * we only report one of the 4 XMLError_Severity values.  Translation
   * of the codes is done in SedError.cpp.
   */
    LIBSEDML_SEV_WARNING = LIBSBML_SEV_WARNING,
    LIBSEDML_SEV_ERROR = LIBSBML_SEV_ERROR,
    LIBSEDML_SEV_FATAL = LIBSBML_SEV_FATAL,

    LIBSEDML_SEV_SCHEMA_ERROR    = (LIBSEDML_SEV_FATAL + 1)
    /*!< The XML content does not conform to
     * the relevant version of the SED-ML XML
     * Schema.  The content is not valid SED-ML. */

  , LIBSEDML_SEV_GENERAL_WARNING
    /*!< The XML content is invalid for some
     * levels/versions of SED-ML, and while it
     * may be valid in others, it is something
     * that is best avoided anyway.  LibSEDML
     * will issue warnings in those cases it
     * can recognize. */

  , LIBSEDML_SEV_NOT_APPLICABLE
    /*!< This error code is only a placeholder
     * for errors that have relevance to some
     * versions of SED-ML but not others. */

  /** @endcond **/
} SedErrorSeverity_t;

END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#ifdef __cplusplus

LIBSEDML_CPP_NAMESPACE_BEGIN

class LIBSEDML_EXTERN SedError : public XMLError
{
public:

  /**
   * Creates a new SedError to report that something occurred during SED-ML
   * processing.
   *
   * When a libSEDML operation on SED-ML content results in a warning, error
   * or other diagnostic, the issue is reported as an SedError object.
   * SedError objects have identification numbers to indicate the nature
   * of the exception.  @if clike These numbers are drawn from
   * the enumeration <a class="el"
   * href="#SedErrorCode_t">
   * SedErrorCode_t</a>.  @endif@if java These numbers are
   * defined as unsigned integer constants in the file
   * "libsedmlConstants.html".  See the <a class="el"
   * href="#SedErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@if python These
   * numbers are defined as unsigned integer constants in the interface
   * class @link libsedml libsedml@endlink.  See the <a class="el"
   * href="#SedErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@~ The argument
   * @p errorId to this constructor @em can be (but does not have to be) a
   * value from this @if clike enumeration. If it @em is a value
   * from <a class="el" href="#SedErrorCode_t">SedErrorCode_t</a>, the
   * SedError class assumes the error is a low-level system or SED-ML layer
   * error and <em>prepends</em> a built-in, predefined error message to
   * any string passed in the argument @p details to this constructor.  In
   * addition, all <a class="el"
   * href="#SedErrorCode_t">SedErrorCode_t</a> errors have associated
   * values for the @p severity and @p category codes, and these fields are
   * filled-in as well from the enumerations <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>,
   * respectively. @else set of constants.  If it @em
   * is one of the predefined error identifiers, the SedError class
   * assumes the error is a low-level system or SED-ML layer error and
   * <em>prepends</em> a built-in, predefined error message to any string
   * passed in the argument @p details to this constructor.  In addition,
   * all the predefined error identifiers have associated values for the
   * @p severity and @p category codes, and these fields are filled-in using
   * the libSEDML defaults for each different error identifier. @endif@~
   *
   * If the error identifier @p errorId is a number greater than 99999, the
   * SedError class assumes the error was generated from another part of
   * the software and does not do additional filling in of values beyond
   * the default in the constructor itself.  This allows SedError to serve
   * as a base class for other errors, such as for user-defined validation
   * rules (see Validator).  Callers should fill in all the parameters with
   * suitable values if generating errors with codes greater than 99999 to
   * make maximum use of the SedError facilities.
   *
   * @if clike As mentioned above, there are two other
   * enumerations, <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>, used for indicating
   * the severity and category of error for the predefined SedError codes.
   * The values passed in @p severity and @p category override the defaults
   * assigned based on the error code.  If the value of @p errorId is a
   * value from <a class="el" href="#SedErrorCode_t">SedErrorCode_t</a>,
   * callers do not need to fill in @p severity and @p category.
   * Conversely, if @p errorId is not a value from <a class="el"
   * href="#SedErrorCode_t">SedErrorCode_t</a>, callers can use other
   * values (not just those from <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>, but their own
   * special values) for @p severity and
   * @p category. @else As mentioned above,
   * there are additional constants defined for <a class="el"
   * href="#SedErrorSeverity_t">standard severity</a> and <a class="el"
   * href="#SedErrorCategory_t">standard category</a> codes, and every predefined
   * error in libSEDML has an associated value for severity and category taken
   * from these predefined sets.  These constants have symbol names
   * prefixed with <code>LIBSEDML_SEV_</code> and <code>LIBSEDML_CAT_</code>,
   * respectively.  If the value of @p errorId is one of the standard error
   * codes, callers do not need to fill in @p severity and @p category in a
   * call to this constructor.  Conversely, if @p errorId is not an existing
   * SEDML-level error code, callers can use other values for @p severity and
   * @p category. @endif@~
   *
   * Please see the top of the documentation for SedError for a longer
   * discussion of the possible error codes, their meanings, and their
   * applicability to different combinations of Level+Version of SED-ML.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level the SED-ML Level of the SED-ML model
   *
   * @param version the SED-ML Version within the Level of the SED-ML model
   *
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by SedError,
   * the given message is @em appended to a predefined message associated
   * with the given code.  If the error code is not recognized, the message
   * is stored as-is as the text of the error.
   *
   * @param line an unsigned int, the line number at which the error occured.
   *
   * @param column an unsigned int, the column number at which the error occured.
   *
   * @param severity an integer indicating severity of the error.
   *
   * @param category an integer indicating the category to which the error
   * belongs.
   */
  SedError
  (
     const unsigned int errorId  = 0
   , const unsigned int level    = SEDML_DEFAULT_LEVEL
   , const unsigned int version  = SEDML_DEFAULT_VERSION
   , const std::string& details  = ""
   , const unsigned int line     = 0
   , const unsigned int column   = 0
   , const unsigned int severity = LIBSEDML_SEV_ERROR
   , const unsigned int category = LIBSEDML_CAT_SEDML
  );


  /**
   * Copy constructor; creates a copy of this SedError.
   */
  SedError(const SedError& orig);

  /**
   * Destroys this SedError.
   */
  virtual ~SedError();

  SedError& operator=(const SedError& rhs);

#ifndef SWIG

  /** @cond doxygenLibsedmlInternal **/

  /**
   * Creates and returns a deep copy of this SedError object.
   *
   * @return the (deep) copy of this SedError object.
   */
  virtual SedError* clone() const;

  /**
   * Outputs this SedError to stream in the following format (and followed
   * by a newline):
   *
   *   line: (error id) message
   *
   * @param stream the output stream to write to.
   */
  virtual void print(std::ostream& stream) const;

  /** @endcond **/

#endif  /* !SWIG */

protected:
  /** @cond doxygenLibsedmlInternal **/

  virtual std::string stringForSeverity(unsigned int code) const;
  virtual std::string stringForCategory(unsigned int code) const;

  /** @endcond **/
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif /* SedError_h */
