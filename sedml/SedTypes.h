/**
 * @file    SEDMLTypes.h
 * @brief   Include all SEDML types in a single header file.
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
 * and also available online as http://sbml.org/software/libsedml/license.html
 * ---------------------------------------------------------------------- -->*/

#ifndef SEDMLTypes_h
#define SEDMLTypes_h


#include <sedml/common/sedmlfwd.h>

#include <sedml/SedVariable.h>
#include <sedml/SedParameter.h>
#include <sedml/SedChange.h>
#include <sedml/SedChangeAttribute.h>
#include <sedml/SedAddXML.h>
#include <sedml/SedChangeXML.h>
#include <sedml/SedRemoveXML.h>
#include <sedml/SedComputeChange.h>
#include <sedml/SedModel.h>
#include <sedml/SedAlgorithm.h>
#include <sedml/SedAlgorithmParameter.h>
#include <sedml/SedSimulation.h>
#include <sedml/SedUniformTimeCourse.h>
#include <sedml/SedOneStep.h>
#include <sedml/SedSteadyState.h>
#include <sedml/SedDataSet.h>
#include <sedml/SedCurve.h>
#include <sedml/SedSurface.h>
#include <sedml/SedOutput.h>
#include <sedml/SedReport.h>
#include <sedml/SedPlot2D.h>
#include <sedml/SedPlot3D.h>
#include <sedml/SedDataGenerator.h>
#include <sedml/SedTask.h>
#include <sedml/SedRepeatedTask.h>
#include <sedml/SedSubTask.h>
#include <sedml/SedSetValue.h>
#include <sedml/SedRange.h>
#include <sedml/SedUniformRange.h>
#include <sedml/SedVectorRange.h>
#include <sedml/SedFunctionalRange.h>
#include <sedml/SedDocument.h>

#include <sedml/SedBase.h>
#include <sedml/SedListOf.h>


#include <sedml/SedReader.h>
#include <sedml/SedWriter.h>

#include <sbml/xml/XMLError.h>
#include <sbml/math/ASTNode.h>
#include <sbml/math/MathML.h>

#endif  /* SEDMLTypes_h */
