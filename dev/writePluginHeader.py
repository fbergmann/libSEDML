#!/usr/bin/env python
#
# @file   writePluginHeader.py
# @brief  Create the extension files for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions

def writeClassDefn(fileOut, nameOfClass, pkg, members):
  fileOut.write('class LIBSEDML_EXTERN {0} : public SedBasePlugin\n'.format(nameOfClass))
  fileOut.write('{\npublic:\n\n')
  writeConstructors(fileOut, nameOfClass, pkg)
  writeRequiredMethods(fileOut)
  writeGetFunctions(fileOut, pkg, members)
  generalFunctions.writeSetDocHeader(fileOut)
  # TO DO - these properly
  fileOut.write('\tvirtual void connectToParent (SedBase* sbase);\n\n\n')
  #fileOut.write('\tvirtual void enablePackageInternal(const std::string& pkgURI,\n')
  #fileOut.write('\t                                   const std::string& pkgPrefix, bool flag);\n\n\n')
  writeClassEnd(fileOut, members)

def writeClassEnd(fileOut, members):
  fileOut.write('protected:\n\n')
  generalFunctions.writeInternalStartDecl(fileOut)
  for i in range (0, len(members)):
    mem = members[i]
    fileOut.write('\tSedListOf{0}s m{0}s;\n'.format(mem['name']))
  fileOut.write('\n')
  generalFunctions.writeInternalEndDecl(fileOut)
  fileOut.write('};\n\n\n')
 
def writeConstructors(fileOut, nameOfClass, pkg):
 # indent = strFunctions.getIndent(nameOfClass)
  fileOut.write('\t/**\n\t * ' )
  fileOut.write('Creates a new {0}\n'.format(nameOfClass))
  fileOut.write('\t */\n')
  fileOut.write('\t{0}(const std::string& uri, const std::string& prefix, \n'.format(nameOfClass))
  fileOut.write('\t                               SedNamespaces* {0}ns);\n\n\n'.format(pkg.lower()))
  fileOut.write('\t/**\n\t * ' )
  fileOut.write('Copy constructor for {0}.\n'.format(nameOfClass))
  fileOut.write('\t *\n')
  fileOut.write('\t * @param orig; the {0} instance to copy.\n'.format(nameOfClass))
  fileOut.write('\t */\n')
  fileOut.write('\t{0}(const {1}& orig);\n\n\n '.format(nameOfClass, nameOfClass))
  fileOut.write('\t/**\n\t * ' )
  fileOut.write('Assignment operator for {0}.\n'.format(nameOfClass))
  fileOut.write('\t *\n')
  fileOut.write('\t * @param rhs; the object whose values are used as the basis\n')
  fileOut.write('\t * of the assignment\n\t */\n')
  fileOut.write('\t{0}& operator=(const {1}& rhs);\n\n\n '.format(nameOfClass, nameOfClass))
  fileOut.write('\t/**\n\t * ' )
  fileOut.write('Creates and returns a deep copy of this {0} object.\n'.format(nameOfClass))
  fileOut.write('\t *\n\t * @return a (deep) copy of this {0} object.\n\t */\n'.format(nameOfClass))
  fileOut.write('\tvirtual {0}* clone () const;\n\n\n '.format(nameOfClass))
  fileOut.write('\t/**\n\t * ' )
  fileOut.write('Destructor for {0}.\n\t */\n'.format(nameOfClass))
  fileOut.write('\tvirtual ~{0}();\n\n\n '.format(nameOfClass))

def writeGetFunctions(fileOut, pkg, members):
  fileOut.write('\t//---------------------------------------------------------------\n')
  fileOut.write('\t//\n')
  fileOut.write('\t// Functions for interacting with the members of the plugin\n')
  fileOut.write('\t//\n')
  fileOut.write('\t//---------------------------------------------------------------\n\n')
  for i in range (0, len(members)):
    mem = members[i]
    writeFunctions(fileOut, mem['name'])
  
def writeFunctions(fileOut, object):
  fileOut.write('\t/**\n')
  fileOut.write('\t * Returns the SedListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return SedListOf{0}s object in this plugin object.\n'.format(object))
  fileOut.write('\t */\n')
  fileOut.write('\tconst SedListOf{0}s* getListOf{0}s () const;\n\n\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Returns the SedListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return SedListOf{0}s object in this plugin object.\n'.format(object))
  fileOut.write('\t */\n')
  fileOut.write('\tSedListOf{0}s* getListOf{0}s ();\n\n\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Returns the {0} object that belongs to the given index. If the \n'.format(object)) 
  fileOut.write('\t * index is invalid, NULL is returned.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * @param n the index number of the {0} to get\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return the nth {0} in the SedListOf{0}s\n'.format(object))
  fileOut.write('\t */\n')
  fileOut.write('\tconst {0}* get{0}(unsigned int n) const;\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Returns the {0} object that belongs to the given index. If the \n'.format(object)) 
  fileOut.write('\t * index is invalid, NULL is returned.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * @param n the index number of the {0} to get\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return the nth {0} in the SedListOf{0}s\n'.format(object))
  fileOut.write('\t */\n')
  fileOut.write('\t{0}* get{0}(unsigned int n);\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Returns the {0} object based on its identifier.\n'.format(object)) 
  fileOut.write('\t *\n')
  fileOut.write('\t * @param sid a string representing the id of the {0} to get\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return {0} in the SedListOf{0}s with the given id\n'.format(object))
  fileOut.write('\t * or NULL if no such {0} exists.\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @see get(unsigned int n)\n')
  fileOut.write('\t * @see size()\n')
  fileOut.write('\t */\n')
  fileOut.write('\tconst {0}* get{0}(const std::string& sid) const;\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Returns the {0} object based on its identifier.\n'.format(object)) 
  fileOut.write('\t *\n')
  fileOut.write('\t * @param sid a string representing the id of the {0} to get\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return {0} in the SedListOf{0}s with the given id\n'.format(object))
  fileOut.write('\t * or NULL if no such {0} exists.\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @see get(unsigned int n)\n')
  fileOut.write('\t * @see size()\n')
  fileOut.write('\t */\n')
  fileOut.write('\t{0}* get{0}(const std::string& sid);\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Adds a copy of the given {0} to the SedListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @param {0} the {0} to be added.\n'.format(strFunctions.lowerFirst(object), object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return integer value indicating success/failure of the\n')
  fileOut.write('\t * function.  @if clike The value is drawn from the\n')
  fileOut.write('\t * enumeration #OperationReturnValues_t. @endif The possible values\n')
  fileOut.write('\t * returned by this function are:\n')
  fileOut.write('\t * @li LIBSEDML_OPERATION_SUCCESS\n')
  fileOut.write('\t */\n')
  fileOut.write('\tint add{0} (const {0}* {1});\n\n\n'.format(object, strFunctions.lowerFirst(object)))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Creates a new {0} object and adds it to the SedListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return the newly created {0} object.\n'.format(object))
  fileOut.write('\t */\n')
  fileOut.write('\t{0}* create{0} ();\n\n\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Removes the nth {0} object from this plugin object\n'.format(object)) 
  fileOut.write('\t * and returns a pointer to it.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * The caller owns the returned object and is responsible for\n')
  fileOut.write('\t * deleting it.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * @param n the index of the {0} to remove\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return the {0} object removed \n'.format(object))
  fileOut.write('\t * or NULL index was out of range.\n'.format(object))
  fileOut.write('\t */\n')
  fileOut.write('\t{0}* remove{0}(unsigned int n);\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Removes the {0} object with the given id from this plugin object\n'.format(object)) 
  fileOut.write('\t * and returns a pointer to it.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * The caller owns the returned object and is responsible for\n')
  fileOut.write('\t * deleting it.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * @param sid a string representing the id of the {0} to remove\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return the {0} object removed \n'.format(object))
  fileOut.write('\t * or NULL if no such {0} exists.\n'.format(object))
  fileOut.write('\t */\n')
  fileOut.write('\t{0}* remove{0}(const std::string& sid);\n'.format(object))
  fileOut.write('\t/**\n')
  fileOut.write('\t * Returns the number of {0} objects in this plugin object.\n'.format(object))
  fileOut.write('\t *\n')
  fileOut.write('\t * @return the number of {0} objects in this plugin object.\n'.format(object))
  fileOut.write('\t */\n')
  fileOut.write('\tunsigned int getNum{0}s () const;\n\n\n'.format(object))



# write the include files
def writeIncludes(fileOut, pkg, element, members):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/common/extern.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/extension/SedBasePlugin.h>\n')
  for i in range (0, len(members)):
    mem = members[i]
    fileOut.write('#include <sedml/packages/{0}/sedml/{1}.h>\n'.format(pkg.lower(), mem['name']))
  fileOut.write('\n\n');
  fileOut.write('LIBSEDML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

def writeIncludeEnds(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('LIBSEDML_CPP_NAMESPACE_END\n')
  fileOut.write('\n\n');
  fileOut.write('#endif /* __cplusplus */\n')
  fileOut.write('#endif /* {0}_H__ */\n\n\n'.format(element))

def writeRequiredMethods(fileOut):
  fileOut.write('\t//---------------------------------------------------------------\n')
  fileOut.write('\t//\n')
  fileOut.write('\t// overridden virtual functions for read/write/check\n')
  fileOut.write('\t//\n')
  fileOut.write('\t//---------------------------------------------------------------\n\n')
  generalFunctions.writeInternalStartDecl(fileOut)
  fileOut.write('\t/**\n')
  fileOut.write('\t * Subclasses must override this method to create, store, and then\n')
  fileOut.write('\t * return an SEDML object corresponding to the next XMLToken in the\n')
  fileOut.write('\t * XMLInputStream if they have their specific elements.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * @return the SEDML object corresponding to next XMLToken in the\n')
  fileOut.write('\t * XMLInputStream or NULL if the token was not recognized.\n')
  fileOut.write('\t */\n')
  fileOut.write('\tvirtual SedBase* createObject (XMLInputStream& stream);\n\n\n')
  generalFunctions.writeInternalEndDecl(fileOut)
  generalFunctions.writeInternalStartDecl(fileOut)
  fileOut.write('\t/**\n')
  fileOut.write('\t * Subclasses must override this method to write out their contained\n')
  fileOut.write('\t * SEDML objects as XML elements if they have their specific elements.\n')
  fileOut.write('\t */\n')
  fileOut.write('\tvirtual void writeElements (XMLOutputStream& stream) const;\n\n\n')
  generalFunctions.writeInternalEndDecl(fileOut)
  fileOut.write('\t/**\n')
  fileOut.write('\t * Checks if this plugin object has all the required elements.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * Subclasses must override this method \n')
  fileOut.write('\t * if they have their specific elements.\n')
  fileOut.write('\t *\n')
  fileOut.write('\t * @return true if this plugin object has all the required elements\n')
  fileOut.write('\t * otherwise false will be returned.\n')
  fileOut.write('\t */\n')
  fileOut.write('\tvirtual bool hasRequiredElements () const;\n\n\n')
  fileOut.write('\t//---------------------------------------------------------------\n\n\n')

def createHeader(package, plugin):
  nameOfPackage = package['name']
  nameOfPlugin = plugin['sbase']
  nameOfClass = nameOfPackage + nameOfPlugin + 'Plugin'
  codeName = nameOfClass + '.h'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfClass)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfPackage, nameOfClass, plugin['extension'])
  writeClassDefn(code, nameOfClass, nameOfPackage, plugin['extension'])
  writeIncludeEnds(code, nameOfClass)

  