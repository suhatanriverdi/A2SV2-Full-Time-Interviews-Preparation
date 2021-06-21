// Question Link: https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int memo[20001];
        memset(memo, -1, sizeof(memo));
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        return helper(0, 0, nums, totalSum, memo);
    }
    
    bool helper(int i, int sum, vector<int> &nums, int totalSum, int memo[]) {
        if (memo[sum] != -1) {
            return memo[sum];
        }
        
        if (i >= nums.size()) {
            return (sum == (totalSum - sum));
        }
        
        // Take current value
        bool A = helper(i + 1, sum + nums[i], nums, totalSum, memo);
        
        // Don't take current value
        bool B = helper(i + 1, sum, nums, totalSum, memo);
        
        memo[sum] = A || B;
        return memo[sum];
    }
};