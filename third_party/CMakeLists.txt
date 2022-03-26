# Based on torch-mlir/README.md
set(Python3_FIND_VIRTUALENV ONLY CACHE STRING "" FORCE)
set(LLVM_ENABLE_PROJECTS mlir CACHE STRING "" FORCE)
set(LLVM_EXTERNAL_PROJECTS "torch-mlir;torch-mlir-dialects" CACHE STRING "" FORCE)
set(LLVM_EXTERNAL_TORCH_MLIR_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/torch-mlir CACHE PATH "" FORCE)
set(LLVM_EXTERNAL_TORCH_MLIR_DIALECTS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/torch-mlir/external/llvm-external-projects/torch-mlir-dialects CACHE PATH "" FORCE)
set(MLIR_ENABLE_BINDINGS_PYTHON ON CACHE BOOL "" FORCE)
set(LLVM_TARGETS_TO_BUILD host CACHE STRING "" FORCE)

add_subdirectory(torch-mlir/external/llvm-project/llvm)
