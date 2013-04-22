## R LibSedML Examples

Examples in this folder contain basic R examples that demonstrate the use of the libSedML library using R. In order to launch the examples, first *manually* install the created binary installer:

 	R CMD INSTALL <filename>

then you ought to be able to launch the examples from the command line like so: 

	R --slave -f create_sedml.R --args <full path to input file> 

The following examples are present: 

### echo_sedml.R
This basic example, just echos a SED-ML document, reading it and writing it again. It takes two arguments, an input file and the output file. 

### create_sedml.R
This example constructs an SED-ML document using the R API. It takes one argument, the output file name.

### print_sedml.R
This example loads a given SED-ML document and prints an overview of its contents. It takes one argument, the SED-ML document to open. 
