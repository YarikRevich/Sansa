cmake_minimum_required(VERSION 3.18)
project(Sansa VERSION 0.1 LANGUAGES CXX DESCRIPTION "Lite-weight opengl abstraction")
include(CTest)

include_directories(${CMAKE_SOURCE_DIR}/vendor/include)
link_directories(${CMAKE_SOURCE_DIR}/vendor/lib)

add_library(sansa SHARED 
            src/main.cpp)
link_libraries(sansa 
            libglfw.3.3.dylib
            libglad.a)

set_property(TARGET sansa COMPILER_VERSION 11)

install(TARGET sansa)
