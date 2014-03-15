#!/usr/bin/env python
#
# @file   fileHeaders.py
# @brief  Create the directory structure for package code
# @author Sarah Keating
#

import sys

def addFilename(outFile, filename, element):
  outFile.write('/**\n')
  outFile.write(' * @file:   {0}\n'.format(filename))
  outFile.write(' * @brief:  Implementation of the {0} class\n'.format(element))
  outFile.write(' * @author: Frank T. Bergmann\n *\n')
  
def addLicence(outFile):
  outFile.write(' * <!--------------------------------------------------------------------------\n')
  outFile.write(' * This file is part of libSEDML.  Please visit http://sed-ml.org for more\n')
  outFile.write(' * information about SED-ML. The latest version of libSEDML can be found on \n')
  outFile.write(' * github: https://github.com/fbergmann/libSEDML/\n')
  outFile.write(' *\n')
  outFile.write(' * Copyright (c) 2013-2014, Frank T. Bergmann  \n')
  outFile.write(' * All rights reserved.\n')
  outFile.write(' * \n')
  outFile.write(' * Redistribution and use in source and binary forms, with or without\n')
  outFile.write(' * modification, are permitted provided that the following conditions are met: \n')
  outFile.write(' * \n')
  outFile.write(' * 1. Redistributions of source code must retain the above copyright notice, this\n')
  outFile.write(' *    list of conditions and the following disclaimer. \n')
  outFile.write(' * 2. Redistributions in binary form must reproduce the above copyright notice,\n')
  outFile.write(' *    this list of conditions and the following disclaimer in the documentation\n')
  outFile.write(' *    and/or other materials provided with the distribution. \n')
  outFile.write(' * \n')
  outFile.write(' * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND\n')
  outFile.write(' * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED\n')
  outFile.write(' * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE\n')
  outFile.write(' * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR\n')
  outFile.write(' * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES\n')
  outFile.write(' * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;\n')
  outFile.write(' * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND\n')
  outFile.write(' * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n')
  outFile.write(' * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS\n')
  outFile.write(' * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n')
  outFile.write(' * ------------------------------------------------------------------------ -->\n')
  outFile.write(' */\n')
  