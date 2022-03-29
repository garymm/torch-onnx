cmake_minimum_required(VERSION 3.22)

project(torch-onnx)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# TODO: ccache

# Use lld (faster linker)
# TODO: this only works for clang < 13. Newer versions need --ld-path= instead of -fuse-ld=
set(CMAKE_EXE_LINKER_FLAGS_INIT "-fuse-ld=lld" CACHE STRING "" FORCE)
set(CMAKE_MODULE_LINKER_FLAGS_INIT "-fuse-ld=lld" CACHE STRING "" FORCE)
set(CMAKE_SHARED_LINKER_FLAGS_INIT "-fuse-ld=lld" CACHE STRING "" FORCE)

add_subdirectory(third_party)
# TODO: get this to build.
#add_subdirectory(transforms)
