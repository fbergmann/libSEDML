/**
 * @file    libsedml-namespace.h
 * @brief   Defines C++ namespace of libSEDML
 */
 

#ifndef LIBSEDML_NAMESPACE_H
#define LIBSEDML_NAMESPACE_H 1

#ifndef SWIG
#include <sbml/common/libsbml-namespace.h>

LIBSBML_CPP_NAMESPACE_USE

#endif
/*
 *
 * The idea of the following marcors are borrowed from 
 * Xerces-C++ XML Parser (http://xerces.apache.org/xerces-c/).
 *
 */

/* Define to enable libSEDML C++ namespace */
#cmakedefine LIBSEDML_USE_CPP_NAMESPACE 1


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

