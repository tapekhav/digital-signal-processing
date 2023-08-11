cmake_minimum_required(VERSION 3.22.1)
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
    add_compile_options(-Wall -Wextra -Werror -Wpedantic -Wconversion -Wformat -Wunused -Wshadow -Wuninitialized -Wsign-compare)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
endif()

add_subdirectory(math)
add_subdirectory(filter)
add_subdirectory(plotters)
add_subdirectory(generator)
add_subdirectory(autocorrelation_function)

include_directories(autocorrelation_function/headers)
include_directories(math/headers)

add_executable(digital_signal_processing
               main.cpp
)

target_link_libraries(digital_signal_processing Math AutocorrelationFunction Filter Plotter)
