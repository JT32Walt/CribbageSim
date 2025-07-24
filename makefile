# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Source files
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Output binary (Windows executable)
TARGET = main.exe

# Default rule
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	del /f $(TARGET) $(OBJS)
