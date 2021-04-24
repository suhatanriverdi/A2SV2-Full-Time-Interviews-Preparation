// Question Link: https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
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
    vector<int> result;
    // Extract LCS
    int i = aLen, j = bLen;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(begin(result), end(result));
    return result;
}