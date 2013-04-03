/**
 * @file    SedMLTypeCodes.h
 * @brief   Enumeration to identify SedML objects at runtime
 * @author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSedML.  Please visit http://sbml.org for more
 * information about SedML, and the latest version of libSedML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#ifndef SedMLTypeCodes_h
#define SedMLTypeCodes_h


#include <sedml/common/libsedml-config.h>
#include <sedml/common/extern.h>

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * An enumeration of SedML types to help identify SedML objects at runtime.
 * Abstract types do not have a typecode since they cannot be instantiated.
 *
 * (NOTES)
 *
 *  - Each typecode is used as a return value (int) of the following functions
 *
 *     - virtual int SedBase::getTypeCode() const;
 *     - virtual int ListOf::getItemTypeCode() const;
 *
 *    (In libSedML 5, the type of return values in these functions have been changed
 *     from typecode (int) to int for extensibility.)
 *
 *  - Each pacakge extension must define similar enum type for each SedBase subclass
 *    (e.g. SedMLLayoutTypeCode_t for the layout extension, SedMLGroupTypeCode_t for
 *          group extension).
 *
 *  - The value of each typecode can be duplicated between those of different 
 *    packages.
 *
 *  - To distinguish the typecodes of different packages, not only the return
 *    value of getTypeCode() but also that of getPackageName() must be checked
 *    as follows:
 *
 *       void example (const SedBase *sb)
 *       {
 *         cons std::string pkgName = sb->getPackageName();
 *         if (pkgName == "core")
 *         {
 *           switch (sb->getTypeCode())
 *           {
 *             case SEDML_MODEL:
 *                ....
 *                break;
 *             case SEDML_REACTION:
 *                ....
 *           }
 *         } 
 *         else if (pkgName == "layout")
 *         {
 *           switch (sb->getTypeCode())
 *           {
 *             case SEDML_LAYOUT_LAYOUT:
 *                ....
 *                break;
 *             case SEDML_LAYOUT_REACTIONGLYPH:
 *                ....
 *           }
 *         } 
 *         ...
 *       } 
 *      
 */
typedef enum
{
      SEDML_UNKNOWN                      =  0
    , SEDML_DOCUMENT                     =  1
    , SEDML_MODEL                        =  20
    , SEDML_CHANGE                       =  21
    , SEDML_CHANGE_ATTRIBUTE             =  22
    , SEDML_CHANGE_REMOVEXML             =  23
    , SEDML_CHANGE_COMPUTECHANGE         =  24
    , SEDML_DATAGENERATOR                =  30    
    , SEDML_VARIABLE                     =  31
    , SEDML_PARAMETER                    =  32
    , SEDML_TASK                         =  40
    , SEDML_OUTPUT                       =  50
    , SEDML_OUTPUT_DATASET               =  51
    , SEDML_OUTPUT_CURVE                 =  52
    , SEDML_OUTPUT_SURFACE               =  53
    , SEDML_OUTPUT_REPORT                =  54
    , SEDML_OUTPUT_PLOT2D                =  55
    , SEDML_OUTPUT_PLOT3D                =  56
	, SEDML_SIMULATION                   =  60
	, SEDML_SIMULATION_ALGORITHM         =  61
	, SEDML_SIMULATION_UNIFORMTIMECOURSE =  62
	, SEDML_LIST_OF                      =  70
	
} SedMLTypeCode_t;



/**
 * This method takes an SedML type code and returns a string representing
 * the code.
 *
 * @if clike LibSedML attaches an identifying code to every kind of SedML
 * object.  These are known as <em>SedML type codes</em>.  The set of
 * possible type codes is defined in the enumeration #SedMLTypeCode_t.
 * The names of the type codes all begin with the characters @c
 * SEDML_. @endif@if java LibSedML attaches an identifying code to every
 * kind of SedML object.  These are known as <em>SedML type codes</em>.  In
 * other languages, the set of type codes is stored in an enumeration; in
 * the Java language interface for libSedML, the type codes are defined as
 * static integer constants in the interface class {@link
 * libsbmlConstants}.  The names of the type codes all begin with the
 * characters @c SEDML_. @endif@if python LibSedML attaches an identifying
 * code to every kind of SedML object.  These are known as <em>SedML type
 * codes</em>.  In the Python language interface for libSedML, the type
 * codes are defined as static integer constants in the interface class
 * @link libsbml@endlink.  The names of the type codes all begin with the
 * characters @c SEDML_. @endif@if csharp LibSedML attaches an identifying
 * code to every kind of SedML object.  These are known as <em>SedML type
 * codes</em>.  In the C# language interface for libSedML, the type codes
 * are defined as static integer constants in the interface class @link
 * libsbml@endlink.  The names of the type codes all begin with
 * the characters @c SEDML_. @endif@~
 *
 * @return a human readable name for the given
 * @if clike #SedMLTypeCode_t value@else SedML type code@endif.
 *
 * @note The caller does not own the returned string and is therefore not
 * allowed to modify it.
 */
LIBSEDML_EXTERN
const char *
SedMLTypeCode_toString (int tc);


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* SedMLTypeCodes_h */
