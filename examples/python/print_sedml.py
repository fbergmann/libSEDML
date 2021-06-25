#!/usr/bin/env python
## 
## @file    print_sedml.py
## @brief   Prints an overview of the elments in the given SED-ML document
## @author  Frank T. Bergmann
## 
## <!--------------------------------------------------------------------------
## This file is part of libSEDML.  Please visit http://sed-ml.org for more
## information about SEDML, and the latest version of libSEDML.
## 
## Copyright (c) 2013, Frank T. Bergmann  
## All rights reserved.
## 
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions are met: 
## 
## 1. Redistributions of source code must retain the above copyright notice, this
##    list of conditions and the following disclaimer. 
## 2. Redistributions in binary form must reproduce the above copyright notice,
##    this list of conditions and the following disclaimer in the documentation
##    and/or other materials provided with the distribution. 
## 
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
## ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
## WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
## DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
## ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
## ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
## SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
## ------------------------------------------------------------------------ -.
## 

from __future__ import print_function
import sys
import os.path
import libsedml


def print_change(change):
  # type: (libsedml.SedSetValue) -> None
  print("\t\tChange model=", change.getModelReference(), " target=", change.getTarget(), 
        " range=", change.getRange(), 
        " math=", libsedml.formulaToString(change.getMath()), "\n")

def print_repeated_task(current):
  # type: (libsedml.SedRepeatedTask) -> None
  print ("\tRepeatedTask id=" , current.getId() , " range=" , current.getRangeId() , " resetModel=" , current.getResetModel() , "\n")
  for i in range(current.getNumRanges()):
    print("\t\tRange: id=",current.getRange(i).getId())
  
  for i in range(current.getNumTaskChanges()):
    print_change(current.getTaskChange(i))

  for i in range(current.getNumSubTasks()):
    print("\t\tSubtask order=",current.getSubTask(i).getOrder(), 
          " task=", current.getSubTask(i).getTask(), "\n")

def main (args):
  """Usage: print_sedml input-filename
  """
  if len(args) != 2:
    print(main.__doc__)
    sys.exit(1)

  doc = libsedml.readSedML(args[1])
  if doc.getErrorLog().getNumFailsWithSeverity(libsedml.LIBSEDML_SEV_ERROR) > 0:
    print (doc.getErrorLog().toString())
    sys.exit(2) 
  
  print ('The document has {0}" simulation(s).'.format(doc.getNumSimulations()))
  for i  in range(0, doc.getNumSimulations()):
    current = doc.getSimulation(i)
    if current.getTypeCode() == libsedml.SEDML_SIMULATION_UNIFORMTIMECOURSE:
      tc = current
      kisaoid="none"
      if tc.isSetAlgorithm():
        kisaoid=tc.getAlgorithm().getKisaoID()
      print ("\tTimecourse id=", tc.getId()," start=",tc.getOutputStartTime()," end=",tc.getOutputEndTime()," numPoints=",tc.getNumberOfPoints()," kisao=",kisaoid,"\n")
    elif current.getTypeCode() == libsedml.SEDML_SIMULATION_STEADYSTATE:
      print ("\tSteadyState id=", current.getId(),"\n")
    elif current.getTypeCode() == libsedml.SEDML_SIMULATION_ONESTEP:
      print ("\tOneStep id=", current.getId(),"\n")
    elif current.getTypeCode() == libsedml.SEDML_SIMULATION_ANALYSIS:
      print ("\tAnalysis id=", current.getId(),"\n")
    else:
      print ("\tUncountered unknown simulation. ",current.getId(),"\n")
  
  print ("\n")
  print ("The document has ", doc.getNumModels() , " model(s)." , "\n")
  for i in range(0,doc.getNumModels()):
    current = doc.getModel(i)
    print ("\tModel id=" , current.getId() , " language=" , current.getLanguage() , " source=" , current.getSource() , " numChanges=" , current.getNumChanges() , "\n")
  
  print ("\n")
  print ("The document has %d task(s)." % doc.getNumTasks())
  for i in range(0,doc.getNumTasks()):
    current = doc.getTask(i)
    if current.getTypeCode() == libsedml.SEDML_TASK_REPEATEDTASK:
      print_repeated_task(current)
    else: 
      print ("\tTask id=" , current.getId() , " model=" , current.getModelReference() , " sim=" , current.getSimulationReference() , "\n")

  print ("\n")
  print ("The document has " , doc.getNumDataGenerators() , " datagenerators(s)." , "\n")
  for i in range( 0,  doc.getNumDataGenerators()):
    current = doc.getDataGenerator(i)
    print ("\tDG id=" , current.getId() , " math=" , libsedml.formulaToString(current.getMath()) , "\n")
  
  print ("\n")
  print ("The document has " , doc.getNumOutputs() , " output(s)." , "\n")
  for i in range (0, doc.getNumOutputs()):
    current = doc.getOutput(i)
    tc = current.getTypeCode()
    if tc == libsedml.SEDML_OUTPUT_REPORT:
      r = current
      print ("\tReport id=" , current.getId() , " numDataSets=" , r.getNumDataSets() , "\n")
    elif tc == libsedml.SEDML_OUTPUT_PLOT2D:
      p = current
      print ("\tPlot2d id=" , current.getId() , " numCurves=" , p.getNumCurves() , "\n")
    elif tc == libsedml.SEDML_OUTPUT_PLOT3D:
      p = current
      print ("\tPlot3d id=" , current.getId() , " numSurfaces=" , p.getNumSurfaces() , "\n")
    else: 
      print ("\tEncountered unknown output " , current.getId() , "\n")
  
if __name__ == '__main__':
  main(sys.argv)
