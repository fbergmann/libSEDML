/**
 * \file    list_of_fix.i
 * \brief   fix for using getListOfXXXXXXX methods in scalar and list context
 * \author  TBI {xtof,raim}@tbi.univie.ac.at
 * 
/* Copyright 2007 TBI
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, WITHOUT EVEN THE IMPLIED WARRANTY OF
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  The software and
 * documentation provided hereunder is on an "as is" basis, and the
 * California Institute of Technology and Japan Science and Technology
 * Corporation have no obligations to provide maintenance, support,
 * updates, enhancements or modifications.  In no event shall the
 * California Institute of Technology or the Japan Science and Technology
 * Corporation be liable to any party for direct, indirect, special,
 * incidental or consequential damages, including lost profits, arising
 * out of the use of this software and its documentation, even if the
 * California Institute of Technology and/or Japan Science and Technology
 * Corporation have been advised of the possibility of such damage. See
 * the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The original code contained here was initially developed by:
 *
 *     Christoph Flamm and Rainer Machne
 *
 * Contributor(s):
 */

// ----------------------------------------------------------------------
// Model::getListOfXXXXXXX
//
// overwrite all Model::getListOfXXXXXXX functions to make their behave more
// perl-like; getListOfXXXXXXX returns a perl array of the requested objects
// instead of a ListOf-object; getListOfXXXXXXX can now be used in perl loop
// statements to iterate over the list of requested objects.
// ----------------------------------------------------------------------

// %feature("shadow")
// Model::getListOfFunctions()
// %{
//   sub getListOfFunctions {
//     my $lox = LibSEDMLc::Model_getListOfFunctions(@_);
//     my @lox = ();
//     for (my $i=0; $i<$lox->size(); $i++) {
//       push @lox, $lox->get($i);
//     }
//     return wantarray ? @lox : $lox;
//   }
// %}
// 
//
// ASTNode::getListOfNodes
//

%feature("shadow")
ASTNode::getListOfNodes()
%{
  sub getListOfNodes {
    my $lox = LibSEDMLc::ASTNode_getListOfNodes(@_);
    my @lox = ();
    for (my $i=0; $i<$lox->size(); $i++) {
      push @lox, $lox->get($i);
    }
    return wantarray ? @lox : $lox;
  }
%}
