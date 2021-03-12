// Question Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
};

class WordDictionary {
private:
    TrieNode* root = new TrieNode();
public:
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children[c] == NULL) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;  
    }
    
    bool search(string word) {
        bool found = false;
        dfs(0, word, root, found);
        return found;
    }
    
    void dfs(int curIdx, string &word, TrieNode* cur, bool &found) {
        if (found == true || cur == NULL) {
            return;
        }
        if (curIdx >= word.size() && cur->isWord) {
            found = true;
            return;
        }
        char c = word[curIdx];
        // If dot, try to go all branches
        if (c == '.') {
            for (auto it : cur->children) {
                dfs(curIdx + 1, word, it.second, found);
            }
        }
        else {
            if (cur->children[c] != NULL) {
                dfs(curIdx + 1, word, cur->children[c], found);
            }
        }
    }
};
