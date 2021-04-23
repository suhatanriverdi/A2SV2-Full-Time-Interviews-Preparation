// Question Link: https://leetcode.com/problems/map-sum-pairs/

// Trie Prefix Sum Solution
struct TrieNode {
    TrieNode* kids[26] = { NULL };
    bool isWord = false;
    int sum = 0;
};

class MapSum {
public:
    TrieNode *root = new TrieNode();
    unordered_map<string, int> wordPrevSum;
    MapSum() {
    }
    
    void insert(string key, int val) {
        int prevSum = (wordPrevSum.find(key) != wordPrevSum.end()) ? wordPrevSum[key] : 0;
        wordPrevSum[key] = val;
        TrieNode *cur = root;
        for (char c : key) {
            if (cur->kids[c - 'a'] == NULL) {
                cur->kids[c - 'a'] = new TrieNode();
            }
            cur->kids[c - 'a']->sum += val;
            cur->kids[c - 'a']->sum -= prevSum;
            cur = cur->kids[c - 'a'];
        }
        cur->isWord = true;
    }
    
    int sum(string prefix) {
        TrieNode *cur = root;
        for (char c : prefix) {
            if (cur->kids[c - 'a'] == NULL) {
                return 0;
            }
            cur = cur->kids[c - 'a'];
        }
        return cur->sum;
    }
};

// Alphabetic Map Solution
class MapSum {
public:
    // Each map holds the words that starts with one specific letter
    vector<unordered_map<string, int>> strValMaps;
    MapSum() {
        strValMaps.resize(26);
    }
    
    void insert(string key, int val) {
        char startsWith = key[0];
        strValMaps[startsWith - 'a'][key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        char startsWith = prefix[0];
        for (auto &pair : strValMaps[startsWith - 'a']) {
            if (isPrefix(pair.first, prefix)) {
                sum += pair.second;
            }
        }
        return sum;
    }
    
    bool isPrefix(const string &A, string &prefix) {
        int sizeA = A.size(), sizePre = prefix.size();
        if (sizePre > sizeA) {
            return false;
        }
        for (int i = 0; i < sizePre; i++) {
            if (A[i] != prefix[i]) {
                return false;
            }
        }
        return true;
    }
};
