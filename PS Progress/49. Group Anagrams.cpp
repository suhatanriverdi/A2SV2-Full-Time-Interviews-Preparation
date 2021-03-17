// Question Link: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> anagMap;
        for (string &str : strs) {
            vector<int> curMap(26, 0);
            for (char c : str) {
                curMap[c - 'a']++;
            }
            anagMap[curMap].push_back(str);
        }
        vector<vector<string>> result;
        for (auto it : anagMap) {
            result.push_back(it.second);
        }
        return result;
    }
};
