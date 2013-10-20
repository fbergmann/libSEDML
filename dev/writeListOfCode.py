#!/usr/bin/env python
#
# @file   writeListOfCode.py
# @brief  Create the code for a list of class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions

def writeConstructors(element, type, package, output):
  element = generalFunctions.writeListOf(element)
  indent = strFunctions.getIndent(element)
  output.write('/*\n' )
  output.write(' * Constructor \n')
  output.write(' */\n')
  output.write('{0}::{0}(unsigned int level, \n'.format(element))
  output.write('\t{0}unsigned int version)\n'.format(indent))
  output.write(' : SedListOf(level, version)\n')
  output.write('{\n' )
  output.write('\tsetSedNamespacesAndOwn(new ')
  output.write('SedNamespaces(level, version)); \n')
  output.write('}\n\n\n')
  output.write('/*\n' )
  output.write(' * Constructor \n')
  output.write(' */\n')
  output.write('{0}::{0}(SedNamespaces* {1}ns)\n '.format(element, package.lower()))
  output.write(' : SedListOf({0}ns)\n'.format(package.lower()))
  output.write('{\n' )
  output.write('\tsetElementNamespace({0}ns->getURI());\n'.format(package.lower()))
  output.write('}\n\n\n')
  output.write('/*\n' )
  output.write(' * Returns a deep copy of this {0} \n'.format(element))
  output.write(' */\n')
  output.write('{0}* \n'.format(element))
  output.write('{0}::clone () const\n '.format(element))
  output.write('{\n' )
  output.write('\treturn new {0}(*this);\n'.format(element))
  output.write('}\n\n\n')
  
def writeGetFunctions(output, element, type, subelement=False, topelement="", name=""):
  listOf = generalFunctions.writeListOf(element)
  output.write('/*\n')
  if subelement == True:
    output.write(' * Return the nth {0} in the {1} within this {2}.\n'.format(element, listOf, topelement))
    output.write(' */\n')
    output.write('{0}*\n'.format(type))
    output.write('{0}::get{1}(unsigned int n)\n'.format(topelement, element))
    output.write('{\n' )
    output.write('\treturn m{0}.get(n);\n'.format(strFunctions.capp(name)))
    output.write('}\n\n\n')
  else:
    output.write(' * Get a {0} from the {1} by index.\n'.format(element, listOf))
    output.write('*/\n')
    output.write('{0}*\n'.format(type))
    output.write('{0}::get(unsigned int n)\n'.format(listOf))
    output.write('{\n' )
    output.write('\treturn static_cast<{0}*>(SedListOf::get(n));\n'.format(type))
    output.write('}\n\n\n')
  output.write('/*\n')
  if subelement == True:
    output.write(' * Return the nth {0} in the {1} within this {2}.\n'.format(element, listOf, topelement))
    output.write(' */\n')
    output.write('const {0}*\n'.format(type))
    output.write('{0}::get{1}(unsigned int n) const\n'.format(topelement, element))
    output.write('{\n' )
    output.write('\treturn m{0}.get(n);\n'.format(strFunctions.capp(name)))
    output.write('}\n\n\n')
  else:
    output.write(' * Get a {0} from the {1} by index.\n'.format(element, listOf))
    output.write(' */\n')
    output.write('const {0}*\n'.format(type))
    output.write('{0}::get(unsigned int n) const\n'.format(listOf))
    output.write('{\n' )
    output.write('\treturn static_cast<const {0}*>(SedListOf::get(n));\n'.format(type))
    output.write('}\n\n\n')
  output.write('/*\n')
  if subelement == True:
    output.write(' * Return a {0} from the {1} by id.\n'.format(element, listOf))
    output.write(' */\n')
    output.write('{0}*\n'.format(type))
    output.write('{0}::get{1}(const std::string& sid)\n'.format(topelement, element))
    output.write('{\n' )
    output.write('\treturn m{0}.get(sid);\n'.format(strFunctions.capp(name)))
    output.write('}\n\n\n')
  else:
    output.write(' * Get a {0} from the {1} by id.\n'.format(element, listOf))
    output.write(' */\n')
    output.write('{0}*\n'.format(type))
    output.write('{0}::get(const std::string& sid)\n'.format(listOf))
    output.write('{\n' )
    output.write('\treturn const_cast<{0}*>(\n'.format(type))
    output.write('\t  static_cast<const {0}&>(*this).get(sid));\n'.format(listOf))
    output.write('}\n\n\n')
  output.write('/*\n')
  if subelement == True:
    output.write(' * Return a {0} from the {1} by id.\n'.format(element, listOf))
    output.write(' */\n')
    output.write('const {0}*\n'.format(type))
    output.write('{0}::get{1}(const std::string& sid) const\n'.format(topelement, element))
    output.write('{\n' )
    output.write('\treturn m{0}.get(sid);\n'.format(strFunctions.capp(name)))
    output.write('}\n\n\n')
  else:
    output.write(' * Get a {0} from the {1} by id.\n'.format(element, listOf))
    output.write(' */\n')
    output.write('const {0}*\n'.format(type))
    output.write('{0}::get(const std::string& sid) const\n'.format(listOf))
    output.write('{\n' )
    output.write('\tvector<SedBase*>::const_iterator result;\n\n')
    output.write('\tresult = find_if( mItems.begin(), mItems.end(), SedIdEq<{0}>(sid) );\n'.format(type))
    output.write('\treturn (result == mItems.end()) ? 0 : static_cast <{0}*> (*result);\n'.format(type))
    output.write('}\n\n\n')
     
def writeRemoveFunctions(output, element, type, subelement=False, topelement="", name=""):
  listOf = generalFunctions.writeListOf(element)
  output.write('/*\n')
  if subelement == True:
    output.write(' * Removes the nth {0} from the {1}.\n'.format(element, listOf))
    output.write(' */\n')
    output.write('{0}*\n'.format(type))
    output.write('{0}::remove{1}(unsigned int n)\n'.format(topelement, element))
    output.write('{\n' )
    output.write('\treturn m{0}.remove(n);\n'.format(strFunctions.capp(name)))
    output.write('}\n\n\n')
  else:
    output.write(' * Removes the nth {0} from this {1}\n'.format(element, listOf))
    output.write(' */\n')
    output.write('{0}*\n{1}::remove(unsigned int n)\n'.format(type, listOf))
    output.write('{\n' )
    output.write('\treturn static_cast<{0}*>(SedListOf::remove(n));\n'.format(type))
    output.write('}\n\n\n')
  output.write('/*\n')
  if subelement == True:
    output.write(' * Removes the a {0} with given id from the {1}.\n'.format(element, listOf))
    output.write(' */\n')
    output.write('{0}*\n'.format(type))
    output.write('{0}::remove{1}(const std::string& sid)\n'.format(topelement, element))
    output.write('{\n' )
    output.write('\treturn m{0}.remove(sid);\n'.format(strFunctions.capp(name)))
    output.write('}\n\n\n')
  else:
    output.write(' * Removes the {0} from this {1} with the given identifier\n'.format(element, listOf))
    output.write(' */\n')
    output.write('{0}*\n{1}::remove(const std::string& sid)\n'.format(type, listOf))
    output.write('{\n' )
    output.write('\tSedBase* item = NULL;\n')
    output.write('\tvector<SedBase*>::iterator result;\n\n')
    output.write('\tresult = find_if( mItems.begin(), mItems.end(), SedIdEq<{0}>(sid) );\n\n'.format(type))
    output.write('\tif (result != mItems.end())\n\t{\n')
    output.write('\t\titem = *result;\n')
    output.write('\t\tmItems.erase(result);\n\t}\n\n')
    output.write('\treturn static_cast <{0}*> (item);\n'.format(type))
    output.write('}\n\n\n')
     
  
def writeProtectedFunctions(output, element, package, name, elementDict):
  type = elementDict['name']
  elName = elementDict['name']
  if elementDict.has_key('elementName'):
    elName = strFunctions.cap(elementDict['elementName']) 
  if elementDict.has_key('element'):
    type = elementDict['element']

  listOf = generalFunctions.writeListOf(elName)
  generalFunctions.writeInternalStart(output)
  output.write('/*\n')
  output.write(' * Creates a new {0} in this {1}\n'.format(element, listOf))
  output.write(' */\n')
  output.write('SedBase*\n{0}::createObject(XMLInputStream& stream)\n'.format(listOf))
  output.write('{\n' )
  output.write('\tconst std::string& name   = stream.peek().getName();\n')
  output.write('\tSedBase* object = NULL;\n\n')
  if elementDict == None or elementDict.has_key('abstract') == False or (elementDict.has_key('abstract') and elementDict['abstract'] == False):
    output.write('\tif (name == "{0}")\n'.format(name))
    output.write('\t{\n')
    output.write('\t\tobject = new {0}(getSedNamespaces());\n'.format(element))
    output.write('\t\tappendAndOwn(object);\n\t}\n\n')
  elif elementDict != None and elementDict.has_key('concrete'):
    for elem in elementDict['concrete']:
      output.write('\tif (name == "{0}")\n'.format(elem['name']))
      output.write('\t{\n')
      output.write('\t\tobject = new {0}(getSedNamespaces());\n'.format(elem['element']))
      output.write('\t\tappendAndOwn(object);\n\t}\n\n')
  output.write('\treturn object;\n')
  output.write('}\n\n\n')
  generalFunctions.writeInternalEnd(output)
  generalFunctions.writeInternalStart(output)
  output.write('/*\n')
  output.write(' * Write the namespace for the {0} package.\n'.format(package))
  output.write(' */\n')
  output.write('void\n{0}::writeXMLNS(XMLOutputStream& stream) const\n'.format(listOf))
  output.write('{\n' )
  output.write('\tXMLNamespaces xmlns;\n\n')
  output.write('\tstd::string prefix = getPrefix();\n\n')
  output.write('\tif (prefix.empty())\n')
  output.write('\t{\n')
  output.write('\t\tif (getNamespaces() != NULL && !getNamespaces()->hasURI(SEDML_XMLNS_L1) && !getNamespaces()->hasURI(SEDML_XMLNS_L1V2))\n')
  output.write('\t\t{\n')
  output.write('\t\t\tif (getVersion() == 2) xmlns.add(SEDML_XMLNS_L1V2,prefix);\n')
  output.write('\t\t\telse xmlns.add(SEDML_XMLNS_L1V2,prefix);\n')
  output.write('\t\t}\n')
  output.write('\t}\n\n')
  output.write('\tstream << xmlns;\n')
  output.write('}\n\n\n')
  generalFunctions.writeInternalEnd(output)
  
   
# write the code file      
def createCode(element, code):
  type = element['name']
  name = element['name']
  if element.has_key('elementName'):
    name = strFunctions.cap(element['elementName']) 
  if element.has_key('element'):
    type = element['element']
  listOf = generalFunctions.writeListOf(name)
  writeConstructors(name, type, element['package'], code) 
  writeGetFunctions(code, name, type)
  code.write('/**\n')
  code.write(' * Adds a copy the given \"{0}\" to this {1}.\n'.format(type, listOf))
  code.write(' *\n')
  code.write(' * @param {0}; the {1} object to add\n'.format(strFunctions.objAbbrev(type), type))
  code.write(' *\n')
  code.write(' * @return integer value indicating success/failure of the\n')
  code.write(' * function.  @if clike The value is drawn from the\n')
  code.write(' * enumeration #OperationReturnValues_t. @endif The possible values\n')
  code.write(' * returned by this function are:\n')
  code.write(' * @li LIBSEDML_OPERATION_SUCCESS\n')
  code.write(' * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE\n')
  code.write(' */\n')
  code.write('int\n')
  code.write('{0}::add{1}(const {2}* {3})\n'.format(listOf, strFunctions.cap(name), type, strFunctions.objAbbrev(type)))
  code.write('{\n')
  code.write('\tif({0} == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;\n'.format(strFunctions.objAbbrev(type)))
  code.write('\tappend({0});\n'.format(strFunctions.objAbbrev(type)))
  code.write('\treturn LIBSEDML_OPERATION_SUCCESS;\n')
  code.write('}\n\n\n')
  code.write('/**\n')
  code.write(' * Get the number of {0} objects in this {1}.\n'.format(type, listOf))
  code.write(' *\n')
  code.write(' * @return the number of {0} objects in this {1}\n'.format(type, listOf))
  code.write(' */\n')
  code.write('unsigned int \n')
  code.write('{0}::getNum{1}s() const\n'.format(listOf, strFunctions.cap(name)))
  code.write('{\n')
  code.write('\treturn size();\n')
  code.write('}\n\n')
  if element.has_key('abstract') == False or (element.has_key('abstract') and element['abstract'] == False):
    code.write('/**\n')
    code.write(' * Creates a new {0} object, adds it to this {1}s\n'.format(type, listOf))
    code.write(' * {0} and returns the {1} object created. \n'.format(element['name'], type))
    code.write(' *\n')
    code.write(' * @return a new {0} object instance\n'.format(type))
    code.write(' *\n')
    code.write(' * @see add{0}(const {0}* {1})\n'.format(type, strFunctions.objAbbrev(type)))
    code.write(' */\n')
    code.write('{0}* \n'.format(type))
    code.write('{0}::create{1}()\n'.format(listOf, strFunctions.cap(name)))
    code.write('{\n')
    code.write('\t{0} *temp = new {0}();\n'.format(type))
    code.write('\tif (temp != NULL) appendAndOwn(temp);\n')
    code.write('\treturn temp;\n')
    code.write('}\n\n')
  elif element.has_key('concrete'):
    for elem in element['concrete']:
      code.write('/**\n')
      code.write(' * Creates a new {0} object, adds it to this {1}\n'.format(elem['element'], listOf))
      code.write(' * {0} and returns the {1} object created. \n'.format(elem['name'], elem['element']))
      code.write(' *\n')
      code.write(' * @return a new {0} object instance\n'.format(elem['element']))
      code.write(' *\n')
      code.write(' * @see add{0}(const {1}* {2})\n'.format(strFunctions.cap(elem['name']), type, strFunctions.objAbbrev(type)))
      code.write(' */\n')
      code.write('{0}* \n'.format(elem['element']))
      code.write('{0}::create{1}()\n'.format(listOf, strFunctions.cap(elem['name'])))
      code.write('{\n')
      code.write('\t{0} *temp = new {0}();\n'.format(elem['element']))
      code.write('\tif (temp != NULL) appendAndOwn(temp);\n')
      code.write('\treturn temp;\n')
      code.write('}\n\n')
  writeRemoveFunctions(code, name, type)
  generalFunctions.writeCommonCPPCode(code, element['name'], element['typecode'],None,  True, False,False, element)
  elementName = element['name']
  if element.has_key('elementName'):
    elementName = element['elementName']
  writeProtectedFunctions(code, element['name'], element['package'], elementName, element)

  