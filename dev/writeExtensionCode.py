#!/usr/bin/env python
#
# @file   writeExtensionCode.py
# @brief  Create the extension files for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions

def writeClass(fileOut, nameOfClass, pkg, elements):
  writeRequiredMethods(fileOut, nameOfClass, pkg, elements)
  writeConstructors(fileOut, nameOfClass)
  writeGetFunctions(fileOut, pkg, nameOfClass, elements)

def writeConstructors(fileOut, nameOfClass):
  fileOut.write('/*\n * Constructor\n */\n' )
  fileOut.write('{0}::{0}()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n * Copy constructor\n */\n' )
  fileOut.write('{0}::{0}(const {0}& orig) :\n '.format(nameOfClass))
  fileOut.write('\tSEDMLExtension(orig)\n')
  fileOut.write('{\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n * Assignment operator\n */\n' )
  fileOut.write('{0}&\n'.format(nameOfClass))
  fileOut.write('{0}::operator=(const {0}& rhs)\n '.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\tif (&rhs != this)\n')
  fileOut.write('\t{\n')
  fileOut.write('\t\tSEDMLExtension::operator=(rhs);\n')
  fileOut.write('\t}\n')
  fileOut.write('\treturn *this;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n * Clone\n */\n' )
  fileOut.write('{0}*\n'.format(nameOfClass))
  fileOut.write('{0}::clone () const\n '.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\treturn new {0}(*this);\n'.format(nameOfClass))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n * Destructor\n */\n' )
  fileOut.write('{0}::~{0}()\n '.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('}\n\n\n')

def writeGetFunctions(fileOut, pkg, nameOfClass, elements):
  fileOut.write('/*\n')
  fileOut.write(' * Returns the name of this package\n')
  fileOut.write(' */\n')
  fileOut.write('const std::string&\n')
  fileOut.write('{0}::getName() const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\treturn getPackageName();\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the URI (namespace) of the package\n') 
  fileOut.write(' */\n')
  fileOut.write('const std::string&\n')
  fileOut.write('{0}::getURI(unsigned int sedmlLevel,\n'.format(nameOfClass))
  fileOut.write('                                  unsigned int sedmlVersion,\n')
  fileOut.write('                                  unsigned int pkgVersion) const\n')
  fileOut.write('{\n')
  fileOut.write('\tif (sedmlLevel == 3)\n')
  fileOut.write('\t{\n')
  fileOut.write('\t\tif (sedmlVersion == 1)\n')
  fileOut.write('\t\t{\n')
  fileOut.write('\t\t\tif (pkgVersion == 1)\n')
  fileOut.write('\t\t\t{\n')
  fileOut.write('\t\t\t\treturn getXmlnsL3V1V1();\n')
  fileOut.write('\t\t\t}\n')
  fileOut.write('\t\t}\n')
  fileOut.write('\t}\n')
  fileOut.write('\n\tstatic std::string empty = "";\n')
  fileOut.write('\n\treturn empty;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the SEDML level with the given URI of this package.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getLevel(const std::string &uri) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\tif (uri == getXmlnsL3V1V1())\n')
  fileOut.write('\t{\n')
  fileOut.write('\t\treturn 3;\n')
  fileOut.write('\t}\n')
  fileOut.write('\n\treturn 0;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the SEDML version with the given URI of this package.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')   
  fileOut.write('{0}::getVersion(const std::string &uri) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\tif (uri == getXmlnsL3V1V1())\n')
  fileOut.write('\t{\n')
  fileOut.write('\t\treturn 1;\n')
  fileOut.write('\t}\n')
  fileOut.write('\n\treturn 0;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the package version with the given URI of this package.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')   
  fileOut.write('{0}::getPackageVersion(const std::string &uri) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\tif (uri == getXmlnsL3V1V1())\n')
  fileOut.write('\t{\n')
  fileOut.write('\t\treturn 1;\n')
  fileOut.write('\t}\n')
  fileOut.write('\n\treturn 0;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns an SEDMLExtensionNamespaces<{0}Extension> object \n'.format(pkg))
  fileOut.write(' */\n')
  fileOut.write('SedNamespaces*\n')   
  fileOut.write('{0}::getSEDMLExtensionNamespaces(const std::string &uri) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\tSedNamespaces* pkgns = NULL;\n')
  fileOut.write('\tif (uri == getXmlnsL3V1V1())\n')
  fileOut.write('\t{\n')
  fileOut.write('\t\tpkgns = new SedNamespaces(1, 1);\n')
  fileOut.write('\t}\n')
  fileOut.write('\n\treturn pkgns;\n')
  fileOut.write('}\n\n\n')



# write the include files
def writeIncludes(fileOut, element, pkg, plugins):
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/extension/SEDMLExtensionRegister.h>\n')
  fileOut.write('#include <sedml/extension/SEDMLExtensionRegistry.h>\n')
  fileOut.write('#include <sedml/extension/SedBasePluginCreator.h>\n')
  fileOut.write('#include <sedml/extension/SedDocumentPlugin.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/packages/{0}/extension/{1}.h>\n'.format(pkg.lower(), element))
  for i in range (0, len(plugins)):
    plug = plugins[i]
    fileOut.write('#include <sedml/packages/{0}/extension/{1}{2}Plugin.h>\n'.format(pkg.lower(), pkg, plug['sbase']))
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <iostream>\n')
  fileOut.write('\n\n');
  fileOut.write('LIBSEDML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

def writeIncludeEnds(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('LIBSEDML_CPP_NAMESPACE_END\n')
  fileOut.write('\n\n');
  fileOut.write('#endif /* __cplusplus */\n\n\n')

def writeInitFunction(fileOut, pkg, nameOfClass, plugins):
  fileOut.write('/*\n')
  fileOut.write(' * Initialization function of {0} extension module which is automatically invoked\n'.format(pkg.lower()))
  fileOut.write(' * by SEDMLExtensionRegister class before main() function invoked. \n')
  fileOut.write(' */\n')
  fileOut.write('void\n')
  fileOut.write('{0}::init()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\t//\n')
  fileOut.write('\t// 1. Check if the {0} package has already been registered\n'.format(pkg.lower()))
  fileOut.write('\t//\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\n\tif (SEDMLExtensionRegistry::getInstance().isRegistered(getPackageName()))\n')
  fileOut.write('\t{\n')
  fileOut.write('\t\t// do nothing\n')
  fileOut.write('\t\t return;\n')
  fileOut.write('\t}\n\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\t//\n')
  fileOut.write('\t// 2. Creates an SEDMLExtension derived object\n')
  fileOut.write('\t//\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\n\t{0}Extension {1}Extension;\n\n'.format(pkg, pkg.lower()));
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\t//\n')
  fileOut.write('\t// 3. Creates the SedBasePlugins required by this package\n')
  fileOut.write('\t//\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\n\tstd::vector<std::string> packageURIs;\n');
  fileOut.write('\tpackageURIs.push_back(getXmlnsL3V1V1());\n');
  fileOut.write('\n\tSedBaseExtensionPoint sedmldocExtPoint("core", SEDML_DOCUMENT);\n');
  # add an extension point for each class that has a plugin
  for i in range (0, len(plugins)):
    plug_ext = plugins[i]
    plug = plug_ext['sbase']
    fileOut.write('\tSedBaseExtensionPoint {0}ExtPoint("core", SEDML_{1});\n'.format(plug.lower(), plug.upper()))
  fileOut.write('\n')
  fileOut.write('\tSedBasePluginCreator<SedDocumentPlugin, {0}Extension> sedmldocPluginCreator(sedmldocExtPoint, packageURIs);\n'.format(pkg))
  for i in range (0, len(plugins)):
    plug_ext = plugins[i]
    plug = plug_ext['sbase']
    fileOut.write('\tSedBasePluginCreator<{0}{1}Plugin, {0}Extension> {2}PluginCreator({2}ExtPoint, packageURIs);\n'.format(pkg, plug, plug.lower()))
  fileOut.write('\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\t//\n')
  fileOut.write('\t// 4. Adds the creator objects to the extension\n')
  fileOut.write('\t//\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\n\t{0}Extension.addSedBasePluginCreator(&sedmldocPluginCreator);\n'.format(pkg.lower()))
  for i in range (0, len(plugins)):
    plug_ext = plugins[i]
    plug = plug_ext['sbase']
    fileOut.write('\t{0}Extension.addSedBasePluginCreator(&{1}PluginCreator);\n'.format(pkg.lower(), plug.lower()))
  fileOut.write('\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\t//\n')
  fileOut.write('\t// 5. Register the object with the registry\n')
  fileOut.write('\t//\n')
  fileOut.write('\t//----------------------------------------------------------------\n')
  fileOut.write('\n')
  fileOut.write('\tint result = SEDMLExtensionRegistry::getInstance().addExtension(&{0}Extension);\n'.format(pkg.lower()))
  fileOut.write('\n')
  fileOut.write('\tif (result != LIBSEDML_OPERATION_SUCCESS)\n')
  fileOut.write('\t{\n')
  fileOut.write('\t\tstd::cerr << "[Error] {0}Extension::init() failed." << std::endl;\n'.format(pkg))
  fileOut.write('\t}\n')
  fileOut.write('}\n\n\n')


def writeRequiredMethods(fileOut, nameOfClass, pkg, elements):
  fileOut.write('/*---------------------------------------------------------------\n')
  fileOut.write(' *\n')
  fileOut.write(' * This block is global initialization code which should be automatically\n')
  fileOut.write(' * executed before invoking main() block.\n')
  fileOut.write(' *\n')
  fileOut.write(' */\n\n')
  fileOut.write('/*------------------ (START) ----------------------------------*/\n\n')
  fileOut.write('/*\n')
  fileOut.write('/* Returns the package name of this extension.\n')
  fileOut.write(' */\n')
  fileOut.write('const std::string&\n')
  fileOut.write('{0}::getPackageName ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\tstatic const std::string pkgName = "{0}";\n'.format(pkg.lower()))
  fileOut.write('\treturn pkgName;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the default SEDML Level this extension.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getDefaultLevel ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\treturn 3;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the default SEDML Version this extension.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getDefaultVersion ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\treturn 1;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the default SEDML version this extension.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getDefaultPackageVersion ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\treturn 1;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * XML namespaces of package.\n')
  fileOut.write(' */\n')
  fileOut.write('const std::string&\n')
  fileOut.write('{0}::getXmlnsL3V1V1 ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('\tstatic const std::string xmlns = "http://www.sedml.org/sedml/level3/version1/{0}/version1";\n'.format(pkg.lower()))
  fileOut.write('\treturn xmlns;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Adds this {0} object to the SEDMLExtensionRegistry class.\n'.format(nameOfClass))
  fileOut.write(' * {0}::init function is automatically invoked when this\n'.format(nameOfClass))
  fileOut.write(' * object is instantiated\n')
  fileOut.write(' */\n')
  fileOut.write('static SEDMLExtensionRegister<{0}> {1}ExtensionRegistry;\n\n\n'.format(nameOfClass, pkg.lower()))
  if len(elements) > 0:
    fileOut.write('static\nconst char * SEDML_{0}_TYPECODE_STRINGS[] = \n'.format(pkg.upper()))
    fileOut.write('{\n')
    el = elements[0]
    name = el['name']
    fileOut.write('\t  "{0}"\n'.format(name))
    for i in range (1, len(elements)):
      el = elements[i]
      name = el['name']
      fileOut.write('\t, "{0}"\n'.format(name))
    fileOut.write('};\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Instantiate SEDMLExtensionNamespaces<{0}>\n'.format(nameOfClass))
  fileOut.write(' * (SedNamespaces) for DLL.\n')
  fileOut.write(' */\n')
  fileOut.write('template class LIBSEDML_EXTERN  SEDMLExtensionNamespaces<{0}>;\n\n\n'.format(nameOfClass))
  fileOut.write('/*------------------ (END) ----------------------------------*/\n\n')


def writeTypeDefns(fileOut, nameOfClass, pkg, elements, number):
  length = len(elements)
  if length > 1:
    el = elements[0];
    el_ty_min = el['typecode']
    el = elements[length-1]
    el_ty_max = el['typecode']
    fileOut.write('/*\n')
    fileOut.write(' * This method takes a type code from the {0} package and returns a string representing \n'.format(pkg))
    fileOut.write(' */\n')
    fileOut.write('const char*\n')   
    fileOut.write('{0}::getStringFromTypeCode(int typeCode) const\n'.format(nameOfClass))
    fileOut.write('{\n')
    fileOut.write('\tint min = {0};\n'.format(el_ty_min))
    fileOut.write('\tint max = {0};\n'.format(el_ty_max))
    fileOut.write('\n\tif ( typeCode < min || typeCode > max)\n')
    fileOut.write('\t{\n')
    fileOut.write('\t\treturn "(Unknown SEDML {0} Type)";\n'.format(pkg))
    fileOut.write('\t}\n')
    fileOut.write('\n\treturn SEDML_{0}_TYPECODE_STRINGS[typeCode - min];\n'.format(pkg.upper()))
    fileOut.write('}\n\n\n')




def createCode(package):
  nameOfPackage = package['name']
  nameOfClass = nameOfPackage + 'Extension'
  plugins = package['plugins']
  codeName = nameOfClass + '.cpp'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfClass)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfClass, nameOfPackage, plugins)
  writeClass(code, nameOfClass, nameOfPackage, package['elements'])
  writeTypeDefns(code, nameOfClass, nameOfPackage, package['elements'], package['number']) 
  writeInitFunction(code, nameOfPackage, nameOfClass, plugins)
  writeIncludeEnds(code, nameOfClass)

  