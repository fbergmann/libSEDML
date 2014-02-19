/**
* @file    local.cpp
* @brief   Python-specific SWIG support code for wrapping libSBML API
* @author  Ben Bornstein
* @author  Ben Kovitz
*
* <!--------------------------------------------------------------------------
* This file is part of libSBML.  Please visit http://sbml.org for more
* information about SBML, and the latest version of libSBML.
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

	case SEDML_CHANGE_ATTRIBUTE:
		return SWIGTYPE_p_SedChangeAttribute;

	case SEDML_CHANGE_ADDXML:
		return SWIGTYPE_p_SedAddXML;

	case SEDML_CHANGE_CHANGEXML:
		return SWIGTYPE_p_SedChangeXML;
		
	case SEDML_RANGE:
		return SWIGTYPE_p_SedRange;

	case SEDML_RANGE_FUNCTIONALRANGE:
		return SWIGTYPE_p_SedFunctionalRange;

	case SEDML_RANGE_UNIFORMRANGE:
		return SWIGTYPE_p_SedUniformRange;

	case SEDML_RANGE_VECTORRANGE:
		return SWIGTYPE_p_SedVectorRange;

	case SEDML_CHANGE_REMOVEXML:
		return SWIGTYPE_p_SedRemoveXML;

	case SEDML_CHANGE_COMPUTECHANGE:
		return SWIGTYPE_p_SedComputeChange;

	case SEDML_DATAGENERATOR:
		return SWIGTYPE_p_SedDataGenerator;

	case SEDML_VARIABLE:
		return SWIGTYPE_p_SedVariable;

	case SEDML_PARAMETER:
		return SWIGTYPE_p_SedParameter;

	case SEDML_TASK:
		return SWIGTYPE_p_SedTask;

	case SEDML_OUTPUT_DATASET:
		return SWIGTYPE_p_SedDataSet;

	case SEDML_OUTPUT_CURVE:
		return SWIGTYPE_p_SedCurve;

	case SEDML_OUTPUT_SURFACE:
		return SWIGTYPE_p_SedSurface;

	case SEDML_OUTPUT_REPORT:
		return SWIGTYPE_p_SedReport;

	case SEDML_OUTPUT_PLOT2D:
		return SWIGTYPE_p_SedPlot2D;

	case SEDML_OUTPUT_PLOT3D:
		return SWIGTYPE_p_SedPlot3D;

	case SEDML_SIMULATION_ALGORITHM:
		return SWIGTYPE_p_SedAlgorithm;

	case SEDML_SIMULATION_ALGORITHM_PARAMETER:
		return SWIGTYPE_p_SedAlgorithmParameter;
		
	case SEDML_SIMULATION:
		return SWIGTYPE_p_SedSimulation;

	case SEDML_SIMULATION_UNIFORMTIMECOURSE:
		return SWIGTYPE_p_SedUniformTimeCourse;
		
	case SEDML_SIMULATION_ONESTEP:
		return SWIGTYPE_p_SedOneStep;
		
	case SEDML_SIMULATION_STEADYSTATE:
		return SWIGTYPE_p_SedSteadyState;
		
	case SEDML_TASK_SETVALUE:
		return SWIGTYPE_p_SedSetValue;
		
	case SEDML_TASK_SUBTASK:
		return SWIGTYPE_p_SedSubTask;

	case SEDML_TASK_REPEATEDTASK:
		return SWIGTYPE_p_SedRepeatedTask;
		
	case SEDML_LIST_OF:
		name = sb->getElementName();
		if(name == "listOf"){
			return SWIGTYPE_p_SedListOf;
		}
		else if(name == "listOfModels")
		{
			return SWIGTYPE_p_SedListOfModels;
		}
		else if(name == "listOfChanges")
		{
			if (((SedListOf*)sb)->getItemTypeCode() == SEDML_TASK_SETVALUE)
			return SWIGTYPE_p_SedListOfTaskChanges;
			return SWIGTYPE_p_SedListOfChanges;
		}
		else if(name == "listOfSimulations")
		{
			return SWIGTYPE_p_SedListOfSimulations;
		}
		else if(name == "listOfTasks")
		{
			return SWIGTYPE_p_SedListOfTasks;
		}
		else if(name == "listOfDataGenerators")
		{
			return SWIGTYPE_p_SedListOfDataGenerators;
		}
		else if(name == "listOfOutputs")
		{
			return SWIGTYPE_p_SedListOfOutputs;
		}
		else if(name == "listOfCurves")
		{
			return SWIGTYPE_p_SedListOfCurves;
		}
		else if(name == "listOfSurfaces")
		{
			return SWIGTYPE_p_SedListOfSurfaces;
		}
		else if(name == "listOfDataSets")
		{
			return SWIGTYPE_p_SedListOfDataSets;
		}
		else if(name == "listOfParameters")
		{
			return SWIGTYPE_p_SedListOfParameters;
		}
		else if(name == "listOfVariables")
		{
			return SWIGTYPE_p_SedListOfVariables;
		}
		else if(name == "listOfSubTasks")
		{
			return SWIGTYPE_p_SedListOfSubTasks;
		}

		else if(name == "listOfRanges")
		{
			return SWIGTYPE_p_SedListOfRanges;
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
