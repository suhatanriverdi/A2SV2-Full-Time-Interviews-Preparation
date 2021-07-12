// Question Link: https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap, tMap;
        for (int i = 0; i < s.size(); i++) {
            if (sMap.find(s[i]) == sMap.end()) {
                sMap[s[i]] = t[i];
                if (tMap.find(t[i]) != tMap.end()) {
                    return false;
                }
                tMap[t[i]] = s[i];
            }
            if (sMap[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};