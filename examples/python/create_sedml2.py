#!/usr/bin/env python
## 
## @file    create_sedml2.py
## @brief   cerates a SED-ML document.
## @author  Frank T. Bergmann
## 
## <!--------------------------------------------------------------------------
## This file is part of libSEDML.  Please visit http://sed-ml.org for more
## information about SEDML, and the latest version of libSEDML.
## 
## Copyright (c) 2013, Frank T. Bergmann
## All rights reserved.
## 
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions are met:
## 
## 1. Redistributions of source code must retain the above copyright notice, this
##    list of conditions and the following disclaimer.
## 2. Redistributions in binary form must reproduce the above copyright notice,
##    this list of conditions and the following disclaimer in the documentation
##    and/or other materials provided with the distribution.
## 
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
## ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
## WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
## DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
## ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
## ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
## SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
## ------------------------------------------------------------------------ -.
## 

import sys
import os.path
import libsedml


def main (args):
  """Usage: create_sedml2 output-filename
  """
  if len(args) != 2:
    print(main.__doc__)
    sys.exit(1)

  # create the document
  doc = libsedml.SedDocument()
  doc.setLevel(1)
  doc.setVersion(3)

  # create a data description
  
  ddesc = doc.createDataDescription()
  ddesc.setId('data1')
  ddesc.setName('Oscli Timecourse data')
  ddesc.setSource('foo.numl')
  
  # create data source 
  dsource = ddesc.createDataSource()
  dsource.setId('dataS1')
  
  # create slice 
  slice = dsource.createSlice()
  slice.setReference('SpeciesIds')
  slice.setValue('S1')
  
  # specify mapping
  timeDesc = libsedml.CompositeDescription()
  timeDesc.setIndexType('double')
  timeDesc.setId('time')
  timeDesc.setName('time')
  
  speciesDesc = timeDesc.createCompositeDescription()
  speciesDesc.setIndexType('string')
  speciesDesc.setId('SpeciesIds')
  speciesDesc.setName('SpeciesIds')
  
  concentrationDesc = speciesDesc.createAtomicDescription()
  concentrationDesc.setValueType("double")
  concentrationDesc.setName("Concentrations")
  
  dimDesc = ddesc.createDimensionDescription()
  dimDesc.append(timeDesc)
  
  # write the document
  libsedml.writeSedML(doc, args[1])


if __name__ == '__main__':
  main(sys.argv)  