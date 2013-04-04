/**
 * @file    create_sedml.cpp
 * @brief   cerates a SED-ML document.
 * @author  Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SEDML, and the latest version of libSEDML.
 *
 * Copyright (c) 2013, Frank T. Bergmann
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


#include <iostream>
#include <sedml/SedMLTypes.h>
#include <sbml/math/FormulaParser.h>

using namespace std;
LIBSEDML_CPP_NAMESPACE_USE

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << endl << "Usage: create_sedml output-filename"
         << endl << endl;
    return 2;
  }

  // create the document
  SedMLDocument doc;
  doc.setLevel(1);
  doc.setVersion(1);

  {
  // create a first model referencing an sbml file
  SedMLModel *model = doc.createSedMLModel();
  model->setId("model1");
  model->setSource("file.xml");
  model->setLanguage("urn:sedml:sbml");

  // create a second model modifying a variable of that other sbml file
  model = doc.createSedMLModel();
  model->setId("model2");
  model->setSource("model1");
  model->setLanguage("urn:sedml:sbml");

  // change a paramerter 'k' to 0.1
  ChangeAttribute* change = model->createChangeAttribute();
  change->setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='k']/@value");
  change->setNewValue("0.1");

  // remove species 's1'
  RemoveXML* remove = model->createRemoveXML();
  remove->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");

  // now for something tricky we want to update the initialConcentration of 'S2' to be
  // half what it was in the original model
  ComputeChange* compute = model->createComputeChange();
  compute->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id=&quot;S2&quot;]/@initialConcentration");
  SedMLVariable *variable = compute->createSedMLVariable();
  variable->setId("S2");
  variable->setModelReference("model1");
  variable->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S2']");
  compute->setMath(SBML_parseFormula("S2 / 2"));
  }

  // create simulation
  UniformTimeCourse* tc = doc.createUniformTimeCourse();
  tc->setId("sim1");
  tc->setInitialTime(0.0);
  tc->setOutputStartTime(0.0);
  tc->setOutputEndTime(10.0);
  tc->setNumberOfPoints(1000);
  // need to set the correct KISAO Term
  Algorithm* alg = tc->createAlgorithm();
  alg->setKisaoID("KISAO:0000019");

  // create a task that uses the simulation and the model above
  Task* task = doc.createTask();
  task->setId("task1");
  task->setModelReference("model1");
  task->setSimulationReference("sim1");

  // add a DataGenerator to hold the output for time
  DataGenerator* dg = doc.createDataGenerator();
  dg->setId("time");
  dg->setName("time");
  SedMLVariable* var = dg->createSedMLVariable();
  var->setId("v0");
  var->setName("time");
  var->setTaskReference("task1");
  var->setSymbol("urn:sedml:symbol:time");
  dg->setMath(SBML_parseFormula("v0"));

  // and one for S1
  dg = doc.createDataGenerator();
  dg->setId("S1");
  dg->setName("S1");
  var = dg->createSedMLVariable();
  var->setId("v1");
  var->setName("S1");
  var->setTaskReference("task1");
  var->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");
  dg->setMath(SBML_parseFormula("v1"));

  // add a report
  Report* report = doc.createReport();
  report->setId("r1");
  report->setName("report 1");
  DataSet* set = report->createDataSet();
  set->setId("ds1");
  set->setLabel("time");
  set->setDataReference("time");
  set = report->createDataSet();
  set->setId("ds2");
  set->setLabel("S1");
  set->setDataReference("S1");

  // add a 2d plot
  Plot2D* plot = doc.createPlot2D();
  plot->setId("p1");
  plot->setName("S1 Timecourse");
  SedMLCurve* curve = plot->createSedMLCurve();
  curve->setId("c1");
  curve->setName("S1");
  curve->setLogX(false);
  curve->setLogY(false);
  curve->setXDataReference("time");
  curve->setYDataReference("S1");

  // add a 3D Plot
  Plot3D* plot2 = doc.createPlot3D();
  plot2->setId("p2");
  plot2->setName("dunno");
  Surface* surf = plot2->createSurface();
  surf->setId("surf1");
  surf->setName("S1");
  surf->setLogX(false);
  surf->setLogY(false);
  surf->setLogZ(false);
  surf->setXDataReference("time");
  surf->setYDataReference("S1");
  surf->setZDataReference("S1");

  // write the document
  writeSedML(&doc, argv[1]);

  return 0;
}
