// wordTable.h

#ifndef WORDTABLE_H
#define WORDTABLE_H

#include <vector> 
#include <iostream> 
#include <utility>
#include <string> 

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
    void searchWord(string word) const; 

    // Insert Function: 
    // Given a string, it will insert into the hash table 
    void insertWord(string word); 

    // Delete Function: 
    //
    void deleteWord(string word); 

    void rangeSearch(string first, string last) const; 

private:
    const static size_t CAPACITY = 10000; 
    // capacity for hash table 

    vector<std::pair<string, int>> table[CAPACITY]; 

    size_t hash(std::string word) const; 
    // Hash function, returns an index for the hash table 
    
};




#endif 