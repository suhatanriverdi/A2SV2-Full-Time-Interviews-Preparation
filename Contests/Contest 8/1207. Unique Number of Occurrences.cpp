// Question Link: https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> s;
        unordered_map<int, int> c;
        for (int &i : arr) {
            c[i]++;
        }
        for (auto it : c) {
            if (s.find(it.second) == s.end()) {
                s.insert(it.second);
            } else {
                return false;
            }
        }
        return true;
    }
};
