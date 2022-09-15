/**
 * @file    create_sedml.c
 * @brief   cerates a SED-ML document.
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


#include <stdio.h>
#include <sedml/SedTypes.h>
#include <sbml/math/FormulaParser.h>

int
main (int argc, char* argv[])
{
  /* declare all variables */ 
  SedDocument_t *doc;
  SedModel_t *model;
  SedChangeAttribute_t *change;
  SedRemoveXML_t *remove;
  SedComputeChange_t *compute;
  SedVariable_t *variable;
  SedUniformTimeCourse_t *tc;
  SedAlgorithm_t *algorithm;
  SedTask_t *task;
  SedDataGenerator_t *dg;
  SedReport_t *report;
  SedDataSet_t *set;
  SedPlot2D_t *plot2d;
  SedCurve_t *curve;
  SedPlot3D_t *plot3d;
  SedSurface_t *surf;

  if (argc != 2)
  {
    printf("Usage: create_sedml output-filename\n\n");
    return 2;
  }

  /* create the document */
  doc = SedDocument_create(1,1);
  SedDocument_setLevel(doc, 1);
  SedDocument_setVersion(doc, 1);  

  
  /* create a first model referencing an sbml file */
  model = SedDocument_createModel(doc);
  SedModel_setId(model, "model1");
  SedModel_setSource(model, "file.xml");
  SedModel_setLanguage(model, "urn:sedml:language:sbml");

  /* create a second model modifying a variable of that other sbml file */
  model = SedDocument_createModel(doc);
  SedModel_setId(model, "model2");
  SedModel_setSource(model, "model1");
  SedModel_setLanguage(model, "urn:sedml:language:sbml");

  /* change a paramerter 'k' to 0.1 */
  change = SedModel_createChangeAttribute(model);
  SedChange_setTarget((SedChange_t*)change, "/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='k']/@value");
  SedChangeAttribute_setNewValue(change, "0.1");

  /* remove species 's1' */
  remove = SedModel_createRemoveXML(model);
  SedChange_setTarget((SedChange_t*)remove, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");

  /* now for something tricky we want to update the initialConcentration of 'S2' to be
   * half what it was in the original model */
  compute = SedModel_createComputeChange(model);
  SedChange_setTarget((SedChange_t*) compute, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id=&quot;S2&quot;]/@initialConcentration");
  variable = SedComputeChange_createVariable(compute);
  SedBase_setId((SedBase_t *)variable, "S2");
  SedVariable_setModelReference(variable, "model1");
  SedVariable_setTarget(variable, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S2']");
  SedComputeChange_setMath(compute, SBML_parseFormula("S2 / 2"));
  
  /* create simulation */
  tc = SedDocument_createUniformTimeCourse(doc);
  SedSimulation_setId((SedSimulation_t*)tc, "sim1");
  SedUniformTimeCourse_setInitialTime(tc, 0.0);
  SedUniformTimeCourse_setOutputStartTime(tc, 0.0);
  SedUniformTimeCourse_setOutputEndTime(tc, 10.0);
  SedUniformTimeCourse_setNumberOfPoints(tc, 1000);
  
  /* need to set the correct KISAO Term */
  algorithm = SedSimulation_createAlgorithm((SedSimulation_t*)tc);
  SedAlgorithm_setKisaoID(algorithm,"KISAO:0000019");

  /* create a task that uses the simulation and the model above */
  task = SedDocument_createTask(doc);
  SedAbstractTask_setId((SedAbstractTask_t*)task, "task1");
  SedTask_setModelReference(task, "model1");
  SedTask_setSimulationReference(task, "sim1");

  /* add a DataGenerator to hold the output for time */
  dg = SedDocument_createDataGenerator(doc);
  SedDataGenerator_setId(dg, "time");
  SedDataGenerator_setName(dg, "time");
  variable = SedDataGenerator_createVariable(dg);
  SedBase_setId((SedBase_t *)variable, "v0");
  SedBase_setName((SedBase_t *)variable, "time");
  SedVariable_setTaskReference(variable, "task1");
  SedVariable_setSymbol(variable, "urn:sedml:symbol:time");
  SedDataGenerator_setMath(dg, SBML_parseFormula("v0"));

  /* and one for S1 */
  dg = SedDocument_createDataGenerator(doc);
  SedDataGenerator_setId(dg, "S1");
  SedDataGenerator_setName(dg, "S1");
  variable = SedDataGenerator_createVariable(dg);
  SedBase_setId((SedBase_t *)variable, "v1");
  SedBase_setName((SedBase_t *)variable, "S1");
  SedVariable_setTaskReference(variable, "task1");
  SedVariable_setTarget(variable, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");
  SedDataGenerator_setMath(dg, SBML_parseFormula("v1"));

  /* add a report */
  report = SedDocument_createReport(doc);
  SedOutput_setId((SedOutput_t*)report,"r1");
  SedOutput_setName((SedOutput_t*)report,"report 1");
  set = SedReport_createDataSet(report);
  SedDataSet_setId(set, "ds1");
  SedDataSet_setLabel(set, "time");
  SedDataSet_setDataReference(set, "time");
  SedDataSet_setId(set, "ds2");
  SedDataSet_setLabel(set, "S1");
  SedDataSet_setDataReference(set, "S1");

  /* add a 2d plot */
  plot2d = SedDocument_createPlot2D(doc);
  SedOutput_setId((SedOutput_t*)plot2d,"p1");
  SedOutput_setName((SedOutput_t*)plot2d,"S1 Timecourse");
  curve = SedPlot2D_createCurve(plot2d);
  SedAbstractCurve_setId((SedAbstractCurve_t*)curve, "c1");
  SedAbstractCurve_setName((SedAbstractCurve_t*)curve, "S1");
  SedAbstractCurve_setLogX((SedAbstractCurve_t*)curve, 0);
  SedCurve_setLogY(curve, 0);
  SedCurve_setType(curve, SEDML_CURVETYPE_POINTS);
  SedAbstractCurve_setXDataReference((SedAbstractCurve_t*)curve, "time");
  SedCurve_setYDataReference(curve, "S1");

  /* add a 3D Plot */
  plot3d = SedDocument_createPlot3D(doc);
  SedOutput_setId((SedOutput_t*)plot3d,"p2");
  SedOutput_setName((SedOutput_t*)plot3d,"S1 Plane");
  surf = SedPlot3D_createSurface(plot3d);
  SedAbstractCurve_setId((SedAbstractCurve_t*)surf,"surf1");
  SedAbstractCurve_setName((SedAbstractCurve_t*)surf,"S1");
  SedAbstractCurve_setLogX((SedAbstractCurve_t*)surf, 0);
  SedCurve_setLogY((SedCurve_t*)surf, 0);
  
  SedAbstractCurve_setXDataReference((SedAbstractCurve_t*)surf, "time");
  SedCurve_setYDataReference((SedCurve_t*)surf, "S1");
  SedSurface_setLogZ(surf, 0);
  SedSurface_setZDataReference(surf, "S1");

  /* write the document */
  writeSedML(doc, argv[1]);

  return 0;
}
