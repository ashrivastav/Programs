CXX = g++
CXXFLAGS = -Wall -g --std=c++17 -fconcepts
all: maxsumsubarray

maxsumsubarray: maxsumsubarray.o
	 $(CXX) -o maxsumsubarray maxsumsubarray.o

maxsumsubarray.o: maxsumsubarray.cpp
	 $(CXX) $(CXXFLAGS) -c maxsumsubarray.cpp
clean:
	 rm maxsumsubarray.o maxsumsubarray
