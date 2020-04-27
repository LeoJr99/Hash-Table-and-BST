# Makefile

#CXX = g++
CXX = clang++ 

CXXFLAGS = -std=c++11 -Wall -Wextra

prog1.out: wordBST.o wordTable.o prog1.o
	${CXX} ${CXXFLAGS} $^ -o $@
