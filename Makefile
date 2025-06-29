CXX = g++
CXXFLAGS = -Wall -Wextra -g3 -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = testes
TEST_BIN_DIR = $(TEST_DIR)/output

# Arquivos fontes
MAIN_SRC = $(SRC_DIR)/main.cpp
SOURCES := $(filter-out $(MAIN_SRC), $(wildcard $(SRC_DIR)/*.cpp))

# Objetos
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/main

# Testes
TEST_SOURCES := $(wildcard $(TEST_DIR)/*.cpp)
TEST_TARGET = $(TEST_BIN_DIR)/testes

# ==== Build do jogo ====
all: $(TARGET)

$(TARGET): $(OBJECTS) $(OBJ_DIR)/main.o
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/main.o: $(MAIN_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ==== Build e execução dos testes ====
testes: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SOURCES) $(OBJECTS)
	@mkdir -p $(TEST_BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# ==== Limpeza ====
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(TEST_BIN_DIR)

.PHONY: all clean testes
