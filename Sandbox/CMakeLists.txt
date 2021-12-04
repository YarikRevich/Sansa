add_executable(sanbox src/main.cpp) 

link_libraries(sanbox 
            libglfw.3.3.dylib
            libglad.a)

set_property(TARGET sanbox PROPERTY CXX_STANDARD 11)