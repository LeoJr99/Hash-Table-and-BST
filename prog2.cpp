// prog2.cpp


#include "wordBST.h"
#include "wordTable.h" 

using namespace std; 

int main() {
    WordTable wordList; 

    wordList.insertWord("how"); 
    wordList.insertWord("how"); 
    wordList.insertWord("how"); 
    wordList.insertWord("are"); 
    wordList.insertWord("you"); 
    wordList.insertWord("there"); 
    wordList.insertWord("here"); 
    wordList.insertWord("hunt"); 
    wordList.insertWord("hut"); 
    wordList.insertWord("word"); 
    wordList.insertWord("near"); 
    wordList.insertWord("this"); 
    wordList.deleteWord("how"); 
    wordList.rangeSearch( "how", "near");


}