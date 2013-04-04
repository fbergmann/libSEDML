/**
 * @file    print_sedml.cpp
 * @brief   Prints an overview of the elments in the given SED-ML document
 * @author  Frank T. Bergmann
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SEDML, and the latest version of libSEDML.
 *
 * Copyright (c) 2013, Frank T. Bergmann  
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ------------------------------------------------------------------------ -->
 */


#include <iostream>
#include <sedml/SedMLTypes.h>

using namespace std;
LIBSEDML_CPP_NAMESPACE_USE

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << endl << "Usage: print_sedml input-filename"
         << endl << endl;
    return 2;
  }

  SedMLDocument *doc = readSedML(argv[1]);
  if ( doc->getErrorLog()->getNumFailsWithSeverity(LIBSEDML_SEV_ERROR) > 0)
  {
    cout << doc->getErrorLog()->toString();
	return 2; 
  }
  
  cout << "The document has " << doc->getNumSimulations() << " simulation(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumSimulations(); ++i)
  {
    Simulation* current = doc->getSimulation(i);
	switch(current->getTypeCode())
	{
	   case SEDML_SIMULATION_UNIFORMTIMECOURSE:
	   {
	      UniformTimeCourse* tc = static_cast<UniformTimeCourse*>(current);
		  cout << "\tTimecourse id=" << tc->getId() << " start=" << tc->getOutputStartTime() << " end=" << tc->getOutputEndTime() << " numPoints=" << tc->getNumberOfPoints() << endl;
		  break;
	   }
	   default:
			cout << "\tUncountered unknown simulation. " << current->getId() << endl;
			break;
	}
  }
  
  cout << endl;
  cout << "The document has " << doc->getNumSedMLModels() << " model(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumSedMLModels(); ++i)
  {
    SedMLModel* current = doc->getSedMLModel(i);
	cout << "\tModel id=" << current->getId() << " language=" << current->getLanguage() << " source=" << current->getSource() << " numChanges=" << current->getNumChanges() << endl;
  }
  
  cout << endl;
  cout << "The document has " << doc->getNumTasks() << " task(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumTasks(); ++i)
  {
    Task* current = doc->getTask(i);
	cout << "\tTask id=" << current->getId() << " model=" << current->getModelReference() << " sim=" << current->getSimulationReference() << endl;
  }

  cout << endl;
  cout << "The document has " << doc->getNumDataGenerators() << " datagenerators(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumDataGenerators(); ++i)
  {
    DataGenerator* current = doc->getDataGenerator(i);
	cout << "\tDG id=" << current->getId() << " math=" << SBML_formulaToString(current->getMath()) << endl;
  }
  
  cout << endl;
  cout << "The document has " << doc->getNumSedMLOutputs() << " output(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumSedMLOutputs(); ++i)
  {
    SedMLOutput* current = doc->getSedMLOutput(i);
	switch(current->getTypeCode())
	{
	    case SEDML_OUTPUT_REPORT:
		{
			Report* r = static_cast<Report*>(current);
			cout << "\tReport id=" << current->getId() << " numDataSets=" << r->getNumDataSets() << endl;
			break;
	    }
	    case SEDML_OUTPUT_PLOT2D:
		{
			Plot2D* p = static_cast<Plot2D*>(current);
			cout << "\tPlot2d id=" << current->getId() << " numCurves=" << p->getNumSedMLCurves() << endl;
			break;
	    }
	    case SEDML_OUTPUT_PLOT3D:
		{
			Plot3D* p = static_cast<Plot3D*>(current);
			cout << "\tPlot3d id=" << current->getId() << " numSurfaces=" << p->getNumSurfaces() << endl;
			break;
	    }
		default: 
			cout << "\tEncountered unknown output " << current->getId() << endl;
			break;
	}
  }

  return 0;
}
