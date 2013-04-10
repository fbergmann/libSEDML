/**
 * @file   SedVisitor.cpp
 * @brief  Visitor Design Pattern for the Sed object tree  
 * @author Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSed.  Please visit http://sbml.org for more
 * information about Sed, and the latest version of libSed.
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

#include <sedml/SedVisitor.h>
#include <sedml/SedTypes.h>


LIBSEDML_CPP_NAMESPACE_BEGIN

SedVisitor::~SedVisitor ()
{
}


void
SedVisitor::visit (const SedDocument& x)
{
  visit( static_cast<const SedBase&>(x) );
}


void
SedVisitor::visit (const SedListOf& x, int type)
{
  visit( static_cast<const SedBase&>(x) );
}


bool
SedVisitor::visit (const SedBase& sb)
{
  return false;
}


void
SedVisitor::leave (const SedDocument& x)
{
}

void
SedVisitor::leave (const SedBase& x)
{
}


void
SedVisitor::leave (const SedListOf& x, int type)
{
}

LIBSEDML_CPP_NAMESPACE_END
