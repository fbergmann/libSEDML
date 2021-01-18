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

  auto* var1 = dg->createDependentVariable();
  var1->setId("v1");
  var1->setModelReference("task1");
  var1->setTerm("urn:sedml:rateOfChange");

  var1 = new SedDependentVariable(1,4);
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
  REQUIRE(line.setStyle("dashDotDot") == LIBSEDML_OPERATION_SUCCESS);
  REQUIRE(line.setStyle(SEDML_LINETYPE_DASHDOTDOT) == LIBSEDML_OPERATION_SUCCESS);

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

