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

%include "local-contrib.i"


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
  %pythoncode
  {
    def __str__(self):
      """
      Return a string representation of this object.

      Note that the string will not be a complete Sed document.
      """

      return self.toSed()
  }
}*/


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

  %pythoncode
  {
    def __getitem__(self, key):

      try:
         keyIsSlice = isinstance(key, slice)
      except:
         keyIsSlice = 0

      if keyIsSlice:
        start = key.start
        if start is None:
          start = 0
        stop = key.stop
        if stop is None:
          stop = self.size()
        return [self[i] for i in range(
          self._fixNegativeIndex(start), self._fixNegativeIndex(stop)
        )]

      key = self._fixNegativeIndex(key)
      if key < 0 or key >= self.size():
        raise IndexError(key)
      return self.get(key)


    def _fixNegativeIndex(self, index):
      if index < 0:
        return index + self.size()
      else:
        return index


    def __iter__(self):
      for i in range(self.size()):
        yield self[i]


    def __repr__(self):
      return "[" + ", ".join([repr(self[i]) for i in range(len(self))]) + "]"


    def __str__(self):
      return repr(self)
  }
}


%extend SedBase
{
  SedBase* downcast()
  {
    return $self;
  }
}



/**
 * Convert objects into the most specific type possible.
 */

%typemap(directorin) SedBase*
{
  $input = SWIG_NewPointerObj(SWIG_as_voidptr($1), GetDowncastSwigType(const_cast<SedBase*>($1)),
                               $owner | %newpointer_flags);
}

%typemap(out) SedBase*, SedSimulation*, SedAbstractTask*, SedTask*, SedOutput*, SedChange*, SedRange*, SedAbstractCurve*, SedVariable*
{
  $result = SWIG_NewPointerObj(SWIG_as_voidptr($1), GetDowncastSwigType($1),
                               $owner | %newpointer_flags);
}

%typemap(out) NMBase*, NUMLList*, ResultComponent*, Dimension*, DimensionDescription*, CompositeDescription*, CompositeValue*, TupleDescription*, Tuple*, AtomicDescription*, AtomicValue*, OntologyTerm*
{
  $result = SWIG_NewPointerObj(SWIG_as_voidptr($1), GetNumlDowncastSwigType($1),
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

#if SWIG_VERSION > 0x010336
%feature("pythonprepend")
XMLOutputStream::writeAttribute
%{
        if type(args[1]) == type(True): return _libsedml.XMLOutputStream_writeAttributeBool(self, *args)
%}
#else 
%feature("pythonprepend")
XMLOutputStream::writeAttribute
%{
        if type(args[2]) == type(True): return _libsedml.XMLOutputStream_writeAttributeBool(*args)
%}
#endif

/**
 * Add an equality operator to SedBase.  All subclasses of SedBase
 * will inherit this method.
 *
 * The %extend rewrites __cmp__ such that two objects of
 * disimilar type can be compared without throwing a TypeError.  For
 * example: the following will return false and not throw an exception:
 *
 *   c = libsedml.Compartment()
 *   n = 5
 *   c == n
 *
 * For more information, see testEquality() in test/TestPython.py
 */

%define SWIGPYTHON__CMP__(CLASS)
%extend CLASS
{
  %pythoncode
  {
    def __eq__(self, rhs):
      if ((self is None) and (rhs is None)): return True
      if ((self is None) or  (rhs is None)): return False
      if (hasattr(self, 'this') and hasattr(rhs, 'this')):
        if (self.this == rhs.this): return True
      return False

    def __ne__(self, rhs):
      if ((self is None) and (rhs is None)): return False
      if ((self is None) or  (rhs is None)): return True
      if (hasattr(self, 'this') and hasattr(rhs, 'this')):
        if (self.this == rhs.this): return False
      return True
  }
}
%enddef

SWIGPYTHON__CMP__(SedBase)
SWIGPYTHON__CMP__(SedWriter)
SWIGPYTHON__CMP__(SedReader)
SWIGPYTHON__CMP__(ASTNode)
SWIGPYTHON__CMP__(XMLNamespaces)
SWIGPYTHON__CMP__(SedNamespaces)
SWIGPYTHON__CMP__(XMLAttributes)
SWIGPYTHON__CMP__(XMLToken)
SWIGPYTHON__CMP__(XMLTriple)
SWIGPYTHON__CMP__(XMLError)
SWIGPYTHON__CMP__(XMLErrorLog)
SWIGPYTHON__CMP__(XMLOutputStream)

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

%ignore SedConstructorException;

%define SEDMLCONSTRUCTOR_EXCEPTION(SBASE_CLASS_NAME)
%exception SBASE_CLASS_NAME {
  try {
    $action
  }
  catch (SBMLConstructorException &e) {
    PyErr_SetString(PyExc_ValueError, const_cast<char*>(e.what()));
    return NULL;
  }
  catch (XMLConstructorException &e) {
    PyErr_SetString(PyExc_ValueError, const_cast<char*>(e.what()));
    return NULL;
  }
  catch (SedConstructorException &e) {
    PyErr_SetString(PyExc_ValueError, const_cast<char*>(e.what()));
    return NULL;
  }
  catch (NUMLConstructorException &e) {
    PyErr_SetString(PyExc_ValueError, const_cast<char*>(e.what()));
    return NULL;
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




// ----------------------------------------------------------------------
// SedReader
// ----------------------------------------------------------------------


%pythoncode
%{
import sys
import os.path

# @cond doxygen-libsedml-internal

def conditional_abspath (filename):
  """conditional_abspath (filename) -> filename

  Returns filename with an absolute path prepended, if necessary.
  Some combinations of platforms and underlying XML parsers *require*
  an absolute path to a filename while others do not.  This function
  encapsulates the appropriate logic.  It is used by readSedML() and
  SedReader.readSedML().
  """
  if sys.platform.find('cygwin') != -1:
    return filename
  else:
    return os.path.abspath(filename)

# @endcond
%}


/*
 * I haven't been able to attach the original docstring without
 * copying it here.  A %feature("docstring") directive placed
 * after here won't do it, and neither will moving the pydoc.i
 * file inclusion from the top of this file to the end of this
 * file.  I'm giving up and just copy-pasting the doc string
 * from SedReader.h.  Definitely non-ideal, but I'm at the end
 * of ideas.
 */
%feature("shadow")
SedReader::readSedML(const std::string&)
%{
  def readSedML(*args):
    """
    readSedML(self, string filename) -> SedDocument

    Reads an Sed document from a file.

    This method is identical to readSedMLFromFile().

    If the file named 'filename' does not exist or its content is not
    valid Sed, one or more errors will be logged with the SedDocument
    object returned by this method.  Callers can use the methods on
    SedDocument such as SedDocument.getNumErrors() and
    SedDocument.getError() to get the errors.  The object returned by
    SedDocument.getError() is an SedError object, and it has methods to
    get the error code, category, and severity level of the problem, as
    well as a textual description of the problem.  The possible severity
    levels range from informational messages to fatal errors; see the
    documentation for SedError for more information.

    If the file 'filename' could not be read, the file-reading error will
    appear first.  The error code can provide a clue about what happened.
    For example, a file might be unreadable (either because it does not
    actually exist or because the user does not have the necessary access
    priviledges to read it) or some sort of file operation error may have
    been reported by the underlying operating system.  Callers can check
    for these situations using a program fragment such as the following:

     reader = SedReader()
     doc    = reader.readSedML(filename)

     if doc.getNumErrors() > 0:
       if doc.getError(0).getErrorId() == libsedml.XMLFileUnreadable:
         # Handle case of unreadable file here.
       elif doc.getError(0).getErrorId() == libsedml.XMLFileOperationError:
         # Handle case of other file error here.
       else:
         # Handle other error cases here.

    If the given filename ends with the suffix \".gz\" (for example,
    \"myfile.xml.gz\"), the file is assumed to be compressed in gzip format
    and will be automatically decompressed upon reading.  Similarly, if the
    given filename ends with \".zip\" or \".bz2\", the file is assumed to be
    compressed in zip or bzip2 format (respectively).  Files whose names
    lack these suffixes will be read uncompressed.  Note that if the file
    is in zip format but the archive contains more than one file, only the
    first file in the archive will be read and the rest ignored.

    To read a gzip/zip file, libSEDML needs to be configured and linked with
    the zlib library at compile time.  It also needs to be linked with the
    bzip2 library to read files in bzip2 format.  (Both of these are the
    default configurations for libSEDML.)  Errors about unreadable files
    will be logged if a compressed filename is given and libSEDML was not
    linked with the corresponding required library.

    Parameter 'filename is the name or full pathname of the file to be
    read.

    Returns a pointer to the SedDocument created from the Sed content.

    See also SedError.

    Note:

    LibSEDML versions 2.x and later versions behave differently in
    error handling in several respects.  One difference is how early some
    errors are caught and whether libSEDML continues processing a file in
    the face of some early errors.  In general, libSEDML versions after 2.x
    stop parsing Sed inputs sooner than libSEDML version 2.x in the face
    of XML errors, because the errors may invalidate any further Sed
    content.  For example, a missing XML declaration at the beginning of
    the file was ignored by libSEDML 2.x but in version 3.x and later, it
    will cause libSEDML to stop parsing the rest of the input altogether.
    While this behavior may seem more severe and intolerant, it was
    necessary in order to provide uniform behavior regardless of which
    underlying XML parser (Expat, Xerces, libxml2) is being used by
    libSEDML.  The XML parsers themselves behave differently in their error
    reporting, and sometimes libSEDML has to resort to the lowest common
    denominator.
    """
    args_copy    = list(args)
    args_copy[1] = conditional_abspath(args[1])
    return _libsedml.SedReader_readSedML(*args_copy)
%}

%feature("shadow")
SedReader::readSedMLFromFile(const std::string&)
%{
  def readSedMLFromFile(*args):
    """
    readSedMLFromFile(self, string filename) -> SedDocument

    Reads an Sed document from a file.

    This method is identical to readSedMLFromFile().

    If the file named 'filename' does not exist or its content is not
    valid Sed, one or more errors will be logged with the SedDocument
    object returned by this method.  Callers can use the methods on
    SedDocument such as SedDocument.getNumErrors() and
    SedDocument.getError() to get the errors.  The object returned by
    SedDocument.getError() is an SedError object, and it has methods to
    get the error code, category, and severity level of the problem, as
    well as a textual description of the problem.  The possible severity
    levels range from informational messages to fatal errors; see the
    documentation for SedError for more information.

    If the file 'filename' could not be read, the file-reading error will
    appear first.  The error code can provide a clue about what happened.
    For example, a file might be unreadable (either because it does not
    actually exist or because the user does not have the necessary access
    priviledges to read it) or some sort of file operation error may have
    been reported by the underlying operating system.  Callers can check
    for these situations using a program fragment such as the following:

     reader = SedReader()
     doc    = reader.readSedML(filename)

     if doc.getNumErrors() > 0:
       if doc.getError(0).getErrorId() == libsedml.XMLFileUnreadable:
         # Handle case of unreadable file here.
       elif doc.getError(0).getErrorId() == libsedml.XMLFileOperationError:
         # Handle case of other file error here.
       else:
         # Handle other error cases here.

    If the given filename ends with the suffix \".gz\" (for example,
    \"myfile.xml.gz\"), the file is assumed to be compressed in gzip format
    and will be automatically decompressed upon reading.  Similarly, if the
    given filename ends with \".zip\" or \".bz2\", the file is assumed to be
    compressed in zip or bzip2 format (respectively).  Files whose names
    lack these suffixes will be read uncompressed.  Note that if the file
    is in zip format but the archive contains more than one file, only the
    first file in the archive will be read and the rest ignored.

    To read a gzip/zip file, libSEDML needs to be configured and linked with
    the zlib library at compile time.  It also needs to be linked with the
    bzip2 library to read files in bzip2 format.  (Both of these are the
    default configurations for libSEDML.)  Errors about unreadable files
    will be logged if a compressed filename is given and libSEDML was not
    linked with the corresponding required library.

    Parameter 'filename is the name or full pathname of the file to be
    read.

    Returns a pointer to the SedDocument created from the Sed content.

    See also SedError.

    Note:

    LibSEDML versions 2.x and later versions behave differently in
    error handling in several respects.  One difference is how early some
    errors are caught and whether libSEDML continues processing a file in
    the face of some early errors.  In general, libSEDML versions after 2.x
    stop parsing Sed inputs sooner than libSEDML version 2.x in the face
    of XML errors, because the errors may invalidate any further Sed
    content.  For example, a missing XML declaration at the beginning of
    the file was ignored by libSEDML 2.x but in version 3.x and later, it
    will cause libSEDML to stop parsing the rest of the input altogether.
    While this behavior may seem more severe and intolerant, it was
    necessary in order to provide uniform behavior regardless of which
    underlying XML parser (Expat, Xerces, libxml2) is being used by
    libSEDML.  The XML parsers themselves behave differently in their error
    reporting, and sometimes libSEDML has to resort to the lowest common
    denominator.
    """
    args_copy    = list(args)
    args_copy[1] = conditional_abspath(args[1])
    return _libsedml.SedReader_readSedML(*args_copy)
%}


/**
 * Since we cannot seem to "shadow" readSedML() (maybe because it's
 * not a method of some object, but rather a top-level function, we
 * employ the following HACK: Tell SWIG to ignore readSedML and just
 * define it in terms of SedReader.readSedML().  This is less than
 * ideal, because the libSEDML C/C++ core does essentially the same
 * thing, so now we're repeating ourselves.
 */

%ignore readSedML(const char*);

%pythoncode
%{
def readSedML(*args):
  """
  readSedML(self, string filename) -> SedDocument

  Reads an Sed document from a file.

  This method is identical to readSedMLFromFile().

  If the file named 'filename' does not exist or its content is not
  valid Sed, one or more errors will be logged with the SedDocument
  object returned by this method.  Callers can use the methods on
  SedDocument such as SedDocument.getNumErrors() and
  SedDocument.getError() to get the errors.  The object returned by
  SedDocument.getError() is an SedError object, and it has methods to
  get the error code, category, and severity level of the problem, as
  well as a textual description of the problem.  The possible severity
  levels range from informational messages to fatal errors; see the
  documentation for SedError for more information.

  If the file 'filename' could not be read, the file-reading error will
  appear first.  The error code can provide a clue about what happened.
  For example, a file might be unreadable (either because it does not
  actually exist or because the user does not have the necessary access
  priviledges to read it) or some sort of file operation error may have
  been reported by the underlying operating system.  Callers can check
  for these situations using a program fragment such as the following:

   reader = SedReader()
   doc    = reader.readSedML(filename)

   if doc.getNumErrors() > 0:
     if doc.getError(0).getErrorId() == libsedml.XMLFileUnreadable:
       # Handle case of unreadable file here.
     elif doc.getError(0).getErrorId() == libsedml.XMLFileOperationError:
       # Handle case of other file error here.
     else:
       # Handle other error cases here.

  If the given filename ends with the suffix \".gz\" (for example,
  \"myfile.xml.gz\"), the file is assumed to be compressed in gzip format
  and will be automatically decompressed upon reading.  Similarly, if the
  given filename ends with \".zip\" or \".bz2\", the file is assumed to be
  compressed in zip or bzip2 format (respectively).  Files whose names
  lack these suffixes will be read uncompressed.  Note that if the file
  is in zip format but the archive contains more than one file, only the
  first file in the archive will be read and the rest ignored.

  To read a gzip/zip file, libSEDML needs to be configured and linked with
  the zlib library at compile time.  It also needs to be linked with the
  bzip2 library to read files in bzip2 format.  (Both of these are the
  default configurations for libSEDML.)  Errors about unreadable files
  will be logged if a compressed filename is given and libSEDML was not
  linked with the corresponding required library.

  Parameter 'filename is the name or full pathname of the file to be
  read.

  Returns a pointer to the SedDocument created from the Sed content.

  See also SedError.

  Note:

  LibSEDML versions 2.x and later versions behave differently in
  error handling in several respects.  One difference is how early some
  errors are caught and whether libSEDML continues processing a file in
  the face of some early errors.  In general, libSEDML versions after 2.x
  stop parsing Sed inputs sooner than libSEDML version 2.x in the face
  of XML errors, because the errors may invalidate any further Sed
  content.  For example, a missing XML declaration at the beginning of
  the file was ignored by libSEDML 2.x but in version 3.x and later, it
  will cause libSEDML to stop parsing the rest of the input altogether.
  While this behavior may seem more severe and intolerant, it was
  necessary in order to provide uniform behavior regardless of which
  underlying XML parser (Expat, Xerces, libxml2) is being used by
  libSEDML.  The XML parsers themselves behave differently in their error
  reporting, and sometimes libSEDML has to resort to the lowest common
  denominator.
  """
  reader = SedReader()
  return reader.readSedML(args[0])
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
 *  - SedNamespacesList SedNamespaces::getSupportedNamespaces()
 *
 */

%feature("shadow")
SedNamespaces::getSupportedNamespaces
%{
  def getSupportedNamespaces(self):
    """
    getSupportedNamespaces(self) -> SedNamespaceList

    Get the List of supported SedNamespaces for this 
    version of LibSEDML.

    Returns the supported list of SedNamespaces.
          

    """
    return _libsedml.SedNamespaces_getSupportedNamespaces(self)
%}

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
