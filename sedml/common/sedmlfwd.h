/**
 * @file    sedmlfwd.h
 * @brief   Forward declarations for all opaque C types.
 * @author  Ben Bornstein
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
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
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sedml.org/software/libsedml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * Declaring all types up-front avoids compilation errors of the form
 * <em>"Redefinition of type 'Foo'"</em>, and allows our combined C/C++
 * headers to depend minimally upon each other.  Put another way, the type
 * definitions below serve the same purpose as <tt>class Foo;</tt> forward
 * declarations in C++ code.
 */

#ifndef sedmlfwd_h
#define sedmlfwd_h


#include <sedml/common/libsedml-namespace.h>
#include <sedml/common/libsedml-config.h>


#ifdef __cplusplus
/**
 * Defined as a class when compiling for C++ and as a C struct when
 * compiling for C.
 */
#  define CLASS_OR_STRUCT class
#else
/**
 * Defined as a class when compiling for C++ and as a C struct when
 * compiling for C.
 */
#  define CLASS_OR_STRUCT struct
#endif  /* __cplusplus */

LIBSEDML_CPP_NAMESPACE_BEGIN

/**
 * @var typedef class SedBase SedBase_t
 * @copydoc SedBase
 */
typedef CLASS_OR_STRUCT SedBase                     SedBase_t;

/**
 * @var typedef class SedReader SedReader_t
 * @copydoc SedReader
 */
typedef CLASS_OR_STRUCT SedReader                     SedReader_t;

/**
 * @var typedef class SedWriter SedWriter_t
 * @copydoc SedWriter
 */
typedef CLASS_OR_STRUCT SedWriter                     SedWriter_t;


/**
 * @var typedef class SedNamespaces SedNamespaces_t
 * @copydoc SedNamespaces
 */
typedef CLASS_OR_STRUCT SedNamespaces              SedNamespaces_t;

/**
 * @var typedef class SedListOf SedListOf_t
 * @copydoc SedListOf
 */
typedef CLASS_OR_STRUCT SedListOf              SedListOf_t;


/**
 * @var typedef class SEDMLDocument SEDMLDocument_t
 * @copydoc SEDMLDocument
 */
typedef CLASS_OR_STRUCT SedDocument              SedDocument_t;


/**
 * @var typedef class SedModel SedModel_t
 * @copydoc SedModel
 */
typedef CLASS_OR_STRUCT SedModel                     SedModel_t;

/**
 * @var typedef class SedVariable SedVariable_t
 * @copydoc SedVariable
 */
typedef CLASS_OR_STRUCT SedVariable                     SedVariable_t;

/**
 * @var typedef class SedParameter SedParameter_t
 * @copydoc SedParameter
 */
typedef CLASS_OR_STRUCT SedParameter                     SedParameter_t;


/**
 * @var typedef class SedChange SedChange_t
 * @copydoc SedChange
 */
typedef CLASS_OR_STRUCT SedChange                     SedChange_t;

/**
 * @var typedef class SedRange SedRange_t
 * @copydoc SedRange
 */
typedef CLASS_OR_STRUCT SedRange                     SedRange_t;

/**
 * @var typedef class SedUniformRange SedUniformRange_t
 * @copydoc SedUniformRange
 */
typedef CLASS_OR_STRUCT SedUniformRange                     SedUniformRange_t;

/**
 * @var typedef class SedVectorRange SedVectorRange_t
 * @copydoc SedVectorRange
 */
typedef CLASS_OR_STRUCT SedVectorRange                     SedVectorRange_t;

/**
 * @var typedef class SedFunctionalRange SedFunctionalRange_t
 * @copydoc SedFunctionalRange
 */
typedef CLASS_OR_STRUCT SedFunctionalRange                     SedFunctionalRange_t;

/**
 * @var typedef class SedAlgorithm SedAlgorithm_t
 * @copydoc SedAlgorithm
 */
typedef CLASS_OR_STRUCT SedAlgorithm                     SedAlgorithm_t;

/**
 * @var typedef class SedOneStep SedOneStep_t
 * @copydoc SedOneStep
 */
typedef CLASS_OR_STRUCT SedOneStep                     SedOneStep_t;

/**
 * @var typedef class SedSteadyState SedSteadyState_t
 * @copydoc SedOneStep
 */
typedef CLASS_OR_STRUCT SedSteadyState                     SedSteadyState_t;

/**
 * @var typedef class SedSubTask SedSubTask_t
 * @copydoc SedOneStep
 */
typedef CLASS_OR_STRUCT SedSubTask                     SedSubTask_t;

/**
 * @var typedef class SedSetValue SedSetValue_t
 * @copydoc SedOneStep
 */
typedef CLASS_OR_STRUCT SedSetValue                     SedSetValue_t;


/**
 * @var typedef class SedAlgorithmParameter SedAlgorithmParameter_t
 * @copydoc SedAlgorithmParameter
 */
typedef CLASS_OR_STRUCT SedAlgorithmParameter                     SedAlgorithmParameter_t;


/**
 * @var typedef class SedComputeChange SedComputeChange_t
 * @copydoc SedComputeChange
 */
typedef CLASS_OR_STRUCT SedComputeChange                     SedComputeChange_t;


/**
 * @var typedef class SedRemoveXML SedRemoveXML_t
 * @copydoc SedRemoveXML
 */
typedef CLASS_OR_STRUCT SedRemoveXML                     SedRemoveXML_t;

/**
 * @var typedef class SedAddXML SedAddXML_t
 * @copydoc SedAddXML
 */
typedef CLASS_OR_STRUCT SedAddXML                     SedAddXML_t;


/**
 * @var typedef class SedChangeXML SedChangeXML_t
 * @copydoc SedChangeXML
 */
typedef CLASS_OR_STRUCT SedChangeXML                     SedChangeXML_t;


/**
 * @var typedef class SedChangeAttribute SedChangeAttribute_t
 * @copydoc SedChangeAttribute
 */
typedef CLASS_OR_STRUCT SedChangeAttribute                     SedChangeAttribute_t;

/**
 * @var typedef class SedDataGenerator SedDataGenerator_t
 * @copydoc SedDataGenerator
 */
typedef CLASS_OR_STRUCT SedDataGenerator                     SedDataGenerator_t;

/**
 * @var typedef class SedListOfDataGenerators SedListOfDataGenerators_t
 * @copydoc SedListOfDataGenerators
 */
typedef CLASS_OR_STRUCT SedListOfDataGenerators                     SedListOfDataGenerators_t;


/**
 * @var typedef class SedListOfModels SedListOfModels_t
 * @copydoc SedListOfModels
 */
typedef CLASS_OR_STRUCT SedListOfModels                     SedListOfModels_t;


/**
 * @var typedef class SedListOfOutputs SedListOfOutputs_t
 * @copydoc SedListOfOutputs
 */
typedef CLASS_OR_STRUCT SedListOfOutputs                     SedListOfOutputs_t;


/**
 * @var typedef class SedListOfTasks SedListOfTasks_t
 * @copydoc SedListOfTasks
 */
typedef CLASS_OR_STRUCT SedListOfTasks                     SedListOfTasks_t;


/**
 * @var typedef class SedTask SedTask_t
 * @copydoc Task
 */
typedef CLASS_OR_STRUCT SedTask                     SedTask_t;

/**
 * @var typedef class SedRepeatedTask SedRepeatedTask_t
 * @copydoc SedRepeatedTask
 */
typedef CLASS_OR_STRUCT SedRepeatedTask                     SedRepeatedTask_t;

/**
 * @var typedef class SedSimulation SedSimulation_t
 * @copydoc SedSimulation
 */
typedef CLASS_OR_STRUCT SedSimulation                     SedSimulation_t;


/**
 * @var typedef class SedUniformTimeCourse SedUniformTimeCourse_t
 * @copydoc SedUniformTimeCourse
 */
typedef CLASS_OR_STRUCT SedUniformTimeCourse                     SedUniformTimeCourse_t;


/**
 * @var typedef class SedOutput SedOutput_t
 * @copydoc Output
 */
typedef CLASS_OR_STRUCT SedOutput                     SedOutput_t;


/**
 * @var typedef class SedPlot3D SedPlot3D_t
 * @copydoc SedPlot3D
 */
typedef CLASS_OR_STRUCT SedPlot3D                     SedPlot3D_t;

/**
 * @var typedef class SedPlot2D SedPlot2D_t
 * @copydoc SedPlot2D
 */
typedef CLASS_OR_STRUCT SedPlot2D                     SedPlot2D_t;

/**
 * @var typedef class SedReport SedReport_t
 * @copydoc SedReport
 */
typedef CLASS_OR_STRUCT SedReport                     SedReport_t;

/**
 * @var typedef class SedSurface SedSurface_t
 * @copydoc SedSurface
 */
typedef CLASS_OR_STRUCT SedSurface                     SedSurface_t;

/**
 * @var typedef class SedCurve SedCurve_t
 * @copydoc SedCurve
 */
typedef CLASS_OR_STRUCT SedCurve                     SedCurve_t;

/**
 * @var typedef class SedDataSet SedDataSet_t
 * @copydoc SedDataSet
 */
typedef CLASS_OR_STRUCT SedDataSet                     SedDataSet_t;

/**
 * @var typedef class ASTNode ASTNode_t
 * @copydoc ASTNode
 */
typedef CLASS_OR_STRUCT ASTNode                     ASTNode_t;

/**
 * @var typedef class XMLNode XMLNode_t
 * @copydoc XMLNode
 */
typedef CLASS_OR_STRUCT XMLNode                     XMLNode_t;

LIBSEDML_CPP_NAMESPACE_END

#undef CLASS_OR_STRUCT

#endif  /* sedmlfwd_h  */

