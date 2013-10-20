#!/usr/bin/env python
#
# @file   writeCode.py
# @brief  Create the cpp file for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions
import createNewElementDictObj
import writeListOfCode
import writeCCode


def writeIncludes(fileOut, element, pkg, hasMath=False):
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/{0}.h>\n'.format(element))
  fileOut.write('#include <sedml/SedTypes.h>\n')
  fileOut.write('#include <sbml/xml/XMLInputStream.h>\n')
  if hasMath == True:
    fileOut.write('#include <sbml/math/MathML.h>\n')
    fileOut.write('#include <sbml/math/ASTNode.h>\n')
  fileOut.write('\n\n');
#  fileOut.write('#if WIN32 && !defined(CYGWIN)\n')
#  fileOut.write('\t#define isnan _isnan\n')
#  fileOut.write('#endif\n')
#  fileOut.write('\n\n');
  fileOut.write('using namespace std;\n')
  fileOut.write('\n\n');
  fileOut.write('LIBSEDML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

# writes list of attributes
def writeAttributes(attrs, output, constType=0, pkg=""):
  for i in range(0, len(attrs)):
    writeAtt(attrs[i]['type'], attrs[i]['name'], output, constType, pkg)
  output.write('\n')

def writeAtt(atttype, name, output, constType, pkg):
  if atttype == 'SId' or atttype == 'SIdRef' or atttype == 'UnitSId' or atttype == 'UnitSIdRef' or atttype == 'string':
    output.write('\t, m{0} ("")\n'.format(strFunctions.cap(name)))
  elif atttype == 'element' or atttype == 'XMLNode*':
    output.write('\t, m{0} (NULL)\n'.format(strFunctions.cap(name)))
  elif atttype == 'lo_element':
    output.write('\t, m{0} ('.format(strFunctions.capp(name)))
    if constType == 0:
      output.write(')\n')
    elif constType == 1:
      output.write('level, version)\n')
    elif constType == 2:
      output.write('{0}ns)\n'.format(pkg))
  elif atttype == 'double':
    output.write('\t, m{0} (numeric_limits<double>::quiet_NaN())\n'.format(strFunctions.cap(name)))
    output.write('\t, mIsSet{0} (false)\n'.format(strFunctions.cap(name)))
  elif atttype == 'int' or atttype == 'uint':
    output.write('\t, m{0} (SEDML_INT_MAX)\n'.format(strFunctions.cap(name)))
    output.write('\t, mIsSet{0} (false)\n'.format(strFunctions.cap(name)))
  elif atttype == 'bool':
    output.write('\t, m{0} (false)\n'.format(strFunctions.cap(name)))
    output.write('\t, mIsSet{0} (false)\n'.format(strFunctions.cap(name)))
  elif atttype == 'std::vector<double>':
    output.write('\t, m{0} ()\n'.format(strFunctions.capp(name)))
  else:
    output.write('\tFIX ME   {0};\n'.format(name))


def writeCopyAttributes(attrs, output, tabs, name):
  for i in range(0, len(attrs)):
    attName = strFunctions.cap(attrs[i]['name'])
    atttype = attrs[i]['type']
    if atttype == 'element' and attName == 'Math':
      output.write('{0}m{1}  = {2}.m{1} != NULL ? {2}.m{1}->deepCopy() : NULL;\n'.format(tabs, strFunctions.cap(attrs[i]['name']), name))
    elif atttype == 'XMLNode*':
      output.write('{0}m{1}  = {2}.m{1} != NULL ? {2}.m{1}->clone() : NULL;\n'.format(tabs, strFunctions.cap(attrs[i]['name']), name))
    else:
      output.write('{0}m{1}  = {2}.m{1};\n'.format(tabs, strFunctions.capp(attrs[i]['name'], atttype == 'lo_element' or atttype == 'std::vector<double>'), name))
    if atttype == 'double' or atttype == 'int' or atttype == 'uint' or atttype == 'bool':
      output.write('{0}mIsSet{1}  = {2}.mIsSet{1};\n'.format(tabs, strFunctions.cap(attrs[i]['name']), name))


def writeConstructors(element, package, output, attrs, hasChildren=False, hasMath=False, elementDict=None):
  baseClass = 'SedBase'
  if elementDict != None and elementDict.has_key('baseClass'):
    baseClass = elementDict['baseClass']
  output.write('/*\n' )
  output.write(' * Creates a new {0}'.format(element))
  output.write(' with the given level, version, and package version.\n */\n')
  output.write('{0}::{0} (unsigned int level, unsigned int version)\n'.format(element))
  output.write('\t: {0}(level, version)\n'.format(baseClass))
  writeAttributes(attrs, output, 1)
  output.write('{\n')
  if element == 'SedDocument':
    output.write('\tmLevel = level;\n');
    output.write('\tmIsSetLevel = true;\n');
    output.write('\tmVersion = version;\n');
    output.write('\tmIsSetVersion = true;\n\n');
    output.write('\tsetSedDocument(this);\n\n');
  output.write('\t// set an SedNamespaces derived object of this package\n')
  output.write('\tsetSedNamespacesAndOwn(new SedNamespaces(level, version));\n'.format(package))
  if hasChildren == True or hasMath == True:
    output.write('\n\t// connect to child objects\n')
    output.write('\tconnectToChild();\n')
  output.write('}\n\n\n')
  output.write('/*\n' )
  output.write(' * Creates a new {0}'.format(element))
  output.write(' with the given SedNamespaces object.\n */\n')
  output.write('{0}::{0} (SedNamespaces* {1}ns)\n'.format(element, package.lower()))
  output.write('\t: {1}({0}ns)\n'.format(package.lower(), baseClass))
  writeAttributes(attrs, output, 2, package.lower())
  output.write('{\n')
  if element == 'SedDocument':
    output.write('\tmLevel = sedns->getLevel();\n');
    output.write('\tmIsSetLevel = true;\n');
    output.write('\tmVersion = sedns->getVersion();\n');
    output.write('\tmIsSetVersion = true;\n\n');
    output.write('\tsetSedDocument(this);\n\n');
  output.write('\t// set the element namespace of this object\n')
  output.write('\tsetElementNamespace({0}ns->getURI());\n'.format(package.lower()))
  if hasChildren == True:
    output.write('\n\t// connect to child objects\n')
    output.write('\tconnectToChild();\n')
  output.write('}\n\n\n')
  output.write('/*\n' )
  output.write(' * Copy constructor for {0}.\n */\n'.format(element))
  output.write('{0}::{0} (const {0}& orig)\n'.format(element, package, package.lower()))
  output.write('\t: {0}(orig)\n'.format(baseClass))
  output.write('{\n')
  output.write('\tif (&orig == NULL)\n')
  output.write('\t{\n')
  output.write('\t\tthrow SedConstructorException("Null argument to copy constructor");\n')
  output.write('\t}\n')
  output.write('\telse\n')
  output.write('\t{\n')
  if element == 'SedDocument':
    output.write('\t\tsetSedDocument(this);\n\n');
  writeCopyAttributes(attrs, output, '\t\t', 'orig')
  if hasChildren == True:
    output.write('\n\t\t// connect to child objects\n')
    output.write('\t\tconnectToChild();\n')
  output.write('\t}\n')
  output.write('}\n\n\n')
  output.write('/*\n' )
  output.write(' * Assignment for {0}.\n */\n'.format(element))
  output.write('{0}&\n{0}::operator=(const {0}& rhs)\n'.format(element))
  output.write('{\n')
  output.write('\tif (&rhs == NULL)\n')
  output.write('\t{\n')
  output.write('\t\tthrow SedConstructorException("Null argument to assignment");\n')
  output.write('\t}\n')
  output.write('\telse if (&rhs != this)\n')
  output.write('\t{\n')
  output.write('\t\t{0}::operator=(rhs);\n'.format(baseClass))
  if element == 'SedDocument':
    output.write('\n\t\tsetSedDocument(this);\n\n');
  writeCopyAttributes(attrs, output, '\t\t', 'rhs')
  if hasChildren == True:
    output.write('\n\t\t// connect to child objects\n')
    output.write('\t\tconnectToChild();\n')
  output.write('\t}\n')
  output.write('\treturn *this;\n')
  output.write('}\n\n\n')
  output.write('/*\n' )
  output.write(' * Clone for {0}.\n */\n'.format(element))
  output.write('{0}*\n{0}::clone () const\n'.format(element))
  output.write('{\n')
  output.write('\treturn new {0}(*this);\n'.format(element))
  output.write('}\n\n\n')
  output.write('/*\n' )
  output.write(' * Destructor for {0}.\n */\n'.format(element))
  output.write('{0}::~{0} ()\n'.format(element))
  output.write('{\n')
  output.write('}\n\n\n')



def writeGetCode(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  if attType == 'lo_element':
    return
  if attType == 'std::vector<double>': 
    output.write('/*\n')
    output.write(' * Returns the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write(' */\n')
    output.write('const {0}&\n'.format(attTypeCode))
    output.write('{0}::get{1}() const\n'.format(element, strFunctions.capp(capAttName)))
    output.write('{\n')
    output.write('\treturn m{0};\n'.format(strFunctions.capp(capAttName)))
    output.write('}\n\n\n')
    output.write('/*\n')
    output.write(' * Returns the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write(' */\n')
    output.write('{0}&\n'.format(attTypeCode))
    output.write('{0}::get{1}()\n'.format(element, strFunctions.capp(capAttName)))
    output.write('{\n')
    output.write('\treturn m{0};\n'.format(strFunctions.capp(capAttName)))
    output.write('}\n\n\n')
  else: 
    output.write('/*\n')
    output.write(' * Returns the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write(' */\n')
    output.write('const {0}\n'.format(attTypeCode))
    output.write('{0}::get{1}() const\n'.format(element, capAttName))
    output.write('{\n')
    output.write('\treturn m{0};\n'.format(capAttName))
    output.write('}\n\n\n')
  if attType == 'element' and attName != 'math':
    output.write('/*\n')
    output.write(' * Creates a new \"{0}\"'.format(attName))
    output.write(' element of this {0} and returns it.\n'.format(element))
    output.write(' */\n')
    output.write('{0}\n'.format(attTypeCode))
    output.write('{0}::create{1}()\n'.format(element, capAttName))
    output.write('{\n')
    output.write('\tm{0} = new {1}();\n'.format(capAttName, attrib['element']))
    output.write('\treturn m{0};\n'.format(capAttName))
    output.write('}\n\n\n')


def writeIsSetCode(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attType == 'lo_element':
    return
  elif attrib['type'] == 'std::vector<double>':
    output.write('/**\n')
    output.write(' * Predicate returning @c true or @c false depending on ')
    output.write('whether this\n * {0}\'s \"{1}\" '.format(element, attName))
    output.write('element has elements set.\n *\n')
    output.write(' * @return @c true if this {0}\'s \"{1}\"'.format(element, attName))
    output.write(' element has been set,\n')
    output.write(' * otherwise @c false is returned.\n')
    output.write(' */\n')
    output.write('bool\n{0}::has{1}() const\n'.format(element, strFunctions.capp(capAttName)))  
    output.write('{\n')
    output.write('\treturn m{0}.size() > 0;\n'.format(strFunctions.capp(capAttName)))
    output.write('}\n\n\n')
    output.write('/**\n')
    output.write(' * Returning the number of elements in this\n * {0}\'s \"{1}\" '.format(element, attName))
    output.write('.\n *\n')
    output.write(' * @return number of elements in this {0}\'s \"{1}\"'.format(element, attName))
    output.write(' \n')
    output.write(' */\n')
    output.write('unsigned int\n{0}::getNum{1}() const\n'.format(element, strFunctions.capp(capAttName)))  
    output.write('{\n')
    output.write('\treturn (unsigned int)m{0}.size();\n'.format(strFunctions.capp(capAttName)))
    output.write('}\n\n\n')
  else:
    output.write('/*\n')
    output.write(' * Returns true/false if {0} is set.\n'.format(attName))
    output.write(' */\n')
    output.write('bool\n')
    output.write('{0}::isSet{1}() const\n'.format(element, capAttName))
    output.write('{\n')
    if attType == 'string':
      output.write('\treturn (m{0}.empty() == false);\n'.format(capAttName))
    elif attType == 'element' or attType == 'XMLNode*':
      output.write('\treturn (m{0} != NULL);\n'.format(capAttName))
    elif num == True:
      output.write('\treturn mIsSet{0};\n'.format(capAttName))
    elif attType == 'boolean':
      output.write('\treturn mIsSet{0};\n'.format(capAttName))
    output.write('}\n\n\n')



def writeSetCode(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  if attType == 'string':
    attTypeCode = 'const std::string&'
  else:
    attTypeCode = att[3]
  num = att[4]
  if attType == 'lo_element':
    return
  elif attrib['type'] == 'std::vector<double>':
    output.write('/**\n')
    output.write(' * Sets the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write(' *\n')
    output.write(' * @param {0}; {1} value of the "{0}" attribute to be set\n'.format(attName, attTypeCode))
    output.write(' *\n')
    output.write(' * @return integer value indicating success/failure of the\n')
    output.write(' * function.  @if clike The value is drawn from the\n')
    output.write(' * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write(' * returned by this function are:\n')
    output.write(' * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write(' * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
    output.write(' */\n')
    output.write('int\n{0}::set{1}('.format(element, strFunctions.capp(capAttName)))
    output.write('const {0}& {1})\n'.format(attTypeCode, attName))
    output.write('{\n')
    output.write('\tm{0} = {1};\n'.format( strFunctions.capp(capAttName), attName))
    output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
    output.write('}\n\n\n')
    output.write('/**\n')
    output.write(' * Adds another value to the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write(' *\n')
    output.write(' * @param {0}; {1} value of the "{0}" attribute to be added \n'.format(attName, 'double'))
    output.write(' *\n')
    output.write(' * @return integer value indicating success/failure of the\n')
    output.write(' * function.  @if clike The value is drawn from the\n')
    output.write(' * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write(' * returned by this function are:\n')
    output.write(' * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write(' * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
    output.write(' */\n')
    output.write('int\n{0}::add{1}('.format(element, capAttName))
    output.write('{0} {1})\n'.format('double', attName))
    output.write('{\n')
    output.write('\tm{0}.push_back({1});\n'.format( strFunctions.capp(capAttName), attName))
    output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
    output.write('}\n\n\n')
  else:
    output.write('/*\n')
    output.write(' * Sets {0} and returns value indicating success.\n'.format(attName))
    output.write(' */\n')
    output.write('int\n')
    output.write('{0}::set{1}({2} {3})\n'.format(element, capAttName, attTypeCode, attName))
    output.write('{\n')
    if attType == 'string':
      if attName == 'id':
        output.write('\treturn SyntaxChecker::checkAndSetSId({0}, m{1});\n'.format(attName, capAttName ))
      else:
        output.write('\tif (&({0}) == NULL)\n'.format(attName))
        output.write('\t{\n\t\treturn LIBSEDML_INVALID_ATTRIBUTE_VALUE;\n\t}\n')
        if attrib['type'] == 'SIdRef':
          output.write('\telse if (!(SyntaxChecker::isValidInternalSId({0})))\n'.format(attName))
          output.write('\t{\n\t\treturn LIBSEDML_INVALID_ATTRIBUTE_VALUE;\n\t}\n')
        output.write('\telse\n\t{\n')
        output.write('\t\tm{0} = {1};\n'.format(capAttName, attName))
        output.write('\t\treturn LIBSEDML_OPERATION_SUCCESS;\n\t}\n')
    elif num == True:
      output.write('\tm{0} = {1};\n'.format(capAttName, attName))
      output.write('\tmIsSet{0} = true;\n'.format(capAttName))
      output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
    elif attType == 'boolean':
      output.write('\tm{0} = {1};\n'.format(capAttName, attName))
      output.write('\tmIsSet{0} = true;\n'.format(capAttName))
      output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
    elif attType == 'XMLNode*':
      output.write('\tif (m{0} == {1})\n'.format(capAttName, attName))
      output.write('\t{\n\t\treturn LIBSEDML_OPERATION_SUCCESS;\n\t}\n')
      output.write('\telse if ({0} == NULL)\n'.format(attName))
      output.write('\t{\n')
      output.write('\t\tdelete m{0};\n'.format(capAttName))
      output.write('\t\tm{0} = NULL;\n'.format(capAttName))
      output.write('\t\treturn LIBSEDML_OPERATION_SUCCESS;\n\t}\n')
      output.write('\tdelete m{0};\n'.format(capAttName))
      output.write('\tm{0} = ({1} != NULL) ?\n'.format(capAttName, attName))
      output.write('\t\t{0}->clone() : NULL;\n'.format(attName))
      output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
    elif attType == 'element':
      output.write('\tif (m{0} == {1})\n'.format(capAttName, attName))
      output.write('\t{\n\t\treturn LIBSEDML_OPERATION_SUCCESS;\n\t}\n')
      output.write('\telse if ({0} == NULL)\n'.format(attName))
      output.write('\t{\n')
      output.write('\t\tdelete m{0};\n'.format(capAttName))
      output.write('\t\tm{0} = NULL;\n'.format(capAttName))
      output.write('\t\treturn LIBSEDML_OPERATION_SUCCESS;\n\t}\n')
      if attTypeCode == 'ASTNode*':
        output.write('\telse if (!({0}->isWellFormedASTNode()))\n'.format(attName))
        output.write('\t{\n\t\treturn LIBSEDML_INVALID_OBJECT;\n\t}\n')
      output.write('\telse\n\t{\n')
      output.write('\t\tdelete m{0};\n'.format(capAttName))
      output.write('\t\tm{0} = ({1} != NULL) ?\n'.format(capAttName, attName))
      if attTypeCode == 'ASTNode*':
        output.write('\t\t\t{0}->deepCopy() : NULL;\n'.format(attName))
      else:
        output.write('\t\t\tstatic_cast<{0}*>({1}->clone()) : NULL;\n'.format(attrib['element'], attName))
      output.write('\t\tif (m{0} != NULL)\n'.format(capAttName))
      output.write('\t\t{\n')
      #if attTypeCode == 'ASTNode*':
      #  output.write('\t\t\tm{0}->setParentSEDMLObject(this);\n'.format(capAttName, attName))
      #else:
      #  output.write('\t\t\tm{0}->connectToParent(this);\n'.format(capAttName, attName))
      if attTypeCode != 'ASTNode*':
        output.write('\t\t\tm{0}->connectToParent(this);\n'.format(capAttName, attName))
      output.write('\t\t}\n')
      output.write('\t\treturn LIBSEDML_OPERATION_SUCCESS;\n\t}\n')
    output.write('}\n\n\n')



def writeUnsetCode(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attType == 'lo_element':
    return
  elif attrib['type'] == 'std::vector<double>':
    output.write('/**\n')
    output.write(' * Clears the \"{0}\"'.format(attName))
    output.write(' element of this {0}.\n'.format(element))
    output.write(' *\n')
    output.write(' * @return integer value indicating success/failure of the\n')
    output.write(' * function.  @if clike The value is drawn from the\n')
    output.write(' * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write(' * returned by this function are:\n')
    output.write(' * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write(' * @li LIBSEDML_OPERATION_FAILED\n')
    output.write(' */\n')
    output.write('int\n{0}::clear{1}()\n'.format(element, strFunctions.capp(capAttName)))
    output.write('{\n')
    output.write('\tm{0}.clear();\n'.format(strFunctions.capp(capAttName)))
    output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
    output.write('}\n\n\n')
  else:    
    output.write('/*\n')
    output.write(' * Unsets {0} and returns value indicating success.\n'.format(attName))
    output.write(' */\n')
    output.write('int\n')
    output.write('{0}::unset{1}()\n'.format(element, capAttName))
    output.write('{\n')
    if attType == 'string':
      output.write('\tm{0}.erase();\n\n'.format(capAttName))
      output.write('\tif (m{0}.empty() == true)\n'.format(capAttName))
      output.write('\t{\n\t\treturn LIBSEDML_OPERATION_SUCCESS;\n\t}\n')
      output.write('\telse\n\t{\n')
      output.write('\t\treturn LIBSEDML_OPERATION_FAILED;\n\t}\n')
    elif num == True:
      if attType == 'double':
        output.write('\tm{0} = numeric_limits<double>::quiet_NaN();\n'.format(capAttName))
      else:
        output.write('\tm{0} = SEDML_INT_MAX;\n'.format(capAttName))
      output.write('\tmIsSet{0} = false;\n\n'.format(capAttName))
      output.write('\tif (isSet{0}() == false)\n'.format(capAttName))
      output.write('\t{\n\t\treturn LIBSEDML_OPERATION_SUCCESS;\n\t}\n')
      output.write('\telse\n\t{\n')
      output.write('\t\treturn LIBSEDML_OPERATION_FAILED;\n\t}\n')
    elif attType == 'boolean':
      output.write('\tm{0} = false;\n'.format(capAttName))
      output.write('\tmIsSet{0} = false;\n'.format(capAttName))
      output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
    elif attType == 'element' or attType == 'XMLNode*':
      output.write('\tdelete m{0};\n'.format(capAttName))
      output.write('\tm{0} = NULL;\n'.format(capAttName))
      output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
    output.write('}\n\n\n')

# for each attribute write a set/get/isset/unset
def writeAttributeCode(attrs, output, element):
  for i in range(0, len(attrs)):
	if attrs[i]['type'] != 'lo_element':
		writeGetCode(attrs[i], output, element)
  for i in range(0, len(attrs)):
	if attrs[i]['type'] != 'lo_element':
		writeIsSetCode(attrs[i], output, element)
  for i in range(0, len(attrs)):
	if attrs[i]['type'] != 'lo_element':
		writeSetCode(attrs[i], output, element)
  for i in range(0, len(attrs)):
	if attrs[i]['type'] != 'lo_element':
		writeUnsetCode(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] == 'lo_element':
      writeListOfSubFunctions(attrs[i], output, element)

def writeListOfSubFunctions(attrib, output, element):
  loname = generalFunctions.writeListOf(strFunctions.cap(attrib['name']))
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  output.write('/*\n')
  output.write(' * Returns the  \"{0}\"'.format(loname))
  output.write(' in this {0} object.\n'.format(element))
  output.write(' */\n')
  output.write('const {0}*\n'.format(loname))
  output.write('{0}::getListOf{1}s() const\n'.format(element, strFunctions.cap(attrib['name'])))
  output.write('{\n')
  output.write('\treturn &m{0};\n'.format(strFunctions.capp(attName)))
  output.write('}\n\n\n')
  writeListOfCode.writeRemoveFunctions(output, strFunctions.cap(attrib['name']), attrib['element'], True, element, capAttName)
  writeListOfCode.writeGetFunctions(output, strFunctions.cap(attrib['name']), attrib['element'], True, element, capAttName)
  output.write('/**\n')
  output.write(' * Adds a copy the given \"{0}\" to this {1}.\n'.format(attrib['element'], element))
  output.write(' *\n')
  output.write(' * @param {0}; the {1} object to add\n'.format(strFunctions.objAbbrev(attrib['element']), attrib['element']))
  output.write(' *\n')
  output.write(' * @return integer value indicating success/failure of the\n')
  output.write(' * function.  @if clike The value is drawn from the\n')
  output.write(' * enumeration #OperationReturnValues_t. @endif The possible values\n')
  output.write(' * returned by this function are:\n')
  output.write(' * @li LIBSEDML_OPERATION_SUCCESS\n')
  output.write(' * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
  output.write(' */\n')
  output.write('int\n')
  output.write('{0}::add{1}(const {2}* {3})\n'.format(element, strFunctions.cap(attrib['name']), attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  output.write('{\n')
  output.write('\tif({0} == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;\n'.format(strFunctions.objAbbrev(attrib['element'])))
  output.write('\tm{0}.append({1});\n'.format(strFunctions.capp(attrib['name']),strFunctions.objAbbrev(attrib['element'])))
  output.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
  output.write('}\n\n\n')
  output.write('/**\n')
  output.write(' * Get the number of {0} objects in this {1}.\n'.format(attrib['element'], element))
  output.write(' *\n')
  output.write(' * @return the number of {0} objects in this {1}\n'.format(attrib['element'], element))
  output.write(' */\n')
  output.write('unsigned int \n')
  output.write('{0}::getNum{1}s() const\n'.format(element, strFunctions.cap(attrib['name'])))
  output.write('{\n')
  output.write('\treturn m{0}.size();\n'.format(strFunctions.capp(attrib['name'])))
  output.write('}\n\n')
  if attrib.has_key('abstract') == False or (attrib.has_key('abstract') and attrib['abstract'] == False):
    output.write('/**\n')
    output.write(' * Creates a new {0} object, adds it to this {1}s\n'.format(attrib['element'], element))
    output.write(' * {0} and returns the {1} object created. \n'.format(element, attrib['element']))
    output.write(' *\n')
    output.write(' * @return a new {0} object instance\n'.format(attrib['element']))
    output.write(' *\n')
    output.write(' * @see add{0}(const {0}* {1})\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
    output.write(' */\n')
    output.write('{0}* \n'.format(attrib['element']))
    output.write('{0}::create{1}()\n'.format(element, strFunctions.cap(attrib['name'])))
    output.write('{\n')
    output.write('\t{0} *temp = new {0}();\n'.format(attrib['element']))
    output.write('\tif (temp != NULL) m{0}.appendAndOwn(temp);\n'.format(strFunctions.capp(attrib['name'])))
    output.write('\treturn temp;\n')
    output.write('}\n\n')
  elif attrib.has_key('concrete'):
    for elem in attrib['concrete']:
      output.write('/**\n')
      output.write(' * Creates a new {0} object, adds it to this {1}s\n'.format(elem['element'], element))
      output.write(' * {0} and returns the {1} object created. \n'.format(element, elem['element']))
      output.write(' *\n')
      output.write(' * @return a new {0} object instance\n'.format(elem['element']))
      output.write(' *\n')
      output.write(' * @see add{0}(const {1}* {2})\n'.format(strFunctions.cap(elem['name']), attrib['element'], strFunctions.objAbbrev(attrib['element'])))
      output.write(' */\n')
      output.write('{0}* \n'.format(elem['element']))
      output.write('{0}::create{1}()\n'.format(element, strFunctions.cap(elem['name'])))
      output.write('{\n')
      output.write('\t{0} *temp = new {0}();\n'.format(elem['element']))
      output.write('\tif (temp != NULL) m{0}.appendAndOwn(temp);\n'.format(strFunctions.capp(attrib['name'])))
      output.write('\treturn temp;\n')
      output.write('}\n\n')


def createCode(element):
  nameOfElement = element['name']
  nameOfPackage = element['package']
  sedmltypecode = element['typecode']
  hasSedListOf = element['hasSedListOf']
  attributes = element['attribs']
  hasChildren = element['hasChildren']
  hasMath = element['hasMath']
  baseClass = 'SedBase'
  if element != None and element.has_key('baseClass'):
    baseClass = element['baseClass']

  codeName = nameOfElement + '.cpp'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfElement)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfElement, nameOfPackage, hasMath)
  writeConstructors(nameOfElement, nameOfPackage, code, attributes, hasChildren, hasMath, element)
  writeAttributeCode(attributes, code, nameOfElement)
  generalFunctions.writeCommonCPPCode(code, nameOfElement, sedmltypecode, attributes, False, hasChildren, hasMath, element,baseClass)
  generalFunctions.writeInternalCPPCode(code, nameOfElement, attributes, False, hasChildren or hasSedListOf, hasMath,baseClass)
  generalFunctions.writeProtectedCPPCode(code, nameOfElement, attributes, False, hasChildren, hasMath,baseClass)
  if element.has_key('additionalCPPImpls'):
    code.write(open(element['additionalCPPImpls'], 'r').read())
  if hasSedListOf:
    writeListOfCode.createCode(element, code)
  writeCCode.createCode(element, code)

#if len(sys.argv) != 2:
#  print 'Usage: writeCode.py element'
#else:
#  element = createNewElementDictObj.createFBCObjective()
#  createCode(element)


