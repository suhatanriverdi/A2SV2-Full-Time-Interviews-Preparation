// Question Link: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        map<vector<int>, int> memo; // {sum, current value, possible Combs}
        return helper(nums, 0, nums[0], target, memo);;
    }
    
    int helper(vector<int>& nums, int sum, int cur, int &target, map<vector<int>, int> &memo) {
        if (memo.find({sum, cur}) != memo.end()) {
            return memo[{sum, cur}];
        }
        if (sum > target) {
            return 0;
        }
        if (sum == target) {
            return 1;
        }
        int possibleCombs = 0;
        for (int &num : nums) {
            possibleCombs += helper(nums, sum + num, num, target, memo);
        }
        memo[{sum, cur}] = possibleCombs;
        return possibleCombs;
    }
};