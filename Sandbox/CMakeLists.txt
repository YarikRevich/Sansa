link_directories(${CMAKE_SOURCE_DIR}/build/bin)

add_executable(sandbox src/main.cpp) 

target_link_libraries(sandbox
            libsansa.dylib
            libglfw.3.3.dylib
            libglad.a)

set_property(TARGET sandbox PROPERTY CXX_STANDARD 11)