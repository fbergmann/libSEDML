/**
 * @file SedSubPlot.cpp
 * @brief Implementation of the SedSubPlot class.
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
#include <sedml/SedSubPlot.h>
#include <sedml/SedListOfSubPlots.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSubPlot using the given SED-ML Level and @ p version values.
 */
SedSubPlot::SedSubPlot(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mPlot ("")
  , mRow (SEDML_INT_MAX)
  , mIsSetRow (false)
  , mCol (SEDML_INT_MAX)
  , mIsSetCol (false)
  , mRowSpan (SEDML_INT_MAX)
  , mIsSetRowSpan (false)
  , mColSpan (SEDML_INT_MAX)
  , mIsSetColSpan (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedSubPlot using the given SedNamespaces object @p sedmlns.
 */
SedSubPlot::SedSubPlot(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mPlot ("")
  , mRow (SEDML_INT_MAX)
  , mIsSetRow (false)
  , mCol (SEDML_INT_MAX)
  , mIsSetCol (false)
  , mRowSpan (SEDML_INT_MAX)
  , mIsSetRowSpan (false)
  , mColSpan (SEDML_INT_MAX)
  , mIsSetColSpan (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedSubPlot.
 */
SedSubPlot::SedSubPlot(const SedSubPlot& orig)
  : SedBase( orig )
  , mPlot ( orig.mPlot )
  , mRow ( orig.mRow )
  , mIsSetRow ( orig.mIsSetRow )
  , mCol ( orig.mCol )
  , mIsSetCol ( orig.mIsSetCol )
  , mRowSpan ( orig.mRowSpan )
  , mIsSetRowSpan ( orig.mIsSetRowSpan )
  , mColSpan ( orig.mColSpan )
  , mIsSetColSpan ( orig.mIsSetColSpan )
{
}


/*
 * Assignment operator for SedSubPlot.
 */
SedSubPlot&
SedSubPlot::operator=(const SedSubPlot& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mPlot = rhs.mPlot;
    mRow = rhs.mRow;
    mIsSetRow = rhs.mIsSetRow;
    mCol = rhs.mCol;
    mIsSetCol = rhs.mIsSetCol;
    mRowSpan = rhs.mRowSpan;
    mIsSetRowSpan = rhs.mIsSetRowSpan;
    mColSpan = rhs.mColSpan;
    mIsSetColSpan = rhs.mIsSetColSpan;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSubPlot object.
 */
SedSubPlot*
SedSubPlot::clone() const
{
  return new SedSubPlot(*this);
}


/*
 * Destructor for SedSubPlot.
 */
SedSubPlot::~SedSubPlot()
{
}


/*
 * Returns the value of the "plot" attribute of this SedSubPlot.
 */
const std::string&
SedSubPlot::getPlot() const
{
  return mPlot;
}


/*
 * Returns the value of the "row" attribute of this SedSubPlot.
 */
int
SedSubPlot::getRow() const
{
  return mRow;
}


/*
 * Returns the value of the "col" attribute of this SedSubPlot.
 */
int
SedSubPlot::getCol() const
{
  return mCol;
}


/*
 * Returns the value of the "rowSpan" attribute of this SedSubPlot.
 */
int
SedSubPlot::getRowSpan() const
{
  return mRowSpan;
}


/*
 * Returns the value of the "colSpan" attribute of this SedSubPlot.
 */
int
SedSubPlot::getColSpan() const
{
  return mColSpan;
}


/*
 * Predicate returning @c true if this SedSubPlot's "plot" attribute is set.
 */
bool
SedSubPlot::isSetPlot() const
{
  return (mPlot.empty() == false);
}


/*
 * Predicate returning @c true if this SedSubPlot's "row" attribute is set.
 */
bool
SedSubPlot::isSetRow() const
{
  return mIsSetRow;
}


/*
 * Predicate returning @c true if this SedSubPlot's "col" attribute is set.
 */
bool
SedSubPlot::isSetCol() const
{
  return mIsSetCol;
}


/*
 * Predicate returning @c true if this SedSubPlot's "rowSpan" attribute is set.
 */
bool
SedSubPlot::isSetRowSpan() const
{
  return mIsSetRowSpan;
}


/*
 * Predicate returning @c true if this SedSubPlot's "colSpan" attribute is set.
 */
bool
SedSubPlot::isSetColSpan() const
{
  return mIsSetColSpan;
}


/*
 * Sets the value of the "plot" attribute of this SedSubPlot.
 */
int
SedSubPlot::setPlot(const std::string& plot)
{
  if (!(SyntaxChecker::isValidInternalSId(plot)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mPlot = plot;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "row" attribute of this SedSubPlot.
 */
int
SedSubPlot::setRow(int row)
{
  mRow = row;
  mIsSetRow = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "col" attribute of this SedSubPlot.
 */
int
SedSubPlot::setCol(int col)
{
  mCol = col;
  mIsSetCol = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "rowSpan" attribute of this SedSubPlot.
 */
int
SedSubPlot::setRowSpan(int rowSpan)
{
  mRowSpan = rowSpan;
  mIsSetRowSpan = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "colSpan" attribute of this SedSubPlot.
 */
int
SedSubPlot::setColSpan(int colSpan)
{
  mColSpan = colSpan;
  mIsSetColSpan = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "plot" attribute of this SedSubPlot.
 */
int
SedSubPlot::unsetPlot()
{
  mPlot.erase();

  if (mPlot.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "row" attribute of this SedSubPlot.
 */
int
SedSubPlot::unsetRow()
{
  mRow = SEDML_INT_MAX;
  mIsSetRow = false;

  if (isSetRow() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "col" attribute of this SedSubPlot.
 */
int
SedSubPlot::unsetCol()
{
  mCol = SEDML_INT_MAX;
  mIsSetCol = false;

  if (isSetCol() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "rowSpan" attribute of this SedSubPlot.
 */
int
SedSubPlot::unsetRowSpan()
{
  mRowSpan = SEDML_INT_MAX;
  mIsSetRowSpan = false;

  if (isSetRowSpan() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "colSpan" attribute of this SedSubPlot.
 */
int
SedSubPlot::unsetColSpan()
{
  mColSpan = SEDML_INT_MAX;
  mIsSetColSpan = false;

  if (isSetColSpan() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedSubPlot::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetPlot() && mPlot == oldid)
  {
    setPlot(newid);
  }
}


/*
 * Returns the XML element name of this SedSubPlot object.
 */
const std::string&
SedSubPlot::getElementName() const
{
  static const string name = "subPlot";
  return name;
}


/*
 * Returns the libSEDML type code for this SedSubPlot object.
 */
int
SedSubPlot::getTypeCode() const
{
  return SEDML_SUBPLOT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedSubPlot object have been set.
 */
bool
SedSubPlot::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetPlot() == false)
  {
    allPresent = false;
  }

  if (isSetRow() == false)
  {
    allPresent = false;
  }

  if (isSetCol() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedSubPlot::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedSubPlot::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSubPlot::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "row")
  {
    value = getRow();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "col")
  {
    value = getCol();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "rowSpan")
  {
    value = getRowSpan();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }
  else if (attributeName == "colSpan")
  {
    value = getColSpan();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Gets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SedBase::getAttribute(attributeName, value);

  if (return_value == LIBSEDML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "plot")
  {
    value = getPlot();
    return_value = LIBSEDML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Predicate returning @c true if this SedSubPlot's attribute "attributeName"
 * is set.
 */
bool
SedSubPlot::isSetAttribute(const std::string& attributeName) const
{
  bool value = SedBase::isSetAttribute(attributeName);

  if (attributeName == "plot")
  {
    value = isSetPlot();
  }
  else if (attributeName == "row")
  {
    value = isSetRow();
  }
  else if (attributeName == "col")
  {
    value = isSetCol();
  }
  else if (attributeName == "rowSpan")
  {
    value = isSetRowSpan();
  }
  else if (attributeName == "colSpan")
  {
    value = isSetColSpan();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "row")
  {
    return_value = setRow(value);
  }
  else if (attributeName == "col")
  {
    return_value = setCol(value);
  }
  else if (attributeName == "rowSpan")
  {
    return_value = setRowSpan(value);
  }
  else if (attributeName == "colSpan")
  {
    return_value = setColSpan(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SedBase::setAttribute(attributeName, value);

  if (attributeName == "plot")
  {
    return_value = setPlot(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SedSubPlot.
 */
int
SedSubPlot::unsetAttribute(const std::string& attributeName)
{
  int value = SedBase::unsetAttribute(attributeName);

  if (attributeName == "plot")
  {
    value = unsetPlot();
  }
  else if (attributeName == "row")
  {
    value = unsetRow();
  }
  else if (attributeName == "col")
  {
    value = unsetCol();
  }
  else if (attributeName == "rowSpan")
  {
    value = unsetRowSpan();
  }
  else if (attributeName == "colSpan")
  {
    value = unsetColSpan();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSubPlot::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("plot");

  attributes.add("row");

  attributes.add("col");

  attributes.add("rowSpan");

  attributes.add("colSpan");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSubPlot::readAttributes(
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&
                             attributes,
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER
                             ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  if (log && getParentSedObject() &&
    static_cast<SedListOfSubPlots*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlFigureLOSubPlotsAllowedCoreAttributes, level,
          version, details, getLine(), getColumn());
      }
    }
  }

  SedBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SedUnknownCoreAttribute);
        log->logError(SedmlSubPlotAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // plot SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("plot", mPlot);

  if (assigned == true)
  {
    if (mPlot.empty() == true)
    {
      logEmptyString(mPlot, level, version, "<SedSubPlot>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mPlot) == false)
    {
      std::string msg = "The plot attribute on the <" + getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mPlot + "', which does not conform to the syntax.";
      logError(SedmlSubPlotPlotMustBePlot, level, version, msg, getLine(),
        getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Sedml attribute 'plot' is missing from the "
        "<SedSubPlot> element.";
      log->logError(SedmlSubPlotAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // row int (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetRow = attributes.readInto("row", mRow);

  if ( mIsSetRow == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'row' from the <SedSubPlot> "
        "element must be an integer.";
      log->logError(SedmlSubPlotRowMustBeInteger, level, version, message,
        getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'row' is missing from the "
        "<SedSubPlot> element.";
      log->logError(SedmlSubPlotAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // col int (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetCol = attributes.readInto("col", mCol);

  if ( mIsSetCol == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'col' from the <SedSubPlot> "
        "element must be an integer.";
      log->logError(SedmlSubPlotColMustBeInteger, level, version, message,
        getLine(), getColumn());
    }
    else
    {
      std::string message = "Sedml attribute 'col' is missing from the "
        "<SedSubPlot> element.";
      log->logError(SedmlSubPlotAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // rowSpan int (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetRowSpan = attributes.readInto("rowSpan", mRowSpan);

  if ( mIsSetRowSpan == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'rowSpan' from the <SedSubPlot> "
        "element must be an integer.";
      log->logError(SedmlSubPlotRowSpanMustBeInteger, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // colSpan int (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetColSpan = attributes.readInto("colSpan", mColSpan);

  if ( mIsSetColSpan == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'colSpan' from the <SedSubPlot> "
        "element must be an integer.";
      log->logError(SedmlSubPlotColSpanMustBeInteger, level, version, message,
        getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedSubPlot::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetPlot() == true)
  {
    stream.writeAttribute("plot", getPrefix(), mPlot);
  }

  if (isSetRow() == true)
  {
    stream.writeAttribute("row", getPrefix(), mRow);
  }

  if (isSetCol() == true)
  {
    stream.writeAttribute("col", getPrefix(), mCol);
  }

  if (isSetRowSpan() == true)
  {
    stream.writeAttribute("rowSpan", getPrefix(), mRowSpan);
  }

  if (isSetColSpan() == true)
  {
    stream.writeAttribute("colSpan", getPrefix(), mColSpan);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSubPlot_t using the given SED-ML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedSubPlot_t *
SedSubPlot_create(unsigned int level, unsigned int version)
{
  return new SedSubPlot(level, version);
}


/*
 * Creates and returns a deep copy of this SedSubPlot_t object.
 */
LIBSEDML_EXTERN
SedSubPlot_t*
SedSubPlot_clone(const SedSubPlot_t* ssp)
{
  if (ssp != NULL)
  {
    return static_cast<SedSubPlot_t*>(ssp->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSubPlot_t object.
 */
LIBSEDML_EXTERN
void
SedSubPlot_free(SedSubPlot_t* ssp)
{
  if (ssp != NULL)
  {
    delete ssp;
  }
}


/*
 * Returns the value of the "plot" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
char *
SedSubPlot_getPlot(const SedSubPlot_t * ssp)
{
  if (ssp == NULL)
  {
    return NULL;
  }

  return ssp->getPlot().empty() ? NULL : safe_strdup(ssp->getPlot().c_str());
}


/*
 * Returns the value of the "row" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_getRow(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->getRow() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "col" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_getCol(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->getCol() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "rowSpan" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_getRowSpan(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->getRowSpan() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "colSpan" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_getColSpan(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->getColSpan() : SEDML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "plot" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetPlot(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? static_cast<int>(ssp->isSetPlot()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "row" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetRow(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? static_cast<int>(ssp->isSetRow()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "col" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetCol(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? static_cast<int>(ssp->isSetCol()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "rowSpan" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetRowSpan(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? static_cast<int>(ssp->isSetRowSpan()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SedSubPlot_t's "colSpan" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedSubPlot_isSetColSpan(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? static_cast<int>(ssp->isSetColSpan()) : 0;
}


/*
 * Sets the value of the "plot" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_setPlot(SedSubPlot_t * ssp, const char * plot)
{
  return (ssp != NULL) ? ssp->setPlot(plot) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "row" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_setRow(SedSubPlot_t * ssp, int row)
{
  return (ssp != NULL) ? ssp->setRow(row) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "col" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_setCol(SedSubPlot_t * ssp, int col)
{
  return (ssp != NULL) ? ssp->setCol(col) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "rowSpan" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_setRowSpan(SedSubPlot_t * ssp, int rowSpan)
{
  return (ssp != NULL) ? ssp->setRowSpan(rowSpan) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "colSpan" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_setColSpan(SedSubPlot_t * ssp, int colSpan)
{
  return (ssp != NULL) ? ssp->setColSpan(colSpan) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "plot" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetPlot(SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->unsetPlot() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "row" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetRow(SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->unsetRow() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "col" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetCol(SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->unsetCol() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "rowSpan" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetRowSpan(SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->unsetRowSpan() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "colSpan" attribute of this SedSubPlot_t.
 */
LIBSEDML_EXTERN
int
SedSubPlot_unsetColSpan(SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? ssp->unsetColSpan() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SedSubPlot_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSubPlot_hasRequiredAttributes(const SedSubPlot_t * ssp)
{
  return (ssp != NULL) ? static_cast<int>(ssp->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


