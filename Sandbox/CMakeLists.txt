
if(WIN32 AND (${DEBUG}))
    link_directories(${CMAKE_SOURCE_DIR}/build/Sansa/Debug)
elseif(UNIX)
    link_directories(${CMAKE_SOURCE_DIR}/build/bin)
endif()

add_executable(sandbox src/main.cpp)

if(WIN32)
set(LIBSANSA "sansa")
elseif(APPLE)
set(LIBSANSA "libsansa.dylib")
endif()


target_link_libraries(sandbox
            ${LIBSANSA}
            ${LIBGLFW}
            ${LIBGLAD})

set_property(TARGET sandbox PROPERTY CXX_STANDARD 11)