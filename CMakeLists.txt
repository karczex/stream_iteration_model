cmake_minimum_required(VERSION 3.10)

# set the project name
project(ProjectName)

add_library(stream OBJECT stream.cpp)

# add the executable
add_executable(test main.c)
target_link_libraries(test stream)



