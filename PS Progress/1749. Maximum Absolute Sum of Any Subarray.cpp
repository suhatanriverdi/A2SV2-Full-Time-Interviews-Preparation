// Question Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int positivesMaxSum = maxSubArraySum(nums);
        for (int &n : nums) {
            n *= -1;
        }
        int negativesMaxSum = maxSubArraySum(nums);
        return max(negativesMaxSum, positivesMaxSum);
    }
    
    int maxSubArraySum(vector<int>& nums) {
        int prevSubIndex = 1, n = nums.size(), subSum, answer = INT_MIN;
        vector<int> prefixSum = {0};
        prefixSum.insert(prefixSum.end(), nums.begin(), nums.end());
        answer = nums[0];
        // Get prefix sum
        for (int i = 1; i < n + 1; i++) {
            prefixSum[i] += prefixSum[i - 1];
        }
        // Find max sub array sum
        for (int i = 1; i < n; i++) {
            subSum = prefixSum[i] - prefixSum[prevSubIndex - 1] + nums[i];
            if (nums[i] > subSum) {
                // Update max sub array sum starting index
                prevSubIndex = i + 1;
                answer = max(nums[i], answer);
            }
            else {
                answer = max(subSum, answer);
            }
        }
        return answer;
    }
};