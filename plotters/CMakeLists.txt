cmake_minimum_required(VERSION 3.22.1)

include_directories(headers)

file(GLOB PLOTTER_HEADERS headers/*.h)
file(GLOB PLOTTER_SOURCE src/*.cpp)

add_library(Plotter ${PLOTTER_HEADERS} ${PLOTTER_SOURCE})