cmake_minimum_required(VERSION 3.22)

project(torch-onnx)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party)
# TODO: get this to build.
add_subdirectory(transforms)
