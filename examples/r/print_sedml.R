# 
# @file    print_sedml.R
# @brief   Prints an overview of the elements in the given SED-ML document
# @author  Frank T. Bergmann
#
# Usage: R --slave -f print_sedml.R --args <full path to input file>
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
  stop("Usage: print_sedml input-filename\n\n");
}

doc = readSedML(args[1]);

cat("The document has ",SedDocument_getNumSimulations(doc)," simulation(s).\n");
for (i in seq_len(SedDocument_getNumSimulations(doc)))
{
  current = SedDocument_getSimulation(doc,i-1);
  switch(enumFromInteger(SedBase_getTypeCode(current), "_SedTypeCode_t"),
     "SEDML_SIMULATION_UNIFORMTIMECOURSE"=
     {
        tc = current;
        cat("\tTimecourse id=",SedSimulation_getId(current),"   start=",SedUniformTimeCourse_getOutputStartTime(tc)," end=",SedUniformTimeCourse_getOutputEndTime(tc)," numPoints=",SedUniformTimeCourse_getNumberOfPoints(tc)," kisao=");
        if (SedSimulation_isSetAlgorithm(current))
        {
          cat(SedAlgorithm_getKisaoID(SedSimulation_getAlgorithm(current)),"\n");
        }
        else
        {
          cat("none\n");
        }
     },
     "default"={
        cat("\tUncountered unknown simulation %s.\n ", SedSimulation_getId(current),"\n");    
	}
  );
}

cat("\n");
cat("The document has ",SedDocument_getNumModels(doc)," model(s).\n");
for (i in seq_len(SedDocument_getNumModels(doc)))
{
  current =  SedDocument_getModel(doc,i-1);
  cat("\tModel id=",SedModel_getId(current),"  language=",SedModel_getLanguage(current)," source=",SedModel_getSource(current)," numChanges=",SedModel_getNumChanges(current),"\n");
}

cat("\n");
cat("The document has ",SedDocument_getNumTasks(doc)," task(s).\n");
for (i in seq_len(SedDocument_getNumTasks(doc)))
{
  current =  SedDocument_getTask(doc,i-1);
  cat("\tTask id=",SedTask_getId(current),"  model=",SedTask_getModelReference(current)," sim=",SedTask_getSimulationReference(current),"\n");
}

cat("\n");
cat("The document has ",SedDocument_getNumDataGenerators(doc)," datagenerators(s).\n");
for (i in seq_len(SedDocument_getNumDataGenerators(doc)))
{
  current = SedDocument_getDataGenerator(doc, i-1);
  cat("\tDG id=",SedDataGenerator_getId(current)," math=",formulaToString(SedDataGenerator_getMath(current)),"\n");
}

cat("\n");
cat("The document has ",SedDocument_getNumOutputs(doc)," output(s).\n");
for (i in seq_len(SedDocument_getNumOutputs(doc)))
{
  current = SedDocument_getOutput(doc,i-1);
  switch(enumFromInteger(SedBase_getTypeCode(current), "_SedTypeCode_t"),
   "SEDML_OUTPUT_REPORT" =
    {
      r = current;
      cat("\tReport id=",SedOutput_getId(current)," numDataSets=", SedReport_getNumDataSets(r),"\n");      
    },
    "SEDML_OUTPUT_PLOT2D"=
    {
      p = current;
      cat("\tPlot2D id=",SedOutput_getId(current)," numCurves=", SedPlot2D_getNumCurves(p),"\n");
    },
    "SEDML_OUTPUT_PLOT3D"=
    {
      p = current;
      cat("\tPlot3D id=", SedOutput_getId(current)," numSurfaces=",SedPlot3D_getNumSurfaces(p),"\n");      
    },
    "default"=
    {	
      cat("\tEncountered unknown output %s\n", SedOutput_getId(current),"\n");
    });
}
