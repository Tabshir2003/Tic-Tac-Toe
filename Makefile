CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

tic_tac_toe: tic_tac_toe.cc
	$(CXX) $(CXXFLAGS) tic_tac_toe.cc -o tic_tac_toe

clean:
	rm -f tic_tac_toe