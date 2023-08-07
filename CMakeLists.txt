cmake_minimum_required(VERSION 3.26)
project(digital_signal_processing)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG ("-std=c++17" COMPILER_HAVE_CPP17)
if (COMPILER_HAVE_CPP17)
    message(STATUS "ADDING C++17")
    set(CMAKE_CXX_STANDARD 17)
endif(COMPILER_HAVE_CPP17)

if (MSVC_VERSION GREATER_EQUAL "1900")
    CHECK_CXX_COMPILER_FLAG("/std:c++17" _cpp_17)
    if (_cpp_17)
        message(STATUS "ADDING C++17")
        add_compile_options("/std:c++17")
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    #add_compile_options(-Wall -Wextra -Werror -Wpedantic -Wconversion -Wformat -Wunused -Wshadow -Wuninitialized)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

include_directories(generator/headers)
include_directories(plotters/headers)
include_directories(filter/headers)

file(GLOB GENERATOR_HEADERS generator/headers/*.h)

add_executable(digital_signal_processing
               main.cpp
               ${GENERATOR_HEADERS}
               generator/src/signal_generate.cpp
               plotters/headers/plotter.h
               plotters/src/plotter.cpp
               filter/headers/windowing_filter.h
               filter/src/windowing_filter.cpp)
