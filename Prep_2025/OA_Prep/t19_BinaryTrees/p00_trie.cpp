#include <bits/stdc++.h>
using namespace std;

struct Node { //TRIE Node structure
    Node* child[26]; // pointer array for child nodes
    int words; // count of words using this node

    Node() {
        words = 0;
        for (int it = 0; it < 26; it++) child[it] = nullptr;
    }
};

void insert_key(Node* root, string& key) {
    Node* iter = root;
    for (auto ch : key) {
        if (!iter->child[ch - 'a']) { // create new node if not exist
            Node* temp = new Node();
            iter->child[ch - 'a'] = temp;
        }
        iter = iter->child[ch - 'a']; // increment to next node
    }
    iter->words++; // increment words at node
}

bool search_key(Node* root, string& key) {
    Node* iter = root;
    for (auto ch : key) {
        if (!iter->child[ch - 'a']) { // word not found
            return false;
        }
        iter = iter->child[ch - 'a']; // move to next node
    }
    return (iter->words > 0); // return true if word exists
}

bool delete_key(Node* root, string& word) {
    Node* iter = root;
    Node* lastBranchNode = nullptr; // to remember last branching node
    char lastBrachChar = 'a';

    // Traverse the Trie to find the word and track branching nodes
    for (auto ch : word) {
        if (!iter->child[ch - 'a']) return false; // word not found
        else {
            int count = 0;// Need to track if more than one child exists: Delete the node or not
            for (int it = 0; it < 26; it++) {
                if (iter->child[it]) count++;
                if (count > 1) { // More than one child: this is a branching node
                    lastBranchNode = iter;
                    lastBrachChar = ch;
                    break; // no need to check further childs for this character
                }
            }
            iter = iter->child[ch - 'a'];
        }
    }

    if (iter->words > 0) { // Case 1: deleted word is prefix of others
        iter->words--;
        return true;
    }
    if (lastBranchNode) { // Case 2: shares prefix with others
        delete lastBranchNode->child[lastBrachChar];
        lastBranchNode->child[lastBrachChar] = nullptr;
        return true;
    } 
    else { // Case 3: no shared prefix
        delete root->child[word[0]];
        root->child[word[0]] = nullptr;
        return true;
    }
}

// Print the Trie structure in tree structure format
void print_trie_node(Node* root, string prefix = "") {
    if (root->words > 0) {
        cout << prefix << " (" << root->words << ")\n"; // print word and count
    }
    for (int it = 0; it < 26; it++) {
        if (root->child[it]) {
            cout << prefix + char(it + 'a') << " -> ";
            print_trie_node(root->child[it], prefix + char(it + 'a')); // recursive call for child nodes
        }
    }
}

int main() {
    Node* root = new Node(); // create root node

    vector<string> inp = { "and", "ant", "dog", "do", "doll", "geek", "dad", "ball" };
    for (int it = 0; it < inp.size(); it++)
        insert_key(root, inp[it]);
    
    cout << "Trie after insertion:\n";
    print_trie_node(root); // print the Trie structure
    cout << "\n";

    vector<string> query = { "do", "geek", "bat" };
    for (int it = 0; it < query.size(); it++) {
        cout << "Searching: " << query[it] << "\n";
        if (search_key(root, query[it])) cout << "\"" << query[it] << "\" is present in the Trie\n";
        else cout << "\"" << query[it] << "\" is not present in the Trie\n";
    }

    vector<string> del = { "geek", "tea" };
    for (int it = 0; it < del.size(); it++) {
        cout << "Query String: " << del[it] << "\n";
        if (delete_key(root, del[it])) cout << "\"" << query[it] << "\" is deleted successfully\n";
        else cout << "\"" << query[it] << "\" is not present in the Trie\n";
    }

    return 0;
}
