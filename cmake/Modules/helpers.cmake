if(NOT HOME)
if(WIN32)
string(REPLACE "\\" "/" HOME "$ENV{USERPROFILE}")
else()
set(HOME $ENV{HOME})
endif()
endif()
### Useful Functions and Macros ###
#Prints a list of messages, each one in a new line
#
#Usage:
#file(GLOB_RECURSE config_files RELATIVE "${PROJECT_SOURCE_DIR}" *.in)
#print_list(${config_files})
function(print_list)
foreach(msg ${ARGV})
message("\n ${msg}")
endforeach()
endfunction()
#Given a variable containing a file list,
#this macro will convert the list to a list containing
#all the absolute paths relative to the original files
#
#Usage:
#file(GLOB_RECURSE config_files RELATIVE "${PROJECT_SOURCE_DIR}" *.in)
#convert_absolut_path(config_files)
macro(convert_absolut_path file_list)
foreach(src_file ${${file_list}})
get_filename_component(src_file_path "${src_file}" ABSOLUTE)
list(REMOVE_ITEM ${file_list} "${src_file}")
list(APPEND ${file_list} "${src_file_path}")
endforeach()
endmacro()
#Given a variable containing a file list,
#this macro will remove all the files wich basename
#does not match the specified pattern
#
#Usage:
#file(GLOB_RECURSE config_files RELATIVE "${PROJECT_SOURCE_DIR}" *.in)
#accept_file_pattern("^a" config_files)
macro(accept_file_pattern pattern input_list)
foreach(src_file ${${input_list}})
get_filename_component(base_name ${src_file} NAME)
if(${base_name} MATCHES ${pattern})
else()
list(REMOVE_ITEM ${input_list} "${src_file}")
endif()
endforeach()
endmacro()
#Given a variable containing a file list,
#this macro will remove all the files wich
#basename match the specified pattern
#
#Usage:
#file(GLOB_RECURSE config_files RELATIVE "${PROJECT_SOURCE_DIR}" *.in)
#reject_file_pattern("^a" config_files)
macro(reject_file_pattern pattern input_list)
foreach(src_file ${${input_list}})
get_filename_component(base_name ${src_file} NAME)
if(${base_name} MATCHES ${pattern})
list(REMOVE_ITEM ${input_list} "${src_file}")
endif()
endforeach()
endmacro()
#Given a variable containing a file list,
#this macro will remove all the non-directory items
#
#Usage:
#file(GLOB src_dirs RELATIVE "${PROJECT_SOURCE_DIR}" *)
#accept_directories(src_dirs)
macro(accept_directories input_list)
foreach(src_file ${${input_list}})
get_filename_component(src_file_path "${src_file}" ABSOLUTE)
if(IS_DIRECTORY ${src_file_path})
else()
list(REMOVE_ITEM ${input_list} "${src_file}")
endif()
endforeach()
endmacro()
#Given a variable containing a file list,
#this macro will remove all the directory items
#
#Usage:
#file(GLOB src_files RELATIVE "${PROJECT_SOURCE_DIR}" *)
#reject_directories(src_files)
macro(reject_directories input_list)
foreach(src_file ${${input_list}})
get_filename_component(src_file_path "${src_file}" ABSOLUTE)
if(IS_DIRECTORY ${src_file_path})
list(REMOVE_ITEM ${input_list} "${src_file}")
endif()
endforeach()
endmacro()

#Appends to ${var_name} the paths to all
#direct subdirs (non-recursively)
#
#Usage:
#nested_dirs(subdirs "/etc")
macro(nested_dirs var_name dir_path)
file(GLOB file_list "${dir_path}/*")
list(REMOVE_DUPLICATES file_list)
foreach(file_path ${file_list})
get_filename_component(full_path "${file_path}" ABSOLUTE)
if(IS_DIRECTORY ${full_path})
list(APPEND ${var_name} "${file_path}")
endif()
endforeach()
endmacro()
#Appends to ${var_name} the paths to all
#nested subdirs (deep recursively)
#
#Usage:
#deep_nested_dirs(dirs "/etc")
macro(deep_nested_dirs var_name dir_path)
file(GLOB file_list "${dir_path}/*")
list(REMOVE_DUPLICATES file_list)
foreach(file_path ${file_list})
get_filename_component(full_path "${file_path}" ABSOLUTE)
if(IS_DIRECTORY ${full_path})
list(APPEND ${var_name} "${file_path}")
deep_nested_dirs(${var_name} "${file_path}")
endif()
endforeach()
endmacro()
#For a given extension, this function will call cmake "configure_file",
#and the output file will have the original path with the extension removed
#
#Usage:
#file(GLOB_RECURSE config_files RELATIVE "${PROJECT_SOURCE_DIR}" *.in)
#render_template("\\.in" ${config_files})
function(render_template extension)
foreach(template_file ${ARGN})
get_filename_component(input_file "${template_file}" ABSOLUTE)
string(REGEX REPLACE "${extension}$" "" output_file ${input_file})
configure_file("${input_file}" "${output_file}")
endforeach()
endfunction()
