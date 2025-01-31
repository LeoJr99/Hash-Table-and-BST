// wordTable.cpp

#include "wordTable.h"

WordTable::WordTable() {} 

WordTable::~WordTable() {}

// Helper Function for sorting strings in descending order
bool stringSort(const std::pair<string, int> &a,
			    const std::pair<string, int> &b) {
	
	return (a.first < b.first); 
}

int WordTable::searchWord(string word) const {
    
    int count = 0; 
    int index = hash(word); 
    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index][i].first == word) {
            count = table[index][i].second; 

            cout << word << " found, count = " << count << endl; 
            return 0; 
        }
    }
    cout << word << " not found" << endl; 
}

int WordTable::insertWord(string word) { 
    int count = 0;
    int index = hash(word); 


    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index][i].first == word) {
            table[index][i].second = table[index][i].second + 1;
            count = table[index][i].second;
            cout << word << " inserted, new count = " << count << endl;

            return 0; 

        } 
    }

    table[index].push_back(std::make_pair(word, 1)); 
    cout << word << " inserted, new count = " << 1 << endl;

}

int WordTable::insertWord2(string word) { 
    int count = 0;
    int index = hash(word); 


    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index][i].first == word) {
            table[index][i].second = table[index][i].second + 1;
            count = table[index][i].second;

            return 0; 

        } 
    }

    table[index].push_back(std::make_pair(word, 1)); 

}

int WordTable::deleteWord(string word) {

    int count = 0;
    int index = hash(word); 

    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index][i].first == word) {
            if (table[index][i].second > 1) {
                table[index][i].second = table[index][i].second - 1;
                count = table[index][i].second;
                cout << word << " deleted, new count = " << count << endl;  
                return 0; 
            }
            else if(table[index][i].second == 1) {
                table[index].erase(table[index].begin() + (i)); 
                cout << word << " deleted" << endl; 
                return 0;
            }
        }
    }
    cout << word << " not found" << endl;
}

void WordTable::rangeSearch(string first, string last) const {

    vector<std::pair<string, int>> wordVector; 

    for (size_t i = 0; i < SIZE; i++) {
        if (table[i].empty()) {
            continue; 
        }
        else {
            for(size_t j = 0; j < table[i].size(); j++) {
                wordVector.push_back(table[i][j]); 
            }
        }
    }
    std::sort(wordVector.begin(), wordVector.end(), stringSort); 

    for (size_t j = 0; j < wordVector.size(); j++) {
        if (wordVector[j].first.compare(first) >= 0 &&
            wordVector[j].first.compare(last) <= 0) {
                cout << wordVector[j].first << endl; 
            }
    }

}

size_t WordTable::hash(string word) const {

    size_t p = 31; 
    // size_t m = 1e10 + 9; 
    size_t hashValue = 0; 
    size_t pPow = 1; // power of p 
    for (char c : word) {
        hashValue = (hashValue + (c - 'a' + 1) *pPow) % SIZE;
        pPow = (pPow * p) % SIZE; 
    }
    return hashValue; 


}
