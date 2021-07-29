cmake_minimum_required(VERSION 3.10)

project("shutdown-program" VERSION 1.0)

message("Project name: " ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(
  SOURCE
  shutdown-v1.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
