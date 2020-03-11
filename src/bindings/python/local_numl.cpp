/**
 * @file    local_numl.cpp
 * @brief   Python-specific SWIG support code for wrapping libNUML API
 * @author  Ben Bornstein
 * @author  Ben Kovitz
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libNUML.  Please visit http://sbml.org for more
 * information about NUML, and the latest version of libNUML.
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
 * and also available online as http://numl.org/software/libnuml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <cstddef>
#include "numl/NMBase.h"
#include "numl/NUMLTypes.h"

/**
 * @return the most specific Swig type for the given NMBase object.
 */
struct swig_type_info* GetNumlDowncastSwigType (NMBase* sb)
{
  if (sb == 0) return SWIGTYPE_p_NMBase;
  
  std::string name;

    switch (sb->getTypeCode())
    {
      case NUML_DOCUMENT:
        return SWIGTYPE_p_NUMLDocument;
  
      case NUML_RESULTCOMPONENT:
    	  return SWIGTYPE_p_ResultComponent;

      case NUML_ONTOLOGYTERM:
    	  return SWIGTYPE_p_OntologyTerm;

      case NUML_DIMENSION:
        return SWIGTYPE_p_Dimension;
  
      case NUML_DIMENSIONDESCRIPTION:
        return SWIGTYPE_p_DimensionDescription;

      case NUML_COMPOSITEDESCRIPTION:
        return SWIGTYPE_p_CompositeDescription;
  
      case NUML_COMPOSITEVALUE:
        return SWIGTYPE_p_CompositeValue;
  
      case NUML_TUPLEDESCRIPTION:
        return SWIGTYPE_p_TupleDescription;
  
      case NUML_TUPLE:
        return SWIGTYPE_p_Tuple;
  
      case NUML_ATOMICDESCRIPTION:
        return SWIGTYPE_p_AtomicDescription;
  
      case NUML_ATOMICVALUE:
        return SWIGTYPE_p_AtomicValue;
		
      case NUML_NUMLLIST:
    	  name = sb->getElementName();
    	  if(name == "NUMLList"){
    		  return SWIGTYPE_p_NUMLList;
    	  }
    	  else if(name == "resultComponents"){
    		  return SWIGTYPE_p_ResultComponents;
    	  }
    	  else if(name=="ontologyTerms"){
    	  	  return SWIGTYPE_p_OntologyTerms;
    	  }
    	  else if(name=="dimension"){
    		  return SWIGTYPE_p_Dimension;
    	  }
    	  else if(name=="dimensionDescription"){
    		  return SWIGTYPE_p_DimensionDescription;
    	  }
    	  else if(name=="compositeDescription"){
    		  return SWIGTYPE_p_CompositeDescription;
    	  }
    	  else if(name=="compositeValue"){
    		  return SWIGTYPE_p_CompositeValue;
    	  }
    	  else if(name=="tupleDescription"){
    		  return SWIGTYPE_p_TupleDescription;
    	  }
    	  else if(name=="tuple"){
    		  return SWIGTYPE_p_Tuple;
    	  }
    	  else if(name=="atomicDescription"){
    		  return SWIGTYPE_p_AtomicDescription;
    	  }
    	  else if(name=="atomicValue"){
    		  return SWIGTYPE_p_AtomicValue;
    	  }
    	  return SWIGTYPE_p_NUMLList;

      default:
    	   return SWIGTYPE_p_NMBase;
    }

    return SWIGTYPE_p_NMBase;
}

/* Compatibility bug fix for swig 2.0.7 and Python 3. 
 * See http://patch-tracker.debian.org/patch/series/view/swig2.0/2.0.7-3/pyint_fromsize_t.diff
 */
#if (PY_MAJOR_VERSION >= 3)
#define PyInt_FromSize_t(x) PyLong_FromSize_t(x)
#endif
