// Question Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size(), result = 0;
        vector<vector<int>> dp(n, vector<int>(n, 40001));
        
        for (int i = 0; i < n; i++) {
            dp[0][i] = arr[0][i];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        dp[i][j] = min(dp[i][j], (dp[i - 1][k] + arr[i][j]));
                    }
                }
            }
        }
        
        return *min_element(begin(dp.back()), end(dp.back()));
    }
};