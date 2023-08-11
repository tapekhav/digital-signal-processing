cmake_minimum_required(VERSION 3.26)

include_directories(headers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../math/headers)

file(GLOB AUTOCORRELATION_HEADERS headers/*.h)
file(GLOB AUTOCORRELATION_SOURCE src/*.cpp)

add_library(AutocorrelationFunction ${AUTOCORRELATION_HEADERS} ${AUTOCORRELATION_SOURCE})
target_link_libraries(AutocorrelationFunction Math)