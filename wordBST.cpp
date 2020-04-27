// wordBST.cpp

#include "wordBST.h"


// Constructor sets up the empty tree  
WordBST::WordBST() : root(0) {} 

WordBST::~WordBST() {
    clear(root); 
}

int WordBST::searchWord(string const& word) const {
    Node *n = root;  

    while(n) {
        if (word > n->pair.first) {
            n = n->right; 
        }
        else if (word < n->pair.first) {
            n = n->left; 
        }
        else if (word == n->pair.first) {
            cout << word << " found, count = " << n->pair.second << endl; 
            return 0; 
        }
    }
    cout << word << " not found" << endl; 
}

void WordBST::insertWord(string const& word) {
    if(!root) {
        root = new Node(); 
        root->pair.first = word; 
        root->pair.second = 1; 
    }
    return insert(word, root); 
}

int WordBST::deleteWord(string const& word) {
    
}

void WordBST::rangeSearch(Node* n, string const& first, string const& last) const {
    if (n == NULL) 
        return; 

    if (first < n->pair.first) {
        rangeSearch(n->left, first, last); 
    }
    if (first <= n->pair.first && last >= n->pair.first) {
        cout << n->pair.first << endl; 
    }
    if (last > n->pair.first) 
        rangeSearch(n->right, first, last); 
}


// ---------- Helper Functions ---------

void WordBST::clear(Node *n) {
    if(n) {
        clear(n->left); 
        clear(n->right); 
        delete n; 
    }
}

void WordBST::insert(string const& word, Node *n) {
    if (word == n->pair.first) {
        n->pair.second = n->pair.second + 1; 
    }
    if (word < n->pair.first) {
        if (n->left) {
            return insert(word, n->left); 
        }
        else {
            n->left = new Node(); 
            n->left->pair.first = word; 
            n->left->pair.second = 1; 
            n->left->parent = n; 
        }
    }
    else {
        if (n->right) 
            return insert(word, n->right); 

        else {
            n->right = new Node(); 
            n->right->pair.first = word; 
            n->right->pair.second = 1; 
            n->right->parent = n; 
        }
    }
}

WordBST::Node* WordBST::getNodeFor(string const& word, Node* n) const {
    if (n==nullptr) 
        return 0; 

    while (n != nullptr) {
        if (n->pair.first == word) 
            return n; 
        
        if (word.compare(n->pair.first) < 0) {
            return getNodeFor(word, n->left); 
        }
        if (word.compare(n->pair.first) > 0) {
            return getNodeFor(word, n->right); 
        }
    }
    return nullptr; 
}

WordBST::Node* WordBST::getSuccessorNode(string const& word) const {
    Node* p1 = getNodeFor(word, root); 
    Node* p2 = nullptr; 
    Node* p3 = nullptr; 

    if (p1->right != nullptr) {
        p1 = p1->right; 
        while (p1->left != nullptr) {
            p1 = p1->left;
        }
        p2 = p1; 
        return p1; 
    }
    if (p1->right == nullptr) {
        p2 = p1->parent; 
        while (word.compare(p2->pair.first) > 0) {
            if (p2 ->parent == nullptr) {
                return p3; 
            }
            p2 = p2->parent; 
        }
        return p2; 
    }
    return nullptr; 
}

