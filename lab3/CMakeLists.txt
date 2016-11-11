project(lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(CDate CDate.cc)
add_executable(dates dates.cc)
add_executable(linked_list linked_list.cc)
add_executable(lists lists.cc)