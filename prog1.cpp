// prog1.cpp

#include "wordTable.h"
#include "wordBST.h" 
#include <fstream> 
#include <cstdlib>
#include <iostream>
#include <sstream> 
#include <string>

using namespace std; 

int main(int argc, char *argv[]) {

    WordTable wordList1;
    WordBST wordList2; 

    ifstream textFile; 
    textFile.open("/autograder/submission/PA1_dataset.txt"); 
    string word;
    int count; 

    if (textFile.fail()) {
        cerr << "Could not open file 'PA1_dataset.txt.'";
        exit(1); 
    }

    while (!textFile.eof() && !textFile.fail() && count < 9999) {
        count++; 
        textFile >> word;
        wordList1.insertWord(word); 
        wordList2.insertWord(word);   
    }
    textFile.close(); 

    string argument = argv[1] ; 
    string::iterator it = argument.begin(); 
    string subword, sub;  
    vector<string> commands; 

    for (it; it != argument.end(); it++) {
        if (subword.length() > 5)
            sub = subword.substr(subword.length() - 4, 4);  
        if (subword == "search" || subword == "delete" || subword == "insert" || subword == "range search") {
            commands.push_back(subword); 
            subword.clear();  
        }
        else {
            if(*it == ',') {
                commands.push_back(subword); 
                subword.clear(); 
                it++; 
            }
            else if (sub == " to ") {
                subword = subword.substr(0, subword.length() - 4); 
                commands.push_back(subword); 
                subword.clear(); 
                sub.clear(); 
                subword += *it;  
            }
            else 
                subword += *it; 
        }
    }
    commands.push_back(subword); 
 
    for (int vecIt = 0; vecIt < commands.size(); vecIt++) {
        cout << commands[vecIt] << " "; 
        if (commands[vecIt] == "range search") {
            wordList1.rangeSearch(commands[vecIt + 1], commands[vecIt + 2]); 
            wordList2.rangeSearch(wordList2.root, commands[vecIt + 1], commands[vecIt + 2] );
        }
        else if (commands[vecIt] == "delete") {
            wordList1.deleteWord(commands[vecIt + 1]); 
            wordList2.deleteWord(commands[vecIt + 1]); 
        }
        else if (commands[vecIt] == "insert") {
            wordList1.insertWord(commands[vecIt + 1]); 
            wordList2.insertWord(commands[vecIt + 1]); 
        }
        else if (commands[vecIt] == "search") {
            wordList1.searchWord(commands[vecIt + 1]); 
            wordList2.searchWord(commands[vecIt + 1]); 
        }
    }

}