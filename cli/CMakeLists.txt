cmake_minimum_required(VERSION 3.22.1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../filter/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../generator/headers)
include_directories(plotters/headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../autocorrelation_function/headers)
include_directories(math/headers)

file(GLOB FILTER_HEADERS headers/*.h)
file(GLOB FILTER_SOURCE src/*.cpp)

add_library(Filter ${FILTER_HEADERS} ${FILTER_SOURCE})