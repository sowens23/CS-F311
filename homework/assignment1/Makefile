Prog = player
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

$(Prog): $(Prog).o
	$(CXX) $(CXXFLAGS) -o $(Prog) $(Prog).o

$(Prog).o: $(Prog).cpp $(Prog).hpp
	$(CXX) $(CXXFLAGS) -c $(Prog).cpp

$(Prog)_test: $(Prog)_test.o $(Prog).o
	$(CXX) $(CXXFLAGS) -o $(Prog)_test $(Prog)_test.o $(Prog).o

$(Prog)_test.o: $(Prog)_test.cpp $(Prog).hpp doctest.h
	$(CXX) $(CXXFLAGS) -c $(Prog)_test.cpp

run: $(Prog)
	./$(Prog)

test: $(Prog)_test
	./$(Prog)_test

clean:
	rm -f *.o $(Prog) $(Prog)_test

.PHONY: run test clean