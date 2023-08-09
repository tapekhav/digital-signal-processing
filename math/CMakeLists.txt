cmake_minimum_required(VERSION 3.26)

include_directories(headers)

file(GLOB MATH_HEADERS headers/*.h)
file(GLOB MATH_SOURCE src/*.cpp)

add_library(Math ${MATH_HEADERS} ${MATH_SOURCE})