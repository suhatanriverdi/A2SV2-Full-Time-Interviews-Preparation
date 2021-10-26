// Question Link: https://leetcode.com/problems/fibonacci-number/

// Initial Recursive without Memoization Solution O(2^N) Time
int fib(int n) {
    if (n == 1 || n == 0) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// Top-Down With Memoization Solution O(N) Time
int fibHelper(int n, int memo[]) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n == 1 || n == 0) {
        return n;
    }
    memo[n] = fibHelper(n - 1, memo) + fibHelper(n - 2, memo);
    return memo[n];
}

int fib(int n) {
    int memo[31] = { -1 };
    memset(memo, -1, sizeof(memo));
    return fibHelper(n, memo);
}

// Bottom-Up/Tabulation Solution O(N) Time
int fib(int n) {
    int dp[31];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
