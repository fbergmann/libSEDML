#!/usr/bin/env python
#
# @file   generalFunctions.py
# @brief  write the functions that occur on all classes
# @author Sarah Keating
#

import sys
import strFunctions

def getByType(attribs, typeName):
  if attribs == None: 
    return None
  for i in range(0, len(attribs)): 
    if attribs[i]['type'] == typeName: 
      return attribs[i]
  return None
  
def containsType(attribs, typeName):
  if attribs == None: 
    return False
  for i in range(0, len(attribs)): 
    if attribs[i]['type'] == typeName: 
      return True
  return False
  
def writeInternalStart(outFile):
  outFile.write('/** @cond doxygen-libsbml-internal */\n\n')
  
def writeInternalEnd(outFile):
  outFile.write('/** @endcond doxygen-libsbml-internal */\n\n\n')

def writeInternalStartDecl(outFile):
  outFile.write('\t/** @cond doxygen-libsbml-internal */\n\n')
  
def writeInternalEndDecl(outFile):
  outFile.write('\t/** @endcond doxygen-libsbml-internal */\n\n\n')

def writeListOf(element):
  if (element == 'SetValue'):
    return 'SedListOfTaskChanges'
  last = len(element)-1
  if element[last] != 's':
    element = element + 's'
  element = 'SedListOf' + element
  return element

def parseAttribute(attrib):
  attName = attrib['name']
  capAttName = strFunctions.cap(attName)
  reqd = attrib['reqd']
  if attrib['type'] == 'SId':
    attType = 'string'
    attTypeCode = 'std::string&'
    num = False
  elif attrib['type'] == 'SIdRef':
    attType = 'string'
    attTypeCode = 'std::string&'
    num = False
  elif attrib['type'] == 'UnitSIdRef':
    attType = 'string'
    attTypeCode = 'std::string&'
    num = False
  elif attrib['type'] == 'UnitSId':
    attType = 'string'
    attTypeCode = 'std::string&'
    num = False
  elif attrib['type'] == 'string':
    attType = 'string'
    attTypeCode = 'std::string&'
    num = False
  elif attrib['type'] == 'double':
    attType = 'double'
    attTypeCode = 'double'
    num = True
  elif attrib['type'] == 'int':
    attType = 'integer'
    attTypeCode = 'int'
    num = True
  elif attrib['type'] == 'uint':
    attType = 'unsigned integer'
    attTypeCode = 'unsigned int'
    num = True
  elif attrib['type'] == 'bool':
    attType = 'boolean'
    attTypeCode = 'bool'
    num = False
  elif attrib['type'] == 'element':
    attType = 'element'
    if attrib['name'] == 'math' or attrib['name'] == 'Math':
      attTypeCode = 'ASTNode*'
    else:
      #attTypeCode = 'element-not-done'
      if attrib.has_key('element'):
	    attTypeCode = '{0}*'.format(attrib['element'])
      else:
        attTypeCode = '{0}*'.format(strFunctions.cap(attrib['name']))
    num = False
  elif attrib['type'] == 'lo_element':
    attType = 'lo_element'
    attTypeCode = attrib['element']
    num = False
  elif attrib['type'] == 'XMLNode*':
    attType = 'XMLNode*'
    attTypeCode = 'XMLNode*'
    num = False
  elif attrib['type'] == 'std::vector<double>':
    attType = 'std::vector<double>'
    attTypeCode = 'std::vector<double>'
    num = False
  else:
    attType = 'FIX ME'
    attTypeCode = 'FIX ME'
    num = False
  return [attName, capAttName, attType, attTypeCode, num, reqd]


def parseAttributeForC(attrib):
  attName = attrib['name']
  capAttName = strFunctions.cap(attName)
  reqd = attrib['reqd']
  if attrib['type'] == 'SId':
    attType = 'string'
    attTypeCode = 'const char *'
    num = False
  elif attrib['type'] == 'SIdRef':
    attType = 'string'
    attTypeCode = 'const char *'
    num = False
  elif attrib['type'] == 'UnitSIdRef':
    attType = 'string'
    attTypeCode = 'const char *'
    num = False
  elif attrib['type'] == 'UnitSId':
    attType = 'string'
    attTypeCode = 'const char *'
    num = False
  elif attrib['type'] == 'string':
    attType = 'string'
    attTypeCode = 'const char *'
    num = False
  elif attrib['type'] == 'double':
    attType = 'double'
    attTypeCode = 'double'
    num = True
  elif attrib['type'] == 'int':
    attType = 'integer'
    attTypeCode = 'int'
    num = True
  elif attrib['type'] == 'uint':
    attType = 'unsigned integer'
    attTypeCode = 'unsigned int'
    num = True
  elif attrib['type'] == 'bool':
    attType = 'boolean'
    attTypeCode = 'int'
    num = False
  elif attrib['type'] == 'element':
    attType = 'element'
    if attrib['name'] == 'math' or attrib['name'] == 'Math':
      attTypeCode = 'ASTNode_t*'
    else:
      #attTypeCode = 'element-not-done'
	  attTypeCode = '{0}*'.format(strFunctions.cap(attrib['name']))
    num = False
  elif attrib['type'] == 'lo_element':
    attType = 'lo_element'
    attTypeCode = attrib['element']
    num = False
  elif attrib['type'] == 'XMLNode*':
    attType = 'XMLNode*'
    attTypeCode = 'XMLNode*'
    num = False
  elif attrib['type'] == 'std::vector<double>':
    attType = 'std::vector<double>'
    attTypeCode = 'std::vector<double>'
    num = False
  else:
    attType = 'FIX ME'
    attTypeCode = 'FIX ME'
    num = False
  return [attName, capAttName, attType, attTypeCode, num, reqd]


def writeGetTypeCodeHeader(outFile, isSedListOf):
  outFile.write('\t/**\n')
  if isSedListOf == True:
    outFile.write('\t * Returns the libSEDML type code for the SEDML objects\n')
    outFile.write('\t * contained in this SedListOf object\n')
  else:
    outFile.write('\t * Returns the libSEDML type code for this SEDML object.\n')
  outFile.write('\t * \n')
  outFile.write('\t * @if clike LibSEDML attaches an identifying code to every kind of SEDML\n')
  outFile.write('\t * object.  These are known as <em>SEDML type codes</em>.  The set of\n')
  outFile.write('\t * possible type codes is defined in the enumeration #SEDMLTypeCode_t.\n')
  outFile.write('\t * The names of the type codes all begin with the characters @c\n')
  outFile.write('\t * SEDML_. @endif@if java LibSEDML attaches an identifying code to every\n')
  outFile.write('\t * kind of SEDML object.  These are known as <em>SEDML type codes</em>.  In\n')
  outFile.write('\t * other languages, the set of type codes is stored in an enumeration; in\n')
  outFile.write('\t * the Java language interface for libSEDML, the type codes are defined as\n')
  outFile.write('\t * static integer constants in the interface class {@link\n')
  outFile.write('\t * libsbmlConstants}.  The names of the type codes all begin with the\n')
  outFile.write('\t * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying\n')
  outFile.write('\t * code to every kind of SEDML object.  These are known as <em>SEDML type\n')
  outFile.write('\t * codes</em>.  In the Python language interface for libSEDML, the type\n')
  outFile.write('\t * codes are defined as static integer constants in the interface class\n')
  outFile.write('\t * @link libsbml@endlink.  The names of the type codes all begin with the\n')
  outFile.write('\t * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying\n')
  outFile.write('\t * code to every kind of SEDML object.  These are known as <em>SEDML type\n')
  outFile.write('\t * codes</em>.  In the C# language interface for libSEDML, the type codes\n')
  outFile.write('\t * are defined as static integer constants in the interface class @link\n')
  outFile.write('\t * libsbmlcs.libsbml@endlink.  The names of the type codes all begin with\n')
  outFile.write('\t * the characters @c SEDML_. @endif\n')
  outFile.write('\t *\n')
  if isSedListOf == True:
    outFile.write('\t * @return the SEDML type code for the objects in this SedListOf instance, or\n')
  else:
    outFile.write('\t * @return the SEDML type code for this object, or\n')
  outFile.write('\t * @link SEDMLTypeCode_t#SEDML_UNKNOWN SEDML_UNKNOWN@endlink (default).\n')
  outFile.write('\t *\n')
  outFile.write('\t * @see getElementName()\n')
  outFile.write('\t */\n')
  if isSedListOf == True:
    outFile.write('\tvirtual int getItemTypeCode () const;\n\n\n')
  else:
    outFile.write('\tvirtual int getTypeCode () const;\n\n\n')
    
def writeGetTypeCodeCPPCode(outFile, element, sbmltc, isSedListOf):
  outFile.write('/*\n')
  outFile.write(' * Returns the libSEDML type code for this SEDML object.\n')
  outFile.write(' */\n')
  outFile.write('int\n{0}::getTypeCode () const\n'.format(element))
  outFile.write('{\n')
  if isSedListOf == True:
    outFile.write('\treturn SEDML_LIST_OF;\n')
  else:
    outFile.write('\treturn {0};\n'.format(sbmltc))
  outFile.write('}\n\n\n')
  if isSedListOf == True:
    outFile.write('/*\n')
    outFile.write(' * Returns the libSEDML type code for the objects in this LIST_OF.\n')
    outFile.write(' */\n')
    outFile.write('int\n{0}::getItemTypeCode () const\n'.format(element))
    outFile.write('{\n')
    outFile.write('\treturn {0};\n'.format(sbmltc))
    outFile.write('}\n\n\n')
    
def writeWriteElementsHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * Subclasses should override this method to write out their contained\n')
  outFile.write('\t * SEDML objects as XML elements.  Be sure to call your parents\n')
  outFile.write('\t * implementation of this method as well.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual void writeElements (XMLOutputStream& stream) const;\n\n\n')
  writeInternalEnd(outFile)

def writeWriteElementsCPPCode(outFile, element, attributes, hasChildren=False, hasMath=False, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * write contained elements\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::writeElements (XMLOutputStream& stream) const\n'.format(element))
  outFile.write('{\n')
  outFile.write('\t{0}::writeElements(stream);\n'.format(baseClass))
  if hasChildren == True:
    for i in range(0, len(attributes)):
      if attributes[i]['type'] == 'element' and (attributes[i]['name'] != 'Math' and attributes[i]['name'] != 'math'):
        outFile.write('\tif (isSet{0}() == true)\n'.format(strFunctions.cap(attributes[i]['name'])))
        outFile.write('\t{\n\t\t')
        outFile.write('m{0}->write(stream);'.format(strFunctions.cap(attributes[i]['name'])))
        outFile.write('\n\t}\n')		
      if attributes[i]['type'] == 'lo_element':
        outFile.write('\tif (getNum{0}() > 0)\n'.format(strFunctions.capp(attributes[i]['name'])))
        outFile.write('\t{\n\t\t')
        outFile.write('m{0}.write(stream);'.format(strFunctions.capp(attributes[i]['name'])))
        outFile.write('\n\t}\n')
  if containsType(attributes, 'XMLNode*'):
    node = getByType(attributes, 'XMLNode*')
    outFile.write('\tif (isSet{0}() == true)\n'.format(strFunctions.cap(node['name'])))
    outFile.write('\t{\n\t\t')
    outFile.write('stream.startElement("{0}");\n'.format(node['name']))
    outFile.write('\t\tstream << *m{0};\n'.format(strFunctions.cap(node['name'])))
    outFile.write('\t\tstream.endElement("{0}");\n'.format(node['name']))
    outFile.write('\n\t}\n')		
  if containsType(attributes, 'std::vector<double>'):
    vector = getByType(attributes, 'std::vector<double>')
    outFile.write('\tif(has{0}())\n'.format(strFunctions.capp(vector['name'])))
    outFile.write('\t{\n')
    outFile.write('\t\tfor (std::vector<double>::const_iterator it = m{0}.begin(); it != m{0}.end(); ++it)\n'.format(strFunctions.capp(vector['name'])))
    outFile.write('\t\t{\n')
    outFile.write('\t\t\tstream.startElement("{0}");\n'.format(vector['name']))
    outFile.write('\t\t\tstream.setAutoIndent(false);\n')
    outFile.write('\t\t\tstream << " " << *it << " ";\n')
    outFile.write('\t\t\tstream.endElement("{0}");\n'.format(vector['name']))
    outFile.write('\t\t\tstream.setAutoIndent(true);\n')
    outFile.write('\t\t}\n')
    outFile.write('\t}\n')
  if hasMath == True:
    for i in range(0, len(attributes)):
      if attributes[i]['type'] == 'element' and attributes[i]['name'] == 'Math' or attributes[i]['name'] == 'math':
        outFile.write('\tif (isSet{0}() == true)\n'.format('Math'))
        outFile.write('\t{\n\t\twriteMathML(getMath(), stream, NULL);\n\t}\n')
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)

def writeAcceptHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * Accepts the given SedVisitor.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual bool accept (SedVisitor& v) const;\n\n\n')
  writeInternalEnd(outFile)

def writeAcceptCPPCode(outFile, element):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Accepts the given SedVisitor.\n')
  outFile.write(' */\n')
  outFile.write('bool\n{0}::accept (SedVisitor& v) const\n'.format(element))
  outFile.write('{\n')
  outFile.write('\treturn false;\n\n')
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)

def writeSetDocHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * Sets the parent SedDocument.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual void setSedDocument (SedDocument* d);\n\n\n')
  writeInternalEnd(outFile)

def writeSetDocCPPCode(outFile, element,attribs, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Sets the parent SedDocument.\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::setSedDocument (SedDocument* d)\n'.format(element))
  outFile.write('{\n')
  outFile.write('\t{0}::setSedDocument(d);\n'.format(baseClass))
  for i in range (0, len(attribs)):
    if attribs[i]['type'] == 'lo_element' or ( attribs[i]['type'] == 'element' and attribs[i]['name'] != 'math'):
      if attribs[i]['reqd'] == True or attribs[i]['type'] == 'lo_element':
        outFile.write('\tm{0}.setSedDocument(d);\n'.format(strFunctions.capp(attribs[i]['name'], attribs[i]['type'] == 'lo_element')))
      else:
        outFile.write('\tif (m{0} != NULL)\n'.format(strFunctions.cap(attribs[i]['name'])))
        outFile.write('\t\tm{0}->setSedDocument(d);\n'.format(strFunctions.cap(attribs[i]['name'])))
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)

def writeConnectHeader(outFile, isSedListOf=False, hasChildren=False):
  if isSedListOf or hasChildren==False:
    return;
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * Connects to child elements.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual void connectToChild ();\n\n\n')
  writeInternalEnd(outFile)


def writeCreateObjectHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * return the SEDML object corresponding to next XMLToken.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual SedBase* createObject(XMLInputStream& stream);\n\n\n')
  writeInternalEnd(outFile)

def writeAddExpectedHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * Get the list of expected attributes for this element.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual void addExpectedAttributes(ExpectedAttributes& attributes);\n\n\n')
  writeInternalEnd(outFile)
  
def writeAddExpectedCPPCode(outFile, element, attribs, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Get the list of expected attributes for this element.\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::addExpectedAttributes(ExpectedAttributes& attributes)\n'.format(element))
  outFile.write('{\n')
  outFile.write('\t{0}::addExpectedAttributes(attributes);\n\n'.format(baseClass))
  for i in range (0, len(attribs)):
    if attribs[i]['type'] != 'element' and attribs[i]['type'] != 'lo_element':
      if attribs[i].has_key('attName'): 
        outFile.write('\tattributes.add("{0}");\n'.format(attribs[i]['attName']))
      else: 
        outFile.write('\tattributes.add("{0}");\n'.format(attribs[i]['name']))
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)
  
def writeReadAttributesHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * Read values from the given XMLAttributes set into their specific fields.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual void readAttributes (const XMLAttributes& attributes,\n')
  outFile.write('\t                             const ExpectedAttributes& expectedAttributes);\n\n\n')
  writeInternalEnd(outFile)

def writeReadAttribute(output, attrib, element):
  attName = attrib['name']
  capAttName = strFunctions.cap(attName)
  if attrib['reqd'] == True:
    use = 'required'
  else:
    use = 'optional'
  if attrib['type'] == 'SId':
    output.write('\t//\n\t// {0} SId'.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    output.write('\tassigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('\tif (assigned == true)\n')
    output.write('\t{\n')
    output.write('\t\t// check string is not empty and correct syntax\n\n')
    output.write('\t\tif (m{0}.empty() == true)\n'.format(capAttName))
    output.write('\t\t{\n')
    output.write('\t\t\tlogEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('\t\t}\n')
    output.write('\t\telse if (SyntaxChecker::isValidSBMLSId(m{0}) == false)\n'.format(capAttName))
    output.write('\t\t{\n\t\t\tlogError(SedInvalidIdSyntax);\n\t\t}\n')
    output.write('\t}\n\n')
  elif attrib['type'] == 'SIdRef':
    output.write('\t//\n\t// {0} SIdRef '.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    if attrib.has_key('attName'): 
      output.write('\tassigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attrib['attName'], capAttName))
    else: 
      output.write('\tassigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('\tif (assigned == true)\n')
    output.write('\t{\n')
    output.write('\t\t// check string is not empty and correct syntax\n\n')
    output.write('\t\tif (m{0}.empty() == true)\n'.format(capAttName))
    output.write('\t\t{\n')
    output.write('\t\t\tlogEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('\t\t}\n')
    output.write('\t\telse if (SyntaxChecker::isValidSBMLSId(m{0}) == false)\n'.format(capAttName))
    output.write('\t\t{\n\t\t\tlogError(SedInvalidIdSyntax);\n\t\t}\n')
    output.write('\t}\n\n')
  elif attrib['type'] == 'UnitSIdRef':
    output.write('\t//\n\t// {0} UnitSIdRef '.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    output.write('\tassigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('\tif (assigned == true)\n')
    output.write('\t{\n')
    output.write('\t\t// check string is not empty and correct syntax\n\n')
    output.write('\t\tif (m{0}.empty() == true)\n'.format(capAttName))
    output.write('\t\t{\n')
    output.write('\t\t\tlogEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('\t\t}\n')
    output.write('\t\telse if (SyntaxChecker::isValidInternalUnitSId(m{0}) == false)\n'.format(capAttName))
    output.write('\t\t{\n\t\t\tlogError(SedInvalidUnitIdSyntax);\n\t\t}\n')
    output.write('\t}\n\n')
  elif attrib['type'] == 'UnitSId':
    output.write('\t//\n\t// {0} UnitSId '.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    output.write('\tassigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('\tif (assigned == true)\n')
    output.write('\t{\n')
    output.write('\t\t// check string is not empty and correct syntax\n\n')
    output.write('\t\tif (m{0}.empty() == true)\n'.format(capAttName))
    output.write('\t\t{\n')
    output.write('\t\t\tlogEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('\t\t}\n')
    output.write('\t\telse if (SyntaxChecker::isValidInternalUnitSId(m{0}) == false)\n'.format(capAttName))
    output.write('\t\t{\n\t\t\tlogError(SedInvalidUnitIdSyntax);\n\t\t}\n')
    output.write('\t}\n\n')
  elif attrib['type'] == 'string':
    output.write('\t//\n\t// {0} string '.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    output.write('\tassigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('\tif (assigned == true)\n')
    output.write('\t{\n')
    output.write('\t\t// check string is not empty\n\n')
    output.write('\t\tif (m{0}.empty() == true)\n'.format(capAttName))
    output.write('\t\t{\n')
    output.write('\t\t\tlogEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('\t\t}\n')
    output.write('\t}\n\n')
  elif attrib['type'] == 'double':
    output.write('\t//\n\t// {0} double '.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    output.write('\tmIsSet{1} = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
  elif attrib['type'] == 'int':
    output.write('\t//\n\t// {0} int '.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    output.write('\tmIsSet{1} = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
  elif attrib['type'] == 'uint':
    output.write('\t//\n\t// {0} unsigned int '.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    output.write('\tmIsSet{1} = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
  elif attrib['type'] == 'bool':
    output.write('\t//\n\t// {0} bool '.format(attName))
    output.write('  ( use = "{0}" )\n\t//\n'.format(use))
    output.write('\tmIsSet{1} = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
  elif attrib['type'] == 'element':
    return
  elif attrib['type'] == 'std::vector<double>':
    return
  else:
    attType = 'FIX ME'
    attTypeCode = 'FIX ME'
    num = False
	
def writeCreateObject(outFile, element, sbmltypecode, attribs, isSedListOf, hasChildren=False, hasMath=False,baseClass='SedBase'):  
  if (isSedListOf == True or hasChildren == False) and baseClass  == 'SedBase':
    return;
  outFile.write('/**\n')
  outFile.write(' * return the SEDML object corresponding to next XMLToken.\n')
  outFile.write(' */\n')
  outFile.write('SedBase*\n{0}::createObject(XMLInputStream& stream)\n'.format(element))
  outFile.write('{\n')
  if baseClass == 'SedBase':
    outFile.write('\tSedBase* object = NULL;\n\n')
  else:
    outFile.write('\tSedBase* object = {0}::createObject(stream);\n\n'.format(baseClass))
  if hasChildren or hasMath:
    outFile.write('\tconst string& name   = stream.peek().getName();\n\n')
  for i in range (0, len(attribs)):
    current = attribs[i]
    if current.has_key('lo_elementName'):        
      outFile.write('\tif (name == "{0}")\n'.format(current['lo_elementName']))	
      outFile.write('\t{\n')	
      outFile.write('\t\tobject = &m{0};\n'.format(strFunctions.capp(current['name'])))	
      outFile.write('\t}\n\n')
    elif current['type'] == 'lo_element':
      outFile.write('\tif (name == "listOf{0}")\n'.format(strFunctions.capp(current['name'])))	
      outFile.write('\t{\n')	
      outFile.write('\t\tobject = &m{0};\n'.format(strFunctions.capp(current['name'])))	
      outFile.write('\t}\n\n')
    elif current['type'] == 'element' and (current['name'] !='Math' and current['name'] != 'math'):
      outFile.write('\tif (name == "{0}")\n'.format(current['name']))	
      outFile.write('\t{\n')	
      outFile.write('\t\tm{0}= new {1}();\n'.format(strFunctions.cap(current['name']), current['element']))	
      outFile.write('\t\tobject = m{0};\n'.format(strFunctions.cap(current['name'])))	
      outFile.write('\t}\n\n')
  outFile.write('\tconnectToChild();\n\n')
  outFile.write('\treturn object;\n')  
  outFile.write('}\n\n\n')  

def writeConnectToParent(outFile, element, sbmltypecode, attribs, isSedListOf, hasChildren=False, hasMath=False, baseClass='SedBase'):  
  #print 'isSedListOf={0} hasChildren={1} hasMath={2}'.format(isSedListOf, hasChildren, hasMath)
  if isSedListOf or hasChildren == False:
    return;
  outFile.write('/*\n')
  outFile.write(' * Read values from the given XMLAttributes set into their specific fields.\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::connectToChild ()\n'.format(element))
  outFile.write('{\n')
  outFile.write('\t{0}::connectToChild();\n\n'.format(baseClass))
  for i in range (0, len(attribs)):
    if attribs[i]['type'] == 'lo_element' or ( attribs[i]['type'] == 'element' and attribs[i]['name'] != 'math'):
      if attribs[i]['reqd'] == True or attribs[i]['type'] == 'lo_element':
        outFile.write('\tm{0}.connectToParent(this);\n'.format(strFunctions.capp(attribs[i]['name'],attribs[i]['type'] == 'lo_element')))
      else:
        outFile.write('\tif (m{0} != NULL)\n'.format(strFunctions.cap(attribs[i]['name'])))
        outFile.write('\t\tm{0}->connectToParent(this);\n'.format(strFunctions.cap(attribs[i]['name'])))
  outFile.write('}\n\n\n')  

def writeReadAttributesCPPCode(outFile, element, attribs, baseClass):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Read values from the given XMLAttributes set into their specific fields.\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::readAttributes (const XMLAttributes& attributes,\n'.format(element))
  outFile.write('                             const ExpectedAttributes& expectedAttributes)\n')
  outFile.write('{\n')
  outFile.write('\t{0}::readAttributes(attributes, expectedAttributes);\n\n'.format(baseClass))
  if (len(attribs) > 0):
    outFile.write('\tbool assigned = false;\n\n')
  for i in range (0, len(attribs)):
    writeReadAttribute(outFile, attribs[i], element)
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)

def writeWriteAttributesHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * Write values of XMLAttributes to the output stream.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual void writeAttributes (XMLOutputStream& stream) const;\n\n\n')
  writeInternalEnd(outFile)
  
def writeWriteAttributesCPPCode(outFile, element, attribs, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Write values of XMLAttributes to the output stream.\n')
  outFile.write(' */\n')
  outFile.write('\tvoid\n{0}::writeAttributes (XMLOutputStream& stream) const\n'.format(element))
  outFile.write('{\n')
  outFile.write('\t{0}::writeAttributes(stream);\n\n'.format(baseClass))
  for i in range (0, len(attribs)):
    if attribs[i]['type'] != 'element' and attribs[i]['type'] != 'XMLNode*' and attribs[i]['type'] != 'lo_element' and attribs[i]['type'] != 'std::vector<double>':
      outFile.write('\tif (isSet{0}() == true)\n'.format(strFunctions.cap(attribs[i]['name'])))
      if attribs[i].has_key('attName'): 
        outFile.write('\t\tstream.writeAttribute("{0}", getPrefix(), m{1});\n\n'.format(attribs[i]['attName'], strFunctions.cap(attribs[i]['name'])))	 
      else:
        outFile.write('\t\tstream.writeAttribute("{0}", getPrefix(), m{1});\n\n'.format(attribs[i]['name'], strFunctions.cap(attribs[i]['name'])))	 
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)
  
def writeGetElementNameHeader(outFile, element, isSedListOf):
  if isSedListOf == True:
    element = writeListOf(element)
  outFile.write('\t/**\n')
  outFile.write('\t * Returns the XML element name of this object, which for {0}, is\n'.format(element))
  outFile.write('\t * always @c "{0}".\n'.format(strFunctions.lowerFirst(element)))
  outFile.write('\t *\n')
  outFile.write('\t * @return the name of this element, i.e. @c "{0}".\n'.format(strFunctions.lowerFirst(element)))
  outFile.write('\t */\n')
  outFile.write('\tvirtual const std::string& getElementName () const;\n\n\n')

def writeGetElementNameCPPCode(outFile, element, isSedListOf=False, dict=None):
  outFile.write('/*\n')
  outFile.write(' * Returns the XML element name of this object\n')
  outFile.write(' */\n')
  outFile.write('const std::string&\n{0}::getElementName () const\n'.format(element))
  outFile.write('{\n')
  if dict != None and dict.has_key('elementName'):
    if isSedListOf:
      if dict.has_key('lo_elementName'):        
        outFile.write('\tstatic const string name = "{0}";\n'.format(dict['lo_elementName']))
      else:
        outFile.write('\tstatic const string name = "listOf{0}";\n'.format(strFunctions.capp(dict['elementName'])))
    else:
      outFile.write('\tstatic const string name = "{0}";\n'.format(dict['elementName']))
  else:
    if dict != None and dict.has_key('lo_elementName'):
      outFile.write('\tstatic const string name = "{0}";\n'.format(dict['lo_elementName']))
    else: 
      outFile.write('\tstatic const string name = "{0}";\n'.format(strFunctions.lowerFirst(element)))
  outFile.write('\treturn name;\n')
  outFile.write('}\n\n\n')
  

def writeHasReqdAttribHeader(outFile, element, attribs):
  outFile.write('\t/**\n')
  outFile.write('\t * Predicate returning @c true if all the required attributes\n')
  outFile.write('\t * for this {0} object have been set.\n'.format(element))
  outFile.write('\t *\n')
  outFile.write('\t * @note The required attributes for a {0} object are:\n'.format(element))
  for i in range (0, len(attribs)):
    att = parseAttribute(attribs[i])
    if att[5] == True:
      outFile.write('\t * @li "{0}"\n'.format(att[0]))
  outFile.write('\t *\n')
  outFile.write('\t * @return a boolean value indicating whether all the required\n')
  outFile.write('\t * attributes for this object have been defined.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual bool hasRequiredAttributes() const;\n\n\n')

def writeHasReqdAttribCPPCode(outFile, element, attribs, baseClass):
  outFile.write('/*\n')
  outFile.write(' * check if all the required attributes are set\n')
  outFile.write(' */\n')
  outFile.write('bool\n{0}::hasRequiredAttributes () const\n'.format(element))
  outFile.write('{\n')
  if baseClass == 'SedBase':
    outFile.write('\tbool allPresent = true;\n\n')
  else:
    outFile.write('\tbool allPresent = {0}::hasRequiredAttributes();\n\n'.format(baseClass))
  for i in range(0, len(attribs)):
    if attribs[i]['reqd'] == True and attribs[i]['type'] != 'element':
      outFile.write('\tif (isSet{0}() == false)\n'.format(strFunctions.cap(attribs[i]['name'])))
      outFile.write('\t\tallPresent = false;\n\n')
  outFile.write('\treturn allPresent;\n')
  outFile.write('}\n\n\n')

def writeHasReqdElementsHeader(outFile, element, attribs):
  outFile.write('\t/**\n')
  outFile.write('\t * Predicate returning @c true if all the required elements\n')
  outFile.write('\t * for this {0} object have been set.\n'.format(element))
  outFile.write('\t *\n')
  outFile.write('\t * @note The required elements for a {0} object are:\n'.format(element))
  for i in range (0, len(attribs)):
    att = parseAttribute(attribs[i])
    if (att[2] == 'element' or att[2] == 'lo_element') and att[5] == True:
      outFile.write('\t * @li "{0}"\n'.format(att[0]))
  outFile.write('\t *\n')
  outFile.write('\t * @return a boolean value indicating whether all the required\n')
  outFile.write('\t * elements for this object have been defined.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual bool hasRequiredElements() const;\n\n\n')

def writeHasReqdElementsCPPCode(outFile, element, attribs, baseClass):
  outFile.write('/*\n')
  outFile.write(' * check if all the required elements are set\n')
  outFile.write(' */\n')
  outFile.write('bool\n{0}::hasRequiredElements () const\n'.format(element))
  outFile.write('{\n')
  if baseClass == 'SedBase':
    outFile.write('\tbool allPresent = true;\n\n')
  else:
    outFile.write('\tbool allPresent = {0}::hasRequiredElements();\n\n'.format(baseClass))
  for i in range(0, len(attribs)):
    if attribs[i]['reqd'] == True and attribs[i]['type'] == 'element':
      outFile.write('\tif (isSet{0}() == false)\n'.format(strFunctions.cap(attribs[i]['name'])))
      outFile.write('\t\tallPresent = false;\n\n')
  outFile.write('\treturn allPresent;\n')
  outFile.write('}\n\n\n')

def writeReadOtherXMLHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('\t/**\n')
  outFile.write('\t * Subclasses should override this method ro read other XML.\n')
  outFile.write('\t *\n\t * return true if read from stream, false otherwise.\n')
  outFile.write('\t */\n')
  outFile.write('\tvirtual bool readOtherXML (XMLInputStream& stream);\n\n\n')
  writeInternalEnd(outFile)
  
def writeReadOtherXMLCPPCode(outFile, element, hasMath = True, attribs = None, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('bool\n{0}::readOtherXML (XMLInputStream& stream)\n'.format(element))
  outFile.write('{\n')
  outFile.write('\tbool          read = false;\n')
  outFile.write('\tconst string& name = stream.peek().getName();\n\n')
  if hasMath == True: 
    outFile.write('\tif (name == "math")\n\t{\n')
    outFile.write('\t\tconst XMLToken elem = stream.peek();\n')
    outFile.write('\t\tconst std::string prefix = checkMathMLNamespace(elem);\n\n')
    #outFile.write('\t\tif (stream.getSedNamespaces() == NULL)\n\t\t{\n')
    #outFile.write('\t\t\tstream.setSedNamespaces(new SedNamespaces(getLevel(), getVersion()));\n\t\t}\n\n')
    outFile.write('\t\tdelete mMath;\n')
    outFile.write('\t\tmMath = readMathML(stream, prefix);\n')
    #outFile.write('\t\tif (mMath != NULL)\n\t\t{\n\t\t\tmMath->setParentSEDMLObject(this);\n\t\t}\n')
    outFile.write('\t\tread = true;\n\t}\n\n')
  elif containsType(attribs, 'XMLNode*'):
    node = getByType(attribs, 'XMLNode*')
    outFile.write('\tif (name == "{0}")\n'.format(node['name']))
    outFile.write('\t{\n')	
    outFile.write('\t\tconst XMLToken& token = stream.next();\n')	
    outFile.write('\t\tstream.skipText();\n')	
    outFile.write('\t\tm{0} = new XMLNode(stream);\n'.format(strFunctions.cap(node['name'])))	
    outFile.write('\t\tstream.skipPastEnd(token);\n')	
    outFile.write('\t\tread = true;\n\t}\n\n')
  elif containsType(attribs, 'std::vector<double>'):
    elem = getByType(attribs, 'std::vector<double>')
    outFile.write('\twhile (stream.peek().getName() == "{0}")\n'.format(elem['name']))
    outFile.write('\t{\n')
    outFile.write('\t  stream.next(); // consume start\n')
    outFile.write('\t  stringstream text;\n')
    outFile.write('\t  while(stream.isGood() && stream.peek().isText())\n')
    outFile.write('\t    text << stream.next().getCharacters();\n')
    outFile.write('\t  double value; text >> value;\n')
    outFile.write('\t  if (!text.fail())\n')
    outFile.write('\t    m{0}.push_back(value);\n'.format(strFunctions.capp(elem['name'])))
    outFile.write('\t  stream.next(); // consume end\n')
    outFile.write('\t  read = true;\n')
    outFile.write('\t}\n')
  outFile.write('\tif ({0}::readOtherXML(stream))\n'.format(baseClass))
  outFile.write('\t{\n\t\tread = true;\n\t}\n')
  outFile.write('\treturn read;\n')
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)
  



def writeProtectedHeaders(outFile, attribs = None, hasChildren=False, hasMath=False, baseClass='SedBase'):
  if hasChildren or baseClass != 'SedBase':
    writeCreateObjectHeader(outFile)
  writeAddExpectedHeader(outFile)
  writeReadAttributesHeader(outFile)
  if hasMath == True or containsType(attribs, 'std::vector<double>') or containsType(attribs, 'XMLNode*'):
    writeReadOtherXMLHeader(outFile)
  writeWriteAttributesHeader(outFile)
  
def writeCommonHeaders(outFile, element, attribs, isSedListOf, hasChildren=False, hasMath=False):
  writeGetElementNameHeader(outFile, element, isSedListOf)
  if isSedListOf == True:
    writeGetTypeCodeHeader(outFile, False)
  writeGetTypeCodeHeader(outFile, isSedListOf)
  if isSedListOf == False:
    writeHasReqdAttribHeader(outFile, element, attribs)
  if hasChildren == True or hasMath == True:
    writeHasReqdElementsHeader(outFile, element, attribs)


def writeInternalHeaders(outFile, isSedListOf, hasChildren=False):
  writeWriteElementsHeader(outFile)
  writeAcceptHeader(outFile)
  writeSetDocHeader(outFile)
  if hasChildren or isSedListOf:
    writeConnectHeader(outFile, isSedListOf, hasChildren)
  
def writeCommonCPPCode(outFile, element, sbmltypecode, attribs, isSedListOf, hasChildren=False, hasMath=False, elementDict=None, baseClass='SedBase'):
  type = elementDict['name']
  name = elementDict['name']
  if elementDict.has_key('elementName'):
    name = strFunctions.cap(elementDict['elementName']) 
  if elementDict.has_key('element'):
    type = elementDict['element']
  if isSedListOf == True:
    element = writeListOf(name)
  writeGetElementNameCPPCode(outFile, element, isSedListOf, elementDict)
  if hasChildren or baseClass != 'SedBase':
    writeCreateObject(outFile, element, sbmltypecode, attribs, isSedListOf, hasChildren, hasMath, baseClass)
    writeConnectToParent(outFile, element, sbmltypecode, attribs, isSedListOf, hasChildren, hasMath, baseClass)
  writeGetTypeCodeCPPCode(outFile, element, sbmltypecode, isSedListOf)
  if isSedListOf == False:
    writeHasReqdAttribCPPCode(outFile, element, attribs, baseClass)
  if hasChildren == True or hasMath == True:
    writeHasReqdElementsCPPCode(outFile, element, attribs, baseClass)

def writeInternalCPPCode(outFile, element, attributes, False, hasChildren, hasMath,baseClass='SedBase'):
  writeWriteElementsCPPCode(outFile, element, attributes, hasChildren, hasMath, baseClass)
  writeAcceptCPPCode(outFile, element)
  writeSetDocCPPCode(outFile, element, attributes,baseClass)

def writeProtectedCPPCode(outFile, element, attribs, False, hasChildren, hasMath, baseClass):
  writeAddExpectedCPPCode(outFile, element, attribs, baseClass)
  writeReadAttributesCPPCode(outFile, element, attribs, baseClass)
  if hasMath == True or containsType(attribs, 'std::vector<double>') or containsType(attribs, 'XMLNode*'):
    writeReadOtherXMLCPPCode(outFile, element, hasMath, attribs, baseClass)
  writeWriteAttributesCPPCode(outFile, element, attribs, baseClass)
