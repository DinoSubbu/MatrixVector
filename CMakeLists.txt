cmake_minimum_required(VERSION 3.20)

project(MatrixVector CXX)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE Sources CONFIGURE_DEPENDS "main.cpp")

include_directories(lib/include)
add_subdirectory(lib)
add_executable(MatrixVector ${Sources})
target_link_libraries(MatrixVector PUBLIC
	MatrixVectorLib
)