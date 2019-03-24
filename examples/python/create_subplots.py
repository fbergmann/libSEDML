#!/usr/bin/env python
import sys
import libsedml


def create_subplots(file_name):
    doc = libsedml.SedDocument(1,4)

    fig = doc.createFigure()
    fig.setNumRows(3)
    fig.setNumCols(3)
    #fig.setWidth(8)
    #fig.setHeight(6)

    fig.setNotes('<p xmlns="xhtml">Figure 1 - Example for figure with text legend and sub-plots.</p>')

    sp = fig.createSubPlot()
    sp.setId('ax1')
    sp.setPlot('plot_y1')
    sp.setRow(1)
    sp.setCol(1)
    sp.setColSpan(1)

    libsedml.writeSedML(doc, file_name)
    pass


if __name__ == "__main__":
    print('using libSEDML: %s' % libsedml.getLibSEDMLDottedVersion())
    file_name = 'subplots.xml'
    num_args = len(sys.argv)
    if num_args > 1:
        file_name = sys.argv[1]
    create_subplots(file_name)