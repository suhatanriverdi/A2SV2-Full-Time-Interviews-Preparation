// Question Link: https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int memo[1001][1001];
        memset(memo, -1, sizeof memo);
        return helper(0, s.size(), s, memo);
    }
    
    // Finds and returns longest palindromic subsequence length
    int helper(int l, int r, string &s, int memo[][1001]) {
        if (memo[l][r] != -1) {
            return memo[l][r];
        }
        if (l > r) {
            return 0;
        }
        if (l == r) {
            return s[l] == s[r];
        }
        if (s[l] == s[r]) {
            memo[l][r] = 2 + helper(l + 1, r - 1, s, memo);
            return memo[l][r];
        }
        else {
            memo[l][r] = max(helper(l, r - 1, s, memo), helper(l + 1, r, s, memo));
            return memo[l][r];
        }
    }
};