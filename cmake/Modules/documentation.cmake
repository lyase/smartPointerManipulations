#################################detecting doxygen before making a doc target###############################
find_package(Doxygen)

if (NOT ${DOXYGEN_EXECUTABLE} STREQUAL "DOXYGEN_EXECUTABLE_NOT_FOUND")
    message("${DOXYGEN_EXECUTABLE}")
configure_file(project-doxy.cfg Doxyfile)
set(COMMAND ${DOGYGEN_EXECUTABLE} Doxyfile)
add_custom_target(doc_html
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        COMMAND cmake .. --graphviz=doc/dependencies.dot
        COMMAND dot -Tsvg ${CMAKE_CURRENT_BINARY_DIR}/doc/dependencies.dot -o ${CMAKE_CURRENT_BINARY_DIR}/doc/dependencies.svg
        COMMAND dot -Tpng doc/dependencies.dot -o doc/dependencies.png
        COMMAND mv ${CMAKE_CURRENT_BINARY_DIR}/doc ${CMAKE_CURRENT_BINARY_DIR}/resources/
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )

add_custom_target(doc_pdf
        make pdf
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/latex
        DEPENDS doc_html
        COMMENT "Generating API documentation - pdf version"
        VERBATIM
    )
endif()
#------------------------------------------------------------------------------------------------------

