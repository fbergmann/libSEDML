/**
 * \file    libsbml.i
 * \brief   Language-independent SWIG directives for wrapping libSEDML
 * \author  Ben Bornstein and Ben Kovitz
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
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

%module(directors="1") libsedml

//#pragma SWIG nowarn=473,401,844

%pragma(java) moduleclassmodifiers="
/**
  * Wrapper class for global methods and constants defined by libSEDML.
  * <p>
  * <em style='color: #555'>
  * This class of objects is defined by libSEDML only and has no direct
  * equivalent in terms of SEDML components.  This class is not prescribed by
  * the SEDML specifications, although it is used to implement features
  * defined in SEDML.
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
	
#include "local.cpp"
%}

%import  sedml/common/libsedml-namespace.h
%import  sedml/common/extern.h
%import  sedml/common/sedmlfwd.h
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
%template(ModelCreatorList)   ListWrapper<ModelCreator>;
%template(DateList)           ListWrapper<Date>;
%template(CVTermList)         ListWrapper<CVTerm>;
%template(ASTNodeList)        ListWrapper<ASTNode>;
%template(SedNamespacesList) ListWrapper<SedNamespaces>;
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
 * Ignore the Visitor pattern accept() method (for now) on all SEDML
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
%ignore ASTNode::setParentSEDMLObject;

/** 
 * Ignore the list that can't be wrapped
 */
%ignore SEDMLExtensionRegistry::getRegisteredPackageNames;

/**
 * SWIG makes no distinction between int and long arguments.
 * (SWIG 1.3 Manual, Section 6.15.2)
 */
%ignore ASTNode::setValue(int);

/**
 * Ignore operator= and operator<< on all SEDML objects.
 */
%ignore *::operator=;
%ignore *::operator<<;
%ignore operator==;
%ignore operator!=;

/**
 * Ignore certain internal implementation methods on all objects.
 */
%ignore *::writeElements;
%ignore *::getElementPosition;
%ignore *::setSEDMLDocument;
%ignore *::setParentSEDMLObject;
%ignore *::setInternalId;
%ignore *::getInternalId;

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
%ignore SEDMLErrorLog::add(const std::list<SEDMLError>& errors);
%ignore SEDMLErrorLog::add(const std::vector<SEDMLError>& errors);

/** 
 * Ignore methods from SEDML Validator that can't be wrapped
 */
%ignore SEDMLValidator::getFailures;
%ignore SEDMLExternalValidator::getArguments;
%ignore SEDMLExternalValidator::setArguments;


/**
 * Ignore 'static ParentMap mParent;' in SBO.h
 */
%ignore mParent;

/**
 * Ignore 'struct xmlErrorTableEntry' in XMLError.h.
 */
%ignore xmlErrorTableEntry;

/**
 * Both "const std::string& SBase::getMetaId() const" and
 * "std:string& SBase::getMetaId()" are defined in SBase.cpp.
 * By default, SWIG doesn't convert non-const std:string& to and from
 * target language string.
 * So we ignore the non-const version.
 */
%ignore SBase::getMetaId();


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
%newobject SBase::toSEDML;
%newobject SEDMLReader::readSEDMLFromString;
%newobject SEDMLReader::readSEDMLFromFile;
%newobject SEDMLReader::readSEDML;
%newobject readSEDML(const char *);
%newobject readSEDMLFromString(const char *);
%newobject readSEDMLFromFile(const char *);
%newobject SEDMLWriter::writeToString;
%newobject writeSEDMLToString;
%newobject readMathMLFromString;
%newobject writeMathMLToString;
%newobject SEDML_formulaToString;
%newobject SEDML_parseFormula;
%newobject SEDML_parseL3Formula;
%newobject SEDML_parseL3FormulaWithModel;
%newobject SEDML_parseL3FormulaWithSettings;
%newobject SEDML_getDefaultL3ParserSettings;
%newobject SEDML_getLastParseL3Error;
%newobject ASTNode::deepCopy;
%newobject ASTNode::getListOfNodes();
%newobject *::remove;
%newobject Model::removeFunctionDefinition;
%newobject Model::removeUnitDefinition;
%newobject Model::removeCompartmentType;
%newobject Model::removeSpeciesType;
%newobject Model::removeSpecies;
%newobject Model::removeCompartment;
%newobject Model::removeParameter;
%newobject Model::removeInitialAssignment;
%newobject Model::removeRule;
%newobject Model::removeConstraint;
%newobject Model::removeReaction;
%newobject Model::removeEvent;
%newobject Reaction::removeReactant;
%newobject Reaction::removeProduct;
%newobject Reaction::removeModifier;
%newobject Event::removeEventAssignment;
%newobject UnitDefinition::removeUnit;
%newobject KineticLaw::removeParameter;
%newobject KineticLaw::removeLocalParameter;
%newobject RDFAnnotationParser::parseRDFAnnotation(XMLNode *);
%newobject RDFAnnotationParser::deleteRDFAnnotation;
%newobject RDFAnnotationParser::parseCVTerms;
%newobject RDFAnnotationParser::parseModelHistory;
%newobject RDFAnnotationParser::createRDFAnnotation;
%newobject RDFAnnotationParser::createAnnotation;
%newobject RDFAnnotationParser::createRDFDescription;
%newobject RDFAnnotationParser::createCVTerms;
%newobject XMLNode::removeChild;
%newobject XMLNode::convertStringToXMLNode;
%newobject Unit::convertToSI;
%newobject UnitDefinition::convertToSI;
%newobject UnitDefinition::combine;


/**
 * In the wrapped languages, these methods will appear as:
 *
 *  - libsedml.formulaToString()
 *  - libsedml.parseFormula()
 */
%rename(formulaToString) SBML_formulaToString;
%rename(parseFormula)    SBML_parseFormula;
%rename(parseL3Formula)    SBML_parseL3Formula;
%rename(parseL3FormulaWithModel)    SBML_parseL3FormulaWithModel;
%rename(parseL3FormulaWithSettings)    SBML_parseL3FormulaWithSettings;
%rename(getDefaultL3ParserSettings)    SBML_getDefaultL3ParserSettings;
%rename(getLastParseL3Error)    SBML_getLastParseL3Error;


/**
 * 
 * wraps "List* ASTNode::getListOfNodes(ASTNodePredicate)" function
 * as "ListWrapper<ASTNode>* ASTNode::getListOfNodes()" function 
 * which returns a list of all ASTNodes. 
 *
 */

%ignore SedBase::getAllElements;
%ignore SedBase::setUserData;
%ignore SedBase::getUserData;


%extend SedBase
{
        /**
         * Returns a list of all child SBase objects, including those nested to
         * an arbitrary depth.
         *
         * @return SBaseList
         */
	ListWrapper<SedBase>* getListOfAllElements()
	{
		List* list = $self->getAllElements();
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

/*
 * Wraps "static void RDFAnnotationParser::parseRDFAnnotation(const XMLNode *annotation, 
 * List *CVTerms)" function as 
 * "static void RDFAnnotationParser::parseRDFAnnotation(const XMLNode *annotation, 
 *  ListWrapper<CVTerm> *CVTerms);
 *
 */

%ignore RDFAnnotationParser::parseRDFAnnotation(const XMLNode * annotation, List * CVTerms);



/**
 * Wrap these files.
 */

%include "std_string.i"

%include sedml/common/libsedml-version.h
%include sedml/common/operationReturnValues.h
%include sbml/common/libsbml-version.h
%include sbml/common/operationReturnValues.h

%include <sedml/SedTypeCodes.h>
%include <sedml/SedBase.h>
%include <sedml/SedNamespaces.h>
%include <sbml/xml/XMLError.h>
%include <sedml/SedError.h>
%include <sbml/xml/XMLErrorLog.h>
%include <sedml/SedErrorLog.h>
%include <sedml/SedListOf.h>


%include <sedml/SedVariable.h>
%include <sedml/SedParameter.h>
%include <sedml/SedChange.h>
%include <sedml/SedChangeAttribute.h>
%include <sedml/SedRemoveXML.h>
%include <sedml/SedComputeChange.h>
%include <sedml/SedModel.h>
%include <sedml/SedAlgorithm.h>
%include <sedml/SedSimulation.h>
%include <sedml/SedUniformTimeCourse.h>
%include <sedml/SedDataSet.h>
%include <sedml/SedCurve.h>
%include <sedml/SedSurface.h>
%include <sedml/SedOutput.h>
%include <sedml/SedReport.h>
%include <sedml/SedPlot2D.h>
%include <sedml/SedPlot3D.h>
%include <sedml/SedDataGenerator.h>
%include <sedml/SedTask.h>
%include <sedml/SedDocument.h>

%include <sedml/SedConstructorException.h>


%include <sedml/SedReader.h>
%include <sedml/SedWriter.h>
%include sedml/SedTypes.h

%include sbml/math/MathML.h
%include sbml/math/ASTNode.h
%include sbml/math/FormulaParser.h
%include sbml/math/FormulaFormatter.h
%include sbml/math/L3Parser.h
%include sbml/math/L3ParserSettings.h

%include sbml/xml/XMLAttributes.h
%include sbml/xml/XMLConstructorException.h
%include sbml/xml/XMLNamespaces.h
%include sbml/xml/XMLToken.h
%include sbml/xml/XMLNode.h
%include sbml/xml/XMLTriple.h
%include sbml/xml/XMLOutputStream.h
%include sbml/xml/XMLInputStream.h
%include sbml/xml/XMLError.h
%include sbml/xml/XMLErrorLog.h
