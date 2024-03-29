# cmake snippet to list all var at this point
# usage include(Listcmake-var.cmake)
#Load and run CMake code from a file or module.
############################################# how to use cmake include  command
#include(<file|module> [OPTIONAL] [RESULT_VARIABLE <VAR>]
#                      [NO_POLICY_SCOPE])
#
#Load and run CMake code from the file given. Variable reads and writes access the scope of the caller (dynamic scoping). If OPTIONAL is present, then no error is raised if the file does not exist. If RESULT_VARIABLE is given the variable will be set to the full filename which has been included or NOTFOUND if it failed.
#
#If a module is specified instead of a file, the file with name <modulename>.cmake is searched first in CMAKE_MODULE_PATH, then in the CMake module directory. There is one exception to this: if the file which calls include() is located itself in the CMake module directory, then first the CMake module directory is searched and CMAKE_MODULE_PATH afterwards. See also policy CMP0017.
#See the cmake_policy() command documentation for discussion of the NO_POLICY_SCOPE option.
###############################################################################
get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(DEBUGING STATUS "${_variableName}=${${_variableName}}")
endforeach()
###############################################################################
