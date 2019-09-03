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
 * Copyright (c) 2013-2014, Frank T. Bergmann  
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
  auto doc = readSedMLFromFile(fileName.c_str());
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
