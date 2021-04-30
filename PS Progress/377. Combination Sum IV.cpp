// Question Link: https://leetcode.com/problems/combination-sum-iv/

// 4ms DP memo solution
class Solution {
    unordered_map<int, int> memo;
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return dfs(nums, target);
    }
    
    int dfs(vector<int> &nums, int sum) {
        if (memo.find(sum) != memo.end()) {
            return memo[sum];
        }
        if (sum <= 0) {
            return sum == 0;
        }
        int result = 0;
        for (int i = 0; i < nums.size() && sum >= nums[i]; i++) {
            result += dfs(nums, sum - nums[i]);
        }
        memo[sum] += result;
        return result;
    }
};

// Bad Solution
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
