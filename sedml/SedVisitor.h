/**
 * @file   SedMLVisitor.h
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
 * ---------------------------------------------------------------------- -->
 *
 * @class SedMLVisitor
 * @ingroup Core
 * @brief Support class for performing operations on SedML objects.
 * 
 * <em style='color: #555'>This class of objects is defined by libSedML only
 * and has no direct equivalent in terms of SedML components.</em>
 * 
 * This is a class that supports the use of the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SedML objects.  The LibSedML
 * implementation of the Visitor Pattern couples the notion of visitation
 * with the traversal of an SedML model oject hierarchy.
 *
 * This class (SedMLVisitor) does not provide stand-alone functionality;
 * rather, it defines the interface that user visitor classes must
 * implement.  All of the individual SedML object classes have methods named
 * <code>accept</code> that are used for invoking an object of class
 * SedMLVisitor.  An example of its use is in the SedML validation system,
 * which is internally implemented using this Visitor Pattern facility.
 */

#ifndef SedMLVisitor_h
#define SedMLVisitor_h


#ifdef __cplusplus


#include <sedml/SedMLTypeCodes.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

/**
 * Forward class name declarations avoid cyclic dependencies.
 */

class SedBase;

class SedMLDocument;
class SedListOf;


class SedMLVisitor
{
public:

  /**
   * Destructor method.
   */
  virtual ~SedMLVisitor ();

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedMLDocument objects.
   *
   * @param x the SedMLDocument object to visit.
   */
  virtual void visit (const SedMLDocument &x);

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on ListOf objects.
   *
   * @param x the ListOf object to visit.
   *
   * @param type the object type code.
   */
  virtual void visit (const SedListOf       &x, int type);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedBase objects.
   *
   * @param x the SedBase object to visit.
   */
  virtual bool visit (const SedBase                    &x);

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SedMLDocument objects.
   *
   * @param x the SedMLDocument object to visit.
   */
  virtual void leave (const SedMLDocument &x);

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on Reaction objects.
   *
   * @param x the Reaction object to visit.
   */
  virtual void leave (const SedBase     &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on ListOf objects.
   *
   * @param x the ListOf object to visit.
   *
   * @param type the object type code.
   *
   */
  virtual void leave (const SedListOf &x, int type);
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* SedMLVisitor_h */

