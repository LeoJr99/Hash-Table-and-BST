// wordSBT.h

#ifndef WORDBST_H
#define WORDBST_H

#include <iostream>
#include <vector>
#include <string> 
#include <utility>

using namespace std; 

class WordBST {
public: 


    struct Node {
        string wordVal; 
        int count; 
        Node *left, *right, *parent;
    };
    Node *root; 

    // Default Constructor 
    WordBST(); 

    // Default Destructor 
    ~WordBST(); 

    int searchWord(string const& word) const; 

    // Insert Function: 
    // Given a string, it will insert into the hash table 
    void insertWord(string const& word); 
    void insertWord2(string const& word); 

    // Delete Function: 
    //
    void deleteWord(string &word); 

    void rangeSearch(Node* n, string const& first, string const& last) const;


    Node* getNodeFor(string const& word, Node *n) const; 
    Node* getSuccessorNode(string const& word) const; 
    
private:

    // recursive functions 
    void clear(Node *n); // will be used for destructor 
    void insert(string const& word, Node *n); // helper function for insert
    void insert2(string const& word, Node *n); // helper function for insert

};

#endif