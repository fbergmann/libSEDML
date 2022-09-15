#!/bin/env python
import libsedml


def create_dependent_variable_example(file_name):
    # create the document
    doc = libsedml.SedDocument(1, 4)

    # create a first model referencing an sbml file
    model = doc.createModel()
    model.setId("model1")
    model.setSource("oscli.xml")
    model.setLanguage("urn:sedml:language:sbml")

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
    var.setId("t")
    var.setName("time")
    var.setTaskReference("task1")
    var.setSymbol("urn:sedml:symbol:time")
    dg.setMath(libsedml.parseFormula("t"))

    # and one for S1
    dg = doc.createDataGenerator()
    dg.setId("S1")
    dg.setName("[S1]")
    var = dg.createVariable()
    var.setId("v1")
    var.setName("[S1]")
    var.setTaskReference("task1")
    var.setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']")
    dg.setMath(libsedml.parseFormula("v1"))

    # and one for the rate of S1
    dg = doc.createDataGenerator()
    dg.setId("dS1dt")
    dg.setName("d[S1]/dt")
    var = dg.createDependentVariable()
    var.setId("v2")
    var.setTerm('urn:sedml:symbol:rateOfChange')
    var.setName("d[S1]/dt")
    var.setTaskReference("task1")
    var.setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']")
    dg.setMath(libsedml.parseFormula("v2"))

    # add a 2d plot
    plot = doc.createPlot2D()
    plot.setId("p1")
    plot.setName("S1 Timecourse")
    curve = plot.createCurve()
    curve.setId("c1")
    curve.setName("[S1]")
    curve.setXDataReference("time")
    curve.setYDataReference("S1")

    curve = plot.createCurve()
    curve.setId("c1")
    curve.setName("d[S1]/dt")
    curve.setXDataReference("time")
    curve.setYDataReference("dS1dt")

    # write doc
    libsedml.writeSedML(doc, file_name)


if __name__ == "__main__":
    create_dependent_variable_example('dependent_example.xml')
