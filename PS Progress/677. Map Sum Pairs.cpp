// Question Link: https://leetcode.com/problems/map-sum-pairs/

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
