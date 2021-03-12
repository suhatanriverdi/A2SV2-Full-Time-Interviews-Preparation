// Question Link: https://leetcode.com/problems/replace-words

struct TrieNode {
    TrieNode* children[26] = {NULL};
    bool isWord = false;
};

class Solution {
private:
    TrieNode* root = new TrieNode();
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<set<string>> roots(26); // Words start with letter x
        for (string &root : dictionary) {
            char c = root[0];
            roots[c - 'a'].insert(root);
        }
        
        // Read each word one by one and insert in to Trie
        istringstream iss(sentence);
        string word, result = "";
        bool found;
        while(iss >> word) {
            insert(word);
            int letterIndex = word[0] - 'a';
            found = false;
            for (string root : roots[letterIndex]) {
                if (startsWith(root, word)) {
                    result += root + " ";
                    found = true;
                    break;
                }
            }
            if (found == false) {
                result += word + " ";
            }
        }
        result.pop_back();
        return result;
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool startsWith(string &prefix, string &word) {
        if (word.size() < prefix.size()) {
            return false;
        }
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            char preC = prefix[i], wordC = word[i];
            if (cur->children[wordC - 'a'] != NULL && wordC == preC) {
                cur = cur->children[wordC - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};
