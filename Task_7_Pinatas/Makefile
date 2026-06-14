# Compiler to use
CXX = g++
   
#Set warnings and optimization                            
CXXFLAGS = -Wall -Wextra -std=c++17 -O3

# Compile application
app: main.cpp                           
	$(CXX) $(CXXFLAGS) main.cpp -o app

# Remove build file
clean:                                  
	rm -f app app.exe