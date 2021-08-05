/**
 * @file SedmlEnumerations.h
 * @brief Definition of SedmlEnumerations.
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
 * @class SedmlEnumerations
 * @sbmlbrief{sedml} TODO:Definition of SedmlEnumerations.
 */


#ifndef SedmlEnumerations_H__
#define SedmlEnumerations_H__


#include <sedml/common/extern.h>
#include <sedml/SedTypeCodes.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * @enum MappingType_t
 * @brief Enumeration of values permitted as the value of "MappingType_t".
 */
typedef enum
{
  SEDML_MAPPINGTYPE_TIME                        /*!< The sedml mappingtype is @c "time". */
, SEDML_MAPPINGTYPE_EXPERIMENTALCONDITION       /*!< The sedml mappingtype is @c "experimentalCondition". */
, SEDML_MAPPINGTYPE_OBSERVABLE                  /*!< The sedml mappingtype is @c "observable". */
, SEDML_MAPPINGTYPE_INVALID                     /*!< Invalid MappingType value. */
} MappingType_t;


/**
 * Returns the string version of the provided #MappingType_t enumeration.
 *
 * @param mt the #MappingType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "time",
 * "experimentalCondition",
 * "observable",
 * "invalid MappingType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_MAPPINGTYPE_INVALID,
 * MappingType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
MappingType_toString(MappingType_t mt);


/**
 * Returns the #MappingType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #MappingType_t.
 *
 * @return the corresponding #MappingType_t or
 * @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t} if no match is
 * found.
 *
 * @note The matching is case-sensitive: "time" will return
 * @sbmlconstant{SEDML_MAPPINGTYPE_TIME, MappingType_t}, but "Time" will return
 * @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
MappingType_t
MappingType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MappingType_t is valid.
 *
 * @param mt the #MappingType_t enumeration to query.
 *
 * @return @c 1 (true) if the #MappingType_t is
 * @sbmlconstant{SEDML_MAPPINGTYPE_TIME, MappingType_t},
 * @sbmlconstant{SEDML_MAPPINGTYPE_EXPERIMENTALCONDITION, MappingType_t}, or
 * @sbmlconstant{SEDML_MAPPINGTYPE_OBSERVABLE, MappingType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_MAPPINGTYPE_INVALID,
 * MappingType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
MappingType_isValid(MappingType_t mt);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MappingType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "time",
 * "experimentalCondition",
 * "observable", or
 * "invalid MappingType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "time" will return @c 1 (true), but
 * "Time" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
MappingType_isValidString(const char* code);


/**
 * @enum AxisType_t
 * @brief Enumeration of values permitted as the value of "AxisType_t".
 */
typedef enum
{
  SEDML_AXISTYPE_LINEAR        /*!< The sedml axistype is @c "linear". */
, SEDML_AXISTYPE_LOG10         /*!< The sedml axistype is @c "log10". */
, SEDML_AXISTYPE_INVALID       /*!< Invalid AxisType value. */
} AxisType_t;


/**
 * Returns the string version of the provided #AxisType_t enumeration.
 *
 * @param at the #AxisType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "linear",
 * "log10",
 * "invalid AxisType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_AXISTYPE_INVALID, AxisType_t}
 * or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
AxisType_toString(AxisType_t at);


/**
 * Returns the #AxisType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_AXISTYPE_INVALID, AxisType_t} if there is no such match.
 *
 * @param code the string to convert to a #AxisType_t.
 *
 * @return the corresponding #AxisType_t or
 * @sbmlconstant{SEDML_AXISTYPE_INVALID, AxisType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "linear" will return
 * @sbmlconstant{SEDML_AXISTYPE_LINEAR, AxisType_t}, but "Linear" will return
 * @sbmlconstant{SEDML_AXISTYPE_INVALID, AxisType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
AxisType_t
AxisType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #AxisType_t is valid.
 *
 * @param at the #AxisType_t enumeration to query.
 *
 * @return @c 1 (true) if the #AxisType_t is
 * @sbmlconstant{SEDML_AXISTYPE_LINEAR, AxisType_t}, or
 * @sbmlconstant{SEDML_AXISTYPE_LOG10, AxisType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_AXISTYPE_INVALID,
 * AxisType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
AxisType_isValid(AxisType_t at);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #AxisType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "linear",
 * "log10", or
 * "invalid AxisType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "linear" will return @c 1 (true), but
 * "Linear" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
AxisType_isValidString(const char* code);


/**
 * @enum LineType_t
 * @brief Enumeration of values permitted as the value of "LineType_t".
 */
typedef enum
{
  SEDML_LINETYPE_NONE             /*!< The sedml linetype is @c "none". */
, SEDML_LINETYPE_SOLID            /*!< The sedml linetype is @c "solid". */
, SEDML_LINETYPE_DASH             /*!< The sedml linetype is @c "dash". */
, SEDML_LINETYPE_DOT              /*!< The sedml linetype is @c "dot". */
, SEDML_LINETYPE_DASHDOT          /*!< The sedml linetype is @c "dashDot". */
, SEDML_LINETYPE_DASHDOTDOT       /*!< The sedml linetype is @c "dashDotDot". */
, SEDML_LINETYPE_INVALID          /*!< Invalid LineType value. */
} LineType_t;


/**
 * Returns the string version of the provided #LineType_t enumeration.
 *
 * @param lt the #LineType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "none",
 * "solid",
 * "dash",
 * "dot",
 * "dashDot",
 * "dashDotDot",
 * "invalid LineType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_LINETYPE_INVALID, LineType_t}
 * or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
LineType_toString(LineType_t lt);


/**
 * Returns the #LineType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_LINETYPE_INVALID, LineType_t} if there is no such match.
 *
 * @param code the string to convert to a #LineType_t.
 *
 * @return the corresponding #LineType_t or
 * @sbmlconstant{SEDML_LINETYPE_INVALID, LineType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "none" will return
 * @sbmlconstant{SEDML_LINETYPE_NONE, LineType_t}, but "None" will return
 * @sbmlconstant{SEDML_LINETYPE_INVALID, LineType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
LineType_t
LineType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #LineType_t is valid.
 *
 * @param lt the #LineType_t enumeration to query.
 *
 * @return @c 1 (true) if the #LineType_t is
 * @sbmlconstant{SEDML_LINETYPE_NONE, LineType_t},
 * @sbmlconstant{SEDML_LINETYPE_SOLID, LineType_t},
 * @sbmlconstant{SEDML_LINETYPE_DASH, LineType_t},
 * @sbmlconstant{SEDML_LINETYPE_DOT, LineType_t},
 * @sbmlconstant{SEDML_LINETYPE_DASHDOT, LineType_t}, or
 * @sbmlconstant{SEDML_LINETYPE_DASHDOTDOT, LineType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_LINETYPE_INVALID,
 * LineType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
LineType_isValid(LineType_t lt);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #LineType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "none",
 * "solid",
 * "dash",
 * "dot",
 * "dashDot",
 * "dashDotDot", or
 * "invalid LineType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "none" will return @c 1 (true), but
 * "None" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
LineType_isValidString(const char* code);


/**
 * @enum MarkerType_t
 * @brief Enumeration of values permitted as the value of "MarkerType_t".
 */
typedef enum
{
  SEDML_MARKERTYPE_NONE                /*!< The sedml markertype is @c "none". */
, SEDML_MARKERTYPE_SQUARE              /*!< The sedml markertype is @c "square". */
, SEDML_MARKERTYPE_CIRCLE              /*!< The sedml markertype is @c "circle". */
, SEDML_MARKERTYPE_DIAMOND             /*!< The sedml markertype is @c "diamond". */
, SEDML_MARKERTYPE_XCROSS              /*!< The sedml markertype is @c "xCross". */
, SEDML_MARKERTYPE_PLUS                /*!< The sedml markertype is @c "plus". */
, SEDML_MARKERTYPE_STAR                /*!< The sedml markertype is @c "star". */
, SEDML_MARKERTYPE_TRIANGLEUP          /*!< The sedml markertype is @c "triangleUp". */
, SEDML_MARKERTYPE_TRIANGLEDOWN        /*!< The sedml markertype is @c "triangleDown". */
, SEDML_MARKERTYPE_TRIANGLELEFT        /*!< The sedml markertype is @c "triangleLeft". */
, SEDML_MARKERTYPE_TRIANGLERIGHT       /*!< The sedml markertype is @c "triangleRight". */
, SEDML_MARKERTYPE_HDASH               /*!< The sedml markertype is @c "hDash". */
, SEDML_MARKERTYPE_VDASH               /*!< The sedml markertype is @c "vDash". */
, SEDML_MARKERTYPE_INVALID             /*!< Invalid MarkerType value. */
} MarkerType_t;


/**
 * Returns the string version of the provided #MarkerType_t enumeration.
 *
 * @param mt the #MarkerType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "none",
 * "square",
 * "circle",
 * "diamond",
 * "xCross",
 * "plus",
 * "star",
 * "triangleUp",
 * "triangleDown",
 * "triangleLeft",
 * "triangleRight",
 * "hDash",
 * "vDash",
 * "invalid MarkerType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_MARKERTYPE_INVALID,
 * MarkerType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
MarkerType_toString(MarkerType_t mt);


/**
 * Returns the #MarkerType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_MARKERTYPE_INVALID, MarkerType_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #MarkerType_t.
 *
 * @return the corresponding #MarkerType_t or
 * @sbmlconstant{SEDML_MARKERTYPE_INVALID, MarkerType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "none" will return
 * @sbmlconstant{SEDML_MARKERTYPE_NONE, MarkerType_t}, but "None" will return
 * @sbmlconstant{SEDML_MARKERTYPE_INVALID, MarkerType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
MarkerType_t
MarkerType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MarkerType_t is valid.
 *
 * @param mt the #MarkerType_t enumeration to query.
 *
 * @return @c 1 (true) if the #MarkerType_t is
 * @sbmlconstant{SEDML_MARKERTYPE_NONE, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_SQUARE, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_CIRCLE, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_DIAMOND, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_XCROSS, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_PLUS, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_STAR, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_TRIANGLEUP, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_TRIANGLEDOWN, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_TRIANGLELEFT, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_TRIANGLERIGHT, MarkerType_t},
 * @sbmlconstant{SEDML_MARKERTYPE_HDASH, MarkerType_t}, or
 * @sbmlconstant{SEDML_MARKERTYPE_VDASH, MarkerType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_MARKERTYPE_INVALID,
 * MarkerType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
MarkerType_isValid(MarkerType_t mt);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MarkerType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "none",
 * "square",
 * "circle",
 * "diamond",
 * "xCross",
 * "plus",
 * "star",
 * "triangleUp",
 * "triangleDown",
 * "triangleLeft",
 * "triangleRight",
 * "hDash",
 * "vDash", or
 * "invalid MarkerType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "none" will return @c 1 (true), but
 * "None" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
MarkerType_isValidString(const char* code);


/**
 * @enum CurveType_t
 * @brief Enumeration of values permitted as the value of "CurveType_t".
 */
typedef enum
{
  SEDML_CURVETYPE_POINTS                     /*!< The sedml curvetype is @c "points". */
, SEDML_CURVETYPE_BAR                        /*!< The sedml curvetype is @c "bar". */
, SEDML_CURVETYPE_BARSTACKED                 /*!< The sedml curvetype is @c "barStacked". */
, SEDML_CURVETYPE_HORIZONTALBAR              /*!< The sedml curvetype is @c "horizontalBar". */
, SEDML_CURVETYPE_HORIZONTALBARSTACKED       /*!< The sedml curvetype is @c "horizontalBarStacked". */
, SEDML_CURVETYPE_INVALID                    /*!< Invalid CurveType value. */
} CurveType_t;


/**
 * Returns the string version of the provided #CurveType_t enumeration.
 *
 * @param ct the #CurveType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "points",
 * "bar",
 * "barStacked",
 * "horizontalBar",
 * "horizontalBarStacked",
 * "invalid CurveType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_CURVETYPE_INVALID,
 * CurveType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
CurveType_toString(CurveType_t ct);


/**
 * Returns the #CurveType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_CURVETYPE_INVALID, CurveType_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #CurveType_t.
 *
 * @return the corresponding #CurveType_t or
 * @sbmlconstant{SEDML_CURVETYPE_INVALID, CurveType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "points" will return
 * @sbmlconstant{SEDML_CURVETYPE_POINTS, CurveType_t}, but "Points" will return
 * @sbmlconstant{SEDML_CURVETYPE_INVALID, CurveType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
CurveType_t
CurveType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #CurveType_t is valid.
 *
 * @param ct the #CurveType_t enumeration to query.
 *
 * @return @c 1 (true) if the #CurveType_t is
 * @sbmlconstant{SEDML_CURVETYPE_POINTS, CurveType_t},
 * @sbmlconstant{SEDML_CURVETYPE_BAR, CurveType_t},
 * @sbmlconstant{SEDML_CURVETYPE_BARSTACKED, CurveType_t},
 * @sbmlconstant{SEDML_CURVETYPE_HORIZONTALBAR, CurveType_t}, or
 * @sbmlconstant{SEDML_CURVETYPE_HORIZONTALBARSTACKED, CurveType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_CURVETYPE_INVALID,
 * CurveType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
CurveType_isValid(CurveType_t ct);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #CurveType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "points",
 * "bar",
 * "barStacked",
 * "horizontalBar",
 * "horizontalBarStacked", or
 * "invalid CurveType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "points" will return @c 1 (true), but
 * "Points" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
CurveType_isValidString(const char* code);


/**
 * @enum SurfaceType_t
 * @brief Enumeration of values permitted as the value of "SurfaceType_t".
 */
typedef enum
{
  SEDML_SURFACETYPE_PARAMETRICCURVE       /*!< The sedml surfacetype is @c "parametricCurve". */
, SEDML_SURFACETYPE_SURFACEMESH           /*!< The sedml surfacetype is @c "surfaceMesh". */
, SEDML_SURFACETYPE_SURFACECONTOUR        /*!< The sedml surfacetype is @c "surfaceContour". */
, SEDML_SURFACETYPE_CONTOUR               /*!< The sedml surfacetype is @c "contour". */
, SEDML_SURFACETYPE_HEATMAP               /*!< The sedml surfacetype is @c "heatMap". */
, SEDML_SURFACETYPE_STACKEDCURVES         /*!< The sedml surfacetype is @c "stackedCurves". */
, SEDML_SURFACETYPE_BAR                   /*!< The sedml surfacetype is @c "bar". */
, SEDML_SURFACETYPE_INVALID               /*!< Invalid SurfaceType value. */
} SurfaceType_t;


/**
 * Returns the string version of the provided #SurfaceType_t enumeration.
 *
 * @param st the #SurfaceType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "parametricCurve",
 * "surfaceMesh",
 * "surfaceContour",
 * "contour",
 * "heatMap",
 * "stackedCurves",
 * "bar",
 * "invalid SurfaceType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_SURFACETYPE_INVALID,
 * SurfaceType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
SurfaceType_toString(SurfaceType_t st);


/**
 * Returns the #SurfaceType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_SURFACETYPE_INVALID, SurfaceType_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #SurfaceType_t.
 *
 * @return the corresponding #SurfaceType_t or
 * @sbmlconstant{SEDML_SURFACETYPE_INVALID, SurfaceType_t} if no match is
 * found.
 *
 * @note The matching is case-sensitive: "parametricCurve" will return
 * @sbmlconstant{SEDML_SURFACETYPE_PARAMETRICCURVE, SurfaceType_t}, but
 * "ParametricCurve" will return @sbmlconstant{SEDML_SURFACETYPE_INVALID,
 * SurfaceType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
SurfaceType_t
SurfaceType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #SurfaceType_t is valid.
 *
 * @param st the #SurfaceType_t enumeration to query.
 *
 * @return @c 1 (true) if the #SurfaceType_t is
 * @sbmlconstant{SEDML_SURFACETYPE_PARAMETRICCURVE, SurfaceType_t},
 * @sbmlconstant{SEDML_SURFACETYPE_SURFACEMESH, SurfaceType_t},
 * @sbmlconstant{SEDML_SURFACETYPE_SURFACECONTOUR, SurfaceType_t},
 * @sbmlconstant{SEDML_SURFACETYPE_CONTOUR, SurfaceType_t},
 * @sbmlconstant{SEDML_SURFACETYPE_HEATMAP, SurfaceType_t},
 * @sbmlconstant{SEDML_SURFACETYPE_STACKEDCURVES, SurfaceType_t}, or
 * @sbmlconstant{SEDML_SURFACETYPE_BAR, SurfaceType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_SURFACETYPE_INVALID,
 * SurfaceType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
SurfaceType_isValid(SurfaceType_t st);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #SurfaceType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "parametricCurve",
 * "surfaceMesh",
 * "surfaceContour",
 * "contour",
 * "heatMap",
 * "stackedCurves",
 * "bar", or
 * "invalid SurfaceType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "parametricCurve" will return @c 1
 * (true), but "ParametricCurve" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
SurfaceType_isValidString(const char* code);


/**
 * @enum ExperimentType_t
 * @brief Enumeration of values permitted as the value of "ExperimentType_t".
 */
typedef enum
{
  SEDML_EXPERIMENTTYPE_STEADYSTATE       /*!< The sedml experimenttype is @c "steadyState". */
, SEDML_EXPERIMENTTYPE_TIMECOURSE        /*!< The sedml experimenttype is @c "timeCourse". */
, SEDML_EXPERIMENTTYPE_INVALID           /*!< Invalid ExperimentType value. */
} ExperimentType_t;


/**
 * Returns the string version of the provided #ExperimentType_t enumeration.
 *
 * @param et the #ExperimentType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "steadyState",
 * "timeCourse",
 * "invalid ExperimentType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID,
 * ExperimentType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
ExperimentType_toString(ExperimentType_t et);


/**
 * Returns the #ExperimentType_t enumeration corresponding to the given string
 * or @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t} if there is
 * no such match.
 *
 * @param code the string to convert to a #ExperimentType_t.
 *
 * @return the corresponding #ExperimentType_t or
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t} if no match is
 * found.
 *
 * @note The matching is case-sensitive: "steadyState" will return
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_STEADYSTATE, ExperimentType_t}, but
 * "SteadyState" will return @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID,
 * ExperimentType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
ExperimentType_t
ExperimentType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #ExperimentType_t is valid.
 *
 * @param et the #ExperimentType_t enumeration to query.
 *
 * @return @c 1 (true) if the #ExperimentType_t is
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_STEADYSTATE, ExperimentType_t}, or
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_TIMECOURSE, ExperimentType_t};
 * @c 0 (false) otherwise (including
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
ExperimentType_isValid(ExperimentType_t et);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #ExperimentType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "steadyState",
 * "timeCourse", or
 * "invalid ExperimentType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "steadyState" will return @c 1 (true),
 * but "SteadyState" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
ExperimentType_isValidString(const char* code);


/**
 * @enum ScaleType_t
 * @brief Enumeration of values permitted as the value of "ScaleType_t".
 */
typedef enum
{
  SEDML_SCALETYPE_LINEAR           /*!< The sedml scaletype is @c "linear". */
, SEDML_SCALETYPE_LOG           /*!< The sedml scaletype is @c "log". */
, SEDML_SCALETYPE_LOG10         /*!< The sedml scaletype is @c "log10". */
, SEDML_SCALETYPE_INVALID       /*!< Invalid ScaleType value. */
} ScaleType_t;


/**
 * Returns the string version of the provided #ScaleType_t enumeration.
 *
 * @param st the #ScaleType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "linear",
 * "log",
 * "log10",
 * "invalid ScaleType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_SCALETYPE_INVALID,
 * ScaleType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
ScaleType_toString(ScaleType_t st);


/**
 * Returns the #ScaleType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_SCALETYPE_INVALID, ScaleType_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #ScaleType_t.
 *
 * @return the corresponding #ScaleType_t or
 * @sbmlconstant{SEDML_SCALETYPE_INVALID, ScaleType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "linear" will return
 * @sbmlconstant{SEDML_SCALETYPE_LINEAR, ScaleType_t}, but "Linear" will return
 * @sbmlconstant{SEDML_SCALETYPE_INVALID, ScaleType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
ScaleType_t
ScaleType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #ScaleType_t is valid.
 *
 * @param st the #ScaleType_t enumeration to query.
 *
 * @return @c 1 (true) if the #ScaleType_t is
 * @sbmlconstant{SEDML_SCALETYPE_LINEAR, ScaleType_t},
 * @sbmlconstant{SEDML_SCALETYPE_LOG, ScaleType_t}, or
 * @sbmlconstant{SEDML_SCALETYPE_LOG10, ScaleType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_SCALETYPE_INVALID,
 * ScaleType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
ScaleType_isValid(ScaleType_t st);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #ScaleType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "linear",
 * "log",
 * "log10", or
 * "invalid ScaleType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "linear" will return @c 1 (true), but
 * "Linear" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
ScaleType_isValidString(const char* code);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SedmlEnumerations_H__ */


