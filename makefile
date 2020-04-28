# Makefile

CXX = g++
#CXX = clang++ 

CXXFLAGS = -std=c++11 -Wall

all: prog1.out

prog1: wordBST.o wordTable.o prog1.cpp
	${CXX} ${CXXFLAGS} $^ -o $@