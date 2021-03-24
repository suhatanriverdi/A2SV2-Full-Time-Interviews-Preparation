// Question Link: https://leetcode.com/problems/jump-game-v

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int maxJumps = 1;
        vector<int> dp(arr.size(), -1);
        // For each building, find max jumps
        for (int pos = 0; pos < arr.size(); pos++) {
            maxJumps = max(maxJumps, getMaxJumps(pos, arr, d, dp));    
        }
        return maxJumps;
    }
    
    int getMaxJumps(int pos, vector<int> &A, int d, vector<int> &dp) {
        // If maxJumps for pos is already calculated
        if (dp[pos] != -1) {
            return dp[pos];
        }
        int result = 0;
        // Right jumps, do the jump if jump is valid 
        for (int r = pos + 1, t = d; t > 0 && r < A.size() && A[pos] > A[r]; t--, r++) {
            result = max(result, getMaxJumps(r, A, d, dp));
        }
        // Left jumps do the jump if jump is valid
        for (int l = pos - 1, t = d; t > 0 && l >= 0 && A[pos] > A[l]; t--, l--) {
            result = max(result, getMaxJumps(l, A, d, dp));
        }
        dp[pos] = result + 1;
        return dp[pos];
    }
};
