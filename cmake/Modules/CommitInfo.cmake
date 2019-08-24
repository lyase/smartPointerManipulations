#this cmake module generate latex file from  source tree  commit informations 
cmake_minimum_required(VERSION 3.7)
FIND_PACKAGE(Git)
project(CommitInfo)
# to trash PROJECT(CONFIGURE)
# get commit  short sha1  
execute_process( 
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ 
	COMMAND ${GIT_EXECUTABLE}  log -1  --abbrev-commit  --pretty=format:%H 
	RESULT_VARIABLE SHORT_HASH_RESULT 
	OUTPUT_VARIABLE SHORT_HASH)
# get commit --abbrev-commit 
execute_process( 
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ 
	COMMAND ${GIT_EXECUTABLE}  log -1 --abbrev-commit  
	RESULT_VARIABLE DETAIL_HASH_RESULT 
	OUTPUT_VARIABLE DETAIL_HASH)
# get commit date
execute_process( 
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ 
	COMMAND ${GIT_EXECUTABLE}  log -1 --date=short --pretty=format:%cd 
	RESULT_VARIABLE SHORT_HASH_RESULT 
	OUTPUT_VARIABLE SHORT_HASH_DATE)
#set build time variable  
IF (NOT DATA_DIR)
SET(DATA_DIR "/usr/share/mydatadir")
ENDIF(NOT DATA_DIR)
MESSAGE(STATUS "Données situées dans ${DATA_DIR}")
# Génération du fichier latex 
# case input is within binary dir 
configure_file( cmake/Modules/CommitInfo.in.tex ${CMAKE_CURRENT_BINARY_DIR}/CommitInfo.tex @ONLY)
set_source_files_properties( ${CMAKE_CURRENT_BINARY_DIR}/CommitInfo.tex PROPERTIES GENERATED TRUE)
