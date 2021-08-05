/**
 * @file SedmlEnumerations.cpp
 * @brief Implementation of SedmlEnumerations.
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
 */
#include <string>
#include <sedml/common/SedmlEnumerations.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


static
const char* SEDML_MAPPING_TYPE_STRINGS[] =
{
  "time"
, "experimentalCondition"
, "observable"
, "invalid MappingType value"
};


/*
 * Returns the string version of the provided #MappingType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
MappingType_toString(MappingType_t mt)
{
  int min = SEDML_MAPPINGTYPE_TIME;
  int max = SEDML_MAPPINGTYPE_INVALID;

  if (mt < min || mt > max)
  {
    return "(Unknown MappingType value)";
  }

  return SEDML_MAPPING_TYPE_STRINGS[mt - min];
}


/*
 * Returns the #MappingType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t} if there is no such
 * match.
 */
LIBSEDML_EXTERN
MappingType_t
MappingType_fromString(const char* code)
{
  static int size = sizeof(SEDML_MAPPING_TYPE_STRINGS)/sizeof(SEDML_MAPPING_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_MAPPING_TYPE_STRINGS[i])
    {
      return (MappingType_t)(i);
    }
  }

  return SEDML_MAPPINGTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MappingType_t is valid.
 */
LIBSEDML_EXTERN
int
MappingType_isValid(MappingType_t mt)
{
  int min = SEDML_MAPPINGTYPE_TIME;
  int max = SEDML_MAPPINGTYPE_INVALID;

  if (mt < min || mt >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MappingType_t.
 */
LIBSEDML_EXTERN
int
MappingType_isValidString(const char* code)
{
  return MappingType_isValid(MappingType_fromString(code));
}


static
const char* SEDML_AXIS_TYPE_STRINGS[] =
{
  "linear"
, "log10"
, "invalid AxisType value"
};


/*
 * Returns the string version of the provided #AxisType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
AxisType_toString(AxisType_t at)
{
  int min = SEDML_AXISTYPE_LINEAR;
  int max = SEDML_AXISTYPE_INVALID;

  if (at < min || at > max)
  {
    return "(Unknown AxisType value)";
  }

  return SEDML_AXIS_TYPE_STRINGS[at - min];
}


/*
 * Returns the #AxisType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_AXISTYPE_INVALID, AxisType_t} if there is no such match.
 */
LIBSEDML_EXTERN
AxisType_t
AxisType_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_AXIS_TYPE_STRINGS)/sizeof(SEDML_AXIS_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_AXIS_TYPE_STRINGS[i])
    {
      return (AxisType_t)(i);
    }
  }

  return SEDML_AXISTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #AxisType_t is valid.
 */
LIBSEDML_EXTERN
int
AxisType_isValid(AxisType_t at)
{
  int min = SEDML_AXISTYPE_LINEAR;
  int max = SEDML_AXISTYPE_INVALID;

  if (at < min || at >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #AxisType_t.
 */
LIBSEDML_EXTERN
int
AxisType_isValidString(const char* code)
{
  return AxisType_isValid(AxisType_fromString(code));
}


static
const char* SEDML_LINE_TYPE_STRINGS[] =
{
  "none"
, "solid"
, "dash"
, "dot"
, "dashDot"
, "dashDotDot"
, "invalid LineType value"
};


/*
 * Returns the string version of the provided #LineType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
LineType_toString(LineType_t lt)
{
  int min = SEDML_LINETYPE_NONE;
  int max = SEDML_LINETYPE_INVALID;

  if (lt < min || lt > max)
  {
    return "(Unknown LineType value)";
  }

  return SEDML_LINE_TYPE_STRINGS[lt - min];
}


/*
 * Returns the #LineType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_LINETYPE_INVALID, LineType_t} if there is no such match.
 */
LIBSEDML_EXTERN
LineType_t
LineType_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_LINE_TYPE_STRINGS)/sizeof(SEDML_LINE_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_LINE_TYPE_STRINGS[i])
    {
      return (LineType_t)(i);
    }
  }

  return SEDML_LINETYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #LineType_t is valid.
 */
LIBSEDML_EXTERN
int
LineType_isValid(LineType_t lt)
{
  int min = SEDML_LINETYPE_NONE;
  int max = SEDML_LINETYPE_INVALID;

  if (lt < min || lt >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #LineType_t.
 */
LIBSEDML_EXTERN
int
LineType_isValidString(const char* code)
{
  return LineType_isValid(LineType_fromString(code));
}


static
const char* SEDML_MARKER_TYPE_STRINGS[] =
{
  "none"
, "square"
, "circle"
, "diamond"
, "xCross"
, "plus"
, "star"
, "triangleUp"
, "triangleDown"
, "triangleLeft"
, "triangleRight"
, "hDash"
, "vDash"
, "invalid MarkerType value"
};


/*
 * Returns the string version of the provided #MarkerType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
MarkerType_toString(MarkerType_t mt)
{
  int min = SEDML_MARKERTYPE_NONE;
  int max = SEDML_MARKERTYPE_INVALID;

  if (mt < min || mt > max)
  {
    return "(Unknown MarkerType value)";
  }

  return SEDML_MARKER_TYPE_STRINGS[mt - min];
}


/*
 * Returns the #MarkerType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_MARKERTYPE_INVALID, MarkerType_t} if there is no such
 * match.
 */
LIBSEDML_EXTERN
MarkerType_t
MarkerType_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_MARKER_TYPE_STRINGS)/sizeof(SEDML_MARKER_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_MARKER_TYPE_STRINGS[i])
    {
      return (MarkerType_t)(i);
    }
  }

  return SEDML_MARKERTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MarkerType_t is valid.
 */
LIBSEDML_EXTERN
int
MarkerType_isValid(MarkerType_t mt)
{
  int min = SEDML_MARKERTYPE_NONE;
  int max = SEDML_MARKERTYPE_INVALID;

  if (mt < min || mt >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MarkerType_t.
 */
LIBSEDML_EXTERN
int
MarkerType_isValidString(const char* code)
{
  return MarkerType_isValid(MarkerType_fromString(code));
}


static
const char* SEDML_CURVE_TYPE_STRINGS[] =
{
  "points"
, "bar"
, "barStacked"
, "horizontalBar"
, "horizontalBarStacked"
, "invalid CurveType value"
};


/*
 * Returns the string version of the provided #CurveType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
CurveType_toString(CurveType_t ct)
{
  int min = SEDML_CURVETYPE_POINTS;
  int max = SEDML_CURVETYPE_INVALID;

  if (ct < min || ct > max)
  {
    return "(Unknown CurveType value)";
  }

  return SEDML_CURVE_TYPE_STRINGS[ct - min];
}


/*
 * Returns the #CurveType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_CURVETYPE_INVALID, CurveType_t} if there is no such
 * match.
 */
LIBSEDML_EXTERN
CurveType_t
CurveType_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_CURVE_TYPE_STRINGS)/sizeof(SEDML_CURVE_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_CURVE_TYPE_STRINGS[i])
    {
      return (CurveType_t)(i);
    }
  }

  return SEDML_CURVETYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #CurveType_t is valid.
 */
LIBSEDML_EXTERN
int
CurveType_isValid(CurveType_t ct)
{
  int min = SEDML_CURVETYPE_POINTS;
  int max = SEDML_CURVETYPE_INVALID;

  if (ct < min || ct >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #CurveType_t.
 */
LIBSEDML_EXTERN
int
CurveType_isValidString(const char* code)
{
  return CurveType_isValid(CurveType_fromString(code));
}


static
const char* SEDML_SURFACE_TYPE_STRINGS[] =
{
  "parametricCurve"
, "surfaceMesh"
, "surfaceContour"
, "contour"
, "heatMap"
, "stackedCurves"
, "bar"
, "invalid SurfaceType value"
};


/*
 * Returns the string version of the provided #SurfaceType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
SurfaceType_toString(SurfaceType_t st)
{
  int min = SEDML_SURFACETYPE_PARAMETRICCURVE;
  int max = SEDML_SURFACETYPE_INVALID;

  if (st < min || st > max)
  {
    return "(Unknown SurfaceType value)";
  }

  return SEDML_SURFACE_TYPE_STRINGS[st - min];
}


/*
 * Returns the #SurfaceType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_SURFACETYPE_INVALID, SurfaceType_t} if there is no such
 * match.
 */
LIBSEDML_EXTERN
SurfaceType_t
SurfaceType_fromString(const char* code)
{
  static int size = sizeof(SEDML_SURFACE_TYPE_STRINGS)/sizeof(SEDML_SURFACE_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_SURFACE_TYPE_STRINGS[i])
    {
      return (SurfaceType_t)(i);
    }
  }

  return SEDML_SURFACETYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #SurfaceType_t is valid.
 */
LIBSEDML_EXTERN
int
SurfaceType_isValid(SurfaceType_t st)
{
  int min = SEDML_SURFACETYPE_PARAMETRICCURVE;
  int max = SEDML_SURFACETYPE_INVALID;

  if (st < min || st >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #SurfaceType_t.
 */
LIBSEDML_EXTERN
int
SurfaceType_isValidString(const char* code)
{
  return SurfaceType_isValid(SurfaceType_fromString(code));
}


static
const char* SEDML_EXPERIMENT_TYPE_STRINGS[] =
{
  "steadyState"
, "timeCourse"
, "invalid ExperimentType value"
};


/*
 * Returns the string version of the provided #ExperimentType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
ExperimentType_toString(ExperimentType_t et)
{
  int min = SEDML_EXPERIMENTTYPE_STEADYSTATE;
  int max = SEDML_EXPERIMENTTYPE_INVALID;

  if (et < min || et > max)
  {
    return "(Unknown ExperimentType value)";
  }

  return SEDML_EXPERIMENT_TYPE_STRINGS[et - min];
}


/*
 * Returns the #ExperimentType_t enumeration corresponding to the given string
 * or @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t} if there is
 * no such match.
 */
LIBSEDML_EXTERN
ExperimentType_t
ExperimentType_fromString(const char* code)
{
  static int size = sizeof(SEDML_EXPERIMENT_TYPE_STRINGS)/sizeof(SEDML_EXPERIMENT_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_EXPERIMENT_TYPE_STRINGS[i])
    {
      return (ExperimentType_t)(i);
    }
  }

  return SEDML_EXPERIMENTTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #ExperimentType_t is valid.
 */
LIBSEDML_EXTERN
int
ExperimentType_isValid(ExperimentType_t et)
{
  int min = SEDML_EXPERIMENTTYPE_STEADYSTATE;
  int max = SEDML_EXPERIMENTTYPE_INVALID;

  if (et < min || et >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #ExperimentType_t.
 */
LIBSEDML_EXTERN
int
ExperimentType_isValidString(const char* code)
{
  return ExperimentType_isValid(ExperimentType_fromString(code));
}


static
const char* SEDML_SCALE_TYPE_STRINGS[] =
{
  "linear"
, "log"
, "log10"
, "invalid ScaleType value"
};


/*
 * Returns the string version of the provided #ScaleType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
ScaleType_toString(ScaleType_t st)
{
  int min = SEDML_SCALETYPE_LINEAR;
  int max = SEDML_SCALETYPE_INVALID;

  if (st < min || st > max)
  {
    return "(Unknown ScaleType value)";
  }

  return SEDML_SCALE_TYPE_STRINGS[st - min];
}


/*
 * Returns the #ScaleType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_SCALETYPE_INVALID, ScaleType_t} if there is no such
 * match.
 */
LIBSEDML_EXTERN
ScaleType_t
ScaleType_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_SCALE_TYPE_STRINGS)/sizeof(SEDML_SCALE_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_SCALE_TYPE_STRINGS[i])
    {
      return (ScaleType_t)(i);
    }
  }

  return SEDML_SCALETYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #ScaleType_t is valid.
 */
LIBSEDML_EXTERN
int
ScaleType_isValid(ScaleType_t st)
{
  int min = SEDML_SCALETYPE_LINEAR;
  int max = SEDML_SCALETYPE_INVALID;

  if (st < min || st >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #ScaleType_t.
 */
LIBSEDML_EXTERN
int
ScaleType_isValidString(const char* code)
{
  return ScaleType_isValid(ScaleType_fromString(code));
}




LIBSEDML_CPP_NAMESPACE_END


