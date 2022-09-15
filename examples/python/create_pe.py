#!/usr/bin/env python
import sys
import libsedml


def create_data_description(doc):
    # type: (libsedml.SedDocument) -> None
    # reference our data file
    ddesc = doc.createDataDescription()
    ddesc.setId('data1')
    ddesc.setName('Oscli Timecourse data')
    ddesc.setSource('foo.csv')

    # this is timecourse data, time down, observed species concentrations next
    # specify mapping
    timeDesc = libsedml.CompositeDescription()
    timeDesc.setIndexType('double')
    timeDesc.setId('time')
    timeDesc.setName('time')

    speciesDesc = timeDesc.createCompositeDescription()
    speciesDesc.setIndexType('string')
    speciesDesc.setId('ColumnNames')
    speciesDesc.setName('ColumnNames')

    concentrationDesc = speciesDesc.createAtomicDescription()
    concentrationDesc.setValueType("double")
    concentrationDesc.setName("Concentrations")

    dimDesc = ddesc.createDimensionDescription()
    dimDesc.append(timeDesc)

    # here we going to extract the 'S1' data
    # create data source
    dsource = ddesc.createDataSource()
    dsource.setId('dataS1')
    # create slice
    slice = dsource.createSlice()
    slice.setReference('ColumnNames')
    slice.setValue('S1')

    dtime = ddesc.createDataSource()
    dtime.setId('dataTime')
    dtime.setIndexSet('time')
    # slice = dtime.createSlice()
    # slice.setReference('ColumnNames')
    # slice.setValue('time')


def create_pe_task(doc):
    # type: (libsedml.SedDocument) -> None
    pe = doc.createParameterEstimationTask()
    pe.setId('pe1')

    # set algorithm
    alg = pe.createAlgorithm()
    alg.setKisaoID("KISAO:0000472")

    # set lsq objective
    pe.createLeastSquareObjectiveFunction()

    # create fit parameter, to vary 'J2_q'
    fp = pe.createAdjustableParameter()
    fp.setId('fitParameter1')
    fp.setModelReference('model1')
    fp.setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='J2_q']")
    fp.setInitialValue(2.4)
    bounds = fp.createBounds()
    bounds.setLowerBound(0.0001)
    bounds.setUpperBound(10)

    # create fit parameter, to vary 'J2_q'
    fp = pe.createAdjustableParameter()
    fp.setId('fitParameter1')
    fp.setModelReference('model1')
    fp.setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id='J2_q']")
    fp.setInitialValue(2.4)
    bounds = fp.createBounds()
    bounds.setLowerBound(0.0001)
    bounds.setUpperBound(10)
    bounds.setScale('lin')

    # create fit experiment, mapping the data
    fe = pe.createFitExperiment()
    fe.setId('exp1')
    fe.setType('timeCourse')
    #fe.setSource('dataS1') # is this needed here? NO

    # map the first column
    dg = doc.createDataGenerator()
    dg.setId('s1_conc')
    var = dg.createVariable()
    var.setId("s1")
    var.setModelReference("model1")
    var.setTarget("/sbml:sbml/sbml:model/sbml:listOfSpecies/sbml:species[@id='S1']")
    dg.setMath(libsedml.parseFormula("s1"))

    map = fe.createFitMapping()
    map.setDataSource('dataS1')
    map.setTarget('s1_conc')
    map.setType('observable')
    map.setWeight(1)


def create_plot(doc):
    # type: (libsedml.SedDocument) -> None
    plot = doc.createParameterEstimationResultPlot()
    plot.setTaskRef('pe1')
    plot.setName('Result Plot')
    plot.setId('plot1')


def create_report(doc):
    # type: (libsedml.SedDocument) -> None
    report = doc.createReport()
    report.setId('report1')
    set = report.createDataSet()
    set.setId('set1')
    set.setLabel('OBJ')
    set.setDataReference('pe_obj') # this is 0D data

    set = report.createDataSet()
    set.setId('set2')
    set.setLabel('FEVAL')
    set.setDataReference('pe_feval') # this is 1D data


def create_output_datagenerators(doc):
    # type: (libsedml.SedDocument) -> None
    dg = doc.createDataGenerator()
    dg.setId('pe_obj')
    var = dg.createVariable()
    var.setId("obj")
    var.setTaskReference("pe1")
    var.setSymbol("sedml:parameterestimation:objective_value")
    dg.setMath(libsedml.parseFormula("obj"))

    dg = doc.createDataGenerator()
    dg.setId('pe_feval')
    var = dg.createVariable()
    var.setId("feval")
    var.setTaskReference("pe1")
    var.setSymbol("sedml:parameterestimation:number_function_evaluations")
    dg.setMath(libsedml.parseFormula("feval"))



def create_pe_example(file_name):
    # type: (str) -> None
    doc = libsedml.SedDocument(1, 4)

    # create a first model referencing an sbml file
    model = doc.createModel()
    model.setId("model1")
    model.setSource("file.xml")
    model.setLanguage("urn:sedml:language:sbml")

    create_data_description(doc)

    create_pe_task(doc)

    create_output_datagenerators(doc)

    create_plot(doc)

    create_report(doc)

    libsedml.writeSedML(doc, file_name)


if __name__ == "__main__":
    print('using libSEDML: %s' % libsedml.getLibSEDMLDottedVersion())
    out_file = 'pe-example.xml'
    create_pe_example(out_file)
