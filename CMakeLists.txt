cmake_minimum_required(VERSION 3.5)
project(leetcode_fight)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp  127_Word_Ladder.cpp 130_Surrounded_Regions.cpp)
add_executable(leetcode_fight ${SOURCE_FILES})