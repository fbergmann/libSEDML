/*
 * @file    print_sedml.java
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
 * ------------------------------------------------------------------------ -.
 */

import java.io.*;
import org.sedml.libsedml.*;

public class print_sedml
{


public static void main (String[] args)
{
  if (args.length != 1)
  {
    System.out.println("Usage: print_sedml input-filename\n" );         
    System.exit(2);
  }

  System.loadLibrary("sedmlj");
  
  SedDocument doc = libsedml.readSedML(args[0]);
  if ( doc.getErrorLog().getNumFailsWithSeverity(libsedml.LIBSEDML_SEV_ERROR) > 0)
  {
    System.out.println(doc.getErrorLog().toString());
    System.exit(2); 
  }
  
  System.out.println("The document has " + doc.getNumSimulations() + " simulation(s).\n");
  for (int i = 0; i < doc.getNumSimulations(); ++i)
  {
    SedSimulation current = doc.getSimulation(i);
    switch(current.getTypeCode())
    {
       case libsedml.SEDML_SIMULATION_UNIFORMTIMECOURSE:
       {
          SedUniformTimeCourse tc = (SedUniformTimeCourse)(current);
          System.out.println( "\tTimecourse id=" + tc.getId() + " start=" + tc.getOutputStartTime() + " end=" + tc.getOutputEndTime() + " numPoints=" + tc.getNumberOfPoints() + " kisao=" + (tc.isSetAlgorithm() ? tc.getAlgorithm().getKisaoID() : "none") + "\n");
          break;
       }
       default:
          System.out.println( "\tUncountered unknown simulation. " + current.getId() + "\n");
          break;
    }
  }
  
  System.out.println( "\n");
  System.out.println( "The document has " + doc.getNumModels() + " model(s).\n");
  for (int i = 0; i < doc.getNumModels(); ++i)
  {
    SedModel current = doc.getModel(i);
    System.out.println( "\tModel id=" + current.getId() + " language=" + current.getLanguage() + " source=" + current.getSource() + " numChanges=" + current.getNumChanges() + "\n");
  }
  
  System.out.println( "\n");
  System.out.println( "The document has " + doc.getNumTasks() + " task(s).\n");
  for (int i = 0; i < doc.getNumTasks(); ++i)
  {
    SedTask current = (SedTask)doc.getTask(i);
    System.out.println( "\tTask id=" + current.getId() + " model=" + current.getModelReference() + " sim=" + current.getSimulationReference() + "\n");
  }

  System.out.println( "\n");
  System.out.println( "The document has " + doc.getNumDataGenerators() + " datagenerators(s).\n");
  for (int i = 0; i < doc.getNumDataGenerators(); ++i)
  {
    SedDataGenerator current = doc.getDataGenerator(i);
    System.out.println( "\tDG id=" + current.getId() + " math=" + libsedml.formulaToString(current.getMath()) + "\n");
  }
  
  System.out.println( "\n");
  System.out.println( "The document has " + doc.getNumOutputs() + " output(s).\n");
  for (int i = 0; i < doc.getNumOutputs(); ++i)
  {
    SedOutput current = doc.getOutput(i);
    switch(current.getTypeCode())
    {
      case libsedml.SEDML_OUTPUT_REPORT:
      {
        SedReport r = (SedReport)(current);
        System.out.println( "\tReport id=" + current.getId() + " numDataSets=" + r.getNumDataSets() + "\n");
        break;
      }
      case libsedml.SEDML_OUTPUT_PLOT2D:
      {
        SedPlot2D p = (SedPlot2D)(current);
        System.out.println( "\tPlot2d id=" + current.getId() + " numCurves=" + p.getNumCurves() + "\n");
        break;
      }
      case libsedml.SEDML_OUTPUT_PLOT3D:
      {
        SedPlot3D p = (SedPlot3D)(current);
        System.out.println( "\tPlot3d id=" + current.getId() + " numSurfaces=" + p.getNumSurfaces() + "\n");
        break;
      }
      default: 
        System.out.println( "\tEncountered unknown output " + current.getId() + "\n");
        break;
    }
  }

  System.exit(0);
}

}