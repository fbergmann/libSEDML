/**
* @file    local.i
* @brief   cs-specific SWIG directives for wrapping libSEDML API this file 
*          has been adapted from the SWIG java bindings written by 
* 	    Ben Bornstein and Akiya Jouraku
* @author  Frank Bergmann (fbergman@u.washington.edu)
* @author  Akiya Jouraku
*
* <!--------------------------------------------------------------------------
* This file is part of libSEDML.  Please visit http://sedml.org for more
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
* and also available online as http://sedml.org/software/libsedml/license.html
* ---------------------------------------------------------------------- -->*/



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

		case (int) libsedml.SEDML_CHANGE_CHANGEXML:
			return new SedChangeXML(cPtr, owner);
			
		case (int) libsedml.SEDML_RANGE:
			return new SedRange(cPtr, owner);

		case (int) libsedml.SEDML_RANGE_FUNCTIONALRANGE:
			return new SedFunctionalRange(cPtr, owner);

		case (int) libsedml.SEDML_RANGE_UNIFORMRANGE:
			return new SedUniformRange(cPtr, owner);

		case (int) libsedml.SEDML_RANGE_VECTORRANGE:
			return new SedVectorRange(cPtr, owner);

		case (int) libsedml.SEDML_CHANGE_ATTRIBUTE:
			return new SedChangeAttribute(cPtr, owner);
			
		case (int) libsedml.SEDML_CHANGE_REMOVEXML:
			return new SedRemoveXML(cPtr, owner);
			
		case (int) libsedml.SEDML_CHANGE_COMPUTECHANGE:
			return new SedComputeChange(cPtr, owner);
			
		case (int) libsedml.SEDML_DATAGENERATOR:
			return new SedDataGenerator(cPtr, owner);
			
		case (int) libsedml.SEDML_VARIABLE:
			return new SedVariable(cPtr, owner);
			
		case (int) libsedml.SEDML_PARAMETER:
			return new SedParameter(cPtr, owner);
			
		case (int) libsedml.SEDML_TASK:
			return new SedTask(cPtr, owner);
			
		case (int) libsedml.SEDML_OUTPUT_DATASET:
			return new SedDataSet(cPtr, owner);
			
		case (int) libsedml.SEDML_OUTPUT_CURVE:
			return new SedCurve(cPtr, owner);
			
		case (int) libsedml.SEDML_OUTPUT_SURFACE:
			return new SedSurface(cPtr, owner);
			
		case (int) libsedml.SEDML_OUTPUT_REPORT:
			return new SedReport(cPtr, owner);
			
		case (int) libsedml.SEDML_OUTPUT_PLOT2D:
			return new SedPlot2D(cPtr, owner);
			
		case (int) libsedml.SEDML_OUTPUT_PLOT3D:
			return new SedPlot3D(cPtr, owner);
			
		case (int) libsedml.SEDML_SIMULATION_ALGORITHM:
			return new SedAlgorithm(cPtr, owner);

			
		case (int) libsedml.SEDML_SIMULATION_ALGORITHM_PARAMETER:
			return new SedAlgorithmParameter(cPtr, owner);
			
		case (int) libsedml.SEDML_SIMULATION:
			return new SedSimulation(cPtr, owner);
			
		case (int) libsedml.SEDML_SIMULATION_UNIFORMTIMECOURSE:
			return new SedUniformTimeCourse(cPtr, owner);
			
		case (int) libsedml.SEDML_SIMULATION_ONESTEP:
			return new SedOneStep(cPtr, owner);
			
		case (int) libsedml.SEDML_SIMULATION_STEADYSTATE:
			return new SedSteadyState(cPtr, owner);
			
			
		case (int) libsedml.SEDML_TASK_SETVALUE:
			return new SedSetValue(cPtr, owner);
			
		case (int) libsedml.SEDML_TASK_SUBTASK:
			return new SedSubTask(cPtr, owner);

		case (int) libsedml.SEDML_TASK_REPEATEDTASK:
			return new SedRepeatedTask(cPtr, owner);
			
		case (int) libsedml.SEDML_LIST_OF:
			String name = sb.getElementName();
			if(name.equals("listOf"))
			{
				return new SedListOf(cPtr, owner);
			}
			else if(name.equals("listOfModels"))
			{
				return new SedListOfModels(cPtr, owner);
			}
			else if(name.equals("listOfChanges"))
			{
				SedListOf temp = new SedListOf(cPtr, false);
				if (temp.getItemTypeCode() ==  (int) libsedml.SEDML_TASK_SETVALUE)
				return new SedListOfTaskChanges(cPtr, owner);
				return new SedListOfChanges(cPtr, owner);
			}
			else if(name.equals("listOfSimulations"))
			{
				return new SedListOfSimulations(cPtr, owner);
			}
			else if(name.equals("listOfTasks"))
			{
				return new SedListOfTasks(cPtr, owner);
			}
			else if(name.equals("listOfDataGenerators"))
			{
				return new SedListOfDataGenerators(cPtr, owner);
			}
			else if(name.equals("listOfOutputs"))
			{
				return new SedListOfOutputs(cPtr, owner);
			}
			else if(name.equals("listOfCurves"))
			{
				return new SedListOfCurves(cPtr, owner);
			}
			else if(name.equals("listOfSurfaces"))
			{
				return new SedListOfSurfaces(cPtr, owner);
			}
			else if(name.equals("listOfDataSets"))
			{
				return new SedListOfDataSets(cPtr, owner);
			}
			else if(name.equals("listOfParameters"))
			{
				return new SedListOfParameters(cPtr, owner);
			}
			else if(name.equals("listOfVariables"))
			{
				return new SedListOfVariables(cPtr, owner);
			}
			
			else if(name == "listOfSubTasks")
			{
				return new SedListOfSubTasks(cPtr, owner);
			}
			
			else if(name == "listOfRanges")
			{
				return new SedListOfRanges(cPtr, owner);
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
COVARIANT_RTYPE_CLONE(SedConstructorException)
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


COVARIANT_RTYPE_CLONE(SedDocument)
COVARIANT_RTYPE_CLONE(SedModel)
COVARIANT_RTYPE_CLONE(SedChange)
COVARIANT_RTYPE_CLONE(SedChangeAttribute)
COVARIANT_RTYPE_CLONE(SedRemoveXML)
COVARIANT_RTYPE_CLONE(SedComputeChange)
COVARIANT_RTYPE_CLONE(SedDataGenerator)
COVARIANT_RTYPE_CLONE(SedVariable)
COVARIANT_RTYPE_CLONE(SedParameter)
COVARIANT_RTYPE_CLONE(SedTask)
COVARIANT_RTYPE_CLONE(SedOutput)
COVARIANT_RTYPE_CLONE(SedDataSet)
COVARIANT_RTYPE_CLONE(SedCurve)
COVARIANT_RTYPE_CLONE(SedSurface)
COVARIANT_RTYPE_CLONE(SedReport)
COVARIANT_RTYPE_CLONE(SedPlot2D)
COVARIANT_RTYPE_CLONE(SedPlot3D)
COVARIANT_RTYPE_CLONE(SedSimulation)
COVARIANT_RTYPE_CLONE(SedUniformTimecourse)
COVARIANT_RTYPE_CLONE(SedAlgorithm)
COVARIANT_RTYPE_CLONE(SedListOf)
COVARIANT_RTYPE_CLONE(SedConstructorException)
COVARIANT_RTYPE_CLONE(SedNamespaces)
COVARIANT_RTYPE_CLONE(SedListOfModels)
COVARIANT_RTYPE_CLONE(SedListOfParameters)
COVARIANT_RTYPE_CLONE(SedListOfVariables)
COVARIANT_RTYPE_CLONE(SedListOfOutputs)
COVARIANT_RTYPE_CLONE(SedListOfDataGenerators)
COVARIANT_RTYPE_CLONE(SedListOfSimulations)
COVARIANT_RTYPE_CLONE(SedListOfTasks)
COVARIANT_RTYPE_CLONE(SedListOfDataSets)
COVARIANT_RTYPE_CLONE(SedListOfCurves)
COVARIANT_RTYPE_CLONE(SedListOfSurfaces)


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



%define COVARIANT_GETID(_CNAME_)
%typemap(cstype) string   _CNAME_ ## ::getId  "_CNAME_"
%csmethodmodifiers  _CNAME_ ## ::getId  "public new"
%enddef



/**
* Wraps the SedConstructorException
*
* The SedConstructorException (C++ class) is wrapped as the 
* SEDMLConsturctorException (C# class) which is derived from
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
	catch (const SedConstructorException &e) {
		SWIG_CSharpSetPendingExceptionCustom(e.what(),0);
	}
	%}
%enddef


SEDMLCONSTRUCTOR_EXCEPTION(SedDocument)
SEDMLCONSTRUCTOR_EXCEPTION(SedModel)
SEDMLCONSTRUCTOR_EXCEPTION(SedChange)
SEDMLCONSTRUCTOR_EXCEPTION(SedChangeAttribute)
SEDMLCONSTRUCTOR_EXCEPTION(SedRemoveXML)
SEDMLCONSTRUCTOR_EXCEPTION(SedComputeChange)
SEDMLCONSTRUCTOR_EXCEPTION(SedDataGenerator)
SEDMLCONSTRUCTOR_EXCEPTION(SedVariable)
SEDMLCONSTRUCTOR_EXCEPTION(SedParameter)
SEDMLCONSTRUCTOR_EXCEPTION(SedTask)
SEDMLCONSTRUCTOR_EXCEPTION(SedOutput)
SEDMLCONSTRUCTOR_EXCEPTION(SedDataSet)
SEDMLCONSTRUCTOR_EXCEPTION(SedCurve)
SEDMLCONSTRUCTOR_EXCEPTION(SedSurface)
SEDMLCONSTRUCTOR_EXCEPTION(SedReport)
SEDMLCONSTRUCTOR_EXCEPTION(SedPlot2D)
SEDMLCONSTRUCTOR_EXCEPTION(SedPlot3D)
SEDMLCONSTRUCTOR_EXCEPTION(SedSimulation)
SEDMLCONSTRUCTOR_EXCEPTION(SedUniformTimecourse)
SEDMLCONSTRUCTOR_EXCEPTION(SedAlgorithm)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOf)
SEDMLCONSTRUCTOR_EXCEPTION(SedConstructorException)
SEDMLCONSTRUCTOR_EXCEPTION(SedNamespaces)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfModels)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfParameters)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfVariables)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfOutputs)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfDataGenerators)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfSimulations)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfTasks)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfDataSets)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfCurves)
SEDMLCONSTRUCTOR_EXCEPTION(SedListOfSurfaces)




%define XMLCONSTRUCTOR_EXCEPTION(SBASE_CLASS_NAME)
%exception SBASE_CLASS_NAME
%{
	try {
		$action
	}
	catch (const XMLConstructorException &e) {
		SWIG_CSharpSetPendingExceptionCustom(e.what(),1);
	}
	%}
%enddef


XMLCONSTRUCTOR_EXCEPTION(XMLAttributes)
XMLCONSTRUCTOR_EXCEPTION(XMLError)
XMLCONSTRUCTOR_EXCEPTION(XMLNamespaces)
XMLCONSTRUCTOR_EXCEPTION(XMLNode)
XMLCONSTRUCTOR_EXCEPTION(XMLOutputStream)
XMLCONSTRUCTOR_EXCEPTION(XMLToken)
XMLCONSTRUCTOR_EXCEPTION(XMLTripple)


/**
* takeover ownership
*
* - void ListOf::appendAndOwn(SedBase* item)
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
*
*  - List* ModelHistory::getListCreators()
*  - List* ModelHistory::getListModifiedDates()
*  - List* SedBase::getCVTerms()
*  - List* SedNamespaces::getSupportedNamespaces()
*
*  ListWrapper<TYPENAME> class is wrapped as TYPENAMEList class.
*  So, the above functions are wrapped as follows:
*
*  - ModelCreatorList ModelHistory.getListCreators()
*  - DateList         ModelHistory.getListModifiedDates()
*  - CVTermList       SedBase.getCVTerms()
*  - SedNamespacesList  SedNamespaces.getSupportedNamespaces()
*
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

LIST_WRAPPER(SedBase::getListOfAllElements,SedBase)
LIST_WRAPPER(SedNamespaces::getSupportedNamespaces,SedNamespaces)


