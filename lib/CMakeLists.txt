cmake_minimum_required(VERSION 3.20)

project(MatrixVectorLib CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE Headers CONFIGURE_DEPENDS "include/*.hpp")
file(GLOB_RECURSE Sources CONFIGURE_DEPENDS "src/*.cpp")
include_directories(include)
add_library(MatrixVectorLib STATIC ${Headers} ${Sources})