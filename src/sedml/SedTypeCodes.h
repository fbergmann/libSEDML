/**
 * @file SedTypeCodes.h
 * @brief Definition of the SedTypeCodes class.
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
 * @class SedTypeCodes
 * @sbmlbrief{} TODO:Definition of the SedTypeCodes class.
 */



#ifndef SedTypeCodes_h
#define SedTypeCodes_h


#include <sedml/common/libsedml-config.h>
#include <sedml/common/extern.h>

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * @enum  SedTypeCode_t
 * @brief The enumeration of possible SED-ML core object types.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 *
 */
typedef enum
{
    SEDML_UNKNOWN                    =  0
  , SEDML_DOCUMENT
  , SEDML_MODEL
  , SEDML_CHANGE
  , SEDML_CHANGE_ADDXML
  , SEDML_CHANGE_ATTRIBUTE
  , SEDML_VARIABLE
  , SEDML_PARAMETER
  , SEDML_SIMULATION
  , SEDML_SIMULATION_UNIFORMTIMECOURSE
  , SEDML_SIMULATION_ALGORITHM
  , SEDML_SEDML_ABSTRACTTASK
  , SEDML_TASK
  , SEDML_DATAGENERATOR
  , SEDML_OUTPUT
  , SEDML_OUTPUT_PLOT
  , SEDML_OUTPUT_PLOT2D
  , SEDML_OUTPUT_PLOT3D
  , SEDML_ABSTRACTCURVE
  , SEDML_OUTPUT_CURVE
  , SEDML_OUTPUT_SURFACE
  , SEDML_OUTPUT_DATASET
  , SEDML_OUTPUT_REPORT
  , SEDML_SIMULATION_ALGORITHM_PARAMETER
  , SEDML_RANGE
  , SEDML_CHANGE_CHANGEXML
  , SEDML_CHANGE_REMOVEXML
  , SEDML_TASK_SETVALUE
  , SEDML_RANGE_UNIFORMRANGE
  , SEDML_RANGE_VECTORRANGE
  , SEDML_RANGE_FUNCTIONALRANGE
  , SEDML_TASK_SUBTASK
  , SEDML_SIMULATION_ANALYSIS
  , SEDML_SIMULATION_ONESTEP
  , SEDML_SIMULATION_STEADYSTATE
  , SEDML_TASK_REPEATEDTASK
  , SEDML_CHANGE_COMPUTECHANGE
  , SEDML_DATA_DESCRIPTION
  , SEDML_DATA_SOURCE
  , SEDML_DATA_SLICE
  , SEDML_TASK_PARAMETER_ESTIMATION
  , SEDML_OBJECTIVE
  , SEDML_LEAST_SQUARE_OBJECTIVE
  , SEDML_ADJUSTABLE_PARAMETER
  , SEDML_EXPERIMENT_REFERENCE
  , SEDML_FIT_EXPERIMENT
  , SEDML_FITMAPPING
  , SEDML_BOUNDS
  , SEDML_FIGURE
  , SEDML_SUBPLOT
  , SEDML_AXIS
  , SEDML_STYLE
  , SEDML_LINE
  , SEDML_MARKER
  , SEDML_FILL
  , SEDML_APPLIEDDIMENSION
  , SEDML_DATA_RANGE
  , SEDML_SHADEDAREA
  , SEDML_PARAMETERESTIMATIONRESULTPLOT
  , SEDML_WATERFALLPLOT
  , SEDML_PARAMETERESTIMATIONREPORT
  , SEDML_LIST_OF
} SedTypeCode_t;



/**
 * This method takes an SED-ML type code and returns a string representing
 * the code.
 *
 * @if clike LibSEDML attaches an identifying code to every kind of SED-ML
 * object.  These are known as <em>SED-ML type codes</em>.  The set of
 * possible type codes is defined in the enumeration #SedTypeCode_t.
 * The names of the type codes all begin with the characters @c
 * SEDML_. @endif@if java LibSEDML attaches an identifying code to every
 * kind of SED-ML object.  These are known as <em>SED-ML type codes</em>.  In
 * other languages, the set of type codes is stored in an enumeration; in
 * the Java language interface for libSEDML, the type codes are defined as
 * static integer constants in the interface class {@link
 * libsedmlConstants}.  The names of the type codes all begin with the
 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
 * code to every kind of SED-ML object.  These are known as <em>SED-ML type
 * codes</em>.  In the Python language interface for libSEDML, the type
 * codes are defined as static integer constants in the interface class
 * @link libsedml@endlink.  The names of the type codes all begin with the
 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
 * code to every kind of SED-ML object.  These are known as <em>SED-ML type
 * codes</em>.  In the C# language interface for libSEDML, the type codes
 * are defined as static integer constants in the interface class @link
 * libsedml@endlink.  The names of the type codes all begin with
 * the characters @c SEDML_. @endif@~
 *
 * @return a human readable name for the given
 * @if clike #SedTypeCode_t value@else SED-ML type code@endif.
 *
 * @note The caller does not own the returned string and is therefore not
 * allowed to modify it.
 */
LIBSEDML_EXTERN
const char *
SedTypeCode_toString (int tc);


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* SedTypeCodes_h */
