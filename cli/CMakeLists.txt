cmake_minimum_required(VERSION 3.22.1)

include_directories(headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../filter/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../generator/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../plotters/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../autocorrelation_function/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../math/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../distribution_function/headers)

file(GLOB CLI_HEADERS headers/*.h)
file(GLOB CLI_SOURCE src/*.cpp)

add_library(CLI ${CLI_HEADERS} ${CLI_SOURCE})

add_compile_definitions(p_signal="${CMAKE_CURRENT_SOURCE_DIR}/plotters/files/signal.txt")
add_compile_definitions(p_filter="${CMAKE_CURRENT_SOURCE_DIR}/plotters/files/filter.txt")
add_compile_definitions(p_autocorr="${CMAKE_CURRENT_SOURCE_DIR}/plotters/files/autocorrelation.txt")
add_compile_definitions(p_dist="${CMAKE_CURRENT_SOURCE_DIR}/plotters/files/distribution_function.txt")