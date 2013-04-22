#!/usr/bin/env ruby
#
## @file    print_sedml.rb
## @brief   Prints an overview of the elments in the given SED-ML document
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
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES
## LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
## ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
## SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
## ------------------------------------------------------------------------ -.
## 


require 'libSEDML'

if ARGV.size != 1
  puts "Usage: ruby print_sedml.rb input-filename"
  exit(2)
end

doc = LibSEDML::readSedML(ARGV[0])
if ( doc.getErrorLog.getNumFailsWithSeverity(LibSEDML::LIBSEDML_SEV_ERROR) > 0)
  puts doc.getErrorLog.toString
  exit(2) 
end

puts "The document has #{doc.getNumSimulations} simulation(s)."
doc.getNumSimulations.times do |i|
  current = doc.getSimulation(i)
  if (current.getTypeCode == LibSEDML::SEDML_SIMULATION_UNIFORMTIMECOURSE)
    tc = current
    kisaoid="none"
    if tc.isSetAlgorithm
	  kisaoid=tc.getAlgorithm.getKisaoID
	end
    puts "\tTimecourse id=#{tc.getId} start=#{tc.getOutputStartTime} end=#{tc.getOutputEndTime} numPoints=#{tc.getNumberOfPoints} kisao=#{kisaoid}\n"
  else
    puts "\tUncountered unknown simulation. ",current.getId,"\n"
  end
end

puts "\nThe document has #{doc.getNumModels} model(s)."
doc.getNumModels.times do |i|
  current = doc.getModel(i)
  puts "\tModel id=#{current.getId} language=#{current.getLanguage} source=#{current.getSource} numChanges=#{current.getNumChanges}\n"
end

puts "\nThe document has #{doc.getNumTasks} task(s)."
doc.getNumTasks.times do |i|
  current = doc.getTask(i)
  puts "\tTask id=#{current.getId} model=#{current.getModelReference} sim=#{current.getSimulationReference}\n"
end

puts "\nThe document has #{doc.getNumDataGenerators} datagenerators(s)."
doc.getNumDataGenerators.times do |i|
  current = doc.getDataGenerator(i)
  puts "\tDG id=#{current.getId} math=#{LibSEDML::formulaToString(current.getMath)}\n"
end

puts "\nThe document has #{doc.getNumOutputs} output(s)."
doc.getNumOutputs.times do |i|
  current = doc.getOutput(i)
  tc = current.getTypeCode
  if tc == LibSEDML::SEDML_OUTPUT_REPORT
    r = (current)
    puts "\tReport id=#{current.getId} numDataSets=#{r.getNumDataSets }\n"
  elsif tc == LibSEDML::SEDML_OUTPUT_PLOT2D
    p = (current)
    puts "\tPlot2d id=#{current.getId} numCurves=#{p.getNumCurves}\n"
  elsif tc == LibSEDML::SEDML_OUTPUT_PLOT3D
    p = (current)
    puts "\tPlot3d id=#{current.getId} numSurfaces=#{p.getNumSurfaces}\n"
  else
    puts "\tEncountered unknown output #{current.getId}\n"
  end
end
puts "\n"

