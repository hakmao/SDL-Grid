SRC_DIR := ../src
TEST_DIR := .
INC_DIR1 := ../src
BUILD_DIR := ./build

SRC_FILES := $(shell find $(SRC_DIR) -name *.cpp)
#OBJ_FILES := $(SRC_FILES:%=$(BUILD_DIR)/%.o)

CXX = g++
LINKER = g++
INC_FLAGS := $(addprefix -I, $(INC_DIR1))
CXX_STD := -std=c++17
CXX_FLAGS = $(INC_FLAGS) $(CXX_STD)
LD_FLAGS= -lncurses

MKDIR_P ?= mkdir -p

.PHONY: all clean


### Tests ###
all: grid_tests

# Grid tests
grid_tests: $(BUILD_DIR)/grid_tests.o $(BUILD_DIR)/grid.o
	$(LINKER) $(CXX_FLAGS) $(LD_FLAGS) $^ -o $@

### Object files ###

$(BUILD_DIR)/grid_tests.o: $(TEST_DIR)/grid_tests.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(BUILD_DIR)/grid.o: $(SRC_DIR)/grid.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

### Clean up ###
clean:
	@echo "Cleaning up..."
	rm -rvf $(BUILD_DIR)
	$(MKDIR_P) $(BUILD_DIR)
	rm ./*_tests ./*.grid

