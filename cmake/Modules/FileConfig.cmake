#this cmake module generate config.h  file in build directory from this  template file 
IF (NOT DATA_DIR)
SET(DATA_DIR "/usr/share/mydatadir")
ENDIF(NOT DATA_DIR)
MESSAGE(STATUS "Données seront  situées dans ${DATA_DIR} defini pendant compilation")
# custom target speciliser pour la Génération du fichier config.h
Project(config_File )
#	OUTPUT ${CMAKE_BINARY_DIR}/config.h
# case input is within source  dir 
CONFIGURE_FILE(cmake/Modules/config.in.h ${CMAKE_BINARY_DIR}/config.hpp)
#to trash add_library ( config_File ${CMAKE_BINARY_DIR}/config.hpp)
#        DEPENDS mvcdoc
#	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/
#        COMMENT "Generating API documentation - pdf version"
#        VERBATIM
#    )
