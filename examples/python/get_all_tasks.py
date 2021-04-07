import libsedml
import sys

class TaskFilter(libsedml.SedElementFilter):
  def __init__(self):
      libsedml.SedElementFilter.__init__(self)
  
  def filter(self, element):
    if isinstance(element, libsedml.SedAbstractTask):
      return True
    return False


def get_all_tasks(filename):

  doc = libsedml.readSedMLFromFile(filename)
  if doc.getNumErrors(libsedml.LIBSEDML_SEV_ERROR) > 0: 
    print("invalid sedml: " + doc.getErrorLog().toString())
    return 1
    
  filter = TaskFilter()
  all_tasks = doc.getListOfAllElements(filter)
  
  for i in range(all_tasks.getSize()): 
    element = all_tasks.get(i)
    print (element.downcast())


if __name__ == "__main__":
  num_args = len(sys.argv)
  if num_args < 2: 
    print("usage: get_all_tasks <sedml file>")
    sys.exit(1)
    
  sys.exit(get_all_tasks(sys.argv[1]))
    
