/**
 * @file    create_nested_task->cpp
 * @brief   creates a SED-ML document with nested task->
 * @author  Frank T-> Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML->  Please visit http://sed-ml->org for more
 * information about SED-ML, and the latest version of libSEDML->
 *
 * Copyright (c) 2013, Frank T-> Bergmann
 * All rights reserved->
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1-> Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer->
 * 2-> Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution->
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED-> IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE->
 * ------------------------------------------------------------------------ -->
 */


#include <iostream>
#include <string>
#include <sedml/SedTypes.h>
#include <sbml/math/FormulaParser.h>


void create_nested_task(const std::string& file_name)
{
    auto* doc = new SedDocument(1, 4);

    // create simulation
    auto* sim = doc->createSteadyState();
    sim->setId("steady1");
    
    // need to set the correct KISAO Term
    auto* alg = sim->createAlgorithm();
    alg->setKisaoID("KISAO:0000282");

    // create model
    auto* model = doc->createModel();
    model->setId("model1");
    model->setLanguage("urn:sedml:language:sbml");
    model->setSource("oscli.xml");

    // create tasks
    {
    auto* task = doc->createTask();
    task->setId("task0");
    task->setModelReference("model1");
    task->setSimulationReference("steady1");
    }

    {
    auto* task = doc->createRepeatedTask();
    task->setId("task1");
    task->setResetModel(true);
    task->setRangeId("current");

    auto* range = task->createUniformRange();
    range->setId("current");
    range->setStart(0);
    range->setEnd(0);
    range->setNumberOfSteps(100);
    range->setType("linear");

    auto* change = task->createTaskChange();
    change->setModelReference("model1");
    change->setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id=&quot;J0_v0&quot;]");
    change->setRange("current");
    change->setMath(SBML_parseFormula("current + var1"));
    
    auto* var = change->createVariable();
    var->setId("var1");
    var->setTarget("/sbml:sbml/sbml:model/sbml:listOfParameters/sbml:parameter[@id=&quot;J0_v0&quot;]");

    auto* subtask = task->createSubTask();
    subtask->setOrder(1);
    subtask->setTask("task0");
    }

    // write doc
    writeSedML(doc, file_name.c_str());
}

int main (int argc, const char* argv[])
{
  create_nested_task("nested_task.xml");
  return 0;
}