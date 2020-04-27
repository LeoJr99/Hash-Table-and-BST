// wordTable.h

#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <vector> 
#include <iostream> 
#include <utility>
#include <string>
#include <algorithm> 

using std::cout, std::endl, std::string, std::vector; 

class WordTable {
public: 
    // Default Constructor 
    WordTable(); 

    // Default Destructor 
    ~WordTable(); 

    // Search Function:
    // Given a string, it will search throughout the hash table.
    // Precondition: Given a valid string to search for 
    // Postcondition: If word is found it will output "[word] found, count = [count]"
    // If word not found it will out output "[word] not found" 
    int searchWord(string word) const; 

    // Insert Function: 
    // Given a string, it will insert into the hash table 
    int insertWord(string const word); 
    int insertWord2(string const word); 

    // Delete Function: 
    int deleteWord(string word); 

    void rangeSearch(string first, string last) const; 

private:
    const static size_t SIZE = 13001; 
    // capacity for hash table, 1.3x the amount of items, and its nearest prime

    vector<std::pair<string, int>> table[SIZE]; 

    size_t hash(std::string word) const; 
    // Hash function, returns an index for the hash table 
    
};




#endif 