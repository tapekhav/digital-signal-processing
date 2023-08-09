cmake_minimum_required(VERSION 3.26)

include_directories(headers)

file(GLOB GENERATOR_HEADERS headers/*.h)
file(GLOB GENERATOR_SOURCE src/*.cpp)

add_library(Generator ${GENERATOR_HEADERS} ${GENERATOR_SOURCE})