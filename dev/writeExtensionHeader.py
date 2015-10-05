#!/usr/bin/env python
#
# @file   writeExtensionHeader.py
# @brief  Create the extension files for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions

def writeClassDefn(fileOut, nameOfClass, pkg):
  fileOut.write('class LIBSEDML_EXTERN {0} : public SEDMLExtension\n'.format(nameOfClass))
  fileOut.write('{\npublic:\n\n')
  writeRequiredMethods(fileOut)
  writeConstructors(fileOut, nameOfClass)
  writeGetFunctions(fileOut, pkg)
  writeInitFunction(fileOut, pkg)
  writeClassEnd(fileOut)

def writeClassEnd(fileOut):
  fileOut.write('};\n\n\n')
 
def writeConstructors(fileOut, nameOfClass):
 # indent = strFunctions.getIndent(nameOfClass)
  fileOut.write('  /**\n   * ' )
  fileOut.write('Creates a new {0}'.format(nameOfClass))
  fileOut.write('   */\n')
  fileOut.write('  {0}();\n\n\n'.format(nameOfClass))
  fileOut.write('  /**\n   * ' )
  fileOut.write('Copy constructor for {0}.\n'.format(nameOfClass))
  fileOut.write('   *\n')
  fileOut.write('   * @param orig; the {0} instance to copy.\n'.format(nameOfClass))
  fileOut.write('   */\n')
  fileOut.write('  {0}(const {1}& orig);\n\n\n'.format(nameOfClass, nameOfClass))
  fileOut.write('  /**\n   * ' )
  fileOut.write('Assignment operator for {0}.\n'.format(nameOfClass))
  fileOut.write('   *\n')
  fileOut.write('   * @param rhs; the object whose values are used as the basis\n')
  fileOut.write('   * of the assignment\n   */\n')
  fileOut.write('  {0}& operator=(const {1}& rhs);\n\n\n'.format(nameOfClass, nameOfClass))
  fileOut.write('  /**\n   * ' )
  fileOut.write('Creates and returns a deep copy of this {0} object.\n'.format(nameOfClass))
  fileOut.write('   *\n   * @return a (deep) copy of this {0} object.\n   */\n'.format(nameOfClass))
  fileOut.write('  virtual {0}* clone () const;\n\n\n'.format(nameOfClass))
  fileOut.write('  /**\n   * ' )
  fileOut.write('Destructor for {0}.\n   */\n'.format(nameOfClass))
  fileOut.write('  virtual ~{0}();\n\n\n'.format(nameOfClass))

def writeGetFunctions(fileOut, pkg):
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the name of this package ("{0}")\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return a string representing the name of this package ("{0}")\n'.format(pkg.lower()))
  fileOut.write('   */\n')
  fileOut.write('  virtual const std::string& getName() const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the URI (namespace) of the package corresponding to the combination of\n') 
  fileOut.write('   * the given sedml level, sedml version, and package version.\n')
  fileOut.write('   * Empty string will be returned if no corresponding URI exists.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param sedmlLevel the level of SEDML\n')
  fileOut.write('   * @param sedmlVersion the version of SEDML\n')
  fileOut.write('   * @param pkgVersion the version of package\n')
  fileOut.write('   *\n')
  fileOut.write('   * @return a string of the package URI\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual const std::string& getURI(unsigned int sedmlLevel,\n')
  fileOut.write('                                    unsigned int sedmlVersion,\n')
  fileOut.write('                                    unsigned int pkgVersion) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the SEDML level with the given URI of this package.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param uri the string of URI that represents one of versions of {0} package\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return the SEDML level with the given URI of this package. 0 will be returned\n')
  fileOut.write('   * if the given URI is invalid.\n')
  fileOut.write('   *\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int getLevel(const std::string &uri) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the SEDML version with the given URI of this package.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param uri the string of URI that represents one of versions of {0} package\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return the SEDML version with the given URI of this package. 0 will be returned\n')
  fileOut.write('   * if the given URI is invalid.\n')
  fileOut.write('   *\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int getVersion(const std::string &uri) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the package version with the given URI of this package.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param uri the string of URI that represents one of versions of {0} package\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return the package version with the given URI of this package. 0 will be returned\n')
  fileOut.write('   * if the given URI is invalid.\n')
  fileOut.write('   *\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int getPackageVersion(const std::string &uri) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns an SEDMLExtensionNamespaces<{0}Extension> object whose alias type is\n'.format(pkg))
  fileOut.write('   * {0}PkgNamespace.\n'.format(pkg))
  fileOut.write('   * Null will be returned if the given uri is not defined in the {0} package.\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @param uri the string of URI that represents one of versions of {0} package\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return an {0}PkgNamespace object corresponding to the given uri. NULL will\n'.format(pkg))
  fileOut.write('   * be returned if the given URI is not defined in {0} package.\n'.format(pkg.lower()))
  fileOut.write('   */\n')
  fileOut.write('  virtual SedNamespaces* getSEDMLExtensionNamespaces(const std::string &uri) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * This method takes a type code from the {0} package and returns a string representing\n'.format(pkg))
  fileOut.write('   * the code.\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual const char* getStringFromTypeCode(int typeCode) const;\n\n\n')



# write the include files
def writeIncludes(fileOut, element, pkg):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/common/extern.h>\n')
  fileOut.write('#include <sedml/SEDMLTypeCodes.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sedml/extension/SEDMLExtension.h>\n')
  fileOut.write('#include <sedml/extension/SEDMLExtensionNamespaces.h>\n')
  fileOut.write('#include <sedml/extension/SEDMLExtensionRegister.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_CREATE_NS\n'.format(pkg.upper()))
  fileOut.write('  #define {0}_CREATE_NS(variable, sedmlns)\\\n'.format(pkg.upper()))
  fileOut.write('    EXTENSION_CREATE_NS({0}PkgNamespaces, variable, sedmlns);\n'.format(pkg))
  fileOut.write('#endif\n')
  fileOut.write('\n\n');
  fileOut.write('#include <vector>\n')
  fileOut.write('\n\n');
  fileOut.write('LIBSEDML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

def writeIncludeEnds(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('LIBSEDML_CPP_NAMESPACE_END\n')
  fileOut.write('\n\n');
  fileOut.write('#endif /* __cplusplus */\n')
  fileOut.write('#endif /* {0}_H__ */\n\n\n'.format(element))

def writeInitFunction(fileOut, pkg):
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Initializes {0} extension by creating an object of this class with\n'.format(pkg.lower()))
  fileOut.write('   * required SedBasePlugin derived objects and registering the object\n')
  fileOut.write('   * to the SEDMLExtensionRegistry class.\n')
  fileOut.write('   *\n')
  fileOut.write('   * (NOTE) This function is automatically invoked when creating the following\n')
  fileOut.write('   *        global object in {0}Extension.cpp\n'.format(pkg))
  fileOut.write('   *\n')
  fileOut.write('   *        static SEDMLExtensionRegister<{0}Extension> {1}ExtensionRegistry;\n'.format(pkg, pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   */\n')
  fileOut.write('  static void init();\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)


def writeRequiredMethods(fileOut):
  fileOut.write('  //---------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // Required class methods\n')
  fileOut.write('  //\n')
  fileOut.write('  //---------------------------------------------------------------\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the package name of this extension.\n')
  fileOut.write('   */\n')
  fileOut.write('  static const std::string& getPackageName ();\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the default SEDML Level this extension.\n')
  fileOut.write('   */\n')
  fileOut.write('  static unsigned int getDefaultLevel();\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the default SEDML Version this extension.\n')
  fileOut.write('   */\n')
  fileOut.write('  static unsigned int getDefaultVersion();\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the default SEDML version this extension.\n')
  fileOut.write('   */\n')
  fileOut.write('  static unsigned int getDefaultPackageVersion();\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns URI of supported versions of this package.\n')
  fileOut.write('   */\n')
  fileOut.write('  static const std::string&  getXmlnsL3V1V1();\n\n\n')
  fileOut.write('  //\n')
  fileOut.write('  // Other URI needed in this package (if any)\n')
  fileOut.write('  //\n')
  fileOut.write('  //---------------------------------------------------------------\n\n\n')

def writeTypeDefns(fileOut, nameOfClass, nameOfPkg, elements, number):
  fileOut.write('// --------------------------------------------------------------------\n')
  fileOut.write('//\n')
  fileOut.write('// Required typedef definitions\n') 
  fileOut.write('//\n')
  fileOut.write('// {0}PkgNamespaces is derived from the SedNamespaces class and\n'.format(nameOfPkg))
  fileOut.write('// used when creating an object of SedBase derived classes defined in\n')
  fileOut.write('// {0} package.\n'.format(nameOfPkg.lower()))
  fileOut.write('//\n')
  fileOut.write('// --------------------------------------------------------------------\n')
  fileOut.write('//\n')
  fileOut.write('// (NOTE)\n')
  fileOut.write('//\n')
  fileOut.write('// SEDMLExtensionNamespaces<{0}> must be instantiated\n'.format(nameOfClass))
  fileOut.write('// in {0}.cpp for DLL.\n'.format(nameOfClass))
  fileOut.write('//\n')
  fileOut.write('typedef SEDMLExtensionNamespaces<{0}> {1}PkgNamespaces;\n\n'.format(nameOfClass, nameOfPkg))
  if len(elements) > 0:
    fileOut.write('typedef enum\n{\n')
    el = elements[0];
    el_ty = el['typecode']
    fileOut.write('    {0}  = {1}\n'.format(el_ty, number))
    for i in range (1, len(elements)):
      el = elements[i];
      el_ty = el['typecode']
      fileOut.write('  , {0:<30} = {1}\n'.format(el_ty, number+i))
    fileOut.write('}\n')
    fileOut.write('SEDML{0}TypeCode_t;\n\n\n'.format(nameOfPkg))




def createHeader(package):
  nameOfPackage = package['name']
  nameOfClass = nameOfPackage + 'Extension'
  codeName = nameOfClass + '.h'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfClass)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfClass, nameOfPackage)
  writeClassDefn(code, nameOfClass, nameOfPackage)
  writeTypeDefns(code, nameOfClass, nameOfPackage, package['elements'], package['number']) 
  writeIncludeEnds(code, nameOfClass)

  