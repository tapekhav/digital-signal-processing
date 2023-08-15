cmake_minimum_required(VERSION 3.22.1)

include_directories(headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../plotters/headers)

file(GLOB DISTRIBUTION_HEADERS headers/*.h)
file(GLOB DISTRIBUTION_SOURCE src/*.cpp)

add_library(Distribution ${DISTRIBUTION_HEADERS} ${DISTRIBUTION_SOURCE})