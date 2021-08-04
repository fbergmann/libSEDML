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



/**
 * Turn on (minimal) Python docstrings and then append our own.
 */
%feature("autodoc", "1");


%trackobjects;


/**
 *  Wraps std::cout, std::cerr, std::clog, std::ostream, and std::ostringstream, 
 *
 * (sample code) -----------------------------------------------------
 *
 * 1. wraps std::cout
 *
 *    xos = libsedml.XMLOutputStream(libsedml.cout)
 *
 * 2. wraps std::cerr
 *
 *    d = libsedml.readSedML("foo.xml")
 *    if d.getNumErrors() > 0 :
 *       d.printErrors(libsedml.cerr)
 *    
 *
 * 3. wraps std::ostringstream
 *
 *    oss = libsedml.ostringstream()
 *    xos = libsedml.XMLOutputStream(oss)
 *    ...
 *    libsedml.endl(oss)
 *    s = oss.str()
 * 
 */

// ignores C++ specific methods in std::string.
%ignore std::basic_string<char>::begin;
%ignore std::basic_string<char>::end;
%ignore std::basic_string<char>::rbegin;
%ignore std::basic_string<char>::rend;
%ignore std::basic_string<char>::get_allocator;
%ignore std::basic_string<char>::capacity;
%ignore std::basic_string<char>::reserve;

%include <std_alloc.i>
%include <std_basic_string.i>
%include <std_string.i>

#pragma SWIG nowarn=509
%warnfilter(401) basic_ios<char>;

namespace std
{
  // Template class basic ios
  template<typename _CharT, typename _Traits = char_traits<_CharT> >
  class basic_ios : public ios_base {};

  // Template class basic_ostream
  template<typename _CharT, typename _Traits = char_traits<_CharT> >
  class basic_ostream : virtual public basic_ios<_CharT, _Traits> 
  {
    public:
      explicit
      basic_ostream(std::basic_streambuf<_CharT, _Traits>* __sb);
      virtual 
      ~basic_ostream();
  };

  // Template class basic_ostringstream
  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
  class basic_ostringstream : public basic_ostream<_CharT, _Traits>
  {
    public:
      explicit
      basic_ostringstream(std::ios_base::openmode __mode = std::ios_base::out);
      ~basic_ostringstream();

      basic_string<_CharT, _Traits, _Alloc> 
      str() const;

      void
      str(const basic_string<_CharT, _Traits, _Alloc>& __s);
  };


  /**
   * Insert a newline character into the given C++ stream.
   *
   * This is a wrapper around the underlying C++ OStream method
   * <code>endl</code>.  It inserts a newline into the stream
   * passed as argument.  Additionally, it flushes buffered
   * streams.
   */
  template<typename _CharT, typename _Traits = char_traits<_CharT> >
  basic_ostream<_CharT, _Traits>& 
  endl(basic_ostream<_CharT, _Traits>&);


  /**
   * Flush the given C++ stream.
   *
   * This is a wrapper around the underlying C++ OStream method
   * <code>flush</code>.  It flush any pending output in the stream 
   * passed as argument.  
   */
  template<typename _CharT, typename _Traits = char_traits<_CharT> >
  basic_ostream<_CharT, _Traits>& 
  flush(basic_ostream<_CharT, _Traits>&);
}

namespace std
{
  /**
   *  std::ostream and std::ostringstream 
   *  (std::ios is not wrapped)
   */
  typedef basic_ios<char>           ios;
  typedef basic_ostream<char>       ostream ;
  typedef basic_ostringstream<char> ostringstream ;

  %template(ostream)       basic_ostream<char>;
  %template(ostringstream) basic_ostringstream<char>;

  /**
   *  output manipulators
   */
  %template(endl)  endl<char, char_traits<char> >;
  %template(flush) flush<char, char_traits<char> >;

  /**
   *  std::cout, std::cerr, and std::clog.
   */
  %immutable;
  extern std::ostream cout;
  extern std::ostream cerr;
  extern std::ostream clog;
  %mutable;
}


/**
 * Convert an SedBase object to a string.
 *
 %extend SedBase
 {
   char* __str__(void)
   {
     return strdup(self->toSed().c_str());
   }
 }

%mixin SedListOf "Enumerable";

/**
 * Allows SedListOf objects:
 *
 *   - To be indexed and sliced, e.g. lst[0].
 */
%extend SedListOf
{
  int __len__()
  {
    return self->size();
  }
  
  SedBase* __getitem__(int i)
  {
    return self->get(fixNegativeIndex(i,self));
  }
  
  void each(void)
  {
    unsigned int i;
    for(i=0;i<self->size();i++){
      rb_yield(SWIG_NewPointerObj(self->get(i),
                                  GetDowncastSwigType(self->get(i)), 0));
    }
  }
}



/**
 * Convert objects into the most specific type possible.
 */
%typemap(out) SedBase*, SedSimulation*, SedAbstractTask*, SedTask*, SedOutput*, SedChange*, SedRange*, SedAbstractCurve*, SedVariable*
{
  $result = SWIG_NewPointerObj(SWIG_as_voidptr($1), GetDowncastSwigType($1),
                               $owner | %newpointer_flags);
}


/*
 * SWIG-generated wrapper code wrongly invokes 
 * XMLOutputStream::writeAttribute(.., const unsigned int& value) instead of
 * XMLOutputStream::writeAttribute(.., const bool& value) even if the writeAttribute 
 * function invoked with a bool value (True or False) in Python code.
 * It seems that a bool value could be casted to unsigned int, int, or long value 
 * in SWIG-generated internal type check code when these types are overloaded in the
 * wrapped function.
 *
 * To avoid this problem, XMLOutputStream::writeAttribute(.., const bool& value)
 * is internally wrapped as XMLOutputStream::writeAttributeBool(.., const bool&) 
 * and this function is properly invoked when the writeAttribute function is invoked
 * with a bool value in Python code.
 */

%extend XMLOutputStream
{
  void writeAttributeBool(const std::string& name, const bool& value)
  {
    $self->writeAttribute(name, value);
  }

  void writeAttributeBool(const XMLTriple& name, const bool& value)
  {
    $self->writeAttribute(name, value);
  }
}


/**
 * The features directives below override the default SWIG generated
 * code for certain methods.  The idea is to tell SWIG to disown the
 * passed-in object.  The containing object will takeover ownership
 * and delete the object as appropriate.  This avoids a deadly
 * double-delete which can result in a segmentation fault.  For
 * example, each SedBase that is appended to a SedListOf is subsequently
 * owned by that SedListOf.
 */

%define TAKEOVER_OWNERSHIP(METHOD_NAME,ARG)
%feature("pythonprepend")
METHOD_NAME
%{
        if ARG is not None: ARG.thisown = 0
%}
%enddef

// ----------------------------------------------------------------------
// SedListOf
// ----------------------------------------------------------------------

TAKEOVER_OWNERSHIP(SedListOf::appendAndOwn(SedBase*),item)

// ----------------------------------------------------------------------
// ASTNode
// ----------------------------------------------------------------------

TAKEOVER_OWNERSHIP(ASTNode::addChild(ASTNode*),disownedChild)
TAKEOVER_OWNERSHIP(ASTNode::prependChild(ASTNode*),disownedChild)
TAKEOVER_OWNERSHIP(ASTNode::insertChild(unsigned int, ASTNode*),disownedChild)
TAKEOVER_OWNERSHIP(ASTNode::replaceChild(unsigned int, ASTNode*),disownedChild)
TAKEOVER_OWNERSHIP(ASTNode::addSemanticsAnnotation(XMLNode*),disownedAnnotation)

/**
 *
 * Wraps the SedConstructorException class (C++ exception defined by libSEDML) 
 * as the ValueError class (Python built-in exception).
 *
 * For example, the exception can be catched in Python code as follows:
 *
 * --------------------------------------
 *  try:
 *    s = libsedml.CompartmentType(level,version)
 *  except ValueError, inst:
 *    errmsg = inst.args[0]
 * --------------------------------------
 */

  %exceptionclass SedConstructorException;
  %exceptionclass SBMLConstructorException;
  %exceptionclass XMLConstructorException;
  %exceptionclass NUMLConstructorException;
  
  %define SEDMLCONSTRUCTOR_EXCEPTION(CLASS_NAME)
  %exception CLASS_NAME{
    try {
      $action
    }
    catch (const SedConstructorException &e){
      static VALUE cpperror = rb_define_class("SedConstructorException", rb_eArgError);
      rb_raise(cpperror, "%s", e.what());
    }
    catch (const SBMLConstructorException &e){
      static VALUE cpperror = rb_define_class("SBMLConstructorException", rb_eArgError);
      rb_raise(cpperror, "%s", e.what());
    }
    catch (const XMLConstructorException &e){
      static VALUE cpperror = rb_define_class("XMLConstructorException", rb_eArgError);
      rb_raise(cpperror, "%s", e.what());
    }
    catch (const NUMLConstructorException &e){
      static VALUE cpperror = rb_define_class("NUMLConstructorException", rb_eArgError);
      rb_raise(cpperror, "%s", e.what());
    }
  }
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
   *  Wraps the following functions by using the corresponding
   *  ListWrapper<TYPENAME> class.
   *
   *  - List* ModelHistory::getListCreators()
   *  - List* ModelHistory::getListModifiedDates()
   *  - List* SedBase::getCVTerms()
   *  - List* SedNamespaces::getSupportedNamespaces()
   *
   *  ListWrapper<TYPENAME> class is wrapped as ListTYPENAMEs class.
   *  So, the above functions are wrapped as follows:
   *
   *  - ModelCreatorList ModelHistory.getListCreators()
   *  - DateList         ModelHistory.getListModifiedDates()
   *  - CVTermList       SedBase.getCVTerms()
   *  - SedNamespacesList SedNamespaces::getSupportedNamespaces()
   *
   */
  
  %typemap(out) List* SedNamespaces::getSupportedNamespaces
  {
    ListWrapper<SedNamespaces> *listw = ($1 != 0) ? new ListWrapper<SedNamespaces>($1) : 0;
    $result = SWIG_NewPointerObj(SWIG_as_voidptr(listw),
#if SWIG_VERSION > 0x010333
                                 SWIGTYPE_p_ListWrapperT_SedNamespaces_t,
#else
                                 SWIGTYPE_p_ListWrapperTSedNamespaces_t,
#endif
                                 SWIG_POINTER_OWN |  0 );
  }
