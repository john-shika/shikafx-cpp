cmake_minimum_required(VERSION 3.24)
project(shikafx LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SKIP_BUILD_RPATH OFF)
set(CMAKE_BUILD_WITH_INSTALL_RPATH OFF)
set(CMAKE_INSTALL_RPATH "")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

option(USE_DEBUG "Enable debug mode" ON)

if (USE_DEBUG)
    add_compile_definitions(DEBUG=1)
endif()

#if(WIN32)
#    set(LIB_TYPE STATIC)
#else()
#    set(LIB_TYPE SHARED)
#endif()

set(LIB_TYPE SHARED)

add_library(c-shikafx-ext ${LIB_TYPE} src/shikafx-ext/__ccode__/preload.c)
add_library(shikafx-ext ${LIB_TYPE} src/shikafx-ext/preload.cpp)

#target_include_directories(c-shikafx-ext PUBLIC ${PROJECT_SOURCE_DIR}/include/shikafx-ext/__ccode__)
#target_include_directories(shikafx-ext PUBLIC ${PROJECT_SOURCE_DIR}/include/shikafx-ext)

#set_target_properties(c-shikafx-ext PROPERTIES LINK_FLAGS "-Wl,-rpath,./")
#set_target_properties(shikafx-ext PROPERTIES LINK_FLAGS "-Wl,-rpath,./")

add_executable(shikafx main.cpp)

#set_target_properties(shikafx PROPERTIES LINK_FLAGS "-Wl,-rpath,./")

target_link_libraries(shikafx-ext PRIVATE c-shikafx-ext)
target_link_libraries(shikafx PRIVATE c-shikafx-ext)
target_link_libraries(shikafx PRIVATE shikafx-ext)

install(TARGETS shikafx DESTINATION bin)
install(TARGETS shikafx-ext DESTINATION lib)
install(TARGETS c-shikafx-ext DESTINATION lib)

export(TARGETS shikafx-ext FILE shikafx-ext.cmake)
export(TARGETS c-shikafx-ext FILE c-shikafx-ext.cmake)
