/**
 * \file    TestIssues.cpp
 * \brief   Issues submitted
 * \author  Frank Bergmann
 * 
 * <!--------------------------------------------------------------------------
 * 
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on 
 * github: https://github.com/fbergmann/libSEDML/
 * 
 * 
 * Copyright (c) 2013-2021, Frank T. Bergmann  
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
 * 
 * ---------------------------------------------------------------------- -->
 * 
 */

#include "catch.hpp"
#include <limits>

#include <iostream>
#include <string>
#include <sstream>

#include <sbml/common/libsbml-version.h>
#include <sedml/common/libsedml-version.h>

#include <sedml/SedDocument.h>
#include <sedml/SedDataGenerator.h>
#include <sedml/SedWriter.h>

#include <sbml/math/L3FormulaFormatter.h>
#include <sbml/math/L3Parser.h>

#include <sedml/SedTypes.h>
#include <cstdlib>

/** @cond doxygenIgnored */

using namespace std;
LIBSBML_CPP_NAMESPACE_USE
LIBSEDML_CPP_NAMESPACE_USE

/** @endcond */



/**
 * Tries to find the test file in the srcdir environment variable.
 *
 * @param fileName the filename relative to this tests srcdir
 *        environment variable.
 *
 * If the filename cannot be found, the test from which this function
 * is called will fail.
 *
 * @return the full path to the test file
 */
std::string getTestFile(const std::string& fileName)
{
  std::stringstream str;
  char* srcDir = getenv("srcdir");
  
  if (srcDir != NULL) str << srcDir;
  else str << ".";

  str << "/" << fileName;
  std::string fullName = str.str();

  return fullName;
}

TEST_CASE("test mathml issue1", "[sedml]")
{  
  SedDocument doc;
  SedDataGenerator* sdg = doc.createDataGenerator();
  ASTNode* astn = SBML_parseL3Formula("S1/S2");
  sdg->setMath(astn);
  ostringstream stream;
  SedWriter sw;
  sw.writeSedML(&doc, stream);
  string v1 = stream.str();
  stream.str("");
  astn = SBML_parseL3Formula("log(S1/S2)");

#if LIBSBML_USE_LEGACY_MATH
  sdg->setMath(astn->getChild(1));
#else 
  ASTNode* node =astn->getChild(1);
  node ->setIsChildFlag(false);
  sdg->setMath(node);
#endif

  sw.writeSedML(&doc, stream);
  string v2 = stream.str();
  //cout << v1 << endl << endl << v2 << endl << endl;
  REQUIRE( v1 == v2 );
}

TEST_CASE("Reading / Writing L1V4", "[sedml]")
{
  std::string fileName = getTestFile("/test-data/noble_1962_local.sedml");
  SedDocument* doc = readSedMLFromFile(fileName.c_str());
  REQUIRE (doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);

  
  // convert to l1v4
  doc->setLevel(1); doc->setVersion(4);

  // write to string
  SedWriter sw;
  std::string l1v4 = sw.writeSedMLToStdString(doc);
  REQUIRE(l1v4.find("version=\"4\"") != std::string::npos);

  // don't need doc anymore
  delete doc;

  // read back
  doc = readSedMLFromString(l1v4.c_str());
  REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);

  delete doc;
}

TEST_CASE("Reading L1V4 curve should not require logY", "[sedml]")
{
  std::string fileName = getTestFile("/test-data/issue_63.sedml");
  SedDocument* doc = readSedMLFromFile(fileName.c_str());
  REQUIRE (doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
  delete doc;
}


TEST_CASE("Test sortOrderedObjects: curves", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/sort_curves.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
    doc->sortOrderedObjects();
    SedOutput* out = doc->getOutput(0);
    REQUIRE(out->getTypeCode() == SEDML_OUTPUT_PLOT2D);
    SedPlot2D* sp2d = static_cast<SedPlot2D*>(out);

    SedAbstractCurve* curve = sp2d->getCurve(0);
    REQUIRE(curve->isSetOrder() == true);
    REQUIRE(curve->getOrder() == 1);
    REQUIRE(curve->getStyle() == "green_line");

    curve = sp2d->getCurve(1);
    REQUIRE(curve->isSetOrder() == true);
    REQUIRE(curve->getOrder() == 2);
    REQUIRE(curve->getStyle() == "purple_line");

    curve = sp2d->getCurve(2);
    REQUIRE(curve->isSetOrder() == true);
    REQUIRE(curve->getOrder() == 3);
    REQUIRE(curve->getStyle() == "red_line");

    delete doc;
}


TEST_CASE("Test sortOrderedObjects: surfaces", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/sort_surfaces.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
    doc->sortOrderedObjects();

    SedOutput* out = doc->getOutput(0);
    REQUIRE(out->getTypeCode() == SEDML_OUTPUT_PLOT3D);
    SedPlot3D* sp3d = static_cast<SedPlot3D*>(out);

    SedSurface* surface = sp3d->getSurface(0);
    REQUIRE(surface->isSetOrder() == true);
    REQUIRE(surface->getOrder() == 0);
    REQUIRE(surface->getId() == "surfaceA");

    surface = sp3d->getSurface(1);
    REQUIRE(surface->isSetOrder() == true);
    REQUIRE(surface->getOrder() == 2);
    REQUIRE(surface->getId() == "surfaceC");

    surface = sp3d->getSurface(2);
    REQUIRE(surface->isSetOrder() == true);
    REQUIRE(surface->getOrder() == 5);
    REQUIRE(surface->getId() == "surfaceB");

    delete doc;
}


TEST_CASE("Test sortOrderedObjects: subtasks", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/sort_subtasks.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
    doc->sortOrderedObjects();

    SedAbstractTask* task = doc->getTask(0);
    REQUIRE(task->getTypeCode() == SEDML_TASK_REPEATEDTASK);
    SedRepeatedTask* rt = static_cast<SedRepeatedTask*>(task);

    SedSubTask* subtask = rt->getSubTask(0);
    REQUIRE(subtask->isSetOrder() == true);
    REQUIRE(subtask->getOrder() == 1);

    subtask = rt->getSubTask(1);
    REQUIRE(subtask->isSetOrder() == true);
    REQUIRE(subtask->getOrder() == 2);

    subtask = rt->getSubTask(2);
    REQUIRE(subtask->isSetOrder() == true);
    REQUIRE(subtask->getOrder() == 3);

    delete doc;
}


TEST_CASE("Test sortOrderedObjects doesn't crash", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/BIOMD0000000087_fig5.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
    doc->sortOrderedObjects();
    delete doc;
}



TEST_CASE("Reading a file with custom namespaces on element should have it available", "[sedml]")
{
  std::string fileName = getTestFile("/test-data/issue_77.sedml");
  SedDocument* doc = readSedMLFromFile(fileName.c_str());
  REQUIRE (doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
  // not defined on document
  REQUIRE ( doc->getNamespaces()->getIndex("http://www.cellml.org/cellml/1.0#") == -1 );
  
  auto* dg = doc->getDataGenerator("xDataGenerator1_1");
  REQUIRE ( dg != NULL );
  auto* var = dg->getVariable("xVariable1_1");
  REQUIRE ( var != NULL );
  // defined on element 
  auto* ns = var->getElementNamespaces();
  REQUIRE ( ns != NULL );  
  REQUIRE ( ns->getIndex("http://www.cellml.org/cellml/1.0#") != -1 );
  REQUIRE ( ns->getIndexByPrefix("cellml") != -1 );
  REQUIRE ( ns->containsUri("http://www.cellml.org/cellml/1.0#"));
  
  
  delete doc;
}


TEST_CASE("create and add nested algorithm parameter", "[sedml]")
{
  SedDocument doc(1, 4);
  auto* sim = doc.createUniformTimeCourse();
  sim->setId("sim1");
  sim->setInitialTime(0.0);
  sim->setOutputStartTime(0.0);
  sim->setOutputEndTime(10.0);
  auto* alg = sim->createAlgorithm();
  alg->setKisaoID("KISAO:0000352");
  auto* p = alg->createAlgorithmParameter();
  p->setKisaoID("KISAO:0000203");
  p->setValue("something");

  auto* p1 = p->createAlgorithmParameter();
  p1->setKisaoID("KISAO:0000029");
  p1->setValue("something");

  REQUIRE(p->getNumAlgorithmParameters() == 1);

  p1 = new SedAlgorithmParameter(1, 4);
  p1->setKisaoID("KISAO:0000089");
  p1->setValue("something");
  REQUIRE( p->addAlgorithmParameter(p1) == LIBSEDML_OPERATION_SUCCESS);
  REQUIRE(p->getNumAlgorithmParameters() == 2);
  REQUIRE(alg->getNumAlgorithmParameters() == 1);
  SedWriter sw;
  std::string l1v4 = sw.writeSedMLToStdString(&doc);
  auto* doc2 = readSedMLFromString(l1v4.c_str());
  REQUIRE(doc2->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
  delete doc2;

}

TEST_CASE("create and add dependent variables", "[sedml]")
{
  SedDocument doc(1, 4);

  auto* dg = doc.createDataGenerator();
  dg->setId("dg1");
  
  auto* var = dg->createVariable();
  var->setId("v0");
  var->setModelReference("task1");
  var->setSymbol("urn:sedml:time");

  auto* var1 = dg->createVariable();
  var1->setId("v1");
  var1->setModelReference("task1");
  var1->setTerm("urn:sedml:rateOfChange");

  var1 = new SedVariable(1,4);
  var1->setId("v2");
  var1->setModelReference("task1");
  var1->setTerm("urn:sedml:rateOfChange");
  REQUIRE(dg->addVariable(var1) == LIBSEDML_OPERATION_SUCCESS);


  dg->setMath(SBML_parseL3Formula("v0 + v1 + v2"));


  SedWriter sw;
  std::string l1v4 = sw.writeSedMLToStdString(&doc);
  auto* doc2 = readSedMLFromString(l1v4.c_str());
  REQUIRE(doc2->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
  delete doc2;
}

TEST_CASE("allow dashDotDot", "[sedml]")
{
  SedLine line(1, 4);
  REQUIRE(line.setType("dashDotDot") == LIBSEDML_OPERATION_SUCCESS);
  REQUIRE(line.setType(SEDML_LINETYPE_DASHDOTDOT) == LIBSEDML_OPERATION_SUCCESS);

}

TEST_CASE("ensure SedStyle members are labled consistently", "[sedml]")
{
  SedStyle style(1, 4);
  REQUIRE(style.isSetLineStyle() == false);
  REQUIRE(style.isSetMarkerStyle() == false);
  REQUIRE(style.isSetFillStyle() == false);

}

TEST_CASE("Reading / Writing changexml with multipme elements", "[sedml]")
{
  std::string fileName = getTestFile("/test-data/issue_89.sedml");
  SedDocument* doc = readSedMLFromFile(fileName.c_str());
  REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);

  auto* model = doc->getModel(0);
  REQUIRE(model != NULL);
  auto* change = dynamic_cast<SedChangeXML*>(model->getChange(0));
  REQUIRE(change != NULL);
  auto* newXML = change->getNewXML();
  REQUIRE(newXML != NULL);
  REQUIRE(newXML->getNumChildren() == 2);
  std::string newString = newXML->toXMLString();
  REQUIRE(!newString.empty());

  change = dynamic_cast<SedChangeXML*>(model->getChange(1));
  REQUIRE(change != NULL);
  newXML = change->getNewXML();
  REQUIRE(newXML != NULL);
  newString = newXML->toXMLString();
  REQUIRE(!newString.empty());


  delete doc;

}


TEST_CASE("Reading / Writing changexml only text node", "[sedml]")
{
  std::string fileName = getTestFile("/test-data/issue_91.sedml");
  SedDocument* doc = readSedMLFromFile(fileName.c_str());
  REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);

  {
    auto* model = doc->getModel(0);
    REQUIRE(model != NULL);
    auto* change = dynamic_cast<SedAddXML*>(model->getChange(0));
    REQUIRE(change != NULL);
    auto* newXML = change->getNewXML();
    REQUIRE(newXML != NULL);
    REQUIRE(newXML->getNumChildren() == 0);
    std::string newString = newXML->toXMLString();
    REQUIRE(!newString.empty());
  }


  {
    auto* model = doc->getModel(1);
    REQUIRE(model != NULL);
    auto* change = dynamic_cast<SedChangeXML*>(model->getChange(0));
    REQUIRE(change != NULL);
    auto* newXML = change->getNewXML();
    REQUIRE(newXML != NULL);
    REQUIRE(newXML->getNumChildren() == 0);
    std::string newString = newXML->toXMLString();
    REQUIRE(!newString.empty());
  }

  delete doc;
}


TEST_CASE("Reading numberOfPoints", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/issue_93.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    bool haveErrors = doc->getNumErrors(LIBSEDML_SEV_ERROR) != 0;

    if (haveErrors)
        doc->getErrorLog()->printErrors();

    REQUIRE(!haveErrors);

    {
        auto* task = dynamic_cast<SedRepeatedTask*> (doc->getTask(0));
        REQUIRE(task != NULL);
        auto* range = dynamic_cast<SedUniformRange*> (task->getRange(0));
        REQUIRE(range != NULL);
        REQUIRE(range->isSetNumberOfPoints());
        REQUIRE(range->getNumberOfPoints() == 10);
    }
    
    {
      auto* list = doc->getAllElements(); 
      REQUIRE(list != NULL);
      REQUIRE(list->getSize() == 4);
      REQUIRE(static_cast<SedBase*>(list->get(0))->getTypeCode() == SEDML_LIST_OF);
      REQUIRE(static_cast<SedBase*>(list->get(1))->getTypeCode() == SEDML_TASK_REPEATEDTASK);
      REQUIRE(static_cast<SedBase*>(list->get(2))->getTypeCode() == SEDML_LIST_OF);
      REQUIRE(static_cast<SedBase*>(list->get(3))->getTypeCode() == SEDML_RANGE_UNIFORMRANGE);
      delete list;
    }
    
    delete doc;
}



TEST_CASE("Id and name on different levels/versions", "[sedml]")
{
    SedNamespaces l1v3(1, 3);
    SedNamespaces l1v4(1, 4);

    //An element that had name and id in l1v3
    SedVariable variable13(&l1v3), variable14(&l1v4);
    CHECK(variable13.isSetId() == false);
    CHECK(variable14.isSetId() == false);
    CHECK(variable13.getId() == "");
    CHECK(variable14.getId() == "");
    CHECK(variable13.setId("variable") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(variable14.setId("variable") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(variable13.isSetId() == true);
    CHECK(variable14.isSetId() == true);
    CHECK(variable13.getId() == "variable");
    CHECK(variable14.getId() == "variable");
    CHECK(variable13.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(variable14.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(variable13.isSetId() == false);
    CHECK(variable14.isSetId() == false);
    CHECK(variable13.getId() == "");
    CHECK(variable14.getId() == "");

    CHECK(variable13.isSetName() == false);
    CHECK(variable14.isSetName() == false);
    CHECK(variable13.getName() == "");
    CHECK(variable14.getName() == "");
    CHECK(variable13.setName("variable") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(variable14.setName("variable") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(variable13.isSetName() == true);
    CHECK(variable14.isSetName() == true);
    CHECK(variable13.getName() == "variable");
    CHECK(variable14.getName() == "variable");
    CHECK(variable13.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(variable14.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(variable13.isSetName() == false);
    CHECK(variable14.isSetName() == false);
    CHECK(variable13.getName() == "");
    CHECK(variable14.getName() == "");

    {
    SedCurve curve13(&l1v3), curve14(&l1v4);
    CHECK(curve13.isSetId() == false);
    CHECK(curve14.isSetId() == false);
    CHECK(curve13.getId() == "");
    CHECK(curve14.getId() == "");
    CHECK(curve13.setId("curve") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve14.setId("curve") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve13.isSetId() == true);
    CHECK(curve14.isSetId() == true);
    CHECK(curve13.getId() == "curve");
    CHECK(curve14.getId() == "curve");
    CHECK(curve13.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve14.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve13.isSetId() == false);
    CHECK(curve14.isSetId() == false);
    CHECK(curve13.getId() == "");
    CHECK(curve14.getId() == "");

    CHECK(curve13.isSetName() == false);
    CHECK(curve14.isSetName() == false);
    CHECK(curve13.getName() == "");
    CHECK(curve14.getName() == "");
    CHECK(curve13.setName("curve") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve14.setName("curve") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve13.isSetName() == true);
    CHECK(curve14.isSetName() == true);
    CHECK(curve13.getName() == "curve");
    CHECK(curve14.getName() == "curve");
    CHECK(curve13.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve14.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve13.isSetName() == false);
    CHECK(curve14.isSetName() == false);
    CHECK(curve13.getName() == "");
    CHECK(curve14.getName() == "");
    }


    {
    SedSurface curve13(&l1v3), curve14(&l1v4);
    CHECK(curve13.isSetId() == false);
    CHECK(curve14.isSetId() == false);
    CHECK(curve13.getId() == "");
    CHECK(curve14.getId() == "");
    CHECK(curve13.setId("curve") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve14.setId("curve") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve13.isSetId() == true);
    CHECK(curve14.isSetId() == true);
    CHECK(curve13.getId() == "curve");
    CHECK(curve14.getId() == "curve");
    CHECK(curve13.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve14.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve13.isSetId() == false);
    CHECK(curve14.isSetId() == false);
    CHECK(curve13.getId() == "");
    CHECK(curve14.getId() == "");

    CHECK(curve13.isSetName() == false);
    CHECK(curve14.isSetName() == false);
    CHECK(curve13.getName() == "");
    CHECK(curve14.getName() == "");
    CHECK(curve13.setName("curve") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve14.setName("curve") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve13.isSetName() == true);
    CHECK(curve14.isSetName() == true);
    CHECK(curve13.getName() == "curve");
    CHECK(curve14.getName() == "curve");
    CHECK(curve13.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve14.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(curve13.isSetName() == false);
    CHECK(curve14.isSetName() == false);
    CHECK(curve13.getName() == "");
    CHECK(curve14.getName() == "");
    }


    //An element that had id but not name in l1v3:
    SedRange range13(&l1v3), range14(&l1v4);
    CHECK(range13.isSetId() == false);
    CHECK(range14.isSetId() == false);
    CHECK(range13.getId() == "");
    CHECK(range14.getId() == "");
    CHECK(range13.setId("range") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(range14.setId("range") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(range13.isSetId() == true);
    CHECK(range14.isSetId() == true);
    CHECK(range13.getId() == "range");
    CHECK(range14.getId() == "range");
    CHECK(range13.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(range14.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(range13.isSetId() == false);
    CHECK(range14.isSetId() == false);
    CHECK(range13.getId() == "");
    CHECK(range14.getId() == "");

    CHECK(range13.isSetName() == false);
    CHECK(range14.isSetName() == false);
    CHECK(range13.getName() == "");
    CHECK(range14.getName() == "");
    CHECK(range13.setName("range") == LIBSEDML_UNEXPECTED_ATTRIBUTE);
    CHECK(range14.setName("range") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(range13.isSetName() == false);
    CHECK(range14.isSetName() == true);
    CHECK(range13.getName() == "");
    CHECK(range14.getName() == "range");
    CHECK(range13.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(range14.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(range13.isSetName() == false);
    CHECK(range14.isSetName() == false);
    CHECK(range13.getName() == "");
    CHECK(range14.getName() == "");

    //An element that didn't have id or name in l1v3:
    SedAlgorithm algorithm13(&l1v3), algorithm14(&l1v4);
    CHECK(algorithm13.isSetId() == false);
    CHECK(algorithm14.isSetId() == false);
    CHECK(algorithm13.getId() == "");
    CHECK(algorithm14.getId() == "");
    CHECK(algorithm13.setId("algorithm") == LIBSEDML_UNEXPECTED_ATTRIBUTE);
    CHECK(algorithm14.setId("algorithm") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(algorithm13.isSetId() == false);
    CHECK(algorithm14.isSetId() == true);
    CHECK(algorithm13.getId() == "");
    CHECK(algorithm14.getId() == "algorithm");
    CHECK(algorithm13.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(algorithm14.unsetId() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(algorithm13.isSetId() == false);
    CHECK(algorithm14.isSetId() == false);
    CHECK(algorithm13.getId() == "");
    CHECK(algorithm14.getId() == "");

    CHECK(algorithm13.isSetName() == false);
    CHECK(algorithm14.isSetName() == false);
    CHECK(algorithm13.getName() == "");
    CHECK(algorithm14.getName() == "");
    CHECK(algorithm13.setName("algorithm") == LIBSEDML_UNEXPECTED_ATTRIBUTE);
    CHECK(algorithm14.setName("algorithm") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(algorithm13.isSetName() == false);
    CHECK(algorithm14.isSetName() == true);
    CHECK(algorithm13.getName() == "");
    CHECK(algorithm14.getName() == "algorithm");
    CHECK(algorithm13.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(algorithm14.unsetName() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(algorithm13.isSetName() == false);
    CHECK(algorithm14.isSetName() == false);
    CHECK(algorithm13.getName() == "");
    CHECK(algorithm14.getName() == "");

}


TEST_CASE("Reading/writing of dashDotDot", "[sedml]")
{
  SedDocument* doc = new SedDocument(1, 4);
  {
    auto* style = doc->createStyle();
    REQUIRE(style != NULL);
    style->setId("test");
    auto* line = style->createLineStyle();
    REQUIRE(line != NULL);
    REQUIRE(line->setType(SEDML_LINETYPE_DASHDOTDOT) == LIBSEDML_OPERATION_SUCCESS);
    REQUIRE(line->getType() == SEDML_LINETYPE_DASHDOTDOT);
    REQUIRE(line->setType("dashDotDot") == LIBSEDML_OPERATION_SUCCESS);
    REQUIRE(line->getType() == SEDML_LINETYPE_DASHDOTDOT);

    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
  }

  std::string sedml = writeSedMLToStdString(doc);
  delete doc;

  doc = readSedMLFromString(sedml.c_str());
  doc->getErrorLog()->printErrors();
  REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
  {
    auto* style = doc->getStyle(0);
    REQUIRE(style != NULL);
    auto* line = style->getLineStyle();
    REQUIRE(line != NULL);
    REQUIRE(line->getType() == SEDML_LINETYPE_DASHDOTDOT);

  }
  delete doc;
}

TEST_CASE("Reading old 'style' attribute on line should give error", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/line_uses_style.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 3);
    SedError* err1 = doc->getError(0);
    CHECK(err1->getErrorId() == SedmlLineAllowedAttributes);

    delete doc;
}


TEST_CASE("Reading old 'style' attribute on marker should give error", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/marker_uses_style.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 3);
    SedError* err1 = doc->getError(0);
    CHECK(err1->getErrorId() == SedmlMarkerAllowedAttributes);

    delete doc;
}

TEST_CASE("Set new symbol on ComputeChange", "[sedml]")
{
    SedComputeChange scc(1, 4);
    CHECK(scc.isSetSymbol() == false);
    CHECK(scc.setSymbol("some_urn") == LIBSEDML_OPERATION_SUCCESS);
    CHECK(scc.getSymbol() == "some_urn");
    char* sccstr = scc.toSed();
    CHECK(string(sccstr) == "<computeChange symbol=\"some_urn\"/>");
    delete sccstr;
    CHECK(scc.isSetSymbol() == true);
    CHECK(scc.unsetSymbol() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(scc.isSetSymbol() == false);

    SedComputeChange scc2(1, 3);
    CHECK(scc2.isSetSymbol() == false);
    CHECK(scc2.setSymbol("some_urn") == LIBSEDML_UNEXPECTED_ATTRIBUTE);
    sccstr = scc.toSed();
    CHECK(string(sccstr) == "<computeChange/>");
    delete sccstr;
    CHECK(scc2.getSymbol() == "");
    CHECK(scc2.isSetSymbol() == false);
    CHECK(scc2.unsetSymbol() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(scc2.isSetSymbol() == false);
}


TEST_CASE("Add algorithm parameters on SedDocument", "[sedml]")
{
    SedDocument doc(1, 4);
    SedAlgorithmParameter* ap = doc.createAlgorithmParameter();
    CHECK(ap != NULL);
    ap->setId("ap1");
    SedAlgorithmParameter* ret_ap = doc.getAlgorithmParameter("ap1");
    CHECK(ret_ap == ap);
    ret_ap = doc.getAlgorithmParameter(0);
    CHECK(ret_ap == ap);
    char* docstr = doc.toSed();
    CHECK(string(docstr) == "<sedML xmlns=\"http://sed-ml.org/sed-ml/level1/version4\" level=\"1\" version=\"4\">\n  <listOfAlgorithmParameters>\n    <algorithmParameter id=\"ap1\"/>\n  </listOfAlgorithmParameters>\n</sedML>");

    SedDocument doc2(1, 3);
    ap = doc2.createAlgorithmParameter();
    CHECK(ap == NULL);
    ret_ap = doc2.getAlgorithmParameter("ap1");
    CHECK(ret_ap == ap);
    ret_ap = doc2.getAlgorithmParameter(0);
    CHECK(ret_ap == ap);
    char* doc2str = doc2.toSed();
    CHECK(string(doc2str) == "<sedML xmlns=\"http://sed-ml.org/sed-ml/level1/version3\" level=\"1\" version=\"3\"/>");
}


TEST_CASE("x, y, and z data now required", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/surface_noxy_l1v3.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    CHECK(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
    delete doc;

    fileName = getTestFile("/test-data/surface_noxy_l1v4.sedml");
    doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 2);
    SedError* err1 = doc->getError(0);
    CHECK(err1->getErrorId() == SedmlSurfaceAllowedAttributes);
    delete doc;

    fileName = getTestFile("/test-data/curve_nox_l1v3.sedml");
        doc = readSedMLFromFile(fileName.c_str());
    CHECK(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
    delete doc;

    fileName = getTestFile("/test-data/curve_nox_l1v4.sedml");
    doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 2);
    err1 = doc->getError(0);
    CHECK(err1->getErrorId() == SedmlAbstractCurveAllowedAttributes);
    delete doc;
}



TEST_CASE("Model 'language' now required", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/model_nolang_l1v3.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    CHECK(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
    delete doc;

    fileName = getTestFile("/test-data/model_nolang_l1v4.sedml");
    doc = readSedMLFromFile(fileName.c_str());
    REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 1);
    SedError* err1 = doc->getError(0);
    CHECK(err1->getErrorId() == SedmlModelAllowedAttributes);
    delete doc;
}



TEST_CASE("Add 'concatenate' to RepeatedTask", "[sedml]")
{
    SedRepeatedTask srt(1, 4);
    CHECK(srt.isSetConcatenate() == false);
    CHECK(srt.setConcatenate(true) == LIBSEDML_OPERATION_SUCCESS);
    CHECK(srt.getConcatenate() == true);
    char* srtstr = srt.toSed();
    CHECK(string(srtstr) == "<repeatedTask concatenate=\"true\"/>");
    delete srtstr;
    CHECK(srt.isSetConcatenate() == true);
    CHECK(srt.unsetConcatenate() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(srt.isSetConcatenate() == false);

    SedRepeatedTask srt2(1, 3);
    CHECK(srt2.isSetConcatenate() == false);
    CHECK(srt2.setConcatenate(true) == LIBSEDML_UNEXPECTED_ATTRIBUTE);
    srtstr = srt.toSed();
    CHECK(string(srtstr) == "<repeatedTask/>");
    delete srtstr;
    CHECK(srt2.isSetConcatenate() == false);
    CHECK(srt2.unsetConcatenate() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(srt2.isSetConcatenate() == false);
}



TEST_CASE("Add change to subtask", "[sedml]")
{
    SedSubTask subtask(1, 4);
    SedSetValue* ssv = subtask.createTaskChange();
    CHECK(ssv != NULL);
    ssv->setId("ssv1");
    SedSetValue* ret_ssv = subtask.getTaskChange("ssv1");
    CHECK(ret_ssv == ssv);
    ret_ssv = subtask.getTaskChange(0);
    CHECK(ret_ssv == ssv);
    char* subtaskstr = subtask.toSed();
    CHECK(string(subtaskstr) == "<subTask>\n  <listOfChanges>\n    <setValue id=\"ssv1\"/>\n  </listOfChanges>\n</subTask>");

    SedSubTask subtask2(1, 3);
    ssv = subtask2.createTaskChange();
    CHECK(ssv == NULL);
    ret_ssv = subtask2.getTaskChange("ssv1");
    CHECK(ret_ssv == ssv);
    ret_ssv = subtask2.getTaskChange(0);
    CHECK(ret_ssv == ssv);
    char* subtask2str = subtask2.toSed();
    CHECK(string(subtask2str) == "<subTask/>");
}



TEST_CASE("Add reverse to axis", "[sedml]")
{
    SedAxis axis(1, 4);
    CHECK(axis.isSetReverse() == false);
    CHECK(axis.setReverse(true) == LIBSEDML_OPERATION_SUCCESS);
    CHECK(axis.isSetReverse() == true);
    CHECK(axis.getReverse() == true);
    CHECK(axis.unsetReverse() == LIBSEDML_OPERATION_SUCCESS);
    CHECK(axis.isSetReverse() == false);

    //Don't need to check l1v3--Axis was added in l1v4.
}


TEST_CASE("Set KiSAO and name", "[sedml]")
{
    SedAlgorithm alg(1, 4);
    alg.setKisaoID(64);
    CHECK(alg.getName() == "Runge-Kutta based method");

    SedAlgorithmParameter* param = alg.createAlgorithmParameter();
    param->setKisaoID("KISAO:0000064");
    CHECK(param->getName() == "Runge-Kutta based method");
}


TEST_CASE("Reading dependent variable", "[sedml]")
{
  std::string fileName = getTestFile("/test-data/issue_140.sedml");
  SedDocument* doc = readSedMLFromFile(fileName.c_str());
  // 2 dependent variables are invalid here (missing term)
  // (However, now that we've moved to Variables, we don't autogenerate that validation rule.
  REQUIRE(doc->getNumErrors(LIBSEDML_SEV_ERROR) == 0); 

  {
    REQUIRE(doc->getNumDataGenerators() > 3);
    auto* dg = doc->getDataGenerator(3);
    REQUIRE(dg != NULL);
    REQUIRE(dg->getNumVariables() > 0);
    auto* var = dg->getVariable(0);
    REQUIRE(var != NULL);

    REQUIRE(var->getTarget() == "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");
    REQUIRE(var->getSymbol2() == "urn:sedml:symbol:time");

  }

  delete doc;

}

TEST_CASE("Create Analysis simulation", "[sedml]")
{
    SedDocument doc(1, 4);
    auto* sim = doc.createAnalysis();
    sim->setId("sim1");
    auto* alg = sim->createAlgorithm();
    alg->setKisaoID("KISAO:0000352");
    auto* p = alg->createAlgorithmParameter();
    p->setKisaoID("KISAO:0000203");
    p->setValue("something");

    REQUIRE(alg->getNumAlgorithmParameters() == 1);
    REQUIRE(sim->getTypeCode() == SEDML_SIMULATION_ANALYSIS);

    SedWriter sw;
    std::string l1v4 = sw.writeSedMLToStdString(&doc);
    auto* doc2 = readSedMLFromString(l1v4.c_str());
    REQUIRE(doc2->getNumErrors(LIBSEDML_SEV_ERROR) == 0);
    std::string l1v4_rt = sw.writeSedMLToStdString(&doc);
    REQUIRE(l1v4 == l1v4_rt);
    delete doc2;

}

TEST_CASE("Don't quash extra namespaces on upleveling", "[sedml]")
{
    SedDocument doc(1, 3);
    doc.getNamespaces()->add("http://test.org/uri", "test");
    doc.setLevel(4);
    REQUIRE(doc.getNamespaces()->getNumNamespaces() == 2);
    CHECK(doc.getNamespaces()->getURI(1) == "http://test.org/uri");
    CHECK(doc.getNamespaces()->getPrefix(1) == "test");

}

TEST_CASE("Redirect getLog for L1v4, 2d", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/logtest.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    SedOutput* out = doc->getOutput(0);
    SedPlot2D* plot = static_cast<SedPlot2D*>(out);
    REQUIRE(plot);
    SedCurve* curve = static_cast<SedCurve*>(plot->getCurve(0));
    REQUIRE(curve);
    CHECK(curve->getLogX() == true);
    CHECK(curve->getLogY() == false);
    curve = static_cast<SedCurve*>(plot->getCurve(1));
    REQUIRE(curve);
    CHECK(curve->getLogX() == true);
    CHECK(curve->getLogY() == true);
}

TEST_CASE("Redirect getLog for L1v4, 3d", "[sedml]")
{
    std::string fileName = getTestFile("/test-data/logtest3d.sedml");
    SedDocument* doc = readSedMLFromFile(fileName.c_str());
    SedOutput* out = doc->getOutput(0);
    SedPlot3D* plot = static_cast<SedPlot3D*>(out);
    REQUIRE(plot);
    SedSurface* curve = static_cast<SedSurface*>(plot->getSurface(0));
    REQUIRE(curve);
    CHECK(curve->getLogX() == true);
    CHECK(curve->getLogY() == false);
    CHECK(curve->getLogZ() == true);
}

