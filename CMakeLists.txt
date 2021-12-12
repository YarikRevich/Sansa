cmake_minimum_required(VERSION 3.18)
project(Sansa VERSION 0.1 LANGUAGES CXX DESCRIPTION "Lite-weight graphics abstraction")
include(CTest)

if(WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES)
endif()


if(NOT WIN32)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
endif()


include_directories(${CMAKE_SOURCE_DIR}/vendor/include/crosplatform)

if(WIN32)
include_directories(${CMAKE_SOURCE_DIR}/vendor/include/windows)
elseif(UNIX)
include_directories(${CMAKE_SOURCE_DIR}/vendor/include/unix)
endif()

include_directories(${CMAKE_SOURCE_DIR}/Sansa/include)

if (WIN32)
link_directories(${CMAKE_SOURCE_DIR}/vendor/lib/windows)
elseif(APPLE)
link_directories(${CMAKE_SOURCE_DIR}/vendor/lib/darwin)
elseif(UNIX)
link_directories(${CMAKE_SOURCE_DIR}/vendor/lib/unix)
endif()

#Names for basic libraries are specified for each OS

if(WIN32)
set(LIBGLFW "glfw3")
set(LIBGLAD "glad")
elseif(UNIX OR APPLE)
set(LIBGLFW "libglfw3.a")
set(LIBGLAD "libglad.a")
endif()

add_subdirectory(Sansa)
add_subdirectory(Sandbox)



