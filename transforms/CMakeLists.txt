add_library(transforms passes.cpp)

target_include_directories(transforms INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}

LINK_LIBS PUBLIC
MLIRPass
)
