CXX := c++
CXXFLAGS := -O2 -std=c++17 -Wall -Wextra -Wshadow -fsanitize=address -fsanitize=undefined

all: sol.cpp
	$(CXX) $(CXXFLAGS) sol.cpp -o sol

clean:
	rm -f sol
