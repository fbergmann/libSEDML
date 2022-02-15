/**
 * @file SedErrorTable.h
 * @brief Definition of the SedErrorTable class.
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


#ifndef SedErrorTable_H__
#define SedErrorTable_H__

#include <sedml/SedError.h>


LIBSEDML_CPP_NAMESPACE_BEGIN

/** @cond doxygenLibsedmlInternal */
typedef struct {
  const char * ref_l1v1;
} referenceEntry;


typedef struct {
  unsigned int code;
  const char * shortMessage;
  unsigned int category;
  unsigned int l1v1_severity;
  const char * message;
  referenceEntry reference;
} sedmlErrorTableEntry;


static const sedmlErrorTableEntry sedmlErrorTable[] =
{
  // 10000
  { SedUnknown,
    "Encountered unknown internal libSEDML error",
    LIBSEDML_CAT_INTERNAL, 
    LIBSEDML_SEV_FATAL,
    "Unrecognized error encountered by libSEDML",
    {"",
    }
  },

  //10001
  {
    SedNotUTF8,
    "File does not use UTF-8 encoding",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A SED-ML XML file must use UTF-8 as the character encoding. More "
    "precisely, the 'encoding' attribute of the XML declaration at the "
    "beginning of the XML data stream cannot have a value other than "
    "'UTF-8'. An example valid declaration is "
    "'<?xml version=\"1.0\" encoding=\"UTF-8\"?>'.",
    {""
    }
  },

  //10002
  {
    SedUnrecognizedElement,
    "Encountered unrecognized element",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A SED-ML XML document must not contain undefined elements or attributes "
    "in the SED-ML namespace. Documents containing unknown elements or "
    "attributes placed in the SED-ML namespace do not conform to the SED-ML "
    "specification.",  
    {""
    }
  },

  //10003
  {
    SedNotSchemaConformant,
    "Document does not conform to the SED-ML XML schema",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A SED-ML XML document must conform to the XML Schema for the corresponding "
    "SED-ML Level, Version and Release. The XML Schema for SED-ML defines the "
    "basic SED-ML object structure, the data types used by those objects, and the "
    "order in which the objects may appear in a SED-ML document.",
    {""
    }
  },

  //10201
  {
    SedInvalidMathElement,
    "Invalid MathML",
    LIBSEDML_CAT_MATHML_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "All MathML content in SED-ML must appear within a <math> element, and the "
    "<math> element must be either explicitly or implicitly in the XML "
    "namespace \"http://www.w3.org/1998/Math/MathML\".",
    {""
    }
  },

  //10401
  {
    SedMissingAnnotationNamespace,
    "Missing declaration of the XML namespace for the annotation",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "Every top-level element within an annotation element must "
    "have a namespace declared.",
    {""
    }
  },

  //10402
  {
    SedDuplicateAnnotationNamespaces,
    "Multiple annotations using the same XML namespace",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "There cannot be more than one top-level element using a "
    "given namespace inside a given annotation element. ", 
    {""
    }
  },

  //10403
  {
    SedNamespaceInAnnotation,
    "The SED-ML XML namespace cannot be used in an Annotation object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "Top-level elements within an annotation element cannot use any SED-ML "
    "namespace, whether explicitly or implicitly (by failing "
    "to declare any namespace).",
    {""
    }
  },

  //10404
  {
    SedMultipleAnnotations,
    "Only one Annotation object is permitted under a given SED-ML object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A given SED-ML object may contain at most one <annotation> element.",
    {""
    }
  },

  //10801
  {
    SedNotesNotInXHTMLNamespace,
    "Notes must be placed in the XHTML XML namespace",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "The contents of the <notes> element must be explicitly placed in the "
    "XHTML XML namespace.", 
    {""
    }
  },

  //10802
  {
    SedNotesContainsXMLDecl,
    "XML declarations are not permitted in Notes objects",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML declaration "
    "(i.e., a string of the form \"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\" "
    "or similar).",
    {""
    }
  },

  //10803
  {
    SedNotesContainsDOCTYPE,
    "XML DOCTYPE elements are not permitted in Notes objects",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML DOCTYPE "
    "declaration (i.e., a string beginning with the characters \"<!DOCTYPE\". ",
    {""
    }
  },

  //10804
  {
    SedInvalidNotesContent,
    "Invalid notes content",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "Invalid contents in a <notes> element. ",
    {""
    }
  },

  //10805
  {
    SedOnlyOneNotesElementAllowed,
    "Only one Notes subobject is permitted on a given SED-ML object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A given SED-ML object may contain at most one <notes> element. ",
    {""
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  SED-ML specific errors.
   * ----------------------------------------------------------------------- */

  // 10101
  { SedmlNSUndeclared,
    "The Sedml namespace is not correctly declared.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "To conform to the Package specification for SBML Level 1 Version 1, an "
    "SBML document must declare "
    "'http://www.sbml.org/sbml/level1/version1/sedml/version1' as the "
    "XMLNamespace to use for elements of this package.",
    { "L3V1 Sedml V1 Section 3.1"
    }
  },

  // 10102
  { SedmlElementNotInNs,
    "Element not in Sedml namespace",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Package must use the "
    "'http://www.sbml.org/sbml/level1/version1/sedml/version1' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Sedml V1 Section 3.1"
    }
  },

  // 10301
  { SedmlDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 10302
  { SedmlIdSyntaxRule,
    "Invalid SId syntax",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of a 'sedml:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 10303
  { SedInvalidMetaidSyntax,
    "Invalid SId syntax",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of a 'sedml:metaid' must conform to the syntax of the XML Type "
    "ID",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20101
  { InvalidNamespaceOnSed,
    "Invalid namespace",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Invalid namespace declared.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20102
  { SedAllowedAttributes,
    "Allowed attributes",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Allowed attributes",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20103
  { SedEmptyListElement,
    "No empty listOf",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "No empty lists",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20201
  { SedmlDocumentAllowedCoreAttributes,
    "Core attributes allowed on <document>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <document> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <document>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20202
  { SedmlDocumentAllowedCoreElements,
    "Core elements allowed on <document>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <document> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <document>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20203
  { SedmlDocumentAllowedAttributes,
    "Attributes allowed on <document>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <document> object must have the required attributes 'sedml:level' and "
    "'sedml:version'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <document> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20204
  { SedmlDocumentAllowedElements,
    "Elements allowed on <document>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <document> object may contain one and only one instance of each of the "
    "<listOfDataDescriptions,> <listOfModels,> <listOfSimulations,> "
    "<listOfAbstractTasks,> <listOfDataGenerators,> <listOfOutputs,> "
    "<listOfStyles> and <listOfAlgorithmParameters> elements. No other elements "
    "from the SBML Level 3 SEDML namespaces are permitted on a <document> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20205
  { SedmlDocumentLevelMustBeNonNegativeInteger,
    "The 'level' attribute must be NonNegativeInteger.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:level' on a <document> must have a value of data type "
    "'integer', and must be non negative.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20206
  { SedmlDocumentVersionMustBeNonNegativeInteger,
    "The 'version' attribute must be NonNegativeInteger.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:version' on a <document> must have a value of data "
    "type 'integer', and must be non negative.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20207
  { SedmlDocumentLODataDescriptionsAllowedCoreElements,
    "Core elements allowed on <listOfDataDescriptions>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDataDescriptions> container object may only contain "
    "<dataDescription> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20208
  { SedmlDocumentLOModelsAllowedCoreElements,
    "Core elements allowed on <listOfModels>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfModels> container object may only contain <model> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20209
  { SedmlDocumentLOSimulationsAllowedCoreElements,
    "Core elements allowed on <listOfSimulations>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSimulations> container object may only contain "
    "<simulation> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20210
  { SedmlDocumentLOTasksAllowedCoreElements,
    "Core elements allowed on <listOfTasks>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfTasks> container object may only contain "
    "<abstractTask> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20211
  { SedmlDocumentLODataGeneratorsAllowedCoreElements,
    "Core elements allowed on <listOfDataGenerators>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDataGenerators> container object may only contain "
    "<dataGenerator> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20212
  { SedmlDocumentLOOutputsAllowedCoreElements,
    "Core elements allowed on <listOfOutputs>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfOutputs> container object may only contain <output> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20213
  { SedmlDocumentLOStylesAllowedCoreElements,
    "Core elements allowed on <listOfStyles>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfStyles> container object may only contain <style> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20214
  { SedmlDocumentLODataDescriptionsAllowedCoreAttributes,
    "Core attributes allowed on <listOfDataDescriptions>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfDataDescriptions> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDataDescriptions> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20215
  { SedmlDocumentLOModelsAllowedCoreAttributes,
    "Core attributes allowed on <listOfModels>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfModels> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfModels> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20216
  { SedmlDocumentLOSimulationsAllowedCoreAttributes,
    "Core attributes allowed on <listOfSimulations>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSimulations> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSimulations> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20217
  { SedmlDocumentLOTasksAllowedCoreAttributes,
    "Core attributes allowed on <listOfTasks>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAbstractTasks> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfAbstractTasks> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20218
  { SedmlDocumentLODataGeneratorsAllowedCoreAttributes,
    "Core attributes allowed on <listOfDataGenerators>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfDataGenerators> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDataGenerators> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20219
  { SedmlDocumentLOOutputsAllowedCoreAttributes,
    "Core attributes allowed on <listOfOutputs>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfOutputs> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfOutputs> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20220
  { SedmlDocumentLOStylesAllowedCoreAttributes,
    "Core attributes allowed on <listOfStyles>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfStyles> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfStyles> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20221
  { SedmlDocumentLOAlgorithmParametersAllowedCoreElements,
    "Core elements allowed on <listOfAlgorithmParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAlgorithmParameters> container object may only "
    "contain <algorithmParameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20222
  { SedmlDocumentLOAlgorithmParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfAlgorithmParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAlgorithmParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfAlgorithmParameters> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20301
  { SedmlModelAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <model> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <model>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20302
  { SedmlModelAllowedCoreElements,
    "Core elements allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <model> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <model>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20303
  { SedmlModelAllowedAttributes,
    "Attributes allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <model> object must have the required attributes 'sedml:language' "
    "(optional before Level 1 Version 4), 'sedml:id', and "
    "'sedml:source', and may have the optional attribute 'sedml:name'. "
    "No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <model> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20304
  { SedmlModelAllowedElements,
    "Elements allowed on <model>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <model> object may contain one and only one instance of the "
    "<listOfChanges> element. No other elements from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <model> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20305
  { SedmlModelSourceMustBeString,
    "The 'source' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20306
  { SedmlModelNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20307
  { SedmlModelLanguageMustBeString,
    "The 'language' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:language' on a <model> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20308
  { SedmlModelLOChangesAllowedCoreElements,
    "Core elements allowed on <listOfChanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfChanges> container object may only contain <change> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20309
  { SedmlModelLOChangesAllowedCoreAttributes,
    "Core attributes allowed on <listOfChanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfChanges> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfChanges> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20401
  { SedmlChangeAllowedCoreAttributes,
    "Core attributes allowed on <change>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <change> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <change>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20402
  { SedmlChangeAllowedCoreElements,
    "Core elements allowed on <change>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <change> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <change>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20403
  { SedmlChangeAllowedAttributes,
    "Attributes allowed on <change>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <change> object must have the required attribute 'sedml:target'. No "
    "other attributes from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<change> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20404
  { SedmlChangeTargetMustBeString,
    "The 'target' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on a <change> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20501
  { SedmlAddXMLAllowedCoreAttributes,
    "Core attributes allowed on <addXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <addXML> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <addXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20502
  { SedmlAddXMLAllowedCoreElements,
    "Core elements allowed on <addXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <addXML> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <addXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20503
  { SedmlAddXMLAllowedElements,
    "Elements allowed on <addXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <addXML> object must contain one and only one instance of the XMLNode "
    "element. No other elements from the SBML Level 3 SED-ML namespaces are "
    "permitted on an <addXML> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20601
  { SedmlChangeAttributeAllowedCoreAttributes,
    "Core attributes allowed on <changeAttribute>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeAttribute> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <changeAttribute>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20602
  { SedmlChangeAttributeAllowedCoreElements,
    "Core elements allowed on <changeAttribute>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeAttribute> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <changeAttribute>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20603
  { SedmlChangeAttributeAllowedAttributes,
    "Attributes allowed on <changeAttribute>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeAttribute> object must have the required attribute "
    "'sedml:newValue'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <changeAttribute> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20604
  { SedmlChangeAttributeNewValueMustBeString,
    "The 'newValue' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:newValue' on a <changeAttribute> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20701
  { SedmlVariableAllowedCoreAttributes,
    "Core attributes allowed on <variable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <variable> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <variable>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20702
  { SedmlVariableAllowedCoreElements,
    "Core elements allowed on <variable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <variable> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <variable>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20703
  { SedmlVariableAllowedAttributes,
    "Attributes allowed on <variable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <variable> object must have the required attribute 'sedml:id', and may "
    "have the optional attributes 'sedml:symbol', "
    "'sedml:target', 'sedml:taskReference', 'sedml:modelReference', "
    "'sedml:term', 'sedml:symbol2', 'sedml:target2' and "
    "'sedml:dimensionTerm'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <variable> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20704
  { SedmlVariableAllowedElements,
    "Elements allowed on <variable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <variable> object may contain one and only one instance of the "
    "<listOfAppliedDimensions> element. No other elements from the SBML Level "
    "3 SED-ML namespaces are permitted on a <variable> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20705
  { SedmlVariableNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <variable> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20706
  { SedmlVariableSymbolMustBeString,
    "The 'symbol' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbol' on a <variable> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20707
  { SedmlVariableTargetMustBeString,
    "The 'target' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on a <variable> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20707
  { SedmlVariableTaskReferenceMustBeAbstractTask,
    "The attribute 'taskReference' must point to AbstractTask object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:taskReference' of a <variable> object "
    "must be the identifier of an existing <abstractTask> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20709
  { SedmlVariableModelReferenceMustBeModel,
    "The attribute 'modelReference' must point to Model object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of a <variable> object "
    "must be the identifier of an existing <model> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20709
  { SedmlVariableTermMustBeString,
    "The 'term' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:term' on a <variable> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20710
  { SedmlVariableSymbol2MustBeString,
    "The 'symbol2' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbolTwo' on a <variable> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20711
  { SedmlVariableTarget2MustBeString,
    "The 'target2' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:targetTwo' on a <variable> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20712
  { SedmlVariableDimensionTermMustBeString,
    "The 'dimensionTerm' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:dimensionTerm' on a <variable> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20713
  { SedmlVariableLOAppliedDimensionsAllowedCoreElements,
    "Core elements allowed on <listOfAppliedDimensions>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAppliedDimensions> container object may only "
    "contain <appliedDimension> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20711
  { SedmlVariableLOAppliedDimensionsAllowedCoreAttributes,
    "Core attributes allowed on <listOfAppliedDimensions>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAppliedDimensions> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfAppliedDimensions> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20801
  { SedmlParameterAllowedCoreAttributes,
    "Core attributes allowed on <parameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameter> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <parameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20802
  { SedmlParameterAllowedCoreElements,
    "Core elements allowed on <parameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameter> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <parameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20803
  { SedmlParameterAllowedAttributes,
    "Attributes allowed on <parameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameter> object must have the required attributes 'sedml:value' and "
    "'sedml:id'. No other attributes from the SBML Level 3 SEDML namespaces are "
    "permitted on a <parameter> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20804
  { SedmlParameterValueMustBeDouble,
    "The 'value' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:value' on a <parameter> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20805
  { SedmlParameterNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <parameter> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20901
  { SedmlSimulationAllowedCoreAttributes,
    "Core attributes allowed on <simulation>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simulation> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <simulation>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20902
  { SedmlSimulationAllowedCoreElements,
    "Core elements allowed on <simulation>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simulation> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <simulation>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20903
  { SedmlSimulationAllowedAttributes,
    "Attributes allowed on <simulation>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simulation> object must have the required attribute 'sedml:id', and may "
    "have the optional attribute 'sedml:name'. No other attributes from the "
    "SBML Level 3 SED-ML namespaces are permitted on a <simulation> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20904
  { SedmlSimulationAllowedElements,
    "Elements allowed on <simulation>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <simulation> object must contain one and only one instance of the "
    "SedAlgorithm element. No other elements from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <simulation> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20905
  { SedmlSimulationNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <simulation> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21001
  { SedmlUniformTimeCourseAllowedCoreAttributes,
    "Core attributes allowed on <uniformTimeCourse>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformTimeCourse> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <uniformTimeCourse>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21002
  { SedmlUniformTimeCourseAllowedCoreElements,
    "Core elements allowed on <uniformTimeCourse>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformTimeCourse> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <uniformTimeCourse>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21003
  { SedmlUniformTimeCourseAllowedAttributes,
    "Attributes allowed on <uniformTimeCourse>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformTimeCourse> object must have the required attributes "
    "'sedml:initialTime', 'sedml:outputStartTime' and 'sedml:outputEndTime', "
    "and may have one of the optional attributes 'sedml:numberOfPoints' or "
    "'sedml:numberOfSteps'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on an <uniformTimeCourse> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21004
  { SedmlUniformTimeCourseInitialTimeMustBeDouble,
    "The 'initialTime' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:initialTime' on an <uniformTimeCourse> must have a "
    "value of data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21005
  { SedmlUniformTimeCourseOutputStartTimeMustBeDouble,
    "The 'outputStartTime' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:outputStartTime' on an <uniformTimeCourse> must have "
    "a value of data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21006
  { SedmlUniformTimeCourseOutputEndTimeMustBeDouble,
    "The 'outputEndTime' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:outputEndTime' on an <uniformTimeCourse> must have a "
    "value of data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21007
  { SedmlUniformTimeCourseNumberOfPointsMustBeInteger,
    "The 'numberOfPoints' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numberOfPoints' on an <uniformTimeCourse> must have a "
    "value of data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21008
  { SedmlUniformTimeCourseNumberOfStepsMustBeInteger,
    "The 'numberOfSteps' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numberOfSteps' on an <uniformTimeCourse> must have a "
    "value of data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21101
  { SedmlAlgorithmAllowedCoreAttributes,
    "Core attributes allowed on <algorithm>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithm> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <algorithm>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21102
  { SedmlAlgorithmAllowedCoreElements,
    "Core elements allowed on <algorithm>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithm> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <algorithm>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21103
  { SedmlAlgorithmAllowedAttributes,
    "Attributes allowed on <algorithm>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithm> object must have the required attribute 'sedml:kisaoID'. No "
    "other attributes from the SBML Level 3 SED-ML namespaces are permitted on "
    "an <algorithm> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21104
  { SedmlAlgorithmAllowedElements,
    "Elements allowed on <algorithm>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithm> object may contain one and only one instance of the "
    "<listOfAlgorithmParameters> element. No other elements from the SBML Level "
    "3 SED-ML namespaces are permitted on an <algorithm> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21105
  { SedmlAlgorithmKisaoIDMustBeString,
    "The 'kisaoID' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:kisaoID' on an <algorithm> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21106
  { SedmlAlgorithmLOAlgorithmParametersAllowedCoreElements,
    "Core elements allowed on <listOfAlgorithmParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAlgorithmParameters> container object may only "
    "contain <algorithmParameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21107
  { SedmlAlgorithmLOAlgorithmParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfAlgorithmParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAlgorithmParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfAlgorithmParameters> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21201
  { SedmlAbstractTaskAllowedCoreAttributes,
    "Core attributes allowed on <abstractTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractTask> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <abstractTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21202
  { SedmlAbstractTaskAllowedCoreElements,
    "Core elements allowed on <abstractTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractTask> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <abstractTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21203
  { SedmlAbstractTaskAllowedAttributes,
    "Attributes allowed on <abstractTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractTask> object must have the required attribute 'sedml:id', and "
    "may have the optional attribute 'sedml:name'. No other attributes from the "
    "SBML Level 3 SED-ML namespaces are permitted on an <abstractTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21204
  { SedmlAbstractTaskNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on an <abstractTask> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21301
  { SedmlTaskAllowedCoreAttributes,
    "Core attributes allowed on <task>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <task> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <task>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21302
  { SedmlTaskAllowedCoreElements,
    "Core elements allowed on <task>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <task> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <task>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21303
  { SedmlTaskAllowedAttributes,
    "Attributes allowed on <task>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <task> object must have the required attributes 'sedml:modelReference' "
    "and 'sedml:simulationReference'. No other attributes from the SBML Level 3 "
    "SED-ML namespaces are permitted on a <task> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21304
  { SedmlTaskModelReferenceMustBeModel,
    "The attribute 'modelReference' must point to Model object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of a <task> object must "
    "be the identifier of an existing <model> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21305
  { SedmlTaskSimulationReferenceMustBeSimulation,
    "The attribute 'simulationReference' must point to Simulation object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:simulationReference' of a <task> object "
    "must be the identifier of an existing <simulation> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21401
  { SedmlDataGeneratorAllowedCoreAttributes,
    "Core attributes allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataGenerator> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <dataGenerator>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21402
  { SedmlDataGeneratorAllowedCoreElements,
    "Core elements allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataGenerator> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <dataGenerator>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21403
  { SedmlDataGeneratorAllowedAttributes,
    "Attributes allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataGenerator> object must have the required attribute 'sedml:id', and "
    "may have the optional attribute 'sedml:name'. No other attributes from the "
    "SBML Level 3 SED-ML namespaces are permitted on a <dataGenerator> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21404
  { SedmlDataGeneratorAllowedElements,
    "Elements allowed on <dataGenerator>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataGenerator> object may contain one and only one instance of each of "
    "the <listOfVariables,> <listOfParameters> and ASTNode elements. No other "
    "elements from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<dataGenerator> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21405
  { SedmlDataGeneratorNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataGenerator> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21406
  { SedmlDataGeneratorLOVariablesAllowedCoreElements,
    "Core elements allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfVariables> container object may only contain "
    "<variable> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21407
  { SedmlDataGeneratorLOParametersAllowedCoreElements,
    "Core elements allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfParameters> container object may only contain "
    "<parameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21408
  { SedmlDataGeneratorLOVariablesAllowedCoreAttributes,
    "Core attributes allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfVariables> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfVariables> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21409
  { SedmlDataGeneratorLOParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfParameters> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfParameters> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21501
  { SedmlOutputAllowedCoreAttributes,
    "Core attributes allowed on <output>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <output> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <output>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21502
  { SedmlOutputAllowedCoreElements,
    "Core elements allowed on <output>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <output> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <output>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21503
  { SedmlOutputAllowedAttributes,
    "Attributes allowed on <output>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <output> object may have the optional attributes 'sedml:id' and "
    "'sedml:name'. No other attributes from the SBML Level 3 SED-ML namespaces "
    "are permitted on an <output> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21504
  { SedmlOutputNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on an <output> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21601
  { SedmlPlotAllowedCoreAttributes,
    "Core attributes allowed on <plot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <plot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21602
  { SedmlPlotAllowedCoreElements,
    "Core elements allowed on <plot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <plot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21603
  { SedmlPlotAllowedAttributes,
    "Attributes allowed on <plot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot> object may have the optional attributes 'sedml:legend', "
    "'sedml:height' and 'sedml:width'. No other attributes from the SBML Level "
    "3 SED-ML namespaces are permitted on a <plot> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21604
  { SedmlPlotAllowedElements,
    "Elements allowed on <plot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot> object may contain one and only one instance of each of the "
    "SedAxis and SedAxis elements. No other elements from the SBML Level 3 "
    "SED-ML namespaces are permitted on a <plot> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21605
  { SedmlPlotLegendMustBeBoolean,
    "The 'legend' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:legend' on a <plot> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21606
  { SedmlPlotHeightMustBeDouble,
    "The 'height' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:height' on a <plot> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21607
  { SedmlPlotWidthMustBeDouble,
    "The 'width' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:width' on a <plot> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21701
  { SedmlPlot2DAllowedCoreAttributes,
    "Core attributes allowed on <plot2D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot2D> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <plot2D>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21702
  { SedmlPlot2DAllowedCoreElements,
    "Core elements allowed on <plot2D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot2D> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <plot2D>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21703
  { SedmlPlot2DAllowedElements,
    "Elements allowed on <plot2D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot2D> object may contain one and only one instance of each of the "
    "<listOfAbstractCurves> and SedAxis elements. No other elements from the "
    "SBML Level 3 SED-ML namespaces are permitted on a <plot2D> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21704
  { SedmlPlot2DLOCurvesAllowedCoreElements,
    "Core elements allowed on <listOfCurves>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfCurves> container object may only contain "
    "<abstractCurve> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21705
  { SedmlPlot2DLOCurvesAllowedCoreAttributes,
    "Core attributes allowed on <listOfCurves>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAbstractCurves> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfAbstractCurves> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21801
  { SedmlPlot3DAllowedCoreAttributes,
    "Core attributes allowed on <plot3D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot3D> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <plot3D>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21802
  { SedmlPlot3DAllowedCoreElements,
    "Core elements allowed on <plot3D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot3D> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <plot3D>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21803
  { SedmlPlot3DAllowedElements,
    "Elements allowed on <plot3D>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <plot3D> object may contain one and only one instance of each of the "
    "<listOfSurfaces> and SedAxis elements. No other elements from the SBML "
    "Level 3 SED-ML namespaces are permitted on a <plot3D> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21804
  { SedmlPlot3DLOSurfacesAllowedCoreElements,
    "Core elements allowed on <listOfSurfaces>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSurfaces> container object may only contain "
    "<surface> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21805
  { SedmlPlot3DLOSurfacesAllowedCoreAttributes,
    "Core attributes allowed on <listOfSurfaces>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSurfaces> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSurfaces> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21901
  { SedmlAbstractCurveAllowedCoreAttributes,
    "Core attributes allowed on <abstractCurve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractCurve> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <abstractCurve>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21902
  { SedmlAbstractCurveAllowedCoreElements,
    "Core elements allowed on <abstractCurve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractCurve> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <abstractCurve>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21903
  { SedmlAbstractCurveAllowedAttributes,
    "Attributes allowed on <abstractCurve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <abstractCurve> object must have the required attribute "
    "'sedml:xDataReference' (optional before Level 1 Version 4), and may have the optional attributes 'sedml:id', "
    "'sedml:name', 'sedml:logX', 'sedml:order', 'sedml:style', and 'sedml:yAxis'. "
    "No other attributes from the SBML Level 3 "
    "SED-ML namespaces are permitted on an <abstractCurve> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21904
  { SedmlAbstractCurveNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on an <abstractCurve> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21905
  { SedmlAbstractCurveLogXMustBeBoolean,
    "The 'logX' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:logX' on an <abstractCurve> must have a value of data "
    "type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21906
  { SedmlAbstractCurveOrderMustBeInteger,
    "The 'order' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:order' on an <abstractCurve> must have a value of "
    "data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21907
  { SedmlAbstractCurveStyleMustBeStyle,
    "The attribute 'style' must point to Style object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:style' of an <abstractCurve> object must "
    "be the identifier of an existing <style> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21908
  { SedmlAbstractCurveYAxisMustBeString,
    "The 'yAxis' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:yAxis' on an <abstractCurve> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21909
  { SedmlAbstractCurveXDataReferenceMustBeDataReference,
    "The attribute 'xDataReference' must point to DataReference object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:xDataReference' of an <abstractCurve> "
    "object must be the identifier of an existing <dataReference> object "
    "defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22001
  { SedmlCurveAllowedCoreAttributes,
    "Core attributes allowed on <curve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <curve> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <curve>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22002
  { SedmlCurveAllowedCoreElements,
    "Core elements allowed on <curve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <curve> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <curve>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22003
  { SedmlCurveAllowedAttributes,
    "Attributes allowed on <curve>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <curve> object must have the required attribute 'sedml:yDataReference', "
    "and may have the optional attributes 'sedml:logY', 'sedml:type', "
    "'sedml:xErrorUpper', 'sedml:xErrorLower', 'sedml:yErrorUpper' and "
    "'sedml:yErrorLower'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <curve> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22004
  { SedmlCurveYDataReferenceMustBeDataGenerator,
    "The attribute 'yDataReference' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yDataReference' of a <curve> object must "
    "be the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22005
  { SedmlCurveLogYMustBeBoolean,
    "The 'logY' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:logY' on a <curve> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22006
  { SedmlCurveTypeMustBeCurveTypeEnum,
    "The 'type' attribute must be CurveTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of a <curve> object must conform "
    "to the syntax of SBML data type 'CurveType' and may only take on the "
    "allowed values of 'CurveType' defined in SBML; that is, the value must be "
    "one of the following: 'points', 'bar', 'barStacked', 'horizontalBar' or "
    "'horizontalBarStacked'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22007
  { SedmlCurveXErrorUpperMustBeDataGenerator,
    "The attribute 'xErrorUpper' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:xErrorUpper' of a <curve> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22008
  { SedmlCurveXErrorLowerMustBeDataGenerator,
    "The attribute 'xErrorLower' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:xErrorLower' of a <curve> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22009
  { SedmlCurveYErrorUpperMustBeDataGenerator,
    "The attribute 'yErrorUpper' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yErrorUpper' of a <curve> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22010
  { SedmlCurveYErrorLowerMustBeDataGenerator,
    "The attribute 'yErrorLower' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yErrorLower' of a <curve> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22101
  { SedmlSurfaceAllowedCoreAttributes,
    "Core attributes allowed on <surface>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <surface> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <surface>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22102
  { SedmlSurfaceAllowedCoreElements,
    "Core elements allowed on <surface>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <surface> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <surface>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22103
  { SedmlSurfaceAllowedAttributes,
    "Attributes allowed on <surface>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <surface> object must have the required attributes "
    "'sedml:xDataReference', 'sedml:yDataReference' (optional before Level 1 Version 4), and"
    "'sedml:zDataReference', and may have the optional attributes 'sedml:id', "
    "'sedml:name', "
    "'sedml:type', 'sedml:style', 'sedml:logX', 'sedml:logY', 'sedml:logZ' and "
    "'sedml:order'. No other attributes from the SBML Level 3 SED-ML namespaces "
    "are permitted on a <surface> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22104
  { SedmlSurfaceZDataReferenceMustBeDataGenerator,
    "The attribute 'zDataReference' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:zDataReference' of a <surface> object "
    "must be the identifier of an existing <dataGenerator> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22105
  { SedmlSurfaceNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <surface> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22106
  { SedmlSurfaceXDataReferenceMustBeDataGenerator,
    "The attribute 'xDataReference' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:xDataReference' of a <surface> object "
    "must be the identifier of an existing <dataGenerator> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22107
  { SedmlSurfaceYDataReferenceMustBeDataGenerator,
    "The attribute 'yDataReference' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yDataReference' of a <surface> object "
    "must be the identifier of an existing <dataGenerator> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22108
  { SedmlSurfaceTypeMustBeSurfaceTypeEnum,
    "The 'type' attribute must be SurfaceTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of a <surface> object must conform "
    "to the syntax of SBML data type 'SurfaceType' and may only take on the "
    "allowed values of 'SurfaceType' defined in SBML; that is, the value must "
    "be one of the following: 'parametricCurve', 'surfaceMesh', "
    "'surfaceContour', 'contour', 'heatMap', 'stackedCurves' or 'bar'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22109
  { SedmlSurfaceStyleMustBeStyle,
    "The attribute 'style' must point to Style object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:style' of a <surface> object must be the "
    "identifier of an existing <style> object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22110
  { SedmlSurfaceLogXMustBeBoolean,
    "The 'logX' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:logX' on a <surface> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22111
  { SedmlSurfaceLogYMustBeBoolean,
    "The 'logY' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:logY' on a <surface> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22112
  { SedmlSurfaceLogZMustBeBoolean,
    "The 'logZ' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:logZ' on a <surface> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22113
  { SedmlSurfaceOrderMustBeInteger,
    "The 'order' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:order' on a <surface> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22201
  { SedmlDataSetAllowedCoreAttributes,
    "Core attributes allowed on <dataSet>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSet> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <dataSet>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22202
  { SedmlDataSetAllowedCoreElements,
    "Core elements allowed on <dataSet>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSet> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <dataSet>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22203
  { SedmlDataSetAllowedAttributes,
    "Attributes allowed on <dataSet>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSet> object must have the required attributes 'sedml:id', "
    "'sedml:label' and 'sedml:dataReference', and may have the optional "
    "attribute 'sedml:name'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <dataSet> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22204
  { SedmlDataSetLabelMustBeString,
    "The 'label' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:label' on a <dataSet> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22205
  { SedmlDataSetDataReferenceMustBeDataGenerator,
    "The attribute 'dataReference' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:dataReference' of a <dataSet> object "
    "must be the identifier of an existing <dataGenerator> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22206
  { SedmlDataSetNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataSet> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22301
  { SedmlReportAllowedCoreAttributes,
    "Core attributes allowed on <report>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <report> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <report>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22302
  { SedmlReportAllowedCoreElements,
    "Core elements allowed on <report>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <report> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <report>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22303
  { SedmlReportAllowedElements,
    "Elements allowed on <report>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <report> object may contain one and only one instance of the "
    "<listOfDataSets> element. No other elements from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <report> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22304
  { SedmlReportLODataSetsAllowedCoreElements,
    "Core elements allowed on <listOfDataSets>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDataSets> container object may only contain "
    "<dataSet> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22305
  { SedmlReportLODataSetsAllowedCoreAttributes,
    "Core attributes allowed on <listOfDataSets>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfDataSets> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDataSets> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22401
  { SedmlAlgorithmParameterAllowedCoreAttributes,
    "Core attributes allowed on <algorithmParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithmParameter> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <algorithmParameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22402
  { SedmlAlgorithmParameterAllowedCoreElements,
    "Core elements allowed on <algorithmParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithmParameter> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <algorithmParameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22403
  { SedmlAlgorithmParameterAllowedAttributes,
    "Attributes allowed on <algorithmParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithmParameter> object must have the required attributes "
    "'sedml:kisaoID' and 'sedml:value'. No other attributes from the SBML Level "
    "3 SED-ML namespaces are permitted on an <algorithmParameter> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22404
  { SedmlAlgorithmParameterAllowedElements,
    "Elements allowed on <algorithmParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <algorithmParameter> object may contain one and only one instance of "
    "the <listOfAlgorithmParameters> element. No other elements from the SBML "
    "Level 3 SED-ML namespaces are permitted on an <algorithmParameter> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22405
  { SedmlAlgorithmParameterKisaoIDMustBeString,
    "The 'kisaoID' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:kisaoID' on an <algorithmParameter> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22406
  { SedmlAlgorithmParameterValueMustBeString,
    "The 'value' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:value' on an <algorithmParameter> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22407
  { SedmlAlgorithmParameterLOAlgorithmParametersAllowedCoreElements,
    "Core elements allowed on <listOfAlgorithmParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAlgorithmParameters> container object may only "
    "contain <algorithmParameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22408
  { SedmlAlgorithmParameterLOAlgorithmParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfAlgorithmParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAlgorithmParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfAlgorithmParameters> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22501
  { SedmlRangeAllowedCoreAttributes,
    "Core attributes allowed on <range>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <range> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <range>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22502
  { SedmlRangeAllowedCoreElements,
    "Core elements allowed on <range>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <range> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <range>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22503
  { SedmlRangeAllowedAttributes,
    "Attributes allowed on <range>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <range> object must have the required attribute 'sedml:id'. No other "
    "attributes from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<range> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22601
  { SedmlChangeXMLAllowedCoreAttributes,
    "Core attributes allowed on <changeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeXML> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <changeXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22602
  { SedmlChangeXMLAllowedCoreElements,
    "Core elements allowed on <changeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeXML> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <changeXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22603
  { SedmlChangeXMLAllowedElements,
    "Elements allowed on <changeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <changeXML> object may contain one and only one instance of the XMLNode "
    "element. No other elements from the SBML Level 3 SED-ML namespaces are "
    "permitted on a <changeXML> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22701
  { SedmlRemoveXMLAllowedCoreAttributes,
    "Core attributes allowed on <removeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <removeXML> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <removeXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22702
  { SedmlRemoveXMLAllowedCoreElements,
    "Core elements allowed on <removeXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <removeXML> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <removeXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22801
  { SedmlSetValueAllowedCoreAttributes,
    "Core attributes allowed on <setValue>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <setValue> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <setValue>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22802
  { SedmlSetValueAllowedCoreElements,
    "Core elements allowed on <setValue>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <setValue> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <setValue>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22803
  { SedmlSetValueAllowedAttributes,
    "Attributes allowed on <setValue>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <setValue> object must have the required attribute "
    "'sedml:modelReference', and may have the optional attributes "
    "'sedml:symbol', 'sedml:target' and 'sedml:range'. No other attributes from "
    "the SBML Level 3 SED-ML namespaces are permitted on a <setValue> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22804
  { SedmlSetValueAllowedElements,
    "Elements allowed on <setValue>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <setValue> object may contain one and only one instance of the ASTNode "
    "element. No other elements from the SBML Level 3 SED-ML namespaces are "
    "permitted on a <setValue> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22805
  { SedmlSetValueModelReferenceMustBeModel,
    "The attribute 'modelReference' must point to Model object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of a <setValue> object "
    "must be the identifier of an existing <model> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22806
  { SedmlSetValueSymbolMustBeString,
    "The 'symbol' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbol' on a <setValue> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22807
  { SedmlSetValueTargetMustBeString,
    "The 'target' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on a <setValue> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22808
  { SedmlSetValueRangeMustBeRange,
    "The attribute 'range' must point to Range object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:range' of a <setValue> object must be "
    "the identifier of an existing <range> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22901
  { SedmlUniformRangeAllowedCoreAttributes,
    "Core attributes allowed on <uniformRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformRange> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <uniformRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22902
  { SedmlUniformRangeAllowedCoreElements,
    "Core elements allowed on <uniformRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformRange> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <uniformRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22903
  { SedmlUniformRangeAllowedAttributes,
    "Attributes allowed on <uniformRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <uniformRange> object must have the required attributes 'sedml:start', "
    "'sedml:end', 'sedml:numberOfPoints' and 'sedml:type'. No other attributes "
    "from the SBML Level 3 SED-ML namespaces are permitted on an <uniformRange> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22904
  { SedmlUniformRangeStartMustBeDouble,
    "The 'start' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:start' on an <uniformRange> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22905
  { SedmlUniformRangeEndMustBeDouble,
    "The 'end' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:end' on an <uniformRange> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22906
  { SedmlUniformRangeNumberOfPointsMustBeInteger,
    "The 'numberOfPoints' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numberOfPoints' on an <uniformRange> must have a "
    "value of data type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 22907
  { SedmlUniformRangeTypeMustBeString,
    "The 'type' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:type' on an <uniformRange> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23001
  { SedmlVectorRangeAllowedCoreAttributes,
    "Core attributes allowed on <vectorRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <vectorRange> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <vectorRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23002
  { SedmlVectorRangeAllowedCoreElements,
    "Core elements allowed on <vectorRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <vectorRange> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <vectorRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23003
  { SedmlVectorRangeAllowedAttributes,
    "Attributes allowed on <vectorRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <vectorRange> object may have the optional attribute 'sedml:value'. No "
    "other attributes from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<vectorRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23004
  { SedmlVectorRangeValueMustBeString,
    "The 'value' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:value' of a <vectorRange> object must be "
    "an vector of values of type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23101
  { SedmlFunctionalRangeAllowedCoreAttributes,
    "Core attributes allowed on <functionalRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <functionalRange> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <functionalRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23102
  { SedmlFunctionalRangeAllowedCoreElements,
    "Core elements allowed on <functionalRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <functionalRange> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <functionalRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23103
  { SedmlFunctionalRangeAllowedAttributes,
    "Attributes allowed on <functionalRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <functionalRange> object must have the required attribute 'sedml:range'. "
    "No other attributes from the SBML Level 3 SED-ML namespaces are permitted "
    "on a <functionalRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23104
  { SedmlFunctionalRangeAllowedElements,
    "Elements allowed on <functionalRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <functionalRange> object may contain one and only one instance of each "
    "of the <listOfVariables,> <listOfParameters> and ASTNode elements. No "
    "other elements from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<functionalRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23105
  { SedmlFunctionalRangeRangeMustBeRange,
    "The attribute 'range' must point to Range object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:range' of a <functionalRange> object "
    "must be the identifier of an existing <range> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23106
  { SedmlFunctionalRangeLOVariablesAllowedCoreElements,
    "Core elements allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfVariables> container object may only contain "
    "<variable> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23107
  { SedmlFunctionalRangeLOParametersAllowedCoreElements,
    "Core elements allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfParameters> container object may only contain "
    "<parameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23108
  { SedmlFunctionalRangeLOVariablesAllowedCoreAttributes,
    "Core attributes allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfVariables> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfVariables> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23109
  { SedmlFunctionalRangeLOParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfParameters> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfParameters> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23201
  { SedmlSubTaskAllowedCoreAttributes,
    "Core attributes allowed on <subTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subTask> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <subTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23202
  { SedmlSubTaskAllowedCoreElements,
    "Core elements allowed on <subTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subTask> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <subTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23203
  { SedmlSubTaskAllowedAttributes,
    "Attributes allowed on <subTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subTask> object must have the required attributes 'sedml:order' and "
    "'sedml:task'. No other attributes from the SBML Level 3 SED-ML namespaces "
    "are permitted on a <subTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23204
  { SedmlSubTaskOrderMustBeInteger,
    "The 'order' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:order' on a <subTask> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23205
  { SedmlSubTaskTaskMustBeAbstractTask,
    "The attribute 'task' must point to AbstractTask object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:task' of a <subTask> object must be the "
    "identifier of an existing <abstractTask> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23206
  { SedmlSubTaskAllowedElements,
    "Elements allowed on <subTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subTask> object may contain one and only one instance of "
    "the <listOfChanges> element. No "
    "other elements from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<repeatedTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23301
  { SedmlOneStepAllowedCoreAttributes,
    "Core attributes allowed on <oneStep>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <oneStep> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <oneStep>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23302
  { SedmlOneStepAllowedCoreElements,
    "Core elements allowed on <oneStep>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <oneStep> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <oneStep>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23303
  { SedmlOneStepAllowedAttributes,
    "Attributes allowed on <oneStep>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <oneStep> object must have the required attribute 'sedml:step'. No "
    "other attributes from the SBML Level 3 SED-ML namespaces are permitted on "
    "an <oneStep> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23304
  { SedmlOneStepStepMustBeDouble,
    "The 'step' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:step' on an <oneStep> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23401
  { SedmlSteadyStateAllowedCoreAttributes,
    "Core attributes allowed on <steadyState>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <steadyState> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <steadyState>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23402
  { SedmlSteadyStateAllowedCoreElements,
    "Core elements allowed on <steadyState>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <steadyState> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <steadyState>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23403
  { SedmlAnalysisAllowedCoreAttributes,
    "Core attributes allowed on <analysis>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <Analysis> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <analysis>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23403
  { SedmlAnalysisAllowedCoreElements,
    "Core elements allowed on <analysis>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <analysis> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <analysis>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23501
  { SedmlRepeatedTaskAllowedCoreAttributes,
    "Core attributes allowed on <repeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <repeatedTask> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <repeatedTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23502
  { SedmlRepeatedTaskAllowedCoreElements,
    "Core elements allowed on <repeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <repeatedTask> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <repeatedTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23503
  { SedmlRepeatedTaskAllowedAttributes,
    "Attributes allowed on <repeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <repeatedTask> object may have the optional attributes 'sedml:rangeId' "
    "and 'sedml:resetModel', and may starting in level 1 version 4 contain "
    "the optional attribute 'sedml:concatenate'. No other attributes from the "
    "SED-ML namespaces are permitted on a <repeatedTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23504
  { SedmlRepeatedTaskAllowedElements,
    "Elements allowed on <repeatedTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <repeatedTask> object may contain one and only one instance of each of "
    "the <listOfRanges,> <listOfSetValues> and <listOfSubTasks> elements. No "
    "other elements from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<repeatedTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23505
  { SedmlRepeatedTaskRangeMustBeRange,
    "The attribute 'rangeId' must point to Range object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:range' of a <repeatedTask> object must "
    "be the identifier of an existing <range> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23506
  { SedmlRepeatedTaskResetModelMustBeBoolean,
    "The 'resetModel' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:resetModel' on a <repeatedTask> must have a value of "
    "data type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23507
  { SedmlRepeatedTaskLORangesAllowedCoreElements,
    "Core elements allowed on <listOfRanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfRanges> container object may only contain <range> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23508
  { SedmlRepeatedTaskLOSetValuesAllowedCoreElements,
    "Core elements allowed on <listOfSetValues>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSetValues> container object may only contain "
    "<setValue> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23509
  { SedmlRepeatedTaskLOSubTasksAllowedCoreElements,
    "Core elements allowed on <listOfSubTasks>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSubTasks> container object may only contain "
    "<subTask> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23510
  { SedmlRepeatedTaskLORangesAllowedCoreAttributes,
    "Core attributes allowed on <listOfRanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfRanges> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfRanges> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23511
  { SedmlRepeatedTaskLOSetValuesAllowedCoreAttributes,
    "Core attributes allowed on <listOfSetValues>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSetValues> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSetValues> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23512
  { SedmlRepeatedTaskLOSubTasksAllowedCoreAttributes,
    "Core attributes allowed on <listOfSubTasks>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSubTasks> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSubTasks> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23513
  { SedmlRepeatedTaskConcatenateMustBeBoolean,
    "The 'concatenate' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:concatenate' on a <repeatedTask> must have a value of "
    "data type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23601
  { SedmlComputeChangeAllowedCoreAttributes,
    "Core attributes allowed on <computeChange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <computeChange> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <computeChange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23602
  { SedmlComputeChangeAllowedCoreElements,
    "Core elements allowed on <computeChange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <computeChange> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <computeChange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23603
  { SedmlComputeChangeAllowedElements,
    "Elements allowed on <computeChange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <computeChange> object may contain one and only one instance of each of "
    "the ASTNode, <listOfVariables> and <listOfParameters> elements. No other "
    "elements from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<computeChange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23604
  { SedmlComputeChangeLOVariablesAllowedCoreElements,
    "Core elements allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfVariables> container object may only contain "
    "<variable> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23605
  { SedmlComputeChangeLOParametersAllowedCoreElements,
    "Core elements allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfParameters> container object may only contain "
    "<parameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23606
  { SedmlComputeChangeLOVariablesAllowedCoreAttributes,
    "Core attributes allowed on <listOfVariables>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfVariables> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfVariables> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23607
  { SedmlComputeChangeLOParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfParameters> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfParameters> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23701
  { SedmlDataDescriptionAllowedCoreAttributes,
    "Core attributes allowed on <dataDescription>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataDescription> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <dataDescription>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23702
  { SedmlDataDescriptionAllowedCoreElements,
    "Core elements allowed on <dataDescription>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataDescription> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <dataDescription>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23703
  { SedmlDataDescriptionAllowedAttributes,
    "Attributes allowed on <dataDescription>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataDescription> object must have the required attribute 'sedml:id', "
    "and may have the optional attributes 'sedml:name', 'sedml:format' and "
    "'sedml:source'. No other attributes from the SBML Level 3 SED-ML namespaces "
    "are permitted on a <dataDescription> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23704
  { SedmlDataDescriptionAllowedElements,
    "Elements allowed on <dataDescription>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataDescription> object may contain one and only one instance of each "
    "of the SedDimensionDescription and <listOfDataSources> elements. No other "
    "elements from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<dataDescription> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23705
  { SedmlDataDescriptionNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataDescription> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23706
  { SedmlDataDescriptionFormatMustBeString,
    "The 'format' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:format' on a <dataDescription> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23707
  { SedmlDataDescriptionSourceMustBeString,
    "The 'source' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <dataDescription> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23708
  { SedmlDataDescriptionLODataSourcesAllowedCoreElements,
    "Core elements allowed on <listOfDataSources>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDataSources> container object may only contain "
    "<dataSource> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23709
  { SedmlDataDescriptionLODataSourcesAllowedCoreAttributes,
    "Core attributes allowed on <listOfDataSources>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfDataSources> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDataSources> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23801
  { SedmlDataSourceAllowedCoreAttributes,
    "Core attributes allowed on <dataSource>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSource> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <dataSource>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23802
  { SedmlDataSourceAllowedCoreElements,
    "Core elements allowed on <dataSource>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSource> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <dataSource>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23803
  { SedmlDataSourceAllowedAttributes,
    "Attributes allowed on <dataSource>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSource> object must have the required attribute 'sedml:id', and may "
    "have the optional attributes 'sedml:name' and 'sedml:indexSet'. No other "
    "attributes from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<dataSource> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23804
  { SedmlDataSourceAllowedElements,
    "Elements allowed on <dataSource>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataSource> object may contain one and only one instance of the "
    "<listOfSlices> element. No other elements from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <dataSource> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23805
  { SedmlDataSourceNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <dataSource> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23806
  { SedmlDataSourceIndexSetMustBeSId,
    "The attribute 'indexSet' must point to SId object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:indexSet' of a <dataSource> object must "
    "be the identifier of an existing < object> defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23807
  { SedmlDataSourceLOSlicesAllowedCoreElements,
    "Core elements allowed on <listOfSlices>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSlices> container object may only contain <slice> "
    "objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23808
  { SedmlDataSourceLOSlicesAllowedCoreAttributes,
    "Core attributes allowed on <listOfSlices>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSlices> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfSlices> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23901
  { SedmlSliceAllowedCoreAttributes,
    "Core attributes allowed on <slice>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <slice> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <slice>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23902
  { SedmlSliceAllowedCoreElements,
    "Core elements allowed on <slice>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <slice> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <slice>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23903
  { SedmlSliceAllowedAttributes,
    "Attributes allowed on <slice>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <slice> object must have the required attributes 'sedml:reference' and "
    "'sedml:value', and may have the optional attributes 'sedml:index', "
    "'sedml:startIndex' and 'sedml:endIndex'. No other attributes from the SBML "
    "Level 3 SED-ML namespaces are permitted on a <slice> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23904
  { SedmlSliceReferenceMustBeSId,
    "The attribute 'reference' must point to SId object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:reference' of a <slice> object must be "
    "the identifier of an existing < object> defined in the enclosing <model> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23905
  { SedmlSliceValueMustBeString,
    "The 'value' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:value' on a <slice> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23906
  { SedmlSliceIndexMustBeSId,
    "The attribute 'index' must point to SId object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:index' of a <slice> object must be the "
    "identifier of an existing < object> defined in the enclosing <model> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23907
  { SedmlSliceStartIndexMustBeInteger,
    "The 'startIndex' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:startIndex' on a <slice> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 23908
  { SedmlSliceEndIndexMustBeInteger,
    "The 'endIndex' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:endIndex' on a <slice> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24001
  { SedmlParameterEstimationTaskAllowedCoreAttributes,
    "Core attributes allowed on <parameterEstimationTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationTask> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <parameterEstimationTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24002
  { SedmlParameterEstimationTaskAllowedCoreElements,
    "Core elements allowed on <parameterEstimationTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationTask> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <parameterEstimationTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24003
  { SedmlParameterEstimationTaskAllowedElements,
    "Elements allowed on <parameterEstimationTask>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationTask> object must contain one and only one instance "
    "of each of the SedAlgorithm, SedObjective, <listOfAdjustableParameters> "
    "and <listOfFitExperiments> elements. No other elements from the SBML "
    "Level 3 SED-ML namespaces are permitted on a <parameterEstimationTask> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24004
  { SedmlParameterEstimationTaskLOAdjustableParametersAllowedCoreElements,
    "Core elements allowed on <listOfAdjustableParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfAdjustableParameters> container object may only "
    "contain <adjustableParameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24005
  { SedmlParameterEstimationTaskLOFitExperimentsAllowedCoreElements,
    "Core elements allowed on <listOfFitExperiments>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfFitExperiments> container object may only contain "
    "<fitExperiment> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24006
  { SedmlParameterEstimationTaskLOAdjustableParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfAdjustableParameters>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfAdjustableParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfAdjustableParameters> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24007
  { SedmlParameterEstimationTaskLOFitExperimentsAllowedCoreAttributes,
    "Core attributes allowed on <listOfFitExperiments>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfFitExperiments> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfFitExperiments> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24101
  { SedmlObjectiveAllowedCoreAttributes,
    "Core attributes allowed on <objective>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <objective> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <objective>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24102
  { SedmlObjectiveAllowedCoreElements,
    "Core elements allowed on <objective>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <objective> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <objective>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24201
  { SedmlLeastSquareObjectiveFunctionAllowedCoreAttributes,
    "Core attributes allowed on <leastSquareObjectiveFunction>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <leastSquareObjectiveFunction> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a "
    "<leastSquareObjectiveFunction>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24202
  { SedmlLeastSquareObjectiveFunctionAllowedCoreElements,
    "Core elements allowed on <leastSquareObjectiveFunction>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <leastSquareObjectiveFunction> object may have the optional SBML Level 3 "
    "Core subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a "
    "<leastSquareObjectiveFunction>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24301
  { SedmlAdjustableParameterAllowedCoreAttributes,
    "Core attributes allowed on <adjustableParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <adjustableParameter> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <adjustableParameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24302
  { SedmlAdjustableParameterAllowedCoreElements,
    "Core elements allowed on <adjustableParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <adjustableParameter> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <adjustableParameter>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24303
  { SedmlAdjustableParameterAllowedAttributes,
    "Attributes allowed on <adjustableParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <adjustableParameter> object may have the optional attributes "
    "'sedml:initialValue', 'sedml:modelReference' and 'sedml:target'. No other "
    "attributes from the SBML Level 3 SED-ML namespaces are permitted on an "
    "<adjustableParameter> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24304
  { SedmlAdjustableParameterAllowedElements,
    "Elements allowed on <adjustableParameter>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <adjustableParameter> object must contain one and only one instance of "
    "the SedBounds element, and may contain one and only one instance of the "
    "<listOfExperimentReferences> element. No other elements from the SBML Level 3 "
    "SED-ML namespaces are permitted on an <adjustableParameter> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24305
  { SedmlAdjustableParameterInitialValueMustBeDouble,
    "The 'initialValue' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:initialValue' on an <adjustableParameter> must have a "
    "value of data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24306
  { SedmlAdjustableParameterModelReferenceMustBeModel,
    "The attribute 'modelReference' must point to Model object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of an "
    "<adjustableParameter> object must be the identifier of an existing <model> "
    "object defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24307
  { SedmlAdjustableParameterTargetMustBeString,
    "The 'target' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on an <adjustableParameter> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24308
  { SedmlAdjustableParameterLOExperimentReferencesAllowedCoreElements,
    "Core elements allowed on <listOfExperimentReferences>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfExperimentReferences> container object may only contain "
    "<experimentReference> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24309
  { SedmlAdjustableParameterLOExperimentReferencesAllowedCoreAttributes,
    "Core attributes allowed on <listOfExperimentReferences>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfExperimentReferences> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfExperimentReferences> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24401
  { SedmlExperimentReferenceAllowedCoreAttributes,
    "Core attributes allowed on <experimentReference>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <experimentReference> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <experimentReference>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24402
  { SedmlExperimentReferenceAllowedCoreElements,
    "Core elements allowed on <experimentReference>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <experimentReference> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <experimentReference>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24403
  { SedmlExperimentReferenceAllowedAttributes,
    "Attributes allowed on <experimentReference>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <experimentReference> object may have the optional attribute "
    "'sedml:experimentId'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on an <experimentReference> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24404
  { SedmlExperimentReferenceExperimentIdMustBeFitExperiment,
    "The attribute 'experimentId' must point to FitExperiment object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:experimentId' of an <experimentReference> "
    "object must be the identifier of an existing <fitExperiment> object "
    "defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24501
  { SedmlFitExperimentAllowedCoreAttributes,
    "Core attributes allowed on <fitExperiment>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitExperiment> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <fitExperiment>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24502
  { SedmlFitExperimentAllowedCoreElements,
    "Core elements allowed on <fitExperiment>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitExperiment> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <fitExperiment>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24503
  { SedmlFitExperimentAllowedAttributes,
    "Attributes allowed on <fitExperiment>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitExperiment> object may have the optional attributes 'sedml:id' and "
    "'sedml:type'. No other attributes from the SBML Level 3 SED-ML namespaces "
    "are permitted on a <fitExperiment> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24504
  { SedmlFitExperimentAllowedElements,
    "Elements allowed on <fitExperiment>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitExperiment> object may contain one and only one instance of each of "
    "the SedAlgorithm and <listOfFitMappings> elements. No other elements from "
    "the SBML Level 3 SED-ML namespaces are permitted on a <fitExperiment> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24505
  { SedmlFitExperimentTypeMustBeExperimentTypeEnum,
    "The 'type' attribute must be ExperimentTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of a <fitExperiment> object must "
    "conform to the syntax of SBML data type 'ExperimentType' and may only take "
    "on the allowed values of 'ExperimentType' defined in SBML; that is, the "
    "value must be one of the following: 'steadyState' or 'timeCourse'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24506
  { SedmlFitExperimentLOFitMappingsAllowedCoreElements,
    "Core elements allowed on <listOfFitMappings>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfFitMappings> container object may only contain "
    "<fitMapping> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24507
  { SedmlFitExperimentLOFitMappingsAllowedCoreAttributes,
    "Core attributes allowed on <listOfFitMappings>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfFitMappings> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfFitMappings> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24601
  { SedmlFitMappingAllowedCoreAttributes,
    "Core attributes allowed on <fitMapping>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitMapping> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <fitMapping>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24602
  { SedmlFitMappingAllowedCoreElements,
    "Core elements allowed on <fitMapping>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitMapping> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <fitMapping>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24603
  { SedmlFitMappingAllowedAttributes,
    "Attributes allowed on <fitMapping>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fitMapping> object must have the required attributes "
    "'sedml:dataSource', 'sedml:target' and 'sedml:type', and may have the "
    "optional attributes 'sedml:weight' and 'sedml:pointWeight'. No other "
    "attributes from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<fitMapping> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24604
  { SedmlFitMappingDataSourceMustBeDataSource,
    "The attribute 'dataSource' must point to DataSource object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:dataSource' of a <fitMapping> object "
    "must be the identifier of an existing <dataSource> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24605
  { SedmlFitMappingTargetMustBeDataGenerator,
    "The attribute 'target' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:target' of a <fitMapping> object must be "
    "the identifier of an existing <dataGenerator> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24606
  { SedmlFitMappingTypeMustBeMappingTypeEnum,
    "The 'type' attribute must be MappingTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of a <fitMapping> object must "
    "conform to the syntax of SBML data type 'MappingType' and may only take on "
    "the allowed values of 'MappingType' defined in SBML; that is, the value "
    "must be one of the following: 'time', 'experimentalCondition' or "
    "'observable'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24607
  { SedmlFitMappingWeightMustBeDouble,
    "The 'weight' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:weight' on a <fitMapping> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24608
  { SedmlFitMappingPointWeightMustBeDataSource,
    "The attribute 'pointWeight' must point to DataSource object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:pointWeight' of a <fitMapping> object "
    "must be the identifier of an existing <dataSource> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24701
  { SedmlBoundsAllowedCoreAttributes,
    "Core attributes allowed on <bounds>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <bounds> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <bounds>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24702
  { SedmlBoundsAllowedCoreElements,
    "Core elements allowed on <bounds>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <bounds> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <bounds>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24703
  { SedmlBoundsAllowedAttributes,
    "Attributes allowed on <bounds>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <bounds> object may have the optional attributes 'sedml:lowerBound', "
    "'sedml:upperBound' and 'sedml:scale'. No other attributes from the SBML "
    "Level 3 SED-ML namespaces are permitted on a <bounds> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24704
  { SedmlBoundsLowerBoundMustBeDouble,
    "The 'lowerBound' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:lowerBound' on a <bounds> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24705
  { SedmlBoundsUpperBoundMustBeDouble,
    "The 'upperBound' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:upperBound' on a <bounds> must have a value of data "
    "type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24706
  { SedmlBoundsScaleMustBeScaleTypeEnum,
    "The 'scale' attribute must be ScaleTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:scale' of a <bounds> object must conform "
    "to the syntax of SBML data type 'ScaleType' and may only take on the "
    "allowed values of 'ScaleType' defined in SBML; that is, the value must be "
    "one of the following: 'lin', 'log' or 'log10'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24801
  { SedmlFigureAllowedCoreAttributes,
    "Core attributes allowed on <figure>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <figure> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <figure>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24802
  { SedmlFigureAllowedCoreElements,
    "Core elements allowed on <figure>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <figure> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <figure>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24803
  { SedmlFigureAllowedAttributes,
    "Attributes allowed on <figure>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <figure> object may have the optional attributes 'sedml:numRows' and "
    "'sedml:numCols'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <figure> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24804
  { SedmlFigureAllowedElements,
    "Elements allowed on <figure>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <figure> object may contain one and only one instance of the "
    "<listOfSubPlots> element. No other elements from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <figure> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24805
  { SedmlFigureNumRowsMustBeInteger,
    "The 'numRows' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numRows' on a <figure> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24806
  { SedmlFigureNumColsMustBeInteger,
    "The 'numCols' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:numCols' on a <figure> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24807
  { SedmlFigureLOSubPlotsAllowedCoreElements,
    "Core elements allowed on <listOfSubPlots>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfSubPlots> container object may only contain "
    "<subPlot> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24808
  { SedmlFigureLOSubPlotsAllowedCoreAttributes,
    "Core attributes allowed on <listOfSubPlots>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <listOfSubPlots> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfSubPlots> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24901
  { SedmlSubPlotAllowedCoreAttributes,
    "Core attributes allowed on <subPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subPlot> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <subPlot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24902
  { SedmlSubPlotAllowedCoreElements,
    "Core elements allowed on <subPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subPlot> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <subPlot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24903
  { SedmlSubPlotAllowedAttributes,
    "Attributes allowed on <subPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <subPlot> object must have the required attributes 'sedml:plot', "
    "'sedml:row' and 'sedml:col', and may have the optional attributes "
    "'sedml:rowSpan' and 'sedml:colSpan'. No other attributes from the SBML "
    "Level 3 SED-ML namespaces are permitted on a <subPlot> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24904
  { SedmlSubPlotPlotMustBePlot,
    "The attribute 'plot' must point to Plot object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:plot' of a <subPlot> object must be the "
    "identifier of an existing <plot> object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24905
  { SedmlSubPlotRowMustBeInteger,
    "The 'row' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:row' on a <subPlot> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24906
  { SedmlSubPlotColMustBeInteger,
    "The 'col' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:col' on a <subPlot> must have a value of data type "
    "'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24907
  { SedmlSubPlotRowSpanMustBeInteger,
    "The 'rowSpan' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:rowSpan' on a <subPlot> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 24908
  { SedmlSubPlotColSpanMustBeInteger,
    "The 'colSpan' attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:colSpan' on a <subPlot> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25001
  { SedmlAxisAllowedCoreAttributes,
    "Core attributes allowed on <axis>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <axis> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <axis>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25002
  { SedmlAxisAllowedCoreElements,
    "Core elements allowed on <axis>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <axis> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <axis>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25003
  { SedmlAxisAllowedAttributes,
    "Attributes allowed on <axis>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "An <axis> object must have the required attribute 'sedml:type', and may "
    "have the optional attributes 'sedml:min', 'sedml:max', 'sedml:grid' and "
    "'sedml:style'. No other attributes from the SBML Level 3 SED-ML namespaces "
    "are permitted on an <axis> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25004
  { SedmlAxisTypeMustBeAxisTypeEnum,
    "The 'type' attribute must be AxisTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of an <axis> object must conform "
    "to the syntax of SBML data type 'AxisType' and may only take on the "
    "allowed values of 'AxisType' defined in SBML; that is, the value must be "
    "one of the following: 'linear' or 'log10'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25005
  { SedmlAxisMinMustBeDouble,
    "The 'min' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:min' on an <axis> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25006
  { SedmlAxisMaxMustBeDouble,
    "The 'max' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:max' on an <axis> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25007
  { SedmlAxisGridMustBeBoolean,
    "The 'grid' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:grid' on an <axis> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25008
  { SedmlAxisStyleMustBeStyle,
    "The attribute 'style' must point to Style object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:style' of an <axis> object must be the "
    "identifier of an existing <style> object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25007
  { SedmlAxisReverseMustBeBoolean,
    "The 'reverse' attribute must be Boolean.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:reverse' on an <axis> must have a value of data type "
    "'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25101
  { SedmlStyleAllowedCoreAttributes,
    "Core attributes allowed on <style>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <style> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <style>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25102
  { SedmlStyleAllowedCoreElements,
    "Core elements allowed on <style>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <style> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <style>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25103
  { SedmlStyleAllowedAttributes,
    "Attributes allowed on <style>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <style> object must have the required attribute 'sedml:id', and may have "
    "the optional attribute 'sedml:baseStyle'. No other attributes from the "
    "SBML Level 3 SED-ML namespaces are permitted on a <style> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25104
  { SedmlStyleAllowedElements,
    "Elements allowed on <style>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <style> object may contain one and only one instance of each of the "
    "SedLine, SedMarker and SedFill elements. No other elements from the SBML "
    "Level 3 SED-ML namespaces are permitted on a <style> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25105
  { SedmlStyleBaseStyleMustBeStyle,
    "The attribute 'baseStyle' must point to Style object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:baseStyle' of a <style> object must be "
    "the identifier of an existing <style> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25201
  { SedmlLineAllowedCoreAttributes,
    "Core attributes allowed on <line>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <line> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <line>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25202
  { SedmlLineAllowedCoreElements,
    "Core elements allowed on <line>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <line> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <line>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25203
  { SedmlLineAllowedAttributes,
    "Attributes allowed on <line>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <line> object may have the optional attributes 'sedml:type', "
    "'sedml:color' and 'sedml:thickness'. No other attributes from the SBML "
    "Level 3 SED-ML namespaces are permitted on a <line> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25204
  { SedmlLineTypeMustBeLineTypeEnum,
    "The 'style' attribute must be LineTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of a <line> object must conform "
    "to the syntax of SBML data type 'LineType' and may only take on the "
    "allowed values of 'LineType' defined in SBML; that is, the value must be "
    "one of the following: 'none', 'solid', 'dash', 'dot', 'dashDot' or "
    "'dashDotDot'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25205
  { SedmlLineColorMustBeString,
    "The 'color' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:color' on a <line> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25206
  { SedmlLineThicknessMustBeDouble,
    "The 'thickness' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:thickness' on a <line> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25301
  { SedmlMarkerAllowedCoreAttributes,
    "Core attributes allowed on <marker>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <marker> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <marker>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25302
  { SedmlMarkerAllowedCoreElements,
    "Core elements allowed on <marker>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <marker> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <marker>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25303
  { SedmlMarkerAllowedAttributes,
    "Attributes allowed on <marker>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <marker> object may have the optional attributes 'sedml:size', "
    "'sedml:style', 'sedml:fill', 'sedml:lineColor' and 'sedml:lineThickness'. "
    "No other attributes from the SBML Level 3 SED-ML namespaces are permitted "
    "on a <marker> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25304
  { SedmlMarkerSizeMustBeDouble,
    "The 'size' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:size' on a <marker> must have a value of data type "
    "'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25305
  { SedmlMarkerTypeMustBeMarkerTypeEnum,
    "The 'style' attribute must be MarkerTypeEnum.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:type' of a <marker> object must conform "
    "to the syntax of SBML data type 'MarkerType' and may only take on the "
    "allowed values of 'MarkerType' defined in SBML; that is, the value must be "
    "one of the following: 'none', 'square', 'circle', 'diamond', 'xCross', "
    "'plus', 'star', 'triangleUp', 'triangleDown', 'triangleLeft', "
    "'triangleRight', 'hDash' or 'vDash'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25306
  { SedmlMarkerFillMustBeString,
    "The 'fill' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:fill' on a <marker> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25307
  { SedmlMarkerLineColorMustBeString,
    "The 'lineColor' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:lineColor' on a <marker> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25308
  { SedmlMarkerLineThicknessMustBeDouble,
    "The 'lineThickness' attribute must be Double.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:lineThickness' on a <marker> must have a value of "
    "data type 'double'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25401
  { SedmlFillAllowedCoreAttributes,
    "Core attributes allowed on <fill>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fill> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <fill>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25402
  { SedmlFillAllowedCoreElements,
    "Core elements allowed on <fill>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fill> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <fill>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25403
  { SedmlFillAllowedAttributes,
    "Attributes allowed on <fill>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <fill> object must have the required attribute 'sedml:color'. No other attributes from "
    "the SBML Level 3 SED-ML namespaces are permitted on a <fill> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25404
  { SedmlFillColorMustBeString,
    "The 'color' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:color' on a <fill> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25501
  { SedmlDependentVariableAllowedCoreAttributes,
    "Core attributes allowed on <dependentVariable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dependentVariable> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <dependentVariable>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25502
  { SedmlDependentVariableAllowedCoreElements,
    "Core elements allowed on <dependentVariable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dependentVariable> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <dependentVariable>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25503
  { SedmlDependentVariableAllowedAttributes,
    "Attributes allowed on <dependentVariable>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dependentVariable> object must have the required attribute "
    "'sedml:term', and may have the optional attributes 'sedml:targetTwo' and "
    "'sedml:symbolTwo'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <dependentVariable> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25504
  { SedmlDependentVariableTermMustBeString,
    "The 'term' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:term' on a <dependentVariable> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25505
  { SedmlDependentVariableTarget2MustBeString,
    "The 'target2' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:targetTwo' on a <dependentVariable> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25506
  { SedmlDependentVariableSymbol2MustBeString,
    "The 'symbol2' attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbolTwo' on a <dependentVariable> must have a value "
    "of data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25601
  { SedmlAppliedDimensionAllowedCoreAttributes,
    "Core attributes allowed on <appliedDimension>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <appliedDimension> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <appliedDimension>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25602
  { SedmlAppliedDimensionAllowedCoreElements,
    "Core elements allowed on <appliedDimension>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <appliedDimension> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <appliedDimension>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25603
  { SedmlAppliedDimensionAllowedAttributes,
    "Attributes allowed on <appliedDimension>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <appliedDimension> object may have the optional attributes "
    "'sedml:target' and 'sedml:dimensionTarget'. No other attributes from the "
    "SBML Level 3 SED-ML namespaces are permitted on a <appliedDimension> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25604
  { SedmlAppliedDimensionTargetMustBeSId,
    "The attribute 'target' must point to SId object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:target' of a <appliedDimension> object "
    "must be the identifier of an existing < object> defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25605
  { SedmlAppliedDimensionDimensionTargetMustBeSId,
    "The attribute 'dimensionTarget' must point to SId object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:dimensionTarget' of a "
    "<appliedDimension> object must be the identifier of an existing < "
    "object> defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25701
  { SedmlDataRangeAllowedCoreAttributes,
    "Core attributes allowed on <dataRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataRange> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <dataRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25702
  { SedmlDataRangeAllowedCoreElements,
    "Core elements allowed on <dataRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataRange> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <dataRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25703
  { SedmlDataRangeAllowedAttributes,
    "Attributes allowed on <dataRange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <dataRange> object must have the required attribute 'sedml:sourceReference'. "
    "No other attributes from the SBML Level 3 SED-ML namespaces are permitted "
    "on a <dataRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25704
  { SedmlDataRangeSourceReferenceMustBeSId,
    "The attribute 'sourceReference' must point to SId object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:sourceReference' of a <dataRange> object must "
    "be the identifier of an existing < object> defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25901
  { SedmlShadedAreaAllowedCoreAttributes,
    "Core attributes allowed on <shadedArea>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <shadedArea> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <shadedArea>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25902
  { SedmlShadedAreaAllowedCoreElements,
    "Core elements allowed on <shadedArea>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <shadedArea> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <shadedArea>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25903
  { SedmlShadedAreaAllowedAttributes,
    "Attributes allowed on <shadedArea>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <shadedArea> object must have the required attributes "
    "'sedml:yDataReferenceFrom' and 'sedml:yDataReferenceTo'. No other "
    "attributes from the SBML Level 3 SED-ML namespaces are permitted on a "
    "<shadedArea> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25904
  { SedmlShadedAreaYDataReferenceFromMustBeDataGenerator,
    "The attribute 'yDataReferenceFrom' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yDataReferenceFrom' of a <shadedArea> "
    "object must be the identifier of an existing <dataGenerator> object "
    "defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 25905
  { SedmlShadedAreaYDataReferenceToMustBeDataGenerator,
    "The attribute 'yDataReferenceTo' must point to DataGenerator object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:yDataReferenceTo' of a <shadedArea> "
    "object must be the identifier of an existing <dataGenerator> object "
    "defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26001
  { SedmlParameterEstimationResultPlotAllowedCoreAttributes,
    "Core attributes allowed on <parameterEstimationResultPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationResultPlot> object may have the optional SBML Level "
    "3 Core attributes 'metaid' and 'sboTerm'. No other attributes from the "
    "SBML Level 3 Core namespaces are permitted on a "
    "<parameterEstimationResultPlot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26002
  { SedmlParameterEstimationResultPlotAllowedCoreElements,
    "Core elements allowed on <parameterEstimationResultPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationResultPlot> object may have the optional SBML Level "
    "3 Core subobjects for notes and annotations. No other elements from the "
    "SBML Level 3 Core namespaces are permitted on a "
    "<parameterEstimationResultPlot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26003
  { SedmlParameterEstimationResultPlotAllowedAttributes,
    "Attributes allowed on <parameterEstimationResultPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationResultPlot> object must have the required attribute "
    "'sedml:taskReference'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <parameterEstimationResultPlot> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26004
  { SedmlParameterEstimationResultPlotTaskReferenceMustBeTask,
    "The attribute 'taskReference' must point to Task object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:taskReference' of a "
    "<parameterEstimationResultPlot> object must be the identifier of an "
    "existing <task> object defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26101
  { SedmlWaterfallPlotAllowedCoreAttributes,
    "Core attributes allowed on <waterfallPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <waterfallPlot> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <waterfallPlot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26102
  { SedmlWaterfallPlotAllowedCoreElements,
    "Core elements allowed on <waterfallPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <waterfallPlot> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <waterfallPlot>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26103
  { SedmlWaterfallPlotAllowedAttributes,
    "Attributes allowed on <waterfallPlot>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <waterfallPlot> object must have the required attribute 'sedml:taskReference'. "
    "No other attributes from the SBML Level 3 SED-ML namespaces are permitted "
    "on a <waterfallPlot> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26104
  { SedmlWaterfallPlotTaskReferenceMustBeTask,
    "The attribute 'taskReference' must point to Task object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:taskReference' of a <waterfallPlot> object "
    "must be the identifier of an existing <task> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26201
  { SedmlParameterEstimationReportAllowedCoreAttributes,
    "Core attributes allowed on <parameterEstimationReport>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationReport> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <parameterEstimationReport>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26202
  { SedmlParameterEstimationReportAllowedCoreElements,
    "Core elements allowed on <parameterEstimationReport>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationReport> object may have the optional SBML Level 3 "
    "Core subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <parameterEstimationReport>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26203
  { SedmlParameterEstimationReportAllowedAttributes,
    "Attributes allowed on <parameterEstimationReport>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <parameterEstimationReport> object must have the required attribute "
    "'sedml:taskReference'. No other attributes from the SBML Level 3 SED-ML "
    "namespaces are permitted on a <parameterEstimationReport> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 26204
  { SedmlParameterEstimationReportTaskReferenceMustBeTask,
    "The attribute 'taskReference' must point to Task object.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:taskReference' of a "
    "<parameterEstimationReport> object must be the identifier of an existing "
    "<task> object defined in the enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  Application-specific codes should begin at 100000.
   * ----------------------------------------------------------------------- */

  //99994
  {
    SedUnknownCoreAttribute,
    "Unknown attribute",
    LIBSEDML_CAT_INTERNAL,
    LIBSEDML_SEV_ERROR,
    "An unknown attribute has been found.", 
    {""
    }
   },

  //99999
  {
    SedCodesUpperBound,
    "Upper boundary of libSEDML-specific diagnostic codes",
    LIBSEDML_CAT_INTERNAL,
    LIBSEDML_SEV_NOT_APPLICABLE,
    "Application-specific codes should begin at 100000.", 
    {""
    }
   }
};

LIBSEDML_CPP_NAMESPACE_END
/** @endcond */



#endif /* !SedErrorTable_H__ */

