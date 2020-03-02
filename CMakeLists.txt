cmake_minimum_required(VERSION 3.11)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Coursework)

### Setup Directories ###
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
#Output all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

### Add External Dependencies ###
add_subdirectory("Libs/sfml")
set(SFML_INCS "Libs/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/Libs/sfml/lib")

### Game ###
file(GLOB_RECURSE SOURCES Game/*.cpp Game/*.h)
add_executable(GAME ${SOURCES})
target_include_directories(GAME SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(GAME ecm maths sfml-graphics sfml-audio)

### ECM Lib ###
file(GLOB_RECURSE SOURCE_FILES Libs/ecm/*.cpp Libs/ecm/*.h)
add_library(ecm STATIC ${SOURCE_FILES})
target_include_directories(ecm INTERFACE "${CMAKE_SOURCE_DIR}/Libs/ecm")
target_link_libraries(ecm PRIVATE maths)

### Maths Lib ###
add_library(maths INTERFACE)
target_sources(maths INTERFACE "${CMAKE_SOURCE_DIR}/Libs/maths/maths.h")
target_include_directories(maths INTERFACE "${CMAKE_SOURCE_DIR}/Libs/maths" SYSTEM INTERFACE ${SFML_INCS})

### Level Loader Lib ###
file(GLOB_RECURSE SOURCES_FILES Libs/level_loader/*.cpp Libs/level_loader/*.h)
add_library(level_loader STATIC ${SOURCES_FILES})
target_include_directories(level_loader INTERFACE "${CMAKE_SOURCE_DIR}/level_loader/")
target_link_libraries(level_loader maths sfml-graphics)