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

#find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules/cmake")
#include(UseCython)
#
#include_directories("${CMAKE_SOURCE_DIR}/includes")
#find_package(Cython MODULE REQUIRED VERSION 3.0)
#
#add_subdirectory(modules/pyskx-ext "${CMAKE_BINARY_DIR}/pyskx-ext")
#
#cython_transpile(pyskx.pyx LANGUAGE CXX OUTPUT_VARIABLE pyskx)
#python3_add_library(pyskx MODULE "${pyskx}")
#
#export(TARGETS pyskx FILE pyskx.cmake)

add_subdirectory(modules/pyskx-ext "${CMAKE_BINARY_DIR}/pyskx-ext")
