/**
 * @file local.i
 * @brief Base file
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


%include "std_string.i"
%include "std_wstring.i"

%include "exception.i"
%include <typemaps.i>

%include "enumsimple.swg"


/**
* Renames *::clone() to *::cloneObject().
* In JDK 1.4.2, libsedml's *::clone() methods can't override 
* "Object Java.lang.Object.clone()" because JDK 1.4.2 doesn't
* allow override with different return type. 
*
* (2008-12-07)
* Currently, JDK 1.5 or later, which allows a covariant return type,
* is required for libSEDML Java binding, and thus we don't have to use
* this rename directive. However, this directive is still enabled for 
* compatiblity.
*/

%rename(cloneObject) *::clone;

/** 
* Rename XMLNode::equals() to XMLNode::xmlEquals(), otherwise it conflicts with the 
* equals operation defined below
*/
%rename(xmlEquals) XMLNode::equals;
/** 
* Rename ASTNode::getClass() to ASTNode::getClassName(), otherwise it conflicts 
*/
%rename(getClassName) ASTNode::getClass;
%rename(setClassName) ASTNode::setClass;

/**
* Wraps covariant return types of ::clone functions.
*
* Currently, SWIG doesn't allow a covariant return type although
* JDK 1.5 or later supports it.
* Thus, the following directives are required to enable the 
* covariant return type. 
*/

#pragma SWIG nowarn=822

%define COVARIANT_RTYPE_CLONE(_CNAME_)
%typemap(jstype) _CNAME_* _CNAME_::clone  "_CNAME_"
%enddef

COVARIANT_RTYPE_CLONE(Compartment)
COVARIANT_RTYPE_CLONE(CompartmentType)
COVARIANT_RTYPE_CLONE(Constraint)
COVARIANT_RTYPE_CLONE(Delay)
COVARIANT_RTYPE_CLONE(Event)
COVARIANT_RTYPE_CLONE(EventAssignment)
COVARIANT_RTYPE_CLONE(FunctionDefinition)
COVARIANT_RTYPE_CLONE(InitialAssignment)
COVARIANT_RTYPE_CLONE(KineticLaw)
COVARIANT_RTYPE_CLONE(Model)
COVARIANT_RTYPE_CLONE(Parameter)
COVARIANT_RTYPE_CLONE(Priority)
COVARIANT_RTYPE_CLONE(LocalParameter)
COVARIANT_RTYPE_CLONE(Reaction)
COVARIANT_RTYPE_CLONE(Rule)
COVARIANT_RTYPE_CLONE(AlgebraicRule)
COVARIANT_RTYPE_CLONE(AssignmentRule)
COVARIANT_RTYPE_CLONE(RateRule)
COVARIANT_RTYPE_CLONE(Species)
COVARIANT_RTYPE_CLONE(SpeciesReference)
COVARIANT_RTYPE_CLONE(SpeciesType)
COVARIANT_RTYPE_CLONE(StoichiometryMath)
COVARIANT_RTYPE_CLONE(Trigger)
COVARIANT_RTYPE_CLONE(Unit)
COVARIANT_RTYPE_CLONE(UnitDefinition)
COVARIANT_RTYPE_CLONE(ListOf)
COVARIANT_RTYPE_CLONE(ListOfCompartmentTypes)
COVARIANT_RTYPE_CLONE(ListOfCompartments)
COVARIANT_RTYPE_CLONE(ListOfConstraints)
COVARIANT_RTYPE_CLONE(ListOfEventAssignments)
COVARIANT_RTYPE_CLONE(ListOfEvents)
COVARIANT_RTYPE_CLONE(ListOfFunctionDefinitions)
COVARIANT_RTYPE_CLONE(ListOfInitialAssignments)
COVARIANT_RTYPE_CLONE(ListOfParameters)
COVARIANT_RTYPE_CLONE(ListOfLocalParameters)
COVARIANT_RTYPE_CLONE(ListOfReactions)
COVARIANT_RTYPE_CLONE(ListOfRules)
COVARIANT_RTYPE_CLONE(ListOfSpecies)
COVARIANT_RTYPE_CLONE(ListOfSpeciesReferences)
COVARIANT_RTYPE_CLONE(ListOfSpeciesTypes)
COVARIANT_RTYPE_CLONE(ListOfUnitDefinitions)
COVARIANT_RTYPE_CLONE(ListOfUnits)
COVARIANT_RTYPE_CLONE(SedConstructorException)
COVARIANT_RTYPE_CLONE(SedNamespaces)
COVARIANT_RTYPE_CLONE(SedDocument)
COVARIANT_RTYPE_CLONE(SedModel)
COVARIANT_RTYPE_CLONE(SedChange)
COVARIANT_RTYPE_CLONE(SedAddXML)
COVARIANT_RTYPE_CLONE(SedChangeAttribute)
COVARIANT_RTYPE_CLONE(SedVariable)
COVARIANT_RTYPE_CLONE(SedParameter)
COVARIANT_RTYPE_CLONE(SedSimulation)
COVARIANT_RTYPE_CLONE(SedUniformTimeCourse)
COVARIANT_RTYPE_CLONE(SedAlgorithm)
COVARIANT_RTYPE_CLONE(SedAbstractTask)
COVARIANT_RTYPE_CLONE(SedTask)
COVARIANT_RTYPE_CLONE(SedDataGenerator)
COVARIANT_RTYPE_CLONE(SedOutput)
COVARIANT_RTYPE_CLONE(SedPlot)
COVARIANT_RTYPE_CLONE(SedPlot2D)
COVARIANT_RTYPE_CLONE(SedPlot3D)
COVARIANT_RTYPE_CLONE(SedAbstractCurve)
COVARIANT_RTYPE_CLONE(SedCurve)
COVARIANT_RTYPE_CLONE(SedSurface)
COVARIANT_RTYPE_CLONE(SedDataSet)
COVARIANT_RTYPE_CLONE(SedReport)
COVARIANT_RTYPE_CLONE(SedAlgorithmParameter)
COVARIANT_RTYPE_CLONE(SedRange)
COVARIANT_RTYPE_CLONE(SedChangeXML)
COVARIANT_RTYPE_CLONE(SedRemoveXML)
COVARIANT_RTYPE_CLONE(SedSetValue)
COVARIANT_RTYPE_CLONE(SedUniformRange)
COVARIANT_RTYPE_CLONE(SedVectorRange)
COVARIANT_RTYPE_CLONE(SedFunctionalRange)
COVARIANT_RTYPE_CLONE(SedSubTask)
COVARIANT_RTYPE_CLONE(SedOneStep)
COVARIANT_RTYPE_CLONE(SedAnalysis)
COVARIANT_RTYPE_CLONE(SedSteadyState)
COVARIANT_RTYPE_CLONE(SedRepeatedTask)
COVARIANT_RTYPE_CLONE(SedComputeChange)
COVARIANT_RTYPE_CLONE(SedDataDescription)
COVARIANT_RTYPE_CLONE(SedDataSource)
COVARIANT_RTYPE_CLONE(SedSlice)
COVARIANT_RTYPE_CLONE(SedParameterEstimationTask)
COVARIANT_RTYPE_CLONE(SedObjective)
COVARIANT_RTYPE_CLONE(SedLeastSquareObjectiveFunction)
COVARIANT_RTYPE_CLONE(SedAdjustableParameter)
COVARIANT_RTYPE_CLONE(SedExperimentReference)
COVARIANT_RTYPE_CLONE(SedFitExperiment)
COVARIANT_RTYPE_CLONE(SedFitMapping)
COVARIANT_RTYPE_CLONE(SedScaling)
COVARIANT_RTYPE_CLONE(SedValueScaling)
COVARIANT_RTYPE_CLONE(SedColumnScaling)
COVARIANT_RTYPE_CLONE(SedBounds)
COVARIANT_RTYPE_CLONE(SedFigure)
COVARIANT_RTYPE_CLONE(SedSubPlot)
COVARIANT_RTYPE_CLONE(SedAxis)
COVARIANT_RTYPE_CLONE(SedStyle)
COVARIANT_RTYPE_CLONE(SedLine)
COVARIANT_RTYPE_CLONE(SedMarker)
COVARIANT_RTYPE_CLONE(SedFill)
COVARIANT_RTYPE_CLONE(SedAppliedDimension)
COVARIANT_RTYPE_CLONE(SedDataRange)
COVARIANT_RTYPE_CLONE(SedShadedArea)
COVARIANT_RTYPE_CLONE(SedListOfModels)
COVARIANT_RTYPE_CLONE(SedListOfChanges)
COVARIANT_RTYPE_CLONE(SedListOfVariables)
COVARIANT_RTYPE_CLONE(SedListOfParameters)
COVARIANT_RTYPE_CLONE(SedListOfSimulations)
COVARIANT_RTYPE_CLONE(SedListOfTasks)
COVARIANT_RTYPE_CLONE(SedListOfDataGenerators)
COVARIANT_RTYPE_CLONE(SedListOfOutputs)
COVARIANT_RTYPE_CLONE(SedListOfCurves)
COVARIANT_RTYPE_CLONE(SedListOfSurfaces)
COVARIANT_RTYPE_CLONE(SedListOfDataSets)
COVARIANT_RTYPE_CLONE(SedListOfAlgorithmParameters)
COVARIANT_RTYPE_CLONE(SedListOfRanges)
COVARIANT_RTYPE_CLONE(SedListOfSetValues)
COVARIANT_RTYPE_CLONE(SedListOfSubTasks)
COVARIANT_RTYPE_CLONE(SedListOfDataDescriptions)
COVARIANT_RTYPE_CLONE(SedListOfDataSources)
COVARIANT_RTYPE_CLONE(SedListOfSlices)
COVARIANT_RTYPE_CLONE(SedListOfAdjustableParameters)
COVARIANT_RTYPE_CLONE(SedListOfExperimentReferences)
COVARIANT_RTYPE_CLONE(SedListOfFitExperiments)
COVARIANT_RTYPE_CLONE(SedListOfFitMappings)
COVARIANT_RTYPE_CLONE(SedListOfSubPlots)
COVARIANT_RTYPE_CLONE(SedListOfStyles)
COVARIANT_RTYPE_CLONE(SedListOfAppliedDimensions)
COVARIANT_RTYPE_CLONE(SedParameterEstimationResultPlot)
COVARIANT_RTYPE_CLONE(SedParameterEstimationReport)
COVARIANT_RTYPE_CLONE(SedWaterfallPlot)



/**
*
* Wraps covariant return types of ListOfXXX::get functions.
*
*/

%define COVARIANT_RTYPE_LISTOF_GET_REMOVE(_CNAME_)
%typemap(jstype) _CNAME_* ListOf ## _CNAME_ ## s::get  "_CNAME_"
%typemap(jstype) _CNAME_* ListOf ## _CNAME_ ## s::remove  "_CNAME_"
%enddef

COVARIANT_RTYPE_LISTOF_GET_REMOVE(CompartmentType)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Compartment)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(EventAssignment)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Event)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(FunctionDefinition)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(InitialAssignment)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(LocalParameter)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Parameter)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Reaction)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Rule)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SpeciesType)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(UnitDefinition)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Constraint)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Unit)

// Only ListOfSpecies and ListOfSpeciesReference classes do not 
// match the above macro...
%typemap(jstype) Species* ListOfSpecies::get    "Species"
%typemap(jstype) Species* ListOfSpecies::remove "Species"
%typemap(jstype) SimpleSpeciesReference* ListOfSpeciesReferences::get    "SimpleSpeciesReference"
%typemap(jstype) SimpleSpeciesReference* ListOfSpeciesReferences::remove "SimpleSpeciesReference"


COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfModels)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfChanges)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfVariables)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfParameters)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfSimulations)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfTasks)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfDataGenerators)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfOutputs)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfCurves)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfSurfaces)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfDataSets)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfAlgorithmParameters)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfRanges)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfSetValues)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfSubTasks)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfDataDescriptions)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfDataSources)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfSlices)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfStyles)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfAdjustableParameters)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfExperimentReferences)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfFitExperiments)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfFitMappings)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfSubPlots)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfAppliedDimensions)

/**
* Wraps the SedConstructorException
*
* The SedConstructorException (C++ class) is wrapped as the 
* SedConstructorException (Java class) which is derived from
* the built-in IllegalArgumentException class which is a subclass
* of RunTimeException.
*
* For example, the exception can be catched in Java code as follows:
*
* ---------------------------------------------
*  try
*  {
*    Model s = new Model(level,version);
*  }
*  catch (SedConstructorException e)
*  {
*     String errmsg = e.getMessage();
*  }
* ---------------------------------------------
*/

%ignore SedConstructorException::SedConstructorException(std::string);

%typemap(javabase) SedConstructorException "java.lang.IllegalArgumentException";
%typemap(javacode) SedConstructorException 
%{
	protected SedConstructorException(long cPtr, boolean cMemoryOwn, String v)
	{
		super(v);
		swigCMemOwn = cMemoryOwn;
		swigCPtr    = cPtr;
	}

	/**
* Exception thrown by libSEDML object constructors if something prevents
* the object from being properly created.
*
* An example of what can cause this exception to be thrown is attempting
* to create an Sed component with an invalid Sed Level/Version
* combination.
*/
	public SedConstructorException(String v)
	{
		this(libsedmlJNI.new_SedConstructorException__SWIG_0(), true, v);
	}
	%}

%define SEDMLCONSTRUCTOR_EXCEPTION(SBASE_CLASS_NAME)
%javaexception("org.sedml.libsedml.SedConstructorException") SBASE_CLASS_NAME
%{
	try {
		$action
	}
	catch (const SedConstructorException &e) {
		jenv->ExceptionClear();
		jclass clazz = jenv->FindClass("org/sedml/libsedml/SedConstructorException");
		if (clazz)
		jenv->ThrowNew(clazz, e.what());
		return $null;
	}
	catch (const SBMLConstructorException &e) {
		jenv->ExceptionClear();
		jclass clazz = jenv->FindClass("org/sedml/libsedml/SedConstructorException");
		if (clazz)
		jenv->ThrowNew(clazz, e.what());
		return $null;
	}
	catch (const XMLConstructorException &e) {
		jenv->ExceptionClear();
		jclass clazz = jenv->FindClass("org/sedml/libsedml/SedConstructorException");
		if (clazz)
		jenv->ThrowNew(clazz, e.what());
		return $null;
	}
	catch (const NUMLConstructorException &e) {
		jenv->ExceptionClear();
		jclass clazz = jenv->FindClass("org/sedml/libsedml/SedConstructorException");
		if (clazz)
		jenv->ThrowNew(clazz, e.what());
		return $null;
	}
	%}
%enddef

SEDMLCONSTRUCTOR_EXCEPTION(AtomicDescription)
SEDMLCONSTRUCTOR_EXCEPTION(AtomicValue)
SEDMLCONSTRUCTOR_EXCEPTION(CompositeDescription)
SEDMLCONSTRUCTOR_EXCEPTION(CompositeValue)
SEDMLCONSTRUCTOR_EXCEPTION(Dimension)
SEDMLCONSTRUCTOR_EXCEPTION(DimensionDescription)

SEDMLCONSTRUCTOR_EXCEPTION(NMBase)
SEDMLCONSTRUCTOR_EXCEPTION(NUMLConstructorException)
SEDMLCONSTRUCTOR_EXCEPTION(NUMLDocument)
SEDMLCONSTRUCTOR_EXCEPTION(NUMLList)
SEDMLCONSTRUCTOR_EXCEPTION(NUMLNamespaces)
SEDMLCONSTRUCTOR_EXCEPTION(OntologyTerm)
SEDMLCONSTRUCTOR_EXCEPTION(OntologyTerms)
SEDMLCONSTRUCTOR_EXCEPTION(ResultComponent)
SEDMLCONSTRUCTOR_EXCEPTION(ResultComponents)

SEDMLCONSTRUCTOR_EXCEPTION(SedAbstractCurve)
SEDMLCONSTRUCTOR_EXCEPTION(SedAbstractTask)
SEDMLCONSTRUCTOR_EXCEPTION(SedAddXML)
SEDMLCONSTRUCTOR_EXCEPTION(SedAdjustableParameter)
SEDMLCONSTRUCTOR_EXCEPTION(SedAlgorithm)
SEDMLCONSTRUCTOR_EXCEPTION(SedAlgorithmParameter)
SEDMLCONSTRUCTOR_EXCEPTION(SedAxis)
SEDMLCONSTRUCTOR_EXCEPTION(SedBase)
SEDMLCONSTRUCTOR_EXCEPTION(SedBaseList)
SEDMLCONSTRUCTOR_EXCEPTION(SedBounds)
SEDMLCONSTRUCTOR_EXCEPTION(SedChange)
SEDMLCONSTRUCTOR_EXCEPTION(SedChangeAttribute)
SEDMLCONSTRUCTOR_EXCEPTION(SedChangeXML)
SEDMLCONSTRUCTOR_EXCEPTION(SedComputeChange)
SEDMLCONSTRUCTOR_EXCEPTION(SedCurve)
SEDMLCONSTRUCTOR_EXCEPTION(SedDataDescription)
SEDMLCONSTRUCTOR_EXCEPTION(SedDataGenerator)
SEDMLCONSTRUCTOR_EXCEPTION(SedDataRange)
SEDMLCONSTRUCTOR_EXCEPTION(SedDataSet)
SEDMLCONSTRUCTOR_EXCEPTION(SedDataSource)
SEDMLCONSTRUCTOR_EXCEPTION(SedDocument)
SEDMLCONSTRUCTOR_EXCEPTION(SedExperimentReference)
SEDMLCONSTRUCTOR_EXCEPTION(SedFigure)
SEDMLCONSTRUCTOR_EXCEPTION(SedFill)
SEDMLCONSTRUCTOR_EXCEPTION(SedFitExperiment)
SEDMLCONSTRUCTOR_EXCEPTION(SedFitMapping)
SEDMLCONSTRUCTOR_EXCEPTION(SedFunctionalRange)
SEDMLCONSTRUCTOR_EXCEPTION(SedLeastSquareObjectiveFunction)
SEDMLCONSTRUCTOR_EXCEPTION(SedLine)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOf)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfAdjustableParameters)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfAlgorithmParameters)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfChanges)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfCurves)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfDataDescriptions)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfDataGenerators)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfDataSets)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfDataSources)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfExperimentReferences)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfFitExperiments)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfFitMappings)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfModels)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfOutputs)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfParameters)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfRanges)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfAppliedDimensions)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfSetValues)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfSimulations)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfSlices)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfSubPlots)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfSubTasks)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfSurfaces)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfTasks)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfVariables)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfStyles)
SEDMLCONSTRUCTOR_EXCEPTION(SedMarker)
SEDMLCONSTRUCTOR_EXCEPTION(SedModel)
SEDMLCONSTRUCTOR_EXCEPTION(SedNamespaces)
SEDMLCONSTRUCTOR_EXCEPTION(SedNamespacesList)
SEDMLCONSTRUCTOR_EXCEPTION(SedObjective)
SEDMLCONSTRUCTOR_EXCEPTION(SedOneStep)
SEDMLCONSTRUCTOR_EXCEPTION(SedAnalysis)
SEDMLCONSTRUCTOR_EXCEPTION(SedOutput)
SEDMLCONSTRUCTOR_EXCEPTION(SedParameter)
SEDMLCONSTRUCTOR_EXCEPTION(SedParameterEstimationReport)
SEDMLCONSTRUCTOR_EXCEPTION(SedParameterEstimationResultPlot)
SEDMLCONSTRUCTOR_EXCEPTION(SedParameterEstimationTask)
SEDMLCONSTRUCTOR_EXCEPTION(SedPlot)
SEDMLCONSTRUCTOR_EXCEPTION(SedPlot2D)
SEDMLCONSTRUCTOR_EXCEPTION(SedPlot3D)
SEDMLCONSTRUCTOR_EXCEPTION(SedRange)
SEDMLCONSTRUCTOR_EXCEPTION(SedAppliedDimension)
SEDMLCONSTRUCTOR_EXCEPTION(SedRemoveXML)
SEDMLCONSTRUCTOR_EXCEPTION(SedRepeatedTask)
SEDMLCONSTRUCTOR_EXCEPTION(SedReport)
SEDMLCONSTRUCTOR_EXCEPTION(SedSetValue)
SEDMLCONSTRUCTOR_EXCEPTION(SedShadedArea)
SEDMLCONSTRUCTOR_EXCEPTION(SedSimulation)
SEDMLCONSTRUCTOR_EXCEPTION(SedSlice)
SEDMLCONSTRUCTOR_EXCEPTION(SedSteadyState)
SEDMLCONSTRUCTOR_EXCEPTION(SedStyle)
SEDMLCONSTRUCTOR_EXCEPTION(SedSubPlot)
SEDMLCONSTRUCTOR_EXCEPTION(SedSubTask)
SEDMLCONSTRUCTOR_EXCEPTION(SedSurface)
SEDMLCONSTRUCTOR_EXCEPTION(SedTask)
SEDMLCONSTRUCTOR_EXCEPTION(SedUniformRange)
SEDMLCONSTRUCTOR_EXCEPTION(SedUniformTimeCourse)
SEDMLCONSTRUCTOR_EXCEPTION(SedVariable)
SEDMLCONSTRUCTOR_EXCEPTION(SedVectorRange)
SEDMLCONSTRUCTOR_EXCEPTION(SedWaterfallPlot)

SEDMLCONSTRUCTOR_EXCEPTION(SyntaxChecker)
SEDMLCONSTRUCTOR_EXCEPTION(Tuple)
SEDMLCONSTRUCTOR_EXCEPTION(TupleDescription)
SEDMLCONSTRUCTOR_EXCEPTION(XMLAttributes)
SEDMLCONSTRUCTOR_EXCEPTION(XMLError)
SEDMLCONSTRUCTOR_EXCEPTION(XMLErrorLog)
SEDMLCONSTRUCTOR_EXCEPTION(XMLInputStream)
SEDMLCONSTRUCTOR_EXCEPTION(XMLNamespaces)
SEDMLCONSTRUCTOR_EXCEPTION(XMLNode)
SEDMLCONSTRUCTOR_EXCEPTION(XMLOutputStream)
SEDMLCONSTRUCTOR_EXCEPTION(XMLOwningOutputFileStream)
SEDMLCONSTRUCTOR_EXCEPTION(XMLOwningOutputStringStream)
SEDMLCONSTRUCTOR_EXCEPTION(XMLToken)
SEDMLCONSTRUCTOR_EXCEPTION(XMLTriple)



/**
* Ignores XMLToken::clone() in order to use XMLNode::clone().
* (XMLNode is a derived class of XMLToken)
* In JDK 1.4.2, "XMLNode XMLNode::clone()" can't override 
* "XMLToken XMLToken::clone()" because JDK 1.4.2 doesn't
* allow override with different return type.
*/

//%javamethodmodifiers       XMLToken::clone "private"

/**
* Ignores XMLErrorLog::getError(unsigned int) in order to use
* SedErrorLog::getError(unsigned int).
* (XMLErrorLog is a derived class of SedErrorLog)
* In JDK 1.4.2, "SedError* SedErrorLog::getError(unsigned int)"
* can't override "XMLError* XMLErrorLog::getError(unsigned int)"
* due to the above mentioned reason.
*/

//%javamethodmodifiers       XMLErrorLog::getError "private"

/**
* Turns off object destruction.  For testing purposes only.
*
* FIXME: Disable for the final 3.0 release.
*/
/*
%typemap (javafinalize) SWIGTYPE %{ %}
*/


/**
* Make most libSEDML constants (e.g. SedTypecodes) Java compile-time
* constants so they may be used in switch statements.
*/
%include "enumsimple.swg"
%javaconst(1);


/**
* A bug in Swig prevents these four ASTNode constants being generated
* as Java compile-time constants.  Swig does not parse the following
* enum correctly:
*
*   typedef enum
*   {
*       AST_PLUS    = '+'
*     , AST_MINUS   = '-'
*     , AST_TIMES   = '*'
*     , AST_DIVIDE  = '/'
*     , AST_POWER   = '^'
*
*
* The generated Java code does not like the tick marks (').  To fix
* this, we need to be explicit about (and duplicate) the value of
* the constants here.
*/

%javaconstvalue("'+'") AST_PLUS;
%javaconstvalue("'-'") AST_MINUS;
%javaconstvalue("'*'") AST_TIMES;
%javaconstvalue("'/'") AST_DIVIDE;
%javaconstvalue("'^'") AST_POWER;



/**
* @return the most specific Java object possible for the given SedBase
* object.
*/
%pragma(java) modulecode =
%{
	

	/**
* Internal method.
*
* @internal
*/
	public static SedBase DowncastSedBase(long cPtr, boolean owner)
	{
		if (cPtr == 0) return null;

		SedBase sb = new SedBase(cPtr, false);
    switch( sb.getTypeCode() )
    {
    case (int) libsedml.SEDML_DOCUMENT:
      return new SedDocument(cPtr, owner);

    case (int) libsedml.SEDML_MODEL:
      return new SedModel(cPtr, owner);

    case (int) libsedml.SEDML_CHANGE:
      return new SedChange(cPtr, owner);

    case (int) libsedml.SEDML_CHANGE_ADDXML:
      return new SedAddXML(cPtr, owner);

    case (int) libsedml.SEDML_CHANGE_ATTRIBUTE:
      return new SedChangeAttribute(cPtr, owner);

    case (int) libsedml.SEDML_VARIABLE:
      return new SedVariable(cPtr, owner);

    case (int) libsedml.SEDML_PARAMETER:
      return new SedParameter(cPtr, owner);

    case (int) libsedml.SEDML_SIMULATION:
      return new SedSimulation(cPtr, owner);

    case (int) libsedml.SEDML_SIMULATION_UNIFORMTIMECOURSE:
      return new SedUniformTimeCourse(cPtr, owner);

    case (int) libsedml.SEDML_SIMULATION_ALGORITHM:
      return new SedAlgorithm(cPtr, owner);

    case (int) libsedml.SEDML_SEDML_ABSTRACTTASK:
      return new SedAbstractTask(cPtr, owner);

    case (int) libsedml.SEDML_TASK:
      return new SedTask(cPtr, owner);

    case (int) libsedml.SEDML_DATAGENERATOR:
      return new SedDataGenerator(cPtr, owner);

    case (int) libsedml.SEDML_OUTPUT:
      return new SedOutput(cPtr, owner);

    case (int) libsedml.SEDML_OUTPUT_PLOT:
      return new SedPlot(cPtr, owner);

    case (int) libsedml.SEDML_OUTPUT_PLOT2D:
      return new SedPlot2D(cPtr, owner);

    case (int) libsedml.SEDML_OUTPUT_PLOT3D:
      return new SedPlot3D(cPtr, owner);

    case (int) libsedml.SEDML_PARAMETERESTIMATIONRESULTPLOT:
      return new SedParameterEstimationResultPlot(cPtr, owner);

    case (int) libsedml.SEDML_ABSTRACTCURVE:
      return new SedAbstractCurve(cPtr, owner);

    case (int) libsedml.SEDML_OUTPUT_CURVE:
      return new SedCurve(cPtr, owner);

    case (int) libsedml.SEDML_OUTPUT_SURFACE:
      return new SedSurface(cPtr, owner);

    case (int) libsedml.SEDML_OUTPUT_DATASET:
      return new SedDataSet(cPtr, owner);

    case (int) libsedml.SEDML_OUTPUT_REPORT:
      return new SedReport(cPtr, owner);

    case (int) libsedml.SEDML_SIMULATION_ALGORITHM_PARAMETER:
      return new SedAlgorithmParameter(cPtr, owner);

    case (int) libsedml.SEDML_RANGE:
      return new SedRange(cPtr, owner);

    case (int) libsedml.SEDML_CHANGE_CHANGEXML:
      return new SedChangeXML(cPtr, owner);

    case (int) libsedml.SEDML_CHANGE_REMOVEXML:
      return new SedRemoveXML(cPtr, owner);

    case (int) libsedml.SEDML_TASK_SETVALUE:
      return new SedSetValue(cPtr, owner);

    case (int) libsedml.SEDML_RANGE_UNIFORMRANGE:
      return new SedUniformRange(cPtr, owner);

    case (int) libsedml.SEDML_RANGE_VECTORRANGE:
      return new SedVectorRange(cPtr, owner);

    case (int) libsedml.SEDML_RANGE_FUNCTIONALRANGE:
      return new SedFunctionalRange(cPtr, owner);

    case (int) libsedml.SEDML_TASK_SUBTASK:
      return new SedSubTask(cPtr, owner);

    case (int) libsedml.SEDML_SIMULATION_ONESTEP:
      return new SedOneStep(cPtr, owner);

    case (int) libsedml.SEDML_SIMULATION_ANALYSIS:
      return new SedAnalysis(cPtr, owner);

    case (int) libsedml.SEDML_SIMULATION_STEADYSTATE:
      return new SedSteadyState(cPtr, owner);

    case (int) libsedml.SEDML_TASK_REPEATEDTASK:
      return new SedRepeatedTask(cPtr, owner);

    case (int) libsedml.SEDML_CHANGE_COMPUTECHANGE:
      return new SedComputeChange(cPtr, owner);

    case (int) libsedml.SEDML_DATA_DESCRIPTION:
      return new SedDataDescription(cPtr, owner);

    case (int) libsedml.SEDML_DATA_SOURCE:
      return new SedDataSource(cPtr, owner);

    case (int) libsedml.SEDML_DATA_SLICE:
      return new SedSlice(cPtr, owner);

    case (int) libsedml.SEDML_TASK_PARAMETER_ESTIMATION:
      return new SedParameterEstimationTask(cPtr, owner);

    case (int) libsedml.SEDML_OBJECTIVE:
      return new SedObjective(cPtr, owner);

    case (int) libsedml.SEDML_LEAST_SQUARE_OBJECTIVE:
      return new SedLeastSquareObjectiveFunction(cPtr, owner);

    case (int) libsedml.SEDML_ADJUSTABLE_PARAMETER:
      return new SedAdjustableParameter(cPtr, owner);

    case (int) libsedml.SEDML_EXPERIMENT_REFERENCE:
      return new SedExperimentReference(cPtr, owner);

    case (int) libsedml.SEDML_FIT_EXPERIMENT:
      return new SedFitExperiment(cPtr, owner);

    case (int) libsedml.SEDML_FITMAPPING:
      return new SedFitMapping(cPtr, owner);

    case (int) libsedml.SEDML_BOUNDS:
      return new SedBounds(cPtr, owner);

    case (int) libsedml.SEDML_FIGURE:
      return new SedFigure(cPtr, owner);

    case (int) libsedml.SEDML_SUBPLOT:
      return new SedSubPlot(cPtr, owner);

    case (int) libsedml.SEDML_AXIS:
      return new SedAxis(cPtr, owner);

    case (int) libsedml.SEDML_STYLE:
      return new SedStyle(cPtr, owner);

    case (int) libsedml.SEDML_LINE:
      return new SedLine(cPtr, owner);

    case (int) libsedml.SEDML_MARKER:
      return new SedMarker(cPtr, owner);

    case (int) libsedml.SEDML_FILL:
      return new SedFill(cPtr, owner);

    case (int) libsedml.SEDML_APPLIEDDIMENSION:
      return new SedAppliedDimension(cPtr, owner);

    case (int) libsedml.SEDML_DATA_RANGE:
      return new SedDataRange(cPtr, owner);

    case (int) libsedml.SEDML_SHADEDAREA:
      return new SedShadedArea(cPtr, owner);

    case (int) libsedml.SEDML_WATERFALLPLOT:
      return new SedWaterfallPlot(cPtr, owner);

    case (int) libsedml.SEDML_PARAMETERESTIMATIONREPORT:
      return new SedParameterEstimationReport(cPtr, owner);

    case (int) libsedml.SEDML_LIST_OF:
      String name = sb.getElementName();
      if(name.equals("listOf"))
      {
        return new SedListOf(cPtr, owner);
      }
      else if (name.equals("listOfModels"))
      {
         return new SedListOfModels(cPtr, owner);
      }
      else if (name.equals("listOfChanges"))
      {
         return new SedListOfChanges(cPtr, owner);
      }
      else if (name.equals("listOfVariables"))
      {
         return new SedListOfVariables(cPtr, owner);
      }
      else if (name.equals("listOfParameters"))
      {
         return new SedListOfParameters(cPtr, owner);
      }
      else if (name.equals("listOfSimulations"))
      {
         return new SedListOfSimulations(cPtr, owner);
      }
      else if (name.equals("listOfTasks"))
      {
         return new SedListOfTasks(cPtr, owner);
      }
      else if (name.equals("listOfDataGenerators"))
      {
         return new SedListOfDataGenerators(cPtr, owner);
      }
      else if (name.equals("listOfOutputs"))
      {
         return new SedListOfOutputs(cPtr, owner);
      }
      else if (name.equals("listOfCurves"))
      {
         return new SedListOfCurves(cPtr, owner);
      }
      else if (name.equals("listOfSurfaces"))
      {
         return new SedListOfSurfaces(cPtr, owner);
      }
      else if (name.equals("listOfDataSets"))
      {
         return new SedListOfDataSets(cPtr, owner);
      }
      else if (name.equals("listOfAlgorithmParameters"))
      {
         return new SedListOfAlgorithmParameters(cPtr, owner);
      }
      else if (name.equals("listOfRanges"))
      {
         return new SedListOfRanges(cPtr, owner);
      }
      else if (name.equals("listOfChanges"))
      {
         return new SedListOfSetValues(cPtr, owner);
      }
      else if (name.equals("listOfSubTasks"))
      {
         return new SedListOfSubTasks(cPtr, owner);
      }
      else if (name.equals("listOfDataDescriptions"))
      {
         return new SedListOfDataDescriptions(cPtr, owner);
      }
      else if (name.equals("listOfDataSources"))
      {
         return new SedListOfDataSources(cPtr, owner);
      }
      else if (name.equals("listOfSlices"))
      {
         return new SedListOfSlices(cPtr, owner);
      }
      else if (name.equals("listOfAdjustableParameters"))
      {
         return new SedListOfAdjustableParameters(cPtr, owner);
      }
      else if (name.equals("listOfExperimentReferences"))
      {
         return new SedListOfExperimentReferences(cPtr, owner);
      }
      else if (name.equals("listOfFitExperiments"))
      {
         return new SedListOfFitExperiments(cPtr, owner);
      }
      else if (name.equals("listOfFitMappings"))
      {
         return new SedListOfFitMappings(cPtr, owner);
      }
      else if (name.equals("listOfSubPlots"))
      {
         return new SedListOfSubPlots(cPtr, owner);
      }
      else if (name.equals("listOfAppliedDimensions"))
      {
         return new SedListOfAppliedDimensions(cPtr, owner);
      }
      else if (name.equals("listOfStyles"))
      {
         return new SedListOfStyles(cPtr, owner);
      }
      
      return new SedListOf(cPtr, owner);        
      
    default:
      return new SedBase(cPtr, owner);
		}      

	}
	%}



/**
* Convert SedBase objects into the most specific object possible.
*/
%typemap("javaout") SedBase*, SedSimulation*, SedAbstractTask*, SedTask*, SedOutput*, SedChange*, SedRange*, SedAbstractCurve*
{
	return ($javaclassname)libsedml.DowncastSedBase($jnicall, $owner);
}


/**
* getCPtrAndDisown() is like getCPtr() but it also sets the SWIG memory
* ownsership flag to false.
*
* We used to use %typemap(javagetcptr), but this has been deprecated
* in SWIG 1.3.24.  Instead we add getCPtrAndDisown() from the incantation
* below (taken from the SWIG 1.3.24 CHANGES file).
*/

/* Utility macro for manipulating the Java body code method attributes */
%define SWIGJAVA_ATTRIBS(TYPENAME, CTOR_ATTRIB, GETCPTR_ATTRIB)

%typemap(javabody) TYPENAME
%{
	private long swigCPtr;
	protected boolean swigCMemOwn;

	CTOR_ATTRIB $javaclassname(long cPtr, boolean cMemoryOwn)
	{
		swigCMemOwn = cMemoryOwn;
		swigCPtr    = cPtr;
	}

	GETCPTR_ATTRIB static long getCPtr($javaclassname obj)
	{
		return (obj == null) ? 0 : obj.swigCPtr;
	}

	GETCPTR_ATTRIB static long getCPtrAndDisown ($javaclassname obj)
	{
		long ptr = 0;

		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}

		return ptr;
	}
	%}


#if SWIG_VERSION >= 0x020000

%typemap(javabody_derived) TYPENAME
%{
	private long swigCPtr;

	CTOR_ATTRIB $javaclassname(long cPtr, boolean cMemoryOwn)
	{
		super($moduleJNI.$javaclassname_SWIGUpcast(cPtr), cMemoryOwn);
		swigCPtr = cPtr;
	}

	GETCPTR_ATTRIB static long getCPtr($javaclassname obj)
	{
		return (obj == null) ? 0 : obj.swigCPtr;
	}

	GETCPTR_ATTRIB static long getCPtrAndDisown ($javaclassname obj)
	{
		long ptr = 0;

		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}

		return ptr;
	}
	%}

#else

%typemap(javabody_derived) TYPENAME
%{
	private long swigCPtr;

	CTOR_ATTRIB $javaclassname(long cPtr, boolean cMemoryOwn)
	{
		super($moduleJNI.SWIG$javaclassnameUpcast(cPtr), cMemoryOwn);
		swigCPtr = cPtr;
	}

	GETCPTR_ATTRIB static long getCPtr($javaclassname obj)
	{
		return (obj == null) ? 0 : obj.swigCPtr;
	}

	GETCPTR_ATTRIB static long getCPtrAndDisown ($javaclassname obj)
	{
		long ptr = 0;

		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}

		return ptr;
	}
	%}

#endif

%enddef

/* The default is protected getCPtr, protected constructor */
SWIGJAVA_ATTRIBS(SWIGTYPE, protected, protected)

/* Public getCPtr method, protected constructor */
%define PUBLIC_GETCPTR(TYPENAME)
SWIGJAVA_ATTRIBS(TYPENAME, protected, public)
%enddef

/* Public getCPtr method, public constructor */
%define PUBLIC_BODYMETHODS(TYPENAME)
SWIGJAVA_ATTRIBS(TYPENAME, public, public)
%enddef

/**
*
* Overrides the 'equals' method for SedBase subclasses and other classes
* in libsedml.
*
* By default, 'equals' method ( and '==' operator) for each wrapped class
* object returns 'true' if the given two objects refer to the same 
* *Java proxy object* (not the underlying C++ object). 
* For example, the following code returns 'true'.
*
*   Model m = new Model();
*   m.createReaction();
*   Reaction r1  = m.getReaction(0);
*   Reaction r2 = r1;
*   return r1.equals(r2);  <---- this returns 'true'
*
* On the other hand, the following code returns 'false' in spite of
* the same underlying C++ objects.
*
*   Model m = new Model();
*   m.createReaction();
*   Reaction r1 = m.getReaction(0);
*   Reaction r2 = m.getReaction(0);
*   return r1.equals(r2);  <---- this returns 'false'
*
* The following override changes the behaviour of 'equals' method such that
* returns 'true' if the given two objects refer to the same underlying C++ 
* object (i.e. 'true' is returned in the both above examples).
*
* (Unfortunately, '==' operator can't be overidden in Java.
*  Thus, the underlying C++ objects can't be compared by the '==' operator.)
* 
*/

%define SWIGJAVA_EQUALS(CLASS)
%typemap("javacode") CLASS
%{
	/**
* Equality comparison method for CLASS.
* <p>
* Because the Java methods for libSEDML are actually wrappers around code
* implemented in C++ and C, certain operations will not behave as
* expected.  Equality comparison is one such case.  An instance of a
* libSEDML object class is actually a <em>proxy object</em>
* wrapping the real underlying C/C++ object.  The normal <code>==</code>
* equality operator in Java will <em>only compare the Java proxy objects</em>,
* not the underlying native object.  The result is almost never what you
* want in practical situations.  Unfortunately, Java does not provide a
* way to override <code>==</code>.
*  <p>
* The alternative that must be followed is to use the
* <code>equals()</code> method.  The <code>equals</code> method on this
* class overrides the default java.lang.Object one, and performs an
* intelligent comparison of instances of objects of this class.  The
* result is an assessment of whether two libSEDML Java objects are truly 
* the same underlying native-code objects.
*  <p>
* The use of this method in practice is the same as the use of any other
* Java <code>equals</code> method.  For example,
* <em>a</em><code>.equals(</code><em>b</em><code>)</code> returns
* <code>true</code> if <em>a</em> and <em>b</em> are references to the
* same underlying object.
*
* @param sb a reference to an object to which the current object
* instance will be compared
*
* @return <code>true</code> if <code>sb</code> refers to the same underlying 
* native object as this one, <code>false</code> otherwise
*/
	public boolean equals(Object sb)
	{
		if ( this == sb ) 
		{
			return true;
		}
		return swigCPtr == getCPtr((CLASS)(sb));
	}

	/**
* Returns a hashcode for this CLASS object.
*
* @return a hash code usable by Java methods that need them.
*/
	public int hashCode()
	{
		return (int)(swigCPtr^(swigCPtr>>>32));
	}
	%}
%enddef

SWIGJAVA_EQUALS(SedBase)
SWIGJAVA_EQUALS(SedReader)
SWIGJAVA_EQUALS(SedWriter)
SWIGJAVA_EQUALS(ASTNode)
SWIGJAVA_EQUALS(CVTerm)
SWIGJAVA_EQUALS(Date)
SWIGJAVA_EQUALS(ModelHistory)
SWIGJAVA_EQUALS(ModelCreator)
SWIGJAVA_EQUALS(XMLNamespaces)
SWIGJAVA_EQUALS(SedNamespaces)
SWIGJAVA_EQUALS(XMLAttributes)
SWIGJAVA_EQUALS(XMLToken)
SWIGJAVA_EQUALS(XMLNode)
SWIGJAVA_EQUALS(XMLTriple)
SWIGJAVA_EQUALS(XMLError)
SWIGJAVA_EQUALS(XMLErrorLog)
SWIGJAVA_EQUALS(XMLOutputStream)

/**
* Part of libSEDML methods takeover ownership of passed-in objects, so we need
* to make sure SWIG disowns the object.
* (Most libSEDML methods don't takeover ownership since 3.0.0)
*
*/

/**
* takeover ownership
*
* - void SedListOf::appendAndOwn(SedBase* item)
*/
%typemap(javain) SedBase*       item "SedBase.getCPtrAndDisown($javainput)";
%typemap(javain) const SedBase* item "SedBase.getCPtr($javainput)";

/**
* takeover ownership
*
* - void ASTNode::addChild (ASTNode* child)
* - void ASTNode::prependChild (ASTNode* child)
*/
%typemap(javain) ASTNode*       child "ASTNode.getCPtrAndDisown($javainput)";
%typemap(javain) const ASTNode* child "ASTNode.getCPtr($javainput)";

/**
* takeover ownership
*
* - void ASTNode::insertChild (unsigned int n, ASTNode *newChild)
* - void ASTNode::replaceChild(unsigned int n, ASTNode *newChild)
*/
%typemap(javain) ASTNode*       newChild "ASTNode.getCPtrAndDisown($javainput)";
%typemap(javain) const ASTNode* newChild "ASTNode.getCPtr($javainput)";

/**
* takeover ownership
*
* - void ASTNode::addSemanticsAnnotation (XMLNode* sAnnotation);
*/
%typemap(javain) XMLNode*       sAnnotation "XMLNode.getCPtrAndDisown($javainput)";
%typemap(javain) const XMLNode* sAnnotation "XMLNode.getCPtr($javainput)";


/**
* On Windows, a string for filename should be encoded by ANSI CP 
* instead of UTF-8 because file I/O APIs internally used in libSEDML 
* requires an ANSI CP encoded string for the given filename.
*  
*  1) SedReader::readSedML(const std::string& filename)
*  2) readSedML(const char* filename)
*  3) SedWriter::writeSedML(SedDocument*, const std::string& filename)
*  4) writeSedML(SedDocument*, const char* filename)
*/

//
// UTF8 -> ANSI CP (for const std::string& filename)
//
%typemap("in") const std::string& filename (const char* arg_pstr, std::string arg_str) 
%{
	if(!$input) {
		SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null std::string");
		return $null;
	}
	arg_pstr = (char const *)jenv->GetStringUTFChars($input, 0);
	if (!arg_pstr) return $null;
#ifdef WIN32
	char*  mbstr = convertUTF8ToACP(arg_pstr);
	if (!mbstr)
	{
		jenv->ReleaseStringUTFChars($input, arg_pstr);
		return $null;
	}

	arg_str.assign(mbstr);
	delete[] mbstr;
#else
	arg_str.assign(arg_pstr);
#endif
	$1 = &arg_str;
	jenv->ReleaseStringUTFChars($input, arg_pstr);

	%}



//
// Unicode -> ANSI CP (for const char* filename)
//
%typemap("in")  const char* filename (const char* arg_pstr)
%{
	if ($input) {
		arg_pstr = (char const *)jenv->GetStringUTFChars($input, 0);
		if (!arg_pstr) return $null;
	}
	else
	{
		arg_pstr = 0;
	}
#ifdef WIN32
	$1 = convertUTF8ToACP(arg_pstr);
	if (!$1)
	{
		jenv->ReleaseStringUTFChars($input, (const char*)arg_pstr);
		return $null;
	}
	jenv->ReleaseStringUTFChars($input, (const char*)arg_pstr);
#else
	$1 = (char*)arg_pstr;
#endif
	%}

%typemap("freearg")  const char* filename 
%{
#ifdef WIN32
	delete[] $1;
#else
	if ($1) jenv->ReleaseStringUTFChars($input, (const char*)$1);
#endif
	%}


/**
* Some combinations of platforms and underlying XML parsers *require*
* an absolute path to a filename while others do not.  It's best to
* hide this from the end-user by making SedReader.readSedML() and
* readSedML() always compute an absolute path and filename.
*/

%pragma(java) modulecode =
%{
	static String getAbsolutePath(String filename)
	{
		java.io.File file = new java.io.File(filename);
		return file.getAbsolutePath();
	}
	%}

%typemap("javain") const std::string& filename "libsedml.getAbsolutePath($javainput)";
%typemap("javain") const char* filename        "libsedml.getAbsolutePath($javainput)";

/**
* Wraps std::ostream by implementing three simple wrapper classes.
*
* 1) OStream wraps std::cout, std::cerr, and std::clog.
*    The following public final static variables are provied in
*    libsedml class like in C++.
*
*    1. public final static OStream cout;
*    2. public final static OStream cerr;
*    3. public final static OStream clog;
*
* 2) OFStream (derived class of OStream) wraps std::ofstream 
*    with ios_base::cout (default) or ios_base::app flag. 
*
* 3) OStringStream (derived class of OStream) wraps std::ostringstream.
*
* These wrapper classes provide only the minimum functions.
*
* (sample code) -----------------------------------------------------
*
* 1. wraps std::cout
*
*    XMLOutputStream xos = new XMLOutputStream(libsedml.cout);
*
* 2. wraps std::cerr
*
*    SedDocument d = libsedml.readSedML("foo.xml");
*    if ( d.getNumErrors() > 0) {
*       d.printErrors(libsedml.cerr);
*    }
*
* 3. wraps std::ofstream (write to file "foo.xml")
*
*    OFStream   ofs = new OFStream("foo.xml");
*    SedDocument d = libsedml.readSedML("foo.xml");
*    SedWriter   w = new SedWriter();
*    w.writeSedML(d,ofs);
*
* 4. wraps std::ofstream (write to file "foo.xml" with append mode)
*
*    OFStream ofs = new OFStream("foo.xml",true);
*    XMLOutputStream xos = new XMLOutputStream(ofs);
*
* 5. wraps std::ostringstream 
*
*    OStringStream   oss = new OStringStream();
*    XMLOutputStream xos = new XMLOutputStream(oss);
*    ...
*    oss.endl();
*    String s = oss.str();
*
*/

%typemap(jstype) std::ostream& "OStream"
%typemap(javain) std::ostream& "SWIGTYPE_p_std__ostream.getCPtr($javainput.get_ostream())";

%include "OStream.h"

%{
#include "OStream.cpp"
	%}

%pragma(java) modulecode =
%{
	/**
* Stream handle for low-level C++ standard output stream.
* <p>
* A few libSEDML methods accept an argument for indicating where to send
* text string output.  An example is the {@link
* SedDocument#printErrors} method.  However, the methods use C++ style
* streams and not Java stream objects.  The OStream object class in the
* libSEDML Java interface provides a wrapper for the underlying C++
* streams.  The present object (cout) is a static final variable that
* can be used directly from your code.  An example use might be
* something like this:
* <p>
* <div class="fragment"><pre class="fragment">
* SedDocument document = libsedml.readSedML("somefile.xml");
* if (document.getNumErrors() > 0)
* {
*     document.printErrors(libsedml.cout);
*     println("Please correct the above problems first.");
*     System.exit(1);
* }</div>
*
* @see #cerr
* @see #clog
*/
	public final static OStream cout;


	/**
* Stream handle for low-level C++ standard error stream.
* <p>
* A few libSEDML methods accept an argument for indicating where to send
* text string output.  An example is the {@link
* SedDocument#printErrors} method.  However, the methods use C++ style
* streams and not Java stream objects.  The OStream object class in the
* libSEDML Java interface provides a wrapper for the underlying C++
* streams.  The present object (cerr) is a static final variable that
* can be used directly from your code.  An example use might be
* something like this:
* <p>
* <div class="fragment"><pre class="fragment">
* SedDocument document = libsedml.readSedML("somefile.xml");
* if (document.getNumErrors() > 0)
* {
*     document.printErrors(libsedml.cerr);
*     println("Please correct the above problems first.");
*     System.exit(1);
* }</div>
* <p>
* By default, most operating systems have have their standard error and
* logging output streams directed to the console/terminal, and this is
* where text messages will be shown.  This can usually be redirected
* elsewhere, although how to do this depends on the specific environment
* where the program is running.
*
* @see #cout
* @see #clog
*/
	public final static OStream cerr;


	/**
* Stream handle for low-level C++ standard logging stream.
* <p>
* A few libSEDML methods accept an argument for indicating where to send
* text string output.  An example is the {@link
* SedDocument#printErrors} method.  However, the methods use C++ style
* streams and not Java stream objects.  The OStream object class in the
* libSEDML Java interface provides a wrapper for the underlying C++
* streams.  The present object (clog) is a static final variable that
* can be used directly from your code.  An example use might be
* something like this:
* <p>
* <div class="fragment"><pre class="fragment">
* SedDocument document = libsedml.readSedML("somefile.xml");
* if (document.getNumErrors() > 0)
* {
*     document.printErrors(libsedml.clog);
*     println("Please correct the above problems first.");
*     System.exit(1);
* }</div>
* <p>
* By default, most operating systems have have their standard error and
* logging output streams directed to the console/terminal, and this is
* where text messages will be shown.  This can usually be redirected
* elsewhere, although how to do this depends on the specific environment
* where the program is running.
*
* @see #cout
* @see #cerr
*/
	public final static OStream clog;

	static {
		cout = new OStream(OStream.COUT); 
		cerr = new OStream(OStream.CERR); 
		clog = new OStream(OStream.CLOG); 
	}

	/**
* This private constructor does nothing and never invoked.
* The purpose of this constuctor is to hide a default constructor of this 
* class in javadoc documentation.
*/
	private libsedml() {}

	%}



/**
*  Wraps the following functions by using the corresponding
*  ListWrapper<TYPENAME> class.
*
*  - List* ModelHistory::getListCreators()
*  - List* ModelHistory::getListModifiedDates()
*  - List* SedBase::getCVTerms()
*  - List* SedNamespaces::getSupportedNamespaces()
*
*  ListWrapper<TYPENAME> class is wrapped as TYPENAMEListclass.
*  So, the above functions are wrapped as follows:
*
*  - ModelCreatorList ModelHistory.getListCreators()
*  - DateList         ModelHistory.getListModifiedDates()
*  - CVTermList       SedBase.getCVTerms()
*  - SedNamespacseList SedNamespaces.getSupportedNamespaces()
*
*/

%define LIST_WRAPPER(_FNAME_,_TYPENAME_)
%typemap(jstype)  List* _FNAME_ %{ _TYPENAME_ ## List %}

%typemap(javaout) List* _FNAME_ 
{ 
	long cPtr = $jnicall;
	return (cPtr == 0) ? null : new  _TYPENAME_ ## List(cPtr, true);
}

%typemap(out) List* _FNAME_ 
{
	ListWrapper<_TYPENAME_> *listw = ($1 != 0) ? new ListWrapper<_TYPENAME_>($1) : 0;  
	*( ListWrapper<_TYPENAME_>   **)&$result = listw;
}
%enddef

LIST_WRAPPER(SedBase::getSedListOfAllElements,SedBase)


