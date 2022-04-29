/**
 * @file    print_sedml.c
 * @brief   Prints an overview of the elments in the given SED-ML document
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
#include <sedml/SedTypeCodes.h>
#include <sbml/math/FormulaFormatter.h>


int
main (int argc, char* argv[])
{
  SedDocument_t *doc;
  unsigned int i;  
  
  if (argc != 2)
  {
    printf("Usage: print_sedml input-filename\n\n");
    return 2;
  }

  doc = readSedML(argv[1]);

  printf("The document has %d data description(s).\n", SedDocument_getNumDataDescriptions(doc));
  for (i = 0; i < SedDocument_getNumDataDescriptions(doc); i++)
  {
    SedDataDescription_t* dd = SedDocument_getDataDescription(doc, i);
    printf("\tDataDescription id=%s format=%s source=%s",
      SedDataDescription_getId(dd),
      SedDataDescription_getFormat(dd),
      SedDataDescription_getSource(dd)
    );
  }

  printf("The document has %d simulation(s).\n",SedDocument_getNumSimulations(doc));
  for (i = 0; i < SedDocument_getNumSimulations(doc); i++)
  {
    SedSimulation_t* current = SedDocument_getSimulation(doc,i);
    switch(SedBase_getTypeCode((SedBase_t*)current))
    {
       case SEDML_SIMULATION_UNIFORMTIMECOURSE:
       {
          SedUniformTimeCourse_t* tc = (SedUniformTimeCourse_t*)current;
          printf("\tTimecourse id=%s   start=%f end=%f numPoints=%d kisao=", 
            SedSimulation_getId(current), 
            SedUniformTimeCourse_getOutputStartTime(tc), 
            SedUniformTimeCourse_getOutputEndTime(tc), 
            SedUniformTimeCourse_getNumberOfPoints(tc)
	  	  );
          if (SedSimulation_isSetAlgorithm(current))
          {
            printf("%s\n", SedAlgorithm_getKisaoID(SedSimulation_getAlgorithm(current)));
          }
          else
          {
            printf("none\n");
          }        
          break;
       }
       default:
          printf("\tUncountered unknown simulation %s.\n ", SedSimulation_getId(current));
          break;
    }
  }
  
  printf("\n");
  printf("The document has %d model(s).\n",SedDocument_getNumModels(doc));
  for (i = 0; i < SedDocument_getNumModels(doc); i++)
  {
    SedModel_t* current =  SedDocument_getModel(doc,i);
    printf("\tModel id=%s  language=%s source=%s numChanges=%d\n", 
	       SedModel_getId(current), 
	       SedModel_getLanguage(current), 
	       SedModel_getSource(current), 
	       SedModel_getNumChanges(current));
  }
  
  printf("\n");
  printf("The document has %d task(s).\n",SedDocument_getNumTasks(doc));
  for (i = 0; i < SedDocument_getNumTasks(doc); ++i)
  {
    SedAbstractTask_t* abstractTask = SedDocument_getTask(doc, i);
    int typeCode = SedBase_getTypeCode((SedBase_t*)abstractTask);
    if (typeCode == SEDML_TASK)
    {
      SedTask_t* current =  (SedTask_t*)SedDocument_getTask(doc,i);
      printf("\tTask id=%s  model=%s sim=%s\n", 
	    SedAbstractTask_getId((SedAbstractTask_t*)current),
	    SedTask_getModelReference(current),
	    SedTask_getSimulationReference(current));
    }
  }

  printf("\n");
  printf("The document has %d datagenerators(s).\n",SedDocument_getNumDataGenerators(doc));
  for (i = 0; i < SedDocument_getNumDataGenerators(doc); ++i)
  {
    SedDataGenerator_t* current = SedDocument_getDataGenerator(doc, i);
    printf("\tDG id=%s math=%s\n",
      SedDataGenerator_getId(current), 
	  SBML_formulaToString(SedDataGenerator_getMath(current)));
  }
  
  printf("\n");
  printf("The document has %d output(s).\n",SedDocument_getNumOutputs(doc));
  for (i = 0; i < SedDocument_getNumOutputs(doc); ++i)
  {
    SedOutput_t* current = SedDocument_getOutput(doc,i);
    switch(SedBase_getTypeCode((SedBase_t*)current))
    {
      case SEDML_OUTPUT_REPORT:
      {
        SedReport_t* r = (SedReport_t*)current;
        printf("\tReport id=%s numDataSets=%d\n", SedOutput_getId(current), SedReport_getNumDataSets(r));
        break;
      }
      case SEDML_OUTPUT_PLOT2D:
      {
        SedPlot2D_t* p = (SedPlot2D_t*)current;
		printf("\tPlot2D id=%s numCurves=%d\n", SedOutput_getId(current), SedPlot2D_getNumCurves(p));
        break;
      }
      case SEDML_OUTPUT_PLOT3D:
      {
        SedPlot3D_t* p = (SedPlot3D_t*)current;
		printf("\tPlot3D id=%s numSurfaces=%d\n", SedOutput_getId(current), SedPlot3D_getNumSurfaces(p));
        break;
      }
      default: 
        printf("\tEncountered unknown output %s\n", SedOutput_getId(current));
        break;
    }
  }

  return 0;
}
