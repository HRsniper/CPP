cmake_minimum_required(VERSION 3.10)

project("shutdown-program" VERSION 2.0)

message("Project name: " ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(
  SOURCES
  shutdown-v2.cpp
  icon-out.o
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
