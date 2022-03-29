add_mlir_library(transforms
  passes.cpp

  DEPENDS
  TorchMLIRConversionPassIncGen

  LINK_COMPONENTS
  Core

  EXCLUDE_FROM_LIBMLIR
)

# target_include_directories(transforms
#   INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
#   PRIVATE ${CMAKE_SOURCE_DIR}/third_party/torch-mlir/external/llvm-project/mlir/include)

