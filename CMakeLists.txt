cmake_minimum_required(VERSION 3.22)

project(torch-onnx)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# TODO: ccache and lld

# Use lld (faster linker)
# TODO: This doesn't seem to be working, probably need to force it into the cache
set(CMAKE_EXE_LINKER_FLAGS_INIT "--ld-path=lld")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "--ld-path=lld")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "--ld-path=lld")

add_subdirectory(third_party)
# TODO: get this to build.
#add_subdirectory(transforms)
