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
        if (word > n->wordVal) {
            n = n->right; 
        }
        else if (word < n->wordVal) {
            n = n->left; 
        }
        else if (word == n->wordVal) {
            cout << word << " found, count = " << n->count << endl; 
            return 0; 
        }
    }
    cout << word << " not found" << endl; 
}

void WordBST::insertWord(string const& word) {
    if(!root) {
        root = new Node(); 
        root->wordVal = word; 
        root->count = 1; 
        cout << word << " inserted, new count = 1" << endl; 
        return; 
    }
    return insert(word, root); 
}
void WordBST::insertWord2(string const& word) {
    if(!root) {
        root = new Node(); 
        root->wordVal = word; 
        root->count = 1; 
        return; 
    }
    return insert2(word, root); 
}

void WordBST::deleteWord(string & value) {
    Node* n; 

    n = getNodeFor( value, root );
    if ( !n )
        return;

    if (n->count > 1) {
        n->count = n->count - 1; 
        cout << value << " deleted, new count = " << n->count << endl; 
        return; 
    }
    else {
        if ( !n->left && !n->right ) {
            if ( n->parent ) {
                if ( n->wordVal < n->parent->wordVal )
                    n->parent->left = nullptr;
                else
                    n->parent->right = nullptr;
                
                if(n != nullptr) {
                    delete n;
                    cout << value << " deleted" << endl; 
                    return;   
                } 
            }
            else {
                if (n != nullptr) {
                    delete n;
                    root = nullptr;
                    cout << value << " deleted" << endl; 
                    return; 
                }
            }
        }
        // case of one child 
        else if ( !n->left ) {
            if ( n == root )
                root = n->right;
            else if ( n->wordVal > n->parent->wordVal ) {
                n->parent->right = n->right;
            }
            else {
                n->parent->left = n->right;
            }
            n->right->parent = n->parent; 
            if (n != nullptr) {
                delete n;
                cout << value << " deleted" << endl; 
                return; 

            }
        }
        // case of one child
        else if ( !n->right ) {
            if ( n == root )
                root = n->left;
            
            else if ( n->wordVal > n->parent->wordVal ) {
                n->parent->right = n->left;
            }
            else {
                n->parent->left = n->left;
            }
            n->left->parent = n->parent;
            if ( n!= nullptr) {
                delete n;
                cout << value << " deleted" << endl; 
                return; 
            }
        }
        // case of 2 children 
        else {
            Node* successor;
            successor = getSuccessorNode( value );
            if ( successor == nullptr ) {
                if (n!= nullptr) {
                    delete n;
                    root = nullptr;
                    cout << value << " deleted" << endl; 
                    return; 
                }
            }
            if ( successor->parent->wordVal == value )
                successor->right = n->right->right;
            else {
                Node* temp = successor->right;
                if ( successor->right )
                    successor->right->parent = successor->parent;
                successor->right = n->right;
                successor->parent->left = temp;
            }
            successor->left = n->left;
            successor->parent = n->parent;

            if ( successor->parent && successor->wordVal < successor->parent->wordVal )
                successor->parent->left = successor;

            if ( successor->right )
                successor->right->parent = successor;

            if ( successor->left )
                successor->left->parent = successor;

            if ( !successor->parent )
                root = successor;

            if (n!= nullptr) {
                delete n;
                cout << value << " deleted" << endl; 
                return; 
            }
        }
    return;
    }
} 


void WordBST::rangeSearch(Node* n, string const& first, string const& last) const {
    if (n == NULL) 
        return; 

    if (first < n->wordVal) {
        rangeSearch(n->left, first, last); 
    }
    if (first <= n->wordVal && last >= n->wordVal) {
        cout << n->wordVal << endl; 
    }
    if (last > n->wordVal) 
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
    if (word == n->wordVal) {
        n->count = n->count + 1; 
        cout << word << " inserted, new count = " << n->count << endl; 
        return; 
    }
    if (word < n->wordVal) {
        if (n->left) {
            return insert(word, n->left); 
        }
        else {
            n->left = new Node(); 
            n->left->wordVal= word; 
            n->left->count = 1; 
            n->left->parent = n; 
            cout << word << " inserted, new count = 1" << endl;
            return; 
        }
    }
    else {
        if (n->right) 
            return insert(word, n->right); 

        else {
            n->right = new Node(); 
            n->right->wordVal= word; 
            n->right->count = 1; 
            n->right->parent = n; 
            cout << word << " inserted, new count = 1" << endl;
            return; 
        }
    }
}
void WordBST::insert2(string const& word, Node *n) {
    if (word == n->wordVal) {
        n->count = n->count + 1; 
        return; 
    }
    if (word < n->wordVal) {
        if (n->left) {
            return insert2(word, n->left); 
        }
        else {
            n->left = new Node(); 
            n->left->wordVal = word; 
            n->left->count = 1; 
            n->left->parent = n; 
            return; 
        }
    }
    else {
        if (n->right) 
            return insert2(word, n->right); 

        else {
            n->right = new Node(); 
            n->right->wordVal = word; 
            n->right->count = 1; 
            n->right->parent = n; 
            return; 
        }
    }
}

WordBST::Node* WordBST::getNodeFor(string const& word, Node* n) const {
    if (n==nullptr) 
        return 0; 

    while (n != nullptr) {
        if (n->wordVal == word) 
            return n; 
        
        if (word.compare(n->wordVal) < 0) {
            return getNodeFor(word, n->left); 
        }
        if (word.compare(n->wordVal) > 0) {
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
        while (word.compare(p2->wordVal) > 0) {
            if (p2 ->parent == nullptr) {
                return p3; 
            }
            p2 = p2->parent; 
        }
        return p2; 
    }
    return nullptr; 
}