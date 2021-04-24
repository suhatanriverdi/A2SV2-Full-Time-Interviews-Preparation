// Question Link: https://www.hackerrank.com/challenges/common-child/problem

// Top-Down
int helper(int i, int j, string &a, string &b, vector<vector<int>> &memo) {
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

int commonChild(string a, string b) {
    vector<vector<int>> memo(a.size() + 1, vector<int>(b.size() + 1, -1));
    return helper(0, 0, a, b, memo);
}

// Bottom-Up
int commonChild(string a, string b) {
    int aLen = a.size(), bLen = b.size();
    vector<vector<int>> dp(aLen + 1, vector<int>(bLen + 1, 0));
    for (int i = 1; i <= aLen; i++) {
        for (int j = 1; j <= bLen; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[aLen][bLen];
}
