#!/bin/env python
import libsedml


def create_nested_task(file_name):
    doc = libsedml.SedDocument(1, 4)

    # create simulation
    sim = doc.createSteadyState()
    sim.setId("steady1")
    
    # need to set the correct KISAO Term
    alg = sim.createAlgorithm()
    alg.setKisaoID("KISAO:0000282")

    # create model
    model = doc.createModel()
    model.setId("model1")
    model.setLanguage("urn:sedml:language:sbml")
    model.setSource("oscli.xml")

    # create tasks
    task = doc.createTask()
    task.setId("task0")
    task.setModelReference("model1")
    task.setSimulationReference("steady1")

    task = doc.createRepeatedTask()
    assert(isinstance(task, libsedml.SedRepeatedTask))
    task.setId("task1")
    task.setResetModel(True)
    task.setRangeId("current")

    range = task.createUniformRange()
    assert(isinstance(range, libsedml.SedUniformRange))
    range.setId("current")
    range.setStart(0)
    range.setEnd(0)
    range.setNumberOfSteps(100)
    range.setType("linear")

    change = task.createTaskChange()
    assert(isinstance(change, libsedml.SedSetValue))
    change.setModelReference("model1")
    change.setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id=&quot;J0_v0&quot;]")
    change.setRange("current")
    change.setMath(libsedml.parseL3Formula("current"))

    subtask = task.createSubTask()
    subtask.setOrder(1)
    subtask.setTask("task0")

    # write doc
    libsedml.writeSedML(doc, file_name)


if __name__ == "__main__":
    create_nested_task('nested_task.xml')
