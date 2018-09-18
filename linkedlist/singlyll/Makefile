CXX = g++
CXXFLAGS = -Wall -g --std=c++17 -fconcepts
all: generic_sll

generic_sll: generic_sll.o
	 $(CXX) -o generic_sll generic_sll.o

generic_sll.o: generic_sll.cc
	 $(CXX) $(CXXFLAGS) -c generic_sll.cc
clean:
	 rm generic_sll.o generic_sll
