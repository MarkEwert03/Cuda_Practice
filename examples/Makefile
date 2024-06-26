# Directiories
EXEC_DIR = ../bin
OBJ_DIR = .objs

# Non CUDA Executables
EXE_1.1 = $(EXEC_DIR)/ex1.1
EXE_1.2 = $(EXEC_DIR)/ex1.2

# Compilers
CXX = g++
LD = g++

# Compiler flags
CXXFLAGS = -std=c++11 -g -O0 -MMD -MP

# Include path
INCLUDE_PATH = -I../include

# Libraries
LIBS = -fopenmp # Add OpenMP library flag

# Source files
SRC_1.1 = example1.1.cpp
SRC_1.2 = example1.2.cpp

# Object files
OBJ_1.1 = $(OBJ_DIR)/example1.1.o
OBJ_1.2 = $(OBJ_DIR)/example1.2.o

# Dependency files
DEP_1.1 = $(OBJ_DIR)/example1.1.d
DEP_1.2 = $(OBJ_DIR)/example1.2.d

all: $(EXE_1.1) $(EXE_1.2)

$(EXE_1.1): $(OBJ_1.1)
	mkdir -p $(EXEC_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(EXE_1.2): $(OBJ_1.2)
	mkdir -p $(EXEC_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Rules for building the object files
$(OBJ_DIR)/%.o: %.cu
	mkdir -p $(OBJ_DIR)
	$(NVCC) $(NVCCFLAGS) $(INCLUDE_PATH) -o $@ -c $<

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) -o $@ -c $<

# Include dependency files if they exist
-include $(DEP_1.1)
-include $(DEP_1.2)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(EXEC_DIR)

.PHONY: all clean