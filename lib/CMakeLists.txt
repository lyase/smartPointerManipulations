# Bibliothèque myceil
SET(myceil_lib_src my_ceil-lib.c)
#addind more files to the project
file(GLOB HPP_FILES *.hpp  interfaces/*.hpp)
file(GLOB CPP_FILES *.cpp)
SET(myceil_lib_src ${myceil_lib_src} my_ceil-lib2.c Foo.cpp ${HPP_FILES} ${CPP_FILES})
#if you want a STATIC lib USE THIS LINE
ADD_LIBRARY(myceil STATIC ${myceil_lib_src})
#if you want a shared lib USE THIS LINE
#ADD_LIBRARY(myceil SHARED ${myceil_lib_src}) 
#check linked libs: 
#ldd build-raspi2.1/ceil
# list symbols in binary 
#nm build-raspi2.1/ceil
# Installation du fichier my_ceil.h et de la cible myceil
INSTALL(FILES my_ceil.h DESTINATION "include")
INSTALL(TARGETS myceil DESTINATION "lib")
