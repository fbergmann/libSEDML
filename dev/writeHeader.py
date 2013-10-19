#!/usr/bin/env python
#
# @file   writeHeader.py
# @brief  Create the header file for an object
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions
import writeListOfHeader
import createNewElementDictObj
import writeCHeader

def writeConstructors(element, package, output):
  indent = strFunctions.getIndent(element)
  output.write('\t/**\n\t * ' )
  output.write('Creates a new {0}'.format(element))
  output.write(' with the given level, version, and package version.\n')
  output.write('\t *\n')
  output.write('\t * @param level an unsigned int, the SEDML Level to assign')
  output.write(' to this {0}\n'.format(element))
  output.write('\t *\n')
  output.write('\t * @param version an unsigned int, the SEDML Version to assign')
  output.write(' to this {0}\n'.format(element))
  output.write('\t *\n')
  output.write('\t * @param pkgVersion an unsigned int, the SEDML {0} Version to assign'.format(package))
  output.write(' to this {0}\n\t */\n'.format(element))
  output.write('\t{0}(unsigned int level      = '.format(element))
  output.write('SEDML_DEFAULT_LEVEL,\n')
  output.write('\t{0}unsigned int version    = '.format(indent))
  output.write('SEDML_DEFAULT_VERSION);\n\n\n')
  output.write('\t/**\n\t * ' )
  output.write('Creates a new {0}'.format(element))
  output.write(' with the given SedNamespaces object.\n')
  output.write('\t *\n')
  output.write('\t * @param {0}ns the SedNamespaces object'.format(package.lower()))
  output.write('\n\t */\n')
  output.write('\t{0}(SedNamespaces* {1}ns);\n\n\n '.format(element,package.lower()))
  output.write('\t/**\n\t * ' )
  output.write('Copy constructor for {0}.\n'.format(element))
  output.write('\t *\n')
  output.write('\t * @param orig; the {0} instance to copy.\n'.format(element))
  output.write('\t */\n')
  output.write('\t{0}(const {1}& orig);\n\n\n '.format(element, element))
  output.write('\t/**\n\t * ' )
  output.write('Assignment operator for {0}.\n'.format(element))
  output.write('\t *\n')
  output.write('\t * @param rhs; the object whose values are used as the basis\n')
  output.write('\t * of the assignment\n\t */\n')
  output.write('\t{0}& operator=(const {1}& rhs);\n\n\n '.format(element, element))
  output.write('\t/**\n\t * ' )
  output.write('Creates and returns a deep copy of this {0} object.\n'.format(element))
  output.write('\t *\n\t * @return a (deep) copy of this {0} object.\n\t */\n'.format(element))
  output.write('\tvirtual {0}* clone () const;\n\n\n '.format(element))
  output.write('\t/**\n\t * ' )
  output.write('Destructor for {0}.\n\t */\n'.format(element))
  output.write('\tvirtual ~{0}();\n\n\n '.format(element))
  return

def writeInclude(attrib, output):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attType == 'lo_element':
    output.write('#include <sedml/{0}.h>\n'.format(attrib['element']))
  elif attType == 'std::vector<double>':
    output.write('#include <vector>')

def writeAtt(attrib, output):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attType == 'string':
    output.write('\tstd::string   m{0};\n'.format(capAttName))
  elif attType == 'element':    
    if attTypeCode == 'ASTNode*' or attName== 'Math':
      output.write('\tASTNode*      m{0};\n'.format(capAttName))
    else:
      output.write('\t{0}*      m{1};\n'.format(attrib['element'], capAttName))
      return
  elif attType == 'lo_element':
    output.write('\t{0}   m{1};\n'.format(generalFunctions.writeListOf(capAttName), strFunctions.capp(attName)))
  elif attTypeCode == 'XMLNode*':
    output.write('\t{0}   m{1};\n'.format('XMLNode*', capAttName))
  elif num == True:
    while len(attTypeCode) < 13:
      attTypeCode = attTypeCode + ' '
    output.write('\t{1} m{0};\n'.format(capAttName, attTypeCode))
    output.write('\tbool          mIsSet{0};\n'.format(capAttName))
  elif attType == 'boolean':
    output.write('\tbool          m{0};\n'.format(capAttName))
    output.write('\tbool          mIsSet{0};\n'.format(capAttName))
  elif attType == 'std::vector<double>':
    output.write('\tstd::vector<double>  m{0};\n'.format( strFunctions.capp(attName)))    
  else:
    output.write('\tFIX ME   {0};\n'.format(attName))

def writeAdditionalIncludes (attrs, output, elementDict):
  if elementDict.has_key('baseClass'):
    output.write('#include <sedml/{0}.h>\n'.format(elementDict['baseClass']))
  for i in range(0, len(attrs)):
    writeInclude(attrs[i], output)  
  output.write('\n\n')

def writeAttributes(attrs, output):
  output.write('protected:\n\n')
  for i in range(0, len(attrs)):
    writeAtt(attrs[i], output)  
  output.write('\n\n')

def writeGetFunction(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'lo_element':
    return
  elif attrib['type'] == 'element':
    if attrib['name'] == 'Math' or attrib['name'] == 'math':
      output.write('\t/**\n')
      output.write('\t * Returns the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('\t *\n')
      output.write('\t * @return the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('\t */\n')
      output.write('\tvirtual const ASTNode*')
      output.write(' get{0}() const;\n\n\n'.format(capAttName))
    else:
      output.write('\t/**\n')
      output.write('\t * Returns the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('\t *\n')
      output.write('\t * @return the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('\t */\n')
      output.write('\tvirtual const {0}*'.format(attrib['element']))
      output.write(' get{0}() const;\n\n\n'.format(capAttName))
      output.write('\t/**\n')
      output.write('\t * Creates a new \"{0}\"'.format(attrib['element']))
      output.write(' and sets it for this {0}.\n'.format(element))
      output.write('\t *\n')
      output.write('\t * @return the created \"{0}\"'.format(attrib['element']))
      output.write(' element of this {0}.\n'.format(element))
      output.write('\t */\n')
      output.write('\tvirtual {0}*'.format(attrib['element']))
      output.write(' create{0}();\n\n\n'.format(capAttName))
  elif attrib['type'] == 'std::vector<double>':
    output.write('\t/**\n')
    output.write('\t * Returns the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @return the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0} as a {1}.\n'.format(element, attType))
    output.write('\t */\n')
    output.write('\tvirtual const {0}&'.format(attTypeCode))
    output.write(' get{0}() const;\n\n\n'.format(strFunctions.capp(attName)))
    output.write('\t/**\n')
    output.write('\t * Returns the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @return the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0} as a {1}.\n'.format(element, attType))
    output.write('\t */\n')
    output.write('\tvirtual {0}&'.format(attTypeCode))
    output.write(' get{0}();\n\n\n'.format(strFunctions.capp(attName)))
  else:
    output.write('\t/**\n')
    output.write('\t * Returns the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @return the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0} as a {1}.\n'.format(element, attType))
    output.write('\t */\n')
    output.write('\tvirtual const {0}'.format(attTypeCode))
    output.write(' get{0}() const;\n\n\n'.format(capAttName))
     
def writeIsSetFunction(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'lo_element':
    return
  elif attrib['type'] == 'std::vector<double>':
    output.write('\t/**\n')
    output.write('\t * Predicate returning @c true or @c false depending on ')
    output.write('whether this\n\t * {0}\'s \"{1}\" '.format(element, attName))
    output.write('element has elements set.\n\t *\n')
    output.write('\t * @return @c true if this {0}\'s \"{1}\"'.format(element, attName))
    output.write(' element has been set,\n')
    output.write('\t * otherwise @c false is returned.\n')
    output.write('\t */\n')
    output.write('\tvirtual bool has{0}() const;\n\n\n'.format(strFunctions.capp(capAttName)))  
    output.write('\t/**\n')
    output.write('\t * Returning the number of elements in this\n\t * {0}\'s \"{1}\" '.format(element, attName))
    output.write('.\n\t *\n')
    output.write('\t * @return number of elements in this {0}\'s \"{1}\"'.format(element, attName))
    output.write(' \n')
    output.write('\t */\n')
    output.write('\tvirtual unsigned int getNum{0}() const;\n\n\n'.format(strFunctions.capp(capAttName)))  
  elif attrib['type'] == 'element':
    output.write('\t/**\n')
    output.write('\t * Predicate returning @c true or @c false depending on ')
    output.write('whether this\n\t * {0}\'s \"{1}\" '.format(element, attName))
    output.write('element has been set.\n\t *\n')
    output.write('\t * @return @c true if this {0}\'s \"{1}\"'.format(element, attName))
    output.write(' element has been set,\n')
    output.write('\t * otherwise @c false is returned.\n')
    output.write('\t */\n')
    output.write('\tvirtual bool isSet{0}() const;\n\n\n'.format(capAttName))
  else:
    output.write('\t/**\n')
    output.write('\t * Predicate returning @c true or @c false depending on ')
    output.write('whether this\n\t * {0}\'s \"{1}\" '.format(element, attName))
    output.write('attribute has been set.\n\t *\n')
    output.write('\t * @return @c true if this {0}\'s \"{1}\"'.format(element, attName))
    output.write(' attribute has been set,\n')
    output.write('\t * otherwise @c false is returned.\n')
    output.write('\t */\n')
    output.write('\tvirtual bool isSet{0}() const;\n\n\n'.format(capAttName))
   
def writeSetFunction(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  if attType == 'string':
    attTypeCode = 'const std::string&' 
  else:
    attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'lo_element':
    return
  elif attrib['type'] == 'element':    
    output.write('\t/**\n')
    output.write('\t * Sets the \"{0}\"'.format(attName))
    output.write(' element of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @param {0}; {1} determining the value of the "resultLevel" attribute to be set.\n'.format(attName, attTypeCode))
    output.write('\t *\n')
    output.write('\t * @return integer value indicating success/failure of the\n')
    output.write('\t * function.  @if clike The value is drawn from the\n')
    output.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('\t * returned by this function are:\n')
    output.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write('\t * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
    output.write('\t */\n')
    output.write('\tvirtual int set{0}('.format(capAttName))
    output.write('{0} {1});\n\n\n'.format(attTypeCode, attName))    
  elif attrib['type'] == 'std::vector<double>':
    output.write('\t/**\n')
    output.write('\t * Sets the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @param {0}; {1} value of the "{0}" attribute to be set\n'.format(attName, attTypeCode))
    output.write('\t *\n')
    output.write('\t * @return integer value indicating success/failure of the\n')
    output.write('\t * function.  @if clike The value is drawn from the\n')
    output.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('\t * returned by this function are:\n')
    output.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write('\t * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
    output.write('\t */\n')
    output.write('\tvirtual int set{0}('.format(strFunctions.capp(capAttName)))
    output.write('const {0}& {1});\n\n\n'.format(attTypeCode, attName))
    output.write('\t/**\n')
    output.write('\t * Adds another value to the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @param {0}; {1} value of the "{0}" attribute to be added \n'.format(attName, 'double'))
    output.write('\t *\n')
    output.write('\t * @return integer value indicating success/failure of the\n')
    output.write('\t * function.  @if clike The value is drawn from the\n')
    output.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('\t * returned by this function are:\n')
    output.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write('\t * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
    output.write('\t */\n')
    output.write('\tvirtual int add{0}('.format(capAttName))
    output.write('{0} {1});\n\n\n'.format('double', attName))
  else:
    output.write('\t/**\n')
    output.write('\t * Sets the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @param {0}; {1} value of the "{0}" attribute to be set\n'.format(attName, attTypeCode))
    output.write('\t *\n')
    output.write('\t * @return integer value indicating success/failure of the\n')
    output.write('\t * function.  @if clike The value is drawn from the\n')
    output.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('\t * returned by this function are:\n')
    output.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write('\t * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
    output.write('\t */\n')
    output.write('\tvirtual int set{0}('.format(capAttName))
    output.write('{0} {1});\n\n\n'.format(attTypeCode, attName))
     
  
def writeUnsetFunction(attrib, output, element):
  attName = attrib['name']
  capAttName = strFunctions.cap(attName)
  if attrib['type'] == 'lo_element':
    return
  elif attrib['type'] == 'std::vector<double>':
    output.write('\t/**\n')
    output.write('\t * Clears the \"{0}\"'.format(attName))
    output.write(' element of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @return integer value indicating success/failure of the\n')
    output.write('\t * function.  @if clike The value is drawn from the\n')
    output.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('\t * returned by this function are:\n')
    output.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write('\t * @li LIBSEDML_OPERATION_FAILED\n')
    output.write('\t */\n')
    output.write('\tvirtual int clear{0}();\n\n\n'.format(strFunctions.capp(capAttName)))
  elif attrib['type'] == 'element':
    output.write('\t/**\n')
    output.write('\t * Unsets the \"{0}\"'.format(attName))
    output.write(' element of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @return integer value indicating success/failure of the\n')
    output.write('\t * function.  @if clike The value is drawn from the\n')
    output.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('\t * returned by this function are:\n')
    output.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write('\t * @li LIBSEDML_OPERATION_FAILED\n')
    output.write('\t */\n')
    output.write('\tvirtual int unset{0}();\n\n\n'.format(capAttName))
  else:
    output.write('\t/**\n')
    output.write('\t * Unsets the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('\t *\n')
    output.write('\t * @return integer value indicating success/failure of the\n')
    output.write('\t * function.  @if clike The value is drawn from the\n')
    output.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('\t * returned by this function are:\n')
    output.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
    output.write('\t * @li LIBSEDML_OPERATION_FAILED\n')
    output.write('\t */\n')
    output.write('\tvirtual int unset{0}();\n\n\n'.format(capAttName))
   
  
   
def writeAttributeFunctions(attrs, output, element, elementDict):
  for i in range(0, len(attrs)):
    writeGetFunction(attrs[i], output, element)
    writeIsSetFunction(attrs[i], output, element)
    writeSetFunction(attrs[i], output, element)
    writeUnsetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] == 'lo_element':
      writeListOfSubFunctions(attrs[i], output, element, elementDict)
      

def writeListOfSubFunctions(attrib, output, element, elementDict):
  loname = generalFunctions.writeListOf(strFunctions.cap(attrib['name']))
  output.write('\t/**\n')
  output.write('\t * Returns the  \"{0}\"'.format(loname))
  output.write(' in this {0} object.\n'.format(element))
  output.write('\t *\n')
  output.write('\t * @return the \"{0}\"'.format(loname))
  output.write(' attribute of this {0}.\n'.format(element))
  output.write('\t */\n')
  output.write('\tconst {0}*'.format(loname))
  output.write(' getListOf{0}s() const;\n\n\n'.format(strFunctions.cap(attrib['name'])))
  writeListOfHeader.writeGetFunctions(output, strFunctions.cap(attrib['name']), attrib['element'], True, element)
  output.write('\t/**\n')
  output.write('\t * Adds a copy the given \"{0}\" to this {1}.\n'.format(attrib['element'], element))
  output.write('\t *\n')
  output.write('\t * @param {0}; the {1} object to add\n'.format(strFunctions.objAbbrev(attrib['element']), attrib['element']))
  output.write('\t *\n')
  output.write('\t * @return integer value indicating success/failure of the\n')
  output.write('\t * function.  @if clike The value is drawn from the\n')
  output.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
  output.write('\t * returned by this function are:\n')
  output.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
  output.write('\t * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
  output.write('\t */\n')
  output.write('\tint add{0}(const {1}* {2});\n\n\n'.format(strFunctions.cap(attrib['name']), attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  output.write('\t/**\n')
  output.write('\t * Get the number of {0} objects in this {1}.\n'.format(attrib['element'], element))
  output.write('\t *\n')
  output.write('\t * @return the number of {0} objects in this {1}\n'.format(attrib['element'], element))
  output.write('\t */\n')
  output.write('\tunsigned int getNum{0}s() const;\n\n\n'.format(strFunctions.cap(attrib['name'])))
  if attrib.has_key('abstract') == False or (attrib.has_key('abstract') and attrib['abstract'] == False):
    output.write('\t/**\n')
    output.write('\t * Creates a new {0} object, adds it to this {1}s\n'.format(attrib['element'], element))
    output.write('\t * {0} and returns the {1} object created. \n'.format(loname, attrib['element']))
    output.write('\t *\n')
    output.write('\t * @return a new {0} object instance\n'.format(attrib['element']))
    output.write('\t *\n')
    output.write('\t * @see add{0}(const {1}* {2})\n'.format(strFunctions.cap(attrib['name']), attrib['element'], strFunctions.objAbbrev(attrib['element'])))
    output.write('\t */\n')
    output.write('\t{0}* create{1}();\n\n\n'.format(attrib['element'], strFunctions.cap(attrib['name'])))
  elif attrib.has_key('concrete'):
    for elem in attrib['concrete']:
      output.write('\t/**\n')
      output.write('\t * Creates a new {0} object, adds it to this {1}s\n'.format(elem['element'], element))
      output.write('\t * {0} and returns the {1} object created. \n'.format(loname, elem['element']))
      output.write('\t *\n')
      output.write('\t * @return a new {0} object instance\n'.format(elem['element']))
      output.write('\t *\n')
      output.write('\t * @see add{0}(const {0}* {1})\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
      output.write('\t */\n')
      output.write('\t{0}* create{1}();\n\n\n'.format(elem['element'], strFunctions.cap(elem['name'])))
  writeListOfHeader.writeRemoveFunctions(output, strFunctions.cap(attrib['name']), attrib['element'], True, element)
 
#write class
def writeClass(attributes, header, nameOfElement, nameOfPackage, hasChildren, hasMath, isSedListOf, elementDict):
  writeAdditionalIncludes(attributes, header, elementDict)
  header.write('class LIBSEDML_EXTERN {0} :'.format(nameOfElement))
  baseClass = 'SedBase'
  if elementDict.has_key('baseClass'):
    baseClass = elementDict['baseClass']
  header.write(' public {0}\n{1}\n\n'.format(baseClass, '{'))
  writeAttributes(attributes, header)
  header.write('public:\n\n')
  writeConstructors(nameOfElement, nameOfPackage, header)
  writeAttributeFunctions(attributes, header, nameOfElement, elementDict)
  generalFunctions.writeCommonHeaders(header, nameOfElement, attributes, False, hasChildren, hasMath)
  generalFunctions.writeInternalHeaders(header, isSedListOf, hasChildren)
  header.write('protected:\n\n')
  generalFunctions.writeProtectedHeaders(header, attributes, hasChildren, hasMath, baseClass)
  if elementDict.has_key('additionalCPPDecls'):
    header.write(open(elementDict['additionalCPPDecls'], 'r').read())
  header.write('\n};\n\n')
 
# write the include files
def writeIncludes(fileOut, element, pkg):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/common/extern.h>\n')
  fileOut.write('#include <sedml/common/sedmlfwd.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <string>\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/SedBase.h>\n')
  fileOut.write('#include <sedml/SedListOf.h>\n')
  fileOut.write('#include <sedml/SedNamespaces.h>\n')
  fileOut.write('\n\n');
  fileOut.write('LIBSEDML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');
  
def writeCPPEnd(fileOut):
  fileOut.write('\n\nLIBSEDML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#endif  /*  __cplusplus  */\n\n')
  
def writeCStart(fileOut):
  fileOut.write('#ifndef SWIG\n\n')
  fileOut.write('LIBSEDML_CPP_NAMESPACE_BEGIN\nBEGIN_C_DECLS\n\n')
  

def writeCEnd(fileOut, element):
  fileOut.write('\n\nEND_C_DECLS\n')
  fileOut.write('LIBSEDML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#endif  /*  !SWIG  */\n\n')
  fileOut.write('#endif /*  {0}_H__  */\n\n'.format(element))
 
  
 
 
# write the header file      
def createHeader(element):
  nameOfElement = element['name']
  nameOfPackage = element['package']
  sedmltypecode = element['typecode']
  hasSedListOf = element['hasSedListOf']
  attributes = element['attribs']
  hasChildren = element['hasChildren']
  hasMath = element['hasMath']
  headerName = nameOfElement + '.h'
  header = open(headerName, 'w')
  fileHeaders.addFilename(header, headerName, nameOfElement)
  fileHeaders.addLicence(header)
  writeIncludes(header, nameOfElement, nameOfPackage)
  writeClass(attributes, header, nameOfElement, nameOfPackage, hasChildren, hasMath, False, element)
  if hasSedListOf == True:
    writeListOfHeader.createHeader(element, header)
  writeCPPEnd(header)
  writeCStart(header)
  writeCHeader.createHeader(element, header)
  writeCEnd(header, nameOfElement)

#if len(sys.argv) != 2:
#  print 'Usage: writeHeader.py element'
#else:
#  element = createNewElementDictObj.createFBCObj()
#  createHeader(element)
  

  