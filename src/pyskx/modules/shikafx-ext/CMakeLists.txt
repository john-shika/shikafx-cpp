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

add_library(c-shikafx-ext ${LIB_TYPE} ../../../shikafx-ext/__ccode__/preload.c)
add_library(shikafx-ext ${LIB_TYPE} ../../../shikafx-ext/preload.cpp)

target_link_libraries(shikafx-ext PRIVATE c-shikafx-ext)

install(TARGETS c-shikafx-ext DESTINATION lib)
install(TARGETS shikafx-ext DESTINATION lib)

export(TARGETS c-shikafx-ext FILE c-shikafx-ext.cmake)
export(TARGETS shikafx-ext FILE shikafx-ext.cmake)
