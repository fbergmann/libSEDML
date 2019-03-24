/**
 * @file SedOperationReturnValues.cpp
 * @brief Implementation of the SedOperationReturnValues class.
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



#include <stdlib.h>
#include <sedml/common/SedOperationReturnValues.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

static SedOperationReturnValues_t SEDML_OPERATION_RETURN_VALUES_INDICES[] = 
{
    LIBSEDML_OPERATION_SUCCESS
  , LIBSEDML_INDEX_EXCEEDS_SIZE
  , LIBSEDML_UNEXPECTED_ATTRIBUTE
  , LIBSEDML_OPERATION_FAILED
  , LIBSEDML_INVALID_ATTRIBUTE_VALUE
  , LIBSEDML_INVALID_OBJECT
  , LIBSEDML_DUPLICATE_OBJECT_ID
  , LIBSEDML_LEVEL_MISMATCH
  , LIBSEDML_VERSION_MISMATCH
  , LIBSEDML_INVALID_XML_OPERATION
  , LIBSEDML_NAMESPACES_MISMATCH
  , LIBSEDML_DUPLICATE_ANNOTATION_NS
  , LIBSEDML_ANNOTATION_NAME_NOT_FOUND
  , LIBSEDML_ANNOTATION_NS_NOT_FOUND
  , LIBSEDML_MISSING_METAID
  , LIBSEDML_DEPRECATED_ATTRIBUTE
};

static const char* SEDML_OPERATION_RETURN_VALUES_STRINGS[] =
{
  /* LIBSEDML_OPERATION_SUCCESS = 0 */
   "The operation was successful. "
  , /*LIBSEDML_INDEX_EXCEEDS_SIZE = -1 */
   "An index parameter exceeded the bounds of a data array or other "
   "collection used in the operation. This return value is typically "
   "returned by methods that take index numbers to refer to lists "
   "of objects, when the caller has provided an index that exceeds "
   "the bounds of the list. LibSEDML provides methods for checking the "
   "size of list/sequence/collection structures, and callers should "
   "verify the sizes before calling methods that take index numbers. "

  , /*LIBSEDML_UNEXPECTED_ATTRIBUTE = -2*/
   "The attribute that is the subject of this operation is not valid "
   "for the combination of Sed Level and Version for the underlying "
   "object. This can happen because libSEDML strives to offer a uniform "
   "API for all Sed Levels and Versions, but some object attributes and "
   "elements are not defined for all Sed Levels and Versions. Calling "
   "programs are expected to be aware of which object structures they "
   "are working with, but when errors of this kind occur, they are "
   "reported using this return value. "

  , /*LIBSEDML_OPERATION_FAILED = -3*/
   "The requested action could not be performed. This can occur in "
   "a variety of contexts, such as passing a null object as a parameter "
   "in a situation where it does not make sense to permit a null object. "
   " "

  , /*LIBSEDML_INVALID_ATTRIBUTE_VALUE = -4*/
   "A value passed as an argument to the method is not of a type that "
   "is valid for the operation or kind of object involved. For example, "
   "this return code is used when a calling program attempts to set an "
   "Sed object identifier to a string whose syntax does not conform to "
   "the Sed identifier syntax. "

  , /*LIBSEDML_INVALID_OBJECT = -5*/
   "The object passed as an argument to the method is not of a type "
   "that is valid for the operation or kind of object involved. For "
   "example, handing an invalidly-constructed ASTNode to a method "
   "expecting an ASTNode will result in this error. "

  , /*LIBSEDML_DUPLICATE_OBJECT_ID = -6*/
   "There already exists an object with this identifier in the "
   "context where this operation is being attempted. This error is "
   "typically returned in situations where Sed object identifiers must be "
   "unique, such as attempting to add two species with the same identifier "
   "to a model. "

  , /*LIBSEDML_LEVEL_MISMATCH = -7*/
   "The Sed Level associated with the object does not match the Level "
   "of the parent object. This error can happen when an Sed component "
   "such as a species or compartment object is created outside of a model "
   "and a calling program then attempts to add the object to a model that "
   "has a different Sed Level defined. "

  , /*LIBSEDML_VERSION_MISMATCH = -8*/
   "The Sed Version within the Sed Level associated with the object "
   "does not match the Version of the parent object. This error can "
   "happen when an Sed component such as a species or compartment object "
   "is created outside of a model and a calling program then attempts to "
   "add the object to a model that has a different Sed Level+Version "
   "combination. "

  , /*LIBSEDML_INVALID_XML_OPERATION = -9*/
   "The XML operation attempted is not valid for the object or context "
   "involved. This error is typically returned by the XML interface layer "
   "of libSEDML, when a calling program attempts to construct or manipulate "
   "XML in an invalid way. "

  , /*LIBSEDML_NAMESPACES_MISMATCH = -10*/
   "The Sed Namespaces associated with the object "
   "do not match the Sed Namespaces of the parent object. This error can "
   "happen when an Sed component such as a species or compartment object "
   "is created outside of a model and a calling program then attempts to "
   "add the object to a model that has a different Sed Namespaces "
   "combination. "

  , /*LIBSEDML_DUPLICATE_ANNOTATION_NS = -11*/
   "There already exists a top level annotation with the same namespace as "
   "annotation being appended. This error is "
   "typically returned in situations where the appendAnnotation function "
   "is being used to add an annotation that has a namespace that is already "
   "present in the existing annotation. "

  , /*LIBSEDML_ANNOTATION_NAME_NOT_FOUND = -12*/
   "The existing annotation does not have a top-level element with "
   "the given name. This error is "
   "typically returned in situations where the "
   "replaceTopLevelAnnotationElement function or "
   "the removeTopLevelAnnotationElement function "
   "is being used to replace or remove an annotation with a name that does "
   "not match the name of any top-level element that is already "
   "present in the existing annotation. "

  , /*LIBSEDML_ANNOTATION_NS_NOT_FOUND = -13*/
   "The existing annotation does not have a top-level element with "
   "the given namespace. This error is "
   "typically returned in situations where the "
   "replaceTopLevelAnnotationElement function or "
   "the removeTopLevelAnnotationElement function "
   "is being used to replace or remove an annotation with a namespace that does "
   "not match the namespace of any top-level element that is already "
   "present in the existing annotation. "

  , /* LIBSEDML_MISSING_METAID   = -14*/
    "The requested action cannot be performed as the target object does not have "
    "the metaid attribute set. "
   
  , /* LIBSEDML_DEPRECATED_ATTRIBUTE   = -15*/
    "The attribute that is the subject of this operation has been deprecated "
    "for the combination of Sed Level and Version for the underlying "
    "object. "
     
};

LIBSEDML_EXTERN
const char *
SedOperationReturnValue_toString (int returnValue)
{
  int length = sizeof(SEDML_OPERATION_RETURN_VALUES_INDICES)/sizeof(SedOperationReturnValues_t);
  for (int i = 0; i < length; ++i)
  {
    if (SEDML_OPERATION_RETURN_VALUES_INDICES[i] == returnValue)
      return SEDML_OPERATION_RETURN_VALUES_STRINGS[i];
  }

  return NULL;
}


LIBSEDML_CPP_NAMESPACE_END

