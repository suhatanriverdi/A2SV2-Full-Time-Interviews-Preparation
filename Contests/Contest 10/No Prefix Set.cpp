// Question Link: https://www.hackerrank.com/challenges/no-prefix-set/problem

// Trie Node
struct TrieNode {
    unordered_map<char, TrieNode*> kids;
    bool isWord;
};

// Inserts the word into trie and checks if any prefix found
bool insert(TrieNode *root, string word) {
    TrieNode* cur = root;
    bool isNewNodeCreated = false;
    for (char c : word) {
        if (cur->kids.find(c) == cur->kids.end()) {
            cur->kids[c] = new TrieNode();
            isNewNodeCreated = true;
        }
        if (cur->isWord == true) {
            return false;
        }
        cur = cur->kids[c];
    }
    cur->isWord = true;
    return isNewNodeCreated;
}

void noPrefix(vector<string> words) {
    TrieNode *root = new TrieNode();
    for (string &word : words) {
        if (insert(root, word) == false) {
            cout << "BAD SET\n";
            cout << word;            
            return;
        }
    }
    cout << "GOOD SET";    
}
