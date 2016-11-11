project(lab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(deque deque.cc)
add_executable(extra extra.cc)
add_executable(insertion insertion.cc)
add_executable(pointers pointers.cc)