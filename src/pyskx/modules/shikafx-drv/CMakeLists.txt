cmake_minimum_required(VERSION 3.24)
project(shikafx-drv LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SKIP_BUILD_RPATH OFF)
set(CMAKE_BUILD_WITH_INSTALL_RPATH OFF)
set(CMAKE_INSTALL_RPATH "")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-mlong-double-128)
endif()

option(USE_DEBUG "Enable debug mode" OFF)

if (USE_DEBUG)
    add_compile_definitions(DEBUG=1)
endif()

set(LIB_TYPE SHARED)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory(../shikafx-ext "${CMAKE_BINARY_DIR}/shikafx-ext")

add_library(shikafx-drv ${LIB_TYPE} ../../../shikafx-drv/preload.cpp)

target_link_libraries(shikafx-drv PRIVATE shikafx-ext c-shikafx-ext)

install(TARGETS shikafx-drv DESTINATION lib)

export(TARGETS shikafx-drv FILE shikafx-drv.cmake)
