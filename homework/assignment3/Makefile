Prog = da3
Prog1 = llnode
CXX = g++
CXXFLAGS = -std=c++17

$(Prog): $(Prog).o
	$(CXX) $(CXXFLAGS) -o $(Prog) $(Prog).o

$(Prog).o: $(Prog).cpp $(Prog).hpp $(Prog1).hpp
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