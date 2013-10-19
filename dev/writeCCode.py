#!/usr/bin/env python
#
# @file   writeCCode.py
# @brief  Create the C code for a class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions


def writeConstructors(element, package, output):
  indent = strFunctions.getIndent(element)
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_create'.format(element))
  output.write('(unsigned int level, unsigned int version)\n')
  output.write('{\n')
  output.write('\treturn new {0}(level, version);\n'.format(element))
  output.write('}\n\n\n')
#  output.write('/**\n')
#  output.write(' * write comments\n')
#  output.write(' */\n')
#  output.write('LIBSEDML_EXTERN\n')
#  output.write('{0}_t *\n'.format(element))
#  output.write('{0}_createWithNS'.format(element))
#  output.write('(SedNamespaces_t *sedmlns)\n')
#  output.write('{\n')
#  output.write('\treturn new {0}(sedmlns);\n'.format(element))
#  output.write('}\n\n\n')
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('void\n')
  output.write('{0}_free'.format(element))
  output.write('({0}_t * {1})\n'.format(element, strFunctions.objAbbrev(element)))
  output.write('{\n')
  output.write('\tif ({0} != NULL)\n'.format(strFunctions.objAbbrev(element)))
  output.write('\t\tdelete {0};\n'.format(strFunctions.objAbbrev(element)))
  output.write('}\n\n\n')
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_clone'.format(element))
  output.write('({0}_t * {1})\n'.format(element, strFunctions.objAbbrev(element)))
  output.write('{\n')
  output.write('\tif ({0} != NULL)\n'.format(strFunctions.objAbbrev(element)))
  output.write('\t{\n')
  output.write('\t\treturn static_cast<{0}_t*>({1}->clone());\n'.format(element, strFunctions.objAbbrev(element)))
  output.write('\t}\n')
  output.write('\telse\n')
  output.write('\t{\n')
  output.write('\t\treturn NULL;\n')
  output.write('\t}\n')
  output.write('}\n\n\n')

def writeAttributeFunctions(attrs, output, element):
  for i in range(0, len(attrs)):
	if attrs[i]['type'] != 'lo_element':
		writeGetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
	if attrs[i]['type'] != 'lo_element':
		writeIsSetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
	if attrs[i]['type'] != 'lo_element':
		writeSetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
	if attrs[i]['type'] != 'lo_element':
		writeUnsetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] == 'lo_element':
      writeListOfSubElements(attrs[i], output, element)

def writeListOfSubElements(attrib, output, element):
  loname = generalFunctions.writeListOf(strFunctions.cap(attrib['name']))
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_add{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('{0}_t * {1})\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  output.write('{\n')
  output.write('\treturn  ({0} != NULL) ? {0}->add{1}({2}) : LIBSBML_INVALID_OBJECT;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(attrib['name']),strFunctions.objAbbrev(attrib['element'])))
  output.write('}\n\n')
  if attrib.has_key('abstract') == False or (attrib.has_key('abstract') and attrib['abstract'] == False):
    output.write('LIBSEDML_EXTERN\n')
    output.write('{0}_t *\n'.format(attrib['element']))
    output.write('{0}_create{1}({0}_t * {2})\n' .format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
    output.write('{\n')
    output.write('\treturn  ({0} != NULL) ? {0}->create{1}() : NULL;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(attrib['name'])))
    output.write('}\n\n')
  elif attrib.has_key('concrete'):
    for elem in attrib['concrete']:
     output.write('LIBSEDML_EXTERN\n')
     output.write('{0}_t *\n'.format(elem['element']))
     output.write('{0}_create{1}({0}_t * {2})\n' .format(element, strFunctions.cap(elem['name']), strFunctions.objAbbrev(element)))
     output.write('{\n')
     output.write('\treturn  ({0} != NULL) ? {0}->create{1}() : NULL;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(elem['name'])))
     output.write('}\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('SedListOf_t *\n')
  output.write('{0}_get{1}({0}_t * {2})\n'.format(element, loname, strFunctions.objAbbrev(element)))
  output.write('{\n')
  output.write('\treturn  ({0} != NULL) ? (SedListOf_t *){0}->getListOf{1}s() : NULL;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(attrib['name'])))
  output.write('}\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_get{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('unsigned int n)\n')
  output.write('{\n')
  output.write('\treturn  ({0} != NULL) ? {0}->get{1}(n) : NULL;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(attrib['name'])))
  output.write('}\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_get{1}ById({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('const char * sid)\n')
  output.write('{\n')
  output.write('\treturn  ({0} != NULL) ? {0}->get{1}(sid) : NULL;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(attrib['name'])))
  output.write('}\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('unsigned int\n')
  output.write('{0}_getNum{1}s({0}_t * {2})\n' .format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('{\n')
  output.write('\treturn  ({0} != NULL) ? {0}->getNum{1}s() : SEDML_INT_MAX;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(attrib['name'])))
  output.write('}\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_remove{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('unsigned int n)\n')
  output.write('{\n')
  output.write('\treturn  ({0} != NULL) ? {0}->remove{1}(n) : NULL;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(attrib['name'])))
  output.write('}\n\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_remove{1}ById({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('const char * sid)\n')
  output.write('{\n')
  output.write('\treturn  ({0} != NULL) ? {0}->remove{1}(sid) : NULL;\n'.format(strFunctions.objAbbrev(element),strFunctions.cap(attrib['name'])))
  output.write('}\n\n')
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
  varname = strFunctions.objAbbrev(element)
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  if attrib['type'] == 'std::vector<double>':
    return
  elif attrib['type'] != 'element' and attrib['type'] != 'lo_element' and attrib['type'] != 'XMLNode*':
    output.write('LIBSEDML_EXTERN\n')
    output.write('{0}\n'.format(attTypeCode))
    output.write('{0}_get{1}'.format(element, capAttName))
    output.write('({0}_t * {1})\n'.format(element, varname))
    output.write('{\n')
    if attType == 'string':
      output.write('\tif ({0} == NULL)\n'.format(varname))
      output.write('\t\treturn NULL;\n\n')
      output.write('\treturn {0}->get{1}().empty() ? NULL : safe_strdup({0}->get{1}().c_str());\n'.format(varname, capAttName))
    elif num == True:
      if attTypeCode == 'double':
        output.write('\treturn ({0} != NULL) ? {0}->get{1}() : numeric_limits<double>::quiet_NaN();\n'.format(varname, capAttName))
      else:
        output.write('\treturn ({0} != NULL) ? {0}->get{1}() : SEDML_INT_MAX;\n'.format(varname, capAttName))
    elif attType == 'boolean':
      output.write('\treturn ({0} != NULL) ? static_cast<int>({0}->get{1}()) : 0;\n'.format(varname, capAttName))
    output.write('}\n\n\n')
  elif attrib['type'] == 'XMLNode*':
      output.write('LIBSEDML_EXTERN\n')
      output.write('XMLNode_t*\n')
      output.write('{0}_get{1}'.format(element, capAttName))
      output.write('({0}_t * {1})\n'.format(element, varname))
      output.write('{\n')
      output.write('\tif ({0} == NULL)\n'.format(varname))
      output.write('\t\treturn NULL;\n\n')
      output.write('\treturn ({0}_t*){1}->get{2}();\n'.format('XMLNode',varname, capAttName))
      output.write('}\n\n\n')
  elif attrib['type'] == 'element':
    if attrib['name'] == 'Math' or attrib['name'] == 'math':
      output.write('LIBSEDML_EXTERN\n')
      output.write('ASTNode_t*\n')
      output.write('{0}_get{1}'.format(element, capAttName))
      output.write('({0}_t * {1})\n'.format(element, varname))
      output.write('{\n')
      output.write('\tif ({0} == NULL)\n'.format(varname))
      output.write('\t\treturn NULL;\n\n')
      output.write('\treturn (ASTNode_t*){0}->get{1}();\n'.format(varname, capAttName))
      output.write('}\n\n\n')
    else:
      output.write('LIBSEDML_EXTERN\n')
      output.write('{0}_t*\n'.format(attrib['element']))
      output.write('{0}_get{1}'.format(element, capAttName))
      output.write('({0}_t * {1})\n'.format(element, varname))
      output.write('{\n')
      output.write('\tif ({0} == NULL)\n'.format(varname))
      output.write('\t\treturn NULL;\n\n')
      output.write('\treturn ({0}_t*){1}->get{2}();\n'.format(attrib['element'],varname, capAttName))
      output.write('}\n\n\n')
      output.write('LIBSEDML_EXTERN\n')
      output.write('{0}_t*\n'.format(attrib['element']))
      output.write('{0}_create{1}'.format(element, capAttName))
      output.write('({0}_t * {1})\n'.format(element, varname))
      output.write('{\n')
      output.write('\tif ({0} == NULL)\n'.format(varname))
      output.write('\t\treturn NULL;\n\n')
      output.write('\treturn ({0}_t*){1}->create{2}();\n'.format(attrib['element'],varname, capAttName))
      output.write('}\n\n\n')
  
 
def writeIsSetFunction(attrib, output, element):
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
  varname = strFunctions.objAbbrev(element)
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_isSet{1}'.format(element, capAttName))
  output.write('({0}_t * {1})\n'.format(element, varname))
  output.write('{\n')
  output.write('\treturn ({0} != NULL) ? static_cast<int>({0}->isSet{1}()) : 0;\n'.format(varname, capAttName))
  output.write('}\n\n\n')
    
 
def writeSetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'lo_element':
    return
  varname = strFunctions.objAbbrev(element)
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  if attrib['type'] == 'std::vector<double>':
    return
  elif attrib['type'] != 'element' and attrib['type'] != 'lo_element':
    output.write('LIBSEDML_EXTERN\n')
    output.write('int\n')
    output.write('{0}_set{1}'.format(element, capAttName))
    output.write('({0}_t * {1},'.format(element, varname))
    output.write(' {0} {1})\n'.format(attTypeCode, attName))
    output.write('{\n')
    output.write('\treturn ({0} != NULL) ? {0}->set{1}({2}) : LIBSEDML_INVALID_OBJECT;\n'.format(varname, capAttName, attName))
    output.write('}\n\n\n')
  elif attrib['type'] == 'element':
    if attrib['name'] == 'Math' or attrib['name'] == 'math':
      output.write('LIBSEDML_EXTERN\n')
      output.write('int\n')
      output.write('{0}_set{1}'.format(element, capAttName))
      output.write('({0}_t * {1},'.format(element, varname))
      output.write(' {0} {1})\n'.format('ASTNode_t*', attName))
      output.write('{\n')
      output.write('\treturn ({0} != NULL) ? {0}->set{1}({2}) : LIBSEDML_INVALID_OBJECT;\n'.format(varname, capAttName, attName))
      output.write('}\n\n\n')
    else:
      output.write('LIBSEDML_EXTERN\n')
      output.write('int\n')
      output.write('{0}_set{1}'.format(element, capAttName))
      output.write('({0}_t * {1},'.format(element, varname))
      output.write(' {0}_t* {1})\n'.format(attrib['element'], attName))
      output.write('{\n')
      output.write('\treturn ({0} != NULL) ? {0}->set{1}({2}) : LIBSEDML_INVALID_OBJECT;\n'.format(varname, capAttName, attName))
      output.write('}\n\n\n')
    
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
  varname = strFunctions.objAbbrev(element)
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_unset{1}'.format(element, capAttName))
  output.write('({0}_t * {1})\n'.format(element, varname))
  output.write('{\n')
  output.write('\treturn ({0} != NULL) ? {0}->unset{1}() : LIBSEDML_INVALID_OBJECT;\n'.format(varname, capAttName))
  output.write('}\n\n\n')
    
 
def writeHasReqdAttrFunction(output, element):
  varname = strFunctions.objAbbrev(element)
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_hasRequiredAttributes'.format(element))
  output.write('({0}_t * {1})\n'.format(element, varname))
  output.write('{\n')
  output.write('\treturn ({0} != NULL) ? static_cast<int>({0}->hasRequiredAttributes()) : 0;\n'.format(varname))
  output.write('}\n\n\n')

def writeHasReqdElementsFunction(output, element):
  varname = strFunctions.objAbbrev(element)
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_hasRequiredElements'.format(element))
  output.write('({0}_t * {1})\n'.format(element, varname))
  output.write('{\n')
  output.write('\treturn ({0} != NULL) ? static_cast<int>({0}->hasRequiredElements()) : 0;\n'.format(varname))
  output.write('}\n\n\n')
    
def writeListOfCode(output, element, type):
  loelement = generalFunctions.writeListOf(element)
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(type))
  output.write('{0}_getById'.format(loelement))
  output.write('(SedListOf_t * lo, const char * sid)\n')
  output.write('{\n')
  output.write('\tif (lo == NULL)\n')
  output.write('\t\treturn NULL;\n\n')
  output.write('\treturn (sid != NULL) ? static_cast <{0} *>(lo)->get(sid) : NULL;\n'.format(loelement))
  output.write('}\n\n\n')
  output.write('/**\n')
  output.write(' * write comments\n')
  output.write(' */\n')
  output.write('LIBSEDML_EXTERN\n')
  output.write('{0}_t *\n'.format(type))
  output.write('{0}_removeById'.format(loelement))
  output.write('(SedListOf_t * lo, const char * sid)\n')
  output.write('{\n')
  output.write('\tif (lo == NULL)\n')
  output.write('\t\treturn NULL;\n\n')
  output.write('\treturn (sid != NULL) ? static_cast <{0} *>(lo)->remove(sid) : NULL;\n'.format(loelement))
  output.write('}\n\n\n')
 
# write the code file      
def createCode(element, code):
  type = element['name']
  name = element['name']
  if element.has_key('elementName'):
    name = strFunctions.cap(element['elementName']) 
  if element.has_key('element'):
    type = element['element']
  writeConstructors(element['name'], element['package'], code)
  writeAttributeFunctions(element['attribs'], code, element['name'])
  writeHasReqdAttrFunction(code, element['name'])
  if element['hasChildren'] == True or element['hasMath'] == True:
    writeHasReqdElementsFunction(code, element['name'])
  if element['hasSedListOf'] == True:
    writeListOfCode(code, name, type)
  code.write('\n\n');
  code.write('LIBSEDML_CPP_NAMESPACE_END\n')
  code.write('\n\n');
 
# to de done

  