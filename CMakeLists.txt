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
target_include_directories(GAME PRIVATE ${SFML_INCS})
target_link_libraries(GAME sfml-graphics)