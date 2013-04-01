#!/usr/bin/env python
#
# @file   writeCHeader.py
# @brief  Create the C headers for a class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions


def writeConstructors(element, package, output):
  indent = strFunctions.getIndent(element)
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_create'.format(element))
  output.write('(unsigned int level, unsigned int version);\n\n\n')
#  output.write('LIBSEDML_EXTERN\n')
#  output.write('{0}_t *\n'.format(element))
#  output.write('{0}_createWithNS'.format(element))
#  output.write('(SedMLNamespaces_t *sedmlns);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('void\n')
  output.write('{0}_free'.format(element))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_clone'.format(element))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))

def writeAttributeFunctions(attrs, output, element):
  for i in range(0, len(attrs)):
    writeGetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeIsSetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeSetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeUnsetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] == 'lo_element':
      writeListOfSubElements(attrs[i], output, element)

def writeListOfSubElements(attrib, output, element):
  loname = generalFunctions.writeListOf(attrib['element'])
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_add{1}({0}_t * {2}, '.format(element, attrib['element'], strFunctions.objAbbrev(element)))
  output.write('{0}_t * {1});\n\n\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_create{1}({0}_t * {2}' .format(element, attrib['element'], strFunctions.objAbbrev(element)))
  output.write(');\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('SedListOf_t *\n')
  output.write('{0}_get{1}({0}_t * {2})'.format(element, loname, strFunctions.objAbbrev(element)))
  output.write(';\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_get{1}({0}_t * {2}, '.format(element, attrib['element'], strFunctions.objAbbrev(element)))
  output.write('unsigned int n);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_get{1}ById({0}_t * {2}, '.format(element, attrib['element'], strFunctions.objAbbrev(element)))
  output.write('const char * sid);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('unsigned int\n')
  output.write('{0}_getNum{1}s({0}_t * {2}' .format(element, attrib['element'], strFunctions.objAbbrev(element)))
  output.write(');\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_remove{1}({0}_t * {2}, '.format(element, attrib['element'], strFunctions.objAbbrev(element)))
  output.write('unsigned int n);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_remove{1}ById({0}_t * {2}, '.format(element, attrib['element'], strFunctions.objAbbrev(element)))
  output.write('const char * sid);\n\n\n')
 # writeListOfHeader.writeGetFunctions(output, attrib['element'], True, element)
 # writeListOfHeader.writeRemoveFunctions(output, attrib['element'], True, element)
 


def writeGetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  if att[3] == 'const char *':
    attTypeCode = 'char *'
  else:
    attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'element' or attrib['type'] == 'lo_element':
    return
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}\n'.format(attTypeCode))
  output.write('{0}_get{1}'.format(element, capAttName))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
 
def writeIsSetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'element' or attrib['type'] == 'lo_element':
    return
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_isSet{1}'.format(element, capAttName))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
    
 
def writeSetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'element' or attrib['type'] == 'lo_element':
    return
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_set{1}'.format(element, capAttName))
  output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
  output.write(' {0} {1});\n\n\n'.format(attTypeCode, attName))
    
def writeUnsetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'element' or attrib['type'] == 'lo_element':
    return
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_unset{1}'.format(element, capAttName))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
    
 
def writeHasReqdAttrFunction(output, element):
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_hasRequiredAttributes'.format(element))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))

def writeHasReqdElementsFunction(output, element):
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_hasRequiredElements'.format(element))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))

    
def writeListOfHeaders(output, element):
  loelement = generalFunctions.writeListOf(element)
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_getById'.format(loelement))
  output.write('(SedListOf_t * lo, const char * sid);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_removeById'.format(loelement))
  output.write('(SedListOf_t * lo, const char * sid);\n\n\n')
 
# write the header file      
def createHeader(element, header):
  writeConstructors(element['name'], element['package'], header)
  writeAttributeFunctions(element['attribs'], header, element['name'])
  writeHasReqdAttrFunction(header, element['name'])
  if element['hasChildren'] == True or element['hasMath'] == True:
    writeHasReqdElementsFunction(header, element['name'])
  if element['hasSedListOf'] == True:
    writeListOfHeaders(header, element['name'])
 

  