#!/usr/bin/env python
#
# @file   strFunctions.py
# @brief  Create the directory structure for package code
# @author Sarah Keating
#

import sys

def cap(word):
  capWord = word[0].upper() + word[1:len(word)]
  return capWord
  
  
def lowerFirst(word):
  capWord = word[0].lower() + word[1:len(word)]
  return capWord

def getIndent(element):
  s1 = '{0}('.format(element)
  indent = ''
  for i in range(0, len(s1)):
    indent = indent + ' ';
  return indent;

def objAbbrev(element):
  abbrev = ''
  for i in range (0, len(element)):
    if element[i].isupper():
      abbrev = abbrev + element[i]
  return abbrev.lower()
    
  