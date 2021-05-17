cmake_minimum_required(VERSION 3.20)

project(MatrixVector CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE Sources CONFIGURE_DEPENDS "main.cpp")

include_directories(include)

add_executable(MatrixVector ${Sources})