## Perl LibSedML Examples

Examples in this folder contain basic perl examples that demonstrate the use of the libSedML library using perl. In order to run them you need to ensure that LibSEDML can be found. As I am not regularly using PERL, I usually do that by specifying the full path where i installed the library in my perl files, like so

	use lib '/usr/local/lib/perl5/site_perl';

or from the command line it would be possible to specify the directories to include directly: 

	perl -I/usr/local/lib/perl5/site_perl/5.14.2/x86_64-linux-gnu-thread-multi -I/usr/local/lib/perl5/site_perl/5.14.2/x86_64-linux-gnu-thread-multi/auto/libSEDML echo_sedml.pl 

The following examples are present: 

### echo_sedml.pl
This basic example, just echos a SED-ML document, reading it and writing it again. It takes two arguments, an input file and the output file. 

### create_sedml.pl
This example constructs an SED-ML document using the Perl API. It takes one argument, the output file name.

### print_sedml.pl
This example loads a given SED-ML document and prints an overview of its contents. It takes one argument, the SED-ML document to open. 
