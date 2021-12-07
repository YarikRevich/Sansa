cmake_minimum_required(VERSION 3.18)
project(Sansa VERSION 0.1 LANGUAGES CXX DESCRIPTION "Lite-weight graphics abstraction")
include(CTest)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/vendor/include)
include_directories(${CMAKE_SOURCE_DIR}/Sansa/include)
link_directories(${CMAKE_SOURCE_DIR}/vendor/lib)


add_subdirectory(Sansa)
add_subdirectory(Sandbox)



