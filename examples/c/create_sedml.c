/**
 * @file    create_sedml.c
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


#include <stdio.h>
#include <sedml/SedMLTypes.h>
#include <sbml/math/FormulaParser.h>

int
main (int argc, char* argv[])
{
  /* declare all variables */ 
  SedMLDocument_t *doc;
  SedMLModel_t *model;
  ChangeAttribute_t *change;
  RemoveXML_t *remove;
  ComputeChange_t *compute;
  SedMLVariable_t *variable;
  UniformTimeCourse_t *tc;
  Algorithm_t *algorithm;
  Task_t *task;
  DataGenerator_t *dg;
  Report_t *report;
  DataSet_t *set;
  Plot2D_t *plot2d;
  SedMLCurve_t *curve;
  Plot3D_t *plot3d;
  Surface_t *surf;

  if (argc != 2)
  {
    printf("Usage: create_sedml output-filename\n\n");
    return 2;
  }

  /* create the document */
  doc = SedMLDocument_create(1,1);
  SedMLDocument_setLevel(doc, 1);
  SedMLDocument_setVersion(doc, 1);  

  
  /* create a first model referencing an sbml file */
  model = SedMLDocument_createSedMLModel(doc);
  SedMLModel_setId(model, "model1");
  SedMLModel_setSource(model, "file.xml");
  SedMLModel_setLanguage(model, "urn:sedml:sbml");

  /* create a second model modifying a variable of that other sbml file */
  model = SedMLDocument_createSedMLModel(doc);
  SedMLModel_setId(model, "model2");
  SedMLModel_setSource(model, "model1");
  SedMLModel_setLanguage(model, "urn:sedml:sbml");

  /* change a paramerter 'k' to 0.1 */
  change = SedMLModel_createChangeAttribute(model);
  Change_setTarget((Change_t*)change, "/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='k']/@value");
  ChangeAttribute_setNewValue(change, "0.1");

  /* remove species 's1' */
  remove = SedMLModel_createRemoveXML(model);
  Change_setTarget((Change_t*)remove, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");

  /* now for something tricky we want to update the initialConcentration of 'S2' to be
   * half what it was in the original model */
  compute = SedMLModel_createComputeChange(model);
  Change_setTarget((Change_t*) compute, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id=&quot;S2&quot;]/@initialConcentration");
  variable = ComputeChange_createSedMLVariable(compute);
  SedMLVariable_setId(variable, "S2");
  SedMLVariable_setModelReference(variable, "model1");
  SedMLVariable_setTarget(variable, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S2']");
  ComputeChange_setMath(compute, SBML_parseFormula("S2 / 2"));
  
  /* create simulation */
  tc = SedMLDocument_createUniformTimeCourse(doc);
  Simulation_setId((Simulation_t*)tc, "sim1");
  UniformTimeCourse_setInitialTime(tc, 0.0);
  UniformTimeCourse_setOutputStartTime(tc, 0.0);
  UniformTimeCourse_setOutputEndTime(tc, 10.0);
  UniformTimeCourse_setNumberOfPoints(tc, 1000);
  
  /* need to set the correct KISAO Term */
  algorithm = Simulation_createAlgorithm((Simulation_t*)tc);
  Algorithm_setKisaoID(algorithm,"KISAO:0000019");

  /* create a task that uses the simulation and the model above */
  task = SedMLDocument_createTask(doc);
  Task_setId(task, "task1");
  Task_setModelReference(task, "model1");
  Task_setSimulationReference(task, "sim1");

  /* add a DataGenerator to hold the output for time */
  dg = SedMLDocument_createDataGenerator(doc);
  DataGenerator_setId(dg, "time");
  DataGenerator_setName(dg, "time");
  variable = DataGenerator_createSedMLVariable(dg);
  SedMLVariable_setId(variable, "v0");
  SedMLVariable_setName(variable, "time");
  SedMLVariable_setTaskReference(variable, "task1");
  SedMLVariable_setSymbol(variable, "urn:sedml:symbol:time");
  DataGenerator_setMath(dg, SBML_parseFormula("v0"));

  /* and one for S1 */
  dg = SedMLDocument_createDataGenerator(doc);
  DataGenerator_setId(dg, "S1");
  DataGenerator_setName(dg, "S1");
  variable = DataGenerator_createSedMLVariable(dg);
  SedMLVariable_setId(variable, "v1");
  SedMLVariable_setName(variable, "S1");
  SedMLVariable_setTaskReference(variable, "task1");
  SedMLVariable_setTarget(variable, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");
  DataGenerator_setMath(dg, SBML_parseFormula("v1"));

  /* add a report */
  report = SedMLDocument_createReport(doc);
  SedMLOutput_setId((SedMLOutput_t*)report,"r1");
  SedMLOutput_setName((SedMLOutput_t*)report,"report 1");
  set = Report_createDataSet(report);
  DataSet_setId(set, "ds1");
  DataSet_setLabel(set, "time");
  DataSet_setDataReference(set, "time");
  DataSet_setId(set, "ds2");
  DataSet_setLabel(set, "S1");
  DataSet_setDataReference(set, "S1");

  /* add a 2d plot */
  plot2d = SedMLDocument_createPlot2D(doc);
  SedMLOutput_setId((SedMLOutput_t*)plot2d,"p1");
  SedMLOutput_setName((SedMLOutput_t*)plot2d,"S1 Timecourse");
  curve = Plot2D_createSedMLCurve(plot2d);
  SedMLCurve_setId(curve, "c1");
  SedMLCurve_setName(curve, "S1");
  SedMLCurve_setLogX(curve, 0);
  SedMLCurve_setLogY(curve, 0);
  SedMLCurve_setXDataReference(curve, "time");
  SedMLCurve_setYDataReference(curve, "S1");

  /* add a 3D Plot */
  plot3d = SedMLDocument_createPlot3D(doc);
  SedMLOutput_setId((SedMLOutput_t*)plot3d,"p2");
  SedMLOutput_setName((SedMLOutput_t*)plot3d,"S1 Plane");
  surf = Plot3D_createSurface(plot3d);
  SedMLCurve_setId((SedMLCurve_t*)surf,"surf1");
  SedMLCurve_setName((SedMLCurve_t*)surf,"S1");
  SedMLCurve_setLogX((SedMLCurve_t*)surf, 0);
  SedMLCurve_setLogY((SedMLCurve_t*)surf, 0);
  SedMLCurve_setXDataReference((SedMLCurve_t*)surf, "time");
  SedMLCurve_setYDataReference((SedMLCurve_t*)surf, "S1");
  Surface_setLogZ(surf, 0);
  Surface_setZDataReference(surf, "S1");

  /* write the document */
  writeSedML(doc, argv[1]);

  return 0;
}
