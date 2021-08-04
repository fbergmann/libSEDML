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
%csconst(1);


%csconstvalue("'+'") AST_PLUS;
%csconstvalue("'-'") AST_MINUS;
%csconstvalue("'*'") AST_TIMES;
%csconstvalue("'/'") AST_DIVIDE;
%csconstvalue("'^'") AST_POWER;


////////////////////////////////////////////////////////////////////////////////
//
// Changes default behaviour for converting string variables between 
// C# side and C++ side.
//
// -----------------------------------------------------------------------------
// (default)  
// C# string (Unicode (wide char)) -> C++ char* (ANSI CP (multibyte char))
// 
// (changed)  
// C# string (Unicode (wide char)) -> C++ wchar_t* (Unicode (wide char)) 
// -> C++ char* (UTF8 (multibyte char))
// -----------------------------------------------------------------------------
//
// By default, C# Unicode string is converted to C++ ANSI CP string (not UTF8 
// string) and this leads to an invalid encoding error in libSEDML API which 
// requires UTF8 string.
// To avoid this problem, the following typemap directive changes the behaviour 
// of string conversion to pass UTF8 string to libSEDML C++ API. 
// Since there seems to be no way to directly convert C# Unicode string to C++ 
// UTF8 string, C# Unicode string is converted to C++ Unicode character (wchar_t*) 
// and then converted to UTF8 character (char*). 
// and then converted to UTF8 character (char*). 
//

#ifdef SWIGWIN 

%define SWIGCSHARP_IMTYPE_WSTRING(TYPENAME)
%typemap(imtype, 
inattributes="[MarshalAs(UnmanagedType.LPWStr)]", 
outattributes="[return: MarshalAs(UnmanagedType.LPWStr)]" 
) TYPENAME "string"
%enddef

SWIGCSHARP_IMTYPE_WSTRING(std::string)
SWIGCSHARP_IMTYPE_WSTRING(std::string&)
SWIGCSHARP_IMTYPE_WSTRING(const std::string&)
SWIGCSHARP_IMTYPE_WSTRING(std::string*)
SWIGCSHARP_IMTYPE_WSTRING(const std::string*)
SWIGCSHARP_IMTYPE_WSTRING(char*)
SWIGCSHARP_IMTYPE_WSTRING(const char*)

//
// In SWIG-1.3.35, a callback function for a returned wide string (implemented in 
// SWIGWStringHelper class) doesn't work when the given Unicode string converted 
// from UTF8 string (the callback function is used in libsedml_wrap.cpp when 
// returning an Unicode character).
// So, currently, the SWIGWStringHelper class is modified as follows.
//
// (NOTICE) 
//  To disable the default SWIGStringHelper class, SWIG_CSHARP_NO_WSTRING_HELPER 
//  needs to be defined by passing  -DSWIG_CSHARP_NO_WSTRING_HELPER  to SWIG command 
//  line.
//

%insert(runtime) %{
  /* Callback for returning strings to C# without leaking memory */
  typedef void * (SWIGSTDCALL* SWIG_CSharpWStringHelperCallback)(const wchar_t *);
  static SWIG_CSharpWStringHelperCallback SWIG_csharp_wstring_callback = NULL;
  %}

%pragma(csharp) imclasscode=%{
  protected class SWIGWStringHelper {

    public delegate IntPtr SWIGWStringDelegate(IntPtr message);
    static SWIGWStringDelegate wstringDelegate = new SWIGWStringDelegate(CreateWString);

    [DllImport("$dllimport", EntryPoint="SWIGRegisterWStringCallback_$module")]
    public static extern void SWIGRegisterWStringCallback_$module(SWIGWStringDelegate wstringDelegate);

    static IntPtr CreateWString([MarshalAs(UnmanagedType.LPWStr)]IntPtr cString) {
      string ustr = System.Runtime.InteropServices.Marshal.PtrToStringUni(cString);
      return System.Runtime.InteropServices.Marshal.StringToHGlobalUni(ustr);
    }

    static SWIGWStringHelper() {
      SWIGRegisterWStringCallback_$module(wstringDelegate);
    }
  }

  static protected SWIGWStringHelper swigWStringHelper = new SWIGWStringHelper();
  %}

%insert(runtime) %{
#ifdef __cplusplus
  extern "C"
#endif
  SWIGEXPORT void SWIGSTDCALL SWIGRegisterWStringCallback_$module(SWIG_CSharpWStringHelperCallback callback) {
    SWIG_csharp_wstring_callback = callback;
  }
  %}

#endif //SWIGWIN

//////////////////////////////////////////////////////////////////////
//
// typemap between "unsigned int (C++)" and "long (C#)"
//
// The following typemap directives for the above conversion have been
// added with CLS-compliant in mind. 
// (uint can not be used in CLS-compliant API)
//
//////////////////////////////////////////////////////////////////////

// mapping for a type of function argument in libsedml_wrap.cpp
%typemap(ctype,  out="unsigned int")        unsigned int        "long long"
%typemap(ctype,  out="unsigned int") const unsigned int& "const long long&"

// mapping for a type of function argument in csharp-files/libsedmlPINVOKE.cs
%typemap(imtype, out="uint") unsigned int        "long"
%typemap(imtype, out="uint") const unsigned int& "long"

// mapping for a type of function argument in csharp-files/*.cs (C# proxy classes)
%typemap(cstype) unsigned int        "long"
%typemap(cstype) const unsigned int& "long"

// conversion for a given argument in libsedml_wrap.cpp
%typemap(in)     unsigned int        { $1 = (unsigned int)$input;  }
%typemap(in)     unsigned int*       { $1 = (unsigned int*)$input; }

// conversion for a returned value in csharp-files/*.cs (C# proxy classes)
%typemap(csout)  unsigned int        { return (long)$imcall; }
%typemap(csout)  const unsigned int& { return (long)$imcall; }
%typemap(csout)  uint                { return (long)$imcall; }
%typemap(csdirectorout) unsigned int "(uint)$cscall"

//////////////////////////////////////////////////////////////////////




/**
* @return the most specific c# object possible for the given SedBase
* object.
*/
%pragma(csharp) modulecode =
%{

  
  public static SedBase DowncastSedBase(IntPtr cPtr, bool owner)
  {
    if (cPtr.Equals(IntPtr.Zero)) return null;
    
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
      if(name == "listOf")
      {
        return new SedListOf(cPtr, owner);
      }
      else if (name == "listOfModels")
      {
         return new SedListOfModels(cPtr, owner);
      }
      else if (name == "listOfChanges")
      {
         return new SedListOfChanges(cPtr, owner);
      }
      else if (name == "listOfVariables")
      {
         return new SedListOfVariables(cPtr, owner);
      }
      else if (name == "listOfParameters")
      {
         return new SedListOfParameters(cPtr, owner);
      }
      else if (name == "listOfSimulations")
      {
         return new SedListOfSimulations(cPtr, owner);
      }
      else if (name == "listOfTasks")
      {
         return new SedListOfTasks(cPtr, owner);
      }
      else if (name == "listOfDataGenerators")
      {
         return new SedListOfDataGenerators(cPtr, owner);
      }
      else if (name == "listOfOutputs")
      {
         return new SedListOfOutputs(cPtr, owner);
      }
      else if (name == "listOfCurves")
      {
         return new SedListOfCurves(cPtr, owner);
      }
      else if (name == "listOfSurfaces")
      {
         return new SedListOfSurfaces(cPtr, owner);
      }
      else if (name == "listOfDataSets")
      {
         return new SedListOfDataSets(cPtr, owner);
      }
      else if (name == "listOfAlgorithmParameters")
      {
         return new SedListOfAlgorithmParameters(cPtr, owner);
      }
      else if (name == "listOfRanges")
      {
         return new SedListOfRanges(cPtr, owner);
      }
      else if (name == "listOfChanges")
      {
         return new SedListOfSetValues(cPtr, owner);
      }
      else if (name == "listOfSubTasks")
      {
         return new SedListOfSubTasks(cPtr, owner);
      }
      else if (name == "listOfDataDescriptions")
      {
         return new SedListOfDataDescriptions(cPtr, owner);
      }
      else if (name == "listOfDataSources")
      {
         return new SedListOfDataSources(cPtr, owner);
      }
      else if (name == "listOfSlices")
      {
         return new SedListOfSlices(cPtr, owner);
      }
      else if (name == "listOfAdjustableParameters")
      {
         return new SedListOfAdjustableParameters(cPtr, owner);
      }
      else if (name == "listOfExperimentReferences")
      {
         return new SedListOfExperimentReferences(cPtr, owner);
      }
      else if (name == "listOfFitExperiments")
      {
         return new SedListOfFitExperiments(cPtr, owner);
      }
      else if (name == "listOfFitMappings")
      {
         return new SedListOfFitMappings(cPtr, owner);
      }
      else if (name == "listOfSubPlots")
      {
         return new SedListOfSubPlots(cPtr, owner);
      }
      else if (name == "listOfAppliedDimensions")
      {
         return new SedListOfAppliedDimensions(cPtr, owner);
      }
      else if (name == "listOfStyles")
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
%typemap("csout", excode=SWIGEXCODE) SedBase*
{
  SedBase ret = (SedBase) libsedml.DowncastSedBase($imcall, $owner);$excode
  return ret;
}


/**
* Convert Rule objects into the most specific object possible.
*/
%typemap("csout", excode=SWIGEXCODE) SedTask*
{
  SedTask ret = (SedTask) libsedml.DowncastSedBase($imcall, $owner);$excode
  return ret;
}

%typemap("csout", excode=SWIGEXCODE) SedAbstractTask*
{
  SedAbstractTask ret = (SedAbstractTask) libsedml.DowncastSedBase($imcall, $owner);$excode
  return ret;
}

%typemap("csout", excode=SWIGEXCODE) SedAbstractCurve*
{
  SedAbstractCurve ret = (SedAbstractCurve) libsedml.DowncastSedBase($imcall, $owner);$excode
  return ret;
}

/**
* Convert Range objects into the most specific object possible.
*/
%typemap("csout", excode=SWIGEXCODE) SedRange*
{
  SedRange ret = (SedRange) libsedml.DowncastSedBase($imcall, $owner);$excode
  return ret;
}

/**
* Convert Rule objects into the most specific object possible.
*/
%typemap("csout", excode=SWIGEXCODE) SedSimulation*
{
  SedSimulation ret = (SedSimulation) libsedml.DowncastSedBase($imcall, $owner);$excode
  return ret;
}

/**
* Convert SimpleSpeciesReference objects into the most specific object possible.
*/
%typemap("csout", excode=SWIGEXCODE) SedOutput*
{
  SedOutput ret
  = (SedOutput) libsedml.DowncastSedBase($imcall, $owner);$excode
  return ret;
}

/**
* Convert SimpleSpeciesReference objects into the most specific object possible.
*/
%typemap("csout", excode=SWIGEXCODE) SedChange*
{
  SedChange ret
  = (SedChange) libsedml.DowncastSedBase($imcall, $owner);$excode
  return ret;
}


/**
* getCPtrAndDisown() is like getCPtr() but it also sets the SWIG memory
* ownsership flag to false.
*
* We used to use %typemap(javagetcptr), but this has been deprecated
* in SWIG 1.3.24.  Instead we add getCPtrAndDisown() from the incantation
* below (taken from the SWIG 1.3.24 CHANGES file).
*/

/* Utility macro for manipulating the C# body code method attributes */
%define SWIGCSHARP_ATTRIBS(TYPENAME, CTOR_ATTRIB, GETCPTR_ATTRIB)

%typemap(csbody) TYPENAME
%{
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;
  
  CTOR_ATTRIB $csclassname(IntPtr cPtr, bool cMemoryOwn)
  {
    swigCMemOwn = cMemoryOwn;
    swigCPtr    = new HandleRef(this, cPtr);
  }
  
  GETCPTR_ATTRIB static HandleRef getCPtr($csclassname obj)
  {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }
  
  GETCPTR_ATTRIB static HandleRef getCPtrAndDisown ($csclassname obj)
  {
    HandleRef ptr = new HandleRef(null, IntPtr.Zero);
    
    if (obj != null)
    {
      ptr             = obj.swigCPtr;
      obj.swigCMemOwn = false;
    }
    
    return ptr;
  }
  %}


#if SWIG_VERSION >= 0x020000

%typemap(csbody_derived) TYPENAME
%{
  private HandleRef swigCPtr;
  
  CTOR_ATTRIB $csclassname(IntPtr cPtr, bool cMemoryOwn) : base($modulePINVOKE.$csclassname_SWIGUpcast(cPtr), cMemoryOwn)
  {
    //super($modulePINVOKE.$csclassnameUpcast(cPtr), cMemoryOwn);
    swigCPtr = new HandleRef(this, cPtr);
  }
  
  GETCPTR_ATTRIB static HandleRef getCPtr($csclassname obj)
  {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }
  
  GETCPTR_ATTRIB static HandleRef getCPtrAndDisown ($csclassname obj)
  {
    HandleRef ptr = new HandleRef(null, IntPtr.Zero);
    
    if (obj != null)
    {
      ptr             = obj.swigCPtr;
      obj.swigCMemOwn = false;
    }
    
    return ptr;
  }
  %}

#else

%typemap(csbody_derived) TYPENAME
%{
  private HandleRef swigCPtr;
  
  CTOR_ATTRIB $csclassname(IntPtr cPtr, bool cMemoryOwn) : base($modulePINVOKE.$csclassnameUpcast(cPtr), cMemoryOwn)
  {
    //super($modulePINVOKE.$csclassnameUpcast(cPtr), cMemoryOwn);
    swigCPtr = new HandleRef(this, cPtr);
  }
  
  GETCPTR_ATTRIB static HandleRef getCPtr($csclassname obj)
  {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }
  
  GETCPTR_ATTRIB static HandleRef getCPtrAndDisown ($csclassname obj)
  {
    HandleRef ptr = new HandleRef(null, IntPtr.Zero);
    
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

/* The default is INTERNAL getCPtr, INTERNAL constructor */
SWIGCSHARP_ATTRIBS(SWIGTYPE, internal, internal)

/* Public getCPtr method, PUBLIC constructor */
%define PUBLIC_GETCPTR(TYPENAME)
SWIGCSHARP_ATTRIBS(TYPENAME, protected, public)
%enddef

/* Public getCPtr method, public constructor */
%define PUBLIC_BODYMETHODS(TYPENAME)
SWIGCSHARP_ATTRIBS(TYPENAME, public, public)
%enddef


/**
*
* Overrides the 'operator==', 'operator!=', 'Equals' and 'GetHashCode' methods 
* for C# proxy classes of SedBase subclasses and classes in libSEDML.
*
* By default, 'operator==' ( and 'Equals' method) for each wrapped class
* object returns 'true' if the given two objects refer to the same 
* *C# proxy object* (not the underlying C++ object). 
* For example, the following code returns 'true'.
*
*   Model m = new Model();
*   m.createReaction();
*   Reaction r1  = m.getReaction(0);
*   Reaction r2 = r1;
*   return (r1 == r2);  <---- this returns 'true'
*
* On the other hand, the following code returns 'false' in spite of
* the same underlying C++ objects.
*
*   Model m = new Model();
*   m.createReaction();
*   Reaction r1 = m.getReaction(0);
*   Reaction r2 = m.getReaction(0);
*   return (r1 == r2);  <---- this returns 'false'
*
* The following override changes the behaviour of the default 'operator==' and
* 'Equals' method such that returns 'true' if the given two objects refer to 
* the same underlying C++  object (i.e. 'true' is returned in the both above
*  examples).
* 
*/


%define SWIGCS_EQUALS(CLASS)
%typemap("cscode") CLASS
%{
  public static bool operator==(CLASS lhs, CLASS rhs)
  {
    if((Object)lhs == (Object)rhs)
    {
      return true;
    }

    if( ((Object)lhs == null) || ((Object)rhs == null) )
    {
      return false;
    }

    return (getCPtr(lhs).Handle.ToString() == getCPtr(rhs).Handle.ToString());
  }

  public static bool operator!=(CLASS lhs, CLASS rhs)
  {
    return !(lhs == rhs);
  }

  public override bool Equals(Object sb)
  {
    if ( ! (sb is CLASS) )
    {
      return false;
    }

    return this == (CLASS)sb;
  }

  public override int GetHashCode()
  {
    return swigCPtr.Handle.ToInt32();
  }
  %}
%enddef

SWIGCS_EQUALS(SedBase)
SWIGCS_EQUALS(SedReader)
SWIGCS_EQUALS(SedWriter)
SWIGCS_EQUALS(ASTNode)
SWIGCS_EQUALS(XMLNamespaces)
SWIGCS_EQUALS(SedNamespaces)
SWIGCS_EQUALS(XMLAttributes)
SWIGCS_EQUALS(XMLToken)
SWIGCS_EQUALS(XMLNode)
SWIGCS_EQUALS(XMLError)
SWIGCS_EQUALS(XMLErrorLog)
SWIGCS_EQUALS(XMLOutputStream)


/**
* Wraps covariant return types of ::clone functions.
*
* Currently, C# doesn't support covariant return types.
* However, in wrapped C# functions, covariant return types can be emulated 
* just by changing the method modifier ("override" -> "new").
*/

#pragma SWIG nowarn=842

%define COVARIANT_RTYPE_CLONE(_CNAME_)
%typemap(cstype) _CNAME_* _CNAME_::clone  "_CNAME_"
%csmethodmodifiers _CNAME_::clone  "public new"
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
COVARIANT_RTYPE_CLONE(SedWaterfallPlot)
COVARIANT_RTYPE_CLONE(SedParameterEstimationReport)
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
COVARIANT_RTYPE_CLONE(SedListOfAppliedDimensions)
COVARIANT_RTYPE_CLONE(SedListOfStyles)

/**
*
* Wraps covariant return types of ListOfXXX::get functions.
*
* Currently, C# doesn't support covariant return types.
* However, in wrapped C# functions, covariant return types can be emulated 
* just by changing the method modifier ("override" -> "new").
*/

%define COVARIANT_RTYPE_LISTOF_GET_REMOVE(_CNAME_)
%typemap(cstype) _CNAME_* ListOf ## _CNAME_ ## s::get  "_CNAME_"
%csmethodmodifiers ListOf ## _CNAME_ ## s::get(unsigned int n)  "public new"
%typemap(cstype) _CNAME_* ListOf ## _CNAME_ ## s::remove  "_CNAME_"
%csmethodmodifiers ListOf ## _CNAME_ ## s::remove(unsigned int n)  "public new"
%enddef

COVARIANT_RTYPE_LISTOF_GET_REMOVE(CompartmentType)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Compartment)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(EventAssignment)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Event)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(FunctionDefinition)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(InitialAssignment)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Parameter)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Reaction)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Rule)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SpeciesType)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(UnitDefinition)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Constraint)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(Unit)

// Some classes don't match the macro above and have to handled separately:

%typemap(cstype) Species* ListOfSpecies::get  "Species"
%csmethodmodifiers ListOfSpecies::get(unsigned int n) "public new"
%typemap(cstype) Species* ListOfSpecies::remove  "Species"
%csmethodmodifiers ListOfSpecies::remove(unsigned int n) "public new"

%typemap(cstype) SimpleSpeciesReference* ListOfSpeciesReferences::get  "SimpleSpeciesReference"
%csmethodmodifiers ListOfSpeciesReferences::get(unsigned int n)  "public new"
%typemap(cstype) SimpleSpeciesReference* ListOfSpeciesReferences::remove  "SimpleSpeciesReference"
%csmethodmodifiers ListOfSpeciesReferences::remove(unsigned int n)  "public new"

%typemap(cstype) LocalParameter* ListOfLocalParameters::get  "Parameter"
%csmethodmodifiers ListOfLocalParameters::get(unsigned int n)  "public new"
%typemap(cstype) LocalParameter* ListOfLocalParameters::remove  "Parameter"
%csmethodmodifiers ListOfLocalParameters::remove(unsigned int n)  "public new"

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
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfAdjustableParameters)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfExperimentReferences)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfFitExperiments)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfFitMappings)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfSubPlots)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfAppliedDimensions)
COVARIANT_RTYPE_LISTOF_GET_REMOVE(SedListOfStyles)

%define COVARIANT_GETID(_CNAME_)
%typemap(cstype) string   _CNAME_ ## ::getId  "_CNAME_"
%csmethodmodifiers  _CNAME_ ## ::getId  "public new"
%enddef



/**
* Wraps the SedConstructorException
*
* The SedConstructorException (C++ class) is wrapped as the 
* SedConstructorException (C# class) which is derived from
* the built-in ArgumentException class.
*
* For example, the exception can be catched in C# code as follows:
*
* ---------------------------------------------
*  Model m;
*  try
*  {
*    m = new Model(level,version);
*  }
*  catch (SedConstructorException e)
*  {
*     string errmsg = e.Message;
*  }
* ---------------------------------------------
*/

%ignore SedConstructorException::SedConstructorException(std::string);

%typemap(csbase) SedConstructorException "System.ArgumentException";
%typemap(cscode) SedConstructorException 
%{
  internal SedConstructorException(IntPtr cPtr, bool cMemoryOwn, string v) : base(v)
  {
    swigCMemOwn = cMemoryOwn;
    swigCPtr    = new HandleRef(this, cPtr);
  }

  public SedConstructorException(string v) : 
  this(libsedmlPINVOKE.new_SedConstructorException__SWIG_0(), true, v) 
  {}
  %}

%typemap(csbase) XMLConstructorException "System.ArgumentException";
%typemap(cscode) XMLConstructorException 
%{
  internal XMLConstructorException(IntPtr cPtr, bool cMemoryOwn, string v) : base(v)
  {
    swigCMemOwn = cMemoryOwn;
    swigCPtr    = new HandleRef(this, cPtr);
  }

  public XMLConstructorException(string v) : 
  this(libsedmlPINVOKE.new_XMLConstructorException(), true, v) 
  {}
  %}

%ignore XMLConstructorException(std::string message);
//
// cited from SWIG and C# manual ("18.4.4 Custom C# ApplicationException example")
// in http://www.swig.org/
// 
%insert(runtime) %{
  // Code to handle throwing of C# CustomApplicationException from C/C++ code.
  // The equivalent delegate to the callback, CSharpExceptionCallback_t, is CustomExceptionDelegate
  // and the equivalent customExceptionCallback instance is customDelegate
  typedef void (SWIGSTDCALL* CSharpExceptionCallback_t)(const char *, int);
  CSharpExceptionCallback_t customExceptionCallback = NULL;

  extern "C" SWIGEXPORT
  void SWIGSTDCALL CustomExceptionRegisterCallback(CSharpExceptionCallback_t customCallback) {
    customExceptionCallback = customCallback;
  }

  // Note that SWIG detects any method calls named starting with
  // SWIG_CSharpSetPendingException for warning 845
  static void SWIG_CSharpSetPendingExceptionCustom(const char *msg, int type) {
    customExceptionCallback(msg, type);
  }
  %}

%pragma(csharp) imclasscode=%{
  class CustomExceptionHelper {
    // C# delegate for the C/C++ customExceptionCallback
    public delegate void CustomExceptionDelegate(string message, int type);
    static CustomExceptionDelegate customDelegate =
    new CustomExceptionDelegate(SetPendingCustomException);

    [DllImport("$dllimport", EntryPoint="CustomExceptionRegisterCallback")]
    public static extern
    void CustomExceptionRegisterCallback(CustomExceptionDelegate customCallback);

    static void SetPendingCustomException(string message, int type) {
      if (type == 0)
      SWIGPendingException.Set(new SedConstructorException(message));
      else 
      SWIGPendingException.Set(new XMLConstructorException(message));
    }

    static CustomExceptionHelper() {
      CustomExceptionRegisterCallback(customDelegate);
    }
  }

  // The following pragma's disable the compiler warning that the variable is
  // never used.  Don't remove the actual code, though, or you will get 
  // compile-time errors.

#pragma warning disable 0414
  static CustomExceptionHelper exceptionHelper = new CustomExceptionHelper();
#pragma warning restore 0414
  %}


%define SEDMLCONSTRUCTOR_EXCEPTION(SBASE_CLASS_NAME)
%exception SBASE_CLASS_NAME
%{
  try {
    $action
  }
  catch (const SBMLConstructorException &e) {
    SWIG_CSharpSetPendingExceptionCustom(e.what(),0);
  }
  catch (const SedConstructorException &e) {
    SWIG_CSharpSetPendingExceptionCustom(e.what(),0);
  }
  catch (const NUMLConstructorException &e) {
    SWIG_CSharpSetPendingExceptionCustom(e.what(),0);
  }
  catch (const XMLConstructorException &e) {
    SWIG_CSharpSetPendingExceptionCustom(e.what(),0);
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
* takeover ownership
*
* - void SedListOf::appendAndOwn(SedBase* item)
*/
%typemap(csin) SedBase*       item "SedBase.getCPtrAndDisown($csinput)";
%typemap(csin) const SedBase* item "SedBase.getCPtr($csinput)";

/**
* takeover ownership
*
* - void ASTNode::addChild (ASTNode* child)
* - void ASTNode::prependChild (ASTNode* child)
*/
%typemap(csin) ASTNode*       child "ASTNode.getCPtrAndDisown($csinput)";
%typemap(csin) const ASTNode* child "ASTNode.getCPtr($csinput)";

/**
* takeover ownership
*
* - void ASTNode::insertChild  (unsigned int n, ASTNode* newChild)
* - void ASTNode::replaceChild (unsigned int n, ASTNode* newChild)
*/
%typemap(csin) ASTNode*       newChild "ASTNode.getCPtrAndDisown($csinput)";
%typemap(csin) const ASTNode* newChild "ASTNode.getCPtr($csinput)";

/**
* takeover ownership
*
* - void ASTNode::addSemanticsAnnotation (XMLNode* sAnnotation);
*/
%typemap(csin) XMLNode*       sAnnotation "XMLNode.getCPtrAndDisown($csinput)";
%typemap(csin) const XMLNode* sAnnotation "XMLNode.getCPtr($csinput)";


/**
* Of course, there are some exceptions to the above rule.  These typemaps
* cover the following functions:
*
*  - writeSEDML()
*  - writeSEDMLToString()
*  - writeMathML()
*  - writeMathMLToString()
*
* Which take either an SedConstructorException or MathMLDocument as input.
*/
%typemap(csin) SedConstructorException   * "SedConstructorException.getCPtr($csinput)";
%typemap(csin) MathMLDocument * "MathMLDocument.getCPtr($csinput)";



%typemap(cstype) std::ostream& "OStream"
%typemap(csin) std::ostream& "SWIGTYPE_p_std__ostream.getCPtr($csinput.get_ostream())";


//////////////////////////////////////////////////////////////////////
//
// directives for converting Unicode <-> UTF8 in Windows
//
//////////////////////////////////////////////////////////////////////

#ifdef SWIGWIN

%typemap(ctype) std::string        "wchar_t*"
%typemap(ctype) std::string&       "wchar_t*"
%typemap(ctype) const std::string& "wchar_t*"
%typemap(ctype) std::string*       "wchar_t*"
%typemap(ctype) const std::string* "wchar_t*"
%typemap(ctype) char*              "wchar_t*"
%typemap(ctype) const char*        "wchar_t*"


//
// Unicode -> UTF8 (std::string&, const std::string&)
// (argument variable)
//
%typemap("in") std::string&, const std::string&  (std::string arg_str) {
  char*  mbstr = convertUnicodeToUTF8($input);
  if (!mbstr) return $null;

  arg_str.assign(mbstr);
  $1 = &arg_str;
  delete[] mbstr;
}


//
// UTF8 -> Unicode (std::string&, const std::string&) 
// (return variable)
//
%typemap("out") std::string&, const std::string& {
  $result = convertUTF8ToUnicode(($1)->c_str());
  wchar_t* unistr = convertUTF8ToUnicode(($1)->c_str());
  $result = (wchar_t*) SWIG_csharp_wstring_callback((const wchar_t*)unistr);
  delete[] unistr;
}


//
// Unicode -> UTF8 (std::string)
// (argument variable)
//
%typemap("in") std::string {
  char*  mbstr = convertUnicodeToUTF8($input);
  (&$1)->assign(mbstr);
  delete[] mbstr;
}


//
// UTF8 -> Unicode (std::string)
// (return variable)
//
%typemap("out") std::string {
  $result = convertUTF8ToUnicode( $1.c_str() );
  wchar_t* unistr = convertUTF8ToUnicode( $1.c_str() );
  $result = (wchar_t*) SWIG_csharp_wstring_callback((const wchar_t*)unistr);
  delete[] unistr;
}


//
// Unicode -> UTF8 (char*, const char*)
// (argument variable)
//
%typemap("in")  char*, const char* {
  if ($input)
  {
    $1 = convertUnicodeToUTF8($input);
    if (!$1) return $null;
  }
}

%typemap("freearg")  char*, const char* {
  delete[] $1;
}


//
// UTF8 -> Unicode (char*, const char*)
// (returned variable)
//
%typemap("out")  char*, const char* {
  $result = convertUTF8ToUnicode( $1 );
  wchar_t* unistr = convertUTF8ToUnicode( $1 );
  $result = (wchar_t*) SWIG_csharp_wstring_callback((const wchar_t*)unistr);
  delete[] unistr;
}


//
//  A string for filename should be encoded by ANSI CP not by UTF-8 
//  because file i/o functions used in libSEDML requires the ANSI CP 
//  encoded string for a given filename.
//  
//  1) SedReader::readSEDML(const std::string& filename)
//  2) readSEDML(const char* filename)
//  3) SedWriter::writeSEDML(SedConstructorException*, const std::string& filename)
//  4) writeSEDML(SedConstructorException*, const char* filename)
//


//
// Unicode -> ANSI CP (for const std::string& filename)
//
%typemap("in") const std::string& filename (std::string arg_str) {
  char*  mbstr = convertUnicodeToACP($input);
  if (!mbstr) return $null;

  arg_str.assign(mbstr);
  $1 = &arg_str;
  delete[] mbstr;
}


//
// Unicode -> ANSI CP (for const char* filename)
//
%typemap("in")  const char* filename{
  if ($input)
  {
    $1 = convertUnicodeToACP($input);
    if (!$1) return $null;
  }
}

#endif //SWIGWIN

///////////////////////////////////////////////////////////////////////////

%include "OStream.h"

%{
#include "OStream.cpp"
  %}

%pragma(csharp) modulecode =
%{
  public static readonly OStream cout = new OStream(OStream.COUT); 
  public static readonly OStream cerr = new OStream(OStream.CERR); 
  public static readonly OStream clog = new OStream(OStream.CLOG); 
  %}


/**
*  Wraps the following functions by using the corresponding
*  ListWrapper<TYPENAME> class.
*/

%define LIST_WRAPPER(_FNAME_,_TYPENAME_)
%typemap(cstype)  List* _FNAME_ %{ _TYPENAME_ ## List %}
%typemap(csout) List* _FNAME_ 
{ 
  IntPtr cPtr = $imcall;
  return (cPtr == IntPtr.Zero) ? null : new _TYPENAME_ ## List(cPtr, true);
}
%typemap(out) List* _FNAME_ 
{
  ListWrapper<_TYPENAME_> *listw = ($1 != 0) ? new ListWrapper<_TYPENAME_>($1) : 0;  
  $result = (void*)listw;
}
%enddef

LIST_WRAPPER(SedNamespaces::getSupportedNamespaces,SedNamespaces)


