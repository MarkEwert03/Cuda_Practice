#!/bin/bash

# Purge build directory
rm -rfd build

# Create build directory
mkdir -p build

# Change into the build directory
cd build

# Run cmake to generate build files
cmake ../CMakeLists.txt

# run make file
make