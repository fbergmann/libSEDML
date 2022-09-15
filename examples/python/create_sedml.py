#!/usr/bin/env python
## 
## @file    create_sedml.py
## @brief   cerates a SED-ML document.
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

import sys
import os.path
import libsedml


def main (args):
  """Usage: create_sedml output-filename
  """
  if len(args) != 2:
    print(main.__doc__)
    sys.exit(1)

  # create the document
  doc = libsedml.SedDocument()
  doc.setLevel(1)
  doc.setVersion(1)

  # create a first model referencing an sbml file
  model = doc.createModel()
  model.setId("model1")
  model.setSource("file.xml")
  model.setLanguage("urn:sedml:language:sbml")

  # create a second model modifying a variable of that other sbml file
  model = doc.createModel()
  model.setId("model2")
  model.setSource("model1")
  model.setLanguage("urn:sedml:language:sbml")

  # change a paramerter 'k' to 0.1
  change = model.createChangeAttribute()
  change.setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='k']/@value")
  change.setNewValue("0.1")

  # remove species 's1'
  remove = model.createRemoveXML()
  remove.setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']")

  # now for something tricky we want to update the initialConcentration of 'S2' to be
  # half what it was in the original model
  compute = model.createComputeChange()
  compute.setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id=&quot;S2&quot;]/@initialConcentration")
  variable = compute.createVariable()
  variable.setId("S2")
  variable.setModelReference("model1")
  variable.setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S2']")
  compute.setMath(libsedml.parseFormula("S2 / 2"))  

  # create simulation
  tc = doc.createUniformTimeCourse()
  tc.setId("sim1")
  tc.setInitialTime(0.0)
  tc.setOutputStartTime(0.0)
  tc.setOutputEndTime(10.0)
  tc.setNumberOfPoints(1000)
  # need to set the correct KISAO Term
  alg = tc.createAlgorithm()
  alg.setKisaoID("KISAO:0000019")

  # create analysis 
  a = doc.createAnalysis()
  a.setId('a1')
  alg = a.createAlgorithm()
  alg.setKisaoID("KISAO:0000019")


  # create a task that uses the simulation and the model above
  task = doc.createTask()
  task.setId("task1")
  task.setModelReference("model1")
  task.setSimulationReference("sim1")

  # add a DataGenerator to hold the output for time
  dg = doc.createDataGenerator()
  dg.setId("time")
  dg.setName("time")
  var = dg.createVariable()
  var.setId("v0")
  var.setName("time")
  var.setTaskReference("task1")
  var.setSymbol("urn:sedml:symbol:time")
  dg.setMath(libsedml.parseFormula("v0"))

  # and one for S1
  dg = doc.createDataGenerator()
  dg.setId("S1")
  dg.setName("S1")
  var = dg.createVariable()
  var.setId("v1")
  var.setName("S1")
  var.setTaskReference("task1")
  var.setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']")
  dg.setMath(libsedml.parseFormula("v1"))

  # add a report
  report = doc.createReport()
  report.setId("r1")
  report.setName("report 1")
  set = report.createDataSet()
  set.setId("ds1")
  set.setLabel("time")
  set.setDataReference("time")
  set = report.createDataSet()
  set.setId("ds2")
  set.setLabel("S1")
  set.setDataReference("S1")

  # add a 2d plot
  plot = doc.createPlot2D()
  plot.setId("p1")
  plot.setName("S1 Timecourse")
  curve = plot.createCurve()
  curve.setId("c1")
  curve.setName("S1")
  curve.setLogX(False)
  curve.setLogY(False)
  curve.setXDataReference("time")
  curve.setYDataReference("S1")

  # add a 3D Plot
  plot2 = doc.createPlot3D()
  plot2.setId("p2")
  plot2.setName("dunno")
  surf = plot2.createSurface()
  surf.setId("surf1")
  surf.setName("S1")
  surf.setLogX(False)
  surf.setLogY(False)
  surf.setLogZ(False)
  surf.setXDataReference("time")
  surf.setYDataReference("S1")
  surf.setZDataReference("S1")

  # write the document
  libsedml.writeSedML(doc, args[1])


if __name__ == '__main__':
  main(sys.argv)
