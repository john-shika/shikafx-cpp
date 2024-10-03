cmake_minimum_required(VERSION 3.24)
project(pyskx-ext LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SKIP_BUILD_RPATH OFF)
set(CMAKE_BUILD_WITH_INSTALL_RPATH OFF)
set(CMAKE_INSTALL_RPATH "")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

option(USE_DEBUG "Enable debug mode" OFF)

if (USE_DEBUG)
    add_compile_definitions(DEBUG=1)
endif()

set(LIB_TYPE SHARED)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(../shikafx-ext "${CMAKE_BINARY_DIR}/shikafx-ext")

add_library(pyskx-ext ${LIB_TYPE} ../../../pyskx-ext/preload.cpp)

target_link_libraries(pyskx-ext PRIVATE shikafx-ext c-shikafx-ext)

install(TARGETS pyskx-ext DESTINATION lib)

export(TARGETS pyskx-ext FILE pyskx-ext.cmake)
