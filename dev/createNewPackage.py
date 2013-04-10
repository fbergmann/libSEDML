#!/usr/bin/env python
#
# @file   createNewPackage.py
# @brief  Create package object to pass to functions
# @author Sarah Keating
#

import sys

def createSed():
  m0 = dict({'name': 'SedDocument', 'typecode': 'SEDML_DOCUMENT'})
  m1 = dict({'name': 'Model', 'typecode': 'SEDML_MODEL', 'isSedListOf': True})
  c1 = dict({'name': 'Change', 'typecode': 'SEDML_CHANGE', 'isSedListOf': True})
  c2 = dict({'name': 'NewXML', 'typecode': 'SEDML_CHANGE_NEW_XML'})
  c3 = dict({'name': 'AddXML', 'typecode': 'SEDML_CHANGE_ADD_XML'})
  c4 = dict({'name': 'ChangeAttribute', 'typecode': 'SEDML_CHANGE_ATTRIBUTE'})
  c5 = dict({'name': 'ComputeChange', 'typecode': 'SEDML_CHANGE_COMPUTECHANGES'})
  v1 = dict({'name': 'Variable', 'typecode': 'SEDML_VARIABLE'})
  p1 = dict({'name': 'Parameter', 'typecode': 'SEDML_PARAMETER'})  
  s1 = dict({'name': 'Simulation', 'typecode': 'SEDML_SIMULATION', 'isSedListOf' : True})
  s2 = dict({'name': 'UniformTimeCourse', 'typecode': 'SEDML_SIMULATION_UNIFORM_TIMECOURSE'})
  s3 = dict({'name': 'Algorithm', 'typecode': 'SEDML_SIMULATION_ALGORITHM'})
  t1 = dict({'name': 'Task', 'typecode': 'SEDML_TASK', 'isSedListOf' : True})
  d1 = dict({'name': 'DataGenerator', 'typecode': 'SEDML_DATAGENERATOR', 'isSedListOf' : True})
  o1 = dict({'name': 'Output', 'typecode': 'SEDML_OUTPUT', 'isSedListOf' : True})
  o2 = dict({'name': 'Plot2D', 'typecode': 'SEDML_OUTPUT_PLOT2D'})
  o3 = dict({'name': 'Plot3D', 'typecode': 'SEDML_OUTPUT_PLOT3D'})
  o4 = dict({'name': 'Curve', 'typecode': 'SEDML_OUTPUT_CURVE'})
  o5 = dict({'name': 'Surface', 'typecode': 'SEDML_OUTPUT_SURFACE'})
  o6 = dict({'name': 'DataSet', 'typecode': 'SEDML_OUTPUT_DATASET'})
  o7 = dict({'name': 'Report', 'typecode': 'SEDML_OUTPUT_REPORT'})
  elem = [m0, m1, c1, c2, c3, c4, c5, v1, p1, s1, s2, s3, t1, d1, o1, o2, o3, o4, o5, o6, o7]
  doc_elem = [m1, c1, s1, t1, d1, o1]
  doc_plug = dict({'sbase': 'SedDocument', 'extension': doc_elem}) 
  plug = [doc_plug]
  package = dict({'name' : 'Sed', 'elements': elem, 'plugins': plug, 'number': 1000})
  return package  
