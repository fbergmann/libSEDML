## Ruby LibSedML Examples

Examples in this folder contain basic ruby examples that demonstrate the use of the libSedML library using ruby. In order to execute these examples, please ensure that the bindings are in the path, for example by passing it into the command line: 

	ruby -I/usr/local/lib/ruby/site_ruby/1.9/x86_64-linux/ create_sedml.rb

The following examples are present: 

### echo_sedml.rb
This basic example, just echos a SED-ML document, reading it and writing it again. It takes two arguments, an input file and the output file. 

### create_sedml.rb
This example constructs an SED-ML document using the python API. It takes one argument, the output file name.

### print_sedml.rb
This example loads a given SED-ML document and prints an overview of its contents. It takes one argument, the SED-ML document to open. 
