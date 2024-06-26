cmake_minimum_required(VERSION 3.18)
project(CudaPractice CUDA CXX)

# Add the main.cu file to the project
add_executable(ex1.3 examples/HelloWorldGPU.cu)

# Set the output directory for the executable
set_target_properties(ex1.3 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

