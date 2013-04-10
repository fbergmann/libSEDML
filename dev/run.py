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
  #package = createNewPackage.createSed()
  #writeExtensionHeader.createHeader(package)
  #writeExtensionCode.createCode(package)
  #plugins = package['plugins']
  #for i in range(0, len(plugins)):
  #  plugin = plugins[i]
  #  writePluginHeader.createHeader(package, plugin)
  createNewElementDictObj.createElements()
  #element = createNewElementDictObj.createSedSimulation()
  #writeCode.createCode(element)
  #writeHeader.createHeader(element)
