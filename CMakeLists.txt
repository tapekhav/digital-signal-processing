cmake_minimum_required(VERSION 3.22.1)
project(digital_signal_processing)

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG ("-std=c++17" COMPILER_HAVE_CPP17)
if (COMPILER_HAVE_CPP17)
    message(STATUS "Adding C++17")
    set(CMAKE_CXX_STANDARD 17)
endif(COMPILER_HAVE_CPP17)

if (MSVC_VERSION GREATER_EQUAL "1900")
    CHECK_CXX_COMPILER_FLAG("/std:c++17" _cpp_17)
    if (_cpp_17)
        message(STATUS "Adding C++17")
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
add_subdirectory(cli)
add_subdirectory(distribution_function)

include_directories(filter/headers)
include_directories(generator/headers)
include_directories(plotters/headers)
include_directories(autocorrelation_function/headers)
include_directories(math/headers)
include_directories(distribution_function/headers)

add_executable(digital_signal_processing
               main.cpp
               cli/headers/option.h
               cli/src/option.cpp
)

find_package(FFTW3 REQUIRED)
set(CMAKE_CXX_FLAGS "-lfftw3")
target_link_libraries(digital_signal_processing Generator Math AutocorrelationFunction Filter Plotter Distribution fftw3)

add_compile_definitions(p_signal="${CMAKE_CURRENT_SOURCE_DIR}/plotters/files/signal.txt")
add_compile_definitions(p_filter="${CMAKE_CURRENT_SOURCE_DIR}/plotters/files/filter.txt")
add_compile_definitions(p_autocorr="${CMAKE_CURRENT_SOURCE_DIR}/plotters/files/autocorrelation.txt")
add_compile_definitions(p_dist="${CMAKE_CURRENT_SOURCE_DIR}/plotters/files/distribution_function.txt")
