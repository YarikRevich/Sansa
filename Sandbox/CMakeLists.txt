
if(WIN32 AND (${DEBUG}))
    link_directories(${CMAKE_SOURCE_DIR}/build/Sansa/Debug)
elseif(UNIX OR APPLE)
    link_directories(${CMAKE_SOURCE_DIR}/build/bin)
endif()

add_executable(sandbox src/main.cpp)

if(WIN32)
set(LIBSANSA "sansa")
elseif(UNIX OR APPLE)
set(LIBSANSA "libsansa.a")
endif()

message(${LIBSANSA}, ${LIBGLFW},
${LIBGLAD})

target_link_libraries(sandbox
            ${LIBSANSA}
            ${LIBGLFW}
            ${LIBGLAD})

if(APPLE)
target_link_libraries(sandbox "-framework Cocoa -framework IOKit -framework CoreVideo")
endif()

set_property(TARGET sandbox PROPERTY CXX_STANDARD 11)