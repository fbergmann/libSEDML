#!/usr/bin/env perl
# -*-Perl-*-
## 
## @file    print_sedml.pl
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
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
## ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
## SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
## ------------------------------------------------------------------------ -.
## 

use File::Basename;
use LibSEDML;
no strict;

if ($#ARGV != 0) {
   print  ("usage: print_sedml.pl input-filename\n");
   exit 1;
}


$doc = LibSEDML::readSedML($ARGV[0]);
if ( $doc->getErrorLog()->getNumFailsWithSeverity($LibSEDML::LIBSEDML_SEV_ERROR) > 0)
{
  print $doc->getErrorLog()->toString();
  exit(2); 
}

print ("The document has ",$doc->getNumSimulations()," simulation(s).\n");
for ($i = 0; $i < $doc->getNumSimulations(); $i++)
{
  $current = $doc->getSimulation($i);
  if ($current->getTypeCode() == $LibSEDML::SEDML_SIMULATION_UNIFORMTIMECOURSE)
  {
    $tc = $current;
    $kisaoid="none";
    if ($tc->isSetAlgorithm())
	{
	  $kisaoid=$tc->getAlgorithm()->getKisaoID();
	}
    print ("\tTimecourse id=", $tc->getId()," start=",$tc->getOutputStartTime()," end=",$tc->getOutputEndTime()," numPoints=",$tc->getNumberOfPoints()," kisao=",$kisaoid,"\n");
  }
  else
  {
    print ("\tUncountered unknown simulation. ",$current->getId(),"\n");
  }
}

print ("The document has ",$doc->getNumModels() , " model(s)." , "\n");
for ($i =0; $i < $doc->getNumModels();$i++)
{
  $current = $doc->getModel($i);
  print ("\tModel id=" , $current->getId() , " language=" , $current->getLanguage() , " source=" , $current->getSource() , " numChanges=" , $current->getNumChanges() , "\n");
}

print ("The document has " , $doc->getNumTasks() , " task(s)." , "\n");
for ($i =0; $i < $doc->getNumTasks();$i++)
{
  $task = $doc->getTask($i);
  print ("\tTask id=" , $task->getId() , " model=" , $task->getModelReference() , " sim=" , $task->getSimulationReference() , "\n");
}


print ("The document has " , $doc->getNumDataGenerators() , " datagenerators(s)." , "\n");
for ($i=0;$i < $doc->getNumDataGenerators();$i++)
{
  $dg = $doc->getDataGenerator($i);
  print ("\tDG id=" , $dg->getId() , " math=" , LibSEDML::formulaToString($dg->getMath()) , "\n");
}

print ("The document has " , $doc->getNumOutputs() , " output(s)." , "\n");
for ($i=0; $i< $doc->getNumOutputs();$i++)
{
  $current = $doc->getOutput($i);
  $tc = $current->getTypeCode();
  if ($tc == $LibSEDML::SEDML_OUTPUT_REPORT){
    $r = ($current);
    print ("\tReport id=" , $current->getId() , " numDataSets=" , $r->getNumDataSets() , "\n");
  }
  elsif ($tc == $LibSEDML::SEDML_OUTPUT_PLOT2D){
    $p = ($current);
    print ("\tPlot2d id=" , $current->getId() , " numCurves=" , $p->getNumCurves() , "\n");
  }
  elsif ($tc == $LibSEDML::SEDML_OUTPUT_PLOT3D){
    $p = ($current);
    print ("\tPlot3d id=" , $current->getId() , " numSurfaces=" , $p->getNumSurfaces() , "\n");
  }
  else {
    print ("\tEncountered unknown output " , $current->getId() , "\n");
  }
}

