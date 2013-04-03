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
  element = createSedDocument()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createSedModel()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createSedChange()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createSedSimulation()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createSedTask()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createSedDataGenerator()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createSedOutput()
  writeCode.createCode(element)
  writeHeader.createHeader(element)

def createSedDocument() :
  a1 = dict({'type': 'int', 'reqd' : True, 'name':'level'})
  a2 = dict({'type': 'int', 'reqd' : True, 'name':'version'})
  lo1 = dict({'type': 'lo_element', 'reqd' : False, 'name':'model', 'element': 'SedMLModel'})
  lo2 = dict({'type': 'lo_element', 'reqd' : False, 'name':'simulation', 'element': 'Simulation'})
  lo3 = dict({'type': 'lo_element', 'reqd' : False, 'name':'task', 'element': 'Task'})
  lo4 = dict({'type': 'lo_element', 'reqd' : False, 'name':'dataGenerator', 'element': 'DataGenerator'})
  lo5 = dict({'type': 'lo_element', 'reqd' : False, 'name':'output', 'element': 'Output'})
  attributes = [a1, a2, lo1, lo2, lo3, lo4, lo5]
  element = dict({'name': 'SedMLDocument', 'package': 'SedML', 'typecode': 'SEDML_DOCUMENT', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False, 'elementName':'sedML'}) 
  return element

def createSedModel() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'string', 'reqd' : False, 'name':'language'})
  a4 = dict({'type': 'string', 'reqd' : True, 'name':'source'})
  lo1 = dict({'type': 'lo_element', 'reqd' : False, 'name':'change', 'element': 'Change'})
  attributes = [a1, a2, a3, a4, lo1]
  element = dict({'name': 'SedMLModel', 'package': 'SedML', 'typecode': 'SEDML_MODEL', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False, 'elementName':'model'}) 
  return element

def createSedChange() :
  a1 = dict({'type': 'string', 'reqd' : True, 'name':'target'})
  attributes = [a1]
  element = dict({'name': 'Change', 'package': 'SedML', 'typecode': 'SEDML_CHANGE', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':False, 'hasMath':False}) 
  return element

def createSedSimulation() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  attributes = [a1, a2]
  element = dict({'name': 'Simulation', 'package': 'SedML', 'typecode': 'SEDML_SIMULATION', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createSedTask() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  attributes = [a1, a2]
  element = dict({'name': 'Task', 'package': 'SedML', 'typecode': 'SEDML_TASK', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createSedDataGenerator() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'element', 'reqd' : False, 'name':'math'})
  attributes = [a1, a2, a3]
  element = dict({'name': 'DataGenerator', 'package': 'SedML', 'typecode': 'SEDML_DATAGENERATOR', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':True}) 
  return element

def createSedOutput() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  attributes = [a1, a2]
  element = dict({'name': 'Output', 'package': 'SedML', 'typecode': 'SEDML_OUTPUT', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element
  
  
