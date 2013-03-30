#!/usr/bin/env python
#
# @file   createDirStruct.py
# @brief  Create teh directory structure for package code
# @author Sarah Keating
#

import sys
import createNewPackage
import createNewElementDictObj
import writeCode
import writeHeader
import writePluginHeader
import writeExtensionHeader
import writeExtensionCode

if len(sys.argv) != 1:
  print 'Usage: run.py'
else:
  #package = createNewPackage.createSedML()
  #writeExtensionHeader.createHeader(package)
  #writeExtensionCode.createCode(package)
  #plugins = package['plugins']
  #for i in range(0, len(plugins)):
  #  plugin = plugins[i]
  #  writePluginHeader.createHeader(package, plugin)
  element = createNewElementDictObj.createSedDocument()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createSedModel()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createSedSimulation()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createSedTask()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createSedDataGenerator()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createSedOutput()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  #element = createNewElementDictObj.createSedSimulation()
  #writeCode.createCode(element)
  #writeHeader.createHeader(element)
