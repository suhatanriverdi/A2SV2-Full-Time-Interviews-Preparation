// Question Link: https://leetcode.com/problems/fibonacci-number/

// Iterative Solution O(N) Time, O(N) Space
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        vector<int> dp(n, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};

// Recursive Solution O(2^N) Time, O(N) Space
class Solution {
public:
    int fib(int n) {
        if (n == 1 || n == 0) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};