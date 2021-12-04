add_library(sansa SHARED 
            src/main.cpp 
            src/texture.cpp
            src/buffers.cpp
            src/window.cpp 
            src/renderer.cpp)
link_libraries(sansa 
            libglfw.3.3.dylib
            libglad.a)
target_precompile_headers(sansa PUBLIC src/pch.hpp)


set_property(TARGET sansa PROPERTY CXX_STANDARD 11)

add_subdirectory(tests)

install(TARGETS sansa DESTINATION "build")