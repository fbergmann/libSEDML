/**
 * @file OStream.h
 * @brief Definition of the OStream class.
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
 *
 * @class OStream
 * @sbmlbrief{} TODO:Definition of the OStream class.
 */



#ifndef OStream_h
#define OStream_h

#include <iostream>
#include <fstream>
#include <sstream>

class SWIGEXPORT OStream 
{
  protected:
    std::ostream* Stream;

  public:

    /**
     * Enumeration listing the possible types of streams to create.
     * <p>
     * This is used by the constructor for this class.  The names
     * of the enumeration members are hopefully self-explanatory.
     */
    enum StdOSType {COUT, CERR, CLOG};


    /**
      * Creates a new OStream object with one of standard output stream objects.
      * 
      * @param sot a value from the StdOSType enumeration(COUT, CERR, or CLOG) 
			* indicating the type of stream to create.
      */
    OStream (StdOSType sot = COUT); 


    /**
     * Destructor.
     */
    virtual ~OStream (); 


    /**
     * Returns the stream object.
     * <p>
     * @return the stream object
     */
    virtual std::ostream* get_ostream ();  


    /**
     * Writes an end-of-line character on this tream.
     */
    void endl ();
  
};
  

class SWIGEXPORT OFStream : public OStream 
{
  public:
    /**
     * Creates a new OFStream object for a file.
     * <p>
     * This opens the given file @p filename with the @p is_append flag
     * (default is <code>false</code>), and creates an OFStream object
     * instance that associates the file's content with an OStream object.
     * <p>
     * @param filename the name of the file to open
     * @param is_append whether to open the file for appending (default:
     * <code>false</code>, meaning overwrite the content instead)
     */
    OFStream (const std::string& filename, bool is_append = false); 

  
    /**
     * Destructor.
     */
    virtual ~OFStream ();


    /**
     * Opens a file and associates this stream object with it.
     * <p>
     * This method opens a given file @p filename with the given
     * @p is_append flag (whose default value is <code>false</code>),
     * and associates <i>this</i> stream object with the file's content.
     * <p>
     * @param filename the name of the file to open
     * @param is_append whether to open the file for appending (default:
     * <code>false</code>, meaning overwrite the content instead)
     */
    void open (const std::string& filename, bool is_append = false);
  

    /**
     * Closes the file currently associated with this stream object.
     */
    void close ();
  

    /**
     * Returns <code>true</code> if this stream object is currently
     * associated with a file.
     * <p>
     * @return <code>true</code> if the stream object is currently
     * associated with a file, <code>false</code> otherwise
     */
    bool is_open (); 
  
};
  

class SWIGEXPORT OStringStream : public OStream 
{
  public:
    /**
     * Creates a new OStringStream object
     */
    OStringStream (); 
  

    /**
     * Returns the copy of the string object currently assosiated 
     * with this <code>ostringstream</code> buffer.
     * <p>
     * @return a copy of the string object for this stream
     */
    std::string str (); 
  

    /**
     * Sets string @p s to the string object currently assosiated with
     * this stream buffer.
     * <p>
     * @param s the string to write to this stream
     */
    void str (const std::string& s);
  

    /**
     * Destructor.
     */
    virtual ~OStringStream (); 
  
};

#endif // OStream_h

