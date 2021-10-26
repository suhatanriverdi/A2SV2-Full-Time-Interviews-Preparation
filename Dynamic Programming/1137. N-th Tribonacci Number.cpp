// Question Link: https://leetcode.com/problems/n-th-tribonacci-number

// Bottom-Up Tabulation O(N) Time & O(N) Space Solution
class Solution {
public:
    int tribonacci(int n) {
        int dp[38];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;  
        dp[2] = 1;  
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            if (i == n) {
                break;
            }
        }
        return dp[n];
    }
};

// Top-Down with Memoization O(N) Time & O(N) Space Solution
int tribonacciHelper(int n, int memo[]) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    memo[n] = tribonacciHelper(n - 1, memo) + tribonacciHelper(n - 2, memo) + tribonacciHelper(n - 3, memo);
    return memo[n];
}

int tribonacci(int n) {
    int memo[38];
    memset(memo, -1, sizeof(memo));
    return tribonacciHelper(n, memo);
}