cmake_minimum_required(VERSION 3.5)
project(leetcode_fight)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp  016_3Sum_Closest.cpp 018_4Sum.cpp)
add_executable(leetcode_fight ${SOURCE_FILES})