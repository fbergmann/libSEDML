/**
 * @file    create_sedml.cpp
 * @brief   creates a SED-ML document.
 * @author  Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML, and the latest version of libSEDML.
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
#include <sedml/SedTypes.h>
#include <sbml/math/FormulaParser.h>

#include <numl/NUMLTypes.h>

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
  SedDocument doc(1,3);
  doc.setAnnotation("<test xmlns='http://test.org/test/annotation' attribute='test' />");

  {
    SedDataDescription* dataDesc =  doc.createDataDescription();
    dataDesc->setId("oscli");
    dataDesc->setName("Oscli Timecourse data");
    dataDesc->setFormat("urn:sedml:format:numl");
    dataDesc->setSource("oscli.numl");

    LIBNUML_CPP_NAMESPACE_QUALIFIER DimensionDescription* dimDesc = dataDesc->createDimensionDescription();
    
    LIBNUML_CPP_NAMESPACE_QUALIFIER CompositeDescription* timeDesc = new LIBNUML_CPP_NAMESPACE_QUALIFIER CompositeDescription();
    timeDesc->setIndexType("double");
    timeDesc->setId("time");
    timeDesc->setName("time");

    LIBNUML_CPP_NAMESPACE_QUALIFIER CompositeDescription* speciesDesc = timeDesc->createCompositeDescription();
    speciesDesc->setIndexType("string");
    speciesDesc->setId("SpeciesIds");
    speciesDesc->setName("SpeciesIds");

    LIBNUML_CPP_NAMESPACE_QUALIFIER AtomicDescription* concentrationDesc = speciesDesc->createAtomicDescription();
    concentrationDesc->setValueType("double");
    concentrationDesc->setName("Concentrations");

    dimDesc->appendAndOwn(timeDesc);

    SedDataSource* dataSource = dataDesc->createDataSource();
    dataSource->setId("dataS1");

    SedSlice* slice = dataSource->createSlice();
    slice->setReference("SpeciesIds");
    slice->setValue("S1");

    dataSource = dataDesc->createDataSource();
    dataSource->setIndexSet("time");
  }

  {
    // create a first model referencing an sbml file
    SedModel *model = doc.createModel();
    model->setId("model1");
    model->setSource("file.xml");
    model->setLanguage("urn:sedml:language:sbml");

    // create a second model modifying a variable of that other sbml file
    model = doc.createModel();
    model->setId("model2");
    model->setSource("model1");
    model->setLanguage("urn:sedml:language:sbml");

    // change a paramerter 'k' to 0.1
    SedChangeAttribute* change = model->createChangeAttribute();
    change->setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='k']/@value");
    change->setNewValue("0.1");

    // remove species 's1'
    SedRemoveXML* remove = model->createRemoveXML();
    remove->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");

    // add another species 's1' using addxml
    SedAddXML* addXml = model->createAddXML();
    addXml->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies");
    addXml->setNewXML(XMLNode::convertStringToXMLNode("<species xmlns='http://www.sbml.org/sbml/level2' id='S1' boundaryCondition='false' initialConcentration='0' compartment='compartment' />"));

    // replace 's1' one more time by a better one 
    SedChangeXML* changeXML = model->createChangeXML();
    changeXML->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");
    changeXML->setNewXML(XMLNode::convertStringToXMLNode("<species xmlns='http://www.sbml.org/sbml/level2'  id='S1' boundaryCondition='false' initialConcentration='10' compartment='compartment' />"));

    // now for something tricky we want to update the initialConcentration of 'S2' to be
    // half what it was in the original model
    SedComputeChange* compute = model->createComputeChange();
    compute->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id=&quot;S2&quot;]/@initialConcentration");
    SedVariable *variable = compute->createVariable();
    variable->setId("S2");
    variable->setModelReference("model1");
    variable->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S2']");
    compute->setMath(SBML_parseFormula("S2 / 2"));
  }

  // create simulation
  SedUniformTimeCourse* tc = doc.createUniformTimeCourse();
  tc->setId("sim1");
  tc->setInitialTime(0.0);
  tc->setOutputStartTime(0.0);
  tc->setOutputEndTime(10.0);
  tc->setNumberOfPoints(1000);
  // need to set the correct KISAO Term
  SedAlgorithm* alg = tc->createAlgorithm();
  alg->setKisaoID("KISAO:0000019");
  SedAlgorithmParameter* algParam = alg->createAlgorithmParameter();
  algParam ->setNotes("<p xmlns='http://www.w3.org/1999/xhtml'>This is the absolute tolerance</p>");
  algParam ->setKisaoID("KISAO:0000211");
  algParam ->setValue("1e-12");
  // add annotation
  tc->setAnnotation("<test xmlns='http://test.org/test/simulation/annotation' attribute='uniform time course' />");
  alg->setAnnotation("<test xmlns='http://test.org/test/simulation/annotation' attribute='algorithm' />");

  // create one step
  SedOneStep* step = doc.createOneStep();
  step->setId("sim2");
  step->setStep(0.1);
  alg = step->createAlgorithm();
  alg->setKisaoID("KISAO:0000019");


  // create steady state
  SedSteadyState* steady = doc.createSteadyState();
  steady->setId("sim3");
  alg = steady->createAlgorithm();
  alg->setKisaoID("KISAO:0000282");

  // create a task that uses the simulation and the model above
  SedTask* task = doc.createTask();
  task->setId("task1");
  task->setModelReference("model1");
  task->setSimulationReference("sim1");

  task = doc.createTask();
  task->setId("task2");
  task->setModelReference("model1");
  task->setSimulationReference("sim2");

  SedRepeatedTask* repeat = doc.createRepeatedTask();
  repeat->setId("task3");
  repeat->setRangeId("index");
  repeat->setResetModel(false);

  SedUniformRange* index = repeat->createUniformRange();
  index->setId("index");
  index->setStart(0);
  index->setEnd(10);
  index->setNumberOfPoints(100);
  index->setType("linear");

  SedFunctionalRange* current = repeat->createFunctionalRange();
  current->setId("current");
  current->setRange("index");
  current->setMath(SBML_parseFormula("piecewise(8, lt(index, 1), 0.1, and(geq(index, 4), lt(index, 6)), 8)"));

  SedVectorRange* vrange = repeat->createVectorRange();
  vrange->setId("vRange");
  vrange->addValue(8);
  vrange->addValue(4);
  vrange->addValue(0.1);


  SedSetValue* setValue = repeat->createTaskChange();
  setValue->setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='J0_v0']");
  setValue->setRange("current");
  setValue->setModelReference("model1");
  setValue->setMath(SBML_parseFormula("current"));

  SedSubTask* subTask = repeat->createSubTask();
  subTask->setTask("task1");
  subTask->setOrder(1);
  

  // add a DataGenerator to hold the output for time
  SedDataGenerator* dg = doc.createDataGenerator();
  dg->setId("time");
  dg->setName("time");
  SedVariable* var = dg->createVariable();
  var->setId("v0");
  var->setName("time");
  var->setTaskReference("task1");
  var->setSymbol("urn:sedml:symbol:time");
  dg->setMath(SBML_parseFormula("v0"));

  // and one for S1
  dg = doc.createDataGenerator();
  dg->setId("S1");
  dg->setName("S1");
  var = dg->createVariable();
  var->setId("v1");
  var->setName("S1");
  var->setTaskReference("task1");
  var->setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");
  dg->setMath(SBML_parseFormula("v1"));

  // add a report
  SedReport* report = doc.createReport();
  report->setId("r1");
  report->setName("report 1");
  SedDataSet* set = report->createDataSet();
  set->setId("ds1");
  set->setLabel("time");
  set->setDataReference("time");
  set = report->createDataSet();
  set->setId("ds2");
  set->setLabel("S1");
  set->setDataReference("S1");

  // add a 2d plot
  SedPlot2D* plot = doc.createPlot2D();
  plot->setId("p1");
  plot->setName("S1 Timecourse");
  SedCurve* curve = plot->createCurve();
  curve->setId("c1");
  curve->setName("S1");
  curve->setLogX(false);
  curve->setLogY(false);
  curve->setXDataReference("time");
  curve->setYDataReference("S1");

  // add a 3D Plot
  SedPlot3D* plot2 = doc.createPlot3D();
  plot2->setId("p2");
  plot2->setName("dunno");
  SedSurface* surf = plot2->createSurface();
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
