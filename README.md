# LibSEDML
Some time ago I developed [libSedML](http://libsedml.sf.net) a C# library that fully supports [SED-ML](http://sed-ml.org) for SBML as well as CellML models for creation of the description just as for the execution of Simulation Experiments. However, frequently the question to a C++ based library comes up. This project makes use of [libSBML](http://sbml.org/Software/libSBML) XML layer as well as code generation as starting point to produce a library for reading and writing of SED-ML models.

## Dependencies

This library requires libSBML to be present, as its XML parsing layer will be used. for that either expat, xerces-c or libXML2 needs to be available. Additionally libSEDML makes use of libnuml. All dependencies are available as git submodule. 

## Building Python wheels

Since all dependencies are included as submodules, be sure to checkout the project with submodules:

	git clone --recurse-submodules https://github.com/fbergmann/libSEDML

Then a build is as easy as: 

	cd libSEDML
	python src/bindings/python/setup.py build

or install, if you prefer. It requires cmake and swig installed. 

## Building

This library uses [CMake](http://cmake.org) to build the library, so from an initial checkout all you would need todo is to run:


    mkdir build  
    cd build
    cmake -DLIBSBML_LIBRARY=< path to libsbml lib> -DLIBSBML_INCLUDE_DIR=< path to includes > ... -DEXTRA_LIBS= < comma separated list of xml libraries> 
    make  
    make install

Should libSBML be installed in a default location it will be found automatically. Note that you do need to list the xml libraries that libSBML was linked against. In most cases libSBML is compiled against libXML and have compression enabled, so your `EXTRA_LIBS` would be:

	EXTRA_LIBS=xml2;bz2;z;iconv

note the semicolon denoting the listing of several libraries. Of course you could also enter the full path to each individual file, just to give an example, on windows I use: 

	EXTRA_LIBS=D:/dependencies/lib/expat.lib

for linking against `expat` and indicating, that libSBML was compiled without compression.

## License

This project is open source and freely available under the [Simplified BSD](http://opensource.org/licenses/BSD-2-Clause) license. Should that license not meet your needs, please contact me.


Copyright (c) 2013-2021, Frank T. Bergmann  
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
