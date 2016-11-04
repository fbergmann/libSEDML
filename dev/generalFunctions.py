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
  outFile.write('/** @cond doxygen-libsedml-internal */\n\n')
  
def writeInternalEnd(outFile):
  outFile.write('/** @endcond doxygen-libsedml-internal */\n\n\n')

def writeInternalStartDecl(outFile):
  outFile.write('  /** @cond doxygen-libsedml-internal */\n\n')
  
def writeInternalEndDecl(outFile):
  outFile.write('  /** @endcond doxygen-libsedml-internal */\n\n\n')

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
  elif attrib['type'] == 'DimensionDescription*':
    attType = 'DimensionDescription*'
    attTypeCode = 'DimensionDescription*'
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
  elif attrib['type'] == 'DimensionDescription*':
    attType = 'DimensionDescription*'
    attTypeCode = 'DimensionDescription*'
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
  outFile.write('  /**\n')
  if isSedListOf == True:
    outFile.write('   * Returns the libSEDML type code for the SEDML objects\n')
    outFile.write('   * contained in this SedListOf object\n')
  else:
    outFile.write('   * Returns the libSEDML type code for this SEDML object.\n')
  outFile.write('   *\n')
  outFile.write('   * @if clike LibSEDML attaches an identifying code to every kind of SEDML\n')
  outFile.write('   * object.  These are known as <em>SEDML type codes</em>.  The set of\n')
  outFile.write('   * possible type codes is defined in the enumeration #SEDMLTypeCode_t.\n')
  outFile.write('   * The names of the type codes all begin with the characters @c\n')
  outFile.write('   * SEDML_. @endif@if java LibSEDML attaches an identifying code to every\n')
  outFile.write('   * kind of SEDML object.  These are known as <em>SEDML type codes</em>.  In\n')
  outFile.write('   * other languages, the set of type codes is stored in an enumeration; in\n')
  outFile.write('   * the Java language interface for libSEDML, the type codes are defined as\n')
  outFile.write('   * static integer constants in the interface class {@link\n')
  outFile.write('   * libsedmlConstants}.  The names of the type codes all begin with the\n')
  outFile.write('   * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying\n')
  outFile.write('   * code to every kind of SEDML object.  These are known as <em>SEDML type\n')
  outFile.write('   * codes</em>.  In the Python language interface for libSEDML, the type\n')
  outFile.write('   * codes are defined as static integer constants in the interface class\n')
  outFile.write('   * @link libsedml@endlink.  The names of the type codes all begin with the\n')
  outFile.write('   * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying\n')
  outFile.write('   * code to every kind of SEDML object.  These are known as <em>SEDML type\n')
  outFile.write('   * codes</em>.  In the C# language interface for libSEDML, the type codes\n')
  outFile.write('   * are defined as static integer constants in the interface class @link\n')
  outFile.write('   * libsedmlcs.libsedml@endlink.  The names of the type codes all begin with\n')
  outFile.write('   * the characters @c SEDML_. @endif\n')
  outFile.write('   *\n')
  if isSedListOf == True:
    outFile.write('   * @return the SEDML type code for the objects in this SedListOf instance, or\n')
  else:
    outFile.write('   * @return the SEDML type code for this object, or\n')
  outFile.write('   * @link SEDMLTypeCode_t#SEDML_UNKNOWN SEDML_UNKNOWN@endlink (default).\n')
  outFile.write('   *\n')
  outFile.write('   * @see getElementName()\n')
  outFile.write('   */\n')
  if isSedListOf == True:
    outFile.write('  virtual int getItemTypeCode () const;\n\n\n')
  else:
    outFile.write('  virtual int getTypeCode () const;\n\n\n')
    
def writeGetTypeCodeCPPCode(outFile, element, sbmltc, isSedListOf):
  outFile.write('/*\n')
  outFile.write(' * Returns the libSEDML type code for this SEDML object.\n')
  outFile.write(' */\n')
  outFile.write('int\n{0}::getTypeCode () const\n'.format(element))
  outFile.write('{\n')
  if isSedListOf == True:
    outFile.write('  return SEDML_LIST_OF;\n')
  else:
    outFile.write('  return {0};\n'.format(sbmltc))
  outFile.write('}\n\n\n')
  if isSedListOf == True:
    outFile.write('/*\n')
    outFile.write(' * Returns the libSEDML type code for the objects in this LIST_OF.\n')
    outFile.write(' */\n')
    outFile.write('int\n{0}::getItemTypeCode () const\n'.format(element))
    outFile.write('{\n')
    outFile.write('  return {0};\n'.format(sbmltc))
    outFile.write('}\n\n\n')
    
def writeWriteElementsHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * Subclasses should override this method to write out their contained\n')
  outFile.write('   * SEDML objects as XML elements.  Be sure to call your parents\n')
  outFile.write('   * implementation of this method as well.\n')
  outFile.write('   */\n')
  outFile.write('  virtual void writeElements (XMLOutputStream& stream) const;\n\n\n')
  writeInternalEnd(outFile)

def writeWriteElementsCPPCode(outFile, element, attributes, hasChildren=False, hasMath=False, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * write contained elements\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::writeElements (XMLOutputStream& stream) const\n'.format(element))
  outFile.write('{\n')
  outFile.write('  {0}::writeElements(stream);\n'.format(baseClass))
  if hasChildren == True:
    for i in range(0, len(attributes)):
      if attributes[i]['type'] == 'element' and (attributes[i]['name'] != 'Math' and attributes[i]['name'] != 'math'):
        outFile.write('  if (isSet{0}() == true)\n'.format(strFunctions.cap(attributes[i]['name'])))
        outFile.write('  {\n    ')
        outFile.write('m{0}->write(stream);'.format(strFunctions.cap(attributes[i]['name'])))
        outFile.write('\n  }\n')		
      if attributes[i]['type'] == 'lo_element':
        outFile.write('  if (getNum{0}() > 0)\n'.format(strFunctions.capp(attributes[i]['name'])))
        outFile.write('  {\n    ')
        outFile.write('m{0}.write(stream);'.format(strFunctions.capp(attributes[i]['name'])))
        outFile.write('\n  }\n')
  if containsType(attributes, 'DimensionDescription*'):
    node = getByType(attributes, 'DimensionDescription*')
    outFile.write('  if (isSet{0}() == true)\n'.format(strFunctions.cap(node['name'])))
    outFile.write('  {\n    ')
    outFile.write('m{0}->write(stream);'.format(strFunctions.cap(node['name'])))
    outFile.write('\n  }\n')		
  if containsType(attributes, 'XMLNode*'):
    node = getByType(attributes, 'XMLNode*')
    outFile.write('  if (isSet{0}() == true)\n'.format(strFunctions.cap(node['name'])))
    outFile.write('  {\n    ')
    outFile.write('stream.startElement("{0}");\n'.format(node['name']))
    outFile.write('    stream << *m{0};\n'.format(strFunctions.cap(node['name'])))
    outFile.write('    stream.endElement("{0}");\n'.format(node['name']))
    outFile.write('\n  }\n')		
  if containsType(attributes, 'std::vector<double>'):
    vector = getByType(attributes, 'std::vector<double>')
    outFile.write('  if(has{0}())\n'.format(strFunctions.capp(vector['name'])))
    outFile.write('  {\n')
    outFile.write('    for (std::vector<double>::const_iterator it = m{0}.begin(); it != m{0}.end(); ++it)\n'.format(strFunctions.capp(vector['name'])))
    outFile.write('    {\n')
    outFile.write('      stream.startElement("{0}");\n'.format(vector['name']))
    outFile.write('      stream.setAutoIndent(false);\n')
    outFile.write('      stream << " " << *it << " ";\n')
    outFile.write('      stream.endElement("{0}");\n'.format(vector['name']))
    outFile.write('      stream.setAutoIndent(true);\n')
    outFile.write('    }\n')
    outFile.write('  }\n')
  if hasMath == True:
    for i in range(0, len(attributes)):
      if attributes[i]['type'] == 'element' and attributes[i]['name'] == 'Math' or attributes[i]['name'] == 'math':
        outFile.write('  if (isSet{0}() == true)\n'.format('Math'))
        outFile.write('  {\n    writeMathML(getMath(), stream, NULL);\n  }\n')
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)

def writeAcceptHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * Accepts the given SedVisitor.\n')
  outFile.write('   */\n')
  outFile.write('  virtual bool accept (SedVisitor& v) const;\n\n\n')
  writeInternalEnd(outFile)

def writeAcceptCPPCode(outFile, element):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Accepts the given SedVisitor.\n')
  outFile.write(' */\n')
  outFile.write('bool\n{0}::accept (SedVisitor& v) const\n'.format(element))
  outFile.write('{\n')
  outFile.write('  return false;\n\n')
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)

def writeSetDocHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * Sets the parent SedDocument.\n')
  outFile.write('   */\n')
  outFile.write('  virtual void setSedDocument (SedDocument* d);\n\n\n')
  writeInternalEnd(outFile)

def writeSetDocCPPCode(outFile, element,attribs, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Sets the parent SedDocument.\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::setSedDocument (SedDocument* d)\n'.format(element))
  outFile.write('{\n')
  outFile.write('  {0}::setSedDocument(d);\n'.format(baseClass))
  for i in range (0, len(attribs)):
    if attribs[i]['type'] == 'lo_element' or ( attribs[i]['type'] == 'element' and attribs[i]['name'] != 'math'):
      if attribs[i]['reqd'] == True or attribs[i]['type'] == 'lo_element':
        outFile.write('  m{0}.setSedDocument(d);\n'.format(strFunctions.capp(attribs[i]['name'], attribs[i]['type'] == 'lo_element')))
      else:
        outFile.write('  if (m{0} != NULL)\n'.format(strFunctions.cap(attribs[i]['name'])))
        outFile.write('    m{0}->setSedDocument(d);\n'.format(strFunctions.cap(attribs[i]['name'])))
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)

def writeConnectHeader(outFile, isSedListOf=False, hasChildren=False):
  if isSedListOf or hasChildren==False:
    return;
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * Connects to child elements.\n')
  outFile.write('   */\n')
  outFile.write('  virtual void connectToChild ();\n\n\n')
  writeInternalEnd(outFile)


def writeCreateObjectHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * return the SEDML object corresponding to next XMLToken.\n')
  outFile.write('   */\n')
  outFile.write('  virtual SedBase* createObject(XMLInputStream& stream);\n\n\n')
  writeInternalEnd(outFile)

def writeAddExpectedHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * Get the list of expected attributes for this element.\n')
  outFile.write('   */\n')
  outFile.write('  virtual void addExpectedAttributes(ExpectedAttributes& attributes);\n\n\n')
  writeInternalEnd(outFile)
  
def writeAddExpectedCPPCode(outFile, element, attribs, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Get the list of expected attributes for this element.\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::addExpectedAttributes(ExpectedAttributes& attributes)\n'.format(element))
  outFile.write('{\n')
  outFile.write('  {0}::addExpectedAttributes(attributes);\n\n'.format(baseClass))
  for i in range (0, len(attribs)):
    if attribs[i]['type'] != 'element' and attribs[i]['type'] != 'lo_element':
      if attribs[i].has_key('attName'): 
        outFile.write('  attributes.add("{0}");\n'.format(attribs[i]['attName']))
      else: 
        outFile.write('  attributes.add("{0}");\n'.format(attribs[i]['name']))
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)
  
def writeReadAttributesHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * Read values from the given XMLAttributes set into their specific fields.\n')
  outFile.write('   */\n')
  outFile.write('  virtual void readAttributes (const XMLAttributes& attributes,\n')
  outFile.write('                               const ExpectedAttributes& expectedAttributes);\n\n\n')
  writeInternalEnd(outFile)

def writeReadAttribute(output, attrib, element):
  attName = attrib['name']
  capAttName = strFunctions.cap(attName)
  if attrib['reqd'] == True:
    use = 'required'
  else:
    use = 'optional'
  if attrib['type'] == 'SId':
    output.write('  //\n  // {0} SId'.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    output.write('  assigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('  if (assigned == true)\n')
    output.write('  {\n')
    output.write('    // check string is not empty and correct syntax\n\n')
    output.write('    if (m{0}.empty() == true)\n'.format(capAttName))
    output.write('    {\n')
    output.write('      logEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('    }\n')
    output.write('    else if (SyntaxChecker::isValidSBMLSId(m{0}) == false)\n'.format(capAttName))
    output.write('    {\n      logError(SedInvalidIdSyntax);\n    }\n')
    output.write('  }\n\n')
  elif attrib['type'] == 'SIdRef':
    output.write('  //\n  // {0} SIdRef '.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    if attrib.has_key('attName'): 
      output.write('  assigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attrib['attName'], capAttName))
    else: 
      output.write('  assigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('  if (assigned == true)\n')
    output.write('  {\n')
    output.write('    // check string is not empty and correct syntax\n\n')
    output.write('    if (m{0}.empty() == true)\n'.format(capAttName))
    output.write('    {\n')
    output.write('      logEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('    }\n')
    output.write('    else if (SyntaxChecker::isValidSBMLSId(m{0}) == false)\n'.format(capAttName))
    output.write('    {\n      logError(SedInvalidIdSyntax);\n    }\n')
    output.write('  }\n\n')
  elif attrib['type'] == 'UnitSIdRef':
    output.write('  //\n  // {0} UnitSIdRef '.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    output.write('  assigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('  if (assigned == true)\n')
    output.write('  {\n')
    output.write('    // check string is not empty and correct syntax\n\n')
    output.write('    if (m{0}.empty() == true)\n'.format(capAttName))
    output.write('    {\n')
    output.write('      logEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('    }\n')
    output.write('    else if (SyntaxChecker::isValidInternalUnitSId(m{0}) == false)\n'.format(capAttName))
    output.write('    {\n      logError(SedInvalidUnitIdSyntax);\n    }\n')
    output.write('  }\n\n')
  elif attrib['type'] == 'UnitSId':
    output.write('  //\n  // {0} UnitSId '.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    output.write('  assigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('  if (assigned == true)\n')
    output.write('  {\n')
    output.write('    // check string is not empty and correct syntax\n\n')
    output.write('    if (m{0}.empty() == true)\n'.format(capAttName))
    output.write('    {\n')
    output.write('      logEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('    }\n')
    output.write('    else if (SyntaxChecker::isValidInternalUnitSId(m{0}) == false)\n'.format(capAttName))
    output.write('    {\n      logError(SedInvalidUnitIdSyntax);\n    }\n')
    output.write('  }\n\n')
  elif attrib['type'] == 'string':
    output.write('  //\n  // {0} string '.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    output.write('  assigned = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
    output.write('  if (assigned == true)\n')
    output.write('  {\n')
    output.write('    // check string is not empty\n\n')
    output.write('    if (m{0}.empty() == true)\n'.format(capAttName))
    output.write('    {\n')
    output.write('      logEmptyString(m{0}, getLevel(), getVersion(), "<{1}>");\n'.format(capAttName, element))
    output.write('    }\n')
    output.write('  }\n\n')
  elif attrib['type'] == 'double':
    output.write('  //\n  // {0} double '.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    output.write('  mIsSet{1} = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
  elif attrib['type'] == 'int':
    output.write('  //\n  // {0} int '.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    output.write('  mIsSet{1} = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
  elif attrib['type'] == 'uint':
    output.write('  //\n  // {0} unsigned int '.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    output.write('  mIsSet{1} = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
    if use == 'required':
      output.write('true);\n\n')
    else:
      output.write('false);\n\n')
  elif attrib['type'] == 'bool':
    output.write('  //\n  // {0} bool '.format(attName))
    output.write('  ( use = "{0}" )\n  //\n'.format(use))
    output.write('  mIsSet{1} = attributes.readInto("{0}", m{1}, getErrorLog(), '.format(attName, capAttName))
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
    outFile.write('  SedBase* object = NULL;\n\n')
  else:
    outFile.write('  SedBase* object = {0}::createObject(stream);\n\n'.format(baseClass))
  if hasChildren or hasMath:
    outFile.write('  const string& name   = stream.peek().getName();\n\n')
  for i in range (0, len(attribs)):
    current = attribs[i]
    if current.has_key('lo_elementName'):        
      outFile.write('  if (name == "{0}")\n'.format(current['lo_elementName']))	
      outFile.write('  {\n')	
      outFile.write('    object = &m{0};\n'.format(strFunctions.capp(current['name'])))	
      outFile.write('  }\n\n')
    elif current['type'] == 'lo_element':
      outFile.write('  if (name == "listOf{0}")\n'.format(strFunctions.capp(current['name'])))	
      outFile.write('  {\n')	
      outFile.write('    object = &m{0};\n'.format(strFunctions.capp(current['name'])))	
      outFile.write('  }\n\n')
    elif current['type'] == 'element' and (current['name'] !='Math' and current['name'] != 'math'):
      outFile.write('  if (name == "{0}")\n'.format(current['name']))	
      outFile.write('  {\n')	
      outFile.write('    m{0}= new {1}();\n'.format(strFunctions.cap(current['name']), current['element']))	
      outFile.write('    object = m{0};\n'.format(strFunctions.cap(current['name'])))	
      outFile.write('  }\n\n')
  outFile.write('  connectToChild();\n\n')
  outFile.write('  return object;\n')  
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
  outFile.write('  {0}::connectToChild();\n\n'.format(baseClass))
  for i in range (0, len(attribs)):
    if attribs[i]['type'] == 'lo_element' or ( attribs[i]['type'] == 'element' and attribs[i]['name'] != 'math'):
      if attribs[i]['reqd'] == True or attribs[i]['type'] == 'lo_element':
        outFile.write('  m{0}.connectToParent(this);\n'.format(strFunctions.capp(attribs[i]['name'],attribs[i]['type'] == 'lo_element')))
      else:
        outFile.write('  if (m{0} != NULL)\n'.format(strFunctions.cap(attribs[i]['name'])))
        outFile.write('    m{0}->connectToParent(this);\n'.format(strFunctions.cap(attribs[i]['name'])))
  outFile.write('}\n\n\n')  

def writeReadAttributesCPPCode(outFile, element, attribs, baseClass):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Read values from the given XMLAttributes set into their specific fields.\n')
  outFile.write(' */\n')
  outFile.write('void\n{0}::readAttributes (const XMLAttributes& attributes,\n'.format(element))
  outFile.write('                             const ExpectedAttributes& expectedAttributes)\n')
  outFile.write('{\n')
  outFile.write('  {0}::readAttributes(attributes, expectedAttributes);\n\n'.format(baseClass))
  if (len(attribs) > 0):
    outFile.write('  bool assigned = false;\n\n')
  for i in range (0, len(attribs)):
    writeReadAttribute(outFile, attribs[i], element)
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)

def writeWriteAttributesHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * Write values of XMLAttributes to the output stream.\n')
  outFile.write('   */\n')
  outFile.write('  virtual void writeAttributes (XMLOutputStream& stream) const;\n\n\n')
  writeInternalEnd(outFile)
  
def writeWriteAttributesCPPCode(outFile, element, attribs, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('/*\n')
  outFile.write(' * Write values of XMLAttributes to the output stream.\n')
  outFile.write(' */\n')
  outFile.write('  void\n{0}::writeAttributes (XMLOutputStream& stream) const\n'.format(element))
  outFile.write('{\n')
  outFile.write('  {0}::writeAttributes(stream);\n\n'.format(baseClass))
  for i in range (0, len(attribs)):
    if attribs[i]['type'] != 'element' and attribs[i]['type'] != 'XMLNode*' and attribs[i]['type'] != 'DimensionDescription*' and attribs[i]['type'] != 'lo_element' and attribs[i]['type'] != 'std::vector<double>':
      outFile.write('  if (isSet{0}() == true)\n'.format(strFunctions.cap(attribs[i]['name'])))
      if attribs[i].has_key('attName'): 
        outFile.write('    stream.writeAttribute("{0}", getPrefix(), m{1});\n\n'.format(attribs[i]['attName'], strFunctions.cap(attribs[i]['name'])))	 
      else:
        outFile.write('    stream.writeAttribute("{0}", getPrefix(), m{1});\n\n'.format(attribs[i]['name'], strFunctions.cap(attribs[i]['name'])))	 
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)
  
def writeGetElementNameHeader(outFile, element, isSedListOf):
  if isSedListOf == True:
    element = writeListOf(element)
  outFile.write('  /**\n')
  outFile.write('   * Returns the XML element name of this object, which for {0}, is\n'.format(element))
  outFile.write('   * always @c "{0}".\n'.format(strFunctions.lowerFirst(element)))
  outFile.write('   *\n')
  outFile.write('   * @return the name of this element, i.e. @c "{0}".\n'.format(strFunctions.lowerFirst(element)))
  outFile.write('   */\n')
  outFile.write('  virtual const std::string& getElementName () const;\n\n\n')

def writeGetElementNameCPPCode(outFile, element, isSedListOf=False, dict=None):
  outFile.write('/*\n')
  outFile.write(' * Returns the XML element name of this object\n')
  outFile.write(' */\n')
  outFile.write('const std::string&\n{0}::getElementName () const\n'.format(element))
  outFile.write('{\n')
  if dict != None and dict.has_key('elementName'):
    if isSedListOf:
      if dict.has_key('lo_elementName'):        
        outFile.write('  static const string name = "{0}";\n'.format(dict['lo_elementName']))
      else:
        outFile.write('  static const string name = "listOf{0}";\n'.format(strFunctions.capp(dict['elementName'])))
    else:
      outFile.write('  static const string name = "{0}";\n'.format(dict['elementName']))
  else:
    if dict != None and dict.has_key('lo_elementName'):
      outFile.write('  static const string name = "{0}";\n'.format(dict['lo_elementName']))
    else: 
      outFile.write('  static const string name = "{0}";\n'.format(strFunctions.lowerFirst(element)))
  outFile.write('  return name;\n')
  outFile.write('}\n\n\n')
  

def writeHasReqdAttribHeader(outFile, element, attribs):
  outFile.write('  /**\n')
  outFile.write('   * Predicate returning @c true if all the required attributes\n')
  outFile.write('   * for this {0} object have been set.\n'.format(element))
  outFile.write('   *\n')
  outFile.write('   * @note The required attributes for a {0} object are:\n'.format(element))
  for i in range (0, len(attribs)):
    att = parseAttribute(attribs[i])
    if att[5] == True:
      outFile.write('   * @li "{0}"\n'.format(att[0]))
  outFile.write('   *\n')
  outFile.write('   * @return a boolean value indicating whether all the required\n')
  outFile.write('   * attributes for this object have been defined.\n')
  outFile.write('   */\n')
  outFile.write('  virtual bool hasRequiredAttributes() const;\n\n\n')

def writeHasReqdAttribCPPCode(outFile, element, attribs, baseClass):
  outFile.write('/*\n')
  outFile.write(' * check if all the required attributes are set\n')
  outFile.write(' */\n')
  outFile.write('bool\n{0}::hasRequiredAttributes () const\n'.format(element))
  outFile.write('{\n')
  if baseClass == 'SedBase':
    outFile.write('  bool allPresent = true;\n\n')
  else:
    outFile.write('  bool allPresent = {0}::hasRequiredAttributes();\n\n'.format(baseClass))
  for i in range(0, len(attribs)):
    if attribs[i]['reqd'] == True and attribs[i]['type'] != 'element':
      outFile.write('  if (isSet{0}() == false)\n'.format(strFunctions.cap(attribs[i]['name'])))
      outFile.write('    allPresent = false;\n\n')
  outFile.write('  return allPresent;\n')
  outFile.write('}\n\n\n')

def writeHasReqdElementsHeader(outFile, element, attribs):
  outFile.write('  /**\n')
  outFile.write('   * Predicate returning @c true if all the required elements\n')
  outFile.write('   * for this {0} object have been set.\n'.format(element))
  outFile.write('   *\n')
  outFile.write('   * @note The required elements for a {0} object are:\n'.format(element))
  for i in range (0, len(attribs)):
    att = parseAttribute(attribs[i])
    if (att[2] == 'element' or att[2] == 'lo_element') and att[5] == True:
      outFile.write('   * @li "{0}"\n'.format(att[0]))
  outFile.write('   *\n')
  outFile.write('   * @return a boolean value indicating whether all the required\n')
  outFile.write('   * elements for this object have been defined.\n')
  outFile.write('   */\n')
  outFile.write('  virtual bool hasRequiredElements() const;\n\n\n')

def writeHasReqdElementsCPPCode(outFile, element, attribs, baseClass):
  outFile.write('/*\n')
  outFile.write(' * check if all the required elements are set\n')
  outFile.write(' */\n')
  outFile.write('bool\n{0}::hasRequiredElements () const\n'.format(element))
  outFile.write('{\n')
  if baseClass == 'SedBase':
    outFile.write('  bool allPresent = true;\n\n')
  else:
    outFile.write('  bool allPresent = {0}::hasRequiredElements();\n\n'.format(baseClass))
  for i in range(0, len(attribs)):
    if attribs[i]['reqd'] == True and attribs[i]['type'] == 'element':
      outFile.write('  if (isSet{0}() == false)\n'.format(strFunctions.cap(attribs[i]['name'])))
      outFile.write('    allPresent = false;\n\n')
  outFile.write('  return allPresent;\n')
  outFile.write('}\n\n\n')

def writeReadOtherXMLHeader(outFile):
  writeInternalStart(outFile)
  outFile.write('  /**\n')
  outFile.write('   * Subclasses should override this method ro read other XML.\n')
  outFile.write('   *\n   * return true if read from stream, false otherwise.\n')
  outFile.write('   */\n')
  outFile.write('  virtual bool readOtherXML (XMLInputStream& stream);\n\n\n')
  writeInternalEnd(outFile)
  
def writeReadOtherXMLCPPCode(outFile, element, hasMath = True, attribs = None, baseClass='SedBase'):
  writeInternalStart(outFile)
  outFile.write('bool\n{0}::readOtherXML (XMLInputStream& stream)\n'.format(element))
  outFile.write('{\n')
  outFile.write('  bool          read = false;\n')
  outFile.write('  const string& name = stream.peek().getName();\n\n')
  if hasMath == True: 
    outFile.write('  if (name == "math")\n  {\n')
    outFile.write('    const XMLToken elem = stream.peek();\n')
    outFile.write('    const std::string prefix = checkMathMLNamespace(elem);\n\n')
    #outFile.write('    if (stream.getSedNamespaces() == NULL)\n    {\n')
    #outFile.write('      stream.setSedNamespaces(new SedNamespaces(getLevel(), getVersion()));\n    }\n\n')
    outFile.write('    delete mMath;\n')
    outFile.write('    mMath = readMathML(stream, prefix);\n')
    #outFile.write('    if (mMath != NULL)\n    {\n      mMath->setParentSEDMLObject(this);\n    }\n')
    outFile.write('    read = true;\n  }\n\n')
  elif containsType(attribs, 'XMLNode*'):
    node = getByType(attribs, 'XMLNode*')
    outFile.write('  if (name == "{0}")\n'.format(node['name']))
    outFile.write('  {\n')	
    outFile.write('    const XMLToken& token = stream.next();\n')	
    outFile.write('    stream.skipText();\n')	
    outFile.write('    m{0} = new XMLNode(stream);\n'.format(strFunctions.cap(node['name'])))	
    outFile.write('    stream.skipPastEnd(token);\n')	
    outFile.write('    read = true;\n  }\n\n')
  elif containsType(attribs, 'DimensionDescription*'):
    node = getByType(attribs, 'DimensionDescription*')
    outFile.write('  if (name == "{0}")\n'.format(node['name']))
    outFile.write('  {\n')	
    outFile.write('    const XMLToken& token = stream.next();\n')	
    outFile.write('    m{0} = new DimensionDescription();\n'.format(strFunctions.cap(node['name'])))	
    outFile.write('    m{0}->read(stream);\n'.format(strFunctions.cap(node['name'])))	
    outFile.write('    stream.skipPastEnd(token);\n')	
    outFile.write('    read = true;\n  }\n\n')
  elif containsType(attribs, 'std::vector<double>'):
    elem = getByType(attribs, 'std::vector<double>')
    outFile.write('  while (stream.peek().getName() == "{0}")\n'.format(elem['name']))
    outFile.write('  {\n')
    outFile.write('    stream.next(); // consume start\n')
    outFile.write('    stringstream text;\n')
    outFile.write('    while(stream.isGood() && stream.peek().isText())\n')
    outFile.write('      text << stream.next().getCharacters();\n')
    outFile.write('    double value; text >> value;\n')
    outFile.write('    if (!text.fail())\n')
    outFile.write('      m{0}.push_back(value);\n'.format(strFunctions.capp(elem['name'])))
    outFile.write('    stream.next(); // consume end\n')
    outFile.write('    read = true;\n')
    outFile.write('  }\n')
  outFile.write('  if ({0}::readOtherXML(stream))\n'.format(baseClass))
  outFile.write('  {\n    read = true;\n  }\n')
  outFile.write('  return read;\n')
  outFile.write('}\n\n\n')
  writeInternalEnd(outFile)
  



def writeProtectedHeaders(outFile, attribs = None, hasChildren=False, hasMath=False, baseClass='SedBase'):
  if hasChildren or baseClass != 'SedBase':
    writeCreateObjectHeader(outFile)
  writeAddExpectedHeader(outFile)
  writeReadAttributesHeader(outFile)
  if hasMath == True or containsType(attribs, 'std::vector<double>') or containsType(attribs, 'XMLNode*') or containsType(attribs, 'DimensionDescription*'): 
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

def writeInternalCPPCode(outFile, element, attributes, unused_arg, hasChildren, hasMath,baseClass='SedBase'):
  writeWriteElementsCPPCode(outFile, element, attributes, hasChildren, hasMath, baseClass)
  writeAcceptCPPCode(outFile, element)
  writeSetDocCPPCode(outFile, element, attributes,baseClass)

def writeProtectedCPPCode(outFile, element, attribs, unused_arg, hasChildren, hasMath, baseClass):
  writeAddExpectedCPPCode(outFile, element, attribs, baseClass)
  writeReadAttributesCPPCode(outFile, element, attribs, baseClass)
  if hasMath == True or containsType(attribs, 'std::vector<double>') or containsType(attribs, 'XMLNode*') or containsType(attribs, 'DimensionDescription*'):
    writeReadOtherXMLCPPCode(outFile, element, hasMath, attribs, baseClass)
  writeWriteAttributesCPPCode(outFile, element, attribs, baseClass)
