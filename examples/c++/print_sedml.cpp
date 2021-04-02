/**
 * @file    print_sedml.cpp
 * @brief   Prints an overview of the elments in the given SED-ML document
 * @author  Frank T. Bergmann
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SED-ML, and the latest version of libSEDML.
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
#include <vector>

#include <sbml/SBMLTypes.h>
LIBSBML_CPP_NAMESPACE_USE

#include <sedml/SedTypes.h>
LIBSEDML_CPP_NAMESPACE_USE

using namespace std;

void printRepeatedTask(const SedRepeatedTask* repeat)
{
  cout << "\tRepeatedTask id='" << repeat->getId() 
       << "' resetModel: '" << (repeat->getResetModel() ? "true" : "false") 
	  << "' range: '" << repeat->getRangeId() << "'" << endl;
  
  for (unsigned int i = 0; i < repeat->getNumRanges(); ++i)
  {
	const SedRange* current = repeat->getRange(i);
	const SedFunctionalRange* functional = dynamic_cast<const SedFunctionalRange*>(current);
	const SedVectorRange* vrange = dynamic_cast<const SedVectorRange*>(current);
	const SedUniformRange* urange = dynamic_cast<const SedUniformRange*>(current);
	if (functional != NULL)
	{
		cout << "\t\tFunctionalRange id='" << functional->getId() << "' range='" << functional->getRange() << "' math='" <<  SBML_formulaToString(functional->getMath()) << "'" << endl;
	}
	else if (vrange != NULL)
	{
		cout << "\t\tVectorRange id='" << vrange->getId() << "' values="; 
		const vector<double>& values = vrange->getValues();
		for (vector<double>::const_iterator it = values.begin(); it != values.end(); ++it)
			cout << *it << ", ";
		cout << endl;
	}
	else if (urange != NULL)
	{
		cout << "\t\tUniformRange id='" << urange->getId() << "' start='" << urange->getStart() << "' end='" << urange->getEnd() << "' numPoints='" << urange->getNumberOfPoints() << "' type='" << urange->getType() << "'" << endl;
	}
	
  }
  cout << endl;
  for (unsigned int i = 0; i < repeat->getNumTaskChanges(); ++i)
  {
	const SedSetValue* current = repeat->getTaskChange(i);
	cout << "\t\tSetvalue range='" << current->getRange() << "' modelReference='" << current->getModelReference() << "' target='" << current->getTarget() << " math='" << SBML_formulaToString(current->getMath()) <<"'" << endl;
  for (unsigned int j = 0; j < current->getNumVariables(); ++j)
  {
    const SedVariable* var = current->getVariable(j);
    cout << "\t\t\tSetVariable id='" << var->getId() << "'" << std::endl;
  }
  for (unsigned int j = 0; j < current->getNumParameters(); ++j)
  {
    const SedParameter* p = current->getParameter(j);
    cout << "\t\t\tSedParameter id='" << p->getId() << "'" << std::endl;
  }
  }
  cout << endl;
  for (unsigned int i = 0; i < repeat->getNumSubTasks(); ++i)
  {
	const SedSubTask* current = repeat->getSubTask(i);
	cout << "\t\tSubTask order='" << current->getOrder() << "' task='" << current->getTask() << "'" << endl;
  }

}
void printAnnotation(const XMLNode& node)
{
  cout << "annotation element: '" << node.getName() << "'" << endl;

  for (int i = 0; i < node.getAttributesLength(); ++i)
  {
    cout << "\tattribute '" << node.getAttrName(i) << "' value: '" << node.getAttrValue(i) << "'" << endl;
  }

  for (unsigned int i = 0; i < node.getNumChildren(); ++i)
  {
    printAnnotation(node.getChild(i));
  }
}

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cout << endl << "Usage: print_sedml input-filename"
         << endl << endl;
    return 2;
  }

  SedDocument *doc = readSedML(argv[1]);
  if ( doc->getErrorLog()->getNumFailsWithSeverity(LIBSEDML_SEV_ERROR) > 0)
  {
    cout << doc->getErrorLog()->toString();
    return 2; 
  }

  if (doc->getNumErrors() > 0)
  {
    cout << "Warnings: " << doc->getErrorLog()->toString() << endl;
  }

  if (doc->isSetAnnotation())
  {
    cout << "document has annotation: " << doc->getAnnotationString() << endl;

    const XMLNode& node = *doc->getAnnotation();
    printAnnotation(node);

  }

  cout << "The document has " << doc->getNumSimulations() << " simulation(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumSimulations(); ++i)
  {
    SedSimulation* current = doc->getSimulation(i);
    if (current->isSetAnnotation())
      printAnnotation(*current->getAnnotation());

    if (current->isSetAlgorithm())
    {
      const SedAlgorithm* alg = current->getAlgorithm();
      if (alg->isSetAnnotation())
      {
        printAnnotation(*alg->getAnnotation());
      }
    }

    switch(current->getTypeCode())
    {
       case SEDML_SIMULATION_UNIFORMTIMECOURSE:
       {
          SedUniformTimeCourse* tc = static_cast<SedUniformTimeCourse*>(current);
          cout << "\tTimecourse id=" << tc->getId() << " start=" << tc->getOutputStartTime() << " end=" << tc->getOutputEndTime() << " numPoints=" << tc->getNumberOfPoints() << " kisao=" << (tc->isSetAlgorithm() ? tc->getAlgorithm()->getKisaoID() : std::string("none")) << endl;
          break;
       }
       default:
          cout << "\tUncountered unknown simulation. " << current->getId() << endl;
          break;
    }
  }
  
  cout << endl;
  cout << "The document has " << doc->getNumModels() << " model(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumModels(); ++i)
  {
    SedModel* current = doc->getModel(i);
    cout << "\tModel id=" << current->getId() << " language=" << current->getLanguage() << " source=" << current->getSource() << " numChanges=" << current->getNumChanges() << endl;
    for (unsigned int j = 0; j < current->getNumChanges(); ++j)
    {
      SedChange* change = current->getChange(j);
      cout << "\t\tchange " << (j + 1) << " target: " << change->getTarget();
      switch (change->getTypeCode())
      {
      case SEDML_CHANGE_ADDXML:
      {
        SedAddXML* addXML = static_cast<SedAddXML*>(change);
        cout << " adds the following child: " << endl << endl << "\t\t\t"
          << addXML->getNewXML()->toXMLString() << endl;
        break;
      }
      case SEDML_CHANGE_ATTRIBUTE:
      {
        SedChangeAttribute* changeAttribute = static_cast<SedChangeAttribute*>(change);
        cout << " changes the attribute to: " << changeAttribute->getNewValue();
        break;
      }
      case SEDML_CHANGE_CHANGEXML:
      {
        SedChangeXML* changeXML = static_cast<SedChangeXML*>(change);
        cout << " replaces the target with: " << endl << endl << "\t\t\t"
          << changeXML->getNewXML()->toXMLString() << endl;
        break;
        break;
      }
      case SEDML_CHANGE_COMPUTECHANGE:
      {
        SedComputeChange* computeChange = static_cast<SedComputeChange*>(change);
        cout << " replaces the value with the computation: " << SBML_formulaToString(computeChange->getMath());
        break;
      }
      case SEDML_CHANGE_REMOVEXML:
        cout << " removes the target!";
        break;
      default:
        cout << " is of unknown type!";
        break;
      }
      cout << endl;
    }
  }
  
  cout << endl;
  cout << "The document has " << doc->getNumTasks() << " task(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumTasks(); ++i)
  {
    SedAbstractTask* abstract = doc->getTask(i);
    SedRepeatedTask* repeat = dynamic_cast<SedRepeatedTask*>(abstract);
    if (repeat != NULL)
    {
      printRepeatedTask(repeat);
    }
    else
    {
      SedTask* current = dynamic_cast<SedTask*>(abstract);
      if (current == NULL) continue;
      cout << "\tTask id=" << current->getId() << " model=" << current->getModelReference() << " sim=" << current->getSimulationReference() << endl;
    }
  }

  cout << endl;
  cout << "The document has " << doc->getNumDataGenerators() << " datagenerators(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumDataGenerators(); ++i)
  {
    SedDataGenerator* current = doc->getDataGenerator(i);
    cout << "\tDG id=" << current->getId() << " math=" << SBML_formulaToString(current->getMath()) << endl;
  }
  
  cout << endl;
  cout << "The document has " << doc->getNumOutputs() << " output(s)." << endl;
  for (unsigned int i = 0; i < doc->getNumOutputs(); ++i)
  {
    SedOutput* current = doc->getOutput(i);
    switch(current->getTypeCode())
    {
      case SEDML_OUTPUT_REPORT:
      {
        SedReport* r = static_cast<SedReport*>(current);
        cout << "\tReport id=" << current->getId() << " numDataSets=" << r->getNumDataSets() << endl;
        break;
      }
      case SEDML_OUTPUT_PLOT2D:
      {
        SedPlot2D* p = static_cast<SedPlot2D*>(current);
        cout << "\tPlot2d id=" << current->getId() << " numCurves=" << p->getNumCurves() << endl;
        break;
      }
      case SEDML_OUTPUT_PLOT3D:
      {
        SedPlot3D* p = static_cast<SedPlot3D*>(current);
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
