// Question Link: https://leetcode.com/problems/longest-common-subsequence/

// Top-Down Solution
class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        return helper(0, 0, a, b, memo);
    }
    
    int helper(int i, int j, string &a, string &b, int memo[][1001]) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (i == a.size() || j == b.size()) {
            return 0;
        }
        int result = 0;
        if (a[i] == b[j]) {
            result = 1 + helper(i + 1, j + 1, a, b, memo);
        }
        else {
            result = max(helper(i, j + 1, a, b, memo), helper(i + 1, j, a, b, memo));
        }
        memo[i][j] = result;
        return result;
    }
};

// Bottom-Up Solution
class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
        int lenA = a.size(), lenB = b.size();
        vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));
        for (int i = 1; i <= lenA; i++) {
            for (int j = 1; j <= lenB; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }   
        }
        return dp[lenA][lenB];
    }
};