/**
 * @file    local-normal.i
 * @brief   PERL-specific SWIG directives for wrapping libSEDML API
 * @author  Ben Bornstein
 * @author  Ben Kovitz
 * @author  Akiya Jouraku
 * @author  Frank Bergmann
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 *
 * Copyright (c) 2013-2016, Frank T. Bergmann
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ------------------------------------------------------------------------ -->
 */


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


/**
 * Wraps standard output streams
 */

%include "std_string.i"

%{
#include <iostream>
#include <sstream>
%}

%rename(COUT) cout;
%rename(CERR) cerr;
%rename(CLOG) clog;

namespace std
{
%immutable;
extern std::ostream cout;
extern std::ostream cerr;
extern std::ostream clog;
%mutable;
}

/**
 * Wraps std::ostream by implementing two simple wrapper classes.
 *
 * 1) OStream wraps std::cout, std::cerr, and std::clog.
 *    The following public final static variables are provied in
 *    libsbml class like in C++.
 *
 *    1. public final static OStream cout;
 *    2. public final static OStream cerr;
 *    3. public final static OStream clog;
 *
 * 2) OStringStream (derived class of OStream) wraps std::ostringstream.
 *
 * These wrapper classes provide only the minimum functions.
 *
 * (sample code) -----------------------------------------------------
 *
 * 1. wraps std::cout
 *
 *    my $xos = new LibSEDML::XMLOutputStream($LibSEDML::COUT);
 *
 * 2. wraps std::cerr
 *
 *    my $rd = new LibSEDML::SEDMLReader
 *    my $d = $rd->readSEDML("foo.xml");
 *    if ( $d->getNumErrors() > 0) {
 *       $d->printErrors($LibSEDML::CERR);
 *    }
 * 3. wraps std::ostringstream 
 *
 *    my $oss = new LibSEDML::OStringStream();
 *    my $xos = new XMLOutputStream($oss->get_ostream());
 *    my $p   = new LibSEDML::Parameter("p", 3.31);
 *    $p->write($xos);
 *    $oss->endl();
 *    print $oss->str();
 *
 */

%include "OStream.h"

%{
#include "OStream.cpp"
%}

%include list_of_fix.i
%include list_get_fix.i


/**
 * Convert objects into the most specific type possible.
 */
%typemap(out) SedBase*, SedSimulation*, SedAbstractTask*, SedTask*, SedOutput*, SedChange*, SedRange*, SedAbstractCurve*
{
  ST(argvi) = SWIG_NewPointerObj(SWIG_as_voidptr($1), GetDowncastSwigType($1),
                                 $owner | %newpointer_flags);
  argvi++;  
}


/**
 * typemap to handle functions which take a FILE*
 */
%typemap(in) FILE * {
  if (SvOK($input)) /* check for undef */
        $1 = PerlIO_findFILE(IoIFP(sv_2io($input)));
  else  $1 = NULL;
}

/**
 * By default, returned boolean false (C++) is converted to "" (Perl) in 
 * SWIG 1.3.31.
 * The following typemap converts returned boolean value to 0 (false) or 
 * 1 (true) like C/C++ for compatibility.
 */
%typemap(out) bool
{
   ST(argvi) = sv_newmortal();
   sv_setiv(ST(argvi++), (IV) $1);
}

/**
 * The features directives below override the default SWIG generated
 * code for certain methods.  The idea is to tell SWIG to disown the
 * passed-in object.  The containing object will takeover ownership
 * and delete the object as appropriate.  This avoids a deadly
 * double-delete which can result in a segmentation fault.  For
 * example, each SBase that is appended to a ListOf is subsequently
 * owned by that ListOf.
 */

// ----------------------------------------------------------------------
// ListOf
// ----------------------------------------------------------------------

%feature("shadow") ListOf::appendAndOwn(SBase*)
%{
  sub appendAndOwn {
    $_[1]->DISOWN() if defined $_[1];
    return LibSBMLc::ListOf_appendAndOwn(@_);
  }
%}

// ----------------------------------------------------------------------
// ASTNode
// ----------------------------------------------------------------------

%feature("shadow") ASTNode::addChild(ASTNode*)
%{
  sub addChild {
    $_[1]->DISOWN() if defined $_[1];
    return LibSBMLc::ASTNode_addChild(@_);
  }
%}

%feature("shadow") ASTNode::prependChild(ASTNode*)
%{
  sub prependChild {
    $_[1]->DISOWN() if defined $_[1];
    return LibSBMLc::ASTNode_prependChild(@_);
  }
%}

%feature("shadow") ASTNode::insertChild(unsigned int, ASTNode*)
%{
  sub insertChild {
    $_[2]->DISOWN() if defined $_[2];
    return LibSBMLc::ASTNode_insertChild(@_);
  }
%}

%feature("shadow") ASTNode::replaceChild(unsigned int, ASTNode*)
%{
  sub replaceChild {
    $_[2]->DISOWN() if defined $_[2];
    return LibSBMLc::ASTNode_replaceChild(@_);
  }
%}

%feature("shadow") ASTNode::addSemanticsAnnotation(XMLNode*)
%{
  sub addSemanticsAnnotation {
    $_[1]->DISOWN() if defined $_[1];
    return LibSBMLc::ASTNode_addSemanticsAnnotation(@_);
  }
%}

/**
 * Wraps the SedConstructorException
 *
 * The SedConstructorException (C++ class) is converted into
 * Perl exception.
 *
 * For example, the exception can be catched in Perl as follows:
 *
 *  -----------------------------------------------------------------
 *  eval
 *  {
 *    $m = new LibSEDML::Model($level,$version);
 *  };
 *  if ($@) 
 *  {
 *    warn $@; # print error message
 *    $m = new LibSEDML::Model(2,4);
 *  }
 *  -----------------------------------------------------------------
 */

%define SEDMLCONSTRUCTOR_EXCEPTION(SBASE_CLASS_NAME)
%exception SBASE_CLASS_NAME {
  try {
    $action
  }  
  catch (XMLConstructorException &e){
    croak("%s", e.what());
  }
  catch (SBMLConstructorException &e){
    croak("%s", e.what());
  }
  catch (SedConstructorException &e){
    croak("%s", e.what());
  }
  catch (NUMLConstructorException &e){
    croak("%s", e.what());
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
