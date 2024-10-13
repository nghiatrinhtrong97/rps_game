# Makefile for RPS Game

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Source files
SRC = src/Client.cpp \
      src/ComputerPlayer.cpp \
      src/Game.cpp \
      src/HumanPlayer.cpp \
      src/main.cpp \
      src/Player.cpp \
      src/ResultManager.cpp \
      src/Server.cpp \
	  src/GameManager.cpp

OBJ = $(SRC:src/%.cpp=obj/%.o)
TARGET = rps_game
all: $(TARGET)


$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)


obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -rf obj/*.o $(TARGET)

.PHONY: all clean