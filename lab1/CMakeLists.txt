cmake_minimum_required(VERSION 3.6)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(q1 q1.cpp)
add_executable(q2 q2.cpp)
add_executable(q3 q3.cpp)
add_executable(hanoi hanoi.cpp)
add_executable(guessing_game guessing_game.cpp)