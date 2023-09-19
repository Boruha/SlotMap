cmake_minimum_required(VERSION 3.15)
project(SloptMap CXX)

add_library(SloptMap src/SloptMap.cpp)
target_include_directories(SloptMap PUBLIC include)



set_target_properties(SloptMap PROPERTIES PUBLIC_HEADER "include/SloptMap.h")
install(TARGETS SloptMap)
