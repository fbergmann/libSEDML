/**
 * @file SedVisitor.h
 * @brief Definition of the SedVisitor class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedVisitor
 * @sbmlbrief{} TODO:Definition of the SedVisitor class.
 */



#ifndef SedVisitor_h
#define SedVisitor_h


#ifdef __cplusplus


#include <sedml/SedTypeCodes.h>


LIBSEDML_CPP_NAMESPACE_BEGIN

/**
 * Forward class name declarations avoid cyclic dependencies.
 */

class SedBase;

class SedDocument;
class SedListOf;

class SedModel;
class SedChange;
class SedAddXML;
class SedChangeAttribute;
class SedVariable;
class SedParameter;
class SedSimulation;
class SedUniformTimeCourse;
class SedAlgorithm;
class SedAbstractTask;
class SedTask;
class SedDataGenerator;
class SedOutput;
class SedPlot;
class SedPlot2D;
class SedPlot3D;
class SedAbstractCurve;
class SedCurve;
class SedSurface;
class SedDataSet;
class SedReport;
class SedAlgorithmParameter;
class SedRange;
class SedChangeXML;
class SedRemoveXML;
class SedSetValue;
class SedUniformRange;
class SedVectorRange;
class SedFunctionalRange;
class SedSubTask;
class SedOneStep;
class SedSteadyState;
class SedAnalysis;
class SedRepeatedTask;
class SedComputeChange;
class SedDataDescription;
class SedDataSource;
class SedSlice;
class SedParameterEstimationTask;
class SedObjective;
class SedLeastSquareObjectiveFunction;
class SedAdjustableParameter;
class SedExperimentReference;
class SedFitExperiment;
class SedFitMapping;
class SedBounds;
class SedFigure;
class SedSubPlot;
class SedAxis;
class SedStyle;
class SedLine;
class SedMarker;
class SedFill;
class SedAppliedDimension;
class SedDataRange;
class SedShadedArea;
class SedParameterEstimationResultPlot;
class SedWaterfallPlot;
class SedParameterEstimationReport;


class SedVisitor
{
public:

  /**
   * Destructor method.
   */
  virtual ~SedVisitor ();

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedDocument objects.
   *
   * @param x the SedDocument object to visit.
   */
  virtual void visit (const SedDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedListOf objects.
   *
   * @param x the SedListOf object to visit.
   *
   * @param type the object type code.
   */
  virtual void visit (const SedListOf       &x, int type);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedBase objects.
   *
   * @param x the SedBase object to visit.
   */
  virtual bool visit (const SedBase                    &x);



/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedModel &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedChange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedAddXML &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedChangeAttribute &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedVariable &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedParameter &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedSimulation &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedUniformTimeCourse &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedAlgorithm &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedAbstractTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedDataGenerator &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedOutput &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedPlot &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedPlot2D &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedPlot3D &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedAbstractCurve &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedCurve &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedSurface &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedDataSet &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedReport &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedAlgorithmParameter &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedChangeXML &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedRemoveXML &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedSetValue &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedUniformRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedVectorRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedFunctionalRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedSubTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedOneStep &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedSteadyState &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit(const SedAnalysis& x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedRepeatedTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedComputeChange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedDataDescription &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedDataSource &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedSlice &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedParameterEstimationTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedObjective &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedLeastSquareObjectiveFunction &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedAdjustableParameter &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedExperimentReference &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedFitExperiment &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedFitMapping &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedBounds &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedFigure &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedSubPlot &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedAxis &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedStyle &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedLine &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedMarker &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedFill &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedAppliedDimension &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedDataRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedShadedArea &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedParameterEstimationResultPlot &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedWaterfallPlot &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to visit.
 */
virtual bool visit (const SedParameterEstimationReport &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedDocument objects.
   *
   * @param x the SedDocument object to visit.
   */
  virtual void leave (const SedDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on Reaction objects.
   *
   * @param x the Reaction object to visit.
   */
  virtual void leave (const SedBase     &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedListOf objects.
   *
   * @param x the SedListOf object to visit.
   *
   * @param type the object type code.
   *
   */
  virtual void leave (const SedListOf &x, int type);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedModel &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedChange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedAddXML &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedChangeAttribute &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedVariable &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedParameter &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedSimulation &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedUniformTimeCourse &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedAlgorithm &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedAbstractTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedDataGenerator &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedOutput &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedPlot &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedPlot2D &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedPlot3D &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedAbstractCurve &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedCurve &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedSurface &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedDataSet &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedReport &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedAlgorithmParameter &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedChangeXML &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedRemoveXML &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedSetValue &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedUniformRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedVectorRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedFunctionalRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedSubTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedOneStep &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedSteadyState &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave(const SedAnalysis& x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedRepeatedTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedComputeChange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedDataDescription &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedDataSource &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedSlice &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedParameterEstimationTask &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedObjective &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedLeastSquareObjectiveFunction &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedAdjustableParameter &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedExperimentReference &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedFitExperiment &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedFitMapping &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedBounds &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedFigure &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedSubPlot &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedAxis &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedStyle &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedLine &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedMarker &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedFill &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedAppliedDimension &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedDataRange &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedShadedArea &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedParameterEstimationResultPlot &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedWaterfallPlot &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedBase objects.
 *
 * @param x the SedBase object to leave.
 */
virtual void leave (const SedParameterEstimationReport &x);
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* SedVisitor_h */

