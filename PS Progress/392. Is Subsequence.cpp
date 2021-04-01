// Question Link: https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        while (!s.empty() && !t.empty()) {
            if (s.back() == t.back()) {
                s.pop_back();
            }
            t.pop_back();
        }
        return s.empty();
    }
};