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
#  output.write('(SedNamespaces_t *sedmlns);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('void\n')
  output.write('{0}_free'.format(element))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_clone'.format(element))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))

def writeAttributeFunctions(attrs, output, element, dict):
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
  loname = generalFunctions.writeListOf(strFunctions.cap(attrib['name']))
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_add{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('{0}_t * {1});\n\n\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  if attrib.has_key('abstract') == False or (attrib.has_key('abstract') and attrib['abstract'] == False):
    output.write('LIBSEDML_EXTERN\n')
    output.write('{0}_t *\n'.format(attrib['element']))
    output.write('{0}_create{1}({0}_t * {2}' .format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
    output.write(');\n\n\n')
  elif attrib.has_key('concrete'):
    for elem in attrib['concrete']:
      output.write('LIBSEDML_EXTERN\n')
      output.write('{0}_t *\n'.format(elem['element']))
      output.write('{0}_create{1}({0}_t * {2}' .format(element, strFunctions.cap(elem['name']), strFunctions.objAbbrev(element)))
      output.write(');\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('SedListOf_t *\n')
  output.write('{0}_get{1}({0}_t * {2})'.format(element, loname, strFunctions.objAbbrev(element)))
  output.write(';\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_get{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('unsigned int n);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_get{1}ById({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('const char * sid);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('unsigned int\n')
  output.write('{0}_getNum{1}s({0}_t * {2}' .format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write(');\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_remove{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('unsigned int n);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_remove{1}ById({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
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
  if attrib['type'] == 'std::vector<double>':
    return
  elif attrib['type'] != 'element' and attrib['type'] != 'lo_element' and attrib['type'] != 'XMLNode*':
    output.write('LIBSEDML_EXTERN\n')
    output.write('{0}\n'.format(attTypeCode))
    output.write('{0}_get{1}'.format(element, capAttName))
    output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
  elif attrib['type'] == 'XMLNode*':
    output.write('LIBSEDML_EXTERN\n')
    output.write('XMLNode_t*\n')
    output.write('{0}_get{1}'.format(element, capAttName))
    output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))    
  elif attrib['type'] == 'element':
    if attrib['name'] == 'Math' or attrib['name'] == 'math':
      output.write('LIBSEDML_EXTERN\n')
      output.write('ASTNode_t*\n')
      output.write('{0}_getMath'.format(element))
      output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
    else:
      output.write('LIBSEDML_EXTERN\n')
      output.write('{0}_t*\n'.format(strFunctions.cap(attrib['element'])))
      output.write('{0}_get{1}'.format(element, capAttName))
      output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
      output.write('LIBSEDML_EXTERN\n')
      output.write('{0}_t*\n'.format(strFunctions.cap(attrib['element'])))
      output.write('{0}_create{1}'.format(element, capAttName))
      output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
 
def writeIsSetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'std::vector<double>':
    return
  elif attrib['type'] != 'lo_element':
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
  if attrib['type'] == 'std::vector<double>':
    return
  elif attrib['type'] != 'element' and attrib['type'] != 'lo_element' and attrib['type'] != 'XMLNode*':
    output.write('LIBSEDML_EXTERN\n')
    output.write('int\n')
    output.write('{0}_set{1}'.format(element, capAttName))
    output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
    output.write(' {0} {1});\n\n\n'.format(attTypeCode, attName))
  elif attrib['type'] == 'XMLNode*':
    output.write('LIBSEDML_EXTERN\n')
    output.write('int\n')
    output.write('{0}_set{1}'.format(element, capAttName))
    output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
    output.write(' XMLNode_t* {0});\n\n\n'.format(attName))
  elif attrib['type'] == 'element':
    if attrib['name'] == 'Math' or attrib['name'] == 'math':
      output.write('LIBSEDML_EXTERN\n')
      output.write('int\n')
      output.write('{0}_setMath'.format(element))
      output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
      output.write(' ASTNode_t* {0});\n\n\n'.format(attName))
    else:
      output.write('LIBSEDML_EXTERN\n')
      output.write('int\n')
      output.write('{0}_set{1}'.format(element, capAttName))
      output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
      output.write(' {0}_t* {1});\n\n\n'.format(attrib['element'], attName))
    
def writeUnsetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'lo_element':
    return
  if attrib['type'] == 'std::vector<double>':
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

    
def writeListOfHeaders(output, element, type):
  loelement = generalFunctions.writeListOf(element)
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(type))
  output.write('{0}_getById'.format(loelement))
  output.write('(SedListOf_t * lo, const char * sid);\n\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(type))
  output.write('{0}_removeById'.format(loelement))
  output.write('(SedListOf_t * lo, const char * sid);\n\n\n')
 
# write the header file      
def createHeader(element, header):
  type = element['name']
  name = element['name']
  if element.has_key('elementName'):
    name = strFunctions.cap(element['elementName']) 
  if element.has_key('element'):
    type = element['element']

  writeConstructors(element['name'], element['package'], header)
  writeAttributeFunctions(element['attribs'], header, element['name'], element)
  writeHasReqdAttrFunction(header, element['name'])
  if element['hasChildren'] == True or element['hasMath'] == True:
    writeHasReqdElementsFunction(header, element['name'])
  if element['hasSedListOf'] == True:
    writeListOfHeaders(header, name, type)
 

  