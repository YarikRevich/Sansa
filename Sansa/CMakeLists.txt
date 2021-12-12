include_directories(include/)

add_library(sansa STATIC 
            src/texture.cpp
            src/window.cpp 
            src/renderer.cpp 
            src/shader.cpp
            src/log.cpp
            src/vao.cpp
            src/ib.cpp
            src/vbo.cpp
            src/objloader.cpp
            src/stb_image.cpp
           
)



target_link_libraries(sansa 
${LIBGLAD}
            ${LIBGLFW}
            )

target_precompile_headers(sansa PUBLIC include/pch.hpp)

set_property(TARGET sansa PROPERTY CXX_STANDARD 17)

add_subdirectory(tests)

install(TARGETS sansa DESTINATION "build")