// Question Link: https://www.hackerrank.com/challenges/common-child/problem

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