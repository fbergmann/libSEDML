/**
 * @file    libsedml-namespace.h
 * @brief   Defines C++ namespace of libSEDML
 * @author  Akiya Jouraku
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
 *------------------------------------------------------------------------- -->
 *
 */

#ifndef LIBSEDML_NAMESPACE_H
#define LIBSEDML_NAMESPACE_H 1

/*
 *
 * The idea of the following marcors are borrowed from 
 * Xerces-C++ XML Parser (http://xerces.apache.org/xerces-c/).
 *
 */

/* Define to enable libSEDML C++ namespace */
/* #undef LIBSEDML_USE_CPP_NAMESPACE */


#if defined(__cplusplus) && defined(LIBSEDML_USE_CPP_NAMESPACE) && !defined(SWIG)
  /* C++ namespace of libSEDML */
  #define LIBSEDML_CPP_NAMESPACE            libsedml
  #define LIBSEDML_CPP_NAMESPACE_BEGIN      namespace LIBSEDML_CPP_NAMESPACE {
  #define LIBSEDML_CPP_NAMESPACE_END        }
  #define LIBSEDML_CPP_NAMESPACE_USE        using namespace LIBSEDML_CPP_NAMESPACE;
  #define LIBSEDML_CPP_NAMESPACE_QUALIFIER  LIBSEDML_CPP_NAMESPACE::

  namespace LIBSEDML_CPP_NAMESPACE {}
#else
  #define LIBSEDML_CPP_NAMESPACE 
  #define LIBSEDML_CPP_NAMESPACE_BEGIN
  #define LIBSEDML_CPP_NAMESPACE_END  
  #define LIBSEDML_CPP_NAMESPACE_USE 
  #define LIBSEDML_CPP_NAMESPACE_QUALIFIER 
#endif


#endif  /* LIBSEDML_NAMESPACE_H */

