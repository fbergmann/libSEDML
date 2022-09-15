# 
# @file    create_sedml.R
# @brief   creates a SED-ML document.
# @author  Frank T. Bergmann
# 
# Usage: R --slave -f create_sedml.R --args <full path to input file> 
#
# <!--------------------------------------------------------------------------
# This file is part of libSEDML.  Please visit http://sed-ml.org for more
# information about SEDML, and the latest version of libSEDML.
# 
# Copyright (c) 2013, Frank T. Bergmann
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# ------------------------------------------------------------------------ -->
# 


library(libSEDML)

args <- commandArgs(trailingOnly = TRUE)

if (length(args) != 1)
{
  stop("Usage: create_sedml output-filename\n\n");
}

#  create the document 
doc = SedDocument(1,1);
SedDocument_setLevel(doc, 1);
SedDocument_setVersion(doc, 1);  


#  create a first model referencing an sbml file 
model = SedDocument_createModel(doc);
SedModel_setId(model, "model1");
SedModel_setSource(model, "file.xml");
SedModel_setLanguage(model, "urn:sedml:language:sbml");

#  create a second model modifying a variable of that other sbml file 
model = SedDocument_createModel(doc);
SedModel_setId(model, "model2");
SedModel_setSource(model, "model1");
SedModel_setLanguage(model, "urn:sedml:language:sbml");

#  change a paramerter 'k' to 0.1 
change = SedModel_createChangeAttribute(model);
SedChange_setTarget(change, "/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='k']/@value");
SedChangeAttribute_setNewValue(change, "0.1");

#  remove species 's1' 
removeXML = SedModel_createRemoveXML(model);
SedChange_setTarget(removeXML, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");

#  now for something tricky we want to update the initialConcentration of 'S2' to be
#  half what it was in the original model 
compute = SedModel_createComputeChange(model);
SedChange_setTarget( compute, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id=&quot;S2&quot;]/@initialConcentration");
variable = SedComputeChange_createVariable(compute);
SedVariable_setId(variable, "S2");
SedVariable_setModelReference(variable, "model1");
SedVariable_setTarget(variable, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S2']");
SedComputeChange_setMath(compute, parseFormula("S2 / 2"));

#  create simulation 
tc = SedDocument_createUniformTimeCourse(doc);
SedSimulation_setId(tc, "sim1");
SedUniformTimeCourse_setInitialTime(tc, 0.0);
SedUniformTimeCourse_setOutputStartTime(tc, 0.0);
SedUniformTimeCourse_setOutputEndTime(tc, 10.0);
SedUniformTimeCourse_setNumberOfPoints(tc, 1000);

#  need to set the correct KISAO Term 
algorithm = SedSimulation_createAlgorithm(tc);
SedAlgorithm_setKisaoID(algorithm,"KISAO:0000019");

#  create a task that uses the simulation and the model above 
task = SedDocument_createTask(doc);
SedTask_setId(task, "task1");
SedTask_setModelReference(task, "model1");
SedTask_setSimulationReference(task, "sim1");

#  add a DataGenerator to hold the output for time 
dg = SedDocument_createDataGenerator(doc);
SedDataGenerator_setId(dg, "time");
SedDataGenerator_setName(dg, "time");
variable = SedDataGenerator_createVariable(dg);
SedVariable_setId(variable, "v0");
SedVariable_setName(variable, "time");
SedVariable_setTaskReference(variable, "task1");
SedVariable_setSymbol(variable, "urn:sedml:symbol:time");
SedDataGenerator_setMath(dg, parseFormula("v0"));

#  and one for S1 
dg = SedDocument_createDataGenerator(doc);
SedDataGenerator_setId(dg, "S1");
SedDataGenerator_setName(dg, "S1");
variable = SedDataGenerator_createVariable(dg);
SedVariable_setId(variable, "v1");
SedVariable_setName(variable, "S1");
SedVariable_setTaskReference(variable, "task1");
SedVariable_setTarget(variable, "/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']");
SedDataGenerator_setMath(dg, parseFormula("v1"));

#  add a report 
report = SedDocument_createReport(doc);
SedOutput_setId(report,"r1");
SedOutput_setName(report,"report 1");
set = SedReport_createDataSet(report);
SedDataSet_setId(set, "ds1");
SedDataSet_setLabel(set, "time");
SedDataSet_setDataReference(set, "time");
SedDataSet_setId(set, "ds2");
SedDataSet_setLabel(set, "S1");
SedDataSet_setDataReference(set, "S1");

#  add a 2d plot 
plot2d = SedDocument_createPlot2D(doc);
SedOutput_setId(plot2d,"p1");
SedOutput_setName(plot2d,"S1 Timecourse");
curve = SedPlot2D_createCurve(plot2d);
SedCurve_setId(curve, "c1");
SedCurve_setName(curve, "S1");
SedCurve_setLogX(curve, 0);
SedCurve_setLogY(curve, 0);
SedCurve_setXDataReference(curve, "time");
SedCurve_setYDataReference(curve, "S1");

#  add a 3D Plot 
plot3d = SedDocument_createPlot3D(doc);
SedOutput_setId(plot3d,"p2");
SedOutput_setName(plot3d,"S1 Plane");
surf = SedPlot3D_createSurface(plot3d);
SedCurve_setId(surf,"surf1");
SedCurve_setName(surf,"S1");
SedCurve_setLogX(surf, 0);
SedCurve_setLogY(surf, 0);
SedCurve_setXDataReference(surf, "time");
SedCurve_setYDataReference(surf, "S1");
SedSurface_setLogZ(surf, 0);
SedSurface_setZDataReference(surf, "S1");

#  write the document 
writeSedML(doc, args[1]);

