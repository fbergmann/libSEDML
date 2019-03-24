/*
 * @file    print_sedml.cs
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

using System;
using System.IO;
using libsedmlcs;


public class print_sedml
{


public static int Main (string[] args)
{
  if (args.Length != 1)
  {
    Console.WriteLine("{0}Usage: print_sedml input-filename{0}{0}", Environment.NewLine );         
    return 2;
  }

  SedDocument doc = libsedml.readSedML(args[0]);
  if ( doc.getErrorLog().getNumFailsWithSeverity(libsedml.LIBSEDML_SEV_ERROR) > 0)
  {
    Console.WriteLine(doc.getErrorLog().toString());
    return 2; 
  }
  
  Console.WriteLine("The document has " + doc.getNumSimulations() + " simulation(s)." + Environment.NewLine);
  for (int i = 0; i < doc.getNumSimulations(); ++i)
  {
    SedSimulation current = doc.getSimulation(i);
    switch(current.getTypeCode())
    {
       case libsedml.SEDML_SIMULATION_UNIFORMTIMECOURSE:
       {
          SedUniformTimeCourse tc = (SedUniformTimeCourse)(current);
          Console.WriteLine( "\tTimecourse id=" + tc.getId() + " start=" + tc.getOutputStartTime() + " end=" + tc.getOutputEndTime() + " numPoints=" + tc.getNumberOfPoints() + " kisao=" + (tc.isSetAlgorithm() ? tc.getAlgorithm().getKisaoID() : "none") + Environment.NewLine);
          break;
       }
       default:
          Console.WriteLine( "\tUncountered unknown simulation. " + current.getId() + Environment.NewLine);
          break;
    }
  }
  
  Console.WriteLine( Environment.NewLine);
  Console.WriteLine( "The document has " + doc.getNumModels() + " model(s)." + Environment.NewLine);
  for (int i = 0; i < doc.getNumModels(); ++i)
  {
    SedModel current = doc.getModel(i);
    Console.WriteLine( "\tModel id=" + current.getId() + " language=" + current.getLanguage() + " source=" + current.getSource() + " numChanges=" + current.getNumChanges() + Environment.NewLine);
  }
  
  Console.WriteLine( Environment.NewLine);
  Console.WriteLine( "The document has " + doc.getNumTasks() + " task(s)." + Environment.NewLine);
  for (int i = 0; i < doc.getNumTasks(); ++i)
  {
    SedTask current = (SedTask)doc.getTask(i);
    Console.WriteLine( "\tTask id=" + current.getId() + " model=" + current.getModelReference() + " sim=" + current.getSimulationReference() + Environment.NewLine);
  }

  Console.WriteLine( Environment.NewLine);
  Console.WriteLine( "The document has " + doc.getNumDataGenerators() + " datagenerators(s)." + Environment.NewLine);
  for (int i = 0; i < doc.getNumDataGenerators(); ++i)
  {
    SedDataGenerator current = doc.getDataGenerator(i);
    Console.WriteLine( "\tDG id=" + current.getId() + " math=" + libsedml.formulaToString(current.getMath()) + Environment.NewLine);
  }
  
  Console.WriteLine( Environment.NewLine);
  Console.WriteLine( "The document has " + doc.getNumOutputs() + " output(s)." + Environment.NewLine);
  for (int i = 0; i < doc.getNumOutputs(); ++i)
  {
    SedOutput current = doc.getOutput(i);
    switch(current.getTypeCode())
    {
      case libsedml.SEDML_OUTPUT_REPORT:
      {
        SedReport r = (SedReport)(current);
        Console.WriteLine( "\tReport id=" + current.getId() + " numDataSets=" + r.getNumDataSets() + Environment.NewLine);
        break;
      }
      case libsedml.SEDML_OUTPUT_PLOT2D:
      {
        SedPlot2D p = (SedPlot2D)(current);
        Console.WriteLine( "\tPlot2d id=" + current.getId() + " numCurves=" + p.getNumCurves() + Environment.NewLine);
        break;
      }
      case libsedml.SEDML_OUTPUT_PLOT3D:
      {
        SedPlot3D p = (SedPlot3D)(current);
        Console.WriteLine( "\tPlot3d id=" + current.getId() + " numSurfaces=" + p.getNumSurfaces() + Environment.NewLine);
        break;
      }
      default: 
        Console.WriteLine( "\tEncountered unknown output " + current.getId() + Environment.NewLine);
        break;
    }
  }

  return 0;
}

}