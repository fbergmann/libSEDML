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
  output.write('{0}Extension::getDefaultLevel(),\n'.format(package))
  output.write('\t{0}unsigned int version    = '.format(indent))
  output.write('{0}Extension::getDefaultVersion(),\n'.format(package))
  output.write('\t{0}unsigned int pkgVersion = '.format(indent))
  output.write('{0}Extension::getDefaultPackageVersion());\n\n\n'.format(package))
  output.write('\t/**\n\t * ' )
  output.write('Creates a new {0}'.format(element))
  output.write(' with the given {0}PkgNamespaces object.\n'.format(package))
  output.write('\t *\n')
  output.write('\t * @param {0}ns the {1}PkgNamespaces object'.format(package.lower(), package))
  output.write('\n\t */\n')
  output.write('\t{0}({1}PkgNamespaces* {2}ns);\n\n\n '.format(element, package, package.lower()))
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
    if attTypeCode == 'ASTNode*':
      output.write('\tASTNode*      m{0};\n'.format(capAttName))
    else:
      return
  elif attType == 'lo_element':
    output.write('\t{0}   m{1};\n'.format(generalFunctions.writeListOf(attTypeCode), capAttName))
  elif num == True:
    while len(attTypeCode) < 13:
      attTypeCode = attTypeCode + ' '
    output.write('\t{1} m{0};\n'.format(capAttName, attTypeCode))
    output.write('\tbool          mIsSet{0};\n'.format(capAttName))
  elif attType == 'boolean':
    output.write('\tbool          m{0};\n'.format(capAttName))
    output.write('\tbool          mIsSet{0};\n'.format(capAttName))
  else:
    output.write('\tFIX ME   {0};\n'.format(attName))
 
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
    if attrib['element'] == 'Math':
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
      return
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
  elif attrib['type'] == 'element':
    if attrib['element'] == 'Math':
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
      return
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
    if attrib['element'] == 'Math':
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
    else:
      return
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
  elif attrib['type'] == 'element':
    if attrib['element'] == 'Math':
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
      return
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
   
  
   
def writeAttributeFunctions(attrs, output, element):
  for i in range(0, len(attrs)):
    writeGetFunction(attrs[i], output, element)
#  for i in range(0, len(attrs)):
    writeIsSetFunction(attrs[i], output, element)
#  for i in range(0, len(attrs)):
    writeSetFunction(attrs[i], output, element)
#  for i in range(0, len(attrs)):
    writeUnsetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] == 'lo_element':
      writeListOfSubFunctions(attrs[i], output, element)
      

def writeListOfSubFunctions(attrib, output, element):
  loname = generalFunctions.writeListOf(attrib['element'])
  output.write('\t/**\n')
  output.write('\t * Returns the  \"{0}\"'.format(loname))
  output.write(' in this {0} object.\n'.format(element))
  output.write('\t *\n')
  output.write('\t * @return the \"{0}\"'.format(loname))
  output.write(' attribute of this {0}.\n'.format(element))
  output.write('\t */\n')
  output.write('\tconst {0}*'.format(loname))
  output.write(' get{0}() const;\n\n\n'.format(loname))
  writeListOfHeader.writeGetFunctions(output, attrib['element'], True, element)
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
  output.write('\tint add{0}(const {0}* {1});\n\n\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  output.write('\t/**\n')
  output.write('\t * Get the number of {0} objects in this {1}.\n'.format(attrib['element'], element))
  output.write('\t *\n')
  output.write('\t * @return the number of {0} objects in this {1}\n'.format(attrib['element'], element))
  output.write('\t */\n')
  output.write('\tunsigned int getNum{0}s() const;\n\n\n'.format(attrib['element']))
  output.write('\t/**\n')
  output.write('\t * Creates a new {0} object, adds it to this {1}s\n'.format(attrib['element'], element))
  output.write('\t * {0} and returns the {1} object created. \n'.format(loname, attrib['element']))
  output.write('\t *\n')
  output.write('\t * @return a new {0} object instance\n'.format(attrib['element']))
  output.write('\t *\n')
  output.write('\t * @see add{0}(const {0}* {1})\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  output.write('\t */\n')
  output.write('\t{0}* create{0}();\n\n\n'.format(attrib['element']))
  writeListOfHeader.writeRemoveFunctions(output, attrib['element'], True, element)
 
#write class
def writeClass(attributes, header, nameOfElement, nameOfPackage, hasChildren, hasMath):
  header.write('class LIBSEDML_EXTERN {0} :'.format(nameOfElement))
  header.write(' public SedBase\n{0}\n\n'.format('{'))
  writeAttributes(attributes, header)
  header.write('public:\n\n')
  writeConstructors(nameOfElement, nameOfPackage, header)
  writeAttributeFunctions(attributes, header, nameOfElement)
  generalFunctions.writeCommonHeaders(header, nameOfElement, attributes, False, hasChildren, hasMath)
  generalFunctions.writeInternalHeaders(header, hasChildren)
  header.write('protected:\n\n')
  generalFunctions.writeProtectedHeaders(header, hasChildren, hasMath)
  header.write('\n};\n\n')
 
# write the include files
def writeIncludes(fileOut, element, pkg):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/common/extern.h>\n')
  fileOut.write('#include <sedml/common/sedmlfwd.h>\n')
  fileOut.write('#include <sedml/packages/{0}/common/{0}fwd.h>\n'.format(pkg.lower()))
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <string>\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/SedBase.h>\n')
  fileOut.write('#include <sedml/ListOf.h>\n')
  fileOut.write('#include <sedml/packages/{0}/extension/{1}Extension.h>\n'.format(pkg.lower(), pkg))
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
  isListOf = element['hasListOf']
  attributes = element['attribs']
  hasChildren = element['hasChildren']
  hasMath = element['hasMath']
  headerName = nameOfElement + '.h'
  header = open(headerName, 'w')
  fileHeaders.addFilename(header, headerName, nameOfElement)
  fileHeaders.addLicence(header)
  writeIncludes(header, nameOfElement, nameOfPackage)
  writeClass(attributes, header, nameOfElement, nameOfPackage, hasChildren, hasMath)
  if isListOf == True:
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
  

  