// Question Link: https://leetcode.com/problems/climbing-stairs/

// Bottom-Up Solution O(N) Time & Space
class Solution {
public:
    int climbStairs(int n) {
        int dp[46];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Top-Down DP O(N) Time & Space
class Solution {
public:
    int climbStairsHelper(int n, int memo[]) {
        if (memo[n] != -1) {
            return memo[n];
        }
        if (n == 1 || n == 2) {
            return n;
        }
        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
        return memo[n];
    }
    
    int climbStairs(int n) {
        int memo[46];
        memset(memo, -1, sizeof(memo));
        return climbStairsHelper(n, memo);
    }
};