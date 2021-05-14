// Question Link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, set<int>> map;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]].insert(i);
        }
        int maxRange = -1;
        for (auto it : map) {
            // at least 2 index found
            if (it.second.size() > 1) {
                maxRange = max(maxRange, *(--it.second.end()) - (*it.second.begin()) - 1);
            }
        }
        return maxRange;
    }
};