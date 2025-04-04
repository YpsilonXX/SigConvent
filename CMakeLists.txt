cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME SigConv)                                     #Project name
set(SRC                                                     #Files for compiling
    internal/main.cc
    internal/signal.cc
    internal/base.cc
)

include_directories(internal/)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${SRC})
