#!/usr/bin/env python
#
# @file   createNewElementDictObj.py
# @brief  Create element object to pass to functions
# @author Sarah Keating
#

import sys

def createSedDocument() :
  a1 = dict({'type': 'int', 'reqd' : True, 'name':'level'})
  a2 = dict({'type': 'int', 'reqd' : True, 'name':'version'})
  lo1 = dict({'type': 'lo_element', 'reqd' : False, 'name':'model', 'element': 'Model'})
  lo2 = dict({'type': 'lo_element', 'reqd' : False, 'name':'simulation', 'element': 'Simulation'})
  lo3 = dict({'type': 'lo_element', 'reqd' : False, 'name':'task', 'element': 'Task'})
  lo4 = dict({'type': 'lo_element', 'reqd' : False, 'name':'dataGenerator', 'element': 'DataGenerator'})
  lo5 = dict({'type': 'lo_element', 'reqd' : False, 'name':'output', 'element': 'Output'})
  attributes = [a1, a2, lo1, lo2, lo3, lo4, lo5]
  element = dict({'name': 'SedMLDocument', 'package': 'SedML', 'typecode': 'SEDML_DOCUMENT', 'hasSedListOf': False, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
  return element

def createSedModel() :
  a1 = dict({'type': 'SId', 'reqd' : True, 'name':'id'})
  a2 = dict({'type': 'string', 'reqd' : False, 'name':'name'})
  a3 = dict({'type': 'string', 'reqd' : False, 'name':'language'})
  a4 = dict({'type': 'string', 'reqd' : True, 'name':'source'})
  attributes = [a1, a2, a3, a4]
  element = dict({'name': 'Model', 'package': 'SedML', 'typecode': 'SEDML_MODEL', 'hasSedListOf': True, 'attribs':attributes, 'hasChildren':True, 'hasMath':False}) 
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
  
  
