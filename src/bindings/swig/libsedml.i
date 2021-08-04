/**
 * @file libsedml.i
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


%module(directors="1") libsedml
%feature("director") SedElementFilter;

%pragma(java) moduleclassmodifiers="
/**
  * Wrapper class for global methods and constants defined by libSEDML.
  * <p>
  * <em style='color: #555'>
  * This class of objects is defined by libSEDML only and has no direct
  * equivalent in terms of Sed components.  This class is not prescribed by
  * the Sed specifications, although it is used to implement features
  * defined in Sed.
  * </em>
  * <p>
  * In the C++ and C versions of libSEDML, there exists a small number of
  * methods that are global in scope; in addition, libSEDML uses a number
  * of enum's to define such things as error codes in a way that can be
  * used by both C++ and C.  This poses a problem in languages such as
  * Java, where there is no concept of global method or global constant.
  * SWIG wraps these global identifiers in the class whose documentation
  * you see before you.
  */
public class"


%{
#include "libsedml.h"

LIBSEDML_CPP_NAMESPACE_USE
LIBSBML_CPP_NAMESPACE_USE
LIBNUML_CPP_NAMESPACE_USE

#include "local.cpp"
%}

%import  sedml/common/libsedml-namespace.h
%import  sedml/common/extern.h
%import  sedml/common/sedmlfwd.h
%include sedml/common/SedmlEnumerations.h
%import  sbml/common/extern.h
%import  sbml/xml/XMLExtern.h

/**
 * Wraps List class by ListWrapper<TYPENAME> template class.
 * TYPENAME is replaced with a corresponding data type which is
 * stored in the List object (e.g. ModelCreator, CVTerm and ASTNode). 
 *
 * ListWrapper<TYPENAME> class is wrapped as TYPENAMEList class
 * (e.g. ListWrapper<CVTerm> -> CVTermList)
 *
 */

%include "ListWrapper.h"
%template(ASTNodeList)        ListWrapper<ASTNode>;
%template(SedNamespacesList)  ListWrapper<SedNamespaces>;
%template(SedBaseList)        ListWrapper<SedBase>;
%template(SBaseList)          ListWrapper<SBase>;

/**
 *
 * Includes a language specific interface file.
 *
 */

%include local.i

/**
 * Unfortunately, SWIG makes no distinction between const and non-const
 * member functions (SWIG 1.3 Manual, Section 6.25), but in libSEDML C++ we
 * have both const and non-const versions of most getter methods.  To avoid
 * a ton of warning messages about 'const' methods not being wrapped, we
 * disable Warning(516).
 */
#pragma SWIG nowarn=516

/**
 * Ignore the Visitor pattern accept() method (for now) on all Sed
 * objects.
 */
%ignore *::accept;

/**
 * Ignore internal implementation methods in ASTNode.h
 */
%ignore ASTNode(Token_t*);
%ignore ASTNode::getListOfNodes(ASTNodePredicate predicate) const;
%ignore ASTNode::fillListOfNodes;
%ignore ASTNode::setSemanticsFlag;
%ignore ASTNode::unsetSemanticsFlag;
%ignore ASTNode::getSemanticsFlag;
%ignore ASTNode::setDefinitionURL;
%ignore ASTNode::setUserData;
%ignore ASTNode::getUserData;
%ignore ASTNode::setParentSBMLObject;

/**
 * SWIG makes no distinction between int and long arguments.
 * (SWIG 1.3 Manual, Section 6.15.2)
 */
%ignore ASTNode::setValue(int);

/**
 * Ignore operator= and operator<< on all Sed objects.
 */
%ignore *::operator=;
%ignore *::operator<<;
%ignore operator==;
%ignore operator!=;

/**
 * Ignore certain internal implementation methods on all objects.
 */
%ignore *::writeElements;
%ignore *::setSedDocument;
%ignore *::setParentSedObject;

/**
 * Ignore internal implementation methods in MathML.h
 */
%ignore readMathML;
%ignore writeMathML;

/**
 * Ignore methods whose pointer argument serves as both input and output
 */
%ignore XMLAttributes::readInto;

/**
 * Ignore methods which receive std::list.
 */
%ignore XMLErrorLog::add(const std::list<XMLError>& errors);
%ignore SedErrorLog::add(const std::list<SedError>& errors);
%ignore SedErrorLog::add(const std::vector<SedError>& errors);

/**
 * Ignore 'struct xmlErrorTableEntry' in XMLError.h.
 */
%ignore xmlErrorTableEntry;

/**
 * Both "const std::string& SedBase::getMetaId() const" and
 * "std:string& SedBase::getMetaId()" are defined in SedBase.cpp.
 * By default, SWIG doesn't convert non-const std:string& to and from
 * target language string.
 * So we ignore the non-const version.
 */
%ignore SedBase::getMetaId();

/**
 * Ignore internal implementation methods in XMLErrorLog
 */
%ignore XMLErrorLog::setParser;

/**
 * Ignore internal implementation methods in SyntaxChecer
 */
%ignore SyntaxChecker::isAllowedElement;
%ignore SyntaxChecker::hasDeclaredNS;
%ignore SyntaxChecker::isCorrectHTMLNode;

/**
 * Ignore internal implementation methods in XMLToken
 */
%ignore XMLToken::write;

/**
 * Ignore internal implementation methods in XMLNode
 */
//%ignore XMLNode::XMLNode(XMLInputStream&);
%ignore XMLNode::write;

/**
 * Ignore internal implementation methods in XMLOutputStream
 */
%ignore XMLOutputStream::getStringStream;

/**
 * Ignore internal implementation classes
 */
%ignore XMLOutputStringStream;
%ignore XMLOutputFileStream;

/**
 * Ignore the unsigned int version of XMLOutputStream::writeAttribute method
 * in order to properly wrap the long version of XMLOutputStream::writeAttribute 
 * method which should be used instead of the unsigned int version.
 */
%ignore XMLOutputStream::writeAttribute(const std::string&, const unsigned int&);
%ignore XMLOutputStream::writeAttribute(const XMLTriple&,   const unsigned int&);

/**
 * The following methods will create new objects.  To prevent memory
 * leaks we must inform SWIG of this.
 */

%typemap(newfree) char * "free($1);";

%newobject *::clone;
%newobject SedBase::toSed;
%newobject SedReader::readSedMLFromString;
%newobject SedReader::readSedMLFromFile;
%newobject SedReader::readSedML;
%newobject readSedML(const char *);
%newobject readSedMLFromString(const char *);
%newobject readSedMLFromFile(const char *);
%newobject SedWriter::writeToString;
%newobject writeSedMLToString;
%newobject readMathMLFromString;
%newobject writeMathMLToString;
%newobject SBML_formulaToString;
%newobject SBML_formulaToL3String;
%newobject SBML_formulaToL3StringWithSettings;
%newobject SBML_parseFormula;
%newobject SBML_parseL3Formula;
%newobject SBML_parseL3FormulaWithModel;
%newobject SBML_parseL3FormulaWithSettings;
%newobject SBML_getDefaultL3ParserSettings;
%newobject SBML_getLastParseL3Error;
%newobject ASTNode::deepCopy;
%newobject ASTNode::getListOfNodes();
%newobject *::remove;
%newobject XMLNode::removeChild;
%newobject XMLNode::convertStringToXMLNode;

/**
 * We can't currently support attaching arbitrary user data to
 * libSEDML objects.
 */
%ignore *::setUserData;
%ignore *::getUserData;

/**
 * In the wrapped languages, these methods will appear as:
 *
 *  - libsbml.formulaToString()
 *  - libsbml.parseFormula()
 */
%rename(formulaToL3String) SBML_formulaToL3String;
%rename(formulaToL3StringWithSettings) SBML_formulaToL3StringWithSettings;
%rename(formulaToString) SBML_formulaToString;
%rename(parseFormula)    SBML_parseFormula;
%rename(parseL3Formula)    SBML_parseL3Formula;
%rename(parseL3FormulaWithModel)    SBML_parseL3FormulaWithModel;
%rename(parseL3FormulaWithSettings)    SBML_parseL3FormulaWithSettings;
%rename(getDefaultL3ParserSettings)    SBML_getDefaultL3ParserSettings;
%rename(getLastParseL3Error)    SBML_getLastParseL3Error;


%rename(getLineStyle) SedStyle::getLine;
%rename(getCol) SedSubPlot::getColumn;
%rename(setCol) SedSubPlot::setColumn;

/**
 *
 * wraps "List* ASTNode::getListOfNodes(ASTNodePredicate)" function
 * as "ListWrapper<ASTNode>* ASTNode::getListOfNodes()" function
 * which returns a list of all ASTNodes.
 *
 */

%ignore SedBase::getAllElements;

%extend SedBase
{
	ListWrapper<SedBase>* getListOfAllElements(SedElementFilter* filter=NULL)
	{
		List* list = $self->getAllElements(filter);
		return new ListWrapper<SedBase>(list);
	}
}

%extend ASTNode
{
  ListWrapper<ASTNode>* getListOfNodes()
  {
    List *list = $self->getListOfNodes(ASTNode_true);
    return new ListWrapper<ASTNode>(list);
  }
}

/**
 * Wrap these files.
 */

%include "std_string.i"
%include "std_vector.i"
%template(DoubleStdVector) std::vector<double>;
typedef std::vector<double> DoubleStdVector;
%template(XmlErrorStdVector) std::vector<XMLError*>;
typedef std::vector<XMLError*> XmlErrorStdVector;
%template(SedErrorStdVector) std::vector<SedError>;
typedef std::vector<SedError> SedErrorStdVector;

%include sedml/common/libsedml-version.h
%include sedml/common/SedOperationReturnValues.h
%include sbml/common/libsbml-version.h
%include sbml/common/operationReturnValues.h

%include sbml/xml/XMLError.h
%include sbml/xml/XMLErrorLog.h




%include <sedml/SedReader.h>
%include <sedml/SedWriter.h>
%include <sedml/SedTypeCodes.h>
%include <sedml/SedTypes.h>
%include <sedml/SedBase.h>
%include <sedml/SedElementFilter.h>
%include <sedml/SedListOf.h>
%include <sedml/SedDocument.h>
%include <sedml/SedErrorLog.h>
%include <sedml/SedError.h>

%include <sedml/SedConstructorException.h>
%include <sedml/SedNamespaces.h>

%include <sedml/SedModel.h>
%include <sedml/SedListOfModels.h>
%include <sedml/SedChange.h>
%include <sedml/SedListOfChanges.h>
%include <sedml/SedAddXML.h>
%include <sedml/SedChangeAttribute.h>
%include <sedml/SedVariable.h>
%include <sedml/SedListOfVariables.h>
%include <sedml/SedParameter.h>
%include <sedml/SedListOfParameters.h>
%include <sedml/SedSimulation.h>
%include <sedml/SedListOfSimulations.h>
%include <sedml/SedUniformTimeCourse.h>
%include <sedml/SedAlgorithm.h>
%include <sedml/SedAbstractTask.h>
%include <sedml/SedListOfTasks.h>
%include <sedml/SedTask.h>
%include <sedml/SedDataGenerator.h>
%include <sedml/SedListOfDataGenerators.h>
%include <sedml/SedOutput.h>
%include <sedml/SedListOfOutputs.h>
%include <sedml/SedPlot.h>
%include <sedml/SedPlot2D.h>
%include <sedml/SedPlot3D.h>
%include <sedml/SedAbstractCurve.h>
%include <sedml/SedListOfCurves.h>
%include <sedml/SedCurve.h>
%include <sedml/SedSurface.h>
%include <sedml/SedListOfSurfaces.h>
%include <sedml/SedDataSet.h>
%include <sedml/SedListOfDataSets.h>
%include <sedml/SedReport.h>
%include <sedml/SedAlgorithmParameter.h>
%include <sedml/SedListOfAlgorithmParameters.h>
%include <sedml/SedRange.h>
%include <sedml/SedListOfRanges.h>
%include <sedml/SedChangeXML.h>
%include <sedml/SedRemoveXML.h>
%include <sedml/SedSetValue.h>
%include <sedml/SedListOfSetValues.h>
%include <sedml/SedUniformRange.h>
%include <sedml/SedVectorRange.h>
%include <sedml/SedFunctionalRange.h>
%include <sedml/SedSubTask.h>
%include <sedml/SedListOfSubTasks.h>
%include <sedml/SedOneStep.h>
%include <sedml/SedAnalysis.h>
%include <sedml/SedSteadyState.h>
%include <sedml/SedRepeatedTask.h>
%include <sedml/SedComputeChange.h>
%include <sedml/SedDataDescription.h>
%include <sedml/SedListOfDataDescriptions.h>
%include <sedml/SedDataSource.h>
%include <sedml/SedListOfDataSources.h>
%include <sedml/SedSlice.h>
%include <sedml/SedListOfSlices.h>
%include <sedml/SedParameterEstimationTask.h>
%include <sedml/SedObjective.h>
%include <sedml/SedLeastSquareObjectiveFunction.h>
%include <sedml/SedAdjustableParameter.h>
%include <sedml/SedListOfAdjustableParameters.h>
%include <sedml/SedExperimentReference.h>
%include <sedml/SedListOfExperimentReferences.h>
%include <sedml/SedFitExperiment.h>
%include <sedml/SedListOfFitExperiments.h>
%include <sedml/SedFitMapping.h>
%include <sedml/SedListOfFitMappings.h>
%include <sedml/SedBounds.h>
%include <sedml/SedFigure.h>
%include <sedml/SedSubPlot.h>
%include <sedml/SedListOfSubPlots.h>
%include <sedml/SedAxis.h>
%include <sedml/SedStyle.h>
%include <sedml/SedListOfStyles.h>
%include <sedml/SedLine.h>
%include <sedml/SedMarker.h>
%include <sedml/SedFill.h>
%include <sedml/SedAppliedDimension.h>
%include <sedml/SedListOfAppliedDimensions.h>
%include <sedml/SedDataRange.h>
%include <sedml/SedShadedArea.h>
%include <sedml/SedParameterEstimationResultPlot.h>
%include <sedml/SedWaterfallPlot.h>
%include <sedml/SedParameterEstimationReport.h>

%include sbml/SyntaxChecker.h
%include sbml/ExpectedAttributes.h

%include sbml/xml/XMLAttributes.h
%include sbml/xml/XMLConstructorException.h
%include sbml/xml/XMLNamespaces.h
%include sbml/xml/XMLToken.h
%include sbml/xml/XMLNode.h
%include sbml/xml/XMLTriple.h
%include sbml/xml/XMLOutputStream.h
%include sbml/xml/XMLInputStream.h

%include ASTNodes.i

%include <numl/common/extern.h>
%include <numl/common/libnuml-namespace.h>
%include <numl/common/libnuml-version.h>
%include <numl/common/operationReturnValues.h>

%include <numl/NUMLNamespaces.h>
%include <numl/NUMLTypeCodes.h>
%include <numl/NUMLTypes.h>
%include <numl/NUMLError.h>
%include <numl/NUMLErrorLog.h>
%include numl/NUMLReader.h
%include numl/NUMLWriter.h
%include <numl/NMBase.h>
%include <numl/NUMLList.h>
%include <numl/OntologyTerm.h>
%include <numl/NUMLDocument.h>
%include <numl/ResultComponent.h>
%include <numl/Dimension.h>
%include <numl/DimensionDescription.h>
%include <numl/CompositeValue.h>
%include <numl/Tuple.h>
%include <numl/AtomicValue.h>
%include <numl/CompositeDescription.h>
%include <numl/TupleDescription.h>
%include <numl/AtomicDescription.h>

%include numl/NUMLErrorLog.h
%include numl/NUMLError.h

