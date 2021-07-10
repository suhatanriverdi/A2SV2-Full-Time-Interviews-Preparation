// Question Link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size(), result = 1;
        vector<int> memo(N, -1);
        for (int i = 0; i < N; i++) {
            result = max(result, helper(i, N, nums, memo));
        }
        return result;
    }
    
    int helper(int cur, int &N, vector<int> &nums, vector<int> &memo) {
        if (memo[cur] != -1) {
            return memo[cur];
        }
        int result = 1;
        for (int next = cur + 1; next < N; next++) {
            if (nums[next] > nums[cur]) {
                result = max(result, 1 + helper(next, N, nums, memo));
            }
        }
        memo[cur] = result;
        return result;
    }
};