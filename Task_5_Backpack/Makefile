# Compiler to use
CXX = g++

#Set warnings and optimization
CXXFLAGS = -Wall -Wextra -std=c++17 -O3

# Build all targets
all: app gen

# Compile main application
app: main.cpp
	$(CXX) $(CXXFLAGS) -o app main.cpp

# Compile test data generator
gen: gen.cpp
	$(CXX) $(CXXFLAGS) -o gen gen.cpp

# Remove build and test files
clean:
	rm -f app gen app.exe gen.exe block.txt transactions.csv