# Makefile

#CXX = g++
CXX = clang++ 

CXXFLAGS = -std=c++11 -Wall -Wextra

prog1: wordBST.o wordTable.o prog1.o
	${CXX} ${CXXFLAGS} $^ -o $@

prog2: wordBST.o wordTable.o prog2.o
	${CXX} ${CXXFLAGS} $^ -o $@
