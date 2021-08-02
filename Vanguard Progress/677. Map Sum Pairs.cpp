// Question Link: https://leetcode.com/problems/map-sum-pairs

struct TrieNode {
    char letter = '\0';
    int sum = 0;
    TrieNode* kids[26] = { NULL };
    TrieNode (char chr, int val) {
        letter = chr;
        sum = val;
    }
};

class MapSum {
private:
    TrieNode* root = new TrieNode('*', 0);
    unordered_map<string, int> wordValueMap;
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        TrieNode* walk = root;
        int valueToAdd = val;
        if (wordValueMap.find(key) != wordValueMap.end()) {
            valueToAdd -= wordValueMap[key];
        }
        for (char c : key) {
            if (walk->kids[c - 'a'] == NULL) {
                walk->kids[c - 'a'] = new TrieNode(c, val);
            }
            else {
                walk->kids[c - 'a']->sum += valueToAdd;
            }
            walk = walk->kids[c - 'a'];
        }
        wordValueMap[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode* walk = root;
        for (char c : prefix) {
            if (walk->kids[c - 'a'] == NULL) {
                return 0;
            }
            walk = walk->kids[c - 'a'];
        }
        return walk->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */