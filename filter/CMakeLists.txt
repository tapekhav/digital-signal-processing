cmake_minimum_required(VERSION 3.22.1)

include_directories(headers)

file(GLOB FILTER_HEADERS headers/*.h)
file(GLOB FILTER_SOURCE src/*.cpp)

add_library(Filter ${FILTER_HEADERS} ${FILTER_SOURCE})