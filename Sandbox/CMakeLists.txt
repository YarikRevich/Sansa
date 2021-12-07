link_directories(${CMAKE_SOURCE_DIR}/build/bin)

add_executable(sanbox src/main.cpp) 

target_link_libraries(sanbox
            libsansa.dylib
            libglfw.3.3.dylib
            libglad.a)

set_property(TARGET sanbox PROPERTY CXX_STANDARD 11)