/**
 * @file    sedmlfwd.h
 * @brief   Forward declarations for all opaque C types.
 * @author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SEDML, and the latest version of libSEDML.
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
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sedml.org/software/libsedml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * Declaring all types up-front avoids compilation errors of the form
 * <em>"Redefinition of type 'Foo'"</em>, and allows our combined C/C++
 * headers to depend minimally upon each other.  Put another way, the type
 * definitions below serve the same purpose as <tt>class Foo;</tt> forward
 * declarations in C++ code.
 */

#ifndef sedmlfwd_h
#define sedmlfwd_h


#include <sedml/common/libsedml-namespace.h>
#include <sedml/common/libsedml-config.h>


#ifdef __cplusplus
/**
 * Defined as a class when compiling for C++ and as a C struct when
 * compiling for C.
 */
#  define CLASS_OR_STRUCT class
#else
/**
 * Defined as a class when compiling for C++ and as a C struct when
 * compiling for C.
 */
#  define CLASS_OR_STRUCT struct
#endif  /* __cplusplus */

LIBSEDML_CPP_NAMESPACE_BEGIN

/**
 * @var typedef class SBase SBase_t
 * @copydoc SBase
 */
typedef CLASS_OR_STRUCT SedBase                     SedBase_t;

/**
 * @var typedef class SedMLNamespaces SedMLNamespaces_t
 * @copydoc SedMLNamespaces
 */
typedef CLASS_OR_STRUCT SedMLNamespaces              SedMLNamespaces_t;

/**
 * @var typedef class SedListOf SedListOf_t
 * @copydoc SedListOf
 */
typedef CLASS_OR_STRUCT SedListOf              SedListOf_t;


/**
 * @var typedef class SEDMLDocument SEDMLDocument_t
 * @copydoc SEDMLDocument
 */
typedef CLASS_OR_STRUCT SedMLDocument              SedMLDocument_t;


/**
 * @var typedef class Model Model_t
 * @copydoc Model
 */
typedef CLASS_OR_STRUCT Model                     Model_t;


/**
 * @var typedef class DataGenerator DataGenerator_t
 * @copydoc DataGenerator
 */
typedef CLASS_OR_STRUCT DataGenerator                     DataGenerator_t;


/**
 * @var typedef class Task Task_t
 * @copydoc Task
 */
typedef CLASS_OR_STRUCT Task                     Task_t;


/**
 * @var typedef class Simulation Simulation_t
 * @copydoc Simulation
 */
typedef CLASS_OR_STRUCT Simulation                     Simulation_t;

/**
 * @var typedef class Output Output_t
 * @copydoc Output
 */
typedef CLASS_OR_STRUCT Output                     Output_t;

LIBSEDML_CPP_NAMESPACE_END

#undef CLASS_OR_STRUCT

#endif  /* sedmlfwd_h  */

