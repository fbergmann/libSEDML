#!/usr/bin/env python
#
# @file   createNewElementDictObj.py
# @brief  Create element object to pass to functions
# @author Sarah Keating
#

import sys

import writeCode
import writeHeader

def createElements():
  elements = [ createSedDocument(), 
              createSedModel(),
			  createSedChange(),
			  createSedParameter(),
			  createSedVariable(),
			  createSedChangeAttribute(),
			  createSedChangeRemoveXML(),
			  createSedComputeChange(),
			  createSedSimulation(),
			  createSedUniformTimeCourse(),
			  createSedAlgorithm(),
			  createSedTask(),
			  createSedDataGenerator(),
			  createSedOutput(),
			  createSedCurve(),
			  createSedSurface(),
			  createSedDataSet(),
			  createSedReport(),
			  createSedPlot2D(),
			  createSedPlot3D() ]
  for element in elements:
    writeCode.createCode(element)
    writeHeader.createHeader(element)


def createSedDocument() :
  a1 = dict({'type': 'int', 'reqd' : True, 'name':'level'})
  a2 = dict({'type': 'int', 'reqd' : True, 'name':'version'})
  lo1 = dict({
              'type': 'lo_element', 
			  'reqd' : False, 
			  'name':'simulation', 
			  'element': 'Simulation',
			  'abstract':True,
			  'concrete': [ 
				           dict({ 'name':'uniformTimeCourse', 'element':'UniformTimeCourse'}),
						   ]
			  })
  lo2 = dict({'type': 'lo_element', 'reqd' : False, 'name':'model', 'element': 'SedMLModel'})
  lo3 = dict({'type': 'lo_element', 'reqd' : False, 'name':'task', 'element': 'Task'})
  lo4 = dict({'type': 'lo_element', 'reqd' : False, 'name':'dataGenerator', 'element': 'DataGenerator'})
  lo5 = dict({
              'type': 'lo_element', 
			  'reqd' : False, 
			  'name':'output', 
			  'element': 'SedMLOutput',
			  'abstract':True,
			  'concrete': [ 
				           dict({ 'name':'report', 'element':'Report'}),
				           dict({ 'name':'plot2d', 'element':'Plot2D'}),
				           dict({ 'name':'plot3D', 'element':'Plot3D'}),
						   ]
			  })
  attributes = [a1, a2, lo1, lo2, lo3, lo4, lo5]
  element = dict({
           'name': 'SedMLDocument', 
		   'package': 'SedML', 
		   'typecode': 'SEDML_DOCUMENT', 
		   'hasSedListOf': False, 
		   'attribs':attributes, 
		   'hasChildren':True, 
		   'hasMath':False, 
		   'elementName':'sedML',
		   'additionalCPPDecls':'../dev/doc_headers.h',
		   'additionalCPPImpls':'../dev/doc_code.cpp'
		   })
  return element

def createSedModel() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'string', 'reqd' : False, 'name':'language'})
  a4 = dict({'type': 'string', 'reqd' : True, 'name':'source'})
  lo1 = dict({
              'type': 'lo_element', 
			  'reqd' : False, 
			  'name':'change', 
			  'element': 'Change',
			  'abstract':True,
			  'concrete': [ 
				           dict({ 'name':'removeXML', 'element':'RemoveXML'}),
				           dict({ 'name':'changeAttribute', 'element':'ChangeAttribute'}),
				           dict({ 'name':'computeChange', 'element':'ComputeChange'}),
						   ]
			  })
  attributes = [a1, a2, a3, a4, lo1]
  element = dict({'name': 'SedMLModel', 'package': 'SedML', 'typecode': 'SEDML_MODEL', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False, 'elementName':'model'})
  return element

def createSedVariable() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'string', 'reqd' : False, 'name':'symbol'})
  a4 = dict({'type': 'string', 'reqd' : False, 'name':'target'})
  a5 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'taskReference'})
  a6 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'modelReference'})
  attributes = [a1, a2, a3, a4, a5, a6]
  element = dict({'name': 'SedMLVariable', 'package': 'SedML', 'typecode': 'SEDML_VARIABLE', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False, 'elementName':'variable'})
  return element

def createSedParameter() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'double', 'reqd' : True, 'name':'value'})
  attributes = [a1, a2, a3]
  element = dict({'name': 'SedMLParameter', 'package': 'SedML', 'typecode': 'SEDML_PARAMETER', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False, 'elementName':'parameter'})
  return element

def createSedAlgorithm() :
  a1 = dict({'type': 'string', 'reqd' : True, 'name':'kisaoID'})
  attributes = [a1]
  element = dict({'name': 'Algorithm', 'package': 'SedML', 'typecode': 'SEDML_SIMULATION_ALGORITHM', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False})
  return element

def createSedChange() :
  a1 = dict({'type': 'string', 'reqd' : True, 'name':'target'})
  attributes = [a1]
  element = dict({
                  'name': 'Change', 
				  'package': 'SedML', 
				  'typecode': 'SEDML_CHANGE', 
				  'hasSedListOf': True, 
				  'attribs':attributes, 
				  'hasChildren':False, 
				  'hasMath':False, 
				  'elementName':'change', 
				  'abstract':True,
				  'concrete': [ 
				           dict({ 'name':'removeXML', 'element':'RemoveXML'}),
				           dict({ 'name':'changeAttribute', 'element':'ChangeAttribute'}),
				           dict({ 'name':'computeChange', 'element':'ComputeChange'}),
						   ]
				  })
  return element

def createSedChangeRemoveXML() :
  attributes = []
  element = dict({'name': 'RemoveXML', 'package': 'SedML', 'typecode': 'SEDML_CHANGE_REMOVEXML', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False, 'baseClass':'Change'})
  return element

def createSedComputeChange() :
  lo1 = dict({'type': 'lo_element', 'reqd' : False, 'name':'variable', 'element': 'SedMLVariable'})
  lo2 = dict({'type': 'lo_element', 'reqd' : False, 'name':'parameter', 'element': 'SedMLParameter'})
  a1 = dict({'type': 'element', 'reqd' : False, 'name':'math'})
  attributes = [lo1, lo2, a1]
  element = dict({'name': 'ComputeChange', 'package': 'SedML', 'typecode': 'SEDML_CHANGE_COMPUTECHANGE', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':True, 'baseClass':'Change'})
  return element

def createSedChangeAttribute() :
  a1 = dict({'type': 'string', 'reqd' : True, 'name':'newValue'})
  attributes = [a1]
  element = dict({'name': 'ChangeAttribute', 'package': 'SedML', 'typecode': 'SEDML_CHANGE_ATTRIBUTE', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False, 'baseClass':'Change'})
  return element

def createSedUniformTimeCourse() :
  a1 = dict({'type': 'double', 'reqd' : True, 'name':'initialTime'})
  a2 = dict({'type': 'double', 'reqd' : True, 'name':'outputStartTime'})
  a3 = dict({'type': 'double', 'reqd' : True, 'name':'outputEndTime'})
  a4 = dict({'type': 'int', 'reqd' : True, 'name':'numberOfPoints'})
  attributes = [a1, a2, a3, a4]
  element = dict({'name': 'UniformTimeCourse', 'package': 'SedML', 'typecode': 'SEDML_SIMULATION_UNIFORMTIMECOURSE', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':False, 'hasMath':False, 'baseClass':'Simulation'})
  return element

def createSedSimulation() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'element', 'reqd' : False, 'name':'algorithm'})
  attributes = [a1, a2, a3]
  element = dict({
                  'name': 'Simulation', 
				  'package': 'SedML', 
				  'typecode': 'SEDML_SIMULATION', 
				  'hasSedListOf': True, 
				  'attribs':attributes, 
				  'hasChildren':True, 
				  'hasMath':False, 
				  'elementName':'simulation',
				  'abstract':True,
				  'concrete': [ 
				           dict({ 'name':'uniformTimeCourse', 'element':'UniformTimeCourse'}),
						   ]
				})
  return element

def createSedTask() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'modelReference'})
  a4 = dict({'type': 'SIdRef', 'reqd' : False, 'name':'simulationReference'})
  attributes = [a1, a2, a3, a4]
  element = dict({'name': 'Task', 'package': 'SedML', 'typecode': 'SEDML_TASK', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False, 'elementName':'task'})
  return element

def createSedDataGenerator() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  lo1 = dict({'type': 'lo_element', 'reqd' : False, 'name':'variable', 'element': 'SedMLVariable'})
  lo2 = dict({'type': 'lo_element', 'reqd' : False, 'name':'parameter', 'element': 'SedMLParameter'})
  a3 = dict({'type': 'element', 'reqd' : False, 'name':'math'})
  attributes = [a1, a2, lo1, lo2, a3]
  element = dict({'name': 'DataGenerator', 'package': 'SedML', 'typecode': 'SEDML_DATAGENERATOR', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':True, 'elementName':'dataGenerator'})
  return element

def createSedOutput() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  attributes = [a1, a2]
  element = dict({
                  'name': 'SedMLOutput', 
				  'package': 'SedML', 
				  'typecode': 'SEDML_OUTPUT', 
				  'hasSedListOf': True, 
				  'attribs':attributes, 
				  'hasChildren':True, 
				  'hasMath':False, 
				  'elementName':'output',
				  'abstract':True,
				  'concrete': [ 
				           dict({ 'name':'report', 'element':'Report'}),
				           dict({ 'name':'plot2d', 'element':'Plot2D'}),
				           dict({ 'name':'plot3D', 'element':'Plot3D'}),
						   ]
				  })
  return element

def createSedReport() :
  lo1 = dict({'type': 'lo_element', 'reqd' : False, 'name':'dataSet', 'element': 'DataSet'})
  attributes = [lo1]
  element = dict({'name': 'Report', 'package': 'SedML', 'typecode': 'SEDML_OUTPUT_REPORT', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False, 'baseClass':'SedMLOutput', 'elementName':'report'})
  return element

def createSedPlot2D() :
  lo1 = dict({'type': 'lo_element', 'reqd' : False, 'name':'curve', 'element': 'SedMLCurve'})
  attributes = [lo1]
  element = dict({'name': 'Plot2D', 'package': 'SedML', 'typecode': 'SEDML_OUTPUT_PLOT2D', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False, 'baseClass':'SedMLOutput', 'elementName':'plot2D'})
  return element

def createSedPlot3D() :
  lo1 = dict({'type': 'lo_element', 'reqd' : False, 'name':'surface', 'element': 'Surface'})
  attributes = [lo1]
  element = dict({'name': 'Plot3D', 'package': 'SedML', 'typecode': 'SEDML_OUTPUT_PLOT3D', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False, 'baseClass':'SedMLOutput' , 'elementName':'plot3D'})
  return element

def createSedDataSet() :
  a0 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a1 = dict({'type': 'string', 'reqd' : True, 'name':'label'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'dataReference'})
  attributes = [a0, a1, a2, a3]
  element = dict({'name': 'DataSet', 'package': 'SedML', 'typecode': 'SEDML_OUTPUT_DATASET', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False, 'elementName':'dataSet'})
  return element

def createSedCurve() :
  a0 = dict({'type': 'SId', 'reqd' : False, 'name':'id'})
  a1 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a2 = dict({'type': 'bool', 'reqd' : True, 'name':'logX'})
  a3 = dict({'type': 'bool', 'reqd' : True, 'name':'logY'})
  a4 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'xDataReference'})
  a5 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'yDataReference'})
  attributes = [a0, a1, a2, a3, a4, a5]
  element = dict({'name': 'SedMLCurve', 'package': 'SedML', 'typecode': 'SEDML_OUTPUT_CURVE', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False, 'elementName':'curve'})
  return element

def createSedSurface() :
  a1 = dict({'type': 'bool', 'reqd' : True, 'name':'logZ'})
  a2 = dict({'type': 'SIdRef', 'reqd' : True, 'name':'zDataReference'})
  attributes = [a1, a2]
  element = dict({'name': 'Surface', 'package': 'SedML', 'typecode': 'SEDML_OUTPUT_SURFACE', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False,'baseClass':'SedMLCurve', 'elementName':'surface' })
  return element
