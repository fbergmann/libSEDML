#!/bin/env python
import libsedml


def create_nested_algorithm_example(file_name):
    doc = libsedml.SedDocument(1, 4)

    # create simulation
    tc = doc.createUniformTimeCourse()
    tc.setId("sim1")
    tc.setInitialTime(0.0)
    tc.setOutputStartTime(0.0)
    tc.setOutputEndTime(10.0)
    tc.setNumberOfPoints(1000)
    
    # need to set the correct KISAO Term
    alg = tc.createAlgorithm()
    alg.setKisaoID("KISAO:0000352")
    alg.setNotes("<p xmlns='http://www.w3.org/1999/xhtml'>a hybrid algorithm</p>")

    p = alg.createAlgorithmParameter()
    p.setKisaoID("KISAO:0000203")
    p.setNotes("<p xmlns='http://www.w3.org/1999/xhtml'>particle number lower limit</p>")
    p.setValue('2000')

    p1 = p.createAlgorithmParameter()
    p1.setKisaoID("KISAO:0000029")
    p1.setNotes("<p xmlns='http://www.w3.org/1999/xhtml'>Gillespie Parameter here</p>")
    p1.setValue('something')

    p1 = p.createAlgorithmParameter()
    p1.setKisaoID("KISAO:0000089")
    p1.setNotes("<p xmlns='http://www.w3.org/1999/xhtml'>LSODA parameter here</p>")
    p1.setValue('something else')


    # write doc
    libsedml.writeSedML(doc, file_name)


if __name__ == "__main__":
    create_nested_algorithm_example('nested_example.xml')
