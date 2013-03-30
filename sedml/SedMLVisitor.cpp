/**
 * @file   SedMLVisitor.cpp
 * @brief  Visitor Design Pattern for the SedML object tree  
 * @author Ben Bornstein
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

#include <sedml/SedMLVisitor.h>
#include <sedml/SedMLDocument.h>
#include <sedml/Model.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

SedMLVisitor::~SedMLVisitor ()
{
}


void
SedMLVisitor::visit (const SedMLDocument& x)
{
  visit( static_cast<const SedBase&>(x) );
}


void
SedMLVisitor::visit (const SedListOf& x, int type)
{
  visit( static_cast<const SedBase&>(x) );
}


bool
SedMLVisitor::visit (const SedBase& sb)
{
  return false;
}


void
SedMLVisitor::leave (const SedMLDocument& x)
{
}

void
SedMLVisitor::leave (const SedBase& x)
{
}


void
SedMLVisitor::leave (const SedListOf& x, int type)
{
}

LIBSEDML_CPP_NAMESPACE_END
