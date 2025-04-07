cmake_minimum_required(VERSION 3.12)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(PROJECT_NAME SigConv)                                     #Project name
set(SRC                                                     #Files for compiling
    internal/main.cc
    internal/signal.cc
    internal/base.cc
    internal/baseconverter.cc
    internal/4B3T.cc
    internal/FOMOT.cc
    internal/settings.cc
    internal/app.cc
)

include_directories(internal/)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${SRC})


file(COPY in.txt DESTINATION ${CMAKE_BINARY_DIR})
