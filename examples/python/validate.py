from numpy.core import numeric
import libsedml
import sys
import os
import glob


def validate_sedml(file_name):
    doc = libsedml.readSedMLFromFile(file_name)
    num_errors = doc.getNumErrors(libsedml.LIBSEDML_SEV_ERROR)
    num_warnings = doc.getNumErrors(libsedml.LIBSEDML_SEV_WARNING)

    print ('file: {0} has {1} warning(s) and {2} error(s)'
        .format(file_name, num_warnings, num_errors))

    log = doc.getErrorLog()
    for i in range(log.getNumErrors()):
        err = log.getError(i)
        print('{0} L{1} C{2}: {3}'.format(err.getSeverityAsString(), err.getLine(), err.getColumn(), err.getMessage()))

    return num_errors


if __name__ == "__main__":
    num_args = len(sys.argv)
    if num_args == 1:
        print('usage: validate sedml_file or folder or glob pattern')
        sys.exit(1)
    
    first = sys.argv[1]

    if os.path.isdir(first):
        first = (sys.argv + '/*.sedml')
    
    if (os.path.isfile(first)):
        sys.exit(validate_sedml(first))
    
    if '*' in first:
        files = glob.glob(first)
        num_errors = 0
        for f in files:
            num_errors += validate_sedml(f)
        sys.exit(num_errors)

    print('usage: validate sedml_file or folder or glob pattern')
    sys.exit(1)
    