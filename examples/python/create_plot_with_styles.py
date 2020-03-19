#!/usr/bin/env python
import sys
import libsedml


def create_plot_with_styles(file_name):
    doc = libsedml.SedDocument(1,4)

    create_styles(doc)

    create_plot_1(doc)

    create_plot_2(doc)

    libsedml.writeSedML(doc, file_name)
    pass


def create_styles(doc):
    # create styles
    style = doc.createStyle()
    style.setId('line_black')
    line = style.createLineStyle()
    line.setStyle('solid')
    line.setColor('#000000FF')
    style = doc.createStyle()
    style.setId('area_blue')
    fill = style.createFillStyle()
    fill.setColor('#0000FF7F')
    style = doc.createStyle()
    style.setId('area_red')
    fill = style.createFillStyle()
    fill.setColor('#0000FF7F')


def create_plot_1(doc):
    # create plots
    plot = doc.createPlot2D()
    plot.setId('plot_errorbar')
    plot.setLegend(True)
    # shaded area
    sa = plot.createShadedArea()
    sa.setId('cy_err_area')
    sa.setName('error_area')
    sa.setOrder(1)
    sa.setXDataReference('x')
    sa.setYDataReferenceFrom('yerr_down')
    sa.setYDataReferenceTo('yerr_up')
    sa.setStyle('area_blue')
    # curve
    curve = plot.createCurve()
    curve.setId('cy_err')
    curve.setName('errorbar')
    curve.setOrder(2)
    curve.setXDataReference('x')
    curve.setYDataReference('y')
    curve.setXErrorUpper('xerr')
    curve.setYErrorUpper('yerr')
    curve.setStyle('line_black')



def create_plot_2(doc):
    # create plots
    plot = doc.createPlot2D()
    plot.setId('plot_area')
    plot.setLegend(True)
    # shaded area
    sa = plot.createShadedArea()
    sa.setId('cy_sin_area')
    sa.setName('area')
    sa.setOrder(1)
    sa.setXDataReference('x')
    sa.setYDataReferenceFrom('y_zero')
    sa.setYDataReferenceTo('y_sin')
    sa.setStyle('area_red')


if __name__ == "__main__":
    print('using libSEDML: %s' % libsedml.getLibSEDMLDottedVersion())
    file_name = 'plot_with_styles.xml'
    num_args = len(sys.argv)
    if num_args > 1:
        file_name = sys.argv[1]
    create_plot_with_styles(file_name)