
set(WRAPPER_FILE "${CUR_BIN_DIRECTORY}/libsedml.py")

if(NOT EXISTS ${WRAPPER_FILE})
  message(FATAL_ERROR "  The SWIG wrapper has not yet been created")
else()


file(READ "${WRAPPER_FILE}" SOURCECODE)

message("Python: patch loader")

file(WRITE "${WRAPPER_FILE}" "
# import statement needed on some systems
import sys
import os.path
import inspect
try: 
  _filename = inspect.getframeinfo(inspect.currentframe()).filename
except:
  _filename = __file__
_path = os.path.dirname(os.path.abspath(_filename))
if not _path in sys.path:
  sys.path.append(_path)

")


file(APPEND  "${WRAPPER_FILE}" "${SOURCECODE}")


message("Python: Add Version to generated file")

file(APPEND "${WRAPPER_FILE}" "
global __version__
__version__ = '${VERSION}'
")
endif()


message ("Python: create 3.x version")

file(READ ${CUR_BIN_DIRECTORY}/libsedml.py init_script)
file(WRITE ${CUR_BIN_DIRECTORY}/libsedml2.py ${init_script})

string(REPLACE 
  "class SBase(_object):"
  "class SBase(_object, metaclass=AutoProperty):"
  init3_script ${init_script}
)

string(REPLACE 
  "class SedBase(_object):"
  "class SedBase(_object, metaclass=AutoProperty):"
  init3_script ${init3_script}
)

string(REPLACE 
  "class SBase(object):"
  "class SBase(object, metaclass=AutoProperty):"
  init3_script ${init3_script}
)

string(REPLACE 
  "class SedBase(object):"
  "class SedBase(object, metaclass=AutoProperty):"
  init3_script ${init3_script}
)


file(WRITE ${CUR_BIN_DIRECTORY}/libsedml3.py ${init3_script})