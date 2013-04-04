/**
 * @file    print_sedml.c
 * @brief   Prints an overview of the elments in the given SED-ML document
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

int
main (int argc, char* argv[])
{
  SedMLDocument_t *doc;
  
  if (argc != 2)
  {
    printf("Usage: print_sedml input-filename\n\n");
    return 2;
  }

  doc = readSedML(argv[1]);
  
  printf("The document has %d simulation(s).\n",SedMLDocument_getNumSimulations(doc));
  for (unsigned int i = 0; i < SedMLDocument_getNumSimulations(doc); i++)
  {
    Simulation_t* current = SedMLDocument_getSimulation(doc,i);
    switch(SedBase_getTypeCode((SedBase_t*)current))
    {
       case SEDML_SIMULATION_UNIFORMTIMECOURSE:
       {
          UniformTimeCourse_t* tc = (UniformTimeCourse_t*)current;
          printf("\tTimecourse id=%s   start=%f end=%f numPoints=%d kisao=", 
            Simulation_getId(current), 
            UniformTimeCourse_getOutputStartTime(tc), 
            UniformTimeCourse_getOutputEndTime(tc), 
            UniformTimeCourse_getNumberOfPoints(tc)
	  	  );
          if (Simulation_isSetAlgorithm(current))
          {
            printf("%s\n", Algorithm_getKisaoID(Simulation_getAlgorithm(current)));
          }
          else
          {
            printf("none\n");
          }        
          break;
       }
       default:
          printf("\tUncountered unknown simulation %s.\n ", Simulation_getId(current));
          break;
    }
  }
  
  printf("\n");
  printf("The document has %d model(s).\n",SedMLDocument_getNumSedMLModels(doc));
  for (unsigned int i = 0; i < SedMLDocument_getNumSedMLModels(doc); i++)
  {
    SedMLModel_t* current =  SedMLDocument_getSedMLModel(doc,i);
    printf("\tModel id=%s  language=%s source=%s numChanges=%d\n", 
	       SedMLModel_getId(current), 
	       SedMLModel_getLanguage(current), 
	       SedMLModel_getSource(current), 
	       SedMLModel_getNumChanges(current));
  }
  
  printf("\n");
  printf("The document has %d task(s).\n",SedMLDocument_getNumTasks(doc));
  for (unsigned int i = 0; i < SedMLDocument_getNumTasks(doc); ++i)
  {
    Task_t* current =  SedMLDocument_getTask(doc,i);
    printf("\tTask id=%s  model=%s sim=%s\n", 
	  Task_getId(current),
	  Task_getModelReference(current),
	  Task_getSimulationReference(current));
  }

  printf("\n");
  printf("The document has %d datagenerators(s).\n",SedMLDocument_getNumDataGenerators(doc));
  for (unsigned int i = 0; i < SedMLDocument_getNumDataGenerators(doc); ++i)
  {
    DataGenerator_t* current = SedMLDocument_getDataGenerator(doc, i);
    printf("\tDG id=%s math=%s\n",
      Task_getId(current), 
	  SBML_formulaToString(Task_getMath(current)));
  }
  
  printf("\n");
  printf("The document has %d output(s).\n",SedMLDocument_getNumSedMLOutputs(doc));
  for (unsigned int i = 0; i < SedMLDocument_getNumSedMLOutputs(doc); ++i)
  {
    SedMLOutput_t* current = SedMLDocument_getSedMLOutput(doc,i);
    switch(current->getTypeCode())
    {
      case SEDML_OUTPUT_REPORT:
      {
        Report_t* r = (Report_t*)current;
        printf("\tReport id=%s numDataSets=%d\n", SedMLOutput_getId(current), Report_getNumDataSets(r));
        break;
      }
      case SEDML_OUTPUT_PLOT2D:
      {
        Plot2D_t* p = (Plot2D_t*)current;
		printf("\tPlot2D id=%s numCurves=%d\n", SedMLOutput_getId(current), Plot2D_getNumCurves(p));
        break;
      }
      case SEDML_OUTPUT_PLOT3D:
      {
        Plot3D_t* p = (Plot3D_t*)current;
		printf("\tPlot2D id=%s numSurfaces=%d\n", SedMLOutput_getId(current), Plot3D_getNumSurfaces(p));
        break;
      }
      default: 
        printf("\tEncountered unknown output %s\n", SedMLOutput_getId(current));
        break;
    }
  }

  return 0;
}
