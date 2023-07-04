# CC = g++

# # CFLAGS = -std=c++11 -Wall

# # TARGET = main bst ll

# # all: $(TARGET)

# EXE = main;

# all: $(EXE)

# bst.o: bst.cpp
# ll.o: ll.cpp



# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall

# Source files
SRCS := main.cpp bst.cpp ll.cpp get_string.cpp
# Object files
OBJS := $(SRCS:.cpp=.o)
# Executable name
TARGET := movie

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
