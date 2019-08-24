cmake_minimum_required(VERSION 3.7)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
include(Listcmake-var)
include(FileConfig)
include(CommitInfo)
include(documentation)
# loading & using helpers
include(helpers )
find_package( Threads )
file(GLOB_RECURSE config_files RELATIVE "${PROJECT_SOURCE_DIR}" *.cpp)
MESSAGE(STATUS "here are file lists starting : \n ")
print_list(${config_files})
MESSAGE(STATUS "here are file lists finish : \n ")
file(GLOB_RECURSE config_files RELATIVE "${PROJECT_SOURCE_DIR}" *.cpp)
convert_absolut_path(config_files)
MESSAGE(STATUS "here are absolute file lists starting : \n ")
   print_list(${config_files})
MESSAGE(STATUS "here are absolute file lists finish : \n ")
#add_dependencies( ceil config_File)
PROJECT(ceil-main)
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG(-std=c++11 HAVE_CPP11)
# Vérification de la présence des dépendances
	FIND_PACKAGE(X11)
	find_library(MathLib NAMES m PATHS ${FOO_PREFIX}/lib)
# Inclusion des répertoires d'en-têtes
INCLUDE_DIRECTORIES(${ZLIB_INCLUDE_DIR})
IF(X11_FOUND)
MESSAGE(STATUS "X11 présent")
INCLUDE_DIRECTORIES(${X11_INCLUDE_DIR})
ELSE(X11_FOUND)
MESSAGE(STATUS "X11 absent")
ENDIF(X11_FOUND)

# Parcours du répertoire lib
ADD_SUBDIRECTORY(lib)
#noter que le lib projet lib a sont propre fichier CMakeLists.txt
# Programme ceil desinition du fichier source
# to trash there is a proper way to require updating cpommit information at build time SET(ceil_src ./apps/main.c ${CMAKE_CURRENT_BINARY_DIR}/CommitInfo.tex )
SET(multithread_src ./apps/atomicMultiThread.cpp)
SET(ceil_src ./apps/main.cpp)
# definition du binaire a construire lors compilation
ADD_EXECUTABLE(ceil-main ${ceil_src})
TARGET_LINK_LIBRARIES(ceil-main myceil  ${MathLib} ${ZLIB_LIBRARY} ${X11_LIBRARIES} )
ADD_EXECUTABLE(multithread ${multithread_src})
TARGET_LINK_LIBRARIES(multithread myceil  ${MathLib} ${ZLIB_LIBRARY} ${X11_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )
# Gestion de l'option WITH_GUI
OPTION(WITH_GUI "Compiler l'interface graphique" OFF)
IF(WITH_GUI)
MESSAGE(STATUS "Compilation de l'interface graphique activée")
ENDIF(WITH_GUI)
# Gestion du paramètre DATA_DIR inclus via config.h
IF (NOT DATA_DIR)
SET(DATA_DIR "/usr/share/mydatadir")
ENDIF(NOT DATA_DIR)
MESSAGE(STATUS "Données situées dans ${DATA_DIR}")
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})
# Installation de la cible ceil
INSTALL(TARGETS ceil-main DESTINATION "bin")
# this will require file configuration done before ceil target build
# adding test targets
# to trash 
#add_dependencies( ceil-main config_File)
ENABLE_TESTING()
add_subdirectory(test)
 ADD_TEST(On_test_le_binaire ${EXECUTABLE_OUTPUT_PATH}/ceil-main 42)
