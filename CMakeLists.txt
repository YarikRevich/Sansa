cmake_minimum_required(VERSION 3.18)
project(Sansa VERSION 0.1 LANGUAGES CXX DESCRIPTION "Lite-weight opengl abstraction")
include(CTest)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${RUNTIME_OUTPUT_DIRECTORY}/bin)

include_directories(${CMAKE_SOURCE_DIR}/vendor/include)
link_directories(${CMAKE_SOURCE_DIR}/vendor/lib)


add_subdirectory(Sansa)
add_subdirectory(Sandbox)



