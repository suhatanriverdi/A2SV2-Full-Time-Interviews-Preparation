// Question Link: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size <= 1) {
            return (size == 0 ? "" : strs[0]);
        }
        string res = strs[0];
        for (string &s : strs) {
            if (isPrefix(s, res) == false) {
                return "";
            }
        }
        return res;
    }
    
    bool isPrefix(string &s, string &res) {
        bool hasCommonLetter = false;
        string prefix = "";
        for (int i = 0; i < min(s.size(), res.size()) && s[i] == res[i]; i++) {
            prefix += s[i];
            hasCommonLetter = true; 
        }
        res = prefix;
        return hasCommonLetter;
    }
};
