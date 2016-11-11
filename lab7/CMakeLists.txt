project(lab7)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(driver driver.cc)
add_executable(hash Hashtable.cc)